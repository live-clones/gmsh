// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Browser.H>
#include "GUI.h"
#include "solverWindow.h"
#include "shortcutWindow.h"
#include "Solvers.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

solverWindow::solverWindow(int solverIndex, int fontsize)
  : _fontsize(fontsize)
{
  for(int i = 0; i < MAX_NUM_SOLVER_OPTIONS; i++)
    if(strlen(SINFO[solverIndex].option_name[i]))
      SINFO[solverIndex].nboptions = i + 1;

  int LL = 2 * IW;
  int width = LL + BB + BB / 3 + 4 * WB;
  int height = (8 + SINFO[solverIndex].nboptions) * BH + 6 * WB;
  int BBS = (width - 8 * WB) / 5;
  
  win = new dialogWindow
    (width, height, CTX.non_modal_windows);
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs
      (WB, WB, width - 2 * WB, height - 3 * WB - 1 * BH);
    {
      Fl_Group *g = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Controls");

      input[2] = new Fl_Input
        (2 * WB, 2 * WB + 1 * BH, LL, BH, "Solver");
      input[2]->callback(solver_ok_cb, (void *)solverIndex);

      Fl_Button *b1 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 1 * BH, BBS, BH, "Choose");
      b1->callback(solver_choose_executable_cb, (void *)solverIndex);
      Fl_Button *b2 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 2 * BH, BBS, BH, "Save");
      b2->callback(options_save_cb);

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

      input[0] = new Fl_Input
        (2 * WB + BB / 2, 2 * WB + 4 * BH, LL - BB / 2, BH, "Input");
      Fl_Button *b3 = new Fl_Button
        (width - 2 * WB - BBS, 2 * WB + 4 * BH, BBS, BH, "Choose");
      b3->callback(solver_file_open_cb, (void *)solverIndex);

      Fl_Button *b4 = new Fl_Button
        (2 * WB, 2 * WB + 4 * BH, BB / 2, BH, "Edit");
      b4->callback(solver_file_edit_cb, (void *)solverIndex);

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
      for(int i = 0; i < 5; i++) {
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
      
      g->end();
    }
    {
      Fl_Group *g = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "About");

      Fl_Browser *o = new Fl_Browser
        (2 * WB, 2 * WB + 1 * BH, width - 4 * WB, height - 5 * WB - 2 * BH);
      o->add(" ");
      add_multiline_in_browser(o, "@c@b@.", SINFO[solverIndex].name, false);
      o->add(" ");
      add_multiline_in_browser(o, "@c@. ", SINFO[solverIndex].help, false);

      g->end();
    }
    o->end();
  }

  {
    Fl_Button *b1 = new Fl_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Kill solver");
    b1->callback(solver_kill_cb, (void *)solverIndex);
    Fl_Button *b2 = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    b2->callback(cancel_cb, (void*)win);
  }

  win->position(CTX.solver_position[0], CTX.solver_position[1]);
  win->end();
}
