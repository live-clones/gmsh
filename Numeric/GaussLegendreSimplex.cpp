// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "Gauss.h"
#include "GaussLegendre1D.h"

static void brickToTet(double xi, double eta, double zeta,
                       double *r, double *s, double *t, double *J)
{
  double r1, rs1;
  *r = 0.5e0 * (1.0e0 + xi);
  r1 = 1.0e0 - (*r);
  *s = 0.5e0 * (1.0e0 + eta) * r1;
  rs1 = 1.0e0 - (*r) - (*s);
  *t = 0.5e0 * (1.0e0 + zeta) * rs1;
  *J = 0.125e0 * r1 * rs1;
}

void quadToTri(double xi, double eta, double *r, double *s, double *J)
{
  double r1;
  *r = 0.5e0 * (1.0e0 + xi);
  r1 = 1.0e0 - (*r);
  *s = 0.5e0 * (1.0e0 + eta) * r1;
  *J = 0.25e0 * r1;  
}

double quadToTriJac(double,double eta)
{
  return 0.125e0 * (1.0e0 - eta);
}

int GaussLegendreTet(int n1, int n2, int n3, IntPt *pts) 
{
  /* get degenerate n1Xn2Xn3 Gauss-Legendre scheme to integrate over a tet */
  int i,j,k,index=0;
  double *pt1,*pt2,*pt3,*wt1,*wt2,*wt3,dJ;

  gmshGaussLegendre1D(n1,&pt1,&wt1);
  gmshGaussLegendre1D(n2,&pt2,&wt2);
  gmshGaussLegendre1D(n3,&pt3,&wt3);
  for(i=0; i < n1; i++) {
    for(j=0; j < n2; j++) {
      for(k=0; k < n3; k++) {
        brickToTet(pt1[i],pt2[j],pt3[k],&(pts[index].pt[0]),
                   &(pts[index].pt[1]),&(pts[index].pt[2]),&dJ);
        pts[index++].weight = dJ*wt1[i]*wt2[j]*wt3[k];
      }
    }
  }
  return index;
}

int GaussLegendreTri(int n1,int n2,IntPt *pts) 
{
  /* get degenerate n1Xn2 Gauss-Legendre scheme to integrate over a tri */
  int i,j,index=0;
  double *pt1,*pt2,*wt1,*wt2,dJ;
  //const double two = 2.0000000000000000;

  gmshGaussLegendre1D(n1,&pt1,&wt1);
  gmshGaussLegendre1D(n2,&pt2,&wt2);
  for(i=0; i < n1; i++) {
    for(j=0; j < n2; j++) {
      quadToTri(pt1[i],pt2[j],&(pts[index].pt[0]),&(pts[index].pt[1]),&dJ);
      pts[index].pt[2] = 0;
      pts[index++].weight = dJ*wt1[i]*wt2[j];
    }
  }
  return index;
}
