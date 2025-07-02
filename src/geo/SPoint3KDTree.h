// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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

#endif
