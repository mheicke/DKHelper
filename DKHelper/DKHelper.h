//
//  DKHelper.h
//  DKHelper
//
//  Created by kevin delord on 24/04/14.
//  Copyright (c) 2014 DK. All rights reserved.
//

#ifndef DKHelper_h__
#define DKHelper_h__

#pragma mark - imports

#import "UIView+DKHelper.h"
#import "UIDevice+DKHelper.h"
#import "NSString+DKHelper.h"
#import "UIImage+DKHelper.h"
#import "NSObject+DKHelper.h"
#import "NSDate+DKHelper.h"
#import "UIColor+DKHelper.h"
#import "CGSize+DKHelper.h"
#import "CGRect+DKHelper.h"
#import "UIImageView+DKHelper.h"
#import "NSNumber+DKHelper.h"
#import "NSArray+DKHelper.h"

#pragma mark - Functions

/**
 * Return a string describing the current version of the application including the build number.
 */
NSString *  appVersion();

CGFloat     degreesToRadians(CGFloat degrees);

CGFloat     radiansToDegrees(CGFloat radians);

#pragma mark - DKLog

// Log
#define __STRING_PRETTY_FUNCTION__                  [NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__]

#if defined (DEBUG)
//# define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
# define DKLog(verbose, fmt, ...) if (verbose) { NSLog(fmt, ##__VA_ARGS__); }
#else
# define DKLog(...) // do nothing
#endif

// App version
#pragma mark - AppVersion
#define DK_APP_VERSION                              appVersion()

// Regex
#define RGX_FILE_EXTENSION                          @".[0-9a-zA-Z]+$"
#define RGX_FILE_NAME_AND_EXTENSION                 @"[0-9a-zA-Z]+.[0-9a-zA-Z]+$"

// Numbers
#pragma mark - Numbers
#define MINMAX(v, min, max)                         ((v <= min) ? min : (v >= max) ? (max) : v )
#define cL(v)                                       (long)(v)
#define cUL(v)                                      (unsigned long)(v)

// NSObjects
#pragma mark - NSObjects
#define OBJECT(dictionary, key)                     ( VALID(dictionary, key) ? [dictionary objectForKey:key] : nil )
#define VALID(dict, key)                            (dict && [dict objectForKey:key] && ![[dict objectForKey:key] isEqual:[NSNull null]])
#define GET_FLOAT(dictionary, key)                  ( VALID(dictionary, key) ? [NSNumber numberWithFloat:[[dictionary objectForKey:key] floatValue]] : nil )
#define GET_NUMBER(dictionary, key)                 ( VALID(dictionary, key) ? [NSNumber numberWithInteger:[[dictionary objectForKey:key] integerValue]] : nil )
#define GET_DATE(dictionary, key)                   ( VALID(dictionary, key) ? [NSDate dateFromISOString:[dictionary objectForKey:key]] : nil )
#define GET_STRING(dictionary, key)                 ( VALID(dictionary, key) ? ( ![[dictionary objectForKey:key] isEqualToString:@""] ? [dictionary objectForKey:key] : nil ) : nil )
#define GET_ASSET_URL(dictionary, key1, key2)       ( VALID(dictionary, key1) ? ( VALID([dictionary objectForKey:key1], key2) ? [[dictionary objectForKey:key1] objectForKey:key2] : nil ) : nil )

// Screen
#pragma mark - Screen
#define iOS7Delta                                   [UIDevice iOS7Delta]
#define is4InchScreen                               ([UIScreen mainScreen].bounds.size.height == 568. && [UIScreen mainScreen].bounds.size.width == 320.)
#define is47InchScreen                              ([UIScreen mainScreen].bounds.size.height == 667. && [UIScreen mainScreen].bounds.size.width == 375.)
#define is55InchScreen                              ([UIScreen mainScreen].bounds.size.height == 960. && [UIScreen mainScreen].bounds.size.width == 540.)

// iOS version
#pragma mark - iOS Version
#define SYSTEM_VERSION_EQUAL_TO(v)                  [UIDevice systemVersionEqualTo:v]
#define SYSTEM_VERSION_GREATER_THAN(v)              [UIDevice systemVersionGreaterThan:v]
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  [UIDevice systemVersionGreaterThanOrEqualTo:v]
#define SYSTEM_VERSION_LESS_THAN(v)                 [UIDevice systemVersionLessThan:v]
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     [UIDevice systemVersionLessThanOrEqualTo:v]

// Predicates
#define OR_PREDICATE(a, b)                          (a ? [NSCompoundPredicate orPredicateWithSubpredicates:@[a, b]] : b)
#define AND_PREDICATE(a, b)                         (a ? [NSCompoundPredicate andPredicateWithSubpredicates:@[a, b]] : b)

// Common File Formats
#define IMAGE_FILE_EXTENSIONS                       NSArray.imageFileExtensions
#define AUDIO_FILE_EXTENSIONS                       NSArray.audioFileExtensions
#define VIDEO_FILE_EXTENSIONS                       NSArray.videoFileExtensions

#endif
