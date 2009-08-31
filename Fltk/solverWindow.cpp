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
#include "FlGui.h"
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

void solver_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;

  std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());

  // if the input file field is empty, fill it with a name guessed
  // from the current model name (only if this file actually exists)
  if(!strlen(FlGui::instance()->solver[num]->input[0]->value())){
    std::string inputFile = split[0] + split[1] + SINFO[num].extension;
    if(!StatFile(inputFile))
      FlGui::instance()->solver[num]->input[0]->value(inputFile.c_str());
  }

  // if the mesh file field is empty, fill it with a name guessed with
  // from the current model name
  if(!strlen(FlGui::instance()->solver[num]->input[1]->value())){
    std::string meshFile = split[0] + split[1] + ".msh";
    FlGui::instance()->solver[num]->input[1]->value(meshFile.c_str());
  }

  // show the window before calling Solver() to avoid race condition on
  // Windows (if the message window pops up die to an error, the window
  // callbacks get messed up)
  FlGui::instance()->solver[num]->win->show();

  std::string inputFile(FlGui::instance()->solver[num]->input[0]->value());
  if(SINFO[num].nboptions && inputFile.size()) {
    std::string file = FixWindowsPath(inputFile.c_str());
    char tmp[256], tmp2[256];
    sprintf(tmp, "\"%s\"", file.c_str());
    sprintf(tmp2, SINFO[num].name_command.c_str(), tmp);
    sprintf(tmp, "%s %s", SINFO[num].option_command.c_str(), tmp2);
    Solver(num, tmp);
  }
}

static void solver_file_open_cb(Fl_Widget *w, void *data)
{
  char tmp[256], tmp2[256];
  int num = (int)(long)data;
  sprintf(tmp, "*%s", SINFO[num].extension.c_str());

  // We allow to create the .pro file... Or should we add a "New file"
  // button?
  if(file_chooser(0, 0, "Choose", tmp)) {
    FlGui::instance()->solver[num]->input[0]->value(file_chooser_get_name(1).c_str());
    if(SINFO[num].nboptions) {
      std::string file = FixWindowsPath(file_chooser_get_name(1).c_str());
      sprintf(tmp, "\"%s\"", file.c_str());
      sprintf(tmp2, SINFO[num].name_command.c_str(), tmp);
      sprintf(tmp, "%s %s", SINFO[num].option_command.c_str(), tmp2);
      Solver(num, tmp);
    }
  }
}

static void solver_file_edit_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  std::string prog = FixWindowsPath(CTX::instance()->editor.c_str());
  std::string file = FixWindowsPath(FlGui::instance()->solver[num]->input[0]->value());
  char cmd[1024];
  ReplaceMultiFormat(prog.c_str(), file.c_str(), cmd);
  SystemCall(cmd);
}

static void solver_choose_mesh_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose", "*"))
    FlGui::instance()->solver[num]->input[1]->value(file_chooser_get_name(1).c_str());
}

static int nbs(const char *str)
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
  int usedopts = 0;

  if(SINFO[num].popup_messages)
    FlGui::instance()->messages->show(true);

  if(strlen(FlGui::instance()->solver[num]->input[1]->value())) {
    std::string m = FixWindowsPath(FlGui::instance()->solver[num]->input[1]->value());
    sprintf(tmp, "\"%s\"", m.c_str());
    sprintf(mesh, SINFO[num].mesh_command.c_str(), tmp);
  }
  else {
    strcpy(mesh, "");
  }

  if(nbs(SINFO[num].button_command[idx].c_str())) {
    for(int i = 0; i < idx; i++)
      usedopts += nbs(SINFO[num].button_command[i].c_str());
    if(usedopts > SINFO[num].nboptions) {
      Msg::Error("Missing options to execute command");
      return;
    }
    int val = FlGui::instance()->solver[num]->choice[usedopts]->value();
    if(val >= 0 && val < (int)SINFO[num].option[usedopts].size())
      sprintf(command, SINFO[num].button_command[idx].c_str(), 
              SINFO[num].option[usedopts][val].c_str());
    else{
      Msg::Warning("Invalid choice (%d) for option %d", val, usedopts);
      strcpy(command, "");
    }
  }
  else {
    strcpy(command, SINFO[num].button_command[idx].c_str());
  }

  std::string c = FixWindowsPath(FlGui::instance()->solver[num]->input[0]->value());
  sprintf(arg, "\"%s\"", c.c_str());
  sprintf(tmp, SINFO[num].name_command.c_str(), arg);
  sprintf(arg, "%s %s %s", tmp, mesh, command);
  Solver(num, arg);
}

static void solver_kill_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  if(SINFO[num].pid > 0) {
    if(KillProcess(SINFO[num].pid))
      Msg::Info("Killed %s pid %d", SINFO[num].name.c_str(), SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}

static void solver_ok_cb(Fl_Widget *w, void *data)
{
  int retry = 0, num = (int)(long)data;

  opt_solver_client_server
    (num, GMSH_SET, FlGui::instance()->solver[num]->menu->menu()[0].value() ? 1 : 0);
  opt_solver_popup_messages
    (num, GMSH_SET, FlGui::instance()->solver[num]->menu->menu()[1].value() ? 1 : 0);
  opt_solver_merge_views
    (num, GMSH_SET, FlGui::instance()->solver[num]->menu->menu()[2].value() ? 1 : 0);

  const char *exe = FlGui::instance()->solver[num]->input[2]->value();
  if(strcmp(opt_solver_executable(num, GMSH_GET, "").c_str(), exe))
    retry = 1;
  opt_solver_executable(num, GMSH_SET, exe);
  if(retry)
    solver_cb(0, data);
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
    FlGui::instance()->solver[num]->input[2]->value(file_chooser_get_name(1).c_str());
    solver_ok_cb(w, data);
  }
}

solverWindow::solverWindow(int solverIndex, int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  for(int i = 0; i < MAX_NUM_SOLVER_OPTIONS; i++)
    if(SINFO[solverIndex].option_name[i].size())
      SINFO[solverIndex].nboptions = i + 1;

  int width = 32 * FL_NORMAL_SIZE;
  int height = (5 + SINFO[solverIndex].nboptions) * BH + 5 * WB;
  int BBS = (width - 9 * WB) / 6;
  int LL = width - (int)(2.75 * BBS);
  
  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Solver");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs
      (WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *g = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Controls");

      menu = new Fl_Menu_Button
        (2 * WB, 2 * WB + 1 * BH, BBS / 2, BH);
      menu->add("Client-server", 0, 0, 0, FL_MENU_TOGGLE);
      menu->add("Pop-up messages",  0, 0, 0, FL_MENU_TOGGLE);
      menu->add("Auto-load results", 0, 0, 0, FL_MENU_TOGGLE);
      menu->callback(solver_ok_cb, (void *)solverIndex);

      input[2] = new Fl_Input
        (2 * WB + BBS / 2, 2 * WB + 1 * BH, LL - BBS / 2, BH, "Command");
      input[2]->callback(solver_ok_cb, (void *)solverIndex);

      Fl_Button *b1 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 1 * BH, BBS, BH, "Choose");
      b1->callback(solver_choose_executable_cb, (void *)solverIndex);

      Fl_Button *b4 = new Fl_Button
        (2 * WB, 2 * WB + 2 * BH, BBS, BH, "Edit");
      b4->callback(solver_file_edit_cb, (void *)solverIndex);
      input[0] = new Fl_Input
        (2 * WB + BBS, 2 * WB + 2 * BH, LL - BBS, BH, "Input file");
      Fl_Button *b3 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 2 * BH, BBS, BH, "Choose");
      b3->callback(solver_file_open_cb, (void *)solverIndex);

      input[1] = new Fl_Input
        (2 * WB, 2 * WB + 3 * BH, LL, BH, "Mesh file");
      Fl_Button *b5 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 3 * BH, BBS, BH, "Choose");
      b5->callback(solver_choose_mesh_cb, (void *)solverIndex);

      for(int i = 0; i < 3; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }

      for(int i = 0; i < SINFO[solverIndex].nboptions; i++) {
        choice[i] = new Fl_Choice
          (2 * WB, 2 * WB + (4 + i) * BH, LL, BH, SINFO[solverIndex].option_name[i].c_str());
        choice[i]->align(FL_ALIGN_RIGHT);
      }

      static int arg[MAX_NUM_SOLVERS][5][2];
      for(int i = 0; i < 5; i++) {
        if(SINFO[solverIndex].button_name[i].size()) {
          arg[solverIndex][i][0] = solverIndex;
          arg[solverIndex][i][1] = i;
          command[i] = new Fl_Button
            ((2 + i) * WB + i * BBS, 3 * WB + (4 + SINFO[solverIndex].nboptions) * BH,
             BBS, BH, SINFO[solverIndex].button_name[i].c_str());
          command[i]->callback
            (solver_command_cb, (void *)arg[solverIndex][i]);
        }
      }

      {
        Fl_Button *b = new Fl_Button
          (width - 2 * WB - BBS, 3 * WB + (4 + SINFO[solverIndex].nboptions) * BH,
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
      add_multiline_in_browser(o, "@c@b@.", SINFO[solverIndex].name.c_str(), false);
      o->add(" ");
      add_multiline_in_browser(o, "@c@. ", SINFO[solverIndex].help.c_str(), false);

      g->end();
    }
    o->end();
  }

  win->position(CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}
