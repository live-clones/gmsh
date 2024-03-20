// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "highOrderToolsWindow.h"
#include "paletteWindow.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"

#if defined(HAVE_MESH)

#include "Generator.h"
#include "HighOrder.h"

#if defined(HAVE_OPTHOM)
#include "HighOrderMeshOptimizer.h"
#include "HighOrderMeshElasticAnalogy.h"
#include "HighOrderMeshFastCurving.h"
#endif

static void highordertools_runp_cb(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;

  int order = (int)o->value[0]->value();
  bool linear = !(bool)o->butt[2]->value();
  bool incomplete = (bool)o->butt[0]->value();
  bool onlyVisible = (bool)o->butt[1]->value();

  if(order == 1)
    SetOrder1(GModel::current());
  else
    SetOrderN(GModel::current(), order, linear, incomplete, onlyVisible);

  FixPeriodicMesh(GModel::current());

  /*
  distanceFromMeshToGeometry_t dist;
  computeDistanceFromMeshToGeometry (GModel::current(), dist);
  for (auto it = dist.d2.begin(); it != dist.d2.end(); ++it){
    printf("GEntity %d of dim %d : dist %12.5E\n",
           it->first->tag(), it->first->dim(), it->second);
  }
  */

  CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void chooseopti_cb(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  const int algo = o->choice[2]->value();

  switch(algo) {
  case 0: { // Optimization
    o->choice[0]->activate();
    o->choice[3]->activate();
    o->value[1]->activate();
    o->value[2]->activate();
    o->value[3]->activate();
    o->value[4]->activate();
    o->value[5]->activate();
    o->value[7]->activate();
    o->value[8]->activate();
    if(o->choice[3]->value() == 0) {
      o->value[9]->deactivate();
      o->value[10]->deactivate();
      o->value[11]->deactivate();
    }
    else {
      o->value[9]->activate();
      o->value[10]->activate();
      o->value[11]->activate();
    }
    break;
  }
  case 1: { // Elastic analogy
    o->choice[0]->deactivate();
    o->choice[3]->deactivate();
    o->value[1]->deactivate();
    o->value[2]->deactivate();
    o->value[3]->deactivate();
    o->value[4]->deactivate();
    o->value[5]->deactivate();
    o->value[7]->deactivate();
    o->value[8]->deactivate();
    o->value[9]->deactivate();
    o->value[10]->deactivate();
    o->value[11]->deactivate();
    break;
  }
  case 2: { // Fast curving
    o->choice[0]->deactivate();
    o->choice[3]->deactivate();
    o->value[1]->deactivate();
    o->value[2]->activate();
    o->value[3]->deactivate();
    o->value[4]->deactivate();
    o->value[5]->deactivate();
    o->value[7]->deactivate();
    o->value[8]->deactivate();
    o->value[9]->deactivate();
    o->value[10]->deactivate();
    o->value[11]->deactivate();
    break;
  }
  case 3: { // Fast curving 2
    o->choice[0]->deactivate();
    o->choice[3]->deactivate();
    o->value[1]->deactivate();
    o->value[2]->activate();
    o->value[3]->deactivate();
    o->value[4]->deactivate();
    o->value[5]->deactivate();
    o->value[7]->deactivate();
    o->value[8]->deactivate();
    o->value[9]->deactivate();
    o->value[10]->deactivate();
    o->value[11]->deactivate();
    break;
  }
  }
}

static void chooseopti_strategy(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  if(o->choice[3]->value() == 1)
    for(int i = 9; i <= 11; i++) o->value[i]->activate();
  else
    for(int i = 9; i <= 11; i++) o->value[i]->deactivate();
}

static void highordertools_runopti_cb(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;

  if(o->butt[3]->value()) FlGui::instance()->graph[0]->showMessages();

  const int algo = o->choice[2]->value();
  bool onlyVisible = (bool)o->butt[1]->value();

  int NE = 0;
  for(auto it = GModel::current()->firstRegion();
      it != GModel::current()->lastRegion(); ++it) {
    NE += (*it)->getNumMeshElements();
  }
  int dim = GModel::current()->getDim() == 3 ? (NE ? 3 : 2) :
                                               GModel::current()->getDim();

#if defined(HAVE_OPTHOM)
  switch(algo) {
  case 0: { // Optimization
    OptHomParameters p;
    p.nbLayers = (int)o->value[2]->value();
    p.BARRIER_MIN = o->value[1]->value();
    p.BARRIER_MAX = o->value[8]->value();
    p.onlyVisible = onlyVisible;
    // change dim if no 3D elements are there
    p.dim = dim;
    p.itMax = (int)o->value[3]->value();
    p.optPassMax = (int)o->value[4]->value();
    p.weight = o->value[5]->value();
    p.distanceFactor = o->value[7]->value();
    // should handle periodic case here:
    p.fixBndNodes = (o->CAD && o->choice[0]->value()) ? 1 : 0;
    p.strategy = o->choice[3]->value();
    p.maxAdaptBlob = o->value[9]->value();
    p.adaptBlobLayerFact = (int)o->value[10]->value();
    p.adaptBlobDistFact = o->value[11]->value();
    p.optPrimSurfMesh = false;
    HighOrderMeshOptimizer(GModel::current(), p);
    break;
  }
  case 1: { // Elastic analogy
    HighOrderMeshElasticAnalogy(GModel::current(), onlyVisible);
    break;
  }
  case 2: { // Fast curving
    FastCurvingParameters p;
    p.onlyVisible = onlyVisible;
    p.thickness = false;
    p.dim = dim;
    p.curveOuterBL =
      (FastCurvingParameters::OUTERBLCURVE)CTX::instance()->mesh.hoCurveOuterBL;
    p.maxNumLayers = (int)o->value[2]->value();
    p.maxRho = CTX::instance()->mesh.hoMaxRho;
    p.maxAngle = CTX::instance()->mesh.hoMaxAngle;
    p.maxAngleInner = CTX::instance()->mesh.hoMaxInnerAngle;
    HighOrderMeshFastCurving(GModel::current(), p);
    break;
  }
  case 3: { // Fast curving 2
    FastCurvingParameters p;
    p.onlyVisible = onlyVisible;
    p.thickness = true;
    p.curveOuterBL =
      (FastCurvingParameters::OUTERBLCURVE)CTX::instance()->mesh.hoCurveOuterBL;
    p.maxNumLayers = (int)o->value[2]->value();
    p.maxRho = CTX::instance()->mesh.hoMaxRho;
    p.maxAngle = CTX::instance()->mesh.hoMaxAngle;
    p.maxAngleInner = CTX::instance()->mesh.hoMaxInnerAngle;
    if(dim == 3) {
      p.dim = 2;
      HighOrderMeshFastCurving(GModel::current(), p);
    }
    p.dim = dim;
    HighOrderMeshFastCurving(GModel::current(), p);
    break;
  }
  }
#else
  Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif

  FixPeriodicMesh(GModel::current());

  CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void getMeshInfoForHighOrder(GModel *gm, int &meshOrder, bool &complete,
                                    bool &CAD)
{
  meshOrder = -1;
  CAD = true;
  complete = true;
  // The following code does not allow to determine accurately if elements are
  // complete or not. To be more precise, we should try to find a hexahedron if
  // order = 2+, a prism or a pyramid if order = 3+ or a tet if order = 4+ and
  // so on...  But it is more likely that we want complete elements so always
  // setting true to 'complete' variable is acceptable.
  for(auto itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
    if((*itr)->getNumMeshElements()) {
      meshOrder = (*itr)->getMeshElement(0)->getPolynomialOrder();
      // complete = (meshOrder <= 2) ? true :
      //  (*itr)->getMeshElement(0)->getNumVolumeVertices() ? true : false;
      if((*itr)->isFullyDiscrete()) CAD = false;
      break;
    }
  }
  for(auto itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
    if((*itf)->getNumMeshElements()) {
      if(meshOrder == -1) {
        meshOrder = (*itf)->getMeshElement(0)->getPolynomialOrder();
        // complete = (meshOrder <= 2) ? 1 :
        //   (*itf)->getMeshElement(0)->getNumFaceVertices();
        if((*itf)->isFullyDiscrete()) CAD = false;
        break;
      }
    }
  }
}

highOrderToolsWindow::highOrderToolsWindow(int deltaFontSize)
{
#if defined(HAVE_MESH)
  getMeshInfoForHighOrder(GModel::current(), meshOrder, complete, CAD);
#endif

  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 3 * IW + 4 * WB;
  int height = 24 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "High-order tools");
  win->box(GMSH_WINDOW_BOX);

  int y = WB;
  int x = 2 * WB;

  box = new Fl_Box(x, y, width - 4 * WB, BH);
  box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

  y += BH;

  butt[1] =
    new Fl_Check_Button(x, y, width - 4 * WB, BH,
                        "Only apply high-order tools to visible entities");
  butt[1]->type(FL_TOGGLE_BUTTON);
  butt[1]->value(1);

  y += BH;

  butt[3] =
    new Fl_Check_Button(x, y, width - 4 * WB, BH, "Show detailed log messages");
  butt[3]->type(FL_TOGGLE_BUTTON);
  butt[3]->value(0);

  {
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  {
    y += BH;
    Fl_Box *b =
      new Fl_Box(x - WB, y, width, BH, "1. Generation of high-order nodes");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  }

  y += BH;

  value[0] = new Fl_Value_Input(x, y, IW, BH, "Polynomial order");
  value[0]->minimum(1);
  value[0]->maximum(10);
  if(CTX::instance()->inputScrolling) value[0]->step(1);
  value[0]->align(FL_ALIGN_RIGHT);
  value[0]->value(meshOrder);

  y += BH;

  butt[0] = new Fl_Check_Button(x, y, width - 4 * WB, BH,
                                "Generate incomplete elements");
  butt[0]->type(FL_TOGGLE_BUTTON);
  butt[0]->value(!complete);
  // AJ: This is bad a design. Add a proper Fl_Button to toggle between
  // completeness if needed. Plus: only 2d version implemented for now
  //  butt[0]->callback(change_completeness_cb);

  y += BH;

  butt[2] = new Fl_Check_Button(x, y, width - 4 * WB, BH,
                                "Use CAD model to curve mesh");
  butt[2]->type(FL_TOGGLE_BUTTON);
  butt[2]->value(1);

  y += BH;

  push[0] = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Generate");
  push[0]->callback(highordertools_runp_cb);

  {
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  {
    y += BH;
    Fl_Box *b = new Fl_Box(x - WB, y, width, BH,
                           "2. Regularization of high-order elements");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  }

  y += BH;
  static Fl_Menu_Item menu_method[] = {
    {"Optimization", 0, nullptr, nullptr},
    {"Elastic Analogy", 0, nullptr, nullptr},
    {"Fast Curving", 0, nullptr, nullptr},
    {"Boundary Layer Curving (experimental)", 0, nullptr, nullptr},
    {nullptr}};
  choice[2] = new Fl_Choice(x, y, IW, BH, "Algorithm");
  choice[2]->align(FL_ALIGN_RIGHT);
  choice[2]->menu(menu_method);
  choice[2]->callback(chooseopti_cb);

  y += BH;
  value[1] = new Fl_Value_Input(x, y, IW / 2.0, BH);
  value[1]->minimum(0);
  value[1]->maximum(1);
  if(CTX::instance()->inputScrolling) value[1]->step(.01);
  value[1]->align(FL_ALIGN_RIGHT);
  value[1]->value(CTX::instance()->mesh.hoThresholdMin);

  value[8] =
    new Fl_Value_Input(x + IW / 2.0, y, IW / 2.0, BH, "Target Jacobian range");
  value[8]->minimum(1);
  value[8]->maximum(10);
  if(CTX::instance()->inputScrolling) value[8]->step(.01);
  value[8]->align(FL_ALIGN_RIGHT);
  value[8]->value(CTX::instance()->mesh.hoThresholdMax);

  y += BH;
  value[2] = new Fl_Value_Input(x, y, IW, BH, "Number of layers");
  value[2]->minimum(1);
  value[2]->maximum(250);
  if(CTX::instance()->inputScrolling) value[2]->step(1);
  value[2]->align(FL_ALIGN_RIGHT);
  value[2]->value(CTX::instance()->mesh.hoNLayers);

  y += BH;
  value[7] = new Fl_Value_Input(x, y, IW, BH, "Distance factor");
  value[7]->minimum(1);
  value[7]->maximum(20000);
  if(CTX::instance()->inputScrolling) value[7]->step(1);
  value[7]->align(FL_ALIGN_RIGHT);
  value[7]->value(12);

  y += BH;
  static Fl_Menu_Item menu_objf[] = {
    {"Fixed", 0, nullptr, nullptr}, {"Free", 0, nullptr, nullptr}, {nullptr}};
  choice[0] = new Fl_Choice(x, y, IW, BH, "Boundary nodes");
  choice[0]->menu(menu_objf);
  choice[0]->align(FL_ALIGN_RIGHT);

  y += BH;
  value[5] = new Fl_Value_Input(x, y, IW, BH, "Weight on node displacement");
  value[5]->align(FL_ALIGN_RIGHT);
  value[5]->value(1.);

  y += BH;
  value[3] = new Fl_Value_Input(x, y, IW, BH, "Maximum number of iterations");
  value[3]->minimum(1);
  value[3]->maximum(10000);
  if(CTX::instance()->inputScrolling) value[3]->step(10);
  value[3]->align(FL_ALIGN_RIGHT);
  value[3]->value(CTX::instance()->mesh.hoIterMax);

  y += BH;
  value[4] = new Fl_Value_Input(x, y, IW, BH, "Max. number of barrier updates");
  value[4]->minimum(1);
  value[4]->maximum(100);
  if(CTX::instance()->inputScrolling) value[4]->step(1);
  value[4]->align(FL_ALIGN_RIGHT);
  value[4]->value(CTX::instance()->mesh.hoPassMax);

  static Fl_Menu_Item menu_strategy[] = {
    {"Disjoint strong", 0, nullptr, nullptr},
    {"Adaptive one-by-one", 0, nullptr, nullptr},
    {"Disjoint weak", 0, nullptr, nullptr},
    {nullptr}};

  y += BH;
  choice[3] = new Fl_Choice(x, y, IW, BH, "Strategy");
  choice[3]->menu(menu_strategy);
  choice[3]->align(FL_ALIGN_RIGHT);
  choice[3]->callback(chooseopti_strategy);

  y += BH;
  value[9] =
    new Fl_Value_Input(x, y, IW, BH, "Max. number of patch adaptation iter.");
  value[9]->minimum(1);
  value[9]->maximum(100);
  if(CTX::instance()->inputScrolling) value[9]->step(1);
  value[9]->align(FL_ALIGN_RIGHT);
  value[9]->value(2);
  value[9]->deactivate();

  y += BH;
  value[10] = new Fl_Value_Input(x, y, IW, BH, "Num. layer adaptation factor");
  value[10]->align(FL_ALIGN_RIGHT);
  value[10]->minimum(1);
  value[10]->maximum(100);
  if(CTX::instance()->inputScrolling) value[10]->step(1);
  value[10]->value(2);
  value[10]->deactivate();

  y += BH;
  value[11] = new Fl_Value_Input(x, y, IW, BH, "Distance adaptation factor");
  value[11]->align(FL_ALIGN_RIGHT);
  value[11]->minimum(1.);
  value[11]->maximum(100.);
  if(CTX::instance()->inputScrolling) value[11]->step(1.);
  value[11]->value(2.);
  value[11]->deactivate();

  y += 1.5 * BH;
  push[1] = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Regularize");
  push[1]->callback(highordertools_runopti_cb);

  // win->resizable(o);
  win->position(CTX::instance()->hotPosition[0],
                CTX::instance()->hotPosition[1]);
  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

void highOrderToolsWindow::show(bool redrawOnly)
{
  getMeshInfoForHighOrder(GModel::current(), meshOrder, complete, CAD);

  if(win->shown() && redrawOnly)
    win->redraw();
  else {
    value[0]->value(meshOrder);
    butt[0]->value(!complete);
    if(CAD) {
      box->label("CAD model is available");
      choice[0]->value(1);
    }
    else {
      box->label("CAD model is not available");
      choice[0]->deactivate();
    }
    win->show();
  }
}

void highordertools_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char *)data;
  if(str && !strcmp(str, "redraw_only"))
    FlGui::instance()->highordertools->show(true);
  else
    FlGui::instance()->highordertools->show(false);
}

#else // HAVE_MESH

highOrderToolsWindow::highOrderToolsWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 3 * IW + 4 * WB;
  int height = 24 * BH;
  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "High-order tools");
  win->box(GMSH_WINDOW_BOX);

  int y = WB;
  int x = 2 * WB;

  box = new Fl_Box(x, y, width - 4 * WB, BH);
  box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  box->label("High-order tools requires mesh module");

  win->position(CTX::instance()->hotPosition[0],
                CTX::instance()->hotPosition[1]);
  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

void highOrderToolsWindow::show(bool redrawOnly)
{
}

void highordertools_cb(Fl_Widget *w, void *data)
{
}

#endif
