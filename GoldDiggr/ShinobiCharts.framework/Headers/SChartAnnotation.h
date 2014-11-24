//
//  SChartAnnotation.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SChartAxis;
@class SChartCanvas;
@class SChartAnnotationZooming;

typedef enum {
    SChartAnnotationAboveData,
    SChartAnnotationBelowData,
} SChartAnnotationPosition;

/** An `SChartAnnotation` is a UIView that can be displayed on a chart - maintaining aspect ratio at all times and position in accordance with the panning of the data range (see below). 
 
 <img src="../Images/api_annotations.png" width=400/>
 
 There are several predefined annotations for convenience - these can be created using the methods below and are bands, lines and text.
 
 An `SChartAnnotation` is fixed to a single point on the chart which means that it will pan but will remain a fixed size regardless of zoom level. If you would like to annotate an area that will scale as the data range is zoomed use `SChartAnnotationZooming`, which is anchored between two limits on either axis.
 
 An annotation can be attached to one of the x axes, and one of the y-axes in the chart.  This is done using the `xAxis` and `yAxis` properties on the annotation.  If an annotation is attached to an axis, the position of the annotation on the chart will correspond to its value on that axis.  The position of the annotation on the x axis will correspond to `xValue` and its position on the y axis will correspond to `yValue`.
 
 More information about using SChartAnnotation can be found in the [user guide](../../user_guide.html#Annotations)
 
@warning This feature isn't currently supported on radial charts.

 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartAnnotation : UIView

#pragma mark -
#pragma mark Positioning the annotation
/** @name Positioning the annotation */

/** The x axis that the annotation is attached to.
 
 A `nil` value will cause the view to be displayed at the midpoint of the width of the chart plot area. */
@property (nonatomic, assign) SChartAxis *xAxis;

/** The y axis that the annotation is attached to.
 
 A `nil` value will cause the view to be displayed at the midpoint of the height of the chart plot area. */
@property (nonatomic, assign) SChartAxis *yAxis;

/** The value on the given `xAxis` that the annotation is going to be anchored to. 
 
 A `nil` value will cause the view to be displayed at the midpoint of the width of the chart plot area. */
@property (nonatomic, retain) id xValue;

/** The value on the given `yAxis` that the annotation is going to be anchored to.
 
 A `nil` value will cause the view to be displayed at the midpoint of the height of the chart plot area. */
@property (nonatomic, retain) id yValue;

/** If this is a text annotation, this property is an accessor for the text label. Otherwise it returns `nil`. */
@property (nonatomic, retain) UILabel *label;

/** Sets how annotations should be drawn relative to your chart data.
 
 - SChartAnnotationAboveData: Configures the annotation to be drawn in front of your chart data.
 - SChartAnnotationBelowData: Configures the annotation to be drawn underneath your chart data.
 
 In most cases, we will want the annotation to be drawn in front of the chart data, and so by default this is set to `SChartAnnotationAboveData`.
 */
@property (nonatomic) SChartAnnotationPosition position;

#pragma mark -
#pragma mark Factory methods
/** @name Creating standard pre-defined annotations */

/** Creates an annotation based on a UILabel with the given string at the given x and y axis positions. */
+(SChartAnnotation *)annotationWithText:(NSString *)text 
                                andFont:(UIFont *)font
                              withXAxis:(SChartAxis *)xAxis 
                               andYAxis:(SChartAxis *)yAxis 
                            atXPosition:(id)xValue 
                           andYPosition:(id)yValue 
                          withTextColor:(UIColor *)textColor
                    withBackgroundColor:(UIColor *)backgroundColor;

/** Creates a vertical line at the given x position that spans the whole height of the y axis. */
+(SChartAnnotationZooming *)verticalLineAtPosition:(id)xValue 
                                         withXAxis:(SChartAxis *)xAxis 
                                          andYAxis:(SChartAxis *)yAxis 
                                         withWidth:(float)width 
                                         withColor:(UIColor *)color;

/** Creates a horizontal line at the given y position that spans the whole width of the x axis. */
+(SChartAnnotationZooming *)horizontalLineAtPosition:(id)yValue 
                                           withXAxis:(SChartAxis *)xAxis 
                                            andYAxis:(SChartAxis *)yAxis 
                                           withWidth:(float)width 
                                           withColor:(UIColor *)color;

/** Creates a vertical band that spans the given range on the x axis and spans the whole height of the y axis. */
+(SChartAnnotationZooming *)verticalBandAtPosition:(id)minX 
                                           andMaxX:(id)maxX 
                                         withXAxis:(SChartAxis *)xAxis 
                                          andYAxis:(SChartAxis *)yAxis 
                                         withColor:(UIColor *)color;

/** Creates a horizontal band that spans the given range on the y axis and spans the whole width of the x axis. */
+(SChartAnnotationZooming *)horizontalBandAtPosition:(id)minY 
                                             andMaxY:(id)maxY 
                                           withXAxis:(SChartAxis *)xAxis 
                                            andYAxis:(SChartAxis *)yAxis 
                                           withColor:(UIColor *)color;

#pragma mark -
#pragma mark Drawing the annotation
/** @name Drawing the annotation */

/** Updates the annotation on the chart.
 
 Override this method to provide custom updating of the annotation while it is being positioned on the chart. */
-(void)updateViewWithCanvas:(SChartCanvas *)canvas;

@end


#pragma mark -
#pragma mark Zooming annotation

/** An `SChartAnnotationZooming` object is pinned between two points on each axis in the chart and will scale according to the current range of the axis.  It is pinned between `xValue` and `xValueMax` on the x axis, and `yValue` and `yValueMax` on the y axis.
 
 This kind of annotation is useful for highlighting areas of data, etc. As we zoom in on a range of data, the zooming annotation will also zoom so that it covers the same range of data on the chart axes.  Due to this, it will not maintain its aspect ratio as the chart is zoomed.
 
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartAnnotationZooming : SChartAnnotation

#pragma mark -
#pragma mark Positioning and zooming
/** @name Positioning and zooming */

/** The upper limit of the annotation on the x axis.
 
 A `nil` value will cause the view to be displayed with its original width. */
@property (nonatomic, retain) id xValueMax;

/** The upper limit of the annotation on the y axis.
 
 A `nil` value will cause the view to be displayed with its original height. */
@property (nonatomic, retain) id yValueMax;

/** Causes the annotation to be stretched to cover the whole width of the chart plot area.
 
 This defaults to `NO`. */
@property (nonatomic) BOOL stretchToBoundsOnX;

/** Causes the annotation to be stretched to cover the whole height of the chart plot area. 
 
 This defaults to `NO`. */
@property (nonatomic) BOOL stretchToBoundsOnY;

#pragma mark -
#pragma mark Drawing the annotation
/** @name Drawing the annotation */

/** Positions the annotation on the chart plot area and zooms according to the axis ranges. 
 
 Override this method to provide custom updating of the annotation while it is being positioned on the chart. */
-(void)updateViewWithCanvas:(SChartCanvas *)canvas;

@end
