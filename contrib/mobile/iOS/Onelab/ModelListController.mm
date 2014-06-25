#import "AppDelegate.h"
#import "ModelListController.h"

#import "Utils.h"
#import "Model.h"

@implementation ModelListController
-(void)viewDidLoad
{
  UIRefreshControl *refreshControl = [[UIRefreshControl alloc] init];
  [refreshControl addTarget:self action:@selector(refreshList) forControlEvents:UIControlEventValueChanged];
  self.refreshControl = refreshControl;

  UILongPressGestureRecognizer *lpgr = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPress:)];
  lpgr.minimumPressDuration = 1.0;
  [self.tableView addGestureRecognizer:lpgr];

  models = [[NSMutableArray alloc] init];
  NSString *docsPath = [Utils getApplicationDocumentsDirectory];
  NSArray *docs = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docsPath error:NULL];
  for(NSString* doc in docs) {
    NSString *docPath = [NSString stringWithFormat:@"%@/%@/", docsPath, doc];
    BOOL isDir = NO; [[NSFileManager defaultManager] fileExistsAtPath:docPath isDirectory:&isDir];
    if(isDir){
      NSString *infos = [NSString stringWithFormat:@"%@%@", docPath, @"infos.xml"];
      if([[NSFileManager defaultManager] fileExistsAtPath:infos]) {
        currentDir = docPath;
        [self parseInfosFile:infos];
      }
    }
  }

  UIBarButtonItem *about = [[UIBarButtonItem alloc] initWithTitle:@"About" style:UIBarButtonItemStyleBordered target:self action:@selector(showAbout)];
  [self.navigationItem setRightBarButtonItems:[NSArray arrayWithObjects: about, nil]];
}

-(void)showAbout
{
  [self performSegueWithIdentifier:@"showAboutSegue" sender:self];
}

-(void)refreshList
{
  NSString *docsPath = [Utils getApplicationDocumentsDirectory];
  NSArray *docs = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docsPath error:NULL];
  for(NSString* doc in docs) {
    NSString *docPath = [NSString stringWithFormat:@"%@/%@/", docsPath, doc];
    BOOL isDir = NO; [[NSFileManager defaultManager] fileExistsAtPath:docPath isDirectory:&isDir];
    if(isDir){
      NSString *infos = [NSString stringWithFormat:@"%@%@", docPath, @"infos.xml"];
      if([[NSFileManager defaultManager] fileExistsAtPath:infos]) {
        currentDir = docPath;
        [self parseInfosFile:infos];
      }
    }
  }
  for (int i=0;i<[models count]; i++) {
    if(![[NSFileManager defaultManager] fileExistsAtPath:[models[i] getFile]]) {
      [models removeObject:models[i]];
      i--;
    }
  }
  [self.tableView reloadData];
  [self.refreshControl endRefreshing];
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
  Model *m = [models objectAtIndex:indexPath.row];
  cell = [tableView dequeueReusableCellWithIdentifier:[m getName]];
  if(cell != nil) return cell;
  cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:[m getName]];
  [cell.textLabel setText:[m getName]];
  if([m getSummary] != nil) [cell.detailTextLabel setText:[m getSummary]];
  if([m getPreview] != nil) cell.imageView.image = [m getPreview];
  if([m getFile] == nil) {
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.userInteractionEnabled = NO;
    cell.textLabel.alpha = 0.75;
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
  AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
  selectedModel = [[models objectAtIndex:indexPath.row] getFile];
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

-(void)handleLongPress:(UILongPressGestureRecognizer *)sender
{
  CGPoint p = [sender locationInView:self.tableView];
  if(sender.state == UIGestureRecognizerStateCancelled) return;
  NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint:p];
  if(indexPath == nil) return;
  UIActionSheet *actionSheet;
  if([[models objectAtIndex:indexPath.row] getUrl])
    actionSheet = [[UIActionSheet alloc] initWithTitle:[[models objectAtIndex:indexPath.row] getName] delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles: @"Open this model", @"More information", nil];
  else
    actionSheet = [[UIActionSheet alloc] initWithTitle:[[models objectAtIndex:indexPath.row] getName] delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles: @"Open this model", nil];
  actionSheet.tag = indexPath.row;
  [actionSheet showInView:self.view];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
  switch (buttonIndex) {
  case 1:
    [[UIApplication sharedApplication] openURL:[[models objectAtIndex:actionSheet.tag] getUrl]];
    break;
  case 0:
    [self tableView:self.tableView didSelectRowAtIndexPath:[NSIndexPath indexPathForRow:actionSheet.tag inSection:0]];
    break;
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
  if([elementName isEqual:@"title"]) {
    for(Model *mp in models) {
      if([[mp getName] isEqual:currentElementValue]){
        [parser abortParsing];
        return;
      }
    }
    Model *m = [[Model alloc] initWithName:currentElementValue];
    [models addObject:m];
  }
  else {
    if(models.count < 1) return;
    if([elementName isEqual:@"summary"]) {
      Model *m = [models lastObject];
      [m setSummary:currentElementValue];
    }
    else if([elementName isEqual:@"file"]) {
      Model *m = [models lastObject];
      [m setFile:[NSString stringWithFormat:@"%@%@", currentDir, currentElementValue]];
    }
    else if([elementName isEqual:@"url"]) {
      Model *m = [models lastObject];
      [m setUrl:currentElementValue];
    }
    else if([elementName isEqual:@"preview"]) {
      Model *m = [models lastObject];
      [m setPreview:[NSString stringWithFormat:@"%@%@", currentDir, currentElementValue]];
    }

  }
  //[currentElementValue release];
  currentElementValue = nil;
}

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
  if ([[segue identifier] isEqualToString:@"showModelSegue"]) {
    ModelViewController *modelViewController = [segue destinationViewController];
    modelViewController.initialModel = selectedModel;
  }
}
@end
