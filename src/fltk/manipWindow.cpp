// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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

  int width = TW;
  int height = 5 * BH + 3 * WB;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Manipulator", CTX::instance()->manipOffset);
  win->box(GMSH_WINDOW_BOX);

  // the names of the rows, then X, Y and Z sharing what is left; each line of
  // three is a row, which widens as one
  int x0 = WB + BB, w0 = width - 2 * WB - BB, cw = w0 / 3;
  static const char *names[4] = {"", "Rotation", "Translation", "Scale"};
  static const char *xyz[3] = {"X", "Y", "Z"};
  static const char *tips[9] = {
    "General.RotationX",    "General.RotationY",    "General.RotationZ",
    "General.TranslationX", "General.TranslationY", "General.TranslationZ",
    "General.ScaleX",       "General.ScaleY",       "General.ScaleZ"};
  for(int r = 0; r < 4; r++) {
    int y = WB + r * BH;
    if(r) {
      Fl_Box *b = new Fl_Box(WB, y, BB, BH, names[r]);
      b->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
    }
    Fl_Group *row = new Fl_Group(x0, y, w0, BH);
    for(int c = 0; c < 3; c++) {
      int x = x0 + c * cw, w = (c < 2) ? cw : w0 - 2 * cw;
      if(!r) {
        Fl_Box *b = new Fl_Box(x, y, w, BH, xyz[c]);
        b->align(FL_ALIGN_INSIDE | FL_ALIGN_CENTER);
      }
      else {
        value[3 * (r - 1) + c] = new Fl_Value_Input(x, y, w, BH);
        value[3 * (r - 1) + c]->tooltip(tips[3 * (r - 1) + c]);
      }
    }
    row->end();
  }

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

  win->end();
  // as narrow as the option window, wider as the window is widened
  ((paletteWindow *)win)->followWidth(width / 2, width - WB);
  ((paletteWindow *)win)->sizeRange(width, height, 0, height);

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
