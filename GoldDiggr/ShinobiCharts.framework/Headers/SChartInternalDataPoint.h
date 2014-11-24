//
//  SChartInternalDataPoint.h
//  SChart
//
//  Copyright (c) 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartData.h"
#import "SChartDataPoint.h"

@class SChartAxis;
@protocol SChartDataTransformer;

/* Internal data points */
@interface SChartInternalDataPoint : SChartDataPoint <SChartData>

- (id)initWithXAxisTransformer:(id<SChartDataTransformer>)xTransformer yAxisTransformer:(id<SChartDataTransformer>)yTransformer;

/* X values by key for series that require multiple values. */
@property (nonatomic, retain) NSDictionary *xValues;

/* Y values by key for series that require multiple values. */
@property (nonatomic, retain) NSDictionary *yValues;

/* Values by key for series that require values independent of axes.*/
@property (nonatomic, retain) NSMutableDictionary *values;


#pragma mark -
#pragma mark Texture
@property (nonatomic, retain) UIImage *texture;

#pragma mark -
#pragma mark Radius
@property (nonatomic, assign) float radius;

@property (nonatomic, assign) float innerRadius;


#pragma mark -
#pragma mark Coords
/* The x coordinate for this data point - calculate by the relevant axis */
@property (nonatomic, assign) double xCoord;

/* The y coordinate for this data point - calculate by the relevant axis */
@property (nonatomic, assign) double yCoord;

/* X coordinates by key for series that require multiple values. */
@property (nonatomic, retain) NSMutableDictionary *xCoords;

/* Y coordinates by key for series that require multiple values. */
@property (nonatomic, retain) NSMutableDictionary *yCoords;


#pragma mark -
#pragma mark Comparing values
/* @name Comparing values */
/* Compare the X component values of these two internal data points */
-(NSComparisonResult)compareXAsNumber:(SChartInternalDataPoint*)dp;

/* Compare the Y component values of these two internal data points */
-(NSComparisonResult)compareYAsNumber:(SChartInternalDataPoint*)dp;


#pragma mark -
#pragma mark Transform values
@property (nonatomic, assign) id<SChartDataTransformer> xAxisTransformer;
@property (nonatomic, assign) id<SChartDataTransformer> yAxisTransformer;

-(id<SChartData>)getExternalDatapoint;

@end
