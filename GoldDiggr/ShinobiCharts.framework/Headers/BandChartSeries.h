//
//  SChartGLView+BandChartSeries.h
//  Dev
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

@interface SChartGLView (BandChartSeries)

- (void)drawBandSeriesFill:(float *)seriesHigh
                 forSeries:(SChartSeries *)s
              andLowSeries:(float *)seriesLow
                  forIndex:(int *)trianglesIndex
                  withSize:(NSInteger)size
         withAreaColorHigh:(UIColor *)areaColorHigh 
          withAreaColorLow:(UIColor *)areaColorLow  
           withOrientation:(SChartSeriesOrientation)orientation
            withNumCrosses:(NSInteger)numCrosses
            andTranslation:(const SChartGLTranslation *)transform;

@end
