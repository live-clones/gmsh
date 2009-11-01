// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "discreteRegion.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "gmshSurface.h"
#include "Octree.h"
#include "SmoothData.h"
#include "Context.h"
#include "OS.h"

#if !defined(HAVE_NO_MESH)
#include "Field.h"
#include "Generator.h"
#endif

std::vector<GModel*> GModel::list;
int GModel::_current = -1;

GModel::GModel(std::string name)
  : _name(name), _visible(1), _octree(0),
    _geo_internals(0), _occ_internals(0), _fm_internals(0),
    _fields(0), _currentMeshEntity(0), normals(0)
{
  partitionSize[0] = 0; partitionSize[1] = 0;
  list.push_back(this);
  // at the moment we always create (at least an empty) GEO model
  _createGEOInternals();
#if !defined(HAVE_NO_MESH)
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
#if !defined(HAVE_NO_MESH)
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

#if !defined(HAVE_NO_MESH)
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
  if(_octree) Octree_Delete(_octree);
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
  if(physicalNames.count(std::pair<int, int>(dim, number)))
    return physicalNames[std::pair<int, int>(dim, number)];
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
#if !defined(HAVE_NO_MESH)
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
  //with 0
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
      if(part)	meshPartitions.insert(part);
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
        if(v->points.empty()) // CAD points already have one by default
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

  std::map<int, std::vector<MElement*> > elements[10];
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


void GModel::createTopologyFromMesh()
{

  // for each discreteRegion, create topology
  std::vector<discreteRegion*> discRegions;
  for(riter it = firstRegion(); it != lastRegion(); it++)
    if((*it)->geomType() == GEntity::DiscreteVolume)
      discRegions.push_back((discreteRegion*) *it);

  for (std::vector<discreteRegion*>::iterator it = discRegions.begin(); 
       it != discRegions.end(); it++)
    (*it)->setBoundFaces();

  //for each discreteFace, createTopology
 std::vector<discreteFace*> discFaces;
  for(fiter it = firstFace(); it != lastFace(); it++)
    if((*it)->geomType() == GEntity::DiscreteSurface)
      discFaces.push_back((discreteFace*) *it);

  createTopologyFromFaces(discFaces);

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
  for (std::vector<discreteFace*>::iterator it = discFaces.begin(); it != discFaces.end(); it++)
    (*it)->findEdges(map_edges);

  //return if no boundary edges (torus, sphere, ..)
  if (map_edges.empty()) return;

  // create reverse map, for each face find set of MEdges that are
  // candidate for new discrete Edges
  std::map<int, std::vector<int> > face2Edges;

  while (!map_edges.empty()){
 
    std::vector<MEdge> myEdges;
    std::vector<int> tagFaces = map_edges.begin()->second;
    myEdges.push_back(map_edges.begin()->first);
    map_edges.erase(map_edges.begin());

    std::map<MEdge, std::vector<int>, Less_Edge >::iterator itmap = map_edges.begin();
    while (itmap != map_edges.end()){
      std::vector<int> tagFaces2 = itmap->second;
      if (tagFaces2 == tagFaces){
        myEdges.push_back(itmap->first);
        map_edges.erase(itmap++);
      }
      else
        itmap++;
    }
    
    //printf("*** %d Edges that bound \n", myEdges.size());
    //for(std::vector<int>::iterator itFace = tagFaces.begin(); itFace != tagFaces.end(); itFace++) 
    //  printf("face %d \n", *itFace);

    // if the loaded mesh already contains discrete Edges, check if
    // the candidate discrete Edge does contain any of those; if not,
    // create discreteEdges and create a map face2Edges that associate
    // for each face the boundary discrete Edges

    for (std::vector<discreteEdge*>::iterator itE = discEdges.begin(); itE != discEdges.end(); itE++){

      bool candidate = true;
      for (unsigned int i = 0; i < (*itE)->getNumMeshElements(); i++){
	MEdge me = (*itE)->getMeshElement(i)->getEdge(0);
	if (std::find(myEdges.begin(), myEdges.end(), me) ==  myEdges.end()){
	  candidate = false;
	  break;
	}
      }

      if (candidate){

	std::vector<int> tagEdges;
	tagEdges.push_back((*itE)->tag());
	//printf("push back edge %d\n", (*itE)->tag());
	for (unsigned int i = 0; i < (*itE)->getNumMeshElements(); i++){
	  MEdge me = (*itE)->getMeshElement(i)->getEdge(0);
	  std::vector<MEdge>::iterator itME = std::find(myEdges.begin(), myEdges.end(), me);
	  myEdges.erase(itME);
	}

	for (std::vector<int>::iterator itFace = tagFaces.begin(); itFace != tagFaces.end(); itFace++) {
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
    
    while (!myEdges.empty()) {
      std::vector<MEdge> myLines;
      myLines.clear();
      std::vector<MEdge>::iterator it = myEdges.begin();
      
      MVertex *vB = (*it).getVertex(0);
      MVertex *vE = (*it).getVertex(1);
      myLines.push_back(*it);
      myEdges.erase(it);
      it++;
      for (int i = 0; i < 2; i++) {
	std::vector<MEdge>::iterator it= myEdges.begin();
	while (it != myEdges.end()){
	  MVertex *v1 = (*it).getVertex(0);
	  MVertex *v2 = (*it).getVertex(1);
	  std::vector<MEdge>::iterator itp;
	  if (v1 == vE){
	    myLines.push_back(*it);
	    myEdges.erase(it);
	    vE = v2;
	    i = -1;
	  }
	  else if (v2 == vE){
	    myLines.push_back(*it);
	    myEdges.erase(it);
	    vE = v1;
	    i = -1;
	  }
	  else it++;
	}
	
	if (vB == vE) break;
	if (myEdges.empty()) break;
	MVertex *temp = vB;
	vB = vE;
	vE = temp;
      }
      
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
      
     
      for (std::vector<int>::iterator itFace = tagFaces.begin(); itFace != tagFaces.end(); itFace++) {

	//delete new mesh vertices of edge from adjacent faces
	GFace *dFace = getFaceByTag(*itFace);
	for (std::vector<MVertex*>::iterator itv = allV.begin(); itv != allV.end(); itv++) {
	  std::vector<MVertex*>::iterator itve = std::find(dFace->mesh_vertices.begin(), dFace->mesh_vertices.end(), *itv);
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
  }
  
  // set boundary edges for each face
  for (std::vector<discreteFace*>::iterator it = discFaces.begin(); it != discFaces.end(); it++){
    //printf("set boundary edge for face =%d \n", (*it)->tag());
    std::map<int, std::vector<int> >::iterator ite = face2Edges.find((*it)->tag());
    if (ite != face2Edges.end()){
      std::vector<int> myEdges = ite->second;
      (*it)->setBoundEdges(myEdges);
    }
  }

  // for each discreteEdge, create Topology
  for (std::vector<discreteEdge*>::iterator it = discEdges.begin(); it != discEdges.end(); it++){
    (*it)->createTopo();
    (*it)->parametrize();
  }


}

GModel *GModel::buildCutGModel(gLevelset *ls)
{
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;

  Msg::Info("Cutting mesh...");
  double t1 = Cpu();

  GModel *cutGM = buildCutMesh(this, ls, elements, vertexMap, physicals);

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

