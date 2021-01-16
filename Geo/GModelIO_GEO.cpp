// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "OS.h"
#include "OpenFile.h"
#include "Numeric.h"
#include "ListUtils.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "Context.h"
#include "Parser.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

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

  Tree_Action(Points, FreeVertex);
  Tree_Delete(Points);
  Tree_Action(Curves, FreeCurve);
  Tree_Delete(Curves);
  Tree_Action(EdgeLoops, FreeEdgeLoop);
  Tree_Delete(EdgeLoops);
  Tree_Action(Surfaces, FreeSurface);
  Tree_Delete(Surfaces);
  Tree_Action(SurfaceLoops, FreeSurfaceLoop);
  Tree_Delete(SurfaceLoops);
  Tree_Action(Volumes, FreeVolume);
  Tree_Delete(Volumes);

  Tree_Action(DelPoints, FreeVertex);
  Tree_Delete(DelPoints);
  Tree_Action(DelCurves, FreeCurve);
  Tree_Delete(DelCurves);
  Tree_Action(DelSurfaces, FreeSurface);
  Tree_Delete(DelSurfaces);
  Tree_Action(DelVolumes, FreeVolume);
  Tree_Delete(DelVolumes);

  List_Action(PhysicalGroups, FreePhysicalGroup);
  List_Delete(PhysicalGroups);
  List_Action(DelPhysicalGroups, FreePhysicalGroup);
  List_Delete(DelPhysicalGroups);

  _changed = true;
}

void GEO_Internals::setMaxTag(int dim, int val)
{
  switch(dim) {
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
  switch(dim) {
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
  if(tag >= 0 && FindPoint(tag)) {
    Msg::Error("GEO point with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(0) + 1;
  if(!lc) lc = MAX_LC;
  Vertex *v = CreateVertex(tag, x, y, z, lc, 1.0);
  Tree_Add(Points, &v);
  _changed = true;
  return true;
}

bool GEO_Internals::addVertex(int &tag, double x, double y,
                              gmshSurface *surface, double lc)
{
  if(tag >= 0 && FindPoint(tag)) {
    Msg::Error("GEO point with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(0) + 1;
  if(!lc) lc = MAX_LC;
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

bool GEO_Internals::addLine(int &tag, const std::vector<int> &pointTags)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(pointTags.size() < 2) {
    Msg::Error("Line requires 2 points");
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < pointTags.size(); i++) {
    int t = pointTags[i];
    List_Add(tmp, &t);
  }
  bool ok = true;
  Curve *c =
    CreateCurve(tag, MSH_SEGM_LINE, 1, tmp, nullptr, -1, -1, 0., 1., ok);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addCircleArc(int &tag, int startTag, int centerTag,
                                 int endTag, double nx, double ny, double nz)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(3, 2, sizeof(int));
  List_Add(tmp, &startTag);
  List_Add(tmp, &centerTag);
  List_Add(tmp, &endTag);
  bool ok = true;
  Curve *c =
    CreateCurve(tag, MSH_SEGM_CIRC, 2, tmp, nullptr, -1, -1, 0., 1., ok);
  if(nx || ny || nz) {
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    EndCurve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz) {
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    EndCurve(rc);
  }
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addEllipseArc(int &tag, int startTag, int centerTag,
                                  int majorTag, int endTag, double nx,
                                  double ny, double nz)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(3, 2, sizeof(int));
  List_Add(tmp, &startTag);
  List_Add(tmp, &centerTag);
  List_Add(tmp, &majorTag);
  List_Add(tmp, &endTag);
  bool ok = true;
  Curve *c =
    CreateCurve(tag, MSH_SEGM_ELLI, 2, tmp, nullptr, -1, -1, 0., 1., ok);
  if(nx || ny || nz) {
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    EndCurve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz) {
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    EndCurve(rc);
  }
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addSpline(int &tag, const std::vector<int> &pointTags)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(pointTags.size() < 2) {
    Msg::Error("Spline curve requires at least 2 control points");
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < pointTags.size(); i++) {
    int t = pointTags[i];
    List_Add(tmp, &t);
  }
  bool ok = true;
  Curve *c =
    CreateCurve(tag, MSH_SEGM_SPLN, 3, tmp, nullptr, -1, -1, 0., 1., ok);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addBezier(int &tag, const std::vector<int> &pointTags)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  if(pointTags.size() < 2) {
    Msg::Error("Bezier curve requires at least 2 control points");
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < pointTags.size(); i++) {
    int t = pointTags[i];
    List_Add(tmp, &t);
  }
  bool ok = true;
  Curve *c =
    CreateCurve(tag, MSH_SEGM_BEZIER, 2, tmp, nullptr, -1, -1, 0., 1., ok);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addBSpline(int &tag, const std::vector<int> &pointTags,
                               const std::vector<double> &seqknots)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(pointTags.size() < 2) {
    Msg::Error("BSpline curve requires at least 2 control points");
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < pointTags.size(); i++) {
    int t = pointTags[i];
    List_Add(tmp, &t);
  }
  Curve *c = nullptr;
  bool ok = true;
  if(seqknots.empty()) {
    c = CreateCurve(tag, MSH_SEGM_BSPLN, 2, tmp, nullptr, -1, -1, 0., 1., ok);
  }
  else {
    int order = seqknots.size() - pointTags.size() - 1;
    List_T *knotsList = List_Create(2, 2, sizeof(double));
    for(std::size_t i = 0; i < seqknots.size(); i++) {
      double d = seqknots[i];
      List_Add(knotsList, &d);
    }
    c = CreateCurve(tag, MSH_SEGM_NURBS, order, tmp, knotsList, -1, -1, 0., 1.,
                    ok);
  }
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::_addCompoundSpline(int &tag,
                                       const std::vector<int> &curveTags,
                                       int numIntervals, bool bspline)
{
  if(tag >= 0 && FindCurve(tag)) {
    Msg::Error("GEO curve with tag %d already exists", tag);
    return false;
  }
  if(curveTags.empty()) {
    Msg::Error("Compound spline curve requires at least 1 input curve");
    return false;
  }
  if(numIntervals < 0) {
    Msg::Error("Negative number of intervals in compound spline");
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;

  List_T *tmp =
    List_Create((numIntervals + 1) * curveTags.size(), 2, sizeof(int));
  for(std::size_t i = 0; i < curveTags.size(); i++) {
    Curve *c = FindCurve(curveTags[i]);
    if(!c) {
      Msg::Error("Unknown GEO curve with tag %d", curveTags[i]);
      return false;
    }
    if(i == 0 && c->beg) List_Add(tmp, &c->beg->Num);
    for(int j = 1; j < numIntervals; j++) {
      double u = (double)j / (double)(numIntervals);
      Vertex V = InterpolateCurve(c, u, 0);
      double lc = (1 - u) * c->beg->lc + u * c->end->lc;
      int tag = getMaxTag(0) + 1;
      Vertex *v = CreateVertex(tag, V.Pos.X, V.Pos.Y, V.Pos.Z, lc, 1.0);
      Tree_Add(Points, &v);
      List_Add(tmp, &v->Num);
    }
    if(c->end) List_Add(tmp, &c->end->Num);
  }
  bool ok = true;
  Curve *c;
  if(bspline)
    c = CreateCurve(tag, MSH_SEGM_BSPLN, 2, tmp, nullptr, -1, -1, 0., 1., ok);
  else // often too oscillatory for non-uniform distribution of control points
    c = CreateCurve(tag, MSH_SEGM_SPLN, 3, tmp, nullptr, -1, -1, 0., 1., ok);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

bool GEO_Internals::addCompoundSpline(int &tag,
                                      const std::vector<int> &curveTags,
                                      int numIntervals)
{
  return _addCompoundSpline(tag, curveTags, numIntervals, false);
}

bool GEO_Internals::addCompoundBSpline(int &tag,
                                       const std::vector<int> &curveTags,
                                       int numIntervals)
{
  return _addCompoundSpline(tag, curveTags, numIntervals, true);
}

bool GEO_Internals::addCurveLoop(int &tag, const std::vector<int> &curveTags,
                                 bool reorient)
{
  if(tag >= 0 && FindEdgeLoop(tag)) {
    Msg::Error("GEO line loop with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(-1) + 1;
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < curveTags.size(); i++) {
    int t = curveTags[i];
    List_Add(tmp, &t);
  }
  bool ok = SortEdgesInLoop(tag, tmp, reorient);
  EdgeLoop *l = CreateEdgeLoop(tag, tmp);
  Tree_Add(EdgeLoops, &l);
  List_Delete(tmp);
  _changed = true;
  return ok;
}

struct VertexPtrLessThan {
  bool operator()(const Vertex *v1, const Vertex *v2) const
  {
    return v1->Num < v2->Num;
  }
};

static bool SortCurvesConsecutive(const std::vector<Curve *> &e,
                                  std::vector<std::vector<Vertex *> > &vs)
{
  vs.clear();
  if(e.empty()) return true;
  std::map<Vertex *, std::pair<Vertex *, Vertex *>, VertexPtrLessThan> c;

  for(size_t i = 0; i < e.size(); i++) {
    Vertex *v0 = e[i]->beg;
    Vertex *v1 = e[i]->end;

    if(!v0 || !v1) {
      Msg::Warning("Skipping GEO curve %d without begin or end point in curve "
                   "loop detection",
                   e[i]->Num);
      continue;
    }

    if(v0 == v1) { // periodic curve
      std::vector<Vertex *> v = {v0, v1};
      vs.push_back(v);
      continue;
    }

    auto it0 = c.find(v0), it1 = c.find(v1);
    if(it0 == c.end())
      c[v0] = std::make_pair(v1, (Vertex *)nullptr);
    else {
      if(it0->second.second == nullptr) { it0->second.second = v1; }
      else {
        Msg::Debug("A list of curves has points that are adjacent to 3 curves");
        return false;
      }
    }
    if(it1 == c.end())
      c[v1] = std::make_pair(v0, (Vertex *)nullptr);
    else {
      if(it1->second.second == nullptr) { it1->second.second = v0; }
      else {
        Msg::Debug("Wrong topology for a list of curves");
        Msg::Debug("Point %d is adjacent to more than 2 points %d %d", v1->Num,
                   it1->second.first->Num, it1->second.second->Num);
        return false;
      }
    }
  }

  while(!c.empty()) {
    std::vector<Vertex *> v;
    Vertex *start = nullptr;
    {
      auto it = c.begin();
      start = it->first;
      for(; it != c.end(); ++it) {
        if(it->second.second == nullptr) {
          start = it->first;
          break;
        }
      }
    }

    auto its = c.find(start);

    Vertex *prev =
      (its->second.second == start) ? its->second.first : its->second.second;
    Vertex *current = start;

    do {
      if(c.size() == 0) {
        Msg::Warning("Wrong topology in a curve loop");
        return false;
      }
      v.push_back(current);
      auto it = c.find(current);
      if(it == c.end() || it->first == nullptr) {
        Msg::Error("Impossible to find point %d", current->Num);
        return false;
      }
      Vertex *v1 = it->second.first;
      Vertex *v2 = it->second.second;
      c.erase(it);
      Vertex *temp = current;
      if(v1 == prev)
        current = v2;
      else if(v2 == prev)
        current = v1;
      else {
        break;
      }
      prev = temp;
      if(current == start) { v.push_back(current); }
    } while(current != start && current != nullptr);
    if(v.size() > 2 && v[v.size() - 2] == v[v.size() - 1]) {
      v.erase(v.begin() + v.size() - 1);
    }
    vs.push_back(v);
  }
  return true;
}

bool GEO_Internals::addCurveLoops(const std::vector<int> &curveTags,
                                  std::vector<int> &curveLoopTags)
{
  curveLoopTags.clear();
  std::vector<Curve *> curves;
  std::multimap<std::pair<Vertex *, Vertex *>, Curve *> pairs;
  for(auto j : curveTags) {
    Curve *c = FindCurve(j);
    if(!c) {
      Msg::Error("Unknown GEO curve %d", j);
      return false;
    }
    if(!c->beg || !c->end) {
      Msg::Error("Cannot create curve loops using curve %d without begin or "
                 "end point",
                 c->Num);
      return false;
    }
    pairs.insert(std::make_pair(std::make_pair(c->beg, c->end), c));
    curves.push_back(c);
  }
  std::vector<std::vector<Vertex *> > vs;
  if(!SortCurvesConsecutive(curves, vs)) {
    Msg::Error("Could not sort curves while creating curve loops");
    return false;
  }

  for(std::size_t i = 0; i < vs.size(); i++) {
    if(vs[i].size() < 2 || vs[i][0] != vs[i][vs[i].size() - 1]) {
      Msg::Warning("Skipping invalid loop with %lu points", vs[i].size());
      continue;
    }
    else {
      List_T *tmp = List_Create(2, 2, sizeof(int));
      for(std::size_t j = 0; j < vs[i].size() - 1; j++) {
        std::pair<Vertex *, Vertex *> p(vs[i][j], vs[i][j + 1]);
        int num = 0;
        auto it = pairs.find(p);
        if(it != pairs.end()) {
          num = it->second->Num;
          pairs.erase(it);
        }
        else {
          std::pair<Vertex *, Vertex *> p2(vs[i][j + 1], vs[i][j]);
          it = pairs.find(p2);
          if(it != pairs.end()) {
            num = -it->second->Num;
            pairs.erase(it);
          }
        }
        if(num) List_Add(tmp, &num);
      }
      int tag = getMaxTag(-1) + 1;
      EdgeLoop *l = CreateEdgeLoop(tag, tmp);
      Tree_Add(EdgeLoops, &l);
      curveLoopTags.push_back(tag);
      List_Delete(tmp);
    }
  }
  _changed = true;
  return curveLoopTags.empty() ? false : true;
}

bool GEO_Internals::addPlaneSurface(int &tag, const std::vector<int> &wireTags)
{
  if(tag >= 0 && FindSurface(tag)) {
    Msg::Error("GEO surface with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  if(wireTags.empty()) {
    Msg::Error("Plane surface requires at least one line loop");
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    int t = wireTags[i];
    List_Add(tmp, &t);
  }
  Surface *s = CreateSurface(tag, MSH_SURF_PLAN);
  bool ok = SetSurfaceGeneratrices(s, tmp);
  List_Delete(tmp);
  EndSurface(s);
  Tree_Add(Surfaces, &s);
  _changed = true;
  return ok;
}

bool GEO_Internals::addDiscreteSurface(int &tag)
{
  if(tag >= 0 && FindSurface(tag)) {
    Msg::Error("GEO surface with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  Surface *s = CreateSurface(tag, MSH_SURF_DISCRETE);
  Tree_Add(Surfaces, &s);
  _changed = true;
  return true;
}

bool GEO_Internals::addSurfaceFilling(int &tag,
                                      const std::vector<int> &wireTags,
                                      int sphereCenterTag)
{
  if(tag >= 0 && FindSurface(tag)) {
    Msg::Error("GEO surface with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  if(wireTags.empty()) {
    Msg::Error("Surface requires at least one line loop");
    return false;
  }
  int ll = (int)std::abs(wireTags[0]);
  EdgeLoop *el = FindEdgeLoop(ll);
  if(!el) {
    Msg::Error("Unknown line loop %d", ll);
    return false;
  }
  int j = List_Nbr(el->Curves), type = MSH_SURF_PLAN;
  if(j == 4)
    type = MSH_SURF_REGL;
  else if(j == 3)
    type = MSH_SURF_TRIC;
  else {
    Msg::Error("Wrong definition of surface %d: %d borders instead of 3 or 4",
               tag, j);
    return false;
  }
  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    int t = wireTags[i];
    List_Add(tmp, &t);
  }
  Surface *s = CreateSurface(tag, type);
  bool ok = SetSurfaceGeneratrices(s, tmp);
  List_Delete(tmp);
  EndSurface(s);
  if(sphereCenterTag >= 0) {
    s->InSphereCenter = FindPoint(sphereCenterTag);
    if(!s->InSphereCenter) {
      Msg::Error("Unknown sphere center point %d", sphereCenterTag);
      ok = false;
    }
  }
  Tree_Add(Surfaces, &s);
  _changed = true;
  return ok;
}

bool GEO_Internals::addSurfaceLoop(int &tag,
                                   const std::vector<int> &surfaceTags)
{
  if(tag >= 0 && FindSurfaceLoop(tag)) {
    Msg::Error("GEO surface loop with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(-2) + 1;

  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < surfaceTags.size(); i++) {
    int t = surfaceTags[i];
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
  if(tag >= 0 && FindVolume(tag)) {
    Msg::Error("GEO volume with tag %d already exists", tag);
    return false;
  }
  if(tag < 0) tag = getMaxTag(3) + 1;

  List_T *tmp = List_Create(2, 2, sizeof(int));
  for(std::size_t i = 0; i < shellTags.size(); i++) {
    int t = shellTags[i];
    List_Add(tmp, &t);
  }
  Volume *v = CreateVolume(tag, MSH_VOLUME);
  bool ok = SetVolumeSurfaces(v, tmp);
  List_Delete(tmp);
  Tree_Add(Volumes, &v);
  _changed = true;
  return ok;
}

bool GEO_Internals::_extrude(int mode,
                             const std::vector<std::pair<int, int> > &inDimTags,
                             double x, double y, double z, double dx, double dy,
                             double dz, double ax, double ay, double az,
                             double angle,
                             std::vector<std::pair<int, int> > &outDimTags,
                             ExtrudeParams *e)
{
  List_T *in = List_Create(inDimTags.size() + 1, 10, sizeof(Shape));
  List_T *out = List_Create(3 * inDimTags.size() + 1, 10, sizeof(Shape));

  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME :
             (dim == 2) ? MSH_SURF_PLAN :
             (dim == 1) ? MSH_SEGM_LINE :
                          MSH_POINT;
    s.Num = tag;
    List_Add(in, &s);
  }

  if(mode == 0) { // extrude
    ExtrudeShapes(TRANSLATE, in, dx, dy, dz, 0., 0., 0., 0., 0., 0., 0., e,
                  out);
  }
  else if(mode == 1) { // revolve
    ExtrudeShapes(ROTATE, in, 0., 0., 0., ax, ay, az, x, y, z, angle, e, out);
  }
  else if(mode == 2) { // extrude+revolve
    ExtrudeShapes(TRANSLATE_ROTATE, in, dx, dy, dz, ax, ay, az, x, y, z, angle,
                  e, out);
  }
  else if(mode == 3) { // boundary layer
    ExtrudeShapes(BOUNDARY_LAYER, in, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., e,
                  out);
  }

  for(int i = 0; i < List_Nbr(out); i++) {
    Shape s;
    List_Read(out, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3)
      outDimTags.push_back(std::pair<int, int>(dim, s.Num));
  }
  List_Delete(in);
  List_Delete(out);
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
                            double x, double y, double z, double ax, double ay,
                            double az, double angle,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(1, inDimTags, x, y, z, 0., 0., 0., ax, ay, az, angle,
                  outDimTags, e);
}

bool GEO_Internals::twist(const std::vector<std::pair<int, int> > &inDimTags,
                          double x, double y, double z, double dx, double dy,
                          double dz, double ax, double ay, double az,
                          double angle,
                          std::vector<std::pair<int, int> > &outDimTags,
                          ExtrudeParams *e)
{
  return _extrude(2, inDimTags, x, y, z, dx, dy, dz, ax, ay, az, angle,
                  outDimTags, e);
}

bool GEO_Internals::boundaryLayer(
  const std::vector<std::pair<int, int> > &inDimTags,
  std::vector<std::pair<int, int> > &outDimTags, ExtrudeParams *e)
{
  return _extrude(3, inDimTags, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
                  outDimTags, e);
}

bool GEO_Internals::_transform(int mode,
                               const std::vector<std::pair<int, int> > &dimTags,
                               double x, double y, double z, double dx,
                               double dy, double dz, double a, double b,
                               double c, double d)
{
  List_T *list = List_Create(dimTags.size() + 1, 10, sizeof(Shape));
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    int dim = dimTags[i].first;
    int tag = dimTags[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME :
             (dim == 2) ? MSH_SURF_PLAN :
             (dim == 1) ? MSH_SEGM_LINE :
                          MSH_POINT;
    s.Num = tag;
    List_Add(list, &s);
  }
  bool ok = true;
  switch(mode) {
  case 0: ok = TranslateShapes(dx, dy, dz, list); break;
  case 1: ok = RotateShapes(dx, dy, dz, x, y, z, a, list); break;
  case 2: ok = DilatShapes(x, y, z, a, b, c, list); break;
  case 3: ok = SymmetryShapes(a, b, c, d, list); break;
  }
  List_Delete(list);
  _changed = true;
  return ok;
}

bool GEO_Internals::translate(const std::vector<std::pair<int, int> > &dimTags,
                              double dx, double dy, double dz)
{
  return _transform(0, dimTags, 0, 0, 0, dx, dy, dz, 0, 0, 0, 0);
}

bool GEO_Internals::rotate(const std::vector<std::pair<int, int> > &dimTags,
                           double x, double y, double z, double ax, double ay,
                           double az, double angle)
{
  return _transform(1, dimTags, x, y, z, ax, ay, az, angle, 0, 0, 0);
}

bool GEO_Internals::dilate(const std::vector<std::pair<int, int> > &dimTags,
                           double x, double y, double z, double a, double b,
                           double c)
{
  return _transform(2, dimTags, x, y, z, 0, 0, 0, a, b, c, 0);
}

bool GEO_Internals::symmetry(const std::vector<std::pair<int, int> > &dimTags,
                             double a, double b, double c, double d)
{
  return _transform(3, dimTags, 0, 0, 0, 0, 0, 0, a, b, c, d);
}

bool GEO_Internals::splitCurve(int tag, const std::vector<int> &pointTags,
                               std::vector<int> &curveTags)
{
  List_T *tmp = List_Create(10, 10, sizeof(int));
  for(std::size_t i = 0; i < pointTags.size(); i++) {
    int t = pointTags[i];
    List_Add(tmp, &t);
  }
  List_T *curves = List_Create(10, 10, sizeof(Curve *));
  bool ok = SplitCurve(tag, tmp, curves);
  for(int i = 0; i < List_Nbr(curves); i++) {
    Curve *c;
    List_Read(curves, i, &c);
    curveTags.push_back(c->Num);
  }
  List_Delete(tmp);
  List_Delete(curves);
  _changed = true;
  return ok;
}

bool GEO_Internals::intersectCurvesWithSurface(
  const std::vector<int> &curveTags, int surfaceTag,
  std::vector<int> &pointTags)
{
  List_T *curves = List_Create(10, 10, sizeof(double));
  List_T *shapes = List_Create(10, 10, sizeof(Shape));
  for(std::size_t i = 0; i < curveTags.size(); i++) {
    double d = curveTags[i];
    List_Add(curves, &d);
  }
  bool ok = IntersectCurvesWithSurface(curves, surfaceTag, shapes);
  for(int i = 0; i < List_Nbr(shapes); i++) {
    Shape s;
    List_Read(shapes, i, &s);
    if(s.Type == MSH_POINT) { pointTags.push_back(s.Num); }
    else {
      Msg::Error("Degenerated curve-surface intersection not implemented");
      return false;
    }
  }
  _changed = true;
  return ok;
}

bool GEO_Internals::copy(const std::vector<std::pair<int, int> > &inDimTags,
                         std::vector<std::pair<int, int> > &outDimTags)
{
  bool ok = true;
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(dim == 0) {
      Vertex *v = FindPoint(tag);
      if(!v) {
        Msg::Error("Unknown GEO point %d", tag);
        ok = false;
      }
      else {
        Vertex *newv = DuplicateVertex(v);
        outDimTags.push_back(std::pair<int, int>(0, newv->Num));
      }
    }
    else if(dim == 1) {
      Curve *c = FindCurve(tag);
      if(!c) {
        Msg::Error("Unknown GEO curve %d", tag);
        ok = false;
      }
      else {
        Curve *newc = DuplicateCurve(c);
        outDimTags.push_back(std::pair<int, int>(1, newc->Num));
      }
    }
    else if(dim == 2) {
      Surface *s = FindSurface(tag);
      if(!s) {
        Msg::Error("Unknown GEO surface %d", tag);
        ok = false;
      }
      else {
        Surface *news = DuplicateSurface(s);
        outDimTags.push_back(std::pair<int, int>(2, news->Num));
      }
    }
    else if(dim == 3) {
      Volume *v = FindVolume(tag);
      if(!v) {
        Msg::Error("Unknown GEO volume %d", tag);
        ok = false;
      }
      else {
        Volume *newv = DuplicateVolume(v);
        outDimTags.push_back(std::pair<int, int>(3, newv->Num));
      }
    }
  }
  _changed = true;
  return ok;
}

bool GEO_Internals::remove(int dim, int tag, bool recursive)
{
  switch(dim) {
  case 0: DeletePoint(tag, recursive); break;
  case 1:
    DeleteCurve(tag, recursive);
    DeleteCurve(-tag, recursive);
    break;
  case 2: DeleteSurface(tag, recursive); break;
  case 3: DeleteVolume(tag, recursive); break;
  }
  _changed = true;
  return true;
}

bool GEO_Internals::remove(const std::vector<std::pair<int, int> > &dimTags,
                           bool recursive)
{
  for(std::size_t i = 0; i < dimTags.size(); i++)
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
  switch(dim) {
  case 0:
    type = MSH_PHYSICAL_POINT;
    str = "point";
    break;
  case 1:
    type = MSH_PHYSICAL_LINE;
    str = "curve";
    break;
  case 2:
    type = MSH_PHYSICAL_SURFACE;
    str = "surface";
    break;
  case 3:
    type = MSH_PHYSICAL_VOLUME;
    str = "volume";
    break;
  default: return false;
  }

  PhysicalGroup *p = FindPhysicalGroup(tag, type);
  if(p && op == 0) {
    Msg::Error("Physical %s %d already exists", str.c_str(), tag);
    return false;
  }
  else if(!p && op > 0) {
    Msg::Error("Physical %s %d does not exist", str.c_str(), tag);
    return false;
  }
  else if(op == 0) {
    List_T *tmp = List_Create(10, 10, sizeof(int));
    for(std::size_t i = 0; i < tags.size(); i++) {
      int t = tags[i];
      List_Add(tmp, &t);
    }
    p = CreatePhysicalGroup(tag, type, tmp);
    List_Delete(tmp);
    List_Add(PhysicalGroups, &p);
  }
  else if(op == 1) {
    for(std::size_t i = 0; i < tags.size(); i++) {
      int t = tags[i];
      List_Add(p->Entities, &t);
    }
  }
  else if(op == 2) {
    for(std::size_t i = 0; i < tags.size(); i++) {
      int t = tags[i];
      List_Suppress(p->Entities, &t, fcmp_int);
    }
    if(!List_Nbr(p->Entities) || tags.empty()) {
      switch(dim) {
      case 0: DeletePhysicalPoint(tag); break;
      case 1: DeletePhysicalLine(tag); break;
      case 2: DeletePhysicalSurface(tag); break;
      case 3: DeletePhysicalVolume(tag); break;
      }
    }
  }
  else {
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
  if(!target) {
    Msg::Error("Unknown GEO point %d", tags[0]);
    return false;
  }

  double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
  for(std::size_t i = 1; i < tags.size(); i++) {
    Vertex *source = FindPoint(tags[i]);
    if(!source) {
      Msg::Error("Unknown GEO point %d", tags[i]);
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
  if(dim != 0) {
    Msg::Error("Setting mesh size only available on GEO points");
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

void GEO_Internals::setTransfiniteLine(int tag, int nPoints, int type,
                                       double coef)
{
  if(!tag) {
    List_T *tmp = Tree2List(Curves);
    for(int i = 0; i < List_Nbr(tmp); i++) {
      Curve *c;
      List_Read(tmp, i, &c);
      c->Method = MESH_TRANSFINITE;
      c->nbPointsTransfinite = (nPoints > 2) ? nPoints : 2;
      c->typeTransfinite = type;
      c->coeffTransfinite = coef;
    }
    List_Delete(tmp);
  }
  else {
    Curve *c = FindCurve(tag);
    if(c) {
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
  if(!tag) {
    List_T *tmp = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(tmp); i++) {
      Surface *s;
      List_Read(tmp, i, &s);
      s->Method = MESH_TRANSFINITE;
      s->Recombine_Dir = arrangement;
      List_Reset(s->TrsfPoints);
    }
    List_Delete(tmp);
  }
  else {
    Surface *s = FindSurface(tag);
    if(s) {
      s->Method = MESH_TRANSFINITE;
      s->Recombine_Dir = arrangement;
      List_Reset(s->TrsfPoints);
      if(cornerTags.empty() || cornerTags.size() == 3 ||
         cornerTags.size() == 4) {
        for(std::size_t j = 0; j < cornerTags.size(); j++) {
          Vertex *v = FindPoint(std::abs(cornerTags[j]));
          if(v)
            List_Add(s->TrsfPoints, &v);
          else
            Msg::Error("Unknown GEO point %d", cornerTags[j]);
        }
      }
      else {
        Msg::Error("Transfinite surface requires 3 or 4 corner points");
      }
    }
  }
  _changed = true;
}

void GEO_Internals::setTransfiniteVolume(int tag,
                                         const std::vector<int> &cornerTags)
{
  if(!tag) {
    List_T *tmp = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(tmp); i++) {
      Volume *v;
      List_Read(tmp, i, &v);
      v->Method = MESH_TRANSFINITE;
      List_Reset(v->TrsfPoints);
    }
    List_Delete(tmp);
  }
  else {
    Volume *v = FindVolume(tag);
    if(v) {
      v->Method = MESH_TRANSFINITE;
      List_Reset(v->TrsfPoints);
      if(cornerTags.empty() || cornerTags.size() == 6 ||
         cornerTags.size() == 8) {
        for(std::size_t i = 0; i < cornerTags.size(); i++) {
          Vertex *vert = FindPoint(std::abs(cornerTags[i]));
          if(vert)
            List_Add(v->TrsfPoints, &vert);
          else
            Msg::Error("Unknown GEO point %d", cornerTags[i]);
        }
      }
    }
  }
  _changed = true;
}

void GEO_Internals::setTransfiniteVolumeQuadTri(int tag)
{
  if(!tag) {
    List_T *tmp = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(tmp); i++) {
      Volume *v;
      List_Read(tmp, i, &v);
      v->QuadTri = TRANSFINITE_QUADTRI_1;
    }
    List_Delete(tmp);
  }
  else {
    Volume *v = FindVolume(tag);
    if(v) v->QuadTri = TRANSFINITE_QUADTRI_1;
  }
  _changed = true;
}

void GEO_Internals::setRecombine(int dim, int tag, double angle)
{
  if(dim == 2) {
    if(!tag) {
      List_T *tmp = Tree2List(Surfaces);
      for(int i = 0; i < List_Nbr(tmp); i++) {
        Surface *s;
        List_Read(tmp, i, &s);
        s->Recombine = 1;
        s->RecombineAngle = angle;
      }
      List_Delete(tmp);
    }
    else {
      Surface *s = FindSurface(tag);
      if(s) {
        s->Recombine = 1;
        s->RecombineAngle = angle;
      }
    }
  }
  else if(dim == 3) {
    if(!tag) {
      List_T *tmp = Tree2List(Volumes);
      for(int i = 0; i < List_Nbr(tmp); i++) {
        Volume *v;
        List_Read(tmp, i, &v);
        v->Recombine3D = 1;
      }
      List_Delete(tmp);
    }
    else {
      Volume *v = FindVolume(tag);
      if(v) { v->Recombine3D = 1; }
    }
  }
  _changed = true;
}

void GEO_Internals::setSmoothing(int tag, int val)
{
  if(!tag) {
    List_T *tmp = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(tmp); i++) {
      Surface *s;
      List_Read(tmp, i, &s);
      s->TransfiniteSmoothing = val;
    }
    List_Delete(tmp);
  }
  else {
    Surface *s = FindSurface(tag);
    if(s) s->TransfiniteSmoothing = val;
  }
  _changed = true;
}

void GEO_Internals::setReverseMesh(int dim, int tag, bool val)
{
  if(dim == 1) {
    if(!tag) {
      List_T *tmp = Tree2List(Curves);
      for(int i = 0; i < List_Nbr(tmp); i++) {
        Curve *c;
        List_Read(tmp, i, &c);
        c->ReverseMesh = val ? 1 : 0;
      }
      List_Delete(tmp);
    }
    else {
      Curve *c = FindCurve(tag);
      if(c) c->ReverseMesh = val ? 1 : 0;
    }
  }
  else if(dim == 2) {
    if(!tag) {
      List_T *tmp = Tree2List(Surfaces);
      for(int i = 0; i < List_Nbr(tmp); i++) {
        Surface *s;
        List_Read(tmp, i, &s);
        s->ReverseMesh = val ? 1 : 0;
      }
      List_Delete(tmp);
    }
    else {
      Surface *s = FindSurface(tag);
      if(s) s->ReverseMesh = val ? 1 : 0;
    }
  }
  _changed = true;
}

void GEO_Internals::setMeshAlgorithm(int dim, int tag, int val)
{
  if(dim == 2) {
    Surface *s = FindSurface(tag);
    if(s) s->MeshAlgorithm = val;
  }
  _changed = true;
}

void GEO_Internals::setMeshSizeFromBoundary(int dim, int tag, int val)
{
  if(dim == 2) {
    Surface *s = FindSurface(tag);
    if(s) s->MeshSizeFromBoundary = val;
  }
  _changed = true;
}

void GEO_Internals::synchronize(GModel *model, bool resetMeshAttributes)
{
  Msg::Debug("Syncing GEO_Internals with GModel");

  // if the entities do not exist in GModel, we create them; if they exist as
  // GEO entities in GModel but don't exist (anymore) in the internal CAD data,
  // we remove them. And if they exist in both the internal CAD data and in the
  // GModel, we update the pointer and the underlying dependencies (e.g. surface
  // boundaries): this is necessary because a GEO entity can change (while
  // keeping the same tag), due e.g. to ReplaceDuplicates.
  //
  // We also remove any entities of type "UnknownModel": these are discrete
  // entities, which are also stored in GEO_Internals so that they can be
  // combined with GEO entities; but they are not GmshModel entities.
  std::vector<std::pair<int, int> > toRemove;
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    GVertex *gv = *it;
    if(gv->getNativeType() == GEntity::GmshModel ||
       gv->getNativeType() == GEntity::UnknownModel) {
      if(!FindPoint(gv->tag()))
        toRemove.push_back(std::pair<int, int>(0, gv->tag()));
    }
  }
  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    GEdge *ge = *it;
    if(ge->getNativeType() == GEntity::GmshModel ||
       ge->getNativeType() == GEntity::UnknownModel) {
      if(!FindCurve(ge->tag()))
        toRemove.push_back(std::pair<int, int>(1, ge->tag()));
    }
  }
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    GFace *gf = *it;
    if(gf->getNativeType() == GEntity::GmshModel ||
       gf->getNativeType() == GEntity::UnknownModel) {
      if(!FindSurface(gf->tag()))
        toRemove.push_back(std::pair<int, int>(2, gf->tag()));
    }
  }
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    GRegion *gr = *it;
    if(gr->getNativeType() == GEntity::GmshModel ||
       gr->getNativeType() == GEntity::UnknownModel) {
      if(!FindVolume(gr->tag()))
        toRemove.push_back(std::pair<int, int>(3, gr->tag()));
    }
  }
  Msg::Debug("Sync is removing %d model entities", toRemove.size());
  model->remove(toRemove);

  if(Tree_Nbr(Points)) {
    List_T *points = Tree2List(Points);
    for(int i = 0; i < List_Nbr(points); i++) {
      Vertex *p;
      List_Read(points, i, &p);
      GVertex *v = model->getVertexByTag(p->Num);
      if(!v) {
        v = new gmshVertex(model, p);
        model->add(v);
      }
      else {
        if(v->getNativeType() == GEntity::GmshModel)
          ((gmshVertex *)v)->resetNativePtr(p);
        if(resetMeshAttributes) v->resetMeshAttributes();
      }
    }
    List_Delete(points);
  }

  if(Tree_Nbr(Curves)) {
    List_T *curves = Tree2List(Curves);
    for(int i = 0; i < List_Nbr(curves); i++) {
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0) {
        GEdge *e = model->getEdgeByTag(c->Num);
        if(!e && c->beg && c->end) {
          e = new gmshEdge(model, c, model->getVertexByTag(c->beg->Num),
                           model->getVertexByTag(c->end->Num));
          model->add(e);
        }
        else if(!e) {
          e = new gmshEdge(model, c, nullptr, nullptr);
          model->add(e);
        }
        else {
          if(e->getNativeType() == GEntity::GmshModel) {
            if(c->beg && c->end)
              ((gmshEdge *)e)
                ->resetNativePtr(c, model->getVertexByTag(c->beg->Num),
                                 model->getVertexByTag(c->end->Num));
            else
              ((gmshEdge *)e)->resetNativePtr(c, nullptr, nullptr);
          }
          if(resetMeshAttributes) e->resetMeshAttributes();
        }
        if(c->degenerated) e->setTooSmall(true);
      }
    }
    List_Delete(curves);
  }

  if(Tree_Nbr(Surfaces)) {
    List_T *surfaces = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++) {
      Surface *s;
      List_Read(surfaces, i, &s);
      GFace *f = model->getFaceByTag(s->Num);
      if(!f) {
        f = new gmshFace(model, s);
        model->add(f);
      }
      else {
        if(f->getNativeType() == GEntity::GmshModel)
          ((gmshFace *)f)->resetNativePtr(s);
        if(resetMeshAttributes) f->resetMeshAttributes();
      }
    }
    List_Delete(surfaces);
  }

  if(Tree_Nbr(Volumes)) {
    List_T *volumes = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++) {
      Volume *v;
      List_Read(volumes, i, &v);
      GRegion *r = model->getRegionByTag(v->Num);
      if(!r) {
        r = new gmshRegion(model, v);
        model->add(r);
      }
      else {
        if(r->getNativeType() == GEntity::GmshModel)
          ((gmshRegion *)r)->resetNativePtr(v);
        if(resetMeshAttributes) r->resetMeshAttributes();
      }
    }
    List_Delete(volumes);
  }

  // delete all physical groups before sync only if there is no mesh (if there
  // is a mesh, it could have been loaded from a file with physical groups - we
  // don't want to remove those)
  if(!model->getNumMeshElements()) model->removePhysicalGroups();
  // we might want to store physical groups directly in GModel; but I guess this
  // is OK for now:
  for(int i = 0; i < List_Nbr(PhysicalGroups); i++) {
    PhysicalGroup *p;
    List_Read(PhysicalGroups, i, &p);
    for(int j = 0; j < List_Nbr(p->Entities); j++) {
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = nullptr;
      int tag = CTX::instance()->geom.orientedPhysicals ? abs(num) : num;
      switch(p->Typ) {
      case MSH_PHYSICAL_POINT: ge = model->getVertexByTag(tag); break;
      case MSH_PHYSICAL_LINE: ge = model->getEdgeByTag(tag); break;
      case MSH_PHYSICAL_SURFACE: ge = model->getFaceByTag(tag); break;
      case MSH_PHYSICAL_VOLUME: ge = model->getRegionByTag(tag); break;
      }
      int pnum = CTX::instance()->geom.orientedPhysicals ?
                   (gmsh_sign(num) * p->Num) :
                   p->Num;
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), pnum) ==
                 ge->physicals.end())
        ge->physicals.push_back(pnum);
    }
  }

  // we might want to store mesh compounds directly in GModel; but this is OK
  // for now.
  for(auto it = _meshCompounds.begin(); it != _meshCompounds.end(); ++it) {
    int dim = it->first;
    std::vector<int> compound = it->second;
    std::vector<GEntity *> ents;
    for(std::size_t i = 0; i < compound.size(); i++) {
      int tag = compound[i];
      GEntity *ent = nullptr;
      switch(dim) {
      case 1: ent = model->getEdgeByTag(tag); break;
      case 2: ent = model->getFaceByTag(tag); break;
      case 3: ent = model->getRegionByTag(tag); break;
      default: Msg::Error("Compound mesh constraint with dimension %d", dim);
      }
      if(ent) ents.push_back(ent);
    }
    for(std::size_t i = 0; i < ents.size(); i++) { ents[i]->compound = ents; }
  }

  // recompute global boundind box in CTX
  SetBoundingBox();

  Msg::Debug("GModel imported:");
  Msg::Debug("%d points", model->getNumVertices());
  Msg::Debug("%d curves", model->getNumEdges());
  Msg::Debug("%d surfaces", model->getNumFaces());
  Msg::Debug("%d volumes", model->getNumRegions());

  _changed = false;
}

bool GEO_Internals::getVertex(int tag, double &x, double &y, double &z)
{
  Vertex *v = FindPoint(tag);
  if(v) {
    x = v->Pos.X;
    y = v->Pos.Y;
    z = v->Pos.Z;
    return true;
  }
  return false;
}

gmshSurface *GEO_Internals::newGeometrySphere(int tag, int centerTag,
                                              int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1) {
    Msg::Error("Unknown sphere center point %d", centerTag);
    return nullptr;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2) {
    Msg::Error("Unknown sphere point %d", pointTag);
    return nullptr;
  }
  return gmshSphere::NewSphere(
    tag, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
    sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
         (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
         (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

gmshSurface *GEO_Internals::newGeometryPolarSphere(int tag, int centerTag,
                                                   int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1) {
    Msg::Error("Unknown polar sphere center point %d", centerTag);
    return nullptr;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2) {
    Msg::Error("Unknown polar sphere point %d", pointTag);
    return nullptr;
  }
  return gmshPolarSphere::NewPolarSphere(
    tag, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
    sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
         (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
         (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

// GModel interface

void GModel::createGEOInternals() { _geo_internals = new GEO_Internals; }

void GModel::deleteGEOInternals()
{
  if(_geo_internals) delete _geo_internals;
  _geo_internals = nullptr;
}

#if defined(HAVE_MESH)

class writeFieldOptionGEO {
private:
  FILE *geo;
  Field *field;

public:
  writeFieldOptionGEO(FILE *fp, Field *_field)
  {
    geo = fp ? fp : stdout;
    field = _field;
  }
  void operator()(std::pair<std::string, FieldOption *> it)
  {
    std::string v;
    it.second->getTextRepresentation(v);
    fprintf(geo, "Field[%i].%s = %s;\n", field->id, it.first.c_str(),
            v.c_str());
  }
};

class writeFieldGEO {
private:
  FILE *geo;

public:
  writeFieldGEO(FILE *fp) { geo = fp ? fp : stdout; }
  void operator()(std::pair<const int, Field *> it)
  {
    fprintf(geo, "Field[%i] = %s;\n", it.first, it.second->getName());
    std::for_each(it.second->options.begin(), it.second->options.end(),
                  writeFieldOptionGEO(geo, it.second));
  }
};

#endif

class writePhysicalGroupGEO {
private:
  FILE *geo;
  int dim;
  bool printLabels;
  std::map<int, std::string> &oldLabels;
  std::map<std::pair<int, int>, std::string> &newLabels;

public:
  writePhysicalGroupGEO(FILE *fp, int i, bool labels,
                        std::map<int, std::string> &o,
                        std::map<std::pair<int, int>, std::string> &n)
    : dim(i), printLabels(labels), oldLabels(o), newLabels(n)
  {
    geo = fp ? fp : stdout;
  }
  void operator()(std::pair<const int, std::vector<GEntity *> > &g)
  {
    std::string oldName, newName;
    if(printLabels) {
      if(newLabels.count(std::pair<int, int>(dim, g.first))) {
        newName = newLabels[std::pair<int, int>(dim, g.first)];
      }
      else if(oldLabels.count(g.first)) {
        oldName = oldLabels[g.first];
        fprintf(geo, "%s = %d;\n", oldName.c_str(), g.first);
      }
    }

    switch(dim) {
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
    for(std::size_t i = 0; i < g.second.size(); i++) {
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
  std::list<GRegion *> regions(gf->regions());
  for(auto itr = regions.begin(); itr != regions.end(); itr++) {
    if(!skipRegion(*itr)) return false;
  }
  return true;
}

static bool skipEdge(GEdge *ge)
{
  if(ge->physicals.size()) return false;
  std::vector<GFace *> faces(ge->faces());
  for(auto itf = faces.begin(); itf != faces.end(); itf++) {
    if(!skipFace(*itf)) return false;
  }
  return true;
}

static bool skipVertex(GVertex *gv)
{
  if(gv->physicals.size()) return false;
  std::vector<GEdge *> const &edges = gv->edges();
  for(auto ite = edges.begin(); ite != edges.end(); ite++) {
    if(!skipEdge(*ite)) return false;
  }
  return true;
}

int GModel::writeGEO(const std::string &name, bool printLabels,
                     bool onlyPhysicals)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Could not open file '%s'", name.c_str());
    return 0;
  }

  std::map<double, std::string> meshSizeParameters;
  int cpt = 0;
  for(auto it = firstVertex(); it != lastVertex(); it++) {
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(meshSizeParameters.find(val) == meshSizeParameters.end()) {
      std::ostringstream paramName;
      paramName << "cl__" << ++cpt;
      fprintf(fp, "%s = %.16g;\n", paramName.str().c_str(), val);
      meshSizeParameters.insert(std::make_pair(val, paramName.str()));
    }
  }

  for(auto it = firstVertex(); it != lastVertex(); it++) {
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(!onlyPhysicals || !skipVertex(*it))
      (*it)->writeGEO(fp, meshSizeParameters[val]);
  }
  for(auto it = firstEdge(); it != lastEdge(); it++) {
    if(!onlyPhysicals || !skipEdge(*it)) (*it)->writeGEO(fp);
  }
  for(auto it = firstFace(); it != lastFace(); it++) {
    if(!onlyPhysicals || !skipFace(*it)) (*it)->writeGEO(fp);
  }
  for(auto it = firstRegion(); it != lastRegion(); it++) {
    if(!onlyPhysicals || !skipRegion(*it)) (*it)->writeGEO(fp);
  }

  std::map<int, std::string> labels;
#if defined(HAVE_PARSER)
  // get "old-style" labels from parser
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); ++it)
    for(std::size_t i = 0; i < it->second.value.size(); i++)
      labels[(int)it->second.value[i]] = it->first;
#endif

  std::map<int, std::vector<GEntity *> > groups[4];
  getPhysicalGroups(groups);
  for(int i = 0; i < 4; i++)
    std::for_each(
      groups[i].begin(), groups[i].end(),
      writePhysicalGroupGEO(fp, i, printLabels, labels, _physicalNames));

#if defined(HAVE_MESH)
  std::for_each(getFields()->begin(), getFields()->end(), writeFieldGEO(fp));
  if(getFields()->getBackgroundField() > 0)
    fprintf(fp, "Background Field = %i;\n", getFields()->getBackgroundField());
#endif

  fclose(fp);
  return 1;
}

int GModel::exportDiscreteGEOInternals()
{
  if(_geo_internals) delete _geo_internals;
  _geo_internals = new GEO_Internals;

  for(auto it = firstVertex(); it != lastVertex(); it++) {
    Vertex *v = CreateVertex((*it)->tag(), (*it)->x(), (*it)->y(), (*it)->z(),
                             (*it)->prescribedMeshSizeAtVertex(), 1.0);
    Tree_Add(_geo_internals->Points, &v);
  }

  for(auto it = firstEdge(); it != lastEdge(); it++) {
    if((*it)->geomType() == GEntity::DiscreteCurve) {
      bool ok = true;
      Curve *c = CreateCurve((*it)->tag(), MSH_SEGM_DISCRETE, 1, nullptr,
                             nullptr, -1, -1, 0., 1., ok);
      c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
      GVertex *gvb = (*it)->getBeginVertex();
      if(gvb) {
        Vertex *v = FindPoint(gvb->tag());
        if(v) {
          List_Add(c->Control_Points, &v);
          c->beg = v;
        }
        else {
          Msg::Error("Unknown GEO point %d", gvb->tag());
        }
      }
      else {
        Msg::Warning("Discrete curve %d has no begin point", (*it)->tag());
      }
      GVertex *gve = (*it)->getEndVertex();
      if(gve) {
        Vertex *v = FindPoint(gve->tag());
        if(v) {
          List_Add(c->Control_Points, &v);
          c->end = v;
        }
        else {
          Msg::Error("Unknown GEO point %d", gve->tag());
        }
      }
      else {
        Msg::Warning("Discrete curve %d has no end point", (*it)->tag());
      }
      EndCurve(c);
      Tree_Add(_geo_internals->Curves, &c);
      CreateReversedCurve(c);
    }
  }

  for(auto it = firstFace(); it != lastFace(); it++) {
    if((*it)->geomType() == GEntity::DiscreteSurface) {
      Surface *s = CreateSurface((*it)->tag(), MSH_SURF_DISCRETE);
      std::vector<GEdge *> const &edges = (*it)->edges();
      s->Generatrices = List_Create(edges.size() + 1, 1, sizeof(Curve *));
      for(auto ite = edges.begin(); ite != edges.end(); ite++) {
        Curve *c = FindCurve((*ite)->tag());
        if(c) { List_Add(s->Generatrices, &c); }
        else {
          Msg::Error("Unknown GEO curve %d", (*ite)->tag());
        }
      }
      EndSurface(s);
      Tree_Add(_geo_internals->Surfaces, &s);
    }
  }

  for(auto it = firstRegion(); it != lastRegion(); it++) {
    if((*it)->geomType() == GEntity::DiscreteVolume) {
      Volume *v = CreateVolume((*it)->tag(), MSH_VOLUME_DISCRETE);
      std::vector<GFace *> faces = (*it)->faces();
      v->Surfaces = List_Create(faces.size() + 1, 1, sizeof(Surface *));
      for(auto itf = faces.begin(); itf != faces.end(); itf++) {
        Surface *s = FindSurface((*itf)->tag());
        if(s) { List_Add(v->Surfaces, &s); }
        else {
          Msg::Error("Unknown GEO surface %d", (*itf)->tag());
        }
      }
      Tree_Add(_geo_internals->Volumes, &v);
    }
  }

  Msg::Debug("Geo internal model has:");
  Msg::Debug("%d points", Tree_Nbr(_geo_internals->Points));
  Msg::Debug("%d curves", Tree_Nbr(_geo_internals->Curves));
  Msg::Debug("%d surfaces", Tree_Nbr(_geo_internals->Surfaces));
  Msg::Debug("%d volumes", Tree_Nbr(_geo_internals->Volumes));

  return 1;
}
