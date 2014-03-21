//
//  AboutViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 21/03/14.
//  Copyright (c) 2014 Maxime Graulich. All rights reserved.
//

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

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.aboutView loadHTMLString:[NSString stringWithFormat:@"<center><h3>Onelab for iOS</h3>Version %@<p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> for more information</p><h3>Gmsh</h3>Version %s<p>Copyright (C) 1997-2014<br>Christophe Geuzaine and Jean-Francois Remacle</p><p><a href=\"http://geuz.org/gmsh/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/gmsh/doc/LICENSE.txt\">licensing information</a><p>Please send all questions and bug reports to <a href=\"mailto:gmsh@geuz.org\">gmsh@geuz.org</a></center><ul><li><i>Build OS:</i> %s</li><li><i>Build date:</i> %s</li><li><i>Build options:</i> %s</li></ul><center><p>Visit <a href=\"http://geuz.org/gmsh/\">http://geuz.org/gmsh/</a> for more information</p><h3>GetDP</h3>Version %s<p>Copyright (C) 1997-2014<br>Christophe Geuzaine and Patrick Dular</p><p><a href=\"http://geuz.org/getdp/doc/CREDITS.txt\">Credits</a> and <a href=\"http://geuz.org/getdp/doc/LICENSE.txt\">licensing information</a><p>Please send all questions and bug reports to <a href=\"mailto:getdp@geuz.org\">getdp@geuz.org</a></center><ul><li><i>Build OS:</i> %s</li><li><i>Build date:</i> %s</li><li><i>Build options:</i> %s</li></ul><center><p>Visit <a href=\"http://geuz.org/getdp/\">http://geuz.org/getdp/</a> for more information</p></center>",
                                    [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"],
                                    GMSH_VERSION,
                                    GMSH_OS,
                                    GMSH_DATE,
                                    GMSH_CONFIG_OPTIONS,
                                    GETDP_VERSION,
                                    GETDP_OS,
                                    GETDP_DATE,
                                    GETDP_CONFIG_OPTIONS]
                           baseURL:nil];
    
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
