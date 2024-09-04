// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth, Ivo Dolezel, Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include <algorithm>
#include <stdexcept>
#include "HierarchicalBasisH1Brick.h"

HierarchicalBasisH1Brick::HierarchicalBasisH1Brick(int order)
{
  _pb1 = order;
  _pb2 = order;
  _pb3 = order;
  for(int i = 0; i < 12; i++) { _pOrderEdge[i] = order; }
  for(int j = 0; j < 6; j++) {
    _pOrderFace1[j] = order;
    _pOrderFace2[j] = order;
  }
  _nvertex = 8;
  _nedge = 12;
  _nfaceQuad = 6;
  _nfaceTri = 0;
  _nVertexFunction = 8;
  _nEdgeFunction = 12 * order - 12;
  _nQuadFaceFunction = 6 * (order - 1) * (order - 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = (order - 1) * (order - 1) * (order - 1);
}

HierarchicalBasisH1Brick::~HierarchicalBasisH1Brick() {}

unsigned int HierarchicalBasisH1Brick::getNumberOfOrientations() const
{
  return 40320; // factorial 8
}

double HierarchicalBasisH1Brick::_affineCoordinate(const int &j,
                                                   const double &u,
                                                   const double &v,
                                                   const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  case(3): return 0.5 * (1 + v);
  case(4): return 0.5 * (1 - v);
  case(5): return 0.5 * (1 + w);
  case(6): return 0.5 * (1 - w);
  default: throw std::runtime_error("j must be : 1<=j<=6");
  }
}
inline void HierarchicalBasisH1Brick::_someProduct(double const &u,
                                                   double const &v,
                                                   double const &w,
                                                   std::vector<double> &product,
                                                   std::vector<double> &lambda)
{
  lambda[0] = _affineCoordinate(1, u, v, w);
  lambda[1] = _affineCoordinate(2, u, v, w);
  lambda[2] = _affineCoordinate(3, u, v, w);
  lambda[3] = _affineCoordinate(4, u, v, w);
  lambda[4] = _affineCoordinate(5, u, v, w);
  lambda[5] = _affineCoordinate(6, u, v, w);
  product[0] = lambda[3] * lambda[5];
  product[1] = lambda[1] * lambda[5];
  product[2] = lambda[1] * lambda[3];
  product[3] = lambda[0] * lambda[5];
  product[4] = lambda[3] * lambda[0];
  product[5] = lambda[2] * lambda[5];
  product[6] = lambda[2] * lambda[0];
  product[7] = lambda[2] * lambda[1];
  product[8] = lambda[3] * lambda[4];
  product[9] = lambda[4] * lambda[1];
  product[10] = lambda[4] * lambda[0];
  product[11] = lambda[4] * lambda[2];
}
void HierarchicalBasisH1Brick::generateBasis(double const &u, double const &v,
                                             double const &w,
                                             std::vector<double> &vertexBasis,
                                             std::vector<double> &edgeBasis,
                                             std::vector<double> &faceBasis,
                                             std::vector<double> &bubbleBasis)
{
  std::vector<double> product(12, 0);
  std::vector<double> lambda(6, 0);
  HierarchicalBasisH1Brick::_someProduct(u, v, w, product, lambda);
  // vertex shape functions:
  vertexBasis[0] = lambda[1] * product[0];
  vertexBasis[1] = lambda[0] * product[0];
  vertexBasis[2] = lambda[0] * product[5];
  vertexBasis[3] = lambda[1] * product[5];
  vertexBasis[4] = lambda[1] * product[8];
  vertexBasis[5] = lambda[0] * product[8];
  vertexBasis[6] = lambda[0] * product[11];
  vertexBasis[7] = lambda[1] * product[11];
  std::vector<double> lkVectorU(_pb1 - 1);
  std::vector<double> lkVectorV(_pb2 - 1);
  std::vector<double> lkVectorW(_pb3 - 1);
  for(int it = 2; it <= _pb1; it++) {
    lkVectorU[it - 2] = OrthogonalPoly::EvalLobatto(it, u);
  }
  for(int it = 2; it <= _pb2; it++) {
    lkVectorV[it - 2] = OrthogonalPoly::EvalLobatto(it, v);
  }
  for(int it = 2; it <= _pb3; it++) {
    lkVectorW[it - 2] = OrthogonalPoly::EvalLobatto(it, w);
  }
  // edge shape functions:
  int indexEdgeBasis = 0;
  std::vector<double> *vectorTarget1(nullptr);
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    switch(iEdge) {
    case(0):
    case(5):
    case(8):
    case(11): vectorTarget1 = &lkVectorU; break;
    case(1):
    case(3):
    case(9):
    case(10): vectorTarget1 = &lkVectorV; break;
    case(2):
    case(4):
    case(6):
    case(7): vectorTarget1 = &lkVectorW; break;
    }
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      edgeBasis[indexEdgeBasis] =
        (*vectorTarget1)[indexEdgeFunc] * product[iEdge];
      indexEdgeBasis++;
    }
  }
  // face shape functions:
  int indexFaceFunction = 0;
  std::vector<double> *vectorTarget2(nullptr);
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int indexLambda;
    switch(iFace) {
    case(0):
      indexLambda = 5;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorV;
      break;
    case(1):
      indexLambda = 3;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorW;
      break;
    case(2):
      indexLambda = 1;
      vectorTarget1 = &lkVectorV;
      vectorTarget2 = &lkVectorW;
      break;
    case(3):
      indexLambda = 0;
      vectorTarget1 = &lkVectorV;
      vectorTarget2 = &lkVectorW;
      break;
    case(4):
      indexLambda = 2;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorW;
      break;
    case(5):
      indexLambda = 4;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorV;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] - 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] - 1; index2++) {
        faceBasis[indexFaceFunction] = lambda[indexLambda] *
                                       (*vectorTarget1)[index1] *
                                       (*vectorTarget2)[index2];
        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1 - 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 - 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 - 1; ipb3++) {
        bubbleBasis[indexBubbleBasis] =
          lkVectorU[ipb1] * lkVectorV[ipb2] * lkVectorW[ipb3];
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisH1Brick::_someProductGrad(
  double const &u, double const &v, double const &w,
  std::vector<double> &product,
  std::vector<std::vector<double> > &gradientProduct,
  std::vector<double> &lambda,
  std::vector<std::vector<double> > &gradientLambda)
{
  lambda[0] = _affineCoordinate(1, u, v, w);
  lambda[1] = _affineCoordinate(2, u, v, w);
  lambda[2] = _affineCoordinate(3, u, v, w);
  lambda[3] = _affineCoordinate(4, u, v, w);
  lambda[4] = _affineCoordinate(5, u, v, w);
  lambda[5] = _affineCoordinate(6, u, v, w);
  gradientLambda[0][0] = 0.5;
  gradientLambda[1][0] = -0.5;
  gradientLambda[2][1] = 0.5;
  gradientLambda[3][1] = -0.5;
  gradientLambda[4][2] = 0.5;
  gradientLambda[5][2] = -0.5;
  product[0] = lambda[3] * lambda[5];
  product[1] = lambda[1] * lambda[5];
  product[2] = lambda[1] * lambda[3];
  product[3] = lambda[0] * lambda[5];
  product[4] = lambda[3] * lambda[0];
  product[5] = lambda[2] * lambda[5];
  product[6] = lambda[2] * lambda[0];
  product[7] = lambda[2] * lambda[1];
  product[8] = lambda[3] * lambda[4];
  product[9] = lambda[4] * lambda[1];
  product[10] = lambda[4] * lambda[0];
  product[11] = lambda[4] * lambda[2];
  gradientProduct[0][1] = -0.5 * lambda[5];
  gradientProduct[0][2] = -0.5 * lambda[3];
  gradientProduct[1][0] = -0.5 * lambda[5];
  gradientProduct[1][2] = -0.5 * lambda[1];
  gradientProduct[2][0] = -0.5 * lambda[3];
  gradientProduct[2][1] = -0.5 * lambda[1];
  gradientProduct[3][0] = 0.5 * lambda[5];
  gradientProduct[3][2] = -0.5 * lambda[0];
  gradientProduct[4][0] = 0.5 * lambda[3];
  gradientProduct[4][1] = -0.5 * lambda[0];
  gradientProduct[5][1] = 0.5 * lambda[5];
  gradientProduct[5][2] = -0.5 * lambda[2];
  gradientProduct[6][0] = 0.5 * lambda[2];
  gradientProduct[6][1] = 0.5 * lambda[0];
  gradientProduct[7][0] = -0.5 * lambda[2];
  gradientProduct[7][1] = 0.5 * lambda[1];
  gradientProduct[8][1] = -0.5 * lambda[4];
  gradientProduct[8][2] = 0.5 * lambda[3];
  gradientProduct[9][0] = -0.5 * lambda[4];
  gradientProduct[9][2] = 0.5 * lambda[1];
  gradientProduct[10][0] = 0.5 * lambda[4];
  gradientProduct[10][2] = 0.5 * lambda[0];
  gradientProduct[11][1] = 0.5 * lambda[4];
  gradientProduct[11][2] = 0.5 * lambda[2];
}

void HierarchicalBasisH1Brick::generateGradientBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &gradientVertex,
  std::vector<std::vector<double> > &gradientEdge,
  std::vector<std::vector<double> > &gradientFace,
  std::vector<std::vector<double> > &gradientBubble)
{
  std::vector<double> product(12, 0);
  std::vector<std::vector<double> > gradientProduct(12,
                                                    std::vector<double>(3, 0));
  std::vector<double> lambda(6, 0);
  std::vector<std::vector<double> > gradientLambda(6,
                                                   std::vector<double>(3, 0));
  HierarchicalBasisH1Brick::_someProductGrad(u, v, w, product, gradientProduct,
                                             lambda, gradientLambda);
  // vertex gradient:
  for(int it = 0; it < 3; it++) {
    gradientVertex[0][it] =
      gradientLambda[1][it] * product[0] + gradientProduct[0][it] * lambda[1];
    gradientVertex[1][it] =
      gradientLambda[0][it] * product[0] + gradientProduct[0][it] * lambda[0];
    gradientVertex[2][it] =
      gradientLambda[0][it] * product[5] + gradientProduct[5][it] * lambda[0];
    gradientVertex[3][it] =
      gradientLambda[1][it] * product[5] + gradientProduct[5][it] * lambda[1];
    gradientVertex[4][it] =
      gradientLambda[1][it] * product[8] + gradientProduct[8][it] * lambda[1];
    gradientVertex[5][it] =
      gradientLambda[0][it] * product[8] + gradientProduct[8][it] * lambda[0];
    gradientVertex[6][it] =
      gradientLambda[0][it] * product[11] + gradientProduct[11][it] * lambda[0];
    gradientVertex[7][it] =
      gradientLambda[1][it] * product[11] + gradientProduct[11][it] * lambda[1];
  }
  std::vector<double> lkVectorU(_pb1 - 1);
  std::vector<double> lkVectorV(_pb2 - 1);
  std::vector<double> lkVectorW(_pb3 - 1);
  std::vector<std::vector<double> > dlkVectorU(_pb1 - 1,
                                               std::vector<double>(3, 0.));
  std::vector<std::vector<double> > dlkVectorV(_pb2 - 1,
                                               std::vector<double>(3, 0.));
  std::vector<std::vector<double> > dlkVectorW(_pb3 - 1,
                                               std::vector<double>(3, 0.));
  for(int it = 2; it <= _pb1; it++) {
    lkVectorU[it - 2] = OrthogonalPoly::EvalLobatto(it, u);
    dlkVectorU[it - 2][0] = OrthogonalPoly::EvalDLobatto(it, u);
  }
  for(int it = 2; it <= _pb2; it++) {
    lkVectorV[it - 2] = OrthogonalPoly::EvalLobatto(it, v);
    dlkVectorV[it - 2][1] = OrthogonalPoly::EvalDLobatto(it, v);
  }
  for(int it = 2; it <= _pb3; it++) {
    lkVectorW[it - 2] = OrthogonalPoly::EvalLobatto(it, w);
    dlkVectorW[it - 2][2] = OrthogonalPoly::EvalDLobatto(it, w);
  }
  // edge gradient:
  int indexEdgeBasis = 0;
  std::vector<double> *vectorTarget1(nullptr);
  std::vector<std::vector<double> > *dvectorTarget1(nullptr);
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    switch(iEdge) {
    case(0):
    case(5):
    case(8):
    case(11):
      vectorTarget1 = &lkVectorU;
      dvectorTarget1 = &dlkVectorU;
      break;
    case(1):
    case(3):
    case(9):
    case(10):
      vectorTarget1 = &lkVectorV;
      dvectorTarget1 = &dlkVectorV;
      break;
    case(2):
    case(4):
    case(6):
    case(7):
      vectorTarget1 = &lkVectorW;
      dvectorTarget1 = &dlkVectorW;
      break;
    }
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      for(int it = 0; it < 3; it++) {
        gradientEdge[indexEdgeBasis][it] =
          (*dvectorTarget1)[indexEdgeFunc][it] * product[iEdge] +
          (*vectorTarget1)[indexEdgeFunc] * gradientProduct[iEdge][it];
      }
      indexEdgeBasis++;
    }
  }
  // face gradient:
  int indexFaceFunction = 0;
  std::vector<double> *vectorTarget2(nullptr);
  std::vector<std::vector<double> > *dvectorTarget2(nullptr);
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int indexLambda = 0;
    switch(iFace) {
    case(0):
      indexLambda = 5;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorV;
      dvectorTarget1 = &dlkVectorU;
      dvectorTarget2 = &dlkVectorV;
      break;
    case(1):
      indexLambda = 3;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorW;
      dvectorTarget1 = &dlkVectorU;
      dvectorTarget2 = &dlkVectorW;
      break;
    case(2):
      indexLambda = 1;
      vectorTarget1 = &lkVectorV;
      vectorTarget2 = &lkVectorW;
      dvectorTarget1 = &dlkVectorV;
      dvectorTarget2 = &dlkVectorW;
      break;
    case(3):
      indexLambda = 0;
      vectorTarget1 = &lkVectorV;
      vectorTarget2 = &lkVectorW;
      dvectorTarget1 = &dlkVectorV;
      dvectorTarget2 = &dlkVectorW;
      break;
    case(4):
      indexLambda = 2;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorW;
      dvectorTarget1 = &dlkVectorU;
      dvectorTarget2 = &dlkVectorW;
      break;
    case(5):
      indexLambda = 4;
      vectorTarget1 = &lkVectorU;
      vectorTarget2 = &lkVectorV;
      dvectorTarget1 = &dlkVectorU;
      dvectorTarget2 = &dlkVectorV;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] - 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] - 1; index2++) {
        for(int it = 0; it < 3; it++) {
          gradientFace[indexFaceFunction][it] =
            gradientLambda[indexLambda][it] * (*vectorTarget1)[index1] *
              (*vectorTarget2)[index2] +
            lambda[indexLambda] * (*dvectorTarget1)[index1][it] *
              (*vectorTarget2)[index2] +
            lambda[indexLambda] * (*vectorTarget1)[index1] *
              (*dvectorTarget2)[index2][it];
        }
        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1 - 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 - 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 - 1; ipb3++) {
        gradientBubble[indexBubbleBasis][0] =
          dlkVectorU[ipb1][0] * lkVectorV[ipb2] * lkVectorW[ipb3];
        gradientBubble[indexBubbleBasis][1] =
          lkVectorU[ipb1] * dlkVectorV[ipb2][1] * lkVectorW[ipb3];
        gradientBubble[indexBubbleBasis][2] =
          lkVectorU[ipb1] * lkVectorV[ipb2] * dlkVectorW[ipb3][2];
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisH1Brick::orientEdge(
  int const &flagOrientation, int const &edgeNumber,
  std::vector<double> &edgeFunctions,
  const std::vector<double> &eTablePositiveFlag,
  const std::vector<double> &eTableNegativeFlag)
{
  if(flagOrientation == -1) {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k] = eTableNegativeFlag[k];
    }
  }
  else {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k] = eTablePositiveFlag[k];
    }
  }
}

void HierarchicalBasisH1Brick::orientEdge(
  int const &flagOrientation, int const &edgeNumber,
  std::vector<std::vector<double> > &edgeFunctions,
  const std::vector<std::vector<double> > &eTablePositiveFlag,
  const std::vector<std::vector<double> > &eTableNegativeFlag)
{
  if(flagOrientation == -1) {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTableNegativeFlag[k][0];
      edgeFunctions[k][1] = eTableNegativeFlag[k][1];
      edgeFunctions[k][2] = eTableNegativeFlag[k][2];
    }
  }
  else {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTablePositiveFlag[k][0];
      edgeFunctions[k][1] = eTablePositiveFlag[k][1];
      edgeFunctions[k][2] = eTablePositiveFlag[k][2];
    }
  }
}

void HierarchicalBasisH1Brick::orientEdgeFunctionsForNegativeFlag(
  std::vector<double> &edgeFunctions)
{
  int constant1 = 0;
  int constant2 = 0;
  for(int edgeNumber = 0; edgeNumber < _nedge; edgeNumber++) {
    constant2 = 0;
    constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      if((k - constant1) % 2 != 0) {
        edgeFunctions[k] = edgeFunctions[k] * (-1);
      }
    }
  }
}

void HierarchicalBasisH1Brick::orientEdgeFunctionsForNegativeFlag(
  std::vector<std::vector<double> > &edgeFunctions)
{
  int constant1 = 0;
  int constant2 = 0;
  for(int edgeNumber = 0; edgeNumber < _nedge; edgeNumber++) {
    constant2 = 0;
    constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] - 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber] + 2;
    for(int k = constant1; k <= constant2; k++) {
      if((k - constant1) % 2 != 0) {
        edgeFunctions[k][0] = edgeFunctions[k][0] * (-1);
        edgeFunctions[k][1] = edgeFunctions[k][1] * (-1);
        edgeFunctions[k][2] = edgeFunctions[k][2] * (-1);
      }
    }
  }
}

void HierarchicalBasisH1Brick::orientOneFace(double const &u, double const &v,
                                             double const &w, int const &flag1,
                                             int const &flag2, int const &flag3,
                                             int const &faceNumber,
                                             std::vector<double> &faceBasis)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderFace1[i] - 1) * (_pOrderFace2[i] - 1);
    }
    if(flag3 == 1) {
      for(int it1 = 2; it1 <= _pOrderFace1[faceNumber]; it1++) {
        for(int it2 = 2; it2 <= _pOrderFace2[faceNumber]; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          faceBasis[iterator] = faceBasis[iterator] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
    else {
      double lambda = 0;
      double var1 = 0;
      double var2 = 0;
      switch(faceNumber) {
      case(0):
        lambda = _affineCoordinate(6, u, v, w);
        var1 = u;
        var2 = v;
        break;
      case(1):
        lambda = _affineCoordinate(4, u, v, w);
        var1 = u;
        var2 = w;
        break;
      case(2):
        lambda = _affineCoordinate(2, u, v, w);
        var1 = v;
        var2 = w;
        break;
      case(3):
        lambda = _affineCoordinate(1, u, v, w);
        var1 = v;
        var2 = w;
        break;
      case(4):
        lambda = _affineCoordinate(3, u, v, w);
        var1 = u;
        var2 = w;
        break;
      case(5):
        lambda = _affineCoordinate(5, u, v, w);
        var1 = u;
        var2 = v;
        break;
      }
      std::vector<double> lkVector1(_pOrderFace1[faceNumber] - 1);
      std::vector<double> lkVector2(_pOrderFace2[faceNumber] - 1);
      for(int it = 2; it <= _pOrderFace1[faceNumber]; it++) {
        lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, var1);
      }
      for(int it = 2; it <= _pOrderFace2[faceNumber]; it++) {
        lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, var2);
      }

      for(int it1 = 2; it1 <= _pOrderFace2[faceNumber]; it1++) {
        for(int it2 = 2; it2 <= _pOrderFace1[faceNumber]; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          faceBasis[iterator] = lambda * lkVector1[it2 - 2] *
                                lkVector2[it1 - 2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
  }
}
void HierarchicalBasisH1Brick::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &gradientFace, std::string typeFunction)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderFace1[i] - 1) * (_pOrderFace2[i] - 1);
    }
    if(flag3 == 1) {
      for(int it1 = 2; it1 <= _pOrderFace1[faceNumber]; it1++) {
        for(int it2 = 2; it2 <= _pOrderFace2[faceNumber]; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          gradientFace[iterator][0] =
            gradientFace[iterator][0] * impactFlag1 * impactFlag2;
          gradientFace[iterator][1] =
            gradientFace[iterator][1] * impactFlag1 * impactFlag2;
          gradientFace[iterator][2] =
            gradientFace[iterator][2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
    else {
      std::vector<double> uvw(3);
      uvw[0] = u;
      uvw[1] = v;
      uvw[2] = w;
      double lambda = 0;
      int var1 = 0;
      int var2 = 0;
      std::vector<double> gradientLambda(3, 0);
      switch(faceNumber) {
      case(0):
        lambda = _affineCoordinate(6, u, v, w);
        var1 = 0;
        var2 = 1;
        gradientLambda[2] = -0.5;
        break;
      case(1):
        lambda = _affineCoordinate(4, u, v, w);
        var1 = 0;
        var2 = 2;
        gradientLambda[1] = -0.5;
        break;
      case(2):
        lambda = _affineCoordinate(2, u, v, w);
        var1 = 1;
        var2 = 2;
        gradientLambda[0] = -0.5;
        break;
      case(3):
        lambda = _affineCoordinate(1, u, v, w);
        var1 = 1;
        var2 = 2;
        gradientLambda[0] = 0.5;
        break;
      case(4):
        lambda = _affineCoordinate(3, u, v, w);
        var1 = 0;
        var2 = 2;
        gradientLambda[1] = 0.5;
        break;
      case(5):
        lambda = _affineCoordinate(5, u, v, w);
        var1 = 0;
        var2 = 1;
        gradientLambda[2] = 0.5;
        break;
      }
      std::vector<double> lkVector1(_pOrderFace1[faceNumber] - 1);
      std::vector<double> lkVector2(_pOrderFace2[faceNumber] - 1);
      std::vector<std::vector<double> > dlkVector1(_pOrderFace1[faceNumber] - 1,
                                                   std::vector<double>(3, 0.));
      std::vector<std::vector<double> > dlkVector2(_pOrderFace2[faceNumber] - 1,
                                                   std::vector<double>(3, 0.));
      for(int it = 2; it <= _pOrderFace1[faceNumber]; it++) {
        lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[var1]);
        dlkVector1[it - 2][var1] = OrthogonalPoly::EvalDLobatto(it, uvw[var1]);
      }
      for(int it = 2; it <= _pOrderFace2[faceNumber]; it++) {
        lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[var2]);
        dlkVector2[it - 2][var2] = OrthogonalPoly::EvalDLobatto(it, uvw[var2]);
      }
      for(int it1 = 2; it1 <= _pOrderFace2[faceNumber]; it1++) {
        for(int it2 = 2; it2 <= _pOrderFace1[faceNumber]; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          for(int itVector = 0; itVector < 3; itVector++) {
            gradientFace[iterator][itVector] =
              (gradientLambda[itVector] * lkVector1[it2 - 2] *
                 lkVector2[it1 - 2] +
               lambda * dlkVector1[it2 - 2][itVector] * lkVector2[it1 - 2] +
               lambda * lkVector1[it2 - 2] * dlkVector2[it1 - 2][itVector]) *
              impactFlag1 * impactFlag2;
          }
          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisH1Brick::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<double> &quadFaceFunctionsAllOrientation,
  const std::vector<double> &triFaceFunctionsAllOrientation,
  std::vector<double> &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += (_pOrderFace1[i] - 1) * (_pOrderFace2[i] - 1);
  }
  int numFaceFunctions =
    (_pOrderFace1[faceNumber] - 1) * (_pOrderFace2[faceNumber] - 1);
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];
  }
}
void HierarchicalBasisH1Brick::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += (_pOrderFace1[i] - 1) * (_pOrderFace2[i] - 1);
  }
  int numFaceFunctions =
    (_pOrderFace1[faceNumber] - 1) * (_pOrderFace2[faceNumber] - 1);
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisH1Brick::getKeysInfo(std::vector<int> &functionTypeInfo,
                                           std::vector<int> &orderInfo)
{
  for(int i = 0; i < 8; i++) {
    functionTypeInfo[i] = 0;
    orderInfo[i] = 1;
  }
  int it = 8;
  for(int numEdge = 0; numEdge < 12; numEdge++) {
    for(int i = 2; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int numFace = 0; numFace < 6; numFace++) {
    for(int n1 = 2; n1 <= _pOrderFace1[numFace]; n1++) {
      for(int n2 = 2; n2 <= _pOrderFace2[numFace]; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
        it++;
      }
    }
  }
  for(int ipb1 = 2; ipb1 <= _pb1; ipb1++) {
    for(int ipb2 = 2; ipb2 <= _pb2; ipb2++) {
      for(int ipb3 = 2; ipb3 <= _pb3; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
}
