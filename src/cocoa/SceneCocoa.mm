// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Cocoa interface, see GuiScene.h: each view in an
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

#include "glApi.h"
#include "cocoaCommon.h"

#include "Gui.h"
#include "GuiScene.h"
#include "GuiActions.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

#import <OpenGL/OpenGL.h>

@interface GmshScenePane : NSOpenGLView {
@public
  sceneView *view;
  // a graphic window of its own, not tiled in the main one
  NSWindow *window;
  paneInput input;
  double lastX, lastY, lastPress;
  bool moved, ready, picking;
}
- (instancetype)initFrom:(GmshScenePane *)from;
- (bool)prepare;
- (void)place;
- (void)drawNow;
- (double)factor;
@end

namespace {

  std::vector<GmshScenePane *> _panes;
  GmshScenePane *_current = nil;
  NSView *_root = nil;
  int _captureW = 0, _captureH = 0;
  bool _animating = false, _drawing = false;
  NSTimer *_animation = nil, *_gamepad = nil;

  std::vector<GVertex *> _vertices;
  std::vector<GEdge *> _edges;
  std::vector<GFace *> _faces;
  std::vector<GRegion *> _regions;
  std::vector<MElement *> _elements;
  std::vector<SPoint2> _points;
  std::vector<PView *> _views;

  void _clearSelected()
  {
    _vertices.clear();
    _edges.clear();
    _faces.clear();
    _regions.clear();
    _elements.clear();
    _points.clear();
    _views.clear();
  }

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

  // what the scene leaves set is put back, for the next pane drawn in a
  // context that shares its objects
  void _putBack()
  {
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glPixelStorei(GL_PACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    if(glApi::BindBuffer) {
      glApi::BindBuffer(0x88EB /* GL_PIXEL_PACK_BUFFER */, 0);
      glApi::BindBuffer(0x88EC /* GL_PIXEL_UNPACK_BUFFER */, 0);
      glApi::BindBuffer(0x8892 /* GL_ARRAY_BUFFER */, 0);
    }
    if(glApi::BindVertexArray) glApi::BindVertexArray(0);
    if(glApi::UseProgram) glApi::UseProgram(0);
  }

  GmshScenePane *_paneOf(sceneView *view)
  {
    for(GmshScenePane *p : _panes)
      if(p->view == view) return p;
    return nil;
  }

  void _forget(GmshScenePane *p)
  {
    auto it = std::find(_panes.begin(), _panes.end(), p);
    if(it != _panes.end()) _panes.erase(it);
    if(_current == p) _current = _panes.empty() ? nil : _panes[0];
  }

  void _redrawAll()
  {
    for(GmshScenePane *p : _panes) [p setNeedsDisplay:YES];
  }

} // namespace

@implementation GmshScenePane

- (instancetype)initFrom:(GmshScenePane *)from
{
  self = [super initWithFrame:NSMakeRect(0, 0, 400, 300) pixelFormat:_format()];
  if(!self) return nil;
  view = new sceneView();
  window = nil;
  lastX = lastY = lastPress = 0.;
  moved = ready = picking = false;
  if(from)
    view->getDrawContext()->copyViewAttributes(from->view->getDrawContext());
  // the objects the contexts can share, they share
  if(!_panes.empty()) {
    NSOpenGLContext *shared =
      [[NSOpenGLContext alloc] initWithFormat:[self pixelFormat]
                                 shareContext:[_panes[0] openGLContext]];
    if(shared) [self setOpenGLContext:shared];
  }
  [self setWantsBestResolutionOpenGLSurface:YES];
  [self setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];
  return self;
}

- (void)dealloc
{
  delete view;
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

- (void)place
{
  NSSize s = [self bounds].size;
  view->setRect(0, 0, (int)s.width, (int)s.height);
  view->setOrigin(0., 0., (int)s.height, [self factor]);
}

- (void)drawNow
{
  NSSize s = [self bounds].size;
  int w = (int)s.width, h = (int)s.height;
  if(w < 1 || h < 1) return;
  double f = [self factor];
  if(_captureW > 0 && _captureH > 0) {
    // in the bottom-left corner, where PixelBuffer::fill() reads, the rest
    // cleared
    int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, (int)(w * f + .5), (int)(h * f + .5));
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    view->setRect(0, h - lh, lw, lh);
    view->setOrigin(0., 0., h, f);
    view->draw(f, h);
    [self place];
  }
  else {
    [self place];
    view->draw(f, h);
  }
  glShader::release();
  _putBack();
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
  view->contextChanged();
}

- (void)drawRect:(NSRect)dirty
{
  if(![self prepare]) return;
  _drawing = true;
  [self drawNow];
  _drawing = false;
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

- (void)handle
{
  if(![self prepare]) return;
  [self place];
  view->handleMouse(input);
  for(int b = 0; b < 3; b++) input.clicked[b] = input.released[b] = false;
  input.doubleClicked = false;
  input.wheel = 0.;
  input.dx = input.dy = 0.;
  // the view asks for the draws it needs: one it did not ask for would start
  // the studio frames over
}

- (void)modifiers:(NSEventModifierFlags)m
{
  // as FLTK has it on macOS: Control is Control, Command the fourth one
  input.shift = (m & NSEventModifierFlagShift) != 0;
  input.ctrl = (m & NSEventModifierFlagControl) != 0;
  input.alt = (m & NSEventModifierFlagOption) != 0;
  input.super = (m & NSEventModifierFlagCommand) != 0;
}

- (void)at:(NSEvent *)e
{
  NSPoint p = [self convertPoint:[e locationInWindow] fromView:nil];
  double x = p.x, y = [self bounds].size.height - p.y;
  input.dx = moved ? x - lastX : 0.;
  input.dy = moved ? y - lastY : 0.;
  lastX = input.x = x;
  lastY = input.y = y;
  moved = true;
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
  [self modifiers:[e modifierFlags]];
  [self at:e];
  [self handle];
}

- (void)press:(NSEvent *)e button:(int)b
{
  _current = self;
  [[self window] makeFirstResponder:self];
  [self modifiers:[e modifierFlags]];
  [self at:e];
  input.clicked[b] = input.dragging[b] = true;
  // a double click is two presses: the scene counts them itself
  double now = TimeOfDay();
  input.doubleClicked =
    b == 0 && now - lastPress < [NSEvent doubleClickInterval];
  if(b == 0) lastPress = input.doubleClicked ? 0. : now;
  [self handle];
}

- (void)releaseButton:(NSEvent *)e button:(int)b
{
  [self modifiers:[e modifierFlags]];
  [self at:e];
  input.released[b] = true;
  input.dragging[b] = false;
  [self handle];
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
  [self modifiers:[e modifierFlags]];
  double dy = [e scrollingDeltaY];
  // a trackpad gives points, a wheel lines
  if([e hasPreciseScrollingDeltas]) dy /= 10.;
  if(dy == 0.) return;
  input.wheel = dy;
  [self handle];
}

- (void)mouseEntered:(NSEvent *)e
{
  _current = self;
}

- (void)mouseExited:(NSEvent *)e
{
  moved = false;
  view->pointerLeft();
}

// Option and the arrows step through what is stacked under the pointer; the
// other keys go on to the window
- (void)keyDown:(NSEvent *)e
{
  NSString *c = [e charactersIgnoringModifiers];
  unichar k = [c length] ? [c characterAtIndex:0] : 0;
  if(([e modifierFlags] & NSEventModifierFlagOption) &&
     (k == NSUpArrowFunctionKey || k == NSDownArrowFunctionKey) &&
     CTX::instance()->mouseSelection && !view->lasso() && !view->addPointMode) {
    if([self prepare]) view->stepPick(k == NSDownArrowFunctionKey ? 1 : -1);
    return;
  }
  cocoaMainKey(e);
}

@end

// a window of its own: the keys the view does not take are Gmsh's, and its
// view goes with it
@interface GmshPaneWindow : NSWindow <NSWindowDelegate> {
@public
  GmshScenePane *held;
}
@end

@implementation GmshPaneWindow
- (void)keyDown:(NSEvent *)e
{
  if(!cocoaMainKey(e)) [super keyDown:e];
}
- (void)windowWillClose:(NSNotification *)n
{
  GmshScenePane *p = held;
  held = nil;
  if(p) _forget(p);
}
@end

namespace {

  GmshScenePane *_newPane(GmshScenePane *from)
  {
    GmshScenePane *p = [[GmshScenePane alloc] initFrom:from];
    _panes.push_back(p);
    return p;
  }

  void _setHost()
  {
    Scene::Host held;
    held.redraw = []() { _redrawAll(); };
    held.redrawView = [](sceneView *view) {
      if(GmshScenePane *p = _paneOf(view)) [p setNeedsDisplay:YES];
    };
    held.check = [](bool rateLimited) { Gui::instance().check(rateLimited); };
    held.wait = [](double seconds, bool force) {
      if(seconds < 0.)
        Gui::instance().wait(force);
      else
        Gui::instance().wait(seconds, force);
    };
    held.drawCurrent = []() {
      if(_current && [_current prepare]) {
        [_current drawNow];
        [[_current openGLContext] flushBuffer];
      }
    };
    held.uiScale = []() { return _current ? (float)[_current factor] : 1.f; };
    held.numViews = []() { return (int)_panes.size(); };
    held.cursor = [](Scene::Cursor kind) {
      for(GmshScenePane *p : _panes) {
        bool picking = kind == Scene::Picking;
        if(p->picking == picking) continue;
        p->picking = picking;
        [[p window] invalidateCursorRectsForView:p];
      }
    };
    held.current = []() -> sceneView * {
      return _current ? _current->view : nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(GmshScenePane *p = _paneOf(view)) _current = p;
    };
    held.later = [](double seconds, std::function<void()> what) {
      NSTimer *t = [NSTimer timerWithTimeInterval:std::max(0., seconds)
                                          repeats:NO
                                            block:^(NSTimer *) {
                                              if(what) what();
                                            }];
      [[NSRunLoop mainRunLoop] addTimer:t forMode:NSRunLoopCommonModes];
    };
    held.buttonDown = []() { return cocoaButtonDown(); };
    held.context = []() -> void * { return (void *)CGLGetCurrentContext(); };
    held.makeCurrent = [](sceneView *view) {
      if(GmshScenePane *p = _paneOf(view)) [p prepare];
    };
    held.screen = [](int &height, float &scale) {
      NSScreen *s = [cocoaMainWindow() screen] ?: [NSScreen mainScreen];
      height = 0;
      scale = 1.f;
      if(!s) return;
      scale = (float)[s backingScaleFactor];
      height = (int)([s frame].size.height * scale);
    };
    Scene::setHost(held);
  }

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

} // namespace

NSView *cocoaSceneWidget()
{
  if(_root) return _root;
  _setHost();
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = [[NSView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
  [_root setAutoresizesSubviews:YES];
  _current = _newPane(nil);
  [_current setFrame:[_root bounds]];
  [_root addSubview:_current];
  return _root;
}

void cocoaSceneRedraw() { _redrawAll(); }

bool cocoaSceneDrawing() { return _drawing; }

void cocoaSceneSize(int &width, int &height)
{
  width = _root ? (int)[_root bounds].size.width : 0;
  height = _root ? (int)[_root bounds].size.height : 0;
}

void cocoaSceneSplit(char how, double ratio)
{
  if(!_current) return;
  if(how == 'u') {
    GmshScenePane *keep = (_current && !_current->window) ? _current : nil;
    for(GmshScenePane *p : _panes)
      if(!keep && !p->window) keep = p;
    if(!keep) return;
    std::vector<GmshScenePane *> gone;
    for(GmshScenePane *p : _panes)
      if(p != keep && !p->window) gone.push_back(p);
    for(GmshScenePane *p : gone) _forget(p);
    [keep removeFromSuperview];
    for(NSView *v in [[_root subviews] copy]) [v removeFromSuperview];
    [keep setFrame:[_root bounds]];
    [_root addSubview:keep];
    _current = keep;
    _redrawAll();
    return;
  }
  if(how != 'h' && how != 'v') {
    Msg::Error("Unknown window splitting method '%c'", how);
    return;
  }
  if(_current->window) {
    Msg::Error("Only the graphic windows of the main window can be split");
    return;
  }
  GmshScenePane *was = _current;
  GmshScenePane *fresh = _newPane(was);
  NSView *parent = [was superview];
  NSRect room = [was frame];
  NSSplitView *split = _split(how == 'h');
  [split setFrame:room];
  if([parent isKindOfClass:[NSSplitView class]]) {
    // in the place the view had among the others
    NSSplitView *up = (NSSplitView *)parent;
    NSUInteger at = [[up arrangedSubviews] indexOfObject:was];
    [up removeArrangedSubview:was];
    [was removeFromSuperview];
    [up insertArrangedSubview:split atIndex:at];
  }
  else {
    [was removeFromSuperview];
    [parent addSubview:split];
  }
  [split addArrangedSubview:was];
  [split addArrangedSubview:fresh];
  [split adjustSubviews];
  if(ratio <= 0. || ratio >= 1.) ratio = .5;
  CGFloat size = how == 'h' ? room.size.width : room.size.height;
  [split setPosition:std::floor(size * ratio) ofDividerAtIndex:0];
  _current = fresh;
  _redrawAll();
}

void cocoaSceneNewWindow()
{
  GmshScenePane *fresh = _newPane(_current);
  GmshPaneWindow *w = [[GmshPaneWindow alloc]
    initWithContentRect:NSMakeRect(0, 0, 600, 500)
              styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                        NSWindowStyleMaskMiniaturizable |
                        NSWindowStyleMaskResizable
                backing:NSBackingStoreBuffered
                  defer:NO];
  [w setReleasedWhenClosed:NO];
  [w setDelegate:w];
  w->held = fresh;
  fresh->window = w;
  [w setTitle:[NSString stringWithFormat:@"Gmsh - Graphic window %d",
                                         (int)_panes.size()]];
  [fresh setFrame:[[w contentView] bounds]];
  [[w contentView] addSubview:fresh];
  [w cascadeTopLeftFromPoint:NSMakePoint(
                               NSMinX([cocoaMainWindow() frame]) + 40.,
                               NSMaxY([cocoaMainWindow() frame]) - 40.)];
  _current = fresh;
  [w makeKeyAndOrderFront:nil];
}

void cocoaSceneDestroy()
{
  [_animation invalidate];
  [_gamepad invalidate];
  _animation = _gamepad = nil;
  for(GmshScenePane *p : std::vector<GmshScenePane *>(_panes))
    if(p->window) {
      GmshPaneWindow *w = (GmshPaneWindow *)p->window;
      w->held = nil;
      [w setDelegate:nil];
      [w close];
    }
  _panes.clear();
  _current = nil;
  // the tiled views are in the main window, which goes with them
  _root = nil;
}

void cocoaSceneStartTimers()
{
  if(_animating && !_animation) {
    _animation = [NSTimer timerWithTimeInterval:.01
                                        repeats:YES
                                          block:^(NSTimer *t) {
                                            if(_animating)
                                              animationTick();
                                            else {
                                              [t invalidate];
                                              _animation = nil;
                                            }
                                          }];
    [[NSRunLoop mainRunLoop] addTimer:_animation forMode:NSRunLoopCommonModes];
  }
  if(!_gamepad) {
    double period = Scene::gamepadPeriod();
    // the option may be switched on: looked at again now and then
    _gamepad = [NSTimer
      timerWithTimeInterval:period > 0. ? period : 3.
                    repeats:NO
                      block:^(NSTimer *) {
                        _gamepad = nil;
                        if(_current && Scene::gamepadTurn(_current->view))
                          [_current setNeedsDisplay:YES];
                        cocoaSceneStartTimers();
                      }];
    [[NSRunLoop mainRunLoop] addTimer:_gamepad forMode:NSRunLoopCommonModes];
  }
}

namespace CocoaScene {

  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always) { return ""; }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }

  bool sceneKey(char key)
  {
    bool taken = false;
    for(GmshScenePane *p : _panes)
      if(p->view->key(key)) {
        taken = true;
        [p setNeedsDisplay:YES];
      }
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!_current) return;
    _current->view->screenMessage[0] = first;
    _current->view->screenMessage[1] = second;
    [_current setNeedsDisplay:YES];
  }

  drawContext *getCurrentDrawContext()
  { return _current ? _current->view->getDrawContext() : nullptr; }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(!_current) return;
    NSSize s = [_current convertSizeToBacking:[_current bounds].size];
    width = (int)(s.width + 0.5);
    height = (int)(s.height + 0.5);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(which >= 0 && which < (int)_panes.size()) _current = _panes[which];
  }

  void showAllInEveryWindow()
  {
    for(GmshScenePane *p : _panes)
      if(drawContext *ctx = p->view->getDrawContext()) ctx->showAll();
    _redrawAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  { cocoaSceneSplit(how, ratio); }

  void copyCurrentOpenglWindowToClipboard()
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w < 1 || h < 1 || !_current || ![_current prepare]) return;
    [_current drawNow];
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
    std::vector<unsigned char> pixels((std::size_t)w * h * 4);
    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    // OpenGL counts the rows from the bottom
    unsigned char *to = [image bitmapData];
    for(int row = 0; row < h; row++) {
      std::memcpy(to + (std::size_t)row * w * 4,
                  pixels.data() + (std::size_t)(h - 1 - row) * w * 4,
                  (std::size_t)w * 4);
      for(int x = 0; x < w; x++) to[((std::size_t)row * w + x) * 4 + 3] = 255;
    }
    NSPasteboard *board = [NSPasteboard generalPasteboard];
    [board clearContents];
    [board setData:[image representationUsingType:NSBitmapImageFileTypePNG
                                       properties:@{}]
           forType:NSPasteboardTypePNG];
    [board setData:[image TIFFRepresentation] forType:NSPasteboardTypeTIFF];
    [_current setNeedsDisplay:YES];
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(width > w || height > h) {
      Msg::Warning(
        "The Cocoa interface cannot render a picture larger than the "
        "graphic window (%d x %d): clamping",
        w, h);
      width = std::min(width, w);
      height = std::min(height, h);
    }
    if(width < 1) width = 1;
    if(height < 1) height = 1;
    _captureW = width;
    _captureH = height;
  }

  void endGraphicCapture()
  {
    _captureW = _captureH = 0;
    _redrawAll();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    int width = 0, height = 0;
    getCurrentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;
    CTX *c = CTX::instance();
    if(c->print.width > 0 || c->print.height > 0) {
      if(c->print.width <= 0) {
        width = (int)(width * c->print.height / (double)height);
        height = c->print.height;
      }
      else if(c->print.height <= 0) {
        height = (int)(height * c->print.width / (double)width);
        width = c->print.width;
      }
      else {
        width = c->print.width;
        height = c->print.height;
      }
    }
    beginGraphicCapture(width, height,
                        c->print.compositeWindows ? true : false);
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    endGraphicCapture();
    return buffer;
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    std::vector<sceneView *> views;
    for(GmshScenePane *p : _panes)
      if(!p->window) views.push_back(p->view);
    if(views.empty() && _current) views.push_back(_current->view);
    Scene::orientViews(views, what, reverse, sync);
    _redrawAll();
  }

  void setMouseSelection(bool on) {}

  void toggleAnimation()
  {
    _animating = !_animating;
    cocoaSceneStartTimers();
  }

  bool animating() { return _animating; }

  void abortSelection()
  {
    if(!_current) return;
    _current->view->quitSelection = 1;
    _current->view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    for(GmshScenePane *p : _panes) p->view->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image")
      for(GmshScenePane *p : _panes)
        if(p->view->getDrawContext())
          p->view->getDrawContext()->invalidateBgImageTexture();
    _redrawAll();
  }

  char selectEntity(int type)
  {
    _clearSelected();
    if(!_current) return 'q';
    return _current->view->selectEntity(type, _vertices, _edges, _faces,
                                        _regions, _elements, _points, _views);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    _clearSelected();
    if(!_current || ![_current prepare]) return false;
    [_current place];
    return _current->view->pick(type, mesh, post, x, y, w, h, _vertices, _edges,
                                _faces, _regions, _elements, _points, _views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_current || ![_current prepare]) return false;
    bool ok = _current->view->printTo(width, height, supersampling, format,
                                      type, pixels);
    [_current setNeedsDisplay:YES];
    return ok;
  }

  const std::vector<GVertex *> &selectedVertices() { return _vertices; }
  const std::vector<GEdge *> &selectedEdges() { return _edges; }
  const std::vector<GFace *> &selectedFaces() { return _faces; }
  const std::vector<GRegion *> &selectedRegions() { return _regions; }
  const std::vector<MElement *> &selectedElements() { return _elements; }
  const std::vector<SPoint2> &selectedPoints() { return _points; }
  const std::vector<PView *> &selectedViews() { return _views; }

  // filled from the list in GuiSceneOps.h
  namespace {
    struct offering {
      offering()
      {
        GuiSceneOps ops;
#define GUI_SCENE_TAKE(name, args, call) ops.name = name;
        GUI_SCENE_VOID(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(ret, name, args, call, none) ops.name = name;
        GUI_SCENE_VALUE(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(type, name) ops.name = name;
        GUI_SCENE_LIST(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
        Gui::offerScene("cocoa", ops);
      }
    };
    offering _offering;
  } // namespace

} // namespace CocoaScene

void cocoaSceneCopy() { CocoaScene::copyCurrentOpenglWindowToClipboard(); }
