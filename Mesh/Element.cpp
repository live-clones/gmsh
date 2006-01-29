// $Id: Element.cpp,v 1.11 2006-01-29 20:32:48 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Mesh.h"
#include "Numeric.h"
#include "Element.h"

extern int edges_quad[4][2];
extern int edges_hexa[12][2];
extern int edges_prism[9][2];
extern int edges_pyramid[8][2];

int Element::TotalNumber = 0;

Element::Element()
  : iEnt(-1), iPart(-1), Visible(VIS_MESH), VSUP(NULL)
{
  Num = ++TotalNumber; 
}

Element::~Element()
{
  if(VSUP) Free(VSUP);
}

double Element::lij(Vertex *Vi, Vertex *Vj)
{
  return sqrt(DSQR(Vi->Pos.X - Vj->Pos.X) +
              DSQR(Vi->Pos.Y - Vj->Pos.Y) +
              DSQR(Vi->Pos.Z - Vj->Pos.Z));
}

double Element::RhoShapeMeasure()
{
  double min = minEdge();
  double max = maxEdge();
  if(max)
    return min/max;
  else
    return 0.;
}

// Quads

Quadrangle::Quadrangle()
  : Element()
{
  for(int i = 0; i < 4; i++) V[i] = NULL;
}

Quadrangle::Quadrangle(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4)
  : Element()
{
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4;
}

double Quadrangle::maxEdge()
{
  double maxlij = 0.;
  for(int i = 0; i < 4; i++)
      maxlij = DMAX(maxlij, lij(V[edges_quad[i][0]], V[edges_quad[i][1]]));
  return maxlij;
}

double Quadrangle::minEdge()
{
  double minlij = 1.e25;
  for(int i = 0; i < 4; i++)
      minlij = DMIN(minlij, lij(V[edges_quad[i][0]], V[edges_quad[i][1]]));
  return minlij;
}

Quadrangle *Create_Quadrangle(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4)
{
  return new Quadrangle(v1, v2, v3, v4);
}

void Quadrangle::ExportStatistics(FILE * f)
{
  int N = 4, NSUP = VSUP ? 5 : 0;
  double g = 0.;
  double e = 0.;
  double r = RhoShapeMeasure();
  print_elm_stats(f, Num, iEnt, g, e, r, "SQ", N, V, "SQ2", NSUP, VSUP);
}

void Free_Quadrangle(void *a, void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  if(q) {
    delete q;
    q = NULL;
  }
}

int compareQuadrangle(const void *a, const void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  Quadrangle *w = *(Quadrangle **) b;
  return (q->Num - w->Num);
}

// Hexas

Hexahedron::Hexahedron()
  : Element()
{
  for(int i = 0; i < 8; i++) V[i] = NULL;
}

Hexahedron::Hexahedron(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4,
		       Vertex *v5, Vertex *v6, Vertex *v7, Vertex *v8)
  : Element()
{
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4;
  V[4] = v5; V[5] = v6; V[6] = v7; V[7] = v8;
}

double Hexahedron::Orientation()
{
  double mat[3][3];
  mat[0][0] = V[1]->Pos.X - V[0]->Pos.X;
  mat[0][1] = V[3]->Pos.X - V[0]->Pos.X;
  mat[0][2] = V[4]->Pos.X - V[0]->Pos.X;
  mat[1][0] = V[1]->Pos.Y - V[0]->Pos.Y;
  mat[1][1] = V[3]->Pos.Y - V[0]->Pos.Y;
  mat[1][2] = V[4]->Pos.Y - V[0]->Pos.Y;
  mat[2][0] = V[1]->Pos.Z - V[0]->Pos.Z;
  mat[2][1] = V[3]->Pos.Z - V[0]->Pos.Z;
  mat[2][2] = V[4]->Pos.Z - V[0]->Pos.Z;
  return det3x3(mat);
}

double Hexahedron::maxEdge()
{
  double maxlij = 0.;
  for(int i = 0; i < 12; i++)
      maxlij = DMAX(maxlij, lij(V[edges_hexa[i][0]], V[edges_hexa[i][1]]));
  return maxlij;
}

double Hexahedron::minEdge()
{
  double minlij = 1.e25;
  for(int i = 0; i < 12; i++)
      minlij = DMIN(minlij, lij(V[edges_hexa[i][0]], V[edges_hexa[i][1]]));
  return minlij;
}

Hexahedron *Create_Hexahedron(Vertex * v1, Vertex * v2, Vertex * v3,
                              Vertex * v4, Vertex * v5, Vertex * v6,
                              Vertex * v7, Vertex * v8)
{
  return new Hexahedron(v1, v2, v3, v4, v5, v6, v7, v8);
}

void Hexahedron::ExportStatistics(FILE * f)
{
  int N = 8, NSUP = VSUP ? 19 : 0;
  double g = 0.;
  double e = 0.;
  double r = RhoShapeMeasure();
  print_elm_stats(f, Num, iEnt, g, e, r, "SH", N, V, "SH2", NSUP, VSUP);
}

void Free_Hexahedron(void *a, void *b)
{
  Hexahedron *h = *(Hexahedron **) a;
  if(h) {
    delete h;
    h = NULL;
  }
}

int compareHexahedron(const void *a, const void *b)
{
  Hexahedron *q = *(Hexahedron **) a;
  Hexahedron *w = *(Hexahedron **) b;
  return (q->Num - w->Num);
}

// Prisms

Prism::Prism()
  : Element()
{
  for(int i = 0; i < 6; i++) V[i] = NULL;
}

Prism::Prism(Vertex *v1, Vertex *v2, Vertex *v3, 
	     Vertex *v4, Vertex *v5, Vertex *v6)
  : Element()
{
  V[0] = v1; V[1] = v2; V[2] = v3; 
  V[3] = v4; V[4] = v5; V[5] = v6;
}

double Prism::Orientation()
{
  double mat[3][3];
  mat[0][0] = V[1]->Pos.X - V[0]->Pos.X;
  mat[0][1] = V[2]->Pos.X - V[0]->Pos.X;
  mat[0][2] = V[3]->Pos.X - V[0]->Pos.X;
  mat[1][0] = V[1]->Pos.Y - V[0]->Pos.Y;
  mat[1][1] = V[2]->Pos.Y - V[0]->Pos.Y;
  mat[1][2] = V[3]->Pos.Y - V[0]->Pos.Y;
  mat[2][0] = V[1]->Pos.Z - V[0]->Pos.Z;
  mat[2][1] = V[2]->Pos.Z - V[0]->Pos.Z;
  mat[2][2] = V[3]->Pos.Z - V[0]->Pos.Z;
  return det3x3(mat);
}

double Prism::maxEdge()
{
  double maxlij = 0.;
  for(int i = 0; i < 9; i++)
      maxlij = DMAX(maxlij, lij(V[edges_prism[i][0]], V[edges_prism[i][1]]));
  return maxlij;
}

double Prism::minEdge()
{
  double minlij = 1.e25;
  for(int i = 0; i < 9; i++)
      minlij = DMIN(minlij, lij(V[edges_prism[i][0]], V[edges_prism[i][1]]));
  return minlij;
}

Prism *Create_Prism(Vertex * v1, Vertex * v2, Vertex * v3,
                    Vertex * v4, Vertex * v5, Vertex * v6)
{
  return new Prism(v1, v2, v3, v4, v5, v6);
}

void Prism::ExportStatistics(FILE * f)
{
  int N = 6, NSUP = VSUP ? 12 : 0;
  double g = 0.;
  double e = 0.;
  double r = RhoShapeMeasure();
  print_elm_stats(f, Num, iEnt, g, e, r, "SI", N, V, "SI2", NSUP, VSUP);
}

void Free_Prism(void *a, void *b)
{
  Prism *p = *(Prism **) a;
  if(p) {
    delete p;
    p = NULL;
  }
}

int comparePrism(const void *a, const void *b)
{
  Prism *q = *(Prism **) a;
  Prism *w = *(Prism **) b;
  return (q->Num - w->Num);
}

// Pyramids

Pyramid::Pyramid()
  : Element()
{
  for(int i = 0; i < 5; i++) V[i] = NULL;
}

Pyramid::Pyramid(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4, Vertex *v5)
  : Element()
{
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4; V[4] = v5; 
}

double Pyramid::Orientation()
{
  double mat[3][3];
  mat[0][0] = V[1]->Pos.X - V[0]->Pos.X;
  mat[0][1] = V[3]->Pos.X - V[0]->Pos.X;
  mat[0][2] = V[4]->Pos.X - V[0]->Pos.X;
  mat[1][0] = V[1]->Pos.Y - V[0]->Pos.Y;
  mat[1][1] = V[3]->Pos.Y - V[0]->Pos.Y;
  mat[1][2] = V[4]->Pos.Y - V[0]->Pos.Y;
  mat[2][0] = V[1]->Pos.Z - V[0]->Pos.Z;
  mat[2][1] = V[3]->Pos.Z - V[0]->Pos.Z;
  mat[2][2] = V[4]->Pos.Z - V[0]->Pos.Z;
  return det3x3(mat);
}

double Pyramid::maxEdge()
{
  double maxlij = 0.;
  for(int i = 0; i < 8; i++)
      maxlij = DMAX(maxlij, lij(V[edges_pyramid[i][0]], V[edges_pyramid[i][1]]));
  return maxlij;
}

double Pyramid::minEdge()
{
  double minlij = 1.e25;
  for(int i = 0; i < 8; i++)
      minlij = DMIN(minlij, lij(V[edges_pyramid[i][0]], V[edges_pyramid[i][1]]));
  return minlij;
}

Pyramid *Create_Pyramid(Vertex * v1, Vertex * v2, Vertex * v3,
                        Vertex * v4, Vertex * v5)
{
  return new Pyramid(v1, v2, v3, v4, v5);
}

void Pyramid::ExportStatistics(FILE * f)
{
  int N = 5, NSUP = VSUP ? 9 : 0;
  double g = 0.;
  double e = 0.;
  double r = RhoShapeMeasure();
  print_elm_stats(f, Num, iEnt, g, e, r, "SY", N, V, "SY2", NSUP, VSUP);
}

void Free_Pyramid(void *a, void *b)
{
  Pyramid *p = *(Pyramid **) a;
  if(p) {
    delete p;
    p = NULL;
  }
}

int comparePyramid(const void *a, const void *b)
{
  Pyramid *q = *(Pyramid **) a;
  Pyramid *w = *(Pyramid **) b;
  return (q->Num - w->Num);
}

// dump an element in a parsed post-processing view

void print_elm_stats(FILE *f, int Num, int Ent, double Gamma, double Eta, double Rho, 
		     const char *S, int N, Vertex **V, 
		     const char *SSUP, int NSUP, Vertex **VSUP)
{
  fprintf(f, "%s(", NSUP ? SSUP : S);
  for(int i = 0; i < N; i++){
    if(i) fprintf(f, ",");
    fprintf(f, "%g,%g,%g", V[i]->Pos.X, V[i]->Pos.Y, V[i]->Pos.Z);
  }
  for(int i = 0; i < NSUP; i++){
    fprintf(f, ",%g,%g,%g", VSUP[i]->Pos.X, VSUP[i]->Pos.Y, VSUP[i]->Pos.Z);
  }
  fprintf(f, "){");
  for(int i = 0; i < N+NSUP; i++)
    fprintf(f, "%d,", Ent);
  for(int i = 0; i < N+NSUP; i++)
    fprintf(f, "%d,", Num);
  for(int i = 0; i < N; i++)
    fprintf(f, "%g,", V[i]->lc);
  for(int i = 0; i < NSUP; i++)
    fprintf(f, "%g,", VSUP[i]->lc);
  for(int i = 0; i < N+NSUP; i++)
    fprintf(f, "%g,", Gamma);
  for(int i = 0; i < N+NSUP; i++)
    fprintf(f, "%g,", Eta);
  for(int i = 0; i < N+NSUP; i++){
    if(i == N+NSUP - 1)
      fprintf(f, "%g", Rho);
    else
      fprintf(f, "%g,", Rho);
  }
  fprintf(f, "};\n");
}
