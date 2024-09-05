// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>
#include <cstdint>

class GFace;

/**
 * @brief Untangling/smoothing of volume mesh based on minimization of the
 *        Winslow functional, with regularization for tangled elements.
 *        See the following paper for details:
 *          Foldover-free maps in 50 lines of code.
 *          Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
 * Sokolov, D. (2021). arXiv preprint arXiv:2102.03069. Quads are subdivided
 * into four overlapping triangles for the smoothing. Only for linear geometry,
 * not high-order. Only for planar surfaces. CAD parameterization for curved
 * faces not supported yet. Mesh vertices on boundary curves are fixed.
 *
 * @param gf The face containing the triangles/quads
 * @param iterMax Number of outer iterations in the optimization (re-evaluation
 * of coefficients in Winslow) Typical range is 10-100.
 * @param timeMax Maximum time budget for the smoothing (in seconds)
 *
 * @return True if the smoothing have been applied (mesh may still be tangled)
 */
bool untangleGFaceMeshConstrained(GFace *gf, int iterMax = 1000,
                                  double timeMax = 9999.);



/*********************/
/* Utility functions */
/*********************/

/**
 * @brief Winslow untangler applies to triangles with target shapes. This
 * utility function create the necessary inputs from triangles and quads.
 *
 * @param[in] points Point coordinates
 * @param[in] elements Triangles and quads.
 * Triangles are detected with elements[i][3] = (uint32_t) -1
 * @param[out] triangles The triangles to optimize, without overlapping when
 * quad subdivided into four corner triangles.
 * @param[out] triIdealShapes The target shapes, equilateral tri for triangles
 * and right-angled triangles for quad.
 * @param[in] preserveQuadAnisotropy If true, the triangles built from quads will
 * preserve the anisotropy of the input quads. Very experimental, does not work well.
 *
 * @return True if success
 */
bool buildTrianglesAndTargetsFromElements(
    const std::vector<std::array<double,2> >& points,
    const std::vector<std::array<uint32_t,4> >& elements,
    std::vector<std::array<uint32_t, 3> >& triangles,
    std::vector<std::array<std::array<double,2>, 3> >& triIdealShapes,
    bool preserveQuadAnisotropy = false);
