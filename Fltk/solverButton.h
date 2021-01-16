// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SOLVER_BUTTON_H
#define SOLVER_BUTTON_H

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>

class solverButton : public Fl_Group {
private:
  Fl_Button *_butt[2];
  Fl_Menu_Button *_popup;
  char _tooltip[256];

public:
  solverButton(int x, int y, int w, int h, int num, Fl_Color col);
  void copy_label(const std::string &label)
  {
    _butt[0]->copy_label(label.c_str());
  }
  std::string label() { return _butt[0]->label(); }
};

#endif
