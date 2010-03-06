#ifndef _DG_CONSERVATION_LAW_SHALLOW_WATER_1D_
#define _DG_CONSERVATION_LAW_SHALLOW_WATER_1D_
#include "dgConservationLaw.h"

class dataCacheMap;
class binding;

class dgConservationLawShallowWater1d : public dgConservationLaw {
  class advection;
  class source;
  class riemann;
  class boundaryWall;
  class clipToPhysics;
  class maxConvectiveSpeed;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaxConvectiveSpeed( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dataCacheDouble *newClipToPhysics (dataCacheMap &cacheMap) const;
  dgConservationLawShallowWater1d() 
  {
    _nbf = 2; // eta u
  }
  dgBoundaryCondition *newBoundaryWall();
};
void dgConservationLawShallowWater1dRegisterBindings(binding *b);
#endif
