// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  Fl_Button *_butt[12];
  Fl_Progress *_label;
  int _minWidth, _minHeight;
  std::vector<std::string> _messages;

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
  int getMenuPositionX();
  int getMenuPositionY();
  void showMenu();
  void hideMenu();
  void showHideMenu();
  void detachMenu();
  void attachMenu();
  void attachDetachMenu();
  bool isMenuDetached() { return _menuwin ? true : false; }
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
void status_play_manual(int time, int incr, bool redraw = true);
void quick_access_cb(Fl_Widget *w, void *data);
void show_hide_message_cb(Fl_Widget *w, void *data);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);

#endif
