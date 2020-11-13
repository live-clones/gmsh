// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FAST_SCALED_CROSS_FIELDS_H
#define FAST_SCALED_CROSS_FIELDS_H

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
class GModel;
class GFace;
class MEdge;
class MVertex;
class MTriangle;
struct MEdgeLessThan;
struct MEdgeHash;
struct MEdgeEqual;

int computeScaledCrossFieldView(GModel* gm,
    int& dataListViewTag, 
    std::size_t targetNumberOfQuads,
    int nbDiffusionLevels = 10,               /* Number of levels (fixed time-step length) */
    double thresholdNormConvergence = 1.e-3,  /* At each level, iterate diffusion+projection until thresholdNormConvergence */
    int nbBoundaryExtensionLayer = 1,         /* Extend boundary conditions on triangle-layers */
    const std::string& viewName = "scaled_cross_field",
    int verbosity = 3,                        /* 0: nothing except errors, 1: terse comments, 2: a bit more, 3: detailed convergence info */
    std::vector<std::array<double,5> >* singularities = NULL, /* If not NULL, fill with positions of the detected singularities and indices */
    bool disableConformalScaling = false,      /* Sometimes (complex corners), it is better to not use conformal scaling */
    double conformalScalingQuantileFiltering = 0.1, /* Alternative to disable (for corners): clamp it by removing exterior quantiles */
    bool adaptSizeMapToSmallFeatures = false
    );

int addSingularitiesAtAcuteCorners(
    const std::vector<GFace*>& faces,
    double thresholdInDeg,  /* angle used to detect acute corners, typically angle=45. for compat. with cross fields */
    std::vector<std::array<double,5> >& singularities);


/* Sub-functions that may be called independantly, 
 * for a better control on what is done on each GFace */

int computeCrossFieldWithHeatEquation(
    const std::vector<GFace*>& faces, 
    std::unordered_map<MEdge,double,MEdgeHash,MEdgeEqual>& edgeTheta,
    int nbDiffusionLevels = 10, 
    double thresholdNormConvergence = 1.e-3, 
    int nbBoundaryExtensionLayer = 1, 
    int verbosity = 3);

int getConnectedSurfaceComponents(const std::vector<GFace*>& faces,
    std::vector<std::vector<GFace*> >& components);

int distributeQuadsBasedOnArea(
    size_t totalNumberOfQuads,
    const std::vector<std::vector<GFace*> >& components,
    std::vector<size_t>& componentNumberOfQuads);

int getFacesTriangles(const std::vector<GFace*>& faces, std::vector<MTriangle*>& triangles);

int computeCrossFieldConformalScaling(
    const std::vector<MTriangle*>& triangles, 
    const std::unordered_map<MEdge,double,MEdgeHash,MEdgeEqual>& edgeTheta,
    std::unordered_map<MVertex*,double>& scaling);

int quantileFiltering(std::unordered_map<MVertex*,double>& scaling, double critera = 0.01);

int computeQuadSizeMapFromCrossFieldConformalFactor(
    const std::vector<MTriangle*>& triangles, 
    std::size_t targetNumberOfQuads, 
    std::unordered_map<MVertex*,double>& scaling);

int extractPerTriangleScaledCrossFieldDirections(
    const std::vector<MTriangle*>& triangles, 
    const std::unordered_map<MEdge,double,MEdgeHash,MEdgeEqual>& edgeTheta,
    const std::unordered_map<MVertex*,double>& scaling,
    std::unordered_map<MTriangle*, std::array<double,9> >& triangleDirections);

int extractTriangularMeshFromFaces(
    const std::vector<GFace*>& faces,
    std::vector<std::array<double,3> >& points,
    std::vector<MVertex*>& origin,
    std::vector<std::array<size_t,2> >& lines,
    std::vector<std::array<size_t,3> >& triangles);

int createScaledCrossFieldView(
    const std::vector<MTriangle*>& triangles, 
    const std::unordered_map<MEdge,double,MEdgeHash,MEdgeEqual>& edgeTheta,
    const std::unordered_map<MVertex*,double>& scaling,
    const std::string& viewName,
    int& dataListViewTag);


#endif
