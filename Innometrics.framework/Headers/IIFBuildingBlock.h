//
//  IIFBuildingBlock.h
//  Kitchensink
//
//  Created by Fedor Pudeyan on 25.09.14.
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

//#import "IIFEventDefinition.h"
#import "IIFEventExecutionContext.h"
//#import "IIFExecutable.h"

#define IIF_CLASSNAME_PREFIX @"IIF"

@interface IIFBuildingBlock : NSObject
@property (nonatomic, strong) NSDictionary *arguments;

- (instancetype)initWithArguments:(NSDictionary *)argumentsDictionary;

@end