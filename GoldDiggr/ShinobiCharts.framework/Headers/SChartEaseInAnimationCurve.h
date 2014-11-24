//
//  SChartEaseInAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve starts off slowly at 0.0, creating a gentle initial phase, then accelerates past 0.5 to reach 1.0.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartEaseInAnimationCurve : NSObject <SChartAnimationCurve>

@end
