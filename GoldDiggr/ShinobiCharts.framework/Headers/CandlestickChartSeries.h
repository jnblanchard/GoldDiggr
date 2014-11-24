//
//  CandlestickChartSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartGLCommon.h"

@interface SChartGLView (CandlestickChartSeries)

- (void)drawCandlesticks:(float *)series
               forSeries:(SChartSeries *)s
           forLinesIndex:(int *)linesIndex
       forTrianglesIndex:(int *)trianglesIndex
                withSize:(NSInteger)size
              withColors:(NSArray *)colors
      withGradientColors:(NSArray *)gradientColors
        withOutlineColor:(NSArray *)outlineColors
          withStickColor:(NSArray *)stickColors
         withCandleWidth:(float)candleWidth
       withOutlineWidths:(NSArray *)outlineWidths
         withStickWidths:(NSArray *)stickWidths
             drawOutline:(bool)drawOutline
              drawSticks:(bool)drawStick
         withOrientation:(SChartSeriesOrientation)orientation
          andTranslation:(const SChartGLTranslation *)transform;

@end
