// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef NODALBASIS_H
#define NODALBASIS_H

#include "fullMatrix.h"
#include "GmshDefines.h"

class nodalBasis {
 public:
  int type, parentType, order, dimension, numFaces;
  bool serendip;
  fullMatrix<double> points;

  nodalBasis() {}
  nodalBasis(int tag);
  virtual ~nodalBasis() {}

  virtual int getNumShapeFunctions() const = 0;
  void getReferenceNodes(fullMatrix<double> &nodes) const {
    nodes = points;
  }
  const fullMatrix<double>& getReferenceNodes() const {
    return points;
  }
  void getReferenceNodesForBezier(fullMatrix<double> &nodes) const;

  // Basis functions & gradients evaluation
  virtual void f(double u, double v, double w, double *sf) const = 0;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const = 0;
  virtual void df(double u, double v, double w, double grads[][3]) const = 0;
  virtual void df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const = 0;
  virtual void ddf(double u, double v, double w, double grads[][3][3]) const {Msg::Fatal("Not implemented");}
  virtual void dddf(double u, double v, double w, double grads[][3][3][3]) const {Msg::Fatal("Not implemented");}

  // closures is the list of the nodes of each face, in the order of
  // the polynomialBasis of the face; fullClosures is mapping of the
  // nodes of the element that rotates the element so that the
  // considered face becomes the first one in the right orientation;
  // For element, like prisms that have different kind of faces,
  // fullCLosure[i] rotates the element so that the considered face
  // becomes the closureRef[i]-th face (the first tringle or the first
  // quad face)
  class closure : public std::vector<int> {
    public:
    int type;
  };
  typedef std::vector<closure> clCont;
  clCont closures, fullClosures;
  std::vector<int> closureRef;

  // for a given face/edge, with both a sign and a rotation, give an
  // ordered list of nodes on this face/edge
  virtual int getClosureType(int id) const { return closures[id].type; }
  virtual const std::vector<int> &getClosure(int id) const { return closures[id]; }
  virtual const std::vector<int> &getFullClosure(int id) const { return fullClosures[id]; }
  inline int getClosureId(int iFace, int iSign = 1, int iRot = 0) const;
  inline void breakClosureId(int i, int &iFace, int &iSign, int &iRot) const;
};

inline int nodalBasis::getClosureId(int iFace, int iSign, int iRot) const
{
  return iFace + numFaces * (iSign == 1 ? 0 : 1) + 2 * numFaces * iRot;
}

inline void nodalBasis::breakClosureId(int i, int &iFace, int &iSign, int &iRot) const
{
  iFace = i % numFaces;
  i = (i - iFace) / numFaces;
  iSign = i % 2;
  iRot = (i - iSign) / 2;
}

#endif
