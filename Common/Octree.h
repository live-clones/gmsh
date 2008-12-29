// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCTREE_H_
#define _OCTREE_H_

#include <list>
#include "OctreeInternals.h"

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
void  Octree_SearchAll(double *, Octree *, std::list<void *> *);

#endif
