//
//  SChartPieSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartDonutSeries.h"

@class SChartPieSeriesStyle;

/** `SChartPieSeries` displays magnitude data on the chart - the larger the value of the datapoint, the larger the slice representing that datapoint.
 
 <img src="../Images/userguide_pieSeries.png" width=300/>
 
 `SChartPieSeries` inherits most of its behavior from its parent `SChartDonutSeries`.  Have a look at the `SChartDonutSeries` API documentation for more information on the common behavior.
 
 One way in which pie series differ from donut series is with regard to styling.  A pie series contains an instance of `SChartPieSeriesStyle`, which manages its appearance.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 @sample PieChart
 */
@interface SChartPieSeries : SChartDonutSeries

#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the pie series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartPieSeriesStyle
 */
-(SChartPieSeriesStyle *)style;

/** Sets the style object for the pie series.
 
 @param style The new style object to use for the pie series.
 @see style
 */
-(void)setStyle:(SChartPieSeriesStyle *)style;

/** Manages the appearance of the pie series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a slice is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartPieSeriesStyle
 */
-(SChartPieSeriesStyle *)selectedStyle;

/** Sets the style object for the scatter series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartPieSeriesStyle *)selectedStyle;

/** @name Information about the pie series */

/** Identical to `[SChartDonutSeries getDonutCenter]`. This returns the center point of the pie, within the chart frame. */
- (CGPoint) getPieCenter;


@end
