// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <regex>

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
#include "gmshSurface.h"
#include "MVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MVertexRTree.h"
#include "ExtrudeParams.h"
#include "StringUtils.h"
#include "Context.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "Numeric.h"
#include "OS.h"
#include "Options.h"
#include "OpenFile.h"
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
#include "meshGFace.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshGRegionHxt.h"
#include "gmshCrossFields.h"
#include "qualityMeasuresJacobian.h"
#include "meshRenumber.h"
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

#if defined(HAVE_PARSER)
#include "Parser.h"
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
static char **_argv = nullptr;

static bool _checkInit()
{
  if(!_initialized) {
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

GMSH_API void gmsh::initialize(int argc, char ** argv,
                               const bool readConfigFiles, const bool run)
{
  if(_initialized) {
    Msg::Warning("Gmsh has aleady been initialized");
    return;
  }

  // when running the app, create a model (that will be used in GmshInitialize
  // to e.g. set the project name)
  if(run) new GModel();

  if(GmshInitialize(argc, argv, readConfigFiles, false)) {
    _initialized = 1;
    _argc = argc;
    _argv = new char *[_argc + 1];
    for(int i = 0; i < argc; i++) _argv[i] = argv[i];

#if defined(HAVE_FLTK)
    // if the GUI is already running (rare case, but could happen), we're done
    if(FlGui::available()) return;
#endif

    if(run) {
      if(CTX::instance()->batch) {
        if(!Msg::GetGmshClient()) CTX::instance()->terminal = 1;
        GmshBatch();
      }
      else {
        GmshFLTK(argc, argv);
      }
    }
    else {
      // throw an exception as soon as an error occurs, unless the GUI is
      // running (by default the Gmsh app - and thus also when "run" is set -
      // always keeps going after errors)
      CTX::instance()->abortOnError = 2;
      // show messages on the terminal
      CTX::instance()->terminal = 1;
    }
    return;
  }
  Msg::Error("Something went wrong when initializing Gmsh");
}

GMSH_API int gmsh::isInitialized()
{
  return _initialized;
}

GMSH_API void gmsh::finalize()
{
  if(!_checkInit()) return;
  if(GmshFinalize()) {
    _argc = 0;
    if(_argv) delete[] _argv;
    _argv = nullptr;
    _initialized = 0;
    return;
  }
  Msg::Error("Something went wrong when finalizing Gmsh");
}

GMSH_API void gmsh::open(const std::string &fileName)
{
  if(!_checkInit()) return;
  if(!GmshOpenProject(fileName))
    Msg::Error("Could not open file '%s'", fileName.c_str());
}

GMSH_API void gmsh::merge(const std::string &fileName)
{
  if(!_checkInit()) return;
  if(!GmshMergeFile(fileName))
    Msg::Error("Could not merge file '%s'", fileName.c_str());
}

GMSH_API void gmsh::write(const std::string &fileName)
{
  if(!_checkInit()) return;
  if(!GmshWriteFile(fileName))
    Msg::Error("Could not write file '%s'", fileName.c_str());
}

GMSH_API void gmsh::clear()
{
  if(!_checkInit()) return;
  if(!GmshClearProject()) Msg::Error("Could not clear project");
}

// gmsh::option

GMSH_API void gmsh::option::setNumber(const std::string &name,
                                      const double value)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(!GmshSetOption(c, n, value, i))
    Msg::Error("Could not set option '%s'", name.c_str());
}

GMSH_API void gmsh::option::getNumber(const std::string &name, double &value)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(!GmshGetOption(c, n, value, i))
    Msg::Error("Could not get option '%s'", name.c_str());
}

GMSH_API void gmsh::option::setString(const std::string &name,
                                      const std::string &value)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(!GmshSetOption(c, n, value, i))
    Msg::Error("Could not set option '%s'", name.c_str());
}

GMSH_API void gmsh::option::getString(const std::string &name,
                                      std::string &value)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  if(!GmshGetOption(c, n, value, i))
    Msg::Error("Could not get option '%s'", name.c_str());
}

GMSH_API void gmsh::option::setColor(const std::string &name, const int r,
                                     const int g, const int b, const int a)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  // allow "Category.Color.Option" name for compatibility with .geo parser
  n = ReplaceSubString("Color.", "", n);
  unsigned int value = CTX::instance()->packColor(r, g, b, a);
  if(!GmshSetOption(c, n, value, i))
    Msg::Error("Could not set option '%s'", name.c_str());
}

GMSH_API void gmsh::option::getColor(const std::string &name, int &r, int &g,
                                     int &b, int &a)
{
  if(!_checkInit()) return;
  std::string c, n;
  int i;
  SplitOptionName(name, c, n, i);
  // allow "Category.Color.Option" name for compatibility with .geo parser
  n = ReplaceSubString("Color.", "", n);
  unsigned int value;
  if(GmshGetOption(c, n, value, i)) {
    r = CTX::instance()->unpackRed(value);
    g = CTX::instance()->unpackGreen(value);
    b = CTX::instance()->unpackBlue(value);
    a = CTX::instance()->unpackAlpha(value);
  }
  else {
    Msg::Error("Could not get option '%s'", name.c_str());
  }
}

GMSH_API void gmsh::option::restoreDefaults()
{
  UnlinkFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName);
  UnlinkFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName);
  ReInitOptions(0);
  InitOptionsGUI(0);
}

// gmsh::model

GMSH_API void gmsh::model::add(const std::string &name)
{
  if(!_checkInit()) return;
  GModel *m = new GModel(name);
  GModel::current(GModel::list.size() - 1);
  if(!m) Msg::Error("Could not add model '%s'", name.c_str());
}

GMSH_API void gmsh::model::remove()
{
  if(!_checkInit()) return;
  GModel *m = GModel::current();
  if(m)
    delete m;
  else
    Msg::Error("Could not remove current model");
}

GMSH_API void gmsh::model::list(std::vector<std::string> &names)
{
  if(!_checkInit()) return;
  for(auto m : GModel::list) names.push_back(m->getName());
}

GMSH_API void gmsh::model::getCurrent(std::string &name)
{
  if(!_checkInit()) return;
  name = GModel::current()->getName();
}

GMSH_API void gmsh::model::setCurrent(const std::string &name)
{
  if(!_checkInit()) return;
  GModel *m = GModel::findByName(name);
  if(!m) {
    Msg::Error("Could not find model '%s'", name.c_str());
    return;
  }
  GModel::setCurrent(m);
  for(auto m : GModel::list) m->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::getFileName(std::string &fileName)
{
  if(!_checkInit()) return;
  fileName = GModel::current()->getFileName();
}

GMSH_API void gmsh::model::setFileName(const std::string &fileName)
{
  if(!_checkInit()) return;
  GModel::current()->setFileName(fileName);
}

GMSH_API void gmsh::model::getEntities(vectorpair &dimTags, const int dim)
{
  if(!_checkInit()) return;
  dimTags.clear();
  std::vector<GEntity *> entities;
  GModel::current()->getEntities(entities, dim);
  dimTags.reserve(entities.size());
  for(auto ge : entities)
    dimTags.push_back(std::make_pair(ge->dim(), ge->tag()));
}

GMSH_API void gmsh::model::setEntityName(const int dim, const int tag,
                                         const std::string &name)
{
  if(!_checkInit()) return;
  GModel::current()->setElementaryName(dim, tag, name);
}

GMSH_API void gmsh::model::getEntityName(const int dim, const int tag,
                                         std::string &name)
{
  if(!_checkInit()) return;
  name = GModel::current()->getElementaryName(dim, tag);
}

GMSH_API void gmsh::model::getPhysicalGroups(vectorpair &dimTags, const int dim)
{
  if(!_checkInit()) return;
  dimTags.clear();
  std::map<int, std::vector<GEntity *> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  for(int d = 0; d < 4; d++) {
    if(dim < 0 || d == dim) {
      for(auto it = groups[d].begin(); it != groups[d].end(); it++)
        dimTags.push_back(std::make_pair(d, it->first));
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
  if(!_checkInit()) return;
  tags.clear();
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  auto it = groups.find(tag);
  if(it != groups.end()) {
    for(auto ge : it->second) tags.push_back(ge->tag());
  }
  else {
    Msg::Error("Physical %s does not exist", _getEntityName(dim, tag).c_str());
  }
}

GMSH_API void gmsh::model::getEntitiesForPhysicalName(const std::string &name,
                                                      vectorpair &dimTags)
{
  if(!_checkInit()) return;
  dimTags.clear();
  std::vector<GEntity *> entities;
  GModel::current()->getEntitiesForPhysicalName(name, entities);
  if(entities.size() != 0) {
    for(auto ge : entities) {
      dimTags.push_back(std::pair<int, int >(ge->dim(), ge->tag()));
    }
  }
  else {
    Msg::Error("Physical name '%s' does not exist", name.c_str());
  }
}

GMSH_API void
gmsh::model::getPhysicalGroupsForEntity(const int dim, const int tag,
                                        std::vector<int> &physicalTags)
{
  if(!_checkInit()) return;
  physicalTags.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  physicalTags = ge->getPhysicalEntities();
}

GMSH_API int gmsh::model::addPhysicalGroup(const int dim,
                                           const std::vector<int> &tags,
                                           const int tag,
                                           const std::string &name)
{
  // FIXME: 1) the "master" physical group definitions are still stored in the
  // buil-in CAD kernel, so that built-in CAD operations (e.g. Coherence) can
  // track physical groups; and 2) the synchronization of the built-in CAD
  // kernel triggers a reset of physical groups in GModel, followed by a
  // copy. So we currently need to maintain both copies when playing with
  // physical groups in the api at the model level.
  if(!_checkInit()) return -1;
  int outTag = tag;
  if(outTag < 0) {
    outTag =
      std::max(GModel::current()->getMaxPhysicalNumber(dim),
               GModel::current()->getGEOInternals()->getMaxPhysicalTag()) +
      1;
  }
  if(!GModel::current()->getGEOInternals()->modifyPhysicalGroup(dim, outTag, 0,
                                                                tags)) {
    Msg::Error("Could not add physical group");
    return -1;
  }
  GModel::current()->addPhysicalGroup(dim, outTag, tags);
  if(!name.empty()) GModel::current()->setPhysicalName(name, dim, outTag);
  return outTag;
}

GMSH_API void gmsh::model::removePhysicalGroups(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  if(dimTags.empty()) {
    GModel::current()->getGEOInternals()->resetPhysicalGroups();
    GModel::current()->removePhysicalGroups();
  }
  else {
    // FIXME: rewrite the unerlying code: it's slow
    for(std::size_t i = 0; i < dimTags.size(); i++) {
      std::vector<int> tags; // empty to delete the group
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(
        dimTags[i].first, dimTags[i].second, 2, tags);
      GModel::current()->removePhysicalGroup(dimTags[i].first,
                                             dimTags[i].second);
    }
  }
}

GMSH_API void gmsh::model::setPhysicalName(const int dim, const int tag,
                                           const std::string &name)
{
  if(!_checkInit()) return;
  GModel::current()->setPhysicalName(name, dim, tag);
}

GMSH_API void gmsh::model::removePhysicalName(const std::string &name)
{
  if(!_checkInit()) return;
  GModel::current()->removePhysicalName(name);
}

GMSH_API void gmsh::model::getPhysicalName(const int dim, const int tag,
                                           std::string &name)
{
  if(!_checkInit()) return;
  name = GModel::current()->getPhysicalName(dim, tag);
}

GMSH_API void gmsh::model::setTag(const int dim, const int tag, const int newTag)
{
  if(!_checkInit()) return;
  GModel::current()->changeEntityTag(dim, tag, newTag);
}

GMSH_API void gmsh::model::getBoundary(const vectorpair &dimTags,
                                       vectorpair &outDimTags,
                                       const bool combined, const bool oriented,
                                       const bool recursive)
{
  if(!_checkInit()) return;
  outDimTags.clear();
  if(!GModel::current()->getBoundaryTags(dimTags, outDimTags, combined,
                                         oriented, recursive)) {
    Msg::Error("Could not get boundary");
  }
}

GMSH_API void gmsh::model::getAdjacencies(const int dim, const int tag,
                                          std::vector<int> &upward,
                                          std::vector<int> &downward)
{
  if(!_checkInit()) return;
  upward.clear();
  downward.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  switch(dim) {
  case 0:
    for(auto &e : static_cast<GVertex *>(ge)->edges())
      upward.push_back(e->tag());
    break;
  case 1:
    for(auto &e : static_cast<GEdge *>(ge)->faces()) upward.push_back(e->tag());
    for(auto &e : static_cast<GEdge *>(ge)->vertices())
      downward.push_back(e->tag());
    break;
  case 2:
    for(auto &e : static_cast<GFace *>(ge)->regions())
      upward.push_back(e->tag());
    for(auto &e : static_cast<GFace *>(ge)->edges())
      downward.push_back(e->tag());
    break;
  case 3:
    for(auto &e : static_cast<GRegion *>(ge)->faces())
      downward.push_back(e->tag());
    break;
  }
}

GMSH_API void gmsh::model::getEntitiesInBoundingBox(
  const double xmin, const double ymin, const double zmin, const double xmax,
  const double ymax, const double zmax, vectorpair &dimTags, const int dim)
{
  if(!_checkInit()) return;
  dimTags.clear();
  SBoundingBox3d box(xmin, ymin, zmin, xmax, ymax, zmax);
  std::vector<GEntity *> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(auto ge : entities)
    dimTags.push_back(std::make_pair(ge->dim(), ge->tag()));
}

GMSH_API void gmsh::model::getBoundingBox(const int dim, const int tag,
                                          double &xmin, double &ymin,
                                          double &zmin, double &xmax,
                                          double &ymax, double &zmax)
{
  if(!_checkInit()) return;

  SBoundingBox3d box;
  if(dim < 0 && tag < 0) {
    box = GModel::current()->bounds();
    if(box.empty()) {
      Msg::Error("Empty bounding box");
      return;
    }
  }
  else {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    box = ge->bounds();
  }
  if(box.empty()) {
    Msg::Error("Empty bounding box");
    return;
  }
  xmin = box.min().x();
  ymin = box.min().y();
  zmin = box.min().z();
  xmax = box.max().x();
  ymax = box.max().y();
  zmax = box.max().z();
}

GMSH_API int gmsh::model::getDimension()
{
  if(!_checkInit()) return -1;
  return GModel::current()->getDim();
}

GMSH_API int gmsh::model::addDiscreteEntity(const int dim, const int tag,
                                            const std::vector<int> &boundary)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  if(outTag < 0) {
    outTag = GModel::current()->getMaxElementaryNumber(dim) + 1;
  }
  GEntity *e = GModel::current()->getEntityByTag(dim, outTag);
  if(e) {
    Msg::Error("%s already exists", _getEntityName(dim, outTag).c_str());
    return -1;
  }
  switch(dim) {
  case 0: {
    discreteVertex *gv = new discreteVertex(GModel::current(), outTag);
    GModel::current()->add(gv);
    break;
  }
  case 1: {
    GVertex *v0 = nullptr, *v1 = nullptr;
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
  }
  return outTag;
}

GMSH_API void gmsh::model::removeEntities(const vectorpair &dimTags,
                                          const bool recursive)
{
  if(!_checkInit()) return;
  std::vector<GEntity*> removed;
  GModel::current()->remove(dimTags, removed, recursive);
  Msg::Debug("Destroying %lu entities in model", removed.size());
  for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
}

GMSH_API void gmsh::model::removeEntityName(const std::string &name)
{
  if(!_checkInit()) return;
  GModel::current()->removeElementaryName(name);
}

GMSH_API void gmsh::model::getType(const int dim, const int tag,
                                   std::string &entityType)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  entityType = ge->getTypeString();
}

GMSH_API void gmsh::model::getParent(const int dim, const int tag,
                                     int &parentDim, int &parentTag)
{
  if(!_checkInit()) return;
  parentDim = -1;
  parentTag = -1;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
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
  if(!_checkInit()) return;
  partitions.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
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

GMSH_API int gmsh::model::getNumberOfPartitions()
{
  if(!_checkInit()) return 0;
  return GModel::current()->getNumPartitions();
}

GMSH_API void gmsh::model::getValue(const int dim, const int tag,
                                    const std::vector<double> &parametricCoord,
                                    std::vector<double> &coord)
{
  if(!_checkInit()) return;
  coord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
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
    if(parametricCoord.size() % 2) {
      Msg::Error("Number of parametric coordinates should be even");
      return;
    }
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
  if(!_checkInit()) return;
  deriv.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
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
    if(parametricCoord.size() % 2) {
      Msg::Error("Number of parametric coordinates should be even");
      return;
    }
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
gmsh::model::getSecondDerivative(const int dim, const int tag,
                                 const std::vector<double> &parametricCoord,
                                 std::vector<double> &deriv)
{
  if(!_checkInit()) return;
  deriv.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++) {
      SVector3 d = ge->secondDer(parametricCoord[i]);
      deriv.push_back(d.x());
      deriv.push_back(d.y());
      deriv.push_back(d.z());
    }
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) {
      Msg::Error("Number of parametric coordinates should be even");
      return;
    }
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
      SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
      SVector3 dudu, dvdv, dudv;
      gf->secondDer(param, dudu, dvdv, dudv);
      deriv.push_back(dudu.x());
      deriv.push_back(dudu.y());
      deriv.push_back(dudu.z());
      deriv.push_back(dvdv.x());
      deriv.push_back(dvdv.y());
      deriv.push_back(dvdv.z());
      deriv.push_back(dudv.x());
      deriv.push_back(dudv.y());
      deriv.push_back(dudv.z());
    }
  }
}

GMSH_API void
gmsh::model::getCurvature(const int dim, const int tag,
                          const std::vector<double> &parametricCoord,
                          std::vector<double> &curvatures)
{
  if(!_checkInit()) return;
  curvatures.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < parametricCoord.size(); i++)
      curvatures.push_back(ge->curvature(parametricCoord[i]));
  }
  else if(dim == 2) {
    if(parametricCoord.size() % 2) {
      Msg::Error("Number of parametric coordinates should be even");
      return;
    }
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
  if(!_checkInit()) return;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    return;
  }
  curvaturesMax.clear();
  curvaturesMin.clear();
  directionsMax.clear();
  directionsMin.clear();
  if(parametricCoord.size() % 2) {
    Msg::Error("Number of parametric coordinates should be even");
    return;
  }
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
  if(!_checkInit()) return;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    return;
  }
  normals.clear();
  if(parametricCoord.size() % 2) {
    Msg::Error("Number of parametric coordinates should be even");
    return;
  }
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
  if(!_checkInit()) return;
  parametricCoord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(coord.size() % 3) {
    Msg::Error("Number of coordinates should be a multiple of 3");
    return;
  }
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
      SPoint2 uv = gf->parFromPoint(p, true, true);
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
  if(!_checkInit()) return;
  min.clear();
  max.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  for(int dim = 0; dim < entity->dim(); dim++) {
    Range<double> r = entity->parBounds(dim);
    min.push_back(r.low());
    max.push_back(r.high());
  }
}

GMSH_API int gmsh::model::isInside(const int dim, const int tag,
                                   const std::vector<double> &coord,
                                   const bool parametric)
{
  if(!_checkInit()) return -1;
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return 0;
  }
  int num = 0;
  if(parametric) {
    if(dim == 1) {
      GEdge *ge = static_cast<GEdge *>(entity);
      for(std::size_t i = 0; i < coord.size(); i++) {
        if(ge->containsParam(coord[i])) num++;
      }
    }
    else if(dim == 2) {
      GFace *gf = static_cast<GFace *>(entity);
      if(coord.size() % 2) {
        Msg::Error("Number of parametric coordinates should be even");
        return num;
      }
      for(std::size_t i = 0; i < coord.size(); i += 2) {
        SPoint2 param(coord[i], coord[i + 1]);
        if(gf->containsParam(param)) num++;
      }
    }
  }
  else {
    if(coord.size() % 3) {
      Msg::Error("Number of coordinates should be a multiple of 3");
      return 0;
    }
    for(std::size_t i = 0; i < coord.size(); i += 3) {
      SPoint3 pt(coord[i], coord[i + 1], coord[i + 2]);
      if(entity->isFullyDiscrete()) { // query the mesh
        SPoint3 uvw;
        MElement *e = GModel::current()->getMeshElementByCoord(pt, uvw,
                                                               entity->dim());
        if(e) {
          int entityTag;
          e = GModel::current()->getMeshElementByTag(e->getNum(), entityTag);
          if(e && entityTag == entity->tag()) num++;
        }
      }
      else { // query the CAD
        if(entity->containsPoint(pt)) num++;
      }
    }
  }
  return num;
}

GMSH_API void gmsh::model::reparametrizeOnSurface(
  const int dim, const int tag, const std::vector<double> &parametricCoord,
  const int surfaceTag, std::vector<double> &surfaceParametricCoord,
  const int which)
{
  if(!_checkInit()) return;
  surfaceParametricCoord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  GFace *gf = GModel::current()->getFaceByTag(surfaceTag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, surfaceTag).c_str());
    return;
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

GMSH_API void gmsh::model::getClosestPoint(const int dim, const int tag,
                                           const std::vector<double> &coord,
                                           std::vector<double> &closestCoord,
                                           std::vector<double> &parametricCoord)
{
  if(!_checkInit()) return;
  closestCoord.clear();
  parametricCoord.clear();
  GEntity *entity = GModel::current()->getEntityByTag(dim, tag);
  if(!entity) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(coord.size() % 3) {
    Msg::Error("Number of coordinates should be a multiple of 3");
    return;
  }
  if(dim == 1) {
    GEdge *ge = static_cast<GEdge *>(entity);
    for(std::size_t i = 0; i < coord.size(); i += 3) {
      SPoint3 p(coord[i], coord[i + 1], coord[i + 2]);
      double t;
      GPoint pp = ge->closestPoint(p, t);
      closestCoord.push_back(pp.x());
      closestCoord.push_back(pp.y());
      closestCoord.push_back(pp.z());
      parametricCoord.push_back(t);
    }
  }
  else if(dim == 2) {
    GFace *gf = static_cast<GFace *>(entity);
    for(std::size_t i = 0; i < coord.size(); i += 3) {
      SPoint3 p(coord[i], coord[i + 1], coord[i + 2]);
      double uv[2] = {0, 0};
      GPoint pp = gf->closestPoint(p, uv);
      closestCoord.push_back(pp.x());
      closestCoord.push_back(pp.y());
      closestCoord.push_back(pp.z());
      parametricCoord.push_back(uv[0]);
      parametricCoord.push_back(uv[1]);
    }
  }
}

GMSH_API void gmsh::model::setVisibility(const vectorpair &dimTags,
                                         const int value, const bool recursive)
{
  if(!_checkInit()) return;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    GEntity *ge = GModel::current()->getEntityByTag(
      dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setVisibility(value, recursive);
  }
}

GMSH_API void gmsh::model::getVisibility(const int dim, const int tag,
                                         int &value)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  value = ge->getVisibility();
}

GMSH_API void gmsh::model::setVisibilityPerWindow(const int value,
                                                  const int windowIndex)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  FlGui::instance()->setCurrentOpenglWindow(windowIndex);
  drawContext *ctx = FlGui::instance()->getCurrentDrawContext();
  GModel *m = GModel::current();
  if(value)
    ctx->show(m);
  else
    ctx->hide(m);
#endif
}

GMSH_API void gmsh::model::setColor(const vectorpair &dimTags, const int r,
                                    const int g, const int b, const int a,
                                    const bool recursive)
{
  if(!_checkInit()) return;
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
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
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
  if(!_checkInit()) return;
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(!gv) {
    Msg::Error("%s does not exist", _getEntityName(0, tag).c_str());
    return;
  }
  GPoint p(x, y, z);
  gv->setPosition(p);
}

GMSH_API void gmsh::model::getAttributeNames(std::vector<std::string> &names)
{
  if(!_checkInit()) return;
  names.clear();
  for(auto a : GModel::current()->getAttributes())
    names.push_back(a.first);
}

GMSH_API void gmsh::model::getAttribute(const std::string &name,
                                        std::vector<std::string> &values)
{
  if(!_checkInit()) return;
  values = GModel::current()->getAttributes()[name];
}

GMSH_API void gmsh::model::setAttribute(const std::string &name,
                                        const std::vector<std::string> &values)
{
  if(!_checkInit()) return;
  GModel::current()->getAttributes()[name] = values;
}

GMSH_API void gmsh::model::removeAttribute(const std::string &name)
{
  if(!_checkInit()) return;
  GModel::current()->getAttributes().erase(name);
}

// gmsh::model::mesh

GMSH_API void gmsh::model::mesh::generate(const int dim)
{
  if(!_checkInit()) return;
  GModel::current()->mesh(dim);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void
gmsh::model::mesh::partition(const int numPart,
                             const std::vector<std::size_t> &elementTags,
                             const std::vector<int> &partitions)
{
  if(!_checkInit()) return;
  std::vector<std::pair<MElement *, int> > epart;
  if(elementTags.size()) {
    if(elementTags.size() != partitions.size()) {
      Msg::Error("Number of element tags (%d) does not match number of "
                 "partitions (%d)",
                 elementTags.size(), partitions.size());
      return;
    }
    epart.reserve(elementTags.size());
    for(std::size_t i = 0; i < elementTags.size(); i++) {
      MElement *el = GModel::current()->getMeshElementByTag(elementTags[i]);
      if(el)
        epart.push_back(std::make_pair(el, partitions[i]));
      else
        Msg::Error("Unknown element %d", elementTags[i]);
    }
  }
  GModel::current()->partitionMesh(
    numPart >= 0 ? numPart : CTX::instance()->mesh.numPartitions, epart);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::unpartition()
{
  if(!_checkInit()) return;
  GModel::current()->unpartitionMesh();
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::refine()
{
  if(!_checkInit()) return;
  GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                CTX::instance()->mesh.algoSubdivide == 1,
                                CTX::instance()->mesh.algoSubdivide == 2,
                                CTX::instance()->mesh.algoSubdivide == 3);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::recombine()
{
  if(!_checkInit()) return;
  GModel::current()->recombineMesh();
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::optimize(const std::string &how,
                                          const bool force, const int niter,
                                          const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  if(dimTags.size()) {
    Msg::Warning(
      "Optimization of specified model entities is not interfaced yet");
  }
  GModel::current()->optimizeMesh(how, force, niter);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::computeCrossField(std::vector<int> &tags)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  if(computeCrossField(GModel::current(), tags)) {
    Msg::Error("Could not compute cross field");
    return;
  }
#else
  Msg::Error("computeCrossField requires the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::splitQuadrangles(const double quality,
                                                  const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  std::vector<GEntity *> entities;
  if(tag < 0) { GModel::current()->getEntities(entities, 2); }
  else {
    GEntity *ge = GModel::current()->getEntityByTag(2, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
      return;
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
#endif
}

GMSH_API void gmsh::model::mesh::setOrder(const int order)
{
  if(!_checkInit()) return;
  GModel::current()->setOrderN(order, CTX::instance()->mesh.secondOrderLinear,
                               CTX::instance()->mesh.secondOrderIncomplete,
                               CTX::instance()->mesh.meshOnlyVisible);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::getLastEntityError(vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> e = GModel::current()->getLastMeshEntityError();
  dimTags.clear();
  for(std::size_t i = 0; i < e.size(); i++)
    dimTags.push_back(std::make_pair(e[i]->dim(), e[i]->tag()));
}

GMSH_API void
gmsh::model::mesh::getLastNodeError(std::vector<std::size_t> &nodeTags)
{
  if(!_checkInit()) return;
  std::vector<MVertex *> v = GModel::current()->getLastMeshVertexError();
  nodeTags.clear();
  for(std::size_t i = 0; i < v.size(); i++) nodeTags.push_back(v[i]->getNum());
}

GMSH_API void gmsh::model::mesh::clear(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first;
    int tag = dimTags[i].second;
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    entities.push_back(ge);
  }
  GModel::current()->deleteMesh(entities);
}

GMSH_API void gmsh::model::mesh::removeElements(
   const int dim, const int tag,
   const std::vector<std::size_t> &elementTags)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(elementTags.empty()) {
    ge->removeElements(true);
  }
  else {
    for(auto t : elementTags) {
      MElement *e = GModel::current()->getMeshElementByTag(t);
      if(!e) {
        Msg::Error("Unknown element %d", t);
      }
      else {
        ge->removeElement(e, true);
      }
    }
  }
  ge->deleteVertexArrays();
  GModel::current()->destroyMeshCaches();
  // we leave the user to call reclassifyNodes()
}

static void _getEntities(const gmsh::vectorpair &dimTags,
                         std::vector<GEntity *> &entities)
{
  if(dimTags.empty()) { GModel::current()->getEntities(entities); }
  else {
    for(auto dimTag : dimTags) {
      int dim = dimTag.first, tag = dimTag.second;
      GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
      if(!ge) {
        Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
        return;
      }
      entities.push_back(ge);
    }
  }
}

GMSH_API void gmsh::model::mesh::reverse(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  for(auto ge : entities) {
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      ge->getMeshElement(j)->reverse();
    }
  }
  GModel::current()->destroyMeshCaches();
}

GMSH_API void gmsh::model::mesh::reverseElements(const std::vector<std::size_t> & elementTags)
{
  if(!_checkInit()) return;
  for(auto const tag : elementTags) {
    MElement *e = GModel::current()->getMeshElementByTag(tag);
    if(e) {
      e->reverse();
    }
    else {
      Msg::Error("Could not find element %d", tag);
    }
  }
  GModel::current()->destroyMeshCaches();
}

GMSH_API void
gmsh::model::mesh::affineTransform(const std::vector<double> &affineTransform,
                                   const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  for(auto ge : entities) {
    for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
      MVertex *v = ge->getMeshVertex(j);
      SPoint3 pt = v->point();
      if(pt.transform(affineTransform))
        v->setXYZ(pt);
      else
        Msg::Error("Could not transform node %d (%g, %g, %g) on %s",
                   v->getNum(), v->x(), v->y(), v->z(),
                   _getEntityName(ge->dim(), ge->tag()).c_str());
    }
  }
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
  for(auto it = f.begin(); it != f.end(); it++) {
    GFace *gf = *it;
    for(std::size_t j = 0; j < gf->mesh_vertices.size(); j++) {
      MVertex *v = gf->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
    }
  }
  for(auto it = e.begin(); it != e.end(); it++) {
    GEdge *ge = *it;
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
      if(entity->dim() == 2 && parametric) {
        SPoint2 param;
        if(!reparamMeshVertexOnFace(v, (GFace *)entity, param, true, false))
          Msg::Warning("Failed to compute parameters of node %d on surface %d",
                       v->getNum(), entity->tag());
        parametricCoord.push_back(param.x());
        parametricCoord.push_back(param.y());
      }
    }
  }
  for(auto it = v.begin(); it != v.end(); it++) {
    GVertex *gv = *it;
    for(std::size_t j = 0; j < gv->mesh_vertices.size(); j++) {
      MVertex *v = gv->mesh_vertices[j];
      nodeTags.push_back(v->getNum());
      coord.push_back(v->x());
      coord.push_back(v->y());
      coord.push_back(v->z());
      if(entity->dim() == 2 && parametric) {
        SPoint2 param;
        if(!reparamMeshVertexOnFace(v, (GFace *)entity, param, true, false))
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
  if(!_checkInit()) return;
  nodeTags.clear();
  coord.clear();
  parametricCoord.clear();
  std::vector<GEntity *> entities;
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    entities.push_back(ge);
  }
  else {
    GModel::current()->getEntities(entities, dim);
  }
  std::size_t numNodes = 0;
  for(auto ge : entities) numNodes += ge->mesh_vertices.size();
  nodeTags.reserve(numNodes);
  coord.reserve(numNodes * 3);
  if(dim > 0 && returnParametricCoord) parametricCoord.reserve(numNodes * dim);

  for(auto ge : entities) {
    for(auto v : ge->mesh_vertices) {
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
  if(!_checkInit()) return;
  nodeTags.clear();
  coord.clear();
  parametricCoord.clear();
  std::vector<GEntity *> entities;
  int dim = ElementType::getDimension(elementType);
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
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
    numElements += entities[i]->getNumMeshElementsByType(familyType);
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
                                         std::vector<double> &parametricCoord,
                                         int &dim, int &tag)
{
  if(!_checkInit()) return;
  MVertex *v = GModel::current()->getMeshVertexByTag(nodeTag);
  if(!v) {
    Msg::Error("Unknown node %d", nodeTag);
    return;
  }
  coord.resize(3);
  coord[0] = v->x();
  coord[1] = v->y();
  coord[2] = v->z();
  parametricCoord.reserve(2);
  double u;
  if(v->getParameter(0, u)) parametricCoord.push_back(u);
  if(v->getParameter(1, u)) parametricCoord.push_back(u);
  if(v->onWhat()) {
    dim = v->onWhat()->dim();
    tag = v->onWhat()->tag();
  }
  else {
    Msg::Warning("Node %d is not classified on any entity", nodeTag);
    dim = -1;
    tag = -1;
  }
}

GMSH_API void
gmsh::model::mesh::setNode(const std::size_t nodeTag,
                           const std::vector<double> &coord,
                           const std::vector<double> &parametricCoord)
{
  if(!_checkInit()) return;
  MVertex *v = GModel::current()->getMeshVertexByTag(nodeTag);
  if(!v) {
    Msg::Error("Unknown node %d", nodeTag);
    return;
  }
  if(coord.size() < 3) {
    Msg::Error("Less than three coordinates provided for node %d", nodeTag);
    return;
  }
  v->setXYZ(coord[0], coord[1], coord[2]);
  if(parametricCoord.size() >= 1) v->setParameter(0, parametricCoord[0]);
  if(parametricCoord.size() >= 2) v->setParameter(1, parametricCoord[1]);
}

GMSH_API void gmsh::model::mesh::rebuildNodeCache(bool onlyIfNecessary)
{
  if(!_checkInit()) return;
  GModel::current()->rebuildMeshVertexCache(onlyIfNecessary);
}

GMSH_API void gmsh::model::mesh::rebuildElementCache(bool onlyIfNecessary)
{
  if(!_checkInit()) return;
  GModel::current()->rebuildMeshElementCache(onlyIfNecessary);
}

GMSH_API void
gmsh::model::mesh::getNodesForPhysicalGroup(const int dim, const int tag,
                                            std::vector<std::size_t> &nodeTags,
                                            std::vector<double> &coord)
{
  if(!_checkInit()) return;
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

GMSH_API void gmsh::model::mesh::getMaxNodeTag(std::size_t &maxTag)
{
  if(!_checkInit()) return;
  maxTag = GModel::current()->getMaxVertexNumber();
}

GMSH_API void gmsh::model::mesh::addNodes(
  const int dim, const int tag, const std::vector<std::size_t> &nodeTags,
  const std::vector<double> &coord, const std::vector<double> &parametricCoord)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  int numNodeTags = nodeTags.size(), numNodes = nodeTags.size();
  if(!numNodeTags) { // this is allowed: we will assign new tags
    numNodes = coord.size() / 3;
  }
  if((int)coord.size() != 3 * numNodes) {
    Msg::Error("Wrong number of coordinates");
    return;
  }
  bool param = false;
  if(parametricCoord.size()) {
    if((int)parametricCoord.size() != dim * numNodes) {
      Msg::Error("Wrong number of parametric coordinates");
      return;
    }
    param = true;
  }
  for(int i = 0; i < numNodes; i++) {
    std::size_t tag = (numNodeTags ? nodeTags[i] : 0); // 0 = automatic tag
    double x = coord[3 * i];
    double y = coord[3 * i + 1];
    double z = coord[3 * i + 2];
    MVertex *vv = nullptr;
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
  if(!_checkInit()) return;
  GModel::current()->pruneMeshVertexAssociations();
}

GMSH_API void gmsh::model::mesh::relocateNodes(const int dim, const int tag)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  if(dim >= 0 && tag >= 0) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
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
      return;
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
      if(r->trihedra.size())
        typeEnt[r->trihedra.front()->getTypeForMSH()].push_back(ge);
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
  if(!_checkInit()) return;
  elementTypes.clear();
  elementTags.clear();
  nodeTags.clear();
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  for(auto it = typeEnt.begin(); it != typeEnt.end(); it++) {
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
                                            std::vector<std::size_t> &nodeTags,
                                            int &dim, int &tag)
{
  if(!_checkInit()) return;
  int entityTag;
  MElement *e = GModel::current()->getMeshElementByTag(elementTag, entityTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    return;
  }
  elementType = e->getTypeForMSH();
  nodeTags.clear();
  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    if(!v) {
      Msg::Error("Unknown node in element %d", elementTag);
      return;
    }
    nodeTags.push_back(v->getNum());
  }
  dim = e->getDim();
  tag = entityTag;
}

GMSH_API void gmsh::model::mesh::getElementByCoordinates(
  const double x, const double y, const double z, std::size_t &elementTag,
  int &elementType, std::vector<std::size_t> &nodeTags, double &u, double &v,
  double &w, const int dim, const bool strict)
{
  if(!_checkInit()) return;
  nodeTags.clear();
  SPoint3 xyz(x, y, z), uvw;
  MElement *e = GModel::current()->getMeshElementByCoord(xyz, uvw, dim, strict);
  if(!e) {
    elementTag = 0;
    elementType = 0;
    u = v = w = 0.;
    Msg::Error("No element found at (%g, %g, %g)", x, y, z);
    return;
  }
  elementTag = e->getNum();
  elementType = e->getTypeForMSH();
  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    if(!v) {
      Msg::Error("Unknown node in element %d", elementTag);
      return;
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
  if(!_checkInit()) return;
  SPoint3 xyz(x, y, z), uvw;
  elementTags.clear();
  std::vector<MElement *> e =
    GModel::current()->getMeshElementsByCoord(xyz, dim, strict);
  if(e.empty()) {
    Msg::Error("No element found at (%g, %g, %g)", x, y, z);
    return;
  }
  for(std::size_t i = 0; i < e.size(); i++) {
    elementTags.push_back(e[i]->getNum());
  }
}

GMSH_API void gmsh::model::mesh::getLocalCoordinatesInElement(
  const std::size_t elementTag, const double x, const double y, const double z,
  double &u, double &v, double &w)
{
  if(!_checkInit()) return;
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    return;
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
    return;
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
        return;
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
    else if(elements[0]->getType() == TYPE_TRIH)
      _addElements(dim, tag, elements, static_cast<GRegion *>(ge)->trihedra);
    else
      ok = false;
    break;
  }
  if(!ok)
    Msg::Error("Wrong type of element for %s",
               _getEntityName(dim, tag).c_str());
}

GMSH_API void gmsh::model::mesh::getMaxElementTag(std::size_t &maxTag)
{
  if(!_checkInit()) return;
  maxTag = GModel::current()->getMaxElementNumber();
}

GMSH_API void gmsh::model::mesh::addElements(
  const int dim, const int tag, const std::vector<int> &elementTypes,
  const std::vector<std::vector<std::size_t> > &elementTags,
  const std::vector<std::vector<std::size_t> > &nodeTags)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(elementTypes.size() != elementTags.size()) {
    Msg::Error("Wrong number of element tags");
    return;
  }
  if(elementTypes.size() != nodeTags.size()) {
    Msg::Error("Wrong number of node tags");
    return;
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
  if(!_checkInit()) return;
  int dim = ElementType::getDimension(elementType);
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  _addElements(dim, tag, ge, elementType, elementTags, nodeTags);
  GModel::current()->destroyMeshCaches();
}

GMSH_API void gmsh::model::mesh::getElementTypes(std::vector<int> &elementTypes,
                                                 const int dim, const int tag)
{
  if(!_checkInit()) return;
  elementTypes.clear();
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  for(auto it = typeEnt.begin(); it != typeEnt.end(); it++) {
    elementTypes.push_back(it->first);
  }
}

GMSH_API int gmsh::model::mesh::getElementType(const std::string &family,
                                               const int order,
                                               const bool serendip)
{
  if(!_checkInit()) return -1;
  int familyType =
    (family == "Point" || family == "point")             ? TYPE_PNT :
    (family == "Line" || family == "line")               ? TYPE_LIN :
    (family == "Triangle" || family == "triangle")       ? TYPE_TRI :
    (family == "Quadrangle" || family == "quadrangle")   ? TYPE_QUA :
    (family == "Tetrahedron" || family == "tetrahedron") ? TYPE_TET :
    (family == "Pyramid" || family == "pyramid")         ? TYPE_PYR :
    (family == "Prism" || family == "prism")             ? TYPE_PRI :
    (family == "Hexahedron" || family == "hexahedron")   ? TYPE_HEX :
    (family == "Polygon" || family == "polygon")         ? TYPE_POLYG :
    (family == "Polyhedron" || family == "polyhedron")   ? TYPE_POLYH :
    (family == "Trihedron" || family == "trihedron")     ? TYPE_TRIH :
                                                           -1;
  return ElementType::getType(familyType, order, serendip);
}

GMSH_API void gmsh::model::mesh::getElementProperties(
  const int elementType, std::string &name, int &dim, int &order, int &numNodes,
  std::vector<double> &localNodeCoord, int &numPrimaryNodes)
{
  if(!_checkInit()) return;
  const char *n;
  MElement::getInfoMSH(elementType, &n);
  name = n;
  int parentType = ElementType::getParentType(elementType);
  nodalBasis *basis = nullptr;
  if(parentType == TYPE_PYR)
    basis = new pyramidalBasis(elementType);
  else
    basis = new polynomialBasis(elementType);
  dim = basis->dimension;
  order = basis->order;
  numNodes = basis->points.size1();
  if(numNodes != ElementType::getNumVertices(elementType)) {
    Msg::Error("Size of basis incompatible with element type");
    return;
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
  if(!_checkInit()) return;
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
    return;
  }
  // check arrays
  bool haveElementTags = !elementTags.empty();
  bool haveNodeTags = !nodeTags.empty();
  if((!haveElementTags && !haveNodeTags) ||
     (haveElementTags && (elementTags.size() != numElements)) ||
     (haveNodeTags && (nodeTags.size() != numElements * numNodes))) {
    if(numTasks > 1)
      Msg::Warning("ElementTags and nodeTags should be preallocated "
                   "if numTasks > 1");
    haveElementTags = haveNodeTags = true;
    preallocateElementsByType(elementType, haveElementTags, haveNodeTags,
                              elementTags, nodeTags, tag);
  }
  const std::size_t begin = (task * numElements) / numTasks;
  const std::size_t end = ((task + 1) * numElements) / numTasks;
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
  if(!_checkInit()) return;
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

GMSH_API void gmsh::model::mesh::getElementQualities(
  const std::vector<std::size_t> &elementTags,
  std::vector<double> &elementQualities, const std::string &qualityName,
  const std::size_t task, const std::size_t numTasks)
{
  if(!_checkInit()) return;

  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    return;
  }

  std::size_t numElements = elementTags.size();
  bool haveElementQualities = elementQualities.size();
  if(!haveElementQualities ||
     (haveElementQualities && (elementQualities.size() < numElements))) {
    if(numTasks > 1)
      Msg::Warning("elementQualities should be preallocated "
                   "if numTasks > 1");
    haveElementQualities = true;
    elementQualities.clear();
    elementQualities.resize(numElements, 0.);
  }

  const std::size_t begin = (task * numElements) / numTasks;
  const std::size_t end = ((task + 1) * numElements) / numTasks;
  for(size_t k = begin; k < end; k++){
    MElement *e = GModel::current()->getMeshElementByTag(elementTags[k]);
    if(!e) {
      Msg::Error("Unknown element %d", elementTags[k]);
      elementQualities[k] = 0.;
      continue;
    }
    if(qualityName == "minSICN"){
      elementQualities[k] = e->minSICNShapeMeasure();
    }
    else if(qualityName == "minSIGE"){
      elementQualities[k] = e->minSIGEShapeMeasure();
    }
    else if(qualityName == "minSJ"){
      elementQualities[k] = e->distoShapeMeasure();
    }
    else if(qualityName == "gamma"){
      elementQualities[k] = e->gammaShapeMeasure();
    }
    else if(qualityName == "eta"){
      elementQualities[k] = e->etaShapeMeasure();
    }
    else if(qualityName == "minIsotropy"){
      elementQualities[k] = e->minIsotropyMeasure();
    }
    else if(qualityName == "angleShape"){
      elementQualities[k] = e->angleShapeMeasure();
    }
    else if(qualityName == "volume"){
      elementQualities[k] = e->getVolume();
    }
    else if(qualityName == "minEdge"){
      elementQualities[k] = e->minEdge();
    }
    else if(qualityName == "maxEdge"){
      elementQualities[k] = e->maxEdge();
    }
    else if(qualityName == "outerRadius"){
      elementQualities[k] = e->getOuterRadius();
    }
    else if(qualityName == "innerRadius"){
      elementQualities[k] = e->getInnerRadius();
    }
#if defined(HAVE_MESH)
    else if(qualityName == "minDetJac"){
      double min, max;
      jacobianBasedQuality::minMaxJacobianDeterminant(e, min, max);
      elementQualities[k] = min;
    }
    else if(qualityName == "maxDetJac"){
      double min, max;
      jacobianBasedQuality::minMaxJacobianDeterminant(e, min, max);
      elementQualities[k] = max;
    }
#endif
    else{
      if(k == begin) {
        Msg::Error("Unknown quality name '%s'", qualityName.c_str());
      }
      elementQualities[k] = 0.;
    }
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
  if(fsType.size() > 8 && fsType.substr(0,8) == "Lagrange") {
    fsName = "Lagrange";
    fsOrder = atoi(fsType.substr(8).c_str());
    fsComp = 1;
    return true;
  }
  if(fsType.size() > 12 && fsType.substr(0,12) == "GradLagrange") {
    fsName = "GradLagrange";
    fsOrder = atoi(fsType.substr(12).c_str());
    fsComp = 3;
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
  if(!_checkInit()) return;
  int numPoints = localCoord.size() / 3;
  if(!numPoints) {
    Msg::Warning("No evaluation points in getJacobians");
    return;
  }
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
    return;
  }

  // check arrays
  bool haveJacobians = !jacobians.empty();
  bool haveDeterminants = !determinants.empty();
  bool havePoints = !coord.empty();
  if((!haveDeterminants && !haveJacobians && !havePoints) ||
     (haveDeterminants && (numElements * numPoints != determinants.size())) ||
     (haveJacobians && (9 * numElements * numPoints != jacobians.size())) ||
     (havePoints && (3 * numElements * numPoints > coord.size()))) {
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
    const size_t begin = (task * numElements) / numTasks;
    const size_t end = ((task + 1) * numElements) / numTasks;
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
                 "and 'havePoints = %s' is not yet implemented",
                 (haveDeterminants ? "true" : "false"),
                 (haveJacobians ? "true" : "false"),
                 (havePoints ? "true" : "false"));
      return;
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
  if(!_checkInit()) return;
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
  if(!_checkInit()) return;
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e) {
    Msg::Error("Unknown element %d", elementTag);
    return;
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
    e->getGradShapeFunctions(localCoord[3 * k], localCoord[3 * k + 1],
                             localCoord[3 * k + 2], value);
    gsf[k].resize(e->getNumShapeFunctions());
    for(std::size_t l = 0; l < e->getNumShapeFunctions(); l++) {
      gsf[k][l][0] = value[l][0];
      gsf[k][l][1] = value[l][1];
      gsf[k][l][2] = value[l][2];
    }
  }
  for(int k = 0; k < numPoints; k++) {
    e->pnt(localCoord[3 * k], localCoord[3 * k + 1], localCoord[3 * k + 2],
           &coord[3 * k]);
    determinants[k] = e->getJacobian(gsf[k], &jacobians[9 * k]);
  }
}

GMSH_API void gmsh::model::mesh::getBasisFunctions(
  const int elementType, const std::vector<double> &localCoord,
  const std::string &functionSpaceType, int &numComponents,
  std::vector<double> &basisFunctions, int &numOrientations,
  const std::vector<int> &wantedOrientations)
{
  if(!_checkInit()) return;
  numComponents = 0;
  basisFunctions.clear();
  std::string fsName = "";
  int fsOrder = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, fsOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }

  const std::size_t numberOfGaussPoints = localCoord.size() / 3;
  const int familyType = ElementType::getParentType(elementType);

  if(fsName == "Lagrange" || fsName == "GradLagrange") { // Lagrange type
    // Check if there is no error in wantedOrientations
    if(wantedOrientations.size() != 0) {
      if(wantedOrientations.size() > 1) {
        Msg::Error("Asking for more orientation that there exist");
        return;
      }

      if(wantedOrientations[0] != 0) {
        Msg::Error(
          "Orientation %i does not exist for function stace named '%s' on %s",
          wantedOrientations[0], fsName.c_str(),
          ElementType::nameOfParentType(familyType, true).c_str());
        return;
      }
    }

    const nodalBasis *basis = nullptr;
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
    HierarchicalBasis *basis(nullptr);
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
      default:
        Msg::Error("Unknown familyType %i for basis function type %s",
                   familyType, fsName.c_str());
        return;
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
      default:
        Msg::Error("Unknown familyType %i for basis function type %s",
                   familyType, fsName.c_str());
        return;
      }
    }
    else {
      Msg::Error("Unknown function space named '%s'", fsName.c_str());
      return;
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
        Msg::Error("Asking for more orientation that there exist");
        return;
      }
      for(unsigned int i = 0; i < wantedOrientations.size(); ++i) {
        if(wantedOrientations[i] >= static_cast<int>(maxOrientation) ||
           wantedOrientations[i] < 0) {
          Msg::Error("Orientation %i does not exist for function stace named "
                     "'%s' on %s",
                     wantedOrientations[i], fsName.c_str(),
                     ElementType::nameOfParentType(familyType, true).c_str());
          return;
        }
      }
      std::vector<int> sortedWantedOrientations = wantedOrientations;
      std::sort(sortedWantedOrientations.begin(),
                sortedWantedOrientations.end());
      int previousInt = sortedWantedOrientations[0];
      for(unsigned int i = 1; i < sortedWantedOrientations.size(); ++i) {
        if(previousInt == sortedWantedOrientations[i]) {
          Msg::Error("Duplicate wanted orientation found");
          return;
        }
        previousInt = sortedWantedOrientations[i];
      }
    }

    std::vector<MVertex *> vertices(numVertices);
    for(unsigned int i = 0; i < numVertices; ++i) {
      vertices[i] = new MVertex(0., 0., 0., nullptr, i + 1);
    }
    MElement *element = nullptr;
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
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
          auto it = std::find(wantedOrientations.begin(),
                              wantedOrientations.end(), iOrientation);
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
            MEdge edgeSolin = element->getEdgeSolin(iEdge);
            const int orientationFlag =
              (edge.getMinVertex() != edgeSolin.getVertex(0)) ? -1 : 1;
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
          auto it = std::find(wantedOrientations.begin(),
                              wantedOrientations.end(), iOrientation);
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
            MEdge edgeSolin = element->getEdgeSolin(iEdge);
            const int orientationFlag =
              (edge.getMinVertex() != edgeSolin.getVertex(0) ? -1 : 1);
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

GMSH_API void gmsh::model::mesh::getBasisFunctionsOrientation(
  const int elementType, const std::string &functionSpaceType,
  std::vector<int> &basisFunctionsOrientation, const int tag,
  const std::size_t task, const std::size_t numTasks)
{
  if(!_checkInit()) return;

  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }

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

  if(basisFunctionsOrientation.empty() ||
     numElements != basisFunctionsOrientation.size()) {
    if(numTasks > 1) {
      Msg::Warning(
        "basisFunctionsOrientation should be preallocated if numTasks > 1");
    }
    preallocateBasisFunctionsOrientation(
      elementType, basisFunctionsOrientation, tag);
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
            if(vertices[j] != nullptr) {
              if(max < vertices[j]->getNum()) {
                max = vertices[j]->getNum();
                maxPos = j;
              }
            }
          }
          vertices[maxPos] = nullptr;
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

GMSH_API void gmsh::model::mesh::getBasisFunctionsOrientationForElement(
  const std::size_t elementTag, const std::string &functionSpaceType,
  int &basisFunctionsOrientation)
{
  if(!_checkInit()) return;

  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }

  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  int elementType = e->getTypeForMSH();
  int familyType = ElementType::getParentType(elementType);

  if(fsName == "Lagrange" || fsName == "GradLagrange") { // Lagrange type
    basisFunctionsOrientation = 0;
  }
  else { // Hierarchical type
    const unsigned int numVertices =
      ElementType::getNumVertices(ElementType::getType(familyType, 1, false));
    std::vector<MVertex *> vertices(numVertices);
    std::vector<unsigned int> verticesOrder(numVertices);
    const std::size_t factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

    for(std::size_t i = 0; i < numVertices; ++i) {
      vertices[i] = e->getVertex(i);
    }

    for(std::size_t i = 0; i < numVertices; ++i) {
      std::size_t max = 0;
      std::size_t maxPos = 0;
      for(std::size_t j = 0; j < numVertices; ++j) {
        if(vertices[j] != nullptr) {
          if(max < vertices[j]->getNum()) {
            max = vertices[j]->getNum();
            maxPos = j;
          }
        }
      }
      vertices[maxPos] = nullptr;
      verticesOrder[maxPos] = numVertices - i - 1;
    }

    basisFunctionsOrientation = 0;
    for(std::size_t i = 0; i < numVertices; ++i) {
      basisFunctionsOrientation +=
        verticesOrder[i] * factorial[numVertices - i - 1];
      for(std::size_t j = i + 1; j < numVertices; ++j) {
        if(verticesOrder[j] > verticesOrder[i]) --verticesOrder[j];
      }
    }
  }

  return;
}

GMSH_API int
gmsh::model::mesh::getNumberOfOrientations(const int elementType,
                                           const std::string &functionSpaceType)
{
  if(!_checkInit()) return -1;

  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return 0;
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
gmsh::model::mesh::preallocateBasisFunctionsOrientation(
  const int elementType, std::vector<int> &basisFunctionsOrientation,
  const int tag)
{
  if(!_checkInit()) return;

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
gmsh::model::mesh::getEdges(const std::vector<std::size_t> &nodeTags,
                            std::vector<std::size_t> &edgeTags,
                            std::vector<int> &edgeOrientations)
{
  edgeTags.clear();
  edgeOrientations.clear();
  std::size_t numEdges = nodeTags.size() / 2;
  if(!numEdges) return;
  edgeTags.resize(numEdges);
  edgeOrientations.resize(numEdges);
  for(std::size_t i = 0; i < numEdges; i++) {
    std::size_t n0 = nodeTags[2 * i];
    std::size_t n1 = nodeTags[2 * i + 1];
    MVertex *v0 = GModel::current()->getMeshVertexByTag(n0);
    MVertex *v1 = GModel::current()->getMeshVertexByTag(n1);
    if(v0 && v1) {
      MEdge edge;
      edgeTags[i] = GModel::current()->getMEdge(v0, v1, edge);
      if(edge.getMinVertex() == v0 && edge.getMaxVertex() == v1)
        edgeOrientations[i] = 1;
      else if(edge.getMaxVertex() == v0 && edge.getMinVertex() == v1)
        edgeOrientations[i] = -1;
      else
        edgeOrientations[i] = 0;
    }
    else {
      Msg::Error("Unknown mesh node %d or %d", n0, n1);
    }
  }
}

GMSH_API void gmsh::model::mesh::getFaces(
  const int faceType, const std::vector<std::size_t> &nodeTags,
  std::vector<std::size_t> &faceTags, std::vector<int> &orientations)
{
  faceTags.clear();
  orientations.clear();
  if(faceType != 3 && faceType != 4) {
    Msg::Error("Unknown face type (should be 3 or 4)");
    return;
  }
  std::size_t numFaces = nodeTags.size() / faceType;
  if(!numFaces) return;
  faceTags.resize(numFaces);
  orientations.resize(numFaces, 0); // TODO
  for(std::size_t i = 0; i < numFaces; i++) {
    std::size_t n0 = nodeTags[faceType * i];
    std::size_t n1 = nodeTags[faceType * i + 1];
    std::size_t n2 = nodeTags[faceType * i + 2];
    std::size_t n3 = (faceType == 4) ? nodeTags[faceType * i + 3] : 0;
    MVertex *v0 = GModel::current()->getMeshVertexByTag(n0);
    MVertex *v1 = GModel::current()->getMeshVertexByTag(n1);
    MVertex *v2 = GModel::current()->getMeshVertexByTag(n2);
    MVertex *v3 =
      (faceType == 4) ? GModel::current()->getMeshVertexByTag(n3) : nullptr;
    if(v0 && v1 && v2) {
      MFace face;
      faceTags[i] = GModel::current()->getMFace(v0, v1, v2, v3, face);
    }
    else {
      Msg::Error("Unknown mesh node %d, %d or %d", n0, n1, n2);
    }
  }
}

GMSH_API void gmsh::model::mesh::createEdges(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  for(GEntity *ge : entities) {
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      for(int k = 0; k < e->getNumEdges(); k++) {
        MEdge edge = e->getEdge(k);
        GModel::current()->addMEdge(std::move(edge));
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::createFaces(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  for(GEntity *ge : entities) {
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      for(int k = 0; k < e->getNumFaces(); k++) {
        MFace face = e->getFace(k);
        GModel::current()->addMFace(std::move(face));
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::getAllEdges(std::vector<std::size_t> &edgeTags,
                                             std::vector<std::size_t> &edgeNodes)
{
  if(!_checkInit()) return;
  GModel *m = GModel::current();
  edgeTags .clear(); edgeTags .reserve(m->getNumMEdges());
  edgeNodes.clear(); edgeNodes.reserve(m->getNumMEdges() * 2);
  for(auto it = m->firstMEdge(); it != m->lastMEdge(); ++it) {
    edgeTags.push_back(it->second);
    edgeNodes.push_back(it->first.getVertex(0)->getNum());
    edgeNodes.push_back(it->first.getVertex(1)->getNum());
  }
}

GMSH_API void gmsh::model::mesh::getAllFaces(const int faceType,
                                             std::vector<std::size_t> &faceTags,
                                             std::vector<std::size_t> &faceNodes)
{
  if(!_checkInit()) return;
  if(faceType != 3 && faceType != 4) {
    Msg::Error("Unknown face type (should be 3 or 4)");
    return;
  }
  faceTags.clear();
  faceNodes.clear();
  GModel *m = GModel::current();
  for(auto it = m->firstMFace(); it != m->lastMFace(); ++it) {
    if(faceType == (int)it->first.getNumVertices()) {
      faceTags.push_back(it->second);
      for(int j = 0; j < faceType; j++)
        faceNodes.push_back(it->first.getVertex(j)->getNum());
    }
  }
}

GMSH_API void gmsh::model::mesh::addEdges(const std::vector<std::size_t> &edgeTags,
                                          const std::vector<std::size_t> &edgeNodes)
{
  if(!_checkInit()) return;
  if(edgeTags.size() * 2 != edgeNodes.size()) {
    Msg::Error("Wrong number of edge nodes");
    return;
  }
  GModel *m = GModel::current();
  for(std::size_t i = 0; i < edgeTags.size(); i++) {
    MVertex *v[2];
    for(int j = 0; j < 2; j++) {
      v[j] = m->getMeshVertexByTag(edgeNodes[2 * i + j]);
      if(!v[j]) {
        Msg::Error("Unknown mesh node %lu", edgeNodes[2 * i + j]);
        return;
      }
    }
    MEdge e(v[0], v[1]);
    m->addMEdge(std::move(e), edgeTags[i]);
  }
}

GMSH_API void gmsh::model::mesh::addFaces(const int faceType,
                                          const std::vector<std::size_t> &faceTags,
                                          const std::vector<std::size_t> &faceNodes)
{
  if(!_checkInit()) return;
  if(faceType != 3 && faceType != 4) {
    Msg::Error("Unknown face type (should be 3 or 4)");
    return;
  }
  if(faceTags.size() * faceType != faceNodes.size()) {
    Msg::Error("Wrong number of face nodes");
    return;
  }
  GModel *m = GModel::current();
  for(std::size_t i = 0; i < faceTags.size(); i++) {
    MVertex *v[4] = {nullptr, nullptr, nullptr, nullptr};
    for(int j = 0; j < faceType; j++) {
      v[j] = m->getMeshVertexByTag(faceNodes[faceType * i + j]);
      if(!v[j]) {
        Msg::Error("Unknown mesh node %lu", faceNodes[faceType * i + j]);
        return;
      }
    }
    MFace f(v[0], v[1], v[2], v[3]);
    m->addMFace(std::move(f), faceTags[i]);
  }
}

GMSH_API void gmsh::model::mesh::getKeys(
  const int elementType, const std::string &functionSpaceType,
  std::vector<int> &typeKeys, std::vector<std::size_t> &entityKeys,
  std::vector<double> &coord, const int tag, const bool returnCoord)
{
  if(!_checkInit()) return;
  coord.clear();
  typeKeys.clear();
  entityKeys.clear();
  int order = 0;
  int numComponents = 0;
  std::string fsName = "";
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, order, numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);

  HierarchicalBasis *basis(nullptr);
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    const nodalBasis *nodalB(nullptr);
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
      if(returnCoord) {
        coord.reserve(coord.size() + numElementsInEntitie *
                                       nodalB->getNumShapeFunctions() * 3);
      }
      typeKeys.reserve(typeKeys.size() +
                       numElementsInEntitie * nodalB->getNumShapeFunctions());
      entityKeys.reserve(entityKeys.size() +
                         numElementsInEntitie * nodalB->getNumShapeFunctions());

      for(std::size_t j = 0; j < numElementsInEntitie; ++j) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        for(size_t k = 0; k < e->getNumVertices(); ++k) {
          typeKeys.push_back(0);
          entityKeys.push_back(e->getVertex(k)->getNum());
          if(returnCoord) {
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
    return;
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
    if(returnCoord) {
      coord.reserve(coord.size() +
                    numElementsInEntitie * numDofsPerElement * 3);
    }
    typeKeys.reserve(typeKeys.size() +
                     numElementsInEntitie * numDofsPerElement);
    entityKeys.reserve(entityKeys.size() +
                       numElementsInEntitie * numDofsPerElement);

    for(std::size_t j = 0; j < numElementsInEntitie; j++) {
      MElement *e = ge->getMeshElementByType(familyType, j);
      // vertices
      for(int k = 0; k < vSize; k++) {
        typeKeys.push_back(0);
        entityKeys.push_back(e->getVertex(k)->getNum());
        if(returnCoord) {
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
          if(returnCoord) {
            MVertex *v1 = edge.getVertex(0);
            MVertex *v2 = edge.getVertex(1);

            coordEdge[0] = 0.5 * (v1->x() + v2->x());
            coordEdge[1] = 0.5 * (v1->y() + v2->y());
            coordEdge[2] = 0.5 * (v1->z() + v2->z());
          }
          std::size_t edgeGlobalIndice = GModel::current()->addMEdge(std::move(edge));
          for(int k = 1; k < const1; k++) {
            typeKeys.push_back(k);
            entityKeys.push_back(edgeGlobalIndice);
            if(returnCoord) {
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
          if(returnCoord) {
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
          std::size_t faceGlobalIndice = GModel::current()->addMFace(std::move(face));
          int it2 = const2;
          if(jj >= numberQuadFaces) { it2 = const3; }
          for(int k = const1; k < it2; k++) {
            typeKeys.push_back(k);
            entityKeys.push_back(faceGlobalIndice);
            if(returnCoord) {
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
        if(returnCoord) {
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
          typeKeys.push_back(k);
          entityKeys.push_back(e->getNum());
          if(returnCoord) {
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
  const std::size_t elementTag, const std::string &functionSpaceType,
  std::vector<int> &typeKeys, std::vector<std::size_t> &entityKeys,
  std::vector<double> &coord, const bool returnCoord)
{
  if(!_checkInit()) return;
  coord.clear();
  typeKeys.clear();
  entityKeys.clear();
  int order = 0;
  int numComponents = 0;
  std::string fsName = "";
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, order, numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  int elementType = e->getTypeForMSH();
  int familyType = ElementType::getParentType(elementType);

  HierarchicalBasis *basis(nullptr);
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    typeKeys.reserve(e->getNumVertices());
    entityKeys.reserve(e->getNumVertices());
    if(returnCoord) { coord.reserve(3 * e->getNumVertices()); }
    for(size_t k = 0; k < e->getNumVertices(); ++k) {
      typeKeys.push_back(0);
      entityKeys.push_back(e->getVertex(k)->getNum());
      if(returnCoord) {
        coord.push_back(e->getVertex(k)->x());
        coord.push_back(e->getVertex(k)->y());
        coord.push_back(e->getVertex(k)->z());
      }
    }
    return;
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    return;
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
  int numDofsPerElement = vSize + bSize + eSize + fSize;
  delete basis;

  typeKeys.reserve(numDofsPerElement);
  entityKeys.reserve(numDofsPerElement);
  if(returnCoord) { coord.reserve(3 * numDofsPerElement); }

  // vertices
  for(int k = 0; k < vSize; k++) {
    typeKeys.push_back(0);
    entityKeys.push_back(e->getVertex(k)->getNum());
    if(returnCoord) {
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
      if(returnCoord) {
        MVertex *v1 = edge.getVertex(0);
        MVertex *v2 = edge.getVertex(1);

        coordEdge[0] = 0.5 * (v1->x() + v2->x());
        coordEdge[1] = 0.5 * (v1->y() + v2->y());
        coordEdge[2] = 0.5 * (v1->z() + v2->z());
      }
      std::size_t edgeGlobalIndice = GModel::current()->addMEdge(std::move(edge));
      for(int k = 1; k < const1; k++) {
        typeKeys.push_back(k);
        entityKeys.push_back(edgeGlobalIndice);
        if(returnCoord) {
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
      if(returnCoord) {
        for(std::size_t indexV = 0; indexV < face.getNumVertices(); ++indexV) {
          coordFace[0] += face.getVertex(indexV)->x();
          coordFace[1] += face.getVertex(indexV)->y();
          coordFace[2] += face.getVertex(indexV)->z();
        }
        coordFace[0] /= face.getNumVertices();
        coordFace[1] /= face.getNumVertices();
        coordFace[2] /= face.getNumVertices();
      }
      std::size_t faceGlobalIndice = GModel::current()->addMFace(std::move(face));
      int it2 = const2;
      if(jj >= numberQuadFaces) { it2 = const3; }
      for(int k = const1; k < it2; k++) {
        typeKeys.push_back(k);
        entityKeys.push_back(faceGlobalIndice);
        if(returnCoord) {
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
    if(returnCoord) {
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
      typeKeys.push_back(k);
      entityKeys.push_back(e->getNum());
      if(returnCoord) {
        coord.push_back(bubbleCenterCoord[0]);
        coord.push_back(bubbleCenterCoord[1]);
        coord.push_back(bubbleCenterCoord[2]);
      }
    }
  }
}

GMSH_API int gmsh::model::mesh::getNumberOfKeys(
  const int elementType, const std::string &functionSpaceType)
{
  int numberOfKeys = 0;
  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return 0;
  }
  int familyType = ElementType::getParentType(elementType);
  if(fsName == "H1Legendre" || fsName == "GradH1Legendre") {
    HierarchicalBasis *basis(nullptr);
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return 0;
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
    HierarchicalBasis *basis(nullptr);
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return 0;
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
    const nodalBasis *basis(nullptr);
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
    return 0;
  }

  return numberOfKeys;
}

GMSH_API void gmsh::model::mesh::getKeysInformation(
  const std::vector<int> &typeKeys, const std::vector<std::size_t> &entityKeys,
  const int elementType, const std::string &functionSpaceType,
  gmsh::vectorpair &infoKeys)
{
  infoKeys.clear();
  int basisOrder = 0;
  std::string fsName = "";
  int numComponents = 0;
  if(!_getFunctionSpaceInfo(functionSpaceType, fsName, basisOrder,
                            numComponents)) {
    Msg::Error("Unknown function space type '%s'", functionSpaceType.c_str());
    return;
  }

  if(typeKeys.size() != entityKeys.size()) {
    Msg::Error("The size of 'typeKeys' is different from the size of "
               "'entityKeys' ('%i', '%i')",
               typeKeys.size(), entityKeys.size());
    return;
  }

  HierarchicalBasis *basis(nullptr);
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
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
    default:
      Msg::Error("Unknown familyType %i for basis function type %s", familyType,
                 fsName.c_str());
      return;
    }
  }
  else if(fsName == "IsoParametric" || fsName == "Lagrange" ||
          fsName == "GradIsoParametric" || fsName == "GradLagrange") {
    const nodalBasis *basis(nullptr);
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

    if(numberOfBubble > numberOfKeys) {
      Msg::Error("Number of bubble functions greater than number of keys");
      return;
    }

    infoKeys.reserve(typeKeys.size());
    for(size_t i = 0; i < typeKeys.size() / numberOfKeys; ++i) {
      for(size_t j = 0; j < numberOfKeys - numberOfBubble; ++j) {
        infoKeys.push_back(std::make_pair(0, basisOrder));
      }
      for(size_t j = 0; j < numberOfBubble; ++j) {
        infoKeys.push_back(std::make_pair(dim, basisOrder));
      }
    }
    return;
  }
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    return;
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
  std::size_t keySize = typeKeys.size();
  if(!keySize) return;
  infoKeys.resize(keySize);
  std::size_t it = keySize / numDofsPerElement;
  for(std::size_t i = 0; i < it; i++) {
    size_t const1 = i * numDofsPerElement;
    for(int j = 0; j < numDofsPerElement; j++) {
      infoKeys[const1 + j] =
        std::make_pair(functionTypeInfo[j], orderInfo[j]);
    }
  }
}

GMSH_API void gmsh::model::mesh::getBarycenters(
  const int elementType, const int tag, const bool fast, const bool primary,
  std::vector<double> &barycenters, const std::size_t task,
  const std::size_t numTasks)
{
  if(!_checkInit()) return;
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
    return;
  }
  if(!numElements) return;

  if(3 * numElements != barycenters.size()) {
    if(numTasks > 1)
      Msg::Warning("Barycenters should be preallocated if numTasks > 1");
    barycenters.resize(3 * numElements);
  }

  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
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
  if(intType.substr(0, 14) == "CompositeGauss") {
    intName = "CompositeGauss";
    intOrder = atoi(intType.substr(14).c_str());
    return true;
  }
  else if(intType.substr(0, 5) == "Gauss") {
    intName = "Gauss";
    intOrder = atoi(intType.substr(5).c_str());
    return true;
  }
  return false;
}

GMSH_API void gmsh::model::mesh::getIntegrationPoints(
  const int elementType, const std::string &integrationType,
  std::vector<double> &localCoord, std::vector<double> &weights)
{
  if(!_checkInit()) return;
  localCoord.clear();
  weights.clear();
  std::string intName = "";
  int intOrder = 0;
  if(!_getIntegrationInfo(integrationType, intName, intOrder)) {
    Msg::Error("Unknown quadrature type '%s'", integrationType.c_str());
    return;
  }
  // get quadrature info
  int familyType = ElementType::getParentType(elementType);
  fullMatrix<double> pts;
  fullVector<double> wgs;
  gaussIntegration::get(familyType, intOrder, pts, wgs,
                        intName == "Gauss" ? false : true);
  if(pts.size1() != wgs.size() || pts.size2() != 3) {
    Msg::Error("Wrong integration point format");
    return;
  }
  localCoord.resize(3 * pts.size1());
  weights.resize(pts.size1());
  for(int i = 0; i < pts.size1(); i++) {
    localCoord[3 * i] = pts(i, 0);
    localCoord[3 * i + 1] = pts(i, 1);
    localCoord[3 * i + 2] = pts(i, 2);
    weights[i] = wgs(i);
  }
}

GMSH_API void gmsh::model::mesh::preallocateBarycenters(
  const int elementType, std::vector<double> &barycenters, const int tag)
{
  if(!_checkInit()) return;
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  std::size_t numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += entities[i]->getNumMeshElementsByType(familyType);
  barycenters.clear();
  if(!numElements) return;
  barycenters.resize(3 * numElements, 0);
}

GMSH_API void gmsh::model::mesh::getElementEdgeNodes(
  const int elementType, std::vector<std::size_t> &nodeTags, const int tag,
  const bool primary, const std::size_t task, const std::size_t numTasks)
{
  if(!_checkInit()) return;
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
      MElement *e = ge->getMeshElementByType(familyType, 0);
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
    return;
  }
  if(!numElements || !numEdgesPerEle || !numNodesPerEdge) return;
  if(numEdgesPerEle * numNodesPerEdge * numElements != nodeTags.size()) {
    if(numTasks > 1)
      Msg::Warning("Nodes should be preallocated if numTasks > 1");
    nodeTags.resize(numEdgesPerEle * numNodesPerEdge * numElements);
  }
  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
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
  if(!_checkInit()) return;
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
      MElement *e = ge->getMeshElementByType(familyType, 0);
      int nf = e->getNumFaces();
      numFacesPerEle = 0;
      for(int k = 0; k < nf; k++) {
        MFace f = e->getFace(k);
        if(faceType == (int)f.getNumVertices()) {
          numFacesPerEle++;
          if(!numNodesPerFace) {
            if(primary) { numNodesPerFace = faceType; }
            else {
              std::vector<MVertex *> v;
              // we could use e->getHighOrderFace() here if we decide to remove
              // getFaceVertices
              e->getFaceVertices(k, v);
              numNodesPerFace = v.size();
            }
          }
        }
      }
    }
    numElements += n;
  }

  if(!numTasks) {
    Msg::Error("Number of tasks should be > 0");
    return;
  }
  if(!numElements || !numFacesPerEle || !numNodesPerFace) return;
  if(numFacesPerEle * numNodesPerFace * numElements > nodeTags.size()) {
    if(numTasks > 1)
      Msg::Warning("Nodes should be preallocated if numTasks > 1");
    nodeTags.resize(numFacesPerEle * numNodesPerFace * numElements);
  }
  const size_t begin = (task * numElements) / numTasks;
  const size_t end = ((task + 1) * numElements) / numTasks;
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
  if(!_checkInit()) return;
  elementTags.clear();
  partitions.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  std::map<MElement *, int> ghostCells;
  if(ge->geomType() == GEntity::GhostCurve)
    ghostCells = static_cast<ghostEdge *>(ge)->getGhostCells();
  else if(ge->geomType() == GEntity::GhostSurface)
    ghostCells = static_cast<ghostFace *>(ge)->getGhostCells();
  else if(ge->geomType() == GEntity::GhostVolume)
    ghostCells = static_cast<ghostRegion *>(ge)->getGhostCells();

  for(auto it = ghostCells.begin(); it != ghostCells.end(); it++) {
    elementTags.push_back(it->first->getNum());
    partitions.push_back(it->second);
  }
}

GMSH_API void gmsh::model::mesh::setSize(const vectorpair &dimTags,
                                         const double size)
{
  if(!_checkInit()) return;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 0) {
      GVertex *gv = GModel::current()->getVertexByTag(tag);
      if(gv) gv->setPrescribedMeshSizeAtVertex(size);
    }
  }
}

GMSH_API void gmsh::model::mesh::getSizes(const vectorpair &dimTags,
                                          std::vector<double> &sizes)
{
  if(!_checkInit()) return;
  sizes.clear();
  if(dimTags.empty()) return;
  sizes.resize(dimTags.size(), 0.);
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 0) {
      GVertex *gv = GModel::current()->getVertexByTag(tag);
      if(gv) {
        double s = gv->prescribedMeshSizeAtVertex();
        if(s != MAX_LC) sizes[i] = s;
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::setSizeAtParametricPoints(
  const int dim, const int tag, const std::vector<double> &parametricCoord,
  const std::vector<double> &sizes)
{
  if(!_checkInit()) return;
  if(dim == 1) {
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(ge) ge->setMeshSizeParametric(parametricCoord, sizes);
  }
}

GMSH_API void gmsh::model::mesh::setSizeCallback(
  std::function<double(int, int, double, double, double, double)> callback)
{
  if(!_checkInit()) return;
  GModel::current()->lcCallback = callback;
}

GMSH_API void gmsh::model::mesh::removeSizeCallback()
{
  if(!_checkInit()) return;
  GModel::current()->lcCallback = nullptr;
}

GMSH_API void
gmsh::model::mesh::setTransfiniteCurve(const int tag, const int numNodes,
                                       const std::string &meshType,
                                       const double coef)
{
  if(!_checkInit()) return;
  // for compatibility with geo files, try both tag and -tag
  for(int sig = -1; sig <= 1; sig += 2) {
    int t = sig * tag;
    GEdge *ge = GModel::current()->getEdgeByTag(t);
    if(ge) {
      ge->meshAttributes.method = MESH_TRANSFINITE;
      ge->meshAttributes.nbPointsTransfinite = numNodes;
      ge->meshAttributes.typeTransfinite =
        (meshType == "Progression" || meshType == "Power") ? 1 :
        (meshType == "Bump")                               ? 2 :
        (meshType == "Beta")                               ? 3 :
        (meshType == "Progression_HWall")                  ? 5 :
        (meshType == "Bump_HWall")                         ? 6 :
        (meshType == "Beta_HWall")                         ? 7 :
                                                             1;
      ge->meshAttributes.coeffTransfinite =  ge->meshAttributes.typeTransfinite > 4 ? coef : std::abs(coef);
      // in .geo file we use a negative tag to do this trick; it's a bad idea
      if(coef < 0 && ge->meshAttributes.typeTransfinite < 4) ge->meshAttributes.typeTransfinite *= -1;
    }
    else {
      if(t > 0) {
        Msg::Error("%s does not exist", _getEntityName(1, t).c_str());
        return;
      }
    }
  }
}

GMSH_API void
gmsh::model::mesh::setTransfiniteSurface(const int tag,
                                         const std::string &arrangement,
                                         const std::vector<int> &cornerTags)
{
  if(!_checkInit()) return;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf) {
    Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
    return;
  }
  gf->meshAttributes.method = MESH_TRANSFINITE;
  gf->meshAttributes.transfiniteArrangement =
    (arrangement == "Right")          ? 1 :
    (arrangement == "Left")           ? -1 :
    (arrangement == "AlternateRight") ? 2 :
    (arrangement == "AlternateLeft")  ? -2 :
    (arrangement == "Alternate")      ? 2 :
                                        -1;
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
  if(!_checkInit()) return;
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr) {
    Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
    return;
  }
  gr->meshAttributes.method = MESH_TRANSFINITE;
  if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8) {
    for(std::size_t i = 0; i < cornerTags.size(); i++) {
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[i]);
      if(gv) gr->meshAttributes.corners.push_back(gv);
    }
  }
}

int _eulerCharacteristic(GRegion *gr)
{
  std::set<GVertex *> vertices;
  std::set<GEdge *> edges;
  for(std::size_t _i = 0; _i < gr->faces().size(); ++_i) {
    GFace *gf = gr->faces()[_i];
    for(std::size_t j = 0; j < gf->edges().size(); ++j) {
      GEdge *ge = gf->edges()[j];
      edges.insert(ge);
      vertices.insert(ge->getBeginVertex());
      vertices.insert(ge->getEndVertex());
    }
  }
  int X = int(vertices.size()) - int(edges.size()) + int(gr->faces().size());
  return X;
}

GMSH_API void gmsh::model::mesh::setTransfiniteAutomatic(
  const vectorpair &dimTags, const double cornerAngle, const bool recombine)
{
#if defined(HAVE_MESH)
  if(!_checkInit()) return;
  Msg::Debug("setTransfiniteAutomatic() with cornerAngle=%.3f, recombine=%i",
             cornerAngle, int(recombine));

  // Collect all quad 4-sided faces (from given faces and volumes)
  std::set<GFace *> faces;
  if(dimTags.size() == 0) { // Empty dimTag => all faces
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities, 2);
    for(std::size_t i = 0; i < entities.size(); i++) {
      GFace *gf = static_cast<GFace *>(entities[i]);
      if(gf->edges().size() == 4) { faces.insert(gf); }
    }
  }
  else {
    for(std::size_t i = 0; i < dimTags.size(); ++i) {
      if(dimTags[i].first == 2) {
        int tag = dimTags[i].second;
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(!gf) {
          Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
          return;
        }
        if(gf->edges().size() == 4) { faces.insert(gf); }
      }
      else if(dimTags[i].first == 3) {
        int tag = dimTags[i].second;
        GRegion *gr = GModel::current()->getRegionByTag(tag);
        if(!gr) {
          Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
          return;
        }
        for(GFace *gf : gr->faces()) {
          if(gf->edges().size() == 4) { faces.insert(gf); }
        }
      }
    }
  }

  // Build the chords, compute the averaged number of points on each chord,
  // assign the transfinite attributes
  bool okf = MeshSetTransfiniteFacesAutomatic(faces, cornerAngle, recombine);
  if(!okf) {
    Msg::Error("failed to automatically set transfinite faces");
    return;
  }

  // Collect the 6-sided volumes with Euler characteristic equal to 2 (ie ball)
  std::set<GRegion *> regions;
  if(dimTags.size() == 0) { // Empty dimTag => all faces
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities, 3);
    for(std::size_t i = 0; i < entities.size(); i++) {
      GRegion *gr = static_cast<GRegion *>(entities[i]);
      if(gr->faces().size() == 6 && _eulerCharacteristic(gr) == 2) {
        regions.insert(gr);
      }
    }
  }
  else {
    for(std::size_t i = 0; i < dimTags.size(); ++i) {
      if(dimTags[i].first == 3) {
        int tag = dimTags[i].second;
        GRegion *gr = GModel::current()->getRegionByTag(tag);
        if(!gr) {
          Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
          return;
        }
        if(gr->faces().size() == 6 && _eulerCharacteristic(gr) == 2) {
          regions.insert(gr);
        }
      }
    }
  }

  std::size_t nr = 0;
  for(GRegion *gr : regions) {
    bool transfinite = true;
    for(GFace *gf : gr->faces()) {
      if(gf->meshAttributes.method != MESH_TRANSFINITE) {
        transfinite = false;
        break;
      }
    }
    if(transfinite) {
      gr->meshAttributes.method = MESH_TRANSFINITE;
      nr += 1;
    }
  }
  if(nr > 0)
    Msg::Debug("transfinite automatic: transfinite set on %li volumes", nr);
#else
  Msg::Error("setTransfiniteAutomatic requires the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::setRecombine(const int dim, const int tag,
                                              const double angle)
{
  if(!_checkInit()) return;
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    gf->meshAttributes.recombine = 1;
    gf->meshAttributes.recombineAngle = angle;
  }
}

GMSH_API void gmsh::model::mesh::setSmoothing(const int dim, const int tag,
                                              const int val)
{
  if(!_checkInit()) return;
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    gf->meshAttributes.transfiniteSmoothing = val;
  }
}

GMSH_API void gmsh::model::mesh::setReverse(const int dim, const int tag,
                                            const bool val)
{
  if(!_checkInit()) return;
  if(dim == 1) {
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    ge->meshAttributes.reverseMesh = val;
  }
  else if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    gf->meshAttributes.reverseMesh = val;
  }
}

GMSH_API void gmsh::model::mesh::setAlgorithm(const int dim, const int tag,
                                              const int val)
{
  if(!_checkInit()) return;
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    gf->meshAttributes.algorithm = val;
  }
}

GMSH_API void gmsh::model::mesh::setSizeFromBoundary(const int dim,
                                                     const int tag,
                                                     const int val)
{
  if(!_checkInit()) return;
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
      return;
    }
    gf->meshAttributes.meshSizeFromBoundary = val;
  }
}

GMSH_API void gmsh::model::mesh::setCompound(const int dim,
                                             const std::vector<int> &tags)
{
  if(!_checkInit()) return;
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
  if(!_checkInit()) return;
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr) {
    Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
    return;
  }
  gr->setOutwardOrientationMeshConstraint();
}

GMSH_API void gmsh::model::mesh::removeConstraints(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    entities[i]->resetMeshAttributes();
}

GMSH_API void gmsh::model::mesh::embed(const int dim,
                                       const std::vector<int> &tags,
                                       const int inDim, const int inTag)
{
  if(!_checkInit()) return;
  if(inDim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(inTag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(2, inTag).c_str());
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++) {
      if(dim == 0) {
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv) {
          Msg::Error("%s does not exist", _getEntityName(0, tags[i]).c_str());
          return;
        }
        gf->addEmbeddedVertex(gv);
      }
      else if(dim == 1) {
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge) {
          Msg::Error("%s does not exist", _getEntityName(1, tags[i]).c_str());
          return;
        }
        gf->addEmbeddedEdge(ge);
      }
    }
  }
  else if(inDim == 3) {
    GRegion *gr = GModel::current()->getRegionByTag(inTag);
    if(!gr) {
      Msg::Error("%s does not exist", _getEntityName(3, inTag).c_str());
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++) {
      if(dim == 0) {
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv) {
          Msg::Error("%s does not exist", _getEntityName(0, tags[i]).c_str());
          return;
        }
        gr->addEmbeddedVertex(gv);
      }
      else if(dim == 1) {
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge) {
          Msg::Error("%s does not exist", _getEntityName(1, tags[i]).c_str());
          return;
        }
        gr->addEmbeddedEdge(ge);
      }
      else if(dim == 2) {
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(!gf) {
          Msg::Error("%s does not exist", _getEntityName(2, tags[i]).c_str());
          return;
        }
        gr->addEmbeddedFace(gf);
      }
    }
  }
}

GMSH_API void gmsh::model::mesh::removeEmbedded(const vectorpair &dimTags,
                                                const int rdim)
{
  if(!_checkInit()) return;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 2) {
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(!gf) {
        Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
        return;
      }
      if(rdim < 0 || rdim == 1) gf->embeddedEdges().clear();
      if(rdim < 0 || rdim == 0) gf->embeddedVertices().clear();
    }
    else if(dimTags[i].first == 3) {
      GRegion *gr = GModel::current()->getRegionByTag(tag);
      if(!gr) {
        Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
        return;
      }
      if(rdim < 0 || rdim == 2) gr->embeddedFaces().clear();
      if(rdim < 0 || rdim == 1) gr->embeddedEdges().clear();
      if(rdim < 0 || rdim == 0) gr->embeddedVertices().clear();
    }
  }
}

GMSH_API void gmsh::model::mesh::getEmbedded(const int dim, const int tag,
                                             vectorpair &dimTags)
{
  if(!_checkInit()) return;
  dimTags.clear();
  if(dim == 2) {
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf) {
      Msg::Error("%s does not exist", _getEntityName(2, tag).c_str());
      return;
    }
    for(auto v : gf->embeddedVertices())
      dimTags.push_back(std::make_pair(v->dim(), v->tag()));
    for(auto e : gf->embeddedEdges())
      dimTags.push_back(std::make_pair(e->dim(), e->tag()));
  }
  else if(dim == 3) {
    GRegion *gr = GModel::current()->getRegionByTag(tag);
    if(!gr) {
      Msg::Error("%s does not exist", _getEntityName(3, tag).c_str());
      return;
    }
    for(auto v : gr->embeddedVertices())
      dimTags.push_back(std::make_pair(v->dim(), v->tag()));
    for(auto e : gr->embeddedEdges())
      dimTags.push_back(std::make_pair(e->dim(), e->tag()));
    for(auto f : gr->embeddedFaces())
      dimTags.push_back(std::make_pair(f->dim(), f->tag()));
  }
}

GMSH_API void
gmsh::model::mesh::reorderElements(const int elementType, const int tag,
                                   const std::vector<std::size_t> &ordering)
{
  if(!_checkInit()) return;
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *> > typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  if(entities.empty()) {
    Msg::Error("No elements to reorder");
    return;
  }
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(!entities[i]->reorder(elementType, ordering)) {
      Msg::Error("Could not reorder elements");
      return;
    }
  }
}

GMSH_API void gmsh::model::mesh::computeRenumbering
  (std::vector<std::size_t> &oldTags,
   std::vector<std::size_t> &newTags,
   const std::string &method,
   const std::vector<std::size_t> &elementTags)
{
  std::map<std::size_t, std::size_t> remap;
#if defined(HAVE_MESH)
  if(method == "RCMK")
    meshRenumber_Vertices_RCMK(elementTags, remap);
  else if(method == "Hilbert")
    meshRenumber_Vertices_Hilbert(elementTags, remap);
  else if(method == "Metis")
    meshRenumber_Vertices_Metis(elementTags, remap);
  else
    Msg::Error("Unknown renumbering method %s", method.c_str());
#else
  Msg::Error("Computing renumbering requires the mesh module");
#endif
  oldTags.reserve(remap.size());
  newTags.reserve(remap.size());
  for(auto r : remap) {
    oldTags.push_back(r.first);
    newTags.push_back(r.second);
  }
}

GMSH_API void gmsh::model::mesh::renumberNodes
  (const std::vector<std::size_t> &oldTags,
   const std::vector<std::size_t> &newTags)
{
  if(!_checkInit()) return;
  if(oldTags.size() != newTags.size()) {
    Msg::Error("Invalid number of tags for node renumbering: %lu != %lu",
               oldTags.size(), newTags.size());
    return;
  }
  std::map<std::size_t, std::size_t> remap;
  for(std::size_t i = 0; i < oldTags.size(); i++)
    remap[oldTags[i]] = newTags[i];
  GModel::current()->renumberMeshVertices(remap);
}

GMSH_API void gmsh::model::mesh::renumberElements
  (const std::vector<std::size_t> &oldTags,
   const std::vector<std::size_t> &newTags)
{
  if(!_checkInit()) return;
  if(oldTags.size() != newTags.size()) {
    Msg::Error("Invalid number of tags for element renumbering: %lu != %lu",
               oldTags.size(), newTags.size());
    return;
  }
  std::map<std::size_t, std::size_t> remap;
  for(std::size_t i = 0; i < oldTags.size(); i++)
    remap[oldTags[i]] = newTags[i];
  GModel::current()->renumberMeshElements(remap);
}

GMSH_API void
gmsh::model::mesh::setPeriodic(const int dim, const std::vector<int> &tags,
                               const std::vector<int> &tagsMaster,
                               const std::vector<double> &affineTransform)
{
  if(!_checkInit()) return;
  if(tags.size() != tagsMaster.size()) {
    Msg::Error("Incompatible number of tags and master tags for periodic mesh");
    return;
  }
  if(affineTransform.size() != 16) {
    Msg::Error("Wrong number of elements in affine transformation (%d != 16)",
               (int)affineTransform.size());
    return;
  }
  for(std::size_t i = 0; i < tags.size(); i++) {
    if(dim == 1) {
      GEdge *target = GModel::current()->getEdgeByTag(tags[i]);
      if(!target) {
        Msg::Error("%s does not exist", _getEntityName(dim, tags[i]).c_str());
        return;
      }
      GEdge *source = GModel::current()->getEdgeByTag(tagsMaster[i]);
      if(!source) {
        Msg::Error("%s does not exist",
                   _getEntityName(dim, tagsMaster[i]).c_str());
        return;
      }
      target->setMeshMaster(source, affineTransform);
    }
    else if(dim == 2) {
      GFace *target = GModel::current()->getFaceByTag(tags[i]);
      if(!target) {
        Msg::Error("%s does not exist", _getEntityName(dim, tags[i]).c_str());
        return;
      }
      GFace *source = GModel::current()->getFaceByTag(tagsMaster[i]);
      if(!source) {
        Msg::Error("%s does not exist",
                   _getEntityName(dim, tagsMaster[i]).c_str());
        return;
      }
      target->setMeshMaster(source, affineTransform);
    }
  }
}

GMSH_API void
gmsh::model::mesh::getPeriodic(const int dim, const std::vector<int> &tags,
                               std::vector<int> &tagsMaster)
{
  if(!_checkInit()) return;
  tagsMaster.clear();
  tagsMaster.reserve(tags.size());
  for(auto i : tags) {
    GEntity *ge = GModel::current()->getEntityByTag(dim, i);
    if(!ge) {
      Msg::Error("%s does not exist", _getEntityName(dim, i).c_str());
      return;
    }
    tagsMaster.push_back(ge->getMeshMaster()->tag());
  }
}

GMSH_API void gmsh::model::mesh::getPeriodicNodes(
  const int dim, const int tag, int &tagMaster,
  std::vector<std::size_t> &nodeTags, std::vector<std::size_t> &nodeTagsMaster,
  std::vector<double> &affineTransform, const bool includeHighOrderNodes)
{
  if(!_checkInit()) return;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(ge->getMeshMaster() != ge) {
    tagMaster = ge->getMeshMaster()->tag();
    for(auto it = ge->correspondingVertices.begin();
        it != ge->correspondingVertices.end(); ++it) {
      nodeTags.push_back(it->first->getNum());
      nodeTagsMaster.push_back(it->second->getNum());
    }
    if(includeHighOrderNodes) {
      for(auto it = ge->correspondingHighOrderVertices.begin();
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

GMSH_API void gmsh::model::mesh::getPeriodicKeys(
  const int elementType, const std::string &functionSpaceType,
  const int tag, int &tagMaster,
  std::vector<int> &typeKeys, std::vector<int> &typeKeysMaster,
  std::vector<std::size_t> &entityKeys, std::vector<std::size_t> &entityKeysMaster,
  std::vector<double> &coord, std::vector<double> &coordMaster,
  const bool returnCoord)
{
  if(!_checkInit()) return;
  int dim = ElementType::getDimension(elementType);
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) {
    Msg::Error("%s does not exist", _getEntityName(dim, tag).c_str());
    return;
  }
  if(ge->getMeshMaster() == ge) { // not periodic
    tagMaster = tag;
    typeKeys.clear();
    typeKeysMaster.clear();
    entityKeys.clear();
    entityKeysMaster.clear();
    return;
  }

  tagMaster = ge->getMeshMaster()->tag();
  getKeys(elementType, functionSpaceType,
          typeKeys, entityKeys, coord, tag, returnCoord);
  typeKeysMaster = typeKeys;
  entityKeysMaster = entityKeys;
  coordMaster = coord;

  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  if(functionSpaceType == "IsoParametric" ||
     functionSpaceType == "Lagrange") {
#pragma omp parallel for num_threads(nthreads)
    for(std::size_t i = 0; i < entityKeys.size(); i++) {
      MVertex *v = GModel::current()->getMeshVertexByTag(entityKeys[i]);
      if(!v) {
        Msg::Warning("Unknown node %d", entityKeys[i]);
      }
      else {
        auto mv = ge->correspondingVertices.find(v);
        if(mv != ge->correspondingVertices.end()) {
          entityKeysMaster[i] = mv->second->getNum();
          if(returnCoord) {
            coord[3 * i] = mv->second->x();
            coord[3 * i + 1] = mv->second->y();
            coord[3 * i + 2] = mv->second->z();
          }
        }
        else {
          auto mv2 = ge->correspondingHighOrderVertices.find(v);
          if(mv2 != ge->correspondingHighOrderVertices.end()) {
            entityKeysMaster[i] = mv2->second->getNum();
            if(returnCoord) {
              coord[3 * i] = mv2->second->x();
              coord[3 * i + 1] = mv2->second->y();
              coord[3 * i + 2] = mv2->second->z();
            }
          }
          else{
            Msg::Warning("Unknown master node corresponding to node %d",
                         entityKeys[i]);
          }
        }
      }
    }
  }
  else{
    Msg::Error("Periodic key generation currently only available for "
               "\"IsoParametric\" and \"Lagrange\" function spaces");
  }
}

GMSH_API void gmsh::model::mesh::getDuplicateNodes(std::vector<std::size_t> &nodeTags,
                                                   const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  GModel *m = GModel::current();
  SBoundingBox3d bbox = m->bounds();
  double lc = bbox.empty() ? 1. : bbox.diag();
  double eps = lc * CTX::instance()->geom.tolerance;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  std::vector<MVertex *> vertices;
  for(std::size_t i = 0; i < entities.size(); i++) {
    vertices.insert(vertices.end(), entities[i]->mesh_vertices.begin(),
                    entities[i]->mesh_vertices.end());
  }
  MVertexRTree pos(eps);
  std::set<MVertex *, MVertexPtrLessThan> duplicates;
  pos.insert(vertices, true, &duplicates);
  for(auto n : duplicates) nodeTags.push_back(n->getNum());
}

GMSH_API void gmsh::model::mesh::removeDuplicateNodes(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  GModel::current()->removeDuplicateMeshVertices(
    CTX::instance()->geom.tolerance, entities);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::removeDuplicateElements(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  std::vector<GEntity *> entities;
  _getEntities(dimTags, entities);
  GModel::current()->removeDuplicateMeshElements(entities);
  CTX::instance()->mesh.changed = ENT_ALL;
}

GMSH_API void gmsh::model::mesh::setVisibility(
  const std::vector<size_t> &elementTags, const int value)
{
  if(!_checkInit()) return;
  for(auto t : elementTags) {
    MElement *e = GModel::current()->getMeshElementByTag(t);
    if(e) e->setVisibility(value);
  }
}

GMSH_API void gmsh::model::mesh::getVisibility(const std::vector<size_t> &elementTags,
                                               std::vector<int> &values)
{
  if(!_checkInit()) return;
  values.clear();
  values.resize(elementTags.size(), 0);
  for(std::size_t i = 0; i < elementTags.size(); i++) {
    MElement *e = GModel::current()->getMeshElementByTag(elementTags[i]);
    if(e) values[i] = e->getVisibility();
  }
}

GMSH_API void gmsh::model::mesh::importStl()
{
  if(!_checkInit()) return;
  GModel *m = GModel::current();
  m->deleteMesh();
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    (*it)->buildSTLTriangulation();
    (*it)->storeSTLAsMesh();
  }
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
    (*it)->storeSTLAsMesh();
  }
}

GMSH_API void gmsh::model::mesh::classifySurfaces(
  const double angle, const bool boundary, const bool forReparametrization,
  const double curveAngle, const bool exportDiscrete)
{
  if(!_checkInit()) return;
  GModel::current()->classifySurfaces(angle, boundary, forReparametrization,
                                      curveAngle);
  if(exportDiscrete) {
    // Warning: this clears GEO_Internals!
    GModel::current()->exportDiscreteGEOInternals();
  }
}

GMSH_API void gmsh::model::mesh::createGeometry(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  GModel::current()->createGeometryOfDiscreteEntities(dimTags);
}

GMSH_API void gmsh::model::mesh::createTopology(const bool makeSimplyConnected,
                                                const bool exportDiscrete)
{
  if(!_checkInit()) return;

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
gmsh::model::mesh::addHomologyRequest(const std::string &type,
                                      const std::vector<int> &domainTags,
                                      const std::vector<int> &subdomainTags,
                                      const std::vector<int> &dims)
{
  if(!_checkInit()) return;
  GModel::current()->addHomologyRequest(type, domainTags, subdomainTags,
                                        dims);
}

GMSH_API void
gmsh::model::mesh::clearHomologyRequests()
{
  if(!_checkInit()) return;
  GModel::current()->clearHomologyRequests();
}

GMSH_API void
gmsh::model::mesh::computeHomology(vectorpair &dimTags)
{
  if(!_checkInit()) return;
  GModel::current()->computeHomology(dimTags);
}

GMSH_API void gmsh::model::mesh::triangulate(const std::vector<double> &coord,
                                             std::vector<std::size_t> &tri)
{
  if(!_checkInit()) return;
  tri.clear();
  if(coord.size() % 2) {
    Msg::Error("Number of 2D coordinates should be even");
    return;
  }
#if defined(HAVE_MESH)
  SBoundingBox3d bbox;
  for(std::size_t i = 0; i < coord.size(); i += 2)
    bbox += SPoint3(coord[i], coord[i + 1], 0.);
  double lc = 10. * norm(SVector3(bbox.max(), bbox.min()));
  std::vector<MVertex *> verts(coord.size() / 2);
  std::size_t j = 0;
  for(std::size_t i = 0; i < coord.size(); i += 2) {
    double XX = 1.e-12 * lc * (double)rand() / (double)RAND_MAX;
    double YY = 1.e-12 * lc * (double)rand() / (double)RAND_MAX;
    MVertex *v = new MVertex(coord[i] + XX, coord[i + 1] + YY, 0.);
    v->setIndex(j);
    verts[j++] = v;
  }
  std::vector<MTriangle *> tris;
  delaunayMeshIn2D(verts, tris);
  if(tris.empty()) return;
  tri.resize(3 * tris.size());
  for(std::size_t i = 0; i < tris.size(); i++) {
    MTriangle *t = tris[i];
    for(std::size_t j = 0; j < 3; j++)
      tri[3 * i + j] = t->getVertex(j)->getIndex() + 1; // start at 1
  }
  for(std::size_t i = 0; i < verts.size(); i++) delete verts[i];
  for(std::size_t i = 0; i < tris.size(); i++) delete tris[i];
#else
  Msg::Error("Triangulate requires the mesh module");
#endif
}

GMSH_API void
gmsh::model::mesh::tetrahedralize(const std::vector<double> &coord,
                                  std::vector<std::size_t> &tetra)
{
  if(!_checkInit()) return;
  tetra.clear();
  if(coord.size() % 3) {
    Msg::Error("Number of coordinates should be a multiple of 3");
    return;
  }
#if defined(HAVE_MESH)
  std::vector<MVertex *> verts(coord.size() / 3);
  std::size_t j = 0;
  for(std::size_t i = 0; i < coord.size(); i += 3) {
    MVertex *v = new MVertex(coord[i], coord[i + 1], coord[i + 2]);
    v->setIndex(j);
    verts[j++] = v;
  }
  std::vector<MTetrahedron *> tets;
  if(CTX::instance()->mesh.algo3d == ALGO_3D_HXT)
    delaunayMeshIn3DHxt(verts, tets);
  else
    delaunayMeshIn3D(verts, tets, true);
  if(tets.empty()) return;
  tetra.resize(4 * tets.size());
  for(std::size_t i = 0; i < tets.size(); i++) {
    MTetrahedron *t = tets[i];
    for(std::size_t j = 0; j < 4; j++)
      tetra[4 * i + j] = t->getVertex(j)->getIndex() + 1; // start at 1
  }
  for(std::size_t i = 0; i < verts.size(); i++) delete verts[i];
  for(std::size_t i = 0; i < tets.size(); i++) delete tets[i];
#else
  Msg::Error("Tetrahedralize requires the mesh module");
#endif
}

// gmsh::model::mesh::field

GMSH_API int gmsh::model::mesh::field::add(const std::string &fieldType,
                                           const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
#if defined(HAVE_MESH)
  if(outTag < 0) { outTag = GModel::current()->getFields()->newId(); }
  if(!GModel::current()->getFields()->newField(outTag, fieldType)) {
    Msg::Error("Cannot add Field %i of type '%s'", outTag, fieldType.c_str());
    return -1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateFields();
#endif
#else
  Msg::Error("Fields require the mesh module");
#endif
  return outTag;
}

GMSH_API void gmsh::model::mesh::field::remove(const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  GModel::current()->getFields()->deleteField(tag);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateFields();
#endif
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::list(std::vector<int> &tags)
{
  if(!_checkInit()) return;
  tags.clear();
#if defined(HAVE_MESH)
  FieldManager &fields = *GModel::current()->getFields();
  for(auto it = fields.begin(); it != fields.end(); it++) {
    tags.push_back(it->first);
  }
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::getType(const int tag,
                                                std::string &fieldType)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  Field *field = GModel::current()->getFields()->get(tag);
  if(!field) {
    Msg::Error("Unknown field %i", tag);
    return;
  }
  fieldType = field->getName();
#else
  Msg::Error("Fields require the mesh module");
#endif
}

#if defined(HAVE_MESH)
static FieldOption *_getFieldOption(const int tag, const std::string &option)
{
  Field *field = GModel::current()->getFields()->get(tag);
  if(!field) {
    Msg::Error("Unknown field %i", tag);
    return nullptr;
  }
  FieldOption *o = field->options[option];
  if(!o) {
    Msg::Error("Unknown option '%s' in field %i of type '%s'", option.c_str(),
               tag, field->getName());
    return nullptr;
  }
  return o;
}
#endif

GMSH_API void gmsh::model::mesh::field::setNumber(const int tag,
                                                  const std::string &option,
                                                  const double value)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return;
  if(o->getType() != FIELD_OPTION_DOUBLE &&
     o->getType() != FIELD_OPTION_INT &&
     o->getType() != FIELD_OPTION_BOOL) {
    Msg::Warning("Field option '%s' is not a number", option.c_str());
  }
  o->numericalValue(value);
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::getNumber(const int tag,
                                                  const std::string &option,
                                                  double &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { return; }
  if(o->getType() != FIELD_OPTION_DOUBLE &&
     o->getType() != FIELD_OPTION_INT &&
     o->getType() != FIELD_OPTION_BOOL) {
    Msg::Warning("Field option '%s' is not a number", option.c_str());
  }
  value = o->numericalValue();
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::setString(const int tag,
                                                  const std::string &option,
                                                  const std::string &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return;
  if(o->getType() != FIELD_OPTION_STRING &&
     o->getType() != FIELD_OPTION_PATH) {
    Msg::Warning("Field option '%s' is not a string", option.c_str());
  }
  o->string(value);
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::getString(const int tag,
                                                  const std::string &option,
                                                  std::string &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { return; }
  if(o->getType() != FIELD_OPTION_STRING &&
     o->getType() != FIELD_OPTION_PATH) {
    Msg::Warning("Field option '%s' is not a string", option.c_str());
  }
  value = o->string();
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void
gmsh::model::mesh::field::setNumbers(const int tag, const std::string &option,
                                     const std::vector<double> &values)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return;
  if(o->getType() == FIELD_OPTION_LIST) {
    std::list<int> vl;
    for(std::size_t i = 0; i < values.size(); i++) vl.push_back((int)values[i]);
    o->list(vl);
  }
  else {
    if(o->getType() != FIELD_OPTION_LIST_DOUBLE) {
      Msg::Warning("Field option '%s' is not a list", option.c_str());
    }
    std::list<double> vl;
    for(std::size_t i = 0; i < values.size(); i++) vl.push_back(values[i]);
    o->listdouble(vl);
  }
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void
gmsh::model::mesh::field::getNumbers(const int tag, const std::string &option,
                                     std::vector<double> &values)
{
  if(!_checkInit()) return;
  values.clear();
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) { return; }
  if(o->getType() == FIELD_OPTION_LIST) {
    std::list<int> vl = o->list();
    for(auto i : vl) values.push_back(i);
  }
  else {
    if(o->getType() != FIELD_OPTION_LIST_DOUBLE) {
      Msg::Warning("Field option '%s' is not a list", option.c_str());
    }
    std::list<double> vl = o->listdouble();
    for(auto d : vl) values.push_back(d);
  }
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::setAsBackgroundMesh(const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
#endif
}

GMSH_API void gmsh::model::mesh::field::setAsBoundaryLayer(const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_MESH)
  GModel::current()->getFields()->addBoundaryLayerFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
#endif
}

// gmsh::model::geo

GMSH_API int gmsh::model::geo::addPoint(const double x, const double y,
                                        const double z, const double meshSize,
                                        const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, zz, lc);
  return outTag;
}

GMSH_API int gmsh::model::geo::addLine(const int startTag, const int endTag,
                                       const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag);
  return outTag;
}

GMSH_API int gmsh::model::geo::addCircleArc(const int startTag,
                                            const int centerTag,
                                            const int endTag, const int tag,
                                            const double nx, const double ny,
                                            const double nz)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addCircleArc(
    outTag, startTag, centerTag, endTag, nx, ny, nz);
  return outTag;
}

GMSH_API int gmsh::model::geo::addEllipseArc(
  const int startTag, const int centerTag, const int majorTag, const int endTag,
  const int tag, const double nx, const double ny, const double nz)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addEllipseArc(
    outTag, startTag, centerTag, majorTag, endTag, nx, ny, nz);
  return outTag;
}

GMSH_API int gmsh::model::geo::addSpline(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addSpline(outTag, pointTags);
  return outTag;
}

GMSH_API int gmsh::model::geo::addBSpline(const std::vector<int> &pointTags,
                                          const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addBSpline(outTag, pointTags);
  return outTag;
}

GMSH_API int gmsh::model::geo::addBezier(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addBezier(outTag, pointTags);
  return outTag;
}

GMSH_API int gmsh::model::geo::addPolyline(const std::vector<int> &pointTags,
                                           const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addLine(outTag, pointTags);
  return outTag;
}

GMSH_API int
gmsh::model::geo::addCompoundSpline(const std::vector<int> &curveTags,
                                    const int numIntervals, const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addCompoundSpline(outTag, curveTags,
                                                          numIntervals);
  return outTag;
}

GMSH_API int
gmsh::model::geo::addCompoundBSpline(const std::vector<int> &curveTags,
                                     const int numIntervals, const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addCompoundBSpline(outTag, curveTags,
                                                           numIntervals);
  return outTag;
}

GMSH_API int gmsh::model::geo::addCurveLoop(const std::vector<int> &curveTags,
                                            const int tag, const bool reorient)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addCurveLoop(outTag, curveTags,
                                                     reorient);
  return outTag;
}

GMSH_API void gmsh::model::geo::addCurveLoops(const std::vector<int> &curveTags,
                                              std::vector<int> &tags)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->addCurveLoops(curveTags, tags);
}

GMSH_API int gmsh::model::geo::addPlaneSurface(const std::vector<int> &wireTags,
                                               const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags);
  return outTag;
}

GMSH_API int
gmsh::model::geo::addSurfaceFilling(const std::vector<int> &wireTags,
                                    const int tag, const int sphereCenterTag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addSurfaceFilling(outTag, wireTags,
                                                          sphereCenterTag);
  return outTag;
}

GMSH_API int
gmsh::model::geo::addSurfaceLoop(const std::vector<int> &surfaceTags,
                                 const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addSurfaceLoop(outTag, surfaceTags);
  return outTag;
}

GMSH_API int gmsh::model::geo::addVolume(const std::vector<int> &shellTags,
                                         const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  GModel::current()->getGEOInternals()->addVolume(outTag, shellTags);
  return outTag;
}

GMSH_API int gmsh::model::geo::addGeometry(const std::string &geometry,
                                           const std::vector<double> &numbers,
                                           const std::vector<std::string> &strings,
                                           const int tag)
{
  int t = tag;
  if(t < 0) t = gmshSurface::maxTag() + 1;

  if(geometry == "ParametricSurface") {
    if(strings.size() == 3)
      gmshParametricSurface::NewParametricSurface(t, strings[0].c_str(),
                                                  strings[1].c_str(),
                                                  strings[2].c_str());
    else
      Msg::Error("Parametric surface definition requires 3 strings "
                 "(3 expressions to compute the coordinates)");
  }
  else if(geometry == "Sphere") {
    if(numbers.size() == 4)
      gmshSphere::NewSphere(t, numbers[0], numbers[1], numbers[2], numbers[3]);
    else
      Msg::Error("Sphere definition requires 4 numbers (3 coordinates "
                 "of the center and the radius)");
  }
  else if(geometry == "PolarSphere") {
    if(numbers.size() == 4)
      gmshPolarSphere::NewPolarSphere(t, numbers[0], numbers[1],
                                      numbers[2], numbers[3]);
    else
      Msg::Error("Polar sphere definition requires 4 numbers (3 coordinates "
                 "of the center and the radius)");
  }
  else {
    Msg::Error("Unknown geometry '%s'", geometry.c_str());
    return 0;
  }
  return t;
}

GMSH_API int gmsh::model::geo::addPointOnGeometry(const int geometryTag,
                                                  const double x,
                                                  const double y,
                                                  const double z,
                                                  const double meshSize,
                                                  const int tag)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  //double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  gmshSurface *s = gmshSurface::getSurface(geometryTag);
  if(s) {
    GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, s, lc);
    return outTag;
  }
  else {
    return 0;
  }
}

static ExtrudeParams *_getExtrudeParams(const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  ExtrudeParams *e = nullptr;
  if(numElements.size()) {
    e = new ExtrudeParams();
    e->mesh.ExtrudeMesh = true;
    e->mesh.NbElmLayer = numElements;
    e->mesh.hLayer = heights;
    if(e->mesh.hLayer.empty()) {
      e->mesh.NbLayer = numElements.size();
      for(int i = 0; i < e->mesh.NbLayer; i++) {
        e->mesh.hLayer.push_back((i + 1.) / e->mesh.NbLayer);
      }
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
  if(!_checkInit()) return;
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  GModel::current()->getGEOInternals()->extrude(
    dimTags, dx, dy, dz, outDimTags, e);
  if(e) delete e;
}

GMSH_API void gmsh::model::geo::revolve(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double ax, const double ay, const double az, const double angle,
  vectorpair &outDimTags, const std::vector<int> &numElements,
  const std::vector<double> &heights, const bool recombine)
{
  if(!_checkInit()) return;
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  GModel::current()->getGEOInternals()->revolve(
    dimTags, x, y, z, ax, ay, az, angle, outDimTags, e);
  if(e) delete e;
}

GMSH_API void gmsh::model::geo::twist(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double dx, const double dy, const double dz, const double ax,
  const double ay, const double az, const double angle, vectorpair &outDimTags,
  const std::vector<int> &numElements, const std::vector<double> &heights,
  const bool recombine)
{
  _checkInit();
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  GModel::current()->getGEOInternals()->twist(
    dimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags, e);
  if(e) delete e;
}

GMSH_API void gmsh::model::geo::extrudeBoundaryLayer(
  const vectorpair &dimTags, vectorpair &outDimTags,
  const std::vector<int> &numElements, const std::vector<double> &heights,
  const bool recombine, const bool second, const int viewIndex)
{
  if(!_checkInit()) return;
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  if(!e) {
    Msg::Error("Element layers are required for boundary layer extrusion");
    return;
  }
  e->mesh.BoundaryLayerIndex = second ? 1 : 0;
  e->mesh.ViewIndex = viewIndex;
  GModel::current()->getGEOInternals()->boundaryLayer(dimTags, outDimTags, e);
  delete e;
}

GMSH_API void gmsh::model::geo::translate(const vectorpair &dimTags,
                                          const double dx, const double dy,
                                          const double dz)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz);
}

GMSH_API void gmsh::model::geo::rotate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double ax,
                                       const double ay, const double az,
                                       const double angle)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->rotate(dimTags, x, y, z, ax, ay, az,
                                               angle);
}

GMSH_API void gmsh::model::geo::dilate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double a,
                                       const double b, const double c)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->dilate(dimTags, x, y, z, a, b, c);
}

GMSH_API void gmsh::model::geo::mirror(const vectorpair &dimTags,
                                       const double a, const double b,
                                       const double c, const double d)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->symmetry(dimTags, a, b, c, d);
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
  if(!_checkInit()) return;
  outDimTags.clear();
  GModel::current()->getGEOInternals()->copy(dimTags, outDimTags);
}

GMSH_API void gmsh::model::geo::remove(const vectorpair &dimTags,
                                       const bool recursive)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->remove(dimTags, recursive);
}

GMSH_API void gmsh::model::geo::removeAllDuplicates()
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->removeAllDuplicates();
}

GMSH_API void gmsh::model::geo::splitCurve(const int tag,
                                           const std::vector<int> &pointTags,
                                           std::vector<int> &curveTags)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->splitCurve(tag, pointTags, curveTags);
}

GMSH_API int gmsh::model::geo::getMaxTag(const int dim)
{
  if(!_checkInit()) return -1;
  return GModel::current()->getGEOInternals()->getMaxTag(dim);
}

GMSH_API void gmsh::model::geo::setMaxTag(const int dim, const int maxTag)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setMaxTag(dim, maxTag);
}

GMSH_API int gmsh::model::geo::addPhysicalGroup(const int dim,
                                                const std::vector<int> &tags,
                                                const int tag,
                                                const std::string &name)
{
  if(!_checkInit()) return -1;
  int outTag = tag;
  if(outTag < 0)
    outTag = GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1;
  GModel::current()->getGEOInternals()->modifyPhysicalGroup(dim, outTag, 0,
                                                            tags);
  if(!name.empty()) GModel::current()->setPhysicalName(name, dim, outTag);
  return outTag;
}

GMSH_API void gmsh::model::geo::removePhysicalGroups(const vectorpair &dimTags)
{
  if(!_checkInit()) return;
  if(dimTags.empty()) {
    GModel::current()->getGEOInternals()->resetPhysicalGroups();
  }
  else {
    for(std::size_t i = 0; i < dimTags.size(); i++) {
      std::vector<int> tags; // empty to delete the group
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(
        dimTags[i].first, dimTags[i].second, 2, tags);
    }
  }
}

GMSH_API void gmsh::model::geo::synchronize()
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
}

// gmsh::model::geo::mesh

GMSH_API void
gmsh::model::geo::mesh::setTransfiniteCurve(const int tag, const int nPoints,
                                            const std::string &meshType,
                                            const double coef)
{
  if(!_checkInit()) return;
  int type = (meshType == "Progression" || meshType == "Power") ? 1 :
             (meshType == "Bump")                               ? 2 :
             (meshType == "Beta")                               ? 3 :
                                                                  1;
  double c = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) type = -type;

  // for compatibility with geo files, try both tag and -tag
  for(int sig = -1; sig <= 1; sig += 2)
    GModel::current()->getGEOInternals()->setTransfiniteLine(sig * tag, nPoints,
                                                             type, c);
}

GMSH_API void gmsh::model::geo::mesh::setTransfiniteSurface(
  const int tag, const std::string &arrangement,
  const std::vector<int> &cornerTags)
{
  if(!_checkInit()) return;
  int t = (arrangement == "Right")          ? 1 :
          (arrangement == "Left")           ? -1 :
          (arrangement == "AlternateRight") ? 2 :
          (arrangement == "AlternateLeft")  ? -2 :
          (arrangement == "Alternate")      ? 2 :
                                              -1;
  GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, t,
                                                              cornerTags);
}

GMSH_API void
gmsh::model::geo::mesh::setTransfiniteVolume(const int tag,
                                             const std::vector<int> &cornerTags)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, cornerTags);
}

GMSH_API void gmsh::model::geo::mesh::setRecombine(const int dim, const int tag,
                                                   const double angle)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setRecombine(dim, tag, angle);
}

GMSH_API void gmsh::model::geo::mesh::setSmoothing(const int dim, const int tag,
                                                   const int val)
{
  if(!_checkInit()) return;
  if(dim == 2) { GModel::current()->getGEOInternals()->setSmoothing(tag, val); }
}

GMSH_API void gmsh::model::geo::mesh::setReverse(const int dim, const int tag,
                                                 const bool val)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setReverseMesh(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setAlgorithm(const int dim, const int tag,
                                                   const int val)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setMeshAlgorithm(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setSizeFromBoundary(const int dim,
                                                          const int tag,
                                                          const int val)
{
  if(!_checkInit()) return;
  GModel::current()->getGEOInternals()->setMeshSizeFromBoundary(dim, tag, val);
}

GMSH_API void gmsh::model::geo::mesh::setSize(const vectorpair &dimTags,
                                              const double size)
{
  if(!_checkInit()) return;
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
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addVertex(outTag, x, y, z, meshSize);
  return outTag;
}

GMSH_API int gmsh::model::occ::addLine(const int startTag, const int endTag,
                                       const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag);
  return outTag;
}

GMSH_API int gmsh::model::occ::addCircleArc(const int startTag,
                                            const int middleTag,
                                            const int endTag, const int tag,
                                            const bool center)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addCircleArc(outTag, startTag,
                                                     middleTag, endTag, center);
  return outTag;
}

GMSH_API int gmsh::model::occ::addCircle(const double x, const double y,
                                         const double z, const double r,
                                         const int tag, const double angle1,
                                         const double angle2,
                                         const std::vector<double> &zAxis,
                                         const std::vector<double> &xAxis)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addCircle(outTag, x, y, z, r, angle1,
                                                  angle2, zAxis, xAxis);
  return outTag;
}

GMSH_API int gmsh::model::occ::addEllipseArc(const int startTag,
                                             const int centerTag,
                                             const int majorTag,
                                             const int endTag, const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addEllipseArc(
    outTag, startTag, centerTag, majorTag, endTag);
  return outTag;
}

GMSH_API int gmsh::model::occ::addEllipse(const double x, const double y,
                                          const double z, const double r1,
                                          const double r2, const int tag,
                                          const double angle1,
                                          const double angle2,
                                          const std::vector<double> &zAxis,
                                          const std::vector<double> &xAxis)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addEllipse(outTag, x, y, z, r1, r2,
                                                   angle1, angle2, zAxis,
                                                   xAxis);
  return outTag;
}

GMSH_API int gmsh::model::occ::addSpline(const std::vector<int> &pointTags,
                                         const int tag,
                                         const std::vector<double> &tangents)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  std::vector<SVector3> t;
  if(tangents.size() % 3) {
    Msg::Error("Number of entries in tangents should be a multiple of 3");
  }
  else if(!tangents.empty()) {
    for(std::size_t i = 0; i < tangents.size(); i += 3) {
      t.push_back(SVector3(tangents[i], tangents[i + 1], tangents[i + 2]));
    }
  }
  GModel::current()->getOCCInternals()->addSpline(outTag, pointTags, t);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBSpline(
  const std::vector<int> &pointTags, const int tag, const int degree,
  const std::vector<double> &weights, const std::vector<double> &knots,
  const std::vector<int> &multiplicities)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBSpline(
    outTag, pointTags, degree, weights, knots, multiplicities);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBezier(const std::vector<int> &pointTags,
                                         const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBezier(outTag, pointTags);
  return outTag;
}

GMSH_API int gmsh::model::occ::addWire(const std::vector<int> &curveTags,
                                       const int tag, const bool checkClosed)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addWire(outTag, curveTags, checkClosed);
  return outTag;
}

GMSH_API int gmsh::model::occ::addCurveLoop(const std::vector<int> &curveTags,
                                            const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addCurveLoop(outTag, curveTags);
  return outTag;
}

GMSH_API int gmsh::model::occ::addRectangle(const double x, const double y,
                                            const double z, const double dx,
                                            const double dy, const int tag,
                                            const double roundedRadius)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addRectangle(outTag, x, y, z, dx, dy,
                                                     roundedRadius);
  return outTag;
}

GMSH_API int gmsh::model::occ::addDisk(const double xc, const double yc,
                                       const double zc, const double rx,
                                       const double ry, const int tag,
                                       const std::vector<double> &zAxis,
                                       const std::vector<double> &xAxis)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addDisk(outTag, xc, yc, zc, rx, ry,
                                                zAxis, xAxis);
  return outTag;
}

GMSH_API int gmsh::model::occ::addPlaneSurface(const std::vector<int> &wireTags,
                                               const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags);
  return outTag;
}

GMSH_API int gmsh::model::occ::addSurfaceFilling(
  const int wireTag, const int tag, const std::vector<int> &pointTags,
  const int degree, const int numPointsOnCurves, const int numIter,
  const bool anisotropic, const double tol2d, const double tol3d,
  const double tolAng, const double tolCurv, const int maxDegree,
  const int maxSegments)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  std::vector<int> surf, surfCont;
  GModel::current()->getOCCInternals()->addSurfaceFilling(
    outTag, wireTag, pointTags, surf, surfCont, degree, numPointsOnCurves,
    numIter, anisotropic, tol2d, tol3d, tolAng, tolCurv, maxDegree,
    maxSegments);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBSplineFilling(const int wireTag,
                                                 const int tag,
                                                 const std::string &type)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBSplineFilling(outTag, wireTag,
                                                          type);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBezierFilling(const int wireTag,
                                                const int tag,
                                                const std::string &type)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBezierFilling(outTag, wireTag, type);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBSplineSurface(
  const std::vector<int> &pointTags, const int numPointsU, const int tag,
  const int degreeU, const int degreeV, const std::vector<double> &weights,
  const std::vector<double> &knotsU, const std::vector<double> &knotsV,
  const std::vector<int> &multiplicitiesU,
  const std::vector<int> &multiplicitiesV, const std::vector<int> &wireTags,
  const bool wire3D)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBSplineSurface(
    outTag, pointTags, numPointsU, degreeU, degreeV, weights, knotsU, knotsV,
    multiplicitiesU, multiplicitiesV, wireTags, wire3D);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBezierSurface(
  const std::vector<int> &pointTags, const int numPointsU, const int tag,
  const std::vector<int> &wireTags, const bool wire3D)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBezierSurface(
    outTag, pointTags, numPointsU, wireTags, wire3D);
  return outTag;
}

GMSH_API int
gmsh::model::occ::addTrimmedSurface(const int surfaceTag,
                                    const std::vector<int> &wireTags,
                                    const bool wire3D, const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addTrimmedSurface(outTag, surfaceTag,
                                                          wireTags, wire3D);
  return outTag;
}

GMSH_API int
gmsh::model::occ::addSurfaceLoop(const std::vector<int> &surfaceTags,
                                 const int tag, const bool sewing)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, surfaceTags,
                                                       sewing);
  return outTag;
}

GMSH_API int gmsh::model::occ::addVolume(const std::vector<int> &shellTags,
                                         const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addVolume(outTag, shellTags);
  return outTag;
}

GMSH_API int gmsh::model::occ::addSphere(const double xc, const double yc,
                                         const double zc, const double radius,
                                         const int tag, const double angle1,
                                         const double angle2,
                                         const double angle3)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addSphere(outTag, xc, yc, zc, radius,
                                                  angle1, angle2, angle3);
  return outTag;
}

GMSH_API int gmsh::model::occ::addBox(const double x, const double y,
                                      const double z, const double dx,
                                      const double dy, const double dz,
                                      const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addBox(outTag, x, y, z, dx, dy, dz);
  return outTag;
}

GMSH_API int gmsh::model::occ::addCylinder(const double x, const double y,
                                           const double z, const double dx,
                                           const double dy, const double dz,
                                           const double r, const int tag,
                                           const double angle)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addCylinder(outTag, x, y, z, dx, dy, dz,
                                                    r, angle);
  return outTag;
}

GMSH_API int gmsh::model::occ::addCone(const double x, const double y,
                                       const double z, const double dx,
                                       const double dy, const double dz,
                                       const double r1, const double r2,
                                       const int tag, const double angle)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addCone(outTag, x, y, z, dx, dy, dz, r1,
                                                r2, angle);
  return outTag;
}

GMSH_API int gmsh::model::occ::addWedge(const double x, const double y,
                                        const double z, const double dx,
                                        const double dy, const double dz,
                                        const int tag, const double ltx,
                                        const std::vector<double> &zAxis)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addWedge(outTag, x, y, z, dx, dy, dz,
                                                 ltx, zAxis);
  return outTag;
}

GMSH_API int gmsh::model::occ::addTorus(const double x, const double y,
                                        const double z, const double r1,
                                        const double r2, const int tag,
                                        const double angle,
                                        const std::vector<double> &zAxis)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->addTorus(outTag, x, y, z, r1, r2,
                                                 angle, zAxis);
  return outTag;
}

GMSH_API void gmsh::model::occ::addThruSections(
  const std::vector<int> &wireTags, vectorpair &outDimTags, const int tag,
  const bool makeSolid, const bool makeRuled, const int maxDegree,
  const std::string &continuity, const std::string &parametrization,
  const bool smoothing)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->addThruSections(
    tag, wireTags, makeSolid, makeRuled, outDimTags, maxDegree,
    continuity, parametrization, smoothing);
}

GMSH_API void gmsh::model::occ::addThickSolid(
  const int volumeTag, const std::vector<int> &excludeSurfaceTags,
  const double offset, vectorpair &outDimTags, const int tag)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->addThickSolid(
    tag, volumeTag, excludeSurfaceTags, offset, outDimTags);
}

GMSH_API void gmsh::model::occ::extrude(const vectorpair &dimTags,
                                        const double dx, const double dy,
                                        const double dz, vectorpair &outDimTags,
                                        const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  GModel::current()->getOCCInternals()->extrude(
    dimTags, dx, dy, dz, outDimTags, e);
  if(e) delete e;
}

GMSH_API void gmsh::model::occ::revolve(
  const vectorpair &dimTags, const double x, const double y, const double z,
  const double ax, const double ay, const double az, const double angle,
  vectorpair &outDimTags, const std::vector<int> &numElements,
  const std::vector<double> &heights, const bool recombine)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  ExtrudeParams *e = _getExtrudeParams(numElements, heights, recombine);
  GModel::current()->getOCCInternals()->revolve(
    dimTags, x, y, z, ax, ay, az, angle, outDimTags, e);
  if(e) delete e;
}

GMSH_API void gmsh::model::occ::addPipe(const vectorpair &dimTags,
                                        const int wireTag,
                                        vectorpair &outDimTags,
                                        const std::string &trihedron)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->addPipe(dimTags, wireTag, outDimTags,
                                                trihedron);
}

GMSH_API void gmsh::model::occ::fillet(const std::vector<int> &volumeTags,
                                       const std::vector<int> &curveTags,
                                       const std::vector<double> &radii,
                                       vectorpair &outDimTags,
                                       const bool removeVolume)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->fillet(volumeTags, curveTags, radii,
                                               outDimTags, removeVolume);
}

GMSH_API void gmsh::model::occ::chamfer(const std::vector<int> &volumeTags,
                                        const std::vector<int> &curveTags,
                                        const std::vector<int> &surfaceTags,
                                        const std::vector<double> &distances,
                                        vectorpair &outDimTags,
                                        const bool removeVolume)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->chamfer(
    volumeTags, curveTags, surfaceTags, distances, outDimTags, removeVolume);
}

GMSH_API void gmsh::model::occ::defeature(const std::vector<int> &volumeTags,
                                          const std::vector<int> &surfaceTags,
                                          vectorpair &outDimTags,
                                          const bool removeVolume)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->defeature(
    volumeTags, surfaceTags, outDimTags, removeVolume);
}

GMSH_API int gmsh::model::occ::fillet2D(const int edgeTag1,
                                        const int edgeTag2,
                                        const double radius, const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->fillet2D(outTag, edgeTag1, edgeTag2, radius);
  return outTag;
}

GMSH_API int gmsh::model::occ::chamfer2D(const int edgeTag1,
                                          const int edgeTag2,
                                          const double distance1,
                                          const double distance2, const int tag)
{
  if(!_checkInit()) return -1;
  _createOcc();
  int outTag = tag;
  GModel::current()->getOCCInternals()->chamfer2D(outTag, edgeTag1, edgeTag2, distance1,
                                                  distance2);
  return outTag;
}

GMSH_API void gmsh::model::occ::offsetCurve( const int curveLoopTag,
                                              double offset,
                                              vectorpair &outDimTags)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->offsetCurve(curveLoopTag, offset, outDimTags);
}

GMSH_API void gmsh::model::occ::fuse(const vectorpair &objectDimTags,
                                     const vectorpair &toolDimTags,
                                     vectorpair &outDimTags,
                                     std::vector<vectorpair> &outDimTagsMap,
                                     const int tag, const bool removeObject,
                                     const bool removeTool)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  GModel::current()->getOCCInternals()->booleanUnion(
    tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
    removeTool);
}

GMSH_API void gmsh::model::occ::getDistance(int dim1, int tag1,
                                  int dim2, int tag2,
                                  double &distance,
                                  double &x1, double &y1, double &z1,
                                  double &x2, double &y2, double &z2)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getDistance(dim1, tag1,
                                  dim2, tag2,
                                  distance,
                                  x1, y1, z1,
                                  x2, y2, z2);
}

GMSH_API void gmsh::model::occ::intersect(
  const vectorpair &objectDimTags, const vectorpair &toolDimTags,
  vectorpair &outDimTags, std::vector<vectorpair> &outDimTagsMap, const int tag,
  const bool removeObject, const bool removeTool)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  GModel::current()->getOCCInternals()->booleanIntersection(
    tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
    removeTool);
}

GMSH_API void gmsh::model::occ::cut(const vectorpair &objectDimTags,
                                    const vectorpair &toolDimTags,
                                    vectorpair &outDimTags,
                                    std::vector<vectorpair> &outDimTagsMap,
                                    const int tag, const bool removeObject,
                                    const bool removeTool)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  GModel::current()->getOCCInternals()->booleanDifference(
    tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
    removeTool);
}

GMSH_API void gmsh::model::occ::fragment(const vectorpair &objectDimTags,
                                         const vectorpair &toolDimTags,
                                         vectorpair &outDimTags,
                                         std::vector<vectorpair> &outDimTagsMap,
                                         const int tag, const bool removeObject,
                                         const bool removeTool)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  GModel::current()->getOCCInternals()->booleanFragments(
    tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap, removeObject,
    removeTool);
}

GMSH_API void gmsh::model::occ::translate(const vectorpair &dimTags,
                                          const double dx, const double dy,
                                          const double dz)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz);
}

GMSH_API void gmsh::model::occ::rotate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double ax,
                                       const double ay, const double az,
                                       const double angle)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->rotate(dimTags, x, y, z, ax, ay, az,
                                               angle);
}

GMSH_API void gmsh::model::occ::dilate(const vectorpair &dimTags,
                                       const double x, const double y,
                                       const double z, const double a,
                                       const double b, const double c)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->dilate(dimTags, x, y, z, a, b, c);
}

GMSH_API void gmsh::model::occ::mirror(const vectorpair &dimTags,
                                       const double a, const double b,
                                       const double c, const double d)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->symmetry(dimTags, a, b, c, d);
}

GMSH_API void gmsh::model::occ::symmetrize(const vectorpair &dimTags,
                                           const double a, const double b,
                                           const double c, const double d)
{
  gmsh::model::occ::mirror(dimTags, a, b, c, d);
}

GMSH_API void
gmsh::model::occ::affineTransform(const vectorpair &dimTags,
                                  const std::vector<double> &affineTransform)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->affine(dimTags, affineTransform);
}

GMSH_API void gmsh::model::occ::copy(const vectorpair &dimTags,
                                     vectorpair &outDimTags)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->copy(dimTags, outDimTags);
}

GMSH_API void gmsh::model::occ::remove(const vectorpair &dimTags,
                                       const bool recursive)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->remove(dimTags, recursive);
}

GMSH_API void gmsh::model::occ::removeAllDuplicates()
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
}

GMSH_API void gmsh::model::occ::healShapes(
  vectorpair &outDimTags, const vectorpair &inDimTags, const double tolerance,
  const bool fixDegenerated, const bool fixSmallEdges, const bool fixSmallFaces,
  const bool sewFaces, const bool makeSolids)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->healShapes(
    inDimTags, outDimTags, tolerance, fixDegenerated, fixSmallEdges,
    fixSmallFaces, sewFaces, makeSolids);
}

GMSH_API void gmsh::model::occ::convertToNURBS(const vectorpair &inDimTags)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->convertToNURBS(inDimTags);
}

GMSH_API void gmsh::model::occ::importShapes(const std::string &fileName,
                                             vectorpair &outDimTags,
                                             const bool highestDimOnly,
                                             const std::string &format)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
  GModel::current()->getOCCInternals()->importShapes(fileName, highestDimOnly,
                                                     outDimTags, format);
}

GMSH_API void gmsh::model::occ::importShapesNativePointer(
  const void *shape, vectorpair &outDimTags, const bool highestDimOnly)
{
  if(!_checkInit()) return;
  _createOcc();
  outDimTags.clear();
#if defined(HAVE_OCC)
  GModel::current()->getOCCInternals()->importShapes(
    static_cast<const TopoDS_Shape *>(shape), highestDimOnly, outDimTags);
#else
  Msg::Error("Gmsh requires OpenCASCADE to import native shape");
#endif
}

GMSH_API void gmsh::model::occ::getEntities(vectorpair &dimTags, const int dim)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getEntities(dimTags, dim);
}

GMSH_API void gmsh::model::occ::getEntitiesInBoundingBox(
  const double xmin, const double ymin, const double zmin, const double xmax,
  const double ymax, const double zmax, vectorpair &dimTags, const int dim)
{
  if(!_checkInit()) return;
  _createOcc();
  dimTags.clear();
  GModel::current()->getOCCInternals()->getEntitiesInBoundingBox(
    xmin, ymin, zmin, xmax, ymax, zmax, dimTags, dim);
}

GMSH_API void gmsh::model::occ::getBoundingBox(const int dim, const int tag,
                                               double &xmin, double &ymin,
                                               double &zmin, double &xmax,
                                               double &ymax, double &zmax)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getBoundingBox(dim, tag, xmin, ymin,
                                                       zmin, xmax, ymax, zmax);
}

GMSH_API void gmsh::model::occ::getCurveLoops(
  const int surfaceTag, std::vector<int> &curveLooptags,
  std::vector<std::vector<int> > &curveTags)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getCurveLoops(surfaceTag,
                                                      curveLooptags,
                                                      curveTags);
}

GMSH_API void gmsh::model::occ::getSurfaceLoops(
  const int volumeTag, std::vector<int> &surfaceLoopTags,
  std::vector<std::vector<int> > &surfaceTags)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getSurfaceLoops(volumeTag,
                                                        surfaceLoopTags,
                                                        surfaceTags);
}

GMSH_API void gmsh::model::occ::getMass(const int dim, const int tag,
                                        double &mass)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getMass(dim, tag, mass);
}

GMSH_API void gmsh::model::occ::getCenterOfMass(const int dim, const int tag,
                                                double &x, double &y, double &z)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getCenterOfMass(dim, tag, x, y, z);
}

GMSH_API void gmsh::model::occ::getMatrixOfInertia(const int dim, const int tag,
                                                   std::vector<double> &m)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->getMatrixOfInertia(dim, tag, m);
}

GMSH_API int gmsh::model::occ::getMaxTag(const int dim)
{
  if(!_checkInit()) return -1;
  _createOcc();
  return GModel::current()->getOCCInternals()->getMaxTag(dim);
}

GMSH_API void gmsh::model::occ::setMaxTag(const int dim, const int maxTag)
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->setMaxTag(dim, maxTag);
}

GMSH_API void gmsh::model::occ::synchronize()
{
  if(!_checkInit()) return;
  _createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
}

// gmsh::model::occ::mesh

GMSH_API void gmsh::model::occ::mesh::setSize(const vectorpair &dimTags,
                                              const double size)
{
  if(!_checkInit()) return;
  _createOcc();
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
}

// gmsh::view

GMSH_API int gmsh::view::add(const std::string &name, const int tag)
{
  if(!_checkInit()) return -1;
#if defined(HAVE_POST)
  PView *view = new PView(tag);
  view->getData()->setName(name);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
  return view->getTag();
#else
  Msg::Error("Views require the post-processing module");
  return -1;
#endif
}

GMSH_API void gmsh::view::remove(const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  delete view;
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API int gmsh::view::getIndex(const int tag)
{
  if(!_checkInit()) return -1;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return -1;
  }
  return view->getIndex();
#else
  Msg::Error("Views require the post-processing module");
  return -1;
#endif
}

GMSH_API void gmsh::view::getTags(std::vector<int> &tags)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  tags.clear();
  for(std::size_t i = 0; i < PView::list.size(); i++)
    tags.push_back(PView::list[i]->getTag());
#else
  Msg::Error("Views require the post-processing module");
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
    return;
  }
  GModel *model = GModel::current();
  if(modelName.size()) {
    model = GModel::findByName(modelName);
    if(!model) {
      Msg::Error("Unknown model '%s'", modelName.c_str());
      return;
    }
  }
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
    return;
  }

  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(view->getData());
  bool changeType = false;
  if(d && d->getType() != type) {
    Msg::Warning("Changing type of view to '%s'", dataType.c_str());
    changeType = true;
  }
  if(!d || changeType) { // change view type
    std::string name = view->getData()->getName();
    delete view->getData();
    d = new PViewDataGModel(type);
    d->setName(name);
    d->setFileName(name + ".msh");
    view->setData(d);
  }
  if(!d->addData(model, tags, data, step, time, partition, numComponents)) {
    Msg::Error("Could not add model data");
    return;
  }
  if(view->getOptions()->adaptVisualizationGrid)
    d->initAdaptiveData(view->getOptions()->timeStep,
                        view->getOptions()->maxRecursionLevel,
                        view->getOptions()->targetError);
  view->setChanged(true);
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::addModelData(
  const int tag, const int step, const std::string &modelName,
  const std::string &dataType, const std::vector<std::size_t> &tags,
  const std::vector<std::vector<double> > &data, const double time,
  const int numComponents, const int partition)
{
  if(!_checkInit()) return;
  if(tags.size() != data.size()) {
    Msg::Error("Incompatible number of tags and data");
    return;
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
  if(!_checkInit()) return;
  _addModelData(tag, step, modelName, dataType, tags, data, time, numComponents,
                partition);
}

#if defined(HAVE_POST)
static stepData<double> *_getModelData(const int tag, const int step,
                                       std::string &dataType, double &time,
                                       int &numComponents, int &numEnt,
                                       int &maxMult)
{
  if(!_checkInit()) return nullptr;
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return nullptr;
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(view->getData());
  if(!d) {
    Msg::Error("View with tag %d does not contain model data", tag);
    return nullptr;
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
    return nullptr;
  }
  time = s->getTime();
  numComponents = s->getNumComponents();
  numEnt = 0;
  maxMult = 0;
  for(std::size_t i = 0; i < s->getNumData(); i++) {
    if(s->getData(i)) {
      numEnt++;
      maxMult = std::max(maxMult, s->getMult(i));
    }
  }
  return s;
}
#endif

GMSH_API void gmsh::view::getModelData(const int tag, const int step,
                                       std::string &dataType,
                                       std::vector<std::size_t> &tags,
                                       std::vector<std::vector<double> > &data,
                                       double &time, int &numComponents)
{
  if(!_checkInit()) return;
  tags.clear();
  data.clear();
#if defined(HAVE_POST)
  int numEnt, maxMult;
  stepData<double> *s =
    _getModelData(tag, step, dataType, time, numComponents, numEnt, maxMult);
  if(!s || !numComponents || !numEnt || !maxMult) return;
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
#endif
}

GMSH_API void gmsh::view::getHomogeneousModelData(
  const int tag, const int step, std::string &dataType,
  std::vector<std::size_t> &tags, std::vector<double> &data, double &time,
  int &numComponents)
{
  if(!_checkInit()) return;
  tags.clear();
  data.clear();
#if defined(HAVE_POST)
  int numEnt, maxMult;
  stepData<double> *s =
    _getModelData(tag, step, dataType, time, numComponents, numEnt, maxMult);
  if(!s || !numComponents || !numEnt || !maxMult) return;
  data.resize(numEnt * numComponents * maxMult, 0.);
  tags.resize(numEnt);
  std::size_t j = 0;
  for(std::size_t i = 0; i < s->getNumData(); i++) {
    double *dd = s->getData(i);
    if(dd) {
      tags[j] = i;
      int mult = s->getMult(i);
      for(int k = 0; k < numComponents * mult; k++) {
        data[j * numComponents * maxMult + k] = dd[k];
      }
      j++;
    }
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

// for better performance, manual C implementation of gmsh::view::getModelData
GMSH_API void gmshViewGetModelData(const int tag, const int step,
                                   char **dataType, size_t **tags,
                                   size_t *tags_n, double ***data,
                                   size_t **data_n, size_t *data_nn,
                                   double *time, int *numComponents, int *ierr)
{
  if(!_checkInit()) {
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
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
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
      view->setChanged(true);
      return;
    }
  }
  Msg::Error("Unknown data type for list import");
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::getListData(const int tag,
                                      std::vector<std::string> &dataTypes,
                                      std::vector<int> &numElements,
                                      std::vector<std::vector<double> > &data,
                                      bool returnAdaptive)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  PViewDataList *d =
    dynamic_cast<PViewDataList *>(view->getData(returnAdaptive));
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
#endif
}

#if defined(HAVE_POST)
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
#endif

GMSH_API void
gmsh::view::addListDataString(const int tag, const std::vector<double> &coord,
                              const std::vector<std::string> &data,
                              const std::vector<std::string> &style)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
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
  view->setChanged(true);
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::getListDataStrings(const int tag, const int dim,
                                             std::vector<double> &coord,
                                             std::vector<std::string> &data,
                                             std::vector<std::string> &style)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
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
#endif
}

GMSH_API void gmsh::view::setInterpolationMatrices(
  const int tag, const std::string &type, const int d,
  const std::vector<double> &coef, const std::vector<double> &exp,
  const int dGeo, const std::vector<double> &coefGeo,
  const std::vector<double> &expGeo)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  PViewData *data = view->getData();
  if(!data) {
    Msg::Error("View with tag %d does not contain any data", tag);
    return;
  }

  int itype = 0;
  if(type == "Line" || type == "line")
    itype = TYPE_LIN;
  else if(type == "Triangle" || type == "triangle")
    itype = TYPE_TRI;
  else if(type == "Quadrangle" || type == "quadrangle")
    itype = TYPE_QUA;
  else if(type == "Tetrahedron" || type == "tetrahedron")
    itype = TYPE_TET;
  else if(type == "Pyramid" || type == "pyramid")
    itype = TYPE_PYR;
  else if(type == "Prism" || type == "prism")
    itype = TYPE_PRI;
  else if(type == "Hexahedron" || type == "hexahedron")
    itype = TYPE_HEX;
  else {
    Msg::Error("Unknown element family type '%s'", type.c_str());
    return;
  }

  if(data->haveInterpolationMatrices(itype))
    data->deleteInterpolationMatrices(itype);

  if(d <= 0) return;

  // field interpolation coefficients and exponents
  if((int)coef.size() != d * d) {
    Msg::Error("Wrong number of coefficients (%d != %d x %d)", (int)coef.size(),
               d, d);
    return;
  }
  if((int)exp.size() != d * 3) {
    Msg::Error("Wrong number of exponents (%d != %d x 3)", (int)exp.size(), d);
    return;
  }
  fullMatrix<double> F(d, d), P(d, 3);
  for(int i = 0; i < d; i++) {
    for(int j = 0; j < d; j++) { F(i, j) = coef[d * i + j]; }
    for(int j = 0; j < 3; j++) { P(i, j) = exp[3 * i + j]; }
  }

  if(dGeo <= 0) {
    data->setInterpolationMatrices(itype, F, P);
    view->setChanged(true);
    return;
  }

  // geometry interpolation coefficients and exponents
  if((int)coefGeo.size() != dGeo * dGeo) {
    Msg::Error("Wrong number of coefficients (%d != %d x %d)",
               (int)coefGeo.size(), dGeo, dGeo);
    return;
  }
  if((int)expGeo.size() != dGeo * 3) {
    Msg::Error("Wrong number of exponents (%d != %d x 3)", (int)expGeo.size(),
               dGeo);
    return;
  }
  fullMatrix<double> Fg(dGeo, dGeo), Pg(dGeo, 3);
  for(int i = 0; i < dGeo; i++) {
    for(int j = 0; j < dGeo; j++) { Fg(i, j) = coefGeo[dGeo * i + j]; }
    for(int j = 0; j < 3; j++) { Pg(i, j) = expGeo[3 * i + j]; }
  }
  data->setInterpolationMatrices(itype, F, P, Fg, Pg);
  view->setChanged(true);
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API int gmsh::view::addAlias(const int refTag, const bool copyOptions,
                                  const int tag)
{
  if(!_checkInit()) return -1;
#if defined(HAVE_POST)
  PView *ref = PView::getViewByTag(refTag);
  if(!ref) {
    Msg::Error("Unknown view with tag %d", refTag);
    return -1;
  }
  PView *view = new PView(ref, copyOptions, tag);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
  return view->getTag();
#else
  Msg::Error("Views require the post-processing module");
  return -1;
#endif
}

GMSH_API void gmsh::view::combine(const std::string &what,
                                  const std::string &how, const bool remove,
                                  const bool copyOptions)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  bool time = (what == "steps") ? true : false; // "elements"
  int ihow = (how == "all") ? 1 : (how == "name") ? 2 : 0; // "visible"
  PView::combine(time, ihow, remove, copyOptions);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::probe(const int tag, const double x, const double y,
                                const double z, std::vector<double> &values,
                                double &distance, const int step,
                                const int numComp, const bool gradient,
                                const double distanceMax,
                                const std::vector<double> &xElemCoord,
                                const std::vector<double> &yElemCoord,
                                const std::vector<double> &zElemCoord,
                                const int dim)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  PViewData *data = view->getData();
  if(!data) {
    Msg::Error("No data in view %d", tag);
    return;
  }
  values.clear();
  std::vector<double> val(9 * data->getNumTimeSteps() * 3);
  int qn = 0;
  double *qx = nullptr, *qy = nullptr, *qz = nullptr;
  if(xElemCoord.size() && yElemCoord.size() && zElemCoord.size() &&
     xElemCoord.size() == yElemCoord.size() &&
     xElemCoord.size() == zElemCoord.size()) {
    qn = xElemCoord.size();
    qx = (double *)&xElemCoord[0];
    qy = (double *)&yElemCoord[0];
    qz = (double *)&zElemCoord[0];
  }
  int numSteps = (step < 0) ? data->getNumTimeSteps() : 1;
  int mult = gradient ? 3 : 1;
  int numVal = 0;
  distance = distanceMax;
  switch(numComp) {
  case 1:
    if(data->searchScalarClosest(x, y, z, distance, &val[0], step, nullptr,
                                 qn, qx, qy, qz, gradient, dim)) {
      numVal = numSteps * mult * 1;
    }
    break;
  case 3:
    if(data->searchVectorClosest(x, y, z, distance, &val[0], step, nullptr,
                                 qn, qx, qy, qz, gradient, dim)) {
      numVal = numSteps * mult * 3;
    }
    break;
  case 9:
    if(data->searchTensorClosest(x, y, z, distance, &val[0], step, nullptr,
                                 qn, qx, qy, qz, gradient, dim)) {
      numVal = numSteps * mult * 9;
    }
    break;
  default:
    if(data->searchScalarClosest(x, y, z, distance, &val[0], step, nullptr,
                                 qn, qx, qy, qz, gradient, dim)) {
      numVal = numSteps * mult * 1;
    }
    else if(data->searchVectorClosest(x, y, z, distance, &val[0], step, nullptr,
                                      qn, qx, qy, qz, gradient,
                                      dim)) {
      numVal = numSteps * mult * 3;
    }
    else if(data->searchTensorClosest(x, y, z, distance, &val[0], step, nullptr,
                                      qn, qx, qy, qz, gradient,
                                      dim)) {
      numVal = numSteps * mult * 9;
    }
    break;
  }
  for(int i = 0; i < numVal; i++) values.push_back(val[i]);
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::write(const int tag, const std::string &fileName,
                                const bool append)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  view->write(fileName, 10, append);
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::setVisibilityPerWindow(const int tag, const int value,
                                                 const int windowIndex)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
#if defined(HAVE_FLTK)
  FlGui::instance()->setCurrentOpenglWindow(windowIndex);
  drawContext *ctx = FlGui::instance()->getCurrentDrawContext();
  if(value)
    ctx->show(view);
  else
    ctx->hide(view);
#endif
#else
  Msg::Error("Views require the post-processing module");
#endif
}

// gmsh::view::option

GMSH_API void gmsh::view::option::setNumber(int tag, const std::string &name,
                                            const double value)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    if(!GmshSetOption("View", name, value, view->getIndex()))
      Msg::Error("Could not set option '%s' in view with tag %d",
                 name.c_str(), tag);
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::getNumber(int tag, const std::string &name,
                                            double &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    if(!GmshGetOption("View", name, value, view->getIndex()))
      Msg::Error("Could not get option '%s' in view with tag %d",
                 name.c_str(), tag);
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::setString(int tag, const std::string &name,
                                            const std::string &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    if(!GmshSetOption("View", name, value, view->getIndex()))
      Msg::Error("Could not set option '%s' in view with tag %d",
                 name.c_str(), tag);
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::getString(int tag, const std::string &name,
                                            std::string &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    if(!GmshGetOption("View", name, value, view->getIndex()))
      Msg::Error("Could not get option '%s' in view with tag %d",
                 name.c_str(), tag);
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::setColor(int tag, const std::string &name,
                                           const int r, const int g,
                                           const int b, const int a)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    unsigned int value = CTX::instance()->packColor(r, g, b, a);
    if(!GmshSetOption("View", name, value, view->getIndex()))
      Msg::Error("Could not set option '%s' in view with tag %d",
                 name.c_str(), tag);
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::getColor(int tag, const std::string &name,
                                           int &r, int &g, int &b, int &a)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(view) {
    unsigned int value;
    if(GmshGetOption("View", name, value, view->getIndex())) {
      r = CTX::instance()->unpackRed(value);
      g = CTX::instance()->unpackGreen(value);
      b = CTX::instance()->unpackBlue(value);
      a = CTX::instance()->unpackAlpha(value);
    }
    else {
      Msg::Error("Could not get option '%s' in view with tag %d",
                 name.c_str(), tag);
    }
  }
  else {
    Msg::Error("Unknown view with tag %d", tag);
  }
#else
  Msg::Error("Views require the post-processing module");
#endif
}

GMSH_API void gmsh::view::option::copy(const int refTag, const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_POST)
  PView *ref = PView::getViewByTag(refTag);
  if(!ref) {
    Msg::Error("Unknown view with tag %d", refTag);
    return;
  }
  PView *view = PView::getViewByTag(tag);
  if(!view) {
    Msg::Error("Unknown view with tag %d", tag);
    return;
  }
  view->setOptions(ref->getOptions());
  view->setChanged(true);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#else
  Msg::Error("Views require the post-processing module");
#endif
}

// gmsh::plugin

GMSH_API void gmsh::plugin::setNumber(const std::string &name,
                                      const std::string &option,
                                      const double value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin option");
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
#endif
}

GMSH_API void gmsh::plugin::setString(const std::string &name,
                                      const std::string &option,
                                      const std::string &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin option");
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
#endif
}

GMSH_API int gmsh::plugin::run(const std::string &name)
{
  if(!_checkInit()) return 0;
#if defined(HAVE_PLUGINS)
  try {
    return PluginManager::instance()->action(name, "Run", nullptr);
  } catch(...) {
    Msg::Error("Unknown plugin or plugin action");
    return 0;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  return 0;
#endif
}

// gmsh::graphics

GMSH_API void gmsh::graphics::draw()
{
#if defined(HAVE_OPENGL)
  drawContext::global()->draw(false); // not rate-limited
#endif
}

// gmsh::fltk

#if defined(HAVE_FLTK)
static void _errorHandlerFltk(const char *fmt, ...)
{
  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  Msg::Error("%s (FLTK internal error)", str);
}

static void _createFltk()
{
  if(!FlGui::available())
    FlGui::instance(_argc, _argv, false, _errorHandlerFltk);
}
#endif

GMSH_API void gmsh::fltk::initialize()
{

  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::setFinishedProcessingCommandLine();
  FlGui::check();
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::finalize()
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  FlGui::destroy();
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API int gmsh::fltk::isAvailable()
{
  if(!_checkInit()) return -1;
#if defined(HAVE_FLTK)
  return FlGui::available() ? 1 : 0;
#else
  return 0;
#endif
}

GMSH_API void gmsh::fltk::wait(const double time)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  if(time >= 0)
    FlGui::wait(time, true); // force
  else
    FlGui::wait(true); // force
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::lock()
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  FlGui::lock();
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::unlock()
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  FlGui::unlock();
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::update()
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->updateViews(true, true);
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::awake(const std::string &action)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  FlGui::awake(action);
#else
  Msg::Error("Fltk not available");
#endif
}

GMSH_API void gmsh::fltk::run()
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->run(); // this calls draw() once
#else
  Msg::Error("Fltk not available");
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
  if(!_checkInit()) return -1;
  dimTags.clear();
#if defined(HAVE_FLTK)
  _createFltk();
  char ret = 0;
  switch(dim) {
  case 0: ret = FlGui::instance()->selectEntity(ENT_POINT); break;
  case 1: ret = FlGui::instance()->selectEntity(ENT_CURVE); break;
  case 2: ret = FlGui::instance()->selectEntity(ENT_SURFACE); break;
  case 3: ret = FlGui::instance()->selectEntity(ENT_VOLUME); break;
  default: ret = FlGui::instance()->selectEntity(ENT_ALL); break;
  }
  if(!FlGui::available()) return 0; // GUI closed during selection
  for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size(); i++)
    dimTags.push_back(
      std::make_pair(0, FlGui::instance()->selectedVertices[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++)
    dimTags.push_back(
      std::make_pair(1, FlGui::instance()->selectedEdges[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++)
    dimTags.push_back(
      std::make_pair(2, FlGui::instance()->selectedFaces[i]->tag()));
  for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size(); i++)
    dimTags.push_back(
      std::make_pair(3, FlGui::instance()->selectedRegions[i]->tag()));
  return selectionCode(ret);
#else
  return 0;
#endif
}

GMSH_API int gmsh::fltk::selectElements(std::vector<std::size_t> &elementTags)
{
  if(!_checkInit()) return -1;
  elementTags.clear();
#if defined(HAVE_FLTK)
  _createFltk();
  int old = CTX::instance()->pickElements;
  CTX::instance()->pickElements = 1;
  CTX::instance()->mesh.changed = ENT_ALL;
  char ret = FlGui::instance()->selectEntity(ENT_ALL);
  CTX::instance()->pickElements = old;
  if(!FlGui::available()) return 0; // GUI closed during selection
  for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size(); i++)
    elementTags.push_back(FlGui::instance()->selectedElements[i]->getNum());
  return selectionCode(ret);
#else
  return 0;
#endif
}

GMSH_API int gmsh::fltk::selectViews(std::vector<int> &viewTags)
{
  if(!_checkInit()) return -1;
  viewTags.clear();
#if defined(HAVE_FLTK)
  _createFltk();
  char ret = FlGui::instance()->selectEntity(ENT_ALL);
  if(!FlGui::available()) return 0; // GUI closed during selection
  for(std::size_t i = 0; i < FlGui::instance()->selectedViews.size(); i++)
    viewTags.push_back(FlGui::instance()->selectedViews[i]->getTag());
  return selectionCode(ret);
#else
  return 0;
#endif
}

GMSH_API void gmsh::fltk::splitCurrentWindow(const std::string &how,
                                             const double ratio)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  if(how == "h")
    FlGui::instance()->splitCurrentOpenglWindow('h', ratio);
  else if(how == "v")
    FlGui::instance()->splitCurrentOpenglWindow('v', ratio);
  else if(how == "u")
    FlGui::instance()->splitCurrentOpenglWindow('u');
  else {
    Msg::Error("Unknown window splitting method '%s'", how.c_str());
  }
#endif
}

GMSH_API void gmsh::fltk::setCurrentWindow(const int windowIndex)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->setCurrentOpenglWindow(windowIndex);
#endif
}

GMSH_API void gmsh::fltk::setStatusMessage(const std::string &message,
                                           const bool graphics)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->setStatus(message, graphics);
#endif
}

GMSH_API void gmsh::fltk::showContextWindow(const int dim, const int tag)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->showOnelabContext(dim, tag);
#endif
}

GMSH_API void gmsh::fltk::openTreeItem(const std::string &name)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->openTreeItem(name);
#endif
}

GMSH_API void gmsh::fltk::closeTreeItem(const std::string &name)
{
  if(!_checkInit()) return;
#if defined(HAVE_FLTK)
  _createFltk();
  FlGui::instance()->closeTreeItem(name);
#endif
}

// gmsh::parser

GMSH_API void gmsh::parser::getNames(std::vector<std::string> &names,
                                     const std::string &search)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  names.clear();
  if(search.empty()) {
    for(auto &p : gmsh_yysymbols) names.push_back(p.first);
    for(auto &p : gmsh_yystringsymbols) names.push_back(p.first);
  }
  else{
    try{
      for(auto &p : gmsh_yysymbols) {
        if(std::regex_search(p.first, std::regex(search)))
          names.push_back(p.first);
      }
      for(auto &p : gmsh_yystringsymbols) {
        if(std::regex_search(p.first, std::regex(search)))
          names.push_back(p.first);
      }
    }
    catch(...) {
    }
  }
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::setNumber(const std::string &name,
                                      const std::vector<double> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  gmsh_yysymbol &s(gmsh_yysymbols[name]);
  s.list = (value.size() != 1);
  s.value = value;
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::getNumber(const std::string &name,
                                      std::vector<double> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  value = gmsh_yysymbols[name].value;
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::setString(const std::string &name,
                                      const std::vector<std::string> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  gmsh_yystringsymbols[name] = value;
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::getString(const std::string &name,
                                      std::vector<std::string> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  value = gmsh_yystringsymbols[name];
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::clear(const std::string &name)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  if(name.empty()) {
    gmsh_yysymbols.clear();
    gmsh_yystringsymbols.clear();
  }
  else {
    {
      auto it = gmsh_yysymbols.find(name);
      if(it != gmsh_yysymbols.end())
        gmsh_yysymbols.erase(it);
    }
    {
      auto it = gmsh_yystringsymbols.find(name);
      if(it != gmsh_yystringsymbols.end())
        gmsh_yystringsymbols.erase(it);
    }
  }
#else
  Msg::Error("Parser not available");
#endif
}

GMSH_API void gmsh::parser::parse(const std::string &fileName)
{
  if(!_checkInit()) return;
#if defined(HAVE_PARSER)
  ParseFile(fileName, true, true);
#else
  Msg::Error("Parser not available");
#endif
}

// gmsh::onelab

GMSH_API void gmsh::onelab::set(const std::string &data,
                                const std::string &format)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  if(format == "json") {
    if(!::onelab::server::instance()->fromJSON(data))
      Msg::Error("Could not parse json data '%s'", data.c_str());
  }
  else
    Msg::Error("Unknown data format");
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::get(std::string &data, const std::string &name,
                                const std::string &format)
{
  if(!_checkInit()) return;
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
#endif
}

GMSH_API void gmsh::onelab::getNames(std::vector<std::string> &names,
                                     const std::string &search)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  ::onelab::server::instance()->getParameterNames(names, search);
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::setNumber(const std::string &name,
                                      const std::vector<double> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  ::onelab::number p(name);
  std::vector< ::onelab::number> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) p = ps[0];
  p.setValues(value);
  ::onelab::server::instance()->set(p, "Gmsh");
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::getNumber(const std::string &name,
                                      std::vector<double> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  value.clear();
  std::vector< ::onelab::number> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) value = ps[0].getValues();
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::setString(const std::string &name,
                                      const std::vector<std::string> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  ::onelab::string p(name);
  std::vector< ::onelab::string> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) p = ps[0];
  p.setValues(value);
  ::onelab::server::instance()->set(p, "Gmsh");
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::getString(const std::string &name,
                                      std::vector<std::string> &value)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  value.clear();
  std::vector< ::onelab::string> ps;
  ::onelab::server::instance()->get(ps, name);
  if(ps.size()) value = ps[0].getValues();
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API int gmsh::onelab::getChanged(const std::string &name)
{
  if(!_checkInit()) return 0;
#if defined(HAVE_ONELAB)
  return ::onelab::server::instance()->getChanged(name);
#else
  Msg::Error("ONELAB not available");
  return 0;
#endif
}

GMSH_API void gmsh::onelab::setChanged(const std::string &name, const int value)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  ::onelab::server::instance()->setChanged(value, name);
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::clear(const std::string &name)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  ::onelab::server::instance()->clear(name);
#else
  Msg::Error("ONELAB not available");
#endif
}

GMSH_API void gmsh::onelab::run(const std::string &name,
                                const std::string &command)
{
  if(!_checkInit()) return;
#if defined(HAVE_ONELAB)
  onelabUtils::runClient(name, command);
#endif
}

// gmsh::logger

GMSH_API void gmsh::logger::write(const std::string &message,
                                  const std::string &level)
{
  if(!_checkInit()) return;
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
#pragma omp critical(apiMsg)
    _log.push_back(level + ": " + message);
  }
  void get(std::vector<std::string> &log) const { log = _log; }
};

GMSH_API void gmsh::logger::start()
{
  if(!_checkInit()) return;
  GmshMessage *msg = Msg::GetCallback();
  if(msg) { Msg::Warning("Logger already started - ignoring"); }
  else {
    msg = new apiMsg();
    Msg::SetCallback(msg);
  }
}

GMSH_API void gmsh::logger::get(std::vector<std::string> &log)
{
  if(!_checkInit()) return;
  apiMsg *msg = dynamic_cast<apiMsg *>(Msg::GetCallback());
  if(msg) { msg->get(log); }
  else {
    log.clear();
  }
}

GMSH_API void gmsh::logger::stop()
{
  if(!_checkInit()) return;
  GmshMessage *msg = Msg::GetCallback();
  if(msg) {
    delete msg;
    Msg::SetCallback(nullptr);
  }
  else {
    Msg::Warning("Logger not started - ignoring");
  }
}

GMSH_API double gmsh::logger::getWallTime()
{
  if(!_checkInit()) return -1;
  return TimeOfDay();
}

GMSH_API double gmsh::logger::getCpuTime()
{
  if(!_checkInit()) return -1;
  return Cpu();
}

GMSH_API double gmsh::logger::getMemory()
{
  if(!_checkInit()) return -1;
  return GetMemoryUsage()/1024./1024.;
}

GMSH_API double gmsh::logger::getTotalMemory()
{
  if(!_checkInit()) return -1;
  return TotalRam();
}

GMSH_API void gmsh::logger::getLastError(std::string &error)
{
  if(!_checkInit()) return;
  error = Msg::GetLastError();
}
