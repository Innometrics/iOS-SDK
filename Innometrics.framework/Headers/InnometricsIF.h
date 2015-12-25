//
//  InnometricsSDK.h
//  InnometricsSDK
//
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

@interface InnometricsIF : NSObject

+ (void)initializeInjectedFramework;

+ (void)postNotificationForManualTriggerWithName:(NSString *)triggerName;

+ (void)postNotificationForManualTriggerWithName:(NSString *)triggerName
                                          object:(NSObject *)object;

+ (void)postNotificationForManualTriggerWithName:(NSString *)triggerName
                                          object:(NSObject *)object
                                            info:(NSDictionary *)info;

@end
