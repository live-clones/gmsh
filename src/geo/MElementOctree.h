// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
  Octree *_octree[4]; // one per dimension
  GModel *_gm;
  int _maxOrder;
  void _insert(MElement *e);
  std::vector<MElement *> _find(double *P, int dim, double tol,
                                bool onlyFirst) const;
  std::vector<MElement *> _find(double *P, int dim, double tol, bool strict,
                                double maxTol, bool onlyFirst) const;

public:
  MElementOctree(GModel *);
  MElementOctree(const std::vector<MElement *> &);
  ~MElementOctree();
  // Get an element of dimension dim (of highest dimension if dim == -1)
  // containing the point, i.e. in its reference element enlarged by tol
  // (Mesh.ToleranceReferenceElement if negative), and for a curve or a
  // surface in space no farther off it than tol times its size; if none and
  // not strict, retry with the tolerance multiplied by 10 up to 1 (0.1 for an
  // octree built from a list of elements). Among the elements of the same
  // dimension, the closest, and among those as close the first one inserted.
  MElement *find(double x, double y, double z, int dim = -1,
                 bool strict = false, double tol = -1.) const;
  // Same, for all the elements, by increasing dimension and in insertion order.
  std::vector<MElement *> findAll(double x, double y, double z, int dim,
                                  bool strict = false, double tol = -1.) const;
  // The element of dimension dim closest to the point, no farther than the
  // distance: for a curve or a surface in space, which a point read from the
  // picture is off by the depth a pixel spans, the one it projects into
  // nearest to it; nullptr if none.
  MElement *findClosest(double x, double y, double z, int dim,
                        double distance) const;
};
#endif
