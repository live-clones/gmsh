#import <Foundation/Foundation.h>

@interface Utils : NSObject

+ (NSString *) getApplicationDocumentsDirectory;
+ (void) copyRes;

+ (id) traverseResponderChainForUIViewController:(UIView *)v;


@end
