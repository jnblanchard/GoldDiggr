//
//  SChartDataPointLabel.h
//  ShinobiCharts
//
//  Created by Thomas Kelly on 14/11/2013.
//
//

#import <UIKit/UIKit.h>

@protocol SChartData;
@class SChartSeries;
@class ShinobiChart;

/** A label representing a single `SChartDataPoint`, styled by `SChartDataPointLabelStyle`.
 
 @available Standard
 @available Premium
*/
@interface SChartDataPointLabel : UILabel

/** Create a label for a given dataPoint */
-(id)initWithDataPoint:(id<SChartData>)dataPoint;

@end
