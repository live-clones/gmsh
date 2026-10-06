// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoFace.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "GPoint.h"
#include "GmshMessage.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "boundaryLayersData.h"
#include "meshGFace.h"
#include <unordered_map>

namespace QuadOpt {

  bool FaceMesh::skip(const char *why) const
  {
    Msg::Warning("QuadOpt: face %d left unchanged: %s", _gf->tag(), why);
    return false;
  }

  bool FaceMesh::build()
  {
    std::vector<MElement *> elements(_gf->triangles.begin(),
                                     _gf->triangles.end());
    elements.insert(elements.end(), _gf->quadrangles.begin(),
                    _gf->quadrangles.end());
    std::unordered_map<MVertex *, int> id;
    std::vector<Cell> cells;
    for(MElement *e : elements) {
      if(e->getPolynomialOrder() != 1) return skip("high-order elements");
      Cell cell;
      cell.n = e->getNumVertices();
      for(int i = 0; i < cell.n; ++i) {
        MVertex *mv = e->getVertex(i);
        auto it = id.find(mv);
        if(it == id.end()) {
          it = id.emplace(mv, _he.addVertex()).first;
          Vert vert;
          vert.mv = mv;
          vert.p = SVector3(mv->x(), mv->y(), mv->z());
          vert.fixed = mv->onWhat() != _gf;
          vert.hasUV = !vert.fixed && mv->getParameter(0, vert.uv[0]) &&
                       mv->getParameter(1, vert.uv[1]);
          _v.push_back(vert);
        }
        cell.v[i] = it->second;
      }
      cells.push_back(cell);
    }
    if(!orient(cells)) return skip("not orientable or non-manifold");
    for(const Cell &c : cells)
      if(_he.add(c) < 0) return skip("overlapping cells");
    // Every curve of the face is kept, also a seam with a triangle on each side.
    std::set<GEdge *> curves(_gf->edges().begin(), _gf->edges().end());
    curves.insert(_gf->embeddedEdges().begin(), _gf->embeddedEdges().end());
    for(GEdge *ge : curves)
      for(MLine *l : ge->lines) {
        auto a = id.find(l->getVertex(0)), b = id.find(l->getVertex(1));
        if(a != id.end() && b != id.end())
          _protected.insert(edgeKey(a->second, b->second));
      }
    return true;
  }

  // Orient every connected component coherently (neighbors traverse their
  // shared edge in opposite directions), then along the CAD normal. False if the
  // face is not orientable or has a non-manifold edge.
  bool FaceMesh::orient(std::vector<Cell> &cells)
  {
    const int count = int(cells.size());
    std::unordered_map<std::uint64_t, std::vector<int> > byEdge;
    for(int k = 0; k < count; ++k)
      for(int i = 0; i < cells[k].n; ++i)
        byEdge[edgeKey(cells[k].v[i], cells[k].v[(i + 1) % cells[k].n])]
          .push_back(k);
    for(const auto &entry : byEdge)
      if(entry.second.size() > 2) return false;
    auto traverses = [&](int k, int a, int b) { // input orientation: a -> b ?
      const Cell &c = cells[k];
      for(int i = 0; i < c.n; ++i)
        if(c.v[i] == a && c.v[(i + 1) % c.n] == b) return true;
      return false;
    };

    std::vector<char> flipped(count, 0), seen(count, 0);
    for(int root = 0; root < count; ++root) {
      if(seen[root]) continue;
      std::vector<int> component = {root};
      seen[root] = 1;
      for(std::size_t h = 0; h < component.size(); ++h) {
        const int k = component[h];
        for(int i = 0; i < cells[k].n; ++i) {
          const int a = cells[k].v[i], b = cells[k].v[(i + 1) % cells[k].n];
          for(int j : byEdge[edgeKey(a, b)]) {
            if(j == k) continue;
            const bool wanted = traverses(j, a, b) == !flipped[k];
            if(!seen[j]) {
              seen[j] = 1;
              flipped[j] = wanted;
              component.push_back(j);
            }
            else if(bool(flipped[j]) != wanted)
              return false; // not orientable
          }
        }
      }
      // Along the CAD normal, on a sample of the component.
      int vote = 0;
      const std::size_t stride = std::max<std::size_t>(1, component.size() / 200);
      for(std::size_t h = 0; h < component.size(); h += stride) {
        const Cell &c = cells[component[h]];
        if(!ensureUV(c.v[0])) continue;
        Corners p = pointsOf(c);
        if(flipped[component[h]]) std::reverse(p.begin(), p.end());
        const double d = dot(
          meanNormal(p.data(), c.n),
          _gf->normal(SPoint2(_v[c.v[0]].uv[0], _v[c.v[0]].uv[1])));
        vote += d > 0. ? 1 : (d < 0. ? -1 : 0);
      }
      if(vote < 0)
        for(int k : component) flipped[k] = !flipped[k];
    }
    for(int k = 0; k < count; ++k)
      if(flipped[k])
        std::reverse(cells[k].v.begin(), cells[k].v.begin() + cells[k].n);
    return true;
  }

  // Write the complex back to the face.
  void FaceMesh::sync()
  {
    for(Vert &v : _v) {
      if(v.fixed) continue;
      if(!v.mv) {
        v.mv = new MFaceVertex(v.p.x(), v.p.y(), v.p.z(), _gf, v.uv[0], v.uv[1]);
        _gf->mesh_vertices.push_back(v.mv);
      }
      else {
        v.mv->setXYZ(v.p.x(), v.p.y(), v.p.z());
        v.mv->setParameter(0, v.uv[0]);
        v.mv->setParameter(1, v.uv[1]);
      }
    }
    for(MTriangle *t : _gf->triangles) delete t;
    for(MQuadrangle *q : _gf->quadrangles) delete q;
    _gf->triangles.clear();
    _gf->quadrangles.clear();
    // Gmsh orients a face from its first element only (orientMeshGFace): list
    // the best-shaped triangle and quad first, so that a nearly flat first
    // element cannot reverse the whole face.
    int best[5] = {-1, -1, -1, -1, -1};
    double bestQuality[5] = {-2., -2., -2., -2., -2.};
    for(int c = 0; c < int(_he.cells.size()); ++c)
      if(_he.cells[c].alive) {
        const int n = _he.cells[c].n;
        const double q = selfQuality(_he.cells[c]);
        if(q > bestQuality[n]) bestQuality[n] = q, best[n] = c;
      }
    auto emit = [&](int c) {
      const Cell &cell = _he.cells[c];
      MVertex *w[4];
      for(int i = 0; i < cell.n; ++i) w[i] = _v[cell.v[i]].mv;
      if(cell.n == 3)
        _gf->triangles.push_back(new MTriangle(w[0], w[1], w[2]));
      else
        _gf->quadrangles.push_back(new MQuadrangle(w[0], w[1], w[2], w[3]));
    };
    for(int n : {3, 4})
      if(best[n] >= 0) emit(best[n]);
    for(int c = 0; c < int(_he.cells.size()); ++c)
      if(_he.cells[c].alive && c != best[3] && c != best[4]) emit(c);

    std::set<MVertex *> removed; // movable vertices no cell uses anymore
    for(std::size_t w = 0; w < _v.size(); ++w)
      if(!_v[w].fixed && _he.star[w].empty()) removed.insert(_v[w].mv);
    auto &owned = _gf->mesh_vertices;
    owned.erase(std::remove_if(owned.begin(), owned.end(),
                               [&](MVertex *v) { return removed.count(v); }),
                owned.end());
    for(MVertex *v : removed) delete v;
    _gf->transfinite_vertices.clear();
    _gf->getColumns()->clearData();
    orientMeshGFace()(_gf);
    _gf->deleteVertexArrays();
    _gf->model()->destroyMeshCaches();
  }

  int FaceMesh::addVertex(const SVector3 &p, const double *uv)
  {
    Vert vert;
    vert.p = p;
    vert.uv[0] = uv[0], vert.uv[1] = uv[1];
    vert.hasUV = true;
    vert.fixed = false;
    _v.push_back(vert);
    return _he.addVertex();
  }

  bool FaceMesh::ensureUV(int id)
  {
    Vert &v = _v[id];
    if(v.hasUV) return true;
    SPoint2 uv;
    if(_gf->geomType() == GEntity::DiscreteSurface)
      uv = _gf->parFromPoint(SPoint3(v.p.x(), v.p.y(), v.p.z()), true, true);
    else if(!v.mv || !reparamMeshVertexOnFace(v.mv, _gf, uv, true, false))
      return false;
    if(!std::isfinite(uv.x()) || !std::isfinite(uv.y())) return false;
    v.uv[0] = uv.x();
    v.uv[1] = uv.y();
    v.hasUV = true;
    return true;
  }

  // Closest point on the CAD surface and its parameters.
  bool FaceMesh::project(const SVector3 &x, const double *guess, SVector3 &out,
                         double *uv) const
  {
    const GPoint gp = _gf->closestPoint(SPoint3(x.x(), x.y(), x.z()), guess);
    if(!gp.succeeded()) return false;
    out = SVector3(gp.x(), gp.y(), gp.z());
    uv[0] = gp.u();
    uv[1] = gp.v();
    return std::isfinite(out.norm());
  }

  // CAD normal at a vertex (cached); the fallback if it cannot be evaluated.
  SVector3 FaceMesh::normalOf(int w, const SVector3 &fallback)
  {
    Vert &v = _v[w];
    if(!v.hasN && ensureUV(w)) {
      v.n = _gf->normal(SPoint2(v.uv[0], v.uv[1]));
      if(v.n.norm() > 0.) v.n.normalize(), v.hasN = true;
    }
    return v.hasN ? v.n : fallback;
  }

  double FaceMesh::align(const Cell &c)
  {
    const Corners p = pointsOf(c);
    const SVector3 fallback = meanNormal(p.data(), c.n);
    SVector3 nv[4];
    for(int i = 0; i < c.n; ++i) nv[i] = normalOf(c.v[i], fallback);
    return alignment(p.data(), nv, c.n);
  }

  double FaceMesh::fit(const Cell &c)
  {
    const Corners p = pointsOf(c);
    const SVector3 own = meanNormal(p.data(), c.n);
    SVector3 mean(0., 0., 0.);
    for(int i = 0; i < c.n; ++i) mean += normalOf(c.v[i], own);
    return quality(p.data(), c.n, mean);
  }

  double FaceMesh::selfQuality(const Cell &c) const
  {
    const Corners p = pointsOf(c);
    return quality(p.data(), c.n, meanNormal(p.data(), c.n));
  }

  // How far the cell cuts through the CAD: distance of its centroid to the
  // tangent plane at each of its vertices, relative to the mean edge length (the
  // sagitta to second order, with no projection on the CAD).
  double FaceMesh::deviation(const Cell &c)
  {
    const Corners p = pointsOf(c);
    const SVector3 own = meanNormal(p.data(), c.n);
    SVector3 centroid(0., 0., 0.);
    double h = 0.;
    for(int i = 0; i < c.n; ++i) {
      centroid += p[i] * (1. / c.n);
      h += (p[(i + 1) % c.n] - p[i]).norm() / c.n;
    }
    if(!(h > 0.)) return 1.e9;
    double worst = 0.;
    for(int i = 0; i < c.n; ++i)
      worst = std::max(
        worst, std::abs(dot(centroid - p[i], normalOf(c.v[i], own))));
    return worst / h;
  }

  double FaceMesh::maxDeviation(const std::vector<Cell> &cells)
  {
    double result = 0.;
    for(const Cell &c : cells) result = std::max(result, deviation(c));
    return result;
  }

} // namespace QuadOpt
