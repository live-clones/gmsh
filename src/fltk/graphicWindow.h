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

#include "Bar.h"
#include "Backend.h"
#include "menuFltk.h"

// reads the description at every draw
class statusButtonFltk : public Fl_Button {
public:
  Ui::BarButton what;
  statusButtonFltk(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {}
  std::string shown() const
  {
    bool on = what.on && what.on();
    const std::string &glyph = (on && what.glyphOn.size()) ? what.glyphOn :
                                                             what.glyph;
    if(glyph.size()) return "@-1" + glyph;
    return (on && what.labelOn.size()) ? what.labelOn : what.label;
  }
  // whether it changed
  bool refresh();
  void draw() override
  {
    refresh();
    Fl_Button::draw();
  }
  int handle(int event) override
  {
    if(event == FL_PUSH && what.menu) {
      fltkMenuPopup(what.menu(), Fl::event_x(), Fl::event_y(), what.label);
      return 1;
    }
    return Fl_Button::handle(event);
  }
};
#if defined(__APPLE__)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif
#include <FL/Fl_Menu_Bar.H>

class sceneViewFltk;
class sceneView;
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
  std::vector<statusButtonFltk *> _butt;
  Fl_Progress *_label;
  int _minWidth, _minHeight;
  std::vector<std::string> _messages;
  // what is about to be forgotten is said to the host, and read back from the
  // settings when shown again
  void _forgetting(const Ui::Backend::Layout &what);

public:
  std::vector<sceneViewFltk *> gl;

public:
  graphicWindow(bool main = true, int numTiles = 1, bool detachedMenu = false);
  ~graphicWindow();
  Fl_Window *getWindow() { return _win; }
  Fl_Window *getMenuWindow() { return _menuwin; }
  onelabGroup *getMenu() { return _onelab; }
  Fl_Progress *getProgress() { return _label; }

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
  Ui::Backend::Layout layout();
  void showMenu();
  void hideMenu();
  void showHideMenu();
  void detachMenu();
  void attachMenu();
  void attachDetachMenu();
  bool isMenuDetached() { return _menuwin ? true : false; }
  bool split(sceneViewFltk *g, char how, double ratio);
  void refreshStatusButtons();
  int getMessageHeight();
  void setMessageHeight(int h);
  void showMessages();
  void hideMessages();
  void showHideMessages();
  void addMessage(const char *msg);
  void clearMessages();
  void messageLines(std::vector<std::string> &lines);
  void copySelectedMessagesToClipboard();
  void setMessageFontSize(int size);
  void changeMessageFontSize(int incr);
  void fillRecentHistoryMenu();
};

void file_quit_cb(Fl_Widget *w, void *data);
void help_about_cb(Fl_Widget *w, void *data);
void fltkOrientViews(const std::string &what, bool reverse, bool sync);
void fltkSetMouseSelection(bool on);
std::vector<sceneView *> fltkViewsBeside(sceneViewFltk *view);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);

// false for an action it does not know
bool fltkWindowAction(const std::string &what);

#endif
