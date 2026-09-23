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
  int step0 = data1->getFirstNonEmptyTimeStep();

  int nbcomplex = 0;
  fullMatrix<double> mat(3, 3), vl(3, 3), vr(3, 3);
  fullVector<double> dr(3), di(3);
  for(int ent = 0; ent < data1->getNumEntities(step0); ent++) {
    for(int ele = 0; ele < data1->getNumElements(step0, ent); ele++) {
      if(data1->skipElement(step0, ent, ele)) continue;
      int numComp = data1->getNumComponents(step0, ent, ele);
      if(numComp != 9) continue;
      int type = data1->getType(step0, ent, ele);
      int numNodes = getNumCornerNodes(data1, step0, ent, ele);
      if(!numNodes) continue;
      std::vector<double> *outmin = dmin->incrementList(3, type, numNodes);
      std::vector<double> *outmid = dmid->incrementList(3, type, numNodes);
      std::vector<double> *outmax = dmax->incrementList(3, type, numNodes);
      if(!outmin || !outmid || !outmax) continue;
      double xyz[3][8];
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(step0, ent, ele, nod, xyz[0][nod], xyz[1][nod],
                       xyz[2][nod]);
      for(int i = 0; i < 3; i++) {
        for(int nod = 0; nod < numNodes; nod++) {
          outmin->push_back(xyz[i][nod]);
          outmid->push_back(xyz[i][nod]);
          outmax->push_back(xyz[i][nod]);
        }
      }
      for(int step = step0; step < data1->getNumTimeSteps(); step++) {
        if(!data1->hasTimeStep(step)) continue;
        for(int nod = 0; nod < numNodes; nod++) {
          for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
              data1->getValue(step, ent, ele, nod, 3 * i + j, mat(i, j));
          if(mat.eig(dr, di, vl, vr, true)) {
            if(!scale) dr(0) = dr(1) = dr(2) = 1.;
            for(int i = 0; i < 3; i++) {
              double res;
              res = dr(0) * vr(i, 0);
              outmin->push_back(res);
              res = dr(1) * vr(i, 1);
              outmid->push_back(res);
              res = dr(2) * vr(i, 2);
              outmax->push_back(res);
            }
            if(di(0) || di(1) || di(2)) nbcomplex++;
          }
          else {
            Msg::Error("Could not compute eigenvalues/vectors");
            for(int i = 0; i < 3; i++) {
              outmin->push_back(0.);
              outmid->push_back(0.);
              outmax->push_back(0.);
            }
          }
        }
      }
    }
  }

  if(nbcomplex) Msg::Error("%d tensors have complex eigenvalues", nbcomplex);

  for(int i = step0; i < data1->getNumTimeSteps(); i++) {
    if(!data1->hasTimeStep(i)) continue;
    double time = data1->getTime(i);
    dmin->Time.push_back(time);
    dmid->Time.push_back(time);
    dmax->Time.push_back(time);
  }
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
