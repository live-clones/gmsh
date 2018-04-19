#include "hxt_tetrahedra.h"
#include "predicates.h"
#include "hxt_sort.h"


/* compile-time parameters */
#define SMALLEST_ROUND 2048
#define ROUND_RATIO 7
#define THREAD_RATIO 8
#define DELETED_BUFFER_SIZE 8182
// #define HXT_DELAUNAY_MAX_MEMORY /* use per thread bufffer instead of a global one (it's faster if it fits into RAM) */
// #define HXT_DELAUNAY_LOW_MEMORY /* doesn't use any buffer (a lot slower, except if you are at the limit of filling the RAM) */
// (if both are defined, MAX_MEMORY takes over MIN_MEMORY)

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

/* usefull mask */
static const uint64_t NEIGH_H = UINT64_C(0xFFFFFFFFFFFFFFFC);

typedef struct TetLocalStruct {
  uint64_t hxtDeclareAligned Map[1024];

  struct{
    uint32_t hxtDeclareAligned node[4];
    uint64_t otherside; // the tet on the other side of the boundar
  } *bnd;
  uint64_t numBnd;
  uint64_t sizeBnd;

  uint64_t* deleted;
  uint64_t numDeleted;
  uint64_t sizeDeleted;

  uint32_t* vertices;
  uint32_t numVertices;
  uint32_t sizeVertices;

  uint64_t startDist;
  uint64_t endDist;
  uint32_t localStart;
} TetLocal;


static inline HXTStatus walking2Cavity(HXTMesh* mesh, TetLocal* local, uint64_t* curTet, const uint32_t vta);
static inline HXTStatus diggingACavity(HXTMesh* mesh, TetLocal* local, uint64_t curTet, const uint32_t vta, const uint16_t color);
static inline HXTStatus fillingACavity(HXTMesh* mesh, TetLocal* local, uint32_t* verticesID, uint64_t* curTet, const uint16_t color);
static inline HXTStatus filterCavity (TetLocal* local, HXTMesh *mesh, const double *nodalSizes);
// static HXTStatus hxtTetrahedraVerifyInternal(HXTMesh* mesh, TetLocal* Locals, int nthreads);



HXTStatus hxtTetrahedraReserve(HXTMesh* mesh, uint64_t ntet){
  ntet+=mesh->tetrahedra.num;
  if(ntet > mesh->tetrahedra.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.colors, ntet*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.node,   ntet*4*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.neigh,  ntet*4*sizeof(uint64_t)) );
    mesh->tetrahedra.size = ntet;
  }
  return HXT_STATUS_OK;
}


/***********************************
 * remove deleted tetrahedra of mesh
 ***********************************/
//TODO: maybe do this in parallel (like in a sort pass)
HXTStatus hxtRemoveDeleted(HXTMesh* mesh){

  uint64_t right = mesh->tetrahedra.num-1;
  uint64_t left = 0;

  while(1) {
    while(left < right && mesh->tetrahedra.colors[right]==HXT_DELETED_COLOR) right--;
    while(left < right && mesh->tetrahedra.colors[left]!=HXT_DELETED_COLOR) left++;

    if(left >= right)
      break;

    mesh->tetrahedra.colors[left] = mesh->tetrahedra.colors[right];

    // swap the two tetrahedra
    for (unsigned j=0; j<4; j++) {

      uint64_t neigh = mesh->tetrahedra.neigh[4*right+j];
      if(neigh!=HXT_NO_ADJACENT)
        mesh->tetrahedra.neigh[neigh] = 4*left+j;

      mesh->tetrahedra.node[4*left+j] = mesh->tetrahedra.node[4*right+j];
      mesh->tetrahedra.neigh[4*left+j] = neigh;
    }

    left++; right--;
  }

  if(left==right && mesh->tetrahedra.colors[left]!=HXT_DELETED_COLOR) left++;

  mesh->tetrahedra.num = left;

  return HXT_STATUS_OK;
}


static inline HXTStatus hxtTetrahedraInit(HXTMesh* mesh, hxtNodeInfo* nodeInfo, uint32_t nToInsert){
  if(nToInsert < 4){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "cannot mesh less than four vertices");
  }
  if(mesh->tetrahedra.size < 5){
    HXT_INFO("Initialization reserved %lu Tet.", 10UL*nToInsert);
    hxtTetrahedraReserve(mesh, 10UL*nToInsert);
  }

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
          orientation = orient3d(mesh->vertices.coord + 4*nodeInfo[i].node,
                                 mesh->vertices.coord + 4*nodeInfo[j].node,
                                 mesh->vertices.coord + 4*nodeInfo[k].node,
                                 mesh->vertices.coord + 4*nodeInfo[l].node);
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
    uint32_t tmp = nodeInfo[i].node;
    nodeInfo[i].node = nodeInfo[0].node;
    nodeInfo[0].node = tmp;
    i = 0;

    tmp = nodeInfo[j].node;
    nodeInfo[j].node = nodeInfo[1].node;
    nodeInfo[1].node = tmp;
    j = 1;

    tmp = nodeInfo[k].node;
    nodeInfo[k].node = nodeInfo[2].node;
    nodeInfo[2].node = tmp;
    k = 2;

    tmp = nodeInfo[l].node;
    nodeInfo[l].node = nodeInfo[3].node;
    nodeInfo[3].node = tmp;
    l = 3;
  }


  if(orientation < 0.0){
    uint32_t tmp = i;
    i = j;
    j = tmp;
  }

  mesh->tetrahedra.neigh[ 0] = 19;        mesh->tetrahedra.node[ 0] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[ 1] = 15;        mesh->tetrahedra.node[ 1] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[ 2] = 11;        mesh->tetrahedra.node[ 2] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[ 3] =  7;        mesh->tetrahedra.node[ 3] = nodeInfo[i].node;

  mesh->tetrahedra.neigh[ 4] = 18;        mesh->tetrahedra.node[ 4] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[ 5] = 10;        mesh->tetrahedra.node[ 5] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[ 6] = 13;        mesh->tetrahedra.node[ 6] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[ 7] =  3;        mesh->tetrahedra.node[ 7] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[8 ] = 17;        mesh->tetrahedra.node[ 8] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[9 ] = 14;        mesh->tetrahedra.node[ 9] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[10] =  5;        mesh->tetrahedra.node[10] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[11] =  2;        mesh->tetrahedra.node[11] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[12] = 16;        mesh->tetrahedra.node[12] = nodeInfo[l].node;
  mesh->tetrahedra.neigh[13] =  6;        mesh->tetrahedra.node[13] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[14] =  9;        mesh->tetrahedra.node[14] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[15] =  1;        mesh->tetrahedra.node[15] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.neigh[16] = 12;        mesh->tetrahedra.node[16] = nodeInfo[k].node;
  mesh->tetrahedra.neigh[17] =  8;        mesh->tetrahedra.node[17] = nodeInfo[j].node;
  mesh->tetrahedra.neigh[18] =  4;        mesh->tetrahedra.node[18] = nodeInfo[i].node;
  mesh->tetrahedra.neigh[19] =  0;        mesh->tetrahedra.node[19] = HXT_GHOST_VERTEX;

  mesh->tetrahedra.num = 5;

  for (uint64_t i=0; i<5 ;i++)  mesh->tetrahedra.colors[i] = UINT16_MAX;

  return HXT_STATUS_OK;
}


// fill the passes array and the number of threads to beginwith
// return the number of passes
static unsigned computePasses(uint32_t passes[12], uint32_t nInserted, uint32_t nToInsert,
                                     int* nthreads)
{
  unsigned npasses;
  *nthreads = 1;

  passes[0] = 0;
  if(nInserted*ROUND_RATIO < SMALLEST_ROUND)
    passes[1] = SMALLEST_ROUND;
  else{
    passes[1] = nInserted*ROUND_RATIO;

    // we already begin with a good number of points in the mesh
    // => compute how much threads we can launch
    uint32_t tmp = nInserted/SMALLEST_ROUND;
    while(tmp>0){
      tmp/=ROUND_RATIO;
      *nthreads*=THREAD_RATIO;
    }
  }

  if(nToInsert < passes[1]){
    passes[1] = nToInsert;
    npasses = 1;
  }
  else{
    npasses = 2;
    for (uint32_t i=ROUND_RATIO*MAX(passes[1],SMALLEST_ROUND); i<nToInsert; i*=ROUND_RATIO)
      passes[npasses++] = i;

    passes[npasses] = nToInsert;
  }

  return npasses;
}



static inline HXTStatus localInit(TetLocal* local){
    local->sizeBnd = 1020; // accounting for the offset in aligned malloc, to avoid additional memory page
    local->numBnd = 0;
    local->bnd = NULL;
    local->sizeDeleted = DELETED_BUFFER_SIZE;
    local->numDeleted = 0;
    local->deleted = NULL;
    local->sizeVertices = 1014;
    local->numVertices = 0;
    local->vertices = NULL;

    HXT_CHECK( hxtAlignedMalloc(&local->bnd, local->sizeBnd*sizeof(local->bnd[0])) );
    HXT_CHECK( hxtAlignedMalloc(&local->deleted, local->sizeDeleted*sizeof(uint64_t)) );
    HXT_CHECK( hxtAlignedMalloc(&local->vertices, local->sizeVertices*sizeof(uint32_t)) );

    return HXT_STATUS_OK;
}


static HXTStatus synchronizeReallocation(HXTMesh* mesh, volatile int* toCopy, volatile int* copy){
  // threads cant be doing something while the realloc portion happen
  #pragma omp barrier
  
  // this unable us to have the same value of toCopy fore everyone, as we are sure nothing happens to those variables here
  if(toCopy!=copy){
    *copy = *toCopy;
  }

  HXTStatus fail = HXT_STATUS_OK;
  // make reallocations in a critical section
  #pragma omp single
  {
    uint64_t nTet = mesh->tetrahedra.num;
    uint64_t tetSize = mesh->tetrahedra.size;
    if(nTet > tetSize){
      fail = hxtAlignedRealloc(&mesh->tetrahedra.neigh, nTet*8*sizeof(uint64_t));
      if(fail>=0) fail = hxtAlignedRealloc(&mesh->tetrahedra.node, nTet*8*sizeof(uint32_t));
      if(fail>=0) fail = hxtAlignedRealloc(&mesh->tetrahedra.colors, nTet*2*sizeof(uint16_t));
      mesh->tetrahedra.size = 2*nTet;
      HXT_INFO("reallocation happened\n");
    }
  } // implicit barrier here

  if(fail<0){
    HXT_TRACE(fail);
    return fail;
  }

  return HXT_STATUS_OK;
}


// pragma atomic capture to get tetrahedra.num and update it at the same time before caling this function !
static inline HXTStatus reserveNewTet(HXTMesh* mesh){
  if(mesh->tetrahedra.num > mesh->tetrahedra.size){
    HXT_CHECK( synchronizeReallocation(mesh, NULL, NULL) );
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus reserveNewDeleted(TetLocal* local, uint64_t num){
  if(num > local->sizeDeleted){
      HXT_CHECK( hxtAlignedRealloc(&local->deleted, 2*num*sizeof(uint64_t)) );
      local->sizeDeleted = 2*num;
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus reserveNewBnd(TetLocal* local, uint64_t num){
  if(num > local->sizeBnd){
      HXT_CHECK( hxtAlignedRealloc(&local->bnd, 2*num*sizeof(local->bnd[0])) );
      local->sizeBnd = 2*num;
  }

  return HXT_STATUS_OK;
}


static inline HXTStatus reserveNewVertices(TetLocal* local, uint32_t num){
  if(num > local->sizeVertices){
      HXT_CHECK( hxtAlignedRealloc(&local->vertices, 2*num*sizeof(uint32_t)) );
      local->sizeVertices = 2*num;
  }

  return HXT_STATUS_OK;
}



static inline HXTStatus checkTetrahedron(hxtVertex* vertices, TetLocal* local, const uint32_t* nodes){
  uint64_t rel = local->endDist - local->startDist;

  if(rel==UINT64_MAX) // we are working with one thread only...
    return HXT_STATUS_OK;

  // unsigned wrap around is defined by the standard, so we improve the speed
  uint64_t d0 = vertices[nodes[0]].padding.hilbertDist - local->startDist;
  uint64_t d1 = vertices[nodes[1]].padding.hilbertDist - local->startDist;
  uint64_t d2 = vertices[nodes[2]].padding.hilbertDist - local->startDist;
  uint64_t d3 = (nodes[3]==HXT_GHOST_VERTEX?0:vertices[nodes[3]].padding.hilbertDist) - local->startDist;

#if defined( HXT_DELAUNAY_MAX_MEMORY ) || defined( HXT_DELAUNAY_LOW_MEMORY )
  if( (d0>=rel) + (d1>=rel) + (d2>=rel) + (d3>=rel) > 1)
    return HXT_STATUS_INTERNAL;
#else
  if((d0>=rel) || (d1>=rel) || (d2>=rel) || (d3>=rel))
    return HXT_STATUS_INTERNAL;
#endif

  return HXT_STATUS_OK;

}


#define HXT_SQR(X) (X)*(X)

static inline HXTStatus filterCavity (TetLocal* local, HXTMesh *mesh, const double *nodalSizes)
{
  uint32_t vta = local->bnd[0].node[0];
  double *vtaCoord = mesh->vertices.coord + 4*vta;
  double vtaNodalSize = nodalSizes[vta];

  for (uint64_t i = 0 ; i< local->numBnd ; i++) {
    for (uint64_t j=1;j<4;j++) {
      uint32_t nodej = local->bnd[i].node[j];

      if (j!=3 || nodej != HXT_GHOST_VERTEX){
        double *Xj = mesh->vertices.coord + 4*nodej;
        double d2 = HXT_SQR (vtaCoord[0]-Xj[0])
                  + HXT_SQR (vtaCoord[1]-Xj[1])
                  + HXT_SQR (vtaCoord[2]-Xj[2]);
        double minSizeAllowed = 0.8 * 0.5 * ( vtaNodalSize + nodalSizes[nodej]);  
        if (d2 < HXT_SQR(minSizeAllowed)){
          return  HXT_STATUS_INTERNAL;
        }
      }
    }
  }
  return  HXT_STATUS_OK;
}


static inline void restoreDeleted(HXTMesh* mesh, TetLocal* local, const uint64_t prevDeleted, const uint16_t color){
  for (uint64_t i=prevDeleted; i<local->numDeleted; i++)
    mesh->tetrahedra.colors[local->deleted[i]/4] = color;

  local->numDeleted = prevDeleted;
}


static inline HXTStatus doTheWork(HXTMesh* mesh,
                                  uint32_t* verticesID,
                                  TetLocal* local,
                                  const double* nodalSizes,
                                  uint64_t* curTet,
                                  const uint32_t vta){
  const uint64_t prevDeleted = local->numDeleted;

  HXT_CHECK( walking2Cavity(mesh, local, curTet, vta) );


  const uint16_t color = mesh->tetrahedra.colors[*curTet/4];
  HXTStatus status = diggingACavity(mesh, local, *curTet, vta, color);

  if(status==HXT_STATUS_INTERNAL){
    restoreDeleted(mesh, local, prevDeleted, color);
    return HXT_STATUS_TRYAGAIN;
  }
  else{
    HXT_CHECK(status);
  }

  // printf("deleted: %lu, bnd:%lu\n", local->numDeleted, local->numBnd);
  if(nodalSizes!=NULL && filterCavity(local, mesh, nodalSizes)==HXT_STATUS_INTERNAL){
    restoreDeleted(mesh, local, prevDeleted, color);
    return HXT_STATUS_FALSE;
  }


  if(local->numBnd > local->numDeleted){
    uint64_t needed = MAX(DELETED_BUFFER_SIZE-local->numDeleted, local->numBnd - local->numDeleted);

    uint64_t ntet;

    #pragma omp atomic capture
    { ntet = mesh->tetrahedra.num; mesh->tetrahedra.num+=needed;}

    reserveNewTet(mesh);
    reserveNewDeleted(local, local->numDeleted+needed);

    #pragma omp simd
    for (uint64_t i=0; i<needed; i++){
      local->deleted[local->numDeleted+i] = 4*(ntet+i);
      mesh->tetrahedra.colors[ntet+i] = HXT_DELETED_COLOR;
    }

    local->numDeleted+=needed;
  }

  HXT_CHECK( fillingACavity(mesh, local, verticesID, curTet, color) );

  return HXT_STATUS_TRUE;
}




static HXTStatus hxtTetrahedraCompute(HXTMesh* mesh,
                                      HXTDelaunayOptions* options,
                                      hxtNodeInfo* nodeInfo,
                                      const uint64_t nToInsert,
                                      int noReordering)
{

  double time = omp_get_wtime();

  uint64_t numTetrahedra = mesh->tetrahedra.num;
  uint32_t totalNumSkipped = 0;

  // third, divide indices in different passes
  const int maxThreads = omp_get_max_threads();
  int threadToBeginWith;
  uint32_t passes[12];

  unsigned npasses = computePasses(passes, options->numVerticesInMesh, nToInsert, &threadToBeginWith);
  threadToBeginWith = MIN(threadToBeginWith, maxThreads);

  // that ugly cast because people want an array of double into the mesh structure
  hxtVertex* vertices = (hxtVertex*) mesh->vertices.coord;
  

  /******************************************************
          shuffle (and optimize cache locality)
  ******************************************************/
  if(noReordering){
    // shuffle nodeInfo
    HXT_CHECK( hxtNodeInfoShuffle(nodeInfo, nToInsert) );
  }
  else{
    hxtVertex* verticesToInsert = vertices + mesh->vertices.num - nToInsert;
    // shuffle the vertices to insert, then sort each pass except the first according to the hilbert curve...
    HXT_CHECK( hxtVerticesShuffle(verticesToInsert, nToInsert) );

    uint32_t nbits = 0;
    HXT_CHECK( hxtVerticesHilbertDist(options->bbox, verticesToInsert, nToInsert, &nbits, NULL) );

    for (unsigned i=1; i<npasses; i++) {
      HXT_CHECK( hxtVerticesSort(verticesToInsert+passes[i], passes[i+1]-passes[i], nbits) );
    }
  }

  /******************************************************
        Initializations and allocations
  ******************************************************/
  if(mesh->tetrahedra.num<5){
    HXT_INFO_COND(options->verbosity>0,
                  "Initializing mesh");
    HXT_CHECK( hxtTetrahedraInit(mesh, nodeInfo, nToInsert) );
    options->numVerticesInMesh = 4; // not counting the ghost vertex
    passes[0] = 4;
  }


  uint32_t*  verticesID;
#if defined( HXT_DELAUNAY_MAX_MEMORY )
  HXT_CHECK( hxtAlignedMalloc(&verticesID, maxThreads*(mesh->vertices.num+SIMD_ALIGN/4)*sizeof(uint32_t)) );
#elif defined( HXT_DELAUNAY_LOW_MEMORY )
  verticesID = NULL; // we do not need it
#else
  HXT_CHECK( hxtAlignedMalloc(&verticesID, (mesh->vertices.num+1)*sizeof(uint32_t)) );
#endif

  TetLocal* Locals;
  HXT_CHECK( hxtMalloc(&Locals, maxThreads*sizeof(TetLocal)) );
  // HXT_CHECK( hxtMalloc())

  for (int i=0; i<maxThreads; i++)
    localInit(&Locals[i]);


  HXT_INFO_COND(options->verbosity>0,
                "insertion of %10u vertices (%3d threads )\t- mesh.nvert: %-10u",
                passes[npasses] - passes[0], maxThreads, options->numVerticesInMesh);

  for (uint32_t p=0; p<npasses; p++)
  {

    double percent = 200;

    int nthreads = threadToBeginWith;
    threadToBeginWith=MIN(threadToBeginWith*THREAD_RATIO, maxThreads);
    const uint32_t initialPassLength = passes[p+1] - passes[p];

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
        nthreads/=2;
      }
      else if(passLength < nthreads*SMALLEST_ROUND)
        nthreads/=2;


      /******************************************************
                      Sorting vertices
      ******************************************************/

      double hxtDeclareAligned bboxShift[4]={0.5,0.5,0.5,0};


      if(percent<100 && nthreads>1)
      {
        bboxShift[0] = (double) rand()/RAND_MAX;
        bboxShift[1] = (double) rand()/RAND_MAX;
        bboxShift[2] = (double) rand()/RAND_MAX;
        bboxShift[3] = (double) rand()/RAND_MAX; // this is not a bbox deformation, it's an index shift
      }

      uint32_t nbits = hxtAdvancedHilbertBits(initialPassLength, passLength, nthreads, maxThreads);
      if(noReordering){
        HXT_CHECK( hxtVerticesHilbertDist(options->bbox, vertices, mesh->vertices.num, &nbits, bboxShift) );
      }
      else{
        HXT_CHECK( hxtVerticesHilbertDist(options->bbox, vertices, mesh->vertices.num - nToInsert + passEnd, &nbits, bboxShift) );
      }
      

      #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
      for (uint32_t i=passStart; i<passEnd; i++) {
        nodeInfo[i].hilbertDist = vertices[nodeInfo[i].node].padding.hilbertDist;
      }

      if(n!=0){
        HXT_CHECK( hxtNodeInfoSort(nodeInfo + passStart, passLength, nbits) );
      }

      const uint32_t rem = passLength%nthreads;
      const uint32_t step = passLength/nthreads;

      uint32_t indexShift = MIN(step-1,(uint32_t) bboxShift[3]*step);

      int threadFinished = 0;

      #pragma omp parallel num_threads(nthreads)
      {
        uint64_t curTet = 0; // we always begin with the first tet. (index 0)
        const int threadID = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        uint32_t localStart;
        uint32_t localN;
        int foundTet = 0;

        if(nthreads>1){
          // if(threadID<nthreads){

          /******************************************************
                          Making partitions
          ******************************************************/

          // printf("bbox: %f %f %f shift = %u/%u\n", bboxShift[0], bboxShift[1], bboxShift[2], indexShift%step, step);
          localStart = step*threadID + ((threadID>=rem)?rem:threadID) + indexShift;
          uint64_t dist = nodeInfo[passStart + localStart].hilbertDist;
          
          uint32_t up = 1;
          while(localStart+up<passLength && dist==nodeInfo[passStart + localStart + up].hilbertDist)
            up++;

          uint32_t down = 0;
          while(localStart>down && dist==nodeInfo[passStart + localStart-down-1].hilbertDist)
            down--;

          if(up>down && threadID!=0 &&
                nodeInfo[passStart
                 + step*(threadID-1) + (((threadID-1)>=rem)?rem:(threadID-1))
                 + indexShift].hilbertDist
                ==dist)
              localStart -=down;
          else
            localStart += up;
        
          Locals[threadID].localStart = localStart;
          // }

          #pragma omp barrier

          // if(threadID<nthreads){
          uint32_t localEnd = Locals[(threadID+1)%nthreads].localStart;
          // if localStart = localEnd, the length is 0
          localN = (localEnd + passLength - localStart)%passLength;

          Locals[threadID].startDist = nodeInfo[passStart + localStart].hilbertDist;
          Locals[threadID].endDist = nodeInfo[passStart + localEnd].hilbertDist;

          /******************************************************
                          find starting tetrahedron
          ******************************************************/

          for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
          {
            curTet = i*4;
            if(mesh->tetrahedra.colors[i]!=HXT_DELETED_COLOR &&
               checkTetrahedron(vertices, &Locals[threadID], mesh->tetrahedra.node + curTet )==HXT_STATUS_OK)
            {
              foundTet = 1;
              break;
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
          Locals[0].startDist = 0;
          Locals[0].endDist = UINT64_MAX;

          for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
          { 
            if(mesh->tetrahedra.colors[i]!=HXT_DELETED_COLOR){
              curTet = i*4;
              foundTet = 1;
              break;
            }
          }
        }

        if (foundTet == 0) {
          HXT_INFO_COND(options->verbosity>1,
                        "thread %d did not find any tetrahedron to begin with", threadID);
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
            #ifdef HXT_DELAUNAY_MAX_MEMORY
              HXTStatus status = doTheWork(mesh,
                                           verticesID+((threadID*(mesh->vertices.num+SIMD_ALIGN/4)) & ~(SIMD_ALIGN/4 - 1)),
                                           &Locals[threadID],
                                           options->nodalSizes,
                                           &curTet,
                                           vta);
            #else
              HXTStatus status = doTheWork(mesh, verticesID, &Locals[threadID], options->nodalSizes, &curTet, vta);
            #endif

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
        }
        // }

        #pragma omp atomic update
        threadFinished++;

        int val = 0;
        do{
          // threads are waiting here for a reallocation
          synchronizeReallocation(mesh, &threadFinished, &val);
        }while(val<nthreads);
        // }while(val<maxThreads);

        // HXT_INFO("thread %d terminated", threadID, threadFinished, nthreads);
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

      percent = (shift-numSkipped)*100.0/(passes[p+1]-passes[p]-numSkipped);
      totalNumSkipped += numSkipped;

      HXT_INFO_COND(options->verbosity>1,
                    "%3d thrd |%10u/%-10u-> %*.1f%-*c\t- mesh.nvert: %-10u",
                    nthreads, shift, passLength, MIN(8,n/2)+5, percent, 8-MIN(8,n/2),'%', options->numVerticesInMesh);
      
      passes[p] += shift;
    }
  }

  /******************************************************
                  Cleaning
  ******************************************************/

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  for (int i=0; i<maxThreads; i++){
    HXT_CHECK( hxtAlignedFree(&Locals[i].deleted) );
    HXT_CHECK( hxtAlignedFree(&Locals[i].bnd) );
    HXT_CHECK( hxtAlignedFree(&Locals[i].vertices) );
  }

  HXT_CHECK( hxtAlignedFree(&verticesID) );
  HXT_CHECK( hxtFree(&Locals) );

  /***************************************************************
    if reordering allowed, remove vertices we could not insert
  ***************************************************************/
  if(!noReordering && totalNumSkipped!=0){
    /* remove deleted vertices and change tetrahedra.node accordingly */

    uint32_t* numInserted;
    HXT_CHECK( hxtAlignedMalloc(&numInserted, maxThreads*sizeof(uint32_t)) );

    uint32_t firstShifted = mesh->vertices.num - nToInsert;
    uint32_t n = nToInsert;

    // when a vertex was skipped, nodeInfo[i].status = HXT_STATUS_FALSE
    #pragma omp parallel
    {
      // uint32_t localFirstSkipped = UINT32_MAX;

      // 1st: mark vertices with their corresponding status
      #pragma omp for schedule(static)
      for (uint32_t i=0; i<nToInsert; i++) {
        uint32_t index = nodeInfo[i].node;
        HXTStatus status = nodeInfo[i].status;
        vertices[index].padding.status = status;
        // if(status!=HXT_STATUS_TRUE && localFirstSkipped>i)
        //   localFirstSkipped = i;
      }

      #pragma omp barrier
      #pragma omp single
      {
        uint32_t i = 0;
        while (vertices[firstShifted+i].padding.status==HXT_STATUS_TRUE) i++;

        firstShifted += i+1;
        n -= i+1;
      }

      uint32_t start = 0;
      int threadID = omp_get_thread_num();
      numInserted[threadID] = 0;

      #pragma omp for schedule(static)
      for (uint32_t i=0; i<n; i++) {
        if(vertices[firstShifted+i].padding.status==HXT_STATUS_TRUE)
          numInserted[threadID]++;
      }

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

HXT_ASSERT(totalNumSkipped==mesh->vertices.num - vertices[mesh->vertices.num-1].padding.index - 1);

    HXT_CHECK( hxtAlignedFree(&numInserted) );

    // 5th: put vertices at the right indices
    for (uint32_t i=firstShifted; i<mesh->vertices.num; i++) {
      vertices[vertices[i].padding.index] = vertices[i];
    }

    if(options->verbosity>1)
      HXT_INFO("%u vertices removed (vertices not inserted in the mesh are removed when using hxtDelaunay)", totalNumSkipped);
    else if(options->verbosity>0)
      HXT_INFO("%u vertices removed", totalNumSkipped);


    mesh->vertices.num = mesh->vertices.num - totalNumSkipped;
  }

  if(options->verbosity>0){
    time = omp_get_wtime() - time;
    long long int tetCreated = (long long int) mesh->tetrahedra.num - (long long int) numTetrahedra;
    HXT_INFO("took %f second for %lld tetrahedra (%.3f Mtet./s)",
                  time, tetCreated , tetCreated/time/1000000.0);
  }

  return HXT_STATUS_OK;
}



static HXTStatus DelaunayOptionsInit(HXTMesh* mesh,
                                HXTDelaunayOptions* userOptions,
                                HXTDelaunayOptions* options,
                                hxtBbox* bbox){
HXT_ASSERT(mesh!=NULL);

  if(userOptions!=NULL){
    options->bbox = userOptions->bbox;
    options->nodalSizes = userOptions->nodalSizes;
    options->verbosity = userOptions->verbosity;
    options->numVerticesInMesh = userOptions->numVerticesInMesh;
  }
  else{
    // default parameters
    options->bbox = NULL;
    options->nodalSizes = NULL;
    options->verbosity = 0;

    // count the number of vertices in the mesh
    #pragma omp parallel for
    for (uint32_t i=0; i<mesh->vertices.num; i++) {
      mesh->vertices.coord[4*i+3] = 0.0;
    }

    #pragma omp parallel for
    for (uint64_t i=0; i<4*mesh->tetrahedra.num; i++) {
      mesh->vertices.coord[4*mesh->tetrahedra.node[i]+3] = 1.0;
    }

    uint32_t numVerticesInMesh = 0;
    #pragma omp parallel for reduction(+:numVerticesInMesh)
    for (uint32_t i=0; i<mesh->vertices.num; i++) {
        numVerticesInMesh += mesh->vertices.coord[4*i+3];
    }

    options->numVerticesInMesh = numVerticesInMesh;
  }

HXT_ASSERT(options->numVerticesInMesh <= mesh->vertices.num);

  if(options->bbox==NULL){
    options->bbox = bbox;
    hxtBboxInit(bbox);
    HXT_CHECK( hxtBboxAdd(bbox, mesh->vertices.coord, mesh->vertices.num) );
  }

  // for the predicates to work
  exactinit(options->bbox->max[0]-options->bbox->min[0],
            options->bbox->max[1]-options->bbox->min[1],
            options->bbox->max[2]-options->bbox->min[2]);

  return HXT_STATUS_OK;
}



HXTStatus hxtDelaunay(HXTMesh* mesh, HXTDelaunayOptions* userOptions){
  HXTDelaunayOptions options;
  hxtBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, userOptions, &options, &bbox) );

  const uint64_t nToInsert = mesh->vertices.num - options.numVerticesInMesh;

  hxtNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, nToInsert*sizeof(hxtNodeInfo)) );
  
  // we fill nodeInfo with the indices of each vertices to insert...
  #pragma omp parallel for simd
  for (uint32_t i=0; i<nToInsert; i++) {
    nodeInfo[i].node = options.numVerticesInMesh + i;
    // nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
  }

  hxtTetrahedraCompute(mesh, &options, nodeInfo, nToInsert, 0);

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );

  return HXT_STATUS_OK;
}



HXTStatus hxtDelaunaySteadyVertices(HXTMesh* mesh, HXTDelaunayOptions* userOptions, hxtNodeInfo* nodeInfo, uint64_t nToInsert){
  HXT_ASSERT(nodeInfo!=NULL);

  HXTDelaunayOptions options;
  hxtBbox bbox;
  HXT_CHECK( DelaunayOptionsInit(mesh, userOptions, &options, &bbox) );

HXT_ASSERT(options.numVerticesInMesh+nToInsert <= mesh->vertices.num);

  hxtTetrahedraCompute(mesh, &options, nodeInfo, nToInsert, 1);
  return HXT_STATUS_OK;
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


// there could be multiple stuff to accelerate the predicate. first see if orient3D to 2 face is negative
// orient3D + orient3D with perpendicular at the vertex
// see if the distance is more than what the radius could be... visually, you can know
double tetInsphere(HXTMesh* mesh, const uint64_t curTet, const uint32_t vta){
  uint32_t* Node = mesh->tetrahedra.node + curTet;

  const double* __restrict__ a = mesh->vertices.coord + 4*Node[0];
  const double* __restrict__ b = mesh->vertices.coord + 4*Node[1];
  const double* __restrict__ c = mesh->vertices.coord + 4*Node[2];
  const double* __restrict__ e = mesh->vertices.coord + 4*vta;

  if(Node[3]==HXT_GHOST_VERTEX){ 
    double det = orient3d(a,b,c,e);

    if(det!=0.0){
      return det;
    }

    // we never go here, except when point are aligned on boundary
    // HXT_INFO("insphere using opposite vertex");
    uint32_t oppositeNode = mesh->tetrahedra.node[mesh->tetrahedra.neigh[curTet+3]];
    double* const __restrict__ oppositeVertex = mesh->vertices.coord + 4*oppositeNode;
    det = insphere(a,b,c,oppositeVertex,e);

    if (det == 0.0) {
      uint32_t nn[5] = {Node[0],Node[1],Node[2],oppositeNode,vta};
      // HXT_INFO("symbolic perturbation on boundary");
      det = symbolicPerturbation (nn, a,b,c,oppositeVertex,e);
      
    }
    return -det;
  }

  double* const __restrict__ d = mesh->vertices.coord + 4*Node[3];

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

static inline HXTStatus walking2Cavity(HXTMesh* mesh, TetLocal* local, uint64_t* __restrict__ curTet, const uint32_t vta){
  uint64_t nextTet = *curTet;

  /* if nextTet is a ghost triangle, go to the neighbor that is not a ghost triangle */
  if(mesh->tetrahedra.node[nextTet+3]==HXT_GHOST_VERTEX)
    nextTet = mesh->tetrahedra.neigh[nextTet+3]&NEIGH_H;

  double* const vtaCoord = mesh->vertices.coord + 4*vta;
  unsigned enteringFace = 4;

#ifdef DEBUG
  uint64_t TotalCount = 0;
#endif
  

  while(1){
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + nextTet;
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + nextTet;

    if (tetInsphere(mesh, nextTet, vta) > 0){
      *curTet = nextTet;
      return HXT_STATUS_OK;
    }
  #ifdef DEBUG
    else if(curNode[3]==HXT_GHOST_VERTEX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "walked outside of the domain");
    }
  #endif


    unsigned i;
    unsigned neigh=4;
    double Min = 0.0;
    for (i=0; i<4; i++)
    {
      // we walk where the volume is minimum
      const double* __restrict__ a = mesh->vertices.coord +4*curNode[(i+1)&3];
      const double* __restrict__ b = mesh->vertices.coord +4*curNode[(i&2)^3];
      const double* __restrict__ c = mesh->vertices.coord +4*curNode[(i+3)&2];
      
      if (i!=enteringFace) {
        double val = orient3d(a,b,c, vtaCoord);
        const uint32_t* __restrict__ neighNodes = mesh->tetrahedra.node + (curNeigh[i]&NEIGH_H);

        if (val < Min && checkTetrahedron((hxtVertex*) mesh->vertices.coord, local, neighNodes)==HXT_STATUS_OK){
          neigh = i;
          Min = val;
          //    break;
        }
      }
    }

    if(neigh==4){
      // if(tetInsphere(mesh, nextTet, vta) > 0){
      //   *curTet = nextTet;
      //   return HXT_STATUS_OK;
      // }
      return HXT_STATUS_TRYAGAIN;
    }

    //    printf("nextTet %u %g %u %u\n",nextTet,Min, count, neigh);
    nextTet = curNeigh[neigh]&NEIGH_H;
    enteringFace = curNeigh[neigh]&3;

    #ifdef DEBUG
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

/* pushing boundary information to local->bnd */
static inline void bndPush( TetLocal* local, const uint32_t vta, 
              const uint32_t node1, const uint32_t node2,
              const uint32_t node3, const uint64_t otherside){
  uint64_t n = local->numBnd;
  local->bnd[n].node[0] = vta;
  local->bnd[n].node[1] = node1;
  local->bnd[n].node[2] = node2;
  local->bnd[n].node[3] = node3;
  local->bnd[n].otherside = otherside;
  local->numBnd++;
}

static inline HXTStatus deletedPush(HXTMesh* mesh, TetLocal* local, const uint64_t neigh){
  // check if 3 points of the new tetrahedra are owned by this thread
  HXT_CHECK( checkTetrahedron((hxtVertex*) mesh->vertices.coord, local, mesh->tetrahedra.node + (neigh&NEIGH_H)) );

  local->deleted[local->numDeleted++] = neigh&NEIGH_H;
  local->vertices[local->numVertices++] = mesh->tetrahedra.node[neigh];

  return HXT_STATUS_OK;
}


//TODO: when applying colors, we need to verify that the cavity is convex... everytime !!
/* this function does a Breadth-first search of the tetrahedra in the cavity
 * it add those to local->deleted
 * it also maintain a local->bnd array with all the information concerning the boundary of the cavity
 */
static inline HXTStatus diggingACavity(HXTMesh* mesh, TetLocal* local, uint64_t curTet, const uint32_t vta, const uint16_t color){
  // add triangle to cavity
  uint64_t start;
  uint16_t* __restrict__ allColors = mesh->tetrahedra.colors;

  local->deleted[local->numDeleted++] = curTet;
  allColors[curTet>>2]=HXT_DELETED_COLOR;

  // add the vertices to the list
  local->vertices[0] = mesh->tetrahedra.node[curTet + 0];
  local->vertices[1] = mesh->tetrahedra.node[curTet + 1];
  local->vertices[2] = mesh->tetrahedra.node[curTet + 2];
  local->vertices[3] = mesh->tetrahedra.node[curTet + 3];
  local->numVertices = 4;
  local->numBnd = 0;

  

  for(start=local->numDeleted-1; start < local->numDeleted; start++){
    uint64_t curTet = local->deleted[start];
    const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + curTet;
    const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + curTet;
    

    /* here we allocate enough space for the boundary (local->bnd), the cavity (local->deleted) and the vertices (local->vertices) */
    HXT_CHECK( reserveNewDeleted(local, local->numDeleted+4) );
    HXT_CHECK( reserveNewBnd(local, local->numBnd+4) );
    HXT_CHECK( reserveNewVertices(local, local->numVertices+4) );

    // we unrolled the loop for speed (also because indices are not trivial, we would need a 4X4 array)

    /* and here we push stuff to local->bnd or local->deleted, always keeping ghost tet at last place */
    uint64_t neigh = curNeigh[0]>>2;
    if(allColors[neigh]!=HXT_DELETED_COLOR){
      if(
        // allColors[neigh] != color || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, vta, curNode[1], curNode[2], curNode[3], curNeigh[0]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, curNeigh[0]) );
        allColors[neigh] = HXT_DELETED_COLOR;
      }
    }

    neigh = curNeigh[1]>>2;
    if(allColors[neigh]!=HXT_DELETED_COLOR){
      if(
        // allColors[neigh] != color || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, vta, curNode[2], curNode[0], curNode[3], curNeigh[1]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, curNeigh[1]) );
        allColors[neigh] = HXT_DELETED_COLOR;
      }
    }

    neigh = curNeigh[2]>>2;
    if(allColors[neigh]!=HXT_DELETED_COLOR){
      if(
        // allColors[neigh] != color || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        bndPush(local, vta, curNode[0], curNode[1], curNode[3], curNeigh[2]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, curNeigh[2]) );
        allColors[neigh] = HXT_DELETED_COLOR;
      }
    }

    neigh = curNeigh[3]>>2;
    if(allColors[neigh]!=HXT_DELETED_COLOR){
      if(
        // allColors[neigh] != color || 
        tetInsphere(mesh, neigh*4, vta)<=0.0){
        // curNode[0] is the biggest, the smallest can be curNode[1] or curNode[2]
        // if(curNode[1]<curNode[2])
        //   bndPush(local, vta, curNode[0], curNode[2], curNode[1], curNeigh[3]);
        // else
          bndPush(local, vta, curNode[1], curNode[0], curNode[2], curNeigh[3]);
      }
      else{
        HXT_CHECK( deletedPush(mesh, local, curNeigh[3]) );
        allColors[neigh] = HXT_DELETED_COLOR;
      }
    }
  }

  return HXT_STATUS_OK;
}


/***********************************
 * filling back the cavity
 ***********************************/
// N+2 point on the surface of the cavity
// 2N triangle on the surface of the cavity, x3 (4*0.5+1) data = 6N+9 uint64_t
// => enough place for the 3N edge x2 data = 6N uint64_t
static inline HXTStatus computeAdjacenciesFast(HXTMesh* mesh, TetLocal* local, uint32_t* __restrict__ verticesID, const uint64_t start, const uint64_t blength){
  uint32_t* __restrict__ localVertices = local->vertices;

HXT_ASSERT(((size_t) verticesID)%SIMD_ALIGN==0);

  uint32_t i;
  #pragma omp simd aligned(verticesID,localVertices:SIMD_ALIGN)
  for (i=0; i<local->numVertices; i++){
    verticesID[localVertices[i]+1] = UINT32_MAX;
  }

  uint32_t npts = 0;
  for (i=0; i<local->numVertices; i++)
  {
    if(verticesID[localVertices[i]+1]>npts){
      // printf("vertice %u (located at %u in verticesID) has got number %u\n",localVertices[i],localVertices[i]+1, npts);
      verticesID[localVertices[i]+1] = npts++;
    }
  }

  HXT_ASSERT_MSG((npts-2)*2==blength, "Failed to compute adjacencies (f)");

  #pragma omp simd aligned(verticesID:SIMD_ALIGN)
  for (i=0; i<blength; i++)
  {
    local->Map[verticesID[local->bnd[i].node[1]+1]*32 + verticesID[local->bnd[i].node[2]+1]] = local->bnd[i].otherside + 3;
    local->Map[verticesID[local->bnd[i].node[2]+1]*32 + verticesID[local->bnd[i].node[3]+1]] = local->bnd[i].otherside + 1;
    local->Map[verticesID[local->bnd[i].node[3]+1]*32 + verticesID[local->bnd[i].node[1]+1]] = local->bnd[i].otherside + 2;
  }

  #pragma omp simd aligned(verticesID:SIMD_ALIGN)
  for (i=0; i<blength; i++)
  {
    mesh->tetrahedra.neigh[local->bnd[i].otherside + 1] = local->Map[verticesID[local->bnd[i].node[3]+1]*32 + verticesID[local->bnd[i].node[2]+1]];
    mesh->tetrahedra.neigh[local->bnd[i].otherside + 2] = local->Map[verticesID[local->bnd[i].node[1]+1]*32 + verticesID[local->bnd[i].node[3]+1]];
    mesh->tetrahedra.neigh[local->bnd[i].otherside + 3] = local->Map[verticesID[local->bnd[i].node[2]+1]*32 + verticesID[local->bnd[i].node[1]+1]];
  }

  return HXT_STATUS_OK;
}


static inline HXTStatus computeAdjacenciesSlow(HXTMesh* mesh, TetLocal* local, const uint64_t start, const uint64_t blength){

  uint64_t tlength = 0;
  const uint64_t middle = blength*3/2; // 3N

  uint64_t* Tmp = (uint64_t*) local->bnd; // we know there is enough space...
  const unsigned index[4] = {2,3,1,2};

  uint64_t i;
  for (i=0; i<blength; i++)
  {
    uint64_t curTet = local->deleted[start+ i];
    const uint32_t* __restrict__ Node = mesh->tetrahedra.node + curTet;

    // printf("===Node: %u %u %u %u\n",Node[0],Node[1],Node[2],Node[3]);

    // pointer to the position of Node[0] in the Tmp array
    uint64_t j;
    for (j=0; j<3; j++)
    {
      // define the edge by the minimum vertex and the other
      uint64_t key = ((uint64_t) Node[index[j]]<<32) + Node[index[j+1]];
      curTet++;

      // linear searching/pushing into Tmp
      uint64_t k;
      for (k=0; k<tlength; k++) // this is the only nested loop... the one that cost it all
      {
        __assume_aligned(Tmp, SIMD_ALIGN);
        if(Tmp[k]==key)
          break;
      }

      // we did not found it
      if(k==tlength){
        // printf("pushing key %lu=(%u<<32) + %u   (tet %lu, %lu = %lu)\n",key,Node[index[j]],Node[node[j+1]], curTet&NEIGH_H, j+1, curTet);
        Tmp[tlength] = (key>>32) + (key<<32);
        Tmp[middle + tlength] = curTet;
        tlength++;
      }
      else{// we found the neighbour !
        uint64_t pairValue = Tmp[middle+k];
        // printf("found key %lu (tet %lu, %lu = %lu) neigh:%lu\n",key, curTet&NEIGH_H, j+1, curTet, pairValue);
        mesh->tetrahedra.neigh[curTet] = pairValue;
        mesh->tetrahedra.neigh[pairValue] = curTet;
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


static inline HXTStatus fillingACavity(HXTMesh* mesh, TetLocal* local, uint32_t* __restrict__ verticesID, uint64_t* __restrict__ curTet, const uint16_t color){
  uint64_t clength = local->numDeleted;
  uint64_t blength = local->numBnd;

  uint64_t start = clength - blength;

  // #pragma vector aligned
  #pragma omp simd
  for (uint64_t i=0; i<blength; i++)
  {

    __assume_aligned(local->deleted, SIMD_ALIGN);
    __assume_aligned(local->bnd, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.colors, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.node, SIMD_ALIGN);
    __assume_aligned(mesh->tetrahedra.neigh, SIMD_ALIGN);

    const uint64_t newTet = local->deleted[i + start];
    uint32_t* __restrict__ Node = mesh->tetrahedra.node + newTet;
    mesh->tetrahedra.colors[newTet>>2] = color;

    /* we need to always put the ghost vertex at the fourth slot*/
    Node[0] = local->bnd[i].node[0];
    Node[1] = local->bnd[i].node[1];
    Node[2] = local->bnd[i].node[2];
    Node[3] = local->bnd[i].node[3];

    const uint64_t otherside = local->bnd[i].otherside;
    mesh->tetrahedra.neigh[newTet] = otherside;
    // update neighbor's neighbor
    mesh->tetrahedra.neigh[otherside] = newTet;

    // we recycle otherside to contain newTet (used in computeAdjacencies)
    local->bnd[i].otherside = newTet;
  }
#ifndef HXT_DELAUNAY_LOW_MEMORY
  if(blength<=60){ // N+2<=32 => N<=30 => 2N<=60
  #ifdef DEBUG
    HXT_CHECK( computeAdjacenciesFast(mesh, local, verticesID, start, blength) );
  #else
    computeAdjacenciesFast(mesh, local, verticesID, start, blength);
  #endif
  }
  else
#endif
  {
  #ifdef DEBUG
    HXT_CHECK(computeAdjacenciesSlow(mesh, local, start, blength) );
  #else
    computeAdjacenciesSlow(mesh, local, start, blength);
  #endif
  }

  *curTet = local->deleted[start];
  local->numDeleted = start;

  return HXT_STATUS_OK;
}


/**************************************************************************
 *                  VERIFYING A MESH                                      *
 **************************************************************************/
// static HXTStatus hxtTetrahedraVerifyInternal(HXTMesh* mesh, TetLocal* Locals, int nthreads)
// {
//   unsigned numErrors = 0;
//   if(mesh->tetrahedra.num > mesh->tetrahedra.size){
//     HXT_WARNING("number of tetrahedra exceed the size of the array");
//     numErrors++;
//   }
//   uint64_t i;
//   // #pragma omp parallel for
//   for (i=0; i<mesh->tetrahedra.num; i++)
//   {

//     uint32_t* Node = mesh->tetrahedra.node + i*4;
//     uint64_t* Neigh = mesh->tetrahedra.neigh + i*4;


//     int deleted = 0;
//     for (int threadID=0; threadID<nthreads; threadID++)
//     {
//       int thisDeleted = 0;
//       for (uint64_t j=0; j<Locals[threadID].numDeleted; j++)
//       {
//         if(i*4==Locals[threadID].deleted[j]){
//           thisDeleted++;
//         }
//       }

//       if(thisDeleted>0){
//         if(thisDeleted>1){
//           HXT_WARNING("tet. %lu is deleted multiple time in thread %d", i*4, threadID);
//           numErrors++;
//         }
//         deleted++;
//       }
//     }

//     if(deleted>0){
//       if(deleted>1){
//         HXT_WARNING("tet. %lu is deleted in mutliple threads",i*4);
//         numErrors++;
//       }

//       int flag = mesh->tetrahedra.colors[i] == HXT_DELETED_COLOR;
//       // verify that the flag is set according to the deleted stuff
//       if(flag!=deleted){
//         HXT_WARNING("tet. %lu 's flag say it is %sdeleted but it is %sin deleted list", i*4, (flag)?"":"not ", (deleted)?"":"not ");
//         numErrors++;
//       }

//       continue;
//     }

//     if(Node[0]>mesh->vertices.num || Node[1]>mesh->vertices.num || Node[2]>mesh->vertices.num
//       || (Node[3]!=HXT_GHOST_VERTEX && Node[3]>mesh->vertices.num)){
//       HXT_WARNING("ghost vertex at wrong place in tet. %lu (%u %u %u %u)", i*4, Node[0], Node[1], Node[2], Node[3]);
//       numErrors++;
//     }


//     double* a = mesh->vertices.coord + 4*Node[0];
//     double* b = mesh->vertices.coord + 4*Node[1];
//     double* c = mesh->vertices.coord + 4*Node[2];
//     double* d;
//     if(Node[3]!=HXT_GHOST_VERTEX)
//       d = mesh->vertices.coord + 4*Node[3];

//     if(Node[3]!=HXT_GHOST_VERTEX && orient3d(a,b,c,d)<0.0){
//       HXT_WARNING("orientation of tet %lu is wrong",i*4);
//       numErrors++;
//     }

//     // check the neighbors
//     unsigned j;
//     for (j=0; j<4; j++)
//     {
//       uint64_t neigh = Neigh[j];

//       // verify that neigh is not deleted
//       if(mesh->tetrahedra.colors[neigh/4] == HXT_DELETED_COLOR){
//         HXT_WARNING("tet %lu has got a deleted tet as its %uth neighbor", i*4, j);
//         numErrors++;
//       }

//       // uint64_t* NeighNeigh = mesh->tetrahedra.neigh + neigh;
//       uint32_t* NeighNode = mesh->tetrahedra.node + (neigh&NEIGH_H);

//       if(mesh->tetrahedra.neigh[neigh]!=i*4+j){
//         HXT_WARNING("tet %lu is not the neighbor of its %uth neighbor", i*4,j);
//         numErrors++;
//       }

//       uint32_t V[3] = { Node[((j+1)&3)], Node[((j&2)^3)], Node[((j+3)&2)]};
//       unsigned l;
//       for (l=0; l<3; l++)
//       {
//         if(NeighNode[(((neigh&3)+1)&3)]==V[l] && NeighNode[(((neigh&3)&2)^3)]==V[(l+2)%3] && NeighNode[(((neigh&3)+3)&2)]==V[(l+1)%3])
//            break;
//       }

//       if(l==3){
//         HXT_WARNING("neighbor %u of tet. %lu doesn't contain 3 common vertices",j,i*4);
//         numErrors++;
//       }

//       if(Node[j]==NeighNode[neigh&3]){
//         HXT_WARNING("neighbor %u of tet. %lu contain the same non-common vertex... (WTF?)");
//         numErrors++;
//       }

//       if(Node[3]!=HXT_GHOST_VERTEX && NeighNode[neigh&3]!=HXT_GHOST_VERTEX && insphere(mesh->vertices.coord + 4*Node[0],
//                   mesh->vertices.coord + 4*Node[1],
//                   mesh->vertices.coord + 4*Node[2],
//                   mesh->vertices.coord + 4*Node[3],
//                   mesh->vertices.coord + 4*NeighNode[neigh&3]].coord)>0.0){
//         HXT_WARNING("neighbor %u (%lu) of tet %lu has it's non-common node in the sphere (insphere(%u %u %u %u %u)=%.12g>0)",j, neigh, i*4, Node[0], Node[1], Node[2], Node[3], NeighNode[neigh&3],insphere(mesh->vertices.coord + 4*Node[0],
//                   mesh->vertices.coord + 4*Node[1],
//                   mesh->vertices.coord + 4*Node[2],
//                   mesh->vertices.coord + 4*Node[3],
//                   mesh->vertices.coord + 4*NeighNode[neigh&3]));
//         numErrors++;
//       }
//     }
//   }

//   if(numErrors){
//     return HXT_ERROR_MSG(HXT_STATUS_ERROR, "hxtTetrahedraVerifyInternal detected %d errors", numErrors);
//   }

//   return HXT_STATUS_OK;
// }

// HXTStatus hxtTetrahedraVerify(HXTMesh* mesh, TetLocal* local, int nthreads)
HXTStatus hxtTetrahedraVerify(HXTMesh* mesh)
{
  volatile int errorOccured = 0;

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
  {

    if(errorOccured)
      continue;

    uint32_t* Node = mesh->tetrahedra.node + i*4;
    uint64_t* Neigh = mesh->tetrahedra.neigh + i*4;

    if(mesh->tetrahedra.colors[i] == HXT_DELETED_COLOR)
      continue;

    // check for good placement of ghost vertex
    if(Node[0]==HXT_GHOST_VERTEX || Node[1]==HXT_GHOST_VERTEX || Node[2]==HXT_GHOST_VERTEX){
      HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost vertex at wrong place in tet. %lu", i*4);
      errorOccured=1;
      continue;
    }

    double* a = mesh->vertices.coord + 4*Node[0];
    double* b = mesh->vertices.coord + 4*Node[1];
    double* c = mesh->vertices.coord + 4*Node[2];

    // check for the orientation
    // if(Node[3]==0){
    //   HXT_WARNING("ghost tet. %lu remains in the array (did you clean the mesh?)",i*4);
    // }
    // else
    if(Node[3]!=HXT_GHOST_VERTEX && orient3d(a,b,c,mesh->vertices.coord + 4*Node[3])<0.0){
      HXT_ERROR_MSG(HXT_STATUS_ERROR, "orientation of tet %lu is wrong",i*4);
      errorOccured=1;
      continue;
    }

    // check the neighbors
    unsigned j;
    for (j=0; j<4; j++)
    {
      uint64_t neigh = Neigh[j];
      // uint64_t* NeighNeigh = mesh->tetrahedra.neigh + neigh;
      uint32_t* NeighNode = mesh->tetrahedra.node + (neigh&NEIGH_H);

      if(mesh->tetrahedra.neigh[neigh]!=i*4+j){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "tet %lu is not the neighbor of its %uth neighbor", i*4,j);
        errorOccured=1;
        continue;
      }

      uint32_t V[3] = { Node[((j+1)&3)], Node[((j&2)^3)], Node[((j+3)&2)]};
      unsigned l;
      for (l=0; l<3; l++)
      {
        if(NeighNode[(((neigh&3)+1)&3)]==V[l] && NeighNode[(((neigh&3)&2)^3)]==V[(l+2)%3] && NeighNode[(((neigh&3)+3)&2)]==V[(l+1)%3])
           break;
      }

      if(l==3){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet. %lu doesn't contain 3 common vertices",j,i*4);
        errorOccured=1;
        continue;
      }

      if(Node[3]!=HXT_GHOST_VERTEX && NeighNode[neigh&3]!=HXT_GHOST_VERTEX && insphere(mesh->vertices.coord + 4*Node[0],
                  mesh->vertices.coord + 4*Node[1],
                  mesh->vertices.coord + 4*Node[2],
                  mesh->vertices.coord + 4*Node[3],
                  mesh->vertices.coord + 4*NeighNode[neigh&3])>0.0){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "neighbor %u of tet %lu has it's non-common node in the sphere (insphere(%u %u %u %u %u)>0)",j,i*4, Node[0], Node[1], Node[2], Node[3], NeighNode[neigh&3]);
        errorOccured=1;
        continue;
      }
    }
  }

  if(errorOccured)
    return HXT_STATUS_ERROR;
  return HXT_STATUS_OK;
}
