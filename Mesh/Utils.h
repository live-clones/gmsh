#ifndef _UTILS_H_
#define _UTILS_H_

void direction (Vertex * v1, Vertex * v2, double d[3]);
void Projette (Vertex * v, double mat[3][3]);
void MeanPlane(List_T *point, Surface *s);
void find_bestuv (Surface * s, double X, double Y,
                  double *U, double *V, double *Z, int N);
void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z);
void XYZtoUV (Surface *s, double X, double Y, double Z, double *U, double *V);
int Oriente (List_T * cu, double n[3]);
double angle_3p (Vertex * V, Vertex * P1, Vertex * P2);
double angle_plan (Vertex * V, Vertex * P1, Vertex * P2, double n[3]);
double angle_3pts (Vertex * a, Vertex * b, Vertex * c);
double trapeze (IntPoint * P1, IntPoint * P2);
void RecursiveIntegration (IntPoint * from, IntPoint * to, double (*f) (double X),
                           List_T * pPoints, double Prec, int *depth);
double Integration (double t1, double t2, double (*f) (double X),
                    List_T * pPoints, double Prec);

#endif
