// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetOpti.h"
#include "hxt_tetFlag.h"
#include "hxt_edgeRemoval.h"
#include "hxt_smoothing.h"
#include "HXTSPR.h"
#include "hxt_sort.h"
#include "hxt_tetRepair.h"
#include "hxt_tetOptiUtils.h"


static inline uint16_t getConflictFlag(HXTMesh* mesh, uint64_t tet) {
  return getUnusedFlag(mesh, tet, 0);
}


static inline void setConflictFlag(HXTMesh* mesh, uint64_t tet) {
  setUnusedFlag(mesh, tet, 0);
}


static inline void unsetConflictFlag(HXTMesh* mesh, uint64_t tet) {
  unsetUnusedFlag(mesh, tet, 0);
}

static void conflictFlagsInit(HXTMesh* mesh, HXTGroup2* badTets, uint64_t num) {
  #pragma omp parallel for simd
  for(uint64_t i=0; i<num; i++) {
    setConflictFlag(mesh, badTets[i].v[1]);
  }
}


/**************************************************************************
                    Thread-shared structure
 **************************************************************************/
typedef struct {
  struct {
    HXTGroup2* array;
    uint64_t num;
  } badTets;

  HXTTetDates date;
  HXTTetQualities quality;
  HXT2Sync toSync;

  int numThreads;
} ThreadShared;


/**************************************************************************
  create/update/delete shared structure, containing list of bad tetrahedra
 **************************************************************************/

// suppose that the right capacity for quality values is already allocated
static HXTStatus badTets_update(HXTMesh* mesh, ThreadShared* shared) {
  int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;

  uint64_t* badTetsCount;
  HXT_CHECK( hxtMalloc(&badTetsCount, maxThreads*sizeof(uint64_t)) );

  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    badTetsCount[threadID] = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(!getProcessedFlag(mesh, i) &&
         !getDeletedFlag(mesh, i) &&
         shared->quality.values[i]<shared->quality.threshold)
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

      status = hxtAlignedFree(&shared->badTets.array);
      if(status==HXT_STATUS_OK)
        status = hxtAlignedMalloc(&shared->badTets.array, sizeof(HXTGroup2)*shared->badTets.num);
    }

    if(status==HXT_STATUS_OK){
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        if(!getProcessedFlag(mesh, i) &&
           !getDeletedFlag(mesh, i) &&
           shared->quality.values[i]<shared->quality.threshold){
          uint64_t badTetsID = badTetsCount[threadID]++;
          shared->badTets.array[badTetsID].v[1] = i;
        }
      }
    }
  }
  HXT_CHECK( hxtFree(&badTetsCount) );

  return status;
}


static HXTStatus badTets_update_among_conflicts(HXTMesh* mesh, ThreadShared* shared) {
  int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;

  uint64_t* badTetsCount;
  HXT_CHECK( hxtMalloc(&badTetsCount, maxThreads*sizeof(uint64_t)) );

  uint64_t oldBadTetNum = shared->badTets.num;
  HXTGroup2* oldBadTets = shared->badTets.array;

  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    badTetsCount[threadID] = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<oldBadTetNum; i++) {
      if(getConflictFlag(mesh, oldBadTets[i].v[1]) && !getDeletedFlag(mesh, oldBadTets[i].v[1]))
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

      status = hxtAlignedMalloc(&shared->badTets.array, sizeof(HXTGroup2)*shared->badTets.num);
    }

    if(status==HXT_STATUS_OK){
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<oldBadTetNum; i++) {
        if(getConflictFlag(mesh, oldBadTets[i].v[1]) && !getDeletedFlag(mesh, oldBadTets[i].v[1])) {
          uint64_t badTetsID = badTetsCount[threadID]++;
          shared->badTets.array[badTetsID] = oldBadTets[i];
        }
      }
    }
  }
  HXT_CHECK( hxtFree(&badTetsCount) );
  HXT_CHECK( hxtAlignedFree(&oldBadTets) );

  return status;
}


static HXTStatus threadShared_init(HXTMesh *mesh,
                                     HXTOptimizeOptions* options,
                                     ThreadShared* shared) {
  shared->numThreads = options->numThreads;

  if(options->qualityMin<0.0)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "quality threshold must be positive");

  shared->badTets.array = NULL;
  shared->badTets.num = mesh->tetrahedra.num;
  shared->quality.function = options->qualityFun ? options->qualityFun : hxtTetAspectRatio;
  shared->quality.threshold = options->qualityMin;
  shared->quality.userData = options->qualityData;
  HXT_CHECK( hxtAlignedMalloc(&shared->quality.values, sizeof(double)*mesh->tetrahedra.size) );

  shared->date.current = 0;
  HXT_CHECK( hxtAlignedMalloc(&shared->date.values, sizeof(HXTTetDate)*mesh->tetrahedra.size) );

  shared->toSync = (HXT2Sync) {.mesh = mesh,
                               .allocMore = 0,
                               .otherArrays = {(void*) &shared->quality.values,
                                               (void*) &shared->date.values, NULL, NULL},
                               .otherArraysElementSize = {sizeof(double), sizeof(HXTTetDate), 0, 0},
                               .otherArraysSetDeleted = {NULL, NULL, NULL, NULL},
                               .threadFinished = 0};

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    shared->date.values[i] = (HXTTetDate) {0};

    if(!getProcessedFlag(mesh, i)) {
      uint32_t* nodes = mesh->tetrahedra.node + 4*i;
// #ifndef NDEBUG
      if(nodes[3]==HXT_GHOST_VERTEX){
        exit( HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost tetrahedra should have been set to processed") );
      }
// #endif
      shared->quality.values[i] = tetQuality(mesh, &shared->quality, nodes[0], nodes[1], nodes[2], nodes[3]);
    }
  }
  return HXT_STATUS_OK;
}


static HXTStatus threadShared_destroy(ThreadShared* shared) {
  HXT_CHECK( hxtAlignedFree(&shared->quality.values) );
  HXT_CHECK( hxtAlignedFree(&shared->date.values) );
  HXT_CHECK( hxtAlignedFree(&shared->badTets.array));
  return HXT_STATUS_OK;
}


static HXTStatus reorderTetIfNeeded(HXTMesh* mesh, ThreadLocal* locals, int nThreads)
{
  int createdNew = 0;
  for(int i=0; i<nThreads; i++) {
    if(locals[i].deleted.createdNew)
      createdNew++;
  }

  if(createdNew > 1) {
    HXT_INFO("reordering tetrahedra to ensure reproducibility (reproducible==true)");
    HXT_CHECK( hxtTetReorder(mesh) );
  }

  for(int i=0; i<nThreads; i++) {
    locals[i].deleted.createdNew = 0;
  }

  return HXT_STATUS_OK;
}



/**************************************************************************
  create/update/delete local structure, containing partitions definition
 **************************************************************************/

static HXTStatus threadLocals_create(ThreadLocal** locals_ptr, ThreadShared* shared, HXTOptimizeOptions* options) {
  int nthreads = options->numThreads;
  ThreadLocal* newLocal;
  HXT_CHECK( hxtMalloc(&newLocal, nthreads*sizeof(ThreadLocal)));

  for (int threadID=0; threadID<nthreads; threadID++) {
    HXT_CHECK( hxtAlignedMalloc(&newLocal[threadID].deleted.array, sizeof(uint64_t)*DELETED_BUFFER_SIZE) );
    // init deleted
    newLocal[threadID].deleted.size = DELETED_BUFFER_SIZE;
    newLocal[threadID].deleted.num = 0;
    newLocal[threadID].deleted.createdNew = 0;

    // partition is initialized in threadLocals_update

    // statistics are also initialize in threadLocals_update

    newLocal[threadID].quality = &shared->quality;
    newLocal[threadID].date = &shared->date;
    newLocal[threadID].toSync = &shared->toSync;
    newLocal[threadID].numVerticesConstrained = options->numVerticesConstrained;
    newLocal[threadID].SPR.dateOfLastCheck = 0;
    newLocal[threadID].SPR.dateOfLastCreation = 0;
    newLocal[threadID].SPR.maxSearchNodes = 500;
  }

  *locals_ptr = newLocal;
  return HXT_STATUS_OK;
}


static Statistic threadLocals_collectStats(ThreadLocal* locals, int nThreads) {
      // check the stat to see if we keep the same number of threads and if we move partitions
  Statistic stat = {0};

  for (int threadID=0; threadID<nThreads; threadID++)
  {
    stat.attempt += locals[threadID].stat.attempt;
    stat.conflict += locals[threadID].stat.conflict;
    stat.success += locals[threadID].stat.success;
  }
  return stat;
}


static HXTStatus threadLocals_update(HXTMesh* mesh, HXTBbox* bbox,
                                     ThreadShared* shared, ThreadLocal* locals,
                                     uint32_t* seed,
                                     int changePartitionCurve,
                                     int badTetAlreadySorted)
{
  const uint64_t bit63 = UINT64_C(1)<<63;
  #pragma omp parallel for simd
  for(uint64_t i=0; i<shared->badTets.num; i++) {
    shared->badTets.array[i].v[0] &= ~bit63;
  }


  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  HXTGroup2* badTets = shared->badTets.array;

  double indexShift = hxtLCGf64(seed);

  if(changePartitionCurve) {
    double hxtDeclareAligned bboxShift[3];
    bboxShift[0] = hxtLCGf64(seed);
    bboxShift[1] = hxtLCGf64(seed);
    bboxShift[2] = hxtLCGf64(seed);

    HXT_CHECK( hxtMoore(bbox, vertices, mesh->vertices.num, bboxShift) );
  }

  if(changePartitionCurve || !badTetAlreadySorted) {
    #pragma omp parallel for simd aligned(badTets:SIMD_ALIGN)
    for (uint64_t i=0; i<shared->badTets.num; i++) {
      uint64_t curTet = badTets[i].v[1];
      uint32_t* nodes = &mesh->tetrahedra.node[4*curTet];
      uint64_t hilbertDist[4];
      for(int j=0; j<4; j++) {
        hilbertDist[j] = vertices[nodes[j]].padding.hilbertDist;
      }

      HXTSORT_4_VALUES_INPLACE(uint64_t, hilbertDist);

      uint64_t minDist = UINT64_MAX;
      uint64_t middle = 0;
      for(int j=0; j<4; j++) {
        if(hilbertDist[(j+1)%4] - hilbertDist[j] < minDist) {
          minDist = hilbertDist[(j+1)%4] - hilbertDist[j];
          middle = hilbertDist[j] + minDist/2;
        }
      }

      // we are going to sort the four values
      badTets[i].v[0] = middle;
    }

    // sort the bad tetrahedrons following their first node hilbert dist
    HXT_CHECK(  group2_sort_v0(badTets, shared->badTets.num, bit63 - 1) );
  }

  if(shared->numThreads==1 || badTets[0].v[0]==badTets[shared->badTets.num-1].v[0]) {
    // only one partition possible, everything is in the same cell !
    shared->numThreads = 1;
    locals[0].partition.startDist = 0;
    locals[0].partition.lengthDist = UINT64_MAX;
    locals[0].partition.firstElem = 0;
    locals[0].partition.numElem = shared->badTets.num;
    locals[0].stat = (Statistic) {0};
    return HXT_STATUS_OK;
  }

  if(shared->numThreads > 1) {
    const double step = shared->badTets.num/shared->numThreads;
    #pragma omp parallel num_threads(shared->numThreads)
    {
      int threadID = omp_get_thread_num();
      locals[threadID].stat = (Statistic) {0};

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
      uint64_t numElem = (firstNext + shared->badTets.num - first)%shared->badTets.num;
      locals[threadID].partition.numElem = numElem;
      locals[threadID].partition.lengthDist = endDist - startDist;

      uint64_t rel = endDist - startDist;

      // dismiss tetrahedron that are in our list but not in our partition
      for (uint64_t i=0; i<numElem; i++) {
        uint64_t index = (first + i)%shared->badTets.num;
        uint64_t curTet = shared->badTets.array[index].v[1];

        uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;

        if(vertexOutOfPartition(vertices, nodes[0], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[1], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[2], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[3], rel, startDist) > 1) {
          shared->badTets.array[index].v[0] |= bit63;
          locals[threadID].stat.attempt++;
          locals[threadID].stat.conflict++;
        }
      }
    }
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
    if(locals[threadID].SPR.dateOfLastCheck > lastCheck)
      lastCheck = locals[threadID].SPR.dateOfLastCheck;
  }

  shared->date.current = lastCheck;

  for(int threadID=0; threadID<shared->numThreads; threadID++) {
    locals[threadID].SPR.dateOfLastCheck = lastCheck;
    locals[threadID].SPR.dateOfLastCreation = lastCheck;
  }
}


static void badTetrahedraStat(HXTMesh* mesh, double* quality, double threshold,
                              uint64_t* badTetNum,
                              double* meanQuality,
                              double* minQuality)
{
  uint64_t good = 0;
  uint64_t bad = 0;
  double sum = 0.0;
  double min = DBL_MAX;

  #pragma omp parallel for reduction(+: good, bad, sum) reduction(min:min)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
  {
    if(getDeletedFlag(mesh, i) || getProcessedFlag(mesh, i))
      continue;

    sum += quality[i];

    if(quality[i]<threshold)
      bad++;
    else
      good++;

    if(quality[i]<min)
      min = quality[i];
  }
  
  *badTetNum = bad;
  *meanQuality = sum / (good + bad);
  *minQuality = min;
}


/**************************************************************************
***************************************************************************

                    main function, optimizes a mesh

 **************************************************************************
 **************************************************************************/

HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh,
                                HXTOptimizeOptions* options)
{
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


  ThreadShared shared;
  HXT_CHECK( threadShared_init(mesh, options, &shared) );

  ThreadLocal* locals = NULL;
  HXT_CHECK( threadLocals_create(&locals, &shared, options) );

  HXT_CHECK( hxtMoore(&bbox, (HXTVertex*) mesh->vertices.coord, mesh->vertices.num, NULL) );


  int doSPR = 1;
  double conflictRatio = 0.0;

  uint64_t roundModifIn = UINT64_MAX;
  uint64_t roundModifOut = UINT64_MAX;
  // uint64_t roundBadTetOut = UINT64_MAX;

  uint64_t maxBadTetIn = 0;
  uint64_t roundBadTetIn = UINT64_MAX;
  double lastSPRModifRatio = 0.95;

  int changePartitionCurve = 0;
  int badTetAlreadySorted = 0;
  
  uint32_t seed = 1;
  volatile HXTStatus globalStatus = HXT_STATUS_OK;
  
  while(1) {
    /**************************************************************************
     * Choosing the number of threads and the method that we are going to use
     **************************************************************************/
    if(conflictRatio==0.0 || shared.badTets.num==0) {
      HXT_CHECK( badTets_update(mesh, &shared) );

      if(shared.badTets.num > maxBadTetIn)
        maxBadTetIn = shared.badTets.num;

      conflictFlagsInit(mesh, shared.badTets.array, shared.badTets.num);
      if(roundModifOut==0 || shared.badTets.num==0 ||
         (maxBadTetIn - roundBadTetIn > 1000 * roundModifOut && roundBadTetIn > 1000 * roundModifOut))
        break;

      double lastModifRatio = (double) roundModifIn/roundBadTetIn;
      if(doSPR) {
        lastSPRModifRatio = lastModifRatio;
        doSPR = 0;
        roundModifOut = 0;
        // roundBadTetOut = shared.badTets.num;
      }
      else if(200.0 * lastModifRatio <= lastSPRModifRatio*lastSPRModifRatio*0.75 + lastSPRModifRatio*0.1 + 0.1) {
        doSPR = 1;
        roundModifOut = 0;
        // roundBadTetOut = shared.badTets.num;
      }
      roundModifIn = 0;
      roundBadTetIn = shared.badTets.num;
      changePartitionCurve = 0;
      badTetAlreadySorted = 0;
      conflictRatio = 0.0;
      shared.numThreads = options->numThreads;

      HXT_INFO_COND(options->verbosity>0,
                    "Improving %10" HXTu64 " tet. on %3d thrd %s",
                    roundBadTetIn, shared.numThreads, doSPR ? "(GSC)":"(S & ER)");
    }
    else {
      HXT_CHECK( badTets_update_among_conflicts(mesh, &shared) );

      badTetAlreadySorted = 1; // because badTets_update_among_conflicts is stable
      if((conflictRatio>0.6 || (doSPR && conflictRatio>0.2)) && shared.numThreads!=1)
        changePartitionCurve = 1;
      else
        changePartitionCurve = 0;
    }

    shared.numThreads = computeNumberOfThreads(conflictRatio,
                                               shared.numThreads,
                                               shared.badTets.num,
                                               doSPR ? 8 : 128);

    shared.toSync.threadFinished = 0;

    // create partitions
    HXT_CHECK( threadLocals_update(mesh, &bbox, &shared, locals, &seed,
                                   changePartitionCurve, badTetAlreadySorted) );

    #pragma omp parallel num_threads(shared.numThreads)
    {
      int threadID = omp_get_thread_num();
      ThreadLocal* local = &locals[threadID];
      const uint64_t numElem = local->partition.numElem;
      const uint64_t first = local->partition.firstElem;

      for (uint64_t i=0; i<numElem && globalStatus==HXT_STATUS_OK; i++) {
        uint64_t index = (first + i)%shared.badTets.num;
        uint64_t curTet = shared.badTets.array[index].v[1];

        if(shared.badTets.array[index].v[0] & (UINT64_C(1)<<63) || !getConflictFlag(mesh, curTet) || getDeletedFlag(mesh, curTet))
          continue;

        HXTStatus status = HXT_STATUS_OK;
        local->stat.attempt++;

        if(!doSPR) {
          int conflict = 0;
          for (int edge=0; edge<6; edge++) {
            unsigned facet0, facet1;
            getFacetsFromEdge(edge, &facet0, &facet1);

            status = hxtEdgeRemoval_opti(local, curTet, edge);
            if(status==HXT_STATUS_CONFLICT)
              conflict = 1;
            else if(status==HXT_STATUS_OK){
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
              status = hxtSmoothing(local, 4*curTet+vertex);
              if(status==HXT_STATUS_CONFLICT)
                conflict = 1;
              else if(status==HXT_STATUS_OK) {
                break;
              }
              else if(status>HXT_STATUS_INTERNAL) {
                // fatal error
                break;
              }
            }
          }

          if(status==HXT_STATUS_INTERNAL && conflict)
            status = HXT_STATUS_CONFLICT;
        }
        else {
          status = hxtSPR_opti(local, curTet);
        }

        if(status==HXT_STATUS_CONFLICT)
          local->stat.conflict++;
        else if(status==HXT_STATUS_OK)
          local->stat.success++;
        else if(status<=HXT_STATUS_INTERNAL)// the cavity could not be modified
          unsetConflictFlag(mesh, curTet);
        else {
          // fatal error
          #pragma omp atomic write
          globalStatus = status;
          break;
        }
      }

      HXTStatus status = waitForPossibleReallocation(&shared.toSync, shared.numThreads);
      if(status!=HXT_STATUS_OK) {
        #pragma omp atomic write
          globalStatus = status;
      }
    } // end of parallel section

    if(globalStatus!=HXT_STATUS_OK){
      HXT_TRACE(globalStatus);
      return globalStatus;
    }

    if(doSPR)
      SPRDates_update(&shared, locals);

    if(options->reproducible) {
      HXT_CHECK( reorderTetIfNeeded(mesh, locals, shared.numThreads) );
    }

    Statistic stat = threadLocals_collectStats(locals, shared.numThreads);
    HXT_INFO_COND(options->verbosity>1,
                  "%3d thrd |%10" HXTu64 "/%-10" HXTu64 " %" HXTu64 " conflicts",
                  shared.numThreads, stat.success, stat.attempt, stat.conflict);

    roundModifIn += stat.success;
    roundModifOut += stat.success;
    conflictRatio = (stat.attempt==0) ? 0 : (double) stat.conflict / stat.attempt;
  }


  if(options->verbosity>1) {
    
    uint64_t badTetNum;
    double meanQuality;
    double minQuality;
    badTetrahedraStat(mesh, shared.quality.values, shared.quality.threshold,
                      &badTetNum, &meanQuality, &minQuality);

    HXT_INFO("%" HXTu64 " bad tet. | mean quality: %g | min quality: %g",
            badTetNum, meanQuality, minQuality);
  }


  for (int threadID=0; threadID<options->numThreads; threadID++) {
    for (uint64_t i=0; i<locals[threadID].deleted.num; i++) {
      uint64_t delTet = locals[threadID].deleted.array[i];
#ifdef DEBUG
      if(!getDeletedFlag(mesh, delTet))
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "deleted flag not set on deleted tet");
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

