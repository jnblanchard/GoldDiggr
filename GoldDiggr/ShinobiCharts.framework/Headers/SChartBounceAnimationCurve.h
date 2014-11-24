//
//  SChartBounceAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 27/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve evaluator describes a curve where the value starts at 0, climbs past 1 and passes it, then returns to 1, creating a 'bounce' effect.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartBounceAnimationCurve : NSObject <SChartAnimationCurve>

@end
