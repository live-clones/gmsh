// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_BOUNDARY_RECOVERY_H
#define MESH_GREGION_BOUNDARY_RECOVERY_H

#include <cstdint>
#include <vector>

class GRegion;
class MVertex;
class splitQuadRecovery;

// A Delaunay tetrahedralization of the vertices of the boundary mesh of a
// region, computed by the caller: tetNode holds 4 positions in vertices per
// tet, and neighbors[4 * t + f] the tet across the facet opposite node f, or -1
// on the convex hull
struct initialTetrahedralization {
  std::vector<MVertex *> vertices;
  std::vector<std::uint32_t> tetNode;
  std::vector<std::int64_t> neighbors;
};

// Recover the boundary mesh of gr (its surfaces, embedded curves and points)
// in a Delaunay tetrahedralization of its vertices with TetGen's algorithm,
// inserting Steiner points if needed (the curve and surface meshes are then
// updated, and the new boundary vertices added to their curve or surface). The
// tetrahedra, covering the convex hull, are stored in gr->tetrahedra. The
// initial tetrahedralization is computed here unless init is given
bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr = nullptr,
                                 const initialTetrahedralization *init = nullptr);

#endif
