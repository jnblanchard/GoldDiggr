//
//  SChartTheme.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SChartStyle;
@class SChartTitleStyle;
@class SChartMainTitleStyle;
@class SChartLegendStyle;
@class SChartAxisStyle;
@class SChartAxisStyle;
@class SChartCrosshairStyle;
@class SChartBoxGestureStyle;
@class SChartLineSeriesStyle;
@class SChartBandSeriesStyle;
@class SChartColumnSeriesStyle;
@class SChartBarSeriesStyle;
@class SChartDonutSeriesStyle;
@class SChartScatterSeriesStyle;
@class SChartOHLCSeriesStyle;
@class SChartCandlestickSeriesStyle;
@class SChartBubbleSeriesStyle;
@class SChartRadialLineSeriesStyle;

/** 
 The SChartTheme class is responsible for storing styling information for the chart's visual components, such as its titles, axes & tickmarks, and series.
 
 Each theme contains a number of style objects that affect the look of certain aspects of the chart such as its axis, its title or its crosshair. These style objects are exposed as properties on the theme.
 There are also a number of style objects for each series type - for most series, six different styles are provided per theme. Radial and financial (ohlc, candlestick) series only have a one style per theme.
 These are accessed via a method on the theme, for example line series styles are returned by:
 
     SChartLineSeriesStyle *thirdSelectedLineSeriesStyle = [theme lineSeriesStyleForSeriesAtIndex: 2 selected: YES];
     SChartColumnSeriesStyle *secondUnselectedColumnSeriesStyle = [theme columnSeriesStyleForSeriesAtIndex: 2 selected: NO];

 
 Note that if there are more series on the chart than there are series styles provided by the theme, the chart will loop through the style objects it has, using the first style object again once it has cycled through its available styles.
 
 A theme is applied to a chart via the `applyTheme:` method. For example:
 
     [chart applyTheme: theme];

 
 The `applyTheme:` message is passed to the chart upon the initialisation of the chart, applying either the theme you provided to the chart via `initWithFrame:withTheme:` (or `initWithFrame:withTheme:withPrimaryXAxisType:withPrimaryYAxisType:`) or the default theme. Applying a theme to a chart will overwrite any changes to any of the style objects on the chart or its series previously - you should make any further customisations <i>after</i> applying the theme.

 ShinobiCharts comes with several pre-created subclasses of SChartTheme:
 
 - *iOS Seven Theme*: Solid colors without gradients, crisp & clear text (default iOS 7+)
 - *Light Theme*: Brighter colors based on a white background (default pre-iOS 7)
 - *Dark Theme*: Softer colors on a black background
 
 A chart running on a version of iOS older than iOS 7 will use the light theme by default, whereas a chart running on iOS 7 or later will default to using our SChartiOS7Theme
 All themes are, however, available to all versions of iOS - just use them as normal. For example, you could use SChartiOS7Theme on iOS 5.
 
 There are two recommended ways to provide your own custom theme:
 
 - You can use one of the provided SChartTheme classes and customise the style objects provided on it.
 - You can subclass one of the SChartTheme classes, customise the style objects provided, and override the '{line, band, bar, column, donut, ohlc}SeriesStyleForSeriesAtIndex:selected:' method to return your own series styles.
 
  More information about using SChartTheme can be found in the [user guide](../../user_guide.html#Themes).
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 @sa SChartiOS7Theme
 @sa SChartLightTheme
 @sa SChartDarkTheme
 @sa SChartMidnightTheme
 @sample ColumnChart
 @sample PieChart
 @sample FinancialChart
 */
@interface SChartTheme : NSObject <NSCopying>

#pragma mark -
#pragma mark Initializing a theme
/** @name Initializing a theme */

/** Initializes and returns a newly allocated theme object with default settings.
 @return An initialized theme object or `nil` if the object couldn't be created.
 */
- (id)init;

/* DEPRECATED - This looks like a private method.  We will take this off the public API in a future commit. */
- (void)setStyles;

#pragma mark -
#pragma mark Individual style objects
/** @name Individual style objects */

/** Style options relating to the overall chart for cartesian charts.
 
 This includes properties such as:
 
 - The background color of the chart.
 - The border of the chart.

 @see SChartStyle
 */
@property (nonatomic, retain) SChartStyle       *chartStyle;

/** Style options relating to the overall chart for radial charts.
 
 This includes properties such as:
 
 - The background color of the chart.
 - The border of the chart.

 @see SChartStyle
 */
@property (nonatomic, retain) SChartStyle       *radialChartStyle;

/** Style options relating to the chart title.
 
 This includes properties such as: 
 
 - The color, font and alignment of the title.
 - Whether the title overlaps with the chart.

 @see SChartMainTitleStyle
 */
@property (nonatomic, retain) SChartMainTitleStyle  *chartTitleStyle;

/** Style options relating to the chart legend. 
 
 This includes properties such as:
 
 - The color and font of text in the legend.
 - The alignment of symbols in the legend.
 - The color of the legend border.
 - The corner radius of the legend.
 - The background color of the legend.
 - The padding around the legend.
 
 @see SChartLegendStyle
 */
@property (nonatomic, retain) SChartLegendStyle      *legendStyle;

/** Style options relating to the x axis of any cartesian charts.
 
 This includes properties such as:
 
 - The color and font of the axis title.
 - The position of the axis title.
 - The width and color of the axis.
 - The width and color of tick marks on the axis.
 - Whether tick marks are shown.
 - The color of grid lines on the chart for the x axis.
 - Whether grid lines are shown.
 
 @see SChartAxisStyle
 */
@property (nonatomic, retain) SChartAxisStyle        *xAxisStyle;

/** Style options relating to the y axis of any cartesian charts.
 
 This includes properties such as:
 
 - The color and font of the axis title.
 - The position of the axis title.
 - The width and color of the axis.
 - The width and color of tick marks on the axis.
 - Whether tick marks are shown.
 - The color of grid lines on the chart for the y axis.
 - Whether grid lines are shown.
 
 @see SChartAxisStyle
 */
@property (nonatomic, retain) SChartAxisStyle        *yAxisStyle;

/** Style options relating to the radial axis (x-axis) of any radial charts.
 
 This includes properties such as:
 
 - The color and font of the axis title.
 - The position of the axis title.
 - The width and color of the axis.
 - The width and color of tick marks on the axis.
 - Whether tick marks are shown.
 - The color of grid lines on the chart for the x axis.
 - Whether grid lines are shown.
 
 @see SChartAxisStyle
 */
@property (nonatomic, retain) SChartAxisStyle        *xAxisRadialStyle;

/** Style options relating to the polar axis (y-axis) of any radial charts.
 
 This includes properties such as:
 
 - The color and font of the axis title.
 - The position of the axis title.
 - The width and color of the axis.
 - The width and color of tick marks on the axis.
 - Whether tick marks are shown.
 - The color of grid lines on the chart for the y axis.
 - Whether grid lines are shown.
 
 @see SChartAxisStyle
 */
@property (nonatomic, retain) SChartAxisStyle        *yAxisRadialStyle;

/** Style options relating to the chart crosshair.
 
 This includes properties such as:
 
 - The color and width of crosshair lines.
 - The color and font of the crosshair tooltip.
 - The width and color of the crosshair tooltip border.
 
 @see SChartCrosshairStyle
 */
@property (nonatomic, retain) SChartCrosshairStyle   *crosshairStyle;

/** Style options relating to the box gesture. 
 
 This includes properties such as:
 
 - The color of the box which is displayed.
 - The color of tracking lines.
 - The width of the lines on the box.
 - The width of the tracking lines.

 @see SChartBoxGestureStyle
 */
@property (nonatomic, retain) SChartBoxGestureStyle *boxGestureStyle;

#pragma mark -
#pragma mark Colors for this theme
/** @name Colors for this theme */

/** Black palette color.
 
 This is used for:
 
 - The color of the box displayed during box gestures.
 - The text color on the chart title and the axis titles.
 - The color of the legend text and border.
 - The color of axis tick marks and labels.
 - The outline drawn for candlestick chart series.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *blackColor;

/** Black palette color with reduced alpha. 
 
 This is used for tracking lines on box gestures, and for the major grid lines on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *blackColorLowAlpha;

/** Red palette color. 
 
 This is used for:
 
 - Area fill underneath the first line series on the chart.
 - The color of the first bar/column series on the chart.
 - The color of falling data points in the first candlestick series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *redColorDark;

/** Red palette color with increased brightness. 
 
 This is used for:
 
 - The line color of the first line series on the chart.
 - The color of the lower limiting line of the first band series on the chart.
 - The color of the first bar/column series on the chart.
 - The color of points in the first scatter series on the chart.
 - The color of falling data points in the first OHLC series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *redColorLight;

/** Red palette color with increased brightness.
 
 This is used for:
 
 - The color of falling data points in the first OHLC series on the chart.
 - The color of falling data points in the first candlestick series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *redColorBrightLight;

/** Green palette color. 
 
 This is used for:
 
 - The area fill color underneath the second line series on the chart.
 - The color of the second bar/column series on the chart.
 - The color of rising data points in the first OHLC series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *greenColorDark;

/** Green palette color with increased brightness. 
 
 This is used for:
 
 - The line color of the second line series on the chart.
 - The color of the upper limiting line in the first band series on the chart.
 - The color of points in the first band series on the chart.
 - The color of the second bar/column series on the chart.
 - The color of points in the second scatter series on the chart.
 - The color of rising data points in the first OHLC series on the chart.
 - The color of rising data points in the first candlestick series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *greenColorLight;

/** Green palette color with increased brightness. 
 
 This is used for the color of rising data points in the first candlestick series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *greenColorBrightLight;

/** Blue palette color. 
 
 This is used for:
 
 - The area fill color underneath the third line series on the chart.
 - The color of the third bar/column series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *blueColorDark;

/** Blue palette color with increased brightness. 
 
 This is used for:
 
 - The color of the third line series on the chart.
 - The color of the lower limiting line in the second band series on the chart.
 - The color of the third bar/column series on the chart.
 - The color of points in the third scatter series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *blueColorLight;

/** Orange palette color. 
 
 This is used for:
 
 - The area fill color underneath the fourth line series on the chart.
 - The color of the fourth bar/column series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *orangeColorDark;

/** Orange palette color with increased brightness.
 
 This is used for:
 
 - The color of the fourth line series on the chart.
 - The color of the upper limiting line in the second band series on the chart.
 - The color of points in the second band series on the chart.
 - The color of the fourth bar/column series on the chart.
 - The color of the fourth scatter series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *orangeColorLight;

/** Purple palette color.
 
 This is used for:
 
 - The area fill color below the fifth line series on the chart.
 - The color of the fifth bar/column series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *purpleColorDark;

/** Purple palette color with increased brightness.
 
 This is used for:
 
 - The color of the fifth line series on the chart.
 - The color of the lower limiting line on the third band series on the chart.
 - The color of the fifth bar/column series on the chart.
 - The color of the fifth scatter series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *purpleColorLight;

/** Yellow palette color. 
 
 This is used for:
 
 - The area fill color below the sixth line series on the chart.
 - The color of the sixth bar/column series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *yellowColorDark;

/** Yellow palette color with increased brightness. 
 
 This is used for:
 
 - The color of the sixth line series on the chart.
 - The color of the upper limiting line on the third band series on the chart.
 - The color of points in the third band series on the chart.
 - The color of the sixth bar/column series on the chart.
 - The color of the sixth scatter series on the chart.
 
 The theme color properties are included to allow you to access the colors used within the theme, and use them elsewhere in your app.
 */
@property (nonatomic, retain) UIColor *yellowColorLight;

#pragma mark -
#pragma mark Fonts
/** @name Fonts */

/** The name of the bold font to use within the theme. */
@property (nonatomic, retain) NSString *boldFontName;

/** The name of the regular font to use within the theme. 
 
 This is used for:
 
 - The chart title.
 - The axis titles.
 - Text in the legend.
 - Text in the crosshair tooltip.
 - Labels in the first donut series on the chart.
 */
@property (nonatomic, retain) NSString *regularFontName;

/** The name of the light font to use within the theme. 
 
 This is used for labels on major axis ticks.
 */
@property (nonatomic, retain) NSString *lightFontName;

#pragma mark -
#pragma mark Managing series styles
/** @name Managing series styles */
/** Default line width for all line series 
 
 Use this setting to apply a consistent line width across all line series. After setting this value call [ShinobiChart applyTheme] on your chart. This value will be used by default. If you have explicitly set the line width on a line series, that value will take precedence over the default. By default, this property is set to `1`.
 */
@property (nonatomic, retain) NSNumber *lineWidth;

/** Default line width for all column series
 
 Use this setting to apply a consistent line width across all column series. After setting this value call [ShinobiChart applyTheme] on your chart. This value will be used by default. If you have explicitly set the column line width on your series, that value will take precedence over the default. By default, this property is set to `1`.
 */
@property (nonatomic, retain) NSNumber *columnLineWidth;

/** Default line width for all bar series
 
 Use this setting to apply a consistent line width across all bar series. After setting this value call [ShinobiChart applyTheme] on your chart. This value will be used by default. If you have explicitly set the bar width on your series, that value will take precedence over the default. By default, this property is set to `1`.
 */
@property (nonatomic, retain) NSNumber *barLineWidth;

/** Default outline or 'crust' thickness for all donut series
  
 Use this setting to apply a consistent crust thickness across all donut series. After setting this value call [ShinobiChart applyTheme] on your chart. This value will be used by default. If you have explicitly set the donut crust thickness on your series, that value will take precedence over the default. By default, this property is set to `5`.
 */
@property (nonatomic, retain) NSNumber *donutCrustThickness;

/** Default outline or 'crust' thickness for all pie series

 Use this setting to apply a consistent crust thickness across all pie series. After setting this value call [ShinobiChart applyTheme] on your chart. This value will be used by default. If you have explicitly set the pie crust thickness on your series, that value will take precedence over the default. By default, this property is set to `1`.
 */
@property (nonatomic, retain) NSNumber *pieCrustThickness;

#pragma mark -
#pragma mark - Series styles
/** @name Series styles */

/** Adds a series style to the array of line series styles contained within the theme.
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addLineSeriesStyle:(SChartLineSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of band series styles
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addBandSeriesStyle:(SChartBandSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of column series styles
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addColumnSeriesStyle:(SChartColumnSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of bar series styles
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addBarSeriesStyle:(SChartBarSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Encodes the donut series style object and stores in the array of donut series styles. 
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.*/
- (void)addDonutSeriesStyle:(SChartDonutSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of scatter series styles
  
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addScatterSeriesStyle:(SChartScatterSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of ohlc series styles
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addOHLCSeriesStyle:(SChartOHLCSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Stores the series style in the array of candlestick series styles
 
 The theme contains two sets of series styles - one for series in their normal state, and one for when they are selected.  When you add a series style to the theme, you can specify when it should be used on a series using the `selected` parameter.
 @param newStyle The series style to add to the theme.
 @param selected If this is set to `YES`, the style will be used for series when they are selected.
 */
- (void)addCandlestickSeriesStyle:(SChartCandlestickSeriesStyle *)newStyle asSelected:(BOOL)selected;

/** Returns the line series style for the specified series on the chart.
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartLineSeriesStyle *)lineSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the radial line series style for the specified series on the chart.
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartRadialLineSeriesStyle *)radialLineSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the band series style for the specified series on the chart. 
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartBandSeriesStyle *)bandSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the column series style for the specified series on the chart. 
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartColumnSeriesStyle *)columnSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the bar series style for the specified series on the chart. 
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartBarSeriesStyle *)barSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the donut series style for the specified series on the chart. 
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartDonutSeriesStyle *)donutSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the scatter series style for the specified series on the chart.
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartScatterSeriesStyle *)scatterSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;


/** Returns the bubble series style for the specified series on the chart.
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartBubbleSeriesStyle *)bubbleSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the OHLC series style for the specified series on the chart. 
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartOHLCSeriesStyle *)ohlcSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/** Returns the candlestick series style for the specified series on the chart.
 
 @param seriesIndex The index of the series on the chart.
 @param selected If set to `YES`, this method returns the selected style for the series.  If not, this method returns the normal style for the series.
 @return The style to use for the given series.
 */
- (SChartCandlestickSeriesStyle *)candlestickSeriesStyleForSeriesAtIndex:(NSInteger)seriesIndex selected:(BOOL)selected;

/* DEPRECATED - We will move this off the public API in a future commit. */
-(void)configureLineSeriesStyle:(SChartLineSeriesStyle *)style;

/* DEPRECATED - We will move this off the public API in a future commit. */
-(void)configureBarSeriesStyle:(SChartBarSeriesStyle *)style;

/* DEPRECATED - We will move this off the public API in a future commit. */
-(void)configureColumnSeriesStyle:(SChartColumnSeriesStyle *)style;

/* DEPRECATED - We will move this off the public API in a future commit. */
-(void)configureScatterSeriesStyle:(SChartScatterSeriesStyle *)style;

@end
