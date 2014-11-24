//
//  SChartLegendSymbolDonutSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartLegendSymbol.h"

@class SChartDonutSeries, SChartDonutSeriesStyle;

/** A symbol designed to represent a donut series in the chart legend.
 
 The symbol makes use of the series styling, in order to better represent it in the legend.
 
 @available Standard
 @available Premium
 */
@interface SChartLegendSymbolDonutSeries : SChartLegendSymbol 

/** @name Styling */

/** The style object for the series associated with this legend symbol.
 
 This property allows you to query the style properties which have been used to create this legend symbol. */
@property (nonatomic, retain) SChartDonutSeriesStyle *style;

/** @name Initialization */

/** Initializes and returns a newly allocated symbol to represent the specified slice in the specified donut series.
 @param donutSeries The chart series which this symbol will be associated with.
 @param index The slice in the series which the symbol will represent.
 @return An initialized symbol, or `nil` if it couldn't be created. */
- (id)initWithSeries:(SChartDonutSeries *)donutSeries andSliceIndex:(NSInteger)index;

@end
