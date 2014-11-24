//
//  ShinobiLog.h
//  ShinobiControls_Source
//
//

#import <Foundation/Foundation.h>

/* Provides logging functionality for ShinobiCharts.
 
 @available Standard
 @available Premium
 */
@interface ShinobiChartLog : NSObject

/* Logs an error message, along with some associated information
 
 @param info    Information associated with the message
 @param msg The message to log
 @param sender  The source of the message
 */
+ (void)logInfo:(NSDictionary *)info withMessage:(NSString *)msg fromSource:(id)sender;

/* Logs an error message, and logs the source of the error
 
 @param msg The message to log
 @param sender The source of the error
 */
+ (void)logMessage:(NSString *)msg fromSource:(id)sender;

/* Logs an error message
 
 @param msg The message to log
 */
+ (void)logMessage:(NSString *)msg;

/* Logs an error message, and stops the application
 
 This is intended for situations where the application cannot be expected to carry on with the error condition.
 noreturn prevents red-herrings for uninitialised variables, etc.
 
 @param msg The message to log
 @param sender  The source of the error
 */
+ (void)fatalLogMessage:(NSString *)msg fromSource:(id)sender __attribute__((noreturn));

/* Sets whether logging is enabled in the framework */
+ (void)setLoggingEnabled:(BOOL)loggingEnabled;

/* Returns `YES` if logging is enabled in the framework. Returns `NO` otherwise */
+ (BOOL)loggingEnabled;

@end
