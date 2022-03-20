// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_HDIV_QUAD_H
#define HIERARCHICAL_BASIS_HDIV_QUAD_H

#include "HierarchicalBasisHdiv.h"

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
class HierarchicalBasisHdivQuad : public HierarchicalBasisHdiv {
public:
  HierarchicalBasisHdivQuad(int order);
  virtual ~HierarchicalBasisHdivQuad();
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
  int _pf1; // face function order in  direction u
  int _pf2; // face function order in  direction v
  int _pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0
                      // order)
  static double
  _affineCoordinate(const int &j, const double &u, const double &v); // affine coordinate lambdaj j=1..6

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
