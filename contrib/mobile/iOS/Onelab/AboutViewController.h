#import <UIKit/UIKit.h>

@interface AboutViewController : UIViewController <UIWebViewDelegate>

@property (weak, nonatomic) IBOutlet UIWebView *aboutView;
@property (nonatomic, retain) NSString *fileToEdit;

@end
