// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "GModelParametrize.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "Field.h"
#include "Generator.h"
#include "meshPartition.h"
#include "HighOrder.h"
#include "meshMetric.h"
#include "meshGRegionMMG.h"
#include "meshGFaceBamg.h"
#include "meshRefine.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataGModel.h"
#endif

#if defined(HAVE_KBIPACK)
#include "Homology.h"
#endif

std::vector<GModel *> GModel::list;
int GModel::_current = -1;

GModel::GModel(const std::string &name)
  : _name(name), _visible(1), _elementOctree(nullptr),
    _geo_internals(nullptr), _occ_internals(nullptr), _acis_internals(nullptr),
    _parasolid_internals(nullptr), _fields(nullptr),
    _currentMeshEntity(nullptr), _numPartitions(0), normals(nullptr),
    lcCallback(nullptr)
{
  _maxVertexNum = CTX::instance()->mesh.firstNodeTag - 1;
  _maxElementNum = CTX::instance()->mesh.firstElementTag - 1;
  _checkPointedMaxVertexNum = _maxVertexNum;
  _checkPointedMaxElementNum = _maxElementNum;

  // hide all other models
  for(std::size_t i = 0; i < list.size(); i++) list[i]->setVisibility(0);

  // push new one into the list
  list.push_back(this);

  // we always create an internal GEO model; other CAD internals are created
  // on-demand
  createGEOInternals();

#if defined(HAVE_MESH)
  _fields = new FieldManager();
#endif
}

GModel::~GModel()
{
  auto it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);

  if(getVisibility()) {
    // if no other model is visible, make the last one visible
    bool othervisible = false;
    for(std::size_t i = 0; i < list.size(); i++) {
      if(list[i]->getVisibility()) othervisible = true;
    }
    if(!othervisible && list.size()) list.back()->setVisibility(1);
  }

  destroy();
  deleteGEOInternals();
  deleteOCCInternals();
  deleteACISInternals();
  deleteParasolidInternals();
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
    Msg::Debug("No current model available: creating one");
    new GModel();
  }
  if(index >= 0) _current = index;
  if(_current < 0 || _current >= (int)list.size()) return list.back();
  return list[_current];
}

int GModel::setCurrent(GModel *m)
{
  for(std::size_t i = 0; i < list.size(); i++) {
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
  return nullptr;
}

void GModel::destroy(bool keepName)
{
  Msg::Debug("Destroying model %s", getName().c_str());

  if(!keepName) {
    _name.clear();
    _fileNames.clear();
  }

  _maxVertexNum = CTX::instance()->mesh.firstNodeTag - 1;
  _maxElementNum = CTX::instance()->mesh.firstElementTag - 1;
  _checkPointedMaxVertexNum = _maxVertexNum;
  _checkPointedMaxElementNum = _maxElementNum;
  _currentMeshEntity = nullptr;
  _lastMeshEntityError.clear();
  _lastMeshVertexError.clear();

  for(auto it = firstRegion(); it != lastRegion(); ++it) delete *it;
  regions.clear();
  std::set<GRegion *, GEntityPtrLessThan>().swap(regions);

  for(auto it = firstFace(); it != lastFace(); ++it) delete *it;
  faces.clear();
  std::set<GFace *, GEntityPtrLessThan>().swap(faces);

  for(auto it = firstEdge(); it != lastEdge(); ++it) delete *it;
  edges.clear();
  std::set<GEdge *, GEntityPtrLessThan>().swap(edges);

  for(auto it = firstVertex(); it != lastVertex(); ++it) delete *it;
  vertices.clear();
  std::set<GVertex *, GEntityPtrLessThan>().swap(vertices);

  destroyMeshCaches();

  resetOCCInternals();

  if(normals) delete normals;
  normals = nullptr;

#if defined(HAVE_MESH)
  _fields->reset();
#endif
  gmshSurface::reset();
}

void GModel::destroyMeshCaches()
{
  // this is called in GEntity::deleteMesh()
#pragma omp critical(destroyMeshCaches)
  {
    _vertexVectorCache.clear();
    std::vector<MVertex *>().swap(_vertexVectorCache);
    _vertexMapCache.clear();
    std::map<std::size_t, MVertex *>().swap(_vertexMapCache);
    _elementVectorCache.clear();
    std::vector<std::pair<MElement *, int> >().swap(_elementVectorCache);
    _elementMapCache.clear();
    std::map<std::size_t, std::pair<MElement *, int> >().swap(_elementMapCache);
    _elementIndexCache.clear();
    std::map<int, int>().swap(_elementIndexCache);
    if(_elementOctree) {
      delete _elementOctree;
      _elementOctree = nullptr;
    }
  }
}

void GModel::deleteMesh()
{
  for(auto it = firstRegion(); it != lastRegion(); ++it) (*it)->deleteMesh();
  for(auto it = firstFace(); it != lastFace(); ++it) (*it)->deleteMesh();
  for(auto it = firstEdge(); it != lastEdge(); ++it) (*it)->deleteMesh();
  for(auto it = firstVertex(); it != lastVertex(); ++it) (*it)->deleteMesh();
  destroyMeshCaches();
  _currentMeshEntity = nullptr;
  _lastMeshEntityError.clear();
  _lastMeshVertexError.clear();
}

void GModel::deleteMesh(const std::vector<GEntity *> &entities)
{
  if(entities.empty()) {
    deleteMesh();
    return;
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    bool ok = true;
    switch(ge->dim()) {
    case 0: {
      std::vector<GEdge *> e = ge->edges();
      for(auto it = e.begin(); it != e.end(); ++it) {
        if((*it)->getNumMeshElements()) {
          ok = false;
          break;
        }
      }
    } break;
    case 1: {
      std::vector<GFace *> f = ge->faces();
      for(auto it = f.begin(); it != f.end(); ++it) {
        if((*it)->getNumMeshElements()) {
          ok = false;
          break;
        }
      }
    } break;
    case 2: {
      std::list<GRegion *> r = ge->regions();
      for(auto it = r.begin(); it != r.end(); ++it) {
        if((*it)->getNumMeshElements()) {
          ok = false;
          break;
        }
      }
    } break;
    }
    if(ok) { ge->deleteMesh(); }
    else {
      Msg::Warning("Cannot delete mesh of entity (%d, %d), connected to mesh "
                   "of higher dimensional entity",
                   ge->dim(), ge->tag());
    }
  }
  destroyMeshCaches();
  _currentMeshEntity = nullptr;
  _lastMeshEntityError.clear();
  _lastMeshVertexError.clear();
}

void GModel::deleteVertexArrays()
{
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    (*it)->deleteVertexArrays();
  for(auto it = firstFace(); it != lastFace(); ++it)
    (*it)->deleteVertexArrays();
  for(auto it = firstEdge(); it != lastEdge(); ++it)
    (*it)->deleteVertexArrays();
  for(auto it = firstVertex(); it != lastVertex(); ++it)
    (*it)->deleteVertexArrays();
}

void GModel::deleteGeometryVertexArrays()
{
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    (*it)->deleteGeometryVertexArrays();
  for(auto it = firstFace(); it != lastFace(); ++it)
    (*it)->deleteGeometryVertexArrays();
  for(auto it = firstEdge(); it != lastEdge(); ++it)
    (*it)->deleteGeometryVertexArrays();
  for(auto it = firstVertex(); it != lastVertex(); ++it)
    (*it)->deleteGeometryVertexArrays();
}

bool GModel::empty() const
{
  return vertices.empty() && edges.empty() && faces.empty() && regions.empty();
}

GRegion *GModel::getRegionByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  auto it = regions.find((GRegion *)&tmp);
  if(it != regions.end())
    return *it;
  else
    return nullptr;
}

GFace *GModel::getFaceByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  auto it = faces.find((GFace *)&tmp);
  if(it != faces.end())
    return *it;
  else
    return nullptr;
}

GEdge *GModel::getEdgeByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  auto it = edges.find((GEdge *)&tmp);
  if(it != edges.end())
    return *it;
  else
    return nullptr;
}

GVertex *GModel::getVertexByTag(int n) const
{
  GEntity tmp((GModel *)this, n);
  auto it = vertices.find((GVertex *)&tmp);
  if(it != vertices.end())
    return *it;
  else
    return nullptr;
}

GEntity *GModel::getEntityByTag(int dim, int n) const
{
  switch(dim) {
  case 0: return getVertexByTag(n);
  case 1: return getEdgeByTag(n);
  case 2: return getFaceByTag(n);
  case 3: return getRegionByTag(n);
  }
  return nullptr;
}

bool GModel::changeEntityTag(int dim, int tag, int newTag)
{
  if(dim == 0) {
    GVertex *gv = getVertexByTag(tag), *gvn = getVertexByTag(newTag);
    if(gvn) {
      Msg::Error("Point with tag %d already exists", newTag);
      return false;
    }
    else if(gv) {
      vertices.erase(gv);
      gv->setTag(newTag);
      vertices.insert(gv);
    }
    else {
      Msg::Error("Unknown model point %d", tag);
      return false;
    }
  }
  else if(dim == 1) {
    GEdge *ge = getEdgeByTag(tag), *gen = getEdgeByTag(newTag);
    if(gen) {
      Msg::Error("Curve with tag %d already exists", newTag);
      return false;
    }
    else if(ge) {
      edges.erase(ge);
      ge->setTag(newTag);
      edges.insert(ge);
    }
    else {
      Msg::Error("Unknown model curve %d", tag);
      return false;
    }
  }
  else if(dim == 2) {
    GFace *gf = getFaceByTag(tag), *gfn = getFaceByTag(newTag);
    if(gfn) {
      Msg::Error("Surface with tag %d already exists", newTag);
      return false;
    }
    else if(gf) {
      faces.erase(gf);
      gf->setTag(newTag);
      faces.insert(gf);
    }
    else {
      Msg::Error("Unknown model surface %d", tag);
      return false;
    }
  }
  else if(dim == 3) {
    GRegion *gr = getRegionByTag(tag), *grn = getRegionByTag(newTag);
    if(grn) {
      Msg::Error("Volume with tag %d already exists", newTag);
      return false;
    }
    else if(gr) {
      regions.erase(gr);
      gr->setTag(newTag);
      regions.insert(gr);
    }
    else {
      Msg::Error("Unknown model volume %d", tag);
      return false;
    }
  }
  return true;
}

std::vector<int> GModel::getTagsForPhysicalName(int dim,
                                                const std::string &name)
{
  std::vector<int> tags;
  std::map<int, std::vector<GEntity *> > physicalGroups;
  getPhysicalGroups(dim, physicalGroups);
  std::vector<GEntity *> entities =
    physicalGroups[getPhysicalNumber(dim, name)];
  for(auto it = entities.begin(); it != entities.end(); it++) {
    GEntity *ge = *it;
    tags.push_back(ge->tag());
  }
  return tags;
}

bool GModel::remove(GRegion *r)
{
  auto it = std::find(firstRegion(), lastRegion(), r);
  if(it != (riter)regions.end()) {
    regions.erase(it);
    std::vector<GFace *> f = r->faces();
    for(auto it = f.begin(); it != f.end(); it++) (*it)->delRegion(r);
    return true;
  }
  else {
    return false;
  }
}

bool GModel::remove(GFace *f)
{
  auto it = std::find(firstFace(), lastFace(), f);
  if(it != faces.end()) {
    faces.erase(it);
    std::vector<GEdge *> const &e = f->edges();
    for(auto it = e.begin(); it != e.end(); it++) (*it)->delFace(f);
    return true;
  }
  else {
    return false;
  }
}

bool GModel::remove(GEdge *e)
{
  auto it = std::find(firstEdge(), lastEdge(), e);
  if(it != edges.end()) {
    edges.erase(it);
    if(e->getBeginVertex()) e->getBeginVertex()->delEdge(e);
    if(e->getEndVertex()) e->getEndVertex()->delEdge(e);
    return true;
  }
  else {
    return false;
  }
}

bool GModel::remove(GVertex *v)
{
  auto it = std::find(firstVertex(), lastVertex(), v);
  if(it != vertices.end()) {
    vertices.erase(it);
    return true;
  }
  else {
    return false;
  }
}

void GModel::remove(int dim, int tag, std::vector<GEntity*> &removed,
                    bool recursive)
{
  if(dim == 3) {
    GRegion *gr = getRegionByTag(tag);
    if(gr) {
      if(remove(gr)) removed.push_back(gr);
      if(recursive) {
        std::vector<GFace *> f = gr->faces();
        for(auto it = f.begin(); it != f.end(); it++)
          remove(2, (*it)->tag(), removed, recursive);
      }
    }
  }
  else if(dim == 2) {
    GFace *gf = getFaceByTag(tag);
    if(gf) {
      bool skip = false;
      for(auto it = firstRegion(); it != lastRegion(); it++) {
        std::vector<GFace *> f = (*it)->faces();
        if(std::find(f.begin(), f.end(), gf) != f.end()) {
          skip = true;
          break;
        }
        auto ef = (*it)->embeddedFaces();
        if(std::find(ef.begin(), ef.end(), gf) != ef.end()) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        if(remove(gf)) removed.push_back(gf);
        if(recursive) {
          std::vector<GEdge *> const &e = gf->edges();
          for(auto it = e.begin(); it != e.end(); it++)
            remove(1, (*it)->tag(), removed, recursive);
        }
      }
    }
  }
  else if(dim == 1) {
    GEdge *ge = getEdgeByTag(tag);
    if(ge) {
      bool skip = false;
      for(auto it = firstRegion(); it != lastRegion(); it++) {
        auto ee = (*it)->embeddedEdges();
        if(std::find(ee.begin(), ee.end(), ge) != ee.end()) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        for(auto it = firstFace(); it != lastFace(); it++) {
          std::vector<GEdge *> const &e = (*it)->edges();
          if(std::find(e.begin(), e.end(), ge) != e.end()) {
            skip = true;
            break;
          }
          auto ee = (*it)->embeddedEdges();
          if(std::find(ee.begin(), ee.end(), ge) != ee.end()) {
            skip = true;
            break;
          }
        }
      }
      if(!skip) {
        if(remove(ge)) removed.push_back(ge);
        if(recursive) {
          if(ge->getBeginVertex())
            remove(0, ge->getBeginVertex()->tag(), removed);
          if(ge->getEndVertex())
            remove(0, ge->getEndVertex()->tag(), removed);
        }
      }
    }
  }
  else if(dim == 0) {
    GVertex *gv = getVertexByTag(tag);
    if(gv) {
      bool skip = false;
      for(auto it = firstEdge(); it != lastEdge(); it++) {
        GEdge *ge = *it;
        if(ge->getBeginVertex() == gv || ge->getEndVertex() == gv) {
          skip = true;
          break;
        }
      }
      if(!skip) {
        for(auto it = firstFace(); it != lastFace(); it++) {
          auto ev = (*it)->embeddedVertices();
          if(std::find(ev.begin(), ev.end(), gv) != ev.end()) {
            skip = true;
            break;
          }
        }
      }
      if(!skip) {
        for(auto it = firstRegion(); it != lastRegion(); it++) {
          auto ev = (*it)->embeddedVertices();
          if(std::find(ev.begin(), ev.end(), gv) != ev.end()) {
            skip = true;
            break;
          }
        }
      }
      if(!skip) {
        if(remove(gv)) removed.push_back(gv);
      }
    }
  }
}

void GModel::remove(const std::vector<std::pair<int, int> > &dimTags,
                    std::vector<GEntity*> &removed, bool recursive)
{
  for(std::size_t i = 0; i < dimTags.size(); i++)
    remove(dimTags[i].first, dimTags[i].second, removed, recursive);
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
  if(!CTX::instance()->geom.snapPoints) return;

  auto vit = firstVertex();

  double tol = CTX::instance()->geom.tolerance;

  while(vit != lastVertex()) {
    std::vector<GEdge *> const &edges = (*vit)->edges();
    for(auto it = edges.begin(); it != edges.end(); ++it) {
      Range<double> parb = (*it)->parBounds(0);
      double t;
      if((*it)->getBeginVertex() == *vit) { t = parb.low(); }
      else if((*it)->getEndVertex() == *vit) {
        t = parb.high();
      }
      else {
        Msg::Error("Weird point: impossible to snap");
        break;
      }
      GPoint gp = (*it)->point(t);
      double d = sqrt((gp.x() - (*vit)->x()) * (gp.x() - (*vit)->x()) +
                      (gp.y() - (*vit)->y()) * (gp.y() - (*vit)->y()) +
                      (gp.z() - (*vit)->z()) * (gp.z() - (*vit)->z()));
      if(d > tol) {
        (*vit)->setPosition(gp);
        Msg::Info("Snapping geometry point %d to curve (distance = %g)",
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
  for(std::size_t i = 0; i < all.size(); i++) {
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
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = std::abs(inDimTags[i].second); // abs for backward compatibility
    bool reverse = (inDimTags[i].second < 0);
    if(dim == 3) {
      GRegion *gr = getRegionByTag(tag);
      if(gr) {
        if(recursive) {
          std::vector<GVertex *> const &vert = gr->vertices();
          for(auto it = vert.begin(); it != vert.end(); it++)
            outDimTags.push_back(std::make_pair(0, (*it)->tag()));
        }
        else {
          std::vector<GFace *> faces(gr->faces());
          std::vector<int> const &orientations = gr->faceOrientations();
          auto ito = orientations.begin();
          for(auto it = faces.begin(); it != faces.end(); it++) {
            int t = (*it)->tag();
            if(oriented && ito != orientations.end()) {
              t *= *ito;
              ito++;
            }
            outDimTags.push_back(std::make_pair(2, t));
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
          for(auto it = vert.begin(); it != vert.end(); it++)
            outDimTags.push_back(std::make_pair(0, (*it)->tag()));
        }
        else {
          std::vector<GEdge *> const &edges = gf->edges();
          std::vector<int> orientations(gf->edgeOrientations());
          auto ito = orientations.begin();
          for(auto it = edges.begin(); it != edges.end(); it++) {
            int t = (*it)->tag();
            if(oriented && ito != orientations.end()) {
              t *= *ito;
              ito++;
            }
            outDimTags.push_back(std::make_pair(1, t));
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
              std::make_pair(0, ge->getEndVertex()->tag()));
          if(ge->getBeginVertex())
            outDimTags.push_back(
              std::make_pair(0, ge->getBeginVertex()->tag()));
        }
        else {
          if(ge->getBeginVertex())
            outDimTags.push_back(
              std::make_pair(0, ge->getBeginVertex()->tag()));
          if(ge->getEndVertex())
            outDimTags.push_back(
              std::make_pair(0, ge->getEndVertex()->tag()));
        }
      }
      else {
        Msg::Error("Unknown model curve with tag %d", tag);
        ret = false;
      }
    }
    else if(dim == 0) {
      GVertex *gv = getVertexByTag(tag);
      if(gv && recursive) {
        outDimTags.push_back(std::make_pair(0, gv->tag()));
      }
    }
  }

  if(combined) {
    // compute boundary of the combined shapes
    std::set<int, AbsIntLessThan> c[3];
    for(std::size_t i = 0; i < outDimTags.size(); i++) {
      int dim = outDimTags[i].first;
      int tag = outDimTags[i].second;
      if(dim >= 0 && dim < 3) {
        auto it = c[dim].find(tag);
        if(it == c[dim].end())
          c[dim].insert(tag);
        else {
          c[dim].erase(it);
        }
      }
    }
    outDimTags.clear();
    for(int dim = 0; dim < 3; dim++) {
      for(auto it = c[dim].begin(); it != c[dim].end(); it++)
        outDimTags.push_back(std::make_pair(dim, *it));
    }
  }
  return ret;
}

int GModel::getMaxElementaryNumber(int dim)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  int num = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    if(dim < 0 || entities[i]->dim() == dim)
      num = std::max(num, std::abs(entities[i]->tag()));
  return num;
}

bool GModel::noPhysicalGroups()
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    if(entities[i]->physicals.size()) return false;
  return true;
}

void GModel::getPhysicalGroups(
  std::map<int, std::vector<GEntity *> > groups[4]) const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    std::map<int, std::vector<GEntity *> > &group(groups[entities[i]->dim()]);
    for(std::size_t j = 0; j < entities[i]->physicals.size(); j++) {
      // physicals can be stored with negative signs when the entity should be
      // "reversed"
      int p = std::abs(entities[i]->physicals[j]);
      group[p].push_back(entities[i]);
    }
  }
  for(int dim = 0; dim < 4; ++dim) {
    std::map<int, std::vector<GEntity *> > &group(groups[dim]);
    for(auto it = group.begin(); it != group.end(); ++it) {
      std::vector<GEntity *> &v = it->second;
      std::sort(v.begin(), v.end(), GEntityPtrLessThan());
      if(std::unique(v.begin(), v.end(), GEntityPtrFullEqual()) != v.end())
        Msg::Debug("removed duplicate entries in physical group (%d, %d)",
                   dim, it->first);
    }
  }
}

void GModel::getPhysicalGroups(
  int dim, std::map<int, std::vector<GEntity *> > &groups) const
{
  std::vector<GEntity *> entities;
  getEntities(entities, dim);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->physicals.size(); j++) {
      // physicals can be stored with negative signs when the entity should be
      // "reversed"
      int p = std::abs(entities[i]->physicals[j]);
      groups[p].push_back(entities[i]);
    }
  }
  for(auto it = groups.begin(); it != groups.end(); ++it) {
    std::vector<GEntity *> &v = it->second;
    std::sort(v.begin(), v.end(), GEntityPtrLessThan());
    if(std::unique(v.begin(), v.end(), GEntityPtrFullEqual()) != v.end())
      Msg::Debug("removed duplicate entries in physical group (%d, %d)",
                 dim, it->first);
  }
}

void GModel::getEntitiesForPhysicalName(const std::string &name,
                                        std::vector<GEntity *> &entities) const
{
  entities.clear();
  std::vector<int> tags[4];
  for(auto it = _physicalNames.begin(); it != _physicalNames.end(); ++it) {
    if(it->second == name) {
      tags[it->first.first].push_back(it->first.second);
    }
  }
  if(tags[0].size()) {
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
      for(std::size_t j = 0; j < (*it)->physicals.size(); j++) {
        int p = std::abs((*it)->physicals[j]);
        auto itFind = std::find(tags[0].begin(), tags[0].end(), p);
        if(itFind != tags[0].end()) {
          entities.push_back(*it);
        }
      }
    }
  }
  if(tags[1].size()) {
    for(auto it = edges.begin(); it != edges.end(); ++it) {
      for(std::size_t j = 0; j < (*it)->physicals.size(); j++) {
        int p = std::abs((*it)->physicals[j]);
        auto itFind = std::find(tags[1].begin(), tags[1].end(), p);
        if(itFind != tags[1].end()) {
          entities.push_back(*it);
        }
      }
    }
  }
  if(tags[2].size()) {
    for(auto it = faces.begin(); it != faces.end(); ++it) {
      for(std::size_t j = 0; j < (*it)->physicals.size(); j++) {
        int p = std::abs((*it)->physicals[j]);
        auto itFind = std::find(tags[2].begin(), tags[2].end(), p);
        if(itFind != tags[2].end()) {
          entities.push_back(*it);
        }
      }
    }
  }
  if(tags[3].size()) {
    for(auto it = regions.begin(); it != regions.end(); ++it) {
      for(std::size_t j = 0; j < (*it)->physicals.size(); j++) {
        int p = std::abs((*it)->physicals[j]);
        auto itFind = std::find(tags[3].begin(), tags[3].end(), p);
        if(itFind != tags[3].end()) {
          entities.push_back(*it);
        }
      }
    }
  }
  std::sort(entities.begin(), entities.end(), GEntityPtrLessThan());
  if(std::unique(entities.begin(), entities.end(), GEntityPtrFullEqual()) !=
     entities.end())
    Msg::Debug("removed duplicate entries for physical name %s",
               name.c_str());

}

void GModel::addPhysicalGroup(int dim, int tag, const std::vector<int> &tags)
{
  for(auto t : tags) {
    GEntity *ge = getEntityByTag(dim, std::abs(t));
    if(ge)
      ge->physicals.push_back((t > 0) ? tag : -tag);
    else
      Msg::Warning("Unknown entity of dimension %d and tag %d in physical "
                   "group %d", dim, t, tag);
  }
}

void GModel::removePhysicalGroups()
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    entities[i]->physicals.clear();
}

void GModel::removePhysicalGroup(int dim, int tag)
{
  // FIXME: this is very inefficient - needs to be rewriten (and we should
  // generalize the function by taking a list of dim, tag pairs)
  std::vector<GEntity *> entities;
  getEntities(entities, dim);
  for(std::size_t i = 0; i < entities.size(); i++) {
    std::vector<int> p;
    for(std::size_t j = 0; j < entities[i]->physicals.size(); j++)
      if(std::abs(entities[i]->physicals[j]) != tag)
        p.push_back(entities[i]->physicals[j]);
    entities[i]->physicals = p;
  }
  _physicalNames.erase(std::make_pair(dim, tag));
}

int GModel::getMaxPhysicalNumber(int dim)
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  int num = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    if(dim < 0 || entities[i]->dim() == dim)
      for(std::size_t j = 0; j < entities[i]->physicals.size(); j++)
        num = std::max(num, std::abs(entities[i]->physicals[j]));
  return num;
}

void GModel::getInnerPhysicalNamesIterators(std::vector<piter> &iterators)
{
  iterators.resize(4, firstPhysicalName());

  for(auto physIt = firstPhysicalName(); physIt != lastPhysicalName(); ++physIt)
    iterators[physIt->first.first] = physIt;
}

int GModel::setPhysicalName(const std::string &name, int dim, int number)
{
  // check if the name is already used
  int findPhy = getPhysicalNumber(dim, name);
  if(findPhy != -1) return findPhy;

  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber(dim) + 1;
  _physicalNames.insert(std::make_pair(std::make_pair(dim, number), name));
  return number;
}

GModel::piter GModel::setPhysicalName(piter pos, const std::string &name,
                                      int dim, int number)
{
  // if no number is given, find the next available one
  if(!number) number = getMaxPhysicalNumber(dim) + 1;
  // Insertion complexity in O(1) if position points to the element that will
  // FOLLOW the inserted element.
  if(pos != lastPhysicalName()) ++pos;
  return _physicalNames.insert(pos, std::make_pair(std::make_pair(dim, number),
                                                   name));
}

std::string GModel::getPhysicalName(int dim, int number) const
{
  auto it = _physicalNames.find(std::make_pair(dim, number));
  if(it != _physicalNames.end()) return it->second;
  return "";
}

void GModel::removePhysicalName(const std::string &name)
{
  auto it = _physicalNames.begin();
  while(it != _physicalNames.end()) {
    if(it->second == name)
      // it = _physicalNames.erase(it); // C++11 only
      _physicalNames.erase(it++);
    else
      ++it;
  }
}

int GModel::getPhysicalNumber(const int &dim, const std::string &name)
{
  for(auto physIt = firstPhysicalName(); physIt != lastPhysicalName(); ++physIt)
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

int GModel::getMeshDim() const
{
  if(getNumMeshElements(3)) return 3;
  if(getNumMeshElements(2)) return 2;
  if(getNumMeshElements(1)) return 1;
  if(getNumMeshElements(0)) return 0;
  return -1;
}

std::string GModel::getElementaryName(int dim, int tag)
{
  auto it = _elementaryNames.find(std::make_pair(dim, tag));
  if(it != _elementaryNames.end()) return it->second;
  return "";
}

void GModel::removeElementaryName(const std::string &name)
{
  auto it = _elementaryNames.begin();
  while(it != _elementaryNames.end()) {
    if(it->second == name)
      // it = _elementaryNames.erase(it); // C++11 only
      _elementaryNames.erase(it++);
    else
      ++it;
  }
}

void GModel::setSelection(int val)
{
  std::vector<GEntity *> entities;
  getEntities(entities);

  for(std::size_t i = 0; i < entities.size(); i++) {
    entities[i]->setSelection(val);
    // reset selection in elements (stored in the visibility flag to
    // save space)
    if(val == 0) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
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
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(!aroundVisible || entities[i]->getVisibility()) {
      if(entities[i]->getNativeType() == GEntity::OpenCascadeModel) {
        bb += entities[i]->bounds();
      }
      else {
        // using the mesh vertices for now
        if(entities[i]->dim() == 0)
          bb += static_cast<GVertex *>(entities[i])->xyz();
        else
          for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
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
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  // must be done after renumbering:
  std::vector<std::pair<int, int> > newPhysicals;
  computeHomology(newPhysicals);
  CTX::instance()->mesh.changed = ENT_ALL;
  return true;
#else
  Msg::Error("Mesh module not compiled");
  return false;
#endif
}

bool GModel::setAllVolumesPositive()
{
  bool ok = true;
  for(auto it = regions.begin(); it != regions.end(); ++it)
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i)
      if(!(*it)->getMeshElement(i)->setVolumePositive()) ok = false;
  return ok;
}

static void
addToMap(std::multimap<MFace, MElement *, MFaceLessThan> &faceToElement,
         std::map<MElement *, std::vector<std::pair<MElement *, bool> > >
           &elToNeighbors,
         const MFace &face, MElement *el)
{
  auto fit = faceToElement.find(face);
  if(fit == faceToElement.end()) {
    faceToElement.insert(std::make_pair(face, el));
  }
  else { // We found the neighbor face outFace
    faceToElement.insert(std::make_pair(face, el));
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
checkConformity(std::multimap<MFace, MElement *, MFaceLessThan> &faceToElement,
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
            Msg::Info("Node %i on entity of dim %i", face.getVertex(jV)->getNum(),
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
  std::multimap<MFace, MElement *, MFaceLessThan> faceToElement;

  MElement *el;
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    for(std::size_t iEl = 0; iEl < (*it)->getNumMeshElements(); ++iEl) {
      el = (*it)->getMeshElement(iEl);
      for(int iFace = 0; iFace < el->getNumFaces(); iFace++) {
        addToMap(faceToElement, elToNeighbors, el->getFace(iFace), el);
      }
    }
  }
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    for(std::size_t iEl = 0; iEl < (*it)->getNumMeshElements(); ++iEl) {
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

int GModel::adaptMesh()
{
#if defined(HAVE_MESH)
  AdaptMesh(this);
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
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
  //             represent a circle - used for curvature-based metric (default:
  //             = 15)
  //    4) A variant (3), direct implementation in the metric eigendirections,
  //    assuming a level set (ls):
  //        - hmin is imposed in the ls gradient,
  //        - hmax is imposed in the two eigendirections of the ls hessian that
  //        are
  //          (almost ?) tangent to the iso-zero plane
  //          + the latter eigenvalues (1/hmax^2) are modified if necessary to
  //          capture the iso-zero curvature
  //      parameters[0] = thickness of the interface in the positive ls
  //      direction (mandatory) parameters[4] = thickness of the interface in
  //      the negative ls direction
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
      Msg::Info(" - Adapt mesh (all dimensions) iter. = %d", ITER);
      fields->reset();
      meshMetric *metric = new meshMetric(this);
      for(std::size_t imetric = 0; imetric < technique.size(); imetric++) {
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
      Msg::Info(" - Adapt mesh iter. = %d ", ITER);
      std::vector<MElement *> elements;

      if(getDim() == 2) {
        for(auto fit = firstFace(); fit != lastFace(); ++fit) {
          if((*fit)->quadrangles.size()) return -1;
          for(unsigned i = 0; i < (*fit)->triangles.size(); i++) {
            elements.push_back((*fit)->triangles[i]);
          }
        }
      }
      else if(getDim() == 3) {
        for(auto rit = firstRegion(); rit != lastRegion(); ++rit) {
          if((*rit)->hexahedra.size()) return -1;
          for(unsigned i = 0; i < (*rit)->tetrahedra.size(); i++) {
            elements.push_back((*rit)->tetrahedra[i]);
          }
        }
      }

      if(elements.size() == 0) return -1;

      fields->reset();
      meshMetric *metric = new meshMetric(this);
      for(std::size_t imetric = 0; imetric < technique.size(); imetric++) {
        metric->addMetric(technique[imetric], f[imetric], parameters[imetric]);
      }
      fields->setBackgroundField(metric);

      if(getDim() == 2) {
        for(auto fit = firstFace(); fit != lastFace(); ++fit) {
          if((*fit)->geomType() != GEntity::DiscreteSurface) {
            meshGFaceBamg(*fit);
            laplaceSmoothing(*fit, CTX::instance()->mesh.nbSmoothing);
          }
          if(_elementOctree) delete _elementOctree;
          _elementOctree = nullptr;
        }
      }
      else if(getDim() == 3) {
        for(auto rit = firstRegion(); rit != lastRegion(); ++rit) {
          refineMeshMMG(*rit);
          if(_elementOctree) delete _elementOctree;
          _elementOctree = nullptr;
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

  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;

  return 0;
#else
  Msg::Error("Mesh module not compiled");
  return -1;
#endif
}

int GModel::refineMesh(int linear, bool splitIntoQuads, bool splitIntoHexas,
                       bool barycentric)
{
#if defined(HAVE_MESH)
  if(!barycentric) { RefineMesh(this, linear, splitIntoQuads, splitIntoHexas); }
  else {
    BarycentricRefineMesh(this);
  }
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
}

int GModel::recombineMesh()
{
#if defined(HAVE_MESH)
  RecombineMesh(this);
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
}

int GModel::optimizeMesh(const std::string &how, const bool force, int niter)
{
#if defined(HAVE_MESH)
  OptimizeMesh(this, how, force, niter);
  FixPeriodicMesh(this);
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;
  return 1;
#else
  Msg::Error("Mesh module not compiled");
  return 0;
#endif
}

int GModel::setOrderN(int order, int linear, int incomplete, int onlyVisible)
{
#if defined(HAVE_MESH)
  if(order > 1)
    SetOrderN(this, order, linear, incomplete, onlyVisible);
  else
    SetOrder1(this);
  FixPeriodicMesh(this);
  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
    renumberMeshElements();
  }
  CTX::instance()->mesh.changed = ENT_ALL;
  return true;
#else
  Msg::Error("Mesh module not compiled");
  return false;
#endif
}

int GModel::getMeshStatus(bool countDiscrete)
{
  std::size_t numEle3D = 0;
  bool toMesh3D = false;
  bool onlyVisible = CTX::instance()->mesh.meshOnlyVisible;

  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    GRegion *gr = *it;
    if(countDiscrete || gr->geomType() != GEntity::DiscreteVolume)
      numEle3D += gr->getNumMeshElements();
    if(countDiscrete && numEle3D) return 3;
    if(gr->geomType() != GEntity::DiscreteVolume &&
       gr->meshAttributes.method != MESH_NONE)
      toMesh3D = true;
  }
  if(numEle3D && toMesh3D) return 3;

  std::size_t numEle2D = 0;
  bool toMesh2D = false, meshDone2D = true;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    GFace *gf = *it;
    if(countDiscrete || gf->geomType() != GEntity::DiscreteSurface)
      numEle2D += gf->getNumMeshElements();
    if(countDiscrete && numEle2D) return 2;
    if(gf->geomType() != GEntity::DiscreteSurface &&
       gf->meshAttributes.method != MESH_NONE)
      toMesh2D = true;
    if(gf->meshStatistics.status != GEntity::DONE &&
       (!onlyVisible || (onlyVisible && gf->getVisibility())))
      meshDone2D = false;
  }
  if(numEle2D && toMesh2D && meshDone2D) return 2;

  std::size_t numEle1D = 0;
  bool toMesh1D = false, meshDone1D = true;
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    GEdge *ge = *it;
    if(countDiscrete || ge->geomType() != GEntity::DiscreteCurve)
      numEle1D += ge->getNumMeshElements();
    if(countDiscrete && numEle1D) return 1;
    if(ge->geomType() != GEntity::DiscreteCurve &&
       ge->meshAttributes.method != MESH_NONE)
      toMesh1D = true;
    if(ge->meshStatistics.status != GEntity::DONE &&
       (!onlyVisible || (onlyVisible && ge->getVisibility())))
      meshDone1D = false;
  }
  if(numEle1D && toMesh1D && meshDone1D) return 1;

  for(auto it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->mesh_vertices.size()) return 0;

  return -1;
}

std::size_t GModel::getNumMeshVertices(int dim) const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  std::size_t n = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim || dim < 0)
      n += entities[i]->getNumMeshVertices();
  return n;
}

std::size_t GModel::getNumMeshElements(int dim) const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  std::size_t n = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    if(entities[i]->dim() == dim || dim < 0)
      n += entities[i]->getNumMeshElements();
  return n;
}

std::size_t GModel::getNumMeshParentElements() const
{
  std::vector<GEntity *> entities;
  getEntities(entities);
  std::size_t n = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    n += entities[i]->getNumMeshParentElements();
  return n;
}

std::size_t GModel::addMEdge(MEdge &&edge, std::size_t num)
{
  std::pair<MEdge, std::size_t> key(std::move(edge),
                                    num ? num : _mapEdgeNum.size() + 1);
  std::pair<hashmapMEdge::iterator, bool> it = _mapEdgeNum.insert(std::move(key));
  return it.first->second;
}

std::size_t GModel::getMEdge(MVertex *v0, MVertex *v1, MEdge &edge)
{
  MEdge e(v0, v1);
  auto it = _mapEdgeNum.find(e);
  if(it != _mapEdgeNum.end()) {
    edge = it->first;
    return it->second;
  }
  else {
    Msg::Error("Unknown edge %d %d", v0->getNum(), v1->getNum());
    return 0;
  }
}

std::size_t GModel::addMFace(MFace &&face, std::size_t num)
{
  std::pair<MFace, std::size_t> key(std::move(face),
                                    num ? num : _mapFaceNum.size() + 1);
  std::pair<hashmapMFace::iterator, bool> it = _mapFaceNum.insert(std::move(key));
  return it.first->second;
}

std::size_t GModel::getMFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
                             MFace &face)
{
  MFace f(v0, v1, v2, v3);
  auto it = _mapFaceNum.find(f);
  if(it != _mapFaceNum.end()) {
    face = it->first;
    return it->second;
  }
  else {
    Msg::Error("Unknown face %d %d %d", v0->getNum(), v1->getNum(), v2->getNum());
    return 0;
  }
}

#if defined(HAVE_POST)
static void getDependentViewData(GModel *m, PViewDataGModel::DataType type,
                                 std::vector<stepData<double> *> &data)
{
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewDataGModel *d =
      dynamic_cast<PViewDataGModel *>(PView::list[i]->getData());
    if(d && d->getType() == type) {
      for(int step = 0; step < d->getNumTimeSteps(); step++) {
        if(d->getStepData(step)->getModel() == m)
          data.push_back(d->getStepData(step));
      }
    }
  }
}
#endif

void GModel::renumberMeshVertices(const std::map<std::size_t, std::size_t> &mapping)
{
  destroyMeshCaches();
  setMaxVertexNumber(CTX::instance()->mesh.firstNodeTag - 1);
  std::vector<GEntity *> entities;
  getEntities(entities);

  std::map<MVertex *, std::size_t> old, remap;
  std::size_t npost = 0;
#if defined(HAVE_POST)
  // check if any nodal post-processing datasets depend on the model
  std::vector<stepData<double> *> data;
  getDependentViewData(this, PViewDataGModel::NodeData, data);
  npost = data.size();
#endif

  std::size_t maxmap = CTX::instance()->mesh.firstNodeTag - 1;
  for(auto m : mapping) maxmap = std::max(maxmap, m.second);
  bool info = true;
  if(mapping.size() || npost) {
    for(auto ge : entities) {
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        old[v] = v->getNum();
        if(mapping.size()) {
          auto it = mapping.find(v->getNum());
          if(it != mapping.end())
            remap[v] = it->second;
          else {
            if(info) {
              Msg::Info("Mapping does not contain a node tag (%lu) - "
                        "incrementing after last provided tag (%lu)",
                        v->getNum(), maxmap);
              info = false;
            }
            remap[v] = ++maxmap;
          }
        }
      }
    }
  }

  // check if we will potentially only save a subset of elements: only those
  // belonging to physical groups and/or those not being orphans
  bool saveOnlyPhysicals = false;
  if(!CTX::instance()->mesh.saveAll) {
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(entities[i]->physicals.size()) {
        saveOnlyPhysicals = true;
        break;
      }
    }
  }
  bool pruneOrphans = CTX::instance()->mesh.saveWithoutOrphans;

  std::size_t n = CTX::instance()->mesh.firstNodeTag - 1;
  if(saveOnlyPhysicals || pruneOrphans) {
    Msg::Debug("Renumbering for potentially partial mesh save");
    // if we potentially only save a subset of elements, make sure to first
    // renumber the nodes that belong to those elements (so that we end up
    // with a dense node numbering in the output file)
    std::size_t nv = CTX::instance()->mesh.firstNodeTag - 1;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      nv += ge->getNumMeshVertices();
    }
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        ge->getMeshVertex(j)->forceNum(nv + 1);
      }
    }
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(!((pruneOrphans && ge->isOrphan()) ||
           (saveOnlyPhysicals && ge->physicals.empty()))) {
        for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
          MElement *e = ge->getMeshElement(j);
          for(std::size_t k = 0; k < e->getNumVertices(); k++) {
            e->getVertex(k)->forceNum(0);
          }
        }
      }
    }
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        if(v->getNum() == 0) v->forceNum(remap.empty() ? ++n : remap[v]);
      }
    }
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        if(v->getNum() == nv + 1) v->forceNum(remap.empty() ? ++n : remap[v]);
      }
    }
  }
  else {
    // full save
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        v->forceNum(remap.empty() ? ++n : remap[v]);
      }
    }
  }

#if defined(HAVE_POST)
  // renumber any dependent nodal post-processing datasets
  if(npost) {
    Msg::Info("Renumbering nodal model data (%d step%s)", npost,
              npost > 1 ? "s" : "");
    std::map<std::size_t, std::size_t> remap2;
    for(auto ge : entities) {
      for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
        MVertex *v = ge->getMeshVertex(j);
        remap2[old[v]] = v->getNum();
      }
    }
    for(auto d : data) { d->renumberData(remap2); }
  }
#endif
}

void GModel::renumberMeshElements(const std::map<std::size_t, std::size_t> &mapping)
{
  destroyMeshCaches();
  setMaxElementNumber(CTX::instance()->mesh.firstElementTag - 1);
  std::vector<GEntity *> entities;
  getEntities(entities);

  std::map<MElement *, int> old, remap;
  std::size_t npost = 0;
#if defined(HAVE_POST)
  // check if any element-based post-processing datasets depend on the model
  std::vector<stepData<double> *> data[2];
  getDependentViewData(this, PViewDataGModel::ElementData, data[0]);
  getDependentViewData(this, PViewDataGModel::ElementNodeData, data[1]);
  npost = data[0].size() + data[1].size();
#endif

  std::size_t maxmap = CTX::instance()->mesh.firstElementTag - 1;
  for(auto m : mapping) maxmap = std::max(maxmap, m.second);
  bool info = true;
  if(mapping.size() || npost) {
    for(auto ge : entities) {
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        old[e] = e->getNum();
        if(mapping.size()) {
          auto it = mapping.find(e->getNum());
          if(it != mapping.end())
            remap[e] = it->second;
          else {
            if(info) {
              Msg::Info("Mapping does not contain an element tag (%lu) - "
                        "incrementing after last provided tag (%lu)",
                        e->getNum(), maxmap);
              info = false;
            }
            remap[e] = ++maxmap;
          }
        }
      }
    }
  }

  // check if we will potentially only save a subset of elements: only those
  // belonging to physical groups and/or those not being orphans
  bool saveOnlyPhysicals = false;
  if(!CTX::instance()->mesh.saveAll) {
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(entities[i]->physicals.size()) {
        saveOnlyPhysicals = true;
        break;
      }
    }
  }
  bool pruneOrphans = CTX::instance()->mesh.saveWithoutOrphans;

  std::size_t n = CTX::instance()->mesh.firstElementTag - 1;
  if(saveOnlyPhysicals || pruneOrphans) {
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(!((pruneOrphans && ge->isOrphan()) ||
           (saveOnlyPhysicals && ge->physicals.empty()))) {
        for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
          MElement *e = ge->getMeshElement(j);
          e->forceNum(remap.empty() ? ++n : remap[e]);
        }
      }
    }
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(((pruneOrphans && ge->isOrphan()) ||
          (saveOnlyPhysicals && ge->physicals.empty()))) {
        for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
          MElement *e = ge->getMeshElement(j);
          e->forceNum(remap.empty() ? ++n : remap[e]);
        }
      }
    }
  }
  else {
    // full save
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        e->forceNum(remap.empty() ? ++n : remap[e]);
      }
    }
  }

#if defined(HAVE_POST)
  // renumber any dependent element post-processing datasets
  if(npost) {
    Msg::Info("Renumbering element model data (%d step%s)", npost,
              npost > 1 ? "s" : "");
    std::map<std::size_t, std::size_t> remap2;
    for(auto ge : entities) {
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        remap2[old[e]] = e->getNum();
      }
    }
    for(int i = 0; i < 2; i++) {
      for(auto d : data[i]) { d->renumberData(remap2); }
    }
  }
#endif
}

std::size_t GModel::getNumMeshElements(unsigned c[6])
{
  c[0] = 0;
  c[1] = 0;
  c[2] = 0;
  c[3] = 0;
  c[4] = 0;
  c[5] = 0;
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2] + c[3] + c[4] + c[5]) return 3;
  for(auto it = firstFace(); it != lastFace(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0] + c[1] + c[2]) return 2;
  for(auto it = firstEdge(); it != lastEdge(); ++it)
    (*it)->getNumMeshElements(c);
  if(c[0]) return 1;
  return 0;
}

MElement *GModel::getMeshElementByCoord(SPoint3 &p, SPoint3 &param, int dim,
                                        bool strict)
{
  if(!_elementOctree) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding mesh element octree");
      _elementOctree = new MElementOctree(this);
    }
  }
  MElement *e = _elementOctree->find(p.x(), p.y(), p.z(), dim, strict);
  if(e) {
    double xyz[3] = {p.x(), p.y(), p.z()}, uvw[3];
    e->xyz2uvw(xyz, uvw);
    param.setPosition(uvw[0], uvw[1], uvw[2]);
  }
  else {
    param.setPosition(0, 0, 0);
  }
  return e;
}

std::vector<MElement *> GModel::getMeshElementsByCoord(SPoint3 &p, int dim,
                                                       bool strict)
{
  if(!_elementOctree) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding mesh element octree");
      _elementOctree = new MElementOctree(this);
    }
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
      Msg::Debug("We have a dense node numbering in the cache");
      dense = true;
    }
    else if(_maxVertexNum < 10 * getNumMeshVertices()) {
      Msg::Debug(
        "We have a fairly dense node numbering - still using cache vector");
      dense = true;
    }
    std::vector<GEntity *> entities;
    getEntities(entities);
    if(dense) {
      // numbering starts at 1
      _vertexVectorCache.resize(_maxVertexNum + 1, (MVertex *)nullptr);
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
          _vertexVectorCache[entities[i]->mesh_vertices[j]->getNum()] =
            entities[i]->mesh_vertices[j];
    }
    else {
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
          _vertexMapCache[entities[i]->mesh_vertices[j]->getNum()] =
            entities[i]->mesh_vertices[j];
    }
  }
}

void GModel::rebuildMeshElementCache(bool onlyIfNecessary)
{
  if(!onlyIfNecessary ||
     (_elementVectorCache.empty() && _elementMapCache.empty())) {
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
      _elementVectorCache.resize(_maxElementNum + 1, std::make_pair(nullptr, 0));
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          _elementVectorCache[e->getNum()] =
            std::make_pair(e, entities[i]->tag());
        }
    }
    else {
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          _elementMapCache[e->getNum()] = std::make_pair(e, entities[i]->tag());
        }
    }
  }
}

MVertex *GModel::getMeshVertexByTag(std::size_t n)
{
  if(_vertexVectorCache.empty() && _vertexMapCache.empty()) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding mesh node cache");
      rebuildMeshVertexCache();
    }
  }

  if(n < _vertexVectorCache.size())
    return _vertexVectorCache[n];
  else
    return _vertexMapCache[n];
}

void GModel::addMVertexToVertexCache(MVertex* v)
{
  if(_vertexVectorCache.empty() && _vertexMapCache.empty()) {
    Msg::Debug("Rebuilding mesh node cache");
    rebuildMeshVertexCache();
  }
  if (_vertexVectorCache.size() > 0) {
#pragma omp critical(addMVertexToVertexCache)
    if (v->getNum() >= _vertexVectorCache.size()) {
      _vertexVectorCache.resize(v->getNum()+1, nullptr);
    }
    _vertexVectorCache[v->getNum()] = v;
  } else {
    _vertexMapCache[v->getNum()] = v;
  }
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
  std::set<MVertex *, MVertexPtrLessThan> sv;
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      MElement *e = entities[i]->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumVertices(); k++)
        sv.insert(e->getVertex(k));
    }
  }
  v.insert(v.begin(), sv.begin(), sv.end());
}

MElement *GModel::getMeshElementByTag(std::size_t n, int &entityTag)
{
  if(_elementVectorCache.empty() && _elementMapCache.empty()) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding mesh element cache");
      rebuildMeshElementCache();
    }
  }

  std::pair<MElement*, int> ret;
  if(n < _elementVectorCache.size())
    ret = _elementVectorCache[n];
  else
    ret = _elementMapCache[n];
  entityTag = ret.second;
  return ret.first;
}

int GModel::getMeshElementIndex(MElement *e)
{
  if(!e) return 0;
  if(_elementIndexCache.empty()) return e->getNum();
  auto it = _elementIndexCache.find(e->getNum());
  if(it != _elementIndexCache.end()) return it->second;
  return e->getNum();
}

void GModel::setMeshElementIndex(MElement *e, int index)
{
  _elementIndexCache[e->getNum()] = index;
}

template <class T>
static std::size_t removeInvisible(std::vector<T *> &elements, bool all)
{
  std::vector<T *> tmp;
  std::size_t n = elements.size();
  for(std::size_t i = 0; i < n; i++) {
    if(all || !elements[i]->getVisibility())
      delete elements[i];
    else
      tmp.push_back(elements[i]);
  }
  elements.clear();
  elements = tmp;
  return n - elements.size();
}

std::size_t GModel::removeInvisibleElements()
{
  std::size_t n = 0;
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    bool all = !(*it)->getVisibility();
    n += removeInvisible((*it)->tetrahedra, all);
    n += removeInvisible((*it)->hexahedra, all);
    n += removeInvisible((*it)->prisms, all);
    n += removeInvisible((*it)->pyramids, all);
    n += removeInvisible((*it)->trihedra, all);
    n += removeInvisible((*it)->polyhedra, all);
    (*it)->deleteVertexArrays();
  }
  for(auto it = firstFace(); it != lastFace(); ++it) {
    bool all = !(*it)->getVisibility();
    n += removeInvisible((*it)->triangles, all);
    n += removeInvisible((*it)->quadrangles, all);
    n += removeInvisible((*it)->polygons, all);
    (*it)->deleteVertexArrays();
  }
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    bool all = !(*it)->getVisibility();
    n += removeInvisible((*it)->lines, all);
    (*it)->deleteVertexArrays();
  }
  destroyMeshCaches();
  Msg::Info("Removed %lu elements", n);
  return n;
}

template <class T>
static std::size_t reverseInvisible(std::vector<T *> &elements, bool all)
{
  std::size_t n = 0;
  std::vector<T *> tmp;
  for(std::size_t i = 0; i < elements.size(); i++) {
    if(all || !elements[i]->getVisibility()) {
      elements[i]->reverse();
      elements[i]->setVisibility(1);
      n++;
    }
  }
  return n;
}

std::size_t GModel::reverseInvisibleElements()
{
  std::size_t n = 0;
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    bool all = !(*it)->getVisibility();
    n += reverseInvisible((*it)->tetrahedra, all);
    n += reverseInvisible((*it)->hexahedra, all);
    n += reverseInvisible((*it)->prisms, all);
    n += reverseInvisible((*it)->pyramids, all);
    n += reverseInvisible((*it)->trihedra, all);
    n += reverseInvisible((*it)->polyhedra, all);
    (*it)->deleteVertexArrays();
    if(all) (*it)->setVisibility(1);
  }
  for(auto it = firstFace(); it != lastFace(); ++it) {
    bool all = !(*it)->getVisibility();
    n += reverseInvisible((*it)->triangles, all);
    n += reverseInvisible((*it)->quadrangles, all);
    n += reverseInvisible((*it)->polygons, all);
    (*it)->deleteVertexArrays();
    if(all) (*it)->setVisibility(1);
  }
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    bool all = !(*it)->getVisibility();
    n += reverseInvisible((*it)->lines, all);
    (*it)->deleteVertexArrays();
    if(all) (*it)->setVisibility(1);
  }
  destroyMeshCaches();
  Msg::Info("Reversed %lu elements", n);
  return n;
}

std::size_t GModel::indexMeshVertices(bool all, int singlePartition,
                                      bool renumber)
{
  std::vector<GEntity *> entities;
  getEntities(entities);

  // tag all mesh nodes with -1 (negative nodes will not be saved)
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->setIndex(-1);

  // tag all mesh nodes belonging to elements that need to be saved with 0, or
  // with -2 if they need to be taken into account in the numbering but need not
  // to be saved (because we save a single partition and they are not used in
  // that partition)
  for(std::size_t i = 0; i < entities.size(); i++) {
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

  // renumber all the mesh nodes tagged with 0
  std::size_t numVertices = 0;
  long int index = 0;
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

void GModel::setCurrentMeshEntity(GEntity *e)
{
#pragma omp atomic write
  _currentMeshEntity = e;
}

int GModel::partitionMesh(
  int numPart, std::vector<std::pair<MElement *, int> > elementPartition)
{
#if defined(HAVE_MESH) && (defined(HAVE_METIS))
  if(numPart > 0) {
    if(_numPartitions > 0) UnpartitionMesh(this);
    if(elementPartition.empty())
      return PartitionMesh(this, numPart);
    else
      return PartitionUsingThisSplit(this, elementPartition);
  }
  return 1;
#else
  Msg::Error("Mesh or Metis module not compiled");
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
  Msg::Error("Mesh or Metis module not compiled");
  return 1;
#endif
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
  for(std::size_t i = 0; i < src.size(); i++) dst.push_back((T *)src[i]);
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
        e = new discreteEdge(this, it->first, nullptr, nullptr);
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
    for(std::size_t i = 0; i < it->second.size(); ++i)
      it->second[i]->updateParent(this);
}

template <class T>
static void _associateEntityWithElementVertices(GEntity *ge,
                                                std::vector<T *> &elements,
                                                bool force = false)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++) {
      if(force || !elements[i]->getVertex(j)->onWhat() ||
         elements[i]->getVertex(j)->onWhat()->dim() > ge->dim())
        elements[i]->getVertex(j)->setEntity(ge);
    }
  }
}

void GModel::createGeometryOfDiscreteEntities(
  const std::vector<std::pair<int, int> > &dimTags)
{
  std::vector<discreteEdge *> e;
  std::vector<discreteFace *> f;
  std::vector<discreteRegion *> r;

  if(dimTags.empty()) {
    for(auto it = firstEdge(); it != lastEdge(); it++) {
      discreteEdge *de = dynamic_cast<discreteEdge *>(*it);
      if(de) e.push_back(de);
    }
    for(auto it = firstFace(); it != lastFace(); it++) {
      discreteFace *df = dynamic_cast<discreteFace *>(*it);
      if(df) f.push_back(df);
    }
    for(auto it = firstRegion(); it != lastRegion(); it++) {
      discreteRegion *dr = dynamic_cast<discreteRegion *>(*it);
      if(dr) r.push_back(dr);
    }
  }
  else {
    for(std::size_t i = 0; i < dimTags.size(); i++) {
      int dim = dimTags[i].first;
      int tag = dimTags[i].second;
      if(dim == 1) {
        discreteEdge *de = dynamic_cast<discreteEdge *>(getEdgeByTag(tag));
        if(de)
          e.push_back(de);
        else
          Msg::Error("No discrete curve with tag %d", tag);
      }
      else if(dim == 2) {
        discreteFace *df = dynamic_cast<discreteFace *>(getFaceByTag(tag));
        if(df)
          f.push_back(df);
        else
          Msg::Error("No discrete surface with tag %d", tag);
      }
      else if(dim == 3) {
        discreteRegion *dr =
          dynamic_cast<discreteRegion *>(getRegionByTag(tag));
        if(dr)
          r.push_back(dr);
        else
          Msg::Error("No discrete volume with tag %d", tag);
      }
    }
  }

  if(e.size()) {
    Msg::StatusBar(true, "Creating geometry of discrete curves...");
    double t1 = Cpu(), w1 = TimeOfDay();
    for(std::size_t i = 0; i < e.size(); i++) {
      if(e[i]->createGeometry())
        Msg::Error("Could not create geometry of discrete curve %d",
                   e[i]->tag());
    }
    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::StatusBar(true,
                   "Done creating geometry of discrete curves "
                   "(Wall %gs, CPU %gs)",
                   w2 - w1, t2 - t1);
  }

  if(f.size()) {
    Msg::StatusBar(true, "Creating geometry of discrete surfaces...");
    double t1 = Cpu(), w1 = TimeOfDay();
    Msg::StartProgressMeter(f.size());
    for(std::size_t i = 0; i < f.size(); i++) {
      Msg::ProgressMeter(i, true, "Creating geometry");
      if(f[i]->createGeometry())
        Msg::Error("Could not create geometry of discrete surface %d",
                   f[i]->tag());
    }
    Msg::StopProgressMeter();
    double t2 = Cpu();
    double w2 = TimeOfDay();
    Msg::StatusBar(true,
                   "Done creating geometry of discrete surfaces "
                   "(Wall %gs, CPU %gs)",
                   w2 - w1, t2 - t1);
  }

  if(r.size()) {
    Msg::StatusBar(true, "Creating geometry of discrete volumes...");
    double t1 = Cpu(), w1 = TimeOfDay();
    for(std::size_t i = 0; i < r.size(); i++) {
      if(r[i]->createGeometry())
        Msg::Error("Could not create geometry of discrete volume %d",
                   r[i]->tag());
    }
    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::StatusBar(true,
                   "Done creating geometry of discrete volumes "
                   "(Wall %gs, CPU %gs)",
                   w2 - w1, t2 - t1);
  }
}

void GModel::_associateEntityWithMeshVertices()
{
  // loop on regions, then on faces, edges and vertices and store the entity
  // pointer in the the elements' vertices (this way we associate the entity of
  // lowest geometrical degree with each vertex)
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->tetrahedra);
    _associateEntityWithElementVertices(*it, (*it)->hexahedra);
    _associateEntityWithElementVertices(*it, (*it)->prisms);
    _associateEntityWithElementVertices(*it, (*it)->pyramids);
    _associateEntityWithElementVertices(*it, (*it)->trihedra);
    _associateEntityWithElementVertices(*it, (*it)->polyhedra);
  }
  for(auto it = firstFace(); it != lastFace(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->triangles);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles);
    _associateEntityWithElementVertices(*it, (*it)->polygons);
  }
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->lines);
  }
  for(auto it = firstVertex(); it != lastVertex(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->points);
  }
}

void GModel::_storeVerticesInEntities(std::map<std::size_t, MVertex *> &vertices)
{
  auto it = vertices.begin();
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
  for(std::size_t i = 0; i < vertices.size(); i++) {
    MVertex *v = vertices[i];
    if(v) { // the vector is allowed to have null entries
      GEntity *ge = v->onWhat();
      if(ge)
        ge->mesh_vertices.push_back(v);
      else {
        delete v; // we delete all unused vertices
        vertices[i] = nullptr;
      }
    }
  }
}

void GModel::pruneMeshVertexAssociations()
{
  std::vector<GEntity *> entities;
  std::set<MVertex *, MVertexPtrLessThan> vertSet;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      MElement *e = entities[i]->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        MVertex *v = e->getVertex(k);
        v->setEntity(nullptr);
        vertSet.insert(v);
      }
    }
    entities[i]->mesh_vertices.clear();
  }
  std::vector<MVertex *> vertices(vertSet.begin(), vertSet.end());
  _associateEntityWithMeshVertices();
  // associate mesh nodes primarily with chain entities
  for(auto it = _chainRegions.begin(); it != _chainRegions.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->tetrahedra, true);
    _associateEntityWithElementVertices(*it, (*it)->hexahedra, true);
    _associateEntityWithElementVertices(*it, (*it)->prisms, true);
    _associateEntityWithElementVertices(*it, (*it)->pyramids, true);
    _associateEntityWithElementVertices(*it, (*it)->trihedra, true);
    _associateEntityWithElementVertices(*it, (*it)->polyhedra, true);
  }
  for(auto it = _chainFaces.begin(); it != _chainFaces.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->triangles, true);
    _associateEntityWithElementVertices(*it, (*it)->quadrangles, true);
    _associateEntityWithElementVertices(*it, (*it)->polygons, true);
  }
  for(auto it = _chainEdges.begin(); it != _chainEdges.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->lines, true);
  }
  for(auto it = _chainVertices.begin(); it != _chainVertices.end(); ++it) {
    _associateEntityWithElementVertices(*it, (*it)->points, true);
  }
  _storeVerticesInEntities(vertices);
}

void GModel::_storePhysicalTagsInEntities(
  int dim, std::map<int, std::map<int, std::string> > &map)
{
  std::map<int, std::map<int, std::string> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it) {
    GEntity *ge = nullptr;
    switch(dim) {
    case 0: ge = getVertexByTag(it->first); break;
    case 1: ge = getEdgeByTag(it->first); break;
    case 2: ge = getFaceByTag(it->first); break;
    case 3: ge = getRegionByTag(it->first); break;
    }

    if(ge) {
      for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
        if(std::find(ge->physicals.begin(), ge->physicals.end(), it2->first) ==
           ge->physicals.end()) {
          ge->physicals.push_back(it2->first);
        }
        if(it2->second.size() && it2->second != "unnamed")
          _physicalNames.insert(
            std::make_pair(std::make_pair(dim, it2->first), it2->second));
      }
    }
  }
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

  // check for duplicate mesh nodes
  {
    Msg::Info("Checking for duplicate nodes...");
    std::vector<MVertex *> vertices;
    for(std::size_t i = 0; i < entities.size(); i++)
      vertices.insert(vertices.end(), entities[i]->mesh_vertices.begin(),
                      entities[i]->mesh_vertices.end());
    MVertexRTree pos(eps);
    std::set<MVertex *, MVertexPtrLessThan> duplicates;
    int num = pos.insert(vertices, true, &duplicates);
    if(num) {
      Msg::Error("%d duplicate node%s: see `duplicate_node.pos'", num,
                 num > 1 ? "s" : "");
      FILE *fp = Fopen("duplicate_nodes.pos", "w");
      if(fp) {
        fprintf(fp, "View \"duplicate vertices\"{\n");
        for(auto it = duplicates.begin(); it != duplicates.end(); it++) {
          MVertex *v = *it;
          fprintf(fp, "SP(%.16g,%.16g,%.16g){%lu};\n", v->x(), v->y(), v->z(),
                  v->getNum());
        }
        fprintf(fp, "};\n");
        fclose(fp);
      }
    }
  }

  // check for duplicate elements and inverted or zero-volume elements
  {
    Msg::Info("Checking for duplicate elements...");
    std::vector<MVertex *> vertices;
    for(std::size_t i = 0; i < entities.size(); i++) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        double vol = e->getVolume();
        if(vol < 0)
          Msg::Warning("Element %d of dimension %d on entity %d has negative "
                       "volume", e->getNum(), e->getDim(), entities[i]->tag());
        else if(vol < eps * eps * eps)
          Msg::Warning("Element %d of dimension %d on entity %d has zero volume",
                       e->getNum(), e->getDim(), entities[i]->tag());
        SPoint3 p = e->barycenter();
        vertices.push_back(new MVertex(p.x(), p.y(), p.z()));
      }
    }
    MVertexRTree pos(eps);
    int num = pos.insert(vertices, true);
    for(std::size_t i = 0; i < vertices.size(); i++) delete vertices[i];
    if(num) Msg::Error("%d duplicate element%s", num, num > 1 ? "s" : "");
  }

  // check for isolated nodes (not belonging to any elements
  {
    Msg::Info("Checking for isolated nodes...");
    std::vector<GEntity *> entities2;
    getEntities(entities2, getMeshDim());
    std::set<MVertex *, MVertexPtrLessThan> allv;
    for(std::size_t i = 0; i < entities2.size(); i++) {
      for(std::size_t j = 0; j < entities2[i]->getNumMeshElements(); j++) {
        MElement *e = entities2[i]->getMeshElement(j);
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          allv.insert(e->getVertex(k));
        }
      }
    }
    int diff = (int)(getNumMeshVertices() - allv.size());
    if(diff) {
      Msg::Warning("%d node%s not connected to any %dD elements", diff,
                   (diff > 1) ? "s" : "", getMeshDim());
    }
  }

  Msg::StatusBar(true, "Done checking mesh coherence");
}

int GModel::removeDuplicateMeshVertices(double tolerance,
                                        const std::vector<GEntity*> &ents)
{
  Msg::StatusBar(true, "Removing duplicate mesh nodes...");

  SBoundingBox3d bbox = bounds();
  double lc = bbox.empty() ? 1. : norm(SVector3(bbox.max(), bbox.min()));
  double eps = lc * tolerance;

  // get entities (in order of increasing dimensions so that topological
  // classification of vertices remains correct)
  std::vector<GEntity*> entities(ents);
  if(entities.empty()) getEntities(entities);

  // re-index all vertices (don't use MVertex::getNum(), as we want to be able
  // to remove duplicate vertices from "incorrect" meshes, where vertices with
  // the same number are duplicated)
  int n = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      v->setIndex(++n);
    }
  }

  MVertexRTree pos(eps);
  std::map<std::size_t, MVertex *> vertices;
  std::map<MVertex *, MVertex *> duplicates;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      MVertex *v2 = pos.insert(v);
      if(v2)
        duplicates[v] = v2; // v should be removed
      else
        vertices[v->getIndex()] = v;
    }
  }

  int num = (int)duplicates.size();
  Msg::Info("Found %d duplicate nodes ", num);

  if(!num) {
    Msg::Info("No duplicate nodes found");
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
        auto it = duplicates.find(e->getVertex(k));
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
        auto cvIter = corrVtcs.find(oldTgt);
        if(cvIter != corrVtcs.end()) {
          MVertex *src = cvIter->second;
          corrVtcs.erase(cvIter);
          corrVtcs[newTgt] = src;
        }
      }
      for(cIter = corrVtcs.begin(); cIter != corrVtcs.end(); ++cIter) {
        MVertex *oldSrc = cIter->second;
        auto nIter = duplicates.find(oldSrc);
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
  for(auto it = duplicates.begin(); it != duplicates.end(); it++)
    to_delete.push_back(it->first);
  for(std::size_t i = 0; i < to_delete.size(); i++) delete to_delete[i];

  if(CTX::instance()->mesh.renumber) {
    renumberMeshVertices();
  }

  if(num)
    Msg::Info("Removed %d duplicate mesh node%s", num, num > 1 ? "s" : "");

  Msg::StatusBar(true, "Done removing duplicate mesh nodes");
  return num;
}

int GModel::removeDuplicateMeshElements(const std::vector<GEntity*> &ents)
{
  Msg::StatusBar(true, "Removing duplicate mesh elements...");

  // this removes elements that have the same nodes (in the same entity)
  std::vector<GEntity*> entities(ents);
  if(entities.empty()) getEntities(entities);
  int num = 0;
  for(auto &e : entities) {
    std::set<MElement*, MElementPtrLessThanVertices> uniq;
    for(std::size_t i = 0; i < e->getNumMeshElements(); i++) {
      MElement *ele = e->getMeshElement(i);
      uniq.insert(ele);
    }
    int diff = e->getNumMeshElements() - uniq.size();
    if(diff > 0) {
      num += diff;
      Msg::Info("Removed %d duplicate element%s in entity %d of dimension %d",
                diff, diff > 1 ? "s" : "", e->tag(), e->dim());
      e->removeElements(false);
      for(auto ele : uniq) e->addElement(ele);
      // TODO: we should delete the duplicate elements
    }
  }

  if(CTX::instance()->mesh.renumber) {
    renumberMeshElements();
  }

  Msg::StatusBar(true, "Done removing duplicate mesh elements");
  return num;
}

void GModel::alignPeriodicBoundaries()
{
  // Is this still necessary/useful?
  // 1) It's quite horrible
  // 2) It's only called when reading MSH2 files

  Msg::Debug("Aligning periodic boundaries");

  // realigning edges

  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    GEdge *tgt = *it;
    GEdge *src = dynamic_cast<GEdge *>(tgt->getMeshMaster());

    if(src != nullptr && src != tgt) {
      // compose a search list on master edge

      std::map<MEdge, MLine *, MEdgeLessThan> srcLines;
      for(std::size_t i = 0; i < src->getNumMeshElements(); i++) {
        MLine *srcLine = dynamic_cast<MLine *>(src->getMeshElement(i));
        if(!srcLine) {
          Msg::Debug("Master element %d is not a line",
                     src->getMeshElement(i)->getNum());
          return;
        }
        srcLines[MEdge(srcLine->getVertex(0), srcLine->getVertex(1))] = srcLine;
      }

      // run through slave edge elements
      // - check whether we find a counterpart (if not, abort)
      // - check orientation and reorient if necessary

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
        MLine *tgtLine = dynamic_cast<MLine *>(tgt->getMeshElement(i));

        if(!tgtLine) {
          Msg::Debug("Slave element %d is not a line",
                     tgt->getMeshElement(i)->getNum());
          return;
        }

        MVertex *tgtVtcs[2];
        for(int iVtx = 0; iVtx < 2; iVtx++) {
          MVertex *tgtVtx = tgtLine->getVertex(iVtx);
          GEntity *ge = tgtVtx->onWhat();
          std::map<MVertex *, MVertex *> &geV2v = ge->correspondingVertices;
          std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
          auto srcIter = v2v.find(tgtVtx);
          if(srcIter == v2v.end() || !srcIter->second) {
            srcIter = geV2v.find(tgtVtx);
            if(srcIter == geV2v.end() || !srcIter->second) {
              Msg::Debug(
                "Could not find periodic counterpart of node %d on curve %d "
                "or on entity %d of dimension %d",
                tgtVtx->getNum(), tgt->tag(), ge->tag(), ge->dim());
              return;
            }
            else
              tgtVtcs[iVtx] = srcIter->second;
          }
          else
            tgtVtcs[iVtx] = srcIter->second;
        }

        MEdge tgtEdge(tgtVtcs[0], tgtVtcs[1]);

        auto sIter = srcLines.find(tgtEdge);

        if(sIter == srcLines.end() || !sIter->second) {
          Msg::Debug(
            "Could not find periodic counterpart of mesh edge %d-%d on "
            "curve %d for mesh edge %d-%d on curve %d",
            tgtLine->getVertex(0)->getNum(), tgtLine->getVertex(1)->getNum(),
            tgt->tag(), tgtVtcs[0]->getNum(), tgtVtcs[1]->getNum(), src->tag());
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

  for(auto it = firstFace(); it != lastFace(); ++it) {
    GFace *tgt = *it;
    GFace *src = dynamic_cast<GFace *>(tgt->getMeshMaster());
    if(src != nullptr && src != tgt) {
      std::map<MFace, MElement *, MFaceLessThan> srcElmts;

      for(std::size_t i = 0; i < src->getNumMeshElements(); ++i) {
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

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
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

          auto vIter = v2v.find(vtx);
          if(vIter == v2v.end() || !vIter->second) {
            vIter = geV2v.find(vtx);
            if(vIter == geV2v.end() || !vIter->second) {
              Msg::Debug("Could not find periodic counterpart of node %d in "
                         "surface %d or in entity %d of dimension %d",
                         vtx->getNum(), tgt->tag(), ge->tag(), ge->dim());
              return;
            }
            else
              vtcs.push_back(vIter->second);
          }
          else
            vtcs.push_back(vIter->second);
        }
        MFace tgtFace(vtcs);

        auto mIter = srcElmts.find(tgtFace);
        if(mIter == srcElmts.end()) {
          std::ostringstream faceDef;
          for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
            faceDef << vtcs[iVtx]->getNum() << " ";
          }
          Msg::Debug("Could not find periodic counterpart of mesh face %s in "
                     "surface %d connected to surface %d",
                     faceDef.str().c_str(), tgt->tag(), src->tag());
          return;
        }
        else {
          const MFace &srcFace = mIter->first;
          MElement *srcElmt = mIter->second;
          std::vector<MVertex *> srcVtcs;

          if((tgtTri && !dynamic_cast<MTriangle *>(srcElmt)) ||
             (tgtQua && !dynamic_cast<MQuadrangle *>(srcElmt))) {
            Msg::Error("Invalid source/target elements");
            return;
          }

          int rotation = 0;
          bool swap = false;

          if(!tgtFace.computeCorrespondence(srcFace, rotation, swap)) {
            Msg::Debug(
              "Could not find correspondence between mesh face %d-%d-%d "
              "(slave) and %d-%d-%d (master)",
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

static void connectMElementsByMFace(
  const MFace &f, std::multimap<MFace, MElement *, MFaceLessThan> &e2f,
  std::set<MElement *> &group, std::set<MFace, MFaceLessThan> &touched,
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
      for(auto it = e2f.lower_bound(ff); it != e2f.upper_bound(ff); ++it) {
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
  std::multimap<MFace, MElement *, MFaceLessThan> e2f;
  for(std::size_t i = 0; i < elements.size(); ++i) {
    for(int j = 0; j < elements[i]->getNumFaces(); j++) {
      e2f.insert(std::make_pair(elements[i]->getFace(j), elements[i]));
    }
  }
  while(!e2f.empty()) {
    std::set<MElement *> group;
    std::set<MFace, MFaceLessThan> touched;
    connectMElementsByMFace(e2f.begin()->first, e2f, group, touched, 0);
    std::vector<MElement *> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    regs.push_back(temp);
    for(auto it = touched.begin(); it != touched.end(); ++it) e2f.erase(*it);
  }
  return regs.size();
}

static void connectMElementsByMEdge(
  const MEdge &e, std::multimap<MEdge, MElement *, MEdgeLessThan> &e2e,
  std::set<MElement *> &group, std::set<MEdge, MEdgeLessThan> &touched)
{
  // this is very slow...
  std::stack<MEdge> _stack;
  _stack.push(e);

  while(!_stack.empty()) {
    MEdge ee = _stack.top();
    _stack.pop();
    if(touched.find(ee) == touched.end()) {
      touched.insert(ee);
      for(auto it = e2e.lower_bound(ee); it != e2e.upper_bound(ee); ++it) {
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
  std::multimap<MEdge, MElement *, MEdgeLessThan> e2e;
  for(std::size_t i = 0; i < elements.size(); ++i) {
    for(int j = 0; j < elements[i]->getNumEdges(); j++) {
      e2e.insert(std::make_pair(elements[i]->getEdge(j), elements[i]));
    }
  }
  while(!e2e.empty()) {
    std::set<MElement *> group;
    std::set<MEdge, MEdgeLessThan> touched;
    connectMElementsByMEdge(e2e.begin()->first, e2e, group, touched);
    std::vector<MElement *> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    faces.push_back(temp);
    for(auto it = touched.begin(); it != touched.end(); ++it) e2e.erase(*it);
  }
  return faces.size();
}

void GModel::makeDiscreteRegionsSimplyConnected()
{
  Msg::Info("Making discrete regions simply connected...");

  std::vector<discreteRegion *> discRegions;
  for(auto it = firstRegion(); it != lastRegion(); it++)
    if((*it)->geomType() == GEntity::DiscreteVolume)
      discRegions.push_back((discreteRegion *)*it);

  std::set<MVertex *> touched;

  for(auto itR = discRegions.begin(); itR != discRegions.end(); itR++) {
    std::vector<MElement *> allElements((*itR)->getNumMeshElements());
    for(std::size_t i = 0; i < (*itR)->getNumMeshElements(); i++)
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
      for(std::size_t i = 0; i < myElements.size(); i++) {
        MElement *e = myElements[i];
        std::vector<MVertex *> verts;
        e->getVertices(verts);
        for(std::size_t k = 0; k < verts.size(); k++) {
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
  for(auto it = firstFace(); it != lastFace(); it++)
    if((*it)->geomType() == GEntity::DiscreteSurface)
      discFaces.push_back((discreteFace *)*it);

  std::set<MVertex *> touched;

  for(auto itF = discFaces.begin(); itF != discFaces.end(); itF++) {
    std::vector<MElement *> allElements((*itF)->getNumMeshElements());
    for(std::size_t i = 0; i < (*itF)->getNumMeshElements(); i++)
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
      for(std::size_t i = 0; i < myElements.size(); i++) {
        MElement *e = myElements[i];
        std::vector<MVertex *> verts;
        e->getVertices(verts);
        for(std::size_t k = 0; k < verts.size(); k++) {
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

static void
makeSimplyConnected(std::map<int, std::vector<MElement *> > elements[11])
{
  // only for tetras and triangles
  Msg::Info("Make simply connected regions and surfaces");
  std::vector<int> regs;
  for(auto it = elements[4].begin(); it != elements[4].end(); it++)
    regs.push_back(it->first);
  std::multimap<MFace, MElement *, MFaceLessThan> f2e;
  if(regs.size() > 2) {
    for(std::size_t i = 0; i < regs.size(); i++) {
      for(std::size_t j = 0; j < elements[4][regs[i]].size(); j++) {
        MElement *el = elements[4][regs[i]][j];
        for(int k = 0; k < el->getNumFaces(); k++)
          f2e.insert(std::make_pair(el->getFace(k), el));
      }
    }
  }
  for(std::size_t i = 0; i < regs.size(); i++) {
    int ri = regs[i];
    std::vector<MElement *> allElements;
    for(std::size_t j = 0; j < elements[4][ri].size(); j++)
      allElements.push_back(elements[4][ri][j]);
    std::vector<std::vector<MElement *> > conRegions;
    int nbConRegions = connectedVolumes(allElements, conRegions);
    Msg::Info("%d connected regions (reg=%d)", nbConRegions, ri);
    std::size_t maxNumEl = 1;
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
          for(std::size_t k = 0; k < conRegions[j].size(); k++) {
            MElement *el = conRegions[j][k];
            for(int l = 0; l < el->getNumFaces(); l++) {
              MFace mf = el->getFace(l);
              auto itl = f2e.lower_bound(mf);
              for(; itl != f2e.upper_bound(mf); itl++) {
                if(itl->second != el) break;
              }
              MElement *el2 = itl->second;
              bool sameRegion = false;
              for(std::size_t m = 0; m < conRegions[j].size(); m++)
                if(conRegions[j][m] == el2) {
                  sameRegion = true;
                  break;
                }
              if(sameRegion) continue;
              for(std::size_t m = 0; m < regs.size(); m++) {
                int rm = regs[m];
                if(rm == ri) continue;
                for(std::size_t n = 0; n < elements[4][rm].size(); n++)
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

        for(std::size_t k = 0; k < conRegions[j].size(); k++) {
          MElement *el = conRegions[j][k];
          std::size_t l = 0;
          for(; l < elements[4][ri].size(); l++)
            if(elements[4][ri][l] == el) break;
          elements[4][ri].erase(elements[4][ri].begin() + l);
          elements[4][r2].push_back(el);
        }
      }
    }
  }

  std::vector<int> faces;
  for(auto it = elements[2].begin(); it != elements[2].end(); it++)
    faces.push_back(it->first);
  std::multimap<MEdge, MElement *, MEdgeLessThan> e2e;
  if(faces.size() > 2) {
    for(std::size_t i = 0; i < faces.size(); i++) {
      for(std::size_t j = 0; j < elements[2][faces[i]].size(); j++) {
        MElement *el = elements[2][faces[i]][j];
        for(int k = 0; k < el->getNumEdges(); k++)
          e2e.insert(std::make_pair(el->getEdge(k), el));
      }
    }
  }
  for(std::size_t i = 0; i < faces.size(); i++) {
    int fi = faces[i];
    std::vector<MElement *> allElements;
    for(std::size_t j = 0; j < elements[2][fi].size(); j++)
      allElements.push_back(elements[2][fi][j]);
    std::vector<std::vector<MElement *> > conSurfaces;
    int nbConSurfaces = connectedSurfaces(allElements, conSurfaces);
    Msg::Info("%d connected surfaces (reg=%d)", nbConSurfaces, fi);
    std::size_t maxNumEl = 1;
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
          for(std::size_t k = 0; k < conSurfaces[j].size(); k++) {
            MElement *el = conSurfaces[j][k];
            for(int l = 0; l < el->getNumEdges(); l++) {
              MEdge me = el->getEdge(l);
              auto itl = e2e.lower_bound(me);
              for(; itl != e2e.upper_bound(me); itl++) {
                if(itl->second != el) break;
              }
              MElement *el2 = itl->second;
              bool sameSurface = false;
              for(std::size_t m = 0; m < conSurfaces[j].size(); m++)
                if(conSurfaces[j][m] == el2) {
                  sameSurface = true;
                  break;
                }
              if(sameSurface) continue;
              for(std::size_t m = 0; m < faces.size(); m++) {
                int fm = faces[m];
                if(fm == fi) continue;
                for(std::size_t n = 0; n < elements[2][fm].size(); n++)
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
        for(std::size_t k = 0; k < conSurfaces[j].size(); k++) {
          MElement *el = conSurfaces[j][k];
          std::size_t l = 0;
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
  std::map<std::size_t, MVertex *> vertexMap;

  if(cutElem)
    Msg::Info("Cutting mesh...");
  else
    Msg::Info("Splitting mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  GModel *cutGM =
    buildCutMesh(this, ls, elements, vertexMap, physicals, cutElem);

  if(!cutElem) makeSimplyConnected(elements);

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    cutGM->_storeElementsInEntities(elements[i]);
  cutGM->_associateEntityWithMeshVertices();
  cutGM->_storeVerticesInEntities(vertexMap);

  for(int i = 0; i < 4; i++) {
    cutGM->_storePhysicalTagsInEntities(i, physicals[i]);
    auto it = physicals[i].begin();
    for(; it != physicals[i].end(); it++) {
      auto it2 = it->second.begin();
      for(; it2 != it->second.end(); it2++)
        if(it2->second != "")
          cutGM->setPhysicalName(it2->second, i, it2->first);
    }
  }

  if(cutElem)
    Msg::Info("Mesh cutting completed (Wall %gs, CPU %gs)", TimeOfDay() - w1,
              Cpu() - t1);
  else
    Msg::Info("Mesh splitting completed (Wall %gs, CPU %gs)", TimeOfDay() - w1,
              Cpu() - t1);

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
                                           const SBoundingBox3d &box)
{
  std::vector<GEntity *> entities;
  getEntitiesInBox(entities, box, EntityDimension);
  for(std::size_t i = 0; i < entities.size(); i++)
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

void GModel::classifySurfaces(double angleThreshold, bool includeBoundary,
                              bool forReparametrization,
                              double curveAngleThreshold)
{
  classifyFaces(this, angleThreshold, includeBoundary, forReparametrization,
                curveAngleThreshold);
}

void GModel::addHomologyRequest(const std::string &type,
                                const std::vector<int> &domain,
                                const std::vector<int> &subdomain,
                                const std::vector<int> &dim)
{
  std::pair<const std::vector<int>, const std::vector<int> > p(domain,
                                                               subdomain);
  std::pair<const std::string, const std::vector<int> > p2(type, dim);
  _homologyRequests.insert(std::make_pair(p, p2));
}

void GModel::clearHomologyRequests()
{
  _homologyRequests.clear();
}

void GModel::computeHomology(std::vector<std::pair<int, int> > &newPhysicals)
{
  newPhysicals.clear();

  if(_homologyRequests.empty()) return;

#if defined(HAVE_KBIPACK)
  Msg::StatusBar(true, "Homology and cohomology computation...");
  double t1 = Cpu(), w1 = TimeOfDay();

  // find unique domain/subdomain requests
  typedef std::pair<const std::vector<int>, const std::vector<int> > dpair;
  typedef std::pair<const std::string, const std::vector<int> > tpair;
  std::set<dpair> domains;
  for(auto it = _homologyRequests.begin(); it != _homologyRequests.end(); it++)
    domains.insert(it->first);
  Msg::Info("Number of cell complexes to construct: %d", domains.size());

  for(auto it = domains.begin(); it != domains.end(); it++) {
    std::pair<std::multimap<dpair, tpair>::iterator,
              std::multimap<dpair, tpair>::iterator>
      itp = _homologyRequests.equal_range(*it);
    bool prepareToRestore = (itp.first != --itp.second);
    itp.second++;
    std::vector<int> imdomain;
    Homology *homology =
      new Homology(this, itp.first->first.first, itp.first->first.second,
                   imdomain, prepareToRestore);

    for(auto itt = itp.first; itt != itp.second; itt++) {
      std::string type = itt->second.first;
      std::vector<int> dim0 = itt->second.second;
      if(dim0.empty())
        for(int i = 0; i < getDim(); i++) dim0.push_back(i);
      std::vector<int> dim;

      std::stringstream ss;
      for(std::size_t i = 0; i < dim0.size(); i++) {
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
        for(std::size_t i = 0; i < dim.size(); i++) {
          std::vector<int> p = homology->addChainsToModel(dim.at(i));
          for(auto t : p) newPhysicals.push_back({dim.at(i), t});
        }
      }
      else if(type == "Cohomology" && !homology->isCohomologyComputed(dim)) {
        homology->findCohomologyBasis(dim);
        Msg::Info("Cohomology space basis cochains to save: %s", dims.c_str());
        for(std::size_t i = 0; i < dim.size(); i++) {
          std::vector<int> p = homology->addCochainsToModel(dim.at(i));
          for(auto t : p) newPhysicals.push_back({dim.at(i), t});
        }
      }
    }
    pruneMeshVertexAssociations();
    delete homology;
  }
  Msg::Info("");

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true,
                 "Done homology and cohomology computation "
                 "(Wall %gs, CPU %gs)",
                 w2 - w1, t2 - t1);

#else
  Msg::Error("Homology computation requires KBIPACK");
#endif
}

void GModel::computeSizeField()
{
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  FieldManager *fields = getFields();
  int myId = fields->newId();
  fields->newField(myId, std::string("AutomaticMeshSizeField"));
  fields->get(myId)->update();
#else
  Msg::Error("Size field computation requires both HXT and P4EST");
#endif
}

#if !defined(HAVE_ACIS)

void GModel::createACISInternals() {}

void GModel::deleteACISInternals() {}

int GModel::readACISSAT(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with ACIS support to load '%s'",
             fn.c_str());
  return 0;
}

#endif

#if !defined(HAVE_PARASOLID)

void GModel::createParasolidInternals() {}

void GModel::deleteParasolidInternals() {}

int GModel::readParasolidXMT(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Parasolid support to read '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeParasolidXMT(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Parasolid support to write '%s'",
             fn.c_str());
  return 0;
}

int GModel::readParasolidSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Parasolid support to read '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeParasolidSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Parasolid support to write '%s'",
             fn.c_str());
  return 0;
}

#endif
