//
//  SChartLineSeriesBaseStyle.h
//  ShinobiCharts
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartScatterSeriesStyle.h"

/** `SChartLineSeriesBaseStyle` manages the appearance of an instance of `SChartLineSeries` and subclasses, on a chart.

 @available Standard
 @available Premium
 */
@interface SChartLineSeriesBaseStyle : SChartScatterSeriesStyle

#pragma mark -
#pragma mark Styling properties
/** @name Styling properties */

/** Defines whether the area between the line and the axis is filled.
 
 The color of the area fill is defined by `areaColor` or `areaColorBelowBaseline`. */
@property (nonatomic)             BOOL      showFill;

/** If `showFill` is set to `YES`, this adds a gradient to the area fill.
 
 The gradient starts at `areaColor` and finishes at `areaColorLowGradient`. */
@property (nonatomic)             BOOL      fillWithGradient;

/** The color of the line.
 
 This property is used as long as `showFill` isn't set to `YES`.  If the area is filled, `areaLineColor` is used instead.
 */
@property (nonatomic, retain)     UIColor   *lineColor;

/** The color for the line if the area is filled.
 
 If the area isn't filled, `lineColor` is used instead.
 */
@property (nonatomic, retain)     UIColor   *areaLineColor;

/** The width of the line in pixels
 
 This property is used as long as `showFill` isn't set to `YES`.  If the area is filled, `areaLineWidth` is used instead.
 */
@property (nonatomic, retain)     NSNumber  *lineWidth;

/** The width of the line in pixels, if the area is filled.
 
 If the area isn't filled, `lineWidth` is used instead.
 */
@property (nonatomic, retain)     NSNumber  *areaLineWidth;

/** The color of the area fill between the line and the axis.
 @see showFill */
@property (nonatomic, retain)     UIColor   *areaColor;

/** The second color which is used to form a gradient area fill.
 @see fillWithGradient */
@property (nonatomic, retain)     UIColor   *areaColorLowGradient;

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
-(void)supplementStyleFromStyle:(SChartLineSeriesBaseStyle *)style;



@end
