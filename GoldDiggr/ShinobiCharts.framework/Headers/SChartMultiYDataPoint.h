//
//  SChartMultiYDataPoint.h
//  ShinobiControls_Source
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartDataPoint.h"

@protocol SChartData;

/** Represents cartesian data points which have multiple y values.  Examples of series which could have multiple y values for each data point are:
 
 - Band series.  See `SChartBandSeries`.
 - Candlestick series.  See `SChartCandlestickSeries`.
 - OHLC series.  See `SChartOHLCSeries`.
 
 @available Standard
 @available Premium
 @sample FinancialChart
 */
@interface SChartMultiYDataPoint : SChartDataPoint <SChartData>

#pragma mark -
#pragma mark Data

/** @name Data */

/** A dictionary of values for this data point.
 
 In order to query the values at a point, you can use the `[SChartDataSeries yValueKeys]` property.  Using the set of keys returned by this property, you are able to iterate through a set of `SChartMultiYDataPoint` objects, and get the value corresponding to the relevant key.
 */
@property (nonatomic, retain) NSMutableDictionary *yValues;


@end
