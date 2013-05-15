//
//  DetailViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EAGLView.h"
#import "AppDelegate.h"

#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

#import "iosGModel.h"

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate, UITextFieldDelegate, UIActionSheetDelegate, UITableViewDelegate, UITableViewDataSource>
{
    @private
    double scaleFactor;
    iosGModel *mIosGModel;
    NSArray *models;
}

- (IBAction)pinch:(UIPinchGestureRecognizer *)sender;
- (IBAction)tap:(UITapGestureRecognizer *)sender;

@property (nonatomic, retain) EAGLView *glView;
@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end
