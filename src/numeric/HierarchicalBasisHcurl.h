// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_HCURL_H
#define HIERARCHICAL_BASIS_HCURL_H

#include "HierarchicalBasis.h"

class HierarchicalBasisHcurl : public HierarchicalBasis {
protected:
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceFunctions){};
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction) = 0;

public:
  virtual ~HierarchicalBasisHcurl() = 0;
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis){};
  virtual void
  generateBasis(double const &u, double const &v, double const &w,
                std::vector<std::vector<double> > &vertexBasis,
                std::vector<std::vector<double> > &edgeBasis,
                std::vector<std::vector<double> > &faceBasis,
                std::vector<std::vector<double> > &bubbleBasis,
                std::string typeFunction) = 0; // typeFunction = HcurlLegendre,
                                               // CurlHcurlLegendre
  virtual void
  orientEdge(int const &flagOrientation, int const &edgeNumber,
             std::vector<std::vector<double> > &edgeBasis,
             const std::vector<std::vector<double> > &eTablePositiveFlag,
             const std::vector<std::vector<double> > &eTableNegativeFlag) = 0;

  virtual void
  orientFace(int const &flag1, int const &flag2, int const &flag3,
             int const &faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientations,
             const std::vector<double> &triFaceFunctionsAllOrientations,
             std::vector<double> &fTableCopy){};
  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
    std::vector<std::vector<double> > &fTableCopy) = 0;
  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeFunctions,
                          const std::vector<double> &eTablePositiveFlag,
                          const std::vector<double> &eTableNegativeFlag){};
  virtual void
  orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions){};
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double> > &edgeFunctions) = 0;

  virtual void addAllOrientedFaceFunctions(
    double const &u, double const &v, double const &w,
    const std::vector<double> &faceFunctions,
    std::vector<double> &quadFaceFunctionsAllOrientations,
    std::vector<double> &triFaceFunctionsAllOrientations){};
  virtual void addAllOrientedFaceFunctions(
    double const &u, double const &v, double const &w,
    const std::vector<std::vector<double> > &faceFunctions,
    std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
    std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
    std::string typeFunction);
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;
};

#endif
