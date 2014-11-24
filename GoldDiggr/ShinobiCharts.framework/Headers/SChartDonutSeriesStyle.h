//
//  SChartDonutSeriesStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartSeriesStyle.h"

typedef enum SChartRadialChartEffect {
    SChartRadialChartEffectFlat,
    SChartRadialChartEffectBevelled,
    SChartRadialChartEffectBevelledLight,
    SChartRadialChartEffectRounded, 
    SChartRadialChartEffectRoundedLight,
    SChartRadialChartEffectChiselled,
    SChartRadialChartEffectDefault = SChartRadialChartEffectChiselled
} SChartRadialChartEffect;

/** `SChartDonutSeriesStyle` manages the appearance of donut series on a `ShinobiChart`.  The API for donut series is defined in `SChartDonutSeries`.
 
 Donut slices (and also pie slices, as `SChartPieSeriesStyle` inherits its behavior from this class) are made up of an outline (or 'crust') and a filled area (or 'flavour').  This style object allows you to manage the following properties of a donut series:
 
 - The color and thickness of the crust around the slices.  You can also configure whether the crust is shown.  See `showCrust`, `crustThickness` and `crustColors` for more information.
 - The fill colors of the slices, and whether slices are filled at all.  See `showFlavour` and `flavourColors` for more information.
 
 When a donut series is drawn, it calls the `crustColorAtIndex:` and `flavourColorAtIndex:` methods on the style to get the crust and flavour colors for each slice.
 
 You can configure whether labels are drawn on a donut series.  By default, they will be.  The labels annotate each slice in the series.  See `showLabels`, `labelFont`, `labelFontColor` and `labelBackgroundColor` for more information.
 
 When a slice in a donut series is selected, it protrudes out from the rest of the series.  You can control how much it protrudes using the `protrusion` property.
 
 @available Standard
 @available Premium
 @sample PieChart
 */
@interface SChartDonutSeriesStyle : SChartSeriesStyle

/** @name General properties */

/** Defines whether the inside of the donut is filled or 'flavoured'. */
@property (nonatomic)                   BOOL                        showFlavour;

/** Defines whether the outline or 'crust' of the donut is to be shown. */
@property (nonatomic)                   BOOL                        showCrust;

/** Defines whether the slices of the series are annotated with labels. */
@property (nonatomic)                   BOOL                        showLabels;

/** The appearance of the series, which can be either flat, bevelled, or rounded.
 
 The complete list of options is:
 
 - SChartRadialChartEffectFlat: Configures the appearance of the series to be flat.
 - SChartRadialChartEffectBevelled: Configures the appearance of the series to be bevelled.
 - SChartRadialChartEffectBevelledLight: Configures the appearance of the series to be bevelled. Has the same shadowing applied as the normal effect but the the shadow color is lighter.
 - SChartRadialChartEffectRounded: Configures the appearance of the series to be rounded.
 - SChartRadialChartEffectRoundedLight: Configures the appearance of the series to be rounded. Has the same shadowing applied as the normal effect but the the shadow color is lighter.
 - SChartRadialChartEffectChiselled: Configures the appearance of the series to be chiselled.
 - SChartRadialChartEffectDefault: Is provided for backwards compatibility. It will be removed in future releases.
 
 In iOS7, the flat effect is the default. In earlier versions of iOS, the chiselled effect is the default.
 */
@property (nonatomic)                   SChartRadialChartEffect     chartEffect;

/** The initial rotation of the series in radians. */
@property (nonatomic, retain)           NSNumber                    *initialRotation;

/** @name Slice properties */

/** An array containing the 'crust' colors of the slices in the series.
 
 The order of the colors in the array corresponds to the order of the slices in the series.
 */
@property (nonatomic, retain)           NSMutableArray              *crustColors;

/** The thickness of the outline or 'crust' of the series, in points. */
@property (nonatomic, retain)           NSNumber                    *crustThickness;

/** An array containing the 'flavour' colors of the slices in the series. 
 
 The order of the colors in the array corresponds to the order of the slices in the series.
 */
@property (nonatomic, retain)           NSMutableArray              *flavourColors;

/** @name Protrusion */

/** The amount by which the slice slides out from the centre when selected, in points. 
 
 A zero value means that no protrusion effect is seen when a slice is selected.
 */
@property (nonatomic,)                  float                       protrusion;

/* DEPRECATED - This will be removed from the public API in a future commit. */
@property (nonatomic)                   BOOL                        protrusionSet;

/** @name Labels */

/** The font used in the labels which annotate the series. */
@property (nonatomic, retain)           UIFont                      *labelFont;

/** The font color used in the labels which annotate the series. */
@property (nonatomic, retain)           UIColor                     *labelFontColor;

/** The background color of the labels which annotate the series. */
@property (nonatomic, retain)           UIColor                     *labelBackgroundColor;

/** @name Update style */

/** Updates this style object using the settings from the passed-in style.
 
 @param style The style with which to configure this style object.
 */
- (void) supplementStyleFromStyle:(SChartDonutSeriesStyle *)style;

/** @name Series colors */

/** Returns the outline or 'crust' color for the given slice in the series. 
 @param index The index of the slice in the series for which to get the crust color.
 */
- (UIColor*) crustColorAtIndex:(NSInteger)index;

/** Returns the fill or 'flavour' color for the given slice in the series. 
 @param index The index of the slice in the series for which to get the flavor color.
 */
- (UIColor*) flavourColorAtIndex:(NSInteger)index;

@end
