// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_HCURL_H
#define HIERARCHICAL_BASIS_HCURL_H

#include "HierarchicalBasis.h"

class HierarchicalBasisHcurl : public HierarchicalBasis {
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
  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<std::vector<double> > &edgeFunctions) = 0;
  virtual void orientFace(double const &u, double const &v, double const &w,
                          int const &flag1, int const &flag2, int const &flag3,
                          int const &faceNumber,
                          std::vector<std::vector<double> > &faceFunctions,
                          std::string typeFunction) = 0;

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeFunctions){};
  virtual void orientFace(double const &u, double const &v, double const &w,
                          int const &flag1, int const &flag2, int const &flag3,
                          int const &faceNumber,
                          std::vector<double> &faceFunctions){};

  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;
};

#endif
