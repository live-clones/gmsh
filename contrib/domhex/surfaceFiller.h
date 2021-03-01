// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#ifndef SURFACEFILLER_H
#define SURFACEFILLER_H

#include <vector>
#include <set>
#include "STensor3.h"

class GFace;
class MVertex;

void packingOfParallelogramsSmoothness(GFace *gf,
                                       std::vector<MVertex *> &packed,
                                       std::vector<SMetric3> &metrics);
void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                             std::vector<SMetric3> &metrics);
void packingOfParallelogramsConstrained(
  GFace *gf, const std::set<MVertex *> &constr_vertices,
  std::vector<MVertex *> &packed, std::vector<SMetric3> &metrics);

#endif
