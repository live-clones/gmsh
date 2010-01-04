#include "dgLimiter.h" 
#include "dgGroupOfElements.h"   
#include "dgSystemOfEquations.h" 


//----------------------------------------------------------------------------------   
bool dgSlopeLimiter::apply ( dgDofContainer &solution,   
			     std::vector<dgGroupOfElements*> &eGroups,   
			     std::vector<dgGroupOfFaces*> &fGroups) 
{    

  //WARNING: ONLY FOR 1 GROUP OF FACES 
  //TODO: make this more general   
  dgGroupOfFaces* group = fGroups[0];   
  fullMatrix<double> &SolLeft = *(solution._dataProxys[0]);
  fullMatrix<double> &SolRight = *(solution._dataProxys[0]);    
  int nbFields = solution.getNbFields();    
  int totNbElems = solution.getNbElements();

  // first compute max and min of all fields for all stencils    
  //----------------------------------------------------------   

  fullMatrix<double> MIN (totNbElems,nbFields );  
  fullMatrix<double>  MAX (totNbElems, nbFields); 
  MIN.setAll ( 1.e22);  
  MAX.setAll (-1.e22);  

  fullMatrix<double>  MEANL (totNbElems, nbFields);    
  fullMatrix<double>  MEANR (totNbElems, nbFields);    
  MEANL.setAll ( 0.01); 
  MEANR.setAll ( 0.01); 

  int iElementL, iElementR, fSize; 	 
  for(int iFace=0 ; iFace<group->getNbElements();iFace++)  
  {
    iElementL = group->getElementLeftId(iFace);  
    iElementR = group->getElementRightId(iFace); 
    if (iElementR >= 0)
    {   
      fullMatrix<double> TempL, TempR;
      TempL.setAsProxy(SolLeft, nbFields*iElementL, nbFields );
      TempR.setAsProxy(SolRight, nbFields*iElementR, nbFields );    	

      fSize = TempL.size1(); 
      for (int k=0; k< nbFields; ++k)    
      {    
        double AVGL = 0;  
        double AVGR = 0;  
        for (int i=0; i<fSize; ++i) 
        {  
          AVGL += TempL(i,k);  
          AVGR += TempR(i,k);  
        }  
        AVGL /= (double) fSize;
        AVGR /= (double) fSize;
        MIN ( iElementL , k ) = std::min ( AVGR , MIN ( iElementL , k ) );  
        MAX ( iElementL , k ) = std::max ( AVGR , MAX ( iElementL , k ) );  
        MIN ( iElementR , k ) = std::min ( AVGL , MIN ( iElementR , k ) );  
        MAX ( iElementR , k ) = std::max ( AVGL , MAX ( iElementR , k ) );  

        MEANR( iElementL,k ) = AVGR;
        MEANL( iElementR,k ) = AVGL;

      }    
    }   
    else{    
      fullMatrix<double> TempL ;  
      TempL.setAsProxy(SolLeft, nbFields*iElementL, nbFields );  
      for (int k=0; k<nbFields; ++k){   
        for (int i=0; i<fSize; ++i){    
          MIN ( iElementL , k ) = std::min (  TempL(i,k) , MIN ( iElementL , k ) );  
          MAX ( iElementL , k ) = std::max (  TempL(i,k) , MAX ( iElementL , k ) );  


          double AVG = 0;
          for (int i=0; i<fSize; ++i)  AVG += TempL(i,k);   

        } 
      }   
    }   
  }
  // some parallel should be done here in order to compute averages on other processors   
  //----------------------------------------------------------   

  //...   

  // then limit the solution  
  //----------------------------------------------------------   

  for (int iElement=0 ; iElement<totNbElems; ++iElement) 
  { 
    fullMatrix<double> Temp;  
    Temp.setAsProxy(SolRight, nbFields*iElement, nbFields );    	
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

      for (int i=0; i<fSize; ++i) Temp(i,k) *= slopeLimiterValue;

      for (int i=0; i<fSize; ++i) Temp(i,k) += AVG;    

    }
  }  
  return true; 

}
