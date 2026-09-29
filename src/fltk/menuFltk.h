// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MENU_FLTK_H
#define MENU_FLTK_H

#include <functional>
#include <string>
#include <vector>

#include "GuiMenus.h"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>

// the description flattened into the Fl_Menu_Item[] Fl_Menu_Bar wants

// the table stays valid until the next call: pass it to menu() straight away;
// systemBar for macOS, which has no mnemonics and its own Quit
Fl_Menu_Item *fltkMenuBuild(bool systemBar);

// just before the menu is shown
void fltkMenuRefresh();

// opens under the entry picked last time; key names the menu, so that two do
// not share that memory
void fltkMenuPopup(const std::vector<Ui::MenuItem> &tree, int x, int y,
                   const std::string &key = "");

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
      fltkMenuPopup(what(), Fl::event_x(), Fl::event_y(), key);
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
    if(event == FL_PUSH || event == FL_SHORTCUT) fltkMenuRefresh();
    return Fl_Menu_Bar::handle(event);
  }
};

#endif
