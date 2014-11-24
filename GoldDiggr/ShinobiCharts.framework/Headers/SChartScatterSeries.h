//
//  SChartScatterSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h> 

#import "SChartPointSeries.h"
#import "SChartScatterSeriesStyle.h"

/** `SChartScatterSeries` is a type of `SChartSeries` that uses its data points to construct a scatter series.
 
 <img src="../Images/userguide_scatterSeries.png" width=400/>
 
 A common use case for scatter series is to use images for your data points.  In order to set a default image for each point in your scatter series, you can configure the series style.  The following code shows how:
 
    scatterSeries.style.pointStyle.texture = [UIImage imageNamed:@"texture.png"];
 
 In order to configure the radius of your data points, you can also configure the series style, as follows:
 
    scatterSeries.style.pointStyle.radius = @10;
 
 Note that there is an SChartBubbleSeries that allows you to control the size of the bubbles via the data point objects returned from your data source.
 
 Data points are rendered as an inner point and an outer point (the drawing of the outer points is handled by the superclass SChartPointSeries). In the case where you just wish to render a single image for your data point, rather than a larger image with a smaller image inside it, you would set the `[SChartPointStyle innerRadius]` property of the the series style to `@0`.
 
 For more information on styling data points, see `SChartPointStyle`.
 
 **Configuring individual data points**
 
 As well as setting default properties for the whole series, you can set properties for individual data points in your chart series.
 
 You specify properties for individual data points in the chart's datasource (which will adopt the `SChartDatasource` protocol).
 
 To set the radius of an individual data point in the series, you would implement the `[SChartDatasource sChartRadiusForDataPoint:dataPointAtIndex:forSeriesAtIndex:]` method on the datasource, and provide the correct radius for each point.
 
 To set an image to use for a particular data point in your series, you would implement the `[SChartDatasource sChartTextureForPoint:dataPointAtIndex:forSeriesAtIndex:]` method on the datasource.  
 
 You can also set the inner radius of individual points, by implementing the `[SChartDatasource sChartInnerRadiusForDataPoint:dataPointAtIndex:forSeriesAtIndex:]` method on the datasource.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartScatterSeries : SChartPointSeries

#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the scatter series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartScatterSeriesStyle
 */
-(SChartScatterSeriesStyle *)style;

/** Sets the style object for the scatter series.
 
 @param style The new style object to use for the scatter series.
 @see style
 */
-(void)setStyle:(SChartScatterSeriesStyle *)style;

/** Manages the appearance of the scatter series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartScatterSeriesStyle
 */
-(SChartScatterSeriesStyle *)selectedStyle;

/** Sets the style object for the scatter series when it is selected.
 
 @param selectedStyle The new style object to use.
 @see selectedStyle
 */
-(void)setSelectedStyle:(SChartScatterSeriesStyle *)selectedStyle;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each datapoint in this series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartXValue` & `sChartYValue` properties to access each datapoint's X & Y values. Here is an example of how to use these properties to style each point:
 
     - (SChartPointStyle*)styleForPoint:(id<SChartData>)point {
     
         SChartPointStyle *newStyle = [super styleForPoint:point];
         
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
- (SChartPointStyle*)styleForPoint:(id<SChartData>)point;
@end
