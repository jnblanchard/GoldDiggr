//
//  SChartLineSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartScatterSeries.h"

/** 
 SChartLineSeries is a type of `SChartSeries` that uses the data points to construct a line series.
 
 
   <img src="../Images/userguide_lineSeries.png" width=400/>
 
 
 The line series consists of a number of points which may or may not be marked, and which are connected by a line with an optional fill (ie: area series) between the line and the chart axis.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartLineSeries : SChartScatterSeries

#pragma mark -
#pragma mark Styling
/** @name Styling */

/** Manages the appearance of the line series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartLineSeriesStyle
 */
-(SChartLineSeriesStyle *)style;

/** Sets the style object for the line series. 
 
 @param style The new style object to use for the line series.
 @see style
 */
-(void)setStyle:(SChartLineSeriesStyle *)style;

/** Manages the appearance of the line series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartLineSeriesStyle
 */
-(SChartLineSeriesStyle *)selectedStyle;

/** Sets the style object for the line series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartLineSeriesStyle *)selectedStyle;

@end
