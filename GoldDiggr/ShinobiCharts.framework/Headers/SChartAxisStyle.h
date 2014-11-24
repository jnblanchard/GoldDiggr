//
//  SChartAxisStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SChartTickStyle;
@class SChartTickStyle;
@class SChartMajorGridlineStyle;
@class SChartGridStripeStyle;
@class SChartAxisTitleStyle;
@class SChartAxisStyle;

/** The axis style object controls the look and feel for the axis, tick marks and labels, gridlines and grid stripes.

 @available Standard
 @available Premium
 
 @see SChartAxis
 @see SChartAxisTitleStyle
 @see SChartTickStyle
 @see SChartMajorGridlineStyle
 @see SChartGridStripeStyle
 */
@interface SChartAxisStyle : NSObject <NSCopying>

/** @name Styling Properties */
/** The UIColor for the axis line */
@property (nonatomic, retain)     UIColor  *lineColor;

/** The width in pixels of the axis line */
@property (nonatomic, retain)     NSNumber *lineWidth;

/** The padding between datapoints of different series where they are plotted on the same axis value.
 
 A value between `0.0` and `1.0` as a percentage of the available space */
@property (nonatomic, retain)     NSNumber *interSeriesPadding;

/** The padding between sets of series' datapoints on neighbouring axis values.
 
 A value between `0.0` and `1.0` as a percentage of the available space */
@property (nonatomic, retain)     NSNumber *interSeriesSetPadding;

/** An SChartTickStyle object containing styling preferences for the major tick marks */
@property (nonatomic, retain)     SChartTickStyle *majorTickStyle;

/** An SChartTickStyle object containing styling preferences for the minor tick marks */
@property (nonatomic, retain)     SChartTickStyle *minorTickStyle;

/** An SChartMajorGridlineStyle object containing styling preferences for the major gridlines */
@property (nonatomic, retain)     SChartMajorGridlineStyle *majorGridLineStyle;

/** An SChartGridStripeStyle object containing styling preferences for the grid stripes */
@property (nonatomic, retain)     SChartGridStripeStyle *gridStripeStyle;

/** An SChartAxisTitleStyle object containing styling preferences for the axis title */
@property (nonatomic, retain)     SChartAxisTitleStyle *titleStyle;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartAxisStyle *)style;

@end
