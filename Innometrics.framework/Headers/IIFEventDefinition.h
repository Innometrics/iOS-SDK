//
//  IIFEventDefinition.h
//  InnometricsSDK
//
//  Created by Fedor Pudeyan on 18.09.14.
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

typedef void(^IIFEventDefinitionDataBlock)(NSDictionary *values, NSArray *segments, NSArray *conditions, NSArray *tags, NSString *definitionId, dispatch_queue_t queue);

@protocol IIFEventDefinition <NSObject>

- (instancetype)initWithDictionary:(NSDictionary *)dictionary executionQueue:(dispatch_queue_t)queue;

- (void)retrieveDataUsingBlock:(IIFEventDefinitionDataBlock)block;

@end

@interface IIFEventDefinition : NSObject <IIFEventDefinition>

@end

@protocol IIFExecutionInitiator <NSObject>

- (void)setEventDefinition:(id <IIFEventDefinition>)eventDefinition;

- (id <IIFEventDefinition>)eventDefinition;

@end
