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
#include "hxt_omp.h"

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


/* the point with barycentric coord (h0,h1,h2,h3) */
// static void isotomicConjugateOfIncenter(double p[4][4], double bary[4])
// {
//   /* Use coordinates relative to point `p[0]' of the tetrahedron. */
//   double xa = p[1][0] - p[0][0];
//   double ya = p[1][1] - p[0][1];
//   double za = p[1][2] - p[0][2];
//   double xb = p[2][0] - p[0][0];
//   double yb = p[2][1] - p[0][1];
//   double zb = p[2][2] - p[0][2];
//   double xc = p[3][0] - p[0][0];
//   double yc = p[3][1] - p[0][1];
//   double zc = p[3][2] - p[0][2];
  
//   /* Cross products of these edges. */
//   double xcrossbc = yb * zc - yc * zb;
//   double ycrossbc = zb * xc - zc * xb;
//   double zcrossbc = xb * yc - xc * yb;
//   double xcrossca = yc * za - ya * zc;
//   double ycrossca = zc * xa - za * xc;
//   double zcrossca = xc * ya - xa * yc;
//   double xcrossab = ya * zb - yb * za;
//   double ycrossab = za * xb - zb * xa;
//   double zcrossab = xa * yb - xb * ya;

//   // get the cross product corresponding to the last face: (c-a)x(a-b)
//   // the sum of the cross product of the faces of a tetrahedron = 0
//   double xsumcros = xcrossab + xcrossbc + xcrossca;
//   double ysumcros = ycrossab + ycrossbc + ycrossca;
//   double zsumcros = zcrossab + zcrossbc + zcrossca;

//   double invA0x2 = 1.0/sqrt(xsumcros*xsumcros + ysumcros*ysumcros + zsumcros*zsumcros); // (2 x area of the facet opposite to p0)^-1
//   double invA1x2 = 1.0/sqrt(xcrossbc*xcrossbc + ycrossbc*ycrossbc + zcrossbc*zcrossbc); // (2 x area of the facet opposite to p1)^-1
//   double invA2x2 = 1.0/sqrt(xcrossca*xcrossca + ycrossca*ycrossca + zcrossca*zcrossca); // (2 x area of the facet opposite to p2)^-1
//   double invA3x2 = 1.0/sqrt(xcrossab*xcrossab + ycrossab*ycrossab + zcrossab*zcrossab); // (2 x area of the facet opposite to p3)^-1

//   double AsumInv = invA0x2 + invA1x2 + invA2x2 + invA3x2;

//   bary[0] = 0.125 + 0.5 * invA0x2 / AsumInv;
//   bary[1] = 0.125 + 0.5 * invA1x2 / AsumInv;
//   bary[2] = 0.125 + 0.5 * invA2x2 / AsumInv;
//   // bary[3] = 0.125 + 0.5 * invA3x2 / AsumInv;
//   bary[3] = 1.0 - bary[0] - bary[1] - bary[2];
// }


// static void hxtTetCircumcenter(double p[4][4], double center[3], double bary[4])
// {
//   /* Use coordinates relative to point `p[0]' of the tetrahedron. */
//   double xa = p[1][0] - p[0][0];
//   double ya = p[1][1] - p[0][1];
//   double za = p[1][2] - p[0][2];
//   double xb = p[2][0] - p[0][0];
//   double yb = p[2][1] - p[0][1];
//   double zb = p[2][2] - p[0][2];
//   double xc = p[3][0] - p[0][0];
//   double yc = p[3][1] - p[0][1];
//   double zc = p[3][2] - p[0][2];

//    Squares of lengths of the edges incident to `p[0]'. 
//   double alength = xa * xa + ya * ya + za * za;
//   double blength = xb * xb + yb * yb + zb * zb;
//   double clength = xc * xc + yc * yc + zc * zc;

//   /* Cross products of these edges. */
//   double xcrossbc = yb * zc - yc * zb;
//   double ycrossbc = zb * xc - zc * xb;
//   double zcrossbc = xb * yc - xc * yb;
//   double xcrossca = yc * za - ya * zc;
//   double ycrossca = zc * xa - za * xc;
//   double zcrossca = xc * ya - xa * yc;
//   double xcrossab = ya * zb - yb * za;
//   double ycrossab = za * xb - zb * xa;
//   double zcrossab = xa * yb - xb * ya;

//   /* calculate the denominator of the formulae. */
//   /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
//   /*   to ensure a correctly signed (and reasonably accurate) result, */
//   /*   avoiding any possibility of division by zero.                  */
//   double xxx = xa * xcrossbc + ya * ycrossbc + za * zcrossbc;
//   int sureSign = (xxx > o3dstaticfilter) - (xxx < -o3dstaticfilter);
//   if(sureSign==0)
//     xxx = orient3d(p[1], p[2], p[3], p[0]);
//   double denominator = 0.5 / xxx;
  

//   /* Calculate offset (from `p[0]') of circumcenter. */
//   double xcirca = (alength * xcrossbc + blength * xcrossca + clength * xcrossab) *
//                   denominator;
//   double ycirca = (alength * ycrossbc + blength * ycrossca + clength * ycrossab) *
//                   denominator;
//   double zcirca = (alength * zcrossbc + blength * zcrossca + clength * zcrossab) *
//                   denominator;
//   center[0] =  xcirca + p[0][0];
//   center[1] =  ycirca + p[0][1];
//   center[2] =  zcirca + p[0][2];

//   if (bary != NULL) {
//     /* To interpolate a linear function at the circumcenter, define a    */
//     /*   coordinate system with a bary0-axis directed from `p[0]' to `p[1]',      */
//     /*   an bary1-axis directed from `p[0]' to `p[2]', and a bary2-axis directed  */
//     /*   from `p[0]' to `p[3]'.  The values for bary0, bary1, and bary2 are computed */
//      /*   by Cramer's Rule for solving systems of linear equations.       */
//     bary[0] = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
//               (2.0 * denominator);
//     bary[1] = (xcirca * xcrossca + ycirca * ycrossca + zcirca * zcrossca) *
//               (2.0 * denominator);
//     bary[2] = (xcirca * xcrossab + ycirca * ycrossab + zcirca * zcrossab) *
//               (2.0 * denominator);
//     bary[3] = 1.0 - bary[0] - bary[1] - bary[2];
//   }
//   // return xxx; // return 6 times volume
// }


static void getBestCenter(double p[4][4], double nodalSize[4], double center[3], double bary[4])
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

  double s0 = nodalSize[0]!=DBL_MAX && nodalSize[0] ? nodalSize[0] : avg;
  double s1 = nodalSize[1]!=DBL_MAX && nodalSize[1] ? nodalSize[1] : avg;
  double s2 = nodalSize[2]!=DBL_MAX && nodalSize[2] ? nodalSize[2] : avg;
  double s3 = nodalSize[3]!=DBL_MAX && nodalSize[3] ? nodalSize[3] : avg;

  double sa = s0/(s0 + s1); // 2/s0 x mean size of the edge a
  double sb = s0/(s0 + s2);
  double sc = s0/(s0 + s3);

  /* Use coordinates relative to point `p[0]' of the tetrahedron. */
  double xa = (p[1][0] - p[0][0])*sa;
  double ya = (p[1][1] - p[0][1])*sa;
  double za = (p[1][2] - p[0][2])*sa;
  double xb = (p[2][0] - p[0][0])*sb;
  double yb = (p[2][1] - p[0][1])*sb;
  double zb = (p[2][2] - p[0][2])*sb;
  double xc = (p[3][0] - p[0][0])*sc;
  double yc = (p[3][1] - p[0][1])*sc;
  double zc = (p[3][2] - p[0][2])*sc;

  /* Squares of lengths of the edges incident to `p[0]'. */
  double alength = xa * xa + ya * ya + za * za;
  double blength = xb * xb + yb * yb + zb * zb;
  double clength = xc * xc + yc * yc + zc * zc;

  /* Cross products of these edges. */
  double xcrossbc = yb * zc - yc * zb;
  double ycrossbc = zb * xc - zc * xb;
  double zcrossbc = xb * yc - xc * yb;
  double xcrossca = yc * za - ya * zc;
  double ycrossca = zc * xa - za * xc;
  double zcrossca = xc * ya - xa * yc;
  double xcrossab = ya * zb - yb * za;
  double ycrossab = za * xb - zb * xa;
  double zcrossab = xa * yb - xb * ya;

  /* calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
  double xxx = xa * xcrossbc + ya * ycrossbc + za * zcrossbc;
  double denominator = 0.5 / xxx;
  

  /* Calculate offset (from `p[0]') of circumcenter. */
  double xcirca = (alength * xcrossbc + blength * xcrossca + clength * xcrossab) *
                  denominator;
  double ycirca = (alength * ycrossbc + blength * ycrossca + clength * ycrossab) *
                  denominator;
  double zcirca = (alength * zcrossbc + blength * zcrossca + clength * zcrossab) *
                  denominator;

  /* To interpolate a linear function at the circumcenter, define a    */
  /*   coordinate system with a bary0-axis directed from `p[0]' to `p[1]',      */
  /*   an bary1-axis directed from `p[0]' to `p[2]', and a bary2-axis directed  */
  /*   from `p[0]' to `p[3]'.  The values for bary0, bary1, and bary2 are computed */
   /*   by Cramer's Rule for solving systems of linear equations.       */
  bary[0] = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
            (2.0 * denominator);
  bary[1] = (xcirca * xcrossca + ycirca * ycrossca + zcirca * zcrossca) *
            (2.0 * denominator);
  bary[2] = (xcirca * xcrossab + ycirca * ycrossab + zcirca * zcrossab) *
            (2.0 * denominator);
  bary[3] = 1.0 - bary[0] - bary[1] - bary[2];

  /* if we are outside the tet, we get back inside, by using the isotomic conjugate of the incenter
   * instead of the circumcenter.
   * We also want to recalculate a new center if any bary is NAN. Because comparison with NAN evaluate
   *  to false, we need to build our comparison backwards and negate it... */
  if(!(bary[0]>0.0 && bary[1]>0.0 && bary[2]>0.0 && bary[3]>0.0)) {
    /* get the cross product corresponding to the last face: (c-a)x(a-b) */
    /* the sum of the cross product of the faces of a tetrahedron = 0 */
    double xsumcros = xcrossab + xcrossbc + xcrossca;
    double ysumcros = ycrossab + ycrossbc + ycrossca;
    double zsumcros = zcrossab + zcrossbc + zcrossca;

    double invA0x2 = 1.0/sqrt(xsumcros*xsumcros + ysumcros*ysumcros + zsumcros*zsumcros); /* (2 x area of the facet opposite to p0)^-1 */
    double invA1x2 = 1.0/sqrt(xcrossbc*xcrossbc + ycrossbc*ycrossbc + zcrossbc*zcrossbc); /* (2 x area of the facet opposite to p1)^-1 */
    double invA2x2 = 1.0/sqrt(xcrossca*xcrossca + ycrossca*ycrossca + zcrossca*zcrossca); /* (2 x area of the facet opposite to p2)^-1 */
    double invA3x2 = 1.0/sqrt(xcrossab*xcrossab + ycrossab*ycrossab + zcrossab*zcrossab); /* (2 x area of the facet opposite to p3)^-1 */

    double x75_den = invA0x2 + invA1x2 + invA2x2 + invA3x2;

    const double alpha = 0.5;

    bary[0] = (1.0 - alpha)*0.25 + alpha*invA0x2/x75_den;
    bary[1] = (1.0 - alpha)*0.25 + alpha*invA1x2/x75_den;
    bary[2] = (1.0 - alpha)*0.25 + alpha*invA2x2/x75_den;
    bary[3] = (1.0 - alpha)*0.25 + alpha*invA3x2/x75_den;
  }

  // compute the cartesian coordinates from the barycentric ones
  center[0] = bary[0]*p[0][0] + bary[1]*p[1][0] + bary[2]*p[2][0] + bary[3]*p[3][0];
  center[1] = bary[0]*p[0][1] + bary[1]*p[1][1] + bary[2]*p[2][1] + bary[3]*p[3][1];
  center[2] = bary[0]*p[0][2] + bary[1]*p[1][2] + bary[2]*p[2][2] + bary[3]*p[3][2];
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


/* receives the 4 nodalSize of the node of a tet, as well as the barycentric
 * coordinates of a point in the tet, and estimate the nodalSize at that point */
static inline double getNodalSizeFromBary(double* nodalSize, double* bary)
{
  double denom = 0.0;
  double num = 0.0;
  int ndef = 0;
  for (int j=0;j<4;j++){
    double size = nodalSize[j];
    if (size != DBL_MAX){
      double weight = bary[j];
      denom += weight;
      num += weight * size;
    }
    else {
      ndef++;
    }
  }

  if(ndef!=4) {
    return num/denom;
  }
  else {
    HXT_WARNING("tetrahedron with undefined size");
    return DBL_MAX;
  }
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
 *  - `startPt[t+1] - startPt[t]` gives how many point will be create by thread t
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


HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                              HXTStatus (*meshSizeFun)(double* coord, size_t n,
                                                       void* meshSizeData),
                              void* meshSizeData)
{
  int maxThreads = omp_get_max_threads();

  uint64_t* startTet; // see refineBalanceWork
  HXT_CHECK( hxtMalloc(&startTet, (maxThreads+1)*sizeof(size_t)) );

  uint32_t* startPt; // see refineBalanceWork
  HXT_CHECK( hxtMalloc(&startPt, (maxThreads+1)*sizeof(uint32_t)) );

  for(int iter=0; iter<42; iter++) {

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
        double bary[4];
        getBestCenter(p, s, &newVertices[4*ptIndex], bary);

// // #ifdef DEBUG
//         if(insphere(p[0], p[1], p[2], p[3], &newVertices[4*ptIndex])>=0.0)
//           HXT_WARNING("the added point is not even in the circumsphere %.12g", orient3d(p[0], p[1], p[2], p[3]));
// // #endif

        ptToTet[ptIndex] = i;

        if(meshSizeFun==NULL) /* we could compute it anyway. TODO: vectorize */
          newVertices[4*ptIndex+3] = getNodalSizeFromBary(s, bary);

        ptIndex++;
      }
    }

    // second step (meshSizeFun): compute the mesh size at all these newly create points
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
        uint64_t tetID = ptToTet[i];
        // if(tetID==HXT_NO_ADJACENT) {
        //   newVertices[4*i + 3] = -DBL_MAX;
        //   continue;
        // }
        double p[4][4];
        double s[4];
        getTetCoordAndNodalSize(mesh, delOptions->nodalSizes, tetID, p, s);

        double* vtaCoord = &newVertices[4*i];
        double vtaSize = newVertices[4*i + 3];

        if(is_too_close(s[0], vtaSize, square_dist(p[0], vtaCoord)) ||
           is_too_close(s[1], vtaSize, square_dist(p[1], vtaCoord)) ||
           is_too_close(s[2], vtaSize, square_dist(p[2], vtaCoord)) ||
           is_too_close(s[3], vtaSize, square_dist(p[3], vtaCoord)) ||
           newVertices[4*i + 3] < 0.0){
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

        HXT_INFO_COND(delOptions->verbosity>1, "Refinement adds %u points", sum);

        mesh->vertices.num += sum;

        status = hxtAlignedFree(&ptToTet);
        if(mesh->vertices.num > mesh->vertices.size){
          status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*mesh->vertices.num);
          if(status==HXT_STATUS_OK){
            status=hxtAlignedRealloc(&delOptions->nodalSizes, mesh->vertices.num*sizeof(double));
            mesh->vertices.size = mesh->vertices.num;
          }
        }
      }

      size_t v = delOptions->insertionFirst + startPt[threadID];

      if(status==HXT_STATUS_OK){
        #pragma omp for schedule(static)
        for (uint64_t i=0; i<totNewPts; i++){
          if(newVertices[4*i + 3] != -DBL_MAX) {
            mesh->vertices.coord[v*4  ] = newVertices[4*i + 0];
            mesh->vertices.coord[v*4+1] = newVertices[4*i + 1];
            mesh->vertices.coord[v*4+2] = newVertices[4*i + 2];
            delOptions->nodalSizes[v] = newVertices[4*i + 3];
            v++;
          }
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
