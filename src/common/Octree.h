// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCTREE_H
#define OCTREE_H

#include <vector>

// Search structure for the elements near a point: a bounding volume
// hierarchy over the elements' bounding boxes, which are computed once, on
// insertion, by the callback. Elements are opaque pointers: the caller tests
// the ones it gets back. Queries do not modify the tree and can run
// concurrently once it is built.
class Octree;

Octree *Octree_Create(void (*BB)(void *, double *, double *));

void Octree_Delete(Octree *);

// Add an element; the tree is built by Octree_Arrange, once all the elements
// have been inserted.
void Octree_Insert(void *, Octree *);
void Octree_Arrange(Octree *);

// Append all the elements whose bounding box, enlarged on each side by
// relTol times its largest extent plus the distance d, contains the point, in
// insertion order.
void Octree_SearchAllNear(double *, Octree *, double relTol, double d,
                          std::vector<void *> *);

#endif
