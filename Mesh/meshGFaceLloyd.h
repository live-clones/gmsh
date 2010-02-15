// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_

class GFace;

class lloydAlgorithm {
  int ITER_MAX;
  bool infiniteNorm ;
 public :
  lloydAlgorithm (int itermax, bool infnorm = false): ITER_MAX(itermax), infiniteNorm(infnorm) {}
  void operator () (GFace *);
};

#endif
