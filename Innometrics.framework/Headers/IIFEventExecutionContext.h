//
//  IIFEventExecutionContext.h
//  Innometrics
//
//  Created by Fedor Pudeyan on 23/07/15.
//  Copyright (c) 2015 APSIS International AB. All rights reserved.
//

@interface IIFEventExecutionContext : NSObject
@property (nonatomic, strong, readonly) NSString *definitionId;

@property (nonatomic, strong, readonly) NSArray *segments;
@property (nonatomic, strong, readonly) NSArray *conditions;
@property (nonatomic, strong, readonly) NSArray *tags;

@property (nonatomic, weak) id target;
@property (nonatomic, strong) NSDictionary *info;
@property (nonatomic, readonly) dispatch_queue_t queue;

- (instancetype)initWithValues:(NSDictionary *)values
                      segments:(NSArray *)segments
                    conditions:(NSArray *)conditions
                          tags:(NSArray *)tags
                  definitionId:(NSString *)definitionId
                         queue:(dispatch_queue_t)queue;


- (void)setValue:(NSObject *)value forName:(NSString *)valueName;

- (NSObject *)valueForName:(NSString *)valueName;


- (NSString *)evaluateString:(NSString *)sourceString excludingValueName:(NSString *)valueToBeExcluded;

- (NSDictionary *)valuesCopy;


@end


