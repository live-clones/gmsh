// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "manipWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "Options.h"
#include "Context.h"

void manip_cb(Fl_Widget *w, void *data) { FlGui::instance()->manip->show(); }

static void manip_update_cb(Fl_Widget *w, void *data)
{
  drawContext *ctx =
    FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
  ctx->r[0] = FlGui::instance()->manip->value[0]->value();
  ctx->r[1] = FlGui::instance()->manip->value[1]->value();
  ctx->r[2] = FlGui::instance()->manip->value[2]->value();
  ctx->t[0] = FlGui::instance()->manip->value[3]->value();
  ctx->t[1] = FlGui::instance()->manip->value[4]->value();
  ctx->t[2] = FlGui::instance()->manip->value[5]->value();
  ctx->s[0] = FlGui::instance()->manip->value[6]->value();
  ctx->s[1] = FlGui::instance()->manip->value[7]->value();
  ctx->s[2] = FlGui::instance()->manip->value[8]->value();
  ctx->setQuaternionFromEulerAngles();
  drawContext::global()->draw();
}

manipWindow::manipWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 4 * BB + 2 * WB;
  int height = 5 * BH + 3 * WB;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Manipulator");
  win->box(GMSH_WINDOW_BOX);

  Fl_Box *top[3], *left[3];
  top[0] = new Fl_Box(WB + 1 * BB, 1 * WB + 0 * BH, BB, BH, "X");
  top[1] = new Fl_Box(WB + 2 * BB, 1 * WB + 0 * BH, BB, BH, "Y");
  top[2] = new Fl_Box(WB + 3 * BB, 1 * WB + 0 * BH, BB, BH, "Z");
  left[0] = new Fl_Box(WB + 0 * BB, 1 * WB + 1 * BH, BB, BH, "Rotation");
  left[1] = new Fl_Box(WB + 0 * BB, 1 * WB + 2 * BH, BB, BH, "Translation");
  left[2] = new Fl_Box(WB + 0 * BB, 1 * WB + 3 * BH, BB, BH, "Scale");
  for(int i = 0; i < 3; i++) {
    top[i]->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
    left[i]->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
  }

  value[0] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 1 * BH, BB, BH);
  value[0]->tooltip("General.RotationX");
  value[1] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 1 * BH, BB, BH);
  value[1]->tooltip("General.RotationY");
  value[2] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 1 * BH, BB, BH);
  value[2]->tooltip("General.RotationZ");

  value[3] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 2 * BH, BB, BH);
  value[3]->tooltip("General.TranslationX");
  value[4] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 2 * BH, BB, BH);
  value[4]->tooltip("General.TranslationY");
  value[5] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 2 * BH, BB, BH);
  value[5]->tooltip("General.TranslationZ");

  value[6] = new Fl_Value_Input(WB + 1 * BB, 1 * WB + 3 * BH, BB, BH);
  value[6]->tooltip("General.ScaleX");
  value[7] = new Fl_Value_Input(WB + 2 * BB, 1 * WB + 3 * BH, BB, BH);
  value[7]->tooltip("General.ScaleY");
  value[8] = new Fl_Value_Input(WB + 3 * BB, 1 * WB + 3 * BH, BB, BH);
  value[8]->tooltip("General.ScaleZ");

  for(int i = 0; i < 9; i++) {
    if(i < 3) {
      value[i]->minimum(0.);
      value[i]->maximum(360.);
      if(CTX::instance()->inputScrolling) value[i]->step(1.);
    }
    else if(i > 5) {
      value[i]->minimum(0.1);
      value[i]->maximum(100.);
      if(CTX::instance()->inputScrolling) value[i]->step(0.1);
    }
    value[i]->align(FL_ALIGN_RIGHT);
    value[i]->callback(manip_update_cb);
  }

  {
    Fl_Button *o =
      new Fl_Button(width - BB - WB, height - BH - WB, BB, BH, "Reset");
    o->callback(status_xyz1p_cb, (void *)"reset");
  }

  win->position(CTX::instance()->manipPosition[0],
                CTX::instance()->manipPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void manipWindow::update(bool force)
{
  if(force || win->shown()) {
    double val1 = CTX::instance()->lc;

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
    for(int i = 0; i < 3; i++) {
      value[i]->minimum(-360.);
      value[i]->maximum(360.);
      if(CTX::instance()->inputScrolling) value[i]->step(1.);
      value[i + 3]->minimum(-val1);
      value[i + 3]->maximum(val1);
      if(CTX::instance()->inputScrolling) value[i + 3]->step(val1 / 200., 1);
      value[i + 6]->minimum(0.01);
      value[i + 6]->maximum(100.);
      if(CTX::instance()->inputScrolling) value[i + 6]->step(0.01);
    }
  }
}

void manipWindow::show()
{
  update(true);
  win->show();
}
