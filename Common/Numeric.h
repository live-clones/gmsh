#ifndef _NUMERIC_H_
#define _NUMERIC_H_

#include <math.h>

#define RADTODEG      57.295779513082321
#define RacineDeDeux  1.4142135623730950
#define RacineDeTrois 1.7320508075688773
#define Pi            3.1415926535897932
#define Deux_Pi       6.2831853071795865

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define SQR(a)   ((a)*(a))

#define IMIN MIN
#define LMIN MIN
#define FMIN MIN
#define DMIN MIN

#define IMAX MAX
#define LMAX MAX
#define FMAX MAX
#define DMAX MAX

#define DSQR SQR
#define FSQR SQU

#define THRESHOLD(a,b,c) (((a)>(c))?(c):((a)<(b)?(b):(a)))

#define myhypot(a,b) (sqrt((a)*(a)+(b)*(b)))
#define sign(x)      (((x)>=0)?1:-1)
#define Pred(x)      ((x)->prev)
#define Succ(x)      ((x)->next)
#define square(x)    ((x)*(x))

double myatan2 (double a, double b);
double myacos (double a);
double myasin (double a);
void prodve (double a[3], double b[3], double c[3]);
void prosca (double a[3], double b[3], double *c);
void norme (double a[3]);
int sys2x2 (double mat[2][2], double b[2], double res[2]);
int sys3x3 (double mat[3][3], double b[3], double res[3], double *det);
int sys3x3_with_tol (double mat[3][3], double b[3], double res[3], double *det);
int det3x3 (double mat[3][3], double *det);
int inv3x3 (double mat[3][3], double inv[3][3], double *det);
double angle_02pi (double A3);

#endif
