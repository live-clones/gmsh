// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLOSEST_VERTEX_H
#define CLOSEST_VERTEX_H

#include <vector>
#include "SPoint3KDTree.h"

class GEntity;
class MVertex;

// object for locating closest mesh (principal) vertex on the entity,
// in/excluding the closure

class closestVertexFinder {
  SPoint3Search _search;
  std::vector<MVertex *> _vertices;

public:
  closestVertexFinder(GEntity *ge, bool includeClosure);

  // find closest vertex for given point
  MVertex *operator()(const SPoint3 &p);
  // find closest vertex for transformation of given point
  MVertex *operator()(const SPoint3 &p, const std::vector<double> &tfo);

  unsigned int getNbVtcs() const { return _vertices.size(); }
};

#endif
