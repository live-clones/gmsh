// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYGON_H
#define MPOLYGON_H

#include "MElement.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "SVector3.h"

#include <array>
#include <unordered_map>

class MPolygon : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::vector<int> _triangles;
  int _numVertices;
  double _normal[3];

public:
  MPolygon(const std::vector<MVertex *> &vertices, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _vertices = vertices;
    _numVertices = _vertices.size();

    for(int j = 0; j < 3; ++j) _normal[j] = 0.0;
    int N = vertices.size();
    for(int i = 0; i < N; ++i) {
      double a[3] = {_vertices[(i + 1) % N]->x() - _vertices[i]->x(),
                     _vertices[(i + 1) % N]->y() - _vertices[i]->y(),
                     _vertices[(i + 1) % N]->z() - _vertices[i]->z()};
      double b[3] = {_vertices[(i + 2) % N]->x() - _vertices[i]->x(),
                     _vertices[(i + 2) % N]->y() - _vertices[i]->y(),
                     _vertices[(i + 2) % N]->z() - _vertices[i]->z()};
      double c[3];
      prodve(a, b, c);
      for(int j = 0; j < 3; ++j) _normal[j] += c[j];
    }
    double den = 1. / sqrt(prosca(_normal, _normal));
    for(int j = 0; j < 3; ++j) _normal[j] *= den;
  }
  ~MPolygon() {}

  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return _numVertices; }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }
  virtual int getNumEdges() const { return getNumVertices(); }
  std::array<int, 2> getEdgeIndices(int num) const
  {
    return {num, (num + 1) % getNumEdges()};
  }
  virtual MEdge getEdge(int num) const
  {
    std::array<int, 2> is = getEdgeIndices(num);
    return MEdge(_vertices[is[0]], _vertices[is[1]]);
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  std::array<int, 2> getEdgeRepIndices(bool curved, int num) const
  {
    return getEdgeIndices(num);
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
  virtual MFace getFace(int num) const
  {
    std::vector<MVertex *> faceVertices(_vertices.begin(),
                                        _vertices.begin() + getNumVertices());
    return MFace(faceVertices);
  }
  virtual int getNumFacesRep(bool curved) { return _triangles.size() / 3; }
  std::array<int, 3> getFaceRepIndices(bool curved, int num) const
  {
    return {_triangles[3 * num], _triangles[3 * num + 1],
            _triangles[3 * num + 2]};
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_vertices[_triangles[3 * num]],
                _vertices[_triangles[3 * num + 1]],
                _vertices[_triangles[3 * num + 2]], x, y, z, n);
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

  void setTriangles(std::vector<MVertex *> &simplices)
  {
    std::unordered_map<MVertex *, int> indices;
    for(int i = 0; i < _vertices.size(); ++i) indices[_vertices[i]] = i;
    _triangles.resize(simplices.size());
    for(int i = 0; i < simplices.size(); ++i) {
      auto it = indices.find(simplices[i]);
      if(it == indices.end()) {
        _vertices.push_back(simplices[i]);
        it = indices.insert({simplices[i], i}).first;
      }
      _triangles[i] = it->second;
    }
  }
  int getNumTriangles() { return _triangles.size() / 3; }
  std::array<int, 3> getTriangleIndices(int num) const
  {
    return {_triangles[3 * num], _triangles[3 * num + 1],
            _triangles[3 * num + 2]};
  }
  MTriangle getTriangle(int num) const
  {
    std::array<int, 3> is = getTriangleIndices(num);
    return MTriangle(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]]);
  }
  double *getNormal() const { return (double *)_normal; }

  void meanValueCoord(double *v, std::vector<double> &coord)
  {
    int N = getNumVertices();
    coord.resize(N);
    std::vector<double> r(N), b(N), g(N), s(N);
    double W = 0.;

    for(int i = 0; i < N; ++i) {
      double *vi = &_vertices[i]->x(), *vip1 = &_vertices[(i + 1) % N]->x();
      b[i] = angle_plan(vi, vip1, v, _normal);
      g[i] = angle_plan(vip1, v, vi, _normal);
      s[i] = b[i] + g[i];
      r[i] = sqrt(pow(vi[0] - v[0], 2) + pow(vi[1] - v[1], 2) +
                  pow(vi[2] - v[2], 2));
    }

    for(int i = 0; i < N; ++i) {
      int im1 = (i - 1 + N) % N, ip1 = (i + 1) % N;
      double *vim1 = &_vertices[im1]->x(), *vip1 = &_vertices[ip1]->x();
      double a = angle_plan(v, vim1, vip1, _normal);
      double signs =
        (s[im1] >= 0.) + (s[i] >= 0.) - (s[im1] < 0.) - (s[i] < 0.);
      double ss = M_PI * signs - s[im1] - s[i];
      if(a * ss < 0.) a *= -1;
      coord[i] = r[im1] * sin(a / 2);
      for(int j = 0; j < N; ++j) {
        if(j == im1 || j == i) continue;
        coord[i] *= r[j] * sin(abs(s[j]) / 2);
      }
      W += coord[i];
    }

    if(abs(W) < 1e-14) {
      Msg::Warning("W = 0");
      for(auto &c : coord) c = 0.;
      return;
    }
    double inv_W = 1. / W;
    for(int i = 0; i < N; ++i) coord[i] *= inv_W;
  }
};

#endif
