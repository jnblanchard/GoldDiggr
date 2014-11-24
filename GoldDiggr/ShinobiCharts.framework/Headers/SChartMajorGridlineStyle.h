//
//  SChartMajorGridlineStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartRadialLineRenderMode.h"

/** Style properties for the major grid lines.
 
 */
@interface SChartMajorGridlineStyle : NSObject <NSCopying>
/** @name Style Properties */
/** Show grid lines from the major tick marks */
@property (nonatomic, assign)     BOOL      showMajorGridLines;   
@property (nonatomic, assign)     BOOL      showMajorGridLinesSet;

/** Should the lines be dashed */
@property (nonatomic, assign)     BOOL      dashedMajorGridLines; 
@property (nonatomic, assign)     BOOL      dashedMajorGridLinesSet;

/** The UIColor of the grid lines */
@property (nonatomic, retain)     UIColor  *lineColor;
/** The width in pixels of the grid lines */
@property (nonatomic, retain)     NSNumber *lineWidth;
/** The dash pattern of the line.
 
 An array of pixel lengths for each adjacent section. The pattern will wrap if the line needs more segments than provided.*/
@property (nonatomic, retain)     NSArray  *dashStyle;

/** Whether x-axis lines and y-axis grid lines on radial charts should be curved or straight.

 By default, this is set to `SChartRadialLineRenderModeCurved`.
 
 - SChartRadialLineRenderModeCurved: Lines are drawn as an arc.
 - SChartRadialLineRenderModeLinear: Lines are drawn as straight lines between tick frequencies, in a "spider-web" style
 */
@property (nonatomic, assign)     SChartRadialLineRenderMode lineRenderMode;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartMajorGridlineStyle *)style;

@end
