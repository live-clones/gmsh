/* $Id: optimesh.cpp,v 1.2 2000-11-23 14:11:24 geuzaine Exp $ */

#include "Gmsh.h"
#include "Adapt.h"
#include "nrutil.h"

#define TOL 1.e-08
#define MAXDEG 999

void frprmn(double p[], int n, double ftol, int *iter, double *fret,
	double (*func)(double []), void (*dfunc)(double [], double []));

extern void SetError(char *, char *);

static int NN,METHOD;
static double MINH , *ERR , *HH , *PP , E0, DIM ;

/* METODE H VERSION 1 : MINIMISER LE NOMBRE D'ELEMENTS
   TOUT EN GARDANT UNE ERREUR GLOBALE DONNEE.  ON MODIFIE
   ICI LE VECTEUR TAILLE DE MAILLE
*/

double fH1 ( double l ){

  int i;
  double val1,val2;

  val1 = 0.0;

  for(i=1;i<=NN;i++){
    val1 += pow(2.*l*DSQR(ERR[i])*PP[i]/DIM,(DIM/(2.*PP[i]+DIM)));
  }
  val2 = 0.0;
  for(i=1;i<=NN;i++){
    val2 += DSQR(ERR[i])*pow(2.*l*DSQR(ERR[i])*PP[i]/DIM,(-2.*PP[i]/(2.*PP[i]+DIM)));
  }
  return -(val1 + l * ( val2 - DSQR(E0)));
}

/* METODE H VERSION 2 : MINIMISER L'ERREUR
   TOUT EN GARDANT UN NOMBRE D'ELEMENTS DONNE.  ON MODIFIE
   ICI LE VECTEUR TAILLE DE MAILLE
*/

double fH2 ( double l ){

  int i;
  double val1,val2,qi;

  val1 = val2 = 0.0;
  for(i=1;i<=NN;i++){
    qi = pow((DIM*l)/(2.*PP[i] * DSQR(ERR[i])) 
	     ,-DIM/(DIM+2.*PP[i]));
    val1 += DSQR(ERR[i]) * pow(qi,-2.*PP[i]/DIM);
    val2 += qi;
  }
/*
  printf( "%12.5e %12.5e\n",l,val1 + l * ( val2 - E0));
*/
  return -(val1 + l * ( val2 - E0));
}


/* METODE P VERSION 1 : MINIMISER LE NOMBRE D'ELEMENTS
   TOUT EN GARDANT UNE ERREUR GLOBALE DONNEE.  ON MODIFIE
   ICI LE VECTEUR DEGRE D'INTERPOLATION
*/

double fP1 ( double l ){

  int i;
  double val1,val2,qi,e;

  val1 = val2 = 0.0;
  for(i=1;i<=NN;i++){
    e = ERR[i];
    if(e==0.0)e=1.e-12;
    qi = - log (2. * l * log (HH[i]/MINH) * DSQR(e)) / log (HH[i]/MINH);
    val1 -= .5 * qi;
    val2 += pow(HH[i]/MINH,qi) * DSQR(e);
  }
/*
  printf( "%12.5e %12.5e\n",l,val1 + l * ( val2 - DSQR(E0)));
*/
  return -(val1 + l * ( val2 - DSQR(E0)));
}


double min1d ( double (*funct)(double), double *xmin){
  double brent(double ax, double bx, double cx,
	      double (*f)(double), double tol, double *xmin);
  void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb,
		double *fc, double (*func)(double));
  double xx,fx,fb,fa,bx,ax;

  switch(METHOD){
  case ADAPT_H1:
  case ADAPT_P1:
    ax=1.e-12;
    xx=1.e2;
    break;
  default:
    ax=1.e-15;
    xx=1.e-12;
    break;
  }    
  mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,funct);
  return brent(ax,xx,bx,funct,TOL,xmin);
}
  

/* optimesh renvoie la contrainte (N0 ou e0) pour le probleme optimise */

double optimesh (int N,        /* Nombre d'elements a traiter        */
		 int method,   /* ADAPT_H1 , ADAPT_P1 , ADAPT_H2 ou ADAPT_P2 */
		 int dim,      /* 2 pour 2D et 3 pour 3D             */
		 double *err,  /* erreurs elementaires               */
		 double *h,    /* tailles de mailles elementaires    */
		 double *p,    /* exposante elementaires             */
		 double e0,    /* erreur prescrite par l'utilisateur */
		 double N0     /* nbre d'elements ds le maillage opt */
		 )
{

  int i;
  double contr,pivrai,lambda,minf,qi,ri,pi,obj,obj2,minri,maxri;
  double errmin,errmax;


  Msg(INFOS, "N=%d Meth=%d dim=%d err[1]=%g err[2]=%g p[1]=%g p[2]=%g prescr=%g",
      N,method,dim,err[1],err[2],p[1],p[2],e0);

  METHOD = method;

  h[N+1] = 1.0;
  p[N+1] = 1.0;

  NN  = N;
  ERR = err;
  HH  = h;
  PP = p;
  NN = N;
  E0 = e0;
  DIM = (double)dim;

  
  for(i=1;i<=N;i++){
    if(i==1){
      errmin=errmax=err[i];
    }
    else{
      errmin = DMIN(errmin,err[i]);
      errmax = DMAX(errmax,err[i]);
    }
  }

  switch (method) {
  case ADAPT_H1 :

    minf = min1d (fH1,&lambda);
    obj = 0.0;
    for(i=1;i<=N;i++){
      qi = pow(2.*lambda*DSQR(err[i])*p[i]/DIM,DIM/(2.*p[i]+DIM));
      ri = pow(qi,1./DIM);
      if(i==1){
		minri=maxri=ri;
      }
      if(err[i]==0.0)ri = .5;

      minri = DMIN(minri,ri);
      maxri = DMAX(maxri,ri);
      obj += DSQR(err[i]) * pow(ri,-2.*p[i]) ; 
      h[i-1] = sqrt(2.) * h[i]/ri;
      p[i-1] = ri;
    }

    contr = fabs(minf);

    Msg(INFOS, "Constraint  : asked %g <==> obtained %g",e0,sqrt(obj));
    Msg(INFOS, "Objective function (Nb. of elements) : %g",-minf);
    Msg(INFOS, "Minimum reduction factor : %g maximum : %g",minri,maxri);
    break;

  case ADAPT_P1 :
    MINH=h[1];
    for(i=1;i<=N;i++){
      MINH =DMIN(h[i],MINH);
    }
    MINH/=2.;

    minf = min1d (fP1,&lambda);
    obj = obj2 = 0.0;
    for(i=1;i<=N;i++){
      qi = -log(2.*lambda*DSQR(err[i])*log(h[i]/MINH))/log(h[i]/MINH);
      pi = p[i] - .5 * qi;
      pivrai = DMIN(DMAX(1.,(double)(int)(pi+.99)),MAXDEG);
      obj2 += pow(h[i]/MINH,2.*(p[i]-pivrai))*DSQR(err[i]);
      obj += DSQR(err[i]) * pow(h[i]/MINH,qi) ; 
      h[i-1] = h[i];
      p[i-1] = pi;
    }
    Msg(INFOS, "Constraint : %g = %g ==> %g",e0,sqrt(obj),sqrt(obj2));
    Msg(INFOS, "Objective function : %g",minf);
    contr = fabs(minf);
    break;

  case ADAPT_H2 :
    minf = min1d (fH2,&lambda);
    obj = 0.0;
    for(i=1;i<=N;i++){
      qi = pow((DIM*lambda)/(2.*DSQR(err[i])*p[i])
	       ,-DIM/(DIM+2.*p[i]));
      ri = pow(qi,1./DIM);
      if(i==1){
	minri=maxri=ri;
      }
      minri = DMIN(minri,ri);
      maxri = DMAX(maxri,ri);
      obj += pow(ri,DIM) ; 
      h[i-1] = h[i]/ri;
      p[i-1] = p[i];
    }

    Msg(INFOS, "Constraint : %g = %g",e0,obj);
    Msg(INFOS, "Objective function (Error in %%) : %g", 100. * sqrt(fabs(minf)));
    Msg(INFOS, "Minri : %g maximum %g",minri,maxri);
    contr = sqrt(fabs(minf));
    break;

  case ADAPT_P2 :
    minf = min1d (fH1,&lambda);
    break;

  default :
    Msg(WARNING, "Unknown mesh optimisation method");
  }

  return contr;
}
