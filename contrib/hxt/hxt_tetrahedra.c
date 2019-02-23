#include "hxt_tetrahedra.h"
#include "predicates.h"
#include "hxt_tetRepair.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"

/**
* \file hxt_tetrahedra.c see header hxt_tetrahedra.h.
* \author Célestin Marot
*/

/* compile-time parameters */
#define SMALLEST_ROUND 2048
#define DELETED_BUFFER_SIZE 8182
// #define HXT_DELAUNAY_LOW_MEMORY /* doesn't use any buffer (a lot slower, except if you are at the limit of filling the RAM) */

/* usefull macros */
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define MAX(x,y) ((x)>(y) ? (x) : (y))
#define MIN(x,y) ((x)<(y) ? (x) : (y))

#define HXT_OMP_CHECK(status) do{ HXTStatus _tmp_ = (status); \
    if(_tmp_<0){ \
      if(_tmp_>HXT_STATUS_INTERNAL) \
        HXT_TRACE_MSG(_tmp_, "cannot break OpenMP region -> exiting"); \
      fflush(stdout); fflush(stderr); \
      exit(_tmp_); \
    } \
  }while(0)


typedef struct{
  uint32_t hxtDeclareAligned node[3];
  uint16_t flag;
  uint64_t neigh; // the tet on the other side of the boundar
} cavityBnd_t;

typedef struct {
#ifndef HXT_DELAUNAY_LOW_MEMORY
  uint64_t hxtDeclareAligned Map[1024];
#endif

  struct {
    cavityBnd_t* bnd;
    uint64_t num;
    uint64_t size;
  } ball;

  struct {
    uint64_t* tetID;
    uint64_t num;
    uint64_t size;
  } deleted;

  struct {
    uint64_t startDist;
    uint64_t endDist;
    uint32_t first;
  } partition;
} TetLocal;


/***********************************
 * create the initial tetrahedron 
 * surrounded by 4 ghost tetrahedra
 ***********************************/
static inline HXTStatus hxtTetrahedraInit(HXTMesh* mesh, hxtNodeInfo* nodeInfo, uint32_t nToInsert, int verbosity){
  if(nToInsert < 4){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "cannot mesh less than four vertices");
  }
  if(mesh->tetrahedra.size < 5){
    uint32_t maxSizeEstim = MAX(omp_get_max_threads()*DELETED_BUFFER_SIZE+8UL*nToInsert, 10UL*nToInsert);
    HXT_CHECK( hxtTetrahedraReserve(mesh, maxSizeEstim) );
    HXT_INFO_COND(verbosity>1, "Initialization reserved %lu Tet.", mesh->tetrahedra.size);
  }

  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  // find non-coplanar vertices
  double orientation = 0.0;

  uint32_t i=0, j=1, k=2, l=3;
  for (i=0; orientation==0.0 && i<nToInsert-3; i++)
  {
    for (j=i+1; orientation==0.0 && j<nToInsert-2; j++)
    {
      for (k=j+1; orientation==0.0 && k<nToInsert-1; k++)
      {
        for (l=k+1; orientation==0.0 && l<nToInsert; l++)
        {
          orientation = orient3d(vertices[nodeInfo[i].node].coord,
                                 vertices[nodeInfo[j].node].coord,
                                 vertices[nodeInfo[k].node].coord,
                                 vertices[nodeInfo[l].node].coord);
        }
      }
    }
  }
  l--; k--; j--; i--;


  if(orientation==0.0){
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "all vertices are coplanar");
  }

  // swap 0<->i  1<->j 2<->k 3<->l
  {
    hxtNodeInfo tmp = nodeInfo[i];
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


  if(orientation < 0.0){
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

  for (uint64_t i=0; i<5 ;i++){
    mesh->tetrahedra.colors[i] = UINT16_MAX;
    mesh->tetrahedra.flag[i] = 0;
  }

  return HXT_STATUS_OK;
}

/***********************************
 * fill the passes array which tells
 * the size of each BRIO round.
 * return the number of BRIO passes
 ***********************************/
static unsigned computePasses(uint32_t passes[12], uint32_t nInserted, uint32_t nToInsert)
{
  unsigned npasses=0;
  passes[0] = nToInsert;

  for (unsigned i=0; i<10; i++) {
    if(passes[i] < SMALLEST_ROUND || passes[i]/8 < nInserted){
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
 * initialisation of the TetLocal structure
 ******************************************/
static inline HXTStatus localInit(TetLocal* local){
    local->ball.size = 1020; // accounting for the offset in aligned malloc, to avoid additional memory page
    local->ball.num = 0;
    local->ball.bnd = NULL;
    local->deleted.size = DELETED_BUFFER_SIZE;
    local->deleted.num = 0;
    local->deleted.tetID = NULL;

    HXT_CHECK( hxtAlignedMalloc(&local->ball.bnd, local->ball.size*sizeof(cavityBnd_t)) );
    HXT_CHECK( hxtAlignedMalloc(&local->deleted.tetID, local->deleted.size*sizeof(uint64_t)) );

    return HXT_STATUS_OK;
}

/***********************************************
           re-allocation functions
 ***********************************************/
static HXTStatus synchronizeReallocation(HXTMesh* mesh, volatile int* toCopy, volatile int* copy){
  // threads cant be doing something while the realloc portion happen
  #pragma omp barrier
  
  // this unable us to have the same value of toCopy for everyone, as we are sure nothing happens to those variables here
  if(toCopy!=copy){
    *copy = *toCopy;
  }

  HXTStatus status = HXT_STATUS_OK;
  // make reallocations in a critical section
  #pragma omp single
  {
    if(mesh->tetrahedra.num > mesh->tetrahedra.size){
      status = hxtTetrahedraDoubleSize(mesh);
    }
  } // implicit barrier here

  if(status!=HXT_STATUS_OK)
    HXT_TRACE(status);

  return status;
}


// pragma atomic capture to get tetrahedra.num and update it at the same time before caling this function !
static inline HXTStatus reserveNewTet(HXTMesh* mesh){
  if(mesh->tetrahedra.num > mesh->tetrahedra.size){
    HXT_CHECK( synchronizeReallocation(mesh, NULL, NULL) );
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus reserveNewDeleted(TetLocal* local, uint64_t num){
  num += local->deleted.num;
  if(num > local->deleted.size){
      HXT_CHECK( hxtAlignedRealloc(&local->deleted.tetID, 2*num*sizeof(uint64_t)) );
      local->deleted.size = 2*num;
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus reserveNewBnd(TetLocal* local, uint64_t num){
  num += local->ball.num;
  if(num > local->ball.size){
      HXT_CHECK( hxtAlignedRealloc(&local->ball.bnd, 2*num*sizeof(cavityBnd_t)) );
      local->ball.size = 2*num;
  }

  return HXT_STATUS_OK;
}
/***********************************************/

/************************************
 * check if a tetrahedra is entirely
 * in the calling thread's partition
 ***********************************/
static inline HXTStatus checkTetrahedron(HXTVertex* vertices, TetLocal* local, const uint32_t* nodes){
  /* Actually, one vertex (not more) could be in another partition without creating a conflict.
   However, all threads would have to have a verticesID array => a lot of memory space wasted.
   Instead, we only allow the ghost vertex to be in another partition, it is handle differently in
   computeAdjacenciesFast function */
  uint64_t rel = local->partition.endDist - local->partition.startDist;

  if(local->partition.endDist==UINT64_MAX) // if we are working with one thread only
    return HXT_STATUS_OK;

  // unsigned wrap around is defined by the standard
  uint64_t d0 = vertices[nodes[0]].padding.hilbertDist - local->partition.startDist;
  uint64_t d1 = vertices[nodes[1]].padding.hilbertDist - local->partition.startDist;
  uint64_t d2 = vertices[nodes[2]].padding.hilbertDist - local->partition.startDist;
  uint64_t d3 = nodes[3]==HXT_GHOST_VERTEX ? d2: (vertices[nodes[3]].padding.hilbertDist - local->partition.startDist);
  
  if((d0>=rel) || (d1>=rel) || (d2>=rel) || (d3>=rel))
    return HXT_STATUS_INTERNAL;

  return HXT_STATUS_OK;

}


static inline HXTStatus pointIsTooClose(const double* __restrict__ p1, const double* __restrict__ p2, double nodalSize){
  double d2 = (p1[0]-p2[0])*(p1[0]-p2[0])
            + (p1[1]-p2[1])*(p1[1]-p2[1])
            + (p1[2]-p2[2])*(p1[2]-p2[2]); 
  if (d2 < 0.8*0.8*nodalSize*nodalSize){
    return  HXT_STATUS_INTERNAL;
  }

  return HXT_STATUS_OK;
}

/* if one edge of the cavity is shorter than the nodalSize, return HXT_STATUS_INTERNAL */
static inline HXTStatus filterCavity (TetLocal* local, HXTMesh *mesh, const double *nodalSizes, const uint32_t vta)
{
  double *vtaCoord = mesh->vertices.coord + 4*vta;
  double vtaNodalSize = nodalSizes[vta];

  for (uint64_t i = 0 ; i< local->ball.num ; i++) {
    for (unsigned j=0;j<3;j++) {
      uint32_t nodej = local->ball.bnd[i].node[j];

      if (j!=3 || nodej != HXT_GHOST_VERTEX){
        double *Xj = mesh->vertices.coord + 4*nodej;
        HXT_CHECK( pointIsTooClose(vtaCoord, Xj, 0.5*( vtaNodalSize + nodalSizes[nodej])) );
      }
    }
  }
  return  HXT_STATUS_OK;
}

static inline HXTStatus filterTet(HXTMesh* mesh, const double *nodalSizes, const uint64_t curTet, const uint32_t vta){
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  double *vtaCoord = vertices[vta].coord;
  double vtaNodalSize = nodalSizes[vta];

  for (unsigned j=0; j<4; j++) {
    uint32_t nodej = mesh->tetrahedra.node[4*curTet+j];

    if (j!=3 || nodej != HXT_GHOST_VERTEX){
      double* Xj = vertices[nodej].coord;
      double otherNodalSize = nodalSizes[nodej];
      if(otherNodalSize==DBL_MAX){
        otherNodalSize = vtaNodalSize;
      }
      HXT_CHECK( pointIsTooClose(vtaCoord, Xj, 0.5*( vtaNodalSize + otherNodalSize)) );
    }
  }
  return HXT_STATUS_OK;
}


/* restore the structure as it was before the failed insertion attempt */
static inline void restoreDeleted(HXTMesh* mesh, TetLocal* local, const uint64_t prevDeleted, const uint16_t color){
  for (uint64_t i=prevDeleted; i<local->deleted.num; i++)
    unmarkTetAsDeleted(mesh, local->deleted.tetID[i]);

  local->deleted.num = prevDeleted;
}


/***********************************
 * insphere predicate & perturbation
 ***********************************/
// see Perturbations and Vertex Removal in a 3D Delaunay Triangulation, O. Devillers & M. Teillaud
static double symbolicPerturbation (uint32_t indices[5] ,  const double* __restrict__ i,
                                                           const double* __restrict__ j,
                                                           const double* __restrict__ k,
                                                           const double* __restrict__ l,
                                                           const double* __restrict__ m){
  double const* pt[5] = {i,j,k,l,m};

  // Sort the five points such that their indices are in the increasing
  //   order. An optimized bubble sort algorithm is used, i.e., it has
  //   the worst case O(n^2) runtime, but it is usually much faster.
  int swaps = 0; // Record the total number of swaps.
  int n = 5;
  int count;
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
    return oriA;
  }
  
  double oriB = -orient3d(pt[0], pt[2], pt[3], pt[4]);
  if (oriB == 0.0) HXT_WARNING("Symbolic perturbation failed (2 superposed vertices ?)");

  // Flip the sign if there are odd number of swaps.
  if ((swaps % 2) != 0) oriB = -oriB;
  return oriB;
}


/* wrapper around the insphere predicate that handles
   the ghost vertex and symbolic perturbation if needed */
double tetInsphere(HXTMesh* mesh, const uint64_t curTet, const uint32_t vta){
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  uint32_t* Node = mesh->tetrahedra.node + curTet;

  const double* __restrict__ a = vertices[Node[0]].coord;
  const double* __restrict__ b = vertices[Node[1]].coord;
  const double* __restrict__ c = vertices[Node[2]].coord;
  const double* __restrict__ e = vertices[vta].coord;

  if(Node[3]==HXT_GHOST_VERTEX){ 
    double det = orient3d(a,b,c,e);

    if(det!=0.0){
      return det;
    }

    // we never go here, except when point are aligned on boundary
    // HXT_INFO("insphere using opposite vertex");
    uint32_t oppositeNode = mesh->tetrahedra.node[mesh->tetrahedra.neigh[curTet+3]];
    double* const __restrict__ oppositeVertex = vertices[oppositeNode].coord;
    det = insphere(a,b,c,oppositeVertex,e);

    if (det == 0.0) {
      uint32_t nn[5] = {Node[0],Node[1],Node[2],oppositeNode,vta};
      // HXT_INFO("symbolic perturbation on boundary");
      det = symbolicPerturbation (nn, a,b,c,oppositeVertex,e);
      
    }
    return -det;
  }

  double* const __restrict__ d = vertices[Node[3]].coord;

  double det = insphere(a,b,c,d,e);
  if (det == 0.0) {
    uint32_t nn[5] = {Node[0],Node[1],Node[2],Node[3],vta};
    // HXT_INFO("symbolic perturbation");
    det = symbolicPerturbation (nn, a,b,c,d,e);
  }
  return det;
}


/***********************************
 * walk to cavity
 ***********************************/
static HXTStatus walking2Cavity(HXTMesh* mesh, TetLocal* local, uint64_t* __restrict__ curTet, const uint32_t vta){
  uint64_t nextTet = *curTet;
  uint32_t seed = 1;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  /* if nextTet is a ghost triangle, go to the neighbor that is not a ghost triangle */
  if(mesh->tetrahedra.node[4*nextTet+3]==HXT_GHOST_VERTEX)
    nextTet = mesh->tetrahedra.neigh[4*nextTet+3]/4;

  double* const vtaCoord = vertices[vta].coord;
  unsigned enteringFace = 4;

#ifndef NDEBUG
  uint64_t TotalCount = 0;
#endif
  

  while(1){
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + 4*nextTet;
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + 4*nextTet;

  #ifndef NDEBUG
    if(curNode[3]==HXT_GHOST_VERTEX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "walked outside of the domain");
    }
  #endif

    unsigned neigh = 4;
    unsigned outside = 0;
    uint32_t randomU = hxtReproducibleLCG(&seed);
    for (unsigned i=0; i<4; i++)
    {
      uint32_t index = (i+randomU)%4;
      if (index!=enteringFace) {
        // we walk where the volume is minimum
        const double* __restrict__ a = vertices[curNode[(index+1)&3]].coord;
        const double* __restrict__ b = vertices[curNode[(index&2)^3]].coord;
        const double* __restrict__ c = vertices[curNode[(index+3)&2]].coord;

        if (orient3d(a,b,c, vtaCoord) < 0.0){
          if(curNeigh[index]==HXT_NO_ADJACENT) { // the point is outside the triangulation
            return HXT_ERROR_MSG(HXT_STATUS_ERROR,
                                "vertex {%f %f %f} outside the triangulation and no ghost tetrahedra",
                                 vtaCoord[0], vtaCoord[1], vtaCoord[2]);
          }

          uint64_t tet = curNeigh[index]/4;
          const uint32_t* __restrict__ neighNodes = mesh->tetrahedra.node + tet*4;
          if(checkTetrahedron(vertices, local, neighNodes)==HXT_STATUS_OK){
            if(neighNodes[3]==HXT_GHOST_VERTEX){
              *curTet = tet;
              return HXT_STATUS_OK;
            }
            neigh=index;
            break;
          }
          outside = 1;
        }
      }
    }

    if(neigh==4){
      const double* __restrict__ a = vertices[curNode[0]].coord;
      const double* __restrict__ b = vertices[curNode[1]].coord;
      const double* __restrict__ c = vertices[curNode[2]].coord;
      const double* __restrict__ d = vertices[curNode[3]].coord;
      if(outside ||
         (orient3d(a,b,c,vtaCoord)<=0.0) +
         (orient3d(a,b,vtaCoord,d)<=0.0) +
         (orient3d(a,vtaCoord,c,d)<=0.0) +
         (orient3d(vtaCoord,b,c,d)<=0.0)>2){
        return HXT_STATUS_TRYAGAIN;
      }
      *curTet = nextTet;
      return HXT_STATUS_OK;
    }

    //    printf("nextTet %u %g %u %u\n",nextTet,Min, count, neigh);
    nextTet = curNeigh[neigh]/4;
    enteringFace = curNeigh[neigh]&3;

  #ifndef NDEBUG
    if(TotalCount>mesh->tetrahedra.num){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "infinite walk to find the cavity");
    }
    // printf("%lu\n",TotalCount);
    TotalCount++;
  #endif
  }
}


/***********************************
 * digging cavity
 ***********************************/

/* pushing cavity boundary information to local->ball */
static inline void bndPush( TetLocal* local, uint16_t flag,
              const uint32_t node1, const uint32_t node2,
              const uint32_t node3, const uint64_t neigh){
  uint64_t n = local->ball.num;
  local->ball.bnd[n].node[0] = node1;
  local->ball.bnd[n].node[1] = node2;
  local->ball.bnd[n].node[2] = node3;
  local->ball.bnd[n].flag = flag;
  local->ball.bnd[n].neigh = neigh;
  local->ball.num++;
}

/* delete a tetrahedra being part of the cavity */
static inline HXTStatus deletedPush(HXTMesh* mesh, TetLocal* local, const uint64_t neigh){
  // check if 3 points of the new tetrahedra are owned by this thread
  HXT_CHECK( checkTetrahedron((HXTVertex*) mesh->vertices.coord, local, mesh->tetrahedra.node + neigh*4) );
  local->deleted.tetID[local->deleted.num++] = neigh;
  markTetAsDeleted(mesh, neigh);

  return HXT_STATUS_OK;
}

/* check if the cavity is star shaped
   This isn't usefull for pure Delaunay but when we constrain cavity with colors,
   it is usefull */
static HXTStatus isStarShaped(TetLocal* local, HXTMesh* mesh, const uint32_t vta, uint64_t* blindFaceIndex)
{
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  double *vtaCoord = vertices[vta].coord;

  for (uint64_t i=0; i<local->ball.num; i++) {
    if(local->ball.bnd[i].node[2]==HXT_GHOST_VERTEX){

    }
    else{
      double* b = vertices[local->ball.bnd[i].node[0]].coord;
      double* c = vertices[local->ball.bnd[i].node[1]].coord;
      double* d = vertices[local->ball.bnd[i].node[2]].coord;
      if(orient3d(vtaCoord, b, c, d)<=0.0){
        *blindFaceIndex = i;
        return HXT_STATUS_INTERNAL;
      }
    }
  }
  return HXT_STATUS_OK;
}


static HXTStatus undeleteTetrahedron(TetLocal* local, HXTMesh* mesh, const uint32_t vta, uint64_t tetToUndelete) {
  // the tetrahedra should not be deleted anymore
  for (uint64_t i=local->deleted.num; ; i--) {
    if(local->deleted.tetID[i-1]==tetToUndelete) {
      local->deleted.num--;
      local->deleted.tetID[i-1] = local->deleted.tetID[local->deleted.num];
      break;
    }
#ifdef DEBUG
    if(i==1)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "could not find the tetrahedra in the deleted array");
#endif
  }
  unmarkTetAsDeleted(mesh, tetToUndelete);

  uint64_t bndFaces[4] = {HXT_NO_ADJACENT, HXT_NO_ADJACENT, HXT_NO_ADJACENT, HXT_NO_ADJACENT};
  int nbndFace = 0;

  // we should update the boundary (that's the difficult part...)
  // first remove all the boundary faces that come from the tetrahedron we just remove from the cavity
  for (uint64_t i=local->ball.num; nbndFace<4 && i>0; i--) {
    if(mesh->tetrahedra.neigh[local->ball.bnd[i-1].neigh]/4==tetToUndelete) {
      bndFaces[nbndFace++] = local->ball.bnd[i-1].neigh;
      local->ball.num--;
      local->ball.bnd[i-1] = local->ball.bnd[local->ball.num];
    }
  }

  // we must replace them by all the other faces of the tetrahedron we just removed
  const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + tetToUndelete*4;
  const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + tetToUndelete*4;

#ifdef DEBUG
  int nbndFace2 = (isTetDeleted(mesh, curNeigh[0]/4)==0) + (isTetDeleted(mesh, curNeigh[1]/4)==0) + (isTetDeleted(mesh, curNeigh[2]/4)==0) + (isTetDeleted(mesh, curNeigh[3]/4)==0);
  if(nbndFace!=nbndFace2)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "found %d non-deleted tet adjacent to the tet we unremove but there should be %d %lu %lu %lu %lu", nbndFace, nbndFace2, bndFaces[0], bndFaces[1], bndFaces[2], bndFaces[3]);
#endif

  HXT_CHECK( reserveNewBnd(local, 3) );

  if(curNeigh[0]!=bndFaces[0] && curNeigh[0]!=bndFaces[1] && curNeigh[0]!=bndFaces[2] && curNeigh[0]!=bndFaces[3])
    bndPush(local,  (mesh->tetrahedra.flag[tetToUndelete] & 0x9) | 
                    (isEdgeConstrained(mesh, tetToUndelete, 0 , 2)>>1) |
                    (isEdgeConstrained(mesh, tetToUndelete, 0 , 1)<<1), curNode[2], curNode[1], curNode[3], 4*tetToUndelete+0);

  if(curNeigh[1]!=bndFaces[0] && curNeigh[1]!=bndFaces[1] && curNeigh[1]!=bndFaces[2] && curNeigh[1]!=bndFaces[3])
    bndPush(local,  ((mesh->tetrahedra.flag[tetToUndelete] & 0xD0)>>4) | 
                    isEdgeConstrained(mesh, tetToUndelete, 0 , 1), curNode[0], curNode[2], curNode[3], 4*tetToUndelete+1);

  if(curNeigh[2]!=bndFaces[0] && curNeigh[2]!=bndFaces[1] && curNeigh[2]!=bndFaces[2] && curNeigh[2]!=bndFaces[3])
    bndPush(local,  ((mesh->tetrahedra.flag[tetToUndelete] & 0x900)>>8) | 
                    (isEdgeConstrained(mesh, tetToUndelete, 1 , 2)>>5) |
                     isEdgeConstrained(mesh, tetToUndelete, 0 , 2), curNode[1], curNode[0], curNode[3], 4*tetToUndelete+2);

  if(curNeigh[3]!=bndFaces[0] && curNeigh[3]!=bndFaces[1] && curNeigh[3]!=bndFaces[2] && curNeigh[3]!=bndFaces[3])
    bndPush(local, (isFacetConstrained(mesh, 4*tetToUndelete+3)>>12) | 
                   (isEdgeConstrained(mesh, tetToUndelete, 0 , 3)>>2) |
                   (isEdgeConstrained(mesh, tetToUndelete, 1 , 3)>>5) |
                   (isEdgeConstrained(mesh, tetToUndelete, 2 , 3)>>8), curNode[0], curNode[1], curNode[2], 4*tetToUndelete+3);

  return HXT_STATUS_OK;
}


static HXTStatus reshapeCavityIfNeeded(TetLocal* local, HXTMesh* mesh, const uint32_t vta, uint64_t prevDeleted) {
  // we will remove the tetrahedra adjacent to the face that does not see the point, progressively, until the cavity is star shaped...
  uint64_t blindFace = 0;
  while(isStarShaped(local, mesh, vta, &blindFace)==HXT_STATUS_INTERNAL)
  {
    // printf("deleting %lu  cavity:%lu  ball:%lu\n",mesh->tetrahedra.neigh[local->ball.bnd[blindFace].neigh]/4, local->deleted.num-prevDeleted, local->ball.num );
    HXT_CHECK( undeleteTetrahedron(local, mesh, vta, mesh->tetrahedra.neigh[local->ball.bnd[blindFace].neigh]/4) );
  }
  return HXT_STATUS_OK;
}


static HXTStatus respectEdgeConstraint(TetLocal* local, HXTMesh* mesh, const uint32_t vta, const uint16_t color, const uint64_t prevDeleted) {
  // HXT_WARNING("a constrained edge was inside the cavity, recovering it");

  // all the tetrahedron have the same color 'color', we will use that color to flag them
  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.tetID[i];
    mesh->tetrahedra.colors[delTet] = 0;
  }

  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.tetID[i];
    int exist = 1;
    for (int j=0; exist && j<4; j++) {
      for (int k=j+1; exist && k<4; k++) {
        if(isEdgeConstrained(mesh, delTet, j, k) && (mesh->tetrahedra.colors[delTet] & (1U<<(j*4+k)))==0) {
          // const int _UP_FACET[4][4] = {{-1, 2, 3, 1},
          //                              { 3,-1, 0, 2},
          //                              { 1, 3,-1, 0},
          //                              { 2, 0, 1,-1}};

          // HXT_WARNING("found constrained edge %u-%u in tetrahedron %lu (%d %d) inside the cavity\n",mesh->tetrahedra.node[4*delTet+ _UP_FACET[j][k]], mesh->tetrahedra.node[4*delTet+ _UP_FACET[k][j]], delTet, j, k);
          // turn around the edge to check if a facet is on the boundary of the cavity. If yes, the edge is processed... if not, we delete one tet.
          int in_facet = j;
          int out_facet = k;

          int edgeIsSafe = 0;
          uint64_t curTet = delTet;
          // first turn
          do
          {
            uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

            // go into the neighbor through out_facet
            uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
            curTet = neigh/4;
            in_facet = neigh%4;

            uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
            for (out_facet=0; out_facet<3; out_facet++)
              if(nodes[out_facet]==newV)
                break;

            if(isTetDeleted(mesh, curTet)!=0) {
              // mark that the edge as been treate
              #ifdef DEBUG
                if((mesh->tetrahedra.colors[curTet] & (1U<<(in_facet<out_facet?in_facet*4+out_facet:out_facet*4+in_facet)))!=0)
                  return HXT_ERROR_MSG(HXT_STATUS_ERROR, "the flag says that the tet has already been processed for this edge...");
              #endif
              mesh->tetrahedra.colors[curTet] |= (1U<<(in_facet*4+out_facet)) | (1U<<(out_facet*4+in_facet));
            }
            else {
              edgeIsSafe=1;
            }

            // printf("edge %u-%u, tet %lu (%d %d)  deleted:%u\n", mesh->tetrahedra.node[4*curTet+ _UP_FACET[in_facet][out_facet]], mesh->tetrahedra.node[4*curTet+ _UP_FACET[out_facet][in_facet]], curTet, in_facet, out_facet, isTetDeleted(mesh, curTet)!=0);

          } while (curTet!=delTet);

          if(!edgeIsSafe) { // we must find a tetrahedron on the opposite side of vta and delete it.
            in_facet = j;
            out_facet = k;
            curTet = delTet;

            uint64_t tetContainingVta = local->deleted.tetID[prevDeleted];
            uint64_t tetToUndelete = HXT_NO_ADJACENT;
            double distMax = 0.0;
            double* vtaCoord = mesh->vertices.coord + 4*vta;

          #ifdef DEBUG
            double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta];
            double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+1];
            double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+2];
            double* d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+3];

            if(orient3d(vtaCoord,b,c,d)<0.0 || orient3d(a,vtaCoord,c,d)<0.0 || orient3d(a,b,vtaCoord,d)<0.0 || orient3d(a,b,c,vtaCoord)<0.0) {
              return HXT_ERROR_MSG(HXT_STATUS_ERROR, "an edge part of a ghost tetrahedron is constrained");
            }
          #endif

            do
            {
              uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

              // go into the neighbor through out_facet
              uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
              curTet = neigh/4;
              in_facet = neigh%4;

              uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
              for (out_facet=0; out_facet<3; out_facet++)
                if(nodes[out_facet]==newV)
                  break;

              double* coord1 = mesh->vertices.coord + newV;
              double* coord2 = mesh->vertices.coord + nodes[in_facet];

              if(curTet!=tetContainingVta) {
                double dist = 0.0;
                for (int l=0; l<3; l++) {
                  double meanCoord = (coord1[l]+coord2[l])*0.5;
                  double diff = meanCoord-vtaCoord[l];
                  dist += diff*diff;
                }

                if(dist>distMax) {
                  dist = distMax;
                  tetToUndelete = curTet;
                }
              }
            } while (curTet!=delTet);

            if(tetToUndelete==delTet)
              exist = 0;

            // printf("undeleting tetrahedron %lu\n", tetToUndelete);
            mesh->tetrahedra.colors[tetToUndelete] = color;
            HXT_CHECK( undeleteTetrahedron(local, mesh, vta, tetToUndelete) );
          }
        }
      }
    }
  }

  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.tetID[i];
    mesh->tetrahedra.colors[delTet] = color;
  }

  return HXT_STATUS_OK;
}


/* this function does a Breadth-first search of the tetrahedra in the cavity
 * it add those to local->deleted
 * it also maintain a local->bnd array with all the information concerning the boundary of the cavity
 */
static inline HXTStatus diggingACavity(HXTMesh* mesh, TetLocal* local, uint64_t curTet, const uint32_t vta, int* edgeConstraint){
  // add tetrahedra to cavity
  local->deleted.tetID[local->deleted.num++] = curTet;
  markTetAsDeleted(mesh, curTet);
  local->ball.num = 0;

  

  for(uint64_t start=local->deleted.num-1; start < local->deleted.num; start++){
    uint64_t curTet = local->deleted.tetID[start];
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + 4*curTet;
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + 4*curTet;

    *edgeConstraint += isAnyEdgeConstrained(mesh, curTet)!=0;

    /* here we allocate enough space for the boundary (local->bnd), the cavity (local->deleted) and the vertices (local->vertices) */
    HXT_CHECK( reserveNewDeleted(local, 4) );
    HXT_CHECK( reserveNewBnd(local, 4) );

    // we unrolled the loop for speed (also because indices are not trivial, we would need a 4X4 array)

    /* and here we push stuff to local->bnd or local->deleted, always keeping ghost tet at last place */
    uint64_t neigh = curNeigh[0]/4;
    if(curNeigh[0]!=HXT_NO_ADJACENT && isTetDeleted(mesh, neigh)==0){
      if(isFacetConstrained(mesh, 4*curTet+0) || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, mesh->tetrahedra.flag[curTet] & 0xF,
                       curNode[1], curNode[2], curNode[3], curNeigh[0]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, neigh) );
      }
    }

    neigh = curNeigh[1]/4;
    if(curNeigh[1]!=HXT_NO_ADJACENT && isTetDeleted(mesh, neigh)==0){
      if(isFacetConstrained(mesh, 4*curTet+1) || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, (isFacetConstrained(mesh, 4*curTet+1)>>4) | 
                       (isEdgeConstrained(mesh, curTet, 1 , 2)>>5) |
                       (isEdgeConstrained(mesh, curTet, 0 , 1)<<1) |
                       (isEdgeConstrained(mesh, curTet, 1 , 3)>>4),
                       curNode[2], curNode[0], curNode[3], curNeigh[1]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, neigh) );
      }
    }

    neigh = curNeigh[2]/4;
    if(curNeigh[2]!=HXT_NO_ADJACENT && isTetDeleted(mesh, neigh)==0){
      if(isFacetConstrained(mesh, 4*curTet+2)|| 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, (isFacetConstrained(mesh, 4*curTet+2)>>8) | 
                       (isEdgeConstrained(mesh, curTet, 0 , 2)>>1) |
                       (isEdgeConstrained(mesh, curTet, 1 , 2)>>4) |
                       (isEdgeConstrained(mesh, curTet, 2 , 3)>>8),
                       curNode[0], curNode[1], curNode[3], curNeigh[2]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, neigh) );
      }
    }

    neigh = curNeigh[3]/4;
    if(curNeigh[3]!=HXT_NO_ADJACENT && isTetDeleted(mesh, neigh)==0){
      if(isFacetConstrained(mesh, 4*curTet+3) || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        
        bndPush(local, (isFacetConstrained(mesh, 4*curTet+3)>>12) | 
                       (isEdgeConstrained(mesh, curTet, 1 , 3)>>6) |
                       (isEdgeConstrained(mesh, curTet, 0 , 3)>>1) |
                       (isEdgeConstrained(mesh, curTet, 2 , 3)>>8),
                       // there are 2 valid order for nodes: 1,0,2,3 and 0,2,1,3
                       curNode[1], curNode[0], curNode[2], curNeigh[3]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, neigh) );
      }
    }
  }

  return HXT_STATUS_OK;
}


/**************************************************************
 * compute adjacencies with a matrix O(1) insertion and search
 **************************************************************/
#ifndef HXT_DELAUNAY_LOW_MEMORY
static inline HXTStatus computeAdjacenciesFast(HXTMesh* mesh, TetLocal* local, uint32_t* __restrict__ verticesID, const uint64_t blength){
  cavityBnd_t* __restrict__ bnd = local->ball.bnd;

#ifndef NDEBUG
  int ghost_is_there = 0;
#endif

HXT_ASSERT(((size_t) bnd)%SIMD_ALIGN==0);
HXT_ASSERT(((size_t) verticesID)%SIMD_ALIGN==0);

  #pragma omp simd aligned(verticesID,bnd:SIMD_ALIGN)
  for (uint32_t i=0; i<blength; i++){
    verticesID[bnd[i].node[0]] = UINT32_MAX;
    verticesID[bnd[i].node[1]] = UINT32_MAX;
    if(bnd[i].node[2]!=HXT_GHOST_VERTEX){
      verticesID[bnd[i].node[2]] = UINT32_MAX;
    }
  }

  uint32_t npts = 1;
  for (uint32_t i=0; i<blength; i++)
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

  #pragma omp simd aligned(verticesID:SIMD_ALIGN)
  for (uint32_t i=0; i<blength; i++)
  {
    local->Map[bnd[i].node[0]*32 + bnd[i].node[1]] = bnd[i].neigh + 3;
    local->Map[bnd[i].node[1]*32 + bnd[i].node[2]] = bnd[i].neigh + 1;
    local->Map[bnd[i].node[2]*32 + bnd[i].node[0]] = bnd[i].neigh + 2;
  }

  #pragma omp simd aligned(verticesID:SIMD_ALIGN)
  for (uint32_t i=0; i<blength; i++)
  {
    mesh->tetrahedra.neigh[bnd[i].neigh + 1] = local->Map[bnd[i].node[2]*32 + bnd[i].node[1]];
    mesh->tetrahedra.neigh[bnd[i].neigh + 2] = local->Map[bnd[i].node[0]*32 + bnd[i].node[2]];
    mesh->tetrahedra.neigh[bnd[i].neigh + 3] = local->Map[bnd[i].node[1]*32 + bnd[i].node[0]];
  }

  return HXT_STATUS_OK;
}
#endif


/**************************************************************
 * compute adjacencies with a matrix O(n) insertion and search
 **************************************************************/
static inline HXTStatus computeAdjacenciesSlow(HXTMesh* mesh, TetLocal* local, const uint64_t start, const uint64_t blength){

  uint64_t tlength = 0;
  const uint64_t middle = blength*3/2; // 3N

  // N+2 point on the surface of the cavity
  // 2N triangle on the surface of the cavity, x3 (4*0.5+1) data = 6N+9 uint64_t
  // => enough place for the 3N edge x2 data = 6N uint64_t
  uint64_t* Tmp = (uint64_t*) local->ball.bnd;
  const unsigned index[4] = {2,3,1,2};

  for (uint64_t i=0; i<blength; i++)
  {
    uint64_t curTet = local->deleted.tetID[start+ i];
    const uint32_t* __restrict__ Node = mesh->tetrahedra.node + 4*curTet;

    // pointer to the position of Node[0] in the Tmp array
    for (unsigned j=0; j<3; j++)
    {
      // define the edge by the minimum vertex and the other
      uint64_t key = ((uint64_t) Node[index[j]]<<32) + Node[index[j+1]];

      // linear searching/pushing into Tmp
      uint64_t k;
      for (k=0; k<tlength; k++) // this is the only nested loop... the one that cost it all
      {
        __assume_aligned(Tmp, SIMD_ALIGN);
        if(Tmp[k]==key)
          break;
      }

      uint64_t curFace = 4*curTet+j+1;

      // we did not found it
      if(k==tlength){
        Tmp[tlength] = (key>>32) + (key<<32);
        Tmp[middle + tlength] = curFace;
        tlength++;
      }
      else{// we found the neighbour !
        uint64_t pairValue = Tmp[middle+k];
        mesh->tetrahedra.neigh[curFace] = pairValue;
        mesh->tetrahedra.neigh[pairValue] = curFace;
        tlength--;
        if(k<tlength){// put the last entry in the one we just discovered
          Tmp[k] = Tmp[tlength];
          Tmp[middle+k] = Tmp[middle + tlength];
        }
      }
    }
  }
  HXT_ASSERT_MSG(tlength==0, "Failed to compute adjacencies (s)"); // verify that all neighbor were found
  return HXT_STATUS_OK;
}


/****************************************
 * filling back the cavity (DelaunayBall)
 ****************************************/
static inline HXTStatus fillingACavity(HXTMesh* mesh, TetLocal* local, uint32_t* __restrict__ verticesID, uint64_t* __restrict__ curTet, const uint32_t vta, const uint16_t color){
  uint64_t clength = local->deleted.num;
  uint64_t blength = local->ball.num;

  uint64_t start = clength - blength;

  // #pragma vector aligned
  #pragma omp simd
  for (uint64_t i=0; i<blength; i++)
  {

    __assume_aligned(local->deleted.tetID, SIMD_ALIGN);
    __assume_aligned(local->ball.bnd, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.colors, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.flag, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.node, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.neigh, SIMD_ALIGN);

    const uint64_t newTet = local->deleted.tetID[i + start];
    uint32_t* __restrict__ Node = mesh->tetrahedra.node + 4*newTet;
    mesh->tetrahedra.colors[newTet] = color;
    mesh->tetrahedra.flag[newTet] = 0;

    /* we need to always put the ghost vertex at the fourth slot*/
    Node[0] = vta;
    Node[1] = local->ball.bnd[i].node[0];
    Node[2] = local->ball.bnd[i].node[1];
    Node[3] = local->ball.bnd[i].node[2];

    const uint64_t neigh = local->ball.bnd[i].neigh;
    mesh->tetrahedra.neigh[4*newTet] = neigh;

    mesh->tetrahedra.flag[newTet] = local->ball.bnd[i].flag;

    // update neighbor's neighbor
    mesh->tetrahedra.neigh[neigh] = 4*newTet;

    // we recycle neigh to contain newTet (used in computeAdjacencies)
    local->ball.bnd[i].neigh = 4*newTet;
  }
#ifndef HXT_DELAUNAY_LOW_MEMORY
  if(blength<=58){ // N+2<=31 => N<=29 => 2N<=58
  #ifndef NDEBUG
    HXT_CHECK( computeAdjacenciesFast(mesh, local, verticesID, blength) );
  #else
    computeAdjacenciesFast(mesh, local, verticesID, blength);
  #endif
  }
  else
#endif
  {
  #ifndef NDEBUG
    HXT_CHECK(computeAdjacenciesSlow(mesh, local, start, blength) );
  #else
    computeAdjacenciesSlow(mesh, local, start, blength);
  #endif
  }



  *curTet = local->deleted.tetID[start];
  local->deleted.num = start;

  return HXT_STATUS_OK;
}


/*************************************************************
 * insert a single point
 ************************************************************/
static inline HXTStatus insertion(HXTMesh* mesh,
                                  uint32_t* verticesID,
                                  TetLocal* local,
                                  const double* nodalSizes,
                                  uint64_t* curTet,
                                  const uint32_t vta,
                                  int perfectlyDelaunay){
  const uint64_t prevDeleted = local->deleted.num;

  HXT_CHECK( walking2Cavity(mesh, local, curTet, vta) );

  if(nodalSizes!=NULL && filterTet(mesh, nodalSizes, *curTet, vta)){
    return HXT_STATUS_FALSE;
  }

  const uint16_t color = mesh->tetrahedra.colors[*curTet];
  int edgeConstraint = 0;
  HXTStatus status = diggingACavity(mesh, local, *curTet, vta, &edgeConstraint);

  if(status==HXT_STATUS_INTERNAL){
    restoreDeleted(mesh, local, prevDeleted, color);
    return HXT_STATUS_TRYAGAIN;
  }
  else{
    HXT_CHECK(status);
  }

  if(edgeConstraint) {
    HXT_CHECK( respectEdgeConstraint(local, mesh, vta, color, prevDeleted) );
  }

  // uint64_t face = 0;
  // if(!perfectlyDelaunay && isStarShaped(local, mesh, vta, &face)==HXT_STATUS_INTERNAL) {
  //   restoreDeleted(mesh, local, prevDeleted, color);
  //   return HXT_STATUS_FALSE;
  // }

  // reshape the cavity if it is not star shaped
  if(!perfectlyDelaunay)
    HXT_CHECK( reshapeCavityIfNeeded(local, mesh, vta, prevDeleted) );

  if(nodalSizes!=NULL && filterCavity(local, mesh, nodalSizes, vta)) {
    restoreDeleted(mesh, local, prevDeleted, color);
    return HXT_STATUS_FALSE;
  }


  if(local->ball.num > local->deleted.num){
    uint64_t needed = MAX(DELETED_BUFFER_SIZE,local->ball.num)-local->deleted.num;

    uint64_t ntet;

    #pragma omp atomic capture
    { ntet = mesh->tetrahedra.num; mesh->tetrahedra.num+=needed;}

    reserveNewTet(mesh);
    reserveNewDeleted(local, needed);

    #pragma omp simd
    for (uint64_t i=0; i<needed; i++){
      local->deleted.tetID[local->deleted.num+i] = ntet+i;
      mesh->tetrahedra.flag[ntet+i] = 0;
      markTetAsDeleted(mesh, ntet+i);
    }

    local->deleted.num+=needed;
  }

  HXT_CHECK( fillingACavity(mesh, local, verticesID, curTet, vta, color) );

  return HXT_STATUS_TRUE;
}


/*************************************************************
 * Delaunay triangulation of a set of points
 ************************************************************/
static HXTStatus parallelDelaunay3D(HXTMesh* mesh,
                                    HXTDelaunayOptions* options,
                                    hxtNodeInfo* nodeInfo,
                                    const uint32_t nToInsert,
                                    int noReordering)
{
  uint32_t totalNumSkipped = 0;
  uint32_t seed = 1;

  // third, divide indices in different passes
  const int maxThreads = options->delaunayThreads;
  const int perfectlyDelaunay = mesh->tetrahedra.num<=5;

  uint32_t passes[12];
  unsigned npasses = computePasses(passes, options->numVerticesInMesh, nToInsert);

  // that ugly cast because people want an array of double into the mesh structure
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  

  /******************************************************
          shuffle (and optimize cache locality)
  ******************************************************/
  if(noReordering){
    // shuffle nodeInfo
    HXT_CHECK( hxtNodeInfoShuffle(nodeInfo, nToInsert) );
  }
  else {
    HXT_INFO_COND(options->verbosity>1, "Reordering vertices from %u to %u", mesh->vertices.num - nToInsert, mesh->vertices.num);
    HXTVertex* verticesToInsert = vertices + mesh->vertices.num - nToInsert;

    if(options->nodalSizes==NULL){
      // shuffle the vertices to insert, then sort each pass except the first according to the hilbert curve...
      HXT_CHECK( hxtVerticesShuffle(verticesToInsert, nToInsert) );
    }
    else{
      HXT_CHECK( hxtNodeInfoShuffle(nodeInfo, nToInsert) );
    }

    uint32_t nbits = hxtAdvancedHilbertBits(options->bbox, options->minSizeStart, options->minSizeEnd,
                                            options->numVerticesInMesh,
                                            options->numVerticesInMesh + nToInsert,
                                            options->numVerticesInMesh + nToInsert/4,
                                            nToInsert/2,
                                            maxThreads);
    
    HXT_CHECK( hxtVerticesHilbertDist(options->bbox, verticesToInsert, nToInsert, &nbits, NULL) );

    if(options->nodalSizes==NULL){
      for (unsigned i=options->numVerticesInMesh < SMALLEST_ROUND; i<npasses; i++) {
        HXT_CHECK( hxtVerticesSort(verticesToInsert+passes[i], passes[i+1]-passes[i], nbits) );
      }
    }
    else{
      #pragma omp parallel for
      for (int i=0; i<nToInsert; i++) {
        nodeInfo[i].hilbertDist = verticesToInsert[i].padding.hilbertDist;
      }

      for (unsigned i=options->numVerticesInMesh < SMALLEST_ROUND; i<npasses; i++) {
        HXT_CHECK( hxtNodeInfoSort(nodeInfo+passes[i], passes[i+1]-passes[i], nbits) );
      }

      const uint32_t nodalMin = mesh->vertices.num - nToInsert;
      double* sizesToInsert = options->nodalSizes + nodalMin;

      size_t vertSize = nToInsert*sizeof(HXTVertex);
      size_t sizeSize = nToInsert*sizeof(double);
      HXTVertex* vertCopy;
      double* sizeCopy;
      HXT_CHECK( hxtAlignedMalloc(&vertCopy, vertSize) );
      HXT_CHECK( hxtAlignedMalloc(&sizeCopy, sizeSize) );
      
      #pragma omp parallel for
      for (uint32_t i=0; i<nToInsert; i++) {
        vertCopy[i] = verticesToInsert[nodeInfo[i].node-nodalMin];
        sizeCopy[i] = sizesToInsert[nodeInfo[i].node-nodalMin];
        nodeInfo[i].node = nodalMin + i;
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
    HXT_INFO_COND(options->verbosity>0,
                  "Initialization of tet. mesh");
    HXT_CHECK( hxtTetrahedraInit(mesh, nodeInfo, nToInsert, options->verbosity) );
    options->numVerticesInMesh = 4; // not counting the ghost vertex
    passes[0] = 4;
  }


  uint32_t*  verticesID;
#ifdef HXT_DELAUNAY_LOW_MEMORY
  verticesID = NULL; // we do not need it
#else
  HXT_CHECK( hxtAlignedMalloc(&verticesID, mesh->vertices.num*sizeof(uint32_t)) );
#endif

  TetLocal* Locals;
  HXT_CHECK( hxtMalloc(&Locals, maxThreads*sizeof(TetLocal)) );
  // HXT_CHECK( hxtMalloc())

  for (int i=0; i<maxThreads; i++)
    localInit(&Locals[i]);


  HXT_INFO_COND(options->verbosity>0,
                "Delaunay of %10u vertices on %3d threads\t- mesh.nvert: %-10u",
                passes[npasses] - passes[0], maxThreads, options->numVerticesInMesh);

  for (uint32_t p=0; p<npasses; p++)
  {

    double percent = 200;
    int nthreads = 1;
    uint32_t tmp = (passes[p+1]-passes[p])/SMALLEST_ROUND;
    while(tmp>0 && nthreads<maxThreads){
      tmp = tmp/2;
      nthreads*=2;
    }
    nthreads = MIN(nthreads, maxThreads);

    // const uint32_t initialPassLength = passes[p+1] - passes[p];

    for(uint32_t n=0; passes[p+1]-passes[p]; n++)
    {
      const uint32_t passStart = passes[p];
      const uint32_t passEnd = passes[p+1];
      const uint32_t passLength = passEnd - passStart;

      /******************************************************
                      choosing number of threads
      ******************************************************/
      if(percent<140/nthreads || passLength<SMALLEST_ROUND){
        nthreads=1;
      }
      else if(percent<20){
        nthreads=(nthreads+1)/2;
      }
      else if(passLength < nthreads*SMALLEST_ROUND)
        nthreads=(nthreads+1)/2;


      /******************************************************
                      Sorting vertices
      ******************************************************/
      double hxtDeclareAligned bboxShift[4]={0.5,0.5,0.5,0};

      if(percent<100 && nthreads>1)
      {
        bboxShift[0] = (double) hxtReproducibleLCG(&seed)/RAND_MAX;
        bboxShift[1] = (double) hxtReproducibleLCG(&seed)/RAND_MAX;
        bboxShift[2] = (double) hxtReproducibleLCG(&seed)/RAND_MAX;
        bboxShift[3] = (double) hxtReproducibleLCG(&seed)/RAND_MAX; // this is not a bbox deformation, it's an index shift
      }

      uint32_t nbits = hxtAdvancedHilbertBits(options->bbox, options->minSizeStart, options->minSizeEnd,
                                                             options->numVerticesInMesh - passStart,
                                                             options->numVerticesInMesh - passStart + nToInsert,
                                                             options->numVerticesInMesh,
                                                             passLength,
                                                             nthreads);
      if(noReordering){
        HXT_CHECK( hxtVerticesHilbertDist(options->bbox, vertices, mesh->vertices.num, &nbits, bboxShift) );
      }
      else{
        // TODO: do not recompute hilber dist of the whole mesh on 1 thread
        HXT_CHECK( hxtVerticesHilbertDist(options->bbox, vertices, mesh->vertices.num - nToInsert + passEnd, &nbits, bboxShift) );
      }
      

      #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
      for (uint32_t i=passStart; i<passEnd; i++) {
        nodeInfo[i].hilbertDist = vertices[nodeInfo[i].node].padding.hilbertDist;
      }

      if(p!=0 || n!=0 || nthreads>1 || options->numVerticesInMesh >= SMALLEST_ROUND){
        HXT_CHECK( hxtNodeInfoSort(nodeInfo + passStart, passLength, nbits) );
      }

      const uint32_t step = passLength/nthreads;

      uint32_t indexShift = MIN(step-1,(uint32_t) bboxShift[3]*step);

      int threadFinished = 0;

      #pragma omp parallel num_threads(nthreads)
      {
      #ifdef _MSC_VER
        #pragma omp single
        nthreads = omp_get_num_threads();
      #endif

        uint64_t curTet = 0; // we always begin with the first tet. (index 0)
        const int threadID = omp_get_thread_num();

        uint32_t localStart;
        uint32_t localN;
        int foundTet = 0;

        if(nthreads>1){
          // if(threadID<nthreads){

          /******************************************************
                          Making partitions
          ******************************************************/
          localStart = step*threadID + indexShift;
          uint64_t dist = nodeInfo[passStart + localStart].hilbertDist;
          
          uint32_t up = 1;
          while(localStart+up<passLength && dist==nodeInfo[passStart + localStart + up].hilbertDist)
            up++;

          localStart = localStart+up==passLength?0:localStart+up;
          if(localStart > 0)
            Locals[threadID].partition.startDist = (nodeInfo[passStart + localStart].hilbertDist
                                                  + nodeInfo[passStart + localStart - 1].hilbertDist + 1)/2;
          else
            Locals[threadID].partition.startDist = nodeInfo[passStart + passLength-1].hilbertDist + (nodeInfo[passStart + localStart].hilbertDist - nodeInfo[passStart + passLength - 1].hilbertDist)/2;
          Locals[threadID].partition.first = localStart;
          // }

          #pragma omp barrier

          // if(threadID<nthreads){
          uint32_t localEnd = Locals[(threadID+1)%nthreads].partition.first;
          localN = (localEnd + passLength - localStart)%passLength;

          Locals[threadID].partition.endDist = Locals[(threadID+1)%nthreads].partition.startDist;

          // printf("%d) first dist: %lu, last dist: %lu startDist: %lu endDist: %lu\n", threadID, nodeInfo[passStart + localStart].hilbertDist, nodeInfo[(passStart + localStart + localN-1)%passLength].hilbertDist, Locals[threadID].partition.startDist, Locals[threadID].partition.endDist);


          /******************************************************
                          find starting tetrahedron
          ******************************************************/

          for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
          {
            curTet = i;
            if(isTetDeleted(mesh, i)==0 &&
               checkTetrahedron(vertices, &Locals[threadID], mesh->tetrahedra.node + curTet*4 )==HXT_STATUS_OK)
            {
              foundTet = 1;
              break;
            }
          }

          if(options->reproducible){
            Locals[threadID].partition.startDist = 0;
            Locals[threadID].partition.endDist = UINT64_MAX;

            // walk in total liberty toward the first point
            HXTStatus status = walking2Cavity(mesh, &Locals[threadID], &curTet, nodeInfo[passStart + (localStart+localN/2)%passLength].node);

            if(status!=HXT_STATUS_OK && status!=HXT_STATUS_TRYAGAIN){
              HXT_OMP_CHECK( status );
            }

            Locals[threadID].partition.startDist = nodeInfo[passStart + localStart].hilbertDist;
            Locals[threadID].partition.endDist = nodeInfo[passStart + localEnd].hilbertDist;

            if(checkTetrahedron(vertices, &Locals[threadID], mesh->tetrahedra.node + curTet*4 )!=HXT_STATUS_OK){
              foundTet = 0;
              // check the neighbors
              for (unsigned i=0; i<4; i++) {
                uint64_t tet = mesh->tetrahedra.neigh[4*curTet+i]/4;
                if(checkTetrahedron(vertices, &Locals[threadID], mesh->tetrahedra.node + tet*4 )==HXT_STATUS_OK){
                  foundTet = 1;
                  curTet = tet;
                  break;
                }
              }
            }
          }

          // }

          #pragma omp barrier
        }
        else
          // if(threadID==0)
        {

          /******************************************************
             single-thread partition and starting tetrahedron
          ******************************************************/
          localStart = 0;
          localN = passLength;
          Locals[0].partition.startDist = 0;
          Locals[0].partition.endDist = UINT64_MAX;

          for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
          { 
            if(isTetDeleted(mesh, i)==0){
              curTet = i;
              foundTet = 1;
              break;
            }
          }
        }

        if (foundTet == 0) {
          HXT_INFO_COND(options->verbosity>1,
                        "thread %d did not find any tetrahedron to begin with", threadID);
        }

        // filtering vertices on the Moore curve
        if(options->nodalSizes!=NULL)
        {
          double* p1 = NULL;
          double p1Size = 0;

          for (uint32_t i=0; i<localN; i++)
          {
            uint32_t passIndex = (localStart+i)%passLength;
            uint32_t lastNode = nodeInfo[passStart + passIndex].node;
            if(nodeInfo[passStart + passIndex].status==HXT_STATUS_TRYAGAIN){
              double* p2 = vertices[lastNode].coord;
              double p2Size = options->nodalSizes[lastNode];
              if(p1!=NULL && pointIsTooClose(p1, p2, 0.5*(p1Size+p2Size))!=HXT_STATUS_OK){
                nodeInfo[passStart + passIndex].status=HXT_STATUS_FALSE;
              }
              else{
                p1 = p2;
                p1Size = p2Size;
              }
            }
          }
        }


        // if(threadID<nthreads){
        if(foundTet!=0){

          /******************************************************
                          vertices insertion
          ******************************************************/
          for (uint32_t i=0; i<localN; i++)
          {
            uint32_t passIndex = (localStart+i)%passLength;
            uint32_t vta = nodeInfo[passStart + passIndex].node;
            if(nodeInfo[passStart + passIndex].status==HXT_STATUS_TRYAGAIN){
              HXTStatus status = insertion(mesh, verticesID, &Locals[threadID], options->nodalSizes, &curTet, vta, perfectlyDelaunay);

              switch(status){
                case HXT_STATUS_TRYAGAIN:
                  // ;
                  if(nthreads==1){
                    double* vtaCoord = vertices[vta].coord;
                    HXT_WARNING("skipping supposedly duplicate vertex (%f %f %f)", vtaCoord[0], vtaCoord[1], vtaCoord[2]);
                    nodeInfo[passStart + passIndex].status = HXT_STATUS_FALSE;
                    break;
                  }
                case HXT_STATUS_FALSE:
                case HXT_STATUS_TRUE:
                  nodeInfo[passStart + passIndex].status = status;
                  break;
                default: // error other than HXT_STATUS_TRYAGAIN cause the program to return
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
        // }

        #pragma omp atomic update
        threadFinished++;

        int val = 0;
        do{
          // threads are waiting here for a reallocation
          HXT_OMP_CHECK( synchronizeReallocation(mesh, &threadFinished, &val) );
        }while(val<nthreads);
        // }while(val<maxThreads);
      }

      /******************************************************
      vertices that have to be tried again are put at the end
      ******************************************************/
      // everything above i+shift is HXT_STATUS_TRYAGAIN
      uint32_t shift = 0;
      unsigned numSkipped = 0;
      for (uint32_t i=passEnd; i>passStart;)
      {
        i--;
        if(nodeInfo[i].status!=HXT_STATUS_TRYAGAIN){
          if(nodeInfo[i].status==HXT_STATUS_FALSE)
            numSkipped++;
          shift++;
        }
        else if(shift!=0) {
          hxtNodeInfo tmp = nodeInfo[i];
          nodeInfo[i] = nodeInfo[i+shift];
          nodeInfo[i+shift] = tmp;
        }
      }

      options->numVerticesInMesh += shift - numSkipped;

      percent = (shift-numSkipped)*100.0/MAX(1,passLength-numSkipped);
      totalNumSkipped += numSkipped;

      HXT_INFO_COND(options->verbosity>1,
                    "%3d thrd |%10u/%-10u-> %*.1f%-*c\t- mesh.nvert: %-10u",
                    nthreads, shift-numSkipped, passLength-numSkipped, MIN(8,n/2)+5, percent, 8-MIN(8,n/2),'%', options->numVerticesInMesh);
      
      passes[p] += shift;
    }
  }

  /******************************************************
                  Cleaning
  ******************************************************/
  #pragma omp parallel num_threads(maxThreads)
  {
    const int threadID = omp_get_thread_num();
    for (uint64_t i=0; i<Locals[threadID].deleted.num; i++) {
      for (int j=0; j<4; j++) {
        mesh->tetrahedra.neigh[4*Locals[threadID].deleted.tetID[i]+j] = HXT_NO_ADJACENT;
      }
    }
  }
  HXT_CHECK( hxtRemoveDeleted(mesh) );

  for (int i=0; i<maxThreads; i++){
    HXT_CHECK( hxtAlignedFree(&Locals[i].deleted.tetID) );
    HXT_CHECK( hxtAlignedFree(&Locals[i].ball.bnd) );
  }

  HXT_CHECK( hxtAlignedFree(&verticesID) );
  HXT_CHECK( hxtFree(&Locals) );

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
      #pragma omp for
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
        options->nodalSizes[vertices[i].padding.index] = options->nodalSizes[i];
      }
      vertices[vertices[i].padding.index] = vertices[i];
    }

    if(options->verbosity>1)
      HXT_INFO("%u vertices removed (vertices not inserted in the mesh are removed when using hxtDelaunay)\n", totalNumSkipped);

    mesh->vertices.num = mesh->vertices.num - totalNumSkipped;
  }

  HXT_INFO_COND(options->verbosity>0, "Delaunay done !%10u skipped", totalNumSkipped);
  HXT_INFO_COND(options->verbosity>1, "mem. allocated:%5.2fGB - mesh.ntet: %-12lu - mesh.nvert: %-10lu",
    ((50 + 2*(mesh->tetrahedra.flag!=NULL)) * mesh->tetrahedra.size +
     (32 + 8*(options->nodalSizes!=NULL)) * mesh->vertices.size)/(1024.*1024.*1024.),
    mesh->tetrahedra.num, mesh->vertices.num);

  if(options->reproducible && maxThreads!=1){
    HXT_INFO_COND(options->verbosity>1, "Reordering tetrahedra (reproducible==true)\n", mesh->vertices.num - nToInsert, mesh->vertices.num);
    HXT_CHECK( hxtTetReorder(mesh) );
  }

  return HXT_STATUS_OK;
}


/*****************************************
 * complete the HXTDelaunayOptions struct
 * when there are missing fields.
 ****************************************/
static HXTStatus DelaunayOptionsInit(HXTMesh* mesh,
                                HXTDelaunayOptions* userOptions,
                                HXTDelaunayOptions* options,
                                HXTBbox* bbox){
HXT_ASSERT(mesh!=NULL);

  if(userOptions!=NULL){
    options->bbox = userOptions->bbox;
    options->nodalSizes = userOptions->nodalSizes;
    options->verbosity = userOptions->verbosity;
    options->minSizeStart = MAX(0.0, userOptions->minSizeStart);
    options->minSizeEnd = MAX(options->minSizeStart, userOptions->minSizeEnd);
    options->numVerticesInMesh = userOptions->numVerticesInMesh;
    options->delaunayThreads = userOptions->delaunayThreads;
    options->reproducible = userOptions->reproducible;
  }
  else{
    HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

    // default parameters
    options->bbox = NULL;
    options->nodalSizes = NULL;
    options->minSizeStart = 0.0;
    options->minSizeEnd = 0.0;
    options->verbosity = 1;
    options->delaunayThreads = 0;
    options->reproducible = 0;

    // count the number of vertices in the mesh
    #pragma omp parallel for
    for (uint32_t i=0; i<mesh->vertices.num; i++) {
      vertices[i].padding.index = 0;
    }

    #pragma omp parallel for
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      vertices[mesh->tetrahedra.node[4*i+0]].padding.index = 1;
      vertices[mesh->tetrahedra.node[4*i+1]].padding.index = 1;
      vertices[mesh->tetrahedra.node[4*i+2]].padding.index = 1;
      if(mesh->tetrahedra.node[4*i+3]!=HXT_GHOST_VERTEX)
        vertices[mesh->tetrahedra.node[4*i+3]].padding.index = 1;
    }

    uint32_t numVerticesInMesh = 0;
    #pragma omp parallel for reduction(+:numVerticesInMesh)
    for (uint32_t i=0; i<mesh->vertices.num; i++) {
        numVerticesInMesh += vertices[i].padding.index;
    }

    options->numVerticesInMesh = numVerticesInMesh;
  }

HXT_ASSERT(options->numVerticesInMesh <= mesh->vertices.num);

  if(options->bbox==NULL){
    options->bbox = bbox;
    hxtBboxInit(bbox);
    HXT_CHECK( hxtBboxAdd(bbox, mesh->vertices.coord, mesh->vertices.num) );
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
HXTStatus hxtDelaunay(HXTMesh* mesh, HXTDelaunayOptions* userOptions){
  HXTDelaunayOptions options;
  HXTBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, userOptions, &options, &bbox) );

  const uint32_t nToInsert = mesh->vertices.num - options.numVerticesInMesh;

  if(options.reproducible && nToInsert<2048) // not worth launching threads and having to reorder tets after...
    options.delaunayThreads = 1;

  hxtNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, nToInsert*sizeof(hxtNodeInfo)) );
  
  // we fill nodeInfo with the indices of each vertices to insert...
  #pragma omp parallel for simd
  for (uint32_t i=0; i<nToInsert; i++) {
    nodeInfo[i].node = options.numVerticesInMesh + i;
    nodeInfo[i].status = HXT_STATUS_TRYAGAIN; // necessary for when foundTet = 0;
  }

  HXT_CHECK( parallelDelaunay3D(mesh, &options, nodeInfo, nToInsert, 0) );

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );

  return HXT_STATUS_OK;
}


/************************************************
 * parallel Delaunay without moving the vertices
 * see header for a complete description
 ***********************************************/
HXTStatus hxtDelaunaySteadyVertices(HXTMesh* mesh, HXTDelaunayOptions* userOptions, hxtNodeInfo* nodeInfo, uint64_t nToInsert){
HXT_ASSERT(nodeInfo!=NULL);

  HXTDelaunayOptions options;
  HXTBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, userOptions, &options, &bbox) );

  if(options.reproducible && nToInsert<2048) // not worth launching threads and having to reorder tets after...
    options.delaunayThreads = 1;

HXT_ASSERT(options.numVerticesInMesh+nToInsert <= mesh->vertices.num);

  HXT_CHECK( parallelDelaunay3D(mesh, &options, nodeInfo, nToInsert, 1) );

  return HXT_STATUS_OK;
}

