#import <UIKit/UIKit.h>

#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

@interface PostProcessingViewController
  : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate,
                      UITextFieldDelegate> {
@private
  PView *_pview;
}

@property (weak, nonatomic) IBOutlet UILabel *Name;
@property (weak, nonatomic) IBOutlet UIPickerView *IntervalsType;
@property (weak, nonatomic) IBOutlet UITextField *Intervals;
@property (weak, nonatomic) IBOutlet UIStepper *IntervalsStepper;
@property (weak, nonatomic) IBOutlet UISlider *RaiseZ;

- (IBAction)stepperValueChanged:(UIStepper *)sender;

- (void)setPView:(PView *)p;

@end
