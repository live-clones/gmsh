// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
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
              "along (%g, %g, %g)", _region->tag(), _sourceFace->tag(),
              _direction.x(), _direction.y(), _direction.z());
  }

  bool fillExtrudeParams(const std::vector<int> &numElements,
                         const std::vector<double> &heights,
                         const bool recombine,
                         bool checkOnly)
  {
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

    // top curves
    {
      std::vector<GEdge *> sourceEdges = _sourceFace->edges();
      std::vector<GEdge *> targetEdges = _targetFace->edges();
      if(sourceEdges.size() != targetEdges.size()) {
        Msg::Error("Incompatible number of curves in surfaces %d and %d",
                   _sourceFace->tag(), _targetFace->tag());
        return false;
      }
      for(std::size_t i = 0; i < targetEdges.size(); i++) {
        ExtrudeParams *ep = new ExtrudeParams(COPIED_ENTITY);
        _fillExtrudeParams(ep, sourceEdges[i]->tag(), numElements, heights, recombine);
        if(targetEdges[i]->meshAttributes.extrude) {
          if(!_isCompatible(targetEdges[i]->meshAttributes.extrude, ep)) {
            Msg::Warning("Incompatible extrusion parameters on curve %d",
                         targetEdges[i]->tag());
            delete ep;
            return false;
          }
        }
        if(checkOnly)
          delete ep;
        else
          targetEdges[i]->meshAttributes.extrude = ep;
      }
    }

    // lateral surfaces
    std::vector<GFace *> regionFaces = _region->faces();
    for(auto e : _sourceFace->edges()) {
      std::vector<GFace*> edgeFaces = e->faces();
      for(auto f : regionFaces) {
        if(f == _sourceFace || f == _targetFace) continue;
        if(std::find(edgeFaces.begin(), edgeFaces.end(), f) != edgeFaces.end()) {
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
        }
      }
    }

    // lateral curves
    std::vector<GEdge *> regionEdges = _region->edges();
    std::vector<GEdge *> sourceEdges = _sourceFace->edges();
    std::vector<GEdge *> targetEdges = _targetFace->edges();
    for(auto v : _sourceFace->vertices()) {
      std::vector<GEdge*> vertexEdges = v->edges();
      for(auto e : regionEdges) {
        if(std::find(sourceEdges.begin(), sourceEdges.end(), e) !=
           sourceEdges.end()) continue;
        if(std::find(targetEdges.begin(), targetEdges.end(), e) !=
           targetEdges.end()) continue;
        if(std::find(vertexEdges.begin(), vertexEdges.end(), e) !=
           vertexEdges.end()) {
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
    for(auto f2 : f) {
      // for each pair of surfaces...
      if(f1 == f2) continue;
      std::vector<GVertex *> v1 = f1->vertices(), v2 = f2->vertices();
      std::vector<GEdge *> e1 = f1->edges(), e2 = f2->edges();
      if((v1.size() != v2.size()) || (e1.size() != e2.size())) continue;
      SVector3 d0(0., 0., 0.);
      bool ok = true;
      for(auto e : gr->edges()) {
        if(std::find(e1.begin(), e1.end(), e) == e1.end() &&
           std::find(e2.begin(), e2.end(), e) == e2.end()) {
          // ... check that all curves not on the boundary of the 2 surfaces are
          // straight lines with the same translation vector
          if(e->geomType() == GEntity::Line) {
            GVertex *vs = e->getBeginVertex(), *vt = e->getEndVertex();
            if(vs && vt) {
              SVector3 d;
              if(std::find(v1.begin(), v1.end(), vs) != v1.end() &&
                 std::find(v2.begin(), v2.end(), vt) != v2.end()) {
                d = SVector3(vs->xyz(), vt->xyz());
              }
              else {
                ok = false;
                break;
              }
              if(d0.norm() == 0.) d0 = d;
              if(!sameDir(d0, d)) {
                ok = false;
                break;
              }
            }
          }
        }
      }
      if(ok && d0.norm() != 0.) {
        // we have a candidate pair...
        info.push_back(extrudeInfo(gr, f1, f2, d0));
        // ... increase the popularity of the potential extrusion direction
        bool found = false;
        for(std::size_t i = 0; i < count.size(); i++) {
          if(sameDir(count[i].first, d0)) {
            count[i].second++;
            found = true;
            break;
          }
        }
        if(!found) count.push_back(std::make_pair(d0, 1));
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
