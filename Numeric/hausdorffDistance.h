// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HAUSDORFF_DISTANCE_H
#define HAUSDORFF_DISTANCE_H

#include <vector>
#include "SPoint3.h"

double hausdorffDistance(const std::vector<SPoint3> &P,
                         const std::vector<SPoint3> &Q);

#endif
