/* $Id: CAD.h,v 1.4 2000-11-26 15:43:45 geuzaine Exp $ */
#ifndef _CAD_H_
#define _CAD_H_

#include "Mesh.h"

int NEWREG(void);
int NEWPOINT(void);

Vertex *FindVertex(int inum, Mesh *M);
Curve *FindCurve(int inum, Mesh *M);
Surface *FindSurface(int inum, Mesh *M);
Volume *FindVolume(int inum, Mesh *M);
EdgeLoop *FindEdgeLoop(int inum, Mesh *M);
SurfaceLoop *FindSurfaceLoop(int inum, Mesh *M);

bool ProjectPointOnCurve (Curve *c, Vertex *v, Vertex *RES, Vertex *DER);
bool ProjectPointOnSurface (Surface *s, Vertex &p);
bool ProjectPointOnSurface (Surface *s, Vertex *p,double *u, double *v);

void Extrude_ProtudePoint(int ep, int ip, double A, double B, double C,
                          double X, double Y, double Z, double alpha,
                          Curve **pc, Curve **prc, ExtrudeParams *e);
Surface *Extrude_ProtudeCurve(int ep, int ic,
                              double A, double B, double C,
                              double X, double Y, double Z,
                              double alpha, ExtrudeParams *e);
void Extrude_ProtudeSurface(int ep, int is,
                            double A, double B, double C,
                            double X, double Y, double Z,
                            double alpha,
                            int NewVolume, ExtrudeParams *e);
void ProtudeXYZ ( double &x, double &y, double &z, ExtrudeParams *e);
void ReplaceAllDuplicates ( Mesh *m );
void Coherence_PS(void);

void ModifyLcPoint(int ip, double lc);
void TranslateShapes(double X,double Y,double Z,
                     List_T *ListShapes, int isFinal);
void DilatShapes(double X,double Y,double Z, double A,
                 List_T *ListShapes, int isFinal);
void RotateShapes (double Ax,double Ay,double Az,
                   double Px,double Py, double Pz,
                   double alpha, List_T *ListShapes);
void SymmetryShapes (double A,double B,double C,
                     double D, List_T *ListShapes, int x);
void CopyShape(int Type, int Num, int *New);

void DeletePoint(int ip);
void DeleteCurve(int ip);
void DeleteSurf( int is );
void DeleteShape(int Type, int Num);

Curve * CreateReversedCurve (Mesh *M,Curve *c);

int recognize_seg(int typ, List_T * liste, int *seg);
int recognize_loop(List_T * liste, int *loop);
int recognize_surfloop(List_T * liste, int *loop);


#endif
