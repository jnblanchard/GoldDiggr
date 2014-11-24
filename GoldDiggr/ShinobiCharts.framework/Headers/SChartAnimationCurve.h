//
//  SChartAnimationCurve.h
//  Dev
//
//  Copyright 2013 Scott Logic Ltd. All rights reserved.
//
//

#import <Foundation/Foundation.h>

/** The `SChartAnimationCurve` protocol allows any object to act as a curve evaluator for series' animations, as defined in `SChartAnimation`.  
 
 Given a time point between the start and end of an animation, a curve evaluator returns a value which represents the progress of the series between its beginning and end positions.  For more information on curve evaluation, see the `valueAtTime:` method defined in the protocol.

 Objects conforming to this protocol need also to conform to the NSCopying protocol.
 
 We have defined concrete implementations of this protocol to support common animation use cases which you might have.  The concrete animation curve classes are:
 
 - `SChartLinearAnimationCurve` - a linear animation.
 - `SChartEaseInAnimationCurve` - animation which starts off gently, then accelerates in the second half of the animation.
 - `SChartEaseOutAnimationCurve` - animation which starts off at a steady speed, then decelerates in the second half of the animation, creating a slow exit phase.
 - `SChartEaseInOutAnimationCurve` - animation which starts off gently, accelerates through the middle part of the animation, then decelerates at the end to finish gently.
 - `SChartBounceAnimationCurve` - animation where the series goes past its final value, then bounces back to it at the end.
 - `SChartDelayBounceAnimationCurve` - similar to the bounce animation curve, but the bounce occurs over the second half of the animation.  For the first half of the animation, the curve returns 0.f.
 - `SChartDelayBounceWithMinimumAnimationCurve` - similar to the delayed bounce animation curve.  The difference is that it returns 0.1f for the first half of the animation, rather than 0.f.
 - `SChartBounceDelayAnimationCurve` - similar to the bounce animation curve, but the bounce occurs over the first half of the animation.  For the second half, the curve returns 1.f.
 - `SChartFlatAnimationCurve` - basically no animation.  Returns 1.f for all time values.
 
 @available Standard
 @available Premium
 */
@protocol SChartAnimationCurve <NSObject, NSCopying>

@required
/** @name Curve Evaluation*/

/** Should return an appropriate value for the animation curve at the given time.
 
 The value returned represents the progress of the series between its beginning and end positions, where 0.f is the start state and 1.f is, nominally, the end state.
 It is valid to return a value 'v' where either v < 0.f or v > 1.f and it not necessary to return 1.f at time 1.f.
 
 @param time Time is provided as a float between 0.f and 1.f, where 0.f is the beginning of the animation and 1.f is the end of the animation. (time = elapsed time / duration)
 */
-(float)valueAtTime:(float)time;


/* DEPRECATED - It doesn't feel right to put this NSObject method on the protocol.  Should we call copyWithZone: instead? 
 
 This method has been added to make use of the convenience method defined in the NSObject class.
 */
-(id)copy;

@end
