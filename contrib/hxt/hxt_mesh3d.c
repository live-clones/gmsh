// #include "hxt_mesh_size.h"
#include "hxt_tetDelaunay.h"
// #include "hxt_vertices.h"
#include "hxt_mesh3d.h"
#include "predicates.h"
#include "hxt_tetFlag.h"

// #if defined(_MSC_VER)
// #define _CRT_RAND_S 
// #include <stdlib.h> 
// double drand48() {
//   double a;
//   rand_s(&a);
//   return a;
// }
// #endif

HXTStatus hxtCreateNodalSizeFromFunction(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                                         double (*mesh_size)(double x, double y, double z, void* userData),
                                         void* userData)
{
  HXT_CHECK(hxtAlignedMalloc(&delOptions->nodalSizes,mesh->vertices.num*sizeof(double)));

  #pragma omp parallel for
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    double* coord = &mesh->vertices.coord[4*i];
    delOptions->nodalSizes[i] = mesh_size(coord[0], coord[1], coord[2], userData);
  }

  return HXT_STATUS_OK;
}


HXTStatus hxtCreateNodalsizeFromTrianglesAndLines(HXTMesh* mesh, HXTDelaunayOptions* delOptions)
{

  HXT_CHECK(hxtAlignedMalloc(&delOptions->nodalSizes,mesh->vertices.num*sizeof(double))); 
  
  #pragma omp parallel for
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    delOptions->nodalSizes[i] = DBL_MAX;
  }

  // only do for triangles
  // we do not take into account hereafter delOptions->nodalSizes = to DBL_MAX
  // could be changed in another fashion
  for (uint32_t i = 0; i<mesh->triangles.num; i++){
    for (uint32_t j = 0; j<3; j++){  
      for (uint32_t k = j+1; k<3; k++){  
        uint32_t n1 = mesh->triangles.node[3*i+j];
        uint32_t n2 = mesh->triangles.node[3*i+k];
        if (n1 != HXT_GHOST_VERTEX && n2 != HXT_GHOST_VERTEX){
          double *X1 = mesh->vertices.coord + (size_t) 4*n1;
          double *X2 = mesh->vertices.coord + (size_t) 4*n2;
          double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                           (X1[1]-X2[1])*(X1[1]-X2[1])+
                           (X1[2]-X2[2])*(X1[2]-X2[2]));
          if(l<delOptions->nodalSizes[n1]) delOptions->nodalSizes[n1] = l;
          if(l<delOptions->nodalSizes[n2]) delOptions->nodalSizes[n2] = l;
        }
      }
    }
  }

  for (uint32_t i = 0; i<mesh->lines.num; i++){
      uint32_t n1 = mesh->lines.node[2*i+0];
      uint32_t n2 = mesh->lines.node[2*i+1];
      if (n1 != HXT_GHOST_VERTEX && n2 != HXT_GHOST_VERTEX){
        double *X1 = mesh->vertices.coord + (size_t) 4*n1;
        double *X2 = mesh->vertices.coord + (size_t) 4*n2;
        double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                         (X1[1]-X2[1])*(X1[1]-X2[1])+
                         (X1[2]-X2[2])*(X1[2]-X2[2]));
        if(l<delOptions->nodalSizes[n1]) delOptions->nodalSizes[n1] = l;
        if(l<delOptions->nodalSizes[n2]) delOptions->nodalSizes[n2] = l;
    }
  }
  return HXT_STATUS_OK;    
}

HXTStatus hxtCreateNodalsizeFromMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions)
{

  HXT_CHECK(hxtAlignedMalloc(&delOptions->nodalSizes,mesh->vertices.num*sizeof(double))); 
  
  #pragma omp parallel for
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    delOptions->nodalSizes[i] = DBL_MAX;
  }

  // only do for triangles
  // we do not take into account hereafter delOptions->nodalSizes = to DBL_MAX
  // could be changed in another fashion
  for (uint32_t i = 0; i<mesh->tetrahedra.num; i++){
    for (uint32_t j = 0; j<4; j++){  
      for (uint32_t k = j+1; k<4; k++){  
        uint32_t n1 = mesh->tetrahedra.node[4*i+j];
        uint32_t n2 = mesh->tetrahedra.node[4*i+k];
        if (n1 != HXT_GHOST_VERTEX && n2 != HXT_GHOST_VERTEX){
          double *X1 = mesh->vertices.coord + (size_t) 4*n1;
          double *X2 = mesh->vertices.coord + (size_t) 4*n2;
          double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
               (X1[1]-X2[1])*(X1[1]-X2[1])+
               (X1[2]-X2[2])*(X1[2]-X2[2]));
          if(l<delOptions->nodalSizes[n1]) delOptions->nodalSizes[n1] = l;
          if(l<delOptions->nodalSizes[n2]) delOptions->nodalSizes[n2] = l;
        }
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtDestroyNodalsize(HXTDelaunayOptions* delOptions)
{
  HXT_CHECK( hxtAlignedFree(&delOptions->nodalSizes) );
  return HXT_STATUS_OK;
}




HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions)
{
// we assume that the input is a surface mesh
  if (mesh->tetrahedra.num)  
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should only contain triangles");
  if (mesh->triangles.num == 0)  
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should contain triangles");

  double minDist2 = DBL_MAX;
  #pragma omp parallel for reduction(min:minDist2)
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t* node = mesh->triangles.node + 3*i;
    for (int j=0; j<3; j++) {
      double* n1 = mesh->vertices.coord + (size_t) 4*node[j];
      double* n2 = mesh->vertices.coord + (size_t) 4*node[(j+1)%3];

      double dist2 = (n1[0]-n2[0])*(n1[0]-n2[0])
                   + (n1[1]-n2[1])*(n1[1]-n2[1])
                   + (n1[2]-n2[2])*(n1[2]-n2[2]);

      if(dist2<minDist2)
        minDist2 = dist2;
    }
  }

  double minSize = sqrt(minDist2);

  hxtNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(hxtNodeInfo)*mesh->vertices.num) );

  #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    nodeInfo[i].node = i;
    nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
  }

  delOptions->minSizeStart = 0.0;
  delOptions->minSizeEnd = minSize;
  HXT_CHECK( hxtDelaunaySteadyVertices(mesh, delOptions, nodeInfo, mesh->vertices.num) );
  delOptions->minSizeStart = minSize;
  delOptions->minSizeEnd = minSize;
  delOptions->numVerticesInMesh = mesh->vertices.num;

#ifdef DEBUG
  #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    if(nodeInfo[i].status!=HXT_STATUS_TRUE){
      HXT_WARNING("vertex %u of the empty mesh was not inserted\n", nodeInfo[i].node);
    }
  }
#endif

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );
  
  return HXT_STATUS_OK;
}



// refine 


double hxtTetCircumcenter(double a[3], double b[3], double c[3], double d[3],
                            double circumcenter[3], double *xi, double *eta, double *zeta)
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
  const double xxx =  orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
    denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
    denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
    denominator;
  circumcenter[0] =  xcirca + a[0];
  circumcenter[1] =  ycirca + a[1];
  circumcenter[2] =  zcirca + a[2];

  /*
 printf(" %g %g %g %g\n",
         sqrt((a[0]-xcirca)*(a[0]-xcirca)+(a[1]-ycirca)*(a[1]-ycirca)+(a[2]-zcirca)*(a[2]-zcirca)),
         sqrt((b[0]-xcirca)*(b[0]-xcirca)+(b[1]-ycirca)*(b[1]-ycirca)+(b[2]-zcirca)*(b[2]-zcirca)),
         sqrt((c[0]-xcirca)*(c[0]-xcirca)+(c[1]-ycirca)*(c[1]-ycirca)+(c[2]-zcirca)*(c[2]-zcirca)),
         sqrt((d[0]-xcirca)*(d[0]-xcirca)+(d[1]-ycirca)*(d[1]-ycirca)+(d[2]-zcirca)*(d[2]-zcirca)) );
  */

  if (xi != (double *) NULL) {
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
  return xxx;
}


static HXTStatus hxtRefineTetrahedraOneStep(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                                            double (*mesh_size)(double x, double y, double z, void* userData),
                                            void* userData , int *nbAdd, int iter)
{
  double *newVertices;
  uint32_t *numCreated;
  int maxThreads = omp_get_max_threads();
  HXT_CHECK( hxtAlignedMalloc(&newVertices, sizeof(double)*4*mesh->tetrahedra.num) );
  HXT_CHECK( hxtMalloc(&numCreated, maxThreads*sizeof(uint32_t)) );

  
  // TODO: creating multiple vertices per tetrahedron
  uint32_t add = 0;
  HXTStatus status = HXT_STATUS_OK;
  #pragma omp parallel reduction(+:add)
  {
    int threadID = omp_get_thread_num();
    uint32_t localAdd = 0;

    
    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
    {
      newVertices[(size_t) 4*i+3] = -1.0;
      if (mesh->tetrahedra.colors[i] != UINT16_MAX && getProcessedFlag(mesh, i)==0){
        double *a = mesh->vertices.coord + (size_t) 4*mesh->tetrahedra.node[4*i+0];
        double *b = mesh->vertices.coord + (size_t) 4*mesh->tetrahedra.node[4*i+1];
        double *c = mesh->vertices.coord + (size_t) 4*mesh->tetrahedra.node[4*i+2];
        double *d = mesh->vertices.coord + (size_t) 4*mesh->tetrahedra.node[4*i+3];
        double circumcenter [3];
        double u,v,w;
        hxtTetCircumcenter(a,b,c,d, circumcenter, &u, &v, &w);
        double circumradius2 = (a[0]-circumcenter[0])*(a[0]-circumcenter[0])+
                               (a[1]-circumcenter[1])*(a[1]-circumcenter[1])+
                               (a[2]-circumcenter[2])*(a[2]-circumcenter[2]);

        setProcessedFlag(mesh, i); // we do not need to refine that tetrahedra anymore

        // all new edges will have a length equal to circumradius2
        double meshSize;
        //        HXTStatus status = hxtMeshSizeEvaluate ( sizeField, circumcenter, &meshSize);

        if(u <= 0 || v <= 0 || w <= 0 || 1.-u-v-w <= 0)
          continue;
        
        if(mesh_size!=NULL) {
          meshSize = mesh_size(circumcenter[0], circumcenter[1], circumcenter[2], userData);
        }
        else { // we suppose delOptions->nodalSize!=NULL
          double SIZES[4];
          double AVG = 0;
          int NN = 0;
          for (int j=0;j<4;j++){
            SIZES[j] = delOptions->nodalSizes[mesh->tetrahedra.node[4*i+j]];
            if (SIZES[j] != DBL_MAX){
              NN++;
              AVG += SIZES[j];
            }
          }
          if (NN != 4){
            AVG /= NN;
            for (int j=0;j<4;j++){
              if (SIZES[j] == DBL_MAX){
                // delOptions->nodalSizes[mesh->tetrahedra.node[4*i+j]] = AVG;
                SIZES[j] = AVG;
              }
            }
          }

          meshSize = SIZES[0] * (1-u-v-w) + SIZES[1] * u + SIZES[2] * v + SIZES[3] * w;
        }
  
        
  
        if (meshSize * meshSize /* .49*/ < circumradius2) {
          //    printf("%llu %g\n",i,sqrt(circumradius2),meshSize);
          newVertices[(size_t) 4*i  ] = circumcenter[0];
          newVertices[(size_t) 4*i+1] = circumcenter[1];
          newVertices[(size_t) 4*i+2] = circumcenter[2];
          newVertices[(size_t) 4*i+3] = meshSize;
          localAdd++;
        }
      }
    }

    numCreated[threadID] = localAdd;

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      add = 0;
      for (int i=0; i<nthreads; i++) {
        uint32_t tsum = add + numCreated[i];
        numCreated[i] = add;
        add = tsum;
      }

      if(mesh->vertices.num + add>mesh->vertices.size){
        status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*(mesh->vertices.num + add));
        if(status==HXT_STATUS_OK){
          status=hxtAlignedRealloc(&delOptions->nodalSizes, (mesh->vertices.num + add)*sizeof(double));
          mesh->vertices.size = mesh->vertices.num + add;
        }
      }
    }

    localAdd = numCreated[threadID] + mesh->vertices.num;

    if(status==HXT_STATUS_OK){
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
        if ( newVertices [4*i+3]!=-1.0 ) {
          mesh->vertices.coord[ (size_t) 4*localAdd   ] = newVertices [(size_t) 4*i  ];
          mesh->vertices.coord[ (size_t) 4*localAdd+1 ] = newVertices [(size_t) 4*i+1];
          mesh->vertices.coord[ (size_t) 4*localAdd+2 ] = newVertices [(size_t) 4*i+2];
          delOptions->nodalSizes[localAdd] = newVertices [4*i+3];
          localAdd++;
        }
      }
    }
  }

  if(status!=HXT_STATUS_OK){
    HXT_TRACE(status);
    return status;
  }

  mesh->vertices.num += add;


  HXT_CHECK( hxtFree(&numCreated) );
  HXT_CHECK(hxtAlignedFree(&newVertices));
  
  HXT_CHECK(hxtDelaunay(mesh, delOptions));

  *nbAdd = mesh->vertices.num - delOptions->numVerticesInMesh;
  delOptions->numVerticesInMesh = mesh->vertices.num;
  return HXT_STATUS_OK;
}

HXTStatus hxtRefineTetrahedra(HXTMesh* mesh,
                              HXTDelaunayOptions* delOptions,
                              double (*mesh_size)(double x, double y, double z, void* userData),
                              void* userData) {
  int iter = 0;
  while(iter++ < 40){
    int nbAdd=0;
    HXT_CHECK(hxtRefineTetrahedraOneStep(mesh, delOptions, mesh_size, userData, &nbAdd, iter));
    //    uint32_t nb;
    //    HXT_CHECK(hxtColorMesh(mesh,&nb));
    if (nbAdd == 0) break;
  }
  return HXT_STATUS_OK;
}


