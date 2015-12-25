//
//  IDCLogger.h
//  InnometricsSDK
//
//  Created by Vladimir on 18.03.14.
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCAbstractLogger.h"

@interface IDCLogger : NSObject <IDCAbstractLogger>

@property (nonatomic, strong) id<IDCAbstractLogger> delegate;

+ (instancetype)logger;

- (instancetype)initWithDelegate:(id<IDCAbstractLogger>)delegate;

- (void)log:(NSString *)format, ... ;

@end
