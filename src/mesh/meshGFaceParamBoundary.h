// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_PARAM_BOUNDARY_H
#define MESH_GFACE_PARAM_BOUNDARY_H

#include <vector>
#include "SPoint2.h"

class GFace;

// Sample the boundary curves of a face in its parametric space, as a flat list
// of segment endpoints (bnd[2i], bnd[2i+1]). Seam curves are sampled on both
// sides.
void trueBoundary(GFace *gf, std::vector<SPoint2> &bnd, int debug);

// Test whether p lies inside the parametric domain bounded by bnd, by counting
// the crossings of the segment from p to a point out known to be outside. N
// returns that number of crossings.
bool pointInsideParametricDomain(std::vector<SPoint2> &bnd, SPoint2 &p,
                                 SPoint2 &out, int &N);

#endif
