// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "MVertex.h"
#include "MElement.h"
#include "HierarchicalBasisUtils.h"

void updateElementVerticesWithNextPermutation(std::vector<MVertex *> &vertices,
                                              MElement *element)
{
  // e.g. 2 5 8 -> 2 8 5 -> 5 2 8 -> 5 8 2 -> 8 2 5 -> 8 5 2
  std::next_permutation(vertices.begin(), vertices.end(), MVertexPtrLessThan());
  for(std::size_t i = 0; i < vertices.size(); ++i)
    element->setVertex(i, vertices[i]);
}
