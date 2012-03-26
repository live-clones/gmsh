// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Divergence.h"
#include "shapeFunctions.h"
#include "GmshDefines.h"

StringXNumber DivergenceOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDivergencePlugin()
  {
    return new GMSH_DivergencePlugin();
  }
}

std::string GMSH_DivergencePlugin::getHelp() const
{
  return "Plugin(Divergence) computes the divergence of the "
    "field in the view `View'.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(Divergence) creates one new view.";
}

int GMSH_DivergencePlugin::getNbOptions() const
{
  return sizeof(DivergenceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DivergencePlugin::getOption(int iopt)
{
  return &DivergenceOptions_Number[iopt];
}

PView *GMSH_DivergencePlugin::execute(PView *v)
{
  int iView = (int)DivergenceOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  if(data1->hasMultipleMeshes()){
    Msg::Error("Divergence plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  int firstNonEmptyStep =  data1->getFirstNonEmptyTimeStep();

  for(int ent = 0; ent < data1->getNumEntities(firstNonEmptyStep); ent++){
    for(int ele = 0; ele < data1->getNumElements(firstNonEmptyStep, ent); ele++){
      if(data1->skipElement(firstNonEmptyStep, ent, ele)) continue;
      int numComp = data1->getNumComponents(firstNonEmptyStep, ent, ele);
      if(numComp != 3) continue;
      int type = data1->getType(firstNonEmptyStep, ent, ele);
      int numNodes = data1->getNumNodes(firstNonEmptyStep, ent, ele);
      std::vector<double> *out = data2->incrementList(1, type, numNodes);
      if(!out) continue;
      double x[8], y[8], z[8], val[8 * 3];
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(firstNonEmptyStep, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = data1->getDimension(firstNonEmptyStep, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
        if(!data1->hasTimeStep(step)) continue;
        for(int nod = 0; nod < numNodes; nod++)
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
        for(int nod = 0; nod < numNodes; nod++){
          double u, v, w;
          element->getNode(nod, u, v, w);
          double f = element->interpolateDiv(val, u, v, w, 3);
          out->push_back(f);
        }
      }
      delete element;
    }
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    if(!data1->hasTimeStep(i)) continue;
    double time = data1->getTime(i);
    data2->Time.push_back(time);
  }
  data2->setName(data1->getName() + "_Divergence");
  data2->setFileName(data1->getName() + "_Divergence.pos");
  data2->finalize();

  return v2;
}
