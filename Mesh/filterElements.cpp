// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <vector>
#include <set>
#include "GmshDefines.h"
#include "filterElements.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "rtree.h"
#include "robustPredicates.h"

void MElementBB(void *a, double *min, double *max);
int MElementInEle(void *a, double *x);

struct MElement_Wrapper {
  bool _overlap;
  MElement *_e;
  std::vector<MElement *> _notOverlap;
  MElement_Wrapper(MElement *e, const std::vector<MElement *> &notOverlap)
    : _overlap(false), _e(e), _notOverlap(notOverlap)
  {
    std::sort(_notOverlap.begin(), _notOverlap.end());
  }
};

/** OVERLAP TEST IN 2D
    only use predicate orient2D :-)

2 cases

1-->

    *---------*
    |         |
    |     *--------*
    |     |   |    |
    *---------*
          |   |    |
          *--------*

2-->

**/

inline double orientationTest(double a[2], double b[2], double c[2])
{
  double s = -robustPredicates::orient2d(a, b, c);
  return s >= 0 ? 1.0 : s <= 0 ? -1.0 : 0.0;
}

inline double orientationTest(MVertex *va, MVertex *vb, MVertex *vc)
{
  double a[2] = {va->x(), va->y()};
  double b[2] = {vb->x(), vb->y()};
  double c[2] = {vc->x(), vc->y()};
  return orientationTest(a, b, c);
}

inline double orientationTest(SVector3 &va, SVector3 &vb, SVector3 &vc)
{
  double a[2] = {va.x(), va.y()};
  double b[2] = {vb.x(), vb.y()};
  double c[2] = {vc.x(), vc.y()};
  return orientationTest(a, b, c);
}

bool intersectEdge2d(const MEdge &ed1, const MEdge &ed2)
{
  double xmax1 = std::max(ed1.getVertex(0)->x(), ed1.getVertex(1)->x());
  double xmax2 = std::max(ed2.getVertex(0)->x(), ed2.getVertex(1)->x());
  double ymax1 = std::max(ed1.getVertex(0)->y(), ed1.getVertex(1)->y());
  double ymax2 = std::max(ed2.getVertex(0)->y(), ed2.getVertex(1)->y());
  double xmin1 = std::min(ed1.getVertex(0)->x(), ed1.getVertex(1)->x());
  double xmin2 = std::min(ed2.getVertex(0)->x(), ed2.getVertex(1)->x());
  double ymin1 = std::min(ed1.getVertex(0)->y(), ed1.getVertex(1)->y());
  double ymin2 = std::min(ed2.getVertex(0)->y(), ed2.getVertex(1)->y());

  if(xmax1 < xmin2) return false;
  if(xmax2 < xmin1) return false;
  if(ymax1 < ymin2) return false;
  if(ymax2 < ymin1) return false;

  if(xmin1 > xmax2) return false;
  if(xmin2 > xmax1) return false;
  if(ymin1 > ymax2) return false;
  if(ymin2 > ymax1) return false;

  //	       ed2.getVertex(0)->x(),ed2.getVertex(0)->y(),ed2.getVertex(1)->x(),ed2.getVertex(1)->y()

  /*  SVector3 a1(ed1.getVertex(0)->x(), ed1.getVertex(0)->y(), 0);
  SVector3 a2(ed1.getVertex(1)->x(), ed1.getVertex(1)->y(), 0);

  SVector3 b1(ed2.getVertex(0)->x(), ed2.getVertex(0)->y(), 0);
  SVector3 b2(ed2.getVertex(1)->x(), ed2.getVertex(1)->y(), 0);

  SVector3 a = (a1+a2)*0.5;
  SVector3 b = (b1+b2)*0.5;

  SVector3 a1l = a + (a2-a1)*0.55;
  SVector3 a2l = a - (a2-a1)*0.55;

  SVector3 b1l = b + (b2-b1)*0.55;
  SVector3 b2l = b - (b2-b1)*0.55;

  if (orientationTest (a1l, a2l, b1l) * orientationTest (a1l, a2l, b2l) <= 0 &&
      orientationTest (b1l, b2l, a1l) * orientationTest (b1l, b2l, a2l) <= 0 )
    return true;
  */
  if(ed1.getVertex(0) == ed2.getVertex(0) ||
     ed1.getVertex(0) == ed2.getVertex(1) ||
     ed1.getVertex(1) == ed2.getVertex(0) ||
     ed1.getVertex(1) == ed2.getVertex(1))
    return false;

  if((orientationTest(ed1.getVertex(0), ed1.getVertex(1), ed2.getVertex(0)) *
        orientationTest(ed1.getVertex(0), ed1.getVertex(1), ed2.getVertex(1)) <=
      0) &&
     (orientationTest(ed2.getVertex(0), ed2.getVertex(1), ed1.getVertex(0)) *
        orientationTest(ed2.getVertex(0), ed2.getVertex(1), ed1.getVertex(1)) <=
      0))
    return true;
  return false;
}

bool overlap2D(MElement *e1, MElement *e2)
{
  for(int i = 0; i < e1->getNumEdges(); i++) {
    MEdge ed1 = e1->getEdge(i);
    for(int j = 0; j < e2->getNumEdges(); j++) {
      MEdge ed2 = e2->getEdge(j);
      if(intersectEdge2d(ed1, ed2)) {
        //	printf("apero time nnodes %d %d partitions %d %d  : %g %g -- %g %g
        // vs %g %g -- %g %g\n",
        //	       e1->getNumVertices(),e2->getNumVertices(),
        //	       e1->getPartition(),e2->getPartition(),
        //	       ed1.getVertex(0)->x(),ed1.getVertex(0)->y(),ed1.getVertex(1)->x(),ed1.getVertex(1)->y(),
        //	       ed2.getVertex(0)->x(),ed2.getVertex(0)->y(),ed2.getVertex(1)->x(),ed2.getVertex(1)->y()
        //		       );
        return true;
      }
    }
  }
  return false;
}

bool rtree_callback(MElement *e1, void *pe2)
{
  MElement_Wrapper *wrapper = static_cast<MElement_Wrapper *>(pe2);
  MElement *e2 = wrapper->_e;

  if(std::binary_search(wrapper->_notOverlap.begin(),
                        wrapper->_notOverlap.end(), e1))
    return true;

  //    for (int i=0;i<e1->getNumVertices();i++){
  //      for (int j=0;j<e2->getNumVertices();j++){
  //        if(e1->getVertex(i) == e2->getVertex(j))return true;
  //      }
  //    }

  if(e1->getDim() <= 2 && e2->getDim() <= 2) {
    wrapper->_overlap = overlap2D(e1, e2);
    return !wrapper->_overlap;
  }
  Msg::Error("overlapping of elements in 3D not done yet");
  return true;
}

struct Less_Partition
  : public std::binary_function<MElement *, MElement *, bool> {
  bool operator()(const MElement *f1, const MElement *f2) const
  {
    return f1->getPartition() < f2->getPartition();
  }
};

void filterColumns(std::vector<MElement *> &elem,
                   std::map<MElement *, std::vector<MElement *> > &_elemColumns)
{
  std::sort(elem.begin(), elem.end());
  std::vector<MElement *> toKeep;
  for(auto it = _elemColumns.begin(); it != _elemColumns.end(); ++it) {
    const std::vector<MElement *> &c = it->second;
    std::size_t MAX = c.size();
    //    printf("size of column %d\n",c.size());
    for(std::size_t i = 0; i < c.size(); i++) {
      if(!std::binary_search(elem.begin(), elem.end(), c[i])) {
        MAX = i;
        break;
      }
    }
    if(!MAX) MAX = 1;
    //    if (MAX != c.size())    printf("MAX = %d c = %d\n",MAX,c.size());
    for(std::size_t i = 0; i < MAX; i++) {
      if(orientationTest(c[i]->getVertex(0), c[i]->getVertex(1),
                         c[i]->getVertex(2)) < 0)
        c[i]->reverse();
      toKeep.push_back(c[i]);
    }
    // for (std::size_t i=MAX;i<c.size();i++){
    // FIXME !!!
    //   delete c[i];
    // }
  }
  // printf("%d --> %d\n", (int)elem.size(), (int)toKeep.size());
  elem = toKeep;
}

static void filterOverlappingElements(
  std::vector<MLine *> &lines, std::vector<MElement *> &els,
  std::map<MElement *, std::vector<MElement *> > &_elemColumns,
  std::map<MElement *, MElement *> &_toFirst)
{
  std::vector<MElement *> newEls;
  RTree<MElement *, double, 3, double> rtree;

  for(std::size_t i = 0; i < lines.size(); i++) {
    MElement *e = lines[i];
    double _min[3], _max[3];
    MElementBB(e, _min, _max);
    rtree.Insert(_min, _max, e);
  }

  for(std::size_t i = 0; i < els.size(); i++) {
    MElement *e = els[i];
    double _min[3], _max[3];
    MElementBB(e, _min, _max);
    MElement *first = _toFirst[e];
    MElement_Wrapper w(e, _elemColumns[first]);
    rtree.Search(_min, _max, rtree_callback, &w);
    if(w._overlap) {
      //     delete e;
    }
    else {
      rtree.Insert(_min, _max, e);
      newEls.push_back(e);
    }
  }
  els = newEls;
}

// WE SHOULD ADD THE BOUNDARY OF THE DOMAIN IN ORDER TO AVOID
// ELEMENTS THAT ARE OUTSIDE THE DOMAIN --> FIXME

void filterOverlappingElements(
  std::vector<MLine *> &bdry, std::vector<MTriangle *> &blTris,
  std::vector<MQuadrangle *> &blQuads,
  std::map<MElement *, std::vector<MElement *> > &_elemColumns,
  std::map<MElement *, MElement *> &_toFirst)
{
  std::vector<MElement *> vvv;
  vvv.insert(vvv.begin(), blTris.begin(), blTris.end());
  vvv.insert(vvv.begin(), blQuads.begin(), blQuads.end());
  Less_Partition lp;
  std::sort(vvv.begin(), vvv.end(), lp);
  filterOverlappingElements(bdry, vvv, _elemColumns, _toFirst);
  filterColumns(vvv, _elemColumns);
  blTris.clear();
  blQuads.clear();
  for(std::size_t i = 0; i < vvv.size(); i++) {
    if(vvv[i]->getType() == TYPE_TRI)
      blTris.push_back((MTriangle *)vvv[i]);
    else if(vvv[i]->getType() == TYPE_QUA)
      blQuads.push_back((MQuadrangle *)vvv[i]);
  }
}
