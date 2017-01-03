// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MVERTEX_RTREE_
#define _MVERTEX_RTREE_

#include <vector>
#include "GmshMessage.h"
#include "MVertex.h"
#include "rtree.h"

// Stores MVertex pointers in an R-Tree so we can query unique vertices by their
// coordinates, up to a prescribed tolerance.
class MVertexRTree{
 private:
  RTree<MVertex*, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(MVertex *v, void *ctx)
  {
    MVertex **out = static_cast<MVertex**>(ctx);
    *out = v;
    return false; // we're done searching
  }
 public:
  MVertexRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<MVertex*, double, 3, double>();
    _tol = tolerance;
  }
  ~MVertexRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  MVertex *insert(MVertex *v, bool warnIfExists=false)
  {
    MVertex *out;
    double _min[3] = {v->x() - _tol, v->y() - _tol, v->z() - _tol};
    double _max[3] = {v->x() + _tol, v->y() + _tol, v->z() + _tol};
    if(!_rtree->Search(_min, _max, rtree_callback, &out)){
      _rtree->Insert(_min, _max, v);
      return 0;
    }
    else{
      if(warnIfExists)
        Msg::Warning("Vertex %d (%.16g, %.16g, %.16g) already exists in the "
                     "mesh with tolerance %g", v->getNum(),
                     v->x(), v->y(), v->z(), _tol);
      return out;
    }
  }
  int insert(std::vector<MVertex*> &v, bool warnIfExists=false)
  {
    int num = 0;
    for(unsigned int i = 0; i < v.size(); i++)
      num += (insert(v[i], warnIfExists) ? 1 : 0);
    return num; // number of vertices not inserted
  }
  MVertex *find(double x, double y, double z)
  {
    MVertex *out;
    double _min[3] = {x - _tol, y - _tol, z - _tol};
    double _max[3] = {x + _tol, y + _tol, z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out))
      return out;
    return 0;
  }
  unsigned int size()
  {
    return _rtree->Count();
  }
};

#endif
