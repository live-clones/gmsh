#ifndef _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#define _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#include "dgConservationLaw.h"
class dgPerfectGasLaw2d : public dgConservationLaw {
  // perfect gas law, GAMMA is the only parameter
  class advection;
  class riemann;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dgPerfectGasLaw2d();
  dgBoundaryCondition *newWallBoundary()const ;
};
class binding;
void dgPerfectGasLaw2dRegisterBindings(binding *b);
#endif
