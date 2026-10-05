// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Quality improvement of the pdel3d mesh by edge removal and node
// relocation, in parallel on partitions of the Moore curve (after HXT's
// hxt_tetOpti.c): the bad tets are sorted along the curve and shared out
// between the threads, and a modification whose cavity leaves the thread's
// piece of the curve is retried in a later round on a shifted curve. The tets
// that neither operation improves get a small polyhedron reconnection (Liu &
// Shewchuk, as HXT does): a cavity grown around the tet, node by node, is
// re-tetrahedralized by an exhaustive search of the tetrahedralization whose
// worst tet is the best.

#include <algorithm>
#include <atomic>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <limits>
#include <memory>
#include "GmshConfig.h"
#include "meshGRegionParallelOptimize.h"
#include "meshGRegionLocalMeshMod.h"
#include "GmshMessage.h"
#include "OS.h"

namespace pdel3d {

  namespace {

    inline double tetQuality(const Mesh &m, vIdx a, vIdx b, vIdx c, vIdx d)
    {
      const double *pa = &m.xyz[4 * a], *pb = &m.xyz[4 * b],
                   *pc = &m.xyz[4 * c], *pd = &m.xyz[4 * d];
      return gammaQuality(pa, pb, pc, pd, orient3dFast(pa, pb, pc, pd));
    }

    enum Status { OK, CONFLICT, NOT_BETTER, CONSTRAINED };

    // the cavity of a small polyhedron reconnection

    constexpr int SPR_MAX_POINTS = 32; // 8-bit node indices, dense tables
    constexpr int SPR_MAX_FACES = 512;
    constexpr int SPR_MAX_TETS = 463; // (n * n - 3 * n - 2) / 2 for n = 32
    constexpr int SPR_MAX_CONSTRAINTS = 100;
    constexpr int SPR_NUM_QUADS = 35960; // C(32, 4)

    // a boundary face of the cavity, counterclockwise seen from inside it,
    // and the mesh facet behind it (NO_ADJ for a face created by the search)
    struct SPRFace {
      std::uint8_t n[3];
      tRef adj;
      double best; // quality of the best tet on it (any cavity point)
    };
    struct SPRTet {
      std::uint8_t n[4];
    };

    // Large (about 500 KB): one per thread, on the heap. The orientations
    // and qualities of the tets on the cavity points are cached by sorted
    // quadruple, for the whole life of the cavity (the points keep their
    // indices while it grows)
    struct SPRCavity {
      int numPoints = 0;
      double xyz[SPR_MAX_POINTS][3];
      vIdx node[SPR_MAX_POINTS];
      std::uint8_t interior[SPR_MAX_POINTS]; // no boundary face: must be used
      int used[SPR_MAX_POINTS]; // by the tets of the search
      int numFaces = 0;
      SPRFace face[SPR_MAX_FACES];
      // index of the face (a, b, c), stored from its smallest node, or
      // UINT16_MAX
      std::uint16_t faceMap[SPR_MAX_POINTS][SPR_MAX_POINTS][SPR_MAX_POINTS];
      int numTets = 0; // the tets of the cavity, then of the solution
      SPRTet tet[SPR_MAX_TETS];
      double worst = 0.; // quality of the worst tet of the cavity
      int numEdges = 0; // constrained edges inside the cavity
      std::uint8_t edge[SPR_MAX_CONSTRAINTS][2];
      int numTriangles = 0; // constrained triangles inside the cavity
      std::uint8_t triangle[SPR_MAX_CONSTRAINTS][3];
      // 0: unknown; else sign + 2 (1 MB, direct: looked up far more often
      // than the qualities)
      std::int8_t orient[SPR_MAX_POINTS][SPR_MAX_POINTS][SPR_MAX_POINTS]
                        [SPR_MAX_POINTS];
      double quality[SPR_NUM_QUADS]; // NaN: unknown
      // the search
      SPRTet stack[SPR_MAX_TETS];
      int depth = 0;
      SPRTet solution[SPR_MAX_TETS];
      int numSolution = 0;
      double solutionQuality = 0.;
      std::uint64_t nodes = 0, maxNodes = 0;
      bool exhausted = false;
    };

    inline unsigned sprQuadIndex(int a, int b, int c, int d)
    {
      // sorted a < b < c < d: the combinadic
      return (unsigned)(a + b * (b - 1) / 2 + c * (c - 1) * (c - 2) / 6 +
                        d * (d - 1) * (d - 2) * (d - 3) / 24);
    }

    struct Local {
      std::vector<tIdx> deleted; // free slots
      Partition partition;
      std::vector<tIdx> cavity, visited;
      std::size_t swaps = 0, relocations = 0;
      std::size_t invalidSwaps = 0;
      std::size_t reconnections = 0, failedReconnections = 0;
      bool noSpace = false;
      std::unique_ptr<SPRCavity> spr;
      std::vector<tIdx> sprDeleted; // the tets of the cavity being grown
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

      // edge removal

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
        // tet 1 holds a, b, ring[0] and ring[1]
        const int s =
          ringOrientation(m, C.tet[1], C.a, C.b, C.ring[0], C.ring[1]);
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
          // a and b on opposite sides, the a-side tet with the ring's
          // orientation
          if(da * db >= 0. || da * s >= 0.) {
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
              m.flag[o] &= ~(F_PROCESSED | F_SPR_TRIED);
          }
        }
        L.swaps++;
        return OK;
      }

      // node relocation

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
          m.flag[r >> 2] &= ~(F_PROCESSED | F_SPR_TRIED);
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

      // small polyhedron reconnection

      // cached orientation of four cavity points, as the sign of
      // orient3d(a, b, c, d) (the cavity's tets are negative)
      int sprOrient(SPRCavity &S, int a, int b, int c, int d) const
      {
        std::int8_t &o = S.orient[a][b][c][d];
        if(!o) {
          // a repeated point: zero
          const double det =
            (a == b || a == c || a == d || b == c || b == d || c == d) ?
              0. :
              orient3dFast(S.xyz[a], S.xyz[b], S.xyz[c], S.xyz[d]);
          o = (std::int8_t)(2 + (det > 0.) - (det < 0.));
        }
        return o - 2;
      }

      // cached quality of the tet (a, b, c, d), -1 when it is not a valid
      // (negatively oriented) tet
      double sprQuality(SPRCavity &S, int a, int b, int c, int d) const
      {
        if(sprOrient(S, a, b, c, d) >= 0) return -1.;
        int v[4] = {a, b, c, d};
        std::sort(v, v + 4);
        const unsigned q = sprQuadIndex(v[0], v[1], v[2], v[3]);
        if(std::isnan(S.quality[q])) {
          const double *p0 = S.xyz[a], *p1 = S.xyz[b], *p2 = S.xyz[c],
                       *p3 = S.xyz[d];
          S.quality[q] = std::max(
            0., gammaQuality(p0, p1, p2, p3, orient3dFast(p0, p1, p2, p3)));
        }
        return S.quality[q];
      }

      void sprSetQuality(SPRCavity &S, const std::uint8_t *n, double q) const
      {
        int v[4] = {n[0], n[1], n[2], n[3]};
        std::sort(v, v + 4);
        S.quality[sprQuadIndex(v[0], v[1], v[2], v[3])] = q;
      }

      // the faces are stored from their smallest node
      static void sprRotate(int &a, int &b, int &c)
      {
        if(b < a && b < c) {
          const int t = a;
          a = b;
          b = c;
          c = t;
        }
        else if(c < a && c < b) {
          const int t = a;
          a = c;
          c = b;
          b = t;
        }
      }
      std::uint16_t sprFindFace(const SPRCavity &S, int a, int b, int c) const
      {
        sprRotate(a, b, c);
        return S.faceMap[a][b][c];
      }
      double sprFaceBest(SPRCavity &S, const SPRFace &f) const
      {
        double q = -1.;
        for(int p = 0; p < S.numPoints; p++)
          if(p != f.n[0] && p != f.n[1] && p != f.n[2])
            q = std::max(q, sprQuality(S, f.n[0], f.n[1], f.n[2], p));
        return q;
      }
      // the best quality is that of the current points: unknown again (-2)
      // for every face when the cavity has grown, computed when needed
      bool sprAddFace(SPRCavity &S, int a, int b, int c, tRef adj,
                      bool best = true) const
      {
        if(S.numFaces >= SPR_MAX_FACES) return false;
        sprRotate(a, b, c);
        S.faceMap[a][b][c] = (std::uint16_t)S.numFaces;
        SPRFace &f = S.face[S.numFaces++];
        f.n[0] = (std::uint8_t)a;
        f.n[1] = (std::uint8_t)b;
        f.n[2] = (std::uint8_t)c;
        f.adj = adj;
        f.best = best ? sprFaceBest(S, f) : -2.;
        return true;
      }
      void sprRemoveFace(SPRCavity &S, int i) const
      {
        SPRFace &f = S.face[i];
        S.faceMap[f.n[0]][f.n[1]][f.n[2]] = UINT16_MAX;
        if(i != S.numFaces - 1) {
          f = S.face[S.numFaces - 1];
          S.faceMap[f.n[0]][f.n[1]][f.n[2]] = (std::uint16_t)i;
        }
        S.numFaces--;
      }

      // a tet of the cavity may have one node outside the partition (as in
      // HXT): two threads cannot both hold three nodes of a tet, and a tet
      // outside the cavity shares three nodes with the cavity tet across its
      // facet, so no other thread can delete it either
      bool sprOutOfPartition(tIdx t, const Partition &P) const
      {
        const vIdx *n = &m.node[4 * t];
        int out = 0;
        for(int k = 0; k < 4; k++) out += outOfPartition(m, n[k], P);
        return out > 1;
      }

      // a boundary face of the cavity through which it can grow: not a
      // constrained facet, a volume tet behind
      bool sprOpen(tRef r) const
      {
        if(r == NO_ADJ) return false;
        const tIdx t = r >> 2;
        return inVolume(t) && !(m.flag[t] & (F_FACET0 << (r & 3)));
      }

      void sprUndelete(Local &L)
      {
        for(tIdx t : L.sprDeleted) m.flag[t] &= ~F_DELETED;
        L.sprDeleted.clear();
      }

      // the node behind the boundary faces that is the most connected to the
      // cavity (ties: the one whose tets are the worst)
      bool sprBestPoint(Local &L, vIdx &best)
      {
        const SPRCavity &S = *L.spr;
        vIdx pts[SPR_MAX_FACES];
        int cnt[SPR_MAX_FACES], np = 0;
        for(int i = 0; i < S.numFaces; i++) {
          if(!sprOpen(S.face[i].adj)) continue;
          const vIdx v = m.node[S.face[i].adj];
          int p = 0;
          while(p < np && pts[p] != v) p++;
          if(p == np) {
            pts[np] = v;
            cnt[np++] = 1;
          }
          else
            cnt[p]++;
        }
        int most = 0;
        bool tie = false;
        for(int p = 0; p < np; p++) {
          if(cnt[p] > most) {
            most = cnt[p];
            best = pts[p];
            tie = false;
          }
          else if(cnt[p] == most)
            tie = true;
        }
        if(!most) return false;
        if(tie) {
          double bestScore = -DBL_MAX;
          for(int p = 0; p < np; p++) {
            if(cnt[p] != most) continue;
            double score = 0.;
            for(int i = 0; i < S.numFaces; i++)
              if(sprOpen(S.face[i].adj) && m.node[S.face[i].adj] == pts[p])
                score -= qual[S.face[i].adj >> 2];
            if(score > bestScore) {
              bestScore = score;
              best = pts[p];
            }
          }
        }
        return true;
      }

      // the edge of t between its facets inF and outF when it is constrained
      // and every tet around it is in the cavity, else -1
      int sprInteriorConstrainedEdge(tIdx t, unsigned inF, unsigned outF) const
      {
        const int e = edgeFromFacets(inF, outF);
        if(!(m.flag[t] & (1 << e))) return -1;
        tIdx cur = t;
        do {
          if(m.flag[cur] & (F_FACET0 << outF)) return -1;
          const vIdx opp = m.node[4 * cur + inF];
          const tRef r = m.neigh[4 * cur + outF];
          if(r == NO_ADJ || !m.isDeleted(r >> 2)) return -1;
          cur = r >> 2;
          inF = r & 3;
          const vIdx *nn = &m.node[4 * cur];
          for(outF = 0; outF < 3; outF++)
            if(nn[outF] == opp) break;
        } while(cur != t);
        return e;
      }

      // grow the cavity by the best node: the tets behind the boundary faces
      // that contain it join the cavity, which exposes new faces, until none
      // is left
      Status sprAttach(Local &L)
      {
        SPRCavity &S = *L.spr;
        vIdx newNode = GHOST;
        if(!sprBestPoint(L, newNode)) return CONSTRAINED;
        if(S.numPoints >= SPR_MAX_POINTS) return CONSTRAINED;
        const int newV = S.numPoints++;
        for(int k = 0; k < 3; k++) S.xyz[newV][k] = m.xyz[4 * newNode + k];
        S.node[newV] = newNode;
        for(int i = 0; i < S.numFaces;) {
          const tRef r = S.face[i].adj;
          if(!sprOpen(r)) {
            i++;
            continue;
          }
          const tIdx t = r >> 2;
          const unsigned f = r & 3;
          const vIdx opp = m.node[r];
          int oppV = -1;
          for(int j = 0; j < S.numPoints; j++)
            if(S.node[j] == opp) {
              oppV = j;
              break;
            }
          if(oppV < 0) {
            i++;
            continue;
          }
          if(sprOutOfPartition(t, L.partition)) return CONFLICT;
          if(S.numTets >= SPR_MAX_TETS) return CONSTRAINED;
          m.flag[t] |= F_DELETED;
          L.sprDeleted.push_back(t);
          // the tet in the cavity's numbering, its nodes in the mesh order:
          // the face holds the facet reversed
          const std::uint8_t *fn = S.face[i].n;
          std::uint8_t *tv = S.tet[S.numTets++].n;
          tv[f] = (std::uint8_t)oppV;
          const vIdx *n = &m.node[4 * t];
          for(int j = 0; j < 3; j++) {
            if(S.node[fn[j]] == n[facetNode0(f)]) {
              tv[facetNode0(f)] = fn[j];
              tv[facetNode1(f)] = fn[(j + 2) % 3];
              tv[facetNode2(f)] = fn[(j + 1) % 3];
              break;
            }
          }
          sprSetQuality(S, tv, qual[t]);
          if(qual[t] < S.worst) S.worst = qual[t];
          sprRemoveFace(S, i);
          for(unsigned g = 0; g < 4; g++) {
            if(g == f) continue;
            const int p0 = tv[facetNode0(g)], p1 = tv[facetNode1(g)],
                      p2 = tv[facetNode2(g)];
            // the facet is a boundary face if it is there reversed
            const std::uint16_t index = sprFindFace(S, p0, p2, p1);
            if(index == UINT16_MAX) {
              if(!sprAddFace(S, p0, p1, p2, m.neigh[4 * t + g], false))
                return CONSTRAINED;
            }
            else if(m.flag[t] & (F_FACET0 << g)) {
              // the face is now inside the cavity, and constrained
              sprRemoveFace(S, index);
              if(S.numTriangles >= SPR_MAX_CONSTRAINTS) return CONSTRAINED;
              std::uint8_t *c = S.triangle[S.numTriangles++];
              c[0] = (std::uint8_t)p0;
              c[1] = (std::uint8_t)p1;
              c[2] = (std::uint8_t)p2;
            }
            else {
              // the face is now inside the cavity; a constrained edge of it
              // may be too
              for(unsigned g2 = 0; g2 < 4; g2++) {
                if(g2 == g) continue;
                const int e = sprInteriorConstrainedEdge(t, g, g2);
                if(e < 0) continue;
                unsigned n0, n1;
                edgeNodes(e, n0, n1);
                const std::uint8_t a = tv[n0], b = tv[n1];
                bool known = false;
                for(int k = 0; k < S.numEdges && !known; k++)
                  known = (S.edge[k][0] == a && S.edge[k][1] == b) ||
                          (S.edge[k][0] == b && S.edge[k][1] == a);
                if(known) continue;
                if(S.numEdges >= SPR_MAX_CONSTRAINTS) return CONSTRAINED;
                S.edge[S.numEdges][0] = a;
                S.edge[S.numEdges++][1] = b;
              }
              sprRemoveFace(S, index);
              if((int)index < i) i = index;
            }
          }
        }
        return OK;
      }

      // the exhaustive search

      // segment (p, q) crosses triangle (a, b, c) properly (no shared node)
      bool sprCrosses(SPRCavity &S, int p, int q, int a, int b, int c) const
      {
        const int s1 = sprOrient(S, a, b, c, p), s2 = sprOrient(S, a, b, c, q);
        if(!s1 || s1 != -s2) return false;
        const int t1 = sprOrient(S, p, q, a, b);
        if(!t1) return false;
        return sprOrient(S, p, q, b, c) == t1 && sprOrient(S, p, q, c, a) == t1;
      }

      // tet (n[0..3], valid, bounding box lo-hi) and triangle (a, b, c)
      // interfere: an edge of one crosses a face of the other
      bool sprInterferes(SPRCavity &S, const int *n, const double *lo,
                         const double *hi, int a, int b, int c) const
      {
        for(int k = 0; k < 3; k++) {
          const double u = S.xyz[a][k], v = S.xyz[b][k], w = S.xyz[c][k];
          if(std::max(u, std::max(v, w)) < lo[k] ||
             std::min(u, std::min(v, w)) > hi[k])
            return false;
        }
        for(unsigned f = 0; f < 4; f++) {
          const int f0 = n[facetNode0(f)], f1 = n[facetNode1(f)],
                    f2 = n[facetNode2(f)];
          if(sprCrosses(S, a, b, f0, f1, f2) ||
             sprCrosses(S, b, c, f0, f1, f2) || sprCrosses(S, c, a, f0, f1, f2))
            return true;
        }
        for(int e = 0; e < 6; e++) {
          unsigned n0, n1;
          edgeNodes(e, n0, n1);
          if(sprCrosses(S, n[n0], n[n1], a, b, c)) return true;
        }
        return false;
      }

      // the candidate tet on face (a, b, c) with apex d can be part of a
      // tetrahedralization of the cavity: no cavity point in it or on it,
      // no interference with the boundary faces and the constraints
      bool sprValid(SPRCavity &S, int a, int b, int c, int d) const
      {
        const int n[4] = {a, b, c, d};
        double lo[3], hi[3];
        for(int k = 0; k < 3; k++) {
          lo[k] = hi[k] = S.xyz[a][k];
          for(int j = 1; j < 4; j++) {
            lo[k] = std::min(lo[k], S.xyz[n[j]][k]);
            hi[k] = std::max(hi[k], S.xyz[n[j]][k]);
          }
        }
        for(int p = 0; p < S.numPoints; p++) {
          if(p == a || p == b || p == c || p == d) continue;
          const double *x = S.xyz[p];
          if(x[0] < lo[0] || x[0] > hi[0] || x[1] < lo[1] || x[1] > hi[1] ||
             x[2] < lo[2] || x[2] > hi[2])
            continue;
          bool inside = true;
          for(unsigned f = 0; f < 4 && inside; f++)
            inside = sprOrient(S, n[facetNode0(f)], n[facetNode1(f)],
                               n[facetNode2(f)], p) <= 0;
          if(inside) return false;
        }
        for(unsigned f = 0; f < 3; f++) {
          // a facet that is a boundary face seen from the other side puts
          // the tet outside the cavity
          if(sprFindFace(S, n[facetNode0(f)], n[facetNode2(f)],
                         n[facetNode1(f)]) != UINT16_MAX)
            return false;
        }
        for(int i = 0; i < S.numFaces; i++) {
          const std::uint8_t *t = S.face[i].n;
          if(sprInterferes(S, n, lo, hi, t[0], t[1], t[2])) return false;
        }
        for(int i = 0; i < S.numTriangles; i++) {
          const std::uint8_t *t = S.triangle[i];
          if(sprInterferes(S, n, lo, hi, t[0], t[1], t[2])) return false;
        }
        for(int i = 0; i < S.numEdges; i++) {
          const int p = S.edge[i][0], q = S.edge[i][1];
          for(unsigned f = 0; f < 4; f++)
            if(sprCrosses(S, p, q, n[facetNode0(f)], n[facetNode1(f)],
                          n[facetNode2(f)]))
              return false;
        }
        return true;
      }

      // depth-first search of the tetrahedralization of the remaining cavity
      // whose worst tet is above S.solutionQuality: the face whose best
      // candidate is the worst is filled first, its candidates best first
      void sprSearch(SPRCavity &S, double worst)
      {
        if(S.exhausted) return;
        if(S.numFaces == 0) {
          for(int p = 0; p < S.numPoints; p++)
            if(S.interior[p] && !S.used[p]) return;
          S.solutionQuality = worst;
          S.numSolution = S.depth;
          std::copy(S.stack, S.stack + S.depth, S.solution);
          return;
        }
        int best = -1;
        double bestMax = DBL_MAX;
        for(int i = 0; i < S.numFaces; i++) {
          double qmax = S.face[i].best;
          if(qmax < -1.5) qmax = S.face[i].best = sprFaceBest(S, S.face[i]);
          if(qmax <= S.solutionQuality) return; // a face nothing can fill
          if(qmax < bestMax) {
            bestMax = qmax;
            best = i;
          }
        }
        const int a = S.face[best].n[0], b = S.face[best].n[1],
                  c = S.face[best].n[2];
        // the candidates, best first
        int cand[SPR_MAX_POINTS], nc = 0;
        double cq[SPR_MAX_POINTS];
        for(int p = 0; p < S.numPoints; p++) {
          if(p == a || p == b || p == c) continue;
          const double q = sprQuality(S, a, b, c, p);
          if(q <= S.solutionQuality) continue;
          int k = nc++;
          while(k > 0 && cq[k - 1] < q) {
            cq[k] = cq[k - 1];
            cand[k] = cand[k - 1];
            k--;
          }
          cq[k] = q;
          cand[k] = p;
        }
        for(int k = 0; k < nc && !S.exhausted; k++) {
          const int d = cand[k];
          if(cq[k] <= S.solutionQuality) break; // the bound may have moved
          if(!sprValid(S, a, b, c, d)) continue;
          if(++S.nodes > S.maxNodes) {
            S.exhausted = true;
            return;
          }
          // place the tet: its base face goes, its other facets close a face
          // or open one (reversed: the remaining cavity is on the other side)
          const int n[4] = {a, b, c, d};
          const SPRFace base = S.face[sprFindFace(S, a, b, c)];
          sprRemoveFace(S, sprFindFace(S, a, b, c));
          SPRFace closed[3];
          int opened[3][3], numClosed = 0, numOpened = 0;
          bool room = true;
          for(unsigned f = 0; f < 3 && room; f++) {
            const int f0 = n[facetNode0(f)], f1 = n[facetNode1(f)],
                      f2 = n[facetNode2(f)];
            const std::uint16_t index = sprFindFace(S, f0, f1, f2);
            if(index != UINT16_MAX) {
              closed[numClosed++] = S.face[index];
              sprRemoveFace(S, index);
            }
            else {
              room = sprAddFace(S, f0, f2, f1, NO_ADJ);
              opened[numOpened][0] = f0;
              opened[numOpened][1] = f2;
              opened[numOpened][2] = f1;
              numOpened++;
            }
          }
          if(room) {
            SPRTet &t = S.stack[S.depth++];
            for(int j = 0; j < 4; j++) t.n[j] = (std::uint8_t)n[j];
            for(int j = 0; j < 4; j++) S.used[n[j]]++;
            sprSearch(S, std::min(worst, cq[k]));
            for(int j = 0; j < 4; j++) S.used[n[j]]--;
            S.depth--;
          }
          // undo (the faces move in the array: by their nodes)
          for(int j = 0; j < numOpened; j++) {
            const std::uint16_t index =
              sprFindFace(S, opened[j][0], opened[j][1], opened[j][2]);
            if(index != UINT16_MAX) sprRemoveFace(S, index);
          }
          for(int j = 0; j < numClosed; j++) {
            sprAddFace(S, closed[j].n[0], closed[j].n[1], closed[j].n[2],
                       closed[j].adj, false);
            S.face[S.numFaces - 1].best = closed[j].best;
          }
          sprAddFace(S, base.n[0], base.n[1], base.n[2], base.adj, false);
          S.face[S.numFaces - 1].best = base.best;
          if(!room) {
            S.exhausted = true;
            return;
          }
        }
      }

      // replace the cavity by the solution
      bool sprRebuild(Local &L, tIdx bad)
      {
        SPRCavity &S = *L.spr;
        const int nt = S.numSolution;
        if(!ensureFreeSlots(L, nt)) return false;
        const std::uint32_t color = m.color[bad];
        // the constrained edges: inside the cavity, and on its boundary faces
        std::uint8_t cEdge[SPR_MAX_POINTS][SPR_MAX_POINTS] = {};
        for(int i = 0; i < S.numEdges; i++)
          cEdge[S.edge[i][0]][S.edge[i][1]] =
            cEdge[S.edge[i][1]][S.edge[i][0]] = 1;
        for(int i = 0; i < S.numFaces; i++) {
          const tRef r = S.face[i].adj;
          if(r == NO_ADJ) continue;
          const tIdx t = r >> 2;
          if(!(m.flag[t] & F_ALL_EDGES)) continue;
          const unsigned f = r & 3;
          // the face seen from the outer tet, so in the reverse order
          const unsigned ind[3] = {facetNode0(f), facetNode2(f), facetNode1(f)};
          const std::uint8_t *fn = S.face[i].n;
          int rot = 0;
          while(rot < 3 && S.node[fn[rot]] != m.node[4 * t + ind[0]]) rot++;
          if(rot == 3) continue;
          for(int j = 0; j < 3; j++) {
            const int e = 5 - edgeFromFacets(ind[j], ind[(j + 1) % 3]);
            if(!(m.flag[t] & (1 << e))) continue;
            const std::uint8_t a = fn[(rot + j) % 3], b = fn[(rot + j + 1) % 3];
            cEdge[a][b] = cEdge[b][a] = 1;
          }
        }
        // the new tets; their facets on the boundary faces get the mesh
        // adjacencies, the others are matched between them through a map
        // of their facets (the face map is free to reuse: the boundary faces
        // are looked up first and dropped from it)
        tIdx created[SPR_MAX_TETS];
        for(int i = 0; i < nt; i++) {
          const tIdx s = newSlot(L);
          created[i] = s;
          const std::uint8_t *v = S.solution[i].n;
          vIdx *n = &m.node[4 * s];
          for(int j = 0; j < 4; j++) n[j] = S.node[v[j]];
          m.color[s] = color;
          m.flag[s] = 0;
          qual[s] = sprQuality(S, v[0], v[1], v[2], v[3]);
          for(unsigned j = 0; j < 4; j++) {
            const int p0 = v[facetNode0(j)], p1 = v[facetNode1(j)],
                      p2 = v[facetNode2(j)];
            const std::uint16_t index = sprFindFace(S, p0, p1, p2);
            if(index == UINT16_MAX) {
              m.neigh[4 * s + j] = NO_ADJ; // inside the cavity, matched below
              continue;
            }
            const tRef a = S.face[index].adj;
            sprRemoveFace(S, index);
            m.neigh[4 * s + j] = a;
            m.neigh[a] = 4 * s + j;
            if(m.flag[a >> 2] & (F_FACET0 << (a & 3)))
              m.flag[s] |= F_FACET0 << j;
          }
          for(int e = 0; e < 6; e++) {
            unsigned n0, n1;
            edgeNodes(e, n0, n1);
            if(cEdge[v[n0]][v[n1]]) m.flag[s] |= 1 << e;
          }
        }
        for(int i = 0; i < nt; i++) {
          const std::uint8_t *v = S.solution[i].n;
          for(unsigned j = 0; j < 4; j++) {
            if(m.neigh[4 * created[i] + j] != NO_ADJ) continue;
            const int p0 = v[facetNode0(j)], p1 = v[facetNode1(j)],
                      p2 = v[facetNode2(j)];
            const std::uint16_t index = sprFindFace(S, p0, p2, p1);
            if(index == UINT16_MAX) {
              sprAddFace(S, p0, p1, p2, 4 * created[i] + j, false);
              continue;
            }
            const tRef other = S.face[index].adj;
            sprRemoveFace(S, index);
            m.neigh[4 * created[i] + j] = other;
            m.neigh[other] = 4 * created[i] + j;
          }
        }
        if(S.numFaces)
          Msg::Warning("%d facets left open by a reconnection", S.numFaces);
        // the constrained triangles inside the cavity are facets again
        for(int i = 0; i < S.numTriangles; i++) {
          const std::uint8_t *c = S.triangle[i];
          for(int k = 0; k < nt; k++) {
            const std::uint8_t *v = S.solution[k].n;
            for(unsigned j = 0; j < 4; j++) {
              const int p0 = v[facetNode0(j)], p1 = v[facetNode1(j)],
                        p2 = v[facetNode2(j)];
              const bool same = (p0 == c[0] || p0 == c[1] || p0 == c[2]) &&
                                (p1 == c[0] || p1 == c[1] || p1 == c[2]) &&
                                (p2 == c[0] || p2 == c[1] || p2 == c[2]);
              if(!same) continue;
              const tRef r = 4 * created[k] + j;
              m.flag[r >> 2] |= F_FACET0 << (r & 3);
              if(m.neigh[r] != NO_ADJ)
                m.flag[m.neigh[r] >> 2] |= F_FACET0 << (m.neigh[r] & 3);
            }
          }
        }
        // the slots of the old tets, and the tets around may be improvable
        for(tIdx t : L.sprDeleted) L.deleted.push_back(t);
        L.sprDeleted.clear();
        for(int i = 0; i < nt; i++)
          for(unsigned j = 0; j < 4; j++) {
            const tRef r = m.neigh[4 * created[i] + j];
            if(r == NO_ADJ) continue;
            const tIdx o = r >> 2;
            if(!m.isGhost(o) && tetInPartition(m, o, L.partition))
              m.flag[o] &= ~(F_PROCESSED | F_SPR_TRIED);
          }
        return true;
      }

      // improve a bad tet by reconnecting a cavity grown around it, node by
      // node, until the search finds a better tetrahedralization
      Status sprImprove(Local &L, tIdx bad)
      {
        if(!L.spr) L.spr.reset(new SPRCavity);
        SPRCavity &S = *L.spr;
        if(sprOutOfPartition(bad, L.partition)) return CONFLICT;
        // only the entries the cavity can reach: a sixteenth of the tables
        // with 16 points, for thousands of cavities per mesh
        const int maxPoints = std::min(opt.sprMaxPoints, SPR_MAX_POINTS);
        for(int a = 0; a < maxPoints; a++) {
          for(int b = 0; b < maxPoints; b++)
            std::memset(S.orient[a][b], 0, maxPoints * SPR_MAX_POINTS);
          std::memset(S.faceMap[a], 0xff, maxPoints * SPR_MAX_POINTS * 2);
        }
        std::fill(S.quality,
                  S.quality +
                    sprQuadIndex(maxPoints - 4, maxPoints - 3, maxPoints - 2,
                                 maxPoints - 1) +
                    1,
                  std::numeric_limits<double>::quiet_NaN());
        S.numPoints = 4;
        S.numFaces = S.numEdges = S.numTriangles = 0;
        S.numTets = 1;
        S.tet[0] = SPRTet{{0, 1, 2, 3}};
        S.worst = qual[bad];
        S.nodes = 0;
        S.maxNodes = (std::uint64_t)std::max(1, opt.sprMaxSearchNodes);
        L.sprDeleted.clear();
        m.flag[bad] |= F_DELETED;
        L.sprDeleted.push_back(bad);
        const vIdx *n = &m.node[4 * bad];
        for(int i = 0; i < 4; i++) {
          for(int k = 0; k < 3; k++) S.xyz[i][k] = m.xyz[4 * n[i] + k];
          S.node[i] = n[i];
        }
        sprSetQuality(S, S.tet[0].n, qual[bad]);
        for(unsigned f = 0; f < 4; f++)
          sprAddFace(S, facetNode0(f), facetNode1(f), facetNode2(f),
                     m.neigh[4 * bad + f], false);
        auto giveUp = [&](Status st) {
          sprUndelete(L);
          if(st == NOT_BETTER) L.failedReconnections++;
          return st;
        };
        while(true) {
          const Status st = sprAttach(L);
          if(st != OK) return giveUp(st);
          // the points without a boundary face are inside the cavity
          std::fill(S.interior, S.interior + S.numPoints, 1);
          for(int i = 0; i < S.numFaces; i++)
            for(int k = 0; k < 3; k++) S.interior[S.face[i].n[k]] = 0;
          std::fill(S.used, S.used + S.numPoints, 0);
          for(int i = 0; i < S.numFaces; i++) S.face[i].best = -2.; // unknown
          S.depth = 0;
          S.numSolution = 0;
          S.solutionQuality = S.worst;
          S.exhausted = false;
          sprSearch(S, DBL_MAX);
          if(S.numSolution) break; // better
          if(S.exhausted || S.numPoints >= maxPoints) return giveUp(NOT_BETTER);
        }
        if(!sprRebuild(L, bad)) return giveUp(CONFLICT);
        L.reconnections++;
        return OK;
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
    const bool haveSPR = opt.sprQualityFactor > 0. && opt.sprMaxPoints > 4;
    double bmin[3], bmax[3];
    m.bbox(bmin, bmax, maxThreads);
    std::vector<Local> locals(maxThreads);
    std::vector<std::vector<badTet>> localBad(maxThreads);
    std::uint32_t seed = 1;
    std::size_t totalSwaps = 0, totalRelocations = 0, totalConflicts = 0,
                totalInvalid = 0, totalReconnections = 0, totalFailed = 0;
    bool ranOutOfSpace = false;
    int pass = 0;
    // one pass over the bad tets: edge removals and relocations on those not
    // yet given up, or reconnections on those given up and not yet tried;
    // returns the number of modifications and the number of bad tets
    auto runPass = [&](bool spr, std::size_t &numBad) -> std::size_t {
      std::vector<badTet> bad;
      numBad = 0;
#pragma omp parallel num_threads(maxThreads) reduction(+ : numBad)
      {
        std::vector<badTet> &lb = localBad[Msg::GetThreadNum()];
        lb.clear();
#pragma omp for schedule(static)
        for(std::size_t t = 0; t < m.ntet; t++) {
          if(!K.inVolume((tIdx)t) || K.qual[t] >= opt.qualityMin) continue;
          numBad++;
          const std::uint16_t f = m.flag[t];
          const bool todo =
            spr ? (f & F_PROCESSED) && !(f & F_SPR_TRIED) &&
                    K.qual[t] < opt.sprQualityFactor * opt.qualityMin :
                  !(f & F_PROCESSED);
          if(todo) lb.push_back({0, (tIdx)t, 1});
        }
      }
      for(auto &lb : localBad) bad.insert(bad.end(), lb.begin(), lb.end());
      if(bad.empty()) return 0;
      std::size_t before = 0;
      for(auto &L : locals)
        before += spr ? L.reconnections : L.swaps + L.relocations;
      int nthreads = maxThreads;
      double conflictRatio = 0.;
      bool curveIsDefault = false;
      for(int round = 0; round < 10; round++) {
        std::size_t numTodo = 0;
        for(auto &b : bad) numTodo += b.todo;
        if(!numTodo) break;
        nthreads = computeNumberOfThreads(conflictRatio, nthreads, numTodo,
                                          spr ? 8 : 128);
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
        // room for the new tets (an edge removal creates at most 3 more, a
        // reconnection a few dozen); a round that ran out of space is redone
        // with twice the capacity
        {
          std::size_t need = K.ntet + (spr ? 64 : 4) * numTodo +
                             (nthreads + 1) * Optimizer::BLOCK;
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
            const Status st = spr ? K.sprImprove(L, b.t) : K.improve(L, b.t);
            if(st == CONFLICT) { numConflicts++; }
            else {
              b.todo = 0;
              if(st != OK) m.flag[b.t] |= spr ? F_SPR_TRIED : F_PROCESSED;
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
      std::size_t after = 0;
      totalSwaps = totalRelocations = totalInvalid = totalReconnections =
        totalFailed = 0;
      for(auto &L : locals) {
        totalSwaps += L.swaps;
        totalInvalid += L.invalidSwaps;
        totalRelocations += L.relocations;
        totalReconnections += L.reconnections;
        totalFailed += L.failedReconnections;
        after += spr ? L.reconnections : L.swaps + L.relocations;
      }
      if(opt.verbosity > 0)
        Msg::Info("Optimization pass %d: %lu bad tets, %lu %s (Wall %gs)", pass,
                  numBad, after - before, spr ? "reconnected" : "improved",
                  TimeOfDay() - t0);
      pass++;
      return after - before;
    };
    // edge removals and relocations until they stall (no progress, or less
    // than 2% of the bad tets improved, which on large meshes goes on for
    // long), then reconnections of the tets they gave up on, which may
    // unlock them again (as HXT alternates its two kinds of rounds); each
    // cycle gets up to maxPasses passes
    for(int cycle = 0; cycle < 5; cycle++) {
      std::size_t lastBad = std::numeric_limits<std::size_t>::max();
      for(int p = 0; p < opt.maxPasses; p++) {
        std::size_t numBad = 0;
        const std::size_t mods = runPass(false, numBad);
        if(!mods || numBad >= lastBad || 50 * mods < numBad) break;
        lastBad = numBad;
      }
      if(!haveSPR) break;
      std::size_t numBad = 0;
      if(!runPass(true, numBad)) break;
    }
    // report before the compaction, which renumbers the tets
    report("done");
    std::size_t ill = 0;
#pragma omp parallel for schedule(static) num_threads(maxThreads)              \
  reduction(+ : ill)
    for(std::size_t t = 0; t < m.ntet; t++)
      if(K.inVolume((tIdx)t) && K.qual[t] < 0.001) ill++;
    if(ill) Msg::Warning("%lu ill-shaped tets are still in the mesh", ill);
    Msg::Info("Optimization: %lu edge swaps, %lu node relocations, %lu "
              "reconnections (Wall %gs)",
              totalSwaps, totalRelocations, totalReconnections,
              TimeOfDay() - t0);
    if(opt.verbosity > 1)
      Msg::Info("  %lu swaps rejected on volume, %lu reconnections failed, "
                "%lu conflicts",
                totalInvalid, totalFailed, totalConflicts);
    for(auto &L : locals)
      for(auto t : L.deleted)
        for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = NO_ADJ;
#pragma omp parallel for schedule(static) num_threads(maxThreads)
    for(std::size_t t = 0; t < m.ntet; t++) m.flag[t] &= ~F_SPR_TRIED;
    m.numDefaultDist = 0;
    m.removeDeleted(maxThreads);
  }

} // namespace pdel3d
