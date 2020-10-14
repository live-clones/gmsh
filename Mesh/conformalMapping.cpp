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

MyMesh::MyMesh(GModel *gm){
  getAllLinesAndTriangles(gm, lines, linesEntities, triangles);
  for(MTriangle *t: triangles){
    SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
		 t->getVertex(1)->y() - t->getVertex(0)->y(),
		 t->getVertex(1)->z() - t->getVertex(0)->z());
    SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
		 t->getVertex(2)->y() - t->getVertex(0)->y(),
		 t->getVertex(2)->z() - t->getVertex(0)->z());
    SVector3 normal_to_triangle = crossprod(v20, v10);
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
    SVector3 normal_to_triangle = crossprod(v20, v10);
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
  //Correction for boundary vertices here //CAREFULL ! This is wrong. We have to project both tangent in the tangent space, compute angle between both, and the compute the angular deflect to this angle.
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
  
  std::cout << "test : " << double() << std::endl;
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
	  setPatchTri.insert(triangleLeft);
	  break;
	}
      }
    }
  }
  return;
}

ConformalMapping::ConformalMapping(GModel *gm): _currentMesh(NULL), _gm(gm), _initialMesh(NULL), _featureCutMesh(NULL), _cutGraphCutMesh(NULL)
{
  _initialMesh = new MyMesh(gm);
  _currentMesh=_initialMesh;
  // _initialMesh->viewNormals();
  //cut mesh on feature lines here
  Msg::Info("Cutting mesh on feature lines");
  _cutMeshOnFeatureLines();
  _currentMesh=_featureCutMesh;
  _currentMesh->computeGeoCharac();
  _viewScalarVertex(_currentMesh->gaussCurv,"gaussian curvature"); //DBG
  //Solve H here
  _computeH();
  //create cutgraph and cut mesh along it
  Msg::Info("Creating cut graph");
  _createCutGraph();
  _cutMeshOnCutGraph();
  //solve crosses
  //parametrization
}

void ConformalMapping::_computeH(){
  _currentMesh->createPatchs();
  _currentMesh->viewPatchs();
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
  _viewScalarTriangles(_currentMesh->H, _currentMesh->triangles, "H");
  return;
}

// void ConformalMapping::_computeHSave(){
//   _currentMesh->createPatchs();
//   _currentMesh->viewPatchs();
//   for(std::set<MTriangle*, MElementPtrLessThan> tri: _currentMesh->trianglesPatchs){
//     //grabbing vertices we are interested in
//     std::set<MVertex *, MVertexPtrLessThan> vertices;
//     for(MTriangle *t: _currentMesh->triangles){
//       for(int k=0;k<3;k++){
// 	MVertex *vK = t->getVertex(k);
// 	vertices.insert(vK);
//       }
//     }
//     //Check if everything matches (geometry characteristics and singularities)
//     //fill _currentMesh->H
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

//     for(MVertex *v: vertices){
//       dof->numberVertex(v, 0, 1);
//     }
//     //Temporary numbering for average
//     dof->numberVertex(*(vertices.begin()), 1, 1);

//     simpleFunction<double> ONE(1.0);
//     laplaceTerm l(0, 1, &ONE);
//     //Matrix
//     for(MTriangle *t: _currentMesh->triangles){
//       SElement se(t);
//       l.addToMatrix(*dof, &se);
//     }
//     //right hand side
//     for(const auto &kv: _currentMesh->gaussCurv){
//       Dof E(kv.first->getNum(), Dof::createTypeWithTwoInts(0, 1));
//       _lsys->addToRightHandSide(dof->getDofNumber(E),kv.second);
//     }
//     //Neumann condition
//     for(const auto &kv: _currentMesh->geodesicCurv){
//       Dof E(kv.first->getNum(), Dof::createTypeWithTwoInts(0, 1));
//       _lsys->addToRightHandSide(dof->getDofNumber(E),kv.second);
//     }
//     //Singularities
//     for(const auto &kv: _currentMesh->singIndices){
//       Dof E(kv.first->getNum(), Dof::createTypeWithTwoInts(0, 1));
//       _lsys->addToRightHandSide(dof->getDofNumber(E), -2.0 * M_PI * (double)kv.second / 4.);
//     }
//     // AVERAGE (temporary fix)
//     Dof EAVG((*(vertices.begin()))->getNum(), Dof::createTypeWithTwoInts(1, 1));
//     for(MVertex *v: vertices){
//       Dof E(v->getNum(), Dof::createTypeWithTwoInts(0, 1));
//       dof->assembleSym(EAVG, E, 1);
//       //      dof->assemble(E, EAVG, 1);
//     }
//     _lsys->systemSolve();
//     for(MVertex *v: vertices){
//       dof->getDofValue(v, 0, 1, _currentMesh->H[v]);
//     }
//     delete _lsys;
//     delete dof;
//   }
//   _viewScalarTriangles(_currentMesh->H, _currentMesh->triangles, "H");
//   return;
// }

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
  _viewScalarVertex(_distanceToFeatureAndSing,"distances"); //DBG
}

void ConformalMapping::_createCutGraph(){
  Msg::Info("Computing distances");
  _computeDistancesToBndAndSing();
  _currentMesh->edgesCutGraph = _createEdgeTree();
  _trimEdgeTree(_currentMesh->edgesCutGraph);
  _viewEdges(_currentMesh->edgesCutGraph,"cutgraphTrimmed");  
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
  // pQueue.push(weightedTri(triangleWeight[triangleLeft],triangleLeft));
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
  // _featureCutMesh->viewMult(multVert);
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

void ConformalMapping::_viewEdges(std::set<const MEdge*> &edges, const std::string& viewName){ //for DBG only
#if defined(HAVE_POST)

  std::vector<double> datalist;
  std::cout << "numbers of edges : " << edges.size() << std::endl;
  for(const MEdge *e: edges){
    datalist.push_back(e->getVertex(0)->x());
    datalist.push_back(e->getVertex(1)->x());
    datalist.push_back(e->getVertex(0)->y());
    datalist.push_back(e->getVertex(1)->y());
    datalist.push_back(e->getVertex(0)->z());
    datalist.push_back(e->getVertex(1)->z());
    datalist.push_back(1.0);
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
