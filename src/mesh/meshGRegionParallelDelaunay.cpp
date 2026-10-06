// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The parallel Delaunay mesher (pdel3d): the Delaunay kernel on flat arrays,
// the Moore curve, the constraints and the coloring of the volumes, the
// boundary recovery, the refinement rounds, and the Gmsh driver that meshes a
// group of regions. The optimizer is in meshGRegionParallelOptimize.cpp.
//
// The data layout and the parallel scheme are those of HXT: flat arrays,
// ghost tetrahedra closing the convex hull, each thread working on a piece of
// a Moore curve, and conflicts retried on shifted curves. What differs:
// - the refinement is del3d's: one candidate per tetrahedron, at its
//   circumcenter, or at a point moved inside when that is outside or too
//   close to a node, with the size interpolated from the nodes; candidates are
//   filtered against the previous ones along the curve and in their cavity,
//   and the size field is only evaluated on those kept;
// - walks start from the tetrahedron that generated the candidate, and switch
//   to a straight walk when the visibility walk wanders (CAD point sets);
// - the boundary is recovered locally: the missing triangles and lines by
//   edge removals first (ring triangulations by dynamic programming), then by
//   TetGen's recovery on small cavities around what is left; the recovery of
//   the whole surface mesh is only the fallback;
// - the optimizer adds a small polyhedron reconnection, limited to the
//   tetrahedra that edge removal and node relocation leave well below the
//   threshold, on small cavities with a bounded search
//   (Mesh.OptimizeReconnection*);
// - the coordinates are perturbed during meshing, as in del3d (see
//   meshGRegionParallelDelaunay() below);
// - it supports del3d's features: groups of volumes colored at once, compound
//   surfaces, embedded curves, surfaces and points, mesh size fields, and
//   quadrangles on the boundary through pyramids.

#include <algorithm>
#include <array>
#include <atomic>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <map>
#include <numeric>
#include <stdexcept>
#include <set>
#include "meshGRegionParallelDelaunay.h"
#include "meshGRegionParallelOptimize.h"
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "Context.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "BackgroundMeshTools.h"
#include "Field.h"
#include "meshGRegion.h"
#include "meshRelocateVertex.h"
#include "MQuadrangle.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionBoundaryRecovery.h"

namespace pdel3d {

  // Mesh

  void Mesh::reserveTets(std::size_t n)
  {
    if(n <= tetCapacity()) return;
    // 4 * tet + facet must fit in a tRef, below NO_ADJ
    const std::size_t maxTets = NO_ADJ / 4;
    if(n > maxTets) {
      if(tetCapacity() >= maxTets)
        throw std::length_error("The Parallel Delaunay algorithm is limited "
                                "to 2^30 tets per group of volumes");
      n = maxTets;
    }
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
    // move the tets: each chunk compacts its own range in place (in
    // parallel: a tet never moves up), then the compacted blocks slide down
    // to their place, in sequence (block c may overlap what block c - 1
    // still has to move), then the adjacencies are renumbered in parallel
#pragma omp parallel for schedule(static) num_threads(nchunks)
    for(int c = 0; c < nchunks; c++) {
      const std::size_t first = c * ntet / nchunks;
      for(std::size_t t = first; t < (c + 1) * ntet / nchunks; t++) {
        if(newIndex[t] == NO_TET) continue;
        const std::size_t s = first + newIndex[t] - liveBefore[c];
        if(s == t) continue;
        for(int k = 0; k < 4; k++) {
          node[4 * s + k] = node[4 * t + k];
          neigh[4 * s + k] = neigh[4 * t + k];
        }
        flag[s] = flag[t];
        if(!color.empty()) color[s] = color[t];
      }
    }
    for(int c = 0; c < nchunks; c++) {
      const std::size_t first = c * ntet / nchunks, dest = liveBefore[c],
                        count = liveBefore[c + 1] - liveBefore[c];
      if(dest == first || !count) continue;
      std::memmove(&node[4 * dest], &node[4 * first], 4 * count * sizeof(vIdx));
      std::memmove(&neigh[4 * dest], &neigh[4 * first],
                   4 * count * sizeof(tRef));
      std::memmove(&flag[dest], &flag[first], count * sizeof(std::uint16_t));
      if(!color.empty())
        std::memmove(&color[dest], &color[first],
                     count * sizeof(std::uint32_t));
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

    // insertion status codes (internal)
    enum Status { OK, CONFLICT, TOO_CLOSE, DOUBLE, NO_SPACE, WALK_FAILED };

    // per-thread state, on its own cache lines: the counters at the end of
    // one thread's state and the vectors at the start of the next thread's
    // are both written on every insertion
    struct alignas(128) Local {
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
    inline void unsetDeleted(Mesh &m, tIdx t)
    { m.flag[t] &= ~(F_DELETED | F_UNDELETE); }

    // the Delaunay kernel
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
          unsigned index = 4, outside = 0;
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
              // a facet leading out of the partition: try another one; a
              // conflict only when none leads inside
              if(!outOfPartition(m, n, P)) {
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

      // constrained cavities (after HXT's hxt_tetDelaunayReshape.c)

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
      bool hintAlive(tIdx hint, vIdx hintNode) const
      {
        return hint != NO_TET && hint < ntet.load(std::memory_order_relaxed) &&
               !m.isDeleted(hint) && m.node[4 * hint] == hintNode;
      }

      Status insert(Local &L, vIdx vta, tIdx &hint, vIdx &hintNode)
      {
        const std::size_t prevDeleted = L.deleted.size();
        const bool alive = hintAlive(hint, hintNode);
        if(alive && tetInPartition(m, hint, L.partition)) {
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
          // the cavity can be emptied (a point on a constrained facet)
          if(!reshapeCavity(L, vta, prevDeleted, undeleteTet) ||
             L.deleted.size() == prevDeleted) {
            restoreDeleted(L, prevDeleted);
            return TOO_CLOSE;
          }
        }
        // the size filter against the cavity vertices, when the size of the
        // point was unknown (with a known size, the digging already tested
        // every vertex it reached)
        if(opt.filterOnSize && p[3] <= 0.) {
          double *pv = &m.xyz[4 * vta];
          { // mean size of the cavity vertices
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
      // the first point, the next different one, the next one not on their
      // line and the next one not in their plane
      auto x = [&](std::size_t q) { return &m.xyz[4 * info[q].node]; };
      auto collinear = [&](const double *a, const double *b, const double *c) {
        for(int q = 0; q < 3; q++) {
          const int r = (q + 1) % 3;
          const double pa[2] = {a[q], a[r]}, pb[2] = {b[q], b[r]},
                       pc[2] = {c[q], c[r]};
          if(robustPredicates::orient2d(pa, pb, pc) != 0.) return false;
        }
        return true;
      };
      std::size_t i = 0, j = 1, k, l;
      while(j < n && x(j)[0] == x(i)[0] && x(j)[1] == x(i)[1] &&
            x(j)[2] == x(i)[2])
        j++;
      for(k = j + 1; k < n && collinear(x(i), x(j), x(k)); k++) {}
      int orientation = 0;
      for(l = k + 1; l < n; l++) {
        orientation = sign(robustPredicates::orient3d(x(l), x(k), x(j), x(i)));
        if(orientation) break;
      }
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

  // driver

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
    // the static filters bound the coordinate differences
    robustPredicates::exactinit(bmax[0] - bmin[0], bmax[1] - bmin[1],
                                bmax[2] - bmin[2]);

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
        const std::size_t ntet0 = K.ntet;
#pragma omp parallel num_threads(nthreads)
        {
          const int tid = Msg::GetThreadNum();
          Local &L = locals[tid];
          L.noSpace = false;
          const Partition &P = L.partition;
          // starting tet, chosen before any thread inserts: the hint of the
          // first vertex when it is alive and in the partition, otherwise any
          // live tet of the partition
          L.curTet = NO_TET;
          bool todo = false;
          for(std::size_t i = 0; i < P.numElem && !todo; i++) {
            const NodeInfo &ni = pass[(P.firstElem + i) % passLength];
            if(ni.status != ST_TODO) continue;
            todo = true;
            if(K.hintAlive(ni.hint, ni.hintNode) &&
               tetInPartition(m, ni.hint, P))
              L.curTet = ni.hint;
            else {
              for(std::size_t t = 0; t < ntet0; t++) {
                if(!m.isDeleted((tIdx)t) && tetInPartition(m, (tIdx)t, P)) {
                  L.curTet = (tIdx)t;
                  break;
                }
              }
            }
          }
          if(todo && L.curTet == NO_TET) L.noStart++;
#pragma omp barrier
          for(std::size_t i = 0; i < P.numElem && L.curTet != NO_TET; i++) {
            NodeInfo &ni = pass[(P.firstElem + i) % passLength];
            if(ni.status != ST_TODO) continue;
            if(L.noSpace) break;
            {
              switch(K.insert(L, ni.node, ni.hint, ni.hintNode)) {
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

  // verification

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

// Moore curve (a closed Hilbert curve) coordinate of the vertices, computed
// with the state-transition tables of HXT (hxt_vertices.c, C. Marot): the
// 63-bit Z-order key of the quantized coordinates is converted 9 bits (one
// octree level per axis, 3 levels) at a time; the first table also closes the
// curve. Vertices sorted on this coordinate are spatially coherent, and
// contiguous ranges of the curve make the partitions of the parallel
// insertion.

namespace pdel3d {

  namespace {

    // Butz's curve: 12 states x 512 entries, each entry packs the next state
    // above bit 9 and the 9 output bits below
    const std::uint16_t hilbert3[6144] = {
      0,    2563, 3079, 2564, 513,  514,  5126, 5125, 5692, 4671, 5691, 1592,
      573,  574,  5178, 5177, 520,  1033, 1547, 1034, 3599, 5646, 1548, 5645,
      4150, 567,  4149, 3124, 2609, 3632, 2610, 3123, 3098, 1565, 539,  540,
      3097, 1566, 5656, 2591, 3106, 1573, 547,  548,  3105, 1574, 5664, 2599,
      528,  1041, 1555, 1042, 3607, 5654, 1556, 5653, 4142, 559,  4141, 3116,
      2601, 3624, 2602, 3115, 576,  1089, 1603, 1090, 3655, 5702, 1604, 5701,
      3674, 3673, 2141, 2142, 1115, 4696, 1116, 1631, 4732, 1149, 5247, 1150,
      4731, 5754, 2168, 5753, 3682, 3681, 2149, 2150, 1123, 4704, 1124, 1639,
      1096, 4175, 73,   4686, 2123, 2124, 74,   4685, 1104, 4183, 81,   4694,
      2131, 2132, 82,   4693, 3190, 1649, 1143, 4208, 3189, 1650, 3700, 3699,
      3182, 1641, 1135, 4200, 3181, 1642, 3692, 3691, 5844, 4823, 5843, 1744,
      725,  726,  5330, 5329, 728,  1241, 1755, 1242, 3807, 5854, 1756, 5853,
      5836, 4815, 5835, 1736, 717,  718,  5322, 5321, 3270, 1729, 1223, 4288,
      3269, 1730, 3780, 3779, 3818, 3817, 2285, 2286, 1259, 4840, 1260, 1775,
      736,  1249, 1763, 1250, 3815, 5862, 1764, 5861, 3826, 3825, 2293, 2294,
      1267, 4848, 1268, 1783, 3322, 1789, 763,  764,  3321, 1790, 5880, 2815,
      640,  1153, 1667, 1154, 3719, 5766, 1668, 5765, 3738, 3737, 2205, 2206,
      1179, 4760, 1180, 1695, 4796, 1213, 5311, 1214, 4795, 5818, 2232, 5817,
      3746, 3745, 2213, 2214, 1187, 4768, 1188, 1703, 1160, 4239, 137,  4750,
      2187, 2188, 138,  4749, 1168, 4247, 145,  4758, 2195, 2196, 146,  4757,
      3254, 1713, 1207, 4272, 3253, 1714, 3764, 3763, 3246, 1705, 1199, 4264,
      3245, 1706, 3756, 3755, 3558, 2017, 1511, 4576, 3557, 2018, 4068, 4067,
      3550, 2009, 1503, 4568, 3549, 2010, 4060, 4059, 1000, 1513, 2027, 1514,
      4079, 6126, 2028, 6125, 4566, 983,  4565, 3540, 3025, 4048, 3026, 3539,
      4094, 4093, 2553, 2554, 511,  4604, 3576, 4603, 4034, 4033, 2501, 2502,
      1475, 5056, 1476, 1991, 1008, 1521, 2035, 1522, 4087, 6134, 2036, 6133,
      4558, 975,  4557, 3532, 3017, 4040, 3018, 3531, 5556, 5555, 437,  5042,
      6071, 2992, 438,  5041, 5548, 5547, 429,  5034, 6063, 2984, 430,  5033,
      3466, 1933, 907,  908,  3465, 1934, 6024, 2959, 3474, 1941, 915,  916,
      3473, 1942, 6032, 2967, 952,  1465, 1979, 1466, 4031, 6078, 1980, 6077,
      6052, 5031, 6051, 1952, 933,  934,  5538, 5537, 4996, 1413, 5511, 1414,
      4995, 6018, 2432, 6017, 6044, 5023, 6043, 1944, 925,  926,  5530, 5529,
      5908, 4887, 5907, 1808, 789,  790,  5394, 5393, 792,  1305, 1819, 1306,
      3871, 5918, 1820, 5917, 5900, 4879, 5899, 1800, 781,  782,  5386, 5385,
      3334, 1793, 1287, 4352, 3333, 1794, 3844, 3843, 3882, 3881, 2349, 2350,
      1323, 4904, 1324, 1839, 800,  1313, 1827, 1314, 3879, 5926, 1828, 5925,
      3890, 3889, 2357, 2358, 1331, 4912, 1332, 1847, 3386, 1853, 827,  828,
      3385, 1854, 5944, 2879, 5492, 5491, 373,  4978, 6007, 2928, 374,  4977,
      5484, 5483, 365,  4970, 5999, 2920, 366,  4969, 3402, 1869, 843,  844,
      3401, 1870, 5960, 2895, 3410, 1877, 851,  852,  3409, 1878, 5968, 2903,
      888,  1401, 1915, 1402, 3967, 6014, 1916, 6013, 5988, 4967, 5987, 1888,
      869,  870,  5474, 5473, 4932, 1349, 5447, 1350, 4931, 5954, 2368, 5953,
      5980, 4959, 5979, 1880, 861,  862,  5466, 5465, 512,  1025, 1539, 1026,
      3591, 5638, 1540, 5637, 3610, 3609, 2077, 2078, 1051, 4632, 1052, 1567,
      4668, 1085, 5183, 1086, 4667, 5690, 2104, 5689, 3618, 3617, 2085, 2086,
      1059, 4640, 1060, 1575, 1032, 4111, 9,    4622, 2059, 2060, 10,   4621,
      1040, 4119, 17,   4630, 2067, 2068, 18,   4629, 3126, 1585, 1079, 4144,
      3125, 1586, 3636, 3635, 3118, 1577, 1071, 4136, 3117, 1578, 3628, 3627,
      4070, 4069, 2529, 2530, 487,  4580, 3552, 4579, 4606, 1023, 4605, 3580,
      3065, 4088, 3066, 3579, 4062, 4061, 2521, 2522, 479,  4572, 3544, 4571,
      4546, 451,  4545, 5568, 3013, 452,  3014, 2503, 1512, 4591, 489,  5102,
      2539, 2540, 490,  5101, 1520, 4599, 497,  5110, 2547, 2548, 498,  5109,
      3542, 2001, 1495, 4560, 3541, 2002, 4052, 4051, 3534, 1993, 1487, 4552,
      3533, 1994, 4044, 4043, 1088, 4167, 65,   4678, 2115, 2116, 66,   4677,
      72,   2635, 3151, 2636, 585,  586,  5198, 5197, 4186, 91,   4185, 5208,
      2653, 92,   2654, 2143, 80,   2643, 3159, 2644, 593,  594,  5206, 5205,
      5244, 5243, 125,  4730, 5759, 2680, 126,  4729, 3702, 3701, 2161, 2162,
      119,  4212, 3184, 4211, 4194, 99,   4193, 5216, 2661, 100,  2662, 2151,
      3694, 3693, 2153, 2154, 111,  4204, 3176, 4203, 6068, 5047, 6067, 1968,
      949,  950,  5554, 5553, 1464, 4543, 441,  5054, 2491, 2492, 442,  5053,
      6060, 5039, 6059, 1960, 941,  942,  5546, 5545, 5028, 1445, 5543, 1446,
      5027, 6050, 2464, 6049, 3978, 3977, 2445, 2446, 1419, 5000, 1420, 1935,
      5508, 5507, 389,  4994, 6023, 2944, 390,  4993, 3986, 3985, 2453, 2454,
      1427, 5008, 1428, 1943, 5020, 1437, 5535, 1438, 5019, 6042, 2456, 6041,
      4820, 1237, 5335, 1238, 4819, 5842, 2256, 5841, 4330, 235,  4329, 5352,
      2797, 236,  2798, 2287, 1240, 4319, 217,  4830, 2267, 2268, 218,  4829,
      1248, 4327, 225,  4838, 2275, 2276, 226,  4837, 4812, 1229, 5327, 1230,
      4811, 5834, 2248, 5833, 4338, 243,  4337, 5360, 2805, 244,  2806, 2295,
      3782, 3781, 2241, 2242, 199,  4292, 3264, 4291, 3834, 3833, 2301, 2302,
      1275, 4856, 1276, 1791, 4884, 1301, 5399, 1302, 4883, 5906, 2320, 5905,
      4394, 299,  4393, 5416, 2861, 300,  2862, 2351, 1304, 4383, 281,  4894,
      2331, 2332, 282,  4893, 1312, 4391, 289,  4902, 2339, 2340, 290,  4901,
      4876, 1293, 5391, 1294, 4875, 5898, 2312, 5897, 4402, 307,  4401, 5424,
      2869, 308,  2870, 2359, 3846, 3845, 2305, 2306, 263,  4356, 3328, 4355,
      3898, 3897, 2365, 2366, 1339, 4920, 1340, 1855, 1152, 4231, 129,  4742,
      2179, 2180, 130,  4741, 136,  2699, 3215, 2700, 649,  650,  5262, 5261,
      4250, 155,  4249, 5272, 2717, 156,  2718, 2207, 144,  2707, 3223, 2708,
      657,  658,  5270, 5269, 5308, 5307, 189,  4794, 5823, 2744, 190,  4793,
      3766, 3765, 2225, 2226, 183,  4276, 3248, 4275, 4258, 163,  4257, 5280,
      2725, 164,  2726, 2215, 3758, 3757, 2217, 2218, 175,  4268, 3240, 4267,
      6004, 4983, 6003, 1904, 885,  886,  5490, 5489, 1400, 4479, 377,  4990,
      2427, 2428, 378,  4989, 5996, 4975, 5995, 1896, 877,  878,  5482, 5481,
      4964, 1381, 5479, 1382, 4963, 5986, 2400, 5985, 3914, 3913, 2381, 2382,
      1355, 4936, 1356, 1871, 5444, 5443, 325,  4930, 5959, 2880, 326,  4929,
      3922, 3921, 2389, 2390, 1363, 4944, 1364, 1879, 4956, 1373, 5471, 1374,
      4955, 5978, 2392, 5977, 1024, 4103, 1,    4614, 2051, 2052, 2,    4613,
      8,    2571, 3087, 2572, 521,  522,  5134, 5133, 4122, 27,   4121, 5144,
      2589, 28,   2590, 2079, 16,   2579, 3095, 2580, 529,  530,  5142, 5141,
      5180, 5179, 61,   4666, 5695, 2616, 62,   4665, 3638, 3637, 2097, 2098,
      55,   4148, 3120, 4147, 4130, 35,   4129, 5152, 2597, 36,   2598, 2087,
      3630, 3629, 2089, 2090, 47,   4140, 3112, 4139, 5332, 5331, 213,  4818,
      5847, 2768, 214,  4817, 5324, 5323, 205,  4810, 5839, 2760, 206,  4809,
      3306, 1773, 747,  748,  3305, 1774, 5864, 2799, 3314, 1781, 755,  756,
      3313, 1782, 5872, 2807, 216,  2779, 3295, 2780, 729,  730,  5342, 5341,
      4294, 711,  4293, 3268, 2753, 3776, 2754, 3267, 224,  2787, 3303, 2788,
      737,  738,  5350, 5349, 4346, 251,  4345, 5368, 2813, 252,  2814, 2303,
      4582, 999,  4581, 3556, 3041, 4064, 3042, 3555, 488,  3051, 3567, 3052,
      1001, 1002, 5614, 5613, 3582, 2041, 1535, 4600, 3581, 2042, 4092, 4091,
      496,  3059, 3575, 3060, 1009, 1010, 5622, 5621, 4574, 991,  4573, 3548,
      3033, 4056, 3034, 3547, 4054, 4053, 2513, 2514, 471,  4564, 3536, 4563,
      3522, 1989, 963,  964,  3521, 1990, 6080, 3015, 4046, 4045, 2505, 2506,
      463,  4556, 3528, 4555, 5396, 5395, 277,  4882, 5911, 2832, 278,  4881,
      5388, 5387, 269,  4874, 5903, 2824, 270,  4873, 3370, 1837, 811,  812,
      3369, 1838, 5928, 2863, 3378, 1845, 819,  820,  3377, 1846, 5936, 2871,
      280,  2843, 3359, 2844, 793,  794,  5406, 5405, 4358, 775,  4357, 3332,
      2817, 3840, 2818, 3331, 288,  2851, 3367, 2852, 801,  802,  5414, 5413,
      4410, 315,  4409, 5432, 2877, 316,  2878, 2367, 64,   2627, 3143, 2628,
      577,  578,  5190, 5189, 5756, 4735, 5755, 1656, 637,  638,  5242, 5241,
      584,  1097, 1611, 1098, 3663, 5710, 1612, 5709, 4214, 631,  4213, 3188,
      2673, 3696, 2674, 3187, 3162, 1629, 603,  604,  3161, 1630, 5720, 2655,
      3170, 1637, 611,  612,  3169, 1638, 5728, 2663, 592,  1105, 1619, 1106,
      3671, 5718, 1620, 5717, 4206, 623,  4205, 3180, 2665, 3688, 2666, 3179,
      128,  2691, 3207, 2692, 641,  642,  5254, 5253, 5820, 4799, 5819, 1720,
      701,  702,  5306, 5305, 648,  1161, 1675, 1162, 3727, 5774, 1676, 5773,
      4278, 695,  4277, 3252, 2737, 3760, 2738, 3251, 3226, 1693, 667,  668,
      3225, 1694, 5784, 2719, 3234, 1701, 675,  676,  3233, 1702, 5792, 2727,
      656,  1169, 1683, 1170, 3735, 5782, 1684, 5781, 4270, 687,  4269, 3244,
      2729, 3752, 2730, 3243, 5044, 1461, 5559, 1462, 5043, 6066, 2480, 6065,
      4490, 395,  4489, 5512, 2957, 396,  2958, 2447, 440,  3003, 3519, 3004,
      953,  954,  5566, 5565, 6020, 4999, 6019, 1920, 901,  902,  5506, 5505,
      5036, 1453, 5551, 1454, 5035, 6058, 2472, 6057, 4498, 403,  4497, 5520,
      2965, 404,  2966, 2455, 5540, 5539, 421,  5026, 6055, 2976, 422,  5025,
      5532, 5531, 413,  5018, 6047, 2968, 414,  5017, 4980, 1397, 5495, 1398,
      4979, 6002, 2416, 6001, 4426, 331,  4425, 5448, 2893, 332,  2894, 2383,
      376,  2939, 3455, 2940, 889,  890,  5502, 5501, 5956, 4935, 5955, 1856,
      837,  838,  5442, 5441, 4972, 1389, 5487, 1390, 4971, 5994, 2408, 5993,
      4434, 339,  4433, 5456, 2901, 340,  2902, 2391, 5476, 5475, 357,  4962,
      5991, 2912, 358,  4961, 5468, 5467, 349,  4954, 5983, 2904, 350,  4953,
      3750, 3749, 2209, 2210, 167,  4260, 3232, 4259, 4286, 703,  4285, 3260,
      2745, 3768, 2746, 3259, 3742, 3741, 2201, 2202, 159,  4252, 3224, 4251,
      4226, 131,  4225, 5248, 2693, 132,  2694, 2183, 1192, 4271, 169,  4782,
      2219, 2220, 170,  4781, 1200, 4279, 177,  4790, 2227, 2228, 178,  4789,
      3222, 1681, 1175, 4240, 3221, 1682, 3732, 3731, 3214, 1673, 1167, 4232,
      3213, 1674, 3724, 3723, 1216, 4295, 193,  4806, 2243, 2244, 194,  4805,
      200,  2763, 3279, 2764, 713,  714,  5326, 5325, 4314, 219,  4313, 5336,
      2781, 220,  2782, 2271, 208,  2771, 3287, 2772, 721,  722,  5334, 5333,
      5372, 5371, 253,  4858, 5887, 2808, 254,  4857, 3830, 3829, 2289, 2290,
      247,  4340, 3312, 4339, 4322, 227,  4321, 5344, 2789, 228,  2790, 2279,
      3822, 3821, 2281, 2282, 239,  4332, 3304, 4331, 3686, 3685, 2145, 2146,
      103,  4196, 3168, 4195, 4222, 639,  4221, 3196, 2681, 3704, 2682, 3195,
      3678, 3677, 2137, 2138, 95,   4188, 3160, 4187, 4162, 67,   4161, 5184,
      2629, 68,   2630, 2119, 1128, 4207, 105,  4718, 2155, 2156, 106,  4717,
      1136, 4215, 113,  4726, 2163, 2164, 114,  4725, 3158, 1617, 1111, 4176,
      3157, 1618, 3668, 3667, 3150, 1609, 1103, 4168, 3149, 1610, 3660, 3659,
      4660, 1077, 5175, 1078, 4659, 5682, 2096, 5681, 4106, 11,   4105, 5128,
      2573, 12,   2574, 2063, 56,   2619, 3135, 2620, 569,  570,  5182, 5181,
      5636, 4615, 5635, 1536, 517,  518,  5122, 5121, 4652, 1069, 5167, 1070,
      4651, 5674, 2088, 5673, 4114, 19,   4113, 5136, 2581, 20,   2582, 2071,
      5156, 5155, 37,   4642, 5671, 2592, 38,   4641, 5148, 5147, 29,   4634,
      5663, 2584, 30,   4633, 5460, 5459, 341,  4946, 5975, 2896, 342,  4945,
      5452, 5451, 333,  4938, 5967, 2888, 334,  4937, 3434, 1901, 875,  876,
      3433, 1902, 5992, 2927, 3442, 1909, 883,  884,  3441, 1910, 6000, 2935,
      344,  2907, 3423, 2908, 857,  858,  5470, 5469, 4422, 839,  4421, 3396,
      2881, 3904, 2882, 3395, 352,  2915, 3431, 2916, 865,  866,  5478, 5477,
      4474, 379,  4473, 5496, 2941, 380,  2942, 2431, 1280, 4359, 257,  4870,
      2307, 2308, 258,  4869, 264,  2827, 3343, 2828, 777,  778,  5390, 5389,
      4378, 283,  4377, 5400, 2845, 284,  2846, 2335, 272,  2835, 3351, 2836,
      785,  786,  5398, 5397, 5436, 5435, 317,  4922, 5951, 2872, 318,  4921,
      3894, 3893, 2353, 2354, 311,  4404, 3376, 4403, 4386, 291,  4385, 5408,
      2853, 292,  2854, 2343, 3886, 3885, 2345, 2346, 303,  4396, 3368, 4395,
      5524, 5523, 405,  5010, 6039, 2960, 406,  5009, 5516, 5515, 397,  5002,
      6031, 2952, 398,  5001, 3498, 1965, 939,  940,  3497, 1966, 6056, 2991,
      3506, 1973, 947,  948,  3505, 1974, 6064, 2999, 408,  2971, 3487, 2972,
      921,  922,  5534, 5533, 4486, 903,  4485, 3460, 2945, 3968, 2946, 3459,
      416,  2979, 3495, 2980, 929,  930,  5542, 5541, 4538, 443,  4537, 5560,
      3005, 444,  3006, 2495, 5076, 1493, 5591, 1494, 5075, 6098, 2512, 6097,
      4586, 491,  4585, 5608, 3053, 492,  3054, 2543, 1496, 4575, 473,  5086,
      2523, 2524, 474,  5085, 1504, 4583, 481,  5094, 2531, 2532, 482,  5093,
      5068, 1485, 5583, 1486, 5067, 6090, 2504, 6089, 4594, 499,  4593, 5616,
      3061, 500,  3062, 2551, 4038, 4037, 2497, 2498, 455,  4548, 3520, 4547,
      4090, 4089, 2557, 2558, 1531, 5112, 1532, 2047, 4262, 679,  4261, 3236,
      2721, 3744, 2722, 3235, 168,  2731, 3247, 2732, 681,  682,  5294, 5293,
      3262, 1721, 1215, 4280, 3261, 1722, 3772, 3771, 176,  2739, 3255, 2740,
      689,  690,  5302, 5301, 4254, 671,  4253, 3228, 2713, 3736, 2714, 3227,
      3734, 3733, 2193, 2194, 151,  4244, 3216, 4243, 3202, 1669, 643,  644,
      3201, 1670, 5760, 2695, 3726, 3725, 2185, 2186, 143,  4236, 3208, 4235,
      5972, 4951, 5971, 1872, 853,  854,  5458, 5457, 856,  1369, 1883, 1370,
      3935, 5982, 1884, 5981, 5964, 4943, 5963, 1864, 845,  846,  5450, 5449,
      3398, 1857, 1351, 4416, 3397, 1858, 3908, 3907, 3946, 3945, 2413, 2414,
      1387, 4968, 1388, 1903, 864,  1377, 1891, 1378, 3943, 5990, 1892, 5989,
      3954, 3953, 2421, 2422, 1395, 4976, 1396, 1911, 3450, 1917, 891,  892,
      3449, 1918, 6008, 2943, 192,  2755, 3271, 2756, 705,  706,  5318, 5317,
      5884, 4863, 5883, 1784, 765,  766,  5370, 5369, 712,  1225, 1739, 1226,
      3791, 5838, 1740, 5837, 4342, 759,  4341, 3316, 2801, 3824, 2802, 3315,
      3290, 1757, 731,  732,  3289, 1758, 5848, 2783, 3298, 1765, 739,  740,
      3297, 1766, 5856, 2791, 720,  1233, 1747, 1234, 3799, 5846, 1748, 5845,
      4334, 751,  4333, 3308, 2793, 3816, 2794, 3307, 256,  2819, 3335, 2820,
      769,  770,  5382, 5381, 5948, 4927, 5947, 1848, 829,  830,  5434, 5433,
      776,  1289, 1803, 1290, 3855, 5902, 1804, 5901, 4406, 823,  4405, 3380,
      2865, 3888, 2866, 3379, 3354, 1821, 795,  796,  3353, 1822, 5912, 2847,
      3362, 1829, 803,  804,  3361, 1830, 5920, 2855, 784,  1297, 1811, 1298,
      3863, 5910, 1812, 5909, 4398, 815,  4397, 3372, 2857, 3880, 2858, 3371,
      4198, 615,  4197, 3172, 2657, 3680, 2658, 3171, 104,  2667, 3183, 2668,
      617,  618,  5230, 5229, 3198, 1657, 1151, 4216, 3197, 1658, 3708, 3707,
      112,  2675, 3191, 2676, 625,  626,  5238, 5237, 4190, 607,  4189, 3164,
      2649, 3672, 2650, 3163, 3670, 3669, 2129, 2130, 87,   4180, 3152, 4179,
      3138, 1605, 579,  580,  3137, 1606, 5696, 2631, 3662, 3661, 2121, 2122,
      79,   4172, 3144, 4171, 6036, 5015, 6035, 1936, 917,  918,  5522, 5521,
      920,  1433, 1947, 1434, 3999, 6046, 1948, 6045, 6028, 5007, 6027, 1928,
      909,  910,  5514, 5513, 3462, 1921, 1415, 4480, 3461, 1922, 3972, 3971,
      4010, 4009, 2477, 2478, 1451, 5032, 1452, 1967, 928,  1441, 1955, 1442,
      4007, 6054, 1956, 6053, 4018, 4017, 2485, 2486, 1459, 5040, 1460, 1975,
      3514, 1981, 955,  956,  3513, 1982, 6072, 3007, 5172, 5171, 53,   4658,
      5687, 2608, 54,   4657, 5164, 5163, 45,   4650, 5679, 2600, 46,   4649,
      3082, 1549, 523,  524,  3081, 1550, 5640, 2575, 3090, 1557, 531,  532,
      3089, 1558, 5648, 2583, 568,  1081, 1595, 1082, 3647, 5694, 1596, 5693,
      5668, 4647, 5667, 1568, 549,  550,  5154, 5153, 4612, 1029, 5127, 1030,
      4611, 5634, 2048, 5633, 5660, 4639, 5659, 1560, 541,  542,  5146, 5145,
      5588, 5587, 469,  5074, 6103, 3024, 470,  5073, 5580, 5579, 461,  5066,
      6095, 3016, 462,  5065, 3562, 2029, 1003, 1004, 3561, 2030, 6120, 3055,
      3570, 2037, 1011, 1012, 3569, 2038, 6128, 3063, 472,  3035, 3551, 3036,
      985,  986,  5598, 5597, 4550, 967,  4549, 3524, 3009, 4032, 3010, 3523,
      480,  3043, 3559, 3044, 993,  994,  5606, 5605, 4602, 507,  4601, 5624,
      3069, 508,  3070, 2559, 3238, 1697, 1191, 4256, 3237, 1698, 3748, 3747,
      3230, 1689, 1183, 4248, 3229, 1690, 3740, 3739, 680,  1193, 1707, 1194,
      3759, 5806, 1708, 5805, 4246, 663,  4245, 3220, 2705, 3728, 2706, 3219,
      3774, 3773, 2233, 2234, 191,  4284, 3256, 4283, 3714, 3713, 2181, 2182,
      1155, 4736, 1156, 1671, 688,  1201, 1715, 1202, 3767, 5814, 1716, 5813,
      4238, 655,  4237, 3212, 2697, 3720, 2698, 3211, 3174, 1633, 1127, 4192,
      3173, 1634, 3684, 3683, 3166, 1625, 1119, 4184, 3165, 1626, 3676, 3675,
      616,  1129, 1643, 1130, 3695, 5742, 1644, 5741, 4182, 599,  4181, 3156,
      2641, 3664, 2642, 3155, 3710, 3709, 2169, 2170, 127,  4220, 3192, 4219,
      3650, 3649, 2117, 2118, 1091, 4672, 1092, 1607, 624,  1137, 1651, 1138,
      3703, 5750, 1652, 5749, 4174, 591,  4173, 3148, 2633, 3656, 2634, 3147,
      4948, 1365, 5463, 1366, 4947, 5970, 2384, 5969, 4458, 363,  4457, 5480,
      2925, 364,  2926, 2415, 1368, 4447, 345,  4958, 2395, 2396, 346,  4957,
      1376, 4455, 353,  4966, 2403, 2404, 354,  4965, 4940, 1357, 5455, 1358,
      4939, 5962, 2376, 5961, 4466, 371,  4465, 5488, 2933, 372,  2934, 2423,
      3910, 3909, 2369, 2370, 327,  4420, 3392, 4419, 3962, 3961, 2429, 2430,
      1403, 4984, 1404, 1919, 5012, 1429, 5527, 1430, 5011, 6034, 2448, 6033,
      4522, 427,  4521, 5544, 2989, 428,  2990, 2479, 1432, 4511, 409,  5022,
      2459, 2460, 410,  5021, 1440, 4519, 417,  5030, 2467, 2468, 418,  5029,
      5004, 1421, 5519, 1422, 5003, 6026, 2440, 6025, 4530, 435,  4529, 5552,
      2997, 436,  2998, 2487, 3974, 3973, 2433, 2434, 391,  4484, 3456, 4483,
      4026, 4025, 2493, 2494, 1467, 5048, 1468, 1983, 704,  1217, 1731, 1218,
      3783, 5830, 1732, 5829, 3802, 3801, 2269, 2270, 1243, 4824, 1244, 1759,
      4860, 1277, 5375, 1278, 4859, 5882, 2296, 5881, 3810, 3809, 2277, 2278,
      1251, 4832, 1252, 1767, 1224, 4303, 201,  4814, 2251, 2252, 202,  4813,
      1232, 4311, 209,  4822, 2259, 2260, 210,  4821, 3318, 1777, 1271, 4336,
      3317, 1778, 3828, 3827, 3310, 1769, 1263, 4328, 3309, 1770, 3820, 3819,
      5684, 4663, 5683, 1584, 565,  566,  5170, 5169, 1080, 4159, 57,   4670,
      2107, 2108, 58,   4669, 5676, 4655, 5675, 1576, 557,  558,  5162, 5161,
      4644, 1061, 5159, 1062, 4643, 5666, 2080, 5665, 3594, 3593, 2061, 2062,
      1035, 4616, 1036, 1551, 5124, 5123, 5,    4610, 5639, 2560, 6,    4609,
      3602, 3601, 2069, 2070, 1043, 4624, 1044, 1559, 4636, 1053, 5151, 1054,
      4635, 5658, 2072, 5657, 768,  1281, 1795, 1282, 3847, 5894, 1796, 5893,
      3866, 3865, 2333, 2334, 1307, 4888, 1308, 1823, 4924, 1341, 5439, 1342,
      4923, 5946, 2360, 5945, 3874, 3873, 2341, 2342, 1315, 4896, 1316, 1831,
      1288, 4367, 265,  4878, 2315, 2316, 266,  4877, 1296, 4375, 273,  4886,
      2323, 2324, 274,  4885, 3382, 1841, 1335, 4400, 3381, 1842, 3892, 3891,
      3374, 1833, 1327, 4392, 3373, 1834, 3884, 3883, 6100, 5079, 6099, 2000,
      981,  982,  5586, 5585, 984,  1497, 2011, 1498, 4063, 6110, 2012, 6109,
      6092, 5071, 6091, 1992, 973,  974,  5578, 5577, 3526, 1985, 1479, 4544,
      3525, 1986, 4036, 4035, 4074, 4073, 2541, 2542, 1515, 5096, 1516, 2031,
      992,  1505, 2019, 1506, 4071, 6118, 2020, 6117, 4082, 4081, 2549, 2550,
      1523, 5104, 1524, 2039, 3578, 2045, 1019, 1020, 3577, 2046, 6136, 3071,
      5940, 4919, 5939, 1840, 821,  822,  5426, 5425, 1336, 4415, 313,  4926,
      2363, 2364, 314,  4925, 5932, 4911, 5931, 1832, 813,  814,  5418, 5417,
      4900, 1317, 5415, 1318, 4899, 5922, 2336, 5921, 3850, 3849, 2317, 2318,
      1291, 4872, 1292, 1807, 5380, 5379, 261,  4866, 5895, 2816, 262,  4865,
      3858, 3857, 2325, 2326, 1299, 4880, 1300, 1815, 4892, 1309, 5407, 1310,
      4891, 5914, 2328, 5913, 832,  1345, 1859, 1346, 3911, 5958, 1860, 5957,
      3930, 3929, 2397, 2398, 1371, 4952, 1372, 1887, 4988, 1405, 5503, 1406,
      4987, 6010, 2424, 6009, 3938, 3937, 2405, 2406, 1379, 4960, 1380, 1895,
      1352, 4431, 329,  4942, 2379, 2380, 330,  4941, 1360, 4439, 337,  4950,
      2387, 2388, 338,  4949, 3446, 1905, 1399, 4464, 3445, 1906, 3956, 3955,
      3438, 1897, 1391, 4456, 3437, 1898, 3948, 3947, 5108, 1525, 5623, 1526,
      5107, 6130, 2544, 6129, 4554, 459,  4553, 5576, 3021, 460,  3022, 2511,
      504,  3067, 3583, 3068, 1017, 1018, 5630, 5629, 6084, 5063, 6083, 1984,
      965,  966,  5570, 5569, 5100, 1517, 5615, 1518, 5099, 6122, 2536, 6121,
      4562, 467,  4561, 5584, 3029, 468,  3030, 2519, 5604, 5603, 485,  5090,
      6119, 3040, 486,  5089, 5596, 5595, 477,  5082, 6111, 3032, 478,  5081,
      896,  1409, 1923, 1410, 3975, 6022, 1924, 6021, 3994, 3993, 2461, 2462,
      1435, 5016, 1436, 1951, 5052, 1469, 5567, 1470, 5051, 6074, 2488, 6073,
      4002, 4001, 2469, 2470, 1443, 5024, 1444, 1959, 1416, 4495, 393,  5006,
      2443, 2444, 394,  5005, 1424, 4503, 401,  5014, 2451, 2452, 402,  5013,
      3510, 1969, 1463, 4528, 3509, 1970, 4020, 4019, 3502, 1961, 1455, 4520,
      3501, 1962, 4012, 4011, 5876, 4855, 5875, 1776, 757,  758,  5362, 5361,
      1272, 4351, 249,  4862, 2299, 2300, 250,  4861, 5868, 4847, 5867, 1768,
      749,  750,  5354, 5353, 4836, 1253, 5351, 1254, 4835, 5858, 2272, 5857,
      3786, 3785, 2253, 2254, 1227, 4808, 1228, 1743, 5316, 5315, 197,  4802,
      5831, 2752, 198,  4801, 3794, 3793, 2261, 2262, 1235, 4816, 1236, 1751,
      4828, 1245, 5343, 1246, 4827, 5850, 2264, 5849, 5300, 5299, 181,  4786,
      5815, 2736, 182,  4785, 5292, 5291, 173,  4778, 5807, 2728, 174,  4777,
      3210, 1677, 651,  652,  3209, 1678, 5768, 2703, 3218, 1685, 659,  660,
      3217, 1686, 5776, 2711, 696,  1209, 1723, 1210, 3775, 5822, 1724, 5821,
      5796, 4775, 5795, 1696, 677,  678,  5282, 5281, 4740, 1157, 5255, 1158,
      4739, 5762, 2176, 5761, 5788, 4767, 5787, 1688, 669,  670,  5274, 5273,
      4628, 1045, 5143, 1046, 4627, 5650, 2064, 5649, 4138, 43,   4137, 5160,
      2605, 44,   2606, 2095, 1048, 4127, 25,   4638, 2075, 2076, 26,   4637,
      1056, 4135, 33,   4646, 2083, 2084, 34,   4645, 4620, 1037, 5135, 1038,
      4619, 5642, 2056, 5641, 4146, 51,   4145, 5168, 2613, 52,   2614, 2103,
      3590, 3589, 2049, 2050, 7,    4100, 3072, 4099, 3642, 3641, 2109, 2110,
      1083, 4664, 1084, 1599, 5236, 5235, 117,  4722, 5751, 2672, 118,  4721,
      5228, 5227, 109,  4714, 5743, 2664, 110,  4713, 3146, 1613, 587,  588,
      3145, 1614, 5704, 2639, 3154, 1621, 595,  596,  3153, 1622, 5712, 2647,
      632,  1145, 1659, 1146, 3711, 5758, 1660, 5757, 5732, 4711, 5731, 1632,
      613,  614,  5218, 5217, 4676, 1093, 5191, 1094, 4675, 5698, 2112, 5697,
      5724, 4703, 5723, 1624, 605,  606,  5210, 5209, 4916, 1333, 5431, 1334,
      4915, 5938, 2352, 5937, 4362, 267,  4361, 5384, 2829, 268,  2830, 2319,
      312,  2875, 3391, 2876, 825,  826,  5438, 5437, 5892, 4871, 5891, 1792,
      773,  774,  5378, 5377, 4908, 1325, 5423, 1326, 4907, 5930, 2344, 5929,
      4370, 275,  4369, 5392, 2837, 276,  2838, 2327, 5412, 5411, 293,  4898,
      5927, 2848, 294,  4897, 5404, 5403, 285,  4890, 5919, 2840, 286,  4889,
      4852, 1269, 5367, 1270, 4851, 5874, 2288, 5873, 4298, 203,  4297, 5320,
      2765, 204,  2766, 2255, 248,  2811, 3327, 2812, 761,  762,  5374, 5373,
      5828, 4807, 5827, 1728, 709,  710,  5314, 5313, 4844, 1261, 5359, 1262,
      4843, 5866, 2280, 5865, 4306, 211,  4305, 5328, 2773, 212,  2774, 2263,
      5348, 5347, 229,  4834, 5863, 2784, 230,  4833, 5340, 5339, 221,  4826,
      5855, 2776, 222,  4825, 1344, 4423, 321,  4934, 2371, 2372, 322,  4933,
      328,  2891, 3407, 2892, 841,  842,  5454, 5453, 4442, 347,  4441, 5464,
      2909, 348,  2910, 2399, 336,  2899, 3415, 2900, 849,  850,  5462, 5461,
      5500, 5499, 381,  4986, 6015, 2936, 382,  4985, 3958, 3957, 2417, 2418,
      375,  4468, 3440, 4467, 4450, 355,  4449, 5472, 2917, 356,  2918, 2407,
      3950, 3949, 2409, 2410, 367,  4460, 3432, 4459, 5812, 4791, 5811, 1712,
      693,  694,  5298, 5297, 1208, 4287, 185,  4798, 2235, 2236, 186,  4797,
      5804, 4783, 5803, 1704, 685,  686,  5290, 5289, 4772, 1189, 5287, 1190,
      4771, 5794, 2208, 5793, 3722, 3721, 2189, 2190, 1163, 4744, 1164, 1679,
      5252, 5251, 133,  4738, 5767, 2688, 134,  4737, 3730, 3729, 2197, 2198,
      1171, 4752, 1172, 1687, 4764, 1181, 5279, 1182, 4763, 5786, 2200, 5785,
      5620, 5619, 501,  5106, 6135, 3056, 502,  5105, 5612, 5611, 493,  5098,
      6127, 3048, 494,  5097, 3530, 1997, 971,  972,  3529, 1998, 6088, 3023,
      3538, 2005, 979,  980,  3537, 2006, 6096, 3031, 1016, 1529, 2043, 1530,
      4095, 6142, 2044, 6141, 6116, 5095, 6115, 2016, 997,  998,  5602, 5601,
      5060, 1477, 5575, 1478, 5059, 6082, 2496, 6081, 6108, 5087, 6107, 2008,
      989,  990,  5594, 5593, 5140, 5139, 21,   4626, 5655, 2576, 22,   4625,
      5132, 5131, 13,   4618, 5647, 2568, 14,   4617, 3114, 1581, 555,  556,
      3113, 1582, 5672, 2607, 3122, 1589, 563,  564,  3121, 1590, 5680, 2615,
      24,   2587, 3103, 2588, 537,  538,  5150, 5149, 4102, 519,  4101, 3076,
      2561, 3584, 2562, 3075, 32,   2595, 3111, 2596, 545,  546,  5158, 5157,
      4154, 59,   4153, 5176, 2621, 60,   2622, 2111, 1408, 4487, 385,  4998,
      2435, 2436, 386,  4997, 392,  2955, 3471, 2956, 905,  906,  5518, 5517,
      4506, 411,  4505, 5528, 2973, 412,  2974, 2463, 400,  2963, 3479, 2964,
      913,  914,  5526, 5525, 5564, 5563, 445,  5050, 6079, 3000, 446,  5049,
      4022, 4021, 2481, 2482, 439,  4532, 3504, 4531, 4514, 419,  4513, 5536,
      2981, 420,  2982, 2471, 4014, 4013, 2473, 2474, 431,  4524, 3496, 4523,
      5748, 4727, 5747, 1648, 629,  630,  5234, 5233, 1144, 4223, 121,  4734,
      2171, 2172, 122,  4733, 5740, 4719, 5739, 1640, 621,  622,  5226, 5225,
      4708, 1125, 5223, 1126, 4707, 5730, 2144, 5729, 3658, 3657, 2125, 2126,
      1099, 4680, 1100, 1615, 5188, 5187, 69,   4674, 5703, 2624, 70,   4673,
      3666, 3665, 2133, 2134, 1107, 4688, 1108, 1623, 4700, 1117, 5215, 1118,
      4699, 5722, 2136, 5721, 5428, 5427, 309,  4914, 5943, 2864, 310,  4913,
      5420, 5419, 301,  4906, 5935, 2856, 302,  4905, 3338, 1805, 779,  780,
      3337, 1806, 5896, 2831, 3346, 1813, 787,  788,  3345, 1814, 5904, 2839,
      824,  1337, 1851, 1338, 3903, 5950, 1852, 5949, 5924, 4903, 5923, 1824,
      805,  806,  5410, 5409, 4868, 1285, 5383, 1286, 4867, 5890, 2304, 5889,
      5916, 4895, 5915, 1816, 797,  798,  5402, 5401, 6132, 5111, 6131, 2032,
      1013, 1014, 5618, 5617, 1528, 4607, 505,  5118, 2555, 2556, 506,  5117,
      6124, 5103, 6123, 2024, 1005, 1006, 5610, 5609, 5092, 1509, 5607, 1510,
      5091, 6114, 2528, 6113, 4042, 4041, 2509, 2510, 1483, 5064, 1484, 1999,
      5572, 5571, 453,  5058, 6087, 3008, 454,  5057, 4050, 4049, 2517, 2518,
      1491, 5072, 1492, 2007, 5084, 1501, 5599, 1502, 5083, 6106, 2520, 6105,
      5364, 5363, 245,  4850, 5879, 2800, 246,  4849, 5356, 5355, 237,  4842,
      5871, 2792, 238,  4841, 3274, 1741, 715,  716,  3273, 1742, 5832, 2767,
      3282, 1749, 723,  724,  3281, 1750, 5840, 2775, 760,  1273, 1787, 1274,
      3839, 5886, 1788, 5885, 5860, 4839, 5859, 1760, 741,  742,  5346, 5345,
      4804, 1221, 5319, 1222, 4803, 5826, 2240, 5825, 5852, 4831, 5851, 1752,
      733,  734,  5338, 5337, 5652, 4631, 5651, 1552, 533,  534,  5138, 5137,
      536,  1049, 1563, 1050, 3615, 5662, 1564, 5661, 5644, 4623, 5643, 1544,
      525,  526,  5130, 5129, 3078, 1537, 1031, 4096, 3077, 1538, 3588, 3587,
      3626, 3625, 2093, 2094, 1067, 4648, 1068, 1583, 544,  1057, 1571, 1058,
      3623, 5670, 1572, 5669, 3634, 3633, 2101, 2102, 1075, 4656, 1076, 1591,
      3130, 1597, 571,  572,  3129, 1598, 5688, 2623, 320,  2883, 3399, 2884,
      833,  834,  5446, 5445, 6012, 4991, 6011, 1912, 893,  894,  5498, 5497,
      840,  1353, 1867, 1354, 3919, 5966, 1868, 5965, 4470, 887,  4469, 3444,
      2929, 3952, 2930, 3443, 3418, 1885, 859,  860,  3417, 1886, 5976, 2911,
      3426, 1893, 867,  868,  3425, 1894, 5984, 2919, 848,  1361, 1875, 1362,
      3927, 5974, 1876, 5973, 4462, 879,  4461, 3436, 2921, 3944, 2922, 3435,
      384,  2947, 3463, 2948, 897,  898,  5510, 5509, 6076, 5055, 6075, 1976,
      957,  958,  5562, 5561, 904,  1417, 1931, 1418, 3983, 6030, 1932, 6029,
      4534, 951,  4533, 3508, 2993, 4016, 2994, 3507, 3482, 1949, 923,  924,
      3481, 1950, 6040, 2975, 3490, 1957, 931,  932,  3489, 1958, 6048, 2983,
      912,  1425, 1939, 1426, 3991, 6038, 1940, 6037, 4526, 943,  4525, 3500,
      2985, 4008, 2986, 3499, 4788, 1205, 5303, 1206, 4787, 5810, 2224, 5809,
      4234, 139,  4233, 5256, 2701, 140,  2702, 2191, 184,  2747, 3263, 2748,
      697,  698,  5310, 5309, 5764, 4743, 5763, 1664, 645,  646,  5250, 5249,
      4780, 1197, 5295, 1198, 4779, 5802, 2216, 5801, 4242, 147,  4241, 5264,
      2709, 148,  2710, 2199, 5284, 5283, 165,  4770, 5799, 2720, 166,  4769,
      5276, 5275, 157,  4762, 5791, 2712, 158,  4761, 4724, 1141, 5239, 1142,
      4723, 5746, 2160, 5745, 4170, 75,   4169, 5192, 2637, 76,   2638, 2127,
      120,  2683, 3199, 2684, 633,  634,  5246, 5245, 5700, 4679, 5699, 1600,
      581,  582,  5186, 5185, 4716, 1133, 5231, 1134, 4715, 5738, 2152, 5737,
      4178, 83,   4177, 5200, 2645, 84,   2646, 2135, 5220, 5219, 101,  4706,
      5735, 2656, 102,  4705, 5212, 5211, 93,   4698, 5727, 2648, 94,   4697,
      4006, 4005, 2465, 2466, 423,  4516, 3488, 4515, 4542, 959,  4541, 3516,
      3001, 4024, 3002, 3515, 3998, 3997, 2457, 2458, 415,  4508, 3480, 4507,
      4482, 387,  4481, 5504, 2949, 388,  2950, 2439, 1448, 4527, 425,  5038,
      2475, 2476, 426,  5037, 1456, 4535, 433,  5046, 2483, 2484, 434,  5045,
      3478, 1937, 1431, 4496, 3477, 1938, 3988, 3987, 3470, 1929, 1423, 4488,
      3469, 1930, 3980, 3979, 448,  3011, 3527, 3012, 961,  962,  5574, 5573,
      6140, 5119, 6139, 2040, 1021, 1022, 5626, 5625, 968,  1481, 1995, 1482,
      4047, 6094, 1996, 6093, 4598, 1015, 4597, 3572, 3057, 4080, 3058, 3571,
      3546, 2013, 987,  988,  3545, 2014, 6104, 3039, 3554, 2021, 995,  996,
      3553, 2022, 6112, 3047, 976,  1489, 2003, 1490, 4055, 6102, 2004, 6101,
      4590, 1007, 4589, 3564, 3049, 4072, 3050, 3563, 3942, 3941, 2401, 2402,
      359,  4452, 3424, 4451, 4478, 895,  4477, 3452, 2937, 3960, 2938, 3451,
      3934, 3933, 2393, 2394, 351,  4444, 3416, 4443, 4418, 323,  4417, 5440,
      2885, 324,  2886, 2375, 1384, 4463, 361,  4974, 2411, 2412, 362,  4973,
      1392, 4471, 369,  4982, 2419, 2420, 370,  4981, 3414, 1873, 1367, 4432,
      3413, 1874, 3924, 3923, 3406, 1865, 1359, 4424, 3405, 1866, 3916, 3915,
      4390, 807,  4389, 3364, 2849, 3872, 2850, 3363, 296,  2859, 3375, 2860,
      809,  810,  5422, 5421, 3390, 1849, 1343, 4408, 3389, 1850, 3900, 3899,
      304,  2867, 3383, 2868, 817,  818,  5430, 5429, 4382, 799,  4381, 3356,
      2841, 3864, 2842, 3355, 3862, 3861, 2321, 2322, 279,  4372, 3344, 4371,
      3330, 1797, 771,  772,  3329, 1798, 5888, 2823, 3854, 3853, 2313, 2314,
      271,  4364, 3336, 4363, 5204, 5203, 85,   4690, 5719, 2640, 86,   4689,
      5196, 5195, 77,   4682, 5711, 2632, 78,   4681, 3178, 1645, 619,  620,
      3177, 1646, 5736, 2671, 3186, 1653, 627,  628,  3185, 1654, 5744, 2679,
      88,   2651, 3167, 2652, 601,  602,  5214, 5213, 4166, 583,  4165, 3140,
      2625, 3648, 2626, 3139, 96,   2659, 3175, 2660, 609,  610,  5222, 5221,
      4218, 123,  4217, 5240, 2685, 124,  2686, 2175, 3110, 1569, 1063, 4128,
      3109, 1570, 3620, 3619, 3102, 1561, 1055, 4120, 3101, 1562, 3612, 3611,
      552,  1065, 1579, 1066, 3631, 5678, 1580, 5677, 4118, 535,  4117, 3092,
      2577, 3600, 2578, 3091, 3646, 3645, 2105, 2106, 63,   4156, 3128, 4155,
      3586, 3585, 2053, 2054, 1027, 4608, 1028, 1543, 560,  1073, 1587, 1074,
      3639, 5686, 1588, 5685, 4110, 527,  4109, 3084, 2569, 3592, 2570, 3083,
      5268, 5267, 149,  4754, 5783, 2704, 150,  4753, 5260, 5259, 141,  4746,
      5775, 2696, 142,  4745, 3242, 1709, 683,  684,  3241, 1710, 5800, 2735,
      3250, 1717, 691,  692,  3249, 1718, 5808, 2743, 152,  2715, 3231, 2716,
      665,  666,  5278, 5277, 4230, 647,  4229, 3204, 2689, 3712, 2690, 3203,
      160,  2723, 3239, 2724, 673,  674,  5286, 5285, 4282, 187,  4281, 5304,
      2749, 188,  2750, 2239, 4326, 743,  4325, 3300, 2785, 3808, 2786, 3299,
      232,  2795, 3311, 2796, 745,  746,  5358, 5357, 3326, 1785, 1279, 4344,
      3325, 1786, 3836, 3835, 240,  2803, 3319, 2804, 753,  754,  5366, 5365,
      4318, 735,  4317, 3292, 2777, 3800, 2778, 3291, 3798, 3797, 2257, 2258,
      215,  4308, 3280, 4307, 3266, 1733, 707,  708,  3265, 1734, 5824, 2759,
      3790, 3789, 2249, 2250, 207,  4300, 3272, 4299, 4518, 935,  4517, 3492,
      2977, 4000, 2978, 3491, 424,  2987, 3503, 2988, 937,  938,  5550, 5549,
      3518, 1977, 1471, 4536, 3517, 1978, 4028, 4027, 432,  2995, 3511, 2996,
      945,  946,  5558, 5557, 4510, 927,  4509, 3484, 2969, 3992, 2970, 3483,
      3990, 3989, 2449, 2450, 407,  4500, 3472, 4499, 3458, 1925, 899,  900,
      3457, 1926, 6016, 2951, 3982, 3981, 2441, 2442, 399,  4492, 3464, 4491,
      5716, 4695, 5715, 1616, 597,  598,  5202, 5201, 600,  1113, 1627, 1114,
      3679, 5726, 1628, 5725, 5708, 4687, 5707, 1608, 589,  590,  5194, 5193,
      3142, 1601, 1095, 4160, 3141, 1602, 3652, 3651, 3690, 3689, 2157, 2158,
      1131, 4712, 1132, 1647, 608,  1121, 1635, 1122, 3687, 5734, 1636, 5733,
      3698, 3697, 2165, 2166, 1139, 4720, 1140, 1655, 3194, 1661, 635,  636,
      3193, 1662, 5752, 2687, 960,  1473, 1987, 1474, 4039, 6086, 1988, 6085,
      4058, 4057, 2525, 2526, 1499, 5080, 1500, 2015, 5116, 1533, 5631, 1534,
      5115, 6138, 2552, 6137, 4066, 4065, 2533, 2534, 1507, 5088, 1508, 2023,
      1480, 4559, 457,  5070, 2507, 2508, 458,  5069, 1488, 4567, 465,  5078,
      2515, 2516, 466,  5077, 3574, 2033, 1527, 4592, 3573, 2034, 4084, 4083,
      3566, 2025, 1519, 4584, 3565, 2026, 4076, 4075, 3622, 3621, 2081, 2082,
      39,   4132, 3104, 4131, 4158, 575,  4157, 3132, 2617, 3640, 2618, 3131,
      3614, 3613, 2073, 2074, 31,   4124, 3096, 4123, 4098, 3,    4097, 5120,
      2565, 4,    2566, 2055, 1064, 4143, 41,   4654, 2091, 2092, 42,   4653,
      1072, 4151, 49,   4662, 2099, 2100, 50,   4661, 3094, 1553, 1047, 4112,
      3093, 1554, 3604, 3603, 3086, 1545, 1039, 4104, 3085, 1546, 3596, 3595,
      4454, 871,  4453, 3428, 2913, 3936, 2914, 3427, 360,  2923, 3439, 2924,
      873,  874,  5486, 5485, 3454, 1913, 1407, 4472, 3453, 1914, 3964, 3963,
      368,  2931, 3447, 2932, 881,  882,  5494, 5493, 4446, 863,  4445, 3420,
      2905, 3928, 2906, 3419, 3926, 3925, 2385, 2386, 343,  4436, 3408, 4435,
      3394, 1861, 835,  836,  3393, 1862, 5952, 2887, 3918, 3917, 2377, 2378,
      335,  4428, 3400, 4427, 5780, 4759, 5779, 1680, 661,  662,  5266, 5265,
      664,  1177, 1691, 1178, 3743, 5790, 1692, 5789, 5772, 4751, 5771, 1672,
      653,  654,  5258, 5257, 3206, 1665, 1159, 4224, 3205, 1666, 3716, 3715,
      3754, 3753, 2221, 2222, 1195, 4776, 1196, 1711, 672,  1185, 1699, 1186,
      3751, 5798, 1700, 5797, 3762, 3761, 2229, 2230, 1203, 4784, 1204, 1719,
      3258, 1725, 699,  700,  3257, 1726, 5816, 2751, 3366, 1825, 1319, 4384,
      3365, 1826, 3876, 3875, 3358, 1817, 1311, 4376, 3357, 1818, 3868, 3867,
      808,  1321, 1835, 1322, 3887, 5934, 1836, 5933, 4374, 791,  4373, 3348,
      2833, 3856, 2834, 3347, 3902, 3901, 2361, 2362, 319,  4412, 3384, 4411,
      3842, 3841, 2309, 2310, 1283, 4864, 1284, 1799, 816,  1329, 1843, 1330,
      3895, 5942, 1844, 5941, 4366, 783,  4365, 3340, 2825, 3848, 2826, 3339,
      3302, 1761, 1255, 4320, 3301, 1762, 3812, 3811, 3294, 1753, 1247, 4312,
      3293, 1754, 3804, 3803, 744,  1257, 1771, 1258, 3823, 5870, 1772, 5869,
      4310, 727,  4309, 3284, 2769, 3792, 2770, 3283, 3838, 3837, 2297, 2298,
      255,  4348, 3320, 4347, 3778, 3777, 2245, 2246, 1219, 4800, 1220, 1735,
      752,  1265, 1779, 1266, 3831, 5878, 1780, 5877, 4302, 719,  4301, 3276,
      2761, 3784, 2762, 3275, 3494, 1953, 1447, 4512, 3493, 1954, 4004, 4003,
      3486, 1945, 1439, 4504, 3485, 1946, 3996, 3995, 936,  1449, 1963, 1450,
      4015, 6062, 1964, 6061, 4502, 919,  4501, 3476, 2961, 3984, 2962, 3475,
      4030, 4029, 2489, 2490, 447,  4540, 3512, 4539, 3970, 3969, 2437, 2438,
      1411, 4992, 1412, 1927, 944,  1457, 1971, 1458, 4023, 6070, 1972, 6069,
      4494, 911,  4493, 3468, 2953, 3976, 2954, 3467, 3430, 1889, 1383, 4448,
      3429, 1890, 3940, 3939, 3422, 1881, 1375, 4440, 3421, 1882, 3932, 3931,
      872,  1385, 1899, 1386, 3951, 5998, 1900, 5997, 4438, 855,  4437, 3412,
      2897, 3920, 2898, 3411, 3966, 3965, 2425, 2426, 383,  4476, 3448, 4475,
      3906, 3905, 2373, 2374, 1347, 4928, 1348, 1863, 880,  1393, 1907, 1394,
      3959, 6006, 1908, 6005, 4430, 847,  4429, 3404, 2889, 3912, 2890, 3403,
      4692, 1109, 5207, 1110, 4691, 5714, 2128, 5713, 4202, 107,  4201, 5224,
      2669, 108,  2670, 2159, 1112, 4191, 89,   4702, 2139, 2140, 90,   4701,
      1120, 4199, 97,   4710, 2147, 2148, 98,   4709, 4684, 1101, 5199, 1102,
      4683, 5706, 2120, 5705, 4210, 115,  4209, 5232, 2677, 116,  2678, 2167,
      3654, 3653, 2113, 2114, 71,   4164, 3136, 4163, 3706, 3705, 2173, 2174,
      1147, 4728, 1148, 1663, 4756, 1173, 5271, 1174, 4755, 5778, 2192, 5777,
      4266, 171,  4265, 5288, 2733, 172,  2734, 2223, 1176, 4255, 153,  4766,
      2203, 2204, 154,  4765, 1184, 4263, 161,  4774, 2211, 2212, 162,  4773,
      4748, 1165, 5263, 1166, 4747, 5770, 2184, 5769, 4274, 179,  4273, 5296,
      2741, 180,  2742, 2231, 3718, 3717, 2177, 2178, 135,  4228, 3200, 4227,
      3770, 3769, 2237, 2238, 1211, 4792, 1212, 1727, 1472, 4551, 449,  5062,
      2499, 2500, 450,  5061, 456,  3019, 3535, 3020, 969,  970,  5582, 5581,
      4570, 475,  4569, 5592, 3037, 476,  3038, 2527, 464,  3027, 3543, 3028,
      977,  978,  5590, 5589, 5628, 5627, 509,  5114, 6143, 3064, 510,  5113,
      4086, 4085, 2545, 2546, 503,  4596, 3568, 4595, 4578, 483,  4577, 5600,
      3045, 484,  3046, 2535, 4078, 4077, 2537, 2538, 495,  4588, 3560, 4587,
      3878, 3877, 2337, 2338, 295,  4388, 3360, 4387, 4414, 831,  4413, 3388,
      2873, 3896, 2874, 3387, 3870, 3869, 2329, 2330, 287,  4380, 3352, 4379,
      4354, 259,  4353, 5376, 2821, 260,  2822, 2311, 1320, 4399, 297,  4910,
      2347, 2348, 298,  4909, 1328, 4407, 305,  4918, 2355, 2356, 306,  4917,
      3350, 1809, 1303, 4368, 3349, 1810, 3860, 3859, 3342, 1801, 1295, 4360,
      3341, 1802, 3852, 3851, 4134, 551,  4133, 3108, 2593, 3616, 2594, 3107,
      40,   2603, 3119, 2604, 553,  554,  5166, 5165, 3134, 1593, 1087, 4152,
      3133, 1594, 3644, 3643, 48,   2611, 3127, 2612, 561,  562,  5174, 5173,
      4126, 543,  4125, 3100, 2585, 3608, 2586, 3099, 3606, 3605, 2065, 2066,
      23,   4116, 3088, 4115, 3074, 1541, 515,  516,  3073, 1542, 5632, 2567,
      3598, 3597, 2057, 2058, 15,   4108, 3080, 4107, 3814, 3813, 2273, 2274,
      231,  4324, 3296, 4323, 4350, 767,  4349, 3324, 2809, 3832, 2810, 3323,
      3806, 3805, 2265, 2266, 223,  4316, 3288, 4315, 4290, 195,  4289, 5312,
      2757, 196,  2758, 2247, 1256, 4335, 233,  4846, 2283, 2284, 234,  4845,
      1264, 4343, 241,  4854, 2291, 2292, 242,  4853, 3286, 1745, 1239, 4304,
      3285, 1746, 3796, 3795, 3278, 1737, 1231, 4296, 3277, 1738, 3788, 3787,
    };

    // spread the low 21 bits of x to every third bit
    inline std::uint64_t spread3(std::uint64_t x)
    {
      x &= 0x1fffffull;
      x = (x | x << 32) & 0x1f00000000ffffull;
      x = (x | x << 16) & 0x1f0000ff0000ffull;
      x = (x | x << 8) & 0x100f00f00f00f00full;
      x = (x | x << 4) & 0x10c30c30c30c30c3ull;
      x = (x | x << 2) & 0x1249249249249249ull;
      return x;
    }

    // the Moore curve at the first iteration: 8 blocks of 64 entries of
    // hilbert3, one per octant, which close the curve
    const std::uint16_t mooreBlock[8] = {2880, 64,  128, 192,
                                         4160, 320, 384, 448};

    inline std::uint64_t mooreKey(std::uint64_t zorder)
    {
      std::uint64_t transform =
        hilbert3[mooreBlock[zorder >> 60] + ((zorder >> 54) & 63)];
      std::uint64_t out = transform & 0x1ff;
      for(int iter = 45; iter >= 0; iter -= 9) {
        transform =
          hilbert3[(transform & ~0x1ffull) | ((zorder >> iter) & 0x1ff)];
        out = (out << 9) | (transform & 0x1ff);
      }
      return out;
    }

  } // namespace

  void mooreCurve(Mesh &m, const double min[3], const double max[3],
                  const double *shift, std::size_t first)
  {
    static const double defaultShift[3] = {0.5, 0.5, 0.5};
    if(!shift) shift = defaultShift;
    const std::size_t n = m.numVertices();
    if(m.dist.size() < n) m.dist.resize(n);
    if(first >= n) return;
    const double nmax = 2097152.; // 1 << 21, quantization levels per axis
    double widthMax = 0.;
    for(int i = 0; i < 3; i++) widthMax = std::max(widthMax, max[i] - min[i]);
    if(widthMax <= 0.) widthMax = 1.;
    // the quantization is piecewise linear on each axis, with the breakpoint
    // (the center of the curve) at shift[i], and continuous there
    double lo[3], middle[3], f0[3], f1[3], sub1[3];
    for(int i = 0; i < 3; i++) {
      double xmin, xmax;
      if(widthMax > 1.5 * (max[i] - min[i])) { // keep the box roughly cubic
        if(shift[i] >= 0.5) {
          xmin = min[i];
          xmax = min[i] + widthMax;
        }
        else {
          xmax = max[i];
          xmin = max[i] - widthMax;
        }
      }
      else {
        xmin = min[i];
        xmax = max[i];
      }
      lo[i] = xmin;
      middle[i] = shift[i] * (xmax - xmin) + xmin;
      f0[i] = (nmax / 2) / (middle[i] - xmin);
      f1[i] = (nmax / 2) / (xmax - middle[i]);
      sub1[i] = 2 * middle[i] - xmax;
      while((xmax - sub1[i]) * f1[i] >= nmax) f1[i] = std::nextafter(f1[i], 0.);
    }
    const int nthreads = CTX::instance()->numThreadsFor(n - first, 1 << 16);
#pragma omp parallel for schedule(static) num_threads(nthreads)
    for(std::size_t i = first; i < n; i++) {
      const double *p = &m.xyz[4 * i];
      std::uint64_t q[3];
      for(int k = 0; k < 3; k++) {
        double v = (p[k] < middle[k]) ? (p[k] - lo[k]) * f0[k] :
                                        (p[k] - sub1[k]) * f1[k];
        if(v < 0.) v = 0.;
        if(v >= nmax) v = nmax - 1;
        q[k] = (std::uint64_t)v;
      }
      m.dist[i] =
        mooreKey(spread3(q[0]) | spread3(q[1]) << 1 | spread3(q[2]) << 2);
    }
  }

} // namespace pdel3d

// Constraints of the pdel3d mesh: locating the surface triangles and the
// curve lines among the facets and edges of the tets, flagging them, and
// coloring the tets by volume

namespace pdel3d {

  namespace {

    inline void sort3(vIdx &a, vIdx &b, vIdx &c)
    {
      if(a > b) std::swap(a, b);
      if(b > c) std::swap(b, c);
      if(a > b) std::swap(a, b);
    }

    inline std::uint64_t hash3(vIdx a, vIdx b, vIdx c)
    {
      std::uint64_t h = a * 0x9e3779b97f4a7c15ull;
      h ^= (h >> 29) + b * 0xbf58476d1ce4e5b9ull;
      h ^= (h >> 31) + c * 0x94d049bb133111ebull;
      return h ^ (h >> 33);
    }

    // open addressing table of the (sorted) triangles
    struct TriangleTable {
      std::size_t mask;
      std::vector<std::uint32_t> slot; // triangle index + 1, 0 when empty
      const std::vector<vIdx> &tri; // sorted nodes

      TriangleTable(const std::vector<vIdx> &sortedTri) : tri(sortedTri)
      {
        const std::size_t n = tri.size() / 3;
        std::size_t size = 16;
        while(size < 2 * n) size <<= 1;
        mask = size - 1;
        slot.assign(size, 0);
        for(std::size_t i = 0; i < n; i++) {
          std::size_t h =
            hash3(tri[3 * i], tri[3 * i + 1], tri[3 * i + 2]) & mask;
          while(slot[h]) h = (h + 1) & mask;
          slot[h] = (std::uint32_t)(i + 1);
        }
      }
      // index of the triangle (a, b, c) sorted, or -1
      std::int64_t find(vIdx a, vIdx b, vIdx c) const
      {
        std::size_t h = hash3(a, b, c) & mask;
        while(slot[h]) {
          const std::size_t i = slot[h] - 1;
          if(tri[3 * i] == a && tri[3 * i + 1] == b && tri[3 * i + 2] == c)
            return (std::int64_t)i;
          h = (h + 1) & mask;
        }
        return -1;
      }
    };

  } // namespace

  std::size_t triangleToTetMap(const Mesh &m, const std::vector<vIdx> &triNode,
                               std::vector<tRef> &tri2tet)
  {
    const std::size_t ntri = triNode.size() / 3;
    tri2tet.assign(ntri, NO_ADJ);
    if(!ntri) return 0;
    std::vector<vIdx> sorted(triNode);
    for(std::size_t i = 0; i < ntri; i++)
      sort3(sorted[3 * i], sorted[3 * i + 1], sorted[3 * i + 2]);
    TriangleTable table(sorted);
    // every interior facet is seen from its two tets: only the one with the
    // smaller index writes, so that the entries are written once
    const int nthreads = CTX::instance()->numThreadsFor(m.ntet, 1 << 16);
#pragma omp parallel for schedule(static) num_threads(nthreads)
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t) || m.isGhost((tIdx)t)) continue;
      const vIdx *n = &m.node[4 * t];
      for(unsigned f = 0; f < 4; f++) {
        const tRef r = m.neigh[4 * t + f];
        if(r != NO_ADJ && (r >> 2) < t && !m.isGhost(r >> 2)) continue;
        vIdx a = n[facetNode0(f)], b = n[facetNode1(f)], c = n[facetNode2(f)];
        sort3(a, b, c);
        const std::int64_t i = table.find(a, b, c);
        if(i >= 0) tri2tet[i] = (tRef)(4 * t + f);
      }
    }
    std::size_t missing = 0;
    for(auto r : tri2tet)
      if(r == NO_ADJ) missing++;
    return missing;
  }

  void linesInTriangles(const std::vector<vIdx> &triNode,
                        const std::vector<vIdx> &lineNode,
                        std::vector<std::uint8_t> &inTriangle)
  {
    const std::size_t nl = lineNode.size() / 2;
    inTriangle.assign(nl, 0);
    if(!nl || triNode.empty()) return;
    std::vector<std::uint64_t> edges;
    edges.reserve(triNode.size());
    for(std::size_t i = 0; i < triNode.size() / 3; i++) {
      for(int j = 0; j < 3; j++) {
        vIdx a = triNode[3 * i + j], b = triNode[3 * i + (j + 1) % 3];
        if(a > b) std::swap(a, b);
        edges.push_back(((std::uint64_t)a << 32) | b);
      }
    }
    std::sort(edges.begin(), edges.end());
    for(std::size_t i = 0; i < nl; i++) {
      vIdx a = lineNode[2 * i], b = lineNode[2 * i + 1];
      if(a > b) std::swap(a, b);
      inTriangle[i] = std::binary_search(edges.begin(), edges.end(),
                                         ((std::uint64_t)a << 32) | b) ?
                        1 :
                        0;
    }
  }

  std::size_t lineToTetMap(const Mesh &m, const std::vector<vIdx> &lineNode,
                           const std::vector<std::uint8_t> &skip,
                           std::vector<std::uint64_t> &line2tet)
  {
    const std::size_t nl = lineNode.size() / 2;
    line2tet.assign(nl, NO_LINE);
    std::size_t todo = 0;
    for(std::size_t i = 0; i < nl; i++)
      if(!skip[i]) todo++;
    if(!todo) return 0;
    // one tet per vertex, then a search of the star of the first node
    std::vector<tIdx> tetOf(m.numVertices(), NO_TET);
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t) || m.isGhost((tIdx)t)) continue;
      for(int k = 0; k < 4; k++) tetOf[m.node[4 * t + k]] = (tIdx)t;
    }
    std::size_t missing = 0;
    std::vector<tIdx> star;
    std::vector<std::uint32_t> mark(m.ntet, 0);
    std::uint32_t stamp = 0;
    for(std::size_t i = 0; i < nl; i++) {
      if(skip[i]) continue;
      const vIdx a = lineNode[2 * i], b = lineNode[2 * i + 1];
      if(a == b) continue; // degenerate line
      if(tetOf[a] == NO_TET) {
        missing++;
        continue;
      }
      star.clear();
      star.push_back(tetOf[a]);
      mark[tetOf[a]] = ++stamp;
      bool found = false;
      for(std::size_t s = 0; s < star.size() && !found; s++) {
        const tIdx t = star[s];
        const vIdx *n = &m.node[4 * t];
        int ia = -1, ib = -1;
        for(int k = 0; k < 4; k++) {
          if(n[k] == a) ia = k;
          if(n[k] == b) ib = k;
        }
        if(ib >= 0) {
          line2tet[i] = 6 * (std::uint64_t)t + (5 - edgeFromFacets(ia, ib));
          found = true;
          break;
        }
        // the neighbors through the facets containing a
        for(unsigned f = 0; f < 4; f++) {
          if((int)f == ia) continue;
          const tIdx nb = m.neigh[4 * t + f] >> 2;
          if(m.isGhost(nb) || mark[nb] == stamp) continue;
          mark[nb] = stamp;
          star.push_back(nb);
        }
      }
      if(!found) missing++;
    }
    return missing;
  }

  void constrainFacets(Mesh &m, const std::vector<tRef> &tri2tet)
  {
    for(auto r : tri2tet) {
      if(r == NO_ADJ) continue;
      m.flag[r >> 2] |= F_FACET0 << (r & 3);
      const tRef s = m.neigh[r];
      if(s != NO_ADJ) m.flag[s >> 2] |= F_FACET0 << (s & 3);
    }
  }

  void constrainEdges(Mesh &m, const std::vector<std::uint64_t> &line2tet)
  {
    for(auto e : line2tet) {
      if(e == NO_LINE) continue;
      const tIdx t0 = (tIdx)(e / 6);
      unsigned inF, outF;
      edgeFacets((int)(e % 6), inF, outF);
      tIdx cur = t0;
      // turn around the edge
      do {
        m.flag[cur] |= 1 << edgeFromFacets(inF, outF);
        const vIdx newV = m.node[4 * cur + inF];
        const tRef r = m.neigh[4 * cur + outF];
        cur = r >> 2;
        inF = r & 3;
        const vIdx *nodes = &m.node[4 * cur];
        for(outF = 0; outF < 3; outF++)
          if(nodes[outF] == newV) break;
      } while(cur != t0);
    }
  }

  // local boundary recovery

  namespace {

    // the ring of tets around an edge, as in the optimizer
    struct Ring {
      vIdx a, b; // the edge
      int n = 0;
      tIdx tet[32];
      vIdx vert[32]; // vert[i] is shared by tets i and i + 1
      tRef outA[32], outB[32]; // outer facets containing a (resp. b)
    };

    struct Recovery {
      Mesh &m;
      std::vector<tRef> v2t; // a tet containing each vertex (NO_ADJ: none)
      std::vector<std::uint64_t> surfaceEdges; // sorted; never removed
      bool isSurfaceEdge(vIdx a, vIdx b) const
      {
        return std::binary_search(surfaceEdges.begin(), surfaceEdges.end(),
                                  edgeKey(a, b));
      }
      std::vector<tIdx> scratch;
      std::size_t swaps = 0;
      // rejection counters, reported at the debug verbosity
      std::size_t rGhost = 0, rBig = 0, rSurfEdge = 0, rBad = 0,
                  rNoVertices = 0, rNoTriangulation = 0, rVolume = 0;

      Recovery(Mesh &mesh) : m(mesh) {}

      static std::uint64_t edgeKey(vIdx x, vIdx y)
      {
        if(x > y) std::swap(x, y);
        return ((std::uint64_t)x << 32) | y;
      }

      // a tet around every needed vertex: the last in the tet array, so that
      // the stars, hence the recovery, do not depend on the threads
      void findStars(const std::vector<std::uint8_t> &needed, int nthreads)
      {
        v2t.assign(needed.size(), NO_ADJ);
        const int nc = std::max(1, nthreads);
        std::vector<std::vector<std::pair<vIdx, tRef>>> found(nc);
#pragma omp parallel for schedule(static, 1) num_threads(nc)
        for(int c = 0; c < nc; c++) {
          for(std::size_t t = m.ntet * c / nc; t < m.ntet * (c + 1) / nc; t++) {
            if(m.isDeleted((tIdx)t) || m.isGhost((tIdx)t)) continue;
            for(unsigned k = 0; k < 4; k++) {
              const vIdx v = m.node[4 * t + k];
              if(needed[v]) found[c].push_back({v, (tRef)(4 * t + k)});
            }
          }
        }
        for(auto &f : found)
          for(auto &p : f) v2t[p.first] = p.second;
      }

      // the tets around vertex v (none above cap). The removals give up on
      // stars above MAX_STAR: the surface Delaunay of a CAD part has vertices
      // joined to thousands of tets, which are not worth the effort
      static constexpr std::size_t MAX_STAR = 4096;
      std::vector<std::uint32_t> mark;
      std::uint32_t stamp = 0;
      void star(vIdx v, std::vector<tIdx> &out,
                std::size_t cap = (std::size_t)-1)
      {
        out.clear();
        if(v2t[v] == NO_ADJ) return;
        tIdx t0 = v2t[v] >> 2;
        if(m.isDeleted(t0)) return;
        if(mark.size() < m.tetCapacity()) mark.resize(m.tetCapacity(), 0);
        stamp++;
        out.push_back(t0);
        mark[t0] = stamp;
        for(std::size_t i = 0; i < out.size(); i++) {
          const tIdx t = out[i];
          const vIdx *n = &m.node[4 * t];
          for(unsigned f = 0; f < 4; f++) {
            if(n[f] == v) continue; // facet opposite v does not contain it
            const tIdx nb = m.neigh[4 * t + f] >> 2;
            if(mark[nb] == stamp) continue;
            mark[nb] = stamp;
            out.push_back(nb);
            if(out.size() > cap) {
              out.clear();
              return;
            }
          }
        }
      }

      // a tet containing x and y, or NO_TET
      tIdx findEdge(vIdx x, vIdx y)
      {
        star(x, scratch);
        for(auto t : scratch) {
          const vIdx *n = &m.node[4 * t];
          if(n[0] == y || n[1] == y || n[2] == y || n[3] == y) return t;
        }
        return NO_TET;
      }

      // the facet (x, y, z), or NO_ADJ
      tRef findFacet(vIdx x, vIdx y, vIdx z)
      {
        star(x, scratch);
        for(auto t : scratch) {
          const vIdx *n = &m.node[4 * t];
          int iy = -1, iz = -1, ix = -1;
          for(int k = 0; k < 4; k++) {
            if(n[k] == x) ix = k;
            if(n[k] == y) iy = k;
            if(n[k] == z) iz = k;
          }
          if(ix >= 0 && iy >= 0 && iz >= 0) return 4 * t + (6 - ix - iy - iz);
        }
        return NO_ADJ;
      }

      // the ring around the edge of tet t between its nodes at positions ia
      // and ib; false when it cannot be removed (a surface edge, more than 31
      // tets, inconsistent). The removals cannot destroy the triangles and
      // lines in the mesh: their edges are all surface edges
      bool buildRing(tIdx t, unsigned ia, unsigned ib, Ring &R)
      {
        R.a = m.node[4 * t + ia];
        R.b = m.node[4 * t + ib];
        if(isSurfaceEdge(R.a, R.b)) {
          rSurfEdge++;
          return false;
        }
        const int e = edgeOfNodes[ia][ib];
        unsigned inF, outF;
        edgeFacets(e, inF, outF);
        R.n = 0;
        tIdx cur = t;
        int ghosts = 0;
        do {
          if(R.n == 31) {
            rBig++;
            return false;
          }
          if(m.isDeleted(cur)) {
            rBad++;
            return false;
          }
          if(m.isGhost(cur) && ++ghosts > 2) {
            rGhost++;
            return false;
          }
          const vIdx *n = &m.node[4 * cur];
          const vIdx r = n[inF];
          unsigned fa = 0, fb = 0;
          for(unsigned k = 0; k < 4; k++) {
            if(n[k] == R.a) fa = k;
            if(n[k] == R.b) fb = k;
          }
          R.tet[R.n] = cur;
          R.vert[R.n] = r;
          R.outA[R.n] = m.neigh[4 * cur + fb];
          R.outB[R.n] = m.neigh[4 * cur + fa];
          R.n++;
          const tRef rf = m.neigh[4 * cur + outF];
          cur = rf >> 2;
          inF = rf & 3;
          const vIdx *nn = &m.node[4 * cur];
          for(outF = 0; outF < 3; outF++)
            if(nn[outF] == r) break;
        } while(cur != t);
        if(R.n < 3) {
          rBad++;
          return false;
        }
        for(int i = 0; i < R.n; i++) {
          if(R.vert[i] == R.a || R.vert[i] == R.b) {
            rBad++;
            return false;
          }
          for(int j = 0; j < i; j++)
            if(R.vert[i] == R.vert[j]) {
              rBad++;
              return false;
            }
          // a hull edge: the ring holds the two ghost tets and the ghost
          // vertex once; a ring tet touching the hull elsewhere means the
          // edge is not a hull edge but the ring is next to it: fine too
        }
        return true;
      }

      int ringPosition(const Ring &R, vIdx v) const
      {
        for(int i = 0; i < R.n; i++)
          if(R.vert[i] == v) return i;
        return -1;
      }

      // Remove the edge of the ring, retriangulating the ring polygon so that
      // it contains the required positions (3 of them: a triangle, 2: a
      // diagonal); facet receives the required triangle. The triangulation
      // maximizing the worst quality of the new tets is found by dynamic
      // programming over the sub-polygons (Klincsek), for any ring size; a
      // ring through the hull holds the ghost vertex once, whose ear (its two
      // neighbors) is forced: the two hull facets of the ring are replaced by
      // the two on the diagonal joining them. Returns false when no valid
      // triangulation exists (positive tets whose volumes add up to the ring)
      bool edgeRemoval(const Ring &R, const int *req, int nreq, tRef *facet)
      {
        const int n = R.n;
        int ghostPos = -1;
        for(int i = 0; i < n; i++)
          if(R.vert[i] == GHOST) ghostPos = i;
        // the real vertices of the polygon, in order, after the ghost
        const int k = ghostPos >= 0 ? n - 1 : n;
        if(k < 3) return false;
        int pos[32];
        for(int i = 0; i < k; i++) pos[i] = (ghostPos + 1 + i) % n;
        int rq[3];
        for(int j = 0; j < nreq; j++) {
          rq[j] = -1;
          for(int i = 0; i < k; i++)
            if(pos[i] == req[j]) rq[j] = i;
          if(rq[j] < 0) return false; // the ghost cannot be required
        }
        // sorted (at most 3 entries: GCC cannot tell, and std::sort trips
        // -Warray-bounds)
        for(int i = 1; i < nreq; i++)
          for(int j = i; j > 0 && rq[j - 1] > rq[j]; j--)
            std::swap(rq[j - 1], rq[j]);
        // a required diagonal that is the closing edge of the polygon is
        // already there
        if(nreq == 2 && rq[0] == 0 && rq[1] == k - 1) nreq = 0;
        const double *pa = &m.xyz[4 * R.a], *pb = &m.xyz[4 * R.b];
        // tet pos[1] holds a, b, r_{pos[0]} and r_{pos[1]}: a real tet
        const int s = ringOrientation(m, R.tet[pos[1]], R.a, R.b,
                                      R.vert[pos[0]], R.vert[pos[1]]);
        double ringVol = 0.;
        for(int i = 0; i < n; i++) {
          if(m.isGhost(R.tet[i])) continue;
          const vIdx *v = &m.node[4 * R.tet[i]];
          ringVol -= orient3dFast(&m.xyz[4 * v[0]], &m.xyz[4 * v[1]],
                                  &m.xyz[4 * v[2]], &m.xyz[4 * v[3]]);
        }
        // the two tets on each triangle (i, j, l) of the polygon, i < j < l:
        // worst quality (-1: invalid), volume, and whether the a-side tet is
        // (j, i, l, a) rather than (i, j, l, a)
        auto idx = [k](int i, int j, int l) { return (i * k + j) * k + l; };
        std::vector<double> tq(k * k * k, -1.), tv(k * k * k, 0.);
        std::vector<std::uint8_t> tflip(k * k * k, 0);
        for(int i = 0; i < k; i++) {
          for(int j = i + 1; j < k; j++) {
            for(int l = j + 1; l < k; l++) {
              const double *p0 = &m.xyz[4 * R.vert[pos[i]]],
                           *p1 = &m.xyz[4 * R.vert[pos[j]]],
                           *p2 = &m.xyz[4 * R.vert[pos[l]]];
              const double da = orient3dFast(p0, p1, p2, pa);
              const double db = orient3dFast(p0, p1, p2, pb);
              // a and b on opposite sides, the a-side tet with the ring's
              // orientation
              if(da * db >= 0. || da * s >= 0.) continue;
              const int t = idx(i, j, l);
              tv[t] = std::fabs(da) + std::fabs(db);
              tflip[t] = da > 0.;
              if(tflip[t])
                tq[t] = std::min(gammaQuality(p1, p0, p2, pa, -da),
                                 gammaQuality(p0, p1, p2, pb, db));
              else
                tq[t] = std::min(gammaQuality(p0, p1, p2, pa, da),
                                 gammaQuality(p1, p0, p2, pb, -db));
            }
          }
        }
        auto triQ = [&](int i, int j, int l) { // any order of the indices
          int a[3] = {i % k, j % k, l % k};
          std::sort(a, a + 3);
          return tq[idx(a[0], a[1], a[2])];
        };
        // Q[i][j]: best worst quality of a triangulation of the chain of
        // vertices i..j (indices modulo k, j < i + k) closed by the diagonal
        // (i, j); K[i][j] the apex of the triangle on that diagonal
        const int kk = 2 * k;
        std::vector<double> Q(kk * kk, -1.);
        std::vector<int> K(kk * kk, -1);
        for(int i = 0; i + 1 < kk; i++) Q[i * kk + i + 1] = 2.;
        for(int len = 2; len < k; len++) {
          for(int i = 0; i + len < kk; i++) {
            const int j = i + len;
            double best = -1.;
            int bk = -1;
            for(int c = i + 1; c < j; c++) {
              const double q =
                std::min(triQ(i, c, j), std::min(Q[i * kk + c], Q[c * kk + j]));
              if(q > best) {
                best = q;
                bk = c;
              }
            }
            Q[i * kk + j] = best;
            K[i * kk + j] = bk;
          }
        }
        // the triangulation: the required piece, then the best completion
        std::vector<std::array<int, 3>> tris;
        std::vector<std::array<int, 2>> chains;
        double worst = 2.;
        if(nreq == 3) {
          worst = triQ(rq[0], rq[1], rq[2]);
          tris.push_back({rq[0], rq[1], rq[2]});
          chains = {{rq[0], rq[1]}, {rq[1], rq[2]}, {rq[2], rq[0] + k}};
        }
        else if(nreq == 2) {
          chains = {{rq[0], rq[1]}, {rq[1], rq[0] + k}};
        }
        else
          chains = {{0, k - 1}};
        for(auto &ch : chains) {
          if(ch[1] - ch[0] < 2) continue;
          worst = std::min(worst, Q[ch[0] * kk + ch[1]]);
        }
        if(worst <= 0.) {
          rNoTriangulation++;
          return false;
        }
        std::vector<std::array<int, 2>> stack(chains);
        while(!stack.empty()) {
          const auto ch = stack.back();
          stack.pop_back();
          if(ch[1] - ch[0] < 2) continue;
          const int c = K[ch[0] * kk + ch[1]];
          tris.push_back({ch[0] % k, c % k, ch[1] % k});
          stack.push_back({ch[0], c});
          stack.push_back({c, ch[1]});
        }
        double vol = 0.;
        for(auto &t : tris) {
          int a[3] = {t[0], t[1], t[2]};
          std::sort(a, a + 3);
          vol += tv[idx(a[0], a[1], a[2])];
        }
        // on a hull edge, the sliver between the two hull triangulations of
        // the quad (a, r_0, b, r_{k-1}) leaves the mesh: the new hull is
        // reflex there (the surface is what it is, the convex hull is not)
        double expected = ringVol;
        if(ghostPos >= 0)
          expected -= std::fabs(orient3dFast(pa, pb, &m.xyz[4 * R.vert[pos[0]]],
                                             &m.xyz[4 * R.vert[pos[k - 1]]]));
        if(std::fabs(vol - expected) > 1.e-6 * ringVol) {
          rVolume++;
          return false;
        }

        const int nc = 2 * (int)tris.size() + (ghostPos >= 0 ? 2 : 0);
        m.reserveTets(m.ntet + nc + 1024);
        for(int i = 0; i < n; i++) m.flag[R.tet[i]] |= F_DELETED;
        struct facetKey {
          vIdx v0, v1, v2;
          tRef ref;
        };
        std::vector<facetKey> facets;
        facets.reserve(4 * nc);
        auto addFacet = [&](vIdx x, vIdx y, vIdx z, tRef ref) {
          if(x > y) std::swap(x, y);
          if(y > z) std::swap(y, z);
          if(x > y) std::swap(x, y);
          facets.push_back({x, y, z, ref});
        };
        auto newTet = [&](vIdx n0, vIdx n1, vIdx n2, vIdx n3) {
          const tIdx s = (tIdx)m.ntet++;
          vIdx *v = &m.node[4 * s];
          v[0] = n0;
          v[1] = n1;
          v[2] = n2;
          v[3] = n3;
          m.flag[s] = 0;
          for(unsigned f = 0; f < 4; f++) {
            m.neigh[4 * s + f] = NO_ADJ;
            addFacet(v[facetNode0(f)], v[facetNode1(f)], v[facetNode2(f)],
                     4 * s + f);
          }
          for(int q = 0; q < 4; q++)
            if(v[q] != GHOST) v2t[v[q]] = 4 * s + q;
          return s;
        };
        if(facet) *facet = NO_ADJ;
        for(std::size_t it = 0; it < tris.size(); it++) {
          int a[3] = {tris[it][0], tris[it][1], tris[it][2]};
          std::sort(a, a + 3);
          vIdx r0 = R.vert[pos[a[0]]], r1 = R.vert[pos[a[1]]],
               r2 = R.vert[pos[a[2]]];
          if(tflip[idx(a[0], a[1], a[2])]) std::swap(r0, r1);
          const tIdx sa = newTet(r0, r1, r2, R.a), sb = newTet(r1, r0, r2, R.b);
          // the required triangle, facet 3 of both
          if(it == 0 && nreq == 3 && facet) *facet = 4 * sa + 3;
          if(ghostPos >= 0 && a[0] == 0 && a[2] == k - 1) {
            // the hull facets (r_0, r_{k-1}, a) and (r_0, r_{k-1}, b) close the
            // ring on the outside: ghost tets oriented from the real tets
            for(int side = 0; side < 2; side++) {
              const tIdx t = side ? sb : sa;
              const vIdx *v = &m.node[4 * t];
              const vIdx x = R.vert[pos[a[1]]];
              unsigned ix = 0;
              while(v[ix] != x) ix++;
              newTet(v[ballNodes[ix][0]], v[ballNodes[ix][1]],
                     v[ballNodes[ix][2]], GHOST);
            }
          }
        }
        // adjacencies: the boundary facets of the ring first
        for(int i = 0; i < n; i++) {
          const vIdx rp = R.vert[(i + n - 1) % n], r = R.vert[i];
          for(int side = 0; side < 2; side++) {
            vIdx x = side ? R.b : R.a, y = rp, z = r;
            if(x > y) std::swap(x, y);
            if(y > z) std::swap(y, z);
            if(x > y) std::swap(x, y);
            const tRef out = side ? R.outB[i] : R.outA[i];
            for(auto &fk : facets) {
              if(fk.ref != NO_ADJ && fk.v0 == x && fk.v1 == y && fk.v2 == z) {
                m.neigh[fk.ref] = out;
                m.neigh[out] = fk.ref;
                fk.ref = NO_ADJ;
                break;
              }
            }
          }
        }
        // then the facets between the new tets
        for(std::size_t i = 0; i < facets.size(); i++) {
          if(facets[i].ref == NO_ADJ) continue;
          for(std::size_t j = i + 1; j < facets.size(); j++) {
            if(facets[j].ref != NO_ADJ && facets[j].v0 == facets[i].v0 &&
               facets[j].v1 == facets[i].v1 && facets[j].v2 == facets[i].v2) {
              m.neigh[facets[i].ref] = facets[j].ref;
              m.neigh[facets[j].ref] = facets[i].ref;
              facets[j].ref = NO_ADJ;
              break;
            }
          }
        }
        for(int i = 0; i < n; i++)
          for(int q = 0; q < 4; q++) m.neigh[4 * R.tet[i] + q] = NO_ADJ;
        swaps++;
        return true;
      }

      // does the segment (x, y) cross the facet (u, v, w)? (x and y on either
      // side of it, and the line through the triangle)
      bool segmentCrossesFacet(const double *x, const double *y,
                               const double *u, const double *v,
                               const double *w) const
      {
        const double sx = orient3dFast(u, v, w, x),
                     sy = orient3dFast(u, v, w, y);
        if(sx * sy >= 0.) return false;
        const double s0 = orient3dFast(x, y, u, v),
                     s1 = orient3dFast(x, y, v, w),
                     s2 = orient3dFast(x, y, w, u);
        return (s0 > 0. && s1 > 0. && s2 > 0.) ||
               (s0 < 0. && s1 < 0. && s2 < 0.);
      }

      // the edges of the facets crossed by the segment (x, y), walking from x
      // to y; false when the walk fails (hull, cycle)
      // an edge of a tet, by the indices of its nodes
      struct EdgeRef {
        tIdx t;
        unsigned ia, ib;
      };
      void facetEdges(tIdx t, unsigned f, std::vector<EdgeRef> &edges)
      {
        const unsigned a = facetNode0(f), b = facetNode1(f), c = facetNode2(f);
        edges.push_back({t, std::min(a, b), std::max(a, b)});
        edges.push_back({t, std::min(b, c), std::max(b, c)});
        edges.push_back({t, std::min(c, a), std::max(c, a)});
      }

      bool crossedEdges(vIdx x, vIdx y, std::vector<EdgeRef> &edges)
      {
        edges.clear();
        const double *px = &m.xyz[4 * x], *py = &m.xyz[4 * y];
        star(x, scratch, MAX_STAR);
        tIdx cur = NO_TET;
        unsigned entering = 4;
        for(auto t : scratch) {
          const vIdx *n = &m.node[4 * t];
          if(m.isGhost(t)) continue;
          unsigned ix = 0;
          while(n[ix] != x) ix++;
          const vIdx u = n[facetNode0(ix)], v = n[facetNode1(ix)],
                     w = n[facetNode2(ix)];
          if(segmentCrossesFacet(px, py, &m.xyz[4 * u], &m.xyz[4 * v],
                                 &m.xyz[4 * w])) {
            const tRef r = m.neigh[4 * t + ix];
            facetEdges(t, ix, edges);
            cur = r >> 2;
            entering = r & 3;
            break;
          }
        }
        if(cur == NO_TET) return false;
        for(int step = 0; step < 200; step++) {
          if(m.isGhost(cur)) return false;
          const vIdx *n = &m.node[4 * cur];
          if(n[0] == y || n[1] == y || n[2] == y || n[3] == y) return true;
          unsigned exitF = 4;
          for(unsigned f = 0; f < 4 && exitF == 4; f++) {
            if(f == entering) continue;
            const vIdx u = n[facetNode0(f)], v = n[facetNode1(f)],
                       w = n[facetNode2(f)];
            if(segmentCrossesFacet(px, py, &m.xyz[4 * u], &m.xyz[4 * v],
                                   &m.xyz[4 * w])) {
              exitF = f;
              facetEdges(cur, f, edges);
            }
          }
          if(exitF == 4) return false; // the segment goes through an edge
          const tRef r = m.neigh[4 * cur + exitF];
          cur = r >> 2;
          entering = r & 3;
        }
        return false;
      }

      // remove the edge (nodes ia < ib of tet t) with the ring triangulation
      // containing the required ring positions of the given vertices when
      // they are all ring vertices (nreq of them), or any valid triangulation
      // when nreq is 0. The callers always hold a tet of the edge: locating
      // it from v2t only works for the nodes of the missing items
      bool removeEdge(tIdx t, unsigned ia, unsigned ib, const vIdx *want,
                      int nreq, tRef *facet)
      {
        if(m.isDeleted(t)) return false;
        Ring R;
        if(!buildRing(t, ia, ib, R)) return false;
        int req[3] = {-1, -1, -1};
        for(int k = 0; k < nreq; k++) {
          req[k] = ringPosition(R, want[k]);
          if(req[k] < 0) {
            rNoVertices++;
            return false;
          }
        }
        if(nreq == 2 &&
           ((req[0] + 1) % R.n == req[1] || (req[1] + 1) % R.n == req[0]))
          return false; // adjacent ring vertices: the edge exists already
        return edgeRemoval(R, req, nreq, facet);
      }

      // create the edge (x, y): by removing an edge around which x and y are
      // ring vertices, or, when no such edge exists, by removing edges of the
      // facets crossed by the segment until one does
      bool recoverEdge(vIdx x, vIdx y)
      {
        const vIdx want[2] = {x, y};
        std::vector<EdgeRef> crossed;
        for(int round = 0; round < 4; round++) {
          star(x, scratch, MAX_STAR);
          std::vector<tIdx> tets(scratch);
          for(auto t : tets) {
            const vIdx *n = &m.node[4 * t];
            for(unsigned ia = 0; ia < 4; ia++) {
              if(n[ia] == x) continue;
              for(unsigned ib = ia + 1; ib < 4; ib++) {
                if(n[ib] == x || n[ib] == GHOST) continue;
                if(removeEdge(t, ia, ib, want, 2, nullptr)) return true;
              }
            }
          }
          // no ring holds both: open the way with an unconstrained removal
          if(!crossedEdges(x, y, crossed)) return false;
          bool removed = false;
          for(auto e : crossed) {
            const vIdx p = m.node[4 * e.t + e.ia], q = m.node[4 * e.t + e.ib];
            if(p == x || p == y || q == x || q == y) continue;
            if(removeEdge(e.t, e.ia, e.ib, nullptr, 0, nullptr)) {
              removed = true;
              break;
            }
          }
          if(!removed) return false;
        }
        return false;
      }

      // create the facet (x, y, z), whose edges exist: by removing an edge
      // around which x, y and z are ring vertices, or, when no such edge
      // exists, by removing edges piercing the facet until one does
      bool recoverFacet(vIdx x, vIdx y, vIdx z, tRef &facet)
      {
        const vIdx want[3] = {x, y, z};
        const double *px = &m.xyz[4 * x], *py = &m.xyz[4 * y],
                     *pz = &m.xyz[4 * z];
        for(int round = 0; round < 4; round++) {
          // the edges of the tets around the three nodes and their neighbors
          std::vector<tIdx> tets;
          for(int k = 0; k < 3; k++) {
            star(want[k], scratch, MAX_STAR);
            tets.insert(tets.end(), scratch.begin(), scratch.end());
          }
          const std::size_t n0 = tets.size();
          for(std::size_t i = 0; i < n0; i++)
            for(unsigned f = 0; f < 4; f++)
              tets.push_back(m.neigh[4 * tets[i] + f] >> 2);
          std::set<std::uint64_t> seen;
          std::vector<EdgeRef> piercing;
          for(auto t : tets) {
            if(m.isGhost(t) || m.isDeleted(t)) continue;
            const vIdx *n = &m.node[4 * t];
            for(unsigned ia = 0; ia < 4; ia++) {
              for(unsigned ib = ia + 1; ib < 4; ib++) {
                const vIdx p = n[ia], q = n[ib];
                if(p == x || p == y || p == z || q == x || q == y || q == z)
                  continue;
                if(!seen.insert(edgeKey(p, q)).second) continue;
                // the ring of an edge around the three nodes holds them all
                if(removeEdge(t, ia, ib, want, 3, &facet)) return true;
                if(segmentCrossesFacet(&m.xyz[4 * p], &m.xyz[4 * q], px, py,
                                       pz))
                  piercing.push_back({t, ia, ib});
              }
            }
          }
          bool removed = false;
          for(auto e : piercing) {
            if(removeEdge(e.t, e.ia, e.ib, nullptr, 0, nullptr)) {
              removed = true;
              break;
            }
          }
          if(!removed) return false;
        }
        return false;
      }
    };

  } // namespace

  std::size_t recoverLocally(Mesh &m, const std::vector<vIdx> &triNode,
                             const std::vector<vIdx> &lineNode,
                             const std::vector<std::uint8_t> &lineInTriangle,
                             std::vector<tRef> &tri2tet,
                             std::vector<std::uint64_t> &line2tet, int nthreads,
                             int verbosity)
  {
    const double t0 = TimeOfDay();
    const std::size_t nt = triNode.size() / 3, nl = lineNode.size() / 2;
    std::size_t missingTri = 0, missingLines = 0;
    for(std::size_t i = 0; i < nt; i++)
      if(tri2tet[i] == NO_ADJ) missingTri++;
    for(std::size_t i = 0; i < nl; i++)
      if(!lineInTriangle[i] && line2tet[i] == NO_LINE) missingLines++;
    if(!missingTri && !missingLines) return 0;
    Recovery R(m);
    R.surfaceEdges.reserve(3 * nt + nl);
    for(std::size_t i = 0; i < nt; i++) {
      R.surfaceEdges.push_back(R.edgeKey(triNode[3 * i], triNode[3 * i + 1]));
      R.surfaceEdges.push_back(
        R.edgeKey(triNode[3 * i + 1], triNode[3 * i + 2]));
      R.surfaceEdges.push_back(R.edgeKey(triNode[3 * i + 2], triNode[3 * i]));
    }
    for(std::size_t i = 0; i < nl; i++)
      R.surfaceEdges.push_back(R.edgeKey(lineNode[2 * i], lineNode[2 * i + 1]));
    std::sort(R.surfaceEdges.begin(), R.surfaceEdges.end());
    // a tet around every vertex of a missing item
    const std::size_t nv = m.numVertices();
    std::vector<std::uint8_t> needed(nv, 0);
    for(std::size_t i = 0; i < nt; i++)
      if(tri2tet[i] == NO_ADJ)
        for(int k = 0; k < 3; k++) needed[triNode[3 * i + k]] = 1;
    for(std::size_t i = 0; i < nl; i++)
      if(!lineInTriangle[i] && line2tet[i] == NO_LINE)
        for(int k = 0; k < 2; k++) needed[lineNode[2 * i + k]] = 1;
    R.findStars(needed, nthreads);
    std::size_t recoveredTri = 0, recoveredLines = 0;
    for(int pass = 0; pass < 8; pass++) {
      bool progress = false;
      for(std::size_t i = 0; i < nl; i++) {
        if(lineInTriangle[i] || line2tet[i] != NO_LINE) continue;
        const vIdx x = lineNode[2 * i], y = lineNode[2 * i + 1];
        tIdx t = R.findEdge(x, y);
        if(t == NO_TET && R.recoverEdge(x, y)) t = R.findEdge(x, y);
        if(t == NO_TET) continue;
        int ix = 0, iy = 0;
        for(int k = 0; k < 4; k++) {
          if(m.node[4 * t + k] == x) ix = k;
          if(m.node[4 * t + k] == y) iy = k;
        }
        line2tet[i] = 6 * (std::uint64_t)t + edgeOfNodes[ix][iy];
        recoveredLines++;
        progress = true;
      }
      for(std::size_t i = 0; i < nt; i++) {
        if(tri2tet[i] != NO_ADJ) continue;
        const vIdx *v = &triNode[3 * i];
        bool edges = true;
        for(int k = 0; k < 3 && edges; k++) {
          const vIdx x = v[k], y = v[(k + 1) % 3];
          if(R.findEdge(x, y) == NO_TET) {
            progress = R.recoverEdge(x, y) || progress;
            edges = R.findEdge(x, y) != NO_TET;
          }
        }
        if(!edges) continue;
        tRef f = R.findFacet(v[0], v[1], v[2]);
        if(f == NO_ADJ && !R.recoverFacet(v[0], v[1], v[2], f)) continue;
        tri2tet[i] = f;
        recoveredTri++;
        progress = true;
      }
      if(!progress) break;
    }
    const std::size_t left =
      missingTri - recoveredTri + missingLines - recoveredLines;
    if(!left) {
      // the edge removals leave deleted tets: the caller redoes the maps on
      // the compacted mesh
      m.removeDeleted(nthreads);
    }
    if(verbosity > 0)
      Msg::Info("Boundary recovery by edge removals: %lu of %lu triangle(s) "
                "and %lu of %lu line(s) recovered by %lu removals (Wall %gs)",
                recoveredTri, missingTri, recoveredLines, missingLines, R.swaps,
                TimeOfDay() - t0);
    if(verbosity > 5)
      Msg::Info("  ring rejections: %lu with a ghost, %lu with more than 31 "
                "tets, %lu surface edges, %lu inconsistent, %lu without the "
                "nodes, %lu without a positive triangulation, %lu with a "
                "volume mismatch",
                R.rGhost, R.rBig, R.rSurfEdge, R.rBad, R.rNoVertices,
                R.rNoTriangulation, R.rVolume);
    return left;
  }

  bool colorVolumes(
    Mesh &m, const std::vector<tRef> &tri2tet,
    const std::vector<std::uint32_t> &triColor,
    const std::vector<std::vector<std::uint32_t>> &volumes,
    const std::map<std::uint32_t, std::vector<std::uint32_t>> &siblings,
    const std::set<std::uint32_t> &embedded)
  {
    auto complete = [&](std::set<std::uint32_t> &set) {
      std::set<std::uint32_t> more;
      for(auto c : set) {
        auto it = siblings.find(c);
        if(it != siblings.end())
          more.insert(it->second.begin(), it->second.end());
      }
      set.insert(more.begin(), more.end());
    };
    // flood fill bounded by the constrained facets
    if(m.color.size() < m.tetCapacity()) m.color.resize(m.tetCapacity());
    std::fill(m.color.begin(), m.color.begin() + m.ntet, 0);
    std::vector<tIdx> stack;
    std::uint32_t color = 1, colorOut = 0;
    for(std::size_t first = 0; first < m.ntet; first++) {
      if(m.isDeleted((tIdx)first) || m.color[first]) continue;
      stack.clear();
      stack.push_back((tIdx)first);
      m.color[first] = color;
      for(std::size_t i = 0; i < stack.size(); i++) {
        const tIdx t = stack[i];
        if(m.isGhost(t)) colorOut = color;
        for(unsigned f = 0; f < 4; f++) {
          const tRef r = m.neigh[4 * t + f];
          if(r == NO_ADJ || (m.flag[t] & (F_FACET0 << f))) continue;
          const tIdx nb = r >> 2;
          if(!m.color[nb]) {
            m.color[nb] = color;
            stack.push_back(nb);
          }
        }
      }
      color++;
    }
    const std::uint32_t numComponents = color - 1;
    Msg::Debug("%u connected components of tets bounded by constrained facets",
               numComponents);
    // merge the components on the two sides of the embedded surfaces
    std::vector<std::uint32_t> root(numComponents + 1);
    std::iota(root.begin(), root.end(), 0);
    auto find = [&](std::uint32_t c) {
      while(root[c] != c) c = root[c] = root[root[c]];
      return c;
    };
    bool merged = false;
    for(std::size_t i = 0; i < tri2tet.size(); i++) {
      const tRef r = tri2tet[i];
      if(r == NO_ADJ || !embedded.count(triColor[i])) continue;
      const tRef s = m.neigh[r];
      if(s == NO_ADJ) continue;
      const std::uint32_t a = find(m.color[r >> 2]), b = find(m.color[s >> 2]);
      if(a == b) continue;
      root[std::max(a, b)] = std::min(a, b);
      merged = true;
    }
    if(merged) {
      for(std::size_t t = 0; t < m.ntet; t++)
        if(!m.isDeleted((tIdx)t)) m.color[t] = find(m.color[t]);
      colorOut = find(colorOut);
    }
    // the surface colors seen by each component
    std::vector<std::set<std::uint32_t>> surfaces(numComponents + 1);
    for(std::size_t i = 0; i < tri2tet.size(); i++) {
      const tRef r = tri2tet[i];
      if(r == NO_ADJ) continue;
      surfaces[m.color[r >> 2]].insert(triColor[i]);
      const tRef s = m.neigh[r];
      if(s != NO_ADJ) surfaces[m.color[s >> 2]].insert(triColor[i]);
    }
    // match the components to the volumes
    std::map<std::set<std::uint32_t>, std::uint32_t> volumeOfSurfaces;
    for(std::uint32_t c = 1; c <= numComponents; c++) complete(surfaces[c]);
    for(std::size_t i = 0; i < volumes.size(); i++) {
      std::set<std::uint32_t> s(volumes[i].begin(), volumes[i].end());
      complete(s);
      if(volumeOfSurfaces.count(s)) {
        Msg::Error("Volumes %lu and %u are bounded by the same surfaces", i,
                   volumeOfSurfaces[s]);
        return false;
      }
      volumeOfSurfaces[s] = (std::uint32_t)i;
    }
    std::vector<std::uint32_t> map(numComponents + 1, Mesh::COLOR_OUT);
    std::vector<bool> found(volumes.size(), false);
    std::uint32_t next = (std::uint32_t)volumes.size();
    for(std::uint32_t c = 1; c <= numComponents; c++) {
      if(c == colorOut || find(c) != c) continue;
      auto it = volumeOfSurfaces.find(surfaces[c]);
      if(it != volumeOfSurfaces.end() && !found[it->second]) {
        map[c] = it->second;
        found[it->second] = true;
      }
      else
        map[c] = next++;
    }
    for(std::size_t t = 0; t < m.ntet; t++)
      if(!m.isDeleted((tIdx)t)) m.color[t] = map[m.color[t]];
    bool ok = true;
    for(std::size_t i = 0; i < volumes.size(); i++) {
      if(!found[i] && Msg::GetVerbosity() > 5) {
        std::string msg = "Volume " + std::to_string(i) + " surfaces:";
        for(auto t : volumes[i]) msg += " " + std::to_string(t);
        Msg::Info("%s", msg.c_str());
        for(std::uint32_t c = 1; c <= numComponents; c++) {
          std::string m2 = "Component " + std::to_string(c) +
                           (c == colorOut ? " (outside):" : ":");
          for(auto t : surfaces[c]) m2 += " " + std::to_string(t);
          Msg::Info("%s", m2.c_str());
        }
      }
      if(!found[i]) {
        Msg::Error("Volume %lu was not found in the tetrahedralization (its "
                   "bounding surfaces "
                   "do not enclose a single connected component)",
                   i);
        ok = false;
      }
    }
    if(next > volumes.size())
      Msg::Info("%u enclosed volume(s) not in the model will not be refined",
                next - (std::uint32_t)volumes.size());
    return ok;
  }

} // namespace pdel3d

// Refinement of the pdel3d mesh: rounds of candidate points, one per tet that
// is too large for the mesh size, filtered and inserted all at once by the
// parallel Delaunay kernel (after HXT's hxt_tetRefine.c)

namespace pdel3d {

  namespace {

    inline double sqDist(const double *a, const double *b)
    {
      const double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
      return dx * dx + dy * dy + dz * dz;
    }

    inline bool tooClose(double s0, double s1, double d2,
                         const RefineOptions &opt)
    {
      if(s0 > 0. && s1 > 0.) {
        const double s =
          std::min(opt.sizeMax, std::max(opt.sizeMin, 0.5 * (s0 + s1))) *
          opt.sizeFactor;
        return d2 < s * s;
      }
      return false;
    }

    // A point inside the tet of nodes p[4] (with sizes s[4]) likely to respect
    // the mesh size: the circumcenter of the tet measured in edge lengths
    // normalized by the sizes, or, when it falls outside the tet or too close
    // to a node, a point between the centroid and the isotomic conjugate of
    // the incenter. center[3] receives the size interpolated there. Returns
    // true when even that point is too close to a node (from HXT)
    bool bestCenter(const double p[4][4], const double nodalSize[4],
                    double center[4], const RefineOptions &opt)
    {
      double avg = 0., num = 0.;
      for(int i = 0; i < 4; i++) {
        if(nodalSize[i] > 0.) {
          avg += nodalSize[i];
          num += 1.;
        }
      }
      avg = num ? avg / num : 1.;
      const double s0 = nodalSize[0] > 0. ? nodalSize[0] : avg;
      const double s1 = nodalSize[1] > 0. ? nodalSize[1] : avg;
      const double s2 = nodalSize[2] > 0. ? nodalSize[2] : avg;
      const double s3 = nodalSize[3] > 0. ? nodalSize[3] : avg;
      // (edge length / mean size over the edge)^2
      const double e0l2 = sqDist(p[0], p[1]) / (0.25 * (s0 + s1) * (s0 + s1));
      const double e1l2 = sqDist(p[0], p[2]) / (0.25 * (s0 + s2) * (s0 + s2));
      const double e2l2 = sqDist(p[0], p[3]) / (0.25 * (s0 + s3) * (s0 + s3));
      const double e3l2 = sqDist(p[1], p[2]) / (0.25 * (s1 + s2) * (s1 + s2));
      const double e4l2 = sqDist(p[1], p[3]) / (0.25 * (s1 + s3) * (s1 + s3));
      const double e5l2 = sqDist(p[2], p[3]) / (0.25 * (s2 + s3) * (s2 + s3));
      // the tet with those edge lengths: O = (0,0,0), A = (xa,0,0),
      // B = (xb,yb,0), C = (xc,yc,zc)
      const double xa = std::sqrt(e0l2);
      const double invtwoxa = 1. / (2 * xa);
      const double xb = (e1l2 + e0l2 - e3l2) * invtwoxa;
      const double yb = std::sqrt(e1l2 - xb * xb);
      const double xc = (e2l2 + e0l2 - e4l2) * invtwoxa;
      const double yc = (e1l2 + e2l2 - e5l2 - 2 * xb * xc) / (2 * yb);
      const double zc = std::sqrt(e2l2 - xc * xc - yc * yc);
      const double xcrossbc = yb * zc, ycrossbc = -zc * xb,
                   zcrossbc = xb * yc - xc * yb;
      const double ycrossca = zc * xa, zcrossca = -xa * yc, zcrossab = xa * yb;
      const double denominator = 0.5 / (xa * yb * zc);
      const double xcirca = 0.5 * xa;
      const double ycirca = (e0l2 * ycrossbc + e1l2 * ycrossca) * denominator;
      const double zcirca =
        (e0l2 * zcrossbc + e1l2 * zcrossca + e2l2 * zcrossab) * denominator;
      double bary0 =
        (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
        (2. * denominator);
      double bary1 =
        (ycirca * ycrossca + zcirca * zcrossca) * (2. * denominator);
      double bary2 = (zcirca * zcrossab) * (2. * denominator);
      double bary3 = 1. - bary0 - bary1 - bary2;
      bool circumcenterOutside = false, circumcenterTooClose = false;
      if(bary0 > 0. && bary1 > 0. && bary2 > 0. && bary3 > 0.) {
        center[0] =
          bary0 * p[0][0] + bary1 * p[1][0] + bary2 * p[2][0] + bary3 * p[3][0];
        center[1] =
          bary0 * p[0][1] + bary1 * p[1][1] + bary2 * p[2][1] + bary3 * p[3][1];
        center[2] =
          bary0 * p[0][2] + bary1 * p[1][2] + bary2 * p[2][2] + bary3 * p[3][2];
        center[3] = bary0 * s0 + bary1 * s1 + bary2 * s2 + bary3 * s3;
        circumcenterTooClose =
          tooClose(s0, center[3], sqDist(p[0], center), opt) ||
          tooClose(s1, center[3], sqDist(p[1], center), opt) ||
          tooClose(s2, center[3], sqDist(p[2], center), opt) ||
          tooClose(s3, center[3], sqDist(p[3], center), opt);
      }
      else // also when a barycentric coordinate is not finite
        circumcenterOutside = true;
      bool otherCenterTooClose = false;
      if(circumcenterOutside || circumcenterTooClose) {
        // the sum of the cross products of the facets of a tet is zero
        const double xsumcros = xcrossbc, ysumcros = ycrossbc + ycrossca;
        const double zsumcros = zcrossab + zcrossbc + zcrossca;
        const double invA0x2 =
          1. / std::sqrt(xsumcros * xsumcros + ysumcros * ysumcros +
                         zsumcros * zsumcros);
        const double invA1x2 =
          1. / std::sqrt(xcrossbc * xcrossbc + ycrossbc * ycrossbc +
                         zcrossbc * zcrossbc);
        const double invA2x2 =
          1. / std::sqrt(ycrossca * ycrossca + zcrossca * zcrossca);
        const double invA3x2 = 1. / zcrossab;
        const double den = invA0x2 + invA1x2 + invA2x2 + invA3x2;
        const double alpha = 0.5;
        bary0 = (1. - alpha) * 0.25 + alpha * invA0x2 / den;
        bary1 = (1. - alpha) * 0.25 + alpha * invA1x2 / den;
        bary2 = (1. - alpha) * 0.25 + alpha * invA2x2 / den;
        bary3 = (1. - alpha) * 0.25 + alpha * invA3x2 / den;
        if(!std::isfinite(bary0) || !std::isfinite(bary1) ||
           !std::isfinite(bary2) || !std::isfinite(bary3))
          bary0 = bary1 = bary2 = bary3 = 0.25;
        double other[4];
        other[0] =
          bary0 * p[0][0] + bary1 * p[1][0] + bary2 * p[2][0] + bary3 * p[3][0];
        other[1] =
          bary0 * p[0][1] + bary1 * p[1][1] + bary2 * p[2][1] + bary3 * p[3][1];
        other[2] =
          bary0 * p[0][2] + bary1 * p[1][2] + bary2 * p[2][2] + bary3 * p[3][2];
        other[3] = bary0 * s0 + bary1 * s1 + bary2 * s2 + bary3 * s3;
        otherCenterTooClose =
          tooClose(s0, other[3], sqDist(p[0], other), opt) ||
          tooClose(s1, other[3], sqDist(p[1], other), opt) ||
          tooClose(s2, other[3], sqDist(p[2], other), opt) ||
          tooClose(s3, other[3], sqDist(p[3], other), opt);
        if(circumcenterOutside || !otherCenterTooClose) {
          for(int k = 0; k < 4; k++) center[k] = other[k];
        }
      }
      return otherCenterTooClose;
    }

    // drop the vertices from `first` on that were not inserted (status[i]
    // is the status of toInsert[i]), renumbering the nodes of the tets
    void compactNewVertices(Mesh &m, std::size_t first,
                            const std::vector<vIdx> &toInsert,
                            const std::vector<std::uint8_t> &status,
                            int nthreads)
    {
      const std::size_t nv = m.numVertices(), nnew = nv - first;
      std::vector<vIdx> newIndex(nnew, GHOST);
      for(std::size_t i = 0; i < toInsert.size(); i++)
        if(status[i] == ST_INSERTED) newIndex[toInsert[i] - first] = 0;
      vIdx n = (vIdx)first;
      for(std::size_t v = first; v < nv; v++) {
        if(newIndex[v - first] == GHOST) continue;
        newIndex[v - first] = n;
        if(n != v)
          for(int k = 0; k < 4; k++) m.xyz[4 * n + k] = m.xyz[4 * v + k];
        n++;
      }
      if(n == nv) return;
      m.xyz.resize(4 * n);
      m.numDefaultDist = std::min(m.numDefaultDist, first);
#pragma omp parallel for schedule(static) num_threads(nthreads)
      for(std::size_t t = 0; t < m.ntet; t++) {
        if(m.isDeleted((tIdx)t)) continue;
        for(int k = 0; k < 4; k++) {
          const vIdx v = m.node[4 * t + k];
          if(v != GHOST && v >= first) m.node[4 * t + k] = newIndex[v - first];
        }
      }
    }

  } // namespace

  void refine(Mesh &m, RefineOptions &opt)
  {
    const double t0 = TimeOfDay();
    const int nthreads = std::max(1, opt.numThreads);
    // only the tets of the volumes are refined
#pragma omp parallel for schedule(static) num_threads(nthreads)
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t)) continue;
      if(m.color[t] >= opt.numVolumes)
        m.flag[t] |= F_PROCESSED;
      else
        m.flag[t] &= ~F_PROCESSED;
    }
    DelaunayOptions dopt;
    dopt.numThreads = nthreads;
    dopt.perfectDelaunay = false;
    dopt.allowOuterInsertion = false;
    dopt.filterOnSize = true;
    dopt.sizeMin = opt.sizeMin;
    dopt.sizeMax = opt.sizeMax;
    dopt.sizeFactor = opt.sizeFactor;
    dopt.curveFilterWindow = opt.curveFilterWindow;
    dopt.compact = false; // once at the end
    dopt.verbosity = opt.verbosity - 1; // its lines per round at -v 6
    DelaunayStats stats;
    std::size_t totalCandidates = 0, totalInserted = 0, totalKept = 0;
    double timeCandidates = 0., timeSizes = 0., timeCompact = 0.;
    std::vector<std::vector<double>> localPts(nthreads);
    std::vector<std::vector<tIdx>> localTets(nthreads);
    std::size_t lastKept = m.ntet / 8;
    for(int iter = 0; iter < 42; iter++) {
      const double t1 = TimeOfDay();
      // one candidate per unprocessed tet; the unprocessed tets are the new
      // ones, gathered at the end of the array, hence the dynamic schedule.
      // The candidates too close to a node of their tet for the size
      // interpolated from its nodes are dropped: the size field is only
      // evaluated on those kept (as HXT does: on the nozzle 785M candidates
      // against 169M kept, and the field took 470 of 540 s)
      const std::size_t ntet = m.ntet;
      std::size_t numCandidates = 0;
#pragma omp parallel num_threads(nthreads) reduction(+ : numCandidates)
      {
        const int tid = Msg::GetThreadNum();
        std::vector<double> &pts = localPts[tid];
        std::vector<tIdx> &tets = localTets[tid];
        pts.clear();
        tets.clear();
        const std::size_t expected = lastKept / nthreads + 4096;
        pts.reserve(4 * (expected + expected / 4));
        tets.reserve(expected + expected / 4);
#pragma omp for schedule(dynamic, 4096) nowait
        for(std::size_t t = 0; t < ntet; t++) {
          if(m.flag[t] & (F_PROCESSED | F_DELETED)) continue;
          m.flag[t] |= F_PROCESSED;
          double p[4][4], s[4];
          for(int i = 0; i < 4; i++) {
            const vIdx v = m.node[4 * t + i];
            for(int k = 0; k < 3; k++) p[i][k] = m.xyz[4 * v + k];
            s[i] = m.xyz[4 * v + 3];
          }
          double center[4];
          numCandidates++;
          if(bestCenter(p, s, center, opt)) continue;
          pts.insert(pts.end(), center, center + 4);
          tets.push_back((tIdx)t);
        }
      }
      totalCandidates += numCandidates;
      if(!numCandidates) break;
      // the candidates kept, appended to the mesh vertices
      std::vector<std::size_t> offset(nthreads + 1, 0);
      for(int i = 0; i < nthreads; i++)
        offset[i + 1] = offset[i] + localTets[i].size();
      const std::size_t numKept = offset[nthreads];
      lastKept = numKept;
      const std::size_t first = m.numVertices();
      std::vector<vIdx> toInsert(numKept);
      std::vector<tIdx> hints(numKept);
      if(m.xyz.capacity() < 4 * (first + numKept))
        m.xyz.reserve(4 * (first + numKept) + 2 * (first + numKept));
      m.xyz.resize(4 * (first + numKept));
#pragma omp parallel for schedule(static) num_threads(nthreads)
      for(int i = 0; i < nthreads; i++) {
        std::copy(localPts[i].begin(), localPts[i].end(),
                  &m.xyz[4 * (first + offset[i])]);
        for(std::size_t j = 0; j < localTets[i].size(); j++) {
          toInsert[offset[i] + j] = (vIdx)(first + offset[i] + j);
          hints[offset[i] + j] = localTets[i][j];
        }
      }
      const double t4 = TimeOfDay();
      // the sizes of the kept candidates from the field, in the volume of
      // their tet
      double timeSizesRound = 0.;
      if(opt.sizeCallback && numKept) {
        std::vector<std::uint32_t> colors(numKept);
#pragma omp parallel for schedule(static) num_threads(nthreads)
        for(std::size_t i = 0; i < numKept; i++) colors[i] = m.color[hints[i]];
        opt.sizeCallback(&m.xyz[4 * first], colors.data(), numKept,
                         opt.sizeData);
        timeSizesRound = TimeOfDay() - t4;
      }
      timeSizes += timeSizesRound;
      if(toInsert.empty()) break;
      totalKept += toInsert.size();
      dopt.partitionability = 1. - std::pow(0.5, iter);
      dopt.numVerticesInMesh = first;
      std::vector<std::uint8_t> status;
      const std::size_t before = stats.inserted;
      insertVertices(m, dopt, toInsert, status, &stats, &hints);
      const double t5 = TimeOfDay();
      compactNewVertices(m, first, toInsert, status, nthreads);
      timeCandidates += t4 - t1;
      timeCompact += TimeOfDay() - t5;
      totalInserted += stats.inserted - before;
      if(opt.verbosity > 0) {
        std::size_t numTets = 0;
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  reduction(+ : numTets)
        for(std::size_t t = 0; t < m.ntet; t++)
          if(!(m.flag[t] & F_DELETED) && m.color[t] < opt.numVolumes) numTets++;
        Msg::Info("Refinement round %d: %lu nodes, %lu tets (%lu of %lu "
                  "candidates inserted, Wall %gs)",
                  iter, m.numVertices(), numTets, stats.inserted - before,
                  toInsert.size(), TimeOfDay() - t1);
      }
      if(stats.inserted == before) break;
    }
    const double t6 = TimeOfDay();
    m.removeDeleted(nthreads);
    timeCompact += TimeOfDay() - t6;
    if(opt.verbosity > 0)
      Msg::Info("Refinement: %lu nodes inserted out of %lu candidates in %lu "
                "rounds (Wall %gs)",
                totalInserted, totalCandidates, stats.rounds, TimeOfDay() - t0);
    if(opt.verbosity > 1)
      Msg::Info("  %lu candidates kept, %lu filtered on the curve, %lu in "
                "their cavity; candidates %gs, sizes %gs, sort %gs, insert "
                "%gs, compaction %gs",
                totalKept, stats.curveFiltered, stats.filtered, timeCandidates,
                timeSizes, stats.timeSort, stats.timeInsert, timeCompact);
  }

} // namespace pdel3d

static int numThreads3D()
{
  int n = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    n = CTX::instance()->mesh.maxNumThreads3D;
  if(!n) n = Msg::GetMaxThreads();
  return n;
}

void delaunayMeshIn3DParallel(std::vector<MVertex *> &v,
                              std::vector<MTetrahedron *> &tets)
{
  const double t0 = TimeOfDay();
  const std::size_t n = v.size();
  pdel3d::Mesh m;
  m.xyz.resize(4 * n);
  for(std::size_t i = 0; i < n; i++) {
    m.xyz[4 * i + 0] = v[i]->x();
    m.xyz[4 * i + 1] = v[i]->y();
    m.xyz[4 * i + 2] = v[i]->z();
    m.xyz[4 * i + 3] = 0.;
  }
  m.reserveTets(8 * n + 16384);
  std::vector<pdel3d::vIdx> toInsert(n);
  std::iota(toInsert.begin(), toInsert.end(), 0);
  std::vector<std::uint8_t> status;
  pdel3d::DelaunayOptions opt;
  opt.numThreads = numThreads3D();
  opt.reorderVertices = true; // toInsert[i] = original index of vertex i
  opt.verbosity = Msg::GetVerbosity() > 5 ? 2 : 1;
  pdel3d::DelaunayStats stats;
  pdel3d::insertVertices(m, opt, toInsert, status, &stats);
  if(Msg::GetVerbosity() > 5) m.verify(true);
  tets.reserve(m.numRealTets());
  for(std::size_t t = 0; t < m.ntet; t++) {
    if(m.isGhost((pdel3d::tIdx)t)) continue;
    const pdel3d::vIdx *nd = &m.node[4 * t];
    tets.push_back(new MTetrahedron(v[toInsert[nd[0]]], v[toInsert[nd[1]]],
                                    v[toInsert[nd[2]]], v[toInsert[nd[3]]]));
  }
  Msg::Info("pdel3d: %lu points, %lu tets (Wall %gs: sort %g, insert %g)", n,
            tets.size(), TimeOfDay() - t0, stats.timeSort, stats.timeInsert);
}

// volume meshing

namespace {

  // the surface mesh of a group of regions, in pdel3d numbering
  struct SurfaceMesh {
    std::vector<GFace *> surfaces;
    std::vector<GEdge *> curves;
    std::vector<GVertex *> points;
    std::vector<MVertex *> vertices; // index -> vertex
    std::vector<pdel3d::vIdx> triNode, lineNode;
    std::vector<std::uint32_t> triColor, lineColor;
    std::vector<MTriangle *> triElem; // the elements behind triNode/lineNode
    std::vector<MLine *> lineElem;
    // surface tags bounding (or embedded in) each region
    std::vector<std::vector<std::uint32_t>> volumes;
    std::set<std::uint32_t> embedded; // the tags of the embedded surfaces
    // the surfaces forming a compound with each surface (a member may carry
    // no element when the elements are classified on the originals)
    std::map<std::uint32_t, std::vector<std::uint32_t>> siblings;
  };

  // The apex of the pyramid on quadrangle mf, whose element normal points
  // into the volume when inward is 1 and out of it when -1. del3d puts it at
  // the barycenter, exactly on the quadrangle, which its boundary recovery
  // and refinement handle exactly. Here the coordinates are perturbed: tets
  // would be built between the quadrangle and the side triangles of the
  // pyramid, colored inside when the perturbation puts the apex outside,
  // and flattened when the coordinates are restored. The apex is pushed
  // into the volume by 1% of the quadrangle's diagonal, further when the
  // quadrangle is warped, so that it is above the planes of the four
  // triangles of its base by that much and those tets are outside.
  // Mesh.OptimizePyramids < 0 gives the push explicitly, as in del3d
  SPoint3 pyramidApex(const MFace &mf, int inward)
  {
    SPoint3 c = mf.barycenter();
    SVector3 n = mf.normal() * (double)inward;
    const double diag = std::max(mf.getVertex(0)->distance(mf.getVertex(2)),
                                 mf.getVertex(1)->distance(mf.getVertex(3)));
    double t;
    if(CTX::instance()->mesh.optimizePyramids < 0) {
      t = std::abs(CTX::instance()->mesh.optimizePyramids) * diag;
    }
    else {
      const double delta = 0.01 * diag;
      t = delta;
      static const int tri[4][3] = {{0, 1, 2}, {0, 2, 3}, {1, 2, 3}, {0, 1, 3}};
      for(int i = 0; i < 4; i++) {
        SPoint3 a = mf.getVertex(tri[i][0])->point();
        SVector3 nt = crossprod(SVector3(a, mf.getVertex(tri[i][1])->point()),
                                SVector3(a, mf.getVertex(tri[i][2])->point()));
        if(nt.normalize() == 0.) continue;
        double cosine = dot(nt, n);
        if(cosine < 0.) {
          nt *= -1.;
          cosine = -cosine;
        }
        if(cosine < 0.5) continue; // badly warped: the pyramid is hopeless
        // height of the barycenter above the plane of the triangle
        const double h = dot(SVector3(a, c), nt);
        t = std::max(t, (delta - h) / cosine);
      }
    }
    return SPoint3(c.x() + t * n.x(), c.y() + t * n.y(), c.z() + t * n.z());
  }

  // returns false when the input is not supported (polygons). The surfaces
  // are the boundary and embedded surfaces of the regions (a compound surface
  // replacing its members when their elements are not reclassified on them);
  // the curves to preserve are the ones embedded in the regions, the others
  // being edges of the surface triangles. Quadrangles are handled as in
  // del3d (splitQuadRecovery): each gets a pyramid apex and its four side
  // triangles are the constraints (the pyramid is built at the end), or two
  // triangles when no pyramids are wanted. The recovery object is filled on
  // the first call and reused on the next ones
  bool collectSurfaceMesh(std::vector<GRegion *> &regions, SurfaceMesh &s,
                          splitQuadRecovery &sqr)
  {
    std::set<GFace *, GEntityPtrLessThan> surfaces;
    std::set<GEdge *, GEntityPtrLessThan> curves;
    const bool compounds = (CTX::instance()->mesh.compoundClassify == 0);
    auto surface = [&](GFace *gf) {
      return (compounds && gf->compoundSurface) ? gf->compoundSurface : gf;
    };
    for(GRegion *gr : regions) {
      std::set<std::uint32_t> tags;
      for(GFace *gf : gr->faces()) {
        surfaces.insert(surface(gf));
        tags.insert(surface(gf)->tag());
      }
      for(GFace *gf : gr->embeddedFaces()) {
        surfaces.insert(surface(gf));
        tags.insert(surface(gf)->tag());
        s.embedded.insert(surface(gf)->tag());
      }
      s.volumes.push_back(std::vector<std::uint32_t>(tags.begin(), tags.end()));
      for(GEdge *ge : gr->embeddedEdges()) curves.insert(ge);
      for(GVertex *gv : gr->embeddedVertices()) s.points.push_back(gv);
    }
    for(GFace *gf : surfaces) {
      if(gf->polygons.size()) {
        Msg::Warning("Surface %d contains polygons: the Parallel Delaunay "
                     "algorithm only supports triangles and quadrangles",
                     gf->tag());
        return false;
      }
    }
    s.surfaces.assign(surfaces.begin(), surfaces.end());
    if(sqr.getQuad().empty()) {
      // the quadrangles of the boundary surfaces, with the volume each
      // bounds (its orientation gives the side of the apex)
      std::vector<std::pair<GFace *, int>> quadSurfaces;
      std::set<GFace *> seen;
      for(GRegion *gr : regions) {
        std::map<GFace *, int> inward;
        bool oriented = false;
        for(GFace *gf : gr->faces()) {
          if(gf->quadrangles.empty()) continue;
          if(seen.count(gf)) {
            Msg::Warning("Surface %d with quadrangles bounds two volumes: "
                         "non-manifold quadrangle boundaries are not supported",
                         gf->tag());
            return false;
          }
          seen.insert(gf);
          if(!oriented && !orientRegionBoundary(gr, inward)) {
            Msg::Warning("Cannot orient the boundary mesh of volume %d to "
                         "place the pyramids on its quadrangles",
                         gr->tag());
            return false;
          }
          oriented = true;
          quadSurfaces.push_back({gf, inward[gf]});
        }
        // no pyramid on an embedded surface (it would need one on each side)
        for(GFace *gf : gr->embeddedFaces()) {
          if(gf->quadrangles.empty()) continue;
          Msg::Warning("Quadrangles of embedded surface %d are split in two "
                       "triangles in the volume mesh",
                       gf->tag());
          for(MQuadrangle *q : gf->quadrangles)
            sqr.add(q->getFace(0), nullptr, gf);
        }
      }
      for(auto &qs : quadSurfaces) {
        GFace *gf = qs.first;
        for(MQuadrangle *q : gf->quadrangles) {
          MFace mf = q->getFace(0);
          MVertex *apex = nullptr;
          if(sqr.doWeCreatePyramids()) {
            SPoint3 p = pyramidApex(mf, qs.second);
            // classified on the volume when the pyramid is built
            apex = new MVertex(p.x(), p.y(), p.z(), gf);
          }
          sqr.add(mf, apex, gf);
        }
      }
    }
    s.curves.assign(curves.begin(), curves.end());
    for(GFace *gf : s.surfaces) {
      if(gf->compound.empty()) continue;
      std::vector<std::uint32_t> &sib = s.siblings[gf->tag()];
      for(GEntity *ge : gf->compound) sib.push_back(ge->tag());
    }
    // number the vertices in order of appearance
    auto index = [&](MVertex *v) -> pdel3d::vIdx {
      if(v->getIndex() < 0) {
        v->setIndex((long)s.vertices.size());
        s.vertices.push_back(v);
      }
      return (pdel3d::vIdx)v->getIndex();
    };
    for(GFace *gf : s.surfaces)
      for(MTriangle *t : gf->triangles)
        for(int k = 0; k < 3; k++) t->getVertex(k)->setIndex(-1);
    for(auto &it : sqr.getTri())
      for(int k = 0; k < 3; k++) it.first.getVertex(k)->setIndex(-1);
    for(GEdge *ge : s.curves)
      for(MLine *l : ge->lines)
        for(int k = 0; k < 2; k++) l->getVertex(k)->setIndex(-1);
    for(GVertex *gv : s.points)
      for(MPoint *p : gv->points) p->getVertex(0)->setIndex(-1);
    for(GFace *gf : s.surfaces) {
      for(MTriangle *t : gf->triangles) {
        for(int k = 0; k < 3; k++) s.triNode.push_back(index(t->getVertex(k)));
        s.triColor.push_back(gf->tag());
        s.triElem.push_back(t);
      }
    }
    // the triangles standing for the quadrangles (no element behind them)
    for(auto &it : sqr.getTri()) {
      for(int k = 0; k < 3; k++)
        s.triNode.push_back(index(it.first.getVertex(k)));
      s.triColor.push_back(surface(it.second)->tag());
      s.triElem.push_back(nullptr);
    }
    for(GEdge *ge : s.curves) {
      for(MLine *l : ge->lines) {
        if(l->getVertex(0) == l->getVertex(1)) continue;
        for(int k = 0; k < 2; k++) s.lineNode.push_back(index(l->getVertex(k)));
        s.lineColor.push_back(ge->tag());
        s.lineElem.push_back(l);
      }
    }
    for(GVertex *gv : s.points)
      for(MPoint *p : gv->points) index(p->getVertex(0));
    return true;
  }

  // the coordinates of the vertices of s and their mesh size: prescribed at
  // the embedded points, otherwise the mean length of their edges in the
  // triangles and lines
  void setVertices(const SurfaceMesh &s, pdel3d::Mesh &m, double factor)
  {
    const std::size_t nv = s.vertices.size();
    m.xyz.assign(4 * nv, 0.);
    for(std::size_t v = 0; v < nv; v++) {
      m.xyz[4 * v + 0] = s.vertices[v]->x();
      m.xyz[4 * v + 1] = s.vertices[v]->y();
      m.xyz[4 * v + 2] = s.vertices[v]->z();
    }
    m.numDefaultDist = 0; // the curve coordinates are those of other vertices
    if(CTX::instance()->mesh.lcFromPoints) {
      for(GVertex *gv : s.points) {
        if(gv->prescribedMeshSizeAtVertex() == MAX_LC) continue;
        for(MPoint *p : gv->points)
          m.xyz[4 * p->getVertex(0)->getIndex() + 3] =
            gv->prescribedMeshSizeAtVertex() / factor;
      }
    }
    std::vector<double> sum(nv, 0.), count(nv, 0.);
    auto addEdge = [&](pdel3d::vIdx a, pdel3d::vIdx b) {
      const double l =
        std::sqrt(std::pow(m.xyz[4 * a] - m.xyz[4 * b], 2) +
                  std::pow(m.xyz[4 * a + 1] - m.xyz[4 * b + 1], 2) +
                  std::pow(m.xyz[4 * a + 2] - m.xyz[4 * b + 2], 2));
      sum[a] += l;
      sum[b] += l;
      count[a] += 1.;
      count[b] += 1.;
    };
    for(std::size_t i = 0; i < s.triNode.size() / 3; i++)
      for(int j = 0; j < 3; j++)
        addEdge(s.triNode[3 * i + j], s.triNode[3 * i + (j + 1) % 3]);
    for(std::size_t i = 0; i < s.lineNode.size() / 2; i++)
      addEdge(s.lineNode[2 * i], s.lineNode[2 * i + 1]);
    for(std::size_t v = 0; v < nv; v++) {
      if(m.xyz[4 * v + 3] > 0.) continue; // prescribed
      m.xyz[4 * v + 3] = count[v] > 0. ? sum[v] / (count[v] * factor) : 0.;
    }
  }

  struct SizeData {
    std::vector<GRegion *> *regions;
    int nthreads;
    bool failed;
  };

  // perturb the coordinates of the vertices by a random fraction of the
  // model size, and restore them on destruction
  class perturbedCoordinates {
  private:
    std::vector<MVertex *> _vertices;
    std::vector<double> _xyz;

  public:
    perturbedCoordinates(const std::vector<MVertex *> &vertices, double factor)
    {
      if(factor <= 0. || vertices.empty()) return;
      _vertices = vertices;
      _xyz.resize(3 * vertices.size());
      double d = 0.;
      for(std::size_t i = 0; i < vertices.size(); i++) {
        MVertex *v = vertices[i];
        _xyz[3 * i] = v->x();
        _xyz[3 * i + 1] = v->y();
        _xyz[3 * i + 2] = v->z();
        d =
          std::max(d, std::max(std::fabs(v->x()),
                               std::max(std::fabs(v->y()), std::fabs(v->z()))));
      }
      d *= std::sqrt(3.) * factor;
      std::uint32_t seed = 12345;
      auto r = [&seed]() {
        seed = seed * 1664525u + 1013904223u;
        return seed * (1. / 4294967296.);
      };
      for(MVertex *v : _vertices) {
        v->x() += d * r();
        v->y() += d * r();
        v->z() += d * r();
      }
    }
    void restore()
    {
      for(std::size_t i = 0; i < _vertices.size(); i++)
        _vertices[i]->setXYZ(_xyz[3 * i], _xyz[3 * i + 1], _xyz[3 * i + 2]);
      _vertices.clear();
    }
    ~perturbedCoordinates() { restore(); }
  };

  // the gmsh mesh size field at the candidate points
  void sizeCallback(double *xyzs, const std::uint32_t *color, std::size_t n,
                    void *data)
  {
    SizeData *sd = (SizeData *)data;
    std::vector<GRegion *> &regions = *sd->regions;
    const double lcGlob = CTX::instance()->lc;
    const bool extend = Extend2dMeshIn3dVolumes();
    // without a size field or a callback the size is a constant per volume
    // (its own size, the global one): no evaluation per point
    GModel *gm = regions.empty() ? nullptr : regions[0]->model();
    if(gm && gm->getFields()->getBackgroundField() <= 0 && !gm->lcCallback) {
      std::vector<double> lc(regions.size());
      for(std::size_t r = 0; r < regions.size(); r++)
        lc[r] = std::min(lcGlob, regions[r]->getMeshSize());
      for(std::size_t i = 0; i < n; i++) {
        if(color[i] >= regions.size()) continue;
        if(extend && xyzs[4 * i + 3] > 0.)
          xyzs[4 * i + 3] = std::min(xyzs[4 * i + 3], lc[color[i]]);
        else
          xyzs[4 * i + 3] = lc[color[i]];
      }
      return;
    }
    const int nthreads =
      std::min(sd->nthreads, CTX::instance()->numThreadsFor(n, 1 << 12));
    std::atomic<bool> exceptions(false);
#pragma omp parallel for schedule(dynamic, 256) num_threads(nthreads)
    for(std::size_t i = 0; i < n; i++) {
      if(exceptions || color[i] >= regions.size()) continue;
      try { // OpenMP forbids leaving the block through an exception
        const double lc =
          BGM_MeshSizeWithoutScaling(regions[color[i]], 0, 0, xyzs[4 * i],
                                     xyzs[4 * i + 1], xyzs[4 * i + 2]);
        if(extend && xyzs[4 * i + 3] > 0.)
          xyzs[4 * i + 3] = std::min(xyzs[4 * i + 3], std::min(lcGlob, lc));
        else
          xyzs[4 * i + 3] = std::min(lcGlob, lc);
      } catch(...) {
        exceptions = true;
      }
    }
    if(exceptions) sd->failed = true;
  }

  // boundary recovery with TetGen (meshGRegionBoundaryRecovery), starting
  // from the current tetrahedralization; the recovered tets (covering the
  // convex hull) come back as elements of regions[0], and the curve and
  // surface meshes may have changed (Steiner points). The mesh is rebuilt
  // from them: vertices, tets, adjacencies and ghosts
  bool recoverBoundary(pdel3d::Mesh &m, SurfaceMesh &s,
                       std::vector<GRegion *> &regions, splitQuadRecovery &sqr,
                       double sizeFactor)
  {
    initialTetrahedralization init;
    init.vertices = s.vertices;
    std::vector<pdel3d::tIdx> realIndex(m.ntet, pdel3d::NO_TET);
    pdel3d::tIdx n = 0;
    for(std::size_t t = 0; t < m.ntet; t++)
      if(!m.isDeleted((pdel3d::tIdx)t) && !m.isGhost((pdel3d::tIdx)t))
        realIndex[t] = n++;
    init.tetNode.reserve(4 * n);
    init.neighbors.reserve(4 * n);
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(realIndex[t] == pdel3d::NO_TET) continue;
      for(int k = 0; k < 4; k++) {
        init.tetNode.push_back(m.node[4 * t + k]);
        const pdel3d::tRef r = m.neigh[4 * t + k];
        init.neighbors.push_back(realIndex[r >> 2] == pdel3d::NO_TET ?
                                   -1 :
                                   (std::int64_t)realIndex[r >> 2]);
      }
    }
    GRegion *gr = regions[0];
    bool ok;
    {
      regionGroupBoundary group(regions);
      ok = meshGRegionBoundaryRecovery(gr, &sqr, &init);
    }
    if(!ok) return false;
    // the surface mesh again (it may have changed), then the vertices of the
    // tets that are not in it (Steiner points in the volume)
    s = SurfaceMesh();
    if(!collectSurfaceMesh(regions, s, sqr)) return false;
    for(MVertex *v : gr->mesh_vertices) v->setIndex(-1);
    for(MTetrahedron *t : gr->tetrahedra) {
      for(int k = 0; k < 4; k++) {
        MVertex *v = t->getVertex(k);
        if(v->getIndex() < 0) {
          v->setIndex((long)s.vertices.size());
          s.vertices.push_back(v);
        }
      }
    }
    // the Steiner points of the local recovery that are gone
    std::size_t kept = 0;
    for(MVertex *v : gr->mesh_vertices) {
      if(v->getIndex() < 0)
        delete v;
      else
        gr->mesh_vertices[kept++] = v;
    }
    gr->mesh_vertices.resize(kept);
    setVertices(s, m, sizeFactor);
    // the tets, oriented with orient3d(n0, n1, n2, n3) < 0
    const std::size_t ntet = gr->tetrahedra.size();
    m.ntet = 0;
    m.reserveTets(2 * ntet + 4096); // room for the ghosts
    m.ntet = ntet;
    std::size_t flat = 0;
    for(std::size_t t = 0; t < ntet; t++) {
      MTetrahedron *tet = gr->tetrahedra[t];
      pdel3d::vIdx *n = &m.node[4 * t];
      for(int k = 0; k < 4; k++)
        n[k] = (pdel3d::vIdx)tet->getVertex(k)->getIndex();
      const double o = robustPredicates::orient3d(
        &m.xyz[4 * n[0]], &m.xyz[4 * n[1]], &m.xyz[4 * n[2]], &m.xyz[4 * n[3]]);
      if(o > 0.) std::swap(n[0], n[1]);
      if(o == 0.) flat++;
      m.flag[t] = 0;
      for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = pdel3d::NO_ADJ;
      delete tet;
    }
    gr->tetrahedra.clear();
    if(flat) {
      Msg::Error("%lu flat tet(s) in the recovered mesh", flat);
      return false;
    }
    // adjacencies through the sorted facets
    struct facetKey {
      pdel3d::vIdx a, b, c;
      pdel3d::tRef ref;
    };
    std::vector<facetKey> facets(4 * ntet);
    for(std::size_t t = 0; t < ntet; t++) {
      for(unsigned f = 0; f < 4; f++) {
        pdel3d::vIdx a = m.node[4 * t + pdel3d::facetNode0(f)],
                     b = m.node[4 * t + pdel3d::facetNode1(f)],
                     c = m.node[4 * t + pdel3d::facetNode2(f)];
        if(a > b) std::swap(a, b);
        if(b > c) std::swap(b, c);
        if(a > b) std::swap(a, b);
        facets[4 * t + f] = {a, b, c, (pdel3d::tRef)(4 * t + f)};
      }
    }
    std::sort(facets.begin(), facets.end(),
              [](const facetKey &x, const facetKey &y) {
                if(x.a != y.a) return x.a < y.a;
                if(x.b != y.b) return x.b < y.b;
                return x.c < y.c;
              });
    std::vector<pdel3d::tRef> hull;
    for(std::size_t i = 0; i < facets.size();) {
      if(i + 1 < facets.size() && facets[i].a == facets[i + 1].a &&
         facets[i].b == facets[i + 1].b && facets[i].c == facets[i + 1].c) {
        m.neigh[facets[i].ref] = facets[i + 1].ref;
        m.neigh[facets[i + 1].ref] = facets[i].ref;
        i += 2;
      }
      else {
        hull.push_back(facets[i].ref);
        i++;
      }
    }
    // a ghost tet on each hull facet, connected to its neighbors through the
    // hull edges
    struct edgeKey {
      pdel3d::vIdx a, b;
      pdel3d::tRef ref;
    };
    std::vector<edgeKey> edges;
    edges.reserve(3 * hull.size());
    for(auto r : hull) {
      const pdel3d::tIdx t = r >> 2, g = (pdel3d::tIdx)m.ntet++;
      const unsigned f = r & 3;
      const pdel3d::vIdx *tn = &m.node[4 * t];
      // ballNodes order: (vta, b0, b1, b2) is a valid tet when vta is on the
      // side of the tet, so (b0, b1, b2, GHOST) is a valid ghost
      static const unsigned ballNodes[4][3] = {
        {1, 2, 3}, {2, 0, 3}, {0, 1, 3}, {1, 0, 2}};
      pdel3d::vIdx *gn = &m.node[4 * g];
      gn[0] = tn[ballNodes[f][0]];
      gn[1] = tn[ballNodes[f][1]];
      gn[2] = tn[ballNodes[f][2]];
      gn[3] = pdel3d::GHOST;
      m.flag[g] = 0;
      m.neigh[4 * g + 3] = r;
      m.neigh[r] = 4 * g + 3;
      // facet k of the ghost (k < 3) is opposite gn[k]: it holds the edge of
      // the two other hull nodes
      for(unsigned k = 0; k < 3; k++) {
        pdel3d::vIdx a = gn[(k + 1) % 3], b = gn[(k + 2) % 3];
        if(a > b) std::swap(a, b);
        edges.push_back({a, b, (pdel3d::tRef)(4 * g + k)});
      }
    }
    std::sort(edges.begin(), edges.end(),
              [](const edgeKey &x, const edgeKey &y) {
                if(x.a != y.a) return x.a < y.a;
                return x.b < y.b;
              });
    for(std::size_t i = 0; i + 1 < edges.size(); i += 2) {
      if(edges[i].a != edges[i + 1].a || edges[i].b != edges[i + 1].b) {
        Msg::Error("Hull edge without two hull facets in the recovered mesh");
        return false;
      }
      m.neigh[edges[i].ref] = edges[i + 1].ref;
      m.neigh[edges[i + 1].ref] = edges[i].ref;
    }
    m.color.assign(m.tetCapacity(), pdel3d::Mesh::COLOR_OUT);
    if(Msg::GetVerbosity() > 5) m.verify(false);
    return true;
  }

  // give the mesh to the regions: the new vertices (in the volume of the
  // tets referencing them) and the tets, created in parallel with explicit
  // numbers (the counters of the model are atomic)
  std::size_t exportMesh(pdel3d::Mesh &m, SurfaceMesh &s,
                         std::vector<GRegion *> &regions, int nthreads)
  {
    std::vector<pdel3d::vIdx> newIndex;
    m.removeUnusedVertices(newIndex, nthreads);
    const std::size_t nv = m.numVertices(), nr = regions.size();
    std::vector<MVertex *> c2v(nv, nullptr);
    std::size_t numOld = 0;
    // the Steiner points of the recovery inside the volumes, classified on
    // regions[0]: they go to the region of their tets like the new vertices,
    // or are deleted when no tet of the volumes uses them
    std::vector<std::uint8_t> inVolume(nv, 0);
    std::vector<MVertex *> &steiner = regions[0]->mesh_vertices;
    for(std::size_t v = 0; v < s.vertices.size(); v++) {
      const bool volume = s.vertices[v]->onWhat() == regions[0];
      if(newIndex[v] == pdel3d::GHOST) {
        if(volume) {
          steiner.erase(
            std::find(steiner.begin(), steiner.end(), s.vertices[v]));
          delete s.vertices[v];
          s.vertices[v] = nullptr;
        }
        continue;
      }
      c2v[newIndex[v]] = s.vertices[v];
      inVolume[newIndex[v]] = volume;
      numOld++;
    }
    const std::size_t firstNew = numOld;
    GModel *model = regions[0]->model();
    const std::size_t baseV = model->getMaxVertexNumber(),
                      baseE = model->getMaxElementNumber();
    const int nt = std::max(1, nthreads);
    // the region of each new or Steiner vertex (any tet referencing it; nr:
    // none)
    std::vector<std::uint32_t> owner(nv, (std::uint32_t)nr);
    std::vector<std::size_t> chunkTets(nt + 1, 0);
#pragma omp parallel for schedule(static) num_threads(nt)
    for(int c = 0; c < nt; c++) {
      std::size_t count = 0;
      for(std::size_t t = c * m.ntet / nt; t < (c + 1) * m.ntet / nt; t++) {
        if(m.isGhost((pdel3d::tIdx)t) || m.color[t] >= nr) continue;
        count++;
        for(int k = 0; k < 4; k++) {
          const pdel3d::vIdx v = m.node[4 * t + k];
          if(v >= firstNew || inVolume[v]) owner[v] = m.color[t];
        }
      }
      chunkTets[c + 1] = count;
    }
    for(int c = 0; c < nt; c++) chunkTets[c + 1] += chunkTets[c];
    const std::size_t total = chunkTets[nt];
    std::vector<std::vector<std::vector<MVertex *>>> localVertices(
      nt, std::vector<std::vector<MVertex *>>(nr));
    std::vector<std::vector<std::vector<MTetrahedron *>>> localTets(
      nt, std::vector<std::vector<MTetrahedron *>>(nr));
#pragma omp parallel num_threads(nt)
    {
#pragma omp for schedule(static)
      for(int c = 0; c < nt; c++) {
        for(std::size_t v = firstNew + c * (nv - firstNew) / nt;
            v < firstNew + (c + 1) * (nv - firstNew) / nt; v++) {
          if(owner[v] == nr) continue;
          GRegion *gr = regions[owner[v]];
          const double *x = &m.xyz[4 * v];
          c2v[v] = new MVertex(x[0], x[1], x[2], gr, baseV + 1 + v - firstNew);
          localVertices[c][owner[v]].push_back(c2v[v]);
        }
      }
#pragma omp for schedule(static)
      for(int c = 0; c < nt; c++) {
        std::size_t rank = chunkTets[c];
        for(std::size_t t = c * m.ntet / nt; t < (c + 1) * m.ntet / nt; t++) {
          if(m.isGhost((pdel3d::tIdx)t) || m.color[t] >= nr) continue;
          const pdel3d::vIdx *n = &m.node[4 * t];
          localTets[c][m.color[t]].push_back(
            new MTetrahedron(c2v[n[0]], c2v[n[1]], c2v[n[2]], c2v[n[3]],
                             (int)(baseE + 1 + rank++)));
        }
      }
    }
    model->setMaxVertexNumber(baseV + nv - firstNew);
    model->setMaxElementNumber(baseE + total);
    for(std::size_t v = 0; v < firstNew; v++) {
      if(!inVolume[v] || !owner[v]) continue;
      steiner.erase(std::find(steiner.begin(), steiner.end(), c2v[v]));
      if(owner[v] == nr) {
        delete c2v[v];
        continue;
      }
      c2v[v]->setEntity(regions[owner[v]]);
      regions[owner[v]]->mesh_vertices.push_back(c2v[v]);
    }
    for(std::size_t r = 0; r < nr; r++) {
      std::size_t numV = 0, numT = 0;
      for(int c = 0; c < nt; c++) {
        numV += localVertices[c][r].size();
        numT += localTets[c][r].size();
      }
      GRegion *gr = regions[r];
      gr->mesh_vertices.reserve(gr->mesh_vertices.size() + numV);
      gr->tetrahedra.reserve(gr->tetrahedra.size() + numT);
      for(int c = 0; c < nt; c++) {
        gr->mesh_vertices.insert(gr->mesh_vertices.end(),
                                 localVertices[c][r].begin(),
                                 localVertices[c][r].end());
        gr->tetrahedra.insert(gr->tetrahedra.end(), localTets[c][r].begin(),
                              localTets[c][r].end());
      }
    }
    return total;
  }

  // Local boundary recovery with TetGen: the tets around the triangles and
  // lines still missing (the stars of their nodes, the tets they cross, two
  // layers around) are handed to TetGen's recovery, cavity by cavity, in its
  // non-convex mode, with the surface triangles and lines inside them and
  // the facets of their boundary as constraints, and the result is stitched
  // back, Steiner points included (the split surface triangles and lines
  // replace the originals). Returns false when a cavity could not be
  // recovered or stitched; the mesh is then left as it was
  bool recoverWithLocalTetGen(pdel3d::Mesh &m, SurfaceMesh &s,
                              std::vector<GRegion *> &regions,
                              const std::vector<pdel3d::tRef> &tri2tet,
                              const std::vector<std::uint64_t> &line2tet,
                              const std::vector<std::uint8_t> &lineInTriangle,
                              int nthreads)
  {
    using namespace pdel3d;
    const double t0 = TimeOfDay();
    const std::size_t nt = s.triNode.size() / 3, nl = s.lineNode.size() / 2;
    std::vector<std::size_t> missingTri, missingLine;
    for(std::size_t i = 0; i < nt; i++)
      if(tri2tet[i] == NO_ADJ) missingTri.push_back(i);
    for(std::size_t i = 0; i < nl; i++)
      if(!lineInTriangle[i] && line2tet[i] == NO_LINE) missingLine.push_back(i);
    if(missingTri.empty() && missingLine.empty()) return true;

    // a tet around every node involved
    Recovery R(m);
    const std::size_t nv = m.numVertices();
    std::vector<std::uint8_t> needed(nv, 0);
    for(auto i : missingTri)
      for(int k = 0; k < 3; k++) needed[s.triNode[3 * i + k]] = 1;
    for(auto i : missingLine)
      for(int k = 0; k < 2; k++) needed[s.lineNode[2 * i + k]] = 1;
    R.findStars(needed, nthreads);

    // the cavity: a tet intersects a triangle when one of its edges pierces
    // it or an edge of the triangle crosses one of its facets
    const double tStart = TimeOfDay();
    std::vector<std::uint8_t> inCavity(m.ntet, 0);
    std::vector<tIdx> cavity;
    auto add = [&](tIdx t) {
      if(t == NO_TET || m.isDeleted(t) || m.isGhost(t) || inCavity[t]) return;
      inCavity[t] = 1;
      cavity.push_back(t);
    };
    // the segment (x, y) meets the facet (u, v, w), touching included: the
    // cavity must hold every tet the missing items pass through
    auto meets = [](const double *x, const double *y, const double *u,
                    const double *v, const double *w) {
      const double sx = orient3dFast(u, v, w, x), sy = orient3dFast(u, v, w, y);
      if(sx * sy > 0.) return false;
      const double s0 = orient3dFast(x, y, u, v), s1 = orient3dFast(x, y, v, w),
                   s2 = orient3dFast(x, y, w, u);
      return (s0 >= 0. && s1 >= 0. && s2 >= 0.) ||
             (s0 <= 0. && s1 <= 0. && s2 <= 0.);
    };
    auto intersects = [&](tIdx t, const double *a, const double *b,
                          const double *c, const vIdx *tri) {
      const vIdx *n = &m.node[4 * t];
      for(unsigned i = 0; i < 4; i++)
        for(unsigned j = i + 1; j < 4; j++) {
          if(n[i] == tri[0] || n[i] == tri[1] || n[i] == tri[2] ||
             n[j] == tri[0] || n[j] == tri[1] || n[j] == tri[2])
            continue;
          if(meets(&m.xyz[4 * n[i]], &m.xyz[4 * n[j]], a, b, c)) return true;
        }
      const double *tp[3] = {a, b, c};
      for(unsigned f = 0; f < 4; f++) {
        const vIdx u = n[facetNode0(f)], v = n[facetNode1(f)],
                   w = n[facetNode2(f)];
        for(int e = 0; e < 3; e++) {
          const vIdx x = tri[e], y = tri[(e + 1) % 3];
          if(x == u || x == v || x == w || y == u || y == v || y == w) continue;
          if(meets(tp[e], tp[(e + 1) % 3], &m.xyz[4 * u], &m.xyz[4 * v],
                   &m.xyz[4 * w]))
            return true;
        }
      }
      return false;
    };
    auto crossedTets = [&](vIdx x, vIdx y) {
      // the tets crossed by the segment (x, y), from the star of x
      const double *px = &m.xyz[4 * x], *py = &m.xyz[4 * y];
      R.star(x, R.scratch);
      tIdx cur = NO_TET;
      unsigned entering = 4;
      for(auto t : R.scratch) {
        add(t);
        const vIdx *n = &m.node[4 * t];
        if(m.isGhost(t)) continue;
        unsigned ix = 0;
        while(n[ix] != x) ix++;
        const vIdx u = n[facetNode0(ix)], v = n[facetNode1(ix)],
                   w = n[facetNode2(ix)];
        if(R.segmentCrossesFacet(px, py, &m.xyz[4 * u], &m.xyz[4 * v],
                                 &m.xyz[4 * w])) {
          const tRef r = m.neigh[4 * t + ix];
          cur = r >> 2;
          entering = r & 3;
        }
      }
      for(int step = 0; step < 1000 && cur != NO_TET; step++) {
        if(m.isGhost(cur)) break;
        add(cur);
        const vIdx *n = &m.node[4 * cur];
        if(n[0] == y || n[1] == y || n[2] == y || n[3] == y) break;
        unsigned exitF = 4;
        for(unsigned f = 0; f < 4 && exitF == 4; f++) {
          if(f == entering) continue;
          const vIdx u = n[facetNode0(f)], v = n[facetNode1(f)],
                     w = n[facetNode2(f)];
          if(R.segmentCrossesFacet(px, py, &m.xyz[4 * u], &m.xyz[4 * v],
                                   &m.xyz[4 * w]))
            exitF = f;
        }
        if(exitF == 4) break;
        const tRef r = m.neigh[4 * cur + exitF];
        cur = r >> 2;
        entering = r & 3;
      }
    };
    for(auto i : missingTri) {
      const vIdx *tri = &s.triNode[3 * i];
      const double *a = &m.xyz[4 * tri[0]], *b = &m.xyz[4 * tri[1]],
                   *c = &m.xyz[4 * tri[2]];
      const std::size_t first = cavity.size();
      for(int k = 0; k < 3; k++) {
        R.star(tri[k], R.scratch);
        for(auto t : R.scratch) add(t);
        crossedTets(tri[k], tri[(k + 1) % 3]);
      }
      // grow through the tets intersecting the triangle
      for(std::size_t j = first; j < cavity.size(); j++) {
        for(unsigned f = 0; f < 4; f++) {
          const tIdx nb = m.neigh[4 * cavity[j] + f] >> 2;
          if(m.isGhost(nb) || inCavity[nb]) continue;
          if(intersects(nb, a, b, c, tri)) add(nb);
        }
      }
    }
    for(auto i : missingLine) {
      const vIdx x = s.lineNode[2 * i], y = s.lineNode[2 * i + 1];
      R.star(y, R.scratch);
      for(auto t : R.scratch) add(t);
      crossedTets(x, y);
    }
    const std::size_t sizeIntersecting = cavity.size();
    // two layers around: room for the flips of the recovery, which must not
    // reach the boundary of the cavity
    for(int layer = 0; layer < 2; layer++) {
      const std::size_t n0 = cavity.size();
      for(std::size_t j = 0; j < n0; j++)
        for(unsigned f = 0; f < 4; f++) add(m.neigh[4 * cavity[j] + f] >> 2);
    }
    const std::size_t sizeLayer = cavity.size();
    // a cavity holding a sizable part of the mesh costs as much as the global
    // recovery, and is more likely to fail: leave it to the global one
    auto tooLarge = [&]() {
      return cavity.size() > 10000 && cavity.size() > m.ntet / 4;
    };
    // a line on the boundary of the cavity could be split by a Steiner
    // point, which the stitching cannot follow: the rings of tets around the
    // lines join the cavity, to a fixpoint (the tets added are examined in
    // turn)
    std::set<std::uint64_t> lineEdges;
    for(std::size_t i = 0; i < nl; i++)
      lineEdges.insert(R.edgeKey(s.lineNode[2 * i], s.lineNode[2 * i + 1]));
    auto addRing = [&](tIdx t, vIdx x, vIdx y) {
      tIdx cur = t;
      vIdx prev = GHOST;
      for(unsigned k = 0; k < 4; k++) {
        const vIdx v = m.node[4 * t + k];
        if(v != x && v != y) {
          prev = v;
          break;
        }
      }
      for(int step = 0; step < 64; step++) {
        add(cur);
        const vIdx *n = &m.node[4 * cur];
        vIdx other = GHOST;
        unsigned fPrev = 4;
        for(unsigned k = 0; k < 4; k++) {
          if(n[k] == prev)
            fPrev = k;
          else if(n[k] != x && n[k] != y)
            other = n[k];
        }
        if(fPrev == 4) break;
        const tRef r = m.neigh[4 * cur + fPrev];
        if(r == NO_ADJ || (r >> 2) == t) break;
        prev = other;
        cur = r >> 2;
      }
    };
    if(!lineEdges.empty())
      for(std::size_t j = 0; j < cavity.size() && !tooLarge(); j++) {
        const tIdx t = cavity[j];
        for(int e = 0; e < 6; e++) {
          unsigned n0, n1;
          edgeNodes(e, n0, n1);
          const vIdx x = m.node[4 * t + n0], y = m.node[4 * t + n1];
          if(lineEdges.count(R.edgeKey(x, y))) addRing(t, x, y);
        }
      }
    if(Msg::GetVerbosity() > 5)
      Msg::Info("  cavity: %lu tets intersecting the missing items, %lu with a "
                "layer, %lu with the rings (%g s)",
                sizeIntersecting, sizeLayer, cavity.size(),
                TimeOfDay() - tStart);
    if(tooLarge()) {
      Msg::Info("Cavity recovery: the cavity is too large (%lu tets)",
                cavity.size());
      return false;
    }
    // connected components
    std::vector<std::uint32_t> component(m.ntet, 0);
    std::vector<std::vector<tIdx>> components;
    for(auto t : cavity) {
      if(component[t]) continue;
      components.emplace_back();
      std::vector<tIdx> &comp = components.back();
      comp.push_back(t);
      component[t] = (std::uint32_t)components.size();
      for(std::size_t j = 0; j < comp.size(); j++)
        for(unsigned f = 0; f < 4; f++) {
          const tIdx nb = m.neigh[4 * comp[j] + f] >> 2;
          if(inCavity[nb] && !component[nb]) {
            component[nb] = (std::uint32_t)components.size();
            comp.push_back(nb);
          }
        }
    }

    std::map<std::uint32_t, GFace *> faceOfTag;
    for(GFace *gf : s.surfaces) faceOfTag[gf->tag()] = gf;
    std::map<std::uint32_t, GEdge *> curveOfTag;
    for(GEdge *ge : s.curves) curveOfTag[ge->tag()] = ge;

    // TetGen is given the tets of each cavity as they are (its non-convex
    // mode: the walks may leave the mesh, the constraints present are bonded
    // beforehand), with the surface triangles and lines in it and the facets
    // of its boundary as constraints: TetGen expects the boundary of a
    // non-convex mesh to be made of constraints, which it never flips, so
    // that the result fits in place of the old tets. Every cavity is
    // recovered and validated before anything is modified: the fallback to
    // the global recovery must find the mesh untouched
    struct Pending {
      std::vector<tIdx> *comp;
      std::vector<vIdx> global; // local -> global vertex
      std::vector<std::size_t> cavityTri, cavityLine;
      boundaryRecoveryOutput out;
      std::vector<std::uint32_t> newNode; // local vertex indices, oriented
      std::vector<tRef> newNeigh; // refs: local (4 * t + f) or outer
      std::vector<std::uint8_t> outer;
      std::vector<std::pair<tRef, tRef>> outerLinks; // (outer ref, local ref)
    };
    std::vector<Pending> pending(components.size());
    std::size_t numCavityTets = 0;
    const int BOUNDARY_TAG = -2; // the facets of the cavity boundary
    for(std::size_t c = 0; c < components.size(); c++) {
      std::vector<tIdx> &comp = components[c];
      Pending &P = pending[c];
      P.comp = &comp;
      numCavityTets += comp.size();
      // local numbering of the vertices; localTet: 1 + the position of a tet
      // in this component, 0 otherwise
      std::map<vIdx, std::uint32_t> local;
      std::vector<vIdx> &global = P.global;
      auto localOf = [&](vIdx v) {
        auto it = local.find(v);
        if(it != local.end()) return it->second;
        const std::uint32_t l = (std::uint32_t)global.size();
        local[v] = l;
        global.push_back(v);
        return l;
      };
      // (the component ids are not needed anymore: the array is reused,
      // cleared component by component rather than in full each time)
      std::vector<std::uint32_t> &localTet = component;
      if(c == 0)
        std::fill(localTet.begin(), localTet.end(), 0);
      else
        for(tIdx t : components[c - 1]) localTet[t] = 0;
      for(std::size_t j = 0; j < comp.size(); j++) {
        localTet[comp[j]] = (std::uint32_t)j + 1;
        for(unsigned k = 0; k < 4; k++) localOf(m.node[4 * comp[j] + k]);
      }
      auto inComponent = [&](vIdx v) { return local.count(v) > 0; };
      const std::size_t nloc = global.size();
      boundaryRecoveryInput in;
      in.carve = false; // everything is kept
      in.postprocess = false;
      in.verbose = false;
      in.nonconvex = true;
      // the facets of flat tets on the boundary overlap exactly: no error
      in.overlapAngleTolerance = 0.;
      in.xyz.resize(3 * nloc);
      for(std::size_t v = 0; v < nloc; v++)
        for(int k = 0; k < 3; k++) in.xyz[3 * v + k] = m.xyz[4 * global[v] + k];
      for(std::size_t j = 0; j < comp.size(); j++)
        for(unsigned k = 0; k < 4; k++) {
          in.tetNode.push_back(local[m.node[4 * comp[j] + k]]);
          const tIdx nb = m.neigh[4 * comp[j] + k] >> 2;
          in.tetNeighbors.push_back(
            localTet[nb] ? (std::int64_t)localTet[nb] - 1 : -1);
        }
      // the constraints: the surface triangles and lines in the cavity,
      // present (a tet of theirs is in it) or missing (their nodes are in it)
      auto sorted3 = [](vIdx a, vIdx b, vIdx c) {
        std::array<vIdx, 3> k = {a, b, c};
        std::sort(k.begin(), k.end());
        return k;
      };
      std::set<std::array<vIdx, 3>> surfaceFacets;
      for(std::size_t i = 0; i < nt; i++) {
        const vIdx *n = &s.triNode[3 * i];
        bool take = false;
        if(tri2tet[i] != NO_ADJ)
          take = localTet[tri2tet[i] >> 2] != 0 ||
                 localTet[m.neigh[tri2tet[i]] >> 2] != 0;
        else
          take = inComponent(n[0]) && inComponent(n[1]) && inComponent(n[2]);
        if(!take) continue;
        P.cavityTri.push_back(i);
        for(int k = 0; k < 3; k++) in.triNode.push_back(local[n[k]]);
        in.triTag.push_back((int)s.triColor[i]);
        std::int64_t tet = -1;
        if(tri2tet[i] != NO_ADJ) {
          const tIdx t0 = tri2tet[i] >> 2, t1 = m.neigh[tri2tet[i]] >> 2;
          tet = localTet[t0] ? (std::int64_t)localTet[t0] - 1 :
                               (std::int64_t)localTet[t1] - 1;
        }
        in.triTet.push_back(tet);
        surfaceFacets.insert(sorted3(n[0], n[1], n[2]));
      }
      for(std::size_t i = 0; i < nl; i++) {
        if(lineInTriangle[i]) continue;
        const vIdx *n = &s.lineNode[2 * i];
        bool take = false;
        // (the ring of a present line is in the cavity or out of it)
        if(line2tet[i] != NO_LINE)
          take = localTet[(tIdx)(line2tet[i] / 6)] != 0;
        else
          take = inComponent(n[0]) && inComponent(n[1]);
        if(!take) continue;
        P.cavityLine.push_back(i);
        for(int k = 0; k < 2; k++) in.segNode.push_back(local[n[k]]);
        in.segTag.push_back((int)s.lineColor[i]);
      }
      // the boundary facets of the cavity: constraints (TetGen must know
      // the boundary of a non-convex mesh) with a tag of their own, and the
      // keys for the stitching
      struct facetKey {
        std::uint32_t v0, v1, v2; // sorted
        tRef ref;
      };
      auto key = [](std::uint32_t x, std::uint32_t y, std::uint32_t z, tRef r) {
        facetKey k{x, y, z, r};
        if(k.v0 > k.v1) std::swap(k.v0, k.v1);
        if(k.v1 > k.v2) std::swap(k.v1, k.v2);
        if(k.v0 > k.v1) std::swap(k.v0, k.v1);
        return k;
      };
      auto less = [](const facetKey &a, const facetKey &b) {
        if(a.v0 != b.v0) return a.v0 < b.v0;
        if(a.v1 != b.v1) return a.v1 < b.v1;
        return a.v2 < b.v2;
      };
      auto same = [](const facetKey &a, const facetKey &b) {
        return a.v0 == b.v0 && a.v1 == b.v1 && a.v2 == b.v2;
      };
      std::vector<facetKey> boundary;
      for(std::size_t j = 0; j < comp.size(); j++) {
        const tIdx t = comp[j];
        for(unsigned f = 0; f < 4; f++) {
          const tRef r = m.neigh[4 * t + f];
          if(localTet[r >> 2]) continue;
          const vIdx a = m.node[4 * t + facetNode0(f)],
                     b = m.node[4 * t + facetNode1(f)],
                     c = m.node[4 * t + facetNode2(f)];
          boundary.push_back(key(local[a], local[b], local[c], r));
          if(surfaceFacets.count(sorted3(a, b, c))) continue;
          in.triNode.push_back(local[a]);
          in.triNode.push_back(local[b]);
          in.triNode.push_back(local[c]);
          in.triTag.push_back(BOUNDARY_TAG);
          in.triTet.push_back((std::int64_t)j);
        }
      }
      boundaryRecoveryOutput &out = P.out;
      const int err = meshGRegionBoundaryRecoveryFlat(in, out);
      if(err) {
        Msg::Info("Cavity recovery failed (error %d) on a cavity of %lu tets",
                  err, comp.size());
        return false;
      }
      for(auto tag : out.changedFaces)
        if(faceOfTag.count(tag) && !faceOfTag[tag]->quadrangles.empty()) {
          Msg::Info("Cavity recovery: Steiner point on a surface with "
                    "quadrangles");
          return false;
        }
      for(auto tag : out.changedFaces)
        if(!faceOfTag.count(tag)) {
          if(tag == BOUNDARY_TAG)
            Msg::Info("Cavity recovery: Steiner point on the cavity boundary");
          else
            Msg::Info("Cavity recovery: Steiner point on an unknown surface %d",
                      tag);
          return false;
        }
      for(auto tag : out.changedEdges)
        if(tag >= 0 && !curveOfTag.count(tag)) {
          Msg::Info("Cavity recovery: Steiner point on an unknown curve %d",
                    tag);
          return false;
        }
      // the new tets, oriented like ours (exactly: flat tets are common in a
      // planar region); the Steiner points follow the cavity vertices
      const std::size_t nnew = out.tetNode.size() / 4;
      auto coord = [&](std::uint32_t l) -> const double * {
        if(l < nloc) return &m.xyz[4 * global[l]];
        return &out.steinerXYZ[3 * (l - nloc)];
      };
      std::vector<std::uint32_t> &newNode = P.newNode;
      newNode = out.tetNode;
      for(std::size_t t = 0; t < nnew; t++) {
        std::uint32_t *n = &newNode[4 * t];
        const double o = robustPredicates::orient3d(coord(n[0]), coord(n[1]),
                                                    coord(n[2]), coord(n[3]));
        if(o == 0.) {
          Msg::Info("Cavity recovery gave a flat tet");
          return false;
        }
        if(o > 0.) std::swap(n[0], n[1]);
      }
      // the stitching: every boundary facet matches a facet of a new tet,
      // the other facets of the new tets match among themselves
      std::vector<facetKey> inner;
      for(std::size_t t = 0; t < nnew; t++)
        for(unsigned f = 0; f < 4; f++)
          inner.push_back(
            key(newNode[4 * t + facetNode0(f)], newNode[4 * t + facetNode1(f)],
                newNode[4 * t + facetNode2(f)], (tRef)(4 * t + f)));
      std::sort(boundary.begin(), boundary.end(), less);
      std::sort(inner.begin(), inner.end(), less);
      P.newNeigh.assign(4 * nnew, NO_ADJ);
      P.outer.assign(4 * nnew, 0);
      {
        std::size_t j = 0;
        for(std::size_t i = 0; i < boundary.size(); i++) {
          while(j < inner.size() && less(inner[j], boundary[i])) j++;
          if(j >= inner.size() || !same(boundary[i], inner[j])) {
            Msg::Info("Cavity recovery changed the cavity boundary");
            return false;
          }
          P.newNeigh[inner[j].ref] = boundary[i].ref;
          P.outer[inner[j].ref] = 1;
          P.outerLinks.push_back({boundary[i].ref, inner[j].ref});
          j++;
        }
        for(std::size_t i = 0; i + 1 < inner.size(); i++) {
          if(P.newNeigh[inner[i].ref] != NO_ADJ) continue;
          if(same(inner[i], inner[i + 1]) &&
             P.newNeigh[inner[i + 1].ref] == NO_ADJ) {
            P.newNeigh[inner[i].ref] = inner[i + 1].ref;
            P.newNeigh[inner[i + 1].ref] = inner[i].ref;
            i++;
          }
        }
        for(auto r : P.newNeigh)
          if(r == NO_ADJ) {
            Msg::Info("Cavity recovery: the cavity is not closed");
            return false;
          }
      }
      // every constraint must be in the new tets: the triangles and lines of
      // the cavity, or those replacing them on the surfaces and curves split
      // by Steiner points
      {
        auto hasFacet = [&](std::uint32_t a, std::uint32_t b, std::uint32_t c) {
          return std::binary_search(inner.begin(), inner.end(), key(a, b, c, 0),
                                    less);
        };
        std::vector<std::uint64_t> edges;
        edges.reserve(6 * nnew);
        for(std::size_t t = 0; t < nnew; t++)
          for(unsigned a = 0; a < 3; a++)
            for(unsigned b = a + 1; b < 4; b++)
              edges.push_back(
                Recovery::edgeKey(newNode[4 * t + a], newNode[4 * t + b]));
        std::sort(edges.begin(), edges.end());
        auto hasEdge = [&](std::uint32_t a, std::uint32_t b) {
          return std::binary_search(edges.begin(), edges.end(),
                                    Recovery::edgeKey(a, b));
        };
        std::size_t lost = 0;
        for(auto i : P.cavityTri) {
          const vIdx *n = &s.triNode[3 * i];
          if(!out.changedFaces.count((int)s.triColor[i]) &&
             !hasFacet(local[n[0]], local[n[1]], local[n[2]]))
            lost++;
        }
        for(std::size_t i = 0; i < out.triTag.size(); i++) {
          const std::uint32_t *n = &out.triNode[3 * i];
          if(out.changedFaces.count(out.triTag[i]) &&
             !hasFacet(n[0], n[1], n[2]))
            lost++;
        }
        for(auto i : P.cavityLine) {
          const vIdx *n = &s.lineNode[2 * i];
          if(!out.changedEdges.count((int)s.lineColor[i]) &&
             !hasEdge(local[n[0]], local[n[1]]))
            lost++;
        }
        for(std::size_t i = 0; i < out.segTag.size(); i++) {
          const std::uint32_t *n = &out.segNode[2 * i];
          if(out.changedEdges.count(out.segTag[i]) && !hasEdge(n[0], n[1]))
            lost++;
        }
        if(lost) {
          Msg::Info("Cavity recovery left %lu constraint(s) missing", lost);
          return false;
        }
      }
    }

    // every missing triangle and line must be in a cavity (one whose nodes are
    // spread over two cavities is in neither): the mesh must stay untouched
    // otherwise, for the fallback
    {
      std::vector<std::uint8_t> triIn(nt, 0), lineIn(nl, 0);
      for(const Pending &P : pending) {
        for(auto i : P.cavityTri) triIn[i] = 1;
        for(auto i : P.cavityLine) lineIn[i] = 1;
      }
      std::size_t left = 0;
      for(auto i : missingTri) left += !triIn[i];
      for(auto i : missingLine) left += !lineIn[i];
      if(left) {
        Msg::Info("Cavity recovery: %lu missing item(s) in no cavity", left);
        return false;
      }
    }

    // commit
    std::size_t steiner = 0;
    std::vector<std::uint8_t> triRemoved(nt, 0), lineRemoved(nl, 0);
    for(Pending &P : pending) {
      const std::vector<tIdx> &comp = *P.comp;
      const std::vector<vIdx> &global = P.global;
      const boundaryRecoveryOutput &out = P.out;
      const std::size_t nnew = P.newNode.size() / 4;
      const std::size_t numSteiner = out.steinerXYZ.size() / 3;
      // the Steiner points: mesh vertices of their curve, surface or region,
      // with the mean size of the cavity
      double meanSize = 0.;
      {
        std::size_t count = 0;
        for(auto v : global)
          if(m.xyz[4 * v + 3] > 0.) {
            meanSize += m.xyz[4 * v + 3];
            count++;
          }
        meanSize = count ? meanSize / count : 0.;
      }
      std::vector<vIdx> newGlobal(global);
      for(std::size_t k = 0; k < numSteiner; k++) {
        const double *x = &out.steinerXYZ[3 * k];
        MVertex *v = nullptr;
        GEdge *ge = nullptr;
        GFace *gf = nullptr;
        if(out.steinerType[k] == 1) {
          auto it = curveOfTag.find(out.steinerSegTag[k]);
          if(it != curveOfTag.end())
            ge = it->second;
          else if(out.steinerFaceTag[k] >= 0) {
            auto jt = faceOfTag.find(out.steinerFaceTag[k]);
            if(jt != faceOfTag.end()) gf = jt->second;
          }
        }
        else if(out.steinerType[k] == 2) {
          auto jt = faceOfTag.find(out.steinerFaceTag[k]);
          if(jt != faceOfTag.end()) gf = jt->second;
        }
        if(ge) {
          MEdgeVertex *ev = new MEdgeVertex(x[0], x[1], x[2], ge, 0);
          double uu = 0;
          if(reparamMeshVertexOnEdge(ev, ge, uu)) ev->setParameter(0, uu);
          ge->mesh_vertices.push_back(ev);
          v = ev;
        }
        else if(gf) {
          MFaceVertex *fv = new MFaceVertex(x[0], x[1], x[2], gf, 0, 0);
          SPoint2 param;
          if(reparamMeshVertexOnFace(fv, gf, param)) {
            fv->setParameter(0, param.x());
            fv->setParameter(1, param.y());
          }
          gf->mesh_vertices.push_back(fv);
          v = fv;
        }
        else {
          v = new MVertex(x[0], x[1], x[2], regions[0]);
          regions[0]->mesh_vertices.push_back(v);
        }
        const vIdx index = (vIdx)m.numVertices();
        v->setIndex((long)index);
        s.vertices.push_back(v);
        m.xyz.insert(m.xyz.end(), {x[0], x[1], x[2], meanSize});
        newGlobal.push_back(index);
        steiner++;
      }
      // the new tets, then the old ones go
      m.reserveTets(m.ntet + nnew + 1024);
      const tIdx base = (tIdx)m.ntet;
      for(std::size_t t = 0; t < nnew; t++) {
        const tIdx id = (tIdx)m.ntet++;
        for(int k = 0; k < 4; k++) {
          m.node[4 * id + k] = newGlobal[P.newNode[4 * t + k]];
          const tRef r = P.newNeigh[4 * t + k];
          m.neigh[4 * id + k] = P.outer[4 * t + k] ? r : r + 4 * base;
        }
        m.flag[id] = 0;
        if(!m.color.empty()) m.color[id] = Mesh::COLOR_OUT;
      }
      for(auto &l : P.outerLinks) m.neigh[l.first] = l.second + 4 * base;
      for(auto t : comp) {
        m.flag[t] |= F_DELETED;
        for(int k = 0; k < 4; k++) m.neigh[4 * t + k] = NO_ADJ;
      }
      // the surface meshes with Steiner points: the triangles and lines
      // passed with that tag are replaced by TetGen's
      for(auto tag : out.changedFaces) {
        GFace *gf = faceOfTag[tag];
        std::set<MTriangle *> gone;
        for(auto i : P.cavityTri)
          if(s.triColor[i] == (std::uint32_t)tag) {
            triRemoved[i] = 1;
            gone.insert(s.triElem[i]);
          }
        std::vector<MTriangle *> kept;
        for(MTriangle *t : gf->triangles) {
          if(gone.count(t))
            delete t;
          else
            kept.push_back(t);
        }
        gf->triangles.swap(kept);
        gf->deleteVertexArrays();
        for(std::size_t i = 0; i < out.triTag.size(); i++) {
          if(out.triTag[i] != tag) continue;
          vIdx n[3];
          for(int k = 0; k < 3; k++) n[k] = newGlobal[out.triNode[3 * i + k]];
          MTriangle *t =
            new MTriangle(s.vertices[n[0]], s.vertices[n[1]], s.vertices[n[2]]);
          gf->triangles.push_back(t);
          for(int k = 0; k < 3; k++) s.triNode.push_back(n[k]);
          s.triColor.push_back(tag);
          s.triElem.push_back(t);
          triRemoved.push_back(0);
        }
      }
      for(auto tag : out.changedEdges) {
        if(tag < 0) continue;
        GEdge *ge = curveOfTag[tag];
        std::set<MLine *> gone;
        for(auto i : P.cavityLine)
          if(s.lineColor[i] == (std::uint32_t)tag) {
            lineRemoved[i] = 1;
            gone.insert(s.lineElem[i]);
          }
        std::vector<MLine *> kept;
        for(MLine *l : ge->lines) {
          if(gone.count(l))
            delete l;
          else
            kept.push_back(l);
        }
        ge->lines.swap(kept);
        ge->deleteVertexArrays();
        for(std::size_t i = 0; i < out.segTag.size(); i++) {
          if(out.segTag[i] != tag) continue;
          vIdx n[2];
          for(int k = 0; k < 2; k++) n[k] = newGlobal[out.segNode[2 * i + k]];
          MLine *l = new MLine(s.vertices[n[0]], s.vertices[n[1]]);
          ge->lines.push_back(l);
          for(int k = 0; k < 2; k++) s.lineNode.push_back(n[k]);
          s.lineColor.push_back(tag);
          s.lineElem.push_back(l);
          lineRemoved.push_back(0);
        }
      }
    }
    // drop the replaced triangles and lines from the surface mesh (the caller
    // maps them to the tets again)
    auto compact = [](auto &nodes, int per, auto &colors, auto &elems,
                      const std::vector<std::uint8_t> &removed) {
      std::size_t n = 0;
      for(std::size_t i = 0; i < removed.size(); i++) {
        if(removed[i]) continue;
        for(int k = 0; k < per; k++) nodes[per * n + k] = nodes[per * i + k];
        colors[n] = colors[i];
        elems[n] = elems[i];
        n++;
      }
      nodes.resize(per * n);
      colors.resize(n);
      elems.resize(n);
    };
    compact(s.triNode, 3, s.triColor, s.triElem, triRemoved);
    compact(s.lineNode, 2, s.lineColor, s.lineElem, lineRemoved);
    m.removeDeleted(nthreads);
    Msg::Info("Boundary recovery on cavities: %lu cavit%s of %lu tets in "
              "all, %lu Steiner point%s (Wall %gs)",
              components.size(), components.size() > 1 ? "ies" : "y",
              numCavityTets, steiner, steiner > 1 ? "s" : "", TimeOfDay() - t0);
    return true;
  }

} // namespace

static int meshRegions(std::vector<GRegion *> &regions, splitQuadRecovery &sqr)
{
  const double t0 = TimeOfDay();
  const int nthreads = numThreads3D();
  const int verbosity = Msg::GetVerbosity() > 5 ? 2 : 1;
  SurfaceMesh s;
  if(!collectSurfaceMesh(regions, s, sqr)) return 2;
  // As del3d, work on coordinates perturbed by up to Mesh.RandomFactor3D times
  // the size of the model, restored when the mesh is handed back (the
  // optimization has removed the tets thin enough to be inverted by that).
  // Measured on benchmarks/3d (October 2026), without the perturbation:
  // - the nodes of curved CAD surfaces are cospherical to rounding, those of
  //   planar faces coplanar, which sends the predicates of the initial
  //   tetrahedralization to the exact arithmetic (3-5x slower on fil, crux,
  //   percolation);
  // - the degenerate Delaunay misses more surface triangles: the recovery is
  //   up to 8x slower (geom8du, vulp5) and falls back to the global one on
  //   vulp5 and core_coil;
  // - the refinement can be faster, though (U_Joint_2.stp, clscale 0.02).
  // The exact coordinates cannot be restored before the refinement: the
  // recovered mesh then holds thousands of flat and hundreds of inverted
  // tets, which only the optimization removes. Doing without the perturbation
  // would need a symbolic perturbation of the predicates of the kernel and of
  // the recovery.
  perturbedCoordinates perturbation(s.vertices,
                                    CTX::instance()->mesh.randFactor3d);
  pdel3d::Mesh m;
  const std::size_t nv = s.vertices.size();
  const double sizeFactor = CTX::instance()->mesh.lcFactor;
  setVertices(s, m, sizeFactor);

  // the Delaunay tetrahedralization of the surface vertices
  Msg::Info("Tetrahedrizing %lu nodes...", nv);
  m.reserveTets(10 * nv + 16384);
  m.color.resize(m.tetCapacity(), pdel3d::Mesh::COLOR_OUT);
  {
    std::vector<pdel3d::vIdx> toInsert(nv);
    std::iota(toInsert.begin(), toInsert.end(), 0);
    std::vector<std::uint8_t> status;
    pdel3d::DelaunayOptions opt;
    opt.numThreads = nthreads;
    opt.verbosity = verbosity;
    opt.reorderVertices = true;
    pdel3d::insertVertices(m, opt, toInsert, status);
    // renumber the surface mesh after the reordering
    std::vector<pdel3d::vIdx> inverse(nv);
    for(std::size_t i = 0; i < nv; i++) inverse[toInsert[i]] = (pdel3d::vIdx)i;
    std::vector<MVertex *> vertices(nv);
    for(std::size_t i = 0; i < nv; i++) {
      vertices[i] = s.vertices[toInsert[i]];
      vertices[i]->setIndex((long)i);
    }
    s.vertices.swap(vertices);
    for(auto &v : s.triNode) v = inverse[v];
    for(auto &v : s.lineNode) v = inverse[v];
    std::size_t notInserted = 0;
    for(std::size_t i = 0; i < nv; i++)
      if(status[i] != pdel3d::ST_INSERTED) notInserted++;
    if(notInserted) {
      Msg::Warning("%lu surface node(s) could not be inserted", notInserted);
      if(Msg::GetVerbosity() > 5) m.verify(true);
      return 2;
    }
  }
  const double t1 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %lu nodes (Wall %gs)", nv, t1 - t0);

  // the surface mesh must be in the tetrahedralization
  std::vector<pdel3d::tRef> tri2tet;
  std::size_t missing = pdel3d::triangleToTetMap(m, s.triNode, tri2tet);
  std::vector<std::uint8_t> lineInTriangle;
  pdel3d::linesInTriangles(s.triNode, s.lineNode, lineInTriangle);
  std::vector<std::uint64_t> line2tet;
  std::size_t missingLines =
    pdel3d::lineToTetMap(m, s.lineNode, lineInTriangle, line2tet);
  const bool recovered = missing || missingLines;
  if(recovered) {
    Msg::Info("Recovering %lu missing triangle(s) and %lu missing line(s)...",
              missing, missingLines);
    // by local edge removals first, then TetGen on the cavities around what
    // is left; the global TetGen recovery of the untouched Delaunay is the
    // fallback
    const std::vector<pdel3d::vIdx> node0(m.node.begin(),
                                          m.node.begin() + 4 * m.ntet);
    const std::vector<pdel3d::tRef> neigh0(m.neigh.begin(),
                                           m.neigh.begin() + 4 * m.ntet);
    const std::vector<std::uint16_t> flag0(m.flag.begin(),
                                           m.flag.begin() + m.ntet);
    const std::size_t ntet0 = m.ntet, nv0 = m.numVertices();
    // the maps after each stage: the edge removals and the cavities move
    // the triangles and lines to other tets
    auto remap = [&]() {
      missing = pdel3d::triangleToTetMap(m, s.triNode, tri2tet);
      pdel3d::linesInTriangles(s.triNode, s.lineNode, lineInTriangle);
      missingLines =
        pdel3d::lineToTetMap(m, s.lineNode, lineInTriangle, line2tet);
    };
    bool local = true;
    pdel3d::recoverLocally(m, s.triNode, s.lineNode, lineInTriangle, tri2tet,
                           line2tet, nthreads, verbosity);
    if(Msg::GetVerbosity() > 5) m.verify(false);
    remap();
    if(missing || missingLines) {
      local = recoverWithLocalTetGen(m, s, regions, tri2tet, line2tet,
                                     lineInTriangle, nthreads);
      if(local) {
        remap();
        local = !missing && !missingLines;
        if(!local)
          Msg::Info("Local boundary recovery incomplete (%lu triangle(s) and "
                    "%lu line(s) missing): falling back to the global one",
                    missing, missingLines);
      }
    }
    if(!local) {
      // from the Delaunay before the local recovery, unless the cavities
      // added Steiner points to the surface mesh, which that tetrahedralization
      // does not have: then from the current one
      if(m.numVertices() == nv0) {
        std::copy(node0.begin(), node0.end(), m.node.begin());
        std::copy(neigh0.begin(), neigh0.end(), m.neigh.begin());
        std::copy(flag0.begin(), flag0.end(), m.flag.begin());
        m.ntet = ntet0;
      }
      else
        Msg::Warning("Falling back to the global boundary recovery after a "
                     "partial local one");
      if(!recoverBoundary(m, s, regions, sqr, sizeFactor)) {
        Msg::Error("Boundary recovery failed");
        return 1;
      }
      remap();
    }
    if(missing || missingLines) {
      Msg::Error(
        "%lu triangle(s) and %lu line(s) still missing after boundary recovery",
        missing, missingLines);
      return 1;
    }
  }
  pdel3d::constrainFacets(m, tri2tet);
  pdel3d::constrainEdges(m, line2tet);
  if(!pdel3d::colorVolumes(m, tri2tet, s.triColor, s.volumes, s.siblings,
                           s.embedded))
    return 1;
  if(Msg::GetVerbosity() > 5) m.verify(!recovered);
  const double t2 = TimeOfDay();
  Msg::Info("Done recovering the boundary (Wall %gs)", t2 - t1);

  // refinement
  const std::size_t numFixed = m.numVertices();
  {
    pdel3d::RefineOptions opt;
    opt.numThreads = nthreads;
    opt.numVolumes = (std::uint32_t)regions.size();
    opt.sizeMin = CTX::instance()->mesh.lcMin;
    opt.sizeMax = CTX::instance()->mesh.lcMax;
    opt.sizeFactor = sizeFactor;
    SizeData sd = {&regions, nthreads, false};
    opt.sizeCallback = sizeCallback;
    opt.sizeData = &sd;
    opt.verbosity = verbosity;
    pdel3d::refine(m, opt);
    if(sd.failed) {
      Msg::Error("Mesh size evaluation failed");
      return 1;
    }
  }
  double t3 = TimeOfDay();
  Msg::Info("Done refining (Wall %gs)", t3 - t2);
  if(Msg::GetVerbosity() > 5) m.verify(false);
  if(CTX::instance()->mesh.optimize > 0 &&
     CTX::instance()->mesh.optimizeThreshold > 0.) {
    Msg::Info("Optimizing mesh...");
    pdel3d::OptimizeOptions opt;
    opt.numThreads = nthreads;
    opt.numVolumes = (std::uint32_t)regions.size();
    opt.numFixedVertices = numFixed;
    opt.qualityMin = CTX::instance()->mesh.optimizeThreshold;
    opt.sprQualityFactor = CTX::instance()->mesh.optimizeReconnectionThreshold;
    opt.sprMaxPoints = CTX::instance()->mesh.optimizeReconnectionPoints;
    opt.sprMaxSearchNodes = CTX::instance()->mesh.optimizeReconnectionSearch;
    opt.verbosity = verbosity;
    pdel3d::optimize(m, opt);
    if(Msg::GetVerbosity() > 5) m.verify(false);
    Msg::Info("Done optimizing mesh (Wall %gs)", TimeOfDay() - t3);
    t3 = TimeOfDay();
  }

  const std::size_t numTets = exportMesh(m, s, regions, nthreads);
  Msg::Info("Done exporting %lu tets (Wall %gs)", numTets, TimeOfDay() - t3);
  // the pyramids on the quadrangles, as in del3d: on the exact coordinates
  // (the apexes are moved into the volume, which the restoration would undo)
  perturbation.restore();
  const int nHybrid = sqr.buildPyramids(regions[0]->model());
  if(nHybrid && sqr.doWeCreatePyramids()) {
    regions[0]->model()->setAllVolumesPositive();
    RelocateVerticesOfPyramids(regions, 3);
  }
  return 0;
}

int meshGRegionParallelDelaunay(std::vector<GRegion *> &regions)
{
  if(regions.empty()) return 0;
  splitQuadRecovery sqr(CTX::instance()->mesh.optimizePyramids >= -2);
  int ret;
  try {
    ret = meshRegions(regions, sqr);
  } catch(std::length_error &e) {
    Msg::Error("%s", e.what());
    ret = 1;
  }
  // the pyramid apexes only go to the volumes on success
  if(ret)
    for(auto &q : sqr.getQuad()) delete q.second;
  return ret;
}
