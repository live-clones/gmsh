#import <UIKit/UIKit.h>

#include "SplitViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
@public
  bool compute;
}

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UITableViewController *modelListController;
@property (strong, nonatomic) SplitViewController *splitViewController; // iPad

@end
