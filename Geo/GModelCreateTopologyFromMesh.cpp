#include <stack> 
#include <set> 
#include <map> 
#include "GModelCreateTopologyFromMesh.h"
#include "GModel.h"
#include "Geo.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "MPoint.h"
#include "MVertex.h"
#include "MLine.h"
#include "MEdge.h"
#include "MFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"

/*
  Assumptions :       
      --> The input mesh is potentially (partially) coloured 
      --> 
*/

template <class T>
class myBundle {
public : 
  std::set<T> stuff;
  void insert (T t) {stuff.insert(t);}
  void print() const {
    printf("bundle of %ld entities\n",stuff.size());
    for (typename std::set<T>::iterator it = stuff.begin(); it != stuff.end() ; ++it){
      printf ("%d ",(*it)->tag());
    }
    printf("\n");
  }
  bool operator  < (const myBundle<T> & other) const{
    if (other.stuff.size() < stuff.size()) return true;
    if (other.stuff.size() > stuff.size()) return false;
    typename std::set<T>::const_iterator it  = stuff.begin();
    typename std::set<T>::const_iterator it2 = other.stuff.begin();
    for ( ; it != stuff.end() ; ++it, ++it2){
      if (*it < *it2) return true;
      if (*it > *it2) return false;
    }
    return false;
  }  
};


bool topoExists (GModel *gm) {
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  std::set<MVertex*> vs;
  for(unsigned int i = 0; i < entities.size(); i++){
    if (entities[i]->vertices().empty()) return false;
  }
  
  return true;
}

void createTopologyFromMesh1D ( GModel *gm , int &num) {

  std::map<MVertex*, myBundle<GEdge*> > _temp;
  std::set<myBundle<GEdge*> > _bundles;
  std::map<MVertex*, GVertex*> _existingVertices;
  std::map<GEdge*, std::set<GVertex*> > _topology;
  
  // create an inverse dictionnary for existing edges
  //  printf("zakkkk\n");

  for(GModel::viter it = gm->firstVertex(); it != gm->lastVertex(); it++) {
    if ((*it)->mesh_vertices.size())
      _existingVertices[(*it)->mesh_vertices[0]] = *it;
  }    

  //  printf("%d mesh vertices are already classified\n",_existingVertices.size());

  
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    for (int i=0;i<(*it)->lines.size();i++){
      MLine *e = (*it)->lines[i];
      for (int j=0;j<2;j++){
	MVertex* v = e->getVertex(j);
	GVertex *gv = _existingVertices[v];
	if (gv)
	  _topology[*it].insert(gv);
	else
	  _temp[v].insert(*it);
      }      
    }    
  }

  //  printf("%d new mesh vertices \n",_temp.size());

  // create unique instances
  for (std::map<MVertex*, myBundle<GEdge*> >::iterator it = _temp.begin(); it != _temp.end() ; it++){    
    if (it->second.stuff.size() > 1) {
      //      it->second.print();
      num++;
      discreteVertex *dv = new discreteVertex (  gm , GModel::current()->getGEOInternals()->MaxPointNum++);    
      gm->add(dv);
      MVertex *v = it->first;
      MPoint *mp = new MPoint(v);
      dv->points.push_back(mp);
      for (std::set<GEdge*>::iterator it2 = it->second.stuff.begin(); it2 != it->second.stuff.end() ; ++it2){
	_topology[*it2].insert(dv);
      }
    }
  }

  // create Edge 2 Vertex topology
  {
    std::map<GEdge*, std::set<GVertex*> >::iterator it =  _topology.begin();
    for ( ; it != _topology.end() ; ++it){
      std::list<GVertex*> l ; l.insert (l.begin(), it->second.begin(), it->second.end());
      if (l.size() == 0){
      }
      else if (l.size() <= 2){
	std::list<GVertex*>::iterator it2 = l.begin();
	it->first->setBeginVertex(*it2);
	if (l.size() == 2)++it2;
	it->first->setEndVertex(*it2);	
      }
      else {
	Msg::Error ("FIXME : create simply connected edges in CreateTopology");
      }
      
      for (std::list<GVertex*>::iterator it2 =  l.begin() ; it2 != l.end() ; ++it2)(*it2)->addEdge(it->first);      
    }
  }


  // NICE :-)
}

void assignFace (GFace *gf, std::set<MElement*> &_f) {

  gf->triangles.clear();
  gf->quadrangles.clear();
  for (std::set<MElement*> :: iterator it = _f.begin() ; it != _f.end() ; ++it) {
    if ((*it)->getNumVertices () == 3) gf->triangles.push_back ((MTriangle*) *it);
    else if ((*it)->getNumVertices () == 4) gf->quadrangles.push_back ((MQuadrangle*) *it);
  }
  
}


void ensureManifoldFace ( GFace *gf) {
  
  std::map<MEdge, std::pair<MElement*,MElement*>, Less_Edge > _pairs;  
  std::set<MEdge,Less_Edge> _nonManifold;

  std::set<MElement*> _allFaces;
  
  for (int i=0;i<gf->getNumMeshElements();i++){
    MElement *e = gf->getMeshElement(i);
    _allFaces.insert(e);
    for (int j=0;j<e->getNumEdges();j++){
      MEdge ed = e->getEdge(j);
      if (_nonManifold.find (ed) == _nonManifold.end() ){
	std::map<MEdge, std::pair<MElement*,MElement*>, Less_Edge >::iterator it =
	  _pairs.find (ed);
	if (it == _pairs.end()){
	  _pairs[ed] = std::make_pair ( e , (MElement*) NULL);
	}
	else {
	  if (it->second.second == NULL){
	    it->second.second = e;
	  }
	  else {
	    _nonManifold.insert (ed);
	    _pairs.erase (it);
	  }
	}
      }
    }
  }
  if (_nonManifold.empty())return;

  Msg::Info ("Face %d is not manifold : splitting it",gf->tag());
  
  //  printf("%d non man %d internal\n",_nonManifold.size(), _pairs.size()); 
  
  std::vector<std::set<MElement *> > _sub;
  while (!_allFaces.empty()) {
    std::stack <MElement*> _stack;
    _stack.push (*_allFaces.begin());
    std::set<MElement*> _f;
    while (!_stack.empty()){
      MElement *e = _stack.top();
      _allFaces.erase(e);
      _stack.pop();
      _f.insert (e);
      for (int j=0;j<e->getNumEdges();j++){
	MEdge ed = e->getEdge(j);
	if (_nonManifold.find (ed) == _nonManifold.end() ){
	  std::map<MEdge, std::pair<MElement*,MElement*>, Less_Edge >::iterator it =
	    _pairs.find (ed);
	  if (it->second.second != NULL){
	    MElement *other  = it->second.second == e ? it->second.first : it->second.second; 
	    if (_f.find (other) == _f.end())_stack.push(other);
	  }
	}
      }
    }
    _sub.push_back (_f);        
  }

  Msg::Info ("Face %d has now %d parts",gf->tag(),_sub.size() );
  //  printf("%d sub parts\n", _sub.size());
  
  for (unsigned int i=0 ; i<_sub.size() ; i++){
    if (i == 0) assignFace (gf, _sub[i]);
    else {
      discreteFace *newF = new discreteFace (gf->model(), NEWREG());
      gf->model()->add (newF);
      assignFace (newF, _sub[i]);
    }
  }  
}

void ensureManifoldFaces ( GModel *gm ) {
  //  printf ("%d faces\n", gm->getNumFaces());
  std::vector<GFace*> f;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++)f.push_back(*it);
  for(unsigned int i=0;i<f.size(); i++)ensureManifoldFace (f[i]);
}

void createTopologyFromMesh2D ( GModel *gm , int & num) {


  std::map<MEdge, myBundle<GFace*>, Less_Edge > _temp;
  std::set<myBundle<GFace*> > _bundles;
  std::map<MEdge, GEdge*, Less_Edge> _existingEdges;
  std::map<GFace*, std::set<GEdge*> > _topology;
  
  // create an inverse dictionnary for existing edges
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    for (int i = 0; i < (*it)->lines.size(); i++)_existingEdges[(*it)->lines[i]->getEdge(0)] = *it;
  }    

  //  printf("%d mesh edges are already classified\n",_existingEdges.size());

  std::map<MEdge,int,Less_Edge> _bnd;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumEdges();j++){
	MEdge ed = e->getEdge(j);
	std::map<MEdge,int,Less_Edge>::iterator it2 = _bnd.find(ed);	
	if (it2 == _bnd.end())_bnd[ed] = 1;
	else it2->second++;
      }
    }
  }

  discreteFace OUT (gm, -1000010200);
  
  // create inverse dictionary for all other edges
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumEdges();j++){
	MEdge ed = e->getEdge(j);
	GEdge *ge = _existingEdges[ed];
	if (ge)
	  _topology[*it].insert(ge);
	else {
	  _temp[ed].insert(*it);
	  if (_bnd[ed] == 1)_temp[ed].insert(&OUT);
	}
      }      
    }    
  }

  //  printf("%d internal edges\n",_temp.size());
  
  // create unique instances
  for (std::map<MEdge, myBundle<GFace*>, Less_Edge >::iterator it = _temp.begin(); it != _temp.end() ; it++){
    _bundles.insert (it->second);
  }

  // create discrete edges  
  std::map <myBundle<GFace*> , GEdge *> _f2e;
  {
    std::set<myBundle<GFace*> >::iterator it = _bundles.begin();
    for (; it != _bundles.end(); ++it) {
      ///      it->print();
      if (it->stuff.size() > 1){
	//	printf("creation of a new discrete edge (%d neighbors)!\n",it->stuff.size());
	discreteEdge *de = new discreteEdge (  gm , NEWREG(), NULL, NULL);    
	num++;
	_f2e [*it] = de;
	gm->add (de);
	for (std::set<GFace*>::iterator it2 = it->stuff.begin(); it2 != it->stuff.end();++it2){
	  if ((*it2) != &OUT)_topology[*it2].insert(de);
	  //	  else printf("on the boundary\n");
	}
      }
    }
  }

  //  create the 1D mesh
  {
    std::map<MEdge, myBundle<GFace*>, Less_Edge > :: iterator it = _temp.begin();
    for (; it != _temp.end(); ++it) {
      if (it->second.stuff.size() > 1){
	MEdge e = it->first;
	GEdge *ge = _f2e [it->second];
	// not yet bounded
	MLine *l = new MLine (e.getVertex(0),e.getVertex(1));
	ge->lines.push_back(l);
      }
    }
  }

  // create Face 2 Edge topology
  {
    std::map<GFace*, std::set<GEdge*> >::iterator it =  _topology.begin();
    for ( ; it != _topology.end() ; ++it){
      if (it->first){
	std::list<GEdge*> l ; l.insert (l.begin(), it->second.begin(), it->second.end());
	it->first->set(l);
	//	printf("Face %d has %d edges\n",it->first->tag(), l.size());
	for (std::list<GEdge*>::iterator it2 =  l.begin() ; it2 != l.end() ; ++it2)(*it2)->addFace(it->first);
      }
    }
  }  
  
  // NICE :-)
}

// home made hash table

/// ----------------------------------------------------------------
/// ---------------   3D         -----------------------------------
/// ----------------------------------------------------------------

void createTopologyFromMesh3D ( GModel *gm , int &num ) {
  
  std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face > _temp;
  std::set<std::pair<GRegion*,GRegion*> > _pairs;
  std::map<MFace, GFace*, Less_Face> _existingFaces;
  std::map<GRegion*, std::set<GFace*> > _topology;

  clock_t t0 = clock();
  // create an inverse dictionnary for existing faces
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++)_existingFaces[(*it)->triangles[i]->getFace(0)] = *it;
    for (unsigned int i = 0; i < (*it)->quadrangles.size(); i++)_existingFaces[(*it)->quadrangles[i]->getFace(0)] = *it;
  }    

  //  printf("%d mesh faces aere already classified\n",_existingFaces.size());
  
  clock_t t1 = clock();
  // --------------------------------------------------------------------------------------------------
  // create inverse dictionary for all other faces
  // This is the most time consuming part !
  // --------------------------------------------------------------------------------------------------

  for(GModel::riter it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    for (int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumFaces();j++){
      }
    }
  }
  

  for(GModel::riter it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    for (int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumFaces();j++){
	MFace f = e->getFace(j);
	GFace *gf = _existingFaces[f];
	if (gf){
	  _topology[*it].insert(gf);
	}
	else  {
	  std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face >::iterator itf = _temp.find(f);
	  if (itf == _temp.end()){
	    _temp[f] = std::make_pair ( (GRegion*)NULL, *it) ;
	  }
	  else {
	    if (*it == itf->second.second)_temp.erase (itf);
	    else itf->second.first = *it ;
	  }
	}
      }      
    }
  }
  // --------------------------------------------------------------------------------------------------
  
  clock_t t2 = clock();

  // create unique instances
  for (std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face >::iterator it = _temp.begin(); it != _temp.end() ; it++){
    _pairs.insert (std::make_pair (std::min (it->second.first, it->second.second),
				   std::max (it->second.first, it->second.second)));
  }    
  
  // create discrete faces
  
  //  printf("%d pairs of regions exist to create new GFaces \n",_pairs.size());
  clock_t t3 = clock();

  std::map <std::pair<GRegion*,GRegion*> , GFace *> _r2f;
  {
    std::set<std::pair<GRegion*,GRegion*> >::iterator it = _pairs.begin();
    for (; it != _pairs.end(); ++it) {
      if (it->first != it->second) {
	printf("creating a new discrete face between %p and %p\n",it->first, it->second);
	discreteFace *df = new discreteFace (  gm , NEWREG());    
	num++;
	gm->add (df);
	_r2f [*it] = df;
	if (it->first)_topology[it->first].insert(df);
	if (it->second)_topology[it->second].insert(df);
      }
    }
  }
  clock_t t4 = clock();

  //  add mesh faces in newly created GFaces
  {
    std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face > :: iterator it = _temp.begin();
    for (; it != _temp.end(); ++it) {
      if (it->second.first != it->second.second){
	MFace f = it->first;      
	GFace *gf = _r2f [it->second];
	if (f.getNumVertices () == 3){
	  MTriangle *t = new MTriangle (f.getVertex(0),f.getVertex(1),f.getVertex(2));
	  gf->triangles.push_back(t);
	  _existingFaces [t->getFace(0)] = gf;
	}
	else if (f.getNumVertices () == 4){
	  MQuadrangle *q = new MQuadrangle (f.getVertex(0),f.getVertex(1),f.getVertex(2),f.getVertex(3));
	  gf->quadrangles.push_back(q);	 
	  _existingFaces [q->getFace(0)] = gf;
	}
      }
    }
  }  
  clock_t t5 = clock();

  // create Regions 2 Faces topology
  {
    std::map<GRegion*, std::set<GFace*> >::iterator it =  _topology.begin();
    for ( ; it != _topology.end() ; ++it){
      std::list<GFace*> l ; l.insert (l.begin(), it->second.begin(), it->second.end());
      it->first->set(l);
      //      printf("Region %d has %d adjacent faces\n",it->first->tag(), l.size());
      for (std::list<GFace*>::iterator it2 =  l.begin() ; it2 != l.end() ; ++it2)(*it2)->addRegion(it->first);      
    }
  }
  clock_t t6 = clock();

  // NICE :-)

  printf("%g %g %g %g %g %g\n",(double)(t1-t0)/CLOCKS_PER_SEC,(double)(t2-t1)/CLOCKS_PER_SEC,(double)(t3-t2)/CLOCKS_PER_SEC
	 ,(double)(t4-t3)/CLOCKS_PER_SEC,(double)(t5-t4)/CLOCKS_PER_SEC,(double)(t6-t5)/CLOCKS_PER_SEC);

  
}

void GModel::createTopologyFromMeshNew ( ) {
  const int dim = getDim ();    

  
  if (topoExists (this)) {
    return;
  }

  //  printf("%d vertices\n", getNumVertices());
  Msg::Info("createTopologyFromMeshNew --> creating a topology from the mesh");
  int numF=0,numE=0,numV=0;
  clock_t t0 = clock();
  if (dim >= 3) createTopologyFromMesh3D (this, numF);
  else ensureManifoldFaces ( this );
  clock_t t1 = clock();
  if (dim >= 2) createTopologyFromMesh2D ( this , numE);
  clock_t t2 = clock();
  if (dim >= 1) createTopologyFromMesh1D ( this, numV);
  clock_t t3 = clock();
  //  printf("%d vertices\n", getNumVertices());

  //  printf("coucou\n");

  
  _associateEntityWithMeshVertices();
  
  std::vector<GEntity*> entities;
  getEntities(entities);
  std::set<MVertex*> vs;
  for(unsigned int i = 0; i < entities.size(); i++){
    vs.insert (entities[i]->mesh_vertices.begin(), entities[i]->mesh_vertices.end());
    entities[i]->mesh_vertices.clear();
  }
  std::vector<MVertex*> cc;
  cc.insert(cc.begin(), vs.begin(), vs.end());
  _storeVerticesInEntities(cc); 

  //  printf("%d vertices\n", getNumVertices());
  
  Msg::Info("createTopologyFromMeshNew (%d regions,  %d faces (%d new) , %d edges (%d new) and %d vertices (%d new))",
	    getNumRegions(),  getNumFaces(), numF, getNumEdges(), numE, getNumVertices(), numV);

  printf("%g %g %g\n",(double)(t1-t0)/CLOCKS_PER_SEC,(double)(t2-t1)/CLOCKS_PER_SEC,(double)(t3-t2)/CLOCKS_PER_SEC);
  
}
