#ifndef _DG_CONSERVATION_LAW_MAXWELL_H
#define _DG_CONSERVATION_LAW_MAXWELL_H
#include "dgConservationLaw.h"



class dgConservationLawMaxwell : public dgConservationLaw {
  std::string _mu_epsFunctionName;
  class advection;
  class source;
  class riemann;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dgBoundaryCondition *newBoundaryWall () ;
  dgConservationLawMaxwell(std::string mu_epsFunctionName);

};
class binding;
void dgConservationLawMaxwellRegisterBindings(binding *b);
#endif
