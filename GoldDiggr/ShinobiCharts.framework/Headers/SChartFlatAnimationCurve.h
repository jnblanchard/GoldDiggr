//
//  SChartFlatAnimationCurve.h
//  ShinobiControls_Source
//
//  Created by Simon Withington on 29/11/2012.
//
//

#import "SChartAnimation.h"

/** This flat curve evaluator returns 1.f ('finished') for all values of time.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 
 @available Standard
 @available Premium
 */
@interface SChartFlatAnimationCurve : NSObject <SChartAnimationCurve>

@end
