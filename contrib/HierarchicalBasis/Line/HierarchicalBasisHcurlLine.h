// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_HCURL_LINE_H
#define HIERARCHICAL_BASIS_HCURL_LINE_H

#include "HierarchicalBasis.h"

/*
 *
 *          ^ v
 *          |
 *          |
 *   0      |     1
 * --+------+-----+---> u
 *
 */

class HierarchicalBasisHcurlLine : public HierarchicalBasis {
private:
  int _pe; //  edge function order in  direction u

  static double
  _affineCoordinate(int j, double u); // affine coordinate lambda_j j={1,2}

  virtual void
  generateHcurlBasis(double u, double v, double w,
                     std::vector<std::vector<double>> &edgeBasis,
                     std::vector<std::vector<double>> &faceBasis,
                     std::vector<std::vector<double>> &bubbleBasis);
  virtual void generateCurlBasis(double u, double v, double w,
                                 std::vector<std::vector<double>> &edgeBasis,
                                 std::vector<std::vector<double>> &faceBasis,
                                 std::vector<std::vector<double>> &bubbleBasis);

  static double dotProduct(const std::vector<double> &u,
                           const std::vector<double> &v);

public:
  HierarchicalBasisHcurlLine(int order);

  virtual ~HierarchicalBasisHcurlLine() = default;

  virtual void generateBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &vertexBasis,
                             std::vector<std::vector<double>> &edgeBasis,
                             std::vector<std::vector<double>> &faceBasis,
                             std::vector<std::vector<double>> &bubbleBasis)
  {
    if(_space == HCURL) {
      generateHcurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
    }
    else if(_space == CURL_HCURL) {
      generateCurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
    }
  }

  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo);
};

#endif
