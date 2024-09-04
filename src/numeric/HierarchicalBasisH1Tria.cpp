// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth, Ivo Dolezel, Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include <stdexcept>
#include "HierarchicalBasisH1Tria.h"

HierarchicalBasisH1Tria::HierarchicalBasisH1Tria(int pf, int pe0, int pe1,
                                                 int pe2)
{
  _nvertex = 3;
  _nedge = 3;
  _nfaceTri = 1;
  _nfaceQuad = 0;
  _nVertexFunction = 3;
  _nEdgeFunction = pe0 + pe1 + pe2 - 3;
  _nQuadFaceFunction = 0;
  _nTriFaceFunction = (pf - 1) * (pf - 2) / 2;
  _nBubbleFunction = 0;
  _pf = pf;

  if(pe0 > pf || pe2 > pf || pe1 > pf) {
    throw std::runtime_error("pe0, pe1  and pe2  must be <=pf");
  }
  _pOrderEdge[0] = pe0;
  _pOrderEdge[1] = pe1;
  _pOrderEdge[2] = pe2;
}
HierarchicalBasisH1Tria::HierarchicalBasisH1Tria(int order)
{
  _nvertex = 3;
  _nedge = 3;
  _nfaceTri = 1;
  _nfaceQuad = 0;
  _nVertexFunction = 3;
  _nEdgeFunction = 3 * order - 3;
  _nQuadFaceFunction = 0;
  _nTriFaceFunction = (order - 1) * (order - 2) / 2;
  _nBubbleFunction = 0;
  _pf = order;
  _pOrderEdge[0] = order;
  _pOrderEdge[1] = order;
  _pOrderEdge[2] = order;
}
HierarchicalBasisH1Tria::~HierarchicalBasisH1Tria() {}

unsigned int HierarchicalBasisH1Tria::getNumberOfOrientations() const
{
  return 6; // factorial 3
}

double HierarchicalBasisH1Tria::_affineCoordinate(int const &j, double const &u,
                                                  double const &v)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  default: throw std::runtime_error("j must be : 1<=j<=3");
  }
}

void HierarchicalBasisH1Tria::generateBasis(double const &u, double const &v,
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
  //*****
  double lambda1 = _affineCoordinate(1, uc, vc);
  double lambda2 = _affineCoordinate(2, uc, vc);
  double lambda3 = _affineCoordinate(3, uc, vc);
  double product32 = lambda2 * lambda3;
  double subtraction32 = lambda3 - lambda2;
  double product13 = lambda3 * lambda1;
  double subtraction13 = lambda1 - lambda3;
  double product21 = lambda2 * lambda1;
  double subtraction21 = lambda2 - lambda1;
  double product = lambda1 * lambda2 * lambda3;
  // vertex shape functions:
  vertexBasis[0] = lambda2;
  vertexBasis[1] = lambda3;
  vertexBasis[2] = lambda1;
  // edge 0  shape functions and a part of face functions :
  int iterator2 = 0;
  for(int k = 0; k <= _pOrderEdge[0] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction32);
    edgeBasis[k] = product32 * kernel;
    int iterator = 0;
    while(iterator <= _pf - 3 - k) {
      faceBasis[iterator2 + iterator] = product * kernel;
      iterator++;
    }
    iterator2 = iterator2 + _pf - 2 - k;
  }
  for(int k = _pOrderEdge[0] - 1; k <= _pf - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction32);
    int iterator = 0;
    while(iterator <= _pf - 3 - k) {
      faceBasis[iterator2 + iterator] = product * kernel;
      iterator++;
    }
    iterator2 = iterator2 + _pf - 2 - k;
  }
  // edge 1 shape functions  :
  for(int k = 0; k <= _pOrderEdge[1] - 2; k++) {
    edgeBasis[_pOrderEdge[0] + k - 1] =
      product13 * OrthogonalPoly::EvalKernelFunction(k, subtraction13);
  }
  // edge 2  shape functions and a part of face functions :
  for(int k = 0; k <= _pOrderEdge[2] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction21);
    edgeBasis[k + _pOrderEdge[0] + _pOrderEdge[1] - 2] = product21 * kernel;
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = _pf - 2;
    while(iterator1 <= _pf - 3 - k) {
      faceBasis[iterator2] = faceBasis[iterator2] * kernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
  for(int k = _pOrderEdge[2] - 1; k <= _pf - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction21);
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = _pf - 2;
    while(iterator1 <= _pf - 3 - k) {
      faceBasis[iterator2] = faceBasis[iterator2] * kernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
}

void HierarchicalBasisH1Tria::generateGradientBasis(
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
  double jacob = 2; // jacobian=((2,0),(0,2))
  //****
  double dlambda1U = 0;
  double dlambda1V = 0.5;
  double dlambda2U = -0.5;
  double dlambda2V = -0.5;
  double dlambda3U = 0.5;
  double dlambda3V = 0;
  double lambda1 = _affineCoordinate(1, uc, vc);
  double lambda2 = _affineCoordinate(2, uc, vc);
  double lambda3 = _affineCoordinate(3, uc, vc);
  double product32 = lambda2 * lambda3;
  double subtraction32 = lambda3 - lambda2;
  double product13 = lambda3 * lambda1;
  double subtraction13 = lambda1 - lambda3;
  double product21 = lambda2 * lambda1;
  double subtraction21 = lambda2 - lambda1;
  double product = lambda1 * lambda2 * lambda3;
  // vertex gradient functions:
  gradientVertex[0][0] = jacob * dlambda2U;
  gradientVertex[0][1] = jacob * dlambda2V;
  gradientVertex[1][0] = jacob * dlambda3U;
  gradientVertex[1][1] = jacob * dlambda3V;
  gradientVertex[2][0] = jacob * dlambda1U;
  gradientVertex[2][1] = jacob * dlambda1V;
  std::vector<double> tablIntermU(_nTriFaceFunction);
  std::vector<double> tablIntermV(_nTriFaceFunction);
  // edge 0  gradient  and a part of face functions gradient :
  int iterator2 = 0;
  for(int k = 0; k <= _pOrderEdge[0] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction32);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subtraction32);
    gradientEdge[k][0] =
      (gradientVertex[1][0] * lambda2 + gradientVertex[0][0] * lambda3) *
        kernel +
      product32 * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
    gradientEdge[k][1] =
      (gradientVertex[1][1] * lambda2 + gradientVertex[0][1] * lambda3) *
        kernel +
      product32 * (gradientVertex[1][1] - gradientVertex[0][1]) * dKernel;
    int iterator = 0;
    while(iterator <= _pf - 3 - k) {
      gradientFace[iterator2 + iterator][0] =
        (gradientVertex[1][0] * product21 + gradientVertex[0][0] * product13 +
         gradientVertex[2][0] * product32) *
          kernel +
        product * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
      gradientFace[iterator2 + iterator][1] =
        (gradientVertex[1][1] * product21 + gradientVertex[0][1] * product13 +
         gradientVertex[2][1] * product32) *
          kernel +
        product * (gradientVertex[1][1] - gradientVertex[0][1]) * dKernel;
      tablIntermU[iterator2 + iterator] =
        product * (gradientVertex[0][0] - gradientVertex[2][0]) * kernel;
      tablIntermV[iterator2 + iterator] =
        product * (gradientVertex[0][1] - gradientVertex[2][1]) * kernel;
      iterator++;
    }

    iterator2 = iterator2 + _pf - 2 - k;
  }
  for(int k = _pOrderEdge[0] - 1; k <= _pf - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction32);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subtraction32);
    int iterator = 0;
    while(iterator <= _pf - 3 - k) {
      gradientFace[iterator2 + iterator][0] =
        (gradientVertex[1][0] * product21 + gradientVertex[0][0] * product13 +
         gradientVertex[2][0] * product32) *
          kernel +
        product * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
      gradientFace[iterator2 + iterator][1] =
        (gradientVertex[1][1] * product21 + gradientVertex[0][1] * product13 +
         gradientVertex[2][1] * product32) *
          kernel +
        product * (gradientVertex[1][1] - gradientVertex[0][1]) * dKernel;
      tablIntermU[iterator2 + iterator] =
        product * (gradientVertex[0][0] - gradientVertex[2][0]) * kernel;
      tablIntermV[iterator2 + iterator] =
        product * (gradientVertex[0][1] - gradientVertex[2][1]) * kernel;
      iterator++;
    }

    iterator2 = iterator2 + _pf - 2 - k;
  }
  // edge 1 shape functions gradient  :
  for(int k = 0; k <= _pOrderEdge[1] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction13);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subtraction13);
    gradientEdge[_pOrderEdge[0] + k - 1][0] =
      (lambda3 * gradientVertex[2][0] + lambda1 * gradientVertex[1][0]) *
        kernel +
      product13 * (gradientVertex[2][0] - gradientVertex[1][0]) * dKernel;
    gradientEdge[_pOrderEdge[0] + k - 1][1] =
      (lambda3 * gradientVertex[2][1] + lambda1 * gradientVertex[1][1]) *
        kernel +
      product13 * (gradientVertex[2][1] - gradientVertex[1][1]) * dKernel;
  }
  // edge 2  gradient  and a part of face functions gradient :
  for(int k = 0; k <= _pOrderEdge[2] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction21);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subtraction21);
    gradientEdge[k + _pOrderEdge[0] + _pOrderEdge[1] - 2][0] =
      (lambda2 * gradientVertex[2][0] + lambda1 * gradientVertex[0][0]) *
        kernel +
      product21 * (gradientVertex[0][0] - gradientVertex[2][0]) * dKernel;
    gradientEdge[k + _pOrderEdge[0] + _pOrderEdge[1] - 2][1] =
      (lambda2 * gradientVertex[2][1] + lambda1 * gradientVertex[0][1]) *
        kernel +
      product21 * (gradientVertex[0][1] - gradientVertex[2][1]) * dKernel;
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = _pf - 2;
    while(iterator1 <= _pf - 3 - k) {
      gradientFace[iterator2][0] =
        gradientFace[iterator2][0] * kernel + tablIntermU[iterator2] * dKernel;
      gradientFace[iterator2][1] =
        gradientFace[iterator2][1] * kernel + tablIntermV[iterator2] * dKernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
  for(int k = _pOrderEdge[2] - 1; k <= _pf - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subtraction21);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subtraction21);
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = _pf - 2;
    while(iterator1 <= _pf - 3 - k) {
      gradientFace[iterator2][0] =
        gradientFace[iterator2][0] * kernel + tablIntermU[iterator2] * dKernel;
      gradientFace[iterator2][1] =
        gradientFace[iterator2][1] * kernel + tablIntermV[iterator2] * dKernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
}

void HierarchicalBasisH1Tria::orientEdge(
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

void HierarchicalBasisH1Tria::orientEdge(
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
void HierarchicalBasisH1Tria::orientEdgeFunctionsForNegativeFlag(
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

void HierarchicalBasisH1Tria::orientEdgeFunctionsForNegativeFlag(
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
void HierarchicalBasisH1Tria::orientOneFace(double const &u, double const &v,
                                            double const &w, int const &flag1,
                                            int const &flag2, int const &flag3,
                                            int const &faceNumber,
                                            std::vector<double> &faceBasis)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    // to map onto the reference domain of gmsh:
    double uc = 2 * u - 1;
    double vc = 2 * v - 1;
    //*****
    int iterator = 0;
    std::vector<double> lambda(3);

    lambda[0] = _affineCoordinate(2, uc, vc);
    lambda[1] = _affineCoordinate(3, uc, vc);
    lambda[2] = _affineCoordinate(1, uc, vc);

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
    std::vector<double> phiSubs2(_pf - 2);
    for(int it = 0; it < _pf - 2; it++) {
      phiSubs2[it] = OrthogonalPoly::EvalKernelFunction(it, subs2);
    }
    for(int n1 = 0; n1 < _pf - 2; n1++) {
      double phiSubs1 = OrthogonalPoly::EvalKernelFunction(n1, subs1);
      for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
        faceBasis[iterator] = product * phiSubs1 * phiSubs2[n2];
        iterator++;
      }
    }
  }
}
void HierarchicalBasisH1Tria::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &gradientFace, std::string typeFunction)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    // to map onto the reference domain of gmsh:
    double uc = 2 * u - 1;
    double vc = 2 * v - 1;
    //*****
    int iterator = 0;
    std::vector<double> lambda(3);
    std::vector<std::vector<double> > dlambda(3, std::vector<double>(2, 0));
    std::vector<double> dProduct(2); // gradient of (lambdaA*lambdaB*lambdaC)

    lambda[0] = _affineCoordinate(2, uc, vc);
    lambda[1] = _affineCoordinate(3, uc, vc);
    lambda[2] = _affineCoordinate(1, uc, vc);
    dlambda[0][0] = -1; //* jacobian
    dlambda[0][1] = -1; //* jacobian
    dlambda[1][0] = 1; //* jacobian
    dlambda[2][1] = 1; //* jacobian
    double pl3l1 = lambda[1] * lambda[2];
    dProduct[0] = lambda[2] * lambda[0] - pl3l1;
    dProduct[1] = lambda[0] * lambda[1] - pl3l1;
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
    std::vector<double> dsubsBA(2);
    std::vector<double> dsubsAC(2);
    for(int i = 0; i < 2; i++) {
      dsubsBA[i] = dlambda[1][i] - dlambda[0][i];
      dsubsAC[i] = dlambda[0][i] - dlambda[2][i];
    }
    std::vector<double> phiSubsAC(_pf - 2);
    std::vector<double> dphiSubsAC(_pf - 2);
    for(int it = 0; it < _pf - 2; it++) {
      phiSubsAC[it] = OrthogonalPoly::EvalKernelFunction(it, subsAC);
      dphiSubsAC[it] = OrthogonalPoly::EvalDKernelFunction(it, subsAC);
    }
    for(int n1 = 0; n1 < _pf - 2; n1++) {
      double phiBA = OrthogonalPoly::EvalKernelFunction(n1, subsBA);
      double dphiBA = OrthogonalPoly::EvalDKernelFunction(n1, subsBA);
      for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
        for(int i = 0; i < 2; i++) {
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
void HierarchicalBasisH1Tria::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<double> &quadFaceFunctionsAllOrientation,
  const std::vector<double> &triFaceFunctionsAllOrientation,
  std::vector<double> &fTableCopy)
{
  int iOrientation = numberOrientationTriFace(flag1, flag2);
  int offset = iOrientation * _nTriFaceFunction;
  for(int i = 0; i < _nTriFaceFunction; i++) {
    fTableCopy[i] = triFaceFunctionsAllOrientation[i + offset];
  }
}
void HierarchicalBasisH1Tria::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iOrientation = numberOrientationTriFace(flag1, flag2);
  int offset = iOrientation * _nTriFaceFunction;
  for(int i = 0; i < _nTriFaceFunction; i++) {
    fTableCopy[i][0] = triFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = triFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = triFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisH1Tria::getKeysInfo(std::vector<int> &functionTypeInfo,
                                          std::vector<int> &orderInfo)
{
  functionTypeInfo[0] = 0;
  functionTypeInfo[1] = 0;
  functionTypeInfo[2] = 0;
  orderInfo[0] = 1;
  orderInfo[1] = 1;
  orderInfo[2] = 1;
  int it = 3;
  for(int numEdge = 0; numEdge < 3; numEdge++) {
    for(int i = 2; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int n1 = 1; n1 < _pf - 1; n1++) {
    for(int n2 = 1; n2 <= _pf - 1 - n1; n2++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = n1 + n2 + 1;
      it++;
    }
  }
}
