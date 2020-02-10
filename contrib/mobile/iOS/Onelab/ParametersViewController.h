#import <UIKit/UIKit.h>
#import <Gmsh/onelab.h>

@class ModelListController;

@interface ParametersViewController : UITableViewController {
@private
  NSMutableArray *_sections;
  NSMutableArray *_sectionstitle;
  NSDate *_lastRefresh;
  UIBarButtonItem *runButton;
  UIBarButtonItem *stopButton;
  UISegmentedControl *control;
}

@property (strong, nonatomic) ModelListController *modelListController;

- (void)resetParameters:(id)sender;

@end
