#ifndef _VERTEX_H_
#define _VERTEX_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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

#include "List.h"

typedef struct {
  double X,Y,Z;
}Coord;

class Vertex {
  public :
  int     Num;
  char    Visible;
  int     Frozen;
  double  lc,u,us[3],w;
  Coord   Pos;
  Coord  *Mov;
  Coord   Freeze;
  List_T *ListSurf;
  List_T *ListCurves;
  List_T *Extruded_Points;
  Vertex ();
  Vertex (double x,double y,double z =0.0, double lc = 1.0, double w = 1.0);
  Vertex operator + ( const Vertex &other);
  Vertex operator - ( const Vertex &other);
  double operator * ( const Vertex &other);
  Vertex operator * ( double d );
  Vertex operator / ( double d );
  Vertex operator % (Vertex &autre); // cross product
  void norme();
};

int compareVertex (const void *a, const void *b);
int comparePosition (const void *a, const void *b);

Vertex *Create_Vertex (int Num, double X, double Y, double Z, double lc, double u);
void Delete_Vertex ( Vertex *pV );
void Free_Vertex (void *a, void *b);
void Free_ExtrudedPoints(List_T* Extruded_Points);

#endif
