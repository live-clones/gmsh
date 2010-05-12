// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelFactory.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "MElementOctree.h"
#include "discreteRegion.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "gmshSurface.h"
#include "Octree.h"
#include "SmoothData.h"
#include "Context.h"
#include "OS.h"

#include "OpenFile.h"
#include "CreateFile.h"

#if defined(HAVE_MESH)
#include "Field.h"
#include "Generator.h"
#endif

std::vector<GModel*> GModel::list;
int GModel::_current = -1;

GModel::GModel(std::string name)
  : _name(name), _visible(1), _octree(0),
    _geo_internals(0), _occ_internals(0), _acis_internals(0), _fm_internals(0),_factory(0), _fields(0), _currentMeshEntity(0), normals(0)
{
  partitionSize[0] = 0; partitionSize[1] = 0;
  list.push_back(this);
  // at the moment we always create (at least an empty) GEO model
  _createGEOInternals();
#if defined(HAVE_OCC)
  _factory = new OCCFactory();
#endif
#if defined(HAVE_MESH)
  _fields = new FieldManager();
#endif
}

GModel::~GModel()
{
  std::vector<GModel*>::iterator it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);
  destroy();
  _deleteGEOInternals();
  _deleteOCCInternals();
#if defined(HAVE_MESH)
  delete _fields;
#endif
}

GModel *GModel::current(int index)
{
  if(list.empty()){
    Msg::Warning("No current model available: creating one");
    new GModel();
  }
  if(index >= 0) _current = index;
  if(_current < 0 || _current >= (int)list.size()) return list.back();
  return list[_current];
}

int GModel::setCurrent(GModel *m)
{
  for (unsigned int i = 0; i < list.size(); i++){
    if (list[i] == m){
      _current = i;
      break;
    }
  }
  return _current;
}

void GModel::setFactory(std::string name)
{
  if(_factory) delete _factory;
  _factory = 0;
  if(name == "Gmsh") {
    Msg::Error("Gmsh factory not created yet");
  }
  else if(name == "OpenCASCADE"){
#if defined(HAVE_OCC)
    _factory = new OCCFactory();
#else
    Msg::Error("Missing OpenCASCADE support");
#endif
  }
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
  _name.clear();

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

  if(normals) delete normals;
  normals = 0;

#if defined(HAVE_MESH)
  _fields->reset();
#endif
  gmshSurface::reset();
}

void GModel::destroyMeshCaches()
{
  _vertexVectorCache.clear();
  _vertexMapCache.clear();
  _elementVectorCache.clear();
  _elementMapCache.clear();
  Octree_Delete(_octree);
  _octree = 0;
}

bool GModel::empty() const
{
  return vertices.empty() && edges.empty() && faces.empty() && regions.empty();
}

int GModel::maxVertexNum()
{
  viter it = firstVertex();
  viter itv = lastVertex();
  int MAXX = 0;
  while(it != itv){
    MAXX = std::max(MAXX, (*it)->tag());
    ++it;
  }
  return MAXX;

}
int GModel::maxEdgeNum()
{
  eiter it = firstEdge();
  eiter ite = lastEdge();
  int MAXX = 0;
  while(it != ite){
    MAXX = std::max(MAXX, (*it)->tag());
    ++it;
  }
  return MAXX;

}

int GModel::maxFaceNum()
{

  fiter it =  firstFace();
  fiter ite = lastFace();
  int MAXX = 0;
  while(it != ite){
    MAXX = std::max(MAXX, (*it)->tag());
    ++it;
  }
  return MAXX;
}

int GModel::maxRegionNum()
{

  riter it =  firstRegion();
  riter ite = lastRegion();
  int MAXX = 0;
  while(it != ite){
    MAXX = std::max(MAXX, (*it)->tag());
    ++it;
  }
  return MAXX;
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

  double tol = CTX::instance()->geom.tolerance;

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

int GModel::getMaxElementaryNumber(int dim)
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim)
      num = std::max(num, std::abs(entities[i]->tag()));
  return num;
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

int GModel::getMaxPhysicalNumber(int dim)
{
  std::vector<GEntity*> entities;
  getEntities(entities);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim)
      for(unsigned int j = 0; j < entities[i]->physicals.size(); j++)
        num = std::max(num, std::abs(entities[i]->physicals[j]));
  return num;
}

int GModel::setPhysicalName(std::string name, int dim, int number)
{
  // check if the name is already used
  piter it = physicalNames.begin();
  while(it != physicalNames.end()){
    if(name == it->second && dim == it->first.first) return it->first.second;
    ++it;
  }
  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber(dim) + 1;
  physicalNames[std::pair<int, int>(dim, number)] = name;
  return number;
}

std::string GModel::getPhysicalName(int dim, int number)
{
  std::map<std::pair<int, int>, std::string>::iterator it =
    physicalNames.find(std::pair<int, int>(dim, number));
  if(it != physicalNames.end()) return it->second;
  return "";
}

int GModel::getPhysicalNumber(const int &dim, const std::string &name)
{
  for(piter physIt = firstPhysicalName(); physIt != lastPhysicalName(); ++physIt)
    if(dim == physIt->first.first && name == physIt->second)
      return physIt->first.second;
  Msg::Warning("No physical group found with the name '%s'", name.c_str());
  return -1;
}

int GModel::getDim()
{
  if(getNumRegions() > 0) return 3;
  if(getNumFaces() > 0) return 2;
  if(getNumEdges() > 0) return 1;
  if(getNumVertices() > 0) return 0;
  Msg::Warning("The model is empty, dim = -1");
  return -1;
}

std::string GModel::getElementaryName(int dim, int number)
{
  std::map<std::pair<int, int>, std::string>::iterator it =
    elementaryNames.find(std::pair<int, int>(dim, number));
  if(it != elementaryNames.end()) return it->second;
  return "";
}

void GModel::setSelection(int val)
{
  std::vector<GEntity*> entities;
  getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++){
    entities[i]->setSelection(val);
    // reset selection in elements (stored in the visibility flag to
    // save space)
    if(val == 0){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        if(entities[i]->getMeshElement(j)->getVisibility() == 2)
          entities[i]->getMeshElement(j)->setVisibility(1);
    }
  }
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
#if defined(HAVE_MESH)
  GenerateMesh(this, dimension);
  return true;
#else
  Msg::Error("Mesh module not compiled");
  return false;
#endif
}

int GModel::getMeshStatus(bool countDiscrete)
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteVolume &&
                          (*it)->meshAttributes.Method != MESH_NONE)) &&
       ((*it)->tetrahedra.size() ||(*it)->hexahedra.size() ||
        (*it)->prisms.size() || (*it)->pyramids.size() ||
        (*it)->polyhedra.size())) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteSurface &&
                          (*it)->meshAttributes.Method != MESH_NONE)) &&
       ((*it)->triangles.size() || (*it)->quadrangles.size() ||
        (*it)->polygons.size())) return 2;
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

int GModel::getNumMeshElements(unsigned c[5])
{
  c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2] + c[3] + c[4]) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2]) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0]) return 1;
  return 0;
}


MElement *GModel::getMeshElementByCoord(SPoint3 &p)
{
  if(!_octree){
    Msg::Debug("Rebuilding mesh element octree");
    _octree = buildMElementOctree(this);
  }
  double P[3] = {p.x(), p.y(), p.z()};
  return (MElement*)Octree_Search(P, _octree);
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

void GModel::getMeshVerticesForPhysicalGroup(int dim, int num, std::vector<MVertex*> &v)
{
  v.clear();
  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::const_iterator it = groups[dim].find(num);
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

MElement *GModel::getMeshElementByTag(int n)
{
  if(_elementVectorCache.empty() && _elementMapCache.empty()){
    Msg::Debug("Rebuilding mesh element cache");
    _elementVectorCache.clear();
    _elementMapCache.clear();
    bool dense = (getNumMeshElements() == MElement::getGlobalNumber());
    std::vector<GEntity*> entities;
    getEntities(entities);
    if(dense){
      Msg::Debug("Good: we have a dense element numbering in the cache");
      // numbering starts at 1
      _elementVectorCache.resize(MElement::getGlobalNumber() + 1);
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
          MElement *e = entities[i]->getMeshElement(j);
          _elementVectorCache[e->getNum()] = e;
        }
    }
    else{
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
          MElement *e = entities[i]->getMeshElement(j);
          _elementMapCache[e->getNum()] = e;
        }
    }
  }

  if(n < (int)_elementVectorCache.size())
    return _elementVectorCache[n];
  else
    return _elementMapCache[n];
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
    removeInvisible((*it)->polyhedra, all);
    (*it)->deleteVertexArrays();
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->triangles, all);
    removeInvisible((*it)->quadrangles, all);
    removeInvisible((*it)->polygons, all);
    (*it)->deleteVertexArrays();
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->lines, all);
    (*it)->deleteVertexArrays();
  }
  destroyMeshCaches();
}

int GModel::indexMeshVertices(bool all, int singlePartition)
{
  std::vector<GEntity*> entities;
  getEntities(entities);

  // tag all mesh vertices with -1 (negative vertices will not be
  // saved)
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->setIndex(-1);

  // tag all mesh vertices belonging to elements that need to be saved
  // with 0, or with -2 if they need to be taken into account in the
  // numbering but need not to be saved (because we save a single
  // partition and they are not used in that partition)
  for(unsigned int i = 0; i < entities.size(); i++){
    if(all || entities[i]->physicals.size()){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        for(int k = 0; k < e->getNumVertices(); k++){
          if(!singlePartition || e->getPartition() == singlePartition)
            e->getVertex(k)->setIndex(0);
          else if(e->getVertex(k)->getIndex() == -1)
            e->getVertex(k)->setIndex(-2);
        }
      }
    }
  }

  // renumber all the mesh vertices tagged with 0
  int numVertices = 0, index = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      if(!entities[i]->mesh_vertices[j]->getIndex()){
        index++;
        numVertices++;
        entities[i]->mesh_vertices[j]->setIndex(index);
      }
      else if(entities[i]->mesh_vertices[j]->getIndex() == -2)
        index++;
  
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
      if(part)  meshPartitions.insert(part);
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
    int type = it->second[0]->getType();
    switch(type){
    case TYPE_PNT:
      {
        GVertex *v = getVertexByTag(it->first);
        if(!v){
          v = new discreteVertex(this, it->first);
          add(v);
        }
        if(!v->points.empty()) { // CAD points already have one by default
          v->points.clear();
          v->mesh_vertices.clear();
        }  
        _addElements(v->points, it->second);
      }
      break;
    case TYPE_LIN:
      {
        GEdge *e = getEdgeByTag(it->first);
        if(!e){
          e = new discreteEdge(this, it->first, 0, 0);
          add(e);
        }
        _addElements(e->lines, it->second);
      }
      break;
    case TYPE_TRI: case TYPE_QUA: case TYPE_POLYG:
      {
        GFace *f = getFaceByTag(it->first);
        if(!f){
          f = new discreteFace(this, it->first);
          add(f);
        }
        if(type == TYPE_TRI) _addElements(f->triangles, it->second);
        else if(type == TYPE_QUA) _addElements(f->quadrangles, it->second);
        else _addElements(f->polygons, it->second);
      }
      break;
    case TYPE_TET: case TYPE_HEX: case TYPE_PYR: case TYPE_PRI: case TYPE_POLYH:
      {
        GRegion *r = getRegionByTag(it->first);
        if(!r){
          r = new discreteRegion(this, it->first);
          add(r);
        }
        if(type == TYPE_TET) _addElements(r->tetrahedra, it->second);
        else if(type == TYPE_HEX) _addElements(r->hexahedra, it->second);
        else if(type == TYPE_PRI) _addElements(r->prisms, it->second);
        else if(type == TYPE_PYR) _addElements(r->pyramids, it->second);
        else _addElements(r->polyhedra, it->second);
      }
      break;
    }
  }
}

template<class T>
static void _associateEntityWithElementVertices(GEntity *ge, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumVertices(); j++){
      if (!elements[i]->getVertex(j)->onWhat() ||
          elements[i]->getVertex(j)->onWhat()->dim() > ge->dim()){
        elements[i]->getVertex(j)->setEntity(ge);
      }
    }
  }
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
    _associateEntityWithElementVertices(*it, (*it)->polyhedra);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    _associateEntityWithElementVertices(*it, (*it)->triangles);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles);
    _associateEntityWithElementVertices(*it, (*it)->polygons);
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
    if(ge) ge->mesh_vertices.push_back(v);
    else delete v; // we delete all unused vertices
  }
}

void GModel::_storeVerticesInEntities(std::vector<MVertex*> &vertices)
{
  for(unsigned int i = 0; i < vertices.size(); i++){
    MVertex *v = vertices[i];
    if(v){ // the vector is allowed to have null entries
      GEntity *ge = v->onWhat();
      if(ge) ge->mesh_vertices.push_back(v);
      else delete v; // we delete all unused vertices
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

  std::map<int, std::vector<MElement*> > elements[10];
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      MElement *e = entities[i]->getMeshElement(j);
      std::vector<MVertex*> verts;
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.find(v);
        if(it == pos.end()){
          Msg::Info("Linear search for (%.16g, %.16g, %.16g)", v->x(), v->y(), v->z()); 
          it = v->linearSearch(pos);
          if(it == pos.end()){
            Msg::Error("Could not find unique vertex (%.16g, %.16g, %.16g)", 
                       v->x(), v->y(), v->z());
            break;
          }
        }
        verts.push_back(*it);
      }
      if(verts.size() == e->getNumVertices()){
        MElementFactory factory;
        MElement *e2 = factory.create(e->getTypeForMSH(), verts, e->getNum(),
                                      e->getPartition());
        switch(e2->getType()){
        case TYPE_PNT: elements[0][entities[i]->tag()].push_back(e2); break;
        case TYPE_LIN: elements[1][entities[i]->tag()].push_back(e2); break;
        case TYPE_TRI: elements[2][entities[i]->tag()].push_back(e2); break;
        case TYPE_QUA: elements[3][entities[i]->tag()].push_back(e2); break;
        case TYPE_TET: elements[4][entities[i]->tag()].push_back(e2); break;
        case TYPE_HEX: elements[5][entities[i]->tag()].push_back(e2); break;
        case TYPE_PRI: elements[6][entities[i]->tag()].push_back(e2); break;
        case TYPE_PYR: elements[7][entities[i]->tag()].push_back(e2); break;
        case TYPE_POLYG: elements[8][entities[i]->tag()].push_back(e2); break;
        case TYPE_POLYH: elements[9][entities[i]->tag()].push_back(e2); break;
        }
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

  Msg::Info("Removed %d duplicate mesh %s", diff, diff > 1 ? "vertices" : "vertex");

  return diff;
}

void GModel::createTopologyFromMesh()
{
  Msg::Info("Creating topology from mesh");
  double t1 = Cpu();

  // for each discreteRegion, create topology
  std::vector<discreteRegion*> discRegions;
  for(riter it = firstRegion(); it != lastRegion(); it++)
    if((*it)->geomType() == GEntity::DiscreteVolume)
      discRegions.push_back((discreteRegion*) *it);

  //EMI-FIX in case of createTopology for Volumes
  //all faces are set to aeach volume
  for (std::vector<discreteRegion*>::iterator it = discRegions.begin();
       it != discRegions.end(); it++)
    (*it)->setBoundFaces();
  
  //for each discreteFace, createTopology
  std::vector<discreteFace*> discFaces;
  for(fiter it = firstFace(); it != lastFace(); it++)
    if((*it)->geomType() == GEntity::DiscreteSurface)
      discFaces.push_back((discreteFace*) *it);
  
  //EMI TODO
  //check for closed faces
 
  createTopologyFromFaces(discFaces);
  
  double t2 = Cpu();
  Msg::Info("Creating topology from mesh done (%g s)", t2-t1);
  
  //create old format (necessaray for boundary layers)
  exportDiscreteGEOInternals();
}

static void recur_connect(MVertex *v,
                          std::multimap<MVertex*,MEdge> &v2e,
                          std::set<MEdge,Less_Edge> &group,
                          std::set<MVertex*> &touched)
{
  if (touched.find(v) != touched.end()) return;

  touched.insert(v);
  for (std::multimap <MVertex*,MEdge>::iterator it = v2e.lower_bound(v); 
       it != v2e.upper_bound(v) ; ++it){
    group.insert(it->second);
    for (int i = 0; i < it->second.getNumVertices(); ++i){
      recur_connect (it->second.getVertex(i), v2e, group, touched);
    }
  }
}

// starting form a list of elements, returns lists of lists that are
// all simply connected
static void recur_connect_e(const MEdge &e,
                            std::multimap<MEdge,MElement*, Less_Edge> &e2e,
                            std::set<MElement*> &group,
                            std::set<MEdge, Less_Edge> &touched)
{
  if (touched.find(e) != touched.end())return;
  touched.insert(e);
  for (std::multimap <MEdge,MElement*,Less_Edge>::iterator it = e2e.lower_bound(e);
         it != e2e.upper_bound(e) ; ++it){
    group.insert(it->second);
    for (int i = 0; i < it->second->getNumEdges(); ++i){
      recur_connect_e(it->second->getEdge(i), e2e, group, touched);
    }
  }
}

static int connected_bounds(std::set<MEdge, Less_Edge> &edges, 
                            std::vector<std::vector<MEdge> > &boundaries)
{
  std::multimap<MVertex*,MEdge> v2e;
  for(std::set<MEdge, Less_Edge>::iterator it = edges.begin(); it != edges.end(); it++){
    for (int j=0;j<it->getNumVertices();j++){
      v2e.insert(std::make_pair(it->getVertex(j),*it));
    }
  }

  while (!v2e.empty()){
    std::set<MEdge, Less_Edge> group;
    std::set<MVertex*> touched;
    recur_connect(v2e.begin()->first, v2e, group, touched);
    std::vector<MEdge> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    boundaries.push_back(temp);
    for (std::set<MVertex*>::iterator it = touched.begin() ; it != touched.end();++it)
      v2e.erase(*it);
  }

  return boundaries.size();
}

void GModel::createTopologyFromFaces(std::vector<discreteFace*> &discFaces)
{
  std::vector<discreteEdge*> discEdges;
  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if((*it)->geomType() == GEntity::DiscreteCurve)
      discEdges.push_back((discreteEdge*) *it);
  }

  // find boundary edges of each face and put them in a map_edges that
  // associates the MEdges with the tags of the adjacent faces
  std::map<MEdge, std::vector<int>, Less_Edge > map_edges;
  for (std::vector<discreteFace*>::iterator it = discFaces.begin(); 
       it != discFaces.end(); it++){
    (*it)->findEdges(map_edges);
  }

  //return if no boundary edges (torus, sphere, ...)
  if (map_edges.empty()) return;

  // create reverse map, for each face find set of MEdges that are
  // candidate for new discrete Edges
  std::map<int, std::vector<int> > face2Edges;

  while (!map_edges.empty()){
    std::set<MEdge, Less_Edge> myEdges;
    myEdges.clear();
    std::vector<int> tagFaces = map_edges.begin()->second;
    myEdges.insert(map_edges.begin()->first);
    map_edges.erase(map_edges.begin());

    std::map<MEdge, std::vector<int>, Less_Edge >::iterator itmap = map_edges.begin();
    while (itmap != map_edges.end()){
      std::vector<int> tagFaces2 = itmap->second;
      if (tagFaces2 == tagFaces){
        myEdges.insert(itmap->first);
        map_edges.erase(itmap++);
      }
      else
        itmap++;
    }

    // if the loaded mesh already contains discrete Edges, check if
    // the candidate discrete Edge does contain any of those; if not,
    // create discreteEdges and create a map face2Edges that associate
    // for each face the boundary discrete Edges

    for (std::vector<discreteEdge*>::iterator itE = discEdges.begin(); 
         itE != discEdges.end(); itE++){

      bool candidate = true;
      for (unsigned int i = 0; i < (*itE)->getNumMeshElements(); i++){
        MEdge me = (*itE)->getMeshElement(i)->getEdge(0);
        std::set<MEdge, Less_Edge >::iterator itset = myEdges.find(me);
        if (itset ==  myEdges.end()){
          candidate = false;
          break;
        }
      }

      if (candidate){
        std::vector<int> tagEdges;
        tagEdges.push_back((*itE)->tag());
        for (unsigned int i = 0; i < (*itE)->getNumMeshElements(); i++){
          MEdge me = (*itE)->getMeshElement(i)->getEdge(0);
          std::set<MEdge, Less_Edge >::iterator itset = myEdges.find(me);
          myEdges.erase(itset);
        }
        
        for (std::vector<int>::iterator itFace = tagFaces.begin(); 
             itFace != tagFaces.end(); itFace++) {
          std::map<int, std::vector<int> >::iterator it = face2Edges.find(*itFace);
          if (it == face2Edges.end()) face2Edges.insert(std::make_pair(*itFace, tagEdges));
          else{
            std::vector<int> allEdges = it->second;
            allEdges.insert(allEdges.begin(), tagEdges.begin(), tagEdges.end());
            it->second = allEdges;
          }
        }
      }
    }

    std::vector<std::vector<MEdge> > boundaries;
    double nbBounds = connected_bounds(myEdges, boundaries);   

    for (int ib  = 0; ib < nbBounds; ib++){
      std::vector<MEdge> myLines = boundaries[ib];

      int numE = maxEdgeNum()+1;
      discreteEdge *e = new discreteEdge(this, numE, 0, 0);
      //printf("*** Created discreteEdge %d \n", numE);
      add(e);
      discEdges.push_back(e);

      //fill new edge with mesh vertices
      std::vector<MVertex*> allV;
      for(unsigned int i = 0; i < myLines.size(); i++) {
        MVertex *v0 = myLines[i].getVertex(0);
        MVertex *v1 = myLines[i].getVertex(1);
        e->lines.push_back(new MLine( v0, v1));
        if (std::find(allV.begin(), allV.end(), v0) ==  allV.end()) allV.push_back(v0);
        if (std::find(allV.begin(), allV.end(), v1) ==  allV.end()) allV.push_back(v1);
        v0->setEntity(e);
        v1->setEntity(e);
      }
      e->mesh_vertices.insert(e->mesh_vertices.begin(), allV.begin(),allV.end());

      for (std::vector<int>::iterator itFace = tagFaces.begin(); 
           itFace != tagFaces.end(); itFace++) {

        //delete new mesh vertices of edge from adjacent faces
        GFace *dFace = getFaceByTag(*itFace);
        for (std::vector<MVertex*>::iterator itv = allV.begin();itv != allV.end(); itv++) {
          std::vector<MVertex*>::iterator itve = 
            std::find(dFace->mesh_vertices.begin(), dFace->mesh_vertices.end(), *itv);
          if (itve != dFace->mesh_vertices.end()) dFace->mesh_vertices.erase(itve);
        }
    
        //fill face2Edges with the new edge
        std::map<int, std::vector<int> >::iterator f2e = face2Edges.find(*itFace);
        if (f2e == face2Edges.end()){
          std::vector<int> tagEdges;
          tagEdges.push_back(numE);
          face2Edges.insert(std::make_pair(*itFace,tagEdges));
        }
        else{
          std::vector<int> tagEdges = f2e->second;
          tagEdges.push_back(numE);
          f2e->second = tagEdges;
        }

      }
     
    }
    if (map_edges.empty()) break;
  }

  // set boundary edges for each face
  for (std::vector<discreteFace*>::iterator it = discFaces.begin();
       it != discFaces.end(); it++){
    std::map<int, std::vector<int> >::iterator ite = face2Edges.find((*it)->tag());
    if (ite != face2Edges.end()){
      std::vector<int> bcEdges = ite->second;
      (*it)->setBoundEdges(bcEdges);
    }
  }

  // for each discreteEdge, create Topology
  std::map<GFace*, std::map<MVertex*, MVertex*, std::less<MVertex*> > > face2Vert;
  face2Vert.clear();
  for (std::vector<discreteEdge*>::iterator it = discEdges.begin(); it != discEdges.end(); it++){
    (*it)->createTopo();
    (*it)->parametrize(face2Vert);//region2Vert
  }

 //we need to recreate lines, triangles and tets
  //that contain those new MEdgeVertices
  //for (std::list<GFace*>::iterator iFace = lFaces.begin();  iFace != lFaces.end(); iFace++){
  for (std::map<GFace*, std::map<MVertex*, MVertex*, std::less<MVertex*> > >::iterator
         iFace= face2Vert.begin(); iFace != face2Vert.end(); iFace++){
    std::map<MVertex*, MVertex*, std::less<MVertex*> > old2new = iFace->second;
    GFace *gf = iFace->first;
    std::vector<MTriangle*> newTriangles;
    std::vector<MQuadrangle*> newQuadrangles;
    for (unsigned int i = 0; i < gf->getNumMeshElements(); ++i){
      MElement *e = gf->getMeshElement(i);
      int N = e->getNumVertices();
      std::vector<MVertex *> v(N);
      for(int j = 0; j < N; j++) v[j] = e->getVertex(j);
      for (int j = 0; j < N; j++){
        std::map<MVertex*, MVertex*, std::less<MVertex*> >::iterator itmap = old2new.find(v[j]);
        MVertex *vNEW;
        if (itmap != old2new.end())  {
          vNEW = itmap->second;
          v[j]=vNEW;
        }
      }
      if (N == 3) newTriangles.push_back(new  MTriangle(v[0], v[1], v[2]));
      else if ( N == 4)  newQuadrangles.push_back(new  MQuadrangle(v[0], v[1], v[2], v[3]));
      
    }
    gf->deleteVertexArrays();
    gf->triangles.clear();
    gf->triangles = newTriangles;
    gf->quadrangles.clear();
    gf->quadrangles = newQuadrangles;
  }

//   for(GModel::riter iRegion = firstRegion();  iRegion != lastRegion(); iRegion++){
//      std::vector<MTetrahedron*> newTetrahedra;
//      std::vector<MHexahedron*> newHexahedra;
//      std::vector<MPrism*> newPrisms;
//      std::vector<MPyramid*> newPyramids;
//      for (unsigned int i = 0; i < (*iRegion)->getNumMeshElements(); ++i){
//        MElement *e = (*iRegion)->getMeshElement(i);
//        int N = e->getNumVertices();
//        std::vector<MVertex *> v(N);
//        for(int j = 0; j < N; j++) v[j] = e->getVertex(j);
//        for (int j = 0; j < N; j++){
//          std::map<MVertex*, MVertex*, std::less<MVertex*> >::iterator itmap = old2new.find(v[j]);
//          MVertex *vNEW;
//          if (itmap != old2new.end())  {
//            vNEW = itmap->second;
//            v[j]=vNEW;
//          }
//        }
//        if (N == 4) newTetrahedra.push_back(new MTetrahedron(v[0], v[1], v[2], v[3]));
//        else if (N == 5) newPyramids.push_back(new MPyramid(v[0], v[1], v[2], v[3], v[4]));
//        else if (N == 6) newPrisms.push_back(new MPrism(v[0], v[1], v[2], v[3], v[4], v[5]));
//        else if (N == 8) newHexahedra.push_back(new MHexahedron(v[0], v[1], v[2], v[3],
//                                                                v[4], v[5], v[6], v[7]));
//      }
//      (*iRegion)->deleteVertexArrays();
//      (*iRegion)->tetrahedra.clear();
//      (*iRegion)->tetrahedra = newTetrahedra;
//      (*iRegion)->pyramids.clear();
//      (*iRegion)->pyramids = newPyramids;
//      (*iRegion)->prisms.clear();
//      (*iRegion)->prisms = newPrisms;
//      (*iRegion)->hexahedra.clear();
//      (*iRegion)->hexahedra = newHexahedra;
//    }

}

GModel *GModel::buildCutGModel(gLevelset *ls, bool cutElem)
{
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;

  Msg::Info("Cutting mesh...");
  double t1 = Cpu();

  GModel *cutGM = buildCutMesh(this, ls, elements, vertexMap, physicals, cutElem);

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    cutGM->_storeElementsInEntities(elements[i]);

  cutGM->_associateEntityWithMeshVertices();

  cutGM->_storeVerticesInEntities(vertexMap);

  for(int i = 0; i < 4; i++)
    cutGM->_storePhysicalTagsInEntities(i, physicals[i]);

  double t2 = Cpu();

  Msg::Info("Mesh cutting complete (%g s)", t2 - t1);
  return cutGM;
}

void GModel::load(std::string fileName)
{
  GModel *temp = GModel::current();
  GModel::setCurrent(this);
  MergeFile(fileName.c_str(),true);
  GModel::setCurrent(temp);
}

void GModel::save(std::string fileName)
{
  GModel *temp = GModel::current();
  GModel::setCurrent(this);
  int guess = GuessFileFormatFromFileName(fileName);
  CreateOutputFile (fileName, guess);
  GModel::setCurrent(temp);
}

GVertex *GModel::addVertex(double x, double y, double z, double lc)
{
  if(_factory) return _factory->addVertex(this, x, y, z, lc);
  return 0;
}

GEdge *GModel::addLine(GVertex *v1, GVertex *v2)
{
  if(_factory) return _factory->addLine(this, v1, v2);
  return 0;
}

GEdge *GModel::addCircleArcCenter(double x, double y, double z, GVertex *start, 
                                  GVertex *end)
{
  if(_factory)
    return _factory->addCircleArc(this, GModelFactory::CENTER_START_END,
                                  start, end, SPoint3(x, y, z));
  return 0;
}

GEdge *GModel::addCircleArc3Points(double x, double y, double z, GVertex *start,
                                   GVertex *end)
{
  if(_factory) 
    return _factory->addCircleArc(this, GModelFactory::THREE_POINTS, 
                                  start, end, SPoint3(x, y, z));
  return 0;
}

GEdge *GModel::addBezier(GVertex *start, GVertex *end, 
			 std::vector<std::vector<double> > points) 
{
  if(_factory) 
    return _factory->addSpline(this, GModelFactory::BEZIER, start, end, 
                               points);
  return 0;
}

GEdge *GModel::addNURBS(GVertex *start, GVertex *end,
			std::vector<std::vector<double> > points, 
			std::vector<double> knots,
			std::vector<double> weights, 
			std::vector<int> mult){  
  if(_factory)
    return _factory->addNURBS(this, start,end,points,knots,weights, mult);
  return 0;
}

void GModel::addRuledFaces (std::vector<std::vector<GEdge *> > edges){
  if(_factory)
    _factory->addRuledFaces(this, edges);
}

GFace* GModel::addFace (std::vector<GEdge *> edges, std::vector< std::vector<double > > points){
  if(_factory)
    return _factory->addFace(this, edges, points);
  return 0;
}

GFace* GModel::addPlanarFace (std::vector<std::vector<GEdge *> > edges){
  if(_factory)
    return _factory->addPlanarFace(this, edges);
  return 0;
}

GEntity *GModel::revolve(GEntity *e, std::vector<double> p1, std::vector<double> p2,
                         double angle)
{
  if(_factory)
    return _factory->revolve(this, e, p1, p2, angle);
  return 0;
}

GEntity *GModel::extrude(GEntity *e, std::vector<double> p1, std::vector<double> p2)
{
  if(_factory) 
    return _factory->extrude(this, e, p1, p2);
  return 0;
}
GEntity *GModel::addPipe(GEntity *e, std::vector<GEdge *>  edges){
  if(_factory) 
    return _factory->addPipe(this,e,edges);
  return 0;
}


GEntity *GModel::addSphere(double cx, double cy, double cz, double radius)
{
  if(_factory) return _factory->addSphere(this, cx, cy, cz, radius);
  return 0;
}

GEntity *GModel::addCylinder(std::vector<double> p1, std::vector<double> p2, 
                             double radius)
{
  if(_factory) return _factory->addCylinder(this, p1, p2, radius);
  return 0;
}

GEntity *GModel::addTorus(std::vector<double> p1, std::vector<double> p2, 
                          double radius1, double radius2)
{
  if(_factory) return _factory->addTorus(this, p1, p2, radius1, radius2);
  return 0;
}

GEntity *GModel::addBlock(std::vector<double> p1, std::vector<double> p2)
{
  if(_factory) return _factory->addBlock(this, p1, p2);
  return 0;
}

GEntity *GModel::addCone(std::vector<double> p1, std::vector<double> p2,
                         double radius1, double radius2)
{
  if(_factory) return _factory->addCone(this, p1, p2,radius1, radius2);
  return 0;
}

GModel *GModel::computeBooleanUnion(GModel *tool, int createNewModel)
{
  if(_factory)
    return _factory->computeBooleanUnion(this, tool, createNewModel);
  return 0;
}

GModel *GModel::computeBooleanIntersection(GModel *tool, int createNewModel)
{
  if(_factory)
    return _factory->computeBooleanIntersection(this, tool, createNewModel);
  return 0;
}

GModel *GModel::computeBooleanDifference(GModel *tool, int createNewModel)
{
  if(_factory)
    return _factory->computeBooleanDifference(this, tool, createNewModel);
  return 0;
}

static void computeDuplicates(GModel *model, 
                              std::multimap<GVertex*, GVertex*> &Unique2Duplicates,
                              std::map<GVertex*, GVertex*> &Duplicates2Unique,
                              const double &eps)
{
  // currently we use a greedy algorithm in n^2 (using bounding boxes
  // and the Octree would certainly be better for huge models...)
  std::list<GVertex*> v;
  v.insert(v.begin(), model->firstVertex(), model->lastVertex());

  while(!v.empty()){
    GVertex *pv = *v.begin();
    v.erase(v.begin());
    bool found = false;
    for ( std::multimap<GVertex*,GVertex*>::iterator it = Unique2Duplicates.begin(); 
          it != Unique2Duplicates.end(); ++it ){
      GVertex *unique = it->first;
      const double d = sqrt((unique->x() - pv->x()) * (unique->x() - pv->x()) +
                            (unique->y() - pv->y()) * (unique->y() - pv->y()) +
                            (unique->z() - pv->z()) * (unique->z() - pv->z()));
      if (d <= eps) {
	found = true;
	Unique2Duplicates.insert(std::make_pair(unique, pv));
	Duplicates2Unique[pv] = unique;
	break;
      }
    }
    if (!found) {
      Unique2Duplicates.insert(std::make_pair(pv, pv));
      Duplicates2Unique[pv] = pv;
    }
  }  
}

static void glueVerticesInEdges(GModel *model, 
                                std::multimap<GVertex*, GVertex*> &Unique2Duplicates,
				std::map<GVertex*, GVertex*> &Duplicates2Unique)
{
  Msg::Debug("Gluing Edges");
  for (GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    GEdge *e = *it;
    GVertex *v1 = e->getBeginVertex();
    GVertex *v2 = e->getEndVertex();
    GVertex *replacementOfv1 = Duplicates2Unique[v1];
    GVertex *replacementOfv2 = Duplicates2Unique[v2];
    if ((v1 != replacementOfv1) || (v2 != replacementOfv2)){
      Msg::Debug("Model Edge %d is re-build", e->tag());
      e->replaceEndingPoints (replacementOfv1, replacementOfv2);
    }
  }
}

static void computeDuplicates(GModel *model,
                              std::multimap<GEdge*, GEdge*> &Unique2Duplicates,
                              std::map<GEdge*,GEdge*> &Duplicates2Unique,
                              const double &eps)
{
  std::list<GEdge*> e;
  e.insert(e.begin(), model->firstEdge(), model->lastEdge());

  while(!e.empty()){
    GEdge *pe = *e.begin();
    // compute a point
    Range<double> r = pe->parBounds(0);
    GPoint gp = pe->point(0.5 * (r.low() + r.high()));
    e.erase(e.begin());
    bool found = false;
    for (std::multimap<GEdge*,GEdge*>::iterator it = Unique2Duplicates.begin(); 
         it != Unique2Duplicates.end(); ++it ){
      GEdge *unique = it->first;
      // first check edges that have same endpoints
      if ((unique->getBeginVertex() == pe->getBeginVertex() && 
	   unique->getEndVertex() == pe->getEndVertex()) ||
	  (unique->getEndVertex() == pe->getBeginVertex() && 
	   unique->getBeginVertex() == pe->getEndVertex())){
	if (unique->geomType() == GEntity::Line && pe->geomType() == GEntity::Line){
	  found = true;
	  Unique2Duplicates.insert(std::make_pair(unique,pe));
	  Duplicates2Unique[pe] = unique;
	  break;	  
	} 
	double t;
	GPoint gp2 = pe->closestPoint(SPoint3(gp.x(),gp.y(),gp.z()),t);
	const double d = sqrt((gp.x() - gp2.x()) * (gp.x() - gp2.x()) +
			      (gp.y() - gp2.y()) * (gp.y() - gp2.y()) +
			      (gp.z() - gp2.z()) * (gp.z() - gp2.z()));
	if (t >= r.low() && t <= r.high() && d <= eps) {
	  found = true;
	  Unique2Duplicates.insert(std::make_pair(unique,pe));
	  Duplicates2Unique[pe] = unique;
	  break;
	}
      }
    }
    if (!found) {
      Unique2Duplicates.insert(std::make_pair(pe,pe));
      Duplicates2Unique[pe] = pe;
    }
  }
}

static void glueEdgesInFaces(GModel *model, 
                             std::multimap<GEdge*, GEdge*> &Unique2Duplicates,
			     std::map<GEdge*, GEdge*> &Duplicates2Unique)
{
  Msg::Debug("Gluing Model Faces");
  for (GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it){
    GFace *f = *it;
    bool aDifferenceExists = false;
    std::list<GEdge*> old = f->edges(), enew;
    for (std::list<GEdge*>::iterator eit = old.begin(); eit !=old.end(); eit++){
      GEdge *temp = Duplicates2Unique[*eit];
      enew.push_back(temp);
      if (temp != *eit){
	aDifferenceExists = true;
      }
    }
    if (aDifferenceExists){
      Msg::Debug("Model Face %d is re-build", f->tag());
      f->replaceEdges (enew);
    }
  }
}

static void computeDuplicates(GModel *model, 
                              std::multimap<GFace*, GFace*> &Unique2Duplicates,
                              std::map<GFace*,GFace*> &Duplicates2Unique, 
                              const double &eps)
{
  std::list<GFace*> f;
  f.insert(f.begin(),model->firstFace(),model->lastFace());

  while(!f.empty()){
    GFace *pf = *f.begin();
    // compute a point
    Range<double> r = pf->parBounds(0);
    Range<double> s = pf->parBounds(1);
    // FIXME : this is WRONG (the point can be in a hole ;-) 
    GPoint gp = pf->point(SPoint2(0.5 * (r.low() + r.high()), 0.5 * (s.low() + s.high())));
    f.erase(f.begin());
    std::list<GEdge*> pf_edges = pf->edges();
    pf_edges.sort();
    bool found = false;
    for (std::multimap<GFace*,GFace*>::iterator it = Unique2Duplicates.begin();
         it != Unique2Duplicates.end(); ++it){
      GFace *unique = it->first;      
      std::list<GEdge*> unique_edges = unique->edges();
      if (unique_edges.size() == pf_edges.size()){
	unique_edges.sort();
	std::list<GEdge*>::iterator it_pf = pf_edges.begin();
	std::list<GEdge*>::iterator it_unique = unique_edges.begin();
	bool all_similar = true;
	// first check faces that have same edges
	for (; it_pf !=  pf_edges.end() ;  ++it_pf,it_unique++){
	  if (*it_pf != *it_unique) all_similar = false;
	}
	if (all_similar){
	  if (unique->geomType() == GEntity::Plane && pf->geomType() == GEntity::Plane){
	    found = true;
	    Unique2Duplicates.insert(std::make_pair(unique,pf));
	    Duplicates2Unique[pf] = unique;
	    break;	  
	  } 
	  double t[2]={0,0};
	  const double d = 1.0;
	  /*sqrt((gp.x()-gp2.x())*(gp.x()-gp2.x())+
	    (gp.y()-gp2.y())*(gp.y()-gp2.y())+
	    (gp.z()-gp2.z())*(gp.z()-gp2.z()));*/
	  //	printf ("closest point @ distance %g\n",d);
	  if (t[0] >= r.low() && t[0] <= r.high() && 
	      t[1] >= s.low() && t[1] <= s.high() && d <= eps) {
	    found = true;
	    Unique2Duplicates.insert(std::make_pair(unique,pf));
	    Duplicates2Unique[pf] = unique;
	    break;
	  }
	}
      }
    }
    if (!found) {
      Unique2Duplicates.insert(std::make_pair(pf,pf));
      Duplicates2Unique[pf] = pf;
    }
  }
}

static void glueFacesInRegions(GModel *model,
                               std::multimap<GFace*, GFace*> &Unique2Duplicates,
			       std::map<GFace*, GFace*> &Duplicates2Unique)
{
  Msg::Debug("Gluing Regions");
  for (GModel::riter it = model->firstRegion(); it != model->lastRegion();++it){
    GRegion *r = *it;
    bool aDifferenceExists = false;
    std::list<GFace*> old = r->faces(), fnew;
    for (std::list<GFace*>::iterator fit = old.begin(); fit != old.end(); fit++){
      std::map<GFace*, GFace*>::iterator itR = Duplicates2Unique.find(*fit);
      if (itR == Duplicates2Unique.end())
	{
	  Msg::Fatal("error in the gluing process");
	}
      GFace *temp = itR->second;;
      fnew.push_back(temp);
      if (temp != *fit){
	aDifferenceExists = true;
      }
    }
    if (aDifferenceExists){
      Msg::Debug("Model Region %d is re-build", r->tag());
      r->replaceFaces (fnew);
    }
  }
}

void GModel::glue(double eps)
{
  {
    std::multimap<GVertex*,GVertex*> Unique2Duplicates;
    std::map<GVertex*,GVertex*> Duplicates2Unique;
    computeDuplicates(this, Unique2Duplicates, Duplicates2Unique, eps);
    glueVerticesInEdges(this, Unique2Duplicates, Duplicates2Unique);
  }
  {
    std::multimap<GEdge*,GEdge*> Unique2Duplicates;
    std::map<GEdge*,GEdge*> Duplicates2Unique;
    computeDuplicates(this, Unique2Duplicates, Duplicates2Unique, eps);
    glueEdgesInFaces(this, Unique2Duplicates, Duplicates2Unique);
  }    
  {
    std::multimap<GFace*,GFace*> Unique2Duplicates;
    std::map<GFace*,GFace*> Duplicates2Unique;
    computeDuplicates(this, Unique2Duplicates, Duplicates2Unique, eps);
    glueFacesInRegions(this, Unique2Duplicates, Duplicates2Unique);
  }    
}

#include "Bindings.h"

void GModel::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<GModel>("GModel");
  cb->setDescription("A GModel contains a geometry and its mesh.");

  methodBinding *cm;
  cm = cb->addMethod("mesh", &GModel::mesh);
  cm->setArgNames("dim", NULL);
  cm->setDescription("Generate a mesh of this model in dimension 'dim'.");
  cm = cb->addMethod("load", &GModel::load);
  cm->setDescription("Merge the file 'filename' in this model, the file can be "
                     "in any format (guessed from the extension) known by gmsh.");
  cm->setArgNames("filename", NULL);
  cm = cb->addMethod("save", &GModel::save);
  cm->setDescription("Save this model in the file 'filename'. The content of the "
                     "file depends on the format (guessed from the extension).");
  cm->setArgNames("filename", NULL);
  cm = cb->addMethod("getNumMeshElements", (int (GModel::*)())&GModel::getNumMeshElements);
  cm->setDescription("return the number of mesh elemnts in the model");
  cm = cb->addMethod("getMeshElementByTag", &GModel::getMeshElementByTag);
  cm->setArgNames("tag", NULL);
  cm->setDescription("access a mesh element by tag, using the element cache");
  cm = cb->addMethod("getNumMeshVertices", &GModel::getNumMeshVertices);
  cm->setDescription("return the total number of vertices in the mesh");
  cm = cb->addMethod("getMeshVertexByTag", &GModel::getMeshVertexByTag);
  cm->setDescription("access a mesh vertex by tag, using the vertex cache");
  cm->setArgNames("tag", NULL);
  cm = cb->addMethod("getNumRegions", &GModel::getNumRegions);
  cm->setDescription("return the number of rgions (3D geometrical entities)");
  cm = cb->addMethod("getNumFaces", &GModel::getNumFaces);
  cm->setDescription("return the number of faces (2D geometrical entities)");
  cm = cb->addMethod("getNumEdges", &GModel::getNumEdges);
  cm->setDescription("return the number of edges (1D geometrical entities)");
  cm = cb->addMethod("getNumVertices", &GModel::getNumVertices);
  cm->setDescription("return the number of vertices (0D geometrical entities)");
  cm = cb->addMethod("getFaceByTag", &GModel::getFaceByTag);
  cm->setDescription("access a geometrical face by tag");
  cm->setArgNames("tag", NULL);
  cm = cb->addMethod("getEdgeByTag", &GModel::getEdgeByTag);
  cm->setDescription("access a geometrical edge by tag");
  cm->setArgNames("tag", NULL);
  cm = cb->addMethod("getVertexByTag", &GModel::getVertexByTag);
  cm->setDescription("access a geometrical vertex by tag");
  cm->setArgNames("tag", NULL);
  cm = cb->addMethod("getRegionByTag", &GModel::getRegionByTag);
  cm->setDescription("access a geometrical region by tag");
  cm->setArgNames("tag", NULL);

  cm = cb->addMethod("addVertex", &GModel::addVertex);
  cm->setDescription("create a new vertex at position (x, y, z), with target "
                     "mesh size lc");
  cm->setArgNames("x", "y", "z", "lc", NULL);
  cm = cb->addMethod("addLine", &GModel::addLine);
  cm->setDescription("create a straight line going from v1 to v2");
  cm->setArgNames("v1", "v2", NULL);
  cm = cb->addMethod("addBezier", &GModel::addBezier);
  cm->setDescription("create a spline going from v1 to v2 and with some control "
                     "points listed in a fullMatrix(N,3)");
  cm->setArgNames("v1", "v2", "controlPoints", NULL);
  cm = cb->addMethod("addNURBS", &GModel::addNURBS);
  cm->setDescription("creates a NURBS curve from v1 to v2 with control Points, knots, weights and multiplicities");
  cm->setArgNames("v1", "v2", "{{poles}}","{knots}","{weights}","{mult}",NULL);
  cm = cb->addMethod("addFace", &GModel::addFace);
  cm->setDescription("creates a face that is constraint by edges and points");
  cm->setArgNames("{list of edges}","{{x,y,z},{x,y,z},...}",NULL);
  cm = cb->addMethod("addRuledFaces", &GModel::addRuledFaces);
  cm->setDescription("creates ruled faces that contains a list of wires");
  cm->setArgNames("{{list of edges},{list of edges},...}",NULL);
  cm = cb->addMethod("addPlanarFace", &GModel::addPlanarFace);
  cm->setDescription("creates a planar face that contains a list of wires");
  cm->setArgNames("{{list of edges},{list of edges},...}",NULL);
  cm = cb->addMethod("addPipe", &GModel::addPipe);
  cm->setDescription("creates a pipe with a base and a wire for the direction");
  cm->setArgNames("ge","{list of edges}",NULL);
  cm = cb->addMethod("addCircleArcCenter", &GModel::addCircleArcCenter);
  cm->setDescription("create a circle arc going from v1 to v2 with its center "
                     "at (x,y,z)");
  cm->setArgNames("x", "y", "z", "v1", "v2", NULL);
  cm = cb->addMethod("addCircleArc3Points", &GModel::addCircleArc3Points);
  cm->setDescription("create a circle arc going from v1 to v2 with an "
                     "intermediary point Xi(x,y,z)");
  cm->setArgNames("x", "y", "z", "v1", "v2", NULL);
  cm = cb->addMethod("revolve", &GModel::revolve);
  cm->setDescription("revolve an entity of a given angle. Axis is defined by 2 "
                     "points");
  cm->setArgNames("entity", "{x1,y1,z1}", "{x2,y2,z2}", "angle", NULL);
  cm = cb->addMethod("extrude", &GModel::extrude);
  cm->setDescription("extrudes an entity. Axis is defined by 2 points");
  cm->setArgNames("entity", "{x1,y1,z1}", "{x2,y2,z2}", NULL);
  cm = cb->addMethod("addSphere", &GModel::addSphere);
  cm->setDescription("add a sphere");
  cm->setArgNames("xc", "yc", "zc", "radius", NULL);
  cm = cb->addMethod("addBlock", &GModel::addBlock);
  cm->setDescription("add a block");
  cm->setArgNames("{x1,y1,z1}", "{x2,y2,z2}", NULL);
  cm = cb->addMethod("addCone", &GModel::addCone);
  cm->setDescription("add a cone");
  cm->setArgNames("{x1,y1,z1}","{x2,y2,z2}","R1","R2",NULL);
  cm = cb->addMethod("addCylinder", &GModel::addCylinder);
  cm->setDescription("add a cylinder");
  cm->setArgNames("{x1,y1,z1}","{x2,y2,z2}", "R",NULL);
  cm = cb->addMethod("addTorus", &GModel::addTorus);
  cm->setDescription("add a torus");
  cm->setArgNames("{x1,y1,z1}","{x2,y2,z2}","R1","R2",NULL);
  cm = cb->addMethod("computeUnion", &GModel::computeBooleanUnion);
  cm->setDescription("compute the boolean union of the model with another one "
                     "(tool). The third parameter tells if a new model has to "
                     "be created");
  cm->setArgNames("tool", "createNewGModel",NULL);
  cm = cb->addMethod("computeIntersection", &GModel::computeBooleanIntersection);
  cm->setDescription("compute the boolean intersection of the model with another "
                     "one. The third parameter tells if a new model has to be created");
  cm->setArgNames("tool","createNewGModel",NULL);
  cm = cb->addMethod("computeDifference", &GModel::computeBooleanDifference);
  cm->setDescription("compute the boolean difference of the model with another "
                     "one (tool). The third parameter tells if a new model has to "
                     "be created");
  cm->setArgNames("tool","createNewGModel",NULL);
  cm = cb->addMethod("glue", &GModel::glue);
  cm->setDescription("glue the geometric model using geometric tolerance eps");
  cm->setArgNames("eps",NULL);
  cm = cb->addMethod("setAsCurrent", &GModel::setAsCurrent);
  cm->setDescription("set the model as the current (active) one");
  cm = cb->setConstructor<GModel>();
  cm->setDescription("Create an empty GModel");
}
