// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MVERTEX_RTREE
#define MVERTEX_RTREE

#include <vector>
#include "GmshMessage.h"
#include "MVertex.h"
#include "rtree.h"

// Stores MVertex pointers in an R-Tree so we can query unique vertices by their
// coordinates, up to a prescribed tolerance.
class MVertexRTree {
private:
  RTree<MVertex *, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(MVertex *v, void *ctx)
  {
    MVertex **out = static_cast<MVertex **>(ctx);
    *out = v;
    return false; // we're done searching
  }

public:
  MVertexRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<MVertex *, double, 3, double>();
    _tol = tolerance;
  }
  ~MVertexRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  MVertex *insert(MVertex *v, bool warnIfExists = false,
                  std::set<MVertex *, MVertexPtrLessThan> *duplicates = nullptr)
  {
    MVertex *out;
    double _min[3] = {v->x() - _tol, v->y() - _tol, v->z() - _tol};
    double _max[3] = {v->x() + _tol, v->y() + _tol, v->z() + _tol};
    if(!_rtree->Search(_min, _max, rtree_callback, &out)) {
      _rtree->Insert(_min, _max, v);
      return nullptr;
    }
    else {
      if(duplicates) {
        duplicates->insert(out);
        duplicates->insert(v);
      }
      if(warnIfExists) {
        Msg::Warning("Node %d (%.16g, %.16g, %.16g) already exists in the "
                     "mesh with tolerance %g as node %d (%.16g, %.16g, %.16g)",
                     v->getNum(), v->x(), v->y(), v->z(), _tol, out->getNum(),
                     out->x(), out->y(), out->z());
      }
      return out;
    }
  }
  int insert(std::vector<MVertex *> &v, bool warnIfExists = false,
             std::set<MVertex *, MVertexPtrLessThan> *duplicates = nullptr)
  {
    int num = 0;
    for(std::size_t i = 0; i < v.size(); i++)
      num += (insert(v[i], warnIfExists, duplicates) ? 1 : 0);
    return num; // number of vertices not inserted
  }
  MVertex *find(double x, double y, double z)
  {
    MVertex *out;
    double _min[3] = {x - _tol, y - _tol, z - _tol};
    double _max[3] = {x + _tol, y + _tol, z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out)) return out;
    return nullptr;
  }
  std::size_t size() { return _rtree->Count(); }
};

#endif
