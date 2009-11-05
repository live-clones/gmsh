#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "dofManager.h"

class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;

class dgAlgorithm {
 public :
   void residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfElements & group, 
           const fullMatrix<double> &solution,
           fullMatrix<double> &residual);
  void residualInterface ( /*dofManager &dof,*/
			   const dgConservationLaw &law,
			   const dgGroupOfFaces & group);
  void residualBoundaryConditions ( /*dofManager &dof,*/
				    const dgConservationLaw &law,
				    const dgGroupOfElements & group);
};


#endif
