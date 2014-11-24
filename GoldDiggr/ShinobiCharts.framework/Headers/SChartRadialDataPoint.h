//
//  SChartRadialDataPoint.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SChartData.h"
#import "SChartDataPoint.h"

/** A `ShinobiChart` can contain either cartesian, radial or pie/donut chart series. Pie and donut chart series contain instances of `SChartRadialDataPoint`. You should look at the documentation for `SChartMappedSeries` for the data points which are used by other types of series.
 
 __Note: The name of this class will be changed in a future version of this framework. The current naming isn't clear, as these types of data points are not used by radial series - they use instances of `SChartDataPoint` instead. We have kept the current naming for now to maintain backwards compatibility.__
 
 A radial data point is made up of a name and a value (magnitude). Unlike data points in cartesian series, a `SChartRadialDataPoint` can have only one value.
 
 @available Standard
 @available Premium
 @sample PieChart
 */
@interface SChartRadialDataPoint : SChartDataPoint <SChartData>

#pragma mark -
#pragma mark Data
/** @name Data */

/** The name of this data point. */
@property (nonatomic, retain) NSString *name;

/** The value (magnitude) of this data point.
 
 All radial data points have a single value. */
@property (nonatomic, retain) NSNumber *value;

@end
