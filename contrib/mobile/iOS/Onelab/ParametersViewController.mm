#import "ParametersViewController.h"
#import "ModelViewController.h"
#import "OptionsViewController.h"
#import "AppDelegate.h"
#import "parameter.h"
#import "Utils.h"

@interface ParametersViewController () {

}
@end

@implementation ParametersViewController

- (void)awakeFromNib
{
  self.clearsSelectionOnViewWillAppear = NO;
  [super awakeFromNib];
}

- (void)viewDidLoad
{
  [super viewDidLoad];

  // Do any additional setup after loading the view, typically from a nib.
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshParameters:)
                                               name:@"refreshParameters" object:nil];
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resetParameters:)
                                               name:@"resetParameters" object:nil];

  self.navigationItem.title = @"Model";

  _sections = [[NSMutableArray alloc] init];
  _sectionstitle = [[NSMutableArray alloc] init];

  UILongPressGestureRecognizer *lpgr =
    [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPress:)];
  lpgr.minimumPressDuration = 1.0;
  [self.tableView addGestureRecognizer:lpgr];

  [self.navigationController setToolbarHidden:NO];
  control = [[UISegmentedControl alloc] initWithItems:
                     [[NSArray alloc] initWithObjects:@"Model", @"Display", nil]];
  UIBarButtonItem *controlBtn = [[UIBarButtonItem alloc] initWithCustomView:control];
  UIBarButtonItem *flexibleSpace =
    [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                                                  target:nil action:nil];
  self.toolbarItems = [[NSArray alloc] initWithObjects:flexibleSpace, controlBtn, flexibleSpace, nil];
  [control addTarget:self action:@selector(indexDidChangeForSegmentedControl:)
    forControlEvents:UIControlEventValueChanged];
  if(![[UIDevice currentDevice].model isEqualToString:@"iPad"] &&
     ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
    self.navigationItem.leftBarButtonItem =
      [[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain
                                      target:self action:@selector(backButtonPressed:)];
  }
  self.navigationItem.rightBarButtonItem =
    [[UIBarButtonItem alloc] initWithTitle:@"Reset" style:UIBarButtonItemStylePlain
                                    target:self action:@selector(resetParameters:)];
}

- (void)viewWillAppear:(BOOL)animated
{
  [self refreshParameters:nil];
  control.selectedSegmentIndex = 0;
  [super viewWillAppear:animated];
}

-(void)backButtonPressed:(id)sender
{
  [self.navigationController popViewControllerAnimated:YES];
}

-(void)handleLongPress:(UILongPressGestureRecognizer *)sender
{
  CGPoint p = [sender locationInView:self.tableView];
  if(sender.state == UIGestureRecognizerStateCancelled) return;
  NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint:p];
  if(!indexPath) return;
  NSMutableArray* section = [_sections objectAtIndex:indexPath.section];
  if(!section) return;
  Parameter * parameter = [section objectAtIndex:indexPath.row];
  if(!parameter) return;
  NSString *name = [parameter getName];
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [name UTF8String]);
  if(number.size() && !number[0].getReadOnly()){
    NSLog(@"Manual edit of parameter '%s' with value '%g'", number[0].getName().c_str(),
          number[0].getValue());
    UIAlertView *alertView =
      [[UIAlertView alloc] initWithTitle:[Utils getStringFromCString:number[0].getShortName().c_str()]
                                 message:name delegate:self cancelButtonTitle:@"Cancel"
                       otherButtonTitles:@"Ok", nil];
    alertView.alertViewStyle = UIAlertViewStylePlainTextInput;
    [alertView textFieldAtIndex:0].text = [NSString stringWithFormat:@"%g", number[0].getValue()];
    [alertView show];
  }
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
  NSLog(@"%@ -> %@", [alertView message], [alertView textFieldAtIndex:0].text);
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number, [[alertView message] UTF8String]);
  if(number.size()){
    double value = [[alertView textFieldAtIndex:0].text doubleValue];
    number[0].setValue(value);
    onelab::server::instance()->set(number[0]);
    if(onelab_cb("check") > 0){
      [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
      [[NSNotificationCenter defaultCenter] postNotificationName:@"refreshParameters" object:nil];
    }
  }
}

- (void)indexDidChangeForSegmentedControl:(id)sender
{
  OptionsViewController *optionsViewController = [[OptionsViewController alloc] init];
  [self.navigationController pushViewController:optionsViewController animated:YES];
}

- (void)addParameterNumber:(onelab::number)p inSection:(NSMutableArray*)section
{
  if(p.getChoices().size() && p.getChoices().size() == p.getValueLabels().size()) { // enumeration
    ParameterNumberList *param = [[ParameterNumberList alloc] initWithNumber:p];
    [section addObject:param];
  }
  else if(p.getChoices().size() == 2 && p.getChoices()[0] == 0 && p.getChoices()[1] == 1) { // check box
    ParameterNumberCheckbox *param = [[ParameterNumberCheckbox alloc] initWithNumber:p];
    [section addObject:param];
  }
  else if(p.getStep() == 1) { // stepper
    ParameterNumberStepper *param = [[ParameterNumberStepper alloc] initWithNumber:p];
    [section addObject:param];
  }
  else if(p.getMin() >= p.getMax() ||
          p.getMin() == -onelab::number::maxNumber() ||
          p.getMax() == onelab::number::maxNumber()) { // text box
    ParameterNumberTextbox *param = [[ParameterNumberTextbox alloc] initWithNumber:p];
    [section addObject:param];
  }
  else { // slider
    ParameterNumberRange *param = [[ParameterNumberRange alloc] initWithNumber:p];
    [section addObject:param];
  }
}

- (void)addParameterString:(onelab::string)p inSection:(NSMutableArray*)section
{
  ParameterStringList *param = [[ParameterStringList alloc] initWithString:p];
  [section addObject:param];
}

- (void)addSection:(NSMutableArray*)s withTitle:(NSString*)t withParameterNumber:(onelab::number)p
{
  [_sections addObject:s];
  [_sectionstitle addObject:t];
  [self addParameterNumber:p inSection:s];
}

- (void)addSection:(NSMutableArray*)s withTitle:(NSString*)t withParameterString:(onelab::string)p
{
  [_sections addObject:s];
  [_sectionstitle addObject:t];
  [self addParameterString:p inSection:s];
}

NSString *GetSectionTitle(NSString *name)
{
  NSString *s = @"";
  NSArray *split = [name componentsSeparatedByString:@"/"];
  for(int i = 0; i < [split count] - 1; i++){
    NSString *name = [split objectAtIndex:i];
    while([name length] && [name characterAtIndex:0] == ' ')
      name = [name substringFromIndex:1];
    while([name length] && ([name characterAtIndex:0] == '{' || [name characterAtIndex:0] == '}'))
      name = [name substringFromIndex:1];
    while([name length] && [name characterAtIndex:0] >= '0' && [name characterAtIndex:0] <= '9')
      name = [name substringFromIndex:1];
    if(i)
      s = [s stringByAppendingString:@" > "];
    s = [s stringByAppendingString:name];
  }
  return s;
}

NSInteger compareParameter(id p1, id p2, void *context)
{
  return [[p1 getName] compare:[p2 getName]];
}

- (void)refreshTableView
{
  std::vector<onelab::number> number;
  onelab::server::instance()->get(number);

  // check for new/updated parameters (number)
  for(int i = 0; i < number.size(); i++) {
    if(!number[i].getVisible()) continue; // do not add invisible parameter
    if(number[i].getName() == "GetDP/}ModelCheck") continue; // don't show model checking

    NSString *name = [Utils getStringFromCString:number[i].getName().c_str()];
    NSString *sectiontitle = GetSectionTitle(name);
    Boolean found = false;
    for(int iSection = 0; iSection < [_sectionstitle count]; iSection++) {
      if([sectiontitle isEqualToString:[_sectionstitle objectAtIndex:iSection]]) {
        NSMutableArray *section = [_sections objectAtIndex:iSection];
        for(int iparameter = 0; iparameter<[section count]; iparameter++) {
          if([[[section objectAtIndex: iparameter] getName] isEqualToString:name]) {
            // the parameter is in the section
            Parameter * p = [section objectAtIndex: iparameter];
            [p refresh]; // just refresh the parameter
            found = true;
            break;
          }
        }
        if(!found){ // the parameter is not in the section, add it
          [self addParameterNumber:number[i] inSection:section];
        }
        found = true;
        break;
      }
    }
    if(found) continue; // the parameter is in the tableView
    // the section has to be created
    NSMutableArray *newSection = [[NSMutableArray alloc] init];
    [self addSection:newSection withTitle:sectiontitle withParameterNumber:number[i]];
  }

  std::vector<onelab::string> string;
  onelab::server::instance()->get(string);

  // check for new/updated parameters (string)
  for(int i = 0; i < string.size(); i++) {
    if(!string[i].getVisible() || string[i].getKind() == "file") continue;
    NSString *name = [Utils getStringFromCString:string[i].getName().c_str()];
    NSString *sectiontitle = GetSectionTitle(name);
    Boolean found = false;
    for(int iSection = 0; iSection < [_sectionstitle count]; iSection++) {
      if([sectiontitle isEqualToString:[_sectionstitle objectAtIndex:iSection]]) {
        NSMutableArray *section = [_sections objectAtIndex:iSection];
        for(int iparameter = 0; iparameter<[section count]; iparameter++) {
          if([[[section objectAtIndex: iparameter] getName] isEqualToString:name]) {
            Parameter * p = [section objectAtIndex: iparameter];
            [p refresh]; // just refresh the parameter
            found = true;
            break;
          }
        }
        if(!found){ // the parameter is not in the section, add it
          [self addParameterString:string[i] inSection:section];
        }
        found = true;
        break;
      }
    }
    if(found) continue; // the parameter is in the tableView
    // the section has to be created
    NSMutableArray *newSection = [[NSMutableArray alloc] init];
    [self addSection:newSection withTitle:sectiontitle withParameterString:string[i]];
  }

  // check for hidden/deleted parameters
  for(int iSection = [_sectionstitle count] - 1; iSection >= 0; iSection--) {
    NSMutableArray *section = [_sections objectAtIndex:iSection];
    for(int iparameter = [section count] - 1; iparameter >= 0; iparameter--) {
      Parameter * p = [section objectAtIndex: iparameter];
      std::vector<onelab::number> number;
      onelab::server::instance()->get(number, [[p getName] UTF8String]);
      std::vector<onelab::string> string;
      onelab::server::instance()->get(string, [[p getName] UTF8String]);
      if((number.size() < 1 && string.size() < 1) ||
         (number.size() > 0 && !number[0].getVisible()) ||
         (string.size() > 0 && !string[0].getVisible())){
        [section removeObjectAtIndex:iparameter];
      }
    }
  }

  // sort parameters in each section
  for(int iSection = 0; iSection < [_sections count]; iSection++) {
    NSMutableArray *section = [_sections objectAtIndex:iSection];
    [section sortUsingFunction:compareParameter context:nil];
  }

  [self.tableView reloadData];
}

- (void)viewDidUnload
{
  [super viewDidUnload];
  // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
  return YES;
}

- (void)refreshParameters:(id)sender
{
  [self performSelectorOnMainThread:@selector(refreshParameters) withObject:nil waitUntilDone:NO];
}

- (void)refreshParameters
{
  if(!_lastRefresh){
    _lastRefresh = [NSDate date];
  }
  else {
    if([_lastRefresh timeIntervalSinceNow] >= -0.1) return;
    _lastRefresh = [NSDate date];
  }
  [self refreshTableView]; // Get the param
}

- (void)resetParameters:(id)sender
{
  if(((AppDelegate *)[UIApplication sharedApplication].delegate)->compute) {
    UIAlertView *alert;
    alert = [[UIAlertView alloc]
              initWithTitle:@"Can't reset model parameters"
                    message:@"The computation has to complete before you can reset the parameters."
                   delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
    return;
  }
  onelab_cb("reset");
  [_sections removeAllObjects];
  [_sectionstitle removeAllObjects];
  [self.tableView reloadData];
  onelab_cb("check");
  [self refreshTableView];
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

#pragma mark - Table View

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
  return [_sections count];
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
  // Return NO if you do not want the specified item to be editable.
  return YES;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
  if([_sections count] < section)
    return 0;
  NSMutableArray *mSection = [_sections objectAtIndex:section];
  return [mSection count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
  // get the param with his name
  static NSString *CellIdentifier = @"parameterCell";
  if(indexPath.section >= _sections.count)
    return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:CellIdentifier];
  NSMutableArray *sectionContent = [_sections objectAtIndex:[indexPath section]];
  if(indexPath.row >= sectionContent.count)
    return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:CellIdentifier];
  Parameter *tmp = [sectionContent objectAtIndex:[indexPath row]];

  UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
  if(cell == nil)
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:CellIdentifier];
  else {
    cell = nil;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                  reuseIdentifier:CellIdentifier];
  }
  [cell setSelectionStyle:UITableViewCellSelectionStyleNone];
  [tmp setLabelFrame:CGRectMake(20, 5, tableView.frame.size.width - 40,
                                cell.frame.size.height/2)];
  [cell addSubview:[tmp getLabel]];
  if([tmp isKindOfClass:[ParameterStringList class]]) {
    ParameterStringList *param = (ParameterStringList *)tmp;
    [param setFrame:CGRectMake(20, 35, tableView.frame.size.width - 40,
                               cell.frame.size.height/2)];
    [cell addSubview:[param getUIView]];
  }
  else if([tmp isKindOfClass:[ParameterNumberList class]]) {
    ParameterNumberList *param = (ParameterNumberList *)tmp;
    [param setFrame:CGRectMake(20, 35, tableView.frame.size.width - 40,
                               cell.frame.size.height/2)];
    [cell addSubview:[param getUIView]];
  }
  else if([tmp isKindOfClass:[ParameterNumberCheckbox class]]) {
    ParameterNumberCheckbox *param = (ParameterNumberCheckbox *)tmp;
    [param setLabelFrame:CGRectMake(85, 10, tableView.frame.size.width - 95,
                                    cell.frame.size.height/2)];
    [param setFrame:CGRectMake(20, 5, tableView.frame.size.width - 40,
                               cell.frame.size.height)];
    [cell addSubview:[param getCheckbox]];
  }
  else if([tmp isKindOfClass:[ParameterNumberStepper class]]) {
    ParameterNumberStepper *param = (ParameterNumberStepper *)tmp;
    [param setFrame:CGRectMake(20, cell.frame.size.height/2 + 5,
                               tableView.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[param getStepper]];
  }
  else if([tmp isKindOfClass:[ParameterNumberRange class]]) {
    ParameterNumberRange *param = (ParameterNumberRange *)tmp;
    [param setFrame:CGRectMake(20, cell.frame.size.height/2 + 10,
                               tableView.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[param getSlider]];
  }
  else if([tmp isKindOfClass:[ParameterNumberTextbox class]]) {
    ParameterNumberTextbox *param = (ParameterNumberTextbox *)tmp;
    [param setFrame:CGRectMake(20, cell.frame.size.height/2 + 10,
                               tableView.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[param getTextbox]];
  }

  return cell;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
  Parameter *param = [[_sections objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
  return [[param class] getHeight];
}

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
  return [_sectionstitle objectAtIndex:section];
}

@end
