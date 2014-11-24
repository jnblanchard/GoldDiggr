//
//  SChartLegend.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef enum {
    SChartSeriesLegendAlignSymbolsLeft,
    SChartSeriesLegendAlignSymbolsRight
} SChartSeriesLegendSymbolAlignment;

typedef enum {
    SChartLegendOrientationVertical,
    SChartLegendOrientationHorizontal
} SChartLegendOrientation;

typedef enum {
    SChartLegendPlacementOutsidePlotArea,
    SChartLegendPlacementInsidePlotArea,
    SChartLegendPlacementOnPlotAreaBorder
} SChartLegendPlacement;

typedef enum {
    SChartLegendPositionTopRight,
    SChartLegendPositionMiddleRight,
    SChartLegendPositionBottomRight,
    SChartLegendPositionBottomMiddle,
    SChartLegendPositionBottomLeft,
    SChartLegendPositionMiddleLeft,
    SChartLegendPositionTopLeft,
    SChartLegendPositionTopMiddle
} SChartLegendPosition;

@class ShinobiChart;
@class SChartLegendStyle;
@class SChartTitle;

/** Series data can be displayed in a legend on a `ShinobiChart`. The `SChartLegend` is a UIView-based object that represents the legend as a visual item on the chart. The legend may appear in a number of preset positions within the chart. 
 
 <img src="../Images/api_legend.png" width=400/>
 
 - SChartLegendPlacementOutsidePlotArea: Configures the legend to be placed outside of the plot area.
 - SChartLegendPlacementInsidePlotArea: Configures the legend to be placed inside of the plot area.
 - SChartLegendPlacementOnPlotAreaBorder: Configures the legend to be placed on the plot area border.
 
 The placement of the legend inside or outside the plot area has different effects. See the `placement` property for more information.
 
 Irrespective of how the plot area behaves, we can anchor the legend to several preset positions in the chart area:

 - SChartLegendPositionTopRight: Configures the legend to be anchored in the top right of the chart area.
 - SChartLegendPositionMiddleRight: Configures the legend to be anchored vertically center on the right of the chart area.
 - SChartLegendPositionBottomRight: Configures the legend to be anchored in the bottom right of the chart area.
 - SChartLegendPositionBottomMiddle: Configures the legend to be anchored in the center at the bottom of the chart area.
 - SChartLegendPositionBottomLeft: Configures the legend to be anchored in the bottom left of the chart area.
 - SChartLegendPositionMiddleLeft: Configures the legend to be anchored vertically center on the left of the chart area.
 - SChartLegendPositionTopLeft: Configures the legend to be anchored in the top left of the chart area.
 - SChartLegendPositionTopMiddle: Configures the legend to be anchored in the center at the top of the chart area.
 
 See the `position` property for more information.
 
 To create a custom legend object, you can subclass `SChartLegend` and override its `drawLegend` method.  You can then assign the new legend object to `[ShinobiChart legend]`.
 
 Any instance of `SChartSeries` will adopt the `SChartLegendItem` protocol, which means that series can also customize how they appear in the legend.  `SChartLegendItem` allows a series to specify the title or symbol which should represent it in the legend.  For radial series, it allows the series to specify how each slice should be represented.  See the protocol's API documentation for more information.
 
 More information about using SChartLegend can be found in the [user guide](../../user_guide.html#Legend), and in our tutorial ['The making of a legend'](http://www.shinobicontrols.com/blog/posts/2012/09/10/the-making-of-a-legend).
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 */
@interface SChartLegend : UIView

#pragma mark -
#pragma mark Initialisation
/** @name Initialisation */

/** Initializes the legend with a reference to the chart.
 @param _chart The chart which will contain the legend.
 @return An initialized legend object, or `nil` if the legend couldn't be created. */
- (id)initWithChart:(ShinobiChart *)_chart;

#pragma mark -
#pragma mark Drawing
/** @name Drawing the legend */

/** The main function called by the chart to construct the legend.
 
 Override this function to create a custom legend. */
- (void)drawLegend;

#pragma mark -
#pragma mark Data
/** @name Data from the chart */

/* A reference to the chart that the legend belongs to */
@property (nonatomic, assign) ShinobiChart *chart;

#pragma mark -
#pragma mark Formatting
/** @name Formatting the legend */
/**Sets a title for the legend. */
@property (nonatomic, retain) NSString *title;

/** Specifies the positioning of the legend on the chart.
 
 The options available are:
 
 - SChartLegendPositionTopRight: Configures the legend to be anchored in the top right of the chart area.
 - SChartLegendPositionMiddleRight: Configures the legend to be anchored vertically center on the right of the chart area.
 - SChartLegendPositionBottomRight: Configures the legend to be anchored in the bottom right of the chart area.
 - SChartLegendPositionBottomMiddle: Configures the legend to be anchored in the center at the bottom of the chart area.
 - SChartLegendPositionBottomLeft: Configures the legend to be anchored in the bottom left of the chart area.
 - SChartLegendPositionMiddleLeft: Configures the legend to be anchored vertically center on the left of the chart area.
 - SChartLegendPositionTopLeft: Configures the legend to be anchored in the top left of the chart area.
 - SChartLegendPositionTopMiddle: Configures the legend to be anchored in the center at the top of the chart area.
 */
@property (nonatomic, assign) SChartLegendPosition position;

/** The position of the legend relative to the chart plot area.
 
 The options available are:
 
 - SChartLegendPlacementOutsidePlotArea: Configures the legend to be placed outside of the plot area.
 - SChartLegendPlacementInsidePlotArea: Configures the legend to be placed inside of the plot area.
 - SChartLegendPlacementOnPlotAreaBorder: Configures the legend to be placed on the plot area border.
 
 If the legend is drawn outside of the plot area, the plot area will shrink to accommodate the legend without obscuring the chart plot.  If the legend is drawn inside the plot area, the plot area will expand as though the legend is not there - with the legend displaying over it.  
 
 If the legend is drawn on the plot area border, the plot area will shrink to accomodate half of the legend.  In this case, the legend will half overlap with the chart, and half be drawn outside the plot area.
 */
@property (nonatomic, assign) SChartLegendPlacement placement;

/** The width that each symbol in the legend should have, in points.
 
 If this is not set by the user, each symbol will automatically take up half of the width of the legend (with the chart series label/text taking up the other half).
 
 By default, this property is set to `24`; */
@property (nonatomic, retain) NSNumber *symbolWidth;

/** DEPRECATED - Use `[SChartLegendStyle showSymbols]` instead. */
@property (nonatomic, assign) BOOL showSymbols  DEPRECATED_ATTRIBUTE;

/** The maximum number of series which are shown per row in horizontal legends. 
 
 By default, this property is set to `4`; */
@property (nonatomic, assign) NSInteger maxSeriesPerLine;

/** If this is set to `YES`, legend labels will autosize to fit their text.
 
 Note that the legend frame will still be overridden if the frame is set manually,
 but this setting will override any value of `fixedWidthRatio` that has been set on the legend.
 
 By default, this property is set to `YES`; */
@property (nonatomic, assign) BOOL autosizeLabels;

/** Defines a fixed ratio of the width of the overall chart which the legend will take up. 
 
 If this value is not set, the width of the chart will be auto-calculated. By default, this property is set to `nil`. */
@property (nonatomic, retain) NSNumber *fixedWidthRatio;

#pragma mark -
#pragma mark Styling
/** @name Styling */

/** Manages the appearance of the legend. 
 @see SChartLegendStyle
 */
@property (nonatomic, retain) SChartLegendStyle *style;

/** Determines the radius of the legend corners.
 
 By default, this property is set to `0`. Setting this to `nil` also equates to a radius of 0 - which results in square corners. 
 
 @warning *DEPRECATED* - This property will be removed in a future release. Use the `cornerRadius` property on the `SChartLegendStyle` class.
 */
@property (nonatomic, retain) NSNumber *cornerRadius DEPRECATED_ATTRIBUTE;

#pragma mark -
#pragma mark Legend items
/** @name Legend items */

/** The symbols which are contained within the legend. */
@property (nonatomic, retain) NSMutableArray *symbols;

/** The labels which are contained within the legend. */
@property (nonatomic, retain) NSMutableArray *labels;

#pragma mark -
#pragma mark Drawing
/** Drawing */

/** Causes the legend to redraw itself. Changes in series styling will not be updated within the legend until this method has been called.*/
- (void)reload;

@end
