// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MELEMENT_OCTREE_
#define _MELEMENT_OCTREE_

#include <vector>

class Octree;
class GModel;
class MElement;

class MElementOctree{
 private:
  Octree *_octree;
 public:
  MElementOctree(GModel *);
  MElementOctree(std::vector<MElement*> &);
  ~MElementOctree();
  MElement *find(double x, double y, double z, int dim = -1);
  Octree *getInternalOctree(){ return _octree; }
};

#endif
