// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VIEW_BUTTON_H
#define VIEW_BUTTON_H

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Menu_Button.H>

class viewButton : public Fl_Group {
private:
  Fl_Check_Button *_toggle;
  Fl_Button *_butt;
  Fl_Menu_Button *_popup;
  char _tooltip[256];

public:
  viewButton(int x, int y, int w, int h, int num, Fl_Color col);
  double value() { return _toggle->value(); }
  void value(double val) { _toggle->value(val); }
  void copy_label(const std::string &label)
  {
    _toggle->copy_label(label.c_str());
  }
  std::string label() { return _toggle->label(); }
};

#endif
