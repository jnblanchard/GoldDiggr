//
//  SChartLegendSymbol.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/** The legend symbols are the visual representations of a series in the chart legend.  `SChartLegendSymbol` is the base class for these symbols. 
 
 As a part of adopting the `SChartLegendItem` protocol, a series may optionally return a symbol object to represent itself.  If you are using one of the series types provided by ShinobiCharts, you shouldn't need to create legend symbols yourself.  All of the series types return an appropriate symbol which will represent them in the chart legend.  These predefined symbols are:
 
 - `SChartLegendSymbolLineSeries` - represents a line series.
 - `SChartLegendSymbolColumnSeries` - represents a column series.
 - `SChartLegendSymbolBarSeries` - represents a bar series.
 - `SChartLegendSymbolScatterSeries` - represents a scatter series.
 - `SChartLegendSymbolPieSeries` - represents a pie series.
 - `SChartLegendSymbolDonutSeries` - represents a donut series.
 - `SChartLegendSymbolBandSeries` - represents a band series.
 - `SChartLegendSymbolCandlestickSeries` - represents a candlestick series.
 - `SChartLegendSymbolOHLCSeries` - represents a OHLC series.
 
 @available Standard
 @available Premium
 */
@interface SChartLegendSymbol : UIView

@end
