#ifndef _HierarchicalBasisH1Line_H_
#define _HierarchicalBasisH1Line_H_

#include "HierarchicalBasisH1.h"
#include <algorithm>

#include <vector>
/*
 *
 *
 *
 *
 *   0          +1
 * --+-----------+---> u
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
  HierarchicalBasisH1Line(int pb1);
  virtual ~HierarchicalBasisH1Line();
  // vertexBasis=[v0,v1]
  // bubbleBasis=[phieb_{2},...,phieb_{pb}]
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             double *vertexBasis, double *edgeBasis,
                             double *faceBasis, double *bubbleBasis);
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        double gradientVertex[][3], double gradientEdge[][3],
                        double gradientFace[][3], double gradientBubble[][3]);

  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                             double *edgeBasis){};
  virtual void orientateEdgeGrad(int const &flagOrientation,
                                 int const &edgeNumber,
                                 double gradientEdge[][3]){};

private:
  int pb1; // bubble function order in  direction u
  static double affineCoordinate(int j,
                                 double u); // affine coordinate lambdaj j={1,2}
  double getDetJacobian(); // for transformation [-1;1] -> [0,1]
};

#endif
