//
//  SChartSeriesStyle.h
//  ShinobiControls_Source
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SChartDataPointLabelStyle;

/** SChartSeriesStyle is the base class for all series styles in ShinobiCharts.  Series style objects manage the appearance of series on a chart.  
 
 SChartSeriesStyle allows you to modify the representation of the series in the chart legend.  In order to tweak properties on a series style object which are specific to that kind of series, you should look at the documentation for the concrete series styles which are available.  These are:
 
 - `SChartBarSeriesStyle` - manages the appearance of bar series.
 - `SChartColumnSeriesStyle` - manages the appearance of column series.
 - `SChartCandlestickSeriesStyle` - manages the appearance of candlestick series.
 - `SChartDonutSeriesStyle` - manages the appearance of donut series.
 - `SChartLineSeriesStyle` - manages the appearance of line series.
 - `SChartBandSeriesStyle` - manages the appearance of band series.
 - `SChartOHLCSeriesStyle` - manages the appearance of Open-High-Low-Closed (OHLC) series.
 - `SChartPieSeriesStyle` - manages the appearance of pie series.
 - `SChartScatterSeriesStyle` - manages the appearance of scatter series.
 
 @available Standard
 @available Premium
 */
@interface SChartSeriesStyle : NSObject

/** Defines whether the chart legend will display a symbolic representation of the series.
 
 If this is set to `YES`, the legend will display symbols.  If this is set to `NO`, the series will be represented by a solid block of color. */
@property (nonatomic)           BOOL        useSeriesSymbols;

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartSeriesStyle *)style;

/** The style to apply to the labels which are displayed for data points.
 
 @see SChartDataPointLabel
 */
@property (nonatomic, retain) SChartDataPointLabelStyle *dataPointLabelStyle;

@end
