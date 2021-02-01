// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include "HierarchicalBasisH1Tetra.h"
HierarchicalBasisH1Tetra::HierarchicalBasisH1Tetra(int order)
{
  _nvertex = 4;
  _nedge = 6;
  _nfaceTri = 4;
  _nfaceQuad = 0;
  _nVertexFunction = 4;
  _nEdgeFunction = 6 * order - 6;
  _nQuadFaceFunction = 0;
  _nTriFaceFunction = 2 * (order - 2) * (order - 1);
  _nBubbleFunction = (order - 1) * (order - 2) * (order - 3) / 6;
  _pb = order;
  for(int i = 0; i < 4; i++) { _pOrderFace[i] = order; }
  for(int i = 0; i < 6; i++) { _pOrderEdge[i] = order; }
}

HierarchicalBasisH1Tetra::~HierarchicalBasisH1Tetra() {}

unsigned int HierarchicalBasisH1Tetra::getNumberOfOrientations() const
{
  return 24; // factorial 4
}

double HierarchicalBasisH1Tetra::_affineCoordinate(const int &j,
                                                   const double &u,
                                                   const double &v,
                                                   const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (1 + u + v + w);
  case(3): return 0.5 * (1 + u);
  case(4): return 0.5 * (1 + w);
  default: throw std::string("j must be : 1<=j<=4");
  }
}

void HierarchicalBasisH1Tetra::generateBasis(double const &u, double const &v,
                                             double const &w,
                                             std::vector<double> &vertexBasis,
                                             std::vector<double> &edgeBasis,
                                             std::vector<double> &faceBasis,
                                             std::vector<double> &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = 2 * w - 1;
  //*****
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double prod = lambda1 * lambda2 * lambda3 * lambda4;
  // vertex shape functions:
  vertexBasis[0] = lambda2;
  vertexBasis[1] = lambda3;
  vertexBasis[2] = lambda1;
  vertexBasis[3] = lambda4;
  // compute the terms to assemble
  std::vector<double> substraction(_nedge);
  substraction[0] = lambda3 - lambda2;
  substraction[1] = lambda1 - lambda3;
  substraction[2] = lambda1 - lambda2;
  substraction[3] = lambda4 - lambda2;
  substraction[4] = lambda4 - lambda1;
  substraction[5] = lambda4 - lambda3;
  std::vector<std::vector<double> > phi(_nedge);
  phi[0] = std::vector<double>(
    std::max(std::max(std::max(_pOrderEdge[0] - 1, _pOrderFace[0] - 2),
                      _pOrderFace[1] - 2),
             _pb - 3));
  phi[1] =
    std::vector<double>(std::max(_pOrderEdge[1] - 1, _pOrderFace[3] - 2));
  phi[2] = std::vector<double>(
    std::max(std::max(std::max(_pOrderEdge[2] - 1, _pOrderFace[0] - 2),
                      _pOrderFace[2] - 2),
             _pb - 3));
  phi[3] = std::vector<double>(
    std::max(std::max(std::max(_pOrderEdge[3] - 1, _pOrderFace[1] - 2),
                      _pOrderFace[2] - 2),
             _pb - 3));
  phi[4] = std::vector<double>(_pOrderEdge[4] - 1);
  phi[5] =
    std::vector<double>(std::max(_pOrderEdge[5] - 1, _pOrderFace[3] - 2));
  for(int i = 0; i < _nedge; i++) {
    for(unsigned int j = 0; j < phi[i].size(); j++) {
      phi[i][j] = OrthogonalPoly::EvalKernelFunction(j, substraction[i]);
    }
  }
  std::vector<double> edgeProduct(_nedge);
  edgeProduct[0] = lambda3 * lambda2;
  edgeProduct[1] = lambda1 * lambda3;
  edgeProduct[2] = lambda2 * lambda1;
  edgeProduct[3] = lambda4 * lambda2;
  edgeProduct[4] = lambda4 * lambda1;
  edgeProduct[5] = lambda4 * lambda3;
  std::vector<double> faceProduct(_nfaceTri);
  faceProduct[0] = edgeProduct[0] * lambda1;
  faceProduct[1] = edgeProduct[0] * lambda4;
  faceProduct[2] = edgeProduct[2] * lambda4;
  faceProduct[3] = edgeProduct[1] * lambda4;
  // edge shape functions:
  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      if(iEdge == 2 && indexEdgeFunc % 2 != 0) {
        edgeBasis[indexEdgeBasis] =
          (-1) * edgeProduct[iEdge] * phi[iEdge][indexEdgeFunc];
      }
      else {
        edgeBasis[indexEdgeBasis] =
          edgeProduct[iEdge] * phi[iEdge][indexEdgeFunc];
      }

      indexEdgeBasis++;
    }
  }
  // face shape functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceTri; iFace++) {
    int indexVectorTarget1 = 0;
    int indexVectorTarget2 = 0;
    switch(iFace) {
    case(0):
      indexVectorTarget1 = 0;
      indexVectorTarget2 = 2;
      break;
    case(1):
      indexVectorTarget1 = 0;
      indexVectorTarget2 = 3;
      break;
    case(2):
      indexVectorTarget1 = 2;
      indexVectorTarget2 = 3;
      break;
    case(3):
      indexVectorTarget1 = 1;
      indexVectorTarget2 = 5;
      break;
    }
    for(int n1 = 0; n1 < _pOrderFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[iFace] - 2 - n1; n2++) {
        int impact = 1;
        if(n2 % 2 != 0) { impact = -1; }
        faceBasis[indexFaceFunction] = impact * faceProduct[iFace] *
                                       phi[indexVectorTarget1][n1] *
                                       phi[indexVectorTarget2][n2];
        indexFaceFunction++;
      }
    }
  }

  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int n1 = 0; n1 < _pb - 3; n1++) {
    for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
      for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
        bubbleBasis[indexBubbleBasis] =
          phi[2][n1] * phi[0][n2] * phi[3][n3] * prod;
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisH1Tetra::orientEdge(
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
void HierarchicalBasisH1Tetra::orientEdge(
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

void HierarchicalBasisH1Tetra::orientEdgeFunctionsForNegativeFlag(
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

void HierarchicalBasisH1Tetra::orientEdgeFunctionsForNegativeFlag(
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
void HierarchicalBasisH1Tetra::orientOneFace(double const &u, double const &v,
                                             double const &w, int const &flag1,
                                             int const &flag2, int const &flag3,
                                             int const &faceNumber,
                                             std::vector<double> &faceBasis)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    // to map onto the reference domain of gmsh:
    double uc = 2 * u - 1;
    double vc = 2 * v - 1;
    double wc = 2 * w - 1;
    //*****
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += int((_pOrderFace[i] - 1) * (_pOrderFace[i] - 2) / 2);
    }
    std::vector<double> lambda(3);
    switch(faceNumber) {
    case(0):
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(3, uc, vc, wc);
      lambda[2] = _affineCoordinate(1, uc, vc, wc);
      break;
    case(1):
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(3, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      break;
    case(2):
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(1, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      break;
    case(3):
      lambda[0] = _affineCoordinate(3, uc, vc, wc);
      lambda[1] = _affineCoordinate(1, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      break;
    }
    double product = lambda[0] * lambda[1] * lambda[2];
    if(flag1 == 1 && flag2 == -1) {
      double copy = lambda[0];
      lambda[0] = lambda[1];
      lambda[1] = copy;
    }
    else if(flag1 == 0 && flag2 == -1) {
      double copy = lambda[2];
      lambda[2] = lambda[1];
      lambda[1] = copy;
    }
    else if(flag1 == 2 && flag2 == -1) {
      double copy = lambda[2];
      lambda[2] = lambda[0];
      lambda[0] = copy;
    }
    else if(flag1 == 1 && flag2 == 1) {
      double copy = lambda[0];
      lambda[0] = lambda[1];
      lambda[1] = lambda[2];
      lambda[2] = copy;
    }
    else if(flag1 == 2 && flag2 == 1) {
      double copy = lambda[0];
      lambda[0] = lambda[2];
      lambda[2] = lambda[1];
      lambda[1] = copy;
    }
    double subs1 = lambda[1] - lambda[0];
    double subs2 = lambda[0] - lambda[2];
    std::vector<double> phiSubs2(_pOrderFace[faceNumber] - 2);
    for(int it = 0; it < _pOrderFace[faceNumber] - 2; it++) {
      phiSubs2[it] = OrthogonalPoly::EvalKernelFunction(it, subs2);
    }
    for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
      double phiSubs1 = OrthogonalPoly::EvalKernelFunction(n1, subs1);
      for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
        faceBasis[iterator] = product * phiSubs1 * phiSubs2[n2];
        iterator++;
      }
    }
  }
}
void HierarchicalBasisH1Tetra::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &gradientFace, std::string typeFunction)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    // to map onto the reference domain of gmsh:
    double uc = 2 * u - 1;
    double vc = 2 * v - 1;
    double wc = 2 * w - 1;
    //*****
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += int((_pOrderFace[i] - 1) * (_pOrderFace[i] - 2) / 2);
    }
    std::vector<double> lambda(3);
    std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
    std::vector<double> dProduct(3); // gradient of (lambdaA*lambdaB*lambdaC)
    switch(faceNumber) {
    case(0): {
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(3, uc, vc, wc);
      lambda[2] = _affineCoordinate(1, uc, vc, wc);
      dlambda[0][0] = -1; //* jacobian
      dlambda[0][1] = -1; //* jacobian
      dlambda[0][2] = -1; //* jacobian
      dlambda[1][0] = 1; //* jacobian
      dlambda[2][1] = 1; //* jacobian
      double pl3l1 = lambda[1] * lambda[2];
      dProduct[0] = lambda[2] * lambda[0] - pl3l1;
      dProduct[1] = lambda[0] * lambda[1] - pl3l1;
      dProduct[2] = -pl3l1; //*jacobian
      break;
    }
    case(1): {
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(3, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      dlambda[0][0] = -1; //* jacobian
      dlambda[0][1] = -1; //* jacobian
      dlambda[0][2] = -1; //* jacobian
      dlambda[1][0] = 1; //* jacobian
      dlambda[2][2] = 1; //* jacobian
      double pl3l4 = lambda[1] * lambda[2];
      dProduct[0] = lambda[2] * lambda[0] - pl3l4; //*jacobian
      dProduct[1] = -pl3l4;
      dProduct[2] = lambda[0] * lambda[1] - pl3l4;
      break;
    }
    case(2): {
      lambda[0] = _affineCoordinate(2, uc, vc, wc);
      lambda[1] = _affineCoordinate(1, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      dlambda[0][0] = -1; //* jacobian
      dlambda[0][1] = -1; //* jacobian
      dlambda[0][2] = -1; //* jacobian
      dlambda[1][1] = 1; //* jacobian
      dlambda[2][2] = 1; //* jacobian
      double pl1l4 = lambda[1] * lambda[2];
      dProduct[0] = -pl1l4;
      dProduct[1] = lambda[0] * lambda[2] - pl1l4;
      dProduct[2] = lambda[0] * lambda[1] - pl1l4; //*jacobian
      break;
    }
    case(3): {
      lambda[0] = _affineCoordinate(3, uc, vc, wc);
      lambda[1] = _affineCoordinate(1, uc, vc, wc);
      lambda[2] = _affineCoordinate(4, uc, vc, wc);
      dlambda[0][0] = 1; //* jacobian
      dlambda[1][1] = 1; //* jacobian
      dlambda[2][2] = 1; //* jacobian
      dProduct[0] = lambda[1] * lambda[2];
      dProduct[1] = lambda[0] * lambda[2];
      dProduct[2] = lambda[0] * lambda[1];
      break;
    }
    }
    double product = lambda[0] * lambda[1] * lambda[2];
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
    double subsBA = lambda[1] - lambda[0];
    double subsAC = lambda[0] - lambda[2];
    std::vector<double> dsubsBA(3);
    std::vector<double> dsubsAC(3);
    for(int i = 0; i < 3; i++) {
      dsubsBA[i] = dlambda[1][i] - dlambda[0][i];
      dsubsAC[i] = dlambda[0][i] - dlambda[2][i];
    }
    std::vector<double> phiSubsAC(_pOrderFace[faceNumber] - 2);
    std::vector<double> dphiSubsAC(_pOrderFace[faceNumber] - 2);
    for(int it = 0; it < _pOrderFace[faceNumber] - 2; it++) {
      phiSubsAC[it] = OrthogonalPoly::EvalKernelFunction(it, subsAC);
      dphiSubsAC[it] = OrthogonalPoly::EvalDKernelFunction(it, subsAC);
    }
    for(int n1 = 0; n1 < _pOrderFace[faceNumber] - 2; n1++) {
      double phiBA = OrthogonalPoly::EvalKernelFunction(n1, subsBA);
      double dphiBA = OrthogonalPoly::EvalDKernelFunction(n1, subsBA);
      for(int n2 = 0; n2 < _pOrderFace[faceNumber] - 2 - n1; n2++) {
        for(int i = 0; i < 3; i++) {
          gradientFace[iterator][i] =
            dProduct[i] * phiBA * phiSubsAC[n2] +
            product * dphiBA * dsubsBA[i] * phiSubsAC[n2] +
            product * phiBA * dsubsAC[i] * dphiSubsAC[n2];
        }
        iterator++;
      }
    }
  }
}
void HierarchicalBasisH1Tetra::generateGradientBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &gradientVertex,
  std::vector<std::vector<double> > &gradientEdge,
  std::vector<std::vector<double> > &gradientFace,
  std::vector<std::vector<double> > &gradientBubble)
{
  // to map onto the reference domain of gmsh:
  // ****
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = 2 * w - 1;
  double jacob = 2; // jacobian=((2,0,0),(0,2,0),(0,0,2))
  //****
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double prod = lambda1 * lambda2 * lambda3 * lambda4;
  // gradient:
  std::vector<double> dlambda1(3, 0);
  std::vector<double> dlambda2(3, -0.5);
  std::vector<double> dlambda3(3, 0);
  std::vector<double> dlambda4(3, 0);
  dlambda1[1] = 0.5;
  dlambda3[0] = 0.5;
  dlambda4[2] = 0.5;
  std::vector<double> dprod(3); // d(lambda1*lambda2*lambda3*lambda4)
  dprod[0] = jacob * (lambda1 * dlambda2[0] * lambda3 * lambda4 +
                      lambda1 * lambda2 * dlambda3[0] * lambda4);
  dprod[1] = jacob * (dlambda1[1] * lambda2 * lambda3 * lambda4 +
                      lambda1 * dlambda2[1] * lambda3 * lambda4);
  dprod[2] = jacob * (lambda1 * dlambda2[2] * lambda3 * lambda4 +
                      lambda1 * lambda2 * lambda3 * dlambda4[2]);
  // gradient of vertex functions:
  // jacob *dlambda
  gradientVertex[0][0] = -1;
  gradientVertex[0][1] = -1;
  gradientVertex[0][2] = -1;
  gradientVertex[1][0] = 1;
  gradientVertex[1][1] = 0;
  gradientVertex[1][2] = 0;
  gradientVertex[2][0] = 0;
  gradientVertex[2][1] = 1;
  gradientVertex[2][2] = 0;
  gradientVertex[3][0] = 0;
  gradientVertex[3][1] = 0;
  gradientVertex[3][2] = 1;
  // compute the terms to assemble
  std::vector<double> substraction(_nedge);
  substraction[0] = lambda3 - lambda2;
  substraction[1] = lambda1 - lambda3;
  substraction[2] = lambda1 - lambda2;
  substraction[3] = lambda4 - lambda2;
  substraction[4] = lambda4 - lambda1;
  substraction[5] = lambda4 - lambda3;
  std::vector<std::vector<double> > dsubstraction(
    _nedge, std::vector<double>(3, 1)); // = dsubstraction*jacob
  dsubstraction[0][0] = 2;
  dsubstraction[1][0] = -1;
  dsubstraction[1][2] = 0;
  dsubstraction[2][1] = 2.;
  dsubstraction[3][2] = 2.;
  dsubstraction[4][0] = 0;
  dsubstraction[4][1] = -1;
  dsubstraction[5][0] = -1;
  dsubstraction[5][1] = 0;
  std::vector<std::vector<double> > phi(_nedge);
  std::vector<std::vector<double> > dphi(_nedge);
  for(int i = 0; i < _nedge; i++) {
    int vectorSize = 0;
    switch(i) {
    case 0:
      vectorSize =
        std::max(std::max(std::max(_pOrderEdge[0] - 1, _pOrderFace[0] - 2),
                          _pOrderFace[1] - 2),
                 _pb - 3);
      break;
    case 1:
      vectorSize = std::max(_pOrderEdge[1] - 1, _pOrderFace[3] - 2);
      break;
    case 2:
      vectorSize =
        std::max(std::max(std::max(_pOrderEdge[2] - 1, _pOrderFace[0] - 2),
                          _pOrderFace[2] - 2),
                 _pb - 3);
      break;
    case 3:
      vectorSize =
        std::max(std::max(std::max(_pOrderEdge[3] - 1, _pOrderFace[1] - 2),
                          _pOrderFace[2] - 2),
                 _pb - 3);
      break;
    case 4: vectorSize = _pOrderEdge[4] - 1; break;
    case 5:
      vectorSize = std::max(_pOrderEdge[5] - 1, _pOrderFace[3] - 2);
      break;
    }
    phi[i] = std::vector<double>(vectorSize);
    dphi[i] = std::vector<double>(vectorSize);
    for(unsigned int j = 0; j < phi[i].size(); j++) {
      phi[i][j] = OrthogonalPoly::EvalKernelFunction(j, substraction[i]);
      dphi[i][j] = OrthogonalPoly::EvalDKernelFunction(j, substraction[i]);
    }
  }
  std::vector<double> edgeProduct(_nedge);
  edgeProduct[0] = lambda3 * lambda2;
  edgeProduct[1] = lambda1 * lambda3;
  edgeProduct[2] = lambda2 * lambda1;
  edgeProduct[3] = lambda4 * lambda2;
  edgeProduct[4] = lambda4 * lambda1;
  edgeProduct[5] = lambda4 * lambda3;
  std::vector<std::vector<double> > dEdgeProduct(_nedge,
                                                 std::vector<double>(3));
  for(int i = 0; i < 3; i++) {
    dEdgeProduct[0][i] =
      jacob * (dlambda3[i] * lambda2 + lambda3 * dlambda2[i]);
    dEdgeProduct[1][i] =
      jacob * (dlambda1[i] * lambda3 + lambda1 * dlambda3[i]);
    dEdgeProduct[2][i] =
      jacob * (dlambda2[i] * lambda1 + lambda2 * dlambda1[i]);
    dEdgeProduct[3][i] =
      jacob * (dlambda4[i] * lambda2 + lambda4 * dlambda2[i]);
    dEdgeProduct[4][i] =
      jacob * (dlambda4[i] * lambda1 + lambda4 * dlambda1[i]);
    dEdgeProduct[5][i] =
      jacob * (dlambda4[i] * lambda3 + lambda4 * dlambda3[i]);
  }
  std::vector<double> faceProduct(_nfaceTri);
  faceProduct[0] = edgeProduct[0] * lambda1;
  faceProduct[1] = edgeProduct[0] * lambda4;
  faceProduct[2] = edgeProduct[2] * lambda4;
  faceProduct[3] = edgeProduct[1] * lambda4;
  std::vector<std::vector<double> > dfaceProduct(_nfaceTri,
                                                 std::vector<double>(3));
  for(int i = 0; i < 3; i++) {
    dfaceProduct[0][i] =
      jacob * (edgeProduct[0] * dlambda1[i]) + dEdgeProduct[0][i] * lambda1;
    dfaceProduct[1][i] =
      jacob * (edgeProduct[0] * dlambda4[i]) + dEdgeProduct[0][i] * lambda4;
    dfaceProduct[2][i] =
      jacob * (edgeProduct[2] * dlambda4[i]) + dEdgeProduct[2][i] * lambda4;
    dfaceProduct[3][i] =
      jacob * (edgeProduct[1] * dlambda4[i]) + dEdgeProduct[1][i] * lambda4;
  }
  // edge shape functions:
  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      int impact1 = 1;
      if(iEdge == 2) {
        impact1 = 1;
        if(indexEdgeFunc % 2 != 0) { impact1 = -1; }
      }
      for(int i = 0; i < 3; i++) {
        gradientEdge[indexEdgeBasis][i] =
          impact1 * (dEdgeProduct[iEdge][i] * phi[iEdge][indexEdgeFunc] +
                     edgeProduct[iEdge] * dphi[iEdge][indexEdgeFunc] *
                       dsubstraction[iEdge][i]);
      }
      indexEdgeBasis++;
    }
  }
  // face shape functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceTri; iFace++) {
    int indexVectorTarget1 = 0;
    int indexVectorTarget2 = 0;
    switch(iFace) {
    case(0):
      indexVectorTarget1 = 0;
      indexVectorTarget2 = 2;
      break;
    case(1):
      indexVectorTarget1 = 0;
      indexVectorTarget2 = 3;
      break;
    case(2):
      indexVectorTarget1 = 2;
      indexVectorTarget2 = 3;
      break;
    case(3):
      indexVectorTarget1 = 1;
      indexVectorTarget2 = 5;
      break;
    }
    for(int n1 = 0; n1 < _pOrderFace[iFace] - 2; n1++) {
      for(int n2 = 0; n2 < _pOrderFace[iFace] - 2 - n1; n2++) {
        int impact = 1;
        if(n2 % 2 != 0) { impact = -1; }
        for(int i = 0; i < 3; i++) {
          gradientFace[indexFaceFunction][i] =
            impact * (dfaceProduct[iFace][i] * phi[indexVectorTarget1][n1] *
                        phi[indexVectorTarget2][n2] +
                      faceProduct[iFace] * dphi[indexVectorTarget1][n1] *
                        dsubstraction[indexVectorTarget1][i] *
                        phi[indexVectorTarget2][n2] +
                      faceProduct[iFace] * phi[indexVectorTarget1][n1] *
                        dsubstraction[indexVectorTarget2][i] *
                        dphi[indexVectorTarget2][n2]);
        }
        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int n1 = 0; n1 < _pb - 3; n1++) {
    for(int n2 = 0; n2 < _pb - 3 - n1; n2++) {
      for(int n3 = 0; n3 < _pb - 3 - n2 - n1; n3++) {
        for(int i = 0; i < 3; i++) {
          gradientBubble[indexBubbleBasis][i] =
            phi[2][n1] * phi[0][n2] * phi[3][n3] * dprod[i] +
            dsubstraction[2][i] * dphi[2][n1] * phi[0][n2] * phi[3][n3] * prod +
            dsubstraction[0][i] * phi[2][n1] * dphi[0][n2] * phi[3][n3] * prod +
            dsubstraction[3][i] * phi[2][n1] * phi[0][n2] * dphi[3][n3] * prod;
        }
        indexBubbleBasis++;
      }
    }
  }
}
void HierarchicalBasisH1Tetra::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<double> &quadFaceFunctionsAllOrientation,
  const std::vector<double> &triFaceFunctionsAllOrientation,
  std::vector<double> &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += int((_pOrderFace[i] - 1) * (_pOrderFace[i] - 2) / 2);
  }
  int numFaceFunctions =
    int((_pOrderFace[faceNumber] - 1) * (_pOrderFace[faceNumber] - 2) / 2);
  int iOrientation = numberOrientationTriFace(flag1, flag2);
  int offset = iOrientation * _nTriFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i] = triFaceFunctionsAllOrientation[i + offset];
  }
}
void HierarchicalBasisH1Tetra::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += int((_pOrderFace[i] - 1) * (_pOrderFace[i] - 2) / 2);
  }
  int numFaceFunctions =
    int((_pOrderFace[faceNumber] - 1) * (_pOrderFace[faceNumber] - 2) / 2);
  int iOrientation = numberOrientationTriFace(flag1, flag2);
  int offset = iOrientation * _nTriFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i][0] = triFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = triFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = triFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisH1Tetra::getKeysInfo(std::vector<int> &functionTypeInfo,
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
  for(int numEdge = 0; numEdge < 6; numEdge++) {
    for(int i = 2; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int numFace = 0; numFace < 4; numFace++) {
    for(int n1 = 1; n1 < _pOrderFace[numFace] - 1; n1++) {
      for(int n2 = 1; n2 <= _pOrderFace[numFace] - 1 - n1; n2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 1;
        it++;
      }
    }
  }
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
