//
//  MPMessageBuilder.h
//
//  Copyright 2015 mParticle, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <CoreLocation/CoreLocation.h>
#import "MPIConstants.h"
#import "MPMediaTrack+Internal.h"

@class MPSession;
@class MPDataModelAbstract;
@class MPMediaTrack;
@class MPCommerceEvent;

@interface MPMessageBuilder : NSObject

@property (nonatomic, strong, readonly, nonnull) NSString *messageType;
@property (nonatomic, strong, readonly, nullable) MPSession *session;
@property (nonatomic, strong, readonly, nonnull) NSDictionary *messageInfo;
@property (nonatomic, unsafe_unretained, readonly) NSTimeInterval timestamp;

+ (nonnull MPMessageBuilder *)newBuilderWithMessageType:(MPMessageType)messageType session:(nonnull MPSession *)session commerceEvent:(nonnull MPCommerceEvent *)commerceEvent;
+ (nonnull MPMessageBuilder *)newBuilderWithMessageType:(MPMessageType)messageType session:(nullable MPSession *)session messageInfo:(nullable NSDictionary<NSString *, id> *)messageInfo;
+ (nonnull MPMessageBuilder *)newBuilderWithMessageType:(MPMessageType)messageType session:(nullable MPSession *)session mediaTrack:(nonnull MPMediaTrack *)mediaTrack mediaAction:(MPMediaAction)mediaAction;
- (nonnull instancetype)initWithMessageType:(MPMessageType)messageType session:(nullable MPSession *)session;
- (nonnull instancetype)initWithMessageType:(MPMessageType)messageType session:(nonnull MPSession *)session commerceEvent:(nonnull MPCommerceEvent *)commerceEvent;
- (nonnull instancetype)initWithMessageType:(MPMessageType)messageType session:(nullable MPSession *)session messageInfo:(nullable NSDictionary<NSString *, id> *)messageInfo;
- (nonnull MPMessageBuilder *)withLaunchInfo:(nonnull NSDictionary *)launchInfo;
- (nonnull MPMessageBuilder *)withLocation:(nonnull CLLocation *)location;
- (nonnull MPMessageBuilder *)withTimestamp:(NSTimeInterval)timestamp;
- (nonnull MPMessageBuilder *)withStateTransition:(BOOL)sessionFinalized previousSession:(nullable MPSession *)previousSession;
- (nonnull MPDataModelAbstract *)build;

@end
