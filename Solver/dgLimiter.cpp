#include "dgLimiter.h" 
#include "dgGroupOfElements.h"   
#include "dgSystemOfEquations.h" 
#include "function.h"

//----------------------------------------------------------------------------------   
int dgSlopeLimiter::apply ( dgDofContainer *solution)
{    
  dgGroupCollection *groups=solution->getGroups();
  solution->scatter();
  int nbFields =_claw->getNbFields();    
	
  // first compute max and min of all fields for all stencils    
  //----------------------------------------------------------   
  dgDofContainer MIN(groups, nbFields);
  dgDofContainer MAX(groups, nbFields);

  MIN.setAll ( 1.e22);  
  MAX.setAll (-1.e22);  

  int iElementL, iElementR, fSize; 	 
  fullMatrix<double> TempL, TempR;
  for( int iGFace=0; iGFace<groups->getNbFaceGroups(); iGFace++) {
    dgGroupOfFaces* group = groups->getFaceGroup(iGFace);  
    const dgGroupOfElements *groupLeft = &group->getGroupLeft();
    const dgGroupOfElements *groupRight = &group->getGroupRight();

    fullMatrix<double> &solleft = solution->getGroupProxy(groupLeft);
    fullMatrix<double> &solright = solution->getGroupProxy(groupRight); 
    fullMatrix<double> &MINLeft = MIN.getGroupProxy(groupLeft);
    fullMatrix<double> &MAXLeft = MAX.getGroupProxy(groupLeft);
    fullMatrix<double> &MINRight = MIN.getGroupProxy(groupRight);
    fullMatrix<double> &MAXRight = MAX.getGroupProxy(groupRight);

    for(int iFace=0 ; iFace<group->getNbElements();iFace++)   {

      iElementL = group->getElementLeftId(iFace);  
      iElementR = group->getElementRightId(iFace); 

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
        MINLeft ( iElementL , k ) = std::min ( AVGR , MINLeft ( iElementL , k ) );  
        MAXLeft ( iElementL , k ) = std::max ( AVGR , MAXLeft ( iElementL , k ) );  
        MINRight ( iElementR , k ) = std::min ( AVGL , MINRight ( iElementR , k ) );  
        MAXRight ( iElementR , k ) = std::max ( AVGL , MAXRight ( iElementR , k ) );  
      }    
    }
  }

   //----------------------------------------------------------   
  // then limit the solution  
  //----------------------------------------------------------   

  for (int iGroup=0 ; iGroup<groups->getNbElementGroups() ; iGroup++) {
    dgGroupOfElements &group = *groups->getElementGroup(iGroup);
    fullMatrix<double> &sol = solution->getGroupProxy(iGroup);
    fullMatrix<double> &MAXG = MAX.getGroupProxy(iGroup);
    fullMatrix<double> &MING = MIN.getGroupProxy(iGroup);
    fullMatrix<double> Temp;  
    for (int iElement=0 ; iElement<group.getNbElements() ; ++iElement)  { 
      Temp.setAsProxy(sol, nbFields*iElement, nbFields );    	
      for (int k=0; k<nbFields; ++k) 
      {
        double AVG = 0.;   
        double locMax = -1.e22; 
        double locMin =  1.e22; 
        double neighMax = MAXG (iElement,k);    
        double neighMin = MING (iElement,k);    
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
  }
  //  --- CLIPPING: check unphysical values
  for (int iG = 0; iG < groups->getNbElementGroups(); iG++){
    dgGroupOfElements* egroup = groups->getElementGroup(iG);  
    fullMatrix<double> &solGroup = solution->getGroupProxy(iG);

    dataCacheMap cacheMap(egroup->getNbNodes());//nbdofs for each element
    dataCacheDouble &solutionE = cacheMap.provideData("Solution");
    dataCacheElement &cacheElement = cacheMap.getElement();
    dataCacheDouble *solutionEClipped = _claw->newClipToPhysics(cacheMap);
    if (solutionEClipped){
      for (int iElement=0 ; iElement<egroup->getNbElements() ;++iElement) {
        solutionE.setAsProxy(solGroup, iElement*nbFields, nbFields );
        solutionE.set((*solutionEClipped)());    
      }
    }
  }  
  return 1; 
}

#include "Bindings.h"

void dgLimiter::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgLimiter>("dgLimiter");
  cb->setDescription("Parent class for limiters");
  methodBinding *cm;
  cm = cb->addMethod("apply",&dgLimiter::apply);
  cm->setArgNames("solution",NULL);
  cm->setDescription("apply the limiter on the solution");
}

void dgSlopeLimiter::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgSlopeLimiter>("dgSlopeLimiter");
  cb->setDescription("The usual DG slope limiter: keep the mean, reduces uniformly the slope until it does not overshoot the neighbors' mean");
  methodBinding *cm;
  cm = cb->setConstructor<dgSlopeLimiter,dgConservationLaw *>();
  cm->setDescription("A new explicit slope limiter");
  cm->setArgNames("law",NULL);
  cb->setParentClass<dgLimiter>();
}

