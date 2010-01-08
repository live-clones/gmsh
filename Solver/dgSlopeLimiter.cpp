#include "dgLimiter.h" 
#include "dgGroupOfElements.h"   
#include "dgSystemOfEquations.h" 
#include "function.h"

//----------------------------------------------------------------------------------   
bool dgSlopeLimiter::apply ( dgDofContainer &solution,   
			     std::vector<dgGroupOfElements*> &eGroups,   
			     std::vector<dgGroupOfFaces*> &fGroups) 
{    

  //WARNING: ONLY FOR 1 GROUP OF FACES 
  //TODO: make this more general   

  dgGroupOfFaces* group = fGroups[0];   
  fullMatrix<double> &solleft = solution.getGroupProxy(0); //*(solution._dataProxys[0]);
  fullMatrix<double> &solright = solution.getGroupProxy(0); //*(solution._dataProxys[0]);
  int nbFields =_claw->nbFields();    
  int totNbElems = solution.getNbElements();

  // first compute max and min of all fields for all stencils    
  //----------------------------------------------------------   

  fullMatrix<double> MIN (totNbElems,nbFields );  
  fullMatrix<double>  MAX (totNbElems, nbFields); 
  MIN.setAll ( 1.e22);  
  MAX.setAll (-1.e22);  

  int iElementL, iElementR, fSize; 	 
  for(int iFace=0 ; iFace<group->getNbElements();iFace++)   {

    iElementL = group->getElementLeftId(iFace);  
    iElementR = group->getElementRightId(iFace); 

    fullMatrix<double> TempL, TempR;
    TempL.setAsProxy(solleft, nbFields*iElementL, nbFields );
    TempR.setAsProxy(solright, nbFields*iElementR, nbFields );    	
    
    fSize = TempL.size1(); 
    for (int k=0; k< nbFields; ++k){    
      double AVGL = 0;  
      double AVGR = 0;  
      for (int i=0; i<fSize; ++i) {  
	AVGL += TempL(i,k);  
	AVGR += TempR(i,k);  
      }  
      AVGL /= (double) fSize;
      AVGR /= (double) fSize;
      MIN ( iElementL , k ) = std::min ( AVGR , MIN ( iElementL , k ) );  
      MAX ( iElementL , k ) = std::max ( AVGR , MAX ( iElementL , k ) );  
      MIN ( iElementR , k ) = std::min ( AVGL , MIN ( iElementR , k ) );  
      MAX ( iElementR , k ) = std::max ( AVGL , MAX ( iElementR , k ) );  
    }    
  }

   //----------------------------------------------------------   
  // then limit the solution  
  //----------------------------------------------------------   

  for (int iElement=0 ; iElement<totNbElems; ++iElement)  { 
    fullMatrix<double> Temp;  
    Temp.setAsProxy(solleft, nbFields*iElement, nbFields );    	
    for (int k=0; k<nbFields; ++k) 
    {
      double AVG = 0.;   
      double locMax = -1.e22; 
      double locMin =  1.e22; 
      double neighMax = MAX (iElement,k);    
      double neighMin = MIN (iElement,k);    
      for (int i=0; i<fSize; ++i)  
      {
        AVG += Temp(i,k);   
        locMax = std::max (locMax, Temp (i,k)); 
        locMin = std::min (locMin, Temp (i,k)); 
      }	
      AVG /= (double) fSize;  

      //SLOPE LIMITING DG
      //-------------------  
      for (int i=0; i<fSize; ++i)Temp(i,k) -= AVG;

      double slopeLimiterValue = 1.0;   
      if (locMax != AVG && locMax > neighMax) slopeLimiterValue = (neighMax-AVG) / (locMax-AVG);    
      if (locMin != AVG && locMin < neighMin) slopeLimiterValue = std::min ( slopeLimiterValue , (AVG-neighMin) / (AVG-locMin) ); 
      if (AVG < neighMin) slopeLimiterValue = 0;  
      if (AVG > neighMax) slopeLimiterValue = 0;  
      
      //      if (slopeLimiterValue != 1.0)	printf("LIMTING %g\n",slopeLimiterValue);
      //      slopeLimiterValue = 0.0;   

      for (int i=0; i<fSize; ++i) Temp(i,k) = AVG + Temp(i,k)*slopeLimiterValue;

    }
  }  

  //  --- CLIPPING: check unphysical values
 //  fullMatrix<double> solutionQP (group->getNbIntegrationPoints(),group->getNbElements() * nbFields);
//   group->getCollocationMatrix().mult(solleft, solutionQP);
//   //dataCacheDouble &solutionQPe = cacheMap.provideData("Solution");
//   //solutionQPe.set(fullMatrix<double>(group.getNbIntegrationPoints(),nbFields));
//   //dataCacheElement &cacheElement = cacheMap.getElement();
//   dataCacheMap cacheMap(group->getNbIntegrationPoints());
//   dataCacheDouble *clipping = _claw->newClipToPhysics(cacheMap);
//   fullMatrix<double> clippedSol;
//    for (int iElement=0 ; iElement<group->getNbElements() ;++iElement) {
//      clippedSol.setAsProxy(solutionQP, iElement*nbFields, nbFields );
//      for (int iPt =0; iPt< group->getNbIntegrationPoints(); iPt++) {
//        for (int k=0;k<nbFields;k++)
// 	 clippedSol(iPt,k) =  (*clipping)(iPt,k);
//      }
//      //cacheElement.set(group.getElement(iElement));
//    }
//    solleft.gemm(group->getRedistributionMatrix(),solutionQP);

  //#if 0
//   double rhomin = 1.e-3;
//   double presmin= 1.e-3;
//   for (int iElement=0;iElement<totNbElems;iElement++){
//     fullMatrix<double> solElem;
//     solElem.setAsProxy(solleft, nbFields*iElement, nbFields );   
//     for (int k=0;k< solElem.size1() ;k++){
//        if (solElem(k,0) < rhomin) {
//  	solElem(k,0) = rhomin;
//        }
//        double rhoV2 = 0;
//        for (int j=0;j<2;j++) {
// 	 double rhov = solElem(k,j+1);
// 	 rhoV2 += rhov*rhov;
//        }
//        rhoV2 /= solElem(k,0);
//        const double p = (1.4-1)*solElem(k,3) - 0.5*(1.4-1)* rhoV2;
//        if (p < presmin) {
// 	 solElem(k,3) = 0.5 *rhoV2 + presmin / (1.4-1);
//        }
//      }
//   }
  //#endif

  return true; 

}

