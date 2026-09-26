// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Scal2Vec.h"
#include "PViewOptions.h"

GMSH_Scal2VecPlugin::GMSH_Scal2VecPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "ViewX", nullptr, -1, ""},
                     {GMSH_FULLRC, "ViewY", nullptr, -1, ""},
                     {GMSH_FULLRC, "ViewZ", nullptr, -1, ""}},
                    {{GMSH_FULLRC, "NameNewView", nullptr, "NewView", ""}})
{
}

std::string GMSH_Scal2VecPlugin::getHelp() const
{
  return "Plugin(Scal2Vec) converts the scalar fields into a vectorial field. "
         "The new view 'NameNewView' contains it. "
         "If the number of a view is -1, the value of the corresponding "
         "component of the vector field is 0.";
}

PView *GMSH_Scal2VecPlugin::execute(PView *v)
{
  // Load options
  int iView[3];
  for(int comp = 0; comp < 3; comp++) iView[comp] = (int)option(comp);

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
  for(int comp = 0; comp < 3; comp++) {
    // the values of each element are read at its index in every view
    PViewData *d = vComp[comp] ? vComp[comp]->getData() : nullptr;
    if(d && (d->getNumEntities() != dataRef->getNumEntities() ||
             d->getNumElements() != dataRef->getNumElements())) {
      Msg::Error("Scal2Vec plugin: View[%d] and View[%d] have different elements",
                 vRef->getIndex(), vComp[comp]->getIndex());
      return v;
    }
  }

  // Initialize the new view
  PView *vNew = new PView();
  PViewDataList *dataNew = getDataList(vNew);

  // the value of each component at each node, from the component views
  createListData(
    dataRef, {dataNew}, [&](const PluginElement &e) { return 3; },
    [&](const PluginElement &e, int step,
        std::vector<std::vector<double> > &res) {
      for(int nod = 0; nod < e.numNodes; nod++) {
        for(int comp = 0; comp < 3; comp++) {
          double val = 0.;
          PViewData *d = nullptr;
          if(comp < 3 && vComp[comp]) d = vComp[comp]->getData();
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
