#import "SplitViewController.h"

@interface SplitViewController ()

@end

@implementation SplitViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if(self) {
    // Custom initialization
  }
  return self;
}

- (void)viewDidLoad
{
  [super viewDidLoad];

  // always show primary and secondary view controllers side-by-side (default
  // since iOS9 is to hide the left pane in portrait mode)
  self.preferredDisplayMode = UISplitViewControllerDisplayModeAllVisible;

  // Do any additional setup after loading the view.
  UINavigationController *right = [self.viewControllers
    objectAtIndex:1]; // right UINavigationController (Detail)
  for(UIViewController *v in right.viewControllers) {
    if([v isKindOfClass:[ModelViewController class]]) {
      modelViewController = (ModelViewController *)v;
    }
  }
  UINavigationController *left = [self.viewControllers
    objectAtIndex:0]; // left UINavigationController (Master)
  for(UIViewController *v in left.viewControllers) {
    if([v isKindOfClass:[ParametersViewController class]]) {
      parametersViewController = (ParametersViewController *)v;
    }
  }
  self.delegate = modelViewController;
  [self setPresentsWithGesture:NO];
}

- (void)viewDidAppear:(BOOL)animated
{
  modelViewController.initialModel = self.initialModel;
  [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

@end
