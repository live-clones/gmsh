// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

IntPt * GQL[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

IntPt *getGQLPts(int order)
{
  // Number of Gauss Point:
  // (order + 1) / 2 *ROUNDED UP*
  int n = (order + 1) / (double)2 + 0.5;
  int index = n;
  if(index >= (int)(sizeof(GQL) / sizeof(IntPt*))){
    Msg::Error("Increase size of GQL in gauss quadrature line");
    index = 0;
  }
  if(!GQL[index]) {
    double *pt,*wt;
    gmshGaussLegendre1D(n,&pt,&wt);
    GQL[index] = new IntPt[n];
    for(int i=0; i < n; i++) {
      GQL[index][i].pt[0] = pt[i];
      GQL[index][i].pt[1] = 0.0;
      GQL[index][i].pt[2] = 0.0;
      GQL[index][i].weight = wt[i];
    }
  }
  return GQL[index];
}

int getNGQLPts(int order)
{
  return (order + 1) / (double)2 + 0.5;
}
