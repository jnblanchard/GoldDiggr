//
//  SChartRadialChartSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SChartSeries.h"

/**
 __Note: The `SChartRadialSeries` class will be removed in a future release. It has only been left in this release in order to maintain backwards compatibility. Please use `SChartDonutSeries` instead.__
 
 `SChartRadialSeries` is the base class for all pie or donut series within a `ShinobiChart`. Typically you would use one of its subclasses in your chart. Currently the following subclasses are available:
 
 - `SChartDonutSeries` - represents donut series.
 - `SChartPieSeries` - represents pie series.
 
 Whereas datapoints for cartesian series require an x and a y value, pie and donut series require a name and a value.
 The x value of a datapoint within a pie/donut series is set as the name of the slice, and the y value is set as its magnitude. See `SChartRadialDataPoint` for more information.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 @sample PieChart
 */

@interface SChartRadialSeries : SChartSeries
/* this will be deprecated in future - left for now as SChartDonutSeries
 * inherits from this, and due to use in delegates */

/** @name Label Format */

/** A format string to use for the labels which annotate data within a pie/donut series.
 
 A typical example of the labels would be the labels on each slice in a pie chart.
 
 By default, this property is set to @"%.2f" which shows the value to two decimal places.
 
 @warning *DEPRECATED* - This property has been moved onto `SChartDonutSeries`. */
@property (nonatomic, retain) NSString               *labelFormatString DEPRECATED_ATTRIBUTE;

@end
