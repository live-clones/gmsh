// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HIERARCHICAL_BASIS_UTILS_H
#define HIERARCHICAL_BASIS_UTILS_H

#include <vector>

class MVertex;
class MElement;

// set the vertices of the element to the next permutation of vertices, in the
// increasing order of their tags
void updateElementVerticesWithNextPermutation(std::vector<MVertex *> &vertices,
                                              MElement *element);

#endif
