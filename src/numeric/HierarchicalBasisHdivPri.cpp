// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).
#include "HierarchicalBasisHdivPri.h"

HierarchicalBasisHdivPri::HierarchicalBasisHdivPri(int order)
{
}

HierarchicalBasisHdivPri::~HierarchicalBasisHdivPri() {}

unsigned int HierarchicalBasisHdivPri::getNumberOfOrientations() const
{
}

double HierarchicalBasisHdivPri::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v,
                                                      const double &w)
{

}

void HierarchicalBasisHdivPri::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{

}

void HierarchicalBasisHdivPri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{

}

void HierarchicalBasisHdivPri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{

}

void HierarchicalBasisHdivPri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{

}

void HierarchicalBasisHdivPri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{

}

void HierarchicalBasisHdivPri::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{

}

void HierarchicalBasisHdivPri::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{

}
