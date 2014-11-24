//
//  SChartPointSeries.h
//  ShinobiControls_Source
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartCartesianSeries.h"

/** An SChartPointSeries acts as the base class for both SChartScatterSeries and SChartBubbleSeries and concerns itself with drawing data points. SChartScatterSeries adds the drawing of inner points, whereas SChartBubbleSeries adds the ability to control the drawn datapoint size via SChartBubbleDataPoints. It is therefore unlikely that you will ever want to directly instantiate a series of this type, but should you wish to do so note that the corresponding point style is SChartBasePointStyle.*/

@class SChartPointSeriesStyle;
@class SChartBaselinePointStyle;

@interface SChartPointSeries : SChartCartesianSeries

/**@name Styling */
/** Override any default settings or theme settings on a _per series_ basis by editing the values in these style objects.
 
 The `SChartScatterSeriesStyle` contains all of the objects relevant to styling a scatter series. */
-(SChartPointSeriesStyle *)style;
-(void)setStyle:(SChartPointSeriesStyle *)style;

/** Style settings in this object will be applied when the series is marked as selected (or a datapoint is selected).*/
-(SChartPointSeriesStyle *)selectedStyle;
-(void)setSelectedStyle:(SChartPointSeriesStyle *)selectedStyle;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Specifies the style to use on a per-point basis
 
 This method is called for each datapoint in this series and the standard implementation chooses to return either the style or selectedStyle object based on the `selectionMode` and
 selected state of either the point or the series. _Computationally expensive operations here will increase initial render time._
 
 Use the `sChartXValue` & `sChartYValue` properties to access each datapoint's X & Y values. Here is an example of how to use these properties to style each point:
 
    - (SChartBaselinePointStyle*)styleForPoint:(id<SChartData>)point {
 
        SChartBaselinePointStyle *newStyle = [super styleForPoint:point];
 
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
- (SChartBaselinePointStyle*)styleForPoint:(id<SChartData>)point;

@end
