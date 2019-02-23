#include "hxt_sort.h"
#include "hxt_tetFlag.h"


static inline void sort3ints(uint32_t i[3]){
  if(i[0]>i[1]){
    uint32_t tmp = i[0]; i[0] = i[1]; i[1] = tmp;
  }

  if(i[1]>i[2]){
    uint32_t tmp1 = i[1]; i[1] = i[2]; i[2] = tmp1;

    if(i[0]>i[1]){
      uint32_t tmp2 = i[0]; i[0] = i[1]; i[1] = tmp2;
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

/**************************************************************************************
 *   Lines --> Triangles   MAPPING  (for each line, get 3*tri+e)
 *************************************************************************************/
HXTStatus hxtGetLines2TriMap(HXTMesh* mesh, uint64_t* lines2TriMap, uint64_t* missing)
{
  HXTGroup2* edgeKey = NULL;
  uint64_t* numEdges = NULL;

  const int maxThreads = omp_get_max_threads();
  const uint64_t n = mesh->vertices.num;
  const uint64_t numEdgesTotal = mesh->triangles.num*3+mesh->lines.num;

  HXT_CHECK( hxtMalloc(&numEdges, maxThreads*sizeof(uint64_t)) );
  HXT_CHECK( hxtAlignedMalloc(&edgeKey, numEdgesTotal*sizeof(HXTGroup2)) );

  #pragma omp parallel
  {
    #pragma omp for nowait
    for (uint64_t i=0; i<mesh->lines.num; i++) {
      uint32_t v0 = mesh->lines.node[2*i];
      uint32_t v1 = mesh->lines.node[2*i+1];

      if(v0<v1) {
        edgeKey[i].v[0] = v0*n + v1;
        edgeKey[i].v[1] = 2*i;
      }
      else if(v0<v1){
        edgeKey[i].v[0] = v1*n + v0;
        edgeKey[i].v[1] = 2*i;
      }
      else {
        edgeKey[i].v[0] = v0*n + v0; // the line begins and ends at the same point...
        edgeKey[i].v[1] = 1;
        lines2TriMap[i] = HXT_NO_ADJACENT;
      }
    }

    #pragma omp for
    for (uint64_t i=0; i<mesh->triangles.num; i++) {
      uint32_t v[3] = {mesh->triangles.node[3*i+0],
                       mesh->triangles.node[3*i+1],
                       mesh->triangles.node[3*i+2]};

      sort3ints(v);

      edgeKey[mesh->lines.num+3*i].v[0] = v[0]*n + v[1];
      edgeKey[mesh->lines.num+3*i].v[1] = 2*(3*i)+1;
      edgeKey[mesh->lines.num+3*i+1].v[0] = v[0]*n + v[2];
      edgeKey[mesh->lines.num+3*i+1].v[1] = 2*(3*i+1)+1;
      edgeKey[mesh->lines.num+3*i+2].v[0] = v[1]*n + v[2];
      edgeKey[mesh->lines.num+3*i+2].v[1] = 2*(3*i+2)+1;
    }
  }

  HXT_CHECK( group2_sort_v0(edgeKey, numEdgesTotal, n*(n-1)-1) );

  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for
    for (uint64_t i=0; i<numEdgesTotal; i++) {
      if(edgeKey[i].v[1]%2==0) {
        if(i!=numEdgesTotal-1 && edgeKey[i].v[0]==edgeKey[i+1].v[0]) {
        #ifndef NDEBUG
          if(edgeKey[i+1].v[1]%2==0) {
            HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated line in mesh->lines (%lu & %lu)\n"
                                           "\tThis case is not handled in Release mode, FIX IT !!",
                                           edgeKey[i].v[1]/2, edgeKey[i+1].v[1]/2);
            exit(EXIT_FAILURE);
          }
          else
        #endif
          {
            lines2TriMap[edgeKey[i].v[1]/2] = edgeKey[i+1].v[1]/2;
          }
        }
        else /* the edge is not in a triangle */ {
          localNum++;
          lines2TriMap[edgeKey[i].v[1]/2] = HXT_NO_ADJACENT;
        }
      }
    }

    numEdges[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      *missing = 0;
      for (int i=0; i<nthreads; i++) {
        *missing += numEdges[i];
      }
    }
  }

  HXT_CHECK( hxtFree(&numEdges) );
  HXT_CHECK( hxtAlignedFree(&edgeKey) );

  return HXT_STATUS_OK;
}


/**************************************************************************************
 *   Lines --> Tetrahedra   MAPPING  (for each line, get 6*tet+e)
 *************************************************************************************/
HXTStatus hxtGetLines2TetMap(HXTMesh* mesh, uint64_t* lines2TetMap, uint64_t* missing)
{
HXT_ASSERT( lines2TetMap!=NULL );
HXT_ASSERT( mesh!=NULL );

  const int maxThreads = omp_get_max_threads();
  const uint64_t n = mesh->vertices.num;
  HXTStatus status = HXT_STATUS_OK;
  uint64_t numEdgesTotal;

  HXTGroup2* edgeKey = NULL;
  uint64_t* numEdges;
  unsigned char* edgeFlag;
  HXT_CHECK( hxtMalloc(&numEdges, maxThreads*sizeof(uint64_t)) );
  HXT_CHECK( hxtAlignedMalloc(&edgeFlag, mesh->tetrahedra.num*sizeof(char)) );
  memset(edgeFlag, 0, mesh->tetrahedra.num*sizeof(char));


  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for schedule(static)
    for (uint64_t tet=0; tet<mesh->tetrahedra.num; tet++) { // for each tetrahedra
      for (int edge=0; edge<6; edge++) {

        unsigned in_facet, out_facet;
        getFacetsFromEdge(edge, &in_facet, &out_facet);

        uint32_t p0, p1;
        {
          unsigned n0, n1;
          getNodesFromEdge(edge, &n0, &n1);
          p0 = mesh->tetrahedra.node[4*tet + n0];
          p1 = mesh->tetrahedra.node[4*tet + n1];
        }

        if(p0==HXT_GHOST_VERTEX || p1==HXT_GHOST_VERTEX)
          continue;

        int truth = 1;

        uint64_t curTet = tet;
        do
        {
          uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

          // go into the neighbor through out_facet
          uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
          curTet = neigh/4;
          in_facet = neigh%4;

          if(transitiveHashedCmp(curTet, tet)) {
            truth=0;
            break;
          }

          uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
          for (out_facet=0; out_facet<3; out_facet++)
            if(nodes[out_facet]==newV)
              break;

        } while (curTet!=tet);

        if(truth){
          edgeFlag[tet] |= 1U<<edge;
          localNum++;
        }
      }
    }

    numEdges[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      numEdgesTotal = mesh->lines.num;
      for (int i=0; i<nthreads; i++) {
        uint32_t tsum = numEdgesTotal + numEdges[i];
        numEdges[i] = numEdgesTotal;
        numEdgesTotal = tsum;
      }

#ifndef NDEBUG
      if(numEdgesTotal>2*mesh->tetrahedra.num+mesh->lines.num){
        HXT_ERROR_MSG(HXT_STATUS_ERROR,
                      "There is less than 2 tetrahedra per edge in average,"
                      "which means the mesh is totally broken !");
        exit(EXIT_FAILURE);
      }
#endif

      status = hxtAlignedMalloc(&edgeKey, numEdgesTotal*sizeof(HXTGroup2));
    }

    if(status==HXT_STATUS_OK) {
      // copy the edges from mesh->lines in the edgeKey struct array
      #pragma omp for
      for (uint64_t l=0; l<mesh->lines.num; l++) {
        uint32_t p0 = mesh->lines.node[2*l+0];
        uint32_t p1 = mesh->lines.node[2*l+1];

        if(p0<p1) {
          edgeKey[l].v[0] = p0*n + p1;
          edgeKey[l].v[1] = 2*l;
        }
        else if(p0>p1){
          edgeKey[l].v[0] = p1*n + p0;
          edgeKey[l].v[1] = 2*l;
        }
        else {
          edgeKey[l].v[0] = p0*n + p0; // the line begins and ends at the same point...
          edgeKey[l].v[1] = 1;
          lines2TetMap[l] = HXT_NO_ADJACENT;
        }

        
      }

      localNum = numEdges[threadID];
      #pragma omp for schedule(static)
      for (uint64_t tet=0; tet<mesh->tetrahedra.num; tet++) {
        for (unsigned edge=0; edge<6; edge++) {
          if(edgeFlag[tet] & (1U<<edge)){
            uint32_t p0, p1;
            {
              unsigned n0, n1;
              getNodesFromEdge(edge, &n0, &n1);
              p0 = mesh->tetrahedra.node[4*tet + n0];
              p1 = mesh->tetrahedra.node[4*tet + n1];
            }

            if(p0<p1){
              edgeKey[localNum].v[0] = p0*n + p1;
            }
            else {
              edgeKey[localNum].v[0] = p1*n + p0;
            }
            edgeKey[localNum].v[1] = 2*(6*tet+edge)+1;

            localNum++;
          }
        }
      }
    }
  }

  HXT_CHECK( hxtAlignedFree(&edgeFlag) );
  HXT_CHECK( status );

  HXT_CHECK( group2_sort_v0(edgeKey, numEdgesTotal, n*(n-1)-1) );

  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    #pragma omp for
    for (uint64_t i=0; i<numEdgesTotal; i++) {
      if(edgeKey[i].v[1]%2==0) {
        if(i!=numEdgesTotal-1 && edgeKey[i].v[0]==edgeKey[i+1].v[0]) {
        #ifndef NDEBUG
          if(edgeKey[i+1].v[1]%2==0) {
            HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated line in mesh->lines (%lu & %lu)\n"
                                           "\tThis case is not handled in Release mode, FIX IT !!",
                                           edgeKey[i].v[1]/2, edgeKey[i+1].v[1]/2);
            exit(EXIT_FAILURE);
          }
          else
        #endif
          {
            lines2TetMap[edgeKey[i].v[1]/2] = edgeKey[i+1].v[1]/2;
          }
        }
        else {
          lines2TetMap[edgeKey[i].v[1]/2] = HXT_NO_ADJACENT;
          localNum++;
        }
      }   
    }

    numEdges[threadID] = localNum;

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
  HXT_CHECK( hxtAlignedFree(&edgeKey) );
  return HXT_STATUS_OK;
}


/**************************************************************************************
 *   Triangles --> Tetrahedra   MAPPING
 *************************************************************************************/
HXTStatus hxtGetTri2TetMap(HXTMesh* mesh, uint64_t* tri2TetMap, uint64_t* missing)
{
  HXT_ASSERT(tri2TetMap!=NULL);

  if(mesh->triangles.num==0)
    return HXT_STATUS_OK;

  const uint64_t n = mesh->vertices.num;
  const int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;
  uint64_t numTrianglesTotal;


  HXTGroup2 *triKey = NULL;
  HXTGroup3* pairKey = NULL;
  uint64_t *numTriangles;
  HXT_CHECK( hxtMalloc(&numTriangles, maxThreads*sizeof(uint64_t)) );
  

#ifndef NDEBUG
  uint64_t nGhosts = 0;

  #pragma omp parallel for reduction(+:nGhosts)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX)
      nGhosts++;
  }

  if(n <= 2642246){
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
      if(n <= 2642246){
        status = hxtAlignedMalloc(&triKey, numTrianglesTotal*sizeof(HXTGroup2));
      }
      else{
        status = hxtAlignedMalloc(&pairKey, numTrianglesTotal*sizeof(HXTGroup3));
      }
    #endif
    }

    if(status==HXT_STATUS_OK) {
      // copy the triangles from mesh->triangles in the triKey struct array
      if(n <= 2642246){
        #pragma omp for
        for (uint64_t i=0; i<mesh->triangles.num; i++) {
          uint32_t v[3] = {mesh->triangles.node[3*i+0],
                           mesh->triangles.node[3*i+1],
                           mesh->triangles.node[3*i+2]};
          sort3ints(v);
          triKey[i].v[1] = 2*i;
          triKey[i].v[0] = v[0]*(n-1)*n + v[1]*n + v[2];
        }
      }
      else{
        #pragma omp for
        for (uint64_t i=0; i<mesh->triangles.num; i++) {
          uint32_t v[3] = {mesh->triangles.node[3*i+0],
                           mesh->triangles.node[3*i+1],
                           mesh->triangles.node[3*i+2]};
          sort3ints(v);
          pairKey[i].v[2] = 2*i;
          pairKey[i].v[1] = v[0]*(n-1) + v[1];
          pairKey[i].v[0] = v[2];
        }
      }

      // add the triangle from the tetrahedral mesh to the triKey struct array
      localNum = numTriangles[threadID];
      if(n <= 2642246){
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
                triKey[localNum].v[1] = 2*(4*i+j)+1;
                triKey[localNum].v[0] = v[0]*(n-1)*n + v[1]*n + v[2]; // max: (n-3)(n-1)n + (n-2)n + (n-1)
                                                                      //    = (n-2)(n-1)n - 1
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
                pairKey[localNum].v[2] = 2*(4*i+j)+1;
                pairKey[localNum].v[1] = v[0]*(n-1) + v[1]; // max: (n-3)(n-1) + (n-2) = (n-2)(n-1) - 1
                pairKey[localNum].v[0] = v[2];              // max: n-1

                localNum++;
              }
            }
          }
        }
      }
    }
  }

  HXT_CHECK(status);

  if(n <= 2642246){
    // sort triKey
    HXT_CHECK( group2_sort_v0(triKey, numTrianglesTotal, (n-2)*(n-1)*n-1) );
  }
  else{
    HXT_CHECK( group3_sort_v0(pairKey, numTrianglesTotal, n-1) );
    HXT_CHECK( group3_sort_v1(pairKey, numTrianglesTotal, (n-2)*(n-1)-1) );
  }


  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    uint64_t localNum = 0;

    if(n <= 2642246){
      #pragma omp for
      for (uint64_t i=0; i<numTrianglesTotal; i++) {
        if(triKey[i].v[1]%2==0) {
          if(i!=numTrianglesTotal-1 && triKey[i].v[0]==triKey[i+1].v[0]) {
          #ifndef NDEBUG
            if(triKey[i+1].v[1]%2==0) {
              HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated triangle in mesh->triangles (%lu & %lu)\n"
                                             "\tThis case is not handled in Release mode, FIX IT !!",
                                             triKey[i].v[1]/2, triKey[i+1].v[1]/2);
              exit(EXIT_FAILURE);
            }
            else
          #endif
            {
              tri2TetMap[triKey[i].v[1]/2] = triKey[i+1].v[1]/2;
            }
          }
          else /* the triangle is missing */ {
            localNum++;
            tri2TetMap[triKey[i].v[1]/2] = HXT_NO_ADJACENT;
          }
        }
      }
    }
    else{
      #pragma omp for
      for (uint64_t i=0; i<numTrianglesTotal; i++) {
        if(pairKey[i].v[2]%2==0) {
          if(i!=numTrianglesTotal-1 && pairKey[i].v[0]==pairKey[i+1].v[0] && pairKey[i].v[1]==pairKey[i+1].v[1]) {
          #ifndef NDEBUG
            if(pairKey[i+1].v[2]%2==0) {
              HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated triangle in mesh->triangles (%lu & %lu)\n"
                                             "\tThis case is not handled in Release mode, FIX IT !!",
                                             pairKey[i].v[2]/2, pairKey[i+1].v[2]/2);
              exit(EXIT_FAILURE);
            }
            else
          #endif
            {
              tri2TetMap[pairKey[i].v[2]/2] = pairKey[i+1].v[2]/2;
            }
          }
          else /* the triangle is missing */ {
            localNum++;
            tri2TetMap[pairKey[i].v[2]/2] = HXT_NO_ADJACENT;
          }
        }
      }
    }

    numTriangles[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      *missing = 0;
      for (int i=0; i<nthreads; i++) {
        *missing += numTriangles[i];
      }
    }
  }

  HXT_CHECK( hxtFree(&numTriangles) );
  HXT_CHECK( hxtAlignedFree(&triKey) );
  HXT_CHECK( hxtAlignedFree(&pairKey) );

  return HXT_STATUS_OK;
}


/**************************************************************************************
 *   Constrain facets of tetrahedron if it is in tri2TetMap
 *************************************************************************************/
HXTStatus hxtConstrainTriangles(HXTMesh* mesh, uint64_t* tri2TetMap)
{
  HXT_ASSERT(tri2TetMap!=NULL);
  HXT_ASSERT(mesh!=NULL);
#ifdef DEBUG
  for (uint64_t i=0; i<mesh->triangles.num; i++) {
    if(tri2TetMap[i]==HXT_NO_ADJACENT)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "There are missing mappings in tri2TetMap");
  }
#endif

  char* faceFlag;
  HXT_CHECK( hxtAlignedMalloc(&faceFlag, 4*mesh->tetrahedra.num*sizeof(char)) );
  memset(faceFlag, 0, 4*mesh->tetrahedra.num*sizeof(char));

  // fill faceFlag
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->triangles.num; i++) {
    faceFlag[tri2TetMap[i]] = 1;
    faceFlag[mesh->tetrahedra.neigh[tri2TetMap[i]]] = 1;
  }

  // constrain corresponding flag, teetrahedron by tetrahedron to avoid race conditions
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    for (uint64_t j=0; j<4; j++) {
      if(faceFlag[4*i+j]) {
        setFacetConstraint(mesh, i, j);
      }
    }
  }

  HXT_CHECK( hxtAlignedFree(&faceFlag) );

  return HXT_STATUS_OK;
}



/**************************************************************************************
 *   Constrain edge of tetrahedron if it is in lines2TetMap but not in lines2TriMap
 *************************************************************************************/
HXTStatus hxtConstrainLinesNotInTriangles(HXTMesh* mesh, uint64_t* lines2TetMap, uint64_t* lines2TriMap)
{
  HXT_ASSERT(lines2TetMap!=NULL);
  HXT_ASSERT(lines2TriMap!=NULL);
  HXT_ASSERT(mesh!=NULL);

#ifdef DEBUG
  for (uint64_t i=0; i<mesh->lines.num; i++) {
    if(lines2TetMap[i]==HXT_NO_ADJACENT && mesh->lines.node[2*i]!=mesh->lines.node[2*i+1])
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "There are missing mappings in lines2TetMap");
  }
#endif

  char* edgeFlag;
  HXT_CHECK( hxtAlignedMalloc(&edgeFlag, 6*mesh->tetrahedra.num*sizeof(char)) );
  memset(edgeFlag, 0, 6*mesh->tetrahedra.num*sizeof(char));

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->lines.num; i++) {
    if(lines2TriMap[i]==HXT_NO_ADJACENT && lines2TetMap[i]!=HXT_NO_ADJACENT) {
      // turn around the edge to set edgeFlag of all tetrahedra to 1...
      uint64_t firstTet = lines2TetMap[i]/6;
      uint64_t curTet = firstTet;
      int edge = lines2TetMap[i]%6;

      unsigned in_facet, out_facet;
      getFacetsFromEdge(edge, &in_facet, &out_facet);

      do
      {
        edgeFlag[6*curTet + getEdgeFromFacets(in_facet, out_facet)] = 1;

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

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    for (int j=0; j<6; j++) {
      if(edgeFlag[6*i+j])
        setEdgeConstraint(mesh, i, j);
    }
  }


  HXT_CHECK( hxtAlignedFree(&edgeFlag) );

  return HXT_STATUS_OK;
}