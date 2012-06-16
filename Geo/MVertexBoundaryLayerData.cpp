// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
    return this->children[i].size();
  }
  else {
    return -1;
  }
}

int MVertexBoundaryLayerData::getNumChildrenFamilies()
{
  return this->children.size();
}

void MVertexBoundaryLayerData::addChildrenFamily(std::vector<MVertex*> family)
{
  this->children.push_back(family);
}
