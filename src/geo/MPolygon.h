// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYGON_H
#define MPOLYGON_H

#include "MElement.h"
#include "MTriangle.h"
#include "SVector3.h"
#include "GaussIntegration.h"

#include <array>
#include <vector>

// A polygon, with an optional sub-triangulation.
//
// What is stored:
//
// - the nodes: the boundary nodes in order (the primary vertices, _numBoundary
//   of them), followed by the nodes of the sub-triangulation that are not
//   boundary nodes (hanging or interior nodes), which are counted as face
//   vertices;
//
// - the sub-triangulation, as 3 indices in the nodes per triangle. It is the
//   geometry of the polygon: the reference coordinates are the physical
//   coordinates, the shape functions are P1 on each triangle, and point
//   location, integration, interpolation and the quality measures all go
//   through the triangles. It is either given (read from the file or set
//   through the API, in which case it is written back with the polygon), or
//   computed by ear clipping the first time it is needed (drawing, volume...)
//   and never written back: _givenTriangles tells which.
//
// What is recomputed when needed rather than stored: the normal (Newell's
// method over the boundary), the edges (consecutive boundary nodes), and the
// integration points (the rules of the triangles, in a shared buffer).
class MPolygon : public MElement {
private:
  std::vector<MVertex *> _vertices;
  mutable std::vector<int> _triangles;
  int _numBoundary;
  mutable bool _givenTriangles;

  // ear clipping, if no triangles are stored yet
  void _ensureTriangles() const;
  // the sub-triangle containing the point, or the closest one, with the
  // barycentric coordinates of the point in it and its distance to its plane
  int _findTriangle(double x, double y, double z, double bary[3],
                    double &dist) const;

public:
  MPolygon(const std::vector<MVertex *> &vertices, int num = 0, int part = 0);
  ~MPolygon() {}

  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return _vertices.size(); }
  virtual int getNumFaceVertices() const
  {
    return (int)_vertices.size() - _numBoundary;
  }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }

  virtual int getNumEdges() const { return _numBoundary; }
  std::array<int, 2> getEdgeIndices(int num) const
  {
    return {num, (num + 1) % getNumEdges()};
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

  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const
  {
    return MFace(std::vector<MVertex *>(_vertices.begin(),
                                        _vertices.begin() + _numBoundary));
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.assign(_vertices.begin(), _vertices.begin() + _numBoundary);
  }
  virtual int getNumFacesRep(bool curved) { return getNumTriangles(); }
  std::array<int, 3> getFaceRepIndices(bool curved, int num) const
  {
    return getTriangleIndices(num);
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);

  virtual int getType() const { return TYPE_POLYG; }
  virtual int getTypeForMSH() const { return MSH_POLYG_; }
  virtual void reverse();
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }

  // set the given sub-triangulation, as vertices of the triangles (the ones
  // that are not boundary nodes are appended to the nodes); if empty, the
  // polygon has no given sub-triangulation and one is computed when needed
  void setTriangles(const std::vector<MVertex *> &simplices);
  bool hasGivenTriangles() const { return _givenTriangles; }
  // keep the computed sub-triangulation as if it had been given, so that it is
  // written with the polygon
  void createTriangles()
  {
    _ensureTriangles();
    _givenTriangles = true;
  }
  int getNumTriangles() const
  {
    _ensureTriangles();
    return (int)_triangles.size() / 3;
  }
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
  // unit normal of the boundary (Newell's method: exact for planar polygons,
  // and an average for the others)
  SVector3 getNormal() const;

  // geometry: the reference coordinates are the physical coordinates, and the
  // Jacobian of the mapping is the identity (the integration weights carry the
  // areas of the triangles)
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

  // no nodal basis: the shape functions are P1 on the triangle holding the
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

  // quality: the worst of the sub-triangles
  virtual void scaledJacRange(double &jmin, double &jmax,
                              GEntity *ge = nullptr) const;
  virtual void idealJacRange(double &jmin, double &jmax, GEntity *ge = nullptr);
  virtual void signedInvCondNumRange(double &iCNMin, double &iCNMax,
                                     GEntity *ge = nullptr);
  virtual void signedInvGradErrorRange(double &minSIGE, double &maxSIGE);
};

#endif
