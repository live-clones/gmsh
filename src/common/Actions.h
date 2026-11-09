// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <vector>

class drawContext;

// The action registry. Actions.cpp describes, in one place, the menus of the
// two interfaces (the graphical interface in src/fltk and the web page in
// contrib/webapp) and what their items do:
// - Each menu is a tree of items. The buttons of the Geometry and Mesh modules
//   are such menus too: a module is a menu shown as rows of buttons.
// - The actions of the items are in one table. Most actions are done in
//   Actions.cpp. An action that shows something of an interface (a window, a
//   file chooser) is done by each interface instead, and an interface that
//   cannot do it leaves its items out.
// To add an item, add it to its menu. To add an action, also add it to the
// table, and, if the interfaces do it, to each of them.

// The kind of an item, which says what it does:
// - ActionMenu shows its items: as a submenu (a heading on the web page), or,
//   if it has no label, as a group of items set apart from the others;
// - ActionRun runs the action of the table with the given name;
// - ActionOperation starts an operation on the entities picked in the scene
//   (see selectionDriver), which the interface runs;
// - ActionShape adds a shape from the values of its fields (see
//   scriptShapes()), which the interface asks for;
// - ActionOption toggles an option ("Mesh.Nodes", shown as a check box) or
//   sets it to a value ("View.IntervalsType=3", shown as a radio item); a
//   View.* option applies to the visible views.
enum actionKind {
  ActionMenu,
  ActionRun,
  ActionOperation,
  ActionShape,
  ActionOption
};

// A value asked for with a slider once an item is picked: the value of the
// option (e.g. "View.NbIso"), from min to max by step. If perValue is true,
// min, max and step are in units of the size of the model divided by the
// largest value of the visible views (for a displacement, say).
struct actionAsk {
  std::string option;
  double min, max, step;
  bool perValue;
};

// An item of a menu
struct actionItem {
  std::string label;
  actionKind kind;
  // the name of the action, operation, shape or option; empty for an item
  // that only asks for a value
  std::string what;
  // the items of a menu
  std::vector<actionItem> items;
  // the tooltip
  std::string help;
  // the keyboard shortcut shown next to the label (the name of an action of
  // Shortcuts.h), which must do what the item does; not needed for an action
  // that has a shortcut of the same name, which is shown
  std::string key;
  // the value asked for, if ask.option is not empty
  actionAsk ask;
};

// The menu with the given name: "Geometry" and "Mesh" (the modules), "Quick
// access" (the menu of the scene) or "View" (the menu of a view)
const actionItem &GetActionMenu(const std::string &name);

// What RunAction() returns, as bits: ActionNotHere if the interface does the
// action, ActionDone otherwise, with ActionViewsChanged if views were added or
// removed (the interface then rebuilds its list of views) and
// ActionModelChanged if entities were added or removed.
enum actionResult {
  ActionNotHere = 0,
  ActionDone = 1,
  ActionViewsChanged = 2,
  ActionModelChanged = 4
};

// Whether the table has an action with this name (as a shortcut that runs
// one, see Shortcuts.h)
bool IsAction(const std::string &name);

// Whether the interface does what an item does: an operation, a shape, or an
// action of the table that the interfaces do
bool IsDoneByInterface(const actionItem &item);

// Do what an item does. For the menu of a view, view is the index of that
// view; ctx is the scene whose point of view an action changes.
int RunAction(const actionItem &item, int view = -1,
              drawContext *ctx = nullptr);

// Whether an item applies now (an item on views needs views, for instance)
bool IsActionAvailable(const actionItem &item);

// The check mark of an item: -1 for none, or 0 or 1 for a check box or a radio
// item (for an action the interface does, the interface gives it)
int GetActionCheck(const actionItem &item);

// What to ask for: the bounds of the slider and the current value
void GetActionAsk(const actionAsk &ask, double &min, double &max, double &step,
                  double &value);

// Set an option, as an item does
void SetActionOption(const std::string &option, double value);

#endif
