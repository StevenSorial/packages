// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Foundation/Foundation.h>

#if TARGET_OS_OSX
#import <FlutterMacOS/FlutterMacOS.h>
#else
#import <Flutter/Flutter.h>
#endif

// A cross-platform display link abstraction.
@protocol FVPDisplayLink <NSObject>

/// Whether the display link is currently running (i.e., firing events).
///
/// Defaults to NO.
@property(nonatomic, assign) BOOL running;

/// The time interval between screen refresh updates.
@property(nonatomic, readonly) CFTimeInterval duration;

@end

// An implementation of FVPDisplayLink using CADisplayLink.
API_AVAILABLE(ios(4.0), macos(14.0))
@interface FVPCADisplayLink : NSObject <FVPDisplayLink>

/// Initializes a display link that calls the given callback when fired.
///
/// The display link starts paused, so must be started, by setting 'running' to YES, before the
/// callback will fire.
- (instancetype)initWithRegistrar:(id<FlutterPluginRegistrar>)registrar
                         callback:(void (^)(void))callback NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

#if TARGET_OS_OSX
// An implementation of FVPDisplayLink using CVDisplayLink.
@interface FVPCoreVideoDisplayLink : NSObject <FVPDisplayLink>

/// Initializes a display link that calls the given callback when fired.
///
/// The display link starts paused, so must be started, by setting 'running' to YES, before the
/// callback will fire.
- (instancetype)initWithRegistrar:(id<FlutterPluginRegistrar>)registrar
                         callback:(void (^)(void))callback NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end
#endif
