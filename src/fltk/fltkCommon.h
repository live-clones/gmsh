// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FLTK_COMMON_H
#define FLTK_COMMON_H

#include "GmshConfig.h"

#include <cstdio>
#include <deque>
#include <functional>
#include <string>
#include <vector>

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Window.H>

#include "Backend.h"
#include "Form.h"
#include "Layout.h"
#include "MapEditor.h"
#include "Menu.h"
#include "Tree.h"

// What the files of the FLTK interface share: the descriptions it was handed,
// the menus, the widgets of a field, the tree, the forms and the scene the
// main window holds. FLTK, nothing else; nothing here calls Gmsh but the
// scene.

const Ui::Backend::Sources &fltkSources();
const Ui::Backend::Host &fltkHost();

// run once the event being handled is over: what it does may open a window,
// start a picking or build again the widget it came from
void fltkLater(const std::function<void()> &what);
// held anywhere: the scene, and a value dragged in a dialog, ask
bool fltkButtonDown();
// the loop turned once, now, unless another thread holds the interface; at
// most once every 1 / refreshRate seconds when rate limited
void fltkCheck(bool rateLimited = false);
bool fltkLocked();

// --- the keys as Ui::Shortcut says them, from the event being handled; a
// digit or a mark is the one typed, whatever key gives it on this keyboard
// (Shift, on a French one)
bool fltkUiKey(int &key, unsigned &mods);
// a key the widget it went to does not take: the shortcuts of Sources::keys;
// true when one was
bool fltkMainKey();

// --- the size of things, all from the size of the type: the width of an
// input and of a button, the height of a line, the border of a window; and
// the box types the windows draw themselves with
#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define GMSH_SIMPLE_RIGHT_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 1)
#define GMSH_SIMPLE_TOP_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 2)
#define IW (10 * FL_NORMAL_SIZE) // input field width
#define BB (7 * FL_NORMAL_SIZE) // width of a button with internal label
#define BH (2 * FL_NORMAL_SIZE + 1) // button height
#define WB (5) // window border

// --- a window of the interface other than the main one: Escape and the key
// of the system (Cmd+W, Alt+F4, Ctrl+W) close it, as its button does
class paletteWindow : public Fl_Double_Window {
public:
  paletteWindow(int w, int h, bool nonModal, const char *l = nullptr)
    : Fl_Double_Window(w, h, l)
  {
    if(nonModal) set_non_modal();
  }
  int handle(int event) override;
  void show() override;
};

// --- menus: an entry runs its action at once, as FLTK calls back after the
// menu is down

// the table stays valid until the next call: pass it to menu() straight away;
// systemBar for macOS, which has no mnemonics and its own Quit
Fl_Menu_Item *fltkMenuBar(bool systemBar);
// what is checked and greyed, read just before the menu is shown
void fltkRefreshMenus();
// opens under the entry picked last time; key names the menu, so that two do
// not share that memory
void fltkPopupMenu(const std::vector<Ui::MenuItem> &tree, int x, int y,
                   const std::string &key = "");

// a button that drops a menu
class popupButtonFltk : public Fl_Button {
public:
  std::function<std::vector<Ui::MenuItem>()> what;
  std::string key;
  popupButtonFltk(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Button(x, y, w, h, l)
  {
  }
  int handle(int event) override
  {
    if(event == FL_PUSH && what) {
      fltkPopupMenu(what(), Fl::event_x(), Fl::event_y(), key);
      return 1;
    }
    return Fl_Button::handle(event);
  }
};

// refreshed before it opens: the check marks would show the state of the last
// build
class menuBarFltk : public Fl_Menu_Bar {
public:
  menuBarFltk(int x, int y, int w, int h) : Fl_Menu_Bar(x, y, w, h) {}
  int handle(int event) override
  {
    if(event == FL_PUSH || event == FL_SHORTCUT) fltkRefreshMenus();
    return Fl_Menu_Bar::handle(event);
  }
};

// --- the widgets of a field, see fieldFltk.cpp

// a number as every interface shows it (Ui::numberText): with the decimals
// of its step, the step being set when values are dragged
class numberFltk : public Fl_Value_Input {
public:
  numberFltk(int x, int y, int w, int h) : Fl_Value_Input(x, y, w, h) {}
  int format(char *buffer) override
  {
    return snprintf(buffer, 128, "%s", Ui::numberText(value(), step()).c_str());
  }
};

// a point on the unit sphere, dragged in a disc
class discFltk : public Fl_Widget {
  double _x, _y, _z;
  void draw() override;

public:
  discFltk(int x, int y, int w, const char *l = nullptr);
  int handle(int event) override;
  void setValue(double x, double y, double z);
  void getValue(double &x, double &y, double &z) const;
};

// the colour map of a view, edited with the mouse and the keys: the editor
// is Ui::MapEditor, what it edits described by Ui::ColourMap
class colourMapFltk : public Fl_Window {
  Ui::MapEditor _edit;
  Ui::ColourMap _map;
  std::string _name;
  double _min, _max;
  bool *_changed;
  // the entry, the intensity and the part of the picture under x, y
  void _at(int x, int y, int &entry, int &value, bool &onWedge);

public:
  colourMapFltk(int x, int y, int w, int h, const char *l = nullptr);
  void draw() override;
  int handle(int event) override;
  void update(const char *name, double min, double max,
              const Ui::ColourMap &map, bool *changed);
};

// the widget one line of the tree carries: the value itself, then the little
// buttons hung after it. The field is copied and kept: FLTK hands a widget a
// pointer when it calls back, and what it points at has to outlive the line
Fl_Group *fltkTreeField(const Ui::Field &f, int x, int y, int w, int h,
                        double labelRatio, const Ui::Colour &highlight,
                        Fl_Color background);
// the tree is being built again: what was kept for the old lines may go
void fltkForgetTreeFields();

// --- a tree whose lines are fields (Tree.h): the modules, with the buttons
// the description puts under it
class treeFltk : public Fl_Group {
  Fl_Tree *_tree;
  std::vector<Fl_Widget *> _treeWidgets;
  // the buttons under the tree, made again from the description each time
  std::vector<Fl_Widget *> _footer;
  double _baseWidth, _indent;
  int _minWindowWidth, _minWindowHeight;
  double _widgetLabelRatio;
  bool _enableTreeWidgetResize;
  bool _firstBuild;
  void _computeWidths();
  // what one line holds: the field the description gives it, or a button
  // that presses it, and the menu it drops at its right end
  void _addLine(const std::string &path, const Ui::Node &node, bool branch);
  void _addFooter();
  static void _treeCallback(Fl_Widget *w, void *data);

public:
  treeFltk(int x, int y, int w, int h, const char *l = nullptr);
  void rebuild(bool deleteWidgets);
  void rebuildFooter();
  void enableTreeWidgetResize(bool value) { _enableTreeWidgetResize = value; }
  void open(const std::string &path, bool open);
  bool isOpen(const std::string &path);
  int minWindowWidth() { return _minWindowWidth; }
  int minWindowHeight() { return _minWindowHeight; }
  std::string pathOf(Fl_Tree_Item *item);
};

// --- the described forms, see dialogFltk.cpp
void fltkShowForm(const Ui::Form &form, bool show);
bool fltkFormVisible(const Ui::Form &form);
std::string fltkFormPane(const Ui::Form &form);
void fltkSetFormPane(const Ui::Form &form, const std::string &pane);
void fltkReloadForm(const Ui::Form &form);
void fltkDropForm(const Ui::Form &form);
void fltkFormOptionChanged(const std::string &name);
// taken down: hiding a form is not the user closing it, and nothing is undone
void fltkFormsClosingDown();
// where the first form shown is, for the layout; false with none
bool fltkFormPosition(int &x, int &y);
// every form shown brought to the front
void fltkFormsToFront();

// --- the scene, see SceneFltk.cpp: its views on GuiPanes, from before the
// first window is made to after the last is gone
void fltkSceneStart();
void fltkSceneStop();
// the views of the main window, tiled in the box made here
Fl_Group *fltkSceneBox(int x, int y, int w, int h);
void fltkSceneSize(int &width, int &height);
void fltkSceneFocus();
void fltkSceneNewWindow();
// the windows of their own the views are in, iconised or shown again
void fltkSceneWindows(bool show);
// the text engine the options say
void fltkFontEngine();

// --- the bar along the bottom of the main window and of every graphic window
// of its own, see BackendFltk.cpp: its buttons and the message, which one
// presses to show the messages
Fl_Group *fltkMakeBar(int x, int y, int w, int h);
void fltkDropBar(Fl_Group *bar);
void fltkRefreshBar();
int fltkBarHeight();
Fl_Window *fltkMainWindow();

#endif
