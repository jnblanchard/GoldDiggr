//
//  SChartBoxGestureStyle.h
//  SChart
//
//  Copyright (c) 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** If you set the [ShinobiChart gesturePanType] property on a chart to `SChartGesturePanTypeBoxDraw`, the chart will draw a box on the chart during a pan.  When the pan is finished, the chart will zoom to the limits of the box.
 
 The SChartBoxGestureStyle class manages the look and feel of the box gesture.  An instance of the class is contained by the chart's theme.  To update the look of the box gesture on a chart, you could use the following code:
    
    chart.theme.boxGestureStyle.boxLineColor = [UIColor redColor];
    [chart applyTheme];
 
 The definition of the chart theme can be found in `SChartTheme`.
 
 @available Standard
 @available Premium
 */
@interface SChartBoxGestureStyle : NSObject <NSCopying>

/** @name Styling Properties */

/** The color of the outline of the box that will be the new zoomed area.*/
@property (nonatomic, retain) UIColor *boxLineColor;

/** The width of the outline of the box that will be the new zoomed area, in points. */
@property (nonatomic, assign) float boxLineWidth;

/** The color of the lines that extend from the zoom box to the axes. */
@property (nonatomic, retain) UIColor *trackingLineColor;

/** The width of the lines that extend from the zoom box to the axes, in points. */
@property (nonatomic, assign) float trackingLineWidth;

@end
