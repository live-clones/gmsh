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

// -1 : not initialized
// 0 : success
// 1 : generic error
// 2 : bad input arguments

#define GMSH_API std::vector<int>
#define GMSH_OK std::vector<int>(1, 0)
#define GMSH_ERROR(n) std::vector<int>(1, n)

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

GMSH_API gmshInitialize(int argc, char **argv)
{
  if(_initialized){
    Msg::Error("Gmsh has aleady been initialized");
    return GMSH_ERROR(1);
  }
  if(GmshInitialize(argc, argv)){
    _initialized = 1;
    return GMSH_OK;
  }
  return GMSH_ERROR(-1);
}

GMSH_API gmshFinalize()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GmshFinalize()){
    _initialized = 0;
    return GMSH_OK;
  }
  Msg::Error("Something went wrong when finalizing Gmsh");
  return GMSH_ERROR(1);
}

GMSH_API gmshOpen(const std::string &fileName)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GmshOpenProject(fileName))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshMerge(const std::string &fileName)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GmshMergeFile(fileName))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshExport(const std::string &fileName)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GmshWriteFile(fileName))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshClear()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GmshClearProject())
    return GMSH_OK;
  return GMSH_ERROR(1);
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

GMSH_API gmshOptionSetNumber(const std::string &name, const double value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshOptionGetNumber(const std::string &name, double &value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshOptionSetString(const std::string &name, const std::string &value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshSetOption(c, n, value, i))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshOptionGetString(const std::string &name, std::string &value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  std::string c, n;
  int i;
  _splitOptionName(name, c, n, i);
  if(GmshGetOption(c, n, value, i))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

// gmshModel

GMSH_API gmshModelCreate(const std::string &name)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel *m = new GModel(name);
  if(m)
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelDelete()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel *m = GModel::current();
  if(m){
    delete m;
    return GMSH_OK;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelList(std::vector<std::string> &names)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  for(unsigned int i = 0; i < GModel::list.size(); i++)
    names.push_back(GModel::list[i]->getName());
  return GMSH_ERROR(1);
}

GMSH_API gmshModelSetCurrent(const std::string &name)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel *m = GModel::findByName(name);
  if(m){
    GModel::setCurrent(m);
    return GMSH_OK;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGetEntities(vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  dimTags.clear();
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
  return GMSH_OK;
}

GMSH_API gmshModelGetPhysicalGroups(vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
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
  return GMSH_OK;
}

GMSH_API gmshModelAddPhysicalGroup(const int dim, const int tag,
                                   const std::vector<int> &tags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
    (dim, tag, 0, tags);
  if(r){
    GModel::current()->getGEOInternals()->synchronize(GModel::current());
    return GMSH_OK;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
                                              std::vector<int> &tags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  tags.clear();
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups.find(tag);
  if(it != groups.end()){
    for(unsigned j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
  return GMSH_OK;
}

GMSH_API gmshModelSetPhysicalName(const int dim, const int tag,
                                  const std::string &name)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->setPhysicalName(name, dim, tag);
  return GMSH_OK;
}

GMSH_API gmshModelGetPhysicalName(const int dim, const int tag,
                                  std::string &name)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  name = GModel::current()->getPhysicalName(dim, tag);
  return GMSH_OK;
}

GMSH_API gmshModelGetBoundary(const vector_pair &inDimTags, vector_pair &outDimTags,
                              const bool combined, const bool oriented,
                              const bool recursive)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  outDimTags.clear();
  bool r = GModel::current()->getBoundaryTags(inDimTags, outDimTags, combined,
                                              oriented, recursive);
  if(r) return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGetEntitiesInBoundingBox(const double x1, const double y1,
                                           const double z1, const double x2,
                                           const double y2, const double z2,
                                           vector_pair &dimTags, const int dim)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  dimTags.clear();
  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
  return GMSH_OK;
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

GMSH_API gmshModelGetBoundingBox(const int dim, const int tag, double &x1, double &y1,
                                 double &z1, double &x2, double &y2, double &z2)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  SBoundingBox3d box = ge->bounds();
  if(box.empty()) return GMSH_ERROR(3);
  x1 = box.min().x();
  y1 = box.min().y();
  z1 = box.min().z();
  x2 = box.max().x();
  y2 = box.max().y();
  z2 = box.max().z();
  return GMSH_OK;
}

GMSH_API gmshModelAddDiscreteEntity(const int dim, const int tag,
                                    const std::vector<int> &boundary)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  if(e){
    Msg::Error("%s already exists", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  // FIXME: check and set boundary entities to construct topology!
  switch(dim){
  case 0: {
    GVertex *gv = new discreteVertex(GModel::current(), tag);
    GModel::current()->add(gv);
    e = gv;
    break;
  }
  case 1: {
    GEdge *ge = new discreteEdge(GModel::current(), tag, 0, 0);
    GModel::current()->add(ge);
    break;
  }
  case 2: {
    GFace *gf = new discreteFace(GModel::current(), tag);
    GModel::current()->add(gf);
    break;
  }
  case 3: {
    GRegion *gr = new discreteRegion(GModel::current(), tag);
    GModel::current()->add(gr);
    break;
  }
  default :
    return GMSH_ERROR(2);
  }
  return GMSH_OK;
}

GMSH_API gmshModelRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->remove(dimTags, recursive);
  return GMSH_OK;
}

GMSH_API gmshModelMesh(int dim)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel *m = GModel::current();
  if(m){
    m->mesh(dim);
    return GMSH_OK;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGetMeshVertices(const int dim, const int tag,
                                  std::vector<int> &vertexTags,
                                  std::vector<double> &coordinates,
                                  std::vector<double> &parametricCoordinates)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  vertexTags.clear();
  coordinates.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  for(unsigned int i = 0; i < ge->mesh_vertices.size(); i++){
    MVertex *v = ge->mesh_vertices[i];
    vertexTags.push_back(v->getNum());
    coordinates.push_back(v->x());
    coordinates.push_back(v->y());
    coordinates.push_back(v->z());
    double par;
    for(int j = 0; j < dim; j++){
      if(v->getParameter(j, par)) parametricCoordinates.push_back(par);
    }
  }
  return GMSH_OK;
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

GMSH_API gmshModelGetMeshElements(const int dim, const int tag,
                                  std::vector<int> &types,
                                  std::vector<std::vector<int> > &elementTags,
                                  std::vector<std::vector<int> > &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  types.clear();
  elementTags.clear();
  vertexTags.clear();
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
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
  return GMSH_OK;
}

GMSH_API gmshModelSetMeshVertices(const int dim, const int tag,
                                  const std::vector<int> &vertexTags,
                                  const std::vector<double> &coordinates,
                                  const std::vector<double> &parametricCoordinates)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  if(!e){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  if(coordinates.size() != 3 * vertexTags.size()){
    Msg::Error("Wrong number of coordinates");
    return GMSH_ERROR(2);
  }
  bool param = false;
  if(parametricCoordinates.size()){
    if(parametricCoordinates.size() != dim * vertexTags.size()){
      Msg::Error("Wrong number of parametric coordinates");
      return GMSH_ERROR(2);
    }
    param = true;
  }
  GModel::current()->destroyMeshCaches();
  if(e->mesh_vertices.size())
    Msg::Warning("%s already contains mesh vertices",
                 _entityName(dim, tag).c_str());
  e->mesh_vertices.clear();
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int n = vertexTags[i];
    double x = coordinates[3 * i];
    double y = coordinates[3 * i + 1];
    double z = coordinates[3 * i + 2];
    MVertex *vv = 0;
    if(param && dim == 1){
      double u = parametricCoordinates[i];
      vv = new MEdgeVertex(x, y, z, e, u, n);
    }
    else if(param && dim == 2){
      double u = parametricCoordinates[i];
      double v = parametricCoordinates[i + 1];
      vv = new MFaceVertex(x, y, z, e, u, v, n);
    }
    else
      vv = new MVertex(x, y, z, e, n);
    e->mesh_vertices.push_back(vv);
  }
  return GMSH_OK;
}

template<class T>
static void _addElements(int dim, int tag, const std::vector<MElement*> &src,
                         std::vector<T*> &dst)
{
  if(dst.size())
    Msg::Warning("%s already contains some mesh elements",
                 _entityName(dim, tag).c_str());
  dst.clear();
  for(unsigned int i = 0; i < src.size(); i++)
    dst.push_back(static_cast<T*>(src[i]));
}

GMSH_API gmshModelSetMeshElements(const int dim, const int tag,
                                  const std::vector<int> &types,
                                  const std::vector<std::vector<int> > &elementTags,
                                  const std::vector<std::vector<int> > &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  if(!e){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  if(types.size() != elementTags.size()){
    Msg::Error("Wrong number of element tags");
    return GMSH_ERROR(2);
  }
  if(types.size() != vertexTags.size()){
    Msg::Error("Wrong number of vertex tags");
    return GMSH_ERROR(2);
  }
  for(unsigned int i = 0; i < types.size(); i++){
    int type = types[i];
    int numEle = elementTags[i].size();
    int numVertPerEle = MElement::getInfoMSH(type);
    if(!numEle) continue;
    if(numEle * numVertPerEle != vertexTags[i].size()){
      Msg::Error("Wrong number of vertex tags for element type %d", type);
      return GMSH_ERROR(2);
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
          return GMSH_ERROR(2);
        }
      }
      elements[j] = f.create(type, vertices, etag);
    }
    bool ok = true;
    switch(dim){
    case 0:
      if(elements[0]->getType() == TYPE_PNT)
        _addElements(dim, tag, elements, static_cast<GVertex*>(e)->points);
      else
        ok = false;
      break;
    case 1:
      if(elements[0]->getType() == TYPE_LIN)
        _addElements(dim, tag, elements, static_cast<GEdge*>(e)->lines);
      else
        ok = false;
     break;
    case 2:
      if(elements[0]->getType() == TYPE_TRI)
        _addElements(dim, tag, elements, static_cast<GFace*>(e)->triangles);
      else if(elements[0]->getType() == TYPE_QUA)
        _addElements(dim, tag, elements, static_cast<GFace*>(e)->quadrangles);
      else
        ok = false;
      break;
    case 3:
      if(elements[0]->getType() == TYPE_TET)
        _addElements(dim, tag, elements, static_cast<GRegion*>(e)->tetrahedra);
      else if(elements[0]->getType() == TYPE_HEX)
        _addElements(dim, tag, elements, static_cast<GRegion*>(e)->hexahedra);
      else if(elements[0]->getType() == TYPE_PRI)
        _addElements(dim, tag, elements, static_cast<GRegion*>(e)->prisms);
      else if(elements[0]->getType() == TYPE_PYR)
        _addElements(dim, tag, elements, static_cast<GRegion*>(e)->pyramids);
      else
        ok = false;
      break;
    }
    if(!ok){
      Msg::Error("Wrong type of element for %s", _entityName(dim, tag).c_str());
      return GMSH_ERROR(2);
    }
  }
  return GMSH_OK;
}

GMSH_API gmshModelSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 0){
      GVertex *gv = GModel::current()->getVertexByTag(tag);
      if(gv) gv->setPrescribedMeshSizeAtVertex(size);
    }
  }
  return GMSH_OK;
}

GMSH_API gmshModelSetTransfiniteLine(const int tag, const int nPoints,
                                     const std::string &type, const double coef)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GEdge *ge = GModel::current()->getEdgeByTag(tag);
  if(!ge){
    Msg::Error("%s does not exist", _entityName(1, tag).c_str());
    return GMSH_ERROR(2);
  }
  ge->meshAttributes.method = MESH_TRANSFINITE;
  ge->meshAttributes.nbPointsTransfinite = nPoints;
  ge->meshAttributes.typeTransfinite =
    (type == "Progression" || type == "Power") ? 1 :
    (type == "Bump") ? 2 :
    1;
  ge->meshAttributes.coeffTransfinite = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) ge->meshAttributes.typeTransfinite *= -1;
  return GMSH_OK;
}

GMSH_API gmshModelSetTransfiniteSurface(const int tag,
                                        const std::string &arrangement,
                                        const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(2, tag).c_str());
    return GMSH_ERROR(2);
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
  return GMSH_OK;
}

GMSH_API gmshModelSetTransfiniteVolume(const int tag,
                                       const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(!gr){
    Msg::Error("%s does not exist", _entityName(3, tag).c_str());
    return GMSH_ERROR(2);
  }
  gr->meshAttributes.method = MESH_TRANSFINITE;
  if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8){
    for(unsigned int i = 0; i < cornerTags.size(); i++){
      GVertex *gv = GModel::current()->getVertexByTag(cornerTags[i]);
      if(gv)
        gr->meshAttributes.corners.push_back(gv);
    }
  }
  return GMSH_OK;
}

GMSH_API gmshModelSetRecombine(const int dim, const int tag, const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  gf->meshAttributes.recombine = 1;
  gf->meshAttributes.recombineAngle = angle;
  return GMSH_OK;
}

GMSH_API gmshModelSetSmoothing(const int dim, const int tag, const int val)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(dim != 2) return GMSH_ERROR(2);
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(!gf){
    Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
    return GMSH_ERROR(2);
  }
  gf->meshAttributes.transfiniteSmoothing = val;
  return GMSH_OK;
}

GMSH_API gmshModelSetReverseMesh(const int dim, const int tag, const bool val)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(dim == 1){
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(!ge){
      Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
      return GMSH_ERROR(2);
    }
    ge->meshAttributes.reverseMesh = val;
  }
  else if(dim == 2){
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(!gf){
      Msg::Error("%s does not exist", _entityName(dim, tag).c_str());
      return GMSH_ERROR(2);
    }
    gf->meshAttributes.reverseMesh = val;
  }
  return GMSH_OK;
}

GMSH_API gmshModelEmbed(const int dim, const std::vector<int> &tags,
                        const int inDim, const int inTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(inDim == 2){
    GFace *gf = GModel::current()->getFaceByTag(inTag);
    if(!gf){
      Msg::Error("%s does not exist", _entityName(2, inTag).c_str());
      return GMSH_ERROR(2);
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv){
          Msg::Error("%s does not exist", _entityName(0, tags[i]).c_str());
          return GMSH_ERROR(2);
        }
        gf->addEmbeddedVertex(gv);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge){
          Msg::Error("%s does not exist", _entityName(1, tags[i]).c_str());
          return GMSH_ERROR(2);
        }
        gf->addEmbeddedEdge(ge);
      }
    }
  }
  else if(inDim == 3){
    GRegion *gr = GModel::current()->getRegionByTag(inTag);
    if(!gr){
      Msg::Error("%s does not exist", _entityName(3, inTag).c_str());
      return GMSH_ERROR(2);
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(!gv){
          Msg::Error("%s does not exist", _entityName(0, tags[i]).c_str());
          return GMSH_ERROR(2);
        }
        gr->addEmbeddedVertex(gv);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(!ge){
          Msg::Error("%s does not exist", _entityName(1, tags[i]).c_str());
          return GMSH_ERROR(2);
        }
        gr->addEmbeddedEdge(ge);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(!gf){
          Msg::Error("%s does not exist", _entityName(2, tags[i]).c_str());
          return GMSH_ERROR(2);
        }
        gr->addEmbeddedFace(gf);
      }
    }
  }
  return GMSH_OK;
}

// gmshModelGeo

GMSH_API gmshModelGeoAddPoint(const int tag, const double x, const double y,
                              const double z, const double meshSize)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  if(GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, zz, lc)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddLine(const int tag, const int startTag, const int endTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddCircleArc(const int tag, const int startTag,
                                  const int centerTag, const int endTag,
                                  const double nx, const double ny, const double nz)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addCircleArc
     (outTag, startTag, centerTag, endTag, nx, ny, nz)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddEllipseArc(const int tag, const int startTag,
                                   const int centerTag, const int majorTag,
                                   const int endTag, const double nx, const double ny,
                                   const double nz)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addEllipseArc
     (outTag, startTag, centerTag, majorTag, endTag, nx, ny, nz)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddSpline(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addSpline(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddBSpline(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addBSpline(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddBezier(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addBezier(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddLineLoop(const int tag, const std::vector<int> &edgeTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addLineLoop(outTag, edgeTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddPlaneSurface(const int tag, const std::vector<int> &wireTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddSurfaceFilling(const int tag, const std::vector<int> &wireTags,
                                       const int sphereCenterTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addSurfaceFilling
     (outTag, wireTags, sphereCenterTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddSurfaceLoop(const int tag, const std::vector<int> &faceTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addSurfaceLoop(outTag, faceTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoAddVolume(const int tag, const std::vector<int> &shellTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int outTag = tag;
  if(GModel::current()->getGEOInternals()->addVolume(outTag, shellTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
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

GMSH_API gmshModelGeoExtrude(const vector_pair &inDimTags,
                             const double dx, const double dy, const double dz,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements,
                             const std::vector<double> &heights,
                             const bool recombine)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  outDimTags.clear();
  if(GModel::current()->getGEOInternals()->extrude
     (inDimTags, dx, dy, dz, outDimTags,
      _getExtrudeParams(numElements, heights, recombine)))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoRevolve(const vector_pair &inDimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay, const double az,
                             const double angle, vector_pair &outDimTags,
                             const std::vector<int> &numElements,
                             const std::vector<double> &heights,
                             const bool recombine)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  outDimTags.clear();
  if(GModel::current()->getGEOInternals()->revolve
    (inDimTags, x, y, z, ax, ay, az, angle, outDimTags,
     _getExtrudeParams(numElements, heights, recombine)))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoTwist(const vector_pair &inDimTags,
                           const double x, const double y, const double z,
                           const double dx, const double dy, const double dz,
                           const double ax, const double ay, const double az,
                           const double angle, vector_pair &outDimTags,
                           const std::vector<int> &numElements,
                           const std::vector<double> &heights,
                           const bool recombine)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  outDimTags.clear();
  if(GModel::current()->getGEOInternals()->twist
    (inDimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags,
     _getExtrudeParams(numElements, heights, recombine)))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoTranslate(const vector_pair &dimTags, const double dx,
                               const double dy, const double dz)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoRotate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double ax,
                            const double ay, const double az, const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GModel::current()->getGEOInternals()->rotate
     (dimTags, x, y, z, ax, ay, az, angle))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoDilate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double a,
                            const double b, const double c)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GModel::current()->getGEOInternals()->dilate
     (dimTags, x, y, z, a, b, c))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoSymmetry(const vector_pair &dimTags, const double a,
                              const double b, const double c, const double d)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GModel::current()->getGEOInternals()->symmetry
     (dimTags, a, b, c, d))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoCopy(const vector_pair &inDimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  outDimTags.clear();
  if(GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(GModel::current()->getGEOInternals()->remove(dimTags, recursive))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelGeoRemoveAllDuplicates()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->getGEOInternals()->removeAllDuplicates();
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetTransfiniteLine(const int tag, const int nPoints,
                                        const std::string &type,
                                        const double coef)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int t =
    (type == "Progression" || type == "Power") ? 1 :
    (type == "Bump") ? 2 :
    1;
  double c = std::abs(coef);
  // in .geo file we use a negative tag to do this trick; it's a bad idea
  if(coef < 0) t = -t;
  GModel::current()->getGEOInternals()->setTransfiniteLine(tag, nPoints, t, c);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetTransfiniteSurface(const int tag,
                                           const std::string &arrangement,
                                           const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  int t =
    (arrangement == "Right") ? 1 :
    (arrangement == "Left") ? -1 :
    (arrangement == "AlternateRight") ? 2 :
    (arrangement == "AlternateLeft") ? -2 :
    (arrangement == "Alternate") ? 2 :
    -1;
  GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, t, cornerTags);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetTransfiniteVolume(const int tag,
                                          const std::vector<int> &cornerTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, cornerTags);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetRecombine(const int dim, const int tag, const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->getGEOInternals()->setRecombine(dim, tag, angle);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetSmoothing(const int dim, const int tag, const int val)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  if(dim != 2) return GMSH_ERROR(2);
  GModel::current()->getGEOInternals()->setSmoothing(tag, val);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetReverseMesh(const int dim, const int tag, const bool val)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->getGEOInternals()->setReverseMesh(dim, tag, val);
  return GMSH_OK;
}

GMSH_API gmshModelGeoSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getGEOInternals()->setMeshSize(dim, tag, size);
  }
  return GMSH_OK;
}

GMSH_API gmshModelGeoSynchronize()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  return GMSH_OK;
}

// gmshModelOcc

static void _createOcc()
{
  if(!GModel::current()->getOCCInternals()) GModel::current()->createOCCInternals();
}

GMSH_API gmshModelOccAddPoint(const int tag, const double x, const double y,
                              const double z, const double meshSize)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addVertex(outTag, x, y, z, meshSize)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddLine(const int tag, const int startTag, const int endTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddCircleArc(const int tag, const int startTag,
                                  const int centerTag, const int endTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addCircleArc
     (outTag, startTag, centerTag, endTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddCircle(const int tag, const double x, const double y,
                               const double z, const double r, const double angle1,
                               const double angle2)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addCircle
     (outTag, x, y, z, r, angle1, angle2)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddEllipseArc(const int tag, const int startTag,
                                   const int centerTag, const int endTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addEllipseArc
     (outTag, startTag, centerTag, endTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddEllipse(const int tag, const double x, const double y,
                                const double z, const double r1, const double r2,
                                const double angle1, const double angle2)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addEllipse
     (outTag, x, y, z, r1, r2, angle1, angle2)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddSpline(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addSpline(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddBezier(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addBezier(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddBSpline(const int tag, const std::vector<int> &vertexTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addBSpline(outTag, vertexTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddWire(const int tag, const std::vector<int> &edgeTags,
                             const bool checkClosed)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addWire
     (outTag, edgeTags, checkClosed)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddLineLoop(const int tag, const std::vector<int> &edgeTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addLineLoop(outTag, edgeTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddRectangle(const int tag, const double x, const double y,
                                  const double z, const double dx, const double dy,
                                  const double roundedRadius)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addRectangle
     (outTag, x, y, z, dx, dy, roundedRadius)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddDisk(const int tag, const double xc, const double yc,
                             const double zc, const double rx, const double ry)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addDisk
     (outTag, xc, yc, zc, rx, ry)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddPlaneSurface(const int tag, const std::vector<int> &wireTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddSurfaceFilling(const int tag, const int wireTag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addSurfaceFilling(outTag, wireTag)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddSurfaceLoop(const int tag, const std::vector<int> &faceTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, faceTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddVolume(const int tag, const std::vector<int> &shellTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addVolume(outTag, shellTags)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddSphere(const int tag, const double xc, const double yc,
                               const double zc, const double radius,
                               const double angle1, const double angle2,
                               const double angle3)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addSphere
     (outTag, xc, yc, zc, radius, angle1, angle2, angle3)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddBox(const int tag, const double x, const double y,
                            const double z, const double dx, const double dy,
                            const double dz)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addBox
     (outTag, x, y, z, dx, dy, dz)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddCylinder(const int tag, const double x, const double y,
                                 const double z, const double dx, const double dy,
                                 const double dz, const double r, const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addCylinder
     (outTag, x, y, z, dx, dy, dz, r, angle)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddCone(const int tag, const double x, const double y,
                             const double z, const double dx, const double dy,
                             const double dz, const double r1, const double r2,
                             const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addCone
     (outTag, x, y, z, dx, dy, dz, r1, r2, angle)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddWedge(const int tag, const double x, const double y,
                              const double z, const double dx, const double dy,
                              const double dz, const double ltx)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addWedge
     (outTag, x, y, z, dx, dy, dz, ltx)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddTorus(const int tag, const double x, const double y,
                              const double z, const double r1, const double r2,
                              const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  int outTag = tag;
  if(GModel::current()->getOCCInternals()->addTorus
     (outTag, x, y, z, r1, r2, angle)){
    std::vector<int> ret = GMSH_OK; ret.push_back(outTag);
    return ret;
  }
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddThruSections(const int tag, const std::vector<int> &wireTags,
                                     vector_pair &outDimTags, const bool makeSolid,
                                     const bool makeRuled)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->addThruSections
    (tag, wireTags, makeSolid, makeRuled, outDimTags))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API addThickSolid(const int tag, const int solidTag,
                       const std::vector<int> &excludeFaceTags,
                       const double offset, vector_pair &outDimTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->addThickSolid
    (tag, solidTag, excludeFaceTags, offset, outDimTags))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccExtrude(const vector_pair &inDimTags,
                             const double dx, const double dy, const double dz,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements,
                             const std::vector<double> &heights,
                             const bool recombine)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->extrude
    (inDimTags, dx, dy, dz, outDimTags,
     _getExtrudeParams(numElements, heights, recombine)))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccRevolve(const vector_pair &inDimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay, const double az,
                             const double angle, vector_pair &outDimTags,
                             const std::vector<int> &numElements,
                             const std::vector<double> &heights,
                             const bool recombine)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->revolve
    (inDimTags, x, y, z, ax, ay, az, angle, outDimTags,
     _getExtrudeParams(numElements, heights, recombine)))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccAddPipe(const vector_pair &inDimTags, const int wireTag,
                             vector_pair &outDimTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->addPipe
    (inDimTags, wireTag, outDimTags))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccFillet(const std::vector<int> &regionTags,
                            const std::vector<int> &edgeTags,
                            const double radius, vector_pair &outDimTags,
                            const bool removeRegion)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->fillet
    (regionTags, edgeTags, radius, outDimTags, removeRegion))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccBooleanUnion(const int tag,
                                  const vector_pair &objectDimTags,
                                  const vector_pair &toolDimTags,
                                  vector_pair &outDimTags,
                                  std::vector<vector_pair > &outDimTagsMap,
                                  const bool removeObject,
                                  const bool removeTool)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(GModel::current()->getOCCInternals()->booleanUnion
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccBooleanIntersection(const int tag,
                                         const vector_pair &objectDimTags,
                                         const vector_pair &toolDimTags,
                                         vector_pair &outDimTags,
                                         std::vector<vector_pair> &outDimTagsMap,
                                         const bool removeObject,
                                         const bool removeTool)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(GModel::current()->getOCCInternals()->booleanIntersection
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccBooleanDifference(const int tag,
                                       const vector_pair &objectDimTags,
                                       const vector_pair &toolDimTags,
                                       vector_pair &outDimTags,
                                       std::vector<vector_pair> &outDimTagsMap,
                                       const bool removeObject,
                                       const bool removeTool)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(GModel::current()->getOCCInternals()->booleanDifference
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccBooleanFragments(const int tag,
                                      const vector_pair &objectDimTags,
                                      const vector_pair &toolDimTags,
                                      vector_pair &outDimTags,
                                      std::vector<vector_pair> &outDimTagsMap,
                                      const bool removeObject,
                                      const bool removeTool)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  if(GModel::current()->getOCCInternals()->booleanFragments
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccTranslate(const vector_pair &dimTags, const double dx,
                               const double dy, const double dz)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  if(GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccRotate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double ax,
                            const double ay, const double az, const double angle)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  if(GModel::current()->getOCCInternals()->rotate
    (dimTags, x, y, z, ax, ay, az, angle))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccDilate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double a,
                            const double b, const double c)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  if(GModel::current()->getOCCInternals()->dilate
    (dimTags, x, y, z, a, b, c))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccSymmetry(const vector_pair &dimTags, const double a,
                              const double b, const double c, const double d)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  if(GModel::current()->getOCCInternals()->symmetry
    (dimTags, a, b, c, d))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccCopy(const vector_pair &inDimTags, vector_pair &outDimTags)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  if(GModel::current()->getOCCInternals()->remove(dimTags, recursive))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccRemoveAllDuplicates()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
  return GMSH_OK;
}

GMSH_API gmshModelOccImportShapes(const std::string &fileName,
                                  vector_pair &outDimTags,
                                  const bool highestDimOnly,
                                  const std::string &format)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  outDimTags.clear();
  if(GModel::current()->getOCCInternals()->importShapes
    (fileName, highestDimOnly, outDimTags, format))
    return GMSH_OK;
  return GMSH_ERROR(1);
}

GMSH_API gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
  return GMSH_OK;
}

GMSH_API gmshModelOccSynchronize()
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
  _createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
  return GMSH_OK;
}

// gmshModelField

GMSH_API gmshModelFieldCreate(const int tag, const std::string &type)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  if(!GModel::current()->getFields()->newField(tag, type)){
    Msg::Error("Cannot create Field %i of type '%s'", tag, type.c_str());
    return GMSH_ERROR(1);
  }
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
#endif
}

GMSH_API gmshModelFieldDelete(const int tag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  GModel::current()->getFields()->deleteField(tag);
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
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

GMSH_API gmshModelFieldSetNumber(const int tag, const std::string &option,
                                 const double value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return GMSH_ERROR(1);
  try { o->numericalValue(value); }
  catch(...){
    Msg::Error("Cannot set numerical value to option '%s' in field %i",
               option.c_str(), tag);
    return GMSH_ERROR(1);
  }
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
#endif
}

GMSH_API gmshModelFieldSetString(const int tag, const std::string &option,
                                 const std::string &value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return GMSH_ERROR(1);
  try { o->string(value); }
  catch(...){
    Msg::Error("Cannot set string value to option '%s' in field %i",
               option.c_str(), tag);
    return GMSH_ERROR(1);
  }
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
#endif
}

GMSH_API gmshModelFieldSetNumbers(const int tag, const std::string &option,
                                  const std::vector<double> &value)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  FieldOption *o = _getFieldOption(tag, option);
  if(!o) return GMSH_ERROR(1);
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
    return GMSH_ERROR(1);
  }
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
#endif
}

GMSH_API gmshModelFieldSetAsBackground(const int tag)
{
  if(!_isInitialized()) return GMSH_ERROR(-1);
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
  return GMSH_OK;
#else
  Msg::Error("Fields require the mesh module");
  return GMSH_ERROR(-1);
#endif
}

