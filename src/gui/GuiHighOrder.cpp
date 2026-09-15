// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "Gui.h"
#include "GuiDeclare.h"

// The high order tools: making the nodes of a high order mesh, then
// moving them until the elements are valid. What the second one offers
// depends on the algorithm, and the optimizer is the only one that uses
// more than the number of layers.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    highOrderParameters &hoStore() { return highOrderStore(); }

    bool hoOptimizing() { return hoStore().algorithm == 0; }
    // the patch adaptation fields only mean something to that one strategy
    bool hoAdaptive()
    {
      return hoOptimizing() && hoStore().strategy == 1;
    }

  } // namespace

  void highOrderRead()
  {
    int order = -1;
    bool complete = true, cad = true;
    highOrderMeshInfo(order, complete, cad);
    highOrderParameters &v = hoStore();
    if(order > 0) v.order = order;
    v.incomplete = !complete;
    v.cadAvailable = cad;
    // "free" only when there is a CAD model to move the boundary nodes along
    v.boundaryNodes = cad ? 1 : 0;
  }

  static Form describeHighOrder()
  {
    highOrderParameters &v = hoStore();
    Form p;
    p.title = "High-order tools";
    p.tabbed = false;

    {
      Pane head;
      head.fields.push_back(says([]() {
        return hoStore().cadAvailable ? "CAD model is available" :
                                        "CAD model is not available";
      }));
      head.fields.push_back(
        check("Only apply high-order tools to visible entities", &v.onlyVisible));
      head.fields.push_back(check("Show detailed log messages", &v.showLog));
      p.panes.push_back(ruled(head));
    }

    {
      Pane gen;
      gen.label = "1. Generation of high-order nodes";
      gen.fields.push_back(
        within(integer("Polynomial order", &v.order), 1, 10, 1));
      gen.fields.push_back(check("Generate incomplete elements", &v.incomplete));
      gen.fields.push_back(check("Use CAD model to curve mesh", &v.useCAD));
      gen.buttonLabel = "Generate";
      gen.button = []() {
        highOrderParameters p = hoStore();
        p.linear = !p.useCAD;
        highOrderSetOrder(p);
      };
      p.panes.push_back(ruled(gen));
    }

    {
      Pane opt;
      opt.label = "2. Regularization of high-order elements";
      opt.fields.push_back(
        choice("Algorithm", &v.algorithm,
               {"Optimization", "Elastic Analogy", "Fast Curving",
                "Boundary Layer Curving (experimental)"},
               {0, 1, 2, 3}));

      // the two ends of the range share a line, and one label; each takes half
      // the width of an input, so that the pair fills exactly one
      Field lo = shared(within(number("", &v.thresholdMin), 0., 1., .01), .5);
      Field hi = beside(shared(
        within(number("Target Jacobian range", &v.thresholdMax), 1., 10., .01),
        .5));
      lo.enabled = hoOptimizing;
      hi.enabled = hoOptimizing;
      opt.fields.push_back(lo);
      opt.fields.push_back(hi);

      // the only field every algorithm uses
      opt.fields.push_back(
        within(integer("Number of layers", &v.numLayers), 1, 250, 1));

      auto onlyOptimizer = [](Field f) {
        f.enabled = hoOptimizing;
        return f;
      };
      opt.fields.push_back(onlyOptimizer(
        within(number("Distance factor", &v.distanceFactor), 1., 20000., 1.)));
      {
        Field nodes = choice("Boundary nodes", &v.boundaryNodes,
                             {"Fixed", "Free"}, {0, 1});
        // without a CAD model there is nothing to move them along
        nodes.enabled = []() {
          return hoOptimizing() && hoStore().cadAvailable;
        };
        opt.fields.push_back(nodes);
      }
      opt.fields.push_back(onlyOptimizer(
        number("Weight on node displacement", &v.weight)));
      opt.fields.push_back(onlyOptimizer(
        within(integer("Maximum number of iterations", &v.iterMax), 1, 10000, 10)));
      opt.fields.push_back(onlyOptimizer(within(
        integer("Max. number of barrier updates", &v.passMax), 1, 100, 1)));
      opt.fields.push_back(onlyOptimizer(
        choice("Strategy", &v.strategy,
               {"Disjoint strong", "Adaptive one-by-one", "Disjoint weak"},
               {0, 1, 2})));

      auto onlyAdaptive = [](Field f) {
        f.enabled = hoAdaptive;
        return f;
      };
      opt.fields.push_back(onlyAdaptive(within(
        number("Max. number of patch adaptation iter.", &v.maxAdaptBlob), 1., 100.,
               1.)));
      opt.fields.push_back(onlyAdaptive(within(
        integer("Num. layer adaptation factor", &v.adaptBlobLayerFact), 1, 100, 1)));
      opt.fields.push_back(onlyAdaptive(within(
        number("Distance adaptation factor", &v.adaptBlobDistFact), 1., 100., 1.)));

      opt.buttonLabel = "Regularize";
      opt.button = []() {
        highOrderParameters p = hoStore();
        // free boundary nodes only mean anything when there is a CAD model
        p.fixBoundaryNodes = (p.cadAvailable && p.boundaryNodes) ? true : false;
        if(p.showLog) Gui::instance().showPanel(Gui::PanelMessageConsole, true);
        highOrderOptimize(p);
      };
      p.panes.push_back(opt);
    }
    return p;
  }

} // namespace

Ui::Form GuiHighOrder::build()
{
  Ui::Form f = describeHighOrder();
  f.id = "highOrder";
  return f;
}

void GuiHighOrder::load() { highOrderRead(); }


#endif
