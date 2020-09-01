// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetRepair.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_vertices.h"
#include "predicates.h"
#include "hxt_sort.h"

/**
* \file hxt_tetRepair.c see header hxt_tetRepair.h
* \author Célestin Marot
*/

#define SWAP(x,y) do{int tmp=x; x=y; y=tmp;}while(0)

/**********************************************
 (re-)compute adjacency of the tetrahedral mesh
 **********************************************/
HXTStatus hxtTetAdjacencies(HXTMesh* mesh){
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
  HXTGroup3* triplet;
  HXTGroup2* pair; // used when n^3 can fit in 64 bits

  if(n > 2642245)// n^3 cannot be on 64 bits
    HXT_CHECK( hxtAlignedMalloc(&triplet, nTet*4*sizeof(HXTGroup3)) );
  else
    HXT_CHECK( hxtAlignedMalloc(&pair, nTet*4*sizeof(HXTGroup2)) );

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
        triplet[i*4+j].v[0] = nodeOrdered[indices[j][0]]*n
                            + nodeOrdered[indices[j][1]];
        triplet[i*4+j].v[1] = nodeOrdered[indices[j][2]];
        triplet[i*4+j].v[2] = i*4 + order[j];
      }
    }
    else{
      for (int j=0; j<4; j++) {
        pair[i*4+j].v[0] = nodeOrdered[indices[j][0]]*n*n
                         + nodeOrdered[indices[j][1]]*n
                         + nodeOrdered[indices[j][2]];
        pair[i*4+j].v[1] = i*4 + order[j];
      }
    }


  }

  // sort the triangles...
  if(n > 2642245)
  {
    HXT_CHECK( group3_sort_v1(triplet, nTet*4, n-1) );
    HXT_CHECK( group3_sort_v0(triplet, nTet*4, n*n-1) );

    // now that triangles are sorted, when two are the same, they are neighbors
    #pragma omp parallel for
    for (uint64_t i=1; i<nTet*4; i++) {
      if(triplet[i-1].v[0]==triplet[i].v[0] &&
         triplet[i-1].v[1]==triplet[i].v[1])
      {
        mesh->tetrahedra.neigh[triplet[i-1].v[2]] = triplet[i].v[2];
        mesh->tetrahedra.neigh[triplet[i].v[2]] = triplet[i-1].v[2];
        // i++; // can be done but break SIMD
      }
    }

    HXT_CHECK( hxtAlignedFree(&triplet) );
  }
  else{
    HXT_CHECK( group2_sort_v0(pair, nTet*4, n*n*n-1) );

    #pragma omp parallel for
    for (uint64_t i=1; i<nTet*4; i++) {
      if(pair[i-1].v[0]==pair[i].v[0])
      {
        mesh->tetrahedra.neigh[pair[i-1].v[1]] = pair[i].v[1];
        mesh->tetrahedra.neigh[pair[i].v[1]] = pair[i-1].v[1];
        // i++; // can be done but break SIMD
      }
    }

    HXT_CHECK( hxtAlignedFree(&pair) );
  }

  return HXT_STATUS_OK;
}



HXTStatus hxtTetReorder(HXTMesh* mesh)
{
  const uint64_t nTet = mesh->tetrahedra.num;
  const uint64_t n = mesh->vertices.num;
  uint64_t max = n*n*n-1;

  HXTGroup3* triplet;
  HXTGroup2* pair; // used when n^3 can fit in 64 bits

  if(n > 2642245){// n^3 cannot be on 64 bits
    HXT_CHECK( hxtAlignedMalloc(&triplet, nTet*4*sizeof(HXTGroup3)) );
    max = n*n-1;
  }

  HXT_CHECK( hxtAlignedMalloc(&pair, nTet*4*sizeof(HXTGroup2)) );

  if(n > 2642245){
    #pragma omp parallel for
    for (uint64_t i=0; i<nTet; i++) {
      triplet[i].v[0] = mesh->tetrahedra.node[4*i]*n
                        + mesh->tetrahedra.node[4*i+1];
      triplet[i].v[1] = mesh->tetrahedra.node[4*i+2];
      triplet[i].v[2] = i;
    }
  }
  else{
    #pragma omp parallel for
    for (uint64_t i=0; i<nTet; i++) {
      pair[i].v[0] = mesh->tetrahedra.node[4*i]*n*n
                   + mesh->tetrahedra.node[4*i+1]*n
                   + mesh->tetrahedra.node[4*i+2];
      pair[i].v[1] = i;
    }
  }

  if(n > 2642245)
  {
    HXT_CHECK( group3_sort_v1(triplet, nTet, n-1) );

    #pragma omp parallel for
    for (uint64_t i=0; i<nTet; i++) {
      pair[i].v[0] = triplet[i].v[0];
      pair[i].v[1] = triplet[i].v[2];
    }

    HXT_CHECK( hxtAlignedFree(&triplet) );
  }


  HXT_CHECK( group2_sort_v0(pair, nTet, max) );

  // we do not care about key anymore, put inverse index
  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    pair[pair[i].v[1]].v[0] = i;
  }

  uint64_t* newNeigh;
  HXT_CHECK( hxtAlignedMalloc(&newNeigh, mesh->tetrahedra.size*4*sizeof(uint64_t)));

  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint64_t index = pair[i].v[1];
    for (unsigned j=0; j<4; j++){
      uint64_t oldNeigh = mesh->tetrahedra.neigh[4*index+j];
      if(oldNeigh==HXT_NO_ADJACENT)
        newNeigh[i*4+j] = HXT_NO_ADJACENT;
      else
        newNeigh[i*4+j] = pair[oldNeigh/4].v[0]*4 + oldNeigh%4;
    }
  }

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
  mesh->tetrahedra.neigh = newNeigh;

  uint32_t* newNode;
  HXT_CHECK( hxtAlignedMalloc(&newNode, mesh->tetrahedra.size*4*sizeof(uint32_t)));

  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint64_t index = pair[i].v[1];
    uint32_t* oldNode = mesh->tetrahedra.node + 4*index;
    #pragma omp simd aligned(newNode:SIMD_ALIGN)
    for (unsigned j=0; j<4; j++)
      newNode[i*4+j] = oldNode[j]; 
  }

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
  mesh->tetrahedra.node = newNode;

  if(mesh->tetrahedra.color != NULL) {
    uint32_t* newColor;
    HXT_CHECK( hxtAlignedMalloc(&newColor, mesh->tetrahedra.size*sizeof(uint32_t)));

    #pragma omp parallel for
    for (uint64_t i=0; i<nTet; i++) {
      uint64_t index = pair[i].v[1];
      newColor[i] = mesh->tetrahedra.color[index]; 
    }

    HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.color) );
    mesh->tetrahedra.color = newColor;
  }

  uint16_t* newFlag;
  HXT_CHECK( hxtAlignedMalloc(&newFlag, mesh->tetrahedra.size*sizeof(uint16_t)));

  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint64_t index = pair[i].v[1];
    newFlag[i] = mesh->tetrahedra.flag[index]; 
  }

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.flag) );
  mesh->tetrahedra.flag = newFlag;

  HXT_CHECK( hxtAlignedFree(&pair) );

  return HXT_STATUS_OK;
}


// assume there is no ghost tetrahedron, this is to repair an imported mesh
HXTStatus hxtTetOrientNodes(HXTMesh* mesh)
{
  const uint64_t nTet = mesh->tetrahedra.num;
  const double* coord = mesh->vertices.coord;

  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint32_t* node = mesh->tetrahedra.node + 4*i;

    if(orient3d(coord+4*node[0], coord+4*node[1], coord+4*node[2], coord+4*node[3])>0){
      uint32_t tmp = node[0];
      node[0] = node[1];
      node[1] = tmp;
    }
  }

  return HXT_STATUS_OK;
}



HXTStatus hxtTetVerify(HXTMesh* mesh)
{
  volatile int errorOccured = 0;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  if(mesh->tetrahedra.node==NULL && mesh->tetrahedra.num!=0) {
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "list of nodes not given");
  }

  if(mesh->tetrahedra.neigh==NULL && mesh->tetrahedra.num!=0)
    HXT_WARNING("adjacencies not computed");

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
  {

    // if(errorOccured)
    //   continue;

    uint32_t* Node = mesh->tetrahedra.node + i*4;

    if(mesh->tetrahedra.flag && getDeletedFlag(mesh, i)){
      // HXT_WARNING("deleted tetrahedra remain in the mesh");
      continue;
    }

    // check for good placement of ghost vertex
    int localError = 0;
    for(int j=0; j<4; j++) {
      if(Node[j]==HXT_GHOST_VERTEX){
        if(j!=3) {
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost vertex at wrong place in tet. %lu", i);
          localError=1;
        }
      }
      else if(Node[j]>=mesh->vertices.num){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "node %d of tet. %lu does not exist", j, i);
        localError=2;
      }
    }

    if(localError) {
      errorOccured = localError;
      continue;
    }

    double* a = vertices[Node[0]].coord;
    double* b = vertices[Node[1]].coord;
    double* c = vertices[Node[2]].coord;

    // check for the orientation
    // if(Node[3]==0){
    //   HXT_WARNING("ghost tet. %lu remains in the array (did you clean the mesh?)",i*4);
    // }
    // else
    if(Node[3]!=HXT_GHOST_VERTEX && orient3d(a,b,c,vertices[Node[3]].coord)>=0.0){
      HXT_ERROR_MSG(HXT_STATUS_ERROR, "orientation of tet %lu is wrong",i);
      errorOccured=3;
      continue;
    }

    if(mesh->tetrahedra.neigh) {
      uint64_t* Neigh = mesh->tetrahedra.neigh + i*4;

      // check the neighbors
      for (unsigned j=0; j<4; j++)
      {
        if(Neigh[j]==HXT_NO_ADJACENT){
          continue;
        }

        uint64_t neigh = Neigh[j]/4;
        unsigned face = Neigh[j]%4;

        if(neigh>=mesh->tetrahedra.num) {
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "%uth neighbor of tet %lu does not exist", j, i);
          errorOccured=4;
          continue;
        }

        if(mesh->tetrahedra.flag && getDeletedFlag(mesh, neigh)) {
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "%uth neighbor of tet %lu is deleted", j, i);
          errorOccured=5;
          continue;
        }

        // uint64_t* NeighNeigh = mesh->tetrahedra.neigh + neigh;
        uint32_t* NeighNode = mesh->tetrahedra.node + neigh*4;
        
        if(mesh->tetrahedra.neigh[4*neigh+face]!=i*4+j){
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "tet %lu (%lu/4) is not the neighbor of its %uth neighbor %lu (%lu/4)", i, i*4,j, neigh, 4*neigh+face);
          errorOccured=6;
          continue;
        }

        uint32_t V[3] = { Node[getNode0FromFacet(j)], Node[getNode1FromFacet(j)], Node[getNode2FromFacet(j)]};
        unsigned l;

        for (l=0; l<3; l++)
        {
          if(NeighNode[getNode0FromFacet(face)]==V[l] && NeighNode[getNode1FromFacet(face)]==V[(l+1)%3] && NeighNode[getNode2FromFacet(face)]==V[(l+2)%3])
             break;
        }

        if(l!=3){
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet. %lu is intersecting it (common face has the same orientation)",j,i);
          errorOccured=7;
          continue;
        }

        for (l=0; l<3; l++)
        {
          if(NeighNode[getNode0FromFacet(face)]==V[l] && NeighNode[getNode2FromFacet(face)]==V[(l+1)%3] && NeighNode[getNode1FromFacet(face)]==V[(l+2)%3])
             break;
        }

        if(l==3){
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet. %lu doesn't contain 3 common vertices",j,i);
          errorOccured=8;
          continue;
        }

        if(mesh->tetrahedra.flag && (getFacetConstraint(mesh, i,j)!=0) ^ (getFacetConstraint(mesh, neigh, face)!=0)) {
          HXT_ERROR_MSG(HXT_STATUS_ERROR, "constraint is not consistent on both side of facet 4*%lu+%u",i,j);
          errorOccured=9;
          continue;
        }

        // only for delaunay triangulation...
        // if(Node[3]!=HXT_GHOST_VERTEX && NeighNode[face]!=HXT_GHOST_VERTEX && insphere(vertices[Node[0]].coord,
        //             vertices[Node[1]].coord,
        //             vertices[Node[2]].coord,
        //             vertices[Node[3]].coord,
        //             vertices[NeighNode[face]].coord)<0.0){
        //   HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet %lu has it's non-common node in the sphere (insphere(%u %u %u %u %u)>0)",j,i*4, Node[0], Node[1], Node[2], Node[3], NeighNode[face]);
        //   errorOccured=1;
        //   continue;
        // }
      }
    }
  }

  if(errorOccured)
    return HXT_STATUS_ERROR;
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
      setDeletedFlag(mesh, i);
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

            if(mesh->tetrahedra.color != NULL) 
              mesh->tetrahedra.color[newGhost] = HXT_COLOR_OUT;

            mesh->tetrahedra.flag[newGhost] = 0;
            if(getFacetConstraint(mesh, i, j))
              setFacetConstraint(mesh, newGhost, 3);

            setProcessedFlag(mesh, newGhost);

            uint32_t v0, v1, v2;

            v0 = mesh->tetrahedra.node[4*i+getNode0FromFacet(j)];
            v1 = mesh->tetrahedra.node[4*i+getNode2FromFacet(j)];
            v2 = mesh->tetrahedra.node[4*i+getNode1FromFacet(j)];

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