//
//  DetailViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//
#import <QuartzCore/QuartzCore.h>

#import "ModelViewController.h"
#import "iosGModel.h"

#import "AppDelegate.h"

@interface ModelViewController ()
@property (strong, nonatomic) UIPopoverController *masterPopoverController;
- (void)configureView;
@end

@implementation ModelViewController

#pragma mark - Managing the detail item
@synthesize glView;

- (void)setDetailItem:(id)newDetailItem
{
    if (_detailItem != newDetailItem) {
        _detailItem = newDetailItem;
        // Update the view.
        [self configureView];
    }

    if (self.masterPopoverController != nil) {
        [self.masterPopoverController dismissPopoverAnimated:YES];
    }        
}

- (void)configureView
{
    // Update the user interface for the detail item.
    if (self.detailItem) {
        self.detailDescriptionLabel.text = [self.detailItem description];
    }
}

-(void)viewWillAppear:(BOOL)animated
{
	_runStopButton.frame = CGRectMake(self.view.frame.size.width - _runStopButton.frame.size.width - 7, 50, _runStopButton.frame.size.width, _runStopButton.frame.size.height );
}

-(void)viewDidAppear:(BOOL)animated
{
	if(self.initialModel != nil){
		UIAlertView* progressAlert = [[UIAlertView alloc] initWithTitle:@"Please wait..." message: @"The model is loading" delegate: self cancelButtonTitle: nil otherButtonTitles: nil];
		[progressAlert show];
		[self.glView load:self.initialModel];
		//[self.initialModel release];
		self.initialModel = nil;
		[progressAlert dismissWithClickedButtonIndex:-1 animated:YES];
	}
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self configureView];
    scaleFactor = 1.;
    setObjCBridge((__bridge void*) self);
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(requestRender) name:@"requestRender" object:nil];
    if([[UIDevice currentDevice].model isEqualToString:@"iPad"] || [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
		UIBarButtonItem *model = [[UIBarButtonItem alloc] initWithTitle:@"Model list" style:UIBarButtonItemStyleBordered target:self action:@selector(showModelsList)];
		[self.navigationItem setRightBarButtonItem:model];
	}
	else
	{
        UIBarButtonItem *settings = [[UIBarButtonItem alloc] initWithTitle:@"Parameters" style:UIBarButtonItemStyleBordered target:self action:@selector(showSettings)];
        [self.navigationItem setRightBarButtonItem:settings];
    }
	[_runStopButton addTarget:self action:@selector(compute) forControlEvents:UIControlEventTouchDown];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
	_runStopButton.frame = CGRectMake(self.view.frame.size.width - _runStopButton.frame.size.width - 7, 50, _runStopButton.frame.size.width, _runStopButton.frame.size.height );
}

- (void)compute
{
	[_runStopButton addTarget:self action:@selector(stop) forControlEvents:UIControlEventTouchDown];
	[_runStopButton setTitle:@"Stop" forState:UIControlStateNormal];
	dispatch_async( dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
        appDelegate->compute = YES;
        onelab_cb("compute");
		[self performSelectorOnMainThread:@selector(didStopCompute:) withObject:nil waitUntilDone:YES];
        appDelegate->compute = NO;
    });
}

- (void)didStopCompute:(id)sender
{
	[self performSelectorOnMainThread:@selector(didStopCompute) withObject:nil waitUntilDone:NO];
}
- (void)didStopCompute
{
	[_runStopButton addTarget:self action:@selector(compute) forControlEvents:UIControlEventTouchDown];
	[_runStopButton setTitle:@"Run" forState:UIControlStateNormal];
}
- (void)stop
{
	onelab_cb("stop");
}
- (IBAction)pinch:(UIPinchGestureRecognizer *)sender
{
    if([sender numberOfTouches] > 2) return;
    float mScale = scaleFactor;
    if (sender.state == UIGestureRecognizerStateBegan)
        mScale = scaleFactor;
    else if(sender.state == UIGestureRecognizerStateChanged)
        mScale = scaleFactor * [sender scale];
    else if(sender.state == UIGestureRecognizerStateEnded || sender.state == UIGestureRecognizerStateCancelled){
        scaleFactor *= [sender scale];
        mScale = scaleFactor;
    }
    mScale = MAX(0.1, mScale);
    glView->mContext->eventHandler(2,mScale);
    [glView drawView];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchPoint = [touch locationInView:self.view];
    glView->mContext->eventHandler(0, touchPoint.x, touchPoint.y);
}

-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self touchesEnded:touches withEvent:event];
}

-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchPoint = [touch locationInView:self.view];
    glView->mContext->eventHandler(4, touchPoint.x, touchPoint.y);
}

- (IBAction)tap:(UITapGestureRecognizer *)sender
{
    sender.numberOfTapsRequired = 2;
	sender.numberOfTouchesRequired = 1;
    if(sender.state == UIGestureRecognizerStateEnded){
        scaleFactor = 1;
        glView->mContext->eventHandler(10);
        [glView drawView];
    }
}

- (void) showModelsList
{
    if(((AppDelegate *)[UIApplication sharedApplication].delegate)->compute) {
        UIAlertView *alert;
        alert = [[UIAlertView alloc] initWithTitle:@"Can't show the models list" message:@"The compute have to be finished before you can select an other model." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [alert show];
        return;
    }
    if([[UIDevice currentDevice].model isEqualToString:@"iPad"] || [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
        AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
        [UIView transitionWithView:appDelegate.window
                          duration:0.5
                           options:UIViewAnimationOptionTransitionFlipFromRight
                        animations:^{ appDelegate.window.rootViewController = appDelegate.modelListController; }
                        completion:nil];
    }
    [self.navigationController popToRootViewControllerAnimated:YES];
}
    
- (void) showSettings
{
    [self performSegueWithIdentifier:@"showSettingsSegue" sender:self];
}

-(void) showAlert:(std::string)msg title:(std::string) title
{
    UIAlertView *alert;
    alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithCString:title.c_str() encoding:[NSString defaultCStringEncoding]] message:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

- (void)viewDidUnload
{
    [self setGlView:nil];
	[self setRunStopButton:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (void)requestRender
{
    [glView drawView];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

#pragma mark - Split view

- (void)splitViewController:(UISplitViewController *)splitController willHideViewController:(UIViewController *)viewController withBarButtonItem:(UIBarButtonItem *)barButtonItem forPopoverController:(UIPopoverController *)popoverController
{
    barButtonItem.title = NSLocalizedString(@"Parameters", @"Parameters");
	[self.navigationItem setLeftBarButtonItem:barButtonItem];
    self.masterPopoverController = popoverController;
}

- (void)splitViewController:(UISplitViewController *)splitController willShowViewController:(UIViewController *)viewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem
{
    // Called when the view is shown again in the split view, invalidating the button and popover controller.
    [self.navigationItem setLeftBarButtonItem:nil animated:YES];
    self.masterPopoverController = nil;
}
#pragma mark - actionsheet

-(void)showMore: (UIBarButtonItem*)sender
{
    UIActionSheet *popupMore = [[UIActionSheet alloc] initWithTitle:@"Other settings" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:
                                (glView->mContext->isShowedMesh())?@"Hide mesh":@"Show mesh",
                                (glView->mContext->isShowedGeom())?@"Hide geometry" :@"Show geometry",
                                @"Set X view",
                                @"Set Y view",
                                @"Set Z view",
                                nil];
    [popupMore showInView:self.view];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSString *text = [actionSheet buttonTitleAtIndex:buttonIndex];
    if([text isEqualToString:@"Hide mesh"])
        glView->mContext->showMesh(false);
    else if([text isEqualToString:@"Show mesh"])
        glView->mContext->showMesh();
    else if([text isEqualToString:@"Hide geometry"])
        glView->mContext->showGeom(false);
    else if([text isEqualToString:@"Show geometry"])
        glView->mContext->showGeom();
    else if([text isEqualToString:@"Set X view"]){
        glView->mContext->eventHandler(5);
    }
    else if([text isEqualToString:@"Set Y view"]){
        glView->mContext->eventHandler(6);
    }
    else if([text isEqualToString:@"Set Z view"]){
        glView->mContext->eventHandler(7);
    }
    [glView drawView];
}

void messageFromCpp (void *self, std::string level, std::string msg)
{
    if(level == "RequestRender"){
        [(__bridge id)self requestRender];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"refreshParameters" object:nil];
    }
    else if(level == "Error")
        [(__bridge id)self showAlert:msg title:level];
}
void getBitmap(void *self, const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth)
{
    [(__bridge id)self getBitmapFromStringObjC:text withTextSize:textsize inMap:map inHeight:height inWidth:width inRealWidth:realWidth];
}
-(void) getBitmapFromStringObjC:(const char *)text withTextSize:(int)textsize inMap:(unsigned char **)map inHeight:(int *)height inWidth:(int *)width inRealWidth:(int *) realWidth
{
    UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 1024, textsize)];
    lbl.font = [UIFont systemFontOfSize:textsize];
    [lbl setText:[NSString stringWithCString:text  encoding:[NSString defaultCStringEncoding]]];
    [lbl setBackgroundColor:[UIColor clearColor]];
    CGSize lblSize = [[lbl text] sizeWithFont:[lbl font]];
    *realWidth = lblSize.width;
    int i;
    for(i=2;i<*realWidth;i*=2); *width = i;
    *height = lblSize.height;
    for(i=2;i<*height;i*=2); *height = i;
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(*width, *height), NO, 0.0);
    [lbl.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();

    CGImageRef bitmap = [img CGImage];
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    unsigned char *rawData = (unsigned char*) calloc(*height * *width * 4, sizeof(unsigned char));
    *map = (unsigned char*) calloc(*height * *width, sizeof(unsigned char));
    NSUInteger bytesPerPixel = 4;
    NSUInteger bytesPerRow = bytesPerPixel * *width;
    NSUInteger bitsPerComponent = 8;
    CGContextRef context = CGBitmapContextCreate(rawData, *width, *height,
                                                 bitsPerComponent, bytesPerRow, colorSpace,
                                                 kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
    CGColorSpaceRelease(colorSpace);
    
    CGContextDrawImage(context, CGRectMake(0, 0, *width, *height), bitmap);
    CGContextRelease(context);

    // rawData contains the image data in the RGBA8888 pixel format.
    for (int byteIndex = 0 ; byteIndex < *width * *height * 4 ; byteIndex+=4)
        *(*map+byteIndex/4) = rawData[byteIndex + 3];
    free(rawData);
}
@end
