// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MLine.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"

const functionSpace* MLine::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  
  switch (order) {
  case 1: return &functionSpaces::find(MSH_LIN_2);
  case 2: return &functionSpaces::find(MSH_LIN_3);
  case 3: return &functionSpaces::find(MSH_LIN_4);
  case 4: return &functionSpaces::find(MSH_LIN_5);
  case 5: return &functionSpaces::find(MSH_LIN_6);
  default: Msg::Error("Order %d line function space not implemented", order);
  }
  return 0;
}

void MLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  static IntPt GQL[100]; 
  double *t, *w;
  int nbP = pOrder / 2 + 1;
  gmshGaussLegendre1D(nbP, &t, &w);
  for (int i = 0; i < nbP; i++){
    GQL[i].pt[0] = t[i];
    GQL[i].pt[1] = 0;
    GQL[i].pt[2] = 0;
    GQL[i].weight = w[i];
  }
  *npts = nbP;
  *pts = GQL;
}
