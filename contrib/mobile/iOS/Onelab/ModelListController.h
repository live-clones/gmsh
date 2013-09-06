//
//  ModelListController.h
//  Onelab
//
//  Created by Maxime Graulich on 31/07/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "EAGLView.h"

@interface ModelListController : UITableViewController <NSXMLParserDelegate, UIActionSheetDelegate>
{
    @private
    NSMutableArray *models;
    NSString *currentElement;
    NSMutableString *currentElementValue;
	NSString *currentDir;
    NSString *selectedModel;
}
@property (nonatomic, retain) EAGLView *glView;
@end
