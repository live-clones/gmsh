// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Eigenvalues.h"
#include "Numeric.h"
#include "GmshDefines.h"

StringXNumber EigenvaluesOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvaluesPlugin()
  {
    return new GMSH_EigenvaluesPlugin();
  }
}

std::string GMSH_EigenvaluesPlugin::getHelp() const
{
  return "Plugin(Eigenvalues) computes the three real "
    "eigenvalues of each tensor in the view `View'.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(Eigenvalues) creates three new scalar views.";
}

int GMSH_EigenvaluesPlugin::getNbOptions() const
{
  return sizeof(EigenvaluesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvaluesPlugin::getOption(int iopt)
{
  return &EigenvaluesOptions_Number[iopt];
}

PView *GMSH_EigenvaluesPlugin::execute(PView *v)
{
  int iView = (int)EigenvaluesOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Eigenvalues plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *min = new PView();
  PView *mid = new PView();
  PView *max = new PView();

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 9) continue;
      int type = data1->getType(0, ent, ele);
      std::vector<double> *outmin = dmin->incrementList(1, type);
      std::vector<double> *outmid = dmid->incrementList(1, type);
      std::vector<double> *outmax = dmax->incrementList(1, type);
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
          double val[9], w[3];
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, val[comp]);
          double A[3][3] = {{val[0], val[1], val[2]},
                            {val[3], val[4], val[5]},
                            {val[6], val[7], val[8]}};
          eigenvalue(A, w);
          outmin->push_back(w[2]);
          outmid->push_back(w[1]);
          outmax->push_back(w[0]);
        }
      }
    }
  }
  
  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    dmin->Time.push_back(time);
    dmid->Time.push_back(time);
    dmax->Time.push_back(time);
  }
  dmin->setName(data1->getName() + "_MinEigenvalues");
  dmin->setFileName(data1->getName() + "_MinEigenvalues.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvalues");
  dmid->setFileName(data1->getName() + "_MidEigenvalues.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvalues");
  dmax->setFileName(data1->getName() + "_MaxEigenvalues.pos");
  dmax->finalize();

  return 0;
}
