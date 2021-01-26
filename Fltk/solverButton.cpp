// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "fileDialogs.h"

static void solver_rename_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Warning("Cannot rename client while solver is running");
    return;
  }

  int num = (intptr_t)data;
  std::string name = opt_solver_name(num, GMSH_GET, "");
  const char *n = fl_input("Solver name:", name.c_str());
  if(n) {
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    std::string host = opt_solver_remote_login(num, GMSH_GET, "");
    // this will remove the old client if the new name is different
    FlGui::instance()->onelab->addSolver(n, exe, host, num);
    onelab_cb(nullptr, (void *)"reset");
  }
}

static void solver_change_exe_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Warning("Cannot change executable name while solver is running");
    return;
  }

  int num = (intptr_t)data;
  std::string name = opt_solver_name(num, GMSH_GET, "");
  std::string exe = opt_solver_executable(num, GMSH_GET, "");
  const char *old = exe.size() ? exe.c_str() : nullptr;
  std::string title = "Choose location of " + name + " executable";
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif
  if(fileChooser(FILE_CHOOSER_SINGLE, title.c_str(), pattern.c_str(), old)) {
    exe = fileChooserGetName(1);
    if(exe.size()) {
      // remove old client if it's already loaded
      auto it = onelab::server::instance()->findClient(name);
      if(it != onelab::server::instance()->lastClient()) delete *it;
      std::string host = opt_solver_remote_login(num, GMSH_GET, "");
      FlGui::instance()->onelab->addSolver(name, exe, host, num);
      onelab_cb(nullptr, (void *)"reset");
    }
  }
}

static void solver_remove_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Warning("Cannot remove client while solver is running");
    return;
  }

  int num = (intptr_t)data;

  std::string name = opt_solver_name(num, GMSH_GET, "");
  opt_solver_name(num, GMSH_SET, "");
  opt_solver_executable(num, GMSH_SET, "");
  opt_solver_remote_login(num, GMSH_SET, "");

  auto it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()) { delete *it; }
  FlGui::instance()->onelab->rebuildSolverList();
}

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
  _popup = new Fl_Menu_Button(x + w - popw, y, popw, h);
  _popup->type(Fl_Menu_Button::POPUP123);
  _popup->add("Rename...", 0, (Fl_Callback *)solver_rename_cb,
              (void *)(intptr_t)num, 0);
  _popup->add("Change Executable Location...", 0,
              (Fl_Callback *)solver_change_exe_cb, (void *)(intptr_t)num,
              FL_MENU_DIVIDER);
  _popup->add("Remove", 0, (Fl_Callback *)solver_remove_cb,
              (void *)(intptr_t)num, 0);

  end(); // close the group
  resizable(_butt[0]);
}
