#include <iostream>
#include <sstream>

#include "rtree.h"
#include "gmsh.h"
#include "Context.h"
#include "GmshMessage.h"

#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

#include "MVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"

#ifndef Periodicity_INCLUDED
#define Periodicity_INCLUDED

struct KeyXYZ
{
  std::vector<int> index;
  std::vector<int> typekey;
  std::size_t entityKeys;
  double x,y,z;
  std::vector<int> nodes;
};

class KeyXYZRTree {
private:
  RTree<struct KeyXYZ *, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(struct KeyXYZ *v, void *ctx)
  {
    struct KeyXYZ **out = static_cast<KeyXYZ **>(ctx);
    *out = v;
  return false; // we're done searching
}

public:
  KeyXYZRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<struct KeyXYZ *, double, 3, double>();
    _tol = tolerance;
  }
  ~KeyXYZRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  void insert(struct KeyXYZ *v)
  {
    struct KeyXYZ *out;
    double _min[3] = {v->x - _tol, v->y - _tol, v->z - _tol};
    double _max[3] = {v->x + _tol, v->y + _tol, v->z + _tol};

    if(!_rtree->Search(_min, _max, rtree_callback, &out)) {
      _rtree->Insert(_min, _max, v);
    }
    else {
      Msg::Debug("Node %d (%.16g, %.16g, %.16g) already exists "
        "with tolerance %g: node %d (%.16g, %.16g, %.16g)",
        v->entityKeys, v->x, v->y, v->z, _tol, out->entityKeys, out->x,
        out->y, out->z);
    }
  }
  struct KeyXYZ *find(struct KeyXYZ *n)
  {
    struct KeyXYZ *out;
    double _min[3] = {n->x - _tol, n->y - _tol, n->z - _tol};
    double _max[3] = {n->x + _tol, n->y + _tol, n->z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out)) { return out; }
    else {
      Msg::Debug("Could not find node corresponding to reference node "
        "%d (%g, %g, %g)",
        n->entityKeys, n->x, n->y, n->z);
      return 0;
    }
  }
};




struct NodeXYZ
{
  int nodeTag;
  double x,y,z;
};

class NodeXYZRTree {
private:
  RTree<struct NodeXYZ *, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(struct NodeXYZ *v, void *ctx)
  {
    struct NodeXYZ **out = static_cast<NodeXYZ **>(ctx);
    *out = v;
  return false; // we're done searching
}

public:
  NodeXYZRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<struct NodeXYZ *, double, 3, double>();
    _tol = tolerance;
  }
  ~NodeXYZRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  void insert(struct NodeXYZ *v)
  {
    struct NodeXYZ *out;
    double _min[3] = {v->x - _tol, v->y - _tol, v->z - _tol};
    double _max[3] = {v->x + _tol, v->y + _tol, v->z + _tol};

    if(!_rtree->Search(_min, _max, rtree_callback, &out)) {
      _rtree->Insert(_min, _max, v);
    }
    else {
      Msg::Debug("Node %d (%.16g, %.16g, %.16g) already exists "
        "with tolerance %g: node %d (%.16g, %.16g, %.16g)",
        v->nodeTag, v->x, v->y, v->z, _tol, out->nodeTag, out->x,
        out->y, out->z);
    }
  }
  struct NodeXYZ *find(struct NodeXYZ *n)
  {
    struct NodeXYZ *out;
    double _min[3] = {n->x - _tol, n->y - _tol, n->z - _tol};
    double _max[3] = {n->x + _tol, n->y + _tol, n->z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out)) { return out; }
    else {
    // std::cout << "Could not find node corresponding to reference node " << n->entityKeys <<
    //           "("<<n->x <<","<<n->y << ","<<n->z << ")" << std::endl;
      Msg::Debug("Could not find node corresponding to reference node "
        "%d (%g, %g, %g)",
        n->nodeTag, n->x, n->y, n->z);
      return 0;
    }
  }
};



void getElementEdgeNodesCoord(const int elementType,
                                            std::vector<std::size_t> & nodeTags,
                                            std::vector<double> & coord,
                                            std::size_t & numElements,
                                            const int tag = -1,
                                            const bool primary = false);

void getElementFaceNodes(const int elementType,
                                        const int faceType,
                                        std::vector<std::size_t> & nodeTags,
                                        std::vector<double> & coord,
                                        const int tag = -1,
                                        const bool primary = false);


void getFullPeriodicKeys(
  GEntity *ge,
  const int elementType, const std::string &fsName,int &order,
  int &numComponents, const int tag, int &tagMaster, const int dim,
  std::vector<int> &typeKeys, std::vector<int> &typeKeysMaster,
  std::vector<std::size_t> &entityKeys,
  std::vector<std::size_t> &entityKeysMaster,
  std::vector<double> &coord,
  std::vector<double> &coordMaster,
  std::vector<int> &orientationSign,
  const bool returnCoord);


#endif // Periodicity_INCLUDED
