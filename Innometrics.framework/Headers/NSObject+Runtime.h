//
//  NSObject+Runtime.h
//  InnometricsSDK
//
//  Created by Vladimir on 13.03.14.
//  Copyright (c) 2014 Sebbia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Runtime)

- (NSArray *)objc_properties;
- (NSString *)typeOfPropertyNamed:(NSString *)name;

@end
