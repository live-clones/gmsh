// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MTRIHEDRON_H
#define MTRIHEDRON_H

#include "MElement.h"

/*
 * MTrihedron
 * A MTrihedron is a plane element composed of
 * a quadrangle and two triangles.
 * It serves as an interface between two non-conforming
 * elements
 *
 *         v
 *         ^
 *         |
 *   3-----------2
 *   |'\   |     |
 *   |  '\ |     |
 *   |     +---- | --> u
 *   |      '\   |
 *   |        '\ |
 *   0-----------1
 *
 */

class MTrihedron : public MElement {
protected:
  MVertex *_v[4];
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_trihedron(num, 0)];
    v[1] = _v[edges_trihedron(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    if(num > 0) {
      v[0] = _v[faces_trihedron(num, 0)];
      v[1] = _v[faces_trihedron(num, 1)];
      v[2] = _v[faces_trihedron(num, 2)];
    }
    else {
      v[0] = _v[0];
      v[1] = _v[1];
      v[2] = _v[2];
      v[3] = _v[3];
    }
  }

public:
  MTrihedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num = 0,
             int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
  }
  MTrihedron(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MTrihedron() {}
  virtual int getDim() const { return 3; } // Can have a volume...
  virtual std::size_t getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual int getNumEdges() const { return 5; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_trihedron(num, 0)], _v[edges_trihedron(num, 1)]);
  }
  virtual int getNumEdgesRep(bool curved) { return 5; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 3; }
  virtual MFace getFace(int num) const
  {
    if(num > 0)
      return MFace(_v[faces_trihedron(num, 0)], _v[faces_trihedron(num, 1)],
                   _v[faces_trihedron(num, 2)]);
    else
      return MFace(_v[0], _v[1], _v[2], _v[3]);
  }

  virtual int getNumFacesRep(bool curved) { return 2; }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    static const int f[2][3] = {{0, 1, 3}, {1, 2, 3}};
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]),
                getVertex(f[num][2]), x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize((num == 0) ? 4 : 3);
    _getFaceVertices(num, v);
  }
  virtual int getType() const { return TYPE_TRIH; }
  virtual int getTypeForMSH() const { return MSH_TRIH_4; }

  virtual void reverse()
  {
    MVertex *tmp = _v[1];
    _v[1] = _v[3];
    _v[3] = tmp;
  }
  virtual int getVolumeSign() { return 0; };
  virtual double getVolume() { return 0; };
  virtual bool setVolumePositive() { return false; };
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    w = 0;
    switch(num) {
    case 0:
      u = -1.;
      v = -1.;
      break;
    case 1:
      u = 1.;
      v = -1.;
      break;
    case 2:
      u = 1.;
      v = 1.;
      break;
    case 3:
      u = -1.;
      v = 1.;
      break;
    default:
      u = 0.;
      v = 0.;
      break;
    }
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < -(1. + tol) || v < -(1. + tol) || u > (1. + tol) || v > (1. + tol) ||
       fabs(w) > tol)
      return false;
    return true;
  }
  static int edges_trihedron(const int edge, const int vert)
  {
    static const int e[5][2] = {
      {0, 1}, {1, 2}, {2, 3}, {3, 0}, {1, 3},
    };
    return e[edge][vert];
  }
  static int faces_trihedron(const int face, const int vert)
  {
    static const int f[3][4] = {
      {0, 1, 2, 3},
      {0, 3, 1, -1},
      {1, 3, 2, -1},
    };
    return f[face][vert];
  }

  // Return the number of nodes that this element must have with the other in
  // order to put an edge between them in the dual graph used during the
  // partitioning.
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
};

#endif
