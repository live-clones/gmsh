// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MPYRAMID_H_
#define _MPYRAMID_H_

#include "MElement.h"

/*
 * MPyramid
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,/      |  '.  \
 *     ,/       .' w |   \
 *   ,/         |  ^ |    \
 *  0----------.'--|-3    `. 
 *   `\        |   |  `\    \
 *     `\     .'   +----`\ - \ -> v
 *       `\   |    `\     `\  \
 *         `\.'      `\     `\`
 *            1----------------2
 *                      `\
 *                         u
 *
 */
class MPyramid : public MElement {
 protected:
  MVertex *_v[5];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_pyramid(num, 0)];
    v[1] = _v[edges_pyramid(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    if(num < 4) {
      v[0] = _v[faces_pyramid(num, 0)];
      v[1] = _v[faces_pyramid(num, 1)];
      v[2] = _v[faces_pyramid(num, 2)];
    }
    else {
      v[0] = _v[0];
      v[1] = _v[3];
      v[2] = _v[2];
      v[3] = _v[1];
    }
  }
 public :
  MPyramid(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3; _v[4] = v4;
  }
  MPyramid(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 5; i++) _v[i] = v[i];
  }
  ~MPyramid(){}
  virtual int getDim() const { return 3; }
  virtual int getNumVertices() const { return 5; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[5] = {0, 3, 2, 1, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 8; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_pyramid(num, 0)], _v[edges_pyramid(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    if(num < 4)
      return MFace(_v[faces_pyramid(num, 0)],
                   _v[faces_pyramid(num, 1)],
                   _v[faces_pyramid(num, 2)]);
    else
      return MFace(_v[0], _v[3], _v[2], _v[1]);
  }
  virtual int getNumFacesRep(){ return 6; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[6][3] = {
      {0, 1, 4},
      {3, 0, 4},
      {1, 2, 4},
      {2, 3, 4},
      {0, 3, 2}, {0, 2, 1}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 3 : 4);
    _getFaceVertices(num, v);
  }
  virtual int getType() const { return TYPE_PYR; }
  virtual int getTypeForMSH() const { return MSH_PYR_5; }
  virtual int getTypeForVTK() const { return 14; }
  virtual const char *getStringForPOS() const { return "SY"; }
  virtual const char *getStringForBDF() const { return "CPYRAM"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    double r = (w != 1.) ? (u * v * w / (1. - w)) : 0.;
    s[0] = 0.25 * ((1. - u) * (1. - v) - w + r);
    s[1] = 0.25 * ((1. + u) * (1. - v) - w - r);
    s[2] = 0.25 * ((1. + u) * (1. + v) - w + r);
    s[3] = 0.25 * ((1. - u) * (1. + v) - w - r);
    s[4] = w;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    if(w == 1.) {
      s[0][0] = -0.25 ; 
      s[0][1] = -0.25 ;
      s[0][2] = -0.25 ; 
      s[1][0] =  0.25 ; 
      s[1][1] = -0.25 ;
      s[1][2] = -0.25 ; 
      s[2][0] =  0.25 ; 
      s[2][1] =  0.25 ;
      s[2][2] = -0.25 ; 
      s[3][0] = -0.25 ; 
      s[3][1] =  0.25 ;
      s[3][2] = -0.25 ; 
    }
    else{
      s[0][0] = 0.25 * ( -(1. - v) + v * w / (1. - w)) ;
      s[0][1] = 0.25 * ( -(1. - u) + u * w / (1. - w)) ;
      s[0][2] = 0.25 * ( -1.     + u * v / (1. - w) + u * v * w / (1. - w) / (1. - w)) ; 
      s[1][0] = 0.25 * (  (1. - v) - v * w / (1. - w)) ;
      s[1][1] = 0.25 * ( -(1. + u) - u * w / (1. - w)) ;
      s[1][2] = 0.25 * ( -1.     - u * v / (1. - w) - u * v * w / (1. - w) / (1. - w)) ; 
      s[2][0] = 0.25 * (  (1. + v) + v * w / (1. - w)) ;
      s[2][1] = 0.25 * (  (1. + u) + u * w / (1. - w)) ;
      s[2][2] = 0.25 * ( -1.     + u * v / (1. - w) + u * v * w / (1. - w) / (1. - w)) ; 
      s[3][0] = 0.25 * ( -(1. + v) - v * w / (1. - w)) ;
      s[3][1] = 0.25 * (  (1. - u) - u * w / (1. - w)) ;
      s[3][2] = 0.25 * ( -1.     - u * v / (1. - w) - u * v * w / (1. - w) / (1. - w)) ; 
    }
    s[4][0] = 0.; 
    s[4][1] = 0.;
    s[4][2] = 1.;
  }
  virtual bool isInside(double u, double v, double w)
  {
    double tol = _isInsideTolerance;
    if(u < (w - (1. + tol)) || u > ((1. + tol) - w) || v < (w - (1. + tol)) ||
       v > ((1. + tol) - w) || w < (-tol) || w > (1. + tol))
      return false;
    return true;
  }
 private:
  int edges_pyramid(const int edge, const int vert) const
  {
    static const int e[8][2] = {
      {0, 1},
      {0, 3},
      {0, 4},
      {1, 2},
      {1, 4},
      {2, 3},
      {2, 4},
      {3, 4}
    };
    return e[edge][vert];
  }
  int faces_pyramid(const int face, const int vert) const
  {
    // only triangular faces
    static const int f[4][3] = {
      {0, 1, 4},
      {3, 0, 4},
      {1, 2, 4},
      {2, 3, 4}
    };
    return f[face][vert];
  }
};

/*
 * MPyramid13
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,7      |  12  \
 *     ,/       .'   |   \
 *   ,/         9    |    11
 *  0--------6-.'----3    `. 
 *   `\        |      `\    \
 *     `5     .'        10   \ 
 *       `\   |           `\  \
 *         `\.'             `\`
 *            1--------8-------2
 *                        
 */
class MPyramid13 : public MPyramid {
 protected:
  MVertex *_vs[8];
 public :
  MPyramid13(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
             MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
             MVertex *v10, MVertex *v11, MVertex *v12, int num=0, int part=0) 
    : MPyramid(v0, v1, v2, v3, v4, num, part)
  {
    _vs[0] = v5; _vs[1] = v6; _vs[2] = v7; _vs[3] = v8; _vs[4] = v9; 
    _vs[5] = v10; _vs[6] = v11; _vs[7] = v12;
    for(int i = 0; i < 8; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPyramid13(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 8; i++) _vs[i] = v[5 + i];
    for(int i = 0; i < 8; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPyramid13(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 13; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[13] = {0, 3, 2, 1, 4, 6, 10, 8, 5, 7, 12, 11, 9};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 8; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPyramid::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 22; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[22][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 5}, {3, 10, 6}, {2, 8, 10}, {1, 5, 8}, {5, 6, 10}, {5, 10, 8}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 6 : 8);
    MPyramid::_getFaceVertices(num, v);
    static const int f[4][3] = {
      {0, 4, 2},
      {1, 2, 7},
      {3, 6, 4},
      {5, 7, 6}
    };
    if(num < 4) {
      v[3] = _vs[f[num][0]];
      v[4] = _vs[f[num][1]];
      v[5] = _vs[f[num][2]];
    }
    else {
      v[4] = _vs[1];
      v[5] = _vs[5];
      v[6] = _vs[3];
      v[7] = _vs[0];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PYR_13; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

/*
 * MPyramid14
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,7      |  12  \
 *     ,/       .'   |   \
 *   ,/         9    |    11
 *  0--------6-.'----3    `. 
 *   `\        |      `\    \
 *     `5     .' 13     10   \ 
 *       `\   |           `\  \
 *         `\.'             `\`
 *            1--------8-------2
 *
 */
class MPyramid14 : public MPyramid {
 protected:
  MVertex *_vs[9];
 public :
  MPyramid14(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
             MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
             MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, 
             int num=0, int part=0) 
    : MPyramid(v0, v1, v2, v3, v4, num, part)
  {
    _vs[0] = v5; _vs[1] = v6; _vs[2] = v7; _vs[3] = v8; _vs[4] = v9; 
    _vs[5] = v10; _vs[6] = v11; _vs[7] = v12; _vs[8] = v13; 
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);   
  }
  MPyramid14(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[5 + i];
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);   
  }
  ~MPyramid14(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 14; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices() const { return 8; }
  virtual int getNumFaceVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPyramid::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 24; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[24][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 13}, {0, 13, 5}, {3, 10, 13}, {3, 13, 6}, 
      {2, 8, 13}, {2, 13, 10}, {1, 5, 13}, {1, 13, 8}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 6 : 9);
    MPyramid::_getFaceVertices(num, v);
    static const int f[4][3] = {
      {0, 4, 2},
      {1, 2, 7},
      {3, 6, 4},
      {5, 7, 6}
    };
    if(num < 4) {
      v[3] = _vs[f[num][0]];
      v[4] = _vs[f[num][1]];
      v[5] = _vs[f[num][2]];
    }
    else {
      v[4] = _vs[1];
      v[5] = _vs[5];
      v[6] = _vs[3];
      v[7] = _vs[0];
      v[8] = _vs[8];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PYR_14; }
  virtual const char *getStringForPOS() const { return "SY2"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

#endif
