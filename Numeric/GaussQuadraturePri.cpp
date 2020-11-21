// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

static std::map<int, IntPt*> GQP;

IntPt *getGQPriPts(int order)
{
  int nLin = (order + 3) / 2;
  int nTri = getNGQTPts(order);
  int n = nLin * nTri;
  if(!GQP.count(n)) {
    double *linPt, *linWt;
    IntPt *triPts = getGQTPts(order);
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
    GQP[n] = intpt;
  }
  return GQP[n];
}

int getNGQPriPts(int order)
{
  int nLin = (order + 3) / 2;
  int nTri = getNGQTPts(order);
  return nLin * nTri;
}
