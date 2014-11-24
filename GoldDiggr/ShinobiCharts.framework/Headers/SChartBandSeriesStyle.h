//
//  SChartBandSeriesStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartLineSeriesStyle.h"

@class SChartPointStyle;

/** `SChartBandSeriesStyle` manages the appearance of an instance of `SChartBandSeries` on a chart.
 
 The band series is visualised as two line series, one for the High values and one for the Low, with an area fill between the lines.
 
 `SChartBandSeriesStyle` allows you to configure the appearance of various aspects of the series, such as:
 
 - The width and color of the lines series.
 - Whether the area between the lines series is filled, and the color of the fill if it is.
 - The appearance of points in the series, both when they are selected and when they are not.
 
 @available Premium
 @sample FinancialChart
 */
@interface SChartBandSeriesStyle : SChartSeriesStyle 

/** @name Styling properties */

/** Defines whether the area between the high and low lines is filled. */
@property (nonatomic)             BOOL      showFill;

/* DEPRECATED - This will be removed from the API in a future commit.  This property should be private. */
@property (nonatomic)             BOOL      showFillSet;

/** The color of the high line. */
@property (nonatomic, retain)     UIColor   *lineColorHigh;

/** The color of the low line. */
@property (nonatomic, retain)     UIColor   *lineColorLow;

/** The width of each of the lines, in points. */
@property (nonatomic, retain)     NSNumber  *lineWidth;

/** The color of the fill between the lines when the high line is above the low line. */
@property (nonatomic, retain)     UIColor   *areaColorNormal;

/** The color of the fill between the lines when the low line is above the high line. */
@property (nonatomic, retain)     UIColor   *areaColorInverted;

/** Manages the appearance of data points within the series.
 @see SChartPointStyle
 */
@property (nonatomic, retain)     SChartPointStyle *pointStyle;

/** Manages the appearance of data points within the series which are selected.
 @see SChartPointStyle
 */
@property (nonatomic, retain)     SChartPointStyle *selectedPointStyle;

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartBandSeriesStyle *)style;

@end
