#ifndef _DG_CONSERVATION_LAW_ADVECTION_H
#define _DG_CONSERVATION_LAW_ADVECTION_H
#include "dgConservationLaw.h"
class constructorBinding;
class methodBinding;
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
  static const char * className;
  static const char * parentClassName;
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;
};
#endif
