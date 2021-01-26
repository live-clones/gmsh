// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#include "HierarchicalBasisHcurlLine.h"

HierarchicalBasisHcurlLine::HierarchicalBasisHcurlLine(int order)
{
  _nvertex = 2;
  _nedge = 1;
  _nfaceTri = 0;
  _nfaceQuad = 0;
  _nVertexFunction = 0;
  _nEdgeFunction = order + 1;
  _nQuadFaceFunction = 0;
  _nTriFaceFunction = 0;
  _nBubbleFunction = 0;
  _pe = order;
}

HierarchicalBasisHcurlLine::~HierarchicalBasisHcurlLine() {}

unsigned int HierarchicalBasisHcurlLine::getNumberOfOrientations() const
{
  return 2; // factorial 2
}

double HierarchicalBasisHcurlLine::_affineCoordinate(int j, double u)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  default: throw std::string("j must be : 1<=j<=2");
  }
}

double HierarchicalBasisHcurlLine::dotProduct(const std::vector<double> &u,
                                              const std::vector<double> &v)
{
  return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}
void HierarchicalBasisHcurlLine::generateHcurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  double lambda1 = _affineCoordinate(1, u);
  double lambda2 = _affineCoordinate(2, u);
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[0] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -1;
  // Whitney functions
  std::vector<double> psie_0(3, 0);
  std::vector<double> psie_1(3, 0);
  for(int i = 0; i < 3; i++) {
    psie_0[i] = lambda1 * n2[i] / dotProduct(n2, t1) +
                lambda2 * n1[i] / dotProduct(n1, t1);
    psie_1[i] = lambda1 * n2[i] / dotProduct(n2, t1) -
                lambda2 * n1[i] / dotProduct(n1, t1);
  }
  double sub = lambda1 - lambda2;

  std::vector<double> legendreVector(_pe, 0);
  for(unsigned int k = 0; k < legendreVector.size(); k++) {
    legendreVector[k] = OrthogonalPoly::EvalLegendre(k, sub);
  }
  int edgeIt = 0;
  for(int j = 0; j < 3; j++) { edgeBasis[edgeIt][j] = psie_0[j]; }
  edgeIt++;
  if(_pe >= 1) {
    for(int j = 0; j < 3; j++) { edgeBasis[edgeIt][j] = psie_1[j]; }
    edgeIt++;
    for(int iedge = 2; iedge <= _pe; iedge++) {
      for(int j = 0; j < 3; j++) {
        edgeBasis[edgeIt][j] = (2 * float(iedge) - 1) / float(iedge) *
                                 legendreVector[iedge - 1] * psie_1[j] -
                               (float(iedge) - 1) / float(iedge) *
                                 legendreVector[iedge - 2] * psie_0[j];
      }
      edgeIt++;
    }
  }
}
void HierarchicalBasisHcurlLine::orientEdge(
  int const &flagOrientation, int const &edgeNumber,
  std::vector<std::vector<double> > &edgeFunctions,
  const std::vector<std::vector<double> > &eTablePositiveFlag,
  const std::vector<std::vector<double> > &eTableNegativeFlag)
{
  if(flagOrientation == -1) {
    for(int k = 0; k <= _pe; k++) {
      edgeFunctions[k][0] = eTableNegativeFlag[k][0];
      edgeFunctions[k][1] = eTableNegativeFlag[k][1];
      edgeFunctions[k][2] = eTableNegativeFlag[k][2];
    }
  }
  else {
    for(int k = 0; k <= _pe; k++) {
      edgeFunctions[k][0] = eTablePositiveFlag[k][0];
      edgeFunctions[k][1] = eTablePositiveFlag[k][1];
      edgeFunctions[k][2] = eTablePositiveFlag[k][2];
    }
  }
}

void HierarchicalBasisHcurlLine::orientEdgeFunctionsForNegativeFlag(
  std::vector<std::vector<double> > &edgeFunctions)
{
  for(int k = 0; k <= _pe; k++) {
    if(k % 2 == 0) {
      edgeFunctions[k][0] = edgeFunctions[k][0] * (-1);
      edgeFunctions[k][1] = edgeFunctions[k][1] * (-1);
      edgeFunctions[k][2] = edgeFunctions[k][2] * (-1);
    }
  }
}
void HierarchicalBasisHcurlLine::generateCurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  // zero for all orders
}

void HierarchicalBasisHcurlLine::getKeysInfo(std::vector<int> &functionTypeInfo,
                                             std::vector<int> &orderInfo)
{
  for(int k = 0; k <= _pe; k++) {
    orderInfo[k] = k;
    functionTypeInfo[k] = 1;
  }
}
