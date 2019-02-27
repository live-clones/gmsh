

#include "HierarchicalBasisH1Line.h"

HierarchicalBasisH1Line:: HierarchicalBasisH1Line(int pb1){
  this->nvertex = 2;
  this->nedge = 0;
  this->nface = 0;
  this->nVertexFunction = 2;
  this->nEdgeFunction = 0;
  this->nFaceFunction = 0;
  this->nBubbleFunction = (pb1 - 1);
  this->pb1=pb1;
}



HierarchicalBasisH1Line::~HierarchicalBasisH1Line(){}


double HierarchicalBasisH1Line:: affineCoordinate(int j, double u){
  switch(j){
  case(1):
    return 0.5*(1+u);
  case(2):
    return 0.5*(1-u);
  default:
         throw std::string("j must be : 1<=j<=2");
       }
}

void HierarchicalBasisH1Line::generateBasis( double const &u, double const &v, double const &w,
                           double *vertexBasis, double *edgeBasis,
                           double *faceBasis, double *bubbleBasis){
  int uc=2*u-1;// for transformation [-1;1] -> [0,1]
  double lambda1=affineCoordinate(1,uc);
  double lambda2=affineCoordinate(2,uc);
  double product=lambda1*lambda2;
  double substraction=lambda1-lambda2;
  //vertex shape functions:
  vertexBasis[0]=  lambda2;
  vertexBasis[1]=  lambda1;
  //bubble functions :
  for(int k=2;k<=this->pb1;k++){
    bubbleBasis[k-2]=product*OrthogonalPoly::EvalKernelFunction(k-2,substraction);
  }
}


void HierarchicalBasisH1Line:: generateGradientBasis(double const &u, double const &v, double const &w,
                        double gradientVertex[][3], double gradientEdge[][3],
                        double gradientFace[][3], double gradientBubble[][3]){
  int uc=2*u-1;// for transformation [-1;1] -> [0,1]
  double dlambda1=0.5;
  double dlambda2=-0.5;
  double detJacob=this->getDetJacobian();
  //vertex gradient functions:
  gradientVertex[0][0]=  detJacob*dlambda2;
  gradientVertex[1][0]=detJacob*dlambda1;
  for(int k=2;k<=this->pb1;k++){
       gradientBubble[k-2][0]=OrthogonalPoly::EvalDLobatto(k,uc)*this->getDetJacobian();
  }

}

double HierarchicalBasisH1Line::getDetJacobian(){
  return 2;
}
