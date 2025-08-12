// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "MVertex.h"
#include "MElement.h"

void validateWantedOrientations(const std::vector<int>& wantedOrientations,
                                int maxOrientation,
                                const std::string& fsName,
                                const int familyType);

// Update Element Vertices With Next Permutation

void updateElementVerticesWithNextPermutation(std::vector<MVertex*>& vertices,
                                              MElement* element);

#endif // UTILS_H
