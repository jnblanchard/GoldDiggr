//
//  SChartGLView+OHLCChartSeries.h
//  Dev
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import "SChartGLCommon.h"

@interface SChartGLView (OHLCChartSeries)

- (void)drawOHLCPoints:(float *)series
             forSeries:(SChartSeries *)s
         forLinesIndex:(int *)linesIndex
   forOffsetLinesIndex:(int *)offsetLinesIndex
              withSize:(NSInteger)size
            withColors:(NSArray *)colors
    withGradientColors:(NSArray *)gradientColors
       withOrientation:(SChartSeriesOrientation)orientation
         withOHLCWidth:(float)ohlcWidth
        withTrunkWidth:(NSArray *)trunkWidth
          withArmWidth:(NSArray *)armWidth
        andTranslation:(const SChartGLTranslation *)transform;

@end
