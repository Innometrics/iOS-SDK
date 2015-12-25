//
//  IDCSegmentEvaluationResult.h
//  InnometricsSDK
//
//  Created by Fedor Pudeyan on 07.05.15.
//  Copyright (c) 2015 Innometrics AB. All rights reserved.
//

@interface IDCSegmentEvaluationResult : NSObject

/**
 *  Meaning of success IQL-query result.
 */
@property (nonatomic, readonly) BOOL found;
@property (nonatomic, readonly) NSDictionary * filteredProfile;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
/**
 * returne session data from filtered profile.
 */
- (NSArray *)getSessionDataWithKey:(NSString *)key;
/**
 * returne event data from filtered profile.
 */
- (NSArray *)getEventDataWithKey:(NSString *)key;
/**
 * returne attribute data from filtered profile.
 */
- (NSArray *)getAttributesDataWithKey:(NSString *)key;

@end
