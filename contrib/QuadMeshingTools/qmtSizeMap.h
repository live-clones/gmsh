// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <string>

class MVertex;
class MTriangle;
class GModel;
class GlobalBackgroundMesh;

/**
 * @brief Compute minimal size values on curve vertices. This the minimum of:
 *        - the current curve length
 *        - the distance to other non-adjacent curves
 *        - the prescribed mesh size
 *
 * @param[in] gbm Background mesh on which to compute the minimal sizes
 * @param[in] clampMinWithTriEdges If true, the minimum length is the maximum
 * of the previously computed size (from CAD) and local background mesh triangle size.
 * This option is useful to avoid over-refinement.
 * @param[out] minSize the minimal distance, for each MVertex of GVertex / GEdge
 *
 * @return 0 if success
 */
int computeMinimalSizeOnCurves(
    GlobalBackgroundMesh& gbm,
    bool clampMinWithTriEdges,
    std::unordered_map<MVertex*,double>& minSize);

/**
 * @brief One way smoothing to get a smooth scalar field where
 *        the gradient is inferior to gradientMax, the output
 *        verify:
 *          v2 = min(v2, v1 + gradientMax * d(x1,v2))
 *        for all edge v1-v2 in the triangles. The propagation is
 *        computed with a Dijkstra-like algorithm.
 *
 * @param triangles The triangulation on which to extract the edges for Dijkstra
 * @param values The scalar field to smooth
 * @param gradientMax The maximum gradient in the ouput, typical range is [1, 1.4]
 *                    for meshing
 *
 * @return 0 if success
 */
int sizeMapOneWaySmoothing(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MVertex*,double>& values,
    double gradientMax = 1.2);


/**
 * @brief Remove extremities in the histogram
 *
 * @param scaling the values on which to apply the filtering
 * @param critera keep values which are in [critera,1-critera] in the histogram
 */
void quantileFiltering(std::unordered_map<MVertex*,double>& scaling, double critera);
