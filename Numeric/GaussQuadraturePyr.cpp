// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshMessage.h"
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"
#include "GaussJacobi1D.h"

IntPt *getGQPyrPts(int order);
int getNGQPyrPts(int order);

IntPt * GQPyr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

IntPt *getGQPyrPts(int order)
{
  int index = order;

  if(index >= (int)(sizeof(GQPyr) / sizeof(IntPt*))){
    Msg::Error("Increase size of GQPyr in gauss quadrature pyr");
    index = 0;
  }

  if(!GQPyr[index]) {

    int nbPtUV = order/2 + 1;
    int nbPtW  = order/2 + 1;
    int nbPtUV2 = nbPtUV * nbPtUV;

    double *linPt,*linWt;
    gmshGaussLegendre1D(nbPtUV,&linPt,&linWt);

    double *GJ20Pt, *GJ20Wt;
    getGaussJacobiQuadrature(2, 0, nbPtW, &GJ20Pt, &GJ20Wt);

    GQPyr[index] = new IntPt[getNGQPyrPts(order)];

    int l = 0;
    for (int i = 0; i < getNGQPyrPts(order); i++) {

      // compose an integration rule for (1-w)^2 f(u,v,w) on the standard hexahedron

      int iW = i / (nbPtUV2);
      int iU = (i - iW*nbPtUV2)/nbPtUV;
      int iV = (i - iW*nbPtUV2 - iU*nbPtUV);

      // std::cout << "Points " << iU << " " << iV << " " << iW << std::endl;

      double wt = linWt[iU]*linWt[iV]*GJ20Wt[iW];

      double up = linPt[iU];
      double vp = linPt[iV];
      double wp = GJ20Pt[iW];

      // now incorporate the Duffy transformation from pyramid to hexahedron

      GQPyr[index][l].pt[0] = 0.5*(1-wp)*up;
      GQPyr[index][l].pt[1] = 0.5*(1-wp)*vp;
      GQPyr[index][l].pt[2] = 0.5*(1+wp);

      wt *= 0.125;
      GQPyr[index][l++].weight = wt *4./3.;

    }

  }
  return GQPyr[index];
}


int getNGQPyrPts(int order)
{
  int nbPtUV = order/2 + 1;
  int nbPtW  = order/2 + 1;

  return nbPtUV*nbPtUV*nbPtW;
}
