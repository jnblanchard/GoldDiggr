//
//  SChartActivityIndicator.h
//  ShinobiControls_Source
//
//  Copyright 2013 Scott Logic Ltd. All rights reserved.
//
//
#import <UIKit/UIKit.h>

/**
 SChart now offers you the option of loading data asynchronously.  If data is loading in the background, the chart displays an activity indicator while the data is being loaded.  The indicator can optionally adopt the SChartActivityIndicator protocol.
 
 SChartActivityIndicator is based on the API of the UIActivityIndicatorView.  As such, it offers methods to start and stop the indicator from animating.  It also offers a color property to allow you to style the indicator.
 */
@protocol SChartActivityIndicator <NSObject>

/** The color of the activity indicator. */
@property (nonatomic, retain) UIColor *color;

@required

/** Starts the activity indicator animating. */
- (void)startAnimating;

/** Stops the activity indicator animating. */
- (void)stopAnimating;

@end
