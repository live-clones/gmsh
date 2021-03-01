// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_HCURL_QUAD_H
#define HIERARCHICAL_BASIS_HCURL_QUAD_H

#include "HierarchicalBasisHcurl.h"

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
class HierarchicalBasisHcurlQuad : public HierarchicalBasisHcurl {
public:
  HierarchicalBasisHcurlQuad(int order);
  virtual ~HierarchicalBasisHcurlQuad();
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
  };
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
  int _pf1; // face function order in  direction u
  int _pf2; // face function order in  direction v
  int _pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0
                      // order)
  static double
  _affineCoordinate(int const &j, double const &u,
                    double const &v); // affine coordinate lambdaj j=1..4
  // edgeBasis=[phie0_{0},...phie0_{pe0},phie1_{0},...phie1_{pe1}...]
  // faceBasis=[phieFf1{n1,n2} (with 0<=n1<=pf1 , 2<=n2<=pf2+1), phieFf2{n1,n2}
  // (with 2<=n1<=pf1+1 , 0<=n2<=pf2) ]
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
