// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MQuadrangle.h"

#if defined(HAVE_GMSH_EMBEDDED)
#include "GmshEmbedded.h"
#else
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"
#endif

void MQuadrangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQQPts(pOrder);
  *pts = getGQQPts(pOrder);
#endif
}

