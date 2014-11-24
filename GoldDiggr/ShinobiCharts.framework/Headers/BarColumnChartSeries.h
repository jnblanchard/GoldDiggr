//
//  BarColumnChartSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartGLCommon.h"

@interface SChartGLView (BarColumnChartSeries)

- (void)drawBarColWithPoints:(float*)points
    series:(SChartSeries *)series
    baseSeries:(float*)basePoints
    pointStyles:(NSArray *)pointStyles
    triangleIndex:(int *)triangleIndex
    lineIndex:(int *)lineIndex
    size:(GLuint)size
    barWidth:(float)barColumnWidth
    glBaseline:(float)glBaseline
    orientation:(SChartSeriesOrientation)orientation
    translation:(const SChartGLTranslation *)translation;

@end
