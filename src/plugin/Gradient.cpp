// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Gradient.h"
#include "shapeFunctions.h"
#include "GmshDefines.h"

GMSH_GradientPlugin::GMSH_GradientPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_GradientPlugin::getHelp() const
{
  return "Plugin(Gradient) computes the gradient of the "
         "field in the view `View'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Gradient) creates one new list-based view.";
}

PView *GMSH_GradientPlugin::execute(PView *v)
{
  int iView = (int)option(0);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  if(data1->hasMultipleMeshes()) {
    Msg::Error("Gradient plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  createListData(
    data1, {data2}, [](const PluginElement &e) { return (e.numComp == 1) ? 3 : (e.numComp == 3) ? 9 : 0; },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      element *s = e.shape();
      if(!s) return false;
      std::vector<double> val;
      e.getValues(data1, step, val);
      for(int nod = 0; nod < e.numNodes; nod++) {
        double u, v, w, f[3];
        s->getNode(nod, u, v, w);
        for(int comp = 0; comp < e.numComp; comp++) {
          s->interpolateGrad(&val[comp], u, v, w, f, e.numComp);
          res[0].insert(res[0].end(), f, f + 3);
        }
      }
      return true;
    });

  data2->setName(data1->getName() + "_Gradient");
  data2->setFileName(data1->getName() + "_Gradient.pos");
  data2->finalize();

  return v2;
}
