#ifndef _HierarchicalBasisH1_H_
#define _HierarchicalBasisH1_H_

#include "OrthogonalPoly.h"
#include "vector"
class HierarchicalBasisH1 {
protected:
  int _nvertex;
  int _nedge;
  int _nface;
  int _nVertexFunction;
  int _nEdgeFunction;
  int _nFaceFunction;
  int _nBubbleFunction;

public:
  virtual ~HierarchicalBasisH1() = 0;
  int getnVertexFunction() const;
  int getnEdgeFunction() const;
  int getnFaceFunction() const;
  int getnBubbleFunction() const;
  int getNumFace() const;
  int getNumEdge() const;
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis) = 0;
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        std::vector<std::vector<double> > &gradientVertex,
                        std::vector<std::vector<double> > &gradientEdge,
                        std::vector<std::vector<double> > &gradientFace,
                        std::vector<std::vector<double> > &gradientBubble) = 0;
  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                             std::vector<double> &edgeBasis) = 0;
  virtual void
  orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &gradientEdge) = 0;

  virtual void orientateFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis) = 0;

  virtual void
  orientateFaceGrad(double const &u, double const &v, double const &w,
                    int const &flag1, int const &flag2, int const &flag3,
                    int const &faceNumber,
                    std::vector<std::vector<double> > &gradientFace) = 0;
  virtual void reverseFaceBubbleFor3D(const bool belongBoundary) = 0;
  virtual void reverseEdgeBubbleFor2D(const bool belongBoundary) = 0;
};

#endif
