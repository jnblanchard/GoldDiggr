//
//  CurrencyViewController.m
//  GoldDiggr
//
//  Created by John Blanchard on 11/18/14.
//  Copyright (c) 2014 John Blanchard. All rights reserved.
//

#import "CurrencyViewController.h"
#import "Data.h"
#import <ShinobiCharts/ShinobiCharts.h>

@interface CurrencyViewController () <UIPickerViewDataSource, UIPickerViewDelegate, SChartDatasource, SChartDelegate>
@property (weak, nonatomic) IBOutlet UITextField *usdTextField;
@property (weak, nonatomic) IBOutlet UIButton *currencyButton;
@property (weak, nonatomic) IBOutlet UITextField *currencyTextField;
@property NSMutableDictionary* dicts;
@property NSMutableArray* dates;
@property NSMutableArray* toUSDs;
@property NSMutableArray* dataSet;
@property double exchangeRate;
@property UIView* maskView;
@property UIPickerView* _providerPickerView;
@property UIToolbar *_providerToolbar;
@property NSArray* currencies;
@property NSMutableArray* dataArray;
@property NSMutableArray* dateArray;
@property NSDate* minDate;
@property NSDate* maxDate;
@property NSDictionary* dict;
@property NSString* lastUsdString;
@property NSString* lastCurrencyString;
@property ShinobiChart* chart;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *actIndicator;
@property (weak, nonatomic) IBOutlet UIButton *convertButton;
@property ShinobiChart* chartTwo;
@property NSString* exchangeCurrency;
@end

@implementation CurrencyViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.dataArray = [NSMutableArray new];
    self.dateArray = [NSMutableArray new];
    self.currencyButton.clipsToBounds = YES;
    self.currencyButton.layer.cornerRadius = 20;
    self.currencyButton.layer.borderWidth = 2.0f;
    self.currencyButton.layer.borderColor = [UIColor blackColor].CGColor;
    self.convertButton.clipsToBounds = YES;
    self.convertButton.layer.cornerRadius = 10;
    self.convertButton.layer.borderWidth = 2.0f;
    self.convertButton.layer.borderColor = [UIColor blackColor].CGColor;
    self.exchangeCurrency = @"Currency";
    self.lastCurrencyString = @"";
    self.lastUsdString = @"";
    self.dict = @{@"Canadaian Dollar": @"DEXCAUS", @"Chinese Yuan": @"DEXCHUS", @"Denish Krone": @"DEXDNUS", @"Euro": @"DEXUSEU", @"Hong Kong Dollar": @"DEXHKUS", @"Indian Rupee": @"DEXINUS", @"Japanese Yen": @"DEXJPUS", @"Malaysian Ringgit": @"DEXMAUS", @"Mexican Peso": @"DEXMXUS", @"New Taiwan Dollar": @"DEXTAUS", @"New Zealand Dollar": @"DEXUSNZ", @"Norwegian Krone": @"DEXNOUS", @"Singapore Dollar": @"DEXSIUS", @"South African Rand": @"DEXSFUS", @"South Korean Won": @"DEXKOUS", @"Sri Lankan Rupee": @"DEXSLUS", @"Swedish Krona": @"DEXSDUS", @"Swiss Franc": @"DEXSZUS", @"Thai Baht": @"DEXTHUS", @"Venezuelan Bolivar": @"DEXVZUS"};
    self.currencies = [self.dict allKeys];
    NSLog(@"%@", self.currencies);
    self.exchangeRate = 2;
    //    [self loadJSON];

    [self makeChart:@"Placeholder Dataset"];
}

- (void) makeChart:(NSString*) title
{
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
    NSLog(@" Max DATE - %@", self.maxDate);

    self.chart = [[ShinobiChart alloc] initWithFrame:CGRectInset(CGRectMake(self.view.frame.origin.x, self.view.frame.origin.y + 69, self.view.frame.size.width, self.view.frame.size.height - 264), 3, 0)];
    [self.chart setTitle:title];
    [self.chart applyTheme:[SChartLightTheme new]];
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
        NSString* min = [self.dateArray lastObject];
        NSString* max = [self.dateArray firstObject];
        dateRange = [[SChartDateRange alloc]initWithDateMinimum:min andDateMaximum:max];
        xAxis = [[SChartDateTimeAxis alloc]initWithRange:dateRange];
        rangeY = [[SChartNumberRange alloc]initWithMinimum:[NSNumber numberWithInt:1] andMaximum:[NSNumber numberWithInt:150]];
        yAxis = [[SChartNumberAxis alloc] initWithRange:rangeY];
    }

    self.chart.xAxis = xAxis;
    self.chart.yAxis = yAxis;
    self.chart.xAxis.titleLabel.text = @"Year";
    self.chart.yAxis.titleLabel.text = [NSString stringWithFormat:@"# of %@s in $1USD", self.exchangeCurrency];
    [self.view addSubview:self.chart];

    self.chart.delegate = self;
    self.chart.datasource = self;
}

- (NSString*) setChartTitle:(NSString*)input
{
    self.exchangeCurrency = input;
    return [NSString stringWithFormat:@"Historical Price of %@", input];
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
    lineSeries.baseline = [NSNumber numberWithInt:10];

    SChartLineSeriesStyle* style = [[SChartLineSeriesStyle alloc] init];
    [style setLineWidth:[NSNumber numberWithInt:3]];
    SChartPointStyle* pointStyle = [SChartPointStyle new];
    pointStyle.color = [UIColor greenColor];
    pointStyle.colorBelowBaseline = [UIColor redColor];
    pointStyle.showPoints = YES;
    [pointStyle setRadius:[NSNumber numberWithInt:3]];
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
        [comps setYear:2005];
        NSDate* temp = [[NSCalendar currentCalendar] dateFromComponents:comps];
        datapoint.xValue = temp; // date
        datapoint.yValue = [NSNumber numberWithInt:dataIndex+2]; // price
    } else {
        datapoint.xValue = [self.dateArray objectAtIndex:dataIndex];
        datapoint.yValue = [self.dataArray objectAtIndex:dataIndex];
    }


    return datapoint;
}

- (void) setLastValuesInFields:(UITextField*) input
{
    if ([self.usdTextField isEqual:input]) {
        self.usdTextField.text = self.lastUsdString;
    } else {
        self.currencyTextField.text = self.lastCurrencyString;
    }
}

- (NSString*) makeJSONRequestString
{
//    return [NSString stringWithFormat:@"http://www.quandl.com/api/v1/datasets/FRED/%@", [self.dict objectForKey: self.currencyButton.titleLabel.text]];
    return [NSString stringWithFormat:@"http://www.quandl.com/api/v1/datasets/FRED/%@?%@", [self.dict objectForKey:self.currencyButton.titleLabel.text], [NSString stringWithFormat:@"auth_token=9unyjxegjy4_K2pG1LLx"]];
}

- (void) loadJSON:(NSString*)apiKey withIndex:(int) index
{
    self.dicts = [NSMutableDictionary new];
    self.dates = [NSMutableArray new];
    self.toUSDs = [NSMutableArray new];
    NSURLRequest * request = [NSURLRequest requestWithURL:[NSURL URLWithString:[self makeJSONRequestString]]];
    [self.actIndicator startAnimating];
    [self.view bringSubviewToFront:self.actIndicator];
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *rsp, NSData *data, NSError *connectionError)
     {
         if (connectionError) {
             NSLog(@"You have a connection error.");
         }
         if ([data isEqual:nil]) {
             NSLog(@"No data exists");
         }
         NSArray* temp = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
         NSArray* tempTwo = [temp valueForKey:@"data"];
         [self loadDates:tempTwo];
         [self.actIndicator stopAnimating];
         [self.view sendSubviewToBack:self.actIndicator];
         [self.maskView removeFromSuperview];
         [self._providerPickerView removeFromSuperview];
         [self._providerToolbar removeFromSuperview];
         [self makeChart:[self setChartTitle:[self.currencies objectAtIndex:index]]];

     }];
}

- (void) breakApartTuple:(NSArray*) tuple
{
    Data* data = [Data new];
//    NSString* wholeDate = [tuple firstObject];
//    NSLog(@"%@", wholeDate);
//    int day = [wholeDate substringWithRange:NSMakeRange(5, 6)].intValue;
//    int month = [wholeDate substringWithRange:NSMakeRange(7, 9)].intValue;
//    int year = [wholeDate substringToIndex:4].intValue;
//    NSLog(@"day - %d", day);
//    NSLog(@"month - %d", month);
//    NSLog(@"year - %d \n\n", year);
//    NSDateComponents *comps = [[NSDateComponents alloc] init];
//    [comps setDay:1];
//    [comps setMonth:1];
//    [comps setYear:2005];
//    NSDate* temp = [[NSCalendar currentCalendar] dateFromComponents:comps];
    data.date = [tuple firstObject];
    NSNumber* num = [tuple lastObject];
    data.data = num.doubleValue;
//    NSLog(@"%@", [data.date isKindOfClass:[NSDate class]]);
    [self.dataArray addObject:num];
    [self.dateArray addObject:[tuple firstObject]];
}

- (void) loadDates:(NSArray*) temp
{

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
        NSNumber* num = [tuple lastObject];
        [self.dataArray addObject:num];
        [self.dateArray addObject:temp];
    }
    NSNumber* num = [self.dataArray firstObject];
    self.exchangeRate = num.doubleValue;
}

- (IBAction)editingBeganInTextField:(UITextField*)sender
{
    if (![self.usdTextField.text isEqualToString:@""] && ![self.currencyTextField.text isEqualToString:@""]) {
        NSLog(@"WARNING: CAN ONLY HAVE ONE INPUT FIELD AT A TIME");
        [self setLastValuesInFields:sender];
    }
    NSNumberFormatter* formatter = [NSNumberFormatter new];
    NSNumber* number = [formatter numberFromString:sender.text];
    if (![sender.text isEqualToString:@""] && number == nil)
    {
        NSLog(@"WARNING: HAVE TO USE NUMBER EX (13023.23");
        [self setLastValuesInFields:sender];
    } else {
        if ([sender isEqual:self.usdTextField]) {
            self.lastUsdString = self.usdTextField.text;
        } else {
            self.lastCurrencyString = self.currencyTextField.text;
        }
    }
}

- (IBAction)currencyButtonHit:(id)sender
{
    [self.usdTextField resignFirstResponder];
    [self createPickerView];

}

-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}


-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    self.dateArray = [NSMutableArray new];
    self.dataArray = [NSMutableArray new];
    [self.currencyButton setTitle:[self.currencies objectAtIndex:row] forState:UIControlStateNormal];
    [self loadJSON:[self.dict valueForKey:[self.currencies objectAtIndex:row]]withIndex:row];
    [self.chart removeFromSuperview];
    [self.view sendSubviewToBack:self.chart];
}

-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return self.currencies.count;
}

-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [self.currencies objectAtIndex:row];
}

- (void) createPickerView {
    self.maskView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
    [self.maskView setBackgroundColor:[UIColor clearColor]];

    [self.view addSubview:self.maskView];
    self._providerToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height - 294, self.view.bounds.size.width, 44)];

    UIBarButtonItem *done = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(dismissActionSheet:)];
    self._providerToolbar.items = @[[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil], done];
    [self._providerToolbar setTintColor:[UIColor whiteColor]];
    self._providerToolbar.barStyle = UIBarStyleBlack;
    [self.view addSubview:self._providerToolbar];

    self._providerPickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height-250, 0, 0)];
    self._providerPickerView.backgroundColor = [UIColor whiteColor];
    self._providerPickerView.showsSelectionIndicator = YES;
    self._providerPickerView.dataSource = self;
    self._providerPickerView.delegate = self;

    [self.view addSubview:self._providerPickerView];

}

- (void)dismissActionSheet:(id)sender{
    [self.maskView removeFromSuperview];
    [self._providerPickerView removeFromSuperview];
    [self._providerToolbar removeFromSuperview];
}


- (IBAction)convertButtonPressed:(id)sender
{
    if ([self.usdTextField.text isEqualToString:@""])
    {
        NSLog(@"%@ %@, is equivalent to $%00f USD", self.currencyTextField.text, self.exchangeCurrency, self.currencyTextField.text.doubleValue/self.exchangeRate);
    }
    if ([self.currencyTextField.text isEqualToString:@""])
    {
        NSLog(@"$%@ USD, is equivalent to %00f %@", self.usdTextField.text, self.usdTextField.text.doubleValue*self.exchangeRate, self.exchangeCurrency);
    }
}

- (IBAction)currencyResetButtonPressed:(id)sender
{
    self.currencyTextField.text = @"";
    self.lastCurrencyString = @"";
}

- (IBAction)resetButtonPressed:(id)sender
{
    self.usdTextField.text = @"";
    self.lastUsdString = @"";
}

@end
