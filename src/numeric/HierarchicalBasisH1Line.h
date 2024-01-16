// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_LINE_H
#define HIERARCHICAL_BASIS_H1_LINE_H

#include "HierarchicalBasisH1.h"
/*
 *
 *
 *
 *          |
 *   0      |     1
 * --+------+-----+---> u
 *
 *
 *
 *
 *
 *
 *
 */
class HierarchicalBasisH1Line : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Line(int pe);
  virtual ~HierarchicalBasisH1Line();
  virtual unsigned int getNumberOfOrientations() const;
  // vertexBasis=[v0,v1]
  // edgeBasis=[phie_{2},...,phie_{pe}]
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
             std::vector<double> &fTableCopy){};
  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &fTableCopy){};

  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo);

private:
  int _pe; //  edge function order in  direction u
  static double
  _affineCoordinate(int j,
                    double u); // affine coordinate lambdaj j={1,2}
  void generateGradientBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &gradientVertex,
                             std::vector<std::vector<double> > &gradientEdge,
                             std::vector<std::vector<double> > &gradientFace,
                             std::vector<std::vector<double> > &gradientBubble);
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis){};
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction = "GradH1Legendre"){};
};

#endif
