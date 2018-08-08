#include "hxt_sort.h"
#include "hxt_tetFlag.h"


static inline void sort3ints(uint32_t i[3]){
  if(i[0]>i[1]){
    uint32_t tmp = i[0]; i[0] = i[1]; i[1] = tmp;
  }

  if(i[1]>i[2]){
    uint32_t tmp = i[1]; i[1] = i[2]; i[2] = tmp;

    if(i[0]>i[1]){
      uint32_t tmp = i[0]; i[0] = i[1]; i[1] = tmp;
    }
  }
}
// just a function such that:
// if hashedCompare(a,b)==true
// then hashedCompare(b,a)==false
//
// BUT hashedCompare(a,b)==true and hashedCompare(b,c)==true
// doesn't imply that hashedCompare(a,c)==true
// and inversely if you replace true with false (no transitivity)
static inline uint64_t hashedCompare(uint64_t a, uint64_t b) {
  return ((a^b)&1)^(a<b);
}


static inline uint64_t hash64(uint64_t x) {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
}


// just a function such that:
// if transitiveHashedCmp(a,b)==true
// then transitiveHashedCmp(b,a)==false
//
// AND transitiveHashedCmp(a,b)==true and transitiveHashedCmp(b,c)==true
// imply that transitiveHashedCmp(a,c)==true
// and inversely if you replace true with false (the relation is transitive)
static inline uint64_t transitiveHashedCmp(uint64_t a, uint64_t b) {
  return hash64(a) < hash64(b);
}


static HXTStatus hxtEdgesNotInTriangles(HXTMesh* mesh, uint32_t* lines, uint64_t* numLines, uint64_t* threadCount, const uint64_t n) {
  HXTGroup2* edgeKey = NULL;

  uint64_t numEdgesTotal = mesh->triangles.num*3+mesh->lines.num;
  HXT_CHECK( hxtAlignedMalloc(&edgeKey, numEdgesTotal*sizeof(HXTGroup2)) );

  #pragma omp parallel
  {
    #pragma omp for nowait
    for (uint64_t i=0; i<mesh->lines.num; i++) {
      if(mesh->lines.node[2*i]<mesh->lines.node[2*i+1]) {
        edgeKey[i].v[0] = mesh->lines.node[2*i]*n + mesh->lines.node[2*i+1];
        edgeKey[i].v[1] = 0;
      }
      else if(mesh->lines.node[2*i]<mesh->lines.node[2*i+1]){
        edgeKey[i].v[0] = mesh->lines.node[2*i+1]*n + mesh->lines.node[2*i];
        edgeKey[i].v[1] = 0;
      }
      else {
        edgeKey[i].v[0] = mesh->lines.node[2*i]*n + mesh->lines.node[2*i]; // the line begins and ends at the same point...
        edgeKey[i].v[1] = 1;
      }
    }

    #pragma omp for nowait
    for (uint64_t i=0; i<mesh->triangles.num; i++) {
      uint32_t v[3] = {mesh->triangles.node[3*i+0],
                       mesh->triangles.node[3*i+1],
                       mesh->triangles.node[3*i+2]};

      sort3ints(v);

      edgeKey[mesh->lines.num+3*i].v[0] = v[0]*n + v[1];
      edgeKey[mesh->lines.num+3*i].v[1] = 1;
      edgeKey[mesh->lines.num+3*i+1].v[0] = v[0]*n + v[2];
      edgeKey[mesh->lines.num+3*i+1].v[1] = 1;
      edgeKey[mesh->lines.num+3*i+2].v[0] = v[1]*n + v[2];
      edgeKey[mesh->lines.num+3*i+2].v[1] = 1;
    }
  }

  group2_sort_v0(edgeKey, numEdgesTotal, n*(n-1)-1);

  uint64_t total = 0;

  // TODO: filter all edge (the sort is stable... maybe put triangles before lines :p)
  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<numEdgesTotal; i++) {
      if(edgeKey[i].v[1]==0) {
        if(i==numEdgesTotal-1 || edgeKey[i].v[0] != edgeKey[i+1].v[0])
          localNum++;
        else
          edgeKey[i].v[1]=1;
      }
    }

    threadCount[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      for (int i=0; i<nthreads; i++) {
        uint32_t tsum = total + threadCount[i];
        threadCount[i] = total;
        total = tsum;
      }
    }

    localNum = threadCount[threadID];
    if(total) {
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<numEdgesTotal; i++) {
        if(edgeKey[i].v[1]==0) {
          lines[2*localNum] = edgeKey[i].v[0]%n;
          lines[2*localNum+1] = edgeKey[i].v[0]/n;
          localNum++;
        }
      }
    }
  }

  *numLines = total;

  HXT_CHECK( hxtAlignedFree(&edgeKey) );

  return HXT_STATUS_OK;
}


/********************************************************************************
 *  report the number of missing edges or set tet.flag for constrained edges    *
 ********************************************************************************/
// every tetrahedra must have a neighbor HXT_NO_ADJACENT is NOT permitted !!!
HXTStatus hxtConstrainEdgesNotInTriangles(HXTMesh* mesh, uint64_t* missing) {
  const int nodeArray[4][4] = {{-1, 2, 3, 1},
                               { 3,-1, 0, 2},
                               { 1, 3,-1, 0},
                               { 2, 0, 1,-1}};

  const int facetToNumber[4][4] = {{-1, 0, 1, 2},
                                   { 0,-1, 3, 4},
                                   { 1, 3,-1, 5},
                                   { 2, 4, 5,-1}};


  const int numberToFacetMin[] = { 0, 0, 0, 1, 1, 2};
  const int numberToFacetMax[] = { 1, 2, 3, 2, 3, 3};

  const uint64_t n = mesh->vertices.num;
  uint64_t* numEdges;
  uint32_t* lines;
  uint64_t numLines;
  int maxThreads = omp_get_max_threads();
  HXT_CHECK( hxtMalloc(&numEdges, maxThreads*sizeof(uint64_t)) );
  HXT_CHECK( hxtAlignedMalloc(&lines, mesh->lines.num*2*sizeof(uint32_t)) );
  
  // we don't wont to constrain edge that are already in a triangle
  HXT_CHECK( hxtEdgesNotInTriangles(mesh, lines, &numLines, numEdges, n) );

  if(numLines==0) {
    HXT_CHECK( hxtAlignedFree(&lines) );
    HXT_CHECK( hxtFree(&numEdges) );
    return HXT_STATUS_OK;
  }

  HXTGroup2* edgeKey = NULL;
  uint64_t numEdgesTotal = 0;
  HXTStatus status = HXT_STATUS_OK;

  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) { // for each tetrahedra
      for (int j=0; j<4; j++) {
        for (int k=j+1; k<4; k++) {
          int in_facet = j;
          int out_facet = k;

          uint32_t p0 = mesh->tetrahedra.node[4*i + nodeArray[j][k]];
          uint32_t p1 = mesh->tetrahedra.node[4*i + nodeArray[k][j]];

          if(p0==HXT_GHOST_VERTEX || p1==HXT_GHOST_VERTEX)
            continue;

          int truth = 1;

          uint64_t curTet = i;
          do
          {
            uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

            // go into the neighbor through out_facet
            uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
            curTet = neigh/4;
            in_facet = neigh%4;

            if(transitiveHashedCmp(curTet, i)) {
              truth=0;
              break;
            }

            uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
            for (out_facet=0; out_facet<3; out_facet++)
              if(nodes[out_facet]==newV)
                break;

          } while (curTet!=i);

          if(truth){
            constrainEdge(mesh, i, j, k);
            localNum++;
          }
        }
      }
    }

    numEdges[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      numEdgesTotal = numLines;
      for (int i=0; i<nthreads; i++) {
        // printf("%lu\n", numEdges[i]);
        uint32_t tsum = numEdgesTotal + numEdges[i];
        numEdges[i] = numEdgesTotal;
        numEdgesTotal = tsum;
      }

#ifndef NDEBUG
      if(numEdgesTotal>2*mesh->tetrahedra.num+numLines){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "you should never go here..");
        exit(EXIT_FAILURE);
      }
#endif

      status = hxtAlignedMalloc(&edgeKey, numEdgesTotal*sizeof(HXTGroup2));
    }

    if(status==HXT_STATUS_OK) {
      // copy the edges from mesh->lines in the edgeKey struct array
      #pragma omp for
      for (uint64_t i=0; i<numLines; i++) {
        uint32_t p0 = lines[2*i+0];
        uint32_t p1 = lines[2*i+1];

        if(p0<p1) {
          edgeKey[i].v[0] = p0*n*2 + p1*2 + 0;
        }
        else {
          edgeKey[i].v[0] = p1*n*2 + p0*2 + 0;
        }

        edgeKey[i].v[1] = HXT_NO_ADJACENT; // this lines does not come from any tetrahedra
      }

      localNum = numEdges[threadID];
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        for (int j=0; j<4; j++) {
          for (int k=j+1; k<4; k++) {
            if(isEdgeConstrained(mesh, i, j, k)){
              uint32_t p0 = mesh->tetrahedra.node[4*i + nodeArray[j][k]];
              uint32_t p1 = mesh->tetrahedra.node[4*i + nodeArray[k][j]];

              if(p0==HXT_GHOST_VERTEX || p1==HXT_GHOST_VERTEX)
              {
                HXT_ERROR_MSG(HXT_STATUS_ERROR, "There were contrained edges before this function was called.");
                exit(EXIT_FAILURE);
              }

              if(p0<p1){
                edgeKey[localNum].v[0] = p0*n*2 + p1*2 + 1;
              }
              else {
                edgeKey[localNum].v[0] = p1*n*2 + p0*2 + 1;
              }
              edgeKey[localNum].v[1] = 6*i+facetToNumber[j][k];

              localNum++;

              unconstrainEdge(mesh, i, j, k);
            }
          }
        }
      }
    }
  }

  HXT_CHECK( hxtAlignedFree(&lines) );

  HXT_CHECK(status);

  group2_sort_v0(edgeKey, numEdgesTotal, (n-1)*n*2-1);

  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    numEdges[threadID] = 0;

    #pragma omp for
    for (uint64_t i=0; i<numEdgesTotal; i++) {
      if(edgeKey[i].v[0]%2==0 && (i==numEdgesTotal-1 || edgeKey[i].v[0]/2!=edgeKey[i+1].v[0]/2))
        numEdges[threadID]++; // the edge is missing          
    }

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      *missing = 0;
      for (int i=0; i<nthreads; i++) {
        *missing+=numEdges[i];
      }
    }
  }

  HXT_CHECK( hxtFree(&numEdges) );

  if(*missing){
    HXT_CHECK( hxtAlignedFree(&edgeKey) );
    return HXT_STATUS_OK;
  }

  char* edgeFlag;
  HXT_CHECK( hxtAlignedMalloc(&edgeFlag, 6*mesh->tetrahedra.num*sizeof(char)) );
  memset(edgeFlag, 0, 6*mesh->tetrahedra.num*sizeof(char));

  #pragma omp parallel for
  for (uint64_t i=1; i<numEdgesTotal; i++) {
    if(edgeKey[i-1].v[0]%2==0) {

      // turn around the edge to set edgeFlag of all tetrahedra to 1...
      uint64_t firstTet = edgeKey[i].v[1]/6;
      uint64_t curTet = firstTet;
      int edgeNumber = edgeKey[i].v[1]%6;
      int in_facet = numberToFacetMin[edgeNumber];
      int out_facet = numberToFacetMax[edgeNumber];

      do
      {
      	edgeFlag[6*curTet + facetToNumber[in_facet][out_facet]] = 1;

      	uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

        // go into the neighbor through out_facet
        uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
        curTet = neigh/4;
        in_facet = neigh%4;
        uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
        for (out_facet=0; out_facet<3; out_facet++)
          if(nodes[out_facet]==newV)
            break;

      } while (curTet!=firstTet);
    }
  }

  HXT_CHECK( hxtAlignedFree(&edgeKey) );

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    for (int j=0; j<6; j++) {
      if(edgeFlag[6*i+j])
        constrainEdge(mesh, i, numberToFacetMin[j], numberToFacetMax[j]);
    }
  }


  HXT_CHECK( hxtAlignedFree(&edgeFlag) );
  

  return HXT_STATUS_OK;
}


/********************************************************************************
 *  report the number of missing triangles or set flag for constrained triangle *
 ********************************************************************************/
// every tetrahedra must have a neighbor HXT_NO_ADJACENT is NOT permitted !!!
HXTStatus hxtConstrainTriangles(HXTMesh* mesh, uint64_t* missing) {
  HXTGroup2 *triKey = NULL;
  HXTGroup3* pairKey = NULL;

  if(mesh->triangles.num==0) {
    *missing = 0;
    return HXT_STATUS_OK;
  }

  uint64_t *numTriangles;
  int maxThreads = omp_get_max_threads();
  HXT_CHECK( hxtMalloc(&numTriangles, maxThreads*sizeof(uint64_t)) );

  const uint64_t n = mesh->vertices.num;
  uint64_t numTrianglesTotal;

  HXTStatus status = HXT_STATUS_OK;

#ifndef NDEBUG
  uint64_t nGhosts = 0;

  #pragma omp parallel for reduction(+:nGhosts)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX)
      nGhosts++;
  }

  if(n <= 2097152){
    HXT_CHECK( hxtAlignedMalloc(&triKey, (2*mesh->tetrahedra.num-3*nGhosts/2+mesh->triangles.num)*sizeof(HXTGroup2)) );
  }
  else{
    HXT_CHECK( hxtAlignedMalloc(&pairKey, (2*mesh->tetrahedra.num-3*nGhosts/2+mesh->triangles.num)*sizeof(HXTGroup3)) );
  }
#endif

  // create a list of triangles in the mesh:
  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.node[4*i+3]!=HXT_GHOST_VERTEX) {
        for (int j=0; j<4; j++) {
          uint64_t neigh = mesh->tetrahedra.neigh[4*i+j]/4;
          if(hashedCompare(i, neigh) || 
             mesh->tetrahedra.node[neigh*4+3]==HXT_GHOST_VERTEX)
            localNum++;
        }
      }
    }

    numTriangles[threadID] = localNum;
    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      numTrianglesTotal = mesh->triangles.num;
      for (int i=0; i<nthreads; i++) {
        uint32_t tsum = numTrianglesTotal + numTriangles[i];
        numTriangles[i] = numTrianglesTotal;
        numTrianglesTotal = tsum;
      }

#ifndef NDEBUG
      if(numTrianglesTotal!=2*mesh->tetrahedra.num-3*nGhosts/2+mesh->triangles.num){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "you should never go here... (%lu!=2*%lu+3*%lu/2",numTrianglesTotal-mesh->triangles.num,
                                                                                                mesh->tetrahedra.num, nGhosts);
        exit(EXIT_FAILURE);
      }
#else
      if(n <= 2097152){
        status = hxtAlignedMalloc(&triKey, numTrianglesTotal*sizeof(HXTGroup2));
      }
      else{
        status = hxtAlignedMalloc(&pairKey, numTrianglesTotal*sizeof(HXTGroup3));
      }
#endif
    }

    if(status==HXT_STATUS_OK) {
      // copy the triangles from mesh->triangles in the triKey struct array
      if(n <= 2097152){
        #pragma omp for
        for (uint64_t i=0; i<mesh->triangles.num; i++) {
          uint32_t v[3] = {mesh->triangles.node[3*i+0],
                           mesh->triangles.node[3*i+1],
                           mesh->triangles.node[3*i+2]};
          sort3ints(v);
          triKey[i].v[1] = HXT_NO_ADJACENT; // this triangle does not come from any tetrahedra
          triKey[i].v[0] = v[0]*(n-1)*n*2 + v[1]*n*2 + v[2]*2 + 0; // the lowest bit of triangles from mesh->triangles is unset
        }
      }
      else{
        #pragma omp for
        for (uint64_t i=0; i<mesh->triangles.num; i++) {
          uint32_t v[3] = {mesh->triangles.node[3*i+0],
                           mesh->triangles.node[3*i+1],
                           mesh->triangles.node[3*i+2]};
          sort3ints(v);
          pairKey[i].v[2] = HXT_NO_ADJACENT; // this triangle does not come from any tetrahedra
          pairKey[i].v[1] = v[0]*(n-1) + v[1];
          pairKey[i].v[0] = v[2]*2+0;
        }
      }

      // add the triangle from the tetrahedral mesh to the triKey struct array
      localNum = numTriangles[threadID];
      if(n <= 2097152){
        #pragma omp for schedule(static)
        for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
          if(mesh->tetrahedra.node[4*i+3]!=HXT_GHOST_VERTEX){
            for (int j=0; j<4; j++) {
              uint64_t neigh = mesh->tetrahedra.neigh[4*i+j]/4;
              if(hashedCompare(i, neigh) || 
                 mesh->tetrahedra.node[neigh*4+3]==HXT_GHOST_VERTEX) {
                uint32_t v[3] = {mesh->tetrahedra.node[4*i+((j+1)&3)],
                                 mesh->tetrahedra.node[4*i+((j+2)&3)],
                                 mesh->tetrahedra.node[4*i+((j+3)&3)]};
                sort3ints(v);
                triKey[localNum].v[1] = 4*i+j;
                triKey[localNum].v[0] = v[0]*(n-1)*n*2 + v[1]*n*2 + v[2]*2 + 1; // max: 2(n-3)(n-1)n + 2(n-2)n + 2(n-1) + 1
                                                                                //    = 2(n-2)(n-1)n-1
                localNum++;
              }
            }
          }
        }
      }
      else {
        #pragma omp for schedule(static)
        for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
          if(mesh->tetrahedra.node[4*i+3]!=HXT_GHOST_VERTEX){
            for (int j=0; j<4; j++) {
              uint64_t neigh = mesh->tetrahedra.neigh[4*i+j]/4;
              if(hashedCompare(i, neigh) || 
                 mesh->tetrahedra.node[neigh*4+3]==HXT_GHOST_VERTEX) {
                uint32_t v[3] = {mesh->tetrahedra.node[4*i+((j+1)&3)],
                                 mesh->tetrahedra.node[4*i+((j+2)&3)],
                                 mesh->tetrahedra.node[4*i+((j+3)&3)]};
                sort3ints(v);
                pairKey[localNum].v[2] = 4*i+j;
                pairKey[localNum].v[1] = v[0]*(n-1) + v[1]; // max: (n-3)(n-1) + (n-2) = (n-2)(n-1) - 1
                pairKey[localNum].v[0] = v[2]*2+1;          // max: (n-1)2+1 = 2n-1

                localNum++;
              }
            }
          }
        }
      }
    }
  }

  HXT_CHECK(status);

  if(n <= 2097152){
    // sort triKey
    group2_sort_v0(triKey, numTrianglesTotal, 2*(n-2)*(n-1)*n-1);
  }
  else{
    group3_sort_v0(pairKey, numTrianglesTotal, 2*n-1);
    group3_sort_v1(pairKey, numTrianglesTotal, (n-2)*(n-1)-1);
  }

  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    numTriangles[threadID] = 0;

    if(n <= 2097152){
      #pragma omp for
      for (uint64_t i=0; i<numTrianglesTotal; i++) {
        if(triKey[i].v[0]%2==0 && (i==numTrianglesTotal-1 || triKey[i].v[0]/2!=triKey[i+1].v[0]/2))
            numTriangles[threadID]++; // the triangle is missing
      }
    }
    else{
      #pragma omp for
      for (uint64_t i=0; i<numTrianglesTotal; i++) {
        if(pairKey[i].v[0]%2==0 && (i==numTrianglesTotal-1 || pairKey[i].v[0]/2!=pairKey[i+1].v[0]/2 || pairKey[i].v[1]!=pairKey[i+1].v[1]))
            numTriangles[threadID]++;
      }
    }

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      *missing = 0;
      for (int i=0; i<nthreads; i++) {
        *missing+=numTriangles[i];
      }
    }
  }

  HXT_CHECK( hxtFree(&numTriangles) );

  if(*missing){
    HXT_CHECK( hxtAlignedFree(&triKey) );
    HXT_CHECK( hxtAlignedFree(&pairKey) );
    return HXT_STATUS_OK;
  }

  char* faceFlag;
  HXT_CHECK( hxtAlignedMalloc(&faceFlag, 4*mesh->tetrahedra.num*sizeof(char)) );
  memset(faceFlag, 0, 4*mesh->tetrahedra.num*sizeof(char));

  if(n <= 2097152){
    #pragma omp parallel for
    for (uint64_t i=1; i<numTrianglesTotal; i++) {
      if(triKey[i-1].v[0]%2==0 ) {
        faceFlag[triKey[i].v[1]] = 1;
        if(mesh->tetrahedra.neigh[triKey[i].v[1]]!=HXT_NO_ADJACENT)
          faceFlag[mesh->tetrahedra.neigh[triKey[i].v[1]]] = 1;
      }
    }
  }
  else{
    #pragma omp parallel for
    for (uint64_t i=1; i<numTrianglesTotal; i++) {     
      if(pairKey[i-1].v[0]%2==0) {
        faceFlag[pairKey[i].v[2]] = 1;
        if(mesh->tetrahedra.neigh[pairKey[i].v[2]]!=HXT_NO_ADJACENT)
          faceFlag[mesh->tetrahedra.neigh[pairKey[i].v[2]]] = 1;
      }
    }
  }

  HXT_CHECK( hxtAlignedFree(&triKey) );
  HXT_CHECK( hxtAlignedFree(&pairKey) );


  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    for (int j=0; j<4; j++) {
      if(faceFlag[4*i+j])
        constrainFacet(mesh, 4*i+j);
    }
  }

  HXT_CHECK( hxtAlignedFree(&faceFlag) );

  return HXT_STATUS_OK;
}