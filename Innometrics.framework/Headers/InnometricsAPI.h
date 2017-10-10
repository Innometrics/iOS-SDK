//
//  InnometricsAPI.h
//  Innometrics
//
//  Copyright (c) 2014 APSIS International AB. All rights reserved.
//

#import "INNResult.h"

/**
 *  Class that allows you to communicate with the Innometrics API.
 */
@interface InnometricsAPI : NSObject

/**
 *  Initializes the library, should be called once as early as possible in App's lifecycle
 *
 *  @param token    Your App's token
 */
+ (nullable instancetype)sharedInstanceWithToken:(nullable NSString *)url;


/**
 *  Singleton instance of library. Returns previously initialized library instance.
 */
+ (nullable instancetype)sharedInstance;

/**
 *  Merges local profile to another profile on Profile Cloud and returns result in resultBlock.
 *
 *  @param profileID    Identifier of target Profile
 *  @param resultBlock  Operation result handler (to be posted on the main thread)
 */
- (void)mergeToProfileWithID:(nonnull NSString *)profileID
                      result:(nullable INNResultBlock)resultBlock;

/**
 *  Renews local profile with random id.
 */
- (void)resetProfile;

/**
 *  Renews current Session.
 */
- (void)createSession;

/**
 *  Adds an Event to current Session.
 *
 *  @param definitionID    Event Definition's identifier
 *  @param data            Dictionary with Event data
 */
- (void)trackEvent:(nonnull NSString *)definitionID
              data:(nullable NSDictionary *)data;

/**
 *  Sets a Profile Attribute's data for current Collect App.
 *
 *  @param data   dictionary with Profile attributes
 */
- (void)setProfileAttribute:(nonnull NSDictionary *)data;

/**
 *  Returns an attributes from the current profile, collectApp and section.
 */
- (nullable NSDictionary *)profileAttribute;


/**
 *  Returns an attributes from the current profile and particular collectApp and section.
 *  @param collectApp   desired attribute's collectApp
 *  @param section      desired attribute's section
 */
- (nullable NSDictionary *)profileAttributeFromCollectApp:(nonnull NSString *)collectApp
                                                  section:(nonnull NSString *)section;
/**
 *  Sets a session data for the current session.
 *
 *  @param data   dictionary with Session data
 */
- (void)setSessionData:(nonnull NSDictionary *)data;

/**
 *  Returns a session data from the current session.
 */
- (nullable NSDictionary *)sessionData;

/**
 *  Evaluates segment with current profile and returns result or error in resultBlock
 *
 *  @param segmentID    ID of preconfigured segment
 *  @param resultBlock  Result handler (to be posted on the main thread)
 */
- (void)checkSegmentWithID:(NSUInteger)segmentID
                    result:(nonnull INNResultBlock)resultBlock;

/**
 *  Evaluates segment with current profile and returns result or error in resultBlock
 *
 *  @param query        IQL-expression
 *  @param resultBlock  Result handler (to be posted on the main thread)
 */
- (void)checkSegmentWithQuery:(nonnull NSString *)query
                       result:(nonnull INNResultBlock)resultBlock;

#pragma mark - Injection Framework

/**
 *  Executes preconfigured Event pulling Trigger with certain triggerName.
 *
 *  @param triggerName  Name of the Trigger, could be added in the configs to any Trigger
 *  @param target       An optional target object, which supposedly started current Event
 *  @param info         Additional information, which could be utilized by TriggerInfoValues
 */
- (void)pullTrigger:(nonnull NSString *)triggerName
             target:(nullable NSObject *)target
               info:(nullable NSDictionary *)info;

@end
