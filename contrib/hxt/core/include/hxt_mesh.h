#ifndef HXT_MESH_H
#define HXT_MESH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_message.h"
#include <stdint.h>

#define HXT_GHOST_VERTEX UINT32_MAX

#define HXT_NO_ADJACENT UINT64_MAX

#define HXT_COLOR_OUT UINT32_MAX

typedef struct {
  // vertices
  struct {
    double* coord; // 3 coordinates + 1 double per vertex!
    uint32_t num;
    uint32_t size;
  } vertices;

  // tetrahedra
  struct {
    uint32_t* node;  // aligned (size = tetrahedra.size*4*sizeof(uint32_t))
    uint64_t* neigh; // aligned (size = tetrahedra.size*4*sizeof(uint64_t))
    uint32_t* color;
    uint16_t* flag;
    uint64_t num;    // number of tetrahedra
    uint64_t size;   // reserved number of tetrahedra (size of the vector)
  } tetrahedra;
  
  // triangles
  struct {
    uint32_t* node;
    uint32_t* color;
    uint64_t num;
    uint64_t size;
  } triangles;

  // lines
  struct {
    uint32_t* node;
    uint32_t* color;
    uint64_t num;
    uint64_t size;
  } lines;

  struct {
    uint32_t* node;
    uint32_t* color;
    uint32_t num;
    uint32_t size;
  } points;

  // boundary representation
  struct {
    uint32_t numVolumes;
    uint32_t *numSurfacesPerVolume;
    uint32_t *surfacesPerVolume;
    uint32_t numSurfaces;
    uint32_t *numCurvesPerSurface;
    uint32_t *curvesPerSurface;
    uint32_t numCurves;
    uint32_t *endPointsOfCurves;
    uint32_t numPoints;
    uint32_t *points;
  } brep;
} HXTMesh;

HXTStatus  hxtMeshCreate          ( HXTMesh** mesh);
HXTStatus  hxtMeshDelete          ( HXTMesh** meshPtr);

// mesh I/O
HXTStatus  hxtMeshReadGmsh       ( HXTMesh* mesh, const char* filename);
HXTStatus  hxtMeshWriteGmsh      ( HXTMesh* mesh, const char* filename);


#ifdef __cplusplus
}
#endif

#endif
