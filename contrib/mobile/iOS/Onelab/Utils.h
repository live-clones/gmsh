#import <Foundation/Foundation.h>

@interface Utils : NSObject

+ (NSString *)getApplicationDocumentsDirectory;
+ (void)copyRes;
+ (void)openModelURL:(NSURL *)url;
+ (id)traverseResponderChainForUIViewController:(UIView *)v;
+ (NSString *)getStringFromCString:(const char *)s;

@end
