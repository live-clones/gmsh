// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <vector>

class drawContext;

// The action registry: the menus of the interfaces (the graphical interface
// in src/fltk, the web page in contrib/webapp) and what their items do, said
// once in Actions.cpp:
// - the menus are a tree of items, the buttons of the Geometry and Mesh
//   modules included (a module is a menu shown as rows of buttons);
// - the actions of the items are in one table, each one done there or, if it
//   shows something of an interface (a window, a file chooser), by each
//   interface: an interface that does not have one leaves its items out.
// To add an item, add it to its menu; to add an action, also add it to the
// table (and, if the interfaces do it, to each of them).

// what an item does
enum actionKind {
  ActionMenu, // shows its items: a submenu (a heading on the web page), or a
              // group of items set apart if it has no label
  ActionRun, // an action of the table, by its name
  ActionOperation, // an operation on the entities picked in the scene (see
                   // selectionDriver), done by the interface
  ActionShape, // a shape added from the values of its fields (see
               // scriptShapes()), by the interface
  ActionOption // an option toggled ("Mesh.Nodes", a check box) or set
               // ("View.IntervalsType=3", a radio item); View.* is the option
               // of the visible views
};

// a value asked for once an item is picked, with a slider: of the option
// (as "View.NbIso"), from min to max by step, these in units of the size of
// the model per largest value of the visible views if perValue
struct actionAsk {
  std::string option;
  double min, max, step;
  bool perValue;
};

struct actionItem {
  std::string label;
  actionKind kind;
  // the action, operation, shape or option ("" for an option only asked for)
  std::string what;
  std::vector<actionItem> items; // of a menu
  std::string help; // a tooltip
  // the keyboard shortcut shown (an action of Shortcuts.h), which must do
  // what the item does
  std::string key;
  actionAsk ask; // asked for if ask.option is not empty
};

// a menu: "Geometry", "Mesh" (the modules), "Quick access" (the menu of the
// scene), "View" (the menu of a view)
const actionItem &GetActionMenu(const std::string &name);

// what RunAction() returns, as bits
enum actionResult {
  ActionNotHere = 0, // done by the interface
  ActionDone = 1,
  ActionViewsChanged = 2, // views added or removed: their list made again
  ActionModelChanged = 4 // entities added or removed
};

// whether the interface does what an item does (an operation, a shape, an
// action of the table it does)
bool IsDoneByInterface(const actionItem &item);

// what an item does, done here: view, the index of the view of a menu of a
// view; ctx, the scene the point of view is of
int RunAction(const actionItem &item, int view = -1,
              drawContext *ctx = nullptr);

// whether an item applies now (those on views need views, ...)
bool IsActionAvailable(const actionItem &item);

// the check mark of an item: -1 for none, 0 or 1 for a check box or a radio
// item (an action the interface does gives its own)
int GetActionCheck(const actionItem &item);

// what to ask: the bounds of the slider and the value of the option now
void GetActionAsk(const actionAsk &ask, double &min, double &max, double &step,
                  double &value);

// an option set, as an item sets it
void SetActionOption(const std::string &option, double value);

#endif
