#ifndef _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#define _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#include "dgConservationLaw.h"
// Compressible Navier-Stokes equations
// d(rho)/dt  + d(rhou)/dx  + d(rhov)/dy = 0
// d(rhou)/dt + d(rhou^2+p)/dx + d(rhouv)/dy + d(t_xx)/dx + d(t_xy)/dy= 0
// d(rhov)/dt + d(rhouv)/dx + d(rhov^2+p)/dy + d(t_xy)/dx + d(t_yy)/dy= 0
// d(rhoE)/dt + d(rhouH)/dx + d(rhovH)/dy + d(ut_xx+vt_xy-q_x)/dx + d(ut_xy+vt_yy-q_y)/dy= 0
class dgPerfectGasLaw2d : public dgConservationLaw {
  class advection;
  class diffusion;
  class riemann;
  class riemannGodunov;
  class source;
  class maxConvectiveSpeed;
  class maxDiffusivity;
  class clipToPhysics;
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
  dataCacheDouble *newClipToPhysics (dataCacheMap &cacheMap) const;
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
