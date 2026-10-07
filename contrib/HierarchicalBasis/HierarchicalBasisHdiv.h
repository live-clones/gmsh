// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Nawfel BENATIA (2025), based on Ismail Badia's contribution
// (2019).
//
// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_HDIV_H
#define HIERARCHICAL_BASIS_HDIV_H

#include "HierarchicalBasis.h"

class HierarchicalBasisHdiv : public HierarchicalBasis {
protected:
  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<double> &faceFunctions) = 0;

  virtual void
  orientOneFace(double u, double v, double w, int flag1, int flag2, int flag3,
                int faceNumber,
                std::vector<std::vector<double>> &faceFunctions) = 0;

  HierarchicalBasisHdiv() = default;

public:
  virtual ~HierarchicalBasisHdiv() = default;

  virtual void generateBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &vertexBasis,
                             std::vector<std::vector<double>> &edgeBasis,
                             std::vector<std::vector<double>> &faceBasis,
                             std::vector<std::vector<double>> &bubbleBasis) = 0;
  virtual void generateBasis(double u, double v, double w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis) = 0;

  virtual void
  orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) = 0;
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double>> &edgeFunctions) = 0;

  virtual void orientEdge(int flagOrientation, int edgeNumber,
                          std::vector<double> &edgeFunctions,
                          const std::vector<double> &eTablePositiveFlag,
                          const std::vector<double> &eTableNegativeFlag) = 0;
  virtual void
  orientEdge(int flagOrientation, int edgeNumber,
             std::vector<std::vector<double>> &edgeBasis,
             const std::vector<std::vector<double>> &eTablePositiveFlag,
             const std::vector<std::vector<double>> &eTableNegativeFlag) = 0;

  virtual void addAllOrientedFaceFunctions(
    double u, double v, double w, const std::vector<double> &faceFunctions,
    std::vector<double> &quadFaceFunctionsAllOrientations,
    std::vector<double> &triFaceFunctionsAllOrientations);
  virtual void addAllOrientedFaceFunctions(
    double u, double v, double w,
    const std::vector<std::vector<double>> &faceFunctions,
    std::vector<std::vector<double>> &quadFaceFunctionsAllOrientations,
    std::vector<std::vector<double>> &triFaceFunctionsAllOrientations);

  virtual void
  orientFace(int flag1, int flag2, int flag3, int faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientations,
             const std::vector<double> &triFaceFunctionsAllOrientations,
             std::vector<double> &fTableCopy) = 0;
  virtual void orientFace(
    int flag1, int flag2, int flag3, int faceNumber,
    const std::vector<std::vector<double>> &quadFaceFunctionsAllOrientations,
    const std::vector<std::vector<double>> &triFaceFunctionsAllOrientations,
    std::vector<std::vector<double>> &fTableCopy) = 0;

  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;
};

#endif
