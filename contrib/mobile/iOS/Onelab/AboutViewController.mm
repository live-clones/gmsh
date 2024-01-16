#import "AboutViewController.h"
#import "GetDP/GetDPConfig.h"
#import "GetDP/GetDPVersion.h"
#import "Gmsh/GmshConfig.h"
#import "Gmsh/GmshVersion.h"

@interface AboutViewController ()

@end

@implementation AboutViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if(self) {
    // Custom initialization
  }
  return self;
}

// this allows to open links in Safari, instead of opening them in the
// AboutViewController
- (BOOL)webView:(UIWebView *)inWeb
  shouldStartLoadWithRequest:(NSURLRequest *)inRequest
              navigationType:(UIWebViewNavigationType)inType
{
  if(inType == UIWebViewNavigationTypeLinkClicked) {
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
  [self loadContent];
  if(![self.fileToEdit isEqual:@"About"] && !
                                            [self.fileToEdit isEqual:@"Help"]) {
    UIBarButtonItem *save =
      [[UIBarButtonItem alloc] initWithTitle:@"Save"
                                       style:UIBarButtonItemStylePlain
                                      target:self
                                      action:@selector(saveFile)];
    [self.navigationItem
      setRightBarButtonItems:[NSArray arrayWithObjects:save, nil]];
  }
}

- (void)loadContent
{
  UIColor *tintColor = self.view.tintColor;
  CGFloat red, green, blue, alpha;
  [tintColor getRed:&red green:&green blue:&blue alpha:&alpha];
  int r = (int)(red * 255), g = (int)(green * 255), b = (int)(blue * 255);

  NSString *css = [NSString
    stringWithFormat:
      @"body { background-color: #FFFFFF; color: #252525; margin: 35px "
      @"10px 35px 10px; padding: 0; font-family: "
      @"helvetica-neue,sans-serif; font-size: 1em; }  b { font-weight: "
      @"normal; color: rgb(%d,%d,%d); } a { color: rgb(%d,%d,%d); }",
      r, g, b, r, g, b];

  if([self.fileToEdit isEqual:@"About"]) {
    [self.aboutView
      loadHTMLString:
        [NSString stringWithFormat:
                    @"<html><head><style "
                    @"type=\"text/css\">%@</style></head><body><center><p><!-- "
                    @"img width=32 "
                    @"src=\"icon_onelab.png\"--></p><h3>Onelab/Mobile</"
                    @"h3>Version %@<p>Copyright (C) 2014-2024 Christophe "
                    @"Geuzaine and Maxime Graulich, University of "
                    @"Li&egrave;ge</p><p>Visit <a "
                    @"href=\"https://onelab.info/\">https://onelab.info/</a> for "
                    @"more information</p><p style=\"padding-top: 35px;\">This "
                    @"version of Onelab/Mobile "
                    @"contains:</p><h3>Gmsh</h3>Version %s (<i>Build date:</i> "
                    @"%s)<p>Copyright (C) 1997-2024 Christophe Geuzaine and "
                    @"Jean-Fran&ccedil;ois Remacle</p><p><a "
                    @"href=\"https://gmsh.info/CREDITS.txt\">Credits</"
                    @"a> and <a "
                    @"href=\"https://gmsh.info/LICENSE.txt\">licensing "
                    @"information</a></p><p><i>Build options:</i> "
                    @"%s</p><p>Visit <a "
                    @"href=\"https://gmsh.info/\">https://gmsh.info</a> for more "
                    @"information</p><h3>GetDP</h3>Version %s (<i>Build "
                    @"date:</i> %s)<p>Copyright (C) 1997-2024 Patrick Dular "
                    @"and Christophe Geuzaine, University of "
                    @"Li&egrave;ge</p><p><a "
                    @"href=\"https://getdp.info/CREDITS.txt\">Credits</"
                    @"a> and <a "
                    @"href=\"https://getdp.info/LICENSE.txt\">licensing "
                    @"information</a></p><p><i>Build options:</i> "
                    @"%s</p><p>Visit <a "
                    @"href=\"https://getdp.info\">https://getdp.info</a> for "
                    @"more information</p></center></body></html>",
                    css,
                    [[[NSBundle mainBundle] infoDictionary]
                      objectForKey:@"CFBundleShortVersionString"],
                    GMSH_VERSION, GMSH_DATE, GMSH_CONFIG_OPTIONS, GETDP_VERSION,
                    GETDP_DATE, GETDP_CONFIG_OPTIONS]
             baseURL:[[NSBundle mainBundle] bundleURL]];
  }
  else if([self.fileToEdit isEqual:@"Help"]) {
    [self.aboutView
      loadHTMLString:
        [NSString stringWithFormat:
                    @"<html><head><style type=\"text/css\">%@ h3 { text-align: "
                    @"center; }</style></head><!-- img width=32 "
                    @"src=\"icon_onelab.png\"--><h3>Onelab/Mobile</h3> "
                    @"<h4>Running an existing model</h4> <p> The list of "
                    @"available models appears when you launch the app. "
                    @"Selecting a model will load it. You can then press "
                    @"<b>Run</b> to launch a simulation with the default set "
                    @"of parameters. When available, additional information "
                    @"about a model can be obtained by long-pressing on the "
                    @"model description and selecting <b>Visit model "
                    @"website</b>.</p> <h4>Modifying a model</h4> <p>To run a "
                    @"model with different parameters, press <b>Parameters</b> "
                    @"and modify any of the presets. Then press <b>Run</b> "
                    @"again: all the simulation steps will be performed with "
                    @"the new parameter values. To restore the preset "
                    @"parameters values, press <b>Reset</b>. </p> <p> Advanced "
                    @"users can also directly edit the model input files: "
                    @"long-press on the model description and select <b>Edit "
                    @"model files</b>. </p> <p> To free up space, temporary "
                    @"model files (meshes, solution files) can be removed by "
                    @"long-pressing on the model description and selecting "
                    @"<b>Clear results</b>. </p> <p> To completey remove a "
                    @"model, long-press on the model description and select "
                    @"<b>Remove</b>. </p> <h4>Sharing a model</h4> <p> To "
                    @"share a model by email, long-press on the model "
                    @"description and select <b>Email model files</b>. </p> "
                    @"<h4>Installing a new model</h4> <p> To install a new "
                    @"model: <ol> <li>Put all the model files (.pro, .geo) in "
                    @"a directory, which should also contain a file named "
                    @"<code>infos.xml</code> with the model information: "
                    @"<pre>\n&lt;?xml version=\"1.0\" "
                    @"encoding=\"utf-8\"?&gt;\n&lt;models&gt;\n  "
                    @"&lt;model&gt;\n    &lt;title&gt;Model "
                    @"title&lt;/title&gt;\n    &lt;summary&gt;Model "
                    @"summary&lt;/summary&gt;\n    &lt;file "
                    @"type=\"pro\"&gt;main_pro_file.pro&lt;/file&gt;\n    "
                    @"&lt;preview "
                    @"type=\"png\"&gt;128x128_pixel_screenshot.png&lt;/"
                    @"preview&gt;\n    "
                    @"&lt;url&gt;http://model_website.com&lt;/url&gt;\n  "
                    @"&lt;/model&gt;\n&lt;/models&gt;\n</pre><li>Zip the "
                    @"directory. <li>Open the .zip file on your device, e.g. "
                    @"through iCloud or by  emailing it to yourself and "
                    @"opening the attachment; or by putting it  on a web "
                    @"server and downloading the file on the device with "
                    @"Safari. <li>Refresh the list of models: the new model "
                    @"will be extracted  alongside Onelab/Mobile\'s built-in "
                    @"models.</ol> <p style=\"padding-top: 2em;\">Visit <a "
                    @"href=\"https://onelab.info/\">https://onelab.info/</a> for "
                    @"more information.</p> </body></html>",
                    css]
             baseURL:[[NSBundle mainBundle] bundleURL]];
  }
  else {
    NSData *fileData = [NSData dataWithContentsOfFile:self.fileToEdit];
    NSString *aStr = [[NSString alloc] initWithData:fileData
                                           encoding:NSUTF8StringEncoding];
    if(!aStr)
      aStr = [[NSString alloc] initWithData:fileData
                                   encoding:NSASCIIStringEncoding];
    if(aStr) {
      aStr = [aStr stringByReplacingOccurrencesOfString:@"<"
                                             withString:@"&lt;"];
      aStr = [aStr stringByReplacingOccurrencesOfString:@">"
                                             withString:@"&gt;"];
    }
    // custom microlight.js for basic syntax highlighting
    const char *js =
      "!function(a,b){\"function\"==typeof "
      "define&&define.amd?define([\"exports\"],b):b(\"undefined\"!=typeof "
      "exports?exports:a.microlight={})}(this,function(a){var "
      "k,l,m,b=window,c=document,d=\"appendChild\",e=\"test\",g=\"opacity:."
      "\",n=function(a){for(l=c.getElementsByClassName(a||\"microlight\"),k="
      "0;m=l[k++];){var "
      "n,o,r,s,t,f=m.textContent,h=0,i=f[0],j=1,p=m.innerHTML=\"\",q=0,u=/"
      "(\\d*\\, \\d*\\, \\d*)(, "
      "([.\\d]*))?/g.exec(b.getComputedStyle(m).color);for(\"px "
      "rgba(\"+u[1]+\",\",u[3]||1;o=n,n=q<7&&\"\\\\\"==n?1:j;){if(j=i,i=f[++"
      "h],s=p.length>1,!j||q>8&&\"\\n\"==j||[/\\S/[e](j),1,1,!/[$\\w]/"
      "[e](j),(\"/"
      "\"==n||\"\\n\"==n)&&s,\'\"\'==n&&s,\"\'\"==n&&s,f[h-4]+o+n==\"-->\",o+"
      "n==\"*/"
      "\"][q])for(p&&(m[d](t=c.createElement(\"span\")).setAttribute("
      "\"style\",[\"\",\"font-weight:bold;color:#00c;\",g+6,\"color: "
      "#a08;\"+g+8,\"font-style:italic;color: "
      "#b00;\"+g+8][q?q<3?2:q>6?4:q>3?3:+/"
      "^(If|Else|ElseIf|EndIf|Include|For|EndFor|Include|Macro|Return)$/"
      "[e](p):0]),t[d](c.createTextNode(p))),r=q&&q<7?q:r,p=\"\",q=11;![1,/"
      "[\\/{}[(\\-+*=<>:;|\\\\.,?!&@~]/[e](j),/[\\])]/[e](j),/[$\\w]/"
      "[e](j),\"/"
      "\"==j&&r<2&&\"<\"!=n,\'\"\'==j,\"\'\"==j,j+i+f[h+1]+f[h+2]==\"<!--\","
      "j+i==\"/*\",j+i==\"//\",j+i==\"//"
      "\"][--q];);p+=j}}};a.reset=n,\"complete\"==c.readyState?n():b."
      "addEventListener(\"load\",function(){n()},0)});";
    [self.aboutView
      loadHTMLString:
        [NSString stringWithFormat:@"<html><head><script>%s</script></"
                                   @"head><body><pre contenteditable=\"true\" "
                                   @"class=microlight>%@</pre></body></html>",
                                   js, aStr]
             baseURL:[[NSBundle mainBundle] bundleURL]];
  }
}

- (void)saveFile
{
  // CGPoint offset = self.aboutView.scrollView.contentOffset;
  NSString *text = [self.aboutView
    stringByEvaluatingJavaScriptFromString:@"document.body.innerText"];
  NSLog(@"Saving file %@", self.fileToEdit);
  NSError *error;
  [text writeToFile:self.fileToEdit
         atomically:YES
           encoding:NSUTF8StringEncoding
              error:&error];
  [self loadContent];
  // trying to restore position, but this is not correct
  //[self.aboutView.scrollView setContentOffset:offset animated:NO];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

/*
  #pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little
preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
