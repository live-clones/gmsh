// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _DISCRETE_FRECHET_DISTANCE_
#define _DISCRETE_FRECHET_DISTANCE_

#include <vector>
#include "SPoint3.h"

double discreteFrechetDistance(const std::vector<SPoint3> &P,
                               const std::vector<SPoint3> &Q);

#endif
