//
//  SChartCanvas.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SChartGLView;
@class SChartCanvasOverlay;
@class SChartCanvasUnderlay;
@class SChartCanvasRenderView;
@class ShinobiChart;

/**
 For each ShinobiChart, one single SChartCanvas will exist to contain the drawing of all of the axes and series. Titles, legends and other chart level objects appear outside of this area in the ShinobiChart view. The canvas is responsible for managing the layers that make up the axis and series.
 
 The canvas itself has no objects drawn directly onto it. The canvas decides how much space it will need to draw any axis and their labels. The plot area view is then sized and laid down to draw the series. This is followed by the SChartCanvasOverlay layer that is used to draw the axes at the highest level.
 
 You should never need to modify this object directly.  We've included information on this class as we refer to the chart canvas at various points in our documentation.
 
 @available Standard
 @available Premium
 @see ChartsUserGuide
*/
@interface SChartCanvas : UIView

/** The chart which contains this canvas */
@property (nonatomic, assign) ShinobiChart *chart;

#pragma mark -
#pragma mark Initializing the canvas
/** @name Initializing the canvas */

/* DEPRECATED - This should be moved into a private header.
 
 Initializes and returns a newly allocated canvas object with the specified frame rectangle.
 @param frame The frame rectangle for the canvas, measured in points.
 @param parentChart The chart which will contain the new canvas.
 @return An initialized canvas object, or `nil` if the object couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame usingChart:(ShinobiChart *)parentChart;

#pragma mark -
#pragma mark Gestures
/** @name Gestures */

/* DEPRECATED - This should be moved into a private header.
 
 Sets whether panning is enabled on the chart canvas.
 @param enable If set to `YES`, panning will be enabled on the canvas.
 */
-(void) enablePanning:(BOOL)enable;

#pragma mark -
#pragma mark Managing our drawing objects
/** @name Managing our drawing objects */

/** The underlay is the layer upon which we draw all of our axes. 
 
 We use pixel based coordinates on the underlay.
 */
@property (nonatomic, retain) SChartCanvasUnderlay* underlay;

/** This is the layer where we draw all of our annotation views that are visualised under our data */
@property (nonatomic, retain) UIView* underlayForAnnotations;

/** This is the layer upon which we draw all of our chart series and also any chart annotations.
 
 This layer is rendered using openGL and therefore uses GL based coordinates. */
@property (nonatomic, retain) SChartGLView *glView;

/** This is the layer where we render things like the crosshair. */
@property (nonatomic, retain) SChartCanvasOverlay* overlay;

/* DEPRECATED - This should be moved into a private header.
 
 If this property is set to `YES`, we will refresh the canvas in the next draw cycle.
 
 We set this property to `YES` when we call [ShinobiChart redrawChartIncludePlotArea:] and pass `YES` in as the argument.
 */
@property (nonatomic) BOOL redrawGL;

/* DEPRECATED - This should be moved into a private header.
 
 We set this property to `YES` when we reload data in the chart. */
@property (nonatomic, assign) BOOL reloadedData;

/* DEPRECATED - This should be moved into a private header.
 
 We set this property to `YES` if the chart responds to device rotations, and we rotate the device. */
@property (nonatomic, assign) BOOL orientationChanged;

@end
