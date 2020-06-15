// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshGlobal.h"
#include "MallocUtils.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"
#include "ghostEdge.h"
#include "ghostFace.h"
#include "ghostRegion.h"
#include "MVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "ExtrudeParams.h"
#include "StringUtils.h"
#include "Context.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "Numeric.h"
#include "OS.h"
#include "HierarchicalBasisH1Quad.h"
#include "HierarchicalBasisH1Tria.h"
#include "HierarchicalBasisH1Line.h"
#include "HierarchicalBasisH1Brick.h"
#include "HierarchicalBasisH1Tetra.h"
#include "HierarchicalBasisH1Pri.h"
#include "HierarchicalBasisH1Point.h"
#include "HierarchicalBasisHcurlLine.h"
#include "HierarchicalBasisHcurlQuad.h"
#include "HierarchicalBasisHcurlBrick.h"
#include "HierarchicalBasisHcurlTria.h"
#include "HierarchicalBasisHcurlTetra.h"
#include "HierarchicalBasisHcurlPri.h"

#if defined(HAVE_MESH)
#include "Field.h"
#include "meshGFaceOptimize.h"
#include "gmshCrossFields.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

#if defined(HAVE_ONELAB)
#include "onelab.h"
#include "onelabUtils.h"
#endif

// automatically generated C++ and C headers (in gmsh/api)
#include "gmsh.h"
extern "C" {
#include "gmshc.h"
}

static int _initialized = 0;
static int _argc = 0;
static char **_argv = 0;

static bool _isInitialized()
{
  if(!_initialized) {
    // make sure stuff gets printed out
    CTX::instance()->terminal = 1;
    Msg::Error("Gmsh has not been initialized");
    return false;
  }
  if(!GModel::current()) {
    Msg::Error("Gmsh has no current model");
    return false;
  }
  return true;
}

// gmsh

GMSH_API void gmsh::initialize(int argc, char **argv, bool readConfigFiles)
{
  if(_initialized) {
    Msg::Warning("Gmsh has aleady been initialized");
    return;
  }
  if(GmshInitialize(argc, argv, readConfigFiles, false)) {
    _initialized = 1;
    _argc = argc;
    _argv = new char *[_argc + 1];
    for(int i = 0; i < argc; i++) _argv[i] = argv[i];
    return;
  }
  throw -1;
}

GMSH_API void gmsh::finalize()
{
  if(!_isInitialized()) { throw -1; }
  if(GmshFinalize()) {
    _argc = 0;
    if(_argv) delete[] _argv;
    _argv = 0;
    _initialized = 0;
    return;
  }
  Msg::Error("Something went wrong when finalizing Gmsh");
  throw 1;
}

GMSH_API void gmsh::open(const std::string &fileName)
{
  if(!_isInitialized()) { throw -1; }
  if(GmshOpenProject(fileName)) return;
  throw 1;
}

GMSH_API void gmsh::merge(const std::string &fileName)
{
  if(!_isInitialized()) { throw -1; }
  if(GmshMergeFile(fileName)) return;
  throw 1;
}

GMSH_API void gmsh::write(const std::string &fileName)
{
  if(!_isInitialized()) { throw -1; }
  if(GmshWriteFile(fileName)) return;
  throw 1;
}

GMSH_API void gmsh::clear()
{
  if(!_isInitialized()) { throw -1; }
  if(GmshClearProject()) return;
  throw 1;
}

// gmsh::option

GMSH_API void gmsh::option::setNumber(const std::string &name,
                                      const double value)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

GMSH_API void gmsh::option::getNumber(const std::string &name, double &value)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

GMSH_API void gmsh::option::setString(const std::string &name,
                                      const std::string &value)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

GMSH_API void gmsh::option::getString(const std::string &name,
                                      std::string &value)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

GMSH_API void gmsh::option::setColor(const std::string &name, const int r,
                                     const int g, const int b, const int a)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  unsigned int value = CTX::instance()->packColor(r, g, b, a);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

GMSH_API void gmsh::option::getColor(const std::string &name, int &r, int &g,
                                     int &b, int &a)
{
  if(!_isInitialized()) { throw -1; }
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  unsigned int value;
  if(GmshGetOption(c, n, value, i)) {
    r = CTX::instance()->unpackRed(value);
    g = CTX::instance()->unpackGreen(value);
    b = CTX::instance()->unpackBlue(value);
    a = CTX::instance()->unpackAlpha(value);
    return;
  }
  throw 1;
}

// gmsh::model

GMSH_API void gmsh::model::add(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel *m = new GModel(name);
  if(!m) { throw 1; }
}

GMSH_API void gmsh::model::remove()
{
  if(!_isInitialized()) { throw -1; }
  GModel *m = GModel::current();
  if(!m) { throw 1; }
  delete m;
}

GMSH_API void gmsh::model::list(std::vector<std::string> &names)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    names.push_back(GModel::list[i]->getName());
}

GMSH_API void gmsh::model::getCurrent(std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  name = GModel::current()->getName();
}

GMSH_API void gmsh::model::setCurrent(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel *m = GModel::findByName(name);
  if(!m) { throw 1; }
  GModel::setCurrent(m);
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    GModel::list[i]->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::getEntities(vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  dimTags.clear();
  std::vector<GEntity *> entities;
  GModel::current()->getEntities(entities, dim);
  for(std::size_t i = 0; i < entities.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
}

GMSH_API void gmsh::model::setEntityName(const int dim, const int tag,
                                         const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->setElementaryName(dim, tag, name);
}

GMSH_API void gmsh::model::getEntityName(const int dim, const int tag,
                                         std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  name = GModel::current()->getElementaryName(dim, tag);
}

GMSH_API void gmsh::model::getPhysicalGroups(vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  dimTags.clear();
  std::map<int, std::vector<GEntity *> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  for(int d = 0; d < 4; d++) {
    if(dim < 0 || d == dim) {
      for(std::map<int, std::vector<GEntity *> >::iterator it =
            groups[d].begin();
          it != groups[d].end(); it++)
        dimTags.push_back(std::pair<int, int>(d, it->first));
    }
  }
}

static std::string _getEntityName(int dim, int tag)
{
  std::stringstream stream;
  switch(dim) {
  case 0: stream << "Point "; break;
  case 1: stream << "Curve "; break;
  case 2: stream << "Surface "; break;
  case 3: stream << "Volume "; break;
  }
  stream << tag;
  return stream.str();
}

GMSH_API void gmsh::model::getEntitiesForPhysicalGroup(const int dim,
                                                       const int tag,
                                                       std::vector<int> &tags)
{
  if(!_isInitialized()) { throw -1; }
  tags.clear();
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity *> >::iterator it = groups.find(tag);
  if(it != groups.end()) {
    for(std::size_t j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
  else {
    Msg::Error("Physical %s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
}

GMSH_API void
gmsh::model::getPhysicalGroupsForEntity(const int dim, const int tag,
                                        std::vector<int> &physicalTags)
{
  if(!_isInitialized()) { throw -1; }
  physicalTags.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  std::vector<int> phy = ge->getPhysicalEntities();
  physicalTags.resize(phy.size());
  for(std::size_t i = 0; i < phy.size(); i++) { physicalTags[i] = phy[i]; }
}

GMSH_API int gmsh::model::addPhysicalGroup(const int dim,
                                           const std::vector<int> &tags,
                                           const int tag)
{
  // FIXME: We currently still store the "original" physical groups in
  // GEOInternals, because some operations in the built-in kernel directly
  // manipulate physicals (most notably Coherence). Until we fully move the
  // physicals to GModel, we need to add the physicals in GEOInternals and
  // perform a hidden sync (which should not reset the mesh attributes of the
  // entities of they have already been created...).
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(outTag < 0) {
    outTag =
      std::max(GModel::current()->getMaxPhysicalNumber(dim),
               GModel::current()->getGEOInternals()->getMaxPhysicalTag()) +
      1;
  }
  if(!GModel::current()->getGEOInternals()->modifyPhysicalGroup(dim, outTag, 0,
                                                                tags)) {
    throw 1;
  }
  GModel::current()->getGEOInternals()->synchronize(GModel::current(), false);
  return outTag;
}

GMSH_API void gmsh::model::setPhysicalName(const int dim, const int tag,
                                           const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->setPhysicalName(name, dim, tag);
}

GMSH_API void gmsh::model::getPhysicalName(const int dim, const int tag,
                                           std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  name = GModel::current()->getPhysicalName(dim, tag);
}

GMSH_API void gmsh::model::getBoundary(const vectorpair &dimTags,
                                       vectorpair &outDimTags,
                                       const bool combined, const bool oriented,
                                       const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getBoundaryTags(dimTags, outDimTags, combined,
                                         oriented, recursive)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::getEntitiesInBoundingBox(
  const double xmin, const double ymin, const double zmin, const double xmax,
  const double ymax, const double zmax, vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  dimTags.clear();
  SBoundingBox3d box(xmin, ymin, zmin, xmax, ymax, zmax);
  std::vector<GEntity *> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(std::size_t i = 0; i < entities.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
}

GMSH_API void gmsh::model::getBoundingBox(const int dim, const int tag,
                                          double &xmin, double &ymin,
                                          double &zmin, double &xmax,
                                          double &ymax, double &zmax)
{
  if(!_isInitialized()) { throw -1; }

  SBoundingBox3d box;
  if(dim < 0 && tag < 0) {
    box = GModel::current()->bounds();
    if(box.empty()) { throw(3); }
  }
  else {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    box = ge->bounds();
  }
  if(box.empty()) { throw(3); }
  xmin = box.min().x();
  ymin = box.min().y();
  zmin = box.min().z();
  xmax = box.max().x();
  ymax = box.max().y();
  zmax = box.max().z();
}

GMSH_API int gmsh::model::getDimension()
{
  if(!_isInitialized()) { throw -1; }

  return GModel::current()->getDim();
}

GMSH_API int gmsh::model::addDiscreteEntity(const int dim, const int tag,
                                            const std::vector<int> &boundary)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(outTag < 0) {
    outTag = GModel::current()->getMaxElementaryNumber(dim) + 1;
  }
  GEntity *e = GModel::current()->getEntityByTag(dim, outTag);
  if(e) {
    Msg::Error("%s already exists", _getEntityName(dim, outTag).c_str());
    throw 2;
  }
  switch(dim) {
  case 0: {
    discreteVertex *gv = new discreteVertex(GModel::current(), outTag);
    GModel::current()->add(gv);
    break;
  }
  case 1: {
    GVertex *v0 = 0, *v1 = 0;
    if(boundary.size() >= 1)
      v0 = GModel::current()->getVertexByTag(boundary[0]);
    if(boundary.size() >= 2)
      v1 = GModel::current()->getVertexByTag(boundary[1]);
    discreteEdge *ge = new discreteEdge(GModel::current(), outTag, v0, v1);
    GModel::current()->add(ge);
    break;
  }
  case 2: {
    discreteFace *gf = new discreteFace(GModel::current(), outTag);
    std::vector<int> tagEdges, signEdges;
    for(std::size_t i = 0; i < boundary.size(); i++) {
      tagEdges.push_back(std::abs(boundary[i]));
      signEdges.push_back(gmsh_sign(boundary[i]));
    }
    if(!tagEdges.empty()) gf->setBoundEdges(tagEdges, signEdges);
    GModel::current()->add(gf);
    break;
  }
  case 3: {
    discreteRegion *gr = new discreteRegion(GModel::current(), outTag);
    std::vector<int> tagFaces, signFaces;
    for(std::size_t i = 0; i < boundary.size(); i++) {
      tagFaces.push_back(std::abs(boundary[i]));
      signFaces.push_back(gmsh_sign(boundary[i]));
    }
    if(!tagFaces.empty()) gr->setBoundFaces(tagFaces, signFaces);
    GModel::current()->add(gr);
    break;
  }
  default: throw 2;
  }
  return outTag;
}

GMSH_API void gmsh::model::removeEntities(const vectorpair &dimTags,
                                          const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->remove(dimTags, recursive);
}

GMSH_API void gmsh::model::removeEntityName(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->removeElementaryName(name);
}

GMSH_API void gmsh::model::removePhysicalGroups(const vectorpair &dimTags)
{
  if(!_isInitialized()) { throw -1; }
  if(dimTags.empty()) {
    GModel::current()->getGEOInternals()->resetPhysicalGroups();
    GModel::current()->removePhysicalGroups();
  }
  else {
    // FIXME:
    // - move the physical code from GEO factory to GModel:
    //    if a mesh is loaded the GEO sync will re-create the group in GModel...
    // - rewrite the unerlying code: it's slow
    for(std::size_t i = 0; i < dimTags.size(); i++)
      GModel::current()->removePhysicalGroup(dimTags[i].first,
                                             dimTags[i].second);
  }
}

GMSH_API void gmsh::model::removePhysicalName(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->removePhysicalName(name);
}

GMSH_API void gmsh::model::getType(const int dim, const int tag,
                                   std::string &entityType)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  entityType = ge->getTypeString();
}

GMSH_API void gmsh::model::getParent(const int dim, const int tag,
                                     int &parentDim, int &parentTag)
{
  if(!_isInitialized()) { throw -1; }
  parentDim = -1;
  parentTag = -1;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  GEntity *parent = ge->getParentEntity();
  if(parent) {
    parentDim = parent->dim();
    parentTag = parent->tag();
  }
}

GMSH_API void gmsh::model::getPartitions(const int dim, const int tag,
                                         std::vector<int> &partitions)
{
  if(!_isInitialized()) { throw -1; }
  partitions.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  std::vector<int> p;
  if(ge->geomType() == GEntity::PartitionPoint)
    p = static_cast<partitionVertex *>(ge)->getPartitions();
  else if(ge->geomType() == GEntity::PartitionCurve)
    p = static_cast<partitionEdge *>(ge)->getPartitions();
  else if(ge->geomType() == GEntity::PartitionSurface)
    p = static_cast<partitionFace *>(ge)->getPartitions();
  else if(ge->geomType() == GEntity::PartitionVolume)
    p = static_cast<partitionRegion *>(ge)->getPartitions();
  else if(ge->geomType() == GEntity::GhostCurve)
    p.push_back(static_cast<ghostEdge *>(ge)->getPartition());
  else if(ge->geomType() == GEntity::GhostSurface)
    p.push_back(static_cast<ghostFace *>(ge)->getPartition());
  else if(ge->geomType() == GEntity::GhostVolume)
    p.push_back(static_cast<ghostRegion *>(ge)->getPartition());

  for(std::size_t i = 0; i < p.size(); i++) partitions.push_back(p[i]);
}

GMSH_API void gmsh::model::getValue(const int dim, const int tag,
                                    const std::vector<double> &parametricCoord,
                                    std::vector<double> &coord)
{
  if(!_isInitialized()) { throw -1; }
  coord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(dim == 0) {
    coord.push_back(static_cast<GVertex *>(entity)->x());
    coord.push_back(static_cast<GVertex *>(entity)->y());
    coord.push_back(static_cast<GVertex *>(entity)->z());
  }
  else if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++) {
      GPoint gp = ge->point(parametricCoord[i]);
      coord.push_back(gp.x());
      coord.push_back(gp.y());
      coord.push_back(gp.z());
    }
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) return;
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
      SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
      GPoint gp = gf->point(param);
      coord.push_back(gp.x());
      coord.push_back(gp.y());
      coord.push_back(gp.z());
    }
  }
}

GMSH_API void
gmsh::model::getDerivative(const int dim, const int tag,
                           const std::vector<double> &parametricCoord,
                           std::vector<double> &deriv)
{
  if(!_isInitialized()) { throw -1; }
  deriv.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++) {
      SVector3 d = ge->firstDer(parametricCoord[i]);
      deriv.push_back(d.x());
      deriv.push_back(d.y());
      deriv.push_back(d.z());
    }
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) return;
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
      SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
      Pair<SVector3, SVector3> d = gf->firstDer(param);
      deriv.push_back(d.left().x());
      deriv.push_back(d.left().y());
      deriv.push_back(d.left().z());
      deriv.push_back(d.right().x());
      deriv.push_back(d.right().y());
      deriv.push_back(d.right().z());
    }
  }
}

GMSH_API void
gmsh::model::getCurvature(const int dim, const int tag,
                          const std::vector<double> &parametricCoord,
                          std::vector<double> &curvatures)
{
  if(!_isInitialized()) { throw -1; }
  curvatures.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++)
      curvatures.push_back(ge->curvature(parametricCoord[i]));
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) return;
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
      SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
      curvatures.push_back(gf->curvatureMax(param));
    }
  }
}

GMSH_API void gmsh::model::getPrincipalCurvatures(
  const int tag, const std::vector<double> &parametricCoord,
  std::vector<double> &curvaturesMax, std::vector<double> &curvaturesMin,
  std::vector<double> &directionsMax, std::vector<double> &directionsMin)
{
  if(!_isInitialized()) { throw -1; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    throw 2;
  }
  curvaturesMax.clear();
  curvaturesMin.clear();
  directionsMax.clear();
  directionsMin.clear();
  if(parametricCoord.size() % 2) return;
  for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
    SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
    double cmin, cmax;
    SVector3 dmin, dmax;
    gf->curvatures(param, dmax, dmin, cmax, cmin);
    curvaturesMax.push_back(cmax);
    curvaturesMin.push_back(cmin);
    directionsMax.push_back(dmax.x());
    directionsMax.push_back(dmax.y());
    directionsMax.push_back(dmax.z());
    directionsMin.push_back(dmin.x());
    directionsMin.push_back(dmin.y());
    directionsMin.push_back(dmin.z());
  }
}

GMSH_API void gmsh::model::getNormal(const int tag,
                                     const std::vector<double> &parametricCoord,
                                     std::vector<double> &normals)
{
  if(!_isInitialized()) { throw -1; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    throw 2;
  }
  normals.clear();
  if(parametricCoord.size() % 2) return;
  for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
    SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
    SVector3 n = gf->normal(param);
    normals.push_back(n.x());
    normals.push_back(n.y());
    normals.push_back(n.z());
  }
}

GMSH_API void
gmsh::model::getParametrization(const int dim, const int tag,
                                const std::vector<double> &coord,
                                std::vector<double> &parametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  parametricCoord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(coord.size() % 3) return;
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < coord.size(); i += 3) {
      SPoint3 p(coord[i], coord[i + 1], coord[i + 2]);
      double t = ge->parFromPoint(p);
      parametricCoord.push_back(t);
    }
  }
  else if(dim == 2) {
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < coord.size(); i += 3) {
      SPoint3 p(coord[i], coord[i + 1], coord[i + 2]);
      SPoint2 uv = gf->parFromPoint(p);
      parametricCoord.push_back(uv.x());
      parametricCoord.push_back(uv.y());
    }
  }
}

GMSH_API void gmsh::model::getParametrizationBounds(const int dim,
                                                    const int tag,
                                                    std::vector<double> &min,
                                                    std::vector<double> &max)
{
  if(!_isInitialized()) { throw -1; }
  min.clear();
  max.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  for(int dim = 0; dim < entity->dim(); dim++) {
    Range<double> r = entity->parBounds(dim);
    min.push_back(r.low());
    max.push_back(r.high());
  }
}

GMSH_API int gmsh::model::isInside(const int dim, const int tag,
                                   const std::vector<double> &parametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  int num = 0;
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++) {
      if(ge->containsParam(parametricCoord[i])) num++;
    }
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) return num;
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
      SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
      if(gf->containsParam(param)) num++;
    }
  }
  return num;
}

GMSH_API void gmsh::model::reparametrizeOnSurface(
  const int dim, const int tag, const std::vector<double> &parametricCoord,
  const int surfaceTag, std::vector<double> &surfaceParametricCoord,
  const int which)
{
  if(!_isInitialized()) { throw -1; }
  surfaceParametricCoord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  GFace *gf = GModel::current()->getFaceByTag(surfaceTag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, surfaceTag).c_str());
    throw 2;
  }
  if(dim == 0) {
    GVertex *gv = static_cast<GVertex *>(entity);
    SPoint2 p = gv->reparamOnFace(gf, which);
    surfaceParametricCoord.push_back(p.x());
    surfaceParametricCoord.push_back(p.y());
  }
  else if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++) {
      SPoint2 p = ge->reparamOnFace(gf, parametricCoord[i], which);
      surfaceParametricCoord.push_back(p.x());
      surfaceParametricCoord.push_back(p.y());
    }
  }
}

GMSH_API void gmsh::model::setVisibility(const vectorpair &dimTags,
                                         const int value, const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    GEntity *ge = GModel::current()->getEntityByTag(
      dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setVisibility(value, recursive);
  }
}

GMSH_API void gmsh::model::getVisibility(const int dim, const int tag,
                                         int &value)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  value = ge->getVisibility();
}

GMSH_API void gmsh::model::setColor(const vectorpair &dimTags, const int r,
                                    const int g, const int b, const int a,
                                    const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    GEntity *ge = GModel::current()->getEntityByTag(
      dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) {
      unsigned int val = CTX::instance()->packColor(r, g, b, a);
      ge->setColor(val, recursive);
    }
  }
}

GMSH_API void gmsh::model::getColor(const int dim, const int tag, int &r,
                                    int &g, int &b, int &a)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  unsigned int value = ge->getColor();
  r = CTX::instance()->unpackRed(value);
  g = CTX::instance()->unpackGreen(value);
  b = CTX::instance()->unpackBlue(value);
  a = CTX::instance()->unpackAlpha(value);
}

GMSH_API void gmsh::model::setCoordinates(const int tag, const double x,
                                          const double y, const double z)
{
  if(!_isInitialized()) { throw -1; }
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(!gv) {
    Msg::Error("%s does not exist", _getEntityName(0, tag).c_str());
    throw 2;
  }
  GPoint p(x, y, z);
  gv->setPosition(p);
}

// gmsh::model::mesh

GMSH_API void gmsh::model::mesh::generate(const int dim)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->mesh(dim);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::partition(const int numPart)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->partitionMesh(
    numPart >= 0 ? numPart : CTX::instance()->mesh.numPartitions);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::unpartition()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->unpartitionMesh();
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::refine()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                CTX::instance()->mesh.algoSubdivide == 1,
                                CTX::instance()->mesh.algoSubdivide == 2,
                                CTX::instance()->mesh.algoSubdivide == 3);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::recombine()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->recombineMesh();
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::optimize(const std::string &how,
                                          const bool force, const int niter,
                                          const vectorpair &dimTags)
{
  if(!_isInitialized()) { throw -1; }
  if(dimTags.size()) {
    Msg::Warning(
      "Optimization of specified model entities is not interfaced yet");
  }
  GModel::current()->optimizeMesh(how, force, niter);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::computeCrossField(std::vector<int> &tags)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  if(computeCrossField(GModel::current(), tags)) throw 1;
#else
  Msg::Error("computeCrossField requires the mesh module");
  throw -1;
#endif
}

GMSH_API void gmsh::model::mesh::splitQuadrangles(const double quality,
                                                  const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  std::vector<GEntity *> entities;
  if(tag < 0) { GModel::current()->getEntities(entities, 2); }
  else {
    GEntity *ge = GModel::current()->getEntityByTag(2, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    GFace *gf = static_cast<GFace *>(entities[i]);
    quadsToTriangles(gf, quality);
  }
  CTX::instance()->mesh.changed = ENT_ALL;
#else
  Msg::Error("splitQuadrangles requires the mesh module");
  throw -1;
#endif
}

GMSH_API void gmsh::model::mesh::setOrder(const int order)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->setOrderN(order, CTX::instance()->mesh.secondOrderLinear,
                               CTX::instance()->mesh.secondOrderIncomplete);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::getLastEntityError(vectorpair &dimTags)
{
  if(!_isInitialized()) { throw -1; }
  std::vector<GEntity *> e = GModel::current()->getLastMeshEntityError();
  dimTags.clear();
  for(std::size_t i = 0; i < e.size(); i++)
    dimTags.push_back(std::pair<int, int>(e[i]->dim(), e[i]->tag()));
}

GMSH_API void
gmsh::model::mesh::getLastNodeError(std::vector<std::size_t> &nodeTags)
{
  if(!_isInitialized()) { throw -1; }
  std::vector<MVertex *> v = GModel::current()->getLastMeshVertexError();
  nodeTags.clear();
  for(std::size_t i = 0; i < v.size(); i++) nodeTags.push_back(v[i]->getNum());
}

GMSH_API void gmsh::model::mesh::clear(const vectorpair &dimTags)
{
  if(!_isInitialized()) { throw -1; }
  std::vector<GEntity *> entities;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first;
    int tag = dimTags[i].second;
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  GModel::current()->deleteMesh(entities);
}

static void _getAdditionalNodesOnBoundary(GEntity *entity,
                                          std::vector<std::size_t> &nodeTags,
                                          std::vector<double> &coord,
                                          std::vector<double> &parametricCoord,
                                          bool parametric)
{
  std::vector<GFace *> f;
  std::vector<GEdge *> e;
  std::vector<GVertex *> v;
  if(entity->dim() > 2) f = entity->faces();
  if(entity->dim() > 1) e = entity->edges();
  if(entity->dim() > 0) v = entity->vertices();
  for(std::vector<GFace *>::iterator it = f.begin(); it != f.end(); it++) {
    GFace *gf = *it;
    for(std::size_t j = 0; j < gf->mesh_vertices.size(); j++) {
      MVertex *v = gf->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
    }
  }
  for(std::vector<GEdge *>::iterator it = e.begin(); it != e.end(); it++) {
    GEdge *ge = *it;
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
      if(entity->dim() == 2 && parametric) {
        SPoint2 param;
        if(!reparamMeshVertexOnFace(v, (GFace *)entity, param))
          Msg::Warning("Failed to compute parameters of node %d on surface %d",
                       v->getNum(), entity->tag());
        parametricCoord.push_back(param.x());
        parametricCoord.push_back(param.y());
      }
    }
  }
  for(std::vector<GVertex *>::iterator it = v.begin(); it != v.end(); it++) {
    GVertex *gv = *it;
    for(std::size_t j = 0; j < gv->mesh_vertices.size(); j++) {
      MVertex *v = gv->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
      if(entity->dim() == 2 && parametric) {
        SPoint2 param;
        if(!reparamMeshVertexOnFace(v, (GFace *)entity, param))
          Msg::Warning("Failed to compute parameters of node %d on surface %d",
                       v->getNum(), entity->tag());
        parametricCoord.push_back(param.x());
        parametricCoord.push_back(param.y());
      }
      else if(entity->dim() == 1 && parametric) {
        double param;
        if(!reparamMeshVertexOnEdge(v, (GEdge *)entity, param))
          Msg::Warning("Failed to compute parameters of node %d on curve %d",
                       v->getNum(), entity->tag());
        parametricCoord.push_back(param);
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::getNodes(std::vector<std::size_t> &nodeTags,
                                          std::vector<double> &coord,
                                          std::vector<double> &parametricCoord,
                                          const int dim, const int tag,
                                          const bool includeBoundary,
                                          const bool returnParametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  nodeTags.clear();
  coord.clear();
  parametricCoord.clear();
  std::vector<GEntity *> entities;
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  else {
    GModel::current()->getEntities(entities, dim);
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
      if(dim > 0 && returnParametricCoord) {
        double par;
        for(int k = 0; k < dim; k++) {
          if(v->getParameter(k, par)) parametricCoord.push_back(par);
        }
      }
    }
    if(includeBoundary)
      _getAdditionalNodesOnBoundary(ge, nodeTags, coord, parametricCoord,
                                    dim > 0 && returnParametricCoord);
  }
}

GMSH_API void gmsh::model::mesh::getNodesByElementType(
  const int elementType, std::vector<std::size_t> &nodeTags,
  std::vector<double> &coord, std::vector<double> &parametricCoord,
  const int tag, const bool returnParametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  nodeTags.clear();
  coord.clear();
  parametricCoord.clear();
  std::vector<GEntity *> entities;
  int dim = ElementType::getDimension(elementType);
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  else {
    GModel::current()->getEntities(entities, dim);
  }

  int familyType = ElementType::getParentType(elementType);
  int numNodesByElements = ElementType::getNumVertices(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); ++i) {
    numElements = entities[i]->getNumMeshElementsByType(familyType);
  }
  std::size_t numNodes = numElements * numNodesByElements;

  nodeTags.reserve(numNodes);
  coord.reserve(numNodes * 3);
  if(returnParametricCoord) { parametricCoord.reserve(numNodes * 3); }

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0;
        j < entities[i]->getNumMeshElementsByType(familyType); j++) {
      MElement *e = ge->getMeshElementByType(familyType, j);
      for(std::size_t k = 0; k < e->getNumVertices(); ++k) {
        MVertex *v = e->getVertex(k);
        nodeTags.push_back(v->getNum());
        coord.push_back(v->x());
        coord.push_back(v->y());
        coord.push_back(v->z());
        if(dim > 0 && returnParametricCoord) {
          double par;
          for(int k = 0; k < dim; k++) {
            if(v->getParameter(k, par)) parametricCoord.push_back(par);
          }
        }
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::getNode(const std::size_t nodeTag,
                                         std::vector<double> &coord,
                                         std::vector<double> &parametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  MVertex *v = GModel::current()->getMeshVertexByTag(nodeTag);
  if(!v) {
    Msg::Error("Unknown node %d", nodeTag);
    throw 2;
  }
  coord.resize(3);
  coord[0] = v->x();
  coord[1] = v->y();
  coord[2] = v->z();
  parametricCoord.reserve(2);
  double u;
  if(v->getParameter(0, u)) parametricCoord.push_back(u);
  if(v->getParameter(1, u)) parametricCoord.push_back(u);
}

GMSH_API void
gmsh::model::mesh::setNode(const std::size_t nodeTag,
                           const std::vector<double> &coord,
                           const std::vector<double> &parametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  MVertex *v = GModel::current()->getMeshVertexByTag(nodeTag);
  if(!v) {
    Msg::Error("Unknown node %d", nodeTag);
    throw 2;
  }
  if(coord.size() < 3) {
    Msg::Error("Less than three coordinates provided for node %d", nodeTag);
    throw 2;
  }
  v->setXYZ(coord[0], coord[1], coord[2]);
  if(parametricCoord.size() >= 1) v->setParameter(0, parametricCoord[0]);
  if(parametricCoord.size() >= 2) v->setParameter(1, parametricCoord[1]);
}

GMSH_API void gmsh::model::mesh::rebuildNodeCache(bool onlyIfNecessary)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->rebuildMeshVertexCache(onlyIfNecessary);
}

GMSH_API void
gmsh::model::mesh::getNodesForPhysicalGroup(const int dim, const int tag,
                                            std::vector<std::size_t> &nodeTags,
                                            std::vector<double> &coord)
{
  if(!_isInitialized()) { throw -1; }
  nodeTags.clear();
  coord.clear();
  std::vector<MVertex *> v;
  GModel::current()->getMeshVerticesForPhysicalGroup(dim, tag, v);
  if(v.empty()) return;
  nodeTags.resize(v.size());
  coord.resize(v.size() * 3);
  for(std::size_t i = 0; i < v.size(); i++) {
    nodeTags[i] = v[i]->getNum();
    coord[3 * i + 0] = v[i]->x();
    coord[3 * i + 1] = v[i]->y();
    coord[3 * i + 2] = v[i]->z();
  }
}

GMSH_API void gmsh::model::mesh::addNodes(
  const int dim, const int tag, const std::vector<std::size_t> &nodeTags,
  const std::vector<double> &coord, const std::vector<double> &parametricCoord)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  int numNodeTags = nodeTags.size(), numNodes = nodeTags.size();
  if(!numNodeTags) { // this is allowed: we will assign new tags
    numNodes = coord.size() / 3;
  }
  if((int)coord.size() != 3 * numNodes) {
    Msg::Error("Wrong number of coordinates");
    throw 2;
  }
  bool param = false;
  if(parametricCoord.size()) {
    if((int)parametricCoord.size() != dim * numNodes) {
      Msg::Error("Wrong number of parametric coordinates");
      throw 2;
    }
    param = true;
  }
  for(int i = 0; i < numNodes; i++) {
    std::size_t tag = (numNodeTags ? nodeTags[i] : 0); // 0 = automatic tag
    double x = coord[3 * i];
    double y = coord[3 * i + 1];
    double z = coord[3 * i + 2];
    MVertex *vv = 0;
    if(param && dim == 1) {
      double u = parametricCoord[i];
      vv = new MEdgeVertex(x, y, z, ge, u, tag);
    }
    else if(param && dim == 2) {
      double u = parametricCoord[2 * i];
      double v = parametricCoord[2 * i + 1];
      vv = new MFaceVertex(x, y, z, ge, u, v, tag);
    }
    else
      vv = new MVertex(x, y, z, ge, tag);
    ge->mesh_vertices.push_back(vv);
  }
  GModel::current()->destroyMeshCaches();
}

GMSH_API void gmsh::model::mesh::reclassifyNodes()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->pruneMeshVertexAssociations();
}

GMSH_API void gmsh::model::mesh::relocateNodes(const int dim, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  std::vector<GEntity *> entities;
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  else {
    GModel::current()->getEntities(entities, dim);
  }
  for(std::size_t i = 0; i < entities.size(); i++)
    entities[i]->relocateMeshVertices();
}

static void
_getEntitiesForElementTypes(int dim, int tag,
                            std::map<int, std::vector<GEntity *> > &typeEnt)
{
  std::vector<GEntity *> entities;
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    entities.push_back(ge);
  }
  else {
    GModel::current()->getEntities(entities, dim);
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    switch(ge->dim()) {
    case 0: {
      GVertex *v = static_cast<GVertex *>(ge);
      if(v->points.size())
        typeEnt[v->points.front()->getTypeForMSH()].push_back(ge);
      break;
    }
    case 1: {
      GEdge *e = static_cast<GEdge *>(ge);
      if(e->lines.size())
        typeEnt[e->lines.front()->getTypeForMSH()].push_back(ge);
      break;
    }
    case 2: {
      GFace *f = static_cast<GFace *>(ge);
      if(f->triangles.size())
        typeEnt[f->triangles.front()->getTypeForMSH()].push_back(ge);
      if(f->quadrangles.size())
        typeEnt[f->quadrangles.front()->getTypeForMSH()].push_back(ge);
      break;
    }
    case 3: {
      GRegion *r = static_cast<GRegion *>(ge);
      if(r->tetrahedra.size())
        typeEnt[r->tetrahedra.front()->getTypeForMSH()].push_back(ge);
      if(r->hexahedra.size())
        typeEnt[r->hexahedra.front()->getTypeForMSH()].push_back(ge);
      if(r->prisms.size())
        typeEnt[r->prisms.front()->getTypeForMSH()].push_back(ge);
      if(r->pyramids.size())
        typeEnt[r->pyramids.front()->getTypeForMSH()].push_back(ge);
      break;
    }
    }
  }
}

GMSH_API void gmsh::model::mesh::getElements(
  std::vector<int> &elementTypes,
  std::vector<std::vector<std::size_t> > &elementTags,
  std::vector<std::vector<std::size_t> > &nodeTags, const int dim,
  const int tag)
{
  if(!_isInitialized()) { throw -1; }
  elementTypes.clear();
  elementTags.clear();
  nodeTags.clear();
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  for(std::map<int, std::vector<GEntity *> >::const_iterator it =
        typeEnt.begin();
      it != typeEnt.end(); it++) {
    elementTypes.push_back(it->first);
    elementTags.push_back(std::vector<std::size_t>());
    nodeTags.push_back(std::vector<std::size_t>());
    int elementType = it->first;
    for(std::size_t i = 0; i < it->second.size(); i++) {
      GEntity *ge = it->second[i];
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        if(e->getTypeForMSH() == elementType) {
          elementTags.back().push_back(e->getNum());
          for(std::size_t k = 0; k < e->getNumVertices(); k++) {
            nodeTags.back().push_back(e->getVertex(k)->getNum());
          }
        }
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::getElement(const std::size_t elementTag,
                                            int &elementType,
                                            std::vector<std::size_t> &nodeTags)
{
  if(!_isInitialized()) { throw -1; }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    throw 2;
  }
  elementType = e->getTypeForMSH();
  nodeTags.clear();
  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    if(!v) {
      Msg::Error("Unknown node in element %d", elementTag);
      throw 2;
    }
    nodeTags.push_back(v->getNum());
  }
}

GMSH_API void gmsh::model::mesh::getElementByCoordinates(
  const double x, const double y, const double z, std::size_t &elementTag,
  int &elementType, std::vector<std::size_t> &nodeTags, double &u, double &v,
  double &w, const int dim, const bool strict)
{
  if(!_isInitialized()) { throw -1; }
  SPoint3 xyz(x, y, z), uvw;
  MElement *e = GModel::current()->getMeshElementByCoord(xyz, uvw, dim, strict);
  if(!e) {
    Msg::Error("No element found at (%g, %g, %g)", x, y, z);
    throw 2;
  }
  elementTag = e->getNum();
  elementType = e->getTypeForMSH();
  nodeTags.clear();
  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    if(!v) {
      Msg::Error("Unknown node in element %d", elementTag);
      throw 2;
    }
    nodeTags.push_back(v->getNum());
  }
  u = uvw.x();
  v = uvw.y();
  w = uvw.z();
}

GMSH_API void gmsh::model::mesh::getElementsByCoordinates(
  const double x, const double y, const double z,
  std::vector<std::size_t> &elementTags, const int dim, const bool strict)
{
  if(!_isInitialized()) { throw -1; }
  SPoint3 xyz(x, y, z), uvw;
  elementTags.clear();
  std::vector<MElement *> e =
    GModel::current()->getMeshElementsByCoord(xyz, dim, strict);
  if(e.empty()) {
    Msg::Error("No element found at (%g, %g, %g)", x, y, z);
    throw 2;
  }
  for(std::size_t i = 0; i < e.size(); i++) {
    elementTags.push_back(e[i]->getNum());
  }
}

GMSH_API void gmsh::model::mesh::getLocalCoordinatesInElement(
  const std::size_t elementTag, const double x, const double y, const double z,
  double &u, double &v, double &w)
{
  if(!_isInitialized()) { throw -1; }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    throw 2;
  }
  double xyz[3] = {x, y, z}, uvw[3];
  e->xyz2uvw(xyz, uvw);
  u = uvw[0];
  v = uvw[1];
  w = uvw[2];
}

template <class T>
static void _addElements(int dim, int tag, const std::vector<MElement *> &src,
                         std::vector<T *> &dst)
{
  for(std::size_t i = 0; i < src.size(); i++)
    dst.push_back(static_cast<T *>(src[i]));
}

static void _addElements(int dim, int tag, GEntity *ge, int type,
                         const std::vector<std::size_t> &elementTags,
                         const std::vector<std::size_t> &nodeTags)
{
  unsigned int numNodesPerEle = MElement::getInfoMSH(type);
  if(!numNodesPerEle) return;
  std::size_t numEleTags = elementTags.size();
  std::size_t numEle = numEleTags;
  if(!numEle) { numEle = nodeTags.size() / numNodesPerEle; }
  if(!numEle) return;
  if(numEle * numNodesPerEle != nodeTags.size()) {
    Msg::Error("Wrong number of node tags for element type %d", type);
    throw 2;
  }
  std::vector<MElement *> elements(numEle);
  std::vector<MVertex *> nodes(numNodesPerEle);
  for(std::size_t j = 0; j < numEle; j++) {
    std::size_t etag = (numEleTags ? elementTags[j] : 0); // 0 = automatic tag
    MElementFactory f;
    for(std::size_t k = 0; k < numNodesPerEle; k++) {
      std::size_t vtag = nodeTags[numNodesPerEle * j + k];
      // this will rebuild the node cache if necessary
      nodes[k] = GModel::current()->getMeshVertexByTag(vtag);
      if(!nodes[k]) {
        Msg::Error("Unknown node %d", vtag);
        throw 2;
      }
    }
    elements[j] = f.create(type, nodes, etag);
  }
  bool ok = true;
  switch(dim) {
  case 0:
    if(elements[0]->getType() == TYPE_PNT)
      _addElements(dim, tag, elements, static_cast<GVertex *>(ge)->points);
    else
      ok = false;
    break;
  case 1:
    if(elements[0]->getType() == TYPE_LIN)
      _addElements(dim, tag, elements, static_cast<GEdge *>(ge)->lines);
    else
      ok = false;
    break;
  case 2:
    if(elements[0]->getType() == TYPE_TRI)
      _addElements(dim, tag, elements, static_cast<GFace *>(ge)->triangles);
    else if(elements[0]->getType() == TYPE_QUA)
      _addElements(dim, tag, elements, static_cast<GFace *>(ge)->quadrangles);
    else
      ok = false;
    break;
  case 3:
    if(elements[0]->getType() == TYPE_TET)
      _addElements(dim, tag, elements, static_cast<GRegion *>(ge)->tetrahedra);
    else if(elements[0]->getType() == TYPE_HEX)
      _addElements(dim, tag, elements, static_cast<GRegion *>(ge)->hexahedra);
    else if(elements[0]->getType() == TYPE_PRI)
      _addElements(dim, tag, elements, static_cast<GRegion *>(ge)->prisms);
    else if(elements[0]->getType() == TYPE_PYR)
      _addElements(dim, tag, elements, static_cast<GRegion *>(ge)->pyramids);
    else
      ok = false;
    break;
  }
  if(!ok) {
    Msg::Error("Wrong type of element for %s",
               _getEntityName(dim, tag).c_str());
    throw 2;
  }
}

GMSH_API void gmsh::model::mesh::addElements(
  const int dim, const int tag, const std::vector<int> &elementTypes,
  const std::vector<std::vector<std::size_t> > &elementTags,
  const std::vector<std::vector<std::size_t> > &nodeTags)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(elementTypes.size() != elementTags.size()) {
    Msg::Error("Wrong number of element tags");
    throw 2;
  }
  if(elementTypes.size() != nodeTags.size()) {
    Msg::Error("Wrong number of node tags");
    throw 2;
  }

  for(std::size_t i = 0; i < elementTypes.size(); i++)
    _addElements(dim, tag, ge, elementTypes[i], elementTags[i], nodeTags[i]);
  GModel::current()->destroyMeshCaches();
}

GMSH_API void gmsh::model::mesh::addElementsByType(
  const int tag, const int elementType,
  const std::vector<std::size_t> &elementTags,
  const std::vector<std::size_t> &nodeTags)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  _addElements(dim, tag, ge, elementType, elementTags, nodeTags);
  GModel::current()->destroyMeshCaches();
}

GMSH_API void gmsh::model::mesh::getElementTypes(std::vector<int> &elementTypes,
                                                 const int dim, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  elementTypes.clear();
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  for(std::map<int, std::vector<GEntity *> >::const_iterator it =
        typeEnt.begin();
      it != typeEnt.end(); it++) {
    elementTypes.push_back(it->first);
  }
}

GMSH_API int gmsh::model::mesh::getElementType(const std::string &family,
                                               const int order,
                                               const bool serendip)
{
  if(!_isInitialized()) { throw -1; }
  int familyType = (family == "point") ?
                     TYPE_PNT :
                     (family == "line") ?
                     TYPE_LIN :
                     (family == "triangle") ?
                     TYPE_TRI :
                     (family == "quadrangle") ?
                     TYPE_QUA :
                     (family == "tetrahedron") ?
                     TYPE_TET :
                     (family == "pyramid") ?
                     TYPE_PYR :
                     (family == "prism") ?
                     TYPE_PRI :
                     (family == "hexahedron") ?
                     TYPE_HEX :
                     (family == "polygon") ?
                     TYPE_POLYG :
                     (family == "polyhedron") ?
                     TYPE_POLYH :
                     (family == "trihedron") ? TYPE_TRIH : -1;
  return ElementType::getType(familyType, order, serendip);
}

GMSH_API void gmsh::model::mesh::getElementProperties(
  const int elementType, std::string &name, int &dim, int &order, int &numNodes,
  std::vector<double> &localNodeCoord, int &numPrimaryNodes)
{
  if(!_isInitialized()) { throw -1; }
  const char *n;
  MElement::getInfoMSH(elementType, &n);
  name = n;
  int parentType = ElementType::getParentType(elementType);
  nodalBasis *basis = 0;
  if(parentType == TYPE_PYR)
    basis = new pyramidalBasis(elementType);
  else
    basis = new polynomialBasis(elementType);
  dim = basis->dimension;
  order = basis->order;
  numNodes = basis->points.size1();
  if(numNodes != ElementType::getNumVertices(elementType)) {
    Msg::Error("Size of basis incompatible with element type");
    throw 2;
  }
  for(int i = 0; i < basis->points.size1(); i++)
    for(int j = 0; j < basis->points.size2(); j++)
      localNodeCoord.push_back(basis->points(i, j));
  delete basis;
  numPrimaryNodes =
    ElementType::getNumVertices(ElementType::getPrimaryType(elementType));
}

GMSH_API void gmsh::model::mesh::getElementsByType(
  const int elementType, std::vector<std::size_t> &elementTags,
  std::vector<std::size_t> &nodeTags, const int tag, const std::size_t task,
  const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += entities[i]->getNumMeshElementsByType(familyType);
  const int numNodes = ElementType::getNumVertices(elementType);
  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    throw 4;
  }
  const std::size_t begin = (task * numElements) / numTasks;
  const std::size_t end = ((task + 1) * numElements) / numTasks;
  // check arrays
  bool haveElementTags = elementTags.size();
  bool haveNodeTags = nodeTags.size();
  if(!haveElementTags && !haveNodeTags) {
    if(numTasks > 1)
      Msg::Warning("ElementTags and nodeTags should be preallocated "
                   "if numTasks > 1");
    haveElementTags = haveNodeTags = true;
    preallocateElementsByType(elementType, haveElementTags, haveNodeTags,
                              elementTags, nodeTags, tag);
  }
  if(haveElementTags && (elementTags.size() < numElements)) {
    Msg::Error("Wrong size of elementTags array (%d < %d)", elementTags.size(),
               numElements);
    throw 4;
  }
  if(haveNodeTags && (nodeTags.size() < numElements * numNodes)) {
    Msg::Error("Wrong size of nodeTags array (%d < %d)", nodeTags.size(),
               numElements * numNodes);
    throw 4;
  }
  size_t o = 0;
  size_t idx = begin * numNodes;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType); j++) {
      if(o >= begin && o < end) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        if(haveElementTags) elementTags[o] = e->getNum();
        if(haveNodeTags) {
          for(std::size_t k = 0; k < e->getNumVertices(); k++) {
            nodeTags[idx++] = e->getVertex(k)->getNum();
          }
        }
      }
      o++;
    }
  }
}

GMSH_API void gmsh::model::mesh::preallocateElementsByType(
  const int elementType, const bool elementTag, const bool nodeTag,
  std::vector<std::size_t> &elementTags, std::vector<std::size_t> &nodeTags,
  const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += entities[i]->getNumMeshElementsByType(familyType);
  const int numNodesPerEle = ElementType::getNumVertices(elementType);
  if(!numElements) return;
  if(elementTag) {
    elementTags.clear();
    elementTags.resize(numElements, 0);
  }
  if(nodeTag) {
    nodeTags.clear();
    nodeTags.resize(numElements * numNodesPerEle, 0);
  }
}

static bool _getFunctionSpaceInfo(const std::string &fsType,
                                  std::string &fsName, int &fsOrder,
                                  int &fsComp)
{
  if(fsType.empty() || fsType == "None") {
    fsName = "";
    fsOrder = 0;
    fsComp = 0;
    return true;
  }
  if(fsType == "IsoParametric" || fsType == "Lagrange") {
    fsName = "Lagrange";
    fsOrder = -1;
    fsComp = 1;
    return true;
  }
  if(fsType == "GradIsoParametric" || fsType == "GradLagrange") {
    fsName = "GradLagrange";
    fsOrder = -1;
    fsComp = 3;
    return true;
  }
  if(fsType.substr(0, 10) == "H1Legendre") {
    fsName = "H1Legendre";
    fsOrder = atoi(fsType.substr(10).c_str());
    fsComp = 1;
    return true;
  }
  if(fsType.substr(0, 14) == "GradH1Legendre") {
    fsName = "GradH1Legendre";
    fsOrder = atoi(fsType.substr(14).c_str());
    fsComp = 3;
    return true;
  }
  if(fsType.substr(0, 13) == "HcurlLegendre") {
    fsName = "HcurlLegendre";
    fsOrder = atoi(fsType.substr(13).c_str());
    fsComp = 3;
    return true;
  }
  if(fsType.substr(0, 17) == "CurlHcurlLegendre") {
    fsName = "CurlHcurlLegendre";
    fsOrder = atoi(fsType.substr(17).c_str());
    fsComp = 3;
    return true;
  }
  return false;
}

GMSH_API void gmsh::model::mesh::getJacobians(
  const int elementType, const std::vector<double> &localCoord,
  std::vector<double> &jacobians, std::vector<double> &determinants,
  std::vector<double> &coord, const int tag, const std::size_t task,
  const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  int numPoints = localCoord.size() / 3;
  if(!numPoints) {
    Msg::Warning("No evaluation points in getJacobians");
    return;
  }

  // check arrays
  bool haveJacobians = jacobians.size();
  bool haveDeterminants = determinants.size();
  bool havePoints = coord.size();
  if(!haveDeterminants && !haveJacobians && !havePoints) {
    if(numTasks > 1)
      Msg::Warning("Jacobians, determinants and points should be preallocated "
                   "if numTasks > 1");
    haveJacobians = haveDeterminants = havePoints = true;
    preallocateJacobians(elementType, numPoints, haveJacobians,
                         haveDeterminants, havePoints, jacobians, determinants,
                         coord, tag);
  }
  // get data
  {
    std::size_t numElements = 0;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      numElements += ge->getNumMeshElementsByType(familyType);
    }
    if(!numTasks) {
      Msg::Error("Number of tasks should be > 0");
      throw 4;
    }
    const size_t begin = (task * numElements) / numTasks;
    const size_t end = ((task + 1) * numElements) / numTasks;
    if(haveDeterminants && (end * numPoints > determinants.size())) {
      Msg::Error("Wrong size of determinants array (%d < %d)",
                 determinants.size(), end * numPoints);
      throw 4;
    }
    if(haveJacobians && (9 * end * numPoints > jacobians.size())) {
      Msg::Error("Wrong size of jacobians array (%d < %d)", jacobians.size(),
                 9 * end * numPoints);
      throw 4;
    }
    if(havePoints && (3 * end * numPoints > coord.size())) {
      Msg::Error("Wrong size of points array (%d < %d)", coord.size(),
                 3 * end * numPoints);
      throw 4;
    }
    if(haveDeterminants && haveJacobians && havePoints) {
      std::vector<std::vector<SVector3> > gsf;
      size_t o = 0;
      size_t idx = begin * numPoints;
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
            j++) {
          if(o >= begin && o < end) {
            MElement *e = ge->getMeshElementByType(familyType, j);
            if(gsf.size() == 0) {
              gsf.resize(numPoints);
              for(int k = 0; k < numPoints; k++) {
                double value[1256][3];
                e->getGradShapeFunctions(localCoord[3 * k],
                                         localCoord[3 * k + 1],
                                         localCoord[3 * k + 2], value);
                gsf[k].resize(e->getNumShapeFunctions());
                for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
                  gsf[k][l][0] = value[l][0];
                  gsf[k][l][1] = value[l][1];
                  gsf[k][l][2] = value[l][2];
                }
              }
            }
            for(int k = 0; k < numPoints; k++) {
              e->pnt(localCoord[3 * k], localCoord[3 * k + 1],
                     localCoord[3 * k + 2], &coord[idx * 3]);
              determinants[idx] = e->getJacobian(gsf[k], &jacobians[idx * 9]);
              idx++;
            }
          }
          o++;
        }
      }
    }
    else if(haveDeterminants && haveJacobians && !havePoints) {
      std::vector<std::vector<SVector3> > gsf;
      size_t o = 0;
      size_t idx = begin * numPoints;
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
            j++) {
          if(o >= begin && o < end) {
            MElement *e = ge->getMeshElementByType(familyType, j);
            if(gsf.size() == 0) {
              gsf.resize(numPoints);
              for(int k = 0; k < numPoints; k++) {
                double value[1256][3];
                e->getGradShapeFunctions(localCoord[3 * k],
                                         localCoord[3 * k + 1],
                                         localCoord[3 * k + 2], value);
                gsf[k].resize(e->getNumShapeFunctions());
                for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
                  gsf[k][l][0] = value[l][0];
                  gsf[k][l][1] = value[l][1];
                  gsf[k][l][2] = value[l][2];
                }
              }
            }
            for(int k = 0; k < numPoints; k++) {
              determinants[idx] = e->getJacobian(gsf[k], &jacobians[idx * 9]);
              idx++;
            }
          }
          o++;
        }
      }
    }
    else if(haveDeterminants && !haveJacobians && havePoints) {
      std::vector<double> jac(9, 0.);
      std::vector<std::vector<SVector3> > gsf;
      size_t o = 0;
      size_t idx = begin * numPoints;
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
            j++) {
          if(o >= begin && o < end) {
            MElement *e = ge->getMeshElementByType(familyType, j);
            if(gsf.size() == 0) {
              gsf.resize(numPoints);
              for(int k = 0; k < numPoints; k++) {
                double value[1256][3];
                e->getGradShapeFunctions(localCoord[3 * k],
                                         localCoord[3 * k + 1],
                                         localCoord[3 * k + 2], value);
                gsf[k].resize(e->getNumShapeFunctions());
                for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
                  gsf[k][l][0] = value[l][0];
                  gsf[k][l][1] = value[l][1];
                  gsf[k][l][2] = value[l][2];
                }
              }
            }
            for(int k = 0; k < numPoints; k++) {
              e->pnt(localCoord[3 * k], localCoord[3 * k + 1],
                     localCoord[3 * k + 2], &coord[idx * 3]);
              determinants[idx] = e->getJacobian(gsf[k], &jac[0]);
              idx++;
            }
          }
          o++;
        }
      }
    }
    else if(haveDeterminants && !haveJacobians && !havePoints) {
      std::vector<double> jac(9, 0.);
      std::vector<std::vector<SVector3> > gsf;
      size_t o = 0;
      size_t idx = begin * numPoints;
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
            j++) {
          if(o >= begin && o < end) {
            MElement *e = ge->getMeshElementByType(familyType, j);
            if(gsf.size() == 0) {
              gsf.resize(numPoints);
              for(int k = 0; k < numPoints; k++) {
                double value[1256][3];
                e->getGradShapeFunctions(localCoord[3 * k],
                                         localCoord[3 * k + 1],
                                         localCoord[3 * k + 2], value);
                gsf[k].resize(e->getNumShapeFunctions());
                for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
                  gsf[k][l][0] = value[l][0];
                  gsf[k][l][1] = value[l][1];
                  gsf[k][l][2] = value[l][2];
                }
              }
            }
            for(int k = 0; k < numPoints; k++) {
              determinants[idx] = e->getJacobian(gsf[k], &jac[0]);
              idx++;
            }
          }
          o++;
        }
      }
    }
    else if(!haveDeterminants && haveJacobians && !havePoints) {
      std::vector<std::vector<SVector3> > gsf;
      size_t o = 0;
      size_t idx = begin * numPoints;
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
            j++) {
          if(o >= begin && o < end) {
            MElement *e = ge->getMeshElementByType(familyType, j);
            if(gsf.size() == 0) {
              gsf.resize(numPoints);
              for(int k = 0; k < numPoints; k++) {
                double value[1256][3];
                e->getGradShapeFunctions(localCoord[3 * k],
                                         localCoord[3 * k + 1],
                                         localCoord[3 * k + 2], value);
                gsf[k].resize(e->getNumShapeFunctions());
                for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
                  gsf[k][l][0] = value[l][0];
                  gsf[k][l][1] = value[l][1];
                  gsf[k][l][2] = value[l][2];
                }
              }
            }
            for(int k = 0; k < numPoints; k++) {
              e->getJacobian(gsf[k], &jacobians[idx * 9]);
              idx++;
            }
          }
          o++;
        }
      }
    }
    else {
      Msg::Error("The case with 'haveDeterminants = %s', `haveJacobians = %s` "
                 "and 'havePoints = %s' is not yet implemented.",
                 (haveDeterminants ? "true" : "false"),
                 (haveJacobians ? "true" : "false"),
                 (havePoints ? "true" : "false"));
      throw 2;
    }
    // Add other combinaisons if necessary
  }
}

GMSH_API void gmsh::model::mesh::preallocateJacobians(
  const int elementType, const int numPoints, const bool allocateJacobians,
  const bool allocateDeterminants, const bool allocateCoord,
  std::vector<double> &jacobians, std::vector<double> &determinants,
  std::vector<double> &coord, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  BasisFactory::getNodalBasis(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += entities[i]->getNumMeshElementsByType(familyType);
  if(!numElements) return;
  if(allocateJacobians) {
    jacobians.clear();
    jacobians.resize(9 * numElements * numPoints);
  }
  if(allocateDeterminants) {
    determinants.clear();
    determinants.resize(numElements * numPoints);
  }
  if(allocateCoord) {
    coord.clear();
    coord.resize(3 * numElements * numPoints);
  }
}

GMSH_API void gmsh::model::mesh::getJacobian(
  const std::size_t elementTag, const std::vector<double> &localCoord,
  std::vector<double> &jacobians, std::vector<double> &determinants,
  std::vector<double> &coord)
{
  if(!_isInitialized()) { throw -1; }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    throw 2;
  }
  int numPoints = localCoord.size() / 3;
  if(!numPoints) {
    Msg::Warning("No evaluation points in getJacobian");
    return;
  }
  std::vector<std::vector<SVector3> > gsf;
  gsf.resize(numPoints);
  jacobians.resize(9 * numPoints);
  determinants.resize(numPoints);
  coord.resize(3 * numPoints);
  for(int k = 0; k < numPoints; k++) {
    double value[1256][3];
    e->getGradShapeFunctions(localCoord[3 * k],
                             localCoord[3 * k + 1],
                             localCoord[3 * k + 2], value);
    gsf[k].resize(e->getNumShapeFunctions());
    for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
      gsf[k][l][0] = value[l][0];
      gsf[k][l][1] = value[l][1];
      gsf[k][l][2] = value[l][2];
    }
  }
  for(int k = 0; k < numPoints; k++) {
    e->pnt(localCoord[3 * k], localCoord[3 * k + 1],
           localCoord[3 * k + 2], &coord[3 * k]);
    determinants[k] = e->getJacobian(gsf[k], &jacobians[9 * k]);
  }
}

GMSH_API void gmsh::model::mesh::getBasisFunctions(
  const int elementType, const std::vector<double> &localCoord,
  const std::string &functionSpaceType, int &numComponents,
  std::vector<double> &basisFunctions, int &numOrientations,
  const std::vector<int> &wantedOrientations)
{
  if(!_isInitialized()) { throw -1; }
  numComponents = 0;
  basisFunctions.clear();
  std::string fsName = "";
  int fsOrder = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, fsOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }

  const std::size_t numberOfGaussPoints = localCoord.size() / 3;
  const int familyType = ElementType::getParentType(elementType);

  if(fsName == "Lagrange" || fsName == "GradLagrange") { // Lagrange type
    // Check if there is no error in wantedOrientations
    if(wantedOrientations.size() != 0) {
      if(wantedOrientations.size() > 1) {
        Msg::Error("Asking for more orientation that there exist.");
        throw 10;
      }

      if(wantedOrientations[0] != 0) {
        Msg::Error(
          "Orientation %i does not exist for function stace named '%s' on %s.",
          wantedOrientations[0], fsName.c_str(),
          ElementType::nameOfParentType(familyType, true).c_str());
        throw 11;
      }
    }

    const nodalBasis *basis = 0;
    if(numComponents) {
      if(fsOrder == -1) { // isoparametric
        basis = BasisFactory::getNodalBasis(elementType);
      }
      else {
        int newType = ElementType::getType(familyType, fsOrder, false);
        basis = BasisFactory::getNodalBasis(newType);
      }
    }
    if(basis) {
      const std::size_t n = basis->getNumShapeFunctions();
      basisFunctions.resize(n * numComponents * numberOfGaussPoints, 0.);
      double s[1256], ds[1256][3];
      for(std::size_t i = 0; i < numberOfGaussPoints; i++) {
        double u = localCoord[i * 3];
        double v = localCoord[i * 3 + 1];
        double w = localCoord[i * 3 + 2];
        switch(numComponents) {
        case 1:
          basis->f(u, v, w, s);
          for(std::size_t j = 0; j < n; j++) basisFunctions[n * i + j] = s[j];
          break;
        case 3:
          basis->df(u, v, w, ds);
          for(std::size_t j = 0; j < n; j++) {
            basisFunctions[n * 3 * i + 3 * j] = ds[j][0];
            basisFunctions[n * 3 * i + 3 * j + 1] = ds[j][1];
            basisFunctions[n * 3 * i + 3 * j + 2] = ds[j][2];
          }
          break;
        }
      }
    }
    numOrientations = 1;
  }
  else { // Hierarchical type
    HierarchicalBasis *basis(0);
    if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
      switch(familyType) {
      case TYPE_HEX: {
        basis = new HierarchicalBasisH1Brick(fsOrder);
      } break;
      case TYPE_PRI: {
        basis = new HierarchicalBasisH1Pri(fsOrder);
      } break;
      case TYPE_TET: {
        basis = new HierarchicalBasisH1Tetra(fsOrder);
      } break;
      case TYPE_QUA: {
        basis = new HierarchicalBasisH1Quad(fsOrder);
      } break;
      case TYPE_TRI: {
        basis = new HierarchicalBasisH1Tria(fsOrder);
      } break;
      case TYPE_LIN: {
        basis = new HierarchicalBasisH1Line(fsOrder);
      } break;
      case TYPE_PNT: {
        basis = new HierarchicalBasisH1Point();
      } break;
      default: Msg::Error("Unknown familyType "); throw 2;
      }
    }
    else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre") {
      switch(familyType) {
      case TYPE_QUA: {
        basis = new HierarchicalBasisHcurlQuad(fsOrder);
      } break;
      case TYPE_HEX: {
        basis = new HierarchicalBasisHcurlBrick(fsOrder);
      } break;
      case TYPE_TRI: {
        basis = new HierarchicalBasisHcurlTria(fsOrder);
      } break;
      case TYPE_TET: {
        basis = new HierarchicalBasisHcurlTetra(fsOrder);
      } break;
      case TYPE_PRI: {
        basis = new HierarchicalBasisHcurlPri(fsOrder);
      } break;
      case TYPE_LIN: {
        basis = new HierarchicalBasisHcurlLine(fsOrder);
      } break;
      default: Msg::Error("Unknown familyType "); throw 2;
      }
    }
    else {
      Msg::Error("Unknown function space named '%s'", fsName.c_str());
      throw 3;
    }

    const std::size_t vSize = basis->getnVertexFunction();
    const std::size_t bSize = basis->getnBubbleFunction();
    const std::size_t eSize = basis->getnEdgeFunction();
    const std::size_t fSize =
      basis->getnTriFaceFunction() + basis->getnQuadFaceFunction();
    const std::size_t maxOrientation = basis->getNumberOfOrientations();
    numOrientations = maxOrientation;
    const std::size_t numFunctionsPerElement = vSize + bSize + eSize + fSize;
    const unsigned int numVertices =
      ElementType::getNumVertices(ElementType::getType(familyType, 1, false));

    basisFunctions.resize(
      (wantedOrientations.size() == 0 ? maxOrientation :
                                        wantedOrientations.size()) *
      numberOfGaussPoints * numFunctionsPerElement * numComponents);

    // Check if there is no error in wantedOrientations
    if(wantedOrientations.size() != 0) {
      if(wantedOrientations.size() > maxOrientation) {
        Msg::Error("Asking for more orientation that there exist.");
        throw 10;
      }
      for(unsigned int i = 0; i < wantedOrientations.size(); ++i) {
        if(wantedOrientations[i] >= static_cast<int>(maxOrientation) ||
           wantedOrientations[i] < 0) {
          Msg::Error("Orientation %i does not exist for function stace named "
                     "'%s' on %s.",
                     wantedOrientations[i], fsName.c_str(),
                     ElementType::nameOfParentType(familyType, true).c_str());
          throw 11;
        }
      }
      std::vector<int> sortedWantedOrientations = wantedOrientations;
      std::sort(sortedWantedOrientations.begin(),
                sortedWantedOrientations.end());
      int previousInt = sortedWantedOrientations[0];
      for(unsigned int i = 1; i < sortedWantedOrientations.size(); ++i) {
        if(previousInt == sortedWantedOrientations[i]) {
          Msg::Error("Duplicate wanted orientation found.");
          throw 12;
        }
        previousInt = sortedWantedOrientations[i];
      }
    }

    std::vector<MVertex *> vertices(numVertices);
    for(unsigned int i = 0; i < numVertices; ++i) {
      vertices[i] = new MVertex(0., 0., 0., 0, i + 1);
    }
    MElement *element = 0;
    switch(familyType) {
    case TYPE_HEX: {
      element = new MHexahedron(vertices);
    } break;
    case TYPE_PRI: {
      element = new MPrism(vertices);
    } break;
    case TYPE_TET: {
      element = new MTetrahedron(vertices);
    } break;
    case TYPE_QUA: {
      element = new MQuadrangle(vertices);
    } break;
    case TYPE_TRI: {
      element = new MTriangle(vertices);
    } break;
    case TYPE_LIN: {
      element = new MLine(vertices);
    } break;
    case TYPE_PNT: {
      element = new MPoint(vertices);
    } break;
    default: Msg::Error("Unknown familyType "); throw 2;
    }

    switch(numComponents) {
    case 1: {
      std::vector<std::vector<double> > vTable(
        numberOfGaussPoints,
        std::vector<double>(vSize)); // Vertex functions of one element
      std::vector<std::vector<double> > bTable(
        numberOfGaussPoints,
        std::vector<double>(bSize)); // bubble functions of one element
      std::vector<std::vector<double> > fTable(
        numberOfGaussPoints,
        std::vector<double>(fSize)); // face functions of one element
      std::vector<std::vector<double> > eTable(
        numberOfGaussPoints,
        std::vector<double>(eSize)); // edge functions of one element

      for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
        const double u = localCoord[3 * q];
        const double v = localCoord[3 * q + 1];
        const double w = localCoord[3 * q + 2];

        basis->generateBasis(u, v, w, vTable[q], eTable[q], fTable[q],
                             bTable[q]);
      }
      // compute only one time the value of the edge basis functions for
      // each possible orientations
      std::vector<std::vector<double> > eTableNegativeFlag(eTable);
      if(eSize != 0) {
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          basis->orientEdgeFunctionsForNegativeFlag(eTableNegativeFlag[q]);
        }
      }

      // compute only one time the value of the face basis functions for
      // each possible orientations
      std::vector<std::vector<double> > quadFaceFunctionsAllOrientations(
        numberOfGaussPoints,
        std::vector<double>(basis->getnQuadFaceFunction() * 8, 0));
      std::vector<std::vector<double> > triFaceFunctionsAllOrientations(
        numberOfGaussPoints,
        std::vector<double>(basis->getnTriFaceFunction() * 6, 0));
      if(fSize != 0) {
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          const double u = localCoord[3 * q];
          const double v = localCoord[3 * q + 1];
          const double w = localCoord[3 * q + 2];

          basis->addAllOrientedFaceFunctions(
            u, v, w, fTable[q], quadFaceFunctionsAllOrientations[q],
            triFaceFunctionsAllOrientations[q]);
        }
      }

      std::vector<std::vector<double> > eTableCopy(
        numberOfGaussPoints,
        std::vector<double>(eSize, 0)); // use eTableCopy to orient the edges
      std::vector<std::vector<double> > fTableCopy(
        numberOfGaussPoints,
        std::vector<double>(fSize, 0)); // use fTableCopy to orient the faces

      unsigned int iOrientationIndex = 0;
      for(unsigned int iOrientation = 0; iOrientation < maxOrientation;
          ++iOrientation) {
        if(wantedOrientations.size() != 0) {
          std::vector<int>::const_iterator it = std::find(
            wantedOrientations.begin(), wantedOrientations.end(), iOrientation);
          if(it != wantedOrientations.end()) {
            iOrientationIndex = &(*it) - &wantedOrientations[0];
          }
          else {
            MVertexPtrLessThan comp;
            std::next_permutation(vertices.begin(), vertices.end(), comp);
            for(unsigned int i = 0; i < numVertices; ++i) {
              element->setVertex(i, vertices[i]);
            }
            continue;
          }
        }
        else {
          iOrientationIndex = iOrientation;
        }

        if(eSize != 0) {
          for(int iEdge = 0; iEdge < basis->getNumEdge(); ++iEdge) {
            MEdge edge = element->getEdge(iEdge);
            const int orientationFlag =
              (edge.getMinVertex()->getNum() !=
                   unsigned(element->getVertexSolin(iEdge, 0)) ?
                 -1 :
                 1);
            for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
              basis->orientEdge(orientationFlag, iEdge, eTableCopy[q],
                                eTable[q], eTableNegativeFlag[q]);
            }
          }
        }

        if(fSize != 0) {
          for(int iFace = 0;
              iFace < basis->getNumTriFace() + basis->getNumQuadFace();
              ++iFace) {
            MFace face = element->getFaceSolin(iFace);
            std::vector<int> faceOrientationFlag(3);
            face.getOrientationFlagForFace(faceOrientationFlag);
            for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
              basis->orientFace(faceOrientationFlag[0], faceOrientationFlag[1],
                                faceOrientationFlag[2], iFace,
                                quadFaceFunctionsAllOrientations[q],
                                triFaceFunctionsAllOrientations[q],
                                fTableCopy[q]);
            }
          }
        }

        const std::size_t offsetOrientation =
          iOrientationIndex * numberOfGaussPoints * numFunctionsPerElement;
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          const std::size_t offsetGP = q * numFunctionsPerElement;

          for(unsigned int i = 0; i < vSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + i] = vTable[q][i];
          }
          unsigned int offset = vSize;
          for(unsigned int i = 0; i < eSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + i] =
              eTableCopy[q][i];
          }
          offset += eSize;
          for(unsigned int i = 0; i < fSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + i] =
              fTableCopy[q][i];
          }
          offset += fSize;
          for(unsigned int i = 0; i < bSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + i] =
              bTable[q][i];
          }
        }

        MVertexPtrLessThan comp;
        std::next_permutation(vertices.begin(), vertices.end(), comp);
        for(unsigned int i = 0; i < numVertices; ++i) {
          element->setVertex(i, vertices[i]);
        }
      }
      break;
    }
    case 3: {
      std::vector<std::vector<std::vector<double> > > vTable(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          vSize,
          std::vector<double>(3, 0.))); // Vertex functions of one element
      std::vector<std::vector<std::vector<double> > > bTable(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          bSize,
          std::vector<double>(3, 0.))); // bubble functions of one element
      std::vector<std::vector<std::vector<double> > > fTable(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          fSize, std::vector<double>(3, 0.))); // face functions of one element
      std::vector<std::vector<std::vector<double> > > eTable(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          eSize, std::vector<double>(3, 0.))); // edge functions of one element

      for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
        const double u = localCoord[3 * q];
        const double v = localCoord[3 * q + 1];
        const double w = localCoord[3 * q + 2];

        basis->generateBasis(u, v, w, vTable[q], eTable[q], fTable[q],
                             bTable[q], fsName);
      }
      // compute only one time the value of the edge basis functions for
      // each possible orientations
      std::vector<std::vector<std::vector<double> > > eTableNegativeFlag(
        eTable);
      if(eSize != 0) {
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          basis->orientEdgeFunctionsForNegativeFlag(eTableNegativeFlag[q]);
        }
      }

      // compute only one time the value of the face basis functions for
      // each possible orientations
      std::vector<std::vector<std::vector<double> > >
        quadFaceFunctionsAllOrientations(
          numberOfGaussPoints,
          std::vector<std::vector<double> >(basis->getnQuadFaceFunction() * 8,
                                            std::vector<double>(3, 0.)));
      std::vector<std::vector<std::vector<double> > >
        triFaceFunctionsAllOrientations(
          numberOfGaussPoints,
          std::vector<std::vector<double> >(basis->getnTriFaceFunction() * 6,
                                            std::vector<double>(3, 0.)));
      if(fSize != 0) {
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          const double u = localCoord[3 * q];
          const double v = localCoord[3 * q + 1];
          const double w = localCoord[3 * q + 2];

          basis->addAllOrientedFaceFunctions(
            u, v, w, fTable[q], quadFaceFunctionsAllOrientations[q],
            triFaceFunctionsAllOrientations[q], fsName);
        }
      }

      std::vector<std::vector<std::vector<double> > > eTableCopy(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          eSize,
          std::vector<double>(3, 0.))); // use eTableCopy to orient the edges
      std::vector<std::vector<std::vector<double> > > fTableCopy(
        numberOfGaussPoints,
        std::vector<std::vector<double> >(
          fSize,
          std::vector<double>(3, 0.))); // use fTableCopy to orient the faces

      unsigned int iOrientationIndex = 0;
      for(unsigned int iOrientation = 0; iOrientation < maxOrientation;
          ++iOrientation) {
        if(wantedOrientations.size() != 0) {
          std::vector<int>::const_iterator it = std::find(
            wantedOrientations.begin(), wantedOrientations.end(), iOrientation);
          if(it != wantedOrientations.end()) {
            iOrientationIndex = &(*it) - &wantedOrientations[0];
          }
          else {
            MVertexPtrLessThan comp;
            std::next_permutation(vertices.begin(), vertices.end(), comp);
            for(unsigned int i = 0; i < numVertices; ++i) {
              element->setVertex(i, vertices[i]);
            }
            continue;
          }
        }
        else {
          iOrientationIndex = iOrientation;
        }

        if(eSize != 0) {
          for(int iEdge = 0; iEdge < basis->getNumEdge(); ++iEdge) {
            MEdge edge = element->getEdge(iEdge);
            const int orientationFlag =
              (edge.getMinVertex()->getNum() !=
                   unsigned(element->getVertexSolin(iEdge, 0)) ?
                 -1 :
                 1);
            for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
              basis->orientEdge(orientationFlag, iEdge, eTableCopy[q],
                                eTable[q], eTableNegativeFlag[q]);
            }
          }
        }

        if(fSize != 0) {
          for(int iFace = 0;
              iFace < basis->getNumTriFace() + basis->getNumQuadFace();
              ++iFace) {
            MFace face = element->getFaceSolin(iFace);
            std::vector<int> faceOrientationFlag(3);
            face.getOrientationFlagForFace(faceOrientationFlag);
            for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
              basis->orientFace(faceOrientationFlag[0], faceOrientationFlag[1],
                                faceOrientationFlag[2], iFace,
                                quadFaceFunctionsAllOrientations[q],
                                triFaceFunctionsAllOrientations[q],
                                fTableCopy[q]);
            }
          }
        }

        const std::size_t offsetOrientation =
          iOrientationIndex * numberOfGaussPoints * numFunctionsPerElement * 3;
        for(unsigned int q = 0; q < numberOfGaussPoints; ++q) {
          const std::size_t offsetGP = q * numFunctionsPerElement * 3;

          for(unsigned int i = 0; i < vSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + 3 * i] =
              vTable[q][i][0];
            basisFunctions[offsetOrientation + offsetGP + 3 * i + 1] =
              vTable[q][i][1];
            basisFunctions[offsetOrientation + offsetGP + 3 * i + 2] =
              vTable[q][i][2];
          }
          unsigned int offset = 3 * vSize;
          for(unsigned int i = 0; i < eSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i] =
              eTableCopy[q][i][0];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 1] =
              eTableCopy[q][i][1];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 2] =
              eTableCopy[q][i][2];
          }
          offset += 3 * eSize;
          for(unsigned int i = 0; i < fSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i] =
              fTableCopy[q][i][0];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 1] =
              fTableCopy[q][i][1];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 2] =
              fTableCopy[q][i][2];
          }
          offset += 3 * fSize;
          for(unsigned int i = 0; i < bSize; ++i) {
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i] =
              bTable[q][i][0];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 1] =
              bTable[q][i][1];
            basisFunctions[offsetOrientation + offsetGP + offset + 3 * i + 2] =
              bTable[q][i][2];
          }
        }

        MVertexPtrLessThan comp;
        std::next_permutation(vertices.begin(), vertices.end(), comp);
        for(unsigned int i = 0; i < numVertices; ++i) {
          element->setVertex(i, vertices[i]);
        }
      }
      break;
    }
    }

    for(unsigned int i = 0; i < numVertices; ++i) { delete vertices[i]; }
    delete element;
    delete basis;
  }

  return;
}

GMSH_API void gmsh::model::mesh::getBasisFunctionsOrientationForElements(
  const int elementType, const std::string &functionSpaceType,
  std::vector<int> &basisFunctionsOrientation, const int tag,
  const std::size_t task, const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }

  if(!basisFunctionsOrientation.size()) {
    if(numTasks > 1) {
      Msg::Warning(
        "basisFunctionsOrientation should be preallocated if numTasks > 1");
    }
    preallocateBasisFunctionsOrientationForElements(
      elementType, basisFunctionsOrientation, tag);
  }

  const int familyType = ElementType::getParentType(elementType);

  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }

  const int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);

  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    const GEntity *ge = entities[i];
    numElements += ge->getNumMeshElementsByType(familyType);
  }

  if(numElements != basisFunctionsOrientation.size()) {
    Msg::Error("Wrong size of 'basisFunctionsOrientation' vector (%i != %i)",
               numElements, basisFunctionsOrientation.size());
    throw 3;
  }

  if(fsName == "Lagrange" || fsName == "GradLagrange") { // Lagrange type
    const std::size_t begin = task * numElements / numTasks;
    const std::size_t end = (task + 1) * numElements / numTasks;
    for(std::size_t iElement = begin; iElement < end; ++iElement) {
      basisFunctionsOrientation[iElement] = 0;
    }
  }
  else { // Hierarchical type
    const unsigned int numVertices =
      ElementType::getNumVertices(ElementType::getType(familyType, 1, false));
    std::vector<MVertex *> vertices(numVertices);
    std::vector<unsigned int> verticesOrder(numVertices);
    const std::size_t factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

    std::size_t entityOffset = 0;

    for(std::size_t iEntity = 0; iEntity < entities.size(); ++iEntity) {
      const GEntity *ge = entities[iEntity];
      std::size_t localNumElements = ge->getNumMeshElementsByType(familyType);

      const std::size_t begin = task * localNumElements / numTasks;
      const std::size_t end = (task + 1) * localNumElements / numTasks;

      for(std::size_t iElement = begin; iElement < end; ++iElement) {
        MElement *e = ge->getMeshElementByType(familyType, iElement);
        for(std::size_t i = 0; i < numVertices; ++i) {
          vertices[i] = e->getVertex(i);
        }

        for(std::size_t i = 0; i < numVertices; ++i) {
          std::size_t max = 0;
          std::size_t maxPos = 0;
          for(std::size_t j = 0; j < numVertices; ++j) {
            if(vertices[j] != 0) {
              if(max < vertices[j]->getNum()) {
                max = vertices[j]->getNum();
                maxPos = j;
              }
            }
          }
          vertices[maxPos] = 0;
          verticesOrder[maxPos] = numVertices - i - 1;
        }

        std::size_t elementOrientation = 0;
        for(std::size_t i = 0; i < numVertices; ++i) {
          elementOrientation +=
            verticesOrder[i] * factorial[numVertices - i - 1];
          for(std::size_t j = i + 1; j < numVertices; ++j) {
            if(verticesOrder[j] > verticesOrder[i]) --verticesOrder[j];
          }
        }

        basisFunctionsOrientation[entityOffset + iElement] =
          (int)elementOrientation;
      }

      entityOffset += localNumElements;
    }
  }

  return;
}

GMSH_API int
gmsh::model::mesh::getNumberOfOrientations(const int elementType,
                                           const std::string &functionSpaceType)
{
  if(!_isInitialized()) { throw -1; }

  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }

  if(fsName == "Lagrange" || fsName == "GradLagrange") { // Lagrange type
    return 1;
  }
  else { // Hierarchical type
    const int familyType = ElementType::getParentType(elementType);
    const unsigned int numVertices =
      ElementType::getNumVertices(ElementType::getType(familyType, 1, false));
    const std::size_t factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
    return factorial[numVertices];
  }

  return 0;
}

GMSH_API void
gmsh::model::mesh::preallocateBasisFunctionsOrientationForElements(
  const int elementType, std::vector<int> &basisFunctionsOrientation,
  const int tag)
{
  if(!_isInitialized()) { throw -1; }

  const int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);

  const int familyType = ElementType::getParentType(elementType);

  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    const GEntity *ge = entities[i];
    numElements += ge->getNumMeshElementsByType(familyType);
  }
  if(!numElements) return;
  basisFunctionsOrientation.resize(numElements);
}

GMSH_API void
gmsh::model::mesh::getEdgeNumber(const std::vector<int> &edgeNodes,
                                 std::vector<int> &edgeNum)
{
  edgeNum.clear();
  int numEdges = edgeNodes.size() / 2;
  if(!numEdges) return;
  edgeNum.resize(numEdges);
  for(int i = 0; i < numEdges; i++) {
    MEdge edge(GModel::current()->getMeshVertexByTag(edgeNodes[2 * i]),
               GModel::current()->getMeshVertexByTag(edgeNodes[2 * i + 1]));
    edgeNum[i] = GModel::current()->getEdgeNumber(edge);
  }
}

GMSH_API void gmsh::model::mesh::getLocalMultipliersForHcurl0(
  const int elementType, std::vector<int> &localMultipliers, const int tag)
{
  localMultipliers.clear();
  int basisOrder = 0;
  std::string fsName = "";
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  HierarchicalBasis *basis(0);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  switch(familyType) {
  case TYPE_QUA: {
    basis = new HierarchicalBasisHcurlQuad(basisOrder);
  } break;
  case TYPE_HEX: {
    basis = new HierarchicalBasisHcurlBrick(basisOrder);
  } break;
  case TYPE_TRI: {
    basis = new HierarchicalBasisHcurlTria(basisOrder);
  } break;
  case TYPE_TET: {
    basis = new HierarchicalBasisHcurlTetra(basisOrder);
  } break;
  case TYPE_PRI: {
    basis = new HierarchicalBasisHcurlPri(basisOrder);
  } break;
  case TYPE_LIN: {
    basis = new HierarchicalBasisHcurlLine(basisOrder);
  } break;
  default: Msg::Error("Unknown familyType "); throw 2;
  }
  // compute the number of Element :
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    std::size_t numElementsInEntitie = ge->getNumMeshElementsByType(familyType);
    numElements += numElementsInEntitie;
  }
  if(!numElements) return;
  int numberEdge = basis->getNumEdge();
  localMultipliers.resize(numElements * numberEdge, 1);
  size_t indexNumElement = 0;
  for(std::size_t ii = 0; ii < entities.size(); ii++) {
    GEntity *ge = entities[ii];
    for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType); j++) {
      MElement *e = ge->getMeshElementByType(familyType, j);
      for(int iEdge = 0; iEdge < basis->getNumEdge(); iEdge++) {
        MEdge edge = e->getEdge(iEdge);
        if(edge.getMinVertex()->getNum() !=
           unsigned(e->getVertexSolin(iEdge, 0))) {
          localMultipliers[indexNumElement * numberEdge + iEdge] = -1;
        }
      }
      indexNumElement++;
    }
  }
  delete basis;
}

GMSH_API void gmsh::model::mesh::getKeysForElements(
  const int elementType, const std::string &functionSpaceType,
  gmsh::vectorpair &keys, std::vector<double> &coord, const int tag,
  const bool generateCoord)
{
  if(!_isInitialized()) { throw -1; }
  coord.clear();
  keys.clear();
  int order = 0;
  int numComponents = 0;
  std::string fsName = "";
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, order, numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);

  HierarchicalBasis *basis(0);
  if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
    switch(familyType) {
    case TYPE_HEX: {
      basis = new HierarchicalBasisH1Brick(order);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisH1Pri(order);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisH1Tetra(order);
    } break;
    case TYPE_QUA: {
      basis = new HierarchicalBasisH1Quad(order);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisH1Tria(order);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisH1Line(order);
    } break;
    case TYPE_PNT: {
      basis = new HierarchicalBasisH1Point();
    } break;
    default: Msg::Error("Unknown familyType "); throw 2;
    }
  }
  else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre") {
    switch(familyType) {
    case TYPE_QUA: {
      basis = new HierarchicalBasisHcurlQuad(order);
    } break;
    case TYPE_HEX: {
      basis = new HierarchicalBasisHcurlBrick(order);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisHcurlTria(order);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisHcurlTetra(order);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisHcurlPri(order);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisHcurlLine(order);
    } break;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    const nodalBasis *nodalB(0);
    if(order == -1) { // isoparametric
      nodalB = BasisFactory::getNodalBasis(elementType);
    }
    else {
      int familyType = ElementType::getParentType(elementType);
      int newType = ElementType::getType(familyType, order, false);
      nodalB = BasisFactory::getNodalBasis(newType);
    }

    for(std::size_t i = 0; i < entities.size(); ++i) {
      GEntity *ge = entities[i];
      std::size_t numElementsInEntitie =
        ge->getNumMeshElementsByType(familyType);
      if(generateCoord) {
        coord.reserve(coord.size() + numElementsInEntitie *
                                       nodalB->getNumShapeFunctions() * 3);
      }
      keys.reserve(keys.size() +
                   numElementsInEntitie * nodalB->getNumShapeFunctions());

      for(std::size_t j = 0; j < numElementsInEntitie; ++j) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        for(size_t k = 0; k < e->getNumVertices(); ++k) {
          keys.push_back(
            std::pair<int, std::size_t>(0, e->getVertex(k)->getNum()));
          if(generateCoord) {
            coord.push_back(e->getVertex(k)->x());
            coord.push_back(e->getVertex(k)->y());
            coord.push_back(e->getVertex(k)->z());
          }
        }
      }
    }
    return;
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    throw 3;
  }

  int vSize = basis->getnVertexFunction();
  int bSize = basis->getnBubbleFunction();
  int eSize = basis->getnEdgeFunction();
  int quadFSize = basis->getnQuadFaceFunction();
  int triFSize = basis->getnTriFaceFunction();
  int fSize = quadFSize + triFSize;
  int numDofsPerElement = vSize + bSize + eSize + fSize;
  int numberQuadFaces = basis->getNumQuadFace();
  int numberTriFaces = basis->getNumTriFace();
  int numTriFaceFunction = 0;
  if(basis->getNumTriFace() != 0) {
    numTriFaceFunction =
      triFSize /
      basis->getNumTriFace(); // number of Tri face functions for one face
  }
  int numQuadFaceFunction = 0;
  if(basis->getNumQuadFace() != 0) {
    numQuadFaceFunction =
      quadFSize /
      basis->getNumQuadFace(); // number of Tri face functions for one face
  }
  int numEdgeFunction = 0;
  if(basis->getNumEdge() != 0) {
    numEdgeFunction =
      eSize / basis->getNumEdge(); // number of edge functions for one edge
  }
  int const1 = numEdgeFunction + 1;
  int const2 = const1 + numQuadFaceFunction;
  int const3 = const1 + numTriFaceFunction;
  int const4 = bSize + std::max(const3, const2);
  delete basis;

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    std::size_t numElementsInEntitie = ge->getNumMeshElementsByType(familyType);
    if(generateCoord) {
      coord.reserve(coord.size() +
                    numElementsInEntitie * numDofsPerElement * 3);
    }
    keys.reserve(keys.size() + numElementsInEntitie * numDofsPerElement);

    for(std::size_t j = 0; j < numElementsInEntitie; j++) {
      MElement *e = ge->getMeshElementByType(familyType, j);
      // vertices
      for(int k = 0; k < vSize; k++) {
        keys.push_back(
          std::pair<int, std::size_t>(0, e->getVertex(k)->getNum()));
        if(generateCoord) {
          coord.push_back(e->getVertex(k)->x());
          coord.push_back(e->getVertex(k)->y());
          coord.push_back(e->getVertex(k)->z());
        }
      }
      // edges
      if(eSize > 0) {
        for(int jj = 0; jj < e->getNumEdges(); jj++) {
          MEdge edge = e->getEdge(jj);
          double coordEdge[3];
          if(generateCoord) {
            MVertex *v1 = edge.getVertex(0);
            MVertex *v2 = edge.getVertex(1);

            coordEdge[0] = 0.5 * (v1->x() + v2->x());
            coordEdge[1] = 0.5 * (v1->y() + v2->y());
            coordEdge[2] = 0.5 * (v1->z() + v2->z());
          }
          int edgeGlobalIndice = GModel::current()->addMEdge(edge);
          for(int k = 1; k < const1; k++) {
            keys.push_back(std::pair<int, std::size_t>(k, edgeGlobalIndice));
            if(generateCoord) {
              coord.push_back(coordEdge[0]);
              coord.push_back(coordEdge[1]);
              coord.push_back(coordEdge[2]);
            }
          }
        }
      }
      // faces
      if(fSize > 0) {
        for(int jj = 0; jj < numberQuadFaces + numberTriFaces; jj++) {
          // Number the faces
          MFace face = e->getFaceSolin(jj);
          double coordFace[3] = {0., 0., 0.};
          if(generateCoord) {
            for(std::size_t indexV = 0; indexV < face.getNumVertices();
                ++indexV) {
              coordFace[0] += face.getVertex(indexV)->x();
              coordFace[1] += face.getVertex(indexV)->y();
              coordFace[2] += face.getVertex(indexV)->z();
            }
            coordFace[0] /= face.getNumVertices();
            coordFace[1] /= face.getNumVertices();
            coordFace[2] /= face.getNumVertices();
          }
          int faceGlobalIndice = GModel::current()->addMFace(face);
          int it2 = const2;
          if(jj >= numberQuadFaces) { it2 = const3; }
          for(int k = const1; k < it2; k++) {
            keys.push_back(std::pair<int, std::size_t>(k, faceGlobalIndice));
            if(generateCoord) {
              coord.push_back(coordFace[0]);
              coord.push_back(coordFace[1]);
              coord.push_back(coordFace[2]);
            }
          }
        }
      }
      // volumes
      if(bSize > 0) {
        double bubbleCenterCoord[3] = {0., 0., 0.};
        if(generateCoord) {
          for(unsigned int indexV = 0; indexV < e->getNumVertices(); ++indexV) {
            bubbleCenterCoord[0] += e->getVertex(indexV)->x();
            bubbleCenterCoord[1] += e->getVertex(indexV)->y();
            bubbleCenterCoord[2] += e->getVertex(indexV)->z();
          }
          bubbleCenterCoord[0] /= e->getNumVertices();
          bubbleCenterCoord[1] /= e->getNumVertices();
          bubbleCenterCoord[2] /= e->getNumVertices();
        }
        for(int k = std::max(const3, const2); k < const4; k++) {
          keys.push_back(std::pair<int, std::size_t>(k, e->getNum()));
          if(generateCoord) {
            coord.push_back(bubbleCenterCoord[0]);
            coord.push_back(bubbleCenterCoord[1]);
            coord.push_back(bubbleCenterCoord[2]);
          }
        }
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::getKeysForElement(
  const std::size_t elementTag, const std::string & functionSpaceType,
  gmsh::vectorpair & keys, std::vector<double> & coord,
  const bool generateCoord)
{
  if(!_isInitialized()) { throw -1; }
  coord.clear();
  keys.clear();
  int order = 0;
  int numComponents = 0;
  std::string fsName = "";
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, order, numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  int elementType = e->getTypeForMSH();
  int familyType = ElementType::getParentType(elementType);

  HierarchicalBasis *basis(0);
  if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
    switch(familyType) {
    case TYPE_HEX: {
      basis = new HierarchicalBasisH1Brick(order);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisH1Pri(order);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisH1Tetra(order);
    } break;
    case TYPE_QUA: {
      basis = new HierarchicalBasisH1Quad(order);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisH1Tria(order);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisH1Line(order);
    } break;
    case TYPE_PNT: {
      basis = new HierarchicalBasisH1Point();
    } break;
    default: Msg::Error("Unknown familyType "); throw 2;
    }
  }
  else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre") {
    switch(familyType) {
    case TYPE_QUA: {
      basis = new HierarchicalBasisHcurlQuad(order);
    } break;
    case TYPE_HEX: {
      basis = new HierarchicalBasisHcurlBrick(order);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisHcurlTria(order);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisHcurlTetra(order);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisHcurlPri(order);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisHcurlLine(order);
    } break;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    for(size_t k = 0; k < e->getNumVertices(); ++k) {
      keys.push_back(std::pair<int, std::size_t>(0, e->getVertex(k)->getNum()));
      if(generateCoord) {
        coord.push_back(e->getVertex(k)->x());
        coord.push_back(e->getVertex(k)->y());
        coord.push_back(e->getVertex(k)->z());
      }
    }
    return;
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    throw 3;
  }

  int vSize = basis->getnVertexFunction();
  int bSize = basis->getnBubbleFunction();
  int eSize = basis->getnEdgeFunction();
  int quadFSize = basis->getnQuadFaceFunction();
  int triFSize = basis->getnTriFaceFunction();
  int fSize = quadFSize + triFSize;
  int numberQuadFaces = basis->getNumQuadFace();
  int numberTriFaces = basis->getNumTriFace();
  int numTriFaceFunction = 0;
  if(basis->getNumTriFace() != 0) {
    numTriFaceFunction =
      triFSize /
      basis->getNumTriFace(); // number of Tri face functions for one face
  }
  int numQuadFaceFunction = 0;
  if(basis->getNumQuadFace() != 0) {
    numQuadFaceFunction =
      quadFSize /
      basis->getNumQuadFace(); // number of Tri face functions for one face
  }
  int numEdgeFunction = 0;
  if(basis->getNumEdge() != 0) {
    numEdgeFunction =
      eSize / basis->getNumEdge(); // number of edge functions for one edge
  }
  int const1 = numEdgeFunction + 1;
  int const2 = const1 + numQuadFaceFunction;
  int const3 = const1 + numTriFaceFunction;
  int const4 = bSize + std::max(const3, const2);
  delete basis;

  // vertices
  for(int k = 0; k < vSize; k++) {
    keys.push_back(std::pair<int, std::size_t>(0, e->getVertex(k)->getNum()));
    if(generateCoord) {
      coord.push_back(e->getVertex(k)->x());
      coord.push_back(e->getVertex(k)->y());
      coord.push_back(e->getVertex(k)->z());
    }
  }
  // edges
  if(eSize > 0) {
    for(int jj = 0; jj < e->getNumEdges(); jj++) {
      MEdge edge = e->getEdge(jj);
      double coordEdge[3];
      if(generateCoord) {
        MVertex *v1 = edge.getVertex(0);
        MVertex *v2 = edge.getVertex(1);

        coordEdge[0] = 0.5 * (v1->x() + v2->x());
        coordEdge[1] = 0.5 * (v1->y() + v2->y());
        coordEdge[2] = 0.5 * (v1->z() + v2->z());
      }
      int edgeGlobalIndice = GModel::current()->addMEdge(edge);
      for(int k = 1; k < const1; k++) {
        keys.push_back(std::pair<int, std::size_t>(k, edgeGlobalIndice));
        if(generateCoord) {
          coord.push_back(coordEdge[0]);
          coord.push_back(coordEdge[1]);
          coord.push_back(coordEdge[2]);
        }
      }
    }
  }
  // faces
  if(fSize > 0) {
    for(int jj = 0; jj < numberQuadFaces + numberTriFaces; jj++) {
      // Number the faces
      MFace face = e->getFaceSolin(jj);
      double coordFace[3] = {0., 0., 0.};
      if(generateCoord) {
        for(std::size_t indexV = 0; indexV < face.getNumVertices();
            ++indexV) {
          coordFace[0] += face.getVertex(indexV)->x();
          coordFace[1] += face.getVertex(indexV)->y();
          coordFace[2] += face.getVertex(indexV)->z();
        }
        coordFace[0] /= face.getNumVertices();
        coordFace[1] /= face.getNumVertices();
        coordFace[2] /= face.getNumVertices();
      }
      int faceGlobalIndice = GModel::current()->addMFace(face);
      int it2 = const2;
      if(jj >= numberQuadFaces) { it2 = const3; }
      for(int k = const1; k < it2; k++) {
        keys.push_back(std::pair<int, std::size_t>(k, faceGlobalIndice));
        if(generateCoord) {
          coord.push_back(coordFace[0]);
          coord.push_back(coordFace[1]);
          coord.push_back(coordFace[2]);
        }
      }
    }
  }
  // volumes
  if(bSize > 0) {
    double bubbleCenterCoord[3] = {0., 0., 0.};
    if(generateCoord) {
      for(unsigned int indexV = 0; indexV < e->getNumVertices(); ++indexV) {
        bubbleCenterCoord[0] += e->getVertex(indexV)->x();
        bubbleCenterCoord[1] += e->getVertex(indexV)->y();
        bubbleCenterCoord[2] += e->getVertex(indexV)->z();
      }
      bubbleCenterCoord[0] /= e->getNumVertices();
      bubbleCenterCoord[1] /= e->getNumVertices();
      bubbleCenterCoord[2] /= e->getNumVertices();
    }
    for(int k = std::max(const3, const2); k < const4; k++) {
      keys.push_back(std::pair<int, std::size_t>(k, e->getNum()));
      if(generateCoord) {
        coord.push_back(bubbleCenterCoord[0]);
        coord.push_back(bubbleCenterCoord[1]);
        coord.push_back(bubbleCenterCoord[2]);
      }
    }
  }
}

GMSH_API int gmsh::model::mesh::getNumberOfKeysForElements(
  const int elementType, const std::string &functionSpaceType)
{
  int numberOfKeys = 0;
  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }
  int familyType = ElementType::getParentType(elementType);
  if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
    HierarchicalBasis *basis(0);
    switch(familyType) {
    case TYPE_HEX: {
      basis = new HierarchicalBasisH1Brick(basisOrder);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisH1Pri(basisOrder);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisH1Tetra(basisOrder);
    } break;
    case TYPE_QUA: {
      basis = new HierarchicalBasisH1Quad(basisOrder);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisH1Tria(basisOrder);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisH1Line(basisOrder);
    } break;
    case TYPE_PNT: {
      basis = new HierarchicalBasisH1Point();
    } break;
    default: Msg::Error("Unknown familyType "); throw 2;
    }
    int vSize = basis->getnVertexFunction();
    int bSize = basis->getnBubbleFunction();
    int eSize = basis->getnEdgeFunction();
    int quadFSize = basis->getnQuadFaceFunction();
    int triFSize = basis->getnTriFaceFunction();
    numberOfKeys = vSize + bSize + eSize + quadFSize + triFSize;
    delete basis;
  }
  else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre") {
    HierarchicalBasis *basis(0);
    switch(familyType) {
    case TYPE_QUA: {
      basis = new HierarchicalBasisHcurlQuad(basisOrder);
    } break;
    case TYPE_HEX: {
      basis = new HierarchicalBasisHcurlBrick(basisOrder);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisHcurlTria(basisOrder);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisHcurlTetra(basisOrder);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisHcurlPri(basisOrder);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisHcurlLine(basisOrder);
    } break;
    default: Msg::Error("Unknown familyType "); throw 2;
    }
    int vSize = basis->getnVertexFunction();
    int bSize = basis->getnBubbleFunction();
    int eSize = basis->getnEdgeFunction();
    int quadFSize = basis->getnQuadFaceFunction();
    int triFSize = basis->getnTriFaceFunction();
    numberOfKeys = vSize + bSize + eSize + quadFSize + triFSize;
    delete basis;
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    const nodalBasis *basis(0);
    if(basisOrder == -1) { // isoparametric
      basis = BasisFactory::getNodalBasis(elementType);
    }
    else {
      int familyType = ElementType::getParentType(elementType);
      int newType = ElementType::getType(familyType, basisOrder, false);
      basis = BasisFactory::getNodalBasis(newType);
    }
    numberOfKeys = basis->getNumShapeFunctions();
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    throw 3;
  }

  return numberOfKeys;
}

GMSH_API void gmsh::model::mesh::getInformationForElements(
  const gmsh::vectorpair &keys, const int elementType,
  const std::string &functionSpaceType, gmsh::vectorpair &infoKeys)
{
  infoKeys.clear();
  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    throw 2;
  }
  HierarchicalBasis *basis(0);
  int familyType = ElementType::getParentType(elementType);
  if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
    switch(familyType) {
    case TYPE_HEX: {
      basis = new HierarchicalBasisH1Brick(basisOrder);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisH1Pri(basisOrder);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisH1Tetra(basisOrder);
    } break;
    case TYPE_QUA: {
      basis = new HierarchicalBasisH1Quad(basisOrder);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisH1Tria(basisOrder);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisH1Line(basisOrder);
    } break;
    case TYPE_PNT: {
      basis = new HierarchicalBasisH1Point();
    } break;
    default: Msg::Error("Unknown familyType "); throw 3;
    }
  }
  else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre") {
    switch(familyType) {
    case TYPE_QUA: {
      basis = new HierarchicalBasisHcurlQuad(basisOrder);
    } break;
    case TYPE_HEX: {
      basis = new HierarchicalBasisHcurlBrick(basisOrder);
    } break;
    case TYPE_TRI: {
      basis = new HierarchicalBasisHcurlTria(basisOrder);
    } break;
    case TYPE_TET: {
      basis = new HierarchicalBasisHcurlTetra(basisOrder);
    } break;
    case TYPE_PRI: {
      basis = new HierarchicalBasisHcurlPri(basisOrder);
    } break;
    case TYPE_LIN: {
      basis = new HierarchicalBasisHcurlLine(basisOrder);
    } break;
    default: Msg::Error("Unknown familyType "); throw 3;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    const nodalBasis *basis(0);
    if(basisOrder == -1) { // isoparametric
      basis = BasisFactory::getNodalBasis(elementType);
    }
    else {
      int familyType = ElementType::getParentType(elementType);
      int newType = ElementType::getType(familyType, basisOrder, false);
      basis = BasisFactory::getNodalBasis(newType);
    }
    std::size_t numberOfKeys = basis->getNumShapeFunctions();
    std::size_t numberOfBubble = basis->getNumBubbleShapeFunctions();
    int dim = ElementType::getDimension(elementType);

    if(numberOfBubble > numberOfKeys) { throw 4; }

    infoKeys.reserve(keys.size());
    for(size_t i = 0; i < keys.size() / numberOfKeys; ++i) {
      for(size_t j = 0; j < numberOfKeys - numberOfBubble; ++j) {
        infoKeys.push_back(std::pair<int, int>(0, basisOrder));
      }
      for(size_t j = 0; j < numberOfBubble; ++j) {
        infoKeys.push_back(std::pair<int, int>(dim, basisOrder));
      }
    }
    return;
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    throw 5;
  }

  int vSize = basis->getnVertexFunction();
  int bSize = basis->getnBubbleFunction();
  int eSize = basis->getnEdgeFunction();
  int quadFSize = basis->getnQuadFaceFunction();
  int triFSize = basis->getnTriFaceFunction();
  int numDofsPerElement = vSize + bSize + eSize + quadFSize + triFSize;
  std::vector<int> functionTypeInfo(numDofsPerElement);
  std::vector<int> orderInfo(numDofsPerElement);
  basis->getKeysInfo(functionTypeInfo, orderInfo);
  delete basis;
  std::size_t keySize = keys.size();
  infoKeys.resize(keySize);
  std::size_t it = keySize / numDofsPerElement;
  for(std::size_t i = 0; i < it; i++) {
    size_t const1 = i * numDofsPerElement;
    for(int j = 0; j < numDofsPerElement; j++) {
      infoKeys[const1 + j] =
        std::pair<int, int>(functionTypeInfo[j], orderInfo[j]);
    }
  }
}

GMSH_API void gmsh::model::mesh::getBarycenters(
  const int elementType, const int tag, const bool fast, const bool primary,
  std::vector<double> &barycenters, const std::size_t task,
  const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    numElements += ge->getNumMeshElementsByType(familyType);
  }
  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    throw 4;
  }
  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
  if(3 * end > barycenters.size()) {
    if(numTasks > 1)
      Msg::Warning("Barycenters should be preallocated if numTasks > 1");
    barycenters.resize(3 * numElements);
  }
  size_t o = 0;
  size_t idx = 3 * begin;
  if(fast) {
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
          j++) {
        if(o >= begin && o < end) {
          MElement *e = ge->getMeshElementByType(familyType, j);
          SPoint3 p = e->fastBarycenter(primary);
          barycenters[idx++] = p[0];
          barycenters[idx++] = p[1];
          barycenters[idx++] = p[2];
        }
        o++;
      }
    }
  }
  else {
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType);
          j++) {
        if(o >= begin && o < end) {
          MElement *e = ge->getMeshElementByType(familyType, j);
          SPoint3 p = e->barycenter(primary);
          barycenters[idx++] = p[0];
          barycenters[idx++] = p[1];
          barycenters[idx++] = p[2];
        }
        o++;
      }
    }
  }
}

static bool _getIntegrationInfo(const std::string &intType,
                                std::string &intName, int &intOrder)
{
  if(intType.substr(0, 5) == "Gauss") {
    intName = "Gauss";
    intOrder = atoi(intType.substr(5).c_str());
    return true;
  }
  return false;
}

GMSH_API void gmsh::model::mesh::getIntegrationPoints(
  const int elementType, const std::string &integrationType,
  std::vector<double> &localCoord, std::vector<double> &weigths)
{
  if(!_isInitialized()) { throw -1; }
  localCoord.clear();
  weigths.clear();
  std::string intName = "";
  int intOrder = 0;
  if(!_getIntegrationInfo(integrationType, intName, intOrder)) {
    Msg::Error("Unknown quadrature type '%s'", integrationType.c_str());
    throw 2;
  }
  // get quadrature info
  int familyType = ElementType::getParentType(elementType);
  fullMatrix<double> pts;
  fullVector<double> weights;
  gaussIntegration::get(familyType, intOrder, pts, weights);
  if(pts.size1() != weights.size() || pts.size2() != 3) {
    Msg::Error("Wrong integration point format");
    throw 3;
  }
  localCoord.resize(3 * pts.size1());
  weigths.resize(pts.size1());
  for(int i = 0; i < pts.size1(); i++) {
    localCoord[3 * i] = pts(i, 0);
    localCoord[3 * i + 1] = pts(i, 1);
    localCoord[3 * i + 2] = pts(i, 2);
    weigths[i] = weights(i);
  }
}

GMSH_API void gmsh::model::mesh::preallocateBarycenters(
  const int elementType, std::vector<double> &barycenters, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += entities[i]->getNumMeshElementsByType(familyType);
  barycenters.clear();
  barycenters.resize(3 * numElements, 0);
}

GMSH_API void gmsh::model::mesh::getElementEdgeNodes(
  const int elementType, std::vector<std::size_t> &nodeTags, const int tag,
  const bool primary, const std::size_t task, const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  int numEdgesPerEle = 0, numNodesPerEdge = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    int n = ge->getNumMeshElementsByType(familyType);
    if(n && !numNodesPerEdge) {
      MElement *e = ge->getMeshElementByType(familyType, i);
      numEdgesPerEle = e->getNumEdges();
      if(primary) { numNodesPerEdge = 2; }
      else {
        std::vector<MVertex *> v;
        // we could use e->getHighOrderEdge() here if we decide to remove
        // getEdgeVertices
        e->getEdgeVertices(0, v);
        numNodesPerEdge = v.size();
      }
    }
    numElements += n;
  }
  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    throw 4;
  }
  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
  if(numEdgesPerEle * numNodesPerEdge * end > nodeTags.size()) {
    if(numTasks > 1)
      Msg::Warning("Nodes should be preallocated if numTasks > 1");
    nodeTags.resize(numEdgesPerEle * numNodesPerEdge * numElements);
  }
  size_t o = 0;
  size_t idx = numEdgesPerEle * numNodesPerEdge * begin;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType); j++) {
      if(o >= begin && o < end) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        for(int k = 0; k < numEdgesPerEle; k++) {
          std::vector<MVertex *> v;
          // we could use e->getHighOrderEdge() here if we decide to remove
          // getEdgeVertices
          e->getEdgeVertices(k, v);
          std::size_t N = primary ? 2 : v.size();
          for(std::size_t l = 0; l < N; l++) {
            nodeTags[idx++] = v[l]->getNum();
          }
        }
      }
      o++;
    }
  }
}

GMSH_API void gmsh::model::mesh::getElementFaceNodes(
  const int elementType, const int faceType, std::vector<std::size_t> &nodeTags,
  const int tag, const bool primary, const std::size_t task,
  const std::size_t numTasks)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  int numFacesPerEle = 0, numNodesPerFace = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    int n = ge->getNumMeshElementsByType(familyType);
    if(n && !numNodesPerFace) {
      MElement *e = ge->getMeshElementByType(familyType, i);
      int nf = e->getNumFaces();
      numFacesPerEle = 0;
      for(int j = 0; j < nf; j++) {
        MFace f = e->getFace(j);
        if(faceType == (int)f.getNumVertices()) numFacesPerEle++;
      }
      if(primary) { numNodesPerFace = faceType; }
      else {
        std::vector<MVertex *> v;
        // we could use e->getHighOrderFace() here if we decide to remove
        // getFaceVertices
        e->getFaceVertices(0, v);
        numNodesPerFace = v.size();
      }
    }
    numElements += n;
  }
  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    throw 4;
  }
  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
  if(numFacesPerEle * numNodesPerFace * end > nodeTags.size()) {
    if(numTasks > 1)
      Msg::Warning("Nodes should be preallocated if numTasks > 1");
    nodeTags.resize(numFacesPerEle * numNodesPerFace * numElements);
  }
  size_t o = 0;
  size_t idx = numFacesPerEle * numNodesPerFace * begin;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType); j++) {
      if(o >= begin && o < end) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        int nf = e->getNumFaces();
        for(int k = 0; k < nf; k++) {
          MFace f = e->getFace(k);
          if(faceType != (int)f.getNumVertices()) continue;
          std::vector<MVertex *> v;
          // we could use e->getHighOrderFace() here if we decide to remove
          // getFaceVertices
          e->getFaceVertices(k, v);
          std::size_t N = primary ? faceType : v.size();
          for(std::size_t l = 0; l < N; l++) {
            nodeTags[idx++] = v[l]->getNum();
          }
        }
      }
      o++;
    }
  }
}

GMSH_API void
gmsh::model::mesh::getGhostElements(const int dim, const int tag,
                                    std::vector<std::size_t> &elementTags,
                                    std::vector<int> &partitions)
{
  if(!_isInitialized()) { throw -1; }
  elementTags.clear();
  partitions.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  std::map<MElement *, int> ghostCells;
  if(ge->geomType() == GEntity::GhostCurve)
    ghostCells = static_cast<ghostEdge *>(ge)->getGhostCells();
  else if(ge->geomType() == GEntity::GhostSurface)
    ghostCells = static_cast<ghostFace *>(ge)->getGhostCells();
  else if(ge->geomType() == GEntity::GhostVolume)
    ghostCells = static_cast<ghostRegion *>(ge)->getGhostCells();

  for(std::map<MElement *, int>::const_iterator it = ghostCells.begin();
      it != ghostCells.end(); it++) {
    elementTags.push_back(it->first->getNum());
    partitions.push_back(it->second);
  }
}

GMSH_API void gmsh::model::mesh::setSize(const vectorpair &dimTags,
                                         const double size)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 0) {
      GVertex *gv = GModel::current()->getVertexByTag(tag);
      if(gv) gv->setPrescribedMeshSizeAtVertex(size);
    }
  }
}

GMSH_API void gmsh::model::mesh::setSizeAtParametricPoints(
  const int dim, const int tag, const std::vector<double> &parametricCoord,
  const std::vector<double> &sizes)
{
  if(!_isInitialized()) { throw -1; }
  if(dim == 1) {
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(ge) ge->setMeshSizeParametric(parametricCoord, sizes);
  }
}

GMSH_API void
gmsh::model::mesh::setTransfiniteCurve(const int tag, const int numNodes,
                                       const std::string &meshType,
                                       const double coef)
{
  if(!_isInitialized()) { throw -1; }
  GEdge *ge = GModel::current()->getEdgeByTag(tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(1, tag).c_str());
    throw 2;
  }
  ge->meshAttributes.method = MESH_TRANSFINITE;
  ge->meshAttributes.nbPointsTransfinite = numNodes;
  ge->meshAttributes.typeTransfinite =
    (meshType == "Progression" || meshType == "Power") ?
      1 :
      (meshType == "Bump") ? 2 : 1;
  ge->meshAttributes.coeffTransfinite = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) ge->meshAttributes.typeTransfinite *= -1;
}

GMSH_API void
gmsh::model::mesh::setTransfiniteSurface(const int tag,
                                         const std::string &arrangement,
                                         const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) { throw -1; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.method = MESH_TRANSFINITE;
  gf->meshAttributes.transfiniteArrangement =
    (arrangement == "Right") ?
      1 :
      (arrangement == "Left") ?
      -1 :
      (arrangement == "AlternateRight") ?
      2 :
      (arrangement == "AlternateLeft") ? -2 :
                                         (arrangement == "Alternate") ? 2 : -1;
  if(cornerTags.empty() || cornerTags.size() == 3 || cornerTags.size() == 4) {
    for(std::size_t j = 0; j < cornerTags.size(); j++) {
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[j]);
      if(gv) gf->meshAttributes.corners.push_back(gv);
    }
  }
}

GMSH_API void
gmsh::model::mesh::setTransfiniteVolume(const int tag,
                                        const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) { throw -1; }
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr) {
    Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
    throw 2;
  }
  gr->meshAttributes.method = MESH_TRANSFINITE;
  if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8) {
    for(std::size_t i = 0; i < cornerTags.size(); i++) {
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[i]);
      if(gv) gr->meshAttributes.corners.push_back(gv);
    }
  }
}

GMSH_API void gmsh::model::mesh::setRecombine(const int dim, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  if(dim != 2) { throw 2; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.recombine = 1;
  gf->meshAttributes.recombineAngle = 45.;
}

GMSH_API void gmsh::model::mesh::setSmoothing(const int dim, const int tag,
                                              const int val)
{
  if(!_isInitialized()) { throw -1; }
  if(dim != 2) { throw 2; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.transfiniteSmoothing = val;
}

GMSH_API void gmsh::model::mesh::setReverse(const int dim, const int tag,
                                            const bool val)
{
  if(!_isInitialized()) { throw -1; }
  if(dim == 1) {
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    ge->meshAttributes.reverseMesh = val;
  }
  else if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    gf->meshAttributes.reverseMesh = val;
  }
}

GMSH_API void gmsh::model::mesh::setAlgorithm(const int dim, const int tag,
                                              const int val)
{
  if(!_isInitialized()) { throw -1; }
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    gf->meshAttributes.algorithm = val;
  }
}

GMSH_API void gmsh::model::mesh::setSizeFromBoundary(const int dim,
                                                     const int tag,
                                                     const int val)
{
  if(!_isInitialized()) { throw -1; }
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      throw 2;
    }
    gf->meshAttributes.meshSizeFromBoundary = val;
  }
}

GMSH_API void gmsh::model::mesh::setCompound(const int dim,
                                             const std::vector<int> &tags)
{
  if(!_isInitialized()) { throw -1; }
  std::vector<GEntity *> ents;
  for(std::size_t i = 0; i < tags.size(); i++) {
    GEntity *ent = GModel::current()->getEntityByTag(dim, tags[i]);
    if(ent) { ents.push_back(ent); }
    else {
      Msg::Error("%s does not exist", _getEntityName(dim, tags[i]).c_str());
    }
  }
  for(std::size_t i = 0; i < ents.size(); i++) { ents[i]->compound = ents; }
}

GMSH_API void gmsh::model::mesh::setOutwardOrientation(const int tag)
{
  if(!_isInitialized()) { throw -1; }
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr) {
    Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
    throw 2;
  }
  gr->setOutwardOrientationMeshConstraint();
}

GMSH_API void gmsh::model::mesh::embed(const int dim,
                                       const std::vector<int> &tags,
                                       const int inDim, const int inTag)
{
  if(!_isInitialized()) { throw -1; }
  if(inDim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(inTag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(2, inTag).c_str());
      throw 2;
    }
    for(std::size_t i = 0; i < tags.size(); i++) {
      if(dim == 0) {
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv) {
          Msg::Error("%s does not exist", _getEntityName(0, tags[i]).c_str());
          throw 2;
        }
        gf->addEmbeddedVertex(gv);
      }
      else if(dim == 1) {
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge) {
          Msg::Error("%s does not exist", _getEntityName(1, tags[i]).c_str());
          throw 2;
        }
        gf->addEmbeddedEdge(ge);
      }
    }
  }
  else if(inDim == 3) {
    GRegion *gr = GModel::current()->getRegionByTag(inTag);
    if(!gr) {
      Msg::Error("%s does not exist", _getEntityName(3, inTag).c_str());
      throw 2;
    }
    for(std::size_t i = 0; i < tags.size(); i++) {
      if(dim == 0) {
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv) {
          Msg::Error("%s does not exist", _getEntityName(0, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedVertex(gv);
      }
      else if(dim == 1) {
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge) {
          Msg::Error("%s does not exist", _getEntityName(1, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedEdge(ge);
      }
      else if(dim == 2) {
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(!gf) {
          Msg::Error("%s does not exist", _getEntityName(2, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedFace(gf);
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::removeEmbedded(const vectorpair &dimTags,
                                                const int rdim)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 2) {
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(!gf) {
        Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
        throw 2;
      }
      if(rdim < 0 || rdim == 1) gf->embeddedEdges().clear();
      if(rdim < 0 || rdim == 0) gf->embeddedVertices().clear();
    }
    else if(dimTags[i].first == 3) {
      GRegion *gr = GModel::current()->getRegionByTag(tag);
      if(!gr) {
        Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
        throw 2;
      }
      if(rdim < 0 || rdim == 2) gr->embeddedFaces().clear();
      if(rdim < 0 || rdim == 1) gr->embeddedEdges().clear();
      if(rdim < 0 || rdim == 0) gr->embeddedVertices().clear();
    }
  }
}

GMSH_API void
gmsh::model::mesh::reorderElements(const int elementType, const int tag,
                                   const std::vector<std::size_t> &ordering)
{
  if(!_isInitialized()) { throw -1; }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  if(entities.empty()) {
    Msg::Error("No elements to reorder");
    throw 2;
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(!entities[i]->reorder(elementType, ordering)) {
      Msg::Error("Could not reorder elements");
      throw 3;
    }
  }
}

GMSH_API void gmsh::model::mesh::renumberNodes()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->renumberMeshVertices();
}

GMSH_API void gmsh::model::mesh::renumberElements()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->renumberMeshElements();
}

GMSH_API void
gmsh::model::mesh::setPeriodic(const int dim, const std::vector<int> &tags,
                               const std::vector<int> &tagsMaster,
                               const std::vector<double> &affineTransform)
{
  if(!_isInitialized()) { throw -1; }
  if(tags.size() != tagsMaster.size()) {
    Msg::Error("Incompatible number of tags and master tags for periodic mesh");
    throw 2;
  }
  if(affineTransform.size() != 16) {
    Msg::Error("Wrong number of elements in affine transformation (%d != 16)",
               (int)affineTransform.size());
    throw 2;
  }
  for(std::size_t i = 0; i < tags.size(); i++) {
    if(dim == 1) {
      GEdge *target = GModel::current()->getEdgeByTag(tags[i]);
      if(!target) {
        Msg::Error("%s does not exist", _getEntityName(dim, tags[i]).c_str());
        throw 2;
      }
      GEdge *source = GModel::current()->getEdgeByTag(tagsMaster[i]);
      if(!source) {
        Msg::Error("%s does not exist",
                   _getEntityName(dim, tagsMaster[i]).c_str());
        throw 2;
      }
      target->setMeshMaster(source, affineTransform);
    }
    else if(dim == 2) {
      GFace *target = GModel::current()->getFaceByTag(tags[i]);
      if(!target) {
        Msg::Error("%s does not exist", _getEntityName(dim, tags[i]).c_str());
        throw 2;
      }
      GFace *source = GModel::current()->getFaceByTag(tagsMaster[i]);
      if(!source) {
        Msg::Error("%s does not exist",
                   _getEntityName(dim, tagsMaster[i]).c_str());
        throw 2;
      }
      target->setMeshMaster(source, affineTransform);
    }
  }
}

GMSH_API void gmsh::model::mesh::getPeriodicNodes(
  const int dim, const int tag, int &tagMaster,
  std::vector<std::size_t> &nodeTags, std::vector<std::size_t> &nodeTagsMaster,
  std::vector<double> &affineTransform, const bool includeHighOrderNodes)
{
  if(!_isInitialized()) { throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    throw 2;
  }
  if(ge->getMeshMaster() != ge) {
    tagMaster = ge->getMeshMaster()->tag();
    for(std::map<MVertex *, MVertex *>::iterator it =
          ge->correspondingVertices.begin();
        it != ge->correspondingVertices.end(); ++it) {
      nodeTags.push_back(it->first->getNum());
      nodeTagsMaster.push_back(it->second->getNum());
    }
    if(includeHighOrderNodes) {
      for(std::map<MVertex *, MVertex *>::iterator it =
            ge->correspondingHighOrderVertices.begin();
          it != ge->correspondingHighOrderVertices.end(); ++it) {
        nodeTags.push_back(it->first->getNum());
        nodeTagsMaster.push_back(it->second->getNum());
      }
    }
    affineTransform = ge->affineTransform;
  }
  else {
    tagMaster = tag;
    nodeTags.clear();
    nodeTagsMaster.clear();
    affineTransform.clear();
  }
}

GMSH_API void gmsh::model::mesh::removeDuplicateNodes()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->removeDuplicateMeshVertices(
    CTX::instance()->geom.tolerance);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void
gmsh::model::mesh::classifySurfaces(const double angle, const bool boundary,
                                    const bool forReparametrization,
                                    const double curveAngle)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->classifySurfaces(angle, boundary, forReparametrization,
                                      curveAngle);
}

GMSH_API void gmsh::model::mesh::createGeometry(const vectorpair &dimTags)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->createGeometryOfDiscreteEntities(dimTags);
}

GMSH_API void gmsh::model::mesh::createTopology(const bool makeSimplyConnected,
                                                const bool exportDiscrete)
{
  if(!_isInitialized()) { throw -1; }

  if(makeSimplyConnected) {
    GModel::current()->makeDiscreteRegionsSimplyConnected();
    GModel::current()->makeDiscreteFacesSimplyConnected();
  }
  GModel::current()->createTopologyFromMesh();
  if(exportDiscrete) {
    // Warning: this clears GEO_Internals!
    GModel::current()->exportDiscreteGEOInternals();
  }
}

GMSH_API void
gmsh::model::mesh::computeHomology(const std::vector<int> &domainTags,
                                   const std::vector<int> &subdomainTags,
                                   const std::vector<int> &dims)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->addHomologyRequest("Homology", domainTags, subdomainTags,
                                        dims);
}

GMSH_API void
gmsh::model::mesh::computeCohomology(const std::vector<int> &domainTags,
                                     const std::vector<int> &subdomainTags,
                                     const std::vector<int> &dims)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->addHomologyRequest("Cohomology", domainTags, subdomainTags,
                                        dims);
}

// gmsh::model::mesh::field

GMSH_API int gmsh::model::mesh::field::add(const std::string &fieldType,
                                           const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
#if defined(HAVE_MESH)
  if(outTag < 0) { outTag = GModel::current()->getFields()->newId(); }
  if(!GModel::current()->getFields()->newField(outTag, fieldType)) {
    Msg::Error("Cannot add Field %i of type '%s'", outTag, fieldType.c_str());
    throw 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateFields();
#endif
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
  return outTag;
}

GMSH_API void gmsh::model::mesh::field::remove(const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->deleteField(tag);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateFields();
#endif
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

#if defined(HAVE_MESH)
static FieldOption *_getFieldOption(const int tag, const std::string &option)
{
  Field *field = GModel::current()->getFields()->get(tag);
  if(!field) {
    Msg::Error("No field with id %i", tag);
    return 0;
  }
  FieldOption *o = field->options[option];
  if(!o) {
    Msg::Error("Unknown option '%s' in field %i of type '%s'", option.c_str(),
               tag, field->getName());
    return 0;
  }
  return o;
}
#endif

GMSH_API void gmsh::model::mesh::field::setNumber(const int tag,
                                                  const std::string &option,
                                                  const double value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { throw 1; }
  try {
    o->numericalValue(value);
  } catch(...) {
    Msg::Error("Cannot set numerical value to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

GMSH_API void gmsh::model::mesh::field::setString(const int tag,
                                                  const std::string &option,
                                                  const std::string &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { throw 1; }
  try {
    o->string(value);
  } catch(...) {
    Msg::Error("Cannot set string value to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

GMSH_API void
gmsh::model::mesh::field::setNumbers(const int tag, const std::string &option,
                                     const std::vector<double> &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { throw 1; }
  try {
    if(o->getType() == FIELD_OPTION_LIST) {
      std::list<int> vl;
      for(std::size_t i = 0; i < value.size(); i++) vl.push_back((int)value[i]);
      o->list(vl);
    }
    else {
      std::list<double> vl;
      for(std::size_t i = 0; i < value.size(); i++) vl.push_back(value[i]);
      o->listdouble(vl);
    }
  } catch(...) {
    Msg::Error("Cannot set numeric values to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

GMSH_API void gmsh::model::mesh::field::setAsBackgroundMesh(const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

GMSH_API void gmsh::model::mesh::field::setAsBoundaryLayer(const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->addBoundaryLayerFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

// gmsh::model::geo

GMSH_API int gmsh::model::geo::addPoint(const double x, const double y,
                                        const double z, const double meshSize,
                                        const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  if(!GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, zz, lc)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addLine(const int startTag, const int endTag,
                                       const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addCircleArc(const int startTag,
                                            const int centerTag,
                                            const int endTag, const int tag,
                                            const double nx, const double ny,
                                            const double nz)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addCircleArc(
       outTag, startTag, centerTag, endTag, nx, ny, nz)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addEllipseArc(
  const int startTag, const int centerTag, const int majorTag, const int endTag,
  const int tag, const double nx, const double ny, const double nz)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addEllipseArc(
       outTag, startTag, centerTag, majorTag, endTag, nx, ny, nz)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addSpline(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSpline(outTag, pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addBSpline(const std::vector<int> &pointTags,
                                          const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBSpline(outTag, pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addBezier(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBezier(outTag, pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::geo::addCompoundSpline(const std::vector<int> &curveTags,
                                    const int numIntervals, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addCompoundSpline(outTag, curveTags,
                                                              numIntervals)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::geo::addCompoundBSpline(const std::vector<int> &curveTags,
                                     const int numIntervals, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addCompoundBSpline(
       outTag, curveTags, numIntervals)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addCurveLoop(const std::vector<int> &curveTags,
                                            const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLineLoop(outTag, curveTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addPlaneSurface(const std::vector<int> &wireTags,
                                               const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::geo::addSurfaceFilling(const std::vector<int> &wireTags,
                                    const int tag, const int sphereCenterTag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSurfaceFilling(
       outTag, wireTags, sphereCenterTag)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::geo::addSurfaceLoop(const std::vector<int> &surfaceTags,
                                 const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSurfaceLoop(outTag,
                                                           surfaceTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::geo::addVolume(const std::vector<int> &shellTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addVolume(outTag, shellTags)) {
    throw 1;
  }
  return outTag;
}

static ExtrudeParams *_getExtrudeParams(const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  ExtrudeParams *e = 0;
  if(numElements.size()) {
    e = new ExtrudeParams();
    e->mesh.ExtrudeMesh = true;
    e->mesh.NbElmLayer = numElements;
    e->mesh.hLayer = heights;
    if(e->mesh.hLayer.empty()) {
      e->mesh.NbLayer = 1;
      e->mesh.hLayer.push_back(1.);
    }
    else {
      e->mesh.NbLayer = heights.size();
    }
    e->mesh.Recombine = recombine;
  }
  return e;
}

GMSH_API void gmsh::model::geo::extrude(const vectorpair &dimTags,
                                        const double dx, const double dy,
                                        const double dz, vectorpair &outDimTags,
                                        const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  if(!_isInitialized()) { throw -1; }
  outDimTags.clear();
  if(dx || dy || dz) {
    if(!GModel::current()->getGEOInternals()->extrude(
         dimTags, dx, dy, dz, outDimTags,
         _getExtrudeParams(numElements, heights, recombine))) {
      throw 1;
    }
  }
  else {
    if(!GModel::current()->getGEOInternals()->boundaryLayer(
         dimTags, outDimTags,
         _getExtrudeParams(numElements, heights, recombine))) {
      throw 1;
    }
  }
}

GMSH_API void gmsh::model::geo::revolve(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double ax, const double ay, const double az, const double angle,
  vectorpair &outDimTags, const std::vector<int> &numElements,
  const std::vector<double> &heights, const bool recombine)
{
  if(!_isInitialized()) { throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->revolve(
       dimTags, x, y, z, ax, ay, az, angle, outDimTags,
       _getExtrudeParams(numElements, heights, recombine))) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::twist(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double dx, const double dy, const double dz, const double ax,
  const double ay, const double az, const double angle, vectorpair &outDimTags,
  const std::vector<int> &numElements, const std::vector<double> &heights,
  const bool recombine)
{
  if(!_isInitialized()) { throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->twist(
       dimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags,
       _getExtrudeParams(numElements, heights, recombine))) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::translate(const vectorpair &dimTags,
                                          const double dx, const double dy,
                                          const double dz)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::rotate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double ax,
                                       const double ay, const double az,
                                       const double angle)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->rotate(dimTags, x, y, z, ax, ay, az,
                                                   angle)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::dilate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double a,
                                       const double b, const double c)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->dilate(dimTags, x, y, z, a, b, c)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::mirror(const vectorpair &dimTags,
                                       const double a, const double b,
                                       const double c, const double d)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->symmetry(dimTags, a, b, c, d)) {
    throw 1;
  }
}

// will be deprecated
GMSH_API void gmsh::model::geo::symmetrize(const vectorpair &dimTags,
                                           const double a, const double b,
                                           const double c, const double d)
{
  gmsh::model::geo::mirror(dimTags, a, b, c, d);
}

GMSH_API void gmsh::model::geo::copy(const vectorpair &dimTags,
                                     vectorpair &outDimTags)
{
  if(!_isInitialized()) { throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->copy(dimTags, outDimTags)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::remove(const vectorpair &dimTags,
                                       const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->remove(dimTags, recursive)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::geo::removeAllDuplicates()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->removeAllDuplicates();
}

GMSH_API void gmsh::model::geo::splitCurve(const int tag,
                                           const std::vector<int> &pointTags,
                                           std::vector<int> &curveTags)
{
  if(!_isInitialized()) { throw -1; }
  if(!GModel::current()->getGEOInternals()->splitCurve(tag, pointTags,
                                                       curveTags)) {
    throw 1;
  }
}

GMSH_API int gmsh::model::geo::getMaxTag(const int dim)
{
  if(!_isInitialized()) { throw -1; }
  return GModel::current()->getGEOInternals()->getMaxTag(dim);
}

GMSH_API void gmsh::model::geo::setMaxTag(const int dim, const int maxTag)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setMaxTag(dim, maxTag);
}

GMSH_API void gmsh::model::geo::synchronize()
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
}

// gmsh::model::geo::mesh

GMSH_API void
gmsh::model::geo::mesh::setTransfiniteCurve(const int tag, const int nPoints,
                                            const std::string &meshType,
                                            const double coef)
{
  if(!_isInitialized()) { throw -1; }
  int t = (meshType == "Progression" || meshType == "Power") ?
            1 :
            (meshType == "Bump") ? 2 : 1;
  double c = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) t = -t;
  GModel::current()->getGEOInternals()->setTransfiniteLine(tag, nPoints, t, c);
}

GMSH_API void gmsh::model::geo::mesh::setTransfiniteSurface(
  const int tag, const std::string &arrangement,
  const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) { throw -1; }
  int t = (arrangement == "Right") ?
            1 :
            (arrangement == "Left") ? -1 :
                                      (arrangement == "AlternateRight") ?
                                      2 :
                                      (arrangement == "AlternateLeft") ?
                                      -2 :
                                      (arrangement == "Alternate") ? 2 : -1;
  GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, t,
                                                              cornerTags);
}

GMSH_API void
gmsh::model::geo::mesh::setTransfiniteVolume(const int tag,
                                             const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, cornerTags);
}

GMSH_API void gmsh::model::geo::mesh::setRecombine(const int dim, const int tag,
                                                   const double angle)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setRecombine(dim, tag, angle);
}

GMSH_API void gmsh::model::geo::mesh::setSmoothing(const int dim, const int tag,
                                                   const int val)
{
  if(!_isInitialized()) { throw -1; }
  if(dim != 2) { throw 2; }
  GModel::current()->getGEOInternals()->setSmoothing(tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setReverse(const int dim, const int tag,
                                                 const bool val)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setReverseMesh(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setAlgorithm(const int dim, const int tag,
                                                   const int val)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setMeshAlgorithm(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setSizeFromBoundary(const int dim,
                                                          const int tag,
                                                          const int val)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getGEOInternals()->setMeshSizeFromBoundary(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setSize(const vectorpair &dimTags,
                                              const double size)
{
  if(!_isInitialized()) { throw -1; }
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getGEOInternals()->setMeshSize(dim, tag, size);
  }
}

// gmsh::model::occ

static void _createOcc()
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
}

GMSH_API int gmsh::model::occ::addPoint(const double x, const double y,
                                        const double z, const double meshSize,
                                        const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addVertex(outTag, x, y, z,
                                                      meshSize)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addLine(const int startTag, const int endTag,
                                       const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addCircleArc(const int startTag,
                                            const int centerTag,
                                            const int endTag, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCircleArc(outTag, startTag,
                                                         centerTag, endTag)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addCircle(const double x, const double y,
                                         const double z, const double r,
                                         const int tag, const double angle1,
                                         const double angle2)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCircle(outTag, x, y, z, r,
                                                      angle1, angle2)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addEllipseArc(const int startTag,
                                             const int centerTag,
                                             const int majorTag,
                                             const int endTag, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addEllipseArc(
       outTag, startTag, centerTag, majorTag, endTag)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addEllipse(const double x, const double y,
                                          const double z, const double r1,
                                          const double r2, const int tag,
                                          const double angle1,
                                          const double angle2)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addEllipse(outTag, x, y, z, r1, r2,
                                                       angle1, angle2)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addSpline(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSpline(outTag, pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addBSpline(
  const std::vector<int> &pointTags, const int tag, const int degree,
  const std::vector<double> &weights, const std::vector<double> &knots,
  const std::vector<int> &multiplicities)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBSpline(
       outTag, pointTags, degree, weights, knots, multiplicities)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addBezier(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBezier(outTag, pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addWire(const std::vector<int> &curveTags,
                                       const int tag, const bool checkClosed)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addWire(outTag, curveTags,
                                                    checkClosed)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addCurveLoop(const std::vector<int> &curveTags,
                                            const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLineLoop(outTag, curveTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addRectangle(const double x, const double y,
                                            const double z, const double dx,
                                            const double dy, const int tag,
                                            const double roundedRadius)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addRectangle(outTag, x, y, z, dx,
                                                         dy, roundedRadius)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addDisk(const double xc, const double yc,
                                       const double zc, const double rx,
                                       const double ry, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addDisk(outTag, xc, yc, zc, rx,
                                                    ry)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addPlaneSurface(const std::vector<int> &wireTags,
                                               const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::occ::addSurfaceFilling(const int wireTag, const int tag,
                                    const std::vector<int> &pointTags)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceFilling(outTag, wireTag,
                                                              pointTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::occ::addBSplineFilling(const int wireTag, const int tag,
                                    const std::string &type)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBSplineFilling(outTag, wireTag,
                                                              type)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::occ::addBezierFilling(const int wireTag, const int tag,
                                   const std::string &type)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBezierFilling(outTag, wireTag,
                                                             type)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addBSplineSurface(
  const std::vector<int> &pointTags, const int numPointsU, const int tag,
  const int degreeU, const int degreeV, const std::vector<double> &weights,
  const std::vector<double> &knotsU, const std::vector<double> &knotsV,
  const std::vector<int> &multiplicitiesU, const std::vector<int> &multiplicitiesV)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBSplineSurface(
       outTag, pointTags, numPointsU, degreeU, degreeV, weights, knotsU, knotsV,
       multiplicitiesU, multiplicitiesV)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addBezierSurface(
  const std::vector<int> &pointTags, const int numPointsU, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBezierSurface(
       outTag, pointTags, numPointsU)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int
gmsh::model::occ::addSurfaceLoop(const std::vector<int> &surfaceTags,
                                 const int tag, const bool sewing)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, surfaceTags,
                                                           sewing)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addVolume(const std::vector<int> &shellTags,
                                         const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addVolume(outTag, shellTags)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addSphere(const double xc, const double yc,
                                         const double zc, const double radius,
                                         const int tag, const double angle1,
                                         const double angle2,
                                         const double angle3)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSphere(
       outTag, xc, yc, zc, radius, angle1, angle2, angle3)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addBox(const double x, const double y,
                                      const double z, const double dx,
                                      const double dy, const double dz,
                                      const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBox(outTag, x, y, z, dx, dy,
                                                   dz)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addCylinder(const double x, const double y,
                                           const double z, const double dx,
                                           const double dy, const double dz,
                                           const double r, const int tag,
                                           const double angle)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCylinder(outTag, x, y, z, dx, dy,
                                                        dz, r, angle)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addCone(const double x, const double y,
                                       const double z, const double dx,
                                       const double dy, const double dz,
                                       const double r1, const double r2,
                                       const int tag, const double angle)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCone(outTag, x, y, z, dx, dy, dz,
                                                    r1, r2, angle)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addWedge(const double x, const double y,
                                        const double z, const double dx,
                                        const double dy, const double dz,
                                        const int tag, const double ltx)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addWedge(outTag, x, y, z, dx, dy,
                                                     dz, ltx)) {
    throw 1;
  }
  return outTag;
}

GMSH_API int gmsh::model::occ::addTorus(const double x, const double y,
                                        const double z, const double r1,
                                        const double r2, const int tag,
                                        const double angle)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addTorus(outTag, x, y, z, r1, r2,
                                                     angle)) {
    throw 1;
  }
  return outTag;
}

GMSH_API void gmsh::model::occ::addThruSections(
  const std::vector<int> &wireTags, vectorpair &outDimTags, const int tag,
  const bool makeSolid, const bool makeRuled, const int maxDegree)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThruSections(
       tag, wireTags, makeSolid, makeRuled, outDimTags, maxDegree)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::addThickSolid(
  const int volumeTag, const std::vector<int> &excludeSurfaceTags,
  const double offset, vectorpair &outDimTags, const int tag)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThickSolid(
       tag, volumeTag, excludeSurfaceTags, offset, outDimTags)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::extrude(const vectorpair &dimTags,
                                        const double dx, const double dy,
                                        const double dz, vectorpair &outDimTags,
                                        const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->extrude(
       dimTags, dx, dy, dz, outDimTags,
       _getExtrudeParams(numElements, heights, recombine))) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::revolve(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double ax, const double ay, const double az, const double angle,
  vectorpair &outDimTags, const std::vector<int> &numElements,
  const std::vector<double> &heights, const bool recombine)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->revolve(
       dimTags, x, y, z, ax, ay, az, angle, outDimTags,
       _getExtrudeParams(numElements, heights, recombine))) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::addPipe(const vectorpair &dimTags,
                                        const int wireTag,
                                        vectorpair &outDimTags)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addPipe(dimTags, wireTag,
                                                    outDimTags)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::fillet(const std::vector<int> &volumeTags,
                                       const std::vector<int> &curveTags,
                                       const std::vector<double> &radii,
                                       vectorpair &outDimTags,
                                       const bool removeVolume)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->fillet(volumeTags, curveTags, radii,
                                                   outDimTags, removeVolume)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::chamfer(const std::vector<int> &volumeTags,
                                        const std::vector<int> &curveTags,
                                        const std::vector<int> &surfaceTags,
                                        const std::vector<double> &distances,
                                        vectorpair &outDimTags,
                                        const bool removeVolume)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->chamfer(volumeTags, curveTags,
                                                    surfaceTags, distances,
                                                    outDimTags, removeVolume)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::fuse(const vectorpair &objectDimTags,
                                     const vectorpair &toolDimTags,
                                     vectorpair &outDimTags,
                                     std::vector<vectorpair> &outDimTagsMap,
                                     const int tag, const bool removeObject,
                                     const bool removeTool)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanUnion(
       tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
       removeTool)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::intersect(
  const vectorpair &objectDimTags, const vectorpair &toolDimTags,
  vectorpair &outDimTags, std::vector<vectorpair> &outDimTagsMap, const int tag,
  const bool removeObject, const bool removeTool)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanIntersection(
       tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
       removeTool)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::cut(const vectorpair &objectDimTags,
                                    const vectorpair &toolDimTags,
                                    vectorpair &outDimTags,
                                    std::vector<vectorpair> &outDimTagsMap,
                                    const int tag, const bool removeObject,
                                    const bool removeTool)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanDifference(
       tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
       removeTool)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::fragment(const vectorpair &objectDimTags,
                                         const vectorpair &toolDimTags,
                                         vectorpair &outDimTags,
                                         std::vector<vectorpair> &outDimTagsMap,
                                         const int tag, const bool removeObject,
                                         const bool removeTool)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanFragments(
       tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
       removeTool)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::translate(const vectorpair &dimTags,
                                          const double dx, const double dy,
                                          const double dz)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::rotate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double ax,
                                       const double ay, const double az,
                                       const double angle)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->rotate(dimTags, x, y, z, ax, ay, az,
                                                   angle)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::dilate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double a,
                                       const double b, const double c)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->dilate(dimTags, x, y, z, a, b, c)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::mirror(const vectorpair &dimTags,
                                       const double a, const double b,
                                       const double c, const double d)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->symmetry(dimTags, a, b, c, d)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::symmetrize(const vectorpair &dimTags,
                                           const double a, const double b,
                                           const double c, const double d)
{
  gmsh::model::occ::mirror(dimTags, a, b, c, d);
}

GMSH_API void gmsh::model::occ::affineTransform(const vectorpair &dimTags,
                                                const std::vector<double> &a)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->affine(dimTags, a)) { throw 1; }
}

GMSH_API void gmsh::model::occ::copy(const vectorpair &dimTags,
                                     vectorpair &outDimTags)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->copy(dimTags, outDimTags)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::remove(const vectorpair &dimTags,
                                       const bool recursive)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->remove(dimTags, recursive)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::removeAllDuplicates()
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
}

GMSH_API void gmsh::model::occ::healShapes(
  vectorpair &outDimTags, const vectorpair &inDimTags, const double tolerance,
  const bool fixDegenerated, const bool fixSmallEdges, const bool fixSmallFaces,
  const bool sewFaces, const bool makeSolids)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->healShapes(
       inDimTags, outDimTags, tolerance, fixDegenerated, fixSmallEdges,
       fixSmallFaces, sewFaces, makeSolids)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::importShapes(const std::string &fileName,
                                             vectorpair &outDimTags,
                                             const bool highestDimOnly,
                                             const std::string &format)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->importShapes(
       fileName, highestDimOnly, outDimTags, format)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::importShapesNativePointer(
  const void *shape, vectorpair &outDimTags, const bool highestDimOnly)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  outDimTags.clear();
#if defined(HAVE_OCC)
  if(!GModel::current()->getOCCInternals()->importShapes(
       static_cast<const TopoDS_Shape *>(shape), highestDimOnly, outDimTags)) {
    throw 1;
  }
#else
  Msg::Error("Gmsh requires OpenCASCADE to import native shape");
  throw -1;
#endif
}

GMSH_API void gmsh::model::occ::getEntities(vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->getEntities(dimTags, dim)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::getEntitiesInBoundingBox(
  const double xmin, const double ymin, const double zmin, const double xmax,
  const double ymax, const double zmax, vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  dimTags.clear();
  if(!GModel::current()->getOCCInternals()->getEntitiesInBoundingBox(
       xmin, ymin, zmin, xmax, ymax, zmax, dimTags, dim)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::getBoundingBox(const int dim, const int tag,
                                               double &xmin, double &ymin,
                                               double &zmin, double &xmax,
                                               double &ymax, double &zmax)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->getBoundingBox(
       dim, tag, xmin, ymin, zmin, xmax, ymax, zmax)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::getMass(const int dim, const int tag,
                                        double &mass)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->getMass(dim, tag, mass)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::getCenterOfMass(const int dim, const int tag,
                                                double &x, double &y, double &z)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->getCenterOfMass(dim, tag, x, y,
                                                            z)) {
    throw 1;
  }
}

GMSH_API void gmsh::model::occ::getMatrixOfInertia(const int dim, const int tag,
                                                   std::vector<double> &m)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->getMatrixOfInertia(dim, tag, m)) {
    throw 1;
  }
}

GMSH_API int gmsh::model::occ::getMaxTag(const int dim)
{
  if(!_isInitialized()) { throw -1; }
  return GModel::current()->getOCCInternals()->getMaxTag(dim);
}

GMSH_API void gmsh::model::occ::setMaxTag(const int dim, const int maxTag)
{
  if(!_isInitialized()) { throw -1; }
  GModel::current()->getOCCInternals()->setMaxTag(dim, maxTag);
}

GMSH_API void gmsh::model::occ::synchronize()
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
}

// gmsh::model::occ::mesh

GMSH_API void gmsh::model::occ::mesh::setSize(const vectorpair &dimTags,
                                              const double size)
{
  if(!_isInitialized()) { throw -1; }
  _createOcc();
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
}

// gmsh::view

GMSH_API int gmsh::view::add(const std::string &name, const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = new PView(tag);
  view->getData()->setName(name);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
  return view->getTag();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::remove(const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  delete view;
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API int gmsh::view::getIndex(const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  return view->getIndex();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::getTags(std::vector<int> &tags)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  tags.clear();
  for(std::size_t i = 0; i < PView::list.size(); i++)
    tags.push_back(PView::list[i]->getTag());
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

template <class T>
static void
_addModelData(const int tag, const int step, const std::string &modelName,
              const std::string &dataType, const std::vector<std::size_t> &tags,
              const T &data, const double time, const int numComponents,
              const int partition)
{
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  GModel *model = GModel::current();
  if(modelName.size()) {
    model = GModel::findByName(modelName);
    if(!model) {
      Msg::Error("Unknown model '%s'", modelName.c_str());
      throw 2;
    }
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(view->getData());
  if(!d) { // change the view type
    std::string name = view->getData()->getName();
    delete view->getData();
    PViewDataGModel::DataType type;
    if(dataType == "NodeData")
      type = PViewDataGModel::NodeData;
    else if(dataType == "ElementData")
      type = PViewDataGModel::ElementData;
    else if(dataType == "ElementNodeData")
      type = PViewDataGModel::ElementNodeData;
    else if(dataType == "GaussPointData")
      type = PViewDataGModel::GaussPointData;
    else if(dataType == "Beam")
      type = PViewDataGModel::BeamData;
    else {
      Msg::Error("Unknown type of view to add '%s'", dataType.c_str());
      throw 2;
    }
    d = new PViewDataGModel(type);
    d->setName(name);
    d->setFileName(name + ".msh");
    view->setData(d);
  }
  if(!d->addData(model, tags, data, step, time, partition, numComponents)) {
    Msg::Error("Could not add model data");
    throw 2;
  }
  if(view->getOptions()->adaptVisualizationGrid)
    d->initAdaptiveData(view->getOptions()->timeStep,
                        view->getOptions()->maxRecursionLevel,
                        view->getOptions()->targetError);
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::addModelData(
  const int tag, const int step, const std::string &modelName,
  const std::string &dataType, const std::vector<std::size_t> &tags,
  const std::vector<std::vector<double> > &data, const double time,
  const int numComponents, const int partition)
{
  if(!_isInitialized()) { throw -1; }
  if(tags.size() != data.size()) {
    Msg::Error("Incompatible number of tags and data");
    throw 2;
  }
  _addModelData(tag, step, modelName, dataType, tags, data, time, numComponents,
                partition);
}

GMSH_API void gmsh::view::addHomogeneousModelData(
  const int tag, const int step, const std::string &modelName,
  const std::string &dataType, const std::vector<std::size_t> &tags,
  const std::vector<double> &data, const double time, const int numComponents,
  const int partition)
{
  if(!_isInitialized()) { throw -1; }
  _addModelData(tag, step, modelName, dataType, tags, data, time, numComponents,
                partition);
}

GMSH_API void gmsh::view::getModelData(const int tag, const int step,
                                       std::string &dataType,
                                       std::vector<std::size_t> &tags,
                                       std::vector<std::vector<double> > &data,
                                       double &time, int &numComponents)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(view->getData());
  if(!d) {
    Msg::Error("View with tag %d does not contain model data", tag);
    return;
  }
  if(d->getType() == PViewDataGModel::NodeData)
    dataType = "NodeData";
  else if(d->getType() == PViewDataGModel::ElementData)
    dataType = "ElementData";
  else if(d->getType() == PViewDataGModel::ElementNodeData)
    dataType = "ElementNodeData";
  else if(d->getType() == PViewDataGModel::GaussPointData)
    dataType = "GaussPointData";
  else if(d->getType() == PViewDataGModel::BeamData)
    dataType = "Beam";
  else
    dataType = "Unknown";
  stepData<double> *s = d->getStepData(step);
  if(!s) {
    Msg::Error("View with tag %d does not contain model data for step %d", tag,
               step);
    throw 2;
  }
  tags.clear();
  data.clear();
  time = s->getTime();
  numComponents = s->getNumComponents();
  int numEnt = 0;
  for(std::size_t i = 0; i < s->getNumData(); i++) {
    if(s->getData(i)) numEnt++;
  }
  if(!numEnt) return;
  data.resize(numEnt);
  tags.resize(numEnt);
  std::size_t j = 0;
  for(std::size_t i = 0; i < s->getNumData(); i++) {
    double *dd = s->getData(i);
    if(dd) {
      tags[j] = i;
      int mult = s->getMult(i);
      data[j].resize(numComponents * mult);
      for(int k = 0; k < numComponents * mult; k++) data[j][k] = dd[k];
      j++;
    }
  }
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

// for better performance, manual C implementation of gmsh::view::getModelData
GMSH_API void gmshViewGetModelData(const int tag, const int step,
                                   char **dataType, size_t **tags,
                                   size_t *tags_n, double ***data,
                                   size_t **data_n, size_t *data_nn,
                                   double *time, int *numComponents, int *ierr)
{
  if(!_isInitialized()) {
    if(ierr) *ierr = -1;
    return;
  }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    if(ierr) *ierr = 2;
    return;
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(view->getData());
  if(!d) {
    Msg::Error("View with tag %d does not contain model data", tag);
    return;
  }
  if(d->getType() == PViewDataGModel::NodeData)
    *dataType = strdup("NodeData");
  else if(d->getType() == PViewDataGModel::ElementData)
    *dataType = strdup("ElementData");
  else if(d->getType() == PViewDataGModel::ElementNodeData)
    *dataType = strdup("ElementNodeData");
  else if(d->getType() == PViewDataGModel::GaussPointData)
    *dataType = strdup("GaussPointData");
  else if(d->getType() == PViewDataGModel::BeamData)
    *dataType = strdup("Beam");
  else
    *dataType = strdup("Unknown");
  stepData<double> *s = d->getStepData(step);
  if(!s) {
    Msg::Error("View with tag %d does not contain model data for step %d", tag,
               step);
    if(ierr) *ierr = 2;
    return;
  }
  *tags_n = 0;
  *data_nn = 0;
  *time = s->getTime();
  *numComponents = s->getNumComponents();
  int numEnt = 0;
  for(size_t i = 0; i < s->getNumData(); i++) {
    if(s->getData(i)) numEnt++;
  }
  if(!numEnt) return;
  *tags_n = numEnt;
  *tags = (size_t *)Malloc(numEnt * sizeof(size_t));
  *data_nn = numEnt;
  *data_n = (size_t *)Malloc(numEnt * sizeof(size_t *));
  *data = (double **)Malloc(numEnt * sizeof(double *));
  size_t j = 0;
  for(size_t i = 0; i < s->getNumData(); i++) {
    double *dd = s->getData(i);
    if(dd) {
      (*tags)[j] = i;
      int mult = s->getMult(i);
      (*data_n)[j] = *numComponents * mult;
      (*data)[j] = (double *)Malloc(*numComponents * mult * sizeof(double));
      for(int k = 0; k < *numComponents * mult; k++) (*data)[j][k] = dd[k];
      j++;
    }
  }
  if(ierr) *ierr = 0;
#else
  Msg::Error("Views require the post-processing module");
  if(ierr) *ierr = -1;
#endif
}

GMSH_API void gmsh::view::addListData(const int tag,
                                      const std::string &dataType,
                                      const int numElements,
                                      const std::vector<double> &data)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(!d) { // change the view type
    std::string name = view->getData()->getName();
    delete view->getData();
    d = new PViewDataList();
    d->setName(name);
    d->setFileName(name + ".pos");
    view->setData(d);
  }
  const char *types[] = {"SP", "VP", "TP", "SL", "VL", "TL", "ST", "VT",
                         "TT", "SQ", "VQ", "TQ", "SS", "VS", "TS", "SH",
                         "VH", "TH", "SI", "VI", "TI", "SY", "VY", "TY"};
  for(int idxtype = 0; idxtype < 24; idxtype++) {
    if(dataType == types[idxtype]) {
      d->importList(idxtype, numElements, data, true);
      return;
    }
  }
  Msg::Error("Unknown data type for list import");
  throw 2;
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::getListData(const int tag,
                                      std::vector<std::string> &dataTypes,
                                      std::vector<int> &numElements,
                                      std::vector<std::vector<double> > &data)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(!d) {
    Msg::Error("View with tag %d does not contain list data", tag);
    return;
  }
  const char *types[] = {"SP", "VP", "TP", "SL", "VL", "TL", "ST", "VT",
                         "TT", "SQ", "VQ", "TQ", "SS", "VS", "TS", "SH",
                         "VH", "TH", "SI", "VI", "TI", "SY", "VY", "TY"};
  std::vector<int> N(24);
  std::vector<std::vector<double> *> V(24);
  d->getListPointers(&N[0], &V[0]);
  for(int idxtype = 0; idxtype < 24; idxtype++) {
    if(N[idxtype]) {
      dataTypes.push_back(types[idxtype]);
      numElements.push_back(N[idxtype]);
      data.push_back(*V[idxtype]);
    }
  }
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

static double getStringStyle(const std::vector<std::string> &style)
{
  if(style.empty()) return 0.;
  int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
  if(style.size() % 2) {
    Msg::Error("Number of string style attributes should be even");
  }
  else {
    for(std::size_t i = 0; i < style.size(); i += 2) {
      std::string key = style[i], val = style[i + 1];
#if defined(HAVE_OPENGL)
      if(key == "Font")
        font = drawContext::global()->getFontIndex(val.c_str());
      else if(key == "FontSize")
        fontsize = atoi(val.c_str());
      else if(key == "Align")
        align = drawContext::global()->getFontAlign(val.c_str());
#endif
    }
  }
  return (double)((align << 16) | (font << 8) | (fontsize));
}

GMSH_API void
gmsh::view::addListDataString(const int tag, const std::vector<double> &coord,
                              const std::vector<std::string> &data,
                              const std::vector<std::string> &style)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(!d) { // change the view type
    std::string name = view->getData()->getName();
    delete view->getData();
    d = new PViewDataList();
    d->setName(name);
    d->setFileName(name + ".pos");
    view->setData(d);
  }
  if(coord.size() == 3) {
    d->T3D.push_back(coord[0]);
    d->T3D.push_back(coord[1]);
    d->T3D.push_back(coord[2]);
    d->T3D.push_back(getStringStyle(style)), d->T3D.push_back(d->T3C.size());
    d->NbT3++;
    for(std::size_t i = 0; i < data.size(); i++) {
      for(std::size_t j = 0; j < data[i].size(); j++) {
        d->T3C.push_back(data[i][j]);
      }
      d->T3C.push_back('\0');
    }
  }
  else if(coord.size() == 2) {
    d->T2D.push_back(coord[0]);
    d->T2D.push_back(coord[1]);
    d->T2D.push_back(getStringStyle(style)), d->T2D.push_back(d->T2C.size());
    d->NbT2++;
    for(std::size_t i = 0; i < data.size(); i++) {
      for(std::size_t j = 0; j < data[i].size(); j++) {
        d->T2C.push_back(data[i][j]);
      }
      d->T2C.push_back('\0');
    }
  }
  d->finalize();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::getListDataStrings(const int tag, const int dim,
                                             std::vector<double> &coord,
                                             std::vector<std::string> &data,
                                             std::vector<std::string> &style)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(!d) {
    Msg::Error("View with tag %d does not contain list data", tag);
    return;
  }
  int nstep = d->getNumTimeSteps();
  if(dim == 3) {
    int ns = d->getNumStrings3D();
    for(int i = 0; i < ns; i++) {
      for(int j = 0; j < nstep; j++) {
        double x, y, z, styl;
        std::string s;
        d->getString3D(i, j, s, x, y, z, styl);
        if(i == 0) {
          coord.push_back(x);
          coord.push_back(y);
          coord.push_back(z);
        }
        data.push_back(s);
        // TODO convert style to strings, pad with empty strings so that all
        // strings return the same number of styling pairs
        style.push_back("");
      }
    }
  }
  else if(dim == 2) {
    int ns = d->getNumStrings2D();
    for(int i = 0; i < ns; i++) {
      for(int j = 0; j < nstep; j++) {
        double x, y, styl;
        std::string s;
        d->getString2D(i, j, s, x, y, styl);
        if(i == 0) {
          coord.push_back(x);
          coord.push_back(y);
        }
        data.push_back(s);
        // TODO convert style to strings, pad with empty strings so that all
        // strings return the same number of styling pairs
        style.push_back("");
      }
    }
  }
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API int gmsh::view::addAlias(const int refTag, const bool copyOptions,
                                  const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *ref = PView::getViewByTag(refTag);
  if(!ref) {
    Msg::Error("Unknown view with tag %d", refTag);
    throw 2;
  }
  PView *view = new PView(ref, copyOptions, tag);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
  return view->getTag();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::copyOptions(const int refTag, const int tag)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *ref = PView::getViewByTag(refTag);
  if(!ref) {
    Msg::Error("Unknown view with tag %d", refTag);
    throw 2;
  }
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  view->setOptions(ref->getOptions());
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::combine(const std::string &what,
                                  const std::string &how, const bool remove,
                                  const bool copyOptions)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  bool time = (what == "steps") ? true : false; // "elements"
  int ihow = (how == "all") ? 1 : (how == "name") ? 2 : 0; // "visible"
  PView::combine(time, ihow, remove, copyOptions);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::probe(const int tag, const double x, const double y,
                                const double z, std::vector<double> &value,
                                const int step, const int numComp,
                                const bool gradient, const double tolerance,
                                const std::vector<double> &xElemCoord,
                                const std::vector<double> &yElemCoord,
                                const std::vector<double> &zElemCoord)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewData *data = view->getData();
  if(!data) { throw 2; }
  value.clear();
  std::vector<double> val(9 * data->getNumTimeSteps());
  bool found = false;
  int qn = 0;
  double *qx = 0, *qy = 0, *qz = 0;
  if(xElemCoord.size() && yElemCoord.size() && zElemCoord.size() &&
     xElemCoord.size() == yElemCoord.size() &&
     xElemCoord.size() == zElemCoord.size()) {
    qn = xElemCoord.size();
    qx = (double *)&xElemCoord[0];
    qy = (double *)&yElemCoord[0];
    qz = (double *)&zElemCoord[0];
  }
  switch(numComp) {
  case 1:
    found = data->searchScalarWithTol(x, y, z, &val[0], step, 0, tolerance, qn,
                                      qx, qy, qz, gradient);
    break;
  case 3:
    found = data->searchVectorWithTol(x, y, z, &val[0], step, 0, tolerance, qn,
                                      qx, qy, qz, gradient);
    break;
  case 9:
    found = data->searchTensorWithTol(x, y, z, &val[0], step, 0, tolerance, qn,
                                      qx, qy, qz, gradient);
    break;
  default:
    found = data->searchScalarWithTol(x, y, z, &val[0], step, 0, tolerance, qn,
                                      qx, qy, qz, gradient);
    if(!found)
      found = data->searchVectorWithTol(x, y, z, &val[0], step, 0, tolerance,
                                        qn, qx, qy, qz, gradient);
    if(!found)
      found = data->searchTensorWithTol(x, y, z, &val[0], step, 0, tolerance,
                                        qn, qx, qy, qz, gradient);
    break;
  }
  if(found) value.insert(value.end(), val.begin(), val.end());
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

GMSH_API void gmsh::view::write(const int tag, const std::string &fileName,
                                const bool append)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  view->write(fileName, 10, append);
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

// gmsh::plugin

GMSH_API void gmsh::plugin::setNumber(const std::string &name,
                                      const std::string &option,
                                      const double value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin option");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

GMSH_API void gmsh::plugin::setString(const std::string &name,
                                      const std::string &option,
                                      const std::string &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin option");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

GMSH_API void gmsh::plugin::run(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->action(name, "Run", 0);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin action");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

// gmsh::graphics

GMSH_API void gmsh::graphics::draw()
{
#if defined(HAVE_OPENGL)
  drawContext::global()->draw();
#endif
}

// gmsh::fltk

static void error_handler(const char *fmt, ...)
{
  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  Msg::Error("%s (FLTK internal error)", str);
  throw -1;
}

GMSH_API void gmsh::fltk::initialize()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  FlGui::instance(_argc, _argv, false, error_handler);
  FlGui::setFinishedProcessingCommandLine();
  FlGui::check(true);
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API int gmsh::fltk::isAvailable()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  return FlGui::available() ? 1 : 0;
#else
  return 0;
#endif
}

GMSH_API void gmsh::fltk::wait(const double time)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  if(time >= 0)
    FlGui::wait(time, true);
  else
    FlGui::wait(true);
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API void gmsh::fltk::lock()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  FlGui::lock();
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API void gmsh::fltk::unlock()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  FlGui::unlock();
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API void gmsh::fltk::update()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  FlGui::instance()->updateViews(true, true);
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API void gmsh::fltk::awake(const std::string &action)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  FlGui::awake(action);
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

GMSH_API void gmsh::fltk::run()
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  FlGui::instance()->run(); // this calls draw() once
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

#if defined(HAVE_FLTK)
static int selectionCode(char val)
{
  switch(val) {
  case 'q': return 0; // abort
  case 'l': return 1; // selected
  case 'r': return 2; // deselected
  case 'u': return 3; // undone last selection
  case 'e': return 4; // ended selection
  default: return -1; // unknown code
  }
}
#endif

GMSH_API int gmsh::fltk::selectEntities(vectorpair &dimTags, const int dim)
{
  if(!_isInitialized()) { throw -1; }
  dimTags.clear();
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  char ret = 0;
  switch(dim) {
  case 0: ret = FlGui::instance()->selectEntity(ENT_POINT); break;
  case 1: ret = FlGui::instance()->selectEntity(ENT_CURVE); break;
  case 2: ret = FlGui::instance()->selectEntity(ENT_SURFACE); break;
  case 3: ret = FlGui::instance()->selectEntity(ENT_VOLUME); break;
  default: ret = FlGui::instance()->selectEntity(ENT_ALL); break;
  }
  for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(0, FlGui::instance()->selectedVertices[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(1, FlGui::instance()->selectedEdges[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(2, FlGui::instance()->selectedFaces[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size(); i++)
    dimTags.push_back(
      std::pair<int, int>(1, FlGui::instance()->selectedRegions[i]->tag()));
  return selectionCode(ret);
#else
  return 0;
#endif
}

GMSH_API int gmsh::fltk::selectElements(std::vector<std::size_t> &elementTags)
{
  if(!_isInitialized()) { throw -1; }
  elementTags.clear();
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  int old = CTX::instance()->pickElements;
  CTX::instance()->pickElements = 1;
  CTX::instance()->mesh.changed = ENT_ALL;
  char ret = FlGui::instance()->selectEntity(ENT_ALL);
  CTX::instance()->pickElements = old;
  for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size(); i++)
    elementTags.push_back(FlGui::instance()->selectedElements[i]->getNum());
  return selectionCode(ret);
#else
  return 0;
#endif
}

GMSH_API int gmsh::fltk::selectViews(std::vector<int> &viewTags)
{
  if(!_isInitialized()) { throw -1; }
  viewTags.clear();
#if defined(HAVE_FLTK)
  if(!FlGui::available()) FlGui::instance(_argc, _argv, false, error_handler);
  char ret = FlGui::instance()->selectEntity(ENT_ALL);
  for(std::size_t i = 0; i < FlGui::instance()->selectedViews.size(); i++)
    viewTags.push_back(FlGui::instance()->selectedViews[i]->getTag());
  return selectionCode(ret);
#else
  return 0;
#endif
}

// gmsh::onelab

GMSH_API void gmsh::onelab::set(const std::string &data,
                                const std::string &format)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  if(format == "json") {
    if(!::onelab::server::instance()->fromJSON(data))
      Msg::Error("Could not parse json data '%s'", data.c_str());
  }
  else
    Msg::Error("Unknown data format");
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::get(std::string &data, const std::string &name,
                                const std::string &format)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  data.clear();
  if(name.empty()) {
    if(format == "json")
      ::onelab::server::instance()->toJSON(data, "Gmsh");
    else
      Msg::Error("Unknown data format");
  }
  else {
    std::vector< ::onelab::number> ps;
    ::onelab::server::instance()->get(ps, name);
    if(ps.size()) {
      if(format == "json")
        data = ps[0].toJSON();
      else
        data = ps[0].toChar();
    }
    else {
      std::vector< ::onelab::string> ps2;
      ::onelab::server::instance()->get(ps2, name);
      if(ps2.size()) {
        if(format == "json")
          data = ps2[0].toJSON();
        else
          data = ps2[0].toChar();
      }
    }
  }
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::setNumber(const std::string &name,
                                      const std::vector<double> &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  ::onelab::number p(name);
  std::vector< ::onelab::number> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) p = ps[0];
  p.setValues(value);
  ::onelab::server::instance()->set(p);
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::getNumber(const std::string &name,
                                      std::vector<double> &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  value.clear();
  std::vector< ::onelab::number> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) value = ps[0].getValues();
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::setString(const std::string &name,
                                      const std::vector<std::string> &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  ::onelab::string p(name);
  std::vector< ::onelab::string> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) p = ps[0];
  p.setValues(value);
  ::onelab::server::instance()->set(p);
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::getString(const std::string &name,
                                      std::vector<std::string> &value)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  value.clear();
  std::vector< ::onelab::string> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) value = ps[0].getValues();
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::clear(const std::string &name)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  ::onelab::server::instance()->clear(name);
#else
  Msg::Error("ONELAB not available");
  throw -1;
#endif
}

GMSH_API void gmsh::onelab::run(const std::string &name,
                                const std::string &command)
{
  if(!_isInitialized()) { throw -1; }
#if defined(HAVE_ONELAB)
  onelabUtils::runClient(name, command);
#endif
}

// gmsh::logger

GMSH_API void gmsh::logger::write(const std::string &message,
                                  const std::string &level)
{
  if(!_isInitialized()) { throw -1; }
  if(level == "error")
    Msg::Error("%s", message.c_str());
  else if(level == "warning")
    Msg::Warning("%s", message.c_str());
  else
    Msg::Info("%s", message.c_str());
}

class apiMsg : public GmshMessage {
private:
  std::vector<std::string> _log;

public:
  apiMsg() {}
  virtual void operator()(std::string level, std::string message)
  {
    _log.push_back(level + ": " + message);
  }
  void get(std::vector<std::string> &log) const { log = _log; }
};

GMSH_API void gmsh::logger::start()
{
  if(!_isInitialized()) { throw -1; }
  GmshMessage *msg = Msg::GetCallback();
  if(msg) { Msg::Warning("Logger already started - ignoring"); }
  else {
    msg = new apiMsg();
    Msg::SetCallback(msg);
  }
}

GMSH_API void gmsh::logger::get(std::vector<std::string> &log)
{
  if(!_isInitialized()) { throw -1; }
  apiMsg *msg = dynamic_cast<apiMsg *>(Msg::GetCallback());
  if(msg) { msg->get(log); }
  else {
    log.clear();
  }
}

GMSH_API void gmsh::logger::stop()
{
  if(!_isInitialized()) { throw -1; }
  GmshMessage *msg = Msg::GetCallback();
  if(msg) {
    delete msg;
    Msg::SetCallback(0);
  }
  else {
    Msg::Warning("Logger not started - ignoring");
  }
}

GMSH_API double gmsh::logger::getWallTime()
{
  if(!_isInitialized()) { throw -1; }
  return TimeOfDay();
}

GMSH_API double gmsh::logger::getCpuTime()
{
  if(!_isInitialized()) { throw -1; }
  return Cpu();
}
