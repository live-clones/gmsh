#ifndef _STL_H_
#define _STL_H_

// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
#include "Tree.h"

class STL_Data
{
 public:
  Tree_T *Vertices;
  Tree_T *Simplexes;
  List_T *LVertices;
  List_T *LSimplexes;
  void Add_Facet (double x1, double y1, double z1,
                  double x2, double y2, double z2,
                  double x3, double y3, double z3);
  int GetNbFacets (){
    return Tree_Nbr (Simplexes);
  }
  int GetNbVertices (){
    return Tree_Nbr (Vertices);
  }
  void GetFacet (int iFac, int &v1, int &v2, int &v3);
  void GetVertex (int iVertex, double &x, double &y, double &z);
  STL_Data ();
  ~STL_Data ();
};

// more convenient representation
class POLY_rep 
{
public :
  List_T *points_and_normals;  // 6 * nbrPoints 
  List_T *polygons; // first integer gives the number of point of the polygon
                   // then next ones are the points id's of the polygon
  POLY_rep (List_T *_p, List_T *_pol) : points_and_normals (_p),polygons(_pol){}
  ~POLY_rep(){if(polygons)List_Delete(polygons);if(points_and_normals)List_Delete(points_and_normals);}
};

#endif
