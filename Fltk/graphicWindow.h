
// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
#include "openglWindow.h"

class graphicWindow{
 private:
  std::string _title;
  int _savedMessageHeight;
 public:
  Fl_Window *win;
  Fl_Tile *tile;
  std::vector<openglWindow*> gl;
  Fl_Browser *browser;
  Fl_Box *bottom;
  Fl_Button *butt[14];
  Fl_Box *label[2];
  int minWidth, minHeight;
 public:
  graphicWindow(bool main=true, int numTiles=1);
  ~graphicWindow();
  void setTitle(std::string str);
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
};

void status_xyz1p_cb(Fl_Widget *w, void *data);
void status_options_cb(Fl_Widget *w, void *data);
void status_play_manual(int time, int incr, bool redraw=true);
void message_cb(Fl_Widget *w, void *data);

#endif
