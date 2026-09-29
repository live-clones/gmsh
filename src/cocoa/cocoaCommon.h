// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef COCOA_COMMON_H
#define COCOA_COMMON_H

#include <functional>
#include <string>
#include <vector>

#import <Cocoa/Cocoa.h>

#include "Backend.h"
#include "Layout.h"
#include "Tree.h"

// What the files of the Cocoa interface share: the descriptions it was
// handed, the menus, the widget of a field, the tree, and the scene the main
// window holds. Objective-C++ with ARC: a C++ object holding an AppKit one
// keeps it alive, and what an AppKit control calls back is a block or a
// small target object that carries a std::function. Nothing here calls Gmsh
// but the scene.

const Ui::Backend::Sources &cocoaSources();
const Ui::Backend::Host &cocoaHost();

inline NSString *cocoaString(const std::string &s)
{
  NSString *said = [[NSString alloc] initWithBytes:s.data()
                                            length:s.size()
                                          encoding:NSUTF8StringEncoding];
  return said ? said : @"";
}
inline std::string cocoaString(NSString *s)
{
  if(!s) return std::string();
  const char *utf8 = [s UTF8String];
  return utf8 ? std::string(utf8) : std::string();
}

// run once the event being handled is over: what it does may open a window,
// start a picking or build the widget it came from again
void cocoaLater(const std::function<void()> &what);
// an event at the end of the queue, so that a loop waiting for one wakes up
void cocoaWake();

// held anywhere: the scene, and a value dragged in a dialog, ask
bool cocoaButtonDown();

// --- keys: false for a key Ui::Shortcut has no name for
bool cocoaUiKey(NSEvent *event, int &key, unsigned &mods);
// a key nothing took, in any window: the shortcuts of Sources::keys
bool cocoaMainKey(NSEvent *event);

// --- menus: every entry runs its action with cocoaLater()

NSMenu *cocoaMenu(const std::vector<Ui::MenuItem> &items, NSString *title);
// the menu bar at the top of the screen, made again when the description
// changed
void cocoaRefreshMenuBar();
// at the pointer
void cocoaPopupMenu(const std::vector<Ui::MenuItem> &items);

// --- the size of the font of the interface, in points, which the widths the
// descriptions give are in
double cocoaEm();
CGFloat cocoaPx(double em);
NSFont *cocoaFont();
NSFont *cocoaFixedFont(CGFloat size);
// the height of a line of widgets
CGFloat cocoaRowHeight();
// what the placement of a form is measured with
Ui::Metrics cocoaMetrics();
// a widget put in the room placed for it: what AppKit draws about a control
// (a push button's shadow) is outside it, and a widget shorter than its line
// sits in the middle of it
void cocoaPlace(NSView *view, NSRect room, bool tall);

// the containers are all drawn from the top down, as the placement is
@interface GmshFlippedView : NSView
@end

// --- a picture of Glyph.h one em square, a template image AppKit draws in
// the colour of the button's text (the colour map, whose strokes have their
// own colours, as it is); nil for a name no glyph has
NSImage *cocoaGlyph(const std::string &name);
// a button shows the picture when there is one, the label otherwise
void cocoaButtonShows(NSButton *button, const std::string &label,
                      const std::string &glyph);

// --- the widget of one field, bound to the place its value lives; `after`
// is what the holder does once the user changed something

NSView *cocoaFieldWidget(const Ui::Field &field,
                         const std::function<void()> &after);
void cocoaRefreshField(NSView *widget);
void cocoaRebindField(NSView *widget, const Ui::Field &field);
NSView *cocoaButtonWidget(const Ui::Button &button,
                          const std::function<void()> &after);
// a label the placement put beside a widget
NSTextField *cocoaLabel(const std::string &text, bool alert);
// the page of prose of a field, as it is written that wide
CGFloat cocoaProseHeight(const Ui::Field &field, CGFloat width);

// --- a tree whose lines are fields (Tree.h): the modules, and a Hierarchy
// field, whose lines are switches

@class GmshTreeSource;

class treeCocoa {
public:
  treeCocoa(const Ui::Tree &tree, bool picks,
            const std::function<void()> &after);
  ~treeCocoa();
  // the scroll view holding the outline
  NSScrollView *widget() { return _scroll; }
  void setTree(const Ui::Tree &tree) { _tree = tree; }
  void refresh(bool rebuild);
  void open(const std::string &path, bool open);
  bool isOpen(const std::string &path) const;

  // --- what the source of the outline asks
  struct line {
    std::string path;
    Ui::Node node;
    bool branch = false, filled = false;
    std::vector<line *> kids;
    id item = nil; // what the outline knows the line by
    NSView *field = nil; // the widget of the field it holds
  };
  const Ui::Tree &tree() const { return _tree; }
  bool picks() const { return _picks; }
  bool quiet() const { return _quiet; }
  const std::function<void()> &after() const { return _after; }
  std::vector<line *> &top() { return _top; }
  line *lineOf(id item);
  void fill(line *l);
  NSView *viewFor(line *l);
  void expanded(line *l, bool open);
  NSOutlineView *outline() { return _outline; }

private:
  Ui::Tree _tree;
  bool _picks;
  std::function<void()> _after;
  NSScrollView *_scroll;
  NSOutlineView *_outline;
  GmshTreeSource *_source;
  unsigned _built;
  bool _everBuilt, _quiet;
  std::vector<line *> _top;
  std::vector<std::pair<std::string, bool>> _wanted;
  void _build();
  void _clear(std::vector<line *> &lines);
  void _branch(std::vector<line *> &into, const std::string &path);
  void _expandWanted(const std::vector<line *> &lines);
  line *_find(const std::string &path) const;
};

// --- the described forms, see dialogCocoa.mm: each a panel of its own

void cocoaShowForm(const Ui::Form &form, bool show);
bool cocoaFormVisible(const Ui::Form &form);
std::string cocoaFormPane(const Ui::Form &form);
void cocoaSetFormPane(const Ui::Form &form, const std::string &pane);
void cocoaReloadForm(const Ui::Form &form);
void cocoaDropForm(const Ui::Form &form);
void cocoaFormOptionChanged(const std::string &name);
void cocoaFormsClosingDown();
NSWindow *cocoaMainWindow();

// --- the scene, see SceneCocoa.mm

NSView *cocoaSceneWidget();
void cocoaSceneRedraw();
void cocoaSceneSize(int &width, int &height);
void cocoaSceneNewWindow();
void cocoaSceneDestroy();
void cocoaSceneStartTimers();
bool cocoaSceneDrawing();

void cocoaRefreshBar();

#endif
