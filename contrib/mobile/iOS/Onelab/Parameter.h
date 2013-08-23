//
//  parameter.h
//  Onelab
//
//  Created by Maxime Graulich on 07/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Gmsh/onelab.h>

#import "drawContext.h"

@interface Parameter : NSObject
{
    @protected
    NSString *name;
    UILabel *label;
}
-(id)init;
-(void)setFrame:(CGRect)frame;
-(void)setLabelFrame:(CGRect)frame;
-(NSString *)getName;
-(UILabel *)getLabel;
-(bool)isReadOnly;
+(double)getHeight;
-(void)refresh;
@end

@interface ParameterStringList : Parameter <UIPickerViewDataSource, UIPickerViewDelegate>
{
    @protected
    UIPickerView *picker;
}
-(id)initWithString:(onelab::string)string;
-(UIPickerView *)getList;
@end


@interface ParameterNumberList : Parameter <UIPickerViewDataSource, UIPickerViewDelegate, UITextFieldDelegate>
{
    @protected
    UIPickerView *picker;
}
-(id)initWithNumber:(onelab::number)number;
-(UIPickerView *)getList;
@end

@interface ParameterNumberCheckbox : Parameter
{
    @protected
    UISwitch *checkbox;
}
-(id)initWithNumber:(onelab::number)number;
-(UISwitch *)getCheckbox;
@end

@interface ParameterNumberRange : Parameter
{
    @protected
    UISlider *slider;
}
-(id)initWithNumber:(onelab::number)number;
-(UISlider *)getSlider;
@end

@interface ParameterNumberTextbox : Parameter <UITextFieldDelegate>
{
@protected
    UITextField *textbox;
}
-(id)initWithNumber:(onelab::number)number;
-(UITextField *)getTextbox;
@end
