//
//  SChartBounceDelayAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve evaluator describes a curve similar to that described by SChartBounceAnimation but where the 'bounce' occurs over a shorter proportion of the duration (`50%`).
 
 For the remainder of the duration, the curve is constant at `1`. This is the 'delay' where there is no change.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartBounceDelayAnimationCurve : NSObject <SChartAnimationCurve>

@end
