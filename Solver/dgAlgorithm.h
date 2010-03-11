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
class dgTransformNodalValue;
class dgSystemOfEquations;

class dgAlgorithm {
 public :
  static void jacobianVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
			      const dgConservationLaw &claw,   // the conservation law
			      const dgGroupOfElements & group, 
			      fullMatrix<double> &solution,
			      fullMatrix<double> &residual);

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
