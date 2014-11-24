//
//  SChartNumberAxis.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SChartAxis.h"

@class SChartNumberRange;

/** 
 An SChartNumberAxis is a subclass of SChartAxis designed to work with data points that use NSNumber. When mapping coordinates it will cast each object to an NSNumber. 
 
  <img src="../Images/api_numberaxis.png" width=300/>
 
 The frequency values for tick marks are expected to be NSNumber objects.
 
 @available Standard
 @available Premium
 
 @sa ChartsUserGuide
 
 @sample Area
 @sample BarChart
 @sample ColumnChart
 @sample FinancialChart
 @sample LargeDataSet
 @sample LineChart
 
 */
@interface SChartNumberAxis : SChartAxis

#pragma mark - 
#pragma mark Initialization
/** @name Initialization */
/** Init with a SChartNumberRange as the default range*/
- (id)initWithRange:(SChartNumberRange *)range;

#pragma mark - 
#pragma mark Zooming
/** The maximum zoom level relative to the maxRange
 
 1 <= zoomInLimit <= 10^13.
 
 By default, this property is set to `10^9`. */
@property (nonatomic) double zoomInLimit;

/** The minimum zoom level relative to the maxRange
 
 0 < zoomOutLimit <= 1
 
 By default, this property is set to `10^(-9)`. */
@property (nonatomic) double zoomOutLimit;

@end
