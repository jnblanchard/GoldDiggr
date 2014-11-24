//
//  ShinobiChart.h
//
//  Copyright (c) 2012 Scott Logic. All rights reserved.
//

// Global Utility Class
#import "ShinobiCharts.h"

// Main Shinobi Chart Files
#import "SChart.h"
#import "SChartDatasource.h"
#import "SChartDelegate.h"

// Legend Symbols
#import "SChartLegendSymbol.h"
#import "SChartLegendSymbolBarSeries.h"
#import "SChartLegendSymbolColumnSeries.h"
#import "SChartLegendSymbolDonutSeries.h"
#import "SChartLegendSymbolLineSeries.h"
#import "SChartLegendSymbolPieSeries.h"
#import "SChartLegendSymbolScatterSeries.h"

// Legend
#import "SChartLegend.h"
#import "SChartLegendItem.h"
#import "SChartLegendStyle.h"

// Series Styles
#import "SChartSeriesStyle.h"
// Bars and Columns
#import "SChartBarColumnSeriesStyle.h"
#import "SChartBarSeriesStyle.h"
#import "SChartColumnSeriesStyle.h"
// Line, Scatter, Bubble, Point
#import "SChartLineSeriesStyle.h"
#import "SChartScatterSeriesStyle.h"
#import "SChartPointSeriesStyle.h"
#import "SChartBubblePointStyle.h"
#import "SChartBubbleSeriesStyle.h"
// Candlestick
#import "SChartCandlestickSeriesStyle.h"
// Radial
#import "SChartRadialLineSeriesStyle.h"
#import "SChartDonutSeriesStyle.h"
#import "SChartPieSeriesStyle.h"

// Series
#import "SChartSeries.h"
// Bars and Columns
#import "SChartBarColumnSeries.h"
#import "SChartBarSeries.h"
#import "SChartColumnSeries.h"
// Line, Step Line, Band, Scatter
#import "SChartLineSeries.h"
#import "SChartStepLineSeries.h"
#import "SChartBandSeries.h"
#import "SChartScatterSeries.h"
#import "SChartBubbleSeries.h"
// Candlestick
#import "SChartCandlestickSeries.h"
// Radial
#import "SChartRadialSeries.h"
#import "SChartDonutSeries.h"
#import "SChartPieSeries.h"
#import "SChartRadialLineSeries.h"

// Data
#import "SChartOHLCDataValueKeys.h"
#import "SChartCandlestickDataValueKeys.h"
#import "SChartBandDataValueKeys.h"
#import "SChartBubbleDataValueKeys.h"
#import "SChartDataSeries.h"

#import "SChartData.h"
#import "SChartDataPoint.h"
#import "SChartRadialDataPoint.h"
#import "SChartMultiXDataPoint.h"
#import "SChartMultiYDataPoint.h"
#import "SChartBubbleDataPoint.h"
#import "SChartDataPointLabel.h"

// Ranges
#import "SChartRange.h"
#import "SChartNumberRange.h"
#import "SChartDateRange.h"

// Axes Styles
#import "SChartAxisTitleStyle.h"
#import "SChartAxisStyle.h"

// Axes
#import "SChartAxis.h"
#import "SChartNumberAxis.h"
#import "SChartDateTimeAxis.h"
#import "SChartCategoryAxis.h"
#import "SChartLogarithmicAxis.h"
#import "SChartDiscontinuousNumberAxis.h"
#import "SChartDiscontinuousDateTimeAxis.h"
#import "SChartDiscontinuousNumberAxis.h"
#import "SChartDateFrequency.h"

// Discontious Axis Classes
#import "SChartTimePeriod.h"

// Tick Marks
#import "SChartTickMark.h"
#import "SChartTickStyle.h"
#import "SChartTickLabelFormatter.h"

// Canvas and Crosshair
#import "SChartCrosshair.h"
#import "SChartCrosshairStyle.h"
#import "SChartCrosshairTooltip.h"
#import "SChartCrosshairMultiValueTooltip.h"

// Chart Styles
#import "SChartStyle.h"
#import "SChartTitleStyle.h"
#import "SChartMainTitleStyle.h"
#import "SChartAxisTitleStyle.h"
#import "SChartPointStyle.h"
#import "SChartGridStripeStyle.h"
#import "SChartMajorGridlineStyle.h"
#import "SChartDataPointLabelStyle.h"

// Animations
#import "SChartAnimation.h"
#import "SChartFlatAnimationCurve.h"
#import "SChartLinearAnimationCurve.h"
#import "SChartEaseInAnimationCurve.h"
#import "SChartEaseOutAnimationCurve.h"
#import "SChartEaseInOutAnimationCurve.h"
#import "SChartBounceAnimationCurve.h"
#import "SChartDelayBounceAnimationCurve.h"
#import "SChartBounceDelayAnimationCurve.h"

// Annotations
#import "SChartAnnotation.h"

// Miscellaneous
#import "SChartTitle.h"

// Chart Themes
#import "SChartTheme.h"
#import "SChartMidnightTheme.h"
#import "SChartLightTheme.h"
#import "SChartDarkTheme.h"
#import "SChartiOS7Theme.h"

// Activity indicators
#import "SChartActivityIndicator.h"

// Logger
#import "ShinobiChartLog.h"

// Deprecations
#import "SChartAxis+Deprecated.h"