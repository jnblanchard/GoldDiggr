//
//  EconGoodViewController.m
//  GoldDiggr
//
//  Created by John Blanchard on 11/18/14.
//  Copyright (c) 2014 John Blanchard. All rights reserved.
//

#import "EconGoodViewController.h"
#import <ShinobiCharts/ShinobiCharts.h>

@interface EconGoodViewController () <UIPickerViewDataSource, UIPickerViewDelegate, UINavigationControllerDelegate, SChartDatasource, SChartDelegate>
@property (weak, nonatomic) IBOutlet UITextField *usdTextField;
@property (weak, nonatomic) IBOutlet UIButton *economicGoodButton;
@property UIView* maskView;
@property UIPickerView* _providerPickerView;
@property UIToolbar *_providerToolbar;
@property NSArray* goods;
@property double exchangeRate;
@property ShinobiChart* chart;
@property ShinobiChart* chartTwo;
@property NSDate* minDate;
@property NSDate* maxDate;
@property NSMutableArray* dataArray;
@property NSMutableArray* dateArray;
@property NSDictionary* dict;
@property int year;
@property int max;
@property (weak, nonatomic) IBOutlet UIButton *printDataButton;
@property NSArray* items;
@property int theIndex;
@property NSString* lastText;
@end

@implementation EconGoodViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.lastText = @"";
    self.year = 1983;
    self.max = 0;
    self.dataArray = [NSMutableArray new];
    self.dateArray = [NSMutableArray new];
    self.items = @[@"Cotton", @"Milk", @"Sugar"];
    self.economicGoodButton.clipsToBounds = YES;
    self.economicGoodButton.layer.borderColor = [UIColor blackColor].CGColor;
    self.economicGoodButton.layer.borderWidth = 2.0f;
    self.economicGoodButton.layer.cornerRadius = 30;
    self.printDataButton.clipsToBounds = YES;
    self.printDataButton.layer.borderColor = [UIColor blackColor].CGColor;
    self.printDataButton.layer.borderWidth = 2.0f;
    self.printDataButton.layer.cornerRadius = 10;
    self.dict = @{@"Milk per lb": @"WSJ/MILK", @"Cotton per lb": @"ODA/PCOTTIND_USD", @"Sugar per lb": @"ODA/PSUGAUSA_USD"};
    self.goods = [self.dict allKeys];
//    [self makeChart:@"Placeholder Dataset"];
    self.theIndex = 2;
    [self.economicGoodButton setTitle:[self.goods objectAtIndex:self.theIndex] forState:UIControlStateNormal];
    [self loadJSON:[self.dict valueForKey:[self.goods objectAtIndex:self.theIndex]]withIndex:self.theIndex];
    self.exchangeRate = 2;
//    [self loadJSON:@"Potassium Choloride" withIndex:1];
}

- (void) makeChart:(NSString*) title
{
    NSLog(@"Making Chart with title: %@", title);
    NSDateComponents *comps = [[NSDateComponents alloc] init];
    [comps setDay:1];
    [comps setMonth:1];
    [comps setYear:1993];
    self.minDate = [[NSCalendar currentCalendar] dateFromComponents:comps];

    NSDateComponents *temp = [[NSDateComponents alloc] init];
    [temp setDay:31];
    [temp setMonth:12];
    [temp setYear:2014];
    self.maxDate = [[NSCalendar currentCalendar] dateFromComponents:temp];

    self.chart = [[ShinobiChart alloc] initWithFrame:CGRectInset(CGRectMake(self.view.frame.origin.x, self.view.frame.origin.y + 68, self.view.frame.size.width, self.view.frame.size.height - 231), 1, 0)];
    [self.chart setTitle:title];
    [self.chart applyTheme:[SChartDarkTheme new]];
    SChartTitlePosition pos = SChartTitlePositionCenter;
    [self.chart setTitlePosition:pos];

    self.chart.licenseKey = @"hhrISctCkSMYEI5MjAxNDEyMTdqbmJsYW5jaGFyZEBtYWMuY29t0Jdf/vFaiXAaIF2H91a9+UT3uIrLZz/nVXe6I9A3C4Nh52uJ05Alb102w//Ce35VnqvkSk+Es6LF522O4bIgBK46t0HzUYZ0gygmnXrnADJSDnQVoGvgUrkqNfZ142rqiW7MKo57wbrndiTYuW205cQW157I=BQxSUisl3BaWf/7myRmmlIjRnMU2cA7q+/03ZX9wdj30RzapYANf51ee3Pi8m2rVW6aD7t6Hi4Qy5vv9xpaQYXF5T7XzsafhzS3hbBokp36BoJZg8IrceBj742nQajYyV7trx5GIw9jy/V6r0bvctKYwTim7Kzq+YPWGMtqtQoU=PFJTQUtleVZhbHVlPjxNb2R1bHVzPnh6YlRrc2dYWWJvQUh5VGR6dkNzQXUrUVAxQnM5b2VrZUxxZVdacnRFbUx3OHZlWStBK3pteXg4NGpJbFkzT2hGdlNYbHZDSjlKVGZQTTF4S2ZweWZBVXBGeXgxRnVBMThOcDNETUxXR1JJbTJ6WXA3a1YyMEdYZGU3RnJyTHZjdGhIbW1BZ21PTTdwMFBsNWlSKzNVMDg5M1N4b2hCZlJ5RHdEeE9vdDNlMD08L01vZHVsdXM+PEV4cG9uZW50PkFRQUI8L0V4cG9uZW50PjwvUlNBS2V5VmFsdWU+"; // TODO: add your trial licence key here!
    self.chart.autoresizingMask = ~UIViewAutoresizingNone;

    SChartDateRange* dateRange;
    SChartDateTimeAxis* xAxis;
    SChartNumberRange* rangeY;
    SChartNumberAxis* yAxis;
    if (self.dataArray.count == 0) {
        dateRange = [[SChartDateRange alloc]initWithDateMinimum:self.minDate andDateMaximum:self.maxDate];
        xAxis = [[SChartDateTimeAxis alloc]initWithRange:dateRange];
        rangeY = [[SChartNumberRange alloc]initWithMinimum:[NSNumber numberWithInt:1] andMaximum:[NSNumber numberWithInt:25]];
        yAxis = [[SChartNumberAxis alloc] initWithRange:rangeY];
    } else {
        NSDate* min = [self.dateArray lastObject];
        NSDate* max = [self.dateArray firstObject];
        dateRange = [[SChartDateRange alloc]initWithDateMinimum:min andDateMaximum:max];
        xAxis = [[SChartDateTimeAxis alloc]initWithRange:dateRange];
        rangeY = [[SChartNumberRange alloc]initWithMinimum:[NSNumber numberWithInt:1] andMaximum:[NSNumber numberWithInt:self.max]];
        yAxis = [[SChartNumberAxis alloc] initWithRange:rangeY];
    }

    self.chart.xAxis = xAxis;
    self.chart.yAxis = yAxis;
    self.chart.xAxis.titleLabel.text = @"Year";
    self.chart.yAxis.titleLabel.text = [NSString stringWithFormat:@"USD cents", self.exchangeRate];
    [self.view addSubview:self.chart];
    self.chart.delegate = self;
    self.chart.datasource = self;
}

-(NSInteger)sChart:(ShinobiChart *)chart numberOfDataPointsForSeriesAtIndex:(NSInteger)seriesIndex
{
    if (self.dataArray.count == 0) {
        return 20;

    } else {
        return self.dataArray.count;
    }
}

-(NSInteger)numberOfSeriesInSChart:(ShinobiChart *)chart
{
    return 1;

}

-(SChartSeries *)sChart:(ShinobiChart *)chart seriesAtIndex:(NSInteger)index
{
    SChartLineSeries *lineSeries = [[SChartLineSeries alloc] init];
    lineSeries.baseline = [NSNumber numberWithInt:1];

    SChartLineSeriesStyle* style = [[SChartLineSeriesStyle alloc] init];
    [style setLineWidth:[NSNumber numberWithInt:3]];
    SChartPointStyle* pointStyle = [SChartPointStyle new];
    pointStyle.color = [UIColor greenColor];
    pointStyle.colorBelowBaseline = [UIColor redColor];
    pointStyle.showPoints = YES;
    [pointStyle setRadius:[NSNumber numberWithInt:4]];
    [pointStyle setInnerRadius:[NSNumber numberWithInt:1]];
    style.pointStyle = pointStyle;
    [style setLineColor:[UIColor greenColor]];
    [style setLineColorBelowBaseline:[UIColor redColor]];
    [lineSeries setStyle:style];
    return lineSeries;
}

-(id<SChartData>)sChart:(ShinobiChart *)chart dataPointAtIndex:(NSInteger)dataIndex forSeriesAtIndex:(NSInteger)seriesIndex
{
    SChartDataPoint *datapoint = [[SChartDataPoint alloc] init];
    if (self.dataArray.count == 0) {
        NSDateComponents *comps = [[NSDateComponents alloc] init];
        [comps setDay:1];
        [comps setMonth:1];
        [comps setYear:self.year];
        NSDate* temp = [[NSCalendar currentCalendar] dateFromComponents:comps];
        datapoint.xValue = temp; // date
        datapoint.yValue = [NSNumber numberWithInt:dataIndex+2]; // price
        self.year+=2;
    } else {
        datapoint.xValue = [self.dateArray objectAtIndex:dataIndex];
        datapoint.yValue = [self.dataArray objectAtIndex:dataIndex];
    }


    return datapoint;
}

- (NSString*) makeJSONRequestString
{
    //    return [NSString stringWithFormat:@"http://www.quandl.com/api/v1/datasets/FRED/%@", [self.dict objectForKey: self.currencyButton.titleLabel.text]];
    return [NSString stringWithFormat:@"http://www.quandl.com/api/v1/datasets/%@?%@", [self.dict objectForKey:self.economicGoodButton.titleLabel.text], [NSString stringWithFormat:@"auth_token=9unyjxegjy4_K2pG1LLx"]];
}

- (void) loadJSON:(NSString*)apiKey withIndex:(int) index
{
    NSURLRequest * request = [NSURLRequest requestWithURL:[NSURL URLWithString:[self makeJSONRequestString]]];
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *rsp, NSData *data, NSError *connectionError)
     {
         if (connectionError) {
             NSLog(@"You have a connection error.");
         }
         if ([data isEqual:nil]) {
             NSLog(@"No data exists");
         }
         NSArray* temp = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
//         NSLog(@"%@", temp);
         NSArray* tempTwo = [temp valueForKey:@"data"];
//         NSLog(@"%@", tempTwo);
         [self loadDates:tempTwo];
         [self.maskView removeFromSuperview];
         [self._providerPickerView removeFromSuperview];
         [self._providerToolbar removeFromSuperview];
         [self makeChart:[self setChartTitle:[self.goods objectAtIndex:index]]];
         [self.chart reloadData];

     }];
}

- (NSString*) setChartTitle:(NSString*)input
{
    return [NSString stringWithFormat:@"Price of %@", input];
}

- (void) loadDates:(NSArray*) temp
{
    self.max = 0;
    for (NSArray* tuple in temp) {
        NSString* dateString = [tuple firstObject];
        NSMutableArray *list = [NSMutableArray array];
        for (int i=0; i<dateString.length; i++) {
            [list addObject:[dateString substringWithRange:NSMakeRange(i, 1)]];
        }
        NSDateComponents *comps = [[NSDateComponents alloc] init];
        [comps setDay:[NSString stringWithFormat:@"%@%@", [list objectAtIndex:5], [list objectAtIndex:6]].intValue];
        [comps setMonth:[NSString stringWithFormat:@"%@%@", [list objectAtIndex:7], [list objectAtIndex:8]].intValue];
        [comps setYear:[NSString stringWithFormat:@"%@%@%@%@", [list objectAtIndex:0], [list objectAtIndex:1], [list objectAtIndex:2], [list objectAtIndex:3]].intValue];
        NSDate* temp = [[NSCalendar currentCalendar] dateFromComponents:comps];
        NSNumber* tempNum = [tuple lastObject];
        [self.dataArray addObject:tempNum];
        if (tempNum.intValue > self.max-5) {
            self.max = tempNum.intValue+5;
        }
        [self.dateArray addObject:temp];
    }
    NSNumber* num = [self.dataArray firstObject];
    self.exchangeRate = num.doubleValue;
}

- (IBAction)economicGoodButtonPressed:(id)sender
{
    [self.usdTextField resignFirstResponder];
    [self createPickerView];
}

- (IBAction)eraseButtonPressed:(id)sender
{
    self.usdTextField.text = @"";
    self.lastText = @"";
}

-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    self.theIndex = row;
    [self.chart removeFromSuperview];
    [self.economicGoodButton setTitle:[self.goods objectAtIndex:row] forState:UIControlStateNormal];
    self.dateArray = [NSMutableArray new];
    self.dataArray = [NSMutableArray new];
    [self loadJSON:[self.dict valueForKey:[self.goods objectAtIndex:row]]withIndex:row];
}

-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return self.goods.count;
}

-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [self.goods objectAtIndex:row];
}

- (void) createPickerView {
    self.maskView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
    [self.maskView setBackgroundColor:[UIColor clearColor]];

    [self.view addSubview:self.maskView];
    self._providerToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height - 294, self.view.bounds.size.width, 44)];

    UIBarButtonItem *done = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(dismissActionSheet:)];
    [done setTintColor:[UIColor yellowColor]];
    self._providerToolbar.items = @[[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil], done];
    [self._providerToolbar setTintColor:[UIColor whiteColor]];
    self._providerToolbar.barStyle = UIBarStyleBlackOpaque;
    [self.view addSubview:self._providerToolbar];

    self._providerPickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height-250, 0, 0)];
    self._providerPickerView.backgroundColor = [UIColor whiteColor];
    self._providerPickerView.showsSelectionIndicator = YES;
    self._providerPickerView.dataSource = self;
    self._providerPickerView.delegate = self;

    [self.view addSubview:self._providerPickerView];

}

- (IBAction)convertButtonPressed:(id)sender
{
    if (![self.usdTextField.text isEqualToString:@""]) {
        double convertToCents = self.usdTextField.text.intValue * 100;
        double conversion = (double)convertToCents/(double)self.exchangeRate;
        NSLog(@"$%@ is %0.2f lbs of %@", self.usdTextField.text, conversion, [self.items objectAtIndex:self.theIndex]);
    }
}

- (void)dismissActionSheet:(id)sender{
    [self.maskView removeFromSuperview];
    [self._providerPickerView removeFromSuperview];
    [self._providerToolbar removeFromSuperview];
}

- (IBAction)checkTextField:(UITextField*)sender
{
    NSNumberFormatter* formatter = [NSNumberFormatter new];
    NSNumber* number = [formatter numberFromString:sender.text];
    if (![sender.text isEqualToString:@""] && number != nil)
    {
        self.lastText = self.usdTextField.text;
    }
    if (![sender.text isEqualToString:@""] && number == nil)
    {
        self.usdTextField.text = self.lastText;
        NSLog(@"Input must be numbers only Ex (32.125324)");
    }
}

@end
