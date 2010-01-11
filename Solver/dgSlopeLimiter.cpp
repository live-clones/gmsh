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
  fullMatrix<double> &solleft = solution.getGroupProxy(0);
  fullMatrix<double> &solright = solution.getGroupProxy(0); 
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
  for (int iG = 0; iG < eGroups.size(); iG++){
    dgGroupOfElements* egroup = eGroups[iG];  
    fullMatrix<double> &solGroup = solution.getGroupProxy(iG);

    dataCacheMap cacheMap(egroup->getNbNodes());//nbdofs for each element
    dataCacheDouble &solutionE = cacheMap.provideData("Solution");
    dataCacheElement &cacheElement = cacheMap.getElement();
    dataCacheDouble *solutionEClipped = _claw->newClipToPhysics(cacheMap);
    if (solutionEClipped){
      for (int iElement=0 ; iElement<egroup->getNbElements() ;++iElement) {
	solutionE.setAsProxy(solGroup, iElement*nbFields, nbFields );
	solutionE.set((*solutionEClipped)());    
       }
      delete solutionEClipped;
    }
  }  
  return true; 
  
}

