// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GTK_COMMON_H
#define GTK_COMMON_H

#include <functional>
#include <string>
#include <vector>

#include <gtk/gtk.h>

#include "Backend.h"
#include "Tree.h"

// What the files of the GTK 4 interface share: the descriptions it was handed,
// the menus, the widget of a field, the tree, and the scene the main window
// holds. Nothing here calls Gmsh but the scene.

// the descriptions this interface builds from, handed to it once; named after
// the interface, since every one built is in the library at once
const Ui::Backend::Sources &gtkSources();
const Ui::Backend::Host &gtkHost();

// run once the event being handled is over: what it does may open a window,
// start a picking or build the widget it came from again, each of which runs
// or needs a loop of its own
void gtkLater(const std::function<void()> &what);

// held anywhere: the scene, and a value dragged in a dialog, ask
bool gtkButtonDown();
// a window of the interface tells the count of the buttons held
void gtkWatchButtons(GtkWidget *window);

// --- the keys, as Ui::Shortcut says them; false for a key it has no name for

bool gtkUiKey(guint keyval, GdkModifierType state, int &key, unsigned &mods);
// a key nothing took, in any window: the shortcuts of Sources::keys
bool gtkMainKey(guint keyval, GdkModifierType state);

// --- menus: every entry runs its action with gtkLater()

// the bar of the main window, whose actions live on the window
GtkWidget *gtkMenuBar(GtkWidget *window);
// built again when the description changed; the switches and what is greyed
// are read again in any case
void gtkRefreshMenuBar();
// at x, y of the widget; x < 0 hangs it under the widget
void gtkPopupMenu(const std::vector<Ui::MenuItem> &items, GtkWidget *over,
                  double x, double y);

// --- the size of things: em is the size of the font of the interface, in
// pixels, which the widths the descriptions give are in

double gtkEm();
int gtkPx(double em);
// the fonts changed: measured again
void gtkForgetMetrics();

// --- the widget of one field, bound to the place its value lives. `after` is
// what the holder does once the user changed something: a dialog looks at the
// whole form again

GtkWidget *gtkFieldWidget(const Ui::Field &field,
                          const std::function<void()> &after);
// the value, the choices, what is greyed, put back in the widget
void gtkRefreshField(GtkWidget *widget);
// the same widget for a field of the same kind, described again
void gtkRebindField(GtkWidget *widget, const Ui::Field &field);
const Ui::Field *gtkFieldOf(GtkWidget *widget);
// a button after a field, or in a row of buttons
GtkWidget *gtkButtonWidget(const Ui::Button &button,
                           const std::function<void()> &after);

// --- a tree whose lines are fields (Tree.h): the modules, and a Hierarchy
// field; one that picks draws a switch in front of each line

class treeGtk {
public:
  treeGtk(const Ui::Tree &tree, bool picks,
          const std::function<void()> &after);
  ~treeGtk();
  GtkWidget *widget() { return _scroll; }
  void setTree(const Ui::Tree &tree) { _tree = tree; }
  // built again when the shape changed, or when asked; the values read again
  void refresh(bool rebuild);
  void open(const std::string &path, bool open);
  bool isOpen(const std::string &path) const;
  // for the handlers of the lines
  struct line;
  Ui::Node nodeOf(const std::string &path)
  {
    return _tree.node ? _tree.node(path) : Ui::Node();
  }
  void after()
  {
    if(_after) _after();
  }

private:
  Ui::Tree _tree;
  bool _picks;
  std::function<void()> _after;
  GtkWidget *_scroll, *_box;
  unsigned _built;
  bool _everBuilt, _firstBuild;
  std::vector<line *> _lines;
  // what was asked before the branch was there, and what each was when last
  // seen
  std::vector<std::pair<std::string, bool> > _wanted;
  void _build();
  void _branch(GtkWidget *into, const std::string &path, int depth);
  line *_find(const std::string &path) const;
  static void _expanded(GObject *expander, GParamSpec *, gpointer data);
};

// the buttons and the message of the bar along the bottom, as they are now
void gtkRefreshBar();

// --- the described forms, see dialogGtk.cpp

void gtkShowForm(const Ui::Form &form, bool show);
bool gtkFormVisible(const Ui::Form &form);
std::string gtkFormPane(const Ui::Form &form);
void gtkSetFormPane(const Ui::Form &form, const std::string &pane);
// the values, or the shape too
void gtkReloadForm(const Ui::Form &form, bool shape);
void gtkDropForm(const Ui::Form &form);
void gtkFormOptionChanged(const std::string &name);
void gtkFormsClosingDown();
// the dialogs are made transient for it
void gtkSetMainWindow(GtkWindow *window);
GtkWindow *gtkMainWindow();
// the box down the right of the main window the dialogs may be docked in,
// inside a scrolled window shown when one is
void gtkSetDock(GtkWidget *box);

// --- the scene, see SceneGtk.cpp: the panes of the main window

// the tiled panes of the main window, made at the first call
GtkWidget *gtkSceneWidget();
void gtkSceneRedraw();
// in the pixels of the widget
void gtkSceneSize(int &width, int &height);
void gtkSceneNewWindow();
// a view is being drawn: the loop is not to be pumped from inside
bool gtkSceneDrawing();
void gtkSceneDestroy();
// the gamepad and the animation, at the rate each asks
void gtkSceneStartTimers();

#endif
