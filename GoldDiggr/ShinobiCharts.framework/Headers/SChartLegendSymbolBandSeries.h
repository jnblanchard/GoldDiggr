//
//  SChartLegendSymbolBandSeries.h
//  SChart
//
//  Copyright (c) 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartLegendSymbol.h"

@class SChartBandSeries, SChartBandSeriesStyle;

/** A symbol designed to represent a band series in the chart legend.
 
 The symbol makes use of the series styling, in order to better represent it in the legend.
 
 @available Premium
 */
@interface SChartLegendSymbolBandSeries : SChartLegendSymbol

/** @name Initialization */

/** Initializes and returns a newly allocated symbol to represent this band series.
 @param series The chart series which this symbol will represent in the chart legend.
 @return An initialized symbol, or `nil` if it couldn't be created. */
- (id)initWithSeries:(SChartBandSeries *)series;

/** @name Styling */

/** The style object for the series associated with this legend symbol.
 
 This property allows you to query the style properties which have been used to create this legend symbol. */
@property (nonatomic, readonly) SChartBandSeriesStyle *style;



@end
