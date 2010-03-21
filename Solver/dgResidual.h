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
#include <vector>

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
  const dgConservationLaw &_claw;
  int _nbFields;
  public:
  dgResidualInterface (const dgConservationLaw &claw);
  void compute1Group ( //dofManager &dof, // the DOF manager (maybe useless here)
                                     dgGroupOfFaces &group, 
                                     const fullMatrix<double> &solution, // solution !! at faces nodes
             const std::vector<const fullMatrix<double>*> solutionOnElements,
                                     fullMatrix<double> &residual // residual !! at faces nodes
            );
  void computeAndMap1Group (dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual);
  ~dgResidualInterface();
};

class dgResidual {
  const dgConservationLaw &_claw;
  public:
  dgResidual (const dgConservationLaw *claw) : _claw(*claw) {}
  void compute(dgGroupCollection &groups, dgDofContainer &solution, dgDofContainer &residual);
  static void registerBindings (binding *b);
};

#endif
