// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include "HierarchicalBasisHdivTria.h"

HierarchicalBasisHdivTria::HierarchicalBasisHdivTria(int order)
{
}

HierarchicalBasisHdivTria::~HierarchicalBasisHdivTria() {}

unsigned int HierarchicalBasisHdivTria::getNumberOfOrientations() const
{
}

double HierarchicalBasisHdivTria::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v)
{

}

void HierarchicalBasisHdivTria::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{

}

void HierarchicalBasisHdivTria::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{

}

void HierarchicalBasisHdivTria::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{

}

void HierarchicalBasisHdivTria::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{

}

void HierarchicalBasisHdivTria::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{

}

void HierarchicalBasisHdivTria::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{

}

void HierarchicalBasisHdivTria::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{

}
