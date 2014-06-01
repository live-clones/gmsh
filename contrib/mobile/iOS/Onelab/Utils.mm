#import "Utils.h"

@implementation Utils

+ (NSString *) getApplicationDocumentsDirectory
{
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
  NSString *basePath = ([paths count] > 0) ? [paths objectAtIndex:0] : nil;
  return basePath;
}

+ (void) copyRes
{
  NSString *resPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"files"];
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
  NSString *docPath = [paths objectAtIndex:0]; //Get the docs directory
  NSArray *resContents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:resPath error:NULL];
  for (NSString *obj in resContents){
    NSLog(@"Replacing model %@", obj);
    NSString *modelSrc = [[resPath stringByAppendingString:@"/"] stringByAppendingString:obj];
    NSString *modelDst = [[docPath stringByAppendingString:@"/"] stringByAppendingString:obj];
    [[NSFileManager defaultManager] removeItemAtPath:modelDst error:nil];
    NSError *error;
    if (![[NSFileManager defaultManager] copyItemAtPath:modelSrc toPath:modelDst error:&error])
      NSLog(@"Error: %@", error);
  }
}

@end
