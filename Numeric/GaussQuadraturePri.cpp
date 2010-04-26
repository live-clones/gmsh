// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Gauss.h"
#include "GaussLegendre1D.h"
#include "stdio.h"

IntPt *getGQPriPts(int order);
int getNGQPriPts(int order);

IntPt * GQP[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

IntPt *getGQPriPts(int order)
{ 
  int nLin = (order+3)/2;
  int nTri = getNGQTPts(order);
  int n = nLin*nTri;
  int index = n;
  if(!GQP[index])
    {
      double *linPt,*linWt;
      IntPt *triPts = getGQTPts(order);
//            printf("o = %d n = %d nT = %d nL = %d i = %d\n",order,n,nTri,nLin,index);
      gmshGaussLegendre1D(nLin,&linPt,&linWt);
      GQP[index] = new IntPt[n];
      int l = 0;
      for(int i=0; i < nTri; i++) {
        for(int j=0; j < nLin; j++) {
            GQP[index][l].pt[0] = triPts[i].pt[0];
            GQP[index][l].pt[1] = triPts[i].pt[1];
            GQP[index][l].pt[2] = linPt[j];
            GQP[index][l++].weight = triPts[i].weight*linWt[j];
//                  printf ("%d: %f %f %f %f\n",l-1,triPts[i].pt[0],triPts[i].pt[1],linPt[j],triPts[i].weight*linWt[j]);
        }
      }
    }
  return GQP[index];
}

int getNGQPriPts(int order)
{ 
  int nLin = (order+3)/2;
  int nTri = getNGQTPts(order);
  return nLin*nTri;

//   if(order == 3)return 8;
//   if(order == 2)return 8;
//   if(order < 2)
//     return GQPnPt[order]; 
//   return ((order+3)/2)*((order+3)/2)*((order+3)/2);
}





