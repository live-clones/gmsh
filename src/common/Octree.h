// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCTREE_H
#define OCTREE_H

#include <vector>

// Search structure for the elements containing a point: a bounding volume
// hierarchy over the elements' bounding boxes, which are computed once, on
// insertion. Elements are opaque pointers; the callbacks give their bounding
// box and tell whether a point is inside (none: whether their box holds it,
// for a caller that only searches near a point and tests the elements
// itself). Queries do not modify the tree and can run concurrently once it is
// built.
class Octree;

Octree *Octree_Create(void (*BB)(void *, double *, double *),
                      int (*InEle)(void *, double *));

void Octree_Delete(Octree *);

// Add an element; the tree is built by Octree_Arrange, once all the elements
// have been inserted.
void Octree_Insert(void *, Octree *);
void Octree_Arrange(Octree *);

// Get an element containing the point, or nullptr.
void *Octree_Search(double *, Octree *);

// Append all the elements containing the point, in insertion order.
void Octree_SearchAll(double *, Octree *, std::vector<void *> *);

// Append all the elements whose bounding box, enlarged on each side by
// relTol times its largest extent plus the distance d, contains the point, in
// insertion order; the InEle callback is not called.
void Octree_SearchAllNear(double *, Octree *, double relTol, double d,
                          std::vector<void *> *);

#endif
