//
//  SChartCartesianSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartMappedSeries.h"
#import "SChartAnimation.h"

@class SChartAxis;

/** `SChartCartesianSeries` represents an instance of a cartesian series on a chart.
 
 Cartesian coordinates are points defined in a plane by a pair of numerical coordinates, which are the signed distances from the point to either axis in the plane.  In our charts, we are using an x and a y axis.
 
 `SChartCartesianSeries` is the base class for all of the concrete cartesian series which are provided in ShinobiCharts.  The concrete series types which are available are:
 
 - `SChartBarSeries` - represents a bar series.
 - `SChartColumnSeries` - represents a column series.
 - `SChartLineSeries` - represents a line series.
 - `SChartStepLineSeries` - represents a stepped line series.
 - `SChartBandSeries` - represents a band series.  These are only available in the premium version of charts.
 - `SChartScatterSeries` - represents a scatter plots.
 - `SChartCandlestickSeries` - represents a candlestick series.  These are only available in the premium version of charts.
 - `SChartOHLCSeries` - represents an Open-High-Low-Closed (OHLC) series.  These are only available in the premium version of charts.
 
 Some types of chart series can be stacked.  This means that they are rendered on top of each other, with the first series rendered at the bottom, and subsequent series offset so that they begin at the top of the previous series.  The types of series which can be stacked are bar series, column series, line series and stepped line series.  See the `stackIndex` property for more information.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 
 */
@interface SChartCartesianSeries : SChartMappedSeries

/** Baseline for the series, on the x or y axis depending on its orientation.
 
 By default, this property is `0.0` */
@property (nonatomic, retain) NSNumber *baseline;

/** The index of the stacked set to which this series belongs.
 
 Series can be stacked on a chart, which means that their values are offset and they are rendered on top of each other, with the first series rendered at the bottom, offset from the baseline, with subsequent series offset so that they begin at the top of the previous series.  Each stacked set in the chart is assigned a unique ID.  To add a series to a stacked set, you set its `stackIndex` property to be the ID of the stacked set to which you wish to add the series.
 
 By default, this property is `nil`. This indicates that the series is not stacked.
 
 The types of series which can be stacked are bar series, column series, line series and stepped line series.
 
 Note that for any stack, all offsets must either be positive or negative - for example:
 Two column series are stacked. Both series have yValues for xValues of 3 and 4. The first series has a yValue of 2 for x=3 and -1 for x=4. The second series has yValues of 7 for x=3 and -3 for x==4. This is OK, whereas if the second series had a yValue of 2 for x=4, that stack would contain both positive and negative offsets and could produce strange effects.
 
 Note also that if your series are stacked, their values must be sorted - with respect to the xAxis in the case of a column series or line series of horizontal orientation, and with respect to the yAxis in the case of a bar series or line series of vertical orientation.
 
 */
@property (nonatomic, retain) NSNumber *stackIndex;

/** Returns the range of the data in the X axis. 
 
 @see SChartRange
 
 @warning *DEPRECATED* - This method has been moved onto `SChartMappedSeries`.
 
 */
-(SChartRange *)rangeOfDataInX;

/** Returns the range of the data in the Y axis.
 
 @see SChartRange
 
 @warning *DEPRECATED* - This method has been moved onto `SChartMappedSeries`.
 
 */
-(SChartRange *)rangeOfDataInY;

/** Returns the datapoint with the largest Y value. */
-(SChartDataPoint *)dataPointWithMaxY;

/** Returns the datapoint with the smallest Y value. */
-(SChartDataPoint *)dataPointWithMinY;

/** Returns the datapoint with the largest X value. */
-(SChartDataPoint *)dataPointWithMaxX;

/** Returns the datapoint with the smallest X value. */
-(SChartDataPoint *)dataPointWithMinX;

#pragma mark -
#pragma mark Animation
/** @name Animation */

/** DEPRECATED - Use `[SChartSeries animationEnabled]` instead. */
@property (nonatomic) BOOL animated DEPRECATED_ATTRIBUTE;

/** DEPRECATED - Configure either the `[SChartSeries entryAnimation]` or `[SChartSeries exitAnimation]` instead. */
@property (nonatomic) float animationDuration   DEPRECATED_ATTRIBUTE;

/** DEPRECATED - Configure either the `[SChartSeries entryAnimation]` or `[SChartSeries exitAnimation]` instead. */
@property (nonatomic)       SChartAnimationCurve   animationCurve   DEPRECATED_ATTRIBUTE;

@end
