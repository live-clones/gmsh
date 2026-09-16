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

// A polygon: its boundary nodes in order, followed by the nodes of its
// sub-triangulation that are not boundary nodes (hanging or interior nodes).
// The sub-triangulation is the geometry of the polygon: it is either given, or
// computed by ear clipping when needed. The reference coordinates of the
// polygon are its physical coordinates, and the shape functions are P1 on each
// sub-triangle.
class MPolygon : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::size_t _numBoundary;
  mutable std::vector<int> _triangles; // 3 indices in _vertices per triangle
  mutable bool _givenTriangles;
  SVector3 _normal;
  std::vector<IntPt> _intpt;

  void _computeNormal();
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
    return (int)(_vertices.size() - _numBoundary);
  }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }

  virtual int getNumEdges() const { return (int)_numBoundary; }
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

  // sub-triangulation, as vertices of the triangles; if given empty, it is
  // computed when needed
  void setTriangles(const std::vector<MVertex *> &simplices);
  bool hasGivenTriangles() const { return _givenTriangles; }
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
  const SVector3 &getNormal() const { return _normal; }

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

  // P1 on the sub-triangles
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
