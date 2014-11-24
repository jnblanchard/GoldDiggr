//
//  SChartLegendItem.h
//  SChart
//
//  Copyright (c) 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SChartLegendSymbol;

/** Specifies the interface required by the legend to display chart series. A series should adopt this protocol if it wishes to specify how it is represented in the legend. 
 
 The `SChartSeries` base class adopts this protocol and therefore any subclasses can specify their representation in the legend by overriding the methods here.  All the series types provided by ShinobiCharts already provide their own implementation of these methods, so you should only need to implement them yourself if you are looking for custom behavior.
 
 @available Standard
 @available Premium
 */
@protocol SChartLegendItem <NSObject>
@optional

/** @name Series Titles */

/** Returns the text displayed in the legend for the series. 
 
 This is relevant for cartesian series, but is not used for radial series.  For radial series, use `titleForSliceInLegend`. */
- (NSString*)titleForSeriesInLegend;


/** Returns the text displayed in the legend for the slice at the given index in the first series on the chart.
 
 This is only relevant for radial series.  This method will be called for each of the slices in the first series in the chart.  If this is implemented, `symbolForSeriesInLegend` will not be called.  Instead of displaying a symbol for each series, we will display more detailed information about the first series in the chart. 
 @param index The index of the relevant slice in the first chart series.
 */
- (NSString*)titleForSliceInLegend:(NSInteger)index;

/** Returns the text color used for series titles in the legend.
 
 By default, the text color is taken from the chart theme.  If you implement this method yourself, the value it returns takes precedence. */
- (UIColor*)textColorForSeriesTitleInLegend;

/** @name Series Symbols */

/** Returns the symbol representing a cartesian series in the legend.
 
 All of the series types provided by ShinobiCharts return an appropriate symbol to represent them in the legend.  If you would like to use a custom symbol, you can subclass one of the series types, and override this method.
 
 For radial series, you should use `symbolForSliceInLegend:` instead.
 
 @see SChartLegendSymbol
 */
- (SChartLegendSymbol*)symbolForSeriesInLegend;


/** Returns the symbol representing a slice in the first radial series on the chart.
 
 All of the series types provided by ShinobiCharts return an appropriate symbol type to be used in the legend.  If you would like to use a custom symbol, you can subclass one of the series types, and override this method.
 
 For cartesian series, you should use `symbolForSeriesInLegend` instead.
 
 @see SChartLegendSymbol 
 */
- (SChartLegendSymbol *)symbolForSliceInLegend:(NSInteger)index;


/** Returns a solid block of color representing a cartesian series in the legend.
 @see SChartLegendSymbol
 */
- (SChartLegendSymbol *)blockSymbolForSeriesInLegend;

@end
