#import "Parameter.h"
#import "Utils.h"

@implementation Parameter
- (id)init
{
  self = [super init];
  if(self) {
    label = [[UILabel alloc] init];
    // set font size at 90% of default size
    label.font = [label.font fontWithSize:(0.9 * label.font.pointSize)];
    [label setBackgroundColor:[UIColor clearColor]];
  }
  return self;
}

- (void)refresh
{
  return;
}

- (NSString *)getName
{
  return name;
}

- (UILabel *)getLabel
{
  return label;
}

- (void)setFrame:(CGRect)frame
{
  return;
}

- (void)setLabelFrame:(CGRect)frame
{
  [label setFrame:frame];
}

- (void)editValue
{
  if(onelab_cb("check") > 0) {
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                        object:nil];
    [[NSNotificationCenter defaultCenter]
      postNotificationName:@"refreshParameters"
                    object:nil];
  }
}

+ (double)getHeight
{
  return 65.0f;
}
@end

@implementation ParameterStringList
- (id)initWithString:(onelab::string)string
{
  self = [super init];
  if(self) {
    [label setText:[Utils getStringFromCString:string.getShortName().c_str()]];
    name = [Utils getStringFromCString:string.getName().c_str()];
    button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button addTarget:self
                action:@selector(selectValue)
      forControlEvents:UIControlEventTouchDown];
    [button setTitle:[Utils getStringFromCString:string.getValue().c_str()]
            forState:UIControlStateNormal];
    [button setEnabled:(string.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(string.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)selectValue
{
  std::vector<onelab::string> string;
  onelab::server::instance()->get(string, [name UTF8String]);
  if(string.size() < 1) return;
  UIAlertController *alertController = [UIAlertController
    alertControllerWithTitle:nil
                     message:nil
              preferredStyle:UIAlertControllerStyleActionSheet];
  [alertController
    addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                       style:UIAlertActionStyleCancel
                                     handler:^(UIAlertAction *action){}]];
  std::vector<std::string> choices = string[0].getChoices();
  for(unsigned int i = 0; i < choices.size(); i++) {
    NSString *t = [Utils getStringFromCString:choices[i].c_str()];
    [alertController
      addAction:[UIAlertAction
                  actionWithTitle:t
                            style:UIAlertActionStyleDefault
                          handler:^(UIAlertAction *action) {
                            [self updateString:string[0] withValue:choices[i]];
                            [self->button
                              setTitle:[Utils getStringFromCString:choices[i]
                                                                     .c_str()]
                              forState:UIControlStateNormal];
                          }]];
  }
  [alertController setModalPresentationStyle:UIModalPresentationPopover];
  UIPopoverPresentationController *popPresenter =
    [alertController popoverPresentationController];
  popPresenter.sourceView = button;
  popPresenter.sourceRect = button.bounds;
  // FIXME: is traverseResponderChainForUIViewController a good idea?
  [[Utils traverseResponderChainForUIViewController:button]
    presentViewController:alertController
                 animated:YES
               completion:nil];
}

- (void)updateString:(onelab::string)s withValue:(std::string)v
{
  s.setValue(v);
  onelab::server::instance()->set(s);
  [super editValue];
}

- (void)refresh
{
  std::vector<onelab::string> string;
  onelab::server::instance()->get(string, [name UTF8String]);
  if(string.size() < 1) return;
  [button setTitle:[Utils getStringFromCString:string[0].getValue().c_str()]
          forState:UIControlStateNormal];
  [button setEnabled:(string[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(string[0].getReadOnly() ? FALSE : TRUE)];
}

- (void)setFrame:(CGRect)frame
{
  [button setFrame:frame];
}

- (UIButton *)getUIView
{
  return button;
}

@end

@implementation ParameterNumberList
- (id)initWithNumber:(onelab::number)number
{
  self = [super init];
  if(self) {
    [label setText:[Utils getStringFromCString:number.getShortName().c_str()]];
    name = [Utils getStringFromCString:number.getName().c_str()];
    button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button addTarget:self
                action:@selector(selectValue)
      forControlEvents:UIControlEventTouchDown];
    [button
      setTitle:[Utils
                 getStringFromCString:number.getValueLabel(number.getValue())
                                        .c_str()]
      forState:UIControlStateNormal];
    [button setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)selectValue
{
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, [name UTF8String]);
  if(numbers.size() < 1) return;
  UIAlertController *alertController = [UIAlertController
    alertControllerWithTitle:nil
                     message:nil
              preferredStyle:UIAlertControllerStyleActionSheet];
  [alertController
    addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                       style:UIAlertActionStyleCancel
                                     handler:^(UIAlertAction *action){}]];
  std::vector<double> choices = numbers[0].getChoices();
  for(unsigned int i = 0; i < choices.size(); i++) {
    NSString *t =
      [Utils getStringFromCString:numbers[0].getValueLabel(choices[i]).c_str()];
    [alertController
      addAction:[UIAlertAction
                  actionWithTitle:t
                            style:UIAlertActionStyleDefault
                          handler:^(UIAlertAction *action) {
                            [self updateNumber:numbers[0] withValue:choices[i]];
                            [self->button
                              setTitle:[Utils
                                         getStringFromCString:numbers[0]
                                                                .getValueLabel(
                                                                  i)
                                                                .c_str()]
                              forState:UIControlStateNormal];
                          }]];
  }
  [alertController setModalPresentationStyle:UIModalPresentationPopover];
  UIPopoverPresentationController *popPresenter =
    [alertController popoverPresentationController];
  popPresenter.sourceView = button;
  popPresenter.sourceRect = button.bounds;
  // FIXME: is traverseResponderChainForUIViewController a good idea?
  [[Utils traverseResponderChainForUIViewController:button]
    presentViewController:alertController
                 animated:YES
               completion:nil];
}

- (void)updateNumber:(onelab::number)n withValue:(double)v
{
  n.setValue(v);
  onelab::server::instance()->set(n);
  [super editValue];
}

- (void)refresh
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  [button
    setTitle:[Utils getStringFromCString:number[0]
                                           .getValueLabel(number[0].getValue())
                                           .c_str()]
    forState:UIControlStateNormal];
  [button setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
}

- (void)setFrame:(CGRect)frame
{
  [button setFrame:frame];
}

- (UIButton *)getUIView
{
  return button;
}

@end

@implementation ParameterNumberCheckbox
- (id)initWithNumber:(onelab::number)number
{
  self = [super init];
  if(self) {
    [label setText:[Utils getStringFromCString:number.getShortName().c_str()]];
    name = [Utils getStringFromCString:number.getName().c_str()];
    checkbox = [[UISwitch alloc] init];
    [checkbox setOn:(number.getValue() == 1)];
    [checkbox addTarget:self
                 action:@selector(valueChange:)
       forControlEvents:UIControlEventValueChanged];
    [checkbox setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)refresh
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  [checkbox setSelected:(number[0].getValue() == 1)];
  [checkbox setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
}

- (void)valueChange:(UISwitch *)sender
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  number[0].setValue(([sender isOn]) ? 1 : 0);
  onelab::server::instance()->set(number[0]);
  [super editValue];
}

- (void)setFrame:(CGRect)frame
{
  [checkbox setFrame:frame];
}

- (UISwitch *)getCheckbox
{
  return checkbox;
}

+ (double)getHeight
{
  return 45.0f;
}
@end

@implementation ParameterNumberStepper
- (id)initWithNumber:(onelab::number)number
{
  self = [super init];
  if(self) {
    name = [Utils getStringFromCString:number.getName().c_str()];
    stepper = [[UIStepper alloc] init];
    // make the stepper a bit smaller
    stepper.transform = CGAffineTransformMakeScale(0.8, 0.8);
    [stepper setValue:number.getValue()];
    [stepper setStepValue:1];
    [stepper setMaximumValue:number.getMax()];
    [stepper setMinimumValue:number.getMin()];
    [stepper addTarget:self
                action:@selector(stepperValueChanged:)
      forControlEvents:UIControlEventValueChanged];
    [label
      setText:[NSString
                stringWithFormat:@"%@ %d",
                                 [Utils
                                   getStringFromCString:number.getShortName()
                                                          .c_str()],
                                 (int)number.getValue()]];
    [stepper setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)stepperValueChanged:(UIStepper *)sender
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  number[0].setValue(sender.value);
  onelab::server::instance()->set(number[0]);
  [label
    setText:[NSString
              stringWithFormat:@"%@ %d",
                               [Utils getStringFromCString:number[0]
                                                             .getShortName()
                                                             .c_str()],
                               (int)number[0].getValue()]];
  [super editValue];
}

- (void)refresh
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  [stepper setValue:number[0].getValue()];
  [label
    setText:[NSString
              stringWithFormat:@"%@ %d",
                               [Utils getStringFromCString:number[0]
                                                             .getShortName()
                                                             .c_str()],
                               (int)number[0].getValue()]];
  [stepper setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
}

- (void)setFrame:(CGRect)frame
{
  [stepper setFrame:frame];
}

- (UIStepper *)getStepper
{
  return stepper;
}

@end

@implementation ParameterNumberRange
- (id)initWithNumber:(onelab::number)number
{
  self = [super init];
  if(self) {
    name = [Utils getStringFromCString:number.getName().c_str()];
    slider = [[UISlider alloc] init];
    [slider setMaximumValue:number.getMax()];
    [slider setMinimumValue:number.getMin()];
    [slider setValue:number.getValue()];
    // TODO add step ?
    [slider addTarget:self
                action:@selector(sliderValueChanged:)
      forControlEvents:UIControlEventTouchUpOutside];
    [slider addTarget:self
                action:@selector(sliderValueChanged:)
      forControlEvents:UIControlEventTouchUpInside];
    [label
      setText:[NSString
                stringWithFormat:@"%@ %g",
                                 [Utils
                                   getStringFromCString:number.getShortName()
                                                          .c_str()],
                                 number.getValue()]];
    [slider setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)refresh
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  [slider setMaximumValue:number[0].getMax()];
  [slider setMinimumValue:number[0].getMin()];
  [slider setValue:number[0].getValue()];
  [label
    setText:[NSString
              stringWithFormat:@"%@ %g",
                               [Utils getStringFromCString:number[0]
                                                             .getShortName()
                                                             .c_str()],
                               number[0].getValue()]];
  [slider setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
}

- (void)sliderValueChanged:(UISlider *)sender
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  number[0].setValue(sender.value);
  onelab::server::instance()->set(number[0]);
  [label
    setText:[NSString
              stringWithFormat:@"%@ %g",
                               [Utils getStringFromCString:number[0]
                                                             .getShortName()
                                                             .c_str()],
                               number[0].getValue()]];
  [super editValue];
}

- (void)setFrame:(CGRect)frame
{
  [slider setFrame:frame];
}

- (UISlider *)getSlider
{
  return slider;
}

@end

@implementation ParameterNumberTextbox
- (id)initWithNumber:(onelab::number)number
{
  self = [super init];
  if(self) {
    [label setText:[Utils getStringFromCString:number.getShortName().c_str()]];
    name = [Utils getStringFromCString:number.getName().c_str()];
    textbox = [[UITextField alloc] init];
    [textbox setBorderStyle:UITextBorderStyleRoundedRect];
    [textbox setText:[NSString stringWithFormat:@"%g", number.getValue()]];
    [textbox setDelegate:self];
    UIToolbar *numberToolbar =
      [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, 320, 50)];
    numberToolbar.items = [NSArray
      arrayWithObjects:
        [[UIBarButtonItem alloc]
          initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                               target:nil
                               action:nil],
        [[UIBarButtonItem alloc] initWithTitle:@"Apply"
                                         style:UIBarButtonItemStyleDone
                                        target:self
                                        action:@selector(doneWithNumberPad)],
        nil];
    [numberToolbar sizeToFit];
    textbox.inputAccessoryView = numberToolbar;
    [textbox setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
    [label setEnabled:(number.getReadOnly() ? FALSE : TRUE)];
  }
  return self;
}

- (void)refresh
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return;
  [textbox setText:[NSString stringWithFormat:@"%g", number[0].getValue()]];
  [textbox setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [label setEnabled:(number[0].getReadOnly() ? FALSE : TRUE)];
  [textbox reloadInputViews];
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() < 1) return YES;
  number[0].setValue([textField.text doubleValue]);
  onelab::server::instance()->set(number[0]);
  [textField setText:[NSString stringWithFormat:@"%g", number[0].getValue()]];
  [super editValue];
  return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
  return [textField endEditing:YES];
}

- (void)doneWithNumberPad
{
  [textbox endEditing:YES];
}

- (void)setFrame:(CGRect)frame
{
  [textbox setFrame:frame];
}

- (UITextField *)getTextbox
{
  return textbox;
}

@end
