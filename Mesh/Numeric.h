/* $Id: Numeric.h,v 1.4 2000-12-18 08:31:58 geuzaine Exp $ */
#ifndef _NUMERIC_H_
#define _NUMERIC_H_

double myatan2 (double a, double b);
double myacos (double a);
void prodve (double a[3], double b[3], double c[3]);
void prosca (double a[3], double b[3], double *c);
void norme (double a[3]);
void direction (Vertex * v1, Vertex * v2, double d[3]);
void Projette (Vertex * v, double mat[3][3]);
int sys2x2 (double mat[2][2], double b[2], double res[2]);
int sys3x3 (double mat[3][3], double b[3], double res[3], double *det);
int sys3x3_with_tol (double mat[3][3], double b[3], double res[3], double *det);
int det3x3 (double mat[3][3], double *det);
int inv3x3 (double mat[3][3], double inv[3][3], double *det);
void find_bestuv (Surface * s, double X, double Y,
                  double *U, double *V, double *Z, int N);
void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z);
void XYZtoUV (Surface *s, double X, double Y, double Z, double *U, double *V);
int Oriente (List_T * cu, double n[3]);
double angle_02pi (double A3);
double angle_3p (Vertex * V, Vertex * P1, Vertex * P2);
double angle_plan (Vertex * V, Vertex * P1, Vertex * P2, double n[3]);
double angle_3pts (Vertex * a, Vertex * b, Vertex * c);
double trapeze (IntPoint * P1, IntPoint * P2);
void RecursiveIntegration (IntPoint * from, IntPoint * to, double (*f) (double X),
                           List_T * pPoints, double Prec, int *depth);
double Integration (double t1, double t2, double (*f) (double X),
                    List_T * pPoints, double Prec);

#endif
