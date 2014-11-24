//
//  SChartStepLineSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartLineSeries.h"

/** SChartStepLineSeries is a type of `SChartLineSeries` that uses its data points to construct a step line series. 
 
 The step line series consists of a number of points which may or may not be marked, that are connected by a stepping line with an optional fill (i.e. an area series) between the line and the axis.
 
 @available Standard
 @available Premium
 @sa ChartsUserGuide
 @sample LargeDataSet
 */
@interface SChartStepLineSeries : SChartLineSeries

@end
