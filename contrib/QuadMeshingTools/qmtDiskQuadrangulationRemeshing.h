// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include "qmtMeshUtils.h"


class SurfaceProjector;

/**
 * @brief Parse the disk quadrangulation list at runtime.
 *        Must be called one-time before using remeshLocalWithDiskQuadrangulation()
 *
 * @return 0 if success
 */
int initDiskQuadrangulations();

/**
 * @brief Look for the best topological disk quadrangulation remeshing
 *        which match the allowed valence ranges.
 *        Requires that the disk quadrangulation data is initialized, see initDiskQuadrangulations()
 *        The GFace mesh is not changed, the changes are stored in the diff
 *        which can executed by the caller.
 *
 * @param[in] gf CAD face containing the elements
 * @param[in] elements Elements (triangles or quads) in the input patch. May be empty
 * @param[in] intVertices Interior vertices in the input patch. May be empty
 * @param[in] bdrVertices Patch ordered boundary vertex loop, minimum 4 vertices
 * @param[in] bndIdealValence The ideal inside quad valence for the boundary corners
 * @param[in] bndAllowedValenceRange The allowed range of inside quad valence
 * @param[in] neighborsForGeometry Adjacent elements that may be used for geometry untangling
 * @param[in] minSICNafer Minimum SICN quality required in the remeshed patch.
 *                        Compared after geometry untangling/smoothing.
 * @param[in] invertNormalsForQuality The CAD normals are used to compute signed quality.
 *                                    This flag invert invert the CAD normals in the measure.
 * @param[in] sp If not nullptr, the surface projector is used instead of the CAD parametrization
 *               in the smoothing. Required if there is no surface parametrization.
 * @param[out] diff The mesh diff (to the GFace) containing the remeshing candidate
 *
 * @return 0 if a valid remeshing has been found
 */
int remeshLocalWithDiskQuadrangulation(
    GFace* gf,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& intVertices,
    const std::vector<MVertex*>& bdrVertices,
    const std::vector<int>& bndIdealValence,
    const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
    const std::vector<MElement*>& neighborsForGeometry,
    double minSICNafer,
    bool invertNormalsForQuality,
    SurfaceProjector* sp,
    GFaceMeshDiff& diff);
