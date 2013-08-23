//
//  ModelListController.m
//  Onelab
//
//  Created by Maxime Graulich on 31/07/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "AppDelegate.h"
#import "ModelListController.h"

#import "Utils.h"

@implementation ModelListController
-(void)viewDidLoad
{
    models = [[NSMutableArray alloc] init];
    modelsName = [[NSMutableArray alloc] init];
    modelsDescription = [[NSMutableArray alloc] init];
    NSString *docsPath = [Utils getApplicationDocumentsDirectory];
    
    [Utils copyRes];
    NSArray *docs = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docsPath error:NULL];
    for(NSString* doc in docs){
        NSString *docPath = [NSString stringWithFormat:@"%@/%@/", docsPath, doc];
        BOOL isDir = NO; [[NSFileManager defaultManager] fileExistsAtPath:docPath isDirectory:&isDir];
        if(isDir){
            [models addObject:doc];
            NSString *infos = [NSString stringWithFormat:@"%@%@", docPath, @"infos.xml"];
            if([[NSFileManager defaultManager] fileExistsAtPath:infos]) {
                [self parseInfosFile:infos];
                if(models.count > modelsName.count)[modelsName addObject:@""];
                if(models.count > modelsDescription.count)[modelsDescription addObject:@""];
            }
            else {
                [modelsName addObject:@""];
                [modelsDescription addObject:@""];
            }
        }
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [models count];
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell;
    if(indexPath.row >= [models count])
        return cell;
    NSString *modelName = [models objectAtIndex:indexPath.row];
    cell = [tableView dequeueReusableCellWithIdentifier:modelName];
    if(cell != nil) return cell;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:modelName];
    [cell.textLabel setText:(![[modelsName objectAtIndex:indexPath.row] isEqual:@""])? [modelsName objectAtIndex:indexPath.row] : [models objectAtIndex:indexPath.row]];
    if(![[modelsDescription objectAtIndex:indexPath.row] isEqual:@""])
        [cell.detailTextLabel setText:[modelsDescription objectAtIndex:indexPath.row]];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}
-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return @"Select a model";
}
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    selectedModel = [NSString stringWithFormat:@"%@/%@/%@.geo",[Utils getApplicationDocumentsDirectory],[models objectAtIndex:indexPath.row], [models objectAtIndex:indexPath.row]];
    if([[UIDevice currentDevice].model isEqualToString:@"iPad"] || [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
        appDelegate.splitViewController.initialModel = selectedModel;
        [UIView transitionWithView:appDelegate.window
                          duration:0.5
                           options:UIViewAnimationOptionTransitionFlipFromLeft
                        animations:^{ appDelegate.window.rootViewController = appDelegate.splitViewController; }
                        completion:nil];
    }
    else
    {
        [self performSegueWithIdentifier:@"showModelSegue" sender:self];
    }
}
- (BOOL) parseInfosFile:(NSString *)file
{
    NSData *xmlFile = [[NSFileManager defaultManager] contentsAtPath:file];
    NSXMLParser *parser;
    parser = [[NSXMLParser alloc] initWithData:xmlFile];
    [parser setDelegate:self];

    [parser setShouldProcessNamespaces:NO];
    [parser setShouldReportNamespacePrefixes:NO];
    [parser setShouldResolveExternalEntities:NO];
    
    return [parser parse];
}
-(void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName attributes:(NSDictionary *)attributeDict
{
    currentElement = elementName;
	//[currentElementValue release];
    currentElementValue = nil;
}
-(void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string
{
    if (!currentElementValue)
        currentElementValue = [[NSMutableString alloc] initWithString:string];
    else
        [currentElementValue appendString:string];
}
-(void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    if([elementName isEqual:@"name"] && models.count > modelsName.count) [modelsName addObject:currentElementValue];
    else if([elementName isEqual:@"description"] && models.count > modelsDescription.count) [modelsDescription addObject:currentElementValue];
    //[currentElementValue release];
    currentElementValue = nil;
}
-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"showModelSegue"])
    {
        ModelViewController *modelViewController = [segue destinationViewController];
        modelViewController.initialModel = selectedModel;
    }
}
@end
