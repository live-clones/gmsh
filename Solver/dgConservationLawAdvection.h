#ifndef _DG_CONSERVATION_LAW_ADVECTION_DIFFUSION_H
#define _DG_CONSERVATION_LAW_ADVECTION_DIFFUSION_H
#include "dgConservationLaw.h"
//AdvectionDiffusion diffusion equation
//dc/dt + v div(c) - nu lapl(c) = 0
class function;
class dgConservationLawAdvectionDiffusion : public dgConservationLaw {
  const function *_vFunction, *_nuFunction;
  class advection;
  class riemann;
  class diffusion;
  class maxConvectiveSpeed;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaximumDiffusivity( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaxConvectiveSpeed( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dgConservationLawAdvectionDiffusion(const function *vFunction, const function *nuFunction);
  static dgConservationLawAdvectionDiffusion *diffusionLaw(const function *nuFunction);
  static dgConservationLawAdvectionDiffusion *advectionLaw(const function *vFunction);
};
class binding;
void dgConservationLawAdvectionDiffusionRegisterBindings (binding *b);
#endif
