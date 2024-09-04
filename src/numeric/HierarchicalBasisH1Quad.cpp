// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

#include <stdexcept>
#include "HierarchicalBasisH1Quad.h"

HierarchicalBasisH1Quad::HierarchicalBasisH1Quad(int pf1, int pf2, int pe0,
                                                 int pe1, int pe2, int pe3)

{
  _nvertex = 4;
  _nedge = 4;
  _nfaceQuad = 1;
  _nfaceTri = 0;
  _nVertexFunction = 4;
  _nEdgeFunction = pe0 + pe1 + pe2 + pe3 - 4;
  _nQuadFaceFunction = (pf1 - 1) * (pf2 - 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = 0;
  _pf1 = pf1;
  _pf2 = pf2;
  if(pe1 > pf2 || pe3 > pf2) {
    throw std::runtime_error("pe1 and pe3 must be <=pf2");
  }
  if(pe0 > pf1 || pe2 > pf1) {
    throw std::runtime_error("pe0  and pe2  must be <=pf1");
  }
  _pOrderEdge[0] = pe0;
  _pOrderEdge[1] = pe1;
  _pOrderEdge[2] = pe2;
  _pOrderEdge[3] = pe3;
}
HierarchicalBasisH1Quad::HierarchicalBasisH1Quad(int order)

{
  _nvertex = 4;
  _nedge = 4;
  _nfaceQuad = 1;
  _nfaceTri = 0;
  _nVertexFunction = 4;
  _nEdgeFunction = 4 * order - 4;
  _nQuadFaceFunction = (order - 1) * (order - 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = 0;
  _pf1 = order;
  _pf2 = order;
  _pOrderEdge[0] = order;
  _pOrderEdge[1] = order;
  _pOrderEdge[2] = order;
  _pOrderEdge[3] = order;
}

HierarchicalBasisH1Quad::~HierarchicalBasisH1Quad() {}

unsigned int HierarchicalBasisH1Quad::getNumberOfOrientations() const
{
  return 24; // factorial 4
}

double HierarchicalBasisH1Quad::_affineCoordinate(int const &j, double const &u,
                                                  double const &v)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  case(3): return 0.5 * (1 + v);
  case(4): return 0.5 * (1 - v);
  default: throw std::runtime_error("j must be : 1<=j<=4");
  }
}

void HierarchicalBasisH1Quad::generateBasis(double const &u, double const &v,
                                            double const &w,
                                            std::vector<double> &vertexBasis,
                                            std::vector<double> &edgeBasis,
                                            std::vector<double> &faceBasis,
                                            std::vector<double> &bubbleBasis)
{
  double lambda1 = _affineCoordinate(1, u, v);
  double lambda2 = _affineCoordinate(2, u, v);
  double lambda3 = _affineCoordinate(3, u, v);
  double lambda4 = _affineCoordinate(4, u, v);
  // vertex shape functions:
  vertexBasis[0] = lambda2 * lambda4;
  vertexBasis[1] = lambda1 * lambda4;
  vertexBasis[2] = lambda1 * lambda3;
  vertexBasis[3] = lambda2 * lambda3;
  // edge 0  & 2 shape functions and a part of face functions (all lk(u)):
  int minpe0pe2 = std::min(_pOrderEdge[0], _pOrderEdge[2]);
  int const1 = _pOrderEdge[0] + _pOrderEdge[1] - 4;
  for(int k = 2; k <= minpe0pe2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double phie0 = lambda4 * lk;
    double phie2 = lambda3 * lk;
    int const2 = k - 2;
    edgeBasis[const2] = phie0;
    edgeBasis[k + const1] = phie2;
    int const3 = _pf2 - 1;
    int iterator = 0;
    while(iterator < const3) {
      int nbr = const2 * const3 + iterator;
      faceBasis[nbr] = lk;
      iterator++;
    }
  }
  if(_pOrderEdge[0] > minpe0pe2) {
    for(int k = minpe0pe2 + 1; k <= _pOrderEdge[0]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double phie0 = lambda4 * lk;
      int const2 = k - 2;
      edgeBasis[const2] = phie0;
      int const3 = _pf2 - 1;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = const2 * const3 + iterator;
        faceBasis[nbr] = lk;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe0pe2 + 1; k <= _pOrderEdge[2]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double phie2 = lambda3 * lk;
      edgeBasis[k + const1] = phie2;
      int iterator = 0;
      int const3 = _pf2 - 1;
      while(iterator < const3) {
        int nbr = (k - 2) * const3 + iterator;
        faceBasis[nbr] = lk;
        iterator++;
      }
    }
  }
  int maxpe0pe2 = std::max(_pOrderEdge[0], _pOrderEdge[2]);
  for(int k = maxpe0pe2 + 1; k <= _pf1; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    int iterator = 0;
    int const3 = _pf2 - 1;
    while(iterator < const3) {
      int nbr = (k - 2) * const3 + iterator;
      faceBasis[nbr] = lk;
      iterator++;
    }
  }
  // edge 1 & 3 shape functions and a part of  face functions (all lk(v)) :
  int minpe1pe3 = std::min(_pOrderEdge[1], _pOrderEdge[3]);
  int const3 = _pOrderEdge[0] - 3;
  int const4 = _pOrderEdge[0] + _pOrderEdge[1] + _pOrderEdge[2] - 5;
  for(int k = 2; k <= minpe1pe3; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double phie3 = lambda2 * lk;
    double phie1 = lambda1 * lk;
    edgeBasis[k + const3] = phie1;
    edgeBasis[k + const4] = phie3;
    int s = k - 2;
    int iterator = 1;
    while(iterator <= _pf1 - 1) {
      faceBasis[s] = faceBasis[s] * lk;
      s = s + _pf2 - 1;
      iterator++;
    }
  }
  if(_pOrderEdge[1] > minpe1pe3) {
    for(int k = minpe1pe3 + 1; k <= _pOrderEdge[1]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double phie1 = lambda1 * lk;
      edgeBasis[k + const3] = phie1;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= _pf1 - 1) {
        faceBasis[s] = faceBasis[s] * lk;
        s = s + _pf2 - 1;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe1pe3 + 1; k <= _pOrderEdge[3]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double phie3 = lambda2 * lk;
      edgeBasis[k + const4] = phie3;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= _pf1 - 1) {
        faceBasis[s] = faceBasis[s] * lk;
        s = s + _pf2 - 1;
        iterator++;
      }
    }
  }
  int maxpe1pe3 = std::max(_pOrderEdge[1], _pOrderEdge[3]);
  for(int k = maxpe1pe3 + 1; k <= _pf2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    int s = k - 2;
    int iterator = 1;
    while(iterator <= _pf1 - 1) {
      faceBasis[s] = faceBasis[s] * lk;
      s = s + _pf2 - 1;
      iterator++;
    }
  }
}

void HierarchicalBasisH1Quad::generateGradientBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &gradientVertex,
  std::vector<std::vector<double> > &gradientEdge,
  std::vector<std::vector<double> > &gradientFace,
  std::vector<std::vector<double> > &gradientBubble)
{
  double dlambda1 = 0.5;
  double dlambda2 = -0.5;
  double dlambda3 = 0.5;
  double dlambda4 = -0.5;
  double lambda1 = _affineCoordinate(1, u, v);
  double lambda2 = _affineCoordinate(2, u, v);
  double lambda3 = _affineCoordinate(3, u, v);
  double lambda4 = _affineCoordinate(4, u, v);
  // vertex gradient functions:
  gradientVertex[0][0] = dlambda2 * lambda4;
  gradientVertex[0][1] = lambda2 * dlambda4;
  gradientVertex[1][0] = dlambda1 * lambda4;
  gradientVertex[1][1] = lambda1 * dlambda4;
  gradientVertex[2][0] = dlambda1 * lambda3;
  gradientVertex[2][1] = lambda1 * dlambda3;
  gradientVertex[3][0] = dlambda2 * lambda3;
  gradientVertex[3][1] = lambda2 * dlambda3;
  // edge 0  & 2 gradient  and a part of face gradient  ( in the direction u
  // ):
  int const1 = _pOrderEdge[0] + _pOrderEdge[1] - 4;
  int minpe0pe2 = std::min(_pOrderEdge[0], _pOrderEdge[2]);
  for(int k = 2; k <= minpe0pe2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double dlk = OrthogonalPoly::EvalDLobatto(k, u);
    double dphie0U = lambda4 * dlk;
    double dphie0V = dlambda4 * lk;
    double dphie2U = lambda3 * dlk;
    double dphie2V = dlambda3 * lk;
    int const2 = k - 2;
    int const3 = _pf2 - 1;
    gradientEdge[const2][0] = dphie0U;
    gradientEdge[const2][1] = dphie0V;
    gradientEdge[k + const1][0] = dphie2U;
    gradientEdge[k + const1][1] = dphie2V;
    int iterator = 0;
    while(iterator < const3) {
      int nbr = const2 * const3 + iterator;
      gradientFace[nbr][0] = dlk;
      gradientFace[nbr][1] = lk;
      iterator++;
    }
  }
  if(_pOrderEdge[0] > minpe0pe2) {
    for(int k = minpe0pe2 + 1; k <= _pOrderEdge[0]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double dlk = OrthogonalPoly::EvalDLobatto(k, u);
      double dphie0U = lambda4 * dlk;
      double dphie0V = dlambda4 * lk;
      int const2 = k - 2;
      int const3 = _pf2 - 1;
      gradientEdge[const2][0] = dphie0U;
      gradientEdge[const2][1] = dphie0V;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = const2 * const3 + iterator;
        gradientFace[nbr][0] = dlk;
        gradientFace[nbr][1] = lk;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe0pe2 + 1; k <= _pOrderEdge[2]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double dlk = OrthogonalPoly::EvalDLobatto(k, u);
      double dphie2U = lambda3 * dlk;
      double dphie2V = dlambda3 * lk;
      gradientEdge[k + const1][0] = dphie2U;
      gradientEdge[k + const1][1] = dphie2V;
      int const3 = _pf2 - 1;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = (k - 2) * (const3) + iterator;
        gradientFace[nbr][0] = dlk;
        gradientFace[nbr][1] = lk;
        iterator++;
      }
    }
  }
  int maxpe0pe2 = std::max(_pOrderEdge[0], _pOrderEdge[2]);
  for(int k = maxpe0pe2 + 1; k <= _pf1; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double dlk = OrthogonalPoly::EvalDLobatto(k, u);
    int iterator = 1;
    while(iterator < _pf2) {
      int nbr = (k - 2) * (_pf2 - 1) + iterator;
      gradientFace[nbr][0] = dlk;
      gradientFace[nbr][1] = lk;
      iterator++;
    }
  }

  // edge 1 & 3 shape functions and a part of  face functions (all lk(v)) :
  int minpe1pe3 = std::min(_pOrderEdge[1], _pOrderEdge[3]);
  int const3 = _pOrderEdge[0] - 3;
  int const4 = _pOrderEdge[0] + _pOrderEdge[1] + _pOrderEdge[2] - 5;
  for(int k = 2; k <= minpe1pe3; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double dlk = OrthogonalPoly::EvalDLobatto(k, v);
    double dphie3U = dlambda2 * lk;
    double dphie3V = lambda2 * dlk;
    double dphie1U = dlambda1 * lk;
    double dphie1V = lambda1 * dlk;
    gradientEdge[k + const3][0] = dphie1U;
    gradientEdge[k + const3][1] = dphie1V;
    gradientEdge[k + const4][0] = dphie3U;
    gradientEdge[k + const4][1] = dphie3V;
    int s = k - 2;
    int iterator = 1;
    while(iterator <= _pf1 - 1) {
      gradientFace[s][0] = gradientFace[s][0] * lk;
      gradientFace[s][1] = gradientFace[s][1] * dlk;
      s = s + _pf2 - 1;
      iterator++;
    }
  }
  if(_pOrderEdge[1] > minpe1pe3) {
    for(int k = minpe1pe3 + 1; k <= _pOrderEdge[1]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double dlk = OrthogonalPoly::EvalDLobatto(k, v);
      double dphie1U = dlambda1 * lk;
      double dphie1V = lambda1 * dlk;
      gradientEdge[k + const3][0] = dphie1U;
      gradientEdge[k + const3][1] = dphie1V;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= _pf1 - 1) {
        gradientFace[s][0] = gradientFace[s][0] * lk;
        gradientFace[s][1] = gradientFace[s][1] * dlk;
        s = s + _pf2 - 1;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe1pe3 + 1; k <= _pOrderEdge[3]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double dlk = OrthogonalPoly::EvalDLobatto(k, v);
      double dphie3U = dlambda2 * lk;
      double dphie3V = lambda2 * dlk;
      gradientEdge[k + const4][0] = dphie3U;
      gradientEdge[k + const4][1] = dphie3V;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= _pf1 - 1) {
        gradientFace[s][0] = gradientFace[s][0] * lk;
        gradientFace[s][1] = gradientFace[s][1] * dlk;
        s = s + _pf2 - 1;
        iterator++;
      }
    }
  }
  int maxpe1pe3 = std::max(_pOrderEdge[1], _pOrderEdge[3]);
  for(int k = maxpe1pe3 + 1; k <= _pf2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double dlk = OrthogonalPoly::EvalDLobatto(k, v);
    int s = k - 2;
    int iterator = 1;
    while(iterator <= _pf1 - 1) {
      gradientFace[s][0] = gradientFace[s][0] * lk;
      gradientFace[s][1] = gradientFace[s][1] * dlk;
      s = s + _pf2 - 1;
      iterator++;
    }
  }
}

void HierarchicalBasisH1Quad::orientEdge(
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

void HierarchicalBasisH1Quad::orientEdge(
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
    }
  }
}

void HierarchicalBasisH1Quad::orientEdgeFunctionsForNegativeFlag(
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

void HierarchicalBasisH1Quad::orientEdgeFunctionsForNegativeFlag(
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
void HierarchicalBasisH1Quad::orientOneFace(double const &u, double const &v,
                                            double const &w, int const &flag1,
                                            int const &flag2, int const &flag3,
                                            int const &faceNumber,
                                            std::vector<double> &faceBasis)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    if(flag3 == 1) {
      for(int it1 = 2; it1 <= _pf1; it1++) {
        for(int it2 = 2; it2 <= _pf2; it2++) {
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
      std::vector<double> lkVector1(_pf2 - 1);
      std::vector<double> lkVector2(_pf1 - 1);
      for(int it = 2; it <= _pf1; it++) {
        lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, u);
      }
      for(int it = 2; it <= _pf2; it++) {
        lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, v);
      }

      for(int it1 = 2; it1 <= _pf2; it1++) {
        for(int it2 = 2; it2 <= _pf1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          faceBasis[iterator] =
            lkVector1[it2 - 2] * lkVector2[it1 - 2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisH1Quad::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &gradientFace, std::string typeFunction)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    if(flag3 == 1) {
      for(int it1 = 2; it1 <= _pf1; it1++) {
        for(int it2 = 2; it2 <= _pf2; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          gradientFace[iterator][0] =
            gradientFace[iterator][0] * impactFlag1 * impactFlag2;
          gradientFace[iterator][1] =
            gradientFace[iterator][1] * impactFlag1 * impactFlag2;

          iterator++;
        }
      }
    }
    else {
      std::vector<double> lkVector1(_pf1 - 1);
      std::vector<double> lkVector2(_pf2 - 1);
      std::vector<double> dlkVector1(_pf1 - 1);
      std::vector<double> dlkVector2(_pf2 - 1);
      for(int it = 2; it <= _pf1; it++) {
        lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, u);
        dlkVector1[it - 2] = OrthogonalPoly::EvalDLobatto(it, u);
      }
      for(int it = 2; it <= _pf2; it++) {
        lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, v);
        dlkVector2[it - 2] = OrthogonalPoly::EvalDLobatto(it, v);
      }
      for(int it1 = 2; it1 <= _pf2; it1++) {
        for(int it2 = 2; it2 <= _pf1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
          if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }

          gradientFace[iterator][0] = dlkVector1[it2 - 2] * lkVector2[it1 - 2] *
                                      impactFlag1 * impactFlag2;
          gradientFace[iterator][1] = lkVector1[it2 - 2] * dlkVector2[it1 - 2] *
                                      impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
  }
}
void HierarchicalBasisH1Quad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<double> &quadFaceFunctionsAllOrientation,
  const std::vector<double> &triFaceFunctionsAllOrientation,
  std::vector<double> &fTableCopy)
{
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  for(int i = 0; i < _nQuadFaceFunction; i++) {
    fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];
  }
}

void HierarchicalBasisH1Quad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  for(int i = 0; i < _nQuadFaceFunction; i++) {
    fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisH1Quad::getKeysInfo(std::vector<int> &functionTypeInfo,
                                          std::vector<int> &orderInfo)
{
  functionTypeInfo[0] = 0;
  functionTypeInfo[1] = 0;
  functionTypeInfo[2] = 0;
  functionTypeInfo[3] = 0;
  orderInfo[0] = 1;
  orderInfo[1] = 1;
  orderInfo[2] = 1;
  orderInfo[3] = 1;
  int it = 4;
  for(int numEdge = 0; numEdge < 4; numEdge++) {
    for(int i = 2; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int n1 = 2; n1 <= _pf1; n1++) {
    for(int n2 = 2; n2 <= _pf2; n2++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = std::max(n1, n2);
      it++;
    }
  }
}
