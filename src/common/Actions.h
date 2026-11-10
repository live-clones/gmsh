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
// To add an item, add it to its menu. An action done here is added to the
// table; one an interface does is added to the interface (fltkActions() on
// the desktop), and an interface that does not have it leaves its items out.
//
// The names of the actions, the operations and the shapes are keys, in snake
// case, starting with what they act on: "mesh_2d", "views_remove_all",
// "script_edit_py", "options_general"; "add_line", "boolean_union",
// "physical_add_point", "define_embed_curve", "mesh_delete_surfaces";
// "add_point", "add_box". They are shared with the keyboard shortcuts (see
// Shortcuts.h): an item shows the shortcut of its name, and a shortcut runs
// the action of its name. What the user reads is the label of an item (and
// the menus it is in), never its name.

// The kind of an item, which says what it does:
// - ItemMenu shows its items: as a submenu, or, if it has no label, as a
//   group of items set apart from the others;
// - ItemAction runs the action of the table of the given name;
// - ItemOperation starts an operation on the entities picked in the scene
//   (see selectionDriver), which the interface runs;
// - ItemShape adds a shape from the values of its fields (see
//   scriptShapes()), which the interface asks for;
// - ItemOption toggles an option ("Mesh.Nodes", shown as a check box) or
//   sets it to a value ("View.IntervalsType=3", shown as a radio item); a
//   View.* option applies to the visible views.
enum itemKind { ItemMenu, ItemAction, ItemOperation, ItemShape, ItemOption };

// An item of a menu
struct actionItem {
  std::string label;
  itemKind kind;
  // the name of the action, operation, shape or option
  std::string name;
  // the items of a menu
  std::vector<actionItem> items;
  // the tooltip
  std::string help;
  // the keyboard shortcut shown next to the label (the name of an action of
  // Shortcuts.h), which must do what the item does; not needed for an action
  // that has a shortcut of the same name, which is shown
  std::string shortcut;
};

// The menu with the given name: "Geometry" and "Mesh" (the modules), "Quick
// access" (the menu of the scene), "View" (the menu of a view) or "Menu bar"
// (the menu bar of the graphical interface)
const actionItem &GetActionMenu(const std::string &name);

// What RunItem() returns, as bits: ActionByInterface if the interface does the
// action, ActionDone otherwise, with ActionViewsChanged if views were added or
// removed (the interface then rebuilds its list of views) and
// ActionModelChanged if entities were added or removed.
enum actionResult {
  ActionByInterface = 0,
  ActionDone = 1,
  ActionViewsChanged = 2,
  ActionModelChanged = 4
};

// Whether the table has an action with this name (as a shortcut that runs
// one, see Shortcuts.h)
bool HasAction(const std::string &name);

// Whether the interface does what an item does: an operation, a shape, or an
// action of the table that the interfaces do
bool IsItemDoneByInterface(const actionItem &item);

// Do what an item does. For the menu of a view, view is the index of that
// view; ctx is the scene whose point of view an action changes.
int RunItem(const actionItem &item, int view = -1, drawContext *ctx = nullptr);

// Whether an item applies now (an item on views needs views, for instance)
bool IsItemAvailable(const actionItem &item);

// The check mark of an item: -1 for none, or 0 or 1 for a check box or a radio
// item (for an action the interface does, the interface gives it)
int GetItemCheck(const actionItem &item);

#endif
