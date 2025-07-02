// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include "HierarchicalBasisH1Point.h"

HierarchicalBasisH1Point::HierarchicalBasisH1Point()
{
  _nvertex = 1;
  _nedge = 0;
  _nfaceTri = 0;
  _nfaceQuad = 0;
  _nVertexFunction = 1;
  _nEdgeFunction = 0;
  _nQuadFaceFunction = 0;
  _nTriFaceFunction = 0;
  _nBubbleFunction = 0;
}

HierarchicalBasisH1Point::~HierarchicalBasisH1Point() {}

unsigned int HierarchicalBasisH1Point::getNumberOfOrientations() const
{
  return 1; // factorial 1
}

void HierarchicalBasisH1Point::generateBasis(double const &u, double const &v,
                                             double const &w,
                                             std::vector<double> &vertexBasis,
                                             std::vector<double> &edgeBasis,
                                             std::vector<double> &faceBasis,
                                             std::vector<double> &bubbleBasis)
{
  vertexBasis[0] = 1;
}

void HierarchicalBasisH1Point::generateGradientBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &gradientVertex,
  std::vector<std::vector<double> > &gradientEdge,
  std::vector<std::vector<double> > &gradientFace,
  std::vector<std::vector<double> > &gradientBubble)
{
  gradientVertex[0][0] = 1;
}

void HierarchicalBasisH1Point::getKeysInfo(std::vector<int> &functionTypeInfo,
                                           std::vector<int> &orderInfo)
{
  functionTypeInfo[0] = 0;
  orderInfo[0] = 0;
}
