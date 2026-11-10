// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ACTIONS_H
#define ACTIONS_H

#include <functional>
#include <string>
#include <vector>

class drawContext;

// The menus of Gmsh's two interfaces, the graphical interface (src/fltk) and
// the web page (contrib/webapp), each item with what it does, in one place:
// Actions.cpp. The Geometry and Mesh modules are menus too, shown as rows of
// buttons.
//
// A click on an item, or a key (which runs the item of its name), goes to one
// function of each interface, runItem(), which does what the item is:
//
//                            desktop (actionMenus.cpp)  web (onelab.html)
//   click ─┐
//   key   ─┴─> runItem(item)
//               ├─ an action of Gmsh   RunItem(), here, then the interface
//               │                      shows what it changed
//               ├─ an operation        runOperation()       startOperation()
//               ├─ a shape             addShape()           showShapeForm()
//               └─ an action of the    fltkActions()        pageActions
//                  interface
//
// The items, as Actions.cpp makes them:
//   action("2D", "mesh_2d", "Mesh the surfaces",     Gmsh does it
//          [](int view, drawContext *ctx) { ... })
//   guiAction("Size fields", "mesh_size_fields")     the interfaces do it
//   option("Nodes", "Mesh.Nodes")                    a check box
//   option("Iso-values", "View.IntervalsType=1")     a radio item
//   operation("Union", "boolean_union")              on entities picked
//   shape("Box", "add_box")                          from the values of a form
//   menu("Delete", "help", {...}), group({...})      a submenu, a group
//
// Names are keys, in snake case, starting with what they act on ("mesh_2d",
// "views_remove_all", "boolean_union", "add_box"; an option is named as the
// option). A keyboard shortcut (see Shortcuts.h) has the name of the item it
// runs, and the item shows it. What the user reads is the label of an item,
// never its name.
//
// How to add...
// - Something Gmsh does: an action() in its menu in Actions.cpp, or in
//   keysOnly() for a key in no menu. Nothing else to do.
// - Something an interface shows (a window, a file chooser): a guiAction() in
//   its menu, and what it does in each interface: in fltkActions() on the
//   desktop (its parts listedFltkActions() in actionMenus.cpp, menuBarActions()
//   in graphicWindow.cpp, keyboardActions() in FlGui.cpp), and in pageActions
//   in onelab.html. An interface without it does not show the item.
// - An option: option(), or presets() for a submenu of its values.
// - A key: E("mesh_2d", {'2'}, "Mesh surfaces") in GetShortcuts()
//   (Shortcuts.cpp), named as its item.
// - An operation: what it picks and writes in the script, in the constructor
//   of selectionDriver, then its operation() item. The web page makes its
//   form from its fields; the desktop reads them from its context windows
//   (dialogValue() in actionMenus.cpp), where a new field needs a widget.
// - A shape: in scriptShapes() and scriptAddShape()
//   (scriptStringInterface.cpp), then its shape() item. The desktop places it
//   with the mouse or from a pane of its elementary context window
//   (contextWindow.cpp), the web page from a form.

// The kind of an item: a menu (or, without label, a group set apart), an
// action (its run, or the interface's if it has none), an operation on the
// entities picked in the scene (see selectionDriver), or a shape added from
// the values of its fields (see scriptShapes()); the interface runs the last
// two
enum itemKind { ItemMenu, ItemAction, ItemOperation, ItemShape };

// What an action does in Gmsh: view is the index of the view whose menu it is
// in (-1 otherwise), ctx the scene whose point of view it changes
typedef std::function<void(int view, drawContext *ctx)> actionFunction;

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
  // for an action: what it does (empty if the interfaces do it), when it
  // applies (always if empty), and its check mark (none if empty)
  actionFunction run;
  std::function<bool()> available;
  std::function<int()> check;
};

// The menu with the given name: "Geometry" and "Mesh" (the modules), "Quick
// access" (the menu of the scene), "View" (the menu of a view), "Menu bar"
// (the menu bar of the graphical interface), or "Keys" (the actions of the
// keys in no menu, which no interface shows)
const actionItem &GetActionMenu(const std::string &name);

// What RunItem() returns, as bits: ActionByInterface if the interface does
// the item, ActionDone otherwise, with what the action changed (found by
// RunItem(), not told by the action), for the interface to show it: views
// added, removed or read again, entities added or removed
enum actionResult {
  ActionByInterface = 0,
  ActionDone = 1,
  ActionViewsChanged = 2,
  ActionModelChanged = 4
};

// Whether an item of the menus, or of keysOnly(), has an action with this
// name (as a shortcut that runs one, see Shortcuts.h)
bool HasAction(const std::string &name);

// Whether the interface does what an item does: an operation, a shape, or an
// action without code (a guiAction())
bool IsItemDoneByInterface(const actionItem &item);

// Do what an item does. For the menu of a view, view is the index of that
// view; ctx is the scene whose point of view an action changes.
int RunItem(const actionItem &item, int view = -1, drawContext *ctx = nullptr);

// Do the action with this name, as an item of it does (from a shortcut, for
// instance)
int RunAction(const std::string &name, int view = -1,
              drawContext *ctx = nullptr);

// Whether an item applies now (an item on views needs views, for instance)
bool IsItemAvailable(const actionItem &item);

// The check mark of an item: -1 for none, or 0 or 1 for a check box or a radio
// item (for an action the interface does, the interface gives it)
int GetItemCheck(const actionItem &item);

#endif
