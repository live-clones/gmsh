// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "Draw.h"
#include "manipWindow.h"
#include "shortcutWindow.h"
#include "graphicWindow.h"
#include "Options.h"
#include "Context.h"

extern Context_T CTX;

void manip_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->manip->show();
}

static void manip_update_cb(Fl_Widget *w, void *data)
{
  drawContext *ctx = GUI::instance()->graph[0]->gl->getDrawContext();
  ctx->r[0] = GUI::instance()->manip->value[0]->value();
  ctx->r[1] = GUI::instance()->manip->value[1]->value();
  ctx->r[2] = GUI::instance()->manip->value[2]->value();
  ctx->t[0] = GUI::instance()->manip->value[3]->value();
  ctx->t[1] = GUI::instance()->manip->value[4]->value();
  ctx->t[2] = GUI::instance()->manip->value[5]->value();
  ctx->s[0] = GUI::instance()->manip->value[6]->value();
  ctx->s[1] = GUI::instance()->manip->value[7]->value();
  ctx->s[2] = GUI::instance()->manip->value[8]->value();
  ctx->setQuaternionFromEulerAngles();
  Draw();
}

manipWindow::manipWindow(int fontsize)
  : _fontsize(fontsize)
{

  int width = 4 * BB + 2 * WB;
  int height = 5 * BH + 3 * WB;

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Manipulator");
  win->box(GMSH_WINDOW_BOX);

  Fl_Box *top[3], *left[3];
  top[0] = new Fl_Box(WB + 1 * BB, 1 * WB + 0 * BH, BB, BH, "X");
  top[1] = new Fl_Box(WB + 2 * BB, 1 * WB + 0 * BH, BB, BH, "Y");
  top[2] = new Fl_Box(WB + 3 * BB, 1 * WB + 0 * BH, BB, BH, "Z");
  left[0] = new Fl_Box(WB + 0 * BB, 1 * WB + 1 * BH, BB, BH, "Rotation");
  left[1] = new Fl_Box(WB + 0 * BB, 1 * WB + 2 * BH, BB, BH, "Translation");
  left[2] = new Fl_Box(WB + 0 * BB, 1 * WB + 3 * BH, BB, BH, "Scale");
  for(int i = 0; i < 3; i++){  
    top[i]->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);
    left[i]->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);
  }

  value[0] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 1 * BH, BB, BH);
  value[1] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 1 * BH, BB, BH);
  value[2] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 1 * BH, BB, BH);
  value[3] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 2 * BH, BB, BH);
  value[4] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 2 * BH, BB, BH);
  value[5] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 2 * BH, BB, BH);
  value[6] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 3 * BH, BB, BH);
  value[7] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 3 * BH, BB, BH);
  value[8] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 3 * BH, BB, BH);

  for(int i = 0; i < 9; i++){
    if(i < 3){
      value[i]->minimum(0.);
      value[i]->maximum(360.);
      value[i]->step(1.);
    }
    else if(i > 5){
      value[i]->minimum(0.1);
      value[i]->maximum(100.);
      value[i]->step(0.1);
    }
    value[i]->align(FL_ALIGN_RIGHT);
    value[i]->callback(manip_update_cb);
  }

  {
    Fl_Return_Button *o = new Fl_Return_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Reset");
    o->callback(status_xyz1p_cb, (void *)"reset");
  }
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(hide_cb, (void *)win);
  }

  win->position(CTX.manip_position[0], CTX.manip_position[1]);
  win->end();
}

void manipWindow::update(bool force)
{
  if(force || win->shown()){
    double val1 = CTX.lc;
    
    double r0 = opt_general_rotation0(0, GMSH_GET, 0);
    double r1 = opt_general_rotation1(0, GMSH_GET, 0);
    double r2 = opt_general_rotation2(0, GMSH_GET, 0);
    double t0 = opt_general_translation0(0, GMSH_GET, 0);
    double t1 = opt_general_translation1(0, GMSH_GET, 0);
    double t2 = opt_general_translation2(0, GMSH_GET, 0);
    double s0 = opt_general_scale0(0, GMSH_GET, 0);
    double s1 = opt_general_scale1(0, GMSH_GET, 0);
    double s2 = opt_general_scale2(0, GMSH_GET, 0);

    value[0]->value(r0);
    value[1]->value(r1);
    value[2]->value(r2);
    value[3]->value(t0);
    value[4]->value(t1);
    value[5]->value(t2);
    value[6]->value(s0);
    value[7]->value(s1);
    value[8]->value(s2);
    for(int i = 0; i < 3; i++){
      value[i]->minimum(-360.);
      value[i]->maximum(360.);
      value[i]->step(1.);
      value[i+3]->minimum(-val1);
      value[i+3]->maximum(val1);
      value[i+3]->step(val1/200.);
      value[i+6]->minimum(0.01);
      value[i+6]->maximum(100.);
      value[i+6]->step(0.01);
    }
  }
}

void manipWindow::show()
{
  update(true);
  win->show();
}
