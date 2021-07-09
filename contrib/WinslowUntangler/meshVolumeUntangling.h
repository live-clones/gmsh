// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <cstdint>

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
