//
//  SChartAnimation.h
//  Dev
//
//  Copyright 2013 Scott Logic Ltd. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import "SChartAnimationCurve.h"

typedef enum {
    SChartAnimationCurveLinear,
    SChartAnimationCurveEaseIn,
    SChartAnimationCurveEaseOut,
    SChartAnimationCurveEaseInOut,
    SChartAnimationCurveBounce,
} SChartAnimationCurve;

/**
 An `SChartAnimation` object determines how an `SChartSeries` is animated.
 
 Depending on the action which an animation is linked to, it may be triggered by different actions:
 
 - Entry Animations are triggered upon the initial addition of the series to the chart and when a series is unhidden using its hidden property.
 - Exit Animations are triggered when a series is hidden using its hidden property.
 
 The code snippet below demonstrates how to set a series to fade in when entering and fade out when exiting.  We set the duration of both animations to be 3 seconds:
 
    SChartAnimation *animation = [ SChartAnimation fadeAnimation ];
    animation.duration = @3;
    series.entryAnimation = [ animation copy ];
    series.exitAnimation = [ animation copy ];
 
 We updated the animation code in version 2.2 of charts.  As a result of these updates, the SChartAnimationCurve enum defined in earlier versions of charts has been deprecated.  Instead of using this, you should configure the properties of the animation to meet your needs.  The properties you can set on an animation are:
 
 - The duration of the animation.  See `duration` for more information.
 - The origin point on the chart from where the series animates to its final position.  See `absoluteOriginX`, `absoluteOriginY`, `normalisedOriginX` and `normalisedOriginY` for more information.
 - How the chart series scales as the animation progresses.  See `xScaleCurve`, `yScaleCurve` or `radiusCurve` for more information.
 - How the transparency of the series varies over the period of the animation.  See `alphaCurve` for more information.
 - For pie/donut chart series, you can specify how the series rotates around the origin during the animation.  See `angleCurve` for more information.
 
 The `SChartAnimation` object is composed of several objects conforming to the `SChartAnimationCurve` protocol,
 which each describe the transition of an aspect of the chart series from the start of the animation to the end.  We have defined concrete implementations of this protocol to support common animation use cases which you might have.  Some of the concrete animation curve classes are:
 
 - `SChartLinearAnimationCurve` - a linear animation.
 - `SChartEaseInAnimationCurve` - animation which starts off gently, then accelerates in the second half of the animation.
 - `SChartEaseOutAnimationCurve` - animation which starts off at a steady speed, then decelerates in the second half of the animation, creating a slow exit phase.
 - `SChartEaseInOutAnimationCurve` - animation which starts off gently, accelerates through the middle part of the animation, then decelerates at the end to finish gently.
 - `SChartBounceAnimationCurve` - animation where the series goes past its final value, then bounces back to it at the end.
 
 Other animation curves are also available, see the API documentation for more information.
 
 To save you having to create animation classes from scratch, we've provided some pre-defined types for you.  Have a look at the factory methods we've provided in the "Creating Animations" sections of this page.

 @warning This feature isn't currently supported on radial charts.
 
 More information about using SChartAnimation can be found in our tutorial ['Animating ShinobiChart Series'](http://www.shinobicontrols.com/blog/posts/2013/03/14/animating-shinobichart-series).
 
 @available Standard
 @available Premium
 */
@interface SChartAnimation : NSObject <NSCopying>

#pragma mark -
#pragma mark Creating Animations
/** @name Creating Animations */

/** Returns an animation where the series scales from its centre.
 
 This is the default entry & exit animation for `SChartScatterSeries`, `SChartDonutSeries`, and `SChartPieSeries`.
 
 By default, the normalized X and Y are both set to `0.5f`, and the animation duration is set to `2.4` seconds.
 */
+(SChartAnimation *)growAnimation;


/** Returns an animation where the series scales from its leftmost point.
 
 This is the default entry & exit animation for `SChartBarSeries`.
 
 By default, the normalized X is set to `0.f`, normalized Y is set to `0.5f`, and the animation duration is set to `2.4` seconds. If a baseline is set on a bar series, and a custom origin has not been set for the animation, the baseline will be used as the origin instead.
 */
+(SChartAnimation *)growHorizontalAnimation;


/** Returns an animation where the series scales from its lowest point.
 
 This is the default entry & exit animation for `SChartColumnSeries`, `SChartOHLCSeries`, and `SChartCandlestickSeries`.
 
 By default, the normalized X is set to `0.5f`, normalized Y is set to `0.f`, and the animation duration is set to `2.4` seconds. If a baseline is set on a column, OHLC, or candlestick series, and a custom origin has not been set on the animation, the baseline will be used as the origin instead.
 */
+(SChartAnimation *)growVerticalAnimation;


/** Returns an animation where the series fades.
 
 By default, the normalized X and Y are both set to `0.5f`, and the animation duration is set to `2.4` seconds.
 */
+(SChartAnimation *)fadeAnimation;


/** Returns an animation where the series mimics the entrance/exit of the picture in an old television.
 
 This is the default entry & exit animation for `SChartLineSeries`, `SChartStepLineSeries`, and `SChartBandSeries`.
 
 By default, the normalized X and Y are both set to `0.5f`, and the animation duration is set to `2.4` seconds.
 */
+(SChartAnimation *)televisionAnimation;

/** Returns an animation where the series rotates with a bounce and changes its protrusion with a bounce.
 
 This is the default selection animation for `SChartDonutSeries` and `SChartPieSeries`.
 
 By default, the normalized X and Y are both set to `0.5f`, and the animation duration is set to `2.4` seconds.
 */
+(SChartAnimation *)radialSelection;


#pragma mark -
#pragma mark Configuring Curves
/** @name Configuration Animation Curves */

/** The overall animation curve for the animation.
 
 Setting this curve will set each of the other curves for the animation to this same curve.
 By default, this property is set to `SChartFlatAnimationCurve`.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    curve;


/** The animation curve describing the transition of the series parallel to the x axis.
 
 This curve describes how the x values of the series scale from some origin along the x axis at the start of the animation to their destination at the end of the animation.
 An xScale value of 0 maps a point at the animation origin whereas a value of 1 maps the point at it's true value perpendicular to the x axis.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    xScaleCurve;


/** The animation curve describing the transition of the series parallel to the y axis.
 
 This curve describes how the y values of the series scale from some origin along the y axis at the start of the animation to their destination at the end of the animation.
 An yScale value of 0 maps a point at the animation origin whereas a value of 1 maps the point at it's true value perpendicular to the yAxis.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    yScaleCurve;


/** This curve only applies to pie/donut chart series.  The animation curve describes the transition of the series around its origin.
 
 This curve describes how the points of the series rotate around the centre of the series from some initial angle at the start of the animation to a destination angle at the end of the animation.
 An angle scale value of 0 maps to the original angle whereas a value of 1 maps to the destination angle.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    angleCurve;


/** The animation curve describing how the radius/radii of the series change during the animation.
 
 This curve describes how both the x values and the y values of a series scale from some origin to their true values.
 It is mostly used for pie/donut series, often in conjunction with an origin at the centre of the pie/donut series.
 Setting this curve will override any previously set values for `xScaleCurve` and `yScaleCurve`.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    radiusCurve;


/** The animation curve describing how the transparency of the series changes during the animation.
 
 This curve describes how the alpha value of the colors of the series scale from some initial alpha value at the start of the animation to some destination alpha at the end of the animation.
 We multiply the value returned by this curve with the colors set to the series, therefore a curve value of 0 results in a completely transparent color and a value of 1 results in the final alpha value of the series color.
 This curve applies to both cartesian and pie/donut series.
 */
@property (retain, nonatomic)   id <SChartAnimationCurve>    alphaCurve;

#pragma mark -
#pragma mark Configuring Duration
/** @name Configuration Animation Duration */

/** The duration of the animation.
 
 The time taken, in seconds, for the animation to progress from start to finish.
 The duration of the animations returned by the factory methods provided is 2.4 seconds.
 The duration of an animation created via alloc/init is 1/64 seconds (instant).
 Use this property to configure how long an animation should take to complete.
 */
@property (retain, nonatomic)   NSNumber    *duration;

#pragma mark -
#pragma mark Configuring Origins
/** @name Configuring the origin of the animation */

/** If this property is set, this will be the origin value in x in data terms - a curve returning 0 maps to this value, whereas a curve returning 1 maps to the final true value of the series.
 
 Points will scale from this value along the x axis in either direction.
 If this property is not set, the animation will use a normalized origin on x - see `normalisedOriginX`.
 */
@property (retain, nonatomic)   id  absoluteOriginX;


/** If this property is set, this will be the origin value in y in data terms - a curve returning 0 maps to this value, whereas a curve returning 1 maps to the final true value.
 
 Points will scale from this value along the y axis in either direction.
 If this property is not set, the animation will use a normalized origin on y - see `normalisedOriginY`.
 */
@property (retain, nonatomic)   id  absoluteOriginY;


/** This property enables you to set a normalized point of origin along the x axis for the animation.
 
 This value is normalized using the range of the series which the animation is applied to.
 For example, setting a `normalisedOriginX` of `0.f` would cause the series to animate from its left-most point.
 Setting a `normalisedOriginX` of `1.f` would cause the series to animate from its right-most point.
 By default, this property is set to `0.5f`. However, if a value is set for `absoluteOriginX`, this property will be ignored.
 */
@property (nonatomic)   float    normalisedOriginX;


/** This property enables you to set a normalized point of origin along the y axis for the animation.
 
 This value is normalized using the range of the series which the animation is applied to.
 For example, setting a `normalisedOriginY` of `0.f` would cause the series to animate from its lowest point.
 Setting a `normalisedOriginY` of `1.f` would cause the series to animate from its highest point.
 By default, this property is set to `0.5f`. However, if a value is set for `absoluteOriginY`, this property will be ignored.
 */
@property (nonatomic)   float    normalisedOriginY;


@end
