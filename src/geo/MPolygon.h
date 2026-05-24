// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYGON_H
#define MPOLYGON_H

#include "MElement.h"
#include "MTriangle.h"
#include "SVector3.h"

#include <unordered_map>
#include <utility>

class MPolygon : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::vector<size_t> _tri, _border;
  SVector3 _normal;

  void computeBorder()
  {
    auto hasher = [](const std::pair<std::size_t, std::size_t> p) -> size_t {
      std::size_t packed = (p.first << 32) | (p.second & 0xFFFFFFFF);
      return std::hash<std::size_t>{}(packed);
    };
    std::unordered_map<std::pair<std::size_t, std::size_t>, int,
                       decltype(hasher)>
      edges(0, hasher);
    for(size_t i = 0; i < _tri.size(); i += 3) {
      for(int j = 0; j < 3; ++j) {
        size_t i0 = _tri[i + j];
        size_t i1 = _tri[i + (j + 1) % 3];
        std::pair<std::size_t, std::size_t> e = {i0, i1};
        if(e.first > e.second) std::swap(e.first, e.second);
        ++edges[e];
      }
    }

    std::unordered_map<size_t, size_t> borders;
    for(size_t i = 0; i < _tri.size(); i += 3) {
      for(int j = 0; j < 3; ++j) {
        size_t i0 = _tri[i + j];
        size_t i1 = _tri[i + (j + 1) % 3];
        std::pair<std::size_t, std::size_t> e = {i0, i1};
        if(e.first > e.second) std::swap(e.first, e.second);
        int n = edges[e];
        if(n == 1)
          borders[i0] = i1;
        else if(n != 2)
          Msg::Error("Non manifold edge %d %d in polygon %d",
                     _vertices[i0]->getNum(), _vertices[i1]->getNum(),
                     getNum());
      }
    }

    _border.reserve(borders.size());
    auto it = borders.begin();
    _border.push_back(it->first);
    while(it->second != _border[0]) {
      _border.push_back(it->second);
      it = borders.find(it->second);
      if(it == borders.end())
        Msg::Error("Cannot reconstruct boundary of polygon %d", getNum());
    }
    if(_border.size() != borders.size()) {
      Msg::Error("The boundary of polygon %d is not a simple loop", getNum());
    }
  }

  void computeNormal()
  {
    _normal = SVector3(0, 0, 0);
    for(size_t i = 0; i < _vertices.size(); ++i) {
      MVertex *v0 = getVertex(i);
      MVertex *v1 = getVertex((i + 1) % _vertices.size());
      MVertex *v2 = getVertex((i + 2) % _vertices.size());
      SVector3 p0(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
      SVector3 p1(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z());
      _normal += crossprod(p0, p1);
    }
    _normal *= 1. / norm(_normal);
  }

public:
  MPolygon(const std::vector<MVertex *> &tri, int num = 0, int part = 0)
    : MElement(num, part)
  {
    std::unordered_map<MVertex *, size_t> indices;
    size_t index;
    _tri.resize(tri.size());
    for(size_t i = 0; i < tri.size(); i += 3) {
      for(int j = 0; j < 3; ++j) {
        auto it = indices.find(tri[i + j]);
        if(it != indices.end())
          index = it->second;
        else {
          index = _vertices.size();
          _vertices.push_back(tri[i + j]);
          indices[_vertices.back()] = index;
        }
        _tri[i + j] = index;
      }
    }

    computeBorder();
    computeNormal();
  }
  ~MPolygon() {}
  int getNumSimplices() { return _tri.size() / 3; }
  MTriangle getSimplex(int num) const
  {
    return MTriangle(_vertices[_tri[3 * num]], _vertices[_tri[3 * num + 1]],
                     _vertices[_tri[3 * num + 2]]);
  }
  SVector3 getNormal() const { return _normal; }
  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return _vertices.size(); }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const
  {
    return _vertices[_border[num]];
  }
  virtual int getNumEdges() const { return _border.size(); }
  virtual MEdge getEdge(int num) const
  {
    if(num < (int)_border.size() - 1)
      return MEdge(_vertices[_border[num]], _vertices[_border[num + 1]]);
    return MEdge(_vertices[_border[num]], _vertices[_border[0]]);
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  std::array<size_t, 2> getEdgeRepIndices(bool curved, int num) const
  {
    if(num < (int)_border.size() - 1) return {_border[num], _border[num + 1]};
    return {_border[num], _border[0]};
  }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    MEdge e = getEdge(num);
    for(int i = 0; i < 2; i++) {
      x[i] = e.getVertex(i)->x();
      y[i] = e.getVertex(i)->y();
      z[i] = e.getVertex(i)->z();
      n[i] = SVector3(0., 0., 1.); // TODO
    }
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const { return MFace(_vertices); }
  virtual int getNumFacesRep(bool curved) { return _tri.size() / 3; }
  std::array<size_t, 3> getFaceRepIndices(bool curved, int num) const
  {
    return {_tri[3 * num], _tri[3 * num + 1], _tri[3 * num + 2]};
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_vertices[_tri[3 * num]], _vertices[_tri[3 * num + 1]],
                _vertices[_tri[3 * num + 2]], x, y, z, n);
  }
  virtual int getType() const { return TYPE_POLYG; }
  virtual int getTypeForMSH() const { return MSH_POLYG_; }
  virtual bool isInside(double u, double v, double w) const
  {
    return false; // TODO
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

#endif
