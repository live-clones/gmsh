//
//  DetailViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EAGLView.h"


@interface UIErrorAlertView : UIAlertView

@end

@interface ModelViewController : UIViewController <UISplitViewControllerDelegate, UIAlertViewDelegate>
{
    @private
    double scaleFactor;
	UIBarButtonItem *_runStopButton, *_playButton, *_stopButton;
	UIAlertView *_loadingAlert;
	UIErrorAlertView *_errorAlert;
	NSMutableArray *_errors;
	UIBackgroundTaskIdentifier _computeBackgroundTaskIdentifier;
	NSTimer *_animation;
}

- (IBAction)pinch:(UIPinchGestureRecognizer *)sender;
- (IBAction)singleTap:(UITapGestureRecognizer *)sender;
- (IBAction)doubleTap:(UITapGestureRecognizer *)sender;

@property (strong, nonatomic) IBOutlet UITapGestureRecognizer *singleTap;
@property (strong, nonatomic) IBOutlet UITapGestureRecognizer *doubleTap;
@property (nonatomic, retain) EAGLView *glView;
@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *progressLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *progressIndicator;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@property (nonatomic, retain) NSString *initialModel;

- (IBAction)startRotation:(UIButton *)sender;

@end
