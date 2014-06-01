#import <UIKit/UIKit.h>

@interface AboutViewController : UIViewController <UIWebViewDelegate>

@property (weak, nonatomic) IBOutlet UIWebView *aboutView;

@end
