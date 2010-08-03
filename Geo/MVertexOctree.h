// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MVERTEX_OCTREE_
#define _MVERTEX_OCTREE_

class Octree;
class GModel;
class MVertex;

class MVertexOctree{
 private:
  Octree *_octree;
 public:
  static double tolerance;
 public:
  MVertexOctree(GModel *, double);
  ~MVertexOctree();
  void insert(MVertex *);
  void finalize();
  MVertex *find(double x, double y, double z);
};

#endif
