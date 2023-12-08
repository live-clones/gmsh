// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

class GModel;

/**
 *
 * WARNING: work in progress, NOT READY for generic usage
 *
 *
 * @brief Determine the number of points on each GEdge
 *        for quad meshing. Try to match the opposite
 *        sides to get regular meshes.
 *        The GEdge meshing properties are changed and
 *        some GEdge are set to transfinite.
 *        The GFace whose boundary curves are all transfinite
 *        are set to transfinite.
 *        Requires a mesh. Use the existing GFace meshes
 *        or a background mesh if available.
 *
 * @param gm The model containing the curves
 * @param maxDiffNbLines Two opposite sides are constrained to the
 *                       same number of lines if their relative difference
 *                       is inferior to this threshold.
 *
 * @return 0 if success
 */
int setQuadqsTransfiniteConstraints(GModel* gm, double maxDiffNbLines = 0.25);
