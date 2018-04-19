#include "hxt_mesh.h"
#include "hxt_vertices.h"
#include "predicates.h"
#include "hxt_sort.h"

#define SWAP(x,y) do{uint32_t tmp=x; x=y; y=tmp;}while(0)

/**********************************************
 (re-)compute adjacency of the tetrahedral mesh
 **********************************************/
typedef struct{
  uint32_t node[3];
  uint64_t face;
} triangleInfo;

typedef struct{
  uint64_t node;
  uint64_t face;
}triangleInfoFast;

static inline uint32_t triangleKey0(triangleInfo* t, const void* userData){
  return t->node[0];
}

static inline uint32_t triangleKey1(triangleInfo* t, const void* userData){
  return t->node[1];
}

static inline uint32_t triangleKey2(triangleInfo* t, const void* userData){
  return t->node[2];
}

static inline uint64_t triangleKeyFast(triangleInfoFast* t, const void* userData){
  return t->node;
}

static HXTStatus triangleSort(triangleInfo* triangles, uint32_t n,
                              uint32_t (*triangleKey)(triangleInfo*, const void*),
                              uint32_t max){
  HXTSORT32_UNIFORM(triangleInfo, triangles, n, max, triangleKey, NULL);
  return HXT_STATUS_OK;
}


HXTStatus hxtComputeAdjacencies(HXTMesh* mesh){
  const uint64_t nTet = mesh->tetrahedra.num;
  const uint64_t n = mesh->vertices.num+1;

  // make sure it was allocated
  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
  HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.neigh, mesh->tetrahedra.size*4*sizeof(uint64_t)) );

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num*4; i++) {
    mesh->tetrahedra.neigh[i] = HXT_NO_ADJACENT;
  }

  // first step, create all triangles...
  triangleInfo* triangles;
  triangleInfoFast* trianglesFast; // used when n^3 can fit in 64 bits

  if(n > 2642245)// n^3 cannot be on 64 bits
    HXT_CHECK( hxtAlignedMalloc(&triangles, nTet*4*sizeof(triangleInfo)) );
  else
    HXT_CHECK( hxtAlignedMalloc(&trianglesFast, nTet*4*sizeof(triangleInfoFast)) );

  int hxtDeclareAligned indices[4][4] = {{1,2,3,0},{0,2,3,0},{0,1,3,0},{0,1,2,0}}; // 4th is just a padding

  // fill the triangle structure
  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint32_t* node = mesh->tetrahedra.node + 4*i;
    int hxtDeclareAligned order[4];

    // sort a and b
    int cmp1 = (node[0] <= node[1]);
    int cmp2 = (node[2] <= node[3]);
    order[0] = !cmp1;
    order[1] = cmp1;
    order[2] = 2 + !cmp2;
    order[3] = 2 + cmp2;

    // after this, order[0] is at the right place
    if(node[order[2]] < node[order[0]]){
      SWAP(order[0], order[2]);
    }

    // after this, order[3] is at the right place
    if(node[order[3]] < node[order[1]]){
      SWAP(order[3], order[1]);
    }

    // remains order[1] and order[2]
    if(node[order[2]] < node[order[1]]){
      SWAP(order[1], order[2]);
    }

    // on some architecture, this is a simple SIMD operation
    uint32_t hxtDeclareAligned nodeOrdered[4];
    for (int j=0; j<4; j++) {
      nodeOrdered[j] = node[order[j]];
    }

    if(nodeOrdered[3]==HXT_GHOST_VERTEX)
      nodeOrdered[3] = mesh->vertices.num;

    if(n > 2642245){
      for (int j=0; j<4; j++) {
        triangles[i*4+j].node[0] = nodeOrdered[indices[j][0]];
        triangles[i*4+j].node[1] = nodeOrdered[indices[j][1]];
        triangles[i*4+j].node[2] = nodeOrdered[indices[j][2]];
        triangles[i*4+j].face = i*4 + order[j];
      }
    }
    else{
      for (int j=0; j<4; j++) {
        trianglesFast[i*4+j].node = nodeOrdered[indices[j][0]]*n*n
                                  + nodeOrdered[indices[j][1]]*n
                                  + nodeOrdered[indices[j][2]];
        trianglesFast[i*4+j].face = i*4 + order[j];
      }
    }


  }

  // sort the triangles...
  if(n > 2642245)
  {
    HXT_CHECK( triangleSort(triangles, nTet*4, triangleKey2, mesh->vertices.num) );
    HXT_CHECK( triangleSort(triangles, nTet*4, triangleKey1, mesh->vertices.num) );
    HXT_CHECK( triangleSort(triangles, nTet*4, triangleKey0, mesh->vertices.num) );

    // now that triangles are sorted, when two are the same, we
    #pragma omp parallel for
    for (uint64_t i=0; i<nTet*4-1; i++) {
      if(triangles[i].node[0]==triangles[i+1].node[0] &&
         triangles[i].node[1]==triangles[i+1].node[1] &&
         triangles[i].node[2]==triangles[i+1].node[2])
      {
        mesh->tetrahedra.neigh[triangles[i].face] = triangles[i+1].face;
        mesh->tetrahedra.neigh[triangles[i+1].face] = triangles[i].face;
        // i++; // can be done but break SIMD
      }
    }

    HXT_CHECK( hxtAlignedFree(&triangles) );
  }
  else{
    HXTSORT64_UNIFORM(triangleInfoFast, trianglesFast, nTet*4, n*n*n-1, triangleKeyFast, NULL);

    #pragma omp parallel for
    for (uint64_t i=0; i<nTet*4-1; i++) {
      if(trianglesFast[i].node==trianglesFast[i+1].node)
      {
        mesh->tetrahedra.neigh[trianglesFast[i].face] = trianglesFast[i+1].face;
        mesh->tetrahedra.neigh[trianglesFast[i+1].face] = trianglesFast[i].face;
        // i++; // can be done but break SIMD
      }
    }

    HXT_CHECK( hxtAlignedFree(&trianglesFast) );
  }




  return HXT_STATUS_OK;
}