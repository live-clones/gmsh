// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Quality improvement of the pdel3d mesh by edge removal and node
// relocation, in parallel on partitions of the Moore curve (after HXT's
// hxt_tetOpti.c): the bad tets are sorted along the curve and shared out
// between the threads, and a modification whose cavity leaves the thread's
// piece of the curve is retried in a later round on a shifted curve.

#include <algorithm>
#include <atomic>
#include <cmath>
#include "pdel3d.h"
#include "pdel3dInternal.h"
#include "meshGRegionLocalMeshMod.h"
#include "GmshMessage.h"
#include "OS.h"

namespace pdel3d {

  namespace {

    // gmsh's gamma quality (3 inradius / circumradius) of the tet (p0, p1,
    // p2, p3) whose orientation determinant is det (negative when valid);
    // -1 for an inverted or flat tet
    double gammaQuality(const double *p0, const double *p1, const double *p2,
                        const double *p3, double det)
    {
      if(det >= 0.) return -1.;
      const double volume = -det / 6.;
      auto sq = [](const double *a, const double *b) {
        const double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return dx * dx + dy * dy + dz * dz;
      };
      const double la = sq(p1, p0), lb = sq(p2, p0), lc = sq(p3, p0);
      const double lA = sq(p3, p2), lB = sq(p3, p1), lC = sq(p2, p1);
      const double lalA = std::sqrt(la * lA), lblB = std::sqrt(lb * lB),
                   lclC = std::sqrt(lc * lC);
      const double insideSqrt = (lalA + lblB + lclC) * (lalA + lblB - lclC) *
                                (lalA - lblB + lclC) * (-lalA + lblB + lclC);
      if(insideSqrt <= 0.) return 0.;
      const double partR = std::sqrt(insideSqrt) / 24.;
      auto area = [](const double *a, const double *b, const double *c) {
        const double u[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
        const double v[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
        const double n[3] = {u[1] * v[2] - u[2] * v[1],
                             u[2] * v[0] - u[0] * v[2],
                             u[0] * v[1] - u[1] * v[0]};
        return 0.5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
      };
      const double s = area(p0, p1, p2) + area(p0, p2, p3) + area(p0, p1, p3) +
                       area(p1, p2, p3);
      const double rho = 9. * volume / s;
      return rho * volume / partR;
    }

    inline double tetQuality(const Mesh &m, vIdx a, vIdx b, vIdx c, vIdx d)
    {
      const double *pa = &m.xyz[4 * a], *pb = &m.xyz[4 * b],
                   *pc = &m.xyz[4 * c], *pd = &m.xyz[4 * d];
      return gammaQuality(pa, pb, pc, pd, orient3dFast(pa, pb, pc, pd));
    }

    enum Status { OK, CONFLICT, NOT_BETTER, CONSTRAINED };

    struct Local {
      std::vector<tIdx> deleted; // free slots
      Partition partition;
      std::vector<tIdx> cavity, visited;
      std::size_t swaps = 0, relocations = 0, conflicts = 0;
      std::size_t invalidSwaps = 0;
      bool noSpace = false;
    };

    class Optimizer {
    public:
      Mesh &m;
      const OptimizeOptions &opt;
      std::vector<double> qual; // per tet slot
      std::vector<std::uint8_t> fixedV;
      std::atomic<std::size_t> ntet;
      std::size_t cap;
      static constexpr std::size_t BLOCK = 1024;

      Optimizer(Mesh &_m, const OptimizeOptions &_opt)
        : m(_m), opt(_opt), ntet(_m.ntet), cap(_m.tetCapacity())
      {
      }

      bool inVolume(tIdx t) const
      { return !m.isDeleted(t) && m.color[t] < opt.numVolumes; }

      double computeQuality(tIdx t) const
      {
        const vIdx *n = &m.node[4 * t];
        return tetQuality(m, n[0], n[1], n[2], n[3]);
      }

      // a free slot for a new tet
      // make sure n free slots are available before a cavity is modified
      bool ensureFreeSlots(Local &L, std::size_t n)
      {
        while(L.deleted.size() < n) {
          const std::size_t first = ntet.fetch_add(BLOCK);
          const std::size_t last = std::min(first + BLOCK, cap);
          if(first >= last) {
            L.noSpace = true;
            return false;
          }
          for(std::size_t t = first; t < last; t++) {
            m.flag[t] = F_DELETED;
            L.deleted.push_back((tIdx)t);
          }
        }
        return true;
      }

      tIdx newSlot(Local &L)
      {
        const tIdx t = L.deleted.back();
        L.deleted.pop_back();
        return t;
      }

      // ---- edge removal ----

      // the tets around the edge e of tet t, in order; ring[i] is the vertex
      // shared by tets i and i + 1
      struct EdgeCavity {
        vIdx a, b; // the edge
        int n = 0;
        tIdx tet[7];
        vIdx ring[7];
        // the neighbors across the facets containing a (opposite b) and b
        // (opposite a), and the constraint of those facets
        tRef outA[7], outB[7];
        std::uint16_t flagA[7], flagB[7];
      };

      Status buildEdgeCavity(Local &L, tIdx t, int e, EdgeCavity &C)
      {
        if(m.flag[t] & (1 << e)) return CONSTRAINED; // constrained edge
        unsigned na, nb;
        edgeNodes(e, na, nb);
        C.a = m.node[4 * t + na];
        C.b = m.node[4 * t + nb];
        unsigned inF, outF;
        edgeFacets(e, inF, outF);
        const Partition &P = L.partition;
        if(outOfPartition(m, C.a, P) || outOfPartition(m, C.b, P))
          return CONFLICT;
        C.n = 0;
        tIdx cur = t;
        do {
          if(C.n == 7) return NOT_BETTER; // no pattern beyond 7
          if(!inVolume(cur)) return CONSTRAINED;
          const std::uint16_t f = m.flag[cur];
          // the facets containing the edge must not be constrained: the edge
          // would be on a surface
          if(f & ((F_FACET0 << inF) | (F_FACET0 << outF))) return CONSTRAINED;
          const vIdx *n = &m.node[4 * cur];
          const vIdx r = n[inF]; // shared with the next tet
          if(outOfPartition(m, r, P)) return CONFLICT;
          // facets opposite a and b
          unsigned fa = 0, fb = 0;
          for(unsigned k = 0; k < 4; k++) {
            if(n[k] == C.a) fa = k;
            if(n[k] == C.b) fb = k;
          }
          C.tet[C.n] = cur;
          C.ring[C.n] = r;
          // the facet containing a is the one opposite b, and conversely
          C.outA[C.n] = m.neigh[4 * cur + fb];
          C.outB[C.n] = m.neigh[4 * cur + fa];
          C.flagA[C.n] = (f & (F_FACET0 << fb)) ? 1 : 0;
          C.flagB[C.n] = (f & (F_FACET0 << fa)) ? 1 : 0;
          C.n++;
          const tRef rf = m.neigh[4 * cur + outF];
          cur = rf >> 2;
          inF = rf & 3;
          const vIdx *nn = &m.node[4 * cur];
          for(outF = 0; outF < 3; outF++)
            if(nn[outF] == r) break;
        } while(cur != t);
        if(C.n < 3) return NOT_BETTER;
        // a consistent mesh gives distinct ring vertices and outer tets that
        // share the facets: anything else means the mesh is corrupted
        for(int i = 0; i < C.n; i++) {
          bool bad = C.ring[i] == C.a || C.ring[i] == C.b;
          for(int j = 0; j < i && !bad; j++) bad = C.ring[i] == C.ring[j];
          for(int side = 0; side < 2 && !bad; side++) {
            const tRef out = side ? C.outB[i] : C.outA[i];
            const tIdx o = out >> 2;
            if(out == NO_ADJ || o >= cap || m.isDeleted(o)) {
              bad = true;
              break;
            }
            const vIdx x = side ? C.b : C.a, rp = C.ring[(i + C.n - 1) % C.n],
                       r = C.ring[i];
            int found = 0;
            for(unsigned k = 0; k < 4; k++) {
              if(k == (out & 3)) continue;
              const vIdx v = m.node[4 * o + k];
              found += (v == x) + (v == rp) + (v == r);
            }
            bad = found != 3;
          }
          if(bad) {
            static int reports = 0;
            if(reports++ < 5) {
              Msg::Warning("Inconsistent ring of %d tets around edge %u-%u of "
                           "tet %u (ring vertex %d: %u, outA %u outB %u)",
                           C.n, C.a, C.b, t, i, C.ring[i], C.outA[i] >> 2,
                           C.outB[i] >> 2);
              for(int j = 0; j < C.n; j++) {
                const vIdx *n = &m.node[4 * C.tet[j]];
                Msg::Warning("  ring tet %u: nodes %u %u %u %u flag 0x%x color "
                             "%u ring %u",
                             C.tet[j], n[0], n[1], n[2], n[3], m.flag[C.tet[j]],
                             m.color[C.tet[j]], C.ring[j]);
              }
            }
            return NOT_BETTER;
          }
        }
        return OK;
      }

      Status edgeRemoval(Local &L, tIdx t, int e)
      {
        EdgeCavity C;
        Status st = buildEdgeCavity(L, t, e, C);
        if(st != OK) return st;
        double worst = 2.;
        for(int i = 0; i < C.n; i++) worst = std::min(worst, qual[C.tet[i]]);
        SwapPattern sp;
        switch(C.n) {
        case 3: BuildSwapPattern3(&sp); break;
        case 4: BuildSwapPattern4(&sp); break;
        case 5: BuildSwapPattern5(&sp); break;
        case 6: BuildSwapPattern6(&sp); break;
        case 7: BuildSwapPattern7(&sp); break;
        default: return NOT_BETTER;
        }
        // the two tets on each possible triangle of the ring. The new tets
        // must have a positive volume, and their volumes must add up to the
        // volume of the ring: a triangle outside the ring polygon can give
        // positive tets that cover existing ones twice
        const double *pa = &m.xyz[4 * C.a], *pb = &m.xyz[4 * C.b];
        double ringVol = 0.;
        for(int i = 0; i < C.n; i++) {
          const vIdx *n = &m.node[4 * C.tet[i]];
          ringVol -= orient3dFast(&m.xyz[4 * n[0]], &m.xyz[4 * n[1]],
                                  &m.xyz[4 * n[2]], &m.xyz[4 * n[3]]);
        }
        double qa[35], qb[35], vol[35];
        bool flip[35];
        for(int i = 0; i < sp.nbr_triangles; i++) {
          const vIdx r0 = C.ring[sp.triangles[i][0]],
                     r1 = C.ring[sp.triangles[i][1]],
                     r2 = C.ring[sp.triangles[i][2]];
          const double *p0 = &m.xyz[4 * r0], *p1 = &m.xyz[4 * r1],
                       *p2 = &m.xyz[4 * r2];
          const double da = orient3dFast(p0, p1, p2, pa);
          const double db = orient3dFast(p0, p1, p2, pb);
          if(da * db >= 0.) { // a and b on the same side: not a valid pair
            qa[i] = qb[i] = -1.;
            vol[i] = 0.;
            flip[i] = false;
            continue;
          }
          vol[i] = std::fabs(da) + std::fabs(db);
          flip[i] = da > 0.;
          if(flip[i]) {
            qa[i] = gammaQuality(p1, p0, p2, pa, -da);
            qb[i] = gammaQuality(p0, p1, p2, pb, db);
          }
          else {
            qa[i] = gammaQuality(p0, p1, p2, pa, da);
            qb[i] = gammaQuality(p1, p0, p2, pb, -db);
          }
        }
        int best = -1;
        double bestWorst = worst;
        for(int i = 0; i < sp.nbr_trianguls; i++) {
          double w = 2., v = 0.;
          for(int j = 0; j < sp.nbr_triangles_2; j++) {
            const int it = sp.trianguls[i][j];
            w = std::min(w, std::min(qa[it], qb[it]));
            v += vol[it];
            if(w <= bestWorst) break;
          }
          if(w > bestWorst && std::fabs(v - ringVol) > 1.e-6 * ringVol) {
            L.invalidSwaps++;
            continue;
          }
          if(w > bestWorst) {
            bestWorst = w;
            best = i;
          }
        }
        if(best < 0) return NOT_BETTER;
        // constrained edges of the cavity, to carry over to the new tets
        std::uint64_t cEdges[42];
        int ncEdges = 0;
        for(int i = 0; i < C.n; i++) {
          const std::uint16_t f = m.flag[C.tet[i]];
          if(!(f & F_ALL_EDGES)) continue;
          for(int k = 0; k < 6; k++) {
            if(!(f & (1 << k))) continue;
            unsigned n0, n1;
            edgeNodes(k, n0, n1);
            vIdx u = m.node[4 * C.tet[i] + n0], v = m.node[4 * C.tet[i] + n1];
            if(u > v) std::swap(u, v);
            cEdges[ncEdges++] = ((std::uint64_t)u << 32) | v;
          }
        }
        const std::uint32_t color = m.color[C.tet[0]];
        // room for the new tets, secured before anything is modified
        if(!ensureFreeSlots(L, 2 * (C.n - 2))) return CONFLICT;
        // the cavity tets are gone; their slots are reused
        for(int i = 0; i < C.n; i++) {
          m.flag[C.tet[i]] |= F_DELETED;
          L.deleted.push_back(C.tet[i]);
        }
        // the new tets, with their facets for the adjacencies
        struct facetKey {
          vIdx v0, v1, v2;
          tRef ref;
        };
        facetKey facets[40];
        int nf = 0;
        tIdx created[10];
        int nc = 0;
        auto addFacet = [&](vIdx x, vIdx y, vIdx z, tRef ref) {
          if(x > y) std::swap(x, y);
          if(y > z) std::swap(y, z);
          if(x > y) std::swap(x, y);
          facets[nf++] = {x, y, z, ref};
        };
        for(int j = 0; j < sp.nbr_triangles_2; j++) {
          const int it = sp.trianguls[best][j];
          vIdx r0 = C.ring[sp.triangles[it][0]],
               r1 = C.ring[sp.triangles[it][1]],
               r2 = C.ring[sp.triangles[it][2]];
          if(flip[it]) std::swap(r0, r1);
          for(int side = 0; side < 2; side++) {
            const tIdx s = newSlot(L);
            vIdx *n = &m.node[4 * s];
            if(side == 0) {
              n[0] = r0;
              n[1] = r1;
              n[2] = r2;
              n[3] = C.a;
              qual[s] = qa[it];
            }
            else {
              n[0] = r1;
              n[1] = r0;
              n[2] = r2;
              n[3] = C.b;
              qual[s] = qb[it];
            }
            m.flag[s] = 0;
            m.color[s] = color;
            for(unsigned f = 0; f < 4; f++) {
              m.neigh[4 * s + f] = NO_ADJ;
              addFacet(n[facetNode0(f)], n[facetNode1(f)], n[facetNode2(f)],
                       4 * s + f);
            }
            // constrained edges
            for(int k = 0; k < ncEdges; k++) {
              const vIdx u = (vIdx)(cEdges[k] >> 32), v = (vIdx)cEdges[k];
              int iu = -1, iv = -1;
              for(int q = 0; q < 4; q++) {
                if(n[q] == u) iu = q;
                if(n[q] == v) iv = q;
              }
              if(iu >= 0 && iv >= 0)
                m.flag[s] |= 1 << (5 - edgeFromFacets(iu, iv));
            }
            created[nc++] = s;
          }
        }
        // adjacencies: the boundary facets of the cavity first
        for(int i = 0; i < C.n; i++) {
          const vIdx rp = C.ring[(i + C.n - 1) % C.n], r = C.ring[i];
          for(int side = 0; side < 2; side++) {
            vIdx x = side ? C.b : C.a, y = rp, z = r;
            if(x > y) std::swap(x, y);
            if(y > z) std::swap(y, z);
            if(x > y) std::swap(x, y);
            const tRef out = side ? C.outB[i] : C.outA[i];
            const bool constrained = side ? C.flagB[i] : C.flagA[i];
            for(int k = 0; k < nf; k++) {
              if(facets[k].v0 == x && facets[k].v1 == y && facets[k].v2 == z) {
                m.neigh[facets[k].ref] = out;
                m.neigh[out] = facets[k].ref;
                if(constrained)
                  m.flag[facets[k].ref >> 2] |= F_FACET0 << (facets[k].ref & 3);
                facets[k].ref = NO_ADJ; // done
                break;
              }
            }
          }
        }
        // then the facets between the new tets
        for(int k = 0; k < nf; k++) {
          if(facets[k].ref == NO_ADJ) continue;
          for(int l = k + 1; l < nf; l++) {
            if(facets[l].ref != NO_ADJ && facets[l].v0 == facets[k].v0 &&
               facets[l].v1 == facets[k].v1 && facets[l].v2 == facets[k].v2) {
              m.neigh[facets[k].ref] = facets[l].ref;
              m.neigh[facets[l].ref] = facets[k].ref;
              facets[l].ref = NO_ADJ;
              break;
            }
          }
        }
        // the tets around the cavity may be improvable now
        for(int i = 0; i < C.n; i++) {
          for(int side = 0; side < 2; side++) {
            const tIdx o = (side ? C.outB[i] : C.outA[i]) >> 2;
            if(!m.isGhost(o) && tetInPartition(m, o, L.partition))
              m.flag[o] &= ~F_PROCESSED;
          }
        }
        L.swaps++;
        return OK;
      }

      // ---- node relocation ----

      // the tets around vertex v, starting from t; the base facet (opposite v)
      // of each is 4 * tet + facet
      Status buildVertexCavity(Local &L, tIdx t, vIdx v, std::vector<tRef> &cav)
      {
        const Partition &P = L.partition;
        if(fixedV[v]) return CONSTRAINED;
        if(outOfPartition(m, v, P)) return CONFLICT;
        cav.clear();
        L.visited.clear();
        unsigned iv = 0;
        while(m.node[4 * t + iv] != v) iv++;
        cav.push_back(4 * t + iv);
        L.visited.push_back(t);
        for(std::size_t i = 0; i < cav.size(); i++) {
          const tIdx cur = cav[i] >> 2;
          const unsigned base = cav[i] & 3;
          if(!inVolume(cur)) return CONSTRAINED;
          for(unsigned f = 0; f < 4; f++) {
            if(f == base) continue;
            if(m.flag[cur] & (F_FACET0 << f)) return CONSTRAINED;
            const tRef r = m.neigh[4 * cur + f];
            const tIdx nb = r >> 2;
            if(std::find(L.visited.begin(), L.visited.end(), nb) !=
               L.visited.end())
              continue;
            if(m.isGhost(nb)) return CONSTRAINED;
            // the vertex of nb that is not in cur must be in the partition
            if(outOfPartition(m, m.node[r], P)) return CONFLICT;
            unsigned k = 0;
            while(m.node[4 * nb + k] != v) k++;
            cav.push_back(4 * nb + k);
            L.visited.push_back(nb);
            if(cav.size() > 200) return CONSTRAINED;
          }
        }
        return OK;
      }

      double worstQuality(const std::vector<tRef> &cav) const
      {
        double w = 2.;
        for(auto r : cav) {
          const vIdx *n = &m.node[4 * (r >> 2)];
          w = std::min(w, tetQuality(m, n[0], n[1], n[2], n[3]));
        }
        return w;
      }

      Status smooth(Local &L, tIdx t, unsigned iv)
      {
        const vIdx v = m.node[4 * t + iv];
        std::vector<tRef> &cav = L.cavity;
        Status st = buildVertexCavity(L, t, v, cav);
        if(st != OK) return st;
        double *x = &m.xyz[4 * v];
        const double start[3] = {x[0], x[1], x[2]};
        // target: the mean of the centroids of the base facets
        double end[3] = {0., 0., 0.};
        for(auto r : cav) {
          const vIdx *n = &m.node[4 * (r >> 2)];
          const unsigned base = r & 3;
          for(unsigned k = 1; k < 4; k++) {
            const double *p = &m.xyz[4 * n[(base + k) & 3]];
            for(int j = 0; j < 3; j++) end[j] += p[j] / 3.;
          }
        }
        for(int j = 0; j < 3; j++) end[j] /= (double)cav.size();
        // golden section search of the position on [start, end] maximizing
        // the worst quality of the cavity (from HXT)
        auto place = [&](double alpha) {
          for(int j = 0; j < 3; j++)
            x[j] = alpha * start[j] + (1. - alpha) * end[j];
          return worstQuality(cav);
        };
        const double invPhi = 0.6180339887498949;
        double a[4] = {1., 0., invPhi, 1. - invPhi}, fa[4];
        for(int i = 0; i < 4; i++) fa[i] = place(a[i]);
        const double original = fa[0];
        while(fa[2] > fa[0] && fa[2] > fa[1] && fa[3] > fa[0] &&
              fa[3] > fa[1] && std::fabs(fa[0] - fa[1]) > 1.e-5) {
          int ind;
          if(fa[2] >= fa[3]) {
            fa[1] = fa[3];
            a[1] = a[3];
            fa[3] = fa[2];
            a[3] = a[2];
            a[2] = a[0] + invPhi * (a[1] - a[0]);
            ind = 2;
          }
          else {
            fa[0] = fa[2];
            a[0] = a[2];
            fa[2] = fa[3];
            a[2] = a[3];
            a[3] = a[1] + invPhi * (a[0] - a[1]);
            ind = 3;
          }
          fa[ind] = place(a[ind]);
        }
        if(fa[1] > fa[0]) {
          a[0] = a[1];
          fa[0] = fa[1];
        }
        if(a[0] >= 0.99 || fa[0] <= original) {
          for(int j = 0; j < 3; j++) x[j] = start[j];
          return NOT_BETTER;
        }
        place(a[0]);
        for(auto r : cav) {
          qual[r >> 2] = computeQuality(r >> 2);
          m.flag[r >> 2] &= ~F_PROCESSED;
        }
        L.relocations++;
        return OK;
      }

      // improve one bad tet; returns CONFLICT when a modification had to be
      // given up because of the partition
      Status improve(Local &L, tIdx t)
      {
        bool conflict = false;
        for(int e = 0; e < 6; e++) {
          const Status st = edgeRemoval(L, t, e);
          if(st == OK) return OK;
          if(st == CONFLICT) conflict = true;
        }
        for(unsigned iv = 0; iv < 4; iv++) {
          const Status st = smooth(L, t, iv);
          if(st == OK) return OK;
          if(st == CONFLICT) conflict = true;
        }
        return conflict ? CONFLICT : NOT_BETTER;
      }
    };

  } // namespace

  namespace {
    struct badTet {
      std::uint64_t dist;
      tIdx t;
      std::uint8_t todo;
    };
  } // namespace

  void optimize(Mesh &m, OptimizeOptions &opt)
  {
    const double t0 = TimeOfDay();
    const int maxThreads = std::max(1, opt.numThreads);
    Optimizer K(m, opt);
    K.qual.assign(m.tetCapacity(), 0.);
    const std::size_t nv = m.numVertices();
    K.fixedV.assign(nv, 0);
    for(std::size_t v = 0; v < std::min(nv, opt.numFixedVertices); v++)
      K.fixedV[v] = 1;
    // the vertices of the constrained facets and edges, and of the hull, are
    // fixed too
#pragma omp parallel for schedule(static) num_threads(maxThreads)
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t)) continue;
      const vIdx *n = &m.node[4 * t];
      const std::uint16_t f = m.flag[t];
      if(m.isGhost((tIdx)t) || m.color[t] >= opt.numVolumes) {
        for(int k = 0; k < 4; k++)
          if(n[k] != GHOST) K.fixedV[n[k]] = 1;
        continue;
      }
      if(f & F_ALL_CONSTRAINTS) {
        for(unsigned k = 0; k < 4; k++)
          if(f & (F_FACET0 << k))
            for(int j = 1; j < 4; j++) K.fixedV[n[(k + j) & 3]] = 1;
        for(int e = 0; e < 6; e++) {
          if(!(f & (1 << e))) continue;
          unsigned n0, n1;
          edgeNodes(e, n0, n1);
          K.fixedV[n[n0]] = K.fixedV[n[n1]] = 1;
        }
      }
    }
#pragma omp parallel for schedule(static) num_threads(maxThreads)
    // F_PROCESSED marks the tets that could not be improved, until a
    // neighbor changes
    for(std::size_t t = 0; t < m.ntet; t++) {
      m.flag[t] &= ~F_PROCESSED;
      if(K.inVolume((tIdx)t)) K.qual[t] = K.computeQuality((tIdx)t);
    }

    auto report = [&](const char *what) -> double {
      double worst = 2., avg = 0.;
      std::size_t count = 0;
#pragma omp parallel for schedule(static) num_threads(maxThreads)              \
  reduction(min : worst) reduction(+ : avg, count)
      for(std::size_t t = 0; t < m.ntet; t++) {
        if(!K.inVolume((tIdx)t)) continue;
        worst = std::min(worst, K.qual[t]);
        avg += K.qual[t];
        count++;
      }
      Msg::Info("Optimization %s: worst = %g / average = %g (%lu tets)", what,
                worst, count ? avg / count : 0., count);
      return worst;
    };
    report("starts");
    double bmin[3], bmax[3];
    m.bbox(bmin, bmax, maxThreads);
    std::vector<Local> locals(maxThreads);
    std::vector<std::vector<badTet>> localBad(maxThreads);
    std::uint32_t seed = 1;
    std::size_t totalSwaps = 0, totalRelocations = 0, totalConflicts = 0,
                totalInvalid = 0;
    std::size_t lastBad = 0;
    bool ranOutOfSpace = false;
    for(int pass = 0; pass < opt.maxPasses; pass++) {
      // the bad tets, sorted along the curve
      std::vector<badTet> bad;
      std::size_t numBad = 0;
#pragma omp parallel num_threads(maxThreads) reduction(+ : numBad)
      {
        std::vector<badTet> &lb = localBad[Msg::GetThreadNum()];
        lb.clear();
#pragma omp for schedule(static)
        for(std::size_t t = 0; t < m.ntet; t++) {
          if(!K.inVolume((tIdx)t) || K.qual[t] >= opt.qualityMin) continue;
          numBad++;
          if(!(m.flag[t] & F_PROCESSED)) lb.push_back({0, (tIdx)t, 1});
        }
      }
      for(auto &lb : localBad) bad.insert(bad.end(), lb.begin(), lb.end());
      if(bad.empty()) break;
      if(pass && numBad >= lastBad) break; // no progress
      lastBad = numBad;
      std::size_t passSwaps = totalSwaps, passReloc = totalRelocations;
      int nthreads = maxThreads;
      double conflictRatio = 0.;
      bool curveIsDefault = false;
      for(int round = 0; round < 10; round++) {
        std::size_t numTodo = 0;
        for(auto &b : bad) numTodo += b.todo;
        if(!numTodo) break;
        nthreads =
          computeNumberOfThreads(conflictRatio, nthreads, numTodo, 128);
        double startShift = 0.;
        if(round > 0 && nthreads > 1) {
          double shift[3] = {lcg01(seed), lcg01(seed), lcg01(seed)};
          startShift = lcg01(seed);
          mooreCurve(m, bmin, bmax, shift);
          curveIsDefault = false;
        }
        else if(!curveIsDefault) {
          mooreCurve(m, bmin, bmax);
          curveIsDefault = true;
        }
#pragma omp parallel for schedule(static) num_threads(maxThreads)
        for(std::size_t i = 0; i < bad.size(); i++)
          bad[i].dist = m.dist[m.node[4 * bad[i].t]];
        sortByDist(bad.data(), bad.size(), maxThreads);
        std::vector<std::uint64_t> dists(bad.size());
        std::vector<std::uint8_t> todo(bad.size());
#pragma omp parallel for schedule(static) num_threads(maxThreads)
        for(std::size_t i = 0; i < bad.size(); i++) {
          dists[i] = bad[i].dist;
          todo[i] = bad[i].todo;
        }
        std::vector<Partition> parts(nthreads);
        nthreads = makePartitions(dists.data(), todo.data(), bad.size(),
                                  numTodo, nthreads, startShift, parts);
        for(int i = 0; i < nthreads; i++) locals[i].partition = parts[i];
        // room for the new tets (an edge removal creates at most 3 more); a
        // round that ran out of space is redone with twice the capacity
        {
          std::size_t need =
            K.ntet + 4 * numTodo + (nthreads + 1) * Optimizer::BLOCK;
          if(ranOutOfSpace) need = std::max(need, 2 * m.tetCapacity());
          ranOutOfSpace = false;
          if(need > m.tetCapacity()) {
            m.reserveTets(
              std::max(need, m.tetCapacity() + m.tetCapacity() / 2));
            K.cap = m.tetCapacity();
            K.qual.resize(K.cap, 0.);
          }
        }
        std::size_t numConflicts = 0;
#pragma omp parallel num_threads(nthreads) reduction(+ : numConflicts)
        {
          const int tid = Msg::GetThreadNum();
          Local &L = locals[tid];
          L.noSpace = false;
          const Partition &P = L.partition;
          for(std::size_t i = 0; i < P.numElem && !L.noSpace; i++) {
            badTet &b = bad[(P.firstElem + i) % bad.size()];
            if(!b.todo) continue;
            if(m.isDeleted(b.t) || K.qual[b.t] >= opt.qualityMin) {
              b.todo = 0;
              continue;
            }
            const Status st = K.improve(L, b.t);
            if(st == CONFLICT) {
              numConflicts++;
              L.conflicts++;
            }
            else {
              b.todo = 0;
              if(st != OK) m.flag[b.t] |= F_PROCESSED; // stuck
            }
          }
        }
        if(K.ntet > K.cap) K.ntet = K.cap;
        m.ntet = K.ntet;
        for(int i = 0; i < nthreads; i++)
          if(locals[i].noSpace) ranOutOfSpace = true;
        conflictRatio = numTodo ? (double)numConflicts / numTodo : 0.;
        totalConflicts += numConflicts;
        if(opt.verbosity > 1)
          Msg::Info("Optimization pass %d round %d: %lu bad tets on %d "
                    "threads, %lu conflicts",
                    pass, round, numTodo, nthreads, numConflicts);
        if(!numConflicts && !ranOutOfSpace) break;
      }
      totalSwaps = totalRelocations = totalInvalid = 0;
      for(auto &L : locals) {
        totalSwaps += L.swaps;
        totalInvalid += L.invalidSwaps;
        totalRelocations += L.relocations;
      }
      if(opt.verbosity > 0)
        Msg::Info("Optimization pass %d: %lu bad tets (%lu to try), %lu edge "
                  "swaps, %lu node relocations (Wall %gs)",
                  pass, numBad, bad.size(), totalSwaps - passSwaps,
                  totalRelocations - passReloc, TimeOfDay() - t0);
      if(totalSwaps == passSwaps && totalRelocations == passReloc) break;
    }
    // report before the compaction, which renumbers the tets
    report("done");
    std::size_t ill = 0;
#pragma omp parallel for schedule(static) num_threads(maxThreads)              \
  reduction(+ : ill)
    for(std::size_t t = 0; t < m.ntet; t++)
      if(K.inVolume((tIdx)t) && K.qual[t] < 0.001) ill++;
    if(ill) Msg::Warning("%lu ill-shaped tets are still in the mesh", ill);
    Msg::Info("Optimization: %lu edge swaps (%lu rejected on volume), %lu "
              "node relocations, %lu conflicts (Wall %gs)",
              totalSwaps, totalInvalid, totalRelocations, totalConflicts,
              TimeOfDay() - t0);
    for(auto &L : locals)
      for(auto t : L.deleted)
        for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = NO_ADJ;
    m.numDefaultDist = 0;
    m.removeDeleted(maxThreads);
  }

} // namespace pdel3d
