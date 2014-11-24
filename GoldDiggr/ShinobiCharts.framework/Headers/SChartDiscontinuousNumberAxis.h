//
//  SChartDiscontinuousAxis.h
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SChartNumberAxis.h"

@class SChartNumberAxis;

typedef struct SChartNumberSkip {
    double start, end;
} SChartNumberSkip;

/**
 * An SChartDiscontinuousNumberAxis is a subclass of SChartNumberAxis,
 * designed to allow skipping over given ranges.
 
 @available Premium
 
 @warning This type of axis is not currently supported radial charts. 
 */
@interface SChartDiscontinuousNumberAxis : SChartNumberAxis

/**
 * Add an SChartNumberSkip with a start and end, to the list of ranges to skip
 *
 * An SChartNumberSkip is defined as follows:
 *
 *    typedef struct {
 *       double start, end;
 *    } SChartNumberSkip;
 *
 * You must reload the chart when adding new skips.
 *
 * @param skip The `SChartNumberSkip` to add to the exclusions
 */
- (void)    addSkip:(SChartNumberSkip)skip;

/**
 * Remove a previously added SChartNumberSkip from the list of ranges to skip.
 *
 * You must reload the chart when removing skips.
 *
 * @param skip The `SChartNumberSkip` to be removed from the exclusions
 */
- (void) removeSkip:(SChartNumberSkip)skip;


/**
 * Returns an array of NSValues, each containing an SChartNumberSkip.
 *
 * Note that you should not call `addSkip` or `removeSkip` while iterating over
 * this array.
 */
- (NSArray *)skips;

@end
