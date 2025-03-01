// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MVERTEXBOUNDARYLAYERDATA_H
#define MVERTEXBOUNDARYLAYERDATA_H

#include <vector>

class MNode;

// A simple data structure to keep track of the "children" of vertices
// in a boundary layer mesh. It should be filled for each MNode on
// the boundary of the geometry with the vertices along the normal
// direction, in order.

class MVertexBoundaryLayerData {
private:
  std::vector<std::vector<MNode *> > children;

public:
  MVertexBoundaryLayerData(){};
  ~MVertexBoundaryLayerData(){};

  std::vector<MNode *> *getChildren(int i);
  int getNumChildren(int i);

  int getNumChildrenFamilies();
  void addChildrenFamily(const std::vector<MNode *> &family);
};

#endif
