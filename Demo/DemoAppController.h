//
//  DemoAppController.h
//  CouchCocoa
//
//  Created by Jens Alfke on 6/1/11.
//  Copyright 2011 Couchbase, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
//  Unless required by applicable law or agreed to in writing, software distributed under the
//  License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
//  either express or implied. See the License for the specific language governing permissions
//  and limitations under the License.

#import <Cocoa/Cocoa.h>
@class CouchDatabase, CouchReplication, DemoQuery, ToyPuller;


/** Generic application delegate for simple Mac OS CouchDB demo apps.
    The name of the (local) database to use should be added to the app's Info.plist
    under the 'DemoDatabase' key. */
@interface DemoAppController : NSObject
{
    IBOutlet NSWindow* _window;
    IBOutlet NSTableView* _table;
    IBOutlet NSArrayController* _tableController;
    
    CouchDatabase* _database;
    DemoQuery* _query;
    CouchReplication *_pull, *_push;
    BOOL _glowing;
    
    ToyPuller* _puller;
}

@property (retain) DemoQuery* query;

- (IBAction) startSync:(id)sender;

- (void) startContinuousSyncWith: (NSURL*)otherDbURL;

@end