//
//  SChartDateFrequency.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    SChartDateFrequencyDenominationSeconds,
    SChartDateFrequencyDenominationMinutes,
    SChartDateFrequencyDenominationHours, 
    SChartDateFrequencyDenominationDays,
    SChartDateFrequencyDenominationWeeks,
    SChartDateFrequencyDenominationMonths,
    SChartDateFrequencyDenominationYears
} SChartDateFrequencyDenomination;

/**
 An `SChartDateFrequency` is used to specify the desired frequency of tick marks on a `SChartDateTimeAxis`. For example, a frequency of 2 hours will cause the axis to attempt to display a tick mark at every 2 hour mark. No class type other than `SChartDateFrequency` (or one of its subclasses) may be used to define a date frequency on the axis.
 
 A frequency of a particular calendar unit may be set from one of the following supported units: year, month, week, day, hour, minute, second. This can be done by either: 
 
 - Initialising an `SChartDateFrequency` object, then using the setter method for the appropriate unit of time (as listed above).
 - Using one of the convenience init methods provided (such as `initWithSecond:`).
 - Using one of the factory methods provided (such as `dateFrequencyWithSecond:`).
 
 A frequency can only be specified in terms of one type of calendar unit. For example - a frequency of 1 hour AND 3 minutes cannot be set. In this case the frequency can only be of the type hour or of the type minute and will be set to the last component specified. To specify partial units it is necessary to use the lowest denominator - in the case of 1 hour and 3 minutes we would create a frequency of 63 minutes.
 
 If an attempt is made to set frequency to a negative or zero value, a default of 1 for the given component will be set. For example, if an attempt is made to set a frequency of -9 years the actual frequency set will be 1 year.
 
 Once the frequency is created, it is given a frequency denomination.  The available frequency denominations are:
 
 - SChartDateFrequencyDenominationSeconds: Configures the frequency denomination of the date frequency object to be seconds.
 - SChartDateFrequencyDenominationMinutes: Configures the frequency denomination of the date frequency object to be minutes.
 - SChartDateFrequencyDenominationHours: Configures the frequency denomination of the date frequency object to be hours.
 - SChartDateFrequencyDenominationDays: Configures the frequency denomination of the date frequency object to be days.
 - SChartDateFrequencyDenominationWeeks: Configures the frequency denomination of the date frequency object to be weeks.
 - SChartDateFrequencyDenominationMonths: Configures the frequency denomination of the date frequency object to be months.
 - SChartDateFrequencyDenominationYears: Configures the frequency denomination of the date frequency object to be years.
 */
@interface SChartDateFrequency : NSObject <NSCopying>

#pragma mark -
#pragma mark Initialization

/** @name Initialization */

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of years. 
 @param newYear The frequency of the new object, in years.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithYear:(NSInteger)newYear;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of months.
 @param newMonth The frequency of the new object, in months.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithMonth:(NSInteger)newMonth;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of weeks.
 @param newWeek The frequency of the new object, in weeks.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithWeek:(NSInteger)newWeek;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of days.
 @param newDay The frequency of the new object, in days.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithDay:(NSInteger)newDay;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of hours.
 @param newHour The frequency of the new object, in hours.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithHour:(NSInteger)newHour;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of minutes.
 @param newMinute The frequency of the new object, in minutes.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithMinute:(NSInteger)newMinute;

/** Initializes and returns a newly allocated date frequency object, with a frequency of the specified number of seconds.
 @param newSecond The frequency of the new object, in seconds.
 @return An initialized date frequency object, or `nil` if the object couldn't be created.
 */
- (id)initWithSecond:(NSInteger)newSecond;

/** @name Factory methods */

/** Returns a new date frequency object, with a frequency of the specified number of years. 
 @param newYear The frequency to use, in years. */
+ (id)dateFrequencyWithYear:(NSInteger)newYear;

/** Returns a new date frequency object, with a frequency of the specified number of months.
 @param newMonth The frequency to use, in months. */
+ (id)dateFrequencyWithMonth:(NSInteger)newMonth;

/** Returns a new date frequency object, with a frequency of the specified number of weeks.
 @param newWeek The frequency to use, in weeks. */
+ (id)dateFrequencyWithWeek:(NSInteger)newWeek;

/** Returns a new date frequency object, with a frequency of the specified number of days.
 @param newDay The frequency to use, in days. */
+ (id)dateFrequencyWithDay:(NSInteger)newDay;

/** Returns a new date frequency object, with a frequency of the specified number of hours.
 @param newHour The frequency to use, in hours. */
+ (id)dateFrequencyWithHour:(NSInteger)newHour;

/** Returns a new date frequency object, with a frequency of the specified number of minutes.
 @param newMinute The frequency to use, in minutes. */
+ (id)dateFrequencyWithMinute:(NSInteger)newMinute;

/** Returns a new date frequency object, with a frequency of the specified number of seconds.
 @param newSecond The frequency to use, in seconds. */
+ (id)dateFrequencyWithSecond:(NSInteger)newSecond;

#pragma mark -
#pragma mark Setting a new frequency
/** @name Setting a new frequency*/

/** Set the date frequency to have a value of the specified number of years.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in years. */
- (void)setYear:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of months.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in months. */
- (void)setMonth:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of weeks.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in weeks. */
- (void)setWeek:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of days.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in days. */
- (void)setDay:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of hours.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in hours. */
- (void)setHour:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of minutes.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in minutes. */
- (void)setMinute:(NSInteger)v;

/** Set the date frequency to have a value of the specified number of seconds.
 
 Before the new value is set, we clear any existing values in the object.
 @param v The new frequency to set, in seconds. */
- (void)setSecond:(NSInteger)v;

#pragma mark -
#pragma mark Accessing the state of the date frequency object
/** @name Accessing the state of the date frequency object */

/** Returns the frequency of the object, measured in seconds. */
- (double)toSeconds;

/** Returns the frequency denomination of the date frequency object.
 
 The available denominations are:
 
 - SChartDateFrequencyDenominationSeconds: Configures the frequency denomination of the date frequency object to be seconds.
 - SChartDateFrequencyDenominationMinutes: Configures the frequency denomination of the date frequency object to be minutes.
 - SChartDateFrequencyDenominationHours: Configures the frequency denomination of the date frequency object to be hours.
 - SChartDateFrequencyDenominationDays: Configures the frequency denomination of the date frequency object to be days.
 - SChartDateFrequencyDenominationWeeks: Configures the frequency denomination of the date frequency object to be weeks.
 - SChartDateFrequencyDenominationMonths: Configures the frequency denomination of the date frequency object to be months.
 - SChartDateFrequencyDenominationYears: Configures the frequency denomination of the date frequency object to be years.
 */
@property (nonatomic, assign) SChartDateFrequencyDenomination denomination;

#pragma mark -
#pragma mark Internal: Date components

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)year;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)month;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)week;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)day;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)hour;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)minute;

/* DEPRECATED - We will remove this from the public API in a future commit, as it is only intended for internal use. */
- (NSInteger)second;

@end
