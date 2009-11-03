#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "dofManager.h"

class groupOfElements;
class groupOfFaces;
class dgConservationLaw;

class dgAlgorithm () {
 public :
  void residualVolume ( dofManager &dof,
			dgConservationLaw &law,
			groupOfElements & group ,
			fullMatrix<double> &solution,
			fullMatrix<double> &residual);
  void residualInterface ( dofManager &dof,
			   dgConservationLaw &law,
			   groupOfFaces & group ,
			   fullMatrix<double> &solution,
			   fullMatrix<double> &residual);
  void residualBoundaryConditions ( dofManager &dof,
				    dgConservationLaw &law,
				    groupOfElements & group ,
				    fullMatrix<double> &solution,
				    fullMatrix<double> &residual);
};


#endif
