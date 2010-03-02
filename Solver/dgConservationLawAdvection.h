#ifndef _DG_CONSERVATION_LAW_ADVECTION_DIFFUSION_H
#define _DG_CONSERVATION_LAW_ADVECTION_DIFFUSION_H
#include "dgConservationLaw.h"
//AdvectionDiffusion diffusion equation
//dc/dt + v div(c) - nu lapl(c) = 0
class dgConservationLawAdvectionDiffusion : public dgConservationLaw {
  std::string _vFunctionName,_nuFunctionName;
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
  dgConservationLawAdvectionDiffusion(std::string vFunctionName, std::string nuFunctionName);
};
class binding;
void dgConservationLawAdvectionDiffusionRegisterBindings (binding *b);
#endif
