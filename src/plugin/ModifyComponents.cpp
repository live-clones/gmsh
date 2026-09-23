// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <algorithm>
#include "GmshConfig.h"
#include "ModifyComponents.h"
#include "OctreePost.h"
#include "mathEvaluator.h"

GMSH_ModifyComponentsPlugin::GMSH_ModifyComponentsPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "TimeStep", nullptr, -1., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""},
                     {GMSH_FULLRC, "OtherTimeStep", nullptr, -1., ""},
                     {GMSH_FULLRC, "OtherView", nullptr, -1., ""},
                     {GMSH_FULLRC, "ForceInterpolation", nullptr, 0., ""}},
                    {{GMSH_FULLRC, "Expression0", nullptr, "v0 * Sin(x)", ""},
                     {GMSH_FULLRC, "Expression1", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression2", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression3", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression4", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression5", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression6", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression7", nullptr, "", ""},
                     {GMSH_FULLRC, "Expression8", nullptr, "", ""}})
{
}

std::string GMSH_ModifyComponentsPlugin::getHelp() const
{
  return "Plugin(ModifyComponents) modifies the components of "
         "the `TimeStep'-th time step in the view `View', using the "
         "expressions provided in `Expression0', ..., `Expression8'. "
         "If an expression is empty, the corresponding component in "
         "the view is not modified.\n\n"
         "The expressions can contain:\n\n"
         "- the usual mathematical functions (Log, Sqrt, "
         "Sin, Cos, Fabs, ...) and operators (+, -, *, /, ^);\n\n"
         "- the symbols x, y and z, to retrieve the "
         "coordinates of the current node;\n\n"
         "- the symbols Time and TimeStep, to retrieve the "
         "current time and time step values;\n\n"
         "- the symbols v0, v1, v2, ..., v8, to retrieve each "
         "component of the field in `View' at the "
         "`TimeStep'-th time step;\n\n"
         "- the symbols w0, w1, w2, ..., w8, to retrieve each "
         "component of the field in `OtherView' at the "
         "`OtherTimeStep'-th time step. If `OtherView' "
         "and `View' are based on different spatial grids, "
         "or if their data types are different, `OtherView' "
         "is interpolated onto `View'.\n\n"
         "If `TimeStep' < 0, the plugin automatically loops "
         "over all the time steps in `View' and evaluates "
         "the expressions for each one.\n\n"
         "If `OtherTimeStep' < 0, the plugin uses `TimeStep' "
         "instead.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "If `OtherView' < 0, the plugin uses `View' instead.\n\n"
         "Plugin(ModifyComponents) is executed in-place.";
}

PView *GMSH_ModifyComponentsPlugin::execute(PView *view)
{
  int timeStep = (int)option(0);
  int iView = (int)option(1);
  int otherTimeStep = (int)option(2);
  int otherView = (int)option(3);
  int forceInterpolation = (int)option(4);

  PView *v1 = getView(iView, view);
  if(!v1) return view;

  PViewData *data1 = v1->getData();

  if(timeStep > data1->getNumTimeSteps() - 1) {
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
               timeStep, v1->getIndex());
    timeStep = 0;
  }

  PView *v2 = v1;

  if(otherView >= 0) {
    if(otherView < (int)PView::list.size())
      v2 = PView::list[otherView];
    else
      Msg::Error("View[%d] does not exist: using self", otherView);
  }

  // the view itself is changed, not the adapted data drawn from it: read the
  // other view the same way
  PViewData *data2 = v2->getData();

  if(otherTimeStep < 0 &&
     data2->getNumTimeSteps() != data1->getNumTimeSteps()) {
    Msg::Error("Number of time steps don't match: using step 0");
    otherTimeStep = 0;
  }
  else if(otherTimeStep > data2->getNumTimeSteps() - 1) {
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
               otherTimeStep, v2->getIndex());
    otherTimeStep = 0;
  }

  std::vector<std::string> expressions(9), expressions0(9);
  for(int i = 0; i < 9; i++) {
    expressions[i] = optionStr(i);
    if(expressions[i].size())
      expressions0[i] = expressions[i];
    else
      expressions0[i] = "0.";
  }

  const char *names[] = {"x",  "y",  "z",  "Time", "TimeStep", "v0", "v1", "v2",
                         "v3", "v4", "v5", "v6",   "v7",       "v8", "w0", "w1",
                         "w2", "w3", "w4", "w5",   "w6",       "w7", "w8"};
  std::size_t numVariables = sizeof(names) / sizeof(names[0]);
  std::vector<std::string> variables(numVariables);
  for(std::size_t i = 0; i < numVariables; i++) variables[i] = names[i];
  mathEvaluator f(expressions0, variables);

  std::vector<double> values(numVariables), res(9);

  OctreePost *octree = nullptr;
  if(forceInterpolation ||
     (data1->getNumEntities() != data2->getNumEntities()) ||
     (data1->getNumElements() != data2->getNumElements())) {
    Msg::Info("Other view based on different grid: interpolating...");
    octree = new OctreePost(v2);
  }

  bool failed = false;
  for(int step = 0; step < data1->getNumTimeSteps(); step++) {
    if(timeStep >= 0 && timeStep != step) continue;

    double time = data1->getTime(step);
    int step2 = (otherTimeStep < 0) ? step : otherTimeStep;

    forEachValue(data1, step, [&](int ent, int ele, int nod, double x,
                                  double y, double z) {
      if(failed) return; // the error is reported once
      int numComp = data1->getNumComponents(step, ent, ele);
      std::vector<double> v(std::max(9, numComp), 0.);
      for(int comp = 0; comp < numComp; comp++)
        data1->getValue(step, ent, ele, nod, comp, v[comp]);
      std::vector<double> w(9, 0.);
      if(octree) {
        // with ForceInterpolation, search in the element of the node first
        int qn = forceInterpolation ? data1->getNumNodes(step, ent, ele) : 0;
        std::vector<double> xe(qn), ye(qn), ze(qn);
        for(int i = 0; i < qn; i++)
          data1->getNode(step, ent, ele, i, xe[i], ye[i], ze[i]);
        double *px = qn ? &xe[0] : nullptr, *py = qn ? &ye[0] : nullptr,
               *pz = qn ? &ze[0] : nullptr;
        if(!octree->searchScalar(x, y, z, &w[0], step2, nullptr, qn, px, py,
                                 pz))
          if(!octree->searchVector(x, y, z, &w[0], step2, nullptr, qn, px, py,
                                   pz))
            octree->searchTensor(x, y, z, &w[0], step2, nullptr, qn, px, py,
                                 pz);
      }
      else if(data2->hasTimeStep(step2) &&
              !data2->skipElement(step2, ent, ele)) {
        int numComp2 = std::min(9, data2->getNumComponents(step2, ent, ele));
        for(int comp = 0; comp < numComp2; comp++)
          data2->getValue(step2, ent, ele, nod, comp, w[comp]);
      }
      values[0] = x;
      values[1] = y;
      values[2] = z;
      values[3] = time;
      values[4] = step;
      for(int i = 0; i < 9; i++) values[5 + i] = v[i];
      for(int i = 0; i < 9; i++) values[14 + i] = w[i];
      if(!f.eval(values, res)) {
        failed = true;
        return;
      }
      for(int comp = 0; comp < numComp; comp++)
        if(expressions[comp].size())
          data1->setValue(step, ent, ele, nod, comp, res[comp]);
    });
  }

  if(octree) delete octree;

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
