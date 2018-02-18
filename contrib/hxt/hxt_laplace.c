#include <math.h>
#include "hxt_laplace.h"
#include "hxt_mesh.h"

#include "hxt_laplace.h"
#include "hxt_api.h"
#include "hxt_linear_system.h"

/*
   compute the element matrix for one P1 triangle
   local matrix is \intE \nabla NI \cdot \nabla NJ ds
     v
   ^
   |                F (u,v) = N_0 (u,v) F_0 + N_1 (u,v) F_1 + N_2 (u,v) F_2
   + 2              FJ is the value of F at node j
   |\               NJ ( uI, vI) = \delta_{ij} 
   |  \             N_0 = 1-u-v ; N_1 = u ; N_2 = v
   |    \           grad N = { { -1 , -1} , { 1 , 0} , { 0 , 1} };
   |      \
   |        \
   |         \
   |0  (0,0)  \ 1 (1,0)
   +------------+--------> u
  
    X_0, X_1, X_2 the three vertices of a triangle in XYZ coordinate system
    X (u,v) = X_0 N_0 + X_1 N_1 + X_2 N_2             
*/

static inline double normalize (double *n){
  double d = sqrt (n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  if (d != 0.0){
    n[0] /= d;
    n[1] /= d;
    n[2] /= d;
  }
  return fabs(d);
}

static inline void crossprod (double *a, double *b, double *n){
  n[0] = a[1]*b[2] - a[2]*b[1]; 
  n[1] = - (a[0]*b[2] - a[2]*b[0]); 
  n[2] = a[0]*b[1] - a[1]*b[0]; 
}


static inline HXTStatus inverseJacobian ( double *X0, double *X1, double *X2, double invjac[3][3], double *det)
{
  double v1[3] = {X1[0]-X0[0],X1[1]-X0[1],X1[2]-X0[2]};
  double v2[3] = {X2[0]-X0[0],X2[1]-X0[1],X2[2]-X0[2]};
  double n[3] ; crossprod (v1,v2,n);
  normalize (n);
  double jac[3][3] = {{v1[0], v1[1], v1[2]},
                      {v2[0], v2[1], v2[2]},
                      {n[0] , n[1] , n[2]}};
  HXT_CHECK(hxtInv3x3(jac, invjac,det));
  return HXT_STATUS_OK;
}

static inline double dotprod (double *a, double *b){
  return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}

static inline void elementMatrix ( double *X0, double *X1, double *X2, double mat[9])
{
  double invjac[3][3], det;
  inverseJacobian ( X0, X1, X2, invjac, &det);

  double GradN0[3] = {-invjac[0][0]-invjac[0][1],-invjac[1][0]-invjac[1][1],-invjac[2][0]-invjac[2][1]};
  double GradN1[3] = {invjac[0][0],invjac[1][0],invjac[2][0]};
  double GradN2[3] = {invjac[0][1],invjac[1][1],invjac[2][1]};

  mat[3*0+0] = dotprod(GradN0,GradN0) * det * .5;
  mat[3*1+1] = dotprod(GradN1,GradN1) * det * .5;
  mat[3*2+2] = dotprod(GradN2,GradN2) * det * .5;
  
  mat[3*0+1] = mat[3*1+0] = dotprod(GradN0,GradN1) * det * .5;
  mat[3*0+2] = mat[3*2+0] = dotprod(GradN0,GradN2) * det * .5;
  mat[3*1+2] = mat[3*2+1] = dotprod(GradN1,GradN2) * det * .5;
}


HXTStatus hxtLaplace(HXTMesh *mesh)
{  
  uint64_t nTriangles  = mesh->triangles.num;
  uint64_t nEdgesBdry = mesh->lines.num;
  uint64_t nVertices = mesh->vertices.num;
  HXTLinearSystem *nrSys; 

  HXT_CHECK(hxtLinearSystemCreateLU(&nrSys,nTriangles,3,1,mesh->triangles.node));

  double *sol, *rhs;
  HXT_CHECK(hxtMalloc(&sol,nVertices*sizeof(double)));
  HXT_CHECK(hxtMalloc(&rhs,nVertices*sizeof(double)));

  for(uint64_t i=0;i<nVertices;i++){
    rhs[i] = 0.0;
  }
  
  double mat[9];
  
  for(uint64_t i=0;i<nTriangles;i++){
    uint32_t n0 = mesh->triangles.node[3*i+0];
    uint32_t n1 = mesh->triangles.node[3*i+1];
    uint32_t n2 = mesh->triangles.node[3*i+2];
    elementMatrix ( mesh->vertices.coord + 4*n0,
                     mesh->vertices.coord + 4*n1,
                     mesh->vertices.coord + 4*n2, mat);
    //    printf("xxx %d %d %d %d %d\n",i,n0,n1,n2, nVertices);
    HXT_CHECK(hxtLinearSystemAddToMatrix(nrSys,i,i,mat));
  }

  
  for(uint64_t i=0;i<nEdgesBdry;i++){
    uint32_t n0 = mesh->lines.node[2*i+0];
    uint32_t n1 = mesh->lines.node[2*i+1];
    double *X0 =  mesh->vertices.coord + 4*n0;
    double *X1 =  mesh->vertices.coord + 4*n1;
    double V0 = X0[1];
    double V1 = X1[1];
    HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(nrSys,n0,0));
    HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(nrSys,n1,0));
    HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n0,0,V0));
    HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n1,0,V1));
    
    // according to your elementary entities, you can set your Dirichlet conditions
    // here 1 and 3 is your elementary entities numbers
    /*if(mesh->lines.colors[i] == 1){
      HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n0,0,0.));
      HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n1,0,0.));
    }
    if(mesh->lines.colors[i] == 3){
      HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n0,0,1.));
      HXT_CHECK(hxtLinearSystemSetRhsEntry(nrSys,rhs,n1,0,1.));
    }*/
  }

  HXT_CHECK(hxtLinearSystemSolve(nrSys,rhs,sol));

  FILE *f = fopen("a.pos","w");
  fprintf(f,"View \"\"{\n");
  for(uint64_t i=0;i<nTriangles;i++){
    int n0 = mesh->triangles.node[3*i+0];
    int n1 = mesh->triangles.node[3*i+1];
    int n2 = mesh->triangles.node[3*i+2];
    double *X0 =  mesh->vertices.coord +4*n0;
    double *X1 =  mesh->vertices.coord +4*n1;
    double *X2 =  mesh->vertices.coord +4*n2;
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",X0[0],X0[1],X0[2],X1[0],X1[1],X1[2],X2[0],X2[1],X2[2],sol[n0],sol[n1],sol[n2]);
  }
  fprintf(f,"};\n");
  fclose(f);

  HXT_CHECK(hxtFree(&rhs));
  HXT_CHECK(hxtFree(&sol));
  HXT_CHECK(hxtLinearSystemDelete(&nrSys));
  

  return HXT_STATUS_OK;
}
