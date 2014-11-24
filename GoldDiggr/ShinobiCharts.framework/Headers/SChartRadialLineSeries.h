//
//  SChartRadialLineSeries.h
//  ShinobiCharts
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartMappedSeries.h"

@class SChartRadialLineSeriesStyle;
@class SChartBasePointStyle;

/** `SChartRadialLineSeries` is a type of `SChartMappedSeries` that uses datapoints to construct a line series on a radial chart. The line series consists of a number of points which may or may not be selected, and which are connected by a line with an optional fill between the line and the chart's center.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartRadialLineSeries : SChartMappedSeries

#pragma mark - Styling
/** @name Styling */

/** Manages the appearance of the radial line series on the chart.
 
 The default settings of the style are inherited from the chart theme. You can tweak the appearance of the series by modifying the style.
 
 @see SChartRadialLineSeriesStyle
 */
-(SChartRadialLineSeriesStyle *)style;

/** Sets the style object for the radial line series.
 
 @param style The new style object to use for the line series.
 @see style
 */
-(void)setStyle:(SChartRadialLineSeriesStyle *)style;

/** Manages the appearance of the line series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme. You can tweak the appearance of the series by modifying the style.
 
 @see SChartRadialLineSeriesStyle
 */
-(SChartRadialLineSeriesStyle *)selectedStyle;

/** Sets the style object for the radial line series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartRadialLineSeriesStyle *)selectedStyle;

/**
 Determines whether the line series will draw a line from the last point back
 to the first point.

 By default, this is set to `NO`.
 */
@property(nonatomic, assign) BOOL pointsWrapAround;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each datapoint in this series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartXValue` & `sChartYValue` properties to access each datapoint's X & Y values. Here is an example of how to use these properties to style each point:
 
     - (SChartBasePointStyle*)styleForPoint:(id<SChartData>)point {
 
         SChartBasePointStyle *newStyle = [super styleForPoint:point];
         
         float yValue = [[point sChartYValue] floatValue];
         
         if (yValue > 90) {
             newStyle.color = [UIColor redColor];
         } else if(yValue > 50) {
             newStyle.color = [UIColor yellowColor];
         } else {
             newStyle.color = [UIColor greenColor];
         }
         return newStyle;
     }
 
 
 @param point The data-point that will be styled by the returned style object.
 
 */
- (SChartBasePointStyle*)styleForPoint:(id<SChartData>)point;

@end
