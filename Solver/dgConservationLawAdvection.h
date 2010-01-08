#ifndef _DG_CONSERVATION_LAW_ADVECTION_H
#define _DG_CONSERVATION_LAW_ADVECTION_H
#include "dgConservationLaw.h"
//Advection diffusion equation
//dc/dt + v div(c) - nu lapl(c) = 0
class dgConservationLawAdvection : public dgConservationLaw {
  std::string _vFunctionName,_nuFunctionName;
  class advection;
  class riemann;
  class diffusion;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaximumDiffusivity( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dgConservationLawAdvection(std::string vFunctionName, std::string nuFunctionName);
};
class binding;
void dgConservationLawAdvectionRegisterBindings (binding *b);
#endif
