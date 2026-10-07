// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_LINE_H
#define HIERARCHICAL_BASIS_H1_LINE_H

#include "HierarchicalBasisH1.h"

/* MLine
 *
 *
 *                   ^ v
 *                   |
 *                   |
 *                   |
 *            v0     |     v1
 *       -----+------+-----+------> u
 *           -1      0     1
 *
 *
 */

class HierarchicalBasisH1Line : public HierarchicalBasisH1 {
private:
  int _pe; //  edge function order in  direction u

  static double
  _affineCoordinate(int j, double u); // affine coordinate lambda_j, j={1,2}

  void generateGradientBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &gradientVertex,
                             std::vector<std::vector<double>> &gradientEdge,
                             std::vector<std::vector<double>> &gradientFace,
                             std::vector<std::vector<double>> &gradientBubble);

public:
  HierarchicalBasisH1Line(int pe);
  ~HierarchicalBasisH1Line() override = default;

  // vertexBasis = [v0,v1]
  // edgeBasis   = [phie_{2},...,phie_{pe}]

  void generateBasis(double u, double v, double w,
                     std::vector<double> &vertexBasis,
                     std::vector<double> &edgeBasis,
                     std::vector<double> &faceBasis,
                     std::vector<double> &bubbleBasis) override;

  void generateBasis(double u, double v, double w,
                     std::vector<std::vector<double>> &vertexBasis,
                     std::vector<std::vector<double>> &edgeBasis,
                     std::vector<std::vector<double>> &faceBasis,
                     std::vector<std::vector<double>> &bubbleBasis) override
  {
    generateGradientBasis(u, v, w, vertexBasis, edgeBasis, faceBasis,
                          bubbleBasis);
  }

  void orientEdgeFunctionsForNegativeFlag(
    std::vector<double> &edgeFunctions) override;
  void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double>> &edgeFunctions) override;

  void orientEdge(int flagOrientation, int edgeNumber,
                  std::vector<double> &edgeFunctions,
                  const std::vector<double> &eTablePositiveFlag,
                  const std::vector<double> &eTableNegativeFlag) override;
  void orientEdge(
    int flagOrientation, int edgeNumber,
    std::vector<std::vector<double>> &edgeBasis,
    const std::vector<std::vector<double>> &eTablePositiveFlag,
    const std::vector<std::vector<double>> &eTableNegativeFlag) override;

  void getKeysInfo(std::vector<int> &functionTypeInfo,
                   std::vector<int> &orderInfo) override;
};

#endif
