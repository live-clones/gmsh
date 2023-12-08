#import "Utils.h"

#include <gmsh/OS.h>

@implementation Utils

+ (NSString *)getApplicationDocumentsDirectory
{
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                       NSUserDomainMask, YES);
  NSString *basePath = ([paths count] > 0) ? [paths objectAtIndex:0] : nil;
  return basePath;
}

+ (void)copyRes
{
  NSString *resPath = [[[NSBundle mainBundle] resourcePath]
    stringByAppendingPathComponent:@"files"];
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                       NSUserDomainMask, YES);
  NSString *docPath = [paths objectAtIndex:0]; // Get the docs directory
  NSArray *resContents =
    [[NSFileManager defaultManager] contentsOfDirectoryAtPath:resPath
                                                        error:NULL];
  for(NSString *obj in resContents) {
    NSLog(@"Replacing model %@", obj);
    NSString *modelSrc =
      [[resPath stringByAppendingString:@"/"] stringByAppendingString:obj];
    NSString *modelDst =
      [[docPath stringByAppendingString:@"/"] stringByAppendingString:obj];
    [[NSFileManager defaultManager] removeItemAtPath:modelDst error:nil];
    NSError *error = nil;
    if(![[NSFileManager defaultManager] copyItemAtPath:modelSrc
                                                toPath:modelDst
                                                 error:&error])
      NSLog(@"Error: %@", error);
    else if(![[NSURL fileURLWithPath:modelDst]
              setResourceValue:[NSNumber numberWithBool:YES]
                        forKey:NSURLIsExcludedFromBackupKey
                         error:&error])
      NSLog(@"Error %@", error);
  }
}

+ (void)openModelURL:(NSURL *)url
{
  if(!url) return;
  NSString *filepath = [url path];
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                       NSUserDomainMask, YES);
  NSString *docPath = [paths objectAtIndex:0]; // Get the docs directory
  NSString *extension = [filepath pathExtension];
  if([extension isEqualToString:@"zip"] || [extension isEqualToString:@"ZIP"]) {
    NSLog(@"Unzipping %@", filepath);
    UnzipFile([filepath UTF8String], [docPath UTF8String]);
    NSLog(@"Removing %@", filepath);
    [[NSFileManager defaultManager] removeItemAtPath:filepath error:nil];
  }
  else {
    NSLog(@"Unknown model file extension: only .zip files are currently "
          @"accepted");
  }
}

+ (UIViewController *)traverseResponderChainForUIViewController:(UIView *)v
{
  id nextResponder = [v nextResponder];
  if([nextResponder isKindOfClass:[UIViewController class]])
    return nextResponder;
  else if([nextResponder isKindOfClass:[UIView class]])
    return [Utils traverseResponderChainForUIViewController:nextResponder];
  else
    return nil;
}

+ (NSString *)getStringFromCString:(const char *)s
{
  return [NSString stringWithCString:s encoding:NSUTF8StringEncoding];
}

@end
