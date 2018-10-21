// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues
//
// Contributed by Tristan Carrier

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_

#include <queue>
#include "fullMatrix.h"
#include "DivideAndConquer.h"

class GFace;

class smoothing {
  int ITER_MAX;
  int NORM;

public:
  smoothing(int, int);
  void optimize_face(GFace *);
  void optimize_model();
};

#endif
