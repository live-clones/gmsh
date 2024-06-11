// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth, Ivo Dolezel, Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include <stdexcept>
#include "HierarchicalBasisHcurlTetra.h"

HierarchicalBasisHcurlTetra::HierarchicalBasisHcurlTetra(int order)
{
  _nvertex = 4;
  _nedge = 6;
  _nfaceTri = 4;
  _nfaceQuad = 0;
  _nVertexFunction = 0;
  _nEdgeFunction = 6 * order + 6;
  _nQuadFaceFunction = 0;
  if(order == 0) {
    _nTriFaceFunction = 0;
    _nBubbleFunction = 0;
  }
  else {
    _nTriFaceFunction = 12 * (order - 1) + 4 * (order - 2) * (order - 1);
    _nBubbleFunction = (order - 1) * (order - 2) * (order - 3) / 2 +
                       2 * (order - 2) * (order - 1);
  }
  _pb = order;
  for(int i = 0; i < 4; i++) { _pOrderFace[i] = order; }
  for(int i = 0; i < 6; i++) { _pOrderEdge[i] = order; }
}

HierarchicalBasisHcurlTetra::~HierarchicalBasisHcurlTetra() {}

unsigned int HierarchicalBasisHcurlTetra::getNumberOfOrientations() const
{
  return 24; // factorial 4
}

double HierarchicalBasisHcurlTetra::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v,
                                                      const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (1 + u + v + w);
  case(3): return 0.5 * (1 + u);
  case(4): return 0.5 * (1 + w);
  default: throw std::runtime_error("j must be : 1<=j<=4");
  }
}

double HierarchicalBasisHcurlTetra::dotProduct(const std::vector<double> &u,
                                               const std::vector<double> &v)
{
  return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

void HierarchicalBasisHcurlTetra::generateHcurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = 2 * w - 1;
  double jacob = 2;
  //*****
  // compute all needed terms
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[1] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -1. / sqrt(3);
  n2[1] = -1. / sqrt(3);
  n2[2] = -1. / sqrt(3);
  std::vector<double> n3 = std::vector<double>(3, 0);
  n3[0] = 1;
  std::vector<double> n4 = std::vector<double>(3, 0);
  n4[2] = 1;
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> t2 = std::vector<double>(3, 0);
  t2[0] = -1;
  t2[1] = 1;
  std::vector<double> t3 = std::vector<double>(3, 0);
  t3[1] = -1;
  std::vector<double> t4 = std::vector<double>(3, 0);
  t4[2] = 1;
  std::vector<double> t5 = std::vector<double>(3, 0);
  t5[0] = -1;
  t5[2] = 1;
  std::vector<double> t6 = std::vector<double>(3, 0);
  t6[1] = -1;
  t6[2] = 1;
  // Whitney functions:
  std::vector<std::vector<double> > psie_0(6, std::vector<double>(3, 0));
  std::vector<std::vector<double> > psie_1(6, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    psie_0[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) +
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_0[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) +
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_0[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) +
                   lambda1 * n2[i] / dotProduct(n2, t3);
    psie_0[3][i] = lambda4 * n2[i] / dotProduct(n2, t4) +
                   lambda2 * n4[i] / dotProduct(n4, t4);
    psie_0[4][i] = lambda4 * n1[i] / dotProduct(n1, t6) +
                   lambda1 * n4[i] / dotProduct(n4, t6);
    psie_0[5][i] = lambda4 * n3[i] / dotProduct(n3, t5) +
                   lambda3 * n4[i] / dotProduct(n4, t5);

    psie_1[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) -
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_1[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) -
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_1[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) -
                   lambda1 * n2[i] / dotProduct(n2, t3);
    psie_1[3][i] = lambda4 * n2[i] / dotProduct(n2, t4) -
                   lambda2 * n4[i] / dotProduct(n4, t4);
    psie_1[4][i] = lambda4 * n1[i] / dotProduct(n1, t6) -
                   lambda1 * n4[i] / dotProduct(n4, t6);
    psie_1[5][i] = lambda4 * n3[i] / dotProduct(n3, t5) -
                   lambda3 * n4[i] / dotProduct(n4, t5);
  }

  std::vector<double> sub(9, 0);
  sub[0] = lambda3 - lambda2;
  sub[1] = lambda1 - lambda3;
  sub[2] = lambda2 - lambda1;
  sub[3] = lambda4 - lambda2;
  sub[4] = lambda4 - lambda1;
  sub[5] = lambda4 - lambda3;
  sub[6] = lambda2 - lambda4;
  sub[7] = -lambda2 + lambda1;
  sub[8] = lambda3 - lambda4;
  std::vector<std::vector<double> > legendreVector(9);
  legendreVector[0] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[0], _pOrderFace[0] - 1), _pOrderFace[1] - 1),
    0));
  legendreVector[1] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[1], _pOrderFace[0] - 1), _pOrderFace[3] - 1),
    0));
  legendreVector[2] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[2], _pOrderFace[0] - 1), _pOrderFace[2] - 1),
    0));
  legendreVector[3] = std::vector<double>(_pOrderEdge[3], 0);
  legendreVector[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[4], _pOrderFace[2] - 1), _pOrderFace[3] - 1),
    0));
  legendreVector[5] = std::vector<double>(
    std::max(std::max(_pOrderEdge[5], _pOrderFace[1] - 1), 0));
  legendreVector[6] = std::vector<double>(
    std::max(std::max(_pOrderFace[1] - 1, _pOrderFace[2] - 1), 0));
  legendreVector[7] = std::vector<double>(std::max(_pOrderFace[2] - 1, 0));
  legendreVector[8] = std::vector<double>(std::max(_pOrderFace[3] - 1, 0));
  for(int i = 0; i < 9; i++) {
    for(unsigned int j = 0; j < legendreVector[i].size(); j++) {
      legendreVector[i][j] = OrthogonalPoly::EvalLegendre(j, sub[i]);
    }
  }
  // compute edge Basis
  int edgeIt = 0;
  for(int i = 0; i < _nedge; i++) {
    for(int j = 0; j < 3; j++) { edgeBasis[edgeIt][j] = jacob * psie_0[i][j]; }
    edgeIt++;
    if(_pOrderEdge[i] >= 1) {
      for(int j = 0; j < 3; j++) {
        edgeBasis[edgeIt][j] = jacob * psie_1[i][j];
      }
      edgeIt++;
      for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
        for(int j = 0; j < 3; j++) {
          edgeBasis[edgeIt][j] =
            jacob * ((2 * float(iedge) - 1) / float(iedge) *
                       legendreVector[i][iedge - 1] * psie_1[i][j] -
                     (float(iedge) - 1) / float(iedge) *
                       legendreVector[i][iedge - 2] * psie_0[i][j]);
        }
        edgeIt++;
      }
    }
  }

  // edge-based face functions , Genuine face functions
  // and Face-based interior functions
  int faceIt = 0;
  int bubbleIt = 0;
  for(int nFace = 0; nFace < _nfaceTri; nFace++) {
    int indexVector1 = 0;
    int indexVector2 = 0;
    std::vector<double> vecTangent1(3, 0);
    std::vector<double> vecTangent2(3, 0);
    std::vector<double> niT(3, 0);
    double faceProduct = 0;
    switch(nFace) {
    case(0):
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda3 * lambda2;
          nD[1] = 0.5;
          index = 0;
          break;
        case(1):
          product = lambda1 * lambda3;
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          index = 1;
          break;
        case(2):
          product = lambda1 * lambda2;
          nD[0] = 0.5;
          index = 2;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[0]; i1++) {
          for(int j = 0; j < 3; j++) {
            faceBasis[faceIt][j] =
              jacob * product * legendreVector[index][i1 - 2] * nD[j];
          }
          faceIt++;
        }
      }

      indexVector1 = 0;
      vecTangent1[0] = 0.5;
      indexVector2 = 2;
      vecTangent2[1] = 0.5;
      niT[2] = 0.5;
      faceProduct = lambda1 * lambda2 * lambda3;
      break;
    case(1):
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda3 * lambda2;
          nD[2] = 0.5;
          index = 0;
          break;
        case(1):
          product = lambda4 * lambda3;
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          index = 5;
          break;
        case(2):
          product = lambda4 * lambda2;
          nD[0] = 0.5;
          index = 6;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[1]; i1++) {
          for(int j = 0; j < 3; j++) {
            faceBasis[faceIt][j] =
              jacob * product * legendreVector[index][i1 - 2] * nD[j];
          }
          faceIt++;
        }
      }
      indexVector1 = 0;
      vecTangent1[0] = 0.5;
      indexVector2 = 6;
      vecTangent2[2] = 0.5;
      niT[1] = 0.5;
      faceProduct = lambda4 * lambda2 * lambda3;
      break;
    case(2):
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda1 * lambda2;
          nD[2] = 0.5;
          index = 7;
          break;
        case(1):
          product = lambda4 * lambda1;
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          index = 4;
          break;
        case(2):
          product = lambda4 * lambda2;
          nD[1] = 0.5;
          index = 6;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[2]; i1++) {
          for(int j = 0; j < 3; j++) {
            faceBasis[faceIt][j] =
              jacob * product * legendreVector[index][i1 - 2] * nD[j];
          }
          faceIt++;
        }
      }
      indexVector1 = 7;
      vecTangent1[1] = 0.5;
      indexVector2 = 6;
      vecTangent2[2] = 0.5;
      niT[0] = 0.5;
      faceProduct = lambda1 * lambda4 * lambda2;
      break;
    case(3):
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda1 * lambda3;
          nD[2] = 0.5;
          index = 1;
          break;
        case(1):
          product = lambda4 * lambda1;
          nD[0] = 0.5;
          index = 4;
          break;
        case(2):
          product = lambda4 * lambda3;
          nD[1] = 0.5;
          index = 8;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[3]; i1++) {
          for(int j = 0; j < 3; j++) {
            faceBasis[faceIt][j] =
              jacob * product * legendreVector[index][i1 - 2] * nD[j];
          }
          faceIt++;
        }
      }
      indexVector1 = 1;
      vecTangent1[1] = 0.5;
      indexVector2 = 8;
      vecTangent2[2] = 0.5;
      niT[0] = -0.5;
      niT[1] = -0.5;
      niT[2] = -0.5;
      faceProduct = lambda1 * lambda3 * lambda4;
      break;
    }
    std::vector<double> copy(
      int((_pOrderFace[nFace] - 2) * (_pOrderFace[nFace] - 1) / 2), 0);
    int itCopy = 0;
    for(int n1 = 0; n1 < _pOrderFace[nFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[nFace] - 2 - n1; n2++) {
        copy[itCopy] = jacob * faceProduct * legendreVector[indexVector1][n1] *
                       legendreVector[indexVector2][n2];
        for(int i = 0; i < 3; i++) {
          faceBasis[faceIt][i] = copy[itCopy] * vecTangent1[i];
        }
        itCopy++;
        faceIt++;
      }
    }
    itCopy = 0;
    for(int n1 = 0; n1 < _pOrderFace[nFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[nFace] - 2 - n1; n2++) {
        for(int i = 0; i < 3; i++) {
          faceBasis[faceIt][i] = copy[itCopy] * vecTangent2[i];
        }
        faceIt++;
        itCopy++;
      }
    }

    for(int n1 = 0; n1 < _pb - 2; n1++) {
      for(int n2 = 0; n2 < _pb - 2 - n1; n2++) {
        for(int i = 0; i < 3; i++) {
          bubbleBasis[bubbleIt][i] = jacob * faceProduct *
                                     legendreVector[indexVector1][n1] *
                                     legendreVector[indexVector2][n2] * niT[i];
        }
        bubbleIt++;
      }
    }
  }
  if(_pb > 3) {
    int itCopy = 0;
    std::vector<double> copyBubbleTerm((_pb - 3) * (_pb - 2) * (_pb - 1) / 6.,
                                       0);
    for(int n1 = 0; n1 < _pb - 3; n1++) {
      double phi1 = OrthogonalPoly::EvalKernelFunction(n1, sub[7]);
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        double phi2 = OrthogonalPoly::EvalKernelFunction(n2, sub[0]);
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          copyBubbleTerm[itCopy] =
            jacob * lambda1 * lambda2 * lambda3 * lambda4 * phi1 * phi2 *
            OrthogonalPoly::EvalKernelFunction(n3, sub[3]);
          bubbleBasis[bubbleIt][0] = copyBubbleTerm[itCopy];
          itCopy++;
          bubbleIt++;
        }
      }
    }
    itCopy = 0;
    for(int n1 = 0; n1 < _pb - 3; n1++) {
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          bubbleBasis[bubbleIt][1] = copyBubbleTerm[itCopy];
          itCopy++;
          bubbleIt++;
        }
      }
    }
    itCopy = 0;
    for(int n1 = 0; n1 < _pb - 3; n1++) {
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          bubbleBasis[bubbleIt][2] = copyBubbleTerm[itCopy];
          itCopy++;
          bubbleIt++;
        }
      }
    }
  }
}

void HierarchicalBasisHcurlTetra::orientEdge(
  int const &flagOrientation, int const &edgeNumber,
  std::vector<std::vector<double> > &edgeFunctions,
  const std::vector<std::vector<double> > &eTablePositiveFlag,
  const std::vector<std::vector<double> > &eTableNegativeFlag)
{
  if(flagOrientation == -1) {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTableNegativeFlag[k][0];
      edgeFunctions[k][1] = eTableNegativeFlag[k][1];
      edgeFunctions[k][2] = eTableNegativeFlag[k][2];
    }
  }
  else {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTablePositiveFlag[k][0];
      edgeFunctions[k][1] = eTablePositiveFlag[k][1];
      edgeFunctions[k][2] = eTablePositiveFlag[k][2];
    }
  }
}
void HierarchicalBasisHcurlTetra::orientEdgeFunctionsForNegativeFlag(
  std::vector<std::vector<double> > &edgeFunctions)
{
  int constant1 = 0;
  int constant2 = 0;
  for(int edgeNumber = 0; edgeNumber < _nedge; edgeNumber++) {
    constant2 = 0;
    constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      if((k - constant1) % 2 == 0) {
        edgeFunctions[k][0] = edgeFunctions[k][0] * (-1);
        edgeFunctions[k][1] = edgeFunctions[k][1] * (-1);
        edgeFunctions[k][2] = edgeFunctions[k][2] * (-1);
      }
    }
  }
}
void HierarchicalBasisHcurlTetra::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    if(typeFunction == "HcurlLegendre") {
      // orient Edge-based interior functions
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double wc = 2 * w - 1;
      double jacob = 2;
      //*****

      int faceIt = 0;
      for(int k = 0; k < faceNumber; k++) {
        faceIt = faceIt + 3 * (_pOrderFace[k] - 1) +
                 (_pOrderFace[k] - 2) * (_pOrderFace[k] - 1);
      }
      std::vector<double> lambda(3);
      std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
      switch(faceNumber) {
      case(0):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][1] = 0.5;
        break;
      case(1):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      case(2):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(1, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][1] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      case(3):
        lambda[0] = _affineCoordinate(3, uc, vc, wc);
        lambda[1] = _affineCoordinate(1, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = 0.5;
        dlambda[1][1] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      }
      if(flag1 == 1 && flag2 == -1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 0 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 2 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[0];
        lambda[0] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[0];
        dlambda[0] = dcopy;
      }
      else if(flag1 == 1 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = lambda[2];
        lambda[2] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dlambda[2];
        dlambda[2] = dcopy;
      }
      else if(flag1 == 2 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      std::vector<double> sub(3);
      sub[0] = lambda[1] - lambda[0];
      sub[1] = lambda[2] - lambda[1];
      sub[2] = lambda[0] - lambda[2];
      std::vector<double> n1 = std::vector<double>(3, 0);
      n1[0] = dlambda[2][0];
      n1[1] = dlambda[2][1];
      n1[2] = dlambda[2][2];
      std::vector<double> n2 = std::vector<double>(3, 0);
      n2[0] = dlambda[0][0];
      n2[1] = dlambda[0][1];
      n2[2] = dlambda[0][2];
      std::vector<double> n3 = std::vector<double>(3, 0);
      n3[0] = dlambda[1][0];
      n3[1] = dlambda[1][1];
      n3[2] = dlambda[1][2];
      // edge-based face functions
      for(int i = 0; i < 3; i++) {
        double product2 = 0;
        std::vector<double> *normal(nullptr);
        switch(i) {
        case(0):
          product2 = lambda[1] * lambda[0];
          normal = &n1;
          break;
        case(1):
          product2 = lambda[1] * lambda[2];
          normal = &n2;
          break;
        case(2):
          product2 = lambda[2] * lambda[0];
          normal = &n3;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[faceNumber]; i1++) {
          faceFunctions[faceIt][0] =
            jacob * product2 * (*normal)[0] *
            OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]);
          faceFunctions[faceIt][1] =
            jacob * product2 * (*normal)[1] *
            OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]);
          faceFunctions[faceIt][2] =
            jacob * product2 * (*normal)[2] *
            OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]);
          faceIt++;
        }
      }
      // Genuine face functions
      double sub1 = sub[0];
      double sub2 = sub[2];
      std::vector<double> LSub2(_pOrderFace[faceNumber] - 2);
      for(int it = 0; it < _pOrderFace[faceNumber] - 2; it++) {
        LSub2[it] = OrthogonalPoly::EvalLegendre(it, sub2);
      }
      double product = lambda[0] * lambda[1] * lambda[2];

      std::vector<double> copy(int((_pOrderFace[faceNumber] - 1) *
                                   (_pOrderFace[faceNumber] - 2) / 2.));
      int it1 = 0;
      for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
        double LSub1 = OrthogonalPoly::EvalLegendre(n1, sub1);
        for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
          copy[it1] = jacob * product * LSub1 * LSub2[n2];
          for(int i = 0; i < 3; i++) {
            faceFunctions[faceIt][i] = copy[it1] * dlambda[1][i];
          }
          it1++;
          faceIt++;
        }
      }
      it1 = 0;
      for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
        for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
          for(int i = 0; i < 3; i++) {
            faceFunctions[faceIt][i] = copy[it1] * dlambda[2][i];
          }
          faceIt++;
          it1++;
        }
      }
    }

    else if("CurlHcurlLegendre" == typeFunction) {
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double wc = 2 * w - 1;
      double jacob = 4; // 8*0.5
      //*****
      int faceIt = 0;
      for(int k = 0; k < faceNumber; k++) {
        faceIt = faceIt + 3 * (_pOrderFace[k] - 1) +
                 (_pOrderFace[k] - 2) * (_pOrderFace[k] - 1);
      }
      std::vector<double> lambda(3);
      std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
      switch(faceNumber) {
      case(0):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][1] = 0.5;
        break;
      case(1):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      case(2):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(1, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[0][2] = -0.5;
        dlambda[1][1] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      case(3):
        lambda[0] = _affineCoordinate(3, uc, vc, wc);
        lambda[1] = _affineCoordinate(1, uc, vc, wc);
        lambda[2] = _affineCoordinate(4, uc, vc, wc);
        dlambda[0][0] = 0.5;
        dlambda[1][1] = 0.5;
        dlambda[2][2] = 0.5;
        break;
      }
      if(flag1 == 1 && flag2 == -1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 0 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 2 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[0];
        lambda[0] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[0];
        dlambda[0] = dcopy;
      }
      else if(flag1 == 1 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = lambda[2];
        lambda[2] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dlambda[2];
        dlambda[2] = dcopy;
      }
      else if(flag1 == 2 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      std::vector<double> sub(3);
      sub[0] = lambda[1] - lambda[0];
      sub[1] = lambda[2] - lambda[1];
      sub[2] = lambda[0] - lambda[2];
      std::vector<double> n1 = std::vector<double>(3, 0);
      n1[0] = dlambda[2][0];
      n1[1] = dlambda[2][1];
      n1[2] = dlambda[2][2];
      std::vector<double> n2 = std::vector<double>(3, 0);
      n2[0] = dlambda[0][0];
      n2[1] = dlambda[0][1];
      n2[2] = dlambda[0][2];
      std::vector<double> n3 = std::vector<double>(3, 0);
      n3[0] = dlambda[1][0];
      n3[1] = dlambda[1][1];
      n3[2] = dlambda[1][2];

      std::vector<std::vector<double> > dsub(3, std::vector<double>(3, 0));
      for(int p = 0; p < 3; p++) {
        dsub[0][p] = dlambda[1][p] - dlambda[0][p];
        dsub[1][p] = dlambda[2][p] - dlambda[1][p];
        dsub[2][p] = dlambda[0][p] - dlambda[2][p];
      }
      // edge-based face functions
      double dlambda23U = dlambda[0][0] * lambda[1] + dlambda[1][0] * lambda[0];
      double dlambda23V = dlambda[0][1] * lambda[1] + dlambda[1][1] * lambda[0];
      double dlambda23W = dlambda[0][2] * lambda[1] + dlambda[1][2] * lambda[0];
      double prod32 = lambda[0] * lambda[1];
      for(int i1 = 2; i1 <= _pOrderFace[faceNumber]; i1++) {
        double dphiU =
          dlambda23U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
          prod32 * dsub[0][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0]);
        double dphiV =
          dlambda23V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
          prod32 * dsub[0][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0]);
        double dphiW =
          dlambda23W * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
          prod32 * dsub[0][2] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0]);
        faceFunctions[faceIt][0] = jacob * (n1[2] * dphiV - n1[1] * dphiW);
        faceFunctions[faceIt][1] = jacob * (n1[0] * dphiW - n1[2] * dphiU);
        faceFunctions[faceIt][2] = jacob * (n1[1] * dphiU - n1[0] * dphiV);
        faceIt++;
      }
      double dlambda13U = dlambda[2][0] * lambda[1] + dlambda[1][0] * lambda[2];
      double dlambda13V = dlambda[2][1] * lambda[1] + dlambda[1][1] * lambda[2];
      double dlambda13W = dlambda[2][2] * lambda[1] + dlambda[1][2] * lambda[2];
      double prod13 = lambda[2] * lambda[1];
      for(int i1 = 2; i1 <= _pOrderFace[faceNumber]; i1++) {
        double dphiU =
          dlambda13U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
          prod13 * dsub[1][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1]);
        double dphiV =
          dlambda13V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
          prod13 * dsub[1][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1]);
        double dphiW =
          dlambda13W * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
          prod13 * dsub[1][2] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1]);

        faceFunctions[faceIt][0] = jacob * (n2[2] * dphiV - n2[1] * dphiW);
        faceFunctions[faceIt][1] = jacob * (n2[0] * dphiW - n2[2] * dphiU);

        faceFunctions[faceIt][2] = jacob * (n2[1] * dphiU - n2[0] * dphiV);

        faceIt++;
      }
      double dlambda12U = dlambda[2][0] * lambda[0] + dlambda[0][0] * lambda[2];
      double dlambda12V = dlambda[2][1] * lambda[0] + dlambda[0][1] * lambda[2];
      double dlambda12W = dlambda[2][2] * lambda[0] + dlambda[0][2] * lambda[2];
      double prod12 = lambda[0] * lambda[2];
      for(int i1 = 2; i1 <= _pOrderFace[faceNumber]; i1++) {
        double dphiU =
          dlambda12U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
          prod12 * dsub[2][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2]);
        double dphiV =
          dlambda12V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
          prod12 * dsub[2][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2]);
        double dphiW =
          dlambda12W * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
          prod12 * dsub[2][2] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2]);

        faceFunctions[faceIt][0] = jacob * (n3[2] * dphiV - n3[1] * dphiW);
        faceFunctions[faceIt][1] = jacob * (n3[0] * dphiW - n3[2] * dphiU);
        faceFunctions[faceIt][2] = jacob * (n3[1] * dphiU - n3[0] * dphiV);
        faceIt++;
      }
      // Genuine face functions
      double subBA = sub[0];
      double subAC = sub[2];
      std::vector<double> dsubBA(3);
      std::vector<double> dsubAC(3);
      for(int i = 0; i < 3; i++) {
        dsubBA[i] = dsub[0][i];
        dsubAC[i] = dsub[2][i];
      }
      std::vector<double> LSubAC(_pOrderFace[faceNumber] - 2);
      std::vector<double> dLSubAC(_pOrderFace[faceNumber] - 2);
      for(int it = 0; it < _pOrderFace[faceNumber] - 2; it++) {
        LSubAC[it] = OrthogonalPoly::EvalLegendre(it, subAC);
        dLSubAC[it] = OrthogonalPoly::EvalDLegendre(it, subAC);
      }
      std::vector<double> LSubBA(_pOrderFace[faceNumber] - 2);
      std::vector<double> dLSubBA(_pOrderFace[faceNumber] - 2);
      for(int it = 0; it < _pOrderFace[faceNumber] - 2; it++) {
        LSubBA[it] = OrthogonalPoly::EvalLegendre(it, subBA);
        dLSubBA[it] = OrthogonalPoly::EvalDLegendre(it, subBA);
      }
      std::vector<double> dProduct(3, 0);
      for(int i = 0; i < 3; i++) {
        dProduct[i] = dlambda[0][i] * lambda[1] * lambda[2] +
                      dlambda[1][i] * lambda[0] * lambda[2] +
                      dlambda[2][i] * lambda[1] * lambda[0];
      }
      double product = lambda[0] * lambda[1] * lambda[2];
      std::vector<std::vector<double> > copy(
        int((_pOrderFace[faceNumber] - 2) * (_pOrderFace[faceNumber] - 1) / 2),
        std::vector<double>(3, 0));
      int itCopy = 0;
      for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
        for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
          std::vector<double> gradFace(3, 0);

          for(int i = 0; i < 3; i++) {
            gradFace[i] = dProduct[i] * LSubAC[n2] * LSubBA[n1] +
                          product * dsubBA[i] * LSubAC[n2] * dLSubBA[n1] +
                          product * dsubAC[i] * dLSubAC[n2] * LSubBA[n1];
            copy[itCopy][i] = gradFace[i];
          }
          itCopy++;
          curlFunction(jacob, dlambda[1], gradFace, faceFunctions[faceIt]);
          faceIt++;
        }
      }
      itCopy = 0;
      for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
        for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
          curlFunction(jacob, dlambda[2], copy[itCopy], faceFunctions[faceIt]);
          faceIt++;
          itCopy++;
        }
      }
    }
    else {
      throw std::runtime_error("unknown typeFunction");
    }
  }
}
void HierarchicalBasisHcurlTetra::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator +=
      3 * (_pOrderFace[i] - 1) + (_pOrderFace[i] - 2) * (_pOrderFace[i] - 1);
  }
  int numFaceFunctions =
    3 * (_pOrderFace[faceNumber] - 1) +
    (_pOrderFace[faceNumber] - 2) * (_pOrderFace[faceNumber] - 1);
  int iOrientation = numberOrientationTriFace(flag1, flag2);
  int offset = iOrientation * _nTriFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i][0] = triFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = triFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = triFaceFunctionsAllOrientation[i + offset][2];
  }
}

inline void HierarchicalBasisHcurlTetra::curlFunction(
  const double &a, const std::vector<double> &nD,
  const std::vector<double> &grad, std::vector<double> &result)
{
  result[0] = a * (nD[2] * grad[1] - nD[1] * grad[2]);
  result[1] = a * (nD[0] * grad[2] - nD[2] * grad[0]);
  result[2] = a * (nD[1] * grad[0] - nD[0] * grad[1]);
}
inline void HierarchicalBasisHcurlTetra::gradient(
  const double &lambda1, const double &lambda2,
  const std::vector<double> &dlambda1, const std::vector<double> &dlambda2,
  std::vector<double> &result)
{
  for(int i = 0; i < 3; i++) {
    result[i] = lambda1 * dlambda2[i] + lambda2 * dlambda1[i];
  }
}

void HierarchicalBasisHcurlTetra::generateCurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = 2 * w - 1;
  double det = 8;
  double jacob = 0.5;
  //*****
  // compute all needed terms
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  std::vector<double> dlambda1(3, 0);
  std::vector<double> dlambda2(3, -0.5);
  std::vector<double> dlambda3(3, 0);
  std::vector<double> dlambda4(3, 0);
  dlambda1[1] = 0.5;
  dlambda3[0] = 0.5;
  dlambda4[2] = 0.5;
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[1] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -1. / sqrt(3);
  n2[1] = -1. / sqrt(3);
  n2[2] = -1. / sqrt(3);
  std::vector<double> n3 = std::vector<double>(3, 0);
  n3[0] = 1;
  std::vector<double> n4 = std::vector<double>(3, 0);
  n4[2] = 1;
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> t2 = std::vector<double>(3, 0);
  t2[0] = -1;
  t2[1] = 1;
  std::vector<double> t3 = std::vector<double>(3, 0);
  t3[1] = -1;
  std::vector<double> t4 = std::vector<double>(3, 0);
  t4[2] = 1;
  std::vector<double> t5 = std::vector<double>(3, 0);
  t5[0] = -1;
  t5[2] = 1;
  std::vector<double> t6 = std::vector<double>(3, 0);
  t6[1] = -1;
  t6[2] = 1;
  std::vector<double> sub(9, 0);
  sub[0] = lambda3 - lambda2;
  sub[1] = lambda1 - lambda3;
  sub[2] = lambda2 - lambda1;
  sub[3] = lambda4 - lambda2;
  sub[4] = lambda4 - lambda1;
  sub[5] = lambda4 - lambda3;
  sub[6] = lambda2 - lambda4;
  sub[7] = -lambda2 + lambda1;
  sub[8] = lambda3 - lambda4;

  std::vector<std::vector<double> > dsubtraction(9, std::vector<double>(3, 0));
  for(int k = 0; k < 3; k++) {
    dsubtraction[0][k] = dlambda3[k] - dlambda2[k];
    dsubtraction[1][k] = dlambda1[k] - dlambda3[k];
    dsubtraction[2][k] = dlambda2[k] - dlambda1[k];
    dsubtraction[3][k] = dlambda4[k] - dlambda2[k];
    dsubtraction[4][k] = dlambda4[k] - dlambda1[k];
    dsubtraction[5][k] = dlambda4[k] - dlambda3[k];
    dsubtraction[6][k] = dlambda2[k] - dlambda4[k];
    dsubtraction[7][k] = -dlambda2[k] + dlambda1[k];
    dsubtraction[8][k] = dlambda3[k] - dlambda4[k];
  }
  std::vector<std::vector<double> > legendreVector(9);
  std::vector<std::vector<double> > dlegendreVector(9);
  legendreVector[0] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[0], _pOrderFace[0] - 1), _pOrderFace[1] - 1),
    0));
  legendreVector[1] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[1], _pOrderFace[0] - 1), _pOrderFace[3] - 1),
    0));
  legendreVector[2] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[2], _pOrderFace[0] - 1), _pOrderFace[2] - 1),
    0));
  legendreVector[3] = std::vector<double>(std::max(_pOrderEdge[3], 0));
  legendreVector[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[4], _pOrderFace[2] - 1), _pOrderFace[3] - 1),
    0));
  legendreVector[5] = std::vector<double>(
    std::max(std::max(_pOrderEdge[5], _pOrderFace[1] - 1), 0));
  legendreVector[6] = std::vector<double>(
    std::max(std::max(_pOrderFace[1] - 1, _pOrderFace[2] - 1), 0));
  legendreVector[7] = std::vector<double>(std::max(_pOrderFace[2] - 1, 0));
  legendreVector[8] = std::vector<double>(std::max(_pOrderFace[3] - 1, 0));

  dlegendreVector[0] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[0], _pOrderFace[0] - 1), _pOrderFace[1] - 1),
    0));
  dlegendreVector[1] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[1], _pOrderFace[0] - 1), _pOrderFace[3] - 1),
    0));
  dlegendreVector[2] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[2], _pOrderFace[0] - 1), _pOrderFace[2] - 1),
    0));
  dlegendreVector[3] = std::vector<double>(std::max(_pOrderEdge[3], 0));
  dlegendreVector[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderEdge[4], _pOrderFace[2] - 1), _pOrderFace[3] - 1),
    0));
  dlegendreVector[5] = std::vector<double>(
    std::max(std::max(_pOrderEdge[5], _pOrderFace[1] - 1), 0));
  dlegendreVector[6] = std::vector<double>(
    std::max(std::max(_pOrderFace[1] - 1, _pOrderFace[2] - 1), 0));
  dlegendreVector[7] = std::vector<double>(std::max(_pOrderFace[2] - 1, 0));
  dlegendreVector[8] = std::vector<double>(std::max(_pOrderFace[3] - 1, 0));
  for(int i = 0; i < 9; i++) {
    for(unsigned int j = 0; j < legendreVector[i].size(); j++) {
      legendreVector[i][j] = OrthogonalPoly::EvalLegendre(j, sub[i]);
      dlegendreVector[i][j] = OrthogonalPoly::EvalDLegendre(j, sub[i]);
    }
  }

  std::vector<std::vector<double> > dfaceProduct(_nfaceTri,
                                                 std::vector<double>(3));
  for(int i = 0; i < 3; i++) {
    dfaceProduct[0][i] = lambda3 * lambda2 * dlambda1[i] +
                         lambda3 * dlambda2[i] * lambda1 +
                         dlambda3[i] * lambda2 * lambda1;
    dfaceProduct[1][i] = lambda3 * lambda2 * dlambda4[i] +
                         lambda3 * dlambda2[i] * lambda4 +
                         dlambda3[i] * lambda2 * lambda4;
    dfaceProduct[2][i] = lambda1 * lambda2 * dlambda4[i] +
                         lambda1 * dlambda2[i] * lambda4 +
                         dlambda1[i] * lambda2 * lambda4;
    dfaceProduct[3][i] = lambda1 * lambda3 * dlambda4[i] +
                         lambda1 * dlambda3[i] * lambda4 +
                         dlambda1[i] * lambda3 * lambda4;
  }
  // Whitney functions:
  std::vector<std::vector<double> > psie_0(6, std::vector<double>(3, 0));
  std::vector<std::vector<double> > psie_1(6, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    psie_0[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) +
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_0[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) +
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_0[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) +
                   lambda1 * n2[i] / dotProduct(n2, t3);
    psie_0[3][i] = lambda4 * n2[i] / dotProduct(n2, t4) +
                   lambda2 * n4[i] / dotProduct(n4, t4);
    psie_0[4][i] = lambda4 * n1[i] / dotProduct(n1, t6) +
                   lambda1 * n4[i] / dotProduct(n4, t6);
    psie_0[5][i] = lambda4 * n3[i] / dotProduct(n3, t5) +
                   lambda3 * n4[i] / dotProduct(n4, t5);

    psie_1[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) -
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_1[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) -
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_1[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) -
                   lambda1 * n2[i] / dotProduct(n2, t3);
    psie_1[3][i] = lambda4 * n2[i] / dotProduct(n2, t4) -
                   lambda2 * n4[i] / dotProduct(n4, t4);
    psie_1[4][i] = lambda4 * n1[i] / dotProduct(n1, t6) -
                   lambda1 * n4[i] / dotProduct(n4, t6);
    psie_1[5][i] = lambda4 * n3[i] / dotProduct(n3, t5) -
                   lambda3 * n4[i] / dotProduct(n4, t5);
  }
  // curl of withney functions
  std::vector<std::vector<double> > curlpsie_0(6, std::vector<double>(3, 0));
  curlpsie_0[0][1] = -1;
  curlpsie_0[0][2] = 1;
  curlpsie_0[1][2] = 1;
  curlpsie_0[2][0] = -1;
  curlpsie_0[2][2] = 1;
  curlpsie_0[3][0] = -1;
  curlpsie_0[3][1] = 1;
  curlpsie_0[4][0] = 1;
  curlpsie_0[5][1] = -1;
  // edge functions
  int edgeIt = 0;
  for(int i = 0; i < _nedge; i++) {
    for(int j = 0; j < 3; j++) {
      edgeBasis[edgeIt][j] = det * jacob * curlpsie_0[i][j];
    }
    edgeIt++;
    if(_pOrderEdge[i] >= 1) {
      for(int j = 0; j < 3; j++) { edgeBasis[edgeIt][j] = 0; }
      edgeIt++;
    }
    for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
      edgeBasis[edgeIt][0] =
        det * jacob *
        ((2 * float(iedge) - 1) / float(iedge) *
           (dsubtraction[i][1] * dlegendreVector[i][iedge - 1] * psie_1[i][2] -
            dsubtraction[i][2] * dlegendreVector[i][iedge - 1] * psie_1[i][1]) -
         (float(iedge) - 1) / float(iedge) *
           (curlpsie_0[i][0] * legendreVector[i][iedge - 2] +
            dsubtraction[i][1] * dlegendreVector[i][iedge - 2] * psie_0[i][2] -
            dsubtraction[i][2] * dlegendreVector[i][iedge - 2] * psie_0[i][1]));
      edgeBasis[edgeIt][1] =
        det * jacob *
        ((2 * float(iedge) - 1) / float(iedge) *
           (dsubtraction[i][2] * dlegendreVector[i][iedge - 1] * psie_1[i][0] -
            dsubtraction[i][0] * dlegendreVector[i][iedge - 1] * psie_1[i][2]) -
         (float(iedge) - 1) / float(iedge) *
           (curlpsie_0[i][1] * legendreVector[i][iedge - 2] +
            dsubtraction[i][2] * dlegendreVector[i][iedge - 2] * psie_0[i][0] -
            dsubtraction[i][0] * dlegendreVector[i][iedge - 2] * psie_0[i][2]));
      edgeBasis[edgeIt][2] =
        det * jacob *
        ((2 * float(iedge) - 1) / float(iedge) *
           (dsubtraction[i][0] * dlegendreVector[i][iedge - 1] * psie_1[i][1] -
            dsubtraction[i][1] * dlegendreVector[i][iedge - 1] * psie_1[i][0]) -
         (float(iedge) - 1) / float(iedge) *
           (curlpsie_0[i][2] * legendreVector[i][iedge - 2] +
            dsubtraction[i][0] * dlegendreVector[i][iedge - 2] * psie_0[i][1] -
            dsubtraction[i][1] * dlegendreVector[i][iedge - 2] * psie_0[i][0]));
      edgeIt++;
    }
  }
  // edge-based face functions , Genuine face functions
  // and Face-based interior functions
  int faceIt = 0;
  int bubbleIt = 0;
  for(int nFace = 0; nFace < _nfaceTri; nFace++) {
    int indexVector1 = 0;
    int indexVector2 = 0;
    std::vector<double> vecTangent1(3, 0);
    std::vector<double> vecTangent2(3, 0);
    std::vector<double> niT(3, 0);
    double faceProduct = 0;
    switch(nFace) {
    case(0):
      indexVector1 = 0;
      vecTangent1[0] = 0.5;
      indexVector2 = 2;
      vecTangent2[1] = 0.5;
      niT[2] = 0.5;
      faceProduct = lambda1 * lambda2 * lambda3;
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> dproduct(3, 0);
        std::vector<double> nD(3, 0);
        switch(i) {
        case(0):
          product = lambda3 * lambda2;
          gradient(lambda3, lambda2, dlambda3, dlambda2, dproduct);
          nD[1] = 0.5;
          break;
        case(1):
          product = lambda1 * lambda3;
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          gradient(lambda3, lambda1, dlambda3, dlambda1, dproduct);
          break;
        case(2):
          product = lambda1 * lambda2;
          gradient(lambda1, lambda2, dlambda1, dlambda2, dproduct);
          nD[0] = 0.5;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[0]; i1++) {
          std::vector<double> grad(3, 0);
          std::vector<double> gradLegendre(3, 0);
          gradLegendre[0] = dsubtraction[i][0] * dlegendreVector[i][i1 - 2];
          gradLegendre[1] = dsubtraction[i][1] * dlegendreVector[i][i1 - 2];
          gradLegendre[2] = dsubtraction[i][2] * dlegendreVector[i][i1 - 2];

          gradient(product, legendreVector[i][i1 - 2], dproduct, gradLegendre,
                   grad);
          curlFunction(jacob * det, nD, grad, faceBasis[faceIt]);

          faceIt++;
        }
      }
      break;
    case(1):
      indexVector1 = 0;
      vecTangent1[0] = 0.5;
      indexVector2 = 6;
      vecTangent2[2] = 0.5;
      niT[1] = 0.5;
      faceProduct = lambda4 * lambda2 * lambda3;

      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> dproduct(3, 0);
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda3 * lambda2;
          gradient(lambda3, lambda2, dlambda3, dlambda2, dproduct);
          nD[2] = 0.5;
          index = 0;
          break;
        case(1):
          product = lambda4 * lambda3;
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          gradient(lambda4, lambda3, dlambda4, dlambda3, dproduct);
          index = 5;
          break;
        case(2):
          product = lambda4 * lambda2;
          gradient(lambda4, lambda2, dlambda4, dlambda2, dproduct);
          nD[0] = 0.5;
          index = 6;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[1]; i1++) {
          std::vector<double> grad(3, 0);
          std::vector<double> gradLegendre(3, 0);
          gradLegendre[0] =
            dsubtraction[index][0] * dlegendreVector[index][i1 - 2];
          gradLegendre[1] =
            dsubtraction[index][1] * dlegendreVector[index][i1 - 2];
          gradLegendre[2] =
            dsubtraction[index][2] * dlegendreVector[index][i1 - 2];
          gradient(product, legendreVector[index][i1 - 2], dproduct,
                   gradLegendre, grad);
          curlFunction(jacob * det, nD, grad, faceBasis[faceIt]);
          faceIt++;
        }
      }
      break;
    case(2):

      indexVector1 = 7;
      vecTangent1[1] = 0.5;
      indexVector2 = 6;
      vecTangent2[2] = 0.5;
      niT[0] = 0.5;
      faceProduct = lambda1 * lambda2 * lambda4;
      for(int i = 0; i < 3; i++) {
        double product = 0;
        std::vector<double> nD(3, 0);
        std::vector<double> dproduct(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda1 * lambda2;
          gradient(lambda1, lambda2, dlambda1, dlambda2, dproduct);
          nD[2] = 0.5;
          index = 7;
          break;
        case(1):
          product = lambda4 * lambda1;
          gradient(lambda4, lambda1, dlambda4, dlambda1, dproduct);
          nD[0] = -0.5;
          nD[1] = -0.5;
          nD[2] = -0.5;
          index = 4;
          break;
        case(2):
          product = lambda4 * lambda2;
          gradient(lambda4, lambda2, dlambda4, dlambda2, dproduct);
          nD[1] = 0.5;
          index = 6;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[2]; i1++) {
          std::vector<double> grad(3, 0);
          std::vector<double> gradLegendre(3, 0);
          gradLegendre[0] =
            dsubtraction[index][0] * dlegendreVector[index][i1 - 2];
          gradLegendre[1] =
            dsubtraction[index][1] * dlegendreVector[index][i1 - 2];
          gradLegendre[2] =
            dsubtraction[index][2] * dlegendreVector[index][i1 - 2];
          gradient(product, legendreVector[index][i1 - 2], dproduct,
                   gradLegendre, grad);
          curlFunction(jacob * det, nD, grad, faceBasis[faceIt]);
          faceIt++;
        }
      }
      break;
    case(3):
      indexVector1 = 1;
      vecTangent1[1] = 0.5;
      indexVector2 = 8;
      vecTangent2[2] = 0.5;
      niT[0] = -0.5;
      niT[1] = -0.5;
      niT[2] = -0.5;
      faceProduct = lambda1 * lambda4 * lambda3;
      for(int i = 0; i < 3; i++) {
        std::vector<double> dproduct(3, 0);
        double product = 0;
        std::vector<double> nD(3, 0);
        int index = 0;
        switch(i) {
        case(0):
          product = lambda1 * lambda3;
          gradient(lambda3, lambda1, dlambda3, dlambda1, dproduct);
          nD[2] = 0.5;
          index = 1;
          break;
        case(1):
          product = lambda4 * lambda1;
          gradient(lambda4, lambda1, dlambda4, dlambda1, dproduct);
          nD[0] = 0.5;
          index = 4;
          break;
        case(2):
          product = lambda4 * lambda3;
          gradient(lambda4, lambda3, dlambda4, dlambda3, dproduct);
          nD[1] = 0.5;
          index = 8;
          break;
        }
        for(int i1 = 2; i1 <= _pOrderFace[3]; i1++) {
          std::vector<double> grad(3, 0);
          std::vector<double> gradLegendre(3, 0);
          gradLegendre[0] =
            dsubtraction[index][0] * dlegendreVector[index][i1 - 2];
          gradLegendre[1] =
            dsubtraction[index][1] * dlegendreVector[index][i1 - 2];
          gradLegendre[2] =
            dsubtraction[index][2] * dlegendreVector[index][i1 - 2];
          gradient(product, legendreVector[index][i1 - 2], dproduct,
                   gradLegendre, grad);
          curlFunction(jacob * det, nD, grad, faceBasis[faceIt]);
          faceIt++;
        }
      }
      break;
    }

    std::vector<std::vector<double> > copy(
      int((_pOrderFace[nFace] - 2) * (_pOrderFace[nFace] - 1) / 2),
      std::vector<double>(3, 0));
    int itCopy = 0;
    for(int n1 = 0; n1 < _pOrderFace[nFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[nFace] - 2 - n1; n2++) {
        std::vector<double> gradFace(3, 0);
        for(int i = 0; i < 3; i++) {
          gradFace[i] =
            dfaceProduct[nFace][i] * legendreVector[indexVector1][n1] *
              legendreVector[indexVector2][n2] +
            faceProduct * dlegendreVector[indexVector1][n1] *
              dsubtraction[indexVector1][i] * legendreVector[indexVector2][n2] +
            faceProduct * legendreVector[indexVector1][n1] *
              dsubtraction[indexVector2][i] * dlegendreVector[indexVector2][n2];
          copy[itCopy][i] = gradFace[i];
        }
        itCopy++;
        curlFunction(jacob * det, vecTangent1, gradFace, faceBasis[faceIt]);

        faceIt++;
      }
    }
    itCopy = 0;
    for(int n1 = 0; n1 < _pOrderFace[nFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[nFace] - 2 - n1; n2++) {
        curlFunction(jacob * det, vecTangent2, copy[itCopy], faceBasis[faceIt]);
        faceIt++;
        itCopy++;
      }
    }
    for(int n1 = 0; n1 < _pb - 2; n1++) {
      for(int n2 = 0; n2 < _pb - 2 - n1; n2++) {
        std::vector<double> gradFace(3, 0);
        for(int i = 0; i < 3; i++) {
          gradFace[i] =
            dfaceProduct[nFace][i] * legendreVector[indexVector1][n1] *
              legendreVector[indexVector2][n2] +
            faceProduct * dlegendreVector[indexVector1][n1] *
              dsubtraction[indexVector1][i] * legendreVector[indexVector2][n2] +
            faceProduct * legendreVector[indexVector1][n1] *
              dsubtraction[indexVector2][i] * dlegendreVector[indexVector2][n2];
        }
        curlFunction(jacob * det, niT, gradFace, bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
  if(_pb > 3) {
    double l1l2l3l4 = lambda1 * lambda2 * lambda3 * lambda4;
    std::vector<double> dl1l2l3l4(3, 0);
    for(int i = 0; i < 3; i++) {
      dl1l2l3l4[i] = lambda1 * lambda2 * lambda3 * dlambda4[i] +
                     lambda1 * lambda2 * dlambda3[i] * lambda4 +
                     lambda1 * dlambda2[i] * lambda3 * lambda4 +
                     dlambda1[i] * lambda2 * lambda3 * lambda4;
    }

    for(int n1 = 0; n1 < _pb - 3; n1++) {
      double phi1 = OrthogonalPoly::EvalKernelFunction(n1, sub[7]);
      double dphi1 = OrthogonalPoly::EvalDKernelFunction(n1, sub[7]);
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        double phi2 = OrthogonalPoly::EvalKernelFunction(n2, sub[0]);
        double dphi2 = OrthogonalPoly::EvalDKernelFunction(n2, sub[0]);
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          bubbleBasis[bubbleIt][0] = 0;
          bubbleBasis[bubbleIt][1] =
            det * jacob *
            (dl1l2l3l4[2] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][2] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][2] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][2] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));
          bubbleBasis[bubbleIt][2] =
            -det * jacob *
            (dl1l2l3l4[1] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][1] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][1] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][1] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));

          bubbleIt++;
        }
      }
    }

    for(int n1 = 0; n1 < _pb - 3; n1++) {
      double phi1 = OrthogonalPoly::EvalKernelFunction(n1, sub[7]);
      double dphi1 = OrthogonalPoly::EvalDKernelFunction(n1, sub[7]);
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        double phi2 = OrthogonalPoly::EvalKernelFunction(n2, sub[0]);
        double dphi2 = OrthogonalPoly::EvalDKernelFunction(n2, sub[0]);
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          bubbleBasis[bubbleIt][0] =
            -det * jacob *
            (dl1l2l3l4[2] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][2] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][2] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][2] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));
          bubbleBasis[bubbleIt][1] = 0;
          bubbleBasis[bubbleIt][2] =
            det * jacob *
            (dl1l2l3l4[0] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][0] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][0] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][0] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));

          bubbleIt++;
        }
      }
    }

    for(int n1 = 0; n1 < _pb - 3; n1++) {
      double phi1 = OrthogonalPoly::EvalKernelFunction(n1, sub[7]);
      double dphi1 = OrthogonalPoly::EvalDKernelFunction(n1, sub[7]);
      for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
        double phi2 = OrthogonalPoly::EvalKernelFunction(n2, sub[0]);
        double dphi2 = OrthogonalPoly::EvalDKernelFunction(n2, sub[0]);
        for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
          bubbleBasis[bubbleIt][0] =
            det * jacob *
            (dl1l2l3l4[1] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][1] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][1] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][1] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));
          bubbleBasis[bubbleIt][1] =
            -det * jacob *
            (dl1l2l3l4[0] * phi1 * phi2 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[7][0] * dphi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * dphi2 * dsubtraction[0][0] * phi1 *
               OrthogonalPoly::EvalKernelFunction(n3, sub[3]) +
             l1l2l3l4 * phi2 * dsubtraction[3][0] * phi1 *
               OrthogonalPoly::EvalDKernelFunction(n3, sub[3]));
          bubbleBasis[bubbleIt][2] = 0;

          bubbleIt++;
        }
      }
    }
  }
}

void HierarchicalBasisHcurlTetra::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{
  int it = 0;
  for(int numEdge = 0; numEdge < 6; numEdge++) {
    for(int i = 0; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int numFace = 0; numFace < 4; numFace++) {
    for(int i = 0; i < 3; i++) {
      for(int i1 = 2; i1 <= _pOrderFace[numFace]; i1++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = i1;
        it++;
      }
    }
    for(int n1 = 1; n1 < _pOrderFace[numFace] - 1; n1++) {
      for(int n2 = 1; n2 <= _pOrderFace[numFace] - 1 - n1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
    for(int n1 = 1; n1 < _pOrderFace[numFace] - 1; n1++) {
      for(int n2 = 1; n2 <= _pOrderFace[numFace] - 1 - n1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
  }
  for(int numFace = 0; numFace < 4; numFace++) {
    for(int n1 = 1; n1 < _pb - 1; n1++) {
      for(int n2 = 1; n2 <= _pb - 1 - n1; n2++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int n1 = 1; n1 < _pb - 2; n1++) {
      for(int n2 = 1; n2 <= _pb - 2 - n1; n2++) {
        for(int n3 = 1; n3 <= _pb - 1 - n2 - n1; n3++) {
          functionTypeInfo[it] = 3;
          orderInfo[it] = n1 + n2 + n3 + 1;
          it++;
        }
      }
    }
  }
}
