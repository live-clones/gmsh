// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GRAPH_MENU_H
#define GRAPH_MENU_H

#include <string>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>

// the X-Y graph menu of inputRange and outputRange: 9 graphs with 4 axes each
// (X, Y, X', Y'), the 36 axes stored in a string, '0' for an axis not drawn

// the menu item of an axis: each graph is a submenu of 4 items and its end
inline int graphMenuIndex(int axis) { return 1 + (axis / 4) * 6 + axis % 4; }

inline void addGraphMenu(Fl_Menu_Button *menu, Fl_Callback *cb,
                         Fl_Callback *resetCb, void *data)
{
  const char *graphs[9] = {"Top Left",     "Top Right", "Bottom Left",
                           "Bottom Right", "Top",       "Bottom",
                           "Left",         "Right",     "Full"};
  const char *axes[4] = {"X ", "Y ", "X ' ", "Y ' "};
  for(const char *g : graphs)
    for(const char *a : axes)
      menu->add((std::string(g) + "/" + a).c_str(), 0, cb, data,
                FL_MENU_TOGGLE);
  menu->add("None", 0, resetCb, data);
}

// the axes checked in the menu, drawn as discrete values ('3'; 1=iso,
// 2=continuous, 4=numeric)
inline std::string graphMenuValue(Fl_Menu_Button *menu)
{
  std::string val(36, '0');
  for(int i = 0; i < 36; i++)
    if(menu->menu()[graphMenuIndex(i)].value()) val[i] = '3';
  return val;
}

// the button lit when any axis is drawn, and the menu checked if asked
inline void showGraphValue(const std::string &val, Fl_Button *butt,
                           Fl_Menu_Button *menu, bool updateMenu)
{
  bool drawn = false;
  for(int i = 0; i < 36; i++) {
    if(val[i] != '0') drawn = true;
    if(!updateMenu) continue;
    Fl_Menu_Item &item = ((Fl_Menu_Item *)menu->menu())[graphMenuIndex(i)];
    if(val[i] != '0')
      item.set();
    else
      item.clear();
  }
  butt->value(drawn ? 1 : 0);
  butt->selection_color(drawn ? FL_YELLOW : butt->color());
  butt->redraw();
}

#endif
