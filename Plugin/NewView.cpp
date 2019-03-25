// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Ruth Sabariego  & Francois Henrotte
//

#include "NewView.h"
#include "GModel.h"
#include "MElement.h"

StringXNumber NewViewOptions_Number[] = {
  {GMSH_FULLRC, "NumComp", NULL, 1.},
  {GMSH_FULLRC, "Value", NULL, 0.},
  {GMSH_FULLRC, "ViewTag", NULL, -1.}
};

StringXString NewViewOptions_String[] = {
  {GMSH_FULLRC, "Type", NULL, "NodeData"}
};

extern "C" {
GMSH_Plugin *GMSH_RegisterNewViewPlugin() { return new GMSH_NewViewPlugin(); }
}

std::string GMSH_NewViewPlugin::getHelp() const
{
  return "Plugin(NewView) creates a new model-based view from the "
         "current mesh, with `NumComp' field components, set to value "
         "`Value'.\n\n"
         "If `ViewTag' is positive, force that tag for the created view.";
}

int GMSH_NewViewPlugin::getNbOptions() const
{
  return sizeof(NewViewOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_NewViewPlugin::getOption(int iopt)
{
  return &NewViewOptions_Number[iopt];
}

int GMSH_NewViewPlugin::getNbOptionsStr() const
{
  return sizeof(NewViewOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_NewViewPlugin::getOptionStr(int iopt)
{
  return &NewViewOptions_String[iopt];
}

PView *GMSH_NewViewPlugin::execute(PView *v)
{
  int numComp = (int)NewViewOptions_Number[0].def;
  int value = NewViewOptions_Number[1].def;
  int tag = (int)NewViewOptions_Number[2].def;
  std::string type = NewViewOptions_String[0].def;

  if(GModel::current()->getMeshStatus() < 1) {
    Msg::Error("No mesh available to create the view: please mesh your model!");
    return v;
  }
  if(numComp < 1) {
    Msg::Error("Bad number of components for Plugin(NewView)");
    return v;
  }
  if(type != "NodeData") {
    Msg::Error("Unknown data type for Plugin(NewView)");
    return v;
  }
  std::map<int, std::vector<double> > d;
  std::vector<GEntity *> entities;
  GModel::current()->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *ve = entities[i]->mesh_vertices[j];
      d[ve->getNum()].resize(numComp, value);
    }
  }

  PView *vn = new PView("New view", "NodeData", GModel::current(), d, tag);
  return vn;
}
