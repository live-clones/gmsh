// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Eigenvalues.h"
#include "Numeric.h"
#include "GmshDefines.h"

GMSH_EigenvaluesPlugin::GMSH_EigenvaluesPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_EigenvaluesPlugin::getHelp() const
{
  return "Plugin(Eigenvalues) computes the three real "
         "eigenvalues of each tensor in the view `View'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Eigenvalues) creates three new list-based scalar views.";
}

PView *GMSH_EigenvaluesPlugin::execute(PView *v)
{
  int iView = (int)option(0);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  if(data1->hasMultipleMeshes()) {
    Msg::Error("Eigenvalues plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *min = new PView();
  PView *mid = new PView();
  PView *max = new PView();

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);
  createListData(
    data1, {dmin, dmid, dmax},
    [](const PluginElement &e) { return (e.numComp == 9) ? 1 : 0; },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      std::vector<double> val;
      e.getValues(data1, step, val);
      for(int nod = 0; nod < e.numNodes; nod++) {
        double *v = &val[9 * nod], w[3];
        double A[3][3] = {
          {v[0], v[1], v[2]}, {v[3], v[4], v[5]}, {v[6], v[7], v[8]}};
        eigenvalue(A, w);
        res[0].push_back(w[2]);
        res[1].push_back(w[1]);
        res[2].push_back(w[0]);
      }
      return true;
    });

  dmin->setName(data1->getName() + "_MinEigenvalues");
  dmin->setFileName(data1->getName() + "_MinEigenvalues.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvalues");
  dmid->setFileName(data1->getName() + "_MidEigenvalues.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvalues");
  dmax->setFileName(data1->getName() + "_MaxEigenvalues.pos");
  dmax->finalize();

  return max;
}
