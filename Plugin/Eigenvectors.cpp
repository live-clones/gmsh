// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Eigenvectors.h"
#include "Numeric.h"
#include "fullMatrix.h"
#include "GmshDefines.h"

StringXNumber EigenvectorsOptions_Number[] = {
  {GMSH_FULLRC, "ScaleByEigenvalues", NULL, 1.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvectorsPlugin()
  {
    return new GMSH_EigenvectorsPlugin();
  }
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
    "Plugin(Eigenvectors) creates three new vector view.";
}

int GMSH_EigenvectorsPlugin::getNbOptions() const
{
  return sizeof(EigenvectorsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvectorsPlugin::getOption(int iopt)
{
  return &EigenvectorsOptions_Number[iopt];
}

static std::vector<double> *incrementList(PViewDataList *data2, int type)
{
  switch(type){
  case TYPE_PNT: data2->NbVP++; return &data2->VP;
  case TYPE_LIN: data2->NbVL++; return &data2->VL;
  case TYPE_TRI: data2->NbVT++; return &data2->VT;
  case TYPE_QUA: data2->NbVQ++; return &data2->VQ;
  case TYPE_TET: data2->NbVS++; return &data2->VS;
  case TYPE_HEX: data2->NbVH++; return &data2->VH;
  case TYPE_PRI: data2->NbVI++; return &data2->VI;
  case TYPE_PYR: data2->NbVY++; return &data2->VY;
  default: return 0;
  }
}

static int nonzero(double v[3])
{
  for(int i = 0; i < 3; i++)
    if(fabs(v[i]) > 1.e-16) return 1;
  return 0;
}

PView *GMSH_EigenvectorsPlugin::execute(PView *v)
{
  int scale = (int)EigenvectorsOptions_Number[0].def;
  int iView = (int)EigenvectorsOptions_Number[1].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
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
  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 9) continue;
      int type = data1->getType(0, ent, ele);
      std::vector<double> *outmin = incrementList(dmin, type);
      std::vector<double> *outmid = incrementList(dmid, type);
      std::vector<double> *outmax = incrementList(dmax, type);
      if(!outmin || !outmid || !outmax) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      double xyz[3][8];
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(0, ent, ele, nod, xyz[0][nod], xyz[1][nod], xyz[2][nod]);
      for(int i = 0; i < 3; i++){
        for(int nod = 0; nod < numNodes; nod++){
          outmin->push_back(xyz[i][nod]);
          outmid->push_back(xyz[i][nod]);
          outmax->push_back(xyz[i][nod]);
        }
      }
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
        for(int nod = 0; nod < numNodes; nod++){
          for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
              data1->getValue(step, ent, ele, nod, 3 * i + j, mat(i, j));
          if(mat.eig(dr, di, vl, vr, true)){
            if(!scale) dr(0) = dr(1) = dr(2) = 1.;
            for(int i = 0; i < 3; i++){
              double res;
              res = dr(0) * vr(i, 0); outmin->push_back(res);
              res = dr(1) * vr(i, 1); outmid->push_back(res);
              res = dr(2) * vr(i, 2); outmax->push_back(res);
            }
            if(di(0) || di(1) || di(2)) nbcomplex++;
          }
          else{
            Msg::Error("Could not compute eigenvalues/vectors");
          }
        }
      }
    }
  }

  if(nbcomplex)
    Msg::Error("%d tensors have complex eigenvalues", nbcomplex);
  
  for(int i = 0; i < data1->getNumTimeSteps(); i++){
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

  return 0;
}
