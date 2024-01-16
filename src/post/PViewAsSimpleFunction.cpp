// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "PView.h"
#include "PViewData.h"
#include "PViewAsSimpleFunction.h"

double PViewEvaluator::operator()(double x, double y, double z) const
{
  PViewData *pvd = _pv->getData();
  double value;
  bool found = pvd->searchScalar(x, y, z, &value, _step);
  //  printf("found %d %g %g %g %g\n",found,x,y,value,x*x+y*y);
  if(found) return value;
  return 1.e22;
}
