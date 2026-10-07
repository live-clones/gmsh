// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).
//
// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_TRIANGLE_H
#define HCURL_TRIANGLE_H

#include <iostream>
#include <math.h>
#include "HierarchicalBasis.h"

/*
 * MTriangle
 *
 *   v
 *   ^
 *   |
 *   2
 *   |`\
 *   |  `\
 *   |    `\
 *   |      `\
 *   v        `\
 *   0---------->1 --> u
 *
 *
 * Oriented Edges:
 *  e0={v0;v1}    e1={v1;v2}  e2={v2;v0}
 *  pe0,pe1,pe2<=pf
 *
 */
class HcurlTriangle : public HierarchicalBasis {
private:
  int _pf; // face function order
  std::array<int, 3> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches
                                  // the edge 0 order)

  // affine coordinate lambda_j j=1..3
  static double _affineCoordinate(int j, double u, double v);

  // edgeBasis=[phie0_{0},...phie0_{pe0},phie1_{0},...phie1_{pe1}...; edge-based
  // bubble functions ] faceBasis=[ genuine bubble functions]
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

  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<std::vector<double>> &faceFunctions);

public:
  HcurlTriangle(int order);

  virtual ~HcurlTriangle() = default;

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
