// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MFACE_H
#define MFACE_H

#include <functional>
#include <vector>
#include "MVertex.h"
#include "MEdge.h"
#include "SVector3.h"
#include "GmshMessage.h"
#include "GmshDefines.h"

template <class t> class fullMatrix;

// A mesh face.
class MFace {
private:
  // faces have 3 or 4 nodes, except the polygonal ones of cut elements: store
  // the usual cases inline, and only allocate for the polygons. (MFace is
  // created by the million during meshing - one per face of every element -
  // so allocating for it shows up in profiles.)
  MVertex *_v[4];
  char _si[4]; // sorted indices
  int _n;
  struct polygon {
    std::vector<MVertex *> v;
    std::vector<char> si;
  };
  polygon *_p; // non-null iff _n > 4

  void _initialize(MVertex *const *v, int n);
  void _copy(const MFace &f);
  void _copyInline(const MFace &f)
  {
    _n = f._n;
    for(int i = 0; i < 4; i++) {
      _v[i] = f._v[i];
      _si[i] = f._si[i];
    }
  }

public:
  MFace() : _n(0), _p(nullptr) {}
  MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3 = nullptr);
  MFace(const std::vector<MVertex *> &v);
  ~MFace() { delete _p; }
  MFace(const MFace &f) : _p(nullptr) { _copy(f); }
  MFace(MFace &&f) noexcept : _p(f._p)
  {
    _copyInline(f);
    f._p = nullptr;
    f._n = 0;
  }
  MFace &operator=(const MFace &f)
  {
    if(this != &f) {
      delete _p;
      _p = nullptr;
      _copy(f);
    }
    return *this;
  }
  MFace &operator=(MFace &&f) noexcept
  {
    if(this != &f) {
      delete _p;
      _p = f._p;
      f._p = nullptr;
      _copyInline(f);
      f._n = 0;
    }
    return *this;
  }
  std::size_t getNumVertices() const { return (std::size_t)_n; }
  MVertex *getVertex(std::size_t i) const
  {
    return _p ? _p->v[i] : _v[i];
  }
  MVertex *getSortedVertex(std::size_t i) const
  {
    return _p ? _p->v[std::size_t(_p->si[i])] : _v[std::size_t(_si[i])];
  }
  MEdge getEdge(std::size_t i) const
  {
    return MEdge(getVertex(i), getVertex((i + 1) % getNumVertices()));
  }
  void getOrientationFlagForFace(std::vector<int> &faceOrientationFlag);
  bool computeCorrespondence(const MFace &, int &, bool &) const;

  void getOrderedVertices(std::vector<MVertex *> &verts) const
  {
    for(std::size_t i = 0; i < getNumVertices(); i++)
      verts.push_back(getSortedVertex(i));
  }
  void getOrderedVertices(const MVertex **const verts) const
  {
    for(std::size_t i = 0; i < getNumVertices(); i++) {
      verts[i] = getSortedVertex(i);
    }
  }
  double approximateArea() const;
  SVector3 normal() const;
  SVector3 tangent(int num) const
  {
    MVertex *v0 = getVertex(0), *v1 = getVertex(1);
    SVector3 t0(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    t0.normalize();
    if(!num) return t0;
    SVector3 n = normal();
    SVector3 t1 = crossprod(n, t0);
    return t1;
  }
  SPoint3 barycenter() const
  {
    SPoint3 p(0., 0., 0.);
    std::size_t n = getNumVertices();
    for(std::size_t i = 0; i < n; i++) {
      const MVertex *v = getVertex(i);
      p[0] += v->x();
      p[1] += v->y();
      p[2] += v->z();
    }
    p[0] /= static_cast<double>(n);
    p[1] /= static_cast<double>(n);
    p[2] /= static_cast<double>(n);
    return p;
  }
  SPoint3 interpolate(const double &u, const double &v) const
  {
    SPoint3 p(0.0, 0.0, 0.0);
    std::size_t n = getNumVertices();
    if(n == 3) {
      const double ff[3] = {1.0 - u - v, u, v};
      for(std::size_t i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i];
        p[1] += v->y() * ff[i];
        p[2] += v->z() * ff[i];
      }
    }
    else if(n == 4) {
      const double ff[4] = {(1 - u) * (1. - v), (1 + u) * (1. - v),
                            (1 + u) * (1. + v), (1 - u) * (1. + v)};
      for(std::size_t i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i] * 0.25;
        p[1] += v->y() * ff[i] * 0.25;
        p[2] += v->z() * ff[i] * 0.25;
      }
    }
    else
      Msg::Error(
        "Cannot interpolate inside a polygonal MFace with more than 4 edges");
    return p;
  }
};

inline bool operator==(const MFace &f1, const MFace &f2)
{
  if(f1.getNumVertices() != f2.getNumVertices()) return false;
  for(std::size_t i = 0; i < f1.getNumVertices(); i++)
    if(f1.getSortedVertex(i)->getNum() != f2.getSortedVertex(i)->getNum())
      return false;
  return true;
}

inline bool operator!=(const MFace &f1, const MFace &f2)
{
  if(f1.getNumVertices() != f2.getNumVertices()) return true;
  for(std::size_t i = 0; i < f1.getNumVertices(); i++)
    if(f1.getSortedVertex(i)->getNum() != f2.getSortedVertex(i)->getNum())
      return true;
  return false;
}

struct MFaceEqual {
  bool operator()(const MFace &f1, const MFace &f2) const { return (f1 == f2); }
};

struct MFaceLessThan {
  bool operator()(const MFace &f1, const MFace &f2) const
  {
    if(f1.getNumVertices() != f2.getNumVertices())
      return f1.getNumVertices() < f2.getNumVertices();
    for(std::size_t i = 0; i < f1.getNumVertices(); i++) {
      if(f1.getSortedVertex(i)->getNum() < f2.getSortedVertex(i)->getNum())
        return true;
      if(f1.getSortedVertex(i)->getNum() > f2.getSortedVertex(i)->getNum())
        return false;
    }
    return false;
  }
};

class MFaceN {
private:
  int _type;
  int _order;
  std::vector<MVertex *> _v;

public:
  MFaceN() {}
  MFaceN(int type, int order, const std::vector<MVertex *> &v);

  int getPolynomialOrder() const { return _order; }
  int getType() const { return _type; }
  bool isTriangular() const { return _type == TYPE_TRI; }
  std::size_t getNumVertices() const { return (int)_v.size(); }
  int getNumCorners() const { return isTriangular() ? 3 : 4; }
  int getNumVerticesOnBoundary() const { return getNumCorners() * _order; }

  MVertex *getVertex(std::size_t i) const { return _v[i]; }
  const std::vector<MVertex *> &getVertices() const { return _v; }

  MEdgeN getHighOrderEdge(int num, int sign) const;
  MFace getFace() const;

  SPoint3 pnt(double u, double v) const;
  SVector3 tangent(double u, double v, int num) const;
  SVector3 normal(double u, double v) const;
  void frame(double u, double v, SVector3 &t0, SVector3 &t1, SVector3 &n) const;
  void frame(double u, double v, SPoint3 &p, SVector3 &t0, SVector3 &t1,
             SVector3 &n) const;

  void repositionInnerVertices(const fullMatrix<double> *) const;
};

#endif
