//
//  DonutChartSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

@interface SChartGLView (DonutChartSeries)

- (void)drawRadialSlice:(NSInteger)sliceIndex
              forSeries:(SChartSeries*)series
              fromAngle:(float)startAngle
                toAngle:(float)endAngle
             fromCentre:(CGPoint)centre
        withInnerRadius:(float)iRad
         andOuterRadius:(float)oRad
       withDisplacement:(float)displace
          withFillColor:(UIColor *)fillColor
          withLineColor:(UIColor *)lineColor
          withLineWidth:(float)lineWidth
             withEffect:(NSInteger)effect;

@end
