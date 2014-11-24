//
//  SChartOHLCSeries.h
//  ShinobiControls_Source
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartBarColumnSeries.h"
#import "SChartOHLCSeriesStyle.h"

/** `SChartOHLCSeries` is a type of `SChartSeries` which displays Open-High-Low-Close (OHLC) data on a chart.
 
 <img src="../Images/userguide_ohlcSeries.png" width=400/>
 
 Each data point in an OHLC series is visualised as a line between the high and low values, with short perpendicular bars indicating the open and close positions.
 
 Data points in an OHLC series will contain multiple values.  This means that they will be instances of `SChartMultiXDataPoint` or `SChartMultiYDataPoint`, depending on the orientation of the series.  The keys for the values in each data point will be `SChartOHLCKeyOpen`, `SChartOHLCKeyHigh`, `SChartOHLCKeyLow` and `SChartOHLCKeyClose`.
 
 In order to provide the Open, High, Low, and Close values to the chart, the data points in the OHLC series should implement either the `[SChartData sChartXValueForKey:]` method or the `[SChartData sChartYValueForKey:]` method on the `SChartData` protocol, depending on the series orientation.
 
 The series contains an instance of `SChartOHLCSeriesStyle`, which manages the appearance of the series on the chart.
 
 @available Premium
 @sa ChartsUserGuide
 @sample FinancialChart
 */
@interface SChartOHLCSeries : SChartBarColumnSeries

#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the OHLC series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartOHLCSeriesStyle
 */
-(SChartOHLCSeriesStyle *)style;

/** Sets the style object for the OHLC series.
 
 @param style The new style object to use for the OHLC series.
 @see style
 */
-(void)setStyle:(SChartOHLCSeriesStyle *)style;

/** Manages the appearance of the OHLC series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartOHLCSeriesStyle
 */
-(SChartOHLCSeriesStyle *)selectedStyle;

/** Sets the style object for the OHLC series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartOHLCSeriesStyle *)selectedStyle;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each OHLC datapoint in the series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartYValueForKey:` method to access each datapoint's Y-values unless you have setup a horizontal OHLC series. This method is also useful if you would like to base the styling of a OHLC point on data relating to the previous point. Here is an example of a simple rule:
 
     - (SChartOHLCSeriesStyle*)styleForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint {
 
        SChartOHLCSeriesStyle *newStyle = [super styleForPoint:point previousPoint:prevPoint];
 
        float open =  [[point sChartYValueForKey: SChartCandlestickKeyOpen] floatValue];
        float close =  [[point sChartYValueForKey: SChartCandlestickKeyClose] floatValue];
        float priorClose =  [[prevPoint sChartYValueForKey: SChartCandlestickKeyClose] floatValue];
 
        if (close > priorClose && close > open) {
            newStyle.risingColor = [UIColor clearColor];
            newStyle.risingColorGradient = [UIColor clearColor];
        }
        return newStyle;
     }

 
 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will be styled by the returned style object
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.
 
 
 */
- (SChartOHLCSeriesStyle*)styleForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint;

/** Specifies the fill color of the trunk for a OHLC on a per-point basis
 
 This method is called for each OHLC point and the standard implementation returns the `risingColor` or `fallingColor` of the style returned by -styleForPoint:previousPoint: You should return a UIColor that will be the used for the OHLC fill of the trunk regardless of any other style settings or selection.
 
 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will use the returned color
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.
 @param style The style object that will be used to style this OHLC point
 
 */
- (UIColor*)fillColorForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint style:(SChartOHLCSeriesStyle*)style;

/** Specifies the gradient fill color of the trunk for a OHLC on a per-point basis
 
 This method is called for each OHLC point and the standard implementation returns the `risingColorGradient` or `fallingColorGradient` of the style returned by -styleForPoint:previousPoint: You should return a UIColor that will be the used for the OHLC gradient fill of the trunk regardless of any other style settings or selection.
 
 ___Note:___ _previousPoint refers to the order that the data is passed into the datasource and not to the ordering as indicated by the axis values._
 
 @param point The data-point that will use the returned color
 @param prevPoint The point that was passed to the datasource immediately prior to this one. Will be nil for first point.
 @param style The style object that will be used to style this OHLC point
 
 */
- (UIColor*)gradientColorForPoint:(id<SChartData>)point previousPoint:(id<SChartData>)prevPoint style:(SChartOHLCSeriesStyle*)style;

@end
