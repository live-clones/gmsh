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
#include <utility>
#include "SPoint3.h"

class MVertex;
class MTriangle;
class MLine;
class GFace;

/**
 * @brief Compute a smooth boundary-aligned cross field by alternating
 *        heat diffusion and projection (also called the MBO method).
 *        The crosses are aligned with the lines.
 *        The crosses are sampled on the mesh edges (Crouzeix-Raviart)
 *        and are represented by the angle of one of the branch with the
 *        edge. Returned values are copied on the triangle for ease of
 *        use in other methods.
 *
 * @param[in] N symmetry invariance, N=4 for crosses, N=6 for asterisks
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
    int N,
    const std::vector<MTriangle*>& triangles,
    const std::vector<MLine*>& lines,
    std::vector<std::array<double,3> >& triEdgeTheta,
    int nbDiffusionLevels = 5,
    double thresholdNormConvergence = 1.e-3,
    int nbBoundaryExtensionLayer = 1,
    int verbosity = 1);

/**
 * @brief Compute the cross field conformal scaling by canceling the Lie bracket,
 *        in a least square sense (singularities are not used).
 *        The scaling defines the "intrinsic" cross field size map (up to a constant).
 *
 * @param[in] N symmetry invariance, N=4 for crosses, N=6 for asterisks
 * @param[in] triangles Triangulation used to compute the cross field, and use to compute the scaling
 * @param[in] triEdgeTheta The cross field, one angle per triangle edge, relative to the edge direction
 *                     should be compatible with the result of computeCrossFieldWithHeatEquation()
 * @param[out] scaling The conformal scaling, scalar field with one value per vertex (P1 FEM)
 *
 * @return 0 if success
 */
int computeCrossFieldConformalScaling(
    int N,
    const std::vector<MTriangle*>& triangles,
    const std::vector<std::array<double,3> >& triEdgeTheta,
    std::unordered_map<MVertex*,double>& scaling);


/**
 * @brief Compute a size map from the conformal scaling by adding an offset
 *        to get targetNumberOfQuads in the end (when integrating the sizemap).
 *
 * @param triangles Triangulation used to compute the conformal scaling
 * @param targetNumberOfQuads The number of quads used to offset the scaling
 * @param[in,out] scaling The size map to update with the offset
 *
 * @return 0 if success
 */
int computeQuadSizeMapFromCrossFieldConformalFactor(
    const std::vector<MTriangle*>& triangles,
    std::size_t targetNumberOfQuads,
    std::unordered_map<MVertex*,double>& scaling);


/**
 * @brief Convert the edge-sampled cross field to a triangle-sampled cross field,
 *        by using Crouzeix-Raviart interpolation.
 *        Each triangle has 3 unit directions at its corner. This cross field is (slighly)
 *        dicontinuous at triangle interfaces.
 *
 * @param[in] N symmetry invariance, N=4 for crosses, N=6 for asterisks
 * @param[in] triangles Triangulation used to compute cross field and size map
 * @param[in] triEdgeTheta The cross field, one angle per triangle edge, relative to the edge direction
 *                     should be compatible with the result of computeCrossFieldWithHeatEquation()
 * @param[out] triangleDirections The cross field sampled at triangle corners, three vectors
 *             per triangle (one per corner).  component ordering: [v1x,v1y,v1z,.., v3x,v3y,v3z]
 *
 * @return 0 if success
 */
int convertToPerTriangleCrossFieldDirections(
    int N,
    const std::vector<MTriangle*>& triangles,
    const std::vector<std::array<double,3> >& triEdgeTheta,
    std::vector<std::array<double,9> >& triangleDirections);

/**
 * @brief Detect the singularities in a cross field by adding angle differences around
 *        vertex one-rings
 *
 * @param[in] N symmetry invariance, N=4 for crosses, N=6 for asterisks
 * @param[in] triangles Triangulation used to compute cross field and size map
 * @param[in] triEdgeTheta The cross field, one angle per triangle edge, relative to the edge direction
 *                     should be compatible with the result of computeCrossFieldWithHeatEquation()
 * @param[in] addSingularitiesAtAcuteCorners If true, at singularity at corners whose angle is small
 * @param[in] thresholdInDeg Corners are considered acute if inferior to this threshold, e.g. 30 (degrees)
 * @param[out] singularities Cross field singularities, position and index (-1 for valence 5,
 *                           +1 for valence 3)
 *
 * @return 0 if success
 */
int detectCrossFieldSingularities(
    int N,
    const std::vector<MTriangle*>& triangles,
    const std::vector<std::array<double,3> >& triEdgeTheta,
    bool addSingularitiesAtAcuteCorners,
    double thresholdInDeg,
    std::vector<std::pair<SPoint3,int> >& singularities);
