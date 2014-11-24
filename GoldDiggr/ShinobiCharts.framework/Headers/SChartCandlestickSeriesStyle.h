//
//  SChartCandlestickSeriesStyle.h
//  Dev
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartOHLCSeriesStyle.h"

/** `SChartCandlestickSeriesStyle` manages the appearance of an instance of `SChartCandlestickSeries` on the chart.
 
 Each data point in a candlestick series is visualised as a thick candle between the open and close values, with 'wicks' indicating the high and low positions.
 
 `SChartCandlestickSeriesStyle` inherits some of its behavior from its parent, `SChartOHLCSeriesStyle`.  This controls things like the colors which are used for data points when their data values are rising or falling.  Have a look at the API documentation of the parent class for more information.
 
 This style object allows you to configure properties which are specific to the appearance of candlestick charts.  These are:
 
 - The color and width of the sticks (or 'wicks') at either end of the candle.  See `stickColor` or `stickWidth` for more information.
 - The color and width of the outline of the candle.  See `outlineColor` and `outlineWidth` for more information.
 
 @available Premium
 @sample FinancialChart
 */
@interface SChartCandlestickSeriesStyle : SChartOHLCSeriesStyle
/** @name Styling properties */

/** The color of the candlestick's outline. */
@property (nonatomic, retain)       UIColor     *outlineColor;

/** The color of the candlestick's high and low sticks. */
@property (nonatomic, retain)       UIColor     *stickColor;

/** The width of the candlestick's high and low sticks, in points. */
@property (nonatomic, retain)       NSNumber    *stickWidth;

/** The width of the candlestick's outline, in points. */
@property (nonatomic, retain)       NSNumber    *outlineWidth;

/** Updates this style object using the specified style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartCandlestickSeriesStyle *)style;

@end
