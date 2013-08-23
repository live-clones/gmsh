//
//  PostProcessingViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 22/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "PostProcessingViewController.h"

@interface PostProcessingViewController ()

@end

@implementation PostProcessingViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)setPView:(PView*)p
{
    _pview = p;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
    if(_pview)
    {
        [_Name setText:[NSString stringWithCString:_pview->getData()->getName().c_str() encoding:[NSString defaultCStringEncoding]]];
        [_IntervalsType setDataSource:self];
        [_IntervalsType setDelegate:self];
        [_IntervalsType selectRow:_pview->getOptions()->intervalsType-1 inComponent:0 animated:YES];
        [_Intervals setText:[NSString stringWithFormat:@"%d",_pview->getOptions()->nbIso]];
        [_RaiseZ setValue:_pview->getOptions()->raise[2]];
        [_RaiseZ addTarget:self action:@selector(slideRaiseZ:) forControlEvents:UIControlEventValueChanged];
    }
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}
-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return 3;
}
-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    NSArray *name = [[NSArray alloc] initWithObjects:@"Iso-values", @"Continuous map", @"Filled iso-values", nil];
    return [name objectAtIndex:row];
}
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    _pview->getOptions()->intervalsType = 1+row;
    _pview->setChanged(true);
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
- (void)slideRaiseZ:(UISlider*)sender
{
    _pview->getOptions()->raise[2] = sender.value;
    _pview->setChanged(true);
    [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender" object:nil];
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidUnload {
    [self setName:nil];
    [self setIntervalsType:nil];
    [self setIntervals:nil];
    [self setRaiseZ:nil];
    [super viewDidUnload];
}
@end
