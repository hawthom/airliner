/****************************************************************************
 *
 *   Copyright (c) 2019 Windhover Labs, L.L.C. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name Windhover Labs nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

"use strict";

var path = require('path');
var fs = require('fs');
var express = require('express');
const Emitter = require('events').EventEmitter;
var mergeJSON = require('merge-json');
const autoBind = require('auto-bind');
const Handlebars = require('handlebars');

/* Content Types */
const ContentTypeEnum = Object.freeze({
    'PANEL':  1,
    'LAYOUT': 2,
    'WIDGET': 3
});


/**
 * Commander plugin
 */
class CdrPlugin extends Emitter {
    /**
     * Constructor for commander plugin
     * @param {String} name    directory name
     * @param {String} webRoot directory path
     * @param {String} urlBase base url
     */
    constructor(config) {
	super();
        
        autoBind(this);

        this.webRoot = config.webRoot;
        this.namespace = config.namespace;
        this.name = config.name;
        this.commands = {};
        this.telemetry = {};
        var self = this;
        
        this.processTelemetryDefRequest = this.processTelemetryDefRequest.bind(this);
        
        this.namespace.onCommandDefRequest(function(cmdReq, cb) {
            if(self.commands.hasOwnProperty(cmdReq.opsPath)) {
                var response = {opsPath: cmdReq.opsPath, Def: self.commands[cmdReq.opsPath].def};
                self.logDebug( 'CmdDefReq: \'' + JSON.stringify( cmdReq, null, '\t' ) + '\'  Def: \'' + JSON.stringify( self.commands[cmdReq.opsPath].def, null, '\t' ) + '\'' );
                cb(self.commands[cmdReq.opsPath].def);
            }
        });
        
        this.namespace.onCommand(function(cmd, cb) {
            if(self.commands.hasOwnProperty(cmd.ops_path)) {
                self.logDebug('Received command \'' + cmd.ops_path + '\'', cmd);
                self.commands[cmd.ops_path].cb(cmd, cb);
            }
        });
        
        this.namespace.onTelemetryDefRequest(this.processTelemetryDefRequest);
        
        this.logDebug('Created.');
    }
    
    
    processTelemetryDefRequest(tlmReq, cb) {
        for(var msgOpsPath in this.telemetry) {
            for(var paramName in this.telemetry[msgOpsPath].content) {
                if(tlmReq.name == msgOpsPath + '/' + paramName) {
                    var output = {opsPath: tlmReq.name};
                        
                    switch(typeof this.telemetry[msgOpsPath].content[paramName]) {
                        case 'number':
                            output.dataType = 'uint32';
                            break;
                                
                        case 'string':
                            output.dataType = 'char';
                            output.arrayLength = 100;
                            break;
                                
                        default:
                            self.logError('Unsupported internal telemetry type of \'' + typeof this.telemetry[msgOpsPath].content[paramName] + '\'');
                            break;
                    }
                        
                    cb(output);
                }
            }
        }
    } 
  
  
    addContent(content) {
        if ( typeof content !== 'undefined' ) {
            global.CONTENT_TREE = mergeJSON.merge( global.CONTENT_TREE, content );

            var appViews = global.NODE_APP.get( 'views' );
            appViews.push( this.webRoot );

            this.processContentTree( content, '');
            
            this.logDebug('Added content.');
        } else {
            this.logError('Content is undefined');
        }
    }
    
    
    addCommand(newCommand, cb) {
        this.commands[newCommand.opsPath] = {};
        this.commands[newCommand.opsPath].def = newCommand;
        this.commands[newCommand.opsPath].cb = cb;
    }

    
    sendTelemetry(tlmObj) {
        this.namespace.sendTelemetry(tlmObj);
    }

    
    addTelemetry(newTelemetry, delay) {
        var self = this;
        
        this.telemetry[newTelemetry.opsPath] = newTelemetry;
        
        setInterval(function() {
            self.telemetry[newTelemetry.opsPath].msgTime = new Date();
            self.namespace.sendTelemetry(self.telemetry[newTelemetry.opsPath]);
        }, delay);
    }

    
    /**
     * This is called by the underlying framework to initialize the plugin.
     */
    initialize( commander, instance ) {
        var self = this;
    }


    /**
     * Returns content type
     * @type {Object}
     */
    static get ContentType() {
        return ContentTypeEnum;
    }

    /**
     * Process content tree
     * @param  {Object} content content object
     * @param  {String} inPath  input path
     */
    processContentTree( content, inPath ) {
        var self = this;
        var filePath = content.filePath;
    
        if(typeof filePath !== 'undefined') {
            var fullFilePath = path.join( self.webRoot, filePath );

            if(path.extname(fullFilePath) === '.pug') {
                global.NODE_APP.get( inPath, function( req, res ) {
                    res.render(fullFilePath, {
                        query: req.query
                    });
                });
            } else if(path.extname(fullFilePath) === '.lyt') {
                global.NODE_APP.get(inPath, function(req, res) {
                    var json = fs.readFileSync(fullFilePath, 'utf8');

                    if(content.hasOwnProperty('handlebarsContext')) {
                        var layoutString = JSON.stringify(json);
                        var template = Handlebars.compile(layoutString);
                        var instantiatedContent = template(content.handlebarsContext);
                        var newJSON = JSON.parse(instantiatedContent);
                        res.send(newJSON);
                    } else {
                        res.send(json);
                    }
                });
            }

            var staticPath = path.join( self.webRoot );
            global.NODE_APP.use( inPath, express.static( staticPath ) );
        }

        if(typeof content.nodes !== 'undefined') {
            for(var nodeName in content.nodes) {
                self.processContentTree( content.nodes[nodeName], inPath + '/' + nodeName );
            }
        } else {
            for(var argName in content) {
                if(typeof content[argName] === 'object') {
        	        self.processContentTree(content[argName], inPath + '/' + argName);
    	        }
            }
        }
    }
    

    /**
     * Reads a json file and applies a callback on read data.
     * @param  {String}   filename file name
     * @param  {Function} callback callback
     */
    readJSONFile(filename, callback) {
        fs.readFile(filename, function(err, data) {
            if(err) {
                callback(err);
                return;
            }
            
            try {
                callback(null, data);
            } catch (exception) {
                callback(exception);
            }
        });
    }
    
    
    logDebug(message) {
        if(typeof this.namespace === 'undefined') {
            console.log('Namespace undefined in plugin \'' + this.name + '\'');
        } else {
            this.namespace.logDebug(this.name, message);
        }
    }
    
    
    logVerbose(message) {
        if(typeof this.namespace === 'undefined') {
            console.log('Namespace undefined in plugin \'' + this.name + '\'');
        } else {
            this.namespace.logVerbose(this.name, message);
        }
    }
    
    
    logInfo(message) {
        if(typeof this.namespace === 'undefined') {
            console.log('Namespace undefined in plugin \'' + this.name + '\'');
        } else {
            this.namespace.logInfo(this.name, message);
        }
    }
    
    
    logWarn(message) {
        if(typeof this.namespace === 'undefined') {
            console.log('Namespace undefined in plugin \'' + this.name + '\'');
        } else {
            this.namespace.logWarn(this.name, message);
        }
    }
    
    
    logError(message) {
        if(typeof this.namespace === 'undefined') {
            console.log('Namespace undefined in plugin \'' + this.name + '\'');
        } else {
            this.namespace.logError(this.name, message);
        }
    }
    

    send( streamID, obj, callback ) {
    	this.namespace.send(streamID, obj, callback);
    }
}



module.exports = {
    CdrPlugin: CdrPlugin,
    ContentTypeEnum: ContentTypeEnum
}