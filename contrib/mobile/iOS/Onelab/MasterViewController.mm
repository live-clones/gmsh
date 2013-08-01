//
//  MasterViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "MasterViewController.h"

#import "DetailViewController.h"

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
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(refreshObject:) name:@"refreshParameters" object:nil];
    runButton = [[UIBarButtonItem alloc] initWithTitle:@"Run" style:UIBarButtonItemStyleBordered target:self action:@selector(runWithNewParameter)];
    [runButton setTitle:@"Run"]; // ?? do nothink ??
    self.navigationItem.leftBarButtonItem = runButton;
    

    UIBarButtonItem *addButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh target:self action:@selector(refreshObject:)];
    self.navigationItem.rightBarButtonItem = addButton;
    self.detailViewController = (DetailViewController *)[[self.splitViewController.viewControllers lastObject] topViewController];
    
    _sections = [[NSMutableArray alloc] init];
    _sectionstitle = [[NSMutableArray alloc] init];
}

- (void) getAvailableParam
{
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number);
    for(int i=0;i<number.size();i++)
    {
        if(!number[i].getVisible()) continue;
        NSString *name=[NSString stringWithCString:number[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSArray *splitedname = [name componentsSeparatedByString:@"/"];
        NSString * sectiontitle = [splitedname objectAtIndex:0];
        bool found = false;
        
        for(int j=0;j<[_sectionstitle count];j++)
        {
            NSString *title = [_sectionstitle objectAtIndex:j];
            if([title isEqualToString:@"Post proccessing"])
            {
                [_sections removeObjectAtIndex:j];
                [_sectionstitle removeObjectAtIndex:j];
            }
            if([title isEqualToString:sectiontitle]) // the section already exists
            {
                NSMutableArray *section = [_sections objectAtIndex:j];
                for(int k=0; k<[section count];k++)
                    if([[section objectAtIndex: k] isEqualToString:name]){found = true; break;}
                if(!found)
                    [section addObject:name];
                found = true;
                break;
            }
        }
        if(found) continue;
        // we have to create the section
        NSMutableArray *newSection = [[NSMutableArray alloc] initWithObjects:name, nil];
        [_sections addObject:newSection];
        [_sectionstitle addObject:sectiontitle];
    }
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string);
    for(int i=0;i<string.size();i++)
    {
        if(!string[i].getVisible()) continue;
        if(string[i].getKind() == "file") continue;
        NSString *name=[NSString stringWithCString:string[i].getName().c_str() encoding:[NSString defaultCStringEncoding]];
        NSArray *splitedname = [name componentsSeparatedByString:@"/"];
        NSString * sectiontitle = [splitedname objectAtIndex:0];
        bool found = false;
        
        for(int j=0;j<[_sectionstitle count];j++)
        {
            NSString *title = [_sectionstitle objectAtIndex:j];
            if([title isEqualToString:sectiontitle]) // the section already exists
            {
                NSMutableArray *section = [_sections objectAtIndex:j];
                for(int k=0; k<[section count];k++)
                    if([[section objectAtIndex: k] isEqualToString:name]){found = true; break;} // the parameters is already in the section
                if(!found)
                    [section addObject:name];
                found = true;
                break;
            }
        }
        if(found) continue;
        // we have to create the section
        NSMutableArray *newSection = [[NSMutableArray alloc] initWithObjects:name, nil];
        [_sections addObject:newSection];
        [_sectionstitle addObject:sectiontitle];
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

- (void)refreshObject:(id)sender
{
    onelab_cb("reset");
    [_sections removeAllObjects];
    [_sectionstitle removeAllObjects];
    [self getAvailableParam]; // Get the param
    for(int i=0; i<_sections.count;i++) // Refresh they values
    {
        NSMutableArray *mSection = [_sections objectAtIndex:i];
        for(int n=0; n <mSection.count;n++)
        {
            NSString *paramName = [mSection objectAtIndex:n];
            
            std::vector<onelab::number> number;
            onelab::server::instance()->get(number,[paramName UTF8String]);
            if(number.size() > 0){
                UITableViewCell *cell = [self.tableView cellForRowAtIndexPath: [NSIndexPath indexPathForRow:n inSection:i]];
                UISlider *slider;
                for(UIView *v in cell.subviews)
                {
                    if ([v isKindOfClass:UISlider.class]){
                        UISlider *slider = (UISlider*)v;
                        [slider setValue:number[0].getValue()];
                        break;
                    }
                    else if([v isKindOfClass:UIPickerView.class]){
                        UIView *picker = (UISlider*)v;
                        int index=0;
                        for(int i=0;i<number[0].getChoices().size();i++)
                            if(number[0].getChoices()[i] == number[0].getValue()){index = i; break;}
                        [(UIPickerView *)picker selectRow:index inComponent:0 animated:YES];
                        break;
                    }
                    else if([v isKindOfClass:UITextField.class])
                    {
                        UITextField *text = (UITextField*) v;
                        [text setText:[NSString stringWithFormat:@"%f", number[0].getValue()]];
                        break;
                    }
                }
            }
            std::vector<onelab::string> string;
            onelab::server::instance()->get(string,[paramName UTF8String]);
            if(string.size() > 0) {
                UIView *picker = [self.tableView viewWithTag:(1000*i+n)];
                if([picker isKindOfClass:UIPickerView.class]){
                    int index = -1;
                    for(int i=0;i<string[0].getChoices().size();i++)
                        if(string[0].getChoices()[i] == string[0].getValue()){index = i; break;}
                    if(index >= 0)
                        [(UIPickerView *)picker selectRow:index inComponent:0 animated:YES];
                     }
            }
        }
    }
    [self.tableView reloadData];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

- (void)runWithNewParameter
{
    dispatch_async( dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [runButton setTitle:@"Stop"];
        [self refreshControl];
        [runButton setAction:@selector(stopRunning)];
        onelab_cb("compute");
        [runButton setTitle:@"Run"];
        [self refreshControl];
        [runButton setAction:@selector(runWithNewParameter)];
        [self getAvailableParam];
    });
}

- (void)stopRunning
{
    onelab_cb("stop");
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
    NSString *paramName = [sectionContent objectAtIndex:[indexPath row]];
    std::vector<onelab::number> number;
    std::vector<onelab::string> string;
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:paramName];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:paramName];
    else
        return cell;
    onelab::server::instance()->get(number,[paramName UTF8String]);
    onelab::server::instance()->get(string,[paramName UTF8String]);
    if(number.size() > 0)
    {
        UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        if(number[0].getReadOnly())
        {
            [cell setUserInteractionEnabled:NO];
            lbl.alpha = 0.439216f;
        }
        if(number[0].getLabel() != "")
            [lbl setText:[NSString stringWithCString:number[0].getLabel().c_str()  encoding:[NSString defaultCStringEncoding]]];
        else
            [lbl setText:[NSString stringWithCString:number[0].getName().c_str()  encoding:[NSString defaultCStringEncoding]]];
        
        [lbl setBackgroundColor:[UIColor clearColor]];
        lbl.tag = -(1000 * indexPath.section + indexPath.row);
        [cell addSubview:lbl];
        if(number[0].getChoices().size() && number[0].getChoices().size() == number[0].getValueLabels().size()) // enumeration
        {
            UIPickerView *picker = [[UIPickerView alloc] initWithFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
            
            picker.showsSelectionIndicator = YES;
            picker.tag = 1000 * indexPath.section + indexPath.row;
            [picker setDataSource:self];
            [picker setDelegate:self];
            for(int row=0;row<number[0].getChoices().size();row++)
                if(number[0].getValue() == number[0].getChoices()[row])[picker selectRow:row inComponent:0 animated:NO];
            [cell addSubview:picker];
        }
        else if(number[0].getChoices().size() == 2 && number[0].getChoices()[0] == 0 && number[0].getChoices()[1] == 1) // check box
        {
            UISwitch *swtch = [[UISwitch alloc] initWithFrame:CGRectMake(10, 5, cell.frame.size.width - 40, cell.frame.size.height)];
            lbl.tag = 1000 * indexPath.section + indexPath.row;
            [swtch setSelected:(number[0].getValue() == 1)];
            [lbl setFrame:CGRectMake(100, 5, cell.frame.size.width - 110, cell.frame.size.height)];
            [cell addSubview:swtch];
            
        }
        else if(number[0].getStep() == 0) // text box
        {
            UITextField *textfield = [[UITextField alloc] initWithFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
            textfield.tag = 1000 * indexPath.section + indexPath.row;
            [textfield setBorderStyle:UITextBorderStyleRoundedRect];
            [textfield setText:[NSString stringWithFormat:@"%f",number[0].getValue()]];
            [textfield setKeyboardType:UIKeyboardTypeNumberPad];
            [textfield addTarget:self action:@selector(PViewNbIso:) forControlEvents:UIControlEventValueChanged];
            [textfield setDelegate:self];
            [cell addSubview:textfield];
        }
        else // slider with range
        {
            UISlider *slider = [[UISlider alloc] initWithFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
            slider.tag = 1000 * indexPath.section + indexPath.row;
            [slider setMaximumValue:number[0].getMax()];
            [slider setMinimumValue:number[0].getMin()];
            [slider setValue:number[0].getValue()];
            //TODO add step ?
            [slider addTarget:self action:@selector(sliderValueChanged:) forControlEvents:UIControlEventTouchUpOutside];
            [slider addTarget:self action:@selector(sliderValueChanged:) forControlEvents:UIControlEventTouchUpInside];
            [lbl setText:[NSString stringWithFormat:@"%@ %f" ,[NSString stringWithCString:number[0].getLabel().c_str()  encoding:[NSString defaultCStringEncoding]], number[0].getValue()]];
            [cell addSubview:slider];
        }
        
    }
    else if(string.size() > 0)
    {
        UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(20, 5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        if(string[0].getReadOnly())
        {
            [cell setUserInteractionEnabled:NO];
            lbl.alpha = 0.439216f;
        }
        [lbl setText:[NSString stringWithCString:string[0].getLabel().c_str() encoding:[NSString defaultCStringEncoding]]];
        [lbl setBackgroundColor:[UIColor clearColor]];
        lbl.tag = -(1000 * indexPath.section + indexPath.row);
        UIPickerView *picker = [[UIPickerView alloc] initWithFrame:CGRectMake(20, cell.frame.size.height/2+5, cell.frame.size.width - 40, cell.frame.size.height/2)];
        picker.showsSelectionIndicator = YES;
        picker.tag = 1000 * indexPath.section + indexPath.row;
        [picker setDataSource:self];
        [picker setDelegate:self];
        for(int row=0;row<string[0].getChoices().size();row++)
            if(string[0].getValue() == string[0].getChoices()[row])[picker selectRow:row inComponent:0 animated:NO];
        [cell addSubview:picker];
        [cell addSubview:lbl];
    }
    return cell;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *paramName = [[_sections objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
    
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[paramName UTF8String]);
    if(number.size() > 0){
        if(number[0].getChoices().size() && number[0].getChoices().size() == number[0].getValueLabels().size()) // enumeration
            return 200.f;
        if(number[0].getChoices().size() == 2 && number[0].getChoices()[0] == 0 && number[0].getChoices()[1] == 1) // check box
            return 40.f;
        return 60.f;
    }
    std::vector<onelab::string> string;
    onelab::server::instance()->get(string,[paramName UTF8String]);
    if(string.size() > 0) return 200.f;
    return 50.f;
}

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [_sectionstitle objectAtIndex:section];
}

-(void)sliderValueChanged:(UISlider *)sender
{
    int nsection = (int)(sender.tag/1000), nrow = sender.tag%1000;
    NSString *title = [[_sections objectAtIndex:nsection] objectAtIndex:nrow];
        
    std::vector<onelab::number> number;
    onelab::server::instance()->get(number,[title UTF8String]);
    number[0].setValue(sender.value);
    onelab::server::instance()->set(number[0]);
    UITableViewCell *cell = [self.tableView cellForRowAtIndexPath: [NSIndexPath indexPathForRow:nrow inSection:nsection]];
    UILabel *lbl = nil;
    for(UIView *v in cell.subviews)
        if ([v isKindOfClass:UILabel.class]){
            lbl = (UILabel*)v;
            break;
        }
    if(lbl != nil)
        [lbl setText:[NSString stringWithFormat:@"%s %f" ,number[0].getLabel().c_str(), sender.value]];
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

#pragma mark - pickerView

-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    int nsection = (int)(pickerView.tag/1000), nrow = pickerView.tag%1000;
    NSString *title = [[_sections objectAtIndex:nsection] objectAtIndex:nrow];
    
    std::vector<onelab::string> string;
    std::vector<onelab::number> number;
    onelab::server::instance()->get(string,[title UTF8String]);
    onelab::server::instance()->get(number,[title UTF8String]);

    if(string.size() > 0) return string[0].getChoices().size();
    else if(number.size() > 0) return number[0].getChoices().size();
    else return 0;
}
-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    int nsection = (int)(pickerView.tag/1000), nrow = pickerView.tag%1000;
    NSString *title = [[_sections objectAtIndex:nsection] objectAtIndex:nrow];
    
    std::vector<onelab::string> string;
    std::vector<onelab::number> number;
    onelab::server::instance()->get(string,[title UTF8String]);
    onelab::server::instance()->get(number,[title UTF8String]);
    
    if(string.size() > 0)
    {
        return [NSString stringWithCString:string[0].getChoices()[row].c_str() encoding:[NSString defaultCStringEncoding]];
    }
    else if(number.size() > 0) return [NSString stringWithCString:number[0].getValueLabel(number[0].getChoices()[row]).c_str() encoding:[NSString defaultCStringEncoding]];
    else return @"?";
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    int nsection = (int)(pickerView.tag/1000), nrow = pickerView.tag%1000;
    NSString *title = [[_sections objectAtIndex:nsection] objectAtIndex:nrow];
    
    std::vector<onelab::string> string;
    std::vector<onelab::number> number;
    onelab::server::instance()->get(string,[title UTF8String]);
    onelab::server::instance()->get(number,[title UTF8String]);

    int index = [pickerView selectedRowInComponent:0];
    if(string.size() > 0)
    {
        std::string selected = string[0].getChoices()[index];
        string[0].setValue(selected);
        onelab::server::instance()->set(string[0]);
    }
    else if(number.size() > 0)
    {
        double selected = number[0].getChoices()[index];
        number[0].setValue(selected);
        onelab::server::instance()->set(number[0]);
    }
    if(onelab_cb("check") == 1)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

#pragma mark - textfield

-(BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    int nsection = (int)(textField.tag/1000), nrow = textField.tag%1000;
    NSString *title = [[_sections objectAtIndex:nsection] objectAtIndex:nrow];
    
    std::vector<onelab::string> string;
    std::vector<onelab::number> number;
    onelab::server::instance()->get(string,[title UTF8String]);
    onelab::server::instance()->get(number,[title UTF8String]);
    
    if(number.size() > 0)
    {
        number[0].setValue([textField.text doubleValue]);
        onelab::server::instance()->set(number[0]);
    }
    else if(string.size() > 0)
    {
        string[0].setValue([textField.text UTF8String]);
        onelab::server::instance()->set(string[0]);
    }
    return YES;
}
-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField endEditing:YES];
    return YES;
}

@end
