#ifndef _OCTREEH_
#define _OCTREEH_

#include <list>
#include "o_internals.h"

using std::list;

/*class Octree; */

Octree* Octree_Create (int, /* max. number of elements allowed in an octant */
		       double *origin,   /* smallest x,y, z of model's bounding box */ 
		       double *size,    /* size in x, y, z of model bounding box */
		       void  (*BB)(void *, double*, double*),
		       void  (*Centroid)(void *, double *),
		       int   (*InEle)(void *, double *));

void  Octree_Delete  (Octree *);  
void  Octree_Insert  (void *, Octree *);
void  Octree_Arrange(Octree *);
void * Octree_Search  (double *, Octree *);
void  Octree_SearchAll (double *, Octree *, list<void *> * );
#endif
