// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_TETRAHEDRON_H
#define H1_TETRAHEDRON_H

#include "HierarchicalBasis.h"

/*
 * MTetrahedron
 *
 *                      v
 *                    .
 *                  ,/
 *                 /
 *              2
 *            ,/|`\
 *          ,/  |  `\
 *        ,/    '.   `\
 *      ,/       |     `\
 *    ,/         |       `\
 *   0-----------'.--------1 --> u
 *    `\.         |      ,/
 *       `\.      |    ,/
 *          `\.   '. ,/
 *             `\. |/
 *                `3
 *                   `\.
 *                      ` w
 *
 *
 *  Oriented Edges:
 *      e0={0, 1}, e1={1, 2}, e2={2, 0}, e3={0, 3}, e4={2, 3}, e5={1, 3}
 *
 *
 * Oritented Surface:
 *      s0={0, 1, 2}, s1={0, 1, 3}, s2={0, 2, 3}, s3={1, 2, 3}
 *
 *   Local (directional) orders on mesh faces are not allowed to exceed
 *   the minimum of the (appropriate directional) orders of approximation
 *   associated with the interior of the adjacent elements.
 *
 *   Local orders of approximation on mesh edges are limited
 *   by the minimum of all (appropriate directional) orders
 *   corresponding to faces sharing that edge
 */

class H1Tetrahedron : public HierarchicalBasis {
private:
  std::array<int, 6> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches
                                  // the order of the edge 0)
  std::array<int, 4> _pOrderFace; // Face functions order in direction
  int _pb; // bubble function order

  // affine coordinate lambdaj j=1..4
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
  H1Tetrahedron(int order);
  ~H1Tetrahedron() override = default;

  // vertexBasis = [v0,...,v3]
  // edgeBasis   = [phie0_{2},...,phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis   =
  // [phif0_{1,1},...,phif0_{1,pF0-2},phif0_{2,1}...,phif0_{2,pF0-3},...,phief0_{pF-2,1},phif1_{1,1}...]
  // bubbleBasis = [phieb_{1,1,1},...,phieb_{1,1,pb-3},...]   n1+n2+n3<=pb-1
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
