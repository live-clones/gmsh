// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_QUAD_H
#define HIERARCHICAL_BASIS_H1_QUAD_H

#include <algorithm>
#include "HierarchicalBasisH1.h"

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
class HierarchicalBasisH1Quad : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Quad(int pf1, int pf2, int pe0, int pe1, int pe2, int pe3);
  HierarchicalBasisH1Quad(int order);
  virtual ~HierarchicalBasisH1Quad();
  // vertexBasis=[v0,...,v3]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis=[phief_{2,2},...,phief_{2,pf2},phief_{3,2},...,phief_{3,pf2},...,phief_{pf1,2},...,phief_{pf1,pf2}]
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
  int _pf1; // face function order in  direction u
  int _pf2; // face function order in  direction v
  int _pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0
                      // order)
  static double
  _affineCoordinate(int const &j, double const &u,
                    double const &v); // affine coordinate lambdaj j=1..4
};

#endif
