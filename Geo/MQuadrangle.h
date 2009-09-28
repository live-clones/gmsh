// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MQUADRANGLE_H_
#define _MQUADRANGLE_H_

#include "MElement.h"

/*
 * MQuadrangle
 *
 *         v
 *         ^
 *         |
 *   3-----------2
 *   |     |     |
 *   |     |     |
 *   |     +---- | --> u
 *   |           |
 *   |           |
 *   0-----------1 
 *
 */
class MQuadrangle : public MElement {
 protected:
  MVertex *_v[4];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_quad(num, 0)];
    v[1] = _v[edges_quad(num, 1)];
  }
  void _getFaceVertices(std::vector<MVertex*> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
    v[2] = _v[2];
    v[3] = _v[3];
  }
 public :
  MQuadrangle(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  MQuadrangle(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MQuadrangle(){}
  virtual int getDim(){ return 2; }
  virtual int getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[4] = {0, 3, 2, 1};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[4] = {0, 1, 3, 2};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 4; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_quad(num, 0)], _v[edges_quad(num, 1)]);
  }
  virtual void getEdgeInfo (const MEdge & edge, int &ithEdge, int &sign) const {
    for (ithEdge=0;ithEdge<4;ithEdge++){
      const MVertex *v0 = _v[edges_quad(ithEdge, 0)];
      const MVertex *v1 = _v[edges_quad(ithEdge, 1)];
      if (v0 == edge.getVertex(0) && v1 == edge.getVertex(1)){
	sign = 1; return;
      }
      if (v1 == edge.getVertex(0) && v0 == edge.getVertex(1)){
	sign = -1; return;
      }
    }
    throw;
  }
  virtual int getNumEdgesRep(){ return 4; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num){ return MFace(_v[0], _v[1], _v[2], _v[3]); }
  virtual int getNumFacesRep(){ return 2; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[2][3] = {
      {0, 1, 2}, {0, 2, 3}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(4);
    _getFaceVertices(v);
  }
  virtual int getType() const { return TYPE_QUA; }
  virtual int getTypeForMSH() const { return MSH_QUA_4; }
  virtual int getTypeForUNV() const { return 94; } // thin shell linear quadrilateral
  virtual int getTypeForVTK() const { return 9; }
  virtual const char *getStringForPOS() const { return "SQ"; }
  virtual const char *getStringForBDF() const { return "CQUAD4"; }
  virtual const char *getStringForDIFF() const { return "ElmB4n2D"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = (1. - u) * (1. - v) * 0.25;
    s[1] = (1. + u) * (1. - v) * 0.25;
    s[2] = (1. + u) * (1. + v) * 0.25;
    s[3] = (1. - u) * (1. + v) * 0.25;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    s[0][0] = -0.25 * (1. - v); s[0][1] = -0.25 * (1. - u); s[0][2] = 0.;
    s[1][0] =  0.25 * (1. - v); s[1][1] = -0.25 * (1. + u); s[1][2] = 0.;
    s[2][0] =  0.25 * (1. + v); s[2][1] =  0.25 * (1. + u); s[2][2] = 0.;
    s[3][0] = -0.25 * (1. + v); s[3][1] =  0.25 * (1. - u); s[3][2] = 0.;
  }
  virtual bool isInside(double u, double v, double w)
  {
    double tol = _isInsideTolerance;
    if(u < -(1. + tol) || v < -(1. + tol) || u > (1. + tol) || v > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
 private:
  int edges_quad(const int edge, const int vert) const
  {
    static const int e[4][2] = {
      {0, 1},
      {1, 2},
      {2, 3},
      {3, 0}
    };
    return e[edge][vert];
  }
};

/*
 * MQuadrangle8
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7           5
 *   |           |
 *   |           |
 *   0-----4-----1 
 *
 */
class MQuadrangle8 : public MQuadrangle {
 protected:
  MVertex *_vs[4];
 public :
  MQuadrangle8(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
               MVertex *v5, MVertex *v6, MVertex *v7, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7;
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle8(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 4; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle8(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[8] = {0, 4, 1, 5, 2, 6, 3, 7};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[8] = {0, 3, 2, 1, 7, 6, 5, 4};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {0, 1, 3, 2, 4, 7, 5, 6};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MQuadrangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 6; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[6][3] = {
      {0, 4, 7}, {1, 5, 4}, {2, 6, 5}, {3, 7, 6}, {4, 5, 6}, {4, 6, 7}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(8);
    MQuadrangle::_getFaceVertices(v);
    v[4] = _vs[0];
    v[5] = _vs[1];
    v[6] = _vs[2];
    v[7] = _vs[3];
  }
  virtual int getTypeForMSH() const { return MSH_QUA_8; }
  virtual int getTypeForUNV() const { return 95; } // shell parabolic quadrilateral
  //virtual int getTypeForVTK() const { return 23; }
  virtual const char *getStringForBDF() const { return "CQUAD8"; }
  virtual const char *getStringForDIFF() const { return "ElmB8n2D"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

/*
 * MQuadrangle9
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7     8     5
 *   |           |
 *   |           |
 *   0-----4-----1 
 *
 */
class MQuadrangle9 : public MQuadrangle {
 protected:
  MVertex *_vs[5];
 public :
  MQuadrangle9(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
               MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7; _vs[4] = v8;
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle9(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 5; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle9(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 9; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[9] = {0, 2, 8, 6, 1, 5, 7, 3, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumFaceVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MQuadrangle::getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 8; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[8][4] = {
      {0, 4, 8}, {0, 8, 7}, {1, 5, 8}, {1, 8, 4}, 
      {2, 6, 8}, {2, 8, 5}, {3, 7, 8}, {3, 8, 6}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(9);
    MQuadrangle::_getFaceVertices(v);
    v[4] = _vs[0];
    v[5] = _vs[1];
    v[6] = _vs[2];
    v[7] = _vs[3];
    v[8] = _vs[4];
  }
  virtual int getTypeForMSH() const { return MSH_QUA_9; }
  virtual const char *getStringForPOS() const { return "SQ2"; }
  virtual const char *getStringForDIFF() const { return "ElmB9n2D"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

#endif
