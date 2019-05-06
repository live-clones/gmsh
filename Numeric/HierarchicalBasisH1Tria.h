// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_TRIA_H
#define HIERARCHICAL_BASIS_H1_TRIA_H

#include <algorithm>
#include "HierarchicalBasisH1.h"

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
class HierarchicalBasisH1Tria : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Tria(int pf, int pe0, int pe1, int pe2);
  HierarchicalBasisH1Tria(int order);
  virtual ~HierarchicalBasisH1Tria();
  // vertexBasis=[v0,...,v2]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis=[phief_{1,1},...,phief_{1,pf-2},phief_{2,1},...,phief_{2,pf2-3},phief_{1,1}...]
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis);
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        std::vector<std::vector<double> > &gradientVertex,
                        std::vector<std::vector<double> > &gradientEdge,
                        std::vector<std::vector<double> > &gradientFace,
                        std::vector<std::vector<double> > &gradientBubble);

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeBasis);
  virtual void orientEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                              std::vector<std::vector<double> > &gradientEdge);

  virtual void orientFace(double const &u, double const &v, double const &w,
                          int const &flag1, int const &flag2, int const &flag3,
                          int const &faceNumber,
                          std::vector<double> &faceBasis){};

  virtual void
  orientFaceGrad(double const &u, double const &v, double const &w,
                 int const &flag1, int const &flag2, int const &flag3,
                 int const &faceNumber,
                 std::vector<std::vector<double> > &gradientFace){};

private:
  int _pf; // face function order
  int _pOrderEdge[3]; // Edge functions order (pOrderEdge[0] matches the edge 0
                      // order)
  static double
  _affineCoordinate(int const &j, double const &u,
                    double const &v); // affine coordinate lambdaj j=1..3
};

#endif
