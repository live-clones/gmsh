// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_BRICK_H
#define HIERARCHICAL_BASIS_H1_BRICK_H

#include "HierarchicalBasisH1.h"

/*
 * MHexahedron
 *
 *          v
 *   3----------2
 *   |\     ^   |\
 *   | \    |   | \
 *   |  \   |   |  \
 *   |   7------+---6
 *   |   |  +-- |-- | -> u
 *   0---+---\--1   |
 *    \  |    \  \  |
 *     \ |     \  \ |
 *      \|      w  \|
 *       4----------5
 *
 *  Oriented Edges:
 * e0={0, 1}, e1={0, 3}, e2={0, 4}, e3={1, 2}, e4 ={1, 5}, e5={3, 2},e6={2, 6},
 * e7={3, 7},e8={4, 5}, e9= {4, 7}, e10={5, 6}, e11={7, 6}
 *
 * Oritented Surface:
 *  s0={0, 1, 3, 2}, s1={0, 1, 4, 5}, s2={0, 3, 4, 7},
 *  s3={1, 2, 5, 6}, s4={3,2,7,6}, s5={4, 5, 7, 6}
 * Local (directional) orders on mesh faces are not allowed to exceed the mini-
 * mum of the (appropriate directional) orders of approximation associated with
 * the interior of the adjacent elements. Local orders of approximation on mesh
 * edges are limited by the minimum of all (appropriate directional) orders cor-
 * responding to faces sharing that edge
 */
class HierarchicalBasisH1Brick : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Brick(int order);
  virtual ~HierarchicalBasisH1Brick();
  virtual unsigned int getNumberOfOrientations() const;
  // vertexBasis=[v0,...,v12]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis=[phif0_{2,2},...,phif0_{2,pF0_2},...,phif0_{pF0_1,2},...,phief0_{pF0_1,pF0_2},phif1_{2,2}...}]
  // bubbleBasis=[phieb_{2,2,2},...,phieb_{2,,2,pb3},phieb_{2,3,2},...,phieb_{2,3,pe3},...}]
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis);
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &vertexBasis,
                             std::vector<std::vector<double> > &edgeBasis,
                             std::vector<std::vector<double> > &faceBasis,
                             std::vector<std::vector<double> > &bubbleBasis,
                             std::string typeFunction = "GradH1Legendre")
  {
    generateGradientBasis(u, v, w, vertexBasis, edgeBasis, faceBasis,
                          bubbleBasis);
  }

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeFunctions,
                          const std::vector<double> &eTablePositiveFlag,
                          const std::vector<double> &eTableNegativeFlag);
  virtual void
  orientEdge(int const &flagOrientation, int const &edgeNumber,
             std::vector<std::vector<double> > &edgeBasis,
             const std::vector<std::vector<double> > &eTablePositiveFlag,
             const std::vector<std::vector<double> > &eTableNegativeFlag);

  virtual void
  orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions);
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double> > &edgeFunctions);

  virtual void
  orientFace(int const &flag1, int const &flag2, int const &flag3,
             int const &faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientation,
             const std::vector<double> &triFaceFunctionsAllOrientation,
             std::vector<double> &fTableCopy);

  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &fTableCopy);
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo);

private:
  int _pb1; // bubble function order in  direction u
  int _pb2; // bubble function order in  direction v
  int _pb3; // bubble function order in  direction w
  int _pOrderEdge[12]; // Edge functions order (pOrderEdge[0] matches the order
                       // of the edge 0)
  int _pOrderFace1[6]; // Face functions order in direction u  (pOrderFace1[0]
                       // matches the order of face 0 in direction u)
  int _pOrderFace2[6]; // Face functions order in direction v (pOrderFace[0]
                       // matches the order of face 0 in direction v)
  static double
  _affineCoordinate(const int &j, const double &u, const double &v,
                    const double &w); // affine coordinate lambdaj j=1..6
  inline void _someProduct(double const &u, double const &v, double const &w,
                           std::vector<double> &product,
                           std::vector<double> &lambda); // compute some product
  inline void
  _someProductGrad(double const &u, double const &v, double const &w,
                   std::vector<double> &product,
                   std::vector<std::vector<double> > &gradientProduct,
                   std::vector<double> &lambda,
                   std::vector<std::vector<double> >
                     &gradientLambda); // compute some product and fill the
                                       // vector gradientVertex
  void generateGradientBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &gradientVertex,
                             std::vector<std::vector<double> > &gradientEdge,
                             std::vector<std::vector<double> > &gradientFace,
                             std::vector<std::vector<double> > &gradientBubble);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction = "GradH1Legendre");
};
#endif
