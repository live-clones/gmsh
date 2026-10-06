// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

namespace QuadOpt {

  // Everything QuadOpt is asked to do, passed explicitly to its entry points.
  // The algorithms never read Gmsh's global context: only the code that calls
  // them (Generator.cpp, meshGFaceDelaunay.cpp) translates Gmsh options into
  // this structure.
  struct Options {
    // PACK finalization: quad patterns on simple faces before the optimization.
    bool patterns = false;
    // PACK finalization: recombine the triangulation with Q-Morph instead of
    // Blossom (which Gmsh runs before QuadOpt is called).
    bool qMorph = false;
    // Run the cavity optimizer after Blossom. It is always part of Q-Morph.
    bool optimize = true;
    // A quad warped by more than this angle (degrees) is split in two triangles.
    double maximumWarping = 25.;
  };

} // namespace QuadOpt
