// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPRISM_H
#define MPRISM_H

#include "MElement.h"

/*
 * MPrism
 *
 *               w
 *               ^
 *               |
 *               3
 *             ,/|`\
 *           ,/  |  `\
 *         ,/    |    `\
 *        4------+------5
 *        |      |      |
 *        |    ,/|`\    |
 *        |  ,/  |  `\  |
 *        |,/    |    `\|
 *       ,|      |      `\
 *     ,/ |      0      | `\
 *    u   |    ,/ `\    |    v
 *        |  ,/     `\  |
 *        |,/         `\|
 *        1-------------2
 *
 */
class MPrism : public MElement {
protected:
  MVertex *_v[6];
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_prism(num, 0)];
    v[1] = _v[edges_prism(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[faces_prism(num, 0)];
    v[1] = _v[faces_prism(num, 1)];
    v[2] = _v[faces_prism(num, 2)];
    if(num >= 2) v[3] = _v[faces_prism(num, 3)];
  }

public:
  MPrism(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
         MVertex *v5, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
    _v[4] = v4;
    _v[5] = v5;
  }
  MPrism(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 6; i++) _v[i] = v[i];
  }
  ~MPrism() {}
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return 6; }
  virtual double getInnerRadius();
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual int getNumEdges() const { return 9; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_prism(num, 0)], _v[edges_prism(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_prism(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 9; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 5; }
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual MFace getFace(int num) const
  {
    if(num < 2)
      return MFace(_v[faces_prism(num, 0)], _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)]);
    else
      return MFace(_v[faces_prism(num, 0)], _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)], _v[faces_prism(num, 3)]);
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize((num < 2) ? 3 : 4);
    _getFaceVertices(num, v);
  }
  virtual int getType() const { return TYPE_PRI; }
  virtual int getTypeForMSH() const { return MSH_PRI_6; }
  virtual int getTypeForUNV() const { return 112; } // solid linear wedge
  virtual int getTypeForVTK() const { return 13; }
  virtual const char *getStringForPOS() const { return "SI"; }
  virtual const char *getStringForBDF() const { return "CPENTA"; }
  virtual const char *getStringForINP() const { return "C3D6"; }
  virtual const char *getStringForKEY() const { return "_SOLID"; }
  virtual const char *getStringForRAD() const { return "/BRICK"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
    tmp = _v[3];
    _v[3] = _v[4];
    _v[4] = tmp;
  }
  virtual double gammaShapeMeasure();
  virtual int getVolumeSign();
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    switch(num) {
    case 0:
      u = 0.;
      v = 0.;
      w = -1.;
      break;
    case 1:
      u = 1.;
      v = 0.;
      w = -1.;
      break;
    case 2:
      u = 0.;
      v = 1.;
      w = -1.;
      break;
    case 3:
      u = 0.;
      v = 0.;
      w = 1.;
      break;
    case 4:
      u = 1.;
      v = 0.;
      w = 1.;
      break;
    case 5:
      u = 0.;
      v = 1.;
      w = 1.;
      break;
    default:
      u = 0.;
      v = 0.;
      w = 0.;
      break;
    }
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(1 / 3., 1 / 3., 0.); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(w > (1. + tol) || w < -(1. + tol) || u < (-tol) || v < (-tol) ||
       u > ((1. + tol) - v))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  static int edges_prism(const int edge, const int vert)
  {
    static const int e[9][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4},
                                {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    return e[edge][vert];
  }
  static int faces_prism(const int face, const int vert)
  {
    static const int f[5][4] = {
      {0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
    return f[face][vert];
  }
  static int faces2edge_prism(const int face, const int edge)
  {
    // return -iedge - 1 if edge is inverted
    //         iedge + 1 otherwise
    static const int e[5][4] = {{2, -4, -1, 0},
                                {7, 9, -8, 0},
                                {1, 5, -7, -3},
                                {3, 8, -6, -2},
                                {4, 6, -9, -5}};
    return e[face][edge];
  }
  static int faceClosureEdge2edge(const int face, const int edge)
  {
    // Warning: numbering of element edge starts here at 1.
    // - 0 means no edge (triangular face)
    // - negative means going backward
    static const int f[5][4] = {{2, -4, -1, 0},
                                {7, 9, -8, 0},
                                {1, 5, -7, -3},
                                {3, 8, -6, -2},
                                {4, 6, -9, -5}};
    return f[face][edge];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
  virtual MEdge getEdgeSolin(int num)
  {
    static const int eSolin[9][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4},
                                     {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    return MEdge(_v[eSolin[num][0]], _v[eSolin[num][1]]);
  }
  virtual MFace getFaceSolin(int num)
  {
    static const int fSolin[5][4] = {
      {0, 1, 3, 4}, {0, 2, 3, 5}, {1, 2, 4, 5}, {0, 1, 2, -1}, {3, 4, 5, -1}};
    if(num > 2) {
      return MFace(_v[fSolin[num][0]], _v[fSolin[num][1]], _v[fSolin[num][2]]);
    }
    else {
      return MFace(_v[fSolin[num][0]], _v[fSolin[num][1]],
                   _v[fSolin[num][2]], _v[fSolin[num][3]]);
    }
  }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[6] = {0, 2, 1, 3, 5, 4};
    return getVertex(map[num]);
  }
};

/*
 * MPrism15
 *
 *               3
 *             ,/|`\
 *           12  |  13
 *         ,/    |    `\
 *        4------14-----5
 *        |      8      |
 *        |      |      |
 *        |      |      |
 *        |      |      |
 *        10     |      11
 *        |      0      |
 *        |    ,/ `\    |
 *        |  ,6     `7  |
 *        |,/         `\|
 *        1------9------2
 *
 */
class MPrism15 : public MPrism {
protected:
  MVertex *_vs[9];

public:
  MPrism15(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           int num = 0, int part = 0)
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6;
    _vs[1] = v7;
    _vs[2] = v8;
    _vs[3] = v9;
    _vs[4] = v10;
    _vs[5] = v11;
    _vs[6] = v12;
    _vs[7] = v13;
    _vs[8] = v14;
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism15(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism15() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 15; }
  virtual MVertex *getVertex(int num)
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 6)
      _v[num] = v;
    else
      _vs[num - 6] = v;
  }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[15] = {0,  6, 1,  9, 2,  7, 8, 10,
                                11, 3, 12, 4, 14, 5, 13};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[15] = {0, 1, 2,  3,  4,  5,  6, 9,
                                7, 8, 10, 11, 12, 14, 13};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexINP(int num)
  {
    static const int map[15] = {0, 1,  2,  3,  4, 5,  6, 9,
                                7, 12, 14, 13, 8, 10, 11};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[15] = {0, 1,  2,  3,  4, 5,  6, 9,
                                7, 12, 14, 13, 8, 10, 11};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexKEY(int num) { return getVertexBDF(num); }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize((num < 2) ? 6 : 8);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1}, {6, 8, 7, -1}, {0, 4, 6, 2}, {2, 7, 5, 1}, {3, 5, 8, 4}};
    const int i = (num < 2) ? 3 : 4;
    v[i] = _vs[f[num][0]];
    v[i + 1] = _vs[f[num][1]];
    v[i + 2] = _vs[f[num][2]];
    if(num >= 2) v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_PRI_15; }
  virtual int getTypeForUNV() const { return 113; } // solid parabolic wedge
  virtual int getTypeForVTK() const { return 26; }
  virtual const char *getStringForBDF() const { return "CPENTA"; }
  virtual const char *getStringForINP() const { return "C3D15"; }
  virtual const char *getStringForKEY() const
  {
    return "_SOLID_P15";
  } /* not implemented yet */
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
    tmp = _v[3];
    _v[3] = _v[4];
    _v[4] = tmp;
    tmp = _vs[1];
    _vs[1] = _vs[3];
    _vs[3] = tmp;
    tmp = _vs[2];
    _vs[2] = _vs[4];
    _vs[4] = tmp;
    tmp = _vs[7];
    _vs[7] = _vs[8];
    _vs[8] = tmp;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 6 ? MPrism::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
};

/*
 * MPrism18
 *
 *               3
 *             ,/|`\
 *           12  |  13
 *         ,/    |    `\
 *        4------14-----5
 *        |      8      |
 *        |    ,/|`\    |
 *        |  15  |  16  |
 *        |,/    |    `\|
 *        10-----17-----11
 *        |      0      |
 *        |    ,/ `\    |
 *        |  ,6     `7  |
 *        |,/         `\|
 *        1------9------2
 *
 */
class MPrism18 : public MPrism {
protected:
  MVertex *_vs[12];

public:
  MPrism18(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           MVertex *v15, MVertex *v16, MVertex *v17, int num = 0, int part = 0)
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6;
    _vs[1] = v7;
    _vs[2] = v8;
    _vs[3] = v9;
    _vs[4] = v10;
    _vs[5] = v11;
    _vs[6] = v12;
    _vs[7] = v13;
    _vs[8] = v14;
    _vs[9] = v15;
    _vs[10] = v16;
    _vs[11] = v17;
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism18(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism18() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 18; }
  virtual MVertex *getVertex(int num)
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 6)
      _v[num] = v;
    else
      _vs[num - 6] = v;
  }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumFaceVertices() const { return 3; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize((num < 2) ? 6 : 9);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1}, {6, 8, 7, -1}, {0, 4, 6, 2}, {2, 7, 5, 1}, {3, 5, 8, 4}};
    const int i = (num < 2) ? 3 : 4;
    v[i] = _vs[f[num][0]];
    v[i + 1] = _vs[f[num][1]];
    v[i + 2] = _vs[f[num][2]];
    if(num >= 2) {
      v[7] = _vs[f[num][3]];
      v[8] = _vs[7 + num];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PRI_18; }
  virtual const char *getStringForPOS() const { return "SI2"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
    tmp = _v[3];
    _v[3] = _v[4];
    _v[4] = tmp;
    // edge vertices
    tmp = _vs[1];
    _vs[1] = _vs[3];
    _vs[3] = tmp;
    tmp = _vs[2];
    _vs[2] = _vs[4];
    _vs[4] = tmp;
    tmp = _vs[7];
    _vs[7] = _vs[8];
    _vs[8] = tmp;
    // quad face vertices
    tmp = _vs[10];
    _vs[10] = _vs[11];
    _vs[11] = tmp;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 6 ? MPrism::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
  virtual int getTypeForVTK() const { return 32; }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[18] = {0,  1,  2,  3, 4,  5,  6,  9,  7,
                                12, 14, 13, 8, 10, 11, 15, 17, 16};
    return getVertex(map[num]);
  }
};

/*
 * MPrismN
 */

typedef std::vector<int> IndicesReversed;

class MPrismN : public MPrism {
  static std::map<int, IndicesReversed> _order2indicesReversedPri;

protected:
  std::vector<MVertex *> _vs;
  const char _order;

public:
  MPrismN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
          MVertex *v5, const std::vector<MVertex *> &v, char order, int num = 0,
          int part = 0)
    : MPrism(v0, v1, v2, v3, v4, v5, num, part), _vs(v), _order(order)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  MPrismN(const std::vector<MVertex *> &v, char order, int num = 0,
          int part = 0)
    : MPrism(v, num, part), _order(order)
  {
    for(std::size_t i = 6; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrismN() {}
  virtual int getPolynomialOrder() const { return _order; }
  virtual std::size_t getNumVertices() const { return 6 + _vs.size(); }
  virtual MVertex *getVertex(int num)
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 6 ? _v[num] : _vs[num - 6];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 6)
      _v[num] = v;
    else
      _vs[num - 6] = v;
  }
  virtual int getNumEdgeVertices() const { return 9 * (_order - 1); }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else {
      int n = _order - 1;
      return (n - 1 + 3 * n) * n;
    }
  }
  virtual int getNumVolumeVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else {
      int n = _order - 1;
      return n * ((n - 1) * n / 2);
    }
  }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MPrism::_getEdgeVertices(num, v);
    const int n = _order - 1;
    for(int i = 0; i < n; i++) v[2 + i] = _vs[num * n + i];
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const;
  virtual int getTypeForMSH() const
  {
    switch(_order) {
    case 0: return MSH_PRI_1;
    case 1: return MSH_PRI_6;
    case 2:
      if(_vs.size() == 12) return MSH_PRI_18;
      if(_vs.size() == 9) return MSH_PRI_15;
      break;
    case 3:
      if(_vs.size() == 34) return MSH_PRI_40;
      if(_vs.size() == 18) return MSH_PRI_24;
      break;
    case 4:
      if(_vs.size() == 69) return MSH_PRI_75;
      if(_vs.size() == 27) return MSH_PRI_33;
      break;
    case 5:
      if(_vs.size() == 120) return MSH_PRI_126;
      if(_vs.size() == 36) return MSH_PRI_42;
      break;
    case 6:
      if(_vs.size() == 190) return MSH_PRI_196;
      if(_vs.size() == 45) return MSH_PRI_51;
      break;
    case 7:
      if(_vs.size() == 282) return MSH_PRI_288;
      if(_vs.size() == 54) return MSH_PRI_60;
      break;
    case 8:
      if(_vs.size() == 399) return MSH_PRI_405;
      if(_vs.size() == 63) return MSH_PRI_69;
      break;
    case 9:
      if(_vs.size() == 544) return MSH_PRI_550;
      if(_vs.size() == 72) return MSH_PRI_78;
      break;
    }
    Msg::Error("No MSH type found for P%d prism with %d nodes", _order,
               6 + _vs.size());
    return 0;
  }
  virtual const char *getStringForPOS() const
  {
    switch(_order) {
    case 0: return "SI0";
    case 1: return "SI1";
    case 2: return "SI2";
    case 3: return "SI3";
    case 4: return "SI4";
    case 5: return "SI5";
    case 6: return "SI6";
    case 7: return "SI7";
    case 8: return "SI8";
    case 9: return "SI9";
    }
    return "";
  }
  virtual void reverse();
  virtual void getNode(int num, double &u, double &v, double &w) const;
};

#endif
