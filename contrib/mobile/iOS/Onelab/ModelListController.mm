//
//  ModelListController.m
//  Onelab
//
//  Created by Maxime Graulich on 31/07/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#import "ModelListController.h"

@interface ModelListController () {
    
}
@end

// TODO Get model list from "Documents"

@implementation ModelListController
-(void)viewDidLoad
{
    models = [NSArray arrayWithObjects:@"magnet", @"pmsm", nil];
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
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:modelName];
    switch (indexPath.row) {
        case 0:
            [cell.textLabel setText:@"Magnet"];
            [cell.detailTextLabel setText:@"A simple magnet example"];
            break;
        case 1:
            [cell.textLabel setText:@"Eight-pole permanent magnet synchronous machine"];
            break;
    }
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}
-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return @"Select a model";
}
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *modelName = [models objectAtIndex:indexPath.row];
    [_glView loadMsh:[NSString stringWithFormat:@"%@%@%@",@"/",modelName,@".geo"]];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"refreshParameters" object:nil];
    [self.navigationController popViewControllerAnimated:YES];
}
@end
