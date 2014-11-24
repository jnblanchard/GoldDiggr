//
//  SChartTitleStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChart.h"


/** The look of a chart is managed by an instance of `SChartTheme` or one of its sub-classes.  Themes contain a set of style objects, each of which are responsible for managing the look of a particular aspect of the chart.  You'll find instances of this class or a subclass on the theme for axes titles and for the chart title.
 
 The SChartTitleStyle class is responsible for managing the look of the titles on the chart.  This includes things like:
 
 - The title color.
 - The title font.
 - The minimum font size for the title.
 - The background color of the title label.
 - The position of the title.
 
 There are two subclasses of SChartTitleStyle.  `SChartAxisTitleStyle` is used for the titles on the chart axes.  `SChartMainTitleStyle` is used for the main title on the chart.
 
 @available Standard
 @available Premium
 */
@interface SChartTitleStyle : NSObject <NSCopying>

/** @name Styling Properties */

/** The color of the text for the title. */
@property (nonatomic, retain)     UIColor           *textColor;

/** The font for the title text. */
@property (nonatomic, retain)     UIFont            *font;

/** The minimum scale factor for the title text.
 
 Functions in the same way as the UILabel equivalent property.
 **/
@property (nonatomic)             CGFloat           minimumScaleFactor;

/** The text alignment of the title. */
@property (nonatomic)             NSTextAlignment   textAlign;

/** The background color of the title label. */
@property (nonatomic, retain)     UIColor           *backgroundColor;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

/** Where the title will appear relative to the chart or axis. 
 
 This property has two different purposes:
 
 The effect of the different position values on the chart depends on the context. `SChartTitleStyle` is used both for the main chart title, and for the axis titles. The main chart title is always displayed at the top of the chart. The value of position is used to define whether the title is displayed on the left, in the center, or on the right of the chart.
 
 For axis titles, the effect of the position value depends on the type of the chart. On cartesian charts, the axis titles are always displayed outside of the axes with reference to the plot area. The value of position defines whether the title is displayed on the left, in the center or on the right for x axes, and at the top, in the center or at the bottom for y axes.
 
 On radial charts, the x axis title is always centered horizontally. The value of position defines whether the x axis title is displayed at the top or at the bottom of the chart. If a position of `SChartTitlePositionCenter` is defined for the x axis, the axis title is also displayed at the bottom. The behavior of the y axis title is the same as for cartesian charts.

 _If you would like to position your title label manually you can do so by setting its frame._

 - The `SChartMainTitleStyle` is used for the main title on the chart. The possible values of position are defined as follows:
  - SChartTitlePositionCenter: Configures the title to align with the center of the chart.
  - SChartTitlePositionBottomOrLeft: Configures the title to align with the left of the chart.
  - SChartTitlePositionTopOrRight: Configures the title to align with the right of the chart.
 
 - The `SChartAxisTitleStyle` is used for the titles on the chart axes. The possible values of position are defined as follows:
  - SChartTitlePositionCenter: Configures the title to align with the center of the axis.
  - SChartTitlePositionBottomOrLeft: Configures the title to align with the or left of the x axis, or the bottom of the y axis.
  - SChartTitlePositionTopOrRight: Configures the title to align with the right of the x axis, or the top of the chart y axis.
 */
@property (nonatomic) SChartTitlePosition           position;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartTitleStyle *)style;

@end
