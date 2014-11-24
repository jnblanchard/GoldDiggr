//
//  SChartBandSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartCartesianSeries.h"
#import "SChartBandSeriesStyle.h"

/** `SChartBandSeries` is a type of `SChartSeries` that uses its data points to construct a band series.
 
  <img src="../Images/userguide_bandSeries.png" width=400/>
 
 Data points in a band series will contain multiple values.  This means that they will be instances of `SChartMultiXDataPoint` or `SChartMultiYDataPoint`, depending on the orientation of the series.  The keys for the values in each data point will be `SChartBandSeriesHigh` and `SChartBandSeriesLow`.
 
 The band series is visualised as two line series, one for the High values and one for the Low, with an area fill between the lines.
 The colour of this fill depends on the relationship between the lines, for example it may be green if the High value is greater than the Low value, and red if the opposite is true.
 
 In order to provide the High and Low values to the chart, the data points in the band series should implement either the `[SChartData sChartXValueForKey:]` method or the `[SChartData sChartYValueForKey:]` method on the `SChartData` protocol, depending on the series orientation.
 
 The band series contains an instance of `SChartBandSeriesStyle`, which manages the appearance of the series.
 
 @available Premium
 @sa ChartsUserGuide
 @sample FinancialChart
 */
@interface SChartBandSeries : SChartCartesianSeries

/** Defines the orientation of the band series.
 
 The available options are:
 
 - SChartSeriesOrientationHorizontal: Each data point for the series will have multiple y-values.
 - SChartSeriesOrientationVertical: Each data point for the series will have multiple x-values.
 
 If the series is horizontal, each data point will have multiple y values.  If the series is vertical, each data point will have multiple x values.
 */
@property (nonatomic, readonly) SChartSeriesOrientation orientation;

#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the band series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartBandSeriesStyle
 */
-(SChartBandSeriesStyle *)style;

/** Sets the style object for the band series.
 
 @param style The new style object to use for the band series.
 @see style
 */
-(void)setStyle:(SChartBandSeriesStyle *)style;

/** Manages the appearance of the band series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartBandSeriesStyle
 */
-(SChartBandSeriesStyle *)selectedStyle;

/** Sets the style object for the band series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartBandSeriesStyle *)selectedStyle;

@end
