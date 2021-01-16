// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).
#include "HierarchicalBasisHcurlPri.h"
HierarchicalBasisHcurlPri::HierarchicalBasisHcurlPri(int order)
{
  _nvertex = 6;
  _nedge = 9;
  if(order < 2) { _nfaceTri = 0; }
  else {
    _nfaceTri = 2;
  }
  _nfaceQuad = 3;
  _nVertexFunction = 0;
  _nEdgeFunction = 9 * order + 9;
  _nQuadFaceFunction = 6 * order * (order + 1);
  if(order == 0) { _nTriFaceFunction = 0; }
  else {
    _nTriFaceFunction = 6 * (order - 1) + 2 * (order - 1) * (order - 2);
  }
  _nBubbleFunction = 3 * (order - 1) * order +
                     (order - 1) * (order - 2) * order +
                     (order - 1) * order * (order + 1) / 2;
  _pb1 = order;
  _pb2 = order;
  for(int i = 0; i < 3; i++) {
    _pOrderQuadFace1[i] = order;
    _pOrderQuadFace2[i] = order;
  }
  for(int i = 0; i < 2; i++) { _pOrderTriFace[i] = order; }
  for(int i = 0; i < 9; i++) { _pOrderEdge[i] = order; }
}

HierarchicalBasisHcurlPri::~HierarchicalBasisHcurlPri() {}

unsigned int HierarchicalBasisHcurlPri::getNumberOfOrientations() const
{
  return 720; // factorial 6
}

double HierarchicalBasisHcurlPri::_affineCoordinate(const int &j,
                                                    const double &u,
                                                    const double &v,
                                                    const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  case(4): return 0.5 * (1 + w);
  case(5): return 0.5 * (1 - w);
  default: throw std::string("j must be : 1<=j<=5");
  }
}

double
HierarchicalBasisHcurlPri::dotProduct(const std::vector<double> &u1,
                                      const std::vector<double> &u2) // in 2D
{
  return u1[0] * u2[0] + u1[1] * u2[1];
}

void HierarchicalBasisHcurlPri::matrixVectorProductForMapping(
  const double &a, const std::vector<double> &u, std::vector<double> &result)
{
  result[0] = a * 2 * u[0];
  result[1] = a * 2 * u[1];
  result[2] = a * u[2];
}
void HierarchicalBasisHcurlPri::generateHcurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = w;
  //*****
  // compute all needed terms
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double lambda5 = _affineCoordinate(5, uc, vc, wc);
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> t2 = std::vector<double>(3, 0);
  t2[0] = -1;
  t2[1] = 1;
  std::vector<double> t3 = std::vector<double>(3, 0);
  t3[1] = 1;
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[1] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -sqrt(0.5);
  n2[1] = -sqrt(0.5);
  std::vector<double> n3 = std::vector<double>(3, 0);
  n3[0] = 1;
  // Whitney functions
  std::vector<std::vector<double> > psie_0(3, std::vector<double>(3, 0));
  std::vector<std::vector<double> > psie_1(3, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    psie_0[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) +
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_0[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) +
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_0[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) +
                   lambda1 * n2[i] / dotProduct(n2, t3);

    psie_1[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) -
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_1[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) -
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_1[2][i] = -lambda2 * n1[i] / dotProduct(n1, t3) +
                   lambda1 * n2[i] / dotProduct(n2, t3); // edge oriented: {0;2}
  }
  double subl3l2 = lambda3 - lambda2;
  double subl1l3 = lambda1 - lambda3;
  double subl1l2 = lambda1 - lambda2;
  double subl2l1 = lambda2 - lambda1;
  std::vector<double> sub(4, 0);
  sub[0] = subl3l2, sub[1] = subl1l3, sub[2] = subl1l2, sub[3] = subl2l1;
  std::vector<std::vector<double> > legendreVector(4);
  legendreVector[0] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[0], _pOrderEdge[6]),
                                 _pOrderQuadFace1[0] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  legendreVector[1] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[3], _pOrderEdge[8]),
                                 _pOrderQuadFace1[2] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  legendreVector[2] = std::vector<double>(
    std::max(std::max(_pOrderEdge[1], _pOrderEdge[7]), _pOrderQuadFace1[1] + 1),
    0);

  legendreVector[3] = std::vector<double>(
    std::max(std::max(std::max(_pOrderTriFace[0] - 1, _pOrderTriFace[1] - 1),
                      _pb1 - 1),
             0),
    0);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, subl3l2);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, subl1l3);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, subl1l2);
  }
  for(unsigned int k = 0; k < legendreVector[3].size(); k++) {
    legendreVector[3][k] = OrthogonalPoly::EvalLegendre(k, subl2l1);
  }

  std::vector<double> legendreW(
    std::max(std::max(std::max(std::max(std::max(std::max(_pOrderEdge[2] + 1,
                                                          _pOrderEdge[4] + 1),
                                                 _pOrderEdge[5] + 1),
                                        _pOrderQuadFace2[0] + 1),
                               _pOrderQuadFace2[1] + 1),
                      _pOrderQuadFace2[2] + 1),
             _pb2 + 1),
    0);
  std::vector<double> lobattoW(
    std::max(
      std::max(std::max(_pOrderQuadFace2[0] + 2, _pOrderQuadFace2[1] + 2),
               _pOrderQuadFace2[2] + 2),
      _pb2 + 2),
    0);
  for(unsigned int k = 0; k < legendreW.size(); k++) {
    legendreW[k] = OrthogonalPoly::EvalLegendre(k, wc);
  }
  for(unsigned int k = 0; k < lobattoW.size(); k++) {
    lobattoW[k] = OrthogonalPoly::EvalLobatto(k, wc);
  }

  // edge functions
  int edgeIt = 0;
  for(int i = 0; i < _nedge; i++) {
    switch(i) {
    case 0:
    case 1:
    case 3:
    case 6:
    case 7:
    case 8: {
      double lambda = 0;
      int index = 0;
      if(i == 0 || i == 1 || i == 3) { lambda = lambda5; }
      else {
        lambda = lambda4;
      }
      if(i == 0 || i == 6) { index = 0; }
      if(i == 1 || i == 7) { index = 2; }
      if(i == 3 || i == 8) { index = 1; }
      matrixVectorProductForMapping(lambda, psie_0[index], edgeBasis[edgeIt]);
      edgeIt++;
      if(_pOrderEdge[i] >= 1) {
        matrixVectorProductForMapping(lambda, psie_1[index], edgeBasis[edgeIt]);
        edgeIt++;
        for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
          for(int j = 0; j < 3; j++) {
            edgeBasis[edgeIt][j] =
              (2 * float(iedge) - 1) / float(iedge) *
                legendreVector[index][iedge - 1] * psie_1[index][j] -
              (float(iedge) - 1) / float(iedge) *
                legendreVector[index][iedge - 2] * psie_0[index][j];
          }
          matrixVectorProductForMapping(lambda, edgeBasis[edgeIt],
                                        edgeBasis[edgeIt]);
          edgeIt++;
        }
      }
    } break;
    case 2:
    case 4:
    case 5: {
      double lamb = 0;
      if(i == 2) { lamb = lambda2; }
      if(i == 4) { lamb = lambda3; }
      if(i == 5) { lamb = lambda1; }
      for(int iedge = 0; iedge <= _pOrderEdge[i]; iedge++) {
        edgeBasis[edgeIt][0] = 0;
        edgeBasis[edgeIt][1] = 0;
        edgeBasis[edgeIt][2] = lamb * legendreW[iedge];
        matrixVectorProductForMapping(1, edgeBasis[edgeIt], edgeBasis[edgeIt]);
        edgeIt++;
      }
    } break;
    }
  }

  // face functions for quadrilateral faces
  int faceIt = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int index = 0;
    double prod = 0;
    switch(iFace) {
    case(0):
      index = 0;
      prod = lambda2 * lambda3;
      break;
    case(1):
      index = 2;
      prod = lambda1 * lambda2;
      break;
    case(2):
      index = 1;
      prod = lambda1 * lambda3;
      break;
    }
    if(_pOrderQuadFace1[iFace] > 0) {
      for(int n1 = 0; n1 <= _pOrderQuadFace1[iFace]; n1++) {
        std::vector<double> facePsi(3, 0);
        if(n1 == 0) {
          facePsi[0] = psie_0[index][0], facePsi[1] = psie_0[index][1],
          facePsi[2] = psie_0[index][2];
        }
        else if(n1 == 1) {
          facePsi[0] = psie_1[index][0], facePsi[1] = psie_1[index][1],
          facePsi[2] = psie_1[index][2];
        }
        else {
          for(int j = 0; j < 3; j++) {
            facePsi[j] = (2 * float(n1) - 1) / float(n1) *
                           legendreVector[index][n1 - 1] * psie_1[index][j] -
                         (float(n1) - 1) / float(n1) *
                           legendreVector[index][n1 - 2] * psie_0[index][j];
          }
        }
        for(int n2 = 2; n2 <= _pOrderQuadFace2[iFace] + 1; n2++) {
          matrixVectorProductForMapping(lobattoW[n2], facePsi,
                                        faceBasis[faceIt]);
          faceIt++;
        }
      }
    }
    for(int n1 = 2; n1 <= _pOrderQuadFace1[iFace] + 1; n1++) {
      double phie =
        prod * OrthogonalPoly::EvalKernelFunction(n1 - 2, sub[index]);

      for(int n2 = 0; n2 <= _pOrderQuadFace2[iFace]; n2++) {
        faceBasis[faceIt][0] = 0;
        faceBasis[faceIt][1] = 0;
        faceBasis[faceIt][2] = phie * legendreW[n2];
        matrixVectorProductForMapping(1, faceBasis[faceIt], faceBasis[faceIt]);
        faceIt++;
      }
    }
  }
  // face functions for triangular faces
  for(int iFace = 0; iFace < 2; iFace++) {
    double lambda = 0;
    if(iFace == 0) { lambda = lambda5; }
    else {
      lambda = lambda4;
    }
    for(int i = 0; i < 3; i++) {
      double prod = 0;
      std::vector<double> nD(3, 0);
      int index = 0;
      switch(i) {
      case(0):
        prod = lambda2 * lambda3;
        nD[1] = 0.5;
        index = 0;
        break;
      case(1):
        prod = lambda1 * lambda3;
        nD[0] = -0.5;
        nD[1] = -0.5;
        index = 1;
        break;
      case(2):
        prod = lambda1 * lambda2;
        nD[0] = 0.5;
        index = 3;
        break;
      }
      for(int n1 = 2; n1 <= _pOrderTriFace[iFace]; n1++) {
        // edge-based triangular face functions
        matrixVectorProductForMapping(
          prod * legendreVector[index][n1 - 2] * lambda, nD, faceBasis[faceIt]);
        faceIt++;
      }
    }
    // Genuine triangular face functions
    double product = lambda1 * lambda2 * lambda3;
    int faceIt2 = faceIt;
    for(int n1 = 0; n1 < _pOrderTriFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderTriFace[iFace] - 2 - n1; n2++) {
        faceBasis[faceIt][0] = 0.5 * lambda * product * legendreVector[0][n1] *
                               legendreVector[3][n2]; // t_AB
        faceBasis[faceIt][1] = 0;
        faceBasis[faceIt][2] = 0;
        matrixVectorProductForMapping(1, faceBasis[faceIt], faceBasis[faceIt]);
        faceIt++;
      }
    }
    for(int n1 = 0; n1 < _pOrderTriFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderTriFace[iFace] - 2 - n1; n2++) {
        faceBasis[faceIt][0] = 0;
        faceBasis[faceIt][1] = faceBasis[faceIt2][0]; // t_CA
        faceBasis[faceIt][2] = 0;
        faceIt++;
        faceIt2++;
      }
    }
  }

  // quadrilateral-face-based bubble functions
  int bubbleIt = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int index = 0;
    double prod = 0;
    std::vector<double> nD(3, 0);
    switch(iFace) {
    case(0):
      index = 0;
      nD[1] = 0.5;
      prod = lambda2 * lambda3;
      break;
    case(1):
      index = 3;
      prod = lambda1 * lambda2;
      nD[0] = 0.5;
      break;
    case(2):
      index = 1;
      prod = lambda1 * lambda3;
      nD[0] = -0.5;
      nD[1] = -0.5;
      break;
    }
    for(int n1 = 2; n1 <= _pb1; n1++) {
      for(int n2 = 2; n2 <= _pb2 + 1; n2++) {
        matrixVectorProductForMapping(lobattoW[n2] * prod *
                                        legendreVector[index][n1 - 2],
                                      nD, bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
  // genuine bubble functions
  double product = lambda1 * lambda2 * lambda3;
  int bubbleIt2 = bubbleIt;
  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      std::vector<double> term(3, 0);
      term[0] = product * legendreVector[0][n1] * legendreVector[3][n2]; // t_AB
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        matrixVectorProductForMapping(lobattoW[n3], term,
                                      bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        bubbleBasis[bubbleIt][1] = -bubbleBasis[bubbleIt2][0];
        bubbleIt++;
        bubbleIt2++;
      }
    }
  }
  // triangular-face-based bubble functions
  for(int n1 = 0; n1 < _pb1 - 1; n1++) {
    for(int n2 = 0; n2 < _pb1 - 1 - n1; n2++) {
      double term = product * legendreVector[0][n1] * legendreVector[3][n2];
      for(int n3 = 0; n3 <= _pb2; n3++) {
        bubbleBasis[bubbleIt][0] = 0;
        bubbleBasis[bubbleIt][1] = 0;
        bubbleBasis[bubbleIt][2] = term * legendreW[n3];
        bubbleIt++;
      }
    }
  }
}

void HierarchicalBasisHcurlPri::orientEdge(
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
void HierarchicalBasisHcurlPri::orientEdgeFunctionsForNegativeFlag(
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
void HierarchicalBasisHcurlPri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{
  if(faceNumber < 3) {
    if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
      int iterator = 0;
      for(int k = 0; k < faceNumber; k++) {
        iterator = iterator + (_pOrderQuadFace1[k] + 1) * _pOrderQuadFace2[k] +
                   (_pOrderQuadFace2[k] + 1) * _pOrderQuadFace1[k];
      }
      if(flag3 == 1) {
        for(int it1 = 0; it1 <= _pOrderQuadFace1[faceNumber]; it1++) {
          for(int it2 = 2; it2 <= _pOrderQuadFace2[faceNumber] + 1; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag1 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
            if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            faceFunctions[iterator][0] =
              faceFunctions[iterator][0] * impactFlag1 * impactFlag2;
            faceFunctions[iterator][1] =
              faceFunctions[iterator][1] * impactFlag1 * impactFlag2;
            faceFunctions[iterator][2] =
              faceFunctions[iterator][2] * impactFlag1 * impactFlag2;
            iterator++;
          }
        }
        for(int it1 = 2; it1 <= _pOrderQuadFace1[faceNumber] + 1; it1++) {
          for(int it2 = 0; it2 <= _pOrderQuadFace2[faceNumber]; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag2 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
            faceFunctions[iterator][0] =
              faceFunctions[iterator][0] * impactFlag1 * impactFlag2;
            faceFunctions[iterator][1] =
              faceFunctions[iterator][1] * impactFlag1 * impactFlag2;
            faceFunctions[iterator][2] =
              faceFunctions[iterator][2] * impactFlag1 * impactFlag2;
            iterator++;
          }
        }
      }
      else {
        if(typeFunction == "HcurlLegendre") {
          // to map onto the reference domain of gmsh:
          double uc = 2 * u - 1;
          double vc = 2 * v - 1;
          double wc = w;
          double jacob = 2;
          //*****
          double prod = 0;
          double sub = 0;
          std::vector<double> psie_0(2, 0);
          std::vector<double> psie_1(2, 0);
          switch(faceNumber) {
          case(0): {
            double lambda2 = _affineCoordinate(2, uc, vc, wc);
            double lambda3 = _affineCoordinate(3, uc, vc, wc);
            prod = lambda2 * lambda3;
            sub = lambda3 - lambda2;
            psie_0[0] = lambda3 + lambda2;
            psie_0[1] = lambda3;
            psie_1[0] = sub;
            psie_1[1] = lambda3;
          } break;
          case(1): {
            double lambda2 = _affineCoordinate(2, uc, vc, wc);
            double lambda1 = _affineCoordinate(1, uc, vc, wc);
            prod = lambda1 * lambda2;
            sub = lambda1 - lambda2;
            psie_0[0] = lambda1;
            psie_0[1] = lambda1 + lambda2;
            psie_1[0] = lambda1;
            psie_1[1] = sub;
          } break;
          case(2): {
            double lambda3 = _affineCoordinate(3, uc, vc, wc);
            double lambda1 = _affineCoordinate(1, uc, vc, wc);
            prod = lambda1 * lambda3;
            sub = lambda1 - lambda3;
            psie_0[0] = -lambda1;
            psie_0[1] = lambda3;
            psie_1[0] = -lambda1;
            psie_1[1] = -lambda3;
          } break;
          }
          std::vector<double> LSub(_pOrderQuadFace1[faceNumber]);
          std::vector<double> phi(_pOrderQuadFace1[faceNumber]);
          for(unsigned int i = 0; i < LSub.size(); i++) {
            LSub[i] = OrthogonalPoly::EvalLegendre(i, sub);
            phi[i] = prod * OrthogonalPoly::EvalKernelFunction(i, sub);
          }
          for(int it1 = 0; it1 <= _pOrderQuadFace2[faceNumber]; it1++) {
            double Lw = OrthogonalPoly::EvalLegendre(it1, wc);
            int impactFlag1 = 1;
            if(flag2 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
            for(int it2 = 2; it2 <= _pOrderQuadFace1[faceNumber] + 1; it2++) {
              int impactFlag2 = 1;
              if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
              faceFunctions[iterator][0] = 0;
              faceFunctions[iterator][1] = 0;
              faceFunctions[iterator][2] =
                impactFlag1 * impactFlag2 * phi[it2 - 2] * Lw;
              iterator++;
            }
          }
          for(int it1 = 2; it1 <= _pOrderQuadFace2[faceNumber] + 1; it1++) {
            double lw = OrthogonalPoly::EvalLobatto(it1, wc);
            int impactFlag1 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1) {
              faceFunctions[iterator][0] =
                -jacob * impactFlag1 * lw * psie_0[0];
              faceFunctions[iterator][1] =
                -jacob * impactFlag1 * lw * psie_0[1];
              faceFunctions[iterator][2] = 0;
              iterator++;
              faceFunctions[iterator][0] = jacob * impactFlag1 * lw * psie_1[0];
              faceFunctions[iterator][1] = jacob * impactFlag1 * lw * psie_1[1];
              faceFunctions[iterator][2] = 0;
              iterator++;
            }
            else {
              faceFunctions[iterator][0] = jacob * impactFlag1 * lw * psie_0[0];
              faceFunctions[iterator][1] = jacob * impactFlag1 * lw * psie_0[1];
              faceFunctions[iterator][2] = 0;
              iterator++;
              faceFunctions[iterator][0] = jacob * impactFlag1 * lw * psie_1[0];
              faceFunctions[iterator][1] = jacob * impactFlag1 * lw * psie_1[1];
              faceFunctions[iterator][2] = 0;
              iterator++;
            }
            for(int it2 = 2; it2 <= _pOrderQuadFace1[faceNumber]; it2++) {
              int impactFlag2 = 1;

              if(flag1 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
              for(int j = 0; j < 2; j++) {
                faceFunctions[iterator][j] =
                  impactFlag1 * impactFlag2 * lw * jacob *
                  ((2 * float(it2) - 1) / float(it2) * LSub[it2 - 1] *
                     psie_1[j] -
                   (float(it2) - 1) / float(it2) * LSub[it2 - 2] * psie_0[j]);
              }
              faceFunctions[iterator][2] = 0; // psie_0[2]==psie_1[2]==0
              iterator++;
            }
          }
        }
        else if("CurlHcurlLegendre" == typeFunction) {
          // to map onto the reference domain of gmsh:
          double uc = 2 * u - 1;
          double vc = 2 * v - 1;
          double wc = w;
          double detJacob = 2; // det*jacob
          double det = 4;
          //*****
          double prod = 0;
          double sub = 0;
          std::vector<double> dsub(2, 0);
          std::vector<double> dProd(2, 0);
          std::vector<double> psie_0(2, 0);
          std::vector<double> psie_1(2, 0);
          double curlpsie_0 = 1;
          switch(faceNumber) {
          case(0): {
            double lambda2 = _affineCoordinate(2, uc, vc, wc);
            double lambda3 = _affineCoordinate(3, uc, vc, wc);
            prod = lambda2 * lambda3;
            sub = lambda3 - lambda2;
            psie_0[0] = lambda3 + lambda2;
            psie_0[1] = lambda3;
            psie_1[0] = sub;
            psie_1[1] = lambda3;
            dProd[0] = 0.5 * (lambda2 - lambda3);
            dProd[1] = -0.5 * lambda3;
            dsub[0] = 1;
            dsub[1] = 0.5;
          } break;
          case(1): {
            double lambda2 = _affineCoordinate(2, uc, vc, wc);
            double lambda1 = _affineCoordinate(1, uc, vc, wc);
            prod = lambda1 * lambda2;
            sub = lambda1 - lambda2;
            psie_0[0] = lambda1;
            psie_0[1] = lambda1 + lambda2;
            psie_1[0] = lambda1;
            psie_1[1] = sub;
            dsub[0] = 0.5;
            dsub[1] = 1;
            dProd[0] = -0.5 * lambda1;
            dProd[1] = 0.5 * (lambda2 - lambda1);
            curlpsie_0 = -1;
          } break;
          case(2): {
            double lambda3 = _affineCoordinate(3, uc, vc, wc);
            double lambda1 = _affineCoordinate(1, uc, vc, wc);
            prod = lambda1 * lambda3;
            sub = lambda1 - lambda3;
            psie_0[0] = -lambda1;
            psie_0[1] = lambda3;
            psie_1[0] = -lambda1;
            psie_1[1] = -lambda3;
            dProd[0] = 0.5 * lambda1;
            dProd[1] = 0.5 * lambda3;
            dsub[0] = -0.5;
            dsub[1] = 0.5;

          } break;
          }
          std::vector<double> Lsub(_pOrderQuadFace1[faceNumber]);
          std::vector<double> dLsub(_pOrderQuadFace1[faceNumber]);
          std::vector<double> phi(_pOrderQuadFace1[faceNumber]);
          std::vector<double> dphi(_pOrderQuadFace1[faceNumber]);
          for(unsigned int i = 0; i < Lsub.size(); i++) {
            Lsub[i] = OrthogonalPoly::EvalLegendre(i, sub);
            dLsub[i] = OrthogonalPoly::EvalDLegendre(i, sub);
            phi[i] = OrthogonalPoly::EvalKernelFunction(i, sub);
            dphi[i] = OrthogonalPoly::EvalDKernelFunction(i, sub);
          }
          for(int it1 = 0; it1 <= _pOrderQuadFace2[faceNumber]; it1++) {
            double Lw = OrthogonalPoly::EvalLegendre(it1, wc);
            int impactFlag1 = 1;
            if(flag2 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
            for(int it2 = 2; it2 <= _pOrderQuadFace1[faceNumber] + 1; it2++) {
              int impactFlag2 = 1;
              if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
              std::vector<double> dphie(2, 0);
              dphie[0] =
                dProd[0] * phi[it2 - 2] + prod * dsub[0] * dphi[it2 - 2];
              dphie[1] =
                dProd[1] * phi[it2 - 2] + prod * dsub[1] * dphi[it2 - 2];
              faceFunctions[iterator][0] =
                detJacob * impactFlag1 * impactFlag2 * Lw * dphie[1];
              faceFunctions[iterator][1] =
                -detJacob * impactFlag1 * impactFlag2 * Lw * dphie[0];
              faceFunctions[iterator][2] = 0;
              iterator++;
            }
          }
          for(int it1 = 2; it1 <= _pOrderQuadFace2[faceNumber] + 1; it1++) {
            double lw = OrthogonalPoly::EvalLobatto(it1, wc);
            double dlw = OrthogonalPoly::EvalDLobatto(it1, wc);
            int impactFlag1 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1) {
              faceFunctions[iterator][0] =
                detJacob * impactFlag1 * dlw * psie_0[1];
              faceFunctions[iterator][1] =
                -detJacob * impactFlag1 * dlw * psie_0[0];
              faceFunctions[iterator][2] = -det * lw * curlpsie_0 * impactFlag1;
              iterator++;
              faceFunctions[iterator][0] =
                -detJacob * impactFlag1 * dlw * psie_1[1];
              faceFunctions[iterator][1] =
                detJacob * impactFlag1 * dlw * psie_1[0];
              faceFunctions[iterator][2] = 0;
              iterator++;
            }
            else {
              faceFunctions[iterator][0] =
                -detJacob * impactFlag1 * dlw * psie_0[1];
              faceFunctions[iterator][1] =
                detJacob * impactFlag1 * dlw * psie_0[0];
              faceFunctions[iterator][2] = det * lw * curlpsie_0 * impactFlag1;
              iterator++;
              faceFunctions[iterator][0] =
                -detJacob * impactFlag1 * dlw * psie_1[1];
              faceFunctions[iterator][1] =
                detJacob * impactFlag1 * dlw * psie_1[0];
              faceFunctions[iterator][2] = 0;
              iterator++;
            }
            for(int it2 = 2; it2 <= _pOrderQuadFace1[faceNumber]; it2++) {
              int impactFlag2 = 1;
              std::vector<double> psie(2, 0);
              for(int j = 0; j < 2; j++) {
                psie[j] =
                  (2 * float(it2) - 1) / float(it2) * Lsub[it2 - 1] *
                    psie_1[j] -
                  (float(it2) - 1) / float(it2) * Lsub[it2 - 2] * psie_0[j];
              }
              double curlpsie = (2 * float(it2) - 1) / float(it2) *
                                  (dsub[0] * dLsub[it2 - 1] * psie_1[1] -
                                   dsub[1] * dLsub[it2 - 1] * psie_1[0]) -
                                (float(it2) - 1) / float(it2) *
                                  (curlpsie_0 * Lsub[it2 - 2] +
                                   dsub[0] * dLsub[it2 - 2] * psie_0[1] -
                                   dsub[1] * dLsub[it2 - 2] * psie_0[0]);
              if(flag1 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
              faceFunctions[iterator][0] =
                -impactFlag1 * impactFlag2 * dlw * detJacob * psie[1];

              faceFunctions[iterator][1] =
                impactFlag1 * impactFlag2 * dlw * detJacob * psie[0];

              faceFunctions[iterator][2] =
                impactFlag1 * impactFlag2 * lw * det * curlpsie;

              iterator++;
            }
          }
        }
        else {
          throw std::string("unknown typeFunction");
        }
      }
    }
  }
  else {
    if(_pOrderTriFace[faceNumber - 3] > 1) {
      int it = 0;
      for(int k = 0; k < 3; k++) {
        it = it + (_pOrderQuadFace1[k] + 1) * _pOrderQuadFace2[k] +
             (_pOrderQuadFace2[k] + 1) * _pOrderQuadFace1[k];
      }
      if(typeFunction == "HcurlLegendre") {
        // to map onto the reference domain of gmsh:
        double uc = 2 * u - 1;
        double vc = 2 * v - 1;
        double wc = w;
        double jacob = 2;
        //*****
        double lambda45 = 0;
        switch(faceNumber) {
        case(3): lambda45 = _affineCoordinate(5, uc, vc, wc); break;
        case(4):
          lambda45 = _affineCoordinate(4, uc, vc, wc);
          it += 3 * (_pOrderTriFace[0] - 1) +
                (_pOrderTriFace[0] - 1) * (_pOrderTriFace[0] - 2);
          break;
        }
        std::vector<double> lambda(3);
        std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][1] = 0.5;
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
        std::vector<double> n2 = std::vector<double>(3, 0);
        n2[0] = dlambda[0][0];
        n2[1] = dlambda[0][1];
        std::vector<double> n3 = std::vector<double>(3, 0);
        n3[0] = dlambda[1][0];
        n3[1] = dlambda[1][1];
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
          for(int i1 = 2; i1 <= _pOrderTriFace[faceNumber - 3]; i1++) {
            faceFunctions[it][0] = jacob * product2 * lambda45 * (*normal)[0] *
                                   OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]);
            faceFunctions[it][1] = jacob * product2 * lambda45 * (*normal)[1] *
                                   OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]);
            faceFunctions[it][2] = 0;
            it++;
          }
        }
        double sub1 = sub[0];
        double sub2 = sub[2];
        std::vector<double> LSub2(_pOrderTriFace[faceNumber - 3] - 2);
        for(int it = 0; it < _pOrderTriFace[faceNumber - 3] - 2; it++) {
          LSub2[it] = OrthogonalPoly::EvalLegendre(it, sub2);
        }
        double product = lambda[0] * lambda[1] * lambda[2];

        std::vector<double> copy(int((_pOrderTriFace[faceNumber - 3] - 1) *
                                     (_pOrderTriFace[faceNumber - 3] - 2) /
                                     2.));
        int it1 = 0;
        for(int n1 = 0; n1 < _pOrderTriFace[faceNumber - 3] - 2; n1++) {
          double LSub1 = OrthogonalPoly::EvalLegendre(n1, sub1);
          for(int n2 = 0; n2 < _pOrderTriFace[faceNumber - 3] - 2 - n1; n2++) {
            copy[it1] = jacob * product * LSub1 * LSub2[n2] * lambda45;
            for(int i = 0; i < 3; i++) {
              faceFunctions[it][i] = copy[it1] * dlambda[1][i];
            }
            it1++;
            it++;
          }
        }
        it1 = 0;
        for(int n1 = 0; n1 < _pOrderTriFace[faceNumber - 3] - 2; n1++) {
          for(int n2 = 0; n2 < _pOrderTriFace[faceNumber - 3] - 2 - n1; n2++) {
            for(int i = 0; i < 3; i++) {
              faceFunctions[it][i] = copy[it1] * dlambda[2][i];
            }
            it++;
            it1++;
          }
        }
      }
      else if("CurlHcurlLegendre" == typeFunction) {
        // to map onto the reference domain of gmsh:
        double uc = 2 * u - 1;
        double vc = 2 * v - 1;
        double wc = w;
        double detJacob = 2; //=det*jacob
        double det = 4;
        //*****
        double lambda45 = 0;
        double dlambda45 = 0;
        switch(faceNumber) {
        case(3):
          lambda45 = _affineCoordinate(5, uc, vc, wc);
          dlambda45 = -0.5;
          break;
        case(4):
          lambda45 = _affineCoordinate(4, uc, vc, wc);
          it += 3 * (_pOrderTriFace[0] - 1) +
                (_pOrderTriFace[0] - 1) * (_pOrderTriFace[0] - 2);
          dlambda45 = 0.5;
          break;
        }
        std::vector<double> lambda(3);
        std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -0.5;
        dlambda[0][1] = -0.5;
        dlambda[1][0] = 0.5;
        dlambda[2][1] = 0.5;
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
        std::vector<double> n1 = std::vector<double>(3, 0);
        n1[0] = dlambda[2][0];
        n1[1] = dlambda[2][1];
        std::vector<double> n2 = std::vector<double>(3, 0);
        n2[0] = dlambda[0][0];
        n2[1] = dlambda[0][1];
        std::vector<double> n3 = std::vector<double>(3, 0);
        n3[0] = dlambda[1][0];
        n3[1] = dlambda[1][1];
        std::vector<double> sub(3);
        sub[0] = lambda[1] - lambda[0];
        sub[1] = lambda[2] - lambda[1];
        sub[2] = lambda[0] - lambda[2];
        std::vector<std::vector<double> > dsub(3, std::vector<double>(3, 0));
        for(int p = 0; p < 3; p++) {
          dsub[0][p] = dlambda[1][p] - dlambda[0][p];
          dsub[1][p] = dlambda[2][p] - dlambda[1][p];
          dsub[2][p] = dlambda[0][p] - dlambda[2][p];
        }
        double dlambda23U =
          dlambda[0][0] * lambda[1] + dlambda[1][0] * lambda[0];
        double dlambda23V =
          dlambda[0][1] * lambda[1] + dlambda[1][1] * lambda[0];
        double prod32 = lambda[0] * lambda[1];
        for(int i1 = 2; i1 <= _pOrderTriFace[faceNumber - 3]; i1++) {
          faceFunctions[it][0] = -detJacob * n1[1] * dlambda45 * prod32 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]);
          faceFunctions[it][1] = detJacob * n1[0] * dlambda45 * prod32 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]);

          faceFunctions[it][2] =
            det *
            (n1[1] *
               (dlambda23U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
                prod32 * dsub[0][0] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0])) *
               lambda45 -
             n1[0] *
               (dlambda23V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
                prod32 * dsub[0][1] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0])) *
               lambda45);

          it++;
        }
        double dlambda13U =
          dlambda[2][0] * lambda[1] + dlambda[1][0] * lambda[2];
        double dlambda13V =
          dlambda[2][1] * lambda[1] + dlambda[1][1] * lambda[2];
        double prod13 = lambda[2] * lambda[1];
        for(int i1 = 2; i1 <= _pOrderTriFace[faceNumber - 3]; i1++) {
          faceFunctions[it][0] = -detJacob * n2[1] * dlambda45 * prod13 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]);
          faceFunctions[it][1] = detJacob * n2[0] * dlambda45 * prod13 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]);

          faceFunctions[it][2] =
            det *
            (n2[1] *
               (dlambda13U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
                prod13 * dsub[1][0] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1])) *
               lambda45 -
             n2[0] *
               (dlambda13V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
                prod13 * dsub[1][1] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1])) *
               lambda45);
          it++;
        }
        double dlambda12U =
          dlambda[2][0] * lambda[0] + dlambda[0][0] * lambda[2];
        double dlambda12V =
          dlambda[2][1] * lambda[0] + dlambda[0][1] * lambda[2];
        double prod12 = lambda[0] * lambda[2];

        for(int i1 = 2; i1 <= _pOrderTriFace[faceNumber - 3]; i1++) {
          faceFunctions[it][0] = -detJacob * n3[1] * dlambda45 * prod12 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]);
          faceFunctions[it][1] = detJacob * n3[0] * dlambda45 * prod12 *
                                 OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]);

          faceFunctions[it][2] =
            det *
            (n3[1] *
               (dlambda12U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
                prod12 * dsub[2][0] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2])) *
               lambda45 -
             n3[0] *
               (dlambda12V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
                prod12 * dsub[2][1] *
                  OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2])) *
               lambda45);

          it++;
        }
        // Genuine face function
        double subBA = sub[0];
        double subAC = sub[2];
        std::vector<double> dsubBA(3, 0);
        std::vector<double> dsubAC(3, 0);
        for(int i = 0; i < 3; i++) {
          dsubBA[i] = dsub[0][i];
          dsubAC[i] = dsub[2][i];
        }
        std::vector<double> LSubAC(_pOrderTriFace[faceNumber - 3] - 2);
        std::vector<double> dLSubAC(_pOrderTriFace[faceNumber - 3] - 2);
        for(int it = 0; it < _pOrderTriFace[faceNumber - 3] - 2; it++) {
          LSubAC[it] = OrthogonalPoly::EvalLegendre(it, subAC);
          dLSubAC[it] = OrthogonalPoly::EvalDLegendre(it, subAC);
        }
        std::vector<double> LSubBA(_pOrderTriFace[faceNumber - 3] - 2);
        std::vector<double> dLSubBA(_pOrderTriFace[faceNumber - 3] - 2);
        for(int it = 0; it < _pOrderTriFace[faceNumber - 3] - 2; it++) {
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
        for(int n1 = 0; n1 < _pOrderTriFace[faceNumber - 3] - 2; n1++) {
          for(int n2 = 0; n2 < _pOrderTriFace[faceNumber - 3] - 2 - n1; n2++) {
            faceFunctions[it][0] = -detJacob * dlambda[1][1] * dlambda45 *
                                   product * LSubBA[n1] * LSubAC[n2];
            faceFunctions[it][1] = detJacob * dlambda[1][0] * dlambda45 *
                                   product * LSubBA[n1] * LSubAC[n2];
            faceFunctions[it][2] =
              det * lambda45 *
              ((dProduct[0] * LSubAC[n2] * LSubBA[n1] +
                product * dsubBA[0] * LSubAC[n2] * dLSubBA[n1] +
                product * dsubAC[0] * dLSubAC[n2] * LSubBA[n1]) *
                 dlambda[1][1] -
               dlambda[1][0] *
                 (dProduct[1] * LSubAC[n2] * LSubBA[n1] +
                  product * dsubBA[1] * LSubAC[n2] * dLSubBA[n1] +
                  product * dsubAC[1] * dLSubAC[n2] * LSubBA[n1]));

            it++;
          }
        }
        for(int n1 = 0; n1 < _pOrderTriFace[faceNumber - 3] - 2; n1++) {
          for(int n2 = 0; n2 < _pOrderTriFace[faceNumber - 3] - 2 - n1; n2++) {
            faceFunctions[it][0] = -detJacob * dlambda[2][1] * dlambda45 *
                                   product * LSubBA[n1] * LSubAC[n2];
            faceFunctions[it][1] = detJacob * dlambda[2][0] * dlambda45 *
                                   product * LSubBA[n1] * LSubAC[n2];
            faceFunctions[it][2] =
              det * lambda45 *
              ((dProduct[0] * LSubAC[n2] * LSubBA[n1] +
                product * dsubBA[0] * LSubAC[n2] * dLSubBA[n1] +
                product * dsubAC[0] * dLSubAC[n2] * LSubBA[n1]) *
                 dlambda[2][1] -
               dlambda[2][0] *
                 (dProduct[1] * LSubAC[n2] * LSubBA[n1] +
                  product * dsubBA[1] * LSubAC[n2] * dLSubBA[n1] +
                  product * dsubAC[1] * dLSubAC[n2] * LSubBA[n1]));
            it++;
          }
        }
      }
      else {
        throw std::string("unknown typeFunction");
      }
    }
  }
}
void HierarchicalBasisHcurlPri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  if(faceNumber < 3) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderQuadFace1[i] + 1) * _pOrderQuadFace2[i] +
                  (_pOrderQuadFace2[i] + 1) * _pOrderQuadFace1[i];
    }
    int numFaceFunctions =
      (_pOrderQuadFace1[faceNumber] + 1) * _pOrderQuadFace2[faceNumber] +
      (_pOrderQuadFace2[faceNumber] + 1) * _pOrderQuadFace1[faceNumber];
    int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
    int offset = iOrientation * _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
      fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
      fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
    }
  }
  else {
    int iterator = _nQuadFaceFunction;
    int numface = faceNumber - 3;
    for(int i = 0; i < numface; i++) {
      iterator += 3 * (_pOrderTriFace[i] - 1) +
                  (_pOrderTriFace[i] - 1) * (_pOrderTriFace[i] - 2);
    }
    int numFaceFunctions =
      3 * (_pOrderTriFace[numface] - 1) +
      (_pOrderTriFace[numface] - 1) * (_pOrderTriFace[numface] - 2);
    int iOrientation = numberOrientationTriFace(flag1, flag2);
    int offset = iOrientation * _nTriFaceFunction - _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i][0] = triFaceFunctionsAllOrientation[i + offset][0];
      fTableCopy[i][1] = triFaceFunctionsAllOrientation[i + offset][1];
      fTableCopy[i][2] = triFaceFunctionsAllOrientation[i + offset][2];
    }
  }
}

void HierarchicalBasisHcurlPri::matrixVectorProductForCurlMapping(
  std::vector<double> &result)
{
  result[0] = 2 * result[0]; // Jacob*result[0]/det;
  result[1] = 2 * result[1]; // Jacob*result[1]/det;
  result[2] = 4 * result[2];
}

void HierarchicalBasisHcurlPri::generateCurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = w;
  //*****
  // compute all needed terms
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double lambda5 = _affineCoordinate(5, uc, vc, wc);
  double dlambda5 = -0.5;
  double dlambda4 = 0.5;
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> t2 = std::vector<double>(3, 0);
  t2[0] = -1;
  t2[1] = 1;
  std::vector<double> t3 = std::vector<double>(3, 0);
  t3[1] = 1;
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[1] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -sqrt(0.5);
  n2[1] = -sqrt(0.5);
  std::vector<double> n3 = std::vector<double>(3, 0);
  n3[0] = 1;
  // Whitney functions
  std::vector<std::vector<double> > psie_0(3, std::vector<double>(3, 0));
  std::vector<std::vector<double> > psie_1(3, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    psie_0[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) +
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_0[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) +
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_0[2][i] = lambda2 * n1[i] / dotProduct(n1, t3) +
                   lambda1 * n2[i] / dotProduct(n2, t3);

    psie_1[0][i] = lambda3 * n2[i] / dotProduct(n2, t1) -
                   lambda2 * n3[i] / dotProduct(n3, t1);
    psie_1[1][i] = lambda1 * n3[i] / dotProduct(n3, t2) -
                   lambda3 * n1[i] / dotProduct(n1, t2);
    psie_1[2][i] =
      -lambda2 * n1[i] / dotProduct(n1, t3) + // edge oriented: {0;2}
      lambda1 * n2[i] / dotProduct(n2, t3);
  }
  double subl3l2 = lambda3 - lambda2;
  double subl1l3 = lambda1 - lambda3;
  double subl1l2 = lambda1 - lambda2;
  double subl2l1 = lambda2 - lambda1;
  std::vector<double> sub(4, 0);
  sub[0] = subl3l2, sub[1] = subl1l3, sub[2] = subl1l2, sub[3] = subl2l1;
  std::vector<std::vector<double> > legendreVector(4);
  std::vector<std::vector<double> > dlegendreVector(4);
  legendreVector[0] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[0], _pOrderEdge[6]),
                                 _pOrderQuadFace1[0] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  dlegendreVector[0] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[0], _pOrderEdge[6]),
                                 _pOrderQuadFace1[0] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  legendreVector[1] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[3], _pOrderEdge[8]),
                                 _pOrderQuadFace1[2] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  dlegendreVector[1] = std::vector<double>(
    std::max(
      std::max(std::max(std::max(std::max(_pOrderEdge[3], _pOrderEdge[8]),
                                 _pOrderQuadFace1[2] + 1),
                        _pOrderTriFace[0] - 1),
               _pOrderTriFace[1] - 1),
      _pb1 - 1),
    0);
  legendreVector[2] = std::vector<double>(
    std::max(std::max(_pOrderEdge[1], _pOrderEdge[7]), _pOrderQuadFace1[1] + 1),
    0);

  dlegendreVector[2] = std::vector<double>(
    std::max(std::max(_pOrderEdge[1], _pOrderEdge[7]), _pOrderQuadFace1[1] + 1),
    0);

  legendreVector[3] = std::vector<double>(
    std::max(std::max(std::max(_pOrderTriFace[0] - 1, _pOrderTriFace[1] - 1),
                      _pb1 - 1),
             0),
    0);
  dlegendreVector[3] = std::vector<double>(
    std::max(std::max(std::max(_pOrderTriFace[0] - 1, _pOrderTriFace[1] - 1),
                      _pb1 - 1),
             0),
    0);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, subl3l2);
    dlegendreVector[0][k] = OrthogonalPoly::EvalDLegendre(k, subl3l2);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, subl1l3);
    dlegendreVector[1][k] = OrthogonalPoly::EvalDLegendre(k, subl1l3);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, subl1l2);
    dlegendreVector[2][k] = OrthogonalPoly::EvalDLegendre(k, subl1l2);
  }
  for(unsigned int k = 0; k < legendreVector[3].size(); k++) {
    legendreVector[3][k] = OrthogonalPoly::EvalLegendre(k, subl2l1);
    dlegendreVector[3][k] = OrthogonalPoly::EvalDLegendre(k, subl2l1);
  }
  std::vector<double> curlpsie_0(3, 1);
  curlpsie_0[2] = -1;
  std::vector<double> curlpsie_1(3, 0);
  std::vector<std::vector<double> > dsubtraction(4, std::vector<double>(2, 0));
  dsubtraction[0][0] = 1;
  dsubtraction[0][1] = 0.5;
  dsubtraction[1][0] = -0.5;
  dsubtraction[1][1] = 0.5;
  dsubtraction[2][0] = 0.5;
  dsubtraction[2][1] = 1;
  dsubtraction[3][0] = -0.5;
  dsubtraction[3][1] = -1;
  std::vector<double> legendreW(
    std::max(std::max(std::max(std::max(std::max(std::max(_pOrderEdge[2] + 1,
                                                          _pOrderEdge[4] + 1),
                                                 _pOrderEdge[5] + 1),
                                        _pOrderQuadFace2[0] + 1),
                               _pOrderQuadFace2[1] + 1),
                      _pOrderQuadFace2[2] + 1),
             _pb2 + 1),
    0);
  std::vector<double> lobattoW(
    std::max(
      std::max(std::max(_pOrderQuadFace2[0] + 2, _pOrderQuadFace2[1] + 2),
               _pOrderQuadFace2[2] + 2),
      _pb2 + 2),
    0);
  std::vector<double> dlobattoW(
    std::max(
      std::max(std::max(_pOrderQuadFace2[0] + 2, _pOrderQuadFace2[1] + 2),
               _pOrderQuadFace2[2] + 2),
      _pb2 + 2),
    0);
  for(unsigned int k = 0; k < legendreW.size(); k++) {
    legendreW[k] = OrthogonalPoly::EvalLegendre(k, wc);
  }
  for(unsigned int k = 0; k < lobattoW.size(); k++) {
    lobattoW[k] = OrthogonalPoly::EvalLobatto(k, wc);
    dlobattoW[k] = OrthogonalPoly::EvalDLobatto(k, wc);
  }
  // edge functions

  int edgeIt = 0;
  for(int i = 0; i < _nedge; i++) {
    switch(i) {
    case 0:
    case 1:
    case 3:
    case 6:
    case 7:
    case 8: {
      double lambda = 0;
      double dlambda = 0;
      int index = 0;
      if(i == 0 || i == 1 || i == 3) {
        lambda = lambda5;
        dlambda = dlambda5;
      }
      else {
        lambda = lambda4;
        dlambda = dlambda4;
      }
      if(i == 0 || i == 6) { index = 0; }
      if(i == 1 || i == 7) { index = 2; }
      if(i == 3 || i == 8) { index = 1; }

      edgeBasis[edgeIt][0] = -dlambda * psie_0[index][1];
      edgeBasis[edgeIt][1] = dlambda * psie_0[index][0];
      edgeBasis[edgeIt][2] = lambda * curlpsie_0[index];
      matrixVectorProductForCurlMapping(edgeBasis[edgeIt]);
      edgeIt++;
      if(_pOrderEdge[i] >= 1) {
        edgeBasis[edgeIt][0] = -dlambda * psie_1[index][1];
        edgeBasis[edgeIt][1] = dlambda * psie_1[index][0];
        edgeBasis[edgeIt][2] = 0;
        matrixVectorProductForCurlMapping(edgeBasis[edgeIt]);
        edgeIt++;
        for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
          double curlpsie =
            (2 * float(iedge) - 1) / float(iedge) *
              (dsubtraction[index][0] * dlegendreVector[index][iedge - 1] *
                 psie_1[index][1] -
               dsubtraction[index][1] * dlegendreVector[index][iedge - 1] *
                 psie_1[index][0]) -
            (float(iedge) - 1) / float(iedge) *
              (curlpsie_0[index] * legendreVector[index][iedge - 2] +
               dsubtraction[index][0] * dlegendreVector[index][iedge - 2] *
                 psie_0[index][1] -
               dsubtraction[index][1] * dlegendreVector[index][iedge - 2] *
                 psie_0[index][0]);
          std::vector<double> psi(3, 0);
          for(int j = 0; j < 2; j++) {
            psi[j] = (2 * float(iedge) - 1) / float(iedge) *
                       legendreVector[index][iedge - 1] * psie_1[index][j] -
                     (float(iedge) - 1) / float(iedge) *
                       legendreVector[index][iedge - 2] * psie_0[index][j];
          }
          edgeBasis[edgeIt][0] = -dlambda * psi[1];
          edgeBasis[edgeIt][1] = dlambda * psi[0];
          edgeBasis[edgeIt][2] = lambda * curlpsie;
          matrixVectorProductForCurlMapping(edgeBasis[edgeIt]);
          edgeIt++;
        }
      }
    } break;
    case 2:
    case 4:
    case 5: {
      double dlambV = 0;
      double dlambU = 0;
      if(i == 2) {
        dlambV = -0.5;
        dlambU = -0.5;
      }
      if(i == 4) { dlambU = 0.5; }
      if(i == 5) { dlambV = 0.5; }
      for(int iedge = 0; iedge <= _pOrderEdge[i]; iedge++) {
        edgeBasis[edgeIt][0] = dlambV * legendreW[iedge];
        edgeBasis[edgeIt][1] = -dlambU * legendreW[iedge];
        edgeBasis[edgeIt][2] = 0;
        matrixVectorProductForCurlMapping(edgeBasis[edgeIt]);
        edgeIt++;
      }
      break;
    }
    }
  }

  // face functions for quadrilateral faces
  int faceIt = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int index = 0;
    double prod = 0;
    std::vector<double> dProd(2, 0);
    switch(iFace) {
    case(0):
      index = 0;
      prod = lambda2 * lambda3;
      dProd[0] = 0.5 * (lambda2 - lambda3);
      dProd[1] = -0.5 * lambda3;
      break;
    case(1):
      index = 2;
      prod = lambda1 * lambda2;
      dProd[0] = -0.5 * lambda1;
      dProd[1] = 0.5 * (lambda2 - lambda1);
      break;
    case(2):
      index = 1;
      prod = lambda1 * lambda3;
      dProd[0] = 0.5 * lambda1;
      dProd[1] = 0.5 * lambda3;
      break;
    }
    if(_pOrderQuadFace1[iFace] > 0) {
      for(int n1 = 0; n1 <= _pOrderQuadFace1[iFace]; n1++) {
        double curlpsie = 0;
        std::vector<double> psie(2, 0);
        if(n1 == 0) {
          curlpsie = curlpsie_0[index];
          psie[0] = psie_0[index][0];
          psie[1] = psie_0[index][1];
        }
        else if(n1 == 1) {
          curlpsie = 0;
          psie[0] = psie_1[index][0];
          psie[1] = psie_1[index][1];
        }
        else {
          for(int j = 0; j < 2; j++) {
            psie[j] = (2 * float(n1) - 1) / float(n1) *
                        legendreVector[index][n1 - 1] * psie_1[index][j] -
                      (float(n1) - 1) / float(n1) *
                        legendreVector[index][n1 - 2] * psie_0[index][j];
          }
          curlpsie = (2 * float(n1) - 1) / float(n1) *
                       (dsubtraction[index][0] *
                          dlegendreVector[index][n1 - 1] * psie_1[index][1] -
                        dsubtraction[index][1] *
                          dlegendreVector[index][n1 - 1] * psie_1[index][0]) -
                     (float(n1) - 1) / float(n1) *
                       (curlpsie_0[index] * legendreVector[index][n1 - 2] +
                        dsubtraction[index][0] *
                          dlegendreVector[index][n1 - 2] * psie_0[index][1] -
                        dsubtraction[index][1] *
                          dlegendreVector[index][n1 - 2] * psie_0[index][0]);
        }
        for(int n2 = 2; n2 <= _pOrderQuadFace2[iFace] + 1; n2++) {
          faceBasis[faceIt][0] = -dlobattoW[n2] * psie[1];
          faceBasis[faceIt][1] = dlobattoW[n2] * psie[0];
          faceBasis[faceIt][2] = lobattoW[n2] * curlpsie;
          matrixVectorProductForCurlMapping(faceBasis[faceIt]);
          faceIt++;
        }
      }
      for(int n1 = 2; n1 <= _pOrderQuadFace1[iFace] + 1; n1++) {
        std::vector<double> dphie(2, 0);
        dphie[0] =
          dProd[0] * OrthogonalPoly::EvalKernelFunction(n1 - 2, sub[index]) +
          prod * dsubtraction[index][0] *
            OrthogonalPoly::EvalDKernelFunction(n1 - 2, sub[index]);
        dphie[1] =
          dProd[1] * OrthogonalPoly::EvalKernelFunction(n1 - 2, sub[index]) +
          prod * dsubtraction[index][1] *
            OrthogonalPoly::EvalDKernelFunction(n1 - 2, sub[index]);
        for(int n2 = 0; n2 <= _pOrderQuadFace2[iFace]; n2++) {
          faceBasis[faceIt][0] = dphie[1] * legendreW[n2];
          faceBasis[faceIt][1] = -dphie[0] * legendreW[n2];
          faceBasis[faceIt][2] = 0;
          matrixVectorProductForCurlMapping(faceBasis[faceIt]);
          faceIt++;
        }
      }
    }
  }

  // face functions for triangular faces
  double prod123 = lambda1 * lambda2 * lambda3;
  double dlambda123U = 0.5 * lambda1 * (lambda2 - lambda3);
  double dlambda123V = 0.5 * lambda3 * (lambda2 - lambda1);
  for(int iFace = 0; iFace < 2; iFace++) {
    double lambda = 0;
    double dlambda = 0;
    if(iFace == 0) {
      lambda = lambda5;
      dlambda = dlambda5;
    }
    else {
      lambda = lambda4;
      dlambda = dlambda4;
    }
    for(int i = 0; i < 3; i++) {
      switch(i) {
      case(0): {
        double prod = lambda2 * lambda3;
        double dProdU = 0.5 * (lambda2 - lambda3);
        for(int n1 = 2; n1 <= _pOrderTriFace[iFace]; n1++) {
          // edge-based triangular face functions
          faceBasis[faceIt][0] =
            -0.5 * dlambda * prod * legendreVector[i][n1 - 2];
          faceBasis[faceIt][1] = 0;
          faceBasis[faceIt][2] =
            0.5 * lambda *
            (dProdU * legendreVector[i][n1 - 2] +
             prod * dsubtraction[i][0] * dlegendreVector[i][n1 - 2]);
          matrixVectorProductForCurlMapping(faceBasis[faceIt]);
          faceIt++;
        }
      } break;
      case(1): {
        double prod = lambda1 * lambda3;
        double dProdU = 0.5 * lambda1;
        double dProdV = 0.5 * lambda3;
        for(int n1 = 2; n1 <= _pOrderTriFace[iFace]; n1++) {
          faceBasis[faceIt][0] =
            0.5 * dlambda * prod * legendreVector[i][n1 - 2];
          faceBasis[faceIt][1] = -faceBasis[faceIt][0];
          faceBasis[faceIt][2] =
            -0.5 * lambda *
            (dProdU * legendreVector[i][n1 - 2] +
             prod * dsubtraction[i][0] * dlegendreVector[i][n1 - 2] -
             (dProdV * legendreVector[i][n1 - 2] +
              prod * dsubtraction[i][1] * dlegendreVector[i][n1 - 2]));
          matrixVectorProductForCurlMapping(faceBasis[faceIt]);
          faceIt++;
        }
        break;
      }
      case(2): {
        double prod = lambda1 * lambda2;
        double dProdV = 0.5 * (lambda2 - lambda1);
        for(int n1 = 2; n1 <= _pOrderTriFace[iFace]; n1++) {
          // edge-based triangular face functions
          faceBasis[faceIt][0] = 0;
          faceBasis[faceIt][1] =
            0.5 * dlambda * prod * legendreVector[3][n1 - 2];
          faceBasis[faceIt][2] =
            -0.5 * (dProdV * legendreVector[3][n1 - 2] +
                    prod * dsubtraction[3][1] * dlegendreVector[3][n1 - 2]);
          matrixVectorProductForCurlMapping(faceBasis[faceIt]);
          faceIt++;
        }
      } break;
      }
    }
    // Genuine triangular face functions

    for(int n1 = 0; n1 < _pOrderTriFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderTriFace[iFace] - 2 - n1; n2++) {
        faceBasis[faceIt][0] = 0;
        faceBasis[faceIt][1] = 0.5 * dlambda * prod123 * legendreVector[0][n1] *
                               legendreVector[3][n2];
        faceBasis[faceIt][2] =
          -0.5 * lambda *
          (dlambda123V * legendreVector[0][n1] * legendreVector[3][n2] +
           prod123 * dsubtraction[0][1] * dlegendreVector[0][n1] *
             legendreVector[3][n2] +
           prod123 * dsubtraction[3][1] * legendreVector[0][n1] *
             dlegendreVector[3][n2]);
        matrixVectorProductForCurlMapping(faceBasis[faceIt]);
        faceIt++;
      }
    }
    for(int n1 = 0; n1 < _pOrderTriFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderTriFace[iFace] - 2 - n1; n2++) {
        faceBasis[faceIt][0] = -0.5 * dlambda * prod123 *
                               legendreVector[0][n1] * legendreVector[3][n2];
        faceBasis[faceIt][1] = 0; // t_AC
        faceBasis[faceIt][2] =
          0.5 * lambda *
          (dlambda123U * legendreVector[0][n1] * legendreVector[3][n2] +
           prod123 * dsubtraction[0][0] * dlegendreVector[0][n1] *
             legendreVector[3][n2] +
           prod123 * dsubtraction[3][0] * legendreVector[0][n1] *
             dlegendreVector[3][n2]);
        matrixVectorProductForCurlMapping(faceBasis[faceIt]);
        faceIt++;
      }
    }
  }

  // quadrilateral-face-based bubble functions
  int bubbleIt = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int index = 0;
    double prod = 0;
    double dProdU = 0;
    double dProdV = 0;
    switch(iFace) {
    case(0):
      prod = lambda2 * lambda3;
      dProdU = 0.5 * (lambda2 - lambda3);
      index = 0;
      for(int n1 = 2; n1 <= _pb1; n1++) {
        double phi = prod * legendreVector[index][n1 - 2];
        double dphiU =
          (dProdU * legendreVector[index][n1 - 2] +
           prod * dsubtraction[index][0] * dlegendreVector[index][n1 - 2]);
        for(int n2 = 2; n2 <= _pb2 + 1; n2++) {
          bubbleBasis[bubbleIt][0] = -0.5 * dlobattoW[n2] * phi;
          bubbleBasis[bubbleIt][1] = 0;
          bubbleBasis[bubbleIt][2] = 0.5 * lobattoW[n2] * dphiU;
          matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
          bubbleIt++;
        }
      }
      break;
    case(1):
      index = 3;
      prod = lambda1 * lambda2;
      dProdV = 0.5 * (lambda2 - lambda1);
      for(int n1 = 2; n1 <= _pb1; n1++) {
        double phi = prod * legendreVector[index][n1 - 2];
        double dphiV =
          dProdV * legendreVector[index][n1 - 2] +
          prod * dsubtraction[index][1] * dlegendreVector[index][n1 - 2];
        for(int n2 = 2; n2 <= _pb2 + 1; n2++) {
          bubbleBasis[bubbleIt][0] = 0;
          bubbleBasis[bubbleIt][1] = 0.5 * dlobattoW[n2] * phi;
          bubbleBasis[bubbleIt][2] = -0.5 * lobattoW[n2] * dphiV;
          matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
          bubbleIt++;
        }
      }
      break;
    case(2):
      index = 1;
      prod = lambda1 * lambda3;
      dProdU = 0.5 * lambda1;
      dProdV = 0.5 * lambda3;
      for(int n1 = 2; n1 <= _pb1; n1++) {
        double phi = prod * legendreVector[index][n1 - 2];
        double dphi =
          (dProdU * legendreVector[index][n1 - 2] +
           prod * dsubtraction[index][0] * dlegendreVector[index][n1 - 2] -
           (dProdV * legendreVector[index][n1 - 2] +
            prod * dsubtraction[index][1] * dlegendreVector[index][n1 - 2]));
        for(int n2 = 2; n2 <= _pb2 + 1; n2++) {
          bubbleBasis[bubbleIt][0] = 0.5 * phi * dlobattoW[n2];
          bubbleBasis[bubbleIt][1] = -0.5 * phi * dlobattoW[n2];
          bubbleBasis[bubbleIt][2] = -0.5 * lobattoW[n2] * dphi;
          matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
          bubbleIt++;
        }
      }
      break;
    }
  }

  // genuine bubble functions
  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      double phi = prod123 * legendreVector[0][n1] * legendreVector[3][n2];
      double dphiV =
        -(dlambda123V * legendreVector[0][n1] * legendreVector[3][n2] +
          prod123 * dsubtraction[0][1] * dlegendreVector[0][n1] *
            legendreVector[3][n2] +
          prod123 * dsubtraction[3][1] * legendreVector[0][n1] *
            dlegendreVector[3][n2]);
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        bubbleBasis[bubbleIt][0] = 0;
        bubbleBasis[bubbleIt][1] = dlobattoW[n3] * phi;
        bubbleBasis[bubbleIt][2] = lobattoW[n3] * dphiV;
        matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      double phi = prod123 * legendreVector[0][n1] * legendreVector[3][n2];
      double dphiU =
        -(dlambda123U * legendreVector[0][n1] * legendreVector[3][n2] +
          prod123 * dsubtraction[0][0] * dlegendreVector[0][n1] *
            legendreVector[3][n2] +
          prod123 * dsubtraction[3][0] * legendreVector[0][n1] *
            dlegendreVector[3][n2]);
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        bubbleBasis[bubbleIt][0] = dlobattoW[n3] * phi;
        bubbleBasis[bubbleIt][1] = 0;
        bubbleBasis[bubbleIt][2] = lobattoW[n3] * dphiU;
        matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
  // triangular-face-based bubble functions
  for(int n1 = 0; n1 < _pb1 - 1; n1++) {
    for(int n2 = 0; n2 < _pb1 - 1 - n1; n2++) {
      double dphiU =
        -(dlambda123U * legendreVector[0][n1] * legendreVector[3][n2] +
          prod123 * dsubtraction[0][0] * dlegendreVector[0][n1] *
            legendreVector[3][n2] +
          prod123 * dsubtraction[3][0] * legendreVector[0][n1] *
            dlegendreVector[3][n2]);
      double dphiV =
        dlambda123V * legendreVector[0][n1] * legendreVector[3][n2] +
        prod123 * dsubtraction[0][1] * dlegendreVector[0][n1] *
          legendreVector[3][n2] +
        prod123 * dsubtraction[3][1] * legendreVector[0][n1] *
          dlegendreVector[3][n2];
      for(int n3 = 0; n3 <= _pb2; n3++) {
        bubbleBasis[bubbleIt][0] = dphiV * legendreW[n3];
        bubbleBasis[bubbleIt][1] = dphiU * legendreW[n3];
        bubbleBasis[bubbleIt][2] = 0;
        matrixVectorProductForCurlMapping(bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
  }
}

void HierarchicalBasisHcurlPri::getKeysInfo(std::vector<int> &functionTypeInfo,
                                            std::vector<int> &orderInfo)
{
  int it = 0;
  for(int numEdge = 0; numEdge < 9; numEdge++) {
    for(int i = 0; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    for(int n1 = 0; n1 <= _pOrderQuadFace1[iFace]; n1++) {
      for(int n2 = 2; n2 <= _pOrderQuadFace2[iFace] + 1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
        it++;
      }
    }
    for(int n1 = 2; n1 <= _pOrderQuadFace1[iFace] + 1; n1++) {
      for(int n2 = 0; n2 <= _pOrderQuadFace2[iFace]; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
        it++;
      }
    }
  }
  for(int iFace = 0; iFace < 2; iFace++) {
    for(int i = 0; i < 3; i++) {
      for(int n1 = 2; n1 <= _pOrderTriFace[iFace]; n1++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1;
        it++;
      }
    }
    for(int n1 = 1; n1 < _pOrderTriFace[iFace] - 1; n1++) {
      for(int n2 = 1; n2 <= _pOrderTriFace[iFace] - 1 - n1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
    for(int n1 = 1; n1 < _pOrderTriFace[iFace] - 1; n1++) {
      for(int n2 = 1; n2 <= _pOrderTriFace[iFace] - 1 - n1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
  }
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    for(int n1 = 2; n1 <= _pb1; n1++) {
      for(int n2 = 2; n2 <= _pb2 + 1; n2++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1, n2);
        it++;
      }
    }
  }
  for(int n1 = 1; n1 < _pb1 - 1; n1++) {
    for(int n2 = 1; n2 <= _pb1 - 1 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1 + n2 + 1, n3);
        it++;
      }
    }
  }
  for(int n1 = 1; n1 < _pb1 - 1; n1++) {
    for(int n2 = 1; n2 <= _pb1 - 1 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1 + n2 + 1, n3);
        it++;
      }
    }
  }
  for(int n1 = 1; n1 <= _pb1 - 1; n1++) {
    for(int n2 = 1; n2 <= _pb1 - n1; n2++) {
      for(int n3 = 0; n3 <= _pb2; n3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1 + n2 + 1, n3);
        it++;
      }
    }
  }
}
