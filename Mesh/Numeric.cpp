// $Id: Numeric.cpp,v 1.15 2001-06-02 13:09:14 geuzaine Exp $

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Numeric.h"
#include "Interpolation.h"
#include "nrutil.h"

double myatan2 (double a, double b){
  if (a == 0.0 && b == 0)
    return 0.0;
  return atan2 (a, b);
}

double myacos (double a){
  if (a == 0)
    return Pi * 0.5;
  if (a == 1)
    return 0.0;
  return acos (a);
}

void prodve (double a[3], double b[3], double c[3]){
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

void prosca (double a[3], double b[3], double *c){
  *c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void norme (double a[3]){
  double mod;
  mod = sqrt (a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
  if (mod == 0.0)
    return;
  a[0] /= mod;
  a[1] /= mod;
  a[2] /= mod;
}

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

int sys2x2 (double mat[2][2], double b[2], double res[2]){
  double det, ud, norm;
  int i;

  norm = DSQR (mat[0][0]) + DSQR (mat[1][1]) + DSQR (mat[0][1]) + DSQR (mat[1][0]);
  det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];

  if (norm == 0.0 || fabs (det) / norm < 1.e-07){
    res[0] = res[1] = 0.0 ;
    return 0;
  }
  ud = 1. / det;

  res[0] = b[0] * mat[1][1] - mat[0][1] * b[1];
  res[1] = mat[0][0] * b[1] - mat[1][0] * b[0];

  for (i = 0; i < 2; i++)
    res[i] *= ud;
  return (1);
}

int sys3x3 (double mat[3][3], double b[3], double res[3], double *det){
  double ud;
  int i;

  *det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
    mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
    mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  if (*det == 0.0){
    res[0] = res[1] = res[2] = 0.0 ;
    return (0);
  }

  ud = 1. / (*det);

  res[0] = b[0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
    mat[0][1] * (b[1] * mat[2][2] - mat[1][2] * b[2]) +
    mat[0][2] * (b[1] * mat[2][1] - mat[1][1] * b[2]);

  res[1] = mat[0][0] * (b[1] * mat[2][2] - mat[1][2] * b[2]) -
    b[0] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
    mat[0][2] * (mat[1][0] * b[2] - b[1] * mat[2][0]);

  res[2] = mat[0][0] * (mat[1][1] * b[2] - b[1] * mat[2][1]) -
    mat[0][1] * (mat[1][0] * b[2] - b[1] * mat[2][0]) +
    b[0] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  for (i = 0; i < 3; i++)
    res[i] *= ud;
  return (1);

}

int sys3x3_with_tol (double mat[3][3], double b[3], double res[3], double *det){
  int out;

  out = sys3x3(mat,b,res,det);

  if (fabs(*det) < 1.e-14){
    Msg(DEBUG, "Assuming 3x3 matrix is singular (det == %g)", fabs(*det));
    res[0] = res[1] = res[2] = 0.0 ;
    return (0);
  }

  return out ;
}

int det3x3 (double mat[3][3], double *det){
  *det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
    mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
    mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
  return 1;
}

int inv3x3 (double mat[3][3], double inv[3][3], double *det){
  double ud;

  *det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
    mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
    mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  if (*det == 0.0)
    return (0);

  ud = 1. / (*det);

  inv[0][0] = ud * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
  inv[0][1] = -ud * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
  inv[0][2] = ud * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
  inv[1][0] = -ud * (mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
  inv[1][1] = ud * (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
  inv[1][2] = -ud * (mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);
  inv[2][0] = ud * (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
  inv[2][1] = -ud * (mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
  inv[2][2] = ud * (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
  return (1);

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

  if(iter == MaxIter) Msg(WARNING, "Could not converge in XYZtoUV");

  if(iter > 10) Msg(WARNING, "Many (%d) iterations in XYZtoUV", iter);

  free_dmatrix(mat,1,3,1,3);
  free_dmatrix(jac,1,3,1,3);

}

void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z){

  double det, Unew, Vnew, err, mat[2][2], jac[2][2];
  int iter;
  Vertex D_u, D_v, P;

  /*
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
  */

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
    if (iter == MaxIter)
      break;
    
  }
  
  *Z = P.Pos.Z;

  /*
  if (iter == MaxIter || (fabs (Unew) >= umax || fabs (Vnew) >= vmax) ||
      Vnew < vmin || Unew < umin){
    find_bestuv (s, *X, *Y, U, V, Z, 30);
    P = InterpolateSurface (s, *U, *V, 0, 0);
    
    *X = P.Pos.X;
    *Y = P.Pos.Y;
    *Z = P.Pos.Z;
  }
  */
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

double angle_02pi (double A3){
  double DP = 2 * Pi;
  while (A3 > DP || A3 < 0.){
    if (A3 > 0)
      A3 -= DP;
    else
      A3 += DP;
  }
  return A3;
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
