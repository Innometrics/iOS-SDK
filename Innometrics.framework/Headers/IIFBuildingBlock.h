//
//  IIFBuildingBlock.h
//  Kitchensink
//
//  Created by Fedor Pudeyan on 25.09.14.
//  Copyright (c) 2014 APSIS International AB. All rights reserved.
//

#import "IIFEventExecutionContext.h"

@interface IIFBuildingBlock : NSObject
@property (nonatomic, strong) NSDictionary *arguments;

- (instancetype)initWithArguments:(NSDictionary *)argumentsDictionary;

@end
