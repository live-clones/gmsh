// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

static std::vector<IntPt *> GQP(40, nullptr), GQPGL(40, nullptr);

IntPt *getGQPriPts(int order, bool forceTensorRule)
{
  int nLin = (order + 3) / 2;
  int nTri = getNGQTPts(order, forceTensorRule);
  int n = nLin * nTri;
  if(forceTensorRule && static_cast<int>(GQPGL.size()) < order + 1)
    GQPGL.resize(order + 1, nullptr);
  else if(!forceTensorRule && static_cast<int>(GQP.size()) < order + 1)
    GQP.resize(order + 1, nullptr);
  if((forceTensorRule && !GQPGL[order]) ||
     (!forceTensorRule && !GQP[order])) {
    double *linPt, *linWt;
    IntPt *triPts = getGQTPts(order, forceTensorRule);
    gmshGaussLegendre1D(nLin, &linPt, &linWt);
    IntPt *intpt = new IntPt[n];
    int l = 0;
    for(int i = 0; i < nTri; i++) {
      for(int j = 0; j < nLin; j++) {
        intpt[l].pt[0] = triPts[i].pt[0];
        intpt[l].pt[1] = triPts[i].pt[1];
        intpt[l].pt[2] = linPt[j];
        intpt[l++].weight = triPts[i].weight * linWt[j];
      }
    }
    if(forceTensorRule)
      GQPGL[order] = intpt;
    else
      GQP[order] = intpt;
  }
  if(forceTensorRule)
    return GQPGL[order];
  else
    return GQP[order];
}

int getNGQPriPts(int order, bool forceTensorRule)
{
  int nLin = (order + 3) / 2;
  int nTri = getNGQTPts(order, forceTensorRule);
  return nLin * nTri;
}
