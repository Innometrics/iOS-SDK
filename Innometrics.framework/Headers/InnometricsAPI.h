//
//  InnometricsAPI.h
//  InnometricsSDK
//
//  Copyright (c) 2014 Innometrics AB. All rights reserved.
//

#import "IDCSegmentEvaluation.h"

typedef NS_ENUM(NSInteger, IDCResultCode) {
    PROFILE_UPDATED = 1,
    PROFILE_MERGED,
    IQL_EXECUTED
};

/**
 *  Protocol definition for a callback to be invoked when SDK finishes a request.
 */
@protocol InnometricsAPIDelegate <NSObject>
@optional
/**
 *  Callback method to be invoked when SDK request fails with error.
 *
 *  @param error error description
 */
- (void)innometricsDidReceiveError:(NSError *)error;

/**
 *  Callback method to be invoked when SDK request is completed successfullly.
 *
 *  @param response response code
 */
- (void)innometricsDidReceiveResponse:(IDCResultCode)response;

@end

/**
 *  Class that allows you to communicate with the Innometrics API.
 */
@interface InnometricsAPI : NSObject

/**
 *  Object that will recieve callbacks when SDK finishes a request.
 */
@property (nonatomic, strong) id<InnometricsAPIDelegate> delegate;

/**
 *  Returns true if SDK is currently scheduled to periodically send data.
 */
@property (nonatomic, readonly) BOOL inSleep;

/**
 *  When first invoked, creates a new object with temporary user profile.
 */
+ (instancetype)sharedManager;

/**
 *  Enables tracking of all app's uncaught exceptions.
 */
- (void)setTrackUncaughtExceptions:(BOOL)trackUncaughtExceptions;

/**
 *  Sets canonical profile id for the current user.
 *
 *  @param profileId canonical profile id
 */
- (void)setCanonicalProfileId:(NSString *)profileId;

/**
 *  Returns canonical profile id.
 *
 *  @return canonical profile id
 */
- (NSString *)canonicalProfileId;

/**
 *  Sets temporary profile id for the current user.
 *
 *  @param profileId temporary profile id
 */
- (void)setTemporaryProfileId:(NSString *)profileId;

/**
 *  Returns temporary profile id.
 *
 *  @return temporary profile id
 */
- (NSString *)temporaryProfileId;

/**
 *  Resets temporary and canonical profile ID's
 */
- (void)resetProfile;

/**
 *  Adds user event.
 *
 *  @param eventDefinition event definition
 *  @param eventData       event data
 */
- (void)trackEvent:(NSString *)eventDefinition data:(NSDictionary *)eventData;

/**
 *  Adds user error.
 *
 *  @param userError user error
 */
- (void)trackError:(NSError *)userError;

/**
 *  Adds an event which contains information about an exception.
 *
 *  @param caughtException an exception
 */
- (void)trackException:(NSException *)caughtException;

/**
 *  Sets an attribute for the current user profile.
 *
 *  @param key   attribute name
 *  @param value attribute value
 */
- (void)setAttributeWithKey:(NSString *)key value:(NSObject *)value;

/**
 *  Add or replace session data for current session.
 *
 *  @param key   data key
 *  @param value ordinary data which can be a json object, NSString or primitive type
 */
- (void)setSessionDataWithKey:(NSString *)key value:(NSObject *)value;

/**
 *  Merges data from previous temporary profile into current canonical profile.
 */
- (void)mergeProfile;


/**
 *  Executes IQL request.
 *
 *  @param query            IQL-statement
 *  @param filteredProfile  If filteredProfile is set to YES and the result of the segment evaluation is YES, then in callback will be available  filteredProfile dictionary. The filtered profile contains the parts of the profile which matched the segment evaluation. Default value is NO.
 *  @param block            Callback block to be invoked upon request completion
 */
- (void)evaluateQuery:(NSString *)query
      filteredProfile:(BOOL)filteredProfile
             callback:(IDCSegmentEvaluationBlock)block;

/**
 *  Evaluates segment with current profile.
 *
 *  @param segmentId        ID of segment, previously created in GUI
 *  @param filteredProfile  If filteredProfile is set to YES and the result of the segment evaluation is YES, then in callback will be available  filteredProfile dictionary. The filtered profile contains the parts of the profile which matched the segment evaluation. Default value is NO.
 *  @param block            Callback block to be invoked upon request completion
 */
- (void)evaluateSegment:(NSUInteger)segmentId
        filteredProfile:(BOOL)filteredProfile
               callback:(IDCSegmentEvaluationBlock)block;


/**
 *  Evaluates segment with current profile in pseudo-synchronous style.
 *  Caching behavior and timeouts per segment could be set in config
 *
 *  @param segmentId        ID of segment, previously created in GUI
 */
- (BOOL)checkSegmentWithId:(NSUInteger)segmentId;

/**
 *  Forces background synchronization out of schedule.
 */
- (void)forceBackgroundSync;

/**
 *  Suspends background synchronization.
 */
- (void)suspendBackgroundSync;

/**
 *  Resumes background synchronization.
 */
- (void)resumeBackgroundSync;

#pragma mark - Deprecated methods

/**
 *  Executes IQL request. Implementation uses evaluateQuery:filteredProfile:callback: instead with filteredProfile attribute set to YES.
 *
 *  @param iql   IQL-statement
 *  @param block Callback block to be invoked upon request completion
 */
- (void)executeIQL:(NSString *)iql
      withCallback:(IDCSegmentEvaluationBlock)block __attribute__((deprecated));

@end
