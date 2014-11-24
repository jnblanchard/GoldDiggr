//
//  SChartDelayBounceAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve evaluator describes a curve similar to that described by `SChartBounceAnimation` but at the start the curve is constant at `0`. This is the 'delay' where there is no change. The 'bounce' occurs over a shorter proportion of the duration (`50%`) at the end.

 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartDelayBounceAnimationCurve : NSObject <SChartAnimationCurve>

@end
