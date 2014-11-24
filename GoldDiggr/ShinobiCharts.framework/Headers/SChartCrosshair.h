//
//  SChartCrosshair.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ShinobiChart;
@class SChartSeries;
@class SChartMappedSeries;
@class SChartCrosshairStyle;
@class SChartCrosshairTooltip;
@protocol SChartData;

typedef enum {
    SChartCrosshairModeSingleSeries,
    SChartCrosshairModeFloating
} SChartCrosshairMode;

typedef enum {
    SChartCrosshairOutOfRangeBehaviorKeepAtEdge,
    SChartCrosshairOutOfRangeBehaviorHide,
    SChartCrosshairOutOfRangeBehaviorRemove,
} SChartCrosshairOutOfRangeBehavior;


/** The SChartCrosshair provides a small circle target with lines that extend to the axis. This is accompanied by a tooltip object - nominally a UIView.  The default implementation for the tooltip is provided by `SChartCrosshairTooltip`.  For data points with multiple values at a single point, another implementation, `SChartCrosshairMultiValueTooltip`, has also been provided.
 
  <img src="../Images/api_crosshair.png" width=400/>
 
 The crosshair is enabled with a _tap-and-hold gesture_ and will lock to the nearest series to pan through the values. On a line series the values will be interpolated between data points, on all other series types the crosshair will jump from data point to data point. Note that line series interpolation can be switched off by setting `interpolatePoints` to `NO`.
 
 In order for a crosshair to be displayed on a chart series, the series must have its `[SChartSeries crosshairEnabled]` property set to `YES`.  This defaults to `NO`, so you will need to set this property on the series in your chart.
 
 More information about using SChartCrosshair can be found in the [user guide](../../user_guide.html#Crosshair), and in our tutorials ['Customizing that Crosshair'](http://www.shinobicontrols.com/blog/posts/2012/07/19/customizing-that-crosshair) and ['Data streaming, crosshairs and custom tooltips in ShinobiCharts'](http://www.shinobicontrols.com/blog/posts/2013/12/04/data-streaming,-crosshairs-and-custom-tooltips-in-shinobicharts).
 
 @available Standard
 @available Premium
 @sample BarChart
 @sample LineChart
 
 @warning Crosshairs are not currently supported on radial charts.
 */
@interface SChartCrosshair : UIView

#pragma mark -
#pragma mark Initialization
/** @name Initialization */

/** Initializes and returns a newly allocated crosshair object, which is associated with the specified chart. */
-(id)initWithChart:(ShinobiChart *)parentChart;

/* DEPRECATED - Use initWithChart: instead. */
-(id)initWithFrame:(CGRect)frame usingChart:(ShinobiChart *)parentChart DEPRECATED_ATTRIBUTE;

/** Configures the crosshair to track a particular series on the chart.
 
 If this property isn't set, the crosshair will lock to the nearest series on the chart when it is drawn.
 @warning The class of this property has been changed from `SChartCartesianSeries` to `SChartMappedSeries`.
 */
@property (nonatomic, retain) SChartMappedSeries *trackingSeries;

/** Configures the crosshair to track a particular data point on the chart.
 
 If this property isn't set, the crosshair will lock to the nearest data point on the nearest series in the chart when it is drawn. 
 */
@property (nonatomic, assign) SChartPoint            trackingPoint;

/** The crosshair holds a reference to the chart which contains it. */
@property (nonatomic, assign) ShinobiChart *chart;

#pragma mark -
#pragma mark Style
/** @name Style */

/** The `SChartCrosshairStyle` object manages the look of the crosshair. 
 
 The default style for the crosshair is defined in the chart theme.  If you wish to modify the look of the crosshair later on, you can set the properties on this object to achieve the desired look.
 */
@property (nonatomic, retain) SChartCrosshairStyle *style;

#pragma mark -
#pragma mark Tooltip
/** @name Tooltip */

/** The tooltip which presents the current data values to the user.
 
 By default, this will be an instance of `SChartCrosshairTooltip`.  You can also override this class to present the crosshair data in a custom way.
*/
@property (nonatomic, retain) SChartCrosshairTooltip *tooltip;

#pragma mark -
#pragma mark Customization
/** @name Customization */

/** When set to `YES` the lines from the target point to the axis will be displayed. 
 
 By default, this property is set to `YES`. */
@property (nonatomic)         BOOL    enableCrosshairLines;

/* DEPRECATED - This should be taken off the API in future releases.  It is used internally, but should not be set from outside of the class. */
@property (nonatomic)         BOOL    enableCrosshairLinesSet;

/** Returns `YES` if the crosshair should draw its tracking lines to the specified point, given the specified frame.
 
 This defaults to a simple bounds check - whether the point is inside the frame.
 */
- (BOOL) shouldDrawCrosshairLinesForPoint:(CGPoint)point inFrame:(CGRect)frame;

/** Defines the behavior of the crosshair when it goes out of range.
 
 The crosshair has different behaviors for when it goes out of range. In this context, "out of range" refers to the case when a series goes off the screen - i.e. it is out of range on one axis, but not the other.
 
 - SChartCrosshairRangeBehaviorKeepAtEdge: Configures the crosshair to move along the edge of the canvas until the series comes back into range
 - SChartCrosshairRangeBehaviorHide: Configures the crosshair to hide, but continue to track the series until it comes back in range.
 - SChartCrosshairRangeBehaviorRemove: Configures the crosshair to remove itself entirely, leaving the chart open for panning or tracking a new series.
 
 By default, the crosshair is set to `SChartCrosshairRangeBehaviorHide`. */
@property (nonatomic)         SChartCrosshairOutOfRangeBehavior outOfRangeBehavior;

/** If set to `YES` the crosshair will move smoothly between points when tracking a line series.
 
 Otherwise the crosshair will jump from point to point as it tracks.
 
 By default, this property is set to `YES`. */
@property (nonatomic)         BOOL      interpolatePoints;

/* DEPRECATED - This property will be taken off the API in future releases.
 
 By default, this property is set to `UIViewAnimationOptionCurveEaseOut`. */
@property (nonatomic)         UIViewAnimationOptions animationOptions;

/* DEPRECATED - This property will be taken off the API in future releases. 
 
 By default, this property is set to `0.2`. */
@property (nonatomic)         CGFloat animationDuration;

/* DEPRECATED - This property will be taken off the API in future releases. 
 
 By default, this property is set to `0.2`. */
@property (nonatomic)         CGFloat animationDelay;

/* DEPRECATED - This property will be taken off the API in future releases. */
@property (nonatomic)         BOOL animationEnabled;

/** Displays the crosshair (with lines and tooltip) on the chart.
 
 This method is called by the chart when the crosshair should be displayed. Override this method to control the display of the crosshair in subclasses. */
-(void)showCrosshair;

/** Hides the crosshair (with lines and tooltip) on the chart.
 
 This method is called by the chart when the crosshair should be dismissed. Override this method to control the display of the crosshair in subclasses. */
-(BOOL)removeCrosshair;

/** Performs the drawing of the lines and the target circle element of the crosshair.
 
 Override this function to provide custom lines or other drawn elements. */
-(void)drawCrosshairLines;

/** Sets the current tooltip element of the crosshair to be an instance of the default base-class - `SChartCrosshairTooltip`. */
-(void)setDefaultTooltip;

/** This describes whether the crosshair is in floating mode or not.
 
 The mode is defined with the following options:
 
 - SChartCrosshairModeSingleSeries: Configures the crosshair to lock to a single series, and display on the closest data point in that series only.
 - SChartCrosshairModeFloating: Configures the crosshair to display on the closest data point.
 */
@property(nonatomic) SChartCrosshairMode mode;

#pragma mark -
#pragma mark Event notifications
/** @name Event notifications */

/** This method is called when the crosshair moves out of the visible range of the chart. 
 
 The behaviour of the crosshair at this point is defined by its `mode` property.
 */
-(void)crosshairMovedOutOfRange;

/** This method is called when the crosshair moves while inside the visible range of the chart. */
-(void)crosshairMovedInsideRange;

/** Returns whether the crosshair should keep tracking. If this is the case, the crosshair should provide a series to track, using its `trackingSeries` property. 
 */
-(BOOL)crosshairShouldKeepTracking;

/** This method informs the crosshair that a gesture was performed which failed to select any series. 
 
 The default behavior in this case is to remove the crosshair. */
-(void)crosshairTrackingFailed;

/** This method informs the crosshair that there was a pinch/pan gesture on the chart. 
 
 The default behavior in this case is to remove the crosshair. */
-(void)crosshairChartGotPinchAndPan;

/** This method is informs the crosshair that there was a tap gesture on the chart at a point. 
 
 The default behavior in this case is to remove the crosshair.
 
 @param tap The point on the chart which was tapped.
 */
-(void)crosshairChartGotTapAt:(CGPoint)tap;

/** This method informs the crosshair that there was a long press gesture on the chart at a point.
 
 The default behavior of the crosshair is to do nothing.  If you wish to do something with the crosshair on receiving this event, you can subclass SChartCrosshair, and override this method.
 
 @param longpress The point on the chart where the long press occurred.
 */
-(void)crosshairChartGotLongPressAt:(CGPoint)longpress;

/** Notifies the crosshair that its parent chart reloaded its data.
 
 The default behavior in this case is to remove the crosshair. */
-(void)chartDidReload;

#pragma mark -
#pragma mark Moving the crosshair
/** @name Moving the crosshair */

/** This method is called when the crosshair changes position.
 
 @param coords The location on the chart where the crosshair should appear, in points.
 @param dataPoint The crosshair tooltip will display the value of this data point.  This can either be an interpolated point, or the nearest actual point on the series, depending on the configuration of the crosshair.
 @param series The series on the chart which the crosshair is locked to.
 @param dataseriesPoint This parameter is used by `SChartCrosshairMultiValueTooltip`.  In this case, the tooltip will display the values contained in this point rather than the value of dataPoint.  For other types of tooltip, this parameter is ignored.
 @warning The 'series' parameter has been changed from class `SChartCartesianSeries` to `SChartMappedSeries`.
 */
-(void)moveToPosition:(SChartPoint)coords andDisplayDataPoint:(SChartPoint)dataPoint fromSeries:(SChartMappedSeries *)series andSeriesDataPoint:(id<SChartData>)dataseriesPoint;

/** Moves the crosshair to the specified pixel coordinates. 
 
 @param floatingCoords The pixel coordinates to which to move the crosshair.
 */
-(void)moveToFloatingPixelPosition:(CGPoint)floatingCoords;

/** Moves the crosshair to the coordinates on the chart corresponding to the specified data point relative to the specified axes.
 
 @param point The data point to which to move the crosshair.
 @param xAxis The x axis with which the data point is associated.  The x value of the data point will be mapped to this axis.
 @param yAxis The y axis with which the data point is associated.  The y value of the data point will be mapped to this axis.
 */
- (void)moveToFloatingPosition:(SChartPoint)point onXAxis:(SChartAxis *)xAxis onYAxis:(SChartAxis *)yAxis;

@end
