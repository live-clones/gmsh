// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Eigenvectors.h"
#include "Numeric.h"
#include "fullMatrix.h"
#include "GmshDefines.h"

GMSH_EigenvectorsPlugin::GMSH_EigenvectorsPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "ScaleByEigenvalues", nullptr, 1., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_EigenvectorsPlugin::getHelp() const
{
  return "Plugin(Eigenvectors) computes the three (right) "
         "eigenvectors of each tensor in the view `View' "
         "and sorts them according to the value of the "
         "associated eigenvalues.\n\n"
         "If `ScaleByEigenvalues' is set, each eigenvector is "
         "scaled by its associated eigenvalue. The plugin "
         "gives an error if the eigenvectors are complex.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Eigenvectors) creates three new list-based vector view.";
}

PView *GMSH_EigenvectorsPlugin::execute(PView *v)
{
  int scale = (int)option(0);
  int iView = (int)option(1);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  if(data1->hasMultipleMeshes()) {
    Msg::Error("Eigenvectors plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *min = new PView();
  PView *mid = new PView();
  PView *max = new PView();

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);
  int nbcomplex = 0;
  fullMatrix<double> mat(3, 3), vl(3, 3), vr(3, 3);
  fullVector<double> dr(3), di(3);
  createListData(
    data1, {dmin, dmid, dmax},
    [](const PluginElement &e) { return (e.numComp == 9) ? 3 : 0; },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      std::vector<double> val;
      e.getValues(data1, step, val);
      for(int nod = 0; nod < e.numNodes; nod++) {
        for(int i = 0; i < 3; i++)
          for(int j = 0; j < 3; j++) mat(i, j) = val[9 * nod + 3 * i + j];
        if(!mat.eig(dr, di, vl, vr, true)) {
          Msg::Error("Could not compute eigenvalues/vectors");
          return false;
        }
        if(!scale) dr(0) = dr(1) = dr(2) = 1.;
        for(int i = 0; i < 3; i++) {
          res[0].push_back(dr(0) * vr(i, 0));
          res[1].push_back(dr(1) * vr(i, 1));
          res[2].push_back(dr(2) * vr(i, 2));
        }
        if(di(0) || di(1) || di(2)) nbcomplex++;
      }
      return true;
    });

  if(nbcomplex) Msg::Error("%d tensors have complex eigenvalues", nbcomplex);

  dmin->setName(data1->getName() + "_MinEigenvectors");
  dmin->setFileName(data1->getName() + "_MinEigenvectors.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvectors");
  dmid->setFileName(data1->getName() + "_MidEigenvectors.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvectors");
  dmax->setFileName(data1->getName() + "_MaxEigenvectors.pos");
  dmax->finalize();

  return max;
}
