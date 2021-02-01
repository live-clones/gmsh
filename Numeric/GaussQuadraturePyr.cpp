// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"
#include "GaussJacobi1D.h"

static std::vector<IntPt *> GQPyr(40, nullptr);

IntPt *getGQPyrPts(int order)
{
  if(static_cast<int>(GQPyr.size()) < order + 1)
    GQPyr.resize(order + 1, nullptr);
  if(!GQPyr[order]) {
    int nbPtUV = order / 2 + 1;
    int nbPtW = order / 2 + 1;
    int nbPtUV2 = nbPtUV * nbPtUV;

    double *linPt, *linWt;
    gmshGaussLegendre1D(nbPtUV, &linPt, &linWt);

    double *GJ20Pt, *GJ20Wt;
    getGaussJacobiQuadrature(2, 0, nbPtW, &GJ20Pt, &GJ20Wt);

    IntPt *intpt = new IntPt[getNGQPyrPts(order)];

    int l = 0;
    for(int i = 0; i < getNGQPyrPts(order); i++) {
      // compose an integration rule for (1-w)^2 f(u,v,w) on the standard
      // hexahedron

      int iW = i / (nbPtUV2);
      int iU = (i - iW * nbPtUV2) / nbPtUV;
      int iV = (i - iW * nbPtUV2 - iU * nbPtUV);

      double wt = linWt[iU] * linWt[iV] * GJ20Wt[iW];

      double up = linPt[iU];
      double vp = linPt[iV];
      double wp = GJ20Pt[iW];

      // now incorporate the Duffy transformation from pyramid to hexahedron

      intpt[l].pt[0] = 0.5 * (1 - wp) * up;
      intpt[l].pt[1] = 0.5 * (1 - wp) * vp;
      intpt[l].pt[2] = 0.5 * (1 + wp);

      wt *= 0.125;
      intpt[l++].weight = wt * 4. / 3.;
    }
    GQPyr[order] = intpt;
  }
  return GQPyr[order];
}

int getNGQPyrPts(int order)
{
  int nbPtUV = order / 2 + 1;
  int nbPtW = order / 2 + 1;
  return nbPtUV * nbPtUV * nbPtW;
}
