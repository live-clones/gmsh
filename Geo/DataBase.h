/* $Id: DataBase.h,v 1.2 2000-11-23 14:11:30 geuzaine Exp $ */
#ifndef _DATABASE_H_
#define _DATABASE_H_

void Cdbpts101 (int ip, double x, double y, double z, double l, double w);
void Cdbpts105 (int ip, double x, double y, double z, double l, double w);
void Cdbseg102 (int iseg, int ip, int newp);
void Cdbz102 (int izon, int ip, int newp, int oldp);
void Cdbseg101 (int iseg, int typseg, int degre, List_T * liste, List_T * listint,
		int, int, double, double, char *, char *, char *);
void Cdbpts201 (int ip);
void Cdbseg201 (int ip);
void Cdbz201 (int ip);
void Cdbz101 (int izon, int typzon, int o1, int o2, int nbu, int nbv,
	      int support, List_T * ListCP, List_T * liste, List_T * intlist);
void CreateNurbsSurface (int Num, int Order1, int Order2, List_T *, List_T *, List_T *);
void CreateNurbsSurfaceSupport (int Num, int Order2, int Order1, 
				List_T * List, List_T *, List_T *);
void Cdbseg301 (int ip);
void Cdbz301 (int ip);
void Cdbn101 (int in, double X, double Y, double Z);
void Cdbe101 (int nElm, int iEnt, int nnoe[4]);

void AddCurveInDataBase (int NumCurve, int TypCurve, int Order, List_T * ControlPoints,
			 List_T * Knots, int VertexBeg, int VertexEnd, double uBeg,
			 double uEnd);
void AddCircleInDataBase (int NumCurve, int TypCurve, List_T * ControlPoints,
			  double n[3]);
void AddQuadricSurfaceInDataBase (int Typ, int NumCyl, double zaxis[3], 
				  double xaxis[3], double center[3],
				  double radius1, double radius2,
				  List_T * loops);

#endif
