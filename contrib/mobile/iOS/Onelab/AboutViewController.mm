#import "AboutViewController.h"
#import "Gmsh/GmshVersion.h"
#import "Gmsh/GmshConfig.h"
#import "GetDP/GetDPVersion.h"
#import "GetDP/GetDPConfig.h"

@interface AboutViewController ()

@end

@implementation AboutViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if (self) {
    // Custom initialization
  }
  return self;
}

// this allows to open links in Safari, instead of opening them in the AboutViewController
-(BOOL) webView:(UIWebView *)inWeb shouldStartLoadWithRequest:(NSURLRequest *)inRequest navigationType:(UIWebViewNavigationType)inType {
  if ( inType == UIWebViewNavigationTypeLinkClicked ) {
    [[UIApplication sharedApplication] openURL:[inRequest URL]];
    return NO;
  }

  return YES;
}

- (void)viewDidLoad
{
  [super viewDidLoad];
  // Do any additional setup after loading the view.
  self.aboutView.delegate = self;
  self.aboutView.dataDetectorTypes = UIDataDetectorTypeNone;
  [self.aboutView loadHTMLString:[NSString stringWithFormat:@"<html><head><style type=\"text/css\"><!--body { background-color: #FFFFFF; color: #252525; margin: 35px 10px 35px 10px; padding: 0; font-family: helvetica-neue,sans-serif; font-size: 1em; }--></style></head><body><center><p><!--img width=32 src=\"icon_onelab.png\"--></p><h3>Onelab/Mobile</h3>Version %@<p>Copyright (C) 2014 Christophe Geuzaine and Maxime Graulich, University of Li&egrave;ge</p><p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> for more information</p><p style=\"padding-top: 35px;\">This version of Onelab/Mobile contains:</p><h3>Gmsh</h3>Version %s (<i>Build date:</i> %s)<p>Copyright (C) 1997-2014 Christophe Geuzaine and Jean-Fran&ccedil;ois Remacle</p><p><a href=\"http://geuz.org/gmsh/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/gmsh/doc/LICENSE.txt\">licensing information</a></p><p><i>Build options:</i> %s</p><p>Visit <a href=\"http://gmsh.info/\">http://gmsh.info</a> for more information</p><h3>GetDP</h3>Version %s (<i>Build date:</i> %s)<p>Copyright (C) 1997-2014 Patrick Dular and Christophe Geuzaine, University of Li&egrave;ge</p><p><a href=\"http://geuz.org/getdp/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/getdp/doc/LICENSE.txt\">licensing information</a></p><p><i>Build options:</i> %s</p><p>Visit <a href=\"http://getdp.info\">http://getdp.info</a> for more information</p></center></body>",
                                           [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"],
                                           GMSH_VERSION,
                                           GMSH_DATE,
                                           GMSH_CONFIG_OPTIONS,
                                           GETDP_VERSION,
                                           GETDP_DATE,
                                           GETDP_CONFIG_OPTIONS]
                         baseURL:[[NSBundle mainBundle] bundleURL]];

}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

/*
  #pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
