#include "hxt_qmbMultiBlock.h"
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
}
#include <iostream>
#include <algorithm> 

MultiBlock:: MultiBlock(HXTEdges *edges, std::vector<Separatrice> vectSep, std::vector<Singularity> vectSing, std::vector<Corner> vectCorner)
{
  m_Edges=edges;
  m_vectSep=vectSep;
  m_vectSing=vectSing;
  m_vectCorner=vectCorner; 
  m_contextTri=NULL;
  m_myTriMesh=NULL;
}

MultiBlock::~MultiBlock()
{
  if(m_contextTri)
    hxtContextDelete(&m_contextTri);
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
  //if(*norm<1e-10)
  if(*norm<=1e-6)
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
  if(*norm<1e-10)
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

static bool sortDouble(double u, double v)
{
  return u < v;
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
  hxtWriteFlaggedTriangles(flag, "flaggedTri.pos");
  hxtWriteFlaggedNodes(cCoord, "flaggedNodes.pos");
  std::vector<std::array<double,3>> coordOfEachVertex;
  std::vector<std::array<double,3>> allMeshNodes;
  std::vector<std::array<int,3>> allMeshTri;
  std::vector<std::array<int,2>> allMeshLines;
  std::vector<int> allMeshLinesColors;
  std::cout << "--Creating new triangles--" << std::endl;   
  createNewTriangles(flag, cSep, cCoord, &allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  std::cout << "--Writing nodes of new triangles--" << std::endl;
  hxtWriteTriVert(allMeshNodes, "triVert1.pos" );
  std::cout << "--Creating mesh--" << std::endl;
  createMyTriMesh(&allMeshNodes, &allMeshTri, &allMeshLines, &allMeshLinesColors);
  std::cout << "----SPLITTING TRI MESH ON MULTI-BLOCK DECOMPOSITION FINISHED----" << std::endl;
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
  if(alpha>-1e-9 && alpha<=1+1e-9 && gamma>-1e-9 && gamma<=1+1e-9){
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
  if(fabs(n[0])<1e-7 && fabs(n[1])<1e-7 && fabs(n[2])<1e-7){
    *edgNum=edges->tri2edg[3*triNum+0];
  }else{
    crossprod(BC,BP,n);
    if(fabs(n[0])<1e-7 && fabs(n[1])<1e-7 && fabs(n[2])<1e-7){
      *edgNum=edges->tri2edg[3*triNum+1];
    }
    else{
      crossprod(AC,AP,n);
      if(fabs(n[0])<1e-7 && fabs(n[1])<1e-7 && fabs(n[2])<1e-7){
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
  if(alpha<0.0005){
    for(int i=0; i<3; i++)
      (*point)[i]=vert[4*nodes[3*triNum+locEdg]+i];
    flag=1;
  }
  else if(alpha>0.9995){
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
  //small func gives back the edge
  for(uint64_t i=0; i<cutEdg.size(); i++){
    if(edges->tri2edg[3*triNum+0]==cutEdg[i]){
      if(!isCloseToVert(&((*cutPoints)[i]),cutEdg[i],triNum, &alpha)){ //not to double vertex
	e1Points.push_back((*cutPoints)[i]);
	d1.push_back(alpha);
      }
    }
    if(edges->tri2edg[3*triNum+1]==cutEdg[i]){
      if(!isCloseToVert(&((*cutPoints)[i]),cutEdg[i],triNum, &alpha)){ //not to double vertex
	e2Points.push_back((*cutPoints)[i]);
	d2.push_back(alpha);
      }
    }
    if(edges->tri2edg[3*triNum+2]==cutEdg[i]){
      if(!isCloseToVert(&((*cutPoints)[i]),cutEdg[i],triNum, &alpha)){ //not to double vertex
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
      // if(ind2!=-1 && ind1!=-1){
	addInIntVectIfNotPresent(&((*connectedNodes)[ind1]), ind2);
      }
      if(ind1!=-1){
      // if(ind1!=-1 && ind2!=-1){
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
  int initAlloc=100;
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
  std::cout<<"FLAG on tri 6 is: "<<flag[6]<<std::endl;
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
      if(newTri.size()==0){ //triangles which edg is bnd sep
	// for(int j=0; j<3; j++){
	//   coord1[j]=vert[4*nodes[3*i+0]+j];
	//   coord2[j]=vert[4*nodes[3*i+1]+j];
	//   coord3[j]=vert[4*nodes[3*i+2]+j];
	// }
	// (*allMeshNodes).push_back(coord1);
	// (*allMeshNodes).push_back(coord2);
	// (*allMeshNodes).push_back(coord3);
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
	    //addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint1, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, linePoint1, &ind);
	    lineIndices[0]=ind;
	  }
	  if(isTriVert(i, linePoint2, &ind)){
	    lineIndices[1]=ind; 
	  }else{
	    //addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint2, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, linePoint2, &ind);
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
	    //addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint1, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, linePoint1, &ind);
	    lineIndices[0]=ind;
	  }
	  if(isTriVert(i, linePoint2, &ind)){
	    lineIndices[1]=ind; 
	  }else{
	    //addInPointsVectIfNotPresentCustomized(start, allMeshNodes, linePoint2, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, linePoint2, &ind);
	    lineIndices[1]=ind;
	  }
	  allMeshLines->push_back(lineIndices);
	  allMeshLinesColors->push_back(localLinesColors[j]);
	}
	//add allTriangles
	for(uint64_t j=0; j<newTri.size(); j++){
	  std::array<double,3> point1, point2, point3;
	  convertIndToCoord(orientedPoints,newTri[j][0], &point1);
	  convertIndToCoord(orientedPoints,newTri[j][1], &point2);
	  convertIndToCoord(orientedPoints,newTri[j][2], &point3);
	  
	  //adding new nodes in the mesh
	  int ind=-1;
	  if(isTriVert(i, point1, &ind)){
	    vertIndices[0]=ind; 
	  }else{
	    // addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point1, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, point1, &ind);
	    vertIndices[0]=ind;
	  }
	  if(isTriVert(i, point2, &ind)){
	    vertIndices[1]=ind; 
	  }else{
	    // addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point2, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, point2, &ind);
	    vertIndices[1]=ind;
	  }
	  if(isTriVert(i, point3, &ind)){
	    vertIndices[2]=ind; 
	  }else{
	    // addInPointsVectIfNotPresentCustomized(start, allMeshNodes, point3, &ind);
	    addInPointsVectIfNotPresentCustomized(0, allMeshNodes, point3, &ind);
	    vertIndices[2]=ind;
	  }
	  (*allMeshTri).push_back(vertIndices);
	}
      }
    }
  }
  return 1;
}

HXTStatus MultiBlock::createMyTriMesh(std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri, std::vector<std::array<int,2>> *allMeshLines, std::vector<int> *allMeshLinesColors){
  hxtContextCreate(&m_contextTri);
  HXT_CHECK(hxtMeshCreate(m_contextTri,&(m_myTriMesh)));
  // vertices
  m_myTriMesh->vertices.num = allMeshNodes->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->vertices.coord),4*(m_myTriMesh->vertices.num)*sizeof(double)));
  for(uint64_t i=0; i<m_myTriMesh->vertices.num; i++){
    for(int t=0; t<3; t++)
      m_myTriMesh->vertices.coord[4*i+t] = (*allMeshNodes)[i][t];
    m_myTriMesh->vertices.coord[4*i+3] = 0.0;
  }
  //DBG start------------------------------------------------
  for(uint64_t i=0; i<m_myTriMesh->vertices.num; i++){
    for(uint64_t j=0; j<m_myTriMesh->vertices.num; j++){
      if(i!=j){
	if(m_myTriMesh->vertices.coord[4*i+0] == m_myTriMesh->vertices.coord[4*j+0]  &&
	   m_myTriMesh->vertices.coord[4*i+1] == m_myTriMesh->vertices.coord[4*j+1] &&
	   m_myTriMesh->vertices.coord[4*i+2] == m_myTriMesh->vertices.coord[4*j+2] )
	  std::cout<<"Duplicated vertices: "<<i<<" "<<j<<std::endl;
      }
    }
  }
  //DBG end------------------------------------------------
  
  // triangles
  m_myTriMesh->triangles.num = allMeshTri->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->triangles.node),3*(m_myTriMesh->triangles.num)*sizeof(uint64_t)));
  for(uint64_t i=0; i<m_myTriMesh->triangles.num; i++){
    for(int t=0; t<3; t++)
      m_myTriMesh->triangles.node[3*i+t] = (*allMeshTri)[i][t];
    //DBG start-------
    if(m_myTriMesh->triangles.node[3*i+0]== m_myTriMesh->triangles.node[3*i+1] ||
       m_myTriMesh->triangles.node[3*i+0]== m_myTriMesh->triangles.node[3*i+2] ||
       m_myTriMesh->triangles.node[3*i+1]== m_myTriMesh->triangles.node[3*i+2])
      std::cout<<"FLATEN TRI: "<<i<<std::endl;
    //DBG end-------------------------
  }
  for(uint64_t i=0; i<m_myTriMesh->triangles.num; i++){
    for(uint64_t j=0; j<m_myTriMesh->triangles.num; j++){
      if(i!=j){
	if(m_myTriMesh->triangles.node[3*i+0]== m_myTriMesh->triangles.node[3*j+0] &&
	   m_myTriMesh->triangles.node[3*i+1]== m_myTriMesh->triangles.node[3*j+1] &&
	   m_myTriMesh->triangles.node[3*i+2]== m_myTriMesh->triangles.node[3*j+2])
	  std::cout<<"DUPLICATED TRI: "<<i<<" "<<j<<std::endl;
      }
    }
  }

  
  // lines
  m_myTriMesh->lines.num = allMeshLines->size();
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->lines.node),2*(m_myTriMesh->lines.num)*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&(m_myTriMesh->lines.colors),(m_myTriMesh->lines.num)*sizeof(uint16_t)));
  for(uint64_t i=0; i<m_myTriMesh->lines.num; i++){
    for(uint64_t t=0; t<2; t++)
      m_myTriMesh->lines.node[2*i+t] = (uint32_t)(*allMeshLines)[i][t];
    m_myTriMesh->lines.colors[i] = (uint16_t)((*allMeshLinesColors)[i]);
    //DBG start-------
    if(m_myTriMesh->lines.node[2*i+0] == m_myTriMesh->lines.node[2*i+1])
      std::cout<<"FLATEN LINE: "<<i<<" Vertices: "<<m_myTriMesh->lines.node[2*i+0]<<" "<<m_myTriMesh->lines.node[2*i+1]<<std::endl;
    //DBG end--------
  }
  for(uint64_t i=0; i<m_myTriMesh->lines.num; i++){
    for(uint64_t j=0; j<m_myTriMesh->lines.num; j++){
      if(i!=j){
	if(m_myTriMesh->lines.node[2*i+0] == m_myTriMesh->lines.node[2*j+0] && m_myTriMesh->lines.node[2*i+1] == m_myTriMesh->lines.node[2*j+1])
	  std::cout<<"DUPLICATED LINE: "<<i<<" "<<j<<std::endl;
      }
    }
  }

  
  hxtMeshWriteGmsh(m_myTriMesh, "qmbMyTriMesh.msh");
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
    fprintf(f,"ST(");
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],mesh->triangles.node[3*i+1],mesh->triangles.node[3*i+2]};
    for(uint32_t j=0; j<3; j++){
      fprintf(f,"%f,%f,%f",mesh->vertices.coord[4*vtri[j]+0],mesh->vertices.coord[4*vtri[j]+1],mesh->vertices.coord[4*vtri[j]+2]);
      if(j<2)
        fprintf(f,",");
    }
    fprintf(f,")");
    fprintf(f,"{");
    if(i!=33112)
      fprintf(f,"%i, %i, %i",flag[i],flag[i],flag[i]);
    else
      fprintf(f,"%i, %i, %i",4,4,4);
    fprintf(f,"};\n");    
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
	int color=(int)j;
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







