// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MQuadrangle.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"

void MQuadrangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
  *npts = getNGQQPts(pOrder);
  *pts = getGQQPts(pOrder);
}

