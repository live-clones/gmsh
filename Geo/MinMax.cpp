// $Id: MinMax.cpp,v 1.4 2001-01-08 08:05:42 geuzaine Exp $

#include "Gmsh.h"
#include "Const.h"
#include "Vertex.h"
#include "Context.h"

extern Context_T    CTX ;

/* ------------------------------------------------------------------------ */
/*  m i n m a x                                                             */
/* ------------------------------------------------------------------------ */

void minmax(void *a , void*b){
  Vertex *v;
  v = *(Vertex**)a;
  CTX.min[0] = (CTX.min[0] < v->Pos.X) ? CTX.min[0] : v->Pos.X;
  CTX.max[0] = (CTX.max[0] > v->Pos.X) ? CTX.max[0] : v->Pos.X;
  CTX.min[1] = (CTX.min[1] < v->Pos.Y) ? CTX.min[1] : v->Pos.Y;
  CTX.max[1] = (CTX.max[1] > v->Pos.Y) ? CTX.max[1] : v->Pos.Y;
  CTX.min[2] = (CTX.min[2] < v->Pos.Z) ? CTX.min[2] : v->Pos.Z;
  CTX.max[2] = (CTX.max[2] > v->Pos.Z) ? CTX.max[2] : v->Pos.Z;
}

void CalculateMinMax (Tree_T *t){
  Vertex   *v;
  double   frac;
  int      exp;

  if(!Tree_Nbr(t)){
    CTX.min[0] = CTX.min[1] = CTX.min[2] = -1.;
    CTX.max[0] = CTX.max[1] = CTX.max[2] =  1.;
    CTX.range[0] = CTX.range[1] = CTX.range[2] = 0.;
    CTX.lc = CTX.lc_middle = 1.;
    return;
  }

  Tree_Right(t,&v);
  CTX.min[0] = CTX.max[0] = v->Pos.X;
  CTX.min[1] = CTX.max[1] = v->Pos.Y;
  CTX.min[2] = CTX.max[2] = v->Pos.Z;
  Tree_Action(t,minmax);

  CTX.range[0] = CTX.max[0]-CTX.min[0]; 
  CTX.range[1] = CTX.max[1]-CTX.min[1]; 
  CTX.range[2] = CTX.max[2]-CTX.min[2];

  if(CTX.range[0] == 0. && CTX.range[1] == 0. && CTX.range[2] == 0.){
    CTX.min[0] -= 1. ; 
    CTX.min[1] -= 1. ; 
    CTX.max[0] += 1. ; 
    CTX.max[1] += 1. ;
    CTX.lc = 1.;
    CTX.lc_middle = 0.;
  }
  else if(CTX.range[0] == 0. && CTX.range[1] == 0.){
    CTX.lc = CTX.lc_middle = CTX.range[2];
    CTX.min[0] -= CTX.lc; 
    CTX.min[1] -= CTX.lc; 
    CTX.max[0] += CTX.lc; 
    CTX.max[1] += CTX.lc;
  }
  else if(CTX.range[0] == 0. && CTX.range[2] == 0.){
    CTX.lc = CTX.lc_middle = CTX.range[1];
    CTX.min[0] -= CTX.lc; 
    CTX.max[0] += CTX.lc;   
  }
  else if(CTX.range[1] == 0. && CTX.range[2] == 0.){
    CTX.lc = CTX.lc_middle = CTX.range[0];
    CTX.min[1] -= CTX.lc; 
    CTX.max[1] += CTX.lc;   
  }
  else if(CTX.range[0] == 0.){ 
    CTX.lc = sqrt(DSQR(CTX.range[1])+DSQR(CTX.range[2]));
    CTX.lc_middle = DMIN(CTX.range[1], CTX.range[2]);
    CTX.min[0] -= CTX.lc; 
    CTX.max[0] += CTX.lc;
  }
  else if(CTX.range[1] == 0.){ 
    CTX.lc = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[2]));
    CTX.lc_middle = DMIN(CTX.range[0], CTX.range[2]);
    CTX.min[1] -= CTX.lc; 
    CTX.max[1] += CTX.lc;
  }
  else if(CTX.range[2] == 0.){ 
    CTX.lc = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[1]));
    CTX.lc_middle = DMIN(CTX.range[0], CTX.range[1]);
  }
  else{
    CTX.lc = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[1])+DSQR(CTX.range[2]));
    if((CTX.range[1] <= CTX.range[0] && CTX.range[0] <= CTX.range[2]) || 
       (CTX.range[2] <= CTX.range[0] && CTX.range[0] <= CTX.range[1])) 
      CTX.lc_middle = CTX.range[0];
    else if((CTX.range[0] <= CTX.range[1] && CTX.range[1] <= CTX.range[2]) || 
            (CTX.range[2] <= CTX.range[1] && CTX.range[1] <= CTX.range[0])) 
      CTX.lc_middle = CTX.range[1];
    else
      CTX.lc_middle = CTX.range[2];
  }

  /* CTX.lc_order : CTX.lc == f * 10^CTX.lc_order with -1<f<1  */

  frac = frexp(CTX.lc, &exp);     
  CTX.lc_order = (int)floor(log10(ldexp(frac,exp)));
}

