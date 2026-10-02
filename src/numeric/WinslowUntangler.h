// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#pragma once

#include <array>
#include <cstdint>
#include <vector>

// Untangling and smoothing of triangle and tetrahedron meshes by minimization
// of a regularized Winslow functional, as described in
//
//   Foldover-free maps in 50 lines of code. V. Garanzha, I. Kaporin,
//   L. Kudryavtseva, F. Protais, N. Ray, D. Sokolov. ACM Transactions on
//   Graphics 40(4), 2021. https://github.com/ssloy/invertible-maps
//
// Each outer iteration updates the regularization from the smallest Jacobian
// determinant and minimizes the functional with L-BFGS.

namespace WinslowUntangler {

  struct Options {
    // Weight of the volume term
    double lambda = 1.;
    int maxOuterIterations = 100;
    // L-BFGS iterations per outer iteration
    int maxInnerIterations = 300;
    // Stop after more than maxFailures failed outer iterations
    int maxFailures = 10;
    // CPU time budget, in seconds
    double timeMax = 9999.;
    int numThreads = 1;
    // Count an inner minimization as failed unless it converges on the
    // gradient, or reaches its iteration limit while the energy still
    // decreases; otherwise only a failed line search counts
    bool strictFailures = false;
    // Smooth the free vertices with 10 Laplacian passes before untangling
    // (3D only)
    bool laplacianPresmoothing = false;
  };

  // Move the vertices that are not locked. Ideal shapes give the target shape
  // of each element; an empty vector means equilateral triangles or regular
  // tetrahedra. Return true if the mesh is untangled and the energy converged.
  bool untangle2D(
    std::vector<std::array<double, 2>> &points, const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &triangles,
    const std::vector<std::array<std::array<double, 2>, 3>> &idealShapes,
    const Options &options = Options());

  // Tetrahedra are positive when (v1 - v0, v2 - v0, v3 - v0) is a left-handed
  // frame, i.e. with the opposite orientation of Gmsh tetrahedra.
  bool untangle3D(
    std::vector<std::array<double, 3>> &points, const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 4>> &tets,
    const std::vector<std::array<std::array<double, 3>, 4>> &idealShapes,
    const Options &options = Options());

} // namespace WinslowUntangler
