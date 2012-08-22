// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "PView.h"
#include "PViewData.h"
#include "PViewAsSimpleFunction.h"

double PViewEvaluator::operator() (const double x, const double y, const double z) const
{
  PViewData * pvd = _pv->getData();
  double value;
  bool found = pvd->searchScalar(x, y, z, &value, _step);
  //  printf("found %d %g %g %g %g\n",found,x,y,value,x*x+y*y);
  if (found) return value;
  return 1.e22;
}
