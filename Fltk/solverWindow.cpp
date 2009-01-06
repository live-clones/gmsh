// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Browser.H>
#include "GModel.h"
#include "GUI.h"
#include "solverWindow.h"
#include "paletteWindow.h"
#include "optionWindow.h"
#include "messageWindow.h"
#include "fileDialogs.h"
#include "GmshMessage.h"
#include "Solvers.h"
#include "StringUtils.h"
#include "Options.h"
#include "OS.h"
#include "Context.h"

extern Context_T CTX;

void solver_cb(Fl_Widget *w, void *data)
{
  static int init = 0, first[MAX_NUM_SOLVERS];
  int num = (int)(long)data;

  if(!init) {
    for(int i = 0; i < MAX_NUM_SOLVERS; i++)
      first[i] = 1;
    init = 1;
  }

  if(first[num]) {
    first[num] = 0;
    char file[256], no_ext[256], ext[256], base[256];
    SplitFileName(GModel::current()->getFileName().c_str(), no_ext, ext, base);
    strcpy(file, no_ext);
    strcat(file, SINFO[num].extension);
    GUI::instance()->solver[num]->input[0]->value(file);
  }
  if(SINFO[num].nboptions) {
    std::string file = FixWindowsPath
      (GUI::instance()->solver[num]->input[0]->value());
    char tmp[256], tmp2[256];
    sprintf(tmp, "\"%s\"", file.c_str());
    sprintf(tmp2, SINFO[num].name_command, tmp);
    sprintf(tmp, "%s %s", SINFO[num].option_command, tmp2);
    Solver(num, tmp);
  }
  GUI::instance()->solver[num]->win->show();
}

static void solver_file_open_cb(Fl_Widget *w, void *data)
{
  char tmp[256], tmp2[256];
  int num = (int)(long)data;
  sprintf(tmp, "*%s", SINFO[num].extension);

  // We allow to create the .pro file... Or should we add a "New file"
  // button?
  if(file_chooser(0, 0, "Choose", tmp)) {
    GUI::instance()->solver[num]->input[0]->value(file_chooser_get_name(1).c_str());
    if(SINFO[num].nboptions) {
      std::string file = FixWindowsPath(file_chooser_get_name(1).c_str());
      sprintf(tmp, "\"%s\"", file.c_str());
      sprintf(tmp2, SINFO[num].name_command, tmp);
      sprintf(tmp, "%s %s", SINFO[num].option_command, tmp2);
      Solver(num, tmp);
    }
  }
}

static void solver_file_edit_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  std::string prog = FixWindowsPath(CTX.editor);
  std::string file = FixWindowsPath(GUI::instance()->solver[num]->input[0]->value());
  char cmd[1024];
  ReplaceMultiFormat(prog.c_str(), file.c_str(), cmd);
  SystemCall(cmd);
}

static void solver_choose_mesh_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose", "*"))
    GUI::instance()->solver[num]->input[1]->value(file_chooser_get_name(1).c_str());
}

static int nbs(char *str)
{
  int i, nb = 0;
  for(i = 0; i < (int)strlen(str) - 1; i++) {
    if(str[i] == '%' && str[i + 1] == 's') {
      nb++;
      i++;
    }
  }
  return nb;
}

static void solver_command_cb(Fl_Widget *w, void *data)
{
  char tmp[256], mesh[256], arg[512], command[256];
  int num = ((int *)data)[0];
  int idx = ((int *)data)[1];
  int i, usedopts = 0;

  if(SINFO[num].popup_messages)
    GUI::instance()->messages->show(true);

  if(strlen(GUI::instance()->solver[num]->input[1]->value())) {
    std::string m = FixWindowsPath(GUI::instance()->solver[num]->input[1]->value());
    sprintf(tmp, "\"%s\"", m.c_str());
    sprintf(mesh, SINFO[num].mesh_command, tmp);
  }
  else {
    strcpy(mesh, "");
  }

  if(nbs(SINFO[num].button_command[idx])) {
    for(i = 0; i < idx; i++)
      usedopts += nbs(SINFO[num].button_command[i]);
    if(usedopts > SINFO[num].nboptions) {
      Msg::Error("Missing options to execute command");
      return;
    }
    sprintf(command, SINFO[num].button_command[idx], SINFO[num].option
            [usedopts][GUI::instance()->solver[num]->choice[usedopts]->value()]);
  }
  else {
    strcpy(command, SINFO[num].button_command[idx]);
  }

  std::string c = FixWindowsPath(GUI::instance()->solver[num]->input[0]->value());
  sprintf(arg, "\"%s\"", c.c_str());
  sprintf(tmp, SINFO[num].name_command, arg);
  sprintf(arg, "%s %s %s", tmp, mesh, command);
  Solver(num, arg);
}

static void solver_kill_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  if(SINFO[num].pid > 0) {
    if(KillProcess(SINFO[num].pid))
      Msg::Info("Killed %s pid %d", SINFO[num].name, SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}

static void solver_ok_cb(Fl_Widget *w, void *data)
{
  int retry = 0, num = (int)(long)data;
  opt_solver_popup_messages
    (num, GMSH_SET, GUI::instance()->solver[num]->butt[0]->value());
  opt_solver_merge_views
    (num, GMSH_SET, GUI::instance()->solver[num]->butt[1]->value());
  opt_solver_client_server
    (num, GMSH_SET, GUI::instance()->solver[num]->butt[2]->value());
  if(strcmp(opt_solver_executable(num, GMSH_GET, NULL), 
            GUI::instance()->solver[num]->input[2]->value()))
    retry = 1;
  opt_solver_executable
    (num, GMSH_SET, GUI::instance()->solver[num]->input[2]->value());
  if(retry)
    solver_cb(NULL, data);
}

static void solver_choose_executable_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose",
#if defined(WIN32)
                  "*.exe"
#else
                  "*"
#endif
                  )){
    GUI::instance()->solver[num]->input[2]->value(file_chooser_get_name(1).c_str());
    solver_ok_cb(w, data);
  }
}

solverWindow::solverWindow(int solverIndex, int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  for(int i = 0; i < MAX_NUM_SOLVER_OPTIONS; i++)
    if(strlen(SINFO[solverIndex].option_name[i]))
      SINFO[solverIndex].nboptions = i + 1;

  int LL = 2 * IW;
  int width = LL + BB + BB / 3 + 4 * WB;
  int height = (7 + SINFO[solverIndex].nboptions) * BH + 5 * WB;
  int BBS = (width - 8 * WB) / 5;
  
  win = new paletteWindow
    (width, height, CTX.non_modal_windows, "Solver");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs
      (WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *g = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Controls");

      Fl_Button *b2 = new Fl_Button
        (2 * WB, 2 * WB + 1 * BH, BB / 2, BH, "Save");
      b2->callback(options_save_cb);
      input[2] = new Fl_Input
        (2 * WB + BB / 2, 2 * WB + 1 * BH, LL - BB / 2, BH, "Solver");
      input[2]->callback(solver_ok_cb, (void *)solverIndex);

      Fl_Button *b1 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 1 * BH, BBS, BH, "Choose");
      b1->callback(solver_choose_executable_cb, (void *)solverIndex);

      int ww = (LL - WB) / 2;
      butt[2] = new Fl_Check_Button
        (2 * WB, 2 * WB + 2 * BH, ww, BH, "Client/server");
      butt[0] = new Fl_Check_Button
        (2 * WB, 2 * WB + 3 * BH, ww, BH, "Pop-up messages");
      butt[1] = new Fl_Check_Button
        (3 * WB + ww, 2 * WB + 2 * BH, ww, BH, "Auto-load results");
      
      for(int i = 0; i < 3; i++){
        butt[i]->type(FL_TOGGLE_BUTTON);
        butt[i]->callback(solver_ok_cb, (void *)solverIndex);
      }

      Fl_Button *b4 = new Fl_Button
        (2 * WB, 2 * WB + 4 * BH, BB / 2, BH, "Edit");
      b4->callback(solver_file_edit_cb, (void *)solverIndex);
      input[0] = new Fl_Input
        (2 * WB + BB / 2, 2 * WB + 4 * BH, LL - BB / 2, BH, "Input");
      Fl_Button *b3 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 4 * BH, BBS, BH, "Choose");
      b3->callback(solver_file_open_cb, (void *)solverIndex);

      input[1] = new Fl_Input
        (2 * WB, 2 * WB + 5 * BH, LL, BH, "Mesh");
      Fl_Button *b5 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 5 * BH, BBS, BH, "Choose");
      b5->callback(solver_choose_mesh_cb, (void *)solverIndex);

      for(int i = 0; i < 3; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }

      for(int i = 0; i < SINFO[solverIndex].nboptions; i++) {
        choice[i] = new Fl_Choice
          (2 * WB, 2 * WB + (6 + i) * BH, LL, BH, SINFO[solverIndex].option_name[i]);
        choice[i]->align(FL_ALIGN_RIGHT);
      }

      static int arg[MAX_NUM_SOLVERS][5][2];
      for(int i = 0; i < 4; i++) {
        if(strlen(SINFO[solverIndex].button_name[i])) {
          arg[solverIndex][i][0] = solverIndex;
          arg[solverIndex][i][1] = i;
          command[i] = new Fl_Button
            ((2 + i) * WB + i * BBS, 3 * WB + (6 + SINFO[solverIndex].nboptions) * BH,
             BBS, BH, SINFO[solverIndex].button_name[i]);
          command[i]->callback
            (solver_command_cb, (void *)arg[solverIndex][i]);
        }
      }

      {
        Fl_Button *b = new Fl_Button
          (width - 2 * WB - BBS, 3 * WB + (6 + SINFO[solverIndex].nboptions) * BH,
           BBS, BH, "Kill");
        b->callback(solver_kill_cb, (void *)solverIndex);
      }
     
      g->end();
    }
    {
      Fl_Group *g = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB, "About");

      Fl_Browser *o = new Fl_Browser
        (2 * WB, 2 * WB + 1 * BH, width - 4 * WB, height - 4 * WB - BH);
      o->add(" ");
      add_multiline_in_browser(o, "@c@b@.", SINFO[solverIndex].name, false);
      o->add(" ");
      add_multiline_in_browser(o, "@c@. ", SINFO[solverIndex].help, false);

      g->end();
    }
    o->end();
  }

  win->position(CTX.solver_position[0], CTX.solver_position[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}
