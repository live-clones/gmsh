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
  // ONLY FOR TESTING NEW FUNCTION FOR JF
  // int vt = -1;
  // computePerTriangleScaledCrossField(GModel::current(),vt);
  // if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  // drawContext::global()->draw();
  // return;

  QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  opt.cross_field_iter = FlGui::instance()->quadmeshingtools->flv_cross_field_iter->value();
  opt.cross_field_bc_expansion = FlGui::instance()->quadmeshingtools->flv_bc_expansion->value();
  opt.cross_field_use_prescribed_if_available = FlGui::instance()->quadmeshingtools->check_cf_use_prescribed->value();
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  int status = computeCrossField(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to compute cross field");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);

  drawContext::global()->draw();
}

static void qmt_crossfield_show_cb(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  int status = showScaledCrosses(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to show scaled crosses");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_compute_uv(Fl_Widget *w, void *data)
{
  const QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  int status = computeUV(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to generate compute uv parametrisation");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_cut_with_uv_isos(Fl_Widget *w, void *data)
{
  quadMeshingToolsWindow* win = FlGui::instance()->quadmeshingtools;
  QuadMeshingOptions& opt = *win->opt;
  QuadMeshingState& state = *win->qstate;
  opt.model_cut = std::string(win->fli_name_cut->value());

  int status = computeQuadLayout(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to generate compute uv parametrisation");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_quad_sizemap(Fl_Widget *w, void *data)
{
  QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  quadMeshingToolsWindow* win = FlGui::instance()->quadmeshingtools;
  opt.sizemap_nb_quads = size_t(win->flv_sizemap_nb_quads->value());
  int status = computeQuadSizeMap(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to compute quad sizemap");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  opt.sizemap_nb_quads = state.s_nb_quad_estimate;
  win->flv_sizemap_nb_quads->value(opt.sizemap_nb_quads);
  drawContext::global()->draw();
}

static void qmt_quad_generate(Fl_Widget *w, void *data)
{
  QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  quadMeshingToolsWindow* win = FlGui::instance()->quadmeshingtools;
  opt.model_quad_init = std::string(win->fli_name_qinit->value());
  opt.fix_decomposition = FlGui::instance()->quadmeshingtools->check_fix_dcp->value();
  int status = generateQuadMesh(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to generate initial quad mesh (quantization)");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_quad_simplify(Fl_Widget *w, void *data)
{
  quadMeshingToolsWindow* win = FlGui::instance()->quadmeshingtools;
  QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  opt.simplify_size_factor = win->flv_simplify_factor->value();
  opt.model_quad = std::string(win->fli_name_qsmp->value());
  int status = simplifyQuadMesh(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to simplify quad mesh");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

static void qmt_quad_smooth(Fl_Widget *w, void *data)
{
  quadMeshingToolsWindow* win = FlGui::instance()->quadmeshingtools;
  QuadMeshingOptions& opt =  *FlGui::instance()->quadmeshingtools->opt;
  QuadMeshingState& state =  *FlGui::instance()->quadmeshingtools->qstate;
  opt.smoothing_explicit_iter = win->flv_smoothing_iter->value();
  int status = smoothQuadMesh(GModel::current(), opt, state);
  if (status != 0) {
    Msg::Error("failed to smooth quad mesh");
  }
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}


quadMeshingToolsWindow::quadMeshingToolsWindow(int deltaFontSize) {
  opt = new QuadMeshingOptions;
  qstate = new QuadMeshingState;

  FL_NORMAL_SIZE -= deltaFontSize;
  int width = int(3.5 * IW) + 4 * WB;
  int height = 28 * BH;
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
    y += BH; /* ---------------------------- new line ---------------------------------*/

    flv_cross_field_iter = new Fl_Value_Input(x, y, IW, BH, "Diffusion/projection steps");
    flv_cross_field_iter->minimum(1);
    flv_cross_field_iter->maximum(100);
    if(CTX::instance()->inputScrolling) flv_cross_field_iter->step(1);
    flv_cross_field_iter->align(FL_ALIGN_RIGHT);
    flv_cross_field_iter->value(opt->cross_field_iter);
    y += BH; /* ---------------------------- new line ---------------------------------*/

    flv_bc_expansion = new Fl_Value_Input(x, y, IW, BH, "Boundary repulsion");
    flv_bc_expansion->minimum(0);
    flv_bc_expansion->maximum(10);
    if(CTX::instance()->inputScrolling) flv_bc_expansion->step(1);
    flv_bc_expansion->align(FL_ALIGN_RIGHT);
    flv_bc_expansion->value(opt->cross_field_bc_expansion);

    push_crossfield_gen = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Compute");
    push_crossfield_gen->callback(qmt_crossfield_generate_cb);

    y += BH; /* ---------------------------- new line ---------------------------------*/
    check_cf_use_prescribed = new Fl_Check_Button(x, y, width - 4 * WB, BH, "Use prescribed singularities (if available)");
    check_cf_use_prescribed->type(FL_TOGGLE_BUTTON);
    check_cf_use_prescribed->value(opt->cross_field_use_prescribed_if_available);

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
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Mesh cutting from UV-parametrisation");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH;
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a UV-parametrisation");

    y += BH;
    fli_name_cut = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_cut->align(FL_ALIGN_RIGHT);
    fli_name_cut->value("cut");

    // y += BH;
    push_compute_uv = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Cut");
    push_compute_uv->callback(qmt_cut_with_uv_isos);
  }

  { /* Seperator */
    y += BH / 2;
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* Quantization box */
    y += BH; /* ---------------------------- new line ---------------------------------*/
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH, "Quad mesh generation via quantization");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    y += BH; /* ---------------------------- new line ---------------------------------*/
    Fl_Box *b2 = new Fl_Box(x, y, width - 4 * WB, BH);
    b2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    b2->label("- require a cut mesh (internal lines)");


    y += BH; /* ---------------------------- new line ---------------------------------*/
    flv_sizemap_nb_quads = new Fl_Value_Input(x, y, IW, BH, "Nb quads (approx.)");
    flv_sizemap_nb_quads->minimum(1);
    flv_sizemap_nb_quads->maximum(1e7);
    if(CTX::instance()->inputScrolling) flv_sizemap_nb_quads->step(10);
    flv_sizemap_nb_quads->align(FL_ALIGN_RIGHT);
    flv_sizemap_nb_quads->value(opt->sizemap_nb_quads);

    push_quad_sizemap = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Size Map");
    push_quad_sizemap->callback(qmt_quad_sizemap);

    y += BH; /* ---------------------------- new line ---------------------------------*/
    check_fix_dcp = new Fl_Check_Button(x, y, width - 4 * WB, BH, "Repair decomposition");
    check_fix_dcp->type(FL_TOGGLE_BUTTON);
    check_fix_dcp->value(opt->fix_decomposition);

    y += BH; /* ---------------------------- new line ---------------------------------*/
    fli_name_qinit = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_qinit->align(FL_ALIGN_RIGHT);
    fli_name_qinit->value("quad");

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
    flv_simplify_factor = new Fl_Value_Input(x, y, IW, BH, "Collapse size factor");
    flv_simplify_factor->minimum(0.1);
    flv_simplify_factor->maximum(3.);
    if(CTX::instance()->inputScrolling) flv_simplify_factor->step(0.01);
    flv_simplify_factor->align(FL_ALIGN_RIGHT);
    flv_simplify_factor->value(opt->simplify_size_factor);

    y += BH;
    fli_name_qsmp = new Fl_Input(x, y, IW, BH, "New model name");
    fli_name_qsmp->align(FL_ALIGN_RIGHT);
    fli_name_qsmp->value("quad_simplified");

    // y += BH;
    push_quad_simplify = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Simplify");
    push_quad_simplify->callback(qmt_quad_simplify);
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
    flv_smoothing_iter = new Fl_Value_Input(x, y, IW, BH, "Explicit iterations");
    flv_smoothing_iter->minimum(1);
    flv_smoothing_iter->maximum(10000);
    if(CTX::instance()->inputScrolling) flv_smoothing_iter->step(1);
    flv_smoothing_iter->align(FL_ALIGN_RIGHT);
    flv_smoothing_iter->value(opt->smoothing_explicit_iter);

    // y += BH;
    push_quad_smooth = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Smooth");
    push_quad_smooth->callback(qmt_quad_smooth);
  }

  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

quadMeshingToolsWindow::~quadMeshingToolsWindow() { 
  Fl::delete_widget(win);
  if (opt) delete opt;
  if (qstate) delete qstate;
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
