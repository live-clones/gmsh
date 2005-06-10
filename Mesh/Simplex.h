#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "List.h"
#include "Tree.h"
#include "Vertex.h"
#include "Element.h"
#include "Face.h"

class SimplexBase : public Element {
 public:
  Vertex  *V[4];         // 4 nodes
  SimplexBase();
  ~SimplexBase() {}
  SimplexBase(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  double Volume_Simplexe();
  double Volume_Simplexe2D();
  double matsimpl(double mat[3][3]);
  void center_tet(double X[4],double Y[4], double Z[4], double res[3]);
  double AireFace(Vertex *V[3]);
  double surfsimpl();
  double GammaShapeMeasure();
  double EtaShapeMeasure();
  double rhoin();
  double maxEdge();
  double minEdge();
  void ExportStatistics(FILE *f);
};

SimplexBase *Create_SimplexBase(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
void Free_SimplexBase(void *a, void *b);
int compareSimplexBase(const void *a, const void *b);

class Simplex : public SimplexBase {
 public:
  Face    F[4];          // 4 faces
  double  Quality;       // simplex quality
  Coord   Center;        // CC center
  double  Radius;        // CC radius
  Simplex *S[4];         // 4 neighbours
  Simplex();
  ~Simplex() {}
  Simplex(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  void Fourre_Simplexe(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  int Pt_In_Simplexe(Vertex *v, double uvw[3], double tol);
  int Pt_In_Simplex_2D(Vertex *v);
  void Center_Circum();
  int CircumCircle(double x1,double y1,double x2,double y2,double x3,double y3,
                   double *xc,double *yc);
  void Center_Ellipsum_2D(double m[3][3]);
  int Pt_In_Ellipse(Vertex *v,double m[3][3]);
  bool VertexIn(Vertex *v);
  bool EdgeIn(Vertex *v1, Vertex *v2, Vertex *v[2]);
  bool SwapEdge(int iFac);
  bool SwapFace(int iFac, List_T *newsimp, List_T *delsimp);
  bool ExtractOppositeEdges( int iFac, Vertex *p[2], Vertex *q[2]);
  void Center_Ellipsum_3D(double m[3][3]);
};

int compareSimplex(const void *a, const void *b);
int compareFace(const void *a, const void *b);

Simplex *Create_Simplex (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
void Free_Simplex(void *a, void *b);

void Move_SimplexBaseToSimplex(Tree_T **base, Tree_T *simp);

#endif
