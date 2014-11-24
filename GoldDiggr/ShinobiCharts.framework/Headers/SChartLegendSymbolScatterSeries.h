//
//  SChartLegendSymbolScatterSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartLegendSymbolPointSeries.h"
#import "SChartScatterSeriesStyle.h" //require this import for style's covariant property

@class SChartScatterSeries, SChartScatterSeriesStyle;

/** A symbol designed to represent a scatter series in the chart legend.
 
 The symbol makes use of the series styling, in order to better represent it in the legend.
 
 @available Standard
 @available Premium
 */
@interface SChartLegendSymbolScatterSeries : SChartLegendSymbolPointSeries

/** @name Initialization */

/** Initializes and returns a newly allocated symbol to represent this scatter series.
 @param series The chart series which this symbol will represent in the chart legend.
 @return An initialized symbol, or `nil` if it couldn't be created. */
- (id)initWithSeries:(SChartScatterSeries *)series;

/** @name Styling */

/** The style object for the series associated with this legend symbol.
 
 This property allows you to query the style properties which have been used to create this legend symbol. */
@property (nonatomic, readonly) SChartScatterSeriesStyle *style;

@end
