/* $Id: MinMax.cpp,v 1.2 2000-11-23 14:11:30 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Vertex.h"
#include "Context.h"

extern Context_T    CTX ;

extern double       LC, MiddleLC;
extern int          LC_ORDER;

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
    LC = MiddleLC = 1.;
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
    LC = 1.;
    MiddleLC = 0.;
  }
  else if(CTX.range[0] == 0. && CTX.range[1] == 0.){
    LC = MiddleLC = CTX.range[2];
    CTX.min[0] -= LC; 
    CTX.min[1] -= LC; 
    CTX.max[0] += LC; 
    CTX.max[1] += LC;
  }
  else if(CTX.range[0] == 0. && CTX.range[2] == 0.){
    LC = MiddleLC = CTX.range[1];
    CTX.min[0] -= LC; 
    CTX.max[0] += LC;   
  }
  else if(CTX.range[1] == 0. && CTX.range[2] == 0.){
    LC = MiddleLC = CTX.range[0];
    CTX.min[1] -= LC; 
    CTX.max[1] += LC;   
  }
  else if(CTX.range[0] == 0.){ 
    LC = sqrt(DSQR(CTX.range[1])+DSQR(CTX.range[2]));
    MiddleLC = DMIN(CTX.range[1], CTX.range[2]);
    CTX.min[0] -= LC; 
    CTX.max[0] += LC;
  }
  else if(CTX.range[1] == 0.){ 
    LC = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[2]));
    MiddleLC = DMIN(CTX.range[0], CTX.range[2]);
    CTX.min[1] -= LC; 
    CTX.max[1] += LC;
  }
  else if(CTX.range[2] == 0.){ 
    LC = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[1]));
    MiddleLC = DMIN(CTX.range[0], CTX.range[1]);
  }
  else{
    LC = sqrt(DSQR(CTX.range[0])+DSQR(CTX.range[1])+DSQR(CTX.range[2]));
    if((CTX.range[1] <= CTX.range[0] && CTX.range[0] <= CTX.range[2]) || 
       (CTX.range[2] <= CTX.range[0] && CTX.range[0] <= CTX.range[1])) 
      MiddleLC = CTX.range[0];
    else if((CTX.range[0] <= CTX.range[1] && CTX.range[1] <= CTX.range[2]) || 
	    (CTX.range[2] <= CTX.range[1] && CTX.range[1] <= CTX.range[0])) 
      MiddleLC = CTX.range[1];
    else
      MiddleLC = CTX.range[2];
  }

  /* LC_ORDER : LC == f * 10^LC_ORDER with -1<f<1  */

  frac = frexp(LC, &exp);     
  LC_ORDER = (int)floor(log10(ldexp(frac,exp)));
}

