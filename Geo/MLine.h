// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MLINE_H_
#define _MLINE_H_

#include "MElement.h"

/*
 * MLine
 *
 *   0----------1 --> u
 *
 */
class MLine : public MElement {
 protected:
  MVertex *_v[2];
  void _getEdgeVertices(std::vector<MVertex*> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
  }
 public :
  MLine(MVertex *v0, MVertex *v1, int num=0, int part=0)
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1;
  }
  MLine(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MElement(num, part)
  {
    for(int i = 0; i < 2; i++) _v[i] = v[i];
  }
  ~MLine(){}
  virtual int getDim() const { return 1; }
  virtual int getNumVertices() const { return 2; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual double getInnerRadius(); // half-length of segment line
  virtual double getLength(); // length of segment line
  virtual void getVertexInfo(const MVertex * vertex, int &ithVertex) const
  {
    ithVertex = _v[0] == vertex ? 0 : 1;
  }
  virtual int getNumEdges(){ return 1; }
  virtual MEdge getEdge(int num){ return MEdge(_v[0], _v[1]); }
  virtual int getNumEdgesRep(){ return 1; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    _getEdgeRep(_v[0], _v[1], x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(v);
  }
  virtual int getNumFaces(){ return 0; }
  virtual MFace getFace(int num){ return MFace(); }
  virtual int getNumFacesRep(){ return 0; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n){}
  virtual int getType() const { return TYPE_LIN; }
  virtual int getTypeForMSH() const { return MSH_LIN_2; }
  virtual int getTypeForUNV() const { return 21; } // linear beam
  virtual int getTypeForVTK() const { return 3; }
  virtual const char *getStringForPOS() const { return "SL"; }
  virtual const char *getStringForBDF() const { return "CBAR"; }
  virtual const char *getStringForINP() const { return "C1D2"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
  }
  virtual const polynomialBasis* getFunctionSpace(int o=-1) const;
  virtual const JacobianBasis* getJacobianFuncSpace(int o=-1) const;
  virtual bool isInside(double u, double v, double w)
  {
    double tol = _isInsideTolerance;
    if(u < -(1. + tol) || u > (1. + tol))
      return false;
    return true;
  }
  virtual void getNode(int num, double &u, double &v, double &w)
  {
    v = w = 0.;
    switch(num) {
    case 0 : u = -1.; break;
    case 1 : u =  1.; break;
    default: u =  0.; break;
    }
  }
  virtual SPoint3 barycenterUVW()
  {
    return SPoint3(0, 0, 0);
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
};

/*
 * MLine3
 *
 *   0-----2----1
 *
 */
class MLine3 : public MLine {
 protected:
  MVertex *_vs[1];
 public :
  MLine3(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0)
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
    _vs[0]->setPolynomialOrder(2);
  }
  MLine3(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MLine(v, num, part)
  {
    _vs[0] = v[2];
    _vs[0]->setPolynomialOrder(2);
  }
  ~MLine3(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 3; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[3] = {0, 2, 1};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexINP(int num){ return getVertexUNV(num); }
  virtual int getNumEdgeVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 2; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int e[2][2] = {
      {0, 2}, {2, 1}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MLine::_getEdgeVertices(v);
    v[2] = _vs[0];
  }
  virtual int getTypeForMSH() const { return MSH_LIN_3; }
  virtual int getTypeForUNV() const { return 24; } // parabolic beam
  virtual int getTypeForVTK() const { return 21; }
  virtual const char *getStringForPOS() const { return "SL2"; }
  virtual const char *getStringForINP() const { return "C1D3"; }
  virtual void getNode(int num, double &u, double &v, double &w)
  {
    num < 2 ? MLine::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
};

/*
 * MLineN
 *
 *   0---2---...-(N-1)-1
 *
 */
class MLineN : public MLine {
 protected:
  std::vector<MVertex *> _vs;
 public :
  MLineN(MVertex *v0, MVertex *v1, const std::vector<MVertex*> &vs, int num=0, int part=0)
    : MLine(v0, v1, num, part), _vs(vs)
  {
    for(unsigned int i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  MLineN(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MLine(v[0] , v[1], num, part)
  {
    for(unsigned int i = 2; i < v.size(); i++)
      _vs.push_back(v[i]);
    for(unsigned int i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  ~MLineN(){}
  virtual int getPolynomialOrder() const { return _vs.size() + 1; }
  virtual int getNumVertices() const { return _vs.size() + 2; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual int getNumEdgeVertices() const { return _vs.size(); }
  virtual int getNumEdgesRep(){ return _vs.size() + 1; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    _getEdgeRep(getVertex((num == 0) ? 0 : num + 1),
                getVertex((num == getNumEdgesRep() - 1) ? 1 : num + 2),
                x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2 + _vs.size());
    MLine::_getEdgeVertices(v);
    for(unsigned int i = 0; i != _vs.size(); ++i) v[i+2] = _vs[i];
  }
  virtual int getTypeForMSH() const
  {
    if(_vs.size() == 2) return MSH_LIN_4;
    if(_vs.size() == 3) return MSH_LIN_5;
    if(_vs.size() == 4) return MSH_LIN_6;
    if(_vs.size() == 5) return MSH_LIN_7;
    if(_vs.size() == 6) return MSH_LIN_8;
    if(_vs.size() == 7) return MSH_LIN_9;
    if(_vs.size() == 8) return MSH_LIN_10;
    if(_vs.size() == 9) return MSH_LIN_11;
    return 0;
  }
  virtual void getNode(int num, double &u, double &v, double &w)
  {
    num < 2 ? MLine::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
};

struct compareMLinePtr {
  bool operator () (MLine *l1, MLine *l2) const
  {
    static Less_Edge le;
    return le(l1->getEdge(0), l2->getEdge(0));
  }
};

#endif
