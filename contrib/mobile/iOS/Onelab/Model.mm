#import "Model.h"

@implementation Model

- (id)initWithName:(NSString *)name
{
  self = [super init];
  if(self) {
    _name = name;
    _summary = nil;
    _file = nil;
    _url = nil;
    _preview = nil;
  }
  return self;
}

- (id)initWithName:(NSString *)name
       withSummary:(NSString *)summary
          withFile:(NSString *)file
{
  self = [super init];
  if(self) {
    _name = name;
    _summary = summary;
    _file = file;
    _url = nil;
    _preview = nil;
  }
  return self;
}

- (NSString *)getName
{
  return _name;
}

- (NSString *)getSummary
{
  return _summary;
}

- (NSString *)getFile
{
  return _file;
}

- (NSURL *)getUrl
{
  return _url;
}

- (UIImage *)getPreview
{
  return _preview;
}

- (void)setSummary:(NSString *)summary
{
  _summary = summary;
}

- (void)setFile:(NSString *)file
{
  _file = file;
}

- (void)setPreview:(NSString *)path
{
  _preview = [UIImage imageWithContentsOfFile:path];
}

- (void)setUrl:(NSString *)url
{
  _url = [NSURL URLWithString:url];
}

- (NSComparisonResult)compare:(Model *)p
{
  return [[self getName] compare:[p getName]];
}

@end
