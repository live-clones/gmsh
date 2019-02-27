

#include "HierarchicalBasisH1Quad.h"

HierarchicalBasisH1Quad::HierarchicalBasisH1Quad(int pb1, int pb2, int pe0,
                                                 int pe1, int pe2, int pe3)

{
  this->nvertex = 4;
  this->nedge = 4;
  this->nface = 1;
  this->nVertexFunction = 4;
  this->nEdgeFunction = pe0 + pe1 + pe2 + pe3 - 4;
  this->nFaceFunction = 0;
  this->nBubbleFunction = (pb1 - 1) * (pb2 - 1);
  this->pb1 = pb1;
  this->pb2 = pb2;
  if(pe1 > pb2 || pe3 > pb2) { throw std::string("pe1 and pe3 must be <=pb2"); }
  if(pe0 > pb1 || pe2 > pb1) {
    throw std::string("pe0  and pe2  must be <=pb1");
  }
  this->pOrderEdge[0] = pe0;
  this->pOrderEdge[1] = pe1;
  this->pOrderEdge[2] = pe2;
  this->pOrderEdge[3] = pe3;
}

HierarchicalBasisH1Quad::~HierarchicalBasisH1Quad() {}

double HierarchicalBasisH1Quad::affineCoordinate(int const &j, double const & u, double const & v)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  case(3): return 0.5 * (1 + v);
  case(4): return 0.5 * (1 - v);
  default: throw std::string("j must be : 1<=j<=4");
  }
}

void HierarchicalBasisH1Quad::generateBasis(
  double const &u, double const &v, double const &w, double *vertexBasis,
  double *edgeBasis, double *faceBasis, double *bubbleBasis)
{
  double lambda1 = affineCoordinate(1, u, v);
  double lambda2 = affineCoordinate(2, u, v);
  double lambda3 = affineCoordinate(3, u, v);
  double lambda4 = affineCoordinate(4, u, v);
  // vertex shape functions:
  vertexBasis[0] = lambda2 * lambda4;
  vertexBasis[1] = lambda1 * lambda4;
  vertexBasis[2] = lambda1 * lambda3;
  vertexBasis[3] = lambda2 * lambda3;
  // edge 0  & 2 shape functions and a part of bubble functions (all lk(u)):
  int minpe0pe2 = std::min(this->pOrderEdge[0], this->pOrderEdge[2]);
  int const1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 4;
  for(int k = 2; k <= minpe0pe2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double phie0 = lambda4 * lk;
    double phie2;
    if(k % 2 != 0) { phie2 = -lambda3 * lk; }
    else {
      phie2 = lambda3 * lk;
    }
    int const2 = k - 2;
    edgeBasis[const2] = phie0;
    edgeBasis[k + const1] = phie2;
    int const3 = this->pb2 - 1;
    int iterator = 0;
    while(iterator < const3) {
      int nbr = const2 * const3 + iterator;
      bubbleBasis[nbr] = lk;
      iterator++;
    }
  }
  if(this->pOrderEdge[0] > minpe0pe2) {
    for(int k = minpe0pe2 + 1; k <= this->pOrderEdge[0]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double phie0 = lambda4 * lk;
      int const2 = k - 2;
      edgeBasis[const2] = phie0;
      int const3 = this->pb2 - 1;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = const2 * const3 + iterator;
        bubbleBasis[nbr] = lk;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe0pe2 + 1; k <= this->pOrderEdge[2]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double phie2;
      if(k % 2 != 0) { phie2 = -lambda3 * lk; }
      else {
        phie2 = lambda3 * lk;
      }
      edgeBasis[k + const1] = phie2;
      int iterator = 0;
      int const3 = this->pb2 - 1;
      while(iterator < const3) {
        int nbr = (k - 2) * const3 + iterator;
        bubbleBasis[nbr] = lk;
        iterator++;
      }
    }
  }
  int maxpe0pe2 = std::max(this->pOrderEdge[0], this->pOrderEdge[2]);
  for(int k = maxpe0pe2 + 1; k <= this->pb1; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    int iterator = 0;
    int const3 = this->pb2 - 1;
    while(iterator < const3) {
      int nbr = (k - 2) * const3 + iterator;
      bubbleBasis[nbr] = lk;
      iterator++;
    }
  }
  // edge 1 & 3 shape functions and a part of  bubble functions (all lk(v)) :
  int minpe1pe3 = std::min(this->pOrderEdge[1], this->pOrderEdge[3]);
  int const3 = this->pOrderEdge[0] - 3;
  int const4 =
    this->pOrderEdge[0] + this->pOrderEdge[1] + this->pOrderEdge[2] - 5;
  for(int k = 2; k <= minpe1pe3; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double phie3;
    if(k % 2 != 0) { phie3 = -lambda2 * lk; }
    else {
      phie3 = lambda2 * lk;
    }
    double phie1 = lambda1 * lk;
    edgeBasis[k + const3] = phie1;
    edgeBasis[k + const4] = phie3;
    int s = k - 2;
    int iterator = 1;
    while(iterator <= this->pb1 - 1) {
      bubbleBasis[s] = bubbleBasis[s] * lk;
      s = s + this->pb2 - 1;
      iterator++;
    }
  }
  if(this->pOrderEdge[1] > minpe1pe3) {
    for(int k = minpe1pe3 + 1; k <= this->pOrderEdge[1]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double phie1 = lambda1 * lk;
      edgeBasis[k + const3] = phie1;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= this->pb1 - 1) {
        bubbleBasis[s] = bubbleBasis[s] * lk;
        s = s + this->pb2 - 1;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe1pe3 + 1; k <= this->pOrderEdge[3]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double phie3;
      if(k % 2 != 0) { phie3 = -lambda2 * lk; }
      else {
        phie3 = lambda2 * lk;
      }
      edgeBasis[k + const4] = phie3;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= this->pb1 - 1) {
        bubbleBasis[s] = bubbleBasis[s] * lk;
        s = s + this->pb2 - 1;
        iterator++;
      }
    }
  }
  int maxpe1pe3 = std::max(this->pOrderEdge[1], this->pOrderEdge[3]);
  for(int k = maxpe1pe3 + 1; k <= this->pb2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    int s = k - 2;
    int iterator = 1;
    while(iterator <= this->pb1 - 1) {
      bubbleBasis[s] = bubbleBasis[s] * lk;
      s = s + this->pb2 - 1;
      iterator++;
    }
  }
}

void HierarchicalBasisH1Quad::generateGradientBasis(
  double const &u, double const &v, double const &w, double gradientVertex[][3],
  double gradientEdge[][3], double gradientFace[][3],
  double gradientBubble[][3])
{
  double dlambda1 = 0.5;
  double dlambda2 = -0.5;
  double dlambda3 = 0.5;
  double dlambda4 = -0.5;
  double lambda1 = affineCoordinate(1, u, v);
  double lambda2 = affineCoordinate(2, u, v);
  double lambda3 = affineCoordinate(3, u, v);
  double lambda4 = affineCoordinate(4, u, v);
  // vertex gradient functions:
  gradientVertex[0][0] = dlambda2 * lambda4;
  gradientVertex[0][1] = lambda2 * dlambda4;
  gradientVertex[1][0] = dlambda1 * lambda4;
  gradientVertex[1][1] = lambda1 * dlambda4;
  gradientVertex[2][0] = dlambda1 * lambda3;
  gradientVertex[2][1] = lambda1 * dlambda3;
  gradientVertex[3][0] = dlambda2 * lambda3;
  gradientVertex[3][1] = lambda2 * dlambda3;
  // edge 0  & 2 gradient  and a part of bubble gradient  ( in the direction u
  // ):
  int const1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 4;
  int minpe0pe2 = std::min(this->pOrderEdge[0], this->pOrderEdge[2]);
  for(int k = 2; k <= minpe0pe2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double dlk = OrthogonalPoly::EvalDLobatto(k, u);
    double dphie0U = lambda4 * dlk;
    double dphie0V = dlambda4 * lk;
    double dphie2U;
    double dphie2V;
    if(k % 2 != 0) {
      dphie2U = -lambda3 * dlk;
      dphie2V = -dlambda3 * lk;
    }
    else {
      dphie2U = lambda3 * dlk;
      dphie2V = dlambda3 * lk;
    }
    int const2 = k - 2;
    int const3 = this->pb2 - 1;
    gradientEdge[const2][0] = dphie0U;
    gradientEdge[const2][1] = dphie0V;
    gradientEdge[k + const1][0] = dphie2U;
    gradientEdge[k + const1][1] = dphie2V;
    int iterator = 0;
    while(iterator < const3) {
      int nbr = const2 * const3 + iterator;
      gradientBubble[nbr][0] = dlk;
      gradientBubble[nbr][1] = lk;
      iterator++;
    }
  }
  if(this->pOrderEdge[0] > minpe0pe2) {
    for(int k = minpe0pe2 + 1; k <= this->pOrderEdge[0]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double dlk = OrthogonalPoly::EvalDLobatto(k, u);
      double dphie0U = lambda4 * dlk;
      double dphie0V = dlambda4 * lk;
      int const2 = k - 2;
      int const3 = this->pb2 - 1;
      gradientEdge[const2][0] = dphie0U;
      gradientEdge[const2][1] = dphie0V;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = const2 * const3 + iterator;
        gradientBubble[nbr][0] = dlk;
        gradientBubble[nbr][1] = lk;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe0pe2 + 1; k <= this->pOrderEdge[2]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, u);
      double dlk = OrthogonalPoly::EvalDLobatto(k, u);
      double dphie2U;
      double dphie2V;
      if(k % 2 != 0) {
        dphie2U = -lambda3 * dlk;
        dphie2V = -dlambda3 * lk;
      }
      else {
        dphie2U = lambda3 * dlk;
        dphie2V = dlambda3 * lk;
      }
      gradientEdge[k + const1][0] = dphie2U;
      gradientEdge[k + const1][1] = dphie2V;
      int const3 = this->pb2 - 1;
      int iterator = 0;
      while(iterator < const3) {
        int nbr = (k - 2) * (const3) + iterator;
        gradientBubble[nbr][0] = dlk;
        gradientBubble[nbr][1] = lk;
        iterator++;
      }
    }
  }
  int maxpe0pe2 = std::max(this->pOrderEdge[0], this->pOrderEdge[2]);
  for(int k = maxpe0pe2 + 1; k <= this->pb1; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, u);
    double dlk = OrthogonalPoly::EvalDLobatto(k, u);
    int iterator = 1;
    while(iterator < this->pb2) {
      int nbr = (k - 2) * (pb2 - 1) + iterator;
      gradientBubble[nbr][0] = dlk;
      gradientBubble[nbr][1] = lk;
      iterator++;
    }
  }

  // edge 1 & 3 shape functions and a part of  bubble functions (all lk(v)) :
  int minpe1pe3 = std::min(this->pOrderEdge[1], this->pOrderEdge[3]);
  int const3 = this->pOrderEdge[0] - 3;
  int const4 =
    this->pOrderEdge[0] + this->pOrderEdge[1] + this->pOrderEdge[2] - 5;
  for(int k = 2; k <= minpe1pe3; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double dlk = OrthogonalPoly::EvalDLobatto(k, v);
    double dphie3U;
    double dphie3V;
    if(k % 2 != 0) {
      dphie3U = -dlambda2 * lk;
      dphie3V = -lambda2 * dlk;
    }
    else {
      dphie3U = dlambda2 * lk;
      dphie3V = lambda2 * dlk;
    }

    double dphie1U = dlambda1 * lk;
    double dphie1V = lambda1 * dlk;
    gradientEdge[k + const3][0] = dphie1U;
    gradientEdge[k + const3][1] = dphie1V;
    gradientEdge[k + const4][0] = dphie3U;
    gradientEdge[k + const4][1] = dphie3V;
    int s = k - 2;
    int iterator = 1;
    while(iterator <= this->pb1 - 1) {
      gradientBubble[s][0] = gradientBubble[s][0] * lk;
      gradientBubble[s][1] = gradientBubble[s][1] * dlk;
      s = s + this->pb2 - 1;
      iterator++;
    }
  }
  if(this->pOrderEdge[1] > minpe1pe3) {
    for(int k = minpe1pe3 + 1; k <= this->pOrderEdge[1]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double dlk = OrthogonalPoly::EvalDLobatto(k, v);
      double dphie1U = dlambda1 * lk;
      double dphie1V = lambda1 * dlk;
      gradientEdge[k + const3][0] = dphie1U;
      gradientEdge[k + const3][1] = dphie1V;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= this->pb1 - 1) {
        gradientBubble[s][0] = gradientBubble[s][0] * lk;
        gradientBubble[s][1] = gradientBubble[s][1] * dlk;
        s = s + this->pb2 - 1;
        iterator++;
      }
    }
  }
  else {
    for(int k = minpe1pe3 + 1; k <= this->pOrderEdge[3]; k++) {
      double lk = OrthogonalPoly::EvalLobatto(k, v);
      double dlk = OrthogonalPoly::EvalDLobatto(k, v);
      double dphie3U;
      double dphie3V;
      if(k % 2 != 0) {
        dphie3U = -dlambda2 * lk;
        dphie3V = -lambda2 * dlk;
      }
      else {
        dphie3U = dlambda2 * lk;
        dphie3V = lambda2 * dlk;
      }
      gradientEdge[k + const4][0] = dphie3U;
      gradientEdge[k + const4][1] = dphie3V;
      int s = k - 2;
      int iterator = 1;
      while(iterator <= this->pb1 - 1) {
        gradientBubble[s][0] = gradientBubble[s][0] * lk;
        gradientBubble[s][1] = gradientBubble[s][1] * dlk;
        s = s + this->pb2 - 1;
        iterator++;
      }
    }
  }
  int maxpe1pe3 = std::max(this->pOrderEdge[1], this->pOrderEdge[3]);
  for(int k = maxpe1pe3 + 1; k <= this->pb2; k++) {
    double lk = OrthogonalPoly::EvalLobatto(k, v);
    double dlk = OrthogonalPoly::EvalDLobatto(k, v);
    int s = k - 2;
    int iterator = 1;
    while(iterator <= this->pb1 - 1) {
      gradientBubble[s][0] = gradientBubble[s][0] * lk;
      gradientBubble[s][1] = gradientBubble[s][1] * dlk;
      s = s + this->pb2 - 1;
      iterator++;
    }
  }
}

void HierarchicalBasisH1Quad::orientateEdge(int const &flagOrientation,
                                            int const &edgeNumber,
                                            double *edgeBasis)
{
  if(flagOrientation == -1) {
    int constant1;
    int constant2;
    switch(edgeNumber) {
    case(0): {
      constant1 = 0;
      constant2 = this->pOrderEdge[0] - 2;
    } break;
    case(1): {
      constant1 = this->pOrderEdge[0] - 1;
      constant2 = this->pOrderEdge[1] + this->pOrderEdge[0] - 3;
    } break;
    case(2): {
      constant1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 2;
      constant2 =
        this->pOrderEdge[1] + this->pOrderEdge[0] + this->pOrderEdge[2] - 4;
    } break;
    case(3): {
      constant1 =
        this->pOrderEdge[0] + this->pOrderEdge[1] + this->pOrderEdge[2] - 1;
      constant2 = this->pOrderEdge[1] + this->pOrderEdge[0] +
                  this->pOrderEdge[2] + pOrderEdge[3] - 5;
    } break;
    default: throw std::string("edgeNumber  must be : 0<=edgeNumber<=3");
    }
    for(int k = constant1; k <= constant2; k++) {
      if(k % 2 != 0) { edgeBasis[k] = edgeBasis[k] * (-1); }
    }
  }
}

void HierarchicalBasisH1Quad::orientateEdgeGrad(int const &flagOrientation,
                                                int const &edgeNumber,
                                                double gradientEdge[][3])
{
  if(flagOrientation == -1) {
    int constant1;
    int constant2;
    switch(edgeNumber) {
    case(0): {
      constant1 = 0;
      constant2 = this->pOrderEdge[0] - 2;
    } break;
    case(1): {
      constant1 = this->pOrderEdge[0] - 1;
      constant2 = this->pOrderEdge[1] + this->pOrderEdge[0] - 3;
    } break;
    case(2): {
      constant1 = this->pOrderEdge[0] + this->pOrderEdge[1] - 2;
      constant2 =
        this->pOrderEdge[1] + this->pOrderEdge[0] + this->pOrderEdge[2] - 4;
    } break;
    case(3): {
      constant1 =
        this->pOrderEdge[0] + this->pOrderEdge[1] + this->pOrderEdge[2] - 1;
      constant2 = this->pOrderEdge[1] + this->pOrderEdge[0] +
                  this->pOrderEdge[2] + pOrderEdge[3] - 5;
    } break;
    default: throw std::string("edgeNumber  must be : 0<=edgeNumber<=3");
    }
    for(int k = constant1; k <= constant2; k++) {
      if(k % 2 != 0) {
        gradientEdge[k][0] = gradientEdge[k][0] * (-1);
        gradientEdge[k][1] = gradientEdge[k][1] * (-1);
      }
    }
  }
}
