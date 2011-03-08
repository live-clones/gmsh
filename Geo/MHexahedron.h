// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MHEXAHEDRON_H_
#define _MHEXAHEDRON_H_

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
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_hexa(num, 0)];
    v[1] = _v[edges_hexa(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[faces_hexa(num, 0)];
    v[1] = _v[faces_hexa(num, 1)];
    v[2] = _v[faces_hexa(num, 2)];
    v[3] = _v[faces_hexa(num, 3)];
  }
 public :
  MHexahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
              MVertex *v5, MVertex *v6, MVertex *v7, int num=0, int part=0)
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; _v[6] = v6; _v[7] = v7;
  }
  MHexahedron(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MElement(num, part)
  {
    for(int i = 0; i < 8; i++) _v[i] = v[i];
  }
  ~MHexahedron(){}
  virtual int getDim() const { return 3; }
  virtual int getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual const polynomialBasis* getFunctionSpace(int o=-1) const;
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[8] = {0, 3, 2, 1, 4, 7, 6, 5};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {2, 3, 7, 6, 0, 1, 5, 4};
    return getVertex(map[num]);
  }
  virtual int getNumEdges(){ return 12; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_hexa(num, 0)], _v[edges_hexa(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 12; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 6; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[faces_hexa(num, 0)],
                 _v[faces_hexa(num, 1)],
                 _v[faces_hexa(num, 2)],
                 _v[faces_hexa(num, 3)]);
  }
  virtual void getFaceInfo (const MFace & face, int &ithFace, int &sign, int &rot)const;
  virtual int getNumFacesRep(){ return 12; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[12][3] = {
      {0, 3, 2}, {0, 2, 1},
      {0, 1, 5}, {0, 5, 4},
      {0, 4, 7}, {0, 7, 3},
      {1, 2, 6}, {1, 6, 5},
      {2, 3, 7}, {2, 7, 6},
      {4, 5, 6}, {4, 6, 7}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
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
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o)
  {
    s[0] = (1. - u) * (1. - v) * (1. - w) * 0.125;
    s[1] = (1. + u) * (1. - v) * (1. - w) * 0.125;
    s[2] = (1. + u) * (1. + v) * (1. - w) * 0.125;
    s[3] = (1. - u) * (1. + v) * (1. - w) * 0.125;
    s[4] = (1. - u) * (1. - v) * (1. + w) * 0.125;
    s[5] = (1. + u) * (1. - v) * (1. + w) * 0.125;
    s[6] = (1. + u) * (1. + v) * (1. + w) * 0.125;
    s[7] = (1. - u) * (1. + v) * (1. + w) * 0.125;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
  {
    s[0][0] = -0.125 * (1. - v) * (1. - w);
    s[0][1] = -0.125 * (1. - u) * (1. - w);
    s[0][2] = -0.125 * (1. - u) * (1. - v);
    s[1][0] =  0.125 * (1. - v) * (1. - w);
    s[1][1] = -0.125 * (1. + u) * (1. - w);
    s[1][2] = -0.125 * (1. + u) * (1. - v);
    s[2][0] =  0.125 * (1. + v) * (1. - w);
    s[2][1] =  0.125 * (1. + u) * (1. - w);
    s[2][2] = -0.125 * (1. + u) * (1. + v);
    s[3][0] = -0.125 * (1. + v) * (1. - w);
    s[3][1] =  0.125 * (1. - u) * (1. - w);
    s[3][2] = -0.125 * (1. - u) * (1. + v);
    s[4][0] = -0.125 * (1. - v) * (1. + w);
    s[4][1] = -0.125 * (1. - u) * (1. + w);
    s[4][2] =  0.125 * (1. - u) * (1. - v);
    s[5][0] =  0.125 * (1. - v) * (1. + w);
    s[5][1] = -0.125 * (1. + u) * (1. + w);
    s[5][2] =  0.125 * (1. + u) * (1. - v);
    s[6][0] =  0.125 * (1. + v) * (1. + w);
    s[6][1] =  0.125 * (1. + u) * (1. + w);
    s[6][2] =  0.125 * (1. + u) * (1. + v);
    s[7][0] = -0.125 * (1. + v) * (1. + w);
    s[7][1] =  0.125 * (1. - u) * (1. + w);
    s[7][2] =  0.125 * (1. - u) * (1. + v);
  }
  virtual bool isInside(double u, double v, double w)
  {
    double tol = _isInsideTolerance;
    if(u < -(1. + tol) || v < -(1. + tol) || w < -(1. + tol) ||
       u > (1. + tol) || v > (1. + tol) || w > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
 private:
  int edges_hexa(const int edge, const int vert) const
  {
    static const int e[12][2] = {
      {0, 1},
      {0, 3},
      {0, 4},
      {1, 2},
      {1, 5},
      {2, 3},
      {2, 6},
      {3, 7},
      {4, 5},
      {4, 7},
      {5, 6},
      {6, 7}
    };
    return e[edge][vert];
  }
  int faces_hexa(const int face, const int vert) const
  {
    static const int f[6][4] = {
      {0, 3, 2, 1},
      {0, 1, 5, 4},
      {0, 4, 7, 3},
      {1, 2, 6, 5},
      {2, 3, 7, 6},
      {4, 5, 6, 7}
    };
    return f[face][vert];
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
 public :
  MHexahedron20(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
                MVertex *v15, MVertex *v16, MVertex *v17, MVertex *v18, MVertex *v19,
                int num=0, int part=0)
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8; _vs[1] = v9; _vs[2] = v10; _vs[3] = v11; _vs[4] = v12;
    _vs[5] = v13; _vs[6] = v14; _vs[7] = v15; _vs[8] = v16; _vs[9] = v17;
    _vs[10] = v18; _vs[11] = v19;
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron20(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron20(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 20; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[20] = {0, 8, 1, 11, 2, 13, 3, 9, 10, 12,
                                14, 15, 4, 16, 5, 18, 6, 19, 7, 17};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 13,
                                9, 10, 12, 14, 15, 16, 18, 19, 17};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[20] = {0, 3, 2, 1, 4, 7, 6, 5, 9, 13, 11,
                                8, 17, 19, 18, 16, 10, 15, 14, 12};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[20] = {2, 3, 7, 6, 0, 1, 5, 4, 9, 18, 12,
                                19, 14, 11, 15, 13, 8, 16, 17, 10};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumEdgesRep(){ return 24; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int e[24][2] = {
      {0, 8}, {8, 1},
      {0, 9}, {9, 3},
      {0, 10}, {10, 4},
      {1, 11}, {11, 2},
      {1, 12}, {12, 5},
      {2, 13}, {13, 3},
      {2, 14}, {14, 6},
      {3, 15}, {15, 7},
      {4, 16}, {16, 5},
      {4, 17}, {17, 7},
      {5, 18}, {18, 6},
      {6, 19}, {19, 7}
    };
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 36; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[36][3] = {
      {0, 9, 8}, {3, 13, 9}, {2, 11, 13}, {1, 8, 11}, {8, 9, 13}, {8, 13, 11},
      {0, 8, 10}, {1, 12, 8}, {5, 16, 12}, {4, 10, 16}, {8, 12, 16}, {8, 16, 10},
      {0, 10, 9}, {4, 17, 10}, {7, 15, 17}, {3, 9, 7}, {9, 10, 17}, {9, 17, 15},
      {1, 11, 12}, {2, 14, 11}, {6, 18, 14}, {5, 12, 18}, {11, 14, 18}, {11, 18, 12},
      {2, 13, 14}, {3, 15, 13}, {7, 19, 15}, {6, 14, 19}, {13, 15, 19}, {13, 19, 14},
      {4, 16, 17}, {5, 18, 16}, {6, 19, 18}, {7, 17, 19}, {16, 18, 19}, {16, 19, 17}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(8);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {
      {1,  5,  3, 0},
      {0,  4,  8, 2},
      {2,  9,  7, 1},
      {3,  6, 10, 4},
      {5,  7, 11, 6},
      {8, 10, 11, 9}
    };
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_20; }
  virtual int getTypeForUNV() const { return 116; } // solid parabolic brick
  //virtual int getTypeForVTK() const { return 25; }
  virtual const char *getStringForBDF() const { return "CHEXA"; }
  virtual const char *getStringForDIFF() const { return "ElmB20n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[12];
    for(int i = 0; i < 12; i++) old[i] = _vs[i];
    _vs[0] = old[3]; _vs[3] = old[0];
    _vs[1] = old[5]; _vs[5] = old[1];
    _vs[2] = old[6]; _vs[6] = old[2];
    _vs[8] = old[10]; _vs[10] = old[8];
    _vs[9] = old[11]; _vs[11] = old[9];
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
 public :
  MHexahedron27(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
                MVertex *v15, MVertex *v16, MVertex *v17, MVertex *v18, MVertex *v19,
                MVertex *v20, MVertex *v21, MVertex *v22, MVertex *v23, MVertex *v24,
                MVertex *v25, MVertex *v26, int num=0, int part=0)
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8; _vs[1] = v9; _vs[2] = v10; _vs[3] = v11; _vs[4] = v12;
    _vs[5] = v13; _vs[6] = v14; _vs[7] = v15; _vs[8] = v16; _vs[9] = v17;
    _vs[10] = v18; _vs[11] = v19; _vs[12] = v20; _vs[13] = v21; _vs[14] = v22;
    _vs[15] = v23; _vs[16] = v24; _vs[17] = v25; _vs[18] = v26;
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron27(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 19; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron27(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 27; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[27] = {6, 8, 26, 24, 0, 2, 20, 18, 7, 15, 3, 17, 5, 25,
                                23, 21, 1, 9, 11, 19, 16, 4, 12, 14, 22, 10, 13};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumFaceVertices() const { return 6; }
  virtual int getNumVolumeVertices() const { 
    return 8;
  }
  virtual int getNumEdgesRep(){ return 24; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int e[24][2] = {
      {0, 8}, {8, 1},
      {0, 9}, {9, 3},
      {0, 10}, {10, 4},
      {1, 11}, {11, 2},
      {1, 12}, {12, 5},
      {2, 13}, {13, 3},
      {2, 14}, {14, 6},
      {3, 15}, {15, 7},
      {4, 16}, {16, 5},
      {4, 17}, {17, 7},
      {5, 18}, {18, 6},
      {6, 19}, {19, 7}
    };
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 48; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[48][3] = {
      {0, 9, 20}, {0, 20, 8}, {3, 13, 20}, {3, 20, 9},
      {2, 11, 20}, {2, 20, 13}, {1, 8, 20}, {1, 20, 11},
      {0, 8, 21}, {0, 21, 10}, {1, 12, 21}, {1, 21, 8},
      {5, 16, 21}, {5, 21, 12}, {4, 10, 21}, {4, 21, 16},
      {0, 10, 22}, {0, 22, 9}, {4, 17, 22}, {4, 22, 10},
      {7, 15, 22}, {7, 22, 17}, {3, 9, 22}, {3, 22, 15},
      {1, 11, 23}, {1, 23, 12}, {2, 14, 23}, {2, 23, 11},
      {6, 18, 23}, {6, 23, 14}, {5, 12, 23}, {5, 23, 18},
      {2, 13, 24}, {2, 24, 14}, {3, 15, 24}, {3, 24, 13},
      {7, 19, 24}, {7, 24, 15}, {6, 14, 24}, {6, 24, 19},
      {4, 16, 25}, {4, 25, 17}, {5, 18, 25}, {5, 25, 16},
      {6, 19, 25}, {6, 25, 18}, {7, 17, 25}, {7, 25, 19}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(9);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {
      {1,  5,  3, 0},
      {0,  4,  8, 2},
      {2,  9,  7, 1},
      {3,  6, 10, 4},
      {5,  7, 11, 6},
      {8, 10, 11, 9}
    };
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
    v[8] = _vs[12+num];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_27; }
  virtual const char *getStringForPOS() const { return "SH2"; }
  virtual const char *getStringForDIFF() const { return "ElmB27n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[19];
    for(int i = 0; i < 19; i++) old[i] = _vs[i];
    // edge vertices
    _vs[0] = old[3]; _vs[3] = old[0];
    _vs[1] = old[5]; _vs[5] = old[1];
    _vs[2] = old[6]; _vs[6] = old[2];
    _vs[8] = old[10]; _vs[10] = old[8];
    _vs[9] = old[11]; _vs[11] = old[9];
    // face vertices
    _vs[13] = old[15]; _vs[15] = old[13];
    _vs[14] = old[16]; _vs[16] = old[14];
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


class MHexahedronN : public MHexahedron {
 protected:
  const char _order;
  std::vector<MVertex*> _vs;
 public :
 MHexahedronN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
	      MVertex *v4, MVertex *v5, MVertex *v6, MVertex *v7,
	      const std::vector<MVertex*> &v, char order, int num=0, int part=0)
   : MHexahedron(v0,v1,v2,v3,v4,v5,v6,v7, num, part), _order(order), _vs(v)
    {
      for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
    }
 MHexahedronN(const std::vector<MVertex*> &v, char order, int num=0, int part=0)
   :  MHexahedron(v[0], v[1], v[2], v[3],v[4], v[5], v[6], v[7], num, part), _order(order)
  {
    for(unsigned int i = 8; i < v.size(); i++) _vs.push_back(v[i]);
    for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
  }
  
  ~MHexahedronN(){}
  virtual int getPolynomialOrder() const { return (int)_order; }
  virtual int getNumVertices() const { return 8 + _vs.size(); }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual MVertex *getVertexDIFF(int num)
  {
    throw;
  }
  virtual int getNumEdgeVertices() const { return 12 * (_order - 1); }
  virtual int getNumFaceVertices() const { return 6 * (_order - 1)*(_order - 1); }
  virtual int getNumVolumeVertices() const { 
    switch(getTypeForMSH()){
    case MSH_HEX_27 : 
    case MSH_HEX_64 : 
    case MSH_HEX_125 : 
    case MSH_HEX_216 : 
    case MSH_HEX_343 : 
    case MSH_HEX_512 : 
    case MSH_HEX_729 : 
    case MSH_HEX_1000 : 
      return (_order - 1)*(_order - 1)*(_order - 1); 
    default:
      return 0;
    }
  }
  virtual int getNumEdgesRep();
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(_order+1);
    MHexahedron::_getEdgeVertices(num, v);
    for (int i=0;i<_order-1;i++) v[2+i] = _vs[(_order-1)*num+i];
  }
  //virtual int getNumFacesRep();
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((_order+1)*(_order+1));
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {
      {0, 3, 2, 1},
      {0, 1, 5, 4},
      {0, 4, 7, 3},
      {1, 2, 6, 5},
      {2, 3, 7, 6},
      {4, 5, 6, 7}
    };
    int count = 4;
    for (int i=0;i<4;i++){
      for (int j=0;j<_order-1;j++) v[count++] = _vs[(_order-1)*f[num][i]+j];      
    }
    for (int i=0;i<(_order+1)*(_order+1);i++){
      int N = _order - 1;
      int start = 8 + 12 * N + num * (_order-1)*(_order-1);
      v[count++] = _vs[start + i];
    }
  }
  virtual int getTypeForMSH() const
  {
    // (p+1)^3
    if(_order == 3 && _vs.size() + 8 == 64 ) return MSH_HEX_64;
    if(_order == 4 && _vs.size() + 8 == 125) return MSH_HEX_125;
    if(_order == 5 && _vs.size() + 8 == 216) return MSH_HEX_216;
    if(_order == 6 && _vs.size() + 8 == 343) return MSH_HEX_343;
    if(_order == 7 && _vs.size() + 8 == 512) return MSH_HEX_512;
    if(_order == 8 && _vs.size() + 8 == 729) return MSH_HEX_729;
    if(_order == 9 && _vs.size() + 8 == 1000) return MSH_HEX_1000;
    if(_order == 3 && _vs.size() + 8 == 56 ) return MSH_HEX_56;
    if(_order == 4 && _vs.size() + 8 == 98) return MSH_HEX_98;
    if(_order == 5 && _vs.size() + 8 == 152) return MSH_HEX_152;
    if(_order == 6 && _vs.size() + 8 == 222) return MSH_HEX_222;
    if(_order == 7 && _vs.size() + 8 == 296) return MSH_HEX_296;
    if(_order == 8 && _vs.size() + 8 == 386) return MSH_HEX_386;
    if(_order == 9 && _vs.size() + 8 == 488) return MSH_HEX_488;
    return 0;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o){
    MElement::getShapeFunctions (u,v,w,s,o);
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
  {
    MElement::getGradShapeFunctions (u,v,w,s,o);
  }

  virtual void revert()
  {
    Msg::Error("not done yet reverse hexN");
  }
};

#endif
