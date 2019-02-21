
#include "HierarchicalBasisH1Tria.h"

HierarchicalBasisH1Tria::HierarchicalBasisH1Tria(int pb,int pe0,int pe1,int pe2):HierarchicalBasisH1(3,3,1,3,pe0+pe1+pe2-3,0,(pb-1)*(pb-2)/2){

  if( pb<3 ){
       throw std::string("pb  must be >=3");
  }
  if(pe0<2 || pe1<2 || pe2<2){
    throw std::string("pe must be >=2");
  }
   this->pb=pb;
   
   if( pe0>pb || pe2> pb || pe1>pb){

       throw std::string("pe0, pe1  and pe2  must be <=pb");
   }
   this->pOrderEdge[0]=pe0;
    this->pOrderEdge[1]=pe1;
    this->pOrderEdge[2]=pe2;

    
}



HierarchicalBasisH1Tria::~HierarchicalBasisH1Tria(){}

double HierarchicalBasisH1Tria:: affineCoordinate(int j, double u,double v ){
  switch(j){
  case(1):
    return 0.5*(1+v);
  case(2):
    return -0.5*(u+v);
  case(3):
    return 0.5*(1+u);
  default:
         throw std::string("j must be : 1<=j<=3");
       }
}


void  HierarchicalBasisH1Tria::generateBasis(  double  u, double  v, double* vertexBasis,double* edgeBasis, double* bubbleBasis,int sizeVertexBasis,int sizeEdgeBasis,int sizeBubbleBasis) {
   if (sizeVertexBasis!=this->nVertexFunction || sizeEdgeBasis!=this->nEdgeFunction || sizeBubbleBasis!=this->nBubbleFunction){
    throw std::string("wrong  size of the  vector in input");
    }
  //to map onto the reference domain of gmsh:
  u=2*u-1;
  v=2*v-1;  
  double lambda1=affineCoordinate(1,u,v);
  double lambda2=affineCoordinate(2,u,v);
  double lambda3=affineCoordinate(3,u,v);
  double product32=lambda2*lambda3;
  double subst32=lambda3-lambda2;
  double product13=lambda3*lambda1;
  double subst13=lambda1-lambda3;
  double product21=lambda2*lambda1;
  double subst21=lambda2-lambda1;
  double product=lambda1*lambda2*lambda3;
 
  std::vector<std::string> debugEdge(this->nEdgeFunction);
  
  std::vector<std::string> debugBubble(this->nBubbleFunction);
  
  //vertex shape functions:
  vertexBasis[0]=  lambda2;
  vertexBasis[1]=  lambda3;
  vertexBasis[2]=  lambda1;
  //edge 0  shape functions and a part of bubble functions :
   int iterator2=0;
  for(int k=0;k<=this->pOrderEdge[0]-2;k++){
    double kernel=OrthogonalPoly::EvalKernelFunction(k,subst32);
    double  phie0=product32*kernel;

    edgeBasis[k]=phie0;
    debugEdge[k]="phie0 "+ std::to_string(k);
    double product4=product*kernel;
    int iterator=0;

    while(iterator<=this->pb-3-k){
      int nbr=iterator2+iterator;
       bubbleBasis[nbr]=product4;
       debugBubble[nbr]="bulleu "+ std::to_string(k);
       iterator++;
    }
   
    iterator2=iterator2+this->pb-2-k;
   
  }
  for(int k=this->pOrderEdge[0]-1;k<=this->pb-3;k++){
    double kernel=OrthogonalPoly::EvalKernelFunction(k,subst32);
    double product4=product*kernel;
    int iterator=0;
    while(iterator<=this->pb-3-k){
      int nbr=iterator2+iterator;
       bubbleBasis[nbr]=product4;
       debugBubble[nbr]="bulleu "+ std::to_string(k);
       iterator++;
    }
   
    iterator2=iterator2+this->pb-2-k;
    }
  //edge 1 shape functions  :
    for(int k=0;k<=this->pOrderEdge[1]-2;k++){
      double kernel=OrthogonalPoly::EvalKernelFunction(k,subst13);
      double  phie1=product13*kernel;
      edgeBasis[this->pOrderEdge[0]+k-1]=phie1;
      debugEdge[this->pOrderEdge[0]+k-1]="phie1 "+ std::to_string(k);
    }
 //edge 2  shape functions and a part of bubble functions :
  for(int k=0;k<=this->pOrderEdge[2]-2;k++){
    double kernel=OrthogonalPoly::EvalKernelFunction(k,subst21);
    double  phie2=product21*kernel;

    edgeBasis[k+pOrderEdge[0]+pOrderEdge[1]-2]=phie2;
    debugEdge[k+pOrderEdge[0]+pOrderEdge[1]-2]="phie2 "+ std::to_string(k);
     int iterator2=k;
     int iterator=0;
     int iterator4=this->pb-2;
    while(iterator<=this->pb-3-k){
       bubbleBasis[iterator2]=bubbleBasis[iterator2]*kernel;
       debugBubble[iterator2]=debugBubble[iterator2]+"v "+ std::to_string(k);
       iterator2=iterator2+iterator4;
       iterator++;
       iterator4--;
    }
   
   
  }
   for(int k=this->pOrderEdge[2]-1;k<=this->pb-3;k++){
     double kernel=OrthogonalPoly::EvalKernelFunction(k,subst21);
     int iterator2=k;
     int iterator=0;
     int iterator4=this->pb-2;
    while(iterator<=this->pb-3-k){
       bubbleBasis[iterator2]=bubbleBasis[iterator2]*kernel;
       debugBubble[iterator2]=debugBubble[iterator2]+"v "+ std::to_string(k);
       iterator2=iterator2+iterator4;
       iterator++;
       iterator4--;
    }

    }
  //debug:
  for (int i =0; i<this->nEdgeFunction;i++){
    std::cout<<debugEdge[i]<<std::endl;
    std::cout<<edgeBasis[i]<<std::endl;

  }
 for (int i =0; i<this->nBubbleFunction;i++){
    std::cout<<debugBubble[i]<<std::endl;
    std::cout<<bubbleBasis[i]<<std::endl;
    }
}

/*

void  HierarchicalBasisH1Tria::generateGradientBasis( double u, double v,double* gradientU, double* gradientV,int size){
  int nTotalFunction= this->getnTotalFunction();
  if (size!=nTotalFunction ){
    throw std::string("bad  size  vectors gradientU , gradientV");
    }
  //to map onto the reference domain of gmsh:
  // *
  u=2*u-1;
  v=2*v-1;
  double jacob=0.5;// jacobian=((0.5,0),(0,0.5))
  //*
  double dlambda1U=0;
  double dlambda1V=0.5;
  double dlambda2U=-0.5;
  double dlambda2V=-0.5;
  double dlambda3U=0.5;
  double dlambda3V=0;
  double lambda1=affineCoordinate(1,u,v);
  double lambda2=affineCoordinate(2,u,v);
  double lambda3=affineCoordinate(3,u,v);
  double product32=lambda2*lambda3;
  double subst32=lambda3-lambda2;
  double product13=lambda3*lambda1;
  double subst13=lambda1-lambda3;
  double product21=lambda2*lambda1;
  double subst21=lambda2-lambda1;
  double product=lambda1*lambda2*lambda3;
  std::vector<std::string> debug(nTotalFunction);
  //vertex gradient functions:
  gradientU[0]=jacob* dlambda2U;
  gradientV[0]= jacob*dlambda2V;
  gradientU[1]=  jacob*dlambda3U;
  gradientV[1]=  jacob*dlambda3V;
  gradientU[2]= jacob*dlambda1U ;
  gradientV[2]= jacob*dlambda1V;
  double tablIntermU[this->nBubbleFunction];
  double tablIntermV[this->nBubbleFunction];
  debug[0]="v0";
  debug[1]="v1";
  debug[2]="v2";
  //edge 0  gradient  and a part of bubble functions gradient :
  int iterator2=this->nEdgeFunction+2;
  for(int k=0;k<=this->pOrderEdge[0]-2;k++){
    double kernel=OrthogonalPoly::EvalKernelFunction(k,subst32);
    double dKernel=OrthogonalPoly::EvalDKernelFunction(k,subst32);
    gradientU[k+3]= (gradientU[1]*lambda2+gradientU[0]*lambda3)*kernel+product32*(gradientU[1]-gradientU[0])*dKernel;
    gradientV[k+3]= (gradientV[1]*lambda2+gradientV[0]*lambda3)*kernel+product32*(gradientV[1]-gradientV[0])*dKernel;;
    debug[k+3]="phie0 "+ std::to_string(k);
    int iterator=0;
    while(iterator<=this->pb-3-k){  
      int nbr=iterator2+iterator+1;
      gradientU[nbr]=(gradientU[1]*product21+gradientU[0]*product13+gradientU[2]*product32)*kernel+product*(gradientU[1]-gradientU[0])*dKernel;
      gradientV[nbr]=(gradientV[1]*product21+gradientV[0]*product13+gradientV[2]*product32)*kernel+product*(gradientV[1]-gradientV[0])*dKernel;
      tablIntermU[k]=product*(gradientU[0]-gradientU[2])*kernel;
      tablIntermV[k]=product*(gradientV[0]-gradientV[2])*kernel;
      debug[nbr]="bulleu "+ std::to_string(k);
      iterator++;
    }
   
    iterator2=iterator2+this->pb-2-k;
   
  }
   for(int k=this->pOrderEdge[0]-1;k<=this->pb-3;k++){
     double kernel=OrthogonalPoly::EvalKernelFunction(k,subst32);
     double dKernel=OrthogonalPoly::EvalDKernelFunction(k,subst32);
     int iterator=0;
     while(iterator<=this->pb-3-k){
      int nbr=iterator2+iterator+1;
      gradientU[nbr]=(gradientU[1]*product21+gradientU[0]*product13+gradientU[2]*product32)*kernel+product*(gradientU[1]-gradientU[0])*dKernel;
      gradientV[nbr]=(gradientV[1]*product21+gradientV[0]*product13+gradientV[2]*product32)*kernel+product*(gradientV[1]-gradientV[0])*dKernel;
      tablIntermU[k]=product*(gradientU[0]-gradientU[2])*kernel;
      tablIntermV[k]=product*(gradientV[0]-gradientV[2])*kernel;
       debug[nbr]="bulleu "+ std::to_string(k);
       iterator++;
    }
   
    iterator2=iterator2+this->pb-2-k;
    }
  //edge 1 shape functions gradient  :
    for(int k=0;k<=this->pOrderEdge[1]-2;k++){
      double kernel=OrthogonalPoly::EvalKernelFunction(k,subst13);
      double dKernel=OrthogonalPoly::EvalDKernelFunction(k,subst13);
      gradientU[this->pOrderEdge[0]+k+2]=(lambda3*gradientU[2]+lambda2*gradientU[1])*kernel+product13*(gradientU[2]-gradientU[1])*dKernel;
      gradientV[this->pOrderEdge[0]+k+2]=(lambda3*gradientV[2]+lambda2*gradientV[1])*kernel+product13*(gradientV[2]-gradientV[1])*dKernel;
      debug[this->pOrderEdge[0]+k+2]="phie1 "+ std::to_string(k);
    }
 //edge 2  gradient  and a part of bubble functions gradient :
  for(int k=0;k<=this->pOrderEdge[2]-2;k++){
    double kernel=OrthogonalPoly::EvalKernelFunction(k,subst21);
    double dKernel=OrthogonalPoly::EvalDKernelFunction(k,subst21);
    gradientU[k+1+pOrderEdge[0]+pOrderEdge[1]]=(lambda2*gradientU[2]+lambda1*gradientU[0])*kernel+product21*(gradientU[0]-gradientU[2])*dKernel;
    gradientV[k+1+pOrderEdge[0]+pOrderEdge[1]]=(lambda2*gradientV[2]+lambda1*gradientV[0])*kernel+product21*(gradientV[0]-gradientV[2])*dKernel;
    debug[k+1+pOrderEdge[0]+pOrderEdge[1]]="phie2 "+ std::to_string(k);
    int iterator2=this->nEdgeFunction+3+k;
    int iterator=0;
    int iterator4=this->pb-2;
    while(iterator<=this->pb-3-k){
      int nbr=iterator2;
       gradientU[nbr]=gradientU[nbr]*kernel+tablIntermU[k]*dKernel;
       gradientV[nbr]=gradientV[nbr]*kernel+tablIntermV[k]*dKernel;
       debug[nbr]=debug[nbr]+"v "+ std::to_string(k);
       iterator2=iterator2+iterator4;
       iterator++;
      iterator4--;
    }
   
   
  }
   for(int k=this->pOrderEdge[2]-1;k<=this->pb-3;k++){
     double kernel=OrthogonalPoly::EvalKernelFunction(k,subst21);
     double dKernel=OrthogonalPoly::EvalDKernelFunction(k,subst21);
     int iterator2=this->nEdgeFunction+3+k;
     int iterator=0;
     int iterator4=this->pb-2;
    while(iterator<=this->pb-3-k){
      int nbr=iterator2;
       gradientU[nbr]=gradientU[nbr]*kernel+tablIntermU[k]*dKernel;
       gradientV[nbr]=gradientV[nbr]*kernel+tablIntermV[k]*dKernel;
       debug[nbr]=debug[nbr]+"v "+ std::to_string(k);
       iterator2=iterator2+iterator4;
       iterator++;
      iterator4--;
    }
 
   }
  //debug:
  for (int i =0; i<nTotalFunction;i++){
    std::cout<<debug[i]<<std::endl;
    std::cout<<gradientU[i]<<std::endl;
      std::cout<<gradientV[i]<<std::endl;
    }
		


 
}

void HierarchicalBasisH1Tria::edgeOrientation(int const& flagOrientation, int const& edgeNumber,double* HierarchicalBasis,double* gradientU, double* gradientV){
  if(flagOrientation== -1){   
      switch(edgeNumber){
       case(0):
	 {
	 int constant=this->pOrderEdge[0]-2;
         for(int k=0;k<=constant;k++){
	 if  HierarchicalBasis[k+3]= HierarchicalBasis[k+3]*(-1);
	   gradientU[k+3]=gradientU[k+3]*(-1);
	   gradientV[k+3]=gradientV[k+3]*(-1);
	 }
	 }
	 break;
	 case(1):
	   {
	  int constant1=this->pOrderEdge[1]-2;
	  for(int k=0;k<=constant1;k++){
	  if  HierarchicalBasis[this->pOrderEdge[0]+k+2]= HierarchicalBasis[this->pOrderEdge[0]+k+2]*(-1);
	   gradientU[this->pOrderEdge[0]+k+2]=gradientU[this->pOrderEdge[0]+k+2]*(-1);
	   gradientV[this->pOrderEdge[0]+k+2]=gradientV[this->pOrderEdge[0]+k+2]*(-1);
	 }
	   }
	  break;
        case(2):
	  {
	 int constant2=this->pOrderEdge[2]-2;
	 for(int k=0;k<=constant2;k++){
	   if  HierarchicalBasis[k+1+pOrderEdge[0]+pOrderEdge[1]]= HierarchicalBasis[k+1+pOrderEdge[0]+pOrderEdge[1]]*(-1);
	   gradientU[k+1+pOrderEdge[0]+pOrderEdge[1]]=gradientU[k+1+pOrderEdge[0]+pOrderEdge[1]]*(-1);
	   gradientV[k+1+pOrderEdge[0]+pOrderEdge[1]]=gradientV[k+1+pOrderEdge[0]+pOrderEdge[1]]*(-1);
	 }
	  }
	  break;

        default:
         throw std::string("edgeNumber  must be : 0<=edgeNumber<=2");
        }

    
  }




  }


   
*/
