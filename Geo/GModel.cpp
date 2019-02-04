// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include <stdlib.h>
#include <sstream>
#include <stack>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"
#include "MElementOctree.h"
#include "discreteRegion.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "gmshSurface.h"
#include "SmoothData.h"
#include "Context.h"
#include "OS.h"
#include "StringUtils.h"
#include "GEdgeLoop.h"
#include "MVertexRTree.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "GModelCreateTopologyFromMesh.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "Field.h"
#include "Generator.h"
#include "meshGFaceOptimize.h"
#include "meshPartition.h"
#include "HighOrder.h"
#include "meshMetric.h"
#include "meshGRegionMMG3D.h"
#include "meshGFaceBamg.h"

static const float EDGE_ANGLE_THRESHOLD = 0.698132;
#endif

#if defined(HAVE_KBIPACK)
#include "Homology.h"
#endif

std::vector<GModel *> GModel::list;
int GModel::_current = -1;

GModel::GModel(const std::string &name)
  : _maxVertexNum(0), _maxElementNum(0), _checkPointedMaxVertexNum(0),
    _checkPointedMaxElementNum(0), _destroying(false), _name(name), _visible(1),
    _elementOctree(0), _geo_internals(0), _occ_internals(0), _acis_internals(0),
    _fields(0), _currentMeshEntity(0), _numPartitions(0),
    normals(0)
{
  // hide all other models
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setVisibility(0);

  // push new one into the list
  list.push_back(this);

  // we always create an internal GEO model; other CAD internals are created
  // on-demand
  _createGEOInternals();

#if defined(HAVE_MESH)
  _fields = new FieldManager();
#endif
}

GModel::~GModel()
{
  std::vector<GModel *>::iterator it =
    std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);

  if(getVisibility()) {
    // if no other model is visible, make the last one visible
    bool othervisible = false;
    for(unsigned int i = 0; i < list.size(); i++) {
      if(list[i]->getVisibility()) othervisible = true;
    }
    if(!othervisible && list.size()) list.back()->setVisibility(1);
  }

  destroy();
  _deleteGEOInternals();
  _deleteOCCInternals();
#if defined(HAVE_MESH)
  delete _fields;
#endif
}

void GModel::setFileName(const std::string &fileName)
{
  _fileName = fileName;
  _fileNames.insert(fileName);

  Msg::SetOnelabString("Gmsh/Model name", fileName,
                       Msg::GetNumOnelabClients() > 1, false, true, 0, "file");
  Msg::SetOnelabString("Gmsh/Model absolute path",
                       SplitFileName(GetAbsolutePath(fileName))[0], false,
                       false, true, 0);
  Msg::SetWindowTitle(fileName);
}

GModel *GModel::current(int index)
{
  if(list.empty()) {
    Msg::Info("No current model available: creating one");
    new GModel();
  }
  if(index >= 0) _current = index;
  if(_current < 0 || _current >= (int)list.size()) return list.back();
  return list[_current];
}

int GModel::setCurrent(GModel *m)
{
  for(unsigned int i = 0; i < list.size(); i++) {
    if(list[i] == m) {
      _current = i;
      break;
    }
  }
  return _current;
}

GModel *GModel::findByName(const std::string &name, const std::string &fileName)
{
  // return last mesh with given name
  for(int i = list.size() - 1; i >= 0; i--)
    if(list[i]->getName() == name &&
       (fileName.empty() || !list[i]->hasFileName(fileName)))
      return list[i];
  return 0;
}

void GModel::destroy(bool keepName)
{
  Msg::Debug("Destroying model %s", getName().c_str());
  _destroying = true;

  if(!keepName) {
    _name.clear();
    _fileNames.clear();
  }

  _maxVertexNum = _maxElementNum = 0;
  _checkPointedMaxVertexNum = _checkPointedMaxElementNum = 0;
  _currentMeshEntity = 0;
  _lastMeshEntityError.clear();
  _lastMeshVertexError.clear();

  for(riter it = firstRegion(); it != lastRegion(); ++it) delete *it;
  regions.clear();
  std::set<GRegion *, GEntityLessThan>().swap(regions);

  for(fiter it = firstFace(); it != lastFace(); ++it) delete *it;
  faces.clear();
  std::set<GFace *, GEntityLessThan>().swap(faces);

  for(eiter it = firstEdge(); it != lastEdge(); ++it) delete *it;
  edges.clear();
  std::set<GEdge *, GEntityLessThan>().swap(edges);

  for(viter it = firstVertex(); it != lastVertex(); ++it) delete *it;
  vertices.clear();
  std::set<GVertex *, GEntityLessThan>().swap(vertices);

  destroyMeshCaches();

  _resetOCCInternals();

  if(normals) delete normals;
  normals = 0;

#if defined(HAVE_MESH)
  _fields->reset();
#endif
  gmshSurface::reset();

  _destroying = false;
}

void GModel::destroyMeshCaches()
{
  _vertexVectorCache.clear();
  std::vector<MVertex *>().swap(_vertexVectorCache);
  _vertexMapCache.clear();
  std::map<int, MVertex *>().swap(_vertexMapCache);
  _elementVectorCache.clear();
  std::vector<MElement *>().swap(_elementVectorCache);
  _elementMapCache.clear();
  std::map<int, MElement *>().swap(_elementMapCache);
  _elementIndexCache.clear();
  std::map<int, int>().swap(_elementIndexCache);
  delete _elementOctree;
  _elementOctree = 0;
}

void GModel::deleteMesh(bool deleteOnlyElements)
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->deleteMesh(deleteOnlyElements);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->deleteMesh(deleteOnlyElements);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->deleteMesh(deleteOnlyElements);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    (*it)->deleteMesh(deleteOnlyElements);
  destroyMeshCaches();
  _currentMeshEntity = 0;
  _lastMeshEntityError.clear();
  _lastMeshVertexError.clear();
}

bool GModel::empty() const
{
  return vertices.empty() && edges.empty() && faces.empty() && regions.empty();
}

GRegion *GModel::getRegionByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  std::set<GRegion *, GEntityLessThan>::const_iterator it =
    regions.find((GRegion *)&tmp);
  if(it != regions.end())
    return *it;
  else
    return 0;
}

GFace *GModel::getFaceByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  std::set<GFace *, GEntityLessThan>::const_iterator it =
    faces.find((GFace *)&tmp);
  if(it != faces.end())
    return *it;
  else
    return 0;
}

GEdge *GModel::getEdgeByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  std::set<GEdge *, GEntityLessThan>::const_iterator it =
    edges.find((GEdge *)&tmp);
  if(it != edges.end())
    return *it;
  else
    return 0;
}

GVertex *GModel::getVertexByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  std::set<GVertex *, GEntityLessThan>::const_iterator it =
    vertices.find((GVertex *)&tmp);
  if(it != vertices.end())
    return *it;
  else
    return 0;
}

GEntity *GModel::getEntityByTag(int dim, int n) const
{
  switch(dim) {
  case 0: return getVertexByTag(n);
  case 1: return getEdgeByTag(n);
  case 2: return getFaceByTag(n);
  case 3: return getRegionByTag(n);
  }
  return 0;
}

std::vector<int> GModel::getTagsForPhysicalName(int dim,
                                                const std::string &name)
{
  std::vector<int> tags;
  std::map<int, std::vector<GEntity *> > physicalGroups;
  getPhysicalGroups(dim, physicalGroups);
  std::vector<GEntity *> entities =
    physicalGroups[getPhysicalNumber(dim, name)];
  for(std::vector<GEntity *>::iterator it = entities.begin();
      it != entities.end(); it++) {
    GEntity *ge = *it;
    tags.push_back(ge->tag());
  }
  return tags;
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

void GModel::remove(int dim, int tag, bool recursive)
{
  // TODO: we should also check dependencies in embedded entities
  if(dim == 3) {
    GRegion *gr = getRegionByTag(tag);
    if(gr) {
      remove(gr);
      if(recursive) {
        std::vector<GFace *> f = gr->faces();
        for(std::vector<GFace *>::iterator it = f.begin(); it != f.end(); it++)
          remove(2, (*it)->tag(), recursive);
      }
    }
  }
  else if(dim == 2) {
    GFace *gf = getFaceByTag(tag);
    if(gf) {
      bool skip = false;
      for(riter it = firstRegion(); it != lastRegion(); it++) {
        std::vector<GFace *> f = (*it)->faces();
        if(std::find(f.begin(), f.end(), gf) != f.end()) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        remove(gf);
        if(recursive) {
          std::vector<GEdge *> const &e = gf->edges();
          for(std::vector<GEdge *>::const_iterator it = e.begin();
              it != e.end(); it++)
            remove(1, (*it)->tag(), recursive);
        }
      }
    }
  }
  else if(dim == 1) {
    GEdge *ge = getEdgeByTag(tag);
    if(ge) {
      bool skip = false;
      for(fiter it = firstFace(); it != lastFace(); it++) {
        std::vector<GEdge *> const &e = (*it)->edges();
        if(std::find(e.begin(), e.end(), ge) != e.end()) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        remove(ge);
        if(recursive) {
          if(ge->getBeginVertex()) remove(0, ge->getBeginVertex()->tag());
          if(ge->getEndVertex()) remove(0, ge->getEndVertex()->tag());
        }
      }
    }
  }
  else if(dim == 0) {
    GVertex *gv = getVertexByTag(tag);
    if(gv) {
      bool skip = false;
      for(eiter it = firstEdge(); it != lastEdge(); it++) {
        GEdge *ge = *it;
        if(ge->getBeginVertex() == gv || ge->getEndVertex() == gv) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        remove(gv);
      }
    }
  }
}

void GModel::remove(const std::vector<std::pair<int, int> > &dimTags,
                    bool recursive)
{
  for(unsigned int i = 0; i < dimTags.size(); i++)
    remove(dimTags[i].first, dimTags[i].second, recursive);
}

void GModel::remove()
{
  regions.clear();
  faces.clear();
  edges.clear();
  vertices.clear();
}

void GModel::snapVertices()
{
  viter vit = firstVertex();

  double tol = CTX::instance()->geom.tolerance;

  while(vit != lastVertex()) {
    std::vector<GEdge *> const &edges = (*vit)->edges();
    for(std::vector<GEdge *>::const_iterator it = edges.begin();
        it != edges.end(); ++it) {
      Range<double> parb = (*it)->parBounds(0);
      double t;
      if((*it)->getBeginVertex() == *vit) {
        t = parb.low();
      }
      else if((*it)->getEndVertex() == *vit) {
        t = parb.high();
      }
      else {
        Msg::Error("Weird vertex: impossible to snap");
        break;
      }
      GPoint gp = (*it)->point(t);
      double d = sqrt((gp.x() - (*vit)->x()) * (gp.x() - (*vit)->x()) +
                      (gp.y() - (*vit)->y()) * (gp.y() - (*vit)->y()) +
                      (gp.z() - (*vit)->z()) * (gp.z() - (*vit)->z()));
      if(d > tol) {
        (*vit)->setPosition(gp);
        Msg::Info(
          "Snapping geometry vertex %d to curve control point (dist = %g)",
          (*vit)->tag(), d);
      }
    }
    vit++;
  }
}

void GModel::getEntities(std::vector<GEntity *> &entities, int dim) const
{
  entities.clear();
  switch(dim) {
  case 0:
    entities.insert(entities.end(), vertices.begin(), vertices.end());
    break;
  case 1: entities.insert(entities.end(), edges.begin(), edges.end()); break;
  case 2: entities.insert(entities.end(), faces.begin(), faces.end()); break;
  case 3:
    entities.insert(entities.end(), regions.begin(), regions.end());
    break;
  default:
    entities.insert(entities.end(), vertices.begin(), vertices.end());
    entities.insert(entities.end(), edges.begin(), edges.end());
    entities.insert(entities.end(), faces.begin(), faces.end());
    entities.insert(entities.end(), regions.begin(), regions.end());
    break;
  }
}

void GModel::getEntitiesInBox(std::vector<GEntity *> &entities,
                              const SBoundingBox3d &box, int dim) const
{
  entities.clear();
  std::vector<GEntity *> all;
  getEntities(all, dim);
  // if we use this often, create an rtree to avoid the linear search
  for(unsigned int i = 0; i < all.size(); i++) {
    SBoundingBox3d bbox = all[i]->bounds();
    if(bbox.min().x() >= box.min().x() && bbox.max().x() <= box.max().x() &&
       bbox.min().y() >= box.min().y() && bbox.max().y() <= box.max().y() &&
       bbox.min().z() >= box.min().z() && bbox.max().z() <= box.max().z())
      entities.push_back(all[i]);
  }
}

class AbsIntLessThan {
public:
  bool operator()(const int &i1, const int &i2) const
  {
    if(std::abs(i1) < std::abs(i2)) return true;
    return false;
  }
};

bool GModel::getBoundaryTags(const std::vector<std::pair<int, int> > &inDimTags,
                             std::vector<std::pair<int, int> > &outDimTags,
                             bool combined, bool oriented, bool recursive)
{
  bool ret = true;
  for(unsigned int i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = std::abs(inDimTags[i].second); // abs for backward compatibility
    bool reverse = (inDimTags[i].second < 0);
    if(dim == 3) {
      GRegion *gr = getRegionByTag(tag);
      if(gr) {
        if(recursive) {
          std::vector<GVertex *> const &vert = gr->vertices();
          for(std::vector<GVertex *>::const_iterator it = vert.begin();
              it != vert.end(); it++)
            outDimTags.push_back(std::pair<int, int>(0, (*it)->tag()));
        }
        else {
          std::vector<GFace *> faces(gr->faces());
          std::vector<int> const &orientations = gr->faceOrientations();
          std::vector<int>::const_iterator ito = orientations.begin();
          for(std::vector<GFace *>::iterator it = faces.begin();
              it != faces.end(); it++) {
            int t = (*it)->tag();
            if(oriented && ito != orientations.end()) {
              t *= *ito;
              ito++;
            }
            outDimTags.push_back(std::pair<int, int>(2, t));
          }
        }
      }
      else {
        Msg::Error("Unknown model region with tag %d", tag);
        ret = false;
      }
    }
    else if(dim == 2) {
      GFace *gf = getFaceByTag(tag);
      if(gf) {
        if(recursive) {
          std::vector<GVertex *> const &vert = gf->vertices();
          for(std::vector<GVertex *>::const_iterator it = vert.begin();
              it != vert.end(); it++)
            outDimTags.push_back(std::pair<int, int>(0, (*it)->tag()));
        }
        else {
          std::vector<GEdge *> const &edges = gf->edges();
          std::vector<int> orientations(gf->edgeOrientations());
          std::vector<int>::iterator ito = orientations.begin();
          for(std::vector<GEdge *>::const_iterator it = edges.begin();
              it != edges.end(); it++) {
            int t = (*it)->tag();
            if(oriented && ito != orientations.end()) {
              t *= *ito;
              ito++;
            }
            outDimTags.push_back(std::pair<int, int>(1, t));
          }
        }
      }
      else {
        Msg::Error("Unknown model face with tag %d", tag);
        ret = false;
      }
    }
    else if(dim == 1) {
      GEdge *ge = getEdgeByTag(tag);
      if(ge) {
        if(reverse) { // for backward compatibility
          if(ge->getEndVertex())
            outDimTags.push_back(
              std::pair<int, int>(0, ge->getEndVertex()->tag()));
          if(ge->getBeginVertex())
            outDimTags.push_back(
              std::pair<int, int>(0, ge->getBeginVertex()->tag()));
        }
        else {
          if(ge->getBeginVertex())
            outDimTags.push_back(
              std::pair<int, int>(0, ge->getBeginVertex()->tag()));
          if(ge->getEndVertex())
            outDimTags.push_back(
              std::pair<int, int>(0, ge->getEndVertex()->tag()));
        }
      }
      else {
        Msg::Error("Unknown model edge with tag %d", tag);
        ret = false;
      }
    }
    else if(dim == 0) {
      GVertex *gv = getVertexByTag(tag);
      if(gv && recursive) {
        outDimTags.push_back(std::pair<int, int>(0, gv->tag()));
      }
    }
  }

  if(combined) {
    // compute boundary of the combined shapes
    std::set<int, AbsIntLessThan> c[3];
    for(unsigned int i = 0; i < outDimTags.size(); i++) {
      int dim = outDimTags[i].first;
      int tag = outDimTags[i].second;
      if(dim >= 0 && dim < 3) {
        std::set<int>::iterator it = c[dim].find(tag);
        if(it == c[dim].end())
          c[dim].insert(tag);
        else {
          c[dim].erase(it);
        }
      }
    }
    outDimTags.clear();
    for(int dim = 0; dim < 3; dim++) {
      for(std::set<int>::iterator it = c[dim].begin(); it != c[dim].end(); it++)
        outDimTags.push_back(std::pair<int, int>(dim, *it));
    }
  }
  return ret;
}

int GModel::getMaxElementaryNumber(int dim)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(dim < 0 || entities[i]->dim() == dim)
      num = std::max(num, std::abs(entities[i]->tag()));
  return num;
}

bool GModel::noPhysicalGroups()
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->physicals.size()) return false;
  return true;
}

void GModel::getPhysicalGroups(
  std::map<int, std::vector<GEntity *> > groups[4]) const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++) {
    std::map<int, std::vector<GEntity *> > &group(groups[entities[i]->dim()]);
    for(unsigned int j = 0; j < entities[i]->physicals.size(); j++) {
      // physicals can be stored with negative signs when the entity should be
      // "reversed"
      int p = std::abs(entities[i]->physicals[j]);
      group[p].push_back(entities[i]);
    }
  }
  for(int dim = 0; dim < 4; ++dim) {
    std::map<int, std::vector<GEntity *> > &group(groups[dim]);
    for(std::map<int, std::vector<GEntity *> >::iterator it = group.begin();
        it != group.end(); ++it) {
      std::vector<GEntity *> &v = it->second;
      std::sort(v.begin(), v.end());
      std::unique(v.begin(), v.end());
    }
  }
}

void GModel::getPhysicalGroups(
  int dim, std::map<int, std::vector<GEntity *> > &groups) const
{
  std::vector<GEntity *> entities;
  getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++) {
    for(unsigned int j = 0; j < entities[i]->physicals.size(); j++) {
      // physicals can be stored with negative signs when the entity should be
      // "reversed"
      int p = std::abs(entities[i]->physicals[j]);
      groups[p].push_back(entities[i]);
    }
  }
  for(std::map<int, std::vector<GEntity *> >::iterator it = groups.begin();
      it != groups.end(); ++it) {
    std::vector<GEntity *> &v = it->second;
    std::sort(v.begin(), v.end());
    std::unique(v.begin(), v.end());
  }
}

void GModel::removePhysicalGroups()
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    entities[i]->physicals.clear();

  // we cannot remove the names here, as removePhysicalGroups() is used in
  // GModelIO_GEO for the synchronization. We need to add an explicit cleanup of
  // physical names + move all physical defintions directly in GModel.
  //physicalNames.clear();
}

void GModel::removePhysicalGroup(int dim, int tag)
{
  // FIXME: this is very inefficient - needs to be rewriten (and we should
  // generalize the function by taking a list of dim, tag pairs)
  std::vector<GEntity *> entities;
  getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++) {
    std::vector<int> p;
    for(unsigned int j = 0; j < entities[i]->physicals.size(); j++)
      if(entities[i]->physicals[j] != tag)
        p.push_back(entities[i]->physicals[j]);
    entities[i]->physicals = p;
  }
  physicalNames.erase(std::pair<int, int>(dim, tag));
}

int GModel::getMaxPhysicalNumber(int dim)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(dim < 0 || entities[i]->dim() == dim)
      for(unsigned int j = 0; j < entities[i]->physicals.size(); j++)
        num = std::max(num, std::abs(entities[i]->physicals[j]));
  return num;
}

void GModel::getInnerPhysicalNamesIterators(std::vector<piter> &iterators)
{
  iterators.resize(4, firstPhysicalName());

  for(piter physIt = firstPhysicalName(); physIt != lastPhysicalName();
      ++physIt)
    iterators[physIt->first.first] = physIt;
}

int GModel::setPhysicalName(const std::string &name, int dim, int number)
{
  // check if the name is already used
  int findPhy = getPhysicalNumber(dim, name);
  if(findPhy != -1) return findPhy;

  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber(dim) + 1;
  physicalNames.insert(std::pair<std::pair<int, int>, std::string>(
    std::pair<int, int>(dim, number), name));
  return number;
}

GModel::piter GModel::setPhysicalName(piter pos, const std::string &name,
                                      int dim, int number)
{
  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber(dim) + 1;
#if __cplusplus >= 201103L
  // Insertion complexity in O(1) if position points to the element that will
  // FOLLOW the inserted element.
  if(pos != lastPhysicalName()) ++pos;
  return physicalNames.insert(pos, std::pair<std::pair<int, int>, std::string>(
                                     std::pair<int, int>(dim, number), name));
#else
  // Insertion complexity in O(1) if position points to the element that will
  // PRECEDE the inserted element.
  return physicalNames.insert(pos, std::pair<std::pair<int, int>, std::string>(
                                     std::pair<int, int>(dim, number), name));
#endif
}

std::string GModel::getPhysicalName(int dim, int number) const
{
  std::map<std::pair<int, int>, std::string>::const_iterator it =
    physicalNames.find(std::pair<int, int>(dim, number));
  if(it != physicalNames.end()) return it->second;
  return "";
}

void GModel::removePhysicalName(const std::string &name)
{
  std::map<std::pair<int, int>, std::string>::iterator it =
    physicalNames.begin();
  while(it != physicalNames.end()){
    if(it->second == name)
      //it = physicalNames.erase(it); // C++11 only
      physicalNames.erase(it++);
    else
      ++it;
  }
}

int GModel::getPhysicalNumber(const int &dim, const std::string &name)
{
  for(piter physIt = firstPhysicalName(); physIt != lastPhysicalName();
      ++physIt)
    if(dim == physIt->first.first && name == physIt->second)
      return physIt->first.second;

  return -1;
}

int GModel::getDim() const
{
  if(getNumRegions() > 0) return 3;
  if(getNumFaces() > 0) return 2;
  if(getNumEdges() > 0) return 1;
  if(getNumVertices() > 0) return 0;
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
  std::vector<GEntity *> entities;
  getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++) {
    entities[i]->setSelection(val);
    // reset selection in elements (stored in the visibility flag to
    // save space)
    if(val == 0) {
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        if(entities[i]->getMeshElement(j)->getVisibility() == 2)
          entities[i]->getMeshElement(j)->setVisibility(1);
    }
  }
}

SBoundingBox3d GModel::bounds(bool aroundVisible)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  SBoundingBox3d bb;
  for(unsigned int i = 0; i < entities.size(); i++) {
    if(!aroundVisible || entities[i]->getVisibility()) {
      if(entities[i]->getNativeType() == GEntity::OpenCascadeModel) {
        bb += entities[i]->bounds();
      }
      else {
        // using the mesh vertices for now
        if(entities[i]->dim() == 0)
          bb += static_cast<GVertex *>(entities[i])->xyz();
        else
          for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
            bb += entities[i]->mesh_vertices[j]->point();
      }
    }
  }
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

bool GModel::setAllVolumesPositive()
{
  bool ok = true;
  for(riter it = regions.begin(); it != regions.end(); ++it)
    for(unsigned int i = 0; i < (*it)->getNumMeshElements(); ++i)
      if(!(*it)->getMeshElement(i)->setVolumePositive()) ok = false;
  return ok;
}

static void
addToMap(std::multimap<MFace, MElement *, Less_Face> &faceToElement,
         std::map<MElement *, std::vector<std::pair<MElement *, bool> > >
           &elToNeighbors,
         const MFace &face, MElement *el)
{
  std::map<MFace, MElement *, Less_Face>::iterator fit =
    faceToElement.find(face);
  if(fit == faceToElement.end()) {
    faceToElement.insert(std::pair<MFace, MElement *>(face, el));
  }
  else { // We found the neighbor face outFace
    faceToElement.insert(std::pair<MFace, MElement *>(face, el));
    if(faceToElement.count(face) > 2) {
      Msg::Error(
        "Topological fault: Face sharing two other faces. Element %i. "
        "Number of nodes %i. Count of faces: %i Three first nodes %i %i %i",
        el->getNum(), face.getNumVertices(), faceToElement.count(face),
        face.getVertex(0)->getNum(), face.getVertex(1)->getNum(),
        face.getVertex(2)->getNum());
      return;
    }
    MFace outFace = fit->first;
    std::vector<std::pair<MElement *, bool> > &neigh = elToNeighbors[el];
    for(size_t iN = 0; iN < neigh.size(); iN++)
      if(neigh[iN].first == fit->second) // Neigbor is already in the map
        return;
    int i0 = -1;
    while(face.getVertex(0) != outFace.getVertex(++i0))
      ;
    bool sameOrientation =
      face.getVertex(1) == outFace.getVertex((i0 + 1) % face.getNumVertices());
    neigh.push_back(std::make_pair(fit->second, !sameOrientation));
    elToNeighbors[fit->second].push_back(std::make_pair(el, !sameOrientation));
  }
}

static void
checkConformity(std::multimap<MFace, MElement *, Less_Face> &faceToElement,
                std::map<MElement *, std::vector<std::pair<MElement *, bool> > >
                  &elToNeighbors,
                const MFace &face, MElement *el)
{
  int connectivity = faceToElement.count(face);
  if(ElementType::getParentType(el->getType()) == TYPE_TRIH) {
    // Each face of a trihedron should exist twice (no face on the boundary)
    if(connectivity != 2)
      Msg::Error("Non conforming trihedron %i (nb connections for a face %i)",
                 el->getNum(), faceToElement.count(face));
  }
  else {
    // A face can exist  twice (inside) or once (boundary)
    if(connectivity != 2) {
      for(std::size_t iV = 0; iV < face.getNumVertices(); iV++)
        if(face.getVertex(iV)->onWhat()->dim() == 3 || connectivity != 1) {
          for(std::size_t jV = 0; jV < face.getNumVertices(); jV++)
            Msg::Info("Vertex %i dim %i", face.getVertex(jV)->getNum(),
                      face.getVertex(iV)->onWhat()->dim());
          Msg::Error("Non conforming element %i (%i connection(s) for a face "
                     "located on dim %i (vertex %i))",
                     el->getNum(), connectivity,
                     face.getVertex(iV)->onWhat()->dim(),
                     face.getVertex(iV)->getNum());
        }
    }
  }
}

void GModel::setAllVolumesPositiveTopology()
{
  Msg::Info("Orienting volumes according to topology");
  std::map<MElement *, std::vector<std::pair<MElement *, bool> > >
    elToNeighbors;
  std::multimap<MFace, MElement *, Less_Face> faceToElement;

  MElement *el;
  for(riter it = regions.begin(); it != regions.end(); ++it) {
    for(unsigned int iEl = 0; iEl < (*it)->getNumMeshElements(); ++iEl) {
      el = (*it)->getMeshElement(iEl);
      for(int iFace = 0; iFace < el->getNumFaces(); iFace++) {
        addToMap(faceToElement, elToNeighbors, el->getFace(iFace), el);
      }
    }
  }
  for(riter it = regions.begin(); it != regions.end(); ++it) {
    for(unsigned int iEl = 0; iEl < (*it)->getNumMeshElements(); ++iEl) {
      el = (*it)->getMeshElement(iEl);
      for(int iFace = 0; iFace < el->getNumFaces(); iFace++) {
        checkConformity(faceToElement, elToNeighbors, el->getFace(iFace), el);
      }
    }
  }
  std::vector<std::pair<MElement *, bool> > queue;
  std::set<MElement *> queued;
  if((*regions.begin())->tetrahedra.size() == 0) {
    Msg::Error(
      "setAllVolumePositiveTopology needs at least one tetrahedron to start");
    return;
  }
  el = (*regions.begin())->tetrahedra[0];
  queue.push_back(std::make_pair(el, true));
  for(size_t i = 0; i < queue.size(); i++) {
    el = queue[i].first;
    if(!queue[i].second) {
      el->reverse();
      // Msg::Info("Reverted element %i of type %i", el->getNum(),
      // el->getType());
    }
    const std::vector<std::pair<MElement *, bool> > &neigh = elToNeighbors[el];
    for(size_t iN = 0; iN < neigh.size(); iN++)
      if(queued.count(neigh[iN].first) == 0) {
        queue.push_back(
          std::make_pair(neigh[iN].first, neigh[iN].second == queue[i].second));
        // if(!(neigh[iN].second == queue[i].second))
        //  Msg::Info("Queuing  element %i (%i) from el %i (%i)",
        //             neigh[iN].first->getNum(), neigh[iN].second,
        //             el->getNum(), queue[i].second);
        queued.insert(neigh[iN].first);
      }
  }
}

int GModel::adaptMesh(std::vector<int> technique,
                      std::vector<simpleFunction<double> *> f,
                      std::vector<std::vector<double> > parameters, int niter,
                      bool meshAll)
{
// For all algorithms:
//
// parameters[1] = lcmin (default : in global gmsh options
//           CTX::instance()->mesh.lcMin)
// parameters[2] = lcmax (default : in global gmsh options
//   CTX::instance()->mesh.lcMax) niter is the maximum number of iterations

// Available algorithms:
//
//    1) Assume that the function is a levelset -> adapt using Coupez
//    technique (technique = 1)
//           parameters[0] = thickness of the interface (mandatory)
//    2) Assume that the function is a physical quantity -> adapt using the
//    Hessian (technique = 2)
//           parameters[0] = N, the final number of elements
//    3) A variant of 1) by P. Frey (= Coupez + takes curvature function into
//    account)
//           parameters[0] = thickness of the interface (mandatory)
//           parameters[3] = the required minimum number of elements to
//             represent a circle - used for curvature-based metric (default: =
//             15)
//    4) A variant (3), direct implementation in the metric eigendirections,
//    assuming a level set (ls):
//        - hmin is imposed in the ls gradient,
//        - hmax is imposed in the two eigendirections of the ls hessian that
//        are
//          (almost ?) tangent to the iso-zero plane
//          + the latter eigenvalues (1/hmax^2) are modified if necessary to
//          capture the iso-zero curvature
//      parameters[0] = thickness of the interface in the positive ls direction
//      (mandatory) parameters[4] = thickness of the interface in the negative
//      ls direction
//         (=parameters[0] if not specified)
//      parameters[3] = the required minimum number of elements to represent a
//      circle
//         - used for curvature-based metric (default: = 15)
//    5) Same as 4, except that the transition in band E uses linear
//    interpolation
//       of h, instead of linear interpolation of metric

#if defined(HAVE_MESH)
  // copy context (in order to allow multiple calls)
  CTX _backup = *(CTX::instance());

  if(getNumMeshElements() == 0) mesh(getDim());
  int nbElemsOld = getNumMeshElements();
  int nbElems;

  FieldManager *fields = getFields();
  fields->reset();

  int ITER = 0;
  if(meshAll) {
    while(1) {
      Msg::Info("-- adaptMesh (allDim) ITER =%d ", ITER);
      fields->reset();
      meshMetric *metric = new meshMetric(this);
      for(unsigned int imetric = 0; imetric < technique.size(); imetric++) {
        metric->addMetric(technique[imetric], f[imetric], parameters[imetric]);
      }
      fields->setBackgroundField(metric);

      opt_mesh_lc_integration_precision(0, GMSH_SET, 1.e-4);
      opt_mesh_algo2d(0, GMSH_SET, 7.0); // bamg
      opt_mesh_algo3d(0, GMSH_SET, 7.0); // mmg3d
      opt_mesh_lc_from_points(0, GMSH_SET, 0.0); // do not mesh lines with lc

      std::for_each(firstRegion(), lastRegion(), deMeshGRegion());
      std::for_each(firstFace(), lastFace(), deMeshGFace());
      std::for_each(firstEdge(), lastEdge(), deMeshGEdge());

      GenerateMesh(this, getDim());
      nbElems = getNumMeshElements();

      char name[256];
      sprintf(name, "meshAdapt-%d.msh", ITER);
      writeMSH(name);
      // metric->exportInfo(name);

      if(ITER++ >= niter) break;
      if(ITER > 3 && fabs((double)(nbElems - nbElemsOld)) < 0.01 * nbElemsOld)
        break;

      nbElemsOld = nbElems;
    }
  }
  else { // adapt only upper most dimension
    while(1) {
      Msg::Info("-- adaptMesh ITER =%d ", ITER);
      std::vector<MElement *> elements;

      if(getDim() == 2) {
        for(fiter fit = firstFace(); fit != lastFace(); ++fit) {
          if((*fit)->quadrangles.size()) return -1;
          for(unsigned i = 0; i < (*fit)->triangles.size(); i++) {
            elements.push_back((*fit)->triangles[i]);
          }
        }
      }
      else if(getDim() == 3) {
        for(riter rit = firstRegion(); rit != lastRegion(); ++rit) {
          if((*rit)->hexahedra.size()) return -1;
          for(unsigned i = 0; i < (*rit)->tetrahedra.size(); i++) {
            elements.push_back((*rit)->tetrahedra[i]);
          }
        }
      }

      if(elements.size() == 0) return -1;

      fields->reset();
      meshMetric *metric = new meshMetric(this);
      for(unsigned int imetric = 0; imetric < technique.size(); imetric++) {
        metric->addMetric(technique[imetric], f[imetric], parameters[imetric]);
      }
      fields->setBackgroundField(metric);

      if(getDim() == 2) {
        for(fiter fit = firstFace(); fit != lastFace(); ++fit) {
          if((*fit)->geomType() != GEntity::DiscreteSurface) {
            meshGFaceBamg(*fit);
            laplaceSmoothing(*fit, CTX::instance()->mesh.nbSmoothing);
          }
          if(_elementOctree) delete _elementOctree;
          _elementOctree = 0;
        }
      }
      else if(getDim() == 3) {
        for(riter rit = firstRegion(); rit != lastRegion(); ++rit) {
          refineMeshMMG(*rit);
          if(_elementOctree) delete _elementOctree;
          _elementOctree = 0;
        }
      }

      char name[256];
      sprintf(name, "meshAdapt-%d.msh", ITER);
      writeMSH(name);

      nbElems = getNumMeshElements();
      if(++ITER >= niter) break;
      if(ITER > 3 && fabs((double)(nbElems - nbElemsOld)) < 0.01 * nbElemsOld)
        break;

      nbElemsOld = nbElems;
    }
  }

  fields->reset();
  // copy context (in order to allow multiple calls)
  *(CTX::instance()) = _backup;

  return 0;
#else
  Msg::Error("Mesh module not compiled");
  return -1;
#endif
}

int GModel::refineMesh(int linear)
{
#if defined(HAVE_MESH)
  RefineMesh(this, linear);
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
}

int GModel::optimizeMesh(const std::string &how)
{
#if defined(HAVE_MESH)
  if(how == "Netgen")
    OptimizeMeshNetgen(this);
  else
    OptimizeMesh(this);
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
}

int GModel::setOrderN(int order, int linear, int incomplete)
{
#if defined(HAVE_MESH)
  SetOrderN(this, order, linear, incomplete);
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
                          (*it)->meshAttributes.method != MESH_NONE)) &&
       ((*it)->tetrahedra.size() || (*it)->hexahedra.size() ||
        (*it)->prisms.size() || (*it)->pyramids.size() ||
        (*it)->polyhedra.size() || (*it)->trihedra.size()))
      return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteSurface &&
                          (*it)->meshAttributes.method != MESH_NONE)) &&
       ((*it)->triangles.size() || (*it)->quadrangles.size() ||
        (*it)->polygons.size()))
      return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if((countDiscrete || ((*it)->geomType() != GEntity::DiscreteCurve &&
                          (*it)->meshAttributes.method != MESH_NONE)) &&
       (*it)->lines.size())
      return 1;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->mesh_vertices.size()) return 0;
  return -1;
}

int GModel::getNumMeshVertices(int dim) const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  unsigned int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim || dim < 0)
      n += entities[i]->getNumMeshVertices();
  return n;
}

int GModel::getNumMeshElements(int dim)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  unsigned int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim || dim < 0)
      n += entities[i]->getNumMeshElements();
  return n;
}

int GModel::getNumMeshParentElements()
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  unsigned int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    n += entities[i]->getNumMeshParentElements();
  return n;
}

void GModel::renumberMeshVertices()
{
  destroyMeshCaches();
  setMaxVertexNumber(0);
  std::vector<GEntity *> entities;
  getEntities(entities);

  // check if we will potentially only save a subset of elements, i.e. those
  // belonging to physical groups
  bool potentiallySaveSubset = false;
  if(!CTX::instance()->mesh.saveAll){
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->physicals.size()){
        potentiallySaveSubset = true;
        break;
      }
    }
  }

  unsigned int n = 0;
  if(potentiallySaveSubset){
    Msg::Debug("Renumbering for potentially partial mesh save");
    // if we potentially only save a subset of elements, make sure to first
    // renumber the vertices that belong to those elements (so that we end up
    // with a dense vertex numbering in the output file)
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->getNumMeshVertices(); j++) {
        ge->getMeshVertex(j)->forceNum(-1);
      }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(ge->physicals.size()){
        for(unsigned int j = 0; j < ge->getNumMeshElements(); j++) {
          MElement *e = ge->getMeshElement(j);
          for(unsigned int k = 0; k < e->getNumVertices(); k++){
            e->getVertex(k)->forceNum(0);
          }
        }
      }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        if(v->getNum() == 0) v->forceNum(++n);
      }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        if(v->getNum() == -1) v->forceNum(++n);
      }
    }
  }
  else{
    // no physical groups
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->getNumMeshVertices(); j++) {
        ge->getMeshVertex(j)->forceNum(++n);
      }
    }
  }
}

void GModel::renumberMeshElements()
{
  destroyMeshCaches();
  setMaxElementNumber(0);
  std::vector<GEntity *> entities;
  getEntities(entities);

  // check if we will potentially only save a subset of elements, i.e. those
  // belonging to physical groups
  bool potentiallySaveSubset = false;
  if(!CTX::instance()->mesh.saveAll){
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->physicals.size()){
        potentiallySaveSubset = true;
        break;
      }
    }
  }

  unsigned int n = 0;
  if(potentiallySaveSubset){
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(ge->physicals.size()){
        for(unsigned int j = 0; j < ge->getNumMeshElements(); j++) {
          ge->getMeshElement(j)->forceNum(++n);
        }
      }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(ge->physicals.empty()){
        for(unsigned int j = 0; j < ge->getNumMeshElements(); j++) {
          ge->getMeshElement(j)->forceNum(++n);
        }
      }
    }
  }
  else{
    for(unsigned int i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->getNumMeshElements(); j++) {
        ge->getMeshElement(j)->forceNum(++n);
      }
    }
  }
}

int GModel::getNumMeshElements(unsigned c[6])
{
  c[0] = 0;
  c[1] = 0;
  c[2] = 0;
  c[3] = 0;
  c[4] = 0;
  c[5] = 0;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2] + c[3] + c[4] + c[5]) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2]) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0]) return 1;
  return 0;
}

MElement *GModel::getMeshElementByCoord(SPoint3 &p, int dim, bool strict)
{
  if(!_elementOctree) {
    Msg::Debug("Rebuilding mesh element octree");
    _elementOctree = new MElementOctree(this);
  }
  return _elementOctree->find(p.x(), p.y(), p.z(), dim, strict);
}

std::vector<MElement *> GModel::getMeshElementsByCoord(SPoint3 &p, int dim,
                                                       bool strict)
{
  if(!_elementOctree) {
    Msg::Debug("Rebuilding mesh element octree");
    _elementOctree = new MElementOctree(this);
  }
  return _elementOctree->findAll(p.x(), p.y(), p.z(), dim, strict);
}

void GModel::rebuildMeshVertexCache(bool onlyIfNecessary)
{
  if(!onlyIfNecessary ||
     (_vertexVectorCache.empty() && _vertexMapCache.empty())) {
    _vertexVectorCache.clear();
    _vertexMapCache.clear();
    bool dense = false;
    if(_maxVertexNum == getNumMeshVertices()) {
      Msg::Debug("We have a dense vertex numbering in the cache");
      dense = true;
    }
    else if(_maxVertexNum < 10 * getNumMeshVertices()) {
      Msg::Debug(
        "We have a fairly dense vertex numbering - still using cache vector");
      dense = true;
    }
    std::vector<GEntity *> entities;
    getEntities(entities);
    if(dense) {
      // numbering starts at 1
      _vertexVectorCache.resize(_maxVertexNum + 1, (MVertex *)0);
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
          _vertexVectorCache[entities[i]->mesh_vertices[j]->getNum()] =
            entities[i]->mesh_vertices[j];
    }
    else {
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
          _vertexMapCache[entities[i]->mesh_vertices[j]->getNum()] =
            entities[i]->mesh_vertices[j];
    }
  }
}

MVertex *GModel::getMeshVertexByTag(int n)
{
  if(_vertexVectorCache.empty() && _vertexMapCache.empty()) {
    Msg::Debug("Rebuilding mesh vertex cache");
    rebuildMeshVertexCache();
  }

  if(n < (int)_vertexVectorCache.size())
    return _vertexVectorCache[n];
  else
    return _vertexMapCache[n];
}

void GModel::getMeshVerticesForPhysicalGroup(int dim, int num,
                                             std::vector<MVertex *> &v)
{
  v.clear();
  std::map<int, std::vector<GEntity *> > groups;
  getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity *> >::const_iterator it = groups.find(num);
  if(it == groups.end()) return;
  const std::vector<GEntity *> &entities = it->second;
  std::set<MVertex *> sv;
  for(unsigned int i = 0; i < entities.size(); i++) {
    if(dim == 0) {
      GVertex *g = (GVertex *)entities[i];
      sv.insert(g->mesh_vertices[0]);
    }
    else {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        for(std::size_t k = 0; k < e->getNumVertices(); k++)
          sv.insert(e->getVertex(k));
      }
    }
  }
  v.insert(v.begin(), sv.begin(), sv.end());
}

MElement *GModel::getMeshElementByTag(int n)
{
  if(_elementVectorCache.empty() && _elementMapCache.empty()) {
    Msg::Debug("Rebuilding mesh element cache");
    _elementVectorCache.clear();
    _elementMapCache.clear();
    bool dense = false;
    if(_maxElementNum == getNumMeshElements()) {
      Msg::Debug("We have a dense element numbering in the cache");
      dense = true;
    }
    else if(_maxElementNum < 10 * getNumMeshElements()) {
      Msg::Debug(
        "We have a fairly dense element numbering - still using cache vector");
      dense = true;
    }
    std::vector<GEntity *> entities;
    getEntities(entities);
    if(dense) {
      // numbering starts at 1
      _elementVectorCache.resize(_maxElementNum + 1, (MElement *)0);
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          _elementVectorCache[e->getNum()] = e;
        }
    }
    else {
      for(unsigned int i = 0; i < entities.size(); i++)
        for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++) {
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

int GModel::getMeshElementIndex(MElement *e)
{
  if(!e) return 0;
  if(_elementIndexCache.empty()) return e->getNum();
  std::map<int, int>::iterator it = _elementIndexCache.find(e->getNum());
  if(it != _elementIndexCache.end()) return it->second;
  return e->getNum();
}

void GModel::setMeshElementIndex(MElement *e, int index)
{
  _elementIndexCache[e->getNum()] = index;
}

template <class T>
static void removeInvisible(std::vector<T *> &elements, bool all)
{
  std::vector<T *> tmp;
  for(unsigned int i = 0; i < elements.size(); i++) {
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
  for(riter it = firstRegion(); it != lastRegion(); ++it) {
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->tetrahedra, all);
    removeInvisible((*it)->hexahedra, all);
    removeInvisible((*it)->prisms, all);
    removeInvisible((*it)->pyramids, all);
    removeInvisible((*it)->trihedra, all);
    removeInvisible((*it)->polyhedra, all);
    (*it)->deleteVertexArrays();
  }
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->triangles, all);
    removeInvisible((*it)->quadrangles, all);
    removeInvisible((*it)->polygons, all);
    (*it)->deleteVertexArrays();
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it) {
    bool all = !(*it)->getVisibility();
    removeInvisible((*it)->lines, all);
    (*it)->deleteVertexArrays();
  }
  destroyMeshCaches();
}

int GModel::indexMeshVertices(bool all, int singlePartition, bool renumber)
{
  std::vector<GEntity *> entities;
  getEntities(entities);

  // tag all mesh vertices with -1 (negative vertices will not be
  // saved)
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->setIndex(-1);

  // tag all mesh vertices belonging to elements that need to be saved with 0,
  // or with -2 if they need to be taken into account in the numbering but need
  // not to be saved (because we save a single partition and they are not used
  // in that partition)
  for(unsigned int i = 0; i < entities.size(); i++) {
    if(all || entities[i]->physicals.size() ||
       (entities[i]->getParentEntity() &&
        entities[i]->getParentEntity()->physicals.size())) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          if(singlePartition <= 0 || e->getPartition() == singlePartition)
            e->getVertex(k)->setIndex(0);
          else if(e->getVertex(k)->getIndex() == -1)
            e->getVertex(k)->setIndex(-2);
        }
      }
    }
  }

  // renumber all the mesh vertices tagged with 0
  int numVertices = 0, index = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      if(!v->getIndex()) {
        index++;
        numVertices++;
        if(renumber)
          v->setIndex(index);
        else
          v->setIndex(v->getNum());
      }
      else if(v->getIndex() == -2) {
        index++;
      }
    }
  }

  return numVertices;
}

void GModel::scaleMesh(double factor)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      v->x() *= factor;
      v->y() *= factor;
      v->z() *= factor;
    }
}

int GModel::partitionMesh(int numPart)
{
#if defined(HAVE_MESH) && (defined(HAVE_METIS))
  opt_mesh_partition_num(0, GMSH_SET, numPart);
  if(numPart > 0) {
    if(_numPartitions > 0) UnpartitionMesh(this);
    int ier = PartitionMesh(this);
    return ier;
  }
  else {
    return 1;
  }
#else
  Msg::Error("Mesh module not compiled");
  return 1;
#endif
}

int GModel::unpartitionMesh()
{
#if defined(HAVE_MESH)
  return UnpartitionMesh(this);
#else
  Msg::Error("Mesh module not compiled");
  return 1;
#endif
}

int GModel::convertOldPartitioningToNewOne()
{
#if defined(HAVE_MESH) && (defined(HAVE_METIS))
  int ier = ConvertOldPartitioningToNewOne(this);
  return ier;
#else
  Msg::Error("Mesh module not compiled");
  return 1;
#endif
}

void GModel::store(std::vector<MVertex *> &vertices, int dim,
                   std::map<int, std::vector<MElement *> > &entityMap,
                   std::map<int, std::map<int, std::string> > &physicalMap)
{
  _storeVerticesInEntities(vertices);
  _storeElementsInEntities(entityMap);
  _storePhysicalTagsInEntities(dim, physicalMap);
  _associateEntityWithMeshVertices();
}

void GModel::storeChain(int dim,
                        std::map<int, std::vector<MElement *> > &entityMap,
                        std::map<int, std::map<int, std::string> > &physicalMap)
{
  _storeElementsInEntities(entityMap);
  _storePhysicalTagsInEntities(dim, physicalMap);
  std::map<int, std::vector<MElement *> >::iterator it;
  for(it = entityMap.begin(); it != entityMap.end(); it++) {
    if(dim == 0)
      _chainVertices.insert(getVertexByTag(it->first));
    else if(dim == 1)
      _chainEdges.insert(getEdgeByTag(it->first));
    else if(dim == 2)
      _chainFaces.insert(getFaceByTag(it->first));
    else if(dim == 3)
      _chainRegions.insert(getRegionByTag(it->first));
  }
}

template <class T>
static void _addElements(std::vector<T *> &dst,
                         const std::vector<MElement *> &src)
{
  for(unsigned int i = 0; i < src.size(); i++) dst.push_back((T *)src[i]);
}

void GModel::_storeElementsInEntities(
  std::map<int, std::vector<MElement *> > &map)
{
  std::map<int, std::vector<MElement *> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it) {
    if(!it->second.size()) continue;
    int type = it->second[0]->getType();
    switch(type) {
    case TYPE_PNT: {
      GVertex *v = getVertexByTag(it->first);
      if(!v) {
        double x = it->second[0]->getVertex(0)->x();
        double y = it->second[0]->getVertex(0)->y();
        double z = it->second[0]->getVertex(0)->z();
        v = new discreteVertex(this, it->first, x, y, z);
        add(v);
      }
      if(!v->points.empty()) { // CAD points already have one by default
        v->points.clear();
        v->mesh_vertices.clear();
      }
      _addElements(v->points, it->second);
    } break;
    case TYPE_LIN: {
      GEdge *e = getEdgeByTag(it->first);
      if(!e) {
        e = new discreteEdge(this, it->first, 0, 0);
        add(e);
      }
      _addElements(e->lines, it->second);
    } break;
    case TYPE_TRI:
    case TYPE_QUA:
    case TYPE_POLYG: {
      GFace *f = getFaceByTag(it->first);
      if(!f) {
        f = new discreteFace(this, it->first);
        add(f);
      }
      if(type == TYPE_TRI)
        _addElements(f->triangles, it->second);
      else if(type == TYPE_QUA)
        _addElements(f->quadrangles, it->second);
      else
        _addElements(f->polygons, it->second);
    } break;
    case TYPE_TET:
    case TYPE_HEX:
    case TYPE_PYR:
    case TYPE_TRIH:
    case TYPE_PRI:
    case TYPE_POLYH: {
      GRegion *r = getRegionByTag(it->first);
      if(!r) {
        r = new discreteRegion(this, it->first);
        add(r);
      }
      if(type == TYPE_TET)
        _addElements(r->tetrahedra, it->second);
      else if(type == TYPE_HEX)
        _addElements(r->hexahedra, it->second);
      else if(type == TYPE_PRI)
        _addElements(r->prisms, it->second);
      else if(type == TYPE_PYR)
        _addElements(r->pyramids, it->second);
      else if(type == TYPE_TRIH)
        _addElements(r->trihedra, it->second);
      else
        _addElements(r->polyhedra, it->second);
    } break;
    }
  }
}

void GModel::_storeParentsInSubElements(
  std::map<int, std::vector<MElement *> > &map)
{
  std::map<int, std::vector<MElement *> >::const_iterator it;
  for(it = map.begin(); it != map.end(); ++it)
    for(unsigned int i = 0; i < it->second.size(); ++i)
      it->second[i]->updateParent(this);
}

template <class T>
static void _associateEntityWithElementVertices(GEntity *ge,
                                                std::vector<T *> &elements,
                                                bool force = false)
{
  for(unsigned int i = 0; i < elements.size(); i++) {
    for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++) {
      if(force || !elements[i]->getVertex(j)->onWhat() ||
         elements[i]->getVertex(j)->onWhat()->dim() > ge->dim())
        elements[i]->getVertex(j)->setEntity(ge);
    }
  }
}

void GModel::createGeometryOfDiscreteEntities()
{
  createTopologyFromMeshNew();
  exportDiscreteGEOInternals();

  Msg::Info("Creating the geometry of discrete surfaces");
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    if((*it)->geomType() == GEntity::DiscreteSurface)
      static_cast<discreteFace *>(*it)->createGeometry();
  }

  Msg::Info("Creating the geometry of discrete curves");
  for(eiter it = firstEdge(); it != lastEdge(); ++it) {
    if((*it)->geomType() == GEntity::DiscreteCurve)
      static_cast<discreteEdge *>(*it)->createGeometry();
  }
}

void GModel::_associateEntityWithMeshVertices()
{
  // loop on regions, then on faces, edges and vertices and store the entity
  // pointer in the the elements' vertices (this way we associate the entity of
  // lowest geometrical degree with each vertex)
  for(riter it = firstRegion(); it != lastRegion(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->tetrahedra);
    _associateEntityWithElementVertices(*it, (*it)->hexahedra);
    _associateEntityWithElementVertices(*it, (*it)->prisms);
    _associateEntityWithElementVertices(*it, (*it)->pyramids);
    _associateEntityWithElementVertices(*it, (*it)->trihedra);
    _associateEntityWithElementVertices(*it, (*it)->polyhedra);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->triangles);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles);
    _associateEntityWithElementVertices(*it, (*it)->polygons);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->lines);
  }
  for(viter it = firstVertex(); it != lastVertex(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->points);
  }
}

void GModel::_storeVerticesInEntities(std::map<int, MVertex *> &vertices)
{
  std::map<int, MVertex *>::iterator it = vertices.begin();
  for(; it != vertices.end(); ++it) {
    MVertex *v = it->second;
    GEntity *ge = v->onWhat();
    if(ge)
      ge->mesh_vertices.push_back(v);
    else {
      delete v; // we delete all unused vertices
      it->second = 0;
    }
  }
}

void GModel::_storeVerticesInEntities(std::vector<MVertex *> &vertices)
{
  for(unsigned int i = 0; i < vertices.size(); i++) {
    MVertex *v = vertices[i];
    if(v) { // the vector is allowed to have null entries
      GEntity *ge = v->onWhat();
      if(ge)
        ge->mesh_vertices.push_back(v);
      else {
        delete v; // we delete all unused vertices
        vertices[i] = 0;
      }
    }
  }
}

void GModel::pruneMeshVertexAssociations()
{
  std::vector<GEntity *> entities;
  std::vector<MVertex *> vertices;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++) {
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      v->setEntity(0);
      vertices.push_back(v);
    }
    entities[i]->mesh_vertices.clear();
  }
  _associateEntityWithMeshVertices();
  // associate mesh vertices primarily with chain entities
  for(riter it = _chainRegions.begin(); it != _chainRegions.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->tetrahedra, true);
    _associateEntityWithElementVertices(*it, (*it)->hexahedra, true);
    _associateEntityWithElementVertices(*it, (*it)->prisms, true);
    _associateEntityWithElementVertices(*it, (*it)->pyramids, true);
    _associateEntityWithElementVertices(*it, (*it)->trihedra, true);
    _associateEntityWithElementVertices(*it, (*it)->polyhedra, true);
  }
  for(fiter it = _chainFaces.begin(); it != _chainFaces.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->triangles, true);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles, true);
    _associateEntityWithElementVertices(*it, (*it)->polygons, true);
  }
  for(eiter it = _chainEdges.begin(); it != _chainEdges.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->lines, true);
  }
  for(viter it = _chainVertices.begin(); it != _chainVertices.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->points, true);
  }
  _storeVerticesInEntities(vertices);
}

void GModel::_storePhysicalTagsInEntities(
  int dim, std::map<int, std::map<int, std::string> > &map)
{
  std::map<int, std::map<int, std::string> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it) {
    GEntity *ge = 0;
    switch(dim) {
    case 0: ge = getVertexByTag(it->first); break;
    case 1: ge = getEdgeByTag(it->first); break;
    case 2: ge = getFaceByTag(it->first); break;
    case 3: ge = getRegionByTag(it->first); break;
    }

    if(ge) {
      std::map<int, std::string>::const_iterator it2 = it->second.begin();
      for(; it2 != it->second.end(); ++it2) {
        if(std::find(ge->physicals.begin(), ge->physicals.end(), it2->first) ==
           ge->physicals.end()) {
          ge->physicals.push_back(it2->first);
        }
      }
    }
  }
}

static bool getMeshVertices(int num, int *indices,
                            std::map<int, MVertex *> &map,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(!map.count(indices[i])) {
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices, int minVertex = 0)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < minVertex ||
       indices[i] > (int)(vec.size() - 1 + minVertex)) {
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

GModel *GModel::createGModel(std::map<int, MVertex *> &vertexMap,
                             std::vector<int> &elementNum,
                             std::vector<std::vector<int> > &vertexIndices,
                             std::vector<int> &elementType,
                             std::vector<int> &physical,
                             std::vector<int> &elementary,
                             std::vector<int> &partition)
{
  int numVertices = (int)vertexMap.size();
  int numElement = (int)elementNum.size();

  if(numElement != (int)vertexIndices.size()) {
    Msg::Error("Dimension in vertices numbers");
    return 0;
  }
  if(numElement != (int)elementType.size()) {
    Msg::Error("Dimension in elementType numbers");
    return 0;
  }
  if(numElement != (int)physical.size()) {
    Msg::Error("Dimension in physical numbers");
    return 0;
  }
  if(numElement != (int)elementary.size()) {
    Msg::Error("Dimension in elementary numbers");
    return 0;
  }
  if(numElement != (int)partition.size()) {
    Msg::Error("Dimension in partition numbers");
    return 0;
  }

  GModel *gm = new GModel();
  std::map<int, std::vector<MElement *> > elements[11];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::vector<MVertex *> vertexVector;

  std::map<int, MVertex *>::const_iterator it = vertexMap.begin();
  std::map<int, MVertex *>::const_iterator end = vertexMap.end();

  int maxVertex = std::numeric_limits<int>::min();
  int minVertex = std::numeric_limits<int>::max();
  int num;

  for(; it != end; ++it) {
    num = it->first;
    minVertex = std::min(minVertex, num);
    maxVertex = std::max(maxVertex, num);
  }
  if(minVertex == std::numeric_limits<int>::max())
    Msg::Error("Could not determine the min index of vertices");

  // if the vertex numbering is dense, transfer the map into a vector to speed
  // up element creation
  if((minVertex == 1 && maxVertex == numVertices) ||
     (minVertex == 0 && maxVertex == numVertices - 1)) {
    Msg::Info("Vertex numbering is dense");
    vertexVector.resize(vertexMap.size() + 1);
    if(minVertex == 1)
      vertexVector[0] = 0;
    else
      vertexVector[numVertices] = 0;
    std::map<int, MVertex *>::const_iterator it = vertexMap.begin();
    for(; it != vertexMap.end(); ++it) vertexVector[it->first] = it->second;
    vertexMap.clear();
  }

  int *indices;
  int nbVertices;
  for(int i = 0; i < numElement; ++i) {
    num = elementNum[i];
    std::vector<MVertex *> vertices;
    nbVertices = (int)vertexIndices[i].size();
    indices = &vertexIndices[i][0];
    if(vertexVector.size()) {
      if(!getMeshVertices(nbVertices, indices, vertexVector, vertices)) {
        Msg::Error("Vertex not found aborting");
        delete gm;
        return 0;
      }
    }
    else {
      if(!getMeshVertices(nbVertices, indices, vertexMap, vertices)) {
        Msg::Error("Vertex not found aborting");
        delete gm;
        return 0;
      }
    }

    MElementFactory f;
    MElement *e = f.create(elementType[i], vertices, num, partition[i]);
    if(!e) {
      Msg::Error("Unknown type of element %d", elementType[i]);
      delete gm;
      return 0;
    }
    switch(e->getType()) {
    case TYPE_PNT: elements[0][elementary[i]].push_back(e); break;
    case TYPE_LIN: elements[1][elementary[i]].push_back(e); break;
    case TYPE_TRI: elements[2][elementary[i]].push_back(e); break;
    case TYPE_QUA: elements[3][elementary[i]].push_back(e); break;
    case TYPE_TET: elements[4][elementary[i]].push_back(e); break;
    case TYPE_HEX: elements[5][elementary[i]].push_back(e); break;
    case TYPE_PRI: elements[6][elementary[i]].push_back(e); break;
    case TYPE_PYR: elements[7][elementary[i]].push_back(e); break;
    case TYPE_TRIH: elements[8][elementary[i]].push_back(e); break;
    case TYPE_POLYG: elements[9][elementary[i]].push_back(e); break;
    case TYPE_POLYH: elements[10][elementary[i]].push_back(e); break;
    default:
      Msg::Error("Wrong type of element");
      delete gm;
      return 0;
    }
    int dim = e->getDim();
    if(physical[i] && (!physicals[dim].count(elementary[i]) ||
                       !physicals[dim][elementary[i]].count(physical[i])))
      physicals[dim][elementary[i]][physical[i]] = "unnamed";
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    gm->_storeElementsInEntities(elements[i]);

  // associate the correct geometrical entity with each mesh vertex
  gm->_associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    gm->_storeVerticesInEntities(vertexVector);
  else
    gm->_storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++) gm->_storePhysicalTagsInEntities(i, physicals[i]);

  return gm;
}

GModel *GModel::createGModel(
  std::map<int, std::vector<MElement *> > &entityToElementsMap,
  std::map<int, std::vector<int> > &entityToPhysicalsMap)
{
  GModel *gm = new GModel();

  std::map<int, MVertex *> vertexMap;
  std::map<int, std::map<int, std::string> > physicals[4];
  for(std::map<int, std::vector<MElement *> >::iterator it =
        entityToElementsMap.begin();
      it != entityToElementsMap.end(); it++) {
    int entity = it->first;
    for(std::size_t iE = 0; iE < it->second.size(); iE++) {
      MElement *me = it->second[iE];
      for(std::size_t iV = 0; iV < me->getNumVertices(); iV++) {
        vertexMap[me->getVertex(iV)->getNum()] = me->getVertex(iV);
      }
      std::vector<int> entityPhysicals = entityToPhysicalsMap[entity];
      for(std::size_t i = 0; i < entityPhysicals.size(); i++) {
        physicals[me->getDim()][entity][entityPhysicals[i]] = "unnamed";
      }
    }
  }

  gm->_storeElementsInEntities(entityToElementsMap);
  gm->_associateEntityWithMeshVertices();
  gm->_storeVerticesInEntities(vertexMap);
  for(int i = 0; i < 4; i++) gm->_storePhysicalTagsInEntities(i, physicals[i]);

  return gm;
}

void GModel::checkMeshCoherence(double tolerance)
{
  int numEle = getNumMeshElements();
  if(!numEle) return;

  Msg::StatusBar(true, "Checking mesh coherence (%d elements)...", numEle);

  SBoundingBox3d bbox = bounds();
  double lc = bbox.empty() ? 1. : norm(SVector3(bbox.max(), bbox.min()));
  double eps = lc * tolerance;

  std::vector<GEntity *> entities;
  getEntities(entities);

  // check for duplicate mesh vertices
  {
    Msg::Info("Checking for duplicate vertices...");
    std::vector<MVertex *> vertices;
    for(unsigned int i = 0; i < entities.size(); i++)
      vertices.insert(vertices.end(), entities[i]->mesh_vertices.begin(),
                      entities[i]->mesh_vertices.end());
    MVertexRTree pos(eps);
    std::set<MVertex *> duplicates;
    int num = pos.insert(vertices, true, &duplicates);
    if(num) {
      Msg::Error("%d duplicate vert%s: see `duplicate_vertices.pos'", num,
                 num > 1 ? "ices" : "ex");
      FILE *fp = Fopen("duplicate_vertices.pos", "w");
      if(fp) {
        fprintf(fp, "View \"duplicate vertices\"{\n");
        for(std::set<MVertex *>::iterator it = duplicates.begin();
            it != duplicates.end(); it++) {
          MVertex *v = *it;
          fprintf(fp, "SP(%.16g,%.16g,%.16g){%d};\n", v->x(), v->y(), v->z(),
                  v->getNum());
        }
        fprintf(fp, "};\n");
        fclose(fp);
      }
    }
  }

  // check for duplicate elements
  {
    Msg::Info("Checking for duplicate elements...");
    std::vector<MVertex *> vertices;
    for(unsigned int i = 0; i < entities.size(); i++) {
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        double vol = e->getVolume();
        if(vol < 0)
          Msg::Warning("Element %d has negative volume", e->getNum());
        else if(vol < eps * eps * eps)
          Msg::Warning("Element %d has zero volume", e->getNum());
        SPoint3 p = e->barycenter();
        vertices.push_back(new MVertex(p.x(), p.y(), p.z()));
      }
    }
    MVertexRTree pos(eps);
    int num = pos.insert(vertices, true);
    for(unsigned int i = 0; i < vertices.size(); i++) delete vertices[i];
    if(num) Msg::Error("%d duplicate element%s", num, num > 1 ? "s" : "");
  }

  Msg::StatusBar(true, "Done checking mesh coherence");
}

int GModel::removeDuplicateMeshVertices(double tolerance)
{
  Msg::StatusBar(true, "Removing duplicate mesh vertices...");

  SBoundingBox3d bbox = bounds();
  double lc = bbox.empty() ? 1. : norm(SVector3(bbox.max(), bbox.min()));
  double eps = lc * tolerance;

  std::vector<GEntity *> entities;
  getEntities(entities);

  // re-index all vertices (don't use MVertex::getNum(), as we want to be able
  // to remove diplicate vertices from "incorrect" meshes, where vertices with
  // the same number are duplicated)
  int n = 0;
  for(unsigned int i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(unsigned int j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      v->setIndex(++n);
    }
  }

  MVertexRTree pos(eps);
  std::map<int, MVertex *> vertices;
  std::map<MVertex *, MVertex *> duplicates;
  for(unsigned int i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(unsigned int j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      MVertex *v2 = pos.insert(v);
      if(v2)
        duplicates[v] = v2; // v should be removed
      else
        vertices[v->getIndex()] = v;
    }
  }

  int num = (int)duplicates.size();
  Msg::Info("Found %d duplicate vertices ", num);

  if(!num) {
    Msg::Info("No duplicate vertices found");
    return 0;
  }

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    // clear list of vertices owned by entity
    ge->mesh_vertices.clear();
    // replace vertices in element
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        std::map<MVertex *, MVertex *>::iterator it =
          duplicates.find(e->getVertex(k));
        if(it != duplicates.end()) e->setVertex(k, it->second);
      }
    }
    // replace vertices in periodic copies
    std::map<MVertex *, MVertex *> &corrVtcs = ge->correspondingVertices;
    if(corrVtcs.size()) {
      std::map<MVertex *, MVertex *>::iterator cIter;
      for(cIter = duplicates.begin(); cIter != duplicates.end(); ++cIter) {
        MVertex *oldTgt = cIter->first;
        MVertex *newTgt = cIter->second;
        std::map<MVertex *, MVertex *>::iterator cvIter = corrVtcs.find(oldTgt);
        if(cvIter != corrVtcs.end()) {
          MVertex *src = cvIter->second;
          corrVtcs.erase(cvIter);
          corrVtcs[newTgt] = src;
        }
      }
      for(cIter = corrVtcs.begin(); cIter != corrVtcs.end(); ++cIter) {
        MVertex *oldSrc = cIter->second;
        std::map<MVertex *, MVertex *>::iterator nIter =
          duplicates.find(oldSrc);
        if(nIter != duplicates.end()) {
          MVertex *tgt = cIter->first;
          MVertex *newSrc = nIter->second;
          corrVtcs[tgt] = newSrc;
        }
      }
    }
  }

  destroyMeshCaches();
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);

  // delete duplicates
  std::vector<MVertex *> to_delete;
  for(std::map<MVertex *, MVertex *>::iterator it = duplicates.begin();
      it != duplicates.end(); it++)
    to_delete.push_back(it->first);
  for(unsigned int i = 0; i < to_delete.size(); i++) delete to_delete[i];

  if(num)
    Msg::Info("Removed %d duplicate mesh %s", num,
              num > 1 ? "vertices" : "vertex");

  Msg::StatusBar(true, "Done removing duplicate mesh vertices");
  return num;
}

/*
struct ElementSort{
  MElement *ele;
  std::vector<int> sortedVertexNum;
};

struct Less_ElementSort{
  return a->sortedVertexNum < b->sortedVertexNum;
};

int GModel::removeDuplicateMeshElements()
{

}
*/

static void recurConnectMElementsByMFace(
  const MFace &f, std::multimap<MFace, MElement *, Less_Face> &e2f,
  std::set<MElement *> &group, std::set<MFace, Less_Face> &touched,
  int recur_level)
{
  // this is very slow...
  std::stack<MFace> _stack;
  _stack.push(f);

  while(!_stack.empty()) {
    MFace ff = _stack.top();
    _stack.pop();
    if(touched.find(ff) == touched.end()) {
      touched.insert(ff);
      for(std::multimap<MFace, MElement *, Less_Face>::iterator it =
            e2f.lower_bound(ff);
          it != e2f.upper_bound(ff); ++it) {
        group.insert(it->second);
        for(int i = 0; i < it->second->getNumFaces(); ++i) {
          _stack.push(it->second->getFace(i));
        }
      }
    }
  }
}

static int connectedVolumes(std::vector<MElement *> &elements,
                            std::vector<std::vector<MElement *> > &regs)
{
  std::multimap<MFace, MElement *, Less_Face> e2f;
  for(unsigned int i = 0; i < elements.size(); ++i) {
    for(int j = 0; j < elements[i]->getNumFaces(); j++) {
      e2f.insert(std::make_pair(elements[i]->getFace(j), elements[i]));
    }
  }
  while(!e2f.empty()) {
    std::set<MElement *> group;
    std::set<MFace, Less_Face> touched;
    recurConnectMElementsByMFace(e2f.begin()->first, e2f, group, touched, 0);
    std::vector<MElement *> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    regs.push_back(temp);
    for(std::set<MFace, Less_Face>::iterator it = touched.begin();
        it != touched.end(); ++it)
      e2f.erase(*it);
  }
  return regs.size();
}

static void recurConnectMElementsByMEdge(
  const MEdge &e, std::multimap<MEdge, MElement *, Less_Edge> &e2e,
  std::set<MElement *> &group, std::set<MEdge, Less_Edge> &touched)
{
  // this is very slow...
  std::stack<MEdge> _stack;
  _stack.push(e);

  while(!_stack.empty()) {
    MEdge ee = _stack.top();
    _stack.pop();
    if(touched.find(ee) == touched.end()) {
      touched.insert(ee);
      for(std::multimap<MEdge, MElement *, Less_Edge>::iterator it =
            e2e.lower_bound(ee);
          it != e2e.upper_bound(ee); ++it) {
        group.insert(it->second);
        for(int i = 0; i < it->second->getNumEdges(); ++i) {
          _stack.push(it->second->getEdge(i));
        }
      }
    }
  }
}

static int connectedSurfaces(std::vector<MElement *> &elements,
                             std::vector<std::vector<MElement *> > &faces)
{
  std::multimap<MEdge, MElement *, Less_Edge> e2e;
  for(unsigned int i = 0; i < elements.size(); ++i) {
    for(int j = 0; j < elements[i]->getNumEdges(); j++) {
      e2e.insert(std::make_pair(elements[i]->getEdge(j), elements[i]));
    }
  }
  while(!e2e.empty()) {
    std::set<MElement *> group;
    std::set<MEdge, Less_Edge> touched;
    recurConnectMElementsByMEdge(e2e.begin()->first, e2e, group, touched);
    std::vector<MElement *> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    faces.push_back(temp);
    for(std::set<MEdge, Less_Edge>::iterator it = touched.begin();
        it != touched.end(); ++it)
      e2e.erase(*it);
  }
  return faces.size();
}

void GModel::alignPeriodicBoundaries()
{
  Msg::Debug("Aligning periodic boundaries");

  // realigning edges

  for(eiter it = firstEdge(); it != lastEdge(); ++it) {
    GEdge *tgt = *it;
    GEdge *src = dynamic_cast<GEdge *>(tgt->getMeshMaster());

    if(src != NULL && src != tgt) {
      // compose a search list on master edge

      std::map<MEdge, MLine *, Less_Edge> srcLines;
      for(unsigned int i = 0; i < src->getNumMeshElements(); i++) {
        MLine *srcLine = dynamic_cast<MLine *>(src->getMeshElement(i));
        if(!srcLine) {
          Msg::Error("Master element %d is not an edge ",
                     src->getMeshElement(i)->getNum());
          return;
        }
        srcLines[MEdge(srcLine->getVertex(0), srcLine->getVertex(1))] = srcLine;
      }

      // run through slave edge elements
      // - check whether we find a counterpart (if not, flag error)
      // - check orientation and reorient if necessary

      for(unsigned int i = 0; i < tgt->getNumMeshElements(); ++i) {
        MLine *tgtLine = dynamic_cast<MLine *>(tgt->getMeshElement(i));

        if(!tgtLine) {
          Msg::Error("Slave element %d is not an edge ",
                     tgt->getMeshElement(i)->getNum());
          return;
        }

        MVertex *tgtVtcs[2];
        for(int iVtx = 0; iVtx < 2; iVtx++) {
          MVertex *tgtVtx = tgtLine->getVertex(iVtx);
          GEntity *ge = tgtVtx->onWhat();
          std::map<MVertex *, MVertex *> &geV2v = ge->correspondingVertices;
          std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
          std::map<MVertex *, MVertex *>::iterator srcIter = v2v.find(tgtVtx);
          if(srcIter == v2v.end() || !srcIter->second) {
            // Msg::Info("Cannot find periodic counterpart of vertex %d on edge
            // %d"
            //              ", looking on entity %d of dimension %d",
            //              tgtVtx->getNum(),tgt->tag(),ge->tag(),ge->dim());
            srcIter = geV2v.find(tgtVtx);
            if(srcIter == geV2v.end() || !srcIter->second) {
              Msg::Error(
                "Cannot find periodic counterpart of vertex %d on edge %d"
                " nor on %d",
                tgtVtx->getNum(), tgt->tag(), ge->tag());
              return;
            }
            else
              tgtVtcs[iVtx] = srcIter->second;
          }
          else
            tgtVtcs[iVtx] = srcIter->second;
        }

        MEdge tgtEdge(tgtVtcs[0], tgtVtcs[1]);

        std::map<MEdge, MLine *, Less_Edge>::iterator sIter =
          srcLines.find(tgtEdge);

        if(sIter == srcLines.end() || !sIter->second) {
          Msg::Error("Can't find periodic counterpart of edge %d-%d on edge %d"
                     ", connected to edge %d-%d on %d",
                     tgtLine->getVertex(0)->getNum(),
                     tgtLine->getVertex(1)->getNum(), tgt->tag(),
                     tgtVtcs[0]->getNum(), tgtVtcs[1]->getNum(), src->tag());
          return;
        }
        else {
          MLine *srcLine = sIter->second;
          MEdge srcEdge(srcLine->getVertex(0), srcLine->getVertex(1));
          if(tgtEdge.computeCorrespondence(srcEdge) == -1) tgtLine->reverse();
        }
      }
    }
  }

  // run through all model faces

  for(GModel::fiter it = firstFace(); it != lastFace(); ++it) {
    GFace *tgt = *it;
    GFace *src = dynamic_cast<GFace *>(tgt->getMeshMaster());
    if(src != NULL && src != tgt) {
      std::map<MFace, MElement *, Less_Face> srcElmts;

      for(unsigned int i = 0; i < src->getNumMeshElements(); ++i) {
        MElement *srcElmt = src->getMeshElement(i);
        int nbVtcs = 0;
        if(dynamic_cast<MTriangle *>(srcElmt)) nbVtcs = 3;
        if(dynamic_cast<MQuadrangle *>(srcElmt)) nbVtcs = 4;
        std::vector<MVertex *> vtcs;
        vtcs.reserve(nbVtcs);
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          vtcs.push_back(srcElmt->getVertex(iVtx));
        }
        srcElmts[MFace(vtcs)] = srcElmt;
      }

      for(unsigned int i = 0; i < tgt->getNumMeshElements(); ++i) {
        MElement *tgtElmt = tgt->getMeshElement(i);
        MTriangle *tgtTri = dynamic_cast<MTriangle *>(tgtElmt);
        MQuadrangle *tgtQua = dynamic_cast<MQuadrangle *>(tgtElmt);

        int nbVtcs = 0;
        if(tgtTri) nbVtcs = 3;
        if(tgtQua) nbVtcs = 4;

        std::vector<MVertex *> vtcs;
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          MVertex *vtx = tgtElmt->getVertex(iVtx);
          GEntity *ge = vtx->onWhat();

          std::map<MVertex *, MVertex *> &geV2v = ge->correspondingVertices;
          std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;

          std::map<MVertex *, MVertex *>::iterator vIter = v2v.find(vtx);
          if(vIter == v2v.end() || !vIter->second) {
            Msg::Info("Could not find copy of vertex %d in face %d"
                      ", looking in entity %d of dimension %d",
                      vtx->getNum(), tgt->tag(), ge->tag(), ge->dim());
            vIter = geV2v.find(vtx);
            if(vIter == geV2v.end() || !vIter->second) {
              Msg::Error("Could not find copy of vertex %d in %d nor in %d",
                         vtx->getNum(), tgt->tag(), ge->tag());
              return;
            }
            else
              vtcs.push_back(vIter->second);
          }
          else
            vtcs.push_back(vIter->second);
        }
        MFace tgtFace(vtcs);

        std::map<MFace, MElement *>::iterator mIter = srcElmts.find(tgtFace);
        if(mIter == srcElmts.end()) {
          std::ostringstream faceDef;
          for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
            faceDef << vtcs[iVtx]->getNum() << " ";
          }
          Msg::Error("Cannot find periodic counterpart of face %s in face %d "
                     "connected to %d",
                     faceDef.str().c_str(), tgt->tag(), src->tag());
          return;
        }
        else {
          const MFace &srcFace = mIter->first;
          MElement *srcElmt = mIter->second;
          std::vector<MVertex *> srcVtcs;

          if(tgtTri && !dynamic_cast<MTriangle *>(srcElmt)) throw;
          if(tgtQua && !dynamic_cast<MQuadrangle *>(srcElmt)) throw;

          int rotation = 0;
          bool swap = false;

          if(!tgtFace.computeCorrespondence(srcFace, rotation, swap)) {
            Msg::Error(
              "Non-corresponding face %d-%d-%d (slave) %d-%d-%d (master)",
              tgtElmt->getVertex(0)->getNum(), tgtElmt->getVertex(1)->getNum(),
              tgtElmt->getVertex(2)->getNum(), srcElmt->getVertex(0)->getNum(),
              srcElmt->getVertex(1)->getNum(), srcElmt->getVertex(2)->getNum());
            return;
          }

          if(tgtTri) tgtTri->reorient(rotation, swap);
          if(tgtQua) tgtQua->reorient(rotation, swap);
        }
      }
    }
  }
  Msg::Debug("Done aligning periodic boundaries");
}

void GModel::makeDiscreteRegionsSimplyConnected()
{
  Msg::Info("Making discrete regions simply connected...");

  std::vector<discreteRegion *> discRegions;
  for(riter it = firstRegion(); it != lastRegion(); it++)
    if((*it)->geomType() == GEntity::DiscreteVolume)
      discRegions.push_back((discreteRegion *)*it);

  std::set<MVertex *> touched;

  for(std::vector<discreteRegion *>::iterator itR = discRegions.begin();
      itR != discRegions.end(); itR++) {
    std::vector<MElement *> allElements((*itR)->getNumMeshElements());
    for(unsigned int i = 0; i < (*itR)->getNumMeshElements(); i++)
      allElements[i] = (*itR)->getMeshElement(i);

    std::vector<std::vector<MElement *> > conRegions;
    int nbRegions = connectedVolumes(allElements, conRegions);
    if(nbRegions > 1) remove(*itR);

    for(int ire = 0; ire < nbRegions; ire++) {
      int numR =
        (nbRegions == 1) ? (*itR)->tag() : getMaxElementaryNumber(3) + 1;
      discreteRegion *r = new discreteRegion(this, numR);
      add(r);
      std::vector<MElement *> myElements = conRegions[ire];
      std::set<MVertex *> myVertices;
      for(unsigned int i = 0; i < myElements.size(); i++) {
        MElement *e = myElements[i];
        std::vector<MVertex *> verts;
        e->getVertices(verts);
        for(unsigned int k = 0; k < verts.size(); k++) {
          if(verts[k]->onWhat() && verts[k]->onWhat()->dim() == 3) {
            if(touched.find(verts[k]) == touched.end()) {
              verts[k]->setEntity(r);
              myVertices.insert(verts[k]);
              touched.insert(verts[k]);
            }
          }
        }
        MElementFactory factory;
        MElement *e2 = factory.create(e->getTypeForMSH(), verts, e->getNum(),
                                      e->getPartition());
        switch(e2->getType()) {
        case TYPE_TET: r->tetrahedra.push_back((MTetrahedron *)e2); break;
        case TYPE_HEX: r->hexahedra.push_back((MHexahedron *)e2); break;
        case TYPE_PRI: r->prisms.push_back((MPrism *)e2); break;
        case TYPE_PYR: r->pyramids.push_back((MPyramid *)e2); break;
        case TYPE_TRIH: r->trihedra.push_back((MTrihedron *)e2); break;
        }
      }
      r->mesh_vertices.insert(r->mesh_vertices.begin(), myVertices.begin(),
                              myVertices.end());
    }
  }

  Msg::Info("Done making discrete regions simply connected");
}

void GModel::makeDiscreteFacesSimplyConnected()
{
  Msg::Info("Making discrete faces simply connected...");

  std::vector<discreteFace *> discFaces;
  for(fiter it = firstFace(); it != lastFace(); it++)
    if((*it)->geomType() == GEntity::DiscreteSurface)
      discFaces.push_back((discreteFace *)*it);

  std::set<MVertex *> touched;

  for(std::vector<discreteFace *>::iterator itF = discFaces.begin();
      itF != discFaces.end(); itF++) {
    std::vector<MElement *> allElements((*itF)->getNumMeshElements());
    for(unsigned int i = 0; i < (*itF)->getNumMeshElements(); i++)
      allElements[i] = (*itF)->getMeshElement(i);

    std::vector<std::vector<MElement *> > conFaces;
    int nbFaces = connectedSurfaces(allElements, conFaces);
    if(nbFaces > 1) remove(*itF);

    for(int ifa = 0; ifa < nbFaces; ifa++) {
      int numF = (nbFaces == 1) ? (*itF)->tag() : getMaxElementaryNumber(2) + 1;
      discreteFace *f = new discreteFace(this, numF);
      add(f);
      std::vector<MElement *> myElements = conFaces[ifa];
      std::set<MVertex *> myVertices;
      for(unsigned int i = 0; i < myElements.size(); i++) {
        MElement *e = myElements[i];
        std::vector<MVertex *> verts;
        e->getVertices(verts);
        for(unsigned int k = 0; k < verts.size(); k++) {
          if(verts[k]->onWhat() && verts[k]->onWhat()->dim() == 2) {
            if(touched.find(verts[k]) == touched.end()) {
              verts[k]->setEntity(f);
              myVertices.insert(verts[k]);
              touched.insert(verts[k]);
            }
          }
        }
        MElementFactory factory;
        MElement *e2 = factory.create(e->getTypeForMSH(), verts, e->getNum(),
                                      e->getPartition());
        if(e2->getType() == TYPE_TRI)
          f->triangles.push_back((MTriangle *)e2);
        else
          f->quadrangles.push_back((MQuadrangle *)e2);
      }
      f->mesh_vertices.insert(f->mesh_vertices.begin(), myVertices.begin(),
                              myVertices.end());
    }
  }

  Msg::Info("Done making discrete faces simply connected");
}

void GModel::createTopologyFromMesh()
{
  makeDiscreteRegionsSimplyConnected();
  makeDiscreteFacesSimplyConnected();
  createTopologyFromMeshNew();
  exportDiscreteGEOInternals();
}

static void
makeSimplyConnected(std::map<int, std::vector<MElement *> > elements[11])
{
  // only for tetras and triangles
  Msg::Info("Make simply connected regions and surfaces");
  std::vector<int> regs;
  for(std::map<int, std::vector<MElement *> >::iterator it =
        elements[4].begin();
      it != elements[4].end(); it++)
    regs.push_back(it->first);
  std::multimap<MFace, MElement *, Less_Face> f2e;
  if(regs.size() > 2) {
    for(unsigned int i = 0; i < regs.size(); i++) {
      for(unsigned int j = 0; j < elements[4][regs[i]].size(); j++) {
        MElement *el = elements[4][regs[i]][j];
        for(int k = 0; k < el->getNumFaces(); k++)
          f2e.insert(std::make_pair(el->getFace(k), el));
      }
    }
  }
  for(unsigned int i = 0; i < regs.size(); i++) {
    int ri = regs[i];
    std::vector<MElement *> allElements;
    for(unsigned int j = 0; j < elements[4][ri].size(); j++)
      allElements.push_back(elements[4][ri][j]);
    std::vector<std::vector<MElement *> > conRegions;
    int nbConRegions = connectedVolumes(allElements, conRegions);
    Msg::Info("%d connected regions (reg=%d)", nbConRegions, ri);
    unsigned int maxNumEl = 1;
    for(int j = 0; j < nbConRegions; j++)
      if(conRegions[j].size() > maxNumEl) maxNumEl = conRegions[j].size();
    for(int j = 0; j < nbConRegions; j++) {
      // remove conRegions containing few elements
      if(conRegions[j].size() < maxNumEl * 1.e-4) {
        // find adjacent region
        int r2 = ri;
        if(regs.size() == 2)
          r2 = (ri + 1) % 2;
        else {
          for(unsigned int k = 0; k < conRegions[j].size(); k++) {
            MElement *el = conRegions[j][k];
            for(int l = 0; l < el->getNumFaces(); l++) {
              MFace mf = el->getFace(l);
              std::multimap<MFace, MElement *, Less_Face>::iterator itl =
                f2e.lower_bound(mf);
              for(; itl != f2e.upper_bound(mf); itl++) {
                if(itl->second != el) break;
              }
              MElement *el2 = itl->second;
              bool sameRegion = false;
              for(unsigned int m = 0; m < conRegions[j].size(); m++)
                if(conRegions[j][m] == el2) {
                  sameRegion = true;
                  break;
                }
              if(sameRegion) continue;
              for(unsigned int m = 0; m < regs.size(); m++) {
                int rm = regs[m];
                if(rm == ri) continue;
                for(unsigned int n = 0; n < elements[4][rm].size(); n++)
                  if(elements[4][rm][n] == el2) {
                    r2 = rm;
                    break;
                  }
                if(r2 != ri) break;
              }
              if(r2 != ri) break;
            }
            if(r2 != ri) break;
          }
          if(r2 == ri)
            Msg::Warning("Element not found for simply connected regions");
        }

        for(unsigned int k = 0; k < conRegions[j].size(); k++) {
          MElement *el = conRegions[j][k];
          unsigned int l = 0;
          for(; l < elements[4][ri].size(); l++)
            if(elements[4][ri][l] == el) break;
          elements[4][ri].erase(elements[4][ri].begin() + l);
          elements[4][r2].push_back(el);
        }
      }
    }
  }

  std::vector<int> faces;
  for(std::map<int, std::vector<MElement *> >::iterator it =
        elements[2].begin();
      it != elements[2].end(); it++)
    faces.push_back(it->first);
  std::multimap<MEdge, MElement *, Less_Edge> e2e;
  if(faces.size() > 2) {
    for(unsigned int i = 0; i < faces.size(); i++) {
      for(unsigned int j = 0; j < elements[2][faces[i]].size(); j++) {
        MElement *el = elements[2][faces[i]][j];
        for(int k = 0; k < el->getNumEdges(); k++)
          e2e.insert(std::make_pair(el->getEdge(k), el));
      }
    }
  }
  for(unsigned int i = 0; i < faces.size(); i++) {
    int fi = faces[i];
    std::vector<MElement *> allElements;
    for(unsigned int j = 0; j < elements[2][fi].size(); j++)
      allElements.push_back(elements[2][fi][j]);
    std::vector<std::vector<MElement *> > conSurfaces;
    int nbConSurfaces = connectedSurfaces(allElements, conSurfaces);
    Msg::Info("%d connected surfaces (reg=%d)", nbConSurfaces, fi);
    unsigned int maxNumEl = 1;
    for(int j = 0; j < nbConSurfaces; j++)
      if(conSurfaces[j].size() > maxNumEl) maxNumEl = conSurfaces[j].size();
    for(int j = 0; j < nbConSurfaces; j++) {
      // remove conSurfaces containing few elements
      if(conSurfaces[j].size() < maxNumEl * 1.e-4) {
        // find adjacent surface
        int f2 = fi;
        if(faces.size() == 2)
          f2 = (fi + 1) % 2;
        else {
          for(unsigned int k = 0; k < conSurfaces[j].size(); k++) {
            MElement *el = conSurfaces[j][k];
            for(int l = 0; l < el->getNumEdges(); l++) {
              MEdge me = el->getEdge(l);
              std::multimap<MEdge, MElement *, Less_Edge>::iterator itl =
                e2e.lower_bound(me);
              for(; itl != e2e.upper_bound(me); itl++) {
                if(itl->second != el) break;
              }
              MElement *el2 = itl->second;
              bool sameSurface = false;
              for(unsigned int m = 0; m < conSurfaces[j].size(); m++)
                if(conSurfaces[j][m] == el2) {
                  sameSurface = true;
                  break;
                }
              if(sameSurface) continue;
              for(unsigned int m = 0; m < faces.size(); m++) {
                int fm = faces[m];
                if(fm == fi) continue;
                for(unsigned int n = 0; n < elements[2][fm].size(); n++)
                  if(elements[2][fm][n] == el2) {
                    f2 = fm;
                    break;
                  }
                if(f2 != fi) break;
              }
              if(f2 != fi) break;
            }
            if(f2 != fi) break;
          }
          if(f2 == fi)
            Msg::Warning("Element not found for simply connected surfaces");
        }
        for(unsigned int k = 0; k < conSurfaces[j].size(); k++) {
          MElement *el = conSurfaces[j][k];
          unsigned int l = 0;
          for(; l < elements[2][fi].size(); l++)
            if(elements[2][fi][l] == el) break;
          elements[2][fi].erase(elements[2][fi].begin() + l);
          elements[2][f2].push_back(el);
        }
      }
    }
  }
}

GModel *GModel::buildCutGModel(gLevelset *ls, bool cutElem, bool saveTri)
{
  if(saveTri)
    CTX::instance()->mesh.saveTri = 1;
  else
    CTX::instance()->mesh.saveTri = 0;

  std::map<int, std::vector<MElement *> > elements[11];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex *> vertexMap;

  if(cutElem)
    Msg::Info("Cutting mesh...");
  else
    Msg::Info("Splitting mesh...");
  double t1 = Cpu();

  GModel *cutGM =
    buildCutMesh(this, ls, elements, vertexMap, physicals, cutElem);

  if(!cutElem) makeSimplyConnected(elements);

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    cutGM->_storeElementsInEntities(elements[i]);
  cutGM->_associateEntityWithMeshVertices();
  cutGM->_storeVerticesInEntities(vertexMap);

  for(int i = 0; i < 4; i++) {
    cutGM->_storePhysicalTagsInEntities(i, physicals[i]);
    std::map<int, std::map<int, std::string> >::iterator it =
      physicals[i].begin();
    for(; it != physicals[i].end(); it++) {
      std::map<int, std::string>::iterator it2 = it->second.begin();
      for(; it2 != it->second.end(); it2++)
        if(it2->second != "")
          cutGM->setPhysicalName(it2->second, i, it2->first);
    }
  }

  if(cutElem)
    Msg::Info("Mesh cutting completed (%g s)", Cpu() - t1);
  else
    Msg::Info("Mesh splitting completed (%g s)", Cpu() - t1);

  return cutGM;
}

void GModel::load(const std::string &fileName)
{
  GModel *temp = GModel::current();
  GModel::setCurrent(this);
  MergeFile(fileName, true);
  GModel::setCurrent(temp);
}

void GModel::save(const std::string &fileName)
{
  GModel *temp = GModel::current();
  GModel::setCurrent(this);
  CreateOutputFile(fileName, FORMAT_AUTO);
  GModel::setCurrent(temp);
}

int GModel::readGEO(const std::string &name)
{
  // readGEO is static, because it can create several models
  ParseFile(name, true);
  // sync OCC first, as GEO_Internals currently contains attributes (physicals)
  // that should also be applied to entities from OCC_Internals
  if(GModel::current()->getOCCInternals())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  return 1;
}

void GModel::setPhysicalNumToEntitiesInBox(int EntityDimension,
                                           int PhysicalNumber,
                                           SBoundingBox3d box)
{
  std::vector<GEntity *> entities;
  getEntitiesInBox(entities, box, EntityDimension);
  for(unsigned int i = 0; i < entities.size(); i++)
    entities[i]->addPhysicalEntity(PhysicalNumber);
}

void GModel::setPhysicalNumToEntitiesInBox(int EntityDimension,
                                           int PhysicalNumber,
                                           std::vector<double> p1,
                                           std::vector<double> p2)
{
  if(p1.size() != 3 || p2.size() != 3) return;
  SBoundingBox3d box(p1[0], p1[2], p1[2], p2[0], p2[1], p2[3]);
  setPhysicalNumToEntitiesInBox(EntityDimension, PhysicalNumber, box);
}

GEdge *getNewModelEdge(GFace *gf1, GFace *gf2,
                       std::map<std::pair<int, int>, GEdge *> &newEdges)
{
  int t1 = gf1 ? gf1->tag() : -1;
  int t2 = gf2 ? gf2->tag() : -1;
  int i1 = std::min(t1, t2);
  int i2 = std::max(t1, t2);

  if(i1 == i2) return 0;

  std::map<std::pair<int, int>, GEdge *>::iterator it =
    newEdges.find(std::make_pair(i1, i2));
  if(it == newEdges.end()) {
    discreteEdge *ge =
      new discreteEdge(GModel::current(),
                       GModel::current()->getMaxElementaryNumber(1) + 1, 0, 0);
    GModel::current()->add(ge);
    newEdges[std::make_pair(i1, i2)] = ge;
    return ge;
  }
  else
    return it->second;
}

#if defined(HAVE_MESH)

void GModel::classifyAllFaces()
{
  std::set<GFace *> faces;
  std::vector<MElement *> elements;
  for(GModel::fiter it = this->firstFace(); it != this->lastFace(); ++it) {
    faces.insert(*it);
    elements.insert(elements.end(), (*it)->triangles.begin(),
                    (*it)->triangles.end());
    elements.insert(elements.end(), (*it)->quadrangles.begin(),
                    (*it)->quadrangles.end());
  }

  discreteEdge *edge = new discreteEdge(
    GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1, 0, 0);
  GModel::current()->add(edge);

  e2t_cont adj;
  buildEdgeToElements(elements, adj);
  std::vector<edge_angle> edges_detected, edges_lonly;
  buildListOfEdgeAngle(adj, edges_detected, edges_lonly);
  for(unsigned int i = 0; i < edges_detected.size(); i++) {
    edge_angle ea = edges_detected[i];
    if(ea.angle <= EDGE_ANGLE_THRESHOLD) break;
    edge->lines.push_back(new MLine(ea.v1, ea.v2));
  }

  this->classifyFaces(faces);

  GModel::current()->remove(edge);
  edge->lines.clear();
  delete edge;
  elements.clear();
  edges_detected.clear();
  edges_lonly.clear();
}

void recurClassifyEdges(MTri3 *t, std::map<MTriangle *, GFace *> &reverse,
                        std::map<MLine *, GEdge *, compareMLinePtr> &lines,
                        std::set<MLine *> &touched,
                        std::set<MTri3 *> &trisTouched,
                        std::map<std::pair<int, int>, GEdge *> &newEdges)
{
  if(!t->isDeleted()) {
    trisTouched.erase(t);
    t->setDeleted(true);
    GFace *gf1 = reverse[t->tri()];
    for(int i = 0; i < 3; i++) {
      GFace *gf2 = 0;
      MTri3 *tn = t->getNeigh(i);
      if(tn) gf2 = reverse[tn->tri()];
      edgeXface exf(t, i);
      MLine ml(exf._v(0), exf._v(1));
      std::map<MLine *, GEdge *, compareMLinePtr>::iterator it =
        lines.find(&ml);
      if(it != lines.end()) {
        if(touched.find(it->first) == touched.end()) {
          GEdge *ge = getNewModelEdge(gf1, gf2, newEdges);
          if(ge) ge->lines.push_back(it->first);
          touched.insert(it->first);
        }
      }
      if(tn)
        recurClassifyEdges(tn, reverse, lines, touched, trisTouched, newEdges);
    }
  }
}

void recurClassify(MTri3 *t, GFace *gf,
                   std::map<MLine *, GEdge *, compareMLinePtr> &lines,
                   std::map<MTriangle *, GFace *> &reverse)
{
  if(!t->isDeleted()) {
    gf->triangles.push_back(t->tri());
    reverse[t->tri()] = gf;
    t->setDeleted(true);
    for(int i = 0; i < 3; i++) {
      MTri3 *tn = t->getNeigh(i);
      if(tn) {
        edgeXface exf(t, i);
        MLine ml(exf._v(0), exf._v(1));
        std::map<MLine *, GEdge *, compareMLinePtr>::iterator it =
          lines.find(&ml);
        if(it == lines.end()) recurClassify(tn, gf, lines, reverse);
      }
    }
  }
}

#endif

void GModel::classifyFaces(std::set<GFace *> &_faces)
{
#if defined(HAVE_MESH)
  std::map<MLine *, GEdge *, compareMLinePtr> lines;

  for(GModel::eiter it = GModel::current()->firstEdge();
      it != GModel::current()->lastEdge(); ++it) {
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      lines[(*it)->lines[i]] = *it;
  }

  std::map<MTriangle *, GFace *> reverse_old;
  std::list<MTri3 *> tris;
  {
    std::set<GFace *>::iterator it = _faces.begin();
    while(it != _faces.end()) {
      GFace *gf = *it;
      for(unsigned int i = 0; i < gf->triangles.size(); i++) {
        tris.push_back(new MTri3(gf->triangles[i], 0));
        reverse_old[gf->triangles[i]] = gf;
      }
      gf->triangles.clear();
      gf->mesh_vertices.clear();
      ++it;
    }
  }
  if(tris.empty()) return;

  connectTriangles(tris);

  std::map<MTriangle *, GFace *> reverse;
  std::multimap<GFace *, GFace *> replacedBy;
  // color all triangles
  std::list<MTri3 *>::iterator it = tris.begin();
  std::list<GFace *> newf;
  while(it != tris.end()) {
    if(!(*it)->isDeleted()) {
      discreteFace *gf = new discreteFace(
        GModel::current(), GModel::current()->getMaxElementaryNumber(2) + 1);
      recurClassify(*it, gf, lines, reverse);
      GModel::current()->add(gf);
      newf.push_back(gf);

      for(unsigned int i = 0; i < gf->triangles.size(); i++) {
        replacedBy.insert(std::make_pair(reverse_old[gf->triangles[i]], gf));
      }
    }
    ++it;
  }

  // now we have all faces coloured. If some regions were existing, replace
  // their faces by the new ones

  for(riter rit = firstRegion(); rit != lastRegion(); ++rit) {
    std::vector<GFace *> _xfaces = (*rit)->faces();
    std::set<GFace *> _newFaces;
    for(std::vector<GFace *>::iterator itf = _xfaces.begin();
        itf != _xfaces.end(); ++itf) {
      std::multimap<GFace *, GFace *>::iterator itLow =
        replacedBy.lower_bound(*itf);
      std::multimap<GFace *, GFace *>::iterator itUp =
        replacedBy.upper_bound(*itf);

      for(; itLow != itUp; ++itLow) _newFaces.insert(itLow->second);
    }
    (*rit)->set(std::vector<GFace *>(_newFaces.begin(), _newFaces.end()));
  }

  // color some lines
  it = tris.begin();
  while(it != tris.end()) {
    (*it)->setDeleted(false);
    ++it;
  }

  // classify edges that are bound by different GFaces
  std::map<std::pair<int, int>, GEdge *> newEdges;
  std::set<MLine *> touched;
  std::set<MTri3 *> trisTouched;
  // bug fix : multiply connected domains

  trisTouched.insert(tris.begin(), tris.end());
  while(!trisTouched.empty())
    recurClassifyEdges(*trisTouched.begin(), reverse, lines, touched,
                       trisTouched, newEdges);

  std::map<discreteFace *, std::vector<int> > newFaceTopology;

  // check if new edges should not be splitted
  // splitted if composed of several open or closed edges

  std::map<MVertex *, GVertex *> modelVertices;

  for(std::map<std::pair<int, int>, GEdge *>::iterator ite = newEdges.begin();
      ite != newEdges.end(); ++ite) {
    std::list<MLine *> allSegments;
    for(unsigned int i = 0; i < ite->second->lines.size(); i++)
      allSegments.push_back(ite->second->lines[i]);

    while(!allSegments.empty()) {
      std::list<MLine *> segmentsForThisDiscreteEdge;
      MVertex *vB = (*allSegments.begin())->getVertex(0);
      MVertex *vE = (*allSegments.begin())->getVertex(1);
      segmentsForThisDiscreteEdge.push_back(*allSegments.begin());
      allSegments.erase(allSegments.begin());
      while(1) {
        bool found = false;
        for(std::list<MLine *>::iterator it = allSegments.begin();
            it != allSegments.end(); ++it) {
          MVertex *v1 = (*it)->getVertex(0);
          MVertex *v2 = (*it)->getVertex(1);
          if(v1 == vE || v2 == vE) {
            segmentsForThisDiscreteEdge.push_back(*it);
            if(v2 == vE) (*it)->reverse();
            vE = (v1 == vE) ? v2 : v1;
            found = true;
            allSegments.erase(it);
            break;
          }
          if(v1 == vB || v2 == vB) {
            segmentsForThisDiscreteEdge.push_front(*it);
            if(v1 == vB) (*it)->reverse();
            vB = (v1 == vB) ? v2 : v1;
            found = true;
            allSegments.erase(it);
            break;
          }
        }
        if(vE == vB) break;
        if(!found) break;
      }

      std::map<MVertex *, GVertex *>::iterator itMV = modelVertices.find(vB);
      if(itMV == modelVertices.end()) {
        GVertex *newGv = new discreteVertex(
          GModel::current(), GModel::current()->getMaxElementaryNumber(0) + 1,
          vB->x(), vB->y(), vB->z());
        newGv->mesh_vertices.push_back(vB);
        vB->setEntity(newGv);
        newGv->points.push_back(new MPoint(vB));
        GModel::current()->add(newGv);
        modelVertices[vB] = newGv;
      }
      itMV = modelVertices.find(vE);
      if(itMV == modelVertices.end()) {
        GVertex *newGv = new discreteVertex(
          GModel::current(), GModel::current()->getMaxElementaryNumber(0) + 1,
          vE->x(), vE->y(), vE->z());
        newGv->mesh_vertices.push_back(vE);
        newGv->points.push_back(new MPoint(vE));
        vE->setEntity(newGv);
        GModel::current()->add(newGv);
        modelVertices[vE] = newGv;
      }

      GEdge *newGe = new discreteEdge(
        GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
        modelVertices[vB], modelVertices[vE]);
      newGe->lines.insert(newGe->lines.end(),
                          segmentsForThisDiscreteEdge.begin(),
                          segmentsForThisDiscreteEdge.end());

      for(std::list<MLine *>::iterator itL =
            segmentsForThisDiscreteEdge.begin();
          itL != segmentsForThisDiscreteEdge.end(); ++itL) {
        if((*itL)->getVertex(0)->onWhat()->dim() != 0) {
          newGe->mesh_vertices.push_back((*itL)->getVertex(0));
          (*itL)->getVertex(0)->setEntity(newGe);
        }
      }

      GModel::current()->add(newGe);
      discreteFace *gf1 = dynamic_cast<discreteFace *>(
        GModel::current()->getFaceByTag(ite->first.first));
      discreteFace *gf2 = dynamic_cast<discreteFace *>(
        GModel::current()->getFaceByTag(ite->first.second));
      if(gf1) newFaceTopology[gf1].push_back(newGe->tag());
      if(gf2) newFaceTopology[gf2].push_back(newGe->tag());
    }
  }

  std::map<discreteFace *, std::vector<int> >::iterator itFT =
    newFaceTopology.begin();
  for(; itFT != newFaceTopology.end(); ++itFT) {
    itFT->first->setBoundEdges(itFT->second);
  }

  for(std::map<std::pair<int, int>, GEdge *>::iterator it = newEdges.begin();
      it != newEdges.end(); ++it) {
    GEdge *ge = it->second;
    GModel::current()->remove(ge);
    //    delete ge;
  }

  it = tris.begin();
  while(it != tris.end()) {
    delete *it;
    ++it;
  }

  // delete empty mesh faces and reclasssify
  std::set<GFace *, GEntityLessThan> fac = faces;
  for(fiter fit = fac.begin(); fit != fac.end(); ++fit) {
    std::set<MVertex *> _verts;
    (*fit)->mesh_vertices.clear();
    for(unsigned int i = 0; i < (*fit)->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        if((*fit)->triangles[i]->getVertex(j)->onWhat()->dim() > 1) {
          (*fit)->triangles[i]->getVertex(j)->setEntity(*fit);
          _verts.insert((*fit)->triangles[i]->getVertex(j));
        }
      }
    }
    if((*fit)->triangles.size())
      (*fit)->mesh_vertices.insert((*fit)->mesh_vertices.begin(),
                                   _verts.begin(), _verts.end());
    else
      remove(*fit);
  }
#endif
}

void GModel::addHomologyRequest(const std::string &type,
                                const std::vector<int> &domain,
                                const std::vector<int> &subdomain,
                                const std::vector<int> &dim)
{
  typedef std::pair<const std::vector<int>, const std::vector<int> > dpair;
  typedef std::pair<const std::string, const std::vector<int> > tpair;
  dpair p(domain, subdomain);
  tpair p2(type, dim);
  _homologyRequests.insert(std::pair<dpair, tpair>(p, p2));
}

void GModel::computeHomology()
{
  if(_homologyRequests.empty()) return;

#if defined(HAVE_KBIPACK)
  double t1 = Cpu();

  // find unique domain/subdomain requests
  typedef std::pair<const std::vector<int>, const std::vector<int> > dpair;
  typedef std::pair<const std::string, const std::vector<int> > tpair;
  std::set<dpair> domains;
  for(std::multimap<dpair, tpair>::iterator it = _homologyRequests.begin();
      it != _homologyRequests.end(); it++)
    domains.insert(it->first);
  Msg::Info("Number of cell complexes to construct: %d", domains.size());

  for(std::set<dpair>::iterator it = domains.begin(); it != domains.end();
      it++) {
    std::pair<std::multimap<dpair, tpair>::iterator,
              std::multimap<dpair, tpair>::iterator>
      itp = _homologyRequests.equal_range(*it);
    bool prepareToRestore = (itp.first != --itp.second);
    itp.second++;
    std::vector<int> imdomain;
    Homology *homology =
      new Homology(this, itp.first->first.first, itp.first->first.second,
                   imdomain, prepareToRestore);

    for(std::multimap<dpair, tpair>::iterator itt = itp.first;
        itt != itp.second; itt++) {
      std::string type = itt->second.first;
      std::vector<int> dim0 = itt->second.second;
      if(dim0.empty())
        for(int i = 0; i < getDim(); i++) dim0.push_back(i);
      std::vector<int> dim;

      std::stringstream ss;
      for(unsigned int i = 0; i < dim0.size(); i++) {
        int d = dim0.at(i);
        if(d >= 0 && d <= getDim()) {
          dim.push_back(d);
          ss << "H";
          if(type == "Homology") ss << "_";
          if(type == "Cohomology") ss << "^";
          ss << d;
          if(i < dim0.size() - 1 && dim0.at(i + 1) >= 0 &&
             dim0.at(i + 1) <= getDim())
            ss << ", ";
        }
      }
      std::string dims = ss.str();

      if(type != "Homology" && type != "Cohomology" && type != "Betti") {
        Msg::Error("Unknown type of homology computation: %s", type.c_str());
      }
      else if(dim.empty()) {
        Msg::Error("Invalid homology computation dimensions given");
      }
      else if(type == "Betti") {
        homology->findBettiNumbers();
      }
      else if(type == "Homology" && !homology->isHomologyComputed(dim)) {
        homology->findHomologyBasis(dim);
        Msg::Info("Homology space basis chains to save: %s", dims.c_str());
        for(unsigned int i = 0; i < dim.size(); i++) {
          homology->addChainsToModel(dim.at(i));
        }
      }
      else if(type == "Cohomology" && !homology->isCohomologyComputed(dim)) {
        homology->findCohomologyBasis(dim);
        Msg::Info("Cohomology space basis cochains to save: %s", dims.c_str());
        for(unsigned int i = 0; i < dim.size(); i++) {
          homology->addCochainsToModel(dim.at(i));
        }
      }
    }
    pruneMeshVertexAssociations();
    delete homology;
  }
  Msg::Info("");

  double t2 = Cpu();
  Msg::StatusBar(true, "Done homology and cohomology computation (%g s)",
                 t2 - t1);

#else
  Msg::Error("Homology computation requires KBIPACK");
#endif
}
