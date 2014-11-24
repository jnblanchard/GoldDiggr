//
//  SChartDataSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SChartRange, SChartDataPoint;

/** Each `SChartSeries` requires a set of data points that it will visually represent. The `SChartDataSeries` looks after these points.  The set of data points it contains will adopt the `SChartData` protocol.
 
 `SChartDataSeries` is not concerned with style or aesthetics. All the properties defined here are related to the data only.
 
 @available Standard
 @available Premium
 */
@interface SChartDataSeries : NSObject

/** @name Data for the series */

/** Returns the data points contained within this series.
 
 Data is provided to the chart from its `SChartDatasource`.  The chart uses this data to build up its series, and to populate the `SChartDataSeries` for each one.  When it is populated, each data series makes internal copies of the data objects which are provided to it from the chart datasource.  The objects stored in this array conform to the `SChartData` protocol which means you can gain access to each datapoint's data via the `SChartData` protocol's methods. The following code shows how you would get the X & Y values of the first datapoint in a series:
 
    id<SChartData> dataPoint = [series.dataSeries.dataPoints firstObject];
    id xValue = [dataPoint sChartXValue];
    id yValue = [dataPoint sChartYValue];
 
 Modifying the value of any of the data points in this array will have no effect on the display of the series in the chart.  In order to refresh the chart to display new data, you should update the chart datasource, then call:
 
    [chart reloadData];
    [chart redrawChart];
 
 This will force the chart to refresh its data, going back to the datasource to get it.
 */
@property (nonatomic, retain) NSMutableArray    *dataPoints;

/** Returns the array of keys (NSString objects) for the x values in this series.

 If each data point in the series contains multiple x values, the data series will contain a set of keys to allow us to get the correct x value back. */
@property (nonatomic, retain) NSArray    *xValueKeys;

/** Returns the array of keys (NSString objects) for the y values in this series.
 
 If each data point in the series contains multiple y values, the data series will contain a set of keys to allow us to get the correct y value back. */
@property (nonatomic, retain) NSArray    *yValueKeys;

/** An array of keys (NSString objects) for this series.
 
 If the series requires values independent of the axes, then it should return the keys for those values here. The data source will then attempt to load these keys for this series.*/
@property (nonatomic, retain) NSArray    *valueKeys;

/** The range of the data values in X. 
 @see SChartRange */
@property (nonatomic, retain) SChartRange       *rangeX;

/** The range of the data values in Y. 
 @see SChartRange */
@property (nonatomic, retain) SChartRange       *rangeY;

/* Returns an array containing all of the x values in this data series. 
 
 The values in the array are ordered according to the order of the data points in the series.  If a data point contains multiple x values, they are all added to this array.
 */
-(NSArray*)allXValues;

/* Returns an array containing all of the y values in this data series.
 
 The values in the array are ordered according to the order of the data points in the series.  If a data point contains multiple y values, they are all added to this array.
 */
-(NSArray*)allYValues;

@end
