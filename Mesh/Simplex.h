#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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

#include "Vertex.h"

typedef struct {
  Vertex *V[3];
}Face;

class Simplex{

public:
  int     Num;           /* Numero                                       */
  int     iEnt;          /* Entite geometrique                           */
  char    Visible;       /* Visualization flag                           */
  Face    F[4];          /* 4 faces                                      */
  Vertex  **VSUP;        /* noeuds supplem pour les elts de degre eleves */
  Vertex  *V[4];         /* 4 noeuds                                     */
  double  Quality;       /* Qualite du simplexe                          */
  Coord   Center;        /* centre du CC                                 */
  double  Radius;        /* Rayon du CC                                  */
  Simplex *S[4];         /* 4 Voisins                                    */
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
  int Pt_In_Ellipse (Vertex *v,double m[3][3]);
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
int compareFace (const void *a, const void *b);

Simplex *Create_Simplex (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
void Free_Simplex (void *a, void *b);
Simplex *Create_Quadrangle (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);


#endif
