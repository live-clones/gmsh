// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Ruth Sabariego  & Francois Henrotte
//

#include "NewView.h"
#include "GModel.h"
#include "MElement.h"

GMSH_NewViewPlugin::GMSH_NewViewPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "NumComp", nullptr, 1., ""},
                     {GMSH_FULLRC, "Value", nullptr, 0., ""},
                     {GMSH_FULLRC, "ViewTag", nullptr, -1., ""},
                     {GMSH_FULLRC, "PhysicalGroup", nullptr, -1., ""}},
                    {{GMSH_FULLRC, "Type", nullptr, "NodeData", ""}})
{
}

std::string GMSH_NewViewPlugin::getHelp() const
{
  return "Plugin(NewView) creates a new model-based view from the "
         "current mesh, with `NumComp' field components, set to value "
         "`Value'.\n\n"
         "If `ViewTag' is positive, force that tag for the created view. "
         "The view type is determined by `Type' (NodeData or ElementData). "
         "In the case of an ElementData type, the view can be restricted "
         "to a specific physical group with a positive `PhysicalGroup'.";
}

PView *GMSH_NewViewPlugin::execute(PView *v)
{
  int numComp = (int)option(0);
  double value = option(1);
  int tag = (int)option(2);
  int phys = (int)option(3);
  std::string type = optionStr(0);

  if(GModel::current()->getMeshStatus() < 0) {
    Msg::Error("No mesh available to create the view: please mesh your model!");
    return v;
  }
  if(numComp < 1) {
    Msg::Error("Bad number of components for Plugin(NewView)");
    return v;
  }
  if(!(type == "NodeData" || type == "ElementData")) {
    Msg::Error("Unknown data type for Plugin(NewView)");
    return v;
  }

  std::map<int, std::vector<double> > d;
  if(type == "NodeData") nodeData(numComp, value, d);
  if(type == "ElementData") elementData(numComp, value, d, phys);

  PView *vn =
    new PView("New view", type, GModel::current(), d, 0., numComp, tag);
  return vn;
}

void GMSH_NewViewPlugin::nodeData(int numComp, double value,
                                  std::map<int, std::vector<double> > &d)
{
  std::vector<GEntity *> entities;
  GModel::current()->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *ve = entities[i]->mesh_vertices[j];
      d[ve->getNum()].resize(numComp, value);
    }
  }
}

void GMSH_NewViewPlugin::elementData(int numComp, double value,
                                     std::map<int, std::vector<double> > &d,
                                     int phys)
{
  std::vector<GEntity *> entities;
  if(phys == -1) { GModel::current()->getEntities(entities, -1); }
  else {
    std::map<int, std::vector<GEntity *> > groups;
    GModel::current()->getPhysicalGroups(-1, groups);
    entities = groups[phys];
  }

  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      MElement *e = entities[i]->getMeshElement(j);
      d[e->getNum()].resize(numComp, value);
    }
  }
}
