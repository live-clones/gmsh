// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Scal2Tens.h"
#include "PViewOptions.h"
#include "shapeFunctions.h"

StringXNumber Scal2TensOptions_Number[] = {
  {GMSH_FULLRC, "NumberOfComponents", nullptr, 9},
  {GMSH_FULLRC, "View0", nullptr, -1},
  {GMSH_FULLRC, "View1", nullptr, -1},
  {GMSH_FULLRC, "View2", nullptr, -1},
  {GMSH_FULLRC, "View3", nullptr, -1},
  {GMSH_FULLRC, "View4", nullptr, -1},
  {GMSH_FULLRC, "View5", nullptr, -1},
  {GMSH_FULLRC, "View6", nullptr, -1},
  {GMSH_FULLRC, "View7", nullptr, -1},
  {GMSH_FULLRC, "View8", nullptr, -1}};

StringXString Scal2TensOptions_String[] = {
  {GMSH_FULLRC, "NameNewView", nullptr, "NewView"}};

extern "C" {
GMSH_Plugin *GMSH_RegisterScal2TensPlugin()
{
  return new GMSH_Scal2TensPlugin();
}
}

std::string GMSH_Scal2TensPlugin::getHelp() const
{
  return "Plugin(Scal2Tens) converts some scalar fields into a tensor field. "
         "The number of components must be given (max. 9). "
         "The new view 'NameNewView' contains the new tensor field. If the "
         "number "
         "of a view is -1, the value of the corresponding component is 0.";
}

int GMSH_Scal2TensPlugin::getNbOptions() const
{
  return sizeof(Scal2TensOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Scal2TensPlugin::getOption(int iopt)
{
  return &Scal2TensOptions_Number[iopt];
}

int GMSH_Scal2TensPlugin::getNbOptionsStr() const
{
  return sizeof(Scal2TensOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_Scal2TensPlugin::getOptionStr(int iopt)
{
  return &Scal2TensOptions_String[iopt];
}

PView *GMSH_Scal2TensPlugin::execute(PView *v)
{
  // Load options
  int numComp = (int)Scal2TensOptions_Number[0].def;
  if((numComp < 1) || (numComp > 9)) {
    Msg::Error(
      "Scal2Tens plugin: NumberOfComponents must be between 1 and 9 (not '%i')",
      numComp);
    return v;
  }
  int iView[9];
  for(int comp = 0; comp < numComp; comp++)
    iView[comp] = (int)Scal2TensOptions_Number[comp + 1].def;

  // Load data
  PView *vRef = nullptr, *vComp[9];
  for(int comp = 0; comp < numComp; comp++) {
    if(iView[comp] < 0)
      vComp[comp] = nullptr;
    else {
      vComp[comp] = getView(iView[comp], v);
      if(!vComp[comp]) {
        Msg::Error("Scal2Tens plugin could not find View '%i'", iView[comp]);
        return v;
      }
      if(!vRef) vRef = vComp[comp];
    }
  }
  if(!vRef) {
    Msg::Error("Scal2Tens plugin could not find any view.");
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
        numComp, type, numNodes); // Pointer in data of the new view
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
          for(int comp = 0; comp < numComp; comp++) {
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

  std::string nameNewView = Scal2TensOptions_String[0].def;
  dataNew->setName(nameNewView);
  dataNew->setFileName(nameNewView + ".pos");
  dataNew->finalize();

  return vNew;
}
