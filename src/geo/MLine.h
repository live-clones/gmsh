// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MLINE_H
#define MLINE_H

#include "MElement.h"

/*
 * MLine
 *
 *         v
 *         ^
 *         |
 *         |
 *   0-----+-----1 --> u
 *
 */
class MLine : public MElement {
protected:
  MVertex *_v[2];
  void _getEdgeVertices(std::vector<MVertex *> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
  }

public:
  MLine(MVertex *v0, MVertex *v1, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
  }
  MLine(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 2; i++) _v[i] = v[i];
  }
  ~MLine() {}
  virtual int getDim() const { return 1; }
  virtual std::size_t getNumVertices() const { return 2; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual double getInnerRadius(); // half-length of segment line
  virtual double getLength(); // length of segment line
  virtual double getVolume();
  virtual void getVertexInfo(const MVertex *vertex, int &ithVertex) const
  {
    ithVertex = _v[0] == vertex ? 0 : 1;
  }
  virtual int getNumEdges() const { return 1; }
  virtual MEdge getEdge(int num) const { return MEdge(_v[0], _v[1]); }
  virtual int getNumEdgesRep(bool curved) { return 1; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getEdgeRep(_v[0], _v[1], x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(v);
  }
  virtual int getNumFaces() { return 0; }
  virtual MFace getFace(int num) const { return MFace(); }
  virtual int getNumFacesRep(bool curved) { return 0; }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
  }
  virtual int getType() const { return TYPE_LIN; }
  virtual int getTypeForMSH() const { return MSH_LIN_2; }
  virtual int getTypeForUNV() const { return 21; } // linear beam
  virtual int getTypeForVTK() const { return 3; }
  virtual const char *getStringForPOS() const { return "SL"; }
  virtual const char *getStringForBDF() const { return "CBAR"; }
  virtual const char *getStringForINP() const { return "T3D2" /*"C1D2"*/; }
  virtual const char *getStringForKEY() const { return "_BEAM"; }
  virtual const char *getStringForRAD() const { return "/TRUSS"; }
  virtual const char *getStringForTOCHNOG() const { return "-bar2"; }
  virtual void reverse()
  {
    MVertex *tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
  }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < -(1. + tol) || u > (1. + tol) || fabs(v) > tol || fabs(w) > tol)
      return false;
    return true;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    v = w = 0.;
    switch(num) {
    case 0: u = -1.; break;
    case 1: u = 1.; break;
    default: u = 0.; break;
    }
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0, 0, 0); }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual void discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts);
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return ((other->getType() == TYPE_LIN || other->getType() == TYPE_PNT) ? 1 :
                                                                             2);
  }
};

/*
 * MLine3
 *
 *         v
 *         ^
 *         |
 *         |
 *   0-----2-----1 --> u
 *
 */
class MLine3 : public MLine {
protected:
  MVertex *_vs[1];

public:
  MLine3(MVertex *v0, MVertex *v1, MVertex *v2, int num = 0, int part = 0)
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
    _vs[0]->setPolynomialOrder(2);
  }
  MLine3(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MLine(v, num, part)
  {
    _vs[0] = v[2];
    _vs[0]->setPolynomialOrder(2);
  }
  ~MLine3() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 3; }
  virtual MVertex *getVertex(int num)
  {
    return num < 2 ? _v[num] : _vs[num - 2];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 2 ? _v[num] : _vs[num - 2];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 2)
      _v[num] = v;
    else
      _vs[num - 2] = v;
  }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[3] = {0, 2, 1};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexINP(int num) { return getVertexUNV(num); }
  virtual MVertex *getVertexKEY(int num) { return getVertexUNV(num); }
  virtual MVertex *getVertexRAD(int num) { return getVertexUNV(num); }
  virtual int getNumEdgeVertices() const { return 1; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MLine::_getEdgeVertices(v);
    v[2] = _vs[0];
  }
  virtual int getTypeForMSH() const { return MSH_LIN_3; }
  virtual int getTypeForUNV() const { return 24; } // parabolic beam
  virtual int getTypeForVTK() const { return 21; }
  virtual const char *getStringForPOS() const { return "SL2"; }
  virtual const char *getStringForINP() const { return "T3D3" /*"C1D3"*/; }
  virtual const char *getStringForKEY() const { return "_BEAM_ELBOW"; }
  virtual const char *getStringForRAD() const { return "/BEAM"; }
  virtual const char *getStringForTOCHNOG() const { return "-bar3"; }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 2 ? MLine::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
  virtual void discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts);
};

/*
 * MLineN
 *
 *         v
 *         ^
 *         |
 *         |
 *  0--2--...--(N-1)--1 --> u
 *
 */
class MLineN : public MLine {
protected:
  std::vector<MVertex *> _vs;

public:
  MLineN(MVertex *v0, MVertex *v1, const std::vector<MVertex *> &vs,
         int num = 0, int part = 0)
    : MLine(v0, v1, num, part), _vs(vs)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  MLineN(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MLine(v[0], v[1], num, part)
  {
    for(std::size_t i = 2; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  ~MLineN() {}
  virtual int getPolynomialOrder() const { return _vs.size() + 1; }
  virtual std::size_t getNumVertices() const { return _vs.size() + 2; }
  virtual MVertex *getVertex(int num)
  {
    return num < 2 ? _v[num] : _vs[num - 2];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 2 ? _v[num] : _vs[num - 2];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 2)
      _v[num] = v;
    else
      _vs[num - 2] = v;
  }
  virtual int getNumEdgeVertices() const { return _vs.size(); }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2 + _vs.size());
    MLine::_getEdgeVertices(v);
    for(std::size_t i = 0; i != _vs.size(); ++i) v[i + 2] = _vs[i];
  }
  virtual int getTypeForMSH() const
  {
    switch(_vs.size()) {
    case 0: return MSH_LIN_2;
    case 1: return MSH_LIN_3;
    case 2: return MSH_LIN_4;
    case 3: return MSH_LIN_5;
    case 4: return MSH_LIN_6;
    case 5: return MSH_LIN_7;
    case 6: return MSH_LIN_8;
    case 7: return MSH_LIN_9;
    case 8: return MSH_LIN_10;
    case 9: return MSH_LIN_11;
    default:
      Msg::Error("No MSH type found for line with %d nodes", 8 + _vs.size());
      return 0;
    }
  }
  virtual void reverse()
  {
    MVertex *tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
    std::vector<MVertex *> inv;
    inv.insert(inv.begin(), _vs.rbegin(), _vs.rend());
    _vs = inv;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 2 ? MLine::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
  virtual void discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts);
};

struct MLinePtrLessThan {
  bool operator()(MLine *l1, MLine *l2) const
  {
    static MEdgeLessThan le;
    return le(l1->getEdge(0), l2->getEdge(0));
  }
};

struct MLinePtrEqual {
  bool operator()(MLine *l1, MLine *l2) const
  {
    static MEdgeEqual le;
    return le(l1->getEdge(0), l2->getEdge(0));
  }
};

#endif
