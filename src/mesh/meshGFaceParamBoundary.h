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

// Same test, for the case where many points are tested against the same
// boundary and the same outside point. Precomputes the half of each crossing
// test that only depends on the segment and on out, and a bounding box per
// segment used to reject segments that cannot cross - which does not change
// the crossing count, only how fast it is obtained.
class ParametricDomainChecker {
public:
  ParametricDomainChecker(std::vector<SPoint2> &bnd, const SPoint2 &out);
  bool inside(const SPoint2 &p, int &N) const;

private:
  std::vector<SPoint2> &_bnd;
  SPoint2 _out;
  std::vector<double> _orientOut;
  std::vector<double> _xmin, _xmax, _ymin, _ymax;
};

#endif
