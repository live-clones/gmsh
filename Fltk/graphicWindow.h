// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GRAPHIC_WINDOW_H_
#define _GRAPHIC_WINDOW_H_

#include <string>
#include <vector>
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
#include "openglWindow.h"
#include "onelabGroup.h"

class graphicWindow{
 private:
  std::string _title;
  int _savedMessageHeight, _savedMenuWidth;
  bool _autoScrollMessages;
 public:
  Fl_Window *win;
#if defined(__APPLE__)
  Fl_Sys_Menu_Bar *sysbar;
#endif
  Fl_Menu_Bar *bar;
  Fl_Tile *tile;
  std::vector<openglWindow*> gl;
  Fl_Browser *browser;
  onelabGroup *onelab;
  Fl_Box *bottom;
  Fl_Button *butt[14];
  Fl_Progress *label;
  int minWidth, minHeight;
 public:
  graphicWindow(bool main=true, int numTiles=1);
  ~graphicWindow();
  void setTitle(std::string str);
  void setAutoScroll(bool val){ _autoScrollMessages = val; }
  bool getAutoScroll(){ return _autoScrollMessages; }
  int getMessageHeight();
  void split(openglWindow *g, char how);
  void setAnimButtons(int mode);
  void checkAnimButtons();
  void showMessages();
  void hideMessages();
  void resizeMessages(int dh);
  void addMessage(const char *msg);
  void clearMessages();
  void saveMessages(const char *filename);
  void copySelectedMessagesToClipboard();
  void fillRecentHistoryMenu();
  void resizeMenu(int dh);
  void showMenu();
  void hideMenu();
  int getMenuWidth();
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
void mesh_1d_cb(Fl_Widget *w, void *data);
void mesh_2d_cb(Fl_Widget *w, void *data);
void mesh_3d_cb(Fl_Widget *w, void *data);
void help_about_cb(Fl_Widget *w, void *data);
void status_xyz1p_cb(Fl_Widget *w, void *data);
void status_options_cb(Fl_Widget *w, void *data);
void status_play_manual(int time, int incr, bool redraw=true);
void message_cb(Fl_Widget *w, void *data);
void menu_cb(Fl_Widget *w, void *data);

#endif
