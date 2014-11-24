//
//  SChartTitle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/** A title object used by the chart and chart axes to display a UILabel with appropriate text.
 
 The look and feel of titles on the chart is managed by instances of one of the sub-classes of `SChartTitleStyle`.
 The look and feel of the chart title is managed by `SChartMainTitleStyle`.  The look and feel of axis titles is managed by `SChartAxisTitleStyle`.  `SChartTitleStyle` contains any common styling properties of all titles.
 
 By default, the chart title is displayed below the chart, and the chart canvas makes room for the title.  If you wish to update the position of the title, you can use the [SChartTitleStyle position] property.  This allows you to specify the position of the title relative to the chart.  `SChartMainTitleStyle` also offers you some properties to fine-tune the title appearance.  These are:
 
 - [SChartMainTitleStyle titleCentresOn]: Allows you to specify whether the title centers on the full chart view, the plot area, or the canvas.
 - [SChartMainTitleStyle overlapChartTitle]: Allows you to specify whether the title overlaps with the chart, or whether the chart canvas makes room for it.
 
 By default, the axes titles are displayed in the center of each axis.  If you wish to update the position of the title, you can use the [SChartTitleStyle position] property.  `SChartAxisTitleStyle` also allows you to specify the orientation of the axis title, to be either horizontal or vertical.

 @available Standard
 @available Premium
 
 @see ChartsUserGuide
 @see ShinobiChart
 @see SChartAxis
 
 @warning Currently, chart titles are not supported by radial charts.
 */
@interface SChartTitle : UILabel

/** DEPRECATED in version 2.6.0. */
@property (nonatomic, assign) BOOL userSetFrame DEPRECATED_ATTRIBUTE;


@end
