#ifndef _HierarchicalBasisH1_H_
#define _HierarchicalBasisH1_H_

// Hierarchical Basis of the master Element
#include "OrthogonalPoly.h"
#include "vector"
class HierarchicalBasisH1 {
protected:
  int nvertex;
  int nedge;
  int nface;
  int nVertexFunction;
  int nEdgeFunction;
  int nFaceFunction;
  int nBubbleFunction;

public:
  virtual ~HierarchicalBasisH1()=0;
  int getnVertexFunction() const;
  int getnEdgeFunction() const;
  int getnFaceFunction() const;
  int getnBubbleFunction() const;
  virtual void generateBasis(double const &u, double const & v, double const & w,double *vertexBasis,double *edgeBasis, double*faceBasis,double *bubbleBasis)=0;
  virtual void generateGradientBasis( double const & u,double const & v, double const & w,double gradientVertex[][3],  double gradientEdge[][3], double gradientFace[][3], double gradientBubble[][3])=0;
  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber, double *edgeBasis)=0;
  virtual void orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,double gradientEdge[][3])=0;
};

#endif
