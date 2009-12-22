#ifndef _DG_CONSERVATION_LAW_SHALLOW_WATER_2D_
#define _DG_CONSERVATION_LAW_SHALLOW_WATER_2D_
#include "dgConservationLaw.h"

class dataCacheMap;
class binding;

class dgConservationLawShallowWater2d : public dgConservationLaw {
  class advection;
  class source;
  class riemann;
  class boundaryWall;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dgConservationLawShallowWater2d() 
  {
    _nbf = 3; // H U(=Hu) V(=Hv)
  }
  dgBoundaryCondition *newBoundaryWall();
};
void dgConservationLawShallowWater2dRegisterBindings(binding *b);
#endif
