#import "AppDelegate.h"
#import "ModelListController.h"
#import "AboutViewController.h"

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
  [models sortUsingSelector:@selector(compare:)];

  UIBarButtonItem *about = [[UIBarButtonItem alloc] initWithTitle:@"About" style:UIBarButtonItemStylePlain target:self action:@selector(showAbout)];
  [self.navigationItem setRightBarButtonItems:[NSArray arrayWithObjects: about, nil]];
}

-(void)showAbout
{
	currentFileToEdit = nil;
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
  [models sortUsingSelector:@selector(compare:)];
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
  if([[UIDevice currentDevice].model isEqualToString:@"iPad"] ||
     [[UIDevice currentDevice].model isEqualToString:@"iPad Simulator"]){
    appDelegate.splitViewController.initialModel = selectedModel;
    [UIView transitionWithView:appDelegate.window
                      duration:0.5
                       options:UIViewAnimationOptionTransitionFlipFromLeft
                    animations:^{ appDelegate.window.rootViewController = appDelegate.splitViewController; }
    completion:nil];
  }
  else{
		[self performSegueWithIdentifier:@"showModelSegue" sender:self];
	}
}

-(void)handleLongPress:(UILongPressGestureRecognizer *)sender
{
  CGPoint p = [sender locationInView:self.tableView];
  if(sender.state == UIGestureRecognizerStateCancelled) return;
  NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint:p];
  if(indexPath == nil) return;
	if([[models objectAtIndex:indexPath.row] getUrl])
    self.longPressActionSheet = [[UIActionSheet alloc] initWithTitle:[[models objectAtIndex:indexPath.row] getName] delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles: @"Open", @"Remove", @"Clear results", @"Edit model files", @"Email model files", @"Visit model website", nil];
  else
		self.longPressActionSheet = [[UIActionSheet alloc] initWithTitle:[[models objectAtIndex:indexPath.row] getName] delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles: @"Open", @"Remove", @"Clear results", @"Edit model files", @"Email model files", nil];
  self.longPressActionSheet.tag = indexPath.row;
  [self.longPressActionSheet showInView:self.view];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
	if(actionSheet == self.longPressActionSheet){
    switch (buttonIndex) {
		case 5:
      [[UIApplication sharedApplication] openURL:[[models objectAtIndex:actionSheet.tag] getUrl]];
      break;
		case 4:
			{
				NSString *modelFile = [[models objectAtIndex:actionSheet.tag] getFile];
				NSString *modelPath = [modelFile stringByDeletingLastPathComponent];
				NSArray *modelFiles = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:modelPath error:NULL];
				// TODO: would probably be better to email a zip archive? (this ignores subdirectories)
				[self attachFilesToEmail:modelFiles filePath:modelPath];
			}
			break;
		case 3:
			{
				NSString *modelFile = [[models objectAtIndex:actionSheet.tag] getFile];
				NSString *modelPath = [modelFile stringByDeletingLastPathComponent];
				NSArray *modelFiles = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:modelPath error:NULL];
				self.editFilesActionSheet = [[UIActionSheet alloc] initWithTitle:@"Model files" delegate:self
																											 cancelButtonTitle: nil
																									destructiveButtonTitle: nil
																											 otherButtonTitles: nil];
				for(NSString *file in modelFiles)  {
					NSString *extension = [file pathExtension];
					if([extension isEqualToString:@"txt"] ||
						 [extension isEqualToString:@"geo"] ||
						 [extension isEqualToString:@"pro"] ||
						 [extension isEqualToString:@"dat"]){
						[self.editFilesActionSheet addButtonWithTitle:file];
					}
				}
				[self.editFilesActionSheet addButtonWithTitle:@"Cancel"];
				self.editFilesActionSheet.cancelButtonIndex = [modelFiles count];
				self.editFilesActionSheet.tag = actionSheet.tag;
				[self.editFilesActionSheet showInView:self.view];
			}
		  break;
    case 2:
      {
				NSString *modelFile = [[models objectAtIndex:actionSheet.tag] getFile];
				NSString *modelPath = [modelFile stringByDeletingLastPathComponent];
				NSArray *modelFiles = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:modelPath error:NULL];
				for (NSString *obj in modelFiles){
					NSString *extension = [obj pathExtension];
					if([extension isEqualToString:@"msh"] ||
						 [extension isEqualToString:@"pre"] ||
						 [extension isEqualToString:@"res"] ||
						 [extension isEqualToString:@"pos"]){
						NSString *file = [[modelPath stringByAppendingString:@"/"] stringByAppendingString:obj];
						NSLog(@"Removing file %@", file);
						[[NSFileManager defaultManager] removeItemAtPath:file error:nil];
					}
				}
			}
      break;
    case 1:
			{
				NSString *file = [[models objectAtIndex:actionSheet.tag] getFile];
				NSString *path = [file stringByDeletingLastPathComponent];
				[[NSFileManager defaultManager] removeItemAtPath:path error:nil];
				[self refreshList];
			}
      break;
		case 0:
			[self tableView:self.tableView didSelectRowAtIndexPath:[NSIndexPath indexPathForRow:actionSheet.tag inSection:0]];
      break;
    }
	}
	else{
		NSString *modelFile = [[models objectAtIndex:actionSheet.tag] getFile];
		NSString *modelPath = [modelFile stringByDeletingLastPathComponent];
		currentFileToEdit = [[modelPath stringByAppendingString:@"/"]
												 stringByAppendingString:[actionSheet buttonTitleAtIndex:buttonIndex]];
		[self performSegueWithIdentifier:@"showAboutSegue" sender:self];
	}
}

- (void)attachFilesToEmail:(NSArray*)files filePath:(NSString*)path
{
	if([MFMailComposeViewController canSendMail] == NO) return;
	
	MFMailComposeViewController *mc = [[MFMailComposeViewController alloc] init];
	mc.mailComposeDelegate = self;
	[mc setSubject:@"My ONELAB model"];
	
	// Add attachments
	for (NSString *file in files){
		NSString *extension = [file pathExtension];
		NSString *filePath = [[path stringByAppendingString:@"/"] stringByAppendingString:file];
		NSData *fileData = [NSData dataWithContentsOfFile:filePath];
		if(fileData){
			NSString *mimeType;
			if ([extension isEqualToString:@"jpg"]) {
				mimeType = @"image/jpeg";
			}
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
			else{
				mimeType = @"text/plain";
			}

			[mc addAttachmentData:fileData mimeType:@"" fileName:file];
		}
	}
	
	// Present mail view controller on screen
	[self presentViewController:mc animated:YES completion:NULL];
	
}

- (void) mailComposeController:(MFMailComposeViewController *)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error
{
	switch (result){
	case MFMailComposeResultCancelled: NSLog(@"Mail cancelled"); break;
	case MFMailComposeResultSaved: NSLog(@"Mail saved"); break;
	case MFMailComposeResultSent: NSLog(@"Mail sent"); break;
	case MFMailComposeResultFailed: NSLog(@"Mail sent failure: %@", [error localizedDescription]); break;
  default: break;
	}
	// Close the Mail Interface
	[self dismissViewControllerAnimated:YES completion:NULL];
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
	else if ([[segue identifier] isEqualToString:@"showAboutSegue"]) {
		AboutViewController *aboutViewController = [segue destinationViewController];
		aboutViewController.fileToEdit = currentFileToEdit;
	}
}
@end
