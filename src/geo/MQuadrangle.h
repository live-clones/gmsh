// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MQUADRANGLE_H
#define MQUADRANGLE_H

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
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_quad(num, 0)];
    v[1] = _v[edges_quad(num, 1)];
  }
  void _getFaceVertices(std::vector<MVertex *> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
    v[2] = _v[2];
    v[3] = _v[3];
  }
  void projectInMeanPlane(double *xn, double *yn);

public:
  MQuadrangle(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num = 0,
              int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
  }
  MQuadrangle(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MQuadrangle() {}

  virtual double etaShapeMeasure();
  virtual double gammaShapeMeasure();
  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[4] = {0, 1, 3, 2};
    return getVertex(map[num]);
  }
  virtual int getNumEdges() const { return 4; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_quad(num, 0)], _v[edges_quad(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_quad(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 4; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const
  {
    return MFace(_v[0], _v[1], _v[2], _v[3]);
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(4);
    _getFaceVertices(v);
  }
  virtual int getType() const { return TYPE_QUA; }
  virtual int getTypeForMSH() const { return MSH_QUA_4; }
  virtual int getTypeForUNV() const
  {
    return 94;
  } // thin shell linear quadrilateral
  virtual int getTypeForVTK() const { return 9; }
  virtual const char *getStringForPOS() const { return "SQ"; }
  virtual const char *getStringForBDF() const { return "CQUAD4"; }
  virtual const char *getStringForDIFF() const { return "ElmB4n2D"; }
  virtual const char *getStringForINP() const { return "CPS4" /*"C2D4"*/; }
  virtual const char *getStringForKEY() const { return "_SHELL"; }
  virtual const char *getStringForRAD() const { return "/SHELL"; }
  virtual const char *getStringForTOCHNOG() const { return "-quad4"; }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    w = 0.;
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
  virtual double getVolume();
  virtual void reverse()
  {
    MVertex *tmp = _v[1];
    _v[1] = _v[3];
    _v[3] = tmp;
  }
  // reorient the quadrangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);

  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < -(1. + tol) || v < -(1. + tol) || u > (1. + tol) || v > (1. + tol) ||
       fabs(w) > tol)
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual double angleShapeMeasure();
  // Computes the minimum inradius of the all the circles tangents to
  // 3 of the 4 edges of the quad. If the 4 points of the quad are not
  // planar, we compute the mean plane due to the least-square
  // criterion.
  virtual double getInnerRadius();
  virtual double getOuterRadius();
  static int edges_quad(const int edge, const int vert)
  {
    static const int e[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    return e[edge][vert];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
  virtual MEdge getEdgeSolin(int num)
  {
    static const int eSolin[4][2] = {{0, 1}, {1, 2}, {3, 2}, {0, 3}};
    return MEdge(_v[eSolin[num][0]], _v[eSolin[num][1]]);
  }
  virtual MFace getFaceSolin(int numFace)
  {
    return MFace(_v[0], _v[1], _v[3], _v[2]);
  }
  virtual double getAngleAtVertex(MVertex *v);
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

public:
  MQuadrangle8(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
               MVertex *v5, MVertex *v6, MVertex *v7, int num = 0, int part = 0)
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4;
    _vs[1] = v5;
    _vs[2] = v6;
    _vs[3] = v7;
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle8(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 4; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle8() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num)
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 4)
      _v[num] = v;
    else
      _vs[num - 4] = v;
  }

  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[8] = {0, 4, 1, 5, 2, 6, 3, 7};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {0, 1, 3, 2, 4, 7, 5, 6};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MQuadrangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(8);
    MQuadrangle::_getFaceVertices(v);
    v[4] = _vs[0];
    v[5] = _vs[1];
    v[6] = _vs[2];
    v[7] = _vs[3];
  }
  virtual int getTypeForMSH() const { return MSH_QUA_8; }
  virtual int getTypeForUNV() const
  {
    return 95;
  } // shell parabolic quadrilateral
  virtual int getTypeForVTK() const { return 23; }
  virtual const char *getStringForBDF() const { return "CQUAD8"; }
  virtual const char *getStringForDIFF() const { return "ElmB8n2D"; }
  virtual const char *getStringForINP() const { return "CPS8" /*"C2D8"*/; }
  virtual const char *getStringForKEY() const { return "_SHELL"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[1];
    _v[1] = _v[3];
    _v[3] = tmp;
    tmp = _vs[0];
    _vs[0] = _vs[3];
    _vs[3] = tmp;
    tmp = _vs[1];
    _vs[1] = _vs[2];
    _vs[2] = tmp;
  }

  // reorient the quadrangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);

  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 4 ? MQuadrangle::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
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

public:
  MQuadrangle9(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
               MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, int num = 0,
               int part = 0)
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4;
    _vs[1] = v5;
    _vs[2] = v6;
    _vs[3] = v7;
    _vs[4] = v8;
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle9(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 5; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle9() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 9; }
  virtual MVertex *getVertex(int num)
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 4)
      _v[num] = v;
    else
      _vs[num - 4] = v;
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[9] = {0, 2, 8, 6, 1, 5, 7, 3, 4};
    return getVertex(map[num]);
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumFaceVertices() const { return 1; }
  virtual int getNumEdgesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MQuadrangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
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
  virtual int getTypeForVTK() const { return 28; }
  virtual const char *getStringForPOS() const { return "SQ2"; }
  virtual const char *getStringForBDF() const { return "CQUAD9"; }
  virtual const char *getStringForDIFF() const { return "ElmB9n2D"; }
  virtual const char *getStringForINP() const { return "M3D9"; /* bof */ }
  virtual const char *getStringForTOCHNOG() const { return "-quad9"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[1];
    _v[1] = _v[3];
    _v[3] = tmp;
    tmp = _vs[0];
    _vs[0] = _vs[3];
    _vs[3] = tmp;
    tmp = _vs[1];
    _vs[1] = _vs[2];
    _vs[2] = tmp;
  }

  // reorient the quadrangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);

  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 4 ? MQuadrangle::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
};

typedef std::vector<int> IndicesReoriented;
typedef std::pair<int, std::pair<int, int> > TupleReorientation;

/*
 * MQuadrangle
 *
 *   3--3+3E-...--4+2E--2
 *   |                  |    E = order - 1;
 *   |                  |    N = total number of vertices
 * 4+3E                3+2E
 *   |                  |    Interior vertex numbers
 *  ...  4+4E to N-1   ...    for edge 0 <= i <= 3: 4+i*E to 3+(i+1)*E
 *   |                  |     in face             : 4+4*E to N-1
 * 3+4E                4+E
 *   |                  |
 *   |                  |
 *   0---4--...---3+E---1
 *
 */
class MQuadrangleN : public MQuadrangle {
  static std::map<TupleReorientation, IndicesReoriented>
    _tuple2indicesReoriented;

protected:
  std::vector<MVertex *> _vs;
  const char _order;

public:
  MQuadrangleN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
               const std::vector<MVertex *> &v, char order, int num = 0,
               int part = 0)
    : MQuadrangle(v0, v1, v2, v3, num, part), _vs(v), _order(order)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  MQuadrangleN(const std::vector<MVertex *> &v, char order, int num = 0,
               int part = 0)
    : MQuadrangle(v[0], v[1], v[2], v[3], num, part), _order(order)
  {
    for(std::size_t i = 4; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  ~MQuadrangleN() {}
  virtual int getPolynomialOrder() const { return _order; }
  virtual std::size_t getNumVertices() const { return 4 + _vs.size(); }
  virtual MVertex *getVertex(int num)
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 4 ? _v[num] : _vs[num - 4];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 4)
      _v[num] = v;
    else
      _vs[num - 4] = v;
  }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return (_order - 1) * (_order - 1);
  }
  virtual int getNumEdgeVertices() const { return 4 * (_order - 1); }
  virtual int getNumEdgesRep(bool curved);
  virtual int getNumFacesRep(bool curved);
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MQuadrangle::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order - 1);
    for(int i = num * (_order - 1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual MFaceN getHighOrderFace(int num, int sign, int rot);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(4 + _vs.size());
    MQuadrangle::_getFaceVertices(v);
    for(std::size_t i = 0; i != _vs.size(); ++i) v[i + 4] = _vs[i];
  }
  virtual const char *getStringForPOS() const
  {
    return (getTypeForMSH() == MSH_QUA_9) ? "SQ2" : "SQ";
  }
  virtual int getTypeForMSH() const
  {
    if(_order == 1 && _vs.size() + 4 == 4) return MSH_QUA_4;
    if(_order == 2 && _vs.size() + 4 == 9) return MSH_QUA_9;
    if(_order == 3 && _vs.size() + 4 == 16) return MSH_QUA_16;
    if(_order == 4 && _vs.size() + 4 == 25) return MSH_QUA_25;
    if(_order == 5 && _vs.size() + 4 == 36) return MSH_QUA_36;
    if(_order == 6 && _vs.size() + 4 == 49) return MSH_QUA_49;
    if(_order == 7 && _vs.size() + 4 == 64) return MSH_QUA_64;
    if(_order == 8 && _vs.size() + 4 == 81) return MSH_QUA_81;
    if(_order == 9 && _vs.size() + 4 == 100) return MSH_QUA_100;
    if(_order == 10 && _vs.size() + 4 == 121) return MSH_QUA_121;

    if(_order == 2 && _vs.size() + 4 == 8) return MSH_QUA_8;
    if(_order == 3 && _vs.size() + 4 == 12) return MSH_QUA_12;
    if(_order == 4 && _vs.size() + 4 == 16) return MSH_QUA_16I;
    if(_order == 5 && _vs.size() + 4 == 20) return MSH_QUA_20;
    if(_order == 6 && _vs.size() + 4 == 24) return MSH_QUA_24;
    if(_order == 7 && _vs.size() + 4 == 28) return MSH_QUA_28;
    if(_order == 8 && _vs.size() + 4 == 32) return MSH_QUA_32;
    if(_order == 9 && _vs.size() + 4 == 36) return MSH_QUA_36I;
    if(_order == 10 && _vs.size() + 4 == 40) return MSH_QUA_40;
    Msg::Error("No MSH type found for P%d quadrangle with %d nodes", _order,
               4 + _vs.size());
    return 0;
  }
  virtual int getTypeForVTK() const
  {
    if(_order == 2 && _vs.size() + 4 == 9) return 28;
    if(_order == 2 && _vs.size() + 4 == 8) return 23;
    return MQuadrangle::getTypeForVTK();
  }
  virtual void reverse();

  // reorient the quadrangle to conform with other face
  // orientation computed with MFace based on this face with respect to other
  // in computeCorrespondence
  virtual void reorient(int rotation, bool swap);

  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 4 ? MQuadrangle::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
};

template <class T> void inline sort2(T &a, T &b)
{
  if(b < a) {
    T t = b;
    b = a;
    a = t;
  }
}

template <class T> void sort4(T *t[4])
{
  sort2<T *>(t[0], t[1]);
  sort2<T *>(t[2], t[3]);
  sort2<T *>(t[0], t[2]);
  sort2<T *>(t[1], t[3]);
  sort2<T *>(t[1], t[2]);
}

struct compareMQuadrangleLexicographic {
  bool operator()(MQuadrangle *t1, MQuadrangle *t2) const
  {
    MVertex *_v1[] = {t1->getVertex(0), t1->getVertex(1), t1->getVertex(2),
                      t1->getVertex(3)};
    MVertex *_v2[] = {t2->getVertex(0), t2->getVertex(1), t2->getVertex(2),
                      t2->getVertex(3)};
    sort4(_v1);
    sort4(_v2);
    if(_v1[0] < _v2[0]) return true;
    if(_v1[0] > _v2[0]) return false;
    if(_v1[1] < _v2[1]) return true;
    if(_v1[1] > _v2[1]) return false;
    if(_v1[2] < _v2[2]) return true;
    if(_v1[2] > _v2[2]) return false;
    if(_v1[3] < _v2[3]) return true;
    return false;
  }
};

#endif
