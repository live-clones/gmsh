#ifndef _DISCRETE_SURFACE_H_
#define _DISCRETE_SURFACE_H_

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



// A convenient surface representation, that can be used
// as a triangulation for any given surface. See e.g. the "Polygonal
// Surface" command in the parser, which takes a surface defined by
// edge loops (that may be initially planar or anything else) and adds
// a triangulation to it in order to represent the shape of the surface.
// This triangulation may be a STL triangulation (polygons are triangle)
// but anything else is okay. Solid modelers like parasolid or proE
// are able to provide such representations. I have written a
// translator from ideas to gmsh that does that.
class POLY_rep 
{
public :
  int num_points, num_polys;
  List_T *points_and_normals;  // 6 * num_points 
  List_T *polygons; // first integer gives the number of point of the polygon
                    // then next ones are the points id's of the polygon
  POLY_rep(int num_points, int num_polys, List_T *_p, List_T *_pol);
  POLY_rep();
  ~POLY_rep();
  double bounding_box[6];
  void compute_bounding_box();
};

// Same thing for discrete curves

class SEGM_rep 
{
public :
  int num_points;
  List_T *points;  // 3 * num_points 
  SEGM_rep(int num_points, List_T *_p);
  SEGM_rep();
  ~SEGM_rep();
  double bounding_box[6];
  void compute_bounding_box();
};



#endif
