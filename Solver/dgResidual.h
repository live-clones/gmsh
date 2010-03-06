#ifndef _DG_RESIDUAL_H_
#define _DG_RESIDUAL_H_
class dgConservationLaw;
class dgGroupCollection;
class dataCacheDouble;
class dataCacheElement;
class dgDofContainer;
class dataCacheMap;
class dgGroupOfElements;
class dgGroupOfFaces;
class binding;
#include "fullMatrix.h"

class dgResidualVolume {
  dataCacheMap *_cacheMap;
  const dgConservationLaw &_claw;
  int _nbFields;
  dataCacheElement &_cacheElement;
  dataCacheDouble &_UVW, &_solutionQPe, &_gradientSolutionQPe;
  dataCacheDouble *_sourceTerm, *_convectiveFlux, *_diffusiveFlux;
  public:
  dgResidualVolume (const dgConservationLaw &claw);
  ~dgResidualVolume();
  void compute1Group(dgGroupOfElements &group, fullMatrix<double> &solution, fullMatrix<double> &residual);
  void compute1GroupWithJacobian(dgGroupOfElements &group, fullMatrix<double> &solution, fullMatrix<double> &residual, fullMatrix<double> &jacobian);
  void computeAndMap1Group(dgGroupOfElements &group, dgDofContainer &solution, dgDofContainer &residual);
};

class dgResidualInterface {
  dataCacheMap *_cacheMapLeft, *_cacheMapRight;
  const dgConservationLaw &_claw;
  int _nbFields;
  dataCacheElement &_cacheElementLeft, &_cacheElementRight;
  dataCacheDouble &_uvwLeft, &_uvwRight, &_solutionQPLeft, &_solutionQPRight, &_gradientSolutionLeft, &_gradientSolutionRight;
  dataCacheDouble &_normals;
  dataCacheDouble *_riemannSolver, *_maximumDiffusivityLeft,*_maximumDiffusivityRight, *_diffusiveFluxLeft, *_diffusiveFluxRight;
  public:
  dgResidualInterface (const dgConservationLaw &claw);
  void compute1Group ( //dofManager &dof, // the DOF manager (maybe useless here)
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     fullMatrix<double> &solutionLeft, 
				     fullMatrix<double> &solutionRight, 
				     fullMatrix<double> &residual // residual !! at faces nodes
            );
  void computeAndMap1Group (dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual);
  ~dgResidualInterface();
};

class dgResidualBoundary {
  const dgConservationLaw &_claw;
  public :
  void compute1Group ( //dofManager &dof, // the DOF manager (maybe useless here)
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     fullMatrix<double> &solutionLeft, 
				     fullMatrix<double> &residual // residual !! at faces nodes
            );
  void computeAndMap1Group (dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual);
  dgResidualBoundary (const dgConservationLaw &claw);
};

class dgResidual {
  const dgConservationLaw &_claw;
  public:
  dgResidual (const dgConservationLaw *claw) : _claw(*claw) {}
  void compute(dgGroupCollection &groups, dgDofContainer &solution, dgDofContainer &residual);
  static void registerBindings (binding *b);
};

#endif
