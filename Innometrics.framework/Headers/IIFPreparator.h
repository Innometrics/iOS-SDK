//
//  IIFPreparator.h
//  Innometrics
//
//  Created by Fedor Pudeyan on 22.10.15.
//  Copyright © 2015 Innometrics AB. All rights reserved.
//

@protocol IIFPreparable <NSObject>

- (void)prepareOnApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

@end

@interface IIFPreparator : NSObject <IIFPreparable>

+ (instancetype)sharedInstance;

- (void)addObjectToPrepare:(NSObject <IIFPreparable> *)object;

@end