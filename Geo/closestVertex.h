// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLOSEST_VERTEX_H
#define CLOSEST_VERTEX_H

#include "GmshConfig.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

#include "SPoint3.h"

#include <vector>
#include <cstring>

class GEntity;
class MVertex;

// object for locating closest mesh (principal) vertex on the entity,
// in/excluding the closure

class closestVertexFinder {
#if defined(HAVE_ANN)
  ANNkd_tree *kdtree;
  ANNpointArray vCoord;
  ANNidxArray index;
  ANNdistArray dist;
  MVertex **vertex;
#endif

  unsigned int nbVtcs;

public:
  closestVertexFinder(GEntity *ge, bool includeClosure);
  ~closestVertexFinder();

  // find closest vertex for given point
  MVertex *operator()(const SPoint3 &p);
  // find closest vertex for transformation of given point
  MVertex *operator()(const SPoint3 &p, const std::vector<double> &tfo);

  unsigned int getNbVtcs() const { return nbVtcs; }
};

#endif
