// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MPRISM_H_
#define _MPRISM_H_

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
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_prism(num, 0)];
    v[1] = _v[edges_prism(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[faces_prism(num, 0)];
    v[1] = _v[faces_prism(num, 1)];
    v[2] = _v[faces_prism(num, 2)];
    if(num >= 2) v[3] = _v[faces_prism(num, 3)];
  }
 public :
  MPrism(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
         MVertex *v5, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; 
  }
  MPrism(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 6; i++) _v[i] = v[i];
  }
  ~MPrism(){}
  virtual int getDim() const { return 3; }
  virtual int getNumVertices() const { return 6; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[6] = {0, 2, 1, 3, 5, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 9; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_prism(num, 0)], _v[edges_prism(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 9; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 5; }
  virtual void getFaceInfo(const MFace & face, int &ithFace, int &sign, int &rot) const; 
  virtual MFace getFace(int num)
  {
    if(num < 2)
      return MFace(_v[faces_prism(num, 0)],
                   _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)]);
    else
      return MFace(_v[faces_prism(num, 0)],
                   _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)],
                   _v[faces_prism(num, 3)]);
  }
  virtual int getNumFacesRep(){ return 8; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[8][3] = {
      {0, 2, 1},
      {3, 4, 5},
      {0, 1, 4}, {0, 4, 3},
      {0, 3, 5}, {0, 5, 2},
      {1, 2, 5}, {1, 5, 4}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
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
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
  }
  virtual const polynomialBasis* getFunctionSpace(int o=-1) const;
  virtual int getVolumeSign();
/*  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = (1. - u - v) * (1. - w) * 0.5;
    s[1] =       u      * (1. - w) * 0.5;
    s[2] =           v  * (1. - w) * 0.5;
    s[3] = (1. - u - v) * (1. + w) * 0.5;
    s[4] =       u      * (1. + w) * 0.5;
    s[5] =           v  * (1. + w) * 0.5;
  }*/
/*  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    printf("here\n");
    s[0][0] = -0.5 * (1. - w)    ;
    s[0][1] = -0.5 * (1. - w)    ;
    s[0][2] = -0.5 * (1. - u - v);
    s[1][0] =  0.5 * (1. - w)    ;
    s[1][1] =  0.                ;
    s[1][2] = -0.5 * u           ;
    s[2][0] =  0.                ;
    s[2][1] =  0.5 * (1. - w)    ;
    s[2][2] = -0.5 * v           ;
    s[3][0] = -0.5 * (1. + w)    ;
    s[3][1] = -0.5 * (1. + w)    ;
    s[3][2] =  0.5 * (1. - u - v);
    s[4][0] =  0.5 * (1. + w)    ;
    s[4][1] =  0.                ;
    s[4][2] =  0.5 * u           ;
    s[5][0] =  0.                ;
    s[5][1] =  0.5 * (1. + w)    ;
    s[5][2] =  0.5 * v           ;
  }*/
  virtual bool isInside(double u, double v, double w)
  {
    double tol = _isInsideTolerance;
    if(w > (1. + tol) || w < -(1. + tol) || u < (1. + tol)
       || v < (1. + tol) || u > ((1. + tol) - v))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
 private:
  int edges_prism(const int edge, const int vert) const
  {
    static const int e[9][2] = {
      {0, 1},
      {0, 2},
      {0, 3},
      {1, 2},
      {1, 4},
      {2, 5},
      {3, 4},
      {3, 5},
      {4, 5}
    };
    return e[edge][vert];
  }
  int faces_prism(const int face, const int vert) const
  {
    static const int f[5][4] = {
      {0, 2, 1, -1},
      {3, 4, 5, -1},
      {0, 1, 4,  3},
      {0, 3, 5,  2},
      {1, 2, 5,  4}
    };
    return f[face][vert];
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
 public :
  MPrism15(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           int num=0, int part=0) 
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6; _vs[1] = v7; _vs[2] = v8; _vs[3] = v9; _vs[4] = v10; 
    _vs[5] = v11; _vs[6] = v12; _vs[7] = v13; _vs[8] = v14;
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism15(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism15(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 15; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[15] = {0, 6, 1, 9, 2, 7, 8, 10, 11, 3, 12, 4, 14, 5, 13};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[15] = {0, 1, 2, 3, 4, 5, 6, 9, 7, 8, 10, 11, 12, 14, 13};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[15] = {0, 2, 1, 3, 5, 4, 7, 9, 6, 13, 14, 12, 8, 11, 10};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[18][2] = {
      {0, 6}, {6, 1},
      {0, 7}, {7, 2},
      {0, 8}, {8, 3},
      {1, 9}, {9, 2},
      {1, 10}, {10, 4},
      {2, 11}, {11, 5},
      {3, 12}, {12, 4},
      {3, 13}, {13, 5},
      {4, 14}, {14, 5}
    };
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 26; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[26][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 8}, {1, 10, 6}, {4, 12, 10}, {3, 8, 12}, {6, 10, 12}, {6, 12, 8},
      {0, 8, 7}, {3, 13, 8}, {5, 11, 13}, {2, 7, 11}, {7, 8, 13}, {7, 13, 11},
      {1, 9, 10}, {2, 11, 9}, {5, 14, 11}, {4, 10, 14}, {9, 11, 14}, {9, 14, 10}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 2) ? 6 : 8);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1},
      {6, 8, 7, -1},
      {0, 4, 6,  2},
      {2, 7, 5,  1},
      {3, 5, 8,  4}
    };
    const int i = (num < 2) ? 3 : 4;
    v[i  ] = _vs[f[num][0]];
    v[i+1] = _vs[f[num][1]];
    v[i+2] = _vs[f[num][2]];
    if (num >= 2) v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_PRI_15; }
  virtual int getTypeForUNV() const { return 113; } // solid parabolic wedge
  virtual const char *getStringForBDF() const { return "CPENTA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[4]; _vs[4] = tmp;
    tmp = _vs[7]; _vs[7] = _vs[8]; _vs[8] = tmp;
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
 public :
  MPrism18(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           MVertex *v15, MVertex *v16, MVertex *v17, int num=0, int part=0) 
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6; _vs[1] = v7; _vs[2] = v8; _vs[3] = v9; _vs[4] = v10; 
    _vs[5] = v11; _vs[6] = v12; _vs[7] = v13; _vs[8] = v14; _vs[9] = v15; 
    _vs[10] = v16; _vs[11] = v17; 
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism18(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism18(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 18; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumFaceVertices() const { return 3; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[18][2] = {
      {0, 6}, {6, 1},
      {0, 7}, {7, 2},
      {0, 8}, {8, 3},
      {1, 9}, {9, 2},
      {1, 10}, {10, 4},
      {2, 11}, {11, 5},
      {3, 12}, {12, 4},
      {3, 13}, {13, 5},
      {4, 14}, {14, 5}
    };
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 32; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[32][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 15}, {0, 15, 8}, {1, 10, 15}, {1, 15, 6},  
      {4, 12, 15}, {4, 15, 10}, {3, 8, 15}, {3, 15, 12},  
      {0, 8, 16}, {0, 16, 7}, {3, 13, 16}, {3, 16, 8},  
      {5, 11, 16}, {5, 16, 13}, {2, 7, 16}, {2, 16, 11},  
      {1, 9, 17}, {1, 17, 10}, {2, 11, 17}, {2, 17, 9},  
      {5, 14, 17}, {5, 17, 11}, {4, 10, 17}, {4, 17, 14}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 2) ? 6 : 9);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1},
      {6, 8, 7, -1},
      {0, 4, 6,  2},
      {2, 7, 5,  1},
      {3, 5, 8,  4}
    };
    const int i = (num < 2) ? 3 : 4;
    v[i  ] = _vs[f[num][0]];
    v[i+1] = _vs[f[num][1]];
    v[i+2] = _vs[f[num][2]];
    if (num >= 2) {
      v[7] = _vs[f[num][3]];
      v[8] = _vs[7+num];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PRI_18; }
  virtual const char *getStringForPOS() const { return "SI2"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    // edge vertices
    tmp = _vs[1]; _vs[1] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[4]; _vs[4] = tmp;
    tmp = _vs[7]; _vs[7] = _vs[8]; _vs[8] = tmp;
    // quad face vertices
    tmp = _vs[10]; _vs[10] = _vs[11]; _vs[11] = tmp;
  }
};

#endif
