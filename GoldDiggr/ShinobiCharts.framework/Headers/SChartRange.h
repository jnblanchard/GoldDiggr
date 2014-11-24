//
//  SChartRange.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
/** `SChartRange` represents a range of values on a chart.  It is used by the chart axes, which are defined in `SChartAxis`.  `SChartRange` is the base class for the concrete range types which are available in ShinobiCharts.  The concrete types are:
 
 - `SChartNumberRange` - represents numerical ranges.
 - `SChartDateRange` - represents date/time ranges.
 
 @available Standard
 @available Premium
 */
@interface SChartRange : NSObject

/** @name Initialization */

/** Initializes and returns a newly allocated range object, with the specified minimum and maximum values. 
 @param min The minimum value of the new range.
 @param max The maximum value of the new range.
 @return An initialized range object, or `nil` if the object couldn't be created.
 */
- (id)initWithMinimum:(NSNumber *)min andMaximum:(NSNumber *)max;

/** @name Information about the range */

/** The minimum value of the range. */
@property (nonatomic, retain, readonly) NSNumber *minimum;

/** The maximum value of the range. */
@property (nonatomic, retain, readonly) NSNumber *maximum;

/** Returns the difference between the maximum and the minimum of the range, as a NSNumber. */
- (NSNumber *)span;


#pragma mark -
#pragma mark Static Initialization

/* Copies the given range object, and returns the new range. 
 @param range The range object to copy.
 @return The copy of the range object.
 */
+ (SChartRange *)rangeWithRange:(SChartRange *)range;

@end
