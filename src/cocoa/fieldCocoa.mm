// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_COCOA)

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>

#import <objc/runtime.h>

#include "cocoaCommon.h"

// The widget of one field. Each carries its binding -- a copy of the field,
// and what the holder does after a change -- as an object associated with
// it, which is also the target and the delegate of its controls, so that it
// goes with the widget: a change the user makes is written through the field,
// then told, then `after` runs; a refresh reads the field and puts the value
// back, quietly.

// --- sizes

// asked once: the widgets are not made again when the option changes
double cocoaEm()
{
  static double em = 0.;
  if(em <= 0.) {
    int size = cocoaSources().settings().fontSize;
    em = size > 0 ? size : [NSFont systemFontSize];
  }
  return em;
}

CGFloat cocoaPx(double em) { return std::floor(em * cocoaEm() + 0.5); }

NSFont *cocoaFont() { return [NSFont systemFontOfSize:cocoaEm()]; }

NSFont *cocoaFixedFont(CGFloat size)
{
  if(size <= 0.) size = cocoaEm() - 1.;
  return [NSFont monospacedSystemFontOfSize:size weight:NSFontWeightRegular];
}

CGFloat cocoaRowHeight() { return std::floor(cocoaEm() * 24. / 13. + .5); }

void cocoaPlace(NSView *view, NSRect room, bool tall)
{
  if(!view) return;
  NSRect r = room;
  if(!tall) {
    CGFloat h = [view intrinsicContentSize].height;
    if(h > 0. && h < room.size.height) {
      r.origin.y += std::floor((room.size.height - h) / 2.);
      r.size.height = h;
    }
  }
  [view setFrame:[view frameForAlignmentRect:r]];
}

@implementation GmshFlippedView
- (BOOL)isFlipped
{
  return YES;
}
@end

namespace {

  struct binding {
    Ui::Field field;
    std::function<void()> after;
    __weak NSView *outer = nil;
    __weak NSView *inner = nil;
    // the number of a slider
    __weak NSTextField *number = nil;
    bool quiet = false;
    std::string was, shown;
    std::vector<std::string> labels;
    std::vector<int> values;
    bool mapHelp = false;
    int mapFrom = -1, mapChannel = 0;
    double wheel = 0.;
    bool dragging = false;
    cocoaTree *tree = nullptr;
    std::vector<std::function<void()>> follow;
    ~binding() { delete tree; }
  };

  const char _key = 0;

} // namespace

@interface GmshBinding
  : NSObject <NSTextFieldDelegate, NSComboBoxDelegate, NSTableViewDataSource,
              NSTableViewDelegate, NSMenuDelegate, NSTextViewDelegate> {
@public
  binding b;
}
@end

namespace {

  binding *_of(NSView *w)
  {
    if(!w) return nullptr;
    GmshBinding *g = objc_getAssociatedObject(w, &_key);
    return g ? &g->b : nullptr;
  }

  // a change the user made: the done() of a choosing that ended, the
  // changed() of a step, then what the holder does; nothing of b is touched
  // afterwards
  void _told(binding *b, bool ends)
  {
    if(b->quiet) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    if(f.done && ends)
      f.done();
    else if(f.changed)
      f.changed();
    if(after) after();
  }

  void _doneAnyway(binding *b)
  {
    if(b->quiet || !b->field.done) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    f.done();
    if(after) after();
  }

  void _choicesOf(const Ui::Field &f, std::vector<std::string> &labels,
                  std::vector<int> &values)
  {
    labels.clear();
    values.clear();
    if(f.dynamicChoices)
      f.dynamicChoices(labels, values);
    else if(f.list && f.itemLabel)
      for(std::size_t i = 0; i < f.list->size(); i++)
        labels.push_back(f.itemLabel((int)i));
    else if(f.list)
      for(std::size_t i = 0; i < f.list->size(); i++)
        labels.push_back(std::to_string((*f.list)[i]));
    else {
      labels = f.choices;
      values = f.values;
    }
  }

  std::string _joined(const std::vector<std::string> &labels)
  {
    std::string s;
    for(const auto &l : labels) s += l + '\n';
    return s;
  }

  // with the decimals of its step when it scrolls, as FLTK has it, unless
  // the value is off the grid of the step
  std::string _number(const Ui::Field &f, double v)
  {
    char s[64];
    if(f.step > 0. && cocoaSources().settings().inputScrolling) {
      int decimals = 0;
      while(decimals < 10 &&
            std::fabs(f.step * std::pow(10., decimals) -
                      std::floor(f.step * std::pow(10., decimals) + .5)) > 1e-9)
        decimals++;
      snprintf(s, sizeof(s), "%.*f", decimals, v);
      if(v != 0. && std::fabs(atof(s) - v) > 1e-9 * std::fabs(v))
        snprintf(s, sizeof(s), "%g", v);
    }
    else
      snprintf(s, sizeof(s), "%g", v);
    return s;
  }

  double _bounded(const Ui::Field &f, double v)
  {
    if(f.maximum > f.minimum) v = std::max(f.minimum, std::min(f.maximum, v));
    if(f.kind == Ui::Integer) v = std::floor(v + .5);
    return v;
  }

  void _numberWrite(binding *b, const std::string &said, bool ends)
  {
    char *end = nullptr;
    double v = strtod(said.c_str(), &end);
    if(end == said.c_str()) {
      cocoaRefreshField(b->outer);
      return;
    }
    v = _bounded(b->field, v);
    b->field.setNumber(v);
    b->shown = _number(b->field, v);
    _told(b, ends);
  }

  bool _editing(NSTextField *t)
  {
    NSText *editor = [t currentEditor];
    return editor && [[t window] firstResponder] == editor;
  }

  NSColor *_alertColour() { return [NSColor systemRedColor]; }

  void _enable(NSView *v, bool on)
  {
    if([v isKindOfClass:[NSControl class]])
      [(NSControl *)v setEnabled:on ? YES : NO];
    if([v isKindOfClass:[NSTextView class]])
      [(NSTextView *)v setSelectable:on ? YES : NO];
    for(NSView *s in [v subviews]) _enable(s, on);
  }

  // the number beside a scale, in em
  const CGFloat _sliderNumber = 3.6;

} // namespace

// --- the text of a value, a number that scrolls with the wheel when it has a
// step

@interface GmshNumberField : NSTextField
@end

@implementation GmshNumberField
- (void)scrollWheel:(NSEvent *)e
{
  binding *b = _of(self);
  if(!b) b = _of([self superview]);
  if(!b || !(b->field.step > 0.) || !cocoaSources().settings().inputScrolling ||
     ![self isEnabled]) {
    [super scrollWheel:e];
    return;
  }
  double dy = [e scrollingDeltaY];
  if([e hasPreciseScrollingDeltas]) {
    // a trackpad: a step every few points
    b->wheel += dy;
    if(std::fabs(b->wheel) < 8.) return;
    dy = b->wheel;
    b->wheel = 0.;
  }
  if(dy == 0.) return;
  const Ui::Field &f = b->field;
  double v = _bounded(f, f.getNumber() + (dy > 0 ? 1. : -1.) * f.step);
  b->field.setNumber(v);
  cocoaRefreshField(b->outer);
  _told(b, false);
}
@end

// --- a number with a scale beside it

@interface GmshSliderBox : GmshFlippedView
@end

@implementation GmshSliderBox
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  NSArray *kids = [self subviews];
  if([kids count] < 2) return;
  NSRect all = [self bounds];
  CGFloat number = cocoaPx(_sliderNumber);
  cocoaPlace(kids[0], NSMakeRect(0., 0., number, all.size.height), false);
  cocoaPlace(kids[1],
             NSMakeRect(number + 4., 0.,
                        std::max(10., all.size.width - number - 4.),
                        all.size.height),
             false);
}
@end

// --- the disc of a direction

@interface GmshDiscView : GmshFlippedView {
@public
  BOOL enabled;
}
@end

@implementation GmshDiscView
- (instancetype)initWithFrame:(NSRect)r
{
  self = [super initWithFrame:r];
  enabled = YES;
  return self;
}
- (NSSize)intrinsicContentSize
{
  return [self frame].size;
}
- (void)drawRect:(NSRect)dirty
{
  binding *b = _of(self);
  if(!b) return;
  double x = 0., y = 0., z = 0.;
  b->field.getVector(x, y, z);
  double length = std::sqrt(x * x + y * y + z * z);
  if(length > 0.) {
    x /= length;
    y /= length;
  }
  NSRect all = [self bounds];
  double side = std::min(all.size.width, all.size.height);
  double r = .5 * side - 3., cx = NSMidX(all), cy = NSMidY(all);
  NSColor *ink =
    enabled ? [NSColor labelColor] : [NSColor disabledControlTextColor];
  [ink set];
  NSBezierPath *circle = [NSBezierPath
    bezierPathWithOvalInRect:NSMakeRect(cx - r, cy - r, 2. * r, 2. * r)];
  [circle stroke];
  NSRectFill(NSMakeRect(cx + r * x - 3., cy - r * y - 3., 6., 6.));
}
- (void)at:(NSEvent *)e
{
  binding *b = _of(self);
  if(!b || !enabled) return;
  NSPoint p = [self convertPoint:[e locationInWindow] fromView:nil];
  NSRect all = [self bounds];
  double r = .5 * std::min(all.size.width, all.size.height) - 3.;
  double xx = (p.x - NSMidX(all)) / r, yy = -(p.y - NSMidY(all)) / r;
  double norm = std::sqrt(xx * xx + yy * yy);
  if(norm > 1.) {
    xx /= norm;
    yy /= norm;
    norm = 1.;
  }
  b->field.setVector(xx, yy, std::sqrt(std::max(0., 1. - norm * norm)));
  [self setNeedsDisplay:YES];
  _told(b, false);
}
- (void)mouseDown:(NSEvent *)e
{
  [self at:e];
}
- (void)mouseDragged:(NSEvent *)e
{
  [self at:e];
}
- (void)mouseUp:(NSEvent *)e
{
  if(binding *b = _of(self)) _doneAnyway(b);
}
@end

// --- the colour map, drawn into the table itself

namespace {

  int _mapChannel(const Ui::ColourMap &map, int i, int channel, bool hsv)
  {
    Ui::Colour c = map.colour(i);
    if(channel == 3) return c.a;
    if(!hsv) return channel == 0 ? c.r : (channel == 1 ? c.g : c.b);
    int h, s, v;
    Ui::toHsv(c, h, s, v);
    return channel == 0 ? h : (channel == 1 ? s : v);
  }

  void _setMapChannel(const Ui::ColourMap &map, int i, int channel, int value,
                      bool hsv)
  {
    Ui::Colour c = map.colour(i);
    if(channel == 3)
      c.a = (unsigned char)value;
    else if(!hsv) {
      if(channel == 0)
        c.r = (unsigned char)value;
      else if(channel == 1)
        c.g = (unsigned char)value;
      else
        c.b = (unsigned char)value;
    }
    else {
      int h, s, v;
      Ui::toHsv(c, h, s, v);
      if(channel == 0)
        h = value;
      else if(channel == 1)
        s = value;
      else
        v = value;
      c = Ui::fromHsv(h, s, v, c.a);
    }
    map.setColour(i, c);
  }

  void _say(const char *text, NSPoint at, NSFont *font, NSColor *ink)
  {
    NSDictionary *a =
      @{NSFontAttributeName : font, NSForegroundColorAttributeName : ink};
    [[NSString stringWithUTF8String:text] drawAtPoint:at withAttributes:a];
  }

} // namespace

@interface GmshMapView : GmshFlippedView
@end

@implementation GmshMapView
- (BOOL)acceptsFirstResponder
{
  return YES;
}
- (void)updateTrackingAreas
{
  for(NSTrackingArea *t in [self trackingAreas]) [self removeTrackingArea:t];
  [self addTrackingArea:[[NSTrackingArea alloc]
                          initWithRect:NSZeroRect
                               options:NSTrackingMouseEnteredAndExited |
                                       NSTrackingActiveInKeyWindow |
                                       NSTrackingInVisibleRect
                                 owner:self
                              userInfo:nil]];
  [super updateTrackingAreas];
}
- (void)mouseEntered:(NSEvent *)e
{
  [[self window] makeFirstResponder:self];
}
- (CGFloat)line
{
  return std::ceil(cocoaEm() * 1.3);
}
- (CGFloat)wedgeY
{
  return [self bounds].size.height - 5. - 3. * [self line];
}
- (void)drawRect:(NSRect)dirty
{
  binding *b = _of(self);
  if(!b) return;
  const Ui::ColourMap &map = b->field.map;
  NSRect all = [self bounds];
  [[NSColor textBackgroundColor] set];
  NSRectFill(all);
  if(map.empty()) return;
  std::string name;
  double least = 0., most = 0.;
  map.about(name, least, most);
  int size = map.size();
  double w = all.size.width, wy = [self wedgeY], lh = [self line];
  if(size < 2 || wy < 4.) return;
  NSColor *ink = [NSColor textColor];
  bool hsv = map.hsv ? map.hsv() : false;
  NSColor *inks[4] = {[NSColor colorWithSRGBRed:1. green:0. blue:0. alpha:1.],
                      [NSColor colorWithSRGBRed:0. green:.78 blue:0. alpha:1.],
                      [NSColor colorWithSRGBRed:0. green:0. blue:1. alpha:1.],
                      ink};
  auto xOf = [&](int i) { return w * i / (double)(size - 1); };
  auto yOf = [&](int v) { return wy * (1. - v / 255.); };
  for(int channel = 0; channel < 4; channel++) {
    [inks[channel] set];
    NSBezierPath *path = [NSBezierPath bezierPath];
    [path setLineWidth:1.];
    for(int i = 0; i < size; i++) {
      NSPoint p = NSMakePoint(xOf(i), yOf(_mapChannel(map, i, channel, hsv)));
      if(i == 0)
        [path moveToPoint:p];
      else
        [path lineToPoint:p];
    }
    [path stroke];
  }
  for(int x = 0; x < (int)w; x++) {
    int i = std::min(size - 1, (int)(x * (double)size / w));
    Ui::Colour c = map.colour(i);
    [[NSColor colorWithSRGBRed:c.r / 255.
                         green:c.g / 255.
                          blue:c.b / 255.
                         alpha:1.] set];
    NSRectFill(NSMakeRect(x, wy, 1., lh));
  }
  NSFont *font = cocoaFont();
  if(b->mapHelp) {
    static const char *const keys[][2] = {
      {"0-9, Ctrl+0-9, F1-F7", "Select predefined colormap"},
      {"mouse1", "Draw red or hue channel"},
      {"mouse2", "Draw green or saturation channel"},
      {"mouse3", "Draw blue or value channel"},
      {"Ctrl+mouse1", "Draw alpha channel"},
      {"Ctrl+c, Ctrl+v, r", "Copy, paste or reset colormap"},
      {"m", "Toggle RGB/HSV mode"},
      {"left, right", "Translate abscissa"},
      {"Ctrl+left, Ctrl+right", "Rotate abscissa"},
      {"i, Ctrl+i", "Invert abscissa or ordinate"},
      {"up, down", "Modify color channel curvature"},
      {"a, Ctrl+a", "Modify alpha coefficient"},
      {"p, Ctrl+p", "Modify alpha channel power law"},
      {"b, Ctrl+b", "Modify gamma correction"},
      {"h", "Show this help message"}};
    const int lines = sizeof(keys) / sizeof(keys[0]);
    double scale = std::min(.85, (wy - 12.) / (lines + 1) / lh);
    NSFont *small = [NSFont systemFontOfSize:cocoaEm() * scale];
    double step = lh * scale + 1.;
    for(int i = 0; i < lines; i++) {
      _say(keys[i][0], NSMakePoint(6., 4. + i * step), small, ink);
      _say(keys[i][1], NSMakePoint(12. * step, 4. + i * step), small, ink);
    }
  }
  else {
    char said[128];
    snprintf(said, sizeof(said), "Colormap %d (%s) - Press h for help",
             map.preset ? map.preset() : 0, hsv ? "HSV" : "RGB");
    _say(said, NSMakePoint(6., 4.), font, ink);
  }
  char says[64];
  double base = wy + lh + 2.;
  snprintf(says, sizeof(says), "%g", least);
  _say(says, NSMakePoint(10., base), font, ink);
  snprintf(says, sizeof(says), "%g", most);
  NSSize wide = [[NSString stringWithUTF8String:says]
    sizeWithAttributes:@{NSFontAttributeName : font}];
  _say(says, NSMakePoint(w - 10. - wide.width, base), font, ink);
}
- (void)paint:(NSEvent *)e first:(bool)first
{
  binding *b = _of(self);
  if(!b) return;
  const Ui::ColourMap &map = b->field.map;
  int size = map.empty() ? 0 : map.size();
  double wy = [self wedgeY], width = [self bounds].size.width;
  NSPoint pos = [self convertPoint:[e locationInWindow] fromView:nil];
  if(size < 2 || width < 1. || pos.y >= wy) return;
  int to = std::max(0, std::min(size - 1, (int)(pos.x * size / width)));
  int from = (first || b->mapFrom < 0) ? to : b->mapFrom;
  b->mapFrom = to;
  int value = std::max(0, std::min(255, (int)((wy - pos.y) * 255. / wy)));
  bool hsv = map.hsv ? map.hsv() : false;
  for(int i = std::min(from, to); i <= std::max(from, to); i++)
    _setMapChannel(map, i, b->mapChannel, value, hsv);
  [self setNeedsDisplay:YES];
  _told(b, false);
}
- (void)press:(NSEvent *)e channel:(int)channel
{
  binding *b = _of(self);
  if(!b) return;
  [[self window] makeFirstResponder:self];
  b->mapHelp = false;
  b->mapChannel = ([e modifierFlags] &
                   (NSEventModifierFlagControl | NSEventModifierFlagCommand)) ?
                    3 :
                    channel;
  [self paint:e first:true];
}
- (void)mouseDown:(NSEvent *)e
{
  [self press:e channel:0];
}
- (void)rightMouseDown:(NSEvent *)e
{
  [self press:e channel:2];
}
- (void)otherMouseDown:(NSEvent *)e
{
  [self press:e channel:1];
}
- (void)mouseDragged:(NSEvent *)e
{
  [self paint:e first:false];
}
- (void)rightMouseDragged:(NSEvent *)e
{
  [self paint:e first:false];
}
- (void)otherMouseDragged:(NSEvent *)e
{
  [self paint:e first:false];
}
- (void)mouseUp:(NSEvent *)e
{
  if(binding *b = _of(self)) b->mapFrom = -1;
}
- (void)rightMouseUp:(NSEvent *)e
{
  [self mouseUp:e];
}
- (void)otherMouseUp:(NSEvent *)e
{
  [self mouseUp:e];
}
- (void)keyDown:(NSEvent *)e
{
  binding *b = _of(self);
  int key = 0;
  unsigned mods = 0;
  if(!b || b->field.map.empty() || !cocoaUiKey(e, key, mods)) {
    [super keyDown:e];
    return;
  }
  const Ui::ColourMap &map = b->field.map;
  bool ctrl = (mods & Ui::ModCommand) != 0, changed = false;
  int presets = map.numPresets ? map.numPresets() : 0, preset = -1;
  if(key >= '0' && key <= '9') preset = (key - '0') + (ctrl ? 10 : 0);
  if(key >= Ui::KeyF1 && key < Ui::KeyF1 + 7) preset = 20 + key - Ui::KeyF1;
  if(preset >= 0 && preset < presets) {
    map.choosePreset(preset);
    changed = true;
  }
  else if(key == 'M' && !ctrl && map.setHsv) {
    map.setHsv(!map.hsv());
    changed = true;
  }
  else if(key == 'H' && !ctrl) {
    b->mapHelp = !b->mapHelp;
    [self setNeedsDisplay:YES];
    return;
  }
  else if(key == 'R' && !ctrl) {
    if(map.preset) map.choosePreset(map.preset());
    changed = true;
  }
  else if(key == 'C' && ctrl) {
    if(map.copy) map.copy();
    return;
  }
  else if(key == 'V' && ctrl) {
    if(map.paste) map.paste();
    changed = true;
  }
  else if(map.parameters) {
    for(const auto &p : map.parameters()) {
      if(!p.up.empty() && p.up.matches(key, mods)) {
        map.adjust(p, true);
        changed = true;
        break;
      }
      if(!p.down.empty() && p.down.matches(key, mods)) {
        map.adjust(p, false);
        changed = true;
        break;
      }
    }
  }
  if(!changed) {
    [super keyDown:e];
    return;
  }
  [self setNeedsDisplay:YES];
  _told(b, true);
}
// Command and the digits or the letters are the map's while the pointer is
// on it, not the menus'
- (BOOL)performKeyEquivalent:(NSEvent *)e
{
  if([[self window] firstResponder] != self) return NO;
  unsigned mods = 0;
  int key = 0;
  if(!cocoaUiKey(e, key, mods)) return NO;
  if(key == 'C' || key == 'V' || (key >= '0' && key <= '9') || key == 'I' ||
     key == 'A' || key == 'P' || key == 'B' || key == Ui::KeyLeft ||
     key == Ui::KeyRight) {
    [self keyDown:e];
    return YES;
  }
  return NO;
}
@end

// --- a page of prose, which follows its links

@interface GmshProseView : NSTextView
@end

@implementation GmshProseView
- (NSSize)intrinsicContentSize
{
  return NSMakeSize(NSViewNoIntrinsicMetric, NSViewNoIntrinsicMetric);
}
- (BOOL)isFlipped
{
  return YES;
}
@end

namespace {

  NSAttributedString *_page(const std::vector<Ui::Line> &page,
                            std::vector<std::function<void()>> *follow)
  {
    NSMutableAttributedString *all = [[NSMutableAttributedString alloc] init];
    double em = cocoaEm();
    for(std::size_t n = 0; n < page.size(); n++) {
      const Ui::Line &l = page[n];
      NSMutableParagraphStyle *p = [[NSMutableParagraphStyle alloc] init];
      if(l.centred) [p setAlignment:NSTextAlignmentCenter];
      if(l.bullet) {
        [p setFirstLineHeadIndent:0.];
        [p setHeadIndent:1.5 * em];
        [p setTabStops:@[ [[NSTextTab alloc]
                         initWithTextAlignment:NSTextAlignmentLeft
                                      location:1.5 * em
                                       options:@{}] ]];
      }
      NSFont *plain = l.heading ? [NSFont boldSystemFontOfSize:em * 1.45] :
                                  [NSFont systemFontOfSize:em];
      NSFont *slanted =
        [[NSFontManager sharedFontManager] convertFont:plain
                                           toHaveTrait:NSItalicFontMask];
      NSDictionary *base = @{
        NSFontAttributeName : plain,
        NSParagraphStyleAttributeName : p,
        NSForegroundColorAttributeName : [NSColor labelColor]
      };
      if(l.bullet)
        [all appendAttributedString:[[NSAttributedString alloc]
                                      initWithString:@"•\t"
                                          attributes:base]];
      for(const Ui::Words &w : l.words) {
        NSMutableDictionary *a = [base mutableCopy];
        if(w.italic) a[NSFontAttributeName] = slanted;
        if(w.follow && follow) {
          a[NSLinkAttributeName] =
            [NSString stringWithFormat:@"gmsh:%d", (int)follow->size()];
          follow->push_back(w.follow);
        }
        [all appendAttributedString:[[NSAttributedString alloc]
                                      initWithString:cocoaString(w.text)
                                          attributes:a]];
      }
      if(n + 1 < page.size())
        [all appendAttributedString:[[NSAttributedString alloc]
                                      initWithString:@"\n"
                                          attributes:base]];
    }
    return all;
  }

  void _prose(binding *b)
  {
    std::vector<Ui::Line> page =
      b->field.prose ? b->field.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page) {
      for(const Ui::Words &w : l.words) said += w.text + (w.italic ? "/" : "|");
      said += '\n';
    }
    if(said == b->was) return;
    b->was = said;
    b->follow.clear();
    NSTextView *t = (NSTextView *)b->inner;
    [[t textStorage] setAttributedString:_page(page, &b->follow)];
  }

  // the columns of the lines of a list, where the tabs of a line stop
  NSAttributedString *_listLine(const Ui::Field &f, const std::string &label)
  {
    NSMutableParagraphStyle *p = [[NSMutableParagraphStyle alloc] init];
    NSMutableArray *stops = [NSMutableArray array];
    double at = 0.;
    for(double w : f.columnsEm) {
      at += cocoaPx(w);
      [stops
        addObject:[[NSTextTab alloc] initWithTextAlignment:NSTextAlignmentLeft
                                                  location:at
                                                   options:@{}]];
    }
    [p setTabStops:stops];
    [p setLineBreakMode:NSLineBreakByTruncatingTail];
    NSFont *font = f.isCode ? cocoaFixedFont(0.) : cocoaFont();
    return [[NSAttributedString alloc] initWithString:cocoaString(label)
                                           attributes:@{
                                             NSFontAttributeName : font,
                                             NSParagraphStyleAttributeName : p
                                           }];
  }

} // namespace

@implementation GmshBinding

// --- the text of a value

- (void)controlTextDidChange:(NSNotification *)n
{
  if(b.quiet) return;
  if(b.field.kind != Ui::Text || b.field.commitsWhenDone) return;
  NSTextField *t = [n object];
  b.shown = cocoaString([t stringValue]);
  b.field.setText(b.shown);
  _told(&b, false);
}

- (void)controlTextDidEndEditing:(NSNotification *)n
{
  if(b.quiet) return;
  NSTextField *t = [n object];
  std::string now = cocoaString([t stringValue]);
  if(now == b.shown) return;
  if(b.field.kind == Ui::Integer || b.field.kind == Ui::Number) {
    _numberWrite(&b, now, true);
    return;
  }
  if(b.field.kind != Ui::Text) return;
  b.shown = now;
  b.field.setText(now);
  _told(&b, true);
}

- (BOOL)control:(NSControl *)control
             textView:(NSTextView *)view
  doCommandBySelector:(SEL)command
{
  if(command == @selector(cancelOperation:)) {
    // Escape closes a panel, and is Gmsh's elsewhere; the text would take it
    // as asking for completions
    NSWindow *w = [control window];
    if([w isKindOfClass:[NSPanel class]])
      [w performClose:nil];
    else if([[NSApp currentEvent] type] == NSEventTypeKeyDown)
      cocoaMainKey([NSApp currentEvent]);
    return YES;
  }
  if(command != @selector(insertNewline:) || b.quiet) return NO;
  std::string now = cocoaString([view string]);
  // Enter says the value is the one, even as it was
  if(b.field.kind == Ui::Integer || b.field.kind == Ui::Number) {
    if(now == b.shown)
      _doneAnyway(&b);
    else
      _numberWrite(&b, now, true);
  }
  else if(b.field.kind == Ui::Text) {
    if(!b.field.commitsWhenDone)
      _doneAnyway(&b);
    else {
      b.shown = now;
      b.field.setText(now);
      _told(&b, true);
    }
  }
  // the text is taken: a dialog's default button is not pressed with it
  [view selectAll:nil];
  return YES;
}

- (void)comboBoxSelectionDidChange:(NSNotification *)n
{
  if(b.quiet) return;
  NSComboBox *c = [n object];
  NSInteger i = [c indexOfSelectedItem];
  if(i < 0 || i >= (NSInteger)b.labels.size()) return;
  b.shown = b.labels[(std::size_t)i];
  b.field.setText(b.shown);
  _told(&b, true);
}

// --- the scale of a number

- (void)slid:(id)sender
{
  if(b.quiet) return;
  NSSlider *s = sender;
  const Ui::Field &g = b.field;
  double v = g.minimum + (g.maximum - g.minimum) * [s doubleValue] / 1000.;
  if(g.step > 0.)
    v = g.minimum + std::floor((v - g.minimum) / g.step + .5) * g.step;
  v = _bounded(g, v);
  b.field.setNumber(v);
  b.shown = _number(g, v);
  b.quiet = true;
  [b.number setStringValue:cocoaString(b.shown)];
  b.quiet = false;
  // a continuous scale says so at every step of the drag, and once more as
  // it is let go
  b.dragging = [[NSApp currentEvent] type] == NSEventTypeLeftMouseDragged;
  _told(&b, !b.dragging);
}

// --- switches and choices

- (void)checked:(id)sender
{
  if(b.quiet) return;
  NSButton *c = sender;
  if(b.field.disclosure)
    b.field.setFlag(!b.field.getFlag());
  else
    b.field.setFlag([c state] == NSControlStateValueOn);
  cocoaRefreshField(b.outer);
  _told(&b, true);
}

- (void)chose:(id)sender
{
  if(b.quiet) return;
  NSPopUpButton *p = sender;
  NSInteger i = [p indexOfSelectedItem];
  if(i < 0 || i >= (NSInteger)b.labels.size()) return;
  if(b.values.empty())
    b.field.setText(b.labels[(std::size_t)i]);
  else if(i < (NSInteger)b.values.size())
    b.field.setNumber(b.values[(std::size_t)i]);
  _told(&b, true);
}

// a menu of switches: its first entry is its name
- (void)switched:(id)sender
{
  if(b.quiet) return;
  NSPopUpButton *p = sender;
  NSInteger i = [p indexOfSelectedItem] - 1;
  if(i < 0) return;
  bool on = !(b.field.chosen && b.field.chosen((int)i));
  if(b.field.choose) b.field.choose((int)i, on);
  cocoaRefreshField(b.outer);
  _told(&b, true);
}

// a menu made when it is opened
- (void)menuNeedsUpdate:(NSMenu *)menu
{
  if(b.field.kind != Ui::Menu) return;
  while([menu numberOfItems] > 1) [menu removeItemAtIndex:1];
  std::vector<std::string> labels;
  std::vector<int> values;
  _choicesOf(b.field, labels, values);
  for(std::size_t i = 0; i < labels.size(); i++) {
    NSMenuItem *it = [menu addItemWithTitle:cocoaString(labels[i])
                                     action:@selector(picked:)
                              keyEquivalent:@""];
    [it setTarget:self];
    [it setTag:(NSInteger)i];
  }
}

- (void)picked:(id)sender
{
  int k = (int)[(NSMenuItem *)sender tag];
  Ui::Field g = b.field;
  std::function<void()> after = b.after;
  cocoaLater([g, k, after]() {
    if(g.choose) g.choose(k, true);
    if(g.done)
      g.done();
    else if(g.changed)
      g.changed();
    if(after) after();
  });
}

- (void)pressed:(id)sender
{
  Ui::Field g = b.field;
  std::function<void()> after = b.after;
  cocoaLater([g, after]() {
    if(g.changed) g.changed();
    if(after) after();
  });
}

- (void)coloured:(id)sender
{
  if(b.quiet) return;
  NSColor *c = [[(NSColorWell *)sender color]
    colorUsingColorSpace:[NSColorSpace sRGBColorSpace]];
  if(!c) return;
  auto byte = [](CGFloat v) {
    return (unsigned char)std::max(0.,
                                   std::min(255., std::floor(v * 255. + .5)));
  };
  b.field.setColour(Ui::Colour(byte([c redComponent]), byte([c greenComponent]),
                               byte([c blueComponent]),
                               byte([c alphaComponent])));
  _told(&b, true);
}

// --- a list

- (NSInteger)numberOfRowsInTableView:(NSTableView *)t
{
  return (NSInteger)b.labels.size();
}

- (NSView *)tableView:(NSTableView *)t
   viewForTableColumn:(NSTableColumn *)column
                  row:(NSInteger)row
{
  NSTextField *cell = [t makeViewWithIdentifier:@"line" owner:self];
  if(!cell) {
    cell = [NSTextField labelWithString:@""];
    [cell setIdentifier:@"line"];
    [cell setLineBreakMode:NSLineBreakByTruncatingTail];
  }
  if(row >= 0 && row < (NSInteger)b.labels.size()) {
    const std::string &label = b.labels[(std::size_t)row];
    if(b.field.columnsEm.size() && label.find('\t') != std::string::npos)
      [cell setAttributedStringValue:_listLine(b.field, label)];
    else {
      [cell setFont:b.field.isCode ? cocoaFixedFont(0.) : cocoaFont()];
      [cell setStringValue:cocoaString(label)];
    }
  }
  return cell;
}

- (void)tableViewSelectionDidChange:(NSNotification *)n
{
  if(b.quiet || !b.field.choose) return;
  NSTableView *t = [n object];
  Ui::Field g = b.field;
  NSIndexSet *picked = [t selectedRowIndexes];
  for(std::size_t i = 0; i < b.labels.size(); i++)
    g.choose((int)i, [picked containsIndex:i] ? true : false);
  _told(&b, true);
}

// a line one clicks is one to be rid of
- (void)clicked:(id)sender
{
  if(b.quiet || b.field.choose || !b.field.removeItem) return;
  NSInteger i = [(NSTableView *)sender clickedRow];
  if(i < 0) return;
  Ui::Field g = b.field;
  std::function<void()> after = b.after;
  cocoaLater([g, i, after]() {
    g.removeItem((int)i);
    if(g.changed) g.changed();
    if(after) after();
  });
}

// --- prose

- (BOOL)textView:(NSTextView *)view
   clickedOnLink:(id)link
         atIndex:(NSUInteger)at
{
  NSString *said =
    [link isKindOfClass:[NSURL class]] ? [link absoluteString] : link;
  if(![said hasPrefix:@"gmsh:"]) return NO;
  int i = [[said substringFromIndex:5] intValue];
  if(i >= 0 && i < (int)b.follow.size()) cocoaLater(b.follow[(std::size_t)i]);
  return YES;
}

@end

// --- the widgets

NSTextField *cocoaLabel(const std::string &text, bool alert)
{
  NSTextField *l = [NSTextField labelWithString:cocoaString(text)];
  [l setFont:cocoaFont()];
  [l setLineBreakMode:NSLineBreakByTruncatingTail];
  if(alert) [l setTextColor:_alertColour()];
  return l;
}

CGFloat cocoaProseHeight(const Ui::Field &f, CGFloat width)
{
  if(!f.prose) return cocoaRowHeight();
  NSAttributedString *page = _page(f.prose(), nullptr);
  NSRect r =
    [page boundingRectWithSize:NSMakeSize(std::max(width, (CGFloat)10.), 1e7)
                       options:NSStringDrawingUsesLineFragmentOrigin |
                               NSStringDrawingUsesFontLeading];
  return std::ceil(r.size.height) + 4.;
}

namespace {

  NSTextField *_textField(bool number)
  {
    NSTextField *t = number ?
                       [[GmshNumberField alloc] initWithFrame:NSZeroRect] :
                       [[NSTextField alloc] initWithFrame:NSZeroRect];
    [t setFont:cocoaFont()];
    [t setBezeled:YES];
    [t setBezelStyle:NSTextFieldSquareBezel];
    [t setEditable:YES];
    [t setSelectable:YES];
    [[t cell] setScrollable:YES];
    [[t cell] setWraps:NO];
    [[t cell] setLineBreakMode:NSLineBreakByClipping];
    return t;
  }

  NSButton *_button(const std::string &label)
  {
    NSButton *p = [NSButton buttonWithTitle:cocoaString(label)
                                     target:nil
                                     action:nil];
    [p setFont:cocoaFont()];
    return p;
  }

  void _fillPopUp(NSPopUpButton *p, const std::vector<std::string> &labels)
  {
    [p removeAllItems];
    // addItemWithTitle: drops a title said twice
    for(const auto &l : labels) {
      [[p menu] addItemWithTitle:cocoaString(l) action:nil keyEquivalent:@""];
    }
  }

} // namespace

NSView *cocoaFieldWidget(const Ui::Field &f, const std::function<void()> &after)
{
  NSView *outer = nil;
  GmshBinding *g = nil;
  auto bind = [&](NSView *o, NSView *in) {
    outer = o;
    g = [[GmshBinding alloc] init];
    g->b.field = f;
    g->b.after = after;
    g->b.outer = o;
    g->b.inner = in;
    objc_setAssociatedObject(o, &_key, g, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
  };
  switch(f.kind) {
  case Ui::Text:
    if(f.dynamicChoices) {
      NSComboBox *c = [[NSComboBox alloc] initWithFrame:NSZeroRect];
      [c setFont:cocoaFont()];
      [c setCompletes:NO];
      [c setNumberOfVisibleItems:12];
      bind(c, c);
      [c setDelegate:g];
    }
    else {
      NSTextField *t = _textField(false);
      bind(t, t);
      [t setDelegate:g];
    }
    break;
  case Ui::Integer:
  case Ui::Number:
    if(f.slider && f.maximum > f.minimum) {
      // the number at the left end and the scale beside it, as the page has
      // it; the scale in a thousand steps
      GmshSliderBox *box =
        [[GmshSliderBox alloc] initWithFrame:NSMakeRect(0, 0, 200, 24)];
      [box setAutoresizesSubviews:YES];
      NSTextField *n = _textField(true);
      NSSlider *s = [NSSlider sliderWithValue:0.
                                     minValue:0.
                                     maxValue:1000.
                                       target:nil
                                       action:nil];
      [s setContinuous:YES];
      [box addSubview:n];
      [box addSubview:s];
      bind(box, s);
      g->b.number = n;
      [n setDelegate:g];
      objc_setAssociatedObject(n, &_key, g, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
      [s setTarget:g];
      [s setAction:@selector(slid:)];
    }
    else {
      NSTextField *t = _textField(true);
      bind(t, t);
      [t setDelegate:g];
    }
    break;
  case Ui::Check:
    if(f.disclosure) {
      // a line one presses to fold or unfold what follows: no frame
      // pressed rather than on or off: AppKit greys the name of a switch that
      // is off, and the arrow says it already
      NSButton *t = _button(f.label);
      [t setBordered:NO];
      bind(t, t);
      [t setTarget:g];
      [t setAction:@selector(checked:)];
    }
    else {
      NSButton *c = [NSButton checkboxWithTitle:cocoaString(f.label)
                                         target:nil
                                         action:nil];
      [c setFont:cocoaFont()];
      bind(c, c);
      [c setTarget:g];
      [c setAction:@selector(checked:)];
    }
    break;
  case Ui::Choice:
    if(f.multiple) {
      NSPopUpButton *p = [[NSPopUpButton alloc] initWithFrame:NSZeroRect
                                                    pullsDown:YES];
      [p setFont:cocoaFont()];
      [p addItemWithTitle:cocoaString(f.label)];
      bind(p, p);
      [p setTarget:g];
      [p setAction:@selector(switched:)];
    }
    else {
      NSPopUpButton *p = [[NSPopUpButton alloc] initWithFrame:NSZeroRect
                                                    pullsDown:NO];
      [p setFont:cocoaFont()];
      bind(p, p);
      [p setTarget:g];
      [p setAction:@selector(chose:)];
    }
    break;
  case Ui::Label: {
    NSTextField *l = f.wraps ? [NSTextField wrappingLabelWithString:@""] :
                               [NSTextField labelWithString:@""];
    [l setFont:f.heading ? [NSFont boldSystemFontOfSize:cocoaEm()] :
                           cocoaFont()];
    [l setAlignment:f.align == Ui::Centre ? NSTextAlignmentCenter :
                    f.align == Ui::Right  ? NSTextAlignmentRight :
                                            NSTextAlignmentLeft];
    if(!f.wraps) [l setLineBreakMode:NSLineBreakByTruncatingTail];
    if(f.alert) [l setTextColor:_alertColour()];
    bind(l, l);
  } break;
  case Ui::Output: {
    NSTextField *t = _textField(false);
    [t setEditable:NO];
    [t setSelectable:YES];
    bind(t, t);
  } break;
  case Ui::Prose: {
    GmshProseView *t =
      [[GmshProseView alloc] initWithFrame:NSMakeRect(0, 0, 200, 50)];
    [t setEditable:NO];
    [t setSelectable:YES];
    [t setDrawsBackground:NO];
    [t setRichText:YES];
    [t setTextContainerInset:NSZeroSize];
    [[t textContainer] setLineFragmentPadding:0.];
    [[t textContainer] setWidthTracksTextView:YES];
    [t setHorizontallyResizable:NO];
    [t setVerticallyResizable:NO];
    bind(t, t);
    [t setDelegate:g];
  } break;
  case Ui::Action: {
    NSButton *p = _button(f.label);
    // as tall as the lines beside it: a rounded button cannot be
    if(f.hangs && f.rows > 1) [p setBezelStyle:NSBezelStyleSmallSquare];
    if(f.isDefault) [p setKeyEquivalent:@"\r"];
    if(f.alert) [p setContentTintColor:_alertColour()];
    bind(p, p);
    [p setTarget:g];
    [p setAction:@selector(pressed:)];
  } break;
  case Ui::Color: {
    NSColorWell *w =
      [[NSColorWell alloc] initWithFrame:NSMakeRect(0, 0, 40, 22)];
    if(@available(macOS 13.0, *)) [w setColorWellStyle:NSColorWellStyleMinimal];
    [[NSColorPanel sharedColorPanel] setShowsAlpha:YES];
    bind(w, w);
    [w setTarget:g];
    [w setAction:@selector(coloured:)];
  } break;
  case Ui::Direction: {
    CGFloat side = std::max(cocoaPx(2.9), cocoaPx(1.45 * std::max(2, f.rows)));
    GmshDiscView *d =
      [[GmshDiscView alloc] initWithFrame:NSMakeRect(0, 0, side, side)];
    bind(d, d);
  } break;
  case Ui::ColorMap: {
    GmshMapView *m =
      [[GmshMapView alloc] initWithFrame:NSMakeRect(0, 0, 200, 150)];
    bind(m, m);
  } break;
  case Ui::Hierarchy: {
    Ui::Tree none;
    cocoaTree *t =
      new cocoaTree(f.hierarchy ? *f.hierarchy : none, true, after);
    NSView *view = t->widget();
    bind(view, view);
    g->b.tree = t;
  } break;
  case Ui::Menu: {
    NSPopUpButton *p = [[NSPopUpButton alloc] initWithFrame:NSZeroRect
                                                  pullsDown:YES];
    [p setFont:cocoaFont()];
    [p addItemWithTitle:cocoaString(f.label)];
    bind(p, p);
    // the list is made when the button is opened
    [[p menu] setDelegate:g];
  } break;
  case Ui::List: {
    NSTableView *t =
      [[NSTableView alloc] initWithFrame:NSMakeRect(0, 0, 200, 100)];
    // the one column as wide as the list, whatever it is given
    NSTableColumn *c = [[NSTableColumn alloc] initWithIdentifier:@"line"];
    [c setResizingMask:NSTableColumnAutoresizingMask];
    [c setWidth:200.];
    [t addTableColumn:c];
    [t setHeaderView:nil];
    [t setColumnAutoresizingStyle:NSTableViewLastColumnOnlyAutoresizingStyle];
    [t setRowHeight:std::ceil(cocoaEm() * 1.35)];
    [t setIntercellSpacing:NSMakeSize(0., 1.)];
    if(@available(macOS 11.0, *)) [t setStyle:NSTableViewStylePlain];
    [t setAllowsMultipleSelection:f.multiple ? YES : NO];
    [t setAllowsEmptySelection:YES];
    NSScrollView *s =
      [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 200, 100)];
    [s setDocumentView:t];
    [s setHasVerticalScroller:YES];
    [s setAutohidesScrollers:YES];
    [s setBorderType:NSBezelBorder];
    bind(s, t);
    [t setDataSource:g];
    [t setDelegate:g];
    [t setTarget:g];
    [t setAction:@selector(clicked:)];
    if(!f.choose && !f.removeItem) [t setAllowsEmptySelection:YES];
  } break;
  case Ui::Spacer: break;
  }
  if(!outer) return nil;
  if(f.tooltip.size() && cocoaSources().settings().tooltips)
    [outer setToolTip:cocoaString(f.tooltip)];
  cocoaRefreshField(outer);
  return outer;
}

void cocoaRebindField(NSView *widget, const Ui::Field &field)
{
  binding *b = _of(widget);
  if(!b || b->field.kind != field.kind) return;
  b->field = field;
  if(b->tree && field.hierarchy) b->tree->setTree(*field.hierarchy);
}

void cocoaRefreshField(NSView *widget)
{
  binding *b = _of(widget);
  if(!b) return;
  const Ui::Field &f = b->field;
  b->quiet = true;
  switch(f.kind) {
  case Ui::Text:
  case Ui::Output: {
    NSTextField *t = (NSTextField *)b->inner;
    std::string value = f.getText();
    bool typing = f.kind == Ui::Text && _editing(t) &&
                  cocoaString([t stringValue]) != b->shown;
    if(!typing) {
      if(cocoaString([t stringValue]) != value)
        [t setStringValue:cocoaString(value)];
      b->shown = value;
    }
    if(f.kind == Ui::Text && f.dynamicChoices) {
      NSComboBox *c = (NSComboBox *)b->outer;
      std::vector<std::string> labels;
      std::vector<int> values;
      f.dynamicChoices(labels, values);
      if(_joined(labels) != b->was) {
        b->was = _joined(labels);
        b->labels = labels;
        [c removeAllItems];
        for(const auto &l : labels) [c addItemWithObjectValue:cocoaString(l)];
      }
    }
  } break;
  case Ui::Integer:
  case Ui::Number: {
    NSTextField *t = b->number ? b->number : (NSTextField *)b->inner;
    std::string value = _number(f, f.getNumber());
    bool typing = _editing(t) && cocoaString([t stringValue]) != b->shown;
    if(!typing) {
      if(cocoaString([t stringValue]) != value)
        [t setStringValue:cocoaString(value)];
      b->shown = value;
    }
    if(b->number && !b->dragging && f.maximum > f.minimum)
      [(NSSlider *)b->inner
        setDoubleValue:std::floor(1000. * (f.getNumber() - f.minimum) /
                                    (f.maximum - f.minimum) +
                                  .5)];
  } break;
  case Ui::Check: {
    NSButton *c = (NSButton *)b->inner;
    bool on = f.getFlag();
    if(f.disclosure)
      // in the colour of text: a button with no frame greys its name when
      // its window is not the key one
      [c setAttributedTitle:[[NSAttributedString alloc]
                              initWithString:cocoaString(f.label +
                                                         (on ? " ▴" : " ▾"))
                                  attributes:@{
                                    NSFontAttributeName : cocoaFont(),
                                    NSForegroundColorAttributeName :
                                      [NSColor labelColor]
                                  }]];
    else
      [c setState:on ? NSControlStateValueOn : NSControlStateValueOff];
  } break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    _choicesOf(f, labels, values);
    NSPopUpButton *p = (NSPopUpButton *)b->inner;
    if(f.multiple) {
      if(_joined(labels) != b->was) {
        b->was = _joined(labels);
        while([p numberOfItems] > 1) [p removeItemAtIndex:1];
        for(const auto &l : labels)
          [[p menu] addItemWithTitle:cocoaString(l)
                              action:nil
                       keyEquivalent:@""];
      }
      [[p itemAtIndex:0] setTitle:cocoaString(f.label)];
      for(NSInteger k = 1; k < [p numberOfItems]; k++)
        [[p itemAtIndex:k] setState:(f.chosen && f.chosen((int)k - 1)) ?
                                      NSControlStateValueOn :
                                      NSControlStateValueOff];
      break;
    }
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      _fillPopUp(p, labels);
    }
    b->labels = labels;
    b->values = values;
    int which = -1;
    std::string current = values.empty() ? f.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(values.empty()) {
        if(labels[k] == current) which = (int)k;
      }
      else if(k < values.size() && values[k] == (int)f.getNumber())
        which = (int)k;
    }
    if(which < 0 && labels.size() && !values.empty()) which = 0;
    if([p indexOfSelectedItem] != which) [p selectItemAtIndex:which];
  } break;
  case Ui::Label: {
    std::string value = f.getText();
    if(value.empty()) value = f.label;
    NSTextField *l = (NSTextField *)b->inner;
    if(cocoaString([l stringValue]) != value)
      [l setStringValue:cocoaString(value)];
  } break;
  case Ui::Prose: _prose(b); break;
  case Ui::Action: break;
  case Ui::Color: {
    Ui::Colour c = f.getColour();
    [(NSColorWell *)b->inner setColor:[NSColor colorWithSRGBRed:c.r / 255.
                                                          green:c.g / 255.
                                                           blue:c.b / 255.
                                                          alpha:c.a / 255.]];
  } break;
  case Ui::Direction:
  case Ui::ColorMap: [b->inner setNeedsDisplay:YES]; break;
  case Ui::Hierarchy:
    if(b->tree) b->tree->refresh(false);
    break;
  case Ui::Menu:
    [[(NSPopUpButton *)b->inner itemAtIndex:0] setTitle:cocoaString(f.label)];
    break;
  case Ui::List: {
    std::vector<std::string> labels;
    std::vector<int> values;
    _choicesOf(f, labels, values);
    NSTableView *t = (NSTableView *)b->inner;
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      b->labels = labels;
      [t reloadData];
    }
    if(f.chosen) {
      NSMutableIndexSet *picked = [NSMutableIndexSet indexSet];
      for(std::size_t k = 0; k < labels.size(); k++)
        if(f.chosen((int)k)) [picked addIndex:k];
      if(![picked isEqualToIndexSet:[t selectedRowIndexes]])
        [t selectRowIndexes:picked byExtendingSelection:NO];
    }
  } break;
  case Ui::Spacer: break;
  }
  if(f.enabled) {
    bool on = f.enabled();
    _enable(b->outer, on);
    if([b->outer isKindOfClass:[GmshDiscView class]]) {
      ((GmshDiscView *)b->outer)->enabled = on ? YES : NO;
      [b->outer setNeedsDisplay:YES];
    }
  }
  b->quiet = false;
}

@interface GmshButtonTarget : NSObject {
@public
  Ui::Button button;
  std::function<void()> after;
}
- (void)pressed:(id)sender;
@end

@implementation GmshButtonTarget
- (void)pressed:(id)sender
{
  if(button.menu) {
    cocoaPopupMenu(button.menu());
    return;
  }
  std::function<void()> what = button.action, then = after;
  cocoaLater([what, then]() {
    if(what) what();
    if(then) then();
  });
}
@end

NSView *cocoaButtonWidget(const Ui::Button &button,
                          const std::function<void()> &after)
{
  std::string label = button.label;
  if(label.empty() && button.menu) label = "▾";
  if(label.empty()) label = button.glyph;
  NSButton *w = _button(label);
  if(button.tooltip.size() && cocoaSources().settings().tooltips)
    [w setToolTip:cocoaString(button.tooltip)];
  if(button.on && button.on())
    [w setFont:[NSFont boldSystemFontOfSize:cocoaEm()]];
  if(button.enabled) [w setEnabled:button.enabled() ? YES : NO];
  GmshButtonTarget *t = [[GmshButtonTarget alloc] init];
  t->button = button;
  t->after = after;
  // a control does not keep its target
  static const char targetKey = 0;
  objc_setAssociatedObject(w, &targetKey, t, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
  [w setTarget:t];
  [w setAction:@selector(pressed:)];
  return w;
}

// --- what the placement is measured with

namespace {
  // the widget of a field that sizes itself, as AppKit makes it
  Ui::Size _measure(const Ui::Field &f, double em, double RH, NSFont *font);
} // namespace

Ui::Metrics cocoaMetrics()
{
  const double em = cocoaEm();
  const double RH = cocoaRowHeight();
  Ui::Metrics m;
  m.field = 10.;
  m.row = RH / em;
  m.line = std::ceil(em * 1.35) / em;
  m.gap = .6;
  m.cellGap = .45;
  m.linePad = .15;
  m.gridRowGap = .3;
  m.rule = .7;
  // a segmented control over a box
  m.tabBar = (RH + 4.) / em;
  m.tab = 1.4;
  m.tabPad = .7;
  m.scrollbar =
    [NSScroller
      scrollerWidthForControlSize:NSControlSizeRegular
                    scrollerStyle:[NSScroller preferredScrollerStyle]] /
    em;
  NSFont *font = cocoaFont();
  m.textWidth = [em, font](const std::string &s) {
    NSSize z =
      [cocoaString(s) sizeWithAttributes:@{NSFontAttributeName : font}];
    return (std::ceil(z.width) + 4.) / em;
  };
  m.widget = [em, RH, font](const Ui::Field &f) -> Ui::Size {
    // a control made to be measured is kept measured: a form is placed again
    // at every change
    static std::map<std::string, Ui::Size> known;
    std::string key;
    if(f.kind == Ui::Check || f.kind == Ui::Action || f.kind == Ui::Menu ||
       (f.kind == Ui::Choice && f.multiple)) {
      key = std::string(1, (char)('a' + f.kind)) + (f.disclosure ? "d" : "") +
            (f.isDefault ? "r" : "") + "/" + f.label;
      auto it = known.find(key);
      if(it != known.end()) return it->second;
    }
    Ui::Size said = _measure(f, em, RH, font);
    if(key.size()) known[key] = said;
    return said;
  };
  m.proseHeight = [em](const Ui::Field &f, double width) -> double {
    return cocoaProseHeight(f, width * em) / em;
  };
  return m;
}

namespace {

  Ui::Size _measure(const Ui::Field &f, double em, double RH, NSFont *font)
  {
    switch(f.kind) {
    case Ui::Check: {
      NSButton *b;
      if(f.disclosure) {
        b = _button(f.label + " ▾");
        [b setBordered:NO];
      }
      else {
        b = [NSButton checkboxWithTitle:cocoaString(f.label)
                                 target:nil
                                 action:nil];
        [b setFont:font];
      }
      return Ui::Size(std::ceil([b intrinsicContentSize].width + 2.) / em,
                      RH / em);
    }
    case Ui::Action: {
      NSButton *b = _button(f.label);
      return Ui::Size(
        std::max(std::ceil([b intrinsicContentSize].width), 4.5 * em) / em,
        RH / em);
    }
    case Ui::Menu: {
      NSPopUpButton *p = [[NSPopUpButton alloc] initWithFrame:NSZeroRect
                                                    pullsDown:YES];
      [p setFont:font];
      [p addItemWithTitle:cocoaString(f.label)];
      return Ui::Size(std::ceil([p intrinsicContentSize].width + 2.) / em,
                      RH / em);
    }
    case Ui::Choice:
      if(f.multiple) {
        NSPopUpButton *p = [[NSPopUpButton alloc] initWithFrame:NSZeroRect
                                                      pullsDown:YES];
        [p setFont:font];
        [p addItemWithTitle:cocoaString(f.label)];
        return Ui::Size(std::ceil([p intrinsicContentSize].width + 2.) / em,
                        RH / em);
      }
      break;
    case Ui::Label: {
      NSFont *face = f.heading ? [NSFont boldSystemFontOfSize:em] : font;
      NSSize z = [cocoaString(f.getText().empty() ? f.label : f.getText())
        sizeWithAttributes:@{NSFontAttributeName : face}];
      return Ui::Size((std::ceil(z.width) + 6.) / em, RH / em);
    }
    case Ui::Color: return Ui::Size(3., RH / em);
    default: break;
    }
    return Ui::Size(-1., RH / em);
  }

} // namespace

#endif
