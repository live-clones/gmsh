// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYHEDRON_H
#define MPOLYHEDRON_H

#include "MElement.h"
#include "MTetrahedron.h"
#include "GaussIntegration.h"

#include <array>
#include <vector>

// A polyhedron, given by its faces, with an optional sub-tetrahedralization.
//
// What is stored:
//
// - the nodes: the nodes of the faces, each once (the primary vertices,
//   _numBoundary of them), followed by the nodes of the sub-tetrahedralization
//   that are not on the faces (interior nodes), which are counted as volume
//   vertices;
//
// - the faces and the tetrahedra, as indices in the nodes, in the single
//   array _data laid out as
//
//     [offset of each face in the face nodes, _numFaces + 1 entries]
//     [nodes of the faces, face after face]              <- _faceIndices()
//     [4 nodes per tetrahedron]                           <- from _tetOffset
//
//   The tetrahedra are the geometry of the polyhedron: the reference
//   coordinates are the physical coordinates, the shape functions are P1 on
//   each tetrahedron, and point location, integration, interpolation and the
//   quality measures all go through them. They are either given (read from
//   the file or set through the API, in which case they are written back with
//   the polyhedron), or computed the first time they are needed as a fan from
//   the first node (correct only if the polyhedron is star-shaped with respect
//   to it) and never written back: _givenTetrahedra tells which. The faces are
//   pure topology once tetrahedra exist (they need not be planar).
//
// What is recomputed rather than stored: the triangles that draw the faces
// (fans from the first node of each face), the normal of an edge (that of the
// first face holding it), the integration points (the rules of the
// tetrahedra, in a shared buffer), and the edges, which are cached in _edges
// the first time they are asked for (drawing, the API, plugins), as pairs of
// node indices with each edge once whatever the orientation of the faces.
class MPolyhedron : public MElement {
private:
  std::vector<MVertex *> _vertices;
  mutable std::vector<int> _data; // mutable: the computed tetrahedra
  mutable std::vector<int> _edges;
  int _numBoundary, _numFaces, _tetOffset;
  mutable bool _givenTetrahedra;

  const int *_faceIndices() const { return &_data[_numFaces + 1]; }
  // build the edge cache, or the fan tetrahedra, if not there yet
  void _ensureEdges() const;
  void _ensureTetrahedra() const;
  int _findTetrahedron(double x, double y, double z, double bary[4]) const;

public:
  MPolyhedron(const std::vector<MVertex *> &vertices, int num = 0,
              int part = 0);
  ~MPolyhedron() {}

  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return _vertices.size(); }
  virtual int getNumVolumeVertices() const
  {
    return (int)_vertices.size() - _numBoundary;
  }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }

  virtual int getNumEdges() const
  {
    _ensureEdges();
    return (int)_edges.size() / 2;
  }
  std::array<int, 2> getEdgeIndices(int num) const
  {
    _ensureEdges();
    return {_edges[2 * num], _edges[2 * num + 1]};
  }
  virtual MEdge getEdge(int num) const
  {
    std::array<int, 2> is = getEdgeIndices(num);
    return MEdge(_vertices[is[0]], _vertices[is[1]]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    std::array<int, 2> is = getEdgeIndices(num);
    v = {_vertices[is[0]], _vertices[is[1]]};
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  std::array<int, 2> getEdgeRepIndices(bool curved, int num) const
  {
    return getEdgeIndices(num);
  }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);

  virtual int getNumFaces() { return _numFaces; }
  virtual MFace getFace(int num) const
  {
    std::vector<MVertex *> v;
    getFaceVertices(num, v);
    return MFace(v);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.clear();
    const int *f = _faceIndices();
    for(int i = _data[num]; i < _data[num + 1]; i++)
      v.push_back(_vertices[f[i]]);
  }
  // the faces are drawn as fans of triangles from their first node
  virtual int getNumFacesRep(bool curved);
  std::array<int, 3> getFaceRepIndices(bool curved, int num) const;
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);

  virtual int getType() const { return TYPE_POLYH; }
  virtual int getTypeForMSH() const { return MSH_POLYH_; }
  virtual void reverse();
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }

  // set the faces, as a flat list of vertices plus the offset of each face in
  // it (numFaces + 1 entries), and the given sub-tetrahedralization, as
  // vertices of the tetrahedra (the ones that are not on the faces are
  // appended to the nodes); if the tetrahedra are empty, the polyhedron has
  // no given sub-tetrahedralization and one is computed when needed
  void setPolygonsAndTetrahedra(const std::vector<MVertex *> &borderVertices,
                                const std::vector<int> &borderOffset,
                                const std::vector<MVertex *> &simplicesVertices)
  {
    setPolygons(borderVertices, borderOffset);
    setTetrahedra(simplicesVertices);
  }
  void setPolygons(const std::vector<MVertex *> &borderVertices,
                   const std::vector<int> &borderOffset);
  void setTetrahedra(const std::vector<MVertex *> &simplicesVertices);
  bool hasGivenTetrahedra() const { return _givenTetrahedra; }
  // keep the computed sub-tetrahedralization as if it had been given, so that
  // it is written with the polyhedron
  void createTetrahedra()
  {
    _ensureTetrahedra();
    _givenTetrahedra = true;
  }
  int getNumPolygons() const { return _numFaces; }
  int getPolygonStart(int i) const { return _data[i]; }
  MVertex *getPolygonVertex(int i) const
  {
    return _vertices[_faceIndices()[i]];
  }
  int getNumTetrahedra() const
  {
    _ensureTetrahedra();
    return ((int)_data.size() - _tetOffset) / 4;
  }
  std::array<int, 4> getTetrahedronIndices(int num) const
  {
    const int *t = &_data[_tetOffset + 4 * num];
    return {t[0], t[1], t[2], t[3]};
  }
  MTetrahedron getTetrahedron(int num) const
  {
    std::array<int, 4> is = getTetrahedronIndices(num);
    return MTetrahedron(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]],
                        _vertices[is[3]]);
  }

  // geometry: the reference coordinates are the physical coordinates, and the
  // Jacobian of the mapping is the identity (the integration weights carry the
  // volumes of the tetrahedra)
  virtual double getVolume();
  virtual void pnt(double u, double v, double w, SPoint3 &p) const
  {
    p = SPoint3(u, v, w);
  }
  virtual void pnt(double u, double v, double w, double *p) const
  {
    p[0] = u;
    p[1] = v;
    p[2] = w;
  }
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const
  {
    for(int i = 0; i < 3; i++) uvw[i] = xyz[i];
  }
  virtual double getJacobian(double u, double v, double w,
                             double jac[3][3]) const;
  using MElement::isInside;
  virtual bool isInside(double u, double v, double w, double tol) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  // no nodal basis: the shape functions are P1 on the tetrahedron holding the
  // point (or the closest one), and zero on the other nodes
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const
  {
    return nullptr;
  }
  virtual const JacobianBasis *getJacobianFuncSpace(int orderElement = -1) const
  {
    return nullptr;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order = -1) const;
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order = -1) const;
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order = -1) const;

  // quality: the worst of the sub-tetrahedra
  virtual void scaledJacRange(double &jmin, double &jmax,
                              GEntity *ge = nullptr) const;
  virtual void idealJacRange(double &jmin, double &jmax, GEntity *ge = nullptr);
  virtual void signedInvCondNumRange(double &iCNMin, double &iCNMax,
                                     GEntity *ge = nullptr);
  virtual void signedInvGradErrorRange(double &minSIGE, double &maxSIGE);
};

#endif
