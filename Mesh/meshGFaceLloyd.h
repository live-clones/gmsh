// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_
#include "fullMatrix.h"
#include "DivideAndConquer.h"
#include <queue>
#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"
#include "MElementOctree.h"

class GFace;

class smoothing{
  int ITER_MAX;
  int NORM;
 public :
  smoothing(int,int);
  void optimize_face(GFace*);
  void optimize_model();
};

#endif