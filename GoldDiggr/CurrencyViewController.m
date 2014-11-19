//
//  CurrencyViewController.m
//  GoldDiggr
//
//  Created by John Blanchard on 11/18/14.
//  Copyright (c) 2014 John Blanchard. All rights reserved.
//

#import "CurrencyViewController.h"
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
@property NSArray* dataArray;
@property NSDate* minDate;
@property NSDate* maxDate;
@property NSDictionary* dict;
@property NSString* lastUsdString;
@property NSString* lastCurrencyString;
@property ShinobiChart* chart;
@property ShinobiChart* chartTwo;
@end

@implementation CurrencyViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.lastCurrencyString = @"";
    self.lastUsdString = @"";
    self.dict = @{@"Canadaian Dollar": @"DEXCAUS", @"Chinese Yuan": @"DEXCHUS", @"Denish Krone": @"DEXDNUS", @"Euro": @"DEXUSEU", @"Hong Kong Dollar": @"DEXHKUS", @"Indian Rupee": @"DEXINUS", @"Japanese Yen": @"DEXJPUS", @"Malaysian Ringgit": @"DEXMAUS", @"Mexican Peso": @"DEXMXUS", @"New Taiwan Dollar": @"DEXTAUS", @"New Zealand Dollar": @"DEXUSNZ", @"Norwegian Krone": @"DEXNOUS", @"Singapore Dollar": @"DEXSIUS", @"South African Rand": @"DEXSFUS", @"South Korean Won": @"DEXKOUS", @"Sri Lankan Rupee": @"DEXSLUS", @"Swedish Krona": @"DEXSDUS", @"Swiss Franc": @"DEXSZUS", @"Thai Baht": @"DEXTHUS", @"Venezuelan Bolivar": @"DEXVZUS"};
    self.currencies = [self.dict allKeys];
    self.exchangeRate = 2;
    self.currencies = @[@"MP", @"GMY", @"Euro", @"POL"];
    //    [self loadJSON];

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

        self.chart = [[ShinobiChart alloc] initWithFrame:CGRectInset(CGRectMake(0, 185, self.view.frame.size.width, self.view.frame.size.height - 230), 5, 5)];
        self.chart.title = @"Number of pesos in $1 USD";
        [self.chart applyTheme:[SChartLightTheme new]];
        SChartTitlePosition pos = SChartTitlePositionCenter;
        [self.chart setTitlePosition:pos];
    
        self.chart.licenseKey = @"hhrISctCkSMYEI5MjAxNDEyMTdqbmJsYW5jaGFyZEBtYWMuY29t0Jdf/vFaiXAaIF2H91a9+UT3uIrLZz/nVXe6I9A3C4Nh52uJ05Alb102w//Ce35VnqvkSk+Es6LF522O4bIgBK46t0HzUYZ0gygmnXrnADJSDnQVoGvgUrkqNfZ142rqiW7MKo57wbrndiTYuW205cQW157I=BQxSUisl3BaWf/7myRmmlIjRnMU2cA7q+/03ZX9wdj30RzapYANf51ee3Pi8m2rVW6aD7t6Hi4Qy5vv9xpaQYXF5T7XzsafhzS3hbBokp36BoJZg8IrceBj742nQajYyV7trx5GIw9jy/V6r0bvctKYwTim7Kzq+YPWGMtqtQoU=PFJTQUtleVZhbHVlPjxNb2R1bHVzPnh6YlRrc2dYWWJvQUh5VGR6dkNzQXUrUVAxQnM5b2VrZUxxZVdacnRFbUx3OHZlWStBK3pteXg4NGpJbFkzT2hGdlNYbHZDSjlKVGZQTTF4S2ZweWZBVXBGeXgxRnVBMThOcDNETUxXR1JJbTJ6WXA3a1YyMEdYZGU3RnJyTHZjdGhIbW1BZ21PTTdwMFBsNWlSKzNVMDg5M1N4b2hCZlJ5RHdEeE9vdDNlMD08L01vZHVsdXM+PEV4cG9uZW50PkFRQUI8L0V4cG9uZW50PjwvUlNBS2V5VmFsdWU+"; // TODO: add your trial licence key here!
        self.chart.autoresizingMask = ~UIViewAutoresizingNone;
    
        SChartDateRange* dateRange = [[SChartDateRange alloc]initWithDateMinimum:self.minDate andDateMaximum:self.maxDate];
        SChartDateTimeAxis* xAxis = [[SChartDateTimeAxis alloc]initWithRange:dateRange];
        self.chart.xAxis = xAxis;
    
    
    
        SChartNumberRange* rangeY = [[SChartNumberRange alloc]initWithMinimum:[NSNumber numberWithInt:1] andMaximum:[NSNumber numberWithInt:25]];
        SChartNumberAxis *yAxis = [[SChartNumberAxis alloc] initWithRange:rangeY];
        self.chart.yAxis = yAxis;
    
        [self.view addSubview:self.chart];
    
        self.chart.delegate = self;
        self.chart.datasource = self;
}

-(NSInteger)sChart:(ShinobiChart *)chart numberOfDataPointsForSeriesAtIndex:(NSInteger)seriesIndex
{
    return 20;
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
    [pointStyle setRadius:[NSNumber numberWithInt:10]];
    [pointStyle setInnerRadius:[NSNumber numberWithInt:6]];
    style.pointStyle = pointStyle;
    [style setLineColor:[UIColor greenColor]];
    [style setLineColorBelowBaseline:[UIColor redColor]];
    [lineSeries setStyle:style];
    return lineSeries;
}

-(id<SChartData>)sChart:(ShinobiChart *)chart dataPointAtIndex:(NSInteger)dataIndex forSeriesAtIndex:(NSInteger)seriesIndex
{
    SChartDataPoint *datapoint = [[SChartDataPoint alloc] init];

    NSDateComponents *comps = [[NSDateComponents alloc] init];
    [comps setDay:1];
    [comps setMonth:1];
    [comps setYear:2005];
    NSDate* temp = [[NSCalendar currentCalendar] dateFromComponents:comps];



    // both functions share the same x-values
    datapoint.xValue = temp;

    // compute the y-value for each series
    datapoint.yValue = [NSNumber numberWithInt:dataIndex+2];

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
    return [NSString stringWithFormat:@"http://www.quandl.com/api/v1/datasets/FRED/%@", [self.dict objectForKey:self.currencyButton.titleLabel.text]];
}

- (void) loadJSON
{
    self.dicts = [NSMutableDictionary new];
    self.dates = [NSMutableArray new];
    self.toUSDs = [NSMutableArray new];
    NSURLRequest * request = [NSURLRequest requestWithURL:[NSURL URLWithString:@"http://www.quandl.com/api/v1/datasets/FRED/DEXMXUS"]];
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *rsp, NSData *data, NSError *connectionError)
     {
         NSArray* temp = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
         NSArray* tempTwo = [temp valueForKey:@"data"];
         [self loadDates:tempTwo];
         [self displayData:tempTwo];
     }];
}

- (NSString*) breakApartTuple:(NSString*) tuple
{
    //    Data* data = [Data new];
    return @"";
}

- (void) loadDates:(NSArray*) temp
{
    for (id tuple in temp) {
        [self breakApartTuple:tuple];
        NSLog(@"At datapoint %lu, %@,", (unsigned long)[temp indexOfObject:tuple], tuple);
    }
}

- (void) displayData:(NSArray*) tempTwo
{
    //    NSLog(@"Value of Dolar in (Date , Peso) format - \n\n%@", tempTwo);
    //    NSLog(@"%@", [tempTwo objectAtIndex:1]);
    //    NSLog(@"%@", self.dates);
}

- (IBAction)editingBeganInTextField:(UITextField*)sender
{
    if (![self.usdTextField.text isEqualToString:@""] && ![self.currencyTextField.text isEqualToString:@""]) {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Cannot execute this conversion." message:@"Must have only one number input, and currency selected" delegate:self cancelButtonTitle:@"Dismiss" otherButtonTitles: nil];
        [alert show];
        NSLog(@"CAN ONLY HAVE ONE INPUT FIELD AT A TIME");
        [self setLastValuesInFields:sender];
    }
    NSNumberFormatter* formatter = [NSNumberFormatter new];
    NSNumber* number = [formatter numberFromString:sender.text];
    if (![sender.text isEqualToString:@""] && number == nil)
    {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Can only input number" message:@"Ex (1,2,3..8,9)" delegate:self cancelButtonTitle:@"Dismiss" otherButtonTitles: nil];
        [alert show];
        NSLog(@"HAVE TO USE NUMBER EX (13023.23");
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
    [self.currencyButton setTitle:[self.currencies objectAtIndex:row] forState:UIControlStateNormal];
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
    self._providerToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height - 344, self.view.bounds.size.width, 44)];

    UIBarButtonItem *done = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(dismissActionSheet:)];
    self._providerToolbar.items = @[[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil], done];
    [self._providerToolbar setTintColor:[UIColor whiteColor]];
    self._providerToolbar.barStyle = UIBarStyleBlack;
    [self.view addSubview:self._providerToolbar];

    self._providerPickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height - 300, 0, 0)];
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
        NSLog(@"%@ pesos, is equivalent to $%00f USD", self.currencyTextField.text, self.currencyTextField.text.doubleValue/self.exchangeRate);
    }
    if ([self.currencyTextField.text isEqualToString:@""])
    {
        NSLog(@"$%@ USD, is equivalent to %00f pesos", self.usdTextField.text, self.usdTextField.text.doubleValue*self.exchangeRate);
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
