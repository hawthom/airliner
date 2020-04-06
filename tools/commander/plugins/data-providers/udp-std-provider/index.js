/*******************************************************************************
 * 
 * Copyright (c) 2018 Windhover Labs, L.L.C. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer. 2. Redistributions in
 * binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution. 3. Neither the name Windhover Labs
 * nor the names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 ******************************************************************************/

'use strict';

const net = require( 'net' );
const events = require( 'events' );
const emitter = require( 'events' ).EventEmitter;
const convict = require( 'convict' );
const dgram = require( 'dgram' );
const path = require( 'path' );
const autoBind = require('auto-bind');
const CdrGroundPlugin = require(path.join(global.CDR_INSTALL_DIR, '/commander/classes/CdrGroundPlugin')).CdrGroundPlugin;


class UdpStdProvider extends CdrGroundPlugin {
	/**
	 * Constructor for UdpStdProvider
	 * 
	 * @param {Object}
	 *                configObj configuration object containing mandatory and
	 *                optional parameters.  
	 *                {
	 *                    namespace: 'airliner', 
	 *                    name:      'fsw-connector', 
	 *                    workspace:  global.CDR_WORKSPACE, 
	 *                    configFile: `${global.CDR_WORKSPACE}/etc/udpstdprovider-config.json`}
	 *                }
	 *                
	 * @constructor
	 */
    constructor(configObj) {
        configObj.webRoot = path.join( __dirname, 'web');  
        super(configObj);
    	
    	autoBind(this);

        /* Initialize the configuration. */
        this.initConfig(configObj.name, configObj.configFile);
        
        /* Initialize server side housekeeping telemetry that we'll publish 
         * later. */
        this.initTelemetry();
        
        /* Initialize the network socket. */
        this.initNetwork();

        /* Initialize client side interface. */
        this.initClientInterface();

        /* Initialize server side commands. */
        this.initCommands();

        this.logInfo( 'Initialized' );
    };
    
    
    processOutgoingBuffer(buffer) {
        if (!this.udpTxEnable) {
            return;
        }
        this.hk.content.msgSentCount++;
        this.sender.send( buffer, 0, buffer.length, this.hk.content.outPort, this.hk.content.outAddress);
    }
    
    
    processIncomingBuffer(buffer, rinfo) {
        if (!this.udpRxEnable) {
            return;
        }
        this.hk.content.msgRecvCount++;
        this.send( this.hk.content.outputStreamID, buffer );
    }
    
    
    startListener() {
        try {        
            var self = this;
            
            /* Start listening for data to send out the socket. */
            this.namespace.recv( this.config.get( 'inputStreamID' ), this.processOutgoingBuffer);
            
            this.listener = dgram.createSocket( {type: 'udp4', reuseAddr: true} );
    
            this.listener.on( 'listening', function() {
                const listenerAddress = self.listener.address();
                self.logInfo(`UDP connector listening ${listenerAddress.address}:${listenerAddress.port}` );
            } );
            
            this.listener.bind( this.hk.content.inPort, function() {            
                self.listener.on( 'message', self.processIncomingBuffer);
    
                self.listener.on( 'error', function(err) {
                    self.logError( `UDP connector error:\n${err}.` );
                } );
            });   
            
            return true;
        } catch(err) {
            this.logError('Failed to bind.  ' + err);
            return false;
        }
    }
    
    
    initConfig(name, configFile) {
    	var config;
    	
        /**
         * Define varibale server schema
         * 
         * @type {Object}
         */
        this.config = convict( {
            env: {
                doc: 'The application environment.',
                format: [ 'production', 'development', 'test' ],
                default: 'development',
                env: 'NODE_ENV'
            },
            inPort: {
                doc: 'Input port.',
                format: 'int',
                default: 0
            },
            outPort: {
                doc: 'Output port.',
                format: 'int',
                default: 0
            },
            outAddress: {
                doc: 'Output IP address.',
                format: 'ipaddress',
                default: '127.0.0.1'
            },
            outputStreamID: {
                doc: 'Output binary stream from binary data provider to the encoder/decoder.',
                format: String,
                default: ''
            },
            inputStreamID: {
                doc: 'Input binary stream from encoder/decoder to binary data provider.',
                format: String,
                default: ''
            },
            udpTxEnable: {
                doc: 'Flag to enable transmit on UDP plugin.',
                format: Boolean,
                default: false
            },
            udpRxEnable: {
                doc: 'Flag to enable receive on UDP plugin.',
                format: Boolean,
                default: false
            }
        } );

        /* Load environment dependent configuration */
        this.config.loadFile( configFile );

        /* Perform validation */
        this.config.validate( {
            allowed: 'strict'
        } );
        
        this.config.name = name;
        
        /* Initialize tx/rx enable flags */
        this.udpTxEnable = this.config.get('udpTxEnable')
        this.udpRxEnable = this.config.get('udpRxEnable')
     }
    
    
    initTelemetry() {
        this.hk = {
            opsPath: '/' + this.config.name + '/hk',
            content: {
                cmdAcceptCount: 0,
                cmdRejectCount: 0,
                inPort: this.config.get( 'inPort' ),
                outPort: this.config.get( 'outPort' ),
                outAddress: this.config.get( 'outAddress' ),
                msgSentCount: 0,
                msgRecvCount: 0,
                inputStreamID: this.config.get( 'inputStreamID' ),
                outputStreamID: this.config.get( 'outputStreamID' ),
                udpTxEnable: this.config.get( 'udpTxEnable' ),
                udpRxEnable: this.config.get( 'udpRxEnable' )
            }
        };
        this.addTelemetry(this.hk, 1000);
    }
    
    
    initNetwork() {
        this.sender = dgram.createSocket( 'udp4' );
        
        this.startListener();
    }
    
    
    
    initClientInterface() {
        var content = {};
        
        content[this.config.name] = {
            shortDescription: 'Standard UDP Provider (' + this.config.name + ')',
            longDescription: 'Standard UDP Provider (' + this.config.name + ')',
            nodes: {
                main: {
                    type: CdrGroundPlugin.ContentType.LAYOUT,
                    shortDescription: 'Main',
                    longDescription: 'Main.',
                    filePath: '/main_layout.lyt',
                    handlebarsContext: {
                        pluginName: this.config.name
                    }
                },
                hk: {
                    type: CdrGroundPlugin.ContentType.PANEL,
                    shortDescription: 'Housekeeping',
                    longDescription: 'Housekeeping',
                    filePath: '/hk.pug',
                    handlebarsContext: {
                        pluginName: this.config.name
                    }
                }
            }
        }
        
        this.addContent(content);
    }
    
    
    initCommands() {
        var cmdSetInput = {
            opsPath: '/' + this.config.name + '/setInput',
            args: [
                {
                    name:    'Port',
                    type:    'uint16',
                    bitSize: 16
                }
            ]
        }
        this.addCommand(cmdSetInput, this.setInput);

        var cmdSetOutput = {
            opsPath: '/' + this.config.name + '/setOutput',
            args: [
                {
                    name:    'Port',
                    type:    'uint16',
                    bitSize: 16
                },{
                    name:    'Address',
                    type:    'char',
                    bitSize: 1024
                }
            ]
        };
        this.addCommand(cmdSetOutput, this.setOutput);
 
        var cmdToggleUdpTxEnable = {
            opsPath: '/' + this.config.name + '/toggleUdpTxEnable',
            args: [
            ]
        }
        this.addCommand(cmdToggleUdpTxEnable, this.toggleUdpTxEnable);

        var cmdToggleUdpRxEnable = {
            opsPath: '/' + this.config.name + '/toggleUdpRxEnable',
            args: [
            ]
        }
        this.addCommand(cmdToggleUdpRxEnable, this.toggleUdpRxEnable);

    }
    
    
    setInput(cmd) {
        var self = this;
        
    	if(cmd.hasOwnProperty('args') == false) {
            this.logError('Invalid arguments.  Port is required.');
    	} else {
            var port = parseInt(cmd.args.Port);
            if(isNaN(port)) {
                this.hk.content.cmdRejectCount++;
                this.logError('Invalid data type for port.  Must be a number.');
            } else if(port < 1024 || port > 65535) {
        	    this.hk.content.cmdRejectCount++;
        	    this.logError('Invalid port.  Must be between 1024 and 65535.');
            } else {
        	    this.logInfo('Commanded to bind to port ' + port);
        	    this.listener.close(function () {
        	        self.hk.content.inPort = port;
                    if(self.startListener()) {
                        self.hk.content.cmdAcceptCount++;
                    } else {
                        self.hk.content.cmdRejectCount++;
                    }
                });
            }
    	}
    };
    
    
    setOutput(cmd) {
    	if(cmd.hasOwnProperty('args') == false) {
            this.logError('Invalid arguments.  Port is required.');
    	} else {
            var port = parseInt(cmd.args.Port);
            if(isNaN(port)) {
                this.hk.content.cmdRejectCount++;
                this.logError('Invalid data type for port.  Must be a number.');
            } else if(port < 1024 || port > 65535) {
                this.hk.content.cmdRejectCount++;
                this.logError('Invalid port.  Must be between 1024 and 65535.');
            } else {
                this.logInfo('Commanded to set output to \'' + cmd.args.Address + ':' + port + '\'');
                this.hk.content.outPort = port;
                this.hk.content.outAddress = cmd.args.Address;
                this.hk.content.cmdAcceptCount++;
            }
    	}
    }

    toggleUdpTxEnable(cmd) {
        var self = this;
        this.udpTxEnable = !this.udpTxEnable;
        this.hk.content.udpTxEnable = this.udpTxEnable; 
    };

    toggleUdpRxEnable(cmd) {
        var self = this;
        this.udpRxEnable = !this.udpRxEnable;
        this.hk.content.udpRxEnable = this.udpRxEnable; 
    };

}



exports = module.exports = UdpStdProvider;
