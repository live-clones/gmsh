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
 * @brief Apply iterative cavity remeshing to the face mesh
 *        to reduce the number of irregular vertices which
 *        are not matching cross field singularities.
 *        The quad patterns must be loaded before (see initQuadPatterns()).
 *
 * @param[in,out] gf The face containing the quad mesh to improve
 * @param[in] singularities Floating list of cross field singularities, specified by
 *                          their position and their index (-1 for valence 5, +1 for valence 3)
 * @param[in] invertNormalsForQuality The CAD normals are used to compute signed quality.
 *                                    This flag invert invert the CAD normals in the measure.
 *
 * @return 0 if success
 */
int improveQuadMeshTopologyWithCavityRemeshing(GFace* gf,
    const std::vector<std::pair<SPoint3,int> >& singularities,
    bool invertNormalsForQuality);

/**
 * @brief Consider the current face mesh as a global single cavity
 *        and try to mesh it with the exising patterns.
 *        The quad patterns must be loaded before (see initQuadPatterns()).
 *
 * @param[in,out] gf The face containing the quad mesh to improve
 * @param[in] invertNormalsForQuality The CAD normals are used to compute signed quality.
 *                                    This flag invert invert the CAD normals in the measure.
 * @param[in] minimumQualityRequired Minimum quality (SICN) required to accept a new quad mesh
 *
 * @return 0 if success
 */
int meshFaceWithGlobalPattern(GFace* gf, bool invertNormalsForQuality, double minimumQualityRequired);


/* List of patterns */
extern const size_t PATTERN_QUAD_REGULAR;
extern const size_t PATTERN_TRIANGLE;
extern const size_t PATTERN_PENTAGON;
extern const size_t PATTERN_QUAD_DIAG35;
extern const size_t PATTERN_QUAD_ALIGNED35;
extern const size_t PATTERN_QUAD_CHORD_UTURN;
extern const size_t PATTERN_2CORNERS;
extern const size_t PATTERN_1CORNER;
extern const size_t PATTERN_DISK;

/**
 * @return the number of corners in the input pattern
 */
size_t patternNumberOfCorners(size_t pId);

/**
 * @brief Initialize the pattern datastructures from raw meshes.
 *        Must be called one-time before using remeshPatchWithQuadPattern()
 *
 * @return 0 if success
 */
int initQuadPatterns();

/**
 * @brief Get a vector with all the patterns.
 *
 * @return the pattern identifiers (see the list of patterns)
 */
std::vector<size_t> getAllLoadedPatterns();

/**
 * @brief Check if there is a topological quad mesh matching
 *        a given boundary, in the specified patterns.
 *        Mesh geometry is totally ignored in this function.
 *
 * @param[in] patternsToCheck The list of patterns to try
 * @param[in] Ncorners The number of corners in the patch
 * @param[in] sideSizes The number of edges on each side
 * @param[out] patternNoAndRot If found, the pattern identifier and its associated rotation
 * @param[out] irregularityMeasure If round, the topological irregularity measure of the pattern
 *
 * @return true if a matching is found
 */
bool patchIsRemeshableWithQuadPattern(
    const std::vector<size_t>& patternsToCheck,
    size_t Ncorners,
    const std::vector<size_t>& sideSizes,
    std::pair<size_t,int>& patternNoAndRot,
    double& irregularityMeasure);


struct QualityConstraints {
  double SICNmin = -1.;
  double SIGEmin = -1.;
  double skewMax = 1.;
};

/**
 * @brief Look for the best topological disk quadrangulation remeshing
 *        which match the allowed valence ranges.
 *        Requires that the disk quadrangulation data is initialized, see initDiskQuadrangulations()
 *        The GFace mesh is not changed, the changes are stored in the diff
 *        which can executed by the caller.
 *
 * @param[in] gf CAD face containing the elements
 * @param[in] patternNoAndRot If found, the pattern identifier and its associated rotation
 * @param[in] sides The vertices on each side. Must be compatible with the output of
 *                  patchIsRemeshableWithQuadPattern()
 * @param[in] elements The old elements in the patch, may be empty
 * @param[in] intVertices The old interior vertices in the patch, may empty
 * @param[in] qualityConstraints Constraints on the quality required in the remeshed patch.
 *                        Checked after geometry untangling/smoothing.
 * @param[in] invertNormalsForQuality The CAD normals are used to compute signed quality.
 *                                    This flag invert invert the CAD normals in the measure.
 * @param[in] sp If not nullptr, the surface projector is used instead of the CAD parametrization
 *               in the smoothing. Required if there is no surface parametrization.
 * @param[out] diff The mesh diff (to the GFace) containing the remeshing candidate
 *
 * @return 0 if success
 */
int remeshPatchWithQuadPattern(
    GFace* gf,
    const std::pair<size_t,int>& patternNoAndRot,
    const std::vector<std::vector<MVertex*> > & sides,
    const std::vector<MElement*> & elements,
    const std::vector<MVertex*>& intVertices,
    const QualityConstraints& qualityConstraints,
    bool invertNormalsForQuality,
    SurfaceProjector* sp,
    GFaceMeshDiff& diff);
