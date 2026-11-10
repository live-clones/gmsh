#include "hxt_combine_cpp_api.h"

#include <cassert>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include "tet_mesh.h"
#include "basic_types.h"
#include "hxt_combine_cell.h"
#include "candidate_cell.h"
#include "algorithms.h"
#include "combine_quality.h"
#include "compute_candidate_cells.h"

#include "hxt_omp.h"
#include <cstdint>

/**
* \author Jeanne Pellerin
*/

namespace HXTCombine {

class StoreCandidateCells{
public:
  // the cells found are appended to cells by flush
  StoreCandidateCells(const TetMeshForCombining& tetMesh, double minQuality, HXTCombineCellArray& cells) :
    tets_(tetMesh), qualityThreshold_(minQuality), cells_(cells),
    buffers_(omp_get_max_threads())
  {
    // No reservation: the number of cells depends on the cell types, on the
    // tet mesh and on the min quality, and the former guess of 20 cells per
    // vertex, constructed upfront, took 26 GB for 9 million vertices
    // whatever the min quality
  }

  void operator()(const vector<VertexIndex>& vertices)
  {
    double quality = cellQuality(tets_, vertices);
    if (quality > qualityThreshold_ && isCellReallyValid(tets_, vertices)){
      CandidateCell cell(vertices, tets_);
      if (cell.checkTetsTopology() && cell.haveTetsSameColor() && cell.checkQuadFacetColor() && cell.checkQuadFacetBoundary())
        cell.appendTo(buffers_[omp_get_thread_num()]);
    }
  }
  // For these pyramids..
  void operator()(const vector<VertexIndex>& vertices, TetIndex t0)
  {
    double quality = cellQuality(tets_, vertices);
    if (quality > qualityThreshold_ && isCellReallyValid(tets_, vertices)) {
      CandidateCell cell(vertices, t0, tets_);
      if (cell.checkTetsTopology() && cell.haveTetsSameColor() && cell.checkQuadFacetColor() && cell.checkQuadFacetBoundary())
        cell.appendTo(buffers_[omp_get_thread_num()]);
    }
  }

  /**
   * Appends the cells of all threads.
   *
   * Must always be called once all cells have been found.
   */
  void flush() {
    std::size_t nbCells = cells_.size(), nbIndices = cells_.nbIndices();
    for (const auto& b : buffers_) {
      nbCells += b.size();
      nbIndices += b.nbIndices();
    }
    cells_.reserve(nbCells, nbIndices);
    for (auto& b : buffers_) {
      cells_.append(b);
      HXTCombineCellArray().swap(b);
    }
  }

private:
  const TetMeshForCombining& tets_;
  const double qualityThreshold_;
  HXTCombineCellArray& cells_;
  std::vector<HXTCombineCellArray> buffers_;
};

namespace {

  // the n vertices of vs nearest to p, NO_ID if fewer
  template <unsigned int N>
  void nearestVertices(const TetMeshForCombining& M, const VertexRange& vs,
                       const vec3& p, unsigned int n, VertexIndex (&best)[N])
  {
    double d2[N];
    for (unsigned int i = 0; i < n; ++i) best[i] = NO_ID;
    for (VertexIndex v : vs) {
      double d = M.point(v).distance2(p);
      unsigned int i = n;
      while (i > 0 && (best[i - 1] == NO_ID || d < d2[i - 1])) {
        if (i < n) {
          best[i] = best[i - 1];
          d2[i] = d2[i - 1];
        }
        --i;
      }
      if (i < n) {
        best[i] = v;
        d2[i] = d;
      }
    }
  }

  // the vertex of vs nearest to p, NO_ID if none
  template <class Accept>
  VertexIndex nearestVertex(const TetMeshForCombining& M,
                            const VertexRange& vs, const vec3& p,
                            const Accept& accept)
  {
    VertexIndex best = NO_ID;
    double d2 = 0.;
    for (VertexIndex v : vs) {
      if (!accept(v)) continue;
      double d = M.point(v).distance2(p);
      if (best == NO_ID || d < d2) {
        best = v;
        d2 = d;
      }
    }
    return best;
  }

  // the vertex of the intersection of the sorted (decreasing) lists first,
  // others[0..nbOthers), not in excluded, nearest to p, in the order of first;
  // NO_ID if none
  VertexIndex nearestCommonVertex(const TetMeshForCombining& M, const VertexRange& first,
                                  const VertexRange* others, unsigned int nbOthers,
                                  const VertexIndex* excluded, unsigned int nbExcluded,
                                  const vec3& p)
  {
    const VertexIndex* at[2] = {nbOthers > 0 ? others[0].begin() : nullptr,
                                nbOthers > 1 ? others[1].begin() : nullptr};
    VertexIndex best = NO_ID;
    double d2 = 0.;
    for (VertexIndex x : first) {
      bool common = true;
      for (unsigned int k = 0; k < nbOthers && common; ++k) {
        while (at[k] != others[k].end() && *at[k] > x) ++at[k];
        common = at[k] != others[k].end() && *at[k] == x;
      }
      if (!common) continue;
      bool out = false;
      for (unsigned int k = 0; k < nbExcluded; ++k) out = out || x == excluded[k];
      if (out) continue;
      const double d = M.point(x).distance2(p);
      if (best == NO_ID || d < d2) {
        best = x;
        d2 = d;
      }
    }
    return best;
  }

  bool areNeighbors(const TetMeshForCombining& M, VertexIndex u, VertexIndex v)
  {
    const VertexRange around = M.verticesAroundVertices(u);
    return std::binary_search(around.begin(), around.end(), v,
                              std::greater<VertexIndex>());
  }

  // Proposals: (sorted vertices, labelling). Keeps one labelling, the
  // smallest, of each set of vertices.
  template <class Proposals>
  void keepSmallestLabellings(Proposals& proposals)
  {
    std::sort(proposals.begin(), proposals.end());
    proposals.erase(std::unique(proposals.begin(), proposals.end(),
                                [](const auto& x, const auto& y) { return x.first == y.first; }),
                    proposals.end());
  }

  // A cell is proposed from several of its corners, mostly by the same
  // thread: each thread compacts its proposals as they come, then all of
  // them together. Same cells as one pass over all the proposals, in the
  // memory of the cells.
  template <class Proposals>
  struct ProposalsByThread {
    explicit ProposalsByThread(int nbThreads) : lists(nbThreads), limits(nbThreads, 1 << 16) {}
    template <class Proposal>
    void add(int thread, const Proposal& p)
    {
      lists[thread].push_back(p);
      if (lists[thread].size() >= limits[thread]) {
        keepSmallestLabellings(lists[thread]);
        limits[thread] = std::max(limits[thread], 2 * lists[thread].size());
      }
    }
    Proposals gather()
    {
      std::size_t n = 0;
#pragma omp parallel for schedule(dynamic, 1) reduction(+ : n)
      for (int t = 0; t < (int)lists.size(); ++t) {
        keepSmallestLabellings(lists[t]);
        n += lists[t].size();
      }
      // The sorted lists cut by the same keys into slices, each slice of
      // all of them gathered and sorted by one thread, in the place of the
      // slice in the result
      const std::size_t nbSlices = 4 * lists.size();
      const Proposals* longest = &lists[0];
      for (const auto& l : lists)
        if (l.size() > longest->size()) longest = &l;
      std::vector<typename Proposals::value_type> cuts;
      for (std::size_t k = 1; k < nbSlices && !longest->empty(); ++k)
        cuts.push_back((*longest)[k * longest->size() / nbSlices]);
      const std::size_t nbCuts = cuts.size();
      // where slice k of list l begins: begins[l][k], k = 0 .. nbCuts + 1
      std::vector<std::vector<std::size_t> > begins(lists.size());
      for (std::size_t l = 0; l < lists.size(); ++l) {
        begins[l].push_back(0);
        for (const auto& cut : cuts)
          begins[l].push_back(std::lower_bound(lists[l].begin(), lists[l].end(), cut) -
                              lists[l].begin());
        begins[l].push_back(lists[l].size());
      }
      std::vector<std::size_t> offset(nbCuts + 2, 0);
      for (std::size_t k = 0; k <= nbCuts; ++k) {
        offset[k + 1] = offset[k];
        for (std::size_t l = 0; l < lists.size(); ++l)
          offset[k + 1] += begins[l][k + 1] - begins[l][k];
      }
      Proposals all(n);
#pragma omp parallel for schedule(dynamic, 1)
      for (int k = 0; k <= (int)nbCuts; ++k) {
        auto out = all.begin() + offset[k];
        for (std::size_t l = 0; l < lists.size(); ++l)
          out = std::copy(lists[l].begin() + begins[l][k], lists[l].begin() + begins[l][k + 1], out);
        std::sort(all.begin() + offset[k], all.begin() + offset[k + 1]);
      }
      for (auto& l : lists) Proposals().swap(l);
      all.erase(std::unique(all.begin(), all.end(),
                            [](const auto& x, const auto& y) { return x.first == y.first; }),
                all.end());
      return all;
    }
    std::vector<Proposals> lists;
    std::vector<std::size_t> limits;
  };

  // A set of hexes (by a key of 8 vertices) shared by the threads
  // The vertices along a Morton curve, for the threads to visit them by
  // blocks of neighbours
  std::vector<VertexIndex> spatialOrder(const TetMeshForCombining& M)
  {
    const VertexIndex n = M.nbVertices();
    vec3 lo = M.point(0), hi = lo;
    for (VertexIndex v = 1; v < n; ++v)
      for (int k = 0; k < 3; ++k) {
        lo[k] = std::min(lo[k], M.point(v)[k]);
        hi[k] = std::max(hi[k], M.point(v)[k]);
      }
    auto spread = [](std::uint64_t x) {
      x &= 0x1fffff;
      x = (x | x << 32) & 0x1f00000000ffffull;
      x = (x | x << 16) & 0x1f0000ff0000ffull;
      x = (x | x << 8) & 0x100f00f00f00f00full;
      x = (x | x << 4) & 0x10c30c30c30c30c3ull;
      x = (x | x << 2) & 0x1249249249249249ull;
      return x;
    };
    std::vector<std::pair<std::uint64_t, VertexIndex> > keys(n);
#pragma omp parallel for schedule(static)
    for (int i = 0; i < (int)n; ++i) {
      std::uint64_t code = 0;
      for (int k = 0; k < 3; ++k) {
        const double t = hi[k] > lo[k] ? (M.point(i)[k] - lo[k]) / (hi[k] - lo[k]) : 0.;
        code |= spread((std::uint64_t)(t * 2097151.)) << k;
      }
      keys[i] = std::make_pair(code, (VertexIndex)i);
    }
    std::sort(keys.begin(), keys.end());
    std::vector<VertexIndex> order(n);
    for (VertexIndex i = 0; i < n; ++i) order[i] = keys[i].second;
    return order;
  }

  // The hexes a thread accepted lately, in an open addressing table emptied
  // when half full: a hex is found from its corners, close along the Morton
  // curve, mostly by the thread that found it first, which skips it then. Without locks, and what the
  // other threads accept is proposed again, removed when they are gathered.
  class RecentHexes {
  public:
    typedef std::array<VertexIndex, 8> Hex8;
    RecentHexes() : slots_(capacity), used_(capacity, 0) {}
    bool contains(const Hex8& h) const
    {
      for (std::size_t i = hash(h);; i = (i + 1) & (capacity - 1)) {
        if (!used_[i]) return false;
        if (slots_[i] == h) return true;
      }
    }
    void insert(const Hex8& h)
    {
      if (2 * size_ >= capacity) {
        std::fill(used_.begin(), used_.end(), 0);
        size_ = 0;
      }
      std::size_t i = hash(h);
      while (used_[i]) {
        if (slots_[i] == h) return;
        i = (i + 1) & (capacity - 1);
      }
      slots_[i] = h;
      used_[i] = 1;
      ++size_;
    }

  private:
    static constexpr std::size_t capacity = 1 << 17;
    static std::size_t hash(const Hex8& h)
    {
      std::uint64_t x = 1469598103934665603ull;
      for (VertexIndex v : h) x = (x ^ v) * 1099511628211ull;
      return (std::size_t)(x ^ (x >> 29)) & (capacity - 1);
    }
    std::vector<Hex8> slots_;
    std::vector<unsigned char> used_;
    std::size_t size_ = 0;
  };

  // The symmetries of the cube on the labellings of a hex (a, b, c, d at the
  // bottom, e, f, g, h above them): the labelling s(h)[i] = h[s[i]], indexed
  // by s[0], s[1] (a neighbour of s[0]) and s[3] (another one), which
  // determine it, with whether it is a rotation (24) or a reflection (24)
  struct HexSymmetries {
    unsigned char perm[8][8][8][8];
    bool rotation[8][8][8];
    bool exists[8][8][8];
    HexSymmetries()
    {
      static const unsigned char rotations[24][8] = {
        {0, 1, 2, 3, 4, 5, 6, 7}, {0, 3, 7, 4, 1, 2, 6, 5}, {0, 4, 5, 1, 3, 7, 6, 2},
        {1, 0, 4, 5, 2, 3, 7, 6}, {1, 2, 3, 0, 5, 6, 7, 4}, {1, 5, 6, 2, 0, 4, 7, 3},
        {2, 1, 5, 6, 3, 0, 4, 7}, {2, 3, 0, 1, 6, 7, 4, 5}, {2, 6, 7, 3, 1, 5, 4, 0},
        {3, 0, 1, 2, 7, 4, 5, 6}, {3, 2, 6, 7, 0, 1, 5, 4}, {3, 7, 4, 0, 2, 6, 5, 1},
        {4, 0, 3, 7, 5, 1, 2, 6}, {4, 5, 1, 0, 7, 6, 2, 3}, {4, 7, 6, 5, 0, 3, 2, 1},
        {5, 1, 0, 4, 6, 2, 3, 7}, {5, 4, 7, 6, 1, 0, 3, 2}, {5, 6, 2, 1, 4, 7, 3, 0},
        {6, 2, 1, 5, 7, 3, 0, 4}, {6, 5, 4, 7, 2, 1, 0, 3}, {6, 7, 3, 2, 5, 4, 0, 1},
        {7, 3, 2, 6, 4, 0, 1, 5}, {7, 4, 0, 3, 6, 5, 1, 2}, {7, 6, 5, 4, 3, 2, 1, 0}};
      static const unsigned char mirror[8] = {0, 3, 2, 1, 4, 7, 6, 5};
      for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
          for (int k = 0; k < 8; ++k) exists[i][j][k] = false;
      for (const auto& r : rotations) {
        for (int m = 0; m < 2; ++m) {
          unsigned char s[8];
          for (int i = 0; i < 8; ++i) s[i] = m ? r[mirror[i]] : r[i];
          std::copy(s, s + 8, perm[s[0]][s[1]][s[3]]);
          rotation[s[0]][s[1]][s[3]] = !m;
          exists[s[0]][s[1]][s[3]] = true;
        }
      }
    }
  };
  const HexSymmetries& hexSymmetries()
  {
    static const HexSymmetries symmetries;
    return symmetries;
  }

  // the positions of the smallest vertex of a labelling and of its neighbours
  // by increasing vertex
  void smallestCorner(const std::array<VertexIndex, 8>& h, int& i0, int n[3])
  {
    static const int neighbours[8][3] = {{1, 3, 4}, {0, 2, 5}, {1, 3, 6}, {0, 2, 7},
                                         {0, 5, 7}, {1, 4, 6}, {2, 5, 7}, {3, 4, 6}};
    i0 = (int)(std::min_element(h.begin(), h.end()) - h.begin());
    std::copy(neighbours[i0], neighbours[i0] + 3, n);
    std::sort(n, n + 3, [&h](int x, int y) { return h[x] < h[y]; });
  }
  std::array<VertexIndex, 8> applySymmetry(const std::array<VertexIndex, 8>& h,
                                           const unsigned char* s)
  {
    std::array<VertexIndex, 8> c;
    for (int i = 0; i < 8; ++i) c[i] = h[s[i]];
    return c;
  }

  // the smallest of the 24 labellings of a hex given by the rotations of the
  // cube (the smallest vertex first, then its smallest neighbour): the
  // labelling of a hex whatever the corner it is found from
  std::array<VertexIndex, 8> canonicalHex(const std::array<VertexIndex, 8>& h)
  {
    const HexSymmetries& S = hexSymmetries();
    int i0, n[3];
    smallestCorner(h, i0, n);
    const int third = S.exists[i0][n[0]][n[1]] && S.rotation[i0][n[0]][n[1]] ? n[1] : n[2];
    return applySymmetry(h, S.perm[i0][n[0]][third]);
  }

  // the same over the mirror labellings too: the hex itself, whatever its
  // orientation (8 vertices may form several hexes)
  std::array<VertexIndex, 8> hexKey(const std::array<VertexIndex, 8>& h)
  {
    const HexSymmetries& S = hexSymmetries();
    int i0, n[3];
    smallestCorner(h, i0, n);
    return applySymmetry(h, S.perm[i0][n[0]][n[1]]);
  }

  // the quality and validity tests of a prism (a,b,c,d,e,f) on its corners
  bool passesPrismTests(const TetMeshForCombining& M,
                        const std::array<VertexIndex, 6>& v, double minQ)
  {
    const VertexIndex a = v[0], b = v[1], c = v[2], d = v[3], e = v[4], f = v[5];
    return !(M.triangleCornerQuality(a, b, c) < minQ) &&
           M.isTriangleFacet(a, b, c) &&
           M.prismCornerQuality(a, b, c, d) >= minQ &&
           M.prismCornerQuality(b, c, a, e) >= minQ &&
           M.isTriangulatedQuad(a, b, e, d) &&
           M.prismCornerQuality(c, a, b, f) >= minQ &&
           M.prismCornerQuality(d, f, e, a) >= minQ &&
           M.prismCornerQuality(f, e, d, c) >= minQ &&
           M.prismCornerQuality(e, d, f, b) >= minQ &&
           M.isTriangleFacet(d, e, f) &&
           M.isTriangulatedQuad(b, c, f, e) &&
           M.isTriangulatedQuad(a, c, f, d);
  }

}

/**
* From each facet (a,b,c) of a free tet, the prisms standing on it along
* the axes of the frame of a nearly normal to it: d the neighbour of a
* nearest to a + h u, e and f the common neighbours nearest to b + d - a
* and c + d - a. A prism made of free tets has a facet of a free tet for
* each of its triangles.
*/
void HXTCombineCellStore::computeGuidedPrisms(double minQuality,
                                              const std::vector<double>& frames,
                                              const std::vector<double>& sizes,
                                              const std::vector<bool>& freeTets)
{
  const TetMeshForCombining& M = mesh_;
  std::vector<trindex> facets;
  // the vertices of the free tets: the corners of a prism made of free tets
  std::vector<char> freeVertex(M.nbVertices(), 0);
  for (TetIndex t = 0; t < M.nbTets(); ++t)
    if (freeTets[t]) {
      for (TetFacetIndex f = 0; f < 4; ++f) facets.push_back(M.tetFacet(t, f));
      for (TetVertexIndex i = 0; i < 4; ++i) freeVertex[M.vertex(t, i)] = 1;
    }
  std::sort(facets.begin(), facets.end());
  facets.erase(std::unique(facets.begin(), facets.end()), facets.end());

  typedef std::array<VertexIndex, 6> Prism6;
  ProposalsByThread<std::vector<std::pair<Prism6, Prism6> > > found(omp_get_max_threads());
#pragma omp parallel for schedule(dynamic, 256)
  for (int i = 0; i < (int)facets.size(); ++i) {
    const int thread = omp_get_thread_num();
    for (int corner = 0; corner < 3; ++corner) {
      // stand on the facet from each of its framed vertices
      const VertexIndex a = facets[i].indices[corner],
                        b = facets[i].indices[(corner + 1) % 3],
                        c = facets[i].indices[(corner + 2) % 3];
      const double size = sizes[a];
      if (!(size > 0.)) continue;
      const vec3 pa = M.point(a), pb = M.point(b), pc = M.point(c);
      const vec3 ab = pb - pa, ac = pc - pa;
      vec3 n(ab[1] * ac[2] - ab[2] * ac[1], ab[2] * ac[0] - ab[0] * ac[2],
             ab[0] * ac[1] - ab[1] * ac[0]);
      const double ln = n.length();
      if (!(ln > 0.)) continue;
      n *= 1. / ln;
      for (int k = 0; k < 3; ++k) {
        const vec3 u(frames[9 * a + 3 * k], frames[9 * a + 3 * k + 1],
                     frames[9 * a + 3 * k + 2]);
        const double dn = u[0] * n[0] + u[1] * n[1] + u[2] * n[2];
        if (std::fabs(dn) < 0.5) continue;
        for (int s = -1; s <= 1; s += 2) {
          const VertexIndex d = nearestVertex(
            M, M.verticesAroundVertices(a), pa + u * (s * size),
            [&](VertexIndex x) { return x != b && x != c; });
          if (d == NO_ID || !freeVertex[d]) continue;
          const vec3 shift = M.point(d) - pa;
          const VertexIndex e = nearestVertex(
            M, M.verticesAroundVertices(b), pb + shift, [&](VertexIndex x) {
              return x != a && x != c && x != d && areNeighbors(M, d, x);
            });
          if (e == NO_ID || !freeVertex[e]) continue;
          const VertexIndex f = nearestVertex(
            M, M.verticesAroundVertices(c), pc + shift, [&](VertexIndex x) {
              return x != a && x != b && x != d && x != e &&
                     areNeighbors(M, d, x) && areNeighbors(M, e, x);
            });
          if (f == NO_ID || !freeVertex[f]) continue;
          std::array<VertexIndex, 6> prism = {{a, b, c, d, e, f}};
          if (!passesPrismTests(M, prism, minQuality)) {
            std::swap(prism[1], prism[2]);
            std::swap(prism[4], prism[5]);
            if (!passesPrismTests(M, prism, minQuality)) continue;
          }
          Prism6 sorted = prism;
          std::sort(sorted.begin(), sorted.end());
          found.add(thread, std::make_pair(sorted, prism));
        }
      }
    }
  }

  // a prism is found from up to its 6 corners
  std::vector<std::pair<Prism6, Prism6> > all = found.gather();

  // the cells in the order of their sorted vertices: each thread stores a
  // block of them, appended in the order of the threads
  HXTCombineCellArray cells;
  {
    StoreCandidateCells store(mesh_, minQuality, cells);
#pragma omp parallel for schedule(static)
    for (int i = 0; i < (int)all.size(); ++i)
      store(vector<VertexIndex>(all[i].second.begin(), all[i].second.end()));
    store.flush();
  }
  prisms().append(cells); // in the order of their sorted vertices
}

/**
* From each vertex a with a frame, one hex per octant of the frame: its
* neighbours b, d, e nearest to a + h s_k u_k, then c, f, h, g the common
* neighbours nearest to the parallelograms they span. On a point set laid
* along the frame, as the frontal filler's, these are nearly all the hexes
* the greedy selection keeps out of the exhaustive enumeration, for a
* handful of candidates per vertex instead of tens.
*/
void HXTCombineCellStore::computeGuidedHexes(double minQuality,
                                             const std::vector<double>& frames,
                                             const std::vector<double>& sizes,
                                             const std::vector<bool>* startVertices,
                                             unsigned int nbChoices,
                                             unsigned int nbChoicesProposed)
{
  const unsigned int maxChoices = 3;
  nbChoices = std::max(1u, std::min(nbChoices, maxChoices));
  const TetMeshForCombining& M = mesh_;
  const int nbThreads = omp_get_max_threads();
  typedef std::array<VertexIndex, 8> Hex8;
  ProposalsByThread<std::vector<std::pair<Hex8, Hex8> > > found(nbThreads);
  // the corners of a hex visited by the same thread, mostly
  const std::vector<VertexIndex> order = spatialOrder(M);
  std::vector<RecentHexes> recent(nbThreads);
#pragma omp parallel for schedule(dynamic, 4096)
  for (int a0 = 0; a0 < (int)order.size(); ++a0) {
    const VertexIndex a = order[a0];
    const double size = sizes[a];
    if (!(size > 0.)) continue;
    if (startVertices && !(*startVertices)[a]) continue;
    const int thread = omp_get_thread_num();
    const vec3 pa = M.point(a);
    const VertexRange aroundA = M.verticesAroundVertices(a);
    vec3 axis[3];
    for (int k = 0; k < 3; ++k)
      axis[k] = vec3(frames[9 * a + 3 * k], frames[9 * a + 3 * k + 1],
                     frames[9 * a + 3 * k + 2]);
    // With startVertices, the corners of a hex are start vertices: the
    // vertices of the free tets, as a cell made of free tets
    auto isStart = [&](VertexIndex v) {
      return v != NO_ID && (!startVertices || (*startVertices)[v]);
    };
    // the neighbours nearest to a + size * s * axis[k], for s = -1, 1
    VertexIndex along[3][2][maxChoices];
    for (int k = 0; k < 3; ++k)
      for (int s = 0; s < 2; ++s) {
        nearestVertices(M, aroundA, pa + axis[k] * (s ? size : -size), nbChoices,
                        along[k][s]);
        for (unsigned int c = 0; c < nbChoices; ++c)
          if (!isStart(along[k][s][c])) along[k][s][c] = NO_ID;
      }

    // The completion of the parallelogram (a, u, v) depends on u and v only:
    // once for each pair of sides and choices of the two axes, not for each
    // proposal. completions[k][l] for the axes k < l, at
    // [side k][side l][choice k][choice l].
    auto completion = [&](VertexIndex u, VertexIndex v) {
      if (u == NO_ID || v == NO_ID || u == v) return (VertexIndex)NO_ID;
      const vec3 p = M.point(u) + M.point(v) - pa;
      const VertexRange aroundV = M.verticesAroundVertices(v);
      const VertexIndex w =
        nearestCommonVertex(M, M.verticesAroundVertices(u), &aroundV, 1, &a, 1, p);
      return isStart(w) ? w : (VertexIndex)NO_ID;
    };
    VertexIndex completions[3][3][2][2][maxChoices][maxChoices];
    for (int k = 0; k < 3; ++k)
      for (int l = k + 1; l < 3; ++l)
        for (int sk = 0; sk < 2; ++sk)
          for (int sl = 0; sl < 2; ++sl)
            for (unsigned int ck = 0; ck < nbChoices; ++ck)
              for (unsigned int cl = 0; cl < nbChoices; ++cl)
                completions[k][l][sk][sl][ck][cl] =
                  completion(along[k][sk][ck], along[l][sl][cl]);

    // The quality tests of a hex (a,b,c,d,e,f,g,h) on its corners and faces:
    // those on the faces at a depend on 2 of b, d, e only (and on their
    // completion), once per pair, for the labelling (bit 0) and its mirror
    // (bit 1), swapping b and d, f and h; those at a on the combination;
    // those at g on the combination and g.
    auto qc = [&](VertexIndex x, VertexIndex y, VertexIndex z) {
      return M.quadCornerQuality(x, y, z) >= minQuality;
    };
    unsigned char faceTests[3][3][2][2][maxChoices][maxChoices];
    for (int k = 0; k < 3; ++k)
      for (int l = k + 1; l < 3; ++l)
        for (int sk = 0; sk < 2; ++sk)
          for (int sl = 0; sl < 2; ++sl)
            for (unsigned int ck = 0; ck < nbChoices; ++ck)
              for (unsigned int cl = 0; cl < nbChoices; ++cl) {
                const VertexIndex u = along[k][sk][ck], v = along[l][sl][cl],
                                  w = completions[k][l][sk][sl][ck][cl];
                unsigned char& tests = faceTests[k][l][sk][sl][ck][cl];
                tests = 0;
                if (w == NO_ID) continue;
                if (k == 0 && l == 1) { // (a, b, c, d): u = b, v = d, w = c
                  if (!qc(v, a, w) || !qc(u, a, w)) continue;
                  const bool asIs = qc(a, u, v) && qc(w, u, v);
                  const bool mirrored = qc(a, v, u) && qc(w, v, u);
                  if ((asIs || mirrored) && M.isTriangulatedQuad(a, u, w, v))
                    tests = asIs | (mirrored << 1);
                }
                else if (k == 0) { // (a, b, f, e): u = b, v = e, w = f; the left face of the mirror
                  if (qc(w, u, v) && M.isTriangulatedQuad(a, u, w, v))
                    tests = qc(v, a, w) | 2;
                }
                else { // (a, d, h, e): u = d, v = e, w = h; the front face of the mirror
                  if (qc(w, u, v) && M.isTriangulatedQuad(a, u, w, v))
                    tests = 1 | (qc(v, a, w) << 1);
                }
              }

    const unsigned int nbCombinations = nbChoices * nbChoices * nbChoices;
    for (unsigned int proposal = 0; proposal < 8 * nbCombinations; ++proposal) {
      const unsigned int octant = proposal % 8, choice = proposal / 8;
      const unsigned int sx = octant & 1, sy = (octant >> 1) & 1, sz = (octant >> 2) & 1;
      const unsigned int cx = choice % nbChoices, cy = (choice / nbChoices) % nbChoices,
                         cz = choice / (nbChoices * nbChoices);
      // already proposed with fewer choices
      if (cx < nbChoicesProposed && cy < nbChoicesProposed && cz < nbChoicesProposed)
        continue;
      const VertexIndex b = along[0][sx][cx], d = along[1][sy][cy], e = along[2][sz][cz];
      if (b == NO_ID || d == NO_ID || e == NO_ID || b == d || b == e || d == e)
        continue;
      const VertexIndex c = completions[0][1][sx][sy][cx][cy];
      const VertexIndex f = completions[0][2][sx][sz][cx][cz];
      const VertexIndex h = completions[1][2][sy][sz][cy][cz];
      if (c == NO_ID || f == NO_ID || h == NO_ID) continue;
      // the labellings passing the tests at a (what follows only depends on
      // the hex found)
      unsigned int labellings = faceTests[0][1][sx][sy][cx][cy] &
                                faceTests[0][2][sx][sz][cx][cz] &
                                faceTests[1][2][sy][sz][cy][cz];
      if ((labellings & 1) &&
          !(M.hexCornerQuality(a, b, d, e) >= minQuality &&
            M.hexCornerQuality(b, c, a, f) >= minQuality &&
            M.hexCornerQuality(d, a, c, h) >= minQuality &&
            M.hexCornerQuality(e, a, h, f) >= minQuality))
        labellings &= ~1u;
      if ((labellings & 2) &&
          !(M.hexCornerQuality(a, d, b, e) >= minQuality &&
            M.hexCornerQuality(d, c, a, h) >= minQuality &&
            M.hexCornerQuality(b, a, c, f) >= minQuality &&
            M.hexCornerQuality(e, a, f, h) >= minQuality))
        labellings &= ~2u;
      if (!labellings) continue;
      const vec3 pg = M.point(c) + M.point(f) + M.point(h) - M.point(b) -
                      M.point(d) - M.point(e) + pa;
      const VertexRange aroundFH[2] = {M.verticesAroundVertices(f), M.verticesAroundVertices(h)};
      const VertexIndex bde[3] = {b, d, e};
      const VertexIndex g = nearestCommonVertex(M, M.verticesAroundVertices(c), aroundFH, 2,
                                                bde, 3, pg);
      if (!isStart(g)) continue;
      Hex8 hex = {{a, b, c, d, e, f, g, h}};
      Hex8 sorted = hex;
      std::sort(sorted.begin(), sorted.end());
      if (std::adjacent_find(sorted.begin(), sorted.end()) != sorted.end())
        continue;
      // already accepted from another corner (the tests at a differ from a
      // corner to the other: a hex is kept if it passes them from one)
      const Hex8 key = hexKey(hex);
      if (recent[thread].contains(key)) continue;
      // the tests at g, the 3 opposite faces shared by both labellings; the
      // octant may be left-handed: then the mirrored labelling
      auto cornersAtG = [&](VertexIndex b, VertexIndex d, VertexIndex f, VertexIndex h) {
        return M.hexCornerQuality(g, f, h, c) >= minQuality &&
               M.hexCornerQuality(f, e, g, b) >= minQuality &&
               M.hexCornerQuality(h, g, e, d) >= minQuality &&
               M.hexCornerQuality(c, b, g, d) >= minQuality;
      };
      if ((labellings & 1) && !cornersAtG(b, d, f, h)) labellings &= ~1u;
      if ((labellings & 2) && !cornersAtG(d, b, h, f)) labellings &= ~2u;
      if (!labellings || !M.isTriangulatedQuad(d, c, g, h) ||
          !M.isTriangulatedQuad(e, f, g, h) || !M.isTriangulatedQuad(b, c, g, f))
        continue;
      if (!(labellings & 1)) {
        std::swap(hex[1], hex[3]);
        std::swap(hex[5], hex[7]);
      }
      // once, in a labelling independent of the corner (and of the thread);
      // of the hexes on the same 8 vertices, the one of smallest labelling is
      // kept below
      recent[thread].insert(key);
      found.add(thread, std::make_pair(sorted, canonicalHex(hex)));
    }
  }

  // in the order of their sorted vertices
  std::vector<std::pair<Hex8, Hex8> > all = found.gather();
  // nor the hexes already there
  if (!hexes().empty()) {
    std::vector<Hex8> known(hexes().size());
#pragma omp parallel for
    for (int i = 0; i < (int)hexes().size(); ++i) {
      std::copy(hexes()[i].vertexes, hexes()[i].vertexes + 8, known[i].begin());
      std::sort(known[i].begin(), known[i].end());
    }
    std::sort(known.begin(), known.end());
    all.erase(std::remove_if(all.begin(), all.end(), [&](const auto& x) {
                return std::binary_search(known.begin(), known.end(), x.first);
              }),
              all.end());
  }

  // the cells in the order of their sorted vertices: each thread stores a
  // block of them, appended in the order of the threads
  HXTCombineCellArray cells;
  {
    StoreCandidateCells store(mesh_, minQuality, cells);
#pragma omp parallel for schedule(static)
    for (int i = 0; i < (int)all.size(); ++i)
      store(vector<VertexIndex>(all[i].second.begin(), all[i].second.end()));
    store.flush();
  }
  hexes().append(cells); // in the order of their sorted vertices
}



//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

double cellQualityAPI(const TetMeshWrapper& tets, const HXTCombineCell& cell) {
  if (cell.isHex()) {
    vec3 points[8];
    for (HexVertexIndex j = 0; j < 8; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return hexSubdivisionBasedQuality((::point3d*)points);
  }
  else if (cell.isPrism()) {
    vector<vec3> points(6);
    for (PrismVertexIndex j = 0; j <6; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return cellApproximateQuality<Prism>(points.data());
  }
  else if (cell.isPyramid()) {
    vector<vec3> points(5);
    for (CellVertexIndex j = 0; j < 5; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return cellApproximateQuality<Pyramid>(points.data());
  }
  else return 0;
}

}
