#import "OptionsViewController.h"
#import "ParametersViewController.h"
#import "PostProcessingViewController.h"
#import "ModelViewController.h"
#import "Utils.h"

#include <gmsh/Context.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>
#include <gmsh/GmshDefines.h>

@interface OptionsViewController ()

@end

@implementation OptionsViewController

- (id)initWithStyle:(UITableViewStyle)style
{
  self = [super initWithStyle:style];
  if (self) {
    // Custom initialization
  }
  return self;
}

- (void)viewDidLoad
{
  [super viewDidLoad];

  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshOptions:)
                                               name:@"refreshParameters" object:nil];
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshOptions:)
                                               name:@"resetParameters" object:nil];

  self.navigationItem.title = @"Display";

  [self.navigationController setToolbarHidden:NO];
  control = [[UISegmentedControl alloc] initWithItems:
                     [[NSArray alloc] initWithObjects:@"Model", @"Display", nil]];
  UIBarButtonItem *controlBtn = [[UIBarButtonItem alloc] initWithCustomView:control];
  UIBarButtonItem *flexibleSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:
                                              UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
  self.toolbarItems = [[NSArray alloc] initWithObjects:flexibleSpace, controlBtn, flexibleSpace, nil];
  [control addTarget:self action:@selector(indexDidChangeForSegmentedControl:)
    forControlEvents:UIControlEventValueChanged];
  if(![[UIDevice currentDevice].model isEqualToString:@"iPad"]
     && ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
    self.navigationItem.leftBarButtonItem =
      [[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain
                                      target:self action:@selector(backButtonPressed:)];
  else
    self.navigationItem.hidesBackButton = true;
}
- (void)viewWillAppear:(BOOL)animated
{
  control.selectedSegmentIndex = 1;
  [super viewWillAppear:animated];
}

-(void)backButtonPressed:(id)sender
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
  [self performSelectorOnMainThread:@selector(refreshOptions) withObject:nil waitUntilDone:NO];
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

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
  switch (section) {
  case 0:
    return @"Display options";
  case 1:
    return @"Result options";
  default:
    return @"Other options";
  }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
  switch (section) {
  case 0:
    return 4;
  case 1:
    return PView::list.size();
  default:
    return 0;
  }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
  UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
  if(cell == nil){
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:@"postproCell"];
  }
  else {
    cell = nil;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:@"postproCell"];
  }
  [cell setFrame:CGRectMake(cell.frame.origin.x, cell.frame.origin.x,
                            tableView.frame.size.width, cell.frame.size.height)];
  switch (indexPath.section) {
  case 0:
    {
      [cell setSelectionStyle:UITableViewCellSelectionStyleNone];
      UISwitch *showHideOptions = [[UISwitch alloc] initWithFrame: CGRectMake(15, 6.5, 100, 30)];
      UILabel *lblOptions =
        [[UILabel alloc] initWithFrame:CGRectMake
                         (25 + (showHideOptions.frame.size.width), 8,
                          (tableView.frame.size.width - (showHideOptions.frame.size.width) - 50), 30)];
      if(indexPath.row == 0) {
        [lblOptions setText:@"Show geometry points"];
        [showHideOptions setOn:(CTX::instance()->geom.points)];
        [showHideOptions addTarget:self action:@selector(setShowGeomPoints:)
                  forControlEvents:UIControlEventValueChanged];
      }
      else if(indexPath.row == 1) {
        [lblOptions setText:@"Show geometry lines"];
        [showHideOptions setOn:(CTX::instance()->geom.lines)];
        [showHideOptions addTarget:self action:@selector(setShowGeomLines:)
                  forControlEvents:UIControlEventValueChanged];
      }
      else if(indexPath.row == 2) {
        [lblOptions setText:@"Show mesh surface edges"];
        [showHideOptions setOn:(CTX::instance()->mesh.surfacesEdges)];
        [showHideOptions addTarget:self action:@selector(setShowMeshSurfacesEdges:)
                  forControlEvents:UIControlEventValueChanged];
      }
      else if(indexPath.row == 3) {
        [lblOptions setText:@"Show mesh volumes edges"];
        [showHideOptions setOn:CTX::instance()->mesh.volumesEdges];
        [showHideOptions addTarget:self action:@selector(setShowMeshVolumesEdges:)
                  forControlEvents:UIControlEventValueChanged];
      }
      [cell addSubview:showHideOptions];
      [cell addSubview:lblOptions];
    }
    break;
  case 1:
    {
      NSArray *rows = [tableView indexPathsForVisibleRows];
      for(NSIndexPath *mIndexpath in rows)
        if(![mIndexpath isEqual:indexPath]){
          UITableViewCell *tmp = [tableView cellForRowAtIndexPath:indexPath];
          for(UIView *tmpv in tmp.subviews)for(UIView *v in tmpv.subviews)
                                             if([v isKindOfClass:[UISwitch class]])
                                               [(UISwitch *)v setOn:PView::list[v.tag]->getOptions()->visible];
        }

      [cell setSelectionStyle:UITableViewCellSelectionStyleGray];
      int i = PView::list.size() - 1 - indexPath.row;
      cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
      UISwitch *showHide = [[UISwitch alloc] initWithFrame: CGRectMake(15, 6.5, 100, 30)];
      UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake
                                      (25 + (showHide.frame.size.width), 8,
                                       (tableView.frame.size.width - showHide.frame.size.width - 50), 30)];
      [showHide setOn:(PView::list[i]->getOptions()->visible == 1)];
      [showHide setTag:i];
      [showHide addTarget:self action:@selector(PViewVisible:) forControlEvents:UIControlEventValueChanged];
      [lbl setBackgroundColor: [UIColor clearColor]];
      [lbl setText:[Utils getStringFromCString:PView::list[i]->getData()->getName().c_str()]];
      [cell addSubview:showHide];
      [cell addSubview:lbl];
    }
    break;
  }
  return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
  if(indexPath.section != 1) return;
  UIStoryboard *storyboard;
  if([[UIDevice currentDevice].model isEqualToString:@"iPad"] ||
     [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
    storyboard = [UIStoryboard storyboardWithName:@"iPadStoryboard" bundle:nil];
  else
    storyboard = [UIStoryboard storyboardWithName:@"iPhoneiPodStoryboard" bundle:nil];
  PostProcessingViewController *postPro =
    [storyboard instantiateViewControllerWithIdentifier:@"PostProcessingViewController"];
  [postPro setPView:PView::list[[tableView numberOfRowsInSection:1]-1- indexPath.row]];
  [self.navigationController pushViewController:postPro animated:YES];
}

- (void)setShowGeomPoints:(UISwitch*)sender
{
  CTX::instance()->geom.points = sender.on;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)setShowGeomLines:(UISwitch*)sender
{
  CTX::instance()->geom.lines = sender.on;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)setShowMeshVolumesEdges:(UISwitch*)sender
{
  CTX::instance()->mesh.volumesEdges = sender.on;
  CTX::instance()->mesh.changed = ENT_VOLUME;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)setShowMeshSurfacesEdges:(UISwitch*)sender
{
  CTX::instance()->mesh.surfacesEdges = sender.on;
  CTX::instance()->mesh.changed = ENT_SURFACE;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

-(IBAction)PViewVisible:(id)sender
{
  PView::list[((UISwitch*)sender).tag]->getOptions()->visible = (((UISwitch*)sender).on)? 1 : 0;
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

#pragma mark - textfield

-(BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
  int val = (int)[textField.text integerValue];
  val = (val > 0)? val : 1;
  val = (val < 1000)? val : 1000;
  [textField setText:[NSString stringWithFormat:@"%d",val]];
  PView::list[textField.tag]->getOptions()->nbIso = val;
  PView::list[textField.tag]->setChanged(true);
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
  return YES;
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
  [textField endEditing:YES];
  return YES;
}

@end
