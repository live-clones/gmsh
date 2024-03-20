// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MEDGE_H
#define MEDGE_H

#include "MVertex.h"
#include "SVector3.h"
#include <iostream>

// A mesh edge.
class MEdge {
private:
  MVertex *_v[2];
  char _si[2]; // sorted indices

public:
  MEdge()
  {
    _v[0] = _v[1] = nullptr;
    _si[0] = _si[1] = 0;
  }
  MEdge(MVertex *v0, MVertex *v1)
  {
    _v[0] = v0;
    _v[1] = v1;
    if(_v[1]->getNum() < _v[0]->getNum()) {
      _si[0] = 1;
      _si[1] = 0;
    }
    else {
      _si[0] = 0;
      _si[1] = 1;
    }
  }
  std::size_t getNumVertices() const { return 2; }
  MVertex *getVertex(std::size_t i) const { return _v[i]; }
  MVertex *getSortedVertex(std::size_t i) const { return _v[int(_si[i])]; }
  MVertex *getMinVertex() const { return _v[int(_si[0])]; }
  MVertex *getMaxVertex() const { return _v[int(_si[1])]; }

  int computeCorrespondence(MEdge &other)
  {
    if(other.getVertex(0) == _v[0] && other.getVertex(1) == _v[1])
      return 1;
    else if(other.getVertex(0) == _v[1] && other.getVertex(1) == _v[0])
      return -1;
    return 0;
  }

  bool alignWith(MEdge &other)
  {
    int orientation = computeCorrespondence(other);
    if(!orientation) return false;
    if(orientation == -1) {
      std::swap(_v[0], _v[1]);
      std::swap(_si[0], _si[1]);
    }
    return true;
  }

  SVector3 scaledTangent() const
  {
    return SVector3(_v[1]->x() - _v[0]->x(), _v[1]->y() - _v[0]->y(),
                    _v[1]->z() - _v[0]->z());
  }
  SVector3 tangent() const
  {
    SVector3 t(_v[1]->x() - _v[0]->x(), _v[1]->y() - _v[0]->y(),
               _v[1]->z() - _v[0]->z());
    t.normalize();
    return t;
  }
  double length() const
  {
    SVector3 t(_v[1]->x() - _v[0]->x(), _v[1]->y() - _v[0]->y(),
               _v[1]->z() - _v[0]->z());
    return t.norm();
  }
  SVector3 normal() const
  {
    // this computes one of the normals to the edge
    SVector3 t = tangent(), ex(0., 0., 0.);
    if(t[0] == 0.)
      ex[0] = 1.;
    else if(t[1] == 0.)
      ex[1] = 1.;
    else
      ex[2] = 1.;
    SVector3 n = crossprod(t, ex);
    n.normalize();
    return n;
  }
  SPoint3 barycenter() const { return interpolate(0.5); }
  SPoint3 interpolate(const double &t) const
  {
    return SPoint3(t * _v[1]->x() + (1. - t) * _v[0]->x(),
                   t * _v[1]->y() + (1. - t) * _v[0]->y(),
                   t * _v[1]->z() + (1. - t) * _v[0]->z());
  }
  bool isInside(MVertex *v) const;
};

inline bool operator==(const MEdge &e1, const MEdge &e2)
{
  return (e1.getMinVertex() == e2.getMinVertex() &&
          e1.getMaxVertex() == e2.getMaxVertex());
}

inline bool operator!=(const MEdge &e1, const MEdge &e2)
{
  return (e1.getMinVertex() != e2.getMinVertex() ||
          e1.getMaxVertex() != e2.getMaxVertex());
}

struct MEdgeEqual {
  bool operator()(const MEdge &e1, const MEdge &e2) const { return (e1 == e2); }
};

struct MEdgeLessThan {
  bool operator()(const MEdge &e1, const MEdge &e2) const
  {
    if(e1.getMinVertex()->getNum() < e2.getMinVertex()->getNum()) return true;
    if(e1.getMinVertex()->getNum() > e2.getMinVertex()->getNum()) return false;
    if(e1.getMaxVertex()->getNum() < e2.getMaxVertex()->getNum()) return true;
    return false;
  }
};

// assume a set of MEdge, give consecutive list of vertices
bool SortEdgeConsecutive(const std::vector<MEdge> &,
                         std::vector<std::vector<MVertex *> > &vs);

class MEdgeN {
private:
  std::vector<MVertex *> _v;

public:
  MEdgeN() {}
  MEdgeN(const std::vector<MVertex *> &v);
  std::size_t getNumVertices() const { return _v.size(); }
  MVertex *getVertex(std::size_t i) const { return _v[i]; }
  const std::vector<MVertex *> &getVertices() const { return _v; }
  int getPolynomialOrder() const { return (int)(getNumVertices() - 1); }

  MEdge getEdge() const;

  SPoint3 pnt(double u) const;
  SVector3 tangent(double u) const;

  double interpolate(const double val[], double u, int stride = 1) const;
};

#endif
