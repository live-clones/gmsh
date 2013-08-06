//
//  SplitViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 05/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MasterViewController.h"
#import "DetailViewController.h"

@interface SplitViewController : UISplitViewController{
    DetailViewController *detailViewController;
    MasterViewController *masterViewController;
}

@property (nonatomic, retain) NSString *initialModel;

@end
