// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GRAPHIC_WINDOW_H
#define GRAPHIC_WINDOW_H

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

class openglWindow;
class onelabGroup;
class messageBrowser;

class toolDock;
class dockDivider;
class paletteWindow;

class graphicWindow {
private:
  bool _autoScrollMessages;
#if defined(__APPLE__)
  Fl_Sys_Menu_Bar *_sysbar;
#endif
  Fl_Menu_Bar *_bar;
  Fl_Tile *_tile;
  Fl_Window *_win, *_menuwin;
  messageBrowser *_browser;
  onelabGroup *_onelab;
  Fl_Box *_bottom;
  Fl_Button *_butt[15];
  Fl_Progress *_label;
  int _minWidth, _minHeight;
  // the size of the icons of the status bar
  int _iconSize;
  // the width of the menu while it is hidden, to show it again
  int _menuWidth;
  std::vector<std::string> _messages;
  // the column of docked tool windows on the right of the tiles, the edge
  // dragged to change its width, and the box that says what resizes
  toolDock *_dock;
  dockDivider *_divider;
  Fl_Box *_resbox;
  // the floating tool being dragged over the dock, docked when the button is
  // released there
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
  Fl_Button *getSelectionButton() { return _butt[9]; }
  Fl_Button *getQueryButton() { return _butt[12]; }
  Fl_Button *getMeasureButton() { return _butt[13]; }
  messageBrowser *getMessageBrowser() { return _browser; }
  std::vector<std::string> &getMessages() { return _messages; }
  int getMinWidth() { return _minWidth; }
  int getMinHeight() { return _minHeight; }
  void setAutoScroll(bool val) { _autoScrollMessages = val; }
  bool getAutoScroll() { return _autoScrollMessages; }
  void setTitle(const std::string &str);
  void setStereo(bool st);
  int getGlWidth();
  void setGlWidth(int w);
  int getGlHeight();
  void setGlHeight(int h);
  int getMenuWidth();
  void setMenuWidth(int w);
  int getMenuHeight();
  void showMenu();
  void hideMenu();
  void showHideMenu();
  void detachMenu();
  void attachMenu();
  void attachDetachMenu();
  bool isMenuDetached() { return _menuwin ? true : false; }
  // tool windows shown are docked, in a column visible while one is docked
  // (see paletteWindow::floating() for the ones kept out)
  void setDocking(bool docking);
  bool isDockShown();
  void dockTool(paletteWindow *w);
  void toolHidden(paletteWindow *w);
  void toolResized(paletteWindow *w);
  // a tool torn out of the dock, shown on the desktop under the pointer, and
  // a floating tool moved on the desktop, docked when dragged over the dock
  void toolTornOut(paletteWindow *w, int x, int y);
  void toolMoved(paletteWindow *w);
  void dragToDock(paletteWindow *w);
  int toolDrop(int event);
  // the tool shown in the dock, used last, if any, and closing it
  paletteWindow *currentDockedTool();
  bool closeDockedTool();
  // runs the entry of the menu bar whose shortcut is the current event
  bool runMenuShortcut();
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
  void changeMessageFontSize(int incr);
  void fillRecentHistoryMenu();
};

void file_quit_cb(Fl_Widget *w, void *data);
void file_watch_cb(Fl_Widget *w, void *data);
void mod_geometry_cb(Fl_Widget *w, void *data);
void mod_mesh_cb(Fl_Widget *w, void *data);
void mod_solver_cb(Fl_Widget *w, void *data);
void mod_post_cb(Fl_Widget *w, void *data);
void mod_back_cb(Fl_Widget *w, void *data);
void mod_forward_cb(Fl_Widget *w, void *data);
void geometry_reload_cb(Fl_Widget *w, void *data);
void onelab_reload_cb(Fl_Widget *w, void *data);
void mesh_1d_cb(Fl_Widget *w, void *data);
void mesh_2d_cb(Fl_Widget *w, void *data);
void mesh_3d_cb(Fl_Widget *w, void *data);
void help_about_cb(Fl_Widget *w, void *data);
void status_xyz1p_cb(Fl_Widget *w, void *data);
void status_options_cb(Fl_Widget *w, void *data);
void status_query_cb(Fl_Widget *w, void *data);
// whether a query is waiting for a click (see status_query_cb)
bool queryMode();
void status_measure_cb(Fl_Widget *w, void *data);
// whether a measurement is waiting for a click (see status_measure_cb)
bool measureMode();
void status_play_manual(int time, int incr, bool redraw = true);
void quick_access_cb(Fl_Widget *w, void *data);
void show_hide_message_cb(Fl_Widget *w, void *data);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);
void dock_tool_cb(Fl_Widget *w, void *data);
void dock_tools_cb(Fl_Widget *w, void *data);

#endif
