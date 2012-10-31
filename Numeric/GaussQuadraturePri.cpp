// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

IntPt *getGQPriPts(int order);
int getNGQPriPts(int order);

IntPt * GQP[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

IntPt *getGQPriPts(int order)
{
  int nLin = (order+3)/2;
  int nTri = getNGQTPts(order);
  int n = nLin*nTri;
  int index = order;
  if (order >= (int)(sizeof(GQP) / sizeof(IntPt*)))
    Msg::Fatal("Increase size of GQP in gauss quadrature prism");
  if(!GQP[index]){
    double *linPt,*linWt;
    IntPt *triPts = getGQTPts(order);
    gmshGaussLegendre1D(nLin,&linPt,&linWt);
    GQP[index] = new IntPt[n];
    int l = 0;
    for(int i=0; i < nTri; i++) {
      for(int j=0; j < nLin; j++) {
        GQP[index][l].pt[0] = triPts[i].pt[0];
        GQP[index][l].pt[1] = triPts[i].pt[1];
        GQP[index][l].pt[2] = linPt[j];
        GQP[index][l++].weight = triPts[i].weight*linWt[j];
      }
    }
  }
  return GQP[index];
}

int getNGQPriPts(int order)
{
  int nLin = (order+3)/2;
  int nTri = getNGQTPts(order);
  return nLin * nTri;

//   if(order == 3)return 8;
//   if(order == 2)return 8;
//   if(order < 2)
//     return GQPnPt[order];
//   return ((order+3)/2)*((order+3)/2)*((order+3)/2);
}





