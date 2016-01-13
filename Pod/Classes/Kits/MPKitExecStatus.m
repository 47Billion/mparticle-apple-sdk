//
//  MPKitExecStatus.m
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

#import "MPKitExecStatus.h"
#import "MPIConstants.h"
#import "MPLogger.h"

@implementation MPKitExecStatus

- (instancetype)init {
    self = [super init];
    if (!self) {
        return nil;
    }
    
    _kitCode = nil;
    _returnCode = MPKitReturnCodeFail;
    _forwardCount = 0;
    
    return self;
}

- (instancetype)initWithSDKCode:(NSNumber *)kitCode returnCode:(MPKitReturnCode)returnCode {
    return [self initWithSDKCode:kitCode returnCode:returnCode forwardCount:(returnCode == MPKitReturnCodeSuccess ? 1 : 0)];
}

- (instancetype)initWithSDKCode:(NSNumber *)kitCode returnCode:(MPKitReturnCode)returnCode forwardCount:(NSUInteger)forwardCount {
    NSAssert(!MPIsNull(kitCode), @"'kitCode' is a required parameter.");
    
    if (MPIsNull(kitCode)) {
        MPLogError(@"'kitCode' is a required parameter.");
        return nil;
    }
    
    self = [self init];
    
    _kitCode = kitCode;
    _returnCode = returnCode;
    _forwardCount = forwardCount;
    
    return self;
}

#pragma mark Public accessors
- (BOOL)success {
    return _returnCode == MPKitReturnCodeSuccess;
}

#pragma mark Public methods
- (void)incrementForwardCount {
    ++_forwardCount;
}

@end
