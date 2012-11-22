// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef NODALBASIS_H
#define NODALBASIS_H

#include "fullMatrix.h"
#include "GmshDefines.h"

class nodalBasis {

 public:
  int type, parentType, order, dimension, numFaces;
  bool serendip;
  fullMatrix<double> points;

  nodalBasis(int tag);
  virtual ~nodalBasis() {}

  // Basis functions evaluation
  virtual void f(double u, double v, double w, double *sf) const {Msg::Fatal("Not implemented");};
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const {Msg::Fatal("Not implemented");};

  // Basis functions gradients evaluation
  virtual void df(double u, double v, double w, double grads[][3]) const {Msg::Fatal("Not implemented");};
  virtual void df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const {Msg::Fatal("Not implemented");};
  
  virtual void ddf(double u, double v, double w, double grads[][3][3]) const {Msg::Fatal("Not implemented");};
  virtual void dddf(double u, double v, double w, double grads[][3][3][3]) const {Msg::Fatal("Not implemented");};

  virtual int getNumShapeFunctions() const {Msg::Fatal("Not implemented"); return -1;}

  class closure : public std::vector<int> {
    public:
    int type;
  };
  typedef std::vector<closure> clCont;
  // closures is the list of the nodes of each face, in the order of
  // the polynomialBasis of the face; fullClosures is mapping of the
  // nodes of the element that rotates the element so that the
  // considered face becomes the first one in the right orientation;
  // For element, like prisms that have different kind of faces,
  // fullCLosure[i] rotates the element so that the considered face
  // becomes the closureRef[i]-th face (the first tringle or the first
  // quad face)
  clCont closures, fullClosures;
  std::vector<int> closureRef;

  // for a given face/edge, with both a sign and a rotation, give an
  // ordered list of nodes on this face/edge
  virtual int getClosureType(int id) const { return closures[id].type; }
  virtual const std::vector<int> &getClosure(int id) const { return closures[id]; }
  virtual const std::vector<int> &getFullClosure(int id) const { return fullClosures[id]; }
  inline int getClosureId(int iFace, int iSign=1, int iRot=0) const;
  inline void breakClosureId(int i, int &iFace, int &iSign, int &iRot) const;

  static inline int getTag(int parentTag, int order, bool serendip = false);

};



inline int nodalBasis::getClosureId(int iFace, int iSign, int iRot) const
{
  return iFace + numFaces*(iSign == 1 ? 0 : 1) + 2*numFaces*iRot;
}



inline void nodalBasis::breakClosureId(int i, int &iFace, int &iSign, int &iRot) const
{
  iFace = i % numFaces;
  i = (i - iFace)/numFaces;
  iSign = i % 2;
  iRot = (i - iSign) / 2;
}



inline int nodalBasis::getTag(int parentTag, int order, bool serendip)
{
  switch (parentTag) {
  case TYPE_PNT :
    return MSH_PNT;
  case TYPE_LIN :
    switch(order) {
    case 0 : return MSH_LIN_1;
    case 1 : return MSH_LIN_2;
    case 2 : return MSH_LIN_3;
    case 3 : return MSH_LIN_4;
    case 4 : return MSH_LIN_5;
    case 5 : return MSH_LIN_6;
    case 6 : return MSH_LIN_7;
    case 7 : return MSH_LIN_8;
    case 8 : return MSH_LIN_9;
    case 9 : return MSH_LIN_10;
    case 10: return MSH_LIN_11;
    default : Msg::Error("line order %i unknown", order); return 0;
    }
    break;
  case TYPE_TRI :
    switch(order) {
    case 0 : return MSH_TRI_1;
    case 1 : return MSH_TRI_3;
    case 2 : return MSH_TRI_6;
    case 3 : return serendip ? MSH_TRI_9  : MSH_TRI_10;
    case 4 : return serendip ? MSH_TRI_12 : MSH_TRI_15;
    case 5 : return serendip ? MSH_TRI_15I: MSH_TRI_21;
    case 6 : return serendip ? MSH_TRI_18 : MSH_TRI_28;
    case 7 : return serendip ? MSH_TRI_21I: MSH_TRI_36;
    case 8 : return serendip ? MSH_TRI_24 : MSH_TRI_45;
    case 9 : return serendip ? MSH_TRI_27 : MSH_TRI_55;
    case 10: return serendip ? MSH_TRI_30 : MSH_TRI_66;
    default : Msg::Error("triangle order %i unknown", order); return 0;
    }
    break;
  case TYPE_QUA :
    switch(order) {
    case 0 : return MSH_QUA_1;
    case 1 : return MSH_QUA_4;
    case 2 : return serendip ? MSH_QUA_8  : MSH_QUA_9;
    case 3 : return serendip ? MSH_QUA_12 : MSH_QUA_16;
    case 4 : return serendip ? MSH_QUA_16I: MSH_QUA_25;
    case 5 : return serendip ? MSH_QUA_20 : MSH_QUA_36;
    case 6 : return serendip ? MSH_QUA_24 : MSH_QUA_49;
    case 7 : return serendip ? MSH_QUA_28 : MSH_QUA_64;
    case 8 : return serendip ? MSH_QUA_32 : MSH_QUA_81;
    case 9 : return serendip ? MSH_QUA_36I: MSH_QUA_100;
    case 10: return serendip ? MSH_QUA_40 : MSH_QUA_121;
    default : Msg::Error("quad order %i unknown", order); return 0;
    }
    break;
  case TYPE_TET :
    switch(order) {
    case 0 : return MSH_TET_1;
    case 1 : return MSH_TET_4;
    case 2 : return MSH_TET_10;
    case 3 : return MSH_TET_20;
    case 4 : return serendip ? MSH_TET_34 : MSH_TET_35;
    case 5 : return serendip ? MSH_TET_52 : MSH_TET_56;
    case 6 : return serendip ? MSH_TET_74 : MSH_TET_84;
    case 7 : return serendip ? MSH_TET_100: MSH_TET_120;
    case 8 : return serendip ? MSH_TET_130: MSH_TET_165;
    case 9 : return serendip ? MSH_TET_164: MSH_TET_220;
    case 10: return serendip ? MSH_TET_202: MSH_TET_286;
    default : Msg::Error("terahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_HEX :
    switch(order) {
    case 0 : return MSH_HEX_1;
    case 1 : return MSH_HEX_8;
    case 2 : return serendip ? MSH_HEX_20 : MSH_HEX_27;
    case 3 : return serendip ? MSH_HEX_56 : MSH_HEX_64;
    case 4 : return serendip ? MSH_HEX_98 : MSH_HEX_125;
    case 5 : return serendip ? MSH_HEX_152: MSH_HEX_216;
    case 6 : return serendip ? MSH_HEX_222: MSH_HEX_343;
    case 7 : return serendip ? MSH_HEX_296: MSH_HEX_512;
    case 8 : return serendip ? MSH_HEX_386: MSH_HEX_729;
    case 9 : return serendip ? MSH_HEX_488: MSH_HEX_1000;
    default : Msg::Error("hexahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_PRI :
    switch(order) {
    case 0 : return MSH_PRI_1;
    case 1 : return MSH_PRI_6;
    case 2 : return serendip ? MSH_PRI_15 : MSH_PRI_18;
    case 3 : return serendip ? MSH_PRI_38 : MSH_PRI_40;
    case 4 : return serendip ? MSH_PRI_66 : MSH_PRI_75;
    case 5 : return serendip ? MSH_PRI_102 : MSH_PRI_126;
    case 6 : return serendip ? MSH_PRI_146 : MSH_PRI_196;
    case 7 : return serendip ? MSH_PRI_198 : MSH_PRI_288;
    case 8 : return serendip ? MSH_PRI_258 : MSH_PRI_405;
    case 9 : return serendip ? MSH_PRI_326 : MSH_PRI_550;
    default : Msg::Error("prism order %i unknown", order); return 0;
    }
    break;
  case TYPE_PYR :
    switch(order) {
    case 0 : return MSH_PYR_1;
    case 1 : return MSH_PYR_5;
    case 2 : return serendip ? MSH_PYR_13 : MSH_PYR_14;
    case 3: return serendip ? MSH_PYR_29 : MSH_PYR_30;
    case 4: return serendip ? MSH_PYR_50 : MSH_PYR_55;
    case 5: return serendip ? MSH_PYR_77 : MSH_PYR_91;
    case 6: return serendip ? MSH_PYR_110 : MSH_PYR_140;
    case 7: return serendip ? MSH_PYR_149 : MSH_PYR_204;
    case 8: return serendip ? MSH_PYR_194 : MSH_PYR_285;
    case 9: return serendip ? MSH_PYR_245 : MSH_PYR_385;
    default : Msg::Error("pyramid order %i unknown", order); return 0;
    }
    break;
  default : Msg::Error("unknown element type %i", parentTag); return 0;
  }
}



#endif
