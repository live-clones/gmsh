#ifndef _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#define _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#include "dgConservationLaw.h"
class dgPerfectGasLaw2d : public dgConservationLaw {
  class advection;
  class diffusion;
  class riemann;
  class riemannGodunov;
  class source;
  class maxConvectiveSpeed;
  class maxDiffusivity;
  // the name of the functions for 
  // viscosity (_muFunctionName)
  // thermal conductivity (_kappaFunctionName)
  std::string _kappaFunctionName,_muFunctionName;
  std::string _sourceFunctionName;

  public:
  dataCacheDouble *newMaxConvectiveSpeed( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaximumDiffusivity( dataCacheMap &cacheMap) const;
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dgPerfectGasLaw2d();  
  dgBoundaryCondition *newWallBoundary() ;
  dgBoundaryCondition *newSlipWallBoundary() ;
  // sets some coefficients 
  void setViscosityAndThermalConductivity (std::string a, std::string b){
    _muFunctionName = a;
    _kappaFunctionName = b;
  }
  // sets some coefficients 
  void setSource(std::string a){
    _sourceFunctionName = a;
  }
};
class binding;
void dgPerfectGasLaw2dRegisterBindings(binding *b);
#endif
