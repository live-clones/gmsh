#ifndef _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#define _DG_CONSERVATION_LAW_PERFECT_GAS_H_
#include "dgConservationLaw.h"
// Compressible Navier-Stokes equations
// d(rho)/dt  + d(rhou)/dx  + d(rhov)/dy = 0
// d(rhou)/dt + d(rhou^2+p)/dx + d(rhouv)/dy + d(t_xx)/dx + d(t_xy)/dy= 0
// d(rhov)/dt + d(rhouv)/dx + d(rhov^2+p)/dy + d(t_xy)/dx + d(t_yy)/dy= 0
// d(rhoE)/dt + d(rhouH)/dx + d(rhovH)/dy + d(ut_xx+vt_xy-q_x)/dx + d(ut_xy+vt_yy-q_y)/dy= 0
class binding;
void dgPerfectGasLaw2dRegisterBindings(binding *b);
#endif
