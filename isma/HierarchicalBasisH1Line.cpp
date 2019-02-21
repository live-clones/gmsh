

#include "HierarchicalBasisH1Line.h"

HierarchicalBasisH1Line:: HierarchicalBasisH1Line(int pb1):HierarchicalBasisH1(2,0,0,2,0,0,(pb1-1)){
  if(pb1<2){

   throw std::string("pb must be >=2");
  }
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


void HierarchicalBasisH1Line::generateBasis( double u,double* vertexBasis,double* bubbleBasis,int sizeVertexBasis, int sizeBubbleBasis){
  u=2*u-1;// for transformation [-1;1] -> [0,1]
  if (sizeVertexBasis!=this->nVertexFunction || sizeBubbleBasis!=this->nBubbleFunction){
    throw std::string("wrong  size of the  vector in input");
  }
  double lambda1=affineCoordinate(1,u);
  double lambda2=affineCoordinate(2,u);
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


void HierarchicalBasisH1Line:: generateGradientBasis( double u,double* vertexGradientU, double *bubbleGradientU ,int sizeVertexBasis, int sizeBubbleBasis){
 u=2*u-1;// for transformation [-1;1] -> [0,1]
 if (sizeVertexBasis!=this->nVertexFunction || sizeBubbleBasis!=this->nBubbleFunction){
    throw std::string("wrong  size of the  vector in input");
  }
  double dlambda1=0.5;
  double dlambda2=-0.5;
  double lambda1=affineCoordinate(1,u);
  double lambda2=affineCoordinate(2,u);
  double detJacob=this->getDetJacobian();

  //vertex gradient functions:
  vertexGradientU[0]=  detJacob*dlambda2;
  vertexGradientU[1]=detJacob*dlambda1;
  double product=lambda1*lambda2;
  double substraction=lambda1-lambda2;
  for(int k=2;k<=this->pb1;k++){
     bubbleGradientU[k-2]=(-0.5*substraction*OrthogonalPoly::EvalKernelFunction(k-2,substraction)+product*OrthogonalPoly::EvalDKernelFunction(k-2,substraction))*detJacob;
  }



}

double HierarchicalBasisH1Line::getDetJacobian(){
  return 0.5;
}
