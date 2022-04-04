// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include "HierarchicalBasisHdivQuad.h"

HierarchicalBasisHdivQuad::HierarchicalBasisHdivQuad(int order)
{
  _nvertex = 4;
  _nedge = 4;
  _nfaceQuad = 1;
  _nfaceTri = 0;
  _nVertexFunction = 0;
  _nEdgeFunction = 0;
  _nQuadFaceFunction = (order + 1) * (order + 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = 0;
  _pf1 = order;
  _pf2 = order;
  _pOrderEdge[0] = order;
  _pOrderEdge[1] = order;
  _pOrderEdge[2] = order;
  _pOrderEdge[3] = order;
}

HierarchicalBasisHdivQuad::~HierarchicalBasisHdivQuad() {}

unsigned int HierarchicalBasisHdivQuad::getNumberOfOrientations() const
{
  return 24; // factorial 4
}

double HierarchicalBasisHdivQuad::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  case(3): return 0.5 * (1 + v);
  case(4): return 0.5 * (1 - v);
  default: throw std::string("j must be : 1<=j<=4");
  }
}

void HierarchicalBasisHdivQuad::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  std::vector<std::vector<double> > legendreVector(2);
  legendreVector[0] = std::vector<double>(_pf1 + 1);
  legendreVector[1] = std::vector<double>(_pf2 + 1);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, u);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, v);
  }

  // face  functions:
  int indexFaceFunction = 0;
  for(int index1 = 0; index1 < _pf1 + 1; index1++) {
    for(int index2 = 0; index2 < _pf2 + 1; index2++) {
      faceBasis[indexFaceFunction][0] = faceBasis[indexFaceFunction][1] = 0.;
      faceBasis[indexFaceFunction][2] = legendreVector[0][index1] *
        legendreVector[1][index2];
      indexFaceFunction++;
    }
  }
}

void HierarchicalBasisHdivQuad::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{
  return;
}

void HierarchicalBasisHdivQuad::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    if(flag3 == 1) {
      for(int it1 = 0; it1 < _pf1 + 1; it1++) {
        for(int it2 = 0; it2 < _pf2 + 1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
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
      std::vector<std::vector<double> > legendreVector(2);
      legendreVector[0] = std::vector<double>(_pf1 + 1);
      legendreVector[1] = std::vector<double>(_pf2 + 1);
      for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
        legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, u);
      }
      for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
        legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, v);
      }

      // face  functions:
      for(int index1 = 0; index1 < _pf2 + 1; index1++) {
        for(int index2 = 0; index2 < _pf1 + 1; index2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && index1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && index2 % 2 == 0) { impactFlag2 = -1; }
          faceFunctions[iterator][0] = 0.;
          faceFunctions[iterator][1] = 0.;
          faceFunctions[iterator][2] = legendreVector[0][index1] *
            legendreVector[1][index2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisHdivQuad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  for(int i = 0; i < _nQuadFaceFunction; i++) {
    fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];

  }
}

void HierarchicalBasisHdivQuad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  for(int i = 0; i < _nQuadFaceFunction; i++) {
    fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisHdivQuad::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{
  return;
}

void HierarchicalBasisHdivQuad::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{
  int it = 0;
  for(int index1 = 0; index1 < _pf1 + 1; index1++) {
    for(int index2 = 0; index2 < _pf2 + 1; index2++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = std::max(index1, index2);
      it++;
    }
  }
}
