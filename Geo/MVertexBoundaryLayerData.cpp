// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "MVertexBoundaryLayerData.h"

std::vector<MVertex*>* MVertexBoundaryLayerData::getChildren(int i)
{
  if (i < (int)this->children.size() && i >= 0) {
    return &(children[i]);
  }
  else {
    return 0;
  }
}

int MVertexBoundaryLayerData::getNumChildren(int i)
{
  if (i < (int)this->children.size() && i >= 0) {
    return (int)this->children[i].size();
  }
  else {
    return -1;
  }
}

int MVertexBoundaryLayerData::getNumChildrenFamilies()
{
  return (int)this->children.size();
}

void MVertexBoundaryLayerData::addChildrenFamily(std::vector<MVertex*> family)
{
  this->children.push_back(family);
}
