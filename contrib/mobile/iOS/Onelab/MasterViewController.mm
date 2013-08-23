//
//  MasterViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"
#import "PostProViewController.h"
#import "AppDelegate.h"
#import "parameter.h"

@interface MasterViewController () {

}
@end

@implementation MasterViewController

- (void)awakeFromNib
{
    self.clearsSelectionOnViewWillAppear = NO;
    self.contentSizeForViewInPopover = CGSizeMake(320.0, 600.0);
    [super awakeFromNib];
}

- (void)viewDidLoad
{
    [super viewDidLoad];

	// Do any additional setup after loading the view, typically from a nib.
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshParameters:) name:@"refreshParameters" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resetParameters:) name:@"resetParameters" object:nil];

	self.navigationItem.title = @"Parameters";

    if(((AppDelegate *)[UIApplication sharedApplication].delegate)->compute){ // Only on iPhone/iPod
        runButton = [[UIBarButtonItem alloc] initWithTitle:@"Stop" style:UIBarButtonItemStyleBordered target:self action:@selector(stopRunning)];
        [runButton setTitle:@"Stop"];
        
    }
    else {
        runButton = [[UIBarButtonItem alloc] initWithTitle:@"Run" style:UIBarButtonItemStyleBordered target:self action:@selector(runWithNewParameter:)];
        [runButton setTitle:@"Run"];
    }
	runButton.possibleTitles = [NSSet setWithObjects:@"Run", @"Stop", nil];
    self.navigationItem.leftItemsSupplementBackButton = YES; // Only for iPhone/iPod
    self.navigationItem.leftBarButtonItem = runButton;
    
    _sections = [[NSMutableArray alloc] init];
    _sectionstitle = [[NSMutableArray alloc] init];
	
	[self.navigationController setToolbarHidden:NO];
	control = [[UISegmentedControl alloc] initWithItems:[[NSArray alloc] initWithObjects:@"Parmeters", @"Views", nil]];
	control.segmentedControlStyle = UISegmentedControlStyleBar;
	UIBarButtonItem *controlBtn = [[UIBarButtonItem alloc] initWithCustomView:control];
	UIBarButtonItem *flexibleSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
	self.toolbarItems = [[NSArray alloc] initWithObjects:flexibleSpace, controlBtn, flexibleSpace, nil];
	[control addTarget:self action:@selector(indexDidChangeForSegmentedControl:) forControlEvents:UIControlEventValueChanged];
}
- (void)viewWillAppear:(BOOL)animated
{
    [self refreshParameters:nil];
	control.selectedSegmentIndex = 0;
	[super viewWillAppear:animated];
}

- (void)indexDidChangeForSegmentedControl:(id)sender
{
	PostProViewController *postProViewController = [[PostProViewController alloc] init];
	[postProViewController setPreviousViewController:self];
	//[self.navigationController setViewControllers:[[NSArray alloc] initWithObjects:postProViewController, nil] animated:NO];
	[postProViewController.navigationItem setHidesBackButton:YES];
	[self.navigationController pushViewController:postProViewController animated:YES];
}
- (void)addParameterNumber:(onelab::number)p atIndexPath:(NSIndexPath*)indexPath
{
	NSLog(@"Add %s at (%d,%d)", p.getName().c_str(), indexPath.section, indexPath.row);
	NSMutableArray* section = [_sections objectAtIndex:indexPath.section];
	if(p.getChoices().size() && p.getChoices().size() == p.getValueLabels().size()) { // enumeration
        parameterNumberList *param = [[parameterNumberList alloc] initWithNumber:p];
        [section addObject:param];
    }
    else if(p.getChoices().size() == 2 && p.getChoices()[0] == 0 && p.getChoices()[1] == 1) { // check box
        parameterNumberCheckbox *param = [[parameterNumberCheckbox alloc] initWithNumber:p];
        [section addObject:param];
    }
    else if(p.getStep() == 0) { // text box
        parameterNumberTextbox *param = [[parameterNumberTextbox alloc] initWithNumber:p];
        [section addObject:param];
    }
    else
    {
        parameterNumberRange *param = [[parameterNumberRange alloc] initWithNumber:p];
        [section addObject:param];
    }
	[self.tableView beginUpdates];
	[self.tableView insertRowsAtIndexPaths:[[NSArray alloc] initWithObjects:indexPath, nil] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
}
- (void)addParameterString:(onelab::string)p atIndexPath:(NSIndexPath*)indexPath
{
	NSMutableArray* section = [_sections objectAtIndex:indexPath.section];
	parameterStringList *param = [[parameterStringList alloc] initWithString:p];
    [section addObject:param];
	[self.tableView beginUpdates];
	[self.tableView insertRowsAtIndexPaths:[[NSArray alloc] initWithObjects:indexPath, nil] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
}
- (void)addSection:(NSMutableArray*)s withTitle:(NSString*)t withParameterNumber:(onelab::number)p
{
	[_sections addObject:s];
	[_sectionstitle addObject:t];
	[self.tableView beginUpdates];
	[self.tableView insertSections:[[NSIndexSet alloc] initWithIndex:[_sections count]-1] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
	[self addParameterNumber:p atIndexPath:[NSIndexPath indexPathForRow:0 inSection:[_sections count]-1]];
}
- (void)addSection:(NSMutableArray*)s withTitle:(NSString*)t withParameterString:(onelab::string)p
{
	[_sections addObject:s];
	[_sectionstitle addObject:t];
	[self.tableView beginUpdates];
	[self.tableView insertSections:[[NSIndexSet alloc] initWithIndex:[_sections count]-1] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
	[self addParameterString:p atIndexPath:[NSIndexPath indexPathForRow:0 inSection:[_sections count]-1]];
}
- (void)refreshTableView
{
	if(!_lastRefresh) _lastRefresh = [NSDate date];
	else {
		if([_lastRefresh timeIntervalSinceNow] >= -1) return;
		_lastRefresh = [NSDate date];
	}
	std::vector<onelab::number> number;
    onelab::server::instance()->get(number);

	//
	for(int i=0;i<number.size();i++) {
		if(!number[i].getVisible()) continue; // Do not add invisible parameter
		NSString *name=[NSString stringWithCString:number[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSString *sectiontitle = [[name componentsSeparatedByString:@"/"] objectAtIndex:0];
		Boolean found = false;
		
		for(int iSection=0; iSection<[_sectionstitle count]; iSection++) { // Check if the section exist
			if([sectiontitle isEqualToString:[_sectionstitle objectAtIndex:iSection]]) {
				NSMutableArray *section = [_sections objectAtIndex:iSection];
				for(int iparameter = 0; iparameter<[section count]; iparameter++) {
					if([[[section objectAtIndex: iparameter] getName] isEqualToString:name]) { // The parameter is in the section
						parameter * p = [section objectAtIndex: iparameter];
						[p refresh]; // just refresh the parameter
                        found = true;
                        break;
					}
				}
				if(!found) // The parameter is not in the section, add it
					[self addParameterNumber:number[i] atIndexPath:[NSIndexPath indexPathForRow:[section count] inSection:iSection]];
				found = true; break;
			}
		}
		if(found) continue; // the parameter is in the tableView
		// The section have to be create
		NSMutableArray *newSection = [[NSMutableArray alloc] init];
		[self addSection:newSection withTitle:sectiontitle withParameterNumber:number[0]];
	}
	std::vector<onelab::string> string;
    onelab::server::instance()->get(string);
	
	//
	for(int i=0;i<string.size();i++) {
		if(!string[i].getVisible() || string[i].getKind() == "file") continue; // Do not add invisible parameter
		NSString *name=[NSString stringWithCString:string[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSString *sectiontitle = [[name componentsSeparatedByString:@"/"] objectAtIndex:0];
		Boolean found = false;
		
		for(int iSection=0; iSection<[_sectionstitle count]; iSection++) { // Check if the section exist
			if([sectiontitle isEqualToString:[_sectionstitle objectAtIndex:iSection]]) {
				NSMutableArray *section = [_sections objectAtIndex:iSection];
				for(int iparameter = 0; iparameter<[section count]; iparameter++) {
					if([[[section objectAtIndex: iparameter] getName] isEqualToString:name]) { // The parameter is in the section
						parameter * p = [section objectAtIndex: iparameter];
						[p refresh]; // just refresh the parameter
                        found = true;
                        break;
					}
				}
				if(!found) // The parameter is not in the section, add it
					[self addParameterString:string[i] atIndexPath:[NSIndexPath indexPathForRow:[section count] inSection:iSection]];
				found = true; break;
			}
		}
		if(found) continue; // the parameter is in the tableView
		// The section have to be create
		NSMutableArray *newSection = [[NSMutableArray alloc] init];
		[self addSection:newSection withTitle:sectiontitle withParameterString:string[0]];
	}
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
	[self refreshTableView]; // Get the param
	[self.tableView setNeedsDisplay];
}
- (void)resetParameters:(id)sender
{
    onelab_cb("reset");
    [_sections removeAllObjects];
    [_sectionstitle removeAllObjects];
    [self.tableView reloadData];
    [self refreshParameters:sender];
    onelab_cb("check");
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)runWithNewParameter:(UIBarButtonItem *)sender
{
    dispatch_async( dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
        appDelegate->compute = YES;
        [sender setTitle:@"Stop"];
		[sender setAction:@selector(stopRunning)];
        self.navigationItem.rightBarButtonItem.enabled = NO;
        onelab_cb("compute");
        if([[UIDevice currentDevice].model isEqualToString:@"iPad"] || [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
            [sender setTitle:@"Run"];
            [sender setAction:@selector(runWithNewParameter:)];
            self.navigationItem.rightBarButtonItem.enabled = YES;
        }
        appDelegate->compute = NO;
    });
    if(![[UIDevice currentDevice].model isEqualToString:@"iPad"] && ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
        [self.navigationController popViewControllerAnimated:YES];
}

- (void)stopRunning
{
    onelab_cb("stop");
    if(![[UIDevice currentDevice].model isEqualToString:@"iPad"] && ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"])
        [self.navigationController popViewControllerAnimated:YES];
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
	if(indexPath.section >= _sections.count) return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    NSMutableArray *sectionContent = [_sections objectAtIndex:[indexPath section]];
	if(indexPath.row >= sectionContent.count) return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    parameter *tmp = [sectionContent objectAtIndex:[indexPath row]];
    
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    else
        return cell;
	[cell setSelectionStyle:UITableViewCellSelectionStyleNone];
    [cell setUserInteractionEnabled:!([tmp isReadOnly])];
    [tmp setLabelFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[tmp getLabel]];
    if([tmp isKindOfClass:[parameterStringList class]]) {
        parameterStringList *param = (parameterStringList *)tmp;
        [param setFrame:CGRectMake(20, 35, cell.frame.size.width - 40, 162)];
        [cell addSubview:[param getList]];
    }
    else if([tmp isKindOfClass:[parameterNumberList class]]) {
        parameterNumberList *param = (parameterNumberList *)tmp;
        [param setFrame:CGRectMake(20, 35, cell.frame.size.width - 40, 162)];
        [cell addSubview:[param getList]];
    }
    else if([tmp isKindOfClass:[parameterNumberCheckbox class]]) {
        parameterNumberCheckbox *param = (parameterNumberCheckbox *)tmp;
        [param setLabelFrame:CGRectMake(100, 5, cell.frame.size.width - 110, cell.frame.size.height)];
        [param setFrame:CGRectMake(10, 5, cell.frame.size.width - 40, cell.frame.size.height)];
        [cell addSubview:[param getCheckbox]];
    }
    else if([tmp isKindOfClass:[parameterNumberRange class]]) {
        parameterNumberRange *param = (parameterNumberRange *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getSlider]];
    }
    else if([tmp isKindOfClass:[parameterNumberTextbox class]]) {
        parameterNumberTextbox *param = (parameterNumberTextbox *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getTextbox]];
    }
        
    return cell;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    parameter *param = [[_sections objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
    return [[param class] getHeight];
}

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [_sectionstitle objectAtIndex:section];
}
@end
