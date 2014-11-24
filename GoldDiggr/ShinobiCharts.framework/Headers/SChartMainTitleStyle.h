//
//  SChartMainTitleStyle.h
//  ShinobiControls_Source
//
//  Copyright 2012 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartTitleStyle.h"


/** A look of a chart is managed by an instance of `SChartTheme` or one of its sub-classes.  Themes contain a set of style objects, each of which are responsible for managing the look of a particular aspect of the chart.
 
 The SChartMainTitleStyle class is responsible for managing the look of the main chart title.  As well as the properties it inherits from `SChartTitleStyle`, it also allows you to specify the chart element on which the title should center, and whether the title should overlap with the chart canvas.
 
 @available Standard
 @available Premium
 
 @warning Chart titles are not currently supported on radial charts.
 */
@interface SChartMainTitleStyle : SChartTitleStyle <NSCopying>

/** Set how the title centers.

 - SChartTitleCentreOnChart: Centers the title on the full chart view.
 - SChartTitleCentreOnPlottingArea: Centers the title on the plot area.
 - SChartTitleCentreOnCanvas: Centers the title on the canvas.
 */
@property (nonatomic, assign) SChartTitleCentresOn titleCentresOn;

/** Indicates whether space should be reserved at the top of the chart for the title, or whether it should overlap with the canvas.
 
 Setting this attribute to `YES` will allow the UILabel to appear over the chart canvas. Setting it to `NO` will push the canvas area down and reserve space above the chart plots for the title.*/
@property (nonatomic, assign) BOOL overlapChartTitle;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartMainTitleStyle *)style;

@end
