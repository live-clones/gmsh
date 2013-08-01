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
    //NSString *modelName = [models objectAtIndex:indexPath.row];
    switch (indexPath.row) {
        case 0:
            cell = [tableView dequeueReusableCellWithIdentifier:@"magnet"];
            if(cell == nil)
                cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"magnet"];
            else
                return cell;
            [cell.textLabel setText:@"Magnet"];
            [cell.detailTextLabel setText:@"A simple magnet example"];
            cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            return cell;
            break;
        case 1:
            cell = [tableView dequeueReusableCellWithIdentifier:@"pmsm"];
            if(cell == nil)
                cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"pmsm"];
            else
                return cell;
            [cell.textLabel setText:@"Eight-pole permanent magnet synchronous machine"];
            cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            return cell;
            break;
        default:
            cell = [tableView dequeueReusableCellWithIdentifier:@"Default"];
            if(cell == nil)
                return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"Default"];
            else
                return cell;
            break;
    }
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
