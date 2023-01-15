// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetDelaunay.h"
#include "hxt_tetDelaunayReshape.h"
#include "predicates.h"
#include "hxt_tetFlag.h"
#include "hxt_tetRepair.h"
#include "hxt_sort.h"
#include "hxt_tetNodalSize.h"


/**
* \file hxt_tetDelaunay.c see header hxt_tetDelaunay.h.
* \author Célestin Marot
*/

/* compile-time parameters */

#define SMALLEST_PASS 2048


/* usefull macros */
#define HXT_OMP_CHECK(status) do{ HXTStatus _tmp_ = (status); \
    if(_tmp_<0){ \
      if(_tmp_>HXT_STATUS_INTERNAL) \
        HXT_TRACE_MSG(_tmp_, "cannot break OpenMP region -> exiting"); \
      exit(_tmp_); \
    } \
  }while(0)


static int compareNodeLexicographically(uint32_t* nodes0, uint32_t* nodes1)
{
  for(int i=0; i<4; i++) {
    if(nodes0[i] < nodes1[i])
      return -1;
    else if(nodes0[i] > nodes1[i])
      return 1;
  }
  return 0;
}


/***********************************
 * create the initial tetrahedron 
 * surrounded by 4 ghost tetrahedra
 ***********************************/
static inline HXTStatus hxtTetrahedraInit(HXTMesh* mesh, HXTNodeInfo* nodeInfo, uint32_t nToInsert, int verbosity){
  if(nToInsert < 4){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "cannot mesh less than four points");
  }
  if(mesh->tetrahedra.size < 5){
    uint64_t sizeEstim = omp_get_max_threads()*DELETED_BUFFER_SIZE+8UL*nToInsert;
    uint64_t maxSizeEstim = MAX(sizeEstim, 10UL*nToInsert);
    HXT_CHECK( hxtTetrahedraReserve(mesh, maxSizeEstim) );
    HXT_INFO_COND(verbosity>1, "Initialization reserved %lu Tet.", mesh->tetrahedra.size);
  }

  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  // find non-coplanar vertices
  int orientation = 0;
  uint32_t i=0, j=1, k=2, l=3;
  for (i=0; orientation==0 && i<nToInsert-3; i++)
  {
    double* d = vertices[nodeInfo[i].node].coord;
    for (j=i+1; orientation==0 && j<nToInsert-2; j++)
    {
      double* c = vertices[nodeInfo[j].node].coord;
      double cdx = c[0] - d[0];
      double cdy = c[1] - d[1];
      double cdz = c[2] - d[2];
      if(cdx == 0.0 && cdy == 0.0 && cdz == 0.0)
        continue;
      for (k=j+1; orientation==0 && k<nToInsert-1; k++)
      {
        double* b = vertices[nodeInfo[k].node].coord;
        double bdx = b[0] - d[0];
        double bdy = b[1] - d[1];
        double bdz = b[2] - d[2];

        double crossx = bdy * cdz - bdz * cdy;
        double crossy = bdz * cdx - bdx * cdz;
        double crossz = bdx * cdy - bdy * cdx;
        // check for collinearity: cross product
        if(crossx == 0.0 && crossy == 0.0 && crossz == 0.0)
          continue;
        for (l=k+1; orientation==0 && l<nToInsert; l++)
        {
          double* a = vertices[nodeInfo[l].node].coord;
          double adx = a[0] - d[0];
          double ady = a[1] - d[1];
          double adz = a[2] - d[2];
          double det = adx * crossx + ady * crossy + adz * crossz;
          orientation = (det > o3dstaticfilter) - (det < -o3dstaticfilter);
        }
      }
    }
  }
  l--; k--; j--; i--;


  if(orientation==0){
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "all vertices are coplanar or nearly coplanar");
  }

  // swap 0<->i  1<->j 2<->k 3<->l
  {
    HXTNodeInfo tmp = nodeInfo[i];
    nodeInfo[i] = nodeInfo[0];
    nodeInfo[0] = tmp;
    nodeInfo[0].status = HXT_STATUS_TRUE;
    i = 0;

    tmp = nodeInfo[j];
    nodeInfo[j] = nodeInfo[1];
    nodeInfo[1] = tmp;
    nodeInfo[1].status = HXT_STATUS_TRUE;
    j = 1;

    tmp = nodeInfo[k];
    nodeInfo[k] = nodeInfo[2];
    nodeInfo[2] = tmp;
    nodeInfo[2].status = HXT_STATUS_TRUE;
    k = 2;

    tmp = nodeInfo[l];
    nodeInfo[l] = nodeInfo[3];
    nodeInfo[3] = tmp;
    nodeInfo[3].status = HXT_STATUS_TRUE;
    l = 3;
  }


  if(orientation > 0){
    uint32_t tmp = i;
    i = j;
    j = tmp;
  }

  mesh->tetrahedra.neigh[ 0] = 19;    mesh->tetrahedra.node[ 0] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[ 1] = 15;    mesh->tetrahedra.node[ 1] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[ 2] = 11;    mesh->tetrahedra.node[ 2] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[ 3] =  7;    mesh->tetrahedra.node[ 3] = nodeInfo[i].node;

  mesh->tetrahedra.neigh[ 4] = 18;    mesh->tetrahedra.node[ 4] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[ 5] = 10;    mesh->tetrahedra.node[ 5] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[ 6] = 13;    mesh->tetrahedra.node[ 6] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[ 7] =  3;    mesh->tetrahedra.node[ 7] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[8 ] = 17;    mesh->tetrahedra.node[ 8] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[9 ] = 14;    mesh->tetrahedra.node[ 9] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[10] =  5;    mesh->tetrahedra.node[10] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[11] =  2;    mesh->tetrahedra.node[11] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[12] = 16;    mesh->tetrahedra.node[12] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[13] =  6;    mesh->tetrahedra.node[13] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[14] =  9;    mesh->tetrahedra.node[14] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[15] =  1;    mesh->tetrahedra.node[15] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[16] = 12;    mesh->tetrahedra.node[16] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[17] =  8;    mesh->tetrahedra.node[17] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[18] =  4;    mesh->tetrahedra.node[18] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[19] =  0;    mesh->tetrahedra.node[19] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.num = 5;

  if(mesh->tetrahedra.color != NULL) {
    for (uint64_t tet=0; tet<5; tet++){
      mesh->tetrahedra.color[tet] = HXT_COLOR_OUT;
    }
  }

  for (uint64_t tet=0; tet<5; tet++){
    mesh->tetrahedra.flag[tet] = 0;
  }

  return HXT_STATUS_OK;
}


/***********************************
 * fill the passes array which tells
 * the size of each BRIO round.
 * return the number of BRIO passes
 ***********************************/
unsigned computePasses(uint32_t passes[12],
                       uint32_t nInserted,
                       uint32_t nToInsert,
                       double partitionability,
                       int maxPartitions)
{
  double alpha = 1.0/(maxPartitions*maxPartitions);
  nInserted *= ((1.0 - alpha) * partitionability + alpha);

  unsigned npasses=0;
  passes[0] = nToInsert;

  for (unsigned i=0; i<10; i++) {
    if(passes[i] < SMALLEST_PASS || passes[i]/8 < nInserted){
      passes[i+1] = 0;
      npasses = i+1;
      break;
    }
    passes[i+1] = passes[i]/7.5;
  }

  for(unsigned i=0; i<=npasses/2; i++){
    uint32_t tmp = passes[i];
    passes[i] = passes[npasses-i];
    passes[npasses-i] = tmp;
  }

  return npasses;
}


/******************************************
 * initialization of the TetLocal structure
 ******************************************/
static inline HXTStatus localInit(TetLocal* local){
  local->ball.size = 1024;
  local->ball.num = 0;
  HXT_CHECK( hxtAlignedMalloc(&local->ball.array, sizeof(cavityBnd_t)*local->ball.size));

  local->deleted.size = DELETED_BUFFER_SIZE;
  local->deleted.num = 0;
  local->deleted.createdNew = 0;
  HXT_CHECK( hxtAlignedMalloc(&local->deleted.array, sizeof(uint64_t)*local->deleted.size) );

  return HXT_STATUS_OK;
}


/************************************
 * check if a tetrahedra is entirely
 * in the calling thread's partition
 ***********************************/
static inline HXTStatus checkTetrahedron(HXTVertex* vertices, HXTPartition* partition, const uint32_t* nodes){
  /* Actually, one vertex (not more) could be in another partition without creating a conflict.
   However, all threads would have to have a verticesID array => a lot of memory space wasted.
   Instead, we only allow the ghost vertex to be in another partition, it is handled differently in
   computeAdjacenciesFast function */
  uint64_t len = partition->lengthDist;
  uint64_t start = partition->startDist;

  // if(local->partition.lengthDist==UINT64_MAX) // if we are working with one thread only
  //   return HXT_STATUS_OK;

  if(vertexOutOfPartition(vertices, nodes[0], len, start) || 
     vertexOutOfPartition(vertices, nodes[1], len, start) ||
     vertexOutOfPartition(vertices, nodes[2], len, start) ||
     (nodes[3]!=HXT_GHOST_VERTEX && vertexOutOfPartition(vertices, nodes[3], len, start)) )
    return HXT_STATUS_INTERNAL;

  return HXT_STATUS_OK;
}


static inline void computeMeanNodalSize(TetLocal* local, HXTNodalSizes* nodalSizes, const uint32_t vta)
{
  double vtaNodalSize = 0.0;
  double denom = 0.0;

  for (uint64_t i = 0 ; i< local->ball.num ; i++) {
    for (unsigned j=0;j<3;j++) {
      uint32_t nodej = local->ball.array[i].node[j];

      if(nodej != HXT_GHOST_VERTEX && nodalSizes->array[nodej] > 0.0) {
        vtaNodalSize += nodalSizes->array[nodej];
        denom += 1.0;
      }
    }
  }

  if(denom > 0.0)
    nodalSizes->array[vta] = vtaNodalSize / denom;
}


/* if one edge of the cavity is shorter than the nodalSize, return HXT_STATUS_INTERNAL */
static inline HXTStatus filterCavity (TetLocal* local, HXTMesh *mesh, const HXTNodalSizes* nodalSizes, const uint32_t vta)
{
  double *vtaCoord = mesh->vertices.coord + 4*vta;
  double vtaNodalSize = nodalSizes->array[vta];

  for (uint64_t i = 0 ; i< local->ball.num ; i++) {
    for (unsigned j=0;j<3;j++) {
      uint32_t nodej = local->ball.array[i].node[j];

      if (nodej != HXT_GHOST_VERTEX){
        double *Xj = mesh->vertices.coord + 4*nodej;
        double otherNodalSize = nodalSizes->array[nodej];
        if(otherNodalSize <= 0.0){
          otherNodalSize = vtaNodalSize;
        }
        if( isTooClose(vtaNodalSize, otherNodalSize, squareDist(vtaCoord, Xj), nodalSizes) )
          return HXT_STATUS_INTERNAL;
      }
    }
  }
  return  HXT_STATUS_OK;
}

static inline HXTStatus filterTet(HXTMesh* mesh, const HXTNodalSizes* nodalSizes, const uint64_t curTet, const uint32_t vta){
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  double *vtaCoord = vertices[vta].coord;
  double vtaNodalSize = nodalSizes->array[vta];

  for (unsigned j=0; j<4; j++) {
    uint32_t nodej = mesh->tetrahedra.node[4*curTet+j];

    if (j!=3 || nodej != HXT_GHOST_VERTEX){
      double* Xj = vertices[nodej].coord;
      double otherNodalSize = nodalSizes->array[nodej];
      if(otherNodalSize <= 0.0){
        otherNodalSize = vtaNodalSize;
      }
      if( isTooClose(vtaNodalSize, otherNodalSize, squareDist(vtaCoord, Xj), nodalSizes) )
          return HXT_STATUS_INTERNAL;
    }
  }
  return HXT_STATUS_OK;
}


/* restore the structure as it was before the failed insertion attempt */
static inline void restoreDeleted(HXTMesh* mesh, TetLocal* local, const uint64_t prevDeleted){
  for (uint64_t i=prevDeleted; i<local->deleted.num; i++)
    unsetDeletedFlag(mesh, local->deleted.array[i]);

  local->deleted.num = prevDeleted;
}


static inline int insphere_sign(const double* const __restrict__ pa, const double* const __restrict__ pb, const double* const __restrict__ pc, const double* const __restrict__ pd, const double* const __restrict__ pe) {
  double aex, bex, cex, dex;
  double aey, bey, cey, dey;
  double aez, bez, cez, dez;
  double aexbey, bexaey, bexcey, cexbey, cexdey, dexcey, dexaey, aexdey;
  double aexcey, cexaey, bexdey, dexbey;
  double alift, blift, clift, dlift;
  double ab, bc, cd, da, ac, bd;
  double abc, bcd, cda, dab;
  double det;


  aex = pa[0] - pe[0];
  bex = pb[0] - pe[0];
  cex = pc[0] - pe[0];
  dex = pd[0] - pe[0];
  aey = pa[1] - pe[1];
  bey = pb[1] - pe[1];
  cey = pc[1] - pe[1];
  dey = pd[1] - pe[1];
  aez = pa[2] - pe[2];
  bez = pb[2] - pe[2];
  cez = pc[2] - pe[2];
  dez = pd[2] - pe[2];

  aexbey = aex * bey;
  bexaey = bex * aey;
  ab = aexbey - bexaey;
  bexcey = bex * cey;
  cexbey = cex * bey;
  bc = bexcey - cexbey;
  cexdey = cex * dey;
  dexcey = dex * cey;
  cd = cexdey - dexcey;
  dexaey = dex * aey;
  aexdey = aex * dey;
  da = dexaey - aexdey;

  aexcey = aex * cey;
  cexaey = cex * aey;
  ac = aexcey - cexaey;
  bexdey = bex * dey;
  dexbey = dex * bey;
  bd = bexdey - dexbey;

  abc = aez * bc - bez * ac + cez * ab;
  bcd = bez * cd - cez * bd + dez * bc;
  cda = cez * da + dez * ac + aez * cd;
  dab = dez * ab + aez * bd + bez * da;

  alift = aex * aex + aey * aey + aez * aez;
  blift = bex * bex + bey * bey + bez * bez;
  clift = cex * cex + cey * cey + cez * cez;
  dlift = dex * dex + dey * dey + dez * dez;

  det = (dlift * abc - clift * dab) + (blift * cda - alift * bcd);

  int ret = (det > ispstaticfilter) - (det < -ispstaticfilter);

  if(ret!=0)
    return ret;

  det = insphere(pa, pb, pc, pd, pe);

  return (det>0.0) - (det<0.0);
}


/***********************************
 * insphere predicate & perturbation
 ***********************************/
// see Perturbations and Vertex Removal in a 3D Delaunay Triangulation, O. Devillers & M. Teillaud
static int symbolicPerturbation (uint32_t indices[5] ,  const double* __restrict__ i,
                                                        const double* __restrict__ j,
                                                        const double* __restrict__ k,
                                                        const double* __restrict__ l,
                                                        const double* __restrict__ m){
  double const* pt[5] = {i,j,k,l,m};

  // Sort the five points such that their indices are in the increasing
  //   order. An optimized bubble sort algorithm is used, i.e., it has
  //   the worst case O(n^2) runtime, but it is usually much faster.
  unsigned swaps = 0; // Record the total number of swaps.
  int n = 5;
  unsigned count;
  do {
    count = 0;
    n = n - 1;
    for (int iter = 0; iter < n; iter++) {
      if (indices[iter] > indices[iter+1]) {

        const double *swappt = pt[iter];
        pt[iter] = pt[iter+1];
        pt[iter+1] = swappt;

        uint32_t sw = indices [iter];
        indices[iter] = indices[iter+1];
        indices[iter+1] = sw;
        count++;
      }
    }
    swaps += count;
  } while (count > 0); // Continue if some points are swapped.
  
  double oriA = orient3d(pt[1], pt[2], pt[3], pt[4]);
  if (oriA != 0.0) {
    // Flip the sign if there are odd number of swaps.
    if ((swaps % 2) != 0) oriA = -oriA;
    return (oriA>0.0) - (oriA<0.0);
  }
  
  double oriB = -orient3d(pt[0], pt[2], pt[3], pt[4]);
  if (oriB == 0.0) HXT_WARNING("Symbolic perturbation failed (2 superposed vertices ?)");

  // Flip the sign if there are odd number of swaps.
  if ((swaps % 2) != 0) oriB = -oriB;
  return (oriB>0.0) - (oriB<0.0);
}


/* wrapper around the insphere predicate that handles
   the ghost vertex and symbolic perturbation if needed */
static int tetInsphere(HXTMesh* mesh, const uint64_t curTet, const uint32_t vta){
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  uint32_t* Node = mesh->tetrahedra.node + curTet;

  const double* __restrict__ a = vertices[Node[0]].coord;
  const double* __restrict__ b = vertices[Node[1]].coord;
  const double* __restrict__ c = vertices[Node[2]].coord;
  const double* __restrict__ e = vertices[vta].coord;

  if(Node[3]==HXT_GHOST_VERTEX){ 
    double det = orient3d(a,b,c,e);

    if(det!=0.0){
      return (det>0.0) - (det<0.0);
    }

    // we never go here, except when point are aligned on boundary
    // HXT_INFO("insphere using opposite vertex");
    uint32_t oppositeNode = mesh->tetrahedra.node[mesh->tetrahedra.neigh[curTet+3]];
    double* const __restrict__ oppositeVertex = vertices[oppositeNode].coord;
    int sign = insphere_sign(a,b,c,oppositeVertex,e);

    if (sign == 0) {
      uint32_t nn[5] = {Node[0],Node[1],Node[2],oppositeNode,vta};
      // HXT_INFO("symbolic perturbation on boundary");
      sign = symbolicPerturbation (nn, a,b,c,oppositeVertex,e);
      
    }
    return -sign;
  }

  double* const __restrict__ d = vertices[Node[3]].coord;

  int sign = insphere_sign(a,b,c,d,e);
  if (sign == 0) {
    uint32_t nn[5] = {Node[0],Node[1],Node[2],Node[3],vta};
    // HXT_INFO("symbolic perturbation");
    sign = symbolicPerturbation (nn, a,b,c,d,e);
  }
  return sign;
}


/***********************************
 * walk to cavity
 ***********************************/
static inline HXTStatus walking2Cavity(HXTMesh* mesh, HXTPartition* partition, uint64_t* __restrict__ curTet, const uint32_t vta)
{
  uint64_t nextTet = *curTet;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  /* if nextTet is a ghost tetrahedron, go to the neighbor that is not a ghost tetrahedron */
  if (mesh->tetrahedra.node[4*nextTet+3]==HXT_GHOST_VERTEX) {
    uint64_t neighbor = mesh->tetrahedra.neigh[4*nextTet+3];
    if (vertexOutOfPartition(vertices, mesh->tetrahedra.node[neighbor], partition->lengthDist, partition->startDist))
      return HXT_STATUS_CONFLICT;
    nextTet = neighbor/4;
  }

  double* const vtaCoord = vertices[vta].coord;
  unsigned enteringFace=4;
  uint64_t rel = partition->lengthDist;

  uint32_t seed = 1;
  enteringFace = 4;

  while(1) {
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + 4*nextTet;
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + 4*nextTet;

#ifndef NDEBUG
    if(curNode[3]==HXT_GHOST_VERTEX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "walked outside of the domain");
    }
#endif

    // we should pass in orient3d mode here :p
    unsigned index = 4;
    unsigned outside = 0;
    unsigned wantToGoInOtherPartition = 0;
    unsigned randomU = hxtLCGu32(&seed);
    for (unsigned j=0; j<4; j++)
    {
      unsigned i = (j+randomU)%4;
      if (i!=enteringFace) {
        // we walk where the volume is minimum
        const double* __restrict__ a = vertices[curNode[getNode0FromFacet(i)]].coord;
        const double* __restrict__ b = vertices[curNode[getNode1FromFacet(i)]].coord;
        const double* __restrict__ c = vertices[curNode[getNode2FromFacet(i)]].coord;

        if (orient3d(vtaCoord,a,b,c) < 0){ // the point is outside the triangle
          // if(curNeigh[i]==HXT_NO_ADJACENT) {
          //   return HXT_ERROR_MSG(HXT_STATUS_ERROR,
          //                       "vertex {%f %f %f} outside the triangulation and no ghost tetrahedra",
          //                        vtaCoord[0], vtaCoord[1], vtaCoord[2]);
          // }

          outside = 1;
          uint32_t node = mesh->tetrahedra.node[curNeigh[i]];

          if(node==HXT_GHOST_VERTEX) {
            *curTet = curNeigh[i]/4;
            return HXT_STATUS_OK;
          }

          if(vertexOutOfPartition(vertices, node, rel, partition->startDist)){
            if(wantToGoInOtherPartition++ > 1000)
              return HXT_STATUS_CONFLICT;
          }
          else {
            index=i;
            break;
          }
        }
      }
    }

    if(index==4){
      const double* __restrict__ a = vertices[curNode[0]].coord;
      const double* __restrict__ b = vertices[curNode[1]].coord;
      const double* __restrict__ c = vertices[curNode[2]].coord;
      const double* __restrict__ d = vertices[curNode[3]].coord;
      if(outside) {
        return HXT_STATUS_CONFLICT;
      }
      else if( (orient3d(a,b,c,vtaCoord)>=0) +
               (orient3d(a,b,vtaCoord,d)>=0) +
               (orient3d(a,vtaCoord,c,d)>=0) +
               (orient3d(vtaCoord,b,c,d)>=0)>2 ){
        *curTet = nextTet;
        return HXT_STATUS_DOUBLE_PT;
      }
      *curTet = nextTet;
      return HXT_STATUS_OK;
    }

    enteringFace = curNeigh[index]&3;
    nextTet = curNeigh[index]/4;
  }
}


/***********************************
 * digging cavity
 ***********************************/

/* this function does a Breadth-first search of the tetrahedra in the cavity
 * it add those to local->deleted
 * it also maintain a local->ball array with all the information concerning the boundary of the cavity
 */
static inline HXTStatus diggingACavity(HXTMesh* mesh, TetLocal* local, uint64_t firstTet, const uint32_t vta, int* edgeConstraint, int perfectDelaunay){
  // add tetrahedra to cavity
  local->deleted.array[local->deleted.num++] = firstTet;
  setDeletedFlag(mesh, firstTet);
  local->ball.num = 0;

  uint64_t rel = local->partition.lengthDist;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  for(uint64_t start=local->deleted.num-1; start < local->deleted.num; start++){
    uint64_t curTet = local->deleted.array[start];
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + 4*curTet;
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + 4*curTet;

    *edgeConstraint |= !perfectDelaunay && isAnyEdgeConstrained(mesh, curTet)!=0;
    int facetConstrained = !perfectDelaunay && isAnyFacetConstrained(mesh, curTet)!=0;

    /* here we allocate enough space for the boundary (local->ball), the cavity (local->deleted) and the vertices (local->vertices) */
    HXT_CHECK( askForDeleted(&local->deleted, 4) );
    HXT_CHECK( askForBall(local, 4) );

    // we unrolled the loop for speed (also because indices are not trivial, we would need a 4X4 array)

    /* and here we push stuff to local->ball or local->deleted, always keeping ghost tet at last place */
    uint64_t neigh = curNeigh[0]/4;
    if(getDeletedFlag(mesh, neigh)==0 || (facetConstrained && getFacetConstraint(mesh, curTet, 0))){
      if((facetConstrained && getFacetConstraint(mesh, curTet, 0)) || 
         tetInsphere(mesh, neigh*4, vta)>=0) {
        bndPush(local, mesh->tetrahedra.flag[curTet] & UINT16_C(0x107),
                       /* corresponds to :
                       getFacetConstraint(mesh, curTet, 0) | 
                       getEdgeConstraint(mesh, curTet, 0) |
                       getEdgeConstraint(mesh, curTet, 1) |
                       getEdgeConstraint(mesh, curTet, 2) */
                curNode[1], curNode[2], curNode[3], curNeigh[0]);
      }
      else{
        uint32_t node = mesh->tetrahedra.node[curNeigh[0]];
        if(node!=HXT_GHOST_VERTEX && vertexOutOfPartition(vertices, node, rel, local->partition.startDist)) {
          return HXT_STATUS_CONFLICT;
        }
        local->deleted.array[local->deleted.num++] = neigh;
        setDeletedFlag(mesh, neigh);
      }
    }

    neigh = curNeigh[1]/4;
    if(getDeletedFlag(mesh, neigh)==0 || (facetConstrained && getFacetConstraint(mesh, curTet, 1))){
      if((facetConstrained && getFacetConstraint(mesh, curTet, 1)) || 
         tetInsphere(mesh, neigh*4, vta)>=0) {
        bndPush(local, (getFacetConstraint(mesh, curTet, 1)>>1) |// constraint on facet 1 goes on facet 0
                       (getEdgeConstraint(mesh, curTet, 3)>>3) | // constraint on edge 3 (facet 1 2) goes on edge 0
                       (getEdgeConstraint(mesh, curTet, 0)<<1) | // constraint on edge 0 (facet 1 0) goes on edge 1
                       (getEdgeConstraint(mesh, curTet, 4)>>2),  // constraint on edge 4 (facet 1 3) goes on edge 2
                curNode[2], curNode[0], curNode[3], curNeigh[1]);
      }
      else{
        uint32_t node = mesh->tetrahedra.node[curNeigh[1]];
        if(node!=HXT_GHOST_VERTEX && vertexOutOfPartition(vertices, node, rel, local->partition.startDist)) {
          return HXT_STATUS_CONFLICT;
        }
        local->deleted.array[local->deleted.num++] = neigh;
        setDeletedFlag(mesh, neigh);
      }
    }

    neigh = curNeigh[2]/4;
    if(getDeletedFlag(mesh, neigh)==0 || (facetConstrained && getFacetConstraint(mesh, curTet, 2))){
      if((facetConstrained && getFacetConstraint(mesh, curTet, 2))|| 
         tetInsphere(mesh, neigh*4, vta)>=0) {
        bndPush(local, (getFacetConstraint(mesh, curTet, 2)>>2) |// constraint on facet 2 goes on facet 0
                       (getEdgeConstraint(mesh, curTet, 1)>>1) | // constraint on edge 1 (facet 2 0) goes on edge 0
                       (getEdgeConstraint(mesh, curTet, 3)>>2) | // constraint on edge 3 (facet 2 1) goes on edge 1
                       (getEdgeConstraint(mesh, curTet, 5)>>3),  // constraint on edge 5 (facet 2 3) goes on edge 2
                curNode[0], curNode[1], curNode[3], curNeigh[2]);
      }
      else{
        uint32_t node = mesh->tetrahedra.node[curNeigh[2]];
        if(node!=HXT_GHOST_VERTEX && vertexOutOfPartition(vertices, node, rel, local->partition.startDist)) {
          return HXT_STATUS_CONFLICT;
        }
        local->deleted.array[local->deleted.num++] = neigh;
        setDeletedFlag(mesh, neigh);
      }
    }

    neigh = curNeigh[3]/4;
    if(getDeletedFlag(mesh, neigh)==0 || (facetConstrained && getFacetConstraint(mesh, curTet, 3))){
      if((facetConstrained && getFacetConstraint(mesh, curTet, 3)) || 
         tetInsphere(mesh, neigh*4, vta)>=0) {
        bndPush(local, (getFacetConstraint(mesh, curTet, 3)>>3) |// constraint on facet 3 goes on facet 0
                       (getEdgeConstraint(mesh, curTet, 4)>>4) | // constraint on edge 4 (facet 3 1) goes on edge 0
                       (getEdgeConstraint(mesh, curTet, 2)>>1) | // constraint on edge 2 (facet 3 0) goes on edge 1
                       (getEdgeConstraint(mesh, curTet, 5)>>3),  // constraint on edge 5 (facet 3 2) goes on edge 2
                       // there are 2 valid order for nodes: 1,0,2,3 and 0,2,1,3
                curNode[1], curNode[0], curNode[2], curNeigh[3]);
      }
      else{
        uint32_t node = mesh->tetrahedra.node[curNeigh[3]];
        if(node!=HXT_GHOST_VERTEX && vertexOutOfPartition(vertices, node, rel, local->partition.startDist)) {
          return HXT_STATUS_CONFLICT;
        }
        local->deleted.array[local->deleted.num++] = neigh;
        setDeletedFlag(mesh, neigh);
      }
    }
  }

  return HXT_STATUS_OK;
}


/**********************************************************************
 * compute adjacencies with a matrix O(1) insertion and search => O(n)
 **********************************************************************/
static inline HXTStatus computeAdjacenciesFast(HXTMesh* mesh, TetLocal* local, unsigned char* __restrict__ verticesID, const unsigned char blength){
  cavityBnd_t* __restrict__ bnd = local->ball.array;

#ifndef NDEBUG
  int ghost_is_there = 0;
#endif

HXT_ASSERT(((size_t) bnd)%SIMD_ALIGN==0);
HXT_ASSERT(((size_t) verticesID)%SIMD_ALIGN==0);

  #pragma omp simd aligned(verticesID,bnd:SIMD_ALIGN)
  for (int i=0; i<blength; i++){
    verticesID[bnd[i].node[0]] = 255;
    verticesID[bnd[i].node[1]] = 255;
    if(bnd[i].node[2]!=HXT_GHOST_VERTEX){
      verticesID[bnd[i].node[2]] = 255;
    }
  }

  unsigned char npts = 1;
  for (int i=0; i<blength; i++)
  {
    if(verticesID[bnd[i].node[0]]>npts){
      verticesID[bnd[i].node[0]] = npts++;
    }
    bnd[i].node[0] = verticesID[bnd[i].node[0]];
    if(verticesID[bnd[i].node[1]]>npts){
      verticesID[bnd[i].node[1]] = npts++;
    }
    bnd[i].node[1] = verticesID[bnd[i].node[1]];

    if(bnd[i].node[2]==HXT_GHOST_VERTEX){
      bnd[i].node[2] = 0;
#ifndef NDEBUG
      ghost_is_there = 1;
#endif
    }
    else{
      if(verticesID[bnd[i].node[2]]>npts){
        verticesID[bnd[i].node[2]] = npts++;
      }
      bnd[i].node[2] = verticesID[bnd[i].node[2]];
    }

  }

  HXT_ASSERT_MSG((npts-3+ghost_is_there)*2==blength, "Failed to compute adjacencies (f) %u (%u ghost) vertices and %u cavity boundaries", npts-1+ghost_is_there, ghost_is_there, blength); // symbol undefined

  #pragma omp simd aligned(bnd:SIMD_ALIGN)
  for (int i=0; i<blength; i++)
  {
    local->Map[bnd[i].node[0]*32 + bnd[i].node[1]] = bnd[i].neigh + 3;
    local->Map[bnd[i].node[1]*32 + bnd[i].node[2]] = bnd[i].neigh + 1;
    local->Map[bnd[i].node[2]*32 + bnd[i].node[0]] = bnd[i].neigh + 2;
  }

  #pragma omp simd aligned(bnd:SIMD_ALIGN)
  for (int i=0; i<blength; i++)
  {
    mesh->tetrahedra.neigh[bnd[i].neigh + 1] = local->Map[bnd[i].node[2]*32 + bnd[i].node[1]];
    mesh->tetrahedra.neigh[bnd[i].neigh + 2] = local->Map[bnd[i].node[0]*32 + bnd[i].node[2]];
    mesh->tetrahedra.neigh[bnd[i].neigh + 3] = local->Map[bnd[i].node[1]*32 + bnd[i].node[0]];
  }

  return HXT_STATUS_OK;
}


/**************************************************************
 * compute adjacencies with a hash table => ~O(n)
 **************************************************************/
// search neighbors in an already initialized hash table. `key` must be unique, and cannot be 0
static inline uint64_t hashTableSearch(HXTGroup2* pairs, uint64_t mask, uint64_t key, uint64_t value) {
  HXT_ASSERT(key != 0);
  
  uint64_t hash = hash64(key) & mask;
  while(pairs[hash].v[0] != key && pairs[hash].v[0] != 0) {
    hash = (hash + 1) & mask;
  }
  if(pairs[hash].v[0] == key) {
    return pairs[hash].v[1];
  }

  pairs[hash].v[0] = key;
  pairs[hash].v[1] = value;
  return HXT_NO_ADJACENT;
}

static inline HXTStatus computeAdjacenciesSlow(HXTMesh* mesh, TetLocal* local, const uint64_t start, const uint64_t blength)
{
  uint64_t size = UINT64_C(1) << u64_log2(5*blength);// 3*blength/2 entries => we want a hash table of at least 3*blength for a good load factor
  uint64_t mask = size - 1;

  // recycle memory
  if(sizeof(cavityBnd_t) * local->ball.size < sizeof(HXTGroup2) * size) {
    uint64_t capacity = (sizeof(HXTGroup2) * size + sizeof(cavityBnd_t) - 1) / sizeof(cavityBnd_t);
    capacity = MAX(2 * local->ball.size, capacity);
    HXT_CHECK( hxtAlignedFree(&local->ball.array) );
    HXT_CHECK( hxtAlignedMalloc(&local->ball.array, sizeof(cavityBnd_t) * capacity) );
    local->ball.size = capacity;
  }
  HXTGroup2* pairs = (HXTGroup2*) local->ball.array;
  memset(pairs, 0, size * sizeof(HXTGroup2));

  const uint8_t index[4] = {2,3,1,2};

#ifdef DEBUG
  int found = 0;
#endif

  for (uint64_t i=0; i<blength; i++)
  {
    uint64_t curTet = local->deleted.array[start + i];
    const uint32_t* __restrict__ Node = mesh->tetrahedra.node + 4*curTet;
    for (unsigned j=0; j<3; j++)
    {
      uint32_t n0 = Node[index[j]];
      uint32_t n1 = Node[index[j+1]];
      uint64_t key = (uint64_t) (n0 ^ n1) << 32 | MAX(n0, n1);

      uint64_t neigh = hashTableSearch(pairs, mask, key, 4 * curTet + j + 1);
      if(neigh != HXT_NO_ADJACENT) {
#ifdef DEBUG
        found++;
#endif
        mesh->tetrahedra.neigh[4 * curTet + j + 1] = neigh;
        mesh->tetrahedra.neigh[neigh] = 4 * curTet + j + 1;
      }
    }
  }

#ifdef DEBUG
  if(2 * found != 3 * blength)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Failed to compute adjacencies (b)");
#endif

  return HXT_STATUS_OK;
}


/**************************************************************
 * compute adjacencies by sorting => O(n log n)
 **************************************************************/
// static inline HXTStatus computeAdjacenciesSlow(HXTMesh* mesh, TetLocal* local, const uint64_t start, const uint64_t blength)
// {
//   HXTGroup2* edges;

//   HXT_CHECK( askForBall(local, 2 * blength) );
//   edges = (HXTGroup2*) local->ball.array; // recycle array

//   const uint8_t index[4] = {2,3,1,2};

//   const uint32_t n = mesh->vertices.num + 1;
//   uint64_t maxKey = 0;

//   for (uint64_t i=0; i<blength; i++)
//   {
//     uint64_t curTet = local->deleted.array[start+ i];
//     const uint32_t* __restrict__ Node = mesh->tetrahedra.node + 4*curTet;
//     for (unsigned j=0; j<3; j++)
//     {
//       uint32_t n0 = Node[index[j]] + 1;
//       uint32_t n1 = Node[index[j+1]] + 1;

//       if(n0 < n1)
//         edges[3*i + j].v[0] = ((uint64_t) n0 * n) + n1;
//       else
//         edges[3*i + j].v[0] = ((uint64_t) n1 * n) + n0;

//       if(edges[3*i + j].v[0] > maxKey)
//         maxKey = edges[3*i + j].v[0];

//       edges[3*i + j].v[1] = 4*curTet+j+1;
//     }
//   }

//   HXT_CHECK( group2_sort_v0(edges, 3*blength, maxKey) );

//   for(int i=0; i<3*blength; i+=2) {
// #ifndef NDEBUG
//     if(edges[i].v[0] != edges[i+1].v[0])
//       return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Failed to compute adjacencies (b)");
// #endif
//     uint64_t f0 = edges[i].v[1];
//     uint64_t f1 = edges[i+1].v[1];

//     mesh->tetrahedra.neigh[f0] = f1;
//     mesh->tetrahedra.neigh[f1] = f0;
//   }
//   return HXT_STATUS_OK;
// }


/****************************************
 * filling back the cavity (DelaunayBall)
 ****************************************/
static inline HXTStatus fillingACavity(HXTMesh* mesh, TetLocal* local, unsigned char* __restrict__ verticesID, uint64_t* __restrict__ curTet, const uint32_t vta, const uint32_t color){
  uint64_t clength = local->deleted.num;
  uint64_t blength = local->ball.num;

  uint64_t start = clength - blength;

  // #pragma vector aligned
#ifdef __GNUC__
    #pragma GCC ivdep
#else
    #pragma ivdep
#endif
  for (uint64_t i=0; i<blength; i++)
  {
    const uint64_t newTet = local->deleted.array[i + start];
    uint32_t* __restrict__ Node = mesh->tetrahedra.node + 4*newTet;

    if(mesh->tetrahedra.color != NULL) {
      mesh->tetrahedra.color[newTet] = color;
    }
    mesh->tetrahedra.flag[newTet] = 0;

    /* we need to always put the ghost vertex at the fourth slot*/
    Node[0] = vta;
    Node[1] = local->ball.array[i].node[0];
    Node[2] = local->ball.array[i].node[1];
    Node[3] = local->ball.array[i].node[2];

    const uint64_t neigh = local->ball.array[i].neigh;
    mesh->tetrahedra.neigh[4*newTet] = neigh;

    mesh->tetrahedra.flag[newTet] = local->ball.array[i].flag;

    #ifdef DEBUG
      if((getFacetConstraint(mesh, neigh / 4, neigh % 4)!=0) ^ (getFacetConstraint(mesh, newTet, 0)!=0))
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "constraints are not the same on both side of the new tet");
      if(getFacetConstraint(mesh, newTet, 1) || getFacetConstraint(mesh, newTet, 2) || getFacetConstraint(mesh, newTet, 3))
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "new tetrahedron flag are erroneous (face constraint on new face)");
      if(getEdgeConstraint(mesh, newTet, getEdgeFromNodes(0, 1)) ||
         getEdgeConstraint(mesh, newTet, getEdgeFromNodes(0, 2)) ||
         getEdgeConstraint(mesh, newTet, getEdgeFromNodes(0, 3))
         )
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "new tetrahedron flag are erroneous (edge constraint on new edge)");
    #endif

    // update neighbor's neighbor
    mesh->tetrahedra.neigh[neigh] = 4*newTet;

    // we recycle neigh to contain newTet (used in computeAdjacencies)
    local->ball.array[i].neigh = 4*newTet;
  }
  if(blength<=58){ // N+2<=31 => N<=29 => 2N<=58
  #ifndef NDEBUG
    HXT_CHECK( computeAdjacenciesFast(mesh, local, verticesID, blength) );
  #else
    computeAdjacenciesFast(mesh, local, verticesID, blength);
  #endif
  }
  else {
    HXT_CHECK(computeAdjacenciesSlow(mesh, local, start, blength) );
  }



  *curTet = local->deleted.array[start];
  local->deleted.num = start;

  return HXT_STATUS_OK;
}


/*************************************************************
 * insert a single point
 ************************************************************/
static HXTStatus insertion(HXT2Sync* shared2sync,
                           TetLocal* local,
                           int perfectDelaunay,
                           int allowOuterInsertion,
                           unsigned char* verticesID,
                           HXTNodalSizes* nodalSizes,
                           uint64_t* curTet,
                           const uint32_t vta){
  const uint64_t prevDeleted = local->deleted.num;
  HXTMesh* mesh = shared2sync->mesh;

  HXT_CHECK( walking2Cavity(mesh, &local->partition, curTet, vta) );

  uint32_t color;
  if(mesh->tetrahedra.color==NULL) {
    color = HXT_COLOR_OUT;
  }
  else {
    color = mesh->tetrahedra.color[*curTet];
    if(!allowOuterInsertion && color==HXT_COLOR_OUT) {
      return HXT_STATUS_FALSE;
    }
  }

  if(nodalSizes!=NULL && nodalSizes->enabled && filterTet(mesh, nodalSizes, *curTet, vta)){
    return HXT_STATUS_FALSE;
  }

  int edgeConstraint = 0;
  HXTStatus status = diggingACavity(mesh, local, *curTet, vta, &edgeConstraint, perfectDelaunay);

  if(status==HXT_STATUS_CONFLICT){
    restoreDeleted(mesh, local, prevDeleted);
    return HXT_STATUS_CONFLICT;
  }
  HXT_CHECK(status);

  if(!perfectDelaunay) {
    int undeleteTet = 0;
    if(edgeConstraint) {
      // printf("we have an edge constraint\n");
      HXT_CHECK( respectEdgeConstraint(local, mesh, vta, color, prevDeleted, &undeleteTet) );
    }
    // reshape the cavity if it is not star shaped
    HXT_CHECK( reshapeCavityIfNeeded(local, mesh, vta, prevDeleted, undeleteTet) );
  }


  if(nodalSizes!=NULL) {
    if(nodalSizes->array[vta] <= 0.0) {
      // we have to compute the nodalsize
      computeMeanNodalSize(local, nodalSizes, vta);
    }

    if(nodalSizes->enabled && filterCavity(local, mesh, nodalSizes, vta)) {
      restoreDeleted(mesh, local, prevDeleted);
      return HXT_STATUS_FALSE;
    }
  }


  if(local->ball.num > local->deleted.num){
    HXT_CHECK( createNewDeleted(shared2sync, &local->deleted, local->ball.num) );
    HXT_ASSERT(local->deleted.num >= local->ball.num);
  }

  HXT_CHECK( fillingACavity(mesh, local, verticesID, curTet, vta, color) );

  return HXT_STATUS_TRUE;
}

/* filter vertices that are too close from each other,
 * returns the number of filtered vertices */
// TODO: this should be done way before assigning partition
// it should be used to identify a possible imbalance ahead of time !
static inline uint32_t filterOnMooreCurve(HXTVertex* vertices,
                                          HXTNodeInfo* nodeInfo,
                                          uint32_t n,
                                          HXTNodalSizes* nodalSizes)
{
  uint32_t mooreSkipped = 0;
  #pragma omp parallel reduction(+:mooreSkipped)
  {
    double* p1 = NULL;
    double p1Size = 0;

    #pragma omp for
    for (uint32_t i=0; i<n; i++)
    {
      uint32_t lastNode = nodeInfo[i].node;
      if(nodeInfo[i].status==HXT_STATUS_TRYAGAIN){
        double* p2 = vertices[lastNode].coord;
        double p2Size = nodalSizes->array[lastNode];
        if(p1!=NULL && isTooClose(p1Size, p2Size, squareDist(p1, p2), nodalSizes)){
          mooreSkipped++;
          nodeInfo[i].status=HXT_STATUS_FALSE;
        }
        else{
          p1 = p2;
          p1Size = p2Size;
        }
      }
    }
  }

  return mooreSkipped;
}


/*************************************************************
 * Delaunay triangulation of a set of points
 ************************************************************/
static HXTStatus parallelDelaunay3D(HXTMesh* mesh,
                                    HXTDelaunayOptions* options,
                                    HXTNodeInfo* nodeInfo,
                                    const uint32_t nToInsert,
                                    int noReordering)
{
  int nonDeterministic = 0;
  uint32_t totalNumSkipped = 0;
  uint32_t totalNumInserted = 0;
  uint32_t seed = 1;

  // third, divide indices in different passes
  const int maxPartitions = options->delaunayThreads;

  uint32_t passes[12];
  unsigned npasses = computePasses(passes, options->numVerticesInMesh, nToInsert, options->partitionability, maxPartitions);

  // that ugly cast because people want an array of double into the mesh structure
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  /******************************************************
          shuffle (and optimize cache locality)
  ******************************************************/
  int firstPassEver = (options->numVerticesInMesh==0);
  HXT_INFO_COND(options->verbosity>1, "Reordering points from %u to %u", mesh->vertices.num - nToInsert, mesh->vertices.num);
  HXTVertex* verticesToInsert = vertices + mesh->vertices.num - nToInsert;

  int defaultMooreCurve = 1;

  if(options->nodalSizes==NULL && !noReordering){
    // shuffle the vertices to insert, then sort each pass except the first according to the hilbert curve...
    if(npasses>1 || firstPassEver){
      HXT_CHECK( hxtVerticesShuffle(verticesToInsert, nToInsert) );
    }

    HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num, NULL) );

    for (unsigned i=firstPassEver; i<npasses; i++) {
      HXT_CHECK( hxtVerticesSort(verticesToInsert+passes[i], passes[i+1]-passes[i]) );
    }

    #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
    for (uint32_t i=0; i<nToInsert; i++) {
      nodeInfo[i].hilbertDist = verticesToInsert[i].padding.hilbertDist;
    }
  }
  else{

    HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num, NULL) );

    if(npasses>1 || firstPassEver)
      HXT_CHECK( hxtNodeInfoShuffle(nodeInfo, nToInsert) );

    #pragma omp parallel for
    for (uint32_t i=0; i<nToInsert; i++) {
      nodeInfo[i].hilbertDist = vertices[nodeInfo[i].node].padding.hilbertDist;
    }

    for (unsigned i=firstPassEver; i<npasses; i++) {
      HXT_CHECK( hxtNodeInfoSort(nodeInfo+passes[i], passes[i+1]-passes[i]) );
    }

    if(!noReordering) {
      double* sizesToInsert = options->nodalSizes->array + options->insertionFirst;

      size_t vertSize = nToInsert*sizeof(HXTVertex);
      size_t sizeSize = nToInsert*sizeof(double);
      HXTVertex* vertCopy;
      double* sizeCopy;
      HXT_CHECK( hxtAlignedMalloc(&vertCopy, vertSize) );
      HXT_CHECK( hxtAlignedMalloc(&sizeCopy, sizeSize) );

      #pragma omp parallel for simd aligned(vertCopy,sizeCopy,nodeInfo: SIMD_ALIGN)
      for (uint32_t i=0; i<nToInsert; i++) {
        vertCopy[i] = verticesToInsert[nodeInfo[i].node-options->insertionFirst];
        sizeCopy[i] = sizesToInsert[nodeInfo[i].node-options->insertionFirst];
        nodeInfo[i].node = options->insertionFirst + i;
      }

      memcpy(verticesToInsert, vertCopy, vertSize);
      memcpy(sizesToInsert, sizeCopy, sizeSize);

      HXT_CHECK( hxtAlignedFree(&vertCopy) );
      HXT_CHECK( hxtAlignedFree(&sizeCopy) );
    }
  }


  /******************************************************
        Initializations and allocations
  ******************************************************/
  if(mesh->tetrahedra.num<5){
    HXT_ASSERT_MSG(options->numVerticesInMesh==0 && mesh->tetrahedra.num==0, "no ghosts or invalid mesh");
    HXT_INFO_COND(options->verbosity>0,
                  "Initialization of tet. mesh");
    HXT_CHECK( hxtTetrahedraInit(mesh, nodeInfo, nToInsert, options->verbosity) );
    options->numVerticesInMesh = 4; // not counting the ghost vertex
    passes[0] = 4;
  }


  unsigned char*  verticesID;
  HXT_CHECK( hxtAlignedMalloc(&verticesID, mesh->vertices.num*sizeof(unsigned char)) );

  TetLocal* Locals;
  HXT_CHECK( hxtMalloc(&Locals, maxPartitions*sizeof(TetLocal)) );

  uint64_t* startTetGlobal;
  if(options->reproducible)
    HXT_CHECK( hxtMalloc(&startTetGlobal, omp_get_max_threads()*maxPartitions*sizeof(uint64_t)) );

  for (int i=0; i<maxPartitions; i++)
    localInit(&Locals[i]);

  HXT_INFO_COND(options->verbosity>0,
                "Delaunay of %10u points on %3d threads - mesh.nvert: %-10u",
                passes[npasses] - passes[0], maxPartitions, options->numVerticesInMesh);

  for (uint32_t ipass=0; ipass<npasses; ipass++)
  {
    int nthreads = maxPartitions;
    double conflictRatio = 0.0;

    for(uint32_t iround=0; passes[ipass+1]-passes[ipass]; iround++)
    {
      const uint32_t passStart = passes[ipass];
      const uint32_t passEnd = passes[ipass+1];
      const uint32_t passLength = passEnd - passStart;
      uint32_t startShift = 0;

      nthreads = computeNumberOfThreads(conflictRatio, nthreads, passes[ipass+1]-passes[ipass], SMALLEST_PASS);

      /******************************************************
                      Sorting vertices
      ******************************************************/
      if(iround>0 && !(nthreads==1 && defaultMooreCurve)) {
        double bboxShift[3];
        if(nthreads==1) {
          startShift = 0;
          bboxShift[0] = 0.5;
          bboxShift[1] = 0.5;
          bboxShift[2] = 0.5;
          defaultMooreCurve = 1;
        }
        else {
          startShift = hxtLCGf64(&seed);
          bboxShift[0] = hxtLCGf64(&seed);
          bboxShift[1] = hxtLCGf64(&seed);
          bboxShift[2] = hxtLCGf64(&seed);
          defaultMooreCurve = 0;
        }

        if(noReordering) {
          HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num, bboxShift) );
        }
        else {
          HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num - nToInsert + passEnd, bboxShift) );
        }

        #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
        for (uint32_t i=passStart; i<passEnd; i++) {
          nodeInfo[i].hilbertDist = vertices[nodeInfo[i].node].padding.hilbertDist;
        }

        HXT_CHECK( hxtNodeInfoSort(nodeInfo + passStart, passLength) );
      }
      else if(!defaultMooreCurve) {
        if(noReordering) {
          HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num, NULL) );
        }
        else {
          HXT_CHECK( hxtMoore(options->bbox, vertices, mesh->vertices.num - nToInsert + passEnd, NULL) );
        }
        defaultMooreCurve = 1;
      }


      /******************************************************
                filtering vertices on the Moore curve
      ******************************************************/
      uint32_t mooreSkipped = 0;
      if(options->nodalSizes!=NULL && options->nodalSizes->enabled)
        mooreSkipped = filterOnMooreCurve(vertices, &nodeInfo[passStart], passLength, options->nodalSizes);


      /******************************************************
                        Making partitions
       ******************************************************/
      if(nthreads > 1) {
        uint32_t numToProcessPerThread = (passLength - mooreSkipped) / nthreads + 1;
        uint32_t counter = numToProcessPerThread;
        int threadID = 0;

        for(uint32_t i=0; i<passLength; i++) {
          uint32_t index = (startShift*passLength/nthreads + i) % passLength;
          uint64_t hilbertDist = nodeInfo[passStart + index].hilbertDist;
          if(counter>=numToProcessPerThread) {
            uint64_t prevDist = nodeInfo[passStart + (index + passLength - 1) % passLength].hilbertDist;
            // uint64_t nextDist = nodeInfo[passStart + (index + 1) % passLength].hilbertDist;
            // uint64_t prevGrad = hilbertDist - prevDist;
            // uint64_t nextGrad = nextDist - hilbertDist;

            if(/*nextGrad <= prevGrad &&*/ hilbertDist!=prevDist) {
              Locals[threadID].partition.firstElem = index;
              Locals[threadID].partition.startDist = prevDist + (hilbertDist - prevDist + 1)/2;
              counter = 0;
              threadID++;
            }
          }

          if(nodeInfo[passStart + index].status==HXT_STATUS_TRYAGAIN)
            counter++;
        }

        if(threadID <= 1) {
          nthreads = 1;
        }
        else {
          nthreads = threadID;

          // don't forget to fill all the fields of partitions
          for(threadID=0; threadID<nthreads; threadID++) {
            uint32_t localStart = Locals[threadID].partition.firstElem;
            uint32_t localEnd = Locals[(threadID+1)%nthreads].partition.firstElem;
            Locals[threadID].partition.numElem = (localEnd + passLength - localStart)%passLength;

            Locals[threadID].partition.lengthDist = Locals[(threadID+1)%nthreads].partition.startDist
                                                  - Locals[threadID].partition.startDist;
          }
        }
      }


      if(nthreads==1) {
        Locals[0].partition.startDist = 0;
        Locals[0].partition.lengthDist = UINT64_MAX;
        Locals[0].partition.firstElem = 0;
        Locals[0].partition.numElem = passLength;
      }


      HXT2Sync shared2sync = {.mesh = mesh,
                              .allocMore = 8,
                              .otherArrays = {NULL},
                              .otherArraysElementSize = {0},
                              .otherArraysSetDeleted = {NULL},
                              .threadFinished = 0};

      int reproducibleSearchThreads = 0;
      if(nthreads>1){
        if(options->reproducible){
          reproducibleSearchThreads = computeNumberOfThreads(0.0, omp_get_max_threads(), mesh->tetrahedra.num, 32768);

          #pragma omp parallel num_threads(reproducibleSearchThreads)
          {
            int threadID = omp_get_thread_num();
            /* we want to reorder tets only at the very end. Therefore, the newly created tet are in non-predictable order.
             * Because the selected tet should not depend on the ordering of tet in reproducible mode,
             * we will select the tet in the good partition that has the lowest lexicographic ordering of its nodes.
             * In this section, we run the maximum number of threads: max threads (=>not corresponding to partitions threads)
             * Each of the max thread look at a chunk of tetrahedra and updates its own array with his idea of what tet.
             * will be the first for each partition thread.
             * Next (line 1659 as I'm writing this), each partition threads will check the results obtained by each maxThreads
             * threads and take the tet which appear first lexicographically. */
            uint64_t* startTetLocal = startTetGlobal + threadID * nthreads;
            for(int i=0; i<nthreads; i++) {
              startTetLocal[i] = UINT64_MAX;
            }

            #pragma omp for
            for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
            {
              if(getDeletedFlag(mesh, i)==0)
              {
                int partitionOfTet = -1;
                for(int t=0; t<nthreads; t++) {
                  if(checkTetrahedron(vertices,
                                      &Locals[t].partition,
                                      &mesh->tetrahedra.node[i*4]
                                      )==HXT_STATUS_OK) {
                    partitionOfTet = t;
                    break;
                  }
                }

                if(partitionOfTet==-1)
                  continue;

                uint64_t oldStartTet = startTetLocal[partitionOfTet];

                if(oldStartTet==UINT64_MAX) {
                  startTetLocal[partitionOfTet] = i;
                }
                else {
                  int cmp = compareNodeLexicographically(&mesh->tetrahedra.node[4*i],
                                                         &mesh->tetrahedra.node[4*oldStartTet]);
                  HXT_ASSERT(cmp!=0);
                  if(cmp==-1){
                    startTetLocal[partitionOfTet] = i;
                  }
                }
              }
            } // implicit barrier at the end of the omp for loop :-)
          }
        }
      }

      #pragma omp parallel num_threads(nthreads)
      {
      #ifdef _MSC_VER
        #pragma omp single
        nthreads = omp_get_num_threads();
      #endif

        uint64_t curTet = HXT_NO_ADJACENT;
        const int threadID = omp_get_thread_num();

        uint32_t localStart = Locals[threadID].partition.firstElem;
        uint32_t localN = Locals[threadID].partition.numElem;

        if(nthreads>1){

          /******************************************************
                          find starting tetrahedron
          ******************************************************/
          if(options->reproducible){
            for(int t=0; t<reproducibleSearchThreads; t++) {
              uint64_t startTet = startTetGlobal[t*nthreads + threadID];
              if(startTet != UINT64_MAX) {
                if(curTet==HXT_NO_ADJACENT) {
                  curTet = startTet;
                }
                else {
                  int cmp = compareNodeLexicographically(&mesh->tetrahedra.node[4*startTet],
                                                         &mesh->tetrahedra.node[4*curTet]);
                  HXT_ASSERT(cmp!=0);
                  if(cmp==-1){
                    curTet = startTet;
                  }
                }
              }
            }
          }
          else {
            // in the standard case we can stop once we've found a correct tet.
            for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
            {
              if(getDeletedFlag(mesh, i)==0 &&
                 checkTetrahedron(vertices, &Locals[threadID].partition,
                                  mesh->tetrahedra.node + i*4 )==HXT_STATUS_OK)
              {
                curTet = i;
                break;
              }
            }
          }
        }
        else {
          /******************************************************
             single-thread starting tetrahedron
          ******************************************************/
          for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
          {
            if(getDeletedFlag(mesh, i)==0){
              curTet = i;
              break;
            }
          }
        }

        #pragma omp barrier

        if (curTet==HXT_NO_ADJACENT) {
          HXT_INFO_COND(options->verbosity>1,
                        "thread %d did not find any tetrahedron to begin with", threadID);
        }
        else{
          /******************************************************
                          vertices insertion
          ******************************************************/
          for (uint32_t i=0; i<localN; i++)
          {
            uint32_t passIndex = (localStart+i)%passLength;
            uint32_t vta = nodeInfo[passStart + passIndex].node;
            if(nodeInfo[passStart + passIndex].status==HXT_STATUS_TRYAGAIN){
              HXTStatus status = insertion(&shared2sync,
                                           &Locals[threadID],
                                           options->perfectDelaunay,
                                           options->allowOuterInsertion,
                                           verticesID,
                                           options->nodalSizes,
                                           &curTet,
                                           vta);

              switch(status){
                case HXT_STATUS_DOUBLE_PT:
                  nodeInfo[passStart + passIndex].status = HXT_STATUS_FALSE;
                  double* vtaCoord = vertices[vta].coord;
                  HXT_WARNING("skipping supposedly duplicate point (%f %f %f)", vtaCoord[0], vtaCoord[1], vtaCoord[2]);
                  break;
                case HXT_STATUS_CONFLICT:
                  status = HXT_STATUS_TRYAGAIN;
                  /* fall through */
                case HXT_STATUS_FALSE:
                case HXT_STATUS_TRUE:
                  nodeInfo[passStart + passIndex].status = status;
                  break;
                default: // other error status cause the program to return
                  nodeInfo[passStart + passIndex].status = HXT_STATUS_TRYAGAIN;
                  HXT_OMP_CHECK( status );
                  break;
              }
            }
            else{
              nodeInfo[passStart + passIndex].status = HXT_STATUS_FALSE;
            }
          }
        }

        HXT_OMP_CHECK( waitForPossibleReallocation(&shared2sync, nthreads) );
      }

      /******************************************************
      vertices that have to be tried again are put at the end
      ******************************************************/
      // everything above i+shift is HXT_STATUS_TRYAGAIN
      uint32_t shift = 0;
      uint32_t numSkipped = 0;
      for (uint32_t i=passEnd; i>passStart;)
      {
        i--;
        if(nodeInfo[i].status!=HXT_STATUS_TRYAGAIN){
          if(nodeInfo[i].status==HXT_STATUS_FALSE)
            numSkipped++;
          shift++;
        }
        else if(shift!=0) {
          HXTNodeInfo tmp = nodeInfo[i];
          nodeInfo[i] = nodeInfo[i+shift];
          nodeInfo[i+shift] = tmp;
        }
      }

      uint32_t numInserted = shift - numSkipped;
      uint32_t numConflict = passLength - shift;

      totalNumInserted += numInserted;
      totalNumSkipped += numSkipped;

      conflictRatio = (double) numConflict / (passLength - numSkipped);

      if(options->verbosity>1) {
          uint32_t numPointsMinusSkipped = passLength - numSkipped;
          uint32_t numInserted = numPointsMinusSkipped - numConflict;
          int numSpaces = MIN(8, iround/2)+5;
          HXT_INFO("%3d thrd |%10u/%-10u-> %*.1f%%",
                   nthreads, numInserted, numPointsMinusSkipped,
                   numSpaces, 100.0*MAX((double) numInserted/numPointsMinusSkipped, 0.0));
      }

      // printf("moore filtered %4.1f%%\n", mooreSkipped*100.0/passLength);
      // printf("total filtered %4.1f%%\n", numSkipped*100.0/passLength);
      // printf("      conflict %4.1f%%\n", numConflict*100.0/passLength);
      // printf("      inserted %4.1f%%\n", numInserted*100.0/passLength);
      // printf("filtered/inserted %f\n", (numSkipped - mooreSkipped)*1.0/numInserted);
      
      passes[ipass] += shift;

      // compute if there was a nonDeterministic ordering of allocation
      if(options->reproducible && nonDeterministic==0) {
        int createdNew = 0;
        for(int threadID=0; threadID<nthreads; threadID++) {
          if(Locals[threadID].deleted.createdNew)
            createdNew++;
        }

        if(createdNew>1)
          nonDeterministic = 1;
      }

      for(int threadID=0; threadID<maxPartitions; threadID++) {
        Locals[threadID].deleted.createdNew = 0;
      }
    }
  }

  options->numVerticesInMesh += totalNumInserted;

  /******************************************************
                  Cleaning
  ******************************************************/
  #pragma omp parallel num_threads(maxPartitions)
  {
    const int threadID = omp_get_thread_num();
    for (uint64_t i=0; i<Locals[threadID].deleted.num; i++) {
      for (int j=0; j<4; j++) {
        mesh->tetrahedra.neigh[4*Locals[threadID].deleted.array[i]+j] = HXT_NO_ADJACENT;
      }
    }
  }
  HXT_CHECK( hxtRemoveDeleted(mesh) );

  for (int i=0; i<maxPartitions; i++){
    HXT_CHECK( hxtAlignedFree(&Locals[i].deleted.array));
    HXT_CHECK( hxtAlignedFree(&Locals[i].ball.array));
  }

  HXT_CHECK( hxtAlignedFree(&verticesID) );
  HXT_CHECK( hxtFree(&Locals) );

  if(options->reproducible)
    HXT_CHECK( hxtFree(&startTetGlobal) );

  /***************************************************************
    if reordering allowed, remove vertices we could not insert
  ***************************************************************/
  if(!noReordering && totalNumSkipped!=0){
    /* remove deleted vertices and change tetrahedra.node accordingly */

    uint32_t* numInserted;
    HXT_CHECK( hxtAlignedMalloc(&numInserted, omp_get_max_threads()*sizeof(uint32_t)) );

    uint32_t firstShifted = mesh->vertices.num - nToInsert;
    uint32_t n = nToInsert;

    // when a vertex was skipped, nodeInfo[i].status = HXT_STATUS_FALSE
    #pragma omp parallel
    {
      // 1st: mark vertices with their corresponding status
      #pragma omp for schedule(static)
      for (uint32_t i=0; i<nToInsert; i++) {
        uint32_t index = nodeInfo[i].node;
        HXTStatus status = nodeInfo[i].status;
        vertices[index].padding.status = status;
      }// implicit barrier here

      #pragma omp single
      {
        uint32_t i = 0;
        while (vertices[firstShifted+i].padding.status==HXT_STATUS_TRUE) i++;

        firstShifted += i+1;
        n -= i+1;
      }// implicit barrier here

      uint32_t start = 0;
      int threadID = omp_get_thread_num();
      numInserted[threadID] = 0;

      #pragma omp for schedule(static)
      for (uint32_t i=0; i<n; i++) {
        if(vertices[firstShifted+i].padding.status==HXT_STATUS_TRUE)
          numInserted[threadID]++;
      }// implicit barrier here

      for (int i=0; i<threadID; i++) {
        start+=numInserted[i];
      }
      start += firstShifted-1;

      // 3rd: compute where each vertices will be
      #pragma omp for schedule(static)
      for (uint32_t i=0; i<n; i++) {
        uint32_t oldStart = start;

        if(vertices[firstShifted+i].padding.status==HXT_STATUS_TRUE)
          start++;

        // index and status are at the same location (it's a union) we cannot put this above the "if" !
        vertices[firstShifted+i].padding.index = oldStart;
      }

      // 4th: update tetrahedra.node accordingly
      #pragma omp for simd
      for (uint64_t i=0; i<4*mesh->tetrahedra.num; i++) {
        uint32_t index = mesh->tetrahedra.node[i];
        if(index>=firstShifted && index!=HXT_GHOST_VERTEX)
          mesh->tetrahedra.node[i] = vertices[index].padding.index;
      }
    }

    HXT_CHECK( hxtAlignedFree(&numInserted) );

    // 5th: put vertices at the right indices
    for (uint32_t i=firstShifted; i<mesh->vertices.num; i++) {
      if(options->nodalSizes!=NULL){
        options->nodalSizes->array[vertices[i].padding.index] = options->nodalSizes->array[i];
      }
      vertices[vertices[i].padding.index] = vertices[i];
    }

    mesh->vertices.num = mesh->vertices.num - totalNumSkipped;
  }

  if(totalNumSkipped!=0 && options->verbosity>0) {
    HXT_INFO("          - %10u points filtered", totalNumSkipped);
    HXT_INFO("          = %10u points added", totalNumInserted);
    HXT_INFO_COND(options->verbosity>1, "mem. allocated:%5.2fGB - mesh.ntet: %-9lu- mesh.nvert: %-10lu",
      ((50 + 2*(mesh->tetrahedra.flag!=NULL)) * mesh->tetrahedra.size +
       (32 + 8*(options->nodalSizes!=NULL)) * mesh->vertices.size)/(1024.*1024.*1024.),
      mesh->tetrahedra.num, mesh->vertices.num);
  }

  if(nonDeterministic){
    HXT_INFO_COND(options->verbosity>1, "Reordering tetrahedra (reproducible==true)", mesh->vertices.num - nToInsert, mesh->vertices.num);
    HXT_CHECK( hxtTetReorder(mesh) );
  }

  return HXT_STATUS_OK;
}


/*****************************************
 * complete the HXTDelaunayOptions struct
 * when there are missing fields.
 ****************************************/
static HXTStatus DelaunayOptionsInit(HXTMesh* mesh,
                                     HXTDelaunayOptions* options,
                                     HXTBbox* bbox){
HXT_ASSERT(mesh!=NULL);
HXT_ASSERT_MSG((options->numVerticesInMesh==0 && mesh->tetrahedra.num==0) ||
               (options->numVerticesInMesh>=4 && mesh->tetrahedra.num>0),
               "Number of vertices in the mesh and number of tetrahedra cannot match");
  
  const uint32_t nVert = mesh->vertices.num;

HXT_ASSERT(options->numVerticesInMesh <= nVert);
HXT_ASSERT(options->insertionFirst <= nVert);

  if(options->bbox==NULL){
    options->bbox = bbox;
    hxtBboxInit(bbox);
    hxtBboxAdd(bbox, mesh->vertices.coord, nVert);
  }

  if(options->delaunayThreads==0)
    options->delaunayThreads = omp_get_max_threads();
  else if(options->delaunayThreads<0)
    options->delaunayThreads = omp_get_num_procs();
  
  if(options->delaunayThreads>omp_get_thread_limit())
    options->delaunayThreads = omp_get_thread_limit();

  // for the predicates to work
  exactinit(options->bbox->max[0]-options->bbox->min[0],
            options->bbox->max[1]-options->bbox->min[1],
            options->bbox->max[2]-options->bbox->min[2]);

  return HXT_STATUS_OK;
}


/*****************************************
 * parallel Delaunay
 * see header for a complete description
 ****************************************/
HXTStatus hxtDelaunay(HXTMesh* mesh, HXTDelaunayOptions* options){
HXT_ASSERT(mesh!=NULL);
HXT_ASSERT(options!=NULL);
  HXTBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, options, &bbox) );

  const uint32_t nToInsert = mesh->vertices.num - options->insertionFirst;

  // don't create more threads than necessary
  options->delaunayThreads = computeNumberOfThreads(0.0, options->delaunayThreads, nToInsert, SMALLEST_PASS);

  HXTNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, nToInsert*sizeof(HXTNodeInfo)) );

  // we fill nodeInfo with the indices of each vertices to insert...
  #pragma omp parallel for simd
  for (uint32_t i=0; i<nToInsert; i++) {
    nodeInfo[i].node = options->insertionFirst + i;
    nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
  }

  HXT_CHECK( parallelDelaunay3D(mesh, options, nodeInfo, nToInsert, 0) );

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );

  return HXT_STATUS_OK;
}


/************************************************
 * parallel Delaunay without moving the vertices
 * see header for a complete description
 ***********************************************/
HXTStatus hxtDelaunaySteadyVertices(HXTMesh* mesh, HXTDelaunayOptions* options, HXTNodeInfo* nodeInfo, uint64_t nToInsert){
HXT_ASSERT(mesh!=NULL);
HXT_ASSERT(options!=NULL);
HXT_ASSERT(nodeInfo!=NULL);
  HXTBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, options, &bbox) );

  // don't create more threads than necessary
  options->delaunayThreads = computeNumberOfThreads(0.0, options->delaunayThreads, nToInsert, SMALLEST_PASS);

  HXT_ASSERT(options->insertionFirst+nToInsert <= mesh->vertices.num);

  HXT_CHECK( parallelDelaunay3D(mesh, options, nodeInfo, nToInsert, 1) );

  return HXT_STATUS_OK;
}

// typedef struct {
//   struct {
//     cavityBnd_t* array;
//     uint64_t size;
//   } ball;

//   struct {
//     unsigned char* array;
//     uint64_t size;
//   } verticesID;
// } hxtDelaunayBuffer_t;


// HXTStatus hxtDelaunayAddOne(HXTMesh* mesh, HXTDelaunayOptions* options, HXTNodeInfo* vtaNodeInfo,
//                             uint64_t** deleted, size_t* numDeleted, size_t* sizeDeleted, void** buffer)
// {
// HXT_ASSERT(buffer!=NULL);
// HXT_ASSERT(deleted!=NULL);
// HXT_ASSERT(numDeleted!=NULL);
// HXT_ASSERT(sizeDeleted!=NULL);
  
//   TetLocal local;
//   uint64_t bufSize;

//   hxtDelaunayBuffer_t* buf;

//   if(*buffer==NULL) {
//     HXT_CHECK( hxtMalloc(buffer, sizeof(hxtDelaunayBuffer_t)) );
//     buf = (hxtDelaunayBuffer_t*) *buffer;
//     buf->verticesID.array = NULL;
//     buf->verticesID.size = 0;
//     buf->ball.size = 1020;
//     HXT_CHECK( hxtAlignedMalloc(&buf->ball.array, sizeof(cavityBnd_t)*buf->ball.size) );
//   }
//   else {
//     buf = (hxtDelaunayBuffer_t*) *buffer;
//   }

//   if(buf->verticesID.size < mesh->vertices.num) {
//     size_t size = MAX(mesh->vertices.num, 2*buf->verticesID.size);
//     HXT_CHECK( hxtAlignedRealloc(&buf->verticesID.array, size*sizeof(unsigned char)) );
//     buf->verticesID.size = size;
//   }

//   local.ball.array = buf->ball.array;
//   local.ball.num = 0;
//   local.ball.size = buf->ball.size;

//   local.deleted.tetID = *deleted;
//   local.deleted.num = *numDeleted;
//   local.deleted.size = *sizeDeleted;

//   local.partition.startDist = 0;
//   local.partition.lenghtDist = UINT64_MAX;

//   uint64_t curTet = 0;

//   for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
//   { 
//     if(getDeletedFlag(mesh, i)==0){
//       curTet = i;
//       break;
//     }
//   }

//   HXTStatus status = insertion(mesh, buf->verticesID.array, &local, options->nodalSizes, &curTet, vtaNodeInfo->node, 0);

//   switch(status){
//     case HXT_STATUS_TRYAGAIN:
//       ;
//       double* vtaCoord = mesh->vertices.coord + 4*vtaNodeInfo->node;
//       HXT_WARNING("skipping supposedly duplicate vertex (%f %f %f)", vtaCoord[0], vtaCoord[1], vtaCoord[2]);
//       vtaNodeInfo->status = HXT_STATUS_FALSE;
//       break;
//       /* fall through */
//     case HXT_STATUS_FALSE:
//     case HXT_STATUS_TRUE:
//       vtaNodeInfo->status = status;
//       break;
//     default: // error other than HXT_STATUS_TRYAGAIN cause the program to return
//       vtaNodeInfo->status = HXT_STATUS_TRYAGAIN;
//       HXT_CHECK( status );
//       break;
//   }
  
//   *deleted = local.deleted.tetID;
//   *numDeleted = local.deleted.num;
//   *sizeDeleted = local.deleted.size;
//   local.ball.array[0].neigh = local.ball.size;  // we store the size in the neigh field of the first member (lazy hack)

//   return HXT_STATUS_OK;
// }


// HXTStatus hxtDelaunayFreeBuffer(void** buffer)
// {
//   if(buffer!=NULL && *buffer!=NULL) {
//     hxtDelaunayBuffer_t* buf = (hxtDelaunayBuffer_t*) *buffer;
//     HXT_CHECK(hxtAlignedFree(buf->verticesID.array));
//     HXT_CHECK(hxtAlignedFree(buf->ball.array));
//   }
//   HXT_CHECK( hxtFree(buffer) );

//   return HXT_STATUS_OK;
// }
