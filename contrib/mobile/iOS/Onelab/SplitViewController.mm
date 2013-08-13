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
	UINavigationController *right = [self.viewControllers objectAtIndex:1]; // right UINavigationController (Detail)
    for(UIViewController *v in right.viewControllers){
        if ([v isKindOfClass:[DetailViewController class]]) {
            detailViewController = (DetailViewController *)v;
        }
    }
    /*UINavigationController *left = [self.viewControllers objectAtIndex:0]; // left UINavigationController (Master)
	 for(UIViewController *v in left.viewControllers){
	 if ([v isKindOfClass:[MasterViewController class]]) {
	 masterViewController = (MasterViewController *)v;
	 }
	 }*/
	self.delegate = detailViewController;
	[self setPresentsWithGesture:NO];
}

-(void)viewDidAppear:(BOOL)animated
{
	if(self.initialModel != nil) [detailViewController.glView load:self.initialModel];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
