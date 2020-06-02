// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetDelaunay.h"
#include "predicates.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"

// mark all the points which are in mesh->(points | lines | triangles)
static void markMeshPoints(HXTMesh* mesh)
{
  #pragma omp parallel for simd
  for(uint32_t i=0; i<mesh->vertices.num; i++) {
    mesh->vertices.coord[4*i+3] = 0.0;
  }

  for(uint64_t i=0; i<mesh->triangles.num; i++) {
    for(int j=0; j<3; j++) {
      mesh->vertices.coord[4* mesh->triangles.node[3*i+j] + 3] = 1.0;
    }
  }

  for(uint64_t i=0; i<mesh->lines.num; i++) {
    for(int j=0; j<2; j++) {
      mesh->vertices.coord[4* mesh->lines.node[2*i+j] + 3] = 1.0;
    }
  }

  for(uint64_t i=0; i<mesh->points.num; i++) {
    for(int j=0; j<2; j++) {
      mesh->vertices.coord[4* mesh->lines.node[2*i+j] + 3] = 1.0;
    }
  }
}


HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions)
{
// we assume that the input is a surface mesh
  if (mesh->tetrahedra.num)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should only contain triangles");
  if (mesh->triangles.num == 0)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should contain triangles");

  HXTNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo)*mesh->vertices.num) );

  markMeshPoints(mesh);

  uint32_t numToInsert = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    if(mesh->vertices.coord[4 * i + 3]==1.0) {
      nodeInfo[numToInsert].node = i;
      nodeInfo[numToInsert].status = HXT_STATUS_TRYAGAIN;
      numToInsert++;
    }
  }

  HXT_CHECK( hxtDelaunaySteadyVertices(mesh, delOptions, nodeInfo, numToInsert) );

#ifdef DEBUG
  #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
  for (uint32_t i=0; i<numToInsert; i++) {
    if(nodeInfo[i].status!=HXT_STATUS_TRUE){
      HXT_WARNING("point %u of the empty mesh was not inserted\n", nodeInfo[i].node);
    }
  }
#endif

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );

  return HXT_STATUS_OK;
}


static inline double square_dist(double v0[3], double v1[3])
{
  return (v1[0] - v0[0])*(v1[0] - v0[0]) +
         (v1[1] - v0[1])*(v1[1] - v0[1]) +
         (v1[2] - v0[2])*(v1[2] - v0[2]);
}


static int is_too_close(double ptSize, double vtaSize, double squareDist)
{
  if(ptSize!=DBL_MAX) {
    double meanSize = 0.5*(ptSize+vtaSize);
    if(squareDist < /*(0.94*0.94) * */meanSize * meanSize) {
      return 1;
    }
  }

  return 0;
}



/* compute a point (center) inside the tetrahedron which is very likely to respect the nodalsize.
 * return 0 if the computed point does respect the interpolated nodalsize
 * return 1 if the computed point does not respect the interpolated nodalsize
 * the interpolated nodalsize is placed into center[3]  */
static int getBestCenter(double p[4][4], double nodalSize[4], double center[4])
{
  double avg = 0.0;
  double num = 0;
  for(int i=0; i<4; i++) {
    double size = nodalSize[i];
    if(size!=DBL_MAX && size>0.0) {
      avg += size;
      num+=1.0;
    }
  }

  if(num==0) {
    HXT_WARNING("tetrahedron with undefined size");
    avg = 1.0;
  }
  else {
    avg /= num;
  }

  double s0 = nodalSize[0]!=DBL_MAX && nodalSize[0]>0.0 ? nodalSize[0] : avg;
  double s1 = nodalSize[1]!=DBL_MAX && nodalSize[1]>0.0 ? nodalSize[1] : avg;
  double s2 = nodalSize[2]!=DBL_MAX && nodalSize[2]>0.0 ? nodalSize[2] : avg;
  double s3 = nodalSize[3]!=DBL_MAX && nodalSize[3]>0.0 ? nodalSize[3] : avg;

  // (e/s)^2  (e is the norm of the edge, s is the mean nodalSize over that edge)
  double e0l2 = square_dist(p[0], p[1])/(0.25*(s0 + s1)*(s0 + s1));
  double e1l2 = square_dist(p[0], p[2])/(0.25*(s0 + s2)*(s0 + s2));
  double e2l2 = square_dist(p[0], p[3])/(0.25*(s0 + s3)*(s0 + s3));
  double e3l2 = square_dist(p[1], p[2])/(0.25*(s1 + s2)*(s1 + s2));
  double e4l2 = square_dist(p[1], p[3])/(0.25*(s1 + s3)*(s1 + s3));
  double e5l2 = square_dist(p[2], p[3])/(0.25*(s2 + s3)*(s2 + s3));

  // normally, this thing should be near 1 if the tet are well refined
  // it can be below 1 only on the surface, because we averaged the line lengths to get the nodalsize
  // in the interior, we forbid that it is below 1.

  // O = (0,0,0)
  // A = (xa,0,0)
  // B = (xb,yb,0)
  // C = (xc,yc,zc)

  // these formula accumulate a lot of errors...
  double xa = sqrt(e0l2);
  double xb = (e1l2 + e0l2 - e3l2)/(2*xa);
  double yb = sqrt(e1l2 - xb*xb);
  double xc = (e2l2 + e0l2 - e4l2)/(2*xa);
  double yc = (e1l2 + e2l2 - e5l2 - 2*xb*xc)/(2*yb);
  double zc = sqrt(e2l2 - xc*xc - yc*yc);

  /* Cross products of these edges. */
  double xcrossbc = yb * zc;
  double ycrossbc = - zc * xb;
  double zcrossbc = xb * yc - xc * yb;
  double ycrossca = zc * xa;
  double zcrossca = - xa * yc;
  double zcrossab = xa * yb;

  double denominator = 0.5 / (xa * yb * zc);

  // /* the same, only in terms of the lengths (just for fun)*/
  // if(!isfinite(denominator))
  //   denominator = 1.0 / sqrt(4*e0l2*e1l2*e2l2
  //                            + (e0l2 + e1l2 - e3l2)*(e0l2 + e2l2 - e4l2)*(e1l2 + e2l2 - e5l2)
  //                            - e0l2*(e1l2 + e2l2 - e5l2)*(e1l2 + e2l2 - e5l2)
  //                            - e1l2*(e0l2 + e2l2 - e4l2)*(e0l2 + e2l2 - e4l2)
  //                            - e2l2*(e0l2 + e1l2 - e3l2)*(e0l2 + e1l2 - e3l2));

  /* Calculate offset (from `p[0]') of circumcenter. */
  double xcirca = 0.5 * xa;
  double ycirca = (e0l2 * ycrossbc + e1l2 * ycrossca) * denominator;
  double zcirca = (e0l2 * zcrossbc + e1l2 * zcrossca + e2l2 * zcrossab) *
                  denominator;

  /* To interpolate a linear function at the circumcenter, define a    */
  /*   coordinate system with a bary0-axis directed from `p[0]' to `p[1]',      */
  /*   an bary1-axis directed from `p[0]' to `p[2]', and a bary2-axis directed  */
  /*   from `p[0]' to `p[3]'.  The values for bary0, bary1, and bary2 are computed */
   /*   by Cramer's Rule for solving systems of linear equations.       */
  double bary0 = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
                   (2.0 * denominator);
  double bary1 = (ycirca * ycrossca + zcirca * zcrossca) * (2.0 * denominator);
  double bary2 = (zcirca * zcrossab) * (2.0 * denominator);
  double bary3 = 1.0 - bary0 - bary1 - bary2;

  int circumcenterOutside = 0;
  int circumcenterTooClose = 0;
  if(bary0>0.0 && bary1>0.0 && bary2>0.0 && bary3>0.0) {
      // compute the cartesian coordinates from the barycentric ones
    center[0] = bary0*p[0][0] + bary1*p[1][0] + bary2*p[2][0] + bary3*p[3][0];
    center[1] = bary0*p[0][1] + bary1*p[1][1] + bary2*p[2][1] + bary3*p[3][1];
    center[2] = bary0*p[0][2] + bary1*p[1][2] + bary2*p[2][2] + bary3*p[3][2];
    center[3] = bary0*s0 + bary1*s1 + bary2*s2 + bary3*s3; // the interpolated nodalSize

    circumcenterTooClose = (
      is_too_close(s0, center[3], square_dist(p[0], center)) ||
      is_too_close(s1, center[3], square_dist(p[1], center)) ||
      is_too_close(s2, center[3], square_dist(p[2], center)) ||
      is_too_close(s3, center[3], square_dist(p[3], center))
    );
  }
  else { // we should also enter this if a bary is not finite
    circumcenterOutside = 1;
  }

  /* if we are outside the tet, or too close to another point, we get back inside,
   * by using the isotomic conjugate of the incenter instead of the circumcenter. */
  int otherCenterTooClose = 0;
  if(circumcenterOutside || circumcenterTooClose) {
    /* get the cross product corresponding to the last face: (c-a)x(a-b) */
    /* the sum of the cross product of the faces of a tetrahedron = 0 */
    double xsumcros = xcrossbc;
    double ysumcros = ycrossbc + ycrossca;
    double zsumcros = zcrossab + zcrossbc + zcrossca;

    double invA0x2 = 1.0/sqrt(xsumcros*xsumcros + ysumcros*ysumcros + zsumcros*zsumcros); /* (2 x area of the facet opposite to p0)^-1 */
    double invA1x2 = 1.0/sqrt(xcrossbc*xcrossbc + ycrossbc*ycrossbc + zcrossbc*zcrossbc); /* (2 x area of the facet opposite to p1)^-1 */
    double invA2x2 = 1.0/sqrt(ycrossca*ycrossca + zcrossca*zcrossca); /* (2 x area of the facet opposite to p2)^-1 */
    double invA3x2 = 1.0/zcrossab; /* (2 x area of the facet opposite to p3)^-1 */

    double x75_den = invA0x2 + invA1x2 + invA2x2 + invA3x2;

    const double alpha = 0.5;

    bary0 = (1.0 - alpha)*0.25 + alpha*invA0x2/x75_den;
    bary1 = (1.0 - alpha)*0.25 + alpha*invA1x2/x75_den;
    bary2 = (1.0 - alpha)*0.25 + alpha*invA2x2/x75_den;
    bary3 = (1.0 - alpha)*0.25 + alpha*invA3x2/x75_den;

    if(!isfinite(bary0) || !isfinite(bary1) || !isfinite(bary2) || !isfinite(bary3))
      bary0 = bary1 = bary2 = bary3 = 0.25;

    // compute the cartesian coordinates from the barycentric ones
    double otherCenter[4];
    otherCenter[0] = bary0*p[0][0] + bary1*p[1][0] + bary2*p[2][0] + bary3*p[3][0];
    otherCenter[1] = bary0*p[0][1] + bary1*p[1][1] + bary2*p[2][1] + bary3*p[3][1];
    otherCenter[2] = bary0*p[0][2] + bary1*p[1][2] + bary2*p[2][2] + bary3*p[3][2];
    otherCenter[3] = bary0*s0 + bary1*s1 + bary2*s2 + bary3*s3; // the interpolated nodalSize

    otherCenterTooClose = (
      is_too_close(s0, otherCenter[3], square_dist(p[0], otherCenter)) ||
      is_too_close(s1, otherCenter[3], square_dist(p[1], otherCenter)) ||
      is_too_close(s2, otherCenter[3], square_dist(p[2], otherCenter)) ||
      is_too_close(s3, otherCenter[3], square_dist(p[3], otherCenter))
    );

    if(circumcenterOutside || !otherCenterTooClose) {
      center[0] = otherCenter[0];
      center[1] = otherCenter[1];
      center[2] = otherCenter[2];
      center[3] = otherCenter[3];
    }
  }

  return otherCenterTooClose;
}


/* just fill tetCoord and tetNodalSize with the coordinates and nodal size of each node of
 * tetrahedron tet */
static inline void getTetCoordAndNodalSize(HXTMesh* mesh, double* nodalSizes, uint64_t tet,
                                           double tetCoord[4][4], double tetNodalSize[4])
{
  uint32_t* nodes = &mesh->tetrahedra.node[4*tet];
  for(int i=0; i<4; i++) {
    tetCoord[i][0] = mesh->vertices.coord[4 * nodes[i] + 0];
    tetCoord[i][1] = mesh->vertices.coord[4 * nodes[i] + 1];
    tetCoord[i][2] = mesh->vertices.coord[4 * nodes[i] + 2];

    tetNodalSize[i] = nodalSizes[nodes[i]];
  }
}


// unlike the bsearch function of stdlib, this one does return where
// it landed even if no element has the right key
static uint64_t* scanbsearch(uint64_t* array, uint64_t key, size_t num)
{
  while (num > 0) {
    uint64_t* pivot = array + (num >> 1);
    uint64_t diff = key - *pivot;

    if (diff==0)
      return pivot;

    if (diff <= key) { // got to search in the upper part
      array = pivot + 1;
      num--;
    }
    num >>= 1;
  }

  return array;
}



/* To balance the work between threads, we need, for each thread `t`:
 *  1 at which tetrahedron it needs to start creating points
 *  2 at which tetrahedron it needs to stop creating points
 *  3 the index of the first point it will create
 * To reserve the right number of points, we needs to know
 *  4 the total number of points
 * 
 *  1: startTet[t]
 *  2: startTet[t+1]  (startTet needs to be of size maxThreads+1)
 *  3: startPt[t]
 *  4: startPt[maxThreads] (startPt also needs to be of size maxThreads+1)
 *
 * We got the nice additional properties that:
 *  - startPt[0] = 0
 *  - startTet[maxThreads] = mesh->tetrahedra.num
 *  - `startPt[t+1] - startPt[t]` gives how many point will be created by thread t
 */
static HXTStatus refineBalanceWork(HXTMesh* mesh, uint32_t* startPt, size_t* startTet, int maxThreads)
{
  size_t* scan;
  uint32_t ptPerThreadGoal;
  HXT_CHECK( hxtAlignedMalloc(&scan, sizeof(size_t) * mesh->tetrahedra.num) );

  #pragma omp parallel num_threads(maxThreads)
  {
    int threadID = omp_get_thread_num();
    startPt[threadID] = 0;

    #pragma omp for
    for(uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      scan[i] = getProcessedFlag(mesh, i)==0; // we could maybe choose to create more than on point per tet later
      startPt[threadID] += scan[i];
    }

    #pragma omp barrier
    #pragma omp single
    {
      // we do a simple prefix sum
      size_t sum = 0;
      for(int t=0; t<maxThreads; t++) {
        size_t tsum = sum + startPt[t];
        startPt[t] = sum;
        sum = tsum;
      }

      startPt[maxThreads] = sum;
      ptPerThreadGoal = sum/maxThreads + 1;
    }

    uint32_t s = startPt[threadID];

    // each thread finish the prefix sum in its own array
    #pragma omp for
    for(uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      size_t inc = scan[i];
      scan[i] = s;
      s += inc;
    }

    size_t scanToFind = threadID * ptPerThreadGoal;

    // we want to find i such that scan[i] = scanToFind.
    // we do a simple binary search in the prefix scan array to find `i`
    size_t* pfnd = scanbsearch(scan, scanToFind, mesh->tetrahedra.num);
    startTet[threadID] = pfnd  - scan;
    if(startTet[threadID] < mesh->tetrahedra.num)
      startPt[threadID] = *pfnd;
    else
      startPt[threadID] = startPt[maxThreads];
  }
  HXT_CHECK( hxtAlignedFree(&scan) );

  startTet[maxThreads] = mesh->tetrahedra.num;

  return HXT_STATUS_OK;
}


/* good hash function for non-cryptographic purpose
 * see https://stackoverflow.com/a/12996028 */
static inline uint64_t hash64(uint64_t x) {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
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


// at the first pass, we split long edges instead of computing the circumcenter
static HXTStatus hxtRefineTetrahedraFirstPass(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                                              HXTStatus (*meshSizeFun)(double* coord, size_t n,
                                                                       void* meshSizeData),
                                              void* meshSizeData)
{
  const int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;

  uint64_t* startPt;
  HXT_CHECK( hxtMalloc(&startPt, maxThreads*sizeof(uint64_t)) );

  unsigned char* edgeFlag;
  HXT_CHECK( hxtAlignedMalloc(&edgeFlag, mesh->tetrahedra.num*sizeof(char)) );
  memset(edgeFlag, 0, mesh->tetrahedra.num*sizeof(char));

  delOptions->insertionFirst = mesh->vertices.num;

  #pragma omp parallel
  {
    const int threadID = omp_get_thread_num();
    size_t localNum = 0;

    #pragma omp for schedule(static)
    for (uint64_t tet=0; tet<mesh->tetrahedra.num; tet++) {
      if (getProcessedFlag(mesh, tet))
        continue;

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

        double* v0 = &mesh->vertices.coord[4*p0];
        double* v1 = &mesh->vertices.coord[4*p1];

        double s0 = delOptions->nodalSizes[p0];
        double s1 = delOptions->nodalSizes[p1];

        if(s0 <= 0.0 || s0==DBL_MAX ||
           s1 <= 0.0 || s1==DBL_MAX)
          continue;

        double l2 = square_dist(v0, v1);

        if(l2 <= 0.25*(s0 + s1)*(s0 + s1))
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
          // count the number of points that you can put on that edge
          double ds = s1 - s0;
          double dx = sqrt(l2);

          int n = log2(s1/s0)/log2((2*dx + ds)/(2*dx - ds));

          if(n > 2.0) {
            edgeFlag[tet] |= 1U<<edge;
            localNum += n-1;
          }
        }
      }
    }

    startPt[threadID] = localNum;

    #pragma omp barrier
    #pragma omp single
    {
      // exclusive scan used to compute starting indices
      int nthreads = omp_get_num_threads();
      size_t sum = 0;
      for (int i=0; i<nthreads; i++) {
        printf("thread %d creates %lu points\n", i, startPt[i]);
        size_t tsum = sum + startPt[i];
        startPt[i] = sum;
        sum = tsum;
      }

      mesh->vertices.num += sum;

      if(mesh->vertices.num > mesh->vertices.size){
        status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*mesh->vertices.num);
        if(status==HXT_STATUS_OK){
          status=hxtAlignedRealloc(&delOptions->nodalSizes, sizeof(double)*mesh->vertices.num);
          mesh->vertices.size = mesh->vertices.num;
        }
      }
    }

    if(status==HXT_STATUS_OK) {
      localNum = startPt[threadID] + delOptions->insertionFirst;

      #pragma omp for schedule(static)
      for (uint64_t tet=0; tet<mesh->tetrahedra.num; tet++) {
        for (unsigned edge=0; edge<6; edge++) {
          if(edgeFlag[tet] & (1U<<edge)){
            uint32_t p0, pn;
            {
              unsigned n0, nn;
              getNodesFromEdge(edge, &n0, &nn);
              p0 = mesh->tetrahedra.node[4*tet + n0];
              pn = mesh->tetrahedra.node[4*tet + nn];
            }

            double* v0 = &mesh->vertices.coord[4*p0];
            double* vn = &mesh->vertices.coord[4*pn];

            double s0 = delOptions->nodalSizes[p0];
            double sn = delOptions->nodalSizes[pn];

            double ds = sn - s0;
            double rs = sn/s0;
            double dx = sqrt(square_dist(v0, vn));

            int n = log2(rs)/log2((2*dx + ds)/(2*dx - ds));

            // subdivide the edge and create the new points
            for(int i=1; i<n; i++) {
              double si = pow(rs, (double) i/n) * s0;
              double alpha = (si - s0)/ds;

              mesh->vertices.coord[4 * localNum + 0] = (1.0 - alpha) * v0[0] + alpha * vn[0];
              mesh->vertices.coord[4 * localNum + 1] = (1.0 - alpha) * v0[1] + alpha * vn[1];
              mesh->vertices.coord[4 * localNum + 2] = (1.0 - alpha) * v0[2] + alpha * vn[2];
              mesh->vertices.coord[4 * localNum + 3] = si; // this is the precomputed nodalSize
              localNum++;
            }
          }
        }
      }
    }
  }

  if(status!=HXT_STATUS_OK){
    HXT_TRACE(status);
    return status;
  }

  HXT_CHECK( hxtFree(&startPt) );
  HXT_CHECK( hxtAlignedFree(&edgeFlag) );

  if(meshSizeFun!=NULL)
    HXT_CHECK( meshSizeFun(&mesh->vertices.coord[4*delOptions->insertionFirst], mesh->vertices.num - delOptions->insertionFirst, meshSizeData) );

  #pragma omp parallel for simd
  for(size_t i=delOptions->insertionFirst; i<mesh->vertices.num; i++) {
    delOptions->nodalSizes[i] = mesh->vertices.coord[4*i+3];
  }

  if(delOptions->insertionFirst == mesh->vertices.num)
      return HXT_STATUS_INTERNAL;

  delOptions->partitionability = 0.0;
  uint32_t oldNumVerticesInMesh = delOptions->numVerticesInMesh;

  HXT_CHECK(hxtDelaunay(mesh, delOptions));

  if (delOptions->numVerticesInMesh == oldNumVerticesInMesh) return HXT_STATUS_INTERNAL;

  return HXT_STATUS_OK;
}


HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                              HXTStatus (*meshSizeFun)(double* coord, size_t n,
                                                       void* meshSizeData),
                              void* meshSizeData)
{
  int maxThreads = omp_get_max_threads();

  {
    HXTStatus status = hxtRefineTetrahedraFirstPass(mesh, delOptions, meshSizeFun, meshSizeData);
    if(status==HXT_STATUS_INTERNAL)
      return HXT_STATUS_OK;
    else
      HXT_CHECK(status);
  }

  uint64_t* startTet; // see refineBalanceWork
  HXT_CHECK( hxtMalloc(&startTet, (maxThreads+1)*sizeof(size_t)) );

  uint32_t* startPt; // see refineBalanceWork
  HXT_CHECK( hxtMalloc(&startPt, (maxThreads+1)*sizeof(uint32_t)) );

  for(int iter=1; iter<42; iter++) {

    delOptions->insertionFirst = mesh->vertices.num;

    HXT_CHECK( refineBalanceWork(mesh, startPt, startTet, maxThreads) );
    uint32_t totNewPts = startPt[maxThreads];

    uint64_t* ptToTet;
    HXT_CHECK( hxtAlignedMalloc(&ptToTet, sizeof(uint64_t)*startPt[maxThreads]) );

    double* newVertices;
    HXT_CHECK( hxtAlignedMalloc(&newVertices, sizeof(double)*4*totNewPts) );

    // first step: compute all new points
    #pragma omp parallel
    {
      int threadID = omp_get_thread_num();
      uint32_t ptIndex = startPt[threadID];

      for(uint64_t i=startTet[threadID]; i<startTet[threadID+1]; i++) {
        if (getProcessedFlag(mesh, i))
          continue;

        setProcessedFlag(mesh, i); // we do not need to refine that tetrahedron anymore

        double p[4][4];
        double s[4];
        getTetCoordAndNodalSize(mesh, delOptions->nodalSizes, i, p, s);

        // TODO: do a SIMD getBestCenter function if it gets slow
        if(getBestCenter(p, s, &newVertices[4*ptIndex]) && meshSizeFun==NULL)
          newVertices[4*ptIndex+3] = -DBL_MAX;

#ifndef NDEBUG
        if(insphere(p[0], p[1], p[2], p[3], &newVertices[4*ptIndex])>=0.0)
          HXT_WARNING("new point is not in the circumsphere of the tet that spawned it");
#endif

        ptToTet[ptIndex] = i;
        ptIndex++;
      }
    }

    // second step (meshSizeFun): compute the effective mesh size at all these newly create points
    if(meshSizeFun!=NULL)
      HXT_CHECK( meshSizeFun(newVertices, totNewPts, meshSizeData) );


    HXTStatus status;
    // third step (filter): verify if they are not too close from the tet corners
    #pragma omp parallel
    {
      int threadID = omp_get_thread_num();

      // we don't really need startPt and startTet anymore because points have been created
      // we recycle startPt to count how many point will be kept for each thread after
      // the filtering
      startPt[threadID] = 0; 

      #pragma omp for schedule(static)
      for(size_t i=0; i<totNewPts; i++) {
        if(newVertices[4*i + 3] <= 0.0)
          continue;

        uint64_t tetID = ptToTet[i];
        double p[4][4];
        double s[4];
        getTetCoordAndNodalSize(mesh, delOptions->nodalSizes, tetID, p, s);

        double* vtaCoord = &newVertices[4*i];
        double vtaSize = newVertices[4*i + 3];

        if(is_too_close(s[0], vtaSize, square_dist(p[0], vtaCoord)) ||
           is_too_close(s[1], vtaSize, square_dist(p[1], vtaCoord)) ||
           is_too_close(s[2], vtaSize, square_dist(p[2], vtaCoord)) ||
           is_too_close(s[3], vtaSize, square_dist(p[3], vtaCoord))){
          newVertices[4*i + 3] = -DBL_MAX;
        }
        else {
          startPt[threadID]++;
        }
      }

      #pragma omp barrier
      #pragma omp single
      {
        int nthreads = omp_get_num_threads();
        uint32_t sum = 0;
        for (int t=0; t<nthreads; t++) {
          uint32_t tsum = sum + startPt[t];
          startPt[t] = sum;
          sum = tsum;
        }

        startPt[maxThreads] = sum;

        HXT_INFO_COND(delOptions->verbosity>1, "Refinement adds %u points from %" HXTu64 " tetrahedra", sum, mesh->tetrahedra.num);

        mesh->vertices.num += sum;

        status = hxtAlignedFree(&ptToTet);
        if(mesh->vertices.num > mesh->vertices.size){
          status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*mesh->vertices.num);
          if(status==HXT_STATUS_OK){
            status=hxtAlignedRealloc(&delOptions->nodalSizes, sizeof(double)*mesh->vertices.num);
            mesh->vertices.size = mesh->vertices.num;
          }
        }
      }

      size_t v = delOptions->insertionFirst + startPt[threadID];

      if(status==HXT_STATUS_OK){
        #pragma omp for schedule(static)
        for (uint64_t i=0; i<totNewPts; i++){
          if(newVertices[4*i + 3] <= 0.0)
            continue;
          mesh->vertices.coord[v*4  ] = newVertices[4*i + 0];
          mesh->vertices.coord[v*4+1] = newVertices[4*i + 1];
          mesh->vertices.coord[v*4+2] = newVertices[4*i + 2];
          delOptions->nodalSizes[v] = newVertices[4*i + 3];
          v++;
        }
      }
    }

    if(status!=HXT_STATUS_OK){
      HXT_TRACE(status);
      return status;
    }

    HXT_CHECK(hxtAlignedFree(&newVertices));

    if(delOptions->insertionFirst == mesh->vertices.num)
      break;

    delOptions->partitionability = 1.0 - pow(0.5, iter);
    uint32_t oldNumVerticesInMesh = delOptions->numVerticesInMesh;

    HXT_CHECK(hxtDelaunay(mesh, delOptions));

    if (delOptions->numVerticesInMesh == oldNumVerticesInMesh) break;
  }

  HXT_CHECK( hxtFree(&startTet) );
  HXT_CHECK( hxtFree(&startPt) );

  return HXT_STATUS_OK;
}
