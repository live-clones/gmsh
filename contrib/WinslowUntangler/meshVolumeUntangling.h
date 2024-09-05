// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <cstdint>
#include <vector>
#include <array>

class GRegion;

/**
 * @brief Untangling/smoothing of volume mesh based on minimization of the
 *        Winslow functional, with regularization for tangled elements.
 *        See the following paper for details:
 *          Foldover-free maps in 50 lines of code.
 *          Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
 * Sokolov, D. (2021). arXiv preprint arXiv:2102.03069. Non-tetrahedron elements
 * are subdivided into (overlapping) tetrahedra for the smoothing. Only for
 * linear geometry, not high-order. Mesh vertices on boundary curves and
 * surfaces are fixed.
 *
 * @param gr The region containing the volume elements
 * @param iterMax Number of outer iterations in the optimization (re-evaluation
 * of coefficients in Winslow) Typical range is 10-100.
 * @param timeMax Maximum time budget for the smoothing (in seconds)
 *
 * @return True if the smoothing have been applied (mesh may still be tangled)
 */
bool untangleGRegionMeshConstrained(GRegion *gr, int iterMax = 100,
                                    double timeMax = 9999.);



/*********************/
/* Utility functions */
/*********************/

/**
 * @brief Transform linear elements into (overlapping) tetrahedra
 * suitable for WinslowUntangler
 *
 * @param[in] elements Vertices of each element. 4 for tet, 8 for hex, 5 for pyr, 6 for prism
 * @param[in] elementTargetShapes To control the shape of the optimized elements.
 * If empty, tetIdealShapes are built to match regular elements (unit cube, regular tet, etc)
 * @param[out] tets The list of tetrahedra obtained by subdividing the elements
 * @param[out] tetIdealShapes The ideal shapes of the tetrahedra to match elementTargetShapes
 * @param[in] dcpHex Decomposition used for hex to tets. Can be 8 (corners), 24
 * (diagonals) or 32 (corners + diagonals)
 *
 * @return True if successful
 */
bool buildTetrahedraFromElements(
    const std::vector<std::vector<uint32_t> > &elements,
    const std::vector<std::vector<std::array<double,3> > > &elementTargetShapes,
    std::vector<std::array<uint32_t, 4> > &tets,
    std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
    int dcpHex = 32);
