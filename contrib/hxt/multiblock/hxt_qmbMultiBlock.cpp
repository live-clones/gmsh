#include "hxt_qmbMultiBlock.h"
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_linear_system.h"
// #include "hxt_linear_system_lu.h"
}
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>



HXTStatus hxtDet3x3(double mat[3][3], double *det)
{
  *det = (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
          mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
          mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
  return HXT_STATUS_OK;
}

HXTStatus hxtInv3x3(double mat[3][3], double inv[3][3], double *det)
{
  HXT_CHECK(hxtDet3x3(mat, det));
  if(*det){
    double ud = 1. / *det;
    inv[0][0] =  (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] =  (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] =  (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] =  (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] =  (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
    return HXT_STATUS_OK;
  }
  else{
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        inv[i][j] = 0.;
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Singular matrix 3x3");
  }
}

HXTStatus hxtNorm2V3(double v[3], double* norm2){
  *norm2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  return HXT_STATUS_OK;
}

MultiBlock:: MultiBlock(HXTEdges *edges, std::vector<Separatrice> vectSep, std::vector<Singularity> vectSing, std::vector<Corner> vectCorner, double *crossfield, double *scalingFactorCrosses)
{
  m_Edges=edges;
  m_vectSep=vectSep;
  m_vectSing=vectSing;
  m_vectCorner=vectCorner; 
  m_myTriMesh=NULL;

  m_quadMesh=NULL; 

  m_crossfield=crossfield;
  m_scalingFactorCrosses=scalingFactorCrosses;
  std::vector<uint64_t> initVect;
  m_vertToTri.resize(m_Edges->edg2mesh->vertices.num,initVect);
  for(size_t k=0;k<m_Edges->edg2mesh->triangles.num;k++){
    for(size_t l=0;l<3;l++)
      m_vertToTri[m_Edges->edg2mesh->triangles.node[3*k+l]].push_back(k);
  }

}

MultiBlock::~MultiBlock()
{
  // if(m_myTriMesh)
  //   hxtMeshDelete(&m_myTriMesh);
  // if(m_quadMesh)
  //   hxtMeshDelete(&m_quadMesh);
}

static void normalize(double *d)
{
  double n = sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
  d[0]/=n;
  d[1]/=n;
  d[2]/=n;
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

static inline HXTStatus trianglebasis(HXTMesh *m, uint32_t *vtri, double *U, double *V, double *n)
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

static inline int comparatorDouble(const void *p1, const void *p2)
{
  double *e0 = (double*)p1;
  double *e1 = (double*)p2;
  int returnValue=0;
  if(*(e0)-*(e1)<0)
    returnValue=-1;
  if(*(e0)-*(e1)>0)
    returnValue=1;
  return returnValue;
}

static inline int isPointDuplicate(double *point1, double *point2, double *norm){
  double a=point1[0]-point2[0];
  double b=point1[1]-point2[1];
  double c=point1[2]-point2[2];
  *norm=sqrt(a*a+b*b+c*c);
  //if(*norm<=1e-6)
  if(*norm<=1.e-10)
    return 1;
  else
    return 0;
}

static inline int isPointDuplicateVec(std::array<double,3> *point1, std::array<double,3> *point2, double *norm){
  double a=(*point1)[0]-(*point2)[0];
  double b=(*point1)[1]-(*point2)[1];
  double c=(*point1)[2]-(*point2)[2];
  *norm=sqrt(a*a+b*b+c*c);
  // if(*norm<abs(1e-6))
  if(*norm<=1.e-10)
    return 1;
  else
    return 0;
}

int MultiBlock::addInPointsVectIfNotPresent(std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind){
  int flag=1;
  int indFound=-1;
  for(uint64_t i=0;i<vect->size();i++){
    double norm=0.0;
    if(isPointDuplicateVec(&((*vect)[i]),&point,&norm)){
      flag=0;
      indFound=i;
    }
  }
  if(flag){
    vect->push_back(point);
    *ind = vect->size()-1;
    return 1;
  }
  else{
    *ind=indFound;
    return 0;
  }

}

int MultiBlock::addInPointsVectIfNotPresent2(std::vector<std::array<double,3>> *vect, std::array<double,3> point){
  int flag=1;
  for(uint64_t i=0;i<vect->size();i++){
    double norm=0.0;
    if(isPointDuplicateVec(&((*vect)[i]),&point,&norm))
      flag=0;
  }
  if(flag){
    vect->push_back(point);
    return 1;
  }
  else{
    return 0;
  }
}

int MultiBlock::addInPointsVectIfNotPresentCustomized(uint64_t begin,std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind){
  int flag=1;
  int indFound=-1;
  for(uint64_t i=begin;i<vect->size();i++){
    double norm=0.0;
    if(isPointDuplicateVec(&((*vect)[i]),&point,&norm)){
      flag=0;
      indFound=i;
    }
  }
  if(flag){
    vect->push_back(point);
    *ind = vect->size()-1;
    return 1;
  }
  else{
    *ind=indFound;
    return 0;
  }
}

HXTStatus MultiBlock::addInIntVectIfNotPresent(std::vector<int> *vect, int value){
  if(vect->size()==0)
    vect->push_back(value);
  else
    if(std::find(vect->begin(), vect->end(), value) == vect->end())
      vect->push_back(value);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::addInUnsgnIntVectIfNotPresent(std::vector<uint64_t> *vect, uint64_t value){
  if(std::find(vect->begin(), vect->end(), value) == vect->end())
    vect->push_back(value);
  return HXT_STATUS_OK;
}

static bool sortDouble(double u, double v)
{
  return u < v;
}

static inline int getLength(std::array<double,3> point1, std::array<double,3> point2, double *length){
  double a=point1[0]-point2[0];
  double b=point1[1]-point2[1];
  double c=point1[2]-point2[2];
  *length=sqrt(a*a+b*b+c*c); 

  return 1;
}

HXTStatus MultiBlock::splitTriMeshOnMBDecomp(){
  // std::cout << "----SPLITTING TRI MESH ON MULTI-BLOCK DECOMPOSITION----" << std::endl;
  // std::vector<int> flag;
  // std::vector<std::vector<int>> cSep;
  // std::vector<std::vector<uint64_t>> cEdg;
  // std::vector<std::vector<std::array<double,3>>> cCoord;
  // std::cout << "--Flagging triangles--" << std::endl;
  // flagTriangles(&flag, &cSep, &cEdg, &cCoord);
  // std::cout << "--Writing triangles and nodes--" << std::endl;
  // // hxtWriteFlaggedTriangles(flag, "flaggedTri.pos");
  // std::cout<<"--Writing nodes--"<<std::endl;
  // hxtWriteFlaggedNodes(cCoord, "flaggedNodes.pos");
  // std::vector<std::array<double,3>> coordOfEachVertex;
  // std::vector<std::array<double,3>> allMeshNodes;
  // std::vector<std::array<int,3>> allMeshTri;
  // std::vector<std::array<int,2>> allMeshLines;
  // std::vector<int> allMeshLinesColors;
  // std::cout << "--Creating new triangles--" << std::endl;   
  // createNewTriangles(flag, cSep, cCoord, &allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  // std::cout << "--Writing nodes of new triangles--" << std::endl;
  // hxtWriteTriVert(allMeshNodes, "meshNodes.pos" );
  // std::cout << "--Creating mesh--" << std::endl;
  // createMyTriMesh(&allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  // std::cout << "----SPLITTING TRI MESH ON MULTI-BLOCK DECOMPOSITION FINISHED----" << std::endl;

  std::cout<<"Create quad layout"<<std::endl;
  buildQuadLayout(); //new

  std::cout<<"------------Start meshing----------"<<std::endl;
  std::vector<double> hVal;
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  for(uint64_t v=0; v<mesh->vertices.num; v++) 
    hVal.push_back(1.0);
  for(uint64_t t=0; t<mesh->triangles.num; t++)
    for(size_t k=0;k<3;k++)
      hVal[mesh->triangles.node[3*t+k]]=exp(-m_scalingFactorCrosses[3*t+k]);
  
  meshQuadLayout(hVal);
  std::cout<<"Storing quad mesh"<<std::endl;
  createQuadMesh();
  
  std::cout<<"----Meshing  FINISHED!----"<<std::endl;
   
  return HXT_STATUS_OK;
}

int MultiBlock::intersectionNodeForGraph2(uint64_t triNum, double *point1, double *point2, double *point3, double *point4, double *newPoint, int *flag){

  *flag=0;
  //initiation in case intersection node is not found
  for(int i=0; i<3; i++){
    newPoint[i]=-1;
  }
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  uint32_t vTriNum[3] = {mesh->triangles.node[3*(triNum)+0],mesh->triangles.node[3*(triNum)+1],mesh->triangles.node[3*(triNum)+2]};
  double u[3]={0,0,0};
  double v[3]={0,0,0};
  double n[3]={0,0,0};
  trianglebasis(mesh,vTriNum,u,v,n);
  //-----------------------------------------------------------
  // double normal[3]={0,0,0};
  // if(getTriSingNormal(triNum, normal)){
  //   for(int mp=0; mp<3; mp++)
  //     n[mp]=normal[mp];
  // }
  //----------------------------------------------------------------
  
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
  if(alpha>-1.e-7 && alpha<=1.+1.e-7 && gamma>-1.e-7 && gamma<=1.+1.e-7){
  //if(alpha>-1.e-3 && alpha<=1.+1.e-3 && gamma>-1.e-3 && gamma<=1.+1.e-3){ //DBG
    *flag=1;
    for(int i=0; i<3; i++){
      newPoint[i] = point1[i]+alpha*AB[i];
    }
  }
  return 1;
}

int MultiBlock::mark(int *flaggedNodes, int size){
  int indicator=1;
  for(int i=1; i<size; i++){
    if(flaggedNodes[i]==0)
      indicator=0;
  }
  return indicator;
} 

int MultiBlock::defineQuads(std::vector<std::vector<int>> graphConnectedNodes, int *quadsWithIndices, int *offset, int *numOffsets, int *sizesQuads, int *numQuads){
  
  int **nodeFlagged;
  HXT_CHECK(hxtMalloc(&(nodeFlagged), (graphConnectedNodes.size())*sizeof(int*)));
  for(int i=0; i<graphConnectedNodes.size(); i++){
    int *temp;
    // HXT_CHECK(hxtMalloc(&(temp), graphConnectedNodes[i].size()*sizeof(int)));
    HXT_CHECK(hxtMalloc(&(temp), 100000*sizeof(int)));
    for(int j=0; j<100; j++){
      temp[j]=0;
    }
    nodeFlagged[i]=temp;
  }
  int from=0;
  int found=0;
  int num=0;
  *numQuads=0;
  for(int k=0; k<graphConnectedNodes.size(); k++){
    std::vector<int> connectedNodes=graphConnectedNodes[k];
    for(int t=1; t<graphConnectedNodes[k].size(); t++){
      if(mark(nodeFlagged[k], graphConnectedNodes[k].size())){
      	*(nodeFlagged[k]+0)=1;
      }
      //taking the node ?
      if(*(nodeFlagged[k]+0)==0){
	if(*(nodeFlagged[k]+t)==0){
	  int count=0;
	  int first=0;
	  from=connectedNodes[0];
	  quadsWithIndices[num]=from;
	  // std::cin;//ALEX
	  num++;
	  count++;
	  found=connectedNodes[t];
	  quadsWithIndices[num]=found;
	  // std::cin;//ALEX
	  num++;
	  count++;
	  *(nodeFlagged[k]+t)=1;
	  first=from;
	  while(first!=found){
	    for(int i=0; i<graphConnectedNodes.size(); i++){
	      std::vector<int> connectedNodesI=graphConnectedNodes[i];
	      if(connectedNodesI[0]==found){
		int length=graphConnectedNodes[i].size();
		for(int j=1; j<length; j++){
		  if(connectedNodesI[j]==from){
		    if(j==1){
		      from=found;
		      if(*(nodeFlagged[i]+(length-1))==0){
			found=connectedNodesI[length-1];
			quadsWithIndices[num]=found;
			// std::cin;//ALEX
			num++;
			count++;
			*(nodeFlagged[i]+(length-1))=1;
		      }
		    } else{
		      from=found;
		      if(*(nodeFlagged[i]+(j-1))==0){
			found=connectedNodesI[j-1];
			quadsWithIndices[num]=found;
			// std::cin;//ALEX
			num++;
			count++;
			*(nodeFlagged[i]+(j-1))=1;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	  sizesQuads[*numQuads]=count;
	  *numQuads=*numQuads+1;
	}
      }
    }
  }
  for(int i=0; i<graphConnectedNodes.size(); i++){
    int *temp;
    temp=nodeFlagged[i];
    HXT_CHECK(hxtFree(&temp));
  }
  HXT_CHECK(hxtFree(&nodeFlagged));

  return 1;
}

int MultiBlock::getGlobalEdg(uint64_t triNum, std::array<double,3> point, uint64_t *edgNum){
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  double vtri[3*3] = {vert[4*nodes[3*triNum+0]+0],vert[4*nodes[3*triNum+0]+1],vert[4*nodes[3*triNum+0]+2],
                      vert[4*nodes[3*triNum+1]+0],vert[4*nodes[3*triNum+1]+1],vert[4*nodes[3*triNum+1]+2],
                      vert[4*nodes[3*triNum+2]+0],vert[4*nodes[3*triNum+2]+1],vert[4*nodes[3*triNum+2]+2]};
  double AB[3]={vtri[3]-vtri[0], vtri[4]-vtri[1], vtri[5]-vtri[2]};
  double BC[3]={vtri[6]-vtri[3], vtri[7]-vtri[4], vtri[8]-vtri[5]};
  double AC[3]={vtri[6]-vtri[0], vtri[7]-vtri[1], vtri[8]-vtri[2]};
  double AP[3]={point[0]-vtri[0], point[1]-vtri[1], point[2]-vtri[2]};
  double BP[3]={point[0]-vtri[3], point[1]-vtri[4], point[2]-vtri[5]};
  double n[3]={0.,0.,0.};

  crossprod(AB,AP,n);
  if(fabs(n[0])<1.e-7 && fabs(n[1])<1.e-7 && fabs(n[2])<1.e-7){
    // if(fabs(n[0])<=1.e-3 && fabs(n[1])<=1.e-3 && fabs(n[2])<=1.e-3){ //DBG
    *edgNum=edges->tri2edg[3*triNum+0];
  }else{
    crossprod(BC,BP,n);
    if(fabs(n[0])<1e-7 && fabs(n[1])<1e-7 && fabs(n[2])<1e-7){
      //if(fabs(n[0])<=1e-3 && fabs(n[1])<=1e-3 && fabs(n[2])<=1e-3){ //DBG
      *edgNum=edges->tri2edg[3*triNum+1];
    }
    else{
      crossprod(AC,AP,n);
      if(fabs(n[0])<=1e-7 && fabs(n[1])<=1e-7 && fabs(n[2])<=1e-7){
	//if(fabs(n[0])<=1e-3 && fabs(n[1])<=1e-3 && fabs(n[2])<=1e-3){ //DBG
  	*edgNum=edges->tri2edg[3*triNum+2];
      }
      else{
	*edgNum=(uint64_t)(-1);
      }
    }
  }
  return 1;
}

int MultiBlock::flagTriangles(std::vector<int> *flag, std::vector<std::vector<int>> *cSep, std::vector<std::vector<uint64_t>> *cEdg, std::vector<std::vector<std::array<double,3>>> *cCoord){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    (*flag).push_back(0);

  int globIndex;
  uint64_t e1,e2;
  std::vector<int> init1;
  std::vector<std::vector<int>> cutSep(mesh->triangles.num, init1);
  std::vector<uint64_t> init2;
  std::vector<std::vector<uint64_t>> cutEdg(mesh->triangles.num, init2);
  std::vector<std::array<double,3>> pCoord; 
  std::vector<std::vector<std::array<double,3>>> cutPoint(mesh->triangles.num, pCoord); 
  
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    for(uint64_t j=0; j<m_vectSep.size(); j++){
      Separatrice *s=&(m_vectSep[j]);
      std::vector<uint64_t> tri=s->getTriangles();
      std::vector<std::array<double,3>> coord=s->getCoord();
      int ID=s->getID();
      if((s->isSaved()) && (s->isBoundary())){ //boundary sep
	for(uint64_t k=1; k<tri.size(); k++){
	  if(i==tri[k]){
	    if((*flag)[i]==0){
	      (*flag)[i]=1;
	      getGlobalEdg(i, coord[k-1], &e1);
	      getGlobalEdg(i, coord[k], &e2);
	      cutEdg[i].push_back(e1);
	      cutEdg[i].push_back(e2);
	      cutPoint[i].push_back(coord[k-1]);
	      cutPoint[i].push_back(coord[k]);
	      cutSep[i].push_back(ID);
	    }
	    else{
	      (*flag)[i]=3;
	      getGlobalEdg(i, coord[k-1], &e1);
	      getGlobalEdg(i, coord[k], &e2);
	      cutEdg[i].push_back(e1);
	      cutEdg[i].push_back(e2);
	      cutPoint[i].push_back(coord[k-1]);
	      cutPoint[i].push_back(coord[k]);
	      cutSep[i].push_back(ID);
	    }
	  }
	}
      }
      if((s->isSaved()) && !(s->isBoundary())){ //normal sep
	for(uint64_t k=1; k<tri.size()-1; k++){
	  if(i==tri[k]){
	    if((*flag)[i]==0){
	      (*flag)[i]=1;
	      getGlobalEdg(i, coord[k-1], &e1);
	      getGlobalEdg(i, coord[k], &e2);
	      cutEdg[i].push_back(e1);
	      cutEdg[i].push_back(e2);
	      cutPoint[i].push_back(coord[k-1]);
	      cutPoint[i].push_back(coord[k]);
	      cutSep[i].push_back(ID);
	    }
	    else{
	      (*flag)[i]=3;
	      getGlobalEdg(i, coord[k-1], &e1);
	      getGlobalEdg(i, coord[k], &e2);
	      cutEdg[i].push_back(e1);
	      cutEdg[i].push_back(e2);
	      cutPoint[i].push_back(coord[k-1]);
	      cutPoint[i].push_back(coord[k]);
	      cutSep[i].push_back(ID);
	    }
	  }
	}
	if(tri[tri.size()-1]!=(uint64_t)-1){
	  if(i==tri[tri.size()-1]){
	    if((*flag)[i]==0)
	      (*flag)[i]=1; //joining other singularity
	    else
	      (*flag)[i]=3;
	    getGlobalEdg(i, coord[coord.size()-2], &e1);
	    getGlobalEdg(i, coord[coord.size()-1], &e2);
	    cutEdg[i].push_back(e1);
	    cutEdg[i].push_back(e2);
	    cutPoint[i].push_back(coord[coord.size()-2]);
	    cutPoint[i].push_back(coord[coord.size()-1]);
	    cutSep[i].push_back(ID);
	  }
	}
      }
    }
  }
 
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    (*cSep).push_back(cutSep[i]);
    (*cEdg).push_back(cutEdg[i]);
    (*cCoord).push_back(cutPoint[i]);
  }
 
  return 1;
}

int MultiBlock::isCloseToVert(std::array<double,3> *point, uint64_t edgNum, uint64_t triNum, double *distance){
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  int locEdg=-1;
  int flag=0;
  for(int i=0; i<3; i++){
    if(edgNum==edges->tri2edg[3*triNum+i])
      locEdg=i;
  }  
  double AB[3]={vert[4*nodes[3*triNum+(locEdg+1)%3]+0]-vert[4*nodes[3*triNum+locEdg]+0],
		vert[4*nodes[3*triNum+(locEdg+1)%3]+1]-vert[4*nodes[3*triNum+locEdg]+1],
		vert[4*nodes[3*triNum+(locEdg+1)%3]+2]-vert[4*nodes[3*triNum+locEdg]+2]};
  double AP[3]={(*point)[0]-vert[4*nodes[3*triNum+locEdg]+0],
		(*point)[1]-vert[4*nodes[3*triNum+locEdg]+1],
		(*point)[2]-vert[4*nodes[3*triNum+locEdg]+2]};
  //AP=alpha*AB
  double alpha=myDot(AP,AB)/myDot(AB,AB);
  //if(alpha<0.0005){ //old
  if(alpha<0.000005){
    //if(alpha<0.005){ //DBG
    for(int i=0; i<3; i++)
      (*point)[i]=vert[4*nodes[3*triNum+locEdg]+i];
    flag=1;
  }
  //else if(alpha>0.9995){ //old
  else if(alpha>0.999995){
    //else if(alpha>(1-0.005)){ //DBG
    for(int i=0; i<3; i++)
      (*point)[i]=vert[4*nodes[3*triNum+(locEdg+1)%3]+i];    
    flag=1;
  }
  *distance=alpha;
  
  return flag;
}



int MultiBlock::reorderPoints(std::vector<std::array<double,3>> points, std::vector<double> distances, std::vector<std::array<double,3>> *reorderedPoints){

  std::vector<double> prov;
  for(uint64_t i=0; i<distances.size(); i++){
    prov.push_back(distances[i]); 
  }
  std::sort(prov.begin(), prov.end(), sortDouble);

  for(uint64_t j=0; j<prov.size(); j++){
    for(uint64_t i=0; i<distances.size(); i++){
      if(distances[i]==prov[j])
	addInPointsVectIfNotPresent2(reorderedPoints, points[i]);
    }
  }
	
  return 1;
}

int MultiBlock::orientateTriNodes(uint64_t triNum, std::vector<std::array<double,3>> *cutPoints, std::vector<uint64_t> cutEdg, std::vector<std::array<double,3>> *orientedPoints){
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  std::array<double, 3> A;
  std::array<double, 3> B;
  std::array<double, 3> C;
  for(int i=0; i<3; i++){
    A[i]=vert[4*nodes[3*triNum+0]+i];
    B[i]=vert[4*nodes[3*triNum+1]+i];
    C[i]=vert[4*nodes[3*triNum+2]+i];
  }
  std::vector<std::array<double, 3>> e1Points;
  std::vector<std::array<double, 3>> e2Points;
  std::vector<std::array<double, 3>> e3Points;
  std::vector<double> d1;
  std::vector<double> d2;
  std::vector<double> d3;
  double alpha=-1.0;
  int globIndex=-1;
  //small func gives back the edge
  for(uint64_t i=0; i<cutEdg.size(); i++){
    if(cutEdg[i]!=(uint64_t)(-1)){
      if(edges->tri2edg[3*triNum+0]==cutEdg[i]){
	if(!isCloseToVert(&((*cutPoints)[i]), cutEdg[i],triNum, &alpha)){	//not to double vertex 
	  // if(!(isTriVert(triNum,(*cutPoints)[i], &globIndex))){
	  e1Points.push_back((*cutPoints)[i]);
	  d1.push_back(alpha);
	}
      }
      if(edges->tri2edg[3*triNum+1]==cutEdg[i]){
	if(!isCloseToVert(&((*cutPoints)[i]),cutEdg[i],triNum, &alpha)){ //not to double vertex
	  // if(!(isTriVert(triNum, (*cutPoints)[i], &globIndex))){
	  e2Points.push_back((*cutPoints)[i]);
	  d2.push_back(alpha);
	}
      }
      if(edges->tri2edg[3*triNum+2]==cutEdg[i]){
	if(!isCloseToVert(&((*cutPoints)[i]),cutEdg[i],triNum, &alpha)){ //not to double vertex
	  //if(!(isTriVert(triNum, (*cutPoints)[i], &globIndex))){
	  e3Points.push_back((*cutPoints)[i]);
	  d3.push_back(alpha);
	}
      }
    }
  }

  std::vector<std::array<double, 3>> p1;
  std::vector<std::array<double, 3>> p2;
  std::vector<std::array<double, 3>> p3;
  reorderPoints(e1Points, d1, &p1);
  reorderPoints(e2Points, d2, &p2);
  reorderPoints(e3Points, d3, &p3);
  (*orientedPoints).push_back(A);
  for(uint64_t i=0; i<p1.size(); i++)
    (*orientedPoints).push_back(p1[i]);
  (*orientedPoints).push_back(B);
  for(uint64_t i=0; i<p2.size(); i++)
    (*orientedPoints).push_back(p2[i]);
  (*orientedPoints).push_back(C);
  for(uint64_t i=0; i<p3.size(); i++)
    (*orientedPoints).push_back(p3[i]);

  return 1;
}

int MultiBlock::getIndice(std::array<double,3> point, std::vector<std::array<double,3>> vectPoints){
  int ind=-1;
  for(uint64_t i=0; i<vectPoints.size(); i++){
    std::array<double,3> vert=vectPoints[i];
    double norm=0.0;
    if(isPointDuplicateVec(&point, &vert, &norm)) 
      ind=(int)i;
  }
  return ind;
}

int MultiBlock::computeAlpha(double *u, double *v, double *d, double *alpha){
  double cosAlpha=0.0;
  double sinAlpha=0.0;
  for(int i=0; i<3; i++){
    cosAlpha+=d[i]*u[i];
    sinAlpha+=d[i]*v[i];
  }
  *alpha=atan2(sinAlpha, cosAlpha);
  
  return 1;
}

int MultiBlock::getTriSingNormal(uint64_t triNum, double *normal){
  int exist=0;
  std::array<double,3> *n; 
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::vector<uint64_t> *singTri=s->getPPatch();
    for(uint64_t j=0; j<singTri->size(); j++){
      if(triNum==(*singTri)[j]){
  	exist=1;
  	n=s->getPNormal();
      }
    }
  }

  if(exist == 1){
    for(int k=0; k<3; k++)
      normal[k]=(*n)[k];
  
   }

  return exist;
}

int MultiBlock::reorderingConnectivityNodes(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets, int *newConnectedNodes, std::vector<std::vector<int>> *graphConnectedNodes){
  FILE *f = fopen("qmbNormalsBeforeAfter.pos","w");
  fprintf(f,"View \"Normals after\" {\n");
  
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  for(int i=0; i<*numOffsets; i++){
    int count=0;
    for(int m=0; m<i; m++)
      count+=offset[m];
    uint64_t tri=connectedTri[count];
    uint32_t vTriNum[3] ={mesh->triangles.node[3*tri+0],mesh->triangles.node[3*tri+1],mesh->triangles.node[3*tri+2]};
    double u[3]={0,0,0};
    double v[3]={0,0,0};
    double n[3]={0,0,0};
    trianglebasis(mesh,vTriNum,u,v,n);   
    int length=offset[i];
    //-------------------------------------------------------------
    double normal[3]={0,0,0};
    double oldNormal[3]={n[0],n[1],n[2]};
    //----------------------------------------------------------------------------
    // double newN[3]={0,0,0};
    // for(size_t k=0;k<3;k++)
    //   normal[k]=n[k];
    // if(length-1==4)
    //   std::cout << "nInter = " << length-1 << std::endl;
    // for(int j=0; j<length-1; j++){
    //   double d[3]={connectedDir[3*(j+1+count)+0],connectedDir[3*(j+1+count)+1],connectedDir[3*(j+1+count)+2]};
    //   normalize(d);
    //   double pert[3]={0.0};
    //   crossprod(d, n, pert);
    //   double perturbation = sqrt(pert[0]*pert[0]+pert[1]*pert[1]+pert[2]*pert[2]);
    //   if(length-1==4)
    // 	std::cout << "preturbation = " << perturbation << std::endl;
    //   for(size_t k=0;k<3;k++)
    // 	normal[k] -= perturbation*d[k];
    // 	// normal[k] -= 1.;
    //   // std::cout << "j: " << j << std::endl;
    // }
    // normalize(normal);
    // for(size_t k=0;k<3;k++)
    //   n[k]=normal[k]; 
    //------------------------------------------------------------------------------------
    if(getTriSingNormal(tri, normal)){
      for(uint64_t t=0; t<3; t++)
      	n[t]=normal[t];
      if(sqrt(normal[1]*normal[1] + normal[0]*normal[0])>1e-2){
	u[0]=-normal[1]; u[1]=normal[0]; u[2]=0.0;
      }
      else{
	u[0]=0.; u[1]=-normal[2]; u[2]=normal[1];
      }
      normalize(u);
      crossprod(n, u, v);
      normalize(v);
      std::array<double, 3> pointVect=m_extraordVertices[connectedNodes[count]];
      double point1[3]={pointVect[0], pointVect[1], pointVect[2]};
      double point2[3]={normal[0]+pointVect[0],normal[1]+pointVect[1],normal[2]+pointVect[2]};
      double point3[3]={oldNormal[0]+pointVect[0],oldNormal[1]+pointVect[1],oldNormal[2]+pointVect[2]};
      // if(length-1==4){
	fprintf(f,"SP(%g,%g,%g){%i};\n", point1[0], point1[1], point1[2], 1);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point2[0], point2[1], point2[2], 1);
	fprintf(f,"SP(%g,%g,%g){%i};\n", point3[0], point3[1], point3[2], 1);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2], 1, 1);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", point1[0],  point1[1],  point1[2],  point3[0],  point3[1],  point3[2], 2, 2);
      // }

      double *angles1;
      HXT_CHECK(hxtMalloc(&angles1, (length-1)*sizeof(double)));
      double *angles2;
      HXT_CHECK(hxtMalloc(&angles2, (length-1)*sizeof(double)));
      int *anglesUsed;
      HXT_CHECK(hxtMalloc(&anglesUsed, (length-1)*sizeof(int)));
      int  *nodes;
      HXT_CHECK(hxtMalloc(&nodes, (length-1)*sizeof(int)));
      int  *nodesSorted;
      HXT_CHECK(hxtMalloc(&nodesSorted, (length-1)*sizeof(int)));
      int  *conn;
      HXT_CHECK(hxtMalloc(&conn, length*sizeof(int)));
 
      for(int j=0; j<length-1; j++){
	double alpha[1];
	double d[3]={connectedDir[3*(j+1+count)+0],connectedDir[3*(j+1+count)+1],connectedDir[3*(j+1+count)+2]};
	normalize(d);
	computeAlpha(u, v, d, alpha);
	angles1[j]=*alpha;
	angles2[j]=*alpha;
	anglesUsed[j]=0;
	nodes[j]=connectedNodes[j+1+count];
      }
      qsort(angles1, (length-1), sizeof(double), comparatorDouble);
      int num=0;
      for(int k=0; k<length-1; k++){
	for(int j=0; j<length-1; j++){
	  if(anglesUsed[j]!=1 && num!=(length-1) && angles1[k]==angles2[j]){
	    nodesSorted[num]=nodes[j];
	    anglesUsed[j]=1;
	    num++;
	  }
	}
      }
      newConnectedNodes[count]=connectedNodes[count];
      conn[0]=connectedNodes[count];
      for(int j=1; j<length; j++){
	newConnectedNodes[j+count]=nodesSorted[j-1];
	conn[j]=nodesSorted[j-1];
      }

      std::vector<int> myNodes;
      for(int s=0; s<length;s++)
	myNodes.push_back(conn[s]);
      (*graphConnectedNodes).push_back(myNodes);

      //DBG start J
      //  std::cout<<"NODE: "<<conn[0]<<std::endl;
      //  std::cout<<"Angles: "<<std::endl;
      //  for(uint64_t p=0; p<length-1; p++)
      //    std::cout<<angles1[p]*(180.0/M_PI)<<", ";
      //  std::cout<<" "<<std::endl;
      //  std::cout<<"Nodes: "<<std::endl;
      //  for(uint64_t p=1; p<length; p++)
      //    std::cout<<conn[p]<<", ";
      // std::cout<<" "<<std::endl;
      //DBG end J
    
      HXT_CHECK(hxtFree(&angles1));
      HXT_CHECK(hxtFree(&angles2));
      HXT_CHECK(hxtFree(&anglesUsed));
      HXT_CHECK(hxtFree(&nodes));
      HXT_CHECK(hxtFree(&nodesSorted));
      HXT_CHECK(hxtFree(&conn));
    }
  }

  fprintf(f,"};");
  fclose(f); 
  return 1;
}

int MultiBlock::getConnectivity(uint64_t triNum, int flag, std::vector<std::array<double,3>> cutPoints, std::vector<int> cutSep, std::vector<std::array<double,3>> *orientedPoints, std::vector<std::vector<int>> *connectedNodes, std::vector<std::array<int,2>> *localLines, std::vector<int> *localLinesColors){

  int ind1=-1, ind2=-1;
  //from nodes orientation in tri
  if(flag==1||flag==2){
    for(uint64_t i=0; i<orientedPoints->size(); i++){
      if(i==0){  //first point
	(*connectedNodes)[0].push_back(0);
	(*connectedNodes)[0].push_back(orientedPoints->size()-1); //node before
	(*connectedNodes)[0].push_back(1); //node after

      }
      else if(i==orientedPoints->size()-1){ //last point
	(*connectedNodes)[orientedPoints->size()-1].push_back(orientedPoints->size()-1);
	(*connectedNodes)[orientedPoints->size()-1].push_back(orientedPoints->size()-2); //node before
	(*connectedNodes)[orientedPoints->size()-1].push_back(0); //node after
      }
      else{
	(*connectedNodes)[i].push_back(i);
	(*connectedNodes)[i].push_back(i-1); //node before
	(*connectedNodes)[i].push_back(i+1); //node after
      }
    }
 
    for(uint64_t i=0; i<cutSep.size(); i++){
      std::array<double,3> point1=cutPoints[2*i];
      std::array<double,3> point2=cutPoints[2*i+1];
      ind1=getIndice(point1,*orientedPoints);
      ind2=getIndice(point2,*orientedPoints);
      std::array<int,2> localLine;
      localLine[0]=ind1;
      localLine[1]=ind2; 
      localLines->push_back(localLine);
      localLinesColors->push_back(cutSep[i]);
      if(ind2!=-1){
	//if(ind2!=-1 && ind1!=-1){ //DBG
	addInIntVectIfNotPresent(&((*connectedNodes)[ind1]), ind2);
      }
      if(ind1!=-1){
	//if(ind1!=-1 && ind2!=-1){ //DBG
	addInIntVectIfNotPresent(&((*connectedNodes)[ind2]), ind1);
      }
    }
  }
  if(flag==3){
    //compute intersection and push it back in oriented points
    int cnt=0; //num of added intersection points
    std::vector<int> init;
    init.reserve(4);
    std::vector<std::vector<int>> sepLinesPointsNotOrdered(cutSep.size(),init);
    for(uint64_t i=0;i<cutSep.size();i++){
      std::vector<int> *linePoint=&(sepLinesPointsNotOrdered[i]);
      std::array<double,3> point1=cutPoints[2*i];  //+0 +1 missing?
      ind1=getIndice(point1,*orientedPoints);
      if(ind1!=-1){
	addInIntVectIfNotPresent(linePoint, ind1);
      }
    }
    for(uint64_t i=0;i<cutSep.size()-1;i++){
      std::vector<int> *linePointI=&(sepLinesPointsNotOrdered[i]);
      std::array<double,3> point1=cutPoints[2*i];
      std::array<double,3> point2=cutPoints[2*i+1];
      for(uint64_t j=i+1;j<cutSep.size();j++){
	if(i!=j){
	  std::vector<int> *linePointJ=&(sepLinesPointsNotOrdered[j]);
	  std::array<double,3> point3=cutPoints[2*j];
	  std::array<double,3> point4=cutPoints[2*j+1];
	  int intersectionExists=0;
	  double coordIntersect[3]={0.0,0.0,0.0};
	  double p1[3]={0.0,0.0,0.0};
	  double p2[3]={0.0,0.0,0.0};
	  double p3[3]={0.0,0.0,0.0};
	  double p4[3]={0.0,0.0,0.0};
	  for(int k=0;k<3;k++){
	    p1[k]=point1[k];
	    p2[k]=point2[k];
	    p3[k]=point3[k];
	    p4[k]=point4[k];
	  }
	  intersectionNodeForGraph2(triNum, p1, p2, p3, p4, coordIntersect, &intersectionExists);
	  if(intersectionExists){
	    std::array<double,3> intersectionPoint;
	    for(int k=0;k<3;k++)
	      intersectionPoint[k]=coordIntersect[k];
	    int nodeDoesntExistOnBnd=0;
	    int ind=-1;
	    nodeDoesntExistOnBnd=addInPointsVectIfNotPresent(orientedPoints, intersectionPoint,&ind);
	    if(ind!=-1){
	      addInIntVectIfNotPresent(&(*linePointI), ind); 
	      addInIntVectIfNotPresent(&(*linePointJ), ind);
	    }
	    if(nodeDoesntExistOnBnd){
	      cnt++;
	      std::vector<int> initVectIntEmpty;
	      connectedNodes->push_back(initVectIntEmpty);
	    }
	  }
	}
      }
    }
    for(uint64_t i=0;i<cutSep.size();i++){
      std::vector<int> *linePoint=&(sepLinesPointsNotOrdered[i]);
      std::array<double,3> point2=cutPoints[2*i+1];
      ind2=getIndice(point2,*orientedPoints);
      if(ind2!=-1)
	addInIntVectIfNotPresent(linePoint, ind2);
    }
    //sorting points on each line
    for(uint64_t i=0; i<cutSep.size();i++){
      std::vector<int> *linePoint=&(sepLinesPointsNotOrdered[i]);
      std::array<double,3> init;
      std::vector<std::array<double,3>> pointsLineCoord(linePoint->size(),init);
      std::vector<std::array<double,3>> orderedPointsLineCoord;
      orderedPointsLineCoord.reserve(pointsLineCoord.size());
      for(uint64_t j=0;j<linePoint->size();j++){
	for(uint64_t k=0;k<3;k++){
	  (pointsLineCoord[j])[k]=((*orientedPoints)[(*linePoint)[j]])[k];
	}
      }
      std::vector<double> dist(linePoint->size(),0.0);
      for(uint64_t j=0;j<linePoint->size();j++){
	std::array<double,3> beginPoint=pointsLineCoord[0];
	std::array<double,3> currPoint=pointsLineCoord[j];
	for(uint64_t k=0;k<3;k++)
	  dist[j]+=(currPoint[k]-beginPoint[k])*(currPoint[k]-beginPoint[k]);
	dist[j]=sqrt(dist[j]);
      }
      reorderPoints(pointsLineCoord, dist, &orderedPointsLineCoord);
      for(uint64_t j=0;j<linePoint->size();j++){
	std::array<double,3> point=orderedPointsLineCoord[j];
	int ind = getIndice(point,*orientedPoints);
	(*linePoint)[j]=ind;
      }
    }
    //adding lines to local lines
    for(uint64_t i=0;i<cutSep.size();i++){
      std::vector<int> *linePoint=&(sepLinesPointsNotOrdered[i]);
      for(uint64_t j=0; j<linePoint->size()-1; j++){
	std::array<int,2> localLine;
	localLine[0]=(*linePoint)[j];
	localLine[1]=(*linePoint)[j+1];
	localLines->push_back(localLine);
	localLinesColors->push_back(cutSep[i]);
      }
    }
    for(uint64_t i=0; i<connectedNodes->size()-cnt; i++){
      if(i==0){  //first point
	(*connectedNodes)[0].push_back(0);
	(*connectedNodes)[0].push_back((int)connectedNodes->size()-1-cnt); //node before
	(*connectedNodes)[0].push_back(1); //node after

      }
      else if(i==connectedNodes->size()-1-cnt){ //last point
	(*connectedNodes)[connectedNodes->size()-1-cnt].push_back((int)connectedNodes->size()-1-cnt);
	(*connectedNodes)[connectedNodes->size()-1-cnt].push_back((int)connectedNodes->size()-2-cnt); //node before
	(*connectedNodes)[connectedNodes->size()-1-cnt].push_back(0); //node after
      }
      else{
	(*connectedNodes)[i].push_back((int)i);
	(*connectedNodes)[i].push_back((int)i-1); //node before
	(*connectedNodes)[i].push_back((int)i+1); //node after
      }
    }
    for(uint64_t i=connectedNodes->size()-cnt; i<connectedNodes->size(); i++){
      (*connectedNodes)[i].push_back((int)i);
    }
    //add connectivites to current ones
    for(uint64_t i=0;i<cutSep.size();i++){
      std::vector<int> *linePoint=&(sepLinesPointsNotOrdered[i]);
      for(uint64_t j=0; j<linePoint->size()-1; j++){
	addInIntVectIfNotPresent(&((*connectedNodes)[(*linePoint)[j]]), (*linePoint)[j+1]);
	addInIntVectIfNotPresent(&((*connectedNodes)[(*linePoint)[j+1]]), (*linePoint)[j]);
      }
    }
    //convert data for reorientation of connectivities
    int *connectedNodesInt;
    uint64_t *connectedTri;
    double *connectedDir;
    int *newConnectedNodesInt;
    int sizeConnectedNodes=0;
    int *offset;
    int numOffsets=0;
    HXT_CHECK(hxtMalloc(&offset, connectedNodes->size()*sizeof(int)));
    for(uint64_t i=0;i<connectedNodes->size();i++){
      numOffsets+=1;
      offset[i]=((*connectedNodes)[i]).size();
      sizeConnectedNodes+=((*connectedNodes)[i]).size();
    }
    HXT_CHECK(hxtMalloc(&newConnectedNodesInt, sizeConnectedNodes*sizeof(int)));
    HXT_CHECK(hxtMalloc(&connectedNodesInt, sizeConnectedNodes*sizeof(int)));
    HXT_CHECK(hxtMalloc(&connectedDir, 3*sizeConnectedNodes*sizeof(double)));
    HXT_CHECK(hxtMalloc(&connectedTri, sizeConnectedNodes*sizeof(uint64_t)));
    for(uint64_t i=0;i<connectedNodes->size();i++){
      int count=0;
      for(int m=0; m<(int)i; m++){
	count+=offset[m];
      }
      for(uint64_t j=0;j<(uint64_t)offset[i];j++){
	connectedNodesInt[count+j]=((*connectedNodes)[i])[j];
	connectedTri[count+j]=triNum;
	std::array<double,3> beginPoint=(*orientedPoints)[((*connectedNodes)[i])[0]];
	std::array<double,3> currPoint=(*orientedPoints)[((*connectedNodes)[i])[j]];
	for(uint64_t k=0;k<3;k++){
	  connectedDir[3*(j+count)+k]=currPoint[k]-beginPoint[k];
	}
      }
    }
    //orientation of connected Nodes
    std::vector<std::vector<int>> graphConnectedNodes;
    reorderingConnectivityNodes(connectedNodesInt, connectedTri, connectedDir, offset, &numOffsets, newConnectedNodesInt, &graphConnectedNodes);
    //copying new values
    for(uint64_t i=0;i<connectedNodes->size();i++){
      for(uint64_t j=0;j<((*connectedNodes)[i]).size();j++){
	((*connectedNodes)[i])[j]=(graphConnectedNodes[i])[j];
      }
    }
    HXT_CHECK(hxtFree(&connectedNodesInt));
    HXT_CHECK(hxtFree(&offset));
    HXT_CHECK(hxtFree(&newConnectedNodesInt));
    HXT_CHECK(hxtFree(&connectedTri));
    HXT_CHECK(hxtFree(&connectedDir));
  }
 
  return 1;
}

int MultiBlock::split(std::vector<int> nodes, std::vector<std::array<int,3>> *triVertInd, std::vector<int> *rest){//ALEX: to modify here. we have to check we are not creating a flat triangle
  //create first triangle
  std::array<int,3> vert;
  for(int i=0; i<3; i++)
    vert[i]=nodes[i];
  (*triVertInd).push_back(vert);

  std::vector<int> rest1;
  //get the rest 
  for(uint64_t i=2; i<nodes.size(); i++)
    rest1.push_back(nodes[i]);
  rest1.push_back(nodes[2]);
  //check if its triangle left
  if(rest1.size()==4){
    for(int i=0; i<3; i++)
      vert[i]=rest1[i];
    (*triVertInd).push_back(vert);
  }else if(rest1.size()>4){
    for(uint64_t i=0; i<rest1.size(); i++)
      (*rest).push_back(rest1[i]);
  }
    
  return 1;
}

int MultiBlock::isElementBnd(std::vector<std::array<double, 3>> bndNodes, std::vector<std::array<double, 3>> polyNodes){
  int flag=0, numNodesOnBnd=0;
  double norm=0.0;
  for(uint64_t i=0; i<polyNodes.size(); i++){
    for(uint64_t j=0; j<bndNodes.size(); j++){
      if(isPointDuplicateVec(&polyNodes[i], &bndNodes[j], &norm))
	numNodesOnBnd++;
    }
  }
  
  if(numNodesOnBnd==(int)bndNodes.size()){
    flag=1;
  }
  
  return flag;
}

bool isTriTooFlat(std::array<double,3> p1,std::array<double,3> p2,std::array<double,3> p3){
  bool isTooFlat=false;
  double angles[3]={0.0};
  double e0[3]={p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
  double nn0 = sqrt(e0[0]*e0[0]+e0[1]*e0[1]+e0[2]*e0[2]);
  if(nn0>1e-10){
    e0[0]/=nn0;e0[1]/=nn0;e0[2]/=nn0;
  }
  double e1[3]={p3[0]-p2[0],p3[1]-p2[1],p3[2]-p2[2]};
  double nn1 = sqrt(e1[0]*e1[0]+e1[1]*e1[1]+e1[2]*e1[2]);
  if(nn1>1e-10){
    e1[0]/=nn1;e1[1]/=nn1;e1[2]/=nn1;
  }
  double res[3]={0.0};
  crossprod(e0,e1,res);
  if(fabs(res[0])<1.e-7 && fabs(res[1])<1.e-7 && fabs(res[2])<1.e-7){
    isTooFlat=true;
  }
  // return false;
  return isTooFlat;
}

void circularVectPermutation(std::vector<int> &vect){
  // int temp=vect[0];
  for(size_t k=0;k<vect.size()-1;k++)
    vect[k]=vect[k+1];
  // vect[vect.size()-1]=temp;
  vect[vect.size()-1]=vect[0];
}

//works on 1 single triangle
int MultiBlock::splitTriangle(std::vector<std::array<double,3>> orientedPoints, std::vector<std::array<double,3>> bndryPoints, std::vector<std::vector<int>> connectedNodes, std::vector<std::array<int,3>> *newTri){ 
  int initAlloc=10000;
  int *triWithIndices;
  HXT_CHECK(hxtMalloc(&triWithIndices,orientedPoints.size()*initAlloc*sizeof(int)));
  int *offset;
  HXT_CHECK(hxtMalloc(&offset,connectedNodes.size()*sizeof(int)));
  for(uint64_t i=0; i<connectedNodes.size(); i++)
    offset[i]=connectedNodes[i].size();
  int numTriangles=-1;
  int numOffsets=connectedNodes.size();
  int sizesTri[100];
  defineQuads(connectedNodes, triWithIndices, offset, &numOffsets, sizesTri, &numTriangles);
  std::vector<std::array<double, 3>> polyNodes;
  std::array<double, 3> point;
  for(int t=0; t<numTriangles; t++){
    int *triIndices;
    HXT_CHECK(hxtMalloc(&triIndices, (sizesTri[t])*sizeof(int)));
    int count=0;
    for(int m=0; m<t; m++){
      count+=sizesTri[m];
    }
    for(int j=0; j<sizesTri[t]; j++){
      triIndices[j]=triWithIndices[j+count];
    }
    std::array<int,3> triVertInd;
    if(sizesTri[t]==4){
      //check if polygone is bnd!
      for(int k=0; k<3; k++){
	convertIndToCoord(orientedPoints, triIndices[k], &point);
	polyNodes.push_back(point);
      }
      if(!isElementBnd(bndryPoints, polyNodes)){
	for(int k=0; k<3; k++)
	  triVertInd[k]=triIndices[k];
	(*newTri).push_back(triVertInd);
      }
      polyNodes.erase(polyNodes.begin(),polyNodes.begin()+polyNodes.size()); //for reallocation
    }else{
      //check if polygone is bnd!
      for(int k=0; k<sizesTri[t]-1; k++){
	convertIndToCoord(orientedPoints, triIndices[k], &point);
	polyNodes.push_back(point);
      }
      if(!isElementBnd(bndryPoints, polyNodes)){
	std::vector<int> nodes(sizesTri[t],0);
	for(int k=0; k<sizesTri[t]; k++)
	  nodes[k]=triIndices[k];
	std::vector<int> rest;
	std::vector<std::array<int,3>> trianglesVertInd;
	//check if flat tri is next
	std::array<double,3> p1, p2, p3;
	convertIndToCoord(orientedPoints,nodes[0], &p1);
	convertIndToCoord(orientedPoints,nodes[1], &p2);
	convertIndToCoord(orientedPoints,nodes[2], &p3);
	int cptPermut=0;
	if(isTriTooFlat(p1, p2, p3)&&cptPermut<nodes.size()){
	  circularVectPermutation(nodes);
	  cptPermut++;
	}
	//
	split(nodes, &trianglesVertInd, &rest);
	for(uint64_t j=0; j<trianglesVertInd.size(); j++)
	  (*newTri).push_back(trianglesVertInd[j]);
	while(rest.size()!=0){//we dont have all triangles
	  std::vector<std::array<int,3>> trianglesVertInd1;
	  std::vector<int> rest2;
	  //check if flat tri is next
	  std::array<double,3> p1, p2, p3;
	  convertIndToCoord(orientedPoints,rest[0], &p1);
	  convertIndToCoord(orientedPoints,rest[1], &p2);
	  convertIndToCoord(orientedPoints,rest[2], &p3);
	  cptPermut=0;
	  if(isTriTooFlat(p1, p2, p3)&&cptPermut<nodes.size()){
	    circularVectPermutation(rest);
	    cptPermut++;
	  }
	  //
	  split(rest, &trianglesVertInd1, &rest2);
	  for(uint64_t j=0; j<trianglesVertInd1.size(); j++)
	    (*newTri).push_back(trianglesVertInd1[j]);
	  rest.erase(rest.begin(),rest.begin()+rest.size()); //for reallocation
	  for(uint64_t k=0; k<rest2.size(); k++)
	    rest.push_back(rest2[k]);
	}
      }
      polyNodes.erase(polyNodes.begin(),polyNodes.begin()+polyNodes.size()); //for reallocation
    }
    HXT_CHECK(hxtFree(&triIndices));
  }
  HXT_CHECK(hxtFree(&triWithIndices));
  HXT_CHECK(hxtFree(&offset));

  return 1;
}

int MultiBlock::convertIndToCoord(std::vector<std::array<double,3>> cCoord, int ind, std::array<double,3> *point){
  for(uint64_t i=0; i<cCoord.size(); i++){
    if((uint64_t)ind==i){
      std::array<double,3> coord=cCoord[i];
      for(int j=0; j<3; j++)
	(*point)[j]=coord[j];
    } 
  }

  return 1;
}

void MultiBlock::computeLocalCutEdges(uint64_t triNum,std::vector<std::array<double,3>> cutCoords,std::vector<uint64_t> *localCutEdges){
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  double A[3] = {vert[4*nodes[3*triNum+0]+0],
		 vert[4*nodes[3*triNum+0]+1],
		 vert[4*nodes[3*triNum+0]+2]};
  double B[3] = {vert[4*nodes[3*triNum+1]+0],
		 vert[4*nodes[3*triNum+1]+1],
		 vert[4*nodes[3*triNum+1]+2]};
  double C[3] = {vert[4*nodes[3*triNum+2]+0],
		 vert[4*nodes[3*triNum+2]+1],
		 vert[4*nodes[3*triNum+2]+2]};
  double AB[3]={0.0,0.0,0.0};
  double BC[3]={0.0,0.0,0.0};
  double CA[3]={0.0,0.0,0.0};
  double AP[3]={0.0,0.0,0.0};
  double BP[3]={0.0,0.0,0.0};
  double CP[3]={0.0,0.0,0.0};
  for(uint64_t k=0; k<cutCoords.size(); k++){
    double P[3]={0.0,0.0,0.0};
    for(int i=0; i<3; i++)
      P[i]=cutCoords[k][i];
    for(int i=0; i<3; i++){
      AB[i]=B[i]-A[i];
      BC[i]=C[i]-B[i];
      CA[i]=A[i]-C[i];
      AP[i]=P[i]-A[i];
      BP[i]=P[i]-B[i];
      CP[i]=P[i]-C[i];
    }
    double normAB;
    hxtNorm2V3(AB, &normAB);
    double normBC;
    hxtNorm2V3(BC, &normBC);
    double normCA;
    hxtNorm2V3(CA, &normCA);
    for(int i=0; i<3; i++){
      AB[i]/=normAB;
      AP[i]/=normAB;
      BC[i]/=normBC;
      BP[i]/=normBC;
      CA[i]/=normCA;
      CP[i]/=normCA;
    }
    double n[3]={0.0,0.0,0.0};
    crossprod(AB, AP, n);
    double normABAP;
    hxtNorm2V3(n, &normABAP);
    crossprod(BC, BP, n);
    double normBCBP;
    hxtNorm2V3(n, &normBCBP);
    crossprod(CA, CP, n);
    double normCACP;
    hxtNorm2V3(n, &normCACP);
    if(normABAP<1e-8)
      (*localCutEdges)[k]=edges->tri2edg[3*triNum+0];
    else if(normBCBP<1e-8)
      (*localCutEdges)[k]=edges->tri2edg[3*triNum+1];
    else if(normCACP<1e-8)
      (*localCutEdges)[k]=edges->tri2edg[3*triNum+2];
    else{
      (*localCutEdges)[k]=(uint64_t)(-1);
    }
  }
  return;
}

int MultiBlock::isTriVert(uint64_t triNum,std::array<double, 3> point, int *globIndex){
  *globIndex=-1;
  int flag=0;
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  std::array<double,3> coord1, coord2, coord3;
  for(int j=0; j<3; j++){
    coord1[j]=vert[4*nodes[3*triNum+0]+j];
    coord2[j]=vert[4*nodes[3*triNum+1]+j];
    coord3[j]=vert[4*nodes[3*triNum+2]+j];
  }
  double norm=0.0;
  if(isPointDuplicateVec(&coord1, &point, &norm)){
    flag=1;
    *globIndex=nodes[3*triNum+0];
  }
  if(isPointDuplicateVec(&coord2, &point, &norm)){
    flag=1;
    *globIndex=nodes[3*triNum+1];
  }
  if(isPointDuplicateVec(&coord3, &point, &norm)){
    flag=1;
    *globIndex=nodes[3*triNum+2];
  }

  return flag;
}

int isExistingMeshLine(std::vector<std::array<int,2>> *allMeshLines, std::array<int,2> lineIndices){
  int exist=0;
  for(uint64_t i=0; i<(*allMeshLines).size(); i++){
    if((lineIndices[0]==(*allMeshLines)[i][0] && lineIndices[1]==(*allMeshLines)[i][1]) ||
       (lineIndices[0]==(*allMeshLines)[i][1] && lineIndices[1]==(*allMeshLines)[i][0]))
      exist=1;
  }
  return exist;
}

// int isExistingMeshElement(std::vector<std::array<int,3>> *allMeshTri,  std::array<int,3> vertIndices){
//   int exist=0;
//   for(uint64_t i=0; i<(*allMeshTri).size(); i++){
//     if( ((*allMeshTri)[i][0]==vertIndices[0] || (*allMeshTri)[i][0]==vertIndices[1] ||(*allMeshTri)[i][0]==vertIndices[2]) &&
// 	((*allMeshTri)[i][1]==vertIndices[0] || (*allMeshTri)[i][1]==vertIndices[1] ||(*allMeshTri)[i][1]==vertIndices[2]) &&
// 	((*allMeshTri)[i][2]==vertIndices[0] || (*allMeshTri)[i][2]==vertIndices[1] ||(*allMeshTri)[i][2]==vertIndices[2]))
//       exist=1;
//   }
//   return exist;
// }

// int isTriFlat(std::array<double,3> point1, std::array<double,3> point2, std::array<double,3> point3){
//   int flat=0;
//   double AB[3], AC[3], n[3];
//   for(int i=0;i<3; i++){
//     AB[i] = point2[i]-point1[i];
//     AC[i] = point3[i]-point1[i];
//     n[i] = 0.0;
//   }
  //normal check
  // crossprod(AB,AC,n);
  // double normABAC;
  // hxtNorm2V3(n, &normABAC);
  // if(normABAC<1e-5)
  //   flat=1;

  //angle check
//   double normAB = sqrt(AB[0]*AB[0]+AB[1]*AB[1]+AB[2]*AB[2]);
//   double normAC = sqrt(AC[0]*AC[0]+AC[1]*AC[1]+AC[2]*AC[2]);
//   double alpha = acos(myDot(AB,AC)/(normAB*normAC));
//   if (fabs(alpha*180.0/M_PI)<= 0.5  || fabs(alpha*180.0/M_PI)>= 179.5)
//     flat=1;

//   return flat;
// }

int MultiBlock::createNewTriangles(std::vector<int> flag, std::vector<std::vector<int>> cSep, std::vector<std::vector<std::array<double,3>>> cCoord, std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri, std::vector<std::array<int,2>> *allMeshLines, std::vector<int> *allMeshLinesColors){ //giving back for mesh create
  int numCutPoints=0;
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  std::array<double,3> coord, coord1, coord2, coord3;
  std::array<int,3> vertIndices;
  allMeshNodes->reserve(mesh->vertices.num);
  allMeshTri->reserve(mesh->triangles.num);
  allMeshLines->reserve(mesh->lines.num);
  allMeshLinesColors->reserve(mesh->lines.num);
  //getting all vertices from the original mesh
  for(uint64_t i=0; i<mesh->vertices.num; i++){
    for(int j=0; j<3; j++)
      coord[j]=vert[4*i+j];
    (*allMeshNodes).push_back(coord);
  }
  uint64_t start=(*allMeshNodes).size();
  //uint64_t start=0;
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    if(flag[i]==0){ //not crossed with separatrice
      for(int j=0; j<3; j++)
	vertIndices[j]=nodes[3*i+j];
      (*allMeshTri).push_back(vertIndices);
    }
    else{
      std::vector<std::array<double,3>> orientedPoints;
      std::vector<uint64_t> localCutEdges(cCoord[i].size(),(uint64_t)-1);
      computeLocalCutEdges(i,cCoord[i], &localCutEdges);
      orientateTriNodes(i, &(cCoord[i]), localCutEdges, &orientedPoints);
      std::vector<std::array<double,3>> bndryPoints(orientedPoints);
      numCutPoints+=cCoord[i].size();
      std::vector<int> initVectIntEmpty;
      std::vector<std::vector<int>> connectedNodes(orientedPoints.size(),initVectIntEmpty);
      std::vector<std::array<int,2>> localLines;
      std::vector<int> localLinesColors;
      getConnectivity(i, flag[i], cCoord[i],  cSep[i], &orientedPoints, &connectedNodes, &localLines, &localLinesColors);
      std::vector<std::array<int,3>> newTri;
      splitTriangle(orientedPoints, bndryPoints, connectedNodes, &newTri);
      if(newTri.size()==0){ //triangles which edg is bnd sep; no need to add coords -they already exist
	for(int j=0; j<3; j++)
	  vertIndices[j]=nodes[3*i+j];
	(*allMeshTri).push_back(vertIndices);
	for(uint64_t j=0; j<localLines.size(); j++){
	  std::array<int,2> lineIndices;
	  std::array<double,3> linePoint1, linePoint2;
	  convertIndToCoord(orientedPoints,localLines[j][0], &linePoint1);
	  convertIndToCoord(orientedPoints,localLines[j][1], &linePoint2);
	  int ind=-1;
	  if(isTriVert(i, linePoint1, &ind)){
	    lineIndices[0]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint1, &ind);
	    lineIndices[0]=ind;
	  }
	  if(isTriVert(i, linePoint2, &ind)){
	    lineIndices[1]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint2, &ind);
	    lineIndices[1]=ind;
	  }
	  allMeshLines->push_back(lineIndices);
	  allMeshLinesColors->push_back(localLinesColors[j]);
	}
      }
      else{
	//add lines
	for(uint64_t j=0; j<localLines.size(); j++){
	  std::array<int,2> lineIndices;
	  std::array<double,3> linePoint1, linePoint2;
	  convertIndToCoord(orientedPoints,localLines[j][0], &linePoint1);
	  convertIndToCoord(orientedPoints,localLines[j][1], &linePoint2);
	  int ind=-1;
	  if(isTriVert(i, linePoint1, &ind)){
	    lineIndices[0]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint1, &ind);
	    lineIndices[0]=ind;
	  }
	  if(isTriVert(i, linePoint2, &ind)){
	    lineIndices[1]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint2, &ind);
	    lineIndices[1]=ind;
	  }
	  if(!isExistingMeshLine(allMeshLines,  lineIndices)){ //DBG
	    allMeshLines->push_back(lineIndices);
	    allMeshLinesColors->push_back(localLinesColors[j]);
	  }else{
	    std::cout<<"Existing line: "<<lineIndices[0]<<" "<<lineIndices[1]<<std::endl; //DBG
	  }
	}
	//add allTriangles
	for(uint64_t j=0; j<newTri.size(); j++){
	  std::array<double,3> point1, point2, point3;
	  convertIndToCoord(orientedPoints,newTri[j][0], &point1);
	  convertIndToCoord(orientedPoints,newTri[j][1], &point2);
	  convertIndToCoord(orientedPoints,newTri[j][2], &point3);
	  
	  //adding new nodes (and triangles)
	  int ind=-1;
	  if(isTriVert(i, point1, &ind)){
	    vertIndices[0]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point1, &ind);
	    vertIndices[0]=ind;
	  }
	  if(isTriVert(i, point2, &ind)){
	    vertIndices[1]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point2, &ind);
	    vertIndices[1]=ind;
	  }
	  if(isTriVert(i, point3, &ind)){
	    vertIndices[2]=ind;
	  }else{
	    addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point3, &ind);
	    vertIndices[2]=ind;
	  }
	  // if(!isExistingMeshElement(allMeshTri, vertIndices)) //DBG
	  (*allMeshTri).push_back(vertIndices);
	}
      }
    }
  }
  return 1;
}

HXTStatus MultiBlock::createMyTriMesh(std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri, std::vector<std::array<int,2>> *allMeshLines, std::vector<int> *allMeshLinesColors){
  HXT_CHECK(hxtMeshCreate(&(m_myTriMesh)));
  // vertices
  m_myTriMesh->vertices.num = allMeshNodes->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->vertices.coord),4*(m_myTriMesh->vertices.num)*sizeof(double)));
  for(uint64_t i=0; i<m_myTriMesh->vertices.num; i++){
    for(int t=0; t<3; t++)
      m_myTriMesh->vertices.coord[4*i+t] = (*allMeshNodes)[i][t];
    m_myTriMesh->vertices.coord[4*i+3] = 0.0;
  }
  
  // triangles
  m_myTriMesh->triangles.num = allMeshTri->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->triangles.node),3*(m_myTriMesh->triangles.num)*sizeof(uint64_t)));
  int numT=0;
  for(uint64_t i=0; i<allMeshTri->size(); i++){
    if((*allMeshTri)[i][0] != (*allMeshTri)[i][1] && (*allMeshTri)[i][0] != (*allMeshTri)[i][2] && (*allMeshTri)[i][1] != (*allMeshTri)[i][2]){ //not storing flatten tri
      for(int t=0; t<3; t++)
	m_myTriMesh->triangles.node[3*numT+t] = (*allMeshTri)[i][t];
      numT++;
    }
  }
  
  // lines
  m_myTriMesh->lines.num = allMeshLines->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->lines.node),2*(m_myTriMesh->lines.num)*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->lines.color),(m_myTriMesh->lines.num)*sizeof(uint16_t)));
  int numL=0;
  for(uint64_t i=0; i<allMeshLines->size(); i++){
    if((*allMeshLines)[i][0] != (*allMeshLines)[i][1]){ // not storing flatten lines
      for(uint64_t t=0; t<2; t++)
	m_myTriMesh->lines.node[2*numL+t] = (uint32_t)(*allMeshLines)[i][t];
      m_myTriMesh->lines.color[numL] = (uint16_t)((*allMeshLinesColors)[i]);
      numL++;
    }
  }

  hxtMeshWriteGmsh(m_myTriMesh, "qmbMyTriMesh.msh");
  std::cout<<"--New mesh written--"<<std::endl;
  
  return HXT_STATUS_OK;
}

HXTMesh* MultiBlock::getMyTriMesh(){
  return m_myTriMesh;
}

HXTStatus MultiBlock::hxtWriteFlaggedTriangles(std::vector<int> flag, const char *fileName){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Triangles\" {\n");
  for(uint64_t i=0; i<mesh->triangles.num; i++){
    if(i==542 || i==496){
      fprintf(f,"ST(");
      uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
      for(uint32_t j=0; j<3; j++){
	fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
	if(j<2)
	  fprintf(f,",");
      }
      fprintf(f,")");
      fprintf(f,"{");
      fprintf(f,"%i, %i, %i",flag[i],flag[i],flag[i]);
      fprintf(f,"};\n");
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::hxtWriteFlaggedNodes(std::vector<std::vector<std::array<double,3>>> cCoord, const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Cut nodes\" {\n");
  for(uint32_t i=0; i<cCoord.size(); i++){
    std::vector<std::array<double,3>> points=cCoord[i];
    if(points.size()!=0){
      for(uint32_t j=0; j<points.size(); j++){
	int color=(int)i;
	std::array<double,3> coord=points[j];
	fprintf(f,"SP(%g,%g,%g){%i};\n", coord[0], coord[1], coord[2], color);
      }
    }
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::hxtWriteTriVert(std::vector<std::array<double,3>> vertices, const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Vertices\" {\n");
  for(uint64_t i=0; i<vertices.size(); i++)
    fprintf(f,"SP(%g,%g,%g){%i};\n", vertices[i][0], vertices[i][1], vertices[i][2], (int)i);
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}







//NEW things----------------------------------------------------------------------------------
HXTStatus MultiBlock::buildQuadLayout(){
  std::cout << "--BUILD GRAPH--" << std::endl;
  std::cout << "--Get graph elements--" << std::endl;
  std::vector<std::array<double,3>> nodesCoord;
  std::vector<uint64_t> triangles;
  std::vector<std::array<double,3>> directions;
  std::vector<double> distance;
  std::vector<int> offset;
  std::vector<std::array<double,3>> newNodes;
  std::vector<uint64_t> newTriangles;
  std::vector<std::array<double,3>> newDirections;
  std::vector<double> newDistances;
  std::vector<int> newOffsetGraph;
  getGraphElements(&nodesCoord, &triangles, &directions, &distance, &offset);
  std::cout << "--Write graph nodes--" << std::endl;
  hxtWriteGraphNodes(nodesCoord, "myGraphNodes.pos");
  std::cout << "--Reorder graph--" << std::endl;
  graphReordering(nodesCoord, triangles, directions, distance,  offset, &newNodes, &newTriangles, &newDirections, &newDistances, &newOffsetGraph);
  std::cout << "--Fill in graph class attributes--" << std::endl;
  fillGraphStruct(newNodes, newTriangles, newOffsetGraph);
  std::cout << "--Put IDs--" << std::endl;
  putIDsInGraph(newNodes, newDirections, newTriangles, newOffsetGraph);
  // killDuplicatesSepTjunction();
  hxtWriteGraphNodes(newNodes, "qmbGraphNodes1.pos");
  hxtWriteGraphNodes(m_extraordVertices, "qmbGraphNodes2.pos");
  // std::cout << "sepgraphnodes: " << std::endl;
  // for(size_t k=0;k<m_sepGraphNodes.size();k++){
  //   std::cout << "sep clean ID: " << k << std::endl;
  //   for(size_t l=0;l<m_sepGraphNodes[k].size();l++)
  //     std::cout << m_sepGraphNodes[k][l] << " ";
  //   std::cout << std::endl;
  // }
  

  std::cout << "--BUILD QUADS--" << std::endl;
  std::cout << "--Nodes connectivity--" << std::endl; 
  int initAlloc=1000000;
  int *connectedNodes;
  HXT_CHECK(hxtMalloc(&connectedNodes, initAlloc*sizeof(int)));
  uint64_t *connectedTri;
  HXT_CHECK(hxtMalloc(&connectedTri, initAlloc*sizeof(uint64_t)));
  double *connectedDir;
  HXT_CHECK(hxtMalloc(&connectedDir, 3*initAlloc*sizeof(double)));
  int *offsetN;
  HXT_CHECK(hxtMalloc(&offsetN, initAlloc*sizeof(int)));
  int numOffsets=-1;
  std::cout << "--Get nodes connectivity--" << std::endl;
  nodesConnectivity(connectedNodes, connectedTri, connectedDir, offsetN, &numOffsets);
  // for(int i=0;i<m_vectSep.size();i++){
  //   if(m_vectSep[i].getIsLimitCycle()){
  //     std::cout << "nPoins: " << m_vectSep[i].getCoord().size() << std::endl;
  //     std::cout << "nTri: " << m_vectSep[i].getTriangles().size() << std::endl;
  //     std::vector<std::array<double,3>> sepPoints=m_vectSep[i].getCoord();
  //     std::cout << "point: " << sepPoints[sepPoints.size()-3][0] << " " << sepPoints[sepPoints.size()-3][1] << " " << sepPoints[sepPoints.size()-3][2] << std::endl;
  //     std::cout << "point: " << sepPoints[sepPoints.size()-2][0] << " " << sepPoints[sepPoints.size()-2][1] << " " << sepPoints[sepPoints.size()-2][2] << std::endl;
  //     std::cout << "point: " << sepPoints[sepPoints.size()-1][0] << " " << sepPoints[sepPoints.size()-1][1] << " " << sepPoints[sepPoints.size()-1][2] << std::endl;
  //   }
  // }
  // std::cout << "--connectedNodes--" << std::endl;
  // for(int i=0;i<numOffsets;i++){
  //   int count=0;
  //   for(int j=0;j<i;j++){
  //     count += offsetN[j];
  //   }
  //   for(int j=0;j<offsetN[i];j++){
  //     std::cout << connectedNodes[count+j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  std::cout << "--Reorder nodes connectivity--" << std::endl;
  int *newConnectedNodes;
  HXT_CHECK(hxtMalloc(&newConnectedNodes, initAlloc*sizeof(int)));
  std::vector<std::vector<int>> graphConnectedNodes;
  reorderingConnectivityNodes(connectedNodes, connectedTri, connectedDir, offsetN, &numOffsets, newConnectedNodes, &graphConnectedNodes);
  // std::cout << "--newconnectedNodes--" << std::endl;
  // for(int i=0;i<numOffsets;i++){
  //   int count=0;
  //   for(int j=0;j<i;j++){ 
  //     count += offsetN[j];
  //   }
  //   for(int j=0;j<offsetN[i];j++){
  //     std::cout << newConnectedNodes[count+j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << "graphconnectednodes" << std::endl;
  // for(uint64_t s=0; s<graphConnectedNodes.size(); s++){
  //   for(uint64_t m=0; m<graphConnectedNodes[s].size(); m++)
  //     std::cout<<" "<<graphConnectedNodes[s][m]<<" ";
  //   std::cout<<std::endl;
  // }
  std::cout << "--Kill duplicates--" << std::endl;
  std::vector<std::vector<int>> cleanGraphConnectedNodes;
  int *cleanOffsetN;
  HXT_CHECK(hxtMalloc(&cleanOffsetN, initAlloc*sizeof(int)));
  killDuplicates(graphConnectedNodes, &cleanGraphConnectedNodes, cleanOffsetN);
  // killDuplicatesSepTjunction();//ALEX
  std::cout << "--Clean graph connected nodes--" << std::endl;
  for(uint64_t s=0; s<cleanGraphConnectedNodes.size(); s++){
    for(uint64_t m=0; m<cleanGraphConnectedNodes[s].size(); m++)
      std::cout<<" "<<cleanGraphConnectedNodes[s][m]<<" ";
    std::cout<<std::endl;
  }
  // PRINT SEP GRAPH NODES
  // std::cout << "sepgraphnodes: " << std::endl;
  // for(size_t k=0;k<m_sepGraphNodes.size();k++){
  //   for(size_t l=0;l<m_sepGraphNodes[k].size();l++)
  //     std::cout << m_sepGraphNodes[k][l] << " ";
  //   std::cout << std::endl;
  // }
  std::cout << "--Define quads--" << std::endl;
  int *quadsWithIndices;
  HXT_CHECK(hxtMalloc(&quadsWithIndices,4*initAlloc*sizeof(int)));
  int numQuads=-1;
  int sizesQuads[1000000];
  // defineQuads(cleanGraphConnectedNodes, quadsWithIndices, cleanOffsetN, &numOffsets, sizesQuads, &numQuads);
  defineQuads(graphConnectedNodes, quadsWithIndices, offsetN, &numOffsets, sizesQuads, &numQuads);
  
  std::cout << "Number of quads: " <<numQuads<< std::endl;
  for(int s=0; s<numQuads; s++)
    std::cout << "num quad nodes: " <<sizesQuads[s]<< std::endl;
  
  std::cout << "Quads with indices: " << std::endl;
  std::cout << "Block 0" << std::endl;
  for(int m=0; m<sizesQuads[0]; m++)
    std::cout<<"Indice: "<<quadsWithIndices[m]<<std::endl;
  std::cout << "-------" << std::endl;
  for(int s=1; s<numOffsets; s++){
    std::cout << "Block " << s << std::endl;
    for(int m=0; m<sizesQuads[s]; m++)
      std::cout<<"Indice: "<<s<<" "<<quadsWithIndices[m+cleanOffsetN[s-1]]<<std::endl;
    std::cout << "-------" << std::endl;
  }

  //clean sep_graphNodes of duplicates 

  std::cout << "--Nodes on bdry--" << std::endl;
  int *nodesOnBdry;
  HXT_CHECK(hxtMalloc(&nodesOnBdry,initAlloc*sizeof(int)));
  int sizeNodesOnBdry[1];
  graphNodesOnBdry(nodesOnBdry, sizeNodesOnBdry);
  std::vector<std::array<double,3>> bdryN;
  for(int s=0; s<*sizeNodesOnBdry; s++){
    bdryN.push_back(m_extraordVertices[nodesOnBdry[s]]);
  }
  hxtWriteGraphNodes(bdryN, "qmbGraphNodesOnBdry.pos");
  std::cout<<"--Clean and store quads in structure--"<<std::endl;
  std::cout<<"Num big quads: "<<numQuads-1<<std::endl;
  putCleanQuadsInStruct(quadsWithIndices, sizesQuads, &numQuads);
  std::cout<<"----BUILDING QUADS FINISHED!----"<<std::endl;

  //new functions start-------------------------------------------
  // std::cout<<"----COLLECTING BLOCKS DATA!----"<<std::endl;
  // std::cout<<"SEP GRAPH STRUCTURE"<<std::endl;
  // for(uint64_t j=0; j<m_vectSep.size(); j++){
  //   Separatrice *sep=&(m_vectSep[j]);
  //   if(sep->isSaved()){ 
  //     int sepID=sep->getID();
  //     int ind=-1;
  //     getCleanedSepIndFromSepID(sepID, &ind);
  //     std::cout<<"SepID: "<<sepID<<" nodes: ";
  //     for(uint64_t k=0; k<m_sepGraphNodes[ind].size(); k++){
  // 	std::cout<<" "<<m_sepGraphNodes[ind][k];
  //     }
  //     std::cout<<" "<<std::endl;
  //     std::cout<<"Num nodes: "<<m_sepGraphNodes[ind].size() <<std::endl;
  //     std::cout<<"Num tri: "<<m_sepGraphTriangles[ind].size() <<std::endl;
  //     std::cout<<"Num directions: "<<m_sepGraphDirections[ind].size() <<std::endl;
  //   }
  // }
  // int numDoubles=0;
  // std::cout<<"Num extr vert: "<<m_extraordVertices.size()<<std::endl;
  // std::cout<<"Num extr tri: "<<m_tri.size()<<std::endl;
  // double normX=-1.0;
  // for(uint64_t l=0; l<m_extraordVertices.size(); l++){
  //   for(uint64_t t=0; t<m_extraordVertices.size(); t++){
  //     if(l!=t && isPointDuplicateVec(&(m_extraordVertices[l]), &(m_extraordVertices[t]), &normX)){
  // 	std::cout<<m_extraordVertices[l][0]<<" "<<m_extraordVertices[l][1]<<" "<<m_extraordVertices[l][2]<<std::endl;
  // 	numDoubles++;
  //     }
  //   }
  // }
  // std::cout<<"Num duplicates: "<<numDoubles<<std::endl;

  std::cout<<"collect T-junction indices"<<std::endl;
  collectTJunctionIndices();
  std::cout<<"num T-junctions: "<< m_extraordVertTjunc.size()<<std::endl;
  // killDuplicatesSepTjunction();//ALEX

  // std::cout<<"triPatches"<<std::endl;
  // std::vector<int> triPatchesIDs;
  // getTriangularPatchesIDs(&triPatchesIDs);
  // std::cout<<"num triPatches: "<< triPatchesIDs.size()<<std::endl;
  // std::cout<<"T-junction patches"<<std::endl;
  // std::vector<int> tJunctionPatchesIDs;
  // getTJunctionsPatchesIDs(&tJunctionPatchesIDs);
  // std::cout<<"num T-junction patches: "<< tJunctionPatchesIDs.size()<<std::endl;
  // for(uint64_t mt=0; mt<tJunctionPatchesIDs.size(); mt++)
  //   std::cout<<"T-junc patch ID: "<<tJunctionPatchesIDs[mt]<<std::endl;

  
  getQuadEdgesData();
  std::cout<<"block2edg"<<std::endl;
  getBlock2Edge();
  std::cout<<"edg2block"<<std::endl;
  getEdge2Block();
  std::cout<<"vert2block"<<std::endl;
  getVert2Block();
  
  // for(uint64_t t=0; t<m_mbQuads.size(); t++){
  //   std::cout<<"Block: "<<t <<" nVertices: "<<m_mbQuads[t].size()<<", nEdges: "<< m_mbBlock2Edg[t].size()<<std::endl;
  //   for(uint64_t k=0; k<m_mbQuads[t].size(); k++)
  //     std::cout << m_mbQuads[t][k] << " , " ;
  //   std::cout << std::endl;
  //   std::cout << "edges : ";
  //   for(uint64_t k=0; k<m_mbBlock2Edg[t].size(); k++)
  //     std::cout << m_mbBlock2Edg[t][k] << " , ";
  //   std::cout << std::endl;
  // }
  // for(uint64_t t=0; t<m_mbEdg2Block.size(); t++){
  //   std::cout << "edge : " << t << " nBlocks : " << m_mbEdg2Block[t].size() << std::endl;
  //   for(uint64_t k=0; k<m_mbEdg2Block[t].size(); k++)
  //     std::cout << m_mbEdg2Block[t][k] << " , ";
  //   std::cout << std::endl;
  // }
  
  dbgPosEdgData("dbgEdgData.pos"); 
  createMbTriPatchs();
  dbgPosPatchData("dbgBlockPatch.pos");
  computePatchsParametrization();
  
  std::cout<<"Start correcting blocks"<<std::endl;
  if(m_extraordVertTjunc.size()>0)
    correctInvalidBlocks();
  std::cout<<"End correcting blocks"<<std::endl; 


  
  // std::cout<<"triPatches"<<std::endl;
  // std::vector<int> triPatchesIDs;
  // getTriangularPatchesIDs(&triPatchesIDs);
  // std::cout<<"num triPatches: "<< triPatchesIDs.size()<<std::endl;
  // std::cout<<"T-junction patches"<<std::endl;
  // std::vector<int> tJunctionPatchesIDs;
  // getTJunctionsPatchesIDs(&tJunctionPatchesIDs);
  // std::cout<<"num T-junction patches: "<< tJunctionPatchesIDs.size()<<std::endl;
  // for(uint64_t mt=0; mt<tJunctionPatchesIDs.size(); mt++)
  //   std::cout<<"T-junc patch ID: "<<tJunctionPatchesIDs[mt]<<std::endl;

  
  dbgPosEdgData("dbgEdgData2.pos"); 
  createMbTriPatchs();
  dbgPosPatchData("dbgBlockPatch2.pos");
  computePatchsParametrization();
  // std::set<uint64_t> setTri;
  // for(size_t k=0;k<m_mbQuadParametrization[0].m_triangles.size();k++)
  //   setTri.insert(m_mbQuadParametrization[0].m_triangles[k]);
  // std::cout << "starting barycenter computation" << std::endl;
  // findPatchBarycenter(setTri);
  
  // //DBG CRITICAL
  // int indQuadTest=0;
  // std::vector<std::array<double,3>> physCoordLine;
  // std::vector<uint64_t> physTriLine;
  // m_mbQuadParametrization[indQuadTest].getStraigthLine(m_extraordVertices[m_mbQuads[indQuadTest][0]], m_extraordVertices[m_mbQuads[indQuadTest][2]], physCoordLine, physTriLine, 1000);
  // m_mbEdges.push_back(physCoordLine);
  // m_mbEdgesTri.push_back(physTriLine);
  // std::cout << "n points in new line: " << physCoordLine.size() << std::endl;
  // std::cout << "n tri in new line: " << physTriLine.size() << std::endl;
  // dbgPosEdgData("dbgEdgData2.pos");
  // m_mbEdges.erase(m_mbEdges.end()-1);
  // m_mbEdgesTri.erase(m_mbEdgesTri.end()-1);
  // //
  // std::vector<std::array<double, 3>> pointsOnEdg;
  // std::vector<uint64_t> trianglesOnEdg;
  // std::cout<<"grabingEdgData "<<std::endl;
  // getDataFromBlockEdgID(m_mbBlock2Edg[0][0], pointsOnEdg, trianglesOnEdg);


  
  // std::cout<<"start printing"<<std::endl;
  // uint64_t triNumX[1];
  // std::array<double, 3> pointX; pointX[0]=m_extraordVertices[17][0]; pointX[1]=m_extraordVertices[17][1]; pointX[2]=m_extraordVertices[17][2];
  // std::cout<<"PointX: "<<pointX[0]<<" "<<pointX[1]<<" "<<pointX[2]<<std::endl;
  // getTriNumFromPointCoord(pointX, m_tri, triNumX);
  // std::cout<<"triNum: "<<triNumX[0]<<std::endl;
  // std::cout<<"Printing node and tri end"<<std::endl;
  
  // --------------------------------------------------------------------------
  // std::cout<<"start printing"<<std::endl;
  // uint64_t partition=20;
  // std::array<double,3> init={{10.0,10.0,10.0}};
  // std::vector<std::array<double,3>> newLine(partition+1,init);
  // std::vector<double> hVal;
  // for(uint64_t s=0; s<m_mbEdges[0].size(); s++)
  //   hVal.push_back(1.0+s*0.1);
  // std::cout<<"length of edg: "<<m_mbEdges[0].size()<<std::endl;
  // lineDiscretization(&m_mbEdges[0], hVal, partition, &newLine);

  //new functions end
  
  
  HXT_CHECK(hxtFree(&connectedNodes));
  HXT_CHECK(hxtFree(&connectedTri));
  HXT_CHECK(hxtFree(&connectedDir));
  HXT_CHECK(hxtFree(&offsetN));
  // HXT_CHECK(hxtFree(&cleanOffsetN));
  HXT_CHECK(hxtFree(&newConnectedNodes));
  HXT_CHECK(hxtFree(&quadsWithIndices));
  HXT_CHECK(hxtFree(&nodesOnBdry));
  m_mbDecompExists=1;
  return HXT_STATUS_OK;
}

void MultiBlock::findPatchBarycenter(const std::set<uint64_t> &setTri){
  HXTEdges *edges=m_Edges;
  HXTMesh *mesh=edges->edg2mesh;
  std::vector<uint32_t> multVert(mesh->vertices.num,0);
  std::vector<uint32_t> multEdges(edges->numEdges,0);
  uint32_t nLocVertices=0;
  std::cout << "flag1" << std::endl;
  for(uint64_t t: setTri){
    for(size_t k=0;k<3;k++)
      multVert[mesh->triangles.node[3*t+k]]++;
    for(size_t k=0;k<3;k++)
      multEdges[edges->tri2edg[3*t+k]]++;
  }
  std::vector<bool> isBndVertex(mesh->vertices.num,false);
  for(size_t k=0;k<edges->numEdges;k++){
    if(multEdges[k]==1){
      isBndVertex[edges->node[2*k+0]]=true;
      isBndVertex[edges->node[2*k+1]]=true;
    }

  }
  for(size_t k=0;k<mesh->vertices.num;k++){
    if(multVert[k]>0){
      nLocVertices++;
    }
  }
  // std::vector<uint32_t> loc2GlobVert(0,nLocVertices);
  // std::vector<uint32_t> glob2LocVert((uint32_t)(-1),mesh->vertices.num);
  // size_t locId=0;
  // for(size_t k=0;k<mesh->vertices.num;k++){
  //   if(multVert[k]>0){
  //     loc2GlobVert[locId]=k;
  //     glob2LocVert[k]=locId;
  //     locId++;
  //   }
  // }
  std::cout << "flag2" << std::endl;
  typedef std::pair<double, uint32_t> weightedVertex;
  std::map<uint32_t, std::set<weightedVertex>> weightedConnectivity;
  std::map<uint32_t, double> distanceToPatchBnd;
  for(uint64_t iE=0;iE<edges->numEdges;iE++){
    if(multEdges[iE]>0){
      const double *v0 = mesh->vertices.coord + 4*edges->node[2*iE+0];
      const double *v1 = mesh->vertices.coord + 4*edges->node[2*iE+1];
      double edgeK[3]={v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
      double length=0.0;
      hxtNorm2V3(edgeK, &length);
      weightedConnectivity[edges->node[2*iE+0]].insert(weightedVertex(length,edges->node[2*iE+1]));
      weightedConnectivity[edges->node[2*iE+1]].insert(weightedVertex(length,edges->node[2*iE+0]));
      distanceToPatchBnd[edges->node[2*iE+0]]=std::numeric_limits<double>::max();
      distanceToPatchBnd[edges->node[2*iE+1]]=std::numeric_limits<double>::max();
    }
  }
  std::cout << "flag3" << std::endl;
  std::priority_queue<weightedVertex,std::vector<weightedVertex>, std::greater<weightedVertex>> priorityQueue;
  for(uint32_t k=0;k<mesh->vertices.num;k++){
    if(isBndVertex[k]){
      distanceToPatchBnd[k]=0.0;
      priorityQueue.push(weightedVertex(0.0,k));
    }
  }
  std::cout << "flag4" << std::endl;
  while(!priorityQueue.empty()){
    std::cout << "flag5" << std::endl;
    uint32_t v=priorityQueue.top().second;
    double distV=distanceToPatchBnd[v];
    priorityQueue.pop();
    for(const weightedVertex &wV: weightedConnectivity[v]){
      double dist=distanceToPatchBnd[wV.second];
      if(dist>distV+wV.first){
	distanceToPatchBnd[wV.second]=distV+wV.first;
	priorityQueue.push(weightedVertex(distanceToPatchBnd[wV.second],wV.second));
      }
    }
  }
  // const char *fileName = "patchDist.pos";
  // FILE *f = fopen(fileName,"w");
  // fprintf(f,"View \"Distance\" {\n");
  // for(const auto &kv: distanceToPatchBnd){
  //   fprintf(f,"SP(%g,%g,%g){%g};\n", mesh->vertices.coord[4*kv.first+0], mesh->vertices.coord[4*kv.first+1], mesh->vertices.coord[4*kv.first+2], kv.second);
  // }
  // fprintf(f,"};");
  // fclose(f);
}

void MultiBlock::buildTotalPatches(){
  m_totalElemPatches.clear();
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

bool MultiBlock::isInTotalPatch(uint64_t tri){
  if(std::find(m_totalElemPatches.begin(),m_totalElemPatches.end(),tri)==m_totalElemPatches.end())
    return false;
  else
    return true;
}



int MultiBlock::localIntersection2(int sepID1, int sepID2, std::vector<std::array<double,3>> *intersectionPoints,std::vector<uint64_t> *newTriangles, std::vector<std::array<double,3>> *directions, std::vector<double> *length){
  int flag=0;
  int num=0;
  int nodeExist=0;
  double point1[3]={0.}, point2[3]={0.}, point3[3]={0.}, point4[3]={0.};
  double currentIntersectionPoint[3];
  Separatrice *sep1=&(m_vectSep[sepID1]);
  Separatrice *sep2=&(m_vectSep[sepID2]);
  std::vector<uint64_t> *elements1=sep1->getPTriangles();
  std::vector<std::array<double,3>> *sepPoints1=sep1->getPCoord();
  std::vector<std::array<double,3>> *sepPoints2=sep2->getPCoord();
  std::vector<uint64_t> *elements2=sep2->getPTriangles();
  uint64_t iEnd, jEnd;
  if((*elements1)[elements1->size()-1]!=(uint64_t)-1){
    iEnd=elements1->size();
  }else{
    iEnd=elements1->size()-1;
  }
  if((*elements2)[elements2->size()-1]!=(uint64_t)-1){
    jEnd=elements2->size();
  }else{
    jEnd=elements2->size()-1;
  }
  for(uint64_t i=1; i<iEnd; i++){
    uint64_t triangle1=(*elements1)[i];
    int isInPatch=isInTotalPatch(triangle1);
    // int isInPatch=checkIfInPatch2(triangle1);
    int isInIgnoredPatch1=m_vectSep[sepID1].isInIgnoredPatch(triangle1);
    for(uint64_t j=1; j<jEnd; j++){
      // bool isBoundarySep = (sep1->isBoundary() || sep2->isBoundary());
      uint64_t triangle2=(*elements2)[j];
      int isInIgnoredPatch2=m_vectSep[sepID2].isInIgnoredPatch(triangle2);
      // if((triangle1==triangle2) && (!isInPatch || isBoundarySep || isInIgnoredPatch1 || isInIgnoredPatch2)){
      if((triangle1==triangle2) && (!isInPatch || isInIgnoredPatch1 || isInIgnoredPatch2)){
      // if(triangle1==triangle2){
	std::array<double,3> p1=(*sepPoints1)[i-1];
	std::array<double,3> p2=(*sepPoints1)[i];
	std::array<double,3> p3=(*sepPoints2)[j-1];
	std::array<double,3> p4=(*sepPoints2)[j];
	for(int k=0; k<3; k++){
	  point1[k]=p1[k];
	  point2[k]=p2[k];
	  point3[k]=p3[k];
	  point4[k]=p4[k];
	}
	// intersectionNodeForGraph(triangle1, point1, point2, point3, point4, currentIntersectionPoint, &nodeExist);
	intersectionNodeForGraph2(triangle1, point1, point2, point3, point4, currentIntersectionPoint, &nodeExist); //DBG Jovana------------
	if(nodeExist==1){
	  flag=1;
	  (*newTriangles).push_back(triangle1);
	  std::array<double,3> pFirst={{0.0,0.0,0.0}};
	  for(int s=0; s<3; s++)
	    pFirst[s]=currentIntersectionPoint[s];
	  (*intersectionPoints).push_back(pFirst);
	  std::array<double,3> b=(*sepPoints1)[i-1];
	  std::array<double,3> newDir={{0.0,0.0,0.0}};
	  double normP=-1.0;
	  if(!isPointDuplicateVec(&pFirst,&b,&normP)){ //pFirst and point b can be the same vertex
	    for(int t=0; t<3; t++){
	      newDir[t]=b[t]-pFirst[t]; 
	    }
	  }else{
	    std::array<double,3> bb=(*sepPoints1)[i];
	    for(int t=0; t<3; t++){
	      newDir[t]=pFirst[t]-bb[t]; 
	    }
	  }
	  (*directions).push_back(newDir);
	  double sum=0;
	  double length1;
	  for(uint64_t t=1;t<i; t++){
	    std::array<double,3> a=(*sepPoints1)[t-1];
	    std::array<double,3> b=(*sepPoints1)[t];
	    getLength(a, b, &length1);
	    sum=sum+length1;
	  }
	  double lengthLast;
	  getLength(p1, pFirst, &lengthLast);
	  (*length).push_back(sum+lengthLast);
	  num++;
	}
      }
    }
  }
  return flag;
}

int MultiBlock::getGraphElements(std::vector<std::array<double,3>> *nodesCoord, std::vector<uint64_t> *triangles, std::vector<std::array<double,3>> *directions, std::vector<double> *distance, std::vector<int> *offset){

  buildTotalPatches();

  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep1=&(m_vectSep[i]);
    bool isSaved1=sep1->isSaved();
    if(isSaved1){
      std::vector<std::array<double,3>> coord;
      int num=0;
      int ID1=sep1->getID();
      std::vector<uint64_t> *elements=sep1->getPTriangles();
      std::vector<std::array<double,3>> *points=sep1->getPCoord();
      (*nodesCoord).push_back((*points)[0]);
      size_t indiceBeginningNodesSep=(*nodesCoord).size()-1;
      std::array<double,3> dir={{0.0,0.0,0.0}};
      std::array<double,3> p1=(*points)[0];
      std::array<double,3> p2=(*points)[1];
      for(int m=0; m<3; m++){
      	dir[m]=p1[m]-p2[m];
      }
      (*directions).push_back(dir);
      (*triangles).push_back((*elements)[1]);
      (*distance).push_back(0.0);
      num++;
      for(uint64_t j=0; j<m_vectSep.size(); j++){
	Separatrice *sep2=&(m_vectSep[j]);
	bool isSaved2=sep2->isSaved();
	if(isSaved2 && i!=j){
	  int ID2=sep2->getID();
	  std::vector<std::array<double,3>> intersectionPoints;
	  intersectionPoints.reserve(100);
	  std::vector<uint64_t> newTriangles;
	  std::vector<std::array<double,3>> directionsNew;
	  directionsNew.reserve(100);
	  std::vector<double> length;
	  length.reserve(1000);
	  int isIntersecting= localIntersection2(ID1, ID2, &intersectionPoints, &newTriangles, &directionsNew, &length);
	  if(intersectionPoints.size()!=newTriangles.size() && intersectionPoints.size()!=directionsNew.size() && intersectionPoints.size()!=length.size()){
	    std::cout << "Pb size intersection points triangles" << std::endl;
	    exit(0);
	  }
	  if(isIntersecting){
	    
	    for(uint64_t l=0; l<intersectionPoints.size(); l++){
	      double norm=0.0;
	      if(!isPointDuplicateVec(&(*nodesCoord)[indiceBeginningNodesSep], &(intersectionPoints[l]), &norm)){//DBG has to be checked for separatrices traced from random point of the boundary, toward inside the domain
		(*nodesCoord).push_back(intersectionPoints[l]);
		(*directions).push_back(directionsNew[l]);
		(*triangles).push_back(newTriangles[l]);
		(*distance).push_back(length[l]);
		num++;
	      }
	    }
	  }
	}
      } 
 
      // adding last point
      if(((*elements)[elements->size()-1]!=(uint64_t)-1) && !(sep1->getIsLimitCycle())){ //not to add T-junction twice (duplicates in sep graph data)
	uint64_t indP=points->size();
	uint64_t indE=elements->size();
	std::array<double,3> point=(*points)[indP-1];
	(*nodesCoord).push_back(point);
	uint64_t tri=(*elements)[indE-1];
	(*triangles).push_back(tri);
	std::array<double,3> dir={{0.0,0.0,0.0}};
	std::array<double,3> point2=(*points)[indP-2];
	for(int m=0; m<3; m++)
	  dir[m]=point2[m]-point[m];
	(*directions).push_back(dir);
	double sum=0;
	for(uint64_t t=1; t<points->size(); t++){
	  double length=-1;
	  getLength((*points)[t-1], (*points)[t], &length);
	  sum=sum+length;
	}
	(*distance).push_back(sum);
	num++;
      }
      (*offset).push_back(num);
    }
  }
  return 1;
}

HXTStatus MultiBlock::hxtWriteGraphNodes(std::vector<std::array<double,3>> nodesCoord, const char *fileName){
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"Graph nodes\" {\n");
  for(uint64_t i=0; i<nodesCoord.size(); i++){
    int color=static_cast<int>(i);
    std::array<double,3> nodes=nodesCoord[i];
    fprintf(f,"SP(%g,%g,%g){%i};\n", nodes[0], nodes[1], nodes[2], color);
  }
  fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

int MultiBlock::isPointSingularity(double *point1){
  int indicator=0;
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    std::array<double,3> singCoord=s->getCoord();
    double point2[3]={0.};
    double norm;
    for(int j=0; j<3; j++)
      point2[j]=singCoord[j];
    if(isPointDuplicate(point1, point2, &norm)){
      indicator=1;
    }
  }
  return indicator;
}

int MultiBlock::graphReordering(std::vector<std::array<double,3>> nodesCoord,std::vector<uint64_t> triangles, std::vector<std::array<double,3>> directions, std::vector<double> distance, std::vector<int> offset, std::vector<std::array<double,3>> *newNodes, std::vector<uint64_t> *newTriangles, std::vector<std::array<double,3>> *newDirections, std::vector<double> *newDistances, std::vector<int> *newOffsetGraph){

  double min=10000;
  int countID=0; //on which offset we are
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep1=&(m_vectSep[i]);
    if(sep1->isSaved()){
      // int ID=sep1->getID();
      int length=offset[countID]; 
      int *triCandidate;
      HXT_CHECK(hxtMalloc(&triCandidate,length*sizeof(uint64_t)));
      double *pointCandidate;
      HXT_CHECK(hxtMalloc(&pointCandidate,3*length*sizeof(double)));
      double *distanceCandidate;
      HXT_CHECK(hxtMalloc(&distanceCandidate,length*sizeof(double)));
      double *directionsCandidate;
      HXT_CHECK(hxtMalloc(&directionsCandidate,3*length*sizeof(double)));
      int *triSorted;
      HXT_CHECK(hxtMalloc(&triSorted,length*sizeof(uint64_t)));
      double *pointSorted;
      HXT_CHECK(hxtMalloc(&pointSorted,3*length*sizeof(double)));
      double *disSorted;
      HXT_CHECK(hxtMalloc(&disSorted,length*sizeof(double)));
      double *directionsSorted;
      HXT_CHECK(hxtMalloc(&directionsSorted,3*length*sizeof(double)));
      double *disProvisory;
      HXT_CHECK(hxtMalloc(&disProvisory,length*sizeof(double)));
      int *tri1;
      HXT_CHECK(hxtMalloc(&tri1,length*sizeof(uint64_t)));
      double *point1;
      HXT_CHECK(hxtMalloc(&point1,3*length*sizeof(double)));
      double *dis1;
      HXT_CHECK(hxtMalloc(&dis1,length*sizeof(double)));
      double *directions1;
      HXT_CHECK(hxtMalloc(&directions1,3*length*sizeof(double))); 
      int count=0;
      for(int k=0; k<countID; k++){
	count=count+offset[k];
      }
      for(int j=0; j<length; j++){
	triCandidate[j]=triangles[count+j];
	distanceCandidate[j]=distance[count+j];
	disProvisory[j]=distance[count+j];
	std::array<double,3> point=nodesCoord[count+j];
	std::array<double,3> dir=directions[count+j];
	for(int m=0; m<3; m++){
	  pointCandidate[3*j+m]=point[m];
	  directionsCandidate[3*j+m]=dir[m];
	}
      }
      qsort(distanceCandidate, length, sizeof(double), comparatorDouble);
      int *distancesUsed;
      HXT_CHECK(hxtMalloc(&distancesUsed, length*sizeof(int)));
      for(int s=0; s<length; s++){
	distancesUsed[s]=0;
      }
      int num=0;
      for(int k=0; k<length; k++){
      	for(int j=0; j<length; j++){
	  if(distancesUsed[j]!=1 && num!=length){
      	    if(distanceCandidate[k]==disProvisory[j]){
      	      // triSorted[num]=triangles[j+count];
	      triSorted[num]=triCandidate[j];
      	      disSorted[num]=disProvisory[j];
      	      for(int m=0; m<3; m++){
		pointSorted[3*num+m]=pointCandidate[3*j+m];
      		directionsSorted[3*num+m]=directionsCandidate[3*j+m];
      	      }
      	      distancesUsed[j] = 1;
      	      num++;
      	    }
      	  }
      	}
      }
  	
      HXT_CHECK(hxtFree(&distancesUsed));
      double normD=-1.;
      int kStart=-1;
      int kEnd=-1;
      if(isPointDuplicate(pointCandidate,pointCandidate+3*(length-1),&normD)){
	if(length==1){
	  sep1->setLoopType(0); //sep containing just 1 triangle
	  kStart=0;
	  kEnd=static_cast<int>(length);
	}
	else{
	  sep1->setLoopType(1);
	  kStart=1; //to discard first and last point - disturbing connectivity
	  kEnd=static_cast<int>(length-1);
	}
	// if(isPointSingularity(pointCandidate)){//DBG it seems we have to check if it's a corner too
	std::array<double,3> vecPointCandidate = {pointCandidate[0],pointCandidate[1],pointCandidate[2]};//DBG
	if(isPointSingularityOrCornerVec(&vecPointCandidate)){ //DBG
	  if(length==1){
	    sep1->setLoopType(0); //sep containing just 1 triangle and starting from sing
	    kStart=0;
	    kEnd=static_cast<int>(length);
	  }
	  else{
	    sep1->setLoopType(2);
	    kStart=0; //torus
	    kEnd=static_cast<int>(length);
	  }
	}
      }
      else{
	sep1->setLoopType(0);
	kStart=0;
	kEnd=static_cast<int>(length);
      }
      
      int num1=0;
      int isLoop=-1;
      for(int k=kStart; k<kEnd; k++){
	tri1[num1]=triSorted[k];
	isLoop=sep1->getLoopType();
	if(isLoop==1){ //shifting
	  dis1[num1]=disSorted[k]-disSorted[kStart];
	}else{
	  dis1[num1]=disSorted[k];
	}
	for(int m=0; m<3; m++){
	  point1[3*num1+m]=pointSorted[3*k+m];
	  directions1[3*num1+m]=directionsSorted[3*k+m];
	}
	num1++;
      }
      if(isLoop==1){ 
	dis1[0]=disSorted[length-1]; 
      }
  
      (*newOffsetGraph).push_back(num1);
      
      //getting shortest quad edge
      if(dis1[0]==0){ //general case
	for(int m=1; m<num1; m++){
	  double a=dis1[m]-dis1[m-1];
	  if(a<min){
	    min=a;
	  }
	}
      }else{ //loop==1 case
	for(int m=2; m<num1; m++){
	  double a=dis1[m]-dis1[m-1];
	  if(a<min){
	    min=a;
	  }
	}
	double b=dis1[0]-dis1[num1-1];
	if(b<min){
	  min=b;
	}
      }

      for(int j=0; j<num1; j++){ // need a new length
	(*newTriangles).push_back(tri1[j]);
	(*newDistances).push_back(dis1[j]);
	std::array<double,3> point={{0.0,0.0,0.0}};
	std::array<double,3> dir={{0.0,0.0,0.0}};
	for(int m=0; m<3;m++){
	  point[m]=point1[3*j+m];
	  dir[m]=directions1[3*j+m];
	}
	(*newNodes).push_back(point);
	(*newDirections).push_back(dir);
      }
  
      countID++;
      
      HXT_CHECK(hxtFree(&point1));
      HXT_CHECK(hxtFree(&pointCandidate));
      HXT_CHECK(hxtFree(&pointSorted));
      HXT_CHECK(hxtFree(&dis1));
      HXT_CHECK(hxtFree(&disProvisory));
      HXT_CHECK(hxtFree(&distanceCandidate));
      HXT_CHECK(hxtFree(&disSorted));
      HXT_CHECK(hxtFree(&tri1));
      HXT_CHECK(hxtFree(&triCandidate));
      HXT_CHECK(hxtFree(&triSorted));
      HXT_CHECK(hxtFree(&directionsCandidate));
      HXT_CHECK(hxtFree(&directionsSorted));
      HXT_CHECK(hxtFree(&directions1));
    }
  }
  m_minEdgLength=min; //probably not needed!!!
  
  return 1;
}

int MultiBlock::fillGraphStruct(std::vector<std::array<double,3>> newNodes, std::vector<uint64_t> newTriangles,  std::vector<int> newOffset){

  HXTEdges *edges=m_Edges;
  int num=0;
  for(uint64_t i=0; i<newOffset.size(); i++){
    num=num+newOffset[i];
  }
  uint64_t numCornerSing=m_vectCorner.size()+m_vectSing.size();
  int initAlloc=num+numCornerSing;
  double *provisoryPoints;
  HXT_CHECK(hxtMalloc(&provisoryPoints,3*initAlloc*sizeof(double)));

  //check if its disabled?
  for(uint64_t i=0; i<m_vectCorner.size(); i++){
    Corner *c=&(m_vectCorner[i]);
    std::array<double,3> coord=c->getCoord();
    m_extraordVertices.push_back(coord);
    std::vector<uint64_t> triangles=c->getTriangles();
    m_tri.push_back(triangles[0]);
    for(int j=0; j<3; j++){
      provisoryPoints[3*i+j]=coord[j];
    } 
  }
  for(uint64_t i=0; i<m_vectSing.size(); i++){
    Singularity *s=&(m_vectSing[i]);
    if(!(s->isDisabled())){ //NEW
      std::array<double,3> coord=s->getCoord();
      m_extraordVertices.push_back(coord);

      uint64_t sepEdg=s->getGlobalEdg();
      // uint64_t tri=edges->edg2tri[2*sepEdg+0];//ALEX: to change (not good anymore)
      std::vector<uint64_t> sepTri=s->getPatch();
      uint64_t tri=sepTri[0];
      m_tri.push_back(tri);
      uint64_t count=m_vectCorner.size();
      for(int j=0; j<3; j++){
	provisoryPoints[3*(i+count)+j]=coord[j];
      }
    }
  }
  for(uint64_t i=numCornerSing; i<numCornerSing+num; i++){
    std::array<double,3> point=newNodes[i-numCornerSing];
    for(int j=0; j<3; j++){
      provisoryPoints[3*i+j]=point[j];
    }
  }

  for(int i=0; i<num; i++){
    int added = addInPointsVectIfNotPresent2(&m_extraordVertices, newNodes[i]);
    // addInUnsignedIntVectIfNotPresent(&m_tri, newTriangles[i]);
    if(added){
      m_tri.push_back(newTriangles[i]);
    }
  }
  
  HXT_CHECK(hxtFree(&provisoryPoints));
  return 1;
}

int MultiBlock:: putIDsInGraph(std::vector<std::array<double,3>> newNodes, std::vector<std::array<double,3>> newDirections,std::vector<uint64_t> newTriangles, std::vector<int> newOffset){

  int numCleanedSep=0;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved())
      numCleanedSep++;
  }
  for(int i=0; i<numCleanedSep; i++){
    int num=0;
    int count=0;
    for(int m=0; m<i; m++){
      count=count+newOffset[m];
    }
    int length=newOffset[i];
    int *nodesID;
    HXT_CHECK(hxtMalloc(&nodesID, 2*length*sizeof(int)));
    int *trianglesID;
    HXT_CHECK(hxtMalloc(&trianglesID, 2*length*sizeof(uint64_t)));
    double *directionsID1;
    HXT_CHECK(hxtMalloc(&directionsID1, 2*3*(length)*sizeof(double)));
    for(int j=0; j<length; j++){
      for(uint64_t k=0; k<m_extraordVertices.size(); k++){
	double point1[3], point2[3];
	std::array<double,3> p1=newNodes[j+count];
	std::array<double,3> p2=m_extraordVertices[k];
	for(int t=0; t<3; t++){
	  point1[t]=p1[t];
	  point2[t]=p2[t];
	}
	double norm;
	if(isPointDuplicate(point1, point2, &norm)){
	  nodesID[num]=k;
	  trianglesID[num]=newTriangles[j+count];
	  num++;
	}
      }
    }
    std::vector<std::array<double,3>> vectDirectionsID1;
    for(int z=0;z<newOffset[i];z++){
      std::array<double,3> dir=newDirections[z+count];
      //addInPointsVectIfNotPresent2(&vectDirectionsID1, dir);
      vectDirectionsID1.push_back(dir);
    }
  
    std::vector<uint64_t> vectTrianglesID;
    std::vector<int> vectNodesID;
    for(int s=0; s<num;s++){
      //addInUnsgnIntVectIfNotPresent(&vectTrianglesID, trianglesID[s]);
      //addInIntVectIfNotPresent(&vectNodesID, nodesID[s]);
      vectTrianglesID.push_back(trianglesID[s]);
      vectNodesID.push_back(nodesID[s]);
    }

    m_sepGraphNodes.push_back(vectNodesID);
    // std::cout << "sepCleanID : " << i << std::endl;
    // std::cout << "nSepGraphNodes : " << vectNodesID.size() << std::endl;
    m_sepGraphTriangles.push_back(vectTrianglesID);
    // std::cout << "nSepGraphTriangles : " << vectTrianglesID.size() << std::endl;
    m_sepGraphDirections.push_back(vectDirectionsID1);
    // std::cout << "nSepGraphDirections : " << vectDirectionsID1.size() << std::endl;
    

    HXT_CHECK(hxtFree(&nodesID));
    HXT_CHECK(hxtFree(&trianglesID));
    HXT_CHECK(hxtFree(&directionsID1));
  }

  // HXTEdges *edges=m_Edges;
  // HXTMesh *mesh = edges->edg2mesh;
  // FILE *f = fopen("triDBG.pos","w");
  // fprintf(f,"View \"Triangles\" {\n");
  // int numExtr=0;
  // for(uint64_t k=0; k<m_sepGraphTriangles.size(); k++){
  //   for(uint64_t l=0; l<m_sepGraphTriangles[k].size(); l++){
  //     fprintf(f,"ST(");
  //     numExtr++;
  //     uint32_t vtri[3] = {mesh->triangles.node[3*m_sepGraphTriangles[k][l]+0],mesh->triangles.node[3*m_sepGraphTriangles[k][l]+1],mesh->triangles.node[3*m_sepGraphTriangles[k][l]+2]};
  //     for(uint32_t j=0; j<3; j++){
  // 	fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
  // 	if(j<2)
  // 	  fprintf(f,",");
  //     }
  //     fprintf(f,")");
  //     fprintf(f,"{");
  //     fprintf(f,"%i, %i, %i",numExtr,numExtr,numExtr);
  //     fprintf(f,"};\n");    
  //   }
  // }
  // fprintf(f,"};");
  // fclose(f);
  
  return 1;
}

int MultiBlock::nodesConnectivity(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets)
{ 
  int num=0;
  int num1=0;
  uint64_t numNodes= m_extraordVertices.size();
  int numCleanedSep=0;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved())
      numCleanedSep++;
  }
  for(uint64_t i=0; i<numNodes; i++){
    int node1=static_cast<int>(i);
    int num2=0;
    connectedNodes[num1]=node1;
    connectedTri[num1]=m_tri[i];
    for(int s=0; s<3; s++){
      connectedDir[3*num1+s]=0.0;
    }
    num1++;
    num2++;
    for(int k=0; k<numCleanedSep; k++){ 
      std::vector<int> *nodes=&(m_sepGraphNodes[k]);
      std::vector<uint64_t> *tri=&(m_sepGraphTriangles[k]);
      std::vector<std::array<double,3>> *dir=&(m_sepGraphDirections[k]);
      uint64_t sizeElementsPerSep=nodes->size();
      for(uint64_t m=0; m<sizeElementsPerSep; m++){ //(-1?!)
	int node2=(*nodes)[m];
	if(node1==node2){
	  // std::cout << "extr vert: " << node1 << std::endl;
	  // std::cout << "on cleanSep: " << k << std::endl;
	  if(checkIfLoop(k)){
	    if(m==0){
	      connectedNodes[num1]=(*nodes)[m+1];
	      connectedTri[num1]=(*tri)[m+1];
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=-d[s];
	      }
	      num1++;
	      num2++;
	      if(checkIfLoop(k)==1){
		int end=sizeElementsPerSep-1;
		connectedNodes[num1]=(*nodes)[end];
		connectedTri[num1]=(*tri)[end];
		for(int s=0; s<3; s++){
		  connectedDir[3*num1+s]=d[s];
		}
		num1++;
		num2++;
	      }else{
		int end=sizeElementsPerSep-1;
		connectedNodes[num1]=(*nodes)[end-1];
		connectedTri[num1]=(*tri)[end-1];
		std::array<double,3> d2=(*dir)[end];
		for(int s=0; s<3; s++){
		  connectedDir[3*num1+s]=d2[s];
		}
		num1++;
		num2++;
	      }
	    }else if(m==(sizeElementsPerSep-1) && checkIfLoop(k)==1){
	      connectedNodes[num1]=(*nodes)[m-1];
	      connectedTri[num1]=(*tri)[m-1];
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=d[s];
	      }
	      num1++;
	      num2++;
	      int start=0;
	      connectedNodes[num1]=(*nodes)[start];
	      connectedTri[num1]=(*tri)[start];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=-d[s];
	      }
	      num1++;
	      num2++;
	    }// else if(m==(sizeElementsPerSep-1) && checkIfLoop(k)==2){
	    //   int end=sizeElementsPerSep-1;
	    //   connectedNodes[num1]=(*nodes)[end-1];
	    //   connectedTri[num1]=(*tri)[end-1];
	    //   std::array<double,3> d2=(*dir)[end];
	    //   for(int s=0; s<3; s++){
	    // 	connectedDir[3*num1+s]=d2[s];
	    //   }
	    //   num1++;
	    //   num2++;
	    // }
	    else if(m!=(sizeElementsPerSep-1)){
	      connectedNodes[num1]=(*nodes)[m-1];
	      connectedTri[num1]=(*tri)[m-1];
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=d[s];
	      }
	      num1++;
	      num2++;
	      connectedNodes[num1]=(*nodes)[m+1];
	      connectedTri[num1]=(*tri)[m+1];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=-d[s];
	      }
	      num1++;
	      num2++;   
	    }
	    else{
	      std::cout<<"Mistake in connectivity nodes!"<<std::endl;
	    }
	  }else{
	    if(m==0){
	      if(sizeElementsPerSep>1){
		connectedNodes[num1]=(*nodes)[m+1];
		connectedTri[num1]=(*tri)[m+1];
	      }else{
		connectedNodes[num1]=(*nodes)[m];
		connectedTri[num1]=(*tri)[m];
	      }
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=-d[s];
	      }
	      num1++;
	      num2++;
	    }else if(m==sizeElementsPerSep-1){
	      if(sizeElementsPerSep>1){
		connectedNodes[num1]=(*nodes)[m-1];
		connectedTri[num1]=(*tri)[m-1];
	      }else{
		connectedNodes[num1]=(*nodes)[m];
		connectedTri[num1]=(*tri)[m];
	      }
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=d[s];
	      }
	      num1++;
	      num2++;   
	    }else{
	      if(sizeElementsPerSep>1){
		connectedNodes[num1]=(*nodes)[m-1];
		connectedTri[num1]=(*tri)[m-1];
	      }else{
		connectedNodes[num1]=(*nodes)[m];
		connectedTri[num1]=(*tri)[m];
	      }
	      std::array<double,3> d=(*dir)[m];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=d[s];
	      }
	      num1++;
	      num2++;
	      connectedNodes[num1]=(*nodes)[m+1];
	      connectedTri[num1]=(*tri)[m+1];
	      for(int s=0; s<3; s++){
		connectedDir[3*num1+s]=-d[s];
	      }
	      num1++;
	      num2++;
	    }	
	  }
	}
      }
    }
    offset[num]=num2;
    num++;
  }
  *numOffsets=num;

  return 1;
}

int MultiBlock::checkIfLoop(int cleanSepInd){
  int ID=-1;
  getSepIDFromCleanedSepInd(cleanSepInd, &ID);
  Separatrice *sep=&(m_vectSep[ID]);
  int isLoop=sep->getLoopType();

  return isLoop;
}

int MultiBlock::killDuplicates(std::vector<std::vector<int>> graphConnectedNodes, std::vector<std::vector<int>> *cleanGraphConnectedNodes,  int *cleanOffset){
  for(uint64_t i=0; i<graphConnectedNodes.size(); i++){
    std::vector<int> cleanNodes;
    for(uint64_t j=0; j<graphConnectedNodes[i].size(); j++)
      addInIntVectIfNotPresent(&cleanNodes, graphConnectedNodes[i][j]);
    (*cleanGraphConnectedNodes).push_back(cleanNodes);
    cleanOffset[i]=(int)cleanNodes.size();
  }
  return 1;
}

int MultiBlock::killDuplicatesSepTjunction(){
  for(size_t k=0;k<m_sepGraphNodes.size();k++){
    if(m_sepGraphNodes[k][m_sepGraphNodes[k].size()-1]==m_sepGraphNodes[k][m_sepGraphNodes[k].size()-2]){
      m_sepGraphNodes[k].pop_back();
      m_sepGraphTriangles[k].pop_back();
      m_sepGraphDirections[k].pop_back();
    }
  }
  return 1;
}


int MultiBlock::graphNodesOnBdry(int *nodesOnBdry, int *sizeNodesOnBdry){
  std::vector<int> vect;
  vect.reserve(10000);
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    bool isSaved=sep->isSaved();
    bool isBoundarySep=sep->isBoundary();
    if(isSaved && isBoundarySep){
      int ID=sep->getID();
      int ind=-1;
      getCleanedSepIndFromSepID(ID, &ind);
      std::vector<int> nodes=m_sepGraphNodes[ind];
      for(uint64_t j=0; j<nodes.size();j++){
	addInIntVectIfNotPresent(&vect, nodes[j]);
      }
    }
  }
  for(uint64_t i=0; i<vect.size(); i++){
    nodesOnBdry[i]=vect[i];
    m_extraordVertBdry.push_back(vect[i]);
  }
  *sizeNodesOnBdry=vect.size();
  
  return 1;
}

int MultiBlock::getCleanedSepIndFromSepID(int ID, int *ind){
  *ind=-1;
  std::vector<int> existingSep;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    int sepID=sep->getID();
    bool exist=sep->isSaved();
    if(exist)
      existingSep.push_back(sepID);
  }
  for(uint64_t i=0; i<existingSep.size(); i++){
    if(ID==existingSep[i]) 
      *ind=static_cast<int>(i);
  }
    
  return 1;
}

int MultiBlock::putCleanQuadsInStruct(int *quadsWithIndices, int *sizesQuads, int *numQuads){
  for(int i=0; i<*numQuads; i++){
    int sizeQuadNodes=sizesQuads[i];
    int *quadIndices;
    HXT_CHECK(hxtMalloc(&quadIndices, (sizeQuadNodes)*sizeof(int)));
    int count=0;
    for(int m=0; m<i; m++){
      count+=sizesQuads[m];
    }
    for(int j=0; j<sizesQuads[i]; j++){
      quadIndices[j]=quadsWithIndices[j+count];
    }
    if(keepTheQuad(quadIndices, &sizeQuadNodes)){ 
    //if(i==0){ //for 1 quad only
       // std::cout << "kept " << std::endl;    
      std::vector<int> indices;
      for(int s=0; s<sizeQuadNodes-1; s++)
	indices.push_back(quadIndices[s]);
      (m_mbQuads).push_back(indices);
    }    
    HXT_CHECK(hxtFree(&quadIndices));
  }
  return 1;
}

int MultiBlock::keepTheQuad(int *quadIndices, int *sizeQuadNodes){
  int indicator=0;
  int ID=-1,  num=0, sepInd=-1;
  std::vector<int> sepEdges;
  sepEdges.reserve(10);
  for(int j=1; j<*sizeQuadNodes; j++){
    int dirSign=0;
    sepInd=getSepCleanIDfrom2extVert(quadIndices[j-1],quadIndices[j],dirSign);
    getSepIDFromCleanedSepInd(sepInd, &ID);
    if(ID!=-1){
      sepEdges.push_back(ID);
      Separatrice *s=&(m_vectSep[ID]);
      if(s->isBoundary())
	num++;
    }
  }
  if(sepEdges.size()!=(uint64_t)num) //DBG JOVANA: check the nodes as well
    indicator=1;
 
  return indicator;
}

int MultiBlock::getSepCleanIDfrom2extVert(int ind1, int ind2, int &direction){
  for(uint64_t i=0;i<m_sepGraphNodes.size();i++){
    std::vector<int> sepByExtrVert=m_sepGraphNodes[i];
    for(uint64_t l=0;l<sepByExtrVert.size()-1;l++){
      if((sepByExtrVert[l]==ind1&&(sepByExtrVert[l+1]==ind2))){
	direction=1;
	return i;
      }
      if((sepByExtrVert[l]==ind2&&(sepByExtrVert[l+1]==ind1))){
	direction=-1;
	return i;
      }
    }
  }
  return -1;
}

int MultiBlock::getSepIDFromCleanedSepInd(int ind, int *ID){
  *ID=-1;
  std::vector<int> existingSep;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
     Separatrice *sep=&(m_vectSep[i]);
     int sepID=sep->getID();
     bool exist=sep->isSaved();
     if(exist)
       existingSep.push_back(sepID);
  }
  for(uint64_t i=0; i<existingSep.size(); i++){
    if(ind==static_cast<int>(i))
      *ID=existingSep[i];
  }
    
  return 1;
}

int MultiBlock::isPointSingularityOrCornerVec(std::array<double,3> *point){
  int indicator=0;
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
      indicator=1;
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
      indicator=1;
    }
  }
  return indicator;
}

int MultiBlock::getQuadEdgesData(){
  int numCleanedSep=0;
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved())
      numCleanedSep++;
  }
  for(int i=0; i<numCleanedSep; i++){
    int ID=-1;
    getSepIDFromCleanedSepInd(i, &ID);
    Separatrice *sep=&(m_vectSep[ID]);
    int isLoop=sep->getLoopType();
    std::vector<std::array<double,3>> sepNodeCoord=sep->getCoord();
    std::vector<uint64_t> sepTriangles=sep->getTriangles();
    std::vector<uint64_t> triangles=m_sepGraphTriangles[i];
    std::vector<int> nodes=m_sepGraphNodes[i];
    for(uint64_t j=0; j<nodes.size()-1; j++){
      std::vector<std::array<double,3>> nodeCoord;
      std::vector<uint64_t> vectTri;
      uint64_t triStart=triangles[j];
      uint64_t triEnd=triangles[j+1];
      uint64_t start=-2;
      uint64_t end=-2;
      for(uint64_t s=0; s<sepTriangles.size(); s++){ 
	if(triStart==sepTriangles[s])
	  start=s;
	if(triEnd==sepTriangles[s])
	  end=s;
      }
      std::array<double,3> point1=m_extraordVertices[nodes[j]];
      std::array<double,3> point2=m_extraordVertices[nodes[j+1]];
      if(j==0 && (isLoop!=1))
	start=0;
      // adding first  point if its not a singularity
      if(!isPointSingularityOrCornerVec(&point1)){
	nodeCoord.push_back(point1);
	vectTri.push_back(m_tri[nodes[j]]);
      }
      for(uint64_t k=start; k<end; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
	if(sepTriangles[k]!=(uint64_t)(-1))
	  vectTri.push_back(sepTriangles[k]);
	else
	  vectTri.push_back(m_tri[nodes[j]]);
      }
      nodeCoord.push_back(point2);
      m_mbEdges.push_back(nodeCoord);
      vectTri.push_back(sepTriangles[end]);
      m_mbEdgesTri.push_back(vectTri);
    }
    if(isLoop==1){ //adding the last edge
      std::vector<std::array<double,3>> nodeCoord;
      uint64_t start=-2;
      uint64_t end=-2;
      uint64_t triStart=triangles[triangles.size()-1];
      uint64_t triEnd=triangles[0];
      for(uint64_t s=0; s<sepTriangles.size(); s++){ 
	if(triStart==sepTriangles[s])
	  start=s;
	if(triEnd==sepTriangles[s])
	  end=s;
      }
      std::array<double,3> point1=m_extraordVertices[nodes[nodes.size()-1]];
      std::array<double,3> point2=m_extraordVertices[nodes[0]];
      std::vector<uint64_t> vectTri;
      // adding first point if its not a singularity
      if(!isPointSingularityOrCornerVec(&point1)){
	nodeCoord.push_back(point1);
	vectTri.push_back(m_tri[nodes[nodes.size()-1]]);
      }
      uint64_t last=sepNodeCoord.size(); //different indice but the same node as for first ind=0
      for(uint64_t k=start; k<last; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
	vectTri.push_back(sepTriangles[k]);
      }
      for(uint64_t k=1; k<end; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
	vectTri.push_back(sepTriangles[k]);
      }
      nodeCoord.push_back(point2);
      m_mbEdges.push_back(nodeCoord);
      vectTri.push_back(sepTriangles[end]);
      m_mbEdgesTri.push_back(vectTri);	    
    }
  }

  return 1;
}

int MultiBlock::getBlock2Edge(){
  m_mbBlock2Edg.clear();
  std::array<double,3> firstPoint={0.,0.,0.};
  std::array<double,3> lastPoint={0.,0.,0.};
  for(uint64_t i=0; i<m_mbQuads.size(); i++){
    std::vector<uint64_t> blockEdges;
    std::vector<std::array<double,3>> pointsCoord;
    for(uint64_t s=0; s<m_mbQuads[i].size(); s++)
      pointsCoord.push_back(m_extraordVertices[m_mbQuads[i][s]]);
    for(uint64_t k=0; k<pointsCoord.size()-1;k++){
      for(uint64_t j=0; j<m_mbEdges.size(); j++){ //DBG
	// if(m_mbEdges[j].size()>0){
	  firstPoint=m_mbEdges[j][0];
	  lastPoint=m_mbEdges[j][m_mbEdges[j].size()-1];
	  double norm=-1.;
	  if((isPointDuplicateVec(&firstPoint, &pointsCoord[k], &norm) && isPointDuplicateVec(&lastPoint, &pointsCoord[k+1], &norm)) ||
	     (isPointDuplicateVec(&firstPoint, &pointsCoord[k+1], &norm)&& isPointDuplicateVec(&lastPoint, &pointsCoord[k], &norm))){
	    blockEdges.push_back(j);
	  }
	// }
      }
    }
    for(uint64_t j=0; j<m_mbEdges.size(); j++){
      // if(m_mbEdges[j].size()>0){ //DBG
	firstPoint=m_mbEdges[j][0];
	lastPoint=m_mbEdges[j][m_mbEdges[j].size()-1];
	double norm=-1.;
	if((isPointDuplicateVec(&firstPoint, &pointsCoord[0], &norm) && isPointDuplicateVec(&lastPoint, &pointsCoord[pointsCoord.size()-1], &norm)) ||
	   (isPointDuplicateVec(&firstPoint, &pointsCoord[pointsCoord.size()-1], &norm)&& isPointDuplicateVec(&lastPoint, &pointsCoord[0], &norm)))
	  blockEdges.push_back(j);
      }
      m_mbBlock2Edg.push_back(blockEdges);
    // }
  }

  return 1;
}


int MultiBlock::getEdge2Block(){
  m_mbEdg2Block.clear();
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    std::vector<uint64_t>  qVal;
    for(uint64_t j=0; j<m_mbQuads.size(); j++){
      for(uint64_t k=0; k<m_mbBlock2Edg[j].size(); k++){
	if(m_mbBlock2Edg[j][k]==i){ 
	  qVal.push_back(j);
	}
      }   
    } 
    m_mbEdg2Block.push_back(qVal);
  }
  return 1;
}


HXTStatus MultiBlock::collectTJunctionIndices(){
  m_extraordVertTjunc.clear();
  for(uint64_t i=0; i<m_vectSep.size(); i++){
    Separatrice *sep=&(m_vectSep[i]);
    if(sep->isSaved() && sep->getIsLimitCycle()){
      int ind=-1;
      int sepID=sep->getID();
      getCleanedSepIndFromSepID(sepID, &ind);
      std::vector<int> extraVertIndices;
      extraVertIndices = m_sepGraphNodes[ind];
      m_extraordVertTjunc.push_back(extraVertIndices[extraVertIndices.size()-1]);
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::isExtrVertOnBdry(int ind, int *isBdry){
  *isBdry=0;
  if(m_extraordVertBdry.size()>0){
    for(uint64_t i=0; i<m_extraordVertBdry.size(); i++){
      if(ind == m_extraordVertBdry[i])
	*isBdry=1;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::isExtrVertTjunction(int ind, int *isTjunction){
  *isTjunction=0;
  if(m_extraordVertTjunc.size()>0){
    for(uint64_t i=0; i<m_extraordVertTjunc.size(); i++){
      if(ind == m_extraordVertTjunc[i])
	*isTjunction=1;
    }
  }
   
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::getTriangularPatchesIDs(std::vector<int> *triPatchesIDs){
  for(uint64_t i=0; i<m_mbQuads.size(); i++){
    if(m_mbQuads[i].size()==3)
      triPatchesIDs->push_back(i);
  }

  return HXT_STATUS_OK;
}

double MultiBlock::getDistanceBetweeenTwoExtrVert(int sepIDNoLimCyc, int extrVertID, int tJuncVertID1){

  uint64_t startTriNum = m_tri[extrVertID];
  uint64_t endTriNum = m_tri[tJuncVertID1];
  int start, end;
  std::array<double,3> startPointCoord = m_extraordVertices[extrVertID];
  std::array<double,3> endPointCoord = m_extraordVertices[tJuncVertID1];
  int ind=-1;
  getCleanedSepIndFromSepID(sepIDNoLimCyc, &ind);
  Separatrice *sep=&(m_vectSep[sepIDNoLimCyc]);
  std::vector<uint64_t> *triangles = sep->getPTriangles();
  std::vector<std::array<double,3>> *pointCoord = sep->getPCoord();
  for(uint64_t i=0; i<triangles->size(); i++){
    if(startTriNum == (*triangles)[i])
      start = (int) i;
    if(endTriNum == (*triangles)[i])
      end = (int) i;
  }

  double distance=0.0;
  double sum=0;
  for(int j=start; j<end-1; j++){
    getLength((*pointCoord)[j],  (*pointCoord)[j+1], &sum);
    distance+=sum;
  }
  getLength((*pointCoord)[end-1],endPointCoord, &sum);
  distance+=sum;
  
  
  return distance;
}

int MultiBlock::getBlockIDFromVertInd(int v1, int v2, int v3, int *blockID){
  int flag1=0; int flag2=0; int flag3=0;
  
  if(v1!=-1 && v2!=-1 && v3!=-1 && v1!=v2 && v1!=v3 && v2!=v3){
    for(uint64_t s=0; s<m_mbQuads.size();s++){
      if(flag1==0 || flag2==0 || flag3==0){
	flag1=0; flag2=0; flag3=0;
	for(uint64_t m=0; m<m_mbQuads[s].size();m++){
	  if(v1 == m_mbQuads[s][m])
	    flag1=1;
	  if(v2 == m_mbQuads[s][m])
	    flag2=1;
	  if(v3 == m_mbQuads[s][m])
	    flag3=1;
	}
	if(flag1==1 && flag2==1 && flag3==1)
	  *blockID=s;
      }
    }
  }
  else{
    *blockID=-1;
  }
 
  return 1;
}

void MultiBlock::getmbEdgIDFrom2ExtrVert(int node1, int node2, int *edgID){
  *edgID=-1;
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    double norm=-1.0;
    int isDuplicate1Start = isPointDuplicateVec(&m_extraordVertices[node1], &m_mbEdges[i][0], &norm);
    int isDuplicate1End = isPointDuplicateVec(&m_extraordVertices[node1], &m_mbEdges[i][m_mbEdges[i].size()-1], &norm);
    int isDuplicate2Start = isPointDuplicateVec(&m_extraordVertices[node2], &m_mbEdges[i][0], &norm);
    int isDuplicate2End = isPointDuplicateVec(&m_extraordVertices[node2], &m_mbEdges[i][m_mbEdges[i].size()-1], &norm);
    
    if((isDuplicate1Start && isDuplicate2End) || (isDuplicate1End && isDuplicate2Start))
      *edgID=(int)i;
  }
  
  return;
}

void MultiBlock::getmbEdgIDFrom2ExtrPoints(std::array<double,3> point1, std::array<double,3> point2 , int *edgID){
  *edgID=-1;
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    double norm=-1.0;
    int isDuplicate1Start = isPointDuplicateVec(&point1, &m_mbEdges[i][0], &norm);
    int isDuplicate1End = isPointDuplicateVec(&point1, &m_mbEdges[i][m_mbEdges[i].size()-1], &norm);
    int isDuplicate2Start = isPointDuplicateVec(&point2, &m_mbEdges[i][0], &norm);
    int isDuplicate2End = isPointDuplicateVec(&point2, &m_mbEdges[i][m_mbEdges[i].size()-1], &norm);
    
    if((isDuplicate1Start && isDuplicate2End) || (isDuplicate1End && isDuplicate2Start))
      *edgID=i;
  }
  
  return;
}


//finding the 2sep which contain Tjunction normal sep and a limit cycle)
//finding the closest neighbour of the T-junction which is not boundary or a T-junction (on the separatrice witch is not a limit cycle) 
//knowing T-junction node, its closest neighbours -> getting a block for correction 
HXTStatus MultiBlock::getTJunctionsPatchesIDs(std::vector<int> *tJunctionPatchesIDs, std::vector<int> *locTjunEdgInd, std::vector<int> *locTjuncInd){
  tJunctionPatchesIDs->clear();
  locTjunEdgInd->clear();
  locTjuncInd->clear();
  int isBdry =0;
  int isTjunction =0;
  int nodeID1 =-1;
  int nodeID2 =-1;
  bool isLimitCycle;
  int edgID[1];
  if(m_extraordVertTjunc.size()>0){
    for(uint64_t i=0; i<m_extraordVertTjunc.size(); i++){
      std::cout << "vert: " << i << " / " << m_extraordVertTjunc.size()-1 << std::endl;
      for(uint64_t j=0; j<m_vectSep.size(); j++){
	std::cout << "sep: " << j << std::endl;
	double min=std::numeric_limits<double>::max();
	double distance=-1.0;
	Separatrice *sep=&(m_vectSep[j]);
	std::cout << "flag1 " << std::endl;
	if(sep->isSaved() && !(sep->getIsLimitCycle())){ //separatrice which is not a limit cycle
	  std::cout << "flag2 " << std::endl;
	  int sepID=sep->getID();
	  int ind=-1;
	  getCleanedSepIndFromSepID(sepID, &ind);
	  std::cout << "flag3 " << std::endl;
	  for(uint64_t k=0; k<m_sepGraphNodes[ind].size(); k++){
	    if(m_extraordVertTjunc[i]==m_sepGraphNodes[ind][k]){
	      std::cout << "flag4 " << std::endl;
	      //previous node
	      isExtrVertOnBdry(m_sepGraphNodes[ind][k-1], &isBdry);
	      isExtrVertTjunction(m_sepGraphNodes[ind][k-1], &isTjunction);
	      if(k!=0 && !(isBdry) && !(isTjunction)){
		distance =  getDistanceBetweeenTwoExtrVert(sepID, m_sepGraphNodes[ind][k-1], m_extraordVertTjunc[i]);
		if(distance<min){
		  min=distance;
		  nodeID1 = m_sepGraphNodes[ind][k-1];
		}
	      }

	      // isExtrVertOnBdry(m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1], &isBdry);
	      // isExtrVertTjunction(m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1], &isTjunction); 
	      // if(k==0 && !(isBdry) && !(isTjunction)){
	      // 	distance =  getDistanceBetweeenTwoExtrVert(sepID, m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1], m_extraordVertTjunc[i]);
	      // 	if(distance<min){
	      // 	  min=distance;
	      // 	  nodeID1 = m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1];
	      // 	}
	      // }
	      // Never k==0 (if everything is good)
	      
	      //next node
	      isExtrVertOnBdry(m_sepGraphNodes[ind][k+1], &isBdry);
	      isExtrVertTjunction(m_sepGraphNodes[ind][k+1], &isTjunction);
	      if((k!=m_sepGraphNodes[ind].size()-1) && !(isBdry) && !(isTjunction)){
		distance =  getDistanceBetweeenTwoExtrVert(sepID, m_sepGraphNodes[ind][k+1], m_extraordVertTjunc[i]);
		if(distance<min){
		  min=distance;
		  nodeID1 = m_sepGraphNodes[ind][k+1];
		}
	      }
	      
	      // isExtrVertOnBdry(m_sepGraphNodes[ind][0], &isBdry);
	      // isExtrVertTjunction(m_sepGraphNodes[ind][0], &isTjunction);
	      // if((k==m_sepGraphNodes[ind].size()-1) && !(isBdry) && !(isTjunction)){
	      // 	distance =  getDistanceBetweeenTwoExtrVert(sepID, m_sepGraphNodes[ind][0], m_extraordVertTjunc[i]);
	      // 	if(distance>min){
	      // 	  min=distance;
	      // 	  nodeID1 = m_sepGraphNodes[ind][0];
	      // 	}
	      // }
	      // Never k==m_sepGraphNodes[ind].size()-1)  (if everything is good)
	      
	    }
	  }
	}
	std::cout << "flag5 " << std::endl;
	if(sep->isSaved() && (sep->getIsLimitCycle())){ //separtrice which is a limit cycle
	  std::cout << "flag6 " << std::endl;
	  int sepID=sep->getID();
	  int ind=-1;
	  getCleanedSepIndFromSepID(sepID, &ind);
	  if(m_extraordVertTjunc[i] == m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1]){
	    // nodeID2 = m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-2]; //DUPLICATES! to fix
	    nodeID2 = m_sepGraphNodes[ind][0];
	    // std::cout<<"-------> Node2: "<<m_sepGraphNodes[ind][0]<<std::endl;
	    // std::cout<<"------>t junc: "<< m_extraordVertTjunc[i]<<std::endl;
	  }
	}
	std::cout << "flag7 " << std::endl;
      }
      //finding a right block
      std::cout<<"Indices: "<<nodeID1<<"; "<<nodeID2<<"; "<<m_extraordVertTjunc[i]<<std::endl;
      int blockID=-1;
      getBlockIDFromVertInd(nodeID1, nodeID2, m_extraordVertTjunc[i], &blockID);
      std::cout<<"block id: "<<blockID<<std::endl;
      tJunctionPatchesIDs->push_back(blockID);
      //std::cout<<"---------> Nodes: "<<nodeID2<<" and "<< m_extraordVertTjunc[i]<<std::endl;
      int edgID[1];
      getmbEdgIDFrom2ExtrVert(nodeID2, m_extraordVertTjunc[i], edgID);
      // std::cout<<"Here"<<std::endl;
      // std::cout<<"edg: "<<edgID[0]<<std::endl;
      // std::cout<<"---------> Nodes: "<<nodeID2<<" and "<< m_extraordVertTjunc[i]<<std::endl;
      int locEdgInd=-1;
      for(uint64_t s=0; s<m_mbBlock2Edg[blockID].size(); s++){
      	if(edgID[0] == m_mbBlock2Edg[blockID][s])
      	  locEdgInd=(int)s; 
      }
      std::cout<<"locEdgInd: "<<locEdgInd<<std::endl;
      locTjunEdgInd->push_back(locEdgInd);
      int locTInd=-1;
      for(uint64_t s=0; s<m_mbQuads[blockID].size(); s++){
	if(m_mbQuads[blockID][s] == m_extraordVertTjunc[i])
	  locTInd=(int)s;	  
      }
      std::cout<<"t loc ind: "<<locTInd<<std::endl;
      locTjuncInd->push_back(locTInd);
    }
  }
  
  return  HXT_STATUS_OK;
}


HXTStatus MultiBlock::getDataFromBlockEdgID(int edgID, std::vector<std::array<double, 3>> &pointsOnEdg, std::vector<uint64_t> &trianglesOnEdg){
  pointsOnEdg.clear();
  trianglesOnEdg.clear();
  for(size_t k=0;k<m_mbEdges[edgID].size();k++){
    pointsOnEdg.push_back(m_mbEdges[edgID][k]);
  }
  for(size_t k=0;k<m_mbEdgesTri[edgID].size();k++){
    trianglesOnEdg.push_back(m_mbEdgesTri[edgID][k]);
  }
  return  HXT_STATUS_OK;
}

HXTStatus MultiBlock::createMbTriPatchs(){
  m_mbBlockTriPatchs.clear();
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  std::set<size_t> emptySet;  
  std::vector<std::set<size_t>> triFladdedWithEdg(mesh->triangles.num,emptySet);
  // std::cout << "flag-3 " << std::endl;
  // std::cout << "nEdges in edg2block: " << m_mbEdg2Block.size() << std::endl;
  // std::cout << "nEdges in edgesTri: " << m_mbEdgesTri.size() << std::endl;
  for(size_t k=0;k<m_mbEdg2Block.size();k++){
    for(size_t l=0;l<m_mbEdgesTri[k].size();l++){
      uint64_t triNum=m_mbEdgesTri[k][l];
      // std::cout << "edgeNum: " << k << std::endl;
      // std::cout << "discrEdg: " << l << " / " << m_mbEdgesTri[k].size()-1 << std::endl;
      // std::cout << "triNum: " << triNum << std::endl;
      triFladdedWithEdg[triNum].insert(k);
    }
  }
  m_mbBlockTriPatchs.clear();
  std::set<uint64_t> emptySet2;
  m_mbBlockTriPatchs.resize(m_mbBlock2Edg.size(),emptySet2);
  //NW
  //have to add in all patchs corresponding block edges triangles (from edgData)
  for(size_t iE=0;iE<m_mbEdg2Block.size();iE++){
    for(size_t iB=0;iB<m_mbEdg2Block[iE].size();iB++){
      uint64_t blockID=m_mbEdg2Block[iE][iB];
      for(size_t k=0;k<m_mbEdgesTri[iE].size();k++){
  	m_mbBlockTriPatchs[blockID].insert(m_mbEdgesTri[iE][k]);
      }
    }
  }
  //
  std::map<uint64_t, bool> trianglePassed;
  std::stack<uint64_t> stackTri;
  for(size_t k=0;k<mesh->triangles.num;k++)
    trianglePassed[k]=false;
  uint64_t triangleLeft=(uint64_t)(-1);
  for(auto &kv: trianglePassed){
    if(!kv.second && triFladdedWithEdg[kv.first].size()==0){
      triangleLeft=kv.first;
      break;
    }
  }
  std::set<uint64_t> setPatchTri;    
  if(triangleLeft!=(uint64_t)(-1)){
    trianglePassed[triangleLeft]=true;
    setPatchTri.insert(triangleLeft);
  }
  std::set<size_t> idEdgesTouched;
  std::set<uint64_t> neighboursTri;
  while(triangleLeft!=(uint64_t)(-1)){
    for(size_t k=0;k<3;k++){
      uint32_t edg=edges->tri2edg[3*triangleLeft+k];
      uint64_t nextTriangle=edges->edg2tri[2*edg+0];
      if(nextTriangle==triangleLeft)
	nextTriangle=edges->edg2tri[2*edg+1];
      // for(size_t l=0;l<m_vertToTri[mesh->triangles.node[3*triangleLeft+k]].size();l++){
      // 	uint64_t nextTriangle=m_vertToTri[mesh->triangles.node[3*triangleLeft+k]][l];
	if(nextTriangle!=(uint64_t)(-1)){
	  // std::cout << "nTriangles : " << mesh->triangles.num << std::endl;
	  // std::cout << "nextTriangle : " << nextTriangle << std::endl;
	  // std::cout << "triflaggedwithedge size : " << triFladdedWithEdg[nextTriangle].size() << std::endl;
	  // std::cout << "tri passed : " << trianglePassed[nextTriangle] << std::endl;
	  if(triFladdedWithEdg[nextTriangle].size()==0 && !trianglePassed[nextTriangle]){
	    stackTri.push(nextTriangle);
	    trianglePassed[nextTriangle]=true;
	    setPatchTri.insert(nextTriangle);
	  }
	  if(triFladdedWithEdg[nextTriangle].size()!=0){
	    neighboursTri.insert(nextTriangle);
	    for(size_t iE: triFladdedWithEdg[nextTriangle]){
	      idEdgesTouched.insert(iE);
	    }
	  }
	}
      // }
    }
    if(!stackTri.empty()){
      triangleLeft = stackTri.top();
      stackTri.pop();
    }
    else{
      //Idea new way: we create initial patchs with edges belonging to corresponding patch edges
      //create patch as done before
      //find which existing patch own ALL the edgTouchedTriangles to the patch we just created
      //add triangles to this patch
      // std::cout << std::endl;
      size_t idPatch=(size_t)(-1);
      for(size_t iB=0;iB<m_mbBlockTriPatchs.size();iB++){
	bool areAllNeigTriInPatch=true;
	for(uint64_t nT: neighboursTri){
	  if(m_mbBlockTriPatchs[iB].find(nT)==m_mbBlockTriPatchs[iB].end()){
	    areAllNeigTriInPatch=false;
	    break;
	  }
	}
	if(areAllNeigTriInPatch)
	  idPatch=iB;
      }
      if(idPatch==(size_t)(-1)){
	dbgPosFlagSetTri(setPatchTri, "dbgLastPatch.pos");
	std::cout << "edges touched: " << std::endl;
	for(size_t id: idEdgesTouched)
	  std::cout << id << " ";
	std::cout<<std::endl;
	std::cout << "problem associating good patch" << std::endl;
	exit(0);
      }
      else
	m_mbBlockTriPatchs[idPatch].insert(setPatchTri.begin(),setPatchTri.end());
      //
      setPatchTri.clear();
      idEdgesTouched.clear();
      neighboursTri.clear();
      triangleLeft=(uint64_t)(-1);
      for(auto &kv: trianglePassed){
	if(!kv.second && triFladdedWithEdg[kv.first].size()==0){
	  triangleLeft=kv.first;
	  trianglePassed[triangleLeft]=true;
	  setPatchTri.insert(triangleLeft);
	  break;
	}
      }
    }
  }
  //have to add in all patchs corresponding block edges triangles (from edgData)
  // std::cout << "flag3 " << std::endl;
  // for(size_t iE=0;iE<m_mbEdg2Block.size();iE++){
  //   for(size_t iB=0;iB<m_mbEdg2Block[iE].size();iB++){
  //     uint64_t blockID=m_mbEdg2Block[iE][iB];
  //     for(size_t k=0;k<m_mbEdgesTri[iE].size();k++){
  // 	m_mbBlockTriPatchs[blockID].insert(m_mbEdgesTri[iE][k]);
  //     }
  //   }
  // }
  return  HXT_STATUS_OK;
}

HXTStatus MultiBlock::getCrossesLifting(const std::vector<uint64_t> &tri, const std::vector<uint64_t> &glob2LocTri, std::vector<std::array<double,3>> &lift, uint64_t triInit, std::array<double,3> dirRef){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  lift.clear();
  std::array<double,3> init={{0.0,0.0,0.0}};
  lift.resize(3*tri.size(),init);

  std::map<uint64_t, bool> trianglePassed;
  for(uint64_t t=0;t<mesh->triangles.num;t++)//mesh triangles not belonging to tri will not be took into account
    trianglePassed[t]=true;
  std::stack<uint64_t> stackTri;
  for(uint64_t t: tri)
    trianglePassed[t]=false;
  uint64_t triangleLeft=triInit;
  trianglePassed[triangleLeft]=true;
  std::map<uint64_t, std::array<double,3>> mapTriDir;
  mapTriDir[triInit] = dirRef;
  while(triangleLeft!=(uint64_t)(-1)){
    uint32_t vtri[3] = {mesh->triangles.node[3*triangleLeft+0],mesh->triangles.node[3*triangleLeft+1],mesh->triangles.node[3*triangleLeft+2]};
    double U[3]={0.}, V[3]={0.}, n[3]={0.};	
    trianglebasis(mesh,vtri,U,V,n);
    for(size_t k=0;k<3;k++){
      //lifting in triangleLeft
      uint32_t edgeRefGlob=edges->tri2edg[3*triangleLeft+k];
      const double *v0 = mesh->vertices.coord + 4*edges->node[2*edgeRefGlob+0];
      const double *v1 = mesh->vertices.coord + 4*edges->node[2*edgeRefGlob+1];
      double edgeK[3]={v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
      normalize(edgeK);
      double alphaEdg=atan2(myDot(edgeK,V),myDot(edgeK,U));
      double cos4Theta=m_crossfield[2*edgeRefGlob+0]*cos(4*alphaEdg) - m_crossfield[2*edgeRefGlob+1]*sin(4*alphaEdg);
      double sin4Theta=m_crossfield[2*edgeRefGlob+1]*cos(4*alphaEdg) + m_crossfield[2*edgeRefGlob+0]*sin(4*alphaEdg);
      double theta=atan2(sin4Theta,cos4Theta)/4.;
      std::vector<std::array<double,3>> dirCross;
      for(size_t l=0;l<4;l++){
	std::array<double,3> dirL={{0.0,0.0,0.0}};
	for(size_t m=0;m<3;m++)
	  dirL[m]=cos(theta+l*M_PI/2.)*U[m]+sin(theta+l*M_PI/2.)*V[m];
	dirCross.push_back(dirL);
      }
      double valMin=1000;
      size_t indMin=0;
      std::array<double,3> dirRefTri=mapTriDir[triangleLeft];
      for(size_t l=0;l<4;l++){
	double diff[3]={dirCross[l][0]-dirRefTri[0],dirCross[l][1]-dirRefTri[1],dirCross[l][2]-dirRefTri[2]};
	double normDiff=sqrt(myDot(diff,diff));
	if(normDiff<valMin){
	  indMin=l;
	  valMin=normDiff;
	}
      }
      lift[3*glob2LocTri[triangleLeft]+k]=dirCross[indMin];
      //
      uint32_t edg=edges->tri2edg[3*triangleLeft+k];
      uint64_t nextTriangle=edges->edg2tri[2*edg+0];
      // for(const MEdge *e: mesh->triangleToEdges[triangleLeft]){
      if(nextTriangle==triangleLeft)
	nextTriangle=edges->edg2tri[2*edg+1];
      if(nextTriangle!=(uint64_t)(-1)){
	if(!trianglePassed[nextTriangle]){
	  stackTri.push(nextTriangle);
	  mapTriDir[nextTriangle]=lift[3*glob2LocTri[triangleLeft]+k];
	  trianglePassed[nextTriangle]=true;
	}
      }
    }
    if(!stackTri.empty()){
      triangleLeft = stackTri.top();
      stackTri.pop();
    }
    else{
      triangleLeft=(uint64_t)(-1);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::computePatchsParametrization(){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  int argc=1;
  HXT_CHECK(hxtInitializeLinearSystems(&argc, NULL));
  m_mbQuadParametrization.clear();
  for(size_t iB=0;iB<m_mbBlockTriPatchs.size();iB++){
    BlockParametrization blockParam(mesh);
    parametrizeBlock(iB, blockParam);
    m_mbQuadParametrization.push_back(blockParam);
    std::string nameTest="dbgParam_" + std::to_string(iB) + ".pos";
    blockParam.dbgPosParam(nameTest.c_str());
  }
  return  HXT_STATUS_OK;
}

int BlockParametrization::isPointInTri(std::vector<std::array<double,3>> tri, std::array<double, 3> point, double *distance1, double *distance2){
  *distance1 = -1.0;
  *distance2 = -1.0;
  int pointIsInTri=0;
  double AB[3]={tri[1][0]-tri[0][0], tri[1][1]-tri[0][1], tri[1][2]-tri[0][2]};
  double AC[3]={tri[2][0]-tri[0][0], tri[2][1]-tri[0][1], tri[2][2]-tri[0][2]};
  double AM[3]={point[0]-tri[0][0],point[1]-tri[0][1],point[2]-tri[0][2]};
  double nABC[3]={0.0,0.0,0.0}; double AMxAB[3]={0.0,0.0,0.0}; double AMxAC[3]={0.0,0.0,0.0}; double  ACxAB[3]={0.0,0.0,0.0};
  crossprod(AB, AC, nABC);
  crossprod(AM, AB, AMxAB);
  crossprod(AM, AC, AMxAC);
  crossprod(AC, AB, ACxAB);

  double alpha = myDot(AMxAC, nABC)/myDot(nABC, nABC);
  double beta = myDot(AMxAB, nABC)/myDot(ACxAB, nABC);
  double numError =1e-10;
  if((alpha>-numError) && (beta>-numError) && (alpha<1.0+numError) && beta<(1-alpha+numError)){
    pointIsInTri=1;
    *distance1 = alpha;
    *distance2 = beta;
  } 
  
  return pointIsInTri;
}

std::array<double,3> BlockParametrization::getPhysCoordFromParamCoord(std::array<double,3> paramCoord, uint64_t globNumTriHint){
  double *coords=m_mesh->vertices.coord;
  std::array<double,3> physicalCoord={{0.,0.,0.}};
  int isPointBelongingToTri=0;
  double alpha=0.0;
  double beta=0.0;
  if(globNumTriHint!=(uint64_t)(-1)){
    uint32_t* nodes = m_mesh->triangles.node+3*globNumTriHint;
    std::vector<std::array<double,3>> tri;
    tri.reserve(3);
    for(size_t k=0;k<3;k++){
      uint32_t nodeLocK=m_nodesGlobalToParam[nodes[k]];
      std::array<double,3> coordK=m_nodesParamCoord[nodeLocK];
      tri.push_back(coordK);
    }
    isPointBelongingToTri=isPointInTri(tri, paramCoord, &alpha, &beta);
    if(isPointBelongingToTri){
      for(size_t k=0;k<3;k++){
  	physicalCoord[k]=alpha*(coords[4*nodes[1]+k]-coords[4*nodes[0]+k])+beta*(coords[4*nodes[2]+k]-coords[4*nodes[0]+k]) + coords[4*nodes[0]+k];
      }
    }
  }
  if(!isPointBelongingToTri){
    for(size_t k=0;k<m_triangles.size();k++){
      uint64_t globTriNum=m_triangles[k];
      uint32_t* nodes = m_mesh->triangles.node+3*globTriNum;
      std::vector<std::array<double,3>> tri;
      tri.reserve(3);
      for(size_t k=0;k<3;k++){
	uint32_t nodeLocK=m_nodesGlobalToParam[nodes[k]];
	std::array<double,3> coordK=m_nodesParamCoord[nodeLocK];
	tri.push_back(coordK);
      }
      isPointBelongingToTri=isPointInTri(tri, paramCoord, &alpha, &beta);
      if(isPointBelongingToTri){
	for(size_t k=0;k<3;k++){
	  physicalCoord[k]=alpha*(coords[4*nodes[1]+k]-coords[4*nodes[0]+k])+beta*(coords[4*nodes[2]+k]-coords[4*nodes[0]+k]) + coords[4*nodes[0]+k];
	}
	break;
      }
    }
  }
  if(!isPointBelongingToTri){
    std::cout << "param coord: " << paramCoord[0] << " / " << paramCoord[1] << " / " << paramCoord[2] << std::endl;
    std::cout << "Unable to find point in parametric space" << std::endl;
    std::cout << "nTriangles: " << m_triangles.size() << std::endl;
    exit(0);
  }
  return physicalCoord;
}

uint64_t BlockParametrization::getBelongingTriangleFromParamCoord(std::array<double,3> paramCoord){
  int isPointBelongingToTri=0;
  double alpha=0.0;
  double beta=0.0;
  uint64_t globalTriNum=(uint64_t)(-1);
  for(size_t k=0;k<m_triangles.size();k++){
    uint64_t globTriNum=m_triangles[k];
    uint32_t* nodes = m_mesh->triangles.node+3*globTriNum;
    std::vector<std::array<double,3>> tri;
    tri.reserve(3);
    for(size_t k=0;k<3;k++){
      uint32_t nodeLocK=m_nodesGlobalToParam[nodes[k]];
      std::array<double,3> coordK=m_nodesParamCoord[nodeLocK];
      tri.push_back(coordK);
    }
    isPointBelongingToTri=isPointInTri(tri, paramCoord, &alpha, &beta);
    if(isPointBelongingToTri){
      globalTriNum=globTriNum;
      break;
    }
  }
  if(globalTriNum==(uint64_t)(-1)){
    std::cout << "problem finding triangle from parametric coordinates" << std::endl;
  }
  return globalTriNum;
}

std::array<double,3> BlockParametrization::getParamCoordFromPhysCoord(std::array<double,3> physCoord, uint64_t globNumTriHint){
  double *coords=m_mesh->vertices.coord;
  std::array<double,3> paramCoord={{0.,0.,0.}};
  int isPointBelongingToTri=0;
  double alpha=0.0;
  double beta=0.0;
  if(globNumTriHint!=(uint64_t)(-1)){
    uint32_t* nodes = m_mesh->triangles.node+3*globNumTriHint;
    std::vector<std::array<double,3>> tri;
    tri.reserve(3);
    for(size_t k=0;k<3;k++){
      std::array<double,3> coordK={{coords[4*nodes[k]+0],coords[4*nodes[k]+1],coords[4*nodes[k]+2]}};
      tri.push_back(coordK);
    }
    isPointBelongingToTri=isPointInTri(tri, physCoord, &alpha, &beta);
    if(isPointBelongingToTri){
      std::array<uint32_t,3> nodesParamTri={{m_nodesGlobalToParam[nodes[0]],m_nodesGlobalToParam[nodes[1]],m_nodesGlobalToParam[nodes[2]]}};
      for(size_t k=0;k<3;k++){
        paramCoord[k]=alpha*(m_nodesParamCoord[nodesParamTri[1]][k]-m_nodesParamCoord[nodesParamTri[0]][k])+beta*(m_nodesParamCoord[nodesParamTri[2]][k]-m_nodesParamCoord[nodesParamTri[0]][k]) + m_nodesParamCoord[nodesParamTri[0]][k];
      }
    }
  }
  if(!isPointBelongingToTri){
    for(size_t k=0;k<m_triangles.size();k++){
      uint64_t globTriNum=m_triangles[k];
      uint32_t* nodes = m_mesh->triangles.node+3*globTriNum;
      std::vector<std::array<double,3>> tri;
      tri.reserve(3);
      for(size_t k=0;k<3;k++){
	std::array<double,3> coordK={{coords[4*nodes[k]+0],coords[4*nodes[k]+1],coords[4*nodes[k]+2]}};
	tri.push_back(coordK);
      }
      isPointBelongingToTri=isPointInTri(tri, physCoord, &alpha, &beta);
      if(isPointBelongingToTri){
	std::array<uint32_t,3> nodesParamTri={{m_nodesGlobalToParam[nodes[0]],m_nodesGlobalToParam[nodes[1]],m_nodesGlobalToParam[nodes[2]]}};
	for(size_t k=0;k<3;k++){
	  paramCoord[k]=alpha*(m_nodesParamCoord[nodesParamTri[1]][k]-m_nodesParamCoord[nodesParamTri[0]][k])+beta*(m_nodesParamCoord[nodesParamTri[2]][k]-m_nodesParamCoord[nodesParamTri[0]][k]) + m_nodesParamCoord[nodesParamTri[0]][k];
	}
	break;
      }
    }
  }
  if(!isPointBelongingToTri){
    std::cout << "physical coord: " << physCoord[0] << " / " << physCoord[1] << " / " << physCoord[2] << std::endl;
    std::cout << "Unable to find point in parametric space" << std::endl;
    exit(0);
  }
  return paramCoord;
}

void BlockParametrization::getStraigthLine(std::array<double,3> physCoord1, std::array<double,3> physCoord2, std::vector<std::array<double,3>> &physCoordLine, std::vector<uint64_t> &physTriLine, uint64_t nPoints){
  physCoordLine.clear();
  physTriLine.clear();
  std::array<double,3> paramCoordPoint1 = getParamCoordFromPhysCoord(physCoord1);
  std::array<double,3> paramCoordPoint2 = getParamCoordFromPhysCoord(physCoord2);
  double AB[3]={paramCoordPoint2[0]-paramCoordPoint1[0],
		paramCoordPoint2[1]-paramCoordPoint1[1],
		paramCoordPoint2[2]-paramCoordPoint1[2]};
  for(uint64_t k=0;k<nPoints+1;k++){
    std::array<double,3> pointParam = {{paramCoordPoint1[0]+((1.*k)/(1.*nPoints))*AB[0],
					paramCoordPoint1[1]+((1.*k)/(1.*nPoints))*AB[1],
					paramCoordPoint1[2]+((1.*k)/(1.*nPoints))*AB[2]}};
    std::array<double,3> pointPhys = getPhysCoordFromParamCoord(pointParam);
    uint64_t globalTriNum = getBelongingTriangleFromParamCoord(pointParam);
    physCoordLine.push_back(pointPhys);
    physTriLine.push_back(globalTriNum);
  }
  return;
}

HXTStatus BlockParametrization::dbgPosParam(const char *fileName){
  HXTMesh *mesh = m_mesh;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"point BC\" {\n");
  fprintf(f,"SP(%.16g,%.16g,%.16g){%.16g};\n", pointBC[0], pointBC[1], pointBC[2], 1.0);
  fprintf(f,"};");
  fprintf(f,"View \"potU\" {\n");
  for(uint64_t triNum: m_triangles){
    // std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
    // std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
    // std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
    // triNum=m_triangles[m_trianglesGlobalToParam[triNum]];//DBG
    std::array<uint32_t,3> globVertInd={{mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]}};
    std::array<uint32_t,3> locVertInd={{m_nodesGlobalToParam[globVertInd[0]],m_nodesGlobalToParam[globVertInd[1]],m_nodesGlobalToParam[globVertInd[2]]}};
    uint32_t iV0=globVertInd[0];
    uint32_t iV1=globVertInd[1];
    uint32_t iV2=globVertInd[2];
    // uint32_t iV0=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[0]]];
    // uint32_t iV1=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[1]]];
    // uint32_t iV2=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[2]]];
    std::array<double,3> point1={{mesh->vertices.coord[4*iV0+0],mesh->vertices.coord[4*iV0+1],mesh->vertices.coord[4*iV0+2]}};
    std::array<double,3> point2={{mesh->vertices.coord[4*iV1+0],mesh->vertices.coord[4*iV1+1],mesh->vertices.coord[4*iV1+2]}};
    std::array<double,3> point3={{mesh->vertices.coord[4*iV2+0],mesh->vertices.coord[4*iV2+1],mesh->vertices.coord[4*iV2+2]}};
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], m_nodesParamCoord[locVertInd[0]][0], m_nodesParamCoord[locVertInd[1]][0], m_nodesParamCoord[locVertInd[2]][0]);
  }
  fprintf(f,"};");
  // fprintf(f,"View \"liftUdbg\" {\n");
  // for(uint64_t triNum: m_triangles){
  //   // std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   // std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
  //   // std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   std::array<uint32_t,3> globVertInd={{mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]}};
  //   std::array<uint32_t,3> locVertInd={{m_nodesGlobalToParam[globVertInd[0]],m_nodesGlobalToParam[globVertInd[1]],m_nodesGlobalToParam[globVertInd[2]]}};
  //   uint32_t iV0=globVertInd[0];
  //   uint32_t iV1=globVertInd[1];
  //   uint32_t iV2=globVertInd[2];
  //   // uint32_t iV0=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[0]]];
  //   // uint32_t iV1=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[1]]];
  //   // uint32_t iV2=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[2]]];
  //   std::array<double,3> point1={{mesh->vertices.coord[4*iV0+0],mesh->vertices.coord[4*iV0+1],mesh->vertices.coord[4*iV0+2]}};
  //   std::array<double,3> point2={{mesh->vertices.coord[4*iV1+0],mesh->vertices.coord[4*iV1+1],mesh->vertices.coord[4*iV1+2]}};
  //   std::array<double,3> point3={{mesh->vertices.coord[4*iV2+0],mesh->vertices.coord[4*iV2+1],mesh->vertices.coord[4*iV2+2]}};
  //   fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n", (point1[0]+point2[0]+point3[0])/3., (point1[1]+point2[1]+point3[1])/3., (point1[2]+point2[2]+point3[2])/3., liftU[m_trianglesGlobalToParam[triNum]][0], liftU[m_trianglesGlobalToParam[triNum]][1], liftU[m_trianglesGlobalToParam[triNum]][2]);
  // }
  // fprintf(f,"};");
  // fprintf(f,"View \"scalingDBG\" {\n");
  // for(uint64_t triNum: m_triangles){
  //   // std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   // std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
  //   // std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   std::array<uint32_t,3> globVertInd={{mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]}};
  //   std::array<uint32_t,3> locVertInd={{m_nodesGlobalToParam[globVertInd[0]],m_nodesGlobalToParam[globVertInd[1]],m_nodesGlobalToParam[globVertInd[2]]}};
  //   uint32_t iV0=globVertInd[0];
  //   uint32_t iV1=globVertInd[1];
  //   uint32_t iV2=globVertInd[2];
  //   // uint32_t iV0=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[0]]];
  //   // uint32_t iV1=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[1]]];
  //   // uint32_t iV2=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[2]]];
  //   std::array<double,3> point1={{mesh->vertices.coord[4*iV0+0],mesh->vertices.coord[4*iV0+1],mesh->vertices.coord[4*iV0+2]}};
  //   std::array<double,3> point2={{mesh->vertices.coord[4*iV1+0],mesh->vertices.coord[4*iV1+1],mesh->vertices.coord[4*iV1+2]}};
  //   std::array<double,3> point3={{mesh->vertices.coord[4*iV2+0],mesh->vertices.coord[4*iV2+1],mesh->vertices.coord[4*iV2+2]}};
  //   fprintf(f,"ST(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n", point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], point3[0], point3[1], point3[2], scaling[m_trianglesGlobalToParam[triNum]], scaling[m_trianglesGlobalToParam[triNum]], scaling[m_trianglesGlobalToParam[triNum]]);
  // }
  // fprintf(f,"};");
  fprintf(f,"View \"potV\" {\n");
  for(uint64_t triNum: m_triangles){
    // std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
    // std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
    // std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
    std::array<uint32_t,3> globVertInd={{mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]}};
    std::array<uint32_t,3> locVertInd={{m_nodesGlobalToParam[globVertInd[0]],m_nodesGlobalToParam[globVertInd[1]],m_nodesGlobalToParam[globVertInd[2]]}};
    uint32_t iV0=globVertInd[0];
    uint32_t iV1=globVertInd[1];
    uint32_t iV2=globVertInd[2];
    std::array<double,3> point1={{mesh->vertices.coord[4*iV0+0],mesh->vertices.coord[4*iV0+1],mesh->vertices.coord[4*iV0+2]}};
    std::array<double,3> point2={{mesh->vertices.coord[4*iV1+0],mesh->vertices.coord[4*iV1+1],mesh->vertices.coord[4*iV1+2]}};
    std::array<double,3> point3={{mesh->vertices.coord[4*iV2+0],mesh->vertices.coord[4*iV2+1],mesh->vertices.coord[4*iV2+2]}};
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], m_nodesParamCoord[locVertInd[0]][1], m_nodesParamCoord[locVertInd[1]][1], m_nodesParamCoord[locVertInd[2]][1]);
  }
  fprintf(f,"};");
  // fprintf(f,"View \"liftVdbg\" {\n");
  // for(uint64_t triNum: m_triangles){
  //   // std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   // std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
  //   // std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
  //   std::array<uint32_t,3> globVertInd={{mesh->triangles.node[3*triNum+0],mesh->triangles.node[3*triNum+1],mesh->triangles.node[3*triNum+2]}};
  //   std::array<uint32_t,3> locVertInd={{m_nodesGlobalToParam[globVertInd[0]],m_nodesGlobalToParam[globVertInd[1]],m_nodesGlobalToParam[globVertInd[2]]}};
  //   uint32_t iV0=globVertInd[0];
  //   uint32_t iV1=globVertInd[1];
  //   uint32_t iV2=globVertInd[2];
  //   // uint32_t iV0=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[0]]];
  //   // uint32_t iV1=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[1]]];
  //   // uint32_t iV2=m_nodesParamToGlobal[m_nodesGlobalToParam[globVertInd[2]]];
  //   std::array<double,3> point1={{mesh->vertices.coord[4*iV0+0],mesh->vertices.coord[4*iV0+1],mesh->vertices.coord[4*iV0+2]}};
  //   std::array<double,3> point2={{mesh->vertices.coord[4*iV1+0],mesh->vertices.coord[4*iV1+1],mesh->vertices.coord[4*iV1+2]}};
  //   std::array<double,3> point3={{mesh->vertices.coord[4*iV2+0],mesh->vertices.coord[4*iV2+1],mesh->vertices.coord[4*iV2+2]}};
  //   fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n", (point1[0]+point2[0]+point3[0])/3., (point1[1]+point2[1]+point3[1])/3., (point1[2]+point2[2]+point3[2])/3., liftV[m_trianglesGlobalToParam[triNum]][0], liftV[m_trianglesGlobalToParam[triNum]][1], liftV[m_trianglesGlobalToParam[triNum]][2]);
  // }
  // fprintf(f,"};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::parametrizeBlock(uint64_t idBlock, BlockParametrization &blockParam){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  uint64_t iB=idBlock;
  //create patch tri numerotation
  size_t nTriangles = m_mbBlockTriPatchs[iB].size();
  uint32_t* nodesLoc;
  HXT_CHECK(hxtAlignedMalloc(&nodesLoc, 3*nTriangles*sizeof(uint32_t)));
  // HXT_CHECK(hxtMalloc(&nodesLoc, 3*nTriangles*sizeof(uint32_t)));
  std::vector<uint64_t> loc2GlobTri;
  std::vector<uint64_t> glob2LocTri(mesh->triangles.num,0);
  std::vector<bool> flaggedVert(mesh->vertices.num,false);
  std::vector<uint32_t> loc2GlobVert;
  std::vector<uint32_t> glob2LocVert(mesh->vertices.num,(uint32_t)(-1));
  for(uint64_t t: m_mbBlockTriPatchs[iB]){
    for(size_t l=0;l<3;l++)
      flaggedVert[mesh->triangles.node[3*t+l]]=true;
  }
  for(uint32_t k=0;k<mesh->vertices.num;k++){
    if(flaggedVert[k]){
      loc2GlobVert.push_back(k);
      glob2LocVert[k]=loc2GlobVert.size()-1;
    }
  }
  for(uint64_t t: m_mbBlockTriPatchs[iB]){
    loc2GlobTri.push_back(t);
    glob2LocTri[t]=loc2GlobTri.size()-1;
    for(size_t l=0;l<3;l++){
      nodesLoc[3*glob2LocTri[t]+l]=glob2LocVert[mesh->triangles.node[3*t+l]];
    }
  }
  //DBG
  if(nTriangles!=loc2GlobTri.size()){
    std::cout << "error counting triangles number" << std::endl;
    exit(0);
  }
  for(uint32_t k=0;k<loc2GlobTri.size();k++){
    if(k!=glob2LocTri[loc2GlobTri[k]]){
      std::cout << "error building correspondance triangles tables" << std::endl;
      exit(0);
    }
  }
  for(uint32_t k=0;k<loc2GlobVert.size();k++){
    if(k!=glob2LocVert[loc2GlobVert[k]]){
      std::cout << "error building correspondance vertices tables" << std::endl;
      exit(0);
    }
  }
  for(uint64_t k=0;k<loc2GlobTri.size();k++){
    for(size_t l=0;l<3;l++){
      if(loc2GlobVert[nodesLoc[3*k+l]]!=mesh->triangles.node[3*loc2GlobTri[k]+l]){
  	std::cout << "error new connectivity" << std::endl;
	std::cout << "patch: " << iB << std::endl;
  	exit(0);
      }
    }
  }
  //
  std::vector<std::array<double,3>> coordLoc;
  for(size_t k=0;k<loc2GlobVert.size();k++){
    uint32_t globInd=loc2GlobVert[k];
    std::array<double,3> coord={{mesh->vertices.coord[4*globInd+0],mesh->vertices.coord[4*globInd+1],mesh->vertices.coord[4*globInd+2]}};
    coordLoc.push_back(coord);
  }
  std::vector<std::array<double,3>> liftU;//3*triLocNum+edgLoc
  std::array<double,3> init={{0.0,0.0,0.0}};//DBG
  liftU.resize(3*nTriangles,init);//DBG
  std::vector<std::array<double,3>> liftV;//3*triLocNum+edgLoc
  liftV.resize(3*nTriangles,init);//DBG
  uint64_t refTriGlob=loc2GlobTri[0];
  uint32_t vtriRef[3] = {mesh->triangles.node[3*refTriGlob+0],mesh->triangles.node[3*refTriGlob+1],mesh->triangles.node[3*refTriGlob+2]};
  double U[3]={0.}, V[3]={0.}, n[3]={0.};	
  trianglebasis(mesh,vtriRef,U,V,n);
  std::array<double,3> dirRefU;
  std::array<double,3> dirRefV;
  uint32_t edgeRefGlob=edges->tri2edg[3*refTriGlob+0];
  double theta=atan2(m_crossfield[2*edgeRefGlob+1],m_crossfield[2*edgeRefGlob+0])/4.;
  for(size_t k=0;k<3;k++){
    dirRefU[k]=cos(theta)*U[k]+sin(theta)*V[k];
    dirRefV[k]=-sin(theta)*U[k]+cos(theta)*V[k];
  }
  getCrossesLifting(loc2GlobTri,glob2LocTri,liftU,refTriGlob,dirRefU);
  getCrossesLifting(loc2GlobTri,glob2LocTri,liftV,refTriGlob,dirRefV);

  HXTLinearSystem *sys;
  // we definitely use PETSc solver if it is enabled
  // #if defined(HXT_HAVE_PETSC)
  //     std::cout << "have petsc" << std::endl;
  //     exit(0);
  // #else
  //     std::cout << "not have petsc" << std::endl;
  //     exit(0);
  // #endif
  // HXT_CHECK(hxtLinearSystemCreatePETSc(&sys,nTriangles,3,2,edges->tri2edg,"-pc_type lu"));
  // #else
  HXT_CHECK(hxtLinearSystemCreateLU(&sys,nTriangles,3,1,nodesLoc));
  // #endif
  double *rhsU;
  HXT_CHECK(hxtMalloc(&rhsU, loc2GlobVert.size()*sizeof(double)));
  double *rhsV;
  HXT_CHECK(hxtMalloc(&rhsV, loc2GlobVert.size()*sizeof(double)));
  for(size_t k=0; k<loc2GlobVert.size(); k++){
    rhsU[k]=0.0;
    rhsV[k]=0.0;
  }

  //DBG
  blockParam.liftU.clear();
  blockParam.liftU.reserve(nTriangles);
  // blockParam.liftU.resize(nTriangles,init);
  blockParam.liftV.clear();
  blockParam.liftV.reserve(nTriangles);
  blockParam.scaling.clear();
  blockParam.scaling.reserve(nTriangles);
  //
  for(size_t iT=0;iT<nTriangles;iT++){
    double vtri[9] = {0.};
    for(int i=0; i<3; i++)
      for(int j=0; j<3; j++){
	vtri[3*i+j] = mesh->vertices.coord[4*loc2GlobVert[nodesLoc[3*iT+i]]+j];
      }
    // uint32_t vtri[3] = {mesh->triangles.node[3*loc2GlobTri[iT]+0],mesh->triangles.node[3*loc2GlobTri[iT]+1],mesh->triangles.node[3*loc2GlobTri[iT]+2]};
    double grad[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
  
    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
			{0,0,0}};
    HXT_CHECK(myNormalizedCrossprod(jac[0],jac[1],jac[2]));
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double dphidx[3][3];
    for(uint32_t i=0; i<3; i++){
      dphidx[i][0] = dphidx[i][1] = dphidx[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
	dphidx[i][0] += grad[i][j]*invjac[0][j];
	dphidx[i][1] += grad[i][j]*invjac[1][j];
	dphidx[i][2] += grad[i][j]*invjac[2][j];
      }
    }
    double localMatrix[3*3]={0.0};
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++)
	for(size_t m=0; m<3; m++)
	  localMatrix[3*k+l]+=dphidx[k][m]*dphidx[l][m]*dJac/2.;
    HXT_CHECK(hxtLinearSystemAddToMatrix(sys,iT,iT,localMatrix));
    std::array<double,3> dirGaussU={{0.0,0.0,0.0}};
    std::array<double,3> dirGaussV={{0.0,0.0,0.0}};
    // for(size_t k=0; k<3; k++)//DBG
    //   for(size_t l=0; l<3; l++){
    // 	dirGaussU[k]+=liftU[3*iT+l][k]*1./3.;
    // 	dirGaussV[k]+=liftV[3*iT+l][k]*1./3.;
    //   }
    for(size_t k=0; k<3; k++)//DBG
      for(size_t l=0; l<3; l++){
	dirGaussU[k]+=liftU[3*iT+l][k];
	dirGaussV[k]+=liftV[3*iT+l][k];
      }
    double scalingLoc=0.0;
    for(size_t k=0; k<3; k++)
      scalingLoc+=(exp(-m_scalingFactorCrosses[3*loc2GlobTri[iT]+k]))*1./3.;
    // for(size_t k=2; k<3; k++)//DBG
    //   scalingLoc+=(exp(-m_scalingFactorCrosses[3*loc2GlobTri[iT]+k]));
    for(size_t k=0; k<3; k++){
      dirGaussU[k]*=scalingLoc;
      dirGaussV[k]*=scalingLoc;
    }
    
    //DBG
    blockParam.liftU.push_back(dirGaussU);
    blockParam.scaling.push_back(scalingLoc);
    // blockParam.liftU.push_back(liftU[3*iT+0]);//DBG
    blockParam.liftV.push_back(dirGaussV);
    //
    // std::array<double,3> dbgGrad={{1.0,0.0,0.0}};//DBG
    double localRhsU[3]={0.0};
    double localRhsV[3]={0.0};
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++){
    	localRhsU[k]+=dphidx[k][l]*dirGaussU[l]*dJac/2.;
    	localRhsV[k]+=dphidx[k][l]*dirGaussV[l]*dJac/2.;
      }
    // for(size_t k=0; k<3; k++)//DBG
    //   for(size_t l=0; l<3; l++){
    // 	localRhsU[k]+=dphidx[k][l]*dbgGrad[l]*dJac/2.;
    // 	localRhsV[k]+=dphidx[k][l]*dbgGrad[l]*dJac/2.;
    //   }
    HXT_CHECK(hxtLinearSystemAddToRhs(sys,rhsU,iT,localRhsU));
    HXT_CHECK(hxtLinearSystemAddToRhs(sys,rhsV,iT,localRhsV));
    //
  }
  //BC
  int iv=0;
  // std::array<double,3> coordPointIv={{mesh->vertices.coord[4*loc2GlobVert[iv]+0],mesh->vertices.coord[4*loc2GlobVert[iv]+1],mesh->vertices.coord[4*loc2GlobVert[iv]+2]}};
  // while(isPointSingularityOrCornerVec(&coordPointIv)){
  //   iv++;
  //   coordPointIv[0]=mesh->vertices.coord[4*loc2GlobVert[iv]+0];
  //   coordPointIv[1]=mesh->vertices.coord[4*loc2GlobVert[iv]+1];
  //   coordPointIv[2]=mesh->vertices.coord[4*loc2GlobVert[iv]+2];
  // }
  HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(sys,iv,0)); //BC. we fix a given node at 0 to remove all problems related to mean value not determined;
  HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,rhsU,iv,0,0));
  HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,rhsV,iv,0,0));
  
  blockParam.pointBC={{mesh->vertices.coord[4*loc2GlobVert[iv]+0],mesh->vertices.coord[4*loc2GlobVert[iv]+1],mesh->vertices.coord[4*loc2GlobVert[iv]+2]}};
  //
  double *solPotU;
  double *solPotV;
  HXT_CHECK(hxtMalloc(&solPotU, loc2GlobVert.size()*sizeof(double)));
  HXT_CHECK(hxtMalloc(&solPotV, loc2GlobVert.size()*sizeof(double)));
  HXT_CHECK(hxtLinearSystemSolve(sys,rhsU,solPotU));
  HXT_CHECK(hxtLinearSystemSolve(sys,rhsV,solPotV));
  HXT_CHECK(hxtLinearSystemDelete(&sys));

  //Fill blockParametrization object
  blockParam.m_triangles.clear();
  blockParam.m_triangles.reserve(loc2GlobTri.size());
  for(size_t k=0;k<loc2GlobTri.size();k++){
    blockParam.m_triangles.push_back(loc2GlobTri[k]);
  }
  blockParam.m_nodesParamCoord.clear();
  blockParam.m_nodesParamCoord.reserve(loc2GlobVert.size());
  for(size_t k=0;k<loc2GlobVert.size();k++){
    std::array<double,3> paramCoord={{0.0,0.0,0.0}};
    paramCoord[0]=solPotU[k];
    paramCoord[1]=solPotV[k];
    blockParam.m_nodesParamCoord.push_back(paramCoord);
  }
  blockParam.m_nodesParamToGlobal.clear();
  blockParam.m_nodesParamToGlobal.reserve(loc2GlobVert.size());
  for(size_t k=0;k<loc2GlobVert.size();k++){
    blockParam.m_nodesParamToGlobal.push_back(loc2GlobVert[k]);
  }
  blockParam.m_nodesGlobalToParam.clear();
  blockParam.m_nodesGlobalToParam.reserve(glob2LocVert.size());
  for(size_t k=0;k<glob2LocVert.size();k++){
    blockParam.m_nodesGlobalToParam.push_back(glob2LocVert[k]);
  }
  blockParam.m_trianglesGlobalToParam.clear();
  blockParam.m_trianglesGlobalToParam.reserve(glob2LocTri.size());
  for(size_t k=0;k<glob2LocTri.size();k++){
    blockParam.m_trianglesGlobalToParam.push_back(glob2LocTri[k]);
  }
  
  HXT_CHECK(hxtFree(&solPotU));
  HXT_CHECK(hxtFree(&solPotV));
  HXT_CHECK(hxtAlignedFree(&nodesLoc));
  // HXT_CHECK(hxtFree(&nodesLoc));
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::parametrizeBlock(std::vector<uint64_t> vectIdBlock, BlockParametrization &blockParam){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  std::set<uint64_t> setTriPatch;
  for(uint64_t iB: vectIdBlock){
    for(uint64_t t: m_mbBlockTriPatchs[iB]){
      setTriPatch.insert(t);
    }
  }
  //create patch tri numerotation
  size_t nTriangles = setTriPatch.size();
  uint32_t* nodesLoc;
  HXT_CHECK(hxtAlignedMalloc(&nodesLoc, 3*nTriangles*sizeof(uint32_t)));
  // HXT_CHECK(hxtMalloc(&nodesLoc, 3*nTriangles*sizeof(uint32_t)));
  std::vector<uint64_t> loc2GlobTri;
  std::vector<uint64_t> glob2LocTri(mesh->triangles.num,0);
  std::vector<bool> flaggedVert(mesh->vertices.num,false);
  std::vector<uint32_t> loc2GlobVert;
  std::vector<uint32_t> glob2LocVert(mesh->vertices.num,(uint32_t)(-1));
  for(uint64_t t: setTriPatch){
    for(size_t l=0;l<3;l++)
      flaggedVert[mesh->triangles.node[3*t+l]]=true;
  }
  for(uint32_t k=0;k<mesh->vertices.num;k++){
    if(flaggedVert[k]){
      loc2GlobVert.push_back(k);
      glob2LocVert[k]=loc2GlobVert.size()-1;
    }
  }
  for(uint64_t t: setTriPatch){
    loc2GlobTri.push_back(t);
    glob2LocTri[t]=loc2GlobTri.size()-1;
    for(size_t l=0;l<3;l++){
      nodesLoc[3*glob2LocTri[t]+l]=glob2LocVert[mesh->triangles.node[3*t+l]];
    }
  }
  //DBG
  if(nTriangles!=loc2GlobTri.size()){
    std::cout << "error counting triangles number" << std::endl;
    exit(0);
  }
  for(uint32_t k=0;k<loc2GlobTri.size();k++){
    if(k!=glob2LocTri[loc2GlobTri[k]]){
      std::cout << "error building correspondance triangles tables" << std::endl;
      exit(0);
    }
  }
  for(uint32_t k=0;k<loc2GlobVert.size();k++){
    if(k!=glob2LocVert[loc2GlobVert[k]]){
      std::cout << "error building correspondance vertices tables" << std::endl;
      exit(0);
    }
  }
  for(uint64_t k=0;k<loc2GlobTri.size();k++){
    for(size_t l=0;l<3;l++){
      if(loc2GlobVert[nodesLoc[3*k+l]]!=mesh->triangles.node[3*loc2GlobTri[k]+l]){
  	std::cout << "error new connectivity" << std::endl;
	std::cout << "patch: " << vectIdBlock[0] << std::endl;
  	exit(0);
      }
    }
  }
  //
  std::vector<std::array<double,3>> coordLoc;
  for(size_t k=0;k<loc2GlobVert.size();k++){
    uint32_t globInd=loc2GlobVert[k];
    std::array<double,3> coord={{mesh->vertices.coord[4*globInd+0],mesh->vertices.coord[4*globInd+1],mesh->vertices.coord[4*globInd+2]}};
    coordLoc.push_back(coord);
  }
  std::vector<std::array<double,3>> liftU;//3*triLocNum+edgLoc
  std::array<double,3> init={{0.0,0.0,0.0}};//DBG
  liftU.resize(3*nTriangles,init);//DBG
  std::vector<std::array<double,3>> liftV;//3*triLocNum+edgLoc
  liftV.resize(3*nTriangles,init);//DBG
  uint64_t refTriGlob=loc2GlobTri[0];
  uint32_t vtriRef[3] = {mesh->triangles.node[3*refTriGlob+0],mesh->triangles.node[3*refTriGlob+1],mesh->triangles.node[3*refTriGlob+2]};
  double U[3]={0.}, V[3]={0.}, n[3]={0.};	
  trianglebasis(mesh,vtriRef,U,V,n);
  std::array<double,3> dirRefU;
  std::array<double,3> dirRefV;
  uint32_t edgeRefGlob=edges->tri2edg[3*refTriGlob+0];
  double theta=atan2(m_crossfield[2*edgeRefGlob+1],m_crossfield[2*edgeRefGlob+0])/4.;
  for(size_t k=0;k<3;k++){
    dirRefU[k]=cos(theta)*U[k]+sin(theta)*V[k];
    dirRefV[k]=-sin(theta)*U[k]+cos(theta)*V[k];
  }
  getCrossesLifting(loc2GlobTri,glob2LocTri,liftU,refTriGlob,dirRefU);
  getCrossesLifting(loc2GlobTri,glob2LocTri,liftV,refTriGlob,dirRefV);

  HXTLinearSystem *sys;
  // we definitely use PETSc solver if it is enabled
  // #if defined(HXT_HAVE_PETSC)
  //     std::cout << "have petsc" << std::endl;
  //     exit(0);
  // #else
  //     std::cout << "not have petsc" << std::endl;
  //     exit(0);
  // #endif
  // HXT_CHECK(hxtLinearSystemCreatePETSc(&sys,nTriangles,3,2,edges->tri2edg,"-pc_type lu"));
  // #else
  HXT_CHECK(hxtLinearSystemCreateLU(&sys,nTriangles,3,1,nodesLoc));
  // #endif
  double *rhsU;
  HXT_CHECK(hxtMalloc(&rhsU, loc2GlobVert.size()*sizeof(double)));
  double *rhsV;
  HXT_CHECK(hxtMalloc(&rhsV, loc2GlobVert.size()*sizeof(double)));
  for(size_t k=0; k<loc2GlobVert.size(); k++){
    rhsU[k]=0.0;
    rhsV[k]=0.0;
  }

  //DBG
  blockParam.liftU.clear();
  blockParam.liftU.reserve(nTriangles);
  // blockParam.liftU.resize(nTriangles,init);
  blockParam.liftV.clear();
  blockParam.liftV.reserve(nTriangles);
  blockParam.scaling.clear();
  blockParam.scaling.reserve(nTriangles);
  //
  for(size_t iT=0;iT<nTriangles;iT++){
    double vtri[9] = {0.};
    for(int i=0; i<3; i++)
      for(int j=0; j<3; j++){
	vtri[3*i+j] = mesh->vertices.coord[4*loc2GlobVert[nodesLoc[3*iT+i]]+j];
      }
    // uint32_t vtri[3] = {mesh->triangles.node[3*loc2GlobTri[iT]+0],mesh->triangles.node[3*loc2GlobTri[iT]+1],mesh->triangles.node[3*loc2GlobTri[iT]+2]};
    double grad[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
  
    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
			{0,0,0}};
    HXT_CHECK(myNormalizedCrossprod(jac[0],jac[1],jac[2]));
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double dphidx[3][3];
    for(uint32_t i=0; i<3; i++){
      dphidx[i][0] = dphidx[i][1] = dphidx[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
	dphidx[i][0] += grad[i][j]*invjac[0][j];
	dphidx[i][1] += grad[i][j]*invjac[1][j];
	dphidx[i][2] += grad[i][j]*invjac[2][j];
      }
    }
    double localMatrix[3*3]={0.0};
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++)
	for(size_t m=0; m<3; m++)
	  localMatrix[3*k+l]+=dphidx[k][m]*dphidx[l][m]*dJac/2.;
    HXT_CHECK(hxtLinearSystemAddToMatrix(sys,iT,iT,localMatrix));
    std::array<double,3> dirGaussU={{0.0,0.0,0.0}};
    std::array<double,3> dirGaussV={{0.0,0.0,0.0}};
    // for(size_t k=0; k<3; k++)//DBG
    //   for(size_t l=0; l<3; l++){
    // 	dirGaussU[k]+=liftU[3*iT+l][k]*1./3.;
    // 	dirGaussV[k]+=liftV[3*iT+l][k]*1./3.;
    //   }
    for(size_t k=0; k<3; k++)//DBG
      for(size_t l=0; l<3; l++){
	dirGaussU[k]+=liftU[3*iT+l][k];
	dirGaussV[k]+=liftV[3*iT+l][k];
      }
    double scalingLoc=0.0;
    for(size_t k=0; k<3; k++)
      scalingLoc+=(exp(-m_scalingFactorCrosses[3*loc2GlobTri[iT]+k]))*1./3.;
    // for(size_t k=2; k<3; k++)//DBG
    //   scalingLoc+=(exp(-m_scalingFactorCrosses[3*loc2GlobTri[iT]+k]));
    for(size_t k=0; k<3; k++){
      dirGaussU[k]*=scalingLoc;
      dirGaussV[k]*=scalingLoc;
    }
    
    //DBG
    blockParam.liftU.push_back(dirGaussU);
    blockParam.scaling.push_back(scalingLoc);
    // blockParam.liftU.push_back(liftU[3*iT+0]);//DBG
    blockParam.liftV.push_back(dirGaussV);
    //
    // std::array<double,3> dbgGrad={{1.0,0.0,0.0}};//DBG
    double localRhsU[3]={0.0};
    double localRhsV[3]={0.0};
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++){
    	localRhsU[k]+=dphidx[k][l]*dirGaussU[l]*dJac/2.;
    	localRhsV[k]+=dphidx[k][l]*dirGaussV[l]*dJac/2.;
      }
    // for(size_t k=0; k<3; k++)//DBG
    //   for(size_t l=0; l<3; l++){
    // 	localRhsU[k]+=dphidx[k][l]*dbgGrad[l]*dJac/2.;
    // 	localRhsV[k]+=dphidx[k][l]*dbgGrad[l]*dJac/2.;
    //   }
    HXT_CHECK(hxtLinearSystemAddToRhs(sys,rhsU,iT,localRhsU));
    HXT_CHECK(hxtLinearSystemAddToRhs(sys,rhsV,iT,localRhsV));
    //
  }
  //BC
  int iv=0;
  // std::array<double,3> coordPointIv={{mesh->vertices.coord[4*loc2GlobVert[iv]+0],mesh->vertices.coord[4*loc2GlobVert[iv]+1],mesh->vertices.coord[4*loc2GlobVert[iv]+2]}};
  // while(isPointSingularityOrCornerVec(&coordPointIv)){
  //   iv++;
  //   coordPointIv[0]=mesh->vertices.coord[4*loc2GlobVert[iv]+0];
  //   coordPointIv[1]=mesh->vertices.coord[4*loc2GlobVert[iv]+1];
  //   coordPointIv[2]=mesh->vertices.coord[4*loc2GlobVert[iv]+2];
  // }
  HXT_CHECK(hxtLinearSystemSetMatrixRowIdentity(sys,iv,0)); //BC. we fix a given node at 0 to remove all problems related to mean value not determined;
  HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,rhsU,iv,0,0));
  HXT_CHECK(hxtLinearSystemSetRhsEntry(sys,rhsV,iv,0,0));
  
  blockParam.pointBC={{mesh->vertices.coord[4*loc2GlobVert[iv]+0],mesh->vertices.coord[4*loc2GlobVert[iv]+1],mesh->vertices.coord[4*loc2GlobVert[iv]+2]}};
  //
  double *solPotU;
  double *solPotV;
  HXT_CHECK(hxtMalloc(&solPotU, loc2GlobVert.size()*sizeof(double)));
  HXT_CHECK(hxtMalloc(&solPotV, loc2GlobVert.size()*sizeof(double)));
  HXT_CHECK(hxtLinearSystemSolve(sys,rhsU,solPotU));
  HXT_CHECK(hxtLinearSystemSolve(sys,rhsV,solPotV));
  HXT_CHECK(hxtLinearSystemDelete(&sys));

  //Fill blockParametrization object
  blockParam.m_triangles.clear();
  blockParam.m_triangles.reserve(loc2GlobTri.size());
  for(size_t k=0;k<loc2GlobTri.size();k++){
    blockParam.m_triangles.push_back(loc2GlobTri[k]);
  }
  blockParam.m_nodesParamCoord.clear();
  blockParam.m_nodesParamCoord.reserve(loc2GlobVert.size());
  for(size_t k=0;k<loc2GlobVert.size();k++){
    std::array<double,3> paramCoord={{0.0,0.0,0.0}};
    paramCoord[0]=solPotU[k];
    paramCoord[1]=solPotV[k];
    blockParam.m_nodesParamCoord.push_back(paramCoord);
  }
  blockParam.m_nodesParamToGlobal.clear();
  blockParam.m_nodesParamToGlobal.reserve(loc2GlobVert.size());
  for(size_t k=0;k<loc2GlobVert.size();k++){
    blockParam.m_nodesParamToGlobal.push_back(loc2GlobVert[k]);
  }
  blockParam.m_nodesGlobalToParam.clear();
  blockParam.m_nodesGlobalToParam.reserve(glob2LocVert.size());
  for(size_t k=0;k<glob2LocVert.size();k++){
    blockParam.m_nodesGlobalToParam.push_back(glob2LocVert[k]);
  }
  blockParam.m_trianglesGlobalToParam.clear();
  blockParam.m_trianglesGlobalToParam.reserve(glob2LocTri.size());
  for(size_t k=0;k<glob2LocTri.size();k++){
    blockParam.m_trianglesGlobalToParam.push_back(glob2LocTri[k]);
  }
  
  HXT_CHECK(hxtFree(&solPotU));
  HXT_CHECK(hxtFree(&solPotV));
  HXT_CHECK(hxtAlignedFree(&nodesLoc));
  // HXT_CHECK(hxtFree(&nodesLoc));
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::dbgPosFlagSetTri(const std::set<uint64_t> &tri, const char *fileName){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  fprintf(f,"View \"flaggedTri\" {\n");
  for(uint64_t triNum: tri){
    std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
    std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
    std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+2]}};
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%i,%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], 1,1,1);
  }
  fprintf(f,"};");  
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::dbgPosEdgData(const char *fileName){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  for(size_t k=0;k<m_mbEdges.size();k++){
  // for(size_t k=0;k<1;k++){
    std::vector<std::array<double, 3>> pointsOnEdg;
    std::vector<uint64_t> trianglesOnEdg;
    getDataFromBlockEdgID(k, pointsOnEdg, trianglesOnEdg);
    fprintf(f,"View \"mbEdg data\" {\n");
    for(uint64_t i=0; i<pointsOnEdg.size(); i++){
      fprintf(f,"SP(%g,%g,%g){%i};\n", pointsOnEdg[i][0], pointsOnEdg[i][1], pointsOnEdg[i][2], k);
      if(i!=pointsOnEdg.size()-1)
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", pointsOnEdg[i][0],  pointsOnEdg[i][1],  pointsOnEdg[i][2],  pointsOnEdg[i+1][0],  pointsOnEdg[i+1][1],  pointsOnEdg[i+1][2], k,k);
      uint64_t triNum=trianglesOnEdg[i];
      std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
      std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
      std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+2]}};
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%i,%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], k,k,k);

    }
    fprintf(f,"};");  
  }
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::dbgPosParametrization(const char *fileName){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  for(size_t k=0;k<m_mbEdges.size();k++){
  // for(size_t k=0;k<1;k++){
    std::vector<std::array<double, 3>> pointsOnEdg;
    std::vector<uint64_t> trianglesOnEdg;
    getDataFromBlockEdgID(k, pointsOnEdg, trianglesOnEdg);
    fprintf(f,"View \"mbEdg data\" {\n");
    for(uint64_t i=0; i<pointsOnEdg.size(); i++){
      fprintf(f,"SP(%g,%g,%g){%i};\n", pointsOnEdg[i][0], pointsOnEdg[i][1], pointsOnEdg[i][2], k);
      if(i!=pointsOnEdg.size()-1)
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%i,%i};\n", pointsOnEdg[i][0],  pointsOnEdg[i][1],  pointsOnEdg[i][2],  pointsOnEdg[i+1][0],  pointsOnEdg[i+1][1],  pointsOnEdg[i+1][2], k,k);
      uint64_t triNum=trianglesOnEdg[i];
      std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
      std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
      std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+2]}};
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%i,%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], k,k,k);

    }
    fprintf(f,"};");  
  }
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::dbgPosPatchData(const char *fileName){
  HXTEdges* edges=m_Edges;
  HXTMesh *mesh = edges->edg2mesh;
  FILE *f = fopen(fileName,"w");
  for(size_t k=0;k<m_mbBlockTriPatchs.size();k++){
  // for(size_t k=0;k<1;k++){
    std::vector<std::array<double, 3>> pointsOnEdg;
    std::vector<uint64_t> trianglesOnEdg;
    getDataFromBlockEdgID(k, pointsOnEdg, trianglesOnEdg);
    fprintf(f,"View \"tri patch block\" {\n");
    for(uint64_t triNum: m_mbBlockTriPatchs[k]){
      std::array<double,3> point1={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+0]+2]}};
      std::array<double,3> point2={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+1]+2]}};
      std::array<double,3> point3={{mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+0],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+1],mesh->vertices.coord[4*mesh->triangles.node[3*triNum+2]+2]}};
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%i,%i,%i};\n", point1[0],  point1[1],  point1[2],  point2[0],  point2[1],  point2[2],  point3[0],  point3[1],  point3[2], k,k,k);

    }
    fprintf(f,"};");  
  }
  fclose(f);
  return HXT_STATUS_OK;
}

//ADD alpha nad beta in return
int MultiBlock::isPointInTri(uint64_t tri, std::array<double, 3> point, double *distance1, double *distance2){
  *distance1 = -1.0;
  *distance2 = -1.0;
  HXTEdges *edges = m_Edges; 
  HXTMesh *mesh = edges->edg2mesh; //from starting, original mesh
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  double orientationABM, orientationBCM, orientationCAM;
  int pointIsInTri=0;
  
  double AB[3]={vert[4*nodes[3*tri+1]+0]-vert[4*nodes[3*tri+0]+0], vert[4*nodes[3*tri+1]+1]-vert[4*nodes[3*tri+0]+1], vert[4*nodes[3*tri+1]+2]-vert[4*nodes[3*tri+0]+2]};
  double AC[3]={vert[4*nodes[3*tri+2]+0]-vert[4*nodes[3*tri+0]+0], vert[4*nodes[3*tri+2]+1]-vert[4*nodes[3*tri+0]+1], vert[4*nodes[3*tri+2]+2]-vert[4*nodes[3*tri+0]+2]};
  double AM[3]={point[0]-vert[4*nodes[3*tri+0]+0],point[1]-vert[4*nodes[3*tri+0]+1],point[2]-vert[4*nodes[3*tri+0]+2]};
  double nABC[3]={0.0,0.0,0.0}; double AMxAB[3]={0.0,0.0,0.0}; double AMxAC[3]={0.0,0.0,0.0}; double  ACxAB[3]={0.0,0.0,0.0};
  crossprod(AB, AC, nABC);
  crossprod(AM, AB, AMxAB);
  crossprod(AM, AC, AMxAC);
  crossprod(AC, AB, ACxAB);

  double alpha = myDot(AMxAC, nABC)/myDot(nABC, nABC);
  double beta = myDot(AMxAB, nABC)/myDot(ACxAB, nABC);
  double numError =1e-10;
  if((alpha>-numError) && (beta>-numError) && (alpha<1.0+numError) && beta<(1-alpha+numError)){
    pointIsInTri=1;
    *distance1 = alpha;
    *distance2 = beta;
  } 
  
  return pointIsInTri;
}

HXTStatus MultiBlock::getTriNumFromPointCoord(std::array<double, 3> pointCoord, std::vector<uint64_t> vectorTriangles, uint64_t *triNum, double *alpha, double *beta){

  *alpha = -1.0;
  *beta = -1.0;
  int found=0;
  int pointIsInTri=0;
  *triNum = (uint64_t)-1;
  for(uint64_t i=0; i<vectorTriangles.size(); i++){
    if(found==0){
      pointIsInTri = isPointInTri(vectorTriangles[i],  pointCoord, alpha, beta);
      if(pointIsInTri == 1){
	*triNum = vectorTriangles[i];
	found = 1;
      }
    }
  }

  if(*triNum == (uint64_t)-1){
    std::cout << "++++++++++++++++++++++++ no triangle found +++++++++++++++++++" << std::endl;
  }


  
  //print DBG file--------------------------------------------------------------
  // HXTEdges *edges = m_Edges; 
  // HXTMesh *mesh = edges->edg2mesh; //from starting, original mesh
  // double *vert = mesh->vertices.coord;
  // uint32_t* nodes = mesh->triangles.node;
  // uint64_t *elemFlagged;
  // HXT_CHECK(hxtMalloc(&elemFlagged, mesh->triangles.num*sizeof(uint64_t)));
  // for(uint64_t i=0; i<mesh->triangles.num; i++)
  //   elemFlagged[i]=0;
  // elemFlagged[(*triNum)]=1;
  // FILE *f = fopen("jovana.pos","w");
  // fprintf(f,"View \"Nodes\" {\n");
  // fprintf(f,"SP(%g,%g,%g){%i};\n", pointCoord[0],pointCoord[1], pointCoord[2], 1); 
  // fprintf(f,"};");
  // fprintf(f,"View \"Flagged patches\"{\n");
  // for(uint64_t i=0; i<mesh->triangles.num; i++){
  //   fprintf(f,"ST(");
  //   uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
  //   for(uint32_t j=0; j<3; j++){
  //     fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
  //     if(j<2)
  //       fprintf(f,",");
  //   }
  //   fprintf(f,")");
  //   fprintf(f,"{");
  //   fprintf(f,"%i, %i, %i",elemFlagged[i],elemFlagged[i],elemFlagged[i]);
  //   fprintf(f,"};\n");    
  // }
  // fprintf(f,"};");
  // fclose(f); 
  // HXT_CHECK(hxtFree(&elemFlagged));
  

  return  HXT_STATUS_OK;
}



double MultiBlock::normDiffVect(std::array<double,3> *coordP1, std::array<double,3> *coordP2){
  double L=0;
  for(uint64_t k=0;k<(*coordP1).size();k++)
    L+=((*coordP2)[k]-(*coordP1)[k])*((*coordP2)[k]-(*coordP1)[k]);
  L=sqrt(L);
  return L;
}

double MultiBlock::computeDiscreteLineLength(std::vector<std::array<double,3>> *pCoordLine){
  double length=0.0;
  for(uint64_t i=0;i<pCoordLine->size()-1;i++){
    std::array<double,3> *coordP1 = &((*pCoordLine)[i]);
    std::array<double,3> *coordP2 = &((*pCoordLine)[i+1]);
    length+=normDiffVect(coordP2,coordP1);
  } 
  return length;
}

double MultiBlock::computeDiscreteLineLengthModified(std::vector<std::array<double,3>> *pCoordLine, std::vector<double> hVal){
  double length=0.0;
  for(uint64_t i=0;i<pCoordLine->size()-1;i++){
    std::array<double,3> *coordP1 = &((*pCoordLine)[i]);
    std::array<double,3> *coordP2 = &((*pCoordLine)[i+1]);
    length+=(normDiffVect(coordP2,coordP1)*((hVal[i]+hVal[i+1])/2.0));
  } 
  
  return length;
}

HXTStatus MultiBlock::lineDiscretization(std::vector<std::array<double,3>> *line, std::vector<double> hVal, uint64_t partition, std::vector<std::array<double,3>> *newLine){
  double edgLength=computeDiscreteLineLengthModified(line, hVal);
  double elemLength=edgLength/(1.0*partition);
  int currentIndice=1;
  (*newLine)[0]=(*line)[0];
  int nAddPoints=1;
  std::array<double,3> precPoint={{0.0,0.0,0.0}};
  double cumulLength=0.0;
  double currentLength=0.0;
  for(uint64_t k=0;k<partition-1;k++){
    double precLength=0.0;
    currentLength=0.0;
    precPoint=(*newLine)[nAddPoints-1];
    currentLength+=(normDiffVect(&((*line)[currentIndice]),&precPoint)*((hVal[currentIndice-1]+hVal[currentIndice])/2.0));
    while(currentLength<elemLength){
      precPoint=(*line)[currentIndice];
      currentIndice++;
      if(currentIndice==(int)line->size())
	break;
      precLength=currentLength;
      currentLength+=(normDiffVect(&((*line)[currentIndice]),&precPoint)*((hVal[currentIndice-1]+hVal[currentIndice])/2.0));
    }
    std::array<double,3> coordNewPoint={{0.0,0.0,0.0}};
    if(currentIndice==(int)line->size()){
      for(uint64_t i=0;i<coordNewPoint.size();i++)
    	coordNewPoint[i]=((*line)[line->size()-1])[i];
    }
    else{
      double alpha=(elemLength-precLength)/((normDiffVect(&((*line)[currentIndice]),&precPoint))*((hVal[currentIndice-1]+hVal[currentIndice])/2.0));
      for(uint64_t i=0;i<coordNewPoint.size();i++){
    	coordNewPoint[i]=precPoint[i] + alpha*(((*line)[currentIndice])[i]-precPoint[i]);
      }
      cumulLength+=precLength+alpha*normDiffVect(&((*line)[currentIndice]),&precPoint)*((hVal[currentIndice-1]+hVal[currentIndice])/2.0);
    }
    (*newLine)[nAddPoints]=coordNewPoint;
    nAddPoints++;
  }
  std::array<double,3> coordNewPoint={{0.0,0.0,0.0}};
  for(uint64_t i=0;i<coordNewPoint.size();i++)
    coordNewPoint[i]=((*line)[line->size()-1])[i];
  (*newLine)[nAddPoints]=coordNewPoint;
  nAddPoints++;
  FILE *f = fopen("newLine.pos","w");
  fprintf(f,"View \"Nodes\" {\n");

  for(uint64_t i=0; i<newLine->size(); i++){
    int color=static_cast<int>(i);
    fprintf(f,"SP(%g,%g,%g){%i};\n", (*newLine)[i][0], (*newLine)[i][1], (*newLine)[i][2], color);
  }
  fprintf(f,"};");
  fclose(f); 
  
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::lineDiscretizationUniform(std::vector<std::array<double,3>> *line, uint64_t partition, std::vector<std::array<double,3>> *newLine){
  double edgLength=computeDiscreteLineLength(line);
  double elemLength=edgLength/(1.0*partition);
  int currentIndice=1;
  (*newLine)[0]=(*line)[0];
  int nAddPoints=1;
  std::array<double,3> precPoint={{0.0,0.0,0.0}};
  double cumulLength=0.0;
  double currentLength=0.0;
  for(uint64_t k=0;k<partition-1;k++){
    double precLength=0.0;
    currentLength=0.0;
    precPoint=(*newLine)[nAddPoints-1];
    currentLength+=normDiffVect(&((*line)[currentIndice]),&precPoint);
    while(currentLength<elemLength){
      precPoint=(*line)[currentIndice];
      currentIndice++;
      if(currentIndice==(int)line->size())
	break;
      precLength=currentLength;
      currentLength+=normDiffVect(&((*line)[currentIndice]),&precPoint);
    }
    std::array<double,3> coordNewPoint={{0.0,0.0,0.0}};
    if(currentIndice==(int)line->size()){
      for(uint64_t i=0;i<coordNewPoint.size();i++)
    	coordNewPoint[i]=((*line)[line->size()-1])[i];
    }
    else{
      double alpha=(elemLength-precLength)/(normDiffVect(&((*line)[currentIndice]),&precPoint));
      for(uint64_t i=0;i<coordNewPoint.size();i++){
    	coordNewPoint[i]=precPoint[i] + alpha*(((*line)[currentIndice])[i]-precPoint[i]);
      }
      cumulLength+=precLength+alpha*normDiffVect(&((*line)[currentIndice]),&precPoint);
    }
    (*newLine)[nAddPoints]=coordNewPoint;
    nAddPoints++;
  }
  std::array<double,3> coordNewPoint={{0.0,0.0,0.0}};
  for(uint64_t i=0;i<coordNewPoint.size();i++)
    coordNewPoint[i]=((*line)[line->size()-1])[i];
  (*newLine)[nAddPoints]=coordNewPoint;
  nAddPoints++;
  FILE *f = fopen("newLine.pos","w");
  fprintf(f,"View \"Nodes\" {\n");

  for(uint64_t i=0; i<newLine->size(); i++){
    int color=static_cast<int>(i);
    fprintf(f,"SP(%g,%g,%g){%i};\n", (*newLine)[i][0], (*newLine)[i][1], (*newLine)[i][2], color);
  }
  fprintf(f,"};");
  fclose(f); 
  
  return HXT_STATUS_OK;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

HXTStatus MultiBlock::meshQuadLayout(std::vector<double> hVal){
  // std::cout<<"collect T-junction indices"<<std::endl;
  // collectTJunctionIndices();
  // std::cout<<"num T-junctions: "<< m_extraordVertTjunc.size()<<std::endl;
  // std::cout<<"--Store points of quad edges--"<<std::endl;
  // getQuadEdgesData();
  // std::cout<<"--Get Block2Edg--"<<std::endl; 
  // getBlock2Edge();
  // std::cout<<"--Get Edge2Block--"<<std::endl;
  // getEdge2Block();

  for(uint64_t t=0; t<m_mbQuads.size(); t++){
    std::cout<<"Block: "<<t <<" nVertices: "<<m_mbQuads[t].size()<<", nEdges: "<< m_mbBlock2Edg[t].size()<<std::endl;
    for(uint64_t k=0; k<m_mbQuads[t].size(); k++)
      std::cout << m_mbQuads[t][k] << " , " ;
    std::cout << std::endl;
    std::cout << "edges : ";
    for(uint64_t k=0; k<m_mbBlock2Edg[t].size(); k++)
      std::cout << m_mbBlock2Edg[t][k] << " , ";
    std::cout << std::endl;
  }
  for(uint64_t t=0; t<m_mbEdg2Block.size(); t++){
    std::cout << "edge : " << t << " nBlocks : " << m_mbEdg2Block[t].size() << std::endl;
    for(uint64_t k=0; k<m_mbEdg2Block[t].size(); k++)
      std::cout << m_mbEdg2Block[t][k] << " , ";
    std::cout << std::endl;
  }
  // std::cout<<"triPatches"<<std::endl;
  // std::vector<int> triPatchesIDs;
  // getTriangularPatchesIDs(&triPatchesIDs);
  // std::cout<<"num triPatches: "<< triPatchesIDs.size()<<std::endl;
  // std::cout<<"T-junction patches"<<std::endl;
  // std::vector<int> tJunctionPatchesIDs;
  // getTJunctionsPatchesIDs(&tJunctionPatchesIDs);
  // std::cout<<"num T-junction patches: "<< tJunctionPatchesIDs.size()<<std::endl;
  // for(uint64_t mt=0; mt<tJunctionPatchesIDs.size(); mt++)
  //   std::cout<<"T-junc patch ID: "<<tJunctionPatchesIDs[mt]<<std::endl;

  // dbgPosEdgData("dbgEdgData.pos"); 
  // createMbTriPatchs();
  // dbgPosPatchData("dbgBlockPatch.pos");
  // std::vector<std::array<double, 3>> pointsOnEdg;
  // std::vector<uint64_t> trianglesOnEdg;
  // std::cout<<"grabingEdgData "<<std::endl;
  // getDataFromBlockEdgID(m_mbBlock2Edg[0][0], &pointsOnEdg, &trianglesOnEdg);
  
   
  std::cout<<"--Get sheets--"<<std::endl;
  getAllSheets();
  std::cout<<"Num sheets: "<<m_Sheets.size()<<std::endl;
  for(uint64_t s=0; s<m_Sheets.size(); s++){
    std::cout<<"sheet "<<s<<", edges:";
    for(uint64_t l=0; l<m_Sheets[s].size(); l++)
      std::cout<<" "<<m_Sheets[s][l];
    std::cout << std::endl;
  }
  std::cout<<" "<<std::endl;
  std::cout<<"--Get and store partition per edge--"<<std::endl;

  // computeAdequatePartitionPerEdge(m_minEdgLength/(5.0), hVal);
  //computeAdequatePartitionPerEdge(m_minEdgLength/(1.0), hVal);
  computeAdequatePartitionPerEdge(0.02, hVal);
  //computeAdequatePartitionPerEdge(3*m_minEdgLength, hVal);
  // computeAdequatePartitionPerEdge(m_sizeQuadMesh, hVal);
  for(uint64_t i=0;i<m_extraordVertices.size();i++){
    m_coordVerticesDiscretization.push_back(m_extraordVertices[i]);
  }
  std::cout<<"--Discretize edges--"<<std::endl;
  discretizeEdges(hVal);
  std::cout<<"--Discretize quads--"<<std::endl;
  discretizeQuads();
  // m_meshMbQuadsExists=1;
  
  return HXT_STATUS_OK;
}


int MultiBlock::getParallelEdg(int blockNum, uint64_t edg1, uint64_t *edg2){
  uint64_t e1, e2, e3, e4;
  if(blockNum!=-1){ 
    e1=m_mbBlock2Edg[blockNum][0];
    e2=m_mbBlock2Edg[blockNum][1];
    e3=m_mbBlock2Edg[blockNum][2];
    e4=m_mbBlock2Edg[blockNum][3];
    if(edg1==e1)
      *edg2=e3;
    if(edg1==e2)
      *edg2=e4;
    if(edg1==e3)
      *edg2=e1;
    if(edg1==e4)
      *edg2=e2;
  }else{
    *edg2=(uint64_t)-1;
  }
  
  return 1;
}

int MultiBlock::getAllSheets(){
  std::vector<bool> edgCollected(m_mbEdges.size(),0);
  std::vector<uint64_t> currentSheet;
  m_Sheets.reserve(100);
  for(uint64_t ie=0; ie<m_mbEdges.size(); ie++){
    if(!(edgCollected[ie])){
      currentSheet.clear();
      currentSheet.reserve(100);
      //Check if block is not quad. In this case, consider that it's not part of the domain (puting -1 or something in this manner)
      uint64_t q0 = (uint64_t)(-1);
      uint64_t q1 = (uint64_t)(-1);
      q0 = m_mbEdg2Block[ie][0];
      if(m_mbEdg2Block[ie].size()>1)
	q1 = m_mbEdg2Block[ie][1];
      uint64_t currentEdg=ie;
      uint64_t currentQ = q0;
      uint64_t nextEdg;	
      bool didLoop=0;
      while(!didLoop && currentQ!=(uint64_t)-1){
	currentSheet.push_back(currentEdg);
	edgCollected[currentEdg]=1;
	getParallelEdg(currentQ, currentEdg, &nextEdg);
	if(nextEdg==ie)
	  didLoop=1;
	currentEdg=nextEdg;
	q0 = m_mbEdg2Block[currentEdg][0];
	q1=(uint64_t)(-1);
	if(m_mbEdg2Block[currentEdg].size()>1)
	  q1 = m_mbEdg2Block[currentEdg][1];
	if(q0!=currentQ)
	  currentQ=q0;
	else if(q1!=(uint64_t)-1 && q1!=currentQ)
	  currentQ=q1;
	else
	  currentQ=(uint64_t)-1;
      }
      if(!didLoop){
	currentSheet.push_back(nextEdg);
	edgCollected[nextEdg]=1;
      }
      q1=(uint64_t)(-1);
      if(m_mbEdg2Block[ie].size()>1)
	q1 = m_mbEdg2Block[ie][1];
      currentEdg=ie;
      currentQ=q1;
      if(currentQ!=(uint64_t)-1){
	getParallelEdg(currentQ, currentEdg, &nextEdg);
	if(nextEdg==ie)
	  didLoop=1;
	currentEdg=nextEdg;
	q0 = m_mbEdg2Block[currentEdg][0];
	q1=(uint64_t)(-1);
	if(m_mbEdg2Block[currentEdg].size()>1)
	  q1 = m_mbEdg2Block[currentEdg][1];
	if(q0!=currentQ)
	  currentQ=q0;
	else if(q1!=(uint64_t)-1 && q1!=currentQ)
	  currentQ=q1;
	else
	  currentQ=(uint64_t)-1;
      }	
      while(!didLoop && currentQ!=(uint64_t)-1){
	currentSheet.push_back(currentEdg);
	edgCollected[currentEdg]=1;
	getParallelEdg(currentQ, currentEdg, &nextEdg);
	if(nextEdg==ie)
	  didLoop=1;
	currentEdg=nextEdg;
	q0 = m_mbEdg2Block[currentEdg][0];
	q1=(uint64_t)(-1);
	if(m_mbEdg2Block[currentEdg].size()>1)
	  q1 = m_mbEdg2Block[currentEdg][1];
	if(q0!=currentQ)
	  currentQ=q0;
	else if(q1!=(uint64_t)-1 && q1!=currentQ)
	  currentQ=q1;
	else
	  currentQ=(uint64_t)-1;
      }
      if(!didLoop){
	currentSheet.push_back(nextEdg);
	edgCollected[nextEdg]=1;
      }
      m_Sheets.push_back(currentSheet);
    }
  }
  return 1;
}

int MultiBlock::computeAdequatePartitionPerEdge(double sizeofElement, std::vector<double> hVal){
  int *partitionPerSheet;
  HXT_CHECK(hxtMalloc(&partitionPerSheet, (m_Sheets.size())*sizeof(int)));
  double length=-1.;
  int  minPartition;
  uint64_t edgNum, currentEdg;
  std::vector<std::array<double,3>> pCoordLine;
  std::vector<uint64_t> sheetEdges;
  //  getting partition per sheet
  for(uint64_t i=0; i<m_Sheets.size(); i++){
    sheetEdges=m_Sheets[i];
    int *partitions;
    HXT_CHECK(hxtMalloc(&partitions, (sheetEdges.size())*sizeof(int)));
    for(uint64_t j=0; j<m_Sheets[i].size(); j++){   
      edgNum=sheetEdges[j];
      pCoordLine=m_mbEdges[edgNum];
      // length=computeDiscreteLineLengthModified(&pCoordLine, hVal);
      length=computeDiscreteLineLength(&pCoordLine);
      partitions[j]=(int)(length/sizeofElement);
      if(partitions[j]==0)
  	partitions[j]+=1;
      else{
  	if((sizeofElement-length/(1.0*partitions[j]+1))<(length/(1.0*partitions[j])-sizeofElement))
  	  partitions[j]+=1;
      }
    }
    minPartition=partitions[0];
    for(uint64_t k=1; k<m_Sheets[i].size(); k++){
      if(minPartition>partitions[k])
  	minPartition=partitions[k];
    }
    partitionPerSheet[i]=minPartition;
    HXT_CHECK(hxtFree(&partitions));
  }
   
  //get and store partition per edge
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    currentEdg=i;
    uint64_t sheetNumber=0;
    for(uint64_t j=0; j<m_Sheets.size(); j++){
      sheetEdges=m_Sheets[j];
      for(uint64_t k=0; k<sheetEdges.size(); k++){
	if(sheetEdges[k]==currentEdg){
	  sheetNumber=j;
	}
      }
    }
    m_partitionPerEdge.push_back(partitionPerSheet[sheetNumber]);
  }

   
  HXT_CHECK(hxtFree(&partitionPerSheet));    
  return 1;
}

int MultiBlock::computeAdequatePartitionPerEdgeV2(double sizeofElement, std::vector<double> hVal){
  //Get smallest edge to get reference element length in parametric space
  double minLength=std::numeric_limits<double>::max();
  uint64_t refEdg=(uint64_t)(-1);
  int partitionRef=0;
  for(uint64_t i=0; i<m_Sheets.size(); i++){
    std::vector<uint64_t> sheetEdges=m_Sheets[i];
    for(uint64_t j=0; j<m_Sheets[i].size(); j++){
      uint64_t edgNum=sheetEdges[j];
      std::vector<std::array<double,3>> pCoordLine=m_mbEdges[edgNum];
      double length=computeDiscreteLineLength(&pCoordLine);
      int partitions=(int)(length/sizeofElement);
      if(partitions==0)
  	partitions=0;
      else{
  	if((sizeofElement-length/(1.0*partitions+1))<(length/(1.0*partitions)-sizeofElement))
  	  partitions+=1;
      }      
      if(length<minLength && partitions!=0){
	minLength=length;
	refEdg=edgNum;
	partitionRef=partitions;
      }
    }
  }
  std::vector<double> hValLineRef;
  hValLineRef.reserve(m_mbEdges[refEdg].size());
  for(size_t k=0;k<m_mbEdges[refEdg].size();k++){
    double alpha=0.0;
    double beta=0.0;
    int isPointInTriBool=isPointInTri(m_mbEdgesTri[refEdg][k], m_mbEdges[refEdg][k], &alpha, &beta);
    if(!isPointInTriBool){
      std::cout << "pb m_mbEdgesTri" << std::endl;
      std::cout << "tri: " << m_mbEdgesTri[refEdg][k] << std::endl;
      exit(0);
    }
    uint32_t *nodesTri=m_Edges->edg2mesh->triangles.node + 3*m_mbEdgesTri[refEdg][k];
    // double hNode=hVal[k];
    double hNode=(1-alpha-beta)*hVal[nodesTri[0]] + alpha*hVal[nodesTri[1]] + beta*hVal[nodesTri[2]];
    hValLineRef.push_back(hNode);
  }
  std::vector<std::array<double,3>> pCoordLineRef=m_mbEdges[refEdg];
  double lengthParamRef=computeDiscreteLineLengthModified(&pCoordLineRef, hValLineRef);
  double sizeOfElementParam=lengthParamRef/(double)(partitionRef);
  //Get appropriate number of partition per sheet
  int *partitionPerSheet;
  HXT_CHECK(hxtMalloc(&partitionPerSheet, (m_Sheets.size())*sizeof(int)));
  double length=-1.;
  int  minPartition;
  uint64_t edgNum, currentEdg;
  std::vector<std::array<double,3>> pCoordLine;
  std::vector<uint64_t> sheetEdges;
  //  getting partition per sheet
  for(uint64_t i=0; i<m_Sheets.size(); i++){
    sheetEdges=m_Sheets[i];
    int *partitions;
    HXT_CHECK(hxtMalloc(&partitions, (sheetEdges.size())*sizeof(int)));
    for(uint64_t j=0; j<m_Sheets[i].size(); j++){
      edgNum=sheetEdges[j];
      pCoordLine=m_mbEdges[edgNum];
      std::vector<double> hValLine;
      hValLine.reserve(m_mbEdges[edgNum].size());
      for(size_t k=0;k<m_mbEdges[edgNum].size();k++){
	double alpha=0.0;
	double beta=0.0;
	int isPointInTriBool=isPointInTri(m_mbEdgesTri[edgNum][k], m_mbEdges[edgNum][k], &alpha, &beta);
	if(!isPointInTriBool){
	  std::cout << "pb m_mbEdgesTri" << std::endl;
	  std::cout << "tri: " << m_mbEdgesTri[edgNum][k] << std::endl;
	  exit(0);
	}
	uint32_t *nodesTri=m_Edges->edg2mesh->triangles.node + 3*m_mbEdgesTri[edgNum][k];
	// double hNode=hVal[k];
	double hNode=(1-alpha-beta)*hVal[nodesTri[0]] + alpha*hVal[nodesTri[1]] + beta*hVal[nodesTri[2]];
	hValLine.push_back(hNode);
      }
      length=computeDiscreteLineLengthModified(&pCoordLine, hVal);
      // length=computeDiscreteLineLength(&pCoordLine);
      //check min size
      partitions[j]=(int)(length/sizeOfElementParam);
      if(partitions[j]==0)
  	partitions[j]+=1;
      else{
  	if((sizeOfElementParam-length/(1.0*partitions[j]+1))<(length/(1.0*partitions[j])-sizeOfElementParam))
  	  partitions[j]+=1;
      }
    }
    minPartition=partitions[0];
    for(uint64_t k=1; k<m_Sheets[i].size(); k++){
      if(minPartition>partitions[k])
  	minPartition=partitions[k];
    }
    partitionPerSheet[i]=minPartition;
    HXT_CHECK(hxtFree(&partitions));
  }
   
  //get and store partition per edge
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    currentEdg=i;
    uint64_t sheetNumber=0;
    for(uint64_t j=0; j<m_Sheets.size(); j++){
      sheetEdges=m_Sheets[j];
      for(uint64_t k=0; k<sheetEdges.size(); k++){
	if(sheetEdges[k]==currentEdg){
	  sheetNumber=j;
	}
      }
    }
    m_partitionPerEdge.push_back(partitionPerSheet[sheetNumber]);
  }

   
  HXT_CHECK(hxtFree(&partitionPerSheet));    
  return 1;
}

void MultiBlock::getExtrVertIDmbEdg(uint64_t extrID[2],int edgID){
  for(uint64_t i=0;i<m_extraordVertices.size();i++){
    if(normDiffVect(&((m_mbEdges[edgID])[0]), &(m_extraordVertices[i]))<=1e-10)
      extrID[0]=i;
    if(normDiffVect(&((m_mbEdges[edgID])[(m_mbEdges[edgID]).size()-1]), &(m_extraordVertices[i]))<=1e-10)
      extrID[1]=i;
  }
  return;
}

// HXTStatus MultiBlock::discretizeEdges(std::vector<double> hVal){
//   std::vector<uint64_t> a;
//   m_discrMbEdges.resize(m_mbEdges.size(),a);
//   for(uint64_t i=0;i<m_mbEdges.size();i++){
//     std::array<double,3> init={{10.0,10.0,10.0}};
//     std::vector<std::array<double,3>> coordDiscrEdg(m_partitionPerEdge[i]+1,init);
//     std::vector<double> hValLine;
//     hValLine.reserve(m_mbEdges[i].size());
//     for(size_t k=0;k<m_mbEdges[i].size();k++){
//       double alpha=0.0;
//       double beta=0.0;
//       int isPointInTriBool=isPointInTri(m_mbEdgesTri[i][k], m_mbEdges[i][k], &alpha, &beta);
//       if(!isPointInTriBool){
// 	std::cout << "pb m_mbEdgesTri" << std::endl;
// 	std::cout << "tri: " << m_mbEdgesTri[i][k] << std::endl;
// 	exit(0);
//       }
//       uint32_t *nodesTri=m_Edges->edg2mesh->triangles.node + 3*m_mbEdgesTri[i][k];
//       // double hNode=hVal[k];
//       double hNode=(1-alpha-beta)*hVal[nodesTri[0]] + alpha*hVal[nodesTri[1]] + beta*hVal[nodesTri[2]];
//       hValLine.push_back(hNode);
//     }
//     lineDiscretization(&(m_mbEdges[i]), hVal, m_partitionPerEdge[i],&coordDiscrEdg);
//     // lineDiscretizationUniform(&(m_mbEdges[i]), m_partitionPerEdge[i],&coordDiscrEdg);
//     (m_discrMbEdges[i]).reserve(m_partitionPerEdge[i]+1);
//     uint64_t extrID[2];
//     getExtrVertIDmbEdg(extrID, i);
//     (m_discrMbEdges[i]).push_back(extrID[0]);
//     for(uint64_t k=1;k<coordDiscrEdg.size()-1;k++){
//       m_coordVerticesDiscretization.push_back(coordDiscrEdg[k]);
//       (m_discrMbEdges[i]).push_back(m_coordVerticesDiscretization.size()-1);
//     }
//     (m_discrMbEdges[i]).push_back(extrID[1]);
//   }
//   return HXT_STATUS_OK;
// }

HXTStatus MultiBlock::discretizeEdges(std::vector<double> hVal){
  std::vector<uint64_t> a;
  m_discrMbEdges.resize(m_mbEdges.size(),a);
  for(uint64_t i=0;i<m_mbEdges.size();i++){
    std::array<double,3> init={{10.0,10.0,10.0}};
    std::vector<std::array<double,3>> coordDiscrEdgParam(m_partitionPerEdge[i]+1,init);
    std::vector<double> hValLine;
    hValLine.reserve(m_mbEdges[i].size());
    for(size_t k=0;k<m_mbEdges[i].size();k++){
      double alpha=0.0;
      double beta=0.0;
      int isPointInTriBool=isPointInTri(m_mbEdgesTri[i][k], m_mbEdges[i][k], &alpha, &beta);
      if(!isPointInTriBool){
	std::cout << "pb m_mbEdgesTri" << std::endl;
	std::cout << "tri: " << m_mbEdgesTri[i][k] << std::endl;
	exit(0);
      }
      uint32_t *nodesTri=m_Edges->edg2mesh->triangles.node + 3*m_mbEdgesTri[i][k];
      // double hNode=hVal[k];
      double hNode=(1-alpha-beta)*hVal[nodesTri[0]] + alpha*hVal[nodesTri[1]] + beta*hVal[nodesTri[2]];
      hValLine.push_back(hNode);
    }
    std::vector<std::array<double,3>> paramLine;
    paramLine.reserve(m_mbEdges[i].size());
    double currentLength=0.0;
    for(size_t k=0;k<m_mbEdges[i].size()-1;k++){
      std::array<double,3> currentParamPoint={{currentLength,0.,0.}};
      paramLine.push_back(currentParamPoint);
      std::array<double,3> *coordP1 = &(m_mbEdges[i][k]);
      std::array<double,3> *coordP2 = &(m_mbEdges[i][k+1]);
      currentLength+=normDiffVect(coordP2,coordP1)*(hValLine[k]+hValLine[k+1])/2.;
    }
    std::array<double,3> lastParamPoint={{currentLength,0.,0.}};
    paramLine.push_back(lastParamPoint);
    lineDiscretizationUniform(&(paramLine), m_partitionPerEdge[i],&coordDiscrEdgParam);
    (m_discrMbEdges[i]).reserve(m_partitionPerEdge[i]+1);
    uint64_t extrID[2];
    getExtrVertIDmbEdg(extrID, i);
    (m_discrMbEdges[i]).push_back(extrID[0]);
    for(uint64_t k=1;k<coordDiscrEdgParam.size()-1;k++){
      size_t indLoc=0;
      for(size_t l=0;l<m_mbEdges[i].size();l++){
	if(paramLine[l][0]>coordDiscrEdgParam[k][0])
	  break;
	indLoc=l;
      }
      std::array<double,3> coordPhysical={{0.,0.,0.}};
      double factLocLine=0.0;
      factLocLine=(coordDiscrEdgParam[k][0]-paramLine[indLoc][0])/(paramLine[indLoc+1][0]-paramLine[indLoc][0]);
      for(size_t l=0;l<3;l++){
	coordPhysical[l]=m_mbEdges[i][indLoc][l]+factLocLine*(m_mbEdges[i][indLoc+1][l]-m_mbEdges[i][indLoc][l]);
      }
      m_coordVerticesDiscretization.push_back(coordPhysical);
      (m_discrMbEdges[i]).push_back(m_coordVerticesDiscretization.size()-1);
    }
    (m_discrMbEdges[i]).push_back(extrID[1]);
  }
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::discretizeQuads(){
  FILE *f = fopen("quadMesh.pos","w");  
  fprintf(f,"View \"Transfinite quads\"{\n");
  
  for(uint64_t i=0;i<m_mbQuads.size();i++){
    if(m_mbQuads[i].size()==4){
      // std::cout << "discretize quad " << i << std::endl;
      bool hasParametrization=false;
      if(m_mbQuadParametrization.size()!=0)
	hasParametrization=true;
      std::vector<int> mbNodesID = m_mbQuads[i];
      std::vector<uint64_t> mbEdgesID =  m_mbBlock2Edg[i];
      uint64_t extrID[2];
      getExtrVertIDmbEdg(extrID, mbEdgesID[0]);
      std::vector<uint64_t> pointsEdg1 = m_discrMbEdges[mbEdgesID[0]];
      if((int)extrID[0]!=mbNodesID[0])
	std::reverse(std::begin(pointsEdg1),std::end(pointsEdg1));
      std::vector<uint64_t> pointsEdg2 = m_discrMbEdges[mbEdgesID[1]];
      getExtrVertIDmbEdg(extrID, mbEdgesID[1]);
      if((int)extrID[0]!=mbNodesID[1])
	std::reverse(std::begin(pointsEdg2),std::end(pointsEdg2));
      std::vector<uint64_t> pointsEdg3 = m_discrMbEdges[mbEdgesID[2]];
      getExtrVertIDmbEdg(extrID, mbEdgesID[2]);
      if((int)extrID[0]!=mbNodesID[3])
	std::reverse(std::begin(pointsEdg3),std::end(pointsEdg3));
      getExtrVertIDmbEdg(extrID, mbEdgesID[3]);
      std::vector<uint64_t> pointsEdg4 = m_discrMbEdges[mbEdgesID[3]];
      getExtrVertIDmbEdg(extrID, mbEdgesID[3]);
      if((int)extrID[0]!=mbNodesID[0])
	std::reverse(std::begin(pointsEdg4),std::end(pointsEdg4));
      uint64_t nPointsEdg1 = pointsEdg1.size();
      uint64_t nPointsEdg2 = pointsEdg2.size();
      std::vector<uint64_t> transfinitePoints(nPointsEdg1*nPointsEdg2,1);
      for(uint64_t j=0; j<nPointsEdg2; j++){
	transfinitePoints[j]=pointsEdg4[j];
	transfinitePoints[(nPointsEdg1-1)*nPointsEdg2+j]=pointsEdg2[j];
      }
      for(uint64_t k=1; k<nPointsEdg1-1; k++){
	transfinitePoints[k*nPointsEdg2+0]=pointsEdg1[k];
	transfinitePoints[k*nPointsEdg2+nPointsEdg2-1]=pointsEdg3[k];
      }
      std::array<double,3> coordPointEdg20={{m_coordVerticesDiscretization[pointsEdg2[0]][0],m_coordVerticesDiscretization[pointsEdg2[0]][1],m_coordVerticesDiscretization[pointsEdg2[0]][2]}};
      std::array<double,3> oldCoordPointEdg20=coordPointEdg20;
      if(hasParametrization){
	coordPointEdg20=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg20);
	// //test phys->param then param-> phys
	// coordPointEdg20=m_mbQuadParametrization[i].getPhysCoordFromParamCoord(coordPointEdg20);
	// double normDiff=sqrt((coordPointEdg20[0]-oldCoordPointEdg20[0])*(coordPointEdg20[0]-oldCoordPointEdg20[0]) + (coordPointEdg20[1]-oldCoordPointEdg20[1])*(coordPointEdg20[1]-oldCoordPointEdg20[1]) + (coordPointEdg20[2]-oldCoordPointEdg20[2])*(coordPointEdg20[2]-oldCoordPointEdg20[2]));
	// if(normDiff>1e-10){
	// 	std::cout << "pb back and forth phys param. Normdiff=" << normDiff << std::endl;
	// 	  exit(0);
	// }
	// coordPointEdg20=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg20);
      }
      std::array<double,3> coordPointEdg2End={{m_coordVerticesDiscretization[pointsEdg2[pointsEdg2.size()-1]][0],m_coordVerticesDiscretization[pointsEdg2[pointsEdg2.size()-1]][1],m_coordVerticesDiscretization[pointsEdg2[pointsEdg2.size()-1]][2]}};
      if(hasParametrization)
	coordPointEdg2End=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg2End);
      std::array<double,3> coordPointEdg40={{m_coordVerticesDiscretization[pointsEdg4[0]][0],m_coordVerticesDiscretization[pointsEdg4[0]][1],m_coordVerticesDiscretization[pointsEdg4[0]][2]}};
      if(hasParametrization)
	coordPointEdg40=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg40);
      std::array<double,3> coordPointEdg4End={{m_coordVerticesDiscretization[pointsEdg4[pointsEdg4.size()-1]][0],m_coordVerticesDiscretization[pointsEdg4[pointsEdg4.size()-1]][1],m_coordVerticesDiscretization[pointsEdg4[pointsEdg4.size()-1]][2]}};
      if(hasParametrization)
	coordPointEdg4End=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg4End);
      for(uint64_t k=1; k<nPointsEdg1-1; k++){
	std::array<double,3> coordPointEdg1k={{m_coordVerticesDiscretization[pointsEdg1[k]][0],m_coordVerticesDiscretization[pointsEdg1[k]][1],m_coordVerticesDiscretization[pointsEdg1[k]][2]}};
	if(hasParametrization)
	  coordPointEdg1k=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg1k);
	std::array<double,3> coordPointEdg3k={{m_coordVerticesDiscretization[pointsEdg3[k]][0],m_coordVerticesDiscretization[pointsEdg3[k]][1],m_coordVerticesDiscretization[pointsEdg3[k]][2]}};
	if(hasParametrization)
	  coordPointEdg3k=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg3k);
	for(uint64_t j=1; j<nPointsEdg2-1; j++){
	  double u=(1.0*k)/(1.0*nPointsEdg1-1.0);
	  double v=(1.0*j)/(1.0*nPointsEdg2-1.0);
	  std::array<double,3> newTpoint={{0.0,0.0,0.0}};
	  std::array<double,3> coordPointEdg2j={{m_coordVerticesDiscretization[pointsEdg2[j]][0],m_coordVerticesDiscretization[pointsEdg2[j]][1],m_coordVerticesDiscretization[pointsEdg2[j]][2]}};
	  if(hasParametrization)
	    coordPointEdg2j=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg2j);
	  std::array<double,3> coordPointEdg4j={{m_coordVerticesDiscretization[pointsEdg4[j]][0],m_coordVerticesDiscretization[pointsEdg4[j]][1],m_coordVerticesDiscretization[pointsEdg4[j]][2]}};
	  if(hasParametrization)
	    coordPointEdg4j=m_mbQuadParametrization[i].getParamCoordFromPhysCoord(coordPointEdg4j);
	  for(int t=0; t<3; t++)
	    newTpoint[t] = (1. - u) * coordPointEdg4j[t] + u * coordPointEdg2j[t] + (1. - v) * coordPointEdg1k[t] + v *coordPointEdg3k[t] -((1. - u) * (1. - v) * coordPointEdg40[t] + u * (1. - v) * coordPointEdg20[t] + u * v * coordPointEdg2End[t] + (1. - u) * v * coordPointEdg4End[t]);
	  if(hasParametrization)
	    newTpoint=m_mbQuadParametrization[i].getPhysCoordFromParamCoord(newTpoint);
	  m_coordVerticesDiscretization.push_back(newTpoint);
	  transfinitePoints[k*nPointsEdg2+j]=m_coordVerticesDiscretization.size()-1;
	  fprintf(f,"SP(%g,%g,%g){%i};\n", newTpoint[0], newTpoint[1], newTpoint[2], 1);
	}
      }
      for(uint64_t k=1; k<nPointsEdg1; k++)
	for(uint64_t j=1; j<nPointsEdg2; j++){
	  std::vector<uint64_t> nodesQuadInd;
	  nodesQuadInd.resize(4,1);
	  nodesQuadInd[0]= transfinitePoints[(k-1)*nPointsEdg2+(j-1)];
	  nodesQuadInd[1]= transfinitePoints[(k)*nPointsEdg2+(j-1)];
	  nodesQuadInd[2]= transfinitePoints[(k)*nPointsEdg2+(j)];
	  nodesQuadInd[3]= transfinitePoints[(k-1)*nPointsEdg2+(j)];
	  m_discrQuads.push_back(nodesQuadInd);
	}
    }
  }
  
  fprintf(f,"};");
  fclose(f);
  
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::createQuadMesh(){
  HXT_CHECK(hxtMeshCreate(&(m_quadMesh)));
  // vertices
  m_quadMesh->vertices.num = m_coordVerticesDiscretization.size();
  HXT_CHECK(hxtAlignedMalloc(&(m_quadMesh->vertices.coord),4*(m_quadMesh->vertices.num)*sizeof(double)));
  for(uint64_t i=0; i<m_quadMesh->vertices.num; i++){
    for(int t=0; t<3; t++)
      m_quadMesh->vertices.coord[4*i+t] = (m_coordVerticesDiscretization[i])[t];
    m_quadMesh->vertices.coord[4*i+3] = 0.0;
  }
  // quads
  m_quadMesh->quads.num = m_discrQuads.size();
  HXT_CHECK(hxtAlignedMalloc(&(m_quadMesh->quads.node),4*(m_quadMesh->quads.num)*sizeof(uint64_t)));
  for(uint64_t i=0; i<m_quadMesh->quads.num; i++)
    for(int t=0; t<4; t++)
      m_quadMesh->quads.node[4*i+t] = (m_discrQuads[i])[t];
  hxtMeshWriteGmsh(m_quadMesh, "qmbFinal.msh");
  
  //-------------getting mesh quality

  std::vector<double> quadsQuality;
  double averageQuality;
  double worstQuality;
  double procentageHighQualityElements;
  getMeshQuality(&quadsQuality, &averageQuality, &worstQuality, &procentageHighQualityElements);
  std::cout<<"Worst quality: "<<worstQuality<<std::endl;
  std::cout<<"Average quality: "<<averageQuality<<std::endl;
  std::cout<<"Procentage elements with quality greater than 0.9: "<<procentageHighQualityElements<<std::endl;
  hxtWriteQuadQualityScalarPos(quadsQuality, "qmbFinalQuality.pos");
  
  return HXT_STATUS_OK;
}

HXTMesh* MultiBlock::getQuadMesh(){
  return m_quadMesh;
}

double MultiBlock::getSingleQuadQuality(int iQuad){
  HXTMesh *quadMesh=m_quadMesh;
  double *vert = quadMesh->vertices.coord;
  uint32_t* nodes = quadMesh->quads.node;
  double vQuad[4*3] = {vert[4*nodes[4*iQuad+0]+0],vert[4*nodes[4*iQuad+0]+1],vert[4*nodes[4*iQuad+0]+2],
		       vert[4*nodes[4*iQuad+1]+0],vert[4*nodes[4*iQuad+1]+1],vert[4*nodes[4*iQuad+1]+2],
		       vert[4*nodes[4*iQuad+2]+0],vert[4*nodes[4*iQuad+2]+1], vert[4*nodes[4*iQuad+2]+2],
		       vert[4*nodes[4*iQuad+3]+0],vert[4*nodes[4*iQuad+3]+1], vert[4*nodes[4*iQuad+3]+2]};
  double e1[3]={vQuad[3]-vQuad[0], vQuad[4]-vQuad[1], vQuad[5]-vQuad[2]};
  double e2[3]={vQuad[6]-vQuad[3], vQuad[7]-vQuad[4], vQuad[8]-vQuad[5]};
  double e3[3]={vQuad[9]-vQuad[6], vQuad[10]-vQuad[7],vQuad[11]-vQuad[8]};
  double e4[3]={vQuad[0]-vQuad[9], vQuad[1]-vQuad[10], vQuad[2]-vQuad[11]};
  double me1[3]={0,0,0}, me2[3]={0,0,0},  me3[3]={0,0,0},  me4[3]={0,0,0};
  for(int i=0; i<3; i++){
    me1[i]=-e1[i];
    me2[i]=-e2[i];
    me3[i]=-e3[i];
    me4[i]=-e4[i];
  }
  
  normalize(e1); normalize(e2); normalize(e3); normalize(e4); normalize(me1); normalize(me2); normalize(me3); normalize(me4);
  double n1[3]={0,0,0};
  myNormalizedCrossprod(e1, me4, n1);
  double n2[3]={0,0,0};
  myNormalizedCrossprod(e2, me1, n2);
  double n3[3]={0,0,0};
  myNormalizedCrossprod(e3, me2, n3);
  double n4[3]={0,0,0};
  myNormalizedCrossprod(e4, me3, n4);

  double d1[3]={0,0,0};
  myNormalizedCrossprod(n1, e1, d1);
  double d2[3]={0,0,0};
  myNormalizedCrossprod(n2, e2, d2);
  double d3[3]={0,0,0};
  myNormalizedCrossprod(n3, e3, d3);
  double d4[3]={0,0,0};
  myNormalizedCrossprod(n4, e4, d4);
 
  double alpha[4]={0,0,0,0};
  computeAlpha(e1, d1, me4, &alpha[0]);
  computeAlpha(e2, d2, me1, &alpha[1]);
  computeAlpha(e3, d3, me2, &alpha[2]);
  computeAlpha(e4, d4, me3, &alpha[3]);
 
   double estim=-1.0;
   double cp=0;
   for(int i=0; i<4; i++){
    cp=(fabs(M_PI/2.0-alpha[i]));
    if(estim<cp)
      estim=cp;
   }

  return estim;
}

int MultiBlock::getMeshQuality(std::vector<double> *quadsQuality, double *averageQuality, double *worstQuality, double *procentageHighQualityElements){
  HXTMesh *quadMesh=m_quadMesh;
  uint64_t nQuads=quadMesh->quads.num;
  for(uint64_t i=0; i<nQuads; i++){
    (*quadsQuality).push_back(0.0);
  }
  for(uint64_t i=0; i<nQuads; i++){
    double crit1=getSingleQuadQuality((int)i);
    double critFinal=-1.0;
    critFinal=1-(2.0/M_PI)*crit1;
    double max=critFinal;
    if(max<0){
      (*quadsQuality)[i]=0.0;
    }else{
      (*quadsQuality)[i]=critFinal;
    }
  }
  double eta_averg=0.0;
  double eta_worst=(*quadsQuality)[0];
  int num=0;
  for(uint64_t i=0; i<nQuads; i++){
    eta_averg+=(*quadsQuality)[i];
    if(eta_worst>(*quadsQuality)[i])
      eta_worst=(*quadsQuality)[i];
    if((*quadsQuality)[i]>=0.9)
      num++;
  }
  *averageQuality=((eta_averg)/(double)nQuads)*100.0;
  *worstQuality=(eta_worst)*100.0;
  *procentageHighQualityElements=(num/(double)nQuads)*100.0;
  std::cout<<"Num high quality elements: "<<num<<std::endl;
  std::cout<<"Num quads: "<<nQuads<<std::endl;
  
  return 1;
}

HXTStatus MultiBlock::hxtWriteQuadQualityScalarPos(std::vector<double> quadsQuality,const char *fileName){
  HXTMesh* mesh=m_quadMesh;
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Quads quality\"{\n");
  for(uint64_t i=0; i<mesh->quads.num; i++){
    fprintf(myfile,"SQ(");
    uint32_t vquad[4] = {mesh->quads.node[4*i+0],mesh->quads.node[4*i+1],mesh->quads.node[4*i+2],mesh->quads.node[4*i+3]};
    double Ue[4];
    for(uint32_t j=0; j<4; j++){
      fprintf(myfile,"%f,%f,%f",mesh->vertices.coord[4*vquad[j]+0],mesh->vertices.coord[4*vquad[j]+1],mesh->vertices.coord[4*vquad[j]+2]);
      if(j<3)
        fprintf(myfile,",");
      Ue[j] = quadsQuality[i];
    }
    fprintf(myfile,")");
    fprintf(myfile,"{");
    for(uint32_t j=0; j<4; j++){      
      fprintf(myfile,"%f",Ue[j]);
      if(j<3)
        fprintf(myfile,",");  
    }
    fprintf(myfile,"};\n");    
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

HXTStatus MultiBlock::mergeEdges(uint64_t edgID1, uint64_t edgID2, uint64_t connectingVertInd, std::vector<std::array<double,3>> *newEdgPoints, std::vector<uint64_t> *newEdgTri){
  
  double norm=-1.0;
  std::vector<std::array<double,3>> pointsEdg1 =  m_mbEdges[edgID1];
  std::vector<uint64_t> triEdg1 =  m_mbEdgesTri[edgID1];
  if(isPointDuplicateVec(&pointsEdg1[0], &m_extraordVertices[connectingVertInd], &norm)){
    std::reverse(std::begin(pointsEdg1),std::end(pointsEdg1));
    std::reverse(std::begin(triEdg1),std::end(triEdg1));
  }
  std::vector<std::array<double,3>> pointsEdg2 =  m_mbEdges[edgID2];
  std::vector<uint64_t> triEdg2 =  m_mbEdgesTri[edgID2];
  if(isPointDuplicateVec(&pointsEdg2[pointsEdg2.size()-1], &m_extraordVertices[connectingVertInd], &norm)){
    std::reverse(std::begin(pointsEdg2),std::end(pointsEdg2));
    std::reverse(std::begin(triEdg2),std::end(triEdg2));
  }
  std::cout << "connection node indice: " << connectingVertInd << std::endl;
  uint64_t idE10=0;
  uint64_t idE11=0;
  uint64_t idE20=0;
  uint64_t idE21=0;
  for(uint64_t i=0;i<m_extraordVertices.size();i++){
    if(normDiffVect(&(pointsEdg1[0]), &(m_extraordVertices[i]))<=1e-10)
      idE10=i;
    if(normDiffVect(&(pointsEdg1[pointsEdg1.size()-1]), &(m_extraordVertices[i]))<=1e-10)
      idE11=i;
    if(normDiffVect(&(pointsEdg2[0]), &(m_extraordVertices[i]))<=1e-10)
      idE20=i;
    if(normDiffVect(&(pointsEdg2[pointsEdg2.size()-1]), &(m_extraordVertices[i]))<=1e-10)
      idE21=i;
  }
  std::cout << "indice edg 1: " << idE10 << " / " << idE11 << std::endl;
  std::cout << "indice edg 2: " << idE20 << " / " << idE21 << std::endl;
  for(uint64_t i=0; i<pointsEdg1.size();i++)
    newEdgPoints->push_back(pointsEdg1[i]);
  for(uint64_t i=1; i<pointsEdg2.size();i++)
    newEdgPoints->push_back(pointsEdg2[i]);
  for(uint64_t i=0; i<triEdg1.size();i++)
    newEdgTri->push_back(triEdg1[i]);
  for(uint64_t i=1; i<triEdg2.size();i++)
    newEdgTri->push_back(triEdg2[i]);

  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::mergeBlocks(uint64_t blockID1, uint64_t blockID2, uint64_t edgToDelete, int currentNode, std::vector<uint64_t> *delBlocks, std::vector<uint64_t> *delEdges){
  //1. taking into the account that blocks can have more than 5 vertices
  //2. put blockID1 on the left and lockID2 on the right
  // if v1 = locEdgBlock1 + 1 then blockID1 is on the left
  // if not, it on the right and we swap values of blockID1 and blockID2, vertices and edges
  int locV1=-1;
  int locV2=-1;
  int locEdgV1=-1;
  int locEdgV2=-1;
  for(uint64_t i=0; i<m_mbBlock2Edg[blockID1].size(); i++){
    if(m_mbBlock2Edg[blockID1][i] == edgToDelete)
      locEdgV1=i;
  }
  for(uint64_t i=0; i<m_mbBlock2Edg[blockID2].size(); i++){
    if(m_mbBlock2Edg[blockID2][i] == edgToDelete)
      locEdgV2=i;
  }
  for(uint64_t i=0; i<m_mbQuads[blockID1].size(); i++){
    if(m_mbQuads[blockID1][i] == currentNode)
      locV1=i;
  }
  for(uint64_t i=0; i<m_mbQuads[blockID2].size(); i++){
    if(m_mbQuads[blockID2][i] == currentNode)
      locV2=i;
  }
  if(locV1 != locEdgV1+1){
    uint64_t currB=blockID1;
    blockID1=blockID2;
    blockID2=currB;
    int currEdg=locEdgV1;
    locEdgV1=locEdgV2;
    locEdgV2=currEdg;
    int currV=locV1;
    locV1=locV2; 
    locV2=currV;
  }
  uint64_t nVert1=m_mbQuads[blockID1].size();
  uint64_t nVert2=m_mbQuads[blockID2].size();
  std::vector<int> newBlockVertices;
  for(uint64_t i=0; i<nVert1-2; i++){
    newBlockVertices.push_back(m_mbQuads[blockID1][(locV1+1+i)%nVert1]);
  }
  for(uint64_t i=0; i<nVert2-2; i++){
    newBlockVertices.push_back(m_mbQuads[blockID2][(locV2+2+i)%nVert2]);
  }
  m_mbQuads.push_back(newBlockVertices);
  std::cout<<"Vertices: "<<std::endl; 
  for(uint64_t i=0; i<newBlockVertices.size(); i++)
    std::cout<<"vertices: "<<newBlockVertices[i]<<", ";
  std::cout<<std::endl;
  
  std::vector<std::array<double,3>> edg0;
  std::vector<uint64_t> edgTri0;
  //merge edg
  mergeEdges(m_mbBlock2Edg[blockID1][(locEdgV1+nVert1-1)%nVert1], m_mbBlock2Edg[blockID2][(locEdgV2+1)%nVert2], m_mbQuads[blockID1][(locV1+nVert1-1)%nVert1], &edg0, &edgTri0);
  m_mbEdges.push_back(edg0);
  m_mbEdgesTri.push_back(edgTri0);

  //delete data
  delBlocks->push_back(blockID1);
  delBlocks->push_back(blockID2);
  delEdges->push_back(edgToDelete);
  delEdges->push_back(m_mbBlock2Edg[blockID1][(locEdgV1+nVert1-1)%nVert1]);
  delEdges->push_back(m_mbBlock2Edg[blockID2][(locEdgV2+1)%nVert2]);
  
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::getVert2Block(){
  size_t nExtrVertices=m_extraordVertices.size();
  std::vector<uint64_t> init;
  m_vert2Block.clear();
  m_vert2Block.resize(nExtrVertices,init);
  for(uint64_t t=0; t<m_mbQuads.size(); t++){
    for(uint64_t k=0; k<m_mbQuads[t].size(); k++){
      m_vert2Block[m_mbQuads[t][k]].push_back(t);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::modifyTBlockNgbrs_TjuncOnRight(int tBlockID, int locIndTjuncVert, int locTjunEdgInd, std::vector<uint64_t> *vecBlocksDelete, std::vector<uint64_t> *vecEdgesDelete){

  //1. modify block M (left neighbour of t-junc block K)
  uint64_t blockK=tBlockID;
  int k = locIndTjuncVert;
  int edgK = locTjunEdgInd;
  size_t nVertK=m_mbQuads[blockK].size();
  uint64_t currentEdg = m_mbBlock2Edg[blockK][(edgK+2)%nVertK];
  uint64_t blockM =(uint64_t)-1;
  if(m_mbEdg2Block[currentEdg][0] == blockK){
    blockM= m_mbEdg2Block[currentEdg][1];
  }else{
    blockM= m_mbEdg2Block[currentEdg][0];
  }
  size_t nVertM=m_mbQuads[blockM].size();
  
  int m=-1; //m=k+1
  for(uint64_t i=0; i<m_mbQuads[blockM].size(); i++){
    if(m_mbQuads[blockK][(k+1)%nVertK] == m_mbQuads[blockM][i])
      m=i;
  }
  //update block M
  std::vector<int> newBlockVerticesM;
  for(uint64_t i=0; i<nVertM-1; i++){//not picking last node
    newBlockVerticesM.push_back(m_mbQuads[blockM][(m+i)%nVertM]);
  }
  newBlockVerticesM.push_back(m_mbQuads[blockK][(k+3)%nVertK]); //last point
  m_mbQuads.push_back(newBlockVerticesM);
  uint64_t edgM=(uint64_t)-1;
  for(uint64_t s=0; s<m_mbBlock2Edg[blockM].size(); s++){
    if(m_mbBlock2Edg[blockM][s] == currentEdg)
      edgM=s;
  }
  std::cout<<"EdgM= "<<edgM<<std::endl;
  std::vector<uint64_t> newTri1M;
  std::vector<std::array<double,3>> newEdg1M;
  std::cout<<"Merge edg1M"<<std::endl;
  mergeEdges(m_mbBlock2Edg[blockM][(edgM+nVertM-1)%nVertM], m_mbBlock2Edg[blockK][(edgK+3)%nVertK], m_mbQuads[blockK][(k+2)%nVertK], &newEdg1M, &newTri1M);
  m_mbEdges.push_back(newEdg1M);  m_mbEdgesTri.push_back(newTri1M);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockM][(edgM+nVertM-1)%nVertM]) ; vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+3)%nVertK]);
  std::vector<uint64_t> newTri2M;
  std::vector<std::array<double,3>> newEdg2M;
  std::cout<<"Merge via param edg2M"<<std::endl;
  m_mbQuadParametrization[blockK].getStraigthLine(m_extraordVertices[m_mbQuads[blockK][(k+3)%nVertK]], m_extraordVertices[m_mbQuads[blockK][(k+1)%nVertK]], newEdg2M, newTri2M, 10000);
  m_mbEdges.push_back(newEdg2M);  m_mbEdgesTri.push_back(newTri2M);  


  //2. block  L (right neighbour of t-junc block)
  uint64_t blockL =(uint64_t)-1;
  if(m_mbEdg2Block[m_mbBlock2Edg[blockK][edgK]][0] == blockK){
    blockL= m_mbEdg2Block[m_mbBlock2Edg[blockK][edgK]][1];
  }else{
    blockL= m_mbEdg2Block[m_mbBlock2Edg[blockK][edgK]][0];
  }
  size_t nVertL=m_mbQuads[blockL].size();
  std::cout<<"Blok L= "<<blockL<<"num vert: "<<m_mbQuads[blockL].size()<<std::endl;
  int l=-1;
  for(uint64_t i=0; i<m_mbQuads[blockL].size(); i++){
    if(m_mbQuads[blockL][i] == m_mbQuads[blockK][k])
      l=i;
  }
  std::cout<<"l= "<<l<<std::endl;
  //update block L
  std::vector<int> newBlockVerticesL;
  for(size_t i=0; i<nVertL-1; i++){//not picking last node
    newBlockVerticesL.push_back(m_mbQuads[blockL][(l+1+i)%nVertL]);
  }
  newBlockVerticesL.push_back(m_mbQuads[blockK][(k+1)%nVertK]);//last node
  m_mbQuads.push_back(newBlockVerticesL);
  uint64_t edgL=(uint64_t)-1;
  for(uint64_t s=0; s<m_mbBlock2Edg[blockL].size(); s++){
    if(m_mbBlock2Edg[blockL][s] == m_mbBlock2Edg[blockK][locTjunEdgInd])
      edgL=s;
  }
  std::cout<<"EdgL= "<<edgL<<std::endl;
  std::vector<uint64_t> newTri1L;
  std::vector<std::array<double,3>> newEdg1L;
  std::cout<<"Merge edg1L"<<std::endl;
  mergeEdges(m_mbBlock2Edg[blockL][(edgL+nVertL-1)%nVertL], m_mbBlock2Edg[blockK][(edgK+1)%nVertK], m_mbQuads[blockK][k], &newEdg1L, &newTri1L);
  m_mbEdges.push_back(newEdg1L);  m_mbEdgesTri.push_back(newTri1L);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockL][(edgL+nVertL-1)%nVertL]); vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+1)%nVertK]);
  
  //3. block T with (at least) 5 vertices - the other block containing T junction vertex
  uint64_t blockT =(uint64_t)-1;
  for(uint64_t i=0; i<m_vert2Block[m_mbQuads[blockK][k]].size();i++){
    if((m_vert2Block[m_mbQuads[blockK][k]][i] != blockK) && (m_vert2Block[m_mbQuads[blockK][k]][i] != blockL))
      blockT=m_vert2Block[m_mbQuads[blockK][k]][i];
  }
  size_t nVertT=m_mbQuads[blockT].size();
  std::cout<<"Block T= "<<blockT<<std::endl;
  int t=-1;
  for(uint64_t i=0; i<m_mbQuads[blockT].size(); i++){
    if(m_mbQuads[blockT][i] == m_mbQuads[blockK][k])
      t=i;
  }
  std::cout<<"t= "<<t<<std::endl;
  //update block T
  std::vector<int> newBlockVerticesT;
  for(uint64_t i=0; i<nVertT-1; i++){//not picking last node
    newBlockVerticesT.push_back(m_mbQuads[blockT][(t+1+i)%nVertT]);
  }
  m_mbQuads.push_back(newBlockVerticesT);
 
  //store things for deleting
  vecBlocksDelete->push_back(blockK);
  vecBlocksDelete->push_back(blockM);
  vecBlocksDelete->push_back(blockL);
  vecBlocksDelete->push_back(blockT);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][edgK]);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+2)%nVertK]);

  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::modifyTBlockNgbrs_TjuncOnLeft(int tBlockID, int locIndTjuncVert, int locTjunEdgInd, std::vector<uint64_t> *vecBlocksDelete, std::vector<uint64_t> *vecEdgesDelete){

  //1. modify block M (block on the left of the t-junc blockK)
  uint64_t blockK=tBlockID;
  std::cout<<"block K: "<<blockK<<std::endl;
  int k = locIndTjuncVert;
  int edgK = locTjunEdgInd;
  std::cout<<"k= "<<k<<std::endl;
  std::cout<<"edgK= "<<edgK<<std::endl;
  size_t nVertK=m_mbQuads[blockK].size();
  std::cout<<"nVertK: "<<nVertK<<std::endl;
  uint64_t currentEdg = m_mbBlock2Edg[blockK][edgK];
  uint64_t blockM =(uint64_t)-1;
  if(m_mbEdg2Block[currentEdg][0] == blockK){
    blockM= m_mbEdg2Block[currentEdg][1];
  }else{
    blockM= m_mbEdg2Block[currentEdg][0];
  }
  std::cout<<"possible blocks: "<<m_mbEdg2Block[currentEdg][1]<<" and "<<m_mbEdg2Block[currentEdg][0]<<std::endl;
  std::cout<<"Edg number: "<<currentEdg<<" , nodes: "<<m_mbQuads[blockK][k]<<" and "<<m_mbQuads[blockK][(k+nVertK-1)%nVertK]<<std::endl;
  std::cout<<"block M: "<<blockM<<std::endl;
  // std::cout<<"oldVertices M: ";
  // for(uint64_t i=0; i<m_mbQuads[blockM].size(); i++)
  //   std::cout<<m_mbQuads[blockM][i]<<", ";
  // std::cout<<" "<<std::endl;
 
  size_t nVertM=m_mbQuads[blockM].size(); 
  std::cout<<"nVertM: "<<nVertM<<std::endl;
  int m=-1;
  int edgM=-1;
  for(uint64_t i=0; i<m_mbQuads[blockM].size(); i++){
    if(m_mbQuads[blockM][i] == m_mbQuads[blockK][k])
      m=i;
  }
  std::cout<<"m= "<<m<<std::endl;
  for(uint64_t i=0; i<m_mbBlock2Edg[blockM].size(); i++){
    if(m_mbBlock2Edg[blockM][i] == m_mbBlock2Edg[blockK][edgK])
      edgM=i;
  }
  std::cout<<"edgM= "<<edgM<<std::endl;
  std::vector<int> newBlockVerticesM;
  for(size_t i=0; i<nVertM-1; i++)
    newBlockVerticesM.push_back(m_mbQuads[blockM][(m+1+i)%nVertM]);
  newBlockVerticesM.push_back(m_mbQuads[blockK][(k+nVertK-1)%nVertK]);
  m_mbQuads.push_back(newBlockVerticesM);
  std::cout<<"newVertices M: ";
  for(uint64_t i=0; i<newBlockVerticesM.size(); i++)
    std::cout<<newBlockVerticesM[i]<<", ";
  std::cout<<" "<<std::endl;
  //edges and triangles
  std::vector<uint64_t> newTri1M;
  std::vector<std::array<double,3>> newEdg1M;
  std::cout<<"Merge edg1K"<<std::endl;
  mergeEdges(m_mbBlock2Edg[blockK][(edgK+nVertK-1)%nVertK], m_mbBlock2Edg[blockM][(edgM+1)%nVertM], m_mbQuads[blockK][k], &newEdg1M, &newTri1M);
  m_mbEdges.push_back(newEdg1M);  m_mbEdgesTri.push_back(newTri1M);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+nVertK-1)%nVertK]); vecEdgesDelete->push_back(m_mbBlock2Edg[blockM][(edgM+1)%nVertM]); 
  std::vector<uint64_t> newTri2M;
  std::vector<std::array<double,3>> newEdg2M;
  std::cout<<"Merge via param edg2M"<<std::endl;
  std::cout << "indice node 1: " << m_mbQuads[blockK][((k+1)%nVertK)] << " / local ind: " << (k+1)%nVertK << " expected value: " << m_mbQuads[blockK][0] << std::endl;
  std::cout << "indice node 2: " << m_mbQuads[blockK][(k+nVertK-1)%nVertK] << " / local ind: " << (k+nVertK-1)%nVertK << " expected value: " << m_mbQuads[blockK][2] << std::endl;
  std::cout<<"Vertices of block K: "<<std::endl;
  for(uint64_t i=0; i<m_mbQuads[blockK].size(); i++)
    std::cout<<m_mbQuads[blockK][i]<<", ";
  std::cout<<" "<<std::endl;
  // std::cout<<"block K: "<<blockK<<std::endl;
  // std::cout<<"blockK vertices: ";
  // for(uint64_t i=0; i<m_mbQuads[blockK].size(); i++)
  //   std::cout<<m_mbQuads[blockK][i]<<", ";
  // std::cout<<" "<<std::endl;
  m_mbQuadParametrization[blockK].getStraigthLine(m_extraordVertices[m_mbQuads[blockK][(k+1)%nVertK]], m_extraordVertices[m_mbQuads[blockK][(k+nVertK-1)%nVertK]], newEdg2M, newTri2M, 10000);
  m_mbEdges.push_back(newEdg2M);  m_mbEdgesTri.push_back(newTri2M); 

  
  //2. block  L (right neighbour of the t-junc blockK)
  uint64_t blockL =(uint64_t)-1;
  if(m_mbEdg2Block[m_mbBlock2Edg[blockK][(edgK+nVertK-2)%nVertK]][0] == blockK){
    blockL= m_mbEdg2Block[m_mbBlock2Edg[blockK][(edgK+nVertK-2)%nVertK]][1];
  }else{
    blockL= m_mbEdg2Block[m_mbBlock2Edg[blockK][(edgK+nVertK-2)%nVertK]][0];
  }
  size_t nVertL=m_mbQuads[blockL].size();
  std::cout<<"Blok L= "<<blockL<<"num vert: "<<m_mbQuads[blockL].size()<<std::endl;
  int l=-1;
  for(uint64_t i=0; i<m_mbQuads[blockL].size(); i++){
    if(m_mbQuads[blockL][i] == m_mbQuads[blockK][(k+nVertK-1)%nVertK])
      l=i;
  }
  std::cout<<"l= "<<l<<std::endl;
  //update block L
  std::vector<int> newBlockVerticesL;
  newBlockVerticesL.push_back(m_mbQuads[blockL][l]);
  newBlockVerticesL.push_back(m_mbQuads[blockK][(k+1)%nVertK]);
  for(size_t i=0; i<nVertL-2; i++){
    newBlockVerticesL.push_back(m_mbQuads[blockL][(l+2+i)%nVertL]);
  }
  m_mbQuads.push_back(newBlockVerticesL);
  std::cout<<"newVertices L: ";
  for(uint64_t i=0; i<newBlockVerticesL.size(); i++)
    std::cout<<newBlockVerticesL[i]<<", ";
  std::cout<<" "<<std::endl;
  uint64_t edgL=(uint64_t)-1;
  for(uint64_t s=0; s<m_mbBlock2Edg[blockL].size(); s++){
    if(m_mbBlock2Edg[blockL][s] == m_mbBlock2Edg[blockK][(edgK+nVertK-2)%nVertK])
      edgL=s;
  }
  std::cout<<"EdgL= "<<edgL<<std::endl;
  std::vector<uint64_t> newTri1L;
  std::vector<std::array<double,3>> newEdg1L;
  std::cout<<"Merge edg1L"<<std::endl;
  mergeEdges(m_mbBlock2Edg[blockK][(edgK+1)%nVertK], m_mbBlock2Edg[blockL][(edgL+1)%nVertL], m_mbQuads[blockL][(l+1)%nVertL], &newEdg1L, &newTri1L);
  m_mbEdges.push_back(newEdg1L);  m_mbEdgesTri.push_back(newTri1L);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+1)%nVertK]); vecEdgesDelete->push_back(m_mbBlock2Edg[blockL][(edgL+1)%nVertL]);


  //3. block T with (at least) 5 vertices - the other block containing T junction vertex
  uint64_t blockT =(uint64_t)-1;
  for(uint64_t i=0; i<m_vert2Block[m_mbQuads[blockK][k]].size();i++){
    if((m_vert2Block[m_mbQuads[blockK][k]][i] != blockK) && (m_vert2Block[m_mbQuads[blockK][k]][i] != blockM))
      blockT=m_vert2Block[m_mbQuads[blockK][k]][i];
  }
  size_t nVertT=m_mbQuads[blockT].size();
  std::cout<<"Block T= "<<blockT<<" ,num vertices: "<<nVertT<< std::endl;
  int t=-1;
  for(uint64_t i=0; i<m_mbQuads[blockT].size(); i++){
    if(m_mbQuads[blockT][i] == m_mbQuads[blockK][k])
      t=i;
  }
  std::cout<<"t= "<<t<<std::endl;
  //update block T
  std::vector<int> newBlockVerticesT;
  for(uint64_t i=0; i<nVertT-1; i++){//not picking last node
    newBlockVerticesT.push_back(m_mbQuads[blockT][(t+1+i)%nVertT]);
  }
  m_mbQuads.push_back(newBlockVerticesT);
  std::cout<<"newVertices T: ";
  for(uint64_t i=0; i<newBlockVerticesT.size(); i++)
    std::cout<<newBlockVerticesT[i]<<", ";
  std::cout<<" "<<std::endl;
 
  //store things for deleting
  vecBlocksDelete->push_back(blockK);
  vecBlocksDelete->push_back(blockM);
  vecBlocksDelete->push_back(blockL);
  vecBlocksDelete->push_back(blockT);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][edgK]);
  vecEdgesDelete->push_back(m_mbBlock2Edg[blockK][(edgK+nVertK-2)%nVertK]);

  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::recomputeMinEdgLength(){
  double min = std::numeric_limits<double>::max();
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    double length = computeDiscreteLineLength(&m_mbEdges[i]);
    if(min>length)
      min=length;
  }
  std::cout<<"Min edg length: "<<min<<std::endl;
  m_minEdgLength = min;
  
  return HXT_STATUS_OK;
}

HXTStatus MultiBlock::correctInvalidBlocks(){

  std::vector<std::vector<uint64_t>> allBlocks;
  std::vector<std::vector<uint64_t>> allEdges;
  std::vector<int> tJunctionPatchesIDs;
  std::vector<int> locTjunEdgInd;
  std::vector<int> locTjuncInd;
  getTJunctionsPatchesIDs(&tJunctionPatchesIDs, &locTjunEdgInd, &locTjuncInd);
  bool keepCorrecting=false;
  for(size_t k=0;k<tJunctionPatchesIDs.size();k++){
    if(m_mbQuads[tJunctionPatchesIDs[k]].size()==4)
      keepCorrecting=true;
  }
  // for(uint64_t i=0; i<tJunctionPatchesIDs.size(); i++){ //while number of Tjunction which have a blockK which is a quad !=0
  while(keepCorrecting){ //while number of Tjunction which have a blockK which is a quad !=0
    size_t i=0;
    for(size_t k=0;k<tJunctionPatchesIDs.size();k++){
      if(m_mbQuads[tJunctionPatchesIDs[k]].size()==4){
	i=k;
	break;
      }
    }
    //check if blockK is q quad. If it is, do the stuff, else not
    std::cout<<"-----> Solving T-junction: "<<i<<std::endl;
    std::cout<<"patch id: "<<tJunctionPatchesIDs[i]<<std::endl;
    std::cout<<"T junc node: "<<m_extraordVertTjunc[i]<<std::endl;
    //collect current edges and blocks to be merged
    int locInd=-1;
    uint64_t globEdgNum = m_mbBlock2Edg[tJunctionPatchesIDs[i]][locTjunEdgInd[i]]; //limit cycle sep edg  on which is T junc
    uint64_t currentEdg = m_mbBlock2Edg[tJunctionPatchesIDs[i]][(locTjunEdgInd[i]+2)%4];
    //Create a larger patch parametrization. Temporary fix for average in parametric space problem
    BlockParametrization blockParam(m_Edges->edg2mesh);
    std::vector<uint64_t> vectIdBlock;
    vectIdBlock.push_back(tJunctionPatchesIDs[i]);
    if(m_mbEdg2Block[globEdgNum][0]==tJunctionPatchesIDs[i])
      vectIdBlock.push_back(m_mbEdg2Block[globEdgNum][1]);
    else
      vectIdBlock.push_back(m_mbEdg2Block[globEdgNum][0]);
    if(m_mbEdg2Block[currentEdg][0]==tJunctionPatchesIDs[i])
      vectIdBlock.push_back(m_mbEdg2Block[currentEdg][1]);
    else
      vectIdBlock.push_back(m_mbEdg2Block[currentEdg][0]);
    parametrizeBlock(vectIdBlock, blockParam);
    m_mbQuadParametrization[tJunctionPatchesIDs[i]]=blockParam;
    std::string nameTest="dbgParam_" + std::to_string(tJunctionPatchesIDs[i]) + "_new.pos";
    blockParam.dbgPosParam(nameTest.c_str());
    //
    std::vector<int> currentNodes;
    std::vector<uint64_t> vecCurrentEdges; 
    std::vector<uint64_t> vecMergeBlockIDs;
    std::vector<uint64_t> blocksDel;
    std::vector<uint64_t> edgesDel;
    std::cout<<"start mod ngbrs"<<std::endl;
    //a check if T junc is on right or on left in the block K
    bool tJunc_onRight = false;
    if(locTjuncInd[i] ==  locTjunEdgInd[i]+1)
      tJunc_onRight = true;
    if(tJunc_onRight){
      std::cout<<"T junc on the right"<<std::endl;
      modifyTBlockNgbrs_TjuncOnRight(tJunctionPatchesIDs[i], locTjuncInd[i], locTjunEdgInd[i], &blocksDel, &edgesDel);
    }
    else{
      std::cout<<"T junc on the left"<<std::endl;
      modifyTBlockNgbrs_TjuncOnLeft(tJunctionPatchesIDs[i], locTjuncInd[i], locTjunEdgInd[i], &blocksDel, &edgesDel);
    }
      
    std::cout<<"end mod ngbrs"<<std::endl;
    allBlocks.push_back(blocksDel);
    allEdges.push_back(edgesDel);

    int currentNode=m_mbQuads[tJunctionPatchesIDs[i]][(locTjuncInd[i]+2)%4];
    currentNodes.push_back(currentNode);
    std::cout<<" curr Node start: "<<currentNode<<std::endl;
    int isBdry;
    isExtrVertOnBdry(currentNode, &isBdry);
    while(!isBdry){
      uint64_t lastBlock1 = (uint64_t)-1;
      uint64_t lastBlock2 = (uint64_t)-1;
      lastBlock1=m_mbEdg2Block[currentEdg][0];
      lastBlock2=m_mbEdg2Block[currentEdg][1];
      for(uint64_t k=0; k<m_vert2Block[currentNode].size(); k++){
	if((m_vert2Block[currentNode][k] != lastBlock1) && (m_vert2Block[currentNode][k] != lastBlock2)){
	  vecMergeBlockIDs.push_back(m_vert2Block[currentNode][k]);
	  std::cout<<"block to merge: "<< m_vert2Block[currentNode][k] << std::endl;
	}
      }
      
      for(uint64_t s=0; s<m_mbBlock2Edg[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]].size(); s++){
      	for(uint64_t l=0; l<m_mbBlock2Edg[vecMergeBlockIDs[vecMergeBlockIDs.size()-2]].size(); l++){
      	  if(m_mbBlock2Edg[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]][s] == m_mbBlock2Edg[vecMergeBlockIDs[vecMergeBlockIDs.size()-2]][l]){
      	    currentEdg=m_mbBlock2Edg[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]][s];
      	    vecCurrentEdges.push_back(currentEdg);
      	    locInd=s;
      	  }
      	} 
      }
      
      if(currentNode != m_mbQuads[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]][(locInd+1)%4]){
	currentNode=m_mbQuads[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]][(locInd+1)%4];
      }else{
	currentNode=m_mbQuads[vecMergeBlockIDs[vecMergeBlockIDs.size()-1]][locInd];
      }
      currentNodes.push_back(currentNode);
      std::cout<<" curr Node: "<<currentNode<<std::endl;
      // std::cout<<"Current edg "<<currentEdg<<std::endl;
      isExtrVertOnBdry(currentNode, &isBdry);
      // if(i==1)
      // 	exit(0);
    } 
    
    //merge blocks
    std::cout<<"Num current edges: "<<vecCurrentEdges.size()<<std::endl;
    std::cout<<"Num blocks to merge: "<<vecMergeBlockIDs.size()<<std::endl; 
    for(uint64_t m=0; m<vecCurrentEdges.size(); m++){
      std::vector<uint64_t> delBlocks;
      std::vector<uint64_t> delEdges;
      mergeBlocks(vecMergeBlockIDs[2*m+0], vecMergeBlockIDs[2*m+1], vecCurrentEdges[m], currentNodes[m], &delBlocks, &delEdges);
      allBlocks.push_back(delBlocks);
      allEdges.push_back(delEdges);
    }
    //Updating everything (quad to edg, edg to quad etc.) && Tjunctions
    //delete quads, edges and corresponding triangles!!!
    for(uint64_t m=0; m<allBlocks.size(); m++){
      for(uint64_t k=0; k<allBlocks[m].size(); k++){
	if(m_mbQuads[allBlocks[m][k]].size()!=0) 
	  m_mbQuads[allBlocks[m][k]].clear();
      }
    }
    for(uint64_t m=0; m<allEdges.size(); m++){
      for(uint64_t k=0; k<allEdges[m].size(); k++){
	//if(m_mbEdges[allEdges[m][k]].size()!=0){
	m_mbEdges[allEdges[m][k]].clear();
	m_mbEdgesTri[allEdges[m][k]].clear();
	//}
      }
    }
    std::vector<std::vector<int>> mbQuadsNew;
    std::vector<std::vector<std::array<double,3>>> mbEdgesNew;
    std::vector<std::vector<uint64_t>> mbEdgesTriNew;
    for(uint64_t m=0; m<m_mbQuads.size(); m++){
      if(m_mbQuads[m].size()!=0)
	mbQuadsNew.push_back(m_mbQuads[m]);
    }
    m_mbQuads=mbQuadsNew;
    for(uint64_t m=0; m<m_mbEdges.size(); m++){
      if(m_mbEdges[m].size()!=0){
	mbEdgesNew.push_back(m_mbEdges[m]);
	mbEdgesTriNew.push_back(m_mbEdgesTri[m]);
      }
    }
    m_mbEdges=mbEdgesNew;
    m_mbEdgesTri=mbEdgesTriNew;

    allBlocks.clear();
    allEdges.clear();
    //update structure
    std::cout<<"update structure"<<std::endl;
    getBlock2Edge();
    getEdge2Block();
    getVert2Block();
    recomputeMinEdgLength();
    dbgPosEdgData("dbgEdgDataTemp.pos"); 
    createMbTriPatchs();
    dbgPosPatchData("dbgBlockPatchTemp.pos");
    computePatchsParametrization();
    //updating Tjunctions
    m_extraordVertTjunc.erase(m_extraordVertTjunc.begin()+i);
    getTJunctionsPatchesIDs(&tJunctionPatchesIDs, &locTjunEdgInd, &locTjuncInd);
    keepCorrecting=false;
    for(size_t k=0;k<tJunctionPatchesIDs.size();k++){
      if(m_mbQuads[tJunctionPatchesIDs[k]].size()==4)
	keepCorrecting=true;
    }
    std::cout<<"Write blocks vert and edges"<<std::endl;
    for(uint64_t t=0; t<m_mbQuads.size(); t++){
      std::cout<<"Block: "<<t <<" nVertices: "<<m_mbQuads[t].size()<<", nEdges: "<< m_mbBlock2Edg[t].size()<<std::endl;
      for(uint64_t k=0; k<m_mbQuads[t].size(); k++)
	std::cout << m_mbQuads[t][k] << " , " ;
      std::cout << std::endl;
      std::cout << "edges : ";
      for(uint64_t k=0; k<m_mbBlock2Edg[t].size(); k++)
	std::cout << m_mbBlock2Edg[t][k] << " , ";
      std::cout << std::endl;
    }
    for(uint64_t t=0; t<m_mbEdg2Block.size(); t++){
      std::cout << "edge : " << t << " nBlocks : " << m_mbEdg2Block[t].size() << std::endl;
      for(uint64_t k=0; k<m_mbEdg2Block[t].size(); k++)
	std::cout << m_mbEdg2Block[t][k] << " , ";
      std::cout << std::endl;
    }
  }

  if(tJunctionPatchesIDs.size()!=0){
    std::cout << "Unable to correct all T-junctions" << std::endl;
    return HXT_STATUS_FAILED;
  }
    
  return HXT_STATUS_OK;
}

 
