/****************************************************************************
 *
 *   Copyright (c) 2018 Windhover Labs, L.L.C. All rights reserved.
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

'use strict';
/*
 * Commander client object
 */
var CommanderClient = CommanderClient || {};
CommanderClient.prototype.__proto__ = EventEmitter.prototype;

/**
 * Commander client connects with node server to send commands and receive
 * telemetry via socketIO
 * 
 * @constructor
 */
function CommanderClient() {
    /**
     * Socket connection check
     * 
     * @type {Boolean}
     */
    this.isSocketConnected = false;
    /**
     * Declares socket
     * 
     * @type {Object}
     */
    this.socket;
    /**
     * Declares and initializes subscriptions to store already subscribe to
     * opsPaths
     * 
     * @type {Object}
     */
    this.subscriptions = {};

    this.videoConnected = false;

    // cu.logInfo( 'Clinet | CommanderClient' );
    /* Connect */
    this.connect();

    var self = this;

    this.requestInterval = setInterval(function() {
        var tlmSubOpsPaths = [];
        var tlmUnsubOpsPaths = [];

        for ( var opsPath in self.subscriptions) {
            var subscription = self.subscriptions[opsPath];

            if (subscription.pendingAction == 'subscribe') {
                subscription.pendingAction = '';
                tlmSubOpsPaths.push(opsPath);
            } else if (subscription.pendingAction == 'unsubscribe') {
                subscription.pendingAction = '';
                tlmUnsubOpsPaths.push(opsPath);
                delete self.subscriptions[opsPath];
            }
        }

        if (tlmSubOpsPaths.length > 0) {
            self.socket.emit('subscribe', tlmSubOpsPaths);
        }

        if (tlmUnsubOpsPaths.length > 0) {
            self.socket.emit('unsubscribe', tlmUnsubOpsPaths);
        }

        self.socket.emit('getMessageIDsAndMacros', {}, function(results) {
        });
    }, 1000);
}

/**
 * Check if socket is connected
 * 
 * @return {boolean} if true socket is connected, otherwise returns false
 */
CommanderClient.prototype.isSocketConnected = function() {
    /* TODO */
    return isSocketConnected;
};

/**
 * Sends a ping to server
 */
CommanderClient.prototype.ping = function(startTime) {
    this.socket.emit('PING', startTime);
};

/**
 * Acts on receiveing a pong
 */
CommanderClient.prototype.pong = function(cb) {
    this.socket.on('PONG', function(startTime) {
        cb(startTime);
    });

};

/**
 * Get a directory listing of layout or .lyt files
 * 
 * @param {String}
 *                path Starting path of directory
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getLayouts = function(path, cb) {
    var self = this;

    this.socket.emit('getLayouts', path, function(result) {
        cb(result);
    });
};

CommanderClient.prototype.callPlugin = function(pluginName, funcName, args, cb) {
    this.socket.emit('pluginFunction', pluginName, funcName, args, function(
            results) {
        cb(results)
    });
};

/**
 * Get a directory listing of panels of .pug files
 * 
 * @param {String}
 *                path Starting path of directory
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getPanels = function(path, cb) {
    this.socket.emit('getPanels', path, function(result) {
        cb(result);
    });
};

/**
 * Get a directory listing of widget of .pug files
 * 
 * @param {String}
 *                path Starting path of directory
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getWidgets = function(path, cb) {
    this.socket.emit('getWidgets', path, function(result) {
        cb(result);
    });
};

/**
 * Save widgets
 * 
 * @param {Object}
 *                widInfoObj this object used to generate widgets
 */
CommanderClient.prototype.saveWidgets = function(widInfoObj) {
    /* save widget state stub */
    // TODO: add feature to save this object at server side.
    if (widInfoObj != undefined) {
        localStorage.setItem("widgetState", JSON.stringify(widInfoObj));
    }
};

/**
 * Load widgets
 * 
 * @param {Function}
 *                cb callback
 */
CommanderClient.prototype.loadWidgets = function(cb) {
    /* load widget state stub */
    // TODO: add feature to retrieve result from server side.
    if (localStorage.widgetState != undefined
            && typeof JSON.parse(localStorage.widgetState) == 'object') {
        cb(JSON.parse(localStorage.widgetState))
    } else {
        // cu.logError( 'loadWidgets | no widget state may be available' );
    }
};

/**
 * Gets default layout configuration
 * 
 * @param {Function}
 *                cb callback on response
 */
CommanderClient.prototype.getDefaultLayout = function(cb) {
    this.socket.emit('getDefaultLayout', function(result) {
        cb(result);
    });
}

/**
 * Get random number
 * 
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getRandom = function(cb) {
    setInterval(function() {
        var random_boolean = Math.random() >= 0.5;
        cb(random_boolean);
    }, 500);
};

/**
 * Subscribe to video stream
 * 
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.enableVideoStream = function(cb) {
    var self = this;
    self.videoConnected = true;

    this.socket.emit('enable-stream', 'video-stream');

    this.socket.on('video-stream', function(msg) {
        if (self.videoConnected) {
            cb(msg)
        }
    });
}

/**
 * Unsubscribe to video stream
 * 
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.disableVideoStream = function() {
    // this.socket.emit( 'disable-stream', 'video-stream');
    this.videoConnected = false;
}

/**
 * Gets ADSB data in JSON
 * 
 * @param {Number}
 *                interval Time interval
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getADSBJson = function(interval, cb) {
    if (this.adsbInterval != undefined) {
        try {
            this.clearADSBInterval();
        } catch (ex) {
            // cu.logError( 'unable to clear ADSB interval ' );
        }
    }
    this.adsbInterval = setInterval(function() {
        this.socket.emit('getADSBJson', function(result) {
            cb(result);
        });
    }, interval);
}

/**
 * Clears adsb interval
 */
CommanderClient.prototype.clearADSBInterval = function() {
    window.clearInterval(this.adsbInterval);
    this.adsbInterval = undefined;
}

/**
 * Get directory listing
 * 
 * @param {String}
 *                path Directory root path
 * @param {String}
 *                extension File extension
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getDirectoryListing = function(path, extension, cb) {
    var re = /(?:\.([^.]+))?$/;

    if (this.isSocketConnected) {
        this.socket.emit('getDirectoryListing', path, function(result) {
            var entries = [];
            var dirEntries = result.files;

            for (var i = 0; i < dirEntries.length; ++i) {
                var entry = dirEntries[i];

                if (entry.hasOwnProperty('type')) {
                    if (entry.type == 'dir') {
                        /* This is a directory. */
                        entries.push(entry);
                    } else {
                        var ext = re.exec(entry.name)[1];

                        if (ext != null) {
                            if (ext == extension) {
                                entries.push(entry);
                            }
                        } else {
                            entries.push(entry);
                        }
                    }
                } else {
                    entries.push(entry);
                }
            }

            cb(entries);
        });
    }
    ;
};

/**
 * Get views
 * 
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getViews = function(cb) {
    if (this.isSocketConnected) {
        this.socket.emit('getViews', function(views) {
            cb(views);
        });
    }
    ;
};

/**
 * Get command definition
 * 
 * @param {Object}
 *                cmdObj Command information
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getCmdDef = function(cmdObj, cb) {
    if (this.isSocketConnected) {
        this.socket.emit('getCmdDef', cmdObj, function(cmdDef) {
            try {
                var outCmdDef = {
                    name : cmdDef.opsPath,
                    argument : cmdDef.args
                };
                cb(outCmdDef);
            } catch (e) {
                // cu.logError( 'loadCommanding | command definition cannot be
                // loaded. ' + e );
            }
        });
    }
    ;
};

/**
 * Get telemetry definition
 * 
 * @param {Object}
 *                tlmObj Telemetry information
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.getTlmDefs = function(tlmObj, cb) {
    if (this.isSocketConnected) {
        this.socket.emit('getTlmDefs', tlmObj, function(tlmDef) {
            cb(tlmDef);
        });
    }
};

/**
 * Updates Telemetry by calling the given callback on newly received tlm
 * database
 * 
 * @param {Object}
 *                items Telemetry uptate items
 */
CommanderClient.prototype.updateTelemetry = function(items) {
    var self = this;
    var subscribersToUpdate = {};

    /*
     * We want to make sure that the subscribers get all the variables they
     * subscribed to in a single callback. So if a subscriber subscribed to an
     * array of multiple items, we want to collect all those items in a single
     * array, and send that to the subscriber. So the first step is to build an
     * array of subscribers, each with an array of all the messages they
     * subscribed to that arrived in this update. To do this first we loop
     * through the items to find their subscribers.
     */
    for ( var opsPath in items) {
        if (self.subscriptions.hasOwnProperty(opsPath)) {
            var subscription = self.subscriptions[opsPath];

            /*
             * Loop through all the subscriber callbacks assigned to this item.
             */
            for ( var i in subscription.cb) {
                var cbID = subscription.cb[i];
                
                if (subscribersToUpdate.hasOwnProperty(cbID.id)) {
                    /*
                     * This subscription must have already got a item queued up
                     * for it in this call because it already has an entry. Just
                     * get a handle to the subscriber record.
                     */
                    var subscriptionUpdate = subscribersToUpdate[cbID.id];
                    
                } else {
                    /*
                     * This is the first time we've added an item to this
                     * subscribers shopping cart in this call. Create an entry
                     * for this subscription.
                     */
                    var subscriptionUpdate = {
                        cbID : cbID,
                        items : []
                    };
                    subscribersToUpdate[cbID.id] = subscriptionUpdate;
                }

                /*
                 * Great. Now we have the subscription entry. Now build up an
                 * object and push the this new item onto the items array.
                 */
                var param = {
                    sample : items[opsPath].sample,
                    opsPath : opsPath
                };
                subscriptionUpdate.items.push(param);
            }
        } else {
            console.log('Received unexpected telemetry update for ' + opsPath);
        }
    }

    /*
     * Now that we've built up a list of subscriptions to update. Loop through
     * the list and send the updates.
     */
    for ( var cbID in subscribersToUpdate) {
        var subUpdate = subscribersToUpdate[cbID];

        var cb = subUpdate.cbID.cb;

        if (typeof cb === 'function') {
            cb(subUpdate.items);
        } else {
        	console.log('Callback is not a function');
        }
    }
}

/**
 * Unsubscribe unused telemetry
 * 
 * @param {Object}
 *                tlmObj Telemetry object
 */
CommanderClient.prototype.unsubscribe = function(tlmObj) {
    if (this.isSocketConnected) {
        for (var i = 0; i < tlmObj.length; ++i) {
            var opsPath = tlmObj[i].name;
        	
            /* Has this opsPath already been subscribed to? */
            if (this.subscriptions.hasOwnProperty(opsPath) == false) {
                /*
                 * We have not subscribed to this yet. Don't worry about this
                 * one.
                 */
            } else {
                var subscription = this.subscriptions[opsPath];
                subscription.refCount--;
                if (subscription.refCount <= 0) {
                    /*
                     * There are no more subscribers for this opsPath. Schedule
                     * it to be unsubscribed.
                     */
                    this.subscriptions[opsPath].pendingAction = 'unsubscribe';
                    this.subscriptions[opsPath].cb = [];
                }
            }
        }
    }
};

/**
 * Unsubscribe all telemetry
 * 
 * @param {Object}
 *                tlmObj Telemetry object
 */
CommanderClient.prototype.unsubscribeAll = function() {
    if (this.isSocketConnected) {
        for(var opsPath in this.subscriptions) {
            this.subscriptions[opsPath].pendingAction = 'unsubscribe';
            this.subscriptions[opsPath].cb = [];
            this.subscriptions[opsPath].refCount = 0;
        }
    }
};

/**
 * Subscribe to telemetry
 * 
 * @param {Object}
 *                tlmObj Telemetry Object
 * @param {Function}
 *                cb Callback
 */
CommanderClient.prototype.subscribe = function(tlmObj, cb) {
    if (this.isSocketConnected) {
        /* Add the callback to the subscription. */
        var id = randomIdGenerator();
        var cbID = {
            cb: cb,
            id: id
        };
        
        for (var i = 0; i < tlmObj.length; ++i) {
            var opsPath = tlmObj[i].name;

            /* Has this opsPath already been subscribed to? */
            if (this.subscriptions.hasOwnProperty(opsPath) == false) {
                /*
                 * We have not subscribed to this yet. Add a new object and
                 * schedule a subscribe request to the server.
                 */
                this.subscriptions[opsPath] = {
                    pendingAction : 'subscribe',
                    cb : [],
                    refCount : 0
                };
            }
            this.subscriptions[opsPath].cb.push(cbID);
            this.subscriptions[opsPath].refCount++;
        }
        
        return id;
    }
    
    return undefined;
};

/**
 * Send commands
 * 
 * @param {Object}
 *                cmdObj Command object
 */
CommanderClient.prototype.sendCommand = function(cmdObj, cb) {
    // cu.logInfo( 'Client | sent command : ', JSON.stringify( cmdObj, 2 ) );
    if (this.isSocketConnected) {
        this.socket.emit('sendCmd', cmdObj, cb);
    };
};

/**
 * Query configuration database
 * 
 * @param {Object}
 *                path XPath style query string
 */
CommanderClient.prototype.queryConfigDB = function(path, cb) {
    // cu.logInfo( 'Client | query config DB : ', JSON.stringify( path, 2 ) );
    if (this.isSocketConnected) {
        this.socket.emit('queryConfigDB', path, cb);
    };
};

/**
 * Get the communication socket
 */
CommanderClient.prototype.getSocket = function() {
    return this.socket;
};

/**
 * Connect to socket
 */
CommanderClient.prototype.connect = function() {
    var self = this;

    this.socket = io({
        reconnection : true,
        reconnectionAttempts : Infinity,
        reconnectionDelay : 1000,
        reconnectDelayMax : 5000,
        autoConnect : true,
        timeout : 5000
    });

    this.socket.on('connect', function() {
        /* Connection established. */
        self.isSocketConnected = true;
        self.emit('connect');
    });

    this.socket.on('connect_error', function(error) {
        /* Connection error. */
        self.isSocketConnected = false;
        self.emit('connect_error', error);
    });

    this.socket.on('connect_timeout', function() {
        /* Connection timeout. */
        self.isSocketConnected = false;
        self.emit('connect_timeout');
    });

    this.socket.on('reconnect', function(number) {
        /* Reconnect occured. */
        self.isSocketConnected = true;
        self.emit('reconnect');
    });

    this.socket.on('reconnect_attempt', function() {
        /* Reconnecting. */
        self.isSocketConnected = false;
        self.emit('reconnect_attempt');
    });

    this.socket.on('reconnecting', function(number) {
        /* Reconnect error occured */
        self.isSocketConnected = false;
        self.emit('reconnecting', number);
    });

    this.socket.on('reconnect_error', function(error) {
        /* Reconnect error occured */
        self.isSocketConnected = false;
        self.emit('reconnect_error', error);
    });

    this.socket.on('reconnect_failed', function() {
        /* Reconnect failed. */
        self.isSocketConnected = false;
        self.emit('reconnect_failed');
    });

    this.socket.on('telemetry-update', function(items) {
        self.updateTelemetry(items);
    });
};



function uniqueId() {
    const firstItem = {
        value: "0"
    };
    /*length can be increased for lists with more items.*/
    let counter = "123456789".split('')
        .reduce((acc, curValue, curIndex, arr) => {
            const curObj = {};
            curObj.value = curValue;
            curObj.prev = acc;

            return curObj;
        }, firstItem);
    firstItem.prev = counter;

    return function () {
        let now = Date.now();
        if (typeof performance === "object" && typeof performance.now === "function") {
            now = performance.now().toString().replace('.', '');
        }
        counter = counter.prev;
        return `${now}${Math.random().toString(16).substr(2)}${counter.value}`;
    }
}

const randomIdGenerator = uniqueId();