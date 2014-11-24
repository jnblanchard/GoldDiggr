//
//  SChartDelegate.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ShinobiChart;
@class SChartSeries;
@class SChartDataPoint;
@class SChartRadialDataPoint;
@class SChartRadialSeries;
@class SChartTickMark;
@class SChartAnimation;
@class SChartAxis;
@class SChartDataPointLabel;

/**
 SChartMovementInformation describes why a chart is triggering pan and zoom delegate methods.
 
 Currently it contains one member - movementIsMomentum. This is true if the chart is panning due to momentum.
 */
typedef struct SChartMovementInformation
{
    int movementIsMomentum : 1;
} SChartMovementInformation;

/**
 The delegate of a `ShinobiChart` object must adopt the `SChartDelegate` protocol.  Optional methods of the protocol allow the delegate to respond to the following types of events:
 
 - Zooming.
 - Panning.
 - Selection on the chart.
 - Chart rendering.
 - Data loading.
 - Chart series animations.
 - Crosshair tracking.
 
 As well as methods to respond to events on the chart, the protocol also provides methods to allow the delegate to manage the chart axes, by altering tick marks on the axes, or by setting tick frequencies.
 
 More information about how to use the SChartDelegate can be found in the [user guide](../../user_guide.html#The%20Delegate).
 
 @sa ChartsUserGuide
 @available Standard
 @available Premium
 */
@protocol SChartDelegate <NSObject>
#pragma mark -
#pragma mark REQUIRED
@required

#pragma mark -
#pragma mark OPTIONAL
@optional
#pragma mark -
#pragma mark Zooming
/** @name Responding to zoom events */

/** A notification that the chart object has started a zoom operation.
 
 This method is called once at the start of a zoom gesture by the user. Each axis maintains its own zoom level, which is available through the [SChartAxis zoom] property. To monitor the progress of the zoom gesture as it happens, implement the method sChartIsZooming:.
 
 @param chart The chart which is zooming.
 */
- (void)sChartDidStartZooming:(ShinobiChart *)chart;

/** A notification that the chart object has finished a zoom operation.
 
 The resulting zoom level is available for each axis object, via the [SChartAxis zoom] property. 
 
 @param chart The chart which finished zooming.
 */
- (void)sChartDidFinishZooming:(ShinobiChart *)chart;

/** A notification that the chart object has reset the zoom level.
 
 The zoom level on an axis can be reset to the _default range_. Implement this method to be notified when the chart has reset to the default zoom level. 
 
 @param chart The chart which reset its zoom to the default level.
 */
- (void)sChartDidResetZoom:(ShinobiChart *)chart;

/** A notification that the chart object is zooming.
 
 This method will be continually called during a zoom operation and is particularly useful to keep multiple charts synchronised. The current zoom level is available on the axis object, and other charts may be programatically zoomed to respond. 
 
 @param chart The chart which is zooming.
 */
- (void)sChartIsZooming:(ShinobiChart *)chart;

/** A notification that the chart object is zooming, with additional data.
 
 This method is similar to sChartIsZooming:, however extra data describing the zoom is given as an argument.  The other difference is that this method is called during deceleration, if an axis has momentum zooming enabled.  sChartIsZooming: is not. 
 
 @param chart The chart which is zooming.
 @param information Extra information describing the zoom.
 */
- (void)sChartIsZooming:(ShinobiChart *)chart withChartMovementInformation:(const SChartMovementInformation *)information;

/** A notification that the chart has adjusted its zoom level using the box feature. 
 
 The box gesture can be enabled on the chart by setting [ShinobiChart gesturePanType] to `SChartGesturePanTypeBoxDraw`.  In this case, panning on the chart will cause a box to be drawn on the chart.  When the user finishes panning, the chart zooms to the limits of the box.
 
 @param chart The chart which is zooming.
 @see ShinobiChart
 */
- (void)sChartDidBoxZoom:(ShinobiChart *)chart;

#pragma mark -
#pragma mark Panning
/** @name Responding to panning events */

/** A notification that the chart object has started a panning operation.
 
 @param chart The chart which has started panning.
 */
- (void)sChartDidStartPanning:(ShinobiChart *)chart;

/** A notification that the chart object has finished a panning operation.
 
 After a pan operation, the axis will have a new range available, which you can query via the [SChartAxis axisRange] property.
 @param chart The chart which finished panning.
 */
- (void)sChartDidFinishPanning:(ShinobiChart *)chart;

/** A notification that the chart object is panning.
 
 The range for each axis is updated as the user pans the chart.  You can query the axis range via the [SChartAxis axisRange] property.
 
 This method is called continually during the pan gesture.
 
 @param chart The chart which is panning.
 */
- (void)sChartIsPanning:(ShinobiChart *)chart;

/** A notification that the chart object is panning, with additional data.
 
 This method is similar to sChartIsPanning:, however extra data describing the pan is given as an argument. 
 
 @see sChartIsPanning:
 @param chart The chart which is panning.
 @param information Extra information regarding the pan.
 */
- (void)sChartIsPanning:(ShinobiChart *)chart withChartMovementInformation:(const SChartMovementInformation *)information;

/** A notification that we have started panning on a pie/donut series.
 
 @param radial The chart containing the pie/donut series which has started panning.
 @param radialSeries The pie/donut series being panned.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)radial radialSeriesDidStartPanning: (SChartRadialSeries *)radialSeries;

/** A notification that a pie/donut series is being panned.
 
 The rotation of the series is updated as the user pans the chart.  You can query the current rotation of the series using the [SChartDonutSeries rotation] property.
 
 @param radial The chart containing the pie/donut series.
 @param radialSeries The pie/donut series being panned.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)radial radialSeriesIsPanning: (SChartRadialSeries *)radialSeries;

/** A notification that a panning gesture on a pie/donut series has ended, and the series will begin to decelerate.
 
 @param chart The chart containing the pie/donut series.
 @param radialSeries The pie/donut series which has started to decelerate.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart radialSeriesWillBeginDecelerating:(SChartRadialSeries *)radialSeries;

/** A notification that a pie/donut series has come to a halt after being panned and released.
 
 @param chart The chart containing the pie/donut series.
 @param radialSeries The pie/donut series which has finished panning.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart radialSeriesDidEndDecelerating:(SChartRadialSeries *)radialSeries;

#pragma mark -
#pragma mark Touch Gestures
/** @name Responding to touch events */

/** A notification that a series has been selected or de-selected.
 
 A touch gesture has resulted in the `selected` property of the series changing. The nearest data point is passed into the method along with the current pixel coordinates of that point.  
 
 @param chart The chart on which the selection has occurred.
 @param series The series which has been selected or de-selected.
 @param dataPoint The nearest data point on that series to the point on the screen which was touched.
 @param pixelPoint The pixel coordinates of that data point.
 */
- (void)sChart:(ShinobiChart *)chart toggledSelectionForSeries:(SChartSeries *)series nearPoint:(SChartDataPoint *)dataPoint
atPixelCoordinate:(CGPoint)pixelPoint;

/** A notification that a data point has been selected or de-selected.
 
 A touch gesture has resulted in the `selected` property of the data point changing. The data point is passed into the method along with the current pixel coordinates of that point and the series that it belongs to.  
 
 @param chart The chart on which the selection has occurred.
 @param dataPoint The data point which was selected or de-selected.
 @param series The chart series which contains that data point.
 @param pixelPoint The pixel coordinates of that data point.
 */
- (void)sChart:(ShinobiChart *)chart toggledSelectionForPoint:(SChartDataPoint *)dataPoint inSeries:(SChartSeries *)series
atPixelCoordinate:(CGPoint)pixelPoint;

/** A notification that a data point on a pie/donut chart has changed state to 'selected' from 'deselected' or vice versa.
 
 The`selected` property of the data point has changed. This could be as a result of a tap gesture on the chart, or of programmatically selecting the point (`setSlice:asSelected`). The data point is returned along with the series that it belongs to and the pixel coordinates of the tap, if any.  

 @param chart The chart on which the selection occurred.
 @param dataPoint The data point which was selected or de-selected.
 @param series The pie/donut series which contains the data point.
 @param pixelPoint The pixel coordinate of the data point.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
*/
- (void)sChart:(ShinobiChart *)chart toggledSelectionForRadialPoint:(SChartRadialDataPoint *)dataPoint inSeries:(SChartRadialSeries *)series
atPixelCoordinate:(CGPoint)pixelPoint;

#pragma mark -
#pragma mark Crosshair
/** @name Tracking the crosshair */

/** Notifies the user when the crosshair moves.
 
 When the crosshair is panned, the new values at the crosshair point are passed into this method. For a line series, the values will be interpolated if they lie between actual data points. On a category axis - or bar/column series - the crosshair will snap to the discrete values. 
 
 @param chart The chart containing the crosshair.
 @param x The x value of the current crosshair position.
 @param y The y value of the current crosshair position.
 */
- (void)sChart:(ShinobiChart *)chart crosshairMovedToXValue:(id)x andYValue:(id)y;

#pragma mark -
#pragma mark Rendering
/** @name Chart Rendering */

/** A notification that the chart object has started rendering.
 
 This is called before the chart starts rendering its data. At this point, the chart axes will be up to date with your data, so a common use case of this method would be to update the chart axes before they are rendered, for example to modify the axis title or range.
 
 @param chart The chart which has started rendering.
 @param fullRedraw If the chart is carrying out a full redraw, this argument is set to `YES`.
 */
- (void)sChartRenderStarted:(ShinobiChart *)chart withFullRedraw:(BOOL)fullRedraw;

/** A notification that the chart object has finished rendering.
 
 This is called once the chart has finished rendering its data. A common use case for this method would be to display the crosshair on the chart after it has rendered, or to add annotations onto the chart. You could also update other UI elements in your application so that they reflect the new state of the chart. You shouldn’t modify the chart plot area or its axes here, as any changes won’t be visualized until the next time that the chart is rendered.
 
 @param chart The chart which has finished rendering.
 */
- (void)sChartRenderFinished:(ShinobiChart *)chart;

#pragma mark -
#pragma mark Tick Marks
/** @name Tick Marks */

/** Alter a tick mark before it is added to an axis on the chart.
 
 This method gives you each tick mark just before it is added to its axis. Use this to set colors, borders, or even move the tickmark's label elsewhere.
 
 @param chart The chart containing the tick marks.
 @param tickMark The tick mark which will be added to its axis.
 @param axis The axis on the chart to which the tick mark will be added.
 */
-(void)sChart:(ShinobiChart *)chart alterTickMark:(SChartTickMark *)tickMark beforeAddingToAxis:(SChartAxis *)axis;

/** Assist the chart in calculating tick label lengths. This is useful when you provide an implementation for sChart:alterTickMark:beforeAddingToAxis:
 
 For example, if you lengthen the tick label strings in alterTickMark, you should hint to the axis that extra room will be required by implementing this method.
 
 The actual contents of this string are ignored, only its size with the current tick-label font is used.
 For example, if you are using a currency format, a string like @"$#.##" will ensure sufficient room is calculated.
 Return nil for the chart to use automatically calculated values for the tick label lengths.
 
 @param chart The chart containing the axis.
 @param axis The axis for which we are returning the longest tick label string.
 @return A string of the right size, from which the axis can deduce the maximum amount of space that tick mark labels will require.
 */
-(NSString *)sChart:(ShinobiChart *)chart longestLabelStringOnAxis:(SChartAxis *)axis;

/** Alter a pie/donut label before it is added to the chart.
 
 This method gives you each label for each pie/donut series before it is added to the chart. Use this to set colors, borders, or reposition the label.
 
 More information about using this method can be found in our tutorial ['Pie chart labels that are out of this... slice'](http://www.shinobicontrols.com/blog/posts/2012/08/06/pie-chart-labels-that-are-out-of-this-slice).
 
 @param chart The chart containing the pie/donut label.
 @param label The pie/donut label being added to the chart.
 @param datapoint The data point on the chart to which the label applies.
 @param index The index of the data point in its pie/donut series.
 @param series The pie/donut series containing the data point.
 
 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart alterLabel:(UILabel *)label forDatapoint:(SChartRadialDataPoint *)datapoint atSliceIndex:(NSInteger)index inRadialSeries:(SChartRadialSeries *)series;

/** Set the major and minor tick frequencies for an axis.
 
 Implement this method to customize your major and minor tick frequencies depending on the state of the axis.
 
 Set the majorTickFrequency and minorTickFrequency pointers to objects of your choosing.
 
 Not setting the minorTickFrequency, or setting it to nil, will result in minor ticks not being displayed.
 You should set frequencies of the correct type to match the axis - for example, SChartDateFrequency for SChartDateTimeAxis, or NSNumber for SChartNumberAxis.
 
 @param chart The chart containing the axis.
 @param majorTickFrequency A pointer to the major tick frequency on the axis.  If you set this value, the axis will update to use the new value.
 @param minorTickFrequency A pointer to the minor tick frequency on the axis.  If you set this value, the axis will update to use the new value.
 @param axis The axis for which we are setting the tick frequencies.
 */
-(void)sChart:(ShinobiChart *)chart setMajorTickFrequency:(id * const)majorTickFrequency andMinorTickFrequency:(id * const)minorTickFrequency onGeneratingTickMarksforAxis:(SChartAxis *)axis;

#pragma mark - Data point labels
/* @name Data point labels */

/** Alter a data point label before it is added to the chart.
 
 This method gives you each data point label for each series before it is added to the chart. Use this to set colors, borders, or reposition the label.
 
 @param chart The chart containing the label.
 @param label The label being added to the chart.
 @param datapoint The data point on the chart to which the label applies.
 @param series The series containing the data point.
 */
-(void)sChart:(ShinobiChart *)chart alterDataPointLabel:(SChartDataPointLabel*)label forDataPoint:(SChartDataPoint *)dataPoint inSeries:(SChartSeries *)series;

#pragma mark -
#pragma mark Animation
/** @name Animation */

/** A notification that an animation of a chart series has ended.
 
 Note that this callback will still be called should one animation be interrupted by another and the series continues to be animated by the second animation.
 
 @param series The chart series which has finished animating.
 @param animation The animation which finished.
 */
-(void)sChartSeries:(SChartSeries *)series animationDidFinish: (SChartAnimation *)animation;


#pragma mark -
#pragma mark Data Loading
/** @name Data Loading */

/** A notification that the chart will start loading its data.
 
 At this point, the chart has been created, but it either doesn’t contain any data, or it is about to reload its data. You shouldn’t do anything with chart axes at this point, as they will be out of date with the new data. A common use case for this method would be to pop up an activity indicator if you think the data will take a long time to load.
 
 @param chart The chart which started loading its data.
 */
-(void)sChartWillStartLoadingData:(ShinobiChart *)chart;

/** A notification that the chart has finished loading its data.
 
 This is called once the chart has finished loading its data, and before it starts rendering its plot area and axes. A common use of this method would be to close the activity indicator if you popped one up during loading. At this point, the chart axes will have been refreshed from the new data, so you could update the chart axes here before they are rendered. It is important to note that this method is only called when we load data, rather than each time the chart is rendered.
 
 @param chart The chart which finished loading its data.
 */
-(void)sChartDidFinishLoadingData:(ShinobiChart *)chart;



@end

