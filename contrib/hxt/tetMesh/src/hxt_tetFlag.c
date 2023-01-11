// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_sort.h"
#include "hxt_tetFlag.h"


/* just a function such that:
 * if hashLess(a,b)==true
 * then hashLess(b,a)==false
 *
 * BUT hashLess(a,b)==true and hashLess(b,c)==true
 * doesn't imply that hashLess(a,c)==true
 * and inversely if you replace true with false (no transitivity) */
static inline uint64_t hashLess(uint64_t a, uint64_t b) {
  return ((a^b)&1)^(a<b);
}

/* just a function such that:
 * if transitiveHashLess(a,b)==true
 * then transitiveHashLess(b,a)==false
 *
 * AND transitiveHashLess(a,b)==true and transitiveHashLess(b,c)==true
 * imply that transitiveHashLess(a,c)==true
 * and inversely if you replace true with false (the relation is transitive) */
static inline uint64_t transitiveHashLess(uint64_t a, uint64_t b) {
  return hash64(a) < hash64(b);
}


#ifndef NDEBUG
static inline uint64_t countBoundaries(HXTMesh* mesh) {
  uint64_t nBoundaries=0;

  #pragma omp parallel for reduction(+:nBoundaries)
  for (uint64_t i=0; i<4*mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.neigh[i]==HXT_NO_ADJACENT)
      nBoundaries++;
  }

  return nBoundaries;
}
#endif


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
      else if(v0>v1){
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

      HXTSORT_3_VALUES_INPLACE(uint32_t, v);

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
            HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated line in mesh->lines (" HXTu64 " & " HXTu64 ")\n"
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

#ifndef NDEBUG
    if(countBoundaries(mesh)!=0)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "a tetrahedron has no neighbor. Add ghosts tetrahedra to use this function");
#endif


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
    for (uint64_t tet=0; tet<mesh->tetrahedra.num; tet++) {
      for (int edge=0; edge<6; edge++) {
        // get some info on the edge (adjacent facets and nodes)

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

        /* visit tetrahedra `tet` by turning around the edge
           we only want the edge to be registered once,
           thus we stop as soon as `transitiveHashLess(curTet, tet)==true`
        */
        int truth = 1;
        uint64_t curTet = tet;
        do
        {
          uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

          // go into the neighbor through out_facet
          uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
          curTet = neigh/4;
          in_facet = neigh%4;

          if(transitiveHashLess(curTet, tet)) {
            truth=0;
            break;
          }

          uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
          for (out_facet=0; out_facet<3; out_facet++)
            if(nodes[out_facet]==newV)
              break;

        } while (curTet!=tet);

        // only the tetrahedron with the biggest hash will register the edge
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
      // exclusive scan used to compute starting indices
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
            HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated line in mesh->lines (" HXTu64 " & " HXTu64 ")\n"
                                            "\tThis issue will not produce a direct error if NDEBUG is defined",
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
  uint64_t nBoundaries = countBoundaries(mesh);

  #pragma omp parallel for reduction(+:nGhosts)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX)
      nGhosts++;
  }

  if(n <= 2642246){
    HXT_CHECK( hxtAlignedMalloc(&triKey, (2*(mesh->tetrahedra.num+nBoundaries)-3*(nGhosts+nBoundaries)/2+mesh->triangles.num)*sizeof(HXTGroup2)) );
  }
  else{
    HXT_CHECK( hxtAlignedMalloc(&pairKey, (2*(mesh->tetrahedra.num+nBoundaries)-3*(nGhosts+nBoundaries)/2+mesh->triangles.num)*sizeof(HXTGroup3)) );
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
          uint64_t neigh = mesh->tetrahedra.neigh[4*i+j];
          if(neigh==HXT_NO_ADJACENT || hashLess(i, neigh/4) || 
             mesh->tetrahedra.node[neigh]==HXT_GHOST_VERTEX)
            localNum++;
        }
      }
    }

    numTriangles[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      // exclusive scan used to compute starting indices
      int nthreads = omp_get_num_threads();
      numTrianglesTotal = mesh->triangles.num;
      for (int i=0; i<nthreads; i++) {
        uint32_t tsum = numTrianglesTotal + numTriangles[i];
        numTriangles[i] = numTrianglesTotal;
        numTrianglesTotal = tsum;
      }

    #ifndef NDEBUG
      if(numTrianglesTotal!=2*(mesh->tetrahedra.num+nBoundaries)-3*(nGhosts+nBoundaries)/2+mesh->triangles.num){
        HXT_ERROR_MSG(HXT_STATUS_ERROR, "you should never go here..."
                                        " (" HXTu64 "!=2*" HXTu64 "+(" HXTu64 "-3*" HXTu64 ")/2",
                                        numTrianglesTotal-mesh->triangles.num,
                                        mesh->tetrahedra.num, nBoundaries, nGhosts);
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
          HXTSORT_3_VALUES_INPLACE(uint32_t, v);
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
          HXTSORT_3_VALUES_INPLACE(uint32_t, v);
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
              uint64_t neigh = mesh->tetrahedra.neigh[4*i+j];
              if(neigh==HXT_NO_ADJACENT || hashLess(i, neigh/4) || 
                 mesh->tetrahedra.node[neigh]==HXT_GHOST_VERTEX) {
                uint32_t v[3] = {mesh->tetrahedra.node[4*i+((j+1)&3)],
                                 mesh->tetrahedra.node[4*i+((j+2)&3)],
                                 mesh->tetrahedra.node[4*i+((j+3)&3)]};
                HXTSORT_3_VALUES_INPLACE(uint32_t, v);
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
              uint64_t neigh = mesh->tetrahedra.neigh[4*i+j];
              if(neigh==HXT_NO_ADJACENT || hashLess(i, neigh/4) || 
                 mesh->tetrahedra.node[neigh]==HXT_GHOST_VERTEX) {
                uint32_t v[3] = {mesh->tetrahedra.node[4*i+((j+1)&3)],
                                 mesh->tetrahedra.node[4*i+((j+2)&3)],
                                 mesh->tetrahedra.node[4*i+((j+3)&3)]};
                HXTSORT_3_VALUES_INPLACE(uint32_t, v);
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
              HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated triangle in mesh->triangles (" HXTu64 " & " HXTu64 ")\n"
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
              HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicated triangle in mesh->triangles (" HXTu64 " & " HXTu64 ")\n"
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

  char* faceFlag;
  HXT_CHECK( hxtAlignedMalloc(&faceFlag, 4*mesh->tetrahedra.num*sizeof(char)) );
  memset(faceFlag, 0, 4*mesh->tetrahedra.num*sizeof(char));

  // fill faceFlag
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->triangles.num; i++) {
    if(tri2TetMap[i]!=HXT_NO_ADJACENT) {
      faceFlag[tri2TetMap[i]] = 1;
      faceFlag[mesh->tetrahedra.neigh[tri2TetMap[i]]] = 1;
    }
  }

  // constrain corresponding flag, tetrahedron by tetrahedron to avoid race conditions
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


/*********************************************************
 *   Constrain an edge in all tetrahedra surrounding it
 *********************************************************
 * In single-thread cases, put edgeFlag==NULL.
 * This function will directly set the constraint bit corresponding to the edge
 * '6*firstTet+edge' on all tetrahedra surrounding this edge.
 *
 * In multi-threaded case, if multiple thread modify different edges of the
 * same tetrahedra, modifying the same flag would result in a race condition.
 * Therefore, in parallel section, you must give an array with a char per edge.
 * This function will set the edges corresponding to '6*firstTet+edge' to 1.
 */
HXTStatus hxtConstrainLine(HXTMesh* mesh, uint64_t tet, int edge, char* edgeFlag)
{
  uint64_t curTet = tet;
  unsigned in_facet, out_facet;
  getFacetsFromEdge(edge, &in_facet, &out_facet);

  // turn around the edge to set edgeFlag of all tetrahedra to 1...
  do
  {
    if(edgeFlag)
      edgeFlag[6*curTet + getEdgeFromFacets(in_facet, out_facet)] = 1;
    else
      setEdgeConstraint(mesh, curTet, getEdgeFromFacets(in_facet, out_facet));

    uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

    // go into the neighbor through out_facet
    uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
    curTet = neigh/4;
    in_facet = neigh%4;
    uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
    for (out_facet=0; out_facet<3; out_facet++)
      if(nodes[out_facet]==newV)
        break;

  } while (curTet!=tet);

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

  char* edgeFlag;
  HXT_CHECK( hxtAlignedMalloc(&edgeFlag, 6*mesh->tetrahedra.num*sizeof(char)) );
  memset(edgeFlag, 0, 6*mesh->tetrahedra.num*sizeof(char));

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->lines.num; i++) {
    if(lines2TriMap[i]==HXT_NO_ADJACENT && lines2TetMap[i]!=HXT_NO_ADJACENT) {
      hxtConstrainLine(mesh, lines2TetMap[i]/6, lines2TetMap[i]%6, edgeFlag);
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