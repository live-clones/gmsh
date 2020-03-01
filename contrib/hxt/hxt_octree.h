#ifndef HXT_OCTREE_H
#define HXT_OCTREE_H

// STD INCLUDES
#include <queue>
#include <vector>

// GMSH INCLUDES

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
  int           nRefine;
  int           nodePerTwoPi;
  int           nodePerGap;
  double       *bbox;
  double       *nodalCurvature;
  double       *nodeNormals;
  double      (*sizeFunction)(double, double, double, double);
  RTree<uint64_t,double,3>  *triRTree;
  HXTMesh      *mesh;
  const char   *filename;
} HXTForestOptions;

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
  // Size gradient
  double ds[P4EST_DIM];
#endif 
  double h;
  // Half cell length for finite differences
  double h_xL, h_xR;
  double h_yD, h_yU;
  double h_zB, h_zT;
  int isBoundary;
} size_data_t;

// A node to search in the tree
typedef struct size_point{
  double x;
  double y;
  double z;
  double size;
  bool isFound;
} size_point_t;

typedef struct size_fun{
  double (*myFun)(double, double, double);
} size_fun_t;

// API ---------------------------------------------------------------------------------------------
HXTStatus hxtForestOptionsCreate(HXTForestOptions **forestOptions);
HXTStatus hxtForestOptionsDelete(HXTForestOptions **forestOptions);

HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, HXTForestOptions *forestOptions);
HXTStatus hxtForestDelete(HXTForest **forest);

HXTStatus hxtForestExport(HXTForest *forest);
HXTStatus hxtForestLoad(HXTForest **forest, const char* filename);

HXTStatus hxtForestRefine(HXTForest *forest);
HXTStatus hxtForestSizeSmoothing(HXTForest *forest);
HXTStatus hxtOctreeSurfacesProches(HXTForest *forest);

HXTStatus hxtOctreeElementEstimation(HXTForest *forest, double *elemEstimate);
HXTStatus hxtOctreeSearchOne(HXTForest *forest, double x, double y, double z, double *size);

#endif
