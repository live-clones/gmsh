
#include "HierarchicalBasisH1Tria.h"

HierarchicalBasisH1Tria::HierarchicalBasisH1Tria(int pb, int pe0, int pe1,
                                                 int pe2)
{
  this->nvertex = 3;
  this->nedge = 3;
  this->nface = 1;
  this->nVertexFunction = 3;
  this->nEdgeFunction = pe0 + pe1 + pe2 - 3;
  this->nFaceFunction = 0;
  this->nBubbleFunction = (pb - 1) * (pb - 2) / 2;
  this->pb = pb;

  if(pe0 > pb || pe2 > pb || pe1 > pb) {
    throw std::string("pe0, pe1  and pe2  must be <=pb");
  }
  this->pOrderEdge[0] = pe0;
  this->pOrderEdge[1] = pe1;
  this->pOrderEdge[2] = pe2;
}
HierarchicalBasisH1Tria::HierarchicalBasisH1Tria(int order)
{
  this->nvertex = 3;
  this->nedge = 3;
  this->nface = 1;
  this->nVertexFunction = 3;
  this->nEdgeFunction = 3*order - 3;
  this->nFaceFunction = 0;
  this->nBubbleFunction = (order- 1) * (order - 2) / 2;
  this->pb = order;
  this->pOrderEdge[0] = order;
  this->pOrderEdge[1] = order;
  this->pOrderEdge[2] = order;
}
HierarchicalBasisH1Tria::~HierarchicalBasisH1Tria() {}

double HierarchicalBasisH1Tria::affineCoordinate(int const& j, double const& u, double  const& v)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  default: throw std::string("j must be : 1<=j<=3");
  }
}

void HierarchicalBasisH1Tria::generateBasis(
  double const &u, double const &v, double const &w, double *vertexBasis,
  double *edgeBasis, double *faceBasis, double *bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  //*****
  double lambda1 = affineCoordinate(1, uc, vc);
  double lambda2 = affineCoordinate(2, uc, vc);
  double lambda3 = affineCoordinate(3, uc, vc);
  double product32 = lambda2 * lambda3;
  double subst32 = lambda3 - lambda2;
  double product13 = lambda3 * lambda1;
  double subst13 = lambda1 - lambda3;
  double product21 = lambda2 * lambda1;
  double subst21 = lambda2 - lambda1;
  double product = lambda1 * lambda2 * lambda3;
  // vertex shape functions:
  vertexBasis[0] = lambda2;
  vertexBasis[1] = lambda3;
  vertexBasis[2] = lambda1;
  // edge 0  shape functions and a part of bubble functions :
  int iterator2 = 0;
  for(int k = 0; k <= this->pOrderEdge[0] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst32);
    edgeBasis[k] = product32 * kernel;
    int iterator = 0;
    while(iterator <= this->pb - 3 - k) {
      bubbleBasis[iterator2 + iterator] = product * kernel;
      iterator++;
    }
    iterator2 = iterator2 + this->pb - 2 - k;
  }
  for(int k = this->pOrderEdge[0] - 1; k <= this->pb - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst32);
    int iterator = 0;
    while(iterator <= this->pb - 3 - k) {
      bubbleBasis[iterator2 + iterator] = product * kernel;
      iterator++;
    }
    iterator2 = iterator2 + this->pb - 2 - k;
  }
  // edge 1 shape functions  :
  for(int k = 0; k <= this->pOrderEdge[1] - 2; k++) {
    edgeBasis[this->pOrderEdge[0] + k - 1] =
      product13 * OrthogonalPoly::EvalKernelFunction(k, subst13);
  }
  // edge 2  shape functions and a part of bubble functions :
  for(int k = 0; k <= this->pOrderEdge[2] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst21);
    edgeBasis[k + pOrderEdge[0] + pOrderEdge[1] - 2] = product21 * kernel;
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = this->pb - 2;
    while(iterator1 <= this->pb - 3 - k) {
      bubbleBasis[iterator2] = bubbleBasis[iterator2] * kernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
  for(int k = this->pOrderEdge[2] - 1; k <= this->pb - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst21);
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = this->pb - 2;
    while(iterator1 <= this->pb - 3 - k) {
      bubbleBasis[iterator2] = bubbleBasis[iterator2] * kernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
}

void HierarchicalBasisH1Tria::generateGradientBasis(
  double const &u, double const &v, double const &w, double gradientVertex[][3],
  double gradientEdge[][3], double gradientFace[][3],
  double gradientBubble[][3])
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
  double lambda1 = affineCoordinate(1, uc, vc);
  double lambda2 = affineCoordinate(2, uc, vc);
  double lambda3 = affineCoordinate(3, uc, vc);
  double product32 = lambda2 * lambda3;
  double subst32 = lambda3 - lambda2;
  double product13 = lambda3 * lambda1;
  double subst13 = lambda1 - lambda3;
  double product21 = lambda2 * lambda1;
  double subst21 = lambda2 - lambda1;
  double product = lambda1 * lambda2 * lambda3;
  // vertex gradient functions:
  gradientVertex[0][0] = jacob * dlambda2U;
  gradientVertex[0][1] = jacob * dlambda2V;
  gradientVertex[1][0] = jacob * dlambda3U;
  gradientVertex[1][1] = jacob * dlambda3V;
  gradientVertex[2][0] = jacob * dlambda1U;
  gradientVertex[2][1] = jacob * dlambda1V;
  double tablIntermU[this->nBubbleFunction];
  double tablIntermV[this->nBubbleFunction];
  // edge 0  gradient  and a part of bubble functions gradient :
  int iterator2 = 0;
  for(int k = 0; k <= this->pOrderEdge[0] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst32);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subst32);
    gradientEdge[k][0] =
      (gradientVertex[1][0] * lambda2 + gradientVertex[0][0] * lambda3) *
        kernel +
      product32 * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
    gradientEdge[k][1] =
      (gradientVertex[1][1] * lambda2 + gradientVertex[0][1] * lambda3) *
        kernel +
      product32 * (gradientVertex[1][1] - gradientVertex[0][1]) * dKernel;
    int iterator = 0;
    while(iterator <= this->pb - 3 - k) {
      gradientBubble[iterator2 + iterator][0] =
        (gradientVertex[1][0] * product21 + gradientVertex[0][0] * product13 +
         gradientVertex[2][0] * product32) *
          kernel +
        product * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
      gradientBubble[iterator2 + iterator][1] =
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

    iterator2 = iterator2 + this->pb - 2 - k;
  }
  for(int k = this->pOrderEdge[0] - 1; k <= this->pb - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst32);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subst32);
    int iterator = 0;
    while(iterator <= this->pb - 3 - k) {
      gradientBubble[iterator2 + iterator][0] =
        (gradientVertex[1][0] * product21 + gradientVertex[0][0] * product13 +
         gradientVertex[2][0] * product32) *
          kernel +
        product * (gradientVertex[1][0] - gradientVertex[0][0]) * dKernel;
      gradientBubble[iterator2 + iterator][1] =
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

    iterator2 = iterator2 + this->pb - 2 - k;
  }
  // edge 1 shape functions gradient  :
  for(int k = 0; k <= this->pOrderEdge[1] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst13);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subst13);
    gradientEdge[this->pOrderEdge[0] + k - 1][0] =
      (lambda3 * gradientVertex[2][0] + lambda1 * gradientVertex[1][0]) *
        kernel +
      product13 * (gradientVertex[2][0] - gradientVertex[1][0]) * dKernel;
    gradientEdge[this->pOrderEdge[0] + k - 1][1] =
      (lambda3 * gradientVertex[2][1] + lambda1 * gradientVertex[1][1]) *
        kernel +
      product13 * (gradientVertex[2][1] - gradientVertex[1][1]) * dKernel;
  }
  // edge 2  gradient  and a part of bubble functions gradient :
  for(int k = 0; k <= this->pOrderEdge[2] - 2; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst21);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subst21);
    gradientEdge[k + pOrderEdge[0] + pOrderEdge[1] - 2][0] =
      (lambda2 * gradientVertex[2][0] + lambda1 * gradientVertex[0][0]) *
        kernel +
      product21 * (gradientVertex[0][0] - gradientVertex[2][0]) * dKernel;
    gradientEdge[k + pOrderEdge[0] + pOrderEdge[1] - 2][1] =
      (lambda2 * gradientVertex[2][1] + lambda1 * gradientVertex[0][1]) *
        kernel +
      product21 * (gradientVertex[0][1] - gradientVertex[2][1]) * dKernel;
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = this->pb - 2;
    while(iterator1 <= this->pb - 3 - k) {
      gradientBubble[iterator2][0] =
        gradientBubble[iterator2][0] * kernel + tablIntermU[iterator2] * dKernel;
      gradientBubble[iterator2][1] =
        gradientBubble[iterator2][1] * kernel + tablIntermV[iterator2] * dKernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
  for(int k = this->pOrderEdge[2] - 1; k <= this->pb - 3; k++) {
    double kernel = OrthogonalPoly::EvalKernelFunction(k, subst21);
    double dKernel = OrthogonalPoly::EvalDKernelFunction(k, subst21);
    int iterator2 = k;
    int iterator1 = 0;
    int iterator3 = this->pb - 2;
    while(iterator1 <= this->pb - 3 - k) {
      gradientBubble[iterator2][0] =
        gradientBubble[iterator2][0] * kernel + tablIntermU[iterator2] * dKernel;
      gradientBubble[iterator2][1] =
        gradientBubble[iterator2][1] * kernel + tablIntermV[iterator2] * dKernel;
      iterator2 = iterator2 + iterator3;
      iterator1++;
      iterator3--;
    }
  }
}

void HierarchicalBasisH1Tria::orientateEdge(int const &flagOrientation,
                                            int const &edgeNumber,
                                            double *edgeBasis)
{
  if(flagOrientation == -1) {
    int const1;
    int const2;
    switch(edgeNumber) {
    case(0): {
      const1 = 0;
      const2 = this->pOrderEdge[0] - 2;
    case(1): {
      const1 = this->pOrderEdge[0] - 1;
      const2 = this->pOrderEdge[0] + this->pOrderEdge[1] - 3;

    } break;
    case(2): {
      const1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 2;
      const2 =
        this->pOrderEdge[2] + this->pOrderEdge[0] + this->pOrderEdge[1] - 4;

    } break;

    default: throw std::string("edgeNumber  must be : 0<=edgeNumber<=2");
    }
      for(int k = const1; k <= const2; k++) {
        if(k % 2 != 0) { edgeBasis[k] = edgeBasis[k] * (-1); }
      }
    }
  }
}

void HierarchicalBasisH1Tria::orientateEdgeGrad(int const &flagOrientation,
                                                int const &edgeNumber,
                                                double gradientEdge[][3])
{
  if(flagOrientation == -1) {
    int const1;
    int const2;
    switch(edgeNumber) {
    case(0): {
      const1 = 0;
      const2 = this->pOrderEdge[0] - 2;

    } break;
    case(1): {
      const1 = this->pOrderEdge[0] - 1;
      const2 = this->pOrderEdge[0] + this->pOrderEdge[1] - 3;

    } break;
    case(2): {
      const1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 2;
      const2 =
        this->pOrderEdge[2] + this->pOrderEdge[0] + this->pOrderEdge[1] - 4;

    } break;

    default: throw std::string("edgeNumber  must be : 0<=edgeNumber<=2");
    }
    for(int k = const1; k <= const2; k++) {
      if(k % 2 != 0) {
        gradientEdge[k][0] = gradientEdge[k][0] * (-1);
        gradientEdge[k][1] = gradientEdge[k][1] * (-1);
      }
    }
  }
}
