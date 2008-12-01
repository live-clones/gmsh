// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "contextWindow.h"
#include "shortcutWindow.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

geometryContextWindow::geometryContextWindow(int fontsize)
  : _fontsize(fontsize)
{
  int width = 31 * _fontsize;
  int height = 5 * WB + 9 * BH;

  win = new dialogWindow
    (width, height, CTX.non_modal_windows, "Contextual Geometry Definitions");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: Parameter
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Parameter");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Name");
      input[0]->value("lc");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Value");
      input[1]->value("0.1");
      for(int i = 0; i < 2; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      {
        Fl_Return_Button *o = new Fl_Return_Button
          (width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
        o->callback(con_geometry_define_parameter_cb);
      }
      group[0]->end();
    }
    // 1: Point
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Point");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate");
      input[2]->value("0");
      input[3] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate");
      input[3]->value("0");
      input[4] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate");
      input[4]->value("0");
      input[5] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Characteristic length");
      input[5]->value("");
      for(int i = 2; i < 6; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      value[0] = new Fl_Value_Input(2 * WB, 2 * WB + 5 * BH, IW/3, BH);
      value[1] = new Fl_Value_Input(2 * WB + IW/3, 2 * WB + 5 * BH, IW/3, BH);
      value[2] = new Fl_Value_Input(2 * WB + 2*IW/3, 2 * WB + 5 * BH, IW/3, BH,
                                    "Snapping grid spacing");
      for(int i = 0; i < 3; i++) {
        value[i]->align(FL_ALIGN_RIGHT);
        value[i]->callback(con_geometry_snap_cb);
      }
      {
        Fl_Return_Button *o = new Fl_Return_Button
          (width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
        o->callback(con_geometry_define_point_cb);
      }
      group[1]->end();
    }
    // 2: Translation
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Translation");
      input[6] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X component");
      input[6]->value("0");
      input[7] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component");
      input[7]->value("0");
      input[8] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component");
      input[8]->value("1");
      for(int i = 6; i < 9; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[2]->end();
    }
    // 3: Rotation
    {
      group[3] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Rotation");
      input[9] = new Fl_Input
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate of an axis point");
      input[9]->value("0");
      input[10] = new Fl_Input
        (2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate of an axis point");
      input[10]->value("0");
      input[11] = new Fl_Input
        (2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate of an axis point");
      input[11]->value("0");
      input[12] = new Fl_Input
        (2 * WB, 2 * WB + 4 * BH, IW, BH, "X component of axis direction");
      input[12]->value("0");
      input[13] = new Fl_Input
        (2 * WB, 2 * WB + 5 * BH, IW, BH, "Y component of axis direction");
      input[13]->value("1");
      input[14] = new Fl_Input
        (2 * WB, 2 * WB + 6 * BH, IW, BH, "Z component of axis direction");
      input[14]->value("0");
      input[15] = new Fl_Input
        (2 * WB, 2 * WB + 7 * BH, IW, BH, "Angle in radians");
      input[15]->value("Pi/4");
      for(int i = 9; i < 16; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[3]->end();
    }
    // 4: Scale
    {
      group[4] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Scale");
      input[16] = new Fl_Input
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "X component of direction");
      input[16]->value("0");
      input[17] = new Fl_Input
        (2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component of direction");
      input[17]->value("0");
      input[18] = new Fl_Input
        (2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component of direction");
      input[18]->value("0");
      input[19] = new Fl_Input
        (2 * WB, 2 * WB + 4 * BH, IW, BH, "Factor");
      input[19]->value("0.5");
      for(int i = 16; i < 20; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[4]->end();
    }
    // 5: Symmetry
    {
      group[5] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Symmetry");
      input[20] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "A");
      input[20]->value("1");
      input[21] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "B");
      input[21]->value("0");
      input[22] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "C");
      input[22]->value("0");
      input[23] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "D");
      input[23]->value("1");
      for(int i = 20; i < 24; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[5]->end();
    }
    o->end();
  }

  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void *)win);
  }

  win->position(CTX.ctx_position[0], CTX.ctx_position[1]);
  win->end();
}

void geometryContextWindow::show(int pane)
{
  for(int i = 0; i < 6; i++)
    group[i]->hide();
  group[pane]->show();
  win->show();
}

meshContextWindow::meshContextWindow(int fontsize)
  : _fontsize(fontsize)
{
  static Fl_Menu menu_transfinite_dir[] = {
    {"Left", 0, 0, 0},
    {"Right", 0, 0, 0},
    {"Alternated", 0, 0, 0},
    {0}
  };

  int width = 29 * _fontsize;
  int height = 5 * WB + 5 * BH;

  win = new dialogWindow
    (width, height, CTX.non_modal_windows, "Contextual Mesh Definitions");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: Characteristic length
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Characteristic Length");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Value");
      input[0]->value("0.1");
      input[0]->align(FL_ALIGN_RIGHT);
      group[0]->end();
    }
    // 1: Transfinite line
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Transfinite Line");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Number of points");
      input[1]->value("10");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Parameter");
      input[2]->value("1");
      for(int i = 1; i < 3; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      static Fl_Menu_Item menu_trsf_mesh[] = {
        {"Progression", 0, 0, 0},
        {"Bump", 0, 0, 0},
        {0}
      };
      choice[0] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Type");
      choice[0]->menu(menu_trsf_mesh);
      choice[0]->align(FL_ALIGN_RIGHT);
      group[1]->end();
    }
    
    // 2: Transfinite surface
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Transfinite Surface");

      choice[1] = new Fl_Choice
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "Transfinite Arrangement");
      choice[1]->menu(menu_transfinite_dir);
      choice[1]->align(FL_ALIGN_RIGHT);

      group[2]->end();
    }
    o->end();
  }

  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void *)win);
  }

  win->position(CTX.ctx_position[0], CTX.ctx_position[1]);
  win->end();
}

void meshContextWindow::show(int pane)
{
  for(int i = 0; i < 3; i++)
    group[i]->hide();
  group[pane]->show();
  win->show();
}
