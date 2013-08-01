//
//  ModelListController.h
//  Onelab
//
//  Created by Maxime Graulich on 31/07/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AppDelegate.h"
#import "EAGLView.h"

@interface ModelListController : UITableViewController
{
    @private
    NSArray *models;
}
@property (nonatomic, retain) EAGLView *glView;
@end
