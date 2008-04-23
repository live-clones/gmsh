#ifndef _GaussLegendreSimplex_h_
#define _GaussLegendreSimplex_h_

#include "MElement.h"

int GaussLegendreTet(int n1,int n2, int n3, IntPt *pts); 
int GaussLegendreTri(int n1,int n2,IntPt *pts);
int GaussLegendreHex(int n1, int n2, int n3, IntPt *pts);
#endif
