// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_PRISM_H
#define H1_PRISM_H
#include "HierarchicalBasis.h"

/**
 * MPrism
 *
 *               w
 *               ^
 *               |
 *               3
 *             ,/|`\
 *           ,/  |  `\
 *         ,/    |    `\
 *        4------+------5
 *        |      |      |
 *        |    ,/|`\    |
 *        |  ,/  |  `\  |
 *        |,/    |    `\|
 *       ,|      |      `\
 *     ,/ |      0      | `\
 *    u   |    ,/ `\    |    v
 *        |  ,/     `\  |
 *        |,/         `\|
 *        1-------------2
 *
 *  Oriented Edges:
 *  e0={0, 1},  e1={0, 2},  e2={0, 3},
 *  e3={1, 2},  e4={1, 4},  e5={2, 5},
 *  e6={3, 4},  e7={3, 5},  e8={4, 5}
 *
 * Oriented Surfaces:
 *   s3={0, 1, 2},      s4={3, 4, 5},       s0={0, 1, 3, 4},        s1={0, 2,
 * 3,5}        s2={1,2,4,5}
 *
 * Local (directional) orders on mesh faces are not allowed to exceed the
 * minimum of the (appropriate directional) orders of approximation associated
 * with the interior of the adjacent elements. Local orders of approximation on
 * mesh edges are limited by the minimum of all (appropriate directional) orders
 * corresponding to faces sharing that edge
 *
 */

class H1Prism : public HierarchicalBasis {
private:
  std::array<int, 2> _pb; //    _pb[0] : bubble function order in  direction uv
                          //    _pb[1] : bubble function order in  direction w
  std::array<int, 9> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches
                                  // the order of the edge 0)

  std::array<std::array<int, 3>, 2>
    _pOrderQuadFace; /* _pOrderQuadFace[0] : Quad Face functions order in
                      * direction u
                      * (_pOrderQuadFace[0][i] corresponds to the u-order of
                      * face i) _pOrderQuadFace[1] : Quad Face functions order
                      * in direction v
                      * (_pOrderQuadFace[1][i] corresponds to the v-order of
                      * face i)
                      */
  std::array<int, 2> _pOrderTriFace; // Tri Face Functions order

  // affine coordinate lambda j=1..5
  static double _affineCoordinate(int j, double u, double v, double w);

  void generateGradientBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &gradientVertex,
                             std::vector<std::vector<double>> &gradientEdge,
                             std::vector<std::vector<double>> &gradientFace,
                             std::vector<std::vector<double>> &gradientBubble);

  void orientOneFace(double u, double v, double w, int flag1, int flag2,
                     int flag3, int faceNumber,
                     std::vector<double> &faceBasis) override;

  void orientOneFace(double u, double v, double w, int flag1, int flag2,
                     int flag3, int faceNumber,
                     std::vector<std::vector<double>> &faceFunctions) override;

public:
  H1Prism(int order);
  ~H1Prism() override = default;

  // vertexBasis=[v0,...,v5]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis=[QuadFace\phif2_{2,2},...,phif2_{2,pF2_2},...,phif2_{pF2_1,2},...,phief2_{pF2_1,pF2_2},phif3_{2,2}...,
  //            TriFace\phif0_{1,1},...,phif0_{1,pF0-2},phif0_{2,1}...,phif0_{2,pF0-3},...,phief0_{pF-2,1},phif1_{1,1}...]
  // bubbleBasis=[phieb_{1,1,1},...]   1<=n1,n2;n1+n2<=pb1-1; 2<=n3<pb2

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

  void getKeysInfo(std::vector<int> &functionTypeInfo,
                   std::vector<int> &orderInfo) override;
};
#endif
