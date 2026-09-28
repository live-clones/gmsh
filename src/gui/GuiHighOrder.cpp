// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>

#include "GuiHighOrder.h"
#include "Gui.h"
#include "GuiDeclare.h"
#include "Context.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MElement.h"
#include "drawContext.h"
#include "GmshMessage.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "HighOrder.h"
#endif

#if defined(HAVE_OPTHOM)
#include "HighOrderMeshOptimizer.h"
#include "HighOrderMeshElasticAnalogy.h"
#include "HighOrderMeshFastCurving.h"
#endif

using namespace Ui;
using namespace Declare;

// telling complete elements from incomplete ones would mean looking for a
// hexahedron at order 2, a prism at order 3, and so on: complete is what one
// usually wants
void GuiHighOrder::load()
{
  CTX *ctx = CTX::instance();
  if(!started) {
    started = true;
    order = ctx->mesh.order < 1 ? 2 : ctx->mesh.order;
    thresholdMin = ctx->mesh.hoThresholdMin;
    thresholdMax = ctx->mesh.hoThresholdMax;
    numLayers = ctx->mesh.hoNLayers;
    iterMax = ctx->mesh.hoIterMax;
    passMax = ctx->mesh.hoPassMax;
  }
  GModel *m = GModel::current();
  incomplete = ctx->mesh.secondOrderIncomplete ? true : false;
  cadAvailable = true;
  bool found = false;
  for(auto it = m->firstRegion(); it != m->lastRegion() && !found; ++it) {
    if(!(*it)->getNumMeshElements()) continue;
    order = (*it)->getMeshElement(0)->getPolynomialOrder();
    cadAvailable = !(*it)->isFullyDiscrete();
    found = true;
  }
  for(auto it = m->firstFace(); it != m->lastFace() && !found; ++it) {
    if(!(*it)->getNumMeshElements()) continue;
    order = (*it)->getMeshElement(0)->getPolynomialOrder();
    cadAvailable = !(*it)->isFullyDiscrete();
    found = true;
  }
  boundaryNodes =
    (cadAvailable && !CTX::instance()->mesh.hoFixBndNodes) ? 1 : 0;
}

Form GuiHighOrder::build()
{
  auto optimizing = [this]() { return algorithm == 0; };
  auto adaptive = [this]() { return algorithm == 0 && strategy == 1; };

  return {
    "highOrder", "High-order tools",
    vbox(
      {label([this]() {
         return cadAvailable ? "CAD model is available" :
                               "CAD model is not available";
       }),
       check("Only apply high-order tools to visible entities", &onlyVisible),
       check("Show detailed log messages", &showLog), rule(),
       heading("1. Generation of high-order nodes"),
       integer("Polynomial order", &order).within(1, 10, 1),
       check("Generate incomplete elements", &incomplete),
       check("Use CAD model to curve mesh", &useCAD),
       hbox({gap(), button("Generate", [this]() { generate(); })}), rule(),
       heading("2. Regularization of high-order elements"),
       choice("Algorithm", &algorithm,
              {"Optimization", "Elastic Analogy", "Fast Curving",
               "Boundary Layer Curving (experimental)"},
              {0, 1, 2, 3}),
       // each end takes half the width of an input
       hbox({number("", &thresholdMin).within(0., 1., .01).share(.5).tight()
               .enabledWhen(optimizing),
             number("Target Jacobian range", &thresholdMax)
                      .within(1., 10., .01).share(.5).tight()
               .enabledWhen(optimizing)}),
       integer("Number of layers", &numLayers).within(1, 250, 1),
       number("Distance factor", &distanceFactor)
         .within(1., 20000., 1.)
         .enabledWhen(optimizing),
       choice("Boundary nodes", &boundaryNodes, {"Fixed", "Free"}, {0, 1})
         .enabledWhen([this]() { return algorithm == 0 && cadAvailable; }),
       number("Weight on node displacement", &weight).enabledWhen(optimizing),
       integer("Maximum number of iterations", &iterMax)
         .within(1, 10000, 10)
         .enabledWhen(optimizing),
       integer("Max. number of barrier updates", &passMax)
         .within(1, 100, 1)
         .enabledWhen(optimizing),
       choice("Strategy", &strategy,
              {"Disjoint strong", "Adaptive one-by-one", "Disjoint weak"},
              {0, 1, 2})
         .enabledWhen(optimizing),
       number("Max. number of patch adaptation iter.", &maxAdaptBlob)
         .within(1., 100., 1.)
         .enabledWhen(adaptive),
       integer("Num. layer adaptation factor", &adaptBlobLayerFact)
         .within(1, 100, 1)
         .enabledWhen(adaptive),
       number("Distance adaptation factor", &adaptBlobDistFact)
         .within(1., 100., 1.)
         .enabledWhen(adaptive),
       hbox({gap(), button("Regularize", [this]() { regularize(); })})})};
}

void GuiHighOrder::generate()
{
#if defined(HAVE_MESH)
  if(order == 1)
    SetOrder1(GModel::current());
  else
    SetOrderN(GModel::current(), order, !useCAD, incomplete, onlyVisible);
  FixPeriodicMesh(GModel::current());
  CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
#else
  Msg::Error("Changing the mesh order requires the mesh module");
#endif
}

void GuiHighOrder::regularize()
{
  if(showLog) Gui::instance().showPanel(Gui::PanelMessageConsole, true);
#if defined(HAVE_MESH)
  int NE = 0;
  for(auto it = GModel::current()->firstRegion();
      it != GModel::current()->lastRegion(); ++it)
    NE += (*it)->getNumMeshElements();
  int dim = (GModel::current()->getDim() == 3) ? (NE ? 3 : 2) :
                                                 GModel::current()->getDim();

#if defined(HAVE_OPTHOM)
  switch(algorithm) {
  case 0: { // optimization
    OptHomParameters p;
    p.nbLayers = numLayers;
    p.BARRIER_MIN = thresholdMin;
    p.BARRIER_MAX = thresholdMax;
    p.onlyVisible = onlyVisible;
    p.dim = dim;
    p.itMax = iterMax;
    p.optPassMax = passMax;
    p.weight = weight;
    p.distanceFactor = distanceFactor;
    p.fixBndNodes = (cadAvailable && boundaryNodes == 0) ? 1 : 0;
    p.strategy = strategy;
    p.maxAdaptBlob = maxAdaptBlob;
    p.adaptBlobLayerFact = adaptBlobLayerFact;
    p.adaptBlobDistFact = adaptBlobDistFact;
    p.optPrimSurfMesh = false;
    HighOrderMeshOptimizer(GModel::current(), p);
    break;
  }
  case 1: // elastic analogy
    HighOrderMeshElasticAnalogy(GModel::current(), onlyVisible);
    break;
  case 2:
  case 3: { // fast curving, with or without the boundary layer thickness
    FastCurvingParameters p;
    p.onlyVisible = onlyVisible;
    p.thickness = (algorithm == 3);
    p.curveOuterBL =
      (FastCurvingParameters::OUTERBLCURVE)CTX::instance()->mesh.hoCurveOuterBL;
    p.maxNumLayers = numLayers;
    p.maxRho = CTX::instance()->mesh.hoMaxRho;
    p.maxAngle = CTX::instance()->mesh.hoMaxAngle;
    p.maxAngleInner = CTX::instance()->mesh.hoMaxInnerAngle;
    if(algorithm == 3 && dim == 3) {
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
  CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
#else
  Msg::Error("High-order mesh optimization requires the mesh module");
#endif
}

#endif
