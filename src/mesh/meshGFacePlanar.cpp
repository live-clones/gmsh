// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdint>
#include <map>
#include <set>
#include "meshGFacePlanar.h"
#include "GFace.h"
#include "GEdge.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MVertex.h"
#include "ExtrudeParams.h"
#include "discreteFace.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"

namespace planar {

  namespace {

    // The stars of the nodes stored one after the other, in the order of vt
    // (with the nodes of each triangle in their order), with the density
    // weight h^4 of each triangle, h the mean local size of the input mesh
    // at its nodes: the ODT sweep reads them in sequence instead of
    // following vt and tri across memory. The connectivity must not change
    // while they are used.
    struct Stars {
      std::vector<std::size_t> first;
      std::vector<std::array<int, 3>> tri;
      std::vector<double> h4;

      explicit Stars(const Mesh &m) : first(m.nv + 1, 0)
      {
        for(int v = 0; v < m.nv; v++) first[v + 1] = first[v] + m.vt[v].size();
        tri.reserve(first[m.nv]);
        h4.reserve(first[m.nv]);
        for(int v = 0; v < m.nv; v++)
          for(int t : m.vt[v]) {
            const std::array<int, 3> &T = m.tri[t];
            double hc = (m.h0[T[0]] + m.h0[T[1]] + m.h0[T[2]]) / 3;
            tri.push_back(T);
            h4.push_back(hc * hc * hc * hc);
          }
      }

      // ODT: mean of the circumcenters of the triangles of the star of v,
      // weighted by their area times the density h^-4, the optimal position
      // of the node for the optimal Delaunay triangulation energy; and the
      // worst gamma of the star (Mesh::starGamma)
      bool odtTarget(const std::vector<V2> &x, int v, V2 &target,
                     double &gamma) const
      {
        V2 num = {0, 0};
        double den = 0;
        gamma = 1.;
        for(std::size_t i = first[v]; i < first[v + 1]; i++) {
          V2 p = x[tri[i][0]], q = x[tri[i][1]], r = x[tri[i][2]];
          double A = 0.5 * orient(p, q, r);
          if(A <= 0) return false;
          // circumcenter
          double d =
            2 * (p.x * (q.y - r.y) + q.x * (r.y - p.y) + r.x * (p.y - q.y));
          double p2 = dot(p, p), q2 = dot(q, q), r2 = dot(r, r);
          V2 c = {
            (p2 * (q.y - r.y) + q2 * (r.y - p.y) + r2 * (p.y - q.y)) / d,
            (p2 * (r.x - q.x) + q2 * (p.x - r.x) + r2 * (q.x - p.x)) / d};
          double w = A / h4[i];
          num = num + w * c;
          den += w;
          gamma = std::min(gamma, gammaOf(p, q, r));
        }
        if(den <= 0) return false;
        target = (1. / den) * num;
        return true;
      }

      // mark node v and the nodes of its star
      void mark(int v, std::vector<char> &marks) const
      {
        for(std::size_t i = first[v]; i < first[v + 1]; i++)
          for(int w : tri[i]) marks[w] = 1;
      }

      // the worst gamma of the star of v with v at pos (Mesh::starGamma)
      double starGamma(const std::vector<V2> &x, int v, V2 pos) const
      {
        double g = 1.;
        for(std::size_t i = first[v]; i < first[v + 1]; i++) {
          V2 P[3];
          for(int k = 0; k < 3; k++) P[k] = tri[i][k] == v ? pos : x[tri[i][k]];
          g = std::min(g, gammaOf(P[0], P[1], P[2]));
        }
        return g;
      }
    };

  } // namespace

  void smoothODT(Mesh &m, int iters)
  {
    const Stars stars(m);
    // move node v to its ODT target, or halfway, if the worst triangle of
    // its star does not get worse; the nodes on curves slide instead. The
    // worst gamma of the star before the move (1 on a curve, 0 if a triangle
    // of the star is flat or inverted)
    auto relax = [&](int v) {
      if(m.onBnd[v]) {
        if(m.slidable(v)) m.slideBest(v);
        return 1.;
      }
      V2 target;
      double g;
      if(!stars.odtTarget(m.x, v, target, g)) return 0.;
      if(stars.starGamma(m.x, v, target) >= g) {
        m.x[v] = target;
        return g;
      }
      V2 half = 0.5 * (m.x[v] + target);
      if(stars.starGamma(m.x, v, half) >= g) m.x[v] = half;
      return g;
    };
    // a sweep only visits the nodes that moved, or whose neighbors moved, by
    // more than tol times their local size in the previous one (the rest has
    // converged), the nodes whose star has a triangle below gPoor (they
    // converge slowly and matter most), and the sliding nodes, whose search
    // for the best position on their curve refines at each visit
    const double tol = 3e-3, gPoor = 0.95;
    std::vector<char> active(m.nv, 1), next(m.nv);
    for(int it = 0; it < iters; it++) {
      std::fill(next.begin(), next.end(), 0);
      bool any = false;
      for(int v = 0; v < m.nv; v++) {
        if(!m.aliveV[v] || !(active[v] || m.slidable(v))) continue;
        const V2 x0 = m.x[v];
        const double g = relax(v);
        if(norm(m.x[v] - x0) > tol * m.h0[v]) {
          stars.mark(v, next);
          any = true;
        }
        else if(g < gPoor) {
          next[v] = 1;
          any = true;
        }
      }
      if(!any) break;
      active.swap(next);
    }
  }

  V2 Face::_to2D(double X, double Y, double Z) const
  {
    SVector3 d(X - _origin.x(), Y - _origin.y(), Z - _origin.z());
    return V2{::dot(d, _e1), ::dot(d, _e2)};
  }

  SPoint3 Face::_to3D(V2 p) const
  {
    return SPoint3(_origin.x() + p.x * _e1.x() + p.y * _e2.x(),
                   _origin.y() + p.x * _e1.y() + p.y * _e2.y(),
                   _origin.z() + p.x * _e1.z() + p.y * _e2.z());
  }

  Face::Face(const std::vector<GFace *> &faces,
             const std::function<bool(GFace *)> &frozen)
    : _faces(faces), _inSet(faces.begin(), faces.end())
  {
    // the nodes of the triangles of the surfaces, numbered in the order they
    // appear, and the triangles
    std::size_t nt = 0;
    for(GFace *gf : faces) nt += gf->triangles.size();
    if(!nt) return;
    _id.reserve(nt / 2 + 3);
    tri.reserve(nt);
    owner.reserve(nt);
    for(std::size_t f = 0; f < faces.size(); f++)
      for(MTriangle *t : faces[f]->triangles) {
        std::array<int, 3> T;
        for(int k = 0; k < 3; k++) {
          MVertex *v = t->getVertex(k);
          auto it = _id.emplace(v, (int)_verts.size());
          if(it.second) _verts.push_back(v);
          T[k] = it.first->second;
        }
        tri.push_back(T);
        owner.push_back((int)f);
      }

    // frame of the plane: the mean normal of the triangles, so that they are
    // counterclockwise in it and keep their orientation when written back
    SVector3 nrm(0., 0., 0.);
    for(GFace *gf : faces)
      for(MTriangle *t : gf->triangles) {
        SVector3 a(t->getVertex(0)->point(), t->getVertex(1)->point());
        SVector3 b(t->getVertex(0)->point(), t->getVertex(2)->point());
        nrm += crossprod(a, b);
      }
    auto clear = [this]() {
      _verts.clear();
      _id.clear();
      tri.clear();
      owner.clear();
    };
    if(nrm.norm() == 0.) {
      clear();
      return;
    }
    nrm.normalize();
    _e1 =
      (std::abs(nrm.x()) < 0.9) ? SVector3(1., 0., 0.) : SVector3(0., 1., 0.);
    _e1 -= ::dot(_e1, nrm) * nrm;
    _e1.normalize();
    _e2 = crossprod(nrm, _e1);
    _origin = _verts[0]->point();
    // several surfaces, or frozen neighbors, must lie in that plane
    SBoundingBox3d bb;
    for(MVertex *v : _verts) bb += v->point();
    const double tol = 1e-8 * bb.diag();
    auto inPlane = [&](MVertex *v) {
      SVector3 d(_origin, v->point());
      return std::abs(::dot(d, nrm)) <= tol;
    };
    if(faces.size() > 1)
      for(MVertex *v : _verts)
        if(!inPlane(v)) {
          clear();
          return;
        }
    const int nSet = (int)_verts.size();

    // the frozen triangles: those of the other surfaces of the plane that
    // touch the nodes of the surfaces (only nodes on curves or points can)
    if(frozen && !faces.empty()) {
      GModel *gm = faces[0]->model();
      for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
        GFace *g = *it;
        if(_inSet.count(g) || !frozen(g)) continue;
        std::vector<MTriangle *> touching;
        for(MTriangle *t : g->triangles)
          for(int k = 0; k < 3; k++) {
            MVertex *v = t->getVertex(k);
            if(v->onWhat() && v->onWhat()->dim() < 2 && _id.count(v)) {
              touching.push_back(t);
              break;
            }
          }
        bool ok = true;
        for(MTriangle *t : touching)
          for(int k = 0; k < 3 && ok; k++) ok = inPlane(t->getVertex(k));
        if(!ok) continue;
        for(MTriangle *t : touching) {
          std::array<int, 3> T;
          for(int k = 0; k < 3; k++) {
            MVertex *v = t->getVertex(k);
            auto it2 = _id.emplace(v, (int)_verts.size());
            if(it2.second) _verts.push_back(v);
            T[k] = it2.first->second;
          }
          tri.push_back(T);
          owner.push_back(-1);
          _numFrozen++;
        }
      }
    }

    const int n0 = (int)_verts.size();
    x.resize(n0);
    onCurve.assign(n0, 0);
    frozenV.assign(n0, 0);
    for(int i = 0; i < n0; i++) {
      MVertex *v = _verts[i];
      x[i] = _to2D(v->x(), v->y(), v->z());
      onCurve[i] = v->onWhat()->dim() < 2 || i >= nSet;
      frozenV[i] = i >= nSet;
    }

    // the edges of the frozen triangles, and those between the triangles of
    // two surfaces, are never flipped nor split; their nodes are fixed
    std::unordered_map<uint64_t, int> edgeOwner;
    for(std::size_t t = 0; t < tri.size(); t++)
      for(int k = 0; k < 3; k++) {
        int a = tri[t][k], b = tri[t][(k + 1) % 3];
        uint64_t key = ((uint64_t)std::min(a, b) << 32) | std::max(a, b);
        auto it = edgeOwner.emplace(key, owner[t]);
        if(owner[t] < 0 || (!it.second && it.first->second != owner[t])) {
          constrainedEdges.push_back({a, b});
          onCurve[a] = onCurve[b] = 1;
        }
      }

    // the curves of the surfaces (boundary and embedded), their edges, and
    // the neighbors of their nodes on them
    std::set<GEdge *> seen;
    for(GFace *gf : faces) {
      std::vector<GEdge *> curves = gf->edges();
      for(GEdge *ge : gf->embeddedEdges()) curves.push_back(ge);
      for(GEdge *ge : curves)
        if(seen.insert(ge).second) _curves.push_back(ge);
    }
    for(GEdge *ge : _curves)
      for(MLine *l : ge->lines) {
        MVertex *a = l->getVertex(0), *b = l->getVertex(1);
        auto ia = _id.find(a), ib = _id.find(b);
        if(ia != _id.end() && ib != _id.end())
          constrainedEdges.push_back({ia->second, ib->second});
        _curveNb[a].push_back(b);
        _curveNb[b].push_back(a);
      }
  }

  int Face::setupSliding(Mesh &m)
  {
    // never on a curve whose nodes a mesh that is not optimized with the
    // surfaces uses (a curve that bounds or is embedded in another surface,
    // possibly meshed at the same time, a periodic curve, a compound) or
    // whose node distribution is imposed (a transfinite or an extruded curve)
    GModel *gm = _faces[0]->model();
    std::set<GEdge *> elsewhere, masters;
    for(auto it = gm->firstFace(); it != gm->lastFace(); ++it)
      if(!_inSet.count(*it))
        for(GEdge *e : (*it)->embeddedEdges()) elsewhere.insert(e);
    for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it)
      if((*it)->getMeshMaster() != *it)
        masters.insert(static_cast<GEdge *>((*it)->getMeshMaster()));
    std::unordered_map<GEdge *, int> curveIndex;
    for(std::size_t c = 0; c < _curves.size(); c++) {
      GEdge *ge = _curves[c];
      const char *fixed = nullptr;
      for(GFace *f : ge->faces())
        if(!_inSet.count(f)) fixed = "it bounds another surface";
      if(elsewhere.count(ge)) fixed = "it is embedded in another surface";
      if(ge->getMeshMaster() != ge || masters.count(ge))
        fixed = "it is periodic";
      if(!ge->compound.empty() || ge->compoundCurve)
        fixed = "it belongs to a compound";
      if(ge->meshAttributes.method == MESH_TRANSFINITE)
        fixed = "it is transfinite";
      if(ge->meshAttributes.extrude &&
         ge->meshAttributes.extrude->mesh.ExtrudeMesh)
        fixed = "it is extruded";
      if(fixed)
        Msg::Debug("Surface %d: the nodes of curve %d do not slide, %s",
                   _faces[0]->tag(), ge->tag(), fixed);
      else
        curveIndex[ge] = (int)c;
    }

    // nodes sliding along their curve, between their two neighbors on it
    const int n0 = (int)_verts.size();
    int nSlide = 0;
    m.slideOn = true;
    m.slideCurve.assign(n0, -1);
    m.tpar.assign(n0, 0.);
    m.slideNb.assign(n0, {-1, -1});
    m.slideNbT.assign(n0, {0., 0.});
    // the nodes of frozen triangles never move
    std::vector<char> usedFrozen(n0, 0);
    for(std::size_t t = 0; t < tri.size(); t++)
      if(owner[t] < 0)
        for(int v : tri[t]) usedFrozen[v] = 1;
    for(int i = 0; i < n0; i++) {
      MVertex *v = _verts[i];
      if(usedFrozen[i] || v->onWhat()->dim() != 1) continue;
      GEdge *ge = static_cast<GEdge *>(v->onWhat());
      auto ci = curveIndex.find(ge);
      if(ci == curveIndex.end()) continue;
      double t;
      if(!v->getParameter(0, t)) continue;
      auto nb = _curveNb.find(v);
      if(nb == _curveNb.end() || nb->second.size() != 2) continue;
      bool ok = true;
      std::array<int, 2> nbId;
      std::array<double, 2> nbT;
      for(int k = 0; k < 2 && ok; k++) {
        MVertex *w = nb->second[k];
        auto iw = _id.find(w);
        if(iw == _id.end()) {
          ok = false;
          break;
        }
        nbId[k] = iw->second;
        if(w->onWhat() == ge)
          nbT[k] = std::numeric_limits<double>::quiet_NaN();
        else if(ge->periodic(0) && w->onWhat()->dim() == 0) {
          // the closing point of a closed curve is at both ends of the
          // parameter range: take the end on the other side of the node than
          // its other neighbor
          Range<double> r = ge->parBounds(0);
          MVertex *o = nb->second[1 - k];
          double to;
          bool side = (o->onWhat() == ge && o->getParameter(0, to)) ?
                        to > t :
                        k == 0;
          nbT[k] = side ? r.low() : r.high();
        }
        else {
          double tw;
          ok = reparamMeshVertexOnEdge(w, ge, tw);
          nbT[k] = tw;
        }
      }
      if(!ok) continue;
      m.tpar[i] = t;
      m.slideCurve[i] = ci->second;
      m.slideNb[i] = nbId;
      m.slideNbT[i] = nbT;
    }
    // a node must lie strictly between the parameters of its neighbors
    for(int i = 0; i < n0; i++) {
      if(m.slideCurve[i] < 0) continue;
      double lim[2];
      for(int k = 0; k < 2; k++)
        lim[k] = std::isnan(m.slideNbT[i][k]) ? m.tpar[m.slideNb[i][k]] :
                                                m.slideNbT[i][k];
      if(!(std::min(lim[0], lim[1]) < m.tpar[i] &&
           m.tpar[i] < std::max(lim[0], lim[1])))
        m.slideCurve[i] = -1;
      else
        nSlide++;
    }
    m.curvePoint = [this](int c, double t) {
      GPoint p = _curves[c]->point(t);
      return _to2D(p.x(), p.y(), p.z());
    };
    return nSlide;
  }

  void Face::write(const Mesh &m, bool topology)
  {
    // move the kept nodes; with topology changes, also create the inserted
    // ones, delete the removed ones (always nodes of a surface) and rebuild
    // the triangles of each surface. The frozen nodes never move.
    const int n0 = (int)_verts.size();
    auto onFace = [](GFace *gf, SPoint3 P, MVertex *v) {
      // the parametric coordinates, on the surfaces that have some
      if(gf->geomType() == GEntity::DiscreteSurface) return;
      SPoint2 uv = gf->parFromPoint(P);
      v->setParameter(0, uv.x());
      v->setParameter(1, uv.y());
    };
    std::vector<MVertex *> vtx(m.nv, nullptr);
    for(int i = 0; i < m.nv; i++) {
      if(!m.aliveV[i]) continue;
      if(i < n0) {
        MVertex *v = _verts[i];
        vtx[i] = v;
        if(m.frozen(i)) continue;
        if(v->onWhat()->dim() == 2 && _inSet.count((GFace *)v->onWhat())) {
          SPoint3 P = _to3D(m.x[i]);
          v->setXYZ(P.x(), P.y(), P.z());
          onFace(static_cast<GFace *>(v->onWhat()), P, v);
        }
        else if(m.slidable(i)) {
          double t;
          v->getParameter(0, t);
          if(t != m.tpar[i]) {
            GPoint p = _curves[m.slideCurve[i]]->point(m.tpar[i]);
            v->setXYZ(p.x(), p.y(), p.z());
            v->setParameter(0, m.tpar[i]);
          }
        }
      }
      else if(topology) {
        GFace *gf = _faces[m.nodeOwner[i]];
        SPoint3 P = _to3D(m.x[i]);
        MVertex *v;
        if(gf->geomType() == GEntity::DiscreteSurface)
          v = new MVertex(P.x(), P.y(), P.z(), gf);
        else {
          SPoint2 uv = gf->parFromPoint(P);
          v = new MFaceVertex(P.x(), P.y(), P.z(), gf, uv.x(), uv.y());
        }
        gf->mesh_vertices.push_back(v);
        vtx[i] = v;
      }
    }
    if(!topology) return;
    std::map<GFace *, std::set<MVertex *>> dead;
    for(int i = 0; i < n0; i++)
      if(!m.aliveV[i]) dead[static_cast<GFace *>(_verts[i]->onWhat())].insert(
          _verts[i]);
    for(auto &d : dead) {
      std::vector<MVertex *> keep;
      keep.reserve(d.first->mesh_vertices.size());
      for(MVertex *v : d.first->mesh_vertices)
        if(!d.second.count(v)) keep.push_back(v);
      d.first->mesh_vertices.swap(keep);
      for(MVertex *v : d.second) delete v;
    }
    for(GFace *gf : _faces) {
      for(MTriangle *t : gf->triangles) delete t;
      gf->triangles.clear();
    }
    for(std::size_t t = 0; t < m.tri.size(); t++)
      if(m.aliveT[t] && m.owner[t] >= 0)
        _faces[m.owner[t]]->triangles.push_back(new MTriangle(
          vtx[m.tri[t][0]], vtx[m.tri[t][1]], vtx[m.tri[t][2]]));
  }

  bool frozenWhileMeshing(GFace *gf)
  {
    return gf->geomType() == GEntity::DiscreteSurface &&
           !static_cast<discreteFace *>(gf)->haveParametrization();
  }

} // namespace planar

void smoothPlanarFaceODT(GFace *gf, int iterations)
{
  if(iterations <= 0) return;
  const double t0 = TimeOfDay();
  planar::Face face({gf}, planar::frozenWhileMeshing);
  if(face.empty()) return;
  planar::Mesh m(face.x, face.tri, face.onCurve);
  face.init(m);
  const int nSlide = CTX::instance()->mesh.boundaryNodeSliding2D ?
                       face.setupSliding(m) :
                       0;
  std::vector<int> all(m.tri.size());
  for(std::size_t t = 0; t < m.tri.size(); t++) all[t] = (int)t;
  const double g0 = m.minGamma(all);
  planar::smoothODT(m, iterations);
  face.write(m, false);
  Msg::Info("ODT smoothing of surface %d: worst gamma %.3f -> %.3f, %d "
            "sliding boundary nodes (%g s)",
            gf->tag(), g0, m.minGamma(all), nSlide, TimeOfDay() - t0);
}
