//
//  SChartSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartLegendItem.h"
#import "SChartDataSeries.h"
#import "SChartData.h"
#import "SChartDataPoint.h"
#import "SChartGLView.h"
#import "SChartTheme.h"
#import "SChartAxis.h"

@class SChartSeriesStyle;
@class SChartDataPoint;
@class ShinobiChart;
@class SChartAnimation;

typedef enum {
    SChartSelectionNone,
    SChartSelectionSeries,
    SChartSelectionPoint
} SChartSelection;

typedef enum {
    SChartSeriesOrientationHorizontal,
    SChartSeriesOrientationVertical
} SChartSeriesOrientation;

/** 
 SChartSeries manages the display of a data series on a `ShinobiChart`.  It contains a set of data points.
 
 There are various things which you can do to configure the behavior and appearance of a chart series:
 
 - A series can optionally use animations when it appears and disappears on the chart.  You can set whether animation should be enabled, and if so, you can configure the animations which the series uses.
 - You can configure whether the series is selectable, and if so, its behavior when it is selected.
 - The series contains instances of `SChartSeriesStyle`, or one of its sub-classes, to manage its appearance.  Tweaking these style objects allows you to change the look of the series on the chart.
 - You can update the representation of the series in the chart legend, and whether the chart crosshair is enabled for the series.
 
 We have created sub-classes of SChartSeries for each of the concrete types of chart series which are available on a chart.  These are:
 
 - `SChartLineSeries` draws data points and connects them, in the order given, using a line.  The display of individual points may be enabled or disabled as required.  Similarly the area fill under the line may be enabled or disabled as required to form __area series__.
 
 <img src="../Images/userguide_lineSeries.png" width=200 alt="Line/Area Series" />
 
 - `SChartScatterSeries` draws data points independently on the chart, with no connections.
 
 <img src="../Images/userguide_scatterSeries.png" width=200 alt="Scatter Series" />
 
 - `SChartBubbleSeries` draws bubbles that are placed at the x and y values of the data. A third property, __Area__, controls the magnitude of the bubble at each point. _Use `SChartBubbleDataPoint` for this series._
 
 <img src="../Images/userguide_bubbleSeries.png" width=100 alt="Bubble Series" />
 
 - `SChartColumnSeries` draws data points as vertical columns on the chart.
 
 <img src="../Images/userguide_columnSeries.png" width=200 alt="Column Series" />
 
 - `SChartBarSeries` draws data points as horizontal bars on the chart.
 
 <img src="../Images/userguide_barSeries.png" width=100 alt="Bar Series" />
 
 - `SChartBandSeries` draws two lines (high and low) and can shade the area between them. ___(Premium Edition only)___.
 
 <img src="../Images/userguide_bandSeries.png" width=200 alt="Band Series" />
 
 - `SChartCandleStickSeries` draws candlestick data points ___(Premium Edition only)___.
 
 <img src="../Images/userguide_candlestickSeries.png" width=200 alt="CandleStick Series" />
 
 - `SChartOHLCSeries` draws Open High Low Close data points ___(Premium Edition only)___.
 
 <img src="../Images/userguide_ohlcSeries.png" width=200 alt="OHLC Series" />
 
 - `SChartStepLineSeries` draws a line chart where the connecting line will only travel in a vertical or horizontal direction to connect the data points.
 
 <img src="../Images/userguide_steplineSeries.png" width=200 alt="Step Line Series" />
 
 - `SChartPieSeries` draws data points as pie slices around a central point.
 
 <img src="../Images/userguide_pieSeries.png" width=100 alt="Pie Series" />
 
 - `SChartDonutSeries` draws data points as donut slices around a central point.
 
 <img src="../Images/userguide_donutSeries.png" width=100 alt="Donut Series" />
 
 
 Series are always drawn in order with the lowest series index first. This means that higher numbered series sit on top and potentially obscure lower numbered series.
 
 More information about using SChartSeries can be found in the [user guide](../../user_guide.html#The%20Chart%27s%20Series).
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartSeries : NSObject <SChartLegendItem>

#pragma mark -
#pragma mark Data and Axis
/** @name Data and Axis setup */

/** `SChartDataSeries` gives you access to the set of data points in the series. 
 
 It contains the data values only, it is not concerned with the appearance of the series on the chart.  The data series is provided to allow you to query the data values in the series, you should not try and use this to modify the series.  If you wish to modify the data in the series, you should update the chart datasource, and then call `[ShinobiChart reloadData]`.
 */
@property (nonatomic, retain) SChartDataSeries *dataSeries;

/** This method returns a string value that will represent the value of a given data point based on its key.
 
 This relies on the data point responding to the appropriate optional method (sChartValueForKey:, sChartXValueForKey: or sChartYValueForKey:).
 
 @param key The key that corresponds to the value needing a string representation.
 @param dataPoint The data point that the value corresponds to.
 @param The axis that the value corresponds to, where `nil` represents an axis independent value.
 @return A string that will be used to represent a value for a data point.*/
- (NSString*) stringForValueWithKey:(NSString*) key withDataPoint:(id<SChartData>) dataPoint usingAxis:(SChartAxis*) axis;

/** This method returns a string value that will represent the key of a given datapoint.
 
 The multi value tooltip uses this method to decide what string to use in its labels for the key of a given datapoint.
 
 @param key The key that needs a string representation.
 @param dataPoint The data point that the key corresponds to.
 @return A string that will be used to represent the given key for a data point.*/
- (NSString*) stringForKey:(NSString*) key withDataPoint:(id<SChartData>) dataPoint;

#pragma mark -
#pragma mark Status
/** @name Status */

/** The orientation of the chart axis which is associated with the series.
 
 It is defined as follows:
 
 - SChartSeriesOrientationHorizontal: Configures the orientation of the chart axis which is associated with the series to be horizontal. Thus the controlled variable will be drawn on the x-axis, while the measured variable will be drawn on the y-axis.
 - SChartSeriesOrientationVertical: Configures the orientation of the chart axis which is associated with the series to be vertical. Thus the  controlled variable will be drawn on the y-axis, while the measured variable will be drawn on the x-axis.
 
 For example, the orientation for column series is SChartSeriesOrientationHorizontal, and the orientation for bar series is SChartSeriesOrientationVertical.
 */
@property (nonatomic, assign) SChartSeriesOrientation orientation;

/** Dictates whether or not a series is hidden on the chart.
 
 If the `hidden` property of a chart series is set to `YES`, then the series will not be drawn on the chart.
 If this property is set to `NO`, the series will be drawn as usual.
 By default, this property is set to `NO`. */
@property (nonatomic)           BOOL    hidden;

#pragma mark -
#pragma mark Data Value Keys
/** Data Value Keys*/

/** Used for data points which contain multiple values (e.g. OHLC data points).  Returns the keys for the x values of the data point.*/
- (NSArray*)xValueKeys;

/** Used for data points which contain multiple values (e.g. OHLC data points).  Returns the keys for the y values of the data point. */
- (NSArray*)yValueKeys;

/** Used for data points which contain values that are independent of axes (e.g. Bubble data points).  Returns the keys for the axis independent values of the data point.*/
- (NSArray *)valueKeys;

/** If the chart ever needs to know about the order in which the value-keys belonging to this series should be used then this method is called for an appropriate comparator.
 
 For example, an SChartCrosshairMultiValueTooltip needs to know the order in which to display its dictionary of key-value pairs.*/
- (NSComparator) comparatorForValueKeys;


#pragma mark -
#pragma mark Animation
/** @name Animation */

/** Whether entry and exit animations are enabled for this series.
 
 If this is set to `YES`, the series will animate in and out using its entryAnimation and exitAnimation animation properties.
 If this is set to `NO`, the series will appear and disappear instantly, with no animation.
 By default, this property is set to `NO` - animation disabled.
 
 @warning Currently, animation is not supported on radial series (SChartRadialLineSeries).
 */
@property (nonatomic)           BOOL    animationEnabled;

/** The animation which describes how the series will enter the chart.

 The chart series will enter when the chart is first drawn, or when its `hidden` property is set to `NO` (having previously been `YES`).
 See `SChartAnimation` for more details.
 */
@property (retain, nonatomic) SChartAnimation *entryAnimation;

/** The animation which describes how the series will exit the chart.
 
 The chart series will exit the chart when its `hidden` property is set to `YES` (having previously been `NO`).
 See `SChartAnimation` for more details.
 */
@property (retain, nonatomic) SChartAnimation *exitAnimation;

#pragma mark -
#pragma mark Selection Options
/** @name Selection Options */

/** Defines what should be selected when the user taps the chart.
 
 This property defines how the series will respond when a tap gesture indicates a point on this series.
 
 The selection modes are defined as follows:
 
 - SChartSelectionNone: Configures this series to select nothing when it is tapped.
 - SChartSelectionPoint: Configures this series to select a point when it is tapped.
 - SChartSelectionSeries: Configures this series to select the series when it is tapped.
 
 There is an important effect of choosing `SChartSelectionNone` - this option will remove this series from the algorithm that searches for the nearest point to the tap.  Hence, a user may tap near to this series - but the algorithm will select a different series based upon its proximity.
 
 @warning Currently selection isn't supported for radial series (SChartRadialLineSeries). Furthermore, selection is handled seperately for pie/donut series - `selectionMode`, `toggleSelection`, and `togglePointSelection` are only applicable to cartesian series.
*/
@property (nonatomic) SChartSelection selectionMode;

/** Dictates whether the chart should allow other series to be selected simultaneously.

 If this is set to `NO`, the chart will de-select all other series before selecting the tapped series. Setting `YES` will allow multiple series to be selected ("toggled") as they are tapped.

 By default, this property is set to `NO`. */
@property (nonatomic) BOOL toggleSelection;

/** Dictates whether the series should only allow only one selected point at a time.

 If this is set to `NO`, the series will de-select all other points in this series before selecting the tapped point. Setting `YES` will allow multiple points to be selected ("toggled") as they are tapped. NOTE: This is _per_ series and will allow multiple points to be selected across series regardless of value. To enable single point selection across all of the series for the chart, use the chart delegate.

 By default, this property is set to `NO`. */
@property (nonatomic) BOOL togglePointSelection;

/** Whether or not the series is selected */
@property (nonatomic, assign) BOOL selected;


#pragma mark -
#pragma mark Crosshair
/** @name Crosshair */

/** Display a tooltip with connecting lines after the user taps-and-holds.
 
 For line series, the tooltip will appear on the nearest series and interpolate values between data points. For column/bar series the crosshair will snap to the nearest column or bar. Once a crosshair is visible it is locked to that current series. It will ignore other series until it is dismissed and re-established on a different series. To dismiss the crosshair the user performs a single tap on the chart. By default, this property is set to `NO`.
 
 @warning Currently, animation is not supported on radial series (SChartRadialLineSeries).
*/
@property (nonatomic) BOOL crosshairEnabled;


#pragma mark -
#pragma mark Styling
/**@name Styling */

/** Manages the appearance of the chart series on the chart.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartSeriesStyle
 */
@property (nonatomic, retain) SChartSeriesStyle *_style;

/** Manages the appearance of the chart series when it is selected.
 
 Style settings in this object will be applied when the series is marked as selected (or a point is selected).
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 
 @see SChartSeriesStyle
 */
@property (nonatomic, retain) SChartSeriesStyle *_selectedStyle;


#pragma mark -
#pragma mark Legend Display Options

/** @name Legend Display Options */

/** The title of the series to be displayed in the legend. */
@property (nonatomic, retain) NSString *title;

/** Whether or not the series should be represented in the legend 
 
 By default, this property is set to `YES`. */
@property (nonatomic, assign) BOOL showInLegend;

/** The object responsible for providing the title and `SChartLegendSymbol` item for representing this symbol in the legend.
 
 By default, this property is set to the series itself. */
@property (nonatomic, assign) id<SChartLegendItem> legendItem;


#pragma mark -
#pragma mark Drawing

/** @name Drawing */

/** DEPRECATED - Use the `hidden` property instead. 
 
 Whether or not the series should be drawn on the chart.*/
- (BOOL)shouldBeDrawn DEPRECATED_ATTRIBUTE;

/** Returns, in data terms, the x component of the point upon which the datapoint at the given index is centered. 
 
 @warning Currently, this method is not supported on radial series (SChartRadialLineSeries).
 */
- (id)centreXOfDataPointAtIndex:(NSInteger)index onChart:(ShinobiChart *)chart;

/** Returns, in data terms, the y component of the point upon which the datapoint at the given index is centered. 
 
  @warning Currently, this method is not supported on radial series (SChartRadialLineSeries).
 */
- (id)centreYOfDataPointAtIndex:(NSInteger)index onChart:(ShinobiChart *)chart;

/** Returns the width, in data terms, of the datapoint at the given index. 
 
  @warning Currently, this method is not supported on radial series (SChartRadialLineSeries).
 */
- (id)widthOfDataPointAtIndex:(NSInteger)index onChart:(ShinobiChart *)chart;

/** Returns the width, in data terms, of the datapoint at the given index. 
 
  @warning Currently, this method is not supported on radial series (SChartRadialLineSeries).
 */
- (id)heightOfDataPointAtIndex:(NSInteger)index onChart:(ShinobiChart *)chart;

#pragma mark -
#pragma mark Subclassing
/**@name Subclassing */

/** Resets the chart series for reuse when the data in the chart is reloaded. 
 
 By default, this clears the data points in the chart series, while leaving the styling, animation and any other series properties intact. If you subclass SChartSeries, you should add any custom implementation you require to the subclass.
 */
- (void)resetForReuse;

#pragma mark -
#pragma mark Data Bins
/**@name Data Bins */

/** The number of datapoints that are rendered in a single pass.
 As render passes are expensive, this defaults to the number of
 datapoints in this series (this is only populated after a data load).

 Note that if your use-cases makes heavy use of appending and/or removing
 datapoints, then you may want to lower this, so a smaller "bin" /
 fewer datapoints need to be re-rendered per append/remove.
 */
@property (nonatomic, retain) NSNumber *numberOfDataPointsPerBin;

@end
