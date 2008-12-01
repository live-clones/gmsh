// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include "GUI.h"
#include "optionWindow.h"
#include "shortcutWindow.h"
#include "GmshMessage.h"
#include "Options.h"
#include "Callbacks.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Context.h"

extern Context_T CTX;

extern StringXColor GeneralOptions_Color[] ;
extern StringXColor GeometryOptions_Color[] ;
extern StringXColor MeshOptions_Color[] ;
extern StringXColor SolverOptions_Color[] ;
extern StringXColor PostProcessingOptions_Color[] ;
extern StringXColor ViewOptions_Color[] ;
extern StringXColor PrintOptions_Color[] ;

static Fl_Menu_Item menu_point_display[] = {
  {"Color dot",   0, 0, 0},
  {"3D sphere",   0, 0, 0},
  {0}
};

static Fl_Menu_Item menu_point_display_post[] = {
  {"Color dot",      0, 0, 0},
  {"3D sphere",      0, 0, 0},
  {"Scaled dot",     0, 0, 0},
  {"Scaled sphere",  0, 0, 0},
  {0}
};

static Fl_Menu_Item menu_line_display[] = {
  {"Color segment", 0, 0, 0},
  {"3D cylinder",   0, 0, 0},
  {0}
};

static Fl_Menu_Item menu_line_display_post[] = {
  {"Color segment",    0, 0, 0},
  {"3D cylinder",      0, 0, 0},
  {"Tapered cylinder", 0, 0, 0},
  {0}
};

static Fl_Menu_Item menu_surface_display[] = {
  {"Cross",     0, 0, 0},
  {"Wireframe", 0, 0, 0},
  {"Solid",     0, 0, 0},
  {0}
};

static Fl_Menu_Item menu_axes_mode[] = {
  {"None",        0, 0, 0},
  {"Simple axes", 0, 0, 0},
  {"Box",         0, 0, 0},
  {"Full grid",   0, 0, 0},
  {"Open grid",   0, 0, 0},
  {"Ruler",       0, 0, 0},
  {0}
};

Fl_Menu_Item menu_font_names[] = {
  {"Times-Roman",           0, 0, (void*)FL_TIMES},
  {"Times-Bold",            0, 0, (void*)FL_TIMES_BOLD},
  {"Times-Italic",          0, 0, (void*)FL_TIMES_ITALIC},
  {"Times-BoldItalic",      0, 0, (void*)FL_TIMES_BOLD_ITALIC},
  {"Helvetica",             0, 0, (void*)FL_HELVETICA},
  {"Helvetica-Bold",        0, 0, (void*)FL_HELVETICA_BOLD},
  {"Helvetica-Oblique",     0, 0, (void*)FL_HELVETICA_ITALIC},
  {"Helvetica-BoldOblique", 0, 0, (void*)FL_HELVETICA_BOLD_ITALIC},
  {"Courier",               0, 0, (void*)FL_COURIER},
  {"Courier-Bold",          0, 0, (void*)FL_COURIER_BOLD},
  {"Courier-Oblique",       0, 0, (void*)FL_COURIER_ITALIC},
  {"Courier-BoldOblique",   0, 0, (void*)FL_COURIER_BOLD_ITALIC},
  {"Symbol",                0, 0, (void*)FL_SYMBOL},
  {"ZapfDingbats",          0, 0, (void*)FL_ZAPF_DINGBATS},
  {0}
};

optionWindow::optionWindow(int fontsize) : _fontsize(fontsize)
{
  int width = 34 * _fontsize + WB;
  int height = 13 * BH + 5 * WB;
  int L = 7 * _fontsize;

  win = new dialogWindow(width, height, CTX.non_modal_windows);
  win->box(GMSH_WINDOW_BOX);
  win->label("Options - General");

  // Buttons
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void *)win);
  }
  {
    Fl_Button *o = new Fl_Button
      ((int)(width - 2.5 * BB - 2 * WB), height - BH - WB, (int)(1.5 * BB), BH, 
       "Save as defaults");
    o->callback(options_save_cb);
  }
  {
    redraw = new Fl_Return_Button
      ((int)(width - 3.5 * BB - 3 * WB), height - BH - WB, BB, BH, "Redraw");
    redraw->callback(redraw_cb);
  }

  // Selection browser
  browser = new Fl_Hold_Browser(WB, WB, L - WB, height - 3 * WB - BH);
  browser->has_scrollbar(Fl_Browser_::VERTICAL);
  browser->add("General");
  browser->add("Geometry");
  browser->add("Mesh");
  browser->add("Solver");
  browser->add("Post-pro");
  browser->callback(options_browser_cb);
  browser->value(1);

  width -= L;
  int BW = width - 4 * WB;
  height -= WB + BH;

  // General options
  general.group = new Fl_Group(L, 0, width, height, "General Options");
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");
      general.butt[10] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable expert mode");
      general.butt[10]->type(FL_TOGGLE_BUTTON);
      general.butt[10]->callback(general_options_ok_cb);

      general.butt[13] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Show tooltips");
      general.butt[13]->type(FL_TOGGLE_BUTTON);
      general.butt[13]->callback(general_options_ok_cb);

      general.butt[6] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Show bounding boxes");
      general.butt[6]->tooltip("(Alt+b)");
      general.butt[6]->type(FL_TOGGLE_BUTTON);
      general.butt[6]->callback(general_options_ok_cb);

      general.butt[2] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, 
         "Draw simplified model during user interaction");
      general.butt[2]->tooltip("(Alt+f)");
      general.butt[2]->type(FL_TOGGLE_BUTTON);
      general.butt[2]->callback(general_options_ok_cb, (void*)"fast_redraw");

      general.butt[11] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Enable mouse hover over meshes");
      general.butt[11]->type(FL_TOGGLE_BUTTON);
      general.butt[11]->callback(general_options_ok_cb);

      general.butt[3] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Enable double buffering");
      general.butt[3]->type(FL_TOGGLE_BUTTON);
      general.butt[3]->callback(general_options_ok_cb);

      general.butt[12] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Enable antialiasing");
      general.butt[12]->type(FL_TOGGLE_BUTTON);
      general.butt[12]->callback(general_options_ok_cb);

      general.butt[5] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 8 * BH, BW, BH, 
         "Use trackball rotation instead of Euler angles");
      general.butt[5]->type(FL_TOGGLE_BUTTON);
      general.butt[5]->callback(general_options_ok_cb);

      general.butt[15] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 9 * BH, BW, BH, "Rotate around pseudo center of mass");
      general.butt[15]->type(FL_TOGGLE_BUTTON);
      general.butt[15]->callback(general_options_ok_cb, (void*)"rotation_center");

      general.push[0] = new Fl_Button
        (L + 2 * IW - 2 * WB, 2 * WB + 10 * BH, BB, BH, "Select");
      general.push[0]->callback(general_options_rotation_center_select_cb);

      general.value[8] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW / 3, BH);
      general.value[8]->callback(general_options_ok_cb, (void*)"rotation_center_coord");
      general.value[9] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 10 * BH, IW / 3, BH);
      general.value[9]->callback(general_options_ok_cb, (void*)"rotation_center_coord");
      general.value[10] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 10 * BH, IW / 3, BH, "Rotation center");
      general.value[10]->align(FL_ALIGN_RIGHT);
      general.value[10]->callback(general_options_ok_cb, (void*)"rotation_center_coord");

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Axes");

      general.choice[4] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode");
      general.choice[4]->menu(menu_axes_mode);
      general.choice[4]->align(FL_ALIGN_RIGHT);
      general.choice[4]->tooltip("(Alt+a)");
      general.choice[4]->callback(general_options_ok_cb, (void*)"general_axes");

      general.butt[16] = new Fl_Check_Button
        (L + width - (int)(0.85*IW) - 2 * WB, 2 * WB + 1 * BH, (int)(0.85*IW), BH,
         "Mikado style");
      general.butt[16]->type(FL_TOGGLE_BUTTON);
      general.butt[16]->callback(general_options_ok_cb);

      general.value[17] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH);
      general.value[17]->minimum(0.);
      general.value[17]->step(1);
      general.value[17]->maximum(100);
      general.value[17]->callback(general_options_ok_cb);
      general.value[18] = new Fl_Value_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 2 * BH, IW / 3, BH);
      general.value[18]->minimum(0.);
      general.value[18]->step(1);
      general.value[18]->maximum(100);
      general.value[18]->callback(general_options_ok_cb);
      general.value[19] = new Fl_Value_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 2 * BH, IW / 3, BH, "Axes tics");
      general.value[19]->minimum(0.);
      general.value[19]->step(1);
      general.value[19]->maximum(100);
      general.value[19]->align(FL_ALIGN_RIGHT);
      general.value[19]->callback(general_options_ok_cb);

      general.input[3] = new Fl_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW/3, BH);
      general.input[3]->callback(general_options_ok_cb);
      general.input[4] = new Fl_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 3 * BH, IW/3, BH);
      general.input[4]->callback(general_options_ok_cb);
      general.input[5] = new Fl_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 3 * BH, IW/3, BH, "Axes format");
      general.input[5]->align(FL_ALIGN_RIGHT);
      general.input[5]->callback(general_options_ok_cb);
      
      general.input[6] = new Fl_Input
        (L + 2 * WB, 2 * WB + 4 * BH, IW/3, BH);
      general.input[6]->callback(general_options_ok_cb);
      general.input[7] = new Fl_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 4 * BH, IW/3, BH);
      general.input[7]->callback(general_options_ok_cb);
      general.input[8] = new Fl_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 4 * BH, IW/3, BH, "Axes labels");
      general.input[8]->align(FL_ALIGN_RIGHT);
      general.input[8]->callback(general_options_ok_cb);

      general.butt[0] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
         "Set position and size of axes automatically");
      general.butt[0]->type(FL_TOGGLE_BUTTON);
      general.butt[0]->callback(general_options_ok_cb, (void*)"general_axes_auto");
      
      general.value[20] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH);
      general.value[20]->callback(general_options_ok_cb);
      general.value[21] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH);
      general.value[21]->callback(general_options_ok_cb);
      general.value[22] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH, "Axes minimum");
      general.value[22]->align(FL_ALIGN_RIGHT);
      general.value[22]->callback(general_options_ok_cb);

      general.value[23] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH);
      general.value[23]->callback(general_options_ok_cb);
      general.value[24] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH);
      general.value[24]->callback(general_options_ok_cb);
      general.value[25] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH, "Axes maximum");
      general.value[25]->align(FL_ALIGN_RIGHT);
      general.value[25]->callback(general_options_ok_cb);

      general.butt[1] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Show small axes");
      general.butt[1]->tooltip("(Alt+Shift+a)");
      general.butt[1]->type(FL_TOGGLE_BUTTON);
      general.butt[1]->callback(general_options_ok_cb, (void*)"general_small_axes");

      general.value[26] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH);
      general.value[26]->minimum(-2000);
      general.value[26]->maximum(2000);
      general.value[26]->step(1);
      general.value[26]->callback(general_options_ok_cb);
      general.value[27] = new Fl_Value_Input
        (L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH, "Small axes position");
      general.value[27]->align(FL_ALIGN_RIGHT);
      general.value[27]->minimum(-2000);
      general.value[27]->maximum(2000);
      general.value[27]->step(1);
      general.value[27]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Output");
      general.butt[7] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Print messages on terminal");
      general.butt[7]->type(FL_TOGGLE_BUTTON);
      general.butt[7]->callback(general_options_ok_cb);

      general.butt[8] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Save session information on exit");
      general.butt[8]->type(FL_TOGGLE_BUTTON);
      general.butt[8]->callback(general_options_ok_cb);

      general.butt[9] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW/2-WB, BH, "Save options on exit");
      general.butt[9]->type(FL_TOGGLE_BUTTON);
      general.butt[9]->callback(general_options_ok_cb);

      Fl_Button *b0 = new Fl_Button
        (L + width / 2, 2 * WB + 3 * BH, (int)(1.75*BB), BH, "Restore default options");
      b0->callback(options_restore_defaults_cb);

      general.butt[14] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
         "Ask confirmation before overwriting files");
      general.butt[14]->type(FL_TOGGLE_BUTTON);
      general.butt[14]->callback(general_options_ok_cb);

      general.value[5] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Message verbosity");
      general.value[5]->minimum(0);
      general.value[5]->maximum(10);
      general.value[5]->step(1);
      general.value[5]->align(FL_ALIGN_RIGHT);
      general.value[5]->callback(general_options_ok_cb);

      general.input[0] = new Fl_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Default file name");
      general.input[0]->align(FL_ALIGN_RIGHT);
      general.input[0]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Helpers");

      general.input[1] = new Fl_Input
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Text editor command");
      general.input[1]->align(FL_ALIGN_RIGHT);
      general.input[1]->callback(general_options_ok_cb);

      general.input[2] = new Fl_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Web browser command");
      general.input[2]->align(FL_ALIGN_RIGHT);
      general.input[2]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Aspect");
      o->hide();

      static Fl_Menu_Item menu_projection[] = {
        {"Orthographic", 0, 0, 0},
        {"Perspective", 0, 0, 0},
        {0}
      };
      general.choice[2] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Projection mode");
      general.choice[2]->menu(menu_projection);
      general.choice[2]->align(FL_ALIGN_RIGHT);
      general.choice[2]->tooltip("(Alt+o)");
      general.choice[2]->callback(general_options_ok_cb);

      general.value[14] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Z-clipping distance factor");
      general.value[14]->minimum(0.1);
      general.value[14]->maximum(10.);
      general.value[14]->step(0.1);
      general.value[14]->align(FL_ALIGN_RIGHT);
      general.value[14]->callback(general_options_ok_cb);

      general.value[15] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW/2, BH);
      general.value[15]->minimum(0.);
      general.value[15]->maximum(10.);
      general.value[15]->step(0.01);
      general.value[15]->align(FL_ALIGN_RIGHT);
      general.value[15]->callback(general_options_ok_cb);

      general.value[16] = new Fl_Value_Input
        (L + 2 * WB + IW/2, 2 * WB + 3 * BH, IW/2, BH, "Polygon offset factor/units");
      general.value[16]->minimum(0.);
      general.value[16]->maximum(10.);
      general.value[16]->step(0.01);
      general.value[16]->align(FL_ALIGN_RIGHT);
      general.value[16]->callback(general_options_ok_cb);

      general.butt[4] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Always apply polygon offset");
      general.butt[4]->type(FL_TOGGLE_BUTTON);
      general.butt[4]->callback(general_options_ok_cb);

      general.value[11] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadric subdivisions");
      general.value[11]->minimum(3);
      general.value[11]->maximum(30);
      general.value[11]->step(1);
      general.value[11]->align(FL_ALIGN_RIGHT);
      general.value[11]->callback(general_options_ok_cb);

      general.value[6] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Point size");
      general.value[6]->minimum(0.1);
      general.value[6]->maximum(50);
      general.value[6]->step(0.1);
      general.value[6]->align(FL_ALIGN_RIGHT);
      general.value[6]->callback(general_options_ok_cb);

      general.value[7] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Line width");
      general.value[7]->minimum(0.1);
      general.value[7]->maximum(50);
      general.value[7]->step(0.1);
      general.value[7]->align(FL_ALIGN_RIGHT);
      general.value[7]->callback(general_options_ok_cb);
      
      static Fl_Menu_Item menu_genvectype[] = {
        {"Line", 0, 0, 0},
        {"Arrow", 0, 0, 0},
        {"Pyramid", 0, 0, 0},
        {"3D arrow", 0, 0, 0},
        {0}
      };
      general.choice[0] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Vector display");
      general.choice[0]->menu(menu_genvectype);
      general.choice[0]->align(FL_ALIGN_RIGHT);
      general.choice[0]->callback(general_options_ok_cb);

      Fl_Button *b = new Fl_Button
        (L + 2 * IW - 2 * WB, 2 * WB + 8 * BH, BB, BH, "Edit arrow");
      b->callback(general_arrow_param_cb);

      general.choice[1] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Font");
      general.choice[1]->menu(menu_font_names);
      general.choice[1]->align(FL_ALIGN_RIGHT);
      general.choice[1]->callback(general_options_ok_cb);

      general.value[12] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Font size");
      general.value[12]->minimum(5);
      general.value[12]->maximum(40);
      general.value[12]->step(1);
      general.value[12]->align(FL_ALIGN_RIGHT);
      general.value[12]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Color");
      o->hide();

      general.value[2] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 1 * BH, IW/3, BH);
      general.value[2]->minimum(-1.);
      general.value[2]->maximum(1.);
      general.value[2]->step(0.01);
      general.value[2]->callback(general_options_ok_cb, (void*)"light_value");

      general.value[3] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 1 * BH, IW/3, BH);
      general.value[3]->minimum(-1.);
      general.value[3]->maximum(1.);
      general.value[3]->step(0.01);
      general.value[3]->callback(general_options_ok_cb, (void*)"light_value");

      general.value[4] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 1 * BH, IW/3, BH, "Light position");
      general.value[4]->minimum(-1.);
      general.value[4]->maximum(1.);
      general.value[4]->step(0.01);
      general.value[4]->align(FL_ALIGN_RIGHT);
      general.value[4]->callback(general_options_ok_cb, (void*)"light_value");

      general.value[13] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Light position divisor");
      general.value[13]->minimum(0.);
      general.value[13]->maximum(1.);
      general.value[13]->step(0.01);
      general.value[13]->align(FL_ALIGN_RIGHT);
      general.value[13]->callback(general_options_ok_cb);

      general.sphere = new spherePositionWidget
        (L + width - 2 * BH - 2 * WB, 2 * WB + 1 * BH, 2 * BH);
      general.sphere->callback(general_options_ok_cb, (void*)"light_sphere");

      general.value[1] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW/2, BH);
      general.value[1]->minimum(0);
      general.value[1]->maximum(10);
      general.value[1]->step(0.1);
      general.value[1]->callback(general_options_ok_cb);
      general.value[0] = new Fl_Value_Input
        (L + 2 * WB + IW/2, 2 * WB + 3 * BH, IW/2, BH, "Material shininess/exponent");
      general.value[0]->minimum(0);
      general.value[0]->maximum(128);
      general.value[0]->step(1);
      general.value[0]->align(FL_ALIGN_RIGHT);
      general.value[0]->callback(general_options_ok_cb);

      static Fl_Menu_Item menu_color_scheme[] = {
        {"Dark", 0, 0, 0},
        {"Light", 0, 0, 0},
        {"Grayscale", 0, 0, 0},
        {0}
      };

      general.choice[3] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Predefined color scheme");
      general.choice[3]->menu(menu_color_scheme);
      general.choice[3]->align(FL_ALIGN_RIGHT);
      general.choice[3]->tooltip("(Alt+c)");
      general.choice[3]->callback(general_options_color_scheme_cb);

      static Fl_Menu_Item menu_bg_grad[] = {
        {"None", 0, 0, 0},
        {"Vertical", 0, 0, 0},
        {"Horizontal", 0, 0, 0},
        {"Radial", 0, 0, 0},
        {0}
      };

      general.choice[5] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Background gradient");
      general.choice[5]->menu(menu_bg_grad);
      general.choice[5]->align(FL_ALIGN_RIGHT);
      general.choice[5]->callback(general_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll
        (L + 2 * WB, 3 * WB + 6 * BH, IW + 20, height - 5 * WB - 6 * BH);
      int i = 0;
      while(GeneralOptions_Color[i].str) {
        general.color[i] = new Fl_Button
          (L + 2 * WB, 3 * WB + (6 + i) * BH, IW, BH, GeneralOptions_Color[i].str);
        general.color[i]->callback(color_cb, (void *)GeneralOptions_Color[i].function);
        i++;
      }
      s->end();

      o->end();
    }
    o->end();
  }
  general.group->end();

  // Geometry options
  geo.group = new Fl_Group(L, 0, width, height, "Geometry Options");
  geo.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");
      o->hide();

      geo.value[2] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Geometry tolerance");
      geo.value[2]->align(FL_ALIGN_RIGHT);
      geo.value[2]->callback(geometry_options_ok_cb);

      geo.butt[8] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Remove duplicate entities in GEO models");
      geo.butt[8]->type(FL_TOGGLE_BUTTON);
      geo.butt[8]->callback(geometry_options_ok_cb);

      geo.butt[11] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Remove small edges in OpenCascade models");
      geo.butt[11]->type(FL_TOGGLE_BUTTON);
      geo.butt[11]->callback(geometry_options_ok_cb);

      geo.butt[12] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Remove small faces in OpenCascade models");
      geo.butt[12]->type(FL_TOGGLE_BUTTON);
      geo.butt[12]->callback(geometry_options_ok_cb);

      geo.butt[13] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Sew faces in OpenCascade models");
      geo.butt[13]->type(FL_TOGGLE_BUTTON);
      geo.butt[13]->callback(geometry_options_ok_cb);

#if !defined(HAVE_OCC)
      geo.butt[11]->deactivate();
      geo.butt[12]->deactivate();
      geo.butt[13]->deactivate();
#endif
      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Visibility");

      geo.butt[0] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Points");
      geo.butt[0]->tooltip("(Alt+p)");
      geo.butt[0]->type(FL_TOGGLE_BUTTON);
      geo.butt[0]->callback(geometry_options_ok_cb);
      
      geo.butt[1] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH, "Lines");
      geo.butt[1]->tooltip("(Alt+l)");
      geo.butt[1]->type(FL_TOGGLE_BUTTON);
      geo.butt[1]->callback(geometry_options_ok_cb);

      geo.butt[2] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surfaces");
      geo.butt[2]->tooltip("(Alt+s)");
      geo.butt[2]->type(FL_TOGGLE_BUTTON);
      geo.butt[2]->callback(geometry_options_ok_cb);

      geo.butt[3] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Volumes");
      geo.butt[3]->tooltip("(Alt+v)");
      geo.butt[3]->type(FL_TOGGLE_BUTTON);
      geo.butt[3]->callback(geometry_options_ok_cb);

      geo.butt[4] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Point numbers");
      geo.butt[4]->type(FL_TOGGLE_BUTTON);
      geo.butt[4]->callback(geometry_options_ok_cb);

      geo.butt[5] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 2 * BH, BW / 2 - WB, BH, "Line numbers");
      geo.butt[5]->type(FL_TOGGLE_BUTTON);
      geo.butt[5]->callback(geometry_options_ok_cb);

      geo.butt[6] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surface numbers");
      geo.butt[6]->type(FL_TOGGLE_BUTTON);
      geo.butt[6]->callback(geometry_options_ok_cb);

      geo.butt[7] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Volume numbers");
      geo.butt[7]->type(FL_TOGGLE_BUTTON);
      geo.butt[7]->callback(geometry_options_ok_cb);

      geo.value[0] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Normals");
      geo.value[0]->minimum(0);
      geo.value[0]->maximum(500);
      geo.value[0]->step(1);
      geo.value[0]->align(FL_ALIGN_RIGHT);
      geo.value[0]->when(FL_WHEN_RELEASE);
      geo.value[0]->callback(geometry_options_ok_cb);

      geo.value[1] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Tangents");
      geo.value[1]->minimum(0);
      geo.value[1]->maximum(500);
      geo.value[1]->step(1);
      geo.value[1]->align(FL_ALIGN_RIGHT);
      geo.value[1]->when(FL_WHEN_RELEASE);
      geo.value[1]->callback(geometry_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Aspect");
      o->hide();

      geo.choice[0] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Point display");
      geo.choice[0]->menu(menu_point_display);
      geo.choice[0]->align(FL_ALIGN_RIGHT);
      geo.choice[0]->callback(geometry_options_ok_cb);

      geo.value[3] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point size");
      geo.value[3]->minimum(0.1);
      geo.value[3]->maximum(50);
      geo.value[3]->step(0.1);
      geo.value[3]->align(FL_ALIGN_RIGHT);
      geo.value[3]->callback(geometry_options_ok_cb);

      geo.value[5] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Selected point size");
      geo.value[5]->minimum(0.1);
      geo.value[5]->maximum(50);
      geo.value[5]->step(0.1);
      geo.value[5]->align(FL_ALIGN_RIGHT);
      geo.value[5]->callback(geometry_options_ok_cb);

      geo.choice[1] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line display");
      geo.choice[1]->menu(menu_line_display);
      geo.choice[1]->align(FL_ALIGN_RIGHT);     
      geo.choice[1]->callback(geometry_options_ok_cb);

      geo.value[4] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Line width");
      geo.value[4]->minimum(0.1);
      geo.value[4]->maximum(50);
      geo.value[4]->step(0.1);
      geo.value[4]->align(FL_ALIGN_RIGHT);
      geo.value[4]->callback(geometry_options_ok_cb);

      geo.value[6] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Selected line width");
      geo.value[6]->minimum(0.1);
      geo.value[6]->maximum(50);
      geo.value[6]->step(0.1);
      geo.value[6]->align(FL_ALIGN_RIGHT);
      geo.value[6]->callback(geometry_options_ok_cb);

      geo.choice[2] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Surface display");
      geo.choice[2]->menu(menu_surface_display);
      geo.choice[2]->align(FL_ALIGN_RIGHT);     
      geo.choice[2]->callback(geometry_options_ok_cb);
      geo.choice[2]->tooltip("(Alt+d)");

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Color");
      o->hide();

      geo.butt[9] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting");
      geo.butt[9]->type(FL_TOGGLE_BUTTON);
      geo.butt[9]->tooltip("(Alt+w)");
      geo.butt[9]->callback(geometry_options_ok_cb);

      geo.butt[14] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Use two-side lighting");
      geo.butt[14]->type(FL_TOGGLE_BUTTON);
      geo.butt[14]->callback(geometry_options_ok_cb);

      geo.butt[10] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Highlight orphan entities");
      geo.butt[10]->type(FL_TOGGLE_BUTTON);
      geo.butt[10]->callback(geometry_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll
        (L + 2 * WB, 2 * WB + 4 * BH, IW + 20, height - 4 * WB - 4 * BH);
      int i = 0;
      while(GeometryOptions_Color[i].str) {
        geo.color[i] = new Fl_Button
          (L + 2 * WB, 2 * WB + (4 + i) * BH, IW, BH, GeometryOptions_Color[i].str);
        geo.color[i]->callback(color_cb, (void *)GeometryOptions_Color[i].function);
        i++;
      }
      s->end();

      o->end();
    }
    o->end();
  }
  geo.group->end();

  // Mesh options
  mesh.group = new Fl_Group(L, 0, width, height, "Mesh Options");
  mesh.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");
      o->hide();

      static Fl_Menu_Item menu_2d_algo[] = {
        {"Frontal", 0, 0, 0},
        {"Delaunay", 0, 0, 0},
        {"MeshAdapt+Delaunay", 0, 0, 0},
        {0}
      };
      static Fl_Menu_Item menu_3d_algo[] = {
        {"Tetgen+Delaunay", 0, 0, 0},
        {"Netgen", 0, 0, 0},
        {0}
      };
      static Fl_Menu_Item menu_recombine_algo[] = {
        {"Mixed Tri-Quads", 0, 0, 0},
        {"All Quads", 0, 0, 0},
        {0}
      };

      mesh.choice[2] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "2D algorithm");
      mesh.choice[2]->menu(menu_2d_algo);
      mesh.choice[2]->align(FL_ALIGN_RIGHT);
      mesh.choice[2]->callback(mesh_options_ok_cb);

      mesh.choice[3] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "3D algorithm");
      mesh.choice[3]->menu(menu_3d_algo);
      mesh.choice[3]->align(FL_ALIGN_RIGHT);
      mesh.choice[3]->callback(mesh_options_ok_cb);

      mesh.choice[5] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Recombine algorithm");
      mesh.choice[5]->menu(menu_recombine_algo);
      mesh.choice[5]->align(FL_ALIGN_RIGHT);
      mesh.choice[5]->callback(mesh_options_ok_cb);

      mesh.value[0] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Smoothing steps");
      mesh.value[0]->minimum(0);
      mesh.value[0]->maximum(100);
      mesh.value[0]->step(1);
      mesh.value[0]->align(FL_ALIGN_RIGHT);
      mesh.value[0]->callback(mesh_options_ok_cb);

      mesh.value[2] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Element size factor");
      mesh.value[2]->minimum(0.001);
      mesh.value[2]->maximum(1000);
      mesh.value[2]->step(0.01);
      mesh.value[2]->align(FL_ALIGN_RIGHT);
      mesh.value[2]->callback(mesh_options_ok_cb);

      mesh.value[25] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Minimum element size");
      mesh.value[25]->align(FL_ALIGN_RIGHT);
      mesh.value[25]->callback(mesh_options_ok_cb);

      mesh.value[26] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Maximum element size");
      mesh.value[26]->align(FL_ALIGN_RIGHT);
      mesh.value[26]->callback(mesh_options_ok_cb);

      mesh.value[3] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Element order");
      mesh.value[3]->minimum(1);
      // FIXME: this makes it possible to set > 2 by hand, but not by
      // dragging (>2 is too buggy for general use)
      mesh.value[3]->maximum(2);
      mesh.value[3]->step(1);
      mesh.value[3]->align(FL_ALIGN_RIGHT);
      mesh.value[3]->callback(mesh_options_ok_cb);

      mesh.butt[4] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 9 * BH, BW, BH, "Use incomplete high order elements");
      mesh.butt[4]->type(FL_TOGGLE_BUTTON);
      mesh.butt[4]->callback(mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Advanced");
      o->hide();

      mesh.butt[5] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Compute element sizes using point values");
      mesh.butt[5]->type(FL_TOGGLE_BUTTON);
      mesh.butt[5]->callback(mesh_options_ok_cb);

      mesh.butt[1] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Compute element sizes from curvature" );
      mesh.butt[1]->type(FL_TOGGLE_BUTTON);
      mesh.butt[1]->callback(mesh_options_ok_cb);

      mesh.butt[16] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Extend element sizes from boundary");
      mesh.butt[16]->type(FL_TOGGLE_BUTTON);
      mesh.butt[16]->callback(mesh_options_ok_cb);

      mesh.butt[2] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Optimize quality of tetrahedra");
      mesh.butt[2]->type(FL_TOGGLE_BUTTON);
      mesh.butt[2]->callback(mesh_options_ok_cb);

      mesh.butt[24] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Optimize quality of tetrahedra with Netgen");
      mesh.butt[24]->type(FL_TOGGLE_BUTTON);
#if !defined(HAVE_NETGEN)
      mesh.butt[24]->deactivate();
#endif
      mesh.butt[24]->callback(mesh_options_ok_cb);

      mesh.butt[3] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Optimize high order mesh (2D-plane only)");
      mesh.butt[3]->type(FL_TOGGLE_BUTTON);
      mesh.butt[3]->callback(mesh_options_ok_cb);

      mesh.butt[21] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Impose C1 continuity (2D-plane only)");
      mesh.butt[21]->type(FL_TOGGLE_BUTTON);
      mesh.butt[21]->callback(mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Visibility");

      mesh.butt[6] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Nodes");
      mesh.butt[6]->tooltip("(Alt+Shift+p)");
      mesh.butt[6]->type(FL_TOGGLE_BUTTON);
      mesh.butt[6]->callback(mesh_options_ok_cb);

      mesh.butt[7] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH, "Lines");
      mesh.butt[7]->tooltip("(Alt+Shift+l)");
      mesh.butt[7]->type(FL_TOGGLE_BUTTON);
      mesh.butt[7]->callback(mesh_options_ok_cb);

      mesh.butt[8] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surface edges");
      mesh.butt[8]->tooltip("(Alt+Shift+s)");
      mesh.butt[8]->type(FL_TOGGLE_BUTTON);
      mesh.butt[8]->callback(mesh_options_ok_cb);

      mesh.butt[9] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Surface faces");
      mesh.butt[9]->tooltip("(Alt+Shift+d)");
      mesh.butt[9]->type(FL_TOGGLE_BUTTON);
      mesh.butt[9]->callback(mesh_options_ok_cb);

      mesh.butt[10] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW / 2 - WB, BH, "Volume edges");
      mesh.butt[10]->tooltip("(Alt+Shift+v)");
      mesh.butt[10]->type(FL_TOGGLE_BUTTON);
      mesh.butt[10]->callback(mesh_options_ok_cb);

      mesh.butt[11] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 6 * BH, BW / 2 - WB, BH, "Volume faces");
      mesh.butt[11]->tooltip("(Alt+Shift+b)");
      mesh.butt[11]->type(FL_TOGGLE_BUTTON);
      mesh.butt[11]->callback(mesh_options_ok_cb);

      mesh.butt[12] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Node labels");
      mesh.butt[12]->type(FL_TOGGLE_BUTTON);
      mesh.butt[12]->callback(mesh_options_ok_cb);

      mesh.butt[13] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 2 * BH, BW / 2 - WB, BH, "Line labels");
      mesh.butt[13]->type(FL_TOGGLE_BUTTON);
      mesh.butt[13]->callback(mesh_options_ok_cb);

      mesh.butt[14] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surface labels");
      mesh.butt[14]->type(FL_TOGGLE_BUTTON);
      mesh.butt[14]->callback(mesh_options_ok_cb);

      mesh.butt[15] = new Fl_Check_Button
        (L + width / 2, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Volume labels");
      mesh.butt[15]->type(FL_TOGGLE_BUTTON);
      mesh.butt[15]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_label_type[] = {
        {"Number", 0, 0, 0},
        {"Elementary entity", 0, 0, 0},
        {"Physical group", 0, 0, 0},
        {"Mesh partition", 0, 0, 0},
        {"Coordinates", 0, 0, 0},
        {0}
      };
      mesh.choice[7] = new Fl_Choice
        (L + width / 2, 2 * WB + 5 * BH, width / 4 - 2 * WB, BH, "Label type");
      mesh.choice[7]->menu(menu_label_type);
      mesh.choice[7]->align(FL_ALIGN_RIGHT);
      mesh.choice[7]->callback(mesh_options_ok_cb);

      mesh.value[12] = new Fl_Value_Input
        (L + width / 2, 2 * WB + 6 * BH, width / 4 - 2 * WB, BH, "Frequency");
      mesh.value[12]->minimum(0);
      mesh.value[12]->maximum(100);
      mesh.value[12]->step(1);
      mesh.value[12]->align(FL_ALIGN_RIGHT);
      mesh.value[12]->when(FL_WHEN_RELEASE);
      mesh.value[12]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_mesh_element_types[] = {
        {"Triangles",   0, 0, 0, FL_MENU_TOGGLE},
        {"Quadrangles", 0, 0, 0, FL_MENU_TOGGLE},
        {"Tetrahedra",  0, 0, 0, FL_MENU_TOGGLE},
        {"Hexahedra",   0, 0, 0, FL_MENU_TOGGLE},
        {"Prisms",      0, 0, 0, FL_MENU_TOGGLE},
        {"Pyramids",    0, 0, 0, FL_MENU_TOGGLE},
        {0}
      };

      mesh.menu = new Fl_Menu_Button
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Elements");
      mesh.menu->menu(menu_mesh_element_types);
      mesh.menu->callback(mesh_options_ok_cb);

      mesh.value[4] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 8 * BH, IW / 4, BH);
      mesh.value[4]->minimum(0);
      mesh.value[4]->maximum(1);
      mesh.value[4]->step(0.01);
      mesh.value[4]->align(FL_ALIGN_RIGHT);
      mesh.value[4]->when(FL_WHEN_RELEASE);
      mesh.value[4]->callback(mesh_options_ok_cb);

      mesh.value[5] = new Fl_Value_Input
        (L + 2 * WB + IW / 4, 2 * WB + 8 * BH, IW / 2 - IW / 4, BH);
      mesh.value[5]->minimum(0);
      mesh.value[5]->maximum(1);
      mesh.value[5]->step(0.01);
      mesh.value[5]->align(FL_ALIGN_RIGHT);
      mesh.value[5]->when(FL_WHEN_RELEASE);
      mesh.value[5]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_quality_type[] = {
        {"Gamma", 0, 0, 0},
        {"Eta", 0, 0, 0},
        {"Rho", 0, 0, 0},
        {"Disto", 0, 0, 0},
        {0}
      };
      mesh.choice[6] = new Fl_Choice
        (L + 2 * WB + IW / 2, 2 * WB + 8 * BH, IW/2, BH, "Quality range");
      mesh.choice[6]->menu(menu_quality_type);
      mesh.choice[6]->align(FL_ALIGN_RIGHT);
      mesh.choice[6]->callback(mesh_options_ok_cb);

      mesh.value[6] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH);
      mesh.value[6]->align(FL_ALIGN_RIGHT);
      mesh.value[6]->when(FL_WHEN_RELEASE);
      mesh.value[6]->callback(mesh_options_ok_cb);

      mesh.value[7] = new Fl_Value_Input
        (L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH, "Size range");
      mesh.value[7]->align(FL_ALIGN_RIGHT);
      mesh.value[7]->when(FL_WHEN_RELEASE);
      mesh.value[7]->callback(mesh_options_ok_cb);

      mesh.value[8] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Normals");
      mesh.value[8]->minimum(0);
      mesh.value[8]->maximum(500);
      mesh.value[8]->step(1);
      mesh.value[8]->align(FL_ALIGN_RIGHT);
      mesh.value[8]->when(FL_WHEN_RELEASE);
      mesh.value[8]->callback(mesh_options_ok_cb);

      mesh.value[13] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Tangents");
      mesh.value[13]->minimum(0);
      mesh.value[13]->maximum(200);
      mesh.value[13]->step(1.0);
      mesh.value[13]->align(FL_ALIGN_RIGHT);
      mesh.value[13]->when(FL_WHEN_RELEASE);
      mesh.value[13]->callback(mesh_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Aspect");
      o->hide();

      mesh.value[9] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Element shrinking factor");
      mesh.value[9]->minimum(0);
      mesh.value[9]->maximum(1);
      mesh.value[9]->step(0.01);
      mesh.value[9]->align(FL_ALIGN_RIGHT);
      mesh.value[9]->when(FL_WHEN_RELEASE);
      mesh.value[9]->callback(mesh_options_ok_cb);

      mesh.choice[0] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      mesh.choice[0]->menu(menu_point_display);
      mesh.choice[0]->align(FL_ALIGN_RIGHT);
      mesh.choice[0]->callback(mesh_options_ok_cb);

      mesh.value[10] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size");
      mesh.value[10]->minimum(0.1);
      mesh.value[10]->maximum(50);
      mesh.value[10]->step(0.1);
      mesh.value[10]->align(FL_ALIGN_RIGHT);
      mesh.value[10]->callback(mesh_options_ok_cb);

      mesh.value[11] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line width");
      mesh.value[11]->minimum(0.1);
      mesh.value[11]->maximum(50);
      mesh.value[11]->step(0.1);
      mesh.value[11]->align(FL_ALIGN_RIGHT);
      mesh.value[11]->callback(mesh_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Color");
      o->hide();

      mesh.butt[17] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting");
      mesh.butt[17]->tooltip("(Alt+w)");
      mesh.butt[17]->type(FL_TOGGLE_BUTTON);
      mesh.butt[17]->callback(mesh_options_ok_cb, (void*)"mesh_light");

      mesh.butt[20] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Enable lighting of lines");
      mesh.butt[20]->type(FL_TOGGLE_BUTTON);
      mesh.butt[20]->callback(mesh_options_ok_cb);

      mesh.butt[18] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Use two-side lighting");
      mesh.butt[18]->type(FL_TOGGLE_BUTTON);
      mesh.butt[18]->callback(mesh_options_ok_cb);

      mesh.butt[0] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Reverse all normals");
      mesh.butt[0]->tooltip("(Alt+Shift+w)");
      mesh.butt[0]->type(FL_TOGGLE_BUTTON);
      mesh.butt[0]->callback(mesh_options_ok_cb);

      mesh.butt[19] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Smooth normals");
      mesh.butt[19]->type(FL_TOGGLE_BUTTON);
      mesh.butt[19]->callback(mesh_options_ok_cb);

      mesh.value[18] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Smoothing threshold angle");
      mesh.value[18]->minimum(0.);
      mesh.value[18]->maximum(180.);
      mesh.value[18]->step(1.);
      mesh.value[18]->align(FL_ALIGN_RIGHT);
      mesh.value[18]->when(FL_WHEN_RELEASE);
      mesh.value[18]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_mesh_color[] = {
        {"By element type", 0, 0, 0},
        {"By elementary entity", 0, 0, 0},
        {"By physical group", 0, 0, 0},
        {"By mesh partition", 0, 0, 0},
        {0}
      };
      mesh.choice[4] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Coloring mode");
      mesh.choice[4]->menu(menu_mesh_color);
      mesh.choice[4]->align(FL_ALIGN_RIGHT);
      mesh.choice[4]->callback(mesh_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll
        (L + 2 * WB, 3 * WB + 8 * BH, IW + 20, height - 5 * WB - 8 * BH);
      int i = 0;
      while(MeshOptions_Color[i].str) {
        mesh.color[i] = new Fl_Button
          (L + 2 * WB, 3 * WB + (8 + i) * BH, IW, BH, MeshOptions_Color[i].str);
        mesh.color[i]->callback(color_cb, (void *)MeshOptions_Color[i].function);
        i++;
      }
      s->end();

      o->end();
    }
    o->end();
  }
  mesh.group->end();

  // Solver options
  solver.group = new Fl_Group(L, 0, width, height, "Solver Options");
  solver.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      {
        Fl_Group *o = new Fl_Group
          (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");

        solver.value[0] = new Fl_Value_Input
          (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Maximum solver delay");
        solver.value[0]->minimum(0);
        solver.value[0]->maximum(10);
        solver.value[0]->step(1);
        solver.value[0]->align(FL_ALIGN_RIGHT);
        solver.value[0]->callback(solver_options_ok_cb);

        solver.input[0] = new Fl_Input
          (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Socket name");
        solver.input[0]->align(FL_ALIGN_RIGHT);
        solver.input[0]->callback(solver_options_ok_cb);

        solver.butt[0] = new Fl_Check_Button
          (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, 
           "Always listen to incoming connection requests");
        solver.butt[0]->type(FL_TOGGLE_BUTTON);
        solver.butt[0]->callback(solver_options_ok_cb);
        
        o->end();
      }
    }
    o->end();
  }
  solver.group->end();

  // Post-processing options
  post.group = new Fl_Group(L, 0, width, height, "Post-processing Options");
  post.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");

      static Fl_Menu_Item menu_links[] = {
        {"None", 0, 0, 0},
        {"Apply next changes to all visible views", 0, 0, 0},
        {"Apply next changes to all views", 0, 0, 0},
        {"Force same options for all visible views", 0, 0, 0},
        {"Force same options for all views", 0, 0, 0},
        {0}
      };

      post.choice[0] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "View links");
      post.choice[0]->menu(menu_links);
      post.choice[0]->align(FL_ALIGN_RIGHT);
      post.choice[0]->callback(post_options_ok_cb);

      post.value[0] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Animation delay");
      post.value[0]->minimum(0);
      post.value[0]->maximum(10);
      post.value[0]->step(0.01);
      post.value[0]->align(FL_ALIGN_RIGHT);
      post.value[0]->callback(post_options_ok_cb);

      post.butt[0] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Cycle through views instead of time steps");
      post.butt[0]->type(FL_TOGGLE_BUTTON);
      post.butt[0]->callback(post_options_ok_cb);

      post.butt[1] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Remove original views after combination");
      post.butt[1]->type(FL_TOGGLE_BUTTON);
      post.butt[1]->callback(post_options_ok_cb);

      post.butt[2] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Draw value scales horizontally");
      post.butt[2]->type(FL_TOGGLE_BUTTON);
      post.butt[2]->callback(post_options_ok_cb);

      o->end();
    }
    o->end();
  }
  post.group->end();

  // View options
  view.index = -1;
  view.group = new Fl_Group(L, 0, width, height, "View Options");
  view.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "General");

      static Fl_Menu_Item menu_plot_type[] = {
        {"3D", 0, 0, 0},
        {"2D space", 0, 0, 0},
        {"2D time", 0, 0, 0},
        {0}
      };
      view.choice[13] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Plot type");
      view.choice[13]->menu(menu_plot_type);
      view.choice[13]->align(FL_ALIGN_RIGHT);
      view.choice[13]->callback(view_options_ok_cb);

      view.input[0] = new Fl_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "View name");
      view.input[0]->align(FL_ALIGN_RIGHT);
      view.input[0]->callback(view_options_ok_cb);

      int sw = (int)(1.5 * _fontsize);
      view.butt_rep[0] = new Fl_Repeat_Button
        (L + 2 * WB, 2 * WB + 3 * BH, sw, BH, "-");
      view.butt_rep[0]->callback(view_options_timestep_decr_cb);
      view.butt_rep[1] = new Fl_Repeat_Button
        (L + 2 * WB + IW - sw, 2 * WB + 3 * BH, sw, BH, "+");
      view.butt_rep[1]->callback(view_options_timestep_incr_cb);
      view.value[50] = new Fl_Value_Input
        (L + 2 * WB + sw, 2 * WB + 3 * BH, IW - 2 * sw, BH);
      view.value[50]->callback(view_options_timestep_cb);
      view.value[50]->align(FL_ALIGN_RIGHT);
      view.value[50]->minimum(0);
      view.value[50]->maximum(0);
      view.value[50]->step(1);
      Fl_Box *a = new Fl_Box
        (L + 2 * WB + IW, 2 * WB + 3 * BH, IW / 2, BH, "Time step");
      a->box(FL_NO_BOX);
      a->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      view.range = new Fl_Group
        (L + 2 * WB, 2 * WB + 4 * BH, width - 4 * WB, 8 * BH);

      view.value[30] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Intervals");
      view.value[30]->align(FL_ALIGN_RIGHT);
      view.value[30]->minimum(1);
      view.value[30]->maximum(256);
      view.value[30]->step(1);
      view.value[30]->when(FL_WHEN_RELEASE);
      view.value[30]->callback(view_options_ok_cb);
      
      static Fl_Menu_Item menu_iso[] = {
        {"Iso-values", 0, 0, 0},
        {"Continuous map", 0, 0, 0},
        {"Filled iso-values", 0, 0, 0},
        {"Numeric values", 0, 0, 0},
        {0}
      };
      view.choice[0] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Intervals type");
      view.choice[0]->menu(menu_iso);
      view.choice[0]->align(FL_ALIGN_RIGHT);
      view.choice[0]->tooltip("(Alt+t)");
      view.choice[0]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_range[] = {
        {"Default", 0, 0, 0},
        {"Custom", 0, 0, 0},
        {"Per time step", 0, 0, 0},
        {0}
      };
      view.choice[7] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Range mode");
      view.choice[7]->menu(menu_range);
      view.choice[7]->align(FL_ALIGN_RIGHT);
      view.choice[7]->tooltip("(Alt+r)");
      view.choice[7]->callback(view_options_ok_cb, (void*)"custom_range");

      int sw2 = (int)(2.5 * _fontsize);
      view.push[1] = new Fl_Button
        (L + 2 * WB, 2 * WB + 7 * BH, sw2, BH, "Min");
      view.push[1]->callback(view_options_ok_cb, (void*)"range_min");
      view.value[31] = new Fl_Value_Input
        (L + 2 * WB + sw2, 2 * WB + 7 * BH, IW - sw2, BH, "Custom minimum");
      view.value[31]->align(FL_ALIGN_RIGHT);
      view.value[31]->when(FL_WHEN_RELEASE);
      view.value[31]->callback(view_options_ok_cb);

      view.push[2] = new Fl_Button
        (L + 2 * WB, 2 * WB + 8 * BH, sw2, BH, "Max");
      view.push[2]->callback(view_options_ok_cb, (void*)"range_max");
      view.value[32] = new Fl_Value_Input
        (L + 2 * WB + sw2, 2 * WB + 8 * BH, IW - sw2, BH, "Custom maximum");
      view.value[32]->align(FL_ALIGN_RIGHT);
      view.value[32]->when(FL_WHEN_RELEASE);
      view.value[32]->callback(view_options_ok_cb);

      view.butt[38] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 9 * BH, BW, BH, "Saturate out-of-range values");
      view.butt[38]->type(FL_TOGGLE_BUTTON);
      view.butt[38]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_scale[] = {
        {"Linear", 0, 0, 0},
        {"Logarithmic", 0, 0, 0},
        {"Double logarithmic", 0, 0, 0},
        {0}
      };
      view.choice[1] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Value scale mode");
      view.choice[1]->menu(menu_scale);
      view.choice[1]->align(FL_ALIGN_RIGHT);
      view.choice[1]->callback(view_options_ok_cb);

      view.input[1] = new Fl_Input
        (L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Number display format");
      view.input[1]->align(FL_ALIGN_RIGHT);
      view.input[1]->callback(view_options_ok_cb);

      view.range->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Axes");
      o->hide();

      view.choice[8] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode");
      view.choice[8]->menu(menu_axes_mode);
      view.choice[8]->align(FL_ALIGN_RIGHT);
      view.choice[8]->tooltip("(Alt+a)");
      view.choice[8]->callback(view_options_ok_cb, (void*)"view_axes");

      view.butt[3] = new Fl_Check_Button
        (L + width - (int)(0.85*IW) - 2 * WB, 2 * WB + 1 * BH, (int)(0.85*IW), BH,
         "Mikado style");
      view.butt[3]->type(FL_TOGGLE_BUTTON);
      view.butt[3]->callback(view_options_ok_cb);

      view.value[3] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 2 * BH, IW/3, BH);
      view.value[3]->minimum(0.);
      view.value[3]->step(1);
      view.value[3]->maximum(100);
      view.value[3]->callback(view_options_ok_cb);
      view.value[4] = new Fl_Value_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 2 * BH, IW/3, BH);
      view.value[4]->minimum(0.);
      view.value[4]->step(1);
      view.value[4]->maximum(100);
      view.value[4]->callback(view_options_ok_cb);
      view.value[5] = new Fl_Value_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 2 * BH, IW/3, BH, "Axes tics");
      view.value[5]->minimum(0.);
      view.value[5]->step(1);
      view.value[5]->maximum(100);
      view.value[5]->align(FL_ALIGN_RIGHT);
      view.value[5]->callback(view_options_ok_cb);

      view.input[7] = new Fl_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW/3, BH);
      view.input[7]->callback(view_options_ok_cb);
      view.input[8] = new Fl_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 3 * BH, IW/3, BH);
      view.input[8]->callback(view_options_ok_cb);
      view.input[9] = new Fl_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 3 * BH, IW/3, BH, "Axes format");
      view.input[9]->align(FL_ALIGN_RIGHT);
      view.input[9]->callback(view_options_ok_cb);
      
      view.input[10] = new Fl_Input
        (L + 2 * WB, 2 * WB + 4 * BH, IW/3, BH);
      view.input[10]->callback(view_options_ok_cb);
      view.input[11] = new Fl_Input
        (L + 2 * WB + 1*IW/3, 2 * WB + 4 * BH, IW/3, BH);
      view.input[11]->callback(view_options_ok_cb);
      view.input[12] = new Fl_Input
        (L + 2 * WB + 2*IW/3, 2 * WB + 4 * BH, IW/3, BH, "Axes labels");
      view.input[12]->align(FL_ALIGN_RIGHT);
      view.input[12]->callback(view_options_ok_cb);
      
      view.butt[25] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Position 3D axes automatically");
      view.butt[25]->type(FL_TOGGLE_BUTTON);
      view.butt[25]->callback(view_options_ok_cb, (void*)"view_axes_auto_3d");
      
      view.value[13] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH);
      view.value[13]->callback(view_options_ok_cb);
      view.value[14] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH);
      view.value[14]->callback(view_options_ok_cb);
      view.value[15] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH, "3D axes minimum");
      view.value[15]->align(FL_ALIGN_RIGHT);
      view.value[15]->callback(view_options_ok_cb);

      view.value[16] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH);
      view.value[16]->callback(view_options_ok_cb);
      view.value[17] = new Fl_Value_Input
        (L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH);
      view.value[17]->callback(view_options_ok_cb);
      view.value[18] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH, "3D axes maximum");
      view.value[18]->align(FL_ALIGN_RIGHT);
      view.value[18]->callback(view_options_ok_cb);

      view.butt[7] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Position 2D axes/value scale automatically");
      view.butt[7]->type(FL_TOGGLE_BUTTON);
      view.butt[7]->callback(view_options_ok_cb, (void*)"view_axes_auto_2d");
      
      view.value[20] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH);
      view.value[20]->minimum(-2000);
      view.value[20]->maximum(2000);
      view.value[20]->step(1);
      view.value[20]->callback(view_options_ok_cb);
      view.value[21] = new Fl_Value_Input
        (L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH, "2D axes/value scale position");
      view.value[21]->align(FL_ALIGN_RIGHT);
      view.value[21]->minimum(-2000);
      view.value[21]->maximum(2000);
      view.value[21]->step(1);
      view.value[21]->callback(view_options_ok_cb);

      view.value[22] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH);
      view.value[22]->minimum(0);
      view.value[22]->maximum(2000);
      view.value[22]->step(1);
      view.value[22]->callback(view_options_ok_cb);
      view.value[23] = new Fl_Value_Input
        (L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH, "2D axes/value scale size");
      view.value[23]->align(FL_ALIGN_RIGHT);
      view.value[23]->minimum(0);
      view.value[23]->maximum(2000);
      view.value[23]->step(1);
      view.value[23]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Visibility");
      o->hide();

      view.butt[4] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Show value scale");
      view.butt[4]->tooltip("(Alt+i)");
      view.butt[4]->type(FL_TOGGLE_BUTTON);
      view.butt[4]->callback(view_options_ok_cb);

      static Fl_Menu_Item time_display[] = {
        {"None", 0, 0, 0},
        {"Value if multi-step", 0, 0, 0},
        {"Value", 0, 0, 0},
        {"Step if multi-step", 0, 0, 0},
        {"Step", 0, 0, 0},
        {0}
      };
      view.choice[12] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Time display mode");
      view.choice[12]->menu(time_display);
      view.choice[12]->align(FL_ALIGN_RIGHT);
      view.choice[12]->callback(view_options_ok_cb);

      view.butt[5] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Show annotations");
      view.butt[5]->tooltip("(Alt+n)");
      view.butt[5]->type(FL_TOGGLE_BUTTON);
      view.butt[5]->callback(view_options_ok_cb);

      view.butt[10] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW / 2, BH, "Draw element outlines");
      view.butt[10]->tooltip("(Alt+e)");
      view.butt[10]->type(FL_TOGGLE_BUTTON);
      view.butt[10]->callback(view_options_ok_cb);

      view.butt[2] = new Fl_Check_Button
        (L + 2 * WB + BW / 2, 2 * WB + 4 * BH, BW / 2, BH, "Draw 3D skin only");
      view.butt[2]->type(FL_TOGGLE_BUTTON);
      view.butt[2]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_view_element_types[] = {
        {"Points",      0, 0, 0, FL_MENU_TOGGLE},
        {"Lines",       0, 0, 0, FL_MENU_TOGGLE},
        {"Triangles",   0, 0, 0, FL_MENU_TOGGLE},
        {"Quadrangles", 0, 0, 0, FL_MENU_TOGGLE},
        {"Tetrahedra",  0, 0, 0, FL_MENU_TOGGLE},
        {"Hexahedra",   0, 0, 0, FL_MENU_TOGGLE},
        {"Prisms",      0, 0, 0, FL_MENU_TOGGLE},
        {"Pyramids",    0, 0, 0, FL_MENU_TOGGLE},
        {0}
      };

      view.menu[1] = new Fl_Menu_Button
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Elements");
      view.menu[1]->menu(menu_view_element_types);
      view.menu[1]->callback(view_options_ok_cb);
      
      static Fl_Menu_Item menu_boundary[] = {
        {"None", 0, 0, 0},
        {"Dimension - 1", 0, 0, 0},
        {"Dimension - 2", 0, 0, 0},
        {"Dimension - 3", 0, 0, 0},
        {0}
      };
      view.choice[9] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Element boundary mode");
      view.choice[9]->menu(menu_boundary);
      view.choice[9]->align(FL_ALIGN_RIGHT);
      view.choice[9]->callback(view_options_ok_cb);

      view.value[0] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Normals");
      view.value[0]->minimum(0);
      view.value[0]->maximum(500);
      view.value[0]->step(1);
      view.value[0]->align(FL_ALIGN_RIGHT);
      view.value[0]->when(FL_WHEN_RELEASE);
      view.value[0]->callback(view_options_ok_cb);

      view.value[1] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Tangents");
      view.value[1]->minimum(0);
      view.value[1]->maximum(500);
      view.value[1]->step(1);
      view.value[1]->align(FL_ALIGN_RIGHT);
      view.value[1]->when(FL_WHEN_RELEASE);
      view.value[1]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_view_field_types[] = {
        {"Scalar", 0, 0, 0, FL_MENU_TOGGLE},
        {"Vector", 0, 0, 0, FL_MENU_TOGGLE},
        {"Tensor", 0, 0, 0, FL_MENU_TOGGLE},
        {0}
      };

      view.menu[0] = new Fl_Menu_Button
        (L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Fields");
      view.menu[0]->menu(menu_view_field_types);
      view.menu[0]->callback(view_options_ok_cb);

      view.value[33] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Maximum recursion level");
      view.value[33]->align(FL_ALIGN_RIGHT);
      view.value[33]->minimum(0);
      view.value[33]->maximum(8);
      view.value[33]->step(1);
      view.value[33]->when(FL_WHEN_RELEASE);
      view.value[33]->callback(view_options_ok_cb);

      view.value[34] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Target error");
      view.value[34]->align(FL_ALIGN_RIGHT);
      view.value[34]->minimum(0.);
      view.value[34]->maximum(1.);
      view.value[34]->step(1.e-3);
      view.value[34]->when(FL_WHEN_RELEASE);
      view.value[34]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Offset");
      o->hide();

      Fl_Box *b = new Fl_Box
        (FL_NO_BOX, L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Coordinate transformation:");
      b->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT);

      int ss = 2*IW/3/3+4;
      view.value[51] = new Fl_Value_Input
        (L + 2 * WB       , 2 * WB + 2 * BH, ss, BH);
      view.value[52] = new Fl_Value_Input
        (L + 2 * WB + ss  , 2 * WB + 2 * BH, ss, BH);
      view.value[53] = new Fl_Value_Input
        (L + 2 * WB + 2*ss, 2 * WB + 2 * BH, ss, BH, " X");
      view.value[40] = new Fl_Value_Input
        (L + 2 * WB + IW  , 2 * WB + 2 * BH, 7*IW/10, BH);

      view.value[54] = new Fl_Value_Input
        (L + 2 * WB       , 2 * WB + 3 * BH, ss, BH);
      view.value[55] = new Fl_Value_Input
        (L + 2 * WB + ss  , 2 * WB + 3 * BH, ss, BH);
      view.value[56] = new Fl_Value_Input
        (L + 2 * WB + 2*ss, 2 * WB + 3 * BH, ss, BH, " Y +");
      view.value[41] = new Fl_Value_Input
        (L + 2 * WB + IW  , 2 * WB + 3 * BH, 7*IW/10, BH);

      view.value[57] = new Fl_Value_Input
        (L + 2 * WB       , 2 * WB + 4 * BH, ss, BH);
      view.value[58] = new Fl_Value_Input
        (L + 2 * WB + ss  , 2 * WB + 4 * BH, ss, BH);
      view.value[59] = new Fl_Value_Input
        (L + 2 * WB + 2*ss, 2 * WB + 4 * BH, ss, BH, " Z");
      view.value[42] = new Fl_Value_Input
        (L + 2 * WB + IW  , 2 * WB + 4 * BH, 7*IW/10, BH);

      Fl_Box *b2 = new Fl_Box
        (FL_NO_BOX, L + 2 * WB + 2 * IW-3*WB, 2 * WB + 1 * BH, 7*IW/10, BH, "Raise:");
      b2->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT);

      view.value[43] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW-3*WB, 2 * WB + 2 * BH, 7*IW/10, BH);
      view.value[44] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW-3*WB, 2 * WB + 3 * BH, 7*IW/10, BH);
      view.value[45] = new Fl_Value_Input
        (L + 2 * WB + 2 * IW-3*WB, 2 * WB + 4 * BH, 7*IW/10, BH);

      view.value[46] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, 3*ss, BH, "Normal raise");

      for(int i = 40; i <= 46; i++){
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE);
        view.value[i]->callback(view_options_ok_cb);
      }
      for(int i = 51; i <= 59; i++){
        view.value[i]->minimum(-1.);
        view.value[i]->maximum(1.);
        view.value[i]->step(0.1);
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE);
        view.value[i]->callback(view_options_ok_cb);
      }

      view.butt[6] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Use general transformation expressions");
      view.butt[6]->type(FL_TOGGLE_BUTTON);
      view.butt[6]->callback(view_options_ok_cb, (void*)"general_transform");

      view.choice[11] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Data source");
      view.choice[11]->align(FL_ALIGN_RIGHT);
      view.choice[11]->add("Self");
      view.choice[11]->callback(view_options_ok_cb);

      view.value[2] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Factor");
      view.value[2]->align(FL_ALIGN_RIGHT);
      view.value[2]->when(FL_WHEN_RELEASE);
      view.value[2]->callback(view_options_ok_cb);

      view.input[4] = new Fl_Input
        (L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "X expression");
      view.input[4]->align(FL_ALIGN_RIGHT);
      view.input[4]->callback(view_options_ok_cb);

      view.input[5] = new Fl_Input
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Y expression");
      view.input[5]->align(FL_ALIGN_RIGHT);
      view.input[5]->callback(view_options_ok_cb);

      view.input[6] = new Fl_Input
        (L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Z expression");
      view.input[6]->align(FL_ALIGN_RIGHT);
      view.input[6]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Aspect");
      o->hide();

      view.value[12] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Element shrinking factor");
      view.value[12]->minimum(0.);
      view.value[12]->step(0.01);
      view.value[12]->maximum(1.);
      view.value[12]->align(FL_ALIGN_RIGHT);
      view.value[12]->when(FL_WHEN_RELEASE);
      view.value[12]->callback(view_options_ok_cb);

      view.choice[5] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      view.choice[5]->menu(menu_point_display_post);
      view.choice[5]->align(FL_ALIGN_RIGHT);
      view.choice[5]->callback(view_options_ok_cb);

      view.value[61] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size");
      view.value[61]->minimum(0.1);
      view.value[61]->maximum(50);
      view.value[61]->step(0.1);
      view.value[61]->align(FL_ALIGN_RIGHT);
      view.value[61]->callback(view_options_ok_cb);

      view.choice[6] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line display");
      view.choice[6]->menu(menu_line_display_post);
      view.choice[6]->align(FL_ALIGN_RIGHT);
      view.choice[6]->callback(view_options_ok_cb);

      view.butt[26] = new Fl_Check_Button
        (L + width - (int)(1.15*BB) - 2 * WB, 2 * WB + 4 * BH, (int)(1.15*BB), BH,
         "Stipple in 2D");
      view.butt[26]->type(FL_TOGGLE_BUTTON);
      view.butt[26]->callback(view_options_ok_cb);

      view.value[62] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Line width");
      view.value[62]->minimum(0.1);
      view.value[62]->maximum(50);
      view.value[62]->step(0.1);
      view.value[62]->align(FL_ALIGN_RIGHT);
      view.value[62]->callback(view_options_ok_cb);

      {
        view.vector = new Fl_Group
          (L + 2 * WB, 2 * WB + 6 * BH, width - 2 * WB, 4 * BH, 0);

        static Fl_Menu_Item menu_vectype[] = {
          {"Line", 0, 0, 0},
          {"Arrow", 0, 0, 0},
          {"Pyramid", 0, 0, 0},
          {"3D arrow", 0, 0, 0},
          {"Displacement", 0, 0, 0},
          {"Comet", 0, 0, 0},
          {0}
        };
        view.choice[2] = new Fl_Choice
          (L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Vector display");
        view.choice[2]->menu(menu_vectype);
        view.choice[2]->align(FL_ALIGN_RIGHT);
        view.choice[2]->callback(view_options_ok_cb);

        view.push[0] = new Fl_Button
          (L + width - (int)(1.15*BB) - 2 * WB, 2 * WB + 6 * BH, (int)(1.15*BB), BH,
           "Edit arrow");
        view.push[0]->callback(view_arrow_param_cb);

        view.value[60] = new Fl_Value_Input
          (L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Arrow size");
        view.value[60]->minimum(0);
        view.value[60]->maximum(500);
        view.value[60]->step(1);
        view.value[60]->align(FL_ALIGN_RIGHT);
        view.value[60]->callback(view_options_ok_cb);

        view.butt[0] = new Fl_Check_Button
          (L + width - (int)(1.15*BB) - 2 * WB, 2 * WB + 7 * BH, (int)(1.15*BB), BH,
           "Proportional");
        view.butt[0]->type(FL_TOGGLE_BUTTON);
        view.butt[0]->callback(view_options_ok_cb);

        view.value[63] = new Fl_Value_Input
          (L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Displacement factor");
        view.value[63]->minimum(0.);
        view.value[63]->maximum(1.);
        view.value[63]->step(0.01);
        view.value[63]->align(FL_ALIGN_RIGHT);
        view.value[63]->when(FL_WHEN_RELEASE);
        view.value[63]->callback(view_options_ok_cb);

        view.choice[10] = new Fl_Choice
          (L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Data source");
        view.choice[10]->align(FL_ALIGN_RIGHT);
        view.choice[10]->add("Self");
        view.choice[10]->callback(view_options_ok_cb);

        view.vector->end();
      }

      static Fl_Menu_Item menu_vecloc[] = {
        {"Barycenter", 0, 0, 0},
        {"Vertex", 0, 0, 0},
        {0}
      };
      view.choice[3] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Glyph location");
      view.choice[3]->menu(menu_vecloc);
      view.choice[3]->align(FL_ALIGN_RIGHT);
      view.choice[3]->callback(view_options_ok_cb);

      view.butt[1] = new Fl_Check_Button
        (L + width - (int)(1.15*BB) - 2 * WB, 2 * WB + 10 * BH, (int)(1.15*BB), BH,
         "Center glyph");
      view.butt[1]->type(FL_TOGGLE_BUTTON);
      view.butt[1]->callback(view_options_ok_cb);
      
      static Fl_Menu_Item menu_tensor[] = {
        {"Von-Mises", 0, 0, 0},
        {0}
      };
      view.choice[4] = new Fl_Choice
        (L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Tensor display");
      view.choice[4]->menu(menu_tensor);
      view.choice[4]->align(FL_ALIGN_RIGHT);
      view.choice[4]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Color");
      o->hide();

      view.butt[11] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting");
      view.butt[11]->tooltip("(Alt+w)");
      view.butt[11]->type(FL_TOGGLE_BUTTON);
      view.butt[11]->callback(view_options_ok_cb, (void*)"view_light");

      view.butt[8] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Enable lighting of lines");
      view.butt[8]->type(FL_TOGGLE_BUTTON);
      view.butt[8]->callback(view_options_ok_cb);

      view.butt[9] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Use two-side lighting");
      view.butt[9]->type(FL_TOGGLE_BUTTON);
      view.butt[9]->callback(view_options_ok_cb);

      view.butt[12] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Smooth normals");
      view.butt[12]->type(FL_TOGGLE_BUTTON);
      view.butt[12]->callback(view_options_ok_cb);

      view.value[10] = new Fl_Value_Input
        (L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Smoothing threshold angle");
      view.value[10]->minimum(0.);
      view.value[10]->step(1.);
      view.value[10]->maximum(180.);
      view.value[10]->align(FL_ALIGN_RIGHT);
      view.value[10]->when(FL_WHEN_RELEASE);
      view.value[10]->callback(view_options_ok_cb);

      view.butt[24] = new Fl_Check_Button
        (L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Use fake transparency mode");
      view.butt[24]->type(FL_TOGGLE_BUTTON);
      view.butt[24]->callback(view_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll
        (L + 2 * WB, 3 * WB + 7 * BH, IW + 20, height - 5 * WB - 7 * BH);
      int i = 0;
      while(ViewOptions_Color[i].str) {
        view.color[i] = new Fl_Button
          (L + 2 * WB, 3 * WB + (7 + i) * BH, IW, BH, ViewOptions_Color[i].str);
        view.color[i]->callback(view_color_cb, (void *)ViewOptions_Color[i].function);
        i++;
      }
      s->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group
        (L + WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Map");
      o->hide();

      view.colorbar = new colorbarWindow
        (L + 2 * WB, 2 * WB + BH, width - 4 * WB, height - 4 * WB - BH);
      view.colorbar->end();
      view.colorbar->callback(view_options_ok_cb);

      o->end();
    }
    o->end();
  }
  view.group->end();

  win->position(CTX.opt_position[0], CTX.opt_position[1]);
  win->end();
}

void optionWindow::showGroup(int num, bool showWindow)
{
  general.group->hide();
  geo.group->hide();
  mesh.group->hide();
  solver.group->hide();
  post.group->hide();
  view.group->hide();
  browser->value(num);
  switch(num){
  case 0: case 1: win->label("Options - General"); general.group->show(); break;
  case 2: win->label("Options - Geometry"); geo.group->show(); break;
  case 3: win->label("Options - Mesh"); mesh.group->show(); break;
  case 4: win->label("Options - Solver"); solver.group->show(); break;
  case 5: win->label("Options - Post-pro"); post.group->show(); break;
  default: 
    {
      updateViewGroup(num - 6);
      static char str[128];
      sprintf(str, "Options - View [%d]", num - 6);
      win->label(str);
      view.group->show();
    }
    break;
  }
  if(showWindow) win->show();
}

void optionWindow::resetBrowser()
{
  int select = browser->value();
  browser->clear();
  browser->add("General");
  browser->add("Geometry");
  browser->add("Mesh");
  browser->add("Solver");
  browser->add("Post-pro");
  for(unsigned int i = 0; i < PView::list.size(); i++){
    char str[128];
    sprintf(str, "View [%d]", i);
    browser->add(str);
  }
  int num = (select <= browser->size()) ? select : browser->size();
  browser->value(num);
  showGroup(num, false);
}

void optionWindow::resetExternalViewList()
{
  char str[32];
  view.choice[10]->clear();
  view.choice[11]->clear();
  view.choice[10]->add("Self");
  view.choice[11]->add("Self");
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    sprintf(str, "View [%d]", i);
    view.choice[10]->add(str, 0, NULL);
    view.choice[11]->add(str, 0, NULL);
  }
  if(view.index >= 0){
    opt_view_external_view(view.index, GMSH_GUI, 0);
    opt_view_gen_raise_view(view.index, GMSH_GUI, 0);
  }
}

void optionWindow::updateViewGroup(int index)
{
  if(index < 0 || index >= (int)PView::list.size()) return;

  view.index = index;

  PView *v = PView::list[index];
  PViewData *data = v->getData();
  PViewOptions *opt = v->getOptions();

  double maxval = std::max(fabs(data->getMin()), fabs(data->getMax()));
  if(!maxval) maxval = 1.;
  double val1 = 10. * CTX.lc;
  double val2 = 2. * CTX.lc / maxval;

  opt_view_name(index, GMSH_GUI, NULL);
  opt_view_format(index, GMSH_GUI, NULL);
  opt_view_type(index, GMSH_GUI, 0);
  opt_view_show_scale(index, GMSH_GUI, 0);
  opt_view_draw_strings(index, GMSH_GUI, 0);

  opt_view_max_recursion_level(index, GMSH_GUI, 0);
  opt_view_target_error(index, GMSH_GUI, 0);
  if(data->isAdaptive()){
    view.value[33]->activate();
    view.value[34]->activate();
  }
  else{
    view.value[33]->deactivate();
    view.value[34]->deactivate();
  }

  if(data->getNumPoints() || data->getNumLines()){
    ((Fl_Menu_Item*)view.choice[13]->menu())[1].activate();
    ((Fl_Menu_Item*)view.choice[13]->menu())[2].activate();
  }
  else {
    ((Fl_Menu_Item*)view.choice[13]->menu())[1].deactivate();
    ((Fl_Menu_Item*)view.choice[13]->menu())[2].deactivate();
  }

  opt_view_auto_position(index, GMSH_GUI, 0);
  opt_view_position0(index, GMSH_GUI, 0);
  opt_view_position1(index, GMSH_GUI, 0);
  opt_view_size0(index, GMSH_GUI, 0);
  opt_view_size1(index, GMSH_GUI, 0);

  opt_view_axes(index, GMSH_GUI, 0);
  opt_view_axes_mikado(index, GMSH_GUI, 0);
  opt_view_axes_format0(index, GMSH_GUI, NULL);
  opt_view_axes_format1(index, GMSH_GUI, NULL);
  opt_view_axes_format2(index, GMSH_GUI, NULL);
  opt_view_axes_tics0(index, GMSH_GUI, 0);
  opt_view_axes_tics1(index, GMSH_GUI, 0);
  opt_view_axes_tics2(index, GMSH_GUI, 0);
  opt_view_axes_label0(index, GMSH_GUI, NULL);
  opt_view_axes_label1(index, GMSH_GUI, NULL);
  opt_view_axes_label2(index, GMSH_GUI, NULL);
  opt_view_axes_auto_position(index, GMSH_GUI, 0);
  opt_view_axes_xmin(index, GMSH_GUI, 0);
  opt_view_axes_xmax(index, GMSH_GUI, 0);
  opt_view_axes_ymin(index, GMSH_GUI, 0);
  opt_view_axes_ymax(index, GMSH_GUI, 0);
  opt_view_axes_zmin(index, GMSH_GUI, 0);
  opt_view_axes_zmax(index, GMSH_GUI, 0);
  for(int i = 13; i <= 18; i++){
    view.value[i]->step(CTX.lc/200.);
    view.value[i]->minimum(-CTX.lc);
    view.value[i]->maximum(CTX.lc);
  }

  if(data->getNumElements()) {
    view.range->activate();
    ((Fl_Menu_Item*)view.choice[13]->menu())[0].activate();
  }
  else {
    view.range->deactivate();
    ((Fl_Menu_Item*)view.choice[13]->menu())[0].deactivate();
  }
  opt_view_show_element(index, GMSH_GUI, 0);
  opt_view_draw_skin_only(index, GMSH_GUI, 0);
  opt_view_light(index, GMSH_GUI, 0);
  opt_view_light_two_side(index, GMSH_GUI, 0);
  opt_view_light_lines(index, GMSH_GUI, 0);
  opt_view_smooth_normals(index, GMSH_GUI, 0);
  opt_view_angle_smooth_normals(index, GMSH_GUI, 0);
  opt_view_boundary(index, GMSH_GUI, 0);
  opt_view_explode(index, GMSH_GUI, 0);
  opt_view_draw_points(index, GMSH_GUI, 0);
  opt_view_draw_lines(index, GMSH_GUI, 0);
  opt_view_draw_triangles(index, GMSH_GUI, 0);
  opt_view_draw_quadrangles(index, GMSH_GUI, 0);
  opt_view_draw_tetrahedra(index, GMSH_GUI, 0);
  opt_view_draw_hexahedra(index, GMSH_GUI, 0);
  opt_view_draw_prisms(index, GMSH_GUI, 0);
  opt_view_draw_pyramids(index, GMSH_GUI, 0);
  opt_view_draw_scalars(index, GMSH_GUI, 0);
  opt_view_draw_vectors(index, GMSH_GUI, 0);
  opt_view_draw_tensors(index, GMSH_GUI, 0);
  opt_view_normals(index, GMSH_GUI, 0);
  opt_view_tangents(index, GMSH_GUI, 0);

  opt_view_nb_iso(index, GMSH_GUI, 0);
  opt_view_intervals_type(index, GMSH_GUI, 0);
  opt_view_range_type(index, GMSH_GUI, 0);
  opt_view_custom_min(index, GMSH_GUI, 0);
  opt_view_custom_max(index, GMSH_GUI, 0);
  opt_view_scale_type(index, GMSH_GUI, 0);
  opt_view_saturate_values(index, GMSH_GUI, 0);

  opt_view_offset0(index, GMSH_GUI, 0);
  opt_view_offset1(index, GMSH_GUI, 0);
  opt_view_offset2(index, GMSH_GUI, 0);
  for(int i = 40; i <= 42; i++) {
    view.value[i]->step(val1/100.);
    view.value[i]->minimum(-val1);
    view.value[i]->maximum(val1);
  }
  opt_view_transform00(index, GMSH_GUI, 0);
  opt_view_transform01(index, GMSH_GUI, 0);
  opt_view_transform02(index, GMSH_GUI, 0);
  opt_view_transform10(index, GMSH_GUI, 0);
  opt_view_transform11(index, GMSH_GUI, 0);
  opt_view_transform12(index, GMSH_GUI, 0);
  opt_view_transform20(index, GMSH_GUI, 0);
  opt_view_transform21(index, GMSH_GUI, 0);
  opt_view_transform22(index, GMSH_GUI, 0);
  opt_view_raise0(index, GMSH_GUI, 0);
  opt_view_raise1(index, GMSH_GUI, 0);
  opt_view_raise2(index, GMSH_GUI, 0);
  opt_view_normal_raise(index, GMSH_GUI, 0);
  for(int i = 43; i <= 46; i++) {
    view.value[i]->step(val2/100.);
    view.value[i]->minimum(-val2);
    view.value[i]->maximum(val2);
  }
  opt_view_use_gen_raise(index, GMSH_GUI, 0);
  opt_view_gen_raise_view(index, GMSH_GUI, 0);
  opt_view_gen_raise_factor(index, GMSH_GUI, 0);
  opt_view_gen_raise0(index, GMSH_GUI, 0);
  opt_view_gen_raise1(index, GMSH_GUI, 0);
  opt_view_gen_raise2(index, GMSH_GUI, 0);
  view.value[2]->step(val2/100.);
  view.value[2]->minimum(-val2);
  view.value[2]->maximum(val2);

  if(data->getNumTimeSteps() == 1) {
    view.value[50]->deactivate();
    view.butt_rep[0]->deactivate();
    view.butt_rep[1]->deactivate();
  }
  else {
    view.value[50]->activate();
    view.butt_rep[0]->activate();
    view.butt_rep[1]->activate();
  }
  view.value[50]->maximum(data->getNumTimeSteps() - 1);
  opt_view_timestep(index, GMSH_GUI, 0);
  opt_view_show_time(index, GMSH_GUI, 0);

  if(data->getNumVectors() || data->getNumTensors())
    view.vector->activate();
  else
    view.vector->deactivate();

  opt_view_point_size(index, GMSH_GUI, 0);
  opt_view_point_type(index, GMSH_GUI, 0);
  opt_view_line_width(index, GMSH_GUI, 0);
  opt_view_line_type(index, GMSH_GUI, 0);
  opt_view_vector_type(index, GMSH_GUI, 0);
  opt_view_arrow_size(index, GMSH_GUI, 0);
  opt_view_arrow_size_proportional(index, GMSH_GUI, 0);

  opt_view_displacement_factor(index, GMSH_GUI, 0);
  double val3 = 2. * CTX.lc / maxval;
  view.value[63]->step(val3/100.);
  view.value[63]->maximum(val3);

  opt_view_external_view(index, GMSH_GUI, 0);
  opt_view_glyph_location(index, GMSH_GUI, 0);
  opt_view_center_glyphs(index, GMSH_GUI, 0);
  opt_view_tensor_type(index, GMSH_GUI, 0);

  opt_view_fake_transparency(index, GMSH_GUI, 0);
  opt_view_use_stipple(index, GMSH_GUI, 0);
  opt_view_color_points(index, GMSH_GUI, 0);
  opt_view_color_lines(index, GMSH_GUI, 0);
  opt_view_color_triangles(index, GMSH_GUI, 0);
  opt_view_color_quadrangles(index, GMSH_GUI, 0);
  opt_view_color_tetrahedra(index, GMSH_GUI, 0);
  opt_view_color_hexahedra(index, GMSH_GUI, 0);
  opt_view_color_prisms(index, GMSH_GUI, 0);
  opt_view_color_pyramids(index, GMSH_GUI, 0);
  opt_view_color_tangents(index, GMSH_GUI, 0);
  opt_view_color_normals(index, GMSH_GUI, 0);
  opt_view_color_text2d(index, GMSH_GUI, 0);
  opt_view_color_text3d(index, GMSH_GUI, 0);
  opt_view_color_axes(index, GMSH_GUI, 0);

  view.colorbar->update(data->getName().c_str(), data->getMin(), 
                        data->getMax(), &opt->CT, &v->getChanged());
}
