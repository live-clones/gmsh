#include "hxt_tetOpti.h"
#include "hxt_tetFlag.h"
#include "hxt_edgeRemoval.h"
#include "hxt_smoothing.h"
#include "hxt_sort.h"
#include "HXTSPR.h"
#include "hxt_tetRepair.h"
#include "hxt_tetOptiDate.h"

#define SMALLEST_ROUND 1024

/**************************************************************************
                    Thread-shared structure
 **************************************************************************/
typedef struct {
  struct {
    HXTGroup2* array;
    uint64_t num;
    uint64_t size;
  } badTets;

  HXTTetDates date;
  HXTTetQualities quality;
  HXT2Sync toSync;

  int numThreads;
  uint32_t seed;
} ThreadShared;


/* Statistics about the mesh improvement.
 * Attempts and conflicts are per operation, so for smoothing and
 * edge-removal, there can be up to 6 E-R attempts and 4 Smoothing attempts
 * = 10 attempts (and maybe also conflict) per bad tetrahedra.
 * Success and failure are per bad tet.
 * Note that the number of `bad tet != failure + success`
 * because some bad tet gets eliminated by operations on other bad tets.
 * Also, some tets might cross partition boundary, in which case conflict
 * is guaranteed, therefore no operation are attempted and the tet does not
 * count in either success or failure */
typedef struct {
  uint64_t attempt;
  uint64_t conflict;
  uint64_t success; // cavity was modified, but there may still be a bad tet.
  uint64_t failure;
} Statistic;


typedef struct 
{
  // cavity for edge removal is a bipyramid
  HXTEdgeRemovalData* edgeRemoval;
  HXTSmoothingData* smoothing;
  HXTSPRData* SPR;

  // list of deleted tet. Added when the cavity is created, removed when the cavity is filled
  HXTDeleted deleted;
  HXTPartition partition;
  Statistic stat;
} ThreadLocal;


static void qualitySetDeleted(void** qualityArray_ptr, uint64_t a, uint64_t b)
{
  double* qualityArray = *qualityArray_ptr;

  for (uint64_t i=a; i<b; i++) {
    qualityArray[i] = DBL_MAX;
  }
}



/**************************************************************************
  create/update/delete shared structure, containing list of bad tetrahedra
 **************************************************************************/

// suppose that the right capacity for quality values is already allocated
static HXTStatus threadShared_update(HXTMesh* mesh, ThreadShared* shared) {
  int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;

  uint64_t* badTetsCount;
  HXT_CHECK( hxtMalloc(&badTetsCount, maxThreads*sizeof(uint64_t)) );

#ifndef __SANITIZE_ADDRESS__ // this portion does not seem to work with the address sanitizer of GCC 8 with OpenMP
  #pragma omp parallel
#endif
  {
    int threadID = omp_get_thread_num();
    badTetsCount[threadID] = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(!getProcessedFlag(mesh, i) && !getDeletedFlag(mesh, i) && shared->quality.values[i]<shared->quality.threshold)
        badTetsCount[threadID]++;
    }

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      shared->badTets.num = 0;
      for (int i=0; i<nthreads; i++) {
        uint64_t tsum = badTetsCount[i] + shared->badTets.num;
        badTetsCount[i] = shared->badTets.num;
        shared->badTets.num = tsum;
      }

      if(shared->badTets.num > shared->badTets.size) {
        hxtAlignedFree(&shared->badTets.array);
        hxtAlignedMalloc(&shared->badTets.array, sizeof(HXTGroup2)*shared->badTets.num);
        shared->badTets.size = shared->badTets.num;
      }
    }

    if(status==HXT_STATUS_OK){
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        if(!getProcessedFlag(mesh, i) && !getDeletedFlag(mesh, i) && shared->quality.values[i]<shared->quality.threshold){
          uint64_t badTetsID = badTetsCount[threadID]++;
          shared->badTets.array[badTetsID].v[1] = i;
        }
      }
    }
  }
  HXT_CHECK( hxtFree(&badTetsCount) );

  shared->toSync.threadFinished = 0;

  return status;
}

static HXTStatus threadShared_create(HXTMesh *mesh,
                                     HXTOptimizeOptions* options,
                                     ThreadShared** shared) {
  ThreadShared* newShared;
  HXT_CHECK( hxtMalloc(&newShared, sizeof(ThreadShared)));
  newShared->numThreads = options->numThreads;

  if(options->qualityMin<0.0)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "quality threshold must be positive");

  newShared->badTets.array = NULL;
  newShared->badTets.size = 0;
  newShared->badTets.num = 0;
  newShared->quality.function = options->qualityFun ? options->qualityFun : hxtTetAspectRatio;
  newShared->quality.threshold = options->qualityMin;
  newShared->quality.userData = options->qualityData;
  HXT_CHECK( hxtAlignedMalloc(&newShared->quality.values, sizeof(double)*mesh->tetrahedra.size) );

  newShared->date.current = 0;
  HXT_CHECK( hxtAlignedMalloc(&newShared->date.values, sizeof(HXTTetDate)*mesh->tetrahedra.size) );

  newShared->toSync = (HXT2Sync) {.mesh = mesh,
                                  .allocMore = 0,
                                  .otherArrays = {(void*) &newShared->quality.values,
                                                  (void*) &newShared->date.values, NULL, NULL},
                                  .otherArraysElementSize = {sizeof(double), sizeof(HXTTetDate), 0, 0},
                                  .otherArraysSetDeleted = {qualitySetDeleted, NULL, NULL, NULL},
                                  .threadFinished = 0};

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    newShared->date.values[i] = (HXTTetDate) {0};

    if(getProcessedFlag(mesh, i))
      newShared->quality.values[i] = DBL_MAX; // exterior tetrahedra have maximum quality
    else {
      uint32_t* nodes = mesh->tetrahedra.node + 4*i;
// #ifndef NDEBUG
      if(nodes[3]==HXT_GHOST_VERTEX){
        exit( HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost tetrahedra should have been set to processed") );
      }
// #endif
      newShared->quality.values[i] = tetQuality(mesh, &newShared->quality, nodes[0], nodes[1], nodes[2], nodes[3]);
    }
  }

  *shared = newShared;
  return HXT_STATUS_OK;
}

static HXTStatus threadShared_destroy(ThreadShared** shared) {
  HXT_CHECK( hxtAlignedFree(&(*shared)->quality.values) );
  HXT_CHECK( hxtAlignedFree(&(*shared)->date.values) );
  HXT_CHECK( hxtAlignedFree(&(*shared)->badTets.array));
  HXT_CHECK( hxtFree(shared) );
  return HXT_STATUS_OK;
}



/**************************************************************************
  create/update/delete local structure, containing partitions definition
 **************************************************************************/

static HXTStatus threadLocals_create(ThreadLocal** locals_ptr, HXTOptimizeOptions* options) {
  int nthreads = options->numThreads;
  ThreadLocal* newLocal;
  HXT_CHECK( hxtMalloc(&newLocal, nthreads*sizeof(ThreadLocal)));

  for (int threadID=0; threadID<nthreads; threadID++) {
    HXT_CHECK( hxtAlignedMalloc(&newLocal[threadID].deleted.array, sizeof(uint64_t)*DELETED_BUFFER_SIZE) );
    newLocal[threadID].deleted.size = DELETED_BUFFER_SIZE;
    newLocal[threadID].deleted.num = 0;
  }

  *locals_ptr = newLocal;
  return HXT_STATUS_OK;
}


static inline HXTStatus EdgeRemovalStructs_create(ThreadLocal* locals, ThreadShared* shared, int nThreads) {
  for (int threadID=0; threadID<nThreads; threadID++) {
    HXT_CHECK( hxtMalloc(&locals[threadID].edgeRemoval, sizeof(HXTEdgeRemovalData)) );
    locals[threadID].edgeRemoval->deleted = &locals[threadID].deleted;
    locals[threadID].edgeRemoval->partition = &locals[threadID].partition;
    locals[threadID].edgeRemoval->quality = &shared->quality;
    locals[threadID].edgeRemoval->date = &shared->date;
    locals[threadID].edgeRemoval->toSync = &shared->toSync;
  }
  return HXT_STATUS_OK;
}


static inline HXTStatus EdgeRemovalStructs_destroy(ThreadLocal* locals, int nThreads) {
  for (int threadID=0; threadID<nThreads; threadID++) {
    HXT_CHECK( hxtFree(&locals[threadID].edgeRemoval) );
  }
  return HXT_STATUS_OK;
}


static inline HXTStatus SmoothingStructs_create(ThreadLocal* locals, ThreadShared* shared,
                                                int nThreads, uint32_t numVerticesConstrained) {
  for (int threadID=0; threadID<nThreads; threadID++) {
    HXT_CHECK( hxtMalloc(&locals[threadID].smoothing, sizeof(HXTSmoothingData)) );
    locals[threadID].smoothing->mesh = shared->toSync.mesh;
    locals[threadID].smoothing->deleted = &locals[threadID].deleted;
    locals[threadID].smoothing->partition = &locals[threadID].partition;
    locals[threadID].smoothing->quality = &shared->quality;
    locals[threadID].smoothing->date = &shared->date;
    locals[threadID].smoothing->numVerticesConstrained = numVerticesConstrained;
  }
  return HXT_STATUS_OK;
}


static inline HXTStatus SmoothingStructs_destroy(ThreadLocal* locals, int nThreads) {
  for (int threadID=0; threadID<nThreads; threadID++) {
    HXT_CHECK( hxtFree(&locals[threadID].smoothing) );
  }
  return HXT_STATUS_OK;
}

// TODO: use a HHXTTetQualities in SPR...
static inline HXTStatus SPRStructs_create(ThreadLocal* locals, ThreadShared* shared,
                                          int nThreads) {
  for (int threadID=0; threadID<nThreads; threadID++) {
    HXT_CHECK( hxtMalloc(&locals[threadID].SPR, sizeof(HXTSPRData)) );
    locals[threadID].SPR->quality = &shared->quality;
    locals[threadID].SPR->date = &shared->date;
    locals[threadID].SPR->dateOfLastCheck = 0;
    locals[threadID].SPR->dateOfLastCreation = 0;
    locals[threadID].SPR->maxSearchNodes = 500;
    locals[threadID].SPR->deleted = &locals[threadID].deleted;
    locals[threadID].SPR->toSync = &shared->toSync;
    locals[threadID].SPR->partition = &locals[threadID].partition;
  }
  return HXT_STATUS_OK;
}


static inline HXTStatus SPRStructs_destroy(ThreadLocal* locals, HXTOptimizeOptions* options) {
  int nthreads = options->numThreads;
  for (int threadID=0; threadID<nthreads; threadID++) {
    HXT_CHECK( hxtFree(&locals[threadID].SPR) );
  }
  return HXT_STATUS_OK;
}

static Statistic threadLocals_collectStats(ThreadLocal* locals, int nThreads) {
      // check the stat to see if we keep the same number of threads and if we move partitions
  Statistic stat = {0,0,0,0};

  for (int threadID=0; threadID<nThreads; threadID++)
  {
    stat.attempt += locals[threadID].stat.attempt;
    stat.conflict += locals[threadID].stat.conflict;
    stat.success += locals[threadID].stat.success;
    stat.failure += locals[threadID].stat.failure;
  }
  return stat;
}

// this
static HXTStatus threadLocals_update(HXTMesh* mesh, HXTBbox* bbox,
                                     ThreadShared* shared, ThreadLocal* locals,
                                     uint32_t* seed, int changePartitions) {

  // initialize statistics
  for (int threadID=0; threadID<shared->numThreads; threadID++) {
    locals[threadID].stat = (Statistic) {0};
  }

  if(shared->numThreads>1) {
    HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
    HXTGroup2* badTets = shared->badTets.array;

    double indexShift = (double) hxtReproducibleLCG(seed)/RAND_MAX;

    if(changePartitions) {
      double hxtDeclareAligned bboxShift[3];

      bboxShift[0] = (double) hxtReproducibleLCG(seed)/RAND_MAX;
      bboxShift[1] = (double) hxtReproducibleLCG(seed)/RAND_MAX;
      bboxShift[2] = (double) hxtReproducibleLCG(seed)/RAND_MAX;

      HXT_CHECK( hxtMoore(bbox, vertices, mesh->vertices.num, bboxShift) );
    }

    #pragma omp parallel for simd aligned(badTets:SIMD_ALIGN)
    for (uint64_t i=0; i<shared->badTets.num; i++) {
      uint32_t firstNode = mesh->tetrahedra.node[4*badTets[i].v[1]];
      badTets[i].v[0] = vertices[firstNode].padding.hilbertDist;
    }

    // sort the bad tetrahedrons following their first node hilbert dist
    HXT_CHECK(  group2_sort_v0(badTets, shared->badTets.num, (UINT64_C(1)<<63) - 1) );

    if(badTets[0].v[0]==badTets[shared->badTets.num-1].v[0]) {
      // only one partition possible, everything is in the same cell !
      shared->numThreads = 1;
      locals[0].partition.startDist = 0;
      locals[0].partition.lengthDist = UINT64_MAX;
      locals[0].partition.firstElem = 0;
      locals[0].partition.numElem = shared->badTets.num;
      return HXT_STATUS_OK;
    }

    const double step = shared->badTets.num/shared->numThreads;

    #pragma omp parallel num_threads(shared->numThreads)
    {
      const int threadID = omp_get_thread_num();

      uint64_t first = MIN((uint64_t) step*(threadID+1)-1, (uint64_t) (step*(threadID + indexShift)));
      uint64_t startDist = badTets[first].v[0];

      uint64_t up = 1;
      while(first+up<shared->badTets.num && startDist==badTets[first + up].v[0])
        up++;

      first = first+up==shared->badTets.num?0:first+up;
      if(first > 0)
        startDist = (badTets[first].v[0] + badTets[first - 1].v[0] + 1)/2;
      else
        startDist = badTets[shared->badTets.num-1].v[0] + 
                   (badTets[first].v[0] - badTets[shared->badTets.num - 1].v[0])/2;

      locals[threadID].partition.firstElem = first;
      locals[threadID].partition.startDist = startDist;

      #pragma omp barrier

      uint64_t firstNext = locals[(threadID+1)%shared->numThreads].partition.firstElem;
      uint64_t endDist = locals[(threadID+1)%shared->numThreads].partition.startDist;
      locals[threadID].partition.numElem = (firstNext + shared->badTets.num - first)%shared->badTets.num;
      locals[threadID].partition.lengthDist = endDist - startDist;

      uint64_t rel = endDist - startDist;

      // dismiss tetrahedron that are in our list but not in our partition
      for (uint64_t i=0; i<locals[threadID].partition.numElem; i++) {
        uint64_t index = (locals[threadID].partition.firstElem + i)%shared->badTets.num;
        uint64_t curTet = shared->badTets.array[index].v[1];

        uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;

        if(vertexOutOfPartition(vertices, nodes[0], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[1], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[2], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[3], rel, startDist) > 1) {
          shared->badTets.array[index].v[1] = HXT_NO_ADJACENT;
          locals[threadID].stat.attempt++;
          locals[threadID].stat.conflict++;
        }
      }
    }
  }
  else {
    // TODO: when there is only one thread, we could sort bad tetrahedra from worst to best...
    locals[0].partition.startDist = 0;
    locals[0].partition.lengthDist = UINT64_MAX;
    locals[0].partition.firstElem = 0;
    locals[0].partition.numElem = shared->badTets.num;
  }

  return HXT_STATUS_OK;
}


static HXTStatus threadLocals_destroy(ThreadLocal** local, int nthreads) {
  for (int threadID=0; threadID<nthreads; threadID++) {
    HXT_CHECK( hxtAlignedFree(&(*local)[threadID].deleted.array) );
  }

  HXT_CHECK( hxtFree(local) );
  return HXT_STATUS_OK;
}


/* once the SPR is done, the current date should be changed to the date of the lastCheck */
static void SPRDates_update(ThreadShared* shared, ThreadLocal* locals)
{
  uint16_t lastCheck = 0;
  for(int threadID=0; threadID<shared->numThreads; threadID++) {
    if(locals[threadID].SPR->dateOfLastCheck > lastCheck)
      lastCheck = locals[threadID].SPR->dateOfLastCheck;
  }

  shared->date.current = lastCheck;

  for(int threadID=0; threadID<shared->numThreads; threadID++) {
    locals[threadID].SPR->dateOfLastCheck = lastCheck;
    locals[threadID].SPR->dateOfLastCreation = lastCheck;
  }
}


static double meanQuality(HXTMesh* mesh, double* quality) {
  double mean = 0;
  uint64_t ntet = 0;
  #pragma omp parallel for reduction(+:mean,ntet)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(quality[i]!=DBL_MAX){
      ntet++;
      mean += quality[i];
    }
  }
  mean/=ntet;
  return mean;
}


static double minQuality(HXTMesh* mesh, double* quality) {
  double min = DBL_MAX;

  #pragma omp parallel for reduction(min:min)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(quality[i]!=DBL_MAX)
      min = fmin(quality[i], min);
  }

  return min;
}


static uint64_t badTetrahedra(HXTMesh* mesh, double* quality, double threshold) {
  uint64_t count = 0;

  #pragma omp parallel for reduction(+:count)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
  {
    if(quality[i]<threshold)
      count++;
  }
  return count;
}


// TODO: some thing are seriously wrongly done
static inline void stage0_heuristic(Statistic stage0, Statistic stage1, uint64_t numBad,
                             int* numThreads, int* changePartitions) {
  if(numBad < (uint64_t) *numThreads*16) {
    *numThreads = MAX(1, numBad/16);
    // *changePartitions = 1;
  }

  if(stage0.attempt==0) // first time, we just return
    return;

  // too much conflict
  if(stage0.conflict>=stage0.attempt){
    // puts("too much conflict");
    *numThreads = 1;
    return;
  }

  // not enough success
  if(stage0.conflict > 10*stage0.success) {
    // int n = stage0.conflict / (10*stage0.success+1);
    // puts("not enough success");
    *numThreads = (*numThreads+1)/2;
    // *changePartitions = 1;
  }

  if(*numThreads>1)
    *changePartitions = 1;

  HXT_UNUSED(stage1);
}


static inline int continue_stage0(Statistic stage0, Statistic stage1) {
  HXT_UNUSED(stage1);

  return stage0.success>16 || stage0.conflict;
}


static inline void stage1_heuristic(Statistic stage0, Statistic stage1, uint64_t numBad,
                             int* numThreads) {
  if(numBad < (uint64_t) *numThreads*2) {
    *numThreads = MAX(1, numBad/2);
  }

  if(stage1.attempt==0) // first time, we just return
    return;

  if(stage1.attempt > 32*stage1.success) {
    *numThreads = (*numThreads+1)/2;
  }

  HXT_UNUSED(stage0);
}


static inline int continue_stage1(Statistic stage1) {
  return stage1.success || stage1.conflict;
}


/**************************************************************************
***************************************************************************

                    main function, optimizes a mesh

 **************************************************************************
 **************************************************************************/

HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh,
                                HXTOptimizeOptions* options){
  ThreadLocal* locals = NULL;
  ThreadShared* shared = NULL;
  volatile HXTStatus globalStatus = HXT_STATUS_OK;
  uint32_t seed = 1;
  
  if(options->numThreads<0)
    options->numThreads = omp_get_num_procs();
  else if(options->numThreads==0)
    options->numThreads = omp_get_max_threads();

  HXTBbox bbox;
  if(options->bbox==NULL) {
    hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);
  }
  else {
    bbox = *options->bbox;
  }

  HXT_CHECK( threadShared_create(mesh, options, &shared) );
  HXT_CHECK( threadLocals_create(&locals, options) );
  HXT_CHECK( EdgeRemovalStructs_create(locals, shared, options->numThreads));
  HXT_CHECK( SmoothingStructs_create(locals, shared, options->numThreads, options->numVerticesConstrained));
  HXT_CHECK( SPRStructs_create(locals, shared, options->numThreads) );

  int iter = 0;
  int SPRnumThreads = options->numThreads;
  Statistic stage0;
  Statistic stage1 = {0};

  do {
    HXT_INFO_COND(options->verbosity>0,
                  "Optimization stage %u.0: smoothing and edge removal", iter);

    int changePartitions = 1;
    shared->numThreads = options->numThreads;
    stage0 = (Statistic) {0};

    do {
      // double time00 = omp_get_wtime();
      // create a list of bad tets
      HXT_CHECK( threadShared_update(mesh, shared) );
      if(shared->badTets.num==0)
        break;

      stage0_heuristic(stage0, stage1, shared->badTets.num, &shared->numThreads, &changePartitions);

      // create partitions
      HXT_CHECK( threadLocals_update(mesh, &bbox, shared, locals, &seed, changePartitions) );

      HXT_INFO_COND(options->verbosity>0, "   "
                    HXTu64 " bad tetrahedra being optimized on %d threads",
                    shared->badTets.num, shared->numThreads);

      #pragma omp parallel num_threads(shared->numThreads)
      {
        const int threadID = omp_get_thread_num();
        ThreadLocal* local = locals + threadID;

        for (uint64_t i=0; i<local->partition.numElem && globalStatus==HXT_STATUS_OK; i++) {
          uint64_t index = (local->partition.firstElem + i)%shared->badTets.num;
          uint64_t curTet = shared->badTets.array[index].v[1];

          if(curTet==HXT_NO_ADJACENT || shared->quality.values[curTet]>= shared->quality.threshold)
            continue;

          HXTStatus status=HXT_STATUS_OK;
          for (int edge=0; edge<6; edge++) {
            unsigned facet0, facet1;
            getFacetsFromEdge(edge, &facet0, &facet1);

            local->stat.attempt++;
            status = hxtEdgeRemoval_opti(local->edgeRemoval, curTet, edge);
            if(status==HXT_STATUS_CONFLICT)
              local->stat.conflict++;
            else if(status==HXT_STATUS_OK){
              local->stat.success++;
              break;
            }
            else if(status>HXT_STATUS_INTERNAL) {
              // fatal error
              break;
            }
          }

          /*** make a swap whenever it is possible and it is an improvement ***/
          if(status<=HXT_STATUS_INTERNAL) {
            for (int vertex=0; vertex<4; vertex++) {
              local->stat.attempt++;
              status = hxtSmoothing(local->smoothing, 4*curTet+vertex);
              if(status==HXT_STATUS_CONFLICT)
                local->stat.conflict++;
              else if(status==HXT_STATUS_OK) {
                local->stat.success++;
                break;
              }
              else if(status>HXT_STATUS_INTERNAL) {
                // fatal error
                break;
              }
            }
          }

          if(status<=HXT_STATUS_INTERNAL) { // the cavity could not be modified
            local->stat.failure++;
            continue;
          }
          else if(status!=HXT_STATUS_OK) {
            #pragma omp atomic write
            globalStatus = status;
            break;
          }
        }

        HXTStatus status = waitForPossibleReallocation(&shared->toSync, shared->numThreads);
        if(status!=HXT_STATUS_OK) {
          #pragma omp atomic write
            globalStatus = status;
        }
      }

      if(globalStatus!=HXT_STATUS_OK){
        HXT_TRACE(globalStatus);
        return globalStatus;
      }

      stage0 = threadLocals_collectStats(locals, shared->numThreads);
      HXT_INFO_COND(options->verbosity>1, "   "
                    HXTu64 " attempts, " HXTu64 " modifications, " HXTu64 " conflict, " HXTu64 " failures",
                    stage0.attempt,      stage0.success,           stage0.conflict,     stage0.failure);
      // double time01 = omp_get_wtime();
      // printf("Smoothing & ER took %f s/tet,  %f modif/tet, %f conflict/attempt\n",
      //        (time01 - time00)/(stage0.success + stage0.failure),
      //        (double) stage0.success/(stage0.success + stage0.failure),
      //        (double) stage0.conflict/stage0.attempt);
    } while(continue_stage0(stage0, stage1));

    // if we exited previous loop, we need to exit this one again
    if(shared->badTets.num==0)
      break;

    // Now, one pass of SPR
    HXT_INFO_COND(options->verbosity>0,
                  "Optimization stage %u.1: small polyhedron reconnection", iter);

    // double time1 = omp_get_wtime();

    // create a list of bad tets
    HXT_CHECK( threadShared_update(mesh, shared) );
    if(shared->badTets.num==0)
      break;

    stage1_heuristic(stage0, stage1, shared->badTets.num, &SPRnumThreads);
    shared->numThreads = SPRnumThreads;
    changePartitions = 1;

    // create partitions
    HXT_CHECK( threadLocals_update(mesh, &bbox, shared, locals, &seed, changePartitions) );

    HXT_INFO_COND(options->verbosity>0, "   "
                  HXTu64 " bad tetrahedra being optimized on %d threads",
                  shared->badTets.num, shared->numThreads);

    #pragma omp parallel num_threads(shared->numThreads)
    {
      const int threadID = omp_get_thread_num();
      ThreadLocal* local = locals + threadID;

      for (uint64_t i=0; i<local->partition.numElem && globalStatus==HXT_STATUS_OK; i++) {
        uint64_t index = (local->partition.firstElem + i)%shared->badTets.num;
        uint64_t curTet = shared->badTets.array[index].v[1];

        if(curTet==HXT_NO_ADJACENT || shared->quality.values[curTet]>= shared->quality.threshold)
          continue;

        local->stat.attempt++;

        HXTStatus status = hxtSPR_opti(local->SPR, curTet);

        if(status==HXT_STATUS_CONFLICT){
          local->stat.conflict++;
          local->stat.failure++;
        }
        else if(status==HXT_STATUS_OK)
          local->stat.success++;
        else if(status==HXT_STATUS_INTERNAL)
          local->stat.failure++;
        else {
          // fatal error
          #pragma omp atomic write
          globalStatus = status;
          break;
        }

      //   // complete verification
      //   for (int threadID=0; threadID<options->numThreads; threadID++) {
      //     for (uint64_t i=0; i<locals[threadID].deleted.num; i++) {
      //       uint64_t delTet = locals[threadID].deleted.array[i];
      // #ifdef DEBUG
      //       if(!getDeletedFlag(mesh, delTet))
      //         return HXT_ERROR_MSG(HXT_STATUS_ERROR, "deleted flag not set on deleted tet");
      //       if(shared->quality.values[delTet]!=DBL_MAX)
      //         return HXT_ERROR_MSG(HXT_STATUS_ERROR, "quality of deleted tet %lu should have been set to DBL_MAX", delTet);
      // #endif
      //       for (int j=0; j<4; j++)
      //         mesh->tetrahedra.neigh[4*delTet+j] = HXT_NO_ADJACENT;
      //     }
      //   }

      //   HXT_CHECK( hxtRemoveDeleted(mesh) );
      //   local->deleted.num = 0;
      }
      
      HXTStatus status = waitForPossibleReallocation(&shared->toSync, shared->numThreads);
      if(status!=HXT_STATUS_OK) {
        #pragma omp atomic write
          globalStatus = status;
      }
    }

    if(globalStatus!=HXT_STATUS_OK){
      HXT_TRACE(globalStatus);
      return globalStatus;
    }

    SPRDates_update(shared, locals);

    stage1 = threadLocals_collectStats(locals, shared->numThreads);
    HXT_INFO_COND(options->verbosity>1, "   "
                  HXTu64 " attempts, " HXTu64 " modifications, " HXTu64 " conflict",
                  stage1.attempt,       stage1.success,           stage1.conflict);
    // double time2 = omp_get_wtime();
    // printf("SPR took %f s/tet,  %f modif/tet, %f conflict/attempt\n",
    //          (time2 - time1)/(stage1.success + stage1.failure),
    //          (double) stage1.success/(stage1.success + stage1.failure),
    //          (double) stage1.conflict/stage1.attempt);

    iter++;
  } while(continue_stage1(stage1));

  HXT_CHECK( SPRStructs_destroy(locals, options) );
  HXT_CHECK( EdgeRemovalStructs_destroy(locals, options->numThreads) );
  HXT_CHECK( SmoothingStructs_destroy(locals, options->numThreads) );

  HXT_INFO_COND(options->verbosity>0, "   "
                "\n\t" HXTu64" bad tet. | mean quality: %f | min quality: %f\n",
                badTetrahedra(mesh, shared->quality.values, shared->quality.threshold),
                meanQuality(mesh, shared->quality.values),
                minQuality(mesh, shared->quality.values));

  for (int threadID=0; threadID<options->numThreads; threadID++) {
    for (uint64_t i=0; i<locals[threadID].deleted.num; i++) {
      uint64_t delTet = locals[threadID].deleted.array[i];
#ifdef DEBUG
      if(!getDeletedFlag(mesh, delTet))
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "deleted flag not set on deleted tet");
      if(shared->quality.values[delTet]!=DBL_MAX)
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "quality of deleted tet should have been set to DBL_MAX");
#endif
      for (int j=0; j<4; j++)
        mesh->tetrahedra.neigh[4*delTet+j] = HXT_NO_ADJACENT;
    }
  }

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );
#endif

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  HXT_CHECK( threadLocals_destroy(&locals, options->numThreads) );
  HXT_CHECK( threadShared_destroy(&shared) );

  return HXT_STATUS_OK;
}

