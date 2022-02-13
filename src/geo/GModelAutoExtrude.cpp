// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshMessage.h"
#include "GModel.h"
#include "Context.h"
#include "ExtrudeParams.h"

bool sameDir(const SVector3 &v1, const SVector3 &v2)
{
  const double tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;
  if(std::abs(v1.x() - v2.x()) < tol &&
     std::abs(v1.y() - v2.y()) < tol &&
     std::abs(v1.z() - v2.z()) < tol) return true;
  return false;
}

bool sortDirCount(const std::pair<SVector3, int> &a,
                  const std::pair<SVector3, int> &b)
{
  return (a.second > b.second);
}

class extrudeInfo {
private:
  GRegion *_region;
  GFace *_sourceFace, *_targetFace;
  SVector3 _direction;
public:
  extrudeInfo(GRegion *r, GFace *s, GFace *t, SVector3 d)
    : _region(r), _sourceFace(s), _targetFace(t), _direction(d)
  {}
  SVector3 getDirection() { return _direction; }
  void print()
  {
    Msg::Info("Volume %d compatible surface pair (%d, %d) extrusion %g %g %g",
              _region->tag(), _sourceFace->tag(), _targetFace->tag(),
              _direction.x(), _direction.y(), _direction.z());
  }
  bool fill()
  {
    // get lateralEdges and lateralFaces
    std::vector<GEdge *> lateralEdges;
    std::vector<GFace *> lateralFaces;
    // add ExtrudeParam in region, targetSurface and lateral entities
    return true;
  }
};

void getCandidateExtrudeInfo(GRegion *gr, std::vector<extrudeInfo> &info,
                             std::vector<std::pair<SVector3, int>> &count)
{
  std::vector<GFace*> f = gr->faces();
  for(auto f1 : f) {
    for(auto f2 : f) {
      if(f1 == f2) continue;
      // for each pair of surfaces...
      std::vector<GVertex *> v1 = f1->vertices(), v2 = f2->vertices();
      std::vector<GEdge *> e1 = f1->edges(), e2 = f2->edges();
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
              else if(std::find(v1.begin(), v1.end(), vt) != v1.end() &&
                      std::find(v2.begin(), v2.end(), vs) != v2.end()) {
                d = SVector3(vt->xyz(), vs->xyz());
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
                                              const bool recombine)
{
  // get pairs of surfaces that could be candidates for extrusion by translation
  std::vector<extrudeInfo> candidates;
  std::vector<std::pair<SVector3, int>> dirCount;
  for(auto r : regions) getCandidateExtrudeInfo(r, candidates, dirCount);

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
    if(m.fill()) m.print();
  }

  return true;
}
