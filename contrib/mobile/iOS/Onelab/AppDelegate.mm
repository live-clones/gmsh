#import "AppDelegate.h"
#import "ModelListController.h"
#import "Utils.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application
  didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // Override point for customization after application launch.
  self.modelListController =
    (ModelListController *)self.window.rootViewController;
  if([[UIDevice currentDevice].model isEqualToString:@"iPad"] ||
     [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]) {
    UIStoryboard *storyboard =
      [UIStoryboard storyboardWithName:@"iPadStoryboard" bundle:nil];
    self.splitViewController = [storyboard
      instantiateViewControllerWithIdentifier:@"SplitViewController"];
  }
  compute = false;
  // Copy resource files if the version of the app has changed
  NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
  NSString *prefsv = [prefs stringForKey:@"OnelabModelsVersion"];
  NSString *bundlev =
    [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"];
  if(!prefsv || ![prefsv isEqualToString:bundlev]) {
    NSLog(@"Updating models to version %@", bundlev);
    [prefs setObject:bundlev forKey:@"OnelabModelsVersion"];
    [prefs synchronize];
    [Utils copyRes];
  }
  else {
    NSLog(@"Leaving models as-is (version %@)", prefsv);
  }

  // Check if there is a model to extract (unzip)
  NSURL *url = [launchOptions objectForKey:UIApplicationLaunchOptionsURLKey];
  if(url) [Utils openModelURL:url];

  return YES;
}

- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options
{
  [Utils openModelURL:url];

  return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
  // Sent when the application is about to move from active to inactive
  // state. This can occur for certain types of temporary interruptions (such as
  // an incoming phone call or SMS message) or when the user quits the
  // application and it begins the transition to the background state.  Use this
  // method to pause ongoing tasks, disable timers, and throttle down OpenGL ES
  // frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
  // Use this method to release shared resources, save user data, invalidate
  // timers, and store enough application state information to restore your
  // application to its current state in case it is terminated later.  If your
  // application supports background execution, this method is called instead
  // of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
  // Called as part of the transition from the background to the inactive state;
  // here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  // Restart any tasks that were paused (or not yet started) while the
  // application was inactive. If the application was previously in the
  // background, optionally refresh the user interface.
  [[NSNotificationCenter defaultCenter] postNotificationName:@"requestRender"
                                                      object:nil];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
  // Called when the application is about to terminate. Save data if
  // appropriate. See also applicationDidEnterBackground:.
}

- (void)application:(UIApplication *)application
  didReceiveLocalNotification:(UILocalNotification *)notification
{
  application.applicationIconBadgeNumber = -1;
  [UIApplication sharedApplication].applicationIconBadgeNumber = -1;
}

@end
