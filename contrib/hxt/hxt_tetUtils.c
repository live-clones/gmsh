#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"

#define MAX(x,y) ((x)>(y) ? (x) : (y))

/***********************************
 * remove deleted tetrahedra of mesh
 ***********************************/
// TODO: a parallel technique
HXTStatus hxtRemoveDeleted(HXTMesh* mesh)
{
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(isTetDeleted(mesh, i)){
      for (unsigned j=0; j<4; j++) {
        uint64_t neigh = mesh->tetrahedra.neigh[4*i+j]; // neighbor of the deleted tet
        if(neigh!=HXT_NO_ADJACENT) // the deleted tet had a neighbor pointing to him...
          mesh->tetrahedra.neigh[neigh] = HXT_NO_ADJACENT;
      }
    }
  }

  uint64_t right = mesh->tetrahedra.num-1;
  uint64_t left = 0;

  while(1) {
    while(left < right && isTetDeleted(mesh, right)) right--;
    while(left < right && isTetDeleted(mesh, left)==0) left++;

    if(left >= right)
      break;

    mesh->tetrahedra.colors[left] = mesh->tetrahedra.colors[right];
    mesh->tetrahedra.flag[left] = mesh->tetrahedra.flag[right];

    // swap the two tetrahedra
    for (unsigned j=0; j<4; j++) {
      uint64_t neighR = mesh->tetrahedra.neigh[4*right+j]; // neighbor of the tet that will be moved (not deleted)
      if(neighR!=HXT_NO_ADJACENT)
        mesh->tetrahedra.neigh[neighR] = 4*left+j;

      mesh->tetrahedra.node[4*left+j] = mesh->tetrahedra.node[4*right+j];
      mesh->tetrahedra.neigh[4*left+j] = neighR;
    }

    left++; right--;
  }

  if(left==right && isTetDeleted(mesh, left)==0) left++;

  mesh->tetrahedra.num = left;

  return HXT_STATUS_OK;
}


/***************************************
 * remove ghost tetrahedra from the mesh
 * see header for more information
 ***************************************/
HXTStatus hxtRemoveGhosts(HXTMesh* mesh){
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX){
      markTetAsDeleted(mesh, i);
    }
  }

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  return HXT_STATUS_OK;
}



/**********************************
 * add ghost tetrahedra to the mesh
 * see header for more information
 **********************************/
HXTStatus hxtAddGhosts(HXTMesh* mesh){
  int maxThreads = omp_get_max_threads();

  uint64_t* hullCount;
  HXTGroup2* edges;
  uint64_t totalHullCount = 0;
  HXT_CHECK( hxtMalloc(&hullCount, maxThreads*sizeof(uint64_t)) );

  HXTStatus status = HXT_STATUS_OK;

  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    hullCount[threadID] = 0;

    // count the number of convex hull faces
    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      for (unsigned j=0; j<4; j++) {
        if(mesh->tetrahedra.neigh[4*i+j]==HXT_NO_ADJACENT)
          hullCount[threadID]++;
      }
    }

    // exclusive scan + allocation
    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();

      for (int i=0; i<nthreads; i++) {
        uint64_t tsum = hullCount[i] + totalHullCount;
        hullCount[i] = totalHullCount;
        totalHullCount = tsum;
      }

      status = hxtTetrahedraReserve(mesh, totalHullCount+mesh->tetrahedra.num);
      if(status!=HXT_STATUS_OK)
        HXT_TRACE(status);
      else {
        status = hxtAlignedMalloc(&edges, 3*totalHullCount*sizeof(HXTGroup2));
        if(status!=HXT_STATUS_OK)
          HXT_TRACE(status);
      }
    }


    if(status== HXT_STATUS_OK){
      // create the Ghost tet.
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        for (unsigned j=0; j<4; j++) {
          if(mesh->tetrahedra.neigh[4*i+j]==HXT_NO_ADJACENT){
            uint64_t newGhost = hullCount[threadID] + mesh->tetrahedra.num;

            mesh->tetrahedra.neigh[4*i+j] = 4*newGhost+3;
            mesh->tetrahedra.neigh[4*newGhost+3] = 4*i+j;

            mesh->tetrahedra.colors[newGhost] = UINT16_MAX;
            mesh->tetrahedra.flag[newGhost] = 0;
            if(isFacetConstrained(mesh, 4*i+j))
              constrainFacet(mesh, 4*newGhost+3);

            uint32_t v0, v1, v2;

            v0 = mesh->tetrahedra.node[4*i+((j+1)&3)];
            v1 = mesh->tetrahedra.node[4*i+((j+3)&2)];
            v2 = mesh->tetrahedra.node[4*i+((j&2)^3)];

            mesh->tetrahedra.node[4*newGhost+0] = v0;
            mesh->tetrahedra.node[4*newGhost+1] = v1;
            mesh->tetrahedra.node[4*newGhost+2] = v2;
            mesh->tetrahedra.node[4*newGhost+3] = HXT_GHOST_VERTEX;

            uint64_t index = 3*hullCount[threadID];

            edges[index+0].v[0] = (v0<v1)?(uint64_t) v0*mesh->vertices.num+v1 : (uint64_t) v1*mesh->vertices.num+v0;
            edges[index+0].v[1] = 4*newGhost+2;
            edges[index+1].v[0] = (v0<v2)?(uint64_t) v0*mesh->vertices.num+v2 : (uint64_t) v2*mesh->vertices.num+v0;
            edges[index+1].v[1] = 4*newGhost+1;
            edges[index+2].v[0] = (v1<v2)?(uint64_t) v1*mesh->vertices.num+v2 : (uint64_t) v2*mesh->vertices.num+v1;
            edges[index+2].v[1] = 4*newGhost+0;

            hullCount[threadID]++;
          }
        }
      }
    }
  }

  if(status!=HXT_STATUS_OK){
    return status;
  }

  mesh->tetrahedra.num+=totalHullCount;

  // now we have to find the adjacencies between ghosts
  const uint64_t max = (uint64_t) mesh->vertices.num*mesh->vertices.num;
  const uint64_t n = totalHullCount*3;
  HXT_CHECK(  group2_sort_v0(edges, n, max) );

  // connect adjacencies
  #pragma omp parallel for
  for (uint64_t i=0; i<n; i+=2) {
    mesh->tetrahedra.neigh[edges[i].v[1]] = edges[i+1].v[1];
    mesh->tetrahedra.neigh[edges[i+1].v[1]] = edges[i].v[1];
  }

  // first make a list with all edges
  HXT_CHECK( hxtAlignedFree(&edges) );
  HXT_CHECK( hxtFree(&hullCount) );

  return HXT_STATUS_OK;
}