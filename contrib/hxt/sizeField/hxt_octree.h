#ifndef HXT_OCTREE_H
#define HXT_OCTREE_H

#include <functional>

// GMSH INCLUDES
#include "rtree.h"
#include "GModel.h"

// P4EST INCLUDES
#ifdef HAVE_P4EST
#include <p4est_to_p8est.h>
#include <p8est_extended.h>
#endif

// HXT INCLUDES
extern "C" {
  #include "hxt_tools.h"
  #include "hxt_mesh.h"
  #include "hxt_bbox.h"
}

// Information needed to create and compute an HXTForest
typedef struct HXTForestOptions{
  int           dim;
  double 				hmax;
  double 				hmin;
  double 				hbulk;
  double 				gradation;
  int           nRefine;
  int           nodePerTwoPi;
  int           nodePerGap;
  double       *bbox;
  double      (*sizeFunction)(double, double, double, double);
  // const char   *forestFile;
  RTree<uint64_t,double,3>  *triRTree;
  HXTMesh                   *mesh;
  double                    *nodalCurvature;
  double                    *nodeNormals;
  std::vector<std::function<double(double)>> *curvFunctions;
  std::vector<std::function<double(double)>> *xFunctions;
  std::vector<std::function<double(double)>> *yFunctions;
  GModel *gmodel;
} HXTForestOptions;

// The structure containing the size field information
typedef struct HXTForest{
#ifdef HAVE_P4EST
  p4est_t *p4est;
#endif 
  HXTForestOptions *forestOptions;
} HXTForest;

// Data available on each tree cell
typedef struct size_data{
  double size;
#ifdef HAVE_P4EST
  double ds[P4EST_DIM]; // Size gradient
#endif
  double h; // The cell size
  // TODO : remplacer les double par un teableu de booleen qui indique si le voisin est full ou hanging
  // Comme ça il faudra juste ajouter h/2
  double h_xL, h_xR; // Half cell length for finite differences
  double h_yD, h_yU;
  double h_zB, h_zT;
  int isBoundary;

  // Coordinates of center : TO REMOVE
  double c[3];
} size_data_t;

// A node to search in the tree
typedef struct size_point{
  double x;
  double y;
  double z;
  double size;
  bool isFound;
} size_point_t;

// Additional user-defined size function : currently not used
typedef struct size_fun{
  double (*myFun)(double, double, double, double);
} size_fun_t;

// API ---------------------------------------------------------------------------------------------
HXTStatus hxtForestOptionsCreate(HXTForestOptions **forestOptions);
HXTStatus hxtForestOptionsDelete(HXTForestOptions **forestOptions);

HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, HXTForestOptions *forestOptions);
HXTStatus hxtForestDelete(HXTForest **forest);

HXTStatus hxtForestSave(HXTForest *forest, const char* forestFile, const char *dataFile);
HXTStatus hxtForestExport(HXTForest *forest, const char *forestFile);
HXTStatus hxtForestExport2D(HXTForest *forest, const char *forestFile);
HXTStatus hxtForestLoad(HXTForest **forest, const char* forestFile, const char *dataFile, HXTForestOptions *forestOptions);

HXTStatus hxtForestRefine(HXTForest *forest);
HXTStatus hxtForestSizeSmoothing(HXTForest *forest);
HXTStatus hxtForestCloseSurfaces(HXTForest *forest);
HXTStatus hxtComputeGradientOnce(HXTForest *forest);

HXTStatus hxtOctreeElementEstimation(HXTForest *forest, double *elemEstimate);
HXTStatus hxtForestSearchOne(HXTForest *forest, double x, double y, double z, double *size, int linear);

// Pour calculer la convergence des derivees
HXTStatus hxtForestRefineToBulk(HXTForest *forest);
HXTStatus hxtForestRefineOneLevel(HXTForest *forest);
HXTStatus hxtL2NormGradient(HXTForest *forest, double *error);
HXTStatus hxtLInfNormGradient(HXTForest *forest, double *error);
HXTStatus hxtGetSmallestCellSize(HXTForest *forest, double *minsize);
HXTStatus hxtGetLargestCellSize(HXTForest *forest, double *maxsize);

HXTStatus medialAxis(HXTForest *forest);

#endif
