//
//  MasterViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "ParametersViewController.h"
#import "ModelViewController.h"
#import "OptionsViewController.h"
#import "AppDelegate.h"
#import "parameter.h"

@interface ParametersViewController () {

}
@end

@implementation ParametersViewController

- (void)awakeFromNib
{
    self.clearsSelectionOnViewWillAppear = NO;
	self.preferredContentSize = CGSizeMake(320.0, 600.0);
    [super awakeFromNib];
}

- (void)viewDidLoad
{
    [super viewDidLoad];

	// Do any additional setup after loading the view, typically from a nib.
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshParameters:) name:@"refreshParameters" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resetParameters:) name:@"resetParameters" object:nil];

	self.navigationItem.title = @"Model";
    
    _sections = [[NSMutableArray alloc] init];
    _sectionstitle = [[NSMutableArray alloc] init];
	
	[self.navigationController setToolbarHidden:NO];
	control = [[UISegmentedControl alloc] initWithItems:[[NSArray alloc] initWithObjects:@"Model", @"Display", nil]];
	UIBarButtonItem *controlBtn = [[UIBarButtonItem alloc] initWithCustomView:control];
	UIBarButtonItem *flexibleSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
	self.toolbarItems = [[NSArray alloc] initWithObjects:flexibleSpace, controlBtn, flexibleSpace, nil];
	[control addTarget:self action:@selector(indexDidChangeForSegmentedControl:) forControlEvents:UIControlEventValueChanged];
	if(![[UIDevice currentDevice].model isEqualToString:@"iPad"] && ![[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain target:self action:@selector(backButtonPressed:)];
    }
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Reset" style:UIBarButtonItemStyleBordered target:self action:@selector(resetParameters:)];
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

- (void)indexDidChangeForSegmentedControl:(id)sender
{
	OptionsViewController *optionsViewController = [[OptionsViewController alloc] init];
	[self.navigationController pushViewController:optionsViewController animated:YES];
}
- (void)addParameterNumber:(onelab::number)p atIndexPath:(NSIndexPath*)indexPath
{
	NSMutableArray* section = [_sections objectAtIndex:indexPath.section];
	if(p.getChoices().size() && p.getChoices().size() == p.getValueLabels().size()) { // enumeration
        ParameterNumberList *param = [[ParameterNumberList alloc] initWithNumber:p];
        [section addObject:param];
    }
    else if(p.getChoices().size() == 2 && p.getChoices()[0] == 0 && p.getChoices()[1] == 1) { // check box
        ParameterNumberCheckbox *param = [[ParameterNumberCheckbox alloc] initWithNumber:p];
        [section addObject:param];
    }
    else if(p.getStep() == 0) { // text box
        ParameterNumberTextbox *param = [[ParameterNumberTextbox alloc] initWithNumber:p];
        [section addObject:param];
    }
    else
    {
        ParameterNumberRange *param = [[ParameterNumberRange alloc] initWithNumber:p];
        [section addObject:param];
    }
	[self.tableView beginUpdates];
	[self.tableView insertRowsAtIndexPaths:[[NSArray alloc] initWithObjects:indexPath, nil] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
}
- (void)addParameterString:(onelab::string)p atIndexPath:(NSIndexPath*)indexPath
{
	NSMutableArray* section = [_sections objectAtIndex:indexPath.section];
	ParameterStringList *param = [[ParameterStringList alloc] initWithString:p];
    [section addObject:param];
	[self.tableView beginUpdates];
	[self.tableView insertRowsAtIndexPaths:[[NSArray alloc] initWithObjects:indexPath, nil] withRowAnimation:UITableViewRowAnimationAutomatic];
	[self.tableView endUpdates];
}
- (void)removeParemeterNumber:(onelab::number)p atIndex:(NSIndexPath*)index
{
	[self.tableView beginUpdates];
	[self.tableView deleteRowsAtIndexPaths: [NSArray arrayWithObject:index] withRowAnimation:UITableViewRowAnimationAutomatic];
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
						Parameter * p = [section objectAtIndex: iparameter];
						if(number[i].getVisible())
							[p refresh]; // just refresh the parameter
						else
							[self removeParemeterNumber:number[i] atIndex:[NSIndexPath indexPathForRow:iparameter inSection:iSection]];
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
						Parameter * p = [section objectAtIndex: iparameter];
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
	[self performSelectorOnMainThread:@selector(refreshParameters) withObject:nil waitUntilDone:NO];
}
- (void)refreshParameters
{
	if(!_lastRefresh) _lastRefresh = [NSDate date];
	else {
		if([_lastRefresh timeIntervalSinceNow] >= -1) return;
		_lastRefresh = [NSDate date];
	}
	[self refreshTableView]; // Get the param
}
- (void)resetParameters:(id)sender
{
	if(((AppDelegate *)[UIApplication sharedApplication].delegate)->compute) {
        UIAlertView *alert;
        alert = [[UIAlertView alloc] initWithTitle:@"Can't reset model's parameters" message:@"The compute have to be finished before you can reset model's parameters." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
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
	if(indexPath.section >= _sections.count) return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    NSMutableArray *sectionContent = [_sections objectAtIndex:[indexPath section]];
	if(indexPath.row >= sectionContent.count) return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    Parameter *tmp = [sectionContent objectAtIndex:[indexPath row]];
    
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    else {
		cell = nil;
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
	}
	[cell setSelectionStyle:UITableViewCellSelectionStyleNone];
    [cell setUserInteractionEnabled:!([tmp isReadOnly])];
    [tmp setLabelFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[tmp getLabel]];
    if([tmp isKindOfClass:[ParameterStringList class]]) {
        ParameterStringList *param = (ParameterStringList *)tmp;
        [param setFrame:CGRectMake(20, 35, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getUIView]];
    }
    else if([tmp isKindOfClass:[ParameterNumberList class]]) {
        ParameterNumberList *param = (ParameterNumberList *)tmp;
        [param setFrame:CGRectMake(20, 35, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getUIView]];
    }
    else if([tmp isKindOfClass:[ParameterNumberCheckbox class]]) {
        ParameterNumberCheckbox *param = (ParameterNumberCheckbox *)tmp;
        [param setLabelFrame:CGRectMake(100, 5, cell.frame.size.width - 110, cell.frame.size.height)];
        [param setFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height)];
        [cell addSubview:[param getCheckbox]];
    }
    else if([tmp isKindOfClass:[ParameterNumberRange class]]) {
        ParameterNumberRange *param = (ParameterNumberRange *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getSlider]];
    }
    else if([tmp isKindOfClass:[ParameterNumberTextbox class]]) {
        ParameterNumberTextbox *param = (ParameterNumberTextbox *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
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
