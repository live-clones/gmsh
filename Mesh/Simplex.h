/* $Id: Simplex.h,v 1.3 2000-11-23 15:05:59 geuzaine Exp $ */
#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include "Vertex.h"

typedef struct {
  Vertex *V[3];
}Face;

class Simplex{

public:
  int     Num;           /* Numero                                       */
  int     iEnt;          /* Entite geometrique                           */
  Face    F[4];          /* 4 faces                                      */
  Vertex  **VSUP;        /* noeuds supplem pour les elts de degre eleves */
  Vertex  *V[4];         /* 4 noeuds                                     */
  double  Quality;       /* Qualite du simplexe                          */
  Coord   Center;        /* centre du CC                                 */
  double  Radius;        /* Rayon du CC                                  */
  Simplex *S[4];    	 /* 4 Voisins                                    */
  static  int TotalNumber;
  static  int TotalAllocated;
  Simplex();
  ~Simplex();
  Simplex(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  void Fourre_Simplexe(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  int Pt_In_Simplexe (Vertex *v, double uvw[3], double tol);
  int Pt_In_Simplex_2D(Vertex *v);
  void Center_Circum();
  double Volume_Simplexe ();
  double matsimpl(double mat[3][3]);
  void center_tet(double X[4],double Y[4], double Z[4], double res[3]);
  double AireFace (Vertex *V[3]);
  double surfsimpl();
  int CircumCircle(double x1,double y1,double x2,double y2,double x3,double y3,
		   double *xc,double *yc);
  double Volume_Simplexe2D();
  void Center_Ellipsum_2D (double m[3][3]);
  int Pt_In_Ellipsis (Vertex *v,double m[3][3]);
  bool VertexIn(Vertex *v);
  bool EdgeIn(Vertex *v1, Vertex *v2, Vertex *v[2]);
  bool SwapEdge (int iFac);
  bool SwapFace (int iFac, List_T *newsimp, List_T *delsimp);
  bool ExtractOppositeEdges ( int iFac, Vertex *p[2], Vertex *q[2]);
  void ExportLcField (FILE *f);
  void Center_Ellipsum_3D (double m[3][3]);
  double GammaShapeMeasure ();
  double RhoShapeMeasure ();
  double EtaShapeMeasure ();
  double lij (int i, int j);
  double rhoin ();
};

int compareSimplex(const void *a, const void *b);
Simplex *Create_Simplex (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
Simplex *Create_Quadrangle (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
int compareFace (const void *a, const void *b);

#endif
