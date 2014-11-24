//
//  SChartAxis+Deprecated.h
//  ShinobiCharts
//
//  Created by Andrew Polkinghorn on 28/05/2014.
//
//

#ifdef SCHART_HIDE_DEPRECATIONS
#   undef DEPRECATED_ATTRIBUTE
#   define DEPRECATED_ATTRIBUTE
#endif

#import "SChartAxis.h"

@class SChartInternalDataPoint;
@class SChartMappedSeries;
@class SChartBarColumnSeries;

@interface SChartAxis (Deprecated)

#pragma mark -
#pragma mark DataPoint Mapping
/* Map a datapoint to openGL coordinates.
 DEPRECATED - this will be removed from the API soon.
 @warning The 'series' parameter has been changed from class `SChartCartesianSeries` to `SChartMappedSeries`.
 */
-(void)mapCoordinatesForDataPoint:(SChartInternalDataPoint *)dp inSeries:(SChartMappedSeries *)series DEPRECATED_ATTRIBUTE;

/* Map a datapoint of a barColumnSeries to openGL coordinates.
 DEPRECATED - this will be removed from the API soon. */
-(void)mapCoordinatesForBarColumnChartDataPoint:(SChartInternalDataPoint *)dp inSeries:(SChartBarColumnSeries *)series DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Gestures
// DEPRECATED - this will be removed from the API soon.
- (void)cancelGestures DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)stopAnimations DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)stopMomentumZooming DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)stopMomentumPanning DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSArray *)manualGenerateTickMarks DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)autoGenerateTickMarks:(BOOL)redrawLabels DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark  Drawing
/* @name Drawing */

// DEPRECATED - this will be removed from the API soon.
- (void)drawTickMarksWithGLFrame:(CGRect)glFrame usingAxisDrawer:(SChartCanvasUnderlay*)drawer needToRedrawLabels:(BOOL)redrawLabels DEPRECATED_ATTRIBUTE;

/* Draws the axis relative to the openGl frame
 DEPRECATED - this will be removed from the API soon. */
- (void)drawAxisWithGLFrame:(CGRect)frame usingAxisDrawer:(SChartCanvasUnderlay *)drawer DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)valueIsVisible:(double)value onSeries:(SChartSeries *)series DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)ensureValueIsVisible:(double)value andRedraw:(BOOL)redraw DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)ensureValueIsVisible:(double)value DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Values in Data Terms
/* @name Values in Data Terms */

/* DEPRECATED - this will be removed from the API soon. Use `stringForId:` instead.
 
 @see stringForId
 */
- (NSString *)stringForValue:(double)value DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSString *)appropriateFormat:(id)numberObj fallbackToLabelFormatter:(BOOL)useLabelFormatter DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSString *)appropriateFormat:(id)numberObj DEPRECATED_ATTRIBUTE;

/* Returns the real data represented by a glCoord (1D)
 DEPRECATED - this will be removed from the API soon. */
-(NSNumber *)dataValueFromCoord:(double)coord DEPRECATED_ATTRIBUTE;

/* Recalculate barcolumn spacing, min and max values
 DEPRECATED - this will be removed from the API soon. */
- (void)recalculateBarColumns:(NSArray *)barColumnSeries DEPRECATED_ATTRIBUTE;

/* DEPRECATED - use 'offsetForSeries:' instead.
 */
-(id)offsetForDataValue:(id)data inSeries: (SChartSeries *)series DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Series Linking
// DEPRECATED - this will be removed from the API soon.
- (BOOL)isLinkedToSeries:(SChartSeries *)series DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSArray *)ownedSeries DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Data
// DEPRECATED - this will be removed from the API soon.
- (id)doubleToData:(double)fp DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Tick Marks
// DEPRECATED - this will be removed from the API soon.
- (NSString *)longestLabel DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (CGSize)sizeTickLabels DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)spaceForLabels:(NSInteger)numLabels withLabelSizeScalers:(CGPoint)scale DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSNumber *)firstMajorTick DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSInteger)indexOfFirstLabel:(NSInteger)ticksPerLabel DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)firstTickInsideChart:(double)firstTickValue DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (NSNumber *)firstMinorTick DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)isOverAlternate:(double)tickMarkValue DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (double)incrementTickMarkValue:(double)tickMarkValue isMajor:(BOOL) major DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (double)decrementTickMarkValue:(double)tickMarkValue isMajor:(BOOL) major DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)rotateLabel:(UILabel *)tickLabel DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal
// DEPRECATED - this will be removed from the API soon.
- (void)removeViews DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Range
// DEPRECATED - this will be removed from the API soon.
- (void)refreshDataRange DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)updateMaxRange DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)zoomWithMomentum DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Internal: Panning and Zooming Internal
// DEPRECATED - this will be removed from the API soon.
- (BOOL)panWithMomentumStartingAt:(double)panVelocityWrapper DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)panWithMomentum DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (void)updateZoom DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Panning
/*  DEPRECATED - this will be removed from the API soon.
 
 Pan to a standard position.
 To set an explicit zoom use panByValue:
 
 - SChartAxisPanToStart: Pans to the start of the axis.
 - SChartAxisPanToEnd: Pans to the end of the axis.
 - SChartAxisPanToCenter: Pans to the center of the axis.
 */
- (BOOL)panTo:(SChartAxisPanTo)panLocation DEPRECATED_ATTRIBUTE;

// DEPRECATED - this will be removed from the API soon.
- (BOOL)panTo:(SChartAxisPanTo)panLocation withAnimation:(BOOL)animation DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark BarColumn Series
/* DEPRECATED - this will be removed from the API soon.
 
 During the next render process, forces the recalculation of the barcolumn series.
 During normal operation the panning and zooming will take place using transforms - with only periodic recalculations. Setting this to `YES` will force the bars and columns to recalculate all coordinates.
 */
@property (nonatomic) BOOL recalculateBarColumnsRequired DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon.
 
 A boolean indicating if the bar and column series are already configured.
 If this is `YES` the chart will not traverse the data to work out spacing and ranges.
 */
@property (nonatomic) BOOL barColumnsConfigured DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Tick Marks

/* DEPRECATED - this will be removed from the API soon. */
@property (nonatomic, assign) CGPoint labelSizeScalers DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon. */
- (BOOL)setRangeWithMinimum:(id)minimum andMaximum:(id)maximum withAnimation:(BOOL)animation usingBounceLimits:(BOOL)rangeChecks DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon. */
- (BOOL)beyondAxisLimits DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon. */
- (BOOL)beyondAxisLimitsOnBothSides DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon. */
- (BOOL)beyondAxisMinLimit DEPRECATED_ATTRIBUTE;

/* DEPRECATED - this will be removed from the API soon. */
- (BOOL)recheckAxisRange DEPRECATED_ATTRIBUTE;

@end
