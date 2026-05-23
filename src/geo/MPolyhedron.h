// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYHEDRON_H
#define MPOLYHEDRON_H

#include "MElement.h"
#include "MTetrahedron.h"

#include <unordered_set>

class MPolyhedron : public MElement {
private:
  std::vector<MVertex *> _tetrahedra, _border_f, _border_e, _border_v;

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
        MVertex *v0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        MVertex *v1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        MVertex *v2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<std::size_t, 3> t = {v0->getNum(), v1->getNum(),
                                        v2->getNum()};
        std::sort(t.begin(), t.end());
        ++faces[t];
      }
    }

    for(size_t i = 0; i < _tetrahedra.size(); i += 4) {
      for(int j = 0; j < 4; ++j) {
        MVertex *v0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
        MVertex *v1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
        MVertex *v2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
        std::array<std::size_t, 3> t = {v0->getNum(), v1->getNum(),
                                        v2->getNum()};
        std::sort(t.begin(), t.end());
        int n = faces[t];
        if(n == 1) {
          _border_f.push_back(v0);
          _border_f.push_back(v1);
          _border_f.push_back(v2);
        }
        else if(n != 2) {
          Msg::Error("Face %d %d %d has more than 2 adjacent _tetrahedra in "
                     "polyhedron %d",
                     v0->getNum(), v1->getNum(), v2->getNum(), getNum());
        }
      }
    }

    std::unordered_set<MVertex *> vertices;
    for(size_t i = 0; i < _border_f.size(); i += 3) {
      for(int j = 0; j < 3; ++j) {
        MVertex *v0 = _border_f[i + j];
        MVertex *v1 = _border_f[i + (j + 1) % 3];
        vertices.insert(v0);
        if(v0->getNum() > v1->getNum()) continue;
        _border_e.push_back(v0);
        _border_e.push_back(v1);
      }
    }
    for(auto v : vertices) _border_v.push_back(v);
  }

public:
  MPolyhedron(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part), _tetrahedra(v)
  {
    computeBorder();
  }
  ~MPolyhedron() {}
  int getNumSimplices() { return _tetrahedra.size() / 4; }
  MTetrahedron getSimplex(int num) const
  {
    return MTetrahedron(_tetrahedra[4 * num], _tetrahedra[4 * num + 1],
                        _tetrahedra[4 * num + 2], _tetrahedra[4 * num + 3]);
  }
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return _border_v.size(); }
  virtual MVertex *getVertex(int num) { return _border_v[num]; }
  virtual const MVertex *getVertex(int num) const { return _border_v[num]; }
  virtual int getNumEdges() const { return _border_e.size() / 2; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_border_e[2 * num], _border_e[2 * num + 1]);
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
    Msg::Info("%g %g %g -> %g %g %g", x[0], y[0], z[0], x[1], y[1], z[1]);
  }
  virtual int getNumFaces() { return _border_f.size() / 3; }
  virtual MFace getFace(int num) const
  {
    return MFace(_border_f[3 * num], _border_f[3 * num + 1],
                 _border_f[3 * num + 2]);
  }
  virtual int getNumFacesRep(bool curved) { return getNumFaces(); }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_border_f[3 * num], _border_f[3 * num + 1],
                _border_f[3 * num + 2], x, y, z, n);
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
