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
  HierarchicalBasisH1Line(int pb);
  virtual ~HierarchicalBasisH1Line();
  // vertexBasis=[v0,v1]
  // BubbleBasis=[phie_{2},...,phie_{pe}]
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

  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                             std::vector<double> &edgeBasis){};
  virtual void
  orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &gradientEdge){};

  virtual void orientateFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis){};

  virtual void
  orientateFaceGrad(double const &u, double const &v, double const &w,
                    int const &flag1, int const &flag2, int const &flag3,
                    int const &faceNumber,
                    std::vector<std::vector<double> > &gradientFace){};
  virtual void reverseFaceBubbleFor3D(const bool belongBoundary){};
  virtual void reverseEdgeBubbleFor2D(const bool belongBoundary);

private:
  int _pb; //  bubble function order in  direction u
  static double
  _affineCoordinate(int j,
                    double u); // affine coordinate lambdaj j={1,2}
  double _getDetJacobian(); // for transformation [-1;1] -> [0,1]
};

#endif
