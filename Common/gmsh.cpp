// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

// gmsh

int gmshInitialize(int argc, char **argv)
{
  return !GmshInitialize(argc, argv);
}

int gmshFinalize()
{
  return !GmshFinalize();
}

int gmshOpen(const std::string &fileName)
{
  return !GmshOpenProject(fileName);
}

int gmshMerge(const std::string &fileName)
{
  return !GmshMergeFile(fileName);
}

int gmshExport(const std::string &fileName)
{
  return !GmshWriteFile(fileName);
}

int gmshClear()
{
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

int gmshOptionSetNumber(const std::string &name, double value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetNumber(const std::string &name, double &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

int gmshOptionSetString(const std::string &name, const std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetString(const std::string &name, std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

// gmshModel

int gmshModelCreate(const std::string &name)
{
  GModel *m = new GModel(name);
  return m ? 0 : 1;
}

int gmshModelSetCurrent(const std::string &name)
{
  GModel *m = GModel::findByName(name);
  if(m){
    GModel::setCurrent(m);
    return 0;
  }
  return 1;
}

int gmshModelDestroy()
{
  GModel *m = GModel::current();
  if(m){
    delete m;
    return 0;
  }
  return 1;
}

int gmshModelGetEntities(std::vector<std::pair<int, int> > &dimTags)
{
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    dimTags.push_back(std::pair<int, int>(entities[i]->dim(), entities[i]->tag()));
  return 0;
}

int gmshModelGetPhysicalGroups(std::vector<std::pair<int, int> > &dimTags)
{
  std::map<int, std::vector<GEntity*> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  for(int dim = 0; dim < 4; dim++){
    for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
        it != groups[dim].end(); it++)
      dimTags.push_back(std::pair<int, int>(dim, it->first));
  }
  return 0;
}

int gmshModelAddPhysicalGroup(int dim, int tag, const std::vector<int> &tags)
{
  bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
    (dim, tag, 0, tags);
  if(r){
    GModel::current()->getGEOInternals()->synchronize(GModel::current());
    return 0;
  }
  return 1;
}

int gmshModelGetEntitiesForPhysicalGroup(int dim, int tag,
                                         std::vector<int> &tags)
{
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups.find(tag);
  if(it != groups.end()){
    for(unsigned j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
  return 0;
}

int gmshModelSetPhysicalName(int dim, int tag, const std::string &name)
{
  GModel::current()->setPhysicalName(name, dim, tag);
  return 0;
}

int gmshModelGetPhysicalName(int dim, int tag, std::string &name)
{
  name = GModel::current()->getPhysicalName(dim, tag);
  return 0;
}

int gmshModelGetVertexCoordinates(int tag, double &x, double &y, double &z)
{
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(gv){
    x = gv->x();
    y = gv->y();
    z = gv->z();
    return 0;
  }
  return 1;
}

int gmshModelGetBoundary(const std::vector<std::pair<int, int> > &inDimTags,
                         std::vector<std::pair<int, int> > &outDimTags,
                         bool combined, bool oriented, bool recursive)
{
  bool r = GModel::current()->getBoundaryTags(inDimTags, outDimTags, combined,
                                              oriented, recursive);
  if(r) return 0;
  return 1;
}

int gmshModelGetEntitiesInBoundingBox(int dim,
                                      double x1, double y1, double z1,
                                      double x2, double y2, double z2,
                                      std::vector<int> &tags)
{
  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(unsigned int i = 0; i < entities.size(); i++)
    tags.push_back(entities[i]->tag());
  return 0;
}

int gmshModelGetBoundingBox(int dim, int tag, double &x1, double &y1, double &z1,
                            double &x2, double &y2, double &z2)
{
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

int gmshModelRemove(const std::vector<std::pair<int, int> > &dimTags,
                    bool recursive)
{
  GModel::current()->remove(dimTags, recursive);
  return 0;
}

int gmshModelMesh(int dim)
{
  GModel *m = GModel::current();
  if(m){
    m->mesh(dim);
    return 0;
  }
  return 1;
}

int gmshModelGetMeshVertices(int dim, int tag, std::vector<int> &vertexTags,
                             std::vector<double> &coords)
{
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

int gmshModelGetMeshElements(int dim, int tag, std::vector<int> &types,
                             std::vector<std::vector<int> > &elementTags,
                             std::vector<std::vector<int> > &vertexTags)
{
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

int gmshModelSetMeshSize(int dim, int tag, double size)
{
  if(dim) return 2;
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(gv){
    gv->setPrescribedMeshSizeAtVertex(size);
    return 0;
  }
  return 1;
}

int gmshModelSetTransfiniteLine(int tag, int nPoints, int type, double coef)
{
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

int gmshModelSetTransfiniteSurface(int tag, int arrangement,
                                   const std::vector<int> &cornerTags)
{
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

int gmshModelSetTransfiniteVolume(int tag, const std::vector<int> &cornerTags)
{
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

int gmshModelSetRecombine(int dim, int tag, double angle)
{
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(gf){
    gf->meshAttributes.recombine = 1;
    gf->meshAttributes.recombineAngle = angle;
    return 0;
  }
  return 1;
}

int gmshModelSetSmoothing(int tag, int val)
{
  GFace *gf = GModel::current()->getFaceByTag(tag);
  if(gf){
    gf->meshAttributes.transfiniteSmoothing = val;
    return 0;
  }
  return 1;
}

int gmshModelSetReverseMesh(int dim, int tag)
{
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

int gmshModelAddEmbedded(int dim, const std::vector<int> &tags, int toDim, int toTag)
{
  if(toDim == 2){
    GFace *gf = GModel::current()->getFaceByTag(toTag);
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
  else if(toDim == 3){
    GRegion *gr = GModel::current()->getRegionByTag(toTag);
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

int gmshModelGeoAddVertex(int &tag, double x, double y, double z, double lc)
{
  return !GModel::current()->getGEOInternals()->addVertex(tag, x, y, z, lc);
}

int gmshModelGeoAddLine(int &tag, int startTag, int endTag)
{
  return !GModel::current()->getGEOInternals()->addLine(tag, startTag, endTag);
}

int gmshModelGeoAddCircleArc(int &tag, int startTag, int centerTag, int endTag,
                             double nx, double ny, double nz)
{
  return !GModel::current()->getGEOInternals()->addCircleArc
    (tag, startTag, centerTag, endTag, nx, ny, nz);
}

int gmshModelGeoAddEllipseArc(int &tag, int startTag, int centerTag, int majorTag,
                              int endTag, double nx, double ny, double nz)
{
  return !GModel::current()->getGEOInternals()->addEllipseArc
    (tag, startTag, centerTag, majorTag, endTag, nx, ny, nz);
}

int gmshModelGeoAddSpline(int &tag, const std::vector<int> &vertexTags)
{
  return !GModel::current()->getGEOInternals()->addSpline(tag, vertexTags);
}

int gmshModelGeoAddBSpline(int &tag, const std::vector<int> &vertexTags)
{
  return !GModel::current()->getGEOInternals()->addBSpline(tag, vertexTags);
}

int gmshModelGeoAddBezier(int &tag, const std::vector<int> &vertexTags)
{
  return !GModel::current()->getGEOInternals()->addBezier(tag, vertexTags);
}

int gmshModelGeoAddLineLoop(int &tag, const std::vector<int> &edgeTags)
{
  return !GModel::current()->getGEOInternals()->addLineLoop(tag, edgeTags);
}

int gmshModelGeoAddPlaneSurface(int &tag, const std::vector<int> &wireTags)
{
  return !GModel::current()->getGEOInternals()->addPlaneSurface(tag, wireTags);
}

int gmshModelGeoAddSurfaceFilling(int &tag, const std::vector<int> &wireTags,
                                  int sphereCenterTag)
{
  return !GModel::current()->getGEOInternals()->addSurfaceFilling
    (tag, wireTags, sphereCenterTag);
}

int gmshModelGeoAddSurfaceLoop(int &tag, const std::vector<int> &faceTags)
{
  return !GModel::current()->getGEOInternals()->addSurfaceLoop(tag, faceTags);
}

int gmshModelGeoAddVolume(int &tag, const std::vector<int> &shellTags)
{
  return !GModel::current()->getGEOInternals()->addVolume(tag, shellTags);
}

static ExtrudeParams *getExtrudeParams(const std::vector<int> &numElements,
                                       const std::vector<double> &heights,
                                       bool recombine)
{
  ExtrudeParams *e = 0;
  if(numElements.size()){
    e = new ExtrudeParams();
    e->mesh.ExtrudeMesh = true;
    e->mesh.NbElmLayer = numElements;
    e->mesh.hLayer = heights;
    if(e->mesh.hLayer.empty()) e->mesh.hLayer.push_back(1.);
    e->mesh.Recombine = recombine;
  }
  return e;
}

int gmshModelGeoExtrude(const std::vector<std::pair<int, int> > &inDimTags,
                        double dx, double dy, double dz,
                        std::vector<std::pair<int, int> > &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, bool recombine)
{
  return !GModel::current()->getGEOInternals()->extrude
    (inDimTags, dx, dy, dz, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoRevolve(const std::vector<std::pair<int, int> > &inDimTags,
                        double x, double y, double z,
                        double ax, double ay, double az, double angle,
                        std::vector<std::pair<int, int> > &outDimTags,
                        const std::vector<int> &numElements,
                        const std::vector<double> &heights, bool recombine)
{
  return !GModel::current()->getGEOInternals()->revolve
    (inDimTags, x, y, z, ax, ay, az, angle, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoTwist(const std::vector<std::pair<int, int> > &inDimTags,
                      double x, double y, double z,
                      double dx, double dy, double dz,
                      double ax, double ay, double az, double angle,
                      std::vector<std::pair<int, int> > &outDimTags,
                      const std::vector<int> &numElements,
                      const std::vector<double> &heights, bool recombine)
{
  return !GModel::current()->getGEOInternals()->twist
    (inDimTags, x, y, z, dx, dy, dz, ax, ay, az, angle, outDimTags,
     getExtrudeParams(numElements, heights, recombine));
}

int gmshModelGeoTranslate(const std::vector<std::pair<int, int> > &dimTags,
                          double dx, double dy, double dz)
{
}

int gmshModelGeoRotate(const std::vector<std::pair<int, int> > &dimTags,
                       double x, double y, double z, double ax, double ay, double az,
                       double angle)
{
}

int gmshModelGeoDilate(const std::vector<std::pair<int, int> > &dimTags,
                       double x, double y, double z,
                       double a, double b, double c)
{
}

int gmshModelGeoSymmetry(const std::vector<std::pair<int, int> > &dimTags,
                         double a, double b, double c, double d)
{
}

int gmshModelGeoCopy(const std::vector<std::pair<int, int> > &inDimTags,
                     std::vector<std::pair<int, int> > &outDimTags)
{
}

int gmshModelGeoRemove(const std::vector<std::pair<int, int> > &dimTags,
                       bool recursive)
{
}

int gmshModelGeoRemoveAllDuplicates()
{
}

int gmshModelGeoSynchronize()
{
  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  return 0;
}
