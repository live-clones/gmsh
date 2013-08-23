//
//  SplitViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 05/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ParametersViewController.h"
#import "ModelViewController.h"

@interface SplitViewController : UISplitViewController{
    ModelViewController *modelViewController;
    ParametersViewController *parametersViewController;
}

@property (nonatomic, retain) NSString *initialModel;

@end
