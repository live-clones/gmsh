#import <UIKit/UIKit.h>
#import "EAGLView.h"

@interface ModelViewController
  : UIViewController <UISplitViewControllerDelegate> {
@private
  double scaleFactor;
  UIBarButtonItem *_runStopButton, *_playButton, *_stopButton;
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
