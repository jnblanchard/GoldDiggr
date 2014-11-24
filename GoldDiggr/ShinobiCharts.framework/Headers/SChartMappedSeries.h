//
//  SChartMappedSeries.h
//  ShinobiCharts
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import <Foundation/Foundation.h>

#import "SChartSeries.h"

@class SChartAxis;

/** `SChartMappedSeries` represents an instance of a series that maps its data to axes on a chart.
 
 Coordinates are points defined in a plane by a pair of numerical coordinates, which are the signed distances from the point to either axis in the plane. Mapped series require a chart with at least one X and at least one Y axis.
 
 `SChartMappedSeries` is the base class for all of the mapped series which are provided in ShinobiCharts. The mapped series types which are available are:
 
 - `SChartBarSeries` - represents a bar series.
 - `SChartColumnSeries` - represents a column series.
 - `SChartLineSeries` - represents a line series.
 - `SChartStepLineSeries` - represents a stepped line series.
 - `SChartBandSeries` - represents a band series.  These are only available in the premium version of charts.
 - `SChartScatterSeries` - represents a scatter plots.
 - `SChartCandlestickSeries` - represents a candlestick series.  These are only available in the premium version of charts.
 - `SChartOHLCSeries` - represents an Open-High-Low-Closed (OHLC) series.  These are only available in the premium version of charts.
 - `SChartRadialLineSeries` - represents a Radar or Polar series depending on the which axes you've given your chart.
 
 Some types of chart series can be stacked.  This means that they are rendered on top of each other, with the first series rendered at the bottom, and subsequent series offset so that they begin at the top of the previous series.  The types of series which can be stacked are bar series, column series, line series and stepped line series.  See the `stackIndex` property for more information.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 
 */
@interface SChartMappedSeries : SChartSeries

/** Returns the range of the data in the X axis.
 
 @see SChartRange
 */
-(SChartRange *)rangeOfDataInX;

/** Returns the range of the data in the Y axis.
 
 @see SChartRange
 */
-(SChartRange *)rangeOfDataInY;

@end

