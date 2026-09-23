// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Scal2Tens.h"
#include "PViewOptions.h"

GMSH_Scal2TensPlugin::GMSH_Scal2TensPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "NumberOfComponents", nullptr, 9, ""},
                     {GMSH_FULLRC, "View0", nullptr, -1, ""},
                     {GMSH_FULLRC, "View1", nullptr, -1, ""},
                     {GMSH_FULLRC, "View2", nullptr, -1, ""},
                     {GMSH_FULLRC, "View3", nullptr, -1, ""},
                     {GMSH_FULLRC, "View4", nullptr, -1, ""},
                     {GMSH_FULLRC, "View5", nullptr, -1, ""},
                     {GMSH_FULLRC, "View6", nullptr, -1, ""},
                     {GMSH_FULLRC, "View7", nullptr, -1, ""},
                     {GMSH_FULLRC, "View8", nullptr, -1, ""}},
                    {{GMSH_FULLRC, "NameNewView", nullptr, "NewView", ""}})
{
}

std::string GMSH_Scal2TensPlugin::getHelp() const
{
  return "Plugin(Scal2Tens) converts some scalar fields into a tensor field. "
         "The number of components must be given (max. 9): a view has 1, 3 or "
         "9, the components beyond `NumberOfComponents' being 0. "
         "The new view 'NameNewView' contains the new tensor field. If the "
         "number "
         "of a view is -1, the value of the corresponding component is 0.";
}

PView *GMSH_Scal2TensPlugin::execute(PView *v)
{
  // Load options
  int numComp = (int)option(0);
  if((numComp < 1) || (numComp > 9)) {
    Msg::Error(
      "Scal2Tens plugin: NumberOfComponents must be between 1 and 9 (not '%i')",
      numComp);
    return v;
  }
  int iView[9];
  for(int comp = 0; comp < numComp; comp++) iView[comp] = (int)option(comp + 1);

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
  for(int comp = 0; comp < numComp; comp++) {
    // the values of each element are read at its index in every view
    PViewData *d = vComp[comp] ? vComp[comp]->getData() : nullptr;
    if(d && (d->getNumEntities() != dataRef->getNumEntities() ||
             d->getNumElements() != dataRef->getNumElements())) {
      Msg::Error("Scal2Tens plugin: View[%d] and View[%d] have different elements",
                 vRef->getIndex(), vComp[comp]->getIndex());
      return v;
    }
  }

  // Initialize the new view
  PView *vNew = new PView();
  PViewDataList *dataNew = getDataList(vNew);

  // list data holds 1, 3 or 9 components: the others are 0
  int outComp = (numComp == 1) ? 1 : (numComp <= 3) ? 3 : 9;

  // the value of each component at each node, from the component views
  createListData(
    dataRef, {dataNew}, [&](const PluginElement &e) { return outComp; },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      for(int nod = 0; nod < e.numNodes; nod++) {
        for(int comp = 0; comp < outComp; comp++) {
          double val = 0.;
          PViewData *d = nullptr;
          if(comp < numComp && vComp[comp]) d = vComp[comp]->getData();
          if(d && d->hasTimeStep(step) && !d->skipElement(step, e.ent, e.ele))
            d->getValue(step, e.ent, e.ele, nod, 0, val);
          res[0].push_back(val);
        }
      }
      return true;
    });

  std::string nameNewView = optionStr(0);
  dataNew->setName(nameNewView);
  dataNew->setFileName(nameNewView + ".pos");
  dataNew->finalize();

  return vNew;
}
