// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include "gmsh.h"
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

static int _initialized = 0;

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

void gmshInitialize(int argc, char **argv)
{
  if(_initialized){
    Msg::Error("Gmsh has aleady been initialized");
    throw 1;
  }
  if(GmshInitialize(argc, argv)){
    _initialized = 1;
    return;
  }
  throw -1;
}

void gmshFinalize()
{
  if(!_isInitialized()){ throw -1; }
  if(GmshFinalize()){
    _initialized = 0;
    return;
  }
  Msg::Error("Something went wrong when finalizing Gmsh");
  throw 1;
}

void gmshOpen(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshOpenProject(fileName)) return;
  throw 1;
}

void gmshMerge(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshMergeFile(fileName)) return;
  throw 1;
}

void gmshExport(const std::string &fileName)
{
  if(!_isInitialized()){ throw -1; }
  if(GmshWriteFile(fileName)) return;
  throw 1;
}

void gmshClear()
{
  if(!_isInitialized()){ throw -1; }
  if(GmshClearProject()) return;
  throw 1;
}

// gmshOption

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

void gmshOptionSetNumber(const std::string &name, const double value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

void gmshOptionGetNumber(const std::string &name, double &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

void gmshOptionSetString(const std::string &name, const std::string &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i)) return;
  throw 1;
}

void gmshOptionGetString(const std::string &name, std::string &value)
{
  if(!_isInitialized()){ throw -1; }
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i)) return;
  throw 1;
}

// gmshModel

void gmshModelCreate(const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = new GModel(name);
  if(!m){ throw 1; }
}

void gmshModelDelete()
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::current();
  if(!m){ throw 1; }
  delete m;
}

void gmshModelList(std::vector<std::string> &names)
{
  if(!_isInitialized()){ throw -1; }
  for(unsigned int i = 0; i < GModel::list.size(); i++)
    names.push_back(GModel::list[i]->getName());
}

void gmshModelSetCurrent(const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::findByName(name);
  if(!m){ throw 1; }
  GModel::setCurrent(m);
}

void gmshModelGetEntities(vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()){ throw -1; }
  dimTags.clear();
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
}

void gmshModelGetPhysicalGroups(vector_pair &dimTags, const int dim)
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

void gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
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

int gmshModelAddPhysicalGroup(const int dim, const std::vector<int> &tags,
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

void gmshModelSetPhysicalName(const int dim, const int tag,
                              const std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->setPhysicalName(name, dim, tag);
}

void gmshModelGetPhysicalName(const int dim, const int tag, std::string &name)
{
  if(!_isInitialized()){ throw -1; }
  name = GModel::current()->getPhysicalName(dim, tag);
}

void gmshModelGetBoundary(const vector_pair &dimTags, vector_pair &outDimTags,
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

void gmshModelGetEntitiesInBoundingBox(const double xmin, const double ymin,
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

void gmshModelGetBoundingBox(const int dim, const int tag, double &xmin,
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

int gmshModelAddDiscreteEntity(const int dim, const int tag,
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

void gmshModelRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->remove(dimTags, recursive);
}

void gmshModelMesh(int dim)
{
  if(!_isInitialized()){ throw -1; }
  GModel *m = GModel::current();
  if(!m){ throw 1; }
  m->mesh(dim);
}

void gmshModelGetLastMeshEntityError(vector_pair &dimTags)
{
  if(!_isInitialized()){ throw -1; }
  std::vector<GEntity*> e = GModel::current()->getLastMeshEntityError();
  dimTags.clear();
  for(unsigned int i = 0; i < e.size(); i++)
    dimTags.push_back(std::pair<int, int>(e[i]->dim(), e[i]->tag()));
}

void gmshModelGetLastMeshVertexError(std::vector<int> &vertexTags)
{
  if(!_isInitialized()){ throw -1; }
  std::vector<MVertex*> v = GModel::current()->getLastMeshVertexError();
  vertexTags.clear();
  for(unsigned int i = 0; i < v.size(); i++)
    vertexTags.push_back(v[i]->getNum());
}

void gmshModelGetMeshVertices(const int dim, const int tag,
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

void gmshModelGetMeshElements(const int dim, const int tag,
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

void gmshModelSetMeshVertices(const int dim, const int tag,
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
  ge->deleteMesh(); // this will also delete the model mesh cache
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
  if(dst.size())
    Msg::Warning("%s already contains mesh elements - appending the new ones",
                 _entityName(dim, tag).c_str());
  for(unsigned int i = 0; i < src.size(); i++)
    dst.push_back(static_cast<T*>(src[i]));
}

void gmshModelSetMeshElements(const int dim, const int tag,
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
  for(unsigned int i = 0; i < types.size(); i++){
    int type = types[i];
    int numEle = elementTags[i].size();
    int numVertPerEle = MElement::getInfoMSH(type);
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

void gmshModelGetMeshVertex(const int vertexTag,
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

void gmshModelGetMeshElement(const int elementTag, int &type,
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

void gmshModelSetMeshSize(const vector_pair &dimTags, const double size)
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

void gmshModelSetTransfiniteLine(const int tag, const int numVertices,
                                 const std::string &type, const double coef)
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

void gmshModelSetTransfiniteSurface(const int tag,
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

void gmshModelSetTransfiniteVolume(const int tag,
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

void gmshModelSetRecombine(const int dim, const int tag)
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

void gmshModelSetSmoothing(const int dim, const int tag, const int val)
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

void gmshModelSetReverseMesh(const int dim, const int tag, const bool val)
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

void gmshModelEmbed(const int dim, const std::vector<int> &tags,
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

// gmshModelGeo

int gmshModelGeoAddPoint(const double x, const double y, const double z,
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

int gmshModelGeoAddLine(const int startTag, const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddCircleArc(const int startTag, const int centerTag,
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

int gmshModelGeoAddEllipseArc(const int startTag, const int centerTag,
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

int gmshModelGeoAddSpline(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddBSpline(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddBezier(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addBezier(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddLineLoop(const std::vector<int> &edgeTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addLineLoop(outTag, edgeTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddPlaneSurface(const std::vector<int> &wireTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddSurfaceFilling(const std::vector<int> &wireTags, const int tag,
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

int gmshModelGeoAddSurfaceLoop(const std::vector<int> &faceTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
  if(!GModel::current()->getGEOInternals()->addSurfaceLoop(outTag, faceTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelGeoAddVolume(const std::vector<int> &shellTags, const int tag)
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

void gmshModelGeoExtrude(const vector_pair &dimTags,
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

void gmshModelGeoRevolve(const vector_pair &dimTags,
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

void gmshModelGeoTwist(const vector_pair &dimTags,
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

void gmshModelGeoTranslate(const vector_pair &dimTags, const double dx,
                           const double dy, const double dz)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz)){
    throw 1;
  }
}

void gmshModelGeoRotate(const vector_pair &dimTags, const double x,
                        const double y, const double z, const double ax,
                        const double ay, const double az, const double angle)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->rotate
     (dimTags, x, y, z, ax, ay, az, angle)){
    throw 1;
  }
}

void gmshModelGeoDilate(const vector_pair &dimTags, const double x,
                        const double y, const double z, const double a,
                        const double b, const double c)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->dilate
     (dimTags, x, y, z, a, b, c)){
    throw 1;
  }
}

void gmshModelGeoSymmetry(const vector_pair &dimTags, const double a,
                          const double b, const double c, const double d)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->symmetry
     (dimTags, a, b, c, d)){
    throw 1;
  }
}

void gmshModelGeoCopy(const vector_pair &dimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()){ throw -1; }
  outDimTags.clear();
  if(!GModel::current()->getGEOInternals()->copy(dimTags, outDimTags)){
    throw 1;
  }
}

void gmshModelGeoRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  if(!GModel::current()->getGEOInternals()->remove(dimTags, recursive)){
    throw 1;
  }
}

void gmshModelGeoRemoveAllDuplicates()
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->removeAllDuplicates();
}

void gmshModelGeoSetTransfiniteLine(const int tag, const int nPoints,
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

void gmshModelGeoSetTransfiniteSurface(const int tag,
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

void gmshModelGeoSetTransfiniteVolume(const int tag,
                                      const std::vector<int> &cornerTags)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, cornerTags);
}

void gmshModelGeoSetRecombine(const int dim, const int tag, const double angle)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setRecombine(dim, tag, angle);
}

void gmshModelGeoSetSmoothing(const int dim, const int tag, const int val)
{
  if(!_isInitialized()){ throw -1; }
  if(dim != 2){ throw 2; }
  GModel::current()->getGEOInternals()->setSmoothing(tag, val);
}

void gmshModelGeoSetReverseMesh(const int dim, const int tag, const bool val)
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->setReverseMesh(dim, tag, val);
}

void gmshModelGeoSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()){ throw -1; }
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getGEOInternals()->setMeshSize(dim, tag, size);
  }
}

void gmshModelGeoSynchronize()
{
  if(!_isInitialized()){ throw -1; }
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
}

// gmshModelOcc

static void _createOcc()
{
  if(!GModel::current()->getOCCInternals()) GModel::current()->createOCCInternals();
}

int gmshModelOccAddPoint(const double x, const double y, const double z,
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

int gmshModelOccAddLine(const int startTag, const int endTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddCircleArc(const int startTag, const int centerTag,
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

int gmshModelOccAddCircle(const double x, const double y, const double z,
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

int gmshModelOccAddEllipseArc(const int startTag, const int centerTag,
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

int gmshModelOccAddEllipse(const double x, const double y, const double z,
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

int gmshModelOccAddSpline(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddBezier(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBezier(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddBSpline(const std::vector<int> &vertexTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addBSpline(outTag, vertexTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddWire(const std::vector<int> &edgeTags, const int tag,
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

int gmshModelOccAddLineLoop(const std::vector<int> &edgeTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addLineLoop(outTag, edgeTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddRectangle(const double x, const double y, const double z,
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

int gmshModelOccAddDisk(const double xc, const double yc, const double zc,
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

int gmshModelOccAddPlaneSurface(const std::vector<int> &wireTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddSurfaceFilling(const int wireTag, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceFilling(outTag, wireTag)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddSurfaceLoop(const std::vector<int> &faceTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, faceTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddVolume(const std::vector<int> &shellTags, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  if(!GModel::current()->getOCCInternals()->addVolume(outTag, shellTags)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccAddSphere(const double xc, const double yc, const double zc,
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

int gmshModelOccAddBox(const double x, const double y, const double z,
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

int gmshModelOccAddCylinder(const double x, const double y, const double z,
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

int gmshModelOccAddCone(const double x, const double y, const double z,
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

int gmshModelOccAddWedge(const double x, const double y, const double z,
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

int gmshModelOccAddTorus(const double x, const double y, const double z,
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

int gmshModelOccAddThruSections(const std::vector<int> &wireTags,
                                vector_pair &outDimTags,
                                const int tag, const bool makeSolid,
                                const bool makeRuled)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThruSections
     (outTag, wireTags, makeSolid, makeRuled, outDimTags)){
    throw 1;
  }
  return outTag;
}

int addThickSolid(const int solidTag,
                  const std::vector<int> &excludeFaceTags,
                  const double offset, vector_pair &outDimTags,
                  const int tag)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->addThickSolid
     (outTag, solidTag, excludeFaceTags, offset, outDimTags)){
    throw 1;
  }
  return outTag;
}

void gmshModelOccExtrude(const vector_pair &dimTags,
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

void gmshModelOccRevolve(const vector_pair &dimTags,
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

void gmshModelOccAddPipe(const vector_pair &dimTags, const int wireTag,
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

void gmshModelOccFillet(const std::vector<int> &regionTags,
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

int gmshModelOccBooleanUnion(const vector_pair &objectDimTags,
                             const vector_pair &toolDimTags,
                             vector_pair &outDimTags,
                             std::vector<vector_pair > &outDimTagsMap,
                             const int tag,
                             const bool removeObject,
                             const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanUnion
     (outTag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccBooleanIntersection(const vector_pair &objectDimTags,
                                    const vector_pair &toolDimTags,
                                    vector_pair &outDimTags,
                                    std::vector<vector_pair> &outDimTagsMap,
                                    const int tag,
                                    const bool removeObject,
                                    const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanIntersection
     (outTag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccBooleanDifference(const vector_pair &objectDimTags,
                                  const vector_pair &toolDimTags,
                                  vector_pair &outDimTags,
                                  std::vector<vector_pair> &outDimTagsMap,
                                  const int tag,
                                  const bool removeObject,
                                  const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanDifference
     (outTag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
  return outTag;
}

int gmshModelOccBooleanFragments(const vector_pair &objectDimTags,
                                 const vector_pair &toolDimTags,
                                 vector_pair &outDimTags,
                                 std::vector<vector_pair> &outDimTagsMap,
                                 const int tag,
                                 const bool removeObject,
                                 const bool removeTool)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  int outTag = tag;
  outDimTags.clear();
  outDimTagsMap.clear();
  if(!GModel::current()->getOCCInternals()->booleanFragments
     (outTag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
      removeObject, removeTool)){
    throw 1;
  }
  return outTag;
}

void gmshModelOccTranslate(const vector_pair &dimTags, const double dx,
                           const double dy, const double dz)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz)){
    throw 1;
  }
}

void gmshModelOccRotate(const vector_pair &dimTags, const double x,
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

void gmshModelOccDilate(const vector_pair &dimTags, const double x,
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

void gmshModelOccSymmetry(const vector_pair &dimTags, const double a,
                          const double b, const double c, const double d)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->symmetry(dimTags, a, b, c, d)){
    throw 1;
  }
}

void gmshModelOccCopy(const vector_pair &dimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  outDimTags.clear();
  if(!GModel::current()->getOCCInternals()->copy(dimTags, outDimTags)){
    throw 1;
  }
}

void gmshModelOccRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  if(!GModel::current()->getOCCInternals()->remove(dimTags, recursive)){
    throw 1;
  }
}

void gmshModelOccRemoveAllDuplicates()
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
}

void gmshModelOccImportShapes(const std::string &fileName,
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

void gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
}

void gmshModelOccSynchronize()
{
  if(!_isInitialized()){ throw -1; }
  _createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
}

// gmshModelField

int gmshModelFieldCreate(const std::string &type, const int tag)
{
  if(!_isInitialized()){ throw -1; }
  int outTag = tag;
#if defined(HAVE_MESH)
  if(outTag < 0){
    outTag = GModel::current()->getFields()->newId();
  }
  if(!GModel::current()->getFields()->newField(tag, type)){
    Msg::Error("Cannot create Field %i of type '%s'", tag, type.c_str());
    throw 1;
  }
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
  return outTag;
}

void gmshModelFieldDelete(const int tag)
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

void gmshModelFieldSetNumber(const int tag, const std::string &option,
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

void gmshModelFieldSetString(const int tag, const std::string &option,
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

void gmshModelFieldSetNumbers(const int tag, const std::string &option,
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

void gmshModelFieldSetAsBackground(const int tag)
{
  if(!_isInitialized()){ throw -1; }
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
#else
  Msg::Error("Fields require the mesh module");
  throw -1;
#endif
}

// gmshView

int gmshViewCreate(const std::string &name, const int tag)
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

void gmshViewDelete(const int tag)
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

int gmshViewGetIndex(const int tag)
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

void gmshViewGetTags(std::vector<int> &tags)
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

void gmshViewAddModelData(const int tag, const std::string &modelName,
                          const std::string &dataType,
                          const std::vector<int> &tags,
                          const std::vector<std::vector<double> > &data,
                          const int step, const int time,
                          const int numComponents, const int partition)
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
    else if(dataType == "Beam")
      type = PViewDataGModel::BeamData;
    else{
      Msg::Error("Unknown type of view to create '%s'", dataType.c_str());
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

/*
void gmshViewAddListData(const int tag, ...);
void gmshViewAddStringData(const int tag, ...);
void gmshViewAddXYData(const int tag, const std::vector<double> &x,
                       const std::vector<double> &y);
void gmshViewAddXYZData(const int tag, const std::vector<double> &x,
                        const std::vector<double> &y,
                        const std::vector<double> &z);

void gmshViewGetValue(tag, x, y, z, step, &vector_double);
void gmshViewGetRawData(tag, &double_vector);
void gmshViewSetRawData(tag, const &double_vector);
*/

void gmshViewExport(const int tag, const std::string &fileName,
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

// gmshPlugin

void gmshPluginSetNumber(const std::string &name, const std::string &option,
                         const double value)
{
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

void gmshPluginSetString(const std::string &name, const std::string &option,
                         const std::string &value)
{
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

void gmshPluginRun(const std::string &name)
{
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
