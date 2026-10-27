// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "Generator.h"
#include "GModel.h"
#include <algorithm>
#include <array>
#include <functional>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include "MFace.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "SVector3.h"
#include "meshGRegion.h"
#include "meshCombine3D.h"
#include "qualityMeasures.h"
#include "robustPredicates.h"

namespace {
  // a face by its vertices sorted by address (3 or 4, the 4th null for a
  // triangle)
  struct SortedFace {
    MVertex *v[4];
    bool operator==(const SortedFace &o) const
    {
      return v[0] == o.v[0] && v[1] == o.v[1] && v[2] == o.v[2] &&
             v[3] == o.v[3];
    }
  };
  struct SortedFaceHash {
    std::size_t operator()(const SortedFace &f) const
    {
      std::size_t h = 0;
      for(int i = 0; i < 4; i++)
        h = h * 0x9E3779B97F4A7C15ull + (std::size_t)f.v[i] / sizeof(void *);
      return h ^ (h >> 29);
    }
  };
  SortedFace sortedFace(MVertex *a, MVertex *b, MVertex *c,
                        MVertex *d = nullptr)
  {
    SortedFace f = {{a, b, c, d}};
    std::sort(f.v, f.v + (d ? 4 : 3));
    return f;
  }
} // namespace

#if defined(HAVE_HXT)

#include "hxt_combine_cpp_api.h"

// Two tets standing on the two triangles of an unmatched hex or prism quad
// face, split along the same diagonal and sharing the vertex opposite to it,
// form a pyramid on that face: replace them with one pyramid. The four
// lateral triangles are preserved, and the base matches the quad face
// without a trihedron.
static std::size_t makeFreePyramids(GRegion *gr)
{
  std::map<MFace, std::vector<MTetrahedron *>, MFaceLessThan> tri2tet;
  for(MTetrahedron *t : gr->tetrahedra)
    for(int f = 0; f < 4; f++) tri2tet[t->getFace(f)].push_back(t);
  // a quad face on 2 tets has its 4 vertices on tets: the others are not
  // counted
  std::unordered_set<MVertex *> onTets;
  onTets.reserve(gr->tetrahedra.size());
  for(MTetrahedron *t : gr->tetrahedra)
    for(int k = 0; k < 4; k++) onTets.insert(t->getVertex(k));
  std::map<MFace, int, MFaceLessThan> quads;
  auto addQuads = [&](MElement *e, int nbFaces,
                      int (*face)(const int, const int)) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) < 0) continue; // a triangle
      bool candidate = true;
      for(int j = 0; j < 4 && candidate; j++)
        candidate = onTets.count(e->getVertex(face(f, j)));
      if(candidate) quads[e->getFace(f)]++;
    }
  };
  for(MHexahedron *h : gr->hexahedra) addQuads(h, 6, MHexahedron::faces_hexa);
  for(MPrism *p : gr->prisms) addQuads(p, 5, MPrism::faces_prism);

  auto apexOf = [](MTetrahedron *t, MVertex *x, MVertex *y, MVertex *z) {
    for(int k = 0; k < 4; k++) {
      MVertex *w = t->getVertex(k);
      if(w != x && w != y && w != z) return w;
    }
    return (MVertex *)nullptr;
  };
  std::set<MTetrahedron *> used;
  std::size_t n = 0;
  for(auto &kv : quads) {
    if(kv.second != 1) continue; // shared by two cells
    const MFace &q = kv.first;
    MVertex *v[4] = {q.getVertex(0), q.getVertex(1), q.getVertex(2),
                     q.getVertex(3)};
    for(int d = 0; d < 2; d++) {
      MVertex *a = v[d], *b = v[d + 1], *c = v[(d + 2) % 4],
              *e = v[(d + 3) % 4];
      auto i1 = tri2tet.find(MFace(a, b, c));
      auto i2 = tri2tet.find(MFace(c, e, a));
      if(i1 == tri2tet.end() || i2 == tri2tet.end()) continue;
      if(i1->second.size() != 1 || i2->second.size() != 1) continue;
      MTetrahedron *t1 = i1->second[0], *t2 = i2->second[0];
      if(t1 == t2 || used.count(t1) || used.count(t2)) continue;
      MVertex *apex = apexOf(t1, a, b, c);
      if(!apex || apex != apexOf(t2, c, e, a)) continue;
      // a warped face can leave one corner of the pyramid nearly flat:
      // keep a margin, later smoothing only protects the worst element of
      // each cavity
      const double minQuality = 0.1;
      MPyramid *p = new MPyramid(v[0], v[1], v[2], v[3], apex);
      if(!(p->minSICNShapeMeasure() >= minQuality)) {
        delete p;
        p = new MPyramid(v[0], v[3], v[2], v[1], apex);
        if(!(p->minSICNShapeMeasure() >= minQuality)) {
          delete p;
          continue;
        }
      }
      used.insert(t1);
      used.insert(t2);
      gr->pyramids.push_back(p);
      n++;
      break;
    }
  }
  if(n) {
    std::vector<MTetrahedron *> kept;
    kept.reserve(gr->tetrahedra.size());
    for(MTetrahedron *t : gr->tetrahedra) {
      if(used.count(t))
        delete t;
      else
        kept.push_back(t);
    }
    gr->tetrahedra.swap(kept);
  }
  return n;
}

// The trihedra with positive volumes (Mesh.Recombine3DPositiveTrihedra). The
// trihedron of an unmatched quadrangular face (p, r, q, s), whose triangles
// (p, q, r) and (p, q, s) are faces of the elements on its other side, has
// half the volume of the tetrahedron (p, q, r, s): positive when s is on the
// other side of (p, q, r) than the element on it, the two triangles lying
// then beyond the quadrangle, negative when they overlap the cell it bounds.
// The diagonal (p, q) of a negative one is swapped to (r, s) by
// retriangulating the tetrahedra around it, else the face is flattened.
namespace {

  void coordinates(const MVertex *v, double x[3])
  {
    x[0] = v->x();
    x[1] = v->y();
    x[2] = v->z();
  }

  double orient(const MVertex *a, const MVertex *b, const MVertex *c,
                const double d[3])
  {
    double pa[3], pb[3], pc[3];
    coordinates(a, pa);
    coordinates(b, pb);
    coordinates(c, pc);
    return robustPredicates::orient3d(pa, pb, pc, d);
  }

  double orient(const MVertex *a, const MVertex *b, const MVertex *c,
                const MVertex *d)
  {
    double pd[3];
    coordinates(d, pd);
    return orient(a, b, c, pd);
  }

  // an unmatched quadrangular face: its diagonal (p, q) and its other
  // vertices r and s, and the cell it bounds
  struct HangingQuad {
    MVertex *p, *q, *r, *s;
    MElement *owner;
  };

  class PositiveTrihedra {
  public:
    // the counts of the faces of negative trihedra
    struct Statistics {
      std::size_t quads = 0, negative = 0, pyramids = 0, swapped[6] = {0},
                  blocked = 0, tooMany = 0, invalid = 0, shifted = 0,
                  flattened = 0, left = 0;
    };

    PositiveTrihedra(GRegion *gr, bool skipPyramids) :
      _gr(gr), _skipPyramids(skipPyramids)
    {
      // the vertices of the elements with triangular faces, marked -1 in
      // MVertex::_index, the other vertices of the quadrangular faces -2: an
      // unmatched face has its 4 vertices on them
      auto mark = [](MElement *e, long m) {
        for(std::size_t k = 0; k < e->getNumVertices(); k++)
          e->getVertex(k)->setIndex(m);
      };
      for(MHexahedron *h : gr->hexahedra) mark(h, -2);
      for(MPrism *p : gr->prisms) mark(p, -2);
      for(MTetrahedron *t : gr->tetrahedra) mark(t, -1);
      for(MPyramid *p : gr->pyramids) mark(p, -1);
      for(MPrism *p : gr->prisms) mark(p, -1);
      _onTriangle.reserve(2 * gr->tetrahedra.size() + 4 * gr->pyramids.size() +
                          2 * gr->prisms.size());
      for(MTetrahedron *t : gr->tetrahedra) addTriangles(t, 4, tetFace);
      for(MPyramid *p : gr->pyramids)
        addTriangles(p, 5, MPyramid::faces_pyramid);
      for(MPrism *p : gr->prisms) addTriangles(p, 5, MPrism::faces_prism);
      if(!gr->tetrahedra.empty()) {
        MTetrahedron *t = gr->tetrahedra[0];
        _orientation = orient(t->getVertex(0), t->getVertex(1),
                              t->getVertex(2), t->getVertex(3)) > 0. ? 1 : -1;
      }
      // in blocks of cells appended in their order, whatever the threads
      auto addAllQuads = [&](const auto &cells, int nbFaces,
                             int (*face)(const int, const int)) {
        const std::size_t block = 4096;
        const int nbBlocks = (int)((cells.size() + block - 1) / block);
        std::vector<std::vector<HangingQuad> > found(nbBlocks);
#pragma omp parallel for schedule(dynamic, 1)
        for(int b = 0; b < nbBlocks; b++)
          for(std::size_t i = b * block;
              i < std::min(cells.size(), (b + 1) * block); i++)
            addQuads(cells[i], nbFaces, face, found[b]);
        for(auto &f : found) _quads.insert(_quads.end(), f.begin(), f.end());
      };
      addAllQuads(gr->hexahedra, 6, MHexahedron::faces_hexa);
      addAllQuads(gr->prisms, 5, MPrism::faces_prism);
    }

    Statistics run()
    {
      Statistics stats;
      stats.quads = _quads.size();
      buildAdjacency();
      // rounds of remedies: a face blocked by a neighbor may pass once the
      // neighbor is done, until a round makes less than 5% of the negative
      // ones positive (10 rounds at most)
      std::size_t previous = 0;
      for(int round = 0; round < 10; round++) {
      std::vector<char> isNegative(_quads.size());
#pragma omp parallel for schedule(static)
      for(int i = 0; i < (int)_quads.size(); i++)
        isNegative[i] = trihedronVolume(_quads[i]) < -_flat;
      std::vector<std::size_t> negative;
      for(std::size_t i = 0; i < _quads.size(); i++)
        if(isNegative[i]) negative.push_back(i);
      if(!round) stats.negative = negative.size();
      if(negative.empty() || (round && negative.size() > .95 * previous))
        break;
      previous = negative.size();
      stats.left = 0;
      // the swaps, then the faces left flattened
      std::vector<std::size_t> left;
      for(std::size_t i : negative) {
        const HangingQuad h = _quads[i];
        if(_skipPyramids && isPyramid(h)) {
          stats.pyramids++;
          continue;
        }
        const int n = swapDiagonal(h);
        if(n > 0) {
          stats.swapped[n]++;
          _quads[i] = {h.r, h.s, h.p, h.q, h.owner}; // the new diagonal
        }
        else {
          if(n == BLOCKED) stats.blocked++;
          if(n == TOO_MANY) stats.tooMany++;
          if(n == INVALID) stats.invalid++;
          left.push_back(i);
        }
      }
      if(!left.empty()) flatten(left, stats);
      }
      // the tetrahedra replaced
      std::vector<MTetrahedron *> kept;
      kept.reserve(_gr->tetrahedra.size() + _added.size());
      for(MTetrahedron *t : _gr->tetrahedra) {
        if(_removed.count(t))
          delete t;
        else
          kept.push_back(t);
      }
      for(MTetrahedron *t : _added)
        if(!_removed.count(t)) kept.push_back(t);
        else delete t;
      _gr->tetrahedra.swap(kept);
      for(const HangingQuad &h : _quads)
        for(MVertex *v : {h.p, h.q, h.r, h.s})
          if(v->getIndex() >= 0) v->setIndex(-1);
      return stats;
    }

  private:
    enum { BLOCKED = -1, TOO_MANY = -2, INVALID = -3 };
    // a negative trihedron of at most this fraction of the cube of the mean
    // edge of its face is taken as flat
    const double _flat = 1.e-3;
    // the quality (gamma of the tetrahedra, SICN of the others) under which
    // an element is not made worse than it is
    const double _minQuality = 0.05;

    GRegion *_gr;
    bool _skipPyramids;
    int _orientation = 1; // the sign of orient3d of the tetrahedra
    // the elements on each triangle (at most 2)
    std::unordered_map<SortedFace, std::array<MElement *, 2>, SortedFaceHash>
      _onTriangle;
    std::vector<HangingQuad> _quads;
    std::unordered_set<MTetrahedron *> _removed;
    std::vector<MTetrahedron *> _added;
    // the vertices of the faces inside the region, numbered in
    // MVertex::_index (the others are marked < 0), with their elements and
    // their unmatched faces
    std::vector<std::vector<MElement *> > _elements;
    std::vector<std::vector<std::size_t> > _quadsOf;

    void buildAdjacency()
    {
      std::size_t nbMovable = 0;
      for(const HangingQuad &h : _quads)
        for(MVertex *v : {h.p, h.q, h.r, h.s})
          if(v->getIndex() < 0 && v->onWhat() && v->onWhat()->dim() == 3)
            v->setIndex(nbMovable++);
      _elements.assign(nbMovable, std::vector<MElement *>());
      _quadsOf.assign(nbMovable, std::vector<std::size_t>());
      auto add = [&](MElement *e) {
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          const long m = e->getVertex(k)->getIndex();
          if(m >= 0) _elements[m].push_back(e);
        }
      };
      for(MTetrahedron *t : _gr->tetrahedra) add(t);
      for(MHexahedron *e : _gr->hexahedra) add(e);
      for(MPrism *e : _gr->prisms) add(e);
      for(MPyramid *e : _gr->pyramids) add(e);
      for(std::size_t i = 0; i < _quads.size(); i++)
        for(MVertex *v : {_quads[i].p, _quads[i].q, _quads[i].r, _quads[i].s})
          if(v->getIndex() >= 0) _quadsOf[v->getIndex()].push_back(i);
    }

    static int tetFace(const int f, const int j)
    {
      return j < 3 ? MTetrahedron::faces_tetra(f, j) : -1;
    }
    // the triangular faces of e (face(f, 3) < 0)
    void addTriangles(MElement *e, int nbFaces,
                      int (*face)(const int, const int))
    {
      for(int f = 0; f < nbFaces; f++) {
        if(face(f, 3) >= 0) continue;
        auto &on = _onTriangle[sortedFace(e->getVertex(face(f, 0)),
                                          e->getVertex(face(f, 1)),
                                          e->getVertex(face(f, 2)))];
        if(!on[0]) on[0] = e;
        else on[1] = e;
      }
    }
    void removeTriangles(MTetrahedron *t)
    {
      for(int f = 0; f < 4; f++) {
        auto it = _onTriangle.find(sortedFace(t->getVertex(tetFace(f, 0)),
                                              t->getVertex(tetFace(f, 1)),
                                              t->getVertex(tetFace(f, 2))));
        if(it == _onTriangle.end()) continue;
        if(it->second[0] == t) it->second[0] = it->second[1];
        it->second[1] = nullptr;
        if(!it->second[0]) _onTriangle.erase(it);
      }
    }
    // the element on triangle (a, b, c) of an unmatched face, if only one
    MElement *onlyElementOn(MVertex *a, MVertex *b, MVertex *c) const
    {
      auto it = _onTriangle.find(sortedFace(a, b, c));
      if(it == _onTriangle.end() || it->second[1]) return nullptr;
      return it->second[0];
    }
    // the unmatched quadrangular faces of e, with their 4 vertices marked -1
    void addQuads(MElement *e, int nbFaces, int (*face)(const int, const int),
                  std::vector<HangingQuad> &quads) const
    {
      for(int f = 0; f < nbFaces; f++) {
        if(face(f, 3) < 0) continue;
        MVertex *v[4];
        bool candidate = true;
        for(int j = 0; j < 4 && candidate; j++) {
          v[j] = e->getVertex(face(f, j));
          candidate = v[j]->getIndex() == -1;
        }
        if(!candidate) continue;
        for(int d = 0; d < 2; d++) {
          HangingQuad h = {v[d], v[d + 2], v[d + 1], v[(d + 3) % 4], e};
          if(onlyElementOn(h.p, h.q, h.r) && onlyElementOn(h.p, h.q, h.s)) {
            quads.push_back(h);
            break;
          }
        }
      }
    }

    // the signed volume of the trihedron of h, divided by the cube of the
    // mean edge of its face (0 if its triangles are not faces of elements)
    double trihedronVolume(const HangingQuad &h) const
    {
      MElement *e = onlyElementOn(h.p, h.q, h.r);
      if(!e) return 0.;
      double c[3] = {0., 0., 0.};
      for(std::size_t i = 0; i < e->getNumVertices(); i++) {
        c[0] += e->getVertex(i)->x() / e->getNumVertices();
        c[1] += e->getVertex(i)->y() / e->getNumVertices();
        c[2] += e->getVertex(i)->z() / e->getNumVertices();
      }
      const double os = orient(h.p, h.q, h.r, h.s), oc = orient(h.p, h.q, h.r, c);
      const double L = (h.p->distance(h.r) + h.r->distance(h.q) +
                        h.q->distance(h.s) + h.s->distance(h.p)) / 4.;
      const double v = std::abs(os) / 12. / (L * L * L);
      return os * oc < 0. ? v : -v;
    }

    MVertex *otherVertex(MTetrahedron *t, MVertex *a, MVertex *b,
                         MVertex *c) const
    {
      for(int k = 0; k < 4; k++) {
        MVertex *w = t->getVertex(k);
        if(w != a && w != b && w != c) return w;
      }
      return nullptr;
    }

    // the two tetrahedra on the triangles of h form a pyramid on it
    bool isPyramid(const HangingQuad &h) const
    {
      MTetrahedron *ta =
        dynamic_cast<MTetrahedron *>(onlyElementOn(h.p, h.q, h.r));
      MTetrahedron *tb =
        dynamic_cast<MTetrahedron *>(onlyElementOn(h.p, h.q, h.s));
      if(!ta || !tb || ta == tb) return false;
      MVertex *apex = otherVertex(ta, h.p, h.q, h.r);
      if(!apex || apex != otherVertex(tb, h.p, h.q, h.s)) return false;
      // as makeFreePyramids
      MPyramid p1(h.p, h.r, h.q, h.s, apex), p2(h.p, h.s, h.q, h.r, apex);
      return p1.minSICNShapeMeasure() >= 0.1 || p2.minSICNShapeMeasure() >= 0.1;
    }

    // the triangulations of the polygon of vertices 0 .. m, each as triangles
    // (i, k, j)
    static const std::vector<std::vector<std::array<int, 3> > > &
    triangulations(int m)
    {
      static std::vector<std::vector<std::vector<std::array<int, 3> > > > all;
#pragma omp critical(positiveTrihedraTriangulations)
      if(all.empty()) {
        all.resize(6);
        // of the polygon i .. j
        std::function<std::vector<std::vector<std::array<int, 3> > >(int, int)>
          of = [&](int i, int j) {
            std::vector<std::vector<std::array<int, 3> > > result;
            if(j - i < 2) {
              result.emplace_back();
              return result;
            }
            for(int k = i + 1; k < j; k++)
              for(auto &left : of(i, k))
                for(auto &right : of(k, j)) {
                  std::vector<std::array<int, 3> > t = left;
                  t.insert(t.end(), right.begin(), right.end());
                  t.push_back({i, k, j});
                  result.push_back(t);
                }
            return result;
          };
        for(int k = 1; k <= 5; k++) all[k] = of(0, k);
      }
      return all[m];
    }

    // The tetrahedra around (p, q), from the one on (p, q, r) to the one on
    // (p, q, s), with their other vertices r = ring[0], ..., ring[n] = s,
    // replaced by the best valid triangulation of the polygon of the ring:
    // a tetrahedron with p and one with q on each triangle, the triangle on
    // (r, s) giving the faces (p, r, s) and (q, r, s) of the new diagonal (a
    // single tetrahedron, (p, q, r, s), is removed). Returns the number of
    // tetrahedra around (p, q), or why it was not swapped.
    int swapDiagonal(const HangingQuad &h)
    {
      MTetrahedron *t =
        dynamic_cast<MTetrahedron *>(onlyElementOn(h.p, h.q, h.r));
      if(!t) return BLOCKED;
      std::vector<MTetrahedron *> shell;
      std::vector<MVertex *> ring(1, h.r);
      while(true) {
        shell.push_back(t);
        if(shell.size() > 5) return TOO_MANY;
        MVertex *next = otherVertex(t, h.p, h.q, ring.back());
        ring.push_back(next);
        if(next == h.s) break;
        auto it = _onTriangle.find(sortedFace(h.p, h.q, next));
        if(it == _onTriangle.end() || !it->second[1]) return BLOCKED;
        MElement *e = it->second[0] == t ? it->second[1] : it->second[0];
        t = dynamic_cast<MTetrahedron *>(e);
        if(!t) return BLOCKED;
      }
      if(onlyElementOn(h.p, h.q, h.s) != shell.back()) return BLOCKED;
      const int n = (int)shell.size();
      double volume = 0., worst = 1.;
      for(MTetrahedron *s : shell) {
        const double o = orient(s->getVertex(0), s->getVertex(1),
                                s->getVertex(2), s->getVertex(3));
        if((o > 0. ? 1 : -1) != _orientation) return INVALID;
        volume += std::abs(o);
        worst = std::min(worst, s->gammaShapeMeasure());
      }
      // the region without the tetrahedron (p, q, r, s) between the two
      // splits of the face
      const double target = volume - std::abs(orient(h.p, h.q, h.r, h.s));
      if(n == 1) {
        // the faces (p, r, s) and (q, r, s) of the new split are on the
        // elements beyond
        auto beyond = [&](MVertex *a) {
          auto it = _onTriangle.find(sortedFace(a, h.r, h.s));
          return it != _onTriangle.end() && it->second[1];
        };
        if(!beyond(h.p) || !beyond(h.q)) return BLOCKED;
        replace(shell, {});
        return 1;
      }
      std::vector<std::array<MVertex *, 4> > best, tets;
      double bestQuality = -1.;
      for(const auto &triangulation : triangulations(n)) {
        tets.clear();
        double sum = 0., quality = 1.;
        bool valid = true;
        for(const auto &tri : triangulation) {
          for(MVertex *apex : {h.p, h.q}) {
            std::array<MVertex *, 4> v = {apex, ring[tri[0]], ring[tri[1]],
                                          ring[tri[2]]};
            double o = orient(v[0], v[1], v[2], v[3]);
            if(o == 0.) {
              valid = false;
              break;
            }
            if((o > 0. ? 1 : -1) != _orientation) std::swap(v[2], v[3]);
            sum += std::abs(o);
            double vol;
            quality = std::min(
              quality,
              qmTetrahedron::gamma(v[0]->x(), v[0]->y(), v[0]->z(), v[1]->x(),
                                   v[1]->y(), v[1]->z(), v[2]->x(), v[2]->y(),
                                   v[2]->z(), v[3]->x(), v[3]->y(), v[3]->z(),
                                   &vol));
            tets.push_back(v);
          }
          if(!valid) break;
        }
        // the same region exactly: no tetrahedron overlaps another
        if(!valid || std::abs(sum - target) > 1.e-9 * volume) continue;
        if(quality > bestQuality) {
          bestQuality = quality;
          best = tets;
        }
      }
      // no tetrahedron worse than the worst one replaced and than 0.05
      if(best.empty() || bestQuality < std::min(worst, _minQuality))
        return INVALID;
      replace(shell, best);
      return n;
    }

    void replace(const std::vector<MTetrahedron *> &shell,
                 const std::vector<std::array<MVertex *, 4> > &tets)
    {
      for(MTetrahedron *t : shell) {
        removeTriangles(t);
        _removed.insert(t);
        for(int k = 0; k < 4; k++) {
          const long m = t->getVertex(k)->getIndex();
          if(m < 0) continue;
          std::vector<MElement *> &around = _elements[m];
          around.erase(std::find(around.begin(), around.end(), t));
        }
      }
      for(const auto &v : tets) {
        MTetrahedron *t = new MTetrahedron(v[0], v[1], v[2], v[3]);
        addTriangles(t, 4, tetFace);
        _added.push_back(t);
        for(int k = 0; k < 4; k++) {
          const long m = t->getVertex(k)->getIndex();
          if(m >= 0) _elements[m].push_back(t);
        }
      }
    }

    // the quality of an element in the flattening: the gamma of the
    // tetrahedra, negative if inverted, the SICN of the others
    double quality(MElement *e) const
    {
      if(e->getType() != TYPE_TET) return e->minSICNShapeMeasure();
      const double o = orient(e->getVertex(0), e->getVertex(1),
                              e->getVertex(2), e->getVertex(3));
      if(o == 0. || (o > 0. ? 1 : -1) != _orientation) return -1.;
      return e->gammaShapeMeasure();
    }

    // the vertex at the other end of the edge of the cell of h leaving its
    // face from v
    MVertex *inwardVertex(const HangingQuad &h, MVertex *v) const
    {
      for(int k = 0; k < h.owner->getNumEdges(); k++) {
        const MEdge edge = h.owner->getEdge(k);
        MVertex *w = edge.getVertex(0) == v ? edge.getVertex(1) :
                     edge.getVertex(1) == v ? edge.getVertex(0) :
                                              nullptr;
        if(w && w != h.p && w != h.q && w != h.r && w != h.s) return w;
      }
      return nullptr;
    }

    // The warping of the face of h reversed: p and q moved out of its cell
    // and r and s into it, along the edges of the cell leaving the face, by
    // the smallest part t <= 1/4 of the mean edge of the face making the
    // trihedron positive (with a margin), if the elements around them keep 80%
    // of the quality of their worst one, and do not go under 0.05 if it is
    // above, and the other trihedra of their vertices do not become negative
    bool shift(std::size_t i,
               const std::vector<std::vector<MElement *> > &elements,
               const std::vector<std::vector<std::size_t> > &quadsOf)
    {
      const HangingQuad h = _quads[i];
      MVertex *vs[4] = {h.p, h.q, h.r, h.s};
      const double side[4] = {-1., -1., 1., 1.};
      SPoint3 x0[4];
      SVector3 dir[4];
      bool movable[4], any = false;
      for(int k = 0; k < 4; k++) {
        x0[k] = vs[k]->point();
        MVertex *w = vs[k]->getIndex() >= 0 ? inwardVertex(h, vs[k]) : nullptr;
        movable[k] = w != nullptr;
        if(!w) continue;
        dir[k] = SVector3(w->x() - x0[k].x(), w->y() - x0[k].y(),
                          w->z() - x0[k].z());
        dir[k].normalize();
        any = true;
      }
      if(!any) return false;
      const double L = (h.p->distance(h.r) + h.r->distance(h.q) +
                        h.q->distance(h.s) + h.s->distance(h.p)) / 4.;
      // the floors of the elements around the vertices, and their trihedra
      // not negative
      double floor[4] = {0., 0., 0., 0.};
      std::vector<std::size_t> fine;
      for(int k = 0; k < 4; k++) {
        if(!movable[k]) continue;
        const long m = vs[k]->getIndex();
        double worst = 1.;
        for(MElement *e : elements[m]) worst = std::min(worst, quality(e));
        floor[k] = std::max(.8 * worst, std::min(worst, _minQuality));
        for(std::size_t j : quadsOf[m])
          if(j != i && trihedronVolume(_quads[j]) >= -_flat) fine.push_back(j);
      }
      auto place = [&](double t) {
        for(int k = 0; k < 4; k++) {
          if(!movable[k]) continue;
          const double d = side[k] * t * L;
          vs[k]->x() = x0[k].x() + d * dir[k].x();
          vs[k]->y() = x0[k].y() + d * dir[k].y();
          vs[k]->z() = x0[k].z() + d * dir[k].z();
        }
      };
      auto valid = [&]() {
        for(int k = 0; k < 4; k++) {
          if(!movable[k]) continue;
          for(MElement *e : elements[vs[k]->getIndex()]) {
            const double w = quality(e);
            if(!(w > 0. && w >= floor[k])) return false;
          }
        }
        for(std::size_t j : fine)
          if(trihedronVolume(_quads[j]) < -_flat) return false;
        return true;
      };
      const double tMax = .25;
      place(tMax);
      if(trihedronVolume(h) >= 0.) {
        double lo = 0., hi = tMax;
        for(int it = 0; it < 12; it++) {
          const double mid = .5 * (lo + hi);
          place(mid);
          if(trihedronVolume(h) >= 0.) hi = mid;
          else lo = mid;
        }
        for(double t : {std::min(tMax, 1.25 * hi), hi}) {
          place(t);
          if(trihedronVolume(h) >= 0. && valid()) return true;
        }
      }
      place(0.);
      return false;
    }

    // The faces moved toward their mean plane: each of their vertices inside
    // the region, as far as (a step of 1, 1/2, 1/4, 1/8 of the way) the
    // elements around it stay valid, keeping 80% of the quality of their
    // worst one, and not going under 0.05 if it is above, and the other
    // trihedra of the vertex do not become negative
    void flatten(const std::vector<std::size_t> &list, Statistics &stats)
    {
      const std::vector<std::vector<MElement *> > &elements = _elements;
      const std::vector<std::vector<std::size_t> > &quadsOf = _quadsOf;
      for(std::size_t i : list) {
        const HangingQuad h = _quads[i];
        if(shift(i, elements, quadsOf)) {
          stats.shifted++;
          continue;
        }
        double c[3] = {0., 0., 0.};
        for(MVertex *v : {h.p, h.q, h.r, h.s}) {
          c[0] += v->x() / 4.;
          c[1] += v->y() / 4.;
          c[2] += v->z() / 4.;
        }
        // the normal of the mean plane, from the diagonals
        const SVector3 d1(h.q->x() - h.p->x(), h.q->y() - h.p->y(),
                          h.q->z() - h.p->z());
        const SVector3 d2(h.s->x() - h.r->x(), h.s->y() - h.r->y(),
                          h.s->z() - h.r->z());
        SVector3 nrm = crossprod(d1, d2);
        if(nrm.norm() == 0.) continue;
        nrm.normalize();
        for(MVertex *v : {h.p, h.q, h.r, h.s}) {
          const long m = v->getIndex();
          if(m < 0) continue;
          const std::vector<std::size_t> &quadsOfV = quadsOf[m];
          const SPoint3 x0 = v->point();
          // the elements around v, the worst first: a step is rejected at
          // the first one under the floor
          std::vector<std::pair<double, MElement *> > around;
          for(MElement *e : elements[m]) around.push_back({quality(e), e});
          std::sort(around.begin(), around.end(),
                    [](const std::pair<double, MElement *> &a,
                       const std::pair<double, MElement *> &b) {
                      return a.first < b.first;
                    });
          const double dist = (x0.x() - c[0]) * nrm.x() +
                              (x0.y() - c[1]) * nrm.y() +
                              (x0.z() - c[2]) * nrm.z();
          const double worst = around.empty() ? 1. : around[0].first;
          const double floor =
            std::max(.8 * worst, std::min(worst, _minQuality));
          std::vector<bool> fine;
          for(std::size_t j : quadsOfV)
            fine.push_back(trihedronVolume(_quads[j]) >= -_flat);
          for(double step : {1., .5, .25, .125}) {
            v->x() = x0.x() - step * dist * nrm.x();
            v->y() = x0.y() - step * dist * nrm.y();
            v->z() = x0.z() - step * dist * nrm.z();
            bool ok = true;
            for(std::size_t k = 0; k < around.size() && ok; k++) {
              const double w = quality(around[k].second);
              ok = w > 0. && w >= floor;
            }
            for(std::size_t k = 0; k < quadsOfV.size() && ok; k++)
              if(fine[k] && quadsOfV[k] != i)
                ok = trihedronVolume(_quads[quadsOfV[k]]) >= -_flat;
            if(ok) break;
            v->x() = x0.x();
            v->y() = x0.y();
            v->z() = x0.z();
          }
        }
        if(trihedronVolume(h) >= -_flat)
          stats.flattened++;
        else
          stats.left++;
      }
    }
  };

} // namespace

// The volume of a first-order hex, exact as the Jacobian determinant of the
// trilinear map has degree 2 along each direction: 2x2x2 Gauss points, in
// closed form (MElement::getVolume takes 27 generic Jacobian evaluations)
static double hexVolume(const MHexahedron *h)
{
  static const double s[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1},
                                 {-1, 1, -1},  {-1, -1, 1}, {1, -1, 1},
                                 {1, 1, 1},    {-1, 1, 1}};
  const double g = 1. / std::sqrt(3.);
  double vol = 0.;
  for(int q = 0; q < 8; q++) {
    const double p[3] = {s[q][0] * g, s[q][1] * g, s[q][2] * g};
    double J[3][3] = {{0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.}};
    for(int i = 0; i < 8; i++) {
      const MVertex *v = h->getVertex(i);
      const double x[3] = {v->x(), v->y(), v->z()};
      const double a = 1. + s[i][0] * p[0], b = 1. + s[i][1] * p[1],
                   c = 1. + s[i][2] * p[2];
      const double d[3] = {s[i][0] * b * c / 8., s[i][1] * a * c / 8.,
                           s[i][2] * a * b / 8.};
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) J[k][l] += x[k] * d[l];
    }
    vol += J[0][0] * (J[1][1] * J[2][2] - J[1][2] * J[2][1]) -
           J[0][1] * (J[1][0] * J[2][2] - J[1][2] * J[2][0]) +
           J[0][2] * (J[1][0] * J[2][1] - J[1][1] * J[2][0]);
  }
  return vol;
}

// The vertices numbered in the order in which the tets first reach them, the
// number kept in MVertex::_index (-1 for the vertices of the region that no
// tet reaches, if any, and 0 in the triangles for the ones of the boundary)
static void createMeshStore(GRegion *gr, HXTCombine::MeshStore &ms,
                            std::vector<MVertex *> &c2v)
{
  const std::vector<MTetrahedron *> &tets = gr->tetrahedra;
  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces)
    for(auto t : gf->triangles)
      for(std::size_t i = 0; i < 3; i++) t->getVertex(i)->setIndex(-1);
  for(auto v : gr->mesh_vertices) v->setIndex(-1);
  for(auto t : tets)
    for(std::size_t i = 0; i < 4; i++) t->getVertex(i)->setIndex(-1);
  c2v.clear();
  for(auto t : tets) {
    for(std::size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      if(v->getIndex() < 0) {
        v->setIndex(c2v.size());
        c2v.push_back(v);
      }
    }
  }

  const int64_t nv = c2v.size(), nt = tets.size();
  ms.vertices.resize(4 * nv);
  ms.tetCorners.resize(4 * nt);
#pragma omp parallel
  {
#pragma omp for schedule(static)
    for(int64_t i = 0; i < nv; i++) {
      ms.vertices[4 * i] = c2v[i]->x();
      ms.vertices[4 * i + 1] = c2v[i]->y();
      ms.vertices[4 * i + 2] = c2v[i]->z();
      ms.vertices[4 * i + 3] = 0.;
    }
#pragma omp for schedule(static)
    for(int64_t t = 0; t < nt; t++)
      for(std::size_t i = 0; i < 4; i++)
        ms.tetCorners[4 * t + i] = tets[t]->getVertex(i)->getIndex();
  }

  for(auto gf : faces) {
    for(auto t : gf->triangles) {
      ms.triangleColors.push_back(gf->tag());
      for(std::size_t i = 0; i < 3; i++)
        ms.triangleCorners.push_back(
          std::max(t->getVertex(i)->getIndex(), 0L));
    }
  }
  computeTetAdjacencies(ms);
}

void MakeFreePyramids(GRegion *gr)
{
  const double tPyramids = TimeOfDay(), cPyramids = Cpu();
  const std::size_t nPyr = makeFreePyramids(gr);
  AddMeshStageTime("combination: pyramids", TimeOfDay() - tPyramids,
                   Cpu() - cPyramids);
  Msg::Debug("%zu pyramids on hex/prism quad faces (%zu tets merged), "
             "%zu tets left",
             nPyr, 2 * nPyr, gr->tetrahedra.size());
}

void MakeTrihedraPositive(GRegion *gr, bool skipPyramids)
{
  const double t0 = TimeOfDay(), c0 = Cpu();
  PositiveTrihedra::Statistics st = PositiveTrihedra(gr, skipPyramids).run();
  AddMeshStageTime("positive trihedra", TimeOfDay() - t0, Cpu() - c0);
  Msg::Info("Region %d: %zu of %zu unmatched faces with negative trihedra: "
            "%zu swapped (1-5 tets: %zu %zu %zu %zu %zu), %zu left to "
            "pyramids, %zu shifted, %zu flattened, %zu left (swap blocked "
            "%zu, more than 5 tets %zu, no valid split %zu)",
            gr->tag(), st.negative, st.quads,
            st.swapped[1] + st.swapped[2] + st.swapped[3] + st.swapped[4] +
              st.swapped[5],
            st.swapped[1], st.swapped[2], st.swapped[3], st.swapped[4],
            st.swapped[5], st.pyramids, st.shifted, st.flattened, st.left,
            st.blocked, st.tooMany, st.invalid);
}

int meshCombine3D(GRegion *gr, const CombineFrames *frames)
{
  if(gr->tetrahedra.empty()) {
    Msg::Error("Region %d has no tetrahedra to combine (Delaunay meshing "
               "likely failed for this region)",
               gr->tag());
    return -1;
  }

  const double tStart = TimeOfDay(), cStart = Cpu();
  Msg::Debug("Creating Mesh Wrapper for region %d", gr->tag());
  double volHex = 0, volTet = 0;
  int numHex = 0, numTet = 0;

  std::vector<MVertex *> c2v;
  HXTCombine::MeshStore ms;
  createMeshStore(gr, ms, c2v);
  // ----------------- I D E N T I F Y   H E X E S
  // -------------------------------------
  Msg::Debug("Identifying Hexes for region %d", gr->tag());
  HXTCombine::TetMeshForCombining tm4c(&ms);
  HXTCombine::HXTCombineCellStore ccs(tm4c);
  double minQuality = CTX::instance()->mesh.recombine3DMinimumQuality;

  bool enablePrisms = CTX::instance()->mesh.recombine3DPrisms;

  // the candidate cells are proposed along the frames of the point insertion
  std::vector<double> axes(9 * c2v.size(), 0.), sizes(c2v.size(), 0.);
  std::size_t nbFramed = 0;
  if(frames) {
    for(std::size_t i = 0; i < c2v.size(); i++) {
      auto it = frames->find(c2v[i]);
      if(it == frames->end()) continue;
      std::copy(it->second.axes, it->second.axes + 9, &axes[9 * i]);
      sizes[i] = it->second.size;
      nbFramed++;
    }
  }

  AddMeshStageTime("combination: setup", TimeOfDay() - tStart, Cpu() - cStart);
  const double cSelect = Cpu();
  HXTCombine::FrameSelectionStatistics stats;
  ccs.selectAlongFrames(minQuality, axes, sizes, enablePrisms, &stats);
  // the CPU time with the clock of the others, shared as std::clock shares
  // it (it counts the system time as well)
  const double cpu = Cpu() - cSelect;
  const double share =
    stats.cpuCandidates + stats.cpuSelection > 0. ?
      stats.cpuCandidates / (stats.cpuCandidates + stats.cpuSelection) :
      0.5;
  AddMeshStageTime("combination: candidates", stats.wallCandidates,
                   share * cpu);
  AddMeshStageTime("combination: selection", stats.wallSelection,
                   (1. - share) * cpu);
  Msg::Debug("%zu Hexes proposed along the frames of %zu vertices, %zu "
             "selected", stats.nbProposedHexes, nbFramed,
             stats.nbSelectedProposedHexes);
  Msg::Debug("%zu Hexes proposed around the %zu vertices left in tets",
             stats.nbResidualHexes, stats.nbFreeVertices);
  if(enablePrisms)
    Msg::Debug("%zu Prisms proposed on the %zu tets left",
               stats.nbProposedPrisms, stats.nbFreeTets);
  const double tOutput = TimeOfDay(), cOutput = Cpu();
  Msg::Debug("%d Hexes selected", ccs.nbSelectedHexes());
  if(enablePrisms)
    Msg::Debug("%d Prisms selected", ccs.nbSelectedPrisms());

  // ----------------- C R E A T I N G  V O L U M E    E L E M E N T S
  // --------------------
  for(auto t : gr->tetrahedra) delete t;
  gr->tetrahedra.clear();

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  std::set<MFace, MFaceLessThan> faceToDelete;

  // only a cell face with its 4 vertices on the surface meshes can be made of
  // 2 boundary triangles: the others are not searched
  std::vector<char> onBoundary(c2v.size());
  for(std::size_t i = 0; i < c2v.size(); i++) {
    GEntity *ge = c2v[i]->onWhat();
    onBoundary[i] = ge && ge->dim() < 3;
  }
  auto faceOnBoundary = [&](const HXTCombine::HXTCombineCell &c,
                            int (*face)(const int, const int), int l) {
    for(int j = 0; j < 4; j++)
      if(!onBoundary[c.vertexes[face(l, j)]]) return false;
    return true;
  };

  // the vertices of the elements, by their number (MVertex::_index)
  std::vector<char> used(c2v.size(), 0);

  for(size_t k = 0; k < ccs.hexes().size(); k++) {
    if(ccs.selectedHexes()[k]) {
      MVertex *v0 = c2v[ccs.hexes()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.hexes()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.hexes()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.hexes()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.hexes()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.hexes()[k].vertexes[5]];
      MVertex *v6 = c2v[ccs.hexes()[k].vertexes[6]];
      MVertex *v7 = c2v[ccs.hexes()[k].vertexes[7]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      used[v4->getIndex()] = 1;
      used[v5->getIndex()] = 1;
      used[v6->getIndex()] = 1;
      used[v7->getIndex()] = 1;
      MHexahedron *h = new MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7);
      volHex += hexVolume(h);
      numHex++;
      gr->hexahedra.push_back(h);
      for(int l = 0; l < 6; l++) {
        if(!faceOnBoundary(ccs.hexes()[k], MHexahedron::faces_hexa, l))
          continue;
        MFace f = h->getFace(l);
        MFace f012(f.getVertex(0), f.getVertex(1), f.getVertex(2));
        MFace f230(f.getVertex(2), f.getVertex(3), f.getVertex(0));
        GFace *gfound012 = findInFaceSearchStructure(f012, search);
        GFace *gfound230 = findInFaceSearchStructure(f230, search);
        if(gfound012 && gfound230 && gfound012 == gfound230) {
          gfound012->quadrangles.push_back(new MQuadrangle(
            f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
          faceToDelete.insert(f012);
          faceToDelete.insert(f230);
        }
        else {
          MFace f013(f.getVertex(0), f.getVertex(1), f.getVertex(3));
          MFace f312(f.getVertex(3), f.getVertex(1), f.getVertex(2));
          GFace *gfound013 = findInFaceSearchStructure(f013, search);
          GFace *gfound312 = findInFaceSearchStructure(f312, search);
          if(gfound013 && gfound312 && gfound013 == gfound312) {
            gfound013->quadrangles.push_back(new MQuadrangle(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
            faceToDelete.insert(f013);
            faceToDelete.insert(f312);
          }
        }
      }
    }
  }
  if(enablePrisms) {
    for(size_t k = 0; k < ccs.prisms().size(); k++) {
      if(!ccs.selectedPrisms()[k]) continue;
      MVertex *v0 = c2v[ccs.prisms()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.prisms()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.prisms()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.prisms()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.prisms()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.prisms()[k].vertexes[5]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      used[v4->getIndex()] = 1;
      used[v5->getIndex()] = 1;
      MPrism *p = new MPrism(v0, v1, v2, v3, v4, v5);
      gr->prisms.push_back(p);
      // Faces 0 and 1 are the 2 triangular caps: they coincide with
      // existing surface triangles already in place, nothing to
      // reconcile. Faces 2-4 are the 3 quad facets: same
      // diagonal-pair-of-triangles-to-quadrangle reconciliation as for
      // hexahedra above.
      for(int l = 2; l < 5; l++) {
        if(!faceOnBoundary(ccs.prisms()[k], MPrism::faces_prism, l)) continue;
        MFace f = p->getFace(l);
        MFace f012(f.getVertex(0), f.getVertex(1), f.getVertex(2));
        MFace f230(f.getVertex(2), f.getVertex(3), f.getVertex(0));
        GFace *gfound012 = findInFaceSearchStructure(f012, search);
        GFace *gfound230 = findInFaceSearchStructure(f230, search);
        if(gfound012 && gfound230 && gfound012 == gfound230) {
          gfound012->quadrangles.push_back(new MQuadrangle(
            f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
          faceToDelete.insert(f012);
          faceToDelete.insert(f230);
        }
        else {
          MFace f013(f.getVertex(0), f.getVertex(1), f.getVertex(3));
          MFace f312(f.getVertex(3), f.getVertex(1), f.getVertex(2));
          GFace *gfound013 = findInFaceSearchStructure(f013, search);
          GFace *gfound312 = findInFaceSearchStructure(f312, search);
          if(gfound013 && gfound312 && gfound013 == gfound312) {
            gfound013->quadrangles.push_back(new MQuadrangle(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
            faceToDelete.insert(f013);
            faceToDelete.insert(f312);
          }
        }
      }
    }
  }

  for(unsigned int k = 0; k < ms.tetCorners.size() / 4; k++) {
    if(ccs.selectedTets()[k]) {
      MVertex *v0 = c2v[ms.tetCorners[4 * k]];
      MVertex *v1 = c2v[ms.tetCorners[4 * k + 1]];
      MVertex *v2 = c2v[ms.tetCorners[4 * k + 2]];
      MVertex *v3 = c2v[ms.tetCorners[4 * k + 3]];
      used[v0->getIndex()] = 1;
      used[v1->getIndex()] = 1;
      used[v2->getIndex()] = 1;
      used[v3->getIndex()] = 1;
      MTetrahedron *tet = new MTetrahedron(v0, v1, v2, v3);
      gr->tetrahedra.push_back(tet);
      volTet += tet->getVolume();
      numTet++;
    }
  }

  {
    std::vector<MVertex *> vr;
    for(auto v : gr->mesh_vertices) {
      if(v->getIndex() >= 0 && used[v->getIndex()])
        vr.push_back(v);
      else {
        delete v;
      }
    }
    Msg::Debug("%d vertices removed by the combination",
               (int)(gr->mesh_vertices.size() - vr.size()));
    gr->mesh_vertices = vr;
  }
  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces) {
    std::vector<MTriangle *> temp;
    for(auto t : gf->triangles) {
      if(faceToDelete.find(t->getFace(0)) == faceToDelete.end()) {
        temp.push_back(t);
      }
      else
        delete t;
    }
    gf->triangles = temp;
  }

  Msg::Debug("Volume Hex %12.5E --- Volume Tet %12.5E --- Percentage Vol Hex "
             "%12.5E", volHex, volTet, 100 * volHex / (volHex + volTet));
  Msg::Debug("Number Hex %12d --- Number Tet %12d --- Percentage Num Hex "
             "%12.5E", numHex, numTet,
             100 * (double)numHex / (numHex + numTet));

  AddMeshStageTime("combination: output", TimeOfDay() - tOutput,
                   Cpu() - cOutput);

  // the trihedra made positive while the faces where the pyramids go are
  // still on tetrahedra, which a swap can replace: the pyramids are made
  // after the smoothing and the second correction (see Generator.cpp)
  if(CTX::instance()->mesh.recombine3DPositiveTrihedra) {
    MakeTrihedraPositive(gr);
  }
  else if(CTX::instance()->mesh.recombine3DPyramids)
    MakeFreePyramids(gr);

  double volPrism = 0.;
  for(MPrism *p : gr->prisms) volPrism += std::abs(p->getVolume());
  Msg::Info("Region %d: %d hexahedra (%.1f%% of the volume), %zu prisms, %zu "
            "pyramids, %zu tetrahedra (Wall %gs)",
            gr->tag(), numHex, 100. * volHex / (volHex + volPrism + volTet),
            gr->prisms.size(), gr->pyramids.size(), gr->tetrahedra.size(),
            TimeOfDay() - tStart);

  return 0;
}
#else

int meshCombine3D(GRegion *gr, const CombineFrames *frames)
{
  Msg::Warning(
    "Gmsh must be compiled with HXT to enable hybrid mesh generation");
  return -1;
}

void MakeTrihedraPositive(GRegion *gr, bool skipPyramids) {}

void MakeFreePyramids(GRegion *gr) {}


#endif


// The quadrangular faces of the hexahedra, prisms and pyramids with two
// triangular faces on their other side get a trihedron, as the original
// version, without looking at all the faces of all the elements: such a face
// has its 4 vertices on elements with triangular faces, and only the faces
// meeting that condition (all the occurrences of a face do), and the
// triangles of the unmatched ones, are counted
bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm)
{
  // the vertices of the elements with triangular faces, marked 1 in
  // MVertex::_index (the other vertices of the quadrangular faces 0)
  bool anyTriangle = false;
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    auto mark = [](MElement *e, long m) {
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++)
        e->getVertex(k)->setIndex(m);
    };
    for(MHexahedron *e : gr->hexahedra) mark(e, 0);
    for(MTetrahedron *e : gr->tetrahedra) mark(e, 0);
    for(MPyramid *e : gr->pyramids) mark(e, 0);
    for(MPrism *e : gr->prisms) mark(e, 0);
    for(MTrihedron *e : gr->trihedra) mark(e, 0);
  }
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    auto mark = [&anyTriangle](MElement *e) {
      anyTriangle = true;
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++)
        e->getVertex(k)->setIndex(1);
    };
    for(MTetrahedron *e : gr->tetrahedra) mark(e);
    for(MPyramid *e : gr->pyramids) mark(e);
    for(MPrism *e : gr->prisms) mark(e);
    for(MTrihedron *e : gr->trihedra) mark(e);
  }
  if(!anyTriangle) return true;

  // the occurrences of the quadrangular faces with their 4 vertices there,
  // with the vertices in the order of their element, sorted by face (and
  // order of occurrence)
  struct QuadOccurrence {
    SortedFace key;
    MVertex *v[4];
    GRegion *gr;
    std::size_t rank;
  };
  std::vector<QuadOccurrence> quads;
  auto addQuads = [&](MElement *e, int nbFaces,
                      int (*face)(const int, const int), GRegion *gr) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) < 0) continue; // a triangle
      QuadOccurrence q;
      bool candidate = true;
      for(int j = 0; j < 4 && candidate; j++) {
        q.v[j] = e->getVertex(face(f, j));
        candidate = q.v[j]->getIndex() == 1;
      }
      if(!candidate) continue;
      q.key = sortedFace(q.v[0], q.v[1], q.v[2], q.v[3]);
      q.gr = gr;
      q.rank = quads.size();
      quads.push_back(q);
    }
  };
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    for(MHexahedron *e : gr->hexahedra)
      addQuads(e, 6, MHexahedron::faces_hexa, gr);
    for(MPrism *e : gr->prisms) addQuads(e, 5, MPrism::faces_prism, gr);
    for(MPyramid *e : gr->pyramids) addQuads(e, 5, MPyramid::faces_pyramid, gr);
    for(MTrihedron *e : gr->trihedra)
      addQuads(e, 3, MTrihedron::faces_trihedron, gr);
  }
  std::sort(quads.begin(), quads.end(),
            [](const QuadOccurrence &x, const QuadOccurrence &y) {
              for(int i = 0; i < 4; i++)
                if(x.key.v[i] != y.key.v[i]) return x.key.v[i] < y.key.v[i];
              return x.rank < y.rank;
            });

  // the faces of the surface meshes bounding the regions (as
  // buildFaceSearchStructure)
  std::unordered_set<SortedFace, SortedFaceHash> boundary;
  {
    std::set<GFace *> faces;
    for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
      std::vector<GFace *> f = (*rit)->faces();
      faces.insert(f.begin(), f.end());
    }
    for(GFace *gf : faces) {
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        const std::size_t n = e->getNumPrimaryVertices();
        if(n == 3)
          boundary.insert(
            sortedFace(e->getVertex(0), e->getVertex(1), e->getVertex(2)));
        else if(n == 4)
          boundary.insert(sortedFace(e->getVertex(0), e->getVertex(1),
                                     e->getVertex(2), e->getVertex(3)));
      }
    }
  }

  // the unmatched ones (an odd number of occurrences, the last one kept, as
  // the original version), not on the boundary, in the order of the original
  // version (MFaceLessThan: by sorted vertex numbers), and the triangles of
  // their two splits
  struct Hanging {
    std::size_t num[4];
    const QuadOccurrence *q;
  };
  std::vector<Hanging> hanging;
  std::unordered_map<SortedFace, int, SortedFaceHash> triangles;
  for(std::size_t i = 0; i < quads.size();) {
    std::size_t j = i + 1;
    while(j < quads.size() && quads[j].key == quads[i].key) j++;
    const QuadOccurrence &q = quads[j - 1];
    if((j - i) % 2 && !boundary.count(q.key)) {
      Hanging h;
      for(int k = 0; k < 4; k++) h.num[k] = q.v[k]->getNum();
      std::sort(h.num, h.num + 4);
      h.q = &q;
      hanging.push_back(h);
      MVertex *const *v = q.v;
      triangles[sortedFace(v[0], v[1], v[2])];
      triangles[sortedFace(v[2], v[3], v[0])];
      triangles[sortedFace(v[0], v[1], v[3])];
      triangles[sortedFace(v[3], v[1], v[2])];
    }
    i = j;
  }
  std::sort(hanging.begin(), hanging.end(),
            [](const Hanging &x, const Hanging &y) {
              return std::lexicographical_compare(x.num, x.num + 4, y.num,
                                                  y.num + 4);
            });

  // their occurrences as faces of the elements
  auto addTriangles = [&](MElement *e, int nbFaces,
                          int (*face)(const int, const int)) {
    for(int f = 0; f < nbFaces; f++) {
      if(face(f, 3) >= 0) continue; // a quadrangle
      auto it = triangles.find(sortedFace(e->getVertex(face(f, 0)),
                                          e->getVertex(face(f, 1)),
                                          e->getVertex(face(f, 2))));
      if(it != triangles.end()) it->second++;
    }
  };
  auto tetFace = [](const int f, const int j) {
    return j < 3 ? MTetrahedron::faces_tetra(f, j) : -1;
  };
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    for(MTetrahedron *e : gr->tetrahedra) addTriangles(e, 4, tetFace);
    for(MPyramid *e : gr->pyramids) addTriangles(e, 5, MPyramid::faces_pyramid);
    for(MPrism *e : gr->prisms) addTriangles(e, 5, MPrism::faces_prism);
    for(MTrihedron *e : gr->trihedra)
      addTriangles(e, 3, MTrihedron::faces_trihedron);
  }
  // unmatched and not on the boundary
  auto hangingTriangle = [&](MVertex *a, MVertex *b, MVertex *c) {
    const SortedFace f = sortedFace(a, b, c);
    auto it = triangles.find(f);
    return it != triangles.end() && it->second % 2 && !boundary.count(f);
  };

  int nbTrihedraCreated = 0;
  for(auto &h : hanging) {
    MVertex *const *v = h.q->v;
    if(hangingTriangle(v[0], v[1], v[2]) && hangingTriangle(v[2], v[3], v[0])) {
      h.q->gr->trihedra.push_back(new MTrihedron(v[3], v[0], v[1], v[2]));
      nbTrihedraCreated++;
    }
    else if(hangingTriangle(v[0], v[1], v[3]) &&
            hangingTriangle(v[3], v[1], v[2])) {
      h.q->gr->trihedra.push_back(new MTrihedron(v[0], v[1], v[2], v[3]));
      nbTrihedraCreated++;
    }
    else
      Msg::Warning("MakeMeshConformal: wrong mesh topology, quad verts %zu %zu "
                   "%zu %zu",
                   v[0]->getNum(), v[1]->getNum(), v[2]->getNum(),
                   v[3]->getNum());
  }
  Msg::Debug("%d hanging quadrangular faces, %d trihedra created",
             (int)hanging.size(), nbTrihedraCreated);
  return true;
}
