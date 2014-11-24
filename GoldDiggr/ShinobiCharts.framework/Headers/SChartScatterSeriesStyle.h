//
//  SChartScatterSeriesStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartPointSeriesStyle.h"

@class SChartPointStyle;

/** SChartScatterSeriesStyle manages the appearance of an instance of `SChartScatterSeries` on a chart.
 
 @available Standard
 @available Premium
 */
@interface SChartScatterSeriesStyle : SChartPointSeriesStyle

#pragma mark -
#pragma mark Styling properties
/** @name Styling */

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartScatterSeriesStyle *)style;

#pragma mark Point styling
/** @name Point styling */

/** Manages the appearance of points that are not selected.
 @see SChartPointStyle */
- (SChartPointStyle *) pointStyle;
- (void) setPointStyle:(SChartPointStyle *)pointStyle;

/** Manages the appearance of points that are selected.
 @see SChartPointStyle */
- (SChartPointStyle *) selectedPointStyle;
- (void) setSelectedPointStyle:(SChartPointStyle *)selectedPointStyle;


@end
