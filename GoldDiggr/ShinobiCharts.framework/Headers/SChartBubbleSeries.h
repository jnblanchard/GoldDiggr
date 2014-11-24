//
//  SChartBubbleSeries.h
//  Dev
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartPointSeries.h"
@class SChartBubblePointStyle;

/**`SChartBubbleSeries` is a type of `SChartSeries` that uses its data points to construct a bubble series.
 
  <img src="../Images/userguide_bubbleSeries.png" width=400/>
 
 This type of series focuses on allowing bubble sizes to be controlled via the use of data point objects of type `SChartBubbleDataPoint`. As such this series ignores attempts to set the size/radius of its data points in any other way.
 
 The size of the bubbles in this series are independent of any axes that the series might be linked to. This makes the concept of a scale that alters the size of all bubbles in the series useful. You can supply your own `scale` or let the series be scaled via an auto-calculated value such that the largest bubble in the series matches some chosen diameter (see `biggestBubbleDiameterForAutoScaling`).
 
 This series has the corresponding series and point styles `SChartBubbleSeriesStyle` and `SChartBubblePointStyle` respectively.*/

@class SChartBubbleSeriesStyle;

@interface SChartBubbleSeries : SChartPointSeries

#pragma mark - Scaling Bubbles
/** @name Scaling Bubbles*/

/** The value that will be used to scale the rendered bubbles for this series.
 
 A value of `nil` will result in the series auto-calculating an appropriate scale to use. The auto-calculated scale is based on `biggestBubbleDiameterForAutoScaling`.
 
 By default, this property is set to `nil`. */
@property (nonatomic, retain) NSNumber *scale;

/** This property is used to calculate an appropriate auto-scale that results in the biggest bubble in the series being `[biggestBubbleDiameterForAutoScaling doubleValue]` points in diameter.
 
 If this property is `nil` then a default value of half of the current smallest canvas dimension will be used instead. 
 
 By default, this property is set to `nil`. */
@property (nonatomic, retain) NSNumber *biggestBubbleDiameterForAutoScaling;

/** Returns the current scale being used to render the bubble series.
 
 If you have set `scale` then this will be returned, otherwise an automatically calculated scale will be returned.
 
 Note that if no `scale` has been set and no auto-caulculated value exists that `nil` will be returned.*/
- (NSNumber*) currentScale;

#pragma mark -
#pragma mark Styling
/**@name Styling */
/** Manages the appearance of the bubble series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartBubbleSeriesStyle
 */
-(SChartBubbleSeriesStyle *)style;

/** Sets the style object for the bubble series.
 
 @param style The new style object to use for the bubble series.
 @see style
 */
-(void)setStyle:(SChartBubbleSeriesStyle *)style;

/** Manages the appearance of the bubble series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartBubbleSeriesStyle
 */
-(SChartBubbleSeriesStyle *)selectedStyle;

/** Sets the style object for the bubble series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartBubbleSeriesStyle *)selectedStyle;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each datapoint in this series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartXValue` & `sChartYValue` properties to access each datapoint's X & Y values. Here is an example of how to use these properties to style each point:
 
     - (SChartBubblePointStyle*)styleForPoint:(id<SChartData>)point {
     
         SChartBubblePointStyle *newStyle = [super styleForPoint:point];
         
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
- (SChartBubblePointStyle*)styleForPoint:(id<SChartData>)point;

@end
