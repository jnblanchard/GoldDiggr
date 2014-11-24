//
//  SChartEaseInOutAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve starts off slowly at 0.0, creating a slow initial phase.
 It accelerates past 0.5, then decelerates to reach 1.0, creating a slow exit phase.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartEaseInOutAnimationCurve : NSObject <SChartAnimationCurve>

@end
