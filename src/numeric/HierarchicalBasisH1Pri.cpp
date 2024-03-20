// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth, Ivo Dolezel, Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include <stdexcept>
#include "HierarchicalBasisH1Pri.h"

HierarchicalBasisH1Pri::HierarchicalBasisH1Pri(int order)
{
  _nvertex = 6;
  _nedge = 9;
  if(order < 3) { _nfaceTri = 0; }
  else {
    _nfaceTri = 2;
  }
  _nfaceQuad = 3;
  _nVertexFunction = 6;
  _nEdgeFunction = 9 * order - 9;
  _nQuadFaceFunction = 3 * (order - 1) * (order - 1);
  _nTriFaceFunction = (order - 2) * (order - 1);
  _nBubbleFunction = (order - 1) * (order - 2) * (order - 1) / 2;
  _pb1 = order;
  _pb2 = order;
  for(int i = 0; i < 3; i++) {
    _pOrderQuadFace1[i] = order;
    _pOrderQuadFace2[i] = order;
  }
  for(int i = 0; i < 2; i++) { _pOrderTriFace[i] = order; }
  for(int i = 0; i < 9; i++) { _pOrderEdge[i] = order; }
}

HierarchicalBasisH1Pri::~HierarchicalBasisH1Pri() {}

unsigned int HierarchicalBasisH1Pri::getNumberOfOrientations() const
{
  return 720; // factorial 6
}

double HierarchicalBasisH1Pri::_affineCoordinate(const int &j, const double &u,
                                                 const double &v,
                                                 const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  case(4): return 0.5 * (1 + w);
  case(5): return 0.5 * (1 - w);
  default: throw std::runtime_error("j must be : 1<=j<=5");
  }
}
void HierarchicalBasisH1Pri::generateBasis(double const &u, double const &v,
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
  double wc = w;
  //*****
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double lambda5 = _affineCoordinate(5, uc, vc, wc);
  // vertex shape functions:
  vertexBasis[0] = lambda2 * lambda5;
  vertexBasis[1] = lambda3 * lambda5;
  vertexBasis[2] = lambda1 * lambda5;
  vertexBasis[3] = lambda2 * lambda4;
  vertexBasis[4] = lambda4 * lambda3;
  vertexBasis[5] = lambda1 * lambda4;
  // compute the terms to assemble
  std::vector<double> product(_nedge);
  product[0] = vertexBasis[0] * lambda3;
  product[1] = vertexBasis[0] * lambda1;
  product[2] = vertexBasis[0] * lambda4;
  product[3] = vertexBasis[1] * lambda1;
  product[4] = vertexBasis[1] * lambda4;
  product[5] = vertexBasis[2] * lambda4;
  product[6] = vertexBasis[3] * lambda3;
  product[7] = vertexBasis[3] * lambda1;
  product[8] = vertexBasis[4] * lambda1;
  std::vector<double> substraction(5);
  substraction[0] = lambda3 - lambda2;
  substraction[1] = lambda1 - lambda2;
  substraction[2] = lambda4 - lambda5;
  substraction[3] = lambda1 - lambda3;
  substraction[4] = lambda2 - lambda1;
  std::vector<std::vector<double> > phi(5);
  phi[0] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[0] - 1, _pOrderEdge[6] - 1),
                               _pOrderQuadFace1[0] - 1),
                      _pOrderTriFace[0] - 2),
             _pOrderTriFace[1] - 2),
    _pb1 - 2));
  phi[1] = std::vector<double>(std::max(
    std::max(_pOrderEdge[1] - 1, _pOrderEdge[7] - 1), _pOrderQuadFace1[1] - 1));
  phi[2] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[2] - 1, _pOrderEdge[4] - 1),
                               _pOrderEdge[5] - 1),
                      _pOrderQuadFace2[0] - 1),
             _pOrderQuadFace2[1] - 1),
    _pOrderQuadFace2[2] - 1));

  phi[3] = std::vector<double>(std::max(
    std::max(_pOrderEdge[8] - 1, _pOrderEdge[3] - 1), _pOrderQuadFace1[2] - 1));
  phi[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderTriFace[1] - 2, _pb1 - 2), _pOrderTriFace[0] - 2),
    0));
  for(int i = 0; i < 5; i++) {
    for(unsigned int j = 0; j < phi[i].size(); j++) {
      phi[i][j] = OrthogonalPoly::EvalKernelFunction(j, substraction[i]);
    }
  }
  // edge shape functions:
  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    int numPhi = 0;
    switch(iEdge) {
    case(0):
    case(6): numPhi = 0; break;
    case(1):
    case(7): numPhi = 1; break;
    case(2):
    case(4):
    case(5): numPhi = 2; break;
    case(3):
    case(8): numPhi = 3; break;
    }
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      edgeBasis[indexEdgeBasis] = product[iEdge] * phi[numPhi][indexEdgeFunc];

      indexEdgeBasis++;
    }
  }
  // face shape functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad + _nfaceTri; iFace++) {
    int indexPhi1 = 0;
    int indexPhi2 = 0;
    double lambdaProduct = 0;
    switch(iFace) {
    case(3):
      indexPhi1 = 0;
      indexPhi2 = 4;
      lambdaProduct = product[0] * lambda1;
      break;
    case(4):
      indexPhi1 = 0;
      indexPhi2 = 4;
      lambdaProduct = product[7] * lambda3;
      break;
    case(0):
      indexPhi1 = 0;
      indexPhi2 = 2;
      lambdaProduct = product[0] * lambda4;
      break;
    case(1):
      indexPhi1 = 1;
      indexPhi2 = 2;
      lambdaProduct = product[7] * lambda5;
      break;
    case(2):
      indexPhi1 = 3;
      indexPhi2 = 2;
      lambdaProduct = product[8] * lambda5;
      break;
    }
    if(iFace < 3) {
      for(int n1 = 0; n1 < _pOrderQuadFace1[iFace] - 1; n1++) {
        for(int n2 = 0; n2 < _pOrderQuadFace2[iFace] - 1; n2++) {
          faceBasis[indexFaceFunction] =
            lambdaProduct * phi[indexPhi1][n1] * phi[indexPhi2][n2];
          indexFaceFunction++;
        }
      }
    }
    else {
      for(int n1 = 0; n1 < _pOrderTriFace[iFace - 3] - 2; n1++) {
        for(int n2 = 0; n2 < _pOrderTriFace[iFace - 3] - 2 - n1; n2++) {
          faceBasis[indexFaceFunction] =
            lambdaProduct * phi[indexPhi1][n1] * phi[indexPhi2][n2];
          indexFaceFunction++;
        }
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  double lambdaProductBubble = lambda1 * lambda2 * lambda3;
  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2; n3++) {
        bubbleBasis[indexBubbleBasis] = lambdaProductBubble * phi[0][n1] *
                                        phi[4][n2] *
                                        OrthogonalPoly::EvalLobatto(n3, w);
        indexBubbleBasis++;
      }
    }
  }
}
void HierarchicalBasisH1Pri::generateGradientBasis(
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
  double wc = w;
  // jacobian=((2,0,0),(0,2,0),(0,0,1))
  //*******
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double lambda5 = _affineCoordinate(5, uc, vc, wc);
  // gradient:
  std::vector<double> dlambda1(3, 0);
  std::vector<double> dlambda2(3, 0);
  std::vector<double> dlambda3(3, 0);
  std::vector<double> dlambda4(3, 0);
  std::vector<double> dlambda5(3, 0);
  dlambda1[1] = 1; // * jacob
  dlambda2[0] = -1;
  dlambda2[1] = -1;
  dlambda3[0] = 1;
  dlambda4[2] = 0.5;
  dlambda5[2] = -0.5;
  for(int i = 0; i < 3; i++) {
    gradientVertex[0][i] = lambda5 * dlambda2[i] + dlambda5[i] * lambda2;
    gradientVertex[1][i] = lambda5 * dlambda3[i] + dlambda5[i] * lambda3;
    gradientVertex[2][i] = lambda5 * dlambda1[i] + dlambda5[i] * lambda1;
    gradientVertex[3][i] = lambda2 * dlambda4[i] + dlambda2[i] * lambda4;
    gradientVertex[4][i] = lambda4 * dlambda3[i] + dlambda4[i] * lambda3;
    gradientVertex[5][i] = lambda1 * dlambda4[i] + dlambda1[i] * lambda4;
  }
  // compute the terms to assemble
  std::vector<double> substraction(5);
  substraction[0] = lambda3 - lambda2;
  substraction[1] = lambda1 - lambda2;
  substraction[2] = lambda4 - lambda5;
  substraction[3] = lambda1 - lambda3;
  substraction[4] = lambda2 - lambda1;
  std::vector<std::vector<double> > dsubstraction(
    5, std::vector<double>(3, 0)); // = dsubstraction*jacob
  for(int i = 0; i < 3; i++) {
    dsubstraction[0][i] = dlambda3[i] - dlambda2[i];
    dsubstraction[1][i] = dlambda1[i] - dlambda2[i];
    dsubstraction[2][i] = dlambda4[i] - dlambda5[i];
    dsubstraction[3][i] = dlambda1[i] - dlambda3[i];
    dsubstraction[4][i] = dlambda2[i] - dlambda1[i];
  }
  std::vector<std::vector<double> > phi(5);
  std::vector<std::vector<double> > dphi(5);
  phi[0] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[0] - 1, _pOrderEdge[6] - 1),
                               _pOrderQuadFace1[0] - 1),
                      _pOrderTriFace[0] - 2),
             _pOrderTriFace[1] - 2),
    _pb1 - 2));
  phi[1] = std::vector<double>(std::max(
    std::max(_pOrderEdge[1] - 1, _pOrderEdge[7] - 1), _pOrderQuadFace1[1] - 1));
  phi[2] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[2] - 1, _pOrderEdge[4] - 1),
                               _pOrderEdge[5] - 1),
                      _pOrderQuadFace2[0] - 1),
             _pOrderQuadFace2[1] - 1),
    _pOrderQuadFace2[2] - 1));

  phi[3] = std::vector<double>(std::max(
    std::max(_pOrderEdge[8] - 1, _pOrderEdge[3] - 1), _pOrderQuadFace1[2] - 1));
  phi[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderTriFace[1] - 2, _pb1 - 2), _pOrderTriFace[0] - 2),
    0));
  dphi[0] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[0] - 1, _pOrderEdge[6] - 1),
                               _pOrderQuadFace1[0] - 1),
                      _pOrderTriFace[0] - 2),
             _pOrderTriFace[1] - 2),
    _pb1 - 2));
  dphi[1] = std::vector<double>(std::max(
    std::max(_pOrderEdge[1] - 1, _pOrderEdge[7] - 1), _pOrderQuadFace1[1] - 1));
  dphi[2] = std::vector<double>(std::max(
    std::max(std::max(std::max(std::max(_pOrderEdge[2] - 1, _pOrderEdge[4] - 1),
                               _pOrderEdge[5] - 1),
                      _pOrderQuadFace2[0] - 1),
             _pOrderQuadFace2[1] - 1),
    _pOrderQuadFace2[2] - 1));

  dphi[3] = std::vector<double>(std::max(
    std::max(_pOrderEdge[8] - 1, _pOrderEdge[3] - 1), _pOrderQuadFace1[2] - 1));
  dphi[4] = std::vector<double>(std::max(
    std::max(std::max(_pOrderTriFace[1] - 2, _pb1 - 2), _pOrderTriFace[0] - 2),
    0));
  for(int i = 0; i < 5; i++) {
    for(unsigned int j = 0; j < phi[i].size(); j++) {
      phi[i][j] = OrthogonalPoly::EvalKernelFunction(j, substraction[i]);
      dphi[i][j] = OrthogonalPoly::EvalDKernelFunction(j, substraction[i]);
    }
  }
  std::vector<double> product1(6);
  product1[0] = lambda2 * lambda5;
  product1[1] = lambda3 * lambda5;
  product1[2] = lambda1 * lambda5;
  product1[3] = lambda2 * lambda4;
  product1[4] = lambda4 * lambda3;
  product1[5] = lambda1 * lambda4;
  std::vector<double> productEdgeTerm(_nedge);
  productEdgeTerm[0] = product1[0] * lambda3;
  productEdgeTerm[1] = product1[0] * lambda1;
  productEdgeTerm[2] = product1[0] * lambda4;
  productEdgeTerm[3] = product1[1] * lambda1;
  productEdgeTerm[4] = product1[1] * lambda4;
  productEdgeTerm[5] = product1[2] * lambda4;
  productEdgeTerm[6] = product1[3] * lambda3;
  productEdgeTerm[7] = product1[3] * lambda1;
  productEdgeTerm[8] = product1[4] * lambda1;
  std::vector<std::vector<double> > dproductEdgeTerm(_nedge,
                                                     std::vector<double>(3));
  for(int i = 0; i < 3; i++) {
    dproductEdgeTerm[0][i] =
      gradientVertex[0][i] * lambda3 + dlambda3[i] * product1[0];
    dproductEdgeTerm[1][i] =
      gradientVertex[0][i] * lambda1 + dlambda1[i] * product1[0];
    dproductEdgeTerm[2][i] =
      gradientVertex[0][i] * lambda4 + dlambda4[i] * product1[0];
    dproductEdgeTerm[3][i] =
      gradientVertex[1][i] * lambda1 + dlambda1[i] * product1[1];
    dproductEdgeTerm[4][i] =
      gradientVertex[1][i] * lambda4 + dlambda4[i] * product1[1];
    dproductEdgeTerm[5][i] =
      gradientVertex[2][i] * lambda4 + dlambda4[i] * product1[2];
    dproductEdgeTerm[6][i] =
      gradientVertex[3][i] * lambda3 + dlambda3[i] * product1[3];
    dproductEdgeTerm[7][i] =
      gradientVertex[3][i] * lambda1 + dlambda1[i] * product1[3];
    dproductEdgeTerm[8][i] =
      gradientVertex[4][i] * lambda1 + dlambda1[i] * product1[4];
  }

  // edge shape functions:
  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    int numPhi = 0;
    switch(iEdge) {
    case(0):
    case(6): numPhi = 0; break;
    case(1):
    case(7): numPhi = 1; break;
    case(2):
    case(4):
    case(5): numPhi = 2; break;
    case(3):
    case(8): numPhi = 3; break;
    }

    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] - 1;
        indexEdgeFunc++) {
      for(int i = 0; i < 3; i++) {
        gradientEdge[indexEdgeBasis][i] =
          dproductEdgeTerm[iEdge][i] * phi[numPhi][indexEdgeFunc] +
          dsubstraction[numPhi][i] * productEdgeTerm[iEdge] *
            dphi[numPhi][indexEdgeFunc];
      }

      indexEdgeBasis++;
    }
  }
  // face shape functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad + _nfaceTri; iFace++) {
    int indexPhi1 = 0;
    int indexPhi2 = 0;
    double productFaceTerm = 0;
    std::vector<double> dproductFaceTerm(3, 0);
    switch(iFace) {
    case(3):
      indexPhi1 = 0;
      indexPhi2 = 4;
      productFaceTerm = productEdgeTerm[0] * lambda1;
      for(int i = 0; i < 3; i++) {
        dproductFaceTerm[i] =
          dproductEdgeTerm[0][i] * lambda1 + productEdgeTerm[0] * dlambda1[i];
      }
      break;
    case(4):
      indexPhi1 = 0;
      indexPhi2 = 4;
      productFaceTerm = productEdgeTerm[7] * lambda3;
      for(int i = 0; i < 3; i++) {
        dproductFaceTerm[i] =
          dproductEdgeTerm[7][i] * lambda3 + productEdgeTerm[7] * dlambda3[i];
      }
      break;
    case(0):
      indexPhi1 = 0;
      indexPhi2 = 2;
      productFaceTerm = productEdgeTerm[0] * lambda4;
      for(int i = 0; i < 3; i++) {
        dproductFaceTerm[i] =
          dproductEdgeTerm[0][i] * lambda4 + productEdgeTerm[0] * dlambda4[i];
      }
      break;
    case(1):
      indexPhi1 = 1;
      indexPhi2 = 2;
      productFaceTerm = productEdgeTerm[7] * lambda5;
      for(int i = 0; i < 3; i++) {
        dproductFaceTerm[i] =
          dproductEdgeTerm[7][i] * lambda5 + productEdgeTerm[7] * dlambda5[i];
      }
      break;
    case(2):
      indexPhi1 = 3;
      indexPhi2 = 2;
      productFaceTerm = productEdgeTerm[8] * lambda5;
      for(int i = 0; i < 3; i++) {
        dproductFaceTerm[i] =
          dproductEdgeTerm[8][i] * lambda5 + productEdgeTerm[8] * dlambda5[i];
      }
      break;
    }
    if(iFace < 3) {
      for(int n1 = 0; n1 < _pOrderQuadFace1[iFace] - 1; n1++) {
        for(int n2 = 0; n2 < _pOrderQuadFace2[iFace] - 1; n2++) {
          for(int i = 0; i < 3; i++) {
            gradientFace[indexFaceFunction][i] =
              dproductFaceTerm[i] * phi[indexPhi1][n1] * phi[indexPhi2][n2] +
              productFaceTerm * dsubstraction[indexPhi1][i] *
                dphi[indexPhi1][n1] * phi[indexPhi2][n2] +
              productFaceTerm * dsubstraction[indexPhi2][i] *
                phi[indexPhi1][n1] * dphi[indexPhi2][n2];
          }
          indexFaceFunction++;
        }
      }
    }
    else {
      for(int n1 = 0; n1 < _pOrderTriFace[iFace - 3] - 2; n1++) {
        for(int n2 = 0; n2 < _pOrderTriFace[iFace - 3] - 2 - n1; n2++) {
          for(int i = 0; i < 3; i++) {
            gradientFace[indexFaceFunction][i] =
              dproductFaceTerm[i] * phi[indexPhi1][n1] * phi[indexPhi2][n2] +
              productFaceTerm * dsubstraction[indexPhi1][i] *
                dphi[indexPhi1][n1] * phi[indexPhi2][n2] +
              productFaceTerm * dsubstraction[indexPhi2][i] *
                phi[indexPhi1][n1] * dphi[indexPhi2][n2];
          }

          indexFaceFunction++;
        }
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  double lambdaProductBubble = lambda1 * lambda2 * lambda3;
  std::vector<double> dlambdaProductBubble(3);
  for(int i = 0; i < 3; i++) {
    dlambdaProductBubble[i] = dlambda1[i] * lambda2 * lambda3 +
                              lambda1 * dlambda2[i] * lambda3 +
                              lambda1 * lambda2 * dlambda3[i];
  }

  for(int n1 = 0; n1 < _pb1 - 2; n1++) {
    for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2; n3++) {
        gradientBubble[indexBubbleBasis][0] =
          (dlambdaProductBubble[0] * phi[0][n1] * phi[4][n2] +
           lambdaProductBubble * dsubstraction[0][0] * dphi[0][n1] *
             phi[4][n2] +
           lambdaProductBubble * dsubstraction[4][0] * phi[0][n1] *
             dphi[4][n2]) *
          OrthogonalPoly::EvalLobatto(n3, w);

        gradientBubble[indexBubbleBasis][1] =
          (dlambdaProductBubble[1] * phi[0][n1] * phi[4][n2] +
           lambdaProductBubble * dsubstraction[0][1] * dphi[0][n1] *
             phi[4][n2] +
           lambdaProductBubble * dsubstraction[4][1] * phi[0][n1] *
             dphi[4][n2]) *
          OrthogonalPoly::EvalLobatto(n3, w);

        gradientBubble[indexBubbleBasis][2] =
          (dlambdaProductBubble[2] * phi[0][n1] * phi[4][n2] +
           lambdaProductBubble * dsubstraction[0][2] * dphi[0][n1] *
             phi[4][n2] +
           lambdaProductBubble * dsubstraction[4][2] * phi[0][n1] *
             dphi[4][n2]) *
            OrthogonalPoly::EvalLobatto(n3, w) +
          OrthogonalPoly::EvalDLobatto(n3, w) * lambdaProductBubble *
            phi[0][n1] * phi[4][n2];

        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisH1Pri::orientEdge(
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
void HierarchicalBasisH1Pri::orientEdge(
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

void HierarchicalBasisH1Pri::orientEdgeFunctionsForNegativeFlag(
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
void HierarchicalBasisH1Pri::orientEdgeFunctionsForNegativeFlag(
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

void HierarchicalBasisH1Pri::orientOneFace(double const &u, double const &v,
                                           double const &w, int const &flag1,
                                           int const &flag2, int const &flag3,
                                           int const &faceNumber,
                                           std::vector<double> &faceBasis)
{
  if(faceNumber < 3) {
    if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
      int iterator = 0;
      for(int i = 0; i < faceNumber; i++) {
        iterator += (_pOrderQuadFace1[i] - 1) * (_pOrderQuadFace2[i] - 1);
      }
      if(flag3 == 1) {
        for(int it1 = 2; it1 <= _pOrderQuadFace1[faceNumber]; it1++) {
          for(int it2 = 2; it2 <= _pOrderQuadFace2[faceNumber]; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            faceBasis[iterator] =
              faceBasis[iterator] * impactFlag1 * impactFlag2;
            iterator++;
          }
        }
      }
      else {
        // to map onto the reference domain of gmsh:
        double uc = 2 * u - 1;
        double vc = 2 * v - 1;
        double wc = w;
        //*****
        double lambdaProduct = 0;
        double var1 = 0;
        double var2 = 0;
        switch(faceNumber) {
        case(0): {
          double lambda2 = _affineCoordinate(2, uc, vc, wc);
          double lambda3 = _affineCoordinate(3, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          lambdaProduct = lambda2 * lambda3 * lambda4 * lambda5;
          var1 = lambda3 - lambda2;
          var2 = lambda4 - lambda5;

        } break;
        case(1): {
          double lambda1 = _affineCoordinate(1, uc, vc, wc);
          double lambda2 = _affineCoordinate(2, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          lambdaProduct = lambda2 * lambda1 * lambda4 * lambda5;
          var1 = lambda1 - lambda2;
          var2 = lambda4 - lambda5;
        } break;
        case(2): {
          double lambda1 = _affineCoordinate(1, uc, vc, wc);
          double lambda3 = _affineCoordinate(3, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          lambdaProduct = lambda1 * lambda3 * lambda4 * lambda5;
          var1 = lambda1 - lambda3;
          var2 = lambda4 - lambda5;
        } break;
        }
        std::vector<double> phi1(_pOrderQuadFace1[faceNumber] - 1);
        std::vector<double> phi2(_pOrderQuadFace2[faceNumber] - 1);
        for(int it = 0; it <= _pOrderQuadFace1[faceNumber] - 2; it++) {
          phi1[it] = OrthogonalPoly::EvalKernelFunction(it, var1);
        }
        for(int it = 0; it <= _pOrderQuadFace2[faceNumber] - 2; it++) {
          phi2[it] = OrthogonalPoly::EvalKernelFunction(it, var2);
        }

        for(int it1 = 0; it1 <= _pOrderQuadFace2[faceNumber] - 2; it1++) {
          for(int it2 = 0; it2 <= _pOrderQuadFace1[faceNumber] - 2; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            faceBasis[iterator] =
              lambdaProduct * phi1[it2] * phi2[it1] * impactFlag1 * impactFlag2;
            iterator++;
          }
        }
      }
    }
  }
  else {
    int constant = faceNumber - 3;
    if(!(flag1 == 0 && flag2 == 1)) {
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double wc = w;
      //*****
      int iterator = (_pOrderQuadFace2[0] - 1) * (_pOrderQuadFace1[0] - 1) +
                     (_pOrderQuadFace2[1] - 1) * (_pOrderQuadFace1[1] - 1) +
                     (_pOrderQuadFace2[2] - 1) * (_pOrderQuadFace1[2] - 1);
      for(int i = 0; i < constant; i++) {
        iterator += int((_pOrderTriFace[i] - 1) * (_pOrderTriFace[i] - 2) / 2);
      }
      std::vector<double> lambda(3);
      double lambdai = 0;
      switch(faceNumber) {
      case(3):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        lambdai = _affineCoordinate(5, uc, vc, wc);
        break;
      case(4):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        lambdai = _affineCoordinate(4, uc, vc, wc);
        break;
      }
      double product = lambda[0] * lambda[1] * lambda[2] * lambdai;
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
      std::vector<double> phiSubs2(_pOrderTriFace[constant] - 2);
      for(int it = 0; it < _pOrderTriFace[constant] - 2; it++) {
        phiSubs2[it] = OrthogonalPoly::EvalKernelFunction(it, subs2);
      }
      for(int n1 = 0; n1 < _pOrderTriFace[constant] - 2; n1++) {
        double phiSubs1 = OrthogonalPoly::EvalKernelFunction(n1, subs1);
        for(int n2 = 0; n2 < _pOrderTriFace[constant] - 2 - n1; n2++) {
          faceBasis[iterator] = product * phiSubs1 * phiSubs2[n2];
          iterator++;
        }
      }
    }
  }
}
void HierarchicalBasisH1Pri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &gradientFace, std::string typeFunction)
{
  if(faceNumber < 3) {
    if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
      int iterator = 0;
      for(int i = 0; i < faceNumber; i++) {
        iterator += (_pOrderQuadFace1[i] - 1) * (_pOrderQuadFace2[i] - 1);
      }
      if(flag3 == 1) {
        for(int it1 = 2; it1 <= _pOrderQuadFace1[faceNumber]; it1++) {
          for(int it2 = 2; it2 <= _pOrderQuadFace2[faceNumber]; it2++) {
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
        // to map onto the reference domain of gmsh:
        double uc = 2 * u - 1;
        double vc = 2 * v - 1;
        double wc = w;
        //*****
        double lambdaProduct = 0;
        std::vector<double> dlambdaProduct(3, 0);
        double var1 = 0;
        std::vector<double> dvar1(3, 0);
        double var2 = 0;
        std::vector<double> dvar2(3, 0);
        switch(faceNumber) {
        case(0): {
          double lambda2 = _affineCoordinate(2, uc, vc, wc);
          double lambda3 = _affineCoordinate(3, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          double lambda45 = lambda4 * lambda5;
          double lambda23 = lambda2 * lambda3;
          lambdaProduct = lambda23 * lambda45;
          var1 = lambda3 - lambda2;
          var2 = lambda4 - lambda5;
          dlambdaProduct[0] = -lambda45 * var1;
          dlambdaProduct[1] = -lambda45 * lambda3;
          dlambdaProduct[2] = -0.5 * lambda23 * var2;
          dvar1[0] = 2;
          dvar1[1] = 1;
          dvar2[2] = 1;

        } break;
        case(1): {
          double lambda1 = _affineCoordinate(1, uc, vc, wc);
          double lambda2 = _affineCoordinate(2, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          var1 = lambda1 - lambda2;
          var2 = lambda4 - lambda5;
          double lambda45 = lambda4 * lambda5;
          double lambda21 = lambda2 * lambda1;
          lambdaProduct = lambda21 * lambda45;
          dlambdaProduct[0] = -lambda45 * lambda1;
          dlambdaProduct[1] = lambda45 * (lambda2 - lambda1);
          dlambdaProduct[2] = -0.5 * lambda21 * var2;
          dvar1[0] = 1;
          dvar1[1] = 2;
          dvar2[2] = 1;

        } break;
        case(2): {
          double lambda1 = _affineCoordinate(1, uc, vc, wc);
          double lambda3 = _affineCoordinate(3, uc, vc, wc);
          double lambda4 = _affineCoordinate(4, uc, vc, wc);
          double lambda5 = _affineCoordinate(5, uc, vc, wc);
          var1 = lambda1 - lambda3;
          var2 = lambda4 - lambda5;
          double lambda45 = lambda4 * lambda5;
          double lambda13 = lambda1 * lambda3;
          lambdaProduct = lambda13 * lambda45;
          dlambdaProduct[0] = lambda45 * lambda1;
          dlambdaProduct[1] = lambda45 * lambda3;
          dlambdaProduct[2] = -0.5 * lambda13 * var2;
          dvar1[0] = -1;
          dvar1[1] = 1;
          dvar2[2] = 1;

        } break;
        }
        std::vector<double> phi1(_pOrderQuadFace1[faceNumber] - 1);
        std::vector<double> phi2(_pOrderQuadFace2[faceNumber] - 1);
        std::vector<double> dphi1(_pOrderQuadFace1[faceNumber] - 1);
        std::vector<double> dphi2(_pOrderQuadFace2[faceNumber] - 1);
        for(int it = 0; it <= _pOrderQuadFace1[faceNumber] - 2; it++) {
          phi1[it] = OrthogonalPoly::EvalKernelFunction(it, var1);
          dphi1[it] = OrthogonalPoly::EvalDKernelFunction(it, var1);
        }
        for(int it = 0; it <= _pOrderQuadFace2[faceNumber] - 2; it++) {
          phi2[it] = OrthogonalPoly::EvalKernelFunction(it, var2);
          dphi2[it] = OrthogonalPoly::EvalDKernelFunction(it, var2);
        }

        for(int it1 = 0; it1 <= _pOrderQuadFace2[faceNumber] - 2; it1++) {
          for(int it2 = 0; it2 <= _pOrderQuadFace1[faceNumber] - 2; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            for(int i = 0; i < 3; i++) {
              gradientFace[iterator][i] =
                impactFlag1 * impactFlag2 *
                (dlambdaProduct[i] * phi1[it2] * phi2[it1] +
                 lambdaProduct * dvar1[i] * dphi1[it2] * phi2[it1] +
                 dvar2[i] * lambdaProduct * phi1[it2] * dphi2[it1]);
            }
            iterator++;
          }
        }
      }
    }
  }
  else {
    int constant = faceNumber - 3;
    if(!(flag1 == 0 && flag2 == 1)) {
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double wc = w;
      //*****
      int iterator = (_pOrderQuadFace2[0] - 1) * (_pOrderQuadFace1[0] - 1) +
                     (_pOrderQuadFace2[1] - 1) * (_pOrderQuadFace1[1] - 1) +
                     (_pOrderQuadFace2[2] - 1) * (_pOrderQuadFace1[2] - 1);
      for(int i = 0; i < constant; i++) {
        iterator += int((_pOrderTriFace[i] - 1) * (_pOrderTriFace[i] - 2) / 2);
      }
      std::vector<double> lambda(3);
      std::vector<std::vector<double> > dlambda(3, std::vector<double>(3, 0));
      double lambdai = 0;
      std::vector<double> dlambdai(3, 0);
      switch(faceNumber) {
      case(3):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -1;
        dlambda[0][1] = -1;
        dlambda[1][0] = 1;
        dlambda[2][1] = 1;
        lambdai = _affineCoordinate(5, uc, vc, wc);
        dlambdai[2] = -0.5;
        break;
      case(4):
        lambda[0] = _affineCoordinate(2, uc, vc, wc);
        lambda[1] = _affineCoordinate(3, uc, vc, wc);
        lambda[2] = _affineCoordinate(1, uc, vc, wc);
        dlambda[0][0] = -1;
        dlambda[0][1] = -1;
        dlambda[1][0] = 1;
        dlambda[2][1] = 1;
        lambdai = _affineCoordinate(4, uc, vc, wc);
        dlambdai[2] = 0.5;
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
      double subs1 = lambda[1] - lambda[0];
      double subs2 = lambda[0] - lambda[2];
      std::vector<double> dsubs1(3, 0);
      std::vector<double> dsubs2(3, 0);
      for(int i = 0; i < 3; i++) {
        dsubs1[i] = dlambda[1][i] - dlambda[0][i];
        dsubs2[i] = dlambda[0][i] - dlambda[2][i];
      }
      double product = lambda[0] * lambda[1] * lambda[2] * lambdai;
      std::vector<double> dproduct(3, 0);
      for(int i = 0; i < 3; i++) {
        dproduct[i] = dlambda[0][i] * lambda[1] * lambda[2] * lambdai +
                      lambda[0] * dlambda[1][i] * lambda[2] * lambdai +
                      lambda[0] * lambda[1] * dlambda[2][i] * lambdai +
                      lambda[0] * lambda[1] * lambda[2] * dlambdai[i];
      }
      std::vector<double> phiSubs2(_pOrderTriFace[constant] - 2);
      std::vector<double> dphiSubs2(_pOrderTriFace[constant] - 2);
      for(int it = 0; it < _pOrderTriFace[constant] - 2; it++) {
        phiSubs2[it] = OrthogonalPoly::EvalKernelFunction(it, subs2);
        dphiSubs2[it] = OrthogonalPoly::EvalDKernelFunction(it, subs2);
      }
      for(int n1 = 0; n1 < _pOrderTriFace[constant] - 2; n1++) {
        double phiSubs1 = OrthogonalPoly::EvalKernelFunction(n1, subs1);
        double dphiSubs1 = OrthogonalPoly::EvalDKernelFunction(n1, subs1);
        for(int n2 = 0; n2 < _pOrderTriFace[constant] - 2 - n1; n2++) {
          for(int i = 0; i < 3; i++) {
            gradientFace[iterator][i] =
              dproduct[i] * phiSubs1 * phiSubs2[n2] +
              product * dphiSubs1 * dsubs1[i] * phiSubs2[n2] +
              product * phiSubs1 * dsubs2[i] * dphiSubs2[n2];
          }

          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisH1Pri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<double> &quadFaceFunctionsAllOrientation,
  const std::vector<double> &triFaceFunctionsAllOrientation,
  std::vector<double> &fTableCopy)
{
  if(faceNumber < 3) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderQuadFace1[i] - 1) * (_pOrderQuadFace2[i] - 1);
    }
    int numFaceFunctions =
      (_pOrderQuadFace1[faceNumber] - 1) * (_pOrderQuadFace2[faceNumber] - 1);
    int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
    int offset = iOrientation * _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];
    }
  }
  else {
    int iterator = _nQuadFaceFunction;
    int numface = faceNumber - 3;
    for(int i = 0; i < numface; i++) {
      iterator += int((_pOrderTriFace[i] - 1) * (_pOrderTriFace[i] - 2) / 2);
    }
    int numFaceFunctions =
      int((_pOrderTriFace[numface] - 1) * (_pOrderTriFace[numface] - 2) / 2);
    int iOrientation = numberOrientationTriFace(flag1, flag2);
    int offset = iOrientation * _nTriFaceFunction - _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i] = triFaceFunctionsAllOrientation[i + offset];
    }
  }
}

void HierarchicalBasisH1Pri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  if(faceNumber < 3) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderQuadFace1[i] - 1) * (_pOrderQuadFace2[i] - 1);
    }
    int numFaceFunctions =
      (_pOrderQuadFace1[faceNumber] - 1) * (_pOrderQuadFace2[faceNumber] - 1);
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
      iterator += int((_pOrderTriFace[i] - 1) * (_pOrderTriFace[i] - 2) / 2);
    }
    int numFaceFunctions =
      int((_pOrderTriFace[numface] - 1) * (_pOrderTriFace[numface] - 2) / 2);
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

void HierarchicalBasisH1Pri::getKeysInfo(std::vector<int> &functionTypeInfo,
                                         std::vector<int> &orderInfo)
{
  for(int i = 0; i < 6; i++) {
    functionTypeInfo[i] = 0;
    orderInfo[i] = 1;
  }
  int it = 6;
  for(int numEdge = 0; numEdge < 9; numEdge++) {
    for(int i = 2; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int iFace = 0; iFace < _nfaceQuad + _nfaceTri; iFace++) {
    if(iFace < 3) {
      for(int n1 = 2; n1 <= _pOrderQuadFace1[iFace]; n1++) {
        for(int n2 = 2; n2 <= _pOrderQuadFace2[iFace]; n2++) {
          functionTypeInfo[it] = 2;
          orderInfo[it] = std::max(n1, n2);
          it++;
        }
      }
    }
    else {
      for(int n1 = 1; n1 < _pOrderTriFace[iFace - 3] - 1; n1++) {
        for(int n2 = 1; n2 <= _pOrderTriFace[iFace - 3] - 1 - n1; n2++) {
          functionTypeInfo[it] = 2;
          orderInfo[it] = n1 + n2 + 1;
          it++;
        }
      }
    }
  }
  for(int n1 = 1; n1 < _pb1 - 1; n1++) {
    for(int n2 = 1; n2 <= _pb1 - 1 - n1; n2++) {
      for(int n3 = 2; n3 <= _pb2; n3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1 + n2 + 1, n3);
        it++;
      }
    }
  }
}
