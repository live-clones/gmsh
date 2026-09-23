// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "Invisible.h"
#include "Context.h"

GMSH_InvisiblePlugin::GMSH_InvisiblePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "DeleteElements", nullptr, 1., ""},
                     {GMSH_FULLRC, "ReverseElements", nullptr, 0., ""},
                     {GMSH_FULLRC, "XMin", nullptr, 0., ""},
                     {GMSH_FULLRC, "YMin", nullptr, 0., ""},
                     {GMSH_FULLRC, "ZMin", nullptr, 0., ""},
                     {GMSH_FULLRC, "XMax", nullptr, 0., ""},
                     {GMSH_FULLRC, "YMax", nullptr, 0., ""},
                     {GMSH_FULLRC, "ZMax", nullptr, 0., ""},
                     {GMSH_FULLRC, "Inside", nullptr, 0., ""}})
{
}

std::string GMSH_InvisiblePlugin::getHelp() const
{
  return "Plugin(Invisible) deletes (if `DeleteElements' is set) or "
         "reverses (if `ReverseElements' is set) all the invisible elements in "
         "the current model. If the bounding box defined by `XMin' < x < `XMax, "
         "`YMin' < y < `YMax and `ZMin' < z < `ZMax' is not empty, mark all "
         "elements outside or inside (if `Inside' is set) the bounding box "
         "as invisible prior to deleting or inverting the elements.";
}

PView *GMSH_InvisiblePlugin::execute(PView *v)
{
  double xmin = option(2);
  double ymin = option(3);
  double zmin = option(4);
  double xmax = option(5);
  double ymax = option(6);
  double zmax = option(7);
  int inside = (int)option(8);

  GModel *m = GModel::current();

  if((xmax - xmin) > 0. || (ymax - ymin) > 0. || (zmax - zmin) > 0.) {
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        bool visible = inside ? true : false;
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          MVertex *v = e->getVertex(k);
          if(v->x() >= xmin && v->x() <= xmax &&
             v->y() >= ymin && v->y() <= ymax &&
             v->z() >= zmin && v->z() <= zmax) {
            visible = inside ? false : true;
            break;
          }
        }
        if(!visible) {
          e->setVisibility(0);
        }
      }
    }
  }

  if(option(0)) m->removeInvisibleElements();
  if(option(1)) m->reverseInvisibleElements();

  // what is drawn depends on the visibility of the elements too
  CTX::instance()->meshChanged();
  return nullptr;
}
