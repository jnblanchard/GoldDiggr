//
//  SChartCandlestickSeries.h
//  SChart
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartOHLCSeries.h"
#import "SChartCandlestickSeriesStyle.h"

/** `SChartCandlestickSeries` is a type of `SChartSeries` which displays Open-High-Low-Close data on a chart.
 
  <img src="../Images/userguide_candlestickSeries.png" width=400/>
 
 Each data point in a candlestick series is visualised as a thick candle between the open and close values, with 'wicks' indicating the high and low positions.
 
 Data points in a candlestick series will contain multiple values.  This means that they will be instances of `SChartMultiXDataPoint` or `SChartMultiYDataPoint`, depending on the orientation of the series.  The keys for the values in each data point will be `SChartCandlestickKeyOpen`, `SChartCandlestickKeyHigh`, `SChartCandlestickKeyLow` and `SChartCandlestickKeyClose`.
 
 In order to provide the Open, High, Low, and Close values to the chart, the data points in the candlestick series should implement either the `[SChartData sChartXValueForKey:]` method or the `[SChartData sChartYValueForKey:]` method on the `SChartData` protocol, depending on the series orientation.
 
 The series contains an instance of `SChartCandlestickSeriesStyle`, which manages the appearance of the series on the chart.
 
 @available Premium
 @sa ChartsUserGuide
 @sample FinancialChart
 */
@interface SChartCandlestickSeries : SChartOHLCSeries

#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the candlestick series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartCandlestickSeriesStyle
 */
-(SChartCandlestickSeriesStyle *)style;

/** Sets the style object for the candlestick series.
 
 @param style The new style object to use for the candlestick series.
 @see style
 */
-(void)setStyle:(SChartCandlestickSeriesStyle *)style;

/** Manages the appearance of the candlestick series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartCandlestickSeriesStyle
 */
-(SChartCandlestickSeriesStyle *)selectedStyle;

/** Sets the style object for the candlestick series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartCandlestickSeriesStyle *)selectedStyle;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each candlestick datapoint in the series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartYValueForKey:` method to access each datapoint's Y-values unless you have setup a horizontal candle series. This method is also useful if you would like to base the styling of a candlestick point on data relating to the previous point. Here is an example of a simple rule:
 
     - (SChartCandlestickSeriesStyle*)styleForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint {
     
         SChartCandlestickSeriesStyle *newStyle = [super styleForPoint:point previousPoint:prevPoint];
         
         float open =  [[point sChartYValueForKey: SChartCandlestickKeyOpen] floatValue];
         float close =  [[point sChartYValueForKey: SChartCandlestickKeyClose] floatValue];
         float priorClose =  [[prevPoint sChartYValueForKey: SChartCandlestickKeyClose] floatValue];
     
         if (close > priorClose && close > open) {
             newStyle.outlineColor = [UIColor greenColor];
             newStyle.risingColor = [UIColor clearColor];
             newStyle.risingColorGradient = [UIColor clearColor];
         }
         return newStyle;
     }

 
 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will be styled by the returned style object
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.

 
 */
- (SChartCandlestickSeriesStyle*)styleForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint;

/** Specifies the fill color for a candlestick on a per-point basis
 
 This method is called for each candlestick point and the standard implementation returns the `risingColor` or `fallingColor` of the style returned by -styleForPoint:previousPoint: You should return a UIColor that will be the used for the candlestick fill regardless of any other style settings or selection.

 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will use the returned color
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.
 @param style The style object that will be used to style this candlestick point
 
 */
- (UIColor*)fillColorForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint style:(SChartCandlestickSeriesStyle*)style;

/** Specifies the gradient fill color for a candlestick on a per-point basis
 
 This method is called for each candlestick point and the standard implementation returns the `risingColorGradient` or `fallingColorGradient` of the style returned by -styleForPoint:previousPoint: You should return a UIColor that will be the used for the candlestick gradient fill regardless of any other style settings or selection.
 
 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will use the returned color
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.
 @param style The style object that will be used to style this candlestick point
 
 */
- (UIColor*)gradientColorForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint style:(SChartCandlestickSeriesStyle*)style;

@end
