// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _VIEW_BUTTON_H_
#define _VIEW_BUTTON_H_

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Button.H>

class viewButton : public Fl_Group {
 private:
  Fl_Light_Button *_toggle;
  Fl_Button *_butt;
  Fl_Menu_Button *_popup;
  char _tooltip[256], _arrow[32];
 public:
  viewButton(int x, int y, int w, int h, int num);
  double value() { return _toggle->value(); }
  void value(double val) { _toggle->value(val); }
  void copy_label(const std::string &label){ _toggle->copy_label(label.c_str()); }
  std::string label(){ return _toggle->label(); }
};

#endif
