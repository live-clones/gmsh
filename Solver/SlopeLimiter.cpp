#include "dgLimiter.h"
#include "dgGroupOfElements.h"
#include "dgSystemOfEquations.h"


// //----------------------------------------------------------------------------------
// bool SlopeLimiter::apply ( dgDofContainer &solution,  
// 			   std::vector<dgGroupOfElements*> &eGroups, 
// 			   std::vector<dgGroupOfFaces*> &fGroups)
// {

//   //WARNING FOR ONLY 1 GROUP OF FACES
//   dgGroupOfFaces* group = fGroups[0];
//   fullMatrix<double> SolLeft = solution._dataProxys[0];
//   fullMatrix<double> SolRight = solution._dataProxys[0];
//   int nbFields = solution->getNbFields();
//   int totNbElems = solution->getNbElements();

//   // first compute max and min of all fields for all stencils
//   //----------------------------------------------------------
//   fullMatrix<double> MIN (totNbElems,nbFields );
//   fullMatrix<double>  MAX (totNbElems, nbFields);  
//   MIN.set_all ( 1.e22);
//   MAX.set_all (-1.e22);

//   fullMatrix<double>  MEANL (totNbElems, nbFields);
//   fullMatrix<double>  MEANR (totNbElems, nbFields);  
//   MEANL.set_all ( 0.01);
//   MEANR.set_all ( 0.01);

//    for(int iFace=0 ; iFace<group->getNbElements();iFace++)
//     {
//       int iElementL = group->getElementLeftId(iFace);
//       int iElementR = group->getElementRightId(iFace);
//       if (iElementR >= 0)
// 	{
// 	  fullMatrix<double> TempL, TempR;
// 	  TempL.setAsProxy(SolLeft, nbFields*iELementL, nbFields );
// 	  TempR.setAsProxy(SolRight, nbFields*iELementR, nbFields );
// 	  printf("TempL size 1 = %d %d ", TempL.size1(), TempL.size2());
// 	  exit(1);

// 	  int fSize = TempL.size2();
// 	  for (int k=0; k< fSize; ++k)
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
// 	fullMatrix<double> TempL, ;
// 	TempL.setAsProxy(SolLeft, nbFields*iELementL, nbFields );
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
  
// //   for (int iElement=0 ; iElement<totNbElems; ++iElement)
// //     {
// //       fullMatrix Temp = fullMatrix(solution->touchElementCoefs (iElement));
// //       for (int k=0; k<nbFields; ++k)
// // 	{
// // 	  double AVG = 0.;
// // 	  double locMax = -1.e22;
// // 	  double locMin =  1.e22;
// // 	  double neighMax = MAX (iElement,k);
// // 	  double neighMin = MIN (iElement,k);
// // 	  for (int i=0; i<fSize; ++i)
// // 	    {
// // 	      AVG += Temp(i,k);
// // 	      locMax = std::max (locMax, Temp (i,k));
// // 	      locMin = std::min (locMin, Temp (i,k));
// // 	    }	  
// // 	  AVG /= (double) fSize;
	  
// // 	  //SLOPE LIMITING DG
// //  	  //-------------------
// // 	  for (int i=0; i<fSize; ++i)Temp(i,k) -= AVG;

// // 	  double slopeLimiterValue = 1.0;
// // 	  if (locMax != AVG && locMax > neighMax) slopeLimiterValue = (neighMax-AVG) / (locMax-AVG);
// // 	  if (locMin != AVG && locMin < neighMin) slopeLimiterValue = std::min ( slopeLimiterValue , (AVG-neighMin) / (AVG-locMin) );
// // 	  if (AVG < neighMin) slopeLimiterValue = 0; 
// // 	  if (AVG > neighMax) slopeLimiterValue = 0; 

// // 	  if (detectDISC(iElement) == 0.0) slopeLimiterValue = 1.0; // do not limit
// // 	  //if (slopeLimiterValue != 1.0) printf("limit (%g) elem =%d \n", slopeLimiterValue, iElement);
	  
// // 	  for (int i=0; i<fSize; ++i) Temp(i,k) *= slopeLimiterValue;

// // 	  for (int i=0; i<fSize; ++i) Temp(i,k) += AVG;

// // 	  //MINMOD DG (IF CHANGE TO THIS ADD LIMITER LINE IN RUNGEKUTTANNOPERATOR.cc)
// // 	  //--------------------------------
// // // 	  if (detectDISC(iElement) != 0.0){
// // // 	    const size_t nn = Temp.size1();
// // // 	    double alpha = 0.5; //0.5 1.0 1.3 (alpha=0.5 => MUSC Schem VAN LEER)
// // // 	    Temp(0,k) = AVG-minmod(AVG-Temp(0,k), alpha*(AVG-MEANL(iElement,k)), alpha*(MEANR(iElement,k)-AVG));
// // // 	    Temp(nn-1,k) = AVG+minmod(Temp(nn-1,k)-AVG, alpha*(AVG-MEANL(iElement,k)), alpha*(MEANR(iElement,k)-AVG));	 
// // // 	    }


// // 	}
// //     }

//   return true;

// }
