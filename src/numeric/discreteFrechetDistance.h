// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_FRECHET_DISTANCE
#define DISCRETE_FRECHET_DISTANCE

#include <vector>
#include "SPoint3.h"

double discreteFrechetDistance(const std::vector<SPoint3> &P,
                               const std::vector<SPoint3> &Q);

#endif
