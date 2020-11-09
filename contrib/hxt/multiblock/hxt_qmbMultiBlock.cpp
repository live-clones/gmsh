#include "hxt_qmbMultiBlock.h"
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
}
#include <cmath>
#include <iostream>
#include <algorithm> 

HXTStatus hxtNorm2V3(double v[3], double* norm2){
  *norm2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  return HXT_STATUS_OK;
}

MultiBlock:: MultiBlock(HXTEdges *edges, std::vector<Separatrice> vectSep, std::vector<Singularity> vectSing, std::vector<Corner> vectCorner)
{
  m_Edges=edges;
  m_vectSep=vectSep;
  m_vectSing=vectSing;
  m_vectCorner=vectCorner; 
  m_myTriMesh=NULL;
}

MultiBlock::~MultiBlock()
{
  // if(m_myTriMesh)
  //   hxtMeshDelete(&m_myTriMesh); 
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
  std::cout << "----SPLITTING TRI MESH ON MULTI-BLOCK DECOMPOSITION----" << std::endl;
  std::vector<int> flag;
  std::vector<std::vector<int>> cSep;
  std::vector<std::vector<uint64_t>> cEdg;
  std::vector<std::vector<std::array<double,3>>> cCoord;
  std::cout << "--Flagging triangles--" << std::endl;
  flagTriangles(&flag, &cSep, &cEdg, &cCoord);
  std::cout << "--Writing triangles and nodes--" << std::endl;
  // hxtWriteFlaggedTriangles(flag, "flaggedTri.pos");
  std::cout<<"--Writing nodes--"<<std::endl;
  hxtWriteFlaggedNodes(cCoord, "flaggedNodes.pos");
  std::vector<std::array<double,3>> coordOfEachVertex;
  std::vector<std::array<double,3>> allMeshNodes;
  std::vector<std::array<int,3>> allMeshTri;
  std::vector<std::array<int,2>> allMeshLines;
  std::vector<int> allMeshLinesColors;
  std::cout << "--Creating new triangles--" << std::endl;   
  createNewTriangles(flag, cSep, cCoord, &allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  std::cout << "--Writing nodes of new triangles--" << std::endl;
  hxtWriteTriVert(allMeshNodes, "meshNodes.pos" );
  std::cout << "--Creating mesh--" << std::endl;
  createMyTriMesh(&allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  std::cout << "----SPLITTING TRI MESH ON MULTI-BLOCK DECOMPOSITION FINISHED----" << std::endl;

  buildQuadLayout(); //new
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
  HXT_CHECK(hxtMalloc(&(nodeFlagged), (*numOffsets)*sizeof(int*)));
  for(int i=0; i<*numOffsets; i++){
    int *temp;
    HXT_CHECK(hxtMalloc(&(temp), 100000*sizeof(int))); //smarter solution?
    for(int j=0; j<100; j++){
      temp[j]=0;
    }
    nodeFlagged[i]=temp;
  }
  int from=0;
  int found=0;
  int num=0;
  *numQuads=0;
  for(int k=0; k<*numOffsets; k++){
    std::vector<int> connectedNodes=graphConnectedNodes[k];
    for(int t=1; t<offset[k]; t++){
      if(mark(nodeFlagged[k], offset[k])){
      	*(nodeFlagged[k]+0)=1;
      }
      //taking the node ?
      if(*(nodeFlagged[k]+0)==0){
	if(*(nodeFlagged[k]+t)==0){
	  int count=0;
	  int first=0;
	  from=connectedNodes[0];
	  quadsWithIndices[num]=from;
	  num++;
	  count++;
	  found=connectedNodes[t];
	  quadsWithIndices[num]=found;
	  num++;
	  count++;
	  *(nodeFlagged[k]+t)=1;
	  first=from;
	  while(first!=found){
	    for(int i=0; i<*numOffsets; i++){
	      std::vector<int> connectedNodesI=graphConnectedNodes[i];
	      if(connectedNodesI[0]==found){
		int length=offset[i];
		for(int j=1; j<length; j++){
		  if(connectedNodesI[j]==from){
		    if(j==1){
		      from=found;
		      if(*(nodeFlagged[i]+(length-1))==0){
			found=connectedNodesI[length-1];
			quadsWithIndices[num]=found;
			num++;
			count++;
			*(nodeFlagged[i]+(length-1))=1;
		      }
		    } else{
		      from=found;
		      if(*(nodeFlagged[i]+(j-1))==0){
			found=connectedNodesI[j-1];
			quadsWithIndices[num]=found;
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
  for(int i=0; i<*numOffsets; i++){
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

int MultiBlock::orientateTriNodes(uint64_t triNum, std::vector<std::array<double,3>> *cutPoints, std::vector<uint64_t> cutEdg,
				  std::vector<std::array<double,3>> *orientedPoints){
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

int MultiBlock::reorderingConnectivityNodes(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets, int *newConnectedNodes, std::vector<std::vector<int>> *graphConnectedNodes){
 
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
    
    HXT_CHECK(hxtFree(&angles1));
    HXT_CHECK(hxtFree(&angles2));
    HXT_CHECK(hxtFree(&anglesUsed));
    HXT_CHECK(hxtFree(&nodes));
    HXT_CHECK(hxtFree(&nodesSorted));
    HXT_CHECK(hxtFree(&conn));

  }
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

int MultiBlock::split(std::vector<int> nodes, std::vector<std::array<int,3>> *triVertInd, std::vector<int> *rest){
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
	split(nodes, &trianglesVertInd, &rest);
	for(uint64_t j=0; j<trianglesVertInd.size(); j++)
	  (*newTri).push_back(trianglesVertInd[j]);
	while(rest.size()!=0){//we dont have all triangles
	  std::vector<std::array<int,3>> trianglesVertInd1;
	  std::vector<int> rest2;
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
    if(normBCBP<1e-8)
      (*localCutEdges)[k]=edges->tri2edg[3*triNum+1];
    if(normCACP<1e-8)
      (*localCutEdges)[k]=edges->tri2edg[3*triNum+2];
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
  hxtWriteGraphNodes(newNodes, "qmbGraphNodes1.pos");
  hxtWriteGraphNodes(m_extraordVertices, "qmbGraphNodes2.pos");


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
  std::cout << "--Reorder nodes connectivity--" << std::endl;
  int *newConnectedNodes;
  HXT_CHECK(hxtMalloc(&newConnectedNodes, initAlloc*sizeof(int)));
  std::vector<std::vector<int>> graphConnectedNodes;
  reorderingConnectivityNodes(connectedNodes, connectedTri, connectedDir, offsetN, &numOffsets, newConnectedNodes, &graphConnectedNodes);
  std::cout << "--connectedNodes--" << std::endl;
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

  std::cout << "--Kill duplicates--" << std::endl;
  std::vector<std::vector<int>> cleanGraphConnectedNodes;
  int *cleanOffsetN;
  HXT_CHECK(hxtMalloc(&cleanOffsetN, initAlloc*sizeof(int)));
  killDuplicates(graphConnectedNodes, &cleanGraphConnectedNodes, cleanOffsetN);
  std::cout << "--Clean graph connected nodes--" << std::endl;
  // for(uint64_t s=0; s<cleanGraphConnectedNodes.size(); s++){
  //   for(uint64_t m=0; m<cleanGraphConnectedNodes[s].size(); m++)
  //     std::cout<<" "<<cleanGraphConnectedNodes[s][m]<<" ";
  //   std::cout<<std::endl;
  // }
  std::cout << "--Define quads--" << std::endl;
  int *quadsWithIndices;
  HXT_CHECK(hxtMalloc(&quadsWithIndices,4*initAlloc*sizeof(int)));
  int numQuads=-1;
  int sizesQuads[1000000];
  defineQuads(cleanGraphConnectedNodes, quadsWithIndices, cleanOffsetN, &numOffsets, sizesQuads, &numQuads);

  // std::cout << "Number of quads: " <<numQuads<< std::endl;
  // for(int s=0; s<numQuads; s++)
  //   std::cout << "num quad nodes: " <<sizesQuads[s]<< std::endl;
  
  // std::cout << "Quads with indices: " << std::endl;
  // for(int m=0; m<sizesQuads[0]; m++)
  //   std::cout<<"Indice: "<<quadsWithIndices[m]<<std::endl;
  // for(int s=1; s<numOffsets; s++){
  //   for(int m=0; m<sizesQuads[s]; m++)
  //     std::cout<<"Indice: "<<s<<" "<<quadsWithIndices[m+cleanOffsetN[s-1]]<<std::endl;
  // }

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
  std::cout<<"----COLLECTING BLOCKS DATA!----"<<std::endl;
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
  getQuadEdgesData();
  std::cout<<"block2edg"<<std::endl;
  getBlock2Edge();
  std::cout<<"edg2block"<<std::endl;
  getEdge2Block();
  // for(uint64_t t=0; t<m_mbQuads.size(); t++)
  //   std::cout<<"Block: "<<t <<" nVertices: "<<m_mbQuads[t].size()<<", nEdges: "<< m_mbBlock2Edg[t].size()<<std::endl;
  std::cout<<"triPatches"<<std::endl;
  std::vector<int> triPatchesIDs;
  getTriangularPatchesIDs(&triPatchesIDs);
  std::cout<<"num triPatches: "<< triPatchesIDs.size()<<std::endl;
  std::cout<<"T-junction patches"<<std::endl;
  std::vector<int> tJunctionPatchesIDs;
  getTJunctionsPatchesIDs(&tJunctionPatchesIDs);
  std::cout<<"num T-junction patches: "<< tJunctionPatchesIDs.size()<<std::endl;
  for(uint64_t mt=0; mt<tJunctionPatchesIDs.size(); mt++)
    std::cout<<"T-junc patch ID: "<<tJunctionPatchesIDs[mt]<<std::endl;

  //---------------------------------------------------------------------------
  // for(uint64_t sl=0; sl<m_tri.size(); sl++)
  //   std::cout<<" "<<m_tri[sl];
  // std::cout<< " "<<std::endl; 
  
  std::cout<<"start printing"<<std::endl;
  uint64_t triNumX[1];
  getTriNumFromPointCoord(m_extraordVertices[2], m_tri, triNumX);
  std::cout<<"Printing node and tri end"<<std::endl;
  
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
   std::cout<<"----Collecting data  FINISHED!----"<<std::endl;
  //new functions end
  
  
  HXT_CHECK(hxtFree(&connectedNodes));
  HXT_CHECK(hxtFree(&connectedTri));
  HXT_CHECK(hxtFree(&connectedDir));
  HXT_CHECK(hxtFree(&offsetN));
  HXT_CHECK(hxtFree(&cleanOffsetN));
  HXT_CHECK(hxtFree(&newConnectedNodes));
  HXT_CHECK(hxtFree(&quadsWithIndices));
  HXT_CHECK(hxtFree(&nodesOnBdry));
  m_mbDecompExists=1;
  return HXT_STATUS_OK;

}

void MultiBlock::buildTotalPatches(){
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
    // int isInPatch=checkIfInPatch2(triangle1);
    // int isInIgnoredPatch1=m_vectSep[sepID1].isInIgnoredPatch(triangle1);
    for(uint64_t j=1; j<jEnd; j++){
      // bool isBoundarySep = (sep1->isBoundary() || sep2->isBoundary());
      uint64_t triangle2=(*elements2)[j];
      // int isInIgnoredPatch2=m_vectSep[sepID2].isInIgnoredPatch(triangle2);
      // if((triangle1==triangle2) && (!isInPatch || isBoundarySep || isInIgnoredPatch1 || isInIgnoredPatch2)){
      // if((triangle1==triangle2) && (!isInPatch || isInIgnoredPatch1 || isInIgnoredPatch2)){
      if(triangle1==triangle2){
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
	  std::array<double,3> pFirst={{0.0,0.0,0.0}};;
	  for(int s=0; s<3; s++)
	    pFirst[s]=currentIntersectionPoint[s];
	  (*intersectionPoints).push_back(pFirst);
	  std::array<double,3> b=(*sepPoints1)[i-1];
	  std::array<double,3> newDir={{0.0,0.0,0.0}};
	  for(int t=0; t<3; t++){
	    newDir[t]=b[t]-pFirst[t]; 
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
	  if(isIntersecting){ 
	    for(uint64_t l=0; l<intersectionPoints.size(); l++){
	      (*nodesCoord).push_back(intersectionPoints[l]);
	      (*directions).push_back(directionsNew[l]);
	      (*triangles).push_back(newTriangles[l]);
	      (*distance).push_back(length[l]);
	      num++;
	    }
	  }
	}
      } 
 
      // adding last point
      // if((*elements)[elements->size()-1]!=(uint64_t)-1){
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
	if(isPointSingularity(pointCandidate)){
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
      uint64_t tri=edges->edg2tri[2*sepEdg+0];
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
      // addInUnsgnIntVectIfNotPresent(&vectTrianglesID, trianglesID[s]);
      //addInIntVectIfNotPresent(&vectNodesID, nodesID[s]);
      vectTrianglesID.push_back(trianglesID[s]);
      vectNodesID.push_back(nodesID[s]);
    }

    m_sepGraphNodes.push_back(vectNodesID);
    m_sepGraphTriangles.push_back(vectTrianglesID);
    m_sepGraphDirections.push_back(vectDirectionsID1);
    

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
	    }else if(m!=(sizeElementsPerSep-1)){
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
    sepInd=getSepCleanIDfrom2extVert(quadIndices[j-1],quadIndices[j]);
    getSepIDFromCleanedSepInd(sepInd, &ID);
    if(ID!=-1){
      sepEdges.push_back(ID);
      Separatrice *s=&(m_vectSep[ID]);
      if(s->isBoundary())
	num++;
    }
  }
  if(sepEdges.size()!=(uint64_t)num)
    indicator=1;
 
  return indicator;
}

int MultiBlock::getSepCleanIDfrom2extVert(int ind1, int ind2){
  for(uint64_t i=0;i<m_sepGraphNodes.size();i++){
    std::vector<int> sepByExtrVert=m_sepGraphNodes[i];
    for(uint64_t l=0;l<sepByExtrVert.size()-1;l++){
      if((sepByExtrVert[l]==ind1&&(sepByExtrVert[l+1]==ind2))||(sepByExtrVert[l]==ind2&&(sepByExtrVert[l+1]==ind1)))
	return i;
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
      if(!isPointSingularityOrCornerVec(&point1))
	nodeCoord.push_back(point1);
      for(uint64_t k=start; k<end; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
      }
      nodeCoord.push_back(point2);
      m_mbEdges.push_back(nodeCoord);
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
      // adding first point if its not a singularity
      if(!isPointSingularityOrCornerVec(&point1))
	nodeCoord.push_back(point1);
      uint64_t last=sepNodeCoord.size(); //different indice but the same node as for first ind=0
      for(uint64_t k=start; k<last; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
      }
      for(uint64_t k=1; k<end; k++){
	std::array<double,3> point=sepNodeCoord[k];
	nodeCoord.push_back(point);
      }
      nodeCoord.push_back(point2);
      m_mbEdges.push_back(nodeCoord);
    }
  }

  return 1;
}

int MultiBlock::getBlock2Edge(){
  std::array<double,3> firstPoint, lastPoint;
  std::vector<std::array<double,3>> edgPoints;
  for(uint64_t i=0; i<m_mbQuads.size(); i++){
    std::vector<uint64_t> blockEdges;
    std::vector<int> nodes;
    std::vector<std::array<double,3>> pointsCoord;
    for(uint64_t s=0; s<m_mbQuads[i].size(); s++){
      nodes.push_back(m_mbQuads[i][s]);
      pointsCoord.push_back(m_extraordVertices[nodes[s]]);
    }
    for(uint64_t j=0; j<m_mbEdges.size(); j++){
      edgPoints=m_mbEdges[j];
      uint64_t end=edgPoints.size()-1;
      firstPoint=edgPoints[0];
      lastPoint=edgPoints[end];
      double norm=-1.;
      // for(uint64_t k=0; k<m_mbEdges[j].size()-1;k++){
      for(uint64_t k=0; k<pointsCoord.size()-1;k++){
	if((isPointDuplicateVec(&firstPoint, &pointsCoord[k], &norm) && isPointDuplicateVec(&lastPoint, &pointsCoord[k+1], &norm)) ||
	   (isPointDuplicateVec(&firstPoint, &pointsCoord[k+1], &norm)&& isPointDuplicateVec(&lastPoint, &pointsCoord[k], &norm))){
	  blockEdges.push_back(j);
	}
      }
      if((isPointDuplicateVec(&firstPoint, &pointsCoord[0], &norm) && isPointDuplicateVec(&lastPoint, &pointsCoord[pointsCoord.size()-1], &norm)) ||
	 (isPointDuplicateVec(&firstPoint, &pointsCoord[pointsCoord.size()-1], &norm)&& isPointDuplicateVec(&lastPoint, &pointsCoord[0], &norm)))
	blockEdges.push_back(j);
    }
    m_mbBlock2Edg.push_back(blockEdges);
  }
  return 1;
}

int MultiBlock::getEdge2Block(){
  for(uint64_t i=0; i<m_mbEdges.size(); i++){
    std::vector<uint64_t> qVal;
    for(uint64_t j=0; j<m_mbQuads.size(); j++){
      for(uint64_t k=0; k<m_mbBlock2Edg[j].size(); k++){
	if(m_mbBlock2Edg[j][k]==i){
	  qVal.push_back(i);
	}
      }   
    }
    m_mbEdg2Block.push_back(qVal);
  }
  return 1;
}

//is it needed?
// HXTStatus MultiBlock::getExtrVertIndFromSepID(int ID, std::vector<int> *extraVertIndices){
//   int ind=-1;
//   getCleanedSepIndFromSepID(ID, &ind);
//   extraVertIndices = m_sepGraphNodes[ind];
  
//   return HXT_STATUS_OK;
// }

HXTStatus MultiBlock::collectTJunctionIndices(){
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
//finding the 2sep which contain Tjunction normal sep and a limit cycle)
//finding the closest neighbour of the T-junction which is not boundary or a T-junction (on the separatrice witch is not a limit cycle) 
//knowing T-junction node, its closest neighbours -> getting a block for correction 
HXTStatus MultiBlock::getTJunctionsPatchesIDs(std::vector<int> *tJunctionPatchesIDs){
  int isBdry =0;
  int isTjunction =0;
  int nodeID1 =-1;
  int nodeID2 =-1;
  bool isLimitCycle;
  if(m_extraordVertTjunc.size()>0){
    for(uint64_t i=0; i<m_extraordVertTjunc.size(); i++){
      for(uint64_t j=0; j<m_vectSep.size(); j++){
	double min=std::numeric_limits<double>::max();
	double distance=-1.0;
	Separatrice *sep=&(m_vectSep[j]);
	if(sep->isSaved() && !(sep->getIsLimitCycle())){ //separatrice which is not a limit cycle
	  int sepID=sep->getID();
	  int ind=-1;
	  getCleanedSepIndFromSepID(sepID, &ind);
	  for(uint64_t k=0; k<m_sepGraphNodes[ind].size(); k++){
	    if(m_extraordVertTjunc[i]==m_sepGraphNodes[ind][k]){
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
	if(sep->isSaved() && (sep->getIsLimitCycle())){ //separtrice which is a limit cycle
	  int sepID=sep->getID();
	  int ind=-1;
	  getCleanedSepIndFromSepID(sepID, &ind);
	  if(m_extraordVertTjunc[i] == m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-1]){
	    // nodeID2 = m_sepGraphNodes[ind][m_sepGraphNodes[ind].size()-2]; //DUPLICATES! to fix
	    nodeID2 = m_sepGraphNodes[ind][0];
	  }
	}
      }
      //finding a right block
      // std::cout<<"Indices: "<<nodeID1<<"; "<<nodeID2<<"; "<<m_extraordVertTjunc[i]<<std::endl;
      int blockID=-1;
      getBlockIDFromVertInd(nodeID1, nodeID2, m_extraordVertTjunc[i], &blockID);
      // std::cout<<"block id: "<<blockID<<std::endl;
      tJunctionPatchesIDs->push_back(blockID);
  
    }
  }
  
  return  HXT_STATUS_OK;
}

//Function not good	    
// HXTStatus MultiBlock::getDataFromBlockEdgID(int edgID, std::vector<std::array<double, 3>> *pointsOnEdg, std::vector<uint64_t> *trianglesOnEdg){
//   std::vector<std::array<double,3>> edgPoints = m_mbEdges[edgID];
//   int startInd=-1; int endInd=-1;
//   double norm=-1.0;
//   for(uint64_t i=0; i<m_extraordVertices.size(); i++){
//     if(isPointDuplicateVec(&m_mbEdges[edgID][0], &m_extraordVertices[i], &norm))
//       startInd=i;
//     if(isPointDuplicateVec(&m_mbEdges[edgID][1], &m_extraordVertices[i], &norm))
//       endInd=i;
//   }
//   std::cout<<"start and end ind: "<<startInd<<"; "<<endInd<<std::endl;
//   int sepInd=getSepCleanIDfrom2extVert(startInd, endInd);
//   std::cout<<"Ind: "<<sepInd<<std::endl;
//   int ID=-1;
//   getSepIDFromCleanedSepInd(sepInd, &ID);
//   std::cout<<"sep id: "<<ID<<std::endl;
//   uint64_t startTri = m_tri[startInd];
//   uint64_t endTri = m_tri[endInd];
//   std::cout<<"Start and end tri "<<startTri<<" "<<endTri<<std::endl; 
//   Separatrice *sep=&(m_vectSep[ID]);
//   std::vector<uint64_t> *triangles = sep->getPTriangles();
//   std::vector<std::array<double,3>> *pointCoord = sep->getPCoord();
//   int start=-1; int end=-1;
//   for(uint64_t i=0; i<triangles->size(); i++){
//     if(startTri == (*triangles)[i])
//       start = (int) i;
//     if(endTri == (*triangles)[i])
//       end = (int) i;
//   }

//  std::cout<<"start and end: "<<start<<"; "<<end<<std::endl;
//   for(uint64_t i=start; i<end+1; i++)
//     trianglesOnEdg->push_back((*triangles)[i]);
 
//   pointsOnEdg->push_back(m_mbEdges[edgID][0]);
//   for(uint64_t i=start; i<end; i++)
//     pointsOnEdg->push_back((*pointCoord)[i]); 
//   pointsOnEdg->push_back(m_mbEdges[edgID][1]);


//   return  HXT_STATUS_OK;
// }

int MultiBlock::isPointInTri(std::array<double, 3> point1, std::array<double, 3> point2, std::array<double, 3> currPoint, double *alpha){

  int flag=0;
  *alpha=-1.0;
  double AB[3], AP[3];
  for(int i=0; i<3; i++){
    AB[i]=point2[i]-point1[i];
    AP[i]=currPoint[i]-point1[i];
  }

  double val=sqrt(AP[0]*AP[0]+AP[1]*AP[1]+AP[2]*AP[2])/sqrt(AB[0]*AB[0]+AB[1]*AB[1]+AB[2]*AB[2]);
  
  if(val>1e-6 && val<1.0001){
    flag=1;
    *alpha=val;
  }
  
  return flag;
}

HXTStatus MultiBlock::getTriNumFromPointCoord(std::array<double, 3> pointCoord, std::vector<uint64_t> vectorTriangles, uint64_t *triNum){
  HXTEdges *edges = m_Edges; 
  HXTMesh *mesh = edges->edg2mesh; //from normal mesh
  double *vert = mesh->vertices.coord;
  uint32_t* nodes = mesh->triangles.node;
  std::array<double, 3> coordV1 = {0.,0.,0.};
  std::array<double, 3> coordV2 = {0.,0.,0.};
  std::array<double, 3> coordV3 = {0.,0.,0.};
  std::cout<<"Point: "<<pointCoord[0]<<" "<<pointCoord[1]<<" "<<pointCoord[2]<<std::endl;
  double norm1=-1.0; double norm2=-1.0;
  double alpha=-1.0;
  int found=0;
  *triNum = (uint64_t)-1;
  for(uint64_t i=0; i<vectorTriangles.size(); i++){
    if(found==0){
      for(int k=0; k<3; k++){
	coordV1[k] = vert[4*nodes[3*(vectorTriangles[i])+0]+k];
	coordV2[k] = vert[4*nodes[3*(vectorTriangles[i])+1]+k];
	coordV2[k] = vert[4*nodes[3*(vectorTriangles[i])+2]+k];
      }
      if(!(isPointDuplicateVec(&coordV1, &pointCoord, &norm1)) && !(isPointDuplicateVec(&coordV2, &pointCoord, &norm2))){
	if(isPointInTri(coordV1, coordV2, pointCoord, &alpha)){
	  *triNum = vectorTriangles[i];
	  found=1; 
	  std::cout<<"position1, tri number: "<<*triNum<<std::endl;
	}
      }
      if((found==0) && !(isPointDuplicateVec(&coordV1, &pointCoord, &norm1)) && !(isPointDuplicateVec(&coordV3, &pointCoord, &norm2))){
	if(isPointInTri(coordV1, coordV3, pointCoord, &alpha)){
	  *triNum = vectorTriangles[i];
	  found=1;
	  std::cout<<"position2, tri number: "<<*triNum<<std::endl;
	}
      }
      if((found==0) && !(isPointDuplicateVec(&coordV2, &pointCoord, &norm1)) && !(isPointDuplicateVec(&coordV3, &pointCoord, &norm2))){
	if(isPointInTri(coordV2, coordV3, pointCoord, &alpha)){
	  *triNum = vectorTriangles[i];
	  found=1;
	  std::cout<<"position3, tri number: "<<*triNum<<std::endl;
	}
      } 
    }
  }

  //print DBG file--------------------------------------------------------------
  uint64_t *elemFlagged;
  HXT_CHECK(hxtMalloc(&elemFlagged, mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<mesh->triangles.num; i++)
    elemFlagged[i]=0;
  elemFlagged[(*triNum)]=1;
  // for(uint64_t i=0; i<m_tri.size(); i++)
  //   elemFlagged[m_tri[i]]=static_cast<int>(i) + 5;
  FILE *f = fopen("jovana.pos","w");
  fprintf(f,"View \"Nodes\" {\n");
  fprintf(f,"SP(%g,%g,%g){%i};\n", pointCoord[0],pointCoord[1], pointCoord[2], 1); 
  // for(uint64_t i=0; i<m_extraordVertices.size(); i++){
  //   int color=static_cast<int>(i) + 5;
  //   fprintf(f,"SP(%g,%g,%g){%i};\n", m_extraordVertices[i][0], m_extraordVertices[i][1], m_extraordVertices[i][2], color); 
  // }
  fprintf(f,"};");
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
    fprintf(f,"%i, %i, %i",elemFlagged[i],elemFlagged[i],elemFlagged[i]);
    fprintf(f,"};\n");    
  }
  fprintf(f,"};");
  fclose(f); 
  HXT_CHECK(hxtFree(&elemFlagged));
  

  return  HXT_STATUS_OK;
}

double MultiBlock::normDiffVect(std::array<double,3> *coordP1, std::array<double,3> *coordP2){
  double L=0;
  for(uint64_t k=0;k<(*coordP1).size();k++)
    L+=((*coordP2)[k]-(*coordP1)[k])*((*coordP2)[k]-(*coordP1)[k]);
  L=sqrt(L);
  return L;
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
  std::cout<<"edgLength: "<<edgLength<<std::endl;
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
