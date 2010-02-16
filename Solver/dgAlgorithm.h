#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "fullMatrix.h"
#include <vector>
class GModel;
class dgGroupCollection;
class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;
class dgDofContainer;
class dgTerm;
class dgLimiter;
class dgSystemOfEquations;

class dgAlgorithm {
 public :
  static void registerBindings(binding *b); 
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
  static void residual( const dgConservationLaw &claw, dgGroupCollection &groups,
			dgDofContainer &solution, dgDofContainer &residual);	  
  static void computeElementaryTimeSteps ( //dofManager &dof, // the DOF manager (maybe useless here)
					  const dgConservationLaw &claw,   // the conservation law
					  const dgGroupOfElements & group, // the group
					  fullMatrix<double> &solution, // the solution 
					  std::vector<double> & DT // elementary time steps
					   );

  static void multAddInverseMassMatrix ( /*dofManager &dof,*/
					const dgGroupOfElements & group,
					fullMatrix<double> &residu,
					fullMatrix<double> &sol);
};

#endif
