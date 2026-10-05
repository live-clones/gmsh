// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cstring>
#include "pdel3d.h"
#include "pdel3dInternal.h"
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "Context.h"

namespace pdel3d {

  // ---------------------------------------------------------------------
  // Mesh
  // ---------------------------------------------------------------------

  void Mesh::reserveTets(std::size_t n)
  {
    if(n <= tetCapacity()) return;
    node.resize(4 * n);
    neigh.resize(4 * n);
    flag.resize(n);
    if(!color.empty()) color.resize(n);
  }

  std::size_t Mesh::numRealTets() const
  {
    std::size_t n = 0;
    for(std::size_t t = 0; t < ntet; t++)
      if(!isDeleted((tIdx)t) && !isGhost((tIdx)t)) n++;
    return n;
  }

  void Mesh::removeDeleted(int nthreads)
  {
    // new index of every tet: counted per chunk, then offset
    std::vector<tIdx> newIndex(ntet);
    const int nchunks = std::max(1, nthreads);
    std::vector<std::size_t> liveBefore(nchunks + 1, 0);
#pragma omp parallel num_threads(nchunks)
    {
#pragma omp for schedule(static)
      for(int c = 0; c < nchunks; c++) {
        tIdx n = 0;
        for(std::size_t t = c * ntet / nchunks; t < (c + 1) * ntet / nchunks;
            t++)
          newIndex[t] = isDeleted((tIdx)t) ? NO_TET : n++;
        liveBefore[c + 1] = n;
      }
#pragma omp single
      for(int c = 0; c < nchunks; c++) liveBefore[c + 1] += liveBefore[c];
#pragma omp for schedule(static)
      for(int c = 0; c < nchunks; c++) {
        const tIdx off = (tIdx)liveBefore[c];
        for(std::size_t t = c * ntet / nchunks; t < (c + 1) * ntet / nchunks;
            t++)
          if(newIndex[t] != NO_TET) newIndex[t] += off;
      }
    }
    const std::size_t n = liveBefore[nchunks];
    if(n == ntet) return;
    // move the tets (never upwards, so in sequence), then renumber the
    // adjacencies in parallel
    for(std::size_t t = 0; t < ntet; t++) {
      const tIdx s = newIndex[t];
      if(s == NO_TET || s == t) continue;
      for(int k = 0; k < 4; k++) {
        node[4 * s + k] = node[4 * t + k];
        neigh[4 * s + k] = neigh[4 * t + k];
      }
      flag[s] = flag[t];
      if(!color.empty()) color[s] = color[t];
    }
#pragma omp parallel for schedule(static) num_threads(nchunks)
    for(std::size_t s = 0; s < n; s++) {
      for(int k = 0; k < 4; k++) {
        const tRef r = neigh[4 * s + k];
        if(r != NO_ADJ) neigh[4 * s + k] = 4 * newIndex[r >> 2] + (r & 3);
      }
    }
    ntet = n;
  }

  void Mesh::removeUnusedVertices(std::vector<vIdx> &newIndex, int nthreads)
  {
    const std::size_t nv = numVertices();
    newIndex.assign(nv, GHOST);
    const int nt = std::max(1, nthreads);
#pragma omp parallel for schedule(static) num_threads(nt)
    for(std::size_t t = 0; t < ntet; t++) {
      if(isDeleted((tIdx)t)) continue;
      for(int k = 0; k < 4; k++)
        if(node[4 * t + k] != GHOST) newIndex[node[4 * t + k]] = 0;
    }
    vIdx n = 0;
    for(std::size_t v = 0; v < nv; v++)
      if(newIndex[v] != GHOST) newIndex[v] = n++;
    if(n == nv) return;
    for(std::size_t v = 0; v < nv; v++) {
      if(newIndex[v] == GHOST || newIndex[v] == v) continue;
      for(int k = 0; k < 4; k++) xyz[4 * newIndex[v] + k] = xyz[4 * v + k];
    }
    xyz.resize(4 * n);
    dist.clear();
    numDefaultDist = 0;
#pragma omp parallel for schedule(static) num_threads(nt)
    for(std::size_t t = 0; t < ntet; t++) {
      if(isDeleted((tIdx)t)) continue;
      for(int k = 0; k < 4; k++)
        if(node[4 * t + k] != GHOST)
          node[4 * t + k] = newIndex[node[4 * t + k]];
    }
  }

  void Mesh::bbox(double min[3], double max[3], int nthreads) const
  {
    for(int k = 0; k < 3; k++) {
      min[k] = 1.e300;
      max[k] = -1.e300;
    }
    const std::size_t n = numVertices();
    const int nt = std::max(1, nthreads);
#pragma omp parallel num_threads(nt)
    {
      double lmin[3] = {1.e300, 1.e300, 1.e300};
      double lmax[3] = {-1.e300, -1.e300, -1.e300};
#pragma omp for schedule(static)
      for(std::size_t i = 0; i < n; i++) {
        for(int k = 0; k < 3; k++) {
          lmin[k] = std::min(lmin[k], xyz[4 * i + k]);
          lmax[k] = std::max(lmax[k], xyz[4 * i + k]);
        }
      }
#pragma omp critical
      for(int k = 0; k < 3; k++) {
        min[k] = std::min(min[k], lmin[k]);
        max[k] = std::max(max[k], lmax[k]);
      }
    }
  }

  namespace {

    // order of the nodes of facet f of a deleted tet when the facet becomes a
    // face of the cavity boundary: (vta, b0, b1, b2) is then a correctly
    // oriented tet, and a ghost vertex (always node 3) stays last
    const unsigned ballNodes[4][3] = {
      {1, 2, 3}, {2, 0, 3}, {0, 1, 3}, {1, 0, 2}};

    // edge index (flag bit position) of the edge between two nodes
    const int edgeOfNodes[4][4] = {
      {-1, 5, 4, 3}, {5, -1, 2, 1}, {4, 2, -1, 0}, {3, 1, 0, -1}};

    inline int sign(double v) { return (v > 0.) - (v < 0.); }

    inline int insphereSign(const double *pa, const double *pb,
                            const double *pc, const double *pd,
                            const double *pe)
    {
      const double aex = pa[0] - pe[0], bex = pb[0] - pe[0],
                   cex = pc[0] - pe[0], dex = pd[0] - pe[0];
      const double aey = pa[1] - pe[1], bey = pb[1] - pe[1],
                   cey = pc[1] - pe[1], dey = pd[1] - pe[1];
      const double aez = pa[2] - pe[2], bez = pb[2] - pe[2],
                   cez = pc[2] - pe[2], dez = pd[2] - pe[2];
      const double ab = aex * bey - bex * aey, bc = bex * cey - cex * bey,
                   cd = cex * dey - dex * cey;
      const double da = dex * aey - aex * dey, ac = aex * cey - cex * aey,
                   bd = bex * dey - dex * bey;
      const double abc = aez * bc - bez * ac + cez * ab,
                   bcd = bez * cd - cez * bd + dez * bc;
      const double cda = cez * da + dez * ac + aez * cd,
                   dab = dez * ab + aez * bd + bez * da;
      const double alift = aex * aex + aey * aey + aez * aez,
                   blift = bex * bex + bey * bey + bez * bez;
      const double clift = cex * cex + cey * cey + cez * cez,
                   dlift = dex * dex + dey * dey + dez * dez;
      const double det =
        (dlift * abc - clift * dab) + (blift * cda - alift * bcd);
      const int ret = (det > robustPredicates::ispstaticfilter) -
                      (det < -robustPredicates::ispstaticfilter);
      if(ret) return ret;
      return sign(robustPredicates::insphere(pa, pb, pc, pd, pe));
    }

    // see Devillers & Teillaud, "Perturbations and vertex removal in a 3D
    // Delaunay triangulation": the sign of the insphere test for cospherical
    // points, decided on the vertex indices
    int symbolicPerturbation(vIdx indices[5], const double *i, const double *j,
                             const double *k, const double *l, const double *m)
    {
      const double *pt[5] = {i, j, k, l, m};
      unsigned swaps = 0;
      int n = 5;
      unsigned count;
      do {
        count = 0;
        n--;
        for(int iter = 0; iter < n; iter++) {
          if(indices[iter] > indices[iter + 1]) {
            std::swap(pt[iter], pt[iter + 1]);
            std::swap(indices[iter], indices[iter + 1]);
            count++;
          }
        }
        swaps += count;
      } while(count > 0);
      double oriA = robustPredicates::orient3d(pt[1], pt[2], pt[3], pt[4]);
      if(oriA != 0.) {
        if(swaps % 2) oriA = -oriA;
        return sign(oriA);
      }
      double oriB = -robustPredicates::orient3d(pt[0], pt[2], pt[3], pt[4]);
      if(oriB == 0.)
        Msg::Warning("Symbolic perturbation failed (superposed vertices?)");
      if(swaps % 2) oriB = -oriB;
      return sign(oriB);
    }

    // sign of the insphere test of vertex vta against tet t (negative: inside
    // the circumsphere); a ghost tet owns the half space beyond its hull face
    inline int tetInsphere(const Mesh &m, tIdx t, vIdx vta)
    {
      const vIdx *n = &m.node[4 * t];
      const double *a = &m.xyz[4 * n[0]], *b = &m.xyz[4 * n[1]],
                   *c = &m.xyz[4 * n[2]], *e = &m.xyz[4 * vta];
      if(n[3] == GHOST) {
        const double det = orient3dFast(a, b, c, e);
        if(det != 0.) return sign(det);
        // on the plane of the hull face: decide with the sphere through the
        // tet on the other side
        const vIdx opp = m.node[m.neigh[4 * t + 3]];
        const double *d = &m.xyz[4 * opp];
        int s = insphereSign(a, b, c, d, e);
        if(s == 0) {
          vIdx nn[5] = {n[0], n[1], n[2], opp, vta};
          s = symbolicPerturbation(nn, a, b, c, d, e);
        }
        return -s;
      }
      const double *d = &m.xyz[4 * n[3]];
      int s = insphereSign(a, b, c, d, e);
      if(s == 0) {
        vIdx nn[5] = {n[0], n[1], n[2], n[3], vta};
        s = symbolicPerturbation(nn, a, b, c, d, e);
      }
      return s;
    }

    // ---------------------------------------------------------------------
    // insertion status codes (internal)
    // ---------------------------------------------------------------------
    enum Status { OK, CONFLICT, TOO_CLOSE, DOUBLE, NO_SPACE, WALK_FAILED };

    // per-thread state
    struct Local {
      struct bndFace {
        vIdx n[3];
        tRef neigh; // the tet outside the cavity, then the new tet
        std::uint16_t flag;
      };
      std::vector<bndFace> ball;
      std::vector<tIdx> deleted; // free slots, the cavity tets at the end
      Partition partition;
      tIdx curTet = NO_TET;
      // adjacency map of the new tets on local vertex ids (< 32)
      tRef map[32 * 32];
      vIdx hkey[64];
      std::uint8_t hval[64];
      // hash table for large cavities: (edge key, tet facet)
      std::vector<std::uint64_t> hkeys;
      std::vector<tRef> hvals;
      // scratch of the cavity reshaping
      std::vector<std::uint64_t> faces;
      std::vector<tIdx> cavIndexKey;
      std::vector<std::uint32_t> cavIndexVal;
      // statistics
      std::size_t conflictWalk = 0, conflictDig = 0, noStart = 0;
      std::size_t hintUsed = 0, hintDead = 0, hintOut = 0;
      std::size_t walkSteps = 0, straightWalks = 0;
      std::size_t inserted = 0, filtered = 0, duplicates = 0, conflicts = 0,
                  walkFailed = 0;
      bool noSpace = false;

      // local id of a vertex of the ball (1..31), 0 for the ghost
      inline unsigned localId(vIdx v, unsigned &npts)
      {
        if(v == GHOST) return 0;
        unsigned h = (v * 2654435761u) >> 26;
        while(hkey[h] != GHOST) {
          if(hkey[h] == v) return hval[h];
          h = (h + 1) & 63;
        }
        hkey[h] = v;
        hval[h] = (std::uint8_t)npts;
        return npts++;
      }
    };

    inline void setDeleted(Mesh &m, tIdx t) { m.flag[t] |= F_DELETED; }
    inline void unsetDeleted(Mesh &m, tIdx t) { m.flag[t] &= ~F_DELETED; }

    // ---------------------------------------------------------------------
    // the Delaunay kernel
    // ---------------------------------------------------------------------
    class Kernel {
    public:
      Mesh &m;
      DelaunayOptions &opt;
      std::atomic<std::size_t> ntet; // slots in use, shared by the threads
      std::size_t cap;
      static constexpr std::size_t BLOCK = 4096; // slots taken at once

      Kernel(Mesh &_m, DelaunayOptions &_opt)
        : m(_m), opt(_opt), ntet(_m.ntet), cap(_m.tetCapacity())
      {
      }

      // mesh size filter
      inline bool tooClose(double s0, double s1, double d2) const
      {
        if(s0 > 0. && s1 > 0.) {
          const double s =
            std::min(opt.sizeMax, std::max(opt.sizeMin, 0.5 * (s0 + s1))) *
            opt.sizeFactor;
          return d2 < s * s;
        }
        return false;
      }
      static inline double sqDist(const double *a, const double *b)
      {
        const double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return dx * dx + dy * dy + dz * dz;
      }

      // take at least `demand` free slots in total in local.deleted; returns
      // false when the capacity is exhausted: the slots taken are then only
      // flagged deleted (the caller restores its cavity, which would unflag
      // them if they were in the list) and go at the next compaction
      bool newDeleted(Local &L, std::size_t demand)
      {
        std::size_t needed = std::max(BLOCK, demand) - L.deleted.size();
        const std::size_t first = ntet.fetch_add(needed);
        const std::size_t last = std::min(first + needed, cap);
        const bool ok = first + needed <= cap;
        for(std::size_t t = first; t < last; t++) {
          m.flag[t] = F_DELETED;
          if(ok) L.deleted.push_back((tIdx)t);
        }
        return ok;
      }

      // walk from L.curTet to the tet containing vta (or to the ghost tet
      // whose hull face vta lies beyond); returns OK, DOUBLE or CONFLICT
      // vta is in tet t (no facet has it beyond): OK, or DOUBLE when it
      // coincides with a node
      Status arrived(Local &L, tIdx t, const double *p)
      {
        const vIdx *curNode = &m.node[4 * t];
        const double *a = &m.xyz[4 * curNode[0]], *b = &m.xyz[4 * curNode[1]],
                     *c = &m.xyz[4 * curNode[2]], *d = &m.xyz[4 * curNode[3]];
        L.curTet = t;
        if((orient3dFast(a, b, c, p) >= 0) + (orient3dFast(a, b, p, d) >= 0) +
             (orient3dFast(a, p, c, d) >= 0) + (orient3dFast(p, b, c, d) >= 0) >
           2)
          return DOUBLE;
        return OK;
      }

      // walk from t0 to the tet containing vta along the segment from the
      // centroid of t0, crossing only the tets cut by that segment: slower
      // than the visibility walk, but it never wanders. Returns CONFLICT when
      // the segment leaves the partition
      Status straightWalk(Local &L, vIdx vta, tIdx t0)
      {
        const Partition &P = L.partition;
        const double *p = &m.xyz[4 * vta];
        L.straightWalks++;
        double q[3] = {0., 0., 0.};
        for(int k = 0; k < 4; k++)
          for(int j = 0; j < 3; j++)
            q[j] += 0.25 * m.xyz[4 * m.node[4 * t0 + k] + j];
        tIdx cur = t0;
        unsigned entering = 4;
        for(std::size_t steps = 0; steps < 10000000; steps++) {
          const vIdx *n = &m.node[4 * cur];
          const tRef *nb = &m.neigh[4 * cur];
          unsigned exitF = 4, anyBeyond = 4;
          for(unsigned i = 0; i < 4; i++) {
            if(i == entering) continue;
            const double *a = &m.xyz[4 * n[facetNode0(i)]];
            const double *b = &m.xyz[4 * n[facetNode1(i)]];
            const double *c = &m.xyz[4 * n[facetNode2(i)]];
            if(orient3dFast(p, a, b, c) >= 0.) continue; // p not beyond
            anyBeyond = i;
            // the segment exits through this facet if the line crosses it
            const double s0 = orient3dFast(q, p, a, b),
                         s1 = orient3dFast(q, p, b, c),
                         s2 = orient3dFast(q, p, c, a);
            if((s0 >= 0. && s1 >= 0. && s2 >= 0.) ||
               (s0 <= 0. && s1 <= 0. && s2 <= 0.)) {
              exitF = i;
              break;
            }
          }
          if(anyBeyond == 4) return arrived(L, cur, p);
          if(exitF == 4) exitF = anyBeyond; // degenerate: any progress
          const vIdx nn = m.node[nb[exitF]];
          if(nn == GHOST) {
            L.curTet = nb[exitF] >> 2;
            return OK;
          }
          if(outOfPartition(m, nn, P)) return CONFLICT;
          entering = nb[exitF] & 3;
          cur = nb[exitF] >> 2;
        }
        return WALK_FAILED;
      }

      Status walk(Local &L, vIdx vta)
      {
        tIdx next = L.curTet;
        std::size_t steps = 0;
        const Partition &P = L.partition;
        if(m.node[4 * next + 3] == GHOST) {
          const tRef r = m.neigh[4 * next + 3];
          if(outOfPartition(m, m.node[r], P)) return CONFLICT;
          next = r >> 2;
        }
        const tIdx start = next;
        const double *p = &m.xyz[4 * vta];
        unsigned enteringFace = 4;
        std::uint32_t seed = 1;
        while(true) {
          const tRef *curNeigh = &m.neigh[4 * next];
          const vIdx *curNode = &m.node[4 * next];
          unsigned index = 4, outside = 0, wantOther = 0;
          const unsigned randomU = lcg(seed);
          for(unsigned j = 0; j < 4; j++) {
            const unsigned i = (j + randomU) & 3;
            if(i == enteringFace) continue;
            const double *a = &m.xyz[4 * curNode[facetNode0(i)]];
            const double *b = &m.xyz[4 * curNode[facetNode1(i)]];
            const double *c = &m.xyz[4 * curNode[facetNode2(i)]];
            if(orient3dFast(p, a, b, c) < 0.) { // p beyond facet i
              outside = 1;
              const vIdx n = m.node[curNeigh[i]];
              if(n == GHOST) {
                L.curTet = curNeigh[i] >> 2;
                return OK;
              }
              if(outOfPartition(m, n, P)) {
                if(wantOther++ > 1000) return CONFLICT;
              }
              else {
                index = i;
                break;
              }
            }
          }
          if(index == 4) {
            if(outside) return CONFLICT; // L.curTet stays: the walk wandered
            L.walkSteps += steps;
            return arrived(L, next, p);
          }
          enteringFace = curNeigh[index] & 3;
          next = curNeigh[index] >> 2;
          // the visibility walk can wander for long in meshes with long
          // tets (the surface Delaunay of a CAD model): switch to the
          // straight walk from the starting tet (close to vta in the common
          // case), which only crosses the tets cut by one segment
          if(++steps > 256) return straightWalk(L, vta, start);
        }
      }

      inline void bndPush(Local &L, std::uint16_t flag, vIdx a, vIdx b, vIdx c,
                          tRef r)
      { L.ball.push_back({{a, b, c}, r, flag}); }

      // constraint flags of facet f of tet t transferred to the new tet
      // (vta, b0, b1, b2) built on it: the facet becomes facet 0, and its
      // edges become edges 0 (b1-b2), 1 (b0-b2) and 2 (b0-b1); with reversed
      // the nodes are pushed as (b1, b0, b2)
      inline std::uint16_t transferFlags(std::uint16_t flag, unsigned f,
                                         bool reversed = false) const
      {
        if(!(flag & F_ALL_CONSTRAINTS)) return 0;
        std::uint16_t nf = 0;
        if(flag & (F_FACET0 << f)) nf |= F_FACET0;
        const unsigned *bn = ballNodes[f];
        const unsigned b0 = reversed ? bn[1] : bn[0],
                       b1 = reversed ? bn[0] : bn[1], b2 = bn[2];
        if(flag & (1 << edgeOfNodes[b1][b2])) nf |= F_EDGE0;
        if(flag & (1 << edgeOfNodes[b0][b2])) nf |= F_EDGE1;
        if(flag & (1 << edgeOfNodes[b0][b1])) nf |= F_EDGE2;
        return nf;
      }

      // breadth-first search of the cavity of vta from firstTet; the cavity
      // tets are appended to L.deleted (and flagged), the boundary faces to
      // L.ball. Returns CONFLICT if the cavity reaches another partition
      Status dig(Local &L, tIdx firstTet, vIdx vta, bool &edgeConstraint)
      {
        L.deleted.push_back(firstTet);
        setDeleted(m, firstTet);
        L.ball.clear();
        const Partition &P = L.partition;
        const bool perfect = opt.perfectDelaunay;
        const double *p = &m.xyz[4 * vta];
        const double filterSize = opt.filterOnSize ? p[3] : 0.;
        for(std::size_t start = L.deleted.size() - 1; start < L.deleted.size();
            start++) {
          const tIdx cur = L.deleted[start];
          const std::uint16_t cflag = m.flag[cur];
          const bool facetConstrained = !perfect && (cflag & F_ALL_FACETS);
          if(!perfect && (cflag & F_ALL_EDGES)) edgeConstraint = true;
          for(unsigned f = 0; f < 4; f++) {
            const tRef r = m.neigh[4 * cur + f];
            const tIdx nb = r >> 2;
            const bool constrained =
              facetConstrained && (cflag & (F_FACET0 << f));
            if(m.isDeleted(nb) && !constrained) continue;
            const vIdx *cn = &m.node[4 * cur];
            if(constrained || tetInsphere(m, nb, vta) >= 0) {
              bndPush(L, transferFlags(cflag, f), cn[ballNodes[f][0]],
                      cn[ballNodes[f][1]], cn[ballNodes[f][2]], r);
            }
            else {
              const vIdx n = m.node[r]; // the node of nb not in cur
              if(n != GHOST) {
                if(outOfPartition(m, n, P)) return CONFLICT;
                // a cavity vertex too close to vta: stop digging right away
                // (the cavities of the first points of a refinement are huge
                // and most of those points are filtered)
                if(filterSize > 0.) {
                  const double *q = &m.xyz[4 * n];
                  const double sn = q[3] > 0. ? q[3] : filterSize;
                  if(tooClose(filterSize, sn, sqDist(p, q))) return TOO_CLOSE;
                }
              }
              L.deleted.push_back(nb);
              setDeleted(m, nb);
            }
          }
        }
        return OK;
      }

      void restoreDeleted(Local &L, std::size_t prevDeleted)
      {
        for(std::size_t i = prevDeleted; i < L.deleted.size(); i++)
          unsetDeleted(m, L.deleted[i]);
        L.deleted.resize(prevDeleted);
      }

      // adjacencies between the new tets of a small cavity (<= 31 vertices):
      // every edge of the boundary is seen twice, in opposite directions
      void adjacenciesFast(Local &L)
      {
        std::fill(L.hkey, L.hkey + 64, GHOST);
        unsigned npts = 1;
        for(auto &b : L.ball) {
          b.n[0] = L.localId(b.n[0], npts);
          b.n[1] = L.localId(b.n[1], npts);
          b.n[2] = L.localId(b.n[2], npts);
        }
        for(auto &b : L.ball) {
          L.map[b.n[0] * 32 + b.n[1]] = b.neigh + 3;
          L.map[b.n[1] * 32 + b.n[2]] = b.neigh + 1;
          L.map[b.n[2] * 32 + b.n[0]] = b.neigh + 2;
        }
        for(auto &b : L.ball) {
          m.neigh[b.neigh + 1] = L.map[b.n[2] * 32 + b.n[1]];
          m.neigh[b.neigh + 2] = L.map[b.n[0] * 32 + b.n[2]];
          m.neigh[b.neigh + 3] = L.map[b.n[1] * 32 + b.n[0]];
        }
      }

      // the same with a hash table on the edges, for large cavities
      void adjacenciesSlow(Local &L)
      {
        const std::size_t nedges = 3 * L.ball.size();
        std::size_t size = 64;
        while(size < 2 * nedges) size <<= 1;
        const std::size_t mask = size - 1;
        L.hkeys.assign(size, 0);
        L.hvals.resize(size);
        static const unsigned index[4] = {2, 3, 1, 2};
        for(auto &b : L.ball) {
          const tIdx t = b.neigh >> 2;
          const vIdx *n = &m.node[4 * t];
          for(unsigned j = 0; j < 3; j++) {
            const vIdx n0 = n[index[j]], n1 = n[index[j + 1]];
            const std::uint64_t key =
              ((std::uint64_t)(n0 ^ n1) << 32) | std::max(n0, n1);
            std::uint64_t h = (key * 0x9e3779b97f4a7c15ull) >> 20 & mask;
            while(L.hkeys[h] != key && L.hkeys[h] != 0) h = (h + 1) & mask;
            const tRef me = 4 * t + j + 1;
            if(L.hkeys[h] == key) {
              m.neigh[me] = L.hvals[h];
              m.neigh[L.hvals[h]] = me;
            }
            else {
              L.hkeys[h] = key;
              L.hvals[h] = me;
            }
          }
        }
      }

      // build the new tets on the boundary faces, reusing the slots of the
      // deleted tets (the last ball.size() slots of L.deleted)
      void fill(Local &L, vIdx vta, std::uint32_t color)
      {
        const std::size_t blength = L.ball.size();
        const std::size_t start = L.deleted.size() - blength;
        const bool hasColor = !m.color.empty();
        for(std::size_t i = 0; i < blength; i++) {
          Local::bndFace &b = L.ball[i];
          const tIdx t = L.deleted[start + i];
          vIdx *n = &m.node[4 * t];
          n[0] = vta;
          n[1] = b.n[0];
          n[2] = b.n[1];
          n[3] = b.n[2];
          if(hasColor) m.color[t] = color;
          m.flag[t] = b.flag;
          m.neigh[4 * t] = b.neigh;
          m.neigh[b.neigh] = 4 * t;
          b.neigh = 4 * t;
        }
        if(blength <= 58)
          adjacenciesFast(L);
        else
          adjacenciesSlow(L);
        L.curTet = L.deleted[start];
        L.deleted.resize(start);
      }

      // ---- constrained cavities (after HXT's hxt_tetDelaunayReshape.c) ----

      // a constrained edge whose every surrounding tet is in the cavity would
      // disappear: flag one of those tets (on the far side of vta) to be
      // undeleted by reshapeCavity(). The color of the cavity tets serves as
      // scratch (one bit per edge already handled), and is restored
      void respectEdgeConstraints(Local &L, vIdx vta, std::uint32_t color,
                                  std::size_t prevDeleted, bool &undeleteTet)
      {
        undeleteTet = false;
        for(std::size_t i = prevDeleted; i < L.deleted.size(); i++)
          m.color[L.deleted[i]] = 0;
        const tIdx tetOfVta = L.deleted[prevDeleted];
        const double *p = &m.xyz[4 * vta];
        for(std::size_t i = prevDeleted; i < L.deleted.size(); i++) {
          const tIdx delTet = L.deleted[i];
          for(int edge = 0; edge < 6; edge++) {
            if(!(m.flag[delTet] & (1 << edge)) ||
               (m.color[delTet] & (1u << edge)))
              continue;
            unsigned inF, outF;
            edgeFacets(edge, inF, outF);
            bool edgeIsSafe = false;
            tIdx cur = delTet;
            tIdx toUndelete = NO_TET;
            double distMax = -1.;
            do {
              const vIdx newV = m.node[4 * cur + inF];
              const tRef r = m.neigh[4 * cur + outF];
              cur = r >> 2;
              inF = r & 3;
              const vIdx *nodes = &m.node[4 * cur];
              for(outF = 0; outF < 3; outF++)
                if(nodes[outF] == newV) break;
              if(m.isDeleted(cur) && !(m.flag[cur] & F_UNDELETE)) {
                m.color[cur] |= 1u << edgeFromFacets(inF, outF);
                if(cur != tetOfVta) {
                  // the tet around the edge farthest from vta, measured at the
                  // midpoint of its two nodes off the edge
                  const double *a = &m.xyz[4 * newV],
                               *b = &m.xyz[4 * nodes[inF]];
                  double d = 0.;
                  for(int l = 0; l < 3; l++) {
                    const double diff = 0.5 * (a[l] + b[l]) - p[l];
                    d += diff * diff;
                  }
                  if(d > distMax) {
                    distMax = d;
                    toUndelete = cur;
                  }
                }
              }
              else
                edgeIsSafe = true;
            } while(cur != delTet);
            if(!edgeIsSafe && toUndelete != NO_TET) {
              m.flag[toUndelete] |= F_UNDELETE;
              undeleteTet = true;
            }
          }
        }
        for(std::size_t i = prevDeleted; i < L.deleted.size(); i++)
          m.color[L.deleted[i]] = color;
      }

      // push facet f of tet t, a tet put back outside the cavity, on the
      // ball: seen from inside the cavity its orientation is the reverse of
      // the one of a deleted tet (the ghost vertex, always node 3, stays
      // last)
      inline void bndPushFacet(Local &L, tIdx t, unsigned f, std::uint64_t r)
      {
        const vIdx *n = &m.node[4 * t];
        bndPush(L, transferFlags(m.flag[t], f, true), n[ballNodes[f][1]],
                n[ballNodes[f][0]], n[ballNodes[f][2]], (tRef)r);
      }

      // remove from the cavity the tets flagged F_UNDELETE and, progressively,
      // the tets behind the boundary faces that do not see vta, until the
      // cavity is star-shaped from vta
      bool reshapeCavity(Local &L, vIdx vta, std::size_t prevDeleted,
                         bool undeleteTet)
      {
        const double *p = &m.xyz[4 * vta];
        std::size_t blindFace = 0;
        if(!undeleteTet) {
          bool starShaped = true;
          for(std::size_t i = 0; i < L.ball.size(); i++) {
            const Local::bndFace &b = L.ball[i];
            if(b.n[2] == GHOST) continue;
            if(orient3dFast(p, &m.xyz[4 * b.n[0]], &m.xyz[4 * b.n[1]],
                            &m.xyz[4 * b.n[2]]) >= 0.) {
              blindFace = i;
              starShaped = false;
              break;
            }
          }
          if(starShaped) return true;
        }
        const std::size_t numTet = L.deleted.size() - prevDeleted;
        tIdx *tets = &L.deleted[prevDeleted];
        // cavity index of each cavity tet, through a small hash table
        std::size_t hsize = 16;
        while(hsize < 4 * numTet) hsize <<= 1;
        const std::size_t hmask = hsize - 1;
        L.cavIndexKey.assign(hsize, NO_TET);
        L.cavIndexVal.resize(hsize);
        auto hashPut = [&](tIdx t, std::uint32_t i) {
          std::size_t h = (t * 2654435761u) & hmask;
          while(L.cavIndexKey[h] != NO_TET) h = (h + 1) & hmask;
          L.cavIndexKey[h] = t;
          L.cavIndexVal[h] = i;
        };
        auto hashGet = [&](tIdx t) -> std::uint32_t {
          std::size_t h = (t * 2654435761u) & hmask;
          while(L.cavIndexKey[h] != t && L.cavIndexKey[h] != NO_TET)
            h = (h + 1) & hmask;
          if(L.cavIndexKey[h] == NO_TET) return 0xffffffffu;
          return L.cavIndexVal[h];
        };
        for(std::size_t i = 0; i < numTet; i++)
          hashPut(tets[i], (std::uint32_t)i);
        // faces[4 * i + f]: for an interior facet, the cavity-local reference
        // 4 * j + g of the facet of the adjacent cavity tet; for a boundary
        // facet, its index in the ball. The ball entries temporarily hold the
        // cavity-local reference of their facet instead of the outside tet
        L.faces.resize(4 * numTet);
        std::size_t curFace = 0;
        for(std::size_t i = 0; i < numTet; i++) {
          const tIdx t = tets[i];
          for(unsigned f = 0; f < 4; f++) {
            const tRef r = m.neigh[4 * t + f];
            if((m.flag[t] & (F_FACET0 << f)) || !m.isDeleted(r >> 2)) {
              L.ball[curFace].neigh = (tRef)(4 * i + f);
              L.faces[4 * i + f] = curFace;
              curFace++;
            }
            else {
              const std::uint32_t j = hashGet(r >> 2);
              if(j == 0xffffffffu) {
                Msg::Error(
                  "Inconsistent cavity in pdel3d (tet %u is not in it)",
                  r >> 2);
                return false;
              }
              L.faces[4 * i + f] = 4 * j + (r & 3);
            }
          }
        }
        // undelete the flagged tets that are not on the boundary of the cavity
        if(undeleteTet) {
          for(std::size_t i = 0; i < numTet; i++) {
            const tIdx t = tets[i];
            if(!(m.flag[t] & F_UNDELETE)) continue;
            bool isBoundary = false;
            for(unsigned f = 0; f < 4; f++) {
              const tRef r = m.neigh[4 * t + f];
              if((m.flag[t] & (F_FACET0 << f)) || !m.isDeleted(r >> 2)) {
                isBoundary = true;
                break;
              }
            }
            if(isBoundary) continue;
            m.flag[t] &= ~(F_UNDELETE | F_DELETED);
            tets[i] = NO_TET;
            for(unsigned f = 0; f < 4; f++) {
              const std::uint64_t out = L.faces[4 * i + f];
              L.faces[out] = L.ball.size();
              bndPushFacet(L, t, f, out);
            }
          }
        }
        // undelete the tets behind the faces that do not see vta; faces below
        // curFace are checked, those at or above are not yet
        curFace = blindFace;
        while(curFace < L.ball.size()) {
          const std::uint64_t in = L.ball[curFace].neigh;
          const tIdx t = tets[in / 4];
          if(!(m.flag[t] & F_UNDELETE)) {
            const Local::bndFace &b = L.ball[curFace];
            if(b.n[2] == GHOST ||
               orient3dFast(p, &m.xyz[4 * b.n[0]], &m.xyz[4 * b.n[1]],
                            &m.xyz[4 * b.n[2]]) < 0.) {
              curFace++;
              continue;
            }
          }
          else
            m.flag[t] &= ~F_UNDELETE;
          m.flag[t] &= ~F_DELETED;
          tets[in / 4] = NO_TET;
          for(unsigned f = 0; f < 4; f++) {
            const tRef r = m.neigh[4 * t + f];
            if((m.flag[t] & (F_FACET0 << f)) || !m.isDeleted(r >> 2)) {
              // an exterior facet of t: remove it from the ball
              std::size_t face = L.faces[4 * (in / 4) + f];
              if(face < curFace) {
                curFace--;
                if(face != curFace) {
                  L.ball[face] = L.ball[curFace];
                  L.faces[L.ball[face].neigh] = face;
                }
                face = curFace;
              }
              const std::size_t last = L.ball.size() - 1;
              if(face != last) {
                L.ball[face] = L.ball[last];
                L.faces[L.ball[face].neigh] = face;
              }
              L.ball.pop_back();
            }
            else {
              // an interior facet of t becomes a boundary face
              const std::uint64_t out = L.faces[4 * (in / 4) + f];
              L.faces[out] = L.ball.size();
              bndPushFacet(L, t, f, out);
            }
          }
        }
        // the ball entries point back to the outside tets
        for(auto &b : L.ball) {
          const std::uint64_t in = b.neigh;
          b.neigh = m.neigh[4 * tets[in / 4] + (in & 3)];
        }
        // compact the cavity
        std::size_t shift = 0;
        for(std::size_t i = 0; i < numTet; i++) {
          if(tets[i] == NO_TET)
            shift++;
          else if(shift)
            tets[i - shift] = tets[i];
        }
        L.deleted.resize(L.deleted.size() - shift);
        return true;
      }

      // hint is the tet where the walk starts when it is alive (its slot
      // may have been recycled: hintNode, its first node when the hint was
      // taken, must still be there) and in the partition; it receives the
      // tet reached by the walk (the one containing vta, or a tet near it
      // on a conflict), where a retry starts
      Status insert(Local &L, vIdx vta, tIdx &hint, vIdx &hintNode,
                    bool checkPartition)
      {
        const std::size_t prevDeleted = L.deleted.size();
        const bool alive = hint != NO_TET && hint < ntet &&
                           !m.isDeleted(hint) && m.node[4 * hint] == hintNode;
        if(alive && (!checkPartition || tetInPartition(m, hint, L.partition))) {
          L.curTet = hint;
          L.hintUsed++;
        }
        else if(!alive)
          L.hintDead++;
        else
          L.hintOut++;
        Status st = walk(L, vta);
        if(st != OK) {
          if(st == CONFLICT) L.conflictWalk++;
          return st;
        }
        // the tet containing vta is the hint of a retry
        hint = L.curTet;
        hintNode = m.node[4 * hint];
        const tIdx t0 = L.curTet;
        const std::uint32_t color =
          m.color.empty() ? Mesh::COLOR_OUT : m.color[t0];
        if(!opt.allowOuterInsertion && color == Mesh::COLOR_OUT)
          return TOO_CLOSE;
        const double *p = &m.xyz[4 * vta];
        if(opt.filterOnSize && p[3] > 0.) {
          // too close to a node of the tet containing it?
          for(unsigned j = 0; j < 4; j++) {
            const vIdx n = m.node[4 * t0 + j];
            if(j == 3 && n == GHOST) break;
            const double s = m.xyz[4 * n + 3] > 0. ? m.xyz[4 * n + 3] : p[3];
            if(tooClose(p[3], s, sqDist(p, &m.xyz[4 * n]))) return TOO_CLOSE;
          }
        }
        bool edgeConstraint = false;
        st = dig(L, t0, vta, edgeConstraint);
        if(st != OK) {
          if(st == CONFLICT) L.conflictDig++;
          restoreDeleted(L, prevDeleted);
          return st;
        }
        if(!opt.perfectDelaunay) {
          bool undeleteTet = false;
          if(edgeConstraint)
            respectEdgeConstraints(L, vta, color, prevDeleted, undeleteTet);
          if(!reshapeCavity(L, vta, prevDeleted, undeleteTet)) {
            restoreDeleted(L, prevDeleted);
            return TOO_CLOSE;
          }
        }
        if(opt.filterOnSize) {
          double *pv = &m.xyz[4 * vta];
          if(pv[3] <= 0.) { // mean size of the cavity vertices
            double s = 0., den = 0.;
            for(auto &b : L.ball) {
              for(int j = 0; j < 3; j++) {
                if(b.n[j] != GHOST && m.xyz[4 * b.n[j] + 3] > 0.) {
                  s += m.xyz[4 * b.n[j] + 3];
                  den += 1.;
                }
              }
            }
            if(den > 0.) pv[3] = s / den;
          }
          for(auto &b : L.ball) {
            for(int j = 0; j < 3; j++) {
              const vIdx n = b.n[j];
              if(n == GHOST) continue;
              const double s = m.xyz[4 * n + 3] > 0. ? m.xyz[4 * n + 3] : pv[3];
              if(tooClose(pv[3], s, sqDist(pv, &m.xyz[4 * n]))) {
                restoreDeleted(L, prevDeleted);
                return TOO_CLOSE;
              }
            }
          }
        }
        if(L.ball.size() > L.deleted.size()) {
          if(!newDeleted(L, L.ball.size())) {
            restoreDeleted(L, prevDeleted);
            return NO_SPACE;
          }
        }
        fill(L, vta, color);
        return OK;
      }
    };

    // the first tet and its 4 ghosts, from 4 non-coplanar vertices of the
    // list (which are moved to its front and marked inserted)
    struct NodeInfo {
      vIdx node;
      std::uint64_t dist;
      tIdx hint;
      vIdx hintNode; // node 0 of the hint tet, to detect a recycled slot
      std::uint8_t status;
    };

    bool initialTets(Mesh &m, std::vector<NodeInfo> &info)
    {
      const std::size_t n = info.size();
      if(n < 4) {
        Msg::Error("Cannot tetrahedralize less than four points");
        return false;
      }
      int orientation = 0;
      std::size_t i = 0, j = 1, k = 2, l = 3;
      for(i = 0; !orientation && i + 3 < n; i++) {
        const double *d = &m.xyz[4 * info[i].node];
        for(j = i + 1; !orientation && j + 2 < n; j++) {
          const double *c = &m.xyz[4 * info[j].node];
          const double cd[3] = {c[0] - d[0], c[1] - d[1], c[2] - d[2]};
          if(cd[0] == 0. && cd[1] == 0. && cd[2] == 0.) continue;
          for(k = j + 1; !orientation && k + 1 < n; k++) {
            const double *b = &m.xyz[4 * info[k].node];
            const double bd[3] = {b[0] - d[0], b[1] - d[1], b[2] - d[2]};
            const double cr[3] = {bd[1] * cd[2] - bd[2] * cd[1],
                                  bd[2] * cd[0] - bd[0] * cd[2],
                                  bd[0] * cd[1] - bd[1] * cd[0]};
            if(cr[0] == 0. && cr[1] == 0. && cr[2] == 0.) continue;
            for(l = k + 1; !orientation && l < n; l++) {
              const double *a = &m.xyz[4 * info[l].node];
              orientation = sign(robustPredicates::orient3d(a, b, c, d));
            }
          }
        }
      }
      l--;
      k--;
      j--;
      i--;
      if(!orientation) {
        Msg::Error("All points are coplanar");
        return false;
      }
      std::swap(info[i], info[0]);
      std::swap(info[j], info[1]);
      std::swap(info[k], info[2]);
      std::swap(info[l], info[3]);
      for(int q = 0; q < 4; q++) info[q].status = ST_INSERTED;
      i = 0;
      j = 1;
      k = 2;
      l = 3;
      if(orientation > 0) std::swap(i, j);
      const vIdx ni = info[i].node, nj = info[j].node, nk = info[k].node,
                 nl = info[l].node;
      m.reserveTets(std::max<std::size_t>(5, m.tetCapacity()));
      // HXT's initial configuration: tet 0 is (l, k, j, i), tets 1..4 are
      // the ghosts on its four facets, with the ghost vertex as node 3
      const vIdx nodes[20] = {nl,    nk,    nj, ni, nl,    nj,   nk,
                              GHOST, nl,    nk, ni, GHOST, nl,   ni,
                              nj,    GHOST, nk, nj, ni,    GHOST};
      const tRef neighs[20] = {19, 15, 11, 7, 18, 10, 13, 3, 17, 14,
                               5,  2,  16, 6, 9,  1,  12, 8, 4,  0};
      for(int q = 0; q < 20; q++) {
        m.node[q] = nodes[q];
        m.neigh[q] = neighs[q];
      }
      for(int t = 0; t < 5; t++) {
        m.flag[t] = 0;
        if(!m.color.empty()) m.color[t] = Mesh::COLOR_OUT;
      }
      m.ntet = 5;
      return true;
    }

    // sizes of the BRIO passes (from HXT), returned in increasing order with
    // passes[npasses] = nToInsert
    unsigned computePasses(std::size_t passes[12], std::size_t nInserted,
                           std::size_t nToInsert, double partitionability,
                           int maxPartitions)
    {
      const double alpha = 1. / ((double)maxPartitions * maxPartitions);
      nInserted =
        (std::size_t)(nInserted * ((1. - alpha) * partitionability + alpha));
      unsigned npasses = 0;
      passes[0] = nToInsert;
      for(unsigned i = 0; i < 10; i++) {
        if(passes[i] < 512 || passes[i] / 8 < nInserted) {
          passes[i + 1] = 0;
          npasses = i + 1;
          break;
        }
        passes[i + 1] = (std::size_t)(passes[i] / 7.5);
      }
      for(unsigned i = 0; i <= npasses / 2; i++)
        std::swap(passes[i], passes[npasses - i]);
      return npasses;
    }

  } // namespace

  // ---------------------------------------------------------------------
  // driver
  // ---------------------------------------------------------------------

  void insertVertices(Mesh &m, DelaunayOptions &opt,
                      std::vector<vIdx> &toInsert,
                      std::vector<std::uint8_t> &status, DelaunayStats *stats,
                      const std::vector<tIdx> *hints)
  {
    const double t0 = TimeOfDay();
    const std::size_t nToInsert = toInsert.size();
    status.assign(nToInsert, ST_TODO);
    if(!nToInsert) return;
    const int maxPartitions = std::max(1, opt.numThreads);
    std::vector<NodeInfo> info(nToInsert);
    for(std::size_t i = 0; i < nToInsert; i++) {
      const tIdx h = hints ? (*hints)[i] : NO_TET;
      info[i] = {toInsert[i], 0, h,
                 h != NO_TET && h < m.ntet ? m.node[4 * h] : GHOST, ST_TODO};
    }

    double bmin[3], bmax[3];
    m.bbox(bmin, bmax, maxPartitions);
    robustPredicates::exactinit(
      std::max(std::fabs(bmin[0]), std::fabs(bmax[0])),
      std::max(std::fabs(bmin[1]), std::fabs(bmax[1])),
      std::max(std::fabs(bmin[2]), std::fabs(bmax[2])));

    const bool firstPassEver = (m.ntet == 0);
    std::size_t numInMesh = 0;
    if(!firstPassEver && opt.numVerticesInMesh != (std::size_t)-1)
      numInMesh = opt.numVerticesInMesh;
    else if(!firstPassEver) {
      std::vector<std::uint8_t> used(m.numVertices(), 0);
#pragma omp parallel for schedule(static) num_threads(maxPartitions)
      for(std::size_t t = 0; t < m.ntet; t++) {
        if(m.isDeleted((tIdx)t)) continue;
        for(int k = 0; k < 4; k++)
          if(m.node[4 * t + k] != GHOST) used[m.node[4 * t + k]] = 1;
      }
      for(auto u : used) numInMesh += u;
    }
    std::size_t passes[12];
    unsigned npasses = computePasses(passes, numInMesh, nToInsert,
                                     opt.partitionability, maxPartitions);

    // shuffle, then sort each pass along the curve (biased randomized
    // insertion order)
    std::uint32_t seed = 1;
    if(npasses > 1 || firstPassEver) {
      for(std::size_t i = nToInsert - 1; i > 0; i--)
        std::swap(info[i], info[lcg(seed) % (i + 1)]);
    }
    // the default curve: only the vertices without a valid coordinate
    {
      bool sameBox = m.numDefaultDist <= m.numVertices();
      for(int k = 0; k < 3 && sameBox; k++)
        sameBox = m.defaultBox[k] == bmin[k] && m.defaultBox[3 + k] == bmax[k];
      if(!sameBox) m.numDefaultDist = 0;
      mooreCurve(m, bmin, bmax, nullptr, m.numDefaultDist);
      m.numDefaultDist = m.numVertices();
      for(int k = 0; k < 3; k++) {
        m.defaultBox[k] = bmin[k];
        m.defaultBox[3 + k] = bmax[k];
      }
    }
    bool curveIsDefault = true;
    std::vector<std::uint64_t> defaultDist; // kept while a shifted curve is on
#pragma omp parallel for schedule(static) num_threads(maxPartitions)
    for(std::size_t i = 0; i < nToInsert; i++)
      info[i].dist = m.dist[info[i].node];
    for(unsigned i = firstPassEver ? 1 : 0; i < npasses; i++)
      sortByDist(&info[passes[i]], passes[i + 1] - passes[i], maxPartitions);
    std::vector<vIdx> originalIndex;
    if(opt.reorderVertices && firstPassEver && nToInsert == m.numVertices()) {
      std::vector<double> xyz(4 * nToInsert);
      originalIndex.resize(nToInsert);
      for(std::size_t i = 0; i < nToInsert; i++) {
        const vIdx o = info[i].node;
        for(int k = 0; k < 4; k++) xyz[4 * i + k] = m.xyz[4 * o + k];
        m.dist[i] = info[i].dist; // dist is read again only in reordered form
        originalIndex[i] = o;
        info[i].node = (vIdx)i;
      }
      m.xyz.swap(xyz);
    }
    if(firstPassEver) {
      if(!initialTets(m, info)) return;
      passes[0] = 4;
    }
    const double t1 = TimeOfDay();

    Kernel K(m, opt);
    std::vector<Local> locals(maxPartitions);
    std::size_t totalInserted = 0, totalFiltered = 0, totalCurveFiltered = 0,
                totalDuplicates = 0, totalConflicts = 0, nrounds = 0;
    if(opt.verbosity > 0)
      Msg::Info("Delaunay of %lu points on %d threads (%lu in the mesh)",
                passes[npasses] - passes[0], maxPartitions, numInMesh);

    bool ranOutOfSpace = false;
    for(unsigned ipass = 0; ipass < npasses; ipass++) {
      int nthreads = maxPartitions;
      double conflictRatio = 0.;
      for(unsigned iround = 0; passes[ipass + 1] > passes[ipass]; iround++) {
        const std::size_t passStart = passes[ipass],
                          passEnd = passes[ipass + 1];
        const std::size_t passLength = passEnd - passStart;
        NodeInfo *pass = &info[passStart];
        double startShift = 0.;
        bool resort = true;
        const double tr0 = TimeOfDay();
        nthreads =
          computeNumberOfThreads(conflictRatio, nthreads, passLength, 512);
        nrounds++;

        // (re)compute the curve: shifted at random for the retries of a
        // multi-threaded round, the default one otherwise
        if(iround > 0 && nthreads > 1) {
          double shift[3] = {lcg01(seed), lcg01(seed), lcg01(seed)};
          startShift = lcg01(seed);
          if(curveIsDefault) defaultDist.swap(m.dist);
          mooreCurve(m, bmin, bmax, shift);
          curveIsDefault = false;
        }
        else if(!curveIsDefault) {
          m.dist.swap(defaultDist);
          curveIsDefault = true;
        }
        else
          resort = false;
        if(resort) {
#pragma omp parallel for schedule(static) num_threads(maxPartitions)
          for(std::size_t i = 0; i < passLength; i++)
            pass[i].dist = m.dist[pass[i].node];
          sortByDist(pass, passLength, maxPartitions);
        }

        // filter the vertices too close to one of the last vertices kept
        // along the curve (a cheap approximation of the filter in the cavity,
        // which costs a walk and a cavity search)
        std::size_t curveSkipped = 0;
        if(opt.filterOnSize) {
          const int W = std::max(1, std::min(opt.curveFilterWindow, 64));
          // in chunks, each with its own window (a few checks are lost at
          // the chunk boundaries)
          const int nchunks =
            (int)std::min<std::size_t>(maxPartitions, 1 + passLength / 4096);
#pragma omp parallel for schedule(static) num_threads(nchunks)                 \
  reduction(+ : curveSkipped)
          for(int c = 0; c < nchunks; c++) {
            const double *ring[64];
            int nring = 0, head = 0;
            for(std::size_t i = c * passLength / nchunks;
                i < (c + 1) * passLength / nchunks; i++) {
              if(pass[i].status != ST_TODO) continue;
              const double *p2 = &m.xyz[4 * pass[i].node];
              bool close = false;
              for(int k = 0; k < nring && !close; k++)
                close =
                  K.tooClose(ring[k][3], p2[3], Kernel::sqDist(ring[k], p2));
              if(close) {
                pass[i].status = ST_FILTERED;
                curveSkipped++;
              }
              else {
                ring[head] = p2;
                head = (head + 1) % W;
                if(nring < W) nring++;
              }
            }
          }
        }

        // partitions: contiguous pieces of the (circular) sorted pass
        {
          // the first round balances the vertices to insert; the retries
          // balance all the vertices of the pass instead: the vertices left
          // by the conflicts lie on the former partition boundaries, and
          // balancing them alone gives thin partitions around those
          // boundaries, which conflict again
          std::vector<std::uint64_t> dists(passLength);
          std::vector<std::uint8_t> todo(passLength);
#pragma omp parallel for schedule(static) num_threads(maxPartitions)
          for(std::size_t i = 0; i < passLength; i++) {
            dists[i] = pass[i].dist;
            todo[i] = iround > 0 || pass[i].status == ST_TODO;
          }
          std::vector<Partition> parts(std::max(1, nthreads));
          nthreads =
            makePartitions(dists.data(), todo.data(), passLength,
                           iround > 0 ? passLength : passLength - curveSkipped,
                           nthreads, startShift, parts);
          for(int i = 0; i < nthreads; i++) locals[i].partition = parts[i];
        }

        // room for the new tets: about 6 net new tets per vertex in a volume,
        // more for vertices on surfaces, plus the blocks the threads hoard; a
        // round that ran out of space is redone with twice the capacity
        {
          std::size_t need = K.ntet + 12 * (passLength - curveSkipped) +
                             (nthreads + 1) * Kernel::BLOCK;
          if(ranOutOfSpace) need = std::max(need, 2 * m.tetCapacity());
          if(need > m.tetCapacity()) {
            m.reserveTets(
              std::max(need, m.tetCapacity() + m.tetCapacity() / 2));
            K.cap = m.tetCapacity();
          }
          ranOutOfSpace = false;
        }

        const double tr1 = TimeOfDay();
#pragma omp parallel num_threads(nthreads)
        {
          const int tid = Msg::GetThreadNum();
          Local &L = locals[tid];
          L.noSpace = false;
          const Partition &P = L.partition;
          // starting tet: the hint of the first vertex when it is alive and
          // in the partition, otherwise any live tet of the partition
          L.curTet = NO_TET;
          for(std::size_t i = 0; i < P.numElem; i++) {
            NodeInfo &ni = pass[(P.firstElem + i) % passLength];
            if(ni.status != ST_TODO) continue;
            if(L.noSpace) continue;
            if(L.curTet == NO_TET) {
              if(ni.hint != NO_TET && ni.hint < K.ntet &&
                 !m.isDeleted(ni.hint) && m.node[4 * ni.hint] == ni.hintNode &&
                 (nthreads == 1 || tetInPartition(m, ni.hint, P)))
                L.curTet = ni.hint;
              else {
                for(std::size_t t = 0; t < K.ntet; t++) {
                  if(!m.isDeleted((tIdx)t) &&
                     (nthreads == 1 || tetInPartition(m, (tIdx)t, P))) {
                    L.curTet = (tIdx)t;
                    break;
                  }
                }
                if(L.curTet == NO_TET) {
                  L.noStart++;
                  break;
                }
              }
            }
            {
              switch(K.insert(L, ni.node, ni.hint, ni.hintNode, nthreads > 1)) {
              case OK:
                ni.status = ST_INSERTED;
                L.inserted++;
                break;
              case TOO_CLOSE:
                ni.status = ST_FILTERED;
                L.filtered++;
                break;
              case DOUBLE:
                ni.status = ST_DUPLICATE;
                L.duplicates++;
                break;
              case CONFLICT: L.conflicts++; break;
              case WALK_FAILED: L.walkFailed++; break;
              case NO_SPACE: L.noSpace = true; break;
              }
            }
          }
        }
        if(K.ntet > K.cap) K.ntet = K.cap;
        m.ntet = K.ntet;
        for(int i = 0; i < nthreads; i++)
          if(locals[i].noSpace) ranOutOfSpace = true;

        // with a single thread, the vertices still to do are those whose walk
        // cycled: give them up (the tets around them are candidates again at
        // the next refinement round)
        if(nthreads == 1 && !ranOutOfSpace) {
          std::size_t failed = 0;
          for(std::size_t i = passStart; i < passEnd; i++) {
            if(info[i].status == ST_TODO) {
              info[i].status = ST_FILTERED;
              failed++;
            }
          }
          if(failed)
            Msg::Warning("%lu point(s) could not be located in the mesh",
                         failed);
        }
        // the vertices still to do go to the end of the pass, in order
        std::size_t shift = 0, numSkipped = 0;
        for(std::size_t i = passEnd; i > passStart;) {
          i--;
          if(info[i].status != ST_TODO) {
            if(info[i].status != ST_INSERTED) numSkipped++;
            shift++;
          }
          else if(shift)
            std::swap(info[i], info[i + shift]);
        }
        const std::size_t numInserted = shift - numSkipped;
        const std::size_t numConflict = passLength - shift;
        totalInserted += numInserted;
        totalCurveFiltered += curveSkipped;
        // the vertices left by a lack of space are not conflicts
        if(passLength != numSkipped && !ranOutOfSpace)
          conflictRatio = (double)numConflict / (passLength - numSkipped);
        if(opt.verbosity > 1) {
          std::size_t cw = 0, cd = 0, ns = 0, hu = 0, hd = 0, ho = 0, ws = 0,
                      sw = 0;
          for(int i = 0; i < nthreads; i++) {
            cw += locals[i].conflictWalk;
            cd += locals[i].conflictDig;
            ns += locals[i].noStart;
            hu += locals[i].hintUsed;
            hd += locals[i].hintDead;
            ho += locals[i].hintOut;
            ws += locals[i].walkSteps;
            sw += locals[i].straightWalks;
            locals[i].conflictWalk = locals[i].conflictDig = locals[i].noStart =
              0;
            locals[i].hintUsed = locals[i].hintDead = locals[i].hintOut = 0;
            locals[i].walkSteps = locals[i].straightWalks = 0;
          }
          Msg::Info("%3d thrd | %10lu / %-10lu inserted (%.1f%%), %lu filtered "
                    "(setup %.4fs, insertion %.4fs; conflicts: walk %lu, "
                    "cavity %lu, no start %lu; hints used %lu, dead %lu, out "
                    "%lu; %lu walk steps, %lu straight walks)",
                    nthreads, numInserted, passLength - numSkipped,
                    100. * numInserted /
                      std::max<std::size_t>(1, passLength - numSkipped),
                    numSkipped, tr1 - tr0, TimeOfDay() - tr1, cw, cd, ns, hu,
                    hd, ho, ws, sw);
        }
        passes[ipass] += shift;
      }
    }
    if(!curveIsDefault) m.dist.swap(defaultDist);
    for(auto &L : locals) {
      totalFiltered += L.filtered;
      totalDuplicates += L.duplicates;
      totalConflicts += L.conflicts;
      for(auto t : L.deleted)
        for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = NO_ADJ;
    }
    if(opt.compact) m.removeDeleted(maxPartitions);
    if(!originalIndex.empty()) {
      for(std::size_t i = 0; i < nToInsert; i++) {
        toInsert[i] = originalIndex[i];
        status[info[i].node] = info[i].status;
      }
    }
    else {
      for(std::size_t i = 0; i < nToInsert; i++) {
        toInsert[i] = info[i].node;
        status[i] = info[i].status;
      }
    }
    const double t2 = TimeOfDay();
    if(stats) {
      stats->inserted += totalInserted;
      stats->filtered += totalFiltered;
      stats->curveFiltered += totalCurveFiltered;
      stats->duplicates += totalDuplicates;
      stats->conflicts += totalConflicts;
      stats->rounds += nrounds;
      stats->timeSort += t1 - t0;
      stats->timeInsert += t2 - t1;
    }
    if(opt.verbosity > 0)
      Msg::Info("  %lu inserted, %lu filtered (%lu along the curve), %lu "
                "duplicates, %lu conflicts, %lu rounds (%g s)",
                totalInserted, totalFiltered + totalCurveFiltered,
                totalCurveFiltered, totalDuplicates, totalConflicts, nrounds,
                t2 - t0);
  }

  // ---------------------------------------------------------------------
  // verification
  // ---------------------------------------------------------------------

  std::size_t Mesh::verify(bool delaunay, bool verbose) const
  {
    std::size_t errors = 0;
    const std::size_t nv = numVertices();
    auto report = [&](const char *what, std::size_t t) {
      errors++;
      if(verbose && errors <= 20)
        Msg::Error("pdel3d verify: %s (tet %lu)", what, t);
    };
    for(std::size_t t = 0; t < ntet; t++) {
      if(isDeleted((tIdx)t)) continue;
      const vIdx *n = &node[4 * t];
      for(int k = 0; k < 3; k++)
        if(n[k] == GHOST || n[k] >= nv) report("invalid node", t);
      if(n[3] != GHOST && n[3] >= nv) report("invalid node 3", t);
      if(n[0] == n[1] || n[0] == n[2] || n[0] == n[3] || n[1] == n[2] ||
         n[1] == n[3] || n[2] == n[3])
        report("repeated node", t);
      if(n[3] != GHOST) {
        if(robustPredicates::orient3d(&xyz[4 * n[0]], &xyz[4 * n[1]],
                                      &xyz[4 * n[2]], &xyz[4 * n[3]]) >= 0.)
          report("wrong orientation", t);
      }
      for(unsigned f = 0; f < 4; f++) {
        const tRef r = neigh[4 * t + f];
        if(r == NO_ADJ) {
          report("missing neighbor", t);
          continue;
        }
        const tIdx nb = r >> 2;
        if(nb >= ntet || isDeleted(nb)) {
          report("neighbor is deleted", t);
          continue;
        }
        if(neigh[r] != 4 * t + f) {
          report("asymmetric adjacency", t);
          continue;
        }
        // the shared facet must have the same nodes
        const vIdx *nn = &node[4 * nb];
        for(int k = 0; k < 3; k++) {
          const vIdx v = n[(f + 1 + k) & 3];
          if(v != nn[0] && v != nn[1] && v != nn[2] && v != nn[3])
            report("facet mismatch", t);
        }
        if(delaunay && n[3] != GHOST && nn[3] != GHOST) {
          const vIdx opp = nn[r & 3];
          const double *e = &xyz[4 * opp];
          if(robustPredicates::insphere(&xyz[4 * n[0]], &xyz[4 * n[1]],
                                        &xyz[4 * n[2]], &xyz[4 * n[3]], e) < 0.)
            report("not locally Delaunay", t);
        }
      }
    }
    // duplicate tets (a double covering is combinatorially consistent)
    {
      std::vector<std::array<vIdx, 5>> keys;
      keys.reserve(ntet);
      for(std::size_t t = 0; t < ntet; t++) {
        if(isDeleted((tIdx)t)) continue;
        std::array<vIdx, 5> k = {node[4 * t], node[4 * t + 1], node[4 * t + 2],
                                 node[4 * t + 3], (vIdx)t};
        std::sort(k.begin(), k.begin() + 4);
        keys.push_back(k);
      }
      std::sort(keys.begin(), keys.end());
      for(std::size_t i = 1; i < keys.size(); i++) {
        if(keys[i][0] == keys[i - 1][0] && keys[i][1] == keys[i - 1][1] &&
           keys[i][2] == keys[i - 1][2] && keys[i][3] == keys[i - 1][3]) {
          errors++;
          if(verbose && errors <= 20)
            Msg::Error("pdel3d verify: duplicate tets %u and %u (%u %u %u %u)",
                       keys[i - 1][4], keys[i][4], keys[i][0], keys[i][1],
                       keys[i][2], keys[i][3]);
        }
      }
    }
    if(verbose) {
      if(errors)
        Msg::Error("pdel3d verify: %lu problems", errors);
      else
        Msg::Info("pdel3d verify: %lu tets OK", numRealTets());
    }
    return errors;
  }

} // namespace pdel3d
