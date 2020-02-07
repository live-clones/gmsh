#import "ModelListController.h"
#import "AboutViewController.h"
#import "AppDelegate.h"

#import "Model.h"
#import "Utils.h"

@implementation ModelListController
- (void)viewDidLoad
{
  UIRefreshControl *refreshControl = [[UIRefreshControl alloc] init];
  [refreshControl addTarget:self
                     action:@selector(refreshList)
           forControlEvents:UIControlEventValueChanged];
  self.refreshControl = refreshControl;

  UILongPressGestureRecognizer *lpgr = [[UILongPressGestureRecognizer alloc]
    initWithTarget:self
            action:@selector(handleLongPress:)];
  lpgr.minimumPressDuration = 1.0;
  [self.tableView addGestureRecognizer:lpgr];

  models = [[NSMutableArray alloc] init];
  NSString *docsPath = [Utils getApplicationDocumentsDirectory];
  NSArray *docs =
    [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docsPath
                                                        error:NULL];
  for(NSString *doc in docs) {
    NSString *docPath = [NSString stringWithFormat:@"%@/%@/", docsPath, doc];
    BOOL isDir = NO;
    [[NSFileManager defaultManager] fileExistsAtPath:docPath
                                         isDirectory:&isDir];
    if(isDir) {
      NSString *infos =
        [NSString stringWithFormat:@"%@%@", docPath, @"infos.xml"];
      if([[NSFileManager defaultManager] fileExistsAtPath:infos]) {
        currentDir = docPath;
        [self parseInfosFile:infos];
      }
    }
  }
  [models sortUsingSelector:@selector(compare:)];

  UIBarButtonItem *about =
    [[UIBarButtonItem alloc] initWithTitle:@"About"
                                     style:UIBarButtonItemStylePlain
                                    target:self
                                    action:@selector(showAbout)];
  [self.navigationItem
    setRightBarButtonItems:[NSArray arrayWithObjects:about, nil]];

  UIBarButtonItem *help =
    [[UIBarButtonItem alloc] initWithTitle:@"Help"
                                     style:UIBarButtonItemStylePlain
                                    target:self
                                    action:@selector(showHelp)];
  [self.navigationItem
    setLeftBarButtonItems:[NSArray arrayWithObjects:help, nil]];
}

- (void)showAbout
{
  currentFileToEdit = @"About";
  [self performSegueWithIdentifier:@"showAboutSegue" sender:self];
}

- (void)showHelp
{
  currentFileToEdit = @"Help";
  [self performSegueWithIdentifier:@"showAboutSegue" sender:self];
}

- (void)refreshList
{
  NSString *docsPath = [Utils getApplicationDocumentsDirectory];
  NSArray *docs =
    [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docsPath
                                                        error:NULL];
  for(NSString *doc in docs) {
    NSString *docPath = [NSString stringWithFormat:@"%@/%@/", docsPath, doc];
    BOOL isDir = NO;
    [[NSFileManager defaultManager] fileExistsAtPath:docPath
                                         isDirectory:&isDir];
    if(isDir) {
      NSString *infos =
        [NSString stringWithFormat:@"%@%@", docPath, @"infos.xml"];
      if([[NSFileManager defaultManager] fileExistsAtPath:infos]) {
        currentDir = docPath;
        [self parseInfosFile:infos];
      }
    }
  }
  for(int i = 0; i < [models count]; i++) {
    if(![[NSFileManager defaultManager] fileExistsAtPath:[models[i] getFile]]) {
      [models removeObject:models[i]];
      i--;
    }
  }
  [models sortUsingSelector:@selector(compare:)];
  [self.tableView reloadData];
  [self.refreshControl endRefreshing];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
  return 1;
}

- (NSInteger)tableView:(UITableView *)tableView
  numberOfRowsInSection:(NSInteger)section
{
  return [models count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
  UITableViewCell *cell;
  if(indexPath.row >= [models count]) return cell;
  Model *m = [models objectAtIndex:indexPath.row];
  cell = [tableView dequeueReusableCellWithIdentifier:[m getName]];
  if(cell != nil) return cell;
  cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle
                                reuseIdentifier:[m getName]];
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

- (NSString *)tableView:(UITableView *)tableView
  titleForHeaderInSection:(NSInteger)section
{
  return @"Select a model";
}

- (void)tableView:(UITableView *)tableView
  didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
  AppDelegate *appDelegate =
    (AppDelegate *)[UIApplication sharedApplication].delegate;
  selectedModel = [[models objectAtIndex:indexPath.row] getFile];
  if([[UIDevice currentDevice].model isEqualToString:@"iPad"] ||
     [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]) {
    appDelegate.splitViewController.initialModel = selectedModel;
    [UIView transitionWithView:appDelegate.window
                      duration:0.5
                       options:UIViewAnimationOptionTransitionFlipFromLeft
                    animations:^{
                      appDelegate.window.rootViewController =
                        appDelegate.splitViewController;
                    }
                    completion:nil];
  }
  else {
    [self performSegueWithIdentifier:@"showModelSegue" sender:self];
  }
}

- (void)handleLongPress:(UILongPressGestureRecognizer *)sender
{
  CGPoint p = [sender locationInView:self.tableView];
  if(sender.state == UIGestureRecognizerStateCancelled) return;
  NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint:p];
  if(indexPath == nil) return;
  UITableViewCell *cell = [self.tableView cellForRowAtIndexPath:indexPath];

  UIAlertController *actionSheet = [UIAlertController
    alertControllerWithTitle:[[models objectAtIndex:indexPath.row] getName]
                     message:nil
              preferredStyle:UIAlertControllerStyleActionSheet];

  [actionSheet
    addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                       style:UIAlertActionStyleCancel
                                     handler:^(UIAlertAction *action){}]];
  [actionSheet
    addAction:[UIAlertAction
                actionWithTitle:@"Open"
                          style:UIAlertActionStyleDefault
                        handler:^(UIAlertAction *action) {
                          [self tableView:self.tableView
                            didSelectRowAtIndexPath:[NSIndexPath
                                                      indexPathForRow:indexPath
                                                                        .row
                                                            inSection:0]];
                        }]];
  [actionSheet addAction:[UIAlertAction
                           actionWithTitle:@"Remove"
                                     style:UIAlertActionStyleDestructive
                                   handler:^(UIAlertAction *action) {
                                     NSString *file = [[self->models
                                       objectAtIndex:indexPath.row] getFile];
                                     NSString *path =
                                       [file stringByDeletingLastPathComponent];
                                     [[NSFileManager defaultManager]
                                       removeItemAtPath:path
                                                  error:nil];
                                     [self refreshList];
                                   }]];
  [actionSheet
    addAction:[UIAlertAction
                actionWithTitle:@"Clear results"
                          style:UIAlertActionStyleDefault
                        handler:^(UIAlertAction *action) {
                          NSString *modelFile = [[self->models
                            objectAtIndex:indexPath.row] getFile];
                          NSString *modelPath =
                            [modelFile stringByDeletingLastPathComponent];
                          NSArray *modelFiles = [[NSFileManager defaultManager]
                            contentsOfDirectoryAtPath:modelPath
                                                error:NULL];
                          for(NSString *obj in modelFiles) {
                            NSString *extension = [obj pathExtension];
                            if([extension isEqualToString:@"msh"] ||
                               [extension isEqualToString:@"pre"] ||
                               [extension isEqualToString:@"res"] ||
                               [extension isEqualToString:@"pos"]) {
                              NSString *file =
                                [[modelPath stringByAppendingString:@"/"]
                                  stringByAppendingString:obj];
                              NSLog(@"Removing file %@", file);
                              [[NSFileManager defaultManager]
                                removeItemAtPath:file
                                           error:nil];
                            }
                          }
                        }]];
  [actionSheet
    addAction:
      [UIAlertAction
        actionWithTitle:@"Edit model files"
                  style:UIAlertActionStyleDefault
                handler:^(UIAlertAction *action) {
                  NSString *modelFile =
                    [[self->models objectAtIndex:indexPath.row] getFile];
                  NSString *modelPath =
                    [modelFile stringByDeletingLastPathComponent];
                  NSArray *modelFiles = [[NSFileManager defaultManager]
                    contentsOfDirectoryAtPath:modelPath
                                        error:NULL];
                  UIAlertController *actionSheet2 = [UIAlertController
                    alertControllerWithTitle:@"Edit model files"
                                     message:nil
                              preferredStyle:UIAlertControllerStyleActionSheet];
                  [actionSheet2
                    addAction:[UIAlertAction
                                actionWithTitle:@"Cancel"
                                          style:UIAlertActionStyleCancel
                                        handler:^(UIAlertAction *action){}]];
                  for(NSString *file in modelFiles) {
                    NSString *extension = [file pathExtension];
                    if([extension isEqualToString:@"txt"] ||
                       [extension isEqualToString:@"geo"] ||
                       [extension isEqualToString:@"pro"] ||
                       [extension isEqualToString:@"dat"]) {
                      [actionSheet2
                        addAction:
                          [UIAlertAction
                            actionWithTitle:file
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction *action) {
                                      NSString *modelFile = [[self->models
                                        objectAtIndex:indexPath.row] getFile];
                                      NSString *modelPath = [modelFile
                                        stringByDeletingLastPathComponent];
                                      self->currentFileToEdit = [[modelPath
                                        stringByAppendingString:@"/"]
                                        stringByAppendingString:file];
                                      [self performSegueWithIdentifier:
                                              @"showAboutSegue"
                                                                sender:self];
                                    }]];
                    }
                  }
                  actionSheet2.popoverPresentationController.sourceView = cell;
                  actionSheet2.popoverPresentationController.sourceRect =
                    cell.bounds;
                  [self presentViewController:actionSheet2
                                     animated:YES
                                   completion:nil];
                }]];
  [actionSheet
    addAction:[UIAlertAction
                actionWithTitle:@"Email model files"
                          style:UIAlertActionStyleDefault
                        handler:^(UIAlertAction *action) {
                          NSString *modelFile = [[self->models
                            objectAtIndex:indexPath.row] getFile];
                          NSString *modelPath =
                            [modelFile stringByDeletingLastPathComponent];
                          NSArray *modelFiles = [[NSFileManager defaultManager]
                            contentsOfDirectoryAtPath:modelPath
                                                error:NULL];
                          // TODO: would probably be better to email a zip
                          // archive? (this ignores subdirectories)
                          [self attachFilesToEmail:modelFiles
                                          filePath:modelPath];
                        }]];
  if([[models objectAtIndex:indexPath.row] getUrl]) {
    [actionSheet
      addAction:[UIAlertAction
                  actionWithTitle:@"Visit model website"
                            style:UIAlertActionStyleDefault
                          handler:^(UIAlertAction *action) {
                            [[UIApplication sharedApplication]
                              openURL:[[self->models
                                        objectAtIndex:indexPath.row] getUrl]];
                          }]];
  }

  actionSheet.popoverPresentationController.sourceView = cell;
  actionSheet.popoverPresentationController.sourceRect = cell.bounds;

  [self presentViewController:actionSheet animated:YES completion:nil];
}

- (void)attachFilesToEmail:(NSArray *)files filePath:(NSString *)path
{
  if([MFMailComposeViewController canSendMail] == NO) return;

  MFMailComposeViewController *mc = [[MFMailComposeViewController alloc] init];
  mc.mailComposeDelegate = self;
  [mc setSubject:@"My ONELAB model"];

  // Add attachments
  for(NSString *file in files) {
    NSString *extension = [file pathExtension];
    NSString *filePath =
      [[path stringByAppendingString:@"/"] stringByAppendingString:file];
    NSData *fileData = [NSData dataWithContentsOfFile:filePath];
    if(fileData) {
      NSString *mimeType;
      if([extension isEqualToString:@"jpg"]) { mimeType = @"image/jpeg"; }
      else if([extension isEqualToString:@"png"]) {
        mimeType = @"image/png";
      }
      else if([extension isEqualToString:@"doc"]) {
        mimeType = @"application/msword";
      }
      else if([extension isEqualToString:@"ppt"]) {
        mimeType = @"application/vnd.ms-powerpoint";
      }
      else if([extension isEqualToString:@"html"]) {
        mimeType = @"text/html";
      }
      else if([extension isEqualToString:@"pdf"]) {
        mimeType = @"application/pdf";
      }
      else {
        mimeType = @"text/plain";
      }

      [mc addAttachmentData:fileData mimeType:@"" fileName:file];
    }
  }

  // Present mail view controller on screen
  [self presentViewController:mc animated:YES completion:NULL];
}

- (void)mailComposeController:(MFMailComposeViewController *)controller
          didFinishWithResult:(MFMailComposeResult)result
                        error:(NSError *)error
{
  switch(result) {
  case MFMailComposeResultCancelled: NSLog(@"Mail cancelled"); break;
  case MFMailComposeResultSaved: NSLog(@"Mail saved"); break;
  case MFMailComposeResultSent: NSLog(@"Mail sent"); break;
  case MFMailComposeResultFailed:
    NSLog(@"Mail sent failure: %@", [error localizedDescription]);
    break;
  default: break;
  }
  // Close the Mail Interface
  [self dismissViewControllerAnimated:YES completion:NULL];
}

- (BOOL)parseInfosFile:(NSString *)file
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

- (void)parser:(NSXMLParser *)parser
  didStartElement:(NSString *)elementName
     namespaceURI:(NSString *)namespaceURI
    qualifiedName:(NSString *)qName
       attributes:(NSDictionary *)attributeDict
{
  currentElement = elementName;
  //[currentElementValue release];
  currentElementValue = nil;
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string
{
  if(!currentElementValue)
    currentElementValue = [[NSMutableString alloc] initWithString:string];
  else
    [currentElementValue appendString:string];
}

- (void)parser:(NSXMLParser *)parser
  didEndElement:(NSString *)elementName
   namespaceURI:(NSString *)namespaceURI
  qualifiedName:(NSString *)qName
{
  if([elementName isEqual:@"title"]) {
    for(Model *mp in models) {
      if([[mp getName] isEqual:currentElementValue]) {
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
      [m setFile:[NSString
                   stringWithFormat:@"%@%@", currentDir, currentElementValue]];
    }
    else if([elementName isEqual:@"url"]) {
      Model *m = [models lastObject];
      [m setUrl:currentElementValue];
    }
    else if([elementName isEqual:@"preview"]) {
      Model *m = [models lastObject];
      [m setPreview:[NSString stringWithFormat:@"%@%@", currentDir,
                                               currentElementValue]];
    }
  }
  //[currentElementValue release];
  currentElementValue = nil;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
  if([[segue identifier] isEqualToString:@"showModelSegue"]) {
    ModelViewController *modelViewController =
      [segue destinationViewController];
    modelViewController.initialModel = selectedModel;
  }
  else if([[segue identifier] isEqualToString:@"showAboutSegue"]) {
    AboutViewController *aboutViewController =
      [segue destinationViewController];
    aboutViewController.fileToEdit = currentFileToEdit;
  }
}
@end
