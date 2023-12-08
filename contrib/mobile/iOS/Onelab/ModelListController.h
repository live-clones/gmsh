#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "EAGLView.h"

@interface ModelListController
  : UITableViewController <NSXMLParserDelegate,
                           MFMailComposeViewControllerDelegate> {
@private
  NSMutableArray *models;
  NSString *currentElement;
  NSMutableString *currentElementValue;
  NSString *currentDir;
  NSString *selectedModel;
  NSString *currentFileToEdit;
}
@property (nonatomic, retain) EAGLView *glView;

@end
