// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FAST_SCALED_CROSS_FIELDS_H
#define FAST_SCALED_CROSS_FIELDS_H

#include <vector>
#include <map>
#include <string>
class GModel;
class GFace;
class MEdge;
class MEdgeLessThan;

int computeScaledCrossFieldView(GModel* gm,
    int& dataListViewTag, 
    std::size_t targetNumberOfQuads,
    int nbDiffusionLevels = 10,               /* Number of levels (fixed time-step length) */
    double thresholdNormConvergence = 1.e-3,  /* At each level, iterate diffusion+projection until thresholdNormConvergence */
    int nbBoundaryExtensionLayer = 1,         /* Extend boundary conditions on triangle-layers */
    const std::string& viewName = "scaled_cross_field",
    int verbosity = 3,                        /* 0: nothing except errors, 1: terse comments, 2: a bit more, 3: detailed convergence info */
    std::vector<std::array<double,4> >* singularities = NULL /* If not NULL, fill with positions of the detected singularities and indices */
    );

/* Sub-functions that may be called independantly */
int extractTriangularMeshFromFaces(
    const std::vector<GFace*>& faces,
    std::vector<std::array<double,3> >& points,
    std::vector<size_t>& pointTag,
    std::vector<std::array<size_t,2> >& lines,
    std::vector<std::array<size_t,3> >& triangles);

int computeCrossFieldWithHeatEquation(const std::vector<GFace*>& faces, std::map<std::array<size_t,2>, double>& edgeTheta,
    int nbDiffusionLevels = 10, double thresholdNormConvergence = 1.e-3, int nbBoundaryExtensionLayer = 1, int verbosity = 3);

int computeCrossFieldScaling(const std::vector<GFace*>& faces, const std::map<std::array<size_t,2>, double>& edgeTheta,
    std::size_t targetNumberOfQuads,
    std::vector<std::size_t>& nodeTags, std::vector<double>& scaling);

int extractPerTriangleScaledCrossFieldDirections(
    const std::vector<GFace*>& faces, 
    const std::map<std::array<size_t,2>, double>& edgeTheta, 
    const std::vector<std::size_t>& nodeTags,
    const std::vector<double>& scaling,
    std::map<size_t, std::array<double,9> >& triangleDirections);


#endif
