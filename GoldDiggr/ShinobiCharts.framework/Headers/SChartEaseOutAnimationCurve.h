//
//  SChartEaseOutAnimationCurve.h
//  Dev
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This curve starts off steadily at 0.0, passes 0.5 then decelerates to reach 1.0, creating a slow exit phase.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartEaseOutAnimationCurve : NSObject <SChartAnimationCurve>

@end
