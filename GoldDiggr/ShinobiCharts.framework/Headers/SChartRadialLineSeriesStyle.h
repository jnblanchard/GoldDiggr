//
//  SChartRadialLineSeriesStyle.h
//  ShinobiCharts
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartLineSeriesBaseStyle.h"
@class SChartBasePointStyle;

/** `SChartRadialLineSeriesStyle` manages the appearance of an instance of `SChartRadialLineSeries` on a chart.
 
 @available Standard
 @available Premium
*/
@interface SChartRadialLineSeriesStyle : SChartLineSeriesBaseStyle

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartRadialLineSeriesStyle *)style;

#pragma mark Point styling
/** @name Point styling */

/** Manages the appearance of points that are not selected.
 @see SChartBasePointStyle */
@property(nonatomic, retain) SChartBasePointStyle *pointStyle;

/** Manages the appearance of points that are selected.
 @see SChartBasePointStyle */
@property(nonatomic, retain) SChartBasePointStyle *selectedPointStyle;


@end
