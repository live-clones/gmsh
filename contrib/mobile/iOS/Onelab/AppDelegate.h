//
//  AppDelegate.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "SplitViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>{
    @public
}

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UITableViewController *modelListController;
@property (strong, nonatomic) SplitViewController *splitViewController;

@end

