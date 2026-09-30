// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Lambda2.h"
#include "Numeric.h"
#include "shapeFunctions.h"

GMSH_Lambda2Plugin::GMSH_Lambda2Plugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Eigenvalue", nullptr, 2., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_Lambda2Plugin::getHelp() const
{
  return "Plugin(Lambda2) computes the eigenvalues "
         "Lambda(1,2,3) of the tensor (S_ik S_kj + "
         "Om_ik Om_kj), where S_ij = 0.5 (ui,j + uj,i) "
         "and Om_ij = 0.5 (ui,j - uj,i) are respectively "
         "the symmetric and antisymmetric parts of the "
         "velocity gradient tensor.\n\n"
         "Vortices are well represented by regions where "
         "Lambda(2) is negative.\n\n"
         "If `View' contains tensor elements, the plugin "
         "directly uses the tensors as the values of the "
         "velocity gradient tensor; if `View' contains "
         "vector elements, the plugin uses them as the "
         "velocities from which to derive the velocity "
         "gradient tensor.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Lambda2) creates one new list-based view.";
}

PView *GMSH_Lambda2Plugin::execute(PView *v)
{
  int ev = (int)option(0);
  int iView = (int)option(1);
  if(ev < 1 || ev > 3) {
    Msg::Error("Eigenvalue should be 1, 2 or 3");
    return v;
  }

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  createListData(
    data1, {data2},
    [](const PluginElement &e) {
      return (e.numComp == 3 || e.numComp == 9) ? 1 : 0;
    },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      std::vector<double> val;
      e.getValues(data1, step, val);
      element *s = e.shape();
      if(e.numComp == 3 && !s) return false;
      for(int nod = 0; nod < e.numNodes; nod++) {
        // the velocity gradient tensor: given, or of the velocities
        double g[3][3];
        if(e.numComp == 9) {
          for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) g[i][j] = val[9 * nod + 3 * i + j];
        }
        else {
          double u, v, w;
          s->getNode(nod, u, v, w);
          for(int i = 0; i < 3; i++)
            s->interpolateGrad(&val[i], u, v, w, g[i], 3);
        }
        // its symmetric and antisymmetric parts S and Om
        double sym[3][3], asym[3][3], a[3][3], lambda[3];
        for(int m = 0; m < 3; m++) {
          for(int n = 0; n < 3; n++) {
            sym[m][n] = 0.5 * (g[m][n] + g[n][m]);
            asym[m][n] = 0.5 * (g[m][n] - g[n][m]);
          }
        }
        for(int m = 0; m < 3; m++) {
          for(int n = 0; n < 3; n++) {
            a[m][n] = 0.;
            for(int l = 0; l < 3; l++)
              a[m][n] += sym[m][l] * sym[l][n] + asym[m][l] * asym[l][n];
          }
        }
        eigenvalue(a, lambda);
        res[0].push_back(lambda[ev - 1]);
      }
      return true;
    });

  data2->setName(data1->getName() + "_Lambda2");
  data2->setFileName(data1->getName() + "_Lambda2.pos");
  data2->finalize();

  return v2;
}
