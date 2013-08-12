//
//  MasterViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"
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
    if(((AppDelegate *)[UIApplication sharedApplication].delegate)->compute){ // Only on iPhone/iPod
        runButton = [[UIBarButtonItem alloc] initWithTitle:@"Stop" style:UIBarButtonItemStyleBordered target:self action:@selector(stopRunning)];
        [runButton setTitle:@"Stop"];
        
    }
    else {
        runButton = [[UIBarButtonItem alloc] initWithTitle:@"Run" style:UIBarButtonItemStyleBordered target:self action:@selector(runWithNewParameter)];
        [runButton setTitle:@"Run"];
    }
    self.navigationItem.leftItemsSupplementBackButton = YES; // Only on iPhone/iPod
    self.navigationItem.leftBarButtonItem = runButton;

    UIBarButtonItem *refresh = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh target:self action:@selector(resetParameters:)];
    self.navigationItem.rightBarButtonItem = refresh;
    self.detailViewController = (DetailViewController *)[[self.splitViewController.viewControllers lastObject] topViewController];
    
    _sections = [[NSMutableArray alloc] init];
    _sectionstitle = [[NSMutableArray alloc] init];
}

- (void) addParameterNumber:(onelab::number)p inSection:(NSMutableArray*)section
{
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
}
- (void) addParameterString:(onelab::string)p inSection:(NSMutableArray*)section
{
    parameterStringList *param = [[parameterStringList alloc] initWithString:p];
    [section addObject:param];
}

- (void) getAvailableParam
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number);
    for(int i=0;i<number.size();i++)
    {
        if(!number[i].getVisible()) continue;
        NSString *name=[NSString stringWithCString:number[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSString * sectiontitle = [[name componentsSeparatedByString:@"/"] objectAtIndex:0];
        bool found = false;
        
        for(int j=0;j<[_sectionstitle count];j++)
        {
            NSString *title = [_sectionstitle objectAtIndex:j];
            if([title isEqualToString:sectiontitle]) // the section already exists
            {
                NSMutableArray *section = [_sections objectAtIndex:j];
                for(int k=0; k<[section count];k++)
                    if([[[section objectAtIndex: k] getName] isEqualToString:name]) {
                        found = true;
                        break;
                    }
                if(!found)
                    [self addParameterNumber:number[i] inSection:section];
                found = true;
                break;
            }
        }
        if(found) continue;
        // we have to create the section
        NSMutableArray *newSection = [[NSMutableArray alloc] init];
        [_sections addObject:newSection];
        [_sectionstitle addObject:sectiontitle];
        [self addParameterNumber:number[i] inSection:[_sections lastObject]];
    }
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string);
    for(int i=0;i<string.size();i++)
    {
        if(!string[i].getVisible()) continue;
        if(string[i].getKind() == "file") continue;
        NSString *name=[NSString stringWithCString:string[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSString * sectiontitle = [[name componentsSeparatedByString:@"/"] objectAtIndex:0];
        bool found = false;
        
        for(int j=0;j<[_sectionstitle count];j++)
        {
            NSString *title = [_sectionstitle objectAtIndex:j];
            if([title isEqualToString:sectiontitle]) // the section already exists
            {
                NSMutableArray *section = [_sections objectAtIndex:j];
                for(int k=0; k<[section count];k++)
                    if([[(parameter*)[section objectAtIndex: k] getName] isEqualToString:name]) {
                        found = true;
                        break;
                    } // the parameters is already in the section
                if(!found)
                    [self addParameterString:string[i] inSection:section];
                found = true;
                break;
            }
        }
        if(found) continue;
        // we have to create the section
        NSMutableArray *newSection = [[NSMutableArray alloc] init];
        [_sections addObject:newSection];
        [_sectionstitle addObject:sectiontitle];
        [self addParameterString:string[i] inSection:[_sections lastObject]];
    }
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [self getAvailableParam];
    [self.tableView reloadData];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}
- (void)refreshParameters:(id)sender
{
    [self getAvailableParam]; // Get the param
    [self.tableView reloadData];
}
- (void)resetParameters:(id)sender
{
    onelab_cb("reset");
    [_sections removeAllObjects];
    [_sectionstitle removeAllObjects];
    [self.tableView reloadData];
    [self getAvailableParam]; // Get the param
    [self.tableView reloadData];
    onelab_cb("check");
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)runWithNewParameter
{
    dispatch_async( dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
        appDelegate->compute = YES;
        [runButton setTitle:@"Stop"];
        [self.navigationController.view setNeedsDisplay];
        [runButton setAction:@selector(stopRunning)];
        self.navigationItem.rightBarButtonItem.enabled = NO;
        onelab_cb("compute");
        if([[UIDevice currentDevice].model isEqualToString:@"iPad"] || [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
            [runButton setTitle:@"Run"];
            [self.navigationController.view setNeedsDisplay];
            [runButton setAction:@selector(runWithNewParameter)];
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
    NSMutableArray *sectionContent = [_sections objectAtIndex:[indexPath section]];
    parameter *tmp = [sectionContent objectAtIndex:[indexPath row]];
    
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[[tmp getLabel] text]];
    else
        return cell;
    [cell setUserInteractionEnabled:!([tmp isReadOnly])];
    [tmp setLabelFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height/2)];
    [cell addSubview:[tmp getLabel]];
    if([tmp isKindOfClass:[parameterStringList class]]) {
        parameterStringList *param = (parameterStringList *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        [cell addSubview:[param getList]];
    }
    else if([tmp isKindOfClass:[parameterNumberList class]]) {
        parameterNumberList *param = (parameterNumberList *)tmp;
        [param setFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
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
