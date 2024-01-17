// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MHEXAHEDRON_H
#define MHEXAHEDRON_H

#include "MElement.h"

/*
 * MHexahedron
 *
 *          v
 *   3----------2
 *   |\     ^   |\
 *   | \    |   | \
 *   |  \   |   |  \
 *   |   7------+---6
 *   |   |  +-- |-- | -> u
 *   0---+---\--1   |
 *    \  |    \  \  |
 *     \ |     \  \ |
 *      \|      w  \|
 *       4----------5
 *
 */
class MHexahedron : public MElement {
protected:
  MVertex *_v[8];
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_hexa(num, 0)];
    v[1] = _v[edges_hexa(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[faces_hexa(num, 0)];
    v[1] = _v[faces_hexa(num, 1)];
    v[2] = _v[faces_hexa(num, 2)];
    v[3] = _v[faces_hexa(num, 3)];
  }

public:
  MHexahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
              MVertex *v5, MVertex *v6, MVertex *v7, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
    _v[4] = v4;
    _v[5] = v5;
    _v[6] = v6;
    _v[7] = v7;
  }
  MHexahedron(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 8; i++) _v[i] = v[i];
  }
  ~MHexahedron() {}
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {2, 3, 7, 6, 0, 1, 5, 4};
    return getVertex(map[num]);
  }
  virtual int getNumEdges() const { return 12; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_hexa(num, 0)], _v[edges_hexa(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_hexa(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 12; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 6; }
  virtual MFace getFace(int num) const
  {
    return MFace(_v[faces_hexa(num, 0)], _v[faces_hexa(num, 1)],
                 _v[faces_hexa(num, 2)], _v[faces_hexa(num, 3)]);
  }
  virtual double getInnerRadius();
  virtual double angleShapeMeasure();
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(4);
    _getFaceVertices(num, v);
  }
  virtual int getType() const { return TYPE_HEX; }
  virtual int getTypeForMSH() const { return MSH_HEX_8; }
  virtual int getTypeForUNV() const { return 115; } // solid linear brick
  virtual int getTypeForVTK() const { return 12; }
  virtual const char *getStringForPOS() const { return "SH"; }
  virtual const char *getStringForBDF() const { return "CHEXA"; }
  virtual const char *getStringForDIFF() const { return "ElmB8n3D"; }
  virtual const char *getStringForINP() const { return "C3D8"; }
  virtual const char *getStringForKEY() const { return "_SOLID"; }
  virtual const char *getStringForRAD() const { return "/BRICK"; }
  virtual const char *getStringForTOCHNOG() const { return "-hex8"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[2];
    _v[2] = tmp;
    tmp = _v[4];
    _v[4] = _v[6];
    _v[6] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    switch(num) {
    case 0:
      u = -1.;
      v = -1.;
      w = -1.;
      break;
    case 1:
      u = 1.;
      v = -1.;
      w = -1.;
      break;
    case 2:
      u = 1.;
      v = 1.;
      w = -1.;
      break;
    case 3:
      u = -1.;
      v = 1.;
      w = -1.;
      break;
    case 4:
      u = -1.;
      v = -1.;
      w = 1.;
      break;
    case 5:
      u = 1.;
      v = -1.;
      w = 1.;
      break;
    case 6:
      u = 1.;
      v = 1.;
      w = 1.;
      break;
    case 7:
      u = -1.;
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
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < -(1. + tol) || v < -(1. + tol) || w < -(1. + tol) ||
       u > (1. + tol) || v > (1. + tol) || w > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  static int edges_hexa(const int edge, const int vert)
  {
    static const int e[12][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                                 {1, 5}, {2, 3}, {2, 6}, {3, 7},
                                 {4, 5}, {4, 7}, {5, 6}, {6, 7}};
    return e[edge][vert];
  }
  static int faces_hexa(const int face, const int vert)
  {
    static const int f[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                                {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
    return f[face][vert];
  }
  static int faces2edge_hexa(const int face, const int edge)
  {
    // return -iedge - 1 if edge is inverted
    //         iedge + 1 otherwise
    static const int e[6][4] = {{2, -6, -4, -1}, {1, 5, -9, -3},
                                {3, 10, -8, -2}, {4, 7, -11, -5},
                                {6, 8, -12, -7}, {9, 11, 12, -10}};
    return e[face][edge];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
  virtual MEdge getEdgeSolin(int num)
  {
    static const int eSolin[12][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                                      {1, 5}, {3, 2}, {2, 6}, {3, 7},
                                      {4, 5}, {4, 7}, {5, 6}, {7, 6}};
    return MEdge(_v[eSolin[num][0]], _v[eSolin[num][1]]);
  }
  virtual MFace getFaceSolin(int num)
  {
    static const int fSolin[6][4] = {{0, 1, 3, 2}, {0, 1, 4, 5}, {0, 3, 4, 7},
                                     {1, 2, 5, 6}, {3, 2, 7, 6}, {4, 5, 7, 6}};
    return MFace(_v[fSolin[num][0]], _v[fSolin[num][1]],
                 _v[fSolin[num][2]], _v[fSolin[num][3]]);
  }
  virtual MVertex *getVertexNEU(int num)
  {
    static const int map[8] = {0, 1, 3, 2, 4, 5, 7, 6};
    return getVertex(map[num]);
  }
};

/*
 * MHexahedron20
 *
 *   3----13----2
 *   |\         |\
 *   | 15       | 14
 *   9  \       11 \
 *   |   7----19+---6
 *   |   |      |   |
 *   0---+-8----1   |
 *    \  17      \  18
 *    10 |        12|
 *      \|         \|
 *       4----16----5
 *
 */
class MHexahedron20 : public MHexahedron {
protected:
  MVertex *_vs[12];

public:
  MHexahedron20(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13,
                MVertex *v14, MVertex *v15, MVertex *v16, MVertex *v17,
                MVertex *v18, MVertex *v19, int num = 0, int part = 0)
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8;
    _vs[1] = v9;
    _vs[2] = v10;
    _vs[3] = v11;
    _vs[4] = v12;
    _vs[5] = v13;
    _vs[6] = v14;
    _vs[7] = v15;
    _vs[8] = v16;
    _vs[9] = v17;
    _vs[10] = v18;
    _vs[11] = v19;
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron20(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron20() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 20; }
  virtual MVertex *getVertex(int num)
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 8)
      _v[num] = v;
    else
      _vs[num - 8] = v;
  }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[20] = {0,  8,  1, 11, 2, 13, 3, 9,  10, 12,
                                14, 15, 4, 16, 5, 18, 6, 19, 7,  17};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                13, 9, 10, 12, 14, 15, 16, 18, 19, 17};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexINP(int num)
  {
    static const int map[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                13, 9, 16, 18, 19, 17, 10, 12, 14, 15};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexKEY(int num)
  {
    static const int map[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                13, 9, 16, 18, 19, 17, 10, 12, 14, 15};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexRAD(int num)
  {
    static const int map[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                13, 9, 16, 18, 19, 17, 10, 12, 14, 15};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[20] = {2,  3,  7,  6,  0,  1,  5, 4,  9,  18,
                                12, 19, 14, 11, 15, 13, 8, 16, 17, 10};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                13, 9, 16, 18, 19, 17, 10, 12, 14, 15};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(8);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {{1, 5, 3, 0},  {0, 4, 8, 2},  {2, 9, 7, 1},
                                {3, 6, 10, 4}, {5, 7, 11, 6}, {8, 10, 11, 9}};
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_20; }
  virtual int getTypeForUNV() const { return 116; } // solid parabolic brick
  virtual int getTypeForVTK() const { return 25; }
  virtual const char *getStringForBDF() const { return "CHEXA"; }
  virtual const char *getStringForINP() const { return "C3D20"; }
  virtual const char *getStringForKEY() const { return "_SOLID_H20"; }
  virtual const char *getStringForRAD() const { return "/BRIC20"; }
  virtual const char *getStringForDIFF() const { return "ElmB20n3D"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[2];
    _v[2] = tmp;
    tmp = _v[4];
    _v[4] = _v[6];
    _v[6] = tmp;
    MVertex *old[12];
    for(int i = 0; i < 12; i++) old[i] = _vs[i];
    _vs[0] = old[3];
    _vs[3] = old[0];
    _vs[1] = old[5];
    _vs[5] = old[1];
    _vs[2] = old[6];
    _vs[6] = old[2];
    _vs[8] = old[10];
    _vs[10] = old[8];
    _vs[9] = old[11];
    _vs[11] = old[9];
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 8 ? MHexahedron::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
};

/*
 * MHexahedron27
 *
 *   3----13----2
 *   |\         |\
 *   |15    24  | 14
 *   9  \ 20    11 \
 *   |   7----19+---6
 *   |22 |  26  | 23|
 *   0---+-8----1   |
 *    \ 17    25 \  18
 *    10 |  21    12|
 *      \|         \|
 *       4----16----5
 *
 */
class MHexahedron27 : public MHexahedron {
protected:
  MVertex *_vs[19];

public:
  MHexahedron27(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13,
                MVertex *v14, MVertex *v15, MVertex *v16, MVertex *v17,
                MVertex *v18, MVertex *v19, MVertex *v20, MVertex *v21,
                MVertex *v22, MVertex *v23, MVertex *v24, MVertex *v25,
                MVertex *v26, int num = 0, int part = 0)
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8;
    _vs[1] = v9;
    _vs[2] = v10;
    _vs[3] = v11;
    _vs[4] = v12;
    _vs[5] = v13;
    _vs[6] = v14;
    _vs[7] = v15;
    _vs[8] = v16;
    _vs[9] = v17;
    _vs[10] = v18;
    _vs[11] = v19;
    _vs[12] = v20;
    _vs[13] = v21;
    _vs[14] = v22;
    _vs[15] = v23;
    _vs[16] = v24;
    _vs[17] = v25;
    _vs[18] = v26;
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron27(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 19; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron27() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 27; }
  virtual MVertex *getVertex(int num)
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 8)
      _v[num] = v;
    else
      _vs[num - 8] = v;
  }
  virtual MVertex *getVertexINP(int num)
  {
    static const int map[27] = {0,  1,  2,  3,  4,  5,  6,  7,  8,
                                11, 13, 9,  16, 18, 19, 17, 10, 12,
                                14, 15, 26, 20, 25, 21, 23, 24, 22};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexKEY(int num)
  {
    static const int map[27] = {0,  1,  2,  3,  4,  5,  6,  7,  8,
                                11, 13, 9,  16, 18, 19, 17, 10, 12,
                                14, 15, 26, 20, 25, 21, 23, 24, 22};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[27] = {6,  8,  26, 24, 0,  2,  20, 18, 7,
                                15, 3,  17, 5,  25, 23, 21, 1,  9,
                                11, 19, 16, 4,  12, 14, 22, 10, 13};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[27] = {0,  1,  2,  3,  4,  5,  6,  7,  8,
                                11, 13, 9,  16, 18, 19, 17, 10, 12,
                                14, 15, 22, 23, 21, 24, 20, 25, 26};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumFaceVertices() const { return 6; }
  virtual int getNumVolumeVertices() const { return 1; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(9);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {{1, 5, 3, 0},  {0, 4, 8, 2},  {2, 9, 7, 1},
                                {3, 6, 10, 4}, {5, 7, 11, 6}, {8, 10, 11, 9}};
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
    v[8] = _vs[12 + num];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_27; }
  virtual int getTypeForVTK() const { return 29; }
  virtual const char *getStringForPOS() const { return "SH2"; }
  virtual const char *getStringForDIFF() const { return "ElmB27n3D"; }
  virtual const char *getStringForINP() const { return "C3D27"; }
  virtual const char *getStringForKEY() const { return "_SOLID_H27"; }
  virtual const char *getStringForRAD() const { return "/BRIC20"; }
  virtual const char *getStringForTOCHNOG() const { return "-hex27"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[2];
    _v[2] = tmp;
    tmp = _v[4];
    _v[4] = _v[6];
    _v[6] = tmp;
    MVertex *old[19];
    for(int i = 0; i < 19; i++) old[i] = _vs[i];
    // edge vertices
    _vs[0] = old[3];
    _vs[3] = old[0];
    _vs[1] = old[5];
    _vs[5] = old[1];
    _vs[2] = old[6];
    _vs[6] = old[2];
    _vs[8] = old[10];
    _vs[10] = old[8];
    _vs[9] = old[11];
    _vs[11] = old[9];
    // face vertices
    _vs[13] = old[15];
    _vs[15] = old[13];
    _vs[14] = old[16];
    _vs[16] = old[14];
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 8 ? MHexahedron::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
};

/*
 * MHexahedronN
 *
 *   3----13----2
 *   |\         |\
 *   |15    24  | 14
 *   9  \ 20    11 \
 *   |   7----19+---6
 *   |22 |  26  | 23|
 *   0---+-8----1   |
 *    \ 17    25 \  18
 *    10 |  21    12|
 *      \|         \|
 *       4----16----5
 *
 *    N = 0RDER - 1
 *    8 := 8 --> 8 + N
 *    9 := 8 + N + 1 --> 8 +  2 * N
 *    :
 *   19 := 8 + 11 * N + 1 --> 8 +  12 * N
 *   20 := 8 + 12 * N + 1 --> 8 +  12 * N + N^2
 *   21 := 8 + 12 * N + N^2 --> 8 +  12 * N + 2 * N^2
 *    :
 *   25 := 8 + 12 * N + 5 * N^2 + 1 --> 8 +  12 * N + 6 * N^2
 *   26 := 8 + 12 * N + 6 * N^2 + 1 --> 8 +  12 * N + 6 * N^2 + N^3
 *
 */

typedef std::vector<int> IndicesReversed;
// typedef std::vector<int> IndicesHighOrderFace;
// typedef std::pair<std::pair<int,int>, std::pair<int,int> >
// TupleHighOrderFace;

class MHexahedronN : public MHexahedron {
  static std::map<int, IndicesReversed> _order2indicesReversedHex;
  //  static std::map<TupleHighOrderFace, IndicesHighOrderFace>
  //  _tuple2indicesHighOrderFace;

protected:
  const char _order;
  std::vector<MVertex *> _vs;

public:
  MHexahedronN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
               MVertex *v5, MVertex *v6, MVertex *v7,
               const std::vector<MVertex *> &v, char order, int num = 0,
               int part = 0)
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part), _order(order),
      _vs(v)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  MHexahedronN(const std::vector<MVertex *> &v, char order, int num = 0,
               int part = 0)
    : MHexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], num, part),
      _order(order)
  {
    for(std::size_t i = 8; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  ~MHexahedronN() {}
  virtual int getPolynomialOrder() const { return (int)_order; }
  virtual std::size_t getNumVertices() const { return 8 + _vs.size(); }
  virtual MVertex *getVertex(int num)
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 8 ? _v[num] : _vs[num - 8];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 8)
      _v[num] = v;
    else
      _vs[num - 8] = v;
  }
  virtual int getNumEdgeVertices() const { return 12 * (_order - 1); }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return 6 * (_order - 1) * (_order - 1);
  }
  virtual int getNumVolumeVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return (_order - 1) * (_order - 1) * (_order - 1);
  }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MHexahedron::_getEdgeVertices(num, v);
    for(int i = 0; i < _order - 1; i++) v[2 + i] = _vs[(_order - 1) * num + i];
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    if(getIsAssimilatedSerendipity()) { v.resize(4 * _order); }
    else {
      v.resize((_order + 1) * (_order + 1));
    }

    MHexahedron::_getFaceVertices(num, v);
    int count = 3;

    int n = _order - 1;
    for(int i = 0; i < 4; i++) {
      if(faces2edge_hexa(num, i) > 0) {
        int edge_num = faces2edge_hexa(num, i) - 1;
        for(int j = 0; j < n; j++) v[++count] = _vs[n * edge_num + j];
      }
      else {
        int edge_num = -faces2edge_hexa(num, i) - 1;
        for(int j = n - 1; j >= 0; j--) v[++count] = _vs[n * edge_num + j];
      }
    }

    if((int)v.size() > count + 1) {
      int start = 12 * n + num * n * n;
      for(int i = 0; i < n * n; i++) { v[++count] = _vs[start + i]; }
    }
  }
  virtual int getTypeForMSH() const
  {
    // (p+1)^3
    if(_order == 1 && _vs.size() + 8 == 8) return MSH_HEX_8;
    if(_order == 2 && _vs.size() + 8 == 27) return MSH_HEX_27;
    if(_order == 3 && _vs.size() + 8 == 64) return MSH_HEX_64;
    if(_order == 4 && _vs.size() + 8 == 125) return MSH_HEX_125;
    if(_order == 5 && _vs.size() + 8 == 216) return MSH_HEX_216;
    if(_order == 6 && _vs.size() + 8 == 343) return MSH_HEX_343;
    if(_order == 7 && _vs.size() + 8 == 512) return MSH_HEX_512;
    if(_order == 8 && _vs.size() + 8 == 729) return MSH_HEX_729;
    if(_order == 9 && _vs.size() + 8 == 1000) return MSH_HEX_1000;

    if(_order == 2 && _vs.size() + 8 == 20) return MSH_HEX_20;
    if(_order == 3 && _vs.size() + 8 == 32) return MSH_HEX_32;
    if(_order == 4 && _vs.size() + 8 == 44) return MSH_HEX_44;
    if(_order == 5 && _vs.size() + 8 == 56) return MSH_HEX_56;
    if(_order == 6 && _vs.size() + 8 == 68) return MSH_HEX_68;
    if(_order == 7 && _vs.size() + 8 == 80) return MSH_HEX_80;
    if(_order == 8 && _vs.size() + 8 == 92) return MSH_HEX_92;
    if(_order == 9 && _vs.size() + 8 == 104) return MSH_HEX_104;

    Msg::Error("No MSH type found for P%d hexahedron with %d nodes", _order,
               8 + _vs.size());
    return 0;
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void reverse();
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 8 ? MHexahedron::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
};

#endif
