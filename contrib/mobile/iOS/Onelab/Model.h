//
//  Model.h
//  Onelab
//
//  Created by Maxime Graulich on 03/09/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Model : NSObject
{
    @private
    NSString *_name, *_summary, *_file;
    NSURL *_url;
    UIImage *_preview;
}
-(id) initWithName:(NSString *)name;
-(id) initWithName:(NSString *)name withSummary:(NSString *)summary withFile:(NSString *)file;
-(NSString *) getName;
-(NSString *) getSummary;
-(NSString *) getFile;
-(void) setSummary:(NSString *)summary;
-(void) setFile:(NSString *)file;
-(NSURL *) getUrl;
-(UIImage *) getPreview;
-(void) setPreview:(NSString *)path;
-(void) setUrl:(NSString *)url;
@end
