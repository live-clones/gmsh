//
//  PostProViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 13/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "PostProViewController.h"

#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

@interface PostProViewController ()

@end

@implementation PostProViewController

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

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return PView::list.size();
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"postproCell"];
    else
        return cell;
    [cell setFrame:CGRectMake(cell.frame.origin.x, cell.frame.origin.x, tableView.frame.size.width, cell.frame.size.height)];
    int i = PView::list.size() - 1 - indexPath.row;
    UISwitch *showHide = [[UISwitch alloc] initWithFrame: CGRectMake(10, 10, 100, 30)];
    UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(10 + (showHide.frame.size.width), 10, (cell.bounds.size.width - 100)/3, 30)];
    lbl.textAlignment = NSTextAlignmentCenter;
    UIButton *intervalType = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    intervalType.frame = CGRectMake(10 + showHide.frame.size.width + lbl.frame.size.width, 10, (cell.bounds.size.width - 100)/3, 30);
    UITextField *nbIso = [[UITextField alloc] initWithFrame:CGRectMake(10 + showHide.frame.size.width + lbl.frame.size.width + intervalType.frame.size.width, 10, (cell.bounds.size.width - 100)/3, 30)];
    [showHide setOn:(PView::list[i]->getOptions()->visible == 1)];
    [showHide setTag:i];
    [showHide addTarget:self action:@selector(PViewVisible:) forControlEvents:UIControlEventValueChanged];
    [lbl setBackgroundColor: [UIColor clearColor]];
    [lbl setText:[NSString stringWithCString:PView::list[i]->getData()->getName().c_str() encoding:[NSString defaultCStringEncoding]]];
    [intervalType setTag:i];
    switch (PView::list[i]->getOptions()->intervalsType) {
        case 3: // ISO
            [intervalType setTitle:@"Use Iso-values" forState:UIControlStateNormal];
            break;
        case 1: // CONTINIOUS
            [intervalType setTitle:@"Use Continous map" forState:UIControlStateNormal];
            break;
        case 2: // DISCRETE
            [intervalType setTitle:@"Use Filled iso-values" forState:UIControlStateNormal];
            break;
    }
    [intervalType addTarget:self action:@selector(PViewIntervalType:) forControlEvents:UIControlEventTouchDown];
    [nbIso setBorderStyle:UITextBorderStyleRoundedRect];
    [nbIso setText:[NSString stringWithFormat:@"%d",PView::list[i]->getOptions()->nbIso]];
    [nbIso setKeyboardType:UIKeyboardTypeNumberPad];
    [nbIso addTarget:self action:@selector(PViewNbIso:) forControlEvents:UIControlEventValueChanged];
    [nbIso setTag:i];
    [nbIso setDelegate:self];
    [cell addSubview:nbIso];
    [cell addSubview:intervalType];
    [cell addSubview:showHide];
    [cell addSubview:lbl];
    return cell;
}

-(IBAction)PViewVisible:(id)sender
{
    PView::list[((UISwitch*)sender).tag]->getOptions()->visible = (((UISwitch*)sender).on)? 1 : 0;
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

-(IBAction)PViewIntervalType:(id)sender
{
    if( [[((UIButton *)sender) titleForState:UIControlStateNormal] isEqual: @"Use Iso-values"])
    {
        [((UIButton *)sender) setTitle:@"Use Continous map" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 1;
    }
    else if( [[((UIButton *)sender) titleForState:UIControlStateNormal] isEqual: @"Use Continous map"])
    {
        [((UIButton *)sender) setTitle:@"Use Filled iso-values" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 2;
    }
    else if( [[((UIButton *)sender) titleForState:UIControlStateNormal] isEqual: @"Use Filled iso-values"])
    {
        [((UIButton *)sender) setTitle:@"Use Iso-values" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 3;
    }
    PView::list[((UIButton *)sender).tag]->setChanged(true);
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}

#pragma mark - textfield

-(BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    NSInteger val = [textField.text integerValue];
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
