#include "hxt_mean_values.h"
#include "hxt_edge.h"
#include "hxt_linear_system.h"
#include "hxt_tools.h"


struct HXTMeanValuesStruct{
  HXTEdges *initialEdges;
  double *uv;// parametrization coordinates
  HXTBoundaries *boundaries;
  int boundary; // index of the longest line loop for bc's
  int nHoles;
  int *hole;
  int aspectRatio;
};


HXTStatus hxtMeanValuesCreate(HXTEdges *edges, HXTMeanValues **meanValues)
{
  HXTMesh *mesh = edges->edg2mesh;


  HXTMeanValues *map;
  HXT_CHECK(hxtMalloc(&map,sizeof(HXTMeanValues)));
  *meanValues = map;

  double *uv;
  HXT_CHECK(hxtMalloc(&uv,2*mesh->vertices.num*sizeof(double)));
  map->uv = uv;

  // #mark
  map->initialEdges = edges; // seems useless

  // be moved into parametrization?
  HXTBoundaries *boundaries;
  //    printf("1 %d %d %d\n",mesh->triangles.node[0],mesh->triangles.node[1],mesh->triangles.node[2]);
  //    printf("1 %d %d %d\n",mesh->triangles.node[3],mesh->triangles.node[4],mesh->triangles.node[5]);
  HXT_CHECK(hxtEdgesSetBoundaries(edges, &boundaries));
  //    printf("2\n");
  map->boundaries = boundaries;


  map->boundary = -1;
  double lMax = -1;
  int nBoundaries;
  HXT_CHECK(hxtBoundariesGetNumberOfLineLoops(boundaries, &nBoundaries));
  map->nHoles = nBoundaries-1;
  for(int i=0; i<nBoundaries; i++){
    double length;
    HXT_CHECK(hxtBoundariesGetLengthOfLineLoop(boundaries,i,&length));
    if (lMax<length){
      lMax = length;
      map->boundary = i;
    }
  }

  HXT_CHECK(hxtMalloc(&map->hole,(nBoundaries+1)*sizeof(int)));
  int c = 0;
  for(int i=0; i<nBoundaries; i++)
    if(i!=map->boundary){
      map->hole[c] = i;
      c++;
    }

  map->aspectRatio = -1;

  return HXT_STATUS_OK;
}


HXTStatus hxtMeanValuesCompute(HXTMeanValues *meanValues){

  HXTEdges *edges = meanValues->initialEdges;
  HXTMesh *mesh = edges->edg2mesh;
  int nTriangles = mesh->triangles.num;
  uint32_t nNodes = mesh->vertices.num;


  //  printf("coucou1 %d\n",meanValues->nHoles);
  int nby = 0;
  for(int i=0; i<meanValues->nHoles; i++){
    int c;
    HXT_CHECK(hxtBoundariesGetNumberOfEdgesOfLineLoop(meanValues->boundaries,meanValues->hole[i],&c));
    nby += c;
  }
  //    printf("coucou1\n");

#ifdef __FILLERGAP_
  uint32_t *fillergap;
  HXT_CHECK(hxtMalloc(&fillergap, 3*(nTriangles+nby)*sizeof(uint32_t)));
  memcpy(fillergap, mesh->triangles.node, 3*nTriangles*sizeof(uint32_t));

  int s=0;
  for(int i=0; i<meanValues->nHoles; i++){
    uint32_t *cedgs;
    HXT_CHECK(hxtBoundariesGetEdgesOfLineLoop(meanValues->boundaries,meanValues->hole[i], &cedgs));
    int n_;
    HXT_CHECK(hxtBoundariesGetNumberOfEdgesOfLineLoop(meanValues->boundaries,meanValues->hole[i],&n_));
    for(int j=0; j<n_; j++){
      fillergap[3*(nTriangles+s+j)+0] = edges->node[2*cedgs[j]+1];
      fillergap[3*(nTriangles+s+j)+1] = edges->node[2*cedgs[j]+0];
      fillergap[3*(nTriangles+s+j)+2] = nNodes+i;
    }
    s += n_;
  }
#endif // __FILLERGAP_

  /*
    for(int i=0; i<nTriangles+nby; i++)
    printf("tri %d (nby=%d) \t %u %u %u\n",i,nby,fillergap[3*i+0],fillergap[3*i+1],fillergap[3*i+2]);
  */

  HXTLinearSystem *sys;

#ifdef __FILLERGAP_
  HXT_CHECK(hxtLinearSystemCreateLU(&sys,nTriangles+nby,3,1,fillergap));
#else
  HXT_CHECK(hxtLinearSystemCreateLU(&sys,nTriangles,3,1,mesh->triangles.node));
#endif


  uint32_t *flag;
  HXT_CHECK(hxtMalloc(&flag,nNodes*sizeof(uint32_t)));
  for(uint32_t ii=0; ii<nNodes; ii++)
    flag[ii] = 0;
  //  printf("coucou1\n");

  /* boundary conditions */
  double *uv = meanValues->uv;
  int n = 0;
  //  printf("coucou31\n");
  HXT_CHECK(hxtBoundariesGetNumberOfEdgesOfLineLoop(meanValues->boundaries,meanValues->boundary,&n));
  //  printf("coucou31 %d %d\n",n,meanValues->boundary);
  uint32_t *edges_ll;
  HXT_CHECK(hxtBoundariesGetEdgesOfLineLoop(meanValues->boundaries, meanValues->boundary,&edges_ll));
  //  printf("coucou31 %d\n",n);
  double totalLength, currentLength;;
  HXT_CHECK(hxtBoundariesGetLengthOfLineLoop(meanValues->boundaries,meanValues->boundary,&totalLength));
  //  printf("coucou31 %d\n",n);
  currentLength = 0;
  for(int i=0; i<n; i++){
    double angle = 2*M_PI * currentLength/totalLength;
    //    printf("%d/%d %g\n",i,n,angle);
    flag[edges->node[2*edges_ll[i]+0]] = 1;
    uv[2*edges->node[2*edges_ll[i]+0]+0] = cos(angle);
    uv[2*edges->node[2*edges_ll[i]+0]+1] = sin(angle);
    currentLength += hxtEdgesLength(meanValues->initialEdges, edges_ll[i]);
  }
  //  printf("coucou31\n");
  //  printf("coucou1\n");

  double *U, *V, *Urhs, *Vrhs;
  //printf("allocation: %d\n",nNodes+meanValues->nHoles);
  HXT_CHECK( hxtMalloc(&U,(nNodes+meanValues->nHoles)*sizeof(double)) );
  HXT_CHECK( hxtMalloc(&V,(nNodes+meanValues->nHoles)*sizeof(double)) );
  HXT_CHECK( hxtMalloc(&Urhs,(nNodes+meanValues->nHoles)*sizeof(double)) );
  HXT_CHECK( hxtMalloc(&Vrhs,(nNodes+meanValues->nHoles)*sizeof(double)) );
  //  printf("coucou1\n");


  // init linear system
  HXT_CHECK(hxtLinearSystemZeroMatrix(sys));
  for(uint32_t i=0; i<(nNodes+meanValues->nHoles); i++){
    Urhs[i] = 0.;
    Vrhs[i] = 0.;
  }

  // setting linear system
  for(uint32_t ie=0; ie<edges->numEdges; ie++){

    int ik[2] = {-1,-1};
    uint64_t *tri = edges->edg2tri + 2*ie;

    // gather local edge index
    for(int it=0; it<2; it++){
      if(tri[it]==(uint64_t)-1)
        break;
      for(int k=0; k<3; k++){
        if(edges->tri2edg[3*tri[it]+k]==ie){
          ik[it] = k;
          break;
        }
      }
    }

    for(int ij=0; ij<2; ij++){

      uint32_t v0 = edges->node[2*ie+ij];
      uint32_t v1 = edges->node[2*ie+(1-ij)];

      if (flag[v0]==1){//boundary nodes/conditons
	HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(sys,v0,0));
        HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,Urhs, v0,0, uv[2*v0+0]));
        HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,Vrhs, v0,0, uv[2*v0+1]));
      }
      else {// inner node
	double e[3] = {mesh->vertices.coord[4*v1+0]-mesh->vertices.coord[4*v0+0],mesh->vertices.coord[4*v1+1]-mesh->vertices.coord[4*v0+1],mesh->vertices.coord[4*v1+2]-mesh->vertices.coord[4*v0+2]};
	double ne = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);

        uint32_t vLeft = mesh->triangles.node[3*tri[0] + (ik[0]+2)%3];
        double a[3] = {mesh->vertices.coord[4*vLeft+0]-mesh->vertices.coord[4*v0+0],mesh->vertices.coord[4*vLeft+1]-mesh->vertices.coord[4*v0+1],mesh->vertices.coord[4*vLeft+2]-mesh->vertices.coord[4*v0+2]};
        double na = sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
        double thetaL = acos((a[0]*e[0]+a[1]*e[1]+a[2]*e[2])/(na*ne));

        double thetaR=0.;
        if(tri[1]==(uint64_t)-1)
          thetaR=0.;
        else{
          uint32_t vRight = mesh->triangles.node[3*tri[1] + (ik[1]+2)%3];
          double b[3] = {mesh->vertices.coord[4*vRight+0]-mesh->vertices.coord[4*v0+0],mesh->vertices.coord[4*vRight+1]-mesh->vertices.coord[4*v0+1],mesh->vertices.coord[4*vRight+2]-mesh->vertices.coord[4*v0+2]};
          double nb = sqrt(b[0]*b[0]+b[1]*b[1]+b[2]*b[2]);
          thetaR = acos((b[0]*e[0]+b[1]*e[1]+b[2]*e[2])/(nb*ne));
        }

        double c = (tan(.5*thetaL)+tan(.5*thetaR))/ne;
        HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, v0, 0, v1, 0, -c));
        HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, v0, 0, v0, 0, c));
      }
    }
  }// end for int ie


#ifdef __FILLERGAP_
  // holes are filled somehow
  for(int i=0; i<meanValues->nHoles; i++){

    HXT_CHECK(hxtBoundariesGetNumberOfEdgesOfLineLoop(meanValues->boundaries,meanValues->hole[i],&n));
    HXT_CHECK(hxtBoundariesGetEdgesOfLineLoop(meanValues->boundaries,meanValues->hole[i],&edges_ll));

    double length;
    HXT_CHECK(hxtBoundariesGetLengthOfLineLoop(meanValues->boundaries,meanValues->hole[i],&length));

    double *c, *d;
    HXT_CHECK(hxtMalloc(&c,n*sizeof(double)));
    HXT_CHECK(hxtMalloc(&d,n*sizeof(double)));

    double radius =  length/(2*M_PI);
    for(int j=0; j<n; j++){
      double le = hxtEdgesLength(meanValues->initialEdges, edges_ll[j]);
      double theta = 2* M_PI * le/length;

      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, edges->node[2*edges_ll[j]+0], 0, edges->node[2*edges_ll[j]+0], 0, tan(.5*(M_PI-theta)/2)/le ));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, edges->node[2*edges_ll[j]+0], 0, edges->node[2*edges_ll[j]+1], 0, -tan(.5*(M_PI-theta)/2)/le ));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, edges->node[2*edges_ll[j]+1], 0, edges->node[2*edges_ll[j]+1], 0, tan(.5*(M_PI-theta)/2)/le ));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, edges->node[2*edges_ll[j]+1], 0, edges->node[2*edges_ll[j]+0], 0, -tan(.5*(M_PI-theta)/2)/le ));

      c[j] = tan(.5*(M_PI-theta)/2)/radius;
      d[j] = tan(.5*(theta))/radius;
    }
    double tc = c[0], td = d[0];
    c[0] += c[n-1];
    d[0] += d[n-1];
    double sum = d[0];
    for(int j=1; j<n; j++){
      double t = c[j];
      c[j] += tc;
      tc = t;
      t = d[j];
      d[j] += td;
      sum += d[j];
      td = t;
    }

    for(int j=0; j<n; j++){

      uint32_t v = edges->node[2*edges_ll[j]+0];

      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, v, 0, v, 0, c[j]));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, v, 0,nNodes+i, 0, -c[j]));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, nNodes+i, 0, nNodes+i, 0, d[j]));
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, nNodes+i, 0, v, 0, -d[j]));

      //for(int k=0; k<n; k++)
      //HXT_CHECK(hxtLinearSystemAddMatrixEntry(sys, v, 0, edges->node[2*edges_ll[k]+0], 0, -c[j]*d[k]/sum));

    }
    HXT_CHECK(hxtFree(&c));
    HXT_CHECK(hxtFree(&d));
  }
#endif
  //  printf("coucou1\n");
  HXT_CHECK(hxtLinearSystemSolve(sys,Urhs,U));
  HXT_CHECK(hxtLinearSystemSolve(sys,Vrhs,V));
  for(uint32_t i=0; i<nNodes; i++){
    uv[2*i+0] = U[i] ;
    uv[2*i+1] = V[i] ;
  }
  //  printf("coucou2\n");

#ifdef __FILLERGAP_
  HXT_CHECK(hxtFree(&fillergap));
#endif
  HXT_CHECK(hxtFree(&flag));
  HXT_CHECK(hxtFree(&U));
  HXT_CHECK(hxtFree(&V));
  HXT_CHECK(hxtFree(&Urhs));
  HXT_CHECK(hxtFree(&Vrhs));
  HXT_CHECK(hxtLinearSystemDelete(&sys));
  //  printf("coucou3\n");

  return HXT_STATUS_OK;
}


HXTStatus hxtMeanValueAspectRatio(HXTMeanValues *meanValues, int *aspectRatio)
{

  if(meanValues->aspectRatio<0){
    *aspectRatio = 1;

    uint32_t numEdges = meanValues->initialEdges->numEdges;
    double *uv = meanValues->uv;
    uint32_t *nodes = meanValues->initialEdges->node;
    for(uint32_t i=0; i<numEdges; i++){
      double du = uv[2*nodes[2*i+1]+0] - uv[2*nodes[2*i+0]+0];
      double dv = uv[2*nodes[2*i+1]+1] - uv[2*nodes[2*i+0]+1];
      if(sqrt(du*du+dv*dv) < 1e-4){
	//	printf("coucou %12.5E %12.5E\n",du,dv);
        *aspectRatio = 0;
        break;
      }
    }
  }
  else
    *aspectRatio = meanValues->aspectRatio;


  return HXT_STATUS_OK;
}



HXTStatus hxtMeanValuesGetData(HXTMeanValues *mv, uint64_t **global,uint32_t **gn, double **uv, int *nv, int *ne, int onlyuv){

  *nv = mv->initialEdges->edg2mesh->vertices.num;
  *ne = mv->initialEdges->edg2mesh->triangles.num;


  if (uv!=NULL){
    double *uv_;
    HXT_CHECK(hxtMalloc(&uv_,2*(*nv)*sizeof(double)));
    for(int iv=0; iv<2*(*nv); iv++)
      uv_[iv] = mv->uv[iv];
    *uv=uv_;
  }
  if (onlyuv) return HXT_STATUS_OK;

  uint64_t *global_;
  HXT_CHECK(hxtMalloc(&global_,(*ne)*sizeof(uint64_t)));
  uint32_t *gn_;

  if (gn!=NULL)
    HXT_CHECK(hxtMalloc(&gn_,sizeof(uint32_t)*3*(*ne)));
  for(int ie=0; ie<(*ne); ie++){
    global_[ie] = mv->initialEdges->global[ie];
    if(gn!=NULL)
      for(int kk=0; kk<3; kk++)
        gn_[3*ie+kk] = mv->initialEdges->edg2mesh->triangles.node[3*ie+kk];

  }

  *global = global_;
  if(gn!=NULL)
    *gn = gn_;

  return HXT_STATUS_OK;
}


#ifdef HXT_CORE_FILEIO
HXTStatus hxtMeanValuesWrite(HXTMeanValues *meanValues, const char* filename)
{

  HXTMesh *mesh = meanValues->initialEdges->edg2mesh;

  char strMesh[64];
  strcpy(strMesh,"MESH_");
  strcat(strMesh,filename);

  HXT_CHECK(hxtMeshWriteGmsh(mesh,strMesh));

  uint32_t nnodes = mesh->vertices.num;

  char strU[64];
  strcpy(strU,"U_");
  strcat(strU,filename);

  char strV[64];
  strcpy(strV,"V_");
  strcat(strV,filename);

  FILE* ufile = fopen(strU,"w");
  fprintf(ufile,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$NodeData\n1\n\"u-component\"\n1\n0\n3\n0\n1\n%u\n",nnodes);
  FILE* vfile = fopen(strV,"w");
  fprintf(vfile,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$NodeData\n1\n\"v-component\"\n1\n0\n3\n0\n1\n%u\n",nnodes);

  for (uint32_t i=0; i<nnodes; i++){
    fprintf(ufile,"%u %f\n",i+1,meanValues->uv[2*i+0]);
    fprintf(vfile,"%u %f\n",i+1,meanValues->uv[2*i+1]);
  }

  fprintf(ufile,"$EndNodeData");
  fprintf(vfile,"$EndNodeData");

  fclose(ufile);
  fclose(vfile);

  return HXT_STATUS_OK;
}


HXTStatus hxtMeanValuesWriteParamMesh(HXTMeanValues *meanValues,const char* filename)
{

  double *uv = meanValues->uv;
  HXTMesh *mesh = meanValues->initialEdges->edg2mesh;

  FILE* file = fopen(filename,"w");
  fprintf(file,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n%u\n",mesh->vertices.num);
  for(int i=0; i<(int)mesh->vertices.num; i++)
    fprintf(file,"%d %f %f 0\n",i+1,uv[2*i+0],uv[2*i+1]);
  fprintf(file,"$EndNodes\n$Elements\n%d\n",(int)mesh->triangles.num);
  for(int i=0; i<(int)mesh->triangles.num; i++)
    fprintf(file,"%d 2 2 0 0 %d %d %d\n",i+1,mesh->triangles.node[3*i+0]+1,mesh->triangles.node[3*i+1]+1,mesh->triangles.node[3*i+2]+1);
  fprintf(file,"$EndElements\n");

  return HXT_STATUS_OK;
}

#endif
