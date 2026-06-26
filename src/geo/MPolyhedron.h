// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYHEDRON_H
#define MPOLYHEDRON_H

#include "MElement.h"
#include "MTetrahedron.h"

#include <array>
#include <unordered_map>
#include <unordered_set>

class MPolyhedron : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::vector<int> _polygons, _polygonStarts;
  std::vector<int> _tetrahedra, _triangles, _lines;
  int _numVertices;

public:
  MPolyhedron(const std::vector<MVertex *> &vertices, int num = 0, int part = 0)
    : MElement(num, part)
  {
    std::unordered_set<MVertex *> set;
    for(int i = 0; i < vertices.size(); ++i) {
      MVertex *v = vertices[i];
      auto it = set.find(v);
      if(it == set.end()) {
        _vertices.push_back(v);
        set.insert(v);
      }
    }
    _numVertices = _vertices.size();
  }
  ~MPolyhedron() {}

  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return _numVertices; }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }
  virtual int getNumEdges() const { return _lines.size() / 2; }
  std::array<int, 2> getEdgeIndices(int num) const
  {
    return {_lines[2 * num], _lines[2 * num + 1]};
  }
  virtual MEdge getEdge(int num) const
  {
    std::array<int, 2> is = getEdgeIndices(num);
    return MEdge(_vertices[is[0]], _vertices[is[1]]);
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
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
  virtual int getNumFaces() { return _polygonStarts.size() - 1; }
  virtual MFace getFace(int num) const
  {
    std::vector<MVertex *> polygonVertices(
      _vertices.begin() + _polygonStarts[num],
      _vertices.begin() + _polygonStarts[num + 1]);
    return MFace(polygonVertices);
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
    std::array<int, 3> is = getFaceRepIndices(curved, num);
    MVertex *vs[3] = {_vertices[is[0]], _vertices[is[1]], _vertices[is[2]]};
    SVector3 p0(vs[1]->x() - vs[0]->x(), vs[1]->y() - vs[0]->y(),
                vs[1]->z() - vs[0]->z());
    SVector3 p1(vs[2]->x() - vs[0]->x(), vs[2]->y() - vs[0]->y(),
                vs[2]->z() - vs[0]->z());
    SVector3 cp = crossprod(p0, p1);
    cp.normalize();
    for(int i = 0; i < 3; i++) {
      x[i] = vs[i]->x();
      y[i] = vs[i]->y();
      z[i] = vs[i]->z();
      n[i] = cp;
    }
  }
  virtual int getType() const { return TYPE_POLYH; }
  virtual int getTypeForMSH() const { return MSH_POLYH_; }
  virtual bool isInside(double u, double v, double w) const
  {
    // TODO
    return false;
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }

  void setPolygonsAndTetrahedra(std::vector<MVertex *> &borderVertices,
                                std::vector<int> &borderOffset,
                                std::vector<MVertex *> &simplicesVertices)
  {
    std::unordered_map<MVertex *, int> indices;
    for(int i = 0; i < _vertices.size(); ++i) indices[_vertices[i]] = i;

    // Polygons
    _polygons.resize(borderVertices.size());
    for(int i = 0; i < borderVertices.size(); ++i)
      _polygons[i] = indices[borderVertices[i]];
    _polygonStarts = borderOffset;

    // Lines
    for(int i = 0; i < _polygonStarts.size(); ++i) {
      int N = _polygonStarts[i + 1] - _polygonStarts[i];
      for(int j = 0; j < N; ++j) {
        int index0 = _polygonStarts[i] + j;
        int index1 = _polygonStarts[i] + (j + 1) % N;
        if(_polygons[index0] > _polygons[index1]) continue;
        _lines.push_back(_polygons[index0]);
        _lines.push_back(_polygons[index1]);
      }
    }

    // Tetrahedra
    _tetrahedra.resize(simplicesVertices.size());
    for(int i = 0; i < simplicesVertices.size(); ++i)
      _tetrahedra[i] = indices[simplicesVertices[i]];

    // Triangles
    auto hasher = [](const std::array<int, 3> &t) -> std::size_t {
      auto [a, b, c] = t;
      return (uint64_t)a << 42 | (uint64_t)b << 21 | (uint64_t)c;
    };
    std::unordered_map<std::array<int, 3>, int, decltype(hasher)> faces(0,
                                                                        hasher);
    for(int i = 0; i < _tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        int i0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        int i1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        int i2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<int, 3> t = {i0, i1, i2};
        std::sort(t.begin(), t.end());
        ++faces[t];
      }
    }
    for(int i = 0; i < _tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        int i0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        int i1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        int i2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<int, 3> t = {i0, i1, i2};
        std::sort(t.begin(), t.end());
        int n = faces[t];
        if(n == 1) {
          _triangles.push_back(i0);
          _triangles.push_back(i1);
          _triangles.push_back(i2);
        }
        else if(n != 2) {
          Msg::Error("Face %d %d %d has more than 2 adjacent _tetrahedra in "
                     "polyhedron %d",
                     _vertices[i0]->getNum(), _vertices[i1]->getNum(),
                     _vertices[i2]->getNum(), getNum());
        }
      }
    }
  }

  int getNumPolygons() { return _polygonStarts.size() - 1; }
  int getPolygonStart(int i) { return _polygonStarts[i]; }
  MVertex *getPolygonVertex(int i) { return _vertices[_polygons[i]]; }

  int getNumTetrahedra() const { return _tetrahedra.size() / 4; }
  std::array<int, 4> getTetrahedronIndices(int num) const
  {
    return {_tetrahedra[4 * num], _tetrahedra[4 * num + 1],
            _tetrahedra[4 * num + 2], _tetrahedra[4 * num + 3]};
  }
  MTetrahedron getTetrahedron(int num) const
  {
    std::array<int, 4> is = getTetrahedronIndices(num);
    return MTetrahedron(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]],
                        _vertices[is[3]]);
  }
};

#endif
