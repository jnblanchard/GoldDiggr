#import <Foundation/Foundation.h>

@class SChartDateFrequency;


/** An `SChartTimePeriod` represents a period of time.  It starts at a point in time, and has a length defined by an instance of `SChartDateFrequency`.
 
 Instances of `SChartTimePeriod` are used by the discontinuous date/time axis (defined in `SChartDiscontinuousDateTimeAxis`).  The axis defines periods of time over which it will skip.
 
 @available Standard
 @available Premium
 */
@interface SChartTimePeriod : NSObject

/** Initializes and returns a newly allocated time period object, starting at the specified start date and running for the specified amount of time.
 @param start The start date of the new time period.
 @param length The length of the time period, expressed as a `SChartDateFrequency`.
 @return An initialized time period object, or `nil` if the object couldn't be created.
 @see SChartDateFrequency
 */
- (id) initWithStart:(NSDate *)start
           andLength:(SChartDateFrequency *)length;

/** Returns the starting point of the time period, as a NSDate object.
 */
- (NSDate *) periodStart;

/** Returns the length of the time period, expressed as a `SChartDateFrequency` object.
 */
- (SChartDateFrequency *) periodLength;

@end


/** A `SChartRepeatedTimePeriod` represents a repeated period of time, starting at a particular point in time.  Each period has a length, and the periods repeat at a given frequency.  The length of each period, and the frequency at which they repeat, are expressed as instances of `SChartDateFrequency`.
 
 Instances of `SChartRepeatedTimePeriod` are used by the discontinuous date/time axis (defined in `SChartDiscontinuousDateTimeAxis`).  The axis uses `SChartRepeatedTimePeriod` to define repeated periods of time over which it will skip.
 
 @available Standard
 @available Premium
 */
@interface SChartRepeatedTimePeriod : SChartTimePeriod

/** Initializes and returns a newly allocated repeated time period object.  The new object will start at the specified start date.  Each of its periods will have the length defined by `length`, and the periods will repeat at the specified frequency.
 @param start The start date of the new time period.
 @param length The length of the time period, expressed as a `SChartDateFrequency`.
 @param freq The frequency at which the time periods will repeat, expressed as a `SChartDateFrequency`.
 @return An initialized repeated time period object, or `nil` if the object couldn't be created.
 @see SChartDateFrequency
 */
- (id) initWithStart:(NSDate *)start
           andLength:(SChartDateFrequency *)length
        andFrequency:(SChartDateFrequency *)freq;

/** @warning UNAVAILABLE ATTRIBUTE - This is inherited from `SChartTimePeriod`, but should not be called on this class.  Use `initWithStart:andLength:andFrequency:` instead. */
- (id) initWithStart:(NSDate *)start
           andLength:(SChartDateFrequency *)length UNAVAILABLE_ATTRIBUTE;

/** Returns the frequency at which the periods will repeat, expressed as a `SChartDateFrequency` object.
 */
- (SChartDateFrequency *) frequency;

@end
