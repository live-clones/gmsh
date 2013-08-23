//
//  PostProcessingViewController.h
//  Onelab
//
//  Created by Maxime Graulich on 22/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

@interface PostProcessingViewController : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>
{
@private
    PView *_pview;
}

@property (weak, nonatomic) IBOutlet UILabel *Name;
@property (weak, nonatomic) IBOutlet UIPickerView *IntervalsType;
@property (weak, nonatomic) IBOutlet UITextField *Intervals;
@property (weak, nonatomic) IBOutlet UISlider *RaiseZ;

- (void)setPView:(PView*)p;

@end
