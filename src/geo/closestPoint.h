// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLOSEST_POINT_H
#define CLOSEST_POINT_H

#include "SPoint3KDTree.h"

class GEntity;
class closestPointFinder {
  SPoint3Search _search;
  double _tolerance;

public:
  closestPointFinder(GEntity *, double);
  SPoint3 operator()(const SPoint3 &p);
  inline double tol() const { return _tolerance; }
};

#endif
