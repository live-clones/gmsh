// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MFACE_H_
#define _MFACE_H_

#include <functional>
#include <vector>
#include "MVertex.h"
#include "MEdge.h"
#include "SVector3.h"
#include "GmshMessage.h"

// A mesh face.
class MFace {
 private:
  std::vector<MVertex *> _v;
  std::vector<char> _si; // sorted indices 

 public:
  MFace() {}
  MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3=0);
  MFace(std::vector<MVertex*> v);
  inline int getNumVertices() const { return _v.size(); }
  inline MVertex *getVertex(const int i) const { return _v[i]; }
  inline MVertex *getSortedVertex(const int i) const { return _v[int(_si[i])]; }
  inline MEdge getEdge(const int i) const
  {
    return MEdge(getVertex(i), getVertex((i + 1) % getNumVertices()));
  }

  bool computeCorrespondence(const MFace&,int&,bool&) const;

  void getOrderedVertices(std::vector<MVertex*> &verts) const
  {
    for(int i = 0; i < getNumVertices(); i++)
      verts.push_back(getSortedVertex(i));
  }
  void getOrderedVertices(const MVertex **const verts) const
  {
    for(int i = 0; i < getNumVertices(); i++)
      verts[i] = getSortedVertex(i);
  }
  SVector3 normal() const;
  SVector3 tangent(int num) const
  {
    SVector3 t0(_v[1]->x() - _v[0]->x(), 
                _v[1]->y() - _v[0]->y(),
                _v[1]->z() - _v[0]->z());
    t0.normalize();
    if(!num) return t0;
    SVector3 n = normal();
    SVector3 t1 = crossprod(n, t0);
    return t1;
  }
  SPoint3 barycenter() const
  {
    SPoint3 p(0., 0., 0.);
    int n = getNumVertices();
    for(int i = 0; i < n; i++) {
      MVertex *v = getVertex(i);
      p[0] += v->x();
      p[1] += v->y();
      p[2] += v->z();
    }
    p[0] /= (double)n;
    p[1] /= (double)n;
    p[2] /= (double)n;
    return p;
  }
  SPoint3 interpolate(const double &u, const double &v) const
  {
    SPoint3 p(0., 0., 0.);
    int n = getNumVertices();
    if(n == 3){
      const double ff[3] = {1. - u - v, u, v};
      for(int i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i];
        p[1] += v->y() * ff[i];
        p[2] += v->z() * ff[i];
      }
    }
    else if(n == 4){
      const double ff[4] = {(1 - u) * (1. - v),
                            (1 + u) * (1. - v),
                            (1 + u) * (1. + v),
                            (1 - u) * (1. + v)};        
      for(int i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i] * .25;
        p[1] += v->y() * ff[i] * .25;
        p[2] += v->z() * ff[i] * .25;
      } 
    }
    else
      Msg::Error("Cannot interpolate inside a polygonal MFace with more than 4 edges");
    return p;
  }
};

inline bool operator==(const MFace &f1, const MFace &f2)
{
  if(f1.getNumVertices() != f2.getNumVertices())
    return false;
  for(int i = 0; i < f1.getNumVertices(); i++)
    if(f1.getSortedVertex(i) != f2.getSortedVertex(i))
      return false;
  return true;
}

inline bool operator!=(const MFace &f1, const MFace &f2)
{
  if(f1.getNumVertices() != f2.getNumVertices())
    return true;
  for(int i = 0; i < f1.getNumVertices(); i++)
    if(f1.getSortedVertex(i) != f2.getSortedVertex(i))
      return true;
  return false;
}

struct Equal_Face : public std::binary_function<MFace, MFace, bool> {
  bool operator()(const MFace &f1, const MFace &f2) const
  {
    return (f1 == f2);
  }
};

struct Less_Face : public std::binary_function<MFace, MFace, bool> {
  bool operator()(const MFace &f1, const MFace &f2) const
  {
    for(int i = 0; i < f1.getNumVertices(); i++) {
      if(f1.getSortedVertex(i) < f2.getSortedVertex(i)) return true;
      if(f1.getSortedVertex(i) > f2.getSortedVertex(i)) return false;
    }
    return false;
  }
};


#endif
