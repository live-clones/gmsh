// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "OS.h"
#include "OpenFile.h"
#include "Numeric.h"
#include "ListUtils.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "GFaceCompound.h"
#include "GEdgeCompound.h"
#include "GRegionCompound.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "Field.h"
#include "Context.h"
#include "Parser.h"

void GEO_Internals::_allocateAll()
{
  _maxPointNum = _maxLineNum = _maxLineLoopNum = _maxSurfaceNum = 0;
  _maxSurfaceLoopNum = _maxVolumeNum = _maxPhysicalNum = 0;

  Points = Tree_Create(sizeof(Vertex *), CompareVertex);
  Curves = Tree_Create(sizeof(Curve *), CompareCurve);
  EdgeLoops = Tree_Create(sizeof(EdgeLoop *), CompareEdgeLoop);
  Surfaces = Tree_Create(sizeof(Surface *), CompareSurface);
  SurfaceLoops = Tree_Create(sizeof(SurfaceLoop *), CompareSurfaceLoop);
  Volumes = Tree_Create(sizeof(Volume *), CompareVolume);

  PhysicalGroups = List_Create(5, 5, sizeof(PhysicalGroup *));
  DelPhysicalGroups = List_Create(5, 5, sizeof(PhysicalGroup *));

  DelPoints = Tree_Create(sizeof(Vertex *), CompareVertex);
  DelCurves = Tree_Create(sizeof(Curve *), CompareCurve);
  DelSurfaces = Tree_Create(sizeof(Surface *), CompareSurface);
  DelVolumes = Tree_Create(sizeof(Volume *), CompareVolume);

  _changed = true;
}

void GEO_Internals::_freeAll()
{
  _maxPointNum = _maxLineNum = _maxLineLoopNum = _maxSurfaceNum = 0;
  _maxSurfaceLoopNum = _maxVolumeNum = _maxPhysicalNum = 0;

  Tree_Action(Points, FreeVertex); Tree_Delete(Points);
  Tree_Action(Curves, FreeCurve); Tree_Delete(Curves);
  Tree_Action(EdgeLoops, FreeEdgeLoop); Tree_Delete(EdgeLoops);
  Tree_Action(Surfaces, FreeSurface); Tree_Delete(Surfaces);
  Tree_Action(SurfaceLoops, FreeSurfaceLoop); Tree_Delete(SurfaceLoops);
  Tree_Action(Volumes, FreeVolume); Tree_Delete(Volumes);

  Tree_Action(DelPoints, FreeVertex); Tree_Delete(DelPoints);
  Tree_Action(DelCurves, FreeCurve); Tree_Delete(DelCurves);
  Tree_Action(DelSurfaces, FreeSurface); Tree_Delete(DelSurfaces);
  Tree_Action(DelVolumes, FreeVolume); Tree_Delete(DelVolumes);

  List_Action(PhysicalGroups, FreePhysicalGroup); List_Delete(PhysicalGroups);
  List_Action(DelPhysicalGroups, FreePhysicalGroup); List_Delete(DelPhysicalGroups);

  _changed = true;
}

void GEO_Internals::setMaxTag(int dim, int val)
{
  switch(dim){
  case 0: _maxPointNum = val; break;
  case 1: _maxLineNum = val; break;
  case -1: _maxLineLoopNum = val; break;
  case 2: _maxSurfaceNum = val; break;
  case -2: _maxSurfaceLoopNum = val; break;
  case 3: _maxVolumeNum = val; break;
  }
}

int GEO_Internals::getMaxTag(int dim) const
{
  switch(dim){
  case 0: return _maxPointNum;
  case 1: return _maxLineNum;
  case -1: return _maxLineLoopNum;
  case 2: return _maxSurfaceNum;
  case -2: return _maxSurfaceLoopNum;
  case 3: return _maxVolumeNum;
  default: return 0;
  }
}

bool GEO_Internals::addVertex(int &tag, double x, double y, double z, double lc)
{
  if(tag >= 0 && FindPoint(tag)){
    Msg::Error("GEO vertex with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(0) + 1;
  Vertex *v = CreateVertex(tag, x, y, z, lc, 1.0);
  Tree_Add(Points, &v);
  _changed = true;
  return true;
}

bool GEO_Internals::addVertex(int &tag, double x, double y, gmshSurface *surface,
                              double lc)
{
  if(tag >= 0 && FindPoint(tag)){
    Msg::Error("GEO vertex with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(0) + 1;
  Vertex *v = CreateVertex(tag, x, y, surface, lc);
  Tree_Add(Points, &v);
  _changed = true;
  return true;
}

bool GEO_Internals::addLine(int &tag, int startTag, int endTag)
{
  std::vector<int> points;
  points.push_back(startTag);
  points.push_back(endTag);
  return addLine(tag, points);
}

bool GEO_Internals::addLine(int &tag, const std::vector<int> &vertexTags)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  Curve *c = CreateCurve(tag, MSH_SEGM_LINE, 1, tmp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addCircleArc(int &tag, int startTag, int centerTag, int endTag,
                                 double nx, double ny, double nz)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(3, 2, sizeof(int));
  List_Add(tmp, &startTag);
  List_Add(tmp, &centerTag);
  List_Add(tmp, &endTag);
  Curve *c = CreateCurve(tag, MSH_SEGM_CIRC, 2, tmp, NULL, -1, -1, 0., 1.);
  if(nx || ny || nz){
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    EndCurve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz){
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    EndCurve(rc);
  }
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addEllipseArc(int &tag, int startTag, int centerTag, int majorTag,
                                  int endTag, double nx, double ny, double nz)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(3, 2, sizeof(int));
  List_Add(tmp, &startTag);
  List_Add(tmp, &centerTag);
  List_Add(tmp, &majorTag);
  List_Add(tmp, &endTag);
  Curve *c = CreateCurve(tag, MSH_SEGM_ELLI, 2, tmp, NULL, -1, -1, 0., 1.);
  if(nx || ny || nz){
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    EndCurve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz){
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    EndCurve(rc);
  }
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addSpline(int &tag, const std::vector<int> &vertexTags)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  Curve *c = CreateCurve(tag, MSH_SEGM_SPLN, 3, tmp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addBSpline(int &tag, const std::vector<int> &vertexTags)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  Curve *c = CreateCurve(tag, MSH_SEGM_BSPLN, 2, tmp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addBezier(int &tag, const std::vector<int> &vertexTags)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  if(vertexTags.size() < 4){
    Msg::Error("Bezier curve requires at least 4 control points");
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  Curve *c = CreateCurve(tag, MSH_SEGM_BEZIER, 2, tmp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addNurbs(int &tag, const std::vector<int> &vertexTags,
                             const std::vector<double> &knots)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  int order = knots.size() - vertexTags.size() - 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  List_T *knotsList = List_Create(2, 2, sizeof(double));
  for(unsigned int i = 0; i < knots.size(); i++){
    double d = knots[i];
    List_Add(knotsList, &d);
  }
  Curve *c = CreateCurve(tag, MSH_SEGM_NURBS, order, tmp, knotsList, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addCompoundLine(int &tag, const std::vector<int> &edgeTags)
{
  if(tag >= 0 && FindCurve(tag)){
    Msg::Error("GEO edge with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  Curve *c = CreateCurve(tag, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
  c->compound = edgeTags;
  EndCurve(c);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  _changed = true;
  return true;
}

bool GEO_Internals::addLineLoop(int &tag, const std::vector<int> &edgeTags)
{
  if(tag >= 0 && FindEdgeLoop(tag)){
    Msg::Error("GEO line loop with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(-1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < edgeTags.size(); i++){
    int t = edgeTags[i];
    List_Add(tmp, &t);
  }
  SortEdgesInLoop(tag, tmp);
  EdgeLoop *l = CreateEdgeLoop(tag, tmp);
  Tree_Add(EdgeLoops, &l);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addPlaneSurface(int &tag, const std::vector<int> &wireTags)
{
  if(tag >= 0 && FindSurface(tag)){
    Msg::Error("GEO face with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  if(wireTags.empty()){
    Msg::Error("Plane surface requires at least one line loop");
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < wireTags.size(); i++){
    int t = wireTags[i];
    List_Add(tmp, &t);
  }
  Surface *s = CreateSurface(tag, MSH_SURF_PLAN);
  SetSurfaceGeneratrices(s, tmp);
  List_Delete(tmp);
  EndSurface(s);
  Tree_Add(Surfaces, &s);
  _changed = true;
  return true;
}

bool GEO_Internals::addDiscreteSurface(int &tag)
{
  if(tag >= 0 && FindSurface(tag)){
    Msg::Error("GEO face with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  Surface *s = CreateSurface(tag, MSH_SURF_DISCRETE);
  Tree_Add(Surfaces, &s);
  _changed = true;
  return true;
}

bool GEO_Internals::addSurfaceFilling(int &tag, const std::vector<int> &wireTags,
                                      int sphereCenterTag)
{
  if(tag >= 0 && FindSurface(tag)){
    Msg::Error("GEO face with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  if(wireTags.empty()){
    Msg::Error("Face requires at least one line loop");
    return false;
  }
  int ll = (int)std::abs(wireTags[0]);
  EdgeLoop *el = FindEdgeLoop(ll);
  if(!el){
    Msg::Error("Unknown line loop %d", ll);
    return false;
  }
  int j = List_Nbr(el->Curves), type = MSH_SURF_PLAN;
  if(j == 4)
    type = MSH_SURF_REGL;
  else if(j == 3)
    type = MSH_SURF_TRIC;
  else{
    Msg::Error("Wrong definition of face %d: %d borders instead of 3 or 4",
               tag, j);
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < wireTags.size(); i++){
    int t = wireTags[i];
    List_Add(tmp, &t);
  }
  Surface *s = CreateSurface(tag, type);
  SetSurfaceGeneratrices(s, tmp);
  List_Delete(tmp);
  EndSurface(s);
  if(sphereCenterTag >= 0){
    s->InSphereCenter = FindPoint(sphereCenterTag);
    if(!s->InSphereCenter){
      Msg::Error("Unknown sphere center vertex %d", sphereCenterTag);
    }
  }
  Tree_Add(Surfaces, &s);
  _changed = true;
  return true;
}

bool GEO_Internals::addCompoundSurface(int &tag, const std::vector<int> &faceTags,
                                       std::vector<int> edgeTags[4])
{
  if(tag >= 0 && FindSurface(tag)){
    Msg::Error("GEO face with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;

  Surface *s = CreateSurface(tag, MSH_SURF_COMPOUND);
  s->compound = faceTags;
  if(edgeTags){
    for(int i = 0; i < 4; i++)
      s->compoundBoundary[i] = edgeTags[i];
  }
  SetSurfaceGeneratrices(s, 0);
  Tree_Add(Surfaces, &s);
  _changed = true;
  return true;
}

bool GEO_Internals::addSurfaceLoop(int &tag, const std::vector<int> &faceTags)
{
  if(tag >= 0 && FindSurfaceLoop(tag)){
    Msg::Error("GEO surface loop with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(-2) + 1;

  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < faceTags.size(); i++){
    int t = faceTags[i];
    List_Add(tmp, &t);
  }
  SurfaceLoop *l = CreateSurfaceLoop(tag, tmp);
  Tree_Add(SurfaceLoops, &l);
  List_Delete(tmp);
  _changed = true;
  return true;
}

bool GEO_Internals::addVolume(int &tag, const std::vector<int> &shellTags)
{
  if(tag >= 0 && FindVolume(tag)){
    Msg::Error("GEO region with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(3) + 1;

  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < shellTags.size(); i++){
    int t = shellTags[i];
    List_Add(tmp, &t);
  }
  Volume *v = CreateVolume(tag, MSH_VOLUME);
  SetVolumeSurfaces(v, tmp);
  List_Delete(tmp);
  Tree_Add(Volumes, &v);
  _changed = true;
  return true;
}

bool GEO_Internals::addCompoundVolume(int &tag, const std::vector<int> &regionTags)
{
  if(tag >= 0 && FindVolume(tag)){
    Msg::Error("GEO region with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(3) + 1;

  Volume *v = CreateVolume(tag, MSH_VOLUME_COMPOUND);
  v->compound = regionTags;
  Tree_Add(Volumes, &v);
  _changed = true;
  return true;
}

bool GEO_Internals::_extrude(int mode,
                             const std::vector<std::pair<int, int> > &inDimTags,
                             double x, double y, double z,
                             double dx, double dy, double dz,
                             double ax, double ay, double az, double angle,
                             std::vector<std::pair<int, int> > &outDimTags,
                             ExtrudeParams *e)
{
  List_T *in = List_Create(inDimTags.size() + 1, 10, sizeof(Shape));
  List_T *out = List_Create(3 * inDimTags.size() + 1, 10, sizeof(Shape));

  for(unsigned int i = 0; i < inDimTags.size(); i++){
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME : (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE : MSH_POINT;
    s.Num = tag;
    List_Add(in, &s);
  }

  if(mode == 0){ // extrude
    ExtrudeShapes(TRANSLATE, in, dx, dy, dz, 0., 0., 0., 0., 0., 0., 0., e, out);
  }
  else if(mode == 1){ // revolve
    ExtrudeShapes(ROTATE, in, 0., 0., 0., ax, ay, az, x, y, z, angle, e, out);
  }
  else if(mode == 2){ // extrude+revolve
    ExtrudeShapes(TRANSLATE_ROTATE, in, dx, dy, dz, ax, ay, az, x, y, z, angle, e, out);
  }
  else if(mode == 3){ // boundary layer
    ExtrudeShapes(BOUNDARY_LAYER, in, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., e, out);
  }

  for(int i = 0; i < List_Nbr(out); i++){
    Shape s;
    List_Read(out, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3) outDimTags.push_back(std::pair<int, int>(dim, s.Num));
  }
  _changed = true;
  return true;
}

bool GEO_Internals::extrude(const std::vector<std::pair<int, int> > &inDimTags,
                            double dx, double dy, double dz,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(0, inDimTags, 0., 0., 0., dx, dy, dz, 0., 0., 0., 0.,
                  outDimTags, e);
}

bool GEO_Internals::revolve(const std::vector<std::pair<int, int> > &inDimTags,
                            double x, double y, double z,
                            double ax, double ay, double az, double angle,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(1, inDimTags, x, y, z, 0., 0., 0., ax, ay, az, angle,
                  outDimTags, e);
}

bool GEO_Internals::twist(const std::vector<std::pair<int, int> > &inDimTags,
                          double x, double y, double z,
                          double dx, double dy, double dz,
                          double ax, double ay, double az, double angle,
                          std::vector<std::pair<int, int> > &outDimTags,
                          ExtrudeParams *e)
{
  return _extrude(2, inDimTags, x, y, z, dx, dy, dz, ax, ay, az, angle,
                  outDimTags, e);
}

bool GEO_Internals::boundaryLayer(const std::vector<std::pair<int, int> > &inDimTags,
                                  std::vector<std::pair<int, int> > &outDimTags,
                                  ExtrudeParams *e)
{
  return _extrude(3, inDimTags, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
                  outDimTags, e);
}

bool GEO_Internals::_transform(int mode,
                               const std::vector<std::pair<int, int> > &dimTags,
                               double x, double y, double z,
                               double dx, double dy, double dz,
                               double a, double b, double c, double d)
{
  List_T *list = List_Create(dimTags.size() + 1, 10, sizeof(Shape));
  for(unsigned int i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first;
    int tag = dimTags[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME : (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE : MSH_POINT;
    s.Num = tag;
    List_Add(list, &s);
  }
  switch(mode){
  case 0: TranslateShapes(dx, dy, dz, list); break;
  case 1: RotateShapes(dx, dy, dz, x, y, z, a, list); break;
  case 2: DilatShapes(x, y, z, a, b, c, list); break;
  case 3: SymmetryShapes(a, b, c, d, list); break;
  }
  _changed = true;
  return true;
}

bool GEO_Internals::translate(const std::vector<std::pair<int, int> > &dimTags,
                              double dx, double dy, double dz)
{
  return _transform(0, dimTags, 0, 0, 0, dx, dy, dz, 0, 0, 0, 0);
}

bool GEO_Internals::rotate(const std::vector<std::pair<int, int> > &dimTags,
                           double x, double y, double z,
                           double ax, double ay, double az, double angle)
{
  return _transform(1, dimTags, x, y, z, ax, ay, az, angle, 0, 0, 0);
}

bool GEO_Internals::dilate(const std::vector<std::pair<int, int> > &dimTags,
                           double x, double y, double z,
                           double a, double b, double c)
{
  return _transform(2, dimTags, x, y, z, 0, 0, 0, a, b, c, 0);
}

bool GEO_Internals::symmetry(const std::vector<std::pair<int, int> > &dimTags,
                             double a, double b, double c, double d)
{
  return _transform(3, dimTags, 0, 0, 0, 0, 0, 0, a, b, c, d);
}

bool GEO_Internals::splitCurve(int tag, const std::vector<int> &vertexTags,
                               std::vector<int> &edgeTags)
{
  List_T *tmp = List_Create(10, 10, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++){
    int t = vertexTags[i];
    List_Add(tmp, &t);
  }
  List_T *curves = List_Create(10, 10, sizeof(Curve *));
  SplitCurve(tag, tmp, curves);
  for(int i = 0; i < List_Nbr(curves); i++){
    Curve *c;
    List_Read(curves, i, &c);
    edgeTags.push_back(c->Num);
  }
  List_Delete(tmp);
  List_Delete(curves);
  _changed = true;
  return true;
}

bool GEO_Internals::intersectCurvesWithSurface(const std::vector<int> &edgeTags,
                                               int faceTag,
                                               std::vector<int> &vertexTags)
{
  List_T *curves = List_Create(10, 10, sizeof(double));
  List_T *shapes = List_Create(10, 10, sizeof(Shape));
  for(unsigned int i = 0; i < edgeTags.size(); i++){
    double d = edgeTags[i];
    List_Add(curves, &d);
  }
  IntersectCurvesWithSurface(curves, faceTag, shapes);
  for(int i = 0; i < List_Nbr(shapes); i++){
    Shape s;
    List_Read(shapes, i, &s);
    if(s.Type == MSH_POINT){
      vertexTags.push_back(s.Num);
    }
    else{
      Msg::Error("Degenerated curve-surface intersection not implemented");
      return false;
    }
  }
  _changed = true;
  return true;
}

bool GEO_Internals::copy(const std::vector<std::pair<int, int> > &inDimTags,
                         std::vector<std::pair<int, int> > &outDimTags)
{
  bool ret = true;
  for(unsigned int i = 0; i < inDimTags.size(); i++){
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(dim == 0){
      Vertex *v = FindPoint(tag);
      if(!v){
        Msg::Error("Unknown GEO vertex with tag %d", tag);
        ret = false;
      }
      else{
        Vertex *newv = DuplicateVertex(v);
        outDimTags.push_back(std::pair<int, int>(0, newv->Num));
      }
    }
    else if(dim == 1){
      Curve *c = FindCurve(tag);
      if(!c){
        Msg::Error("Unknown GEO curve with tag %d", tag);
        ret = false;
      }
      else{
        Curve *newc = DuplicateCurve(c);
        outDimTags.push_back(std::pair<int, int>(1, newc->Num));
      }
    }
    else if(dim == 2){
      Surface *s = FindSurface(tag);
      if(!s){
        Msg::Error("Unknown GEO surface with tag %d", tag);
        ret = false;
      }
      else{
        Surface *news = DuplicateSurface(s);
        outDimTags.push_back(std::pair<int, int>(2, news->Num));
      }
    }
    else if(dim == 3){
      Volume *v = FindVolume(tag);
      if(!v){
        Msg::Error("Unknown GEO region with tag %d", tag);
        ret = false;
      }
      else{
        Volume *newv = DuplicateVolume(v);
        outDimTags.push_back(std::pair<int, int>(3, newv->Num));
      }
    }
  }
  _changed = true;
  return ret;
}

bool GEO_Internals::remove(int dim, int tag, bool recursive)
{
  switch(dim){
  case 0: DeletePoint(tag, recursive); break;
  case 1: DeleteCurve(tag, recursive); DeleteCurve(-tag, recursive); break;
  case 2: DeleteSurface(tag, recursive); break;
  case 3: DeleteVolume(tag, recursive); break;
  }
  _changed = true;
  return true;
}

bool GEO_Internals::remove(const std::vector<std::pair<int, int> > &dimTags,
                           bool recursive)
{
  for(unsigned int i = 0; i < dimTags.size(); i++)
    remove(dimTags[i].first, dimTags[i].second, recursive);
  return true;
}

void GEO_Internals::resetPhysicalGroups()
{
  List_Action(PhysicalGroups, FreePhysicalGroup);
  List_Action(DelPhysicalGroups, FreePhysicalGroup);
  List_Reset(PhysicalGroups);
  _changed = true;
}

bool GEO_Internals::modifyPhysicalGroup(int dim, int tag, int op,
                                        const std::vector<int> &tags)
{
  int type;
  std::string str;
  switch(dim){
  case 0: type = MSH_PHYSICAL_POINT; str = "point"; break;
  case 1: type = MSH_PHYSICAL_LINE; str = "line"; break;
  case 2: type = MSH_PHYSICAL_SURFACE; str = "surface"; break;
  case 3: type = MSH_PHYSICAL_VOLUME; str = "volume"; break;
  default: return false;
  }

  PhysicalGroup *p = FindPhysicalGroup(tag, type);
  if(p && op == 0){
    Msg::Error("Physical %s %d already exists", str.c_str(), tag);
    return false;
  }
  else if(!p && op > 0){
    Msg::Error("Physical %s %d does not exist", str.c_str(), tag);
    return false;
  }
  else if(op == 0){
    List_T *tmp = List_Create(10, 10, sizeof(int));
    for(unsigned int i = 0; i < tags.size(); i++){
      int t = tags[i];
      List_Add(tmp, &t);
    }
    p = CreatePhysicalGroup(tag, type, tmp);
    List_Delete(tmp);
    List_Add(PhysicalGroups, &p);
  }
  else if(op == 1){
    for(unsigned int i = 0; i < tags.size(); i++){
      int t = tags[i];
      List_Add(p->Entities, &t);
    }
  }
  else if(op == 2){
    for(unsigned int i = 0; i < tags.size(); i++){
      int t = tags[i];
      List_Suppress(p->Entities, &t, fcmp_int);
    }
    if(!List_Nbr(p->Entities)){
      switch(dim){
      case 0: DeletePhysicalPoint(tag); break;
      case 1: DeletePhysicalLine(tag); break;
      case 2: DeletePhysicalSurface(tag); break;
      case 3: DeletePhysicalVolume(tag); break;
      }
    }
  }
  else{
    Msg::Error("Unsupported operation on physical %s %d", str.c_str(), tag);
    return false;
  }
  _changed = true;
  return true;
}

void GEO_Internals::removeAllDuplicates()
{
  ReplaceAllDuplicates();
  _changed = true;
}

bool GEO_Internals::mergeVertices(const std::vector<int> &tags)
{
  if(tags.size() < 2) return true;
  Vertex *target = FindPoint(tags[0]);
  if(!target){
    Msg::Error("Could not find GEO vertex with tag %d", tags[0]);
    return false;
  }

  double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
  for(unsigned int i = 1; i < tags.size(); i++){
    Vertex *source = FindPoint(tags[i]);
    if(!source){
      Msg::Error("Could not find GEO vertex with tag %d", tags[i]);
      return false;
    }
    source->Typ = target->Typ;
    source->Pos.X = x;
    source->Pos.Y = y;
    source->Pos.Z = z;
    source->boundaryLayerIndex = target->boundaryLayerIndex;
  }
  ExtrudeParams::normalsCoherence.push_back(SPoint3(x, y, z));
  ReplaceAllDuplicates();
  _changed = true;
  return true;
}

void GEO_Internals::setCompoundMesh(int dim, const std::vector<int> &tags)
{
  _meshCompounds.insert(std::make_pair(dim, tags));
  _changed = true;
}

void GEO_Internals::setMeshSize(int dim, int tag, double size)
{
  if(dim != 0){
    Msg::Error("Setting mesh size only available on GEO vertices");
    return;
  }
  Vertex *v = FindPoint(tag);
  if(v) v->lc = size;
  _changed = true;
}

void GEO_Internals::setDegenerated(int dim, int tag)
{
  if(dim != 1) return;
  Curve *c = FindCurve(tag);
  if(c) c->degenerated = true;
  _changed = true;
}

void GEO_Internals::setTransfiniteLine(int tag, int nPoints, int type, double coef)
{
  if(!tag){
    List_T *tmp = Tree2List(Curves);
    for(int i = 0; i < List_Nbr(tmp); i++){
      Curve *c;
      List_Read(tmp, i, &c);
      c->Method = MESH_TRANSFINITE;
      c->nbPointsTransfinite = (nPoints > 2) ? nPoints : 2;
      c->typeTransfinite = type;
      c->coeffTransfinite = coef;
    }
    List_Delete(tmp);
  }
  else{
    Curve *c = FindCurve(tag);
    if(c){
      c->Method = MESH_TRANSFINITE;
      c->nbPointsTransfinite = (nPoints > 2) ? nPoints : 2;
      c->typeTransfinite = type;
      c->coeffTransfinite = coef;
    }
  }
  _changed = true;
}

void GEO_Internals::setTransfiniteSurface(int tag, int arrangement,
                                          const std::vector<int> &cornerTags)
{
  if(!tag){
    List_T *tmp = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(tmp); i++){
      Surface *s;
      List_Read(tmp, i, &s);
      s->Method = MESH_TRANSFINITE;
      s->Recombine_Dir = arrangement;
      List_Reset(s->TrsfPoints);
    }
    List_Delete(tmp);
  }
  else{
    Surface *s = FindSurface(tag);
    if(s){
      s->Method = MESH_TRANSFINITE;
      s->Recombine_Dir = arrangement;
      List_Reset(s->TrsfPoints);
      if(cornerTags.empty() || cornerTags.size() == 3 || cornerTags.size() == 4){
        for(unsigned int j = 0; j < cornerTags.size(); j++){
          Vertex *v = FindPoint(std::abs(cornerTags[j]));
          if(v)
            List_Add(s->TrsfPoints, &v);
          else
            Msg::Error("Unknown GEO vertex with tag %d", cornerTags[j]);
        }
      }
      else{
        Msg::Error("Transfinite surface requires 3 or 4 corner vertices");
      }
    }
  }
  _changed = true;
}

void GEO_Internals::setTransfiniteVolume(int tag, const std::vector<int> &cornerTags)
{
  if(!tag){
    List_T *tmp = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(tmp); i++){
      Volume *v;
      List_Read(tmp, i, &v);
      v->Method = MESH_TRANSFINITE;
      List_Reset(v->TrsfPoints);
    }
    List_Delete(tmp);
  }
  else{
    Volume *v = FindVolume(tag);
    if(v){
      v->Method = MESH_TRANSFINITE;
      List_Reset(v->TrsfPoints);
      if(cornerTags.empty() || cornerTags.size() == 6 || cornerTags.size() == 8){
        for(unsigned int i = 0; i < cornerTags.size(); i++){
          Vertex *vert = FindPoint(std::abs(cornerTags[i]));
          if(vert)
            List_Add(v->TrsfPoints, &vert);
          else
            Msg::Error("Unknown GEO vertex with tag %d", cornerTags[i]);
        }
      }
    }
  }
  _changed = true;
}

void GEO_Internals::setTransfiniteVolumeQuadTri(int tag)
{
  if(!tag){
    List_T *tmp = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(tmp); i++){
      Volume *v;
      List_Read(tmp, i, &v);
      v->QuadTri = TRANSFINITE_QUADTRI_1;
    }
    List_Delete(tmp);
  }
  else{
    Volume *v = FindVolume(tag);
    if(v)
      v->QuadTri = TRANSFINITE_QUADTRI_1;
  }
  _changed = true;
}

void GEO_Internals::setRecombine(int dim, int tag, double angle)
{
  if(dim == 2){
    if(!tag){
      List_T *tmp = Tree2List(Surfaces);
      for(int i = 0; i < List_Nbr(tmp); i++){
        Surface *s;
        List_Read(tmp, i, &s);
        s->Recombine = 1;
        s->RecombineAngle = angle;
      }
      List_Delete(tmp);
    }
    else{
      Surface *s = FindSurface(tag);
      if(s){
        s->Recombine = 1;
        s->RecombineAngle = angle;
      }
    }
  }
  else if(dim == 3){
    if(!tag){
      List_T *tmp = Tree2List(Volumes);
      for(int i = 0; i < List_Nbr(tmp); i++){
        Volume *v;
        List_Read(tmp, i, &v);
        v->Recombine3D = 1;
      }
      List_Delete(tmp);
    }
    else{
      Volume *v = FindVolume(tag);
      if(v){
        v->Recombine3D = 1;
      }
    }
  }
  _changed = true;
}

void GEO_Internals::setSmoothing(int tag, int val)
{
  if(!tag){
    List_T *tmp = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(tmp); i++){
      Surface *s;
      List_Read(tmp, i, &s);
      s->TransfiniteSmoothing = val;
    }
    List_Delete(tmp);
  }
  else{
    Surface *s = FindSurface(tag);
    if(s) s->TransfiniteSmoothing = val;
  }
  _changed = true;
}

void GEO_Internals::setReverseMesh(int dim, int tag)
{
  if(dim == 1){
    if(!tag){
      List_T *tmp = Tree2List(Curves);
      for(int i = 0; i < List_Nbr(tmp); i++){
        Curve *c;
        List_Read(tmp, i, &c);
        c->ReverseMesh = 1;
      }
      List_Delete(tmp);
    }
    else{
      Curve *c = FindCurve(tag);
      if(c) c->ReverseMesh = 1;
    }
  }
  else if(dim == 2){
    if(!tag){
      List_T *tmp = Tree2List(Surfaces);
      for(int i = 0; i < List_Nbr(tmp); i++){
        Surface *s;
        List_Read(tmp, i, &s);
        s->ReverseMesh = 1;
      }
      List_Delete(tmp);
    }
    else{
      Surface *s = FindSurface(tag);
      if(s) s->ReverseMesh = 1;
    }
  }
  _changed = true;
}

void GEO_Internals::synchronize(GModel *model)
{
  Msg::Debug("Syncing GEO_Internals with GModel");

  // if the entities do not exist in GModel, we create them; if they exist as
  // GEO entities in GModel but don't exist (anymore) in the internal CAD data,
  // we remove them. And if they exist in both the internal CAD data and in the
  // GModel, we update the pointer and the underlying dependencies (e.g. surface
  // boundaries): this is necessary because a GEO entity can change (while
  // keeping the same tag), due e.g. to ReplaceDuplicates.

  std::vector<std::pair<int, int> > toRemove;
  for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    GVertex *gv = *it;
    if(gv->getNativeType() == GEntity::GmshModel){
      if(!FindPoint(gv->tag()))
        toRemove.push_back(std::pair<int, int>(0, gv->tag()));
    }
  }
  for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    GEdge *ge = *it;
    if(ge->getNativeType() == GEntity::GmshModel){
      if(!FindCurve(ge->tag()))
        toRemove.push_back(std::pair<int, int>(1, ge->tag()));
    }
  }
  for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it){
    GFace *gf = *it;
    if(gf->getNativeType() == GEntity::GmshModel){
      if(!FindSurface(gf->tag()))
        toRemove.push_back(std::pair<int, int>(2, gf->tag()));
    }
  }
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    GRegion *gr = *it;
    if(gr->getNativeType() == GEntity::GmshModel){
      if(!FindVolume(gr->tag()))
        toRemove.push_back(std::pair<int, int>(3, gr->tag()));
    }
  }
  Msg::Debug("Sync is removing %d model entities", toRemove.size());
  model->remove(toRemove);

  if(Tree_Nbr(Points)) {
    List_T *points = Tree2List(Points);
    for(int i = 0; i < List_Nbr(points); i++){
      Vertex *p;
      List_Read(points, i, &p);
      GVertex *v = model->getVertexByTag(p->Num);
      if(!v){
        v = new gmshVertex(model, p);
        model->add(v);
      }
      else{
        if(v->getNativeType() == GEntity::GmshModel)
          ((gmshVertex*)v)->resetNativePtr(p);
        v->resetMeshAttributes();
      }
    }
    List_Delete(points);
  }

  if(Tree_Nbr(Curves)) {
    List_T *curves = Tree2List(Curves);
    // generate all curves except compounds
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0){
        GEdge *e = model->getEdgeByTag(c->Num);
        if(!e && c->Typ == MSH_SEGM_COMPOUND){
          Msg::Debug("Postpone creation of compound edge %d until all others "
                     "have been created", c->Num);
        }
        else if(!e && c->beg && c->end){
          e = new gmshEdge(model, c, model->getVertexByTag(c->beg->Num),
                           model->getVertexByTag(c->end->Num));
          model->add(e);
        }
        else if(!e){
          e = new gmshEdge(model, c, 0, 0);
          model->add(e);
        }
        else{
          if(e->getNativeType() == GEntity::GmshModel &&
             c->Typ != MSH_SEGM_COMPOUND){
            if(c->beg && c->end)
              ((gmshEdge*)e)->resetNativePtr(c, model->getVertexByTag(c->beg->Num),
                                             model->getVertexByTag(c->end->Num));
            else
              ((gmshEdge*)e)->resetNativePtr(c, 0, 0);
          }
          e->resetMeshAttributes();
        }
        if(c->degenerated) e->setTooSmall(true);
      }
    }
    // now generate the compound curves
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0){
        GEdge *e = model->getEdgeByTag(c->Num);
        if(!e && c->Typ == MSH_SEGM_COMPOUND){
          std::vector<GEdge*> comp;
          for(unsigned int j = 0; j < c->compound.size(); j++){
            GEdge *ge = model->getEdgeByTag(c->compound[j]);
            if(ge) comp.push_back(ge);
          }
          e = new GEdgeCompound(model, c->Num, comp);
          e->meshAttributes.method = c->Method;
          e->meshAttributes.nbPointsTransfinite = c->nbPointsTransfinite;
          e->meshAttributes.typeTransfinite = c->typeTransfinite;
          e->meshAttributes.coeffTransfinite = c->coeffTransfinite;
          e->meshAttributes.extrude = c->Extrude;
          e->meshAttributes.reverseMesh = c->ReverseMesh;
          model->add(e);
          if(c->degenerated) e->setTooSmall(true);
        }
      }
    }
    List_Delete(curves);
  }

  if(Tree_Nbr(Surfaces)) {
    List_T *surfaces = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      GFace *f = model->getFaceByTag(s->Num);
      if(!f && s->Typ == MSH_SURF_COMPOUND){
        std::list<GFace*> comp;
        for(unsigned int j = 0; j < s->compound.size(); j++){
          GFace *gf = model->getFaceByTag(s->compound[j]);
          if(gf)
            comp.push_back(gf);
        }
        std::list<GEdge*> b[4];
        for(int j = 0; j < 4; j++){
          for(unsigned int k = 0; k < s->compoundBoundary[j].size(); k++){
            GEdge *ge = model->getEdgeByTag(s->compoundBoundary[j][k]);
            if(ge) b[j].push_back(ge);
          }
        }
        int param = CTX::instance()->mesh.remeshParam;
        GFaceCompound::typeOfCompound typ = GFaceCompound::HARMONIC_CIRCLE;
        if (param == 1) typ = GFaceCompound::CONFORMAL_SPECTRAL;
        if (param == 2) typ = GFaceCompound::RADIAL_BASIS;
        if (param == 3) typ = GFaceCompound::HARMONIC_PLANE;
        if (param == 4) typ = GFaceCompound::CONVEX_CIRCLE;
        if (param == 5) typ = GFaceCompound::CONVEX_PLANE;
        if (param == 6) typ = GFaceCompound::HARMONIC_SQUARE;
        if (param == 7) typ = GFaceCompound::CONFORMAL_FE;
        int algo = CTX::instance()->mesh.remeshAlgo;
        f = new GFaceCompound(model, s->Num, comp, b[0], b[1], b[2], b[3], typ, algo);
        f->meshAttributes.recombine = s->Recombine;
        f->meshAttributes.recombineAngle = s->RecombineAngle;
        f->meshAttributes.method = s->Method;
        f->meshAttributes.extrude = s->Extrude;
        f->meshAttributes.transfiniteArrangement = s->Recombine_Dir;
        f->meshAttributes.corners.clear();
        for(int j = 0; j < List_Nbr(s->TrsfPoints); j++){
          Vertex *corn;
          List_Read(s->TrsfPoints, j, &corn);
          GVertex *gv = f->model()->getVertexByTag(corn->Num);
          if(gv)
            f->meshAttributes.corners.push_back(gv);
          else
            Msg::Error("Unknown vertex %d in transfinite attributes", corn->Num);
        }
        model->add(f);
      }
      else if(!f){
        f = new gmshFace(model, s);
        model->add(f);
      }
      else{
        if(f->getNativeType() == GEntity::GmshModel &&
           s->Typ != MSH_SURF_COMPOUND)
          ((gmshFace*)f)->resetNativePtr(s);
        f->resetMeshAttributes();
      }
    }
    List_Delete(surfaces);
  }

  if(Tree_Nbr(Volumes)) {
    List_T *volumes = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      GRegion *r = model->getRegionByTag(v->Num);
      if(!r && v->Typ == MSH_VOLUME_COMPOUND){
        std::vector<GRegion*> comp;
        for(unsigned int j = 0; j < v->compound.size(); j++){
          GRegion *gr = model->getRegionByTag(v->compound[j]);
          if(gr) comp.push_back(gr);
        }
        r = new GRegionCompound(model, v->Num, comp);
        model->add(r);
      }
      else if(!r){
        r = new gmshRegion(model, v);
        model->add(r);
      }
      else{
        if(r->getNativeType() == GEntity::GmshModel &&
           v->Typ != MSH_VOLUME_COMPOUND)
          ((gmshRegion*)r)->resetNativePtr(v);
        r->resetMeshAttributes();
      }
    }
    List_Delete(volumes);
  }

  // we might want to store physical groups directly in GModel; but this is OK
  // for now. We always start from scratch in GModel, as physical groups are
  // only stored in GEO internals anyway
  model->deletePhysicalGroups();
  for(int i = 0; i < List_Nbr(PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(PhysicalGroups, i, &p);
    for(int j = 0; j < List_Nbr(p->Entities); j++){
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = 0;
      int tag = CTX::instance()->geom.orientedPhysicals ? abs(num) : num;
      switch(p->Typ){
      case MSH_PHYSICAL_POINT:   ge = model->getVertexByTag(tag); break;
      case MSH_PHYSICAL_LINE:    ge = model->getEdgeByTag(tag); break;
      case MSH_PHYSICAL_SURFACE: ge = model->getFaceByTag(tag); break;
      case MSH_PHYSICAL_VOLUME:  ge = model->getRegionByTag(tag); break;
      }
      int pnum = CTX::instance()->geom.orientedPhysicals ?
        (gmsh_sign(num) * p->Num) : p->Num;
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), pnum) ==
         ge->physicals.end())
        ge->physicals.push_back(pnum);
    }
  }

  // we might want to store mesh compounds directly in GModel; but this is OK
  // for now.
  for(std::multimap<int, std::vector<int> >::iterator it = _meshCompounds.begin();
      it != _meshCompounds.end(); ++it){
    int dim = it->first;
    std::vector<int> compound = it->second;
    std::vector<GEntity*> ents;
    for (unsigned int i = 0; i < compound.size(); i++){
      int tag = compound[i];
      GEntity *ent = NULL;
      switch(dim) {
      case 1: ent = model->getEdgeByTag(tag); break;
      case 2: ent = model->getFaceByTag(tag); break;
      case 3: ent = model->getRegionByTag(tag); break;
      default : Msg::Error("compound mesh with dimension %d",dim);
      }
      if(ent) ents.push_back(ent);
    }
    for (unsigned int i=0;i<ents.size();i++){
      ents[i]->_compound = ents;
    }
  }

  Msg::Debug("GModel imported:");
  Msg::Debug("%d vertices", model->getNumVertices());
  Msg::Debug("%d edges", model->getNumEdges());
  Msg::Debug("%d faces", model->getNumFaces());
  Msg::Debug("%d regions", model->getNumRegions());

  _changed = false;
}

bool GEO_Internals::getVertex(int tag, double &x, double &y, double &z)
{
  Vertex *v = FindPoint(tag);
  if(v){
    x = v->Pos.X;
    y = v->Pos.Y;
    z = v->Pos.Z;
    return true;
  }
  return false;
}

gmshSurface *GEO_Internals::newGeometrySphere(int tag, int centerTag, int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1){
    Msg::Error("Unknown sphere center vertex %d", centerTag);
    return 0;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2){
    Msg::Error("Unknown sphere vertex %d", pointTag);
    return 0;
  }
  return gmshSphere::NewSphere
    (tag, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
          (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
          (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

gmshSurface *GEO_Internals::newGeometryPolarSphere(int tag, int centerTag, int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1){
    Msg::Error("Unknown polar sphere center vertex %d", centerTag);
    return 0;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2){
    Msg::Error("Unknown polar sphere vertex %d", pointTag);
    return 0;
  }
  return gmshPolarSphere::NewPolarSphere
    (tag, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
          (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
          (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

// GModel interface

void GModel::_createGEOInternals()
{
  _geo_internals = new GEO_Internals;
}

void GModel::_deleteGEOInternals()
{
  if(_geo_internals) delete _geo_internals;
  _geo_internals = 0;
}

class writeFieldOptionGEO {
 private :
  FILE *geo;
  Field *field;
 public :
  writeFieldOptionGEO(FILE *fp, Field *_field)
  {
    geo = fp ? fp : stdout;
    field = _field;
  }
  void operator() (std::pair<std::string, FieldOption *> it)
  {
    std::string v;
    it.second->getTextRepresentation(v);
    fprintf(geo, "Field[%i].%s = %s;\n", field->id, it.first.c_str(), v.c_str());
  }
};

class writeFieldGEO {
  private :
    FILE *geo;
  public :
    writeFieldGEO(FILE *fp) { geo = fp ? fp : stdout; }
    void operator() (std::pair<const int, Field *> it)
    {
      fprintf(geo, "Field[%i] = %s;\n", it.first, it.second->getName());
      std::for_each(it.second->options.begin(), it.second->options.end(),
          writeFieldOptionGEO(geo, it.second));
    }
};

class writePhysicalGroupGEO {
  private :
    FILE *geo;
    int dim;
    bool printLabels;
    std::map<int, std::string> &oldLabels;
    std::map<std::pair<int, int>, std::string> &newLabels;
  public :
    writePhysicalGroupGEO(FILE *fp, int i, bool labels,
        std::map<int, std::string> &o,
        std::map<std::pair<int, int>, std::string> &n)
      : dim(i), printLabels(labels), oldLabels(o), newLabels(n)
    {
      geo = fp ? fp : stdout;
    }
    void operator () (std::pair<const int, std::vector<GEntity *> > &g)
    {
      std::string oldName, newName;
      if(printLabels){
        if(newLabels.count(std::pair<int, int>(dim, g.first))) {
          newName = newLabels[std::pair<int, int>(dim, g.first)];
        }
        else if(oldLabels.count(g.first)) {
          oldName = oldLabels[g.first];
          fprintf(geo, "%s = %d;\n", oldName.c_str(), g.first);
        }
      }

      switch (dim) {
        case 0: fprintf(geo, "Physical Point"); break;
        case 1: fprintf(geo, "Physical Line"); break;
        case 2: fprintf(geo, "Physical Surface"); break;
        case 3: fprintf(geo, "Physical Volume"); break;
      }

      if(oldName.size())
        fprintf(geo, "(%s) = {", oldName.c_str());
      else if(newName.size())
        fprintf(geo, "(\"%s\") = {", newName.c_str());
      else
        fprintf(geo, "(%d) = {", g.first);
      for(unsigned int i = 0; i < g.second.size(); i++) {
        if(i) fprintf(geo, ", ");
        fprintf(geo, "%d", g.second[i]->tag());
      }
      fprintf(geo, "};\n");
    }
};

static bool skipRegion(GRegion *gr)
{
  if(gr->physicals.size()) return false;
  return true;
}

static bool skipFace(GFace *gf)
{
  if(gf->physicals.size()) return false;
  std::list<GRegion*> regions(gf->regions());
  for(std::list<GRegion*>::iterator itr = regions.begin(); itr != regions.end(); itr++){
    if(!skipRegion(*itr)) return false;
  }
  return true;
}

static bool skipEdge(GEdge *ge)
{
  if(ge->physicals.size()) return false;
  std::list<GFace*> faces(ge->faces());
  for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++){
    if(!skipFace(*itf)) return false;
  }
  return true;
}

static bool skipVertex(GVertex *gv)
{
  if(gv->physicals.size()) return false;
  std::list<GEdge*> edges(gv->edges());
  for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++){
    if(!skipEdge(*ite)) return false;
  }
  return true;
}

int GModel::writeGEO(const std::string &name, bool printLabels, bool onlyPhysicals)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Could not open file '%s'", name.c_str());
    return 0;
  }

  std::map<double, std::string> meshSizeParameters;
  int cpt = 0;
  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(meshSizeParameters.find(val) == meshSizeParameters.end()){
      std::ostringstream paramName;
      paramName << "cl__" << ++cpt;
      fprintf(fp, "%s = %.16g;\n", paramName.str().c_str(), val);
      meshSizeParameters.insert(std::make_pair(val, paramName.str()));
    }
  }

  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(!onlyPhysicals || !skipVertex(*it))
      (*it)->writeGEO(fp, meshSizeParameters[val]);
  }
  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if(!onlyPhysicals || !skipEdge(*it))
      (*it)->writeGEO(fp);
  }
  for(fiter it = firstFace(); it != lastFace(); it++){
    if(!onlyPhysicals || !skipFace(*it))
      (*it)->writeGEO(fp);
  }
  for(riter it = firstRegion(); it != lastRegion(); it++){
    if(!onlyPhysicals || !skipRegion(*it))
      (*it)->writeGEO(fp);
  }

  std::map<int, std::string> labels;
#if defined(HAVE_PARSER)
  // get "old-style" labels from parser
  for(std::map<std::string, gmsh_yysymbol>::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); ++it)
    for(unsigned int i = 0; i < it->second.value.size(); i++)
      labels[(int)it->second.value[i]] = it->first;
#endif

  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  for(int i = 0; i < 4; i++)
    std::for_each(groups[i].begin(), groups[i].end(),
        writePhysicalGroupGEO(fp, i, printLabels, labels, physicalNames));

  std::for_each(getFields()->begin(), getFields()->end(), writeFieldGEO(fp));
  if(getFields()->getBackgroundField() > 0)
    fprintf(fp, "Background Field = %i;\n", getFields()->getBackgroundField());

  fclose(fp);
  return 1;
}

int GModel::exportDiscreteGEOInternals()
{
  int maxv = 1; // FIXME: temorary - see TODO below

  if(_geo_internals){
    maxv = _geo_internals->getMaxTag(3);
    delete _geo_internals;
  }
  _geo_internals = new GEO_Internals;

  for(viter it = firstVertex(); it != lastVertex(); it++){
    Vertex *v = CreateVertex((*it)->tag(), (*it)->x(), (*it)->y(), (*it)->z(),
        (*it)->prescribedMeshSizeAtVertex(), 1.0);
    Tree_Add(_geo_internals->Points, &v);
  }

  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if((*it)->geomType() == GEntity::DiscreteCurve){
      Curve *c = CreateCurve((*it)->tag(), MSH_SEGM_DISCRETE, 1,
          NULL, NULL, -1, -1, 0., 1.);
      List_T *points = Tree2List(_geo_internals->Points);
      GVertex *gvb = (*it)->getBeginVertex();
      GVertex *gve = (*it)->getEndVertex();
      int nb = 2 ;
      c->Control_Points = List_Create(nb, 1, sizeof(Vertex *));
      for(int i = 0; i < List_Nbr(points); i++) {
        Vertex *v;
        List_Read(points, i, &v);
        if (v->Num == gvb->tag()) {
          List_Add(c->Control_Points, &v);
          c->beg = v;
        }
        if (v->Num == gve->tag()) {
          List_Add(c->Control_Points, &v);
          c->end = v;
        }
      }
      EndCurve(c);
      Tree_Add(_geo_internals->Curves, &c);
      CreateReversedCurve(c);
      List_Delete(points);
    }
  }

  for(fiter it = firstFace(); it != lastFace(); it++){
    if((*it)->geomType() == GEntity::DiscreteSurface){
      Surface *s = CreateSurface((*it)->tag(), MSH_SURF_DISCRETE);
      std::list<GEdge*> edges = (*it)->edges();
      s->Generatrices = List_Create(edges.size(), 1, sizeof(Curve *));
      List_T *curves = Tree2List(_geo_internals->Curves);
      Curve *c;
      for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++){
        for(int i = 0; i < List_Nbr(curves); i++) {
          List_Read(curves, i, &c);
          if (c->Num == (*ite)->tag()) {
            List_Add(s->Generatrices, &c);
          }
        }
      }
      Tree_Add(_geo_internals->Surfaces, &s);
      List_Delete(curves);
    }
  }

  // TODO: create Volumes from discreteRegions ; meanwhile, keep track of
  // maximum volume tag so that we don't break later operations:
  _geo_internals->setMaxTag(3, maxv);

  Msg::Debug("Geo internal model has:");
  Msg::Debug("%d Vertices", Tree_Nbr(_geo_internals->Points));
  Msg::Debug("%d Edges", Tree_Nbr(_geo_internals->Curves));
  Msg::Debug("%d Faces", Tree_Nbr(_geo_internals->Surfaces));

  return 1;
}
