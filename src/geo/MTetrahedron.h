// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MTETRAHEDRON_H
#define MTETRAHEDRON_H

#include "MElement.h"

/*
 * MTetrahedron
 *
 *                      v
 *                    .
 *                  ,/
 *                 /
 *              2
 *            ,/|`\
 *          ,/  |  `\
 *        ,/    '.   `\
 *      ,/       |     `\
 *    ,/         |       `\
 *   0-----------'.--------1 --> u
 *    `\.         |      ,/
 *       `\.      |    ,/
 *          `\.   '. ,/
 *             `\. |/
 *                `3
 *                   `\.
 *                      ` w
 *
 */
class MTetrahedron : public MElement {
protected:
  MVertex *_v[4];
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_tetra(num, 0)];
    v[1] = _v[edges_tetra(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[faces_tetra(num, 0)];
    v[1] = _v[faces_tetra(num, 1)];
    v[2] = _v[faces_tetra(num, 2)];
  }

public:
  MTetrahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num = 0,
               int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
  }
  MTetrahedron(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MTetrahedron() {}
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual int getNumEdges() const { return 6; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_tetra(num, 0)], _v[edges_tetra(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_tetra(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 6; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 4; }
  virtual MFace getFace(int num) const
  {
    return MFace(_v[faces_tetra(num, 0)], _v[faces_tetra(num, 1)],
                 _v[faces_tetra(num, 2)]);
  }
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual int getNumFacesRep(bool curved) { return 4; }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_v[faces_tetra(num, 0)], _v[faces_tetra(num, 1)],
                _v[faces_tetra(num, 2)], x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    _getFaceVertices(num, v);
  }
  virtual int getType() const { return TYPE_TET; }
  virtual int getTypeForMSH() const { return MSH_TET_4; }
  virtual int getTypeForUNV() const { return 111; } // solid linear tetrahedron
  virtual int getTypeForVTK() const { return 10; }
  virtual const char *getStringForPOS() const { return "SS"; }
  virtual const char *getStringForBDF() const { return "CTETRA"; }
  virtual const char *getStringForDIFF() const { return "ElmT4n3D"; }
  virtual const char *getStringForINP() const { return "C3D4"; }
  virtual const char *getStringForKEY() const { return "_SOLID"; }
  virtual const char *getStringForRAD() const { return "/TETRA4"; }
  virtual const char *getStringForTOCHNOG() const { return "-tet4"; }
  virtual void reverse()
  {
    MVertex *tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
  }
  void getMat(double mat[3][3]) const
  {
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[2]->x() - _v[0]->x();
    mat[0][2] = _v[3]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[2]->y() - _v[0]->y();
    mat[1][2] = _v[3]->y() - _v[0]->y();
    mat[2][0] = _v[1]->z() - _v[0]->z();
    mat[2][1] = _v[2]->z() - _v[0]->z();
    mat[2][2] = _v[3]->z() - _v[0]->z();
  }
  virtual double getVolume();
  virtual int getVolumeSign() { return (getVolume() >= 0) ? 1 : -1; }
  virtual double gammaShapeMeasure();
  virtual double getInnerRadius();
  virtual double getOuterRadius();
  virtual double etaShapeMeasure();
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    switch(num) {
    case 0:
      u = 0.;
      v = 0.;
      w = 0.;
      break;
    case 1:
      u = 1.;
      v = 0.;
      w = 0.;
      break;
    case 2:
      u = 0.;
      v = 1.;
      w = 0.;
      break;
    case 3:
      u = 0.;
      v = 0.;
      w = 1.;
      break;
    default:
      u = 0.;
      v = 0.;
      w = 0.;
      break;
    }
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(.25, .25, .25); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < (-tol) || v < (-tol) || w < (-tol) || u > ((1. + tol) - v - w))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual SPoint3 circumcenter();
  static int edges_tetra(const int edge, const int vert)
  {
    static const int e[6][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {3, 1}};
    return e[edge][vert];
  }
  static int faces_tetra(const int face, const int vert)
  {
    static const int f[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
    return f[face][vert];
  }
  static int faces2edge_tetra(const int face, const int edge)
  {
    // return -iedge - 1 if edge is inverted
    //         iedge + 1 otherwise
    static const int e[4][3] = {
      {-3, -2, -1}, {1, -6, 4}, {-4, 5, 3}, {6, 2, -5}};
    return e[face][edge];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
  virtual MEdge getEdgeSolin(int num)
  {
    static const int eSolin[6][2] = {{0, 1}, {1, 2}, {2, 0},
                                     {0, 3}, {2, 3}, {1, 3}};
    return MEdge(_v[eSolin[num][0]], _v[eSolin[num][1]]);
  }
  virtual MFace getFaceSolin(int num)
  {
    static const int fSolin[4][3] = {
      {0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
    return MFace(_v[fSolin[num][0]], _v[fSolin[num][1]], _v[fSolin[num][2]]);
  }
};

/*
 * MTetrahedron10
 *
 *              2
 *            ,/|`\
 *          ,/  |  `\
 *        ,6    '.   `5
 *      ,/       8     `\
 *    ,/         |       `\
 *   0--------4--'.--------1
 *    `\.         |      ,/
 *       `\.      |    ,9
 *          `7.   '. ,/
 *             `\. |/
 *                `3
 *
 */
class MTetrahedron10 : public MTetrahedron {
protected:
  MVertex *_vs[6];

public:
  MTetrahedron10(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
                 MVertex *v4, MVertex *v5, MVertex *v6, MVertex *v7,
                 MVertex *v8, MVertex *v9, int num = 0, int part = 0)
    : MTetrahedron(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4;
    _vs[1] = v5;
    _vs[2] = v6;
    _vs[3] = v7;
    _vs[4] = v8;
    _vs[5] = v9;
    for(int i = 0; i < 6; i++) _vs[i]->setPolynomialOrder(2);
  }
  MTetrahedron10(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MTetrahedron(v, num, part)
  {
    for(int i = 0; i < 6; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 6; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MTetrahedron10() {}
  virtual int getPolynomialOrder() const { return 2; }
  virtual std::size_t getNumVertices() const { return 10; }
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
    static const int map[10] = {0, 4, 1, 5, 2, 6, 7, 9, 8, 3};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexVTK(int num)
  {
    static const int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    return getVertex(map[num]);
  }
  virtual MVertex *getVertexDIFF(int num) { return getVertexBDF(num); }
  virtual MVertex *getVertexINP(int num) { return getVertexBDF(num); }
  virtual MVertex *getVertexKEY(int num) { return getVertexBDF(num); }
  virtual MVertex *getVertexRAD(int num) { return getVertexBDF(num); }
  virtual int getNumEdgeVertices() const { return 6; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual int getNumEdgesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual int getNumFacesRep(bool curved);
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    MTetrahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(6);
    MTetrahedron::_getFaceVertices(num, v);
    static const int f[4][3] = {{2, 1, 0}, {0, 5, 3}, {3, 4, 2}, {5, 1, 4}};
    v[3] = _vs[f[num][0]];
    v[4] = _vs[f[num][1]];
    v[5] = _vs[f[num][2]];
  }
  virtual int getTypeForMSH() const { return MSH_TET_10; }
  virtual int getTypeForUNV() const
  {
    return 118;
  } // solid parabolic tetrahedron
  virtual int getTypeForVTK() const { return 24; }
  virtual const char *getStringForPOS() const { return "SS2"; }
  virtual const char *getStringForBDF() const { return "CTETRA"; }
  virtual const char *getStringForDIFF() const { return "ElmT10n3D"; }
  virtual const char *getStringForINP() const { return "C3D10"; }
  virtual const char *getStringForKEY() const { return "_SOLID"; }
  virtual const char *getStringForRAD() const { return "/TETRA10"; }
  virtual const char *getStringForTOCHNOG() const { return "-tet10"; }
  virtual void reverse()
  {
    MVertex *tmp;
    tmp = _v[0];
    _v[0] = _v[1];
    _v[1] = tmp;
    tmp = _vs[1];
    _vs[1] = _vs[2];
    _vs[2] = tmp;
    tmp = _vs[5];
    _vs[5] = _vs[3];
    _vs[3] = tmp;
  }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 4 ? MTetrahedron::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  void xyz2uvw(double xyz[3], double uvw[3]) const
  {
    return MElement::xyz2uvw(xyz, uvw);
  }
};

/* tet order 3 FIXME: check the plot
 *
 *              2
 *            ,/|`\
 *          ,8  |  `7              E = order - 1
 *        ,/    13   `\            C = 4 + 6*E
 *      ,9       |     `6          F = ((order - 1)*(order - 2))/2
 *    ,/         |       `\        N = total number of vertices
 *   0-----4-----'.--5-----1
 *    `\.         |      ,/        Interior vertex numbers
 *       11.     12    ,15           for edge 0 <= i <= 5: 4+i*E to 4+(i+1)*E-1
 *          `\.   '. 14              for face 0 <= j <= 3: C+j*F to C+(j+1)*F-1
 *             10\.|/        in volume           : C+4*F to N-1
 *                `3
 *
 */

typedef std::vector<int> IndicesReversed;

class MTetrahedronN : public MTetrahedron {
  static std::map<int, IndicesReversed> _order2indicesReversedTet;

protected:
  std::vector<MVertex *> _vs;
  const char _order;

public:
  MTetrahedronN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
                const std::vector<MVertex *> &v, char order, int num = 0,
                int part = 0)
    : MTetrahedron(v0, v1, v2, v3, num, part), _vs(v), _order(order)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  MTetrahedronN(const std::vector<MVertex *> &v, char order, int num = 0,
                int part = 0)
    : MTetrahedron(v[0], v[1], v[2], v[3], num, part), _order(order)
  {
    for(std::size_t i = 4; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
  }
  ~MTetrahedronN() {}
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
  virtual int getNumEdgeVertices() const { return 6 * (_order - 1); }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return 4 * ((_order - 1) * (_order - 2)) / 2;
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MTetrahedron::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order - 1);
    for(int i = num * (_order - 1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    if(getIsAssimilatedSerendipity()) { v.resize(3 * _order); }
    else {
      v.resize((_order + 1) * (_order + 2) / 2);
    }

    MTetrahedron::_getFaceVertices(num, v);
    int count = 2;

    int n = _order - 1;
    for(int i = 0; i < 3; i++) {
      if(faces2edge_tetra(num, i) > 0) {
        int edge_num = faces2edge_tetra(num, i) - 1;
        for(int j = 0; j < n; j++) v[++count] = _vs[n * edge_num + j];
      }
      else {
        int edge_num = -faces2edge_tetra(num, i) - 1;
        for(int j = n - 1; j >= 0; j--) v[++count] = _vs[n * edge_num + j];
      }
    }

    if((int)v.size() > count + 1) {
      int start = 6 * n + num * (n - 1) * n / 2;
      for(int i = 0; i < (n - 1) * n / 2; i++) { v[++count] = _vs[start + i]; }
    }
  }
  virtual int getNumVolumeVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return ((_order - 1) * (_order - 2) * (_order - 3)) / 6;
  }
  virtual int getTypeForMSH() const
  {
    // (p+1)*(p+2)*(p+3)/6
    if(_order == 1 && _vs.size() + 4 == 4) return MSH_TET_4;
    if(_order == 2 && _vs.size() + 4 == 10) return MSH_TET_10;
    if(_order == 3 && _vs.size() + 4 == 20) return MSH_TET_20;
    if(_order == 4 && _vs.size() + 4 == 35) return MSH_TET_35;
    if(_order == 5 && _vs.size() + 4 == 56) return MSH_TET_56;
    if(_order == 6 && _vs.size() + 4 == 84) return MSH_TET_84;
    if(_order == 7 && _vs.size() + 4 == 120) return MSH_TET_120;
    if(_order == 8 && _vs.size() + 4 == 165) return MSH_TET_165;
    if(_order == 9 && _vs.size() + 4 == 220) return MSH_TET_220;
    if(_order == 10 && _vs.size() + 4 == 286) return MSH_TET_286;

    if(_order == 3 && _vs.size() + 4 == 16) return MSH_TET_16;
    if(_order == 4 && _vs.size() + 4 == 22) return MSH_TET_22;
    if(_order == 5 && _vs.size() + 4 == 28) return MSH_TET_28;
    if(_order == 6 && _vs.size() + 4 == 34) return MSH_TET_34;
    if(_order == 7 && _vs.size() + 4 == 40) return MSH_TET_40;
    if(_order == 8 && _vs.size() + 4 == 46) return MSH_TET_46;
    if(_order == 9 && _vs.size() + 4 == 52) return MSH_TET_52;
    if(_order == 10 && _vs.size() + 4 == 58) return MSH_TET_58;
    Msg::Error("No MSH type found for P%d tetrahedron with %d nodes", _order,
               4 + _vs.size());
    return 0;
  }
  virtual void reverse();
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual int getNumEdgesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual int getNumFacesRep(bool curved);
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    num < 4 ? MTetrahedron::getNode(num, u, v, w) :
              MElement::getNode(num, u, v, w);
  }
  void xyz2uvw(double xyz[3], double uvw[3]) const
  {
    return MElement::xyz2uvw(xyz, uvw);
  }
};

#endif
