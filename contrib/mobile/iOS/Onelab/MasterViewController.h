//
//  MasterViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Gmsh/onelab.h>

#import "AppDelegate.h"

@class DetailViewController;

@interface MasterViewController : UITableViewController <UIPickerViewDataSource, UIPickerViewDelegate, UITextFieldDelegate>
{
    @private
    NSMutableArray *_sections;
    NSMutableArray *_sectionstitle;
    
    UIBarButtonItem *runButton;
    UIBarButtonItem *stopButton;
}

@property (strong, nonatomic) DetailViewController *detailViewController;

@end
