// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).


#include "HierarchicalBasisH1Line.h"

HierarchicalBasisH1Line::HierarchicalBasisH1Line(int pe)
{
  _nvertex = 2;
  _nedge = 1;
  _nface = 0;
  _nVertexFunction = 2;
  _nEdgeFunction = (pe - 1);
  _nFaceFunction = 0;
  _nBubbleFunction = 0;
  _pe=pe;
}

HierarchicalBasisH1Line::~HierarchicalBasisH1Line() {}

double HierarchicalBasisH1Line::_affineCoordinate(int j, double u)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  default: throw std::string("j must be : 1<=j<=2");
  }
}

void HierarchicalBasisH1Line::generateBasis(double const &u, double const &v,
                                            double const &w,
                                            std::vector<double> &vertexBasis,
                                            std::vector<double> &edgeBasis,
                                            std::vector<double> &faceBasis,
                                            std::vector<double> &bubbleBasis)
{
  double lambda1 = _affineCoordinate(1, u);
  double lambda2 = _affineCoordinate(2, u);
  double product = lambda1 * lambda2;
  double substraction = lambda1 - lambda2;
  // vertex shape functions:
  vertexBasis[0] = lambda2;
  vertexBasis[1] = lambda1;
  // edge functions :
  for(int k = 2; k <= _pe; k++) {
    edgeBasis[k - 2] =
      product * OrthogonalPoly::EvalKernelFunction(k - 2, substraction);
  }
}

void HierarchicalBasisH1Line::generateGradientBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &gradientVertex,
  std::vector<std::vector<double> > &gradientEdge,
  std::vector<std::vector<double> > &gradientFace,
  std::vector<std::vector<double> > &gradientBubble)
{
  double dlambda1 = 0.5;
  double dlambda2 = -0.5;
  // vertex gradient functions:
  gradientVertex[0][0] =  dlambda2;
  gradientVertex[1][0] =  dlambda1;
  for(int k = 2; k <= _pe; k++) {
    gradientEdge[k - 2][0] =
      OrthogonalPoly::EvalDLobatto(k, u);
  }
}
