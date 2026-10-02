// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SPOINT3_KDTREE_H
#define SPOINT3_KDTREE_H

#include "SPoint3.h"
#include "nanoflann.hpp"

struct SPoint3Cloud {
  std::vector<SPoint3> pts;
};

template <typename Derived> struct SPoint3CloudAdaptor {
  const Derived &obj;
  SPoint3CloudAdaptor(const Derived &obj_) : obj(obj_) {}
  inline const Derived &derived() const { return obj; }
  inline size_t kdtree_get_point_count() const { return derived().pts.size(); }
  inline double kdtree_distance(const double *p1, const size_t idx_p2,
                                size_t /*size*/) const
  {
    const double d0 = p1[0] - derived().pts[idx_p2].x();
    const double d1 = p1[1] - derived().pts[idx_p2].y();
    const double d2 = p1[2] - derived().pts[idx_p2].z();
    return d0 * d0 + d1 * d1 + d2 * d2;
  }
  inline double kdtree_get_pt(const size_t idx, int dim) const
  {
    if(dim == 0)
      return derived().pts[idx].x();
    else if(dim == 1)
      return derived().pts[idx].y();
    else
      return derived().pts[idx].z();
  }
  template <class BBOX> bool kdtree_get_bbox(BBOX & /*bb*/) const
  {
    return false;
  }
};

typedef nanoflann::KDTreeSingleIndexAdaptor
  <nanoflann::L2_Simple_Adaptor<double, SPoint3CloudAdaptor<SPoint3Cloud> >,
   SPoint3CloudAdaptor<SPoint3Cloud>, 3> SPoint3KDTree;

// exact nearest neighbor search in a set of points: fill points(), call
// build(), then query (concurrent queries are safe)
class SPoint3Search {
private:
  SPoint3Cloud _pc;
  SPoint3CloudAdaptor<SPoint3Cloud> _adaptor;
  SPoint3KDTree *_tree;

public:
  SPoint3Search() : _adaptor(_pc), _tree(nullptr) {}
  SPoint3Search(const SPoint3Search &) = delete;
  SPoint3Search &operator=(const SPoint3Search &) = delete;
  ~SPoint3Search() { delete _tree; }
  std::vector<SPoint3> &points() { return _pc.pts; }
  const SPoint3 &point(std::size_t i) const { return _pc.pts[i]; }
  std::size_t size() const { return _pc.pts.size(); }
  void build()
  {
    delete _tree;
    _tree = new SPoint3KDTree(3, _adaptor,
                              nanoflann::KDTreeSingleIndexAdaptorParams(10));
    _tree->buildIndex();
  }
  void clear()
  {
    delete _tree;
    _tree = nullptr;
    _pc.pts.clear();
  }
  // the (at most) k closest points by increasing distance, with their squared
  // distances; returns how many were found
  std::size_t nearest(const SPoint3 &p, std::size_t k, std::size_t *idx,
                      double *dist2) const
  {
    if(!_tree) return 0;
    double xyz[3] = {p.x(), p.y(), p.z()};
    return _tree->knnSearch(xyz, k, idx, dist2);
  }
  // the closest point, or size() if there is none
  std::size_t nearest(const SPoint3 &p, double *dist2 = nullptr) const
  {
    std::size_t idx;
    double d2;
    if(!nearest(p, 1, &idx, &d2)) return size();
    if(dist2) *dist2 = d2;
    return idx;
  }
};

#endif
