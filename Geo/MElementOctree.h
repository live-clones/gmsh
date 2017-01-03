// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MELEMENT_OCTREE_
#define _MELEMENT_OCTREE_

#include <vector>

class Octree;
class GModel;
class MElement;

class MElementOctree{
 private:
  Octree *_octree;
  GModel *_gm;
  std::vector<MElement*> _elems;
 public:
  MElementOctree(GModel *);
  MElementOctree(const std::vector<MElement*> &);
  ~MElementOctree();
  MElement *find(double x, double y, double z, int dim = -1, bool strict = false) const;
  Octree *getInternalOctree(){ return _octree; }
  std::vector<MElement *> findAll(double x, double y, double z, int dim, bool strict = false);
};
#endif
