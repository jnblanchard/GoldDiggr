//
//  SChartDiscontinuousDateTimeAxis.h
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartDateTimeAxis.h"

@class SChartTimePeriod;
@class SChartRepeatedTimePeriod;

/**
 * An SChartDiscontinuousDateTimeAxis is a subclass of SChartDateTimeAxis
 * designed to work with NSDates, skipping over specified time periods.
 
 @available Premium
 */

@interface SChartDiscontinuousDateTimeAxis : SChartDateTimeAxis

#pragma mark - Time Periods
/** @name Time Periods */

/**
 * Adds an `SChartTimePeriod` to the list of date-periods to skip over.
 * You must reload the chart when new skips are added.
 *
 * @param period A new time period to exclude
 */
- (void) addExcludedTimePeriod:(SChartTimePeriod *)period;

/**
 * Adds an `SChartRepeatedTimePeriod` to the skipping algorithm. This causes
 * the axis to skip over a time period repeatedly, anchored at a certain
 * starting point.
 *
 * This starting date may be anywhere, including outside the current axis
 * range. The axis will calculate the correct in-range start for you.
 *
 * You must reload the chart when new skips are added.
 *
 * @param period A new repeat-time period to exclude
 */
- (void) addExcludedRepeatedTimePeriod:(SChartRepeatedTimePeriod *)period;

/**
 * Removes a single, previously added, skip period.
 *
 * You must reload the chart when skips are removed.
 *
 * @param period The same, or an equivalent time period to remove from the exclusions
 */
- (void) removeExcludedTimePeriod:(SChartTimePeriod *)period;

/**
 * Removes a repeated time period/the multiple skips caused by one repeated
 * time period.
 *
 * You must reload the chart when skips are removed.
 *
 * @param period The same, or an equivalent repeat-time period to remove from the exclusions
 */
- (void) removeExcludedRepeatedTimePeriod:(SChartRepeatedTimePeriod *)period;

/**
 * Returns an array of the skipping time periods previously given to the axis.
 *
 * Note that you must copy this array if you wish to iterate over it and call
 * any of the single-add or single-remove methods mentioned in this class.
 */
- (NSArray *) excludedTimePeriods;

/**
 * Returns an array of the repeat-skip time periods previously given to the
 * axis.
 *
 * Note that you must copy this array if you wish to iterate over it and call
 * any of the repeat-add or repeat-remove methods mentioned in this class.
 */
- (NSArray *) excludedRepeatedTimePeriods;

#pragma mark - Subclassing
/** @name Subclassing */

/**
 * Returns the cache count for time-skips. Called when a new cache is required,
 * for example, on a new zoom level.
 *
 * This may be overridden if you wish to trade memory for time or vice-versa
 * when the axis is calculating tick labels. For a faster axis, return a large
 * value (e.g. 1,000), for lower memory usage, return a small value (e.g. 50 -
 * 100).
 *
 * Defaults to 400.
 */
- (NSUInteger)cacheCount;

@end
