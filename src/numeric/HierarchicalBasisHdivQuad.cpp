// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include "HierarchicalBasisHdivQuad.h"

HierarchicalBasisHdivQuad::HierarchicalBasisHdivQuad(int order)
{
}

HierarchicalBasisHdivQuad::~HierarchicalBasisHdivQuad() {}

unsigned int HierarchicalBasisHdivQuad::getNumberOfOrientations() const
{
}

double HierarchicalBasisHdivQuad::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v)
{

}

void HierarchicalBasisHdivQuad::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{

}

void HierarchicalBasisHdivQuad::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{

}

void HierarchicalBasisHdivQuad::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{

}

void HierarchicalBasisHdivQuad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{

}

void HierarchicalBasisHdivQuad::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{

}

void HierarchicalBasisHdivQuad::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{

}

void HierarchicalBasisHdivQuad::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{

}
