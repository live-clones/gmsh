// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_BOUNDARY_RECOVERY_H
#define MESH_GREGION_BOUNDARY_RECOVERY_H

#include <cstdint>
#include <set>
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

// The boundary recovery on flat arrays: the tetrahedralization of the
// vertices (4 positions per tet in tetNode, tetNeighbors[4 * t + f] the tet
// across the facet opposite node f or -1), the triangles and segments to
// recover with an integer tag each (the tag of their surface or curve; -1 for
// a triangle edge)
struct boundaryRecoveryInput {
  std::vector<double> xyz; // 3 per vertex
  std::vector<std::uint32_t> tetNode;
  std::vector<std::int64_t> tetNeighbors;
  std::vector<std::uint32_t> triNode;
  std::vector<int> triTag;
  std::vector<std::uint32_t> segNode;
  std::vector<int> segTag;
  // remove the tets outside the surfaces (only for a closed surface mesh)
  bool carve = true;
  // TetGen's Delaunay recovery and optimization of the whole mesh afterwards
  bool postprocess = true;
  bool verbose = true;
  // the mesh is a cavity rather than a convex hull: the constraints present
  // in it are bonded before the recovery, which walks only for the missing
  // ones, and the walks may leave the mesh. triTet[i] is then the tet holding
  // triangle i (-1: none, to be recovered)
  bool nonconvex = false;
  std::vector<std::int64_t> triTet;
  // the dihedral angle (degrees) below which two facets sharing an edge are
  // reported as overlapping; negative: Mesh.AngleToleranceFacetOverlap
  double overlapAngleTolerance = -1.;
};

// The result: the Steiner points (vertex numVertices + k for the k-th one;
// type 0 in the volume, 1 on a segment, 2 on a facet, with the tags of that
// segment and of a facet at it), the tets (without the hull tets), the
// triangles and segments as recovered (split at the Steiner points) with
// their tags, and the tags of the facets and segments that received Steiner
// points
struct boundaryRecoveryOutput {
  std::vector<double> steinerXYZ;
  std::vector<int> steinerType, steinerSegTag, steinerFaceTag;
  std::vector<std::uint32_t> tetNode;
  std::vector<std::uint32_t> triNode;
  std::vector<int> triTag;
  std::vector<std::uint32_t> segNode;
  std::vector<int> segTag;
  std::set<int> changedFaces, changedEdges;
};

// run TetGen's boundary recovery on the flat arrays; returns 0 on success,
// TetGen's error code otherwise (1: out of memory, 3: invalid input)
int meshGRegionBoundaryRecoveryFlat(const boundaryRecoveryInput &in,
                                    boundaryRecoveryOutput &out);

// Recover the boundary mesh of gr (its surfaces, embedded curves and points)
// in a Delaunay tetrahedralization of its vertices with TetGen's algorithm,
// inserting Steiner points if needed (the curve and surface meshes are then
// updated, and the new boundary vertices added to their curve or surface). The
// tetrahedra are stored in gr->tetrahedra. The initial tetrahedralization is
// computed here unless init is given: the tetrahedra then cover its convex
// hull, otherwise those outside the surfaces are removed
bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr = nullptr,
                                 const initialTetrahedralization *init = nullptr);

#endif
