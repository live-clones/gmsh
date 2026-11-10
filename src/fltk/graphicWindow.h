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

// What the status bar does, also from the keys and the menus (see
// fltkActions.cpp):
// the point of view of the viewports of g (those of the current window, or all
// of them to sync them with Ctrl, if null): "x", "y", "z" (the axis out of
// the screen, or into it with Shift), "3d" (isometric), "1:1" (the model
// fitted in the window), "r" (rotated by 90 degrees), "reset"
void setPointOfView(const char *which, graphicWindow *g = nullptr);
// the query or the measure, the two tools that take the clicks on the model
// until asked to stop (see sceneTool), started or stopped; whether each
// waits for a click
void toggleTool(const std::string &name);
bool queryMode();
bool measureMode();
// colour the buttons of the mouse selection, the query and the measurement
// according to their states
void updateModeButtons();
// the mouse selection on or off (the "S" button of the status bar)
void toggleMouseSelection();
// the quick access menu of the status bar (also on a double click in the
// scene)
void quick_access_cb(Fl_Widget *w, void *data);
// a step of the animation: of the time steps (time), or of the views
void status_play_manual(int time, int incr, bool redraw = true);
// the console, the menu and the docked tool windows shown or hidden, the
// menu attached to the window or detached, and a graphic window added
void showHideMessages();
void showHideMenu();
void attachDetachMenu();
void dockCurrentTool();
void dockAllTools();
void newGraphicWindow();

#endif
