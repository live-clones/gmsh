// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "FlGui.h"
#include "Options.h"
#include "onelabGroup.h"
#include "solverButton.h"

static void solver_remove_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->onelab->isBusy()){
    Msg::Warning("Cannot remove client while solver is running");
    return;
  }

  int num = (intptr_t)data;

  std::string name = opt_solver_name(num, GMSH_GET, "");
  opt_solver_name(num, GMSH_SET, "");
  opt_solver_executable(num, GMSH_SET, "");
  opt_solver_remote_login(num, GMSH_SET, "");

  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()){
    onelab::client *c = it->second;
    delete c;
  }
  FlGui::instance()->onelab->rebuildSolverList();
}

solverButton::solverButton(int x, int y, int w, int h, int num, Fl_Color col)
  : Fl_Group(x,y,w,h)
{
  int popw = FL_NORMAL_SIZE + 2;

  _butt[0] = new Fl_Button(x, y, w - popw, h);
  _butt[0]->box(FL_FLAT_BOX);
  _butt[0]->color(col);
  _butt[0]->selection_color(col);
  _butt[0]->callback(solver_cb, (void *)num);
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
  _popup = new Fl_Menu_Button(x + w - popw, y, popw, h);
  _popup->type(Fl_Menu_Button::POPUP123);
  _popup->add("Remove", 0, (Fl_Callback *)solver_remove_cb, (void *)num, 0);

  end(); // close the group
  resizable(_butt[0]);
}
