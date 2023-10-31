#include "hxt_alphaUtils.h"
#include "predicates.h"
#include "hxt_tetFlag.h"


double tetrahedron_circumcenter(const double a[3], const double b[3], const double c[3], const double d[3], double circumcenter[3], double* xi, double* eta,double* zeta)
{
    double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  /* Use coordinates relative to point `a' of the tetrahedron. */
  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  /* Squares of lengths of the edges incident to `a'. */
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  /* Cross products of these edges. */
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  /* Calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
//   oriA = orient3d(pt[1], pt[2], pt[3], pt[4]);
//   const double xxx = robustPredicates::orient3d(b, c, d, a);
  const double xxx = orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  if(xi != (double *)NULL) {
    /* To interpolate a linear function at the circumcenter, define a    */
    /*   coordinate system with a xi-axis directed from `a' to `b',      */
    /*   an eta-axis directed from `a' to `c', and a zeta-axis directed  */
    /*   from `a' to `d'.  The values for xi, eta, and zeta are computed */
    /*   by Cramer's Rule for solving systems of linear equations.       */
    *xi = (xcirca * xcrosscd + ycirca * ycrosscd + zcirca * zcrosscd) *
          (2.0 * denominator);
    *eta = (xcirca * xcrossdb + ycirca * ycrossdb + zcirca * zcrossdb) *
           (2.0 * denominator);
    *zeta = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
            (2.0 * denominator);
  }

  double R;
  if (xxx > 1e-6) // avoid inserting points in sliver tetrahedra
    R = sqrt ((a[0]-circumcenter[0])*(a[0]-circumcenter[0])+(a[1]-circumcenter[1])*(a[1]-circumcenter[1])+(a[2]-circumcenter[2])*(a[2]-circumcenter[2]));
  else
    R = -DBL_MAX;
  return R;
}

double tetAlphaShape(HXTMesh* mesh, const int *tet, const double h){
    double *p0 = &mesh->vertices.coord[4*tet[0]];
    double *p1 = &mesh->vertices.coord[4*tet[1]];
    double *p2 = &mesh->vertices.coord[4*tet[2]];
    double *p3 = &mesh->vertices.coord[4*tet[3]];
    // printf("points : (%f, %f, %f), (%f, %f, %f), (%f, %f, %f), (%f, %f, %f) \n", p0[0], p0[1], p0[2], p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p3[0], p3[1], p3[2]);
    double a[3] = {p0[0], p0[1], p0[2]};
    double b[3] = {p1[0], p1[1], p1[2]};
    double c[3] = {p2[0], p2[1], p2[2]};
    double d[3] = {p3[0], p3[1], p3[2]};
    double C[3], xi, eta, zeta;
    double R = tetrahedron_circumcenter(a, b, c, d, C, &xi, &eta, &zeta);
    // printf("circumcenter : (%f, %f, %f); circumradius : %f \n", C[0], C[1], C[2], R);
    if (R < 0.)
      R = sqrt ((p0[0]-C[0])*(p0[0]-C[0])+(p0[1]-C[1])*(p0[1]-C[1])+(p0[2]-C[2])*(p0[2]-C[2]));
    return R/h;
}

int pointInTetrahedron(double *p0, double* p1, double *p2, double *p3, double *c){
    // printf("p0 : %f, %f, %f \n", p0[0], p0[1], p0[2]);
    // printf("p1 : %f, %f, %f \n", p1[0], p1[1], p1[2]);
    // printf("p2 : %f, %f, %f \n", p2[0], p2[1], p2[2]);
    // printf("p3 : %f, %f, %f \n", p3[0], p3[1], p3[2]);
    // printf("c : %f, %f, %f \n", c[0], c[1], c[2]);

    // printf("orient 0 : %f \n", orient3d(p0, p1, p2, c));
    // printf("orient 1 : %f \n", orient3d(p1, p3, p2, c));
    // printf("orient 2 : %f \n", orient3d(p0, p3, p1, c));
    // printf("orient 3 : %f \n", orient3d(p0, p2, p3, c));
    // if (orient3d(p0, p1, p2, c) <= 0) return 0;
    // if (orient3d(p1, p3, p2, c) <= 0) return 0;
    // if (orient3d(p0, p3, p1, c) <= 0) return 0;
    // if (orient3d(p0, p2, p3, c) <= 0) return 0;
    // return 1;
    // double res0 = orient3d(p0, p1, p2, p3, c);
    // double res0 = orient3d(p0, p1, p2, p3, c);
    // double res0 = orient3d(p0, p1, p2, p3, c);
    // double v0[3], v1[3], v2[3], v3[3];
    // for (int i=0; i<3; i++){
    //     v0[i] = p0[i] - c[i];
    //     v1[i] = p1[i] - c[i];
    //     v2[i] = p2[i] - c[i];
    //     v3[i] = p3[i] - c[i];
    // }
    // double n0[3], n1[3], n2[3], n3[3];
    // cross(v0, v1, n0);
    // cross(v1, v2, n1);
    // cross(v2, v3, n2);
    // cross(v3, v0, n3);
    // double d0 = dot(n0, n1);
    // double d1 = dot(n1, n2);
    // double d2 = dot(n2, n3);
    // double d3 = dot(n3, n0);
    // if (d0*d1*d2*d3 < 0) return 0;
    // return 1;

    // double avg = 0.0;
    // double num = 0;
    // for(int i=0; i<4; i++) {
    //   double size = nodalSize[i];
    //   if(size>0.0) {
    //     avg += size;
    //     num+=1.0;
    //   }
    // }

    // if(num==0) {
    //   HXT_WARNING("tetrahedron with undefined size");
    //   avg = 1.0;
    // }
    // else {
    //   avg /= num;
    // }

    // double s0 = nodalSize[0]>0.0 ? nodalSize[0] : avg;
    // double s1 = nodalSize[1]>0.0 ? nodalSize[1] : avg;
    // double s2 = nodalSize[2]>0.0 ? nodalSize[2] : avg;
    // double s3 = nodalSize[3]>0.0 ? nodalSize[3] : avg;

    // (e/s)^2  (e is the norm of the edge, s is the mean nodalSize over that edge)
    double e0l2 = squareDist(p0, p1); ///(0.25*(s0 + s1)*(s0 + s1));
    double e1l2 = squareDist(p0, p2); ///(0.25*(s0 + s2)*(s0 + s2));
    double e2l2 = squareDist(p0, p3); ///(0.25*(s0 + s3)*(s0 + s3));
    double e3l2 = squareDist(p1, p2); ///(0.25*(s1 + s2)*(s1 + s2));
    double e4l2 = squareDist(p1, p3); ///(0.25*(s1 + s3)*(s1 + s3));
    double e5l2 = squareDist(p2, p3); ///(0.25*(s2 + s3)*(s2 + s3));

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

    // int circumcenterOutside = 0;
    // int circumcenterTooClose = 0;
    if(bary0>0.0 && bary1>0.0 && bary2>0.0 && bary3>0.0) {
      return 1;
      //   // compute the cartesian coordinates from the barycentric ones
      // center[0] = bary0*p[0][0] + bary1*p[1][0] + bary2*p[2][0] + bary3*p[3][0];
      // center[1] = bary0*p[0][1] + bary1*p[1][1] + bary2*p[2][1] + bary3*p[3][1];
      // center[2] = bary0*p[0][2] + bary1*p[1][2] + bary2*p[2][2] + bary3*p[3][2];
      // center[3] = bary0*s0 + bary1*s1 + bary2*s2 + bary3*s3; // the interpolated nodalSize

      // circumcenterTooClose = (
      //   isTooClose(s0, center[3], squareDist(p[0], center), ns) ||
      //   isTooClose(s1, center[3], squareDist(p[1], center), ns) ||
      //   isTooClose(s2, center[3], squareDist(p[2], center), ns) ||
      //   isTooClose(s3, center[3], squareDist(p[3], center), ns)
      // );
    }
    // else { // we should also enter this if a bary is not finite
    return 0;
    // }
}

double computeTetMeshSize(HXTMesh* mesh, HXTDelaunayOptions* delOptions, uint32_t *_tet){
    double h = 0.;
    for (int i=0; i<4; i++){
        h += delOptions->nodalSizes->array[_tet[i]]/4.;
    }
    return h;
}

/* just fill tetCoord and tetNodalSize with the coordinates and nodal size of each node of
 * tetrahedron tet */
void getTetCoordAndNodalSize(HXTMesh* mesh, double* nsarray, uint64_t tet,
                                           double tetCoord[4][4], double tetNodalSize[4])
{
  uint32_t* nodes = &mesh->tetrahedra.node[4*tet];
  for(int i=0; i<4; i++) {
    tetCoord[i][0] = mesh->vertices.coord[4 * nodes[i] + 0];
    tetCoord[i][1] = mesh->vertices.coord[4 * nodes[i] + 1];
    tetCoord[i][2] = mesh->vertices.coord[4 * nodes[i] + 2];
    if (nsarray != NULL)
      tetNodalSize[i] = nsarray[nodes[i]];
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

// for parallel implementation 
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
 *  - startTet[maxThreads] = alphaShapeOptions->n_tetrahedra
 *  - `startPt[t+1] - startPt[t]` gives how many point will be created by thread t
 */
HXTStatus balanceRefineWorkInAlphaShape(HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, uint32_t* startPt, size_t* startTet, int maxThreads)
{
  size_t* scan;
  uint32_t ptPerThreadGoal;
  HXT_CHECK( hxtAlignedMalloc(&scan, sizeof(size_t) * alphaShapeOptions->n_tetrahedra) );

  #pragma omp parallel num_threads(maxThreads)
  {
    int threadID = omp_get_thread_num();

    startPt[threadID] = 0;
    #pragma omp for
    for(uint64_t i=0; i<alphaShapeOptions->n_tetrahedra; i++) {
      scan[i] = getProcessedFlag(mesh, alphaShapeOptions->tetrahedra[i])==0;
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
    for(uint64_t i=0; i<alphaShapeOptions->n_tetrahedra; i++) {
      size_t inc = scan[i];
      scan[i] = s;
      s += inc;
    }
    size_t scanToFind = threadID * ptPerThreadGoal;

    // we want to find i such that scan[i] = scanToFind.
    // we do a simple binary search in the prefix scan array to find `i`
    size_t* pfnd = scanbsearch(scan, scanToFind, mesh->tetrahedra.num);
    startTet[threadID] = pfnd  - scan;
    if(startTet[threadID] < alphaShapeOptions->n_tetrahedra)
      startPt[threadID] = *pfnd;
    else
      startPt[threadID] = startPt[maxThreads];
  }
  HXT_CHECK( hxtAlignedFree(&scan) );

  startTet[maxThreads] = alphaShapeOptions->n_tetrahedra;

  return HXT_STATUS_OK;
}

void cross(double* v0, double* v1, double *res){
    res[0] = v0[1]*v1[2] - v0[2]*v1[1];
    res[1] = v0[2]*v1[0] - v0[0]*v1[2];
    res[2] = v0[0]*v1[1] - v0[1]*v1[0];
}

double dot(double* v0, double* v1){
    return v0[0]*v1[0] + v0[1]*v1[1] + v0[2]*v1[2];
}

void triangleCircumCenter(double* p0, double* p1, double* p2, double* c){
    double v0[3], v1[3], v2[3];
    for (int i=0; i<3; i++){
        v0[i] = p1[i] - p0[i];
        v1[i] = p2[i] - p0[i];
    }
    double v0norm2 = v0[0]*v0[0]+v0[1]*v0[1]+v0[2]*v0[2];
    double v1norm2 = v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2];
    double n0[3], n1[3];
    cross(v0, v1, n0);
    cross(v1, v0, n1);
    double n0norm2 = n0[0]*n0[0]+n0[1]*n0[1]+n0[2]*n0[2];
    double n0cv0[3], n1cv1[3];
    cross(n0, v0, n0cv0);
    cross(n1, v1, n1cv1);
    for (int i=0; i<3; i++){
        c[i] = p0[i] + 0.5*(v1norm2*n0cv0[i] + v0norm2*n1cv1[i])/n0norm2;
    }
}

void getTetVertices(HXTMesh* mesh, uint64_t tet, double pTet[4][3]){
    uint32_t* nodes = &mesh->tetrahedra.node[4*tet];
    for(int i=0; i<4; i++) {
        pTet[i][0] = mesh->vertices.coord[4 * nodes[i] + 0];
        pTet[i][1] = mesh->vertices.coord[4 * nodes[i] + 1];
        pTet[i][2] = mesh->vertices.coord[4 * nodes[i] + 2];
    }
}

uint64_t findPointInNeighbouringTets(HXTMesh* mesh, uint64_t tet, double* p){
    for (uint64_t i=0; i<4; i++){
        uint64_t currNeigh = mesh->tetrahedra.neigh[4*tet+i]/4;
        if (mesh->tetrahedra.color[currNeigh] == HXT_COLOR_OUT) continue;
        double pTet[4][3];
        getTetVertices(mesh, currNeigh, pTet);
        // getTetCoordAndNodalSize(mesh, NULL, currNeigh, pTet, NULL);
        if (pointInTetrahedron(pTet[0], pTet[1], pTet[2], pTet[3], p)==1) return currNeigh;
        for (uint64_t j=0; j<4; j++){
            uint64_t currNeighNeigh = mesh->tetrahedra.neigh[4*currNeigh+j]/4;
            if (mesh->tetrahedra.color[currNeighNeigh] == HXT_COLOR_OUT) continue;
            double pTetNeigh[4][3];
            // getTetCoordAndNodalSize(mesh, NULL, currNeighNeigh, pTetNeigh, NULL);
            getTetVertices(mesh, currNeighNeigh, pTetNeigh);
            if (pointInTetrahedron(pTetNeigh[0], pTetNeigh[1], pTetNeigh[2], pTetNeigh[3], p)==1) return currNeighNeigh;
        }
    }
    // printf("did not find point in neighbors ... \n");
    return -1;
}

