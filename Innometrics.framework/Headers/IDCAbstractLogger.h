//
//  IDCAbstractLogger.h
//  InnometricsSDK
//
//  Created by Vladimir on 18.03.14.
//  Copyright (c) 2014 Sebbia. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IDCAbstractLogger <NSObject>
@optional
- (void)printMessage:(NSString *)message;
@end
