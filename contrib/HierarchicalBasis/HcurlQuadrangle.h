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

#ifndef HCURL_QUADRANGLE_H
#define HCURL_QUADRANGLE_H

#include "HierarchicalBasis.h"

/*
 *
 *         v
 *         ^
 *         |+1
 *   3<----------2
 *   |     |     ^
 *   |     |     |
 * -1|     +---- |+1 --> u
 *   |           |
 *   v           |
 *   0---------->1
 *	   -1
 *
 * Oriented Edges:
 *  e0={v0;v1}    e1={v1;v2}  e2={v2;v3}  e3={v3;v4}
 *  pe3,pe1<=pf2       pe0,pe2<=pf1
 *
 */
class HcurlQuadrangle : public HierarchicalBasis {
private:
  std::array<int, 4> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches
                                  // the edge 0 order)
  std::array<int, 2> _pf; /* _pf[0] face function order in  direction u
                           & _pf[1] face function order in  direction v */

  static double _affineCoordinate(int j, double u,
                                  double v); // affine coordinate lambdaj j=1..4

  // edgeBasis=[phie0_{0},...phie0_{pe0},phie1_{0},...phie1_{pe1}...]
  // faceBasis=[phieFf1{n1,n2} (with 0<=n1<=pf1 , 2<=n2<=pf2+1), phieFf2{n1,n2}
  // (with 2<=n1<=pf1+1 , 0<=n2<=pf2) ]

  virtual void
  generateHcurlBasis(double u, double v, double w,
                     std::vector<std::vector<double>> &edgeBasis,
                     std::vector<std::vector<double>> &faceBasis,
                     std::vector<std::vector<double>> &bubbleBasis);

  virtual void generateCurlBasis(double u, double v, double w,
                                 std::vector<std::vector<double>> &edgeBasis,
                                 std::vector<std::vector<double>> &faceBasis,
                                 std::vector<std::vector<double>> &bubbleBasis);

  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<std::vector<double>> &faceFunctions);

public:
  HcurlQuadrangle(int order);

  virtual ~HcurlQuadrangle() = default;

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
