// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stack>
#include <set>
#include <map>
#include "OS.h"
#include "GModelCreateTopologyFromMesh.h"
#include "GModel.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "MPoint.h"
#include "MVertex.h"
#include "MLine.h"
#include "MEdge.h"
#include "MFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"

// Assumption: The input mesh is potentially (partially) coloured

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

bool topoExists(GModel *gm)
{
  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  std::set<MVertex*> vs;
  for(unsigned int i = 0; i < entities.size(); i++){
    if (entities[i]->vertices().empty()) return false;
  }
  return true;
}

void createTopologyFromMesh1D(GModel *gm, int &num)
{
  std::map<MVertex*, myBundle<GEdge*> > _temp;
  std::set<myBundle<GEdge*> > _bundles;
  std::map<MVertex*, GVertex*> _existingVertices;
  std::map<GEdge*, std::set<GVertex*> > _topology;

  // create an inverse dictionnary for existing edges

  for(GModel::viter it = gm->firstVertex(); it != gm->lastVertex(); it++) {
    if ((*it)->mesh_vertices.size())
      _existingVertices[(*it)->mesh_vertices[0]] = *it;
  }

  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    for (unsigned int i=0;i<(*it)->lines.size();i++){
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

  // create unique instances
  for(std::map<MVertex*, myBundle<GEdge*> >::iterator it = _temp.begin();
      it != _temp.end() ; it++){
    if (it->second.stuff.size() > 1) {
      num++;
      discreteVertex *dv = new discreteVertex(gm, gm->getMaxElementaryNumber(0) + 1);
      gm->add(dv);
      MVertex *v = it->first;
      MPoint *mp = new MPoint(v);
      dv->points.push_back(mp);
      for (std::set<GEdge*>::iterator it2 = it->second.stuff.begin();
           it2 != it->second.stuff.end() ; ++it2){
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
	Msg::Error("FIXME: create simply connected edges in CreateTopology "
                   "(%d vertices bounding one GEdge)", l.size());
      }

      for (std::list<GVertex*>::iterator it2 =  l.begin(); it2 != l.end(); ++it2)
        (*it2)->addEdge(it->first);
    }
  }

  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    if (!(*it)->getBeginVertex() && !(*it)->getEndVertex()){
      num++;
      discreteVertex *dv = new discreteVertex(gm, gm->getMaxElementaryNumber(0) + 1);
      gm->add(dv);
      MVertex *v = (*it)->lines[0]->getVertex(0);
      MPoint *mp = new MPoint(v);
      dv->points.push_back(mp);
      dv->addEdge (*it);
      (*it)->setBeginVertex(dv);
      (*it)->setEndVertex(dv);
      _topology[*it].insert(dv);
    }
  }
}

void assignFace (GFace *gf, std::set<MElement*> &_f)
{
  gf->triangles.clear();
  gf->quadrangles.clear();
  for (std::set<MElement*> :: iterator it = _f.begin() ; it != _f.end() ; ++it) {
    if ((*it)->getNumVertices () == 3) gf->triangles.push_back ((MTriangle*) *it);
    else if ((*it)->getNumVertices () == 4) gf->quadrangles.push_back ((MQuadrangle*) *it);
  }
}

void ensureManifoldFace(GFace *gf)
{
  std::map<MEdge, std::pair<MElement*,MElement*>, Less_Edge > _pairs;
  std::set<MEdge,Less_Edge> _nonManifold;

  std::set<MElement*> _allFaces;

  for (unsigned int i = 0; i < gf->getNumMeshElements(); i++){
    MElement *e = gf->getMeshElement(i);
    _allFaces.insert(e);
    for (int j = 0; j < e->getNumEdges(); j++){
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
	    MElement *other = it->second.second == e ?
              it->second.first : it->second.second;
	    if (_f.find (other) == _f.end())_stack.push(other);
	  }
	}
      }
    }
    _sub.push_back (_f);
  }

  Msg::Info ("Face %d is non-manifold: splitting it in %d parts",
             gf->tag(), _sub.size());

  for (unsigned int i=0 ; i<_sub.size() ; i++){
    if (i == 0) assignFace (gf, _sub[i]);
    else {
      discreteFace *newF = new discreteFace
        (gf->model(), gf->model()->getMaxElementaryNumber(2) + 1);
      gf->model()->add (newF);
      assignFace (newF, _sub[i]);
    }
  }
}

void ensureManifoldFaces(GModel *gm)
{
  std::vector<GFace*> f;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++)
    f.push_back(*it);
  for(unsigned int i = 0; i < f.size(); i++)
    ensureManifoldFace (f[i]);
}

// FIXME : 2 TIMES THE SAME MLINE IN EACH CONNECTED PART IF PERIODIC
std::vector<GEdge*> ensureSimplyConnectedEdge(GEdge *ge)
{
  std::vector<GEdge*> _all;
  std::set<MLine*> _lines;
  std::map<MVertex*, std::pair<MLine*,MLine*> > _conn;

  _all.push_back(ge);

  // create vertex to edge connectivity : only 2 neighbors are considered ...
  for (unsigned int i = 0; i < ge->lines.size(); i++){
    _lines.insert(ge->lines[i]);
    for (int j=0;j<2;j++){
      std::map<MVertex*, std::pair<MLine*,MLine*> >::iterator it =
        _conn.find(ge->lines[i]->getVertex(j));
      if (it == _conn.end())
	_conn[ge->lines[i]->getVertex(j)]= std::make_pair (ge->lines[i], (MLine*)NULL);
      else
	it->second.second = ge->lines[i];
    }
  }

  std::vector <std::vector <MLine*> > _parts;
  while (!_lines.empty()){
    std::stack<MLine*> _stack;
    _stack.push(*_lines.begin());
    std::vector<MLine*> _part;
    while (!_stack.empty()){
      MLine *l = _stack.top();
      _stack.pop();
      _lines.erase (l);
      // avoid adding twice the last one
      if (!_part.size()  || _part[_part.size() - 1] != l){
	_part.push_back(l);
      }
      for (int j=0;j<2;j++){
	std::map<MVertex*, std::pair<MLine*,MLine*> >::iterator it =
          _conn.find(l->getVertex(j));
	if (it->second.first == l && it->second.second != NULL &&
            _lines.find (it->second.second) != _lines.end()){
	  _stack.push (it->second.second);
	}
	else if (it->second.second == l &&
                 _lines.find (it->second.first) != _lines.end()){
	  _stack.push (it->second.first);
	}
      }
    }
    _parts.push_back(_part);
  }

  if (_parts.size() == 1) return _all;

  Msg::Info ("Edge %d is not simply connected: splitting it in %d parts",
             ge->tag(),_parts.size());

  for (size_t i = 0; i < _parts.size() ; i++){
    if (i == 0)ge->lines = _parts[i];
    else {
      discreteEdge *newE = new discreteEdge
        (ge->model(), ge->model()->getMaxElementaryNumber(1) + 1, NULL, NULL);
      ge->model()->add (newE);
      newE->lines = _parts[i];
      _all.push_back(newE);
    }
  }
  return _all;
}

void createTopologyFromMesh2D(GModel *gm, int &num)
{
  std::map<MEdge, myBundle<GFace*>, Less_Edge > _temp;
  std::set<myBundle<GFace*> > _bundles;
  std::map<MEdge, GEdge*, Less_Edge> _existingEdges;
  std::map<GFace*, std::set<GEdge*> > _topology;

  // create an inverse dictionnary for existing edges
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    for (unsigned int i = 0; i < (*it)->lines.size(); i++)
      _existingEdges[(*it)->lines[i]->getEdge(0)] = *it;
  }

  std::map<MEdge,int,Less_Edge> _bnd;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (unsigned int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumEdges();j++){
	MEdge ed = e->getEdge(j);
	std::map<MEdge,int,Less_Edge>::iterator it2 = _bnd.find(ed);
	if (it2 == _bnd.end())_bnd[ed] = 1;
	else it2->second++;
      }
    }
  }

  discreteFace *OUT = NULL;

  // create inverse dictionary for all other edges
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (unsigned int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumEdges();j++){
	MEdge ed = e->getEdge(j);
	GEdge *ge = _existingEdges[ed];
	if (ge)
	  _topology[*it].insert(ge);
	else {
	  _temp[ed].insert(*it);
	  if (_bnd[ed] == 1)_temp[ed].insert(OUT);
	}
      }
    }
  }

  // create unique instances
  for (std::map<MEdge, myBundle<GFace*>, Less_Edge >::iterator it = _temp.begin();
       it != _temp.end() ; it++){
    _bundles.insert (it->second);
  }

  // create discrete edges
  std::map <myBundle<GFace*> , GEdge *> _f2e;
  {
    std::set<myBundle<GFace*> >::iterator it = _bundles.begin();
    for (; it != _bundles.end(); ++it) {
      if (it->stuff.size() > 1){
	discreteEdge *de = new discreteEdge
          (gm, gm->getMaxElementaryNumber(1) + 1, NULL, NULL);
	num++;
	_f2e [*it] = de;
	gm->add (de);
	for (std::set<GFace*>::iterator it2 = it->stuff.begin(); it2 != it->stuff.end();++it2){
	  if ((*it2) != OUT)_topology[*it2].insert(de);
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


  std::map<GEdge*, std::vector<GEdge*> > _parts;
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    _parts[*it] = ensureSimplyConnectedEdge (*it);
  }

  // create Face 2 Edge topology
  {
    std::map<GFace*, std::set<GEdge*> >::iterator it =  _topology.begin();
    for ( ; it != _topology.end() ; ++it){
      if (it->first){
	std::list<GEdge*> l ;
	for (std::set<GEdge*>::iterator it2 = it->second.begin();
             it2 != it->second.end() ; ++it2)
	  l.insert (l.begin(), _parts[*it2].begin(),  _parts[*it2].end());
	it->first->set(l);
	for (std::list<GEdge*>::iterator it2 =  l.begin() ; it2 != l.end(); ++it2)
          (*it2)->addFace(it->first);
      }
    }
  }
}

class topoFace {
public:
  MVertex *v[4];
  MVertex *getVertex (int i) const {return v[i];}
  MVertex *getSortedVertex (int i) const {return v[i];}
  int getNumVertices() const {return v[3]? 4:3;}
  inline bool operator == (const topoFace &f) const
  {
    if (v[0] != f.v[0])return false;
    if (v[1] != f.v[1])return false;
    if (v[2] != f.v[2])return false;
    return true;
  }
  inline bool operator < (const topoFace &f) const
  {
    if (v[0] < f.v[0])return true;
    if (v[0] > f.v[0])return false;
    if (v[1] < f.v[1])return true;
    if (v[1] > f.v[1])return false;
    if (v[2] < f.v[2])return true;
    return false;
  }
  inline void sortVerts3 ()
  {
    MVertex *tmp;
    if(v[0]>v[1]){
      tmp = v[0];
      v[0] = v[1];
      v[1] = tmp;
    }
    if(v[0]>v[2]){
      tmp = v[0];
      v[0]=v[2];
      v[2] = tmp;
    }
    if(v[1]>v[2]){
      tmp = v[1];
      v[1]=v[2];
      v[2]=tmp;
    }
    return;
  }
  topoFace (MVertex *v1, MVertex *v2, MVertex *v3)
  {
    v[0]=v1; v[1]=v2; v[2]=v3;v[3] = NULL;
    sortVerts3();
  }
};

#ifdef _USE_MFACE__
typedef class  MFace MYFACE;
#else
typedef class  topoFace MYFACE;
#endif

template <class T>
class hashMapTopoFace {
  std::vector<std::vector<std::pair<MYFACE, T> > > _data;
public:
  hashMapTopoFace (int N) {
    _data.resize (std::max(N,2));
  }

  size_t N() const {return _data.size();}

  typename std::vector<std::pair<MYFACE, T> >::iterator begin(int i)
  {
    return _data[i].begin();
  }
  typename std::vector<std::pair<MYFACE, T> >::iterator end  (int i)
  {
    return _data[i].end();
  }

  void addNoTest (const MYFACE &t, const T& toAdd)
  {
    size_t h = ((size_t) t.getSortedVertex(0) >> 8) ;
    size_t POS = h % _data.size();
    _data[POS].push_back(std::make_pair(t,toAdd));
  }

  T & find (const MYFACE &t, bool &found)
  {
    size_t h = ((size_t) t.getSortedVertex(0) >> 8) ;
    size_t POS = h % _data.size();
    std::vector<std::pair<MYFACE, T> > &v = _data[POS];
    for (unsigned int i=0; i< v.size();i++){
      if (t == v[i].first){
	found = true;
	return v[i].second;
      }
    }
    found = false;
    // bad design of this routine
    return v[0].second;
  }
};

inline MYFACE builder (MElement *e, int num)
{
#ifdef _USE_MFACE__
  return e->getFace(num);
#else
  if (e->getType() == TYPE_TET){
    return topoFace (e->getVertex (MTetrahedron::faces_tetra(num, 0)),
		     e->getVertex (MTetrahedron::faces_tetra(num, 1)),
		     e->getVertex (MTetrahedron::faces_tetra(num, 2)));
  }
  if (e->getType() == TYPE_TRI){
    return topoFace (e->getVertex (0),
		     e->getVertex (1),
		     e->getVertex (2));
  }
  Msg::Fatal("JF : finish the code of createtopologyfrommesh");
  return topoFace (e->getVertex (0),
                   e->getVertex (1),
                   e->getVertex (2));
#endif
}

void createTopologyFromMesh3D(GModel *gm, int &num)
{
  std::set<std::pair<GRegion*,GRegion*> > _pairs;
  hashMapTopoFace<GFace*> _existingFaces(gm->getNumMeshVertices()/10);
  hashMapTopoFace< std::pair<GRegion*,GRegion*> > _temp(gm->getNumMeshVertices()/3);
  std::map<GRegion*, std::set<GFace*> > _topology;

  // create an inverse dictionnary for existing faces
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++) {
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      _existingFaces.addNoTest (builder((*it)->triangles[i], 0), *it);
    }
    for (unsigned int i = 0; i < (*it)->quadrangles.size(); i++){
      _existingFaces.addNoTest (builder((*it)->quadrangles[i], 0), *it);
    }
  }

  // create inverse dictionary for all other faces
  // This is the most time consuming part !

  for(GModel::riter it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    for (unsigned int i=0;i<(*it)->getNumMeshElements();i++){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumFaces();j++){
	MYFACE f = builder(e,j);
	bool found;
	GFace *gf = _existingFaces.find (f,found);
	if (found){
	  _topology[*it].insert(gf);
	}
	else  {
	  std::pair<GRegion*,GRegion*> &myPair = _temp.find (f,found);
	  if (!found){
	    _temp.addNoTest (f, std::make_pair ( (GRegion*)NULL, *it) );
	  }
	  else {
	    myPair.first = *it ;
	  }
	}
      }
    }
  }

  // create unique instances
  for (size_t K=0;K<_temp.N();K++){
    for (std::vector<std::pair<MYFACE, std::pair<GRegion*,GRegion*> > >::iterator it =
           _temp.begin(K); it != _temp.end(K) ; it++){
      _pairs.insert (std::make_pair (std::min (it->second.first, it->second.second),
				     std::max (it->second.first, it->second.second)));
    }
  }

  // create discrete faces
  std::map <std::pair<GRegion*,GRegion*> , GFace *> _r2f;
  {
    std::set<std::pair<GRegion*,GRegion*> >::iterator it = _pairs.begin();
    for (; it != _pairs.end(); ++it) {
      if (it->first != it->second) {
	discreteFace *df = new discreteFace(gm, gm->getMaxElementaryNumber(2) + 1);
	num++;
	gm->add (df);
	_r2f [*it] = df;
	if (it->first)_topology[it->first].insert(df);
	if (it->second)_topology[it->second].insert(df);
      }
    }
  }

  //  add mesh faces in newly created GFaces
  for (size_t K=0;K<_temp.N();K++){
    std::vector<std::pair< MYFACE, std::pair<GRegion*,GRegion*> > > :: iterator it =
      _temp.begin(K);
    for (; it != _temp.end(K); ++it) {
      if (it->second.first != it->second.second){
	MYFACE f = it->first;
	GFace *gf = _r2f [it->second];
	if (f.getNumVertices () == 3){
	  MTriangle *t = new MTriangle (f.getVertex(0),f.getVertex(1),f.getVertex(2));
	  gf->triangles.push_back(t);
	}
	else if (f.getNumVertices () == 4){
	  MQuadrangle *q = new MQuadrangle (f.getVertex(0),f.getVertex(1),
                                            f.getVertex(2),f.getVertex(3));
	  gf->quadrangles.push_back(q);
	}
      }
    }
  }

  // create Regions 2 Faces topology
  {
    std::map<GRegion*, std::set<GFace*> >::iterator it =  _topology.begin();
    for ( ; it != _topology.end() ; ++it){
      std::list<GFace*> l ; l.insert (l.begin(), it->second.begin(), it->second.end());
      it->first->set(l);
      for (std::list<GFace*>::iterator it2 =  l.begin() ; it2 != l.end() ; ++it2)
        (*it2)->addRegion(it->first);
    }
  }
}

void GModel::createTopologyFromMeshNew()
{
  const int dim = getDim ();

  double t1 = Cpu();

  if (topoExists (this)) {
    return;
  }

  Msg::Info("createTopologyFromMeshNew --> creating a topology from the mesh");
  int numF=0,numE=0,numV=0;
  if (dim >= 3) createTopologyFromMesh3D (this, numF);
  else ensureManifoldFaces ( this );
  if (dim >= 2) createTopologyFromMesh2D ( this , numE);
  if (dim >= 1) createTopologyFromMesh1D ( this, numV);

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

  double t2 = Cpu();
  Msg::Info("createTopologyFromMeshNew done in %3.f sec.)",t2-t1);
}
