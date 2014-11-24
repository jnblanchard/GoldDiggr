//
//  SChartTickStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartTickLabelOrientation.h"

/** The style properties for tick marks 
 
 */
@interface SChartTickStyle : NSObject <NSCopying>
/** @name Styling Properties */
/** Should tick marks be displayed on the axes. */
@property (nonatomic) BOOL showTicks;

/** DEPRECATED in 2.6.0 - this will be removed from the API soon. */
@property (nonatomic) BOOL showTicksSet DEPRECATED_ATTRIBUTE;

/** Should labels be displayed on the major tick marks. */
@property (nonatomic) BOOL showLabels;

/** DEPRECATED in 2.6.0 - this will be removed from the API soon. */
@property (nonatomic) BOOL showLabelsSet DEPRECATED_ATTRIBUTE;

/** The orientation of labels on major tick marks
 
 - TickLabelOrientationHorizontal: Configures the orientation of the labels on major tick marks to be horizontal.
 - TickLabelOrientationDiagonal: Configures the orientation of the labels on major tick marks to be diagonal.
 - TickLabelOrientationVertical: Configures the orientation of the labels on major tick marks to be vertical.
 
 @warning Tick label orientation isn't currently supported by radial charts.
 */
@property (nonatomic) TickLabelOrientation tickLabelOrientation;

/** DEPRECATED in 2.6.0 - this will be removed from the API soon. */
@property (nonatomic) BOOL tickLabelOrientationSet DEPRECATED_ATTRIBUTE;

/** The UIColor for the tick mark lines */
@property (nonatomic, retain) UIColor *lineColor;
/** The width of the tick mark line in pixels */
@property (nonatomic, retain) NSNumber *lineWidth;
/** The length of the tick mark lines in pixels */
@property (nonatomic, retain) NSNumber *lineLength;
/** The color for the text in labels */
@property (nonatomic, retain) UIColor *labelColor;
/** The font for the labels */
@property (nonatomic, retain) UIFont  *labelFont;
/** The text alignment of the labels */
@property (nonatomic, assign) NSTextAlignment textAlignment;
/** The shadow color for label text */
@property (nonatomic, retain) UIColor *labelTextShadowColor;
/** The gap between a tick label and its corresponding tick mark 
 
 By default, this property is set to `5`. */
@property (nonatomic, retain) NSNumber *tickGap;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartTickStyle *)style;

@end
