//
//  SChartDataPointLabelStyle.h
//  ShinobiCharts
//
//  Created by Thomas Kelly on 14/11/2013.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SChartDataPointLabelDisplayValues)
{
    SChartDataPointLabelDisplayValuesX,
    SChartDataPointLabelDisplayValuesY,
    SChartDataPointLabelDisplayValuesBoth
};

typedef NS_ENUM(NSUInteger, SChartDataPointLabelOrientation)
{
    SChartDataPointLabelOrientationHorizontal,
    SChartDataPointLabelOrientationVertical,
    SChartDataPointLabelOrientationHorizontalReversed,
    SChartDataPointLabelOrientationVerticalReversed
};

typedef NS_ENUM(NSUInteger, SChartDataPointLabelPosition)
{
    SChartDataPointLabelPositionBelowData,
    SChartDataPointLabelPositionAboveData
};

/** The data point label style object controls the look and feel for labels appearing next to a series data point.
 
 @available Standard
 @available Premium
 */
@interface SChartDataPointLabelStyle : NSObject<NSCopying>

#pragma mark - Layout
/** @name Layout */

/** Whether or not to show a label next to each `SChartDataPoint`. Defaults to `NO`. */
@property (nonatomic, assign) BOOL showLabels;

/** The center of the `SChartDataPointLabel`, relative to the data point. Defaults to `CGPointZero`. */
@property (nonatomic, assign) CGPoint offsetFromDataPoint;

/** Whether or not to offset negative values in the opposite direction to positive values. Defaults to `YES`.
 
 Setting this to `YES` will offset positive values in the same way, but negative values in the opposite direction.
 For horizontal series such as column charts, this means in the opposite Y direction.
 For vertical series such as bar charts, this means in the opposite X direction. */
@property (nonatomic, assign) BOOL offsetFlippedForNegativeValues;

/** The direction the text should be displayed. Defaults to `SChartDataPointLabelOrientationHorizontal`.
 
 * `SChartDataPointLabelOrientationHorizontal`: Text is displayed left-to-right.
 * `SChartDataPointLabelOrientationVertical`: Text is rotated and displayed top-to-bottom.
 * `SChartDataPointLabelOrientationHorizontalReversed`: Text is displayed upside down, right-to-left.
 * `SChartDataPointLabelOrientationVerticalReversed`: Text is rotated and displayed bottom-to-top.
 */
@property (nonatomic, assign) SChartDataPointLabelOrientation textOrientation;

/** The position in the data where the data point label should be placed. Defaults to `SChartDataPointLabelPositionBelowData`
 
 * `SChartDataPointLabelPositionAboveData`: The data point label is drawn on top of the data.
 * `SChartDataPointLabelPositionBelowData`: The data point label is drawn behind the data. */
@property (nonatomic, assign) SChartDataPointLabelPosition position;

#pragma mark - Appearance
/** @name Appearance */

/** The font used for the data point label.
 
 Default value is inherited from the axis label font of current theme. */
@property (nonatomic, retain) UIFont *font;

/** The color of the text used to display the data point label.
 
 Default value is inherited from the title text color of current theme. */
@property (nonatomic, retain) UIColor *textColor;

/** Whether to display x and y values, or both, of the `SChartDataPoint`.
 
 * `SChartDataPointLabelDisplayXValue`: Only display the X-value of the `SChartDataPoint`.
 * `SChartDataPointLabelDisplayYValue`: Only display the Y-value of the `SChartDataPoint`.
 * `SChartDataPointLabelDisplayBothValues`: Display both the X and Y values of the `SChartDataPoint`. */
@property (nonatomic, assign) SChartDataPointLabelDisplayValues displayValues;

/** Supplements this style object by taking styles from an existing `SChartDataPointLabelStyle`. */
- (void)supplementStyleFromStyle:(SChartDataPointLabelStyle *)style;

@end
