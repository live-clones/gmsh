//crosses computed on edges with crouzeix raviart
//H computed on triangular nodes

//We have to think by GFaces

//map triangles to edges
//Map edges to triangles
//map line to edge ??
//map edge to line ??


//cross class
// -- edge associated to cross
// -- get four directions
// -- get theta (regarding the local basis)
// -- get 3 euler angles (normal fixed. It has to be manifold normal)
// -- lifting to a given direction
//Edge enriched
// -- local basis
// -- ??

//Get mesh faces and lines
//Compute gaussian curvature
//Compute geodesic curvature
//Cutting mesh along feature lines
// -- Keep correspondances to old mesh
//Creating cut graph and cutting mesh along it
// -- Keep correspondances to old mesh
//Creating smooth arbitrary 3D basis
// -- work on mesh cut along feature lines and cutgraph
//Compute H
//Create lifting of local basis on a triangle, to get phi, gamma and psi (same as in 3D, avoiding locks etc)
//Compute crossfield
//Compute overall lifting
//Compute Potentials

#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MEdge.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include <queue>
#include <stack>
#include <limits>
#include "GmshMessage.h"

#include "conformalMapping.h"
//FOR DBG VIEWS ONLY
#include "gmsh.h"

#if defined(HAVE_SOLVER) && defined(HAVE_POST)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemGmm.h"
#include "linearSystemMUMPS.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#endif

//TODO: add condition module exists
#include "fullMatrix.h"

#ifdef HAVE_QUADMESHINGTOOLS
#include "qmt_cross_field.h"
#endif

static void getModelFaces(GModel *gm, std::set<GFace *> &f)
{
  if(f.size()>0){
    Msg::Warning("Faces set not empty. Clearing it.");
    f.clear();
  }
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    GFace *gf = *it;
    f.insert(gf);
  }
}

static void getModelEdges(GModel *gm, std::set<GEdge *> &e)
{
  if(e.size()>0){
    Msg::Warning("Edges set not empty. Clearing it.");
    e.clear();
  }
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    GEdge *ge = *it;
    e.insert(ge);
  }
}

static void getFaceEdges(GFace *gf, std::set<GEdge *> &e)
{
  if(e.size()>0){
    Msg::Warning("Edges set not empty. Clearing it.");
    e.clear();
  }
  for (GEdge* ge: gf->edges()) {
    e.insert(ge);
  }
  for (GEdge* ge: gf->embeddedEdges()) {
    e.insert(ge);
  }
}

static void addFaceTriangles(GFace *gf, std::set<MTriangle *, MElementPtrLessThan> &t)
{
  for(std::vector<MTriangle *>::const_iterator it = gf->triangles.begin(); it != gf->triangles.end(); ++it) {
    MTriangle *mt = *it;
    t.insert(mt);
  }
}

static void addEdgeLines(GEdge *ge, std::set<MLine *, MLinePtrLessThan> &l)
{
  for(std::vector<MLine *>::const_iterator it = ge->lines.begin(); it != ge->lines.end(); ++it) {
    MLine *ml = *it;
    l.insert(ml);
  }
}

static void addEdgeLinesEntities(GEdge *ge, std::map<MLine *, GEdge *, MLinePtrLessThan> &linesEntities)
{
  for(std::vector<MLine *>::const_iterator it = ge->lines.begin(); it != ge->lines.end(); ++it) {
    MLine *ml = *it;
    linesEntities[ml]=ge;
  }
}

static void getAllLinesAndTriangles(GModel *gm, std::set<MLine *, MLinePtrLessThan> &l, std::map<MLine *, GEdge *, MLinePtrLessThan> &linesEntities, std::set<MTriangle *, MElementPtrLessThan> &t){
  if(l.size()>0){
    Msg::Warning("Lines set not empty. Clearing it.");
    l.clear();
  }
  if(t.size()>0){
    Msg::Warning("Triangles set not empty. Clearing it");
    t.clear();
  }
  std::set<GFace *> f;
  std::set<GEdge *> e;
  getModelFaces(gm, f);
  getModelEdges(gm, e);
  for(GEdge *ge: e){
    addEdgeLines(ge, l);
    addEdgeLinesEntities(ge,linesEntities);
  }
  for(GFace *gf: f)
    addFaceTriangles(gf, t);
}

static void getFaceLinesAndTriangles(GFace *gf, std::set<MLine *, MLinePtrLessThan> &l,std::set<MTriangle *, MElementPtrLessThan> &t){
  if(l.size()>0){
    Msg::Warning("Lines set not empty. Clearing it.");
    l.clear();
  }
  if(t.size()>0){
    Msg::Warning("Triangles set not empty. Clearing it");
    t.clear();
  }
  for(GEdge* ge: gf->edges())
    addEdgeLines(ge, l);
  for(GEdge* ge: gf->embeddedEdges())
    addEdgeLines(ge, l);
  addFaceTriangles(gf, t);
}

void liftEulerAngles(std::vector<SVector3> &vectEulerAngles){
  SVector3 &eulerRef = vectEulerAngles[0];
  //DBG solve periodicity here
  for(size_t k=1;k<vectEulerAngles.size();k++){
    SVector3 &euler = vectEulerAngles[k];
    for(int i=0;i<3;i++){
      if(fabs(euler[i]-2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
	euler[i]=euler[i]-2*M_PI;
      if(fabs(euler[i]+2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
	euler[i]=euler[i]+2*M_PI;
    }
  }
  //DBG solve non unicity here
  for(size_t k=1;k<vectEulerAngles.size();k++){
    SVector3 &euler = vectEulerAngles[k];
    if(fabs(euler[0]-M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      /* printf("case 1\n"); */
      euler[0]=euler[0]-M_PI;
      euler[2]=euler[2]-M_PI;
      euler[1]=-euler[1];
      if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[1]=2*M_PI+euler[1];
      }
      if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[1]=-2*M_PI+euler[1];
      }
      if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
	euler[2]=2*M_PI+euler[2];
      }
      if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[2]=-2*M_PI+euler[2];
      }
    }
    if(fabs(euler[0]+M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      /* printf("case 2\n"); */
      euler[0]=euler[0]+M_PI;
      euler[2]=euler[2]-M_PI;
      euler[1]=-euler[1];
      if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[1]=2*M_PI+euler[1];
      }
      if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[1]=-2*M_PI+euler[1];
      }
      if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
	euler[2]=2*M_PI+euler[2];
      }
      if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
	euler[2]=-2*M_PI+euler[2];
      }
    }
  }
  return;
}

void directionsToEulerAngle(const std::vector<SVector3> &dir, SVector3 &eulerAngles, double &flagNotUnique){
  SVector3 u=dir[0];
  SVector3 v=dir[1];
  SVector3 w=dir[2];
  
  double psi=0.0;
  double theta=0.0;
  double phi=0.0;

  int flagNoNutation=1;
  double sign=0.0;
  double phiPlusPsi=0.0;
  if(fabs(w[2])<cos(1.*M_PI/180.0)) // if theta>M_PI-1deg or theta<1deg, snapped to M_PI or 0.
    flagNoNutation=0.;

  if(flagNoNutation){
    if(w[2]<0){
      theta=M_PI;
      sign=-1.0;
    }
    else{
      theta=0;
      sign=1.0;
    }
    psi=0.0;
    phiPlusPsi=atan2(-v[0],u[0]);
    phi=phiPlusPsi;
    eulerAngles[0]=psi;
    eulerAngles[1]=theta;
    eulerAngles[2]=phi;
  }
  else{
    psi = atan2(w[0],-w[1]);
    phi = atan2(u[2],v[2]);
    if(fabs(cos(phi))>0.01)
      theta=atan2(v[2]/cos(phi),w[2]);
    else
      theta=atan2(u[2]/sin(phi),w[2]);
    eulerAngles[0]=psi;
    eulerAngles[1]=theta;
    eulerAngles[2]=phi;
  }
  flagNotUnique=sign;
  return;
}

void Cross2D::_computeDirections(){
  if(edge){
    _directions.clear();
    SVector3 eDir(edge->getVertex(1)->x() - edge->getVertex(0)->x(),
		  edge->getVertex(1)->y() - edge->getVertex(0)->y(),
		  edge->getVertex(1)->z() - edge->getVertex(0)->z());
    eDir.normalize();
    SVector3 normal=_mesh->normals[edge];
    normal.normalize();
    SVector3 t=crossprod(normal,eDir);
    SVector3 U = cos(theta)*eDir + sin(theta)*t;
    U.normalize();
    SVector3 V = -sin(theta)*eDir + cos(theta)*t;
    V.normalize();
    _directions.push_back(U);
    _directions.push_back(V);
    _directions.push_back(normal);
  }
  return;
}

SVector3 Cross2D::getClosestBranchToDirection(SVector3 dir){
  dir.normalize();
  SVector3 closestDir(0.0);
  double maxPS=-2.;
  for(size_t k=0; k<2; k++){
    SVector3 branche = getDirection(k);
    if(dot(branche,dir)>maxPS){
      maxPS=dot(branche,dir);
      closestDir=branche;
    }
    if(dot(-branche,dir)>maxPS){
      maxPS=dot(-branche,dir);
      closestDir=-branche;
    }
  }
  return closestDir;
}

  //Warning !! No periodicity or lock problems are solved in this function. It is not needed because of characteristics of problem data and a well chosen reference base.
  //If this function is needed in a different context, euler angles of each node at each node of the triangle have to be post treated in order to remove periodicity, lock, and non unicity of the representation
SVector3 Cross2D::getEulerAngles(double &noNutation){
  if(_directions.size()!=3){
    _directions.clear();
    _computeDirections();
  }
  SVector3 eulerAngles;
  directionsToEulerAngle(_directions, eulerAngles, noNutation);
  return eulerAngles;
}

SVector3 Cross2D::getEulerAngles(std::vector<SVector3> baseRef, double &noNutation){
  if(_directions.size()!=3){
    _directions.clear();
    _computeDirections();
  }
  SVector3 eulerAngles;
  fullMatrix<double> directionsFM(3,3);
  fullMatrix<double> rotDirectionsFM(3,3);
  fullMatrix<double> baseRefFM(3,3);
  for(size_t k=0;k<3;k++)
    baseRef[k].normalize();
  for(size_t k=0;k<3;k++)
    for(size_t l=0;l<3;l++){
      directionsFM(k,l)=_directions[l][k];
      baseRefFM(k,l)=baseRef[l][k];
    }
  baseRefFM.transposeInPlace();
  baseRefFM.mult(directionsFM,rotDirectionsFM);
  std::vector<SVector3> rotDir;
  SVector3 init;
  for(size_t k=0;k<3;k++)
    rotDir.push_back(init);
  for(size_t k=0;k<3;k++)
    for(size_t l=0;l<3;l++)
      rotDir[k][l]=rotDirectionsFM(l,k);
  directionsToEulerAngle(rotDir, eulerAngles, noNutation);
  return eulerAngles;
}

std::vector<SVector3> Cross2D::getDirFromEulerAngles(const SVector3 &eulerAngles){
  std::vector<SVector3> dir(3,SVector3(0.0));
  double c1 = cos(eulerAngles[0]);
  double s1 = sin(eulerAngles[0]);
  double c2 = cos(eulerAngles[1]);
  double s2 = sin(eulerAngles[1]);
  double c3 = cos(eulerAngles[2]);
  double s3 = sin(eulerAngles[2]);
  dir[0][0] = c1*c3-c2*s1*s3;
  dir[0][1] = c2*c1*s3+c3*s1;
  dir[0][2] = s3*s2;
  
  dir[1][0] = -c1*s3-c3*c2*s1;
  dir[1][1] = c1*c2*c3-s1*s3;
  dir[1][2] = c3*s2;

  dir[2][0] = s2*s1;
  dir[2][1] = -c1*s2;
  dir[2][2] = c2;
  
  return dir;
}

std::vector<SVector3> Cross2D::getDirFromEulerAngles(std::vector<SVector3> baseRef, const SVector3 &eulerAngles){
  fullMatrix<double> dirFM(3,3);
  double c1 = cos(eulerAngles[0]);
  double s1 = sin(eulerAngles[0]);
  double c2 = cos(eulerAngles[1]);
  double s2 = sin(eulerAngles[1]);
  double c3 = cos(eulerAngles[2]);
  double s3 = sin(eulerAngles[2]);
  dirFM(0,0) = c1*c3-c2*s1*s3;
  dirFM(0,1) = c2*c1*s3+c3*s1;
  dirFM(0,2) = s3*s2;
  
  dirFM(1,0) = -c1*s3-c3*c2*s1;
  dirFM(1,1) = c1*c2*c3-s1*s3;
  dirFM(1,2) = c3*s2;

  dirFM(2,0) = s2*s1;
  dirFM(2,1) = -c1*s2;
  dirFM(2,2) = c2;
  dirFM.transposeInPlace();
  fullMatrix<double> baseRefFM(3,3);
  for(size_t k=0;k<3;k++)
    baseRef[k].normalize();
  for(size_t k=0;k<3;k++)
    for(size_t l=0;l<3;l++)
      baseRefFM(k,l)=baseRef[l][k];
  fullMatrix<double> rotDirectionsFM(3,3);
  baseRefFM.mult(dirFM,rotDirectionsFM);
  std::vector<SVector3> dir(3,SVector3(0.0));
  for(size_t k=0;k<3;k++)
    for(size_t l=0;l<3;l++)
      dir[k][l]=rotDirectionsFM(l,k);
  return dir;
}

MyMesh::MyMesh(GModel *gm){
  getAllLinesAndTriangles(gm, lines, linesEntities, triangles);
  for(MTriangle *t: triangles){
    SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
		 t->getVertex(1)->y() - t->getVertex(0)->y(),
		 t->getVertex(1)->z() - t->getVertex(0)->z());
    SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
		 t->getVertex(2)->y() - t->getVertex(0)->y(),
		 t->getVertex(2)->z() - t->getVertex(0)->z());
    SVector3 normal_to_triangle = crossprod(v10, v20);
    normal_to_triangle.normalize();
    for(int k=0;k<3;k++){
      MEdge edgeK=t->getEdge(k);
      std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
      insertData=edges.insert(edgeK);
      triangleToEdges[t].push_back(&(*insertData.first));
      edgeToTriangles[&(*insertData.first)].push_back(t);
      normals[&(*insertData.first)]+=normal_to_triangle;
      isFeatureEdge[&(*insertData.first)]=false;
      MVertex *vK=t->getVertex(k);
      normalsVertex[vK]+=normal_to_triangle;
      vertexToTriangles[vK].insert(t);
    }
  }
  for(std::map<const MEdge *, SVector3>::value_type& kv: normals)
    kv.second.normalize();
  for(std::map<MVertex *, SVector3>::value_type& kv: normalsVertex)
    kv.second.normalize();
  
  for(MLine *l: lines){
    std::set<MEdge, MEdgeLessThan>::iterator it=edges.find(l->getEdge(0));
    if(it==edges.end()){
      Msg::Error("Cannot find feature edge in mesh edges");
      return;
    }
    else{
      featureDiscreteEdges.insert(&(*it));
      isFeatureEdge[&(*it)]=true;
      featureDiscreteEdgesEntities[&(*it)]=linesEntities[l];
    }
  }
  for(const MEdge *e: featureDiscreteEdges){
    featureVertices.insert(e->getVertex(0));
    featureVertices.insert(e->getVertex(1));
    featureVertexToEdges[e->getVertex(0)].insert(e);
    featureVertexToEdges[e->getVertex(1)].insert(e);
  }
  getSingularities(gm);
}

void MyMesh::getSingularities(GModel *gm){
  std::map<int, std::vector<GEntity *> > groups[4];
  gm->getPhysicalGroups(groups);
  for(std::map<int, std::vector<GEntity *> >::iterator it = groups[0].begin();
      it != groups[0].end(); ++it) {
    std::string name = gm->getPhysicalName(0, it->first);
    if(name == "SINGULARITY_OF_INDEX_THREE") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty()){
	  singularities.insert(it->second[j]->mesh_vertices[0]);
	  singIndices[it->second[j]->mesh_vertices[0]] = 1;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_FIVE") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty()){
	  singularities.insert(it->second[j]->mesh_vertices[0]);
	  singIndices[it->second[j]->mesh_vertices[0]] = -1;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_SIX") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty()){
	  singularities.insert(it->second[j]->mesh_vertices[0]);
	  singIndices[it->second[j]->mesh_vertices[0]] = -2;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_EIGHT") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty()){
	  singularities.insert(it->second[j]->mesh_vertices[0]);
	  singIndices[it->second[j]->mesh_vertices[0]] = -4;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_TWO") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty()){
	  singularities.insert(it->second[j]->mesh_vertices[0]);
	  singIndices[it->second[j]->mesh_vertices[0]] = 2;
	}
      }
    }
  }
  return;
}

MyMesh::MyMesh(MyMesh &originalMesh){
  for(MTriangle *t: originalMesh.triangles){
    triangles.insert(t);
  }
  for(MLine *l: originalMesh.lines){
    lines.insert(l);
  }
  for(auto &kv: originalMesh.linesEntities){
    linesEntities[kv.first]=kv.second;
  }
  for(MTriangle *t: triangles)
    for(int k=0;k<3;k++){
      MEdge edgeK=t->getEdge(k);
      std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
      insertData=edges.insert(edgeK);
      triangleToEdges[t].push_back(&(*insertData.first));
      edgeToTriangles[&(*insertData.first)].push_back(t);
      isFeatureEdge[&(*insertData.first)]=false;
      MVertex *vK=t->getVertex(k);
      vertexToTriangles[vK].insert(t);
    }
  for(MLine *l: lines){
    std::set<MEdge, MEdgeLessThan>::iterator it=edges.find(l->getEdge(0));
    if(it==edges.end()){
      Msg::Error("Cannot find feature edge in mesh edges");
      return;
    }
    else{
      featureDiscreteEdges.insert(&(*it));
      featureDiscreteEdgesEntities[&(*it)]=linesEntities[l];
      isFeatureEdge[&(*it)]=true;
    }
  }
  for(const MEdge *e: featureDiscreteEdges){
    featureVertices.insert(e->getVertex(0));
    featureVertices.insert(e->getVertex(1));
    featureVertexToEdges[e->getVertex(0)].insert(e);
    featureVertexToEdges[e->getVertex(1)].insert(e);
  }
  //TODO need smart gestion of singularities (everything can change when cutting
  for(MVertex *v:originalMesh.singularities){
    singularities.insert(v);
    singIndices[v]=originalMesh.singIndices[v];
  }
}

void MyMesh::updateNormals(){
  normals.clear();
  normalsVertex.clear();
  for(MTriangle *t: triangles){
    SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
		 t->getVertex(1)->y() - t->getVertex(0)->y(),
		 t->getVertex(1)->z() - t->getVertex(0)->z());
    SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
		 t->getVertex(2)->y() - t->getVertex(0)->y(),
		 t->getVertex(2)->z() - t->getVertex(0)->z());
    SVector3 normal_to_triangle = crossprod(v10, v20);
    normal_to_triangle.normalize();
    for(int k=0;k<3;k++){
      MEdge edgeK=t->getEdge(k);
      std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
      insertData=edges.insert(edgeK);
      if(insertData.second){
	Msg::Error("Reached an edge not listed while updating normals");
	return;
      }
      normals[&(*insertData.first)]+=normal_to_triangle;
      MVertex *vK=t->getVertex(k);
      normalsVertex[vK]+=normal_to_triangle;
    }
  }
  for(std::map<const MEdge *, SVector3>::value_type& kv: normals)
    kv.second.normalize();
  for(std::map<MVertex *, SVector3>::value_type& kv: normalsVertex)
    kv.second.normalize();
}

void MyMesh::updateEdgesAndVertexToTri(){
  triangleToEdges.clear();
  for(MTriangle *t: triangles)
    for(int k=0;k<3;k++){
      MEdge edgeK=t->getEdge(k);
      std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
      insertData=edges.insert(edgeK);
      triangleToEdges[t].push_back(&(*insertData.first));
      edgeToTriangles[&(*insertData.first)].push_back(t);
      if(insertData.second)
	isFeatureEdge[&(*insertData.first)]=false;
      MVertex *vK=t->getVertex(k);
      vertexToTriangles[vK].insert(t);
    }
}

void MyMesh::_computeDarbouxFrameOnFeatureVertices(){ //darboux frame with geodesic normal poiting inside the domain
  MVertexPtrEqual isVertTheSame;
  MEdgeEqual isEdgeTheSame;
  if(normals.size()==0||normalsVertex.size()==0)
    updateNormals();
  for(MVertex *v: featureVertices){
    if(featureVertexToEdges[v].size()!=2){
      Msg::Error("Can't run darboux frame on a mesh not splitted along feature edges");
      return;
    }

    std::set<const MEdge *>::iterator itSetEdge=featureVertexToEdges[v].begin();
    const MEdge *e1=*(itSetEdge);
    itSetEdge++;
    const MEdge *e2=*(itSetEdge);
    MVertex *v1=e1->getVertex(0);
    if(isVertTheSame(v1,v))
      v1=e1->getVertex(1);
    MVertex *v2=e2->getVertex(0);
    if(isVertTheSame(v2,v))
      v2=e2->getVertex(1);
    SVector3 v01(v1->x() - v->x(),
		 v1->y() - v->y(),
		 v1->z() - v->z());
    v01.normalize();
    SVector3 v02(v2->x() - v->x(),
		 v2->y() - v->y(),
		 v2->z() - v->z());
    v02.normalize();
    SVector3 normalV = normalsVertex[v];
    normalV.normalize();
    SVector3 t01 = crossprod(normalV, v01);
    t01.normalize();
    double cosV02=dot(v02,v01);
    double sinV02=dot(v02,t01);
    if(edgeToTriangles[e1].size()!=1){
      Msg::Error("Can't run darboux frame on a mesh not splitted along feature edges");
      return;
    }
    MTriangle *tri = *(edgeToTriangles[e1].begin());
    const MEdge *eRef=NULL;	
    for(const MEdge* eT: triangleToEdges[tri]){
      if(!isEdgeTheSame(*eT,*e1)){
	if(isVertTheSame(eT->getVertex(0),v)||isVertTheSame(eT->getVertex(1),v)){
	  eRef=eT;
	}
      }
    }
    if(eRef==NULL){
      Msg::Error("Can't run darboux frame. Not finding reference edge for orientability");
      return;      
    }
    MVertex *vRef=eRef->getVertex(0);
    if(isVertTheSame(vRef,v))
      vRef=eRef->getVertex(1);
    SVector3 vectRef(vRef->x() - v->x(),
		     vRef->y() - v->y(),
		     vRef->z() - v->z());
    vectRef.normalize();
    double cosRef=dot(vectRef,v01);;
    double sinRef=dot(vectRef,t01);
    double angleRef=atan2(sinRef,cosRef);
    double angleV02=atan2(sinV02,cosV02);
    if(angleRef>0){
      if(angleV02<=0+1e-10)
	angleV02+=2*M_PI;
    }
    else
      if(angleV02>=0-1e-10)
	angleV02-=2*M_PI;
	
    double angleInnerGeodesicNormal=angleV02/2.0;
    SVector3 innerGeodesicNormal = cos(angleInnerGeodesicNormal)*v01 + sin(angleInnerGeodesicNormal)*t01;
    innerGeodesicNormal.normalize();
    SVector3 T = crossprod(innerGeodesicNormal, normalV);
    T.normalize();
    _darbouxFrameVertices[v].push_back(T);
    _darbouxFrameVertices[v].push_back(innerGeodesicNormal);
    _darbouxFrameVertices[v].push_back(normalV);
  }
  return;
}

void MyMesh::_computeGaussCurv(){
  MVertexPtrEqual isVertTheSame;
  std::map<MVertex *, double, MVertexPtrLessThan> angleRef;
  std::map<MVertex *, double, MVertexPtrLessThan> patchArea;
  std::map<MVertex *, double, MVertexPtrLessThan> cotanL;
  std::map<MVertex *, double, MVertexPtrLessThan> weight;
  std::map<MVertex *, double, MVertexPtrLessThan> patchLength;
  for(MTriangle *t: triangles){
    for(int k=0; k<3; k++){
      MVertex *v=t->getVertex(k);
      MEdge e1=t->getEdge(k);
      MEdge e2=t->getEdge((k-1+3)%3);
      MVertex *v1=e1.getVertex(0);
      if(isVertTheSame(v1,v))
	v1=e1.getVertex(1);
      MVertex *v2=e2.getVertex(0);
      if(isVertTheSame(v2,v))
	v2=e2.getVertex(1);
      if(!isVertTheSame(e1.getVertex(0),v)&&!isVertTheSame(e1.getVertex(1),v)){
	Msg::Error("Ups.");
	return;
      }
      if(!isVertTheSame(e2.getVertex(0),v)&&!isVertTheSame(e2.getVertex(1),v)){
	Msg::Error("Ups.");
	return;
      }
      SVector3 v01(v1->x() - v->x(),
		   v1->y() - v->y(),
		   v1->z() - v->z());
      v01.normalize();
      SVector3 v02(v2->x() - v->x(),
		   v2->y() - v->y(),
		   v2->z() - v->z());
      v02.normalize();
      double angle = acos(dot(v01,v02));
      gaussCurv[v]+=angle;
      patchArea[v]+=t->getVolume();
      cotanL[v]+=t->getEdge((k+1)%3).length()*t->getEdge((k+1)%3).length()/tan(angle);
      angleRef[v]=2*M_PI;
    }
  }
  for(MTriangle *t: triangles){
    for(int k=0; k<3; k++){
      MVertex *v=t->getVertex(k);
      weight[v]=(patchArea[v]/2.-cotanL[v]/8.);
    }
  }
  for(MVertex *v: featureVertices){
    if(featureVertexToEdges[v].size()!=2){
      Msg::Error("Can't compute Gaussian curvature on non manifold surface, or on manifold with feature lines. Consider splitting geometry along feature lines.");
      return;
    }
    std::set<const MEdge *>::iterator itEdges=featureVertexToEdges[v].begin();
    const MEdge *e1=*(itEdges);
    itEdges++;
    const MEdge *e2=*(itEdges);
    MVertex *v1=e1->getVertex(0);
    if(isVertTheSame(v1,v))
      v1=e1->getVertex(1);
    MVertex *v2=e2->getVertex(0);
    if(isVertTheSame(v2,v))
      v2=e2->getVertex(1);
    SVector3 v10(v->x() - v1->x(),
		 v->y() - v1->y(),
		 v->z() - v1->z());
    v10.normalize();
    SVector3 v02(v2->x() - v->x(),
		 v2->y() - v->y(),
		 v2->z() - v->z());
    v02.normalize();
    std::vector<SVector3> darbouxVertex=_darbouxFrameVertices[v];
    if(darbouxVertex.size()!=3){
      Msg::Error("Can't compute Gaussian curvature on boundary. A darboux frame is not defined");
      return;
    }
    SVector3 yBase(0.0,1.0,0.0);
    SVector3 normalTest = darbouxVertex[2];
    // SVector3 normalTest = darbouxVertex[2] - dot(yBase,darbouxVertex[2])*yBase;
    // normalTest.normalize();
    SVector3 v10Proj = v10 - dot(v10,normalTest)*normalTest;
    v10Proj.normalize();
    SVector3 v02Proj = v02 - dot(v02,normalTest)*normalTest;
    v02Proj.normalize();
    double cosAngleTang=dot(v10Proj,v02Proj);
    if(cosAngleTang>1.)
      cosAngleTang=1.;
    if(cosAngleTang<-1.)
      cosAngleTang=-1.;
    double angleTan=acos(cosAngleTang);
    double sign=0.0;
    double angleGeo=angleTan;
    if(dot(v02Proj,darbouxVertex[1])>0){//convexe
      sign=1.0;
    }
    else{//concave
      sign=-1.0;
    }
    angleTan=M_PI-sign*angleTan;
    angleRef[v]=angleTan;
    weight[v]=patchArea[v]/3.;
    //Geodesic curvature
    patchLength[v]=(e1->length()+e2->length());
    // geodesicCurv[v]=sign*angleGeo/(0.5*(e1->length()+e2->length()));
    geodesicCurv[v]=sign*angleGeo; //Storing this because already integrated
  }
  //gauss curvature
  for(auto &kv: gaussCurv){
    double value=kv.second;
    kv.second = (angleRef[kv.first]-value); //Storing this because already integrated
    // kv.second = (angleRef[kv.first]-value)/(patchArea[kv.first]/3.); //Less precise value of Gauss curvature, but consistent with linear FEM and Gauss Bonnet
    
    // kv.second = (angleRef[kv.first]-value)/(patchArea[kv.first]/2.-cotanL[kv.first]/8.); //more accurate. Have to check if it's consistant with gauss theorem and FE discretization
    // kv.second = (angleRef[kv.first]-value)/weight[kv.first];
  }
  //Check that all curvatures matches
  double intGauss=0.0;
  double intGeodesic=0.0;
  for(const auto &kv: gaussCurv){
    intGauss+=kv.second;
    intGeodesic+=geodesicCurv[kv.first];
  }
  std::cout << "value check : " << (intGauss+intGeodesic)/(2*M_PI) << std::endl;
  double sum=0;
  for(const auto &kv: singIndices){
    sum+=(double)kv.second/4.;
  }
  std::cout << "sum sing : " << sum << std::endl;
  return;
}

void MyMesh::createPatchs(){
  trianglesPatchs.clear();
  std::map<MTriangle *, bool, MElementPtrLessThan> trianglePassed;
  std::stack<MTriangle *> stackTri;
  for(MTriangle *t: triangles)
    trianglePassed[t]=false;
  MTriangle *triangleLeft=NULL;
  for(auto &kv: trianglePassed){
    if(!kv.second){
      triangleLeft=kv.first;
      break;
    }
  }
  trianglePassed[triangleLeft]=true;
  std::set<MTriangle *, MElementPtrLessThan> setPatchTri;
  setPatchTri.insert(triangleLeft);
  while(triangleLeft){
    for(const MEdge *e: triangleToEdges[triangleLeft]){
      if(!isFeatureEdge[e]){
	for(MTriangle *t: edgeToTriangles[e]){
	  if(!trianglePassed[t]){
	    stackTri.push(t);
	    trianglePassed[t]=true;
	    setPatchTri.insert(t);
	  }
	}
      }
    }
    if(!stackTri.empty()){
      triangleLeft = stackTri.top();
      stackTri.pop();
    }
    else{
      trianglesPatchs.push_back(setPatchTri);
      setPatchTri.clear();
      triangleLeft=NULL;
      for(auto &kv: trianglePassed){
	if(!kv.second){
	  triangleLeft=kv.first;
	  trianglePassed[triangleLeft]=true;
	  setPatchTri.insert(triangleLeft);
	  break;
	}
      }
    }
  }
  return;
}
double MyMesh::_getAngleBetweenEdges(const MEdge &e,const MEdge &eRef, SVector3 &normal){
  SVector3 vRef(eRef.getVertex(1)->x() - eRef.getVertex(0)->x(),
		eRef.getVertex(1)->y() - eRef.getVertex(0)->y(),
		eRef.getVertex(1)->z() - eRef.getVertex(0)->z());
  vRef.normalize();
  SVector3 v(e.getVertex(1)->x() - e.getVertex(0)->x(),
	     e.getVertex(1)->y() - e.getVertex(0)->y(),
	     e.getVertex(1)->z() - e.getVertex(0)->z());
  v.normalize();
  SVector3 t=crossprod(normal,vRef);
  t.normalize();
  double cos=dot(v,vRef);
  double sin=dot(v,t);
  return atan2(sin,cos);
}

void MyMesh::computeManifoldBasis(){
  if(trianglesPatchs.size()==0)
    createPatchs();
  std::map<const MEdge *, double> theta;
  for(size_t kP=0;kP<trianglesPatchs.size();kP++){
    std::set<MTriangle*, MElementPtrLessThan> tri = trianglesPatchs[kP];
    //grabbing edges we are interested in
    std::map<const MEdge *, size_t> idEdge;
    size_t id=0;
    for(MTriangle *t: tri){
      for(int k=0;k<3;k++){
	const MEdge *eK = triangleToEdges[t][k];
	if(idEdge.find(eK)==idEdge.end()){
	  idEdge[eK]=id;
	  id++;
	}
      }
    } 
    //fill _currentMesh->manifoldBasis
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
    printf("petsc solver\n");
#elif defined(HAVE_MUMPS)
    linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
    printf("mmups solver\n");
#else
    linearSystemFull<double> *_lsys = new linearSystemFull<double>;
    printf("default solver\n");
#endif
#endif
    dofManager<double> *dof = new dofManager<double>(_lsys);
    std::set<const MEdge*> dbgEdgeBC;
    dbgEdgeBC.insert(triangleToEdges[*(tri.begin())][0]);
    // ConformalMapping::_viewEdges(dbgEdgeBC,"edgeBC");
    Dof E0(idEdge[*(dbgEdgeBC.begin())], Dof::createTypeWithTwoInts(0, 1));
    Dof E02(idEdge[*(dbgEdgeBC.begin())], Dof::createTypeWithTwoInts(1, 1));
    dof->fixDof(E0,1.0);dof->fixDof(E02,0.0);
    
    size_t nEdgesId=0;
    for(const auto &kv: idEdge){
      //numberdof here
      Dof EdgeDof(kv.second, Dof::createTypeWithTwoInts(0, 1));
      Dof EdgeDof2(kv.second, Dof::createTypeWithTwoInts(1, 1));
      dof->numberDof(EdgeDof);dof->numberDof(EdgeDof2);
      nEdgesId++;
    }    
    Msg::Info("Manifold base system, 2*%i unknowns...",idEdge.size());
    Msg::Info(" ",idEdge.size());
    for(MTriangle *t: tri){
      double V = t->getVolume();
      SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
		   t->getVertex(1)->y() - t->getVertex(0)->y(),
		   t->getVertex(1)->z() - t->getVertex(0)->z());
      SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
		   t->getVertex(2)->y() - t->getVertex(0)->y(),
		   t->getVertex(2)->z() - t->getVertex(0)->z());
      SVector3 tNormal = crossprod(v10, v20);
      tNormal.normalize();
      double g1[3], g2[3], g3[3];
      double a[3];
      a[0] = 1;
      a[1] = 0;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      a[0] = 0;
      a[1] = 1;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g2);
      a[0] = 0;
      a[1] = 0;
      a[2] = 1;
      t->interpolateGrad(a, 0, 0, 0, g3);
      SVector3 G[3];
      G[0] = SVector3(g1[0] + g2[0] - g3[0], g1[1] + g2[1] - g3[1],
		      g1[2] + g2[2] - g3[2]);
      G[1] = SVector3(g2[0] + g3[0] - g1[0], g2[1] + g3[1] - g1[1],
		      g2[2] + g3[2] - g1[2]);
      G[2] = SVector3(g1[0] + g3[0] - g2[0], g1[1] + g3[1] - g2[1],
		      g1[2] + g3[2] - g2[2]);
      
      fullMatrix<double> Kelem(6, 6);
      for(size_t k=0;k<3;k++)
	for(size_t l=0;l<3;l++){
	  Kelem(k,l)+=dot(G[k],G[l])*V;
	  Kelem(k+3,l+3)+=dot(G[k],G[l])*V;
	}
      double alphaEdge[3]={0.0};
      MEdge edgeRef = t->getEdge(0);
      size_t localId=0;
      for(size_t k=0;k<3;k++){
	alphaEdge[localId]=-_getAngleBetweenEdges(*(triangleToEdges[t][k]),edgeRef,tNormal);
	localId++;
      }
      fullMatrix<double> localEdgeRot(6, 6);
      localEdgeRot(0,0)=localEdgeRot(3,3)=cos(alphaEdge[0]);
      localEdgeRot(1,1)=localEdgeRot(4,4)=cos(alphaEdge[1]);
      localEdgeRot(2,2)=localEdgeRot(5,5)=cos(alphaEdge[2]);
      localEdgeRot(0,3)=sin(alphaEdge[0]);localEdgeRot(1,4)=sin(alphaEdge[1]);localEdgeRot(2,5)=sin(alphaEdge[2]);
      localEdgeRot(3,0)=-sin(alphaEdge[0]);localEdgeRot(4,1)=-sin(alphaEdge[1]);localEdgeRot(5,2)=-sin(alphaEdge[2]);
      fullMatrix<double> KR(6, 6);
      fullMatrix<double> RtKR(6, 6);
      Kelem.mult(localEdgeRot,KR);
      localEdgeRot.transposeInPlace();
      localEdgeRot.mult(KR,RtKR);

      for(size_t kE=0; kE<3; kE++){
	for(size_t lE=0; lE<3; lE++){
	  for(size_t iF=0; iF<2; iF++){
	    for(size_t jF=0; jF<2; jF++){
	      Dof Ek(idEdge[triangleToEdges[t][kE]], Dof::createTypeWithTwoInts(iF, 1));
	      Dof El(idEdge[triangleToEdges[t][lE]], Dof::createTypeWithTwoInts(jF, 1));
	      dof->assemble(Ek, El, RtKR(iF*3+kE,jF*3+lE));
	    }
	  }
	}
      }
    }
    std::cout << "solving manifold base system for 2*" << idEdge.size() << " unknowns..." << std::endl;
    _lsys->systemSolve();
    for(const auto &kv: idEdge){
      double valueCos=0.0;
      double valueSin=0.0;
      Dof c(kv.second, Dof::createTypeWithTwoInts(0, 1));
      Dof s(kv.second, Dof::createTypeWithTwoInts(1, 1));
      dof->getDofValue(c, valueCos);
      dof->getDofValue(s, valueSin);
      SVector3 vect(valueCos,valueSin,0);
      if(vect.norm()<1e-12){
	Msg::Warning("it seems manifold basis computation failed, keep going anyway.");
	theta[kv.first]=atan2(vect[1],vect[0]);
      }
      else{
	theta[kv.first]=atan2(vect[1],vect[0]);
      }
    }
    delete _lsys;
    delete dof;
  }
  for(const MEdge &e: edges){
    manifoldBasis[&e]=Cross2D(this,&e,theta[&e]);
  }
  ConformalMapping::_viewScalarEdges(theta,"theta"); //DBG
  return;
}

// void MyMesh::computeManifoldBasis(){
//   createPatchs();
//   std::map<const MEdge *, double> theta;
//   for(const MEdge &e: edges){
//     theta[&e]=-10000;
//   }
//   size_t countP=0;//DBG
//   for(size_t k=0;k<trianglesPatchs.size();k++){
//     std::cout << "patch : " << countP << std::endl;//DBG
//     std::cout << "nTri : " << trianglesPatchs[k].size() << std::endl;//DBG
//     // std::set<MTriangle*, MElementPtrLessThan> tri = trianglesPatchs[k];
//     // std::set<MTriangle*, MElementPtrLessThan> tri;
//     // tri.insert(*(trianglesPatchs[k].begin()));
//     // MTriangle *newT=edgeToTriangles[triangleToEdges[*(trianglesPatchs[k].begin())][0]][1];
//     // tri.insert(newT);
//     // tri.insert(edgeToTriangles[triangleToEdges[*(trianglesPatchs[k].begin())][1]][1]);
//     // tri.insert(edgeToTriangles[triangleToEdges[*(trianglesPatchs[k].begin())][2]][1]);
//     // tri.insert(edgeToTriangles[triangleToEdges[newT][0]][0]);
//     // tri.insert(edgeToTriangles[triangleToEdges[newT][1]][1]);
//     // tri.insert(edgeToTriangles[triangleToEdges[newT][2]][0]);
//     std::set<MTriangle*, MElementPtrLessThan> tri;
//     MTriangle *triBC=NULL;
//     for(MTriangle *t: triangles){
//       if(t->getNum()==31)
// 	triBC=t;
//       // if(t->getNum()==15||t->getNum()==17||t->getNum()==47||t->getNum()==20||t->getNum()==21||t->getNum()==25||t->getNum()==38||t->getNum()==32||t->getNum()==45||t->getNum()==39||t->getNum()==26||t->getNum()==42||t->getNum()==43||t->getNum()==44||t->getNum()==31)//adding 31 fuck everything up...
// 	// if(t->getNum()==15||t->getNum()==17||t->getNum()==47||t->getNum()==20||t->getNum()==21||t->getNum()==25||t->getNum()==38||t->getNum()==32||t->getNum()==45||t->getNum()==39||t->getNum()==26||t->getNum()==42||t->getNum()==43)//adding 31 fuck everything up...
// 	// if(t->getNum()==31)
//       if(t->getNum()==31||t->getNum()==42||t->getNum()==43||t->getNum()==44)
//       // if(!(t->getNum()==31)&&!(t->getNum()==43)&&!(t->getNum()==42)&&!(t->getNum()==44))
// 	tri.insert(t);
//     }
//     //grabbing vertices we are interested in
//     std::map<const MEdge *, size_t> idEdge;
//     std::set<MVertex *, MVertexPtrLessThan> vertices;
//     size_t id=0;
//     std::cout << "iding edges " << std::endl;//DBG
//     for(MTriangle *t: tri){
//       for(int k=0;k<3;k++){
// 	const MEdge *eK = triangleToEdges[t][k];
// 	if(idEdge.find(eK)==idEdge.end()){
// 	  idEdge[eK]=id;
// 	  id++;
// 	}
//       }
//     } 
//     //fill _currentMesh->manifoldBasis
// #if defined(HAVE_SOLVER)
// #if defined(HAVE_PETSC)
//     linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
//     printf("petsc solver\n");
// #elif defined(HAVE_MUMPS)
//     linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
//     printf("mmups solver\n");
// #else
//     linearSystemFull<double> *_lsys = new linearSystemFull<double>;
//     printf("default solver\n");
// #endif
// #endif
//     dofManager<double> *dof = new dofManager<double>(_lsys);
//     //Temporary numbering for average
//     // Dof EdgeBC(nEdgesId+1, Dof::createTypeWithTwoInts(0, 1));
//     // dof->numberDof(EdgeBC);
//     //temporary : BC 0 on first edge
//     // Dof E0((idEdge.begin())->second, Dof::createTypeWithTwoInts(0, 1));
//     std::set<const MEdge*> dbgEdgeBC;
//     dbgEdgeBC.insert(triangleToEdges[triBC][0]);
//     ConformalMapping::_viewEdges(dbgEdgeBC,"edgeBC");
//     Dof E0(idEdge[triangleToEdges[triBC][0]], Dof::createTypeWithTwoInts(0, 1));
//     // dof->assembleSym(EdgeBC, E0, 1);
//     dof->fixDof(E0,0.0);
    
//     std::cout << "numbering edges " << std::endl;//DBG
//     size_t nEdgesId=0;
//     for(const auto &kv: idEdge){
//       //numberdof here
//       std::cout << "numbering dof : " << kv.second << std::endl;
//       Dof EdgeDof(kv.second, Dof::createTypeWithTwoInts(0, 1));
//       dof->numberDof(EdgeDof);
//       nEdgesId++;
//     }

    
//     size_t counT=0;//DBG
//     for(MTriangle *t: tri){
//       std::cout << "************ triangle : " << counT << std::endl;//DBG
//       std::cout << "************ tri num  : " << t->getNum() << std::endl;//DBG
//       double V = t->getVolume();
//       std::cout << "volume : " << V << std::endl;
//       SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
// 		   t->getVertex(1)->y() - t->getVertex(0)->y(),
// 		   t->getVertex(1)->z() - t->getVertex(0)->z());
//       SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
// 		   t->getVertex(2)->y() - t->getVertex(0)->y(),
// 		   t->getVertex(2)->z() - t->getVertex(0)->z());
//       SVector3 tNormal = crossprod(v10, v20);
//       tNormal.normalize();
//       if(t->getNum()==31||t->getNum()==42||t->getNum()==43||t->getNum()==44)
// 	std::cout << "normal tri 31 : " << tNormal[0] << ", " << tNormal[1] << ", " << tNormal[2] << std::endl;
//       double g1[3], g2[3], g3[3];
//       double a[3];
//       a[0] = 1;
//       a[1] = 0;
//       a[2] = 0;
//       t->interpolateGrad(a, 0, 0, 0, g1);
//       a[0] = 0;
//       a[1] = 1;
//       a[2] = 0;
//       t->interpolateGrad(a, 0, 0, 0, g2);
//       a[0] = 0;
//       a[1] = 0;
//       a[2] = 1;
//       t->interpolateGrad(a, 0, 0, 0, g3);
//       SVector3 G[3];
//       G[0] = SVector3(g1[0] + g2[0] - g3[0], g1[1] + g2[1] - g3[1],
// 		      g1[2] + g2[2] - g3[2]);
//       G[1] = SVector3(g2[0] + g3[0] - g1[0], g2[1] + g3[1] - g1[1],
// 		      g2[2] + g3[2] - g1[2]);
//       G[2] = SVector3(g1[0] + g3[0] - g2[0], g1[1] + g3[1] - g2[1],
// 		      g1[2] + g3[2] - g2[2]);
//       double alphaEdgeInit[3]={0.0};
//       MEdge edgeRef = t->getEdge(0);
//       size_t localId=0;
//       std::cout << "compute local angles " << std::endl;//DBG
//       for(size_t k=0;k<3;k++){
// 	alphaEdgeInit[localId]=_getAngleBetweenEdges(*(triangleToEdges[t][k]),edgeRef,tNormal);
// 	localId++;
//       }

//       //Loop on iRef to pick the best lifting possible
//       double minSum=std::numeric_limits<double>::max();;
//       double alphaEdge[3]={0.0};
//       for(size_t sgnA=0;sgnA<3;sgnA++){
// 	for(size_t sgnB=0;sgnB<3;sgnB++){
// 	  for(size_t sgnC=0;sgnC<3;sgnC++){
// 	    double alphaTest[3]={alphaEdgeInit[0]+(1.*sgnA-1.)*2*M_PI,
// 				 alphaEdgeInit[1]+(1.*sgnB-1.)*2*M_PI,
// 				 alphaEdgeInit[2]+(1.*sgnC-1.)*2*M_PI};
// 	    double sumDiff=0.0;
// 	    for(size_t k=0;k<3;k++){
// 	      for(size_t l=0;l<3;l++){
// 		sumDiff+=(alphaTest[k]-alphaTest[l])*(alphaTest[k]-alphaTest[l]);
// 	      }	
// 	    }
// 	    SVector3 gradAlphaEdgeTest = alphaTest[0]*G[0]+alphaTest[1]*G[1]+alphaTest[2]*G[2];
// 	    sumDiff=gradAlphaEdgeTest.norm();
// 	    if(sumDiff<minSum){
// 	      minSum=sumDiff;
// 	      alphaEdge[0]=alphaTest[0];alphaEdge[1]=alphaTest[1];alphaEdge[2]=alphaTest[2];
// 	    }
// 	  }
// 	}
//       }

//       SVector3 gradAlphaEdge = (alphaEdge[0]*G[0]+alphaEdge[1]*G[1]+alphaEdge[2]*G[2]);
//       // SVector3 gradAlphaEdge(0.,0.,0.);
//       std::cout << "++++++ sum diff alpha carre :" << minSum << std::endl;
//       double RHS[3] = {dot(gradAlphaEdge, G[0]), dot(gradAlphaEdge, G[1]),
// 		       dot(gradAlphaEdge, G[2])};
//       std::cout << "rhs : " << RHS[0] << " , " << RHS[1] << " , " << RHS[2] << std::endl;//DBG	    
//       std::cout << "assemble " << std::endl;//DBG
//       for(size_t k=0; k<3; k++){
// 	std::cout << "idEdge : "<< idEdge[triangleToEdges[t][k]] << std::endl;
// 	Dof Ek(idEdge[triangleToEdges[t][k]], Dof::createTypeWithTwoInts(0, 1));
// 	dof->assemble(Ek, -RHS[k] * V);
// 	for(size_t l=0; l<3; l++){
// 	  Dof El(idEdge[triangleToEdges[t][l]], Dof::createTypeWithTwoInts(0, 1));
// 	  dof->assemble(Ek, El, dot(G[k], G[l]) * V);
// 	}
//       }
//       counT++;//DBG
//     }

//     std::cout << "solve " << std::endl;//DBG
//     _lsys->systemSolve();
//     std::cout << "getting back sol " << std::endl;//DBG
//     for(const auto &kv: idEdge){
//       double value=0.0;
//       Dof d(kv.second, Dof::createTypeWithTwoInts(0, 1));
//       dof->getDofValue(d, value);
//       theta[kv.first]=value;
//       // std::cout << value << std::endl;
//     }
//     delete _lsys;
//     delete dof;
//     countP++;//DBG
//   }
//   std::cout << "creating crossfield " << std::endl;//DBG
//   for(const MEdge &e: edges){
//     crossField[&e]=Cross2D(this,&e,theta[&e]);
//   }
//   ConformalMapping::_viewScalarEdges(theta,"theta"); //DBG
//   return;
// }

ConformalMapping::ConformalMapping(GModel *gm): _currentMesh(NULL), _gm(gm), _initialMesh(NULL), _featureCutMesh(NULL), _cutGraphCutMesh(NULL)
{
  _initialMesh = new MyMesh(gm);
  _currentMesh=_initialMesh;
  //cut mesh on feature lines here
  Msg::Info("Cutting mesh on feature lines");
  _cutMeshOnFeatureLines();
  _currentMesh=_featureCutMesh;
  Msg::Info("Compute geometric characteristics");
  _currentMesh->computeGeoCharac();
  // _viewScalarVertex(_currentMesh->gaussCurv,"gaussian curvature"); //DBG
  //Solve H here
  Msg::Info("Compute H");
  _computeH();
  _viewScalarTriangles(_currentMesh->H, _currentMesh->triangles, "H");
  //create cutgraph and cut mesh along it
  Msg::Info("Creating cut graph");
  _createCutGraph();
  // _viewScalarVertex(_distanceToFeatureAndSing,"distances"); //DBG
  // Msg::Info("Cutting mesh on cut graph");
  Msg::Info("Cut mesh on cut graph");
  std::cout << "Cut mesh on cut graph" << std::endl;
  _cutMeshOnCutGraph();
  _currentMesh=_cutGraphCutMesh;
  // _currentMesh=_initialMesh;
  //compute local smooth manifold basis
  Msg::Info("Create manifold basis");
  std::cout << "Create manifold basis" << std::endl;
  _currentMesh->viewNormals();
  _createManifoldBasis();
  _viewCrosses(_currentMesh->manifoldBasis,"manifold basis");
  //solve crosses
  _computeCrossesFromH();
  std::cout << "print crosses" << std::endl;
  _viewCrosses(_currentMesh->crossField,"crossfield");
  //parametrization
  std::cout << "compute parametrization" << std::endl;
  _computeParametrization();
}

void ConformalMapping::_computeH(){
  if(_currentMesh->trianglesPatchs.size()==0)
    _currentMesh->createPatchs();
  bool viewPatchForDebug=false;
  for(size_t k=0;k<_currentMesh->trianglesPatchs.size();k++){
    std::set<MTriangle*, MElementPtrLessThan> tri = _currentMesh->trianglesPatchs[k];
    //grabbing vertices we are interested in
    std::map<MVertex *, int, MVertexPtrLessThan> patchSingIndices;
    std::set<MVertex *, MVertexPtrLessThan> vertices;
    for(MTriangle *t: tri){
      for(int k=0;k<3;k++){
	MVertex *vK = t->getVertex(k);
	vertices.insert(vK);
	if(_currentMesh->singIndices.find(vK)!=_currentMesh->singIndices.end()){
	  patchSingIndices[vK]=_currentMesh->singIndices[vK];
	}
      }
    }
    //Check if everything matches (geometry characteristics and singularities)
    bool canBeComputed=false;
    double intGauss=0.0;
    double intGeodesic=0.0;
    for(MVertex *v: vertices){
      intGauss+=_currentMesh->gaussCurv[v];
      intGeodesic+=_currentMesh->geodesicCurv[v];
    }
    double sumSing=0;
    for(const auto &kv: patchSingIndices){
      sumSing+=((double)kv.second)/4.;
    }
    double checkSum=(intGauss+intGeodesic)/(2*M_PI)-sumSing;
    if(fabs(checkSum)<1e-10){
      canBeComputed=true;
    }
    else{
      Msg::Error("Gauss and geodesic curvature not matching number of singularities on patch %i.",k);
      Msg::Error("Patch %i miss singularities for a total indice of %g",k,checkSum*4.);
      Msg::Error("Skipping computation of H on this patch.");
      viewPatchForDebug=true;
    }
    if(canBeComputed){
      //fill _currentMesh->H
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
      linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
      printf("petsc solver\n");
#elif defined(HAVE_MUMPS)
      linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
      printf("mmups solver\n");
#else
      linearSystemFull<double> *_lsys = new linearSystemFull<double>;
      printf("default solver\n");
#endif
#endif
      dofManager<double> *dof = new dofManager<double>(_lsys);

      for(MVertex *v: vertices){
	dof->numberVertex(v, 0, 1);
      }
      //Temporary numbering for average
      dof->numberVertex(*(vertices.begin()), 1, 1);

      simpleFunction<double> ONE(1.0);
      laplaceTerm l(0, 1, &ONE);
      //Matrix
      for(MTriangle *t: tri){
	SElement se(t);
	l.addToMatrix(*dof, &se);
      }
      //right hand side
      for(MVertex *v: vertices){
	Dof E(v->getNum(), Dof::createTypeWithTwoInts(0, 1));
	_lsys->addToRightHandSide(dof->getDofNumber(E),_currentMesh->gaussCurv[v]);
      }
      //Neumann condition
      for(MVertex *v: vertices){
	Dof E(v->getNum(), Dof::createTypeWithTwoInts(0, 1));
	_lsys->addToRightHandSide(dof->getDofNumber(E),_currentMesh->geodesicCurv[v]);
      }
      //Singularities
      for(const auto &kv: patchSingIndices){
	Dof E(kv.first->getNum(), Dof::createTypeWithTwoInts(0, 1));
	_lsys->addToRightHandSide(dof->getDofNumber(E), -2.0 * M_PI * ((double)kv.second) / 4.);
      }
      // AVERAGE (temporary fix)
      Dof EAVG((*(vertices.begin()))->getNum(), Dof::createTypeWithTwoInts(1, 1));
      for(MVertex *v: vertices){
	Dof E(v->getNum(), Dof::createTypeWithTwoInts(0, 1));
	dof->assembleSym(EAVG, E, 1);
	//      dof->assemble(E, EAVG, 1);
      }
      _lsys->systemSolve();
      for(MVertex *v: vertices){
	dof->getDofValue(v, 0, 1, _currentMesh->H[v]);
      }
      delete _lsys;
      delete dof;
    }
  }
  if(viewPatchForDebug)
    _currentMesh->viewPatchs();
  return;
}

void ConformalMapping::_computeCrossesFromH(){
  if(_currentMesh->trianglesPatchs.size()==0)
    _currentMesh->createPatchs();
  std::map<const MEdge *, double> theta;
  for(size_t kP=0;kP<_currentMesh->trianglesPatchs.size();kP++){
    std::set<MTriangle*, MElementPtrLessThan> tri = _currentMesh->trianglesPatchs[kP];
    //grabbing edges we are interested in and numbering dofs
    std::map<const MEdge *, size_t> idEdge;
    std::set<const MEdge*> edgeBC;
    size_t id=0;
    size_t nBC=0;
    for(MTriangle *t: tri){
      for(int k=0;k<3;k++){
	const MEdge *eK = _currentMesh->triangleToEdges[t][k];
	if(idEdge.find(eK)==idEdge.end()){
	  idEdge[eK]=id;
	  id++;
	  if(_currentMesh->isFeatureEdge[eK]&&nBC<1){
	    edgeBC.insert(eK);
	    nBC++;
	  }
	}
      }
    }
    //fill _currentMesh->crossfield
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
    printf("petsc solver\n");
#elif defined(HAVE_MUMPS)
    linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
    printf("mmups solver\n");
#else
    linearSystemFull<double> *_lsys = new linearSystemFull<double>;
    printf("default solver\n");
#endif
#endif
    dofManager<double> *dof = new dofManager<double>(_lsys);
    // ConformalMapping::_viewEdges(edgeBC,"edgeBC");
    Dof E0(idEdge[*(edgeBC.begin())], Dof::createTypeWithTwoInts(0, 1));
    dof->fixDof(E0,-_currentMesh->manifoldBasis[*(edgeBC.begin())].theta);
    size_t nEdgesId=0;
    for(const auto &kv: idEdge){
      //numberdof here
      Dof EdgeDof(kv.second, Dof::createTypeWithTwoInts(0, 1));
      dof->numberDof(EdgeDof);
      nEdgesId++;
    }    
    Msg::Info("Crosses system, %i unknowns...",idEdge.size());
    Msg::Info(" ");
    for(MTriangle *t: tri){
      double V = t->getVolume();
      SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
		   t->getVertex(1)->y() - t->getVertex(0)->y(),
		   t->getVertex(1)->z() - t->getVertex(0)->z());
      SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
		   t->getVertex(2)->y() - t->getVertex(0)->y(),
		   t->getVertex(2)->z() - t->getVertex(0)->z());
      SVector3 tNormal = crossprod(v10, v20);
      tNormal.normalize();
      double g1[3], g2[3], g3[3];
      double a[3];
      a[0] = 1;
      a[1] = 0;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      a[0] = 0;
      a[1] = 1;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g2);
      a[0] = 0;
      a[1] = 0;
      a[2] = 1;
      t->interpolateGrad(a, 0, 0, 0, g3);
      SVector3 G[3];
      G[0] = SVector3(g1[0] + g2[0] - g3[0], g1[1] + g2[1] - g3[1],
		      g1[2] + g2[2] - g3[2]);
      G[1] = SVector3(g2[0] + g3[0] - g1[0], g2[1] + g3[1] - g1[1],
		      g2[2] + g3[2] - g1[2]);
      G[2] = SVector3(g1[0] + g3[0] - g2[0], g1[1] + g3[1] - g2[1],
		      g1[2] + g3[2] - g2[2]);

      std::vector<Cross2D*> basesTriEdge;
      basesTriEdge.reserve(3);
      for(size_t k=0;k<3;k++){
	basesTriEdge.push_back(&(_currentMesh->manifoldBasis[_currentMesh->triangleToEdges[t][k]]));
      }
      //Choose baseRef and create euler lifting
      double delta[4]={0.0,3.*M_PI/180.0,6.*M_PI/180.0,-3.*M_PI/180.0};
      SVector3 initSV3(0.0);
      std::vector<SVector3> baseRef(3,initSV3);
      size_t idDelta=0;
      double noNutation=1;
      std::vector<SVector3> eulerAngles(3,initSV3);
      while(fabs(noNutation)>1e-10){
	if(idDelta>3){
	  Msg::Error("Bug base tri euler angles.");
	  std::cout << "Bug base tri euler angles." << std::endl;
	  return;
	}
	baseRef[0]=basesTriEdge[0]->getDirection(0);
	baseRef[1]=cos(delta[idDelta])*basesTriEdge[0]->getDirection(1) + sin(delta[idDelta])*basesTriEdge[0]->getDirection(2);
	baseRef[2]=-sin(delta[idDelta])*basesTriEdge[0]->getDirection(1) + cos(delta[idDelta])*basesTriEdge[0]->getDirection(2);
	double noNutationK=0.0;
	noNutation=0.0;
	for(size_t k=0;k<3;k++){
	  eulerAngles[k]=basesTriEdge[k]->getEulerAngles(baseRef, noNutationK);
	  if(fabs(noNutationK)>fabs(noNutation))
	    noNutation=noNutationK;
	}
	idDelta++;
      }
      //critical: lifting on euler angles have to be done !!
      liftEulerAngles(eulerAngles);
      //Compute H and euler angles gradients
      SVector3 HNodes(0.0);
      for(size_t k=0;k<3;k++){
	MVertex *vK=t->getVertex(k);
	HNodes[k]=_featureCutMesh->H[_cutGraphToFeatureMeshVertex[vK]];
      }
      SVector3 gradH(0.0);
      for(size_t k=0;k<3;k++)
	gradH[k]=HNodes[0]*g1[k] + HNodes[1]*g2[k] + HNodes[2]*g3[k];
      SVector3 psi(0.0), gamma(0.0), phi(0.0);
      for(size_t k=0;k<3;k++){
	psi[k]=eulerAngles[k][0];
	gamma[k]=eulerAngles[k][1];
	phi[k]=eulerAngles[k][2];
      }
      SVector3 gradPsi(0.0), gradPhi(0.0);
      gradPsi=psi[0]*G[0]+psi[1]*G[1]+psi[2]*G[2];
      gradPhi=phi[0]*G[0]+phi[1]*G[1]+phi[2]*G[2];
      double psiGauss=(psi[0]+psi[1]+psi[2])/3.;
      double gammaGauss=(gamma[0]+gamma[1]+gamma[2])/3.;
      double phiGauss=(phi[0]+phi[1]+phi[2])/3.;
      SVector3 eulerGauss(psiGauss,gammaGauss,phiGauss);
      std::vector<SVector3> baseGauss = Cross2D::getDirFromEulerAngles(baseRef, eulerGauss);
      SVector3 Ug=baseGauss[0];
      SVector3 Vg=baseGauss[1];
      SVector3 Gu(0.0);
      for(size_t k=0; k<3; k++)
	for(size_t l=0; l<3; l++)
	  Gu[k]+=Ug[l]*G[k][l];
      SVector3 Gv(0.0);
      for(size_t k=0; k<3; k++)
	for(size_t l=0; l<3; l++)
	  Gv[k]+=Vg[l]*G[k][l];
      fullMatrix<double> Kelem(3, 3);
      for(size_t k=0; k<3; k++)
	for(size_t l=0; l<3; l++)
	  Kelem(k,l)=(Gu[k]*Gu[l]+Gv[k]*Gv[l])*V;
      SVector3 Relem(0.0);
      double Ru=(-dot(gradH,Vg)-dot(gradPhi,Ug)-cos(gammaGauss)*dot(gradPsi,Ug))*V;
      double Rv=(dot(gradH,Ug)-dot(gradPhi,Vg)-cos(gammaGauss)*dot(gradPsi,Vg))*V;
      for(size_t k=0; k<3; k++){
	Relem[k]=Gu[k]*Ru + Gv[k]*Rv;
      }
      for(size_t kE=0; kE<3; kE++){
	Dof Ek(idEdge[_currentMesh->triangleToEdges[t][kE]], Dof::createTypeWithTwoInts(0, 1));
	dof->assemble(Ek, Relem[kE]);
      	for(size_t lE=0; lE<3; lE++){
	  Dof El(idEdge[_currentMesh->triangleToEdges[t][lE]], Dof::createTypeWithTwoInts(0, 1));
	  dof->assemble(Ek, El, Kelem(kE,lE));
      	}
      }
    }
    std::cout << "Crosses system, " << idEdge.size()<< " unknowns..." << std::endl;
    _lsys->systemSolve();
    for(const auto &kv: idEdge){
      double valueTheta=0.0;
      Dof c(kv.second, Dof::createTypeWithTwoInts(0, 1));
      dof->getDofValue(c, valueTheta);
      theta[kv.first]=valueTheta;
    }
    delete _lsys;
    delete dof;
  }
  for(const MEdge &e: _currentMesh->edges){
    _currentMesh->crossField[&e]=Cross2D(_currentMesh,&e,_currentMesh->manifoldBasis[&e].theta+theta[&e]);
  }
  return;
}

std::map<const MEdge*, SVector3> ConformalMapping::_getLifting(MyMesh *mesh, const std::set<MTriangle*, MElementPtrLessThan> &triangles, MTriangle* triangleInit, const SVector3 &dirRef){
  std::map<const MEdge*, SVector3> lift;
  std::map<MTriangle *, bool, MElementPtrLessThan> trianglePassed;
  std::stack<MTriangle *> stackTri;
  for(MTriangle *t: triangles)
    trianglePassed[t]=false;
  MTriangle *triangleLeft=triangleInit;
  trianglePassed[triangleLeft]=true;
  std::map<MTriangle *, SVector3, MElementPtrLessThan> mapTriDir;
  mapTriDir[triangleInit] = dirRef;
  while(triangleLeft){
    for(const MEdge *e: mesh->triangleToEdges[triangleLeft]){
      for(MTriangle *t: mesh->edgeToTriangles[e]){
	lift[e]=mesh->crossField[e].getClosestBranchToDirection(mapTriDir[triangleLeft]);
	if(!trianglePassed[t]){
	  stackTri.push(t);
	  mapTriDir[t]=mesh->crossField[e].getClosestBranchToDirection(mapTriDir[triangleLeft]);
	  trianglePassed[t]=true;
	}
      }
    }
    if(!stackTri.empty()){
      triangleLeft = stackTri.top();
      stackTri.pop();
    }
    else{
      triangleLeft=NULL;
    }
  }
  return lift;
}

void ConformalMapping::_solvePotOnPatch(const std::set<MTriangle*, MElementPtrLessThan> &tri, const SVector3 &dirRef, std::map<MVertex *, double, MVertexPtrLessThan> &pot){
  //grabbing edges we are interested in and numbering dofs
  std::set<MVertex *, MVertexPtrLessThan> vertices;
  for(MTriangle *t: tri){
    for(int k=0;k<3;k++){
      MVertex *vK = t->getVertex(k);
      vertices.insert(vK);
    }
  }
  //lifting here
  std::map<const MEdge*, SVector3> liftU = _getLifting(_currentMesh, tri, (*(tri.begin())), dirRef);
  //fill _currentMesh->crossfield
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
  printf("petsc solver\n");
#elif defined(HAVE_MUMPS)
  linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
  printf("mmups solver\n");
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
  printf("default solver\n");
#endif
#endif
  //numbergin dof. Carefull, there is a boundary condition!
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> vertToVertDof;
  for(MVertex *v: vertices){
    vertToVertDof[v]=v;
  }
  std::vector<MEdge> featEdgBC;
  for(MTriangle *t: tri){
    for(const MEdge* e: _currentMesh->triangleToEdges[t]){
      if(_currentMesh->isFeatureEdge[e]){
	SVector3 edgVect(e->getVertex(1)->x() - e->getVertex(0)->x(),
			 e->getVertex(1)->y() - e->getVertex(0)->y(),
			 e->getVertex(1)->z() - e->getVertex(0)->z());
	edgVect.normalize();
	if(fabs(dot(edgVect,liftU[e]))<0.3) // TODO: check the lifting vector. We should have perfectly aligned crosses on feature edges
	  featEdgBC.push_back(*e);
      }
    }
  }
  std::cout << "size feature edges: " << featEdgBC.size() << std::endl;
  
  std::vector<std::vector<MVertex *> > vSorted;
  SortEdgeConsecutive(featEdgBC, vSorted);
  std::cout << "n Lines BC: " << vSorted.size() << std::endl;
  for(std::vector<MVertex *> &vectVert: vSorted){
    for(MVertex* v: vectVert)
      vertToVertDof[v]=vectVert[0];
  }
  dofManager<double> *dof = new dofManager<double>(_lsys);
  for(MVertex *v: vertices){
    dof->numberVertex(vertToVertDof[v], 0, 1);
  }
  //Temporary numbering for average
  dof->numberVertex(*(vertices.begin()), 1, 1);
    
  Msg::Info("Pametrization system, 2*%i unknowns...",vertices.size());
  Msg::Info(" ");
  for(MTriangle *t: tri){
    double V = t->getVolume();
    double g1[3], g2[3], g3[3];
    double a[3];
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;
    t->interpolateGrad(a, 0, 0, 0, g1);
    a[0] = 0;
    a[1] = 1;
    a[2] = 0;
    t->interpolateGrad(a, 0, 0, 0, g2);
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    t->interpolateGrad(a, 0, 0, 0, g3);
    SVector3 dirGauss(0.0);
    for(const MEdge* e: _currentMesh->triangleToEdges[t]){
      dirGauss+=liftU[e]*(1./3.);
    }
    dirGauss.normalize();
    double HGauss=0.0;
    for(size_t k=0;k<3;k++)
      HGauss+=_featureCutMesh->H[_cutGraphToFeatureMeshVertex[t->getVertex(k)]];
    dirGauss*=exp(-HGauss);
    fullMatrix<double> Kelem(3, 3);
    Kelem.setAll(0.0);
    fullMatrix<double> g(3, 3);
    for(size_t k=0; k<3; k++){
      g(k,0)=g1[k];
      g(k,1)=g2[k];
      g(k,2)=g3[k];
    }
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++)
	for(size_t m=0; m<3; m++)
	  Kelem(k,l)+=(g(m,k)*g(m,l))*V;
    SVector3 Relem(0.0);
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++)
	Relem[k]+=g(l,k)*dirGauss[l]*V;
    for(size_t kE=0; kE<3; kE++){
      MVertex* v=t->getVertex(kE);
      Dof Ek(vertToVertDof[v]->getNum(), Dof::createTypeWithTwoInts(0, 1));
      dof->assemble(Ek, Relem[kE]);
      for(size_t lE=0; lE<3; lE++){
	MVertex* v2=t->getVertex(lE);
	Dof El(vertToVertDof[v2]->getNum(), Dof::createTypeWithTwoInts(0, 1));
	dof->assemble(Ek, El, Kelem(kE,lE));
      }
    }
  }
  // AVERAGE (temporary fix)
  Dof EAVG((*(vertices.begin()))->getNum(), Dof::createTypeWithTwoInts(1, 1));
  for(MVertex *v: vertices){
    Dof E(v->getNum(), Dof::createTypeWithTwoInts(0, 1));
    dof->assembleSym(EAVG, E, 1);
    //      dof->assemble(E, EAVG, 1);
  }

  _lsys->systemSolve();
  for(MVertex *v: vertices){
    dof->getDofValue(vertToVertDof[v], 0, 1, pot[v]);
  }
  delete _lsys;
  delete dof;
  return;
}

void ConformalMapping::_computeParametrization(){
  if(_currentMesh->trianglesPatchs.size()==0)
    _currentMesh->createPatchs();
  for(size_t kP=0;kP<_currentMesh->trianglesPatchs.size();kP++){
    std::set<MTriangle*, MElementPtrLessThan> tri = _currentMesh->trianglesPatchs[kP];
    SVector3 dirRefU=_currentMesh->crossField[_currentMesh->triangleToEdges[(*(tri.begin()))][0]].getDirection(0);
    SVector3 dirRefV=_currentMesh->crossField[_currentMesh->triangleToEdges[(*(tri.begin()))][0]].getDirection(1);
    _solvePotOnPatch(tri, dirRefU, _currentMesh->potU);
    _solvePotOnPatch(tri, dirRefV, _currentMesh->potV);
  }
  _viewScalarTriangles(_currentMesh->potU, _currentMesh->triangles, "potU");
  _viewScalarTriangles(_currentMesh->potV, _currentMesh->triangles, "potV");
  return;
}

void ConformalMapping::_computeDistancesToBndAndSing(){
  typedef std::pair<double, MVertex*> weightedVertex;
  std::map<MVertex *, std::set<weightedVertex>> weightedConnectivity;
  for(const MEdge &e: _currentMesh->edges){
    double length=e.length();
    weightedConnectivity[e.getVertex(0)].insert(weightedVertex(length,e.getVertex(1)));
    weightedConnectivity[e.getVertex(1)].insert(weightedVertex(length,e.getVertex(0)));
    _distanceToFeatureAndSing[e.getVertex(0)]=std::numeric_limits<double>::max();
    _distanceToFeatureAndSing[e.getVertex(1)]=std::numeric_limits<double>::max();
  }
  std::priority_queue<weightedVertex,std::vector<weightedVertex>, std::greater<weightedVertex>> priorityQueue;
  for(MVertex *v: _currentMesh->featureVertices){
    _distanceToFeatureAndSing[v]=0.0;
    priorityQueue.push(weightedVertex(0.0,v));
  }
  for(MVertex *v: _currentMesh->singularities){
    _distanceToFeatureAndSing[v]=0.0;
    priorityQueue.push(weightedVertex(0.0,v));
  }
  while(!priorityQueue.empty()){
    MVertex *v=priorityQueue.top().second;
    double distV=_distanceToFeatureAndSing[v];
    priorityQueue.pop();
    for(const weightedVertex &wV: weightedConnectivity[v]){
      double dist=_distanceToFeatureAndSing[wV.second];
      if(dist>distV+wV.first){
	_distanceToFeatureAndSing[wV.second]=distV+wV.first;
	priorityQueue.push(weightedVertex(_distanceToFeatureAndSing[wV.second],wV.second));
      }
    }
  }
}

void ConformalMapping::_createCutGraph(){
  _computeDistancesToBndAndSing();
  _currentMesh->cutGraphDiscreteEdges = _createEdgeTree();
  _trimEdgeTree(_currentMesh->cutGraphDiscreteEdges);
  _viewEdges(_currentMesh->cutGraphDiscreteEdges,"cutgraphTrimmed");
  for(const MEdge &e: _currentMesh->edges){
    _currentMesh->isCutGraphEdge[&e]=false;
  }
  for(const MEdge *e: _currentMesh->cutGraphDiscreteEdges){
    _currentMesh->isCutGraphEdge[e]=true;
  }
}

std::set<const MEdge *> ConformalMapping::_createEdgeTree(){
  typedef std::pair<double,MTriangle *> weightedTri;
  std::set<weightedTri> weightedTriangles;
  std::map<MTriangle *, bool, MElementPtrLessThan> trianglePassed;
  std::map<MTriangle *, double, MElementPtrLessThan> triangleWeight;
  std::priority_queue<weightedTri,std::vector<weightedTri>, std::less<weightedTri>> pQueue;
  // std::priority_queue<weightedTri,std::vector<weightedTri>, std::greater<weightedTri>> pQueue;
  std::set<const MEdge *> edgeTree;
  for(MTriangle *t: _currentMesh->triangles){
    trianglePassed[t]=false;
    triangleWeight[t]=0.0;
    for(int k=0;k<3;k++){
      MVertex *v=t->getVertex(k);
      triangleWeight[t]+=_distanceToFeatureAndSing[v];
    }
    triangleWeight[t]/=3.0;
  }
  for(const MEdge &e: _currentMesh->edges){
    edgeTree.insert(&e);
  }
  //Put random triangle as passed (or well chosen one
  MTriangle *triangleLeft=NULL;
  for(auto &kv: trianglePassed){
    if(!kv.second){
      triangleLeft=kv.first;
      break;
    }
  }
  trianglePassed[triangleLeft]=true;
  while(triangleLeft){
    for(const MEdge *e: _currentMesh->triangleToEdges[triangleLeft]){
      if(!_currentMesh->isFeatureEdge[e]){
	for(MTriangle *t: _currentMesh->edgeToTriangles[e]){
	  if(!trianglePassed[t]){
	    pQueue.push(weightedTri(triangleWeight[t],t));
	    trianglePassed[t]=true;
	    edgeTree.erase(e);
	  }
	}
      }
    }
    if(!pQueue.empty()){
      triangleLeft = pQueue.top().second;
      pQueue.pop();
    }
    else{
      triangleLeft=NULL;
      for(auto &kv: trianglePassed){
	if(!kv.second){
	  triangleLeft=kv.first;
	  trianglePassed[triangleLeft]=true;
	  break;
	}
      }
    }
  }
  return edgeTree;
}

void ConformalMapping::_trimEdgeTree(std::set<const MEdge *> &edgeTree){//TODO: can be tremendously accelerated (killing all trees with root on boundary/sing and no sing as leave right away, then trimming the one left). Option 2: trimming can actually be in a 4 loop, we store falgs for deleted edges and voila.
  std::map<MVertex *, int> multVertex;
  for(const MEdge *e: edgeTree){
    multVertex[e->getVertex(0)]++;
    multVertex[e->getVertex(1)]++;
  }
  for(const MEdge *e: _currentMesh->featureDiscreteEdges){
    multVertex[e->getVertex(0)]++;
    multVertex[e->getVertex(1)]++;
  }
  for(MVertex *v: _currentMesh->singularities){//TODO: we have to think about what to do with singularities which are on a boundary
    multVertex[v]++;
  }
  std::map<MVertex *, std::vector<MVertex*>> connectivity;
  std::map<MVertex *, std::vector<const MEdge*>> edgesConnect;
  for(const MEdge *e: edgeTree){
    connectivity[e->getVertex(0)].push_back(e->getVertex(1));
    connectivity[e->getVertex(1)].push_back(e->getVertex(0));
    edgesConnect[e->getVertex(0)].push_back(e);
    edgesConnect[e->getVertex(1)].push_back(e);
  }
  MVertex *vLeaf=NULL;
  const MEdge *eLeaf=NULL;
  for(auto &kv: connectivity){
    if(kv.second.size()==1){
      if(_currentMesh->singularities.find(kv.first)==_currentMesh->singularities.end()){
	vLeaf = kv.first;
	eLeaf = edgesConnect[vLeaf][0];
	break;
      }
    }
  }
  while(vLeaf){
    MVertex *nextLeaf=connectivity[vLeaf][0];
    connectivity[vLeaf].pop_back();
    edgesConnect[vLeaf].pop_back();
    edgeTree.erase(eLeaf);
    std::vector<const MEdge*>::iterator itEdgeConn= edgesConnect[nextLeaf].begin();
    for(std::vector<MVertex*>::iterator itVertConn = connectivity[nextLeaf].begin(); itVertConn != connectivity[nextLeaf].end() ; itVertConn++){
      if(*itVertConn!=vLeaf){
	itEdgeConn++;
      }
      else{
	connectivity[nextLeaf].erase(itVertConn);
	edgesConnect[nextLeaf].erase(itEdgeConn);
	break;
      }
    }
    if(connectivity[nextLeaf].size()==1 && _currentMesh->singularities.find(nextLeaf)==_currentMesh->singularities.end()){
      vLeaf=nextLeaf;
      eLeaf=edgesConnect[vLeaf][0];
    }
    else{
      vLeaf=NULL;
      eLeaf=NULL;
      for(auto &kv: connectivity){
	if(kv.second.size()==1){
	  if(_currentMesh->singularities.find(kv.first)==_currentMesh->singularities.end()){
	    vLeaf = kv.first;
	    eLeaf = edgesConnect[vLeaf][0];
	    break;
	  }
	}
      }
    }
  }
}

void ConformalMapping::_cutMeshOnFeatureLines(){
  _featureCutMesh = new MyMesh(*_initialMesh);
  std::map<MVertex *, int> multVert;
  for(MTriangle *t: _featureCutMesh->triangles){
    for(int k=0;k<3;k++){
      multVert[t->getVertex(k)]=0;
      _featureToInitMeshVertex[t->getVertex(k)]=t->getVertex(k);
    }
  }
  for(MLine *l: _featureCutMesh->lines){
    for(int k=0;k<2;k++){
      multVert[l->getVertex(k)]++;
    }
  }
  // _featureCutMesh->viewMult(multVert);//DBG
  //Delete all edges and lines
  _featureCutMesh->featureVertices.clear();
  _featureCutMesh->triangleToEdges.clear();
  _featureCutMesh->normals.clear();
  _featureCutMesh->edges.clear();
  _featureCutMesh->lines.clear();
  _featureCutMesh->linesEntities.clear();
  _featureCutMesh->isFeatureEdge.clear();
  _featureCutMesh->featureDiscreteEdges.clear();
  _featureCutMesh->featureDiscreteEdgesEntities.clear();
  _featureCutMesh->edgeToTriangles.clear();
  _featureCutMesh->featureVertexToEdges.clear();


  //Cut the mesh
  //loop on tri
  std::map<MVertex *, int> multVertexProcessed;
  std::map<MTriangle *, std::vector<MVertex *>> vertexProcessedPerTriangle;
  std::set<MTriangle *, MElementPtrLessThan> trianglesQueue;
  for(const MEdge *fe: _initialMesh->featureDiscreteEdges){
    for(int k=0; k<2;k++){
      MVertex *currentVertex;
      currentVertex = fe->getVertex(k);
      for(MTriangle *t:_initialMesh->edgeToTriangles[fe]){
	MVertex *newVertex=currentVertex;
	if(multVertexProcessed[currentVertex]>0){
	  GEntity *geVertex = currentVertex->onWhat();
	  // //DBG
	  // double fact = (1.0+0.05*multVertexProcessed[currentVertex]);
	  // newVertex = new MVertex(currentVertex->x()*fact,currentVertex->y()*fact,currentVertex->z()*fact,geVertex,0);
	  // //
	  newVertex = new MVertex(currentVertex->x(),currentVertex->y(),currentVertex->z(),geVertex,0);
	  geVertex->mesh_vertices.push_back(newVertex);
	}
	trianglesQueue.clear();
	std::vector<MVertex *>::iterator vertexProcessed=std::find(vertexProcessedPerTriangle[t].begin(),vertexProcessedPerTriangle[t].end(),currentVertex);
	if(vertexProcessed==vertexProcessedPerTriangle[t].end()){
	  trianglesQueue.insert(t);
	  _featureToInitMeshVertex[newVertex]=currentVertex;
	}
	while(trianglesQueue.size()>0){
	  std::set<MTriangle *, MElementPtrLessThan>::iterator it=trianglesQueue.begin();
	  MTriangle *currentTri=*it;
	  for(int l=0;l<3;l++){
	    MVertexPtrEqual isVertTheSame;
	    if(isVertTheSame(currentTri->getVertex(l),currentVertex)){
	      currentTri->setVertex(l,newVertex);
	      // Getting other triangles to add to queue
	      for(int m=0;m<2;m++){
	      	const MEdge *ptrEdgeM=_initialMesh->triangleToEdges[currentTri][(l+2+m)%3];
	      	if(!_initialMesh->isFeatureEdge[ptrEdgeM]){
	      	  for(MTriangle *triCandidate: _initialMesh->edgeToTriangles[ptrEdgeM]){
	      	    std::vector<MVertex *>::iterator itProcessed=std::find(vertexProcessedPerTriangle[triCandidate].begin(),vertexProcessedPerTriangle[triCandidate].end(),currentVertex);
	      	    MElementPtrEqual isTriTheSame;
	      	    if((!isTriTheSame(triCandidate, currentTri))&&(itProcessed==vertexProcessedPerTriangle[triCandidate].end())){
	      	      trianglesQueue.insert(triCandidate);
	      	    }
	      	  }
	      	}
	      }
	    }
	  }
	  vertexProcessedPerTriangle[currentTri].push_back(currentVertex);
	  trianglesQueue.erase(it);
	}
	multVertexProcessed[currentVertex]++;
      }
    }
    //add new feature MLine and MEdge if some where created
    for(MTriangle *t:_initialMesh->edgeToTriangles[fe]){
      MEdgeEqual isEdgeTheSame;
      for(int k=0;k<3;k++){
    	MEdge newEdgeK=t->getEdge(k);
	if(_featureToInitMeshVertex[newEdgeK.getVertex(0)]!=NULL&&_featureToInitMeshVertex[newEdgeK.getVertex(1)]!=NULL){
	  MEdge edgeK(_featureToInitMeshVertex[newEdgeK.getVertex(0)],_featureToInitMeshVertex[newEdgeK.getVertex(1)]);
	  if(isEdgeTheSame(edgeK,*fe)){
	    std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
	    insertData=_featureCutMesh->edges.insert(newEdgeK);
	    if(insertData.second){
	      _featureCutMesh->isFeatureEdge[&(*insertData.first)]=true;
	      _featureCutMesh->featureDiscreteEdges.insert(&(*insertData.first));
	      MLine *newLine;
	      newLine = new MLine((*(insertData.first)).getVertex(0),(*(insertData.first)).getVertex(1));
	      _featureCutMesh->lines.insert(newLine);
	    
	      _featureCutMesh->linesEntities[newLine]=_initialMesh->featureDiscreteEdgesEntities[fe];
	      _featureCutMesh->featureDiscreteEdgesEntities[&(*insertData.first)]=_initialMesh->featureDiscreteEdgesEntities[fe];
	      _featureCutMesh->featureDiscreteEdgesEntities[&(*insertData.first)]->addLine(newLine); //TODO has to be removed in the end
	    }
	  }
	}
      }
    }
  }
  _featureCutMesh->updateEdgesAndVertexToTri();
  _featureCutMesh->updateNormals();
  for(const MEdge *e: _featureCutMesh->featureDiscreteEdges){
    _featureCutMesh->featureVertices.insert(e->getVertex(0));
    _featureCutMesh->featureVertices.insert(e->getVertex(1));
    _featureCutMesh->featureVertexToEdges[e->getVertex(0)].insert(e);
    _featureCutMesh->featureVertexToEdges[e->getVertex(1)].insert(e);
  }
}

void ConformalMapping::_cutMeshOnCutGraph(){
  _cutGraphCutMesh = new MyMesh(*_featureCutMesh);
  std::map<MVertex *, int> multVert;
  for(MTriangle *t: _cutGraphCutMesh->triangles){
    for(int k=0;k<3;k++){
      multVert[t->getVertex(k)]=0;
      _cutGraphToFeatureMeshVertex[t->getVertex(k)]=t->getVertex(k);
    }
  }
  for(MLine *l: _cutGraphCutMesh->lines){
    for(int k=0;k<2;k++){
      multVert[l->getVertex(k)]++;
    }
  }
  // _featureCutMesh->viewMult(multVert);//DBG
  //Delete all edges and lines
  _cutGraphCutMesh->featureVertices.clear();
  _cutGraphCutMesh->triangleToEdges.clear();
  _cutGraphCutMesh->normals.clear();
  _cutGraphCutMesh->edges.clear();
  _cutGraphCutMesh->lines.clear();
  _cutGraphCutMesh->linesEntities.clear();
  _cutGraphCutMesh->isFeatureEdge.clear();
  _cutGraphCutMesh->featureDiscreteEdges.clear();
  _cutGraphCutMesh->featureDiscreteEdgesEntities.clear();
  _cutGraphCutMesh->edgeToTriangles.clear();
  _cutGraphCutMesh->featureVertexToEdges.clear();


  //Cut the mesh
  //loop on tri
  std::map<MVertex *, int> multVertexProcessed;
  std::map<MTriangle *, std::vector<MVertex *>> vertexProcessedPerTriangle;
  std::set<MTriangle *, MElementPtrLessThan> trianglesQueue;
  for(const MEdge *fe: _featureCutMesh->cutGraphDiscreteEdges){
    for(int k=0; k<2;k++){
      MVertex *currentVertex;
      currentVertex = fe->getVertex(k);
      for(MTriangle *t:_featureCutMesh->edgeToTriangles[fe]){
	MVertex *newVertex=currentVertex;
	if(multVertexProcessed[currentVertex]>0){
	  GEntity *geVertex = currentVertex->onWhat();
	  // //DBG
	  // double fact = (1.0+0.05*multVertexProcessed[currentVertex]);
	  // newVertex = new MVertex(currentVertex->x()*fact,currentVertex->y()*fact,currentVertex->z()*fact,geVertex,0);
	  // //
	  newVertex = new MVertex(currentVertex->x(),currentVertex->y(),currentVertex->z(),geVertex,0);
	  geVertex->mesh_vertices.push_back(newVertex);
	}
	trianglesQueue.clear();
	std::vector<MVertex *>::iterator vertexProcessed=std::find(vertexProcessedPerTriangle[t].begin(),vertexProcessedPerTriangle[t].end(),currentVertex);
	if(vertexProcessed==vertexProcessedPerTriangle[t].end()){
	  trianglesQueue.insert(t);
	  _cutGraphToFeatureMeshVertex[newVertex]=currentVertex;
	}
	while(trianglesQueue.size()>0){
	  std::set<MTriangle *, MElementPtrLessThan>::iterator it=trianglesQueue.begin();
	  MTriangle *currentTri=*it;
	  for(int l=0;l<3;l++){
	    MVertexPtrEqual isVertTheSame;
	    if(isVertTheSame(currentTri->getVertex(l),currentVertex)){
	      currentTri->setVertex(l,newVertex);
	      // Getting other triangles to add to queue
	      for(int m=0;m<2;m++){
	      	const MEdge *ptrEdgeM=_featureCutMesh->triangleToEdges[currentTri][(l+2+m)%3];
	      	if(!_featureCutMesh->isCutGraphEdge[ptrEdgeM]){
	      	  for(MTriangle *triCandidate: _featureCutMesh->edgeToTriangles[ptrEdgeM]){
	      	    std::vector<MVertex *>::iterator itProcessed=std::find(vertexProcessedPerTriangle[triCandidate].begin(),vertexProcessedPerTriangle[triCandidate].end(),currentVertex);
	      	    MElementPtrEqual isTriTheSame;
	      	    if((!isTriTheSame(triCandidate, currentTri))&&(itProcessed==vertexProcessedPerTriangle[triCandidate].end())){
	      	      trianglesQueue.insert(triCandidate);
	      	    }
	      	  }
	      	}
	      }
	    }
	  }
	  vertexProcessedPerTriangle[currentTri].push_back(currentVertex);
	  trianglesQueue.erase(it);
	}
	multVertexProcessed[currentVertex]++;
      }
    }
    //add new feature MLine and MEdge if some where created
    if(_featureCutMesh->isFeatureEdge[fe]){
      for(MTriangle *t:_featureCutMesh->edgeToTriangles[fe]){
	MEdgeEqual isEdgeTheSame;
	for(int k=0;k<3;k++){
	  MEdge newEdgeK=t->getEdge(k);
	  if(_cutGraphToFeatureMeshVertex[newEdgeK.getVertex(0)]!=NULL&&_cutGraphToFeatureMeshVertex[newEdgeK.getVertex(1)]!=NULL){
	    MEdge edgeK(_cutGraphToFeatureMeshVertex[newEdgeK.getVertex(0)],_cutGraphToFeatureMeshVertex[newEdgeK.getVertex(1)]);
	    if(isEdgeTheSame(edgeK,*fe)){
	      std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> insertData;
	      insertData=_cutGraphCutMesh->edges.insert(newEdgeK);
	      if(insertData.second){
		_cutGraphCutMesh->isFeatureEdge[&(*insertData.first)]=true;
		_cutGraphCutMesh->featureDiscreteEdges.insert(&(*insertData.first));
		MLine *newLine;
		newLine = new MLine((*(insertData.first)).getVertex(0),(*(insertData.first)).getVertex(1));
		_cutGraphCutMesh->lines.insert(newLine);
	    
		_cutGraphCutMesh->linesEntities[newLine]=_featureCutMesh->featureDiscreteEdgesEntities[fe];
		_cutGraphCutMesh->featureDiscreteEdgesEntities[&(*insertData.first)]=_featureCutMesh->featureDiscreteEdgesEntities[fe];
		_cutGraphCutMesh->featureDiscreteEdgesEntities[&(*insertData.first)]->addLine(newLine); //TODO has to be removed in the end
	      }
	    }
	  }
	}
      }
    }
  }
  _cutGraphCutMesh->updateEdgesAndVertexToTri();
  _cutGraphCutMesh->updateNormals();
  for(const MEdge *e: _cutGraphCutMesh->featureDiscreteEdges){
    _cutGraphCutMesh->featureVertices.insert(e->getVertex(0));
    _cutGraphCutMesh->featureVertices.insert(e->getVertex(1));
    _cutGraphCutMesh->featureVertexToEdges[e->getVertex(0)].insert(e);
    _cutGraphCutMesh->featureVertexToEdges[e->getVertex(1)].insert(e);
  }
}

ConformalMapping::~ConformalMapping(){
  if(_initialMesh)
    delete _initialMesh;
  if(_featureCutMesh)
    delete _featureCutMesh;
  if(_cutGraphCutMesh)
    delete _cutGraphCutMesh;
}

void MyMesh::viewNormals(){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const MEdge &e: edges){
    SPoint3 b=e.barycenter();
    for (size_t lv = 0; lv < 3; ++lv){
      datalist.push_back(b[lv]);
    }
    for (size_t lv = 0; lv < 3; ++lv){
      datalist.push_back(normals[&e][lv]);
    }
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'","normals");
  int dataListViewTag = gmsh::view::add("normals");
  gmsh::view::addListData(dataListViewTag, "VP", datalist.size()/(3+3), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void MyMesh::viewPatchs(){ //for DBG only
#if defined(HAVE_POST)
  int tag=0;
  gmsh::initialize();
  Msg::Debug("create view '%s'","Triangle patchs");
  int dataListViewTag = gmsh::view::add("Triangle patchs");
  size_t nTri=0;
  std::vector<double> datalist;
  for(std::set<MTriangle*, MElementPtrLessThan> setTri: trianglesPatchs){
    for(MTriangle *t: setTri){
      datalist.push_back(t->getVertex(0)->x());
      datalist.push_back(t->getVertex(1)->x());
      datalist.push_back(t->getVertex(2)->x());
      datalist.push_back(t->getVertex(0)->y());
      datalist.push_back(t->getVertex(1)->y());
      datalist.push_back(t->getVertex(2)->y());
      datalist.push_back(t->getVertex(0)->z());
      datalist.push_back(t->getVertex(1)->z());
      datalist.push_back(t->getVertex(2)->z());
      datalist.push_back(tag);
      datalist.push_back(tag);
      datalist.push_back(tag);
      nTri++;
    }
    tag++;
    // gmsh::view::addListData(dataListViewTag, "SL", datalist.size()/(3+3+2), datalist);
  }
  gmsh::view::addListData(dataListViewTag, "ST", nTri, datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void MyMesh::viewDarbouxFrame(size_t i){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const auto &kv: _darbouxFrameVertices){
    MVertex *v=kv.first;
    std::vector<SVector3> darbouxFrame = kv.second;
    for (size_t lv = i; lv < i+1; ++lv){
      datalist.push_back(v->x());
      datalist.push_back(v->y());
      datalist.push_back(v->z());
      datalist.push_back(darbouxFrame[lv][0]);
      datalist.push_back(darbouxFrame[lv][1]);
      datalist.push_back(darbouxFrame[lv][2]);
    }
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'","darboux frames");
  int dataListViewTag = gmsh::view::add("darboux frames");
  gmsh::view::addListData(dataListViewTag, "VP", datalist.size()/(3+3), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void MyMesh::viewMult(std::map<MVertex *, int> &multVert){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const auto& kv: multVert){
    datalist.push_back(kv.first->x());
    datalist.push_back(kv.first->y());
    datalist.push_back(kv.first->z());
    datalist.push_back(kv.second);
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'","mult");
  int dataListViewTag = gmsh::view::add("mult");
  gmsh::view::addListData(dataListViewTag, "SP", datalist.size()/(3+1), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewScalarVertex(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const auto& kv: scalar){
    datalist.push_back(kv.first->x());
    datalist.push_back(kv.first->y());
    datalist.push_back(kv.first->z());
    datalist.push_back(kv.second);
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'",viewName);
  int dataListViewTag = gmsh::view::add(viewName);
  gmsh::view::addListData(dataListViewTag, "SP", datalist.size()/(3+1), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewScalarEdges(std::map<const MEdge *, double> &scalar, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const auto& kv: scalar){
    SPoint3 b=kv.first->barycenter();
    datalist.push_back(b.x());
    datalist.push_back(b.y());
    datalist.push_back(b.z());
    datalist.push_back(kv.second);
  }
  if(!datalist.empty()){
    gmsh::initialize();
    Msg::Debug("create view '%s'",viewName);
    int dataListViewTag = gmsh::view::add(viewName);
    gmsh::view::addListData(dataListViewTag, "SP", datalist.size()/(3+1), datalist);
  }
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewCrosses(std::map<const MEdge *, Cross2D> crossField, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  size_t nData=0;
  for(auto &kv: crossField){
    SPoint3 b=kv.first->barycenter();
    for(size_t k=0; k<2; k++){
      datalist.push_back(b.x());
      datalist.push_back(b.y());
      datalist.push_back(b.z());
      SVector3 vRef(kv.first->getVertex(1)->x() - kv.first->getVertex(0)->x(),
		    kv.first->getVertex(1)->y() - kv.first->getVertex(0)->y(),
		    kv.first->getVertex(1)->z() - kv.first->getVertex(0)->z());
      vRef.normalize();
      SVector3 normal=kv.second._mesh->normals[kv.first];
      SVector3 t=crossprod(normal,vRef);
      t.normalize();
      SVector3 branche = kv.second.getDirection(k);
      datalist.push_back(branche[0]);
      datalist.push_back(branche[1]);
      datalist.push_back(branche[2]);
      nData++;
    }
    for(size_t k=0; k<2; k++){
      datalist.push_back(b.x());
      datalist.push_back(b.y());
      datalist.push_back(b.z());
      SVector3 vRef(kv.first->getVertex(1)->x() - kv.first->getVertex(0)->x(),
		    kv.first->getVertex(1)->y() - kv.first->getVertex(0)->y(),
		    kv.first->getVertex(1)->z() - kv.first->getVertex(0)->z());
      vRef.normalize();
      SVector3 normal=kv.second._mesh->normals[kv.first];
      SVector3 t=crossprod(normal,vRef);
      t.normalize();
      SVector3 branche = kv.second.getDirection(k);
      datalist.push_back(-branche[0]);
      datalist.push_back(-branche[1]);
      datalist.push_back(-branche[2]);
      nData++;
    }
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'",viewName);
  int dataListViewTag = gmsh::view::add(viewName);
  // gmsh::view::addListData(dataListViewTag, "SL", datalist.size()/(3+3+2), datalist);
  gmsh::view::addListData(dataListViewTag, "VP", nData, datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewVectTri(std::map<const MTriangle *, SVector3, MElementPtrLessThan> vectTri, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  size_t nData=0;
  for(auto &kv: vectTri){
    SVector3 b(0.0);
    for(size_t k=0; k<3; k++){
      b[0]+=kv.first->getVertex(k)->x()/3.;
      b[1]+=kv.first->getVertex(k)->y()/3.;
      b[2]+=kv.first->getVertex(k)->z()/3.;
    }
    datalist.push_back(b[0]);
    datalist.push_back(b[1]);
    datalist.push_back(b[2]);
    datalist.push_back(kv.second.x());
    datalist.push_back(kv.second.y());
    datalist.push_back(kv.second.z());
    nData++;
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'",viewName);
  int dataListViewTag = gmsh::view::add(viewName);
  // gmsh::view::addListData(dataListViewTag, "SL", datalist.size()/(3+3+2), datalist);
  gmsh::view::addListData(dataListViewTag, "VP", nData, datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewEdges(std::set<const MEdge*> &edges, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(const MEdge *e: edges){
    datalist.push_back(e->getVertex(0)->x());
    datalist.push_back(e->getVertex(1)->x());
    datalist.push_back(e->getVertex(0)->y());
    datalist.push_back(e->getVertex(1)->y());
    datalist.push_back(e->getVertex(0)->z());
    datalist.push_back(e->getVertex(1)->z());
    datalist.push_back(0.0);//DBG
    datalist.push_back(1.0);
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'",viewName);
  int dataListViewTag = gmsh::view::add(viewName);
  // gmsh::view::addListData(dataListViewTag, "SL", datalist.size()/(3+3+2), datalist);
  gmsh::view::addListData(dataListViewTag, "SL", edges.size(), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}

void ConformalMapping::_viewScalarTriangles(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, std::set<MTriangle *, MElementPtrLessThan> &triangles, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  for(MTriangle *t: triangles){
    datalist.push_back(t->getVertex(0)->x());
    datalist.push_back(t->getVertex(1)->x());
    datalist.push_back(t->getVertex(2)->x());
    datalist.push_back(t->getVertex(0)->y());
    datalist.push_back(t->getVertex(1)->y());
    datalist.push_back(t->getVertex(2)->y());
    datalist.push_back(t->getVertex(0)->z());
    datalist.push_back(t->getVertex(1)->z());
    datalist.push_back(t->getVertex(2)->z());
    datalist.push_back(scalar[t->getVertex(0)]);
    datalist.push_back(scalar[t->getVertex(1)]);
    datalist.push_back(scalar[t->getVertex(2)]);
  }
  gmsh::initialize();
  Msg::Debug("create view '%s'",viewName);
  int dataListViewTag = gmsh::view::add(viewName);
  // gmsh::view::addListData(dataListViewTag, "SL", datalist.size()/(3+3+2), datalist);
  gmsh::view::addListData(dataListViewTag, "ST", triangles.size(), datalist);
#else 
  Msg::Error("Cannot create view without POST module");
  return;
#endif
}
