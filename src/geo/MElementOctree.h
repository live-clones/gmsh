// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MELEMENT_OCTREE
#define MELEMENT_OCTREE

#include <vector>

class Octree;
class GModel;
class MElement;

class MElementOctree {
private:
  Octree *_octree;
  GModel *_gm;
  std::vector<MElement *> _elems;

public:
  MElementOctree(GModel *);
  MElementOctree(const std::vector<MElement *> &);
  ~MElementOctree();
  MElement *find(double x, double y, double z, int dim = -1,
                 bool strict = false) const;
  std::vector<MElement *> findAll(double x, double y, double z, int dim,
                                  bool strict = false) const;
};
#endif
