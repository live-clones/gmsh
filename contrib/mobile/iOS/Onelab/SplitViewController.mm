//
//  SplitViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 05/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "SplitViewController.h"

@interface SplitViewController ()

@end

@implementation SplitViewController

-(void)viewDidAppear:(BOOL)animated
{
    //UINavigationController *left = [self.viewControllers objectAtIndex:0]; // left UINavigationController (Master)
    UINavigationController *right = [self.viewControllers objectAtIndex:1]; // right UINavigationController (Detail)
    for(UIViewController *v in right.viewControllers){
        if ([v isKindOfClass:[DetailViewController class]]) {
            detailViewController = (DetailViewController *)v;
        }
    }
    if(self.initialModel != nil) [detailViewController.glView load:self.initialModel];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
