#import "OptionsViewController.h"
#import "ModelViewController.h"
#import "ParametersViewController.h"
#import "PostProcessingViewController.h"
#import "Utils.h"

#include <gmsh/Context.h>
#include <gmsh/GmshDefines.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

@interface OptionsViewController ()

@end

@implementation OptionsViewController

- (id)initWithStyle:(UITableViewStyle)style
{
  self = [super initWithStyle:style];
  if(self) {
    // Custom initialization
  }
  return self;
}

- (void)viewDidLoad
{
  [super viewDidLoad];

  [[NSNotificationCenter defaultCenter] addObserver:self
                                           selector:@selector(refreshOptions:)
                                               name:@"refreshParameters"
                                             object:nil];
  [[NSNotificationCenter defaultCenter] addObserver:self
                                           selector:@selector(refreshOptions:)
                                               name:@"resetParameters"
                                             object:nil];

  self.navigationItem.title = @"Display";

  [self.navigationController setToolbarHidden:NO];
  control = [[UISegmentedControl alloc]
    initWithItems:[[NSArray alloc] initWithObjects:@"Model", @"Display", nil]];
  UIBarButtonItem *controlBtn =
    [[UIBarButtonItem alloc] initWithCustomView:control];
  UIBarButtonItem *flexibleSpace = [[UIBarButtonItem alloc]
    initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                         target:nil
                         action:nil];
  self.toolbarItems = [[NSArray alloc]
    initWithObjects:flexibleSpace, controlBtn, flexibleSpace, nil];
  [control addTarget:self
              action:@selector(indexDidChangeForSegmentedControl:)
    forControlEvents:UIControlEventValueChanged];
  if(![[UIDevice currentDevice].model isEqualToString:@"iPad"] &&
     ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
    self.navigationItem.leftBarButtonItem =
      [[UIBarButtonItem alloc] initWithTitle:@"Back"
                                       style:UIBarButtonItemStylePlain
                                      target:self
                                      action:@selector(backButtonPressed:)];
  else
    self.navigationItem.hidesBackButton = true;
}
- (void)viewWillAppear:(BOOL)animated
{
  control.selectedSegmentIndex = 1;
  [super viewWillAppear:animated];
}

- (void)backButtonPressed:(id)sender
{
  for(UIViewController *v in [self.navigationController viewControllers])
    if([v isKindOfClass:[ModelViewController class]])
      [self.navigationController popToViewController:v animated:YES];
}

- (void)indexDidChangeForSegmentedControl:(id)sender
{
  [self.navigationController popViewControllerAnimated:YES];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (void)refreshOptions:(id)sender
{
  [self performSelectorOnMainThread:@selector(refreshOptions)
                         withObject:nil
                      waitUntilDone:NO];
}

- (void)refreshOptions
{
  [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
  return 2;
  // Section 0: Display options
  // Section 1: Result options
}

- (NSString *)tableView:(UITableView *)tableView
  titleForHeaderInSection:(NSInteger)section
{
  switch(section) {
  case 0: return @"Display options";
  case 1: return @"Result options";
  default: return @"Other options";
  }
}

- (NSInteger)tableView:(UITableView *)tableView
  numberOfRowsInSection:(NSInteger)section
{
  switch(section) {
  case 0: return 4;
  case 1: return PView::list.size();
  default: return 0;
  }
}

- (CGFloat)tableView:(UITableView *)tableView
  heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
  return 45.0f;
}

- (UITableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
  UITableViewCell *cell =
    [tableView dequeueReusableCellWithIdentifier:@"postproCell"];
  if(cell == nil) {
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:@"postproCell"];
  }
  else {
    cell = nil;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:@"postproCell"];
  }

  [cell setSelectionStyle:UITableViewCellSelectionStyleNone];
  [cell
    setFrame:CGRectMake(cell.frame.origin.x, cell.frame.origin.x,
                        tableView.frame.size.width, cell.frame.size.height)];
  switch(indexPath.section) {
  case 0: {
    UISwitch *showHide =
      [[UISwitch alloc] initWithFrame:CGRectMake(15, 6.5, 100, 30)];
    UILabel *label = [[UILabel alloc]
      initWithFrame:CGRectMake(25 + (showHide.frame.size.width), 8,
                               (tableView.frame.size.width -
                                (showHide.frame.size.width) - 50),
                               30)];
    // set font size at 90% of default size
    label.font =
      [label.font fontWithSize:(0.9 * label.font.pointSize)];

    if(indexPath.row == 0) {
      [label setText:@"Show geometry points"];
      [showHide setOn:(CTX::instance()->geom.points)];
      [showHide addTarget:self
                          action:@selector(setShowGeomPoints:)
                forControlEvents:UIControlEventValueChanged];
    }
    else if(indexPath.row == 1) {
      [label setText:@"Show geometry curves"];
      [showHide setOn:(CTX::instance()->geom.curves)];
      [showHide addTarget:self
                          action:@selector(setShowGeomCurves:)
                forControlEvents:UIControlEventValueChanged];
    }
    else if(indexPath.row == 2) {
      [label setText:@"Show mesh surface edges"];
      [showHide setOn:(CTX::instance()->mesh.surfaceEdges)];
      [showHide addTarget:self
                          action:@selector(setShowMeshSurfaceEdges:)
                forControlEvents:UIControlEventValueChanged];
    }
    else if(indexPath.row == 3) {
      [label setText:@"Show mesh volume edges"];
      [showHide setOn:CTX::instance()->mesh.volumeEdges];
      [showHide addTarget:self
                          action:@selector(setShowMeshVolumeEdges:)
                forControlEvents:UIControlEventValueChanged];
    }
    [cell.contentView addSubview:showHide];
    [cell.contentView addSubview:label];
  } break;
  case 1: {
    int i = (int)(PView::list.size() - 1 - indexPath.row);
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    UISwitch *showHide =
      [[UISwitch alloc] initWithFrame:CGRectMake(15, 6.5, 100, 30)];
    UILabel *label = [[UILabel alloc]
      initWithFrame:CGRectMake(25 + (showHide.frame.size.width), 8,
                               (tableView.frame.size.width -
                                showHide.frame.size.width - 50),
                               30)];
    // set font size at 90% of default size
    label.font = [label.font fontWithSize:(0.9 * label.font.pointSize)];
    [showHide setOn:(PView::list[i]->getOptions()->visible == 1)];
    [showHide setTag:i];
    [showHide addTarget:self
                 action:@selector(PViewVisible:)
       forControlEvents:UIControlEventValueChanged];
    [label setBackgroundColor:[UIColor clearColor]];
    [label setText:[Utils getStringFromCString:PView::list[i]
                                               ->getData()
                                               ->getName()
                                               .c_str()]];
    [cell.contentView addSubview:showHide];
    [cell.contentView addSubview:label];
  } break;
  }
  return cell;
}

- (void)tableView:(UITableView *)tableView
  didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
  if(indexPath.section != 1) return;
  UIStoryboard *storyboard;
  if([[UIDevice currentDevice].model isEqualToString:@"iPad"] ||
     [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
    storyboard = [UIStoryboard storyboardWithName:@"iPadStoryboard" bundle:nil];
  else
    storyboard = [UIStoryboard storyboardWithName:@"iPhoneiPodStoryboard"
                                           bundle:nil];
  PostProcessingViewController *postPro = [storyboard
    instantiateViewControllerWithIdentifier:@"PostProcessingViewController"];
  [postPro setPView:PView::list[[tableView numberOfRowsInSection:1] - 1 -
                                indexPath.row]];
  [self.navigationController pushViewController:postPro animated:YES];
}

- (void)setShowGeomPoints:(UISwitch *)sender
{
  CTX::instance()->geom.points = sender.on;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)setShowGeomCurves:(UISwitch *)sender
{
  CTX::instance()->geom.curves = sender.on;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)setShowMeshVolumeEdges:(UISwitch *)sender
{
  CTX::instance()->mesh.volumeEdges = sender.on;
  CTX::instance()->mesh.changed = ENT_VOLUME;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)setShowMeshSurfaceEdges:(UISwitch *)sender
{
  CTX::instance()->mesh.surfaceEdges = sender.on;
  CTX::instance()->mesh.changed = ENT_SURFACE;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (IBAction)PViewVisible:(id)sender
{
  PView::list[((UISwitch *)sender).tag]->getOptions()->visible =
    (((UISwitch *)sender).on) ? 1 : 0;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

#pragma mark - textfield

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
  int val = (int)[textField.text integerValue];
  val = (val > 0) ? val : 1;
  val = (val < 1000) ? val : 1000;
  [textField setText:[NSString stringWithFormat:@"%d", val]];
  PView::list[textField.tag]->getOptions()->nbIso = val;
  PView::list[textField.tag]->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
  return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
  [textField endEditing:YES];
  return YES;
}

@end
