// $Id: Utils.cpp,v 1.2 2001-08-12 20:45:58 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Interpolation.h"
#include "nrutil.h"
#include "Context.h"

extern Context_T CTX;

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

void MeanPlane(List_T *points, Surface *s){
  int       i, j, ix, iy, iz, N;
  double    det,sys[3][3],b[3],res[3],mod,t1[3],t2[3],ex[3],s2s[2][2],r2[2],X,Y,Z;
  Vertex   *v;

  N = List_Nbr (points);

  for (i = 0; i < 3; i++){
    b[i] = 0.0;
    for (j = 0; j < 3; j++){
      sys[i][j] = 0.0;
    }
  }

  /* ax + by + cz = 1 */

  ix = iy = iz = 0;

  // TOLERANCE ! WARNING WARNING
  double eps = 1.e-6 * CTX.lc;

  for (i = 0; i < N; i++){
    List_Read (points, i, &v);

    if (!i){
      X = v->Pos.X;
      Y = v->Pos.Y;
      Z = v->Pos.Z;
    }
    else{
      if(fabs(X-v->Pos.X) > eps) ix = 1;
      if(fabs(Y-v->Pos.Y) > eps) iy = 1;
      if(fabs(Z-v->Pos.Z) > eps) iz = 1;
    }
    
    sys[0][0] += v->Pos.X * v->Pos.X;
    sys[1][1] += v->Pos.Y * v->Pos.Y;
    sys[2][2] += v->Pos.Z * v->Pos.Z;
    sys[0][1] += v->Pos.X * v->Pos.Y;
    sys[0][2] += v->Pos.X * v->Pos.Z;
    sys[1][2] += v->Pos.Y * v->Pos.Z;
    sys[2][1] = sys[1][2];
    sys[1][0] = sys[0][1];
    sys[2][0] = sys[0][2];
    b[0] += v->Pos.X;
    b[1] += v->Pos.Y;
    b[2] += v->Pos.Z;
  }

  s->d = 1.0;

  /* x = X */

  if (!ix){
    s->d = X;
    res[0] = 1.;
    res[1] = res[2] = 0.0;
    Msg(DEBUG, "Mean plane of type 'x = c'");
  }

  /* y = Y */

  else if (!iy){
    s->d = Y;
    res[1] = 1.;
    res[0] = res[2] = 0.0;
    Msg(DEBUG, "Mean plane of type 'y = c'");
  }

  /* z = Z */

  else if (!iz){
    s->d = Z;
    res[2] = 1.;
    res[1] = res[0] = 0.0;
    Msg(DEBUG, "Mean plane of type 'z = c'");
  }

  /* by + cz = -x */

  else if (!sys3x3_with_tol (sys, b, res, &det)){
    s->d = 0.0;
    s2s[0][0] = sys[1][1];
    s2s[0][1] = sys[1][2];
    s2s[1][0] = sys[1][2];
    s2s[1][1] = sys[2][2];
    b[0] = -sys[0][1];
    b[1] = -sys[0][2];
    if (sys2x2 (s2s, b, r2)){
      res[0] = 1.;
      res[1] = r2[0];
      res[2] = r2[1];
      Msg(DEBUG, "Mean plane of type 'by + cz = -x'");
    }

    /* ax + cz = -y */
    
    else{
      s->d = 0.0;
      s2s[0][0] = sys[0][0];
      s2s[0][1] = sys[0][2];
      s2s[1][0] = sys[0][2];
      s2s[1][1] = sys[2][2];
      b[0] = -sys[0][1];
      b[1] = -sys[1][2];
      if (sys2x2 (s2s, b, r2)){
        res[0] = r2[0];
        res[1] = 1.;
        res[2] = r2[1];
        Msg(DEBUG, "Mean plane of type 'ax + cz = -y'");
      }
      
      /* ax + by = -z */
      
      else{
        s->d = 1.0;
        s2s[0][0] = sys[0][0];
        s2s[0][1] = sys[0][1];
        s2s[1][0] = sys[0][1];
        s2s[1][1] = sys[1][1];
        b[0] = -sys[0][2];
        b[1] = -sys[1][2];
        if (sys2x2 (s2s, b, r2)){
          res[0] = r2[0];
          res[1] = r2[1];
          res[2] = 1.;
          Msg(DEBUG, "Mean plane of type 'ax + by = -z'");
        }
        else{
          Msg(GERROR, "Problem in mean plane computation");
        }
      }
    }
  }

  s->a = res[0];
  s->b = res[1];
  s->c = res[2];
  mod = sqrt (res[0] * res[0] + res[1] * res[1] + res[2] * res[2]);
  for (i = 0; i < 3; i++)
    res[i] /= mod;

  /* L'axe n'est pas l'axe des x */

  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0] == 0.0)
    ex[0] = 1.0;
  else if(res[1] == 0.0)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve (res, ex, t1);

  mod = sqrt (t1[0] * t1[0] + t1[1] * t1[1] + t1[2] * t1[2]);
  for (i = 0; i < 3; i++)
    t1[i] /= mod;

  prodve (t1, res, t2);

  mod = sqrt (t2[0] * t2[0] + t2[1] * t2[1] + t2[2] * t2[2]);
  for (i = 0; i < 3; i++)
    t2[i] /= mod;

  for (i = 0; i < 3; i++)
    s->plan[0][i] = t1[i];
  for (i = 0; i < 3; i++)
    s->plan[1][i] = t2[i];
  for (i = 0; i < 3; i++)
    s->plan[2][i] = res[i];

  Msg(DEBUG1, "Plane  : (%g x + %g y + %g z = %g)", s->a, s->b, s->c, s->d);
  Msg(DEBUG2, "Normal : (%g , %g , %g )", res[0], res[1], res[2]);
  Msg(DEBUG2, "t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg(DEBUG3, "t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);

  /* Matrice orthogonale */

  if (!iz){
    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        s->invplan[i][j] = (i == j) ? 1. : 0.;
        s->plan[i][j] = (i == j) ? 1. : 0.;
      }
    }
  }
  else{
    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        s->invplan[i][j] = s->plan[j][i];
      }
    }
  }


// this is the end of the algo as it was used for surface drawing:

#if 0
  /* L'axe n'est pas l'axe des x */
  if(res[0] > res[1]){
    ex[0] = 0.;
    ex[1] = 1.;
    ex[2] = 0.;
  }
  else{
    ex[0] = 1.;
    ex[1] = 0.;
    ex[2] = 0.;
  }
  
  prodve(res,ex,t1);
  
  mod = sqrt (t1[0] * t1[0] + t1[1] * t1[1] + t1[2] * t1[2] ) ;
  for(i=0;i<3;i++) t1[i]/=mod;

  prodve(t1,res,t2);

  mod = sqrt (t2[0] * t2[0] + t2[1] * t2[1] + t2[2] * t2[2] ) ;
  for(i=0;i<3;i++) t2[i]/=mod;

  for(i=0;i<3;i++)s->plan[0][i] = t1[i];
  for(i=0;i<3;i++)s->plan[1][i] = t2[i];
  for(i=0;i<3;i++)s->plan[2][i] = res[i];

  /* Matrice orthogonale */

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      s->invplan[i][j] = s->plan[j][i];
    }
  }
#endif
}



#define  Precision 1.e-10
#define  MaxIter 20

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

void invert_singular_matrix(double **M, int n, double **I);

void XYZtoUV (Surface *s, double X, double Y, double Z, double *U, double *V) {
  double Unew,Vnew,err;
  int    iter;
  Vertex D_u,D_v,P;
  double **mat, **jac ;

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

    Unew = *U + jac[1][1] * (X-P.Pos.X) + jac[2][1] * (Y-P.Pos.Y) + jac[3][1] * (Z-P.Pos.Z) ;
    Vnew = *V + jac[1][2] * (X-P.Pos.X) + jac[2][2] * (Y-P.Pos.Y) + jac[3][2] * (Z-P.Pos.Z) ;

    err = DSQR(Unew - *U) + DSQR(Vnew - *V) ;

    iter++;    
    *U = Unew;
    *V = Vnew;
  }

  if(iter > 10){
    if(iter == MaxIter) Msg(WARNING, "Could not converge in XYZtoUV");
    else Msg(WARNING, "Many (%d) iterations in XYZtoUV", iter);
  }

  free_dmatrix(mat,1,3,1,3);
  free_dmatrix(jac,1,3,1,3);

}

void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z){

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
    
    Unew = *U + 1.0 * (jac[0][0] * (*X - P.Pos.X) + jac[1][0] * (*Y - P.Pos.Y));
    Vnew = *V + 1.0 * (jac[0][1] * (*X - P.Pos.X) + jac[1][1] * (*Y - P.Pos.Y));
    
    err = DSQR (Unew - *U) + DSQR (Vnew - *V);
    
    iter++;
    *U = Unew;
    *V = Vnew;
  }
  
  *Z = P.Pos.Z;

  if(iter > 10){
    if(iter == MaxIter) Msg(WARNING, "Could not converge in XYtoUV");
    else Msg(WARNING, "Many (%d) iterations in XYtoUV...", iter);
  }

  if (Unew > umax || Vnew > vmax || Unew < umin || Vnew < vmin){
    Msg(WARNING, "(U,V) thresholded in XYtoUV (surface mesh may be wrong)");
    if(Unew > umax) *U = umax;
    if(Vnew > vmax) *V = vmax;
    if(Unew < umin) *U = umin;
    if(Vnew < vmin) *V = vmin;
  }

#if 0
  if (iter == MaxIter || Unew > umax || Vnew > vmax || Unew < umin || Vnew < vmin){
    static int first_try=1;
    if(first_try){
      Msg(WARNING, "Entering rescue mode in XYtoUV...");
      first_try=0;
    }
    find_bestuv (s, *X, *Y, U, V, Z, 30);
    P = InterpolateSurface (s, *U, *V, 0, 0);
    
    *X = P.Pos.X;
    *Y = P.Pos.Y;
    *Z = P.Pos.Z;
  }
#endif
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

  if ((err < Prec) && (*depth > 1)){
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
