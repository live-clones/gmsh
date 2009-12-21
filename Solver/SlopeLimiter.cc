#include "dgLimiter.h"
#include "dgGroupOfElements.h"
#include "dgSystemOfEquations.h"
#include "dgConservationLaw.h"


// //----------------------------------------------------------------------------------
// bool SlopeLimiter::apply ( dgDofContainer &solution ,  
// 			   std::vector<dgGroupOfElements*> &eGroups, 
// 			   std::vector<dgGroupOfFaces*> &fGroups)
// {

//   const DGIntMatrix &topo = domain->getFaceToRegion();
//   const int fSize = solution->FunctionSpaceSize();
//   const ClosedFunctionSpace* fsC = DGModelDataManager::instance().getFunctionSpace(problemName,0);

// //   //--- Correct unphysical values 
// //   double Amin = 1.e-5;
// //   for (int iE=0;iE<solution->getNbElements();iE++){
// //     fullMatrix soljElem = solution->touchElementCoefs(iE);
// //     for (int k=0;k< soljElem.size1() ;k++){
// //       if (soljElem(k,0) < Amin)  soljElem(k,0) = Amin;
// //     }
// //   }

//   //WARNING FOR ONLY 1 GROUP OF FACES

//   // first compute max and min of all fields for all stencils
//   //----------------------------------------------------------
//   fullMatrix MIN (solution->getNbElements(), solution->getNbFields());
//   fullMatrix MAX (solution->getNbElements(), solution->getNbFields());  
//   MIN.set_all ( 1.e22);
//   MAX.set_all (-1.e22);

//   fullMatrix MEANL (solution->getNbElements(), solution->getNbFields());
//   fullMatrix MEANR (solution->getNbElements(), solution->getNbFields());  
//   MEANL.set_all ( 0.01);
//   MEANR.set_all ( 0.01);

//   dgGroupOfElements* group = fGroups[0];
//   for(int iFace=0 ; iFace<group->getNbElements();iFace++)
//     {
//       const int iElementL = group->getElementLeft(iFace);
//       const int iElementR = group->getElementRight(iFace);
//       if (iElementR >= 0)
// 	{
// 	  const fullMatrix TempR = fullMatrix(solution->seeElementCoefs (iElementR));
// 	  const fullMatrix TempL = fullMatrix(solution->seeElementCoefs (iElementL));
// 	  for (int k=0; k<nbFields; ++k)
// 	    {
// 	      double AVGL = 0;
// 	      double AVGR = 0;
// 	      for (int i=0; i<fSize; ++i)
// 		{
// 		  AVGL += TempL(i,k);
// 		  AVGR += TempR(i,k);
// 		}
// 	      AVGL /= (double) fSize;
// 	      AVGR /= (double) fSize;
// 	      MIN ( iElementL , k ) = std::min ( AVGR , MIN ( iElementL , k ) );
// 	      MAX ( iElementL , k ) = std::max ( AVGR , MAX ( iElementL , k ) );
// 	      MIN ( iElementR , k ) = std::min ( AVGL , MIN ( iElementR , k ) );
// 	      MAX ( iElementR , k ) = std::max ( AVGL , MAX ( iElementR , k ) );
	      
// 	      MEANR( iElementL,k ) = AVGR;
// 	      MEANL( iElementR,k ) = AVGL;
	      
// 	    }
// 	}
//       else{
// 	const fullMatrix TempL = fullMatrix(solution->seeElementCoefs (iElementL));
// 	for (int k=0; k<nbFields; ++k){
// 	  for (int i=0; i<fSize; ++i){
// 	    MIN ( iElementL , k ) = std::min (  TempL(i,k) , MIN ( iElementL , k ) );
// 	    MAX ( iElementL , k ) = std::max (  TempL(i,k) , MAX ( iElementL , k ) );
	    

// 	    double AVG = 0;
// 	    for (int i=0; i<fSize; ++i)  AVG += TempL(i,k);

// 	  }
// 	}
//       }
//     }
//   // some parallel should be done here in order to compute averages on other processors
//   //----------------------------------------------------------

//   //...
  
//   // then limit the solution
//   //----------------------------------------------------------
  
//   for (int iElement=0 ; iElement<solution->getNbElements(); ++iElement)
//     {
//       fullMatrix Temp = fullMatrix(solution->touchElementCoefs (iElement));
//       for (int k=0; k<nbFields; ++k)
// 	{
// 	  double AVG = 0.;
// 	  double locMax = -1.e22;
// 	  double locMin =  1.e22;
// 	  double neighMax = MAX (iElement,k);
// 	  double neighMin = MIN (iElement,k);
// 	  for (int i=0; i<fSize; ++i)
// 	    {
// 	      AVG += Temp(i,k);
// 	      locMax = std::max (locMax, Temp (i,k));
// 	      locMin = std::min (locMin, Temp (i,k));
// 	    }	  
// 	  AVG /= (double) fSize;
	  
// 	  //SLOPE LIMITING DG
//  	  //-------------------
// 	  for (int i=0; i<fSize; ++i)Temp(i,k) -= AVG;

// 	  double slopeLimiterValue = 1.0;
// 	  if (locMax != AVG && locMax > neighMax) slopeLimiterValue = (neighMax-AVG) / (locMax-AVG);
// 	  if (locMin != AVG && locMin < neighMin) slopeLimiterValue = std::min ( slopeLimiterValue , (AVG-neighMin) / (AVG-locMin) );
// 	  if (AVG < neighMin) slopeLimiterValue = 0; 
// 	  if (AVG > neighMax) slopeLimiterValue = 0; 

// 	  if (detectDISC(iElement) == 0.0) slopeLimiterValue = 1.0; // do not limit
// 	  //if (slopeLimiterValue != 1.0) printf("limit (%g) elem =%d \n", slopeLimiterValue, iElement);
	  
// 	  for (int i=0; i<fSize; ++i) Temp(i,k) *= slopeLimiterValue;

// 	  for (int i=0; i<fSize; ++i) Temp(i,k) += AVG;

// 	  //MINMOD DG (IF CHANGE TO THIS ADD LIMITER LINE IN RUNGEKUTTANNOPERATOR.cc)
// 	  //--------------------------------
// // 	  if (detectDISC(iElement) != 0.0){
// // 	    const size_t nn = Temp.size1();
// // 	    double alpha = 0.5; //0.5 1.0 1.3 (alpha=0.5 => MUSC Schem VAN LEER)
// // 	    Temp(0,k) = AVG-minmod(AVG-Temp(0,k), alpha*(AVG-MEANL(iElement,k)), alpha*(MEANR(iElement,k)-AVG));
// // 	    Temp(nn-1,k) = AVG+minmod(Temp(nn-1,k)-AVG, alpha*(AVG-MEANL(iElement,k)), alpha*(MEANR(iElement,k)-AVG));	 
// // 	    }


// 	}
//     }

//   return true;

// }
