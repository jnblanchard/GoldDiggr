//
//  SChartMidnightTheme.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

/** The SChartMidnightTheme is based around a black background with lighter features.
 
 @available Standard
 @available Premium
 
 @warning The `SChartMidnightTheme` will be removed in a future release.
 */
@class SChartTheme;

DEPRECATED_ATTRIBUTE
@interface SChartMidnightTheme : SChartTheme {
    
    UIColor *midnight_greyColor, 
            *midnight_greyColorLowAlpha,
            *midnight_greyColorLabel,
            *midnight_brownColorDark,
            *midnight_brownColorLight,
            *midnight_pinkColor,
            *midnight_pinkColorLowAlpha,
            *midnight_textShadowColor;
}

/** @name Colors for this theme */
/** Gray palette color.
 
 This is used for:
 
 - The axis lines and tick marks on the chart axes.
 - Crosshair lines.
 - Tracking lines on box gestures.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_greyColor;

/** Gray palette color with reduced alpha. 
 
 This is used for major grid lines on the chart.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_greyColorLowAlpha;

/** Gray palette color for text labels. 
 
 This is used for:
 
 - The chart title.
 - The axis titles.
 - Labels on the chart axes.
 - The text in the chart legend.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_greyColorLabel;

/** DEPRECATED - use [SChartTheme blueColorDark] instead.
 
 Blue palette color */
@property (nonatomic, retain, readonly) UIColor *midnight_blueColorDark DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme blueColorLight] instead.
 
 Blue palette color with increased brightness */
@property (nonatomic, retain, readonly) UIColor *midnight_blueColorLight DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme greenColorDark] instead.
 
 Green palette color */
@property (nonatomic, retain, readonly) UIColor *midnight_greenColorDark DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme greenColorLight] instead.
 
 Green palette color with increased brightness */
@property (nonatomic, retain, readonly) UIColor *midnight_greenColorLight DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme purpleColorDark] instead.
 
 Purple palette color */
@property (nonatomic, retain, readonly) UIColor *midnight_purpleColorDark DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme purpleColorLight] instead.
 
 Purple palette color with increased brightness */
@property (nonatomic, retain, readonly) UIColor *midnight_purpleColorLight DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme orangeColorDark] instead.
 
 Orange palette color */
@property (nonatomic, retain, readonly) UIColor *midnight_orangeColorDark DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme orangeColorLight] instead.
 
 Orange palette color with increased brightness */
@property (nonatomic, retain, readonly) UIColor *midnight_orangeColorLight DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme yellowColorDark] instead.
 
 Yellow palette color */
@property (nonatomic, retain, readonly) UIColor *midnight_yellowColorDark DEPRECATED_ATTRIBUTE;

/** DEPRECATED - use [SChartTheme yellowColorLight] instead.
 
 Yellow palette color with increased brightness */
@property (nonatomic, retain, readonly) UIColor *midnight_yellowColorLight DEPRECATED_ATTRIBUTE;

/** Brown palette color. 
 
 This is used for:
 
 - The area fill underneath the sixth line series on the chart.
 - The sixth bar/column series on the chart.
 - The sixth scatter series on the chart.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_brownColorDark;

/** Brown palette color with increased brightness. 
 
 This is used for:
 
 - The sixth line series on the chart.
 - The sixth bar/column series on the chart.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_brownColorLight;

/* DEPRECATED - This color is no longer used.  It has been left on the API for backwards compatibility only. */
@property (nonatomic, retain, readonly) UIColor *midnight_pinkColor DEPRECATED_ATTRIBUTE;

/* DEPRECATED - This color is no longer used.  It has been left on the API for backwards compatibility only. */
@property (nonatomic, retain, readonly) UIColor *midnight_pinkColorLowAlpha DEPRECATED_ATTRIBUTE;

/** Shadow palette color for labels.
 
 This is used for:
 
 - Shadow on text in axis labels.
 */
@property (nonatomic, retain, readonly) UIColor *midnight_textShadowColor;
@end
