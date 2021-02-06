// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPYRAMID_H
#define MPYRAMID_H

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
  void _getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v[0] = _v[edges_pyramid(num, 0)];
    v[1] = _v[edges_pyramid(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex *> &v) const
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

public:
  MPyramid(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
           int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v0;
    _v[1] = v1;
    _v[2] = v2;
    _v[3] = v3;
    _v[4] = v4;
  }
  MPyramid(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    for(int i = 0; i < 5; i++) _v[i] = v[i];
  }
  ~MPyramid() {}
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const { return 5; }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual void setVertex(int num, MVertex *v) { _v[num] = v; }
  virtual int getNumEdges() const { return 8; }
  virtual MEdge getEdge(int num) const
  {
    return MEdge(_v[edges_pyramid(num, 0)], _v[edges_pyramid(num, 1)]);
  }
  virtual int numEdge2numVertex(int numEdge, int numVert) const
  {
    return edges_pyramid(numEdge, numVert);
  }
  virtual int getNumEdgesRep(bool curved) { return 8; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces() { return 5; }
  virtual MFace getFace(int num) const
  {
    if(num < 4)
      return MFace(_v[faces_pyramid(num, 0)], _v[faces_pyramid(num, 1)],
                   _v[faces_pyramid(num, 2)]);
    else
      return MFace(_v[0], _v[3], _v[2], _v[1]);
  }
  virtual int getNumFacesRep(bool curved);
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize((num < 4) ? 3 : 4);
    _getFaceVertices(num, v);
  }
  virtual bool getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const;
  virtual int getType() const { return TYPE_PYR; }
  virtual int getTypeForMSH() const { return MSH_PYR_5; }
  virtual int getTypeForVTK() const { return 14; }
  virtual const char *getStringForPOS() const { return "SY"; }
  virtual const char *getStringForBDF() const { return "CPYRAM"; }
  virtual void reverse()
  {
    MVertex *tmp = _v[0];
    _v[0] = _v[2];
    _v[2] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    switch(num) {
    case 0:
      u = -1.;
      v = -1.;
      w = 0.;
      break;
    case 1:
      u = 1.;
      v = -1.;
      w = 0.;
      break;
    case 2:
      u = 1.;
      v = 1.;
      w = 0.;
      break;
    case 3:
      u = -1.;
      v = 1.;
      w = 0.;
      break;
    case 4:
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
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., .2); }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(u < (w - (1. + tol)) || u > ((1. + tol) - w) || v < (w - (1. + tol)) ||
       v > ((1. + tol) - w) || w < (-tol) || w > (1. + tol))
      return false;
    return true;
  }
  void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  static int edges_pyramid(const int edge, const int vert)
  {
    static const int e[8][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                                {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    return e[edge][vert];
  }
  static int faces_pyramid(const int face, const int vert)
  {
    static const int f[5][4] = {
      {0, 1, 4, -1}, {3, 0, 4, -1}, {1, 2, 4, -1}, {2, 3, 4, -1}, {0, 3, 2, 1}};
    return f[face][vert];
  }
  static int faces2edge_pyramid(const int face, const int edge)
  {
    // return -iedge - 1 if edge is inverted
    //         iedge + 1 otherwise
    static const int e[5][4] = {{1, 5, -3, 0},
                                {-2, 3, -8, 0},
                                {4, 7, -5, 0},
                                {6, 8, -7, 0},
                                {2, -6, -4, -1}};
    return e[face][edge];
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const;
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

//------------------------------------------------------------------------------

typedef std::vector<int> IndicesReversed;

class MPyramidN : public MPyramid {
  static std::map<int, IndicesReversed> _order2indicesReversedPyr;

protected:
  std::vector<MVertex *> _vs;
  const char _order;

  void _addHOEdgePoints(int num, std::vector<MVertex *> &v,
                        bool fw = true) const;

public:
  MPyramidN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
            const std::vector<MVertex *> &v, char order, int num = 0,
            int part = 0)
    : MPyramid(v0, v1, v2, v3, v4, num, part), _vs(v), _order(order)
  {
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
    getFunctionSpace(order);
  }
  MPyramidN(const std::vector<MVertex *> &v, char order, int num = 0,
            int part = 0)
    : MPyramid(v[0], v[1], v[2], v[3], v[4], num, part), _order(order)
  {
    for(std::size_t i = 5; i < v.size(); i++) _vs.push_back(v[i]);
    for(std::size_t i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_order);
    getFunctionSpace(order);
  }
  ~MPyramidN();
  virtual int getPolynomialOrder() const { return _order; }
  virtual std::size_t getNumVertices() const { return 5 + _vs.size(); }
  virtual MVertex *getVertex(int num)
  {
    return num < 5 ? _v[num] : _vs[num - 5];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return num < 5 ? _v[num] : _vs[num - 5];
  }
  virtual void setVertex(int num, MVertex *v)
  {
    if(num < 5)
      _v[num] = v;
    else
      _vs[num - 5] = v;
  }
  virtual int getNumEdgeVertices() const { return 8 * (_order - 1); }
  virtual int getNumFaceVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return (_order - 1) * (_order - 1) +
             4 * ((_order - 1) * (_order - 2)) / 2;
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_order + 1);
    MPyramid::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order - 1);
    for(int i = num * (_order - 1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const;

  virtual int getNumVolumeVertices() const
  {
    if(getIsAssimilatedSerendipity())
      return 0;
    else
      return (_order - 2) * ((_order - 2) + 1) * (2 * (_order - 2) + 1) / 6;
  }
  virtual int getTypeForMSH() const
  {
    if(_order == 1 && _vs.size() + 5 == 5) return MSH_PYR_5;
    if(_order == 2 && _vs.size() + 5 == 14) return MSH_PYR_14;
    if(_order == 3 && _vs.size() + 5 == 30) return MSH_PYR_30;
    if(_order == 4 && _vs.size() + 5 == 55) return MSH_PYR_55;
    if(_order == 5 && _vs.size() + 5 == 91) return MSH_PYR_91;
    if(_order == 6 && _vs.size() + 5 == 140) return MSH_PYR_140;
    if(_order == 7 && _vs.size() + 5 == 204) return MSH_PYR_204;
    if(_order == 8 && _vs.size() + 5 == 285) return MSH_PYR_285;
    if(_order == 9 && _vs.size() + 5 == 385) return MSH_PYR_385;

    if(_order == 2 && _vs.size() + 5 == 13) return MSH_PYR_13;
    if(_order == 3 && _vs.size() + 5 == 21) return MSH_PYR_21;
    if(_order == 4 && _vs.size() + 5 == 29) return MSH_PYR_29;
    if(_order == 5 && _vs.size() + 5 == 37) return MSH_PYR_37;
    if(_order == 6 && _vs.size() + 5 == 45) return MSH_PYR_45;
    if(_order == 7 && _vs.size() + 5 == 53) return MSH_PYR_53;
    if(_order == 8 && _vs.size() + 5 == 61) return MSH_PYR_61;
    if(_order == 9 && _vs.size() + 5 == 69) return MSH_PYR_69;
    Msg::Error("No MSH type found for P%d pyramid with %d nodes", _order,
               5 + _vs.size());
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
    num < 5 ? MPyramid::getNode(num, u, v, w) : MElement::getNode(num, u, v, w);
  }
};

#endif
