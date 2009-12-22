#ifndef _DG_CONSERVATION_LAW_WAVE_EQUATION_H_
#define _DG_CONSERVATION_LAW_WAVE_EQUATION_H_
#include "dgConservationLaw.h"
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
  dgBoundaryCondition *newBoundaryWall () const;
  dgConservationLawWaveEquation(int DIM);
  static const char *className;
  static const char *parentClassName;
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;
};
#endif
