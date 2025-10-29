#include "GModel.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "Context.h"
#include "meshDuplicateVertices.h"


// User Euler
bool allowVertexCollapse(MVertex *v1, MVertex *v0,
                         std::map<MVertex*, std::vector<MFace>> &v2f)
{
  
  auto &f0 = v2f[v0];
  auto &f1 = v2f[v1];

  std::set<MFace,MFaceLessThan> F;
  std::set<MEdge,MEdgeLessThan> E;
  std::set<MVertex*> V;
  for (auto f : f0){
    F.insert(f);
    for (size_t i=0;i<f.getNumVertices();i++){
      E.insert(f.getEdge(i));
      V.insert(f.getVertex(i));
    }
  }

  for (auto f : f1){
    F.insert(f);
    for (size_t i=0;i<f.getNumVertices();i++){
      E.insert(f.getEdge(i));
      V.insert(f.getVertex(i));
    }
  }
  
  // replace v1 by v0
  std::set<MFace,MFaceLessThan> fnew;
  for (auto f : f0){
    std::set<MVertex*> nv;    
    for (size_t i=0;i<f.getNumVertices();i++){
      auto v = f.getVertex(i);
      if (v == v1)nv.insert(v0);
      else nv.insert(v);
    }
    std::vector<MVertex*> vv;
    vv.insert(vv.begin(), nv.begin(), nv.end());
    if (vv.size() == 4)fnew.insert(MFace(vv[0],vv[1],vv[2],vv[3]));
    if (vv.size() == 3)fnew.insert(MFace(vv[0],vv[1],vv[2]));
  }
  for (auto f : f1){
    std::set<MVertex*> nv;    
    for (size_t i=0;i<f.getNumVertices();i++){
      auto v = f.getVertex(i);
      if (v == v1)nv.insert(v0);
      else nv.insert(v);
    }
    std::vector<MVertex*> vv;
    vv.insert(vv.begin(), nv.begin(), nv.end());
    if (vv.size() == 4)fnew.insert(MFace(vv[0],vv[1],vv[2],vv[3]));
    if (vv.size() == 3)fnew.insert(MFace(vv[0],vv[1],vv[2]));
  }


  std::set<MEdge,MEdgeLessThan> enew;
  std::set<MVertex*> vnew;
  std::vector<MFace> ff;
  for (auto f : fnew){
    ff.push_back(f);
    for (size_t i=0;i<f.getNumVertices();i++){
      enew.insert(f.getEdge(i));
      vnew.insert(f.getVertex(i));
    }
  }

  if (F.size() - E.size() + V.size() == fnew.size() - enew.size() + vnew.size()){
    v2f[v0] = ff;
    v2f[v1] = {};
    return true;
  }
  printf("%lu %lu %lu -- %lu %lu %lu\n",F.size(), E.size(), V.size(),fnew.size(), enew.size(), vnew.size());
  
  return false;
}

void analyseVertex (MVertex *v, int &dim, bool &nonManifold){
  dim = v->onWhat()->dim();
  nonManifold = false;
  if (dim == 1){
    auto numFaces = v->onWhat()->faces().size();
    if (numFaces > 2) nonManifold = true;
  }
  else if (dim == 0){
    auto edges = v->onWhat()->edges();
    for (auto e : edges){
      auto numFaces = e->faces().size();
      if (numFaces > 2) nonManifold = true;
    }
  }
}

static bool allowMerge (MVertex *v1, MVertex *v2, std::map<MVertex*, std::vector<MFace>> &v2f){
  bool nm1, nm2;
  int d1, d2;
  analyseVertex (v1, d1, nm1);
  analyseVertex (v2, d2, nm2);
  if (d1 == 0 && d2 == 0){
    if (nm1 && nm2) return false;
  }
  if (!allowVertexCollapse (v1,v2,v2f))return false;
    
  
  return true;
}

int getAppetiteForMotion (MVertex *v){
  bool nm;
  int d;
  analyseVertex (v, d, nm);
  //  auto tag = v->onWhat()->tag();
  int val = 0;
  if (nm) val = -1000+(d)*100;  
  else val = d*100;  
  //  if (d == 0 && (tag == 293 || tag == 333))
  //    printf("%d %d\n",tag,val);
  return -val;
}

static void createDuplicatedVertices () {

  std::map<MVertex*, std::vector<MFace> > v2f; 
  {
    auto itf = GModel::current()->firstFace();
    auto ite = GModel::current()->lastFace();
    
    for (auto it = itf ; it != ite ; ++it) {
      GFace *f = *it;
      std::vector<MTriangle*> ts;
      for (size_t i=0;i<f->triangles.size();i++){
	v2f[f->triangles[i]->getVertex(0)].push_back(f->triangles[i]->getFace(0));
	v2f[f->triangles[i]->getVertex(1)].push_back(f->triangles[i]->getFace(0));
	v2f[f->triangles[i]->getVertex(2)].push_back(f->triangles[i]->getFace(0));
      }
      for (size_t i=0;i<f->quadrangles.size();i++){
	v2f[f->quadrangles[i]->getVertex(0)].push_back(f->quadrangles[i]->getFace(0));
	v2f[f->quadrangles[i]->getVertex(1)].push_back(f->quadrangles[i]->getFace(0));
	v2f[f->quadrangles[i]->getVertex(2)].push_back(f->quadrangles[i]->getFace(0));
	v2f[f->quadrangles[i]->getVertex(3)].push_back(f->quadrangles[i]->getFace(0));
      }
    }
  }
 
  degeneratedVertices::instance().initialize();
  {
    auto itf  = GModel::current()->firstEdge();
    auto ite = GModel::current()->lastEdge();
    for (auto it = itf ; it != ite ; ++it) {
      GEdge *f = *it;
      for (size_t i=0;i<f->getNumMeshElements();i++){
	MElement *e = f->getMeshElement(i);
	for (int j=0;j<e->getNumEdges();j++){
	  MEdge ed = e->getEdge(j);
	  MVertex *v0 = ed.getVertex(0);
	  MVertex *v1 = ed.getVertex(1);
	  double d = v0->distance(v1);
	  if(d < CTX::instance()->mesh.toleranceEdgeLength) {
	    if (allowMerge(v0,v1,v2f))
	      degeneratedVertices::instance().add(v0,v1);
	  }
	}
      }
    }
  }
  {
    auto itf = GModel::current()->firstFace();
    auto ite = GModel::current()->lastFace();
  
    for (auto it = itf ; it != ite ; ++it) {
      GFace *f = *it;
      for (size_t i=0;i<f->getNumMeshElements();i++){
	MElement *e = f->getMeshElement(i);
	for (int j=0;j<e->getNumEdges();j++){
	  MEdge ed = e->getEdge(j);
	  MVertex *v0 = ed.getVertex(0);
	  MVertex *v1 = ed.getVertex(1);
	  double d = v0->distance(v1);
	  if(d < CTX::instance()->mesh.toleranceEdgeLength) {
	    if (allowMerge(v0,v1,v2f))
	      degeneratedVertices::instance().add(v0,v1);
	  }
	}
      }
    }
  }
  {
    auto itf  = GModel::current()->firstRegion();
    auto ite = GModel::current()->lastRegion();
    for (auto it = itf ; it != ite ; ++it) {
      GRegion *f = *it;
      for (size_t i=0;i<f->getNumMeshElements();i++){
	MElement *e = f->getMeshElement(i);
	for (int j=0;j<e->getNumEdges();j++){
	  MEdge ed = e->getEdge(j);
	  MVertex *v0 = ed.getVertex(0);
	  MVertex *v1 = ed.getVertex(1);
	  double d = v0->distance(v1);
	  if(d < CTX::instance()->mesh.toleranceEdgeLength) {
	    if (allowMerge(v0,v1,v2f))
	      degeneratedVertices::instance().add(v0,v1);
	  }
	}
      }
    }
  }
}


void removeAllMeshEntitiesThatHaveSmallEdges(){

  if (CTX::instance()->mesh.toleranceEdgeLength <= 0.0) return;

  createDuplicatedVertices();

  int countLines = 0;
  int countTriangles = 0;
  int countQuads = 0;
  int countQuadsToTri = 0;

  {
    auto itf = GModel::current()->firstEdge();
    auto ite = GModel::current()->lastEdge();

    for (auto it = itf ; it != ite ; ++it) {
      GEdge *f = *it;
      std::vector<MLine*> ts;
      for (size_t i=0;i<f->lines.size();i++){
	MLine *t = f->lines[i];
	MVertex *v0 = degeneratedVertices::instance().representative(t->getVertex(0));
	MVertex *v1 = degeneratedVertices::instance().representative(t->getVertex(1));
	t->setVertex(0,v0);
	t->setVertex(1,v1);
	if (v0 != v1) ts.push_back(t);
	else {
	  countLines++;
	  //	  printf("%d %d %lu -- ",b0->getNum(),b0->onWhat()->dim(),b0->onWhat()->edges().size());
	  //	  printf("%d %d %lu -->",b1->getNum(),b1->onWhat()->dim(),b1->onWhat()->edges().size());
	  //	  printf("%d %d %lu \n" ,v1->getNum(),v1->onWhat()->dim(),v1->onWhat()->edges().size());
	  delete t;
	}
      }
      f->lines = ts;
    }
  }  

  {
    auto itf = GModel::current()->firstFace();
    auto ite = GModel::current()->lastFace();
  
    for (auto it = itf ; it != ite ; ++it) {
      GFace *f = *it;
      std::vector<MTriangle*> ts;
      for (size_t i=0;i<f->triangles.size();i++){
	MTriangle *t = f->triangles[i];
	MVertex *v0 = degeneratedVertices::instance().representative(t->getVertex(0));
	MVertex *v1 = degeneratedVertices::instance().representative(t->getVertex(1));
	MVertex *v2 = degeneratedVertices::instance().representative(t->getVertex(2));
	t->setVertex(0,v0);
	t->setVertex(1,v1);
	t->setVertex(2,v2);
	if (v0 != v1 && v0 != v2 && v1 != v2) ts.push_back(t);
	else {countTriangles++; delete t;}
      }
      f->triangles = ts;
      std::vector<MQuadrangle*> qs;
      for (size_t i=0;i<f->quadrangles.size();i++){
	MQuadrangle *q = f->quadrangles[i];
	MVertex *v0 = degeneratedVertices::instance().representative(q->getVertex(0));
	MVertex *v1 = degeneratedVertices::instance().representative(q->getVertex(1));
	MVertex *v2 = degeneratedVertices::instance().representative(q->getVertex(2));
	MVertex *v3 = degeneratedVertices::instance().representative(q->getVertex(3));
	q->setVertex(0,v0);
	q->setVertex(1,v1);
	q->setVertex(2,v2);
	q->setVertex(3,v3);
	std::set<MVertex*> S = {v0, v1, v2, v3};
	if (S.size() == 4){
	  qs.push_back(q);
	}
	else if (S.size() == 3){
	  if      (v0 == v1) f->triangles.push_back(new MTriangle(v1,v2,v3));
	  else if (v1 == v2) f->triangles.push_back(new MTriangle(v2,v3,v0));
	  else if (v2 == v3) f->triangles.push_back(new MTriangle(v3,v0,v1));
	  else if (v3 == v0) f->triangles.push_back(new MTriangle(v0,v1,v2));
	  countQuadsToTri++;
	  delete q;
	}
	else {countQuads++; delete q;}
      }
      f->quadrangles = qs;
    }
  }  
  Msg::Info("Removing All Mesh Entities That Have Edges Smaller Than %12.5E",CTX::instance()->mesh.toleranceEdgeLength);  
  Msg::Info("%d edges %d triangles %d quads %d quads2tri",countLines, countTriangles, countQuads, countQuadsToTri);  
}
  
