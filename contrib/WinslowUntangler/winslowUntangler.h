// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

// This module re-implements the constrained 2d/3d untangler described in the
// paper:
//
//      Foldover-free maps in 50 lines of code.
//      Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
//      Sokolov, D. (2021). arXiv preprint arXiv:2102.03069.
//      reference implementation: https://github.com/ssloy/invertible-maps

#pragma once

#include <vector>
#include <array>
#include <cstdint>

/**
 * @brief Planar untangler based on the minimization of the Winslow functional
 *        with regularization for inverted elements.
 *        Only apply to triangles. Quads should be split in multiple triangles
 * by the caller (the triangles may overlap)
 *
 * @param[in,out] points Coordinates of the 2D points to optimize
 * @param[in] locked Locked vertices
 * @param[in] triangles List of triangle indexes in points
 * @param[in] triIdealShapes Not supported yet, let it empty
 * @param[in] lambda Tradeoff between shape and area. 0 is Winslow
 * @param[in] iterMaxInner Maximum number of iterations for each LBFGS solve
 * @param[in] iterMaxOuter Maximum number of outer steps
 * @param[in] iterFailMax Stop the solver after iterFailMax step failures
 * @param[in] timeMax Stop the solver after timeMax CPU seconds
 *
 * @return true if converged, but solution may still be good if false returned
 *         (solver stopped after timeMax or iterMaxOuter)
 */
bool untangle_triangles_2D(
  std::vector<std::array<double, 2> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3> > &triangles,
  const std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
  double lambda = 1., int iterMaxInner = 300, int iterMaxOuter = 100,
  int iterFailMax = 10, double timeMax = 9999.);

/**
 * @brief Volume untangler based on the minimization of the Winslow functional
 *        with regularization for inverted elements.
 *        Only apply to tetrahedra. Other cell types should be split in multiple
 * tets by the caller (the tets may overlap, e.g. use 32 tets per hex)
 *
 * @param[in,out] points Coordinates of the 3D points to optimize
 * @param[in] locked Locked vertices
 * @param[in] tets List of tet indexes in points
 * @param[in] tetIdealShapes Ideal shapes for the tets. Useful for anisotropic
 * targets or for decomposition of hex/prism/pyramid into tets. Can be empty.
 * @param[in] lambda Tradeoff between shape and volume. 0 is Winslow.
 * @param[in] iterMaxInner Maximum number of iterations for each LBFGS solve
 * @param[in] iterMaxOuter Maximum number of outer steps
 * @param[in] iterFailMax Stop the solver after iterFailMax step failures
 * @param[in] timeMax Stop the solver after timeMax CPU seconds
 *
 * @return true if converged, but solution may still be good if false returned
 *         (solver stopped after timeMax or iterMaxOuter)
 */
bool untangle_tetrahedra(
  std::vector<std::array<double, 3> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4> > &tets,
  const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  double lambda = 1., int iterMaxInner = 300, int iterMaxOuter = 100,
  int iterFailMax = 10, double timeMax = 9999.);
