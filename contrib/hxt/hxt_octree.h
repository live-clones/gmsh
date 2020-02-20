#ifndef HXT_OCTREE_H
#define HXT_OCTREE_H

// STD INCLUDES
#include <queue>
#include <vector>

// GMSH INCLUDES ...

#include "SPoint3.h"
#include "SVector3.h"
#include "rtree.h"

// P4EST INCLUDES

#ifdef HAVE_P4EST
#include <p4est_to_p8est.h>
#include <p8est_bits.h>
#include <p8est_ghost.h>
#include <p8est_nodes.h>
#include <p8est_vtk.h>
#include <p8est_iterate.h>
#include <p8est_extended.h>
#include <p8est_search.h>
#endif 

// HXT INCLUDES

extern "C" {
  #include "hxt_api.h"
  #include "hxt_mesh.h"
  #include "hxt_bbox.h"
}

typedef struct HXTForestOptions{
  double 				hmax;
  double 				hmin;
  double 				hbulk;
  double 				gradMax;
  int                   nodePerTwoPi;
  int                   nodePerGap;
  double               *bbox;
  double               *nodalCurvature;
  double               *nodeNormals;
  double              (*sizeFunction)(double, double, double, double) ;
  RTree<uint64_t,double,3>  *triRTree;
  HXTMesh              *mesh;
  const char           *filename;
} HXTForestOptions;

typedef struct HXTForest{
#ifdef HAVE_P4EST
  p4est_t          *p4est;
#endif 
  HXTForestOptions  *forestOptions;
} HXTForest;

// Donnees disponibles sur chaque quadrant
typedef struct size_data{
  double size;
#ifdef HAVE_P4EST
  double ds[P4EST_DIM];
#endif 
  double d2s; // Laplacien

  double h;
  // Les tailles pour les differences finies
  double h_xL, h_xR;
  double h_yD, h_yU;
  
  double h_xavg;
  double h_yavg;
  
  double h_zB, h_zT;
  double h_zavg;

  double hMin;
  
  int refineFlag; 
  int coarsenFlag; 
  
} size_data_t;

// Un point pour la recherche dans l'arbre
typedef struct size_point{
  double x;
  double y;
  double z;
  double size;
  int surfaceFlag;
  bool isFound;
} size_point_t;

typedef struct size_fun{
  double (*myFun)(double, double, double);
} size_fun_t;

// API ---------------------------------------------------------------------------------------------
HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, HXTForestOptions *forestOptions);
HXTStatus hxtForestDelete(HXTForest **forest);
HXTStatus hxtForestOptionsCreate(HXTForestOptions **forestOptions);
HXTStatus hxtForestOptionsDelete(HXTForestOptions **forestOptions);

HXTStatus hxtOctreeRefineToBulkSize(HXTForest *forest);
HXTStatus hxtOctreeCurvatureRefine(HXTForest *forest, int nMax);

HXTStatus hxtOctreeComputeGradient(HXTForest *forest);
HXTStatus hxtOctreeSetMaxGradient(HXTForest *forest);
HXTStatus hxtOctreeComputeMaxGradientX(HXTForest *forest, double *dsdx_max);
HXTStatus hxtOctreeComputeMaxGradientY(HXTForest *forest, double *dsdy_max);
HXTStatus hxtOctreeComputeMaxGradientZ(HXTForest *forest, double *dsdz_max);
HXTStatus hxtOctreeComputeMinimumSize(HXTForest *forest, double *size_min);
HXTStatus hxtOctreeComputeMaximumSize(HXTForest *forest, double *size_max);

HXTStatus hxtOctreeSmoothGradient(HXTForest *forest, int nMax);

HXTStatus hxtOctreeSurfacesProches(HXTForest *forest);
HXTStatus hxtOctreeElementEstimation(HXTForest *forest, double *elemEstimate);
HXTStatus hxtOctreeSearchOne(HXTForest *forest, double x, double y, double z, double *size);

HXTStatus hxtOctreeExport(HXTForest *forest);

#endif
