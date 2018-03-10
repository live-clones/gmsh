#ifndef _HEXTREME_MESH_
#define _HEXTREME_MESH_

#include "hxt_tools.h" // to have SIMD_ALIGN and stdint.h




#define HXT_GHOST_VERTEX UINT32_MAX
#define HXT_DELETED_COLOR (UINT16_MAX-1)

#define HXT_NO_ADJACENT UINT64_MAX


struct hxtMeshStruct {
  HXTContext* ctx;

  // vertices
  struct {
    uint32_t num;
    uint32_t size;
    double* coord; // 3 coordinates + 1 double per vertex!
  } vertices;
  uint64_t* typeStat; // to delete

  // tetrahedra
  struct {
    uint32_t* node;  // aligned (size = tetrahedra.size*4*sizeof(uint32_t))
    uint64_t* neigh; // aligned (size = tetrahedra.size*4*sizeof(uint64_t))
    uint16_t* colors;
    uint64_t num;    // number of tetrahedra
    uint64_t size;   // reserved number of tetrahedra (size of the vector)
  } tetrahedra;

  // triangles // TODO: consider writing a array of structure...
  struct {
    uint32_t* node;
    uint16_t* colors;
    uint64_t num;
    uint64_t size;
  } triangles;

  // lines // TODO: consider writing a array of structure...
  struct {
    uint32_t* node;
    uint16_t* colors;
    uint64_t num;
    uint64_t size;
  } lines;
};


#endif
