// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _APPROXIMATION_ERROR_
#define _APPROXIMATION_ERROR_

#include <map>
#include "simpleFunction.h"

class MElement;

// computes E such as
// E^2 = \int_e [C_e(f) - f]^2 de
// where C_e(f) is clement's interpolation operator of f on e
double approximationError(simpleFunction<double> &f, MElement *e);

#endif
