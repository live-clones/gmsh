// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Scal2Vec.h"
#include "PViewOptions.h"
#include "shapeFunctions.h"

StringXNumber Scal2VecOptions_Number[] = {{GMSH_FULLRC, "ViewX", nullptr, -1},
                                          {GMSH_FULLRC, "ViewY", nullptr, -1},
                                          {GMSH_FULLRC, "ViewZ", nullptr, -1}};

StringXString Scal2VecOptions_String[] = {
  {GMSH_FULLRC, "NameNewView", nullptr, "NewView"}};

extern "C" {
GMSH_Plugin *GMSH_RegisterScal2VecPlugin() { return new GMSH_Scal2VecPlugin(); }
}

std::string GMSH_Scal2VecPlugin::getHelp() const
{
  return "Plugin(Scal2Vec) converts the scalar fields into a vectorial field. "
         "The new view 'NameNewView' contains it. "
         "If the number of a view is -1, the value of the corresponding "
         "component of the vector field is 0.";
}

int GMSH_Scal2VecPlugin::getNbOptions() const
{
  return sizeof(Scal2VecOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Scal2VecPlugin::getOption(int iopt)
{
  return &Scal2VecOptions_Number[iopt];
}

int GMSH_Scal2VecPlugin::getNbOptionsStr() const
{
  return sizeof(Scal2VecOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_Scal2VecPlugin::getOptionStr(int iopt)
{
  return &Scal2VecOptions_String[iopt];
}

PView *GMSH_Scal2VecPlugin::execute(PView *v)
{
  // Load options
  int iView[3];
  for(int comp = 0; comp < 3; comp++)
    iView[comp] = (int)Scal2VecOptions_Number[comp].def;

  // Load data
  PView *vRef = nullptr, *vComp[3];
  for(int comp = 0; comp < 3; comp++) {
    if(iView[comp] < 0)
      vComp[comp] = nullptr;
    else {
      vComp[comp] = getView(iView[comp], v);
      if(!vComp[comp]) {
        Msg::Error("Scal2Vec plugin could not find View '%i'", iView[comp]);
        return v;
      }
      if(!vRef) vRef = vComp[comp];
    }
  }
  if(!vRef) {
    Msg::Error("Scal2Vec plugin could not find any view.");
    return v;
  }
  PViewData *dataRef = vRef->getData();

  // Initialize the new view
  PView *vNew = new PView();
  PViewDataList *dataNew = getDataList(vNew);

  int step0 = dataRef->getFirstNonEmptyTimeStep();
  for(int ent = 0; ent < dataRef->getNumEntities(step0); ent++) {
    for(int ele = 0; ele < dataRef->getNumElements(step0, ent); ele++) {
      if(dataRef->skipElement(step0, ent, ele)) continue;
      int type = dataRef->getType(step0, ent, ele);
      int numNodes = dataRef->getNumNodes(step0, ent, ele);
      std::vector<double> *out = dataNew->incrementList(
        3, type, numNodes); // Pointer in data of the new view
      if(!out) continue;
      double x[8], y[8], z[8];
      for(int nod = 0; nod < numNodes; nod++)
        dataRef->getNode(step0, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = dataRef->getDimension(step0, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++)
        out->push_back(x[nod]); // Save coordinates (x,y,z)
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = step0; step < dataRef->getNumTimeSteps(); step++) {
        if(!dataRef->hasTimeStep(step)) continue;
        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < 3; comp++) {
            double val = 0.;
            if(vComp[comp])
              vComp[comp]->getData()->getValue(step, ent, ele, nod, 0, val);
            out->push_back(val); // Save value
          }
        }
      }
      delete element;
    }
  }

  for(int step = step0; step < dataRef->getNumTimeSteps(); step++) {
    if(!dataRef->hasTimeStep(step)) continue;
    dataNew->Time.push_back(dataRef->getTime(step));
  }

  std::string nameNewView = Scal2VecOptions_String[0].def;
  dataNew->setName(nameNewView);
  dataNew->setFileName(nameNewView + ".pos");
  dataNew->finalize();

  return vNew;
}
