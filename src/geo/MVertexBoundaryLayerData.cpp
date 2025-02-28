// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MVertexBoundaryLayerData.h"

std::vector<MVertex *> *MVertexBoundaryLayerData::getChildren(int i)
{
  if(i < (int)this->children.size() && i >= 0) { return &(children[i]); }
  else {
    return nullptr;
  }
}

int MVertexBoundaryLayerData::getNumChildren(int i)
{
  if(i < (int)this->children.size() && i >= 0) {
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

void MVertexBoundaryLayerData::addChildrenFamily(
  const std::vector<MVertex *> &family)
{
  this->children.push_back(family);
}
