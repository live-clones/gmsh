// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>
#include <utility>

class MTriangle;
class MLine;

/**
 * @brief Compute a smooth boundary-aligned cross field by alternating
 *        heat diffusion and projection (also called the MBO method).
 *        The crosses are aligned with the lines.
 *        The crosses are sampled on the mesh edges (Crouzeix-Raviart)
 *        and are represented by the angle of one of the branch with the
 *        edge. Returned values are copied on the triangle for ease of
 *        use in other methods.
 *
 * @param[in] triangles Triangulation used for the Crouzeix-Raviart computation, must be connected
 * @param[in] lines Boundary conditions (cross aligned, theta angle is 0), must be non-empty
 * @param[out] triEdgeTheta The cross field, one angle (in radians) per triangle edge. 
 *             It is the relative angle between the edge and one branch of the cross.
 *             i.e.: branch = cos(theta)*edge_tangent+sin(theta)*edge_ortho
 * @param[in] nbDiffusionLevels Number of diffusion levels in the MBO algo. 
 * @param[in] thresholdNormConvergence Converence criteria inside each level
 * @param[in] nbBoundaryExtensionLayer Extend the Dirichlet BCs inside (on X layers) 
 *            to push singularities inside the faces.
 * @param[in] verbosity 0: no log (except errors), 1: two lines, 2: one per level, 3+: details
 *
 * @return 0 if success
 */
int computeCrossFieldWithHeatEquation(
    const std::vector<MTriangle*>& triangles, 
    const std::vector<MLine*>& lines, 
    std::vector<std::array<double,3> >& triEdgeTheta, 
    int nbDiffusionLevels = 5, 
    double thresholdNormConvergence = 1.e-3, 
    int nbBoundaryExtensionLayer = 1,
    int verbosity = 1);

