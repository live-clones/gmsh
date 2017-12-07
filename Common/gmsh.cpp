// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshGlobal.h"
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
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "ExtrudeParams.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "Field.h"
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

#include "gmsh.h" // automatically generated, in gmsh/api

static int _initialized = 0;
static int _argc = 0;
static char **_argv = 0;

static bool _isInitialized()
{
  if(!_initialized){
    // make sure stuff gets printed out
    CTX::instance()->terminal = 1;
    Msg::Error("Gmsh has not been initialized");
    return false;
  }
  return true;
}

// gmsh

void gmsh::initialize(int argc, char **argv, bool readConfigFiles)
{
  if(_initialized){
    Msg::Error("Gmsh has aleady been initialized");
    throw 1;
  }
  if(GmshInitialize(argc, argv, readConfigFiles)){
    _initialized = 1;
    _argc = argc;
    _argv = new char*[_argc + 1];
    for(int i = 0; i < argc; i++) _argv[i] = argv[i];
    return;
  }
  throw -1;
}

void gmsh::finalize()
{
  if(!_isInitialized()){ throw -1; }
  if(GmshFinalize()){
    _argc = 0;
    if(_argv) delete [] _argv;
    _argv = 0;
    _initialized = 0;
    return;
  }
  Msg::Error("Something went wrong when finalizing Gmsh");
  throw 1;
}

void gmsh::open(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshOpenProject(fileName)) return;
  throw 1;
}

void gmsh::merge(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshMergeFile(fileName)) return;
  throw 1;
}

void gmsh::write(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshWriteFile(fileName)) return;
  throw 1;
}

void gmsh::clear()
{
  if(!_isInitialized()){ throw -1; }
  if(GmshClearProject()) return;
  throw 1;
}

// gmsh::option

static void _splitOptionName(const std::string &fullName, std::string &category,
                             std::string &name, int &index)
{
  std::string::size_type d = fullName.find_first_of('.');
  if(d == std::string::npos){
    name = fullName;
    return;
  }
  category = fullName.substr(0, d);
  std::string::size_type b1 = fullName.find_first_of('[');
  std::string::size_type b2 = fullName.find_last_of(']');
  if(b1 != std::string::npos && b2 != std::string::npos){
    std::string id = fullName.substr(b1 + 1, b2 - b1 - 1);
    index = atoi(id.c_str());
    category = fullName.substr(0, b1);
    name = fullName.substr(d + 1, b1 - d);
  }
  else{
    index = 0;
    name = fullName.substr(d + 1);
  }
  Msg::Debug("Decoded option name '%s' . '%s' (index %d)", category.c_str(),
             name.c_str(), index);
}

void gmsh::option::setNumber(const std::string &name, const double value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

void gmsh::option::getNumber(const std::string &name, double &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

void gmsh::option::setString(const std::string &name, const std::string &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

void gmsh::option::getString(const std::string &name, std::string &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

// gmsh::model

void gmsh::model::add(const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = new GModel(name);
  if(!m){ throw 1; }
}

void gmsh::model::remove()
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::current();
  if(!m){ throw 1; }
  delete m;
}

void gmsh::model::list(std::vector<std::string> &names)
{
  if(!_isInitialized()){ throw -1; }
  for(unsigned int i = 0; i < GModel::list.size(); i++)
    names.push_back(GModel::list[i]->getName());
}

void gmsh::model::setCurrent(const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::findByName(name);
  if(!m){ throw 1; }
  GModel::setCurrent(m);
}

void gmsh::model::getEntities(vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()){ throw -1; }
  dimTags.clear();
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
}

void gmsh::model::getPhysicalGroups(vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()){ throw -1; }
  dimTags.clear();
  std::map<int, std::vector<GEntity*> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  for(int d = 0; d < 4; d++){
    if(dim < 0 || d == dim){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[d].begin();
          it != groups[d].end(); it++)
        dimTags.push_back(std::pair<int, int>(d, it->first));
    }
  }
}

void gmsh::model::getEntitiesForPhysicalGroup(const int dim, const int tag,
                                              std::vector<int> &tags)
{
  if(!_isInitialized()){ throw -1; }
  tags.clear();
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups.find(tag);
  if(it != groups.end()){
    for(unsigned j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
}

int gmsh::model::addPhysicalGroup(const int dim, const std::vector<int> &tags,
                                  const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(outTag < 0)
    outTag = GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1;
  if(!GModel::current()->getGEOInternals()->modifyPhysicalGroup
     (dim, outTag, 0, tags)){
    throw 1;
  }
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  return outTag;
}

void gmsh::model::setPhysicalName(const int dim, const int tag,
                                  const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->setPhysicalName(name, dim, tag);
}

void gmsh::model::getPhysicalName(const int dim, const int tag, std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  name = GModel::current()->getPhysicalName(dim, tag);
}

void gmsh::model::getBoundary(const vector_pair &dimTags, vector_pair &outDimTags,
                              const bool combined, const bool oriented,
                              const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getBoundaryTags(dimTags, outDimTags, combined,
                                         oriented, recursive)){
    throw 1;
  }
}

void gmsh::model::getEntitiesInBoundingBox(const double xmin, const double ymin,
                                           const double zmin, const double xmax,
                                           const double ymax, const double zmax,
                                           vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()){ throw -1; }
  dimTags.clear();
  SBoundingBox3d box(xmin, ymin, zmin, xmax, ymax, zmax);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
}

static std::string _entityName(int dim, int tag)
{
  std::stringstream stream;
  switch(dim){
  case 0 : stream << "Point "; break;
  case 1 : stream << "Line "; break;
  case 2 : stream << "Surface "; break;
  case 3 : stream << "Volume "; break;
  }
  stream << tag;
  return stream.str();
}

void gmsh::model::getBoundingBox(const int dim, const int tag, double &xmin,
                                 double &ymin, double &zmin, double &xmax,
                                 double &ymax, double &zmax)
{
  if(!_isInitialized()){ throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  SBoundingBox3d box = ge->bounds();
  if(box.empty()){ throw(3); }
  xmin = box.min().x();
  ymin = box.min().y();
  zmin = box.min().z();
  xmax = box.max().x();
  ymax = box.max().y();
  zmax = box.max().z();
}

int gmsh::model::addDiscreteEntity(const int dim, const int tag,
                                   const std::vector<int> &boundary)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(outTag < 0){
    outTag = GModel::current()->getMaxElementaryNumber(dim);
  }
  GEntity *e = GModel::current()->getEntityByTag(dim, outTag);
  if(e){
    Msg::Error("%s already exists", _entityName(dim, outTag).c_str());
    throw 2;
  }
  // FIXME: check and set boundary entities to construct topology!
  switch(dim){
  case 0: {
    GVertex *gv = new discreteVertex(GModel::current(), outTag);
    GModel::current()->add(gv);
    e = gv;
    break;
  }
  case 1: {
    GEdge *ge = new discreteEdge(GModel::current(), outTag, 0, 0);
    GModel::current()->add(ge);
    break;
  }
  case 2: {
    GFace *gf = new discreteFace(GModel::current(), outTag);
    GModel::current()->add(gf);
    break;
  }
  case 3: {
    GRegion *gr = new discreteRegion(GModel::current(), outTag);
    GModel::current()->add(gr);
    break;
  }
  default :
    throw 2;
  }
  return outTag;
}

void gmsh::model::removeEntities(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->remove(dimTags, recursive);
}

// gmsh::model::mesh

void gmsh::model::mesh::generate(int dim)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::current();
  if(!m){ throw 1; }
  m->mesh(dim);
}

void gmsh::model::mesh::getLastEntityError(vector_pair &dimTags)
{
  if(!_isInitialized()){ throw -1; }
  std::vector<GEntity*> e = GModel::current()->getLastMeshEntityError();
  dimTags.clear();
  for(unsigned int i = 0; i < e.size(); i++)
    dimTags.push_back(std::pair<int, int>(e[i]->dim(), e[i]->tag()));
}

void gmsh::model::mesh::getLastVertexError(std::vector<int> &vertexTags)
{
  if(!_isInitialized()){ throw -1; }
  std::vector<MVertex*> v = GModel::current()->getLastMeshVertexError();
  vertexTags.clear();
  for(unsigned int i = 0; i < v.size(); i++)
    vertexTags.push_back(v[i]->getNum());
}

void gmsh::model::mesh::getVertices(const int dim, const int tag,
                                    std::vector<int> &vertexTags,
                                    std::vector<double> &coord,
                                    std::vector<double> &parametricCoord)
{
  if(!_isInitialized()){ throw -1; }
  vertexTags.clear();
  coord.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  for(unsigned int i = 0; i < ge->mesh_vertices.size(); i++){
    MVertex *v = ge->mesh_vertices[i];
    vertexTags.push_back(v->getNum());
    coord.push_back(v->x());
    coord.push_back(v->y());
    coord.push_back(v->z());
    double par;
    for(int j = 0; j < dim; j++){
      if(v->getParameter(j, par)) parametricCoord.push_back(par);
    }
  }
}

template<class T>
static void _addElementInfo(const std::vector<T*> &ele,
                            std::vector<int> &elementType,
                            std::vector<std::vector<int> > &elementTags,
                            std::vector<std::vector<int> > &vertexTags)
{
  if(ele.empty()) return;
  elementType.push_back(ele.front()->getTypeForMSH());
  elementTags.push_back(std::vector<int>());
  vertexTags.push_back(std::vector<int>());
  for(unsigned int i = 0; i < ele.size(); i++){
    elementTags.back().push_back(ele[i]->getNum());
    for(unsigned int j = 0; j < ele[i]->getNumVertices(); j++){
      vertexTags.back().push_back(ele[i]->getVertex(j)->getNum());
    }
  }
}

void gmsh::model::mesh::getElements(const int dim, const int tag,
                                    std::vector<int> &types,
                                    std::vector<std::vector<int> > &elementTags,
                                    std::vector<std::vector<int> > &vertexTags)
{
  if(!_isInitialized()){ throw -1; }
  types.clear();
  elementTags.clear();
  vertexTags.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  switch(dim){
  case 0: {
    GVertex *v = static_cast<GVertex*>(ge);
    _addElementInfo(v->points, types, elementTags, vertexTags);
    break; }
  case 1: {
    GEdge *e = static_cast<GEdge*>(ge);
    _addElementInfo(e->lines, types, elementTags, vertexTags);
    break; }
  case 2: {
    GFace *f = static_cast<GFace*>(ge);
    _addElementInfo(f->triangles, types, elementTags, vertexTags);
    _addElementInfo(f->quadrangles, types, elementTags, vertexTags);
    break; }
  case 3: {
    GRegion *r = static_cast<GRegion*>(ge);
    _addElementInfo(r->tetrahedra, types, elementTags, vertexTags);
    _addElementInfo(r->hexahedra, types, elementTags, vertexTags);
    _addElementInfo(r->prisms, types, elementTags, vertexTags);
    _addElementInfo(r->pyramids, types, elementTags, vertexTags);
    break; }
  }
}

void gmsh::model::mesh::setVertices(const int dim, const int tag,
                                    const std::vector<int> &vertexTags,
                                    const std::vector<double> &coord,
                                    const std::vector<double> &parametricCoord)
{
  if(!_isInitialized()){ throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  if(coord.size() != 3 * vertexTags.size()){
    Msg::Error("Wrong number of coord");
    throw 2;
  }
  bool param = false;
  if(parametricCoord.size()){
    if(parametricCoord.size() != dim * vertexTags.size()){
      Msg::Error("Wrong number of parametric coord");
      throw 2;
    }
    param = true;
  }
  // delete vertices and elements; this will also delete the model mesh cache
  ge->deleteMesh();
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int n = vertexTags[i];
    double x = coord[3 * i];
    double y = coord[3 * i + 1];
    double z = coord[3 * i + 2];
    MVertex *vv = 0;
    if(param && dim == 1){
      double u = parametricCoord[i];
      vv = new MEdgeVertex(x, y, z, ge, u, n);
    }
    else if(param && dim == 2){
      double u = parametricCoord[2 * i];
      double v = parametricCoord[2 * i + 1];
      vv = new MFaceVertex(x, y, z, ge, u, v, n);
    }
    else
      vv = new MVertex(x, y, z, ge, n);
    ge->mesh_vertices.push_back(vv);
  }
}

template<class T>
static void _addElements(int dim, int tag, const std::vector<MElement*> &src,
                         std::vector<T*> &dst)
{
  for(unsigned int i = 0; i < src.size(); i++)
    dst.push_back(static_cast<T*>(src[i]));
}

void gmsh::model::mesh::setElements(const int dim, const int tag,
                                    const std::vector<int> &types,
                                    const std::vector<std::vector<int> > &elementTags,
                                    const std::vector<std::vector<int> > &vertexTags)
{
  if(!_isInitialized()){ throw -1; }
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  if(types.size() != elementTags.size()){
    Msg::Error("Wrong number of element tags");
    throw 2;
  }
  if(types.size() != vertexTags.size()){
    Msg::Error("Wrong number of vertex tags");
    throw 2;
  }
  // delete only elements; this will also delete the model mesh cache
  ge->deleteMesh(true);
  for(unsigned int i = 0; i < types.size(); i++){
    int type = types[i];
    unsigned int numEle = elementTags[i].size();
    unsigned int numVertPerEle = MElement::getInfoMSH(type);
    if(!numEle) continue;
    if(numEle * numVertPerEle != vertexTags[i].size()){
      Msg::Error("Wrong number of vertex tags for element type %d", type);
      throw 2;
    }
    std::vector<MElement*> elements(numEle);
    std::vector<MVertex*> vertices(numVertPerEle);
    for(unsigned int j = 0; j < numEle; j++){
      int etag = elementTags[i][j];
      MElementFactory f;
      for(unsigned int k = 0; k < numVertPerEle; k++){
        int vtag = vertexTags[i][numVertPerEle * j + k];
        // this will rebuild the vertex cache if necessary
        vertices[k] = GModel::current()->getMeshVertexByTag(vtag);
        if(!vertices[k]){
          Msg::Error("Unknown mesh vertex %d", vtag);
          throw 2;
        }
      }
      elements[j] = f.create(type, vertices, etag);
    }
    bool ok = true;
    switch(dim){
    case 0:
      if(elements[0]->getType() == TYPE_PNT)
        _addElements(dim, tag, elements, static_cast<GVertex*>(ge)->points);
      else
        ok = false;
      break;
    case 1:
      if(elements[0]->getType() == TYPE_LIN)
        _addElements(dim, tag, elements, static_cast<GEdge*>(ge)->lines);
      else
        ok = false;
     break;
    case 2:
      if(elements[0]->getType() == TYPE_TRI)
        _addElements(dim, tag, elements, static_cast<GFace*>(ge)->triangles);
      else if(elements[0]->getType() == TYPE_QUA)
        _addElements(dim, tag, elements, static_cast<GFace*>(ge)->quadrangles);
      else
        ok = false;
      break;
    case 3:
      if(elements[0]->getType() == TYPE_TET)
        _addElements(dim, tag, elements, static_cast<GRegion*>(ge)->tetrahedra);
      else if(elements[0]->getType() == TYPE_HEX)
        _addElements(dim, tag, elements, static_cast<GRegion*>(ge)->hexahedra);
      else if(elements[0]->getType() == TYPE_PRI)
        _addElements(dim, tag, elements, static_cast<GRegion*>(ge)->prisms);
      else if(elements[0]->getType() == TYPE_PYR)
        _addElements(dim, tag, elements, static_cast<GRegion*>(ge)->pyramids);
      else
        ok = false;
      break;
    }
    if(!ok){
      Msg::Error("Wrong type of element for %s", _entityName(dim, tag).c_str());
      throw 2;
    }
  }
}

void gmsh::model::mesh::getVertex(const int vertexTag,
                                  std::vector<double> &coord,
                                  std::vector<double> &parametricCoord)
{
  if(!_isInitialized()){ throw -1; }
  MVertex *v = GModel::current()->getMeshVertexByTag(vertexTag);
  if(!v){
    Msg::Error("Unknown mesh vertex %d", vertexTag);
    throw 2;
  }
  coord.clear();
  coord.push_back(v->x());
  coord.push_back(v->x());
  coord.push_back(v->x());
  parametricCoord.clear();
  double u;
  if(v->getParameter(0, u))
    parametricCoord.push_back(u);
  if(v->getParameter(1, u))
    parametricCoord.push_back(u);
}

void gmsh::model::mesh::getElement(const int elementTag, int &type,
                                   std::vector<int> &vertexTags)
{
  if(!_isInitialized()){ throw -1; }
  MElement *e = GModel::current()->getMeshElementByTag(elementTag);
  if(!e){
    Msg::Error("Unknown mesh element %d", elementTag);
    throw 2;
  }
  type = e->getTypeForMSH();
  vertexTags.clear();
  for(int i = 0; i < e->getNumVertices(); i++){
    MVertex *v = e->getVertex(i);
    if(!v){
      Msg::Error("Unknown mesh vertex in element %d", elementTag);
      throw 2;
    }
    vertexTags.push_back(v->getNum());
  }
}

void gmsh::model::mesh::setSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()){ throw -1; }
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 0){
      GVertex *gv = GModel::current()->getVertexByTag(tag);
      if(gv) gv->setPrescribedMeshSizeAtVertex(size);
    }
  }
}

void gmsh::model::mesh::setTransfiniteLine(const int tag, const int numVertices,
                                           const std::string &type,
                                           const double coef)
{
  if(!_isInitialized()){ throw -1; }
  GEdge *ge = GModel::current()->getEdgeByTag(tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(1, tag).c_str());
    throw 2;
  }
  ge->meshAttributes.method = MESH_TRANSFINITE;
  ge->meshAttributes.nbPointsTransfinite = numVertices;
  ge->meshAttributes.typeTransfinite =
    (type == "Progression" || type == "Power") ? 1 :
    (type == "Bump") ? 2 :
    1;
  ge->meshAttributes.coeffTransfinite = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) ge->meshAttributes.typeTransfinite *= -1;
}

void gmsh::model::mesh::setTransfiniteSurface(const int tag,
                                              const std::string &arrangement,
                                              const std::vector<int> &cornerTags)
{
  if(!_isInitialized()){ throw -1; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(2, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.method = MESH_TRANSFINITE;
  gf->meshAttributes.transfiniteArrangement =
    (arrangement == "Right") ? 1 :
    (arrangement == "Left") ? -1 :
    (arrangement == "AlternateRight") ? 2 :
    (arrangement == "AlternateLeft") ? -2 :
    (arrangement == "Alternate") ? 2 :
    -1;
  if(cornerTags.empty() || cornerTags.size() == 3 || cornerTags.size() == 4){
    for(unsigned int j = 0; j < cornerTags.size(); j++){
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[j]);
      if(gv)
        gf->meshAttributes.corners.push_back(gv);
    }
  }
}

void gmsh::model::mesh::setTransfiniteVolume(const int tag,
                                             const std::vector<int> &cornerTags)
{
  if(!_isInitialized()){ throw -1; }
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr){
    Msg::Error("%s does not exist", _entityName(3, tag).c_str());
    throw 2;
  }
  gr->meshAttributes.method = MESH_TRANSFINITE;
  if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8){
    for(unsigned int i = 0; i < cornerTags.size(); i++){
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[i]);
      if(gv)
        gr->meshAttributes.corners.push_back(gv);
    }
  }
}

void gmsh::model::mesh::setRecombine(const int dim, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  if(dim != 2){ throw 2; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.recombine = 1;
  gf->meshAttributes.recombineAngle = 45.;
}

void gmsh::model::mesh::setSmoothing(const int dim, const int tag, const int val)
{
  if(!_isInitialized()){ throw -1; }
  if(dim != 2){ throw 2; }
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    throw 2;
  }
  gf->meshAttributes.transfiniteSmoothing = val;
}

void gmsh::model::mesh::setReverse(const int dim, const int tag, const bool val)
{
  if(!_isInitialized()){ throw -1; }
  if(dim == 1){
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(!ge){
      Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
      throw 2;
    }
    ge->meshAttributes.reverseMesh = val;
  }
  else if(dim == 2){
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf){
      Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
      throw 2;
    }
    gf->meshAttributes.reverseMesh = val;
  }
}

void gmsh::model::mesh::embed(const int dim, const std::vector<int> &tags,
                              const int inDim, const int inTag)
{
  if(!_isInitialized()){ throw -1; }
  if(inDim == 2){
    GFace *gf = GModel::current()->getFaceByTag(inTag);
    if(!gf){
      Msg::Error("%s does not exist", _entityName(2, inTag).c_str());
      throw 2;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv){
          Msg::Error("%s does not exist", _entityName(0, tags[i]).c_str());
          throw 2;
        }
        gf->addEmbeddedVertex(gv);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge){
          Msg::Error("%s does not exist", _entityName(1, tags[i]).c_str());
          throw 2;
        }
        gf->addEmbeddedEdge(ge);
      }
    }
  }
  else if(inDim == 3){
    GRegion *gr = GModel::current()->getRegionByTag(inTag);
    if(!gr){
      Msg::Error("%s does not exist", _entityName(3, inTag).c_str());
      throw 2;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv){
          Msg::Error("%s does not exist", _entityName(0, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedVertex(gv);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge){
          Msg::Error("%s does not exist", _entityName(1, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedEdge(ge);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(!gf){
          Msg::Error("%s does not exist", _entityName(2, tags[i]).c_str());
          throw 2;
        }
        gr->addEmbeddedFace(gf);
      }
    }
  }
}

// gmsh::model::mesh::field

int gmsh::model::mesh::field::add(const std::string &type, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
#if defined(HAVE_MESH)
  if(outTag < 0){
    outTag = GModel::current()->getFields()->newId();
  }
  if(!GModel::current()->getFields()->newField(tag, type)){
    Msg::Error("Cannot add Field %i of type '%s'", tag, type.c_str());
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
  return outTag;
}

void gmsh::model::mesh::field::remove(const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->deleteField(tag);
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

#if defined(HAVE_MESH)
static FieldOption *_getFieldOption(const int tag, const std::string &option)
{
  Field *field = GModel::current()->getFields()->get(tag);
  if(!field){
    Msg::Error("No field with id %i", tag);
    return 0;
  }
  FieldOption *o = field->options[option];
  if(!o){
    Msg::Error("Unknown option '%s' in field %i of type '%s'", option.c_str(),
               tag, field->getName());
    return 0;
  }
  return o;
}
#endif

void gmsh::model::mesh::field::setNumber(const int tag, const std::string &option,
                                         const double value)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o){ throw 1; }
  try { o->numericalValue(value); }
  catch(...){
    Msg::Error("Cannot set numerical value to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

void gmsh::model::mesh::field::setString(const int tag, const std::string &option,
                                         const std::string &value)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o){ throw 1; }
  try { o->string(value); }
  catch(...){
    Msg::Error("Cannot set string value to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

void gmsh::model::mesh::field::setNumbers(const int tag, const std::string &option,
                                          const std::vector<double> &value)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o){ throw 1; }
  try {
    if(o->getType() == FIELD_OPTION_LIST) {
      std::list<int> vl;
      for(unsigned int i = 0; i < value.size(); i++)
        vl.push_back((int)value[i]);
      o->list(vl);
    }
    else{
      std::list<double> vl;
      for(unsigned int i = 0; i < value.size(); i++)
        vl.push_back(value[i]);
      o->listdouble(vl);
    }
  }
  catch(...){
    Msg::Error("Cannot set numeric values to option '%s' in field %i",
               option.c_str(), tag);
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

void gmsh::model::mesh::field::setAsBackground(const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

// gmsh::model::geo

int gmsh::model::geo::addPoint(const double x, const double y, const double z,
                               const double meshSize, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  if(!GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, zz, lc)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addLine(const int startTag, const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addCircleArc(const int startTag, const int centerTag,
                                   const int endTag, const int tag, const double nx,
                                   const double ny, const double nz)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addCircleArc
     (outTag, startTag, centerTag, endTag, nx, ny, nz)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addEllipseArc(const int startTag, const int centerTag,
                                    const int majorTag, const int endTag,
                                    const int tag, const double nx, const double ny,
                                    const double nz)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addEllipseArc
     (outTag, startTag, centerTag, majorTag, endTag, nx, ny, nz)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addSpline(const std::vector<int> &vertexTags,
                                const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addBSpline(const std::vector<int> &vertexTags,
                                 const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addBezier(const std::vector<int> &vertexTags,
                                const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBezier(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addLineLoop(const std::vector<int> &edgeTags,
                                  const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLineLoop(outTag, edgeTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addPlaneSurface(const std::vector<int> &wireTags,
                                      const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addSurfaceFilling(const std::vector<int> &wireTags,
                                        const int tag,
                                        const int sphereCenterTag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSurfaceFilling
     (outTag, wireTags, sphereCenterTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addSurfaceLoop(const std::vector<int> &faceTags,
                                     const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSurfaceLoop(outTag, faceTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::geo::addVolume(const std::vector<int> &shellTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addVolume(outTag, shellTags)){
    throw 1;
  }
  return outTag;
}

static ExtrudeParams *_getExtrudeParams(const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine)
{
  ExtrudeParams *e = 0;
  if(numElements.size()){
    e = new ExtrudeParams();
    e->mesh.ExtrudeMesh = true;
    e->mesh.NbElmLayer = numElements;
    e->mesh.hLayer = heights;
    if(e->mesh.hLayer.empty()){
      e->mesh.NbLayer = 1;
      e->mesh.hLayer.push_back(1.);
    }
    else{
      e->mesh.NbLayer = heights.size();
    }
    e->mesh.Recombine = recombine;
  }
  return e;
}

void gmsh::model::geo::extrude(const vector_pair &dimTags,
                               const double dx, const double dy, const double dz,
                               vector_pair &outDimTags,
                               const std::vector<int> &numElements,
                               const std::vector<double> &heights,
                               const bool recombine)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->extrude
     (dimTags, dx, dy, dz, outDimTags,
      _getExtrudeParams(numElements, heights, recombine))){
    throw 1;
  }
}

void gmsh::model::geo::revolve(const vector_pair &dimTags,
                               const double x, const double y, const double z,
                               const double ax, const double ay, const double az,
                               const double angle,
                               vector_pair &outDimTags,
                               const std::vector<int> &numElements,
                               const std::vector<double> &heights,
                               const bool recombine)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->revolve
     (dimTags, x, y, z, ax, ay, az, angle, outDimTags,
      _getExtrudeParams(numElements, heights, recombine))){
    throw 1;
  }
}

void gmsh::model::geo::twist(const vector_pair &dimTags,
                             const double x, const double y, const double z,
                             const double dx, const double dy, const double dz,
                             const double ax, const double ay, const double az,
                             const double angle,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements,
                             const std::vector<double> &heights,
                             const bool recombine)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->twist
     (dimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags,
      _getExtrudeParams(numElements, heights, recombine))){
    throw 1;
  }
}

void gmsh::model::geo::translate(const vector_pair &dimTags, const double dx,
                                 const double dy, const double dz)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz)){
    throw 1;
  }
}

void gmsh::model::geo::rotate(const vector_pair &dimTags, const double x,
                              const double y, const double z, const double ax,
                              const double ay, const double az, const double angle)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->rotate
     (dimTags, x, y, z, ax, ay, az, angle)){
    throw 1;
  }
}

void gmsh::model::geo::dilate(const vector_pair &dimTags, const double x,
                              const double y, const double z, const double a,
                              const double b, const double c)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->dilate
     (dimTags, x, y, z, a, b, c)){
    throw 1;
  }
}

void gmsh::model::geo::symmetry(const vector_pair &dimTags, const double a,
                                const double b, const double c, const double d)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->symmetry
     (dimTags, a, b, c, d)){
    throw 1;
  }
}

void gmsh::model::geo::copy(const vector_pair &dimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->copy(dimTags, outDimTags)){
    throw 1;
  }
}

void gmsh::model::geo::remove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->remove(dimTags, recursive)){
    throw 1;
  }
}

void gmsh::model::geo::removeAllDuplicates()
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->removeAllDuplicates();
}

void gmsh::model::geo::synchronize()
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
}

// gmsh::model::geo::mesh

void gmsh::model::geo::mesh::setTransfiniteLine(const int tag, const int nPoints,
                                                const std::string &type,
                                                const double coef)
{
  if(!_isInitialized()){ throw -1; }
  int t =
    (type == "Progression" || type == "Power") ? 1 :
    (type == "Bump") ? 2 :
    1;
  double c = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) t = -t;
  GModel::current()->getGEOInternals()->setTransfiniteLine(tag, nPoints, t, c);
}

void gmsh::model::geo::mesh::setTransfiniteSurface(const int tag,
                                                   const std::string &arrangement,
                                                   const std::vector<int> &cornerTags)
{
  if(!_isInitialized()){ throw -1; }
  int t =
    (arrangement == "Right") ? 1 :
    (arrangement == "Left") ? -1 :
    (arrangement == "AlternateRight") ? 2 :
    (arrangement == "AlternateLeft") ? -2 :
    (arrangement == "Alternate") ? 2 :
    -1;
  GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, t, cornerTags);
}

void gmsh::model::geo::mesh::setTransfiniteVolume(const int tag,
                                                  const std::vector<int> &cornerTags)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, cornerTags);
}

void gmsh::model::geo::mesh::setRecombine(const int dim, const int tag,
                                          const double angle)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setRecombine(dim, tag, angle);
}

void gmsh::model::geo::mesh::setSmoothing(const int dim, const int tag, const int val)
{
  if(!_isInitialized()){ throw -1; }
  if(dim != 2){ throw 2; }
  GModel::current()->getGEOInternals()->setSmoothing(tag, val);
}

void gmsh::model::geo::mesh::setReverse(const int dim, const int tag, const bool val)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setReverseMesh(dim, tag, val);
}

void gmsh::model::geo::mesh::setSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()){ throw -1; }
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getGEOInternals()->setMeshSize(dim, tag, size);
  }
}

// gmsh::model::occ

static void _createOcc()
{
  if(!GModel::current()->getOCCInternals()) GModel::current()->createOCCInternals();
}

int gmsh::model::occ::addPoint(const double x, const double y, const double z,
                               const double meshSize, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addVertex(outTag, x, y, z, meshSize)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addLine(const int startTag, const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addCircleArc(const int startTag, const int centerTag,
                                   const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCircleArc
     (outTag, startTag, centerTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addCircle(const double x, const double y, const double z,
                                const double r, const int tag,
                                const double angle1, const double angle2)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCircle
     (outTag, x, y, z, r, angle1, angle2)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addEllipseArc(const int startTag, const int centerTag,
                                    const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addEllipseArc
     (outTag, startTag, centerTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addEllipse(const double x, const double y, const double z,
                                 const double r1, const double r2,
                                 const int tag,
                                 const double angle1, const double angle2)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addEllipse
     (outTag, x, y, z, r1, r2, angle1, angle2)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addSpline(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addBezier(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBezier(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addWire(const std::vector<int> &edgeTags, const int tag,
                              const bool checkClosed)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addWire
     (outTag, edgeTags, checkClosed)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addLineLoop(const std::vector<int> &edgeTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLineLoop(outTag, edgeTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addRectangle(const double x, const double y, const double z,
                                   const double dx, const double dy, const int tag,
                                   const double roundedRadius)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addRectangle
     (outTag, x, y, z, dx, dy, roundedRadius)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addDisk(const double xc, const double yc, const double zc,
                              const double rx, const double ry, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addDisk
     (outTag, xc, yc, zc, rx, ry)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addPlaneSurface(const std::vector<int> &wireTags,
                                      const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addSurfaceFilling(const int wireTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceFilling(outTag, wireTag)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addSurfaceLoop(const std::vector<int> &faceTags,
                                     const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, faceTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addVolume(const std::vector<int> &shellTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addVolume(outTag, shellTags)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addSphere(const double xc, const double yc, const double zc,
                                const double radius, const int tag,
                                const double angle1, const double angle2,
                                const double angle3)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSphere
     (outTag, xc, yc, zc, radius, angle1, angle2, angle3)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addBox(const double x, const double y, const double z,
                             const double dx, const double dy, const double dz,
                             const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBox
     (outTag, x, y, z, dx, dy, dz)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addCylinder(const double x, const double y, const double z,
                                  const double dx, const double dy, const double dz,
                                  const double r, const int tag, const double angle)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCylinder
     (outTag, x, y, z, dx, dy, dz, r, angle)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addCone(const double x, const double y, const double z,
                              const double dx, const double dy, const double dz,
                              const double r1, const double r2, const int tag,
                              const double angle)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addCone
     (outTag, x, y, z, dx, dy, dz, r1, r2, angle)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addWedge(const double x, const double y, const double z,
                               const double dx, const double dy, const double dz,
                               const int tag, const double ltx)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addWedge
     (outTag, x, y, z, dx, dy, dz, ltx)){
    throw 1;
  }
  return outTag;
}

int gmsh::model::occ::addTorus(const double x, const double y, const double z,
                               const double r1, const double r2, const int tag,
                               const double angle)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addTorus
     (outTag, x, y, z, r1, r2, angle)){
    throw 1;
  }
  return outTag;
}

void gmsh::model::occ::addThruSections(const std::vector<int> &wireTags,
                                       vector_pair &outDimTags,
                                       const int tag, const bool makeSolid,
                                       const bool makeRuled)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThruSections
     (tag, wireTags, makeSolid, makeRuled, outDimTags)){
    throw 1;
  }
}

void gmsh::model::occ::addThickSolid(const int solidTag,
                                     const std::vector<int> &excludeFaceTags,
                                     const double offset, vector_pair &outDimTags,
                                     const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThickSolid
     (tag, solidTag, excludeFaceTags, offset, outDimTags)){
    throw 1;
  }
}

void gmsh::model::occ::extrude(const vector_pair &dimTags,
                               const double dx, const double dy, const double dz,
                               vector_pair &outDimTags,
                               const std::vector<int> &numElements,
                               const std::vector<double> &heights,
                               const bool recombine)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->extrude
    (dimTags, dx, dy, dz, outDimTags,
     _getExtrudeParams(numElements, heights, recombine))){
    throw 1;
  }
}

void gmsh::model::occ::revolve(const vector_pair &dimTags,
                               const double x, const double y, const double z,
                               const double ax, const double ay, const double az,
                               const double angle, vector_pair &outDimTags,
                               const std::vector<int> &numElements,
                               const std::vector<double> &heights,
                               const bool recombine)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->revolve
     (dimTags, x, y, z, ax, ay, az, angle, outDimTags,
      _getExtrudeParams(numElements, heights, recombine))){
    throw 1;
  }
}

void gmsh::model::occ::addPipe(const vector_pair &dimTags, const int wireTag,
                               vector_pair &outDimTags)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addPipe
     (dimTags, wireTag, outDimTags)){
    throw 1;
  }
}

void gmsh::model::occ::fillet(const std::vector<int> &regionTags,
                              const std::vector<int> &edgeTags,
                              const double radius, vector_pair &outDimTags,
                              const bool removeRegion)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->fillet
     (regionTags, edgeTags, radius, outDimTags, removeRegion)){
    throw 1;
  }
}

void gmsh::model::occ::fuse(const vector_pair &objectDimTags,
                            const vector_pair &toolDimTags,
                            vector_pair &outDimTags,
                            std::vector<vector_pair > &outDimTagsMap,
                            const int tag,
                            const bool removeObject,
                            const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanUnion
     (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
}

void gmsh::model::occ::intersect(const vector_pair &objectDimTags,
                                 const vector_pair &toolDimTags,
                                 vector_pair &outDimTags,
                                 std::vector<vector_pair> &outDimTagsMap,
                                 const int tag,
                                 const bool removeObject,
                                 const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanIntersection
     (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
}

void gmsh::model::occ::cut(const vector_pair &objectDimTags,
                           const vector_pair &toolDimTags,
                           vector_pair &outDimTags,
                           std::vector<vector_pair> &outDimTagsMap,
                           const int tag,
                           const bool removeObject,
                           const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanDifference
     (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
}

void gmsh::model::occ::fragment(const vector_pair &objectDimTags,
                                const vector_pair &toolDimTags,
                                vector_pair &outDimTags,
                                std::vector<vector_pair> &outDimTagsMap,
                                const int tag,
                                const bool removeObject,
                                const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanFragments
     (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
}

void gmsh::model::occ::translate(const vector_pair &dimTags, const double dx,
                                 const double dy, const double dz)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz)){
    throw 1;
  }
}

void gmsh::model::occ::rotate(const vector_pair &dimTags, const double x,
                              const double y, const double z, const double ax,
                              const double ay, const double az, const double angle)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->rotate
     (dimTags, x, y, z, ax, ay, az, angle)){
    throw 1;
  }
}

void gmsh::model::occ::dilate(const vector_pair &dimTags, const double x,
                              const double y, const double z, const double a,
                              const double b, const double c)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->dilate
     (dimTags, x, y, z, a, b, c)){
    throw 1;
  }
}

void gmsh::model::occ::symmetry(const vector_pair &dimTags, const double a,
                                const double b, const double c, const double d)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->symmetry(dimTags, a, b, c, d)){
    throw 1;
  }
}

void gmsh::model::occ::copy(const vector_pair &dimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->copy(dimTags, outDimTags)){
    throw 1;
  }
}

void gmsh::model::occ::remove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->remove(dimTags, recursive)){
    throw 1;
  }
}

void gmsh::model::occ::removeAllDuplicates()
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
}

void gmsh::model::occ::importShapes(const std::string &fileName,
                                    vector_pair &outDimTags,
                                    const bool highestDimOnly,
                                    const std::string &format)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->importShapes
     (fileName, highestDimOnly, outDimTags, format)){
    throw 1;
  }
}

// void gmsh::model::occ::importShapesNativePointer(const void *shape,
//                                                  vector_pair &outDimTags,
//                                                  const bool highestDimOnly)
// {
//   if(!_isInitialized()){ throw -1; }
//   _createOcc();
//   outDimTags.clear();
// #if defined(HAVE_OCC)
//   if(!GModel::current()->getOCCInternals()->importShapes
//      (static_cast<TopoDS_Shape*>(shape), outDimTags, highestDimOnly)){
//     throw 1;
//   }
// #else
//   Msg::Error("Gmsh requires OpenCASCADE to import native shape");
//   throw -1;
// #endif
// }

void gmsh::model::occ::setMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
}

void gmsh::model::occ::synchronize()
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
}

// gmsh::view

int gmsh::view::add(const std::string &name, const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = new PView(tag);
  view->getData()->setName(name);
  return view->getTag();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::remove(const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  delete view;
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

int gmsh::view::getIndex(const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  return view->getIndex();
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::getTags(std::vector<int> &tags)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  tags.clear();
  for(unsigned int i = 0; i < PView::list.size(); i++)
    tags.push_back(PView::list[i]->getTag());
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::addModelData(const int tag, const int step,
                              const std::string &modelName,
                              const std::string &dataType,
                              const std::vector<int> &tags,
                              const std::vector<std::vector<double> > &data,
                              const double time, const int numComponents,
                              const int partition)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  GModel *model = GModel::current();
  if(modelName.size()){
    model = GModel::findByName(modelName);
    if(!model){
      Msg::Error("Unknown model '%s'", modelName.c_str());
      throw 2;
    }
  }
  if(tags.size() != data.size()){
    Msg::Error("Incompatible number of tags and data");
    throw 2;
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel*>(view->getData());
  if(!d){ // change the view type
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
    else{
      Msg::Error("Unknown type of view to add '%s'", dataType.c_str());
      throw 2;
    }
    d = new PViewDataGModel(type);
    d->setName(name);
    d->setFileName(name + ".msh");
    view->setData(d);
  }
  d->addData(model, tags, data, step, time, partition, numComponents);
  if(view->getOptions()->adaptVisualizationGrid)
    d->initAdaptiveData(view->getOptions()->timeStep,
                        view->getOptions()->maxRecursionLevel,
                        view->getOptions()->targetError);
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::getModelData(const int tag, const int step,
                              std::string &dataType, std::vector<int> &tags,
                              std::vector<std::vector<double> > &data,
                              double &time, int &numComponents)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataGModel *d = dynamic_cast<PViewDataGModel*>(view->getData());
  if(!d){
    Msg::Error("View with tag %d does not contain model data", tag);
    throw 2;
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
  if(!s){
    Msg::Error("View with tag %d does not contain model data for step %d",
               tag, step);
    throw 2;
  }
  tags.clear();
  data.clear();
  time = s->getTime();
  numComponents = s->getNumComponents();
  int numEnt = 0;
  for(int i = 0; i < s->getNumData(); i++){
    if(s->getData(i)) numEnt++;
  }
  if(!numEnt) return;
  data.resize(numEnt);
  tags.resize(numEnt);
  int j = 0;
  for(int i = 0; i < s->getNumData(); i++){
    double *dd = s->getData(i);
    if(dd){
      tags[j] = i;
      int mult = s->getMult(i);
      data[j].resize(numComponents * mult);
      for(int k = 0; k < numComponents * mult; k++)
        data[j][k] = dd[k];
      j++;
    }
  }
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::addListData(const int tag, const std::string &type,
                             const int numEle, const std::vector<double> &data)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewDataList *d = dynamic_cast<PViewDataList*>(view->getData());
  if(!d){ // change the view type
    std::string name = view->getData()->getName();
    delete view->getData();
    d = new PViewDataList();
    d->setName(name);
    d->setFileName(name + ".pos");
    view->setData(d);
  }
  const char *types[] = {"SP", "VP", "TP", "SL", "VL", "TL", "ST", "VT", "TT",
                         "SQ", "VQ", "TQ", "SS", "VS", "TS", "SH", "VH", "TH",
                         "SI", "VI", "TI", "SY", "VY", "TY"};
  for(int idxtype = 0; idxtype < 24; idxtype++){
    if(type == types[idxtype]){
      d->importList(idxtype, numEle, data, true);
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

void gmsh::view::probe(const int tag, const double x, const double y,
                       const double z, std::vector<double> &value,
                       const int step, const int numComp,
                       const bool gradient, const double tolerance,
                       const std::vector<double> &xElemCoord,
                       const std::vector<double> &yElemCoord,
                       const std::vector<double> &zElemCoord)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
    Msg::Error("Unknown view with tag %d", tag);
    throw 2;
  }
  PViewData *data = view->getData();
  if(!data){ throw 2; }
  value.clear();
  std::vector<double> val(9 * data->getNumTimeSteps());
  bool found = false;
  int qn = 0;
  double *qx = 0, *qy = 0, *qz = 0;
  if(xElemCoord.size() && yElemCoord.size() && zElemCoord.size() &&
     xElemCoord.size() == yElemCoord.size() &&
     xElemCoord.size() == zElemCoord.size()){
    qn = xElemCoord.size();
    qx = (double*)&xElemCoord[0];
    qy = (double*)&yElemCoord[0];
    qz = (double*)&zElemCoord[0];
  }
  switch(numComp){
  case 1:
    found = data->searchScalarWithTol
      (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    break;
  case 3:
    found = data->searchVectorWithTol
      (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    break;
  case 9:
    found = data->searchTensorWithTol
      (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    break;
  default:
    found = data->searchScalarWithTol
      (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    if(!found)
      found = data->searchVectorWithTol
        (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    if(!found)
      found = data->searchTensorWithTol
        (x, y, z, &val[0], step, 0, tolerance, qn, qx, qy, qz, gradient);
    break;
  }
  if(found)
    value.insert(value.end(), val.begin(), val.end());
#else
  Msg::Error("Views require the post-processing module");
  throw -1;
#endif
}

void gmsh::view::write(const int tag, const std::string &fileName,
                       const bool append)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_POST)
  PView *view = PView::getViewByTag(tag);
  if(!view){
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

void gmsh::plugin::setNumber(const std::string &name, const std::string &option,
                             const double value)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  }
  catch(...) {
    Msg::Error("Unknown plugin or plugin option");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

void gmsh::plugin::setString(const std::string &name, const std::string &option,
                             const std::string &value)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->setPluginOption(name, option, value);
  }
  catch(...) {
    Msg::Error("Unknown plugin or plugin option");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

void gmsh::plugin::run(const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_PLUGINS)
  try {
    PluginManager::instance()->action(name, "Run", 0);
  }
  catch(...) {
    Msg::Error("Unknown plugin or plugin action");
    throw 2;
  }
#else
  Msg::Error("Views require the post-processing and plugin modules");
  throw -1;
#endif
}

// gmsh::graphics

void gmsh::graphics::draw()
{
#if defined(HAVE_OPENGL)
  drawContext::global()->draw();
#endif
}

// gmsh::fltk

void gmsh::fltk::initialize()
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_FLTK)
  FlGui::instance(_argc, _argv);
  FlGui::check();
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

void gmsh::fltk::wait(const double time)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_FLTK)
  if(!FlGui::available())
    FlGui::instance(_argc, _argv);
  if(time >= 0)
    FlGui::wait(time);
  else
    FlGui::wait();
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

void gmsh::fltk::run()
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_FLTK)
  if(!FlGui::available())
    FlGui::instance(_argc, _argv);
  FlGui::instance()->run(); // this calls draw() once
#else
  Msg::Error("Fltk not available");
  throw -1;
#endif
}

// gmsh::onelab

void gmsh::onelab::get(std::string &data, const std::string &format)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_ONELAB)
  if(format == "json")
    ::onelab::server::instance()->toJSON(data, "Gmsh");
  else
    Msg::Error("Unknown data format");
#else
  Msg::Error("Onelab not available");
  throw -1;
#endif
}

void gmsh::onelab::set(const std::string &data, const std::string &format)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_ONELAB)
  if(format == "json")
    ::onelab::server::instance()->fromJSON(data);
  else
    Msg::Error("Unknown data format");
#else
  Msg::Error("Onelab not available");
  throw -1;
#endif
}

void gmsh::onelab::run(const std::string &name, const std::string &command)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_ONELAB)
  onelabUtils::runClient(name, command);
#endif
}
