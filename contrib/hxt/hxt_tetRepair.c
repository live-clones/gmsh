#include "hxt_mesh.h"
#include "hxt_vertices.h"
#include "predicates.h"
#include "hxt_sort.h"
#include "hxt_tetRepair.h"
#include "hxt_tetFlag.h"

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
    for (uint64_t i=0; i<nTet*4-1; i++) {
      if(triplet[i].v[0]==triplet[i+1].v[0] &&
         triplet[i].v[1]==triplet[i+1].v[1])
      {
        mesh->tetrahedra.neigh[triplet[i].v[2]] = triplet[i+1].v[2];
        mesh->tetrahedra.neigh[triplet[i+1].v[2]] = triplet[i].v[2];
        // i++; // can be done but break SIMD
      }
    }

    HXT_CHECK( hxtAlignedFree(&triplet) );
  }
  else{
    HXT_CHECK( group2_sort_v0(pair, nTet*4, n*n*n-1) );

    #pragma omp parallel for
    for (uint64_t i=0; i<nTet*4-1; i++) {
      if(pair[i].v[0]==pair[i+1].v[0])
      {
        mesh->tetrahedra.neigh[pair[i].v[1]] = pair[i+1].v[1];
        mesh->tetrahedra.neigh[pair[i+1].v[1]] = pair[i].v[1];
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
    #pragma omp simd aligned(newNode:SIMD_ALIGN) aligned(oldNode:16)
    for (unsigned j=0; j<4; j++)
      newNode[i*4+j] = oldNode[j]; 
  }

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
  mesh->tetrahedra.node = newNode;

  uint16_t* newColor;
  HXT_CHECK( hxtAlignedMalloc(&newColor, mesh->tetrahedra.size*sizeof(uint16_t)));

  #pragma omp parallel for
  for (uint64_t i=0; i<nTet; i++) {
    uint64_t index = pair[i].v[1];
    newColor[i] = mesh->tetrahedra.colors[index]; 
  }

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.colors) );
  mesh->tetrahedra.colors = newColor;

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

    if(orient3d(coord+4*node[0], coord+4*node[1], coord+4*node[2], coord+4*node[3])<0){
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

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
  {

    // if(errorOccured)
    //   continue;

    uint32_t* Node = mesh->tetrahedra.node + i*4;
    uint64_t* Neigh = mesh->tetrahedra.neigh + i*4;

    if(isTetDeleted(mesh, i)){
      // HXT_WARNING("deleted tetrahedra remain in the mesh");
      continue;
    }

    // check for good placement of ghost vertex
    if(Node[0]==HXT_GHOST_VERTEX || Node[1]==HXT_GHOST_VERTEX || Node[2]==HXT_GHOST_VERTEX){
      HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost vertex at wrong place in tet. %lu", i);
      errorOccured=1;
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
    if(Node[3]!=HXT_GHOST_VERTEX && orient3d(a,b,c,vertices[Node[3]].coord)<=0.0){
      HXT_ERROR_MSG(HXT_STATUS_ERROR, "orientation of tet %lu is wrong",i);
      errorOccured=1;
      continue;
    }

    // check the neighbors
    for (unsigned j=0; j<4; j++)
    {
      uint64_t neigh = Neigh[j];

      if(neigh==HXT_NO_ADJACENT){
        continue;
      }

      if(neigh>=mesh->tetrahedra.num*4) {
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "%uth neighbor of tet %lu does not exist", j, i);
        errorOccured=1;
        continue;
      }

      // uint64_t* NeighNeigh = mesh->tetrahedra.neigh + neigh;
      uint32_t* NeighNode = mesh->tetrahedra.node + neigh/4*4;
      
      if(mesh->tetrahedra.neigh[neigh]!=i*4+j){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "tet %lu (%lu/4) is not the neighbor of its %uth neighbor %lu (%lu/4)", i, i*4,j, neigh/4, neigh);
        errorOccured=1;
        continue;
      }

      uint32_t V[3] = { Node[((j+1)&3)], Node[((j&2)^3)], Node[((j+3)&2)]};
      unsigned l;

      for (l=0; l<3; l++)
      {
        if(NeighNode[(((neigh&3)+1)&3)]==V[l] && NeighNode[(((neigh&3)&2)^3)]==V[(l+1)%3] && NeighNode[(((neigh&3)+3)&2)]==V[(l+2)%3])
           break;
      }

      if(l!=3){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet. %lu is intersecting it (common face has the same orientation)",j,i);
        errorOccured=1;
        continue;
      }

      for (l=0; l<3; l++)
      {
        if(NeighNode[(((neigh&3)+1)&3)]==V[l] && NeighNode[(((neigh&3)&2)^3)]==V[(l+2)%3] && NeighNode[(((neigh&3)+3)&2)]==V[(l+1)%3])
           break;
      }

      if(l==3){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet. %lu doesn't contain 3 common vertices",j,i);
        errorOccured=1;
        continue;
      }


      if((isFacetConstrained(mesh, i*4+j)!=0) ^ (isFacetConstrained(mesh, neigh)!=0)) {
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "constraint is not consistent on both side of facet 4*%lu+%u",i,j);
        errorOccured=1;
        continue;
      }

      // only for delaunay triangulation...
      // if(Node[3]!=HXT_GHOST_VERTEX && NeighNode[neigh&3]!=HXT_GHOST_VERTEX && insphere(vertices[Node[0]].coord,
      //             vertices[Node[1]].coord,
      //             vertices[Node[2]].coord,
      //             vertices[Node[3]].coord,
      //             vertices[NeighNode[neigh&3]].coord)>0.0){
      //   HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet %lu has it's non-common node in the sphere (insphere(%u %u %u %u %u)>0)",j,i*4, Node[0], Node[1], Node[2], Node[3], NeighNode[neigh&3]);
      //   errorOccured=1;
      //   continue;
      // }
    }
  }

  if(errorOccured)
    return HXT_STATUS_ERROR;
  return HXT_STATUS_OK;
}
