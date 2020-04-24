#include "hxt_curvature.h"
#include "hxt_tools.h"
#include <stdio.h>

// #include <time.h> // for commented timings


#define tolerance 0.1e-20

static HXTStatus hxtInv4x4ColumnMajor(double m[16], double invOut[16], double *det)
{
  double inv[16];
  int i;
  
  inv[ 0] =  m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
  inv[ 4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
  inv[ 8] =  m[4] * m[ 9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[ 9];
  inv[12] = -m[4] * m[ 9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[ 9];
  inv[ 1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
  inv[ 5] =  m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
  inv[ 9] = -m[0] * m[ 9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[ 9];
  inv[13] =  m[0] * m[ 9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[ 9];
  inv[ 2] =  m[1] * m[ 6] * m[15] - m[1] * m[ 7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[ 7] - m[13] * m[3] * m[ 6];
  inv[ 6] = -m[0] * m[ 6] * m[15] + m[0] * m[ 7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[ 7] + m[12] * m[3] * m[ 6];
  inv[10] =  m[0] * m[ 5] * m[15] - m[0] * m[ 7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[ 7] - m[12] * m[3] * m[ 5];
  inv[14] = -m[0] * m[ 5] * m[14] + m[0] * m[ 6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[ 6] + m[12] * m[2] * m[ 5];
  inv[ 3] = -m[1] * m[ 6] * m[11] + m[1] * m[ 7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[ 9] * m[2] * m[ 7] + m[ 9] * m[3] * m[ 6];
  inv[ 7] =  m[0] * m[ 6] * m[11] - m[0] * m[ 7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[ 8] * m[2] * m[ 7] - m[ 8] * m[3] * m[ 6];
  inv[11] = -m[0] * m[ 5] * m[11] + m[0] * m[ 7] * m[ 9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[ 9] - m[ 8] * m[1] * m[ 7] + m[ 8] * m[3] * m[ 5];
  inv[15] =  m[0] * m[ 5] * m[10] - m[0] * m[ 6] * m[ 9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[ 9] + m[ 8] * m[1] * m[ 6] - m[ 8] * m[2] * m[ 5];
  
  *det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
  
  if(*det == 0)
    return HXT_STATUS_ERROR;
    
  double invDet = 1.0 / *det;
  
  for(i = 0; i < 16; i++)
    invOut[i] = inv[i] * invDet;
  
  return HXT_STATUS_OK;
}
 
static void solveEig(double A, double B, double C, double D, 
                      double* lambda1, double *v1x, double*v1y, 
                      double* lambda2, double *v2x, double*v2y ) 
{
  if(B*C <= tolerance  ) {
    *lambda1 = A; *v1x = 1; *v1y = 0;
    *lambda2 = D; *v2x = 0; *v2y = 1;
    return;
  }
  
  double tr = A + D;
  double det = A * D - B * C;
  double S = sqrt( (tr*tr/4) - det );
  *lambda1 = tr/2 + S;
  *lambda2 = tr/2 - S;

  double temp = ((A-D)*(A-D)/4) + B * C;
  
  double SS = sqrt( temp > 0 ? temp: 0.0);
  if( A - D < 0 ) {
    *v1x = C;
    *v1y = - (A-D)/2 + SS;
    *v2x = + (A-D)/2 - SS;
    *v2y = B;
  } else {
    *v2x = C;
    *v2y = - (A-D)/2 - SS;
    *v1x = + (A-D)/2 + SS;
    *v1y = B;
  }
  
  double n1 = sqrt((*v1x)*(*v1x)+(*v1y)*(*v1y));
  *v1x /= n1; *v1y /= n1;
  double n2 = sqrt((*v2x)*(*v2x)+(*v2y)*(*v2y));
  *v2x /= n2; *v2y /= n2;
}

static inline int node2trianglescmp(const void *p0, const void *p1)
{ 
  const uint64_t *e0 = (const uint64_t*)p0;
  const uint64_t *e1 = (const uint64_t*)p1;
  
  if (e0[0] < e1[0]) return -1;
  if (e0[0] > e1[0]) return  1;
  return 0;
}

 
static inline double normalize (double *n){
  double d = sqrt (n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  if (d != 0.0){
    n[0] /= d;
    n[1] /= d;
    n[2] /= d;
  }
  return fabs(d);
}

static inline void makevector (double *a, double *b, double *ba){
  ba[0] = b[0]-a[0];
  ba[1] = b[1]-a[1];
  ba[2] = b[2]-a[2];
}

static inline double dotprod (double *a, double *b){
  return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}

static inline void crossprod (double *a, double *b, double *n){
  n[0] = a[1]*b[2] - a[2]*b[1]; 
  n[1] = - (a[0]*b[2] - a[2]*b[0]); 
  n[2] = a[0]*b[1] - a[1]*b[0]; 
}

static inline void unitNormal2Triangle (double *x1, double *x2, double *x3, double *n, double *s) {

  double a[3] = {x2[0]-x1[0],x2[1]-x1[1],x2[2]-x1[2]};
  double b[3] = {x3[0]-x1[0],x3[1]-x1[1],x3[2]-x1[2]};

  
  crossprod (a,b,n);
  *s = 2*normalize(n);
  //    printf("%g %g %g = %g %g %g\n",(x1[0]+x2[0]+x3[0])/3.,
  //           (x1[1]+x2[1]+x3[1])/3.,(x1[2]+x2[2]+x3[2])/3.,
  //           n[0],n[1],n[2]);
}

void computeLocalFrame (double *n, double *u, double *v) {
  if (fabs(n[0]) > fabs(n[1]) && fabs(n[0]) > fabs(n[2])){
    u[0] = 0;u[1] = 0; u[2] = 1;
  }
  else {
    u[0] = 1;u[1] = 0; u[2] = 0;
  }  
  crossprod (n,u,v);
  normalize (v);
  crossprod (v,n,u);    
  //  printf("%g %g %g\n",v[0],v[1],v[2]);
  //  printf("%g %g %g\n",u[0],u[1],u[2]);
  //  printf("%g %g %g\n",v[0],v[1],v[2]);
}


void saveNodalField (HXTMesh *mesh, double *v, int ncomp, const char *fn){
  FILE *f  = fopen (fn , "w");
  uint64_t nTriangles  = mesh->triangles.num;
  fprintf(f,"View \"Vector\" {\n");
  for (uint64_t i = 0; i<nTriangles; i++){
    double *p0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *p1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *p2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    double *v0 = &v[abs(ncomp)*mesh->triangles.node[3*i+0]];
    double *v1 = &v[abs(ncomp)*mesh->triangles.node[3*i+1]];
    double *v2 = &v[abs(ncomp)*mesh->triangles.node[3*i+2]];
    if (ncomp == 3)
      fprintf(f,"VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
              p0[0],p0[1],p0[2],p1[0],p1[1],p1[2],p2[0],p2[1],p2[2],
              v0[0],v0[1],v0[2],v1[0],v1[1],v1[2],v2[0],v2[1],v2[2]);
    else if (ncomp == 1)
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              p0[0],p0[1],p0[2],p1[0],p1[1],p1[2],p2[0],p2[1],p2[2],
              v0[0],v1[0],v2[0]);
    else if (ncomp == 6)
      fprintf(f,"VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
                    p0[0],p0[1],p0[2],p1[0],p1[1],p1[2],p2[0],p2[1],p2[2],
                    v0[0],v0[1],v0[2],v1[0],v1[1],v1[2],v2[0],v2[1],v2[2]);
    else if (ncomp == -6)
      fprintf(f,"VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
              p0[0],p0[1],p0[2],p1[0],p1[1],p1[2],p2[0],p2[1],p2[2],
              v0[3],v0[4],v0[5],v1[3],v1[4],v1[5],v2[3],v2[4],v2[5]);
  }  
  fprintf(f,"};\n");
  
  fclose (f);
}

HXTStatus hxtCurvatureRusinkiewicz (HXTMesh *mesh, double **nodalCurvatures, double **crossField, HXTEdges* edges, int debug)
{
  // clock_t T1 = clock();
  
  uint64_t nTriangles  = mesh->triangles.num;
  //  uint64_t nEdgesBdry = mesh->lines.num;
  uint64_t nVertices   = mesh->vertices.num;
  
  HXT_CHECK(hxtMalloc(nodalCurvatures,6*nVertices*sizeof(double)));

  // FIXME: not all nodalCurvatures are initialized by the following algorithm,
  // => it result in an undefined behavior when computing cross-field (line 374+)
  // To at least have a deterministic result, I decided to initialize nodalCurvature to 0
  memset(*nodalCurvatures, 0, 6*nVertices*sizeof(double));

  uint64_t *node2tri;
  HXT_CHECK(hxtMalloc(&node2tri,3*2*nTriangles*sizeof(uint64_t))); 

  // --> FIRST COMPUTE NODE NORMALS  and node2triangle connectivity
  double   *nodeNormals;
  HXT_CHECK(hxtMalloc(&nodeNormals,3*nVertices*sizeof(double))); 
  for (uint64_t i = 0; i<3*nVertices; i++)nodeNormals[i] = 0.0;  
  uint64_t counter = 0;

  double n[3],surf;
  
  for (uint64_t i = 0; i<nTriangles; i++){
    node2tri[counter++] = mesh->triangles.node[3*i+0];
    node2tri[counter++] = i;
    node2tri[counter++] = mesh->triangles.node[3*i+1];
    node2tri[counter++] = i;
    node2tri[counter++] = mesh->triangles.node[3*i+2];
    node2tri[counter++] = i;
    unitNormal2Triangle ( mesh->vertices.coord + 4*mesh->triangles.node[3*i+0],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*i+1],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*i+2], n, &surf);
    double *n0 = &nodeNormals[3*mesh->triangles.node[3*i+0]];
    double *n1 = &nodeNormals[3*mesh->triangles.node[3*i+1]];
    double *n2 = &nodeNormals[3*mesh->triangles.node[3*i+2]];
    for (uint64_t i1 = 0; i1 < 3; i1++) {
      n0[i1]+=n[i1];
      n1[i1]+=n[i1];
      n2[i1]+=n[i1];
    }
  }
  for (uint64_t i = 0; i<nVertices; i++)normalize(&nodeNormals[3*i]);  
  if (debug) saveNodalField (mesh,nodeNormals, 3, "normals.pos");
  
  qsort(node2tri,3*nTriangles,2*sizeof(uint64_t),node2trianglescmp);


  // --> COMPUTE THE SECOND FUNDAMENTAL TENSOR ON EACH TRIANGLE USING LEAST SQUARES  

  double   *CURV;
  HXT_CHECK(hxtMalloc(&CURV,4*nTriangles*sizeof(double))); 

  for (uint64_t i = 0; i<nTriangles; i++){

    double *n0 = &nodeNormals[3*mesh->triangles.node[3*i+0]];
    double *n1 = &nodeNormals[3*mesh->triangles.node[3*i+1]];
    double *n2 = &nodeNormals[3*mesh->triangles.node[3*i+2]];

    double e0[3],e1[3],e2[3];
    makevector (mesh->vertices.coord + 4*mesh->triangles.node[3*i+2],
                mesh->vertices.coord + 4*mesh->triangles.node[3*i+1],e0);
    makevector (mesh->vertices.coord + 4*mesh->triangles.node[3*i+0],
                mesh->vertices.coord + 4*mesh->triangles.node[3*i+2],e1);
    makevector (mesh->vertices.coord + 4*mesh->triangles.node[3*i+1],
                mesh->vertices.coord + 4*mesh->triangles.node[3*i+0],e2);
 
    unitNormal2Triangle ( mesh->vertices.coord + 4*mesh->triangles.node[3*i+0],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*i+1],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*i+2], n, &surf);
    double u[3],v[3];
    makevector (mesh->vertices.coord + 4*mesh->triangles.node[3*i+0],
                mesh->vertices.coord + 4*mesh->triangles.node[3*i+1],u);
    normalize(u);
    crossprod(n,u,v);    

    double sys[6][4], rhs[6], temp[3], invA[16], A[16], B[4];
    sys[0][0] = sys[1][2] = dotprod(e0,u);
    sys[0][1] = sys[1][3] = dotprod(e0,v);
    sys[0][2] = sys[0][3] = sys[1][0] = sys[1][1] = 0; 
    makevector (n2,n1,temp);
    rhs[0] = dotprod(temp,u);
    rhs[1] = dotprod(temp,v);

    sys[2][0] = sys[3][2] = dotprod(e1,u);
    sys[2][1] = sys[3][3] = dotprod(e1,v);
    sys[2][2] = sys[2][3] = sys[3][0] = sys[3][1] = 0; 
    makevector (n0,n2,temp);
    rhs[2] = dotprod(temp,u);
    rhs[3] = dotprod(temp,v);

    sys[4][0] = sys[5][2] = dotprod(e2,u);
    sys[4][1] = sys[5][3] = dotprod(e2,v);
    sys[4][2] = sys[4][3] = sys[5][0] = sys[5][1] = 0; 
    makevector (n1,n0,temp);
    rhs[4] = dotprod(temp,u);
    rhs[5] = dotprod(temp,v);

    for (uint64_t i1=0;i1<4;i1++){
      B[i1] = 0.0;
      for (uint64_t i3=0;i3<6;i3++){
        B[i1] += sys[i3][i1] * rhs[i3];
      }
      for (uint64_t i2=0;i2<4;i2++){
        A[i1+4*i2] = 0.0;
        for (uint64_t i3=0;i3<6;i3++){
          A[i1+4*i2] += sys[i3][i2] * sys[i3][i1];
        }
      }
    }
    double det;
    hxtInv4x4ColumnMajor(A, invA,&det);
    for (uint64_t i1=0;i1<4;i1++){
      CURV[4*i+i1] = 0.0;
      for (uint64_t i2=0;i2<4;i2++){
        CURV[4*i+i1] += invA[i1+4*i2] * B[i2];
      }
    }
    CURV[4*i+1] = CURV[4*i+2] = 0.5* (CURV[4*i+1] + CURV[4*i+2]);
  }

  // Get vertex curvatures by averaging triangle curvatures
  uint64_t currentVertex = nVertices + 1;
  uint64_t count = 0;
  double uP[3],vP[3], A, B, D;
  for (uint64_t i = 0; i<6*nTriangles; i+=2){
    uint64_t iVertex   = node2tri[i];
    uint64_t iTriangle = node2tri[i+1];
    //    printf("%d %d %d %d\n",iVertex,iTriangle,nVertices,currentVertex);
    if (currentVertex != iVertex){
      // compute the real stuff
      if (currentVertex != nVertices + 1){
        //        printf("%g %g %g %d \n",A,B,D,count);
        A /= (double) count;
        B /= (double) count;
        D /= (double) count;
        double lambda1, lambda2, v1x, v1y, v2x, v2y;
        solveEig(A, B, B, D, 
                  & lambda1, & v1x, &v1y, 
                  & lambda2, & v2x, & v2y );
        (*nodalCurvatures) [6 * currentVertex + 0] = fabs(lambda1) * (v1x * uP[0] + v1y * vP[0]);      
        (*nodalCurvatures) [6 * currentVertex + 1] = fabs(lambda1) * (v1x * uP[1] + v1y * vP[1]);      
        (*nodalCurvatures) [6 * currentVertex + 2] = fabs(lambda1) * (v1x * uP[2] + v1y * vP[2]);      
        (*nodalCurvatures) [6 * currentVertex + 3] = fabs(lambda2) * (v2x * uP[0] + v2y * vP[0]);      
        (*nodalCurvatures) [6 * currentVertex + 4] = fabs(lambda2) * (v2x * uP[1] + v2y * vP[1]);      
        (*nodalCurvatures) [6 * currentVertex + 5] = fabs(lambda2) * (v2x * uP[2] + v2y * vP[2]);            
      }
      
      count = 0;
      A = 0.0;
      B = 0.0;
      D = 0.0;
      computeLocalFrame (&nodeNormals[3*iVertex], uP, vP);
      currentVertex = iVertex;
    }
    unitNormal2Triangle ( mesh->vertices.coord + 4*mesh->triangles.node[3*iTriangle+0],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*iTriangle+1],
                          mesh->vertices.coord + 4*mesh->triangles.node[3*iTriangle+2], n, &surf);
    double uF[3],vF[3];
    makevector (mesh->vertices.coord + 4*mesh->triangles.node[3*iTriangle+0],
                mesh->vertices.coord + 4*mesh->triangles.node[3*iTriangle+1],uF);
    normalize(uF);
    crossprod(n,uF,vF);    
    double *c = &CURV[4*iTriangle];       
    double UP[3] = {dotprod (uP,uF),dotprod (uP,vF),0};
    normalize(UP);
    double VP[3] = {dotprod (vP,uF),dotprod (vP,vF),0};
    normalize(VP);
    //    printf("C[%d] = %g %g %g %g V= %g %g %g %g %g %g\n",iTriangle,c[0],c[1],c[2],c[3],uF[0],uF[1],uF[2],vF[0],vF[1],vF[2]);
    A += (UP[0]*UP[0]*c[0] + 2*UP[0]*UP[1]*c[1] + UP[1]*UP[1]*c[3]) ;
    D += (VP[0]*VP[0]*c[0] + 2*VP[0]*VP[1]*c[1] + VP[1]*VP[1]*c[3]) ;
    B += (VP[0]*UP[0]*c[0] + (VP[1]*UP[0]+VP[0]*UP[1])*c[1] + VP[1]*UP[1]*c[3]) ;
    count++;
  }

  if (debug)saveNodalField (mesh,*nodalCurvatures,  6, "curvaturesMax.pos");
  if (debug)saveNodalField (mesh,*nodalCurvatures, -6, "curvaturesMin.pos");

  //-----------------------------------------------------------------------------
  //            C R O S S    F I E L D    
  //-----------------------------------------------------------------------------

  //  printf("coucou1 %d\n",edges->numEdges);
  HXT_CHECK(hxtMalloc(crossField,3*edges->numEdges*sizeof(double)));
  for (uint64_t i = 0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i  ];
    uint32_t v1 = edges->node[2*i+1];
    double dir0[3] = {(*nodalCurvatures) [6 * v0 + 0],
		      (*nodalCurvatures) [6 * v0 + 1],
		      (*nodalCurvatures) [6 * v0 + 2]};
    double dir1[3] = {(*nodalCurvatures) [6 * v0 + 3],
		      (*nodalCurvatures) [6 * v0 + 4],
		      (*nodalCurvatures) [6 * v0 + 5]};
    double x1 = normalize(dir0);
    double x2 = normalize(dir1);
    double *n    = &(nodeNormals [3 * v0]);    
    double dir2[3];
    crossprod(dir0,dir1,dir2);
    if (dotprod(n,dir2) < 0){
      dir1[0] = -dir1[0];
      dir1[1] = -dir1[1];
      dir1[2] = -dir1[2];
    }
    
    //    printf ("vertex %d C %g %g %g\n",v0,dir0[0],dir0[1],dir0[2]);
    double ed[3];
    makevector (mesh->vertices.coord + 4*v0,
                mesh->vertices.coord + 4*v1, ed);
    normalize(ed);
    double SIN = dotprod(ed,dir0);
    double COS = dotprod(ed,dir1);
    double ANG = atan2(SIN,COS);
    //    printf ("%g %g %g\n",SIN,COS,ANG);
    (*crossField)[2*i  ] = cos(4*ANG);
    (*crossField)[2*i+1] = sin(4*ANG);
    if (x2 > x1){
      double temp = x1;
      x1 = x2;x2 = temp;
    }
    (*crossField)[2*edges->numEdges+i] = x1 > 1.e-4 ? x1/x2 : 1.e-12;
    //    printf("%g %g %g\n",x1,x2,(*crossField)[2*edges->numEdges+i]);
  }
  //  printf("coucou2\n");
  
  //-----------------------------------------------------------------------------
  //            E N D    C R O S S    F I E L D    
  //-----------------------------------------------------------------------------

  HXT_CHECK(hxtFree(&node2tri)); 
  HXT_CHECK(hxtFree(&nodeNormals)); 
  HXT_CHECK(hxtFree(&CURV)); 

  // clock_t T2 = clock();

  
  //  HXT_INFO ("Curvature has been computed for %u vertices in %8.4f seconds",nVertices,(double)(T2-T1)/CLOCKS_PER_SEC);

  return HXT_STATUS_OK;
  
}
