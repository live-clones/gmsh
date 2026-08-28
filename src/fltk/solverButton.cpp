// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <FL/fl_ask.H>
#include "GmshMessage.h"
#include "FlGui.h"
#include "Options.h"
#include "onelabGroup.h"
#include "solverButton.h"
#include "menuFltk.h"
#include "GuiMenus.h"
#include "GuiActions.h"
#include "fileDialogs.h"

solverButton::solverButton(int x, int y, int w, int h, int num, Fl_Color col)
  : Fl_Group(x, y, w, h)
{
  int popw = FL_NORMAL_SIZE + 2;

  _butt[0] = new Fl_Button(x, y, w - popw, h);
  _butt[0]->box(FL_FLAT_BOX);
  _butt[0]->color(col);
  _butt[0]->selection_color(col);
  _butt[0]->callback(solver_cb, (void *)(intptr_t)num);
  _butt[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);

  std::string name = opt_solver_name(num, GMSH_GET, "");
  _butt[0]->copy_label(name.c_str());
  std::string exe = opt_solver_executable(num, GMSH_GET, "");
  strcpy(_tooltip, exe.c_str());
  _butt[0]->tooltip(_tooltip);

  _butt[1] = new Fl_Button(x + w - popw, y, popw, h, "@>");
  _butt[1]->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _butt[1]->tooltip("Show solver option menu");
  _butt[1]->box(FL_FLAT_BOX);
  _butt[1]->color(col);
  _butt[1]->selection_color(col);
  // described once in src/common/GuiMenus.cpp, as the view menu is
  _popup = new popupButtonFltk(x + w - popw, y, popw, h);
  _popup->box(FL_NO_BOX);
  _popup->key = "solver";
  _popup->what = [num]() { return Menu::solverActions(num); };

  end(); // close the group
  resizable(_butt[0]);
}
