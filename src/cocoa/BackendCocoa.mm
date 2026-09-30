// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>

#include "cocoaCommon.h"
#include "Console.h"

// The Cocoa interface: one window -- the tree down the left, the scene and
// the console under it, the bar along the bottom -- the menus in the bar at
// the top of the screen, and a panel for each described form
// (dialogCocoa.mm). The loop is AppKit's, turned by hand -- nextEvent and
// sendEvent, never [NSApp run] -- so that check() and wait() can turn it from
// inside the mesher, and a question can run a modal loop of its own.

@interface GmshMainWindow : NSWindow <NSWindowDelegate> {
@public
  bool closing;
}
@end

@interface GmshConsole : NSTextView
@end

// the tree taken out of the main window: closed from its frame, it goes back
@interface GmshTreePanel : NSPanel <NSWindowDelegate>
@end

// the console with the bar over its lines: the filter, Save, Clear,
// Autoscroll, as Ui::Console says them
@interface GmshConsoleBox : GmshFlippedView {
@public
  NSImageView *look;
  NSTextField *filter;
  NSButton *save, *clear, *copy, *follow;
  NSScrollView *lines;
}
@end

@interface GmshConsoleTarget : NSObject <NSTextFieldDelegate>
- (void)save:(id)sender;
- (void)clear:(id)sender;
- (void)copy:(id)sender;
- (void)follow:(id)sender;
@end

@interface GmshMainView : NSView
@end

@interface GmshTreeBox : NSView {
@public
  NSView *tree, *footer;
}
@end

// the bar of the main window or of a graphic window of its own
@interface GmshBar : NSView {
@public
  NSView *buttons;
  NSButton *message;
  NSTextField *progressText;
  NSProgressIndicator *progress;
  // what makes its buttons be made again
  std::string built;
}
@end

@interface GmshBarTarget : NSObject {
@public
  std::size_t index;
}
- (void)pressed:(id)sender;
@end

@interface GmshAppDelegate : NSObject <NSApplicationDelegate>
@end

// a block run when an entry of a menu is chosen
@interface GmshPopUpBlock : NSObject {
@public
  void (^chose)(NSInteger);
}
- (void)chose:(id)sender;
@end

@implementation GmshPopUpBlock
- (void)chose:(id)sender
{
  if(chose) chose([(NSPopUpButton *)sender indexOfSelectedItem]);
}
@end

namespace {

  // --- the main window and what it holds

  struct mainWindow {
    GmshMainWindow *window = nil;
    NSSplitView *side = nil, *split = nil;
    GmshTreeBox *treeBox = nil;
    // the tree in a window of its own, when it is detached
    GmshTreePanel *treePanel = nil;
    NSScrollView *consoleScroll = nil;
    GmshConsoleBox *consoleBox = nil;
    GmshConsole *messages = nil;
    GmshBar *bar = nil;
    treeCocoa *tree = nullptr;
    std::string footerBuilt;
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console said;
    bool fullscreen = false, treeWas = true, consoleWas = true;
    CGFloat consoleHeight = 150., treeWidth = 300.;
  };

  mainWindow *_w = nullptr;
  bool _running = false;
  int _locked = 0;
  double _lastCheck = -1e10;
  GmshAppDelegate *_delegate = nil;

  double _now() { return [NSDate timeIntervalSinceReferenceDate]; }

  // what a control is associated with: its target, which it does not keep;
  // the room before a button of the bar, and its width
  const char _targetKey = 0, _gapKey = 0, _widthKey = 0;

  CGFloat _barHeight() { return std::ceil(cocoaRowHeight() + 6.); }

  void _consoleFont(int size)
  {
    if(!_w) return;
    NSFont *f = cocoaFixedFont(size > 0 ? size : cocoaEm() - 2.);
    [_w->messages setFont:f];
  }

  bool _dark()
  {
    NSAppearance *a =
      _w ? [_w->messages effectiveAppearance] : [NSApp effectiveAppearance];
    return [[a bestMatchFromAppearancesWithNames:@[
      NSAppearanceNameAqua, NSAppearanceNameDarkAqua
    ]] isEqualToString:NSAppearanceNameDarkAqua];
  }

  // one turn of the loop: an event, or nothing once `until` is past
  bool _turn(NSDate *until)
  {
    @autoreleasepool {
      NSEvent *e = [NSApp nextEventMatchingMask:NSEventMaskAny
                                      untilDate:until
                                         inMode:NSDefaultRunLoopMode
                                        dequeue:YES];
      if(!e) return false;
      if([e type] != NSEventTypeApplicationDefined) [NSApp sendEvent:e];
      [NSApp updateWindows];
      return true;
    }
  }

  // what changed, on the screen: AppKit draws before the loop sleeps, and a
  // loop turned from inside the mesher never does
  void _display()
  {
    for(NSWindow *w in [NSApp windows])
      if([w isVisible] && [w viewsNeedDisplay]) [w displayIfNeeded];
    [CATransaction flush];
  }

  // what is waiting, and no more
  void _drain()
  {
    for(int i = 0; i < 1000 && _turn([NSDate distantPast]); i++) {}
    _display();
  }

  void _refreshFooter()
  {
    if(!_w) return;
    std::vector<Ui::Button> row = cocoaSources().tree.footer ?
                                    cocoaSources().tree.footer() :
                                    std::vector<Ui::Button>();
    std::string shape = Ui::signature(row);
    if(shape == _w->footerBuilt) return;
    _w->footerBuilt = shape;
    NSView *footer = _w->treeBox->footer;
    for(NSView *v in [[footer subviews] copy]) [v removeFromSuperview];
    for(const auto &b : row)
      [footer addSubview:cocoaButtonWidget(b, []() {
                cocoaLater([]() {
                  if(_w && _w->tree) _w->tree->refresh(false);
                  _refreshFooter();
                });
              })];
    [footer setHidden:row.empty()];
    [_w->treeBox resizeSubviewsWithOldSize:NSZeroSize];
  }

  void _showConsole(bool show)
  {
    if(!_w) return;
    NSView *c = _w->consoleBox;
    if(show == ![c isHidden]) return;
    if(!show) _w->consoleHeight = std::max((CGFloat)40., [c frame].size.height);
    [c setHidden:!show];
    [_w->split adjustSubviews];
    if(show) {
      CGFloat all = [_w->split bounds].size.height;
      [_w->split
             setPosition:std::max((CGFloat)50., all - _w->consoleHeight -
                                                  [_w->split dividerThickness])
        ofDividerAtIndex:0];
    }
  }

  bool _treeShown()
  {
    return _w->treePanel ? [_w->treePanel isVisible] : ![_w->treeBox isHidden];
  }

  void _showTree(bool show)
  {
    if(!_w) return;
    if(_w->treePanel) {
      if(show)
        [_w->treePanel orderFront:nil];
      else
        [_w->treePanel orderOut:nil];
      return;
    }
    NSView *t = _w->treeBox;
    if(show == ![t isHidden]) return;
    if(!show) _w->treeWidth = std::max((CGFloat)50., [t frame].size.width);
    [t setHidden:!show];
    [_w->side adjustSubviews];
    if(show) [_w->side setPosition:_w->treeWidth ofDividerAtIndex:0];
  }

  // from the top left of the screen, as the other interfaces have it
  NSPoint _topLeft(int x, int y)
  {
    NSRect all = [[NSScreen mainScreen] visibleFrame];
    return NSMakePoint(all.origin.x + x, NSMaxY(all) - y);
  }

  // the tree taken out of the main window into a panel of its own, and put
  // back
  void _detachTree(bool detached)
  {
    if(!_w || detached == (_w->treePanel != nil)) return;
    if(detached) {
      const Ui::Backend::Settings set = cocoaSources().settings();
      if(![_w->treeBox isHidden])
        _w->treeWidth = std::max((CGFloat)50., [_w->treeBox frame].size.width);
      [_w->treeBox removeFromSuperview];
      [_w->side adjustSubviews];
      CGFloat h = set.treeHeight > 0 ? set.treeHeight : 600.;
      GmshTreePanel *panel = [[GmshTreePanel alloc]
        initWithContentRect:NSMakeRect(0, 0, _w->treeWidth, h)
                  styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                            NSWindowStyleMaskResizable |
                            NSWindowStyleMaskMiniaturizable
                    backing:NSBackingStoreBuffered
                      defer:NO];
      [panel setTitle:@"Gmsh"];
      [panel setFloatingPanel:NO];
      [panel setHidesOnDeactivate:NO];
      [panel setReleasedWhenClosed:NO];
      [panel setDelegate:panel];
      [_w->treeBox setHidden:NO];
      [panel setContentView:_w->treeBox];
      [_w->treeBox resizeSubviewsWithOldSize:NSZeroSize];
      if(set.treeX > 0 || set.treeY > 0)
        [panel setFrameTopLeftPoint:_topLeft(set.treeX, set.treeY)];
      else
        [panel center];
      _w->treePanel = panel;
      [panel makeKeyAndOrderFront:nil];
      return;
    }
    if(cocoaHost().layoutChanged) {
      NSRect all = [[NSScreen mainScreen] visibleFrame];
      NSRect f = [_w->treePanel frame];
      Ui::Backend::Layout l;
      l.treeX = (int)(f.origin.x - all.origin.x);
      l.treeY = (int)(NSMaxY(all) - NSMaxY(f));
      l.treeHeight = (int)[[_w->treePanel contentView] frame].size.height;
      cocoaHost().layoutChanged(l);
    }
    GmshTreePanel *panel = _w->treePanel;
    _w->treePanel = nil;
    [panel setContentView:[[NSView alloc] initWithFrame:NSZeroRect]];
    [panel orderOut:nil];
    [_w->side addSubview:_w->treeBox positioned:NSWindowBelow
              relativeTo:_w->split];
    [_w->side adjustSubviews];
    [_w->side setPosition:_w->treeWidth ofDividerAtIndex:0];
    [_w->treeBox resizeSubviewsWithOldSize:NSZeroSize];
  }

  // nothing but the scene
  void _fullscreenParts(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    if(on) {
      _w->treeWas = _treeShown();
      _w->consoleWas = ![_w->consoleBox isHidden];
    }
    _showTree(!on && _w->treeWas);
    _showConsole(!on && _w->consoleWas);
    [_w->bar setHidden:on];
    [[_w->window contentView] resizeSubviewsWithOldSize:NSZeroSize];
  }

  // the extensions a panel allows; none for anything
  std::vector<std::string> _extensions(const Ui::Backend::FileFormat &f)
  {
    std::vector<std::string> out;
    for(const auto &one : f.patterns()) {
      std::size_t dot = one.rfind('.');
      std::string ext = dot == std::string::npos ? one : one.substr(dot + 1);
      if(ext.empty() || ext.find('*') != std::string::npos) return {};
      out.push_back(ext);
    }
    return out;
  }

  void _allow(NSSavePanel *panel, const std::vector<std::string> &extensions)
  {
    NSMutableArray *types = nil;
    if(extensions.size()) {
      types = [NSMutableArray array];
      for(const auto &e : extensions) [types addObject:cocoaString(e)];
    }
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    [panel setAllowedFileTypes:types];
#pragma clang diagnostic pop
    [panel setAllowsOtherFileTypes:YES];
  }

  NSInteger _modal(NSAlert *alert)
  {
    // the question comes before whatever else is up
    [NSApp activateIgnoringOtherApps:YES];
    return [alert runModal];
  }

} // namespace

// --- the pieces of the main window

@implementation GmshTreePanel
- (void)keyDown:(NSEvent *)e
{
  cocoaMainKey(e);
}
- (BOOL)windowShouldClose:(NSWindow *)sender
{
  cocoaLater([]() { _detachTree(false); });
  return NO;
}
@end

@implementation GmshMainWindow
// what nothing took is Gmsh's, or nothing: a key Gmsh has no use for does not
// beep
- (void)keyDown:(NSEvent *)e
{
  cocoaMainKey(e);
}
- (BOOL)windowShouldClose:(NSWindow *)sender
{
  if(closing) return YES;
  std::function<void()> quit = cocoaHost().quitting;
  if(quit) cocoaLater(quit);
  return NO;
}
- (void)windowWillEnterFullScreen:(NSNotification *)n
{
  _fullscreenParts(true);
}
- (void)windowDidExitFullScreen:(NSNotification *)n
{
  _fullscreenParts(false);
}
@end

void cocoaForgetMessages()
{
  if(_w) _w->said.clear();
}

namespace {

  // a line in its colour, at the end
  void _consoleLine(const std::string &text, int level)
  {
    static const unsigned light[] = {0x1a4fa0, 0, 0xa05a00, 0xb00000,
                                     0x707070};
    static const unsigned dark[] = {0x8ab4f8, 0, 0xf0b060, 0xff7070, 0xa0a0a0};
    // on the colour the console is drawn on, whatever the option says
    unsigned ink =
      (level >= 0 && level <= 4) ? (_dark() ? dark[level] : light[level]) : 0;
    NSColor *colour = ink ? [NSColor colorWithSRGBRed:((ink >> 16) & 255) / 255.
                                                green:((ink >> 8) & 255) / 255.
                                                 blue:(ink & 255) / 255.
                                                alpha:1.] :
                            [NSColor textColor];
    NSTextStorage *all = [_w->messages textStorage];
    NSString *line = cocoaString(text);
    if([all length]) line = [@"\n" stringByAppendingString:line];
    NSFont *font = [_w->messages font] ?: cocoaFixedFont(0.);
    [all appendAttributedString:[[NSAttributedString alloc]
                                  initWithString:line
                                      attributes:@{
                                        NSForegroundColorAttributeName : colour,
                                        NSFontAttributeName : font
                                      }]];
  }

  void _consoleFollow()
  {
    [_w->messages
      scrollRangeToVisible:NSMakeRange([[_w->messages textStorage] length], 0)];
  }

  // the lines again, the filter having changed
  void _consoleRefill()
  {
    [[_w->messages textStorage]
      setAttributedString:[[NSAttributedString alloc] init]];
    for(const Ui::Console::Line *l : _w->said.shown())
      _consoleLine(l->text, l->level);
    if(_w->said.autoScroll()) _consoleFollow();
  }

} // namespace

@implementation GmshConsoleBox
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  NSRect b = [self bounds];
  CGFloat row = cocoaRowHeight(), pad = 2., x = pad, side = cocoaPx(1.);
  [look setFrame:NSMakeRect(x, pad + (row - side) / 2., side, side)];
  x += side + pad;
  CGFloat fw = cocoaPx(15.);
  [filter setFrame:NSMakeRect(x, pad, fw, row)];
  x += fw + 2. * pad;
  for(NSButton *c in @[ save, clear, copy, follow ]) {
    CGFloat w = std::ceil([c intrinsicContentSize].width);
    [c setFrame:NSMakeRect(x, pad, w, row)];
    x += w + pad;
  }
  CGFloat top = row + 2. * pad;
  [lines setFrame:NSMakeRect(0, top, b.size.width,
                             std::max((CGFloat)0., b.size.height - top))];
}
@end

@implementation GmshConsoleTarget
- (void)controlTextDidChange:(NSNotification *)n
{
  if(!_w ||
     !_w->said.setFilter(cocoaString([_w->consoleBox->filter stringValue])))
    return;
  // what does not parse is said in red
  [_w->consoleBox->filter setTextColor:_w->said.filterValid() ?
                                         [NSColor controlTextColor] :
                                         [NSColor systemRedColor]];
  _consoleRefill();
}
- (void)copy:(id)sender
{
  if(!_w) return;
  NSPasteboard *board = [NSPasteboard generalPasteboard];
  [board clearContents];
  [board setString:cocoaString(_w->said.shownText())
           forType:NSPasteboardTypeString];
}
- (void)save:(id)sender
{
  if(cocoaSources().saveMessages) cocoaLater(cocoaSources().saveMessages);
}
- (void)clear:(id)sender
{
  if(!_w) return;
  [[_w->messages textStorage]
    setAttributedString:[[NSAttributedString alloc] init]];
  cocoaForgetMessages();
}
- (void)follow:(id)sender
{
  if(!_w) return;
  _w->said.setAutoScroll([_w->consoleBox->follow state] == NSControlStateValueOn);
  if(_w->said.autoScroll()) _consoleFollow();
}
@end

@implementation GmshConsole
// the keys the text does not take are Gmsh's
- (void)keyDown:(NSEvent *)e
{
  if(([e modifierFlags] & NSEventModifierFlagCommand) || !cocoaMainKey(e))
    [super keyDown:e];
}
@end

// the files dropped on the window are opened
@implementation GmshMainView
- (instancetype)initWithFrame:(NSRect)r
{
  self = [super initWithFrame:r];
  [self registerForDraggedTypes:@[ NSPasteboardTypeFileURL ]];
  return self;
}
- (NSDragOperation)draggingEntered:(id<NSDraggingInfo>)info
{
  return NSDragOperationCopy;
}
- (BOOL)performDragOperation:(id<NSDraggingInfo>)info
{
  NSArray *urls = [[info draggingPasteboard]
    readObjectsForClasses:@[ [NSURL class] ]
                  options:@{NSPasteboardURLReadingFileURLsOnlyKey : @YES}];
  std::vector<std::string> paths;
  for(NSURL *u in urls) paths.push_back(cocoaString([u path]));
  std::function<void(const std::vector<std::string> &)> open =
    cocoaHost().filesDropped;
  if(open && paths.size()) cocoaLater([open, paths]() { open(paths); });
  return YES;
}
// the bar along the bottom, the rest above it
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  if(!_w) {
    [super resizeSubviewsWithOldSize:old];
    return;
  }
  NSRect all = [self bounds];
  CGFloat bar = [_w->bar isHidden] ? 0. : _barHeight();
  [_w->bar setFrame:NSMakeRect(0., 0., all.size.width, bar)];
  [_w->side
    setFrame:NSMakeRect(0., bar, all.size.width, all.size.height - bar)];
}
@end

// the tree, and the buttons of the solver under it
@implementation GmshTreeBox
- (BOOL)isFlipped
{
  return YES;
}
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  NSRect all = [self bounds];
  CGFloat rh = cocoaRowHeight(), pad = 4.;
  CGFloat h = [footer isHidden] ? 0. : rh + 2. * pad;
  [tree setFrame:NSMakeRect(0., 0., all.size.width, all.size.height - h)];
  [footer setFrame:NSMakeRect(0., all.size.height - h, all.size.width, h)];
  CGFloat x = pad;
  for(NSView *b in [footer subviews]) {
    CGFloat w = std::ceil([b intrinsicContentSize].width);
    cocoaPlace(b, NSMakeRect(x, pad, w, rh), false);
    x += w + 4.;
  }
}
@end

@implementation GmshBar
- (BOOL)isFlipped
{
  return YES;
}
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  NSRect all = [self bounds];
  CGFloat rh = cocoaRowHeight(), y = std::floor((all.size.height - rh) / 2.);
  CGFloat x = 4.;
  for(NSView *b in [buttons subviews]) {
    NSNumber *wide = objc_getAssociatedObject(b, &_widthKey);
    CGFloat w =
      wide ? [wide doubleValue] : std::ceil([b intrinsicContentSize].width);
    if(NSNumber *gap = objc_getAssociatedObject(b, &_gapKey))
      x += [gap doubleValue];
    cocoaPlace(b, NSMakeRect(x, y, w, rh), false);
    x += w + 1.;
  }
  [buttons setFrame:NSMakeRect(0., 0., x, all.size.height)];
  CGFloat right = all.size.width - 18.;
  if(![progress isHidden]) {
    right -= 200.;
    [progress
      setFrame:NSMakeRect(right, y + std::floor((rh - 12.) / 2.), 200., 12.)];
    CGFloat tw = std::min((CGFloat)160.,
                          std::ceil([progressText intrinsicContentSize].width));
    right -= tw + 6.;
    cocoaPlace(progressText, NSMakeRect(right, y, tw, rh), false);
  }
  cocoaPlace(message,
             NSMakeRect(x + 6., y, std::max((CGFloat)10., right - x - 12.), rh),
             false);
}
@end

@implementation GmshBarTarget
- (void)pressed:(id)sender
{
  std::vector<Ui::BarButton> now = cocoaSources().barButtons();
  if(index >= now.size()) return;
  const Ui::BarButton &one = now[index];
  if(one.menu) {
    cocoaPopupMenu(one.menu());
    return;
  }
  NSEventModifierFlags m = [NSEvent modifierFlags];
  bool reverse = (m & NSEventModifierFlagShift) != 0;
  bool sync =
    (m & (NSEventModifierFlagCommand | NSEventModifierFlagControl)) != 0;
  std::function<void(bool, bool)> what = one.action;
  cocoaLater([what, reverse, sync]() {
    if(what) what(reverse, sync);
    cocoaRefreshBar();
  });
}
- (void)messagePressed:(id)sender
{
  if(cocoaSources().barPressed) cocoaLater(cocoaSources().barPressed);
}
@end

@implementation GmshAppDelegate
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)app
{
  std::function<void()> quit = cocoaHost().quitting;
  if(quit) cocoaLater(quit);
  return NSTerminateCancel;
}
- (void)application:(NSApplication *)app openURLs:(NSArray<NSURL *> *)urls
{
  std::vector<std::string> paths;
  for(NSURL *u in urls)
    if([u isFileURL]) paths.push_back(cocoaString([u path]));
  std::function<void(const std::vector<std::string> &)> open =
    cocoaHost().filesDropped;
  if(open && paths.size()) cocoaLater([open, paths]() { open(paths); });
}
@end

namespace {

  // --- the backend

  class backendCocoa : public Ui::Backend {
  public:
    std::string name() override
    {
      NSOperatingSystemVersion v =
        [[NSProcessInfo processInfo] operatingSystemVersion];
      char said[64];
      snprintf(said, sizeof(said), "Cocoa (macOS %d.%d)", (int)v.majorVersion,
               (int)v.minorVersion);
      return said;
    }

    void setSources(const Sources &sources) override { _sources = sources; }
    const Sources &sources() const { return _sources; }
    void setHost(const Host &host) override { _host = host; }
    const Host &host() const { return _host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(_w) return true;
      // without a session of the window server, nothing can be shown
      CFDictionaryRef session = CGSessionCopyCurrentDictionary();
      if(!session) {
        if(_host.error) _host.error("Could not open a display");
        return false;
      }
      CFRelease(session);
      static bool launched = false;
      if(!launched) {
        launched = true;
        [NSApplication sharedApplication];
        // a process started from a terminal is not yet an application with
        // a menu bar and a place in the Dock
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        _delegate = [[GmshAppDelegate alloc] init];
        [NSApp setDelegate:_delegate];
        [NSApp finishLaunching];
      }
      _build();
      [NSApp activateIgnoringOtherApps:YES];
      cocoaSceneStartTimers();
      return true;
    }

    void destroy() override
    {
      _running = false;
      if(!_w) return;
      cocoaFormsClosingDown();
      cocoaSceneDestroy();
      mainWindow *w = _w;
      _w = nullptr;
      delete w->tree;
      w->tree = nullptr;
      if(w->treePanel) {
        [w->treePanel setDelegate:nil];
        [w->treePanel orderOut:nil];
        w->treePanel = nil;
      }
      w->window->closing = true;
      [w->window setDelegate:nil];
      [w->window close];
      delete w;
      _drain();
    }

    int runLoop() override
    {
      _running = true;
      while(_running && _w) _turn([NSDate distantFuture]);
      return 0;
    }

    void check(bool rateLimited) override
    {
      if(!_w || _locked > 0 || cocoaSceneDrawing()) return;
      double rate = _sources.settings ? _sources.settings().refreshRate : 0.;
      double now = _now();
      if(rateLimited && rate > 0. && now - _lastCheck < 1. / rate) return;
      _lastCheck = now;
      _drain();
    }

    bool ready() override { return _w != nullptr; }

    void wait(double seconds, bool force) override
    {
      if(!_w || cocoaSceneDrawing()) return;
      if(!force && _locked > 0) return;
      if(seconds == 0.) {
        _drain();
        return;
      }
      _turn(seconds > 0. ? [NSDate dateWithTimeIntervalSinceNow:seconds] :
                           [NSDate distantFuture]);
      _drain();
    }

    void lock() override { _locked++; }
    void unlock() override { _locked--; }
    int locked() override { return _locked; }

    void postFromThread(const std::function<void()> &what) override
    {
      // the timer is made on the thread of the interface
      std::function<void()> kept = what;
      dispatch_async(dispatch_get_main_queue(), ^{ cocoaLater(kept); });
    }

    void copyText(const std::string &text) override
    {
      NSPasteboard *board = [NSPasteboard generalPasteboard];
      [board clearContents];
      [board setString:cocoaString(text) forType:NSPasteboardTypeString];
    }

    void beep() override { NSBeep(); }

    // --- messages, the bar

    void addMessage(const std::string &text, int level) override
    {
      if(!_w || !_w->said.add(text, level)) return;
      _consoleLine(text, level);
      if(_w->said.autoScroll()) _consoleFollow();
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(_w) lines = _w->said.texts();
    }

    void refreshBar() override { cocoaRefreshBar(); }

    void optionChanged(const std::string &name) override
    { cocoaFormOptionChanged(name); }

    int numWindows() override { return _w ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(_w && which == 0) [_w->window setTitle:cocoaString(title)];
    }

    // --- the questions that stop everything

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      NSAlert *alert = [[NSAlert alloc] init];
      [alert setMessageText:cocoaString(question)];
      if(hint.size()) [alert setInformativeText:cocoaString(hint)];
      [alert addButtonWithTitle:readOnly ? @"Close" : @"OK"];
      if(!readOnly) [alert addButtonWithTitle:@"Cancel"];
      NSTextField *line = nil;
      NSTextView *text = nil;
      if(readOnly || hint.size() || value.find('\n') != std::string::npos) {
        // several lines: a little editor, or what is shown
        NSScrollView *s = [[NSScrollView alloc]
          initWithFrame:NSMakeRect(0, 0, 500, readOnly ? 300 : 120)];
        [s setHasVerticalScroller:YES];
        [s setBorderType:NSBezelBorder];
        text = [[NSTextView alloc] initWithFrame:[[s contentView] bounds]];
        [text setFont:cocoaFixedFont(0.)];
        [text setEditable:readOnly ? NO : YES];
        [text setRichText:NO];
        [text setAutoresizingMask:NSViewWidthSizable];
        [text setString:cocoaString(value)];
        [s setDocumentView:text];
        [alert setAccessoryView:s];
      }
      else {
        line = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 360, 24)];
        [line setStringValue:cocoaString(value)];
        [alert setAccessoryView:line];
        [[alert window] setInitialFirstResponder:line];
      }
      [alert layout];
      if(line) [[alert window] makeFirstResponder:line];
      bool ok = _modal(alert) == NSAlertFirstButtonReturn && !readOnly;
      if(ok) value = cocoaString(line ? [line stringValue] : [text string]);
      return ok;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one, const std::string &two) override
    {
      NSAlert *alert = [[NSAlert alloc] init];
      [alert setMessageText:cocoaString(question)];
      // Return presses the second, or the only one, as fl_choice() has it,
      // and Escape the first: the first added is the one Return presses
      std::vector<int> order;
      if(one.size()) order.push_back(1);
      if(zero.size()) order.push_back(0);
      if(two.size()) order.push_back(2);
      if(order.empty()) order.push_back(0);
      const std::string *labels[3] = {&zero, &one, &two};
      for(int i : order) {
        NSButton *b =
          [alert addButtonWithTitle:cocoaString(labels[i]->size() ? *labels[i] :
                                                                    "OK")];
        if(i == 0 && order.size() > 1) [b setKeyEquivalent:@"\033"];
      }
      NSInteger said = _modal(alert) - NSAlertFirstButtonReturn;
      if(said >= 0 && said < (NSInteger)order.size())
        return order[(std::size_t)said];
      return 0;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names, int *chosenFormat) override
    {
      NSSavePanel *panel;
      if(mode == Create)
        panel = [NSSavePanel savePanel];
      else {
        NSOpenPanel *open = [NSOpenPanel openPanel];
        [open setCanChooseFiles:YES];
        [open setCanChooseDirectories:NO];
        [open setAllowsMultipleSelection:mode == OpenSeveral ? YES : NO];
        panel = open;
      }
      [panel setMessage:cocoaString(title)];
      [panel setTitle:cocoaString(title)];
      [panel setCanCreateDirectories:YES];
      [panel setShowsHiddenFiles:NO];
      if(names.size() && names[0].size()) {
        NSString *from = [cocoaString(names[0]) stringByExpandingTildeInPath];
        BOOL folder = NO;
        if([[NSFileManager defaultManager] fileExistsAtPath:from
                                                isDirectory:&folder] &&
           folder)
          [panel setDirectoryURL:[NSURL fileURLWithPath:from isDirectory:YES]];
        else {
          NSString *dir = [from stringByDeletingLastPathComponent];
          if([dir length])
            [panel setDirectoryURL:[NSURL fileURLWithPath:dir isDirectory:YES]];
          if(mode == Create)
            [panel setNameFieldStringValue:[from lastPathComponent]];
        }
      }
      // several formats may share an extension: the one picked is said, from
      // a menu under the panel
      std::vector<std::vector<std::string>> allowed;
      for(const auto &f : formats) allowed.push_back(_extensions(f));
      NSPopUpButton *which = nil;
      if(formats.size() > 1) {
        which = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(0, 0, 320, 26)
                                           pullsDown:NO];
        for(const auto &f : formats) {
          std::string said =
            f.name.size() ? f.name + " (" + f.pattern + ")" : f.pattern;
          [[which menu] addItemWithTitle:cocoaString(said)
                                  action:nil
                           keyEquivalent:@""];
        }
        NSTextField *say = [NSTextField labelWithString:@"Format:"];
        NSView *accessory =
          [[NSView alloc] initWithFrame:NSMakeRect(0, 0, 420, 40)];
        [say setFrameOrigin:NSMakePoint(10, 12)];
        [say sizeToFit];
        [which setFrame:NSMakeRect(NSMaxX([say frame]) + 8, 7, 340, 26)];
        [accessory addSubview:say];
        [accessory addSubview:which];
        [panel setAccessoryView:accessory];
        if([panel isKindOfClass:[NSOpenPanel class]])
          [(NSOpenPanel *)panel setAccessoryViewDisclosed:YES];
        __weak NSSavePanel *weak = panel;
        std::vector<std::vector<std::string>> kept = allowed;
        GmshPopUpBlock *target = [[GmshPopUpBlock alloc] init];
        target->chose = ^(NSInteger i) {
          if(weak && i >= 0 && i < (NSInteger)kept.size())
            _allow(weak, kept[(std::size_t)i]);
        };
        [which setTarget:target];
        [which setAction:@selector(chose:)];
        objc_setAssociatedObject(which, &_targetKey, target,
                                 OBJC_ASSOCIATION_RETAIN_NONATOMIC);
      }
      if(allowed.size()) _allow(panel, allowed[0]);
      bool ok = [panel runModal] == NSModalResponseOK;
      if(chosenFormat)
        *chosenFormat =
          which ? (int)[which indexOfSelectedItem] : (formats.size() ? 0 : -1);
      if(!ok) return false;
      std::vector<std::string> out;
      if([panel isKindOfClass:[NSOpenPanel class]])
        for(NSURL *u in [(NSOpenPanel *)panel URLs])
          out.push_back(cocoaString([u path]));
      else if([panel URL])
        out.push_back(cocoaString([[panel URL] path]));
      if(out.empty()) return false;
      names = out;
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      [NSApp setAppearance:[NSAppearance
                             appearanceNamed:dark ? NSAppearanceNameDarkAqua :
                                                    NSAppearanceNameAqua]];
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    { cocoaShowForm(form, show); }
    bool formVisible(const Ui::Form &form) override
    { return cocoaFormVisible(form); }
    std::string formPane(const Ui::Form &form) override
    { return cocoaFormPane(form); }
    void setFormPane(const Ui::Form &form, const std::string &pane) override
    { cocoaSetFormPane(form, pane); }
    void reloadForm(const Ui::Form &form) override { cocoaReloadForm(form); }
    void rebuildForm(const Ui::Form &form) override { cocoaReloadForm(form); }
    void dropForm(const Ui::Form &form) override { cocoaDropForm(form); }

    void refreshMenus() override { cocoaRefreshMenuBar(); }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &) override
    { cocoaPopupMenu(items); }

    void refreshTree(bool rebuild) override
    {
      if(!_w || !_w->tree) return;
      _w->tree->setTree(_sources.tree);
      _w->tree->refresh(rebuild);
      _refreshFooter();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(_w && _w->tree) _w->tree->open(name, open);
    }

    bool treeItemOpen(const std::string &name) override
    { return _w && _w->tree && _w->tree->isOpen(name); }

    void showTree() override { _showTree(true); }

    void setSolverButtonMode(const std::string &, const std::string &) override
    { _refreshFooter(); }

    void showConsole(bool show) override { _showConsole(show); }

    bool consoleVisible() override
    { return _w && ![_w->consoleBox isHidden]; }

    // --- the interface as a whole

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      NSWindow *win = _w->window;
      if(what == "new")
        cocoaSceneNewWindow();
      else if(what == "minimize")
        [([NSApp keyWindow] ?: win) miniaturize:nil];
      else if(what == "zoom")
        [([NSApp keyWindow] ?: win) zoom:nil];
      else if(what == "fullscreen")
        [win toggleFullScreen:nil];
      else if(what == "front") {
        [NSApp activateIgnoringOtherApps:YES];
        [NSApp arrangeInFront:nil];
        [win makeKeyAndOrderFront:nil];
      }
      else if(what == "show_hide_tree")
        _showTree(!_treeShown());
      else if(what == "attach_detach")
        _detachTree(_w->treePanel == nil);
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    void detachTree(bool detached) override { _detachTree(detached); }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      cocoaSceneSize(l.sceneWidth, l.sceneHeight);
      if(!_w->treePanel && ![_w->treeBox isHidden])
        l.treeWidth = (int)[_w->treeBox frame].size.width;
      if(![_w->consoleBox isHidden])
        l.consoleHeight = (int)[_w->consoleBox frame].size.height;
      {
        // from the top left of the screen, as the options say it
        NSRect all = [[NSScreen mainScreen] visibleFrame];
        NSRect f = [_w->window frame];
        l.sceneX = (int)(f.origin.x - all.origin.x);
        l.sceneY = (int)(NSMaxY(all) - NSMaxY(f));
      }
      cocoaFormPosition(l.dialogX, l.dialogY);
      l.treeDetached = _w->treePanel ? 1 : 0;
      if(_w->treePanel) {
        NSRect all = [[NSScreen mainScreen] visibleFrame];
        NSRect f = [_w->treePanel frame];
        l.treeX = (int)(f.origin.x - all.origin.x);
        l.treeY = (int)(NSMaxY(all) - NSMaxY(f));
        l.treeHeight = (int)[[_w->treePanel contentView] frame].size.height;
      }
      return l;
    }

    void setSceneSize(int width, int height) override
    {
      if(!_w) return;
      int sw = 0, sh = 0;
      cocoaSceneSize(sw, sh);
      NSRect frame = [_w->window frame];
      CGFloat dw = width >= 0 ? width - sw : 0.,
              dh = height >= 0 ? height - sh : 0.;
      frame.size.width += dw;
      frame.size.height += dh;
      // the top left corner stays where it is
      frame.origin.y -= dh;
      [_w->window setFrame:frame display:YES];
    }

    void setConsoleFontSize(int size) override { _consoleFont(size); }

    void setTreeWidth(int width) override
    {
      if(!_w || width < 0) return;
      _w->treeWidth = width;
      if(_w->treePanel) {
        NSSize c = [[_w->treePanel contentView] frame].size;
        [_w->treePanel setContentSize:NSMakeSize(width, c.height)];
      }
      else if(![_w->treeBox isHidden])
        [_w->side setPosition:width ofDividerAtIndex:0];
    }

    void enableTooltips(bool on) override {}

  private:
    Sources _sources;
    Host _host;

    void _build()
    {
      const Settings set = _sources.settings();
      if(set.darkScheme) applyColorScheme(true);
      _w = new mainWindow;
      int treeWidth = set.treeWidth > 50 ? set.treeWidth : 300;
      int sceneWidth = set.sceneWidth > 100 ? set.sceneWidth : 700;
      int sceneHeight = set.sceneHeight > 100 ? set.sceneHeight : 600;
      int consoleHeight = set.consoleHeight > 0 ? set.consoleHeight : 150;
      _w->treeWidth = treeWidth;
      _w->consoleHeight = consoleHeight;
      NSRect content =
        NSMakeRect(0, 0, treeWidth + 1 + sceneWidth,
                   sceneHeight + 1 + consoleHeight + _barHeight());
      GmshMainWindow *win = [[GmshMainWindow alloc]
        initWithContentRect:content
                  styleMask:NSWindowStyleMaskTitled |
                            NSWindowStyleMaskClosable |
                            NSWindowStyleMaskMiniaturizable |
                            NSWindowStyleMaskResizable
                    backing:NSBackingStoreBuffered
                      defer:NO];
      win->closing = false;
      _w->window = win;
      [win setReleasedWhenClosed:NO];
      [win setDelegate:win];
      [win setTitle:@"Gmsh"];
      [win setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
      [win setContentMinSize:NSMakeSize(400, 300)];
      GmshMainView *main = [[GmshMainView alloc] initWithFrame:content];
      [win setContentView:main];

      // the tree, and the buttons of the solver under it
      _w->treeBox =
        [[GmshTreeBox alloc] initWithFrame:NSMakeRect(0, 0, treeWidth, 400)];
      _w->tree = new treeCocoa(_sources.tree, false, []() {
        cocoaLater([]() {
          if(_w && _w->tree) _w->tree->refresh(false);
        });
      });
      _w->treeBox->tree = _w->tree->widget();
      _w->treeBox->footer = [[GmshFlippedView alloc] initWithFrame:NSZeroRect];
      [_w->treeBox addSubview:_w->treeBox->tree];
      [_w->treeBox addSubview:_w->treeBox->footer];

      // the scene over the console
      _w->consoleScroll = [[NSScrollView alloc]
        initWithFrame:NSMakeRect(0, 0, sceneWidth, consoleHeight)];
      [_w->consoleScroll setHasVerticalScroller:YES];
      [_w->consoleScroll setHasHorizontalScroller:YES];
      [_w->consoleScroll setAutohidesScrollers:YES];
      _w->messages = [[GmshConsole alloc]
        initWithFrame:NSMakeRect(0, 0, sceneWidth, consoleHeight)];
      [_w->messages setEditable:NO];
      [_w->messages setSelectable:YES];
      [_w->messages setRichText:YES];
      [_w->messages setUsesFindBar:YES];
      [_w->messages setTextContainerInset:NSMakeSize(2., 2.)];
      // one line a message, however long: the console scrolls across
      [_w->messages setHorizontallyResizable:YES];
      [_w->messages setMaxSize:NSMakeSize(1e7, 1e7)];
      [[_w->messages textContainer] setWidthTracksTextView:NO];
      [[_w->messages textContainer] setContainerSize:NSMakeSize(1e7, 1e7)];
      [_w->messages
        setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];
      [_w->consoleScroll setDocumentView:_w->messages];
      _consoleFont(set.consoleFontSize);
      {
        // the bar over the lines
        static GmshConsoleTarget *consoleTarget =
          [[GmshConsoleTarget alloc] init];
        GmshConsoleBox *box = [[GmshConsoleBox alloc]
          initWithFrame:NSMakeRect(0, 0, sceneWidth, consoleHeight)];
        box->look = [NSImageView
          imageViewWithImage:cocoaGlyph(Ui::Console::filterGlyph())];
        box->filter = [NSTextField textFieldWithString:@""];
        [box->filter setDelegate:consoleTarget];
        box->save = [NSButton buttonWithTitle:cocoaString(Ui::Console::saveLabel())
                                       target:consoleTarget
                                       action:@selector(save:)];
        box->clear =
          [NSButton buttonWithTitle:cocoaString(Ui::Console::clearLabel())
                             target:consoleTarget
                             action:@selector(clear:)];
        box->copy =
          [NSButton buttonWithTitle:cocoaString(Ui::Console::copyLabel())
                             target:consoleTarget
                             action:@selector(copy:)];
        box->follow = [NSButton
          checkboxWithTitle:cocoaString(Ui::Console::autoScrollLabel())
                     target:consoleTarget
                     action:@selector(follow:)];
        [box->follow setState:_w->said.autoScroll() ? NSControlStateValueOn :
                                                      NSControlStateValueOff];
        if(set.tooltips) {
          [box->filter setToolTip:cocoaString(Ui::Console::filterTip())];
          [box->save setToolTip:cocoaString(Ui::Console::saveTip())];
          [box->clear setToolTip:cocoaString(Ui::Console::clearTip())];
          [box->copy setToolTip:cocoaString(Ui::Console::copyTip())];
        }
        for(NSButton *b in @[ box->save, box->clear, box->copy ]) {
          [b setBezelStyle:NSBezelStyleRounded];
          [b setControlSize:NSControlSizeSmall];
        }
        box->lines = _w->consoleScroll;
        for(NSView *v in @[ box->look, box->filter, box->save, box->clear,
                            box->copy, box->follow, box->lines ])
          [box addSubview:v];
        _w->consoleBox = box;
      }

      _w->split =
        [[NSSplitView alloc] initWithFrame:NSMakeRect(0, 0, sceneWidth, 400)];
      [_w->split setVertical:NO];
      [_w->split setDividerStyle:NSSplitViewDividerStyleThin];
      [_w->split addSubview:cocoaSceneWidget()];
      [_w->split addSubview:_w->consoleBox];
      [_w->split setHoldingPriority:NSLayoutPriorityDefaultLow
                  forSubviewAtIndex:0];
      [_w->split setHoldingPriority:NSLayoutPriorityDefaultHigh
                  forSubviewAtIndex:1];

      _w->side = [[NSSplitView alloc] initWithFrame:NSMakeRect(0, 0, 700, 400)];
      [_w->side setVertical:YES];
      [_w->side setDividerStyle:NSSplitViewDividerStyleThin];
      [_w->side addSubview:_w->treeBox];
      [_w->side addSubview:_w->split];
      [_w->side setHoldingPriority:NSLayoutPriorityDefaultHigh
                 forSubviewAtIndex:0];
      [_w->side setHoldingPriority:NSLayoutPriorityDefaultLow
                 forSubviewAtIndex:1];
      [main addSubview:_w->side];

      // the bar: the buttons, the message one presses to show the messages,
      // the progress of what runs
      GmshBar *bar = (GmshBar *)cocoaMakeBar();
      _w->bar = bar;
      [main addSubview:bar];

      cocoaRefreshMenuBar();
      _refreshFooter();
      cocoaRefreshBar();

      [main resizeSubviewsWithOldSize:NSZeroSize];
      [_w->side adjustSubviews];
      [_w->split adjustSubviews];
      [_w->side setPosition:treeWidth ofDividerAtIndex:0];
      [_w->split setPosition:[_w->split bounds].size.height - consoleHeight -
                             [_w->split dividerThickness]
            ofDividerAtIndex:0];
      [_w->treeBox resizeSubviewsWithOldSize:NSZeroSize];
      if(!set.showModuleMenu) _showTree(false);

      if(set.sceneX > 0 || set.sceneY > 0) {
        // from the top left of the screen, as the other interfaces have it
        NSRect all = [[NSScreen mainScreen] visibleFrame];
        [win setFrameTopLeftPoint:NSMakePoint(all.origin.x + set.sceneX,
                                              NSMaxY(all) - set.sceneY)];
      }
      else
        [win center];
      [win makeKeyAndOrderFront:nil];
      [win makeFirstResponder:cocoaSceneWidget().subviews.firstObject];
      if(set.detachedTree) _detachTree(true);
    }
  };

  backendCocoa *_the = nullptr;

} // namespace

NSWindow *cocoaMainWindow() { return _w ? _w->window : nil; }

bool cocoaButtonDown() { return [NSEvent pressedMouseButtons] != 0; }

namespace {

  // the bars made, forgotten with their window
  NSHashTable *_bars()
  {
    static NSHashTable *bars = [NSHashTable weakObjectsHashTable];
    return bars;
  }

  void _refreshBar(GmshBar *barView, const std::vector<Ui::BarButton> &bar)
  {
    std::string shape = Ui::signature(bar);
    NSView *row = barView->buttons;
    bool tips = cocoaSources().settings().tooltips;
    if(shape != barView->built) {
      barView->built = shape;
      for(NSView *v in [[row subviews] copy]) [v removeFromSuperview];
      for(std::size_t i = 0; i < bar.size(); i++) {
        NSButton *b = [NSButton buttonWithTitle:cocoaString(bar[i].label)
                                         target:nil
                                         action:nil];
        [b setBezelStyle:NSBezelStyleRounded];
        [b setControlSize:NSControlSizeSmall];
        [b setFont:[NSFont systemFontOfSize:[NSFont smallSystemFontSize]]];
        GmshBarTarget *t = [[GmshBarTarget alloc] init];
        t->index = i;
        [b setTarget:t];
        [b setAction:@selector(pressed:)];
        // a control does not keep its target
        objc_setAssociatedObject(b, &_targetKey, t,
                                 OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        if(bar[i].gapBefore && i)
          objc_setAssociatedObject(b, &_gapKey, @(cocoaPx(.6)),
                                   OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        [row addSubview:b];
      }
    }
    NSArray *made = [row subviews];
    for(std::size_t i = 0; i < bar.size() && i < [made count]; i++) {
      NSButton *b = made[i];
      const Ui::BarButton &one = bar[i];
      bool on = one.on && one.on();
      std::string label = (on && one.labelOn.size()) ? one.labelOn : one.label;
      std::string glyph = (on && one.glyphOn.size()) ? one.glyphOn : one.glyph;
      cocoaButtonShows(b, label, glyph);
      [b setEnabled:(one.enabled ? one.enabled() : true) ? YES : NO];
      if(one.tooltip.size() && tips) [b setToolTip:cocoaString(one.tooltip)];
      if(one.alert && one.alert()) {
        [b setBezelColor:[NSColor systemRedColor]];
        [b setFont:[NSFont boldSystemFontOfSize:[NSFont smallSystemFontSize]]];
      }
      else if(on && one.onColour) {
        Ui::Colour c = one.onColour();
        [b setBezelColor:[NSColor colorWithSRGBRed:c.r / 255.
                                             green:c.g / 255.
                                              blue:c.b / 255.
                                             alpha:1.]];
        [b setFont:[NSFont systemFontOfSize:[NSFont smallSystemFontSize]]];
      }
      else {
        [b setBezelColor:nil];
        [b setFont:on ?
                     [NSFont boldSystemFontOfSize:[NSFont smallSystemFontSize]] :
                     [NSFont systemFontOfSize:[NSFont smallSystemFontSize]]];
      }
      CGFloat w = std::ceil([b intrinsicContentSize].width);
      if(one.widthEm > 0.) w = std::max(w, cocoaPx(one.widthEm));
      objc_setAssociatedObject(b, &_widthKey, @(w),
                               OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    if(cocoaSources().barMessage) {
      Ui::BarMessage m = cocoaSources().barMessage();
      NSColor *ink = m.weight == Ui::MessageError ? [NSColor systemRedColor] :
                     m.weight == Ui::MessageWarning ?
                                                    [NSColor systemOrangeColor] :
                                                    [NSColor labelColor];
      NSMutableParagraphStyle *p = [[NSMutableParagraphStyle alloc] init];
      [p setLineBreakMode:NSLineBreakByTruncatingTail];
      [barView->message
        setAttributedTitle:[[NSAttributedString alloc]
                             initWithString:cocoaString(m.text)
                                 attributes:@{
                                   NSForegroundColorAttributeName : ink,
                                   NSFontAttributeName : cocoaFont(),
                                   NSParagraphStyleAttributeName : p
                                 }]];
      // the progress of what has finished stays said, at nought or at the end
      bool going = m.running && m.fraction > 0. && m.fraction < 1.;
      [barView->progress setHidden:!going];
      [barView->progressText setHidden:!going];
      if(going) {
        [barView->progress setDoubleValue:1000. * m.fraction];
        [barView->progressText setStringValue:cocoaString(m.progressText)];
      }
    }
    if(cocoaSources().barTooltip && tips)
      [barView->message setToolTip:cocoaString(cocoaSources().barTooltip())];
    [barView resizeSubviewsWithOldSize:NSZeroSize];
  }

} // namespace

CGFloat cocoaBarHeight() { return _barHeight(); }

NSView *cocoaMakeBar()
{
  GmshBar *bar = [[GmshBar alloc] initWithFrame:NSZeroRect];
  bar->buttons = [[GmshFlippedView alloc] initWithFrame:NSZeroRect];
  [bar addSubview:bar->buttons];
  bar->message = [NSButton buttonWithTitle:@"" target:nil action:nil];
  [bar->message setBordered:NO];
  [bar->message setAlignment:NSTextAlignmentLeft];
  [[bar->message cell] setLineBreakMode:NSLineBreakByTruncatingTail];
  static GmshBarTarget *messageTarget = [[GmshBarTarget alloc] init];
  [bar->message setTarget:messageTarget];
  [bar->message setAction:@selector(messagePressed:)];
  [bar addSubview:bar->message];
  bar->progressText = [NSTextField labelWithString:@""];
  [bar->progressText setFont:[NSFont systemFontOfSize:cocoaEm() - 2.]];
  [bar->progressText setHidden:YES];
  [bar addSubview:bar->progressText];
  bar->progress = [[NSProgressIndicator alloc] initWithFrame:NSZeroRect];
  [bar->progress setStyle:NSProgressIndicatorStyleBar];
  [bar->progress setIndeterminate:NO];
  [bar->progress setMinValue:0.];
  [bar->progress setMaxValue:1000.];
  [bar->progress setHidden:YES];
  [bar addSubview:bar->progress];
  [_bars() addObject:bar];
  if(cocoaSources().barButtons) _refreshBar(bar, cocoaSources().barButtons());
  return bar;
}

void cocoaRefreshBar()
{
  if(!_w || !cocoaSources().barButtons) return;
  std::vector<Ui::BarButton> bar = cocoaSources().barButtons();
  for(GmshBar *b in [[_bars() allObjects] copy]) _refreshBar(b, bar);
}

bool cocoaMainKey(NSEvent *e)
{
  int key = 0;
  unsigned mods = 0;
  if(!cocoaUiKey(e, key, mods)) return false;
  if(key == Ui::KeyEscape && _w && _w->fullscreen) {
    [_w->window toggleFullScreen:nil];
    return true;
  }
  if(!cocoaSources().keys) return false;
  bool taken = false;
  for(const Ui::KeyBinding &k : cocoaSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    taken = true;
    if(k.action) cocoaLater(k.action);
    if(k.spent) break;
  }
  if(taken) cocoaLater([]() { cocoaRefreshBar(); });
  return taken;
}

const Ui::Backend::Sources &cocoaSources()
{
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

const Ui::Backend::Host &cocoaHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

// made once
namespace {
  struct offeringCocoa {
    offeringCocoa()
    {
      Ui::offer("cocoa", []() -> Ui::Backend * {
        if(!_the) _the = new backendCocoa();
        return _the;
      });
    }
  };
  offeringCocoa _offeringCocoa;
} // namespace
