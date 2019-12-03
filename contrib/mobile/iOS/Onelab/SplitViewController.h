#import <UIKit/UIKit.h>

#import "ParametersViewController.h"
#import "ModelViewController.h"

@interface SplitViewController : UISplitViewController {
  ModelViewController *modelViewController;
  ParametersViewController *parametersViewController;
}

@property (nonatomic, retain) NSString *initialModel;

@end
