// $Id: Utils.cpp,v 1.13 2002-05-20 18:28:28 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Interpolation.h"
#include "NRUtil.h"
#include "Context.h"

extern Context_T CTX;

void dsvdcmp(double **a, int m, int n, double w[], double **v);

void direction (Vertex * v1, Vertex * v2, double d[3]){
  d[0] = v2->Pos.X - v1->Pos.X;
  d[1] = v2->Pos.Y - v1->Pos.Y;
  d[2] = v2->Pos.Z - v1->Pos.Z;
}

void Projette (Vertex * v, double mat[3][3]){
  double X, Y, Z;

  X = v->Pos.X * mat[0][0] + v->Pos.Y * mat[0][1] + v->Pos.Z * mat[0][2];
  Y = v->Pos.X * mat[1][0] + v->Pos.Y * mat[1][1] + v->Pos.Z * mat[1][2];
  Z = v->Pos.X * mat[2][0] + v->Pos.Y * mat[2][1] + v->Pos.Z * mat[2][2];
  v->Pos.X = X;
  v->Pos.Y = Y;
  v->Pos.Z = Z;
}

/*
  Le concept d'un plan moyen calcule au sens des moidres carres n'est
  pas le bon pour les surfaces non-planes : imagine un quart de cercle
  extrude d'une faible hauteur. Le plan moyen sera dans le plan du
  cercle! En attendant mieux, il y a donc un test de coherence
  supplementaire pour les surfaces non-planes. */

void MeanPlane(List_T *points, Surface *s){
  int    i, j, min, ndata, na;
  double **U, **V, *W, res[4], ex[3], t1[3], t2[3], svd[3];
  Vertex *v;
  double xm=0., ym=0., zm=0.;

  ndata = List_Nbr(points);
  na = 3;

  U = dmatrix(1,ndata,1,na);
  V = dmatrix(1,na,1,na);
  W = dvector(1,na);

  for (i=0; i<ndata; i++){
    List_Read(points, i, &v);
    xm += v->Pos.X;
    ym += v->Pos.Y;
    zm += v->Pos.Z;
  }
  xm/=(double)ndata;
  ym/=(double)ndata;
  zm/=(double)ndata;

  for (i=0; i<ndata; i++){
    List_Read(points, i, &v);
    U[i+1][1] = v->Pos.X-xm;
    U[i+1][2] = v->Pos.Y-ym;
    U[i+1][3] = v->Pos.Z-zm;
  }
  dsvdcmp(U,ndata,na,W,V);
  if(fabs(W[1])<fabs(W[2]) && fabs(W[1])<fabs(W[3])) min=1;
  else if(fabs(W[2])<fabs(W[1]) && fabs(W[2])<fabs(W[3])) min=2;
  else min=3;
  svd[0] = W[1];
  svd[1] = W[2];
  svd[2] = W[3];
  res[0] = V[1][min];
  res[1] = V[2][min];
  res[2] = V[3][min];
  norme(res);

  free_dmatrix(U,1,ndata,1,na);
  free_dmatrix(V,1,na,1,na);
  free_dvector(W,1,na);

  // check coherence of results for non-plane surfaces
  if(s->Typ != MSH_SURF_PLAN){
    double res2[3], c[3], cosc, sinc, angplan;
    double eps=1.e-3;
    Vertex v1, v2, v3;
    v1 = InterpolateSurface(s,0.5,0.5,0,0);
    v2 = InterpolateSurface(s,0.5+eps,0.5,0,0);
    v3 = InterpolateSurface(s,0.5,0.5+eps,0,0);
    t1[0] = v2.Pos.X-v1.Pos.X;
    t1[1] = v2.Pos.Y-v1.Pos.Y;
    t1[2] = v2.Pos.Z-v1.Pos.Z;
    t2[0] = v3.Pos.X-v1.Pos.X;
    t2[1] = v3.Pos.Y-v1.Pos.Y;
    t2[2] = v3.Pos.Z-v1.Pos.Z;
    norme(t1);
    norme(t2);
    prodve(t1, t2, res2);
    norme(res2);
    prodve (res, res2, c);
    prosca (res, res2, &cosc);
    sinc = sqrt (c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
    angplan = myatan2 (sinc, cosc);
    angplan = angle_02pi(angplan)*180./Pi;
    if((angplan>70 && angplan<110) ||
       (angplan>260 && angplan<280)){
      Msg(INFO, "SVD failed (angle=%g): using rough algo...", angplan);
      res[0]=res2[0];
      res[1]=res2[1];
      res[2]=res2[2];
      goto end;
    }
  }
    
  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0]==0.) 
    ex[0] = 1.0;
  else if(res[1]==0.)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve(res, ex, t1);
  norme(t1);
  prodve (t1, res, t2);
  norme(t2);

end:
  res[3] = (xm*res[0]+ym*res[1]+zm*res[2]);

  for(i=0; i<3; i++) s->plan[0][i] = t1[i];
  for(i=0; i<3; i++) s->plan[1][i] = t2[i];
  for(i=0; i<3; i++) s->plan[2][i] = res[i];

  s->a = res[0];
  s->b = res[1];
  s->c = res[2];
  s->d = res[3];

  Msg(DEBUG1, "Surface: %d", s->Num);
  Msg(DEBUG2, "SVD    : %g,%g,%g (min=%d)", svd[0],svd[1],svd[2],min);
  Msg(DEBUG2, "Plane  : (%g x + %g y + %g z = %g)", s->a, s->b, s->c, s->d);
  Msg(DEBUG2, "Normal : (%g , %g , %g )", s->a, s->b, s->c);
  Msg(DEBUG3, "t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg(DEBUG3, "t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      s->invplan[i][j] = s->plan[j][i];
    }
  }

  //check coherence for plane surfaces
  if(s->Typ==MSH_SURF_PLAN){
    Curve *c;
    for(i=0;i<List_Nbr(s->Generatrices);i++) {
      List_Read(s->Generatrices,i,&c);
      if(c->Num>0){
	List_Read(s->Generatrices,i,&c);
	for(j=0;j<List_Nbr(c->Control_Points);j++){
	  List_Read(c->Control_Points,j,&v);
	  double d = s->a*v->Pos.X+s->b*v->Pos.Y+s->c*v->Pos.Z-s->d;
	  if(fabs(d)>CTX.lc*1.e-3){
	    Msg(GERROR1, "Plane surface %d (%gx+%gy+%gz+%g=0) is not plane!",
		s->Num, s->a, s->b, s->c, s->d);
	    Msg(GERROR3, "Control point %d = (%g,%g,%g), val=%g",
		v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, d);
	    return;
	  }
	}
      }
    }
  }

}


#define  Precision 1.e-10
#define  MaxIter 50

void find_bestuv (Surface * s, double X, double Y,
                  double *U, double *V, double *Z, int N){
  double d, mina, min, minu, minv, Unew, Vnew;
  static int i, j;
  Vertex P;

  d = 1. / (double) N;

  for (i = 0; i <= N; i++){
    for (j = 0; j <= N; j++){
      Unew = ((double) i) * d;
      Vnew = ((double) j) * d;
      P = InterpolateSurface (s, Unew, Vnew, 0, 0);
      if (!i && !j){
        min = myhypot (X - P.Pos.X, Y - P.Pos.Y);
        minu = Unew;
        minv = Vnew;
        *Z = P.Pos.Z;
      }
      else{
        if ((mina = myhypot (X - P.Pos.X, Y - P.Pos.Y)) < min){
          min = mina;
          minu = Unew;
          minv = Vnew;
          *Z = P.Pos.Z;
        }
      }
    }
  }
  *U = minu;
  *V = minv;
}

// Numerical Recipes in C, p. 62
void invert_singular_matrix(double **M, int n, double **I){
  double  **V, **T, *W;
  int     i, j, k; 

  V = dmatrix(1,n,1,n);
  T = dmatrix(1,n,1,n);
  W = dvector(1,n);

  dsvdcmp(M, n, n, W, V);

  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      I[i][j] = 0.0 ;
      T[i][j] = 0.0 ;
    }
  }

#define PREC 1.e-16 //singular value precision
  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      if(fabs(W[i]) > PREC){
        T[i][j] += M[j][i] / W[i] ;
      }
    }
  }
#undef PREC
  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      for(k=1 ; k<=n ; k++){
        I[i][j] += V[i][k] * T[k][j] ;
      }
    }
  }

  free_dmatrix(V,1,n,1,n);
  free_dmatrix(T,1,n,1,n);
  free_dvector(W,1,n);
}

void XYZtoUV (Surface *s, double X, double Y, double Z, double *U, double *V,
	      double relax) {
  double Unew,Vnew,err;
  int    iter;
  Vertex D_u,D_v,P;
  double **mat, **jac ;
  double umin, umax, vmin, vmax;

  if (s->Typ == MSH_SURF_NURBS){
    umin = s->ku[0];
    umax = s->ku[s->OrderU + s->Nu];
    vmin = s->kv[0];
    vmax = s->kv[s->OrderV + s->Nv];
  }
  else{
    umin = vmin = 0.0;
    umax = vmax = 1.0;
  }

  mat = dmatrix(1,3,1,3);
  jac = dmatrix(1,3,1,3);

  *U = *V = 0.487;
  err = 1.0;
  iter = 1;    

  while ( err > Precision && iter < MaxIter ){
    P   = InterpolateSurface(s, *U, *V, 0, 0);
    D_u = InterpolateSurface(s, *U, *V, 1, 1);
    D_v = InterpolateSurface(s, *U, *V, 1, 2);

    mat[1][1] = D_u.Pos.X; 
    mat[1][2] = D_u.Pos.Y; 
    mat[1][3] = D_u.Pos.Z; 
    mat[2][1] = D_v.Pos.X; 
    mat[2][2] = D_v.Pos.Y; 
    mat[2][3] = D_v.Pos.Z; 
    mat[3][1] = 0.; 
    mat[3][2] = 0.; 
    mat[3][3] = 0.; 
    invert_singular_matrix(mat,3,jac);

    Unew = *U + relax * (jac[1][1] * (X-P.Pos.X) + jac[2][1] * (Y-P.Pos.Y) + 
			 jac[3][1] * (Z-P.Pos.Z)) ;
    Vnew = *V + relax * (jac[1][2] * (X-P.Pos.X) + jac[2][2] * (Y-P.Pos.Y) +
			 jac[3][2] * (Z-P.Pos.Z)) ;

    err = DSQR(Unew - *U) + DSQR(Vnew - *V) ;

    iter++;    
    *U = Unew;
    *V = Vnew;
  }

  free_dmatrix(mat,1,3,1,3);
  free_dmatrix(jac,1,3,1,3);

  if(iter == MaxIter ||
     (Unew > umax || Vnew > vmax || Unew < umin || Vnew < vmin)){
    if(relax < 1.e-12)
      Msg(GERROR, "Could not converge: surface mesh will be wrong");
    else{
      Msg(INFO, "Relaxation factor = %g", 0.75*relax);
      XYZtoUV (s, X, Y, Z, U, V, 0.75*relax);
    }
  }

}

void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z, double relax){

  double det, Unew, Vnew, err, mat[2][2], jac[2][2];
  int iter;
  Vertex D_u, D_v, P;
  double umin, umax, vmin, vmax;

  if (s->Typ == MSH_SURF_NURBS){
    umin = s->ku[0];
    umax = s->ku[s->OrderU + s->Nu];
    vmin = s->kv[0];
    vmax = s->kv[s->OrderV + s->Nv];
  }
  else{
    umin = vmin = 0.0;
    umax = vmax = 1.0;
  }

  *U = *V = 0.487;
  err = 1.0;
  iter = 1;

  while (err > Precision && iter < MaxIter){
    P = InterpolateSurface (s, *U, *V, 0, 0);
    D_u = InterpolateSurface (s, *U, *V, 1, 1);
    D_v = InterpolateSurface (s, *U, *V, 1, 2);
    mat[0][0] = D_u.Pos.X;
    mat[0][1] = D_u.Pos.Y;
    mat[1][0] = D_v.Pos.X;
    mat[1][1] = D_v.Pos.Y;
    det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    
    if (det == 0.0){
      iter = MaxIter;
      break;
    }

    jac[0][0] = mat[1][1] / det;
    jac[0][1] = -mat[0][1] / det;
    jac[1][0] = -mat[1][0] / det;
    jac[1][1] = mat[0][0] / det;
    
    Unew = *U + relax * (jac[0][0] * (*X - P.Pos.X) + jac[1][0] * (*Y - P.Pos.Y));
    Vnew = *V + relax * (jac[0][1] * (*X - P.Pos.X) + jac[1][1] * (*Y - P.Pos.Y));
    
    err = DSQR (Unew - *U) + DSQR (Vnew - *V);
    
    iter++;
    *U = Unew;
    *V = Vnew;
  }
  
  *Z = P.Pos.Z;

  int thresh = Unew > umax || Vnew > vmax || Unew < umin || Vnew < vmin;

  if(iter == MaxIter || thresh){
    if(relax < 1.e-6){
      Msg(GERROR, "Could not converge: surface mesh will probably be wrong");
      if(Unew > umax) *U = umax;
      if(Vnew > vmax) *V = vmax;
      if(Unew < umin) *U = umin;
      if(Vnew < vmin) *V = vmin;
      find_bestuv (s, *X, *Y, U, V, Z, 30);
      P = InterpolateSurface (s, *U, *V, 0, 0);
      *X = P.Pos.X;
      *Y = P.Pos.Y;
      *Z = P.Pos.Z;
    }
    else{
      Msg(INFO, "Relaxation factor = %g", 0.75*relax);
      XYtoUV (s, X, Y, U, V, Z, 0.75*relax);
    }
  }

}


int Oriente (List_T * cu, double n[3]){
  int N, i, a, b, c;
  double cosa, sina, sum, v[3], w[3], u[3];
  Vertex *ver[3];

  N = List_Nbr (cu);

  sum = 0.0;
  for (i = 0; i < N; i++){
    if (i == N - 1){
      a = N - 1;
      b = 1;
      c = 2;
    }
    else if (i == N - 2){
      a = N - 2;
      b = N - 1;
      c = 1;
    }
    else{
      a = i;
      b = i + 1;
      c = i + 2;
    }
    List_Read (cu, a, &ver[0]);
    List_Read (cu, b, &ver[1]);
    List_Read (cu, c, &ver[2]);
    
    u[0] = ver[1]->Pos.X - ver[0]->Pos.X;
    u[1] = ver[1]->Pos.Y - ver[0]->Pos.Y;
    u[2] = ver[1]->Pos.Z - ver[0]->Pos.Z;
    
    v[0] = ver[2]->Pos.X - ver[1]->Pos.X;
    v[1] = ver[2]->Pos.Y - ver[1]->Pos.Y;
    v[2] = ver[2]->Pos.Z - ver[1]->Pos.Z;
    norme (u);
    norme (v);
    prodve (u, v, w);
    prosca (w, n, &sina);
    prosca (u, v, &cosa);
    sum += myatan2 (sina, cosa);
  }

  if (sum < 0)
    return (1);
  else
    return (0);
}

double angle_3p (Vertex * V, Vertex * P1, Vertex * P2){
  double PA[3], PB[3], angplan;
  double cosc, sinc, c[3];

  PA[0] = P1->Pos.X - V->Pos.X;
  PA[1] = P1->Pos.Y - V->Pos.Y;
  PA[2] = P1->Pos.Z - V->Pos.Z;

  PB[0] = P2->Pos.X - V->Pos.X;
  PB[1] = P2->Pos.Y - V->Pos.Y;
  PB[2] = P2->Pos.Z - V->Pos.Z;

  norme (PA);
  norme (PB);

  prodve (PA, PB, c);

  prosca (PA, PB, &cosc);
  sinc = sqrt (c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);

  angplan = myatan2 (sinc, cosc);

  return angplan;
}

double angle_plan (Vertex * V, Vertex * P1, Vertex * P2, double n[3]){
  double PA[3], PB[3], angplan;
  double cosc, sinc, c[3];

  PA[0] = P1->Pos.X - V->Pos.X;
  PA[1] = P1->Pos.Y - V->Pos.Y;
  PA[2] = P1->Pos.Z - V->Pos.Z;

  PB[0] = P2->Pos.X - V->Pos.X;
  PB[1] = P2->Pos.Y - V->Pos.Y;
  PB[2] = P2->Pos.Z - V->Pos.Z;

  norme (PA);
  norme (PB);

  prodve (PA, PB, c);

  prosca (PA, PB, &cosc);
  prosca (c, n, &sinc);
  angplan = myatan2 (sinc, cosc);

  return angplan;
}

double angle_3pts (Vertex * a, Vertex * b, Vertex * c){
  double L, prosca, angle;

  L = myhypot ((a->Pos.X - b->Pos.X), (a->Pos.Y - b->Pos.Y)) *
    myhypot ((b->Pos.X - c->Pos.X), (b->Pos.Y - c->Pos.Y));

  prosca = ((a->Pos.X - b->Pos.X) * (c->Pos.X - b->Pos.X) +
            (a->Pos.Y - b->Pos.Y) * (c->Pos.Y - b->Pos.Y)) / L;

  angle = acos (prosca) * 180. / Pi ;
  return (angle);
}

double trapeze (IntPoint * P1, IntPoint * P2){
  return (0.5 * (P1->lc + P2->lc) * (P2->t - P1->t));
}


void RecursiveIntegration (IntPoint * from, IntPoint * to, double (*f) (double X),
                           List_T * pPoints, double Prec, int *depth){
  IntPoint P, p1;
  double err, val1, val2, val3;

  (*depth)++;

  P.t = 0.5 * (from->t + to->t);
  P.lc = f (P.t);

  val1 = trapeze (from, to);
  val2 = trapeze (from, &P);
  val3 = trapeze (&P, to);

  err = fabs (val1 - val2 - val3);
  //  Msg(INFO,"Int %22.15 E %22.15 E %22.15 E\n", val1,val2,val3);
  if (((err < Prec) && (*depth > 1)) || (*depth > 25)){
    List_Read (pPoints, List_Nbr (pPoints) - 1, &p1);
    P.p = p1.p + val2;
    List_Add (pPoints, &P);
    
    List_Read (pPoints, List_Nbr (pPoints) - 1, &p1);
    to->p = p1.p + val3;
    List_Add (pPoints, to);
  }
  else{
    RecursiveIntegration (from, &P, f, pPoints, Prec, depth);
    RecursiveIntegration (&P, to, f, pPoints, Prec, depth);
  }
  (*depth)--;
}

double Integration (double t1, double t2, double (*f) (double X),
                    List_T * pPoints, double Prec){
  int depth;
  IntPoint from, to;

  depth = 0;

  from.t = t1;
  from.lc = f(from.t);
  from.p = 0.0;
  List_Add (pPoints, &from);

  to.t = t2;
  to.lc = f(to.t);
  RecursiveIntegration (&from, &to, f, pPoints, Prec, &depth);
  
  List_Read (pPoints, List_Nbr (pPoints) - 1, &to);
  return (to.p);
}
