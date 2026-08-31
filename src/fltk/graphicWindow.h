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

#include "GuiActions.h"
#include "Bar.h"
#include "GuiStatus.h"
#include "menuFltk.h"

// One button of the status bar, bound to what src/common/GuiStatus.h says it
// is. It reads the description at every draw rather than being told, so a
// button that says whether the mouse picks cannot be left showing the wrong
// thing by an option changed from a script.
class statusButtonFltk : public Fl_Button {
public:
  Ui::BarButton what;
  statusButtonFltk(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {}
  // the label it carries now: the play button says pause while it plays
  std::string shown() const
  {
    bool on = what.on && what.on();
    const std::string &glyph = (on && what.glyphOn.size()) ? what.glyphOn :
                                                             what.glyph;
    if(glyph.size()) return "@-1" + glyph;
    return (on && what.labelOn.size()) ? what.labelOn : what.label;
  }
  void refresh();
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
  // the buttons of the status bar, in the order src/common/GuiStatus.h
  // describes them
  std::vector<statusButtonFltk *> _butt;
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
  // bring the buttons of the status bar up to date: what is greyed out, what
  // is pressed, what is worth looking at
  void refreshStatusButtons();
  int getMessageHeight();
  void setMessageHeight(int h);
  void showMessages();
  void hideMessages();
  void showHideMessages();
  void addMessage(const char *msg);
  void clearMessages();
  // what the browser holds, in the order it holds it: writing it to a file is
  // done once, in messagesSave()
  void messageLines(std::vector<std::string> &lines);
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
// what Gui::orientViews() and Gui::setMouseSelection() come down to here: the
// views the status bar acts upon, and the pointers it changes, are the
// interface's
void fltkOrientViews(const std::string &what, bool reverse, bool sync);
void fltkSetMouseSelection(bool on);
bool fltkAnimating();
void fltkToggleAnimation();
void status_options_cb(Fl_Widget *w, void *data);
void show_hide_message_cb(Fl_Widget *w, void *data);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);

// The actions the shared menu description names: the file chooser and the
// windows are the one part of a menu entry that is genuinely toolkit business.
void fltkFileAction(const std::string &what);
void fltkWindowAction(const std::string &what);

#endif
