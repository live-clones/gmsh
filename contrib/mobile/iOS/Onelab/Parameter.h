#import <Foundation/Foundation.h>
#import <Gmsh/onelab.h>

#import "drawContext.h"

@interface Parameter : NSObject {
@protected
  NSString *name;
  UILabel *label;
}
- (id)init;
- (void)setFrame:(CGRect)frame;
- (void)setLabelFrame:(CGRect)frame;
- (NSString *)getName;
- (UILabel *)getLabel;
+ (double)getHeight;
- (void)refresh;
@end

@interface ParameterStringList : Parameter <UIActionSheetDelegate> {
@protected
  UIButton *button;
}
- (id)initWithString:(onelab::string)string;
- (UIPickerView *)getUIView;
@end

@interface ParameterNumberList : Parameter <UIActionSheetDelegate> {
@protected
  UIButton *button;
}
- (id)initWithNumber:(onelab::number)number;
- (UITextField *)getUIView;
@end

@interface ParameterNumberCheckbox : Parameter {
@protected
  UISwitch *checkbox;
}
- (id)initWithNumber:(onelab::number)number;
- (UISwitch *)getCheckbox;
@end

@interface ParameterNumberStepper : Parameter {
@protected
  UIStepper *stepper;
}
- (id)initWithNumber:(onelab::number)number;
- (UIStepper *)getStepper;
@end

@interface ParameterNumberRange : Parameter {
@protected
  UISlider *slider;
}
- (id)initWithNumber:(onelab::number)number;
- (UISlider *)getSlider;
@end

@interface ParameterNumberTextbox : Parameter <UITextFieldDelegate> {
@protected
  UITextField *textbox;
}
- (id)initWithNumber:(onelab::number)number;
- (UITextField *)getTextbox;
@end
