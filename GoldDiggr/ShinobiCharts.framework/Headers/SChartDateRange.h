//
//  SChartDateRange.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartRange.h"

/** An `SChartDateRange` object is an instance of `SChartRange` that is specific to NSDate - with each element in the range represented by an NSDate object. This is the likely range of choice for an `SChartDateTimeAxis`.
 
 @available Standard
 @available Premium
 @sample ColumnChart
 @sample FinancialChart
 @sample LineChart
 */
@interface SChartDateRange : SChartRange

#pragma mark -
#pragma mark Initialization
/** @name Initialization */

/** Initializes and returns a newly allocated range object with the specified minimum and maximum dates. 
 @param min The minimum date in the range.
 @param max The maximum date in the range.
 @return An initialized range object or `nil` if the range couldn't be created.
 */
- (id)initWithDateMinimum:(NSDate *)min andDateMaximum:(NSDate *)max;

/** @name Information about the range */

/** Returns the minimum of the range as an NSDate object. */
- (NSDate *)minimumAsDate;

/** Returns the maximum of the range as an NSDate object. */
- (NSDate *)maximumAsDate;


@end
