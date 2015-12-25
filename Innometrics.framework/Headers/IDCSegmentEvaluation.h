//
//  IDCSegmentEvaluation.h
//  InnometricsSDK
//
//  Created by Fedor Pudeyan on 07.05.15.
//  Copyright (c) 2015 Innometrics AB. All rights reserved.
//

#import "IDCSegmentEvaluationResult.h"

/**
 *  Block definition for a callback to be invoked when IQL request is finished.
 *
 *  @param result IQL request result
 *  @param error  error or nil
 */
typedef void(^IDCSegmentEvaluationBlock)(IDCSegmentEvaluationResult *result, NSError *error);

