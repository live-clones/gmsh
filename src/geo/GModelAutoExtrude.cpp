// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshMessage.h"
#include "GModel.h"
#include "Context.h"
#include "ExtrudeParams.h"

static bool sameDir(const SVector3 &v1, const SVector3 &v2)
{
  const double tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;
  if(std::abs(v1.x() - v2.x()) < tol &&
     std::abs(v1.y() - v2.y()) < tol &&
     std::abs(v1.z() - v2.z()) < tol) return true;
  return false;
}

static bool sortDirCount(const std::pair<SVector3, int> &a,
                         const std::pair<SVector3, int> &b)
{
  return (a.second > b.second);
}

class extrudeInfo {
private:
  GRegion *_region;
  GFace *_sourceFace, *_targetFace;
  SVector3 _direction;
  void _fillExtrudeParams(ExtrudeParams *ep, int sourceTag,
                          const std::vector<int> &numElements,
                          const std::vector<double> &heights,
                          const bool recombine)
  {
    ep->fill(TRANSLATE, _direction.x(), _direction.y(), _direction.z(),
             0, 0, 0, 0, 0, 0, 0);
    ep->geo.Source = sourceTag;
    if(numElements.size()) {
      ep->mesh.ExtrudeMesh = true;
      ep->mesh.NbElmLayer = numElements;
      ep->mesh.hLayer = heights;
      if(ep->mesh.hLayer.empty()) {
        ep->mesh.NbLayer = numElements.size();
        for(int i = 0; i < ep->mesh.NbLayer; i++) {
          ep->mesh.hLayer.push_back((i + 1.) / ep->mesh.NbLayer);
        }
      }
      else {
        ep->mesh.NbLayer = heights.size();
      }
      ep->mesh.Recombine = recombine;
    }
  }
  bool _isCompatible(ExtrudeParams *ep1, ExtrudeParams *ep2)
  {
    if(ep1->geo.Mode != ep2->geo.Mode) return false;
    if(ep1->geo.Type != ep2->geo.Type) return false;
    if(ep1->geo.Source != ep2->geo.Source) return false;
    for(int i = 0; i < 3; i++) {
      if(ep1->geo.trans[i] != ep2->geo.trans[i]) return false;
    }
    if(ep1->mesh.ExtrudeMesh && ep2->mesh.ExtrudeMesh) {
      if(ep1->mesh.NbElmLayer != ep2->mesh.NbElmLayer) return false;
      if(ep1->mesh.hLayer != ep2->mesh.hLayer) return false;
      if(ep1->mesh.NbLayer != ep2->mesh.NbLayer) return false;
    }
    return true;
  }

public:
  extrudeInfo(GRegion *r, GFace *s, GFace *t, SVector3 d)
    : _region(r), _sourceFace(s), _targetFace(t), _direction(d)
  {}
  SVector3 getDirection() { return _direction; }
  void print()
  {
    Msg::Info("Volume %d reverse-engineered as extruded from surface %d "
              "to surface %d along (%g, %g, %g)", _region->tag(),
              _sourceFace->tag(), _targetFace->tag(), _direction.x(),
              _direction.y(), _direction.z());
  }

  bool fillExtrudeParams(const std::vector<int> &numElements,
                         const std::vector<double> &heights,
                         const bool recombine,
                         bool checkOnly)
  {
    auto se = _sourceFace->edges();
    std::set<GEdge *, GEntityPtrLessThan> sourceEdges(se.begin(), se.end());
    auto te = _targetFace->edges();
    std::set<GEdge *, GEntityPtrLessThan> targetEdges(te.begin(), te.end());

    // volume
    {
      ExtrudeParams *ep = new ExtrudeParams(EXTRUDED_ENTITY);
      _fillExtrudeParams(ep, _sourceFace->tag(), numElements, heights, recombine);
      if(_region->meshAttributes.extrude) {
        if(!_isCompatible(_region->meshAttributes.extrude, ep)) {
          Msg::Warning("Incompatible extrusion parameters on volume %d",
                       _region->tag());
          delete ep;
          return false;
        }
      }
      if(checkOnly)
        delete ep;
      else
        _region->meshAttributes.extrude = ep;
    }

    // top surface
    {
      ExtrudeParams *ep = new ExtrudeParams(COPIED_ENTITY);
      _fillExtrudeParams(ep, _sourceFace->tag(), numElements, heights, recombine);
      if(_targetFace->meshAttributes.extrude) {
        if(!_isCompatible(_targetFace->meshAttributes.extrude, ep)) {
          Msg::Warning("Incompatible extrusion parameters on surface %d",
                       _targetFace->tag());
          delete ep;
          return false;
        }
      }
      if(checkOnly)
        delete ep;
      else
        _targetFace->meshAttributes.extrude = ep;
    }

    // lateral surfaces and top curves
    std::vector<GFace *> regionFaces = _region->faces();
    for(auto e : _sourceFace->edges()) {
      auto f = e->faces();
      std::set<GFace *, GEntityPtrLessThan> edgeFaces(f.begin(), f.end());
      for(auto f : regionFaces) {
        if(f == _sourceFace || f == _targetFace) continue;
        if(edgeFaces.find(f) != edgeFaces.end()) {
          // lateral surface
          ExtrudeParams *ep = new ExtrudeParams(EXTRUDED_ENTITY);
          _fillExtrudeParams(ep, e->tag(), numElements, heights, recombine);
          if(f->meshAttributes.extrude) {
            if(!_isCompatible(f->meshAttributes.extrude, ep)) {
              Msg::Warning("Incompatible extrusion parameters on surface %d",
                           f->tag());
              delete ep;
              return false;
            }
          }
          if(checkOnly)
            delete ep;
          else
            f->meshAttributes.extrude = ep;
          // top curve
          for(auto fe : f->edges()) {
            if(targetEdges.find(fe) != targetEdges.end()) {
              ExtrudeParams *ep = new ExtrudeParams(COPIED_ENTITY);
              _fillExtrudeParams(ep, e->tag(), numElements, heights, recombine);
              if(fe->meshAttributes.extrude) {
                if(!_isCompatible(fe->meshAttributes.extrude, ep)) {
                  Msg::Warning("Incompatible extrusion parameters on curve %d",
                               fe->tag());
                  delete ep;
                  return false;
                }
              }
              if(checkOnly)
                delete ep;
              else
                fe->meshAttributes.extrude = ep;
            }
          }
        }
      }
    }

    // lateral curves
    std::vector<GEdge *> regionEdges = _region->edges();
    for(auto v : _sourceFace->vertices()) {
      auto ve = v->edges();
      std::set<GEdge*, GEntityPtrLessThan> vertexEdges(ve.begin(), ve.end());
      for(auto e : regionEdges) {
        if(sourceEdges.find(e) != sourceEdges.end()) continue;
        if(targetEdges.find(e) != targetEdges.end()) continue;
        if(vertexEdges.find(e) != vertexEdges.end()) {
          ExtrudeParams *ep = new ExtrudeParams(EXTRUDED_ENTITY);
          _fillExtrudeParams(ep, v->tag(), numElements, heights, recombine);
          if(e->meshAttributes.extrude) {
            if(!_isCompatible(e->meshAttributes.extrude, ep)) {
              Msg::Warning("Incompatible extrusion parameters on curve %d",
                           e->tag());
              delete ep;
              return false;
            }
          }
          if(checkOnly)
            delete ep;
          else
            e->meshAttributes.extrude = ep;
        }
      }
    }

    return true;
  }
};

void getCandidateExtrudeInfo(GRegion *gr, std::vector<extrudeInfo> &info,
                             std::vector<std::pair<SVector3, int>> &count)
{
  std::vector<GFace*> f = gr->faces();
  for(auto f1 : f) {
    auto f1v = f1->vertices();
    auto f1e = f1->edges();
    std::set<GVertex *, GEntityPtrLessThan> v1(f1v.begin(), f1v.end());
    std::set<GEdge *, GEntityPtrLessThan> e1(f1e.begin(), f1e.end());
    for(auto f2 : f) {
      // for each pair of surfaces
      if(f1 == f2) continue;

      Msg::Debug("Testing surface pair %d - %d:", f1->tag(), f2->tag());
      auto f2v = f2->vertices();
      auto f2e = f2->edges();
      std::set<GVertex *, GEntityPtrLessThan> v2(f2v.begin(), f2v.end());
      std::set<GEdge *, GEntityPtrLessThan> e2(f2e.begin(), f2e.end());
      // abort if different topology
      if((v1.size() != v2.size()) || (e1.size() != e2.size())) {
        Msg::Debug(" - incompatible surfaces %d (#points=%lu, #curves=%lu) - "
                   "%d (#points=%lu, #curves=%lu)",
                   f1->tag(), v1.size(), e1.size(),
                   f2->tag(), v2.size(), e2.size());
        continue;
      }

      SVector3 t0(0., 0., 0.);
      bool translated = true;

      std::set<GEdge*> perp;
      for(auto e : gr->edges()) {
        // skip curves that are on the boundary of the 2 surfaces
        if(e1.find(e) != e1.end() || e2.find(e) != e2.end()) {
          continue;
        }
        if((v1.find(e->getBeginVertex()) != v1.end() ||
            v1.find(e->getEndVertex()) != v1.end()) &&
           (v2.find(e->getBeginVertex()) != v2.end() ||
            v2.find(e->getEndVertex()) != v2.end())) {
          perp.insert(e);
        }
      }

      if(perp.size() != v1.size()) {
        Msg::Debug(" - number of extruded curves differs from number of "
                   "source/target surface points (%lu != %lu)",
                   perp.size(), v1.size());
        continue;
      }

      if(perp.size() + e1.size() + e2.size() != gr->edges().size()) {
        Msg::Debug(" - extra curves not connected to source/target surfaces");
        continue;
      }

      for(auto e : perp) {
        // straight lines with the same translation vector?
        if(e->geomType() == GEntity::Line) {
          GVertex *vs = e->getBeginVertex(), *vt = e->getEndVertex();
          if(vs && vt) {
            SVector3 t;
            if(v1.find(vs) != v1.end() && v2.find(vt) != v2.end()) {
              t = SVector3(vs->xyz(), vt->xyz());
            }
            else if(v1.find(vt) != v1.end() && v2.find(vs) != v2.end()) {
              t = SVector3(vt->xyz(), vs->xyz());
            }
            else {
              // should not happen
              translated = false;
              break;
            }
            if(t0.norm() == 0.) t0 = t;
            if(!sameDir(t0, t)) {
              Msg::Debug(" - straight line t=(%g, %g, %g) != t0=(%g, %g, %g)",
                         t.x(), t.y(), t.z(), t0.x(), t0.y(), t0.z());
              translated = false;
              break;
            }
          }
        }
        else {
          // TODO: could check here if all curves are circles to detect
          // extrusions by rotation
          translated = false;
          break;
        }
      }
      if(translated && t0.norm() != 0.) {
        for(auto v : v1) {
          // common point is impossible, abort
          if(v2.find(v) != v2.end()) continue;
        }
        // we have a candidate pair for extrusion by translation
        Msg::Debug("Volume %d possible extrusion candidate from surface %d to "
                   "surface %d along (%g, %g, %g)", gr->tag(), f1->tag(), f2->tag(),
                   t0.x(), t0.y(), t0.z());
        info.push_back(extrudeInfo(gr, f1, f2, t0));
        // ... increase the popularity of the potential extrusion direction
        bool found = false;
        for(std::size_t i = 0; i < count.size(); i++) {
          if(sameDir(count[i].first, t0)) {
            count[i].second++;
            found = true;
            break;
          }
        }
        if(!found) count.push_back(std::make_pair(t0, 1));
      }
    }
  }
}

bool GModel::addAutomaticExtrusionConstraints(const std::vector<int> &numElements,
                                              const std::vector<double> &heights,
                                              const bool recombine,
                                              const std::vector<int> &regionTags)
{
  std::vector<GRegion *> regs;
  if(regionTags.empty()) {
    regs.insert(regs.end(), regions.begin(), regions.end());
  }
  else {
    for(auto t : regionTags) {
      GRegion *r = getRegionByTag(t);
      if(r) regs.push_back(r);
      else Msg::Error("Unknown volume %d for automatic extrusion constraints");
    }
  }

  // get pairs of surfaces that could be candidates for extrusion by translation
  std::vector<extrudeInfo> candidates;
  std::vector<std::pair<SVector3, int>> dirCount;
  for(auto r : regs) getCandidateExtrudeInfo(r, candidates, dirCount);

  if(candidates.empty()) {
    Msg::Info("No candidates found for automatic extrusion constraints");
    return false;
  }

  // sort the extrusion directions by popularity
  std::sort(dirCount.begin(), dirCount.end(), sortDirCount);

  // keep candidates corresponding to the most popular extrusion direction
  std::vector<extrudeInfo> matches;
  for(auto c : candidates) {
    if(sameDir(c.getDirection(), dirCount.front().first)) matches.push_back(c);
  }

  // compute extrude information
  for(auto m : matches) {
    if(m.fillExtrudeParams(numElements, heights, recombine, true)) {
      m.fillExtrudeParams(numElements, heights, recombine, false);
      m.print();
    }
  }

  return true;
}
