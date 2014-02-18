//
//  Utils.m
//  Onelab
//
//  Created by Maxime Graulich on 06/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "Utils.h"

@implementation Utils

+ (NSString *) getApplicationDocumentsDirectory
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *basePath = ([paths count] > 0) ? [paths objectAtIndex:0] : nil;
    return basePath;
}

+ (void) copyRes
{
    NSString *resPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"files"];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docPath = [paths objectAtIndex:0]; //Get the docs directory
    
    NSArray *resContents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:resPath error:NULL];
    //[[NSFileManager defaultManager] removeItemAtPath:[docPath stringByAppendingString:@"/"] error:nil];
    for (NSString* obj in resContents){
        NSError* error;
        if (![[NSFileManager defaultManager] copyItemAtPath:[resPath stringByAppendingPathComponent:obj] toPath:[docPath stringByAppendingPathComponent:obj] error:&error])
            NSLog(@"Error: %@", error);
    }
}

@end
