// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "quadMeshingToolsWindow.h"
#include "gmshCrossFields.h"
#include "paletteWindow.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "Generator.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "quad_meshing_tools.h"
#endif

static void qmt_crossfield_generate_cb(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  int status = computeCrossField(GModel::current(), opt);
  if (status != 0) {
    Msg::Error("failed to compute cross field");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  int statusH = computeH(GModel::current(), opt);
  if (statusH != 0) {
    Msg::Error("failed to compute H from cross field");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_crossfield_show_cb(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  int status = showScaledCrosses(GModel::current(), opt);
  if (status != 0) {
    Msg::Error("failed to show scaled crosses");
  }
  drawContext::global()->draw();
}

static void qmt_quad_generate(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  int status = generateQuadMesh(GModel::current(), opt);
  if (status != 0) {
    Msg::Error("failed to generate initial quad mesh (quantization)");
  }
  drawContext::global()->draw();
}

static void qmt_compute_uv(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  int status = computeUV(GModel::current(), opt);
  if (status != 0) {
    Msg::Error("failed to generate compute uv parametrisation");
  }
  drawContext::global()->draw();
}

quadMeshingToolsWindow::quadMeshingToolsWindow(int deltaFontSize) {
  opt = new QuadMeshingOptions;

  FL_NORMAL_SIZE -= deltaFontSize;
  int width = int(3.5 * IW) + 4 * WB;
  int height = 24 * BH;
  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Quad meshing tools");
  win->box(GMSH_WINDOW_BOX);

  /* Text information display */
  int y = WB;
  int x = 2 * WB;

  { /* Cross field box */
    // y += BH;
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Cross field computation");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    y += BH;

    push_crossfield_gen = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Compute");
    push_crossfield_gen->callback(qmt_crossfield_generate_cb);

    Fl_Value_Input* flv_cross_field_iter; /* auto delete ? */
    flv_cross_field_iter = new Fl_Value_Input(x, y, IW, BH, "Diffusion/projection steps");
    flv_cross_field_iter->minimum(1);
    flv_cross_field_iter->maximum(100);
    if(CTX::instance()->inputScrolling) flv_cross_field_iter->step(1);
    flv_cross_field_iter->align(FL_ALIGN_RIGHT);
    flv_cross_field_iter->value(opt->cross_field_iter);

    y += BH;
    push_crossfield_show = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Show");
    push_crossfield_show->callback(qmt_crossfield_show_cb);
    // if (!crossfield || !H) push_crossfield_show->clear_active();
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* uv param box */
    y += BH;
    Fl_Box *b =
      new Fl_Box(x - WB, y, width, BH, "UV-parametrisation computation");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a cross-field");

    // y += BH;
    push_compute_uv = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Compute");
    push_compute_uv->callback(qmt_compute_uv);
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* cutting */
    y += BH;
    Fl_Box *b =
      new Fl_Box(x - WB, y, width, BH, "Mesh cutting from UV-parametrisation");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a UV-parametrisation");

    y += BH;
    Fl_Input* fli_name_cut;
    fli_name_cut = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_cut->align(FL_ALIGN_RIGHT);
    fli_name_cut->value("cut");

    // y += BH;
    push_compute_uv = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Cut");
    push_compute_uv->callback(qmt_compute_uv);
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* Quantization box */
    y += BH;
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Quad mesh generation via quantization");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a classified triangulation");

    y += BH;
    Fl_Input* fli_name_qinit;
    fli_name_qinit = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_qinit->align(FL_ALIGN_RIGHT);
    fli_name_qinit->value("quad");

    // y += BH;
    push_quad_generate = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Generate");
    push_quad_generate->callback(qmt_quad_generate);
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* Simplification box */
    y += BH;
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Quad mesh simplification (chord collapses)");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a quad mesh");

    y += BH;
    Fl_Value_Input* flv_simplify_factor; /* auto delete ? */
    flv_simplify_factor = new Fl_Value_Input(x, y, IW, BH, "Collapse size factor");
    flv_simplify_factor->minimum(0.1);
    flv_simplify_factor->maximum(3.);
    if(CTX::instance()->inputScrolling) flv_simplify_factor->step(0.01);
    flv_simplify_factor->align(FL_ALIGN_RIGHT);
    flv_simplify_factor->value(opt->simplify_size_factor);

    y += BH;
    Fl_Input* fli_name_qsmp;
    fli_name_qsmp = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_qsmp->align(FL_ALIGN_RIGHT);
    fli_name_qsmp->value("quad_simplified");

    // y += BH;
    push_quad_simplify = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Simplify");
    push_quad_simplify->callback(qmt_quad_generate);
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* Smoothing box */
    y += BH;
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Quad mesh smoothing (Winslow)");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a quad mesh");

    y += BH;
    Fl_Value_Input* flv_smoothing_iter; /* auto delete ? */
    flv_smoothing_iter = new Fl_Value_Input(x, y, IW, BH, "Explicit iterations");
    flv_smoothing_iter->minimum(1);
    flv_smoothing_iter->maximum(10000);
    if(CTX::instance()->inputScrolling) flv_smoothing_iter->step(1);
    flv_smoothing_iter->align(FL_ALIGN_RIGHT);
    flv_smoothing_iter->value(opt->smoothing_explicit_iter);

    // y += BH;
    push_quad_smooth = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Smooth");
    push_quad_smooth->callback(qmt_quad_generate);
  }

  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

quadMeshingToolsWindow::~quadMeshingToolsWindow() { 
  Fl::delete_widget(win);
  delete opt;
}

void quadMeshingToolsWindow::show(bool redrawOnly) {
  if(win->shown() && redrawOnly)
    win->redraw();
  else {
    if (crossfield) {
      push_crossfield_show->activate();
    } else {
      // push_crossfield_show->clear_active();
    }
    win->show();
  }
}

void quadmeshingtools_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char *)data;
  if(str && !strcmp(str, "redraw_only"))
    FlGui::instance()->quadmeshingtools->show(true);
  else
    FlGui::instance()->quadmeshingtools->show(false);
}
