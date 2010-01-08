#ifndef _DG_CONSERVATION_LAW_WAVE_EQUATION_H_
#define _DG_CONSERVATION_LAW_WAVE_EQUATION_H_
#include "dgConservationLaw.h"
// Linear acoustics
// dp/dt - rho*c^2  div(u,v) = 0
// du/dt + 1/rho  dp/dx = 0
// dv/dt + 1/rho  dp/dy = 0
class methodBinding;
class constructorBinding;
class dgConservationLawWaveEquation : public dgConservationLaw {
  int _DIM;
  class hyperbolicFlux;
  class maxConvectiveSpeed;
  class riemann;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const ;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const ;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const ;
  dataCacheDouble *newMaxConvectiveSpeed (dataCacheMap &cacheMap) const;
  dgBoundaryCondition *newBoundaryWall () ;
  dgConservationLawWaveEquation(int DIM);
  static const char *className;
  static const char *parentClassName;
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;
};
void dgConservationLawWaveEquationRegisterBindings(binding *b);
#endif
