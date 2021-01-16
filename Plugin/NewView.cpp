// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
  {GMSH_FULLRC, "NumComp", nullptr, 1.},
  {GMSH_FULLRC, "Value", nullptr, 0.},
  {GMSH_FULLRC, "ViewTag", nullptr, -1.},
  {GMSH_FULLRC, "PhysicalGroup", nullptr, -1.}};

StringXString NewViewOptions_String[] = {
  {GMSH_FULLRC, "Type", nullptr, "NodeData"}};

extern "C" {
GMSH_Plugin *GMSH_RegisterNewViewPlugin() { return new GMSH_NewViewPlugin(); }
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
  double value = NewViewOptions_Number[1].def;
  int tag = (int)NewViewOptions_Number[2].def;
  int phys = (int)NewViewOptions_Number[3].def;
  std::string type = NewViewOptions_String[0].def;

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

  PView *vn = new PView("New view", type, GModel::current(), d, tag);
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
