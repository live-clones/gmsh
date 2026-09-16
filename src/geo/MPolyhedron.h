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

// A polyhedron: the nodes of its faces, followed by the nodes of its
// sub-tetrahedralization that are not on the faces (interior nodes). The faces
// are lists of indices in the vertices. The sub-tetrahedralization is the
// geometry of the polyhedron: it is either given, or computed as a fan from
// the first vertex when needed (which is only correct if the polyhedron is
// star-shaped with respect to it). The reference coordinates of the polyhedron
// are its physical coordinates, and the shape functions are P1 on each
// sub-tetrahedron.
class MPolyhedron : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::size_t _numBoundary;
  std::vector<int> _polygons, _polygonStarts; // faces, as indices in _vertices
  std::vector<int> _lines, _lineFaces; // edges, and a face holding each
  mutable std::vector<int> _tetrahedra; // 4 indices in _vertices per tet
  mutable std::vector<int> _triangles; // the boundary of the tetrahedra
  mutable bool _givenTetrahedra;
  std::vector<IntPt> _intpt;

  void _computeEdges();
  void _computeTriangles() const;
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
    return (int)(_vertices.size() - _numBoundary);
  }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }

  virtual int getNumEdges() const { return (int)_lines.size() / 2; }
  std::array<int, 2> getEdgeIndices(int num) const
  {
    return {_lines[2 * num], _lines[2 * num + 1]};
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

  virtual int getNumFaces() { return getNumPolygons(); }
  virtual MFace getFace(int num) const
  {
    std::vector<MVertex *> v;
    getFaceVertices(num, v);
    return MFace(v);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.clear();
    for(int i = _polygonStarts[num]; i < _polygonStarts[num + 1]; i++)
      v.push_back(_vertices[_polygons[i]]);
  }
  virtual int getNumFacesRep(bool curved)
  {
    _ensureTetrahedra();
    return (int)_triangles.size() / 3;
  }
  std::array<int, 3> getFaceRepIndices(bool curved, int num) const
  {
    return {_triangles[3 * num], _triangles[3 * num + 1],
            _triangles[3 * num + 2]};
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);

  virtual int getType() const { return TYPE_POLYH; }
  virtual int getTypeForMSH() const { return MSH_POLYH_; }
  virtual void reverse();
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }

  // faces as a flat list of vertices plus offsets, and sub-tetrahedralization
  // as vertices of the tetrahedra (computed when needed if given empty)
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
  // keep the computed sub-tetrahedralization as if it had been given
  void createTetrahedra()
  {
    _ensureTetrahedra();
    _givenTetrahedra = true;
  }
  int getNumPolygons() const
  {
    return _polygonStarts.empty() ? 0 : (int)_polygonStarts.size() - 1;
  }
  int getPolygonStart(int i) const { return _polygonStarts[i]; }
  MVertex *getPolygonVertex(int i) const { return _vertices[_polygons[i]]; }
  int getNumTetrahedra() const
  {
    _ensureTetrahedra();
    return (int)_tetrahedra.size() / 4;
  }
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

  // geometry: reference coordinates are the physical coordinates
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
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  // P1 on the sub-tetrahedra
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
