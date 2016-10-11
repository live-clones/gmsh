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


void createTopologyFromMesh1D ( GModel *gm ) {
  std::map<MVertex*, myBundle<GEdge*> > _temp;
  std::set<myBundle<GEdge*> > _bundles;
  std::map<MVertex*, GVertex*> _existingVertices;
  std::map<GEdge*, std::set<GVertex*> > _topology;
  
  // create an inverse dictionnary for existing edges
  for(GModel::viter it = gm->firstVertex(); it != gm->lastVertex(); it++) {
    _existingVertices[(*it)->mesh_vertices[0]] = *it;
  }    

  //  printf("%ud mesh vertices are already classified\n",_existingVertices.size());

  
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
    _bundles.insert (it->second);
  }

  //  printf("%d bundles\n",_bundles.size());

  
  // create discrete edges

  std::map <myBundle<GEdge*> , GVertex *> _e2v;
  {
    std::set<myBundle<GEdge*> >::iterator it = _bundles.begin();
    for (; it != _bundles.end(); ++it) {
      if (it->stuff.size() > 1) {
	discreteVertex *dv = new discreteVertex (  gm , NEWPOINT());    
	_e2v [*it] = dv;
	for (std::set<GEdge*>::iterator it2 = it->stuff.begin(); it2 != it->stuff.end() ; ++it2){
	  _topology[*it2].insert(dv);
	}
      }
    }
  }

  //  create the 0D mesh
  {
    std::map<MVertex*, myBundle<GEdge*> > :: iterator it = _temp.begin();
    for (; it != _temp.end(); ++it) {
      if (it->second.stuff.size() > 1) {
	MVertex *v = it->first;
	GVertex *gv = _e2v [it->second];
	gv->mesh_vertices.push_back(v);
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

void createTopologyFromMesh2D ( GModel *gm ) {

  std::map<MEdge, myBundle<GFace*>, Less_Edge > _temp;
  std::set<myBundle<GFace*> > _bundles;
  std::map<MEdge, GEdge*, Less_Edge> _existingEdges;
  std::map<GFace*, std::set<GEdge*> > _topology;
  
  // create an inverse dictionnary for existing edges
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    for (int i = 0; i < (*it)->lines.size(); i++)_existingEdges[(*it)->lines[i]->getEdge(0)] = *it;
  }    

  printf("%d mesh edges are already classified\n",_existingEdges.size());

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

  discreteFace OUT (gm, 1000010200);
  
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

  printf("%d internal edges\n",_temp.size());
  
  // create unique instances
  for (std::map<MEdge, myBundle<GFace*>, Less_Edge >::iterator it = _temp.begin(); it != _temp.end() ; it++){
    _bundles.insert (it->second);
  }

  // create discrete edges  
  std::map <myBundle<GFace*> , GEdge *> _f2e;
  {
    std::set<myBundle<GFace*> >::iterator it = _bundles.begin();
    for (; it != _bundles.end(); ++it) {
      //      it->print();
      if (it->stuff.size() > 1){
	printf("creation of a new discrete edge (%d neighbors)!\n",it->stuff.size());
	discreteEdge *de = new discreteEdge (  gm , NEWREG(), NULL, NULL);    
	_f2e [*it] = de;
	for (std::set<GFace*>::iterator it2 = it->stuff.begin(); it2 != it->stuff.end();++it2)
	  if ((*it2) != &OUT)_topology[*it2].insert(de);
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
	for (int i=0;i<e.getNumVertices ();i++)e.getVertex(i)->setEntity(ge);
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
	//      printf("Face %d has %d edges\n",it->first->tag(), l.size());
	for (std::list<GEdge*>::iterator it2 =  l.begin() ; it2 != l.end() ; ++it2)(*it2)->addFace(it->first);
      }
    }
  }

  
  // NICE :-)
}

/// ----------------------------------------------------------------
/// ---------------   3D         -----------------------------------
/// ----------------------------------------------------------------

void createTopologyFromMesh3D ( GModel *gm ) {
  
  std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face > _temp;
  std::set<std::pair<GRegion*,GRegion*> > _pairs;
  std::map<MFace, GFace*, Less_Face> _existingFaces;
  std::map<GRegion*, std::set<GFace*> > _topology;

  // create an inverse dictionnary for existing faces
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++)_existingFaces[(*it)->triangles[i]->getFace(0)] = *it;
    for (unsigned int i = 0; i < (*it)->quadrangles.size(); i++)_existingFaces[(*it)->quadrangles[i]->getFace(0)] = *it;
  }    

  //  printf("%d mesh faces aere already classified\n",_existingFaces.size());
  
  // create inverse dictionary for all other faces
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
	    itf->second.first = *it ;
	  }
	}
      }      
    }
  }
  
  //  printf("%d new mesh faces \n",_temp.size());

  // create unique instances
  for (std::map<MFace, std::pair<GRegion*,GRegion*>, Less_Face >::iterator it = _temp.begin(); it != _temp.end() ; it++){
    _pairs.insert (std::make_pair (std::min (it->second.first, it->second.second),
				   std::max (it->second.first, it->second.second)));
  }    
  
  // create discrete faces
  
  //  printf("%d pairs of regions exist to create new GFaces \n",_pairs.size());

  std::map <std::pair<GRegion*,GRegion*> , GFace *> _r2f;
  {
    std::set<std::pair<GRegion*,GRegion*> >::iterator it = _pairs.begin();
    for (; it != _pairs.end(); ++it) {
      if (it->first != it->second) {
	printf("creating a new discrete face between %p and %p\n",it->first, it->second);
	discreteFace *df = new discreteFace (  gm , NEWREG());    
	_r2f [*it] = df;
	if (it->first)_topology[it->first].insert(df);
	if (it->second)_topology[it->second].insert(df);
      }
    }
  }

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
	}
	else if (f.getNumVertices () == 4){
	  MQuadrangle *q = new MQuadrangle (f.getVertex(0),f.getVertex(1),f.getVertex(2),f.getVertex(3));
	  gf->quadrangles.push_back(q);	 
	}
	for (int i=0;i<f.getNumVertices ();i++)f.getVertex(i)->setEntity(gf);
      }
    }
  }  
  
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
  
  // NICE :-)
  
}

void createTopologyFromMeshNew ( GModel *gm ) {
  const int dim = gm->getDim ();    
  if (dim >= 3) createTopologyFromMesh3D (gm);
  if (dim >= 2) createTopologyFromMesh2D (gm);
  if (dim >= 1) createTopologyFromMesh1D (gm);
  Msg::Info("createTopologyFromMeshNew (%d regions %d faces and %d edges)",gm->getNumRegions(),  gm->getNumFaces(), gm->getNumEdges());

}
