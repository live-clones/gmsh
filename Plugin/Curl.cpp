// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Curl.h"
#include "shapeFunctions.h"
#include "GmshDefines.h"

StringXNumber CurlOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCurlPlugin()
  {
    return new GMSH_CurlPlugin();
  }
}

std::string GMSH_CurlPlugin::getHelp() const
{
  return "Plugin(Curl) computes the curl of the field "
    "in the view `View'.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(Curl) creates one new view.";
}

int GMSH_CurlPlugin::getNbOptions() const
{
  return sizeof(CurlOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CurlPlugin::getOption(int iopt)
{
  return &CurlOptions_Number[iopt];
}

PView *GMSH_CurlPlugin::execute(PView *v)
{
  int iView = (int)CurlOptions_Number[0].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  if(data1->hasMultipleMeshes()){
    Msg::Error("Curl plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 3) continue;
      int type = data1->getType(0, ent, ele);
      std::vector<double> *out = data2->incrementList(3, type);
      if(!out) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      double x[8], y[8], z[8], val[8 * 3];
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = data1->getDimension(0, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
        for(int nod = 0; nod < numNodes; nod++)
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
        for(int nod = 0; nod < numNodes; nod++){
          double u, v, w, f[3];
          element->getNode(nod, u, v, w);
          element->interpolateCurl(val, u, v, w, f, 3);
          out->push_back(f[0]);
          out->push_back(f[1]);
          out->push_back(f[2]);
        }
      }
      delete element;
    }
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    data2->Time.push_back(time);
  }
  data2->setName(data1->getName() + "_Curl");
  data2->setFileName(data1->getName() + "_Curl.pos");
  data2->finalize();
  
  return v2;
}
