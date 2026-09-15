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

// one button of the status bar, bound to what the description says it
// is; it reads the description at every draw rather than being told
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
  // the buttons of the status bar, in the order src/gui/GuiStatus.h
  // describes them
  std::vector<statusButtonFltk *> _butt;
  Fl_Progress *_label;
  int _minWidth, _minHeight;
  std::vector<std::string> _messages;
  // what is about to be forgotten -- the width of a tree being folded
  // away, the height of a console being hidden, where a tree stood as a
  // window of its own -- is said to the host, and read back from the
  // settings when the thing is shown again
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
  // where everything ended up, for the option file
  Ui::Backend::Layout layout();
  void showMenu();
  void hideMenu();
  void showHideMenu();
  void detachMenu();
  void attachMenu();
  void attachDetachMenu();
  bool isMenuDetached() { return _menuwin ? true : false; }
  bool split(sceneViewFltk *g, char how, double ratio);
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
  // what the browser holds, in the order it holds it
  void messageLines(std::vector<std::string> &lines);
  void copySelectedMessagesToClipboard();
  void setMessageFontSize(int size);
  void changeMessageFontSize(int incr);
  void fillRecentHistoryMenu();
};

void file_quit_cb(Fl_Widget *w, void *data);
void help_about_cb(Fl_Widget *w, void *data);
// the views the status bar acts upon, and the pointers it changes
void fltkOrientViews(const std::string &what, bool reverse, bool sync);
void fltkSetMouseSelection(bool on);
// the scenes of the window holding a view, or the view alone
std::vector<sceneView *> fltkViewsBeside(sceneViewFltk *view);
void show_hide_menu_cb(Fl_Widget *w, void *data);
void attach_detach_menu_cb(Fl_Widget *w, void *data);

// the actions the menu description names; false for an action it does
// not know
bool fltkWindowAction(const std::string &what);

#endif
