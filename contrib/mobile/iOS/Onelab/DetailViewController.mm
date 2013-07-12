//
//  DetailViewController.m
//  Onelab
//
//  Created by Maxime Graulich on 08/04/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//
#import <QuartzCore/QuartzCore.h>

#import "DetailViewController.h"

@interface DetailViewController ()
@property (strong, nonatomic) UIPopoverController *masterPopoverController;
- (void)configureView;
@end

@implementation DetailViewController

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

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(requestRender) name:@"requestRender" object:nil];
    [self configureView];
    scaleFactor = 1.;
    mIosGModel = new iosGModel((__bridge void*) self);
    models = [NSArray arrayWithObjects:@"pmsm", @"magnet", nil];
}

- (IBAction)pinch:(UIPinchGestureRecognizer *)sender
{
    if([sender numberOfTouches] != 2) return;
    float mScale;
    if (sender.state == UIGestureRecognizerStateBegan)
        mScale = scaleFactor;
    else if(sender.state == UIGestureRecognizerStateChanged)
        mScale = scaleFactor * [sender scale];
    else if(sender.state == UIGestureRecognizerStateEnded){
        scaleFactor *= [sender scale];
        mScale = scaleFactor;
    }
    else
        mScale = 1.0f;
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
    if(sender.state == UIGestureRecognizerStateEnded){
        scaleFactor = 1;
        glView->mContext->eventHandler(5);
        [glView drawView];
    }
}

- (void) showModelsList
{
    
    for(UIView *v in self.view.subviews)
        if(v.tag ==-2)
        {
            [self hideModelsList];
            return;
        }
    UITableView *modelsList = [[UITableView alloc] initWithFrame:CGRectMake(20,20,self.view.bounds.size.width-40,self.view.bounds.size.height - 2 * 40)];
    [modelsList setBackgroundColor: [UIColor colorWithRed:0.6 green:0.6 blue:0.6 alpha:.75]];
    [modelsList.layer setBorderWidth:1.];
    [modelsList.layer setBorderColor:[UIColor colorWithRed:0.9 green:0.9 blue:0.9 alpha:1].CGColor];
    modelsList.tag = -2;
    [modelsList setDataSource:self];
    [modelsList setDelegate:self];
    [self.view addSubview:modelsList];
    [self.view bringSubviewToFront:modelsList];
}

- (void) hideModelsList
{
    for(UIView *v in self.view.subviews)
        if(v.tag == -2)
            [v removeFromSuperview];
}

- (void) showPostpro
{
    if(PView::list.size() <= 0)
    {
        UIAlertView *alert;
        alert = [[UIAlertView alloc] initWithTitle:@"Post proccessing" message:@"No post processing data" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [alert show];
        return;
    }
    for(UIView *v in self.view.subviews)
        if(v.tag == -1){
            [self hidePostpro];
            return;
        }
    int maxPView = (self.view.bounds.size.height - 2 * 40)/30;
    int height = 2 * 40 + ((PView::list.size() <= maxPView)? PView::list.size() : maxPView) * 30;
    UIView *postpro = [[UIView alloc] initWithFrame: CGRectMake(20,20,self.view.bounds.size.width-40,height)];
    [postpro setBackgroundColor: [UIColor colorWithRed:0.6 green:0.6 blue:0.6 alpha:.75]];
    [postpro.layer setBorderWidth:1.];
    [postpro.layer setBorderColor:[UIColor colorWithRed:0.9 green:0.9 blue:0.9 alpha:1].CGColor];
    UILabel *title = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, postpro.bounds.size.width - 20, 30)];
    [title setBackgroundColor: [UIColor clearColor]];
    [title setText:@"Post processing"];
    [postpro addSubview:title];
    UIButton *ok = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    ok.frame = CGRectMake(10, postpro.bounds.size.height-40, postpro.bounds.size.width - 20, 30);
    [ok setTitle:@"OK" forState:UIControlStateNormal];
    int i0 = PView::list.size()-1;
    for(int i=i0; i >= 0 && i >= i0-maxPView; i--)
    {
        UISwitch *showHide = [[UISwitch alloc] initWithFrame: CGRectMake(10, 40 + (i0-i)*30, 100, 30)];
        UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(10 + (showHide.frame.size.width), 40 + (i0-i)*30, (postpro.bounds.size.width - 20)/5, 30)];
        UIButton *intervalType = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        intervalType.frame = CGRectMake(10 + showHide.frame.size.width + lbl.frame.size.width, 40 + (i0-i)*30, (postpro.bounds.size.width - 20)/3, 30);
        UITextField *nbIso = [[UITextField alloc] initWithFrame:CGRectMake(10 + showHide.frame.size.width + lbl.frame.size.width + intervalType.frame.size.width, 40 + (i0-i)*30, (postpro.bounds.size.width - 20)/3, 30)];
        [showHide setOn:(PView::list[i]->getOptions()->visible == 1)];
        [showHide setTag:i];
        [showHide addTarget:self action:@selector(PViewVisible:) forControlEvents:UIControlEventValueChanged];
        [lbl setBackgroundColor: [UIColor clearColor]];
        [lbl setText:[NSString stringWithCString:PView::list[i]->getData()->getName().c_str() encoding:[NSString defaultCStringEncoding]]];
        [intervalType setTag:i];
        switch (PView::list[i]->getOptions()->intervalsType) {
            case 3: // ISO
                [intervalType setTitle:@"Use Iso-values" forState:UIControlStateNormal];
                break;
            case 1: // CONTINIOUS
                [intervalType setTitle:@"Use Continous map" forState:UIControlStateNormal];
                break;
            case 2: // DISCRETE
                [intervalType setTitle:@"Use Filled iso-values" forState:UIControlStateNormal];
                break;
        }
        [intervalType addTarget:self action:@selector(PViewIntervalType:) forControlEvents:UIControlEventTouchDown];
        [nbIso setBorderStyle:UITextBorderStyleRoundedRect];
        [nbIso setText:[NSString stringWithFormat:@"%d",PView::list[i]->getOptions()->nbIso]];
        [nbIso setKeyboardType:UIKeyboardTypeNumberPad];
        [nbIso addTarget:self action:@selector(PViewNbIso:) forControlEvents:UIControlEventValueChanged];
        [nbIso setTag:i];
        [nbIso setDelegate:self];
        [postpro addSubview:nbIso];
        [postpro addSubview:intervalType];
        [postpro addSubview:showHide];
        [postpro addSubview:lbl];
    }
    [ok addTarget:self action:@selector(hidePostpro) forControlEvents:UIControlEventTouchDown];
    [postpro addSubview:ok];
    postpro.tag = -1;
    [self.view addSubview:postpro];
    [self.view bringSubviewToFront:postpro];
}

-(void)hidePostpro
{
    for(UIView *v in self.view.subviews)
        if(v.tag == -1)
            [v removeFromSuperview];
}

-(void) showAlert:(std::string)msg title:(std::string) title
{
    UIAlertView *alert;
    alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithCString:title.c_str() encoding:[NSString defaultCStringEncoding]] message:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

-(IBAction)PViewVisible:(id)sender
{
    PView::list[((UISwitch*)sender).tag]->getOptions()->visible = (((UISwitch*)sender).on)? 1 : 0;
    [self requestRender];
}

-(IBAction)PViewIntervalType:(id)sender
{
    if( [((UIButton *)sender) titleForState:UIControlStateNormal] == @"Use Iso-values")
    {
        [((UIButton *)sender) setTitle:@"Use Continous map" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 1;
    }
    else if( [((UIButton *)sender) titleForState:UIControlStateNormal] == @"Use Continous map")
    {
        [((UIButton *)sender) setTitle:@"Use Filled iso-values" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 2;
    }
    else if( [((UIButton *)sender) titleForState:UIControlStateNormal] == @"Use Filled iso-values")
    {
        [((UIButton *)sender) setTitle:@"Use Iso-values" forState:UIControlStateNormal];
        PView::list[((UIButton *)sender).tag]->getOptions()->intervalsType = 3;
    }
    PView::list[((UIButton *)sender).tag]->setChanged(true);
    [self requestRender];
}

- (void)viewDidUnload
{
    [self setGlView:nil];
    [self setGlView:nil];
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
    barButtonItem.title = NSLocalizedString(@"Settings", @"Settings");
    UIBarButtonItem *postpro = [[UIBarButtonItem alloc] initWithTitle:@"Post processing" style:UIBarButtonItemStyleBordered target:self action:@selector(showPostpro)];
    UIBarButtonItem *more = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAdd target:self action:@selector(showMore:)];
    UIBarButtonItem *model = [[UIBarButtonItem alloc] initWithTitle:@"Load model" style:UIBarButtonItemStyleBordered target:self action:@selector(showModelsList)];
    NSArray *btns = [[NSArray alloc] initWithObjects:barButtonItem, postpro, more, nil];
    [self.navigationItem setLeftBarButtonItems:btns];
    [self.navigationItem setRightBarButtonItem:model];
    self.masterPopoverController = popoverController;
}

- (void)splitViewController:(UISplitViewController *)splitController willShowViewController:(UIViewController *)viewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem
{
    // Called when the view is shown again in the split view, invalidating the button and popover controller.
    [self.navigationItem setLeftBarButtonItem:nil animated:YES];
    self.masterPopoverController = nil;
}

#pragma mark - textfield

-(BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    NSInteger val = [textField.text integerValue];
    val = (val > 0)? val : 1;
    val = (val < 1000)? val : 1000;
    [textField setText:[NSString stringWithFormat:@"%d",val]];
    PView::list[textField.tag]->getOptions()->nbIso = val;
    PView::list[textField.tag]->setChanged(true);
    [self requestRender];
    return YES;
}
-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField endEditing:YES];
    return YES;
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
    //[popupMore showFromBarButtonItem:sender animated:true];
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
        /*glView->mContext->setRotation(0, 0, 0);
        glView->mContext->setRotation(90, 0, 0);*/
    }
    else if([text isEqualToString:@"Set Y view"]){
        //glView->mContext->setRotation(0, 90, 0);
    }
    else if([text isEqualToString:@"Set Z view"]){
        //glView->mContext->setRotation(0, 0, 0);
    }
    [glView drawView];
}

void messageFromCpp (void *self, std::string level, std::string msg)
{
    if(level == "RequestRender"){
        [(__bridge id)self requestRender];
        //[[NSNotificationCenter defaultCenter] postNotificationName:@"refreshParameters" object:nil];
    }
    else if(level == "Error")
        ;//[(__bridge id)self showAlert:msg title:level];
}

#pragma mark - tableView

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [models count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *modelName = [models objectAtIndex:indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:modelName];
    if(cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:modelName];
    else
        return cell;
    [cell.textLabel setText:modelName];
    return cell;
}

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return @"Select a model";
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 30;
}

-(NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
     NSString *modelName = [models objectAtIndex:indexPath.row];
     //NSString *ressourcePath = [[NSBundle mainBundle] resourcePath];
    [glView loadMsh:[NSString stringWithFormat:@"%@%@%@",@"/",modelName,@".geo"]];
    //glView->mContext->load([[NSString stringWithFormat:@"%@%@%@%@",ressourcePath,@"/",modelName,@".geo"] UTF8String]);
    [self hideModelsList];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"refreshParameters" object:nil];
    return indexPath;
}

@end
