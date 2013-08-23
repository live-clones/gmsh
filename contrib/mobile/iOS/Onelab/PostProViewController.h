//
//  PostProViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 13/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PostProViewController : UITableViewController <UITextFieldDelegate>
{
@private
    UIViewController *_prevViewController;
    UISegmentedControl *control;
}
- (void)setPreviousViewController:(UIViewController*)prev;
@end
