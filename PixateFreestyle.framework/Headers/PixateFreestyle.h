/*
 * Copyright 2012-present Pixate, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  PixateFreestyle.h
//
//  Created by Paul Colton on 12/11/12.
//  Copyright (c) 2012 Pixate, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <PixateFreestyle/PXVirtualControl.h>
#import <PixateFreestyle/PXStyleable.h>
#import <PixateFreestyle/UIColor+PXColors.h>
#import <PixateFreestyle/UINavigationItem+PXStyling.h>
#import <PixateFreestyle/UITabBarItem+PXStyling.h>
#import <PixateFreestyle/UIBarButtonItem+PXStyling.h>
#import <PixateFreestyle/NSDictionary+PXCSSEncoding.h>
#import <PixateFreestyle/UIView+PXStyling.h>
#import <PixateFreestyle/PixateFreestyleConfiguration.h>
#import <PixateFreestyle/PXStylesheet.h>
#import <PixateFreestyle/PixateFreestyleConfiguration.h>
#import <PixateFreestyle/PXStyleUtils.h>
#import <PixateFreestyle/PXViewUtils.h>
#import <PixateFreestyle/PXRuleSet.h>
#import <PixateFreestyle/PXSpecificity.h>
#import <PixateFreestyle/PXTypeSelector.h>
#import <PixateFreestyle/PXDeclarationContainer.h>
#import <PixateFreestyle/PXDeclaration.h>
#import <PixateFreestyle/PXPaint.h>
#import <PixateFreestyle/PXShadow.h>
#import <PixateFreestyle/PXDimension.h>
#import <PixateFreestyle/PXOffsets.h>
#import <PixateFreestyle/PXBorderInfo.h>
#import <PixateFreestyle/PXShadowPaint.h>
#import <PixateFreestyle/PXSelector.h>
#import <PixateFreestyle/PXSourceEmitter.h>
#import <PixateFreestyle/PXSourceWriter.h>
#import <PixateFreestyle/PXStylesheet-Private.h>
#import <PixateFreestyle/PXStylesheetParser.h>
#import <PixateFreestyle/PXMediaGroup.h>
#import <PixateFreestyle/PXKeyframe.h>
#import <PixateFreestyle/PXKeyframeBlock.h>
#import <PixateFreestyle/PXParser.h>
#import <PixateFreestyle/PXParserBase.h>
#import <PixateFreestyle/PXStylesheetLexer.h>
#import <PixateFreestyle/PXStylesheetLexeme.h>
#import <PixateFreestyle/PXLexeme.h>
#import <PixateFreestyle/PXMediaExpression.h>
#import <PixateFreestyle/PXStylerContext.h>
#import <PixateFreestyle/PXCacheManager.h>
#import <PixateFreestyle/PXForceLoadPixateCategories.h>
#import <PixateFreestyle/PXForceLoadStylingCategories.h>
#import <PixateFreestyle/PXForceLoadVirtualCategories.h>
#import <PixateFreestyle/PXForceLoadControls.h>
#import <PixateFreestyle/PXForceLoadCGCategories.h>
#import <PixateFreestyle/PXAnimationInfo.h>
#import <PixateFreestyle/PXBoundable.h>
#import <PixateFreestyle/PXBoxModel.h>
#import <PixateFreestyle/PXPaintable.h>
#import <PixateFreestyle/PXRenderable.h>
#import <PixateFreestyle/PXShadowGroup.h>
#import <PixateFreestyle/PXShape.h>
#import <PixateFreestyle/PXShapeDocument.h>
#import <PixateFreestyle/PXStrokeRenderer.h>
#import <PixateFreestyle/PXStyleTreeInfo.h>

//! Project version number for PixateFreestyle.
FOUNDATION_EXPORT double PixateFreestyleVersionNumber;

//! Project version string for PixateFreestyle.
FOUNDATION_EXPORT const unsigned char PixateFreestyleVersionString[];

/**
 * This is the main entry point into the Pixate Engine
 */
@interface PixateFreestyle : NSObject

/**
 * The version number of the Pixate Engine
 */
+ (NSString *)version;

/**
 * The build date of this version of the Pixate Engine
 */
+ (NSDate *)buildDate;

/**
 * The api integer version of the API
 */
+ (int)apiVersion;

/*
 * Are we in Appcelerator Titanium mode
 */
+ (BOOL)titaniumMode;

/**
 *  A property used to configure options in the Pixate
 */
+ (PixateFreestyleConfiguration *)configuration;

/**
 * This property, when set to YES, automatically refreshes
 * styling when the orientation of your device changes. This is
 * set to NO by default.
 */
+ (BOOL)refreshStylesWithOrientationChange;
+ (void)setRefreshStylesWithOrientationChange:(BOOL)value;

/**
 *  This is required before styling can occur.
 */
+ (void) initializePixateFreestyle;

/**
 *  Return a collection of all styleables that match the specified selector. Note that the selector runs against views
 *  that are in the current view tree only.
 *
 *  @param styleable The root of the tree to search
 *  @param source The selector to use for matching
 */
+ (NSArray *)selectFromStyleable:(id<PXStyleable>)styleable usingSelector:(NSString *)source;

/**
 *  Return a string representation of all active rule sets matching the specified styleable
 *
 *  @param styleable The styleable to match
 */
+ (NSString *)matchingRuleSetsForStyleable:(id<PXStyleable>)styleable;

/**
 *  Return a string representation of all active declarations that apply to the specified styleable. Note that the list
 *  shows the result of merging all matching rule sets, taking specificity and duplications into account.
 *
 *  @param styleable The styleable to match
 */
+ (NSString *)matchingDeclarationsForStyleable:(id<PXStyleable>)styleable;

/**
 *  Allocate and initialize a new stylesheet using the specified source and stylesheet origin
 *
 *  @param source The CSS source for this stylesheet
 *  @param origin The specificity origin for this stylesheet
 */
+ (id)styleSheetFromSource:(NSString *)source withOrigin:(PXStylesheetOrigin)origin;

/**
 *  Allocate and initialize a new styleheet for the specified path and stylesheet origin
 *
 *  @param filePath The string path to the stylesheet file
 *  @param origin The specificity origin for this stylesheet
 */
+ (id)styleSheetFromFilePath:(NSString *)filePath withOrigin:(PXStylesheetOrigin)origin;

/**
 *  A class-level getter returning the current application-level stylesheet. This value may be nil
 */
+ (PXStylesheet *)currentApplicationStylesheet;

/**
 *  A class-level getter returning the current user-level stylesheet. This value may be nil
 */
+ (PXStylesheet *)currentUserStylesheet;

/**
 *  A class-level getter returning the current view-level stylesheet. This value may be nil
 */
+ (PXStylesheet *)currentViewStylesheet;

/**
 *  Calls updateStylesForAllViews. Please call updateStylesForAllViews directly.
 */
+ (void)applyStylesheets __deprecated_msg("Use updateStylesForAllViews");

/**
 * Update styles for all windows and all if their subviews.
 */
+ (void)updateStylesForAllViews;

/**
 *  Update styles for this styleable and all of its descendant styleables
 *
 *  @param styleable The styleable to update
 */
+ (void)updateStyles:(id<PXStyleable>)styleable;

/**
 *  Update styles for this styleable only
 *
 *  @param styleable The styleable to update
 */
+ (void)updateStylesNonRecursively:(id<PXStyleable>)styleable;

/**
 *  Update styles for this styleable and all of its descendant styleables asynchronously
 *
 *  @param styleable The styleable to update
 */
+ (void)updateStylesAsync:(id<PXStyleable>)styleable;

/**
 *  Update styles for this styleable only asynchronously
 *
 *  @param styleable The styleable to update
 */
+ (void)updateStylesNonRecursivelyAsync:(id<PXStyleable>)styleable;

/**
 *  Remove all content from Pixate's image cache, if one is being used
 */
+ (void)clearImageCache;

/**
 *  Remove all content from Pixate's style cache, if one is being used
 */
+ (void)clearStyleCache;

@end
