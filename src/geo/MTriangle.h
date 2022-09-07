// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MTRIANGLE_H
#define MTRIANGLE_H

#include "MElement.h"

/*
 * MTriangle
 *
 *   v
 *   ^
 *   |
 *   2
 *   |`\
 *   |  `\
 *   |    `\
 *   |      `\
 *   |        `\
 *   0----------1 --> u
 *
 */
class MTriangle : public MElement {
protected:
  MVertex *_v[3];
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_tri(num, 0)];
    v[1] = _v[edges_tri(num, 1)];
  }
  void _getFaceVertices(std::vector<MVertex *> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
    v[2] = _v[2];
  }

public:
  MTriangle(MVertex *v0, MVertex *v1, MVertex *v2, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
  }
  MTriangle(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 3; i++) _v[i] = v[i];
  }
  ~MTriangle() {}
  virtual int getDim() const { return 2; }
  virtual double etaShapeMeasure();
  virtual double gammaShapeMeasure();
  virtual double getInnerRadius();
  virtual double getOuterRadius();
  virtual double angleShapeMeasure();
  virtual std::size_t getNumVertices() const { return 3; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual MVertex *getOtherVertex(MVertex *v1, MVertex *v2)
  {
    if(_v[0] != v1 && _v[0] != v2) return _v[0];
    if(_v[1] != v1 && _v[1] != v2) return _v[1];
    if(_v[2] != v1 && _v[2] != v2) return _v[2];
    return nullptr;
  }
  virtual int getNumEdges() const { return 3; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_tri(num, 0)], _v[edges_tri(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_tri(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 3; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const { return MFace(_v[0], _v[1], _v[2]); }
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual int getNumFacesRep(bool curved) { return 1; }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_v[0], _v[1], _v[2], x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    _getFaceVertices(v);
  }
  virtual int getType() const { return TYPE_TRI; }
  virtual int getTypeForMSH() const { return MSH_TRI_3; }
  virtual int getTypeForUNV() const { return 91; } // thin shell linear triangle
  virtual int getTypeForVTK() const { return 5; }
  virtual const char *getStringForPOS() const { return "ST"; }
  virtual const char *getStringForBDF() const { return "CTRIA3"; }
  virtual const char *getStringForDIFF() const { return "ElmT3n2D"; }
  virtual const char *getStringForINP() const
  {
    return "CPS3" /*"STRI3"*/ /*"C2D3"*/;
  }
  virtual const char *getStringForKEY() const { return "_SHELL"; }
  virtual const char *getStringForRAD() const { return "/SH3N"; }
  virtual const char *getStringForTOCHNOG() const { return "-tria3"; }
  virtual void reverse()
  {
    MVertex *tmp = _v[1];
    _v[1] = _v[2];
    _v[2] = tmp;
  }

  // reorient the triangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);

  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    w = 0.;
    switch(num) {
    case 0:
      u = 0.;
      v = 0.;
      break;
    case 1:
      u = 1.;
      v = 0.;
      break;
    case 2:
      u = 0.;
      v = 1.;
      break;
    default:
      u = 0.;
      v = 0.;
      break;
    }
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(1 / 3., 1 / 3., 0.); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < (-tol) || v < (-tol) || u > ((1. + tol) - v) || fabs(w) > tol)
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual SPoint3 circumcenter();
  virtual double getVolume();
  static int edges_tri(const int edge, const int vert)
  {
    static const int e[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    return e[edge][vert];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
  virtual MEdge getEdgeSolin(int num)
  {
    static const int eSolin[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    return MEdge(_v[eSolin[num][0]], _v[eSolin[num][1]]);
  }
  virtual MFace getFaceSolin(int num) { return getFace(num); }
};

/*
 * MTriangle6
 *
 *   2
 *   |`\
 *   |  `\
 *   5    `4
 *   |      `\
 *   |        `\
 *   0-----3----1
 *
 */
class MTriangle6 : public MTriangle {
protected:
  MVertex *_vs[3];

public:
  MTriangle6(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
             MVertex *v5, int num = 0, int part = 0)
    : MTriangle(v0, v1, v2, num, part)
  {
    _vs[0] = v3;
    _vs[1] = v4;
    _vs[2] = v5;
    for(int i = 0; i < 3; i++) _vs[i]->setPolynomialOrder(2);
  }
  MTriangle6(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MTriangle(v, num, part)
  {
    for(int i = 0; i < 3; i++) _vs[i] = v[3 + i];
    for(int i = 0; i < 3; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MTriangle6() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 6; }
  virtual MVertex *getVertex(int num)
  {
    return num < 3 ? _v[num] : _vs[num - 3];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 3 ? _v[num] : _vs[num - 3];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 3)
      _v[num] = v;
    else
      _vs[num - 3] = v;
  }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[6] = {0, 3, 1, 4, 2, 5};
    return getVertex(map[num]);
  }
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const
  {
    MElement::xyz2uvw(xyz, uvw);
  }
  virtual int getNumEdgeVertices() const { return 3; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MTriangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(6);
    MTriangle::_getFaceVertices(v);
    v[3] = _vs[0];
    v[4] = _vs[1];
    v[5] = _vs[2];
  }
  virtual int getTypeForMSH() const { return MSH_TRI_6; }
  virtual int getTypeForUNV() const
  {
    return 92;
  } // thin shell parabolic triangle
  virtual int getTypeForVTK() const { return 22; }
  virtual const char *getStringForPOS() const { return "ST2"; }
  virtual const char *getStringForBDF() const { return "CTRIA6"; }
  virtual const char *getStringForDIFF() const { return "ElmT6n2D"; }
  virtual const char *getStringForINP() const
  {
    return "CPS6" /*"STRI65"*/ /*"C2D6"*/;
  }
  virtual const char *getStringForKEY() const { return "_SHELL"; }
  virtual const char *getStringForTOCHNOG() const { return "-tria6"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[1];
    _v[1] = _v[2];
    _v[2] = tmp;
    tmp = _vs[0];
    _vs[0] = _vs[2];
    _vs[2] = tmp;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 3 ? MTriangle::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  // reorient the triangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);
};

typedef std::vector<int> IndicesReoriented;
typedef std::pair<int, std::pair<int, int> > TupleReorientation;

/*
 * MTriangleN  FIXME: check the plot
 *
 *   2
 *   |`\                E = order - 1;
 *   |  `\              N = total number of vertices
 * 3+2E   2+2E
 *   |      `\          Interior vertex numbers
 *  ...       ...         for edge 0 <= i <= 2: 3+i*E to 2+(i+1)*E
 *   |          `\        in face             : 3+3*E to N-1
 * 2+3E           3+E
 *   |  3+3E to N-1 `\
 *   |                `\
 *   0---3--...---2+E---1
 *
 */
class MTriangleN : public MTriangle {
  static std::map<TupleReorientation, IndicesReoriented>
    _tuple2indicesReoriented;

protected:
  std::vector<MVertex *> _vs;
  const char _order;

public:
  MTriangleN(MVertex *v0, MVertex *v1, MVertex *v2,
             const std::vector<MVertex *> &v, char order, int num = 0,
             int part = 0)
    : MTriangle(v0, v1, v2, num, part), _vs(v), _order(order)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  MTriangleN(const std::vector<MVertex *> &v, char order, int num = 0,
             int part = 0)
    : MTriangle(v[0], v[1], v[2], num, part), _order(order)
  {
    for(std::size_t i = 3; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  ~MTriangleN() {}
  virtual int getPolynomialOrder() const { return _order; }
  virtual std::size_t getNumVertices() const { return 3 + _vs.size(); }
  virtual MVertex *getVertex(int num)
  {
    return num < 3 ? _v[num] : _vs[num - 3];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 3 ? _v[num] : _vs[num - 3];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 3)
      _v[num] = v;
    else
      _vs[num - 3] = v;
  }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return (_order - 1) * (_order - 2) / 2;
  }
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const
  {
    MElement::xyz2uvw(xyz, uvw);
  }
  virtual int getNumEdgeVertices() const { return 3 * (_order - 1); }
  virtual int getNumEdgesRep(bool curved);
  virtual int getNumFacesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MTriangle::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order - 1);
    for(int i = num * (_order - 1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3 + _vs.size());
    MTriangle::_getFaceVertices(v);
    for(std::size_t i = 0; i != _vs.size(); ++i) v[i + 3] = _vs[i];
  }
  virtual int getTypeForMSH() const
  {
    if(_order == 1 && _vs.size() == 0) return MSH_TRI_3;
    if(_order == 2 && _vs.size() == 3) return MSH_TRI_6;
    if(_order == 3 && _vs.size() == 7) return MSH_TRI_10;
    if(_order == 4 && _vs.size() == 12) return MSH_TRI_15;
    if(_order == 5 && _vs.size() == 18) return MSH_TRI_21;
    if(_order == 6 && _vs.size() == 25) return MSH_TRI_28;
    if(_order == 7 && _vs.size() == 33) return MSH_TRI_36;
    if(_order == 8 && _vs.size() == 42) return MSH_TRI_45;
    if(_order == 9 && _vs.size() == 52) return MSH_TRI_55;
    if(_order == 10 && _vs.size() == 63) return MSH_TRI_66;

    if(_order == 3 && _vs.size() == 6) return MSH_TRI_9;
    if(_order == 4 && _vs.size() == 9) return MSH_TRI_12;
    if(_order == 5 && _vs.size() == 12) return MSH_TRI_15I;
    if(_order == 6 && _vs.size() == 15) return MSH_TRI_18;
    if(_order == 7 && _vs.size() == 18) return MSH_TRI_21I;
    if(_order == 8 && _vs.size() == 21) return MSH_TRI_24;
    if(_order == 9 && _vs.size() == 24) return MSH_TRI_27;
    if(_order == 10 && _vs.size() == 27) return MSH_TRI_30;
    Msg::Error("No MSH type found for P%d triangle with %d nodes", _order,
               3 + _vs.size());
    return 0;
  }
  virtual int getTypeForVTK() const
  {
    return (_order == 2) ? 22 : MTriangle::getTypeForVTK();
  }
  virtual void reverse();
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 3 ? MTriangle::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  // reorient the triangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);
};

template <class T> void sort3(T t[3])
{
  T temp;
  if(t[0] > t[1]) {
    temp = t[1];
    t[1] = t[0];
    t[0] = temp;
  }
  if(t[1] > t[2]) {
    temp = t[2];
    t[2] = t[1];
    t[1] = temp;
  }
  if(t[0] > t[1]) {
    temp = t[1];
    t[1] = t[0];
    t[0] = temp;
  }
}

struct compareMTriangleLexicographic {
  bool operator()(MTriangle *t1, MTriangle *t2) const
  {
    std::size_t _v1[3] = {t1->getVertex(0)->getNum(),
                          t1->getVertex(1)->getNum(),
                          t1->getVertex(2)->getNum()};
    std::size_t _v2[3] = {t2->getVertex(0)->getNum(),
                          t2->getVertex(1)->getNum(),
                          t2->getVertex(2)->getNum()};
    sort3(_v1);
    sort3(_v2);
    if(_v1[0] < _v2[0]) return true;
    if(_v1[0] > _v2[0]) return false;
    if(_v1[1] < _v2[1]) return true;
    if(_v1[1] > _v2[1]) return false;
    if(_v1[2] < _v2[2]) return true;
    return false;
  }
};

#endif
