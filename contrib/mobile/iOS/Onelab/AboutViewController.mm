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

  if(self.fileToEdit){
    NSData *fileData = [NSData dataWithContentsOfFile:self.fileToEdit];
    NSString* aStr = [[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding];
    if(!aStr) aStr = [[NSString alloc] initWithData:fileData encoding:NSASCIIStringEncoding];
    if(aStr){
      aStr = [aStr stringByReplacingOccurrencesOfString:@"<"
                                             withString:@"&lt;"];
      aStr = [aStr stringByReplacingOccurrencesOfString:@">"
                                             withString:@"&gt;"];
    }
    
    // custom microlight.js for basic syntax highlighting
    const char *js = "!function(a,b){\"function\"==typeof define&&define.amd?define([\"exports\"],b):b(\"undefined\"!=typeof exports?exports:a.microlight={})}(this,function(a){var k,l,m,b=window,c=document,d=\"appendChild\",e=\"test\",g=\"opacity:.\",n=function(a){for(l=c.getElementsByClassName(a||\"microlight\"),k=0;m=l[k++];){var n,o,r,s,t,f=m.textContent,h=0,i=f[0],j=1,p=m.innerHTML=\"\",q=0,u=/(\\d*\\, \\d*\\, \\d*)(, ([.\\d]*))?/g.exec(b.getComputedStyle(m).color);for(\"px rgba(\"+u[1]+\",\",u[3]||1;o=n,n=q<7&&\"\\\\\"==n?1:j;){if(j=i,i=f[++h],s=p.length>1,!j||q>8&&\"\\n\"==j||[/\\S/[e](j),1,1,!/[$\\w]/[e](j),(\"/\"==n||\"\\n\"==n)&&s,\'\"\'==n&&s,\"\'\"==n&&s,f[h-4]+o+n==\"-->\",o+n==\"*/\"][q])for(p&&(m[d](t=c.createElement(\"span\")).setAttribute(\"style\",[\"\",\"font-weight:bold;color:#00c;\",g+6,\"color: #a08;\"+g+8,\"font-style:italic;color: #b00;\"+g+8][q?q<3?2:q>6?4:q>3?3:+/^(If|Else|ElseIf|EndIf|Include|For|EndFor|Include|Macro|Return)$/[e](p):0]),t[d](c.createTextNode(p))),r=q&&q<7?q:r,p=\"\",q=11;![1,/[\\/{}[(\\-+*=<>:;|\\\\.,?!&@~]/[e](j),/[\\])]/[e](j),/[$\\w]/[e](j),\"/\"==j&&r<2&&\"<\"!=n,\'\"\'==j,\"\'\"==j,j+i+f[h+1]+f[h+2]==\"<!--\",j+i==\"/*\",j+i==\"//\",j+i==\"//\"][--q];);p+=j}}};a.reset=n,\"complete\"==c.readyState?n():b.addEventListener(\"load\",function(){n()},0)});";

    [self.aboutView loadHTMLString:[NSString stringWithFormat:@"<html><head><script>%s</script></head><body><pre contenteditable=\"true\" class=microlight>%@</pre></body></html>", js, aStr] baseURL:[[NSBundle mainBundle] bundleURL]];
    UIBarButtonItem *save = [[UIBarButtonItem alloc] initWithTitle:@"Save" style:UIBarButtonItemStylePlain target:self action:@selector(saveFile)];
    [self.navigationItem setRightBarButtonItems:[NSArray arrayWithObjects: save, nil]];
  }
  else{
    [self.aboutView loadHTMLString:[NSString stringWithFormat:@"<html><head><style type=\"text/css\"><!--body { background-color: #FFFFFF; color: #252525; margin: 35px 10px 35px 10px; padding: 0; font-family: helvetica-neue,sans-serif; font-size: 1em; }--></style></head><body><center><p><!--img width=32 src=\"icon_onelab.png\"--></p><h3>Onelab/Mobile</h3>Version %@<p>Copyright (C) 2014-2016 Christophe Geuzaine and Maxime Graulich, University of Li&egrave;ge</p><p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> for more information</p><p style=\"padding-top: 35px;\">This version of Onelab/Mobile contains:</p><h3>Gmsh</h3>Version %s (<i>Build date:</i> %s)<p>Copyright (C) 1997-2016 Christophe Geuzaine and Jean-Fran&ccedil;ois Remacle</p><p><a href=\"http://geuz.org/gmsh/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/gmsh/doc/LICENSE.txt\">licensing information</a></p><p><i>Build options:</i> %s</p><p>Visit <a href=\"http://gmsh.info/\">http://gmsh.info</a> for more information</p><h3>GetDP</h3>Version %s (<i>Build date:</i> %s)<p>Copyright (C) 1997-2016 Patrick Dular and Christophe Geuzaine, University of Li&egrave;ge</p><p><a href=\"http://geuz.org/getdp/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/getdp/doc/LICENSE.txt\">licensing information</a></p><p><i>Build options:</i> %s</p><p>Visit <a href=\"http://getdp.info\">http://getdp.info</a> for more information</p></center></body>",
                                             [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"],
                                             GMSH_VERSION,
                                             GMSH_DATE,
                                             GMSH_CONFIG_OPTIONS,
                                             GETDP_VERSION,
                                             GETDP_DATE,
                                             GETDP_CONFIG_OPTIONS]
                           baseURL:[[NSBundle mainBundle] bundleURL]];
  }
}

-(void)saveFile
{
  NSString *text = [self.aboutView stringByEvaluatingJavaScriptFromString:
                          @"document.body.innerText"];
  NSLog(@"Saving file %@", self.fileToEdit);
  NSError *error;
  [text writeToFile:self.fileToEdit atomically:YES
           encoding:NSUTF8StringEncoding error:&error];
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
