// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <vector>

#import <objc/runtime.h>

#include "cocoaCommon.h"

// A described form in a panel of its own, its widgets placed where Layout.h
// puts them -- the flex and grid of the page, as the FLTK interface places
// its widgets: AppKit lays out nothing here. The widgets are made once for a
// shape of the form; what folds away, and the panel resized by the user,
// only move them. Tabs are a segmented control over a box, the panes stacked
// in it, one shown; a box that scrolls a scroll view.

@class GmshFormPanel;

namespace {
  // the room between the edge of the panel and what it holds
  CGFloat _margin() { return cocoaPx(.6); }

  CGFloat _px(double em) { return std::floor(em * cocoaEm() + .5); }

  NSRect _abs(const Ui::Rect &r)
  {
    CGFloat m = _margin();
    return NSMakeRect(m + _px(r.x), m + _px(r.y), _px(r.w), _px(r.h));
  }

  NSRect _in(NSRect r, NSPoint origin)
  {
    return NSMakeRect(r.origin.x - origin.x, r.origin.y - origin.y,
                      r.size.width, r.size.height);
  }

  bool _tall(const Ui::Field &f)
  {
    return f.kind == Ui::Prose || f.kind == Ui::List ||
           f.kind == Ui::Hierarchy || f.kind == Ui::ColorMap ||
           f.kind == Ui::Direction || (f.kind == Ui::Action && f.hangs) ||
           (f.kind == Ui::Label && f.wraps && f.rows > 1);
  }

  // the name placed beside the widget, rather than drawn by it
  bool _namedBeside(const Ui::Field &f)
  {
    if(f.label.empty()) return false;
    switch(f.kind) {
    case Ui::Check:
    case Ui::Label:
    case Ui::Action:
    case Ui::Menu:
    case Ui::Spacer: return false;
    case Ui::Choice: return !f.multiple;
    default: return true;
    }
  }

} // namespace

class dialogCocoa {
public:
  const Ui::Form *which = nullptr;
  Ui::Form panel;
  GmshFormPanel *win = nil;
  NSView *content = nil;
  std::string built, folding, pane;
  bool forcePane = false, building = false, dropping = false;
  bool resizedByUser = false, placing = false, positioned = false;
  CGFloat widestSeen = 0.;
  std::vector<Ui::PlacedItem> placed;
  // what was made for each placed item: its widget, or the frame of its tabs
  // or its scroll view
  struct made {
    NSView *view = nil;
    NSTextField *label = nil;
    std::vector<NSView *> trailing;
    // tabs: the row of them, the box, the panes; what scrolls: the document
    NSSegmentedControl *tabs = nil;
    NSMutableArray *panes = nil;
    NSView *document = nil;
    std::vector<std::string> labels;
  };
  std::vector<made> items;
  std::set<std::string> options;
  NSTimer *tick = nil;

  ~dialogCocoa();
  void build();
  void reshape();
  void refresh();
  void show();
  void hide();
  bool shown() const { return win && [(NSWindow *)win isVisible]; }
  void applyPane();
  void tabChosen(std::size_t index, NSInteger segment);
  void userResized();

private:
  Ui::Placement _placement(NSSize room);
  NSSize _room();
  void _take(const Ui::Form &now);
  void _make(std::size_t i);
  void _placeAll(const Ui::Placement &p);
  NSView *_container(std::size_t i, NSPoint &origin);
  void _showPanes();
  void _setContentSize(NSSize size);
};

// the panel: Escape closes it, and what nothing in it took is Gmsh's, as in
// the main window
@interface GmshFormPanel : NSPanel <NSWindowDelegate> {
@public
  dialogCocoa *dialog;
}
@end

// the target of a row of tabs
@interface GmshTabsTarget : NSObject {
@public
  dialogCocoa *dialog;
  std::size_t index;
}
- (void)chose:(id)sender;
@end

@implementation GmshTabsTarget
- (void)chose:(id)sender
{
  if(dialog)
    dialog->tabChosen(index, [(NSSegmentedControl *)sender selectedSegment]);
}
@end

namespace {

  std::map<const Ui::Form *, dialogCocoa *> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogCocoa *> dialogs;
    return dialogs;
  }

  bool _closingDown = false;

  dialogCocoa *_find(const Ui::Form *which)
  {
    auto it = _dialogs().find(which);
    return it == _dialogs().end() ? nullptr : it->second;
  }

  std::set<const Ui::Form *> _pending;

  // once the event is over: several changes make one
  void _askReshape(const Ui::Form *which)
  {
    if(_pending.empty())
      cocoaLater([]() {
        std::set<const Ui::Form *> now;
        now.swap(_pending);
        for(const Ui::Form *w : now)
          if(dialogCocoa *d = _find(w))
            if(d->shown()) d->reshape();
      });
    _pending.insert(which);
  }

  const char _tabsKey = 0;

} // namespace

@implementation GmshFormPanel
- (void)keyDown:(NSEvent *)e
{
  if(!cocoaMainKey(e)) [super keyDown:e];
}
- (void)cancelOperation:(id)sender
{
  [self performClose:sender];
}
- (void)windowWillClose:(NSNotification *)n
{
  dialogCocoa *d = dialog;
  if(!d || _closingDown || d->dropping) return;
  [d->tick invalidate];
  d->tick = nil;
  // closing a dialog undoes what it leaves behind
  if(d->panel.closed) cocoaLater(d->panel.closed);
}
- (void)windowDidEndLiveResize:(NSNotification *)n
{
  if(dialog) dialog->userResized();
}
- (void)windowDidResize:(NSNotification *)n
{
  if(dialog && [self inLiveResize]) dialog->userResized();
}
@end

dialogCocoa::~dialogCocoa()
{
  dropping = true;
  [tick invalidate];
  tick = nil;
  for(auto &m : items)
    if(m.tabs) {
      GmshTabsTarget *t = [m.tabs target];
      if(t) t->dialog = nullptr;
    }
  if(win) {
    win->dialog = nullptr;
    [win setDelegate:nil];
    [win orderOut:nil];
    [win close];
    win = nil;
  }
}

Ui::Placement dialogCocoa::_placement(NSSize room)
{
  const double em = cocoaEm();
  Ui::Metrics m = cocoaMetrics();
  Ui::Size need = Ui::treeSize(panel.content, m, panel.leastRows);
  // never so narrow that a dialog with little in it looks starved, as the
  // page has it; a column down the side is beside the dialog
  double least = 12.;
  const Ui::Item &c = panel.content;
  if(c.kind == Ui::Item::ABox && c.box->direction == Ui::Box::Across &&
     c.box->items.size() > 1 && Ui::fills(c.box->items[0]))
    least += Ui::treeSize(c.box->items[0], m, 0).w;
  double width = std::max(need.w, least);
  double height = need.h;
  CGFloat inner = 2. * _margin();
  if(resizedByUser) {
    width = std::max(width, (room.width - inner) / em);
    height = std::max(height, (room.height - inner) / em);
  }
  else {
    // keeps the widest width asked for, so that it sits still
    CGFloat pixels = _px(width);
    if(pixels > widestSeen)
      widestSeen = pixels;
    else
      width = widestSeen / em;
  }
  return Ui::placeTree(panel.content, m, width, height, panel.leastRows);
}

NSSize dialogCocoa::_room()
{ return [win contentRectForFrameRect:[win frame]].size; }

NSView *dialogCocoa::_container(std::size_t i, NSPoint &origin)
{
  const Ui::PlacedItem &p = placed[i];
  origin = NSZeroPoint;
  if(p.parent == (std::size_t)-1 || p.parent >= items.size()) return content;
  made &up = items[p.parent];
  const Ui::PlacedItem &holder = placed[p.parent];
  if(up.tabs && p.pane >= 0 && p.pane < (int)[up.panes count]) {
    origin = _abs(holder.panes[(std::size_t)p.pane]).origin;
    return up.panes[(NSUInteger)p.pane];
  }
  if(up.document) {
    origin = _abs(holder.box).origin;
    return up.document;
  }
  return _container(p.parent, origin);
}

void dialogCocoa::_make(std::size_t i)
{
  const Ui::PlacedItem &p = placed[i];
  made &m = items[i];
  NSPoint origin;
  NSView *into = _container(i, origin);
  const Ui::Item &item = *p.item;
  if(item.kind == Ui::Item::ATabs) {
    NSBox *box = [[NSBox alloc] initWithFrame:NSZeroRect];
    [box setTitlePosition:NSNoTitle];
    [box setBoxType:NSBoxPrimary];
    [into addSubview:box];
    m.view = box;
    NSMutableArray *labels = [NSMutableArray array];
    for(const auto &t : item.tabs->tabs) {
      m.labels.push_back(t.first);
      [labels addObject:cocoaString(t.first.size() ? t.first : "·")];
    }
    GmshTabsTarget *target = [[GmshTabsTarget alloc] init];
    target->dialog = this;
    target->index = i;
    m.tabs = [NSSegmentedControl
      segmentedControlWithLabels:labels
                    trackingMode:NSSegmentSwitchTrackingSelectOne
                          target:target
                          action:@selector(chose:)];
    [m.tabs setFont:cocoaFont()];
    [m.tabs setSelectedSegment:0];
    // a control does not keep its target
    objc_setAssociatedObject(m.tabs, &_tabsKey, target,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    m.panes = [NSMutableArray array];
    for(std::size_t k = 0; k < item.tabs->tabs.size(); k++) {
      NSView *pane = [[GmshFlippedView alloc] initWithFrame:NSZeroRect];
      [pane setHidden:k != 0];
      [into addSubview:pane];
      [m.panes addObject:pane];
    }
    // over the box, whose top edge runs through it
    [into addSubview:m.tabs];
    return;
  }
  if(item.kind == Ui::Item::ABox) {
    NSScrollView *scroll = [[NSScrollView alloc] initWithFrame:NSZeroRect];
    [scroll setHasVerticalScroller:YES];
    [scroll setAutohidesScrollers:YES];
    [scroll setDrawsBackground:NO];
    [scroll setBorderType:NSNoBorder];
    NSView *doc = [[GmshFlippedView alloc] initWithFrame:NSZeroRect];
    [scroll setDocumentView:doc];
    [into addSubview:scroll];
    m.view = scroll;
    m.document = doc;
    return;
  }
  if(item.kind == Ui::Item::ARule) {
    NSBox *line = [[NSBox alloc] initWithFrame:NSZeroRect];
    [line setBoxType:NSBoxSeparator];
    [into addSubview:line];
    m.view = line;
    return;
  }
  const Ui::Field &f = p.field;
  if(item.kind == Ui::Item::AHeading) {
    NSTextField *h = cocoaLabel(item.text, false);
    [h setFont:[NSFont boldSystemFontOfSize:cocoaEm()]];
    [into addSubview:h];
    m.view = h;
    return;
  }
  if(f.kind == Ui::Spacer) return;
  const Ui::Form *form = which;
  NSView *w = cocoaFieldWidget(f, [form]() { _askReshape(form); });
  if(!w) return;
  [into addSubview:w];
  m.view = w;
  if(f.option.size()) options.insert(f.option);
  if(_namedBeside(f)) {
    m.label = cocoaLabel(f.label, f.alert);
    if(f.labelBefore) [m.label setAlignment:NSTextAlignmentRight];
    [into addSubview:m.label];
  }
  for(const Ui::Button &b : f.trailing) {
    NSView *t = cocoaButtonWidget(b, [form]() { _askReshape(form); });
    // a square as tall as the line, as the placement has it: no room for
    // the margins of a rounded button
    if([t isKindOfClass:[NSButton class]]) {
      NSButton *square = (NSButton *)t;
      [square setBezelStyle:NSBezelStyleSmallSquare];
      [square setFont:[NSFont systemFontOfSize:[NSFont smallSystemFontSize]]];
    }
    [into addSubview:t];
    m.trailing.push_back(t);
  }
}

void dialogCocoa::_placeAll(const Ui::Placement &placement)
{
  placing = true;
  const CGFloat RH = cocoaRowHeight();
  std::vector<CGFloat> bottoms(placed.size(), 0.);
  for(std::size_t i = 0; i < placed.size(); i++) {
    const Ui::PlacedItem &p = placed[i];
    made &m = items[i];
    NSPoint origin;
    _container(i, origin);
    NSRect r = _in(_abs(p.box), origin);
    // how far down what is inside a box that scrolls runs
    for(std::size_t up = p.parent; up != (std::size_t)-1 && up < placed.size();
        up = placed[up].parent)
      if(items[up].document) {
        NSRect doc = _abs(placed[up].box);
        NSRect mine = _abs(p.box);
        bottoms[up] = std::max(bottoms[up], NSMaxY(mine) - doc.origin.y);
        break;
      }
    if(m.tabs) {
      CGFloat bar = cocoaPx(cocoaMetrics().tabBar);
      NSSize want = [m.tabs intrinsicContentSize];
      CGFloat w = std::min(r.size.width, (CGFloat)std::ceil(want.width));
      NSRect row = NSMakeRect(r.origin.x + std::floor((r.size.width - w) / 2.),
                              r.origin.y, w, bar);
      cocoaPlace(m.tabs, row, false);
      NSRect box =
        NSMakeRect(r.origin.x, r.origin.y + std::floor(bar / 2.), r.size.width,
                   r.size.height - std::floor(bar / 2.));
      [m.view setFrame:box];
      for(NSUInteger k = 0; k < [m.panes count] && k < p.panes.size(); k++)
        [m.panes[k] setFrame:_in(_abs(p.panes[k]), origin)];
      [m.tabs setHidden:p.hidden];
      [m.view setHidden:p.hidden];
      if(p.hidden)
        for(NSView *pane in m.panes) [pane setHidden:YES];
      continue;
    }
    if(m.document) {
      [m.view setFrame:r];
      [m.view setHidden:p.hidden];
      continue;
    }
    if(!m.view) continue;
    if(p.item->kind == Ui::Item::ARule) {
      [m.view setFrame:NSMakeRect(r.origin.x,
                                  r.origin.y + std::floor(r.size.height / 2.),
                                  r.size.width, 1.)];
      [m.view setHidden:p.hidden];
      continue;
    }
    bool tall = p.item->kind == Ui::Item::AField && _tall(p.field);
    if(!tall) r.size.height = std::max(r.size.height, RH);
    // a rounded button narrower than its name and its margins, as a share of
    // a line makes some: a square one keeps none
    if(p.field.kind == Ui::Action && [m.view isKindOfClass:[NSButton class]]) {
      NSButton *b = (NSButton *)m.view;
      if([b bezelStyle] != NSBezelStyleSmallSquare && [b isBordered] &&
         [b intrinsicContentSize].width > r.size.width)
        [b setBezelStyle:NSBezelStyleSmallSquare];
    }
    cocoaPlace(m.view, r, tall);
    [m.view setHidden:p.hidden];
    if(m.label) {
      bool beside = p.label.w > 0.;
      if(beside) {
        NSRect l = _in(_abs(p.label), origin);
        l.origin.y = r.origin.y;
        l.size.height = tall ? std::min(RH, r.size.height) : r.size.height;
        cocoaPlace(m.label, l, false);
      }
      [m.label setHidden:p.hidden || !beside];
    }
    for(std::size_t t = 0; t < m.trailing.size(); t++) {
      bool there = t < p.trailing.size();
      if(there) {
        NSRect b = _in(_abs(p.trailing[t]), origin);
        b.origin.y = r.origin.y;
        b.size.height = std::min(RH, r.size.height);
        cocoaPlace(m.trailing[t], b, false);
      }
      [m.trailing[t] setHidden:p.hidden || !there];
    }
  }
  // the documents of what scrolls, as tall as what they hold
  for(std::size_t i = 0; i < placed.size(); i++)
    if(items[i].document) {
      NSScrollView *s = (NSScrollView *)items[i].view;
      NSSize inside = [s contentSize];
      [items[i].document
        setFrame:NSMakeRect(0., 0., inside.width,
                            std::max(inside.height, bottoms[i]))];
    }
  CGFloat m2 = 2. * _margin();
  _setContentSize(
    NSMakeSize(_px(placement.width) + m2, _px(placement.height) + m2));
  placing = false;
}

void dialogCocoa::_setContentSize(NSSize size)
{
  NSRect now = [win contentRectForFrameRect:[win frame]];
  [win setContentMinSize:resizedByUser ? [win contentMinSize] : size];
  if(std::fabs(now.size.width - size.width) < .5 &&
     std::fabs(now.size.height - size.height) < .5)
    return;
  if([win inLiveResize]) return;
  // the top left corner stays where it is
  NSRect frame =
    [win frameRectForContentRect:NSMakeRect(now.origin.x, now.origin.y,
                                            size.width, size.height)];
  frame.origin.y += [win frame].size.height - frame.size.height;
  [win setFrame:frame display:YES];
}

void dialogCocoa::userResized()
{
  if(placing || !win) return;
  resizedByUser = true;
  Ui::Placement p = _placement(_room());
  if(p.items.size() != placed.size()) return;
  placed = p.items;
  _placeAll(p);
}

void dialogCocoa::build()
{
  building = true;
  panel = *which;
  built = Ui::signature(panel);
  folding = Ui::folding(panel);
  if(!win) {
    win = [[GmshFormPanel alloc]
      initWithContentRect:NSMakeRect(0, 0, 300, 200)
                styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                          NSWindowStyleMaskMiniaturizable |
                          NSWindowStyleMaskResizable
                  backing:NSBackingStoreBuffered
                    defer:YES];
    win->dialog = this;
    [win setDelegate:win];
    [win setReleasedWhenClosed:NO];
    [win setHidesOnDeactivate:NO];
    [win setFloatingPanel:NO];
    [win setBecomesKeyOnlyIfNeeded:NO];
  }
  [win setTitle:cocoaString(panel.title)];
  items.clear();
  options.clear();
  NSView *old = content;
  content = [[GmshFlippedView alloc] initWithFrame:NSZeroRect];
  Ui::Placement p = _placement(_room());
  placed = p.items;
  items.assign(placed.size(), made());
  for(std::size_t i = 0; i < placed.size(); i++) _make(i);
  [win setContentView:content];
  // the old widgets go once the event that asked for this is over: one of
  // them may be the button whose action is running
  if(old) {
    NSView *gone = old;
    cocoaLater([gone]() { (void)gone; });
  }
  _placeAll(p);
  forcePane = true;
  building = false;
  applyPane();
}

void dialogCocoa::_showPanes()
{
  for(std::size_t i = 0; i < items.size(); i++) {
    made &m = items[i];
    if(!m.tabs) continue;
    NSInteger shown = [m.tabs selectedSegment];
    for(NSUInteger k = 0; k < [m.panes count]; k++)
      [m.panes[k] setHidden:placed[i].hidden || (NSInteger)k != shown];
  }
}

void dialogCocoa::applyPane()
{
  if(forcePane && pane.size()) {
    forcePane = false;
    building = true;
    for(std::size_t i = 0; i < items.size(); i++) {
      made &m = items[i];
      if(!m.tabs) continue;
      for(std::size_t k = 0; k < m.labels.size(); k++) {
        if(m.labels[k] != pane) continue;
        [m.tabs setSelectedSegment:(NSInteger)k];
        // and the tabs the pane's are in, for tabs under tabs
        for(std::size_t up = placed[i].parent; up != (std::size_t)-1;
            up = placed[up].parent)
          if(items[up].tabs && placed[i].pane >= 0) {
            std::size_t below = i;
            while(placed[below].parent != up) below = placed[below].parent;
            if(placed[below].pane >= 0)
              [items[up].tabs setSelectedSegment:placed[below].pane];
          }
      }
    }
    building = false;
  }
  _showPanes();
}

void dialogCocoa::tabChosen(std::size_t index, NSInteger segment)
{
  if(building || index >= items.size()) return;
  made &m = items[index];
  if(segment < 0 || segment >= (NSInteger)m.labels.size()) return;
  std::string label = m.labels[(std::size_t)segment];
  bool moved = pane != label;
  pane = label;
  _showPanes();
  if(!moved || !placed[index].item->tabs->chosen) return;
  std::function<void(const std::string &)> chosen =
    placed[index].item->tabs->chosen;
  cocoaLater([chosen, label]() { chosen(label); });
}

void dialogCocoa::refresh()
{
  // what folded away takes no room: the widgets are moved
  std::string now = Ui::folding(panel);
  if(now != folding) {
    folding = now;
    Ui::Placement p = _placement(_room());
    if(p.items.size() == placed.size()) {
      placed = p.items;
      _placeAll(p);
    }
  }
  // the fields of the form of now, in the order they were made
  for(std::size_t i = 0; i < items.size() && i < placed.size(); i++) {
    if(!items[i].view || placed[i].item->kind != Ui::Item::AField) continue;
    cocoaRebindField(items[i].view, placed[i].field);
    cocoaRefreshField(items[i].view);
  }
  applyPane();
}

// the form of now, of the shape the widgets were made for: the placed items
// point into the form, and are those of the one taken
void dialogCocoa::_take(const Ui::Form &now)
{
  panel = now;
  Ui::Placement p = _placement(_room());
  if(p.items.size() != placed.size()) {
    build();
    return;
  }
  folding = Ui::folding(panel);
  bool moved = false;
  for(std::size_t i = 0; i < placed.size() && !moved; i++) {
    const Ui::Rect &a = placed[i].box, &b = p.items[i].box;
    if(placed[i].hidden != p.items[i].hidden || a.x != b.x || a.y != b.y ||
       a.w != b.w || a.h != b.h)
      moved = true;
  }
  placed = p.items;
  if(moved) _placeAll(p);
}

void dialogCocoa::reshape()
{
  if(!which) return;
  Ui::Form now = *which;
  if(!win || Ui::signature(now) != built)
    build();
  else
    _take(now);
  refresh();
}

void dialogCocoa::show()
{
  Ui::Form now = *which;
  if(!win || Ui::signature(now) != built)
    build();
  else
    _take(now);
  forcePane = true;
  refresh();
  if(!positioned) {
    positioned = true;
    // where the option says, from the top left of the screen as the other
    // interfaces have it; or in the top right corner of the main window
    const Ui::Backend::Settings set = cocoaSources().settings();
    NSWindow *main = cocoaMainWindow();
    NSScreen *screen = [main screen] ?: [NSScreen mainScreen];
    NSRect all = [screen visibleFrame], f = [win frame];
    if(set.dialogX > 0 || set.dialogY > 0)
      f.origin = NSMakePoint(all.origin.x + set.dialogX,
                             NSMaxY(all) - set.dialogY - f.size.height);
    else if(main)
      f.origin = NSMakePoint(NSMaxX([main frame]) - f.size.width - 20.,
                             NSMaxY([main frame]) - f.size.height - 60.);
    [win setFrame:[win constrainFrameRect:f toScreen:screen] display:NO];
  }
  [win makeKeyAndOrderFront:nil];
  if(panel.refreshEvery > 0. && !tick) {
    const Ui::Form *form = which;
    tick = [NSTimer timerWithTimeInterval:panel.refreshEvery
                                  repeats:YES
                                    block:^(NSTimer *) {
                                      dialogCocoa *d = _find(form);
                                      if(d && d->shown()) d->reshape();
                                    }];
    [[NSRunLoop mainRunLoop] addTimer:tick forMode:NSRunLoopCommonModes];
  }
}

void dialogCocoa::hide()
{
  if(!shown()) return;
  // closed by Gmsh rather than by the user: what the panel leaves behind is
  // undone all the same, as in the other interfaces
  [win close];
}

// --- what the backend asks

namespace {
  dialogCocoa *_dialog(const Ui::Form &form)
  {
    dialogCocoa *d = _find(&form);
    if(d) return d;
    d = new dialogCocoa;
    d->which = &form;
    _dialogs()[&form] = d;
    return d;
  }
} // namespace

void cocoaShowForm(const Ui::Form &form, bool show)
{
  if(!show) {
    if(dialogCocoa *d = _find(&form)) d->hide();
    return;
  }
  _dialog(form)->show();
}

bool cocoaFormPosition(int &x, int &y)
{
  for(auto &it : _dialogs())
    if(it.second->shown()) {
      // from the top left of the screen, as the options say it
      NSWindow *win = it.second->win;
      NSRect all = [([win screen] ?: [NSScreen mainScreen]) visibleFrame];
      NSRect f = [win frame];
      x = (int)(f.origin.x - all.origin.x);
      y = (int)(NSMaxY(all) - NSMaxY(f));
      return true;
    }
  return false;
}

bool cocoaFormVisible(const Ui::Form &form)
{
  dialogCocoa *d = _find(&form);
  return d && d->shown();
}

std::string cocoaFormPane(const Ui::Form &form)
{
  dialogCocoa *d = _find(&form);
  return d ? d->pane : "";
}

void cocoaSetFormPane(const Ui::Form &form, const std::string &pane)
{
  dialogCocoa *d = _dialog(form);
  d->pane = pane;
  d->forcePane = true;
  if(d->shown()) d->applyPane();
}

void cocoaReloadForm(const Ui::Form &form)
{
  dialogCocoa *d = _find(&form);
  if(d && d->shown()) d->reshape();
}

void cocoaDropForm(const Ui::Form &form)
{
  auto it = _dialogs().find(&form);
  if(it == _dialogs().end()) return;
  dialogCocoa *d = it->second;
  _dialogs().erase(it);
  _pending.erase(&form);
  delete d;
}

void cocoaFormOptionChanged(const std::string &name)
{
  for(auto &it : _dialogs()) {
    dialogCocoa *d = it.second;
    if(d->shown() && d->options.count(name)) d->refresh();
  }
}

void cocoaFormsClosingDown()
{
  _closingDown = true;
  for(auto &it : _dialogs()) delete it.second;
  _dialogs().clear();
  _pending.clear();
}
