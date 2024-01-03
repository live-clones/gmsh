// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "Invisible.h"

StringXNumber InvisibleOptions_Number[] = {
  {GMSH_FULLRC, "DeleteElements", nullptr, 1.},
  {GMSH_FULLRC, "ReverseElements", nullptr, 0.},
  {GMSH_FULLRC, "XMin", nullptr, 0.},
  {GMSH_FULLRC, "YMin", nullptr, 0.},
  {GMSH_FULLRC, "ZMin", nullptr, 0.},
  {GMSH_FULLRC, "XMax", nullptr, 0.},
  {GMSH_FULLRC, "YMax", nullptr, 0.},
  {GMSH_FULLRC, "ZMax", nullptr, 0.}
};

extern "C" {
GMSH_Plugin *GMSH_RegisterInvisiblePlugin()
{
  return new GMSH_InvisiblePlugin();
}
}

std::string GMSH_InvisiblePlugin::getHelp() const
{
  return "Plugin(Invisible) deletes (if `DeleteElements' is set) or "
         "reverses (if `ReverseElements' is set) all the invisible elements in "
         "the current model. If the bounding box defined by `XMin' < x < `XMax, "
         "`YMin' < y < `YMax and `ZMin' < z < `ZMax' is not empty, mark all "
         "elements outside the bounding box as invisible prior to deleting or "
         "inverting the elements.";
}

int GMSH_InvisiblePlugin::getNbOptions() const
{
  return sizeof(InvisibleOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_InvisiblePlugin::getOption(int iopt)
{
  return &InvisibleOptions_Number[iopt];
}

PView *GMSH_InvisiblePlugin::execute(PView *v)
{
  double xmin = InvisibleOptions_Number[2].def;
  double ymin = InvisibleOptions_Number[3].def;
  double zmin = InvisibleOptions_Number[4].def;
  double xmax = InvisibleOptions_Number[5].def;
  double ymax = InvisibleOptions_Number[6].def;
  double zmax = InvisibleOptions_Number[7].def;

  GModel *m = GModel::current();

  if((xmax - xmin) > 0. || (ymax - ymin) > 0. || (zmax - zmin) > 0.) {
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        bool visible = false;
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          MVertex *v = e->getVertex(k);
          if(v->x() >= xmin && v->x() <= xmax &&
             v->y() >= ymin && v->y() <= ymax &&
             v->z() >= zmin && v->z() <= zmax) {
            visible = true;
            break;
          }
        }
        if(!visible) {
          e->setVisibility(0);
        }
      }
    }
  }

  if(InvisibleOptions_Number[0].def)
    m->removeInvisibleElements();
  if(InvisibleOptions_Number[1].def)
    m->reverseInvisibleElements();

  return nullptr;
}
