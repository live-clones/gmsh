//
//  DetailViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EAGLView.h"

@interface ModelViewController : UIViewController <UISplitViewControllerDelegate, UIActionSheetDelegate>
{
    @private
    double scaleFactor;
}

- (IBAction)pinch:(UIPinchGestureRecognizer *)sender;
- (IBAction)tap:(UITapGestureRecognizer *)sender;

@property (nonatomic, retain) EAGLView *glView;
@property (strong, nonatomic) id detailItem;
@property (strong, nonatomic) IBOutlet UIButton *runStopButton;
@property (weak, nonatomic) IBOutlet UILabel *progressLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *progressIndicator;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@property (nonatomic, retain) NSString *initialModel;

@end
