#include "hxt_qmbQuadGenerator.h"
#include "hxt_qmbMultiBlock.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
}
#include <iostream>
#include <string>
#include <algorithm>

// #include "hxt_gmsh_link.h"
// #ifdef GMSH_LINKED
#include "gmsh.h"
// #endif

static inline HXTStatus myNormalizedCrossprod(double *a, double *b, double *n)
{ 
  n[0] = a[1]*b[2]-a[2]*b[1];
  n[1] = a[2]*b[0]-a[0]*b[2];
  n[2] = a[0]*b[1]-a[1]*b[0];
  double nn = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  n[0] /= nn; n[1] /= nn; n[2] /= nn;

  return HXT_STATUS_OK;
}

static void normalize(double *d)
{
  double n = sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
  d[0]/=n;
  d[1]/=n;
  d[2]/=n;
}
static inline double myDot(double *a, double *b)
{
  double d = 0.;
  for (int i=0; i<3; i++)
    d += a[i]*b[i];
  return d;
}

static inline HXTStatus crossprod(double *a, double *b, double *n)
{
  n[0] = a[1]*b[2]-a[2]*b[1];
  n[1] = a[2]*b[0]-a[0]*b[2];
  n[2] = a[0]*b[1]-a[1]*b[0];

  return HXT_STATUS_OK;
}

static inline int comparator(const void *p1, const void *p2)
{
  uint64_t *e0 = (uint64_t*)p1; 
  uint64_t *e1 = (uint64_t*)p2;
  return (int)(*(e0)-*(e1));
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

HXTStatus QuadGenerator::trianglebasis(HXTMesh *m, uint32_t *vtri, double *U, double *V, double *n)
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
  
  return HXT_STATUS_OK;
}

int QuadGenerator::triRot(uint32_t singularEdge, int triNum, int *rotationEdges, int *rotationVertices){
  HXTEdges *edg=m_triEdges;
  int num=1;
  int notfound = 1;
  for(int i=0; i<3;i++){
    if(singularEdge == edg->tri2edg[3*triNum+i]){
      num=i;
      notfound=0;
    }
  }
  if(notfound)
  std:: cout << "triangle rotation have not found edge on triangle" <<  std::endl;
  rotationEdges[0]= (num-1+3)%3; rotationEdges[1]= (num+3)%3; rotationEdges[2]= (num+1+3)%3;
  rotationVertices[0]=(num-1+3)%3; rotationVertices[1]= (num+3)%3; rotationVertices[2]=(num+1+3)%3;
  
  return 1;
}

QuadGenerator::QuadGenerator(HXTMesh *mesh, int nbTurns, double critNorm, int flagTypePos, const char *fileName)
{
  m_nbTurns=nbTurns;
  if(critNorm<0)
    m_critNorm=0.6;
  else
    m_critNorm=critNorm;
  m_flagTypePosCF=flagTypePos;
  m_filePosCF=fileName;
  //clean mesh here
  m_triMesh=mesh;
  m_sizeSeeding=1000;
  m_mBlock=NULL;
}

QuadGenerator::~QuadGenerator()
{
  if(m_crossfield)
    hxtFree(&m_crossfield);
  if(m_triEdges)
    hxtEdgesDelete(&(m_triEdges));
  if(m_mBlock)
    delete m_mBlock;
}

static inline int isPointDuplicate(double *point1, double *point2, double *norm){
  double a=point1[0]-point2[0];
  double b=point1[1]-point2[1];
  double c=point1[2]-point2[2];
  *norm=sqrt(a*a+b*b+c*c);
  if(*norm<=1e-6)
    return 1;
  else
    return 0;
}

//1. prepare geo
HXTStatus QuadGenerator::prepareGeoFile(std::string geoFileName, double *directionsCR){
  std::cout<<"--Writing singularities in geo file--"<<std::endl;
  HXT_CHECK(hxtEdgesCreate(m_triMesh,&m_triEdges));
  HXT_CHECK(hxtMalloc(&m_crossfield,2*m_triEdges->numEdges*sizeof(double)));
  for(uint64_t i=0;i<m_triEdges->numEdges;i++){
    m_crossfield[2*i+0]=directionsCR[2*i+0];
    m_crossfield[2*i+1]=directionsCR[2*i+1];
  }
  //locate singularities and corners
  std::cout << "--Find singularities--" << std::endl;
  findSingularitiesAndCreatePatches();
  std::cout << "--Write singularities--" << std::endl;
  hxtWriteSingularities("qmbSingularities.pos");
  std::cout << "--Write patches--" << std::endl;
  hxtWritePatches("qmbPatches.pos");
  std::cout << "--Build corners--" << std::endl;
  std::cout << "--Disable singularities on boundary and corner patches--" << std::endl;
  buildCorners();
  std::cout << "nSing before cleaning : " << m_vectSing.size() << std::endl;
  cleanSingularities();
  std::cout << "nSing after cleaning : " << m_vectSing.size() << std::endl;
  std::cout << "--Write corners--" << std::endl;
  hxtWriteCorners("qmbCorners.pos");
  std::cout << "--Write corner patches--" << std::endl;
  hxtWriteCornerPatches("qmbCornerPatches.pos");
  std::cout << "--Create boundaryLines--" << std::endl;
  createBoundaryLines();
  std::cout << "--Build Boundary--" << std::endl;
  buildBoundary();
  std::cout << "--Write boundary lines--" << std::endl;
  hxtWriteBdryLines("qmbBoundaryLines.pos");
  std::cout << "--Start initiation from corners--" << std::endl;
  initiationFromCorner();
  std::cout << "--Start initiation from singularities--" << std::endl;
  initiationFromSingularities();
  std::cout << "--Write separatrices initiation --" << std::endl;
  hxtWriteInitSep("qmbInitiation.pos");
  std::cout << "--Disable duplicates--" << std::endl;
  for(uint64_t t=0; t<m_vectSing.size(); t++)
    disableSepDuplicates((int) t);
  std::cout << "--Write separatrices initiation without duplicates--" << std::endl;
  hxtWriteInitSep("qmbInitiationNoDuplicates.pos");
  std::cout << "--Save bdry lines as separatrices--" << std::endl;
  saveBdryLinesAsSeparatrices();
  std::cout << "--Fill geo file--" << std::endl;
  fillGeoFile(geoFileName);
  std::cout << "     <-END->" << std::endl;
  std::cout<<" " <<std::endl;
  
  return HXT_STATUS_OK;
}


HXTStatus QuadGenerator::loadDirectionFieldCR(HXTEdges *edges, const char *fileName, int nbTurns, double *crossfield)
{
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t *edg2tri = edges->edg2tri;
  FILE* myfile = fopen(fileName,"r");
  if (!myfile) return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED, "mesh file '%s' cannot be opened",(fileName==NULL)?"NULL":fileName);
  char buf[BUFSIZ]={""};
  double a,b,c;
  if(fgets(buf, BUFSIZ, myfile)!=NULL){
    // if(strstr(buf, "View \"Direction fields\"{")){
      for(uint64_t i=0; i<edges->numEdges; i++){
	const double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
	const double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
	double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
	double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
	e[0] /= norm; e[1] /= norm; e[2] /= norm;
	for(int t=0; t<2; t++){// for each triangle
	  int  numtri = edg2tri[2*i+t];
	  if(numtri != -1){
	    if(fgets(buf, BUFSIZ, myfile)!=NULL){
	      double x,y,z;
	      sscanf(buf, "VP(%lf,%lf,%lf){%lf,%lf,%lf}",&x,&y,&z,&a,&b,&c);
	      double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};        
	      uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
	      HXT_CHECK( trianglebasis(mesh,vtri,U,V,n) );
	      double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
	      double norm2 = sqrt(a*a + b*b + c*c);
	      double cosTheta = (a*e[0] + b*e[1] + c*e[2])/norm2;
	      double sinTheta = (a*f[0] + b*f[1] + c*f[2])/norm2;
	      double theta = atan2(sinTheta,cosTheta);
	      crossfield[2*i+0] = norm2*cos(nbTurns*theta);
	      crossfield[2*i+1] = norm2*sin(nbTurns*theta);
	      for(int nb=1; nb<nbTurns; nb++){
		if(fgets(buf, BUFSIZ, myfile)!=NULL){
		}
	      }
	    }
	  }// end if
	}//end for t
      }
    // }
    // else{
    //   return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Wrong HXT directionField Format");
    // }
  }
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::loadDirectionFieldLag(HXTEdges *edges, const char *fileName, int nbTurns, double *crossfield)
{
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t *edg2tri = edges->edg2tri;
  FILE* myfile = fopen(fileName,"r");
  if (!myfile) return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED, "mesh file '%s' cannot be opened",(fileName==NULL)?"NULL":fileName);
  char buf[BUFSIZ]={""};
  int numNodes= mesh->vertices.num;
  double *crossNodes; //value of a crossfield in a node
  HXT_CHECK(hxtMalloc(&crossNodes,3*numNodes*sizeof(double)));
  double a,b,c;
  if(fgets(buf, BUFSIZ, myfile)!=NULL){
    if(strstr(buf, "View \"Direction fields\"{")){
      int num=0;
      for(int i=0; i<4*numNodes; i+=nbTurns){// for each node get one vector
	if(fgets(buf, BUFSIZ, myfile)!=NULL){
	  sscanf(buf, "VP(%*f,%*f,%*f){%lf,%lf,%lf}",&a,&b,&c);
	  crossNodes[3*num+0]=a;
	  crossNodes[3*num+1]=b;
	  crossNodes[3*num+2]=c;
	  num++;
	  for (int j=0; j<nbTurns-1; j++)
	    if(fgets(buf, BUFSIZ, myfile)!=NULL){
	    }
	}
      }//end for i
      for(uint64_t i=0; i<edges->numEdges; i++){
	const double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
	const double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
	double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
	double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
	e[0] /= norm; e[1] /= norm; e[2] /= norm;
	int node1= edges->node[2*i+0];
	int node2= edges->node[2*i+1];
	uint64_t numtri = edg2tri[2*i+0];
	double a1=crossNodes[3*node1+0];
	double b1=crossNodes[3*node1+1];
	double c1=crossNodes[3*node1+2];
	double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};        
	uint32_t vtri[3] = {mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
	HXT_CHECK(trianglebasis(mesh,vtri,U,V,n) );
	double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
	double norm2 = sqrt(a1*a1 + b1*b1 + c1*c1);
	double cosTheta1 = (a1*e[0] + b1*e[1] + c1*e[2])/norm2;
	double sinTheta1 = (a1*f[0] + b1*f[1] + c1*f[2])/norm2;
	double theta1 = atan2(sinTheta1,cosTheta1);
	double N1[3];
	N1[0]=norm2*cos(nbTurns*theta1)*e[0]+norm2*sin(nbTurns*theta1)*f[0];
	N1[1]=norm2*cos(nbTurns*theta1)*e[1]+norm2*sin(nbTurns*theta1)*f[1];
	N1[2]=norm2*cos(nbTurns*theta1)*e[2]+norm2*sin(nbTurns*theta1)*f[2];

	double a2=crossNodes[3*node2+0]; 
	double b2=crossNodes[3*node2+1];
	double c2=crossNodes[3*node2+2];
	double norm3 = sqrt(a2*a2 + b2*b2 + c2*c2);
	double cosTheta2 = (a2*e[0] + b2*e[1] + c2*e[2])/norm3;
	double sinTheta2 = (a2*f[0] + b2*f[1] + c2*f[2])/norm3;
	double theta2 = atan2(sinTheta2,cosTheta2);
	double N2[3];
	N2[0]=norm3*cos(nbTurns*theta2)*e[0]+norm3*sin(nbTurns*theta2)*f[0];
	N2[1]=norm3*cos(nbTurns*theta2)*e[1]+norm3*sin(nbTurns*theta2)*f[1];
	N2[2]=norm3*cos(nbTurns*theta2)*e[2]+norm3*sin(nbTurns*theta2)*f[2];
	
	double Ni[3]={(N1[0]+N2[0])/2.0, (N1[1]+N2[1])/2.0, (N1[2]+N2[2])/2.0};
	crossfield[2*i+0] = Ni[0]*e[0]+Ni[1]*e[1]+Ni[2]*e[2];
	crossfield[2*i+1] = Ni[0]*f[0]+Ni[1]*f[1]+Ni[2]*f[2];
      }//end for edges
    }
    else{
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Wrong HXT directionField Format");
    }
  }
  HXT_CHECK(hxtFree(&crossNodes));
  fclose(myfile);
  return HXT_STATUS_OK;
}

/* Return a full sorted list of flagged singular elements, the number of repetition of those singular elements in the array, and the number of singularities */
/* This function has to be used before locateSingularity() */
int QuadGenerator::listSingularElements(uint64_t *masterElement, uint64_t *elemFlagged, int *sizeSingularEdges, int *elemOcc)
{
  double *crossField=m_crossfield;
  HXTEdges *edg=m_triEdges;
  double *normField;
  HXT_CHECK(hxtMalloc(&normField,edg->numEdges*sizeof(double)));
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    normField[ie] = sqrt(crossField[2*ie+0]*crossField[2*ie+0] + crossField[2*ie+1]*crossField[2*ie+1]);
  }
  for(uint32_t it=0;it<edg->edg2mesh->triangles.num;it++){
    masterElement[it] = (uint64_t)-1;
  }
  double critNorm = m_critNorm;
  for(uint32_t ie=0;ie<2*edg->numEdges;ie++){
    elemFlagged[ie]=-1;
  }
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    if(normField[ie]<critNorm){
      elemFlagged[2*ie+0]= edg->edg2tri[2*ie+0];
      elemFlagged[2*ie+1]= edg->edg2tri[2*ie+1];
      uint64_t masterE1 = edg->edg2tri[2*ie+0];
      uint64_t masterE2 = edg->edg2tri[2*ie+1];
      while(masterElement[masterE1]!=(uint64_t)-1)
	masterE1 = masterElement[masterE1];
      if(masterE2!=(uint64_t)-1){
	while(masterElement[masterE2]!=(uint64_t)-1)
	  masterE2 = masterElement[masterE2];
      }
      double normE1 = 2.;
      double normE2 = 2.;
      for(int j=0;j<3;j++){
	normE1 = fmin(normE1,normField[edg->tri2edg[3*masterE1+j]]);
	if(masterE2!=(uint64_t)-1)
	  normE2 = fmin(normE2,normField[edg->tri2edg[3*masterE2+j]]);
      }
      if((normE1<=normE2)&&(masterE2!=(uint64_t)-1)&&(masterE1!=masterE2)){
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
  for(uint32_t it=0;it<edg->edg2mesh->triangles.num;it++){
    int master=it;
    while(masterElement[master]!=(uint64_t)-1)
      master = masterElement[master];
    if(masterElement[it]!=(uint64_t)-1)
      masterElement[it] = master;
  }

  //Adding masterElements as their own masters
  for(uint32_t j=0;j<edg->edg2mesh->triangles.num;j++){
    if(masterElement[j]!=(uint64_t)-1)
      masterElement[masterElement[j]]=masterElement[j];
  }
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    elemFlagged[2*ie+0] = masterElement[edg->edg2tri[2*ie+0]];
    if(edg->edg2tri[2*ie+1]!=(uint64_t)-1)
      elemFlagged[2*ie+1] = masterElement[edg->edg2tri[2*ie+1]];
  }

  //Merging patches which are in contact
  double *minNormTri;
  HXT_CHECK(hxtMalloc(&minNormTri,edg->edg2mesh->triangles.num*sizeof(double)));
  for(uint32_t j=0;j<edg->edg2mesh->triangles.num;j++){
    double minNorm =2.0;
    for(int k=0;k<3;k++){
      minNorm = fmin(minNorm,normField[edg->tri2edg[3*j+k]]);
    }
    minNormTri[j]=minNorm;
  }
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    if(elemFlagged[2*ie+0]!=(uint64_t)-1&&elemFlagged[2*ie+1]!=(uint64_t)-1){
      if(elemFlagged[2*ie+0]!=elemFlagged[2*ie+1]){
	double normMaster0=minNormTri[elemFlagged[2*ie+0]];
	double normMaster1=minNormTri[elemFlagged[2*ie+1]];
	uint64_t newMaster,newSlave;
	if(normMaster0<=normMaster1){
	  newMaster=elemFlagged[2*ie+0];
	  newSlave=elemFlagged[2*ie+1];
	}
	else{
	  newMaster=elemFlagged[2*ie+1];
	  newSlave=elemFlagged[2*ie+0];
	}
	for(uint32_t k=0;k<2*edg->numEdges;k++){
	  if(elemFlagged[k]==newSlave){
	    elemFlagged[k]=newMaster;
	  }
	}
	for(uint32_t k=0;k<edg->edg2mesh->triangles.num;k++){
	  if(masterElement[k]==newSlave){
	    masterElement[k]=newMaster;
	  }
	}
      }
    }
  }

 //beginning singular patch triangles--------------------------------------------------------
  int *singularPatchTri;
  HXT_CHECK(hxtMalloc(&singularPatchTri,edg->edg2mesh->triangles.num*sizeof(uint64_t)));
  for(uint32_t j=0;j<edg->edg2mesh->triangles.num;j++){
    singularPatchTri[j]=masterElement[j];
  }
  int nbLayers=0;
  for(uint32_t j=0;j<edg->edg2mesh->triangles.num;j++){
    singularPatchTri[j]=masterElement[j];
  }
  for(int i=0;i<nbLayers;i++){
    int triEdg, neighbour, element;
    for(uint32_t i=0;i<edg->edg2mesh->triangles.num;i++){
      if(singularPatchTri[i]==-1){
  	for(int j=0; j<3; j++){
  	  //traversing all edges of triangle i to find all neighbours
  	  triEdg=edg->tri2edg[3*i+j];
  	  if(edg->edg2tri[2*triEdg+0]!=i){
  	    neighbour=edg->edg2tri[2*triEdg+0];
  	  }else
  	    neighbour=edg->edg2tri[2*triEdg+1];
  	  //neighbour found, checking if its not the boundary and which element it is - in case it has its master
  	  if(neighbour>=0){
  	    element=masterElement[neighbour];
  	  }
	  else
	    element=-1;
  	  if(element!=-1){
  	    singularPatchTri[i]=element;
  	  }
  	}
      }
    }
    for(uint32_t j=0;j<edg->edg2mesh->triangles.num;j++){
      masterElement[j]=singularPatchTri[j];
    }
  }

 for(uint32_t ie=0;ie<edg->numEdges;ie++){
    elemFlagged[2*ie+0] = singularPatchTri[edg->edg2tri[2*ie+0]];
    if(edg->edg2tri[2*ie+1]!=(uint64_t)-1)
      elemFlagged[2*ie+1] = singularPatchTri[edg->edg2tri[2*ie+1]];
  }
  //end singular patch triangles------------------------
  
  qsort(elemFlagged,2*edg->numEdges,sizeof(uint64_t),comparator);
  uint32_t i=0;
  int nDiffElem =0;
  while(i<2*edg->numEdges-1){
    int cpt =1;
    while((elemFlagged[i]==elemFlagged[i+1])&&i<2*edg->numEdges-2){
      cpt++;
      i++;
    }
    elemOcc[nDiffElem]=cpt;
    nDiffElem++;
    i++;
  }
  *sizeSingularEdges = nDiffElem-1;

  HXT_CHECK(hxtFree(&minNormTri));
  HXT_CHECK(hxtFree(&normField));
  HXT_CHECK(hxtFree(&singularPatchTri));
  return 1;
}
/* Return the list of singularities (by returning the singular edges number) */
/* Has to be used after listSingularElements() */
int QuadGenerator::locateSingularity(uint64_t *elemFlagged, uint64_t *singularEdges, int *sizeSingularEdges, int *elemOcc)
{
  double *crossField=m_crossfield;
  HXTEdges *edg=m_triEdges;
  double *normField;
  HXT_CHECK(hxtMalloc(&normField,edg->numEdges*sizeof(double)));
  for(uint32_t ie=0;ie<edg->numEdges;ie++){
    normField[ie] = sqrt(crossField[2*ie+0]*crossField[2*ie+0] + crossField[2*ie+1]*crossField[2*ie+1]);
  }
  int offset = 0;
  for(int j=0;j<sizeSingularEdges[0];j++){
    double norm = 2;
    int edgeSing = -1;
    offset = offset + elemOcc[j];
    uint64_t elemSing = elemFlagged[offset];
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

int QuadGenerator::getMiddleEdgeCoord(uint64_t globalEdgeNum, std::array<double,3> *coord)
{
  HXTEdges *edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  int indNode1=edg->node[2*globalEdgeNum+0];
  int indNode2=edg->node[2*globalEdgeNum+1];
  double node1Coord[3], node2Coord[3];
  for(int i=0; i<3; i++){
    node1Coord[i]=m->vertices.coord[4*indNode1+i];
    node2Coord[i]=m->vertices.coord[4*indNode2+i];
    (*coord)[i]=(node1Coord[i]+node2Coord[i])*0.5;
  }
  
  return 1;
}

//Finding singular edges, singular points and patches +  writing pos files
HXTStatus QuadGenerator::findSingularitiesAndCreatePatches(){
  HXTEdges* edges=m_triEdges;
  uint64_t* elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, 2*edges->numEdges*sizeof(uint64_t)));
  int* elemOcc;
  HXT_CHECK(hxtMalloc(&elemOcc, edges->edg2mesh->triangles.num*sizeof(int)));
  int sizeSingularEdges=0;
  uint64_t *masterElement;
  HXT_CHECK(hxtMalloc(&masterElement,edges->edg2mesh->triangles.num*sizeof(uint64_t)));
  listSingularElements(masterElement,elemFlagged, &sizeSingularEdges, elemOcc);
  uint64_t *singularEdges;
  HXT_CHECK(hxtMalloc(&(singularEdges), sizeSingularEdges*sizeof(uint64_t)));
  locateSingularity(elemFlagged, singularEdges, &sizeSingularEdges, elemOcc);
  for(int i=0; i<sizeSingularEdges; i++){
    std::vector<uint64_t> patch;
    uint64_t masterElemSing=edges->edg2tri[2*singularEdges[i]+0];
    uint64_t masterElemSing2=edges->edg2tri[2*singularEdges[i]+1];
    uint64_t nTri=edges->edg2mesh->triangles.num;
    for(uint64_t j=0; j<nTri; j++){
      if(masterElement[j]==masterElemSing||(masterElemSing2!=(uint64_t)-1 && masterElement[j]==masterElemSing2))
	patch.push_back(j);
    }
    std::array<double,3> coord;
    getMiddleEdgeCoord(singularEdges[i], &coord);
    Singularity s(i, singularEdges[i], coord, patch);
    m_vectSing.push_back(s);
    m_crossfield[2*singularEdges[i]+0]=0.0;
    m_crossfield[2*singularEdges[i]+1]=0.0;
  }
  HXT_CHECK(hxtFree(&masterElement));
  HXT_CHECK(hxtFree(&singularEdges));
  HXT_CHECK(hxtFree(&elemFlagged));
  HXT_CHECK(hxtFree(&elemOcc));
  
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteSingularities(const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Singularities\" {\n");
  for(uint32_t i=0; i<m_vectSing.size(); i++){
    int color=i;
    Singularity *s=&(m_vectSing[i]);
    if(!s->isDisabled()){
      std::array<double,3> coord=s->getCoord();
      fprintf(f,"SP(%g,%g,%g){%i};\n", coord[0], coord[1], coord[2], color);
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWritePatches(const char *fileName){
  HXTEdges *edges=m_triEdges;
  HXTMesh *mesh=edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  uint64_t *elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    elemFlagged[i]=0;
  for(uint32_t k=0; k<m_vectSing.size(); k++){
    Singularity *s=&(m_vectSing[k]);
    if(!s->isDisabled()){
      std::vector<uint64_t> patch=s->getPatch();
      for(uint32_t j=0; j<patch.size(); j++){
	uint64_t tri=patch[j];
	elemFlagged[tri]=1;
      }
    }
  }
  
  fprintf(f,"View \"Flagged patches\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(f,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    for(uint32_t j=0; j<3; j++){
      fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(f,",");
    }
    fprintf(f,")");
    fprintf(f,"{");
    fprintf(f,"%lX, %lX, %lX",elemFlagged[i],elemFlagged[i],elemFlagged[i]);
    fprintf(f,"};\n");    
  }
  fprintf(f,"};");
  fclose(f);
  
  HXT_CHECK(hxtFree(&elemFlagged));
  return HXT_STATUS_OK;
}

int QuadGenerator::getCornerGlobalVertexInd(std::vector<std::vector<uint64_t>> *boundaryVert2Edg, std::vector<uint64_t> *cornerIndices)
{
  HXTEdges* edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  int *boundaryEdg;
  HXT_CHECK(hxtMalloc(&boundaryEdg,edg->numEdges*sizeof(int)));
  for(uint64_t i=0; i<edg->numEdges; i++){
    boundaryEdg[i]=0;
  }
  for(uint64_t i=0; i<edg->numEdges; i++){
    if((edg->edg2tri[2*i+1]==(uint64_t)-1)){ //with H func - circle around sing not to be bdry
      boundaryEdg[i]=1;
    }
  }
  for(uint64_t i=0; i<edg->numEdges; i++){
    if(boundaryEdg[i]==1){
      int node1= edg->node[2*i+0];
      int node2= edg->node[2*i+1];
      (*boundaryVert2Edg)[node1].push_back(i);
      (*boundaryVert2Edg)[node2].push_back(i);   
    }  
  }
  // finding corners with multiplicity
  int *isVertCorner;
  HXT_CHECK(hxtMalloc(&isVertCorner,edg->edg2mesh->vertices.num*sizeof(int)));
  for(uint64_t i=0; i<edg->edg2mesh->vertices.num; i++)
    isVertCorner[i]=0;
  for(uint64_t i=0; i<edg->edg2mesh->vertices.num; i++){
    if((*boundaryVert2Edg)[i].size()>2 || (*boundaryVert2Edg)[i].size()==1){ //coment about circle not-corners stuff
      isVertCorner[i]=1; 
    }
  }
  // feature line : we can also check multiplicity of nodes connectivity with boundary/feature edges. if > 2 it's a corner for sure
  double alpha=0.0;
  double vert0[3], vert1[3], vert2[3];
  for(uint64_t i=0; i<edg->edg2mesh->vertices.num; i++){
    if(isVertCorner[i]){
      cornerIndices->push_back(i);
    }
    else if((*boundaryVert2Edg)[i].size()>0){
      double *v0 = m->vertices.coord + 4*edg->node[2*(*boundaryVert2Edg)[i][0]+0];
      double *v1 = m->vertices.coord + 4*edg->node[2*(*boundaryVert2Edg)[i][0]+1];
      double *v2 = m->vertices.coord + 4*edg->node[2*(*boundaryVert2Edg)[i][1]+0];
      double *v3 = m->vertices.coord + 4*edg->node[2*(*boundaryVert2Edg)[i][1]+1];
      if(edg->node[2*(*boundaryVert2Edg)[i][0]+0]==edg->node[2*(*boundaryVert2Edg)[i][1]+0]){
  	for(int j=0; j<3; j++){
  	  vert0[j]=v0[j];
  	  vert1[j]=v1[j];
  	  vert2[j]=v3[j];
  	}
      }else if(edg->node[2*(*boundaryVert2Edg)[i][0]+0]==edg->node[2*(*boundaryVert2Edg)[i][1]+1]){
  	for(int j=0; j<3; j++){
  	  vert0[j]=v0[j];
  	  vert1[j]=v1[j];
  	  vert2[j]=v2[j];
  	}
      }else if(edg->node[2*(*boundaryVert2Edg)[i][0]+1]==edg->node[2*(*boundaryVert2Edg)[i][1]+0]){
  	for(int j=0; j<3; j++){
  	  vert0[j]=v1[j];
  	  vert1[j]=v0[j];
  	  vert2[j]=v3[j];
  	}
      }else{
  	for(int j=0; j<3; j++){
  	  vert0[j]=v1[j];
  	  vert1[j]=v0[j];
  	  vert2[j]=v2[j];
  	}
      }
      double e[3] = {vert1[0]-vert0[0], vert1[1]-vert0[1], vert1[2]-vert0[2]};
      normalize(e); 
      double e1[3] ={vert0[0]-vert2[0],vert0[1]-vert2[1],vert0[2]-vert2[2]}; 
      normalize(e1);
      alpha=myDot(e,e1);
      if(alpha<=(sqrt(2)/2+1e-10)){
	cornerIndices->push_back(i);
      }      
    }
  }
  HXT_CHECK(hxtFree(&(boundaryEdg)));
  HXT_CHECK(hxtFree(&(isVertCorner)));
  return 1;
}

int QuadGenerator::cornerTri(std::vector<uint64_t> cornerIndices,  std::vector<uint64_t> *corner2Tri, int *sizeCorner2Tri)
{
  HXTEdges* edg=m_triEdges;
  HXTMesh *mesh = edg->edg2mesh;
  for(uint64_t i=0; i<cornerIndices.size(); i++){
    int num=0;
    for(uint64_t j=0; j<edg->edg2mesh->triangles.num; j++){
      uint32_t  vtri[3] =  {mesh->triangles.node[3*j+0],mesh->triangles.node[3*j+1],mesh->triangles.node[3*j+2]};
      for(int k=0; k<3; k++){
	if(vtri[k]==cornerIndices[i]){
	  corner2Tri->push_back(j);
	  num++;
	}
      }
    }
    sizeCorner2Tri[i]=num;
  }

  return 1;
}

int QuadGenerator::cornerEdg(std::vector<std::vector<uint64_t>> *boundaryVert2Edg, std::vector<uint64_t> cornerIndices,  std::vector<uint64_t> corner2Tri, int *sizeCorner2Tri, std::vector<uint64_t> *corner2Edg, int *sizeCorner2Edg)
{
  HXTEdges* edg=m_triEdges;
  for(uint64_t i=0; i<cornerIndices.size(); i++){
    uint64_t e1=(uint64_t)-1;
    uint64_t e2=(uint64_t)-1;
    std::vector<uint64_t> vert2Edg = (*boundaryVert2Edg)[cornerIndices[i]];
    for(uint64_t k=0; k<vert2Edg.size(); k++){
      if(edg->edg2tri[2*vert2Edg[k]+1]==(uint64_t)-1){
	if(e1==(uint64_t)-1)
	  e1=vert2Edg[k];
	else if(e2==(uint64_t)-1)
	  e2=vert2Edg[k];
      }
    }
    int offset2=0;
    for(uint64_t m=0; m<i; m++){
      offset2=offset2+sizeCorner2Edg[m];
    }
    uint64_t *edges;
    HXT_CHECK(hxtMalloc(&edges, 3*sizeCorner2Tri[i]*sizeof(uint64_t)));
    for(int j=0; j<3*sizeCorner2Tri[i]; j++)
      edges[j]=(uint64_t)-1;
    for(int j=0; j<sizeCorner2Tri[i]; j++){
      uint64_t triNum=corner2Tri[offset2+j];
      for(int k=0; k<3; k++){
	edges[3*j+k]=edg->tri2edg[3*triNum+k];
      }
    }
    for(int j=0; j<3*sizeCorner2Tri[i]-1; j++){
      for(int k=j+1; k<3*sizeCorner2Tri[i]; k++){
	if(edges[j]==edges[k]){
	  edges[j]=(uint64_t)-1;
	  edges[k]=(uint64_t)-1;
	}
      }
    }
    for(int j=0; j<3*sizeCorner2Tri[i]; j++){
      if(edges[j]==e1 || edges[j]==e2){
	edges[j]=(uint64_t)-1;
      }
    }
    int sum=0;
    int offset=0;
    for(uint64_t m=0; m<i; m++){
      offset=offset+sizeCorner2Edg[m];
    }
    for(int j=0; j<3*sizeCorner2Tri[i]; j++){
      if(edges[j]!=(uint64_t)-1){
	corner2Edg->push_back(edges[j]);
	sum++;	   
      }
    }
    sizeCorner2Edg[i]=sum;
    HXT_CHECK(hxtFree(&edges));
  }
  return 1;
}

int QuadGenerator::checkIfInCornerPatch(uint64_t triNum, bool *isInPatch, uint64_t *patchID){
  *isInPatch=0;
  *patchID=(uint64_t) -1;
  for(uint64_t ip=0; ip<m_vectCorner.size(); ip++){
    Corner c=m_vectCorner[ip];
    std::vector<uint64_t> patch=c.getPatch();
    for(uint64_t ie=0; ie<patch.size(); ie++){
      if(triNum==patch[ie]){
	*isInPatch=1;
	*patchID=ip;
      }
    }
  }
  return 1;
}

HXTStatus QuadGenerator::singEdgToNode(uint64_t edgNum, uint64_t  *nodeID){
  HXTEdges* edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  uint64_t triNum=edg->edg2tri[2*edgNum+0];
  double *crossField=m_crossfield;
  int nbTurns=m_nbTurns;
  double *vert = m->vertices.coord;

  int k=-1;
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*triNum+i]){
      k=i;
    }
  }
  double U[3],V[3],e[3],e1[3];
  for(int j=0;j<3;j++){
    U[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+0];
    V[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+1];
  }
  uint32_t vTriNum[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3],m->triangles.node[3*triNum+(k+2)%3]};
  double u1[3]={0,0,0};
  double v1[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(m,vTriNum,u1,v1,n);
  int edgNum1=edg->tri2edg[3*triNum+(k+1)%3];
  int edgNum2=edg->tri2edg[3*triNum+(k+2)%3];
  for(int j=0; j<3; j++){
    e[j]=vert[4*edg->node[2*edgNum2+1]+j]-vert[4*edg->node[2*edgNum2+0]+j];
    e1[j]=vert[4*edg->node[2*edgNum1+1]+j]-vert[4*edg->node[2*edgNum1+0]+j];
  }
  normalize(e); normalize(e1);
  double angAlpha2 = atan2(myDot(e,v1), myDot(e,u1));
  double angAlpha1 = atan2(myDot(e1,v1), myDot(e1,u1));
  multR(angAlpha1*nbTurns, &U[1], &V[1]);
  multR(angAlpha2*nbTurns, &U[2], &V[2]);
  double xi=0.0;
  double eta=0.0;
  double U0 = U[0]-U[1]+U[2]+2*xi*(U[1]-U[2])+2*eta*(U[1]-U[0]);
  double V0 = V[0]-V[1]+V[2]+2*xi*(V[1]-V[2])+2*eta*(V[1]-V[0]);
  xi=1.0;
  eta=0.0;
  double U1 = U[0]-U[1]+U[2]+2*xi*(U[1]-U[2])+2*eta*(U[1]-U[0]);
  double V1 = V[0]-V[1]+V[2]+2*xi*(V[1]-V[2])+2*eta*(V[1]-V[0]);
  double norm0=U0*U0+V0*V0;
  double norm1=U1*U1+V1*V1;
  if(norm0<norm1)
    *nodeID=vTriNum[0];
  else
    *nodeID=vTriNum[1];
  return HXT_STATUS_OK;
}

HXTStatus  QuadGenerator::getBoundaryDirectionsAtCorner(std::vector<std::vector<uint64_t>> *boundaryVert2Edg){
  HXTEdges* edges=m_triEdges;
  HXTMesh *m = edges->edg2mesh;
  for(uint64_t i=0;i<m_vectCorner.size();i++){
    Corner *c=&(m_vectCorner[i]);
    uint64_t cornerNode=c->getGlobalVertex();
    for(uint64_t k=0;k<(*boundaryVert2Edg)[cornerNode].size();k++){
      uint64_t edg1=(*boundaryVert2Edg)[cornerNode][k];
      double *v0;
      double *v1;
      if(edges->node[2*edg1+0]==cornerNode){
	v0=m->vertices.coord + 4*edges->node[2*edg1+0];
	v1=m->vertices.coord + 4*edges->node[2*edg1+1];
      }
      else{
	v0=m->vertices.coord + 4*edges->node[2*edg1+1];
	v1=m->vertices.coord + 4*edges->node[2*edg1+0];
      }
      double direction1[3];
      for(int k=0;k<3;k++){
	direction1[k]=v1[k]-v0[k];
      }
      normalize(direction1);
      std::array<double,3> dir1={{0.0,0.0,0.0}};
      for(int k=0; k<3; k++){
	dir1[k] = direction1[k];
      }
      //storing directions at bdry in each corner
      c->addDirections(dir1);    
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::buildCorners(){
  HXTEdges* edges=m_triEdges;
  HXTMesh *mesh = edges->edg2mesh;
  //Corners global indices
  const std::vector<uint64_t> initBdryVert;
  std::vector<std::vector<uint64_t>> boundaryVert2Edg(mesh->vertices.num,initBdryVert);
  std::vector<uint64_t> cornerIndices;
  getCornerGlobalVertexInd(&boundaryVert2Edg, &cornerIndices);
  std::cout<<"Num corners: "<< cornerIndices.size()<< std::endl;
  //Corners triangles
  std::vector<uint64_t> corner2Tri;
  int *sizeCorner2Tri;
  HXT_CHECK(hxtMalloc(&(sizeCorner2Tri), (cornerIndices.size())*sizeof(int)));
  cornerTri(cornerIndices, &corner2Tri, sizeCorner2Tri);
  //Corners edges
  std::vector<uint64_t> corner2Edg;
  int *sizeCorner2Edg;
  HXT_CHECK(hxtMalloc(&(sizeCorner2Edg), (cornerIndices.size())*sizeof(int)));
  cornerEdg(&boundaryVert2Edg, cornerIndices, corner2Tri, sizeCorner2Tri, &corner2Edg,sizeCorner2Edg);
  //storing
  int offsetTri=0, offsetEdg=0; 
  for(uint64_t i=0; i<cornerIndices.size(); i++){
    bool isFictive=0;
    std::array<double,3> cornerCoord;
    std::vector<uint64_t> patch;
    std::vector<uint64_t> triangles;
    std::vector<uint64_t> cornerEdges;
    for(int j=0; j<3; j++)
      cornerCoord[j]=mesh->vertices.coord[4*cornerIndices[i]+j];
    for(int j=0; j<sizeCorner2Tri[i]; j++){
      triangles.push_back(corner2Tri[offsetTri+j]);
      patch.push_back(corner2Tri[offsetTri+j]);
    }
    offsetTri=offsetTri+sizeCorner2Edg[i];
    for(int j=0; j<sizeCorner2Edg[i]; j++){
      cornerEdges.push_back(corner2Edg[offsetEdg+j]);
    }
    offsetEdg=offsetEdg+sizeCorner2Edg[i]; 
    Corner c(i, cornerIndices[i],  cornerCoord,  isFictive,  patch,  triangles,  cornerEdges);
    m_vectCorner.push_back(c);				 
  }
  //remove singularities on boundary by creating fictive corners
  for(uint64_t i=0;i<m_vectSing.size();i++){
    Singularity *s=&(m_vectSing[i]);
    uint64_t singEdg=s->getGlobalEdg();
    if(edges->edg2tri[2*singEdg+1]==(uint64_t)-1){ //is on boundary // feature lines : here check if it's also a feature line
      //check if one of the vertices is a corner
      int isAlreadyACorner=0;
      for(uint64_t j=0;j<m_vectCorner.size();j++){
	Corner c=m_vectCorner[j];
        uint64_t cornerNode=c.getGlobalVertex();
  	if(edges->node[2*singEdg+0]==cornerNode||edges->node[2*singEdg+1]==cornerNode)
  	  isAlreadyACorner=1;
      }
      if(!isAlreadyACorner){
        uint64_t nodeSing=0;
  	singEdgToNode(singEdg, &nodeSing);
	int ID=m_vectCorner.size();
	std::array<double,3> cornerCoord;
	for(int j=0; j<3; j++)
	  cornerCoord[j]=mesh->vertices.coord[4*nodeSing+j];
	bool isFictive=1;
	std::vector<uint64_t> patch;
	std::vector<uint64_t> triangles;
	int numTri=0;
	//finding corresponding triangles
	for(uint64_t j=0; j<edges->edg2mesh->triangles.num; j++){
	  uint32_t  vtri[3] = {mesh->triangles.node[3*j+0],mesh->triangles.node[3*j+1],mesh->triangles.node[3*j+2]};
	  for(int k=0; k<3; k++){
	    if(vtri[k]==nodeSing){
	      patch.push_back(j);
	      triangles.push_back(j);
	      numTri++;
	    }
	  }
	}
	std::vector<uint64_t> cornerEdges;
	//finding corresponding edges
	for(int j=0; j<numTri; j++){
	  uint32_t triEdg[3], edgNode[2];
	  for(int k=0; k<3; k++){
	    triEdg[k]=edges->tri2edg[3*triangles[j]+k];
	    for(int m=0; m<2; m++)
	      edgNode[m]=edges->node[2*triEdg[k]+m];
	    if(edgNode[0]!=nodeSing && edgNode[1]!=nodeSing)
	      cornerEdges.push_back(triEdg[k]);
	  }
	}
	Corner c(ID, nodeSing,  cornerCoord,  isFictive,  patch,  triangles,  cornerEdges);
	m_vectCorner.push_back(c);
      }
      s->setIsDisabled();
    }
  }
  
  //disable sing in corner patch
  //check if singularity is in the corner patch - not active
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    bool isDisabled=s->isDisabled();
    if(!isDisabled){
      uint64_t singEdg=s->getGlobalEdg();
      uint64_t patch1=-1, patch2=-1;
      bool isInPatch1=0, isInPatch2=0;
      uint64_t triNum1=edges->edg2tri[2*singEdg+0];
      uint64_t triNum2=edges->edg2tri[2*singEdg+1];
      checkIfInCornerPatch(triNum1, &isInPatch1, &patch1);
      checkIfInCornerPatch(triNum2, &isInPatch2, &patch2);
      if(isInPatch1==1 || isInPatch2==1){
	s->setIsDisabled();
      }
    }
  }
  //Storing boundary directions for each corner
  std::vector<std::vector<double>> directions;
  getBoundaryDirectionsAtCorner(&boundaryVert2Edg);
  
  HXT_CHECK(hxtFree(&sizeCorner2Tri));
  HXT_CHECK(hxtFree(&sizeCorner2Edg)); 
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::cleanSingularities()
{
  std::vector<Singularity> oldSing=m_vectSing;
  m_vectSing.clear();
  for(uint64_t i=0;i<oldSing.size();i++){
    if(!((oldSing[i]).isDisabled()))
      m_vectSing.push_back(oldSing[i]);
  }
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteCorners(const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Corners\" {\n");
  for(uint32_t i=0; i<m_vectCorner.size(); i++){
    int color=i;
    Corner *c=&m_vectCorner[i];
    if(!(c->isFictive())){
      std::array<double,3> coord=c->getCoord();
      fprintf(f,"SP(%g,%g,%g){%i};\n", coord[0], coord[1], coord[2], color);
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteCornerPatches(const char *fileName){
  HXTEdges *edges=m_triEdges;
  HXTMesh *mesh=edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  uint64_t *elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    elemFlagged[i]=0;
  for(uint32_t k=0; k<m_vectCorner.size(); k++){
    Corner *c=&(m_vectCorner[k]);
    if(!(c->isFictive())){
      std::vector<uint64_t> patch=c->getPatch();
      for(uint32_t j=0; j<patch.size(); j++){
	uint64_t tri=patch[j];
	elemFlagged[tri]=1;
      }
    }
  }
  
  fprintf(f,"View \"Flagged corner patches\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(f,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    for(uint32_t j=0; j<3; j++){
      fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(f,",");
    }
    fprintf(f,")");
    fprintf(f,"{");
    fprintf(f,"%lX, %lX, %lX",elemFlagged[i],elemFlagged[i],elemFlagged[i]);
    fprintf(f,"};\n");    
  }
  fprintf(f,"};");
  fclose(f);
  
  HXT_CHECK(hxtFree(&elemFlagged));
  return HXT_STATUS_OK;
}

int QuadGenerator:: lineLoopNodes(HXTBoundaries* boundaries, int numLineLoop, int *bdryNodes, int *numNodes, int *triangles, int *numTriangles)
{
  HXTEdges* edg=m_triEdges;
  HXTLineLoop *lineLoop;
  uint32_t *edges;
  hxtBoundariesGetLineLoop(boundaries, numLineLoop, &lineLoop);
  hxtBoundariesGetEdgesOfLineLoop(boundaries, numLineLoop, &edges);
  int numBdryEdg[1];
  hxtBoundariesGetNumberOfEdgesOfLineLoop(boundaries, numLineLoop, numBdryEdg);
  int num1=0;
  int node1= edg->node[2*edges[0]+0];
  int node2= edg->node[2*edges[0]+1];
  int node3= edg->node[2*edges[1]+0];
  int node4= edg->node[2*edges[1]+1];
  triangles[0]=edg->edg2tri[2*edges[0]+0];
  if(node2==node3 || node2==node4){
    bdryNodes[num1]=node1;
    num1++;
    bdryNodes[num1]=node2;
    num1++;
  }else{
    bdryNodes[num1]=node2;
    num1++;
    bdryNodes[num1]=node1;
    num1++;
  }
  for(int k=1; k<*numBdryEdg; k++){
    int node1= edg->node[2*edges[k]+0];
    int node2= edg->node[2*edges[k]+1];
    triangles[k]=edg->edg2tri[2*edges[k]+0];
    if(node1!= bdryNodes[num1-1]){
      bdryNodes[num1]=node1;
      num1++;
    }else{
      bdryNodes[num1]=node2;
      num1++;
    }
  }
  *numNodes=num1;
  *numTriangles=num1-1;
  return 1;
}

int QuadGenerator::doShiffting(int *nodes, int *numNodes, int startIndice, int *newNodes, int *triangles, int *numTriangles, int *newTriangles){
  int num1=0;
  int num2=0;
  if(startIndice!=0){
    for(int i=startIndice; i<*numNodes; i++){
      newNodes[num1]=nodes[i];
      num1++;
    }
    for(int j=1; j<startIndice; j++){
      newNodes[num1]=nodes[j];
      num1++;
    }
    newNodes[num1]=nodes[startIndice];
    for(int i=startIndice; i<*numTriangles; i++){
      newTriangles[num2]=triangles[i];
      num2++;
    }
    for(int j=0; j<startIndice; j++){
      newTriangles[num2]=triangles[j];
      num2++;
    }
  }else{
    for(int k=0; k<*numNodes; k++){
      newNodes[k]=nodes[k];
    }
    for(int i=0; i<*numTriangles; i++){
      newTriangles[i]=triangles[i];
    } 
  }
  return 1;
}

// //Getting the lines from the boundary, by giving the first corner indice and getting the next corner index 
int QuadGenerator::bdrySepLine(int *bdryNodes, int *numNodes, int *line, int *num1, int Ind1, int *Ind2, int *startingCornerID, int *endingCornerID)
{
  int num=0;
  int flag=1;
  *startingCornerID = -1;
  *endingCornerID = -1;
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner c=m_vectCorner[i];
    int vertex=c.getGlobalVertex();
    if(vertex==bdryNodes[Ind1+num]){
      *startingCornerID = i;
    }
  }
  line[num]=bdryNodes[Ind1];
  num++;
  while(flag==1 && (Ind1+num)<*numNodes){
    for(uint64_t  i=0; i<m_vectCorner.size(); i++){
      if(flag==1){
	Corner c=m_vectCorner[i];
	int vertex=c.getGlobalVertex();
	if(vertex==bdryNodes[Ind1+num]){ 
	  line[num]=vertex;
	  *endingCornerID = i;
	  num++;
	  flag=0;
	}
      }
    }
    if(flag==1){
      line[num]=bdryNodes[Ind1+num];
      num++;
    }
  }
  *num1=num;
  *Ind2=Ind1+num-1;
  return 1;
}

int QuadGenerator::getCornerIDFromGlobalVert(uint64_t  vertexID){
  int ID=-1;
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner c=m_vectCorner[i];
     uint32_t  currentVert=c.getGlobalVertex();
    if(currentVert==vertexID)
      ID=c.getID();
  }
  return ID;
}  

HXTStatus QuadGenerator:: createBoundaryLines(){
  HXTEdges* edges=m_triEdges;
  HXTMesh* m=edges->edg2mesh;
  int HARDalloc=10000;
  HXTBoundaries* boundaries;
  //build boundary
  hxtEdgesSetBoundaries(edges, &(boundaries));
  int numLoops=0;
  //get num of loops
  hxtBoundariesGetNumberOfLineLoops(boundaries, &numLoops);
  //Creating boundary lines
  for(int l=0; l<numLoops; l++){
    int numEdgLineLoop[1];
    HXTLineLoop *lineLoop;
    hxtBoundariesGetLineLoop(boundaries, l, &lineLoop);
    hxtBoundariesGetNumberOfEdgesOfLineLoop(boundaries, l, numEdgLineLoop);
    int *bdryNodes;
    HXT_CHECK(hxtMalloc(&bdryNodes, (*numEdgLineLoop+1)*sizeof(int)));
    int numNodes[1];
    int *triangles;
    HXT_CHECK(hxtMalloc(&triangles, *numEdgLineLoop*sizeof(int)));
    int numTriangles[1];
    lineLoopNodes(boundaries, l, bdryNodes, numNodes, triangles, numTriangles); 
    //Indicator if geometry has corners (in the given loop l) and on which indice
    int cornerNode=0;
    int indicator=0;
    for(int j=0; j<*numNodes-1; j++){
      for(uint64_t i=0; i<m_vectCorner.size(); i++){
	Corner c=m_vectCorner[i];
	int vertex=c.getGlobalVertex();
	if(vertex==bdryNodes[j] && indicator!=1){
	  cornerNode=j;
	  indicator=1;
	}
      }
    } 
    int *reorderedBdryNodes;
    HXT_CHECK(hxtMalloc(&reorderedBdryNodes,(*numNodes)*sizeof(int)));
    int *reorderedTriangles;
    HXT_CHECK(hxtMalloc(&reorderedTriangles, (*numTriangles)*sizeof(int))); 
    doShiffting(bdryNodes, numNodes, cornerNode, reorderedBdryNodes, triangles, numTriangles, reorderedTriangles); 
    int Ind1=0;
    int Ind2[1];
    *Ind2=0;
    int numNodesInLine;
    int *line;
    HXT_CHECK(hxtMalloc(&(line), HARDalloc*sizeof(int*)));
    int startingCornerID=-1;
    int endingCornerID=-1;
    while((*Ind2+1)!=*numNodes){ //end of *numNodes array
      bdrySepLine(reorderedBdryNodes, numNodes, line, &numNodesInLine, Ind1, Ind2, &startingCornerID, &endingCornerID);
      uint64_t *triangleNumbers;
      HXT_CHECK(hxtMalloc(&triangleNumbers, (numNodesInLine)*sizeof(uint64_t)));
      //fill in all atributes for boundary line
      uint64_t isALoop=0;
      std::vector<std::array<double,3>> vectNodesCoord;
      std::vector<uint64_t> vectTriangles;

      if(startingCornerID==-1){
	triangleNumbers[0]= reorderedTriangles[Ind1+0];
      }
      else{
	triangleNumbers[0]= -1;
      }
      vectTriangles.push_back(triangleNumbers[0]);
      for(int i=0; i<numNodesInLine-1; i++){
	triangleNumbers[i+1]=reorderedTriangles[Ind1+i];
	vectTriangles.push_back(triangleNumbers[i+1]);
      }
      for(int i=0; i<numNodesInLine; i++){
	int node1=line[i];
	double *point = m->vertices.coord + 4*node1;
	std::array<double,3> myPoint={{-1.0,-1.0,-1.0}};
	for(int j=0; j<3; j++){
	  myPoint[j]=point[j];
	}
	vectNodesCoord.push_back(myPoint);
      }
      Corner *pStartCorner;
      Corner *pEndCorner;
      if(startingCornerID==-1)
	pStartCorner=NULL;
      else{
	int ID=getCornerIDFromGlobalVert(startingCornerID);
	pStartCorner=&(m_vectCorner[ID]);
      }
      if(endingCornerID==-1)
	pEndCorner=NULL;
      else{
	int ID=getCornerIDFromGlobalVert(endingCornerID);
	pEndCorner=&(m_vectCorner[ID]);
      }
      //create boundary line
      BoundaryLine bd(isALoop, vectNodesCoord, vectTriangles, pStartCorner, pEndCorner);
      m_vectBoundaryLine.push_back(bd);
      
      Ind1 = *Ind2;
      HXT_CHECK(hxtFree(&triangleNumbers));
    }
    HXT_CHECK(hxtFree(&line));
    HXT_CHECK(hxtFree(&reorderedBdryNodes));
    HXT_CHECK(hxtFree(&reorderedTriangles));
    HXT_CHECK(hxtFree(&bdryNodes));
    HXT_CHECK(hxtFree(&triangles));
  }
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::buildBoundary(){
  Boundary bdry(m_vectCorner, m_vectBoundaryLine); 
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteBdryLines(const char *fileName)
{
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Boundary lines\" {\n");
  for(uint64_t i=0; i<m_vectBoundaryLine.size(); i++){
    BoundaryLine bl=m_vectBoundaryLine[i];
    std::vector<std::array<double,3>> coord=bl.getCoord();
    for(uint64_t j=0; j<coord.size()-1; j++){
      std::array<double,3> point1=coord[j];
      std::array<double,3> point2=coord[j+1];
      fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], (int)i);
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], (int)i, (int)i);
    }  
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

int QuadGenerator::closestBranchInTri(uint64_t triNum, uint64_t edgNum, double *coordP, double enteringAngle, double *closestAngle){
  HXTEdges* edg=m_triEdges;
  HXTMesh* m=edg->edg2mesh;
  double *crossField=m_crossfield;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  int nbTurns = m_nbTurns;
  double  AB[3], AC[3], AP[3], U[3],V[3], e[3], e1[3];
  int k=-1;
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*triNum+i]){
      k=i;
    }
  }
  for(int j=0;j<3;j++){
    U[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+0];
    V[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+1];
  }
  uint32_t vTriNum[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3],m->triangles.node[3*triNum+(k+2)%3]};
  double u1[3]={0,0,0};
  double v1[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(m,vTriNum,u1,v1,n);
  int edgNum1=edg->tri2edg[3*triNum+(k+1)%3];
  int edgNum2=edg->tri2edg[3*triNum+(k+2)%3];
  for(int j=0; j<3; j++){
    e[j]=vert[4*edg->node[2*edgNum2+1]+j]-vert[4*edg->node[2*edgNum2+0]+j];
    e1[j]=vert[4*edg->node[2*edgNum1+1]+j]-vert[4*edg->node[2*edgNum1+0]+j];
  }
  normalize(e); normalize(e1);
  double angAlpha2 = atan2(myDot(e,v1), myDot(e,u1));
  double angAlpha1 = atan2(myDot(e1,v1), myDot(e1,u1));
  multR(angAlpha1*nbTurns, &U[1], &V[1]);
  multR(angAlpha2*nbTurns, &U[2], &V[2]);
  for(int j=0; j<3;j++){
    AB[j]=vert[4*nodes[3*triNum+(k+1)%3]+j]-vert[4*nodes[3*triNum+k]+j];
    AC[j]=vert[4*nodes[3*triNum+(k+2)%3]+j]-vert[4*nodes[3*triNum+k]+j];
    AP[j]=coordP[j]-vert[4*nodes[3*triNum+k]+j];
  }
  double q[3]={0,0,0};
  crossprod(AB, AC, q);
  double s[3]={0,0,0};
  crossprod(AP, AB, s);
  double t[3]={0,0,0};
  crossprod(AP, AC, t);
  double xi=myDot(t,q)/myDot(q,q);
  double eta=-myDot(s,q)/myDot(q,q);
  double theta = atan2(V[0]-V[1]+V[2]+2*xi*(V[1]-V[2])+2*eta*(V[1]-V[0]), U[0]-U[1]+U[2]+2*xi*(U[1]-U[2])+2*eta*(U[1]-U[0]))/nbTurns;
  double b[4]={theta, theta+M_PI/2., theta+M_PI, theta+M_PI*(3./2.)};
  double minDiff=-2.0;
  double minAngle=0.0;
  for(int i=0; i<4; i++){
    if ((minDiff < cos(b[i]-enteringAngle))){
      minDiff= cos((b[i]-enteringAngle));
      minAngle=atan2(sin(b[i]), cos(b[i]));
    }
  }
  *closestAngle=atan2(sin(minAngle), cos(minAngle));
  
  return 1;
}

int QuadGenerator::isToCloseToBndryDir(int cornerID, double *dirInit){
  int value=0;
  Corner *c=&m_vectCorner[cornerID];
  std::vector<std::array<double,3>> directionBoundary=c->getDirections();
  double angleMin = 10.0*M_PI/180.0;
  for(uint64_t i=0;i<directionBoundary.size();i++){//feature lines : modify the 2 with bndr size
    double dir[3]={0.,0.,0.};
    std::array<double,3> dB=directionBoundary[i];
    for(int j=0; j<3; j++)
      dir[j]=dB[j];
    double dirInitNorm[3];
    for(int k=0;k<3;k++)
      dirInitNorm[k]=dirInit[k];
    normalize(dirInitNorm);
    normalize(dir);
    double cosAngle=myDot(dirInitNorm, dir);
    if(cosAngle>cos(angleMin))
      value=1;
  }
  return value;
}

int QuadGenerator::seedingCorner(int sizeSeed, uint64_t edgToSeed, uint64_t triNum, double *x, int *sizeP, int cornerID)
{
  HXTEdges* edg=m_triEdges;
  HXTMesh* m=edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  //double angleLim=M_PI/180.0*2.0;
  double angleLim=M_PI/180.0*5.0;
  int k=-1;
  for(int i=0; i<3;i++){
    if(edgToSeed==edg->tri2edg[3*triNum+i]){
      k=i;
    }
  } 
  double coordVertex[3*3] = {vert[4*nodes[3*triNum+k]+0],vert[4*nodes[3*triNum+k]+1],vert[4*nodes[3*triNum+k]+2],
			     vert[4*nodes[3*triNum+(k+1)%3]+0],vert[4*nodes[3*triNum+(k+1)%3]+1],vert[4*nodes[3*triNum+(k+1)%3]+2],
			     vert[4*nodes[3*triNum+(k+2)%3]+0],vert[4*nodes[3*triNum+(k+2)%3]+1],vert[4*nodes[3*triNum+(k+2)%3]+2]};
  double A[3], AB[3], P[3], S[3], PS[3], SP[3];
  for(int j=0; j<3; j++){
    A[j]=coordVertex[j];
    AB[j]=coordVertex[j+3]-coordVertex[j];
    S[j]=coordVertex[j+6];
  }
  uint32_t vtri[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3], m->triangles.node[3*triNum+(k+2)%3]};
  double u[3], v[3], n[3];
  trianglebasis(m, vtri,u,v,n);
  *sizeP=0;
  double *seeds;
  HXT_CHECK(hxtMalloc(&seeds, sizeSeed*sizeof(double)));
  int flagSeedToAdd=1; 
  for(int l=0; l<sizeSeed; l++)
    seeds[l]=(1.0*l+1.0)/(1.0*sizeSeed+1.0);
  for(int l=0; l<sizeSeed; l++){
    double xi=seeds[l];
    for(int j=0; j<3; j++){
      P[j]=A[j]+xi*AB[j];
    }
    for(int j=0; j<3; j++){
      PS[j]=S[j]-P[j];
      SP[j]=P[j]-S[j];
    }
    double enteringAngle;
    double sinAngle=myDot(v,PS);
    double cosAngle=myDot(u,PS);
    enteringAngle=atan2(sinAngle, cosAngle);
    double closestAngle;
    closestBranchInTri(triNum, edg->tri2edg[3*triNum+k], P, enteringAngle, &closestAngle);
    if((cos(angleLim)<cos(enteringAngle-closestAngle))&&!isToCloseToBndryDir(cornerID,SP)){
      if(flagSeedToAdd==1){
	x[*sizeP]=xi;
	(*sizeP)++;
	flagSeedToAdd=0; 
      }
    }else{
      flagSeedToAdd=1;
    }
  }
  HXT_CHECK(hxtFree(&seeds));
  return 1;
}

HXTStatus QuadGenerator::initiationFromCorner(){
  HXTEdges* edges=m_triEdges;
  HXTMesh* m=edges->edg2mesh;
  int sizeSeeding=m_sizeSeeding;
  uint64_t e1;
  double a1[3], a2[3], point2[3];
  std::cout<<"Total num corners: "<<m_vectCorner.size()<<std::endl;
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&m_vectCorner[i];
    if(!(c->isFictive())){
      std::vector<uint64_t> cornerEdg=c->getEdges();
      std::vector<uint64_t> cornerTri=c->getTriangles();
      uint64_t cornerNode=c->getGlobalVertex();
    
      int initAlloc=50000;
      for(uint64_t j=0; j<cornerEdg.size(); j++){
	e1=cornerEdg[j];
	uint64_t node1=cornerNode;
	int sizeSeedCorner=0;
	double xC[1000]={0.5};
	seedingCorner(sizeSeeding, cornerEdg[j], cornerTri[j], xC, &sizeSeedCorner,i);
	for(int k=0;k<sizeSeedCorner;k++){
	  uint64_t *triangleNumbers1; 
	  HXT_CHECK(hxtMalloc(&triangleNumbers1, initAlloc*sizeof(uint64_t))); 
	  triangleNumbers1[0]=cornerTri[j]; //should be Master triangle
	  triangleNumbers1[1]=cornerTri[j]; 
	  int r=-1;
	  for(int l=0; l<3;l++){
	    if(e1==edges->tri2edg[3*triangleNumbers1[1]+l]){
	      r=l;
	    }
	  }
	  double *v0 = m->vertices.coord + 4*edges->edg2mesh->triangles.node[3*triangleNumbers1[1]+r];
	  double *v1 = m->vertices.coord + 4*edges->edg2mesh->triangles.node[3*triangleNumbers1[1]+(r+1)%3];
	  for(int k=0; k<3; k++){
	    a1[k]=v1[k]-v0[k];
	  }
	  double *point1= m->vertices.coord + 4*node1;
	  for(int t=0; t<3; t++){
	    point2[t]=v0[t]+a1[t]*xC[k];
	  }
	  for(int k=0; k<3; k++){
	    a2[k]=point1[k]-point2[k];
	  }
	  double normA1 = 0.0;
	  double normA2 = 0.0;
	  for(int k=0; k<3; k++){
	    normA1+=a1[k]*a1[k];
	    normA2+=a2[k]*a2[k];
	  }
	  normA1=sqrt(normA1);
	  normA2=sqrt(normA2);
	  double alpha1=acos(myDot(a1,a2)/(normA1*normA2));
	  //storing separatrice
	  int ID=m_vectSep.size();
	  std::vector<std::array<double,3>> nodesCoord;
	  std::array<double,3> p1,p2;
	  for(int s=0; s<3; s++){
	    p1[s]=point1[s];
	    p2[s]=point2[s];
	  }
	  nodesCoord.push_back(p1);
	  nodesCoord.push_back(p2);
	  std::vector<uint64_t> triangles;
	  triangles.push_back(triangleNumbers1[0]);
	  triangles.push_back(triangleNumbers1[1]);
	  std::vector<uint64_t> edges;
	  edges.push_back(e1);
	  std::vector<double> enteringAngles;
	  enteringAngles.push_back(alpha1);
	  //num of elements =2
	  Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
	  m_vectSep.push_back(sep);
	  HXT_CHECK(hxtFree(&triangleNumbers1));
	}
      }
    }
  }
  return HXT_STATUS_OK;
}

int QuadGenerator::seedingPInitSep(uint64_t singEdg, uint64_t triNum, double *x, int *sizeP){
  int sizeSeed=m_sizeSeeding;
  HXTEdges *edg = m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  //double angleLim=M_PI/180.0*2.0;
  double angleLim=M_PI/180.0*5.0;
  int k=-1;
  for(int i=0; i<3;i++){
    if(singEdg==edg->tri2edg[3*triNum+i]){
      k=(i+2)%3;
    }
  }
  double coordVertex[3*3] = {vert[4*nodes[3*triNum+k]+0],vert[4*nodes[3*triNum+k]+1],vert[4*nodes[3*triNum+k]+2],
			     vert[4*nodes[3*triNum+(k+1)%3]+0],vert[4*nodes[3*triNum+(k+1)%3]+1],vert[4*nodes[3*triNum+(k+1)%3]+2],
			     vert[4*nodes[3*triNum+(k+2)%3]+0],vert[4*nodes[3*triNum+(k+2)%3]+1],vert[4*nodes[3*triNum+(k+2)%3]+2]};
  double A[3], AB[3], C[3], B[3], P[3], S[3], PS[3];
  for(int j=0; j<3; j++){
    A[j]=coordVertex[j];
    B[j]=coordVertex[j+3];
    C[j]=coordVertex[j+6];
    AB[j]=B[j]-A[j];
    S[j]=(B[j]+C[j])/2.0;
  }
  uint32_t vtri[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3], m->triangles.node[3*triNum+(k+2)%3]};
  double u[3], v[3], n[3];
  trianglebasis(m, vtri,u,v,n);
  *sizeP=0;
  double *seeds;
  HXT_CHECK(hxtMalloc(&seeds, sizeSeed*sizeof(double)));
  int flagSeedToAdd=1; 
  for(int l=0; l<sizeSeed; l++)
    seeds[l]=(1.0*l+1.0)/(1.0*sizeSeed+1.0);
  for(int l=0; l<sizeSeed; l++){
    double xi=seeds[l];
    for(int j=0; j<3; j++){
      P[j]=A[j]+xi*AB[j];
    }
    for(int j=0; j<3; j++){
      PS[j]=S[j]-P[j];
    }
    double enteringAngle;
    double sinAngle=myDot(v,PS);
    double cosAngle=myDot(u,PS);
    enteringAngle=atan2(sinAngle, cosAngle);
    double closestAngle;
    closestBranchInTri(triNum, edg->tri2edg[3*triNum+k], P, enteringAngle, &closestAngle);
    if(cos(angleLim)<cos(enteringAngle-closestAngle)){
      if(flagSeedToAdd==1){
	x[*sizeP]=xi;
	(*sizeP)++;
	flagSeedToAdd=0; 
      }
    }else{
      flagSeedToAdd=1;
    }
  }
  HXT_CHECK(hxtFree(&seeds));
  return 1;
}

int QuadGenerator::seedingQInitSep(uint64_t singEdg, uint64_t triNum, double *y, int *sizeQ){
  int sizeSeed=m_sizeSeeding;
  HXTEdges *edg = m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  //double angleLim=M_PI/180.0*2.0;
  double angleLim=M_PI/180.0*5.0;
  int k=-1;
  for(int i=0; i<3;i++){
    if(singEdg==edg->tri2edg[3*triNum+i]){
      k=(i+2)%3;
    }
  }
  double coordVertex[3*3] = {vert[4*nodes[3*triNum+k]+0],vert[4*nodes[3*triNum+k]+1],vert[4*nodes[3*triNum+k]+2],
			     vert[4*nodes[3*triNum+(k+1)%3]+0],vert[4*nodes[3*triNum+(k+1)%3]+1],vert[4*nodes[3*triNum+(k+1)%3]+2],
			     vert[4*nodes[3*triNum+(k+2)%3]+0],vert[4*nodes[3*triNum+(k+2)%3]+1],vert[4*nodes[3*triNum+(k+2)%3]+2]};
  double A[3], B[3], C[3], AC[3], QS[3], Q[3], S[3];
  for(int j=0; j<3; j++){
    A[j]=coordVertex[j];
    B[j]=coordVertex[j+3];
    C[j]=coordVertex[j+6];
    AC[j]=C[j]-A[j];
    S[j]=(B[j]+C[j])/2.0;
  }
  uint32_t vtri[3] = {m->triangles.node[3*triNum+(k+2)%3],m->triangles.node[3*triNum+(k+3)%3], m->triangles.node[3*triNum+(k+4)%3]};
  double u[3], v[3], n[3];
  trianglebasis(m, vtri,u,v,n);

  *sizeQ=0;
  double *seeds;
  HXT_CHECK(hxtMalloc(&seeds, sizeSeed*sizeof(double)));
  int flagSeedToAdd=1; 
  for(int l=0; l<sizeSeed; l++)
    seeds[l]=(1.0*l+1.0)/(1.0*sizeSeed+1.0);
  for(int l=0; l<sizeSeed; l++){
    double eta = seeds[l];
    for(int j=0; j<3; j++){
      Q[j]=A[j]+eta*AC[j];
    }
    for(int j=0; j<3; j++){
      QS[j]=S[j]-Q[j];
    }
    double enteringAngle;
    double sinAngle=myDot(v,QS);
    double cosAngle=myDot(u,QS);
    enteringAngle=atan2(sinAngle, cosAngle);
    double closestAngle;
    closestBranchInTri(triNum, edg->tri2edg[3*triNum+(k+2)%3], Q, enteringAngle, &closestAngle);
    if(cos(angleLim)<cos(enteringAngle-closestAngle)){
      if(flagSeedToAdd==1){
	y[*sizeQ]=eta;
	(*sizeQ)++;
      	flagSeedToAdd=0; 
      }
    }else{
      flagSeedToAdd=1;
    }
  }
  HXT_CHECK(hxtFree(&seeds));
  return 1;
}
 
int QuadGenerator::pointP(uint64_t edgNum, uint64_t triNum, double xi, double *P, double *alpha)
{
  HXTEdges *edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  int rotationEdges[3], rotationVertices[3];
  
  triRot(edgNum, triNum, rotationEdges, rotationVertices);
  uint32_t vTriNum[3] = {m->triangles.node[3*triNum+rotationVertices[0]],m->triangles.node[3*triNum+rotationVertices[1]],m->triangles.node[3*triNum+rotationVertices[2]]};
  double vtri[3*3] = {vert[4*vTriNum[0]+0],vert[4*vTriNum[0]+1],vert[4*vTriNum[0]+2],
                      vert[4*vTriNum[1]+0],vert[4*vTriNum[1]+1],vert[4*vTriNum[1]+2],
                      vert[4*vTriNum[2]+0],vert[4*vTriNum[2]+1],vert[4*vTriNum[2]+2]};

  P[0] = vtri[0]*(1-xi)+vtri[3]*xi; P[1] = vtri[1]*(1-xi)+vtri[4]*xi; P[2] = vtri[2]*(1-xi)+vtri[5]*xi;

  double u[3]={0,0,0};
  double v[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(m,vTriNum,u,v,n);
  double B[3], C[3], S[3], SP[3];
  for(int j=0; j<3;j++){
    B[j]=vert[4*vTriNum[1]+j]; 
    C[j]=vert[4*vTriNum[2]+j];
    S[j]=(C[j]+B[j])/2;
    SP[j]=P[j]-S[j];
  }
  normalize(SP);
  double sinus=myDot(v,SP);
  double cosinus=myDot(u,SP);
  *alpha=M_PI+atan2(sinus, cosinus);
  *alpha=atan2(sin(*alpha),cos(*alpha));
  
  return 1;
}

int QuadGenerator::pointQ(uint64_t edgNum, uint64_t triNum, double eta, double *Q, double *alpha)
{
  HXTEdges *edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  int rotationEdges[3], rotationVertices[3];

  triRot(edgNum, triNum, rotationEdges, rotationVertices);
  uint32_t vTriNum[3] = {m->triangles.node[3*triNum+rotationVertices[0]],m->triangles.node[3*triNum+rotationVertices[1]],m->triangles.node[3*triNum+rotationVertices[2]]};
  double vtri[3*3] = {vert[4*vTriNum[0]+0],vert[4*vTriNum[0]+1],vert[4*vTriNum[0]+2],
                      vert[4*vTriNum[1]+0],vert[4*vTriNum[1]+1],vert[4*vTriNum[1]+2],
                      vert[4*vTriNum[2]+0],vert[4*vTriNum[2]+1],vert[4*vTriNum[2]+2]};

  Q[0] = vtri[0]*(1-eta)+vtri[6]*eta; Q[1] = vtri[1]*(1-eta)+vtri[7]*eta; Q[2] = vtri[2]*(1-eta)+vtri[8]*eta;
  double A[3], B[3], C[3], S[3], QS[3], CA[3], CB[3];
 
  for(int j=0; j<3;j++){
    A[j]=vert[4*vTriNum[0]+j];
    B[j]=vert[4*vTriNum[1]+j]; 
    C[j]=vert[4*vTriNum[2]+j];
    S[j]=(C[j]+B[j])/2;
    QS[j]=S[j]-Q[j];
    CA[j]=A[j]-C[j];
    CB[j]=B[j]-C[j];
  }
  normalize(QS); normalize(CA); normalize(CB);
  double n[3]={0,0,0};
  myNormalizedCrossprod(CA, CB, n);
  double v[3]={0,0,0};
  myNormalizedCrossprod(n, CA, v);
  double sinus=myDot(v,QS);
  double cosinus=myDot(CA,QS);

  *alpha=atan2(sinus, cosinus);

  return 1;
}

HXTStatus QuadGenerator::initiationFromSingularities(){
  HXTEdges* edges=m_triEdges;
  uint64_t sizeSingularEdges=m_vectSing.size();
  uint64_t *triNum1;
  HXT_CHECK(hxtMalloc(&triNum1,  2*(sizeSingularEdges)*sizeof(uint64_t)));
  double coordP[3], coordQ[3], alpha1[1];
  int pEdgNum1=1, pEdgNum2=1, qEdgNum1=1, qEdgNum2=1;
  uint64_t nSep=m_vectSep.size(); 
 
  for(uint64_t i=0; i<sizeSingularEdges; i++){
    Singularity *s=&(m_vectSing[i]);
    uint64_t singEdg=s->getGlobalEdg();
    triNum1[2*i+0]= edges->edg2tri[2*singEdg+0];
    triNum1[2*i+1]= edges->edg2tri[2*singEdg+1];
    std::array<double,3> singCoord=s->getCoord();
    for(int k=0; k<3;k++){
      if(singEdg== edges->tri2edg[3*triNum1[2*i+0]+k]){
	pEdgNum1=edges->tri2edg[3*triNum1[2*i+0]+(k+2)%3];
	qEdgNum1=edges->tri2edg[3*triNum1[2*i+0]+(k+1)%3];
      }
    }
    if(triNum1[2*i+1]!=(uint64_t)-1){
      for(int k=0; k<3;k++){
	if(singEdg== edges->tri2edg[3*triNum1[2*i+1]+k]){
	  pEdgNum2=edges->tri2edg[3*triNum1[2*i+1]+(k+2)%3];
	  qEdgNum2=edges->tri2edg[3*triNum1[2*i+1]+(k+1)%3];
	}
      }
    }
    double *xSP;
    double *ySQ;
    HXT_CHECK(hxtMalloc(&xSP,  m_sizeSeeding*sizeof(double)));
    HXT_CHECK(hxtMalloc(&ySQ,  m_sizeSeeding*sizeof(double)));
    int sizeP=0;
    seedingPInitSep(singEdg, triNum1[2*i+0], xSP, &sizeP);
    for(int j=0; j<sizeP; j++){
      pointP(singEdg, triNum1[2*i+0], xSP[j], coordP, alpha1);
      std::array<double,3> pointP={{0.0,0.0,0.0}};
      for(int s=0; s<3; s++)
	pointP[s]=coordP[s];
      int ID=nSep;
      std::vector<std::array<double,3>> nodesCoord;
      nodesCoord.push_back(singCoord);
      nodesCoord.push_back(pointP);
      std::vector<uint64_t> triangles;
      triangles.push_back(triNum1[2*i+1]);
      triangles.push_back(triNum1[2*i+0]);
      std::vector<uint64_t> edges;
      edges.push_back(pEdgNum1);
      std::vector<double> enteringAngles;
      enteringAngles.push_back(*alpha1);    
      //num elem =2
      Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
      m_vectSep.push_back(sep);
      nSep++;
    }
    int sizeQ=0;
    seedingQInitSep(singEdg, triNum1[2*i+0], ySQ, &sizeQ);
    for(int j=0; j<sizeQ; j++){
      pointQ(singEdg, triNum1[2*i+0], ySQ[j], coordQ, alpha1);
      std::array<double,3> pointQ={{0.0,0.0,0.0}};
      for(int s=0; s<3;s++)
	pointQ[s]=coordQ[s];
      int ID=nSep;
      std::vector<std::array<double,3>> nodesCoord;
      nodesCoord.push_back(singCoord);
      nodesCoord.push_back(pointQ);
      std::vector<uint64_t> triangles;
      triangles.push_back(triNum1[2*i+1]);
      triangles.push_back(triNum1[2*i+0]);
      std::vector<uint64_t> edges;
      edges.push_back(qEdgNum1);
      std::vector<double> enteringAngles;
      enteringAngles.push_back(*alpha1);    
      //num elem =2
      Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
      m_vectSep.push_back(sep);
      nSep++;
    }
    if(triNum1[2*i+1]!=(uint64_t)-1){
      sizeP=0;
      seedingPInitSep(singEdg, triNum1[2*i+1], xSP, &sizeP);
      for(int j=0; j<sizeP; j++){
	pointP(singEdg, triNum1[2*i+1], xSP[j], coordP, alpha1);
	std::array<double,3> pointP={{0.0,0.0,0.0}};
	for(int s=0; s<3;s++)
	  pointP[s]=coordP[s];
	int ID=nSep;
	std::vector<std::array<double,3>> nodesCoord;
	nodesCoord.push_back(singCoord);
	nodesCoord.push_back(pointP);
	std::vector<uint64_t> triangles;
	triangles.push_back(triNum1[2*i+0]);
	triangles.push_back(triNum1[2*i+1]);
	std::vector<uint64_t> edges;
	edges.push_back(pEdgNum2);
	std::vector<double> enteringAngles;
	enteringAngles.push_back(*alpha1);    
	//num elem =2
	Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
	m_vectSep.push_back(sep);
	nSep++;
      }
    }
    if(triNum1[2*i+1]!=(uint64_t)-1){
      sizeQ=0;
      seedingQInitSep(singEdg, triNum1[2*i+1], ySQ, &sizeQ);
      for(int j=0; j<sizeQ; j++){
	pointQ(singEdg, triNum1[2*i+1], ySQ[j], coordQ, alpha1);
	std::array<double,3> pointQ={{0.0,0.0,0.0}};
	for(int s=0; s<3;s++)
	  pointQ[s]=coordQ[s];
	int ID=nSep;
	std::vector<std::array<double,3>> nodesCoord;
	nodesCoord.push_back(singCoord);
	nodesCoord.push_back(pointQ);
	std::vector<uint64_t> triangles;
	triangles.push_back(triNum1[2*i+0]);
	triangles.push_back(triNum1[2*i+1]);
	std::vector<uint64_t> edges;
	edges.push_back(qEdgNum2);
	std::vector<double> enteringAngles;
	enteringAngles.push_back(*alpha1);    
	//num elem =2
	Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
	m_vectSep.push_back(sep);
	nSep++;
      }
    }
    HXT_CHECK(hxtFree(&xSP));
    HXT_CHECK(hxtFree(&ySQ)); 
  }

  HXT_CHECK(hxtFree(&triNum1));
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteInitSep(const char *fileName){
int num=0;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Initiation of separatrices\" {\n");
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved()){
      std::vector<std::array<double,3>> points;
      points=sep->getCoord();
      for(uint64_t j=0; j<points.size()-1; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], num);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], num, num);
      }
      num++;
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

int QuadGenerator::getAllSepFromSing(int singID, std::vector<int> *separatricesIDs){
  Singularity *s=&(m_vectSing[singID]);
  std::array<double,3> *singCoord=s->getPCoord();

  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    std::vector<std::array<double,3>> *sepPoints=sep->getPCoord();
    double point1[3]={0.};
    double point2[3]={0.};
    double norm;
    for(int j=0; j<3; j++){
      point1[j]=(*singCoord)[j];
      point2[j]=(*sepPoints)[0][j];
    }
    if(isPointDuplicate(point1, point2, &norm)){
      (*separatricesIDs).push_back(i);
    }
  }
  
  return 1;
}

int QuadGenerator::getAngleBetweenSep(std::array<double,3> singCoord, std::array<double,3> P1, std::array<double,3> P2, double *alpha){
  double SP1[3], SP2[3];
  for(int i=0; i<3; i++){
    SP1[i]=P1[i]-singCoord[i];
    SP2[i]=P2[i]-singCoord[i];
  }
  double nSP1 = 0.0, nSP2 = 0.0;
  for(int k=0; k<3; k++){
    nSP1+=SP1[k]*SP1[k];
    nSP2+=SP2[k]*SP2[k];
  }
  double cosAlpha=myDot(SP1, SP2)/(sqrt(nSP1)*sqrt(nSP2));
  *alpha=acos(cosAlpha)*180./M_PI;
    
  return 1;
}

HXTStatus QuadGenerator::disableSepDuplicates(int singID){
  Singularity *s=&(m_vectSing[singID]);
  std::array<double,3> *singCoord=s->getPCoord();
  std::vector<int> separatricesIDs;
  getAllSepFromSing(singID, &separatricesIDs);
  std::vector<std::array<double,3>> initiationPoints;
  for(uint64_t j=0; j<separatricesIDs.size(); j++){
    Separatrice *sep=&(m_vectSep[separatricesIDs[j]]);
    std::vector<std::array<double,3>> *sepPoints=sep->getPCoord();
    initiationPoints.push_back((*sepPoints)[1]);
  }
  double alpha=-1;
  for(uint64_t k=0; k<initiationPoints.size()-1; k++){
    for(uint64_t t=k+1; t<initiationPoints.size(); t++){
      Separatrice *sep1=&(m_vectSep[separatricesIDs[k]]);
      Separatrice *sep2=&(m_vectSep[separatricesIDs[t]]);
      if(sep1->isSaved() && sep2->isSaved()){ 
	getAngleBetweenSep(*singCoord,initiationPoints[k],initiationPoints[t], &alpha);
	// if(alpha<=20.0){
	if(alpha<=25.0){
	  Separatrice *sep=&(m_vectSep[separatricesIDs[t]]);
	  sep->Disable();
	}
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::saveBdryLinesAsSeparatrices(){
  for(uint64_t i=0; i<m_vectBoundaryLine.size(); i++){
    BoundaryLine *bd=&(m_vectBoundaryLine[i]);
    //create separatrice
    int ID=m_vectSep.size();
    std::vector<std::array<double,3>> vectNodesCoord=bd->getCoord();
    std::vector<uint64_t> vectTriangles=bd->getTriangles();
    std::vector<uint64_t> edgesSep(1,0);
    std::vector<double> enteringAngles(1,0.);
    Separatrice sep(ID, vectNodesCoord, vectTriangles, edgesSep, enteringAngles);
    sep.setIsBoundarySep();
    m_vectSep.push_back(sep);
  }
  return HXT_STATUS_OK;
}

int QuadGenerator::optimizeSizeofRadius(double *radius){
  HXTEdges* edges = m_triEdges;
  HXTMesh* mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  double a, b, c, point1[3], point2[3];
  double minRadius=1., length=0.;
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    if(!s->isDisabled()){
      uint64_t sEdg = s->getGlobalEdg();
      for(int j=0; j<3; j++){
	point1[j]=vert[4*edges->node[2*sEdg+0]+j];
	point2[j]=vert[4*edges->node[2*sEdg+1]+j];
      }
      a=point1[0]-point2[0]; b=point1[1]-point2[1]; c=point1[2]-point2[2];
      length=0.4*sqrt(a*a+b*b+c*c);
      if(minRadius>length){
	minRadius=length;
      }
    }
  }
 
  // *radius=3*minRadius;
  *radius=0.5*minRadius;
  return 1;
}

int QuadGenerator::getCornerIndex(int cornerID, int *index){
  int num=0;
  double cornerCoord[3], sepStartCoord[3], norm=-1.;

  Corner *c=&(m_vectCorner[cornerID]);
  std::array<double,3> *coord= c->getPCoord();
  for(int i=0; i<3; i++)
    cornerCoord[i]=(*coord)[i];
  for(uint64_t i=0; i<m_vectSep.size()-m_vectBoundaryLine.size(); i++){
    Separatrice *sep=&m_vectSep[i];
    if(sep->isSaved()){
      std::vector<std::array<double,3>> *sepPoints=sep->getPCoord();
      for(int j=0; j<3; j++)
	sepStartCoord[j]=(*sepPoints)[0][j];
      if(isPointDuplicate(cornerCoord, sepStartCoord, &norm))
	num++;
    }
  }
  double startPoint[3], endPoint[3];
  for(uint64_t i=0; i<m_vectBoundaryLine.size(); i++){
    BoundaryLine *bd=&(m_vectBoundaryLine[i]);
    std::vector<std::array<double,3>> vectNodesCoord=bd->getCoord();
    for(int j=0; j<3; j++){
      startPoint[j]=vectNodesCoord[0][j];
      endPoint[j]=vectNodesCoord[vectNodesCoord.size()-1][j];
    }
    if(isPointDuplicate(cornerCoord, startPoint, &norm))
      num++;
    if(isPointDuplicate(cornerCoord, endPoint, &norm))
      num++;
  }

  
  *index=num;
  //for quad test:
  // if(num==0)
  //   *index=2;

  return 1;
}

int QuadGenerator::getSingIndex(int singID, int *index){
  int num=0;
  double singCoord[3], sepStartCoord[3], norm=-1.;
  Singularity *s=&(m_vectSing[singID]);
  std::array<double,3> *coord= s->getPCoord();
  for(int i=0; i<3; i++)
    singCoord[i]=(*coord)[i];
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&m_vectSep[i];
    if(sep->isSaved()){ 
      std::vector<std::array<double,3>> *sepPoints=sep->getPCoord();
      for(int j=0; j<3; j++)
	sepStartCoord[j]=(*sepPoints)[0][j];
      if(isPointDuplicate(singCoord, sepStartCoord, &norm))
	num++;
    }
  }
  *index=num;  
  return 1;
}

HXTStatus QuadGenerator::fillGeoFile(std::string myGeoFile){
  HXTEdges* edges=m_triEdges;
  HXTMesh* mesh=edges->edg2mesh;
  uint16_t *colors= mesh->triangles.colors;

  gmsh::initialize();
  // HXT_INFO("gmsh: merge the file %s", myGeoFile);
  // gmsh::merge(myGeoFile);
  HXT_INFO("gmsh: open the file %s", myGeoFile);
  gmsh::open(myGeoFile);
  // gmsh::model::occ::synchronize();
  gmsh::model::geo::synchronize();
  //identify corners from geo
  double xmin=0., ymin=0., zmin=0., xmax=0., ymax=0., zmax=0.;
  std::vector<std::array<double,3>> allCoord;
  std::array<double,3> point;
  gmsh::vectorpair dimTagsPoints;
  gmsh::model::getEntities(dimTagsPoints,0); 
  for(uint64_t i=0; i<dimTagsPoints.size(); i++){
    gmsh::model::getBoundingBox(0, dimTagsPoints[i].second, xmin, ymin, zmin, xmax, ymax, zmax);
    point[0]=xmin; point[1]=ymin; point[2]=zmin;
    allCoord.push_back(point);
  }
  
    std::vector<int> cornerGeoTags;
    for(uint64_t i=0; i<m_vectCorner.size(); i++)
      cornerGeoTags.push_back(-1);
    for(uint64_t i=0; i<m_vectCorner.size(); i++){
      Corner *c=&m_vectCorner[i];
      if(!c->isFictive()){
	std::array<double,3> *cPoint= c->getPCoord();
	for(uint64_t j=0; j<allCoord.size(); j++){
	  if((*cPoint)[0]==allCoord[j][0] && (*cPoint)[1]==allCoord[j][1] && (*cPoint)[2]==allCoord[j][2]){
	    cornerGeoTags[i]=dimTagsPoints[j].second;
	    break;
	  }
	}
      }
    }
    double hmax=0.1, radius;
    optimizeSizeofRadius(&radius);
    // std::cout<<"Radius: "<<radius<<", mesh size: "<<hmax<<std::endl;
 
    int N=20;
    // int N=50;
    double x=0., y=0., z=0.;
    int index=0;
    std::vector<int> singThreeTags;
    std::vector<int> singFiveTags;
    //int num;
    int lineTag=-1, pointTag=-1, singTag=-1, cornerTag=-1, loopTag=-1;
  
    //Singularities
    for(uint64_t i=0; i<m_vectSing.size();i++){
      Singularity *s=&(m_vectSing[i]);
      if(!s->isDisabled()){
	std::array<double,3> *coord= s->getPCoord();
	uint64_t sEdg=s->getGlobalEdg();
	uint64_t sTri=edges->edg2tri[2*sEdg+0]; //for surface color
	std::vector<int> curvePointsTags;
	std::vector<int> pointsTags;
	std::vector<int> linesTags;
	// singTag=gmsh::model::occ::addPoint((*coord)[0],(*coord)[1],(*coord)[2], 10.*radius, -1);
	singTag=gmsh::model::geo::addPoint((*coord)[0],(*coord)[1],(*coord)[2], 10.*radius, -1);
	pointsTags.push_back(singTag);
	getSingIndex(i, &index);
	std::cout<<"Singularity "<<i<<", index: "<<index<<std::endl;
	if(index==3 || index==4) //doubled because of the vertex closeness
	  singThreeTags.push_back(singTag);
	if(index==5 || index==6) //doubled because of the vertex closeness
	  singFiveTags.push_back(singTag);
	//Disk around singularity
	for(int j=0; j<N; j++){
	  x=(*coord)[0]+radius*cos((1.0*j)/(1.0*N)*2.0*M_PI);
	  y=(*coord)[1]+radius*sin((1.0*j)/(1.0*N)*2.0*M_PI);
	  z=(*coord)[2];
	  // pointTag=gmsh::model::occ::addPoint(x,y,z, radius, -1);
	  pointTag=gmsh::model::geo::addPoint(x,y,z, radius, -1);
	  pointsTags.push_back(pointTag);
	  curvePointsTags.push_back(pointTag);
	  // lineTag=gmsh::model::occ::addLine(singTag, pointTag, -1);
	  lineTag=gmsh::model::geo::addLine(singTag, pointTag, -1);
	  linesTags.push_back(lineTag);
	}
	std::vector<int> curveLinesTags;
	for(uint64_t j=1; j<curvePointsTags.size(); j++){
	  // lineTag=gmsh::model::occ::addLine(curvePointsTags[j-1],curvePointsTags[j],-1);
	  lineTag=gmsh::model::geo::addLine(curvePointsTags[j-1],curvePointsTags[j],-1);
	  linesTags.push_back(lineTag);
	  curveLinesTags.push_back(lineTag);
	  lineTag++;
	}
	// lineTag=gmsh::model::occ::addLine(curvePointsTags[curvePointsTags.size()-1],curvePointsTags[0],-1);
	lineTag=gmsh::model::geo::addLine(curvePointsTags[curvePointsTags.size()-1],curvePointsTags[0],-1);
	linesTags.push_back(lineTag);
	curveLinesTags.push_back(lineTag);
	//add Disk
	// loopTag=gmsh::model::occ::addCurveLoop(curveLinesTags,-1);
	loopTag=gmsh::model::geo::addCurveLoop(curveLinesTags,-1);
	// loopTag=gmsh::model::occ::addBSpline(curveLinesTags,-1);
	//Surface embeding
	// gmsh::model::occ::synchronize();
	gmsh::model::geo::synchronize();
	gmsh::model::mesh::embed(0, pointsTags, 2, (int) colors[sTri]); //points
	gmsh::model::mesh::embed(1, linesTags, 2, (int) colors[sTri]); //lines
	gmsh::model::mesh::embed(1, curveLinesTags, 2, (int) colors[sTri]); //curve
      }
    }
    std::cout<<"Singualrities written!"<<std::endl;

    //Corners
    for(uint64_t i=0; i<m_vectCorner.size(); i++){
      Corner *c=&m_vectCorner[i];
      if(!c->isFictive()){
	std::array<double,3> *coord= c->getPCoord();
	std::vector<uint64_t> *cPatch=c->getPPatch();
	// uint64_t cTri=(*cPatch)[0]; //for surface color
	std::vector<int> tags;
	if(cornerGeoTags[i]!=-1){
	  cornerTag=cornerGeoTags[i];
	  tags.push_back(cornerTag);
	  getCornerIndex(i, &index);
	  std::cout<<"Corner - existing: "<<i<<", index: "<<index<<std::endl;
	  if(index==2 || index==3) //doubled because of the vertex closeness
	    singThreeTags.push_back(cornerTag);
	  if(index==4 || index==5) //doubled because of the vertex closeness
	    singFiveTags.push_back(cornerTag);
	}
	else{
	  // cornerTag=gmsh::model::occ::addPoint((*coord)[0],(*coord)[1],(*coord)[2], 2*radius, -1);
	  cornerTag=gmsh::model::geo::addPoint((*coord)[0],(*coord)[1],(*coord)[2], 2*radius, -1);
	  tags.push_back(cornerTag);
	  gmsh::model::geo::synchronize();
	  // gmsh::model::occ::synchronize();
	  gmsh::model::mesh::embed(0, tags, 2, (int) colors[(*cPatch)[0]]); //points
	  getCornerIndex(i, &index);
	  std::cout<<"Corner: "<<i<<", index: "<<index<<std::endl;
	  if(index==2 || index==3) //doubled because of the vertex closeness
	    singThreeTags.push_back(cornerTag);
	  if(index==4 || index==5) //doubled because of the vertex closeness
	    singFiveTags.push_back(cornerTag);
	  cornerTag++;
	}
      }
    }
    std::cout<<"Corners written!"<<std::endl;

    int physicalGroup=-1;
    physicalGroup=gmsh::model::addPhysicalGroup(0, singThreeTags, -1);
    gmsh::model::setPhysicalName(0, physicalGroup, "SINGULARITY_OF_INDEX_THREE");
    physicalGroup=gmsh::model::addPhysicalGroup(0, singFiveTags, -1);
    gmsh::model::setPhysicalName(0, physicalGroup, "SINGULARITY_OF_INDEX_FIVE");
    // gmsh::model::occ::synchronize();
    gmsh::model::geo::synchronize();
    std::cout<<"Geometry ready!"<<std::endl;
    gmsh::fltk::run();
    //gmsh::write("myGeoFile.geo_unrolled");
    gmsh::finalize();

    return HXT_STATUS_OK;
  }

//------------------------------------------------------------------------------

//2.a generate separatrices with presecribed singularities - H function crosses
HXTStatus QuadGenerator::computeSeparatricesOnExistingSing(double *directionsH)
{
  HXT_CHECK(hxtEdgesCreate(m_triMesh,&m_triEdges));
  HXT_CHECK(hxtMalloc(&m_crossfield,2*m_triEdges->numEdges*sizeof(double)));
  for(uint64_t i=0;i<m_triEdges->numEdges;i++){
    m_crossfield[2*i+0]=directionsH[2*i+0];
    m_crossfield[2*i+1]=directionsH[2*i+1];
  } 
  std::cout<<"--COMPUTE SEPARATRICES--"<<std::endl;
  std::cout << "--Reading geo file to get singularities and corners--" << std::endl;
  std::vector<std::array<double,3>> allCoord;
  readGeoFileToBuildSingsAndCorners(&allCoord);
  std::cout << "--Reading finished--" << std::endl;
  std::cout << "--Building H singularities--" << std::endl;
  buildHSingularities(allCoord);
  std::cout << "--Writing all singularities--" << std::endl;
  hxtWriteSingularities("qmbAllSingularities.pos");
  std::cout << "--Writing all patches--" << std::endl;
  hxtWritePatches("qmbAllPatches.pos");
  std::cout << "--Build corners--" << std::endl;
  std::cout << "--Disable singularities on boundary and corner patches--" << std::endl;
  buildCorners();
  std::cout << "nSing before cleaning : " << m_vectSing.size() << std::endl;
  cleanSingularities();
  std::cout << "nSing after cleaning : " << m_vectSing.size() << std::endl;
  std::cout << "--Writing corners--" << std::endl;
  hxtWriteCorners("qmbCorners.pos");
  std::cout << "--Writing corner patches--" << std::endl;
  hxtWriteCornerPatches("qmbCornerPatches.pos");
  std::cout << "--Create boundaryLines--" << std::endl;
  createBoundaryLines();
  std::cout << "--Build Boundary--" << std::endl;
  buildBoundary();
  std::cout << "--Write boundary lines--" << std::endl;
  hxtWriteBdryLines("qmbBoundaryLines.pos");
  std::cout << "--Start initiation from corners--" << std::endl;
  initiationFromCorner();
  std::cout << "--Start initiation from H singularities--" << std::endl; 
  initiationFromHSingularities();
  std::cout << "--Writing singularities--" << std::endl;
  hxtWriteSingularities("qmbSingularities.pos");
  std::cout << "--Writing singular patches--" << std::endl;
  hxtWritePatches("qmbPatches.pos");
  std::cout << "--Write separatrices initiation --" << std::endl;
  hxtWriteInitSep("qmbInitiation.pos");
  std::cout << "--Disable initiation duplicates--" << std::endl;
  for(uint64_t t=0; t<m_vectSing.size(); t++)
    disableSepDuplicates((int) t);
  std::cout << "--Write separatrices initiation without duplicates--" << std::endl;
  hxtWriteInitSep("qmbInitiationNoDuplicates.pos");
  std::cout << "--Save bdry lines as separatrices--" << std::endl;
  saveBdryLinesAsSeparatrices();
  std::cout << "--Propagating separatrices--" << std::endl;
  uint64_t end=(m_vectSep.size()-m_vectBoundaryLine.size());
  for(uint64_t i=0; i<end; i++){
    std::cout<<"Sep: "<<i<<std::endl;
    propagateKowalski((int)i);
  }
  std::cout << "--Write separatrices--" << std::endl;
  hxtWriteSeparatricesPos("qmbSeparatrices.pos");
  std::cout<<"--Building intersection tri values--"<<std::endl;
  buildIntersectionTriValues();
  std::cout << "--Cleaning separatrices--" << std::endl;
  std::cout << "--Grouping--" << std::endl;
  groupingSep();
  std::cout << "--Global intersection--" << std::endl;
  globalIntersection();
  std::cout << "--Comparision--" << std::endl;
  comparison();
  std::cout<<"--Detecting limit cycles--"<<std::endl;
  std::vector<uint64_t> limitCycleIDs;
  detectLimitCycleCandidates(&limitCycleIDs);
  std::cout<<"NUM SEP1: "<<m_vectSep.size()<<std::endl;
  if(limitCycleIDs.size()==0)
    std::cout<<"NO LIMIT CYCLES!"<<std::endl;
  else{
    std::cout<<"LIMIT CYCLES PRESENT!"<<std::endl;
    std::cout<<"Num limit cycle candidates = "<<limitCycleIDs.size() <<", sep IDs:"<<std::endl;
    for(uint64_t t=0; t<limitCycleIDs.size(); t++)
      std::cout<<limitCycleIDs[t]<<std::endl;
    std::cout<<"--Write limit cycles--"<<std::endl;
    hxtWriteLimitCycleCandidates(&limitCycleIDs, "qmbLimitCycles.pos");
    std::cout<<"--Cut limit cycles--"<<std::endl;
    cutLimitCycleCandidates(&limitCycleIDs);
    std::cout<<"--Write cut limit cycles--"<<std::endl;
    hxtWriteLimitCycleCandidates(&limitCycleIDs, "qmbCutLimitCycles.pos");
    std::cout<<"--Solve limit cycles tangential crossings--"<<std::endl;
    solveTangentialCrossings(&limitCycleIDs);
  }
  std::cout<<"Total sep num: "<<m_vectSep.size()<<std::endl;
  std::cout<<"----COMPUTE SEPARATRICES FINISHED!----"<<std::endl;
  hxtWriteSavedSeparatrices("qmbCompleteSeparatrices.pos");
  hxtWriteEverything("qmbEverything.pos");
  return HXT_STATUS_OK;
}

//-----------------------------------------------------------------------------------------------------------

//2.b generate separatrices without prescribed singularities, CR crosses
HXTStatus QuadGenerator::computeSeparatrices(double *directionsCR)
{
  HXT_CHECK(hxtEdgesCreate(m_triMesh,&m_triEdges));
  HXT_CHECK(hxtMalloc(&m_crossfield,2*m_triEdges->numEdges*sizeof(double)));
  for(uint64_t i=0;i<m_triEdges->numEdges;i++){
    m_crossfield[2*i+0]=directionsCR[2*i+0];
    m_crossfield[2*i+1]=directionsCR[2*i+1];
  }  
  std::cout << "--Finding singularities--" << std::endl;
  findSingularitiesAndCreatePatches();
  std::cout << "--Writing singularities--" << std::endl;
  hxtWriteSingularities("qmbSingularities.pos");
  std::cout << "--Writing patches--" << std::endl;
  hxtWritePatches("qmbPatches.pos");
  std::cout << "--Build corners--" << std::endl;
  std::cout << "--Disable singularities on boundary and corner patches--" << std::endl;
  buildCorners();
  std::cout << "nSing before cleaning : " << m_vectSing.size() << std::endl;
  cleanSingularities();
  std::cout << "nSing after cleaning : " << m_vectSing.size() << std::endl;
  std::cout << "--Writing corners--" << std::endl;
  hxtWriteCorners("qmbCorners.pos");
  std::cout << "--Writing corner patches--" << std::endl;
  hxtWriteCornerPatches("qmbCornerPatches.pos");
  std::cout << "--Create boundaryLines--" << std::endl;
  createBoundaryLines();
  // feature lines : createFeatureLines
  // std::cout << "--Create featureLines--" << std::endl;
  // createFeatureLines();
  std::cout << "--Build Boundary--" << std::endl;
  buildBoundary(); // feature lines : not used
  std::cout << "--Write boundary lines--" << std::endl;
  hxtWriteBdryLines("qmbBoundaryLines.pos");
  std::cout << "--Start initiation from corners--" << std::endl;
  initiationFromCorner();
  std::cout << "--Start initiation from singularities--" << std::endl;
  initiationFromSingularities();
  std::cout << "--Write separatrices initiation --" << std::endl;
  hxtWriteInitSep("qmbInitiation.pos");
   std::cout << "--Disable initiation duplicates--" << std::endl;
  for(uint64_t t=0; t<m_vectSing.size(); t++){
    disableSepDuplicates((int) t);
  }
  std::cout << "--Write separatrices initiation without duplicates--" << std::endl;
  hxtWriteInitSep("qmbInitiationNoDuplicates.pos");
  std::cout << "--Save bdry lines as separatrices--" << std::endl;
  saveBdryLinesAsSeparatrices();
  std::cout << "--Propagating separatrices--" << std::endl;
  uint64_t end=(m_vectSep.size()-m_vectBoundaryLine.size());
  int num=0;
  for(uint64_t i=0; i<end; i++){
    propagateKowalski(num);
    num++;
  }
  std::cout << "--Write separatrices--" << std::endl;
  hxtWriteSeparatricesPos("qmbSeparatrices.pos");
   std::cout<<"--Building intersection tri values--"<<std::endl;
  buildIntersectionTriValues();
  std::cout << "--Cleaning separatrices--" << std::endl;
  std::cout << "--Grouping--" << std::endl;
  groupingSep();
  std::cout << "--Global intersection--" << std::endl;
  globalIntersection();
  std::cout << "--Comparision--" << std::endl;
  comparison();
  std::cout<<"--Detecting limit cycles--"<<std::endl;
  std::vector<uint64_t> limitCycleIDs;
  detectLimitCycleCandidates(&limitCycleIDs);
  if(limitCycleIDs.size()==0)
    std::cout<<"--No limit cycles!--"<<std::endl;
  else{
    std::cout<<"--Limit cycles exist!--"<<std::endl;
    std::cout<<"Num limit cycle candidates = "<<limitCycleIDs.size() <<", sep IDs:"<<std::endl;
    for(uint64_t t=0; t<limitCycleIDs.size(); t++)
      std::cout<<limitCycleIDs[t]<<std::endl;
    std::cout<<"--Write limit cycles--"<<std::endl;
    hxtWriteLimitCycleCandidates(&limitCycleIDs, "qmbLimitCycles.pos");
    std::cout<<"--Cut limit cycles--"<<std::endl;
    cutLimitCycleCandidates(&limitCycleIDs);
    std::cout<<"--Write cut limit cycles--"<<std::endl;
    hxtWriteLimitCycleCandidates(&limitCycleIDs, "qmbCutLimitCycles.pos");
    std::cout<<"--Solve limit cycles tangential crossings--"<<std::endl;
    solveTangentialCrossings(&limitCycleIDs);
  }
  std::cout<<"----COMPUTE SEPARATRICES FINISHED!----"<<std::endl;
  hxtWriteSavedSeparatrices("qmbCompleteSeparatrices.pos");
  hxtWriteEverything("qmbEverything.pos");

  
  return HXT_STATUS_OK;
}

int findTriNum(HXTEdges *edges, double *coordVert0, double *coordVert1, double *coordVert2, uint64_t *triNum){
  HXTMesh *mesh = edges->edg2mesh;
  *triNum=(uint64_t)-1;
  double norm1=1., norm2=1., norm3=1.;
  double point0[3], point1[3], point2[3];
  for(int i=0; i<3; i++){
    point0[i]=0.; point1[i]=0.; point2[i]=0.;
  }
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t vtri[3] = { mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    const double *v0 = mesh->vertices.coord + 4*vtri[0];
    const double *v1 = mesh->vertices.coord + 4*vtri[1];
    const double *v2 = mesh->vertices.coord + 4*vtri[2];
    for(int k=0; k<3; k++){
      point0[k] = v0[k];
      point1[k] = v1[k];
      point2[k] = v2[k];
    }
    if(isPointDuplicate(coordVert0, point0, &norm1)){
      if((isPointDuplicate(coordVert1, point1, &norm2) || isPointDuplicate(coordVert1, point2, &norm2)) &&
	 (isPointDuplicate(coordVert2, point1, &norm3) || isPointDuplicate(coordVert2, point2, &norm3)))
	*triNum=i;
    }
    if(isPointDuplicate(coordVert0, point1, &norm1)){
      if((isPointDuplicate(coordVert1, point0, &norm2) || isPointDuplicate(coordVert1, point2, &norm2)) &&
	 (isPointDuplicate(coordVert2, point0, &norm3) || isPointDuplicate(coordVert2, point2, &norm3)))
	*triNum=i;
    }
    if(isPointDuplicate(coordVert0, point2, &norm1)){
      if((isPointDuplicate(coordVert1, point0, &norm2) || isPointDuplicate(coordVert1, point1, &norm2)) &&
	 (isPointDuplicate(coordVert2, point0, &norm3) || isPointDuplicate(coordVert2, point1, &norm3)))
	*triNum=i;
    }

  }
  return 1;
}

int QuadGenerator::isTriUsed(HXTEdges *edges, int *markedTri, uint64_t triNum){
  HXTMesh *mesh = edges->edg2mesh;
  int flag=0;
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    if(markedTri[triNum]==1)
      flag=1;
  }
  return flag;
}

HXTStatus QuadGenerator::readHDirections(HXTEdges *edges, const char *filename, double *h_crossfield){ //apriori: const per triangle
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t *tri2edg = edges->tri2edg;
  uint64_t triNum=(uint64_t)-1;
  for(uint64_t i=0; i<edges->numEdges; i++){
    h_crossfield[2*i+0]=0.;
    h_crossfield[2*i+1]=0.;
  }
  int *markedTri;
  HXT_CHECK(hxtMalloc(&markedTri,mesh->triangles.num*sizeof(int)));
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    markedTri[i]=0;
  //read
  FILE* myfile = fopen(filename,"r");
  if (!myfile) return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED, "mesh file '%s' cannot be opened",(filename==NULL)?"NULL":filename);
  char buf[BUFSIZ]={""};
  if(fgets(buf, BUFSIZ, myfile)!=NULL){
    // if(strstr(buf, "View \"circle_Directions\"{")){   //to comment: name depends on geometry name 
    while(fgets(buf, BUFSIZ, myfile)!=NULL){
      double x0,y0,z0,x1,y1,z1,x2,y2,z2;
      double a0, a1, a2, b0, b1, b2, c0, c1, c2, m0, m1, m2, n0, n1, n2, p0, p1, p2;
      sscanf(buf, "VT(%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf){%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf}",
	     &x0,&y0,&z0,&x1,&y1,&z1,&x2,&y2,&z2, &a0,&a1,&a2,&b0,&b1,&b2,&c0,&c1,&c2,&m0,&m1,&m2,&n0,&n1,&n2,&p0,&p1,&p2);
      double point0[3]={x0, y0, z0};
      double point1[3]={x1, y1, z1};
      double point2[3]={x2, y2, z2};
   
      findTriNum(edges, point0, point1, point2, &triNum); //numbering corespondance between hxt and gmsh is good, but last tri is doubled
      std::cout<<"Triangle: "<<triNum<<std::endl;
      if(!isTriUsed(edges, markedTri,  triNum) && triNum!=(uint64_t)-1){
      	markedTri[triNum]=1;
	uint64_t edg0=tri2edg[3*triNum+0];
	uint64_t edg1=tri2edg[3*triNum+1];
	uint64_t edg2=tri2edg[3*triNum+2];
	const double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*triNum+0];
	const double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*triNum+1];
	const double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*triNum+2];
	double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
	double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
	e[0] /= norm; e[1] /= norm; e[2] /= norm;
      
	double e1[3] = {v2[0]-v1[0],v2[1]-v1[1],v2[2]-v1[2]};
	norm = sqrt(e1[0]*e1[0]+e1[1]*e1[1]+e1[2]*e1[2]);
	e1[0] /= norm; e1[1] /= norm; e1[2] /= norm;
      
	double e2[3] = {v0[0]-v2[0],v0[1]-v2[1],v0[2]-v2[2]};
	norm = sqrt(e2[0]*e2[0]+e2[1]*e2[1]+e2[2]*e2[2]);
	e2[0] /= norm; e2[1] /= norm; e2[2] /= norm;
	
	double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};        
	uint32_t vtri[3] = { mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]};
	HXT_CHECK( trianglebasis(mesh,vtri,U,V,n) );
	double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
	double f1[3] = {n[1]*e1[2]-n[2]*e1[1], n[2]*e1[0]-n[0]*e1[2], n[0]*e1[1]-n[1]*e1[0]};
	double f2[3] = {n[1]*e2[2]-n[2]*e2[1], n[2]*e2[0]-n[0]*e2[2], n[0]*e2[1]-n[1]*e2[0]};
	double norm2 = sqrt(a0*a0 + a1*a1 + a2*a2);
    
	int nbTurns=4;
	//values for each edg 
	double cosTheta = (a0*e[0] + a1*e[1] + a2*e[2])/norm2;
	double sinTheta = (a0*f[0] + a1*f[1] + a2*f[2])/norm2;
	double theta = atan2(sinTheta,cosTheta);
	h_crossfield[2*edg0+0]+= norm2*cos(nbTurns*theta);
	h_crossfield[2*edg0+1]+= norm2*sin(nbTurns*theta);

	cosTheta = (a0*e1[0] + a1*e1[1] + a2*e1[2])/norm2;
	sinTheta = (a0*f1[0] + a1*f1[1] + a2*f1[2])/norm2;
	theta = atan2(sinTheta,cosTheta);
	h_crossfield[2*edg1+0]+= norm2*cos(nbTurns*theta);
	h_crossfield[2*edg1+1]+= norm2*sin(nbTurns*theta);

	cosTheta = (a0*e2[0] + a1*e2[1] + a2*e2[2])/norm2;
	sinTheta = (a0*f2[0] + a1*f2[1] + a2*f2[2])/norm2;
	theta = atan2(sinTheta,cosTheta);
	h_crossfield[2*edg2+0]+= norm2*cos(nbTurns*theta);
	h_crossfield[2*edg2+1]+= norm2*sin(nbTurns*theta);
      }
    }
  }
  fclose(myfile);
 
  //average theta on not bdry edges
  for(uint64_t i=0; i<edges->numEdges; i++){
    uint32_t *edgNodes = &(edges->node[2*i]);
    if(!(hxtEdgesIsBoundary(edges, edgNodes) && edges->edg2tri[2*i+1]==(uint64_t)-1)){
      h_crossfield[2*i+0]/=2.;
      h_crossfield[2*i+1]/=2.;
    }
  }
  
  HXT_CHECK(hxtFree(&markedTri));
   
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::writeHDirectionsEdges(HXTEdges *edges, double *h_crossfield, const char *filename){
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t *edg2tri = edges->edg2tri;
  
  FILE* myfile = fopen(filename,"w");
  fprintf(myfile,"View \"Direction field H\"{\n");
  for(uint64_t i=0; i<edges->numEdges; i++){    
    double Ue, Ve;
    Ue = h_crossfield[2*i+0];
    Ve = h_crossfield[2*i+1];
    double ne = sqrt(Ue*Ue+Ve*Ve);  //is it necessary? not
    double theta = atan2(Ve,Ue)/4.; //----
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;

    for(int t=0; t<2; t++){// for each triangle
      uint64_t numtri = edg2tri[2*i+t];
      if (numtri != (uint64_t)-1){
        double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};        
        uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
        HXT_CHECK( trianglebasis(mesh,vtri,U,V,n) );
	
        double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]}; //local transform
	
        for(int nb=0; nb<4; nb++){  
          theta += 2.*M_PI/4.;
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

HXTStatus QuadGenerator::readGeoFileToBuildSingsAndCorners(std::vector<std::array<double,3>> *allCoord){  
  
  gmsh::vectorpair dimTags;
  gmsh::model::getPhysicalGroups(dimTags,0);
  std::cout<<"Num physical groups: "<<dimTags.size()<<std::endl;
  std::string name=" ", s3="SINGULARITY_OF_INDEX_THREE", s5="SINGULARITY_OF_INDEX_FIVE", s6="SINGULARITY_OF_INDEX_SIX", s8="SINGULARITY_OF_INDEX_EIGHT";
  double xmin=0., ymin=0., zmin=0., xmax=0., ymax=0., zmax=0.;
  std::array<double,3> point;
  for(uint64_t i=0; i<dimTags.size(); i++){
    gmsh::model::getPhysicalName(0, dimTags[i].second, name);
    std::cout<<"Physical name:"<<name<<std::endl;
    if(name.compare(s3)==0 || name.compare(s5)==0 || name.compare(s6)==0 || name.compare(s8)==0){
      std::vector<int> pointsTags;
      gmsh::model::getEntitiesForPhysicalGroup(0, dimTags[i].second, pointsTags);
      for(uint64_t j=0; j<pointsTags.size(); j++){
	gmsh::model::getBoundingBox(0, pointsTags[j], xmin, ymin, zmin, xmax, ymax, zmax);
	point[0]=xmin; point[1]=ymin; point[2]=zmin;
	(*allCoord).push_back(point);
      }
    }
  }
  
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::constructHSingularity(int ID, std::array<double, 3> singCoord, std::vector<uint64_t> *singEdges){ 
  HXTEdges *edg=m_triEdges;
  HXTMesh *mesh = edg->edg2mesh;
  uint32_t *tri2edg = edg->tri2edg;
  double norm=-1.;
  std::vector<uint64_t> patch;
  double vert0[3], vert1[3], vert2[3], singularity[3];
  for(int i=0; i<3; i++){
    vert0[i]=0.; vert1[i]=0.; vert2[i]=0.;
    singularity[i]=singCoord[i];
  }
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    for(int k=0; k<3; k++){
      vert0[k]=v0[k]; vert1[k]=v1[k]; vert2[k]=v2[k];
    }
    if(isPointDuplicate(vert0,singularity, &norm)){
      patch.push_back(i);
      (*singEdges).push_back((uint64_t)tri2edg[3*i+1]);
    }
    if(isPointDuplicate(vert1,singularity, &norm)){
      patch.push_back(i);
      (*singEdges).push_back((uint64_t)tri2edg[3*i+2]);
    }
    if(isPointDuplicate(vert2,singularity, &norm)){
      patch.push_back(i);
      (*singEdges).push_back((uint64_t)tri2edg[3*i+0]);
    }
  }

  Singularity s(ID, (*singEdges)[0], singCoord, patch);
  m_vectSing.push_back(s);
  
  return HXT_STATUS_OK;
}

HXTStatus  QuadGenerator::buildHSingularities(std::vector<std::array<double,3>> allCoord){
  for(uint64_t i=0; i<allCoord.size(); i++){
    std::vector<uint64_t> singEdges;
    constructHSingularity((int) i, allCoord[i], &singEdges);
  }
   
  return HXT_STATUS_OK;
}

HXTStatus  QuadGenerator::getSingularEdges(int singID, std::vector<uint64_t> *singEdges){
  HXTEdges *edg=m_triEdges;
  HXTMesh *mesh = edg->edg2mesh;
  uint32_t *tri2edg = edg->tri2edg;
  double norm=-1.;
  Singularity *s=&m_vectSing[singID];
  std::array<double,3> *singCoord=s->getPCoord();
  double singPoint[3], vert0[3], vert1[3], vert2[3];
  for(int i=0; i<3; i++)
    singPoint[i]=(*singCoord)[i];
  
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    for(int k=0; k<3; k++){
      vert0[k]=v0[k]; vert1[k]=v1[k]; vert2[k]=v2[k];
    }
    if(isPointDuplicate(vert0,singPoint, &norm)){
      (*singEdges).push_back((uint64_t)tri2edg[3*i+1]);
    }
    if(isPointDuplicate(vert1,singPoint, &norm)){
      (*singEdges).push_back((uint64_t)tri2edg[3*i+2]);
    }
    if(isPointDuplicate(vert2,singPoint, &norm)){
      (*singEdges).push_back((uint64_t)tri2edg[3*i+0]);
    }
  }
  
   return HXT_STATUS_OK;
}

int QuadGenerator::seedingSingularity(int sizeSeed, uint64_t edgToSeed, uint64_t triNum, double *x, int *sizeP)
{
  HXTEdges* edg=m_triEdges;
  HXTMesh* m=edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  //double angleLim=M_PI/180.0*2.0;
  double angleLim=M_PI/180.0*5.0;
  int k=-1;
  for(int i=0; i<3;i++){
    if(edgToSeed==edg->tri2edg[3*triNum+i]){
      k=i;
    }
  } 
  double coordVertex[3*3] = {vert[4*nodes[3*triNum+k]+0],vert[4*nodes[3*triNum+k]+1],vert[4*nodes[3*triNum+k]+2],
			     vert[4*nodes[3*triNum+(k+1)%3]+0],vert[4*nodes[3*triNum+(k+1)%3]+1],vert[4*nodes[3*triNum+(k+1)%3]+2],
			     vert[4*nodes[3*triNum+(k+2)%3]+0],vert[4*nodes[3*triNum+(k+2)%3]+1],vert[4*nodes[3*triNum+(k+2)%3]+2]};
  double A[3], AB[3], P[3], S[3], PS[3];
  for(int j=0; j<3; j++){
    A[j]=coordVertex[j];
    AB[j]=coordVertex[j+3]-coordVertex[j];
    S[j]=coordVertex[j+6];
  }
  uint32_t vtri[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3], m->triangles.node[3*triNum+(k+2)%3]};
  double u[3], v[3], n[3];
  trianglebasis(m, vtri,u,v,n);
  *sizeP=0;
  double *seeds;
  HXT_CHECK(hxtMalloc(&seeds, sizeSeed*sizeof(double)));
  int flagSeedToAdd=1;
  for(int l=0; l<sizeSeed; l++)
    seeds[l]=(1.0*l+1.0)/(1.0*sizeSeed+1.0);
  for(int l=0; l<sizeSeed; l++){
    double xi=seeds[l];
    for(int j=0; j<3; j++){
      P[j]=A[j]+xi*AB[j];
    }
    for(int j=0; j<3; j++){
      PS[j]=S[j]-P[j];
    }
    double enteringAngle;
    double sinAngle=myDot(v,PS);
    double cosAngle=myDot(u,PS);
    enteringAngle=atan2(sinAngle, cosAngle);
    double closestAngle;
    closestBranchInTri(triNum, edg->tri2edg[3*triNum+k], P, enteringAngle, &closestAngle);
    if((cos(angleLim)<cos(enteringAngle-closestAngle))){
      if(flagSeedToAdd==1){
	x[*sizeP]=xi;
	(*sizeP)++;
	flagSeedToAdd=0; 
      }
    }else{
      flagSeedToAdd=1;
    }
  }
  HXT_CHECK(hxtFree(&seeds));
  return 1;
}

HXTStatus  QuadGenerator::initiationFromHSingularities(){
  HXTEdges* edges=m_triEdges;
  HXTMesh* m=edges->edg2mesh;
  int sizeSeeding=m_sizeSeeding;
  double a1[3], a2[3], point2[3];
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&m_vectSing[i];
    if(!s->isDisabled()){ //real singularity
      std::vector<uint64_t> singTri=s->getPatch();
      std::vector<uint64_t> singEdges;
      getSingularEdges((int) i, &singEdges);
      //initiation
      int initAlloc=50000;
      for(uint64_t j=0; j<singEdges.size(); j++){
	uint64_t  e1=singEdges[j];
	int sizeSeedCorner=0;
	double xC[1000]={0.5};
	seedingSingularity(sizeSeeding, singEdges[j], singTri[j], xC, &sizeSeedCorner);

	for(int k=0;k<sizeSeedCorner;k++){
	  uint64_t *triangleNumbers1; 
	  HXT_CHECK(hxtMalloc(&triangleNumbers1, initAlloc*sizeof(uint64_t))); 
	  triangleNumbers1[0]=singTri[j]; //should be Master triangle
	  triangleNumbers1[1]=singTri[j]; 
	  int r=-1;
	  for(int l=0; l<3;l++){
	    if(e1==edges->tri2edg[3*triangleNumbers1[1]+l]){
	      r=l;
	    }
	  }
      
	  double *v0 = m->vertices.coord + 4*edges->edg2mesh->triangles.node[3*triangleNumbers1[1]+r];
	  double *v1 = m->vertices.coord + 4*edges->edg2mesh->triangles.node[3*triangleNumbers1[1]+(r+1)%3];
	  for(int k=0; k<3; k++){
	    a1[k]=v1[k]-v0[k];
	  }
	  std::array<double,3> *singCoord=s->getPCoord();
	  double point1[3]={(*singCoord)[0], (*singCoord)[1], (*singCoord)[2]}; 
	  for(int t=0; t<3; t++){
	    point2[t]=v0[t]+a1[t]*xC[k];
	  }
	  for(int k=0; k<3; k++){
	    a2[k]=point1[k]-point2[k];
	  }
	  double normA1 = 0.0;
	  double normA2 = 0.0;
	  for(int k=0; k<3; k++){
	    normA1+=a1[k]*a1[k];
	    normA2+=a2[k]*a2[k];
	  }
	  normA1=sqrt(normA1);
	  normA2=sqrt(normA2);
	  double alpha1=acos(myDot(a1,a2)/(normA1*normA2));
	  //storing separatrice
	  int ID=m_vectSep.size();
	  std::vector<std::array<double,3>> nodesCoord;
	  std::array<double,3> p1,p2;
	  for(int s=0; s<3; s++){
	    p1[s]=point1[s];
	    p2[s]=point2[s];
	  }
	  nodesCoord.push_back(p1);
	  nodesCoord.push_back(p2);
	  std::vector<uint64_t> triangles;
	  triangles.push_back(triangleNumbers1[0]);
	  triangles.push_back(triangleNumbers1[1]);
	  std::vector<uint64_t> edges;
	  edges.push_back(e1);
	  std::vector<double> enteringAngles;
	  enteringAngles.push_back(alpha1);
	  //num of elements =2
	  Separatrice sep(ID, nodesCoord, triangles, edges, enteringAngles);
	  m_vectSep.push_back(sep);
	  HXT_CHECK(hxtFree(&triangleNumbers1));
	}
      }
    }
  }

  return HXT_STATUS_OK;
}

int QuadGenerator::isPointCorner(std::array<double,3> *point){
  int indicator=0;
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::array<double,3> cCoord=c->getCoord();
    double point2[3]={0.};
    double point1[3]={0.};
    double norm;
    for(int j=0; j<3; j++){
      point2[j]=cCoord[j];
      point1[j]=(*point)[j];
    }
    if(isPointDuplicate(point1, point2, &norm)){
      indicator=1;
    }
  }
  return indicator;
}

std::vector<uint64_t>* QuadGenerator::getSingularityOrCornerPatch(std::array<double,3> *point){
  double point1[3]={0.};
  for(int i=0; i<3; i++)
    point1[i]=(*point)[i];
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::array<double,3> singCoord=s->getCoord();
    double point2[3]={0.};
    double norm;
    for(int j=0; j<3; j++)
      point2[j]=singCoord[j];
    if(isPointDuplicate(point1, point2, &norm)){
      return s->getPPatch();
    }
  }
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::array<double,3> cornerCoord=c->getCoord();
    double point2[3]={0.};
    double norm;
    for(int j=0; j<3; j++)
      point2[j]=cornerCoord[j];
    if(isPointDuplicate(point1, point2, &norm)){
      return c->getPPatch();
    }
  }
  return NULL;
}

HXTStatus QuadGenerator::addLastPatchInIgnoredPatchs(int sepID){
  std::vector<std::array<double,3>>* pCoord = m_vectSep[sepID].getPCoord();
  std::array<double,3> lastPoint=(*pCoord)[pCoord->size()-1];
  std::vector<uint64_t>* patch = getSingularityOrCornerPatch(&lastPoint);
  if(patch==NULL){
    std::cout << "Mistake in built patches! " << std::endl;
    exit(0);
  }
  m_vectSep[sepID].addToIgnoredPatch(patch);
  return HXT_STATUS_OK;
}

int QuadGenerator::checkIfInPatch(uint64_t triNum, std::array<double,3> *point){
  int isInPatch=0;
  for(int i=0; i<3; i++)
    (*point)[i]=-1;
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::vector<uint64_t> *patch=s->getPPatch();
    for(uint64_t j=0; j<patch->size(); j++){
      if(triNum==(*patch)[j]){
	isInPatch=1;
	std::array<double,3> *coordSing=s->getPCoord();
	for(int k=0; k<3; k++)
	  (*point)[k]=(*coordSing)[k];
      }
    }
  }
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::vector<uint64_t> *patch=c->getPPatch();
    for(uint64_t j=0; j<patch->size(); j++){
      if(triNum==(*patch)[j]){
	isInPatch=1;
	std::array<double,3> *coordCorner=c->getPCoord();
	for(int k=0; k<3; k++)
	  (*point)[k]=(*coordCorner)[k];
      }
    }
  }
  return isInPatch;
}

void QuadGenerator::projectDirOnTriPlan(double *dir, uint64_t triNum){
  HXTMesh *mesh=m_triEdges->edg2mesh;
  uint32_t vTri[3] = {mesh->triangles.node[3*(triNum)+0],mesh->triangles.node[3*(triNum)+1],mesh->triangles.node[3*(triNum)+2]};
  double U[3],V[3],n[3];
  trianglebasis(mesh, vTri, U, V, n);
  double scalarP=0.0;
  for(int i=0;i<3;i++)
    scalarP+=dir[i]*n[i];
  for(int i=0;i<3;i++)
    dir[i]=dir[i]-scalarP*n[i];
  return;
}

HXTStatus QuadGenerator::linkSepToSing(Separatrice *sep, uint64_t triNum, uint64_t edgNum, std::array<double,3> singPoint, bool *discard){
  std::vector<std::array<double,3>> *points=sep->getPCoord();
  bool flag=1;
  double coordSing[3]={0.};
  double lastDir[3]={0.};
  for(uint64_t i=0;i<3;i++){
    coordSing[i]=singPoint[i];
    lastDir[i]=((*points)[points->size()-1])[i]-((*points)[points->size()-2])[i];
  }
  double dirToSing2[3]={0.0};
  for(uint64_t i=0;i<3;i++){
    dirToSing2[i]=singPoint[i]-((*points)[points->size()-1])[i];
  }
  uint64_t newTriNumForProj=m_triEdges->edg2tri[2*edgNum+0];
  if (newTriNumForProj==triNum){
    newTriNumForProj=m_triEdges->edg2tri[2*edgNum+1];  // do something if newtrinum is -1
  }

  projectDirOnTriPlan(dirToSing2,newTriNumForProj);
  normalize(dirToSing2);
  normalize(lastDir);
  double crossProdDir[3]={0.};
  crossprod(dirToSing2, lastDir, crossProdDir);
  double sinDir=0.0;
  for(uint64_t i=0;i<3;i++)
    sinDir+=crossProdDir[i]*crossProdDir[i];
  sinDir=sqrt(sinDir);
  double cosDir= myDot(dirToSing2,lastDir);
  double angleLink=atan2(sinDir,cosDir);
  sep->setLinkAngle(angleLink);
  if(angleLink>=M_PI/2.0)
    *discard=1;
  else
    *discard=0;
  while(flag){
    double dirToSing[3]={0.0};
    double lastPoint[3]={0.0};
    // double coordP[3]={0.};
    for(uint64_t i=0;i<3;i++){
      lastPoint[i]=((*points)[points->size()-1])[i];
      dirToSing[i]=singPoint[i]-lastPoint[i];
    }
    newTriNumForProj=m_triEdges->edg2tri[2*edgNum+0];
    if (newTriNumForProj==triNum){
      newTriNumForProj=m_triEdges->edg2tri[2*edgNum+1];  // do something if newtrinum is -1
    }

    projectDirOnTriPlan(dirToSing,newTriNumForProj);

    double newPoint[3]={0.0};
    uint64_t newEdgNum=-1;
    double angle=0;
    trialPoint(triNum, edgNum, lastPoint, dirToSing, newPoint, &newEdgNum, &angle);
    double d1[3]={0.0};
    double d2[3]={0.0};
    for(int k=0; k<3; k++){
      d1[k] = newPoint[k]-lastPoint[k];
      d2[k] = dirToSing[k];
    }
    double norm2=0.0;
    for(int k=0; k<3; k++)
      norm2+=d1[k]*d1[k];
    norm2=sqrt(norm2);
    for(int k=0; k<3; k++)
      d1[k]=d1[k]/norm2;
    norm2=0.0;
    for(int k=0; k<3; k++)
      norm2+=d2[k]*d2[k];
    norm2=sqrt(norm2);
    for(int k=0; k<3; k++)
      d2[k]=d2[k]/norm2;
    double scalarp = 0.0;
    for(int k=0; k<3; k++)
      scalarp += d1[k]*d2[k];

    if(scalarp<0){
      uint64_t nTriNum=m_triEdges->edg2tri[2*edgNum+0];
      if (nTriNum==triNum){
    	nTriNum=m_triEdges->edg2tri[2*edgNum+1]; // do something if newtrinum is -1
      }
      triNum=nTriNum;
      trialPoint(triNum, edgNum, lastPoint, dirToSing, newPoint, &newEdgNum, &angle);
    }
    std::array<double,3> newPointForSep={{0.0,0.0,0.0}};
    for(uint64_t i=0;i<3;i++)
      newPointForSep[i]=newPoint[i];
    sep->addPoint(newPointForSep);
    uint64_t newTriNum=m_triEdges->edg2tri[2*edgNum+0];
    if(newTriNum==triNum){
      newTriNum=m_triEdges->edg2tri[2*edgNum+1];  // do something if newtrinum is -1
    }

    sep->addTriangle(newTriNum);	
    triNum=newTriNum;
    edgNum=newEdgNum;
    double norm=0;
    if(isPointDuplicate(newPoint, coordSing, &norm))
      flag=0;
  }
  return HXT_STATUS_OK;
}

int QuadGenerator::closestPointAngle(uint64_t triNum, uint64_t edgNum, double *coordP, double enteringAngle, double *closestAngle){
  const double *crossField=m_crossfield;
  int nbTurns=m_nbTurns;
  HXTEdges *edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  uint32_t newTriNum=edg->edg2tri[2*edgNum+0]; 
  double  AB[3], AC[3], AP[3], U[3],V[3], e[3], e1[3];
  int k=-1;
  if (newTriNum==triNum){
    newTriNum=edg->edg2tri[2*edgNum+1];
  }
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*newTriNum+i]){
      k=i;
    }
  }
  for(int j=0;j<3;j++){
    U[j] = crossField[2*edg->tri2edg[3*newTriNum+(k+j)%3]+0];
    V[j] = crossField[2*edg->tri2edg[3*newTriNum+(k+j)%3]+1];
  }
  uint32_t vTriNum[3] = {m->triangles.node[3*newTriNum+k],m->triangles.node[3*newTriNum+(k+1)%3],m->triangles.node[3*newTriNum+(k+2)%3]};
  double u1[3]={0,0,0};
  double v1[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(m,vTriNum,u1,v1,n);
  uint64_t edgNum1=edg->tri2edg[3*newTriNum+(k+1)%3];
  uint64_t edgNum2=edg->tri2edg[3*newTriNum+(k+2)%3];
  for(int j=0; j<3; j++){
    e[j]=vert[4*edg->node[2*edgNum2+1]+j]-vert[4*edg->node[2*edgNum2+0]+j];
    e1[j]=vert[4*edg->node[2*edgNum1+1]+j]-vert[4*edg->node[2*edgNum1+0]+j];
  }
  normalize(e); normalize(e1);
  double angAlpha2 = atan2(myDot(e,v1), myDot(e,u1));
  double angAlpha1 = atan2(myDot(e1,v1), myDot(e1,u1));
  multR(angAlpha1*nbTurns, &U[1], &V[1]);
  multR(angAlpha2*nbTurns, &U[2], &V[2]);
  for(int j=0; j<3;j++){
    AB[j]=vert[4*nodes[3*newTriNum+(k+1)%3]+j]-vert[4*nodes[3*newTriNum+k]+j];
    AC[j]=vert[4*nodes[3*newTriNum+(k+2)%3]+j]-vert[4*nodes[3*newTriNum+k]+j];
    AP[j]=coordP[j]-vert[4*nodes[3*newTriNum+k]+j];
  }
  double q[3]={0,0,0};
  crossprod(AB, AC, q);
  double s[3]={0,0,0};
  crossprod(AP, AB, s);
  double t[3]={0,0,0};
  crossprod(AP, AC, t);
  double xi=myDot(t,q)/myDot(q,q);
  double eta=-myDot(s,q)/myDot(q,q);
  double theta = atan2(V[0]-V[1]+V[2]+2*xi*(V[1]-V[2])+2*eta*(V[1]-V[0]), U[0]-U[1]+U[2]+2*xi*(U[1]-U[2])+2*eta*(U[1]-U[0]))/nbTurns;
  double b[4]={theta, theta+M_PI/2., theta+M_PI, theta+M_PI*(3./2.)};
  double minDiff=-2.0;
  double minAngle=0.0;
  for(int i=0; i<4; i++){
    if ((minDiff < cos(b[i]-enteringAngle))){
      minDiff= cos((b[i]-enteringAngle));
      minAngle=b[i];
    }
  }
  *closestAngle=atan2(sin(minAngle), cos(minAngle));
  return 1;
}

int QuadGenerator::closestDirection(uint64_t triNum, uint64_t  edgNum,  double *angleDirection,  double *direction){
  HXTEdges *edg=m_triEdges;
  double  pEdge[3], t[3], n[3], v[3];
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  double alpha=*angleDirection;
  uint64_t newTriNum=edg->edg2tri[2*edgNum+0];
  if (newTriNum==triNum){
    newTriNum=edg->edg2tri[2*edgNum+1];  
  }
  int k=-1;
  
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*newTriNum+i]){
      k=i;
    }
  }
  uint64_t vTriNum[3] = {m->triangles.node[3*newTriNum+k],m->triangles.node[3*newTriNum+(k+1)%3],m->triangles.node[3*newTriNum+(k+2)%3]};

  //New local edge num of pEdge (AB) is k
  for(int j=0; j<3; j++){
    pEdge[j]=vert[4*vTriNum[1]+j]-vert[4*vTriNum[0]+j];
  }
  normalize(pEdge);

  //New local num of AC is (k+2)%3
  for(int j=0; j<3; j++){
    t[j]=vert[4*vTriNum[2]+j]-vert[4*vTriNum[0]+j];
  }
  normalize(t);
  
  myNormalizedCrossprod(pEdge,t, n);
  myNormalizedCrossprod(n, pEdge, v);
  for(int j=0;j<3;j++){
    direction[j]=cos(alpha)*pEdge[j]+sin(alpha)*v[j];
  }
  return 1;
}

int QuadGenerator::trialPoint(uint64_t triNum, uint64_t edgNum, double *coordP, double *direction, double *pointCoord,  uint64_t *newEdgNum, double *angle){
  HXTEdges *edg=m_triEdges;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  uint64_t newTriNum=edg->edg2tri[2*edgNum+0];
  if (newTriNum==triNum){
    newTriNum=edg->edg2tri[2*edgNum+1];  // do something if newtrinum is -1
  }
  double A[3], B[3], C[3], BC[3], CB[3], AC[3], CA[3], PC[3], PB[3], AB[3];
  double beta=-1.0, gamma=-1.0;
  int k=-1;  
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*newTriNum+i]){
      k=i;           
    }
  }
  double coordVertex[3*3] = {vert[4*nodes[3*newTriNum+k]+0],vert[4*nodes[3*newTriNum+k]+1],vert[4*nodes[3*newTriNum+k]+2],
			     vert[4*nodes[3*newTriNum+(k+1)%3]+0],vert[4*nodes[3*newTriNum+(k+1)%3]+1],vert[4*nodes[3*newTriNum+(k+1)%3]+2],
			     vert[4*nodes[3*newTriNum+(k+2)%3]+0],vert[4*nodes[3*newTriNum+(k+2)%3]+1],vert[4*nodes[3*newTriNum+(k+2)%3]+2]};
  for(int j=0; j<3; j++){
    A[j]= coordVertex[j];
    B[j]= coordVertex[j+3];
    C[j]= coordVertex[j+6];
    AB[j]=B[j]-A[j]; BC[j]=C[j]-B[j]; CB[j]=B[j]-C[j]; CA[j]=A[j]-C[j]; AC[j]=C[j]-A[j];
    PC[j] = C[j]-coordP[j];
    PB[j] = B[j]-coordP[j];
  }
  double u[3]={0.0};
  double normAB=0.0;
  for(int j=0; j<3; j++)
    normAB+=AB[j]*AB[j];
  normAB=sqrt(normAB);
  for(int j=0; j<3; j++)
    u[j]=AB[j]/normAB;
  double n[3]={0,0,0}; 
  myNormalizedCrossprod(AB, AC, n);
  double v[3]={0,0,0};
  myNormalizedCrossprod(n, AB, v);
  double du=myDot(direction, u);
  double dv=myDot(direction, v);
  double BCu=myDot(BC, u);
  double BCv=myDot(BC, v);
  double PBu=myDot(PB, u);
  double PBv=myDot(PB, v);
  double PCu=myDot(PC, u);
  double PCv=myDot(PC, v);
  double CAu=myDot(CA, u);
  double CAv=myDot(CA, v);
  int isParallelBC=0;
  int isParallelCA=0;
  if(fabs(du)<1e-10){
    if(fabs(BCu)<1e-10)
      isParallelBC=1;
    else
      beta=-PBu/BCu;
    if(fabs(CAu)<1e-10)
      isParallelCA=1;
    else
      gamma=-PCu/CAu;
  }
  else{
    if(fabs(BCv-dv*BCu/du)<1e-10)
      isParallelBC=1;
    else
      beta=(dv*PBu/du-PBv)/(BCv-dv*BCu/du);
    if(fabs(CAv-dv*CAu/du)<1e-10)
      isParallelCA=1;
    else
      gamma=(dv*PCu/du-PCv)/(CAv-dv*CAu/du);
  }
  if(!isParallelBC&&beta>=0&&beta<1){
  // if(!isParallelBC&&beta>=0&&beta<=1){
    if(fabs(beta)<1e-6)
      beta=1e-6;
    if(fabs(1-beta)<1e-6)
      beta=1-1e-6;
    for(int j=0; j<3; j++){
      pointCoord[j] = B[j]+beta*BC[j];
    }
    *newEdgNum=edg->tri2edg[3*newTriNum+((k+1)%3)];
    //finding entering angle
    double PI[3];
    for(int i=0; i<3; i++){
      PI[i]=pointCoord[i]-coordP[i];
    }
    normalize(PI); normalize(CB); normalize(CA);
    double n[3]={0,0,0}; 
    myNormalizedCrossprod(CA, CB, n);
    double v[3]={0,0,0};
    myNormalizedCrossprod(n,CB, v);
    double sinAngle=myDot(v,PI);
    double cosAngle=myDot(CB,PI);
    *angle=atan2(sinAngle, cosAngle);
  }
 else if(!isParallelCA&&gamma>=0&&gamma<1){
  //else if(!isParallelCA&&gamma>=0&&gamma<=1){
    if(fabs(gamma)<1e-6)
      gamma=1e-6;
    if(fabs(1-gamma)<1e-6)
      gamma=1-1e-6;
    for(int j=0; j<3; j++){
      pointCoord[j] = C[j]+gamma*CA[j];
    }
    *newEdgNum=edg->tri2edg[3*newTriNum+((k+2)%3)];
    //finding entering angle
    double PI[3];
    for(int i=0; i<3; i++){
      PI[i]=pointCoord[i]-coordP[i];
    }
    normalize(PI); normalize(AC); normalize(AB);
    double n[3]={0,0,0}; 
    myNormalizedCrossprod(AB, AC, n);
    double v[3]={0,0,0};
    myNormalizedCrossprod(n, AC, v);
    double sinAngle=myDot(v,PI);
    double cosAngle=myDot(AC,PI);
    *angle=atan2(sinAngle, cosAngle);
  }
  else{
    std::cout<<"Check trialPoint function  - sep is hitting the vertex"<< std::endl;
    // exit(0);
  }
  return 1;
}

int QuadGenerator::correction(double *pointCoord, uint64_t triNum, uint64_t edgNum, double enteringAngle, double *direction){
  const double *crossField=m_crossfield;
  HXTEdges *edg=m_triEdges;
  int nbTurns=m_nbTurns;
  HXTMesh *m = edg->edg2mesh;
  double *vert = m->vertices.coord;
  uint32_t* nodes = m->triangles.node;
  int k=-1;
  for(int i=0; i<3;i++){
    if(edgNum==edg->tri2edg[3*triNum+i]){
      k=i;
    }
  }
  double U[3], V[3], e2[3], e1[3], AB[3], AC[3], AP[3];
  for(int j=0;j<3;j++){
    U[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+0];
    V[j] = crossField[2*edg->tri2edg[3*triNum+(k+j)%3]+1];
  }
  uint32_t vTriNum[3] = {m->triangles.node[3*triNum+k],m->triangles.node[3*triNum+(k+1)%3],m->triangles.node[3*triNum+(k+2)%3]};
  double u1[3]={0,0,0};
  double v1[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(m,vTriNum,u1,v1,n);
  uint64_t edgNum1=edg->tri2edg[3*triNum+(k+1)%3];
  uint64_t edgNum2=edg->tri2edg[3*triNum+(k+2)%3];
  for(int j=0; j<3; j++){
    e2[j]=vert[4*edg->node[2*edgNum2+1]+j]-vert[4*edg->node[2*edgNum2+0]+j];
    e1[j]=vert[4*edg->node[2*edgNum1+1]+j]-vert[4*edg->node[2*edgNum1+0]+j];
  }
  normalize(e2); 
  double angAlpha2 = atan2(myDot(e2,v1), myDot(e2,u1));
  normalize(e1);
  double angAlpha1 = atan2(myDot(e1,v1), myDot(e1,u1));
  multR(angAlpha1*nbTurns, &U[1], &V[1]);
  multR(angAlpha2*nbTurns, &U[2], &V[2]);
  for(int j=0; j<3;j++){
    AB[j]=vert[4*nodes[3*triNum+(k+1)%3]+j]-vert[4*nodes[3*triNum+k]+j];
    AC[j]=vert[4*nodes[3*triNum+(k+2)%3]+j]-vert[4*nodes[3*triNum+k]+j];
    AP[j]=pointCoord[j]-vert[4*nodes[3*triNum+k]+j];
  }
  double q[3]={0,0,0};
  crossprod(AB, AC, q);
  double s[3]={0,0,0};
  crossprod(AP, AB, s);
  double t[3]={0,0,0};
  crossprod(AP, AC, t);
  double xi=myDot(t,q)/myDot(q,q);
  double eta=-myDot(s,q)/myDot(q,q);
  double theta = atan2(V[0]-V[1]+V[2]+2*xi*(V[1]-V[2])+2*eta*(V[1]-V[0]), U[0]-U[1]+U[2]+2*xi*(U[1]-U[2])+2*eta*(U[1]-U[0]))/nbTurns;
  double b[4]={theta, theta+M_PI/2., theta+M_PI, theta+M_PI*(3./2.)};
  double minDiff=-2;
  double minAngle=-100.;
  for(int i=0; i<4; i++){
    if ((minDiff < (cos(b[i]-enteringAngle)))){
      minDiff= (cos(b[i]-enteringAngle));
      minAngle=atan2(sin(b[i]), cos(b[i]));
      minAngle=atan2(sin(minAngle), cos(minAngle));
    }
  }
  double d1[3]={0.};
  double d2[3]={0.};
  for(int k=0; k<3; k++){
    d1[k] = -cos(enteringAngle)*u1[k]-sin(enteringAngle)*v1[k];
    d2[k] = -cos(minAngle)*u1[k]-sin(minAngle)*v1[k];
  }
  for(int k=0; k<3; k++){
    direction[k]=d1[k]+d2[k];
  }
  double norm=0.0;
  for(int k=0; k<3; k++)
    norm+=direction[k]*direction[k];
  norm=sqrt(norm);
  for(int k=0; k<3; k++)
    direction[k]=direction[k]/norm;
  return 1;
}

int QuadGenerator::candidatePoint(double *coordP, uint64_t triNum, uint64_t edgNum, double *alpha1, double *point, uint64_t *newTriNum, uint64_t *newEdgNum, double *alpha3)
{
  HXTEdges *edg=m_triEdges;
  for(int k=0; k<3; k++){
    point[k]=-1;
  }
  //edgNum is global edgNum where point P is located
  double  alpha2[1],  angleDirection1[1], direction[3], direction1[3], pointCoord[3];
  closestPointAngle(triNum, edgNum, coordP, *alpha1, angleDirection1);
  closestDirection(triNum, edgNum,  angleDirection1,  direction1);
  trialPoint(triNum, edgNum, coordP, direction1, pointCoord, newEdgNum, alpha2);
  double d1[3]={0.0};
  double d2[3]={0.0};
  for(int k=0; k<3; k++){
    d1[k] = pointCoord[k]-coordP[k];
    d2[k] = direction1[k];
  }
  double norm=0.0;
  for(int k=0; k<3; k++)
    norm+=d1[k]*d1[k];
  norm=sqrt(norm);
  for(int k=0; k<3; k++)
    d1[k]=d1[k]/norm;
  norm=0.0;
  for(int k=0; k<3; k++)
    norm+=d2[k]*d2[k];
  norm=sqrt(norm);
  for(int k=0; k<3; k++)
    d2[k]=d2[k]/norm;
  double scalarp = 0.0;
  for(int k=0; k<3; k++)
    scalarp += d1[k]*d2[k];

  if(scalarp<0){
    uint64_t nTriNum=edg->edg2tri[2*edgNum+0];
    if (nTriNum==triNum){
      nTriNum=edg->edg2tri[2*edgNum+1];  // do something if newtrinum is -1
    }
    triNum=nTriNum;
    trialPoint(triNum, edgNum, coordP, direction1, pointCoord, newEdgNum, alpha2);
  }
  *newTriNum=edg->edg2tri[2*edgNum+0];
  if (*newTriNum==triNum){
    *newTriNum=edg->edg2tri[2*edgNum+1];  
  }
  correction(pointCoord, *newTriNum, *newEdgNum, *alpha2, direction);
  trialPoint(triNum, edgNum, coordP, direction, point, newEdgNum, alpha3);
  for(int k=0; k<3; k++){
    d1[k] = point[k]-coordP[k];
    d2[k] = direction[k];
  }
  norm=0.0;
  for(int k=0; k<3; k++)
    norm+=d1[k]*d1[k];
  norm=sqrt(norm);
  for(int k=0; k<3; k++)
    d1[k]=d1[k]/norm;
  norm=0.0;
  for(int k=0; k<3; k++)
    norm+=d2[k]*d2[k];
  norm=sqrt(norm);
  for(int k=0; k<3; k++)
    d2[k]=d2[k]/norm;
  scalarp = 0.0;
  for(int k=0; k<3; k++)
    scalarp += d1[k]*d2[k];
  
  if(scalarp<0){
    uint64_t nTriNum=edg->edg2tri[2*edgNum+0];
    if (nTriNum==triNum){
      nTriNum=edg->edg2tri[2*edgNum+1];
    }
    triNum=nTriNum;
    trialPoint(triNum, edgNum, coordP, direction, point, newEdgNum, alpha3);
    *newTriNum=edg->edg2tri[2*edgNum+0];
    if (*newTriNum==triNum){
      *newTriNum=edg->edg2tri[2*edgNum+1];
    }
  }
  return 1;
}

HXTStatus QuadGenerator::propagateKowalski(int sepID){
  HXTEdges* edges=m_triEdges;
  Separatrice *sep=&(m_vectSep[sepID]);
  std::vector<double> angles=sep->getAngles();
  if(sep->getPCoord()->size()!=2){ 
    while(sep->getPCoord()->size()!=(angles.size()+1)){
      sep->getPCoord()->pop_back();
      sep->getPTriangles()->pop_back();
    }
  }                            
  std::vector<uint64_t> triangles=sep->getTriangles();
  std::vector<uint64_t> edgesS=sep->getEdges();
  std::vector<std::array<double,3>> points=sep->getCoord();
  int num=0;
  uint64_t newEdgNum[1], newTriNum[1];
  double newAngle[1], point2[3];
  double coordS[3]={0.}, point1[3]={0.};
  std::array<double,3> pointS=points[points.size()-2];
  std::array<double,3> pointP=points[points.size()-1];
  for(int i=0; i<3; i++){
    coordS[i]=pointS[i];
    point1[i]=pointP[i];
  }
  uint64_t oldTriNum=triangles[triangles.size()-1];
  uint64_t oldEdgNum=edgesS[edgesS.size()-1];
  double oldAngle[1];
  double a=angles[angles.size()-1];
  *oldAngle=a;
  int flag=0;
  int flagPropagationStarted=0;
  int numOutOfPatch=0;
  double pointOld[3]={0.0};
  for(int i=0;i<3;i++)
    pointOld[i]=coordS[i];
  while(flag==0 && edges->edg2tri[2*oldEdgNum+0]!=(uint64_t)-1 && edges->edg2tri[2*oldEdgNum+1]!=(uint64_t)-1 && num<20000){
    candidatePoint(point1, oldTriNum, oldEdgNum, oldAngle, point2, newTriNum,  newEdgNum, newAngle);
    std::array<double,3> patchPoint;
    int isInPatch=checkIfInPatch(*newTriNum, &patchPoint);
    if((!isInPatch)&&(!flagPropagationStarted)){
      numOutOfPatch++;
      if(numOutOfPatch>3)
	flagPropagationStarted=1;
    }
    //hit singular area!
    if((isInPatch)&&(flagPropagationStarted)){
      if(isPointCorner(&patchPoint)){
	sep->addTriangle(*newTriNum);
	sep->addPoint(patchPoint);
      }
      else{
	bool discard;
	linkSepToSing(sep,oldTriNum,oldEdgNum,patchPoint,&discard);
	if(discard){
	  addLastPatchInIgnoredPatchs(sepID);
	  propagateKowalski(sepID);
	  sep->Disable(); 
	}
      }
      flag=1;
      num++;
    }
    //
    if(flag==0){
      num++;
      oldTriNum=*newTriNum;
      sep->addTriangle(oldTriNum);
      oldEdgNum=*newEdgNum;
      sep->addEdge(oldEdgNum);
      *oldAngle=*newAngle;
      sep->addAngle(*oldAngle);
      std::array<double,3> endPoint={{0.0,0.0,0.0}};
      for(int k=0; k<3;k++){
	pointOld[k]=point1[k];
	point1[k]=point2[k];
	endPoint[k]=point1[k];
      }
      sep->addPoint(endPoint);
    }
  }
  if(edges->edg2tri[2*oldEdgNum+0]==(uint64_t)-1 || edges->edg2tri[2*oldEdgNum+1]==(uint64_t)-1 ){
    std::array<double,3> pointToTest = (*sep->getPCoord())[sep->getPCoord()->size()-1]; 
    int isCorner=isPointCorner(&pointToTest); 
    if(isCorner==0){//point is not a corner
      num++;
      std::array<double,3> endPoint={{-1.0,-1.0,-1.0}};
      sep->addPoint(endPoint);
      uint64_t endTri=(uint64_t)-1;
      sep->addTriangle(endTri);
      //push edg -1 too
      sep->setIsRemovable(1);
    }
  }   
  if(num>20000){
    std::cout<<"Num propagated elements: "<<num<<std::endl;
    std::cout<<"Check propagateKowalski, sepID: "<<sepID<<std::endl; 
  }

  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteSeparatricesPos(const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Separatrices\" {\n");
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved()){
      std::vector<std::array<double,3>> points=sep->getCoord();
      std::vector<uint64_t> triangles=sep->getTriangles();
      int color = i;
      for(uint64_t j=0;j<points.size()-2; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      int sizeTri=triangles.size();
      int sizePoints=points.size();
      uint64_t tri=triangles[sizeTri-1];
      if(tri!=(uint64_t)-1){
	std::array<double,3> point1=points[sizePoints-2];
	std::array<double,3> point2=points[points.size()-1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
      }
      else{
	std::array<double,3> point1=points[sizePoints-2];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
      }
    }
  }
  
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::buildIntersectionTriValues(){
  std::vector<std::array<int, 2>> init;
  init.reserve(10); //changable
  m_flaggedTri.assign(m_triMesh->triangles.num, init);

  std::array<int, 2> val;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&m_vectSep[i];
    std::vector<uint64_t> *triangles=sep->getPTriangles();
    for(uint64_t j=1; j<triangles->size()-1; j++){
      val[0]=(int)i; //sepID
      val[1]=j;      //position
      m_flaggedTri[(*triangles)[j]].push_back(val); 
    }
  }

  return HXT_STATUS_OK;
}

int QuadGenerator::findPatchID(uint64_t triNum, uint64_t *patchID){
  *patchID=(uint64_t)-1;
  std::vector<std::vector<uint64_t>> allPatches;
  
  //collecting all patches
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::vector<uint64_t> patch=s->getPatch();
    allPatches.push_back(patch);
  }
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::vector<uint64_t> patch=c->getPatch();
    allPatches.push_back(patch);
  }

  //finding patch in which triNum is
  for(uint64_t i=0; i<allPatches.size(); i++){
    std::vector<uint64_t> triangles=allPatches[i];
    for(uint64_t j=0; j<triangles.size(); j++){
      if(triNum==triangles[j])
	*patchID=i;
    }
  }
  return 1;
}

int QuadGenerator::groupingSep()
{
  uint64_t triangle1, triangle2;
  uint64_t num1=0, num2=0, *elements;
  HXT_CHECK(hxtMalloc(&elements, 2*(m_vectSep.size())*sizeof(uint64_t)));
  
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved()){
      std::vector<uint64_t> triangles=sep->getTriangles();
      triangle1=triangles[1];
      triangle2=triangles[triangles.size()-1];
      uint64_t patchID=(uint64_t)-1;
      findPatchID(triangle1, &patchID);
      num1=patchID;
      if(triangle2==(uint64_t)-1){
	num2=(uint64_t)-1;
      }
      else{
	findPatchID(triangle2, &patchID);
	num2=patchID;
      }
      uint64_t sepExtr[2]={num1, num2};
      qsort(sepExtr, 2, sizeof(uint64_t), comparator);
      elements[2*i+0]=sepExtr[0];
      elements[2*i+1]=sepExtr[1];
    }
  }
 
  int *flag;
  HXT_CHECK(hxtMalloc(&flag, (m_vectSep.size())*sizeof(int)));
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    if(m_vectSep[i].isSaved())
      flag[i]=0;
    else
      flag[i]=1;
  }
  
  int groupID=0;
  for(uint64_t i=0; i<(m_vectSep.size()-1); i++){
    if(flag[i]==0){
      int ID=groupID;
      std::vector<Separatrice*> vectSep;
      vectSep.push_back(&(m_vectSep[i]));
      flag[i]=1;
      for(uint64_t j=i+1; j<m_vectSep.size(); j++){
	if(flag[j]==0){
	  if(elements[2*i]==elements[2*j] && elements[2*i+1]==elements[2*j+1]){
	    vectSep.push_back(&(m_vectSep[j]));
	    flag[j]=1;
	  }
	}
      }
      //creating separatrice group
      SepGroup sg(ID, vectSep);
      m_vectGroups.push_back(sg);
      groupID++;
    }
  }
 
  HXT_CHECK(hxtFree(&flag));
  HXT_CHECK(hxtFree(&elements));
  
  return 1;
}

void QuadGenerator::buildTotalPatches(){
  m_totalElemPatches.reserve(1000);
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::vector<uint64_t> *patch=s->getPPatch();
    for(uint64_t j=0; j<patch->size(); j++){
      m_totalElemPatches.push_back((*patch)[j]);
    }
  }
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::vector<uint64_t> *patch=c->getPPatch();
    for(uint64_t j=0; j<patch->size(); j++){
      m_totalElemPatches.push_back((*patch)[j]);
    }
  }
  return;
}

int QuadGenerator::intersectionNodeForGraph(uint64_t triNum, double *point1, double *point2, double *point3, double *point4, double *newPoint, int *flag){

  *flag=0;
  //initiation in case intersection node is not found
  for(int i=0; i<3; i++){
    newPoint[i]=-1;
  }
  HXTEdges* edges=m_triEdges;
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t vTriNum[3] = {mesh->triangles.node[3*(triNum)+0],mesh->triangles.node[3*(triNum)+1],mesh->triangles.node[3*(triNum)+2]};
  double u[3]={0,0,0};
  double v[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(mesh,vTriNum,u,v,n);
  double alpha=-1.0, gamma=-1.0;
  double temp1[3], temp2[3], temp3[3], temp4[3], AB[3], AC[3], CA[3], CD[3];
  for(int i=0; i<3; i++){
    AB[i]=point2[i]-point1[i];
    AC[i]=point3[i]-point1[i];
    CA[i]=point1[i]-point3[i];
    CD[i]=point4[i]-point3[i];
  }
  crossprod(AC,CD,temp1);
  crossprod(AB,CD,temp2);
  if(myDot(temp2,n)!=0){
    alpha = myDot(temp1,n)/myDot(temp2,n);
  }
  crossprod(CA,AB,temp3);
  crossprod(CD,AB,temp4);
  if(myDot(temp4,n)!=0){
    gamma = myDot(temp3,n)/myDot(temp4,n);
  }
  if(alpha>-1e-9 && alpha<=1+1e-9 && gamma>-1e-9 && gamma<=1+1e-9){
    *flag=1;
    for(int i=0; i<3; i++){
      newPoint[i] = point1[i]+alpha*AB[i];
    }
  }
  return 1;
}

int QuadGenerator::localIntersection(int sepID1, int sepID2){
  int flag=0, nodeExist, position=-1;
  double point1[3]={0.}, point2[3]={0.}, point3[3]={0.}, point4[3]={0.}, newPoint[3]={0.};
  Separatrice *sep1=&(m_vectSep[sepID1]);
  Separatrice *sep2=&(m_vectSep[sepID2]);
  bool isBoundarySep=(sep1->isBoundary() || sep2->isBoundary());
  std::vector<std::array<double,3>> *pointsSep1= sep1->getPCoord();
  std::vector<std::array<double,3>> *pointsSep2= sep2->getPCoord();
  std::vector<uint64_t> *triangles1=sep1->getPTriangles();
  for(uint64_t i=2; i<triangles1->size()-1; i++){
    int isInPatch=checkIfInPatch2((*triangles1)[i]);
    int isInIgnoredPatch=m_vectSep[sepID1].isInIgnoredPatch((*triangles1)[i]);
    if((*triangles1)[i]!=(uint64_t)-1 && m_flaggedTri[(*triangles1)[i]].size()>1){
      std::vector<std::array<int, 2>> values=m_flaggedTri[(*triangles1)[i]];
      for(uint64_t j=0; j<values.size(); j++){
	if(values[j][0]==sepID2){
	  position=values[j][1];
	  if(!isInPatch || isBoundarySep || isInIgnoredPatch){
	    std::array<double,3> p1=(*pointsSep1)[i-1];
	    std::array<double,3> p2=(*pointsSep1)[i];
	    std::array<double,3> p3=(*pointsSep2)[position-1];
	    std::array<double,3> p4=(*pointsSep2)[position];
	    for(int k=0; k<3; k++){
	      point1[k]=p1[k]; point2[k]=p2[k]; point3[k]=p3[k]; point4[k]=p4[k];
	    }
	    intersectionNodeForGraph((*triangles1)[i], point1, point2, point3, point4, newPoint, &nodeExist);
	    if(nodeExist==1)
	      flag=1;
	    
	  }
	}
      }
    }
  }

  return flag;
}

int QuadGenerator::globalIntersection()
{
  buildTotalPatches();
  for(uint64_t i=0; i<m_vectGroups.size(); i++){
    SepGroup *sg=&(m_vectGroups[i]);
    std::vector<Separatrice*>* vectSep=sg->getPSeparatrices();
    for(uint64_t j=0; j<vectSep->size(); j++){
      Separatrice *sep1=(*vectSep)[j];
      int ID1=sep1->getID();
      for(uint64_t k=0; k<m_vectGroups.size(); k++){
	if(i!=k){
	  SepGroup *sgK=&(m_vectGroups[k]);
	  std::vector<Separatrice*>* vectSepK=sgK->getPSeparatrices();
	  for(uint64_t l=0; l<vectSepK->size(); l++){
	    int ID2=(vectSepK->at(l))->getID();
	    if(localIntersection(ID1, ID2)){
	      sep1->addIntersectingSepID(ID2);
	    }
	  }
	}
      }
      std::vector<int> *intersection=sep1->getPIntersection();
      uint64_t size=intersection->size();    
      uint64_t *intersectionSepID1;
      HXT_CHECK(hxtMalloc(&intersectionSepID1,size*sizeof(uint64_t)));
      for(uint64_t s=0; s<size; s++)
      	intersectionSepID1[s]=static_cast<uint64_t>((*intersection)[s]);
      int sizeInt=static_cast<int>(size);
      qsort(intersectionSepID1, sizeInt, sizeof(uint64_t), comparator);
      for(uint64_t s=0; s<size; s++)
      	(*intersection)[s]=static_cast<int>(intersectionSepID1[s]);
      HXT_CHECK(hxtFree(&intersectionSepID1));
    }
  }
  return 1;
}

int QuadGenerator::comparison(){
  int flag=0;
  int *flaggedSep;
  HXT_CHECK(hxtMalloc(&flaggedSep,m_vectSep.size()*sizeof(int)));
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    flaggedSep[i]=1;
  }
  for(uint64_t i=0; i<m_vectGroups.size(); i++){
    SepGroup *sg=&(m_vectGroups[i]);
    std::vector<Separatrice*>* vectSep=sg->getPSeparatrices();
    for(uint64_t j=0;j<vectSep->size()-1; j++){
      Separatrice *sep1=(*vectSep)[j];
      int ID1=sep1->getID();
      if(flaggedSep[ID1]==1){
	for(uint64_t k=j+1; k<vectSep->size(); k++){
	  Separatrice *sep2=(*vectSep)[k];
	  int ID2=sep2->getID();
	  std::vector<int> *intersectionSep1=sep1->getPIntersection();
	  std::vector<int> *intersectionSep2=sep2->getPIntersection(); 
	  flag=0;
	  if(intersectionSep1->size()==intersectionSep2->size()){
	    flag=1;
	    for(uint64_t l=0; l<intersectionSep1->size(); l++){
	      if((*intersectionSep1)[l]!=(*intersectionSep2)[l])
	    	flag=0;
	    }
	  }
	  if(flag==1){
	    flaggedSep[ID2]=0;
	  }
       	}
      }
    }
  }

  //disabling separatrices which are copies of existing separatrices
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    int ID=sep->getID();   
    if(flaggedSep[ID]==0)
      sep->Disable(); 
  }
    
  HXT_CHECK(hxtFree(&flaggedSep));
  return 1;
}

int QuadGenerator::checkIfInPatch2(uint64_t triNum){
  int isInPatch=0;
  for(uint64_t i=0; i<m_totalElemPatches.size(); i++){
    if(triNum==m_totalElemPatches[i])
	isInPatch=1;
  }
  return isInPatch;
}

int QuadGenerator::detectLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs){
  double point1[3], point2[3], point3[3], point4[3], newPoint[3];
  for(int i=0; i<3; i++){
    point1[i]=0.; point2[i]=0.; point3[i]=0.; point4[i]=0.; newPoint[i]=0.;
  }
  int nodeExist=0, position=-1;

  std::vector<std::vector<std::array<int,3>>> allSepIntersections; //intersecting sepID, num intersections, max intersection distance
  std::vector<uint64_t> candidates;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep1=&m_vectSep[i];
    std::vector<std::array<int,3>> repetitions; //intersecting sepID, num intersections, max intersection distance
    std::array<int,3> val;
    std::vector<int> intersectionPosition;
    for(uint64_t j=0; j<m_vectSep.size(); j++){
      if(i!=j){
	Separatrice *sep2=&m_vectSep[j];
	int isSaved=(sep1->isSaved() && sep2->isSaved());
	int isBoundarySep=sep1->isBoundary();
	if(isSaved && !isBoundarySep){
	  int numIntersections=0;
	  std::vector<std::array<double,3>> *pointsSep1= sep1->getPCoord();
	  std::vector<std::array<double,3>> *pointsSep2= sep2->getPCoord();
	  std::vector<uint64_t> *triangles1=sep1->getPTriangles();
	  for(uint64_t k=2; k<triangles1->size()-1; k++){
	    int isInPatch=checkIfInPatch2((*triangles1)[k]);
	    int isInIgnoredPatch=m_vectSep[sep1->getID()].isInIgnoredPatch((*triangles1)[k]);
	    if((*triangles1)[k]!=(uint64_t)-1 && m_flaggedTri[(*triangles1)[k]].size()>1){
	      std::vector<std::array<int, 2>> values=m_flaggedTri[(*triangles1)[k]];
	      for(uint64_t t=0; t<values.size(); t++){
		if(values[t][0]==sep2->getID()){
		  position=values[t][1];
		  if(!isInPatch || isBoundarySep || isInIgnoredPatch){
		    std::array<double,3> p1=(*pointsSep1)[k-1];
		    std::array<double,3> p2=(*pointsSep1)[k];
		    std::array<double,3> p3=(*pointsSep2)[position-1];
		    std::array<double,3> p4=(*pointsSep2)[position];
		    for(int s=0; s<3; s++){
		      point1[s]=p1[s]; point2[s]=p2[s]; point3[s]=p3[s]; point4[s]=p4[s];
		    }
		    intersectionNodeForGraph((*triangles1)[k], point1, point2, point3, point4, newPoint, &nodeExist);
		    if(nodeExist==1){
		      numIntersections++;
		      intersectionPosition.push_back(k);
		    }
		  }
		}
	      }    
	    }
	  }
	  if(numIntersections>1){ 
	    val[0]=sep2->getID();
	    val[1]=numIntersections;
	    val[2]=intersectionPosition[intersectionPosition.size()-1]-intersectionPosition[0];
	    repetitions.push_back(val);
	  }
	}
      }
    }
    if(repetitions.size()>0){
      candidates.push_back(sep1->getID());
      allSepIntersections.push_back(repetitions);
    }
  }

  std::vector<int> flag;
  for(uint64_t i=0; i<candidates.size(); i++)
    flag.push_back(0);
  double min=-1.0;
  for(uint64_t i=0; i<candidates.size(); i++){
    if(flag[i]==0){
      for(uint64_t j=0; j<allSepIntersections[i].size(); j++){ //intersecting sepID, num intersections, max intersection distance
	min=allSepIntersections[i][j][2];
	for(uint64_t k=0; k<candidates.size(); k++){
	  if(i!=k && flag[k]==0 && (uint64_t)allSepIntersections[i][j][0]==candidates[k]){
	    for(uint64_t t=0; t<allSepIntersections[k].size(); t++){
	      if((uint64_t)allSepIntersections[k][t][0]==candidates[i]){
		if(min>allSepIntersections[k][t][2])
		  flag[i]=1;
		else
		  flag[k]=1;
	      }
	    }
	  }
	}
      }
    }
  }

  for(uint64_t i=0; i<flag.size(); i++)
    if(flag[i]==1)
      limitCycleIDs->push_back(candidates[i]);
  
  return 1;
}

int QuadGenerator::cutLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs)
{
  double point1[3], point2[3], point3[3], point4[3], newPoint[3];
  for(int i=0; i<3; i++){
    point1[i]=0.; point2[i]=0.; point3[i]=0.; point4[i]=0.; newPoint[i]=0.;
  }
  int nodeExist=0, position=-1;
  
  for(uint64_t i=0; i<limitCycleIDs->size(); i++){
    Separatrice *sep=&(m_vectSep[(*limitCycleIDs)[i]]);
    int lastIntersectionPosition=0;
    std::array<double,3> lastIntersectionPoint;
    uint64_t lastIntersectionTriangle=(uint64_t)-1;
    std::vector<std::array<double,3>> *points1= sep->getPCoord();
    std::vector<uint64_t> *triangles= sep->getPTriangles();
    for(uint64_t j=triangles->size()-2; j>1; j--){   
      if((*triangles)[j]!=(uint64_t)-1 && m_flaggedTri[(*triangles)[j]].size()>1){
	std::vector<std::array<int, 2>> values=m_flaggedTri[(*triangles)[j]];
	for(uint64_t t=0; t<values.size(); t++){
	  Separatrice *sep2=&(m_vectSep[values[t][0]]);
	  if(sep2->isSaved()){
	    std::vector<std::array<double,3>> *points2= sep2->getPCoord();
	    position=values[t][1];
	    std::array<double,3> p1=(*points1)[j-1];
	    std::array<double,3> p2=(*points1)[j];
	    std::array<double,3> p3=(*points2)[position-1];
	    std::array<double,3> p4=(*points2)[position];
	    for(int s=0; s<3; s++){
	      point1[s]=p1[s]; point2[s]=p2[s]; point3[s]=p3[s]; point4[s]=p4[s];
	    }
	    intersectionNodeForGraph((*triangles)[j], point1, point2, point3, point4, newPoint, &nodeExist);
	    if(nodeExist==1){
	      lastIntersectionPosition=j;
	      lastIntersectionTriangle=(*triangles)[j];
	      for(int m=0; m<3; m++)
		lastIntersectionPoint[m]=newPoint[m];
	    }
	  }
	}   
      }
    }
    for(uint64_t j=triangles->size(); j>(uint64_t)lastIntersectionPosition; j--){
      sep->getPCoord()->pop_back();
      sep->getPTriangles()->pop_back();
    }
    sep->getPCoord()->push_back(lastIntersectionPoint);
    sep->getPTriangles()->push_back(lastIntersectionTriangle);
  }

  return 1;
}

// glue, make new Sep and discard other two sep
int QuadGenerator::solveTangentialCrossings(std::vector<uint64_t> *limitCycleIDs){
  if((*limitCycleIDs).size()>1){
    for(uint64_t i=0; i<limitCycleIDs->size(); i++){
      Separatrice *sep1=&(m_vectSep[(*limitCycleIDs)[i]]);
      for(uint64_t j=0; j<limitCycleIDs->size(); j++){
	Separatrice *sep2=&(m_vectSep[(*limitCycleIDs)[j]]);
	if((*limitCycleIDs)[i]!=(*limitCycleIDs)[j] && sep1->isSaved() && sep2->isSaved()){
	  std::vector<std::array<double,3>> *points1 = sep1->getPCoord();
	  std::vector<std::array<double,3>> *points2 = sep2->getPCoord();
	  double lastPoint1[3], lastPoint2[3];
	  for(int t=0; t<3; t++){
	    lastPoint1[t]=(*points1)[(*points1).size()-1][t];
	    lastPoint2[t]=(*points2)[(*points2).size()-1][t];
	  }
	  double norm;
	  if(isPointDuplicate(lastPoint1, lastPoint2, &norm)){
	    std::cout<<"Tangential crosssing!!!"<<"Separatrices: "<<(*limitCycleIDs)[i]<<" and "<<(*limitCycleIDs)[j]<<std::endl;
	    std::vector<uint64_t> edges1 = sep1->getEdges();
	    std::vector<uint64_t> *triangles1 = sep1->getPTriangles();
	    std::vector<double> enteringAngles1 = sep1->getAngles();
	    std::vector<uint64_t> edges2 = sep2->getEdges();
	    std::vector<uint64_t> *triangles2 = sep2->getPTriangles();
	    std::vector<double> enteringAngles2 = sep2->getAngles();
	    int ID=m_vectSep.size();
	    std::vector<std::array<double,3>> nodesCoord;
	    std::vector<uint64_t> triangles;
	    std::vector<uint64_t> edges;
	    std::vector<double> enteringAngles;
	    for(uint64_t k=0; k<(*points1).size()-1; k++){ 
	      nodesCoord.push_back((*points1)[k]);
	      triangles.push_back((*triangles1)[k]);
	      edges.push_back(edges1[k]);
	      enteringAngles.push_back(enteringAngles1[k]);
	    }
	    for(uint64_t k=(*points2).size()-2; k>0; k--){
	      nodesCoord.push_back((*points2)[k]);
	      triangles.push_back((*triangles2)[k+1]); //we are traversing: tri and then node -> here is viceversa because of the direction!
	      edges.push_back(edges2[k]);
	      enteringAngles.push_back(enteringAngles2[k]);
	    }
	    nodesCoord.push_back((*points2)[0]);
	    triangles.push_back((*triangles2)[0+1]);
	    Separatrice newSep = Separatrice(ID, nodesCoord, triangles, edges, enteringAngles);
	    m_vectSep.push_back(newSep);
	    sep1->Disable();
	    sep2->Disable();
	  }
	}
      }
    }
  }
  return 1;
}

HXTStatus QuadGenerator::hxtWriteLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs, const char *fileName){
  int num=0;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Limit cycles\" {\n");
  for(uint64_t i=0; i<limitCycleIDs->size(); i++){
    Separatrice *sep=&m_vectSep[(*limitCycleIDs)[i]];
    int color= num;
    if(sep->isSaved()){
      std::vector<std::array<double,3>> points=sep->getCoord();
      std::vector<uint64_t> triangles=sep->getTriangles();
      for(uint64_t j=0;j<points.size()-3; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      for(uint64_t j=points.size()-3;j<points.size()-2; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      int sizeTri=triangles.size();
      int sizePoints=points.size();
      uint64_t tri=triangles[sizeTri-1];
      if(tri!=(uint64_t)-1){
	std::array<double,3> point1=points[sizePoints-2];
	std::array<double,3> point2=points[points.size()-1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);

      }
      else{
	std::array<double,3> point1=points[sizePoints-2];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], 1);
      }
      num++;
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteSavedSeparatrices(const char *fileName){
  int num=0;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \" Saved separatrices\" {\n");
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    int color= num;
    if(sep->isSaved()){
      std::vector<std::array<double,3>> points=sep->getCoord();
      std::vector<uint64_t> triangles=sep->getTriangles();
      for(uint64_t j=0;j<points.size()-3; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      for(uint64_t j=points.size()-3;j<points.size()-2; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      int sizeTri=triangles.size();
      int sizePoints=points.size();
      uint64_t tri=triangles[sizeTri-1];
      if(tri!=(uint64_t)-1){
	std::array<double,3> point1=points[sizePoints-2];
	std::array<double,3> point2=points[points.size()-1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);

      }
      else{
	std::array<double,3> point1=points[sizePoints-2];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], 1);
      }
      num++;
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus QuadGenerator::hxtWriteEverything(const char *fileName){

  HXTEdges *edges=m_triEdges;
  HXTMesh *mesh=edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Separatrices\" {\n");
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    std::vector<std::array<double,3>> points=sep->getCoord();
    std::vector<uint64_t> triangles=sep->getTriangles();
    int color = i;
    for(uint64_t j=0;j<points.size()-2; j++){
      std::array<double,3> point1=points[j];
      std::array<double,3> point2=points[j+1];
      fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
    }
    int sizeTri=triangles.size();
    int sizePoints=points.size();
    uint64_t tri=triangles[sizeTri-1];
    if(tri!=(uint64_t)-1){
      std::array<double,3> point1=points[sizePoints-2];
      std::array<double,3> point2=points[points.size()-1];
      fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
    }
    else{
      std::array<double,3> point1=points[sizePoints-2];
      fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
    }
  }
  fprintf(f,"};");
  
  fprintf(f,"View \"Saved separatrices\" {\n");
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved()){
      std::vector<std::array<double,3>> points=sep->getCoord();
      std::vector<uint64_t> triangles=sep->getTriangles();
      int color = i;
      for(uint64_t j=0;j<points.size()-2; j++){
	std::array<double,3> point1=points[j];
	std::array<double,3> point2=points[j+1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
      }
      int sizeTri=triangles.size();
      int sizePoints=points.size();
      uint64_t tri=triangles[sizeTri-1];
      if(tri!=(uint64_t)-1){
	std::array<double,3> point1=points[sizePoints-2];
	std::array<double,3> point2=points[points.size()-1];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], color,color);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], color);
      }
      else{
	std::array<double,3> point1=points[sizePoints-2];
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], color);
      }
    }
  }
  fprintf(f,"};");
  fprintf(f,"View \"Singularities\" {\n");
  for(uint32_t i=0; i<m_vectSing.size(); i++){
    int color=i;
    Singularity *s=&(m_vectSing[i]);
    std::array<double,3> coord=s->getCoord();
    fprintf(f,"SP(%g,%g,%g){%i};\n", coord[0], coord[1], coord[2], color);
  }
  for(uint32_t i=0; i<m_vectCorner.size(); i++){
    int color=i;
    Corner *c=&(m_vectCorner[i]);
    std::array<double,3> coord=c->getCoord();
    fprintf(f,"SP(%g,%g,%g){%i};\n", coord[0], coord[1], coord[2], color);
  }
  fprintf(f,"};");

  uint64_t *elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    elemFlagged[i]=0;
  for(uint32_t k=0; k<m_vectSing.size(); k++){
    Singularity *s=&(m_vectSing[k]);
    std::vector<uint64_t> patch=s->getPatch();
    for(uint32_t j=0; j<patch.size(); j++){
      uint64_t tri=patch[j];
      elemFlagged[tri]=1;
    }
  }
  
  fprintf(f,"View \"Flagged patches\"{\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(f,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    for(uint32_t j=0; j<3; j++){
      fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(f,",");
    }
    fprintf(f,")");
    fprintf(f,"{");
    fprintf(f,"%lX, %lX, %lX",elemFlagged[i],elemFlagged[i],elemFlagged[i]);
    fprintf(f,"};\n");    
  }
  fprintf(f,"};");
  fclose(f);
  
  HXT_CHECK(hxtFree(&elemFlagged));
  return HXT_STATUS_OK;
}

//-----------------------------------------------------------------------------

//3. create split mesh on MB decomposition

HXTStatus QuadGenerator::splitTriMeshOnMBDecomp()
{
  if(m_mBlock)
    m_mBlock->splitTriMeshOnMBDecomp();
  else{
    m_mBlock = new MultiBlock(m_triEdges, m_vectSep, m_vectSing, m_vectCorner);
    m_mBlock->splitTriMeshOnMBDecomp();
  }
  return HXT_STATUS_OK;
}

HXTMesh* QuadGenerator::getSplitTriMeshOnMBDecomp()
{
  if(m_mBlock)
    return m_mBlock->getMyTriMesh();
  else{
    std::cout << "No multiblock Houston" << std::endl;
    return NULL;
  }
}
