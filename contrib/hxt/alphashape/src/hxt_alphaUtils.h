#ifndef HXT_ALPHAUTILS_H
#define HXT_ALPHAUTILS_H

#include "hxt_tetDelaunay.h"
#include "hxt_omp.h"

/**
 * \struct HXTAlphaShapeOptions
 * 
 * Options for the alpha shape functions
 * 
 *
 */
typedef struct {

  int colorIn;                 /* Color of tetrahedra inside alpha shape*/
  int colorOut;                /* Color of tetrahedra outside alpha shape*/
  int colorBoundary;           /* Color of triangles on the boundary of alpha shape*/

  double alpha;                /* Alpha value for alpha shape */
  double hMean;               /* Mean size of the mesh */   
  double minQuality;           /* Minimum quality of the elements in the mesh */
  double minRadius;            /* Minimum radius of the elements in the mesh */

  uint64_t n_tetrahedra;            /* size of following list */
  uint64_t* tetrahedra;        /**
                                List of tetrahedra in the alpha shape */
  uint32_t n_boundaryFacets;   /* size of following list */
  uint32_t* boundaryFacets;    /**
                                List of boundary facets of the alpha shape */

//   int verbosity;              /**<
//                                *  - if verbosity<=0: don't print information.
//                                *  - if verbosity==1: print basic information on each pass
//                                *  - if verbosity>=2: print everything */
} HXTAlphaShapeOptions;


double tetrahedron_circumcenter(const double a[3], const double b[3], const double c[3], const double d[3], double circumcenter[3], double* xi, double* eta,double* zeta);

double tetAlphaShape(HXTMesh* mesh, const int *tet, const double h);

double computeTetMeshSize(HXTMesh* mesh, HXTDelaunayOptions* delOptions, uint32_t *_tet);

int pointInTetrahedron(double *p0, double* p1, double *p2, double *p3, double *c);

void getTetCoordAndNodalSize(HXTMesh* mesh, double* nsarray, uint64_t tet, double tetCoord[4][4], double tetNodalSize[4]);

HXTStatus balanceRefineWorkInAlphaShape(HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, uint32_t* startPt, size_t* startTet, int maxThreads);

void cross(double* v0, double* v1, double *res);

double dot(double* v0, double* v1);

void triangleCircumCenter(double* p0, double* p1, double* p2, double* c);

uint64_t findPointInNeighbouringTets(HXTMesh* mesh, uint64_t tet, double* p);

void getTetVertices(HXTMesh* mesh, uint64_t tet, double pTet[4][3]);

#endif
