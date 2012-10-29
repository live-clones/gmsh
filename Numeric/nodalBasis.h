// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef BASIS_H
#define BASIS_H

#include "fullMatrix.h"
#include "GmshDefines.h"

class nodalBasis {

 public:
  int type, parentType, order, dimension, numFaces;
  bool serendip;
  fullMatrix<double> points;

  virtual void initialize() {};

  // Basis functions evaluation
  inline virtual void f(double u, double v, double w, double *sf) const {};
  inline void f(fullMatrix<double> &coord, fullMatrix<double> &sf) const {};

  // Basis functions gradients evaluation
  inline virtual void df(double u, double v, double w, double grads[][3]) const {};
  inline void df(fullMatrix<double> &coord, fullMatrix<double> &dfm) const {};
  
  inline void ddf(double u, double v, double w, double grads[][3][3]) const {};
  inline void dddf(double u, double v, double w, double grads[][3][3][3]) const {};

  inline virtual int getNumShapeFunctions() const {Msg::Fatal("Not implemented"); return -1;}

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
  inline virtual int getClosureType(int id) const {Msg::Fatal("Not implemented"); return -1;}
  inline virtual const std::vector<int> &getClosure(int id) const {Msg::Fatal("Not implemented"); std::vector<int> *ret=NULL; return *ret;}
  inline virtual const std::vector<int> &getFullClosure(int id) const {Msg::Fatal("Not implemented"); std::vector<int> *ret=NULL; return *ret;}
  inline virtual int getClosureId(int iFace, int iSign=1, int iRot=0) const {Msg::Fatal("Not implemented"); return -1;}
  inline void breakClosureId(int i, int &iFace, int &iSign, int &iRot) const {Msg::Fatal("Not implemented");iFace=-1; iSign=-1; iRot=-1;}

  static int getTag(int parentTag, int order, bool serendip = false)
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
    case TYPE_HEX :
      switch(order) {
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
    case TYPE_PRI :
      switch(order) {
      case 0 : return MSH_PRI_1;
      case 1 : return MSH_PRI_6;
      case 2 : return MSH_PRI_18;
      default : Msg::Error("prism order %i unknown", order); return 0;
      }
    default : Msg::Error("unknown element type %i", parentTag); return 0;
    }
  }
  
};
#endif
