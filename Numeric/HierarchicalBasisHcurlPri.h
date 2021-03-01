// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).
#ifndef HIERARCHICAL_BASIS_HCURL_PRI_H
#define HIERARCHICAL_BASIS_HCURL_PRI_H

#include "HierarchicalBasisHcurl.h"
#include <math.h>

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
 *  e0={0, 1}, e1={0, 2}, e2={0, 3}, e3={1, 2}, e4={1, 4},
 *  e5={2, 5}, e6={3, 4}, e7={3, 5}, e8={4, 5}
 *
 *
 * Oriented Surfaces:
 *  s3={0, 1, 2}, s4={3, 4, 5}, s0={0, 1, 3, 4}, s1={0, 2, 3,5}
 *  s2={1,2,4,5}
 * Local (directional) orders on mesh faces are not allowed to exceed the mini-
 * mum of the (appropriate directional) orders of approximation associated with
 * the interior of the adjacent elements. Local orders of approximation on mesh
 * edges are limited by the minimum of all (appropriate directional) orders cor-
 * responding to faces sharing that edge
 */
class HierarchicalBasisHcurlPri : public HierarchicalBasisHcurl {
public:
  HierarchicalBasisHcurlPri(int order);
  virtual ~HierarchicalBasisHcurlPri();
  virtual unsigned int getNumberOfOrientations() const;
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &vertexBasis,
                             std::vector<std::vector<double> > &edgeBasis,
                             std::vector<std::vector<double> > &faceBasis,
                             std::vector<std::vector<double> > &bubbleBasis,
                             std::string typeFunction)
  {
    if(typeFunction == "HcurlLegendre") {
      generateHcurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
    }
    else if("CurlHcurlLegendre" == typeFunction) {
      generateCurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
    }
    else {
      throw std::string("unknown typeFunction");
    }
  }

  virtual void
  orientEdge(int const &flagOrientation, int const &edgeNumber,
             std::vector<std::vector<double> > &edgeBasis,
             const std::vector<std::vector<double> > &eTablePositiveFlag,
             const std::vector<std::vector<double> > &eTableNegativeFlag);
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double> > &edgeFunctions);
  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &fTableCopy);

  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo);

private:
  int _pb1; // bubble function order in  direction uv
  int _pb2; // bubble function order in  direction w
  int _pOrderEdge[9]; // Edge functions order (pOrderEdge[0] matches the order
                      // of the edge 0)
  int _pOrderQuadFace1[3]; // Quad Face functions order in direction u
                           // (pOrderFace1[0] matches the order of face 0 in
                           // direction u)
  int _pOrderQuadFace2[3]; // Quad Face functions order in direction v
                           // (pOrderFace[0] matches the order of face 0 in
                           // direction v)
  int _pOrderTriFace[2]; // Tri Face Functions order
  static double
  _affineCoordinate(const int &j, const double &u, const double &v,
                    const double &w); // affine coordinate lambda j=1..5
  static double dotProduct(const std::vector<double> &u1,
                           const std::vector<double> &u2);
  // to take into account the mapping (product with jacobian)
  static void matrixVectorProductForMapping(
    const double &a, const std::vector<double> &u,
    std::vector<double> &result); // ((2,0,0),(0,2,0),(0,0,1))*u
  static void matrixVectorProductForCurlMapping(
    std::vector<double> &result); // det*((0.5,0,0),(0,0.5,0),(0,0,1))*result
  virtual void
  generateHcurlBasis(double const &u, double const &v, double const &w,
                     std::vector<std::vector<double> > &edgeBasis,
                     std::vector<std::vector<double> > &faceBasis,
                     std::vector<std::vector<double> > &bubbleBasis);

  virtual void
  generateCurlBasis(double const &u, double const &v, double const &w,
                    std::vector<std::vector<double> > &edgeBasis,
                    std::vector<std::vector<double> > &faceBasis,
                    std::vector<std::vector<double> > &bubbleBasis);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction);
};
#endif
