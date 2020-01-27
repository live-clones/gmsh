#ifndef _HXT_OCTREE_API_H_
#define _HXT_OCTREE_API_H_

#include <vector>
extern "C" {
#include "hxt_api.h"
#include "hxt_bbox.h"
}

struct HXTForest;
struct HXTForestOptions;

HXTStatus hxtOctreeRefineSizeVariation(HXTForest *forest, int recursive);
HXTStatus hxtOctreeCoarsenSizeVariation(HXTForest *forest, int recursive);
HXTStatus hxtOctreeRefineToLevel(HXTForest *forest, int lvl);
HXTStatus hxtOctreeInitialRefine(HXTForest *forest, int nRefine);
HXTStatus hxtOctreeComputeLaplacian(HXTForest *forest);

// HXTStatus hxtOctreeRefineLaplacian(HXTForest *forest);
HXTStatus hxtOctreeCoarsenLaplacian(HXTForest *forest, int recursive);
HXTStatus hxtOctreeLaplacianRefine(HXTForest *forest, int nRefine);

// HXTStatus hxtOctreeBalance(HXTForest *forest);

HXTStatus hxtOctreeSetMaxGradient(HXTForest *forest);
HXTStatus hxtOctreeSmoothGradient(HXTForest *forest, int nMax);

HXTStatus hxtOctreeComputeMaxGradientX(HXTForest *forest, double* dsdx_max);
HXTStatus hxtOctreeComputeMaxGradientY(HXTForest *forest, double* dsdy_max);
HXTStatus hxtOctreeComputeMaxGradientZ(HXTForest *forest, double* dsdz_max);
HXTStatus hxtOctreeComputeMinimumSize(HXTForest *forest, double* size_min);

HXTStatus hxtForestOptionsCreate(HXTForestOptions **forestOptions);
HXTStatus hxtForestOptionsDelete(HXTForestOptions **forestOptions);

// HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, void *user_pointer);
HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, HXTForestOptions *forestOptions);
HXTStatus hxtForestDelete(HXTForest **forest);

HXTStatus hxtForestWriteBBoxMesh(HXTBbox *bbox, const char* filename);

HXTStatus hxtOctreeRTreeIntersection(HXTForest *forest);

HXTStatus hxtOctreeCurvatureRefine(HXTForest *forest, int nMax);

HXTStatus hxtOctreeSearchOne(HXTForest *forest, double x, double y, double z, double *size);
HXTStatus hxtOctreeSearch(HXTForest *forest, std::vector<double> *x, std::vector<double> *y, std::vector<double> *z, std::vector<double> *size);

HXTStatus hxtOctreeSurfacesProches(HXTForest *forest);

HXTStatus hxtOctreeElementEstimation(HXTForest *forest, double *elemEstimate);

#endif
