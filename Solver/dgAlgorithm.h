#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "dofManager.h"

class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;
class dgTerm;

class dgAlgorithm {
 public :
   void residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfElements & group, 
           const fullMatrix<double> &solution,
           fullMatrix<double> &residual);
   void residualInterface ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfFaces & group, 
           const fullMatrix<double> &solution, // ! at face nodes
           fullMatrix<double> &residual); // ! at face nodes
  void residualBoundaryConditions ( /*dofManager &dof,*/
				    const dgConservationLaw &law,
				    const dgGroupOfElements & group);
  void multAddInverseMassMatrix ( /*dofManager &dof,*/
      const dgGroupOfElements & group,
      fullMatrix<double> &residu,
      fullMatrix<double> &sol);
};


#endif
