//
//  EconGoodViewController.m
//  GoldDiggr
//
//  Created by John Blanchard on 11/18/14.
//  Copyright (c) 2014 John Blanchard. All rights reserved.
//

#import "EconGoodViewController.h"
@interface EconGoodViewController () <UIPickerViewDataSource, UIPickerViewDelegate, UINavigationControllerDelegate>
@property (weak, nonatomic) IBOutlet UITextField *usdTextField;
@property (weak, nonatomic) IBOutlet UIButton *economicGoodButton;
@property UIView* maskView;
@property UIPickerView* _providerPickerView;
@property UIToolbar *_providerToolbar;
@property NSArray* goods;
@property double exchangeRate;
@end

@implementation EconGoodViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.goods = @[@"Gold",@"Silver",@"AZ",@"AR",@"CA",@"CO",@"CT",@"DE",@"FL",@"GA",@"HI",@"ID",@"IL",@"IN",@"IA",@"KS",@"KP",@"LA",@"ME",@"MD",@"MA",@"MI",@"MN",@"MS",@"MO",@"MT",@"NE",@"NV",@"NH",@"NJ",@"NM",@"NY"];
}

- (IBAction)economicGoodButtonPressed:(id)sender
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
    [self.economicGoodButton setTitle:[self.goods objectAtIndex:row] forState:UIControlStateNormal];
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

- (IBAction)checkTextField:(UITextField*)sender
{
    NSNumberFormatter* formatter = [NSNumberFormatter new];
    NSNumber* number = [formatter numberFromString:sender.text];
    if (![sender.text isEqualToString:@""] && number != nil)
    {
        NSLog(@"$%@ USD is equal to %fOZ of %@", self.usdTextField.text, self.usdTextField.text.doubleValue*self.exchangeRate,self.economicGoodButton.titleLabel.text );
    }
}

@end
