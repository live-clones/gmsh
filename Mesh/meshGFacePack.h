#ifndef _MESH_GFACE_PACK_
#define _MESH_GFACE_PACK_

#include <algorithm>
#include <vector>
#include "Numeric.h"
#include "SPoint2.h"
#include "rtree.h"

class planarPointWithExclusionRegion {
  SPoint2 _center;
  SPoint2 _q[4];
public:

 planarPointWithExclusionRegion(const SPoint2 &c, SPoint2 q[4]) : _center(c){
    _q[0] = q[0];
    _q[1] = q[1];
    _q[2] = q[2];
    _q[3] = q[3];
  }
  
  bool inExclusionZone(SPoint2 &p){
    double mat[2][2];
    double b[2], uv[2];
    mat[0][0] = _q[1].x() - _q[0].x();
    mat[0][1] = _q[2].x() - _q[0].x();
    mat[1][0] = _q[1].y() - _q[0].y();
    mat[1][1] = _q[2].y() - _q[0].y();
    b[0] = p.x() - _q[0].x();
    b[1] = p.y() - _q[0].y();
    sys2x2(mat, b, uv);
    if(uv[0] >= 0 && uv[1] >= 0 && 1. - uv[0] - uv[1] >= 0) return true;
    mat[0][0] = _q[3].x() - _q[2].x();
    mat[0][1] = _q[0].x() - _q[2].x();
    mat[1][0] = _q[3].y() - _q[2].y();
    mat[1][1] = _q[0].y() - _q[2].y();
    b[0] = p.x() - _q[2].x();
    b[1] = p.y() - _q[2].y();
    sys2x2(mat, b, uv);
    if(uv[0] >= 0 && uv[1] >= 0 && 1. - uv[0] - uv[1] >= 0) return true;
    return false;    
  }
  void minmax(double _min[2], double _max[2]) const{
    _min[0] =
      std::min(std::min(std::min(_q[0].x(), _q[1].x()), _q[2].x()), _q[3].x());
    _min[1] =
      std::min(std::min(std::min(_q[0].y(), _q[1].y()), _q[2].y()), _q[3].y());
    _max[0] =
      std::max(std::max(std::max(_q[0].x(), _q[1].x()), _q[2].x()), _q[3].x());
    _max[1] =
      std::max(std::max(std::max(_q[0].y(), _q[1].y()), _q[2].y()), _q[3].y());
  }
};

class the_wrapper {
public:
  SPoint2 _p;
  bool _tooclose;
  the_wrapper(const SPoint2 &sp) :  _p(sp) , _tooclose(false){}
};

bool rtree_callback(planarPointWithExclusionRegion *neighbour, void *point)
{
  the_wrapper *w = static_cast<the_wrapper *>(point);
  
  if(neighbour->inExclusionZone(w->_p)) {
    w->_tooclose = true;
    return false;
  }
  return true;
}

class planarSearchTool {
  RTree<planarPointWithExclusionRegion *, double, 2, double> rtree;
  std::vector<planarPointWithExclusionRegion*> v;
 public :
  planarSearchTool(){
  }
  ~planarSearchTool(){
    for (auto ptr : v)delete ptr;
    v.clear();
  }
  void insert (SPoint2 &c,  SPoint2 p[4]){
    planarPointWithExclusionRegion *sp =
      new planarPointWithExclusionRegion(c, p);
    v.push_back(sp);
    double _min[2], _max[2];
    sp->minmax(_min, _max);    
    rtree.Insert(_min, _max, sp);    
  }
  bool insertIfNotTooClose (SPoint2 &c,  SPoint2 p[4]){
    the_wrapper w(c);
    double _min[2] = {c.x() - 1.e-1, c.y() - 1.e-1};
    double _max[2] = {c.x() + 1.e-1, c.y() + 1.e-1};
    rtree.Search(_min, _max, rtree_callback, &w);
    
    return w._tooclose;
  }
};


#endif
