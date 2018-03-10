#include <math.h>
#include <time.h>
#include "hxt_bbox.h"
#include "hxt_tools.h"
#include "hxt_mesh_size.h"
#include "hxt_tetrahedra.h"
#include "hxt_vertices.h"
#include "hxt_mesh3d.h"
#include "predicates.h"

#ifdef HXT_MICROSOFT
#define _CRT_RAND_S 
#include <stdlib.h> 
double drand48() {
  double a;
  rand_s(&a);
  return a;
}
#endif

static inline void sort3ints(uint32_t *i){
  uint32_t no1 = i[0];
  uint32_t no2 = i[1];
  uint32_t no3 = i[2];

  if (no1>no2) {   
    i[1]=no1;    
    i[0]=no2;   
  } else {
    i[1]=no2;  
    i[0]=no1;  
  } 
  if (i[1]>no3) { 
    i[2]=i[1];    
    if(i[0]>no3){         
      i[1]=i[0];                
      i[0]=no3;
    }else {
      i[1]=no3;      
    }         
  }else i[2]=no3;
  //printf("%u %u %u\n",i[0],i[1],i[2]);
}


static inline int facecmp(const void *p0, const void *p1)
{ 
  uint32_t *f0 = (uint32_t*)p0;
  uint32_t *f1 = (uint32_t*)p1;
  
  if (f0[0] != f1[0]) return f0[0] - f1[0];
  if (f0[1] != f1[1]) return f0[1] - f1[1];
  return f0[2] - f1[2];
}

HXTStatus hxtCreateFaceSearchStructure(HXTMesh* mesh, uint32_t **pfaces){
  uint32_t *tfaces;
  
  HXT_CHECK(hxtMalloc(&tfaces,3*mesh->triangles.num*sizeof(uint32_t)));
  memcpy (tfaces, mesh->triangles.node, 3*mesh->triangles.num*sizeof(uint32_t));    
  
#pragma omp parallel for
  for (uint32_t i = 0; i<mesh->triangles.num; i++)sort3ints(&tfaces[3*i]);
  
  // CELESTIN FIXME : SHOULD USE YOUR PARALLEL SORT
  qsort(tfaces,mesh->triangles.num,3*sizeof(uint32_t),facecmp);
  *pfaces = tfaces;
  return HXT_STATUS_OK;  
}

HXTStatus hxtComputeMeshSizeFromMesh (HXTMesh* mesh, double **psizes){

  double *sizes;
  HXT_CHECK(hxtMalloc(&sizes,mesh->vertices.num*sizeof(double))); 
  
#pragma omp parallel for
  for (uint32_t i = 0; i<mesh->tetrahedra.num; i++){
    for (uint32_t j = 0; j<4; j++){  
      uint32_t n1 = mesh->tetrahedra.node[4*i+j];      
      if (n1 != HXT_GHOST_VERTEX)
        sizes[n1] = 1.e22;
    }
  }


#pragma omp parallel for
  for (uint32_t i = 0; i<mesh->tetrahedra.num; i++){
    for (uint32_t j = 0; j<4; j++){  
      uint32_t n1 = mesh->tetrahedra.node[4*i+(j+0)%4];
      uint32_t n2 = mesh->tetrahedra.node[4*i+(j+1)%4];
      if (n1 != HXT_GHOST_VERTEX && n2 != HXT_GHOST_VERTEX){
        double *X1 = mesh->vertices.coord + 4*n1;
        double *X2 = mesh->vertices.coord + 4*n2;
        double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                         (X1[1]-X2[1])*(X1[1]-X2[1])+
                         (X1[2]-X2[2])*(X1[2]-X2[2]));
        sizes [n1] = l < sizes [n1] ? l : sizes [n1];
        sizes [n2] = l < sizes [n2] ? l : sizes [n2];
      }
    }
  }
  *psizes = sizes;
  return HXT_STATUS_OK;    
}

// TODO: use a sort on the index only and then put everything into order...
HXTStatus hxtEmptyMesh(HXTMesh* mesh){
// we assume that the input is a surface mesh
  if (mesh->tetrahedra.num)  
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should only contain triangles");
  if (mesh->triangles.num == 0)  
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should contain triangles");

  hxtNodeInfo* nodeInfo;

  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(hxtNodeInfo)*mesh->vertices.num) );

  #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    nodeInfo[i].node = i;
  }

  HXT_CHECK( hxtDelaunaySteadyVertices(mesh, NULL, nodeInfo, mesh->vertices.num) );

  HXT_CHECK( hxtAlignedFree(&nodeInfo) );
  
  return HXT_STATUS_OK;
  
}


HXTStatus hxtVerifyBoundary(HXTMesh* mesh, uint32_t *missing) {

  uint32_t ft [4][3] = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
  
  uint16_t *flags;
  HXT_CHECK(hxtMalloc(&flags,mesh->triangles.num*sizeof(uint16_t))); 
#pragma omp parallel for
  for (uint32_t i = 0; i<mesh->triangles.num; i++)flags[i] = 0;

  uint32_t *tfaces;
  HXT_CHECK(hxtCreateFaceSearchStructure(mesh, &tfaces));   
  
#pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    uint32_t *v = &mesh->tetrahedra.node[4*i];
    for (uint32_t j=0; j<4;j++){
      uint32_t facet[3] = {v[ft[j][0]],v[ft[j][1]],v[ft[j][2]]};
      sort3ints (facet);
      uint32_t* found = (uint32_t*)bsearch (facet, tfaces, mesh->triangles.num, 3*sizeof(uint32_t), facecmp);
      if (found) {
        uint32_t facetId = (found - tfaces)/3;
        flags[facetId] = 1;
      }
    }
  }

  *missing=0;
  for (uint32_t i = 0; i<mesh->triangles.num; i++)*missing += 1 - flags[i];
  HXT_CHECK(hxtFree(&tfaces)); 
  HXT_CHECK(hxtFree(&flags)); 
  return HXT_STATUS_OK;
}

// refine 


double hxtTetCircumcenter(double a[3], double b[3], double c[3], double d[3],
                            double circumcenter[3], double *xi, double *eta, double *zeta){
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


/// Starts from an empty 3D mesh and color the different regions 
/// assume that neighbors are computed
HXTStatus hxtColorMesh(HXTMesh* mesh, uint32_t *nbColors) { // TODO: why is nbColors unused ??
  // compute the face search structure
  uint32_t *tfaces;
  HXT_CHECK(hxtCreateFaceSearchStructure(mesh, &tfaces));   
  
  // TODO: check this out
#pragma omp parallel for
  for (uint64_t i = 0; i<mesh->tetrahedra.num; i++)
    mesh->tetrahedra.colors[i] = 0 ;//mesh->tetrahedra.node[4*i+3]!=HXT_GHOST_VERTEX ? 0 : UINT16_MAX;

  uint16_t color = 1;
  uint16_t colorOut = 0;

  uint64_t *stack;
  HXT_CHECK(hxtMalloc(&stack,mesh->tetrahedra.num*sizeof(uint64_t))); 
  while (1){
    uint64_t stackSize = 0;
    uint64_t first;

    for ( first = 0; first<mesh->tetrahedra.num; first++)if (mesh->tetrahedra.colors[first] == 0) break;    
    
    if (first == mesh->tetrahedra.num) break;
    stack[stackSize++] = first;
    int count = 1;
    while (stackSize){
      stackSize --;
      uint64_t t = stack[stackSize];
      mesh->tetrahedra.colors[t] = color;
      if (mesh->tetrahedra.node[4*t+3] == HXT_GHOST_VERTEX)
        colorOut = color;
      for (uint16_t i = 0; i< 4;i++){
        uint64_t neigh = mesh->tetrahedra.neigh[4*t+i]/4;
        if (!mesh->tetrahedra.colors[neigh]){
          uint32_t* const Node = mesh->tetrahedra.node + 4*t;
          uint32_t facet [3] = {Node[(i+1)%4], Node[(i+2)%4], Node[(i+3)%4]};
          sort3ints(facet);
          uint32_t* found = (uint32_t*)bsearch (facet, tfaces, mesh->triangles.num, 3*sizeof(uint32_t), facecmp);
          if (!found){
            stack[stackSize++] = neigh;
            count ++;
          }
        }
      }
    }
    color++;
  }
  for (int i=0;i<mesh->tetrahedra.num;i++)if (mesh->tetrahedra.colors[i] == colorOut) mesh->tetrahedra.colors[i] = UINT16_MAX;
  HXT_CHECK(hxtFree(&stack)); 
  HXT_CHECK(hxtFree(&tfaces)); 
  return HXT_STATUS_OK;
}


HXTStatus hxtRefineTetrahedraOneStep(HXTMesh* mesh, HXTMeshSize* sizeField, int *nbAdd, double **nodalSizes, int iter) {

  double *newSizes;
  double *newVertices;
  HXT_CHECK(hxtMalloc(&newVertices, 4*mesh->tetrahedra.num*sizeof(double))); 
  HXT_CHECK(hxtMalloc(&newSizes,mesh->tetrahedra.num*sizeof(double))); 
#pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++)
    newVertices[4*i+3] = 0.0;
  
  // TODO: not creating point stupidly
  uint32_t add = 0;
#pragma omp parallel for reduction (+:add)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    uint16_t myColor = mesh->tetrahedra.colors[i];
    if (myColor != UINT16_MAX){
      double *a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+0];
      double *b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+1];
      double *c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+2];
      double *d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+3];
      double circumcenter [3];
      double u,v,w;
      hxtTetCircumcenter(a,b,c,d, circumcenter, &u, &v, &w);
      double circumradius = sqrt((a[0]-circumcenter[0])*(a[0]-circumcenter[0])+
                                 (a[1]-circumcenter[1])*(a[1]-circumcenter[1])+
                                 (a[2]-circumcenter[2])*(a[2]-circumcenter[2]));
      // all new edges will have a length equal to circumradius
      double meshSize;
      //        HXTStatus status = hxtMeshSizeEvaluate ( sizeField, circumcenter, &meshSize);
      meshSize =
        (*nodalSizes)[mesh->tetrahedra.node[4*i+0]] * (1-u-v-w) +
        (*nodalSizes)[mesh->tetrahedra.node[4*i+1]] * u +
        (*nodalSizes)[mesh->tetrahedra.node[4*i+2]] * v +
        (*nodalSizes)[mesh->tetrahedra.node[4*i+3]] * w;
      //        printf("%g %g %g %g\n",u,v,w,meshSize);
      // if mesh size  is significantly smaller than circumradius
      if (u > 0 && v > 0 && w > 0 && 1.-u-v-w > 0 && meshSize *.8 < circumradius) {
        //            printf("%llu %g\n",i,circumradius);
        newVertices[4*i  ] = circumcenter[0];
        newVertices[4*i+1] = circumcenter[1];
        newVertices[4*i+2] = circumcenter[2];
        newVertices[4*i+3] = 1.0;
        newSizes[i] = meshSize;
        add++;
      }
    }
  }  

  if (mesh->vertices.num + add >= mesh->vertices.size){
    HXT_CHECK(hxtRealloc(&mesh->vertices.coord,4*(mesh->vertices.num + add)*sizeof(double))); 
    HXT_CHECK(hxtRealloc(nodalSizes,(mesh->vertices.num + add)*sizeof(double))); 
    mesh->vertices.size = mesh->vertices.num + add;
  }

  add = 0;
// #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    if ( newVertices [4*i+3]!=0.0 ) {
      mesh->vertices.coord[ 4*mesh->vertices.num   ] = newVertices [4*i  ];
      mesh->vertices.coord[ 4*mesh->vertices.num+1 ] = newVertices [4*i+1];
      mesh->vertices.coord[ 4*mesh->vertices.num+2 ] = newVertices [4*i+2];
      (*nodalSizes) [ mesh->vertices.num ] = newSizes[i];
      mesh->vertices.num++;
      add++;
    }
  }
  
  HXT_CHECK(hxtDelaunay(mesh, NULL));

  HXT_CHECK(hxtFree(&newVertices));
  HXT_CHECK(hxtFree(&newSizes));
  *nbAdd = add;
  return HXT_STATUS_OK;
}

HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTMeshSize* sizeField, double **nodalSizes) {
  int iter = 0;
  while(iter++ < 20){
    int nbAdd=0;
    clock_t t1 = clock();
    HXT_CHECK(hxtRefineTetrahedraOneStep(mesh, sizeField, &nbAdd, nodalSizes, iter));
    HXT_INFO("ITERATION %3d -- %3f seconds\n",iter,(double)(clock()-t1)/CLOCKS_PER_SEC); 
    //    uint32_t nb;
    //    HXT_CHECK(hxtColorMesh(mesh,&nb));
    if (nbAdd == 0) break;
  }
  return HXT_STATUS_OK;
}


