// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Cocoa interface, see GuiPanes.h: each view in an
// NSOpenGLView of its own, their contexts sharing what they can; the views of
// the main window split with NSSplitView, a new graphic window a window
// holding one more

#include "GmshConfig.h"

#define GL_SILENCE_DEPRECATION

#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#include "cocoaCommon.h"

#include "Gui.h"
#include "GuiPanes.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"

#import <OpenGL/OpenGL.h>

@class GmshScenePane;

namespace {
  // the C++ side of a pane: what GuiPanes knows, and the view that shows it
  struct pane : public GuiPanes::Pane {
    GmshScenePane *ns = nil;
    // the window of a graphic window of its own
    NSWindow *top = nil;
  };
} // namespace

@interface GmshScenePane : NSOpenGLView {
@public
  pane *owner;
  bool ready, picking;
}
- (instancetype)initSharing:(NSOpenGLContext *)shared;
- (bool)prepare;
- (double)factor;
@end

namespace {

  NSView *_root = nil;

  GuiPanes &_all() { return GuiPanes::instance(); }

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  NSOpenGLPixelFormat *_format()
  {
    // the scene is drawn with the shader pipeline: OpenGL 3.2 and up
    NSOpenGLPixelFormatAttribute attributes[] = {NSOpenGLPFAOpenGLProfile,
                                                 NSOpenGLProfileVersion3_2Core,
                                                 NSOpenGLPFADoubleBuffer,
                                                 NSOpenGLPFAAccelerated,
                                                 NSOpenGLPFAColorSize,
                                                 24,
                                                 NSOpenGLPFAAlphaSize,
                                                 8,
                                                 NSOpenGLPFADepthSize,
                                                 24,
                                                 NSOpenGLPFAStencilSize,
                                                 8,
                                                 0};
    return [[NSOpenGLPixelFormat alloc] initWithAttributes:attributes];
  }

} // namespace

@implementation GmshScenePane

- (instancetype)initSharing:(NSOpenGLContext *)shared
{
  self = [super initWithFrame:NSMakeRect(0, 0, 400, 300) pixelFormat:_format()];
  if(!self) return nil;
  owner = nullptr;
  ready = picking = false;
  // the objects the contexts can share, they share
  if(shared) {
    NSOpenGLContext *mine =
      [[NSOpenGLContext alloc] initWithFormat:[self pixelFormat]
                                 shareContext:shared];
    if(mine) [self setOpenGLContext:mine];
  }
  [self setWantsBestResolutionOpenGLSurface:YES];
  [self setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];
  return self;
}

- (BOOL)acceptsFirstResponder
{
  return YES;
}
- (BOOL)acceptsFirstMouse:(NSEvent *)e
{
  return YES;
}
- (BOOL)isOpaque
{
  return YES;
}

- (double)factor
{
  return [self convertSizeToBacking:NSMakeSize(1., 1.)].width;
}

// the context current and made the window's; false before it has one
- (bool)prepare
{
  if(!ready) return false;
  [[self openGLContext] makeCurrentContext];
  glShader::setWindowFramebuffer(0);
  return true;
}

- (void)prepareOpenGL
{
  [super prepareOpenGL];
  ready = true;
  GLint vsync = 1;
  [[self openGLContext] setValues:&vsync
                     forParameter:NSOpenGLContextParameterSwapInterval];
  // what is kept per context is this one's before anything is built in it
  glShader::setContext(CGLGetCurrentContext());
  glShader::setWindowFramebuffer(0);
  if(owner) owner->view->contextChanged();
}

- (void)drawRect:(NSRect)dirty
{
  if(!owner || ![self prepare]) return;
  _all().draw(owner);
  [[self openGLContext] flushBuffer];
}

- (void)reshape
{
  [super reshape];
  [self setNeedsDisplay:YES];
}

- (void)viewDidChangeBackingProperties
{
  [super viewDidChangeBackingProperties];
  [self setNeedsDisplay:YES];
}

- (void)modifiers:(NSEventModifierFlags)m
{
  // as FLTK has it on macOS: Control is Control, Command the fourth one
  owner->modifiers((m & NSEventModifierFlagShift) != 0,
                   (m & NSEventModifierFlagControl) != 0,
                   (m & NSEventModifierFlagOption) != 0,
                   (m & NSEventModifierFlagCommand) != 0);
}

// where the event is, y down
- (NSPoint)at:(NSEvent *)e
{
  NSPoint p = [self convertPoint:[e locationInWindow] fromView:nil];
  return NSMakePoint(p.x, [self bounds].size.height - p.y);
}

- (void)updateTrackingAreas
{
  for(NSTrackingArea *t in [self trackingAreas]) [self removeTrackingArea:t];
  [self addTrackingArea:[[NSTrackingArea alloc]
                          initWithRect:NSZeroRect
                               options:NSTrackingMouseMoved |
                                       NSTrackingMouseEnteredAndExited |
                                       NSTrackingActiveInKeyWindow |
                                       NSTrackingInVisibleRect
                                 owner:self
                              userInfo:nil]];
  [super updateTrackingAreas];
}

- (void)resetCursorRects
{
  [self addCursorRect:[self bounds]
               cursor:picking ? [NSCursor pointingHandCursor] :
                                [NSCursor arrowCursor]];
}

- (void)moveTo:(NSEvent *)e
{
  if(!owner) return;
  [self modifiers:[e modifierFlags]];
  NSPoint p = [self at:e];
  owner->moved(p.x, p.y);
}

- (void)press:(NSEvent *)e button:(int)b
{
  if(!owner) return;
  [[self window] makeFirstResponder:self];
  [self modifiers:[e modifierFlags]];
  NSPoint p = [self at:e];
  // a double click is two presses: the scene counts them itself
  owner->pressed(b, p.x, p.y, [NSEvent doubleClickInterval]);
}

- (void)releaseButton:(NSEvent *)e button:(int)b
{
  if(!owner) return;
  [self modifiers:[e modifierFlags]];
  NSPoint p = [self at:e];
  owner->released(b, p.x, p.y);
}

- (void)mouseMoved:(NSEvent *)e
{
  [self moveTo:e];
}
- (void)mouseDragged:(NSEvent *)e
{
  [self moveTo:e];
}
- (void)rightMouseDragged:(NSEvent *)e
{
  [self moveTo:e];
}
- (void)otherMouseDragged:(NSEvent *)e
{
  [self moveTo:e];
}
- (void)mouseDown:(NSEvent *)e
{
  [self press:e button:0];
}
- (void)rightMouseDown:(NSEvent *)e
{
  [self press:e button:1];
}
- (void)otherMouseDown:(NSEvent *)e
{
  [self press:e button:2];
}
- (void)mouseUp:(NSEvent *)e
{
  [self releaseButton:e button:0];
}
- (void)rightMouseUp:(NSEvent *)e
{
  [self releaseButton:e button:1];
}
- (void)otherMouseUp:(NSEvent *)e
{
  [self releaseButton:e button:2];
}

- (void)scrollWheel:(NSEvent *)e
{
  if(!owner) return;
  [self modifiers:[e modifierFlags]];
  double dy = [e scrollingDeltaY];
  // a trackpad gives points, a wheel lines
  if([e hasPreciseScrollingDeltas]) dy /= 10.;
  NSPoint p = [self at:e];
  owner->wheel(dy, p.x, p.y);
}

- (void)mouseEntered:(NSEvent *)e
{
  if(owner) _all().setCurrent(owner);
}

- (void)mouseExited:(NSEvent *)e
{
  if(owner) owner->left();
}

// Option and the arrows step through what is stacked under the pointer; the
// other keys go on to the window
- (void)keyDown:(NSEvent *)e
{
  NSString *c = [e charactersIgnoringModifiers];
  unichar k = [c length] ? [c characterAtIndex:0] : 0;
  if(owner && ([e modifierFlags] & NSEventModifierFlagOption) &&
     (k == NSUpArrowFunctionKey || k == NSDownArrowFunctionKey) &&
     CTX::instance()->mouseSelection && !owner->view->lasso() &&
     !owner->view->addPointMode) {
    if([self prepare])
      owner->view->stepPick(k == NSDownArrowFunctionKey ? 1 : -1);
    return;
  }
  cocoaMainKey(e);
}

@end

// a window of its own: the keys the view does not take are Gmsh's, and its
// view goes with it
@interface GmshPaneWindow : NSWindow <NSWindowDelegate> {
@public
  pane *held;
}
@end

namespace {
  void _destroy(pane *p)
  {
    [p->ns removeFromSuperview];
    p->ns->owner = nullptr;
    delete p;
  }
} // namespace

@implementation GmshPaneWindow
- (void)keyDown:(NSEvent *)e
{
  if(!cocoaMainKey(e)) [super keyDown:e];
}
- (void)windowWillClose:(NSNotification *)n
{
  pane *p = held;
  held = nullptr;
  if(!p) return;
  p->top = nil;
  _all().dropped(p);
  _destroy(p);
}
@end

namespace {

  // the splits of the main window: a divider as thin as it can be
  NSSplitView *_split(bool across)
  {
    NSSplitView *s =
      [[NSSplitView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
    [s setVertical:across ? YES : NO];
    [s setDividerStyle:NSSplitViewDividerStyleThin];
    [s setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];
    return s;
  }

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    t.makePane = [](GuiPanes::Pane *) -> GuiPanes::Pane * {
      pane *p = new pane;
      const std::vector<GuiPanes::Pane *> &all = _all().panes();
      NSOpenGLContext *shared =
        all.empty() ? nil : [_pane(all[0])->ns openGLContext];
      p->ns = [[GmshScenePane alloc] initSharing:shared];
      p->ns->owner = p;
      return p;
    };
    t.redraw = [](GuiPanes::Pane *p) { [_pane(p)->ns setNeedsDisplay:YES]; };
    t.prepare = [](GuiPanes::Pane *p) { return [_pane(p)->ns prepare]; };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      NSSize s = [_pane(p)->ns bounds].size;
      w = (int)s.width;
      h = (int)s.height;
      f = [_pane(p)->ns factor];
    };
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      // the top left corner, in the window counted upwards
      GmshScenePane *v = _pane(p)->ns;
      NSPoint o = [v convertPoint:NSMakePoint(0, [v bounds].size.height)
                           toView:nil];
      x = (int)o.x;
      y = (int)-o.y;
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      if(![_pane(p)->ns prepare]) return;
      _all().draw(p);
      [[_pane(p)->ns openGLContext] flushBuffer];
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      GmshScenePane *w = _pane(was)->ns;
      NSView *parent = [w superview];
      NSRect room = [w frame];
      NSSplitView *split = _split(how == 'h');
      [split setFrame:room];
      if([parent isKindOfClass:[NSSplitView class]]) {
        // in the place the view had among the others
        NSSplitView *up = (NSSplitView *)parent;
        NSUInteger at = [[up arrangedSubviews] indexOfObject:w];
        [up removeArrangedSubview:w];
        [w removeFromSuperview];
        [up insertArrangedSubview:split atIndex:at];
      }
      else {
        [w removeFromSuperview];
        [parent addSubview:split];
      }
      [split addArrangedSubview:w];
      [split addArrangedSubview:_pane(fresh)->ns];
      [split adjustSubviews];
      CGFloat size = how == 'h' ? room.size.width : room.size.height;
      [split setPosition:std::floor(size * ratio) ofDividerAtIndex:0];
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      GmshScenePane *k = _pane(keep)->ns;
      [k removeFromSuperview];
      for(GuiPanes::Pane *p : gone) _destroy(_pane(p));
      for(NSView *v in [[_root subviews] copy]) [v removeFromSuperview];
      [k setFrame:[_root bounds]];
      [_root addSubview:k];
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      GmshPaneWindow *w = [[GmshPaneWindow alloc]
        initWithContentRect:NSMakeRect(0, 0, 600, 500)
                  styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                            NSWindowStyleMaskMiniaturizable |
                            NSWindowStyleMaskResizable
                    backing:NSBackingStoreBuffered
                      defer:NO];
      [w setReleasedWhenClosed:NO];
      [w setDelegate:w];
      w->held = _pane(fresh);
      _pane(fresh)->top = w;
      [w setTitle:[NSString stringWithFormat:@"Gmsh - Graphic window %d",
                                             (int)_all().panes().size()]];
      [_pane(fresh)->ns setFrame:[[w contentView] bounds]];
      [[w contentView] addSubview:_pane(fresh)->ns];
      [w cascadeTopLeftFromPoint:NSMakePoint(
                                   NSMinX([cocoaMainWindow() frame]) + 40.,
                                   NSMaxY([cocoaMainWindow() frame]) - 40.)];
      [w makeKeyAndOrderFront:nil];
    };
    t.cursor = [](bool picking) {
      for(GuiPanes::Pane *q : _all().panes()) {
        GmshScenePane *p = _pane(q)->ns;
        if(p->picking == picking) continue;
        p->picking = picking;
        [[p window] invalidateCursorRectsForView:p];
      }
    };
    t.clipboard = [](int w, int h, const std::vector<unsigned char> &rgba) {
      NSBitmapImageRep *image =
        [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:nullptr
                                                pixelsWide:w
                                                pixelsHigh:h
                                             bitsPerSample:8
                                           samplesPerPixel:4
                                                  hasAlpha:YES
                                                  isPlanar:NO
                                            colorSpaceName:NSDeviceRGBColorSpace
                                               bytesPerRow:w * 4
                                              bitsPerPixel:32];
      // OpenGL counts the rows from the bottom
      unsigned char *to = [image bitmapData];
      for(int row = 0; row < h; row++) {
        std::memcpy(to + (std::size_t)row * w * 4,
                    rgba.data() + (std::size_t)(h - 1 - row) * w * 4,
                    (std::size_t)w * 4);
        for(int x = 0; x < w; x++) to[((std::size_t)row * w + x) * 4 + 3] = 255;
      }
      NSPasteboard *board = [NSPasteboard generalPasteboard];
      [board clearContents];
      [board setData:[image representationUsingType:NSBitmapImageFileTypePNG
                                         properties:@{}]
             forType:NSPasteboardTypePNG];
      [board setData:[image TIFFRepresentation] forType:NSPasteboardTypeTIFF];
    };
    t.later = [](double seconds, std::function<void()> what) {
      NSTimer *timer = [NSTimer timerWithTimeInterval:std::max(0., seconds)
                                              repeats:NO
                                                block:^(NSTimer *) {
                                                  if(what) what();
                                                }];
      [[NSRunLoop mainRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    };
    t.buttonDown = []() { return cocoaButtonDown(); };
    t.context = []() -> void * { return (void *)CGLGetCurrentContext(); };
    t.screen = [](int &height, float &scale) {
      NSScreen *s = [cocoaMainWindow() screen] ?: [NSScreen mainScreen];
      height = 0;
      scale = 1.f;
      if(!s) return;
      scale = (float)[s backingScaleFactor];
      height = (int)([s frame].size.height * scale);
    };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("cocoa"); }
  };
  offering _offering;

} // namespace

NSView *cocoaSceneWidget()
{
  if(_root) return _root;
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = [[NSView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
  [_root setAutoresizesSubviews:YES];
  GmshScenePane *first = _pane(_all().start(_toolkit()))->ns;
  [first setFrame:[_root bounds]];
  [_root addSubview:first];
  return _root;
}

void cocoaSceneRedraw() { _all().redrawAll(); }

bool cocoaSceneDrawing() { return _all().drawing(); }

void cocoaSceneSize(int &width, int &height)
{
  width = _root ? (int)[_root bounds].size.width : 0;
  height = _root ? (int)[_root bounds].size.height : 0;
}

void cocoaSceneNewWindow() { _all().newWindow(); }

void cocoaSceneDestroy()
{
  std::vector<GuiPanes::Pane *> panes = _all().panes();
  _all().stop();
  for(GuiPanes::Pane *q : panes) {
    pane *p = _pane(q);
    if(p->top) {
      GmshPaneWindow *w = (GmshPaneWindow *)p->top;
      w->held = nullptr;
      [w setDelegate:nil];
      [w close];
    }
    p->ns->owner = nullptr;
    delete p;
  }
  // the tiled views are in the main window, which goes with them
  _root = nil;
}

void cocoaSceneStartTimers() { _all().startTimers(); }

