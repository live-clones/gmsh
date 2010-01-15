#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "fullMatrix.h"
#include <vector>
class GModel;
class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;
class dgDofContainer;
class dgTerm;
class dgLimiter;
class dgSystemOfEquations;

class dgAlgorithm {
 public :
  static void residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
			      const dgConservationLaw &claw,   // the conservation law
			      const dgGroupOfElements & group, 
			      fullMatrix<double> &solution,
			      fullMatrix<double> &residual);
  static void residualInterface ( //dofManager &dof, // the DOF manager (maybe useless here)
				 const dgConservationLaw &claw,   // the conservation law
				 dgGroupOfFaces & group, 
				 const fullMatrix<double> &solution, // ! at face nodes
				 fullMatrix<double> &solutionRight,
				 fullMatrix<double> &solutionLeft,
				 fullMatrix<double> &residual); // ! at face nodes
  static void residualBoundary ( //dofManager &dof, // the DOF manager (maybe useless here)
				const dgConservationLaw &claw,   // the conservation law
				dgGroupOfFaces &group, 
				const fullMatrix<double> &solution, // solution !! at faces nodes
				fullMatrix<double> &solutionLeft,
				fullMatrix<double> &residual // residual !! at faces nodes
				 );
  // works only if there is only 1 group of element
  static void residual( const dgConservationLaw &claw,
			std::vector<dgGroupOfElements*> &eGroups, //group of elements
			std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
			std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
      std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
			std::vector<fullMatrix<double> *> &solution, // solution !! at faces nodes
			std::vector<fullMatrix<double> *> &residual // residual !! at faces nodes
			);	  
  void rungeKutta (
		   const dgConservationLaw &claw,
		   std::vector<dgGroupOfElements*> &eGroups, //group of elements
		   std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
		   std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
      std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
		   double h,	
		   dgDofContainer &residu,
		   dgDofContainer &sol,
       dgSystemOfEquations *syst,
		   dgLimiter *limiter=NULL,
		   int orderRK=4);
  static void computeElementaryTimeSteps ( //dofManager &dof, // the DOF manager (maybe useless here)
					  const dgConservationLaw &claw,   // the conservation law
					  const dgGroupOfElements & group, // the group
					  fullMatrix<double> &solution, // the solution 
					  std::vector<double> & DT // elementary time steps
					   );
  void multirateRungeKutta (
		   const dgConservationLaw &claw,
		   std::vector<dgGroupOfElements*> &eGroups, //group of elements
		   std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
		   std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
      std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
		   double h,	
		   dgDofContainer &residu,
		   dgDofContainer &sol,
		   int orderRK=3);

  static void multAddInverseMassMatrix ( /*dofManager &dof,*/
					const dgGroupOfElements & group,
					fullMatrix<double> &residu,
					fullMatrix<double> &sol);
  static void buildGroups(GModel *model, int dim, int order,
			  std::vector<dgGroupOfElements*> &eGroups,
			  std::vector<dgGroupOfFaces*> &fGroups,
			  std::vector<dgGroupOfFaces*> &bGroups,
			  std::vector<dgGroupOfElements*> &ghostGroups);
};


#endif
