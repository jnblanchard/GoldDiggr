//
//  SChartData.h
//  SChart
//
//  Copyright (c) 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/** The `SChartData` protocol allows any object to act as a datapoint within a series on a `ShinobiChart`. The `[SChartDatasource sChart:dataPointAtIndex:forSeriesAtIndex:]` method returns an object that implements this protocol. It can be your own object or an instance of the `SChartDataPoint` class that we supply.
 
 The protocol has two required methods, which return the x and y values for the object.  Radial data points return the name of the data point as the x value, and the value of the data point as the y value.
 
 It also has a set of optional methods and properties, which allow you to:
 
 - Handle selection. 
 - Return x or y values for a given key.  This is used for multi-value data points.  Examples of these are `SChartMultiXDataPoint` and `SChartMultiYDataPoint`.
 - Return the index of the data point within the instance of `SChartSeries` which contains it.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@protocol SChartData <NSObject>
#pragma mark -
#pragma mark REQUIRED
@required

/** @name Single value points */

/** Returns the x value of the data point. 
 
 This is used for series that require only a single x value. Series that require multiple x values should implement `sChartXValueForKey:` and check the specific series class for the required keys. */
- (id)sChartXValue;

/** Returns the y value of the data point.
 
 This is used for series that require only a single y value. Series that require multiple y values should implement `sChartYValueForKey:` and check the specific series class for the required keys. */
- (id)sChartYValue;

#pragma mark -
#pragma mark OPTIONAL
@optional
/** @name Axis independent values*/

/** This is used for series that require data values which are independent of the axes. The expected keys can be found on the series that is trying to render the data point.
 
 An example of this is SChartBubbleDataPoint which has a third data value relating to the size of the bubbles.*/
- (id)sChartValueForKey:(NSString*)key;

/** @name Multi value points */

/** Returns the x value corresponding to the provided key.
 
This is only required for series with more than one x value and keys are specified on the series type.  For example, OHLC keys include "low", "high", etc.  For series with just a single x value, use `sChartXValue` instead. */
- (id)sChartXValueForKey:(NSString*)key;

/** Returns the y value corresponding to the provided key. 
 
 This is only required for series with more than one y value and keys are specified on the series type.  For example, OHLC keys include "low", "high", etc. For series with just a single y value, use `sChartYValue` instead. */
- (id)sChartYValueForKey:(NSString*)key;

/** @name Selection */

/** Returns `YES` if this data point is selected. */
- (BOOL)sChartPointIsSelected;

/** @name Index */

/** Returns the index of this data point in the chart series which contains it. 
 @see SChartSeries
 @see SChartDataSeries */
@property (nonatomic) NSInteger sChartDataPointIndex;

@end
