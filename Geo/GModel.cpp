// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GModel.h"
#include "MElement.h"
#include "discreteRegion.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "Message.h"

#if defined(HAVE_GMSH_EMBEDDED)
#include "GmshEmbedded.h"
#else
#include "gmshSurface.h"
#include "Octree.h"
#include "SmoothData.h"
#include "Field.h"
#include "Generator.h"
#include "Context.h"
#endif

extern Context_T CTX;

std::vector<GModel*> GModel::list;
int GModel::_current = -1;

GModel::GModel(std::string name)
  : _octree(0), _geo_internals(0), _occ_internals(0), _fm_internals(0), 
    _fields(0), _currentMeshEntity(0), modelName(name), normals(0)
{
  partitionSize[0] = 0; partitionSize[1] = 0;
  list.push_back(this);

#if !defined(HAVE_GMSH_EMBEDDED)
  // at the moment we always create (at least an empty) GEO model
  _createGEOInternals();
  _fields = new FieldManager();
#endif
}

GModel::~GModel()
{
  std::vector<GModel*>::iterator it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);

  destroy();

#if !defined(HAVE_GMSH_EMBEDDED)
  _deleteGEOInternals();
  _deleteOCCInternals();
  delete _fields;
#endif
}

GModel *GModel::current(int index)
{
  if(index >= 0) _current = index;
  if(list.empty()) return 0; // not an error

  if(_current < 0 || _current >= (int)list.size()) return list.back();
  return list[_current];
}

GModel *GModel::findByName(std::string name)
{
  // return last mesh with given name
  for(int i = list.size() - 1; i >= 0; i--)
    if(list[i]->getName() == name) return list[i];
  return 0;
}

void GModel::destroy()
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    delete *it;
  regions.clear();

  std::vector<GFace*> to_keep;
  for(fiter it = firstFace(); it != lastFace(); ++it){
    // projection faces are persistent
    if((*it)->getNativeType() == GEntity::UnknownModel &&
       (*it)->geomType() == GEntity::ProjectionFace)
      to_keep.push_back(*it);
    else
      delete *it;
  }
  faces.clear();
  faces.insert(to_keep.begin(), to_keep.end());

  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    delete *it;
  edges.clear();

  for(viter it = firstVertex(); it != lastVertex(); ++it)
    delete *it;
  vertices.clear();

  destroyMeshCaches();

  MVertex::resetGlobalNumber();
  MElement::resetGlobalNumber();

#if !defined(HAVE_GMSH_EMBEDDED)
  if(normals) delete normals;
  normals = 0;

  _fields->reset();
  gmshSurface::reset();
#endif
}

void GModel::destroyMeshCaches()
{
  _vertexVectorCache.clear();
  _vertexMapCache.clear();
#if !defined(HAVE_GMSH_EMBEDDED)
  if(_octree) Octree_Delete(_octree);
  _octree = 0;
#endif
}

bool GModel::empty() const
{
  return vertices.empty() && edges.empty() && faces.empty() && regions.empty();
}

GRegion *GModel::getRegionByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  std::set<GRegion*, GEntityLessThan>::const_iterator it = regions.find((GRegion*)&tmp);
  if(it != regions.end())
    return *it;
  else
    return 0;
}

GFace *GModel::getFaceByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  std::set<GFace*, GEntityLessThan>::const_iterator it = faces.find((GFace*)&tmp);
  if(it != faces.end())
    return *it;
  else
    return 0;
}

GEdge *GModel::getEdgeByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  std::set<GEdge*, GEntityLessThan>::const_iterator it = edges.find((GEdge*)&tmp);
  if(it != edges.end())
    return *it;
  else
    return 0;
}

GVertex *GModel::getVertexByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  std::set<GVertex*, GEntityLessThan>::const_iterator it = vertices.find((GVertex*)&tmp);
  if(it != vertices.end())
    return *it;
  else
    return 0;
}

void GModel::remove(GRegion *r)
{
  riter it = std::find(firstRegion(), lastRegion(), r);
  if(it != (riter)regions.end()) regions.erase(it);
}

void GModel::remove(GFace *f)
{
  fiter it = std::find(firstFace(), lastFace(), f);
  if(it != faces.end()) faces.erase(it);
}

void GModel::remove(GEdge *e)
{
  eiter it = std::find(firstEdge(), lastEdge(), e);
  if(it != edges.end()) edges.erase(it);
}

void GModel::remove(GVertex *v)
{
  viter it = std::find(firstVertex(), lastVertex(), v);
  if(it != vertices.end()) vertices.erase(it);
}

void GModel::snapVertices()
{
  viter vit = firstVertex();

  double tol = CTX.geom.tolerance;

  while (vit != lastVertex()){
    std::list<GEdge*> edges = (*vit)->edges();
    for (std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); ++it){
      Range<double> parb = (*it)->parBounds(0);
      double t;
      if ((*it)->getBeginVertex() == *vit){
        t = parb.low();
      }
      else if ((*it)->getEndVertex() == *vit){
        t = parb.high();
      }
      else{
	Msg::Error("Weird vertex: impossible to snap");
	break;
      }
      GPoint gp = (*it)->point(t);
      double d = sqrt((gp.x() - (*vit)->x()) * (gp.x() - (*vit)->x()) +
                      (gp.y() - (*vit)->y()) * (gp.y() - (*vit)->y()) +
                      (gp.z() - (*vit)->z()) * (gp.z() - (*vit)->z()));
      if (d > tol){
        (*vit)->setPosition(gp);
        Msg::Warning("Geom Vertex %d Corrupted (%12.5E)... Snap performed",
		     (*vit)->tag(), d);
      }
    }
    vit++;
  }
}

void GModel::getEntities(std::vector<GEntity*> &entities)
{
  entities.clear();
  entities.insert(entities.end(), vertices.begin(), vertices.end());
  entities.insert(entities.end(), edges.begin(), edges.end());
  entities.insert(entities.end(), faces.begin(), faces.end());
  entities.insert(entities.end(), regions.begin(), regions.end());
}

bool GModel::noPhysicalGroups()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->physicals.size()) return false;
  return true;
}

void GModel::getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4])
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    std::map<int, std::vector<GEntity*> > &group(groups[entities[i]->dim()]);
    for(unsigned int j = 0; j < entities[i]->physicals.size(); j++){
      // physicals can be stored with negative signs when the entity
      // should be "reversed"
      int p = std::abs(entities[i]->physicals[j]);
      if(std::find(group[p].begin(), group[p].end(), entities[i]) == group[p].end())
	group[p].push_back(entities[i]);
    }
  }
}

void GModel::deletePhysicalGroups()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    entities[i]->physicals.clear();
}

void GModel::deletePhysicalGroup(int dim, int num)
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    if(dim == entities[i]->dim()){
      std::vector<int> p;
      for(unsigned int j = 0; j < entities[i]->physicals.size(); j++)
        if(entities[i]->physicals[j] != num) 
	  p.push_back(entities[i]->physicals[j]);
      entities[i]->physicals = p;
    }
  }
}

int GModel::getMaxPhysicalNumber()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->physicals.size(); j++)
      num = std::max(num, std::abs(entities[i]->physicals[j]));
  return num;
}

int GModel::setPhysicalName(std::string name, int number)
{
  // check if the name is already used
  std::map<int, std::string>::iterator it = physicalNames.begin();
  while(it != physicalNames.end()){
    if(it->second == name) return it->first;
    ++it;
  }
  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber() + 1;
  physicalNames[number] = name;
  return number;
}

std::string GModel::getPhysicalName(int number)
{
  return physicalNames[number];
}

SBoundingBox3d GModel::bounds()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  // using the mesh vertices for now; should use entities[i]->bounds() instead
  SBoundingBox3d bb;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      bb += entities[i]->mesh_vertices[j]->point();
  return bb;
}

int GModel::mesh(int dimension)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  GenerateMesh(this, dimension);
  return true;
#else
  Msg::Error("Embedded Gmsh cannot do mesh generation");
  return false;
#endif
}

int GModel::getMeshStatus(bool countDiscrete)
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteVolume &&
			  (*it)->meshAttributes.Method != MESH_NONE)) &&
       ((*it)->tetrahedra.size() ||(*it)->hexahedra.size() ||
        (*it)->prisms.size() || (*it)->pyramids.size())) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteSurface &&
			  (*it)->meshAttributes.Method != MESH_NONE)) &&
       ((*it)->triangles.size() || (*it)->quadrangles.size())) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteCurve &&
			  (*it)->meshAttributes.Method != MESH_NONE)) &&
       (*it)->lines.size()) return 1;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->mesh_vertices.size()) return 0;
  return -1;
}

int GModel::getNumMeshVertices()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  unsigned int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    n += entities[i]->mesh_vertices.size();
  return n;
}

int GModel::getNumMeshElements()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  unsigned int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    n += entities[i]->getNumMeshElements();
  return n;
}

int GModel::getNumMeshElements(unsigned c[4])
{
  c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2] + c[3]) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1]) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0]) return 1;
  return 0;
}

static void MElementBB(void *a, double *min, double *max)
{
  MElement *e = (MElement*)a;
  MVertex *v = e->getVertex(0);
  min[0] = max[0] = v->x(); 
  min[1] = max[1] = v->y(); 
  min[2] = max[2] = v->z();
  for(int i = 1; i < e->getNumVertices(); i++){
    v = e->getVertex(i);
    min[0] = std::min(min[0], v->x()); max[0] = std::max(max[0], v->x());
    min[1] = std::min(min[1], v->y()); max[1] = std::max(max[1], v->y());
    min[2] = std::min(min[2], v->z()); max[2] = std::max(max[2], v->z());
  }
}

static void MElementCentroid(void *a, double *x)
{
  MElement *e = (MElement*)a;
  MVertex *v = e->getVertex(0);
  int n = e->getNumVertices();
  x[0] = v->x(); x[1] = v->y(); x[2] = v->z();
  for(int i = 1; i < n; i++) {
    v = e->getVertex(i);
    x[0] += v->x(); x[1] += v->y(); x[2] += v->z();
  }
  double oc = 1. / (double)n;
  x[0] *= oc;
  x[1] *= oc;
  x[2] *= oc;
}

static int MElementInEle(void *a, double *x)
{
  MElement *e = (MElement*)a;
  double uvw[3];
  e->xyz2uvw(x, uvw);
  return e->isInside(uvw[0], uvw[1], uvw[2]) ? 1 : 0;
}

MElement *GModel::getMeshElementByCoord(SPoint3 &p)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  if(!_octree){
    Msg::Debug("Rebuilding mesh element octree");
    SBoundingBox3d bb = bounds();
    double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
    double size[3] = {bb.max().x() - bb.min().x(),
		      bb.max().y() - bb.min().y(),
		      bb.max().z() - bb.min().z()};                   
    const int maxElePerBucket = 100; // memory vs. speed trade-off
    _octree = Octree_Create(maxElePerBucket, min, size, 
			    MElementBB, MElementCentroid, MElementInEle);
    std::vector<GEntity*> entities;
    getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++)
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
	Octree_Insert(entities[i]->getMeshElement(j), _octree);
    Octree_Arrange(_octree);
  }
  double P[3] = {p.x(), p.y(), p.z()};
  return (MElement*)Octree_Search(P, _octree);
#else
  Msg::Error("Embedded Gmsh cannot perform octree-based element searches");
  return 0;
#endif
}

MVertex *GModel::getMeshVertexByTag(int n)
{
  if(_vertexVectorCache.empty() && _vertexMapCache.empty()){
    Msg::Debug("Rebuilding mesh vertex cache");
    _vertexVectorCache.clear();
    _vertexMapCache.clear();
    bool dense = (getNumMeshVertices() == MVertex::getGlobalNumber());
    std::vector<GEntity*> entities;
    getEntities(entities);
    if(dense){
      Msg::Debug("Good: we have a dense vertex numbering in the cache");
      // numbering starts at 1
      _vertexVectorCache.resize(MVertex::getGlobalNumber() + 1);
      for(unsigned int i = 0; i < entities.size(); i++)
	for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
	  _vertexVectorCache[entities[i]->mesh_vertices[j]->getNum()] = 
	    entities[i]->mesh_vertices[j];
    }
    else{
      for(unsigned int i = 0; i < entities.size(); i++)
	for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
	  _vertexMapCache[entities[i]->mesh_vertices[j]->getNum()] = 
	    entities[i]->mesh_vertices[j];
    }
  }
  
  if(n < (int)_vertexVectorCache.size())
    return _vertexVectorCache[n];
  else
    return _vertexMapCache[n];
}

void GModel::getMeshVertices(int number, int dim, std::vector<MVertex*> &v)
{
  v.clear();
  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::const_iterator it = groups[dim].find(number);
  if(it == groups[dim].end()) return;
  const std::vector<GEntity *> &entities = it->second;
  std::set<MVertex*> sv;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(dim == 0){
      GVertex *g = (GVertex*)entities[i];
      sv.insert(g->mesh_vertices[0]);
    }
    else{
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	MElement *e = entities[i]->getMeshElement(j);
	for(int k = 0; k < e->getNumVertices(); k++)
	  sv.insert(e->getVertex(k));
      }
    }
  }
  v.insert(v.begin(), sv.begin(), sv.end());
}

template <class T>
static void removeInvisible(std::vector<T*> &elements, bool all)
{
  std::vector<T*> tmp;
  for(unsigned int i = 0; i < elements.size(); i++){
    if(all || !elements[i]->getVisibility())
      delete elements[i];
    else
      tmp.push_back(elements[i]);
  }
  elements.clear();
  elements = tmp;
}

void GModel::removeInvisibleElements()
{
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->tetrahedra, all);
    removeInvisible((*it)->hexahedra, all);
    removeInvisible((*it)->prisms, all);
    removeInvisible((*it)->pyramids, all);
    (*it)->deleteVertexArrays();
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->triangles, all);
    removeInvisible((*it)->quadrangles, all);
    (*it)->deleteVertexArrays();
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->lines, all);
    (*it)->deleteVertexArrays();
  }
}

int GModel::indexMeshVertices(bool all)
{
  std::vector<GEntity*> entities;
  getEntities(entities);

  // tag all mesh vertices with -1 (negative vertices will not be
  // saved)
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->setIndex(-1);
  
  // tag all mesh vertices belonging to elements that need to be saved
  // with 0
  for(unsigned int i = 0; i < entities.size(); i++)
    if(all || entities[i]->physicals.size())
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
	for(int k = 0; k < entities[i]->getMeshElement(j)->getNumVertices(); k++)
	  entities[i]->getMeshElement(j)->getVertex(k)->setIndex(0);

  // renumber all the mesh vertices tagged with 0
  int numVertices = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      if(!entities[i]->mesh_vertices[j]->getIndex())
        entities[i]->mesh_vertices[j]->setIndex(++numVertices);
  
  return numVertices;
}

void GModel::scaleMesh(double factor)
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      v->x() *= factor;
      v->y() *= factor;
      v->z() *= factor;
    }
}

void GModel::recomputeMeshPartitions()
{
  meshPartitions.clear();
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      int part = entities[i]->getMeshElement(j)->getPartition();
      if(part) meshPartitions.insert(part);
    }
  }
}

void GModel::deleteMeshPartitions()
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      entities[i]->getMeshElement(j)->setPartition(0);
  meshPartitions.clear();
}

template<class T>
static void _addElements(std::vector<T*> &dst, const std::vector<MElement*> &src)
{
  for(unsigned int i = 0; i < src.size(); i++) dst.push_back((T*)src[i]);
}

void GModel::_storeElementsInEntities(std::map<int, std::vector<MElement*> > &map)
{
  std::map<int, std::vector<MElement*> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it){
    if(!it->second.size()) continue;
    int numEdges = it->second[0]->getNumEdges();
    switch(numEdges){
    case 0: 
      {
        GVertex *v = getVertexByTag(it->first);
        if(!v){
          v = new discreteVertex(this, it->first);
          add(v);
        }
	if(v->points.empty()) // CAD points already have one by default
	  _addElements(v->points, it->second);
      }
      break;
    case 1: 
      {
        GEdge *e = getEdgeByTag(it->first);
        if(!e){
          e = new discreteEdge(this, it->first);
          add(e);
        }
        _addElements(e->lines, it->second);
      }
      break;
    case 3: case 4: 
      {
        GFace *f = getFaceByTag(it->first);
        if(!f){
          f = new discreteFace(this, it->first);
          add(f);
        }
        if(numEdges == 3) _addElements(f->triangles, it->second);
        else _addElements(f->quadrangles, it->second);
      }
      break;
    case 6: case 12: case 9: case 8:
      {
        GRegion *r = getRegionByTag(it->first);
        if(!r){
          r = new discreteRegion(this, it->first);
          add(r);
        }
        if(numEdges == 6) _addElements(r->tetrahedra, it->second);
        else if(numEdges == 12) _addElements(r->hexahedra, it->second);
        else if(numEdges == 9) _addElements(r->prisms, it->second);
        else _addElements(r->pyramids, it->second);
      }
      break;
    }
  }
}

template<class T>
static void _associateEntityWithElementVertices(GEntity *ge, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      elements[i]->getVertex(j)->setEntity(ge);
}

void GModel::_associateEntityWithMeshVertices()
{
  // loop on regions, then on faces, edges and vertices and store the
  // entity pointer in the the elements' vertices (this way we
  // associate the entity of lowest geometrical degree with each
  // vertex)
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    _associateEntityWithElementVertices(*it, (*it)->tetrahedra);
    _associateEntityWithElementVertices(*it, (*it)->hexahedra);
    _associateEntityWithElementVertices(*it, (*it)->prisms);
    _associateEntityWithElementVertices(*it, (*it)->pyramids);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    _associateEntityWithElementVertices(*it, (*it)->triangles);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    _associateEntityWithElementVertices(*it, (*it)->lines);
  }
  for(viter it = firstVertex(); it != lastVertex(); ++it){
    _associateEntityWithElementVertices(*it, (*it)->points);
  }
}

void GModel::_storeVerticesInEntities(std::map<int, MVertex*> &vertices)
{
  std::map<int, MVertex*>::const_iterator it = vertices.begin();
  for(; it != vertices.end(); ++it){
    MVertex *v = it->second;
    GEntity *ge = v->onWhat();
    if(ge){
      if(ge->dim() || ge->mesh_vertices.empty()){ // special case for points
	ge->mesh_vertices.push_back(v);
      }
    }
    else
      delete v; // we delete all unused vertices
  }
}

void GModel::_storeVerticesInEntities(std::vector<MVertex*> &vertices)
{
  for(unsigned int i = 0; i < vertices.size(); i++){
    MVertex *v = vertices[i];
    if(v){ // the vector is allowed to have null entries
      GEntity *ge = v->onWhat();
      if(ge) {
	if(ge->dim() || ge->mesh_vertices.empty()){ // special case for points
	  ge->mesh_vertices.push_back(v);
	}
      }
      else
        delete v; // we delete all unused vertices
    }
  }
}

void GModel::checkMeshCoherence(double tolerance)
{
  int numEle = getNumMeshElements();
  if(!numEle) return;

  Msg::Info("Checking mesh coherence (%d elements)", numEle);

  SBoundingBox3d bbox = bounds();
  double lc = bbox.empty() ? 1. : norm(SVector3(bbox.max(), bbox.min()));

  std::vector<GEntity*> entities;
  getEntities(entities);

  // check for duplicate mesh vertices
  {
    double old_tol = MVertexLessThanLexicographic::tolerance;
    MVertexLessThanLexicographic::tolerance = tolerance * lc;
    std::set<MVertex*, MVertexLessThanLexicographic> pos;
    int num = 0;
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
	MVertex *v = entities[i]->mesh_vertices[j];
	std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.find(v);
	if(it == pos.end()){
	  pos.insert(v);
	}
	else{
	  Msg::Info("Vertices %d and %d have identical position (%g, %g, %g)",
		    (*it)->getNum(), v->getNum(), v->x(), v->y(), v->z());
	  num++;
	}
      }
    }
    if(num) Msg::Warning("%d duplicate vertices", num);
    MVertexLessThanLexicographic::tolerance = old_tol;
  }

  // check for duplicate elements
  {
    double old_tol = MElementLessThanLexicographic::tolerance;
    MElementLessThanLexicographic::tolerance = tolerance * lc;
    std::set<MElement*, MElementLessThanLexicographic> pos;
    int num = 0;
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	MElement *e = entities[i]->getMeshElement(j);
	std::set<MElement*, MElementLessThanLexicographic>::iterator it = pos.find(e);
	if(it == pos.end()){
	  pos.insert(e);
	}
	else{
	  std::ostringstream sstream;
	  sstream << "Element " << e->getNum() << " [ ";
	  for (int k = 0; k < e->getNumVertices(); k++)
	    sstream << e->getVertex(k)->getNum() << " ";
	  sstream << "] on entity " << entities[i]->tag() 
		  << " has same barycenter as element " << (*it)->getNum() 
		  << " [ ";
	  for (int k = 0; k < (*it)->getNumVertices(); k++)
	    sstream << (*it)->getVertex(k)->getNum() << " ";
	  sstream << "]";
	  Msg::Info("%s", sstream.str().c_str());
	  num++;
	}
      }
    }
    if(num) Msg::Warning("%d duplicate elements", num);
    MElementLessThanLexicographic::tolerance = old_tol;
  }
}

int GModel::removeDuplicateMeshVertices(double tolerance)
{
  SBoundingBox3d bbox = bounds();
  double lc = bbox.empty() ? 1. : norm(SVector3(bbox.max(), bbox.min()));

  std::vector<GEntity*> entities;
  getEntities(entities);

  double old_tol = MVertexLessThanLexicographic::tolerance;
  MVertexLessThanLexicographic::tolerance = tolerance * lc;
  std::set<MVertex*, MVertexLessThanLexicographic> pos;

  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      MVertex w(v->x(), v->y(), v->z());
      std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.find(&w);
      if(it == pos.end())
        pos.insert(new MVertex(v->x(), v->y(), v->z()));
    }
  }

  int diff = getNumMeshVertices() - pos.size();
  if(!diff){
    for(std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.begin();
        it != pos.end(); it++)
      delete *it;
    Msg::Info("No duplicate vertices found");
    return 0;
  }

  std::map<int, std::vector<MElement*> > elements[8];
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      MElement *e = entities[i]->getMeshElement(j);
      std::vector<MVertex*> verts;
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.find(v);
        if(it != pos.end())
          verts.push_back(*it);
        else
          Msg::Error("Could not find unique vertex (%g,%g,%g)", v->x(), v->y(), v->z());
      }
      MElementFactory factory;
      MElement *e2 = factory.create(e->getTypeForMSH(), verts, e->getNum(), 
                                    e->getPartition());
      switch(e2->getNumEdges()){
      case 0: elements[0][entities[i]->tag()].push_back(e2); break;
      case 1: elements[1][entities[i]->tag()].push_back(e2); break;
      case 3: elements[2][entities[i]->tag()].push_back(e2); break;
      case 4: elements[3][entities[i]->tag()].push_back(e2); break;
      case 6: elements[4][entities[i]->tag()].push_back(e2); break;
      case 12: elements[5][entities[i]->tag()].push_back(e2); break;
      case 9: elements[6][entities[i]->tag()].push_back(e2); break;
      case 8: elements[7][entities[i]->tag()].push_back(e2); break;
      }
    }
  }

  for(unsigned int i = 0; i < entities.size(); i++)
    entities[i]->deleteMesh();

  std::vector<MVertex*> vertices;
  for(std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.begin();
      it != pos.end(); it++)
    vertices.push_back(*it);

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);

  MVertexLessThanLexicographic::tolerance = old_tol;

  Msg::Info("Removed %d duplicate mesh vertices", diff);
    
  return diff;
}
