// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GRAPHIC_WINDOW_H
#define GRAPHIC_WINDOW_H

#include <functional>
#include <map>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Progress.H>
#if defined(__APPLE__)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif
#include <FL/Fl_Menu_Bar.H>
#include "paletteWindow.h"

class openglWindow;
class onelabGroup;
class messageBrowser;

class toolDock;
class dockDivider;
class paletteWindow;

// the buttons of the status bar (see statusButtons() in graphicWindow.cpp)
enum statusButtonId {
  StatusMenu,
  StatusModels,
  StatusQuick,
  StatusX,
  StatusY,
  StatusZ,
  Status3D,
  StatusRotate,
  StatusFit,
  StatusSelect,
  StatusQuery,
  StatusMeasure,
  StatusRewind,
  StatusBack,
  StatusPlay,
  StatusForward,
  StatusButtons
};

class graphicWindow : public dockHost {
private:
  bool _autoScrollMessages;
  // while the dock lets its tools go (see setDocking())
  bool _undocking = false;
#if defined(__APPLE__)
  Fl_Sys_Menu_Bar *_sysbar;
#endif
  Fl_Menu_Bar *_bar;
  // the menu bar, in the window or the system's
  Fl_Menu_ *_menuBar() const
  {
#if defined(__APPLE__)
    if(_sysbar) return _sysbar;
#endif
    return _bar;
  }
  Fl_Tile *_tile;
  Fl_Window *_win, *_menuwin;
  messageBrowser *_browser;
  onelabGroup *_onelab;
  Fl_Box *_bottom;

  Fl_Button *_butt[StatusButtons];
  Fl_Progress *_label;
  int _minWidth, _minHeight;
  // the size of the icons of the status bar
  int _iconSize;
  // the width of the menu while it is hidden, to show it again
  int _menuWidth;
  // where the tiles were pressed (which may start dragging an edge between
  // them), and the sizes of the menu and the messages at that time (see
  // tileReleased())
  int _pushX, _pushY, _pushMenuWidth, _pushMessageHeight;
  std::vector<std::string> _messages;
  // the column of docked tool windows on the right of the tiles, the edge
  // dragged to change its width, and the box that tells FLTK which part of
  // the window resizes
  toolDock *_dock;
  dockDivider *_divider;
  Fl_Box *_resbox;
  // the floating tool window being dragged over the dock; it is docked when
  // the mouse button is released there
  paletteWindow *_dropping;
  bool _overDock(paletteWindow *w);
  void _dropHint(bool on);
  void _dropTarget(bool on);
  static void _drop_cb(void *data);
  void _layoutDock(int width);
  int _leastTileWidth();
  int _fitDockWidth(int w);

public:
  std::vector<openglWindow *> gl;

public:
  graphicWindow(bool main = true, int numTiles = 1, bool detachedMenu = false);
  ~graphicWindow();
  Fl_Window *getWindow() { return _win; }
  Fl_Window *getMenuWindow() { return _menuwin; }
  onelabGroup *getMenu() { return _onelab; }
  Fl_Progress *getProgress() { return _label; }
  Fl_Button *getSelectionButton() { return _butt[StatusSelect]; }
  Fl_Button *getQueryButton() { return _butt[StatusQuery]; }
  Fl_Button *getMeasureButton() { return _butt[StatusMeasure]; }
  messageBrowser *getMessageBrowser() { return _browser; }
  std::vector<std::string> &getMessages() { return _messages; }
  void setAutoScroll(bool val) { _autoScrollMessages = val; }
  bool getAutoScroll() { return _autoScrollMessages; }
  void setTitle(const std::string &str);
  int getGlWidth();
  void setGlWidth(int w);
  int getGlHeight();
  void setGlHeight(int h);
  int getMenuWidth();
  // called when the tiles are pressed, and when an edge between them is
  // released
  void tilePushed();
  void tileReleased();
  void setMenuWidth(int w);
  int getMenuHeight();
  void showMenu();
  void hideMenu();
  void showHideMenu();
  void detachMenu();
  void attachMenu();
  void attachDetachMenu();
  bool isMenuDetached() { return _menuwin ? true : false; }
  // with docking on, the tool windows are shown docked in a column, which is
  // visible while a tool is docked (paletteWindow::floating() says which
  // windows always float)
  void setDocking(bool docking);
  bool isDockShown();
  // the dockHost of the tool windows (see paletteWindow.h): toolTornOut()
  // shows a tool torn out of the dock on the desktop, under the pointer;
  // toolMoved() and dragToDock() follow a floating tool moved on the desktop,
  // which is docked when dragged over the dock
  bool takesTools() const override { return !_undocking; }
  void dockTool(paletteWindow *w) override;
  void toolHidden(paletteWindow *w) override;
  void toolResized(paletteWindow *w) override;
  void toolTornOut(paletteWindow *w, int x, int y) override;
  void toolMoved(paletteWindow *w) override;
  void dragToDock(paletteWindow *w) override;
  int toolDrop(int event) override;
  bool closeTool(Fl_Window *w) override;
  // the docked tool used last, if any, and closing it
  paletteWindow *currentDockedTool();
  bool closeDockedTool();
#if defined(__APPLE__)
  bool hasSystemMenuBar() const { return _sysbar != nullptr; }
#endif
  int getDockWidth();
  void setDockWidth(int w);
  bool split(openglWindow *g, char how, double ratio);
  void setAnimButtons(int mode);
  void checkAnimButtons();
  int getMessageHeight();
  void setMessageHeight(int h);
  void showMessages();
  void hideMessages();
  void showHideMessages();
  void addMessage(const char *msg);
  void clearMessages();
  void saveMessages(const char *filename);
  void copySelectedMessagesToClipboard();
  void setMessageFontSize(int size);
  void fillRecentHistoryMenu();
};

void file_quit_cb(Fl_Widget *w, void *data);
void file_watch_cb(Fl_Widget *w, void *data);
void geometry_reload_cb(Fl_Widget *w, void *data);
void geometry_edit_cb(Fl_Widget *w, void *data);
void file_window_cb(Fl_Widget *w, void *data);
void mesh_save_cb(Fl_Widget *w, void *data);
void onelab_reload_cb(Fl_Widget *w, void *data);
void help_about_cb(Fl_Widget *w, void *data);
void status_xyz1p_cb(Fl_Widget *w, void *data);
// the quick access menu of the status bar (also on a double click in the
// scene)
void quick_access_cb(Fl_Widget *w, void *data);
// the mouse selection on or off (the "S" button of the status bar, Escape)
void mouse_selection_cb(Fl_Widget *w, void *data);
void status_query_cb(Fl_Widget *w, void *data);
// whether a query is waiting for a click (see status_query_cb)
bool queryMode();
void status_measure_cb(Fl_Widget *w, void *data);
// whether a measurement is waiting for a click (see status_measure_cb)
bool measureMode();
// colour the buttons of the mouse selection, the query and the measurement
// according to their states
void updateModeButtons();
void status_play_manual(int time, int incr, bool redraw = true);
void show_hide_message_cb(Fl_Widget *w, void *data);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);
void dock_tool_cb(Fl_Widget *w, void *data);
void dock_tools_cb(Fl_Widget *w, void *data);

// The items of the action registry (see Actions.h) in this interface:
// - canRunItem() says whether an item can be used now;
// - runItem() does what an item does (view is the index of the view, for the
//   menu of a view);
// - addActionItems() adds the items of a menu to an FLTK menu, where they act
//   on the given view; with marks, the items that toggle or set an option
//   show its value (not in a menu that stays, which would not follow it).
struct actionItem;
class Fl_Menu_;
bool canRunItem(const actionItem &item);
void runItem(const actionItem &item, int view = -1);
// whether a menu of the registry has an item this interface can run now
bool canRunAnyItem(const actionItem &menu);
void addActionItems(Fl_Menu_ *m, const actionItem &menu, int view,
                    bool marks = true);

// An action of the registry this interface does: what it does (view: the
// index of the view of a menu of a view), its check mark, and, for an item
// that is a submenu filled by the interface (the recent files), how to fill
// it under path
struct fltkAction {
  std::function<void(int view)> run;
  std::function<int()> check;
  std::function<void(Fl_Menu_ *m, const std::string &path)> fill;
};
// the actions of the menu bar (see the "Menu bar" menu of Actions.cpp)
const std::map<std::string, fltkAction> &menuBarActions();
// the actions of the keys that are not in a menu (see FlGui::runShortcut())
const std::map<std::string, fltkAction> &keyboardActions();

#endif
