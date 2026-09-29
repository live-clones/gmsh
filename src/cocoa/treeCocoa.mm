// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_COCOA)

#include <algorithm>

#import <objc/runtime.h>

#include "cocoaCommon.h"

// The tree as a view-based NSOutlineView: a branch is filled the first time
// the outline asks for its children, which is when it is opened, so that what
// is asked of the description is what is shown; a line with a field holds its
// widget. A line is its path, which is what survives a rebuild; the outline
// knows it by a small object the line keeps.

@interface GmshTreeItem : NSObject {
@public
  cocoaTree::line *line;
}
@end
@implementation GmshTreeItem
@end

@interface GmshOutlineView : NSOutlineView {
@public
  cocoaTree *tree;
}
@end

@interface GmshTreeSource
  : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate> {
@public
  cocoaTree *tree;
}
- (void)clicked:(id)sender;
- (void)picked:(id)sender;
- (void)named:(id)sender;
@end

namespace {

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  NSColor *_colour(const Ui::Colour &c)
  {
    return [NSColor colorWithSRGBRed:c.r / 255.
                               green:c.g / 255.
                                blue:c.b / 255.
                               alpha:c.a / 255.];
  }

  // a row that holds a field: the widget, then the name
  const double _fieldEm = 8.;

} // namespace

// the widget of a row that holds a field, and the name after it
@interface GmshTreeRow : NSTableCellView {
@public
  NSView *widget;
  NSView *name;
}
@end

@implementation GmshTreeRow
- (void)resizeSubviewsWithOldSize:(NSSize)old
{
  NSRect all = [self bounds];
  CGFloat x = 0.;
  CGFloat h = all.size.height;
  if(widget) {
    // a switch or a button as wide as it is, a value as wide as a short field
    NSSize want = [widget intrinsicContentSize];
    CGFloat wide = want.width > 0. && [widget isKindOfClass:[NSButton class]] ?
                     std::ceil(want.width) :
                     cocoaPx(_fieldEm);
    cocoaPlace(widget, NSMakeRect(x, 0., wide, h), false);
    x += wide + cocoaPx(.45);
  }
  if(name)
    cocoaPlace(name, NSMakeRect(x, 0., std::max(10., all.size.width - x), h),
               false);
}
@end

@implementation GmshOutlineView
- (NSMenu *)menuForEvent:(NSEvent *)e
{
  NSPoint p = [self convertPoint:[e locationInWindow] fromView:nil];
  NSInteger row = [self rowAtPoint:p];
  if(row < 0 || !tree) return nil;
  cocoaTree::line *l = tree->lineOf([self itemAtRow:row]);
  if(!l || !tree->tree().node) return nil;
  Ui::Node node = tree->tree().node(l->path);
  if(node.menu) {
    std::vector<Ui::MenuItem> items = node.menu();
    cocoaLater([items]() { cocoaPopupMenu(items); });
  }
  return nil;
}
// the keys go on to the window: the tree takes none of Gmsh's
- (void)keyDown:(NSEvent *)e
{
  int key = 0;
  unsigned mods = 0;
  if(cocoaUiKey(e, key, mods) &&
     (key == Ui::KeyUp || key == Ui::KeyDown || key == Ui::KeyLeft ||
      key == Ui::KeyRight) &&
     !mods) {
    [super keyDown:e];
    return;
  }
  if(!cocoaMainKey(e)) [super keyDown:e];
}
@end

@implementation GmshTreeSource

- (NSInteger)outlineView:(NSOutlineView *)o numberOfChildrenOfItem:(id)item
{
  if(!tree) return 0;
  if(!item) return (NSInteger)tree->top().size();
  cocoaTree::line *l = tree->lineOf(item);
  if(!l) return 0;
  tree->fill(l);
  return (NSInteger)l->kids.size();
}

- (id)outlineView:(NSOutlineView *)o child:(NSInteger)index ofItem:(id)item
{
  std::vector<cocoaTree::line *> *kids = &tree->top();
  if(item) {
    cocoaTree::line *l = tree->lineOf(item);
    tree->fill(l);
    kids = &l->kids;
  }
  if(index < 0 || index >= (NSInteger)kids->size()) return nil;
  return (*kids)[(std::size_t)index]->item;
}

- (BOOL)outlineView:(NSOutlineView *)o isItemExpandable:(id)item
{
  cocoaTree::line *l = tree ? tree->lineOf(item) : nullptr;
  return l && l->branch;
}

- (NSView *)outlineView:(NSOutlineView *)o
     viewForTableColumn:(NSTableColumn *)column
                   item:(id)item
{
  cocoaTree::line *l = tree ? tree->lineOf(item) : nullptr;
  return l ? tree->viewFor(l) : nil;
}

- (CGFloat)outlineView:(NSOutlineView *)o heightOfRowByItem:(id)item
{
  cocoaTree::line *l = tree ? tree->lineOf(item) : nullptr;
  if(l && l->node.hasField && !l->branch && !tree->picks())
    return cocoaRowHeight() + 2.;
  return std::ceil(cocoaEm() * 1.55);
}

- (NSTableRowView *)outlineView:(NSOutlineView *)o rowViewForItem:(id)item
{
  NSTableRowView *r = [[NSTableRowView alloc] init];
  cocoaTree::line *l = tree ? tree->lineOf(item) : nullptr;
  if(l && l->node.highlight.a)
    [r setBackgroundColor:_colour(l->node.highlight)];
  return r;
}

- (BOOL)outlineView:(NSOutlineView *)o shouldSelectItem:(id)item
{
  return NO;
}

- (void)outlineViewItemDidExpand:(NSNotification *)n
{
  cocoaTree::line *l = tree ? tree->lineOf([n userInfo][@"NSObject"]) : nullptr;
  if(l) tree->expanded(l, true);
}

- (void)outlineViewItemDidCollapse:(NSNotification *)n
{
  cocoaTree::line *l = tree ? tree->lineOf([n userInfo][@"NSObject"]) : nullptr;
  if(l) tree->expanded(l, false);
}

// a line without a widget of its own is pressed where it is written
- (void)clicked:(id)sender
{
  if(!tree || tree->quiet() || tree->picks() || !tree->tree().node) return;
  NSOutlineView *o = sender;
  NSInteger row = [o clickedRow];
  if(row < 0) return;
  cocoaTree::line *l = tree->lineOf([o itemAtRow:row]);
  if(!l || l->field) return;
  Ui::Node node = tree->tree().node(l->path);
  if(!node.pressed || (node.enabled && !node.enabled())) return;
  std::function<void()> what = node.pressed, after = tree->after();
  cocoaLater([what, after]() {
    what();
    if(after) after();
  });
}

// the switch of a line, in a tree whose lines are switches
- (void)picked:(id)sender
{
  if(!tree || tree->quiet() || !tree->tree().node) return;
  NSButton *b = sender;
  NSInteger row = [tree->outline() rowForView:b];
  if(row < 0) return;
  cocoaTree::line *l = tree->lineOf([tree->outline() itemAtRow:row]);
  if(!l) return;
  Ui::Node node = tree->tree().node(l->path);
  if(node.pick) node.pick([b state] == NSControlStateValueOn);
  std::function<void()> after = tree->after();
  if(after) after();
}

// the name after the widget of a line, which one presses
- (void)named:(id)sender
{
  if(!tree || !tree->tree().node) return;
  NSInteger row = [tree->outline() rowForView:sender];
  if(row < 0) return;
  cocoaTree::line *l = tree->lineOf([tree->outline() itemAtRow:row]);
  if(!l) return;
  Ui::Node node = tree->tree().node(l->path);
  if(!node.pressed) return;
  std::function<void()> what = node.pressed, after = tree->after();
  cocoaLater([what, after]() {
    what();
    if(after) after();
  });
}

@end

cocoaTree::cocoaTree(const Ui::Tree &tree, bool picks,
                     const std::function<void()> &after)
  : _tree(tree), _picks(picks), _after(after), _built(0), _everBuilt(false),
    _quiet(false)
{
  _source = [[GmshTreeSource alloc] init];
  _source->tree = this;
  GmshOutlineView *o =
    [[GmshOutlineView alloc] initWithFrame:NSMakeRect(0, 0, 200, 300)];
  o->tree = this;
  _outline = o;
  NSTableColumn *c = [[NSTableColumn alloc] initWithIdentifier:@"tree"];
  [c setResizingMask:NSTableColumnAutoresizingMask];
  [c setWidth:200.];
  [_outline addTableColumn:c];
  [_outline setOutlineTableColumn:c];
  [_outline setHeaderView:nil];
  // the one column as wide as the outline
  [_outline
    setColumnAutoresizingStyle:NSTableViewLastColumnOnlyAutoresizingStyle];
  [_outline setIndentationPerLevel:cocoaPx(1.1)];
  [_outline setAutoresizesOutlineColumn:NO];
  [_outline setIntercellSpacing:NSMakeSize(0., 0.)];
  if(@available(macOS 11.0, *)) [_outline setStyle:NSTableViewStylePlain];
  [_outline setSelectionHighlightStyle:NSTableViewSelectionHighlightStyleNone];
  [_outline setFocusRingType:NSFocusRingTypeNone];
  [_outline setDataSource:_source];
  [_outline setDelegate:_source];
  [_outline setTarget:_source];
  [_outline setAction:@selector(clicked:)];
  _scroll = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 200, 300)];
  [_scroll setDocumentView:_outline];
  [_scroll setHasVerticalScroller:YES];
  [_scroll setAutohidesScrollers:YES];
  [_scroll setBorderType:picks ? NSBezelBorder : NSNoBorder];
  refresh(true);
}

cocoaTree::~cocoaTree()
{
  // the scroll view is its holder's; the outline stops asking
  _source->tree = nullptr;
  ((GmshOutlineView *)_outline)->tree = nullptr;
  [_outline setDataSource:nil];
  [_outline setDelegate:nil];
  _clear(_top);
}

void cocoaTree::_clear(std::vector<line *> &lines)
{
  for(line *l : lines) {
    _clear(l->kids);
    if(l->item) ((GmshTreeItem *)l->item)->line = nullptr;
    delete l;
  }
  lines.clear();
}

cocoaTree::line *cocoaTree::lineOf(id item)
{
  if(!item || ![item isKindOfClass:[GmshTreeItem class]]) return nullptr;
  return ((GmshTreeItem *)item)->line;
}

void cocoaTree::_branch(std::vector<line *> &into, const std::string &path)
{
  if(!_tree.children || !_tree.node) return;
  bool commands = cocoaSources().settings().showModuleMenu;
  for(const std::string &child : _tree.children(path)) {
    if(path.empty() && child == "0Modules" && !commands && !_picks) continue;
    line *l = new line;
    l->path = child;
    l->node = _tree.node(child);
    l->branch = !_tree.children(child).empty();
    GmshTreeItem *item = [[GmshTreeItem alloc] init];
    item->line = l;
    l->item = item;
    into.push_back(l);
  }
}

void cocoaTree::fill(line *l)
{
  if(!l || l->filled) return;
  l->filled = true;
  _branch(l->kids, l->path);
}

NSView *cocoaTree::viewFor(line *l)
{
  // made once: the outline may ask again as the row comes back into view
  static const char viewKey = 0;
  if(!l) return nil;
  GmshTreeItem *item = (GmshTreeItem *)l->item;
  NSView *made = objc_getAssociatedObject(item, &viewKey);
  if(made) return made;
  const Ui::Node &node = l->node;
  std::string label = _labelOf(node, l->path);
  GmshTreeRow *row =
    [[GmshTreeRow alloc] initWithFrame:NSMakeRect(0, 0, 200, 20)];
  [row setAutoresizesSubviews:YES];
  if(_picks) {
    NSButton *b = [NSButton checkboxWithTitle:cocoaString(label)
                                       target:_source
                                       action:@selector(picked:)];
    [b setFont:cocoaFont()];
    [b setState:node.picked && node.picked() ? NSControlStateValueOn :
                                               NSControlStateValueOff];
    l->field = b;
    row->name = b;
    [row addSubview:b];
  }
  else if(!l->branch && node.hasField) {
    NSView *w = cocoaFieldWidget(node.field, _after);
    if(w) {
      row->widget = w;
      [row addSubview:w];
      l->field = w;
    }
    if(node.label.size()) {
      NSView *name;
      if(node.pressed) {
        NSButton *b = [NSButton buttonWithTitle:cocoaString(label)
                                         target:_source
                                         action:@selector(named:)];
        [b setBordered:NO];
        [b setAlignment:NSTextAlignmentLeft];
        [b setFont:cocoaFont()];
        name = b;
      }
      else
        name = cocoaLabel(label, false);
      row->name = name;
      [row addSubview:name];
    }
  }
  else {
    NSTextField *t = cocoaLabel(label, false);
    [row setTextField:t];
    row->name = t;
    [row addSubview:t];
  }
  if(node.tooltip.size() && cocoaSources().settings().tooltips)
    [row setToolTip:cocoaString(node.tooltip)];
  if(node.enabled && !node.enabled()) {
    [row setAlphaValue:.5];
    if(l->field && [l->field isKindOfClass:[NSControl class]])
      [(NSControl *)l->field setEnabled:NO];
  }
  [row resizeSubviewsWithOldSize:NSZeroSize];
  objc_setAssociatedObject(item, &viewKey, row,
                           OBJC_ASSOCIATION_RETAIN_NONATOMIC);
  return row;
}

void cocoaTree::expanded(line *l, bool open)
{
  if(_quiet || !_tree.setClosed) return;
  _tree.setClosed(l->path, !open);
}

void cocoaTree::_expandWanted(const std::vector<line *> &lines)
{
  for(line *l : lines) {
    if(!l->branch) continue;
    // as the FLTK tree has it: the modules folded under their root -- a
    // branch is made when first opened, so always -- the rest open unless
    // the description folds it; the tree of a field folded
    bool open = !l->node.closed && !(_tree.closed && _tree.closed(l->path)) &&
                !_picks && l->path.compare(0, 9, "0Modules/") != 0;
    for(auto w = _wanted.begin(); w != _wanted.end(); ++w)
      if(w->first == l->path) {
        open = w->second;
        _wanted.erase(w);
        break;
      }
    if(open) {
      [_outline expandItem:l->item];
      _expandWanted(l->kids);
    }
  }
}

void cocoaTree::_build()
{
  // what was open stays open
  std::vector<line *> todo = _top;
  while(!todo.empty()) {
    line *l = todo.back();
    todo.pop_back();
    if(l->branch && l->filled) {
      bool asked = false;
      for(auto &w : _wanted)
        if(w.first == l->path) asked = true;
      if(!asked)
        _wanted.push_back(std::make_pair(
          l->path, [_outline isItemExpanded:l->item] ? true : false));
    }
    for(line *k : l->kids) todo.push_back(k);
  }
  _quiet = true;
  std::vector<line *> old;
  old.swap(_top);
  _branch(_top, "");
  [_outline reloadData];
  [_outline sizeLastColumnToFit];
  _expandWanted(_top);
  _clear(old);
  _quiet = false;
  _wanted.clear();
}

void cocoaTree::refresh(bool rebuild)
{
  unsigned generation = _tree.generation ? _tree.generation() : 0;
  if(rebuild || !_everBuilt || generation != _built) {
    _everBuilt = true;
    _built = generation;
    _build();
  }
  if(!_tree.node) return;
  _quiet = true;
  std::vector<line *> todo = _top;
  while(!todo.empty()) {
    line *l = todo.back();
    todo.pop_back();
    for(line *k : l->kids) todo.push_back(k);
    l->node = _tree.node(l->path);
    const Ui::Node &node = l->node;
    bool on = node.enabled ? node.enabled() : true;
    if(l->field) {
      if(_picks)
        [(NSButton *)l->field setState:node.picked && node.picked() ?
                                         NSControlStateValueOn :
                                         NSControlStateValueOff];
      else {
        cocoaRebindField(l->field, node.field);
        cocoaRefreshField(l->field);
      }
      NSView *row = [l->field superview];
      [row setAlphaValue:on ? 1. : .5];
      if(!node.field.enabled && [l->field isKindOfClass:[NSControl class]])
        [(NSControl *)l->field setEnabled:on ? YES : NO];
    }
  }
  _quiet = false;
}

cocoaTree::line *cocoaTree::_find(const std::string &path) const
{
  std::vector<line *> todo = _top;
  while(!todo.empty()) {
    line *l = todo.back();
    todo.pop_back();
    if(l->path == path) return l;
    for(line *k : l->kids) todo.push_back(k);
  }
  return nullptr;
}

void cocoaTree::open(const std::string &path, bool open)
{
  if(open) {
    std::size_t at = 0;
    while((at = path.find('/', at + 1)) != std::string::npos)
      if(line *up = _find(path.substr(0, at))) [_outline expandItem:up->item];
  }
  if(line *l = _find(path)) {
    if(open)
      [_outline expandItem:l->item];
    else
      [_outline collapseItem:l->item];
    return;
  }
  for(auto &w : _wanted)
    if(w.first == path) {
      w.second = open;
      return;
    }
  _wanted.push_back(std::make_pair(path, open));
}

bool cocoaTree::isOpen(const std::string &path) const
{
  if(line *l = _find(path))
    return [_outline isItemExpanded:l->item] ? true : false;
  for(auto &w : _wanted)
    if(w.first == path) return w.second;
  return false;
}

#endif
