// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "qoHalfEdge.h"
#include <array>
#include <functional>
#include <vector>

namespace QuadOpt {

  // Patch search after Bunin (2006): find a disk of cells whose boundary has n
  // convex corners, so that a pattern of the library can re-mesh it with fewer
  // singularities. The search is topological: the geometry only gives each
  // boundary vertex the number of quads it should have inside the patch, the
  // angle of the patch there divided by 90 degrees and rounded: one is a convex
  // corner, two a point of a side. (Re-entrant corners, three, are not handled.)

  struct Patch {
    std::vector<int> cells;
    std::vector<int> loop; // oriented boundary
    std::vector<int> corner; // loop indices of the corners
    std::vector<int> side; // side[j]: edges from corner j to corner j + 1
    std::vector<int> param; // what the pattern solved for, see Pattern::fit
    int pattern = -1; // index in patterns()
  };

  // A quad mesh of the patch: the boundary vertices are the loop (indices 0 to
  // loop size - 1), then come the new vertices. Positions are not part of the
  // pattern, only a first guess of them: new vertex k is the combination
  // sum_i weight[k][i] * (loop vertex i), a transfinite interpolation.
  struct Rewrite {
    std::vector<std::array<int, 4> > quad; // counterclockwise like the loop
    std::vector<std::vector<double> > weight; // one per new vertex
  };

  // A family of quad meshes of a disk with n corners, given by the side lengths.
  struct Pattern {
    const char *name;
    // Solves the pattern for the side lengths; false if it has no such mesh.
    bool (*fit)(const std::vector<int> &side, std::vector<int> &param);
    // The mesh of a patch for which fit succeeded.
    void (*build)(const Patch &patch, Rewrite &rewrite);
    // Interior vertices of valence other than four in the mesh of n corners.
    int (*singularities)(int corners);
  };
  const std::vector<Pattern> &patterns();

  // What the search asks of the mesh.
  struct Probe {
    std::function<double(int cell, int corner)> degrees; // angle of a cell corner
    std::function<bool(int vertex)> movable; // may sit inside a patch
  };

  // The smallest patch around the vertices of the seeds (grown by rings of
  // cells, at most maxCells) that a pattern improves, i.e. that has more
  // defects (triangles, interior vertices of valence other than four) than the
  // pattern has singularities. False if there is none.
  bool findPatch(const HalfEdgeMesh &he, const Probe &mesh,
                 const std::vector<int> &seeds, std::size_t maxCells,
                 Patch &patch);

} // namespace QuadOpt
