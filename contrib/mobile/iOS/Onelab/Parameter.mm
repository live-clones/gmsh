//
//  parameter.m
//  Onelab
//
//  Created by Maxime Graulich on 07/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "parameter.h"

@implementation Parameter
-(id)init
{
    self = [super init];
    if(self)
    {
        label = [[UILabel alloc] init];
        [label setBackgroundColor:[UIColor clearColor]];
    }
    return self;
}
-(void)refresh
{
	return;
}
-(NSString *)getName
{
    return name;
}
-(UILabel *)getLabel
{
    return label;
}
-(void)setFrame:(CGRect)frame
{
    return;
}
-(void)setLabelFrame:(CGRect)frame
{
    [label setFrame:frame];
}
-(bool)isReadOnly
{
    return NO;
}
+(double)getHeight
{
    return 60.0f;
}
@end

@implementation ParameterStringList
-(id) initWithString:(onelab::string)string
{
    self = [super init];
    if(self)
    {
        label.alpha = (string.getReadOnly())? 0.439216f : 1.0f;
        [label setText:(string.getLabel() != "")?[NSString stringWithCString:string.getLabel().c_str() encoding:[NSString defaultCStringEncoding]] : [[[NSString stringWithCString:string.getName().c_str() encoding:[NSString defaultCStringEncoding]] componentsSeparatedByString:@"/"] lastObject]];
        name = [NSString stringWithCString:string.getName().c_str() encoding:[NSString defaultCStringEncoding]];
        picker = [[UIPickerView alloc] init];
        picker.showsSelectionIndicator = YES;
        [picker setDataSource:self];
        [picker setDelegate:self];
		bool valueInChoices = true;
        for(int row=0;row<string.getChoices().size();row++){
            if(string.getValue() == string.getChoices()[row]) {
				[picker selectRow:row inComponent:0 animated:NO];
				valueInChoices = false;
			}
		}
		if(valueInChoices) [picker selectRow:string.getChoices().size() inComponent:0 animated:YES];
    }
    return self;
}
-(void)refresh
{
	[picker reloadAllComponents];
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}
-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string,[name UTF8String]);
    if(string.size() < 1) return 0;
	bool valueInChoices = true;
	for(int row=0;row<string[0].getChoices().size();row++) if(string[0].getValue() == string[0].getChoices()[row])valueInChoices=false;
	if(valueInChoices) return string[0].getChoices().size()+1;
    return string[0].getChoices().size();
}
-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string,[name UTF8String]);
    if(string.size() < 1) return @"NULL";
	if(row >= string[0].getChoices().size()) return [NSString stringWithCString:string[0].getValue().c_str() encoding:[NSString defaultCStringEncoding]];
    return [NSString stringWithCString:string[0].getChoices()[row].c_str() encoding:[NSString defaultCStringEncoding]];
}
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string,[name UTF8String]);
    if(string.size() < 1) return;
    std::string selected = string[0].getChoices()[row];
    string[0].setValue(selected);
    onelab::server::instance()->set(string[0]);
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
-(void)setFrame:(CGRect)frame
{
    [picker setFrame:frame];
}
-(UIPickerView *)getList
{
    return picker;
}
-(bool)isReadOnly
{
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string,[name UTF8String]);
    if(string.size() < 1) return YES;
    return string[0].getReadOnly();
}
+(double)getHeight
{
    return 210.0f;
}
@end

@implementation ParameterNumberList
-(id) initWithNumber:(onelab::number) number
{
    self = [super init];
    if(self)
    {
        label.alpha = (number.getReadOnly())? 0.439216f : 1.0f;
        [label setText:(number.getLabel() != "")?[NSString stringWithCString:number.getLabel().c_str() encoding:[NSString defaultCStringEncoding]] : [[[NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]] componentsSeparatedByString:@"/"] lastObject]];
        name = [NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]];
        picker = [[UIPickerView alloc] init];
        picker.showsSelectionIndicator = YES;
        [picker setDataSource:self];
        [picker setDelegate:self];
        for(int row=0;row<number.getChoices().size();row++)
            if(number.getValue() == number.getChoices()[row])[picker selectRow:row inComponent:0 animated:NO];
    }
    return self;
}
-(void)refresh
{
	[picker reloadAllComponents];
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}
-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return 0;
    return number[0].getChoices().size();
}
-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return @"NULL";
    return [NSString stringWithCString:number[0].getValueLabel(number[0].getChoices()[row]).c_str() encoding:[NSString defaultCStringEncoding]];
}
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return;
    double selected = number[0].getChoices()[row];
    number[0].setValue(selected);
    onelab::server::instance()->set(number[0]);
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
-(void)setFrame:(CGRect)frame
{
    [picker setFrame:frame];
}
-(UIPickerView *)getList
{
    return picker;
}
-(bool)isReadOnly
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return YES;
    return number[0].getReadOnly();
}
+(double)getHeight
{
    return 210.0f;
}
@end

@implementation ParameterNumberCheckbox
-(id) initWithNumber:(onelab::number) number
{
    self = [super init];
    if(self)
    {
        label.alpha = (number.getReadOnly())? 0.439216f : 1.0f;
        [label setText:(number.getLabel() != "")?[NSString stringWithCString:number.getLabel().c_str() encoding:[NSString defaultCStringEncoding]] : [[[NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]] componentsSeparatedByString:@"/"] lastObject]];
        name = [NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]];
        checkbox = [[UISwitch alloc] init];
        [checkbox setSelected:(number.getValue() == 1)];
        [checkbox addTarget:self action:@selector(valueChange:) forControlEvents:UIControlEventValueChanged];
    }
    return self;
}
-(void)refresh
{
	std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    [checkbox setSelected:(number[0].getValue() == 1)];
}
-(void) valueChange:(UISwitch *)sender
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return;
    number[0].setValue(([sender isOn])? 1 : 0);
    onelab::server::instance()->set(number[0]);
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
-(void)setFrame:(CGRect)frame
{
    [checkbox setFrame:frame];
}
-(UISwitch *)getCheckbox
{
    return checkbox;
}
-(bool)isReadOnly
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return YES;
    return number[0].getReadOnly();
}
+(double)getHeight
{
    return 40.0f;
}
@end

@implementation ParameterNumberRange
-(id) initWithNumber:(onelab::number) number
{
    self = [super init];
    if(self)
    {
        label.alpha = (number.getReadOnly())? 0.439216f : 1.0f;
        name = [NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]];
        slider = [[UISlider alloc] init];
        [slider setMaximumValue:number.getMax()];
        [slider setMinimumValue:number.getMin()];
        [slider setValue:number.getValue()];
        //TODO add step ?
        [slider addTarget:self action:@selector(sliderValueChanged:) forControlEvents:UIControlEventTouchUpOutside];
        [slider addTarget:self action:@selector(sliderValueChanged:) forControlEvents:UIControlEventTouchUpInside];
        [label setText:[NSString stringWithFormat:@"%@ %f" ,(number.getLabel() != "")?[NSString stringWithCString:number.getLabel().c_str() encoding:[NSString defaultCStringEncoding]] : [[[NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]] componentsSeparatedByString:@"/"] lastObject], number.getValue()]];
    }
    return self;
}
-(void)refresh
{
	std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return;
	[slider setMaximumValue:number[0].getMax()];
	[slider setMinimumValue:number[0].getMin()];
	[slider setValue:number[0].getValue()];
}
-(void)sliderValueChanged:(UISlider *)sender
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return;
    number[0].setValue(sender.value);
    onelab::server::instance()->set(number[0]);
    [label setText:[NSString stringWithFormat:@"%s %f" ,(number[0].getLabel() != "")?number[0].getLabel().c_str():number[0].getName().c_str(), number[0].getValue()]];
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
-(void)setFrame:(CGRect)frame
{
    [slider setFrame:frame];
}
-(UISlider *)getSlider
{
    return slider;
}
-(bool)isReadOnly
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return YES;
    return number[0].getReadOnly();
}
+(double)getHeight
{
    return 60.0f;
}
@end

@implementation ParameterNumberTextbox
-(id)initWithNumber:(onelab::number)number
{
    self = [super init];
    if(self)
    {
        label.alpha = (number.getReadOnly())? 0.439216f : 1.0f;
        [label setText:(number.getLabel() != "")?[NSString stringWithCString:number.getLabel().c_str() encoding:[NSString defaultCStringEncoding]] : [[[NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]] componentsSeparatedByString:@"/"] lastObject]];
        name = [NSString stringWithCString:number.getName().c_str() encoding:[NSString defaultCStringEncoding]];
        textbox = [[UITextField alloc] init];
        [textbox setBorderStyle:UITextBorderStyleRoundedRect];
        [textbox setKeyboardType:UIKeyboardTypeNumberPad];
        [textbox setText:[NSString stringWithFormat:@"%f", number.getValue()]];
        [textbox setDelegate:self];
        UIToolbar* numberToolbar = [[UIToolbar alloc]initWithFrame:CGRectMake(0, 0, 320, 50)];
        numberToolbar.barStyle = UIBarStyleBlackTranslucent;
        numberToolbar.items = [NSArray arrayWithObjects:
                               [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil],
                               [[UIBarButtonItem alloc]initWithTitle:@"Apply" style:UIBarButtonItemStyleDone target:self action:@selector(doneWithNumberPad)],
                               nil];
        [numberToolbar sizeToFit];
        textbox.inputAccessoryView = numberToolbar;
    }
    return self;
}
-(void)refresh
{
	std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return;
	[textbox setText:[NSString stringWithFormat:@"%f", number[0].getValue()]];
	[textbox reloadInputViews];
}
-(BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return YES;
    number[0].setValue([textField.text doubleValue]);
    onelab::server::instance()->set(number[0]);
	[textField setText:[NSString stringWithFormat:@"%f", number[0].getValue()]];
    return YES;
}
-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    return [textField endEditing:YES];
}
-(void)doneWithNumberPad
{
    [textbox endEditing:YES];
}
-(void)setFrame:(CGRect)frame
{
    [textbox setFrame:frame];
}
-(UITextField *)getTextbox
{
    return textbox;
}
-(bool)isReadOnly
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[name UTF8String]);
    if(number.size() < 1) return YES;
    return number[0].getReadOnly();
}
+(double)getHeight
{
    return 60.f;
}
@end
