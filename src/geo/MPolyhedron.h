// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYHEDRON_H
#define MPOLYHEDRON_H

#include "MElement.h"
#include "MTetrahedron.h"
#include "SVector3.h"

#include <array>
#include <unordered_set>

class MPolyhedron : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::vector<size_t> _tetrahedra, _border_f, _border_e, _border_v;
  std::vector<SVector3> _normals_v;

  void computeBorder()
  {
    auto hasher = [](const std::array<std::size_t, 3> &t) -> std::size_t {
      auto [v0, v1, v2] = t; // Extract the three size_t values
      std::size_t seed = std::hash<std::size_t>{}(v0);
      seed ^=
        std::hash<std::size_t>{}(v1) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      seed ^=
        std::hash<std::size_t>{}(v2) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      return seed;
    };
    std::unordered_map<std::array<std::size_t, 3>, int, decltype(hasher)> faces(
      0, hasher);
    for(size_t i = 0; i < _tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        size_t i0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        size_t i1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        size_t i2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<std::size_t, 3> t = {i0, i1, i2};
        std::sort(t.begin(), t.end());
        ++faces[t];
      }
    }

    for(size_t i = 0; i < _tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        size_t i0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        size_t i1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        size_t i2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<std::size_t, 3> t = {i0, i1, i2};
        std::sort(t.begin(), t.end());
        int n = faces[t];
        if(n == 1) {
          _border_f.push_back(i0);
          _border_f.push_back(i1);
          _border_f.push_back(i2);
        }
        else if(n != 2) {
          Msg::Error("Face %d %d %d has more than 2 adjacent _tetrahedra in "
                     "polyhedron %d",
                     _vertices[i0]->getNum(), _vertices[i1]->getNum(),
                     _vertices[i2]->getNum(), getNum());
        }
      }
    }

    std::unordered_set<size_t> vertices;
    for(size_t i = 0; i < _border_f.size(); i += 3) {
      for(int j = 0; j < 3; ++j) {
        size_t i0 = _border_f[i + j];
        size_t i1 = _border_f[i + (j + 1) % 3];
        vertices.insert(i0);
        if(i0 > i1) continue;
        _border_e.push_back(i0);
        _border_e.push_back(i1);
      }
    }
    for(auto v : vertices) _border_v.push_back(v);
  }

  void computeNormals()
  {
    _normals_v.clear();
    _normals_v.resize(_vertices.size(), SVector3(0., 0., 0.));
    for(int i = 0; i < _border_f.size(); i += 3) {
      MVertex *vs[3] = {_vertices[_border_f[i]], _vertices[_border_f[i + 1]],
                        _vertices[_border_f[i + 2]]};
      SVector3 p0(vs[1]->x() - vs[0]->x(), vs[1]->y() - vs[0]->y(),
                  vs[1]->z() - vs[0]->z());
      SVector3 p1(vs[2]->x() - vs[0]->x(), vs[2]->y() - vs[0]->y(),
                  vs[2]->z() - vs[0]->z());
      SVector3 cp = crossprod(p0, p1);
      cp *= 1. / norm(cp);
      _normals_v[_border_f[i]] += cp;
      _normals_v[_border_f[i]] += cp;
      _normals_v[_border_f[i]] += cp;
    }
    for(auto &n : _normals_v) n.normalize();
  }

public:
  MPolyhedron(const std::vector<MVertex *> &tetrahedra, int num = 0,
              int part = 0)
    : MElement(num, part)
  {
    std::unordered_map<MVertex *, size_t> indices;
    size_t index;
    _tetrahedra.resize(tetrahedra.size());
    for(size_t i = 0; i < tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        auto it = indices.find(tetrahedra[i + j]);
        if(it != indices.end())
          index = it->second;
        else {
          index = _vertices.size();
          _vertices.push_back(tetrahedra[i + j]);
          indices[_vertices.back()] = index;
        }
        _tetrahedra[i + j] = index;
      }
    }

    computeBorder();
    computeNormals();
  }
  ~MPolyhedron() {}
  int getNumSimplices() const { return _tetrahedra.size() / 4; }
  std::array<size_t, 4> getSimplexIndices(int num) const
  {
    return {_tetrahedra[4 * num], _tetrahedra[4 * num + 1],
            _tetrahedra[4 * num + 2], _tetrahedra[4 * num + 3]};
  }
  MTetrahedron getSimplex(int num) const
  {
    std::array<size_t, 4> is = getSimplexIndices(num);
    return MTetrahedron(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]],
                        _vertices[is[3]]);
  }

  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return _vertices.size(); }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }
  virtual int getNumEdges() const { return _border_e.size() / 2; }
  std::array<size_t, 2> getEdgeIndices(int num) const
  {
    return {_border_e[2 * num], _border_e[2 * num + 1]};
  }
  virtual MEdge getEdge(int num) const
  {
    std::array<size_t, 2> is = getEdgeIndices(num);
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
  virtual int getNumFaces() { return _border_f.size() / 3; }
  std::array<size_t, 3> getFaceIndices(int num) const
  {
    return {_border_f[3 * num], _border_f[3 * num + 1], _border_f[3 * num + 2]};
  }
  virtual MFace getFace(int num) const
  {
    std::array<size_t, 3> is = getFaceIndices(num);
    return MFace(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]]);
  }
  virtual int getNumFacesRep(bool curved) { return getNumFaces(); }
  std::array<size_t, 3> getFaceRepIndices(bool curved, int num) const
  {
    return getFaceIndices(num);
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    std::array<size_t, 3> is = getFaceIndices(num);
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
};

#endif
