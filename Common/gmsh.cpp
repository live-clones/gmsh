// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "gmsh.h"
#include "GmshConfig.h"
#include "GmshGlobal.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
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

static int _initialized = 0;

static bool isInitialized()
{
  if(!_initialized){
    Msg::Error("Gmsh has not been initialized");
    return false;
  }
  return true;
}

// gmsh

int gmshInitialize(int argc, char **argv)
{
  if(_initialized){
    Msg::Error("Gmsh has aleady been initialized");
    return 1;
  }
  if(GmshInitialize(argc, argv)){
    _initialized = 1;
    return 0;
  }
  return 1;
}

int gmshFinalize()
{
  if(!isInitialized()) return -1;
  return !GmshFinalize();
}

int gmshOpen(const std::string &fileName)
{
  if(!isInitialized()) return -1;
  return !GmshOpenProject(fileName);
}

int gmshMerge(const std::string &fileName)
{
  if(!isInitialized()) return -1;
  return !GmshMergeFile(fileName);
}

int gmshExport(const std::string &fileName)
{
  if(!isInitialized()) return -1;
  return !GmshWriteFile(fileName);
}

int gmshClear()
{
  if(!isInitialized()) return -1;
  return !GmshClearProject();
}

// gmshOption

static void splitOptionName(const std::string &fullName, std::string &category,
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

int gmshOptionSetNumber(const std::string &name, const double value)
{
  if(!isInitialized()) return -1;
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetNumber(const std::string &name, double &value)
{
  if(!isInitialized()) return -1;
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

int gmshOptionSetString(const std::string &name, const std::string &value)
{
  if(!isInitialized()) return -1;
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetString(const std::string &name, std::string &value)
{
  if(!isInitialized()) return -1;
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

// gmshModel

int gmshModelCreate(const std::string &name)
{
  if(!isInitialized()) return -1;
  GModel *m = new GModel(name);
  return m ? 0 : 1;
}

int gmshModelSetCurrent(const std::string &name)
{
  if(!isInitialized()) return -1;
  GModel *m = GModel::findByName(name);
  if(m){
    GModel::setCurrent(m);
    return 0;
  }
  return 1;
}

int gmshModelDestroy()
{
  if(!isInitialized()) return -1;
  GModel *m = GModel::current();
  if(m){
    delete m;
    return 0;
  }
  return 1;
}

int gmshModelGetEntities(vector_pair &dimTags, const int dim)
{
  if(!isInitialized()) return -1;
  dimTags.clear();
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
  return 0;
}

int gmshModelGetPhysicalGroups(vector_pair &dimTags, const int dim)
{
  if(!isInitialized()) return -1;
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
  return 0;
}

int gmshModelAddPhysicalGroup(const int dim, const int tag, const std::vector<int> &tags)
{
  if(!isInitialized()) return -1;
  bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
    (dim, tag, 0, tags);
  if(r){
    GModel::current()->getGEOInternals()->synchronize(GModel::current());
    return 0;
  }
  return 1;
}

int gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
                                         std::vector<int> &tags)
{
  if(!isInitialized()) return -1;
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups.find(tag);
  if(it != groups.end()){
    for(unsigned j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
  return 0;
}

int gmshModelSetPhysicalName(const int dim, const int tag, const std::string &name)
{
  if(!isInitialized()) return -1;
  GModel::current()->setPhysicalName(name, dim, tag);
  return 0;
}

int gmshModelGetPhysicalName(const int dim, const int tag, std::string &name)
{
  if(!isInitialized()) return -1;
  name = GModel::current()->getPhysicalName(dim, tag);
  return 0;
}

int gmshModelGetVertexCoordinates(const int tag, double &x, double &y, double &z)
{
  if(!isInitialized()) return -1;
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(gv){
    x = gv->x();
    y = gv->y();
    z = gv->z();
    return 0;
  }
  return 1;
}

int gmshModelGetBoundary(const vector_pair &inDimTags, vector_pair &outDimTags,
                         const bool combined, const bool oriented, const bool recursive)
{
  if(!isInitialized()) return -1;
  outDimTags.clear();
  bool r = GModel::current()->getBoundaryTags(inDimTags, outDimTags, combined,
                                              oriented, recursive);
  if(r) return 0;
  return 1;
}

int gmshModelGetEntitiesInBoundingBox(const double x1, const double y1, const double z1,
                                      const double x2, const double y2, const double z2,
                                      vector_pair &dimTags, const int dim)
{
  if(!isInitialized()) return -1;
  dimTags.clear();
  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
  return 0;
}

int gmshModelGetBoundingBox(const int dim, const int tag, double &x1, double &y1,
                            double &z1, double &x2, double &y2, double &z2)
{
  if(!isInitialized()) return -1;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) return 1;
  SBoundingBox3d box = ge->bounds();
  if(box.empty()) return 2;
  x1 = box.min().x();
  y1 = box.min().y();
  z1 = box.min().z();
  x2 = box.max().x();
  y2 = box.max().y();
  z2 = box.max().z();
  return 0;
}

int gmshModelRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!isInitialized()) return -1;
  GModel::current()->remove(dimTags, recursive);
  return 0;
}

int gmshModelMesh(int dim)
{
  if(!isInitialized()) return -1;
  GModel *m = GModel::current();
  if(m){
    m->mesh(dim);
    return 0;
  }
  return 1;
}

int gmshModelGetMeshVertices(const int dim, const int tag,
                             std::vector<int> &vertexTags,
                             std::vector<double> &coords)
{
  if(!isInitialized()) return -1;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) return 1;
  for(unsigned int i = 0; i < ge->mesh_vertices.size(); i++){
    MVertex *v = ge->mesh_vertices[i];
    vertexTags.push_back(v->getNum());
    coords.push_back(v->x());
    coords.push_back(v->y());
    coords.push_back(v->z());
  }
  return 0;
}

template<class T>
static void addElementInfo(std::vector<T*> &ele,
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

int gmshModelGetMeshElements(const int dim, const int tag, std::vector<int> &types,
                             std::vector<std::vector<int> > &elementTags,
                             std::vector<std::vector<int> > &vertexTags)
{
  if(!isInitialized()) return -1;
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) return 1;
  switch(dim){
  case 0: {
    GVertex *v = static_cast<GVertex*>(ge);
    addElementInfo(v->points, types, elementTags, vertexTags);
    break; }
  case 1: {
    GEdge *e = static_cast<GEdge*>(ge);
    addElementInfo(e->lines, types, elementTags, vertexTags);
    break; }
  case 2: {
    GFace *f = static_cast<GFace*>(ge);
    addElementInfo(f->triangles, types, elementTags, vertexTags);
    addElementInfo(f->quadrangles, types, elementTags, vertexTags);
    break; }
  case 3: {
    GRegion *r = static_cast<GRegion*>(ge);
    addElementInfo(r->tetrahedra, types, elementTags, vertexTags);
    addElementInfo(r->hexahedra, types, elementTags, vertexTags);
    addElementInfo(r->prisms, types, elementTags, vertexTags);
    addElementInfo(r->pyramids, types, elementTags, vertexTags);
    break; }
  }
  return 0;
}

int gmshModelSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!isInitialized()) return -1;
  int ret = 0;
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim != 1) ret = 1;
    GVertex *gv = GModel::current()->getVertexByTag(tag);
    if(gv) gv->setPrescribedMeshSizeAtVertex(size);
  }
  return ret;
}

int gmshModelSetTransfiniteLine(const int tag, const int nPoints, const int type,
                                const double coef)
{
  if(!isInitialized()) return -1;
  GEdge *ge = GModel::current()->getEdgeByTag(tag);
  if(ge){
    ge->meshAttributes.method = MESH_TRANSFINITE;
    ge->meshAttributes.nbPointsTransfinite = nPoints;
    ge->meshAttributes.typeTransfinite = type;
    ge->meshAttributes.coeffTransfinite = coef;
    return 0;
  }
  return 1;
}

int gmshModelSetTransfiniteSurface(const int tag, const int arrangement,
                                   const std::vector<int> &cornerTags)
{
  if(!isInitialized()) return -1;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(gf){
    gf->meshAttributes.method = MESH_TRANSFINITE;
    gf->meshAttributes.transfiniteArrangement = arrangement;
    if(cornerTags.empty() || cornerTags.size() == 3 || cornerTags.size() == 4){
      for(unsigned int j = 0; j < cornerTags.size(); j++){
        GVertex *gv = GModel::current()->getVertexByTag(cornerTags[j]);
        if(gv)
          gf->meshAttributes.corners.push_back(gv);
      }
    }
    return 0;
  }
  return 1;
}

int gmshModelSetTransfiniteVolume(const int tag, const std::vector<int> &cornerTags)
{
  if(!isInitialized()) return -1;
  GRegion *gr = GModel::current()->getRegionByTag(tag);
  if(gr){
    gr->meshAttributes.method = MESH_TRANSFINITE;
    if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8){
      for(unsigned int i = 0; i < cornerTags.size(); i++){
        GVertex *gv = GModel::current()->getVertexByTag(cornerTags[i]);
        if(gv)
          gr->meshAttributes.corners.push_back(gv);
      }
    }
    return 0;
  }
  return 1;
}

int gmshModelSetRecombine(const int dim, const int tag, const double angle)
{
  if(!isInitialized()) return -1;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(gf){
    gf->meshAttributes.recombine = 1;
    gf->meshAttributes.recombineAngle = angle;
    return 0;
  }
  return 1;
}

int gmshModelSetSmoothing(const int tag, const int val)
{
  if(!isInitialized()) return -1;
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(gf){
    gf->meshAttributes.transfiniteSmoothing = val;
    return 0;
  }
  return 1;
}

int gmshModelSetReverseMesh(const int dim, const int tag)
{
  if(!isInitialized()) return -1;
  if(dim == 1){
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if(ge) ge->meshAttributes.reverseMesh = 1;
  }
  else if(dim == 2){
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if(gf) gf->meshAttributes.reverseMesh = 1;
  }
  return 0;
}

int gmshModelEmbed(const int dim, const std::vector<int> &tags,
                   const int inDim, const int inTag)
{
  if(!isInitialized()) return -1;
  if(inDim == 2){
    GFace *gf = GModel::current()->getFaceByTag(inTag);
    if(gf){
      for(unsigned int i = 0; i < tags.size(); i++){
        if(dim == 0){
          GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
          if(gv)
            gf->addEmbeddedVertex(gv);
        }
        else if(dim == 1){
          GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
          if(ge)
            gf->addEmbeddedEdge(ge);
        }
      }
    }
  }
  else if(inDim == 3){
    GRegion *gr = GModel::current()->getRegionByTag(inTag);
    if(gr){
      for(unsigned int i = 0; i < tags.size(); i++){
        if(dim == 0){
          GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
          if(gv)
            gr->addEmbeddedVertex(gv);
        }
        else if(dim == 1){
          GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
          if(ge)
            gr->addEmbeddedEdge(ge);
        }
        else if(dim == 2){
          GFace *gf = GModel::current()->getFaceByTag(tags[i]);
          if(gf)
            gr->addEmbeddedFace(gf);
        }
      }
    }
  }
  return 0;
}

// gmshModelGeo

int gmshModelGeoAddPoint(const int tag, const double x, const double y, const double z,
                         int &outTag, const double meshSize)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  double xx = CTX::instance()->geom.scalingFactor * x;
  double yy = CTX::instance()->geom.scalingFactor * y;
  double zz = CTX::instance()->geom.scalingFactor * z;
  double lc = CTX::instance()->geom.scalingFactor * meshSize;
  return !GModel::current()->getGEOInternals()->addVertex(outTag, xx, yy, zz, lc);
}

int gmshModelGeoAddLine(const int tag, const int startTag, const int endTag,
                        int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addLine(outTag, startTag, endTag);
}

int gmshModelGeoAddCircleArc(const int tag, const int startTag, const int centerTag,
                             const int endTag, int &outTag,
                             const double nx, const double ny, const double nz)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addCircleArc
    (outTag, startTag, centerTag, endTag, nx, ny, nz);
}

int gmshModelGeoAddEllipseArc(const int tag, const int startTag, const int centerTag,
                              const int majorTag, const int endTag, int &outTag,
                              const double nx, const double ny, const double nz)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addEllipseArc
    (outTag, startTag, centerTag, majorTag, endTag, nx, ny, nz);
}

int gmshModelGeoAddSpline(const int tag, const std::vector<int> &vertexTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addSpline(outTag, vertexTags);
}

int gmshModelGeoAddBSpline(const int tag, const std::vector<int> &vertexTags,
                           int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addBSpline(outTag, vertexTags);
}

int gmshModelGeoAddBezier(const int tag, const std::vector<int> &vertexTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addBezier(outTag, vertexTags);
}

int gmshModelGeoAddLineLoop(const int tag, const std::vector<int> &edgeTags,
                            int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addLineLoop(outTag, edgeTags);
}

int gmshModelGeoAddPlaneSurface(const int tag, const std::vector<int> &wireTags,
                                int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addPlaneSurface(outTag, wireTags);
}

int gmshModelGeoAddSurfaceFilling(const int tag, const std::vector<int> &wireTags,
                                  int &outTag, const int sphereCenterTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addSurfaceFilling
    (outTag, wireTags, sphereCenterTag);
}

int gmshModelGeoAddSurfaceLoop(const int tag, const std::vector<int> &faceTags,
                               int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addSurfaceLoop(outTag, faceTags);
}

int gmshModelGeoAddVolume(const int tag, const std::vector<int> &shellTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  outTag = tag;
  return !GModel::current()->getGEOInternals()->addVolume(outTag, shellTags);
}

static ExtrudeParams *getExtrudeParams(const std::vector<int> &numElements,
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

int gmshModelGeoExtrude(const vector_pair &inDimTags,
                        const double dx, const double dy, const double dz,
                        vector_pair &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, const bool recombine)
{
  if(!isInitialized()) return -1;
  outDimTags.clear();
  return !GModel::current()->getGEOInternals()->extrude
    (inDimTags, dx, dy, dz, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoRevolve(const vector_pair &inDimTags,
                        const double x, const double y, const double z,
                        const double ax, const double ay, const double az,
                        const double angle, vector_pair &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, const bool recombine)
{
  if(!isInitialized()) return -1;
  outDimTags.clear();
  return !GModel::current()->getGEOInternals()->revolve
    (inDimTags, x, y, z, ax, ay, az, angle, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoTwist(const vector_pair &inDimTags,
                      const double x, const double y, const double z,
                      const double dx, const double dy, const double dz,
                      const double ax, const double ay, const double az,
                      const double angle, vector_pair &outDimTags,
                      const std::vector<int> &numElements,
                      const std::vector<double> &heights, const bool recombine)
{
  if(!isInitialized()) return -1;
  outDimTags.clear();
  return !GModel::current()->getGEOInternals()->twist
    (inDimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoTranslate(const vector_pair &dimTags, const double dx,
                          const double dy, const double dz)
{
  if(!isInitialized()) return -1;
  return !GModel::current()->getGEOInternals()->translate(dimTags, dx, dy, dz);
}

int gmshModelGeoRotate(const vector_pair &dimTags, const double x, const double y,
                       const double z, const double ax, const double ay, const double az,
                       const double angle)
{
  if(!isInitialized()) return -1;
  return !GModel::current()->getGEOInternals()->rotate
    (dimTags, x, y, z, ax, ay, az, angle);
}

int gmshModelGeoDilate(const vector_pair &dimTags, const double x, const double y,
                       const double z, const double a, const double b, const double c)
{
  if(!isInitialized()) return -1;
  return !GModel::current()->getGEOInternals()->dilate
    (dimTags, x, y, z, a, b, c);
}

int gmshModelGeoSymmetry(const vector_pair &dimTags,
                         const double a, const double b, const double c, const double d)
{
  if(!isInitialized()) return -1;
  return !GModel::current()->getGEOInternals()->symmetry
    (dimTags, a, b, c, d);
}

int gmshModelGeoCopy(const vector_pair &inDimTags, vector_pair &outDimTags)
{
  if(!isInitialized()) return -1;
  outDimTags.clear();
  return !GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags);
}

int gmshModelGeoRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!isInitialized()) return -1;
  return !GModel::current()->getGEOInternals()->remove(dimTags, recursive);
}

int gmshModelGeoRemoveAllDuplicates()
{
  if(!isInitialized()) return -1;
  GModel::current()->getGEOInternals()->removeAllDuplicates();
  return 0;
}

int gmshModelGeoSetTransfiniteLine(const int tag, const int nPoints, const int type,
                                   const double coef)
{
  if(!isInitialized()) return -1;
  return 1;
}

int gmshModelGeoSetTransfiniteSurface(const int tag, const int arrangement,
                                      const std::vector<int> &cornerTags)
{
  if(!isInitialized()) return -1;
  return 1;
}

int gmshModelGeoSetTransfiniteVolume(const int tag, const std::vector<int> &cornerTags)
{
  if(!isInitialized()) return -1;
  return 1;
}

int gmshModelGeoSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!isInitialized()) return -1;
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getGEOInternals()->setMeshSize(dim, tag, size);
  }
  return 0;
}

int gmshModelGeoSynchronize()
{
  if(!isInitialized()) return -1;
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  return 0;
}

// gmshModelOcc

static void createOcc()
{
  if(!GModel::current()->getOCCInternals()) GModel::current()->createOCCInternals();
}

int gmshModelOccAddPoint(const int tag, const double x, const double y, const double z,
                         int &outTag, const double meshSize)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addVertex(outTag, x, y, z, meshSize);
}

int gmshModelOccAddLine(const int tag, const int startTag, const int endTag,
                        int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addLine(outTag, startTag, endTag);
}

int gmshModelOccAddCircleArc(const int tag, const int startTag, const int centerTag,
                             const int endTag, int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addCircleArc
    (outTag, startTag, centerTag, endTag);
}

int gmshModelOccAddCircle(const int tag, const double x, const double y, const double z,
                          const double r, int &outTag, const double angle1,
                          const double angle2)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addCircle
    (outTag, x, y, z, r, angle1, angle2);
}

int gmshModelOccAddEllipseArc(const int tag, const int startTag, const int centerTag,
                              const int endTag, int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addEllipseArc
    (outTag, startTag, centerTag, endTag);
}

int gmshModelOccAddEllipse(const int tag, const double x, const double y, const double z,
                           const double r1, const double r2, int &outTag,
                           const double angle1, const double angle2)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addEllipse
    (outTag, x, y, z, r1, r2, angle1, angle2);
}

int gmshModelOccAddSpline(const int tag, const std::vector<int> &vertexTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addSpline(outTag, vertexTags);
}

int gmshModelOccAddBezier(const int tag, const std::vector<int> &vertexTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addBezier(outTag, vertexTags);
}

int gmshModelOccAddBSpline(const int tag, const std::vector<int> &vertexTags,
                           int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addBSpline(outTag, vertexTags);
}

int gmshModelOccAddWire(const int tag, const std::vector<int> &edgeTags,
                        int &outTag, const bool checkClosed)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addWire
    (outTag, edgeTags, checkClosed);
}

int gmshModelOccAddLineLoop(const int tag, const std::vector<int> &edgeTags,
                            int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addLineLoop(outTag, edgeTags);
}

int gmshModelOccAddRectangle(const int tag, const double x, const double y,
                             const double z, const double dx, const double dy,
                             int &outTag, const double roundedRadius)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addRectangle
    (outTag, x, y, z, dx, dy, roundedRadius);
}

int gmshModelOccAddDisk(const int tag, const double xc, const double yc,
                        const double zc, const double rx, const double ry,
                        int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addDisk
    (outTag, xc, yc, zc, rx, ry);
}

int gmshModelOccAddPlaneSurface(const int tag, const std::vector<int> &wireTags,
                                int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addPlaneSurface(outTag, wireTags);
}

int gmshModelOccAddSurfaceFilling(const int tag, const int wireTag, int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addSurfaceFilling(outTag, wireTag);
}

int gmshModelOccAddSurfaceLoop(const int tag, const std::vector<int> &faceTags,
                               int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addSurfaceLoop(outTag, faceTags);
}

int gmshModelOccAddVolume(const int tag, const std::vector<int> &shellTags,
                          int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addVolume(outTag, shellTags);
}

int gmshModelOccAddSphere(const int tag, const double xc, const double yc,
                          const double zc, const double radius, int &outTag,
                          const double angle1, const double angle2,
                          const double angle3)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addSphere
    (outTag, xc, yc, zc, radius, angle1, angle2, angle3);
}

int gmshModelOccAddBox(const int tag, const double x, const double y, const double z,
                       const double dx, const double dy, const double dz, int &outTag)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addBox
    (outTag, x, y, z, dx, dy, dz);
}

int gmshModelOccAddCylinder(const int tag, const double x, const double y,
                            const double z, const double dx, const double dy,
                            const double dz, const double r, int &outTag,
                            const double angle)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addCylinder
    (outTag, x, y, z, dx, dy, dz, r, angle);
}

int gmshModelOccAddCone(const int tag, const double x, const double y, const double z,
                        const double dx, const double dy, const double dz,
                        const double r1, const double r2, int &outTag,
                        const double angle)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addCone
    (outTag, x, y, z, dx, dy, dz, r1, r2, angle);
}

int gmshModelOccAddWedge(const int tag, const double x, const double y, const double z,
                         const double dx, const double dy, const double dz,
                         int &outTag, const double ltx)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addWedge
    (outTag, x, y, z, dx, dy, dz, ltx);
}

int gmshModelOccAddTorus(const int tag, const double x, const double y, const double z,
                         const double r1, const double r2, int &outTag,
                         const double angle)
{
  if(!isInitialized()) return -1;
  createOcc();
  outTag = tag;
  return !GModel::current()->getOCCInternals()->addTorus
    (outTag, x, y, z, r1, r2, angle);
}

int gmshModelOccAddThruSections(const int tag, const std::vector<int> &wireTags,
                                vector_pair &outDimTags, const bool makeSolid,
                                const bool makeRuled)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->addThruSections
    (tag, wireTags, makeSolid, makeRuled, outDimTags);
}

GMSH_API addThickSolid(const int tag, const int solidTag,
                       const std::vector<int> &excludeFaceTags,
                       const double offset, vector_pair &outDimTags)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->addThickSolid
    (tag, solidTag, excludeFaceTags, offset, outDimTags);
}

int gmshModelOccExtrude(const vector_pair &inDimTags,
                        const double dx, const double dy, const double dz,
                        vector_pair &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, const bool recombine)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->extrude
    (inDimTags, dx, dy, dz, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelOccRevolve(const vector_pair &inDimTags,
                        const double x, const double y, const double z,
                        const double ax, const double ay, const double az,
                        const double angle, vector_pair &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, const bool recombine)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->revolve
    (inDimTags, x, y, z, ax, ay, az, angle, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelOccAddPipe(const vector_pair &inDimTags, const int wireTag,
                        vector_pair &outDimTags)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->addPipe
    (inDimTags, wireTag, outDimTags);
}

int gmshModelOccFillet(const std::vector<int> &regionTags,
                       const std::vector<int> &edgeTags,
                       const double radius, vector_pair &outDimTags,
                       const bool removeRegion)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->fillet
    (regionTags, edgeTags, radius, outDimTags, removeRegion);
}

int gmshModelOccBooleanUnion(const int tag, const vector_pair &objectDimTags,
                             const vector_pair &toolDimTags,
                             vector_pair &outDimTags,
                             std::vector<vector_pair > &outDimTagsMap,
                             const bool removeObject, const bool removeTool)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  return !GModel::current()->getOCCInternals()->booleanUnion
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool);
}

int gmshModelOccBooleanIntersection(const int tag, const vector_pair &objectDimTags,
                                    const vector_pair &toolDimTags,
                                    vector_pair &outDimTags,
                                    std::vector<vector_pair > &outDimTagsMap,
                                    const bool removeObject, const bool removeTool)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  return !GModel::current()->getOCCInternals()->booleanIntersection
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool);
}

int gmshModelOccBooleanDifference(const int tag, const vector_pair &objectDimTags,
                                  const vector_pair &toolDimTags,
                                  vector_pair &outDimTags,
                                  std::vector<vector_pair > &outDimTagsMap,
                                  const bool removeObject, const bool removeTool)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  return !GModel::current()->getOCCInternals()->booleanDifference
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool);
}

int gmshModelOccBooleanFragments(const int tag, const vector_pair &objectDimTags,
                                 const vector_pair &toolDimTags,
                                 vector_pair &outDimTags,
                                 std::vector<vector_pair> &outDimTagsMap,
                                 const bool removeObject, const bool removeTool)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  outDimTagsMap.clear();
  return !GModel::current()->getOCCInternals()->booleanFragments
    (tag, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
     removeObject, removeTool);
}

int gmshModelOccTranslate(const vector_pair &dimTags, const double dx,
                          const double dy, const double dz)
{
  if(!isInitialized()) return -1;
  createOcc();
  return !GModel::current()->getOCCInternals()->translate(dimTags, dx, dy, dz);
}

int gmshModelOccRotate(const vector_pair &dimTags, const double x, const double y,
                       const double z, const double ax, const double ay, const double az,
                       const double angle)
{
  if(!isInitialized()) return -1;
  createOcc();
  return !GModel::current()->getOCCInternals()->rotate
    (dimTags, x, y, z, ax, ay, az, angle);
}

int gmshModelOccDilate(const vector_pair &dimTags, const double x, const double y,
                       const double z, const double a, const double b, const double c)
{
  if(!isInitialized()) return -1;
  createOcc();
  return !GModel::current()->getOCCInternals()->dilate
    (dimTags, x, y, z, a, b, c);
}

int gmshModelOccSymmetry(const vector_pair &dimTags,
                         const double a, const double b, const double c, const double d)
{
  if(!isInitialized()) return -1;
  createOcc();
  return !GModel::current()->getOCCInternals()->symmetry
    (dimTags, a, b, c, d);
}

int gmshModelOccCopy(const vector_pair &inDimTags, vector_pair &outDimTags)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags);
}

int gmshModelOccRemove(const vector_pair &dimTags, const bool recursive)
{
  if(!isInitialized()) return -1;
  createOcc();
  return !GModel::current()->getOCCInternals()->remove(dimTags, recursive);
}

int gmshModelOccRemoveAllDuplicates()
{
  if(!isInitialized()) return -1;
  createOcc();
  GModel::current()->getOCCInternals()->removeAllDuplicates();
  return 0;
}

int gmshModelOccImportShapes(const std::string &fileName, vector_pair &outDimTags,
                             const bool highestDimOnly, const std::string &format)
{
  if(!isInitialized()) return -1;
  createOcc();
  outDimTags.clear();
  return !GModel::current()->getOCCInternals()->importShapes
    (fileName, highestDimOnly, outDimTags, format);
}

int gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size)
{
  if(!isInitialized()) return -1;
  createOcc();
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    GModel::current()->getOCCInternals()->setMeshSize(dim, tag, size);
  }
  return 0;
}

int gmshModelOccSynchronize()
{
  if(!isInitialized()) return -1;
  createOcc();
  GModel::current()->getOCCInternals()->synchronize(GModel::current());
  return 0;
}

// gmshModelField

int gmshModelFieldAdd(const int tag, const std::string &type)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  if(!GModel::current()->getFields()->newField(tag, type)){
    Msg::Error("Cannot create Field %i of type '%s'", tag, type.c_str());
    return 1;
  }
  return 0;
#else
  return 1;
#endif
}

#if defined(HAVE_MESH)
static FieldOption *getFieldOption(const int tag, const std::string &option)
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

int gmshModelFieldSetNumber(const int tag, const std::string &option,
                            const double value)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  FieldOption *o = getFieldOption(tag, option);
  if(!o) return 1;
  try { o->numericalValue(value); }
  catch(...){
    Msg::Error("Cannot set numerical value to option '%s' in field %i",
               option.c_str(), tag);
    return 1;
  }
  return 0;
#else
  return 1;
#endif
}

int gmshModelFieldSetString(const int tag, const std::string &option,
                            const std::string &value)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  FieldOption *o = getFieldOption(tag, option);
  if(!o) return 1;
  try { o->string(value); }
  catch(...){
    Msg::Error("Cannot set string value to option '%s' in field %i",
               option.c_str(), tag);
    return 1;
  }
  return 0;
#else
  return 1;
#endif
}

int gmshModelFieldSetNumbers(const int tag, const std::string &option,
                             const std::vector<double> &value)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  FieldOption *o = getFieldOption(tag, option);
  if(!o) return 1;
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
    return 1;
  }
  return 0;
#else
  return 1;
#endif
}

int gmshModelFieldSetAsBackground(const int tag)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  GModel::current()->getFields()->setBackgroundFieldId(tag);
  return 0;
#else
  return 1;
#endif
}

int gmshModelFieldDelete(const int tag)
{
  if(!isInitialized()) return -1;
#if defined(HAVE_MESH)
  GModel::current()->getFields()->deleteField(tag);
  return 0;
#else
  return 1;
#endif
}
