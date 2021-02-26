#include "hxt_ginzburg.h"
#include "hxt_tools.h"
#include "hxt_edge.h"
#include "hxt_curvature.h"
#include "hxt_linear_system.h"
#include "hxt_non_linear_solver.h"
#include <math.h>
#include <stdio.h>

#define WEAK 1
#define CURV 1

struct HXTGinzburgStruct {
  HXTEdges *edges;
  double *curvatureCrossField; // curvatures as a cross field
  double *crossfield; // (cos nt, sin nt) by edge
  double *epsilonSq; // by triangle
  double meanEps;
  int nbTurns;
  int useWeakBoundary;
  char *petscOpt;
  int useCurvature;
};

static void normalize3(double *d)
{
  double n = sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
  d[0]/=n;
  d[1]/=n;
  d[2]/=n;
}

HXTStatus hxtGinzburgGetDirections(HXTGinzburg *ginzburg, double **crossfield){
  *crossfield = ginzburg->crossfield;
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgSetSolutionTorus(HXTGinzburg *gz, double R1, double R2) 
{
  HXTEdges *edges = gz->edges;
  HXTMesh *mesh = edges->edg2mesh;
  for (int i = 0; i <(int) edges->numEdges; ++i) {
    double *v0 = mesh->vertices.coord + 4*edges->node[i*2+0];
    double *v1 = mesh->vertices.coord + 4*edges->node[i*2+1];
    double x = (v0[0]+v1[0])/2;
    double y = (v0[1]+v1[1])/2;
    double z = (v0[2]+v1[2])/2;
    double r = hypot(x,y);
    double center[] = {x/r*R1, y/r*R1, 0};
    double ca = x/r;
    double sa = y/r;
    double sb = z/R2;
    double cb = (r-R1)/R2;
    double f[] = {-sb*ca, -sb*sa, cb};
    double b0[] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};
    normalize3(b0);
    double b1[] = {-x+center[0], -y+center[1], -z+center[2]};
    normalize3(b1);
    double b2[] = {b0[1]*b1[2]-b0[2]*b1[1],b0[2]*b1[0]-b0[0]*b1[2],b0[0]*b1[1]-b0[1]*b1[0]};
    normalize3(b2);
    double cc = f[0]*b0[0]+f[1]*b0[1]+f[2]*b0[2];
    double sc = f[0]*b2[0]+f[1]*b2[1]+f[2]*b2[2];
    double alpha = atan2(sc, cc);
    gz->crossfield[i*2+0] = cos(alpha*4);
    gz->crossfield[i*2+1] = sin(alpha*4);
  }
  return HXT_STATUS_OK;
}


static inline int comparator(const void *p1, const void *p2)
{
  uint32_t *e0 = (uint32_t*)p1;
  uint32_t *e1 = (uint32_t*)p2;
  return (int)(*(e0)-*(e1));
}

static inline HXTStatus myNormalizedCrossprod(double *a, double *b, double *n)
{ 
  n[0] = a[1]*b[2]-a[2]*b[1];
  n[1] = a[2]*b[0]-a[0]*b[2];
  n[2] = a[0]*b[1]-a[1]*b[0];

  double nn = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  n[0] /= nn; n[1] /= nn; n[2] /= nn;

  return HXT_STATUS_OK;
}

static inline HXTStatus trianglebasis(HXTMesh *m,uint32_t *vtri, double *U, double *V, double *n)
{  

  const double *v0 = m->vertices.coord + 4*vtri[0];
  const double *v1 = m->vertices.coord + 4*vtri[1];
  const double *v2 = m->vertices.coord + 4*vtri[2];

  double a[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double b[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  
  HXT_CHECK(myNormalizedCrossprod(a,b,n));

  U[0] = a[0]; U[1] = a[1]; U[2] = a[2];  
  double na = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
  U[0] /= na; U[1] /= na; U[2] /= na;
  
  HXT_CHECK(myNormalizedCrossprod(n,U,V));

  //printf("tri (%d %d %d) ~ %f %f ; %f %f\n",vtri[0],vtri[1],vtri[2],U[0],U[1],V[0],V[1]);
  
  return HXT_STATUS_OK;

}

static inline double myDot(double *a, double *b)
{
  double d = 0.;
  for (int i=0; i<3; i++)
    d += a[i]*b[i];
  return d;
}


static inline double getAlpha(HXTEdges *edg, uint64_t triNum, int edgNum)
{

  HXTMesh *m = edg->edg2mesh;
  double U[3]={0.}, V[3]={0.}, n[3]={0.};
  uint32_t vtri[3] = {m->triangles.node[3*triNum+0],m->triangles.node[3*triNum+1],m->triangles.node[3*triNum+2]};
  
  int edgNumG = -1;
  for(int i=0; i<3; i++)// looking for global edge numbering
    if( (vtri[(edgNum+0)%3] == edg->node[2*edg->tri2edg[3*triNum+i]+0] || vtri[(edgNum+0)%3] == edg->node[2*edg->tri2edg[3*triNum+i]+1]) &&
        (vtri[(edgNum+1)%3] == edg->node[2*edg->tri2edg[3*triNum+i]+0] || vtri[(edgNum+1)%3] == edg->node[2*edg->tri2edg[3*triNum+i]+1]) )
      edgNumG = edg->tri2edg[3*triNum+i];
  
  HXT_CHECK(trianglebasis(m,vtri,U,V,n));
  
  const double *v0 = m->vertices.coord + 4*edg->node[2*edgNumG+0];
  const double *v1 = m->vertices.coord + 4*edg->node[2*edgNumG+1];
  double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
  double ne = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
  e[0] /= ne; e[1] /= ne; e[2] /= ne;

  double alpha = atan2(myDot(e,V),myDot(e,U));

  //printf("tri %d ~ edg %d (%d) ~ %f\n",triNum,edgNum,edgNumG,180/M_PI*alpha);
  
  return alpha;
}


static inline HXTStatus vertexCrouzeixRaviart(const double *U, double *F)
{
  double xi[3] = {0.,1.,0.};
  double eta[3] = {0.,0.,1.};
  for (uint32_t i=0; i<3; i++)
    F[i] = U[0] * (1.-2.*eta[i]) + U[1] * (2*(xi[i]+eta[i])-1.) + U[2] * (1.-2.*xi[i]);
  return HXT_STATUS_OK;
}

static inline double CRshapes(uint32_t i, double xi, double eta)
{
  double omegaI;
  switch(i){
    case 0:
      omegaI = 1.-2.*eta;
      break;
    case 1:
      omegaI = 2.*(xi+eta)-1.;
      break;
    default:
      omegaI = 1.-2.*xi;
      break;
  }
  return  omegaI;
}

static inline HXTStatus crouzeixRaviart(const double *U, const double *pt, uint32_t N, double *F)
{
  for (uint32_t i=0; i<N; i++){    
    double w0 = (1.-2.*pt[2*i+1]), w1 =2.*(pt[2*i]+pt[2*i+1])-1, w2 = 1.-2.*pt[2*i];
    F[2*i]   = U[0] * w0  + U[2] * w1 + U[4] * w2;
    F[2*i+1] = U[1] * w0  + U[3] * w1 + U[5] * w2;
  }
  return HXT_STATUS_OK;
}

// TEST 
double imposed_norm (double x, double y, double eps){
  return 1.0;
  double X[4][2] = {{0,-.3},{-.3,0.},{0.3,0},{0,0.3}};
  double f = 0.0;
  for (int i=0;i<4;i++){
    double ri = sqrt ((X[i][0]-x)*(X[i][0]-x)+
		      (X[i][1]-y)*(X[i][1]-y));
    f += exp(-ri/eps);
  }
  return 1.-f;

}


//
// add a term that helps the cross field to align with a given smooth vector field (curvature)
//
//  T (u) = 1/2 \intE (u - u_{imp})^2 * C dx
// dT (u) =     \intE (u - u_{imp})du * C dx
//
//  Here, C is a coefficient that we could choose as $(C_{\max} - C_{\min})^2$
//
static inline HXTStatus elementGinzburg(double *vtri, double *cf, double *grad, double *f, double myEpsilon)
{
  double weights[3] = {1./6,1./6,1./6};
  double points[2*3] = {1./6,1./6, 1./6,2./3, 2./3,1./6};
  uint32_t nPoints = 3;

  double gradCR[3][3] = {{0.,-2.,0.},{2.,2.,0.},{-2.,0.,0.}};
  double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
                      {vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
                      {0,0,0}};
  HXT_CHECK(myNormalizedCrossprod(jac[0],jac[1],jac[2]));
  double dJac, invjac[3][3];
  HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
  // initialization
  for(int r=0; r<6; r++){
    f[r]=0.;
    if(grad != NULL)
      for(int c=0; c<6; c++)
        grad[6*r+c]=0.;
  }
  double *uv;

  //  double x = (vtri[0] + vtri[3] + vtri[6])/3.;
  //  double y = (vtri[1] + vtri[4] + vtri[7])/3.;
  //  double r = sqrt(x*x+y*y);
  //  double g_xx = x/(r*r)+y*y;
  //  double g_xy = x*y*(1./(r*r-1));
  //  double g_yy = y*y/(r*r)+x*x
  
  HXT_CHECK(hxtMalloc(&uv,2*nPoints*sizeof(double)));
  HXT_CHECK(crouzeixRaviart(cf,points,nPoints,uv));
  double dCRdX[3][3];
  for(uint32_t i=0; i<3; i++){
    dCRdX[i][0] = dCRdX[i][1] = dCRdX[i][2] = 0;
    for (uint32_t j = 0; j < 3; ++j) {
      dCRdX[i][0] += gradCR[i][j]*invjac[0][j];
      dCRdX[i][1] += gradCR[i][j]*invjac[1][j];
      dCRdX[i][2] += gradCR[i][j]*invjac[2][j];
    }
  }
  // linear part
  for(uint32_t i=0; i<3; i++){
    for(uint32_t j=0; j<3; j++){
      double KJi =
        dCRdX[i][0]*dCRdX[j][0] +
        dCRdX[i][1]*dCRdX[j][1] +
        dCRdX[i][2]*dCRdX[j][2];
      //      KJi /=sqrt(x*x); // FIXME TEST
      double uj=cf[2*j+0], vj=cf[2*j+1];      
      f[i+0]              += uj*KJi*dJac/2.;
      f[i+3]              += vj*KJi*dJac/2.;
      if (grad != NULL) {
        grad[6*(i+0)+j+0]  = KJi*dJac/2.;  
        grad[6*(i+3)+j+3]  = KJi*dJac/2.; 
      }
    }
  }// end linear part

  // -----------------------------------------------
  // force to align to direction of curvature
  //double coef = 1.0;
  //  for(uint32_t i=0; i<3; i++){
  // add a mass matrix 
  //    grad[6*(i+0)+i+0]  += 1./6. * dJac / 2. * coef;  
  //    grad[6*(i+3)+i+3]  += 1./6. * dJac / 2. * coef;
  // add a RHS 
  //    f[i+0] += 1./6. * dJac * coef;
  //    f[i+3] += 1./6. * dJac * coef;
  //  }
  // -----------------------------------------------
  

  // nonlinear term quadrature
  for(uint32_t n=0; n<nPoints; n++){
    double xi =   points[2*n], eta =   points[2*n+1], weight = weights[n];
    double u=uv[2*n+0], v=uv[2*n+1];
    // TEST 
    double x = (1-xi-eta) * vtri[0] + xi * vtri[3] + eta * vtri[3] ;
    double y = (1-xi-eta) * vtri[1] + xi * vtri[4] + eta * vtri[5] ;
    double FFF = imposed_norm (x,y,3*sqrt(myEpsilon));
    double EE;
    if (FFF < 0.9) EE = myEpsilon / 1;
    else EE = myEpsilon;
    for(int i=0; i<3; i++){
      f[i+0] += dJac * weight * 1./EE * u * (u*u + v*v - FFF) * CRshapes(i,xi,eta);
      f[i+3] += dJac * weight * 1./EE * v * (u*u + v*v - FFF) * CRshapes(i,xi,eta);
      if (grad != NULL) {
        for(int j=0; j<3; j++){
          grad[6*(i+0)+j+0] += dJac * weight * (3.*u*u + v*v - FFF)*CRshapes(j,xi,eta)*CRshapes(i,xi,eta)/EE;
          grad[6*(i+0)+j+3] += dJac * weight * 2.*u*v * CRshapes(j,xi,eta)*CRshapes(i,xi,eta)/EE ;
          grad[6*(i+3)+j+0]  = grad[6*(i+0)+j+3];
          grad[6*(i+3)+j+3] += dJac * weight * (u*u + 3.*v*v - FFF)*CRshapes(j,xi,eta)*CRshapes(i,xi,eta)/EE;
        }
      }
    }
  }
  
  HXT_CHECK(hxtFree(&uv));
  return HXT_STATUS_OK;
}// end elementGinzburg

static inline HXTStatus elementEnergy(double *vtri, double *Ue, double *Ve, double myEpsilon, double *energy)
{

#if 1
  double weights[7] = {9./80,.066197076394253,.066197076394253,.066197076394253,.062969590272414,.062969590272414,.062969590272414};
  double points[2*7] = {1./3,1./3,
                        .470142064105115,.470142064105115,
                        .470142064105115,.059715871789770,
                        .059715871789770,.470142064105115,
                        .101286507323456,.101286507323456,
                        .101286507323456,.797426985353087,
                        .797426985353087,.101286507323456};
  int nPoints = 7;
#else
  double weights[3] = {1./6,1./6,1./6};
  double points[2*3] = {0.5, 0, 0, 0.5, 0.5, 0.5};
  uint32_t nPoints = 3;
#endif

  double gradCR[3][3] = {{0.,-2.,0.},{2.,2.,0.},{-2.,0.,0.}};
  double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
                      {vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
                      {0,0,0}};
  HXT_CHECK(myNormalizedCrossprod(jac[0],jac[1],jac[2]));
  double dJac, invjac[3][3];
  HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));

  double dCRdX[3][3];
  for(int i=0; i<3; i++){
    dCRdX[i][0] = dCRdX[i][1] = dCRdX[i][2] = 0;
    for (int j = 0; j < 3; ++j) {
      dCRdX[i][0] += gradCR[i][j]*invjac[0][j];
      dCRdX[i][1] += gradCR[i][j]*invjac[1][j];
      dCRdX[i][2] += gradCR[i][j]*invjac[2][j];
    }
  }

  double su[3]={0.}, sv[3]={0.};
  for(int i = 0; i<3; i++)
    for(int j=0; j<3; j++){
      su[j] += Ue[i]*dCRdX[i][j];
      sv[j] += Ve[i]*dCRdX[i][j];
    }
  
  for(int i=0; i<3; i++)
    *energy += su[i]*su[i] + sv[i]*sv[i];
  *energy *= dJac/2.;
    
  double nonlinear = 0.;
  for(int n=0; n<nPoints; n++){// quadrature
    double u=0., v=0.;
    double xi = points[2*n], eta = points[2*n+1], weight = weights[n];    
    for(uint32_t i = 0; i<3; i++){
      u += Ue[i]*CRshapes(i,xi,eta);
      v += Ve[i]*CRshapes(i,xi,eta);
    }
    nonlinear += dJac * weight * (u*u+v*v - 1.)*(u*u+v*v -1.);
  }
  *energy += 1./(2.*myEpsilon) * nonlinear;
  *energy *= .5;
  
  return HXT_STATUS_OK;
}


static HXTStatus multR(const double alphaN, double *v0, double *v1)
{//edge basis |-> triangle basis
  double c = cos(alphaN);
  double s = sin(alphaN);
  double w0 = c*(*v0) - s*(*v1);
  double w1 = s*(*v0) + c*(*v1);
  *v0 = w0;
  *v1 = w1;
  return HXT_STATUS_OK;
}

static inline HXTStatus computeTotalEnergy( HXTGinzburg *dir, double *total)
{  
  HXTEdges *edges = dir->edges;
  HXTMesh *mesh = edges->edg2mesh;
  double *crossfield = dir->crossfield;
  
  uint64_t ntri = mesh->triangles.num;
  uint32_t* nodes = mesh->triangles.node;
  double *vert = mesh->vertices.coord;
  
  uint32_t* tri2edg= edges->tri2edg;
  
  for(uint64_t i=0; i<ntri; i++){

    double U[3]={0}, V[3]={0.}, n[3]={0.};
    uint32_t vtri[3] = {nodes[3*i+0],nodes[3*i+1],nodes[3*i+2]};
    HXT_CHECK(trianglebasis(mesh,vtri,U,V,n));

    double Ue[3], Ve[3];
    for(uint32_t j=0; j<3; j++){     
      double alphaN = getAlpha(edges,i,j)*dir->nbTurns;
      Ue[j] = crossfield[2*tri2edg[3*i+j]+0];
      Ve[j] = crossfield[2*tri2edg[3*i+j]+1];
      HXT_CHECK(multR(alphaN,&Ue[j],&Ve[j]));
    }

    double energy = 0;    
    
    double v_[3*3] = {vert[4*nodes[3*i+0]],vert[4*nodes[3*i+0]+1],vert[4*nodes[3*i+0]+2],
                      vert[4*nodes[3*i+1]],vert[4*nodes[3*i+1]+1],vert[4*nodes[3*i+1]+2],
                      vert[4*nodes[3*i+2]],vert[4*nodes[3*i+2]+1],vert[4*nodes[3*i+2]+2]};
    
    HXT_CHECK(elementEnergy(v_,Ue,Ve,dir->epsilonSq[i],&energy));
    
    *total += energy;
    
  }// end for i < ntri
    

  return HXT_STATUS_OK;
}
/*
static HXTStatus hxtGinzburgF(void *data, const double *crossfield, double *f)
{
  HXTGinzburg *directions = (HXTGinzburg*)data;
  HXT_CHECK(computeTotalEnergy(directions, f));
  return HXT_STATUS_OK;
}
*/
static inline HXTStatus element2global( HXTGinzburg  *dir, uint64_t triNum, const double *cf, double *grad, double *f, double epsilon_)
{

  HXTEdges *edg = dir->edges;
  HXTMesh *m=edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  
  double cft[6] = {cf[0],cf[1],cf[2],cf[3],cf[4],cf[5]};
  for (uint32_t i=0; i<3; i++){
    double alphaIN = getAlpha(edg,triNum,i)*dir->nbTurns;
    HXT_CHECK(multR(alphaIN,&cft[2*i],&cft[2*i+1]));
  }

  
  double vtri[3*3] = {vert[4*nodes[3*triNum+0]+0],vert[4*nodes[3*triNum+0]+1],vert[4*nodes[3*triNum+0]+2],
                      vert[4*nodes[3*triNum+1]+0],vert[4*nodes[3*triNum+1]+1],vert[4*nodes[3*triNum+1]+2],
                      vert[4*nodes[3*triNum+2]+0],vert[4*nodes[3*triNum+2]+1],vert[4*nodes[3*triNum+2]+2]};
  
  // element contribution
  HXT_CHECK(elementGinzburg(vtri,cft,grad,f,epsilon_));
  for(uint32_t i=0; i<3; i++){
    double alphaIN = getAlpha(edg,triNum,i)*dir->nbTurns;
    HXT_CHECK(multR(-alphaIN,&f[i+0],&f[i+3]));
    if (grad != NULL)
      for(uint32_t j=0; j<6; j++)
        HXT_CHECK(multR(-alphaIN,&grad[6*(i+0)+j],&grad[6*(i+3)+j]));
  }
  for(uint32_t j=0; j<3; j++){
    double alphaJN = getAlpha(edg,triNum,j)*dir->nbTurns;
    if (grad != NULL)
      for(uint32_t i=0; i<6; i++)
        HXT_CHECK(multR(-alphaJN,&grad[6*i+(j+0)],&grad[6*i+(j+3)]));
  }
  return HXT_STATUS_OK;
}

/* Needed to impose strong BC on singularities location */
double edgeLength(const HXTMesh *mesh, uint32_t i1, uint32_t i2){
  double *x1 = mesh->vertices.coord + 4*i1;
  double *x2 = mesh->vertices.coord + 4*i2;
  double dx = x1[0]-x2[0];
  double dy = x1[1]-x2[1];
  double dz = x1[2]-x2[2];

  return sqrt(dx*dx+dy*dy+dz*dz);
}
/* Return a full sorted list of flagged singular elements, the number of repetition of those singular elements in the array, and the number of singularities */
/* This function has to be used before locateSingularity() */
static int listSingularElements(const double *crossField, const HXTEdges *edg, int *elemFlagged, int *sizeSingularEdges, int *elemOcc)
{
  double *normField;
  HXT_CHECK(hxtMalloc(&normField,edg->numEdges*sizeof(double)));
  int *masterElement;
  HXT_CHECK(hxtMalloc(&masterElement,edg->edg2mesh->triangles.num*sizeof(int)));
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    normField[ie] = crossField[2*ie+0]*crossField[2*ie+0] + crossField[2*ie+1]*crossField[2*ie+1];
  }
  for(uint32_t it=0;it<edg->edg2mesh->triangles.num;it++){
    masterElement[it] = -1;
  }
  double critNorm = 0.5;
  for(uint32_t ie=0;ie<2*edg->numEdges;ie++){
    elemFlagged[ie]=-1;
  }
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    if(normField[ie]<critNorm){
      elemFlagged[2*ie+0]= edg->edg2tri[2*ie+0];
      elemFlagged[2*ie+1]= edg->edg2tri[2*ie+1];
      int masterE1 = edg->edg2tri[2*ie+0];
      int masterE2 = edg->edg2tri[2*ie+1];
      while(masterElement[masterE1]!=-1)
          masterE1 = masterElement[masterE1];
      if(masterE2!=-1){
          while(masterElement[masterE2]!=-1)
            masterE2 = masterElement[masterE2];
      }
      double normE1 = 2.;
      double normE2 = 2.;
      for(int j=0;j<3;j++){
          normE1 = fmin(normE1,normField[edg->tri2edg[3*masterE1+j]]);
          if(masterE2!=-1)
            normE2 = fmin(normE2,normField[edg->tri2edg[3*masterE2+j]]);
      }
      if((normE1<=normE2)&&(masterE2!=-1)&&(masterE1!=masterE2)){
          masterElement[masterE2] = masterE1;
      }
      if(normE2<normE1){
          masterElement[masterE1] = masterE2;
      }
    }
    else{
      elemFlagged[2*ie]=-1;
      elemFlagged[2*ie+1]=-1;
    }
  }
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    int masterE1 = elemFlagged[2*ie+0];
    int masterE2 = elemFlagged[2*ie+1];
    if(masterE1!=-1)
      while(masterElement[masterE1]!=-1){
        masterE1 = masterElement[masterE1];
      }
    if(masterE2!=-1)
      while(masterElement[masterE2]!=-1){
        masterE2 = masterElement[masterE2];
      }
    elemFlagged[2*ie+0] = masterE1;
    elemFlagged[2*ie+1] = masterE2;
  }
  qsort(elemFlagged,2*edg->numEdges,sizeof(uint32_t),comparator);
  uint32_t i=0;
  int nDiffElem =0;
  while(i<2*edg->numEdges-1){
    int cpt =1;
    while(elemFlagged [i]==elemFlagged[i+1]){
          cpt++;
          i++;
    }
    elemOcc[nDiffElem]=cpt;
    nDiffElem++;
    i++;
  }
  *sizeSingularEdges = nDiffElem -1;
  HXT_CHECK(hxtFree(&normField));
  HXT_CHECK(hxtFree(&masterElement));
  return 1;
}
/* Return the list of singularities (by returning the singular edges number) */
/* Has to be used after listSingularElements() */
static int locateSingularity(const double *crossField, const HXTEdges *edg, int *elemFlagged, int *singularEdges, int *sizeSingularEdges, int *elemOcc)
{
  double *normField;
  HXT_CHECK(hxtMalloc(&normField,edg->numEdges*sizeof(double)));
  int *masterElement;
  HXT_CHECK(hxtMalloc(&masterElement,edg->edg2mesh->triangles.num*sizeof(int)));
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    normField[ie] = crossField[2*ie+0]*crossField[2*ie+0] + crossField[2*ie+1]*crossField[2*ie+1];
  }
  int offset = 0;
  for(int j=0;j<sizeSingularEdges[0];j++){
    double norm = 2;
    int edgeSing = -1;
    offset = offset + elemOcc[j];
    int elemSing = elemFlagged[offset];
      for(int k=0;k<3;k++){
          if(norm >= normField[edg->tri2edg[3*elemSing+k]]){
            norm = normField[edg->tri2edg[3*elemSing+k]];
            edgeSing = edg->tri2edg[3*elemSing+k];
          }
      }
      singularEdges[j] = edgeSing;
  }  
  HXT_CHECK(hxtFree(&normField));
  return 1;
}

int hxtGinzburgSingularityCreation(HXTGinzburg *ginzburg)
{
  double *crossField = ginzburg->crossfield;
  HXTEdges *edges = ginzburg->edges;
  /* Flagging element around singularities and gatherind singular areas around each singular edges */
  uint64_t nTriangles  = edges->edg2mesh->triangles.num;
  double *normField;
  HXT_CHECK(hxtMalloc(&normField,edges->numEdges*sizeof(double)));
  double *flaggedElemPT;
  HXT_CHECK(hxtMalloc(&flaggedElemPT,nTriangles*sizeof(double)));
  int* elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, 2*edges->numEdges*sizeof(int)));
  int* elemOcc;
  HXT_CHECK(hxtMalloc(&elemOcc, edges->edg2mesh->triangles.num*sizeof(int)));
  int sizeSingularEdges[1]={0};
  listSingularElements(crossField, edges, elemFlagged, sizeSingularEdges, elemOcc);

  int* singEdg;
  HXT_CHECK(hxtMalloc(&singEdg, sizeSingularEdges[0]*sizeof(int)));

  locateSingularity(crossField, edges, elemFlagged, singEdg, sizeSingularEdges, elemOcc);
  uint32_t sinEdgNum=0;
  for(int i=0; i<sizeSingularEdges[0]; i++){
    sinEdgNum=singEdg[i];
    crossField[2*sinEdgNum+0]=0;
    crossField[2*sinEdgNum+1]=0; 
   }
  /* If needed, we can do a new computation here imposing in a strong way the location of singularities in order to smooth the crossfield around singularities */
  for(uint32_t ie=0; ie<edges->numEdges; ie++){
    normField[ie] = sqrt(crossField[2*ie]*crossField[2*ie] + crossField[2*ie+1]*crossField[2*ie+1]);
  }
  for(uint32_t it=0; it<nTriangles; it++){
    flaggedElemPT[it] = 0;
  }
  for(int ie=0; ie<sizeSingularEdges[0]; ie++){
    flaggedElemPT[edges->edg2tri[2*singEdg[ie]+0]] =1;
    flaggedElemPT[edges->edg2tri[2*singEdg[ie]+1]] =1;
  }
  HXT_CHECK(hxtFree(&normField));
  HXT_CHECK(hxtFree(&flaggedElemPT));
  HXT_CHECK(hxtFree(&elemFlagged));
  HXT_CHECK(hxtFree(&elemOcc));
  HXT_CHECK(hxtFree(&singEdg));
  
  return 1;
}

HXTStatus hxtGinzburgCreate(HXTMesh *mesh, double epsilon, int nbTurns, int useWeakBoundary, int useCurvature, const char *petscOpt, HXTGinzburg **ginzburg)
{
  HXTGinzburg* directions;
  HXT_CHECK( hxtMalloc (&directions,sizeof(HXTGinzburg)));
  *ginzburg = directions;
  directions->nbTurns = nbTurns;
  directions->useWeakBoundary = useWeakBoundary;
  directions->petscOpt = strdup(petscOpt);
  directions->useCurvature = useCurvature;
  directions->curvatureCrossField = NULL;
  
  uint64_t nTriangles  = mesh->triangles.num;
  
  HXTEdges* edges;  
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  directions->edges = edges;  

  double *EpsilonSq;
  double meanEps = 0.;
  HXT_CHECK( hxtMalloc (&EpsilonSq,nTriangles * sizeof(double)) );
  if (epsilon > 0){
    for (int i=0; i<(int)nTriangles; i++)    
      EpsilonSq[i] = epsilon*epsilon;
    meanEps = epsilon;
  }
  else {
    double *vert = mesh->vertices.coord;
    uint32_t *node = mesh->triangles.node;
    for (int i=0; i<(int)nTriangles; i++){        
      double vtri[9] = {vert[4*node[3*i+0]+0],vert[4*node[3*i+0]+1],vert[4*node[3*i+0]+2],
        vert[4*node[3*i+1]+0],vert[4*node[3*i+1]+1],vert[4*node[3*i+1]+2],
        vert[4*node[3*i+2]+0],vert[4*node[3*i+2]+1],vert[4*node[3*i+2]+2]};;
      double a[3] = {vtri[3]-vtri[0], vtri[4]-vtri[1], vtri[5]-vtri[2]};// first edge vector
      double b[3] = {vtri[6]-vtri[0], vtri[7]-vtri[1], vtri[8]-vtri[2]};// reversed last edge vector
      double n_[3];
      n_[0] = a[1]*b[2]-a[2]*b[1];
      n_[1] = a[2]*b[0]-a[0]*b[2];
      n_[2] = a[0]*b[1]-a[1]*b[0];
      double area = sqrt(n_[0]*n_[0]+n_[1]*n_[1]+n_[2]*n_[2])/2.;
      EpsilonSq[i] = area * sqrt(2.*directions->nbTurns) * fabs(epsilon);
      meanEps += EpsilonSq[i] * fabs(epsilon);
    }
    meanEps /= nTriangles;
    meanEps = sqrt(meanEps);
  }
  directions->meanEps = meanEps;
  printf("mean espilon = %g\n", meanEps);
  directions->epsilonSq = EpsilonSq;

  HXT_CHECK(hxtMalloc(&directions->crossfield,2*edges->numEdges*sizeof(double)));
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgDelete(HXTGinzburg **ginzburgp)
{
  HXTGinzburg *ginzburg = *ginzburgp;
  HXT_CHECK(hxtEdgesDelete(&ginzburg->edges));
  HXT_CHECK(hxtFree(&ginzburg->epsilonSq));
  HXT_CHECK(hxtFree(&ginzburg->crossfield));
  free(ginzburg->petscOpt);
  HXT_CHECK(hxtFree(&ginzburg));
  return HXT_STATUS_OK;
}

static HXTStatus hxtGinzburgG(void *data, const double *crossfield, HXTLinearSystem *sys, double *f)
{
  HXTGinzburg *directions = (HXTGinzburg*)data;
  HXTEdges *edges = directions->edges;
  HXTMesh *mesh = edges->edg2mesh;
  int nTriangles = mesh->triangles.num;
  int size;
  HXT_CHECK(hxtLinearSystemSize(sys, &size));
  for(int i=0; i < size; ++i){
    f[i] = 0.;
  }
  for(int i=0; i<nTriangles; i++){// assemble system
    double localVector[6] = {0.};
    double elementCf[6] = {0.};
    for(int icf=0; icf<3; icf++){
      elementCf[2*icf+0] = crossfield[2*(edges->tri2edg[3*i+icf])+0];
      elementCf[2*icf+1] = crossfield[2*(edges->tri2edg[3*i+icf])+1];
    }      
    HXT_CHECK(element2global(directions,i,elementCf,NULL,localVector,directions->epsilonSq[i]));
    HXT_CHECK(hxtLinearSystemAddToRhs(sys,f,i,localVector));
  }
  for (uint32_t ie = 0; ie < edges->numEdges; ie++) { // apply constraint from BC's for N-R
    if ((ie==0 && edges->edgesBdryTotal == 0 && directions->curvatureCrossField == NULL) ||
        edges->edg2tri[ie*2+1] == (uint64_t)-1 ||
        hxtEdgesIsBoundary (edges, &(edges->node[2*ie]))){
      if (directions->useWeakBoundary) {
        // weak BCs
        double eps = WEAK*sqrt(directions->epsilonSq[edges->edg2tri[2*ie+0]]);
        double l = edgeLength(mesh, edges->node[2*ie+0], edges->node[2*ie+1]);
        double U = crossfield[2*ie+0];
        double V = crossfield[2*ie+1];
        HXT_CHECK(hxtLinearSystemAddRhsEntry(sys,f,ie,0,-(1.-U)*l/eps));        
        HXT_CHECK(hxtLinearSystemAddRhsEntry(sys,f,ie,1,-(0-V)*l/eps));        
      }
      else {
	// strong BCs
	HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,f,ie,0,0));
	HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,f,ie,1,0));           
        //        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "not implemented");
      }
    }
    // align with curvatures
    if (directions->curvatureCrossField){
      double eps = sqrt(directions->epsilonSq[edges->edg2tri[2*ie+0]]);
      double l = edgeLength(mesh, edges->node[2*ie+0], edges->node[2*ie+1]);
      double U = crossfield[2*ie+0];
      double V = crossfield[2*ie+1];
      double valU = directions->curvatureCrossField[2*ie];
      double valV = directions->curvatureCrossField[2*ie+1];
      HXT_CHECK(hxtLinearSystemAddRhsEntry(sys,f,ie,0,-(valU-U)*l/eps*CURV));        
      HXT_CHECK(hxtLinearSystemAddRhsEntry(sys,f,ie,1,-(valV-V)*l/eps*CURV));        
    }
  }
  double total = 0;
  HXT_CHECK(computeTotalEnergy(directions,&total));
  printf("~ energy = %.16e (%e) ----\n",total,directions->nbTurns*M_PI*log(1/directions->meanEps));
  return HXT_STATUS_OK;
}

static HXTStatus hxtGinzburgH(void *data, const double *solution, HXTLinearSystem *sys)
{
  HXTGinzburg *directions = (HXTGinzburg*)data;
  const double *crossfield = solution;
  HXTEdges *edges = directions->edges;
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t nTriangles = mesh->triangles.num;
  for(uint64_t i=0; i<nTriangles; i++){// assemble system
    double localVector[6] = {0.} , localMatrix[36] = {0.};   
    double elementCf[6] = {0.};
    for(int icf=0; icf<3; icf++){
      elementCf[2*icf+0] = crossfield[2*(edges->tri2edg[3*i+icf])+0];
      elementCf[2*icf+1] = crossfield[2*(edges->tri2edg[3*i+icf])+1];
    }      
    HXT_CHECK(element2global(directions,i,elementCf,localMatrix,localVector,directions->epsilonSq[i]));
    HXT_CHECK(hxtLinearSystemAddToMatrix(sys,i,i,localMatrix));
  }
  for (uint32_t ie = 0; ie < edges->numEdges; ie++) { // apply constraint from BC's for N-R
    if ((ie==0 && edges->edgesBdryTotal == 0 && directions->curvatureCrossField == NULL) ||
        edges->edg2tri[ie*2+1] == (uint64_t)-1 ||
        hxtEdgesIsBoundary (edges, &(edges->node[2*ie]))){
      if (directions->useWeakBoundary) {
        // weak BCs
        double eps = WEAK*sqrt(directions->epsilonSq[edges->edg2tri[2*ie+0]]);
        double l = edgeLength(mesh, edges->node[2*ie+0], edges->node[2*ie+1]);
        HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys,ie,0,ie,0,l/eps));
        HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys,ie,1,ie,1,l/eps));
      }
      else {
	HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(sys,ie,0));
	HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(sys,ie,1));
      }
    }
    // align with curvatures
    if (directions->curvatureCrossField){
      double eps = sqrt(directions->epsilonSq[edges->edg2tri[2*ie+0]]);
      double l = edgeLength(mesh, edges->node[2*ie+0], edges->node[2*ie+1]);
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys,ie,0,ie,0,l/eps*CURV));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys,ie,1,ie,1,l/eps*CURV));
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgComputeDirections(HXTGinzburg *directions, int maxIter)
{
  HXTEdges *edges = directions->edges;
  HXTMesh *mesh = edges->edg2mesh;
  int nTriangles = mesh->triangles.num;
  HXTLinearSystem *nrSys;
  // we definitely use PETSc solver if it is enabled
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&nrSys,nTriangles,3,2,edges->tri2edg,"-pc_type lu"));
#else
  HXT_CHECK(hxtLinearSystemCreateLU(&nrSys,nTriangles,3,2,edges->tri2edg));
#endif
  double *nodalCurvatures = NULL;
  if(directions->useCurvature)
    HXT_CHECK(hxtCurvatureRusinkiewicz (mesh, &nodalCurvatures,&directions->curvatureCrossField, edges, 1));
  double *crossfield;
  crossfield = directions->crossfield;
  // apply BC's & initialize to a zero solution within the domain
  for(uint32_t i=0; i<edges->numEdges; i++){    
    if((i==0 && edges->edgesBdryTotal == 0 && directions->curvatureCrossField == NULL) ||
       edges->edg2tri[2*i+1] == (uint64_t)-1 ||
       hxtEdgesIsBoundary (edges, &(edges->node[2*i]))) // boundary edge
      if (edges->edg2tri[2*i+1] == (uint64_t)-1){
	crossfield[2*i+0] = 1.;// local, u=cos(4*theta)
      }
      else{
	crossfield[2*i+0] = 0.;// local, u=cos(4*theta)
      }
    else
      crossfield[2*i+0] = 0.;
    crossfield[2*i+1] = 0.;// local, v=sin(4*theta)
  }
  //hxtGinzburgSetSolutionTorus(directions, 1, 0.5);
#ifdef HXT_HAVE_PETSC_D
  HXT_CHECK(hxtNonLinearSolverPETSc(nrSys, crossfield, hxtGinzburgG, hxtGinzburgH, directions, directions->petscOpt));
  //HXT_CHECK(hxtOptimizationTao(nrSys, crossfield, hxtGinzburgF, hxtGinzburgG, hxtGinzburgH, directions, "-pc_type lu -tao_grtol 1e-3 -tao_type lmvm -tao_ls_type unit"));
#else
  HXT_CHECK(hxtNewtonRaphson(nrSys, crossfield, 2*edges->numEdges, maxIter, 1e-10, hxtGinzburgG, hxtGinzburgH, directions));
#endif
  HXT_CHECK(hxtLinearSystemDelete(&nrSys));
  if (nodalCurvatures)
    HXT_CHECK(hxtFree(&nodalCurvatures));
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgWriteEnergy(HXTGinzburg *dir, const char *fileName)
{

  HXTEdges *edges = dir->edges;
  double *crossfield = dir->crossfield;
  
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;
  double total = 0.;
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Ginzburg-Landau energy\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(myfile,"ST(");
    double U[3]={0}, V[3]={0.}, n[3]={0.};
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    HXT_CHECK(trianglebasis(mesh,vtri,U,V,n));
    
    double Ue[3], Ve[3];
    for(uint32_t j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(myfile,",");
      double alphaN = getAlpha(edges,i,j)*dir->nbTurns;
      Ue[j] = crossfield[2*tri2edg[3*i+j]+0];
      Ve[j] = crossfield[2*tri2edg[3*i+j]+1];
      HXT_CHECK(multR(alphaN,&Ue[j],&Ve[j]));
    }

    fprintf(myfile,")");
    double energy = 0.;

    double v_[3*3] = {mesh->vertices.coord[4*mesh->triangles.node[3*i+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*i+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*i+0]+2],
    mesh->vertices.coord[4*mesh->triangles.node[3*i+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*i+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*i+1]+2],
    mesh->vertices.coord[4*mesh->triangles.node[3*i+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*i+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*i+2]+2]};
    
    HXT_CHECK(elementEnergy(v_,Ue,Ve,dir->epsilonSq[i],&energy));
    total += energy;
    //printf("energy of %d is %f \n",i,energy);

    double a[3] = {v_[3]-v_[0], v_[4]-v_[1], v_[5]-v_[2]};// first edge vector
    double b[3] = {v_[6]-v_[0], v_[7]-v_[1], v_[8]-v_[2]};// reversed last edge vector
    double n_[3];
    n_[0] = a[1]*b[2]-a[2]*b[1];
    n_[1] = a[2]*b[0]-a[0]*b[2];
    n_[2] = a[0]*b[1]-a[1]*b[0];
    double area = sqrt(n_[0]*n_[0]+n_[1]*n_[1]+n_[2]*n_[2])/2.;
    
    fprintf(myfile,"{%f,%f,%f};\n",energy/area,energy/area,energy/area);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  printf("total energy is %.16e\n",total);
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgWriteCurvatureCrossField(HXTGinzburg *dir, const char *fileName)
{
  if (!dir->curvatureCrossField)return HXT_STATUS_OK;
  double *temp = dir -> crossfield;
  dir -> crossfield = dir->curvatureCrossField;
  HXT_CHECK(hxtGinzburgWriteDirections(dir, fileName));
  dir -> crossfield  = temp;
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgWriteDirections(HXTGinzburg *dir, const char *fileName)
{

  HXTEdges *edges = dir->edges;
  double *crossfield = dir->crossfield;

  
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t *edg2tri = edges->edg2tri;
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Direction fields\"{\n");
  for(uint64_t i=0; i<edges->numEdges; i++){    

    double Ue, Ve;
    Ue = crossfield[2*i+0];
    Ve = crossfield[2*i+1];
    double ne = sqrt(Ue*Ue+Ve*Ve);
    double theta = atan2(Ve,Ue)/dir->nbTurns;    

    const double  *v0 = mesh->vertices.coord +4*edges->node[2*i+0], *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;


    for(int t=0; t<2; t++){// for each triangle
      uint64_t numtri = edg2tri[2*i+t];
      if (numtri != (uint64_t)-1){
        
        double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};        
        uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
        HXT_CHECK( trianglebasis(mesh,vtri,U,V,n) );

        double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
        
        for(int nb=0; nb<dir->nbTurns; nb++){  
          theta += 2.*M_PI/dir->nbTurns;
          double c = cos(theta)*ne, s = sin(theta)*ne;
          fprintf(myfile,"VP(%f,%f,%f){%f,%f,%f};\n",(v0[0]+v1[0])/2.,(v0[1]+v1[1])/2.,(v0[2]+v1[2])/2.,c*e[0]+s*f[0],c*e[1]+s*f[1],c*e[2]+s*f[2]);
        }
      }// end if
    }//end for t
  }// end edges
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}



HXTStatus hxtWriteField(HXTGinzburg *dir, char *fileName)
{

  HXTEdges *edges = dir->edges;
  double *crossfield = dir->crossfield;
 
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Vector field\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(myfile,"VT(");
    double U[3]={0}, V[3]={0.}, n[3]={0.};
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    HXT_CHECK(trianglebasis(mesh,vtri,U,V,n));

    double n0, u0, n1;
    if (1-fabs(n[2]) > 1e-8){
      n0 = atan2(U[2],-V[2]); // atan2( R02, -R12 )
      u0 = acos(n[2]); // acos( R22 )
      n1 = atan2(n[0],n[1]);// atan2( R20, R21 )
    }
    else{
      n0 = n[2]*atan2(-U[1],U[0]); // R22 * atan2( -R01, R00) ~ 0
      u0 = (1-n[2])/2 * M_PI; // (1- R22 )/2 * M_PI
      n1 = 0; // 0 ~ R22 * atan2( R10, R11 )
    }

    // from u basis to x basis (with n turns), both express within u basis 
    
    double Uu[3] = {1,0,0};
    double Vu[3] = {0,1,0};
    double nu[3] = {0,0,1};    

    int NBTURNS = dir->nbTurns;
    // first rotation around n axis (1 turn)
    multR(n1,&Uu[0],&Uu[1]);
    multR(n1,&Vu[0],&Vu[1]);
    //multR(n1/NBTURNS,&nu[0],&nu[1]);

    // second rotation around u axis (1 turn)
    multR(u0,&Uu[1],&Uu[2]);
    multR(u0,&Vu[1],&Vu[2]);
    multR(u0,&nu[1],&nu[2]);

    // third and last rotation around n axis (n turns)
    multR(n0*NBTURNS,&Uu[0],&Uu[1]);// x axis expressed within u basis
    multR(n0*NBTURNS,&Vu[0],&Vu[1]);// y axis expressed within u basis
    multR(n0*NBTURNS,&nu[0],&nu[1]);// z axis expressed within u basis

    // x = Uu[0]*U + Uu[1]*V + Uu[2]*n
    // y = Vu[0]*U + Vu[1]*V + Vu[2]*n
    // z = nu[0]*U + nu[1]*V + nu[2]*n

    double Ue[3], Ve[3];
    for(uint32_t j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(myfile,",");
      double alphaN = getAlpha(edges,i,j)*NBTURNS;
      Ue[j] = crossfield[2*tri2edg[3*i+j]+0];
      Ve[j] = crossfield[2*tri2edg[3*i+j]+1];
      HXT_CHECK(multR(alphaN,&Ue[j],&Ve[j]));
    }
    fprintf(myfile,")");
    double Uv[3] = {0.}, Vv[3] = {0.};
    HXT_CHECK(vertexCrouzeixRaviart(Ue,Uv));
    HXT_CHECK(vertexCrouzeixRaviart(Ve,Vv));
    fprintf(myfile,"{");
    for(uint32_t j=0; j<3; j++){      
      // x = Uu[0]*U + Uu[1]*V + Uu[2]*n
      // y = Vu[0]*U + Vu[1]*V + Vu[2]*n
      // z = nu[0]*U + nu[1]*V + nu[2]*n
      //printf("angleE = %f\n",180./M_PI*atan2(Uv[j]*Vu[0] + Vv[j]*Vu[1],Uv[j]*Uu[0] + Vv[j]*Uu[1])/NBTURNS);
      double vf[3] = { Uv[j]*Uu[0] + Vv[j]*Uu[1] , Uv[j]*Vu[0] + Vv[j]*Vu[1] , Uv[j]*nu[0] + Vv[j]*nu[1] };
      double nVf= sqrt(Uv[j]*Uv[j]+Vv[j]*Vv[j]);
      fprintf(myfile,"%f,%f,%f",vf[0]*nVf,vf[1]*nVf,vf[2]*nVf);
      if(j<2)
        fprintf(myfile,",");  
    }
    fprintf(myfile,"};\n");    
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtWriteDgp1ScalarPos(HXTEdges *edges, double *scalarField, char *fileName)
{

  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Scalar field\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(myfile,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    double Ue[3];
    for(uint32_t j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(myfile,",");
      Ue[j] = scalarField[tri2edg[3*i+j]];
    }
    fprintf(myfile,")");
    double Uv[3] = {0.};
    HXT_CHECK(vertexCrouzeixRaviart(Ue,Uv));
    fprintf(myfile,"{");
    for(uint32_t j=0; j<3; j++){      
      fprintf(myfile,"%f",Uv[0]);
      if(j<2)
        fprintf(myfile,",");  
    }
    fprintf(myfile,"};\n");    
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtWriteDgp0ScalarPos(HXTEdges *edges, double *scalarField, char *fileName)
{

  HXTMesh *mesh = edges->edg2mesh;
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Scalar element field\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(myfile,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    double Ue[3];
    for(uint32_t j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(myfile,",");
      Ue[j] = scalarField[i];
    }
    fprintf(myfile,")");
    double Uv[3] = {0.};
    HXT_CHECK(vertexCrouzeixRaviart(Ue,Uv));
    fprintf(myfile,"{");
    for(uint32_t j=0; j<3; j++){      
      fprintf(myfile,"%f",Uv[0]);
      if(j<2)
        fprintf(myfile,",");  
    }
    fprintf(myfile,"};\n");    
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}


HXTStatus hxtGinzburgWriteTxt(HXTGinzburg *dir, const char *fileName)
{
  HXTEdges *edges = dir->edges;
  double *crossfield = dir->crossfield;

  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;  
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"%d\n",(int)mesh->triangles.num);
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    double U[3]={0}, V[3]={0.}, n[3]={0.};
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    HXT_CHECK(trianglebasis(mesh,vtri,U,V,n));
    double Ue[3], Ve[3];
    for(uint32_t j=0; j<3; j++){
      double alphaN = getAlpha(edges,i,j)*dir->nbTurns;
      Ue[j] = crossfield[2*tri2edg[3*i+j]+0];
      Ve[j] = crossfield[2*tri2edg[3*i+j]+1];
      HXT_CHECK(multR(alphaN,&Ue[j],&Ve[j]));
      fprintf(myfile,"%f %f ",Ue[j],Ve[j]);
    }
    fprintf(myfile,"\n");    
  }
  fclose(myfile);
  return HXT_STATUS_OK;
}


HXTStatus hxtGinzburgWriteVectorCurvatureTrianglePos(HXTGinzburg *dir, const char *fileName)
{
  if (!dir->curvatureCrossField)return HXT_STATUS_OK;
  double *temp = dir -> crossfield;
  dir -> crossfield = dir->curvatureCrossField;
  HXT_CHECK(hxtGinzburgWriteVectorTrianglePos(dir, fileName));
  dir -> crossfield  = temp;
  return HXT_STATUS_OK;
}

HXTStatus hxtGinzburgWriteVectorTrianglePos(HXTGinzburg *ginzburg, const char *fileName)
{
  HXTEdges *edges = ginzburg->edges;

  double *crossfield = ginzburg->crossfield;
  
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;
  
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Direction fields (VT)\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(myfile,"VT(");
    double U[3]={0}, V[3]={0.}, n[3]={0.};
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    HXT_CHECK(trianglebasis(mesh,vtri,U,V,n));
    double Ue[3], Ve[3];
    for(uint32_t j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(myfile,",");
      double alpha = getAlpha(edges,i,j);
      Ue[j] = crossfield[2*tri2edg[3*i+j]+0];
      Ve[j] = crossfield[2*tri2edg[3*i+j]+1];
      HXT_CHECK(multR(alpha*ginzburg->nbTurns,&Ue[j],&Ve[j]));
    }
    fprintf(myfile,")");
    double Uv[3] = {0.}, Vv[3] = {0.};
    HXT_CHECK(vertexCrouzeixRaviart(Ue,Uv));
    HXT_CHECK(vertexCrouzeixRaviart(Ve,Vv));
    fprintf(myfile,"{");
    for(uint32_t j=0; j<3; j++){
      double theta = atan2(Vv[j],Uv[j])/ginzburg->nbTurns;
      double cf[3] = {cos(theta)*U[0]+sin(theta)*V[0],cos(theta)*U[1]+sin(theta)*V[1],cos(theta)*U[2]+sin(theta)*V[2]};
      double nCf= pow((Uv[j]*Uv[j]+Vv[j]*Vv[j]),1./(2.*ginzburg->nbTurns));
      fprintf(myfile,"%f,%f,%f",cf[0]*nCf,cf[1]*nCf,cf[2]*nCf);
      if(j<2)
        fprintf(myfile,",");  
    }
    fprintf(myfile,"};\n");    
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}
