//
//  MasterViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Gmsh/onelab.h>

@class DetailViewController;

@interface MasterViewController : UITableViewController
{
    @private
    NSMutableArray *_sections;
    NSMutableArray *_sectionstitle;
    
    UIBarButtonItem *runButton;
    UIBarButtonItem *stopButton;
}

@property (strong, nonatomic) DetailViewController *detailViewController;

- (void)resetParameters:(id)sender;

@end
