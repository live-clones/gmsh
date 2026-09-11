// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Flat, index-based reimplementation of the frontal hex-filling point
// insertion of Filler::treat_region (simple3D.cpp): same algorithm (a BFS
// front of candidate points, accepted when inside the domain, far enough
// from previously accepted points, and following the local size/frame
// field), but with struct-of-arrays storage and integer indices instead of
// one heap-allocated Node/MVertex/GVertex per point, and a uniform spatial
// hash instead of an RTree for the local spacing test.

#ifndef POINT_INSERTION_FLAT_H
#define POINT_INSERTION_FLAT_H

class GRegion;

// Fills gr with interior points the same way Filler::treat_region does, then
// hands them to the Delaunay tetrahedralizer. Drop-in replacement for
// `Filler().treat_region(gr)`.
void fillRegionFlat(GRegion *gr);

#endif
