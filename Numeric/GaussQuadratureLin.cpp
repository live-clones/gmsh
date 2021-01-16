// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

static std::vector<IntPt *> GQL(40, nullptr);

IntPt *getGQLPts(int order)
{
  // Number of Gauss Point: (order + 1) / 2 *ROUNDED UP*
  int n = (order + 1) / (double)2 + 0.5;
  if(static_cast<int>(GQL.size()) < order + 1) GQL.resize(order + 1, nullptr);
  if(!GQL[order]) {
    double *pt, *wt;
    gmshGaussLegendre1D(n, &pt, &wt);
    IntPt *intpt = new IntPt[n];
    for(int i = 0; i < n; i++) {
      intpt[i].pt[0] = pt[i];
      intpt[i].pt[1] = 0.0;
      intpt[i].pt[2] = 0.0;
      intpt[i].weight = wt[i];
    }
    GQL[order] = intpt;
  }
  return GQL[order];
}

int getNGQLPts(int order) { return (order + 1) / (double)2 + 0.5; }
