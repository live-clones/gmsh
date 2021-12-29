// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "groupOfElements.h"
#include "GModel.h"
#include "GEntity.h"

groupOfElements::groupOfElements(GFace *gf)
{
  elementFilterTrivial filter;
  addElementary(gf, filter);
}

groupOfElements::groupOfElements(GRegion *gr)
{
  elementFilterTrivial filter;
  addElementary(gr, filter);
}

groupOfElements::groupOfElements(std::vector<MElement *> &elems)
{
  elementFilterTrivial filter;
  for(auto it = elems.begin(); it != elems.end();
      it++) {
    MElement *e = *it;
    if(filter(e)) {
      insert(e);
    }
  }
}

void groupOfElements::addElementary(GEntity *ge, const elementFilter &filter)
{
  for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
    MElement *e = ge->getMeshElement(j);
    if(filter(e)) {
      insert(e);
    }
  }
}

void groupOfElements::addPhysical(int dim, int physical,
                                  const elementFilter &filter)
{
  std::map<int, std::vector<GEntity *> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  std::vector<GEntity *> &ent = groups[dim][physical];
  for(std::size_t i = 0; i < ent.size(); i++) {
    addElementary(ent[i], filter);
  }
}
