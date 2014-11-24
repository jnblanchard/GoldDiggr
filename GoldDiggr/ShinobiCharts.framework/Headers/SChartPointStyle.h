//
//  SChartPointStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartBaselinePointStyle.h"

/** `SChartPointStyle` manages the appearance of data points within chart series.  It is used by instances of `SChartBandSeries`, `SChartLineSeries` and `SChartScatterSeries`, as all of these types of series can display individual points.
 
 By default, points are displayed as two circles, one displayed within the other.  You can configure the color and radius of both circles.  You can also add a gradient to a point, so that it fades as you move out from its center.
 
 You also have the option to display images for each point, rather than displaying two circles.  This is managed using the `texture` property.
 
 @available Standard
 @available Premium
 */
@interface SChartPointStyle : SChartBaselinePointStyle

#pragma mark -
#pragma mark Styling Properties
/** @name Styling Properties */
/** The color of the inner sections of data points. */
@property (nonatomic, retain)     UIColor   *innerColor;

/** The color of the inner sections of data points when the chart series goes below its baseline. */
@property (nonatomic, retain)     UIColor   *innerColorBelowBaseline;

/** The radius of the inner section of a data point. */
@property (nonatomic, retain)     NSNumber  *innerRadius;

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartPointStyle *)style;

@end
