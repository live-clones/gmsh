// $Id: Numeric.cpp,v 1.1 2001-08-11 23:28:31 geuzaine Exp $

#include "Gmsh.h"
#include "Numeric.h"

// this file should contain only purely numerical routines (that do
// not depend on any Gmsh structures)

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

int sys2x2 (double mat[2][2], double b[2], double res[2]){
  double det, ud, norm;
  int i;

  norm = DSQR (mat[0][0]) + DSQR (mat[1][1]) + DSQR (mat[0][1]) + DSQR (mat[1][0]);
  det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];

  // TOLERANCE ! WARNING WARNING
  if (norm == 0.0 || fabs (det) / norm < 1.e-07){
    Msg(DEBUG, "Assuming 2x2 matrix is singular (det/norm == %g)", fabs(det)/norm);
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
  double norm;

  out = sys3x3(mat,b,res,det);
  norm = 
    DSQR (mat[0][0]) + DSQR (mat[0][1]) + DSQR (mat[0][2]) + 
    DSQR (mat[1][0]) + DSQR (mat[1][1]) + DSQR (mat[1][2]) + 
    DSQR (mat[2][0]) + DSQR (mat[2][1]) + DSQR (mat[2][2]) ;

  // TOLERANCE ! WARNING WARNING
  if (norm == 0.0 || fabs (*det) / norm < 1.e-12){
    Msg(DEBUG, "Assuming 3x3 matrix is singular (det/norm == %g)", fabs(*det)/norm);
    res[0] = res[1] = res[2] = 0.0 ;
    return 0;
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

