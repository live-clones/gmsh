// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_HDIV_TETRA_H
#define HIERARCHICAL_BASIS_HDIV_TETRA_H

#include "HierarchicalBasisHdiv.h"
#include <math.h>

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
 * e0={0, 1}, e1={1, 2}, e2={2, 0}, e3={0, 3}, e4={2, 3}, e5={1, 3}
 *
 *
 * Oritented Surface:
 *  s0={0, 1, 2}, s1={0, 1, 3}, s2={0, 2, 3}, s3={1, 2, 3}
 * Local (directional) orders on mesh faces are not allowed to exceed the mini-
 * mum of the (appropriate directional) orders of approximation associated with
 * the interior of the adjacent elements. Local orders of approximation on mesh
 * edges are limited by the minimum of all (appropriate directional) orders cor-
 * responding to faces sharing that edge
 */
class HierarchicalBasisHdivTetra : public HierarchicalBasisHdiv {
public:
  HierarchicalBasisHdivTetra(int order);
  virtual ~HierarchicalBasisHdivTetra();
  virtual unsigned int getNumberOfOrientations() const;
  
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector< double > &vertexBasis,
                             std::vector< double > &edgeBasis,
                             std::vector< double > &faceBasis,
                             std::vector< double > &bubbleBasis)
  {
    generateDivBasis(u, v, w, faceBasis, bubbleBasis);
  };
  
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &vertexBasis,
                             std::vector<std::vector<double> > &edgeBasis,
                             std::vector<std::vector<double> > &faceBasis,
                             std::vector<std::vector<double> > &bubbleBasis,
                             std::string typeFunction)
  {
    if(typeFunction == "HdivLegendre") {
      generateHdivBasis(u, v, w, faceBasis, bubbleBasis);
    }
    else {
      throw std::string("unknown typeFunction");
    }
  };
  virtual void  orientFace(int const &flag1, int const &flag2, int const &flag3,
             int const &faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientations,
             const std::vector<double> &triFaceFunctionsAllOrientations,
             std::vector<double> &fTableCopy);
  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &fTableCopy);
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo);
                           
private:
  int _pb; // bubble function order
  int _pOrderEdge[6]; // Edge functions order (pOrderEdge[0] matches the order
                      // of the edge 0)
  int _pOrderFace[4]; // Face functions order in direction
  
  static double
  _affineCoordinate(const int &j, const double &u, const double &v,
                    const double &w); // affine coordinate lambdaj j=1..6

  virtual void
  generateHdivBasis(double const &u, double const &v, double const &w,
                     std::vector<std::vector<double> > &faceBasis,
                     std::vector<std::vector<double> > &bubbleBasis);
  virtual void
  generateDivBasis(double const &u, double const &v, double const &w,
                    std::vector< double > &faceBasis,
                    std::vector< double > &bubbleBasis);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector< double > &faceFunctions);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction);
};

#endif
