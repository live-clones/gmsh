#ifndef _OCTREE_H_
#define _OCTREE_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include <list>
#include "OctreeInternals.h"

using std::list;

Octree* Octree_Create(int maxElements, // max. num of elts allowed in an octant
		      double *origin, // smallest x,y, z of model's bounding box
		      double *size, // size in x, y, z of model bounding box
		      void  (*BB)(void *, double*, double*),
		      void  (*Centroid)(void *, double *),
		      int   (*InEle)(void *, double *));

void  Octree_Delete(Octree *);  
void  Octree_Insert(void *, Octree *);
void  Octree_Arrange(Octree *);
void * Octree_Search(double *, Octree *);
void  Octree_SearchAll(double *, Octree *, list<void *> *);

#endif
