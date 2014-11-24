//
//  SChartCrosshairMultiValueTooltip.h
//  Dev
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SChartCrosshairTooltip.h"

/** A tooltip that can handle the display of multi-value data points. 
 
 To use a tooltip of this class type simply assign it to your chart's crosshair like so:
 
 `chart.crosshair.tooltip = [[SChartCrosshairMultiValueTooltip new]autorelease]`;
 
 A tooltip of this type handles the multi-values of a datapoint by building a dictionary of key-value strings to be displayed. For example, a crosshair (with a tooltip of this type) that is tracking an OHLC series will likely read from multi-value datapoints such that the following dictionary of strings is to be displayed { Open : value1, High : value2, Low : value3, Close: value4 }. This dictionary is constructed via the method `keyValueDisplayPairsForDataPoint:onSeries:withXAxis:withYAxis:` (which can be overriden in a subclass if you wish to change the key-value pairs that the tooltip finally displays).
 
 A tooltip of this type is made up from an array of labels (one label for each key or value) and a main label (inherited from SChartCrosshairTooltip) which will display any left over values that do not belong to the key-value pairs.
 */

@interface SChartCrosshairMultiValueTooltip : SChartCrosshairTooltip

/** An array of labels that contains a label for each display key and each display value (as dictated by keyValueDisplayPairsForDataPoint:onSeries:withXAxis:withYAxis:).*/
@property (nonatomic, retain) NSMutableArray   *labels;

#pragma mark - Methods for Subclassing
/** @name Methods for Subclassing*/

/** Returns a dictionary of key-value pairs that will be displayed in this tooltip.
 
 For example an OHLC series with a multi-y data point will return a dictionary with four entries. The keys will be "Open", "High", "Low", "Close" as returned by the series method -[SChartSeries stringForKey:withDataPoint:], with corresponding values from the given data point.
 
 The default behaviour is to use the methods `-[SChartSeries stringForKey:withDataPoint:]` and `-[SChartSeries stringForValueWithKey:withDataPoint:usingAxis:]` to retrieve the desired display strings for each key and each value. This means that if you only need to change the text that is displayed for each key or value it is likely less work to subclass your series and override these methods.
 
 @param dataPoint The data point that the toolip is attempting to display values for.
 @param series The series that dataPoint belongs to.
 @param xAxis The x-axis that the series is linked to.
 @param yAxis The y-axis that the series is linked to.
 
 @return A dictionary of `NSString` objects that are to be displayed in this tooltip. */
- (NSDictionary*) keyValueDisplayPairsForDataPoint:(id<SChartData>) dataPoint onSeries:(SChartSeries*) series withXAxis:(SChartAxis*) xAxis withYAxis:(SChartAxis*) yAxis;

/** Returns the string that will be used as the main label on this tooltip.
 
 The default beahviour of this method is to return string representations of the x and y values, where no multi-values exist, as formatted by the appropriate axis.
 
 @param dataPoint The data point that the toolip requires the main label text for.
 @param series The series that dataPoint belongs to.
 @param xAxis The x-axis that the series is linked to.
 @param yAxis The y-axis that the series is linked to.
 
 @return A string representing the text to be displayed in this tooltip's main label.*/
- (NSString*) mainLabelStringForDataPoint:(id<SChartData>) dataPoint onSeries:(SChartSeries*) series withXAxis:(SChartAxis*) xAxis withYAxis:(SChartAxis*) yAxis;

@end
