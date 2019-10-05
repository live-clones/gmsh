#import "PostProcessingViewController.h"
#import "Utils.h"

#include <gmsh/Context.h>

@interface PostProcessingViewController ()

@end

@implementation PostProcessingViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if(self) {
    // Custom initialization
  }
  return self;
}

- (void)setPView:(PView *)p
{
  _pview = p;
}

- (void)viewDidLoad
{
  [super viewDidLoad];
  // Do any additional setup after loading the view.
  if(_pview) {
    [_Name
      setText:[Utils
                getStringFromCString:_pview->getData()->getName().c_str()]];
    [_IntervalsType setDataSource:self];
    [_IntervalsType setDelegate:self];
    [_Intervals
      setText:[NSString stringWithFormat:@"%d", _pview->getOptions()->nbIso]];
    UIToolbar *numberToolbar =
      [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, 320, 50)];
    numberToolbar.items = [NSArray
      arrayWithObjects:
        [[UIBarButtonItem alloc]
          initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                               target:nil
                               action:nil],
        [[UIBarButtonItem alloc] initWithTitle:@"Done"
                                         style:UIBarButtonItemStyleDone
                                        target:self
                                        action:@selector(doneWithNumberPad)],
        nil];
    [numberToolbar sizeToFit];
    _Intervals.delegate = self;
    _Intervals.inputAccessoryView = numberToolbar;
    [_RaiseZ setValue:_pview->getOptions()->raise[2]];

    double maxval = std::max(fabs(_pview->getData()->getMin()),
                             fabs(_pview->getData()->getMax()));
    if(!maxval) maxval = 1.;
    double val2 = 2. * CTX::instance()->lc / maxval;
    [_RaiseZ setMinimumValue:-val2];
    [_RaiseZ setMaximumValue:val2];
    [_RaiseZ addTarget:self
                action:@selector(slideRaiseZ:)
      forControlEvents:UIControlEventValueChanged];
    [_IntervalsStepper setStepValue:1];
    [_IntervalsStepper setValue:_pview->getOptions()->nbIso];
    [_IntervalsStepper setMaximumValue:1000];
    [_IntervalsStepper setMinimumValue:1];
  }
}

- (void)viewDidAppear:(BOOL)animated
{
  [_IntervalsType selectRow:_pview->getOptions()->intervalsType - 1
                inComponent:0
                   animated:YES];
}

- (IBAction)stepperValueChanged:(UIStepper *)sender
{
  [_Intervals setText:[NSString stringWithFormat:@"%.0f", [sender value]]];
  _pview->getOptions()->nbIso = [sender value];
  _pview->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
  return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView
  numberOfRowsInComponent:(NSInteger)component
{
  return 3;
}

- (NSString *)pickerView:(UIPickerView *)pickerView
             titleForRow:(NSInteger)row
            forComponent:(NSInteger)component
{
  NSArray *name =
    [[NSArray alloc] initWithObjects:@"Iso-values", @"Continuous map",
                                     @"Filled iso-values", nil];
  return [name objectAtIndex:row];
}

- (void)pickerView:(UIPickerView *)pickerView
      didSelectRow:(NSInteger)row
       inComponent:(NSInteger)component
{
  _pview->getOptions()->intervalsType = (int)(1 + row);
  _pview->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)slideRaiseZ:(UISlider *)sender
{
  _pview->getOptions()->raise[2] = sender.value;
  _pview->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
  [_IntervalsStepper setValue:_pview->getOptions()->nbIso];
  _pview->getOptions()->nbIso = (int)[textField.text integerValue];
  _pview->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
  return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
  return [_Intervals endEditing:YES];
}

- (void)doneWithNumberPad
{
  [_Intervals endEditing:YES];
}

@end
