//
//  IIFTag.h
//  InnometricsSDK
//
//  Created by Fedor Pudeyan on 18.09.14.
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

#import "IIFEventExecutionContext.h"

@protocol IIFTag <NSObject>

- (void)runInContext:(IIFEventExecutionContext *)context;

@end