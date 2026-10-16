#include "hxt_combine_cpp_api.h"

#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>

#include "basic_types.h"
#include "cell_types.h"
#include "tet_mesh.h"

#include <cmath>
#include <cstdlib>
#include "hxt_omp.h"

/**
* \author Jeanne Pellerin
*/

namespace {
  using namespace HXTCombine;

  // a pseudo-random permutation of the indices
  uint64_t mixIndex(uint64_t x)
  {
    x += 0x9E3779B97F4A7C15ull;
    x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ull;
    x = (x ^ (x >> 27)) * 0x94D049BB133111EBull;
    return x ^ (x >> 31);
  }

  /**
  * The order of the local search: the worst cells first, by tenths of
  * quality, in a pseudo-random order within a tenth. The worst cells are
  * close to one another: in the exact order of their quality, the trials
  * would mostly touch the previous ones and could not run at the same
  * time. Same quality of the result.
  */
  std::vector<CellIndex> localSearchOrder(std::vector<CellIndex> cells,
                                          const double* cellQualities)
  {
    struct Key {
      int level;
      uint64_t mix;
      CellIndex cell;
      bool operator<(const Key& other) const
      {
        if (level != other.level) return level < other.level;
        if (mix != other.mix) return mix < other.mix;
        return cell < other.cell;
      }
    };
    std::vector<Key> keys(cells.size());
    for (std::size_t i = 0; i < cells.size(); ++i)
      keys[i] = {(int)std::floor(10. * cellQualities[cells[i]]), mixIndex(cells[i]), cells[i]};
    std::sort(keys.begin(), keys.end());
    for (std::size_t i = 0; i < cells.size(); ++i) cells[i] = keys[i].cell;
    return cells;
  }

  /**
  * Sorts the cells indices according to their quality: hexes before prisms
  * before pyramids, then decreasing quality, then increasing index. The
  * order is total, so the selection does not depend on the order in which
  * the threads found the candidates. Only the active cells are returned.
  */
  std::vector<CellIndex> orderCellDecreasingQuality(
    const HXTCombineCellArray& cells, const double* cellQualities,
    const std::vector<bool>& active)
  {
    // the sort keys side by side, not scattered in the cells
    struct Key {
      double quality;
      CellIndex cell;
      unsigned int nbVertices;
    };
    std::vector<Key> keys;
    keys.reserve(cells.size());
    for (CellIndex c = 0; c < cells.size(); ++c)
      if (active[c]) keys.push_back({cellQualities[c], c, cells[c].nbVertices()});
    std::sort(keys.begin(), keys.end(), [](const Key& a, const Key& b) {
      if (a.nbVertices != b.nbVertices) return a.nbVertices > b.nbVertices;
      if (a.quality != b.quality) return a.quality > b.quality;
      return a.cell < b.cell;
    });
    std::vector<CellIndex> order(keys.size());
    for (std::size_t i = 0; i < keys.size(); ++i) order[i] = keys[i].cell;
    return order;
  }

  // decreasing quality, then increasing index
  struct BetterCell {
    const double* quality;
    bool operator()(CellIndex a, CellIndex b) const
    {
      if (quality[a] != quality[b]) return quality[a] > quality[b];
      return a < b;
    }
  };

  /**
  * Lists of cells by tet or by vertex in compressed rows: the same lists, in
  * increasing cell order, as vectors of vectors, without an allocation and
  * its spare capacity per row (most of the memory of the selection on
  * meshes with millions of candidates)
  */
  class CellLists {
  public:
    struct Row {
      const CellIndex *b, *e;
      const CellIndex *begin() const { return b; }
      const CellIndex *end() const { return e; }
    };
    // rowsOf(c, add) calls add(row) for each row of cell c
    template <class RowsOf>
    CellLists(std::size_t nbRows, std::size_t nbCells, const RowsOf &rowsOf)
      : start_(nbRows + 1, 0)
    {
      for (CellIndex c = 0; c < nbCells; ++c)
        rowsOf(c, [&](std::size_t r) { start_[r + 1]++; });
      for (std::size_t r = 0; r < nbRows; ++r) start_[r + 1] += start_[r];
      cells_.resize(start_[nbRows]);
      std::vector<std::size_t> next(start_.begin(), start_.end() - 1);
      for (CellIndex c = 0; c < nbCells; ++c)
        rowsOf(c, [&](std::size_t r) { cells_[next[r]++] = c; });
    }
    Row operator[](std::size_t r) const
    {
      return {cells_.data() + start_[r], cells_.data() + start_[r + 1]};
    }
  private:
    std::vector<std::size_t> start_;
    std::vector<CellIndex> cells_;
  };

  /**
  * The ranks of the earliest operation, and of the earliest WRITE one, of a
  * round reading the state around each vertex: an operation runs in the
  * round only if no earlier one is to change what it reads, nor, if it
  * changes the state, reads what it changes (deterministic reservations,
  * Blelloch, Fineman, Gibbons, Shun 2012). The ranks are stamped with the
  * round, for an earlier round to hold none.
  */
  class Reservations {
  public:
    static constexpr unsigned int NONE = (unsigned int)-1;
    explicit Reservations(std::size_t nbVertices) :
      any_(nbVertices, EMPTY), write_(nbVertices, EMPTY) {}
    void nextRound() { stamp_ = (uint64_t)--round_ << 32; }
    void reserve(VertexIndex v, unsigned int rank, bool write)
    {
      writeMin(any_[v], stamp_ | rank);
      if (write) writeMin(write_[v], stamp_ | rank);
    }
    unsigned int anyRank(VertexIndex v) const { return rankOf(any_[v]); }
    unsigned int writeRank(VertexIndex v) const { return rankOf(write_[v]); }
  private:
    static constexpr uint64_t EMPTY = ~(uint64_t)0;
    // the earlier rounds have greater stamps
    uint32_t round_ = 0xffffffffu;
    uint64_t stamp_ = (uint64_t)0xffffffffu << 32;
    unsigned int rankOf(const uint64_t& r) const
    {
      const uint64_t x = __atomic_load_n(&r, __ATOMIC_RELAXED);
      return (x >> 32) == (stamp_ >> 32) ? (unsigned int)x : NONE;
    }
    static void writeMin(uint64_t& r, uint64_t value)
    {
      uint64_t current = __atomic_load_n(&r, __ATOMIC_RELAXED);
      while (value < current &&
             !__atomic_compare_exchange_n(&r, &current, value, true,
                                          __ATOMIC_RELAXED, __ATOMIC_RELAXED)) {}
    }
    std::vector<uint64_t> any_, write_;
  };

  /**
  * An operation of the selection, planned from the current state: DONE, it
  * changes nothing and depends on nothing that may change in the round;
  * READ, it changes nothing but depends on the state around its vertices;
  * WRITE, it changes the state around its vertices only, and depends on it.
  */
  struct Operation {
    enum Kind { DONE, READ, WRITE };
    unsigned int rank;
    Kind kind;
    bool planned;
    std::vector<VertexIndex> vertices;
    std::vector<CellIndex> pool, blockers, released;
    void reset(unsigned int r)
    {
      rank = r;
      kind = DONE;
      planned = false;
      vertices.clear();
      pool.clear();
      blockers.clear();
      released.clear();
    }
  };

  /**
  * By vertex, a superset of the free cells: unselected, with no selected
  * interior tet. A local search reaches the cells sharing a vertex with an
  * ejected cell, hundreds per vertex, but those it can refill with are
  * either the cells around the interior tets of the ejected cell or free
  * cells, a few once the frontal selection has covered most of the volume.
  * A cell is added when it becomes free and never removed: the users check
  * that it still is.
  */
  class FreeCellIndex {
  public:
    explicit FreeCellIndex(std::size_t nbCells) : in_(nbCells, false) {}
    bool contains(CellIndex c) const { return in_[c]; }
    void add(const HXTCombineCell& cell, CellIndex c)
    {
      if (in_[c]) return;
      in_[c] = true;
      for (unsigned int i = 0; i < cell.nbVertices(); ++i)
        byVertex_[cell.vertexes[i]].push_back(c);
    }
    // f(c) for each indexed cell c of vertex v
    template <class F>
    void forEachCell(VertexIndex v, const F &f) const
    {
      auto it = byVertex_.find(v);
      if (it == byVertex_.end()) return;
      for (CellIndex c : it->second) f(c);
    }
  private:
    std::vector<bool> in_;
    std::unordered_map<VertexIndex, std::vector<CellIndex> > byVertex_;
  };

  /**
  * The connectivity of a type of cell in the local indices of its vertices:
  * the kind of each pair (an edge, a diagonal of a quad facet), the quad
  * facets of each vertex as bits, the edges, the 2 diagonals of each quad
  * facet and its 4 triangles (the 3-subsets of its vertices).
  */
  struct CellTopology {
    enum { NONE = 0, EDGE = 1, DIAGONAL = 2 };
    unsigned int nbEdges = 0, nbQuadFacets = 0;
    unsigned char pair[8][8] = {{0}};
    unsigned char quadFacets[8] = {0};
    unsigned char edge[12][2] = {{0}};
    unsigned char diagonal[12][2] = {{0}};
    unsigned char quadTriangle[24][3] = {{0}};
  };

  template <class T>
  CellTopology makeTopology()
  {
    CellTopology t;
    t.nbEdges = T::nbEdges;
    t.nbQuadFacets = T::nbQuadFacets;
    for (unsigned int e = 0; e < T::nbEdges; ++e) {
      const unsigned int a = T::edgeVertex[e][0], b = T::edgeVertex[e][1];
      t.edge[e][0] = a;
      t.edge[e][1] = b;
      t.pair[a][b] = t.pair[b][a] = CellTopology::EDGE;
    }
    for (unsigned int d = 0; d < 2 * T::nbQuadFacets; ++d) {
      const unsigned int a = T::quadFacetDiagonalVertex[d][0], b = T::quadFacetDiagonalVertex[d][1];
      t.diagonal[d][0] = a;
      t.diagonal[d][1] = b;
      t.pair[a][b] = t.pair[b][a] = CellTopology::DIAGONAL;
    }
    for (unsigned int f = 0; f < T::nbQuadFacets; ++f)
      for (unsigned int k = 0; k < 4; ++k)
        for (unsigned int j = 0; j < 3; ++j) {
          const unsigned int v = T::quadFacetTriangleVertex[4 * f + k][j];
          t.quadTriangle[4 * f + k][j] = v;
          t.quadFacets[v] |= 1 << f;
        }
    return t;
  }

  const CellTopology& topologyOf(unsigned int nbVertices)
  {
    static const CellTopology hex = makeTopology<Hex>(), prism = makeTopology<Prism>(),
                              pyramid = makeTopology<Pyramid>();
    return nbVertices == 8 ? hex : nbVertices == 6 ? prism : pyramid;
  }

  class CellGreedySelection {
  public:
    static constexpr CellIndex NO_CELL = (CellIndex)-1;
    // the flags of the cells, written by several threads
    typedef std::vector<char> Flags;

    CellGreedySelection(const TetMeshWrapper& tets,
                        const std::vector<HXTCombineCellArray>& allCells)
      :tets_(tets), dirty_(tets.nbVertices(), 0), allCells_(&allCells),
      tetOwner_(tets.nbTets(), NO_CELL), vertexToSelected_(tets.nbVertices())
    {}

    /**
    * \pre selected is allocated.
    * It is assumed that already selected cells where so by the same instance of the Selector.
    */
    void computeCompatibleCellCombination(
      const HXTCombineCellArray& cells,
      const double* cellQualities,
      vector<bool>& selected)
    {
      // A cell with an interior tet taken by a cell of a previous call (the
      // hexes, for the prisms) can never be selected: this call only ejects
      // its own cells. Most prisms are such cells.
      vector<bool> active(cells.size());
      for (CellIndex c = 0; c < cells.size(); ++c)
        active[c] = selected[c] || !oneInteriorTetSelected(cells[c]);

      CellLists tetToCells(tetOwner_.size(), cells.size(),
                           [&](CellIndex c, const auto &add) {
                             if (!active[c]) return;
                             const HXTCombineCell &cell = cells[c];
                             for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i)
                               add(cell.interiorTetrahedra[i]);
                           });
      std::vector<CellIndex> order =
        orderCellDecreasingQuality(cells, cellQualities, active);

      Flags flags(selected.begin(), selected.end());
      Reservations reservations(tets_.nbVertices());
      greedySelection(cells, order, flags);

      FreeCellIndex freeCells(cells.size());
      for (CellIndex c : order)
        if (isFree(cells[c], c, flags)) freeCells.add(cells[c], c);

      localSearch(cells, cellQualities, tetToCells, freeCells, reservations, flags);
      coverage(cells, cellQualities, order, tetToCells, freeCells, reservations, flags);
      for (CellIndex c = 0; c < cells.size(); ++c) selected[c] = flags[c];
    }

  private:
    bool isFree(const HXTCombineCell& cell, CellIndex c, const Flags& selected) const
    {
      return !selected[c] && !oneInteriorTetSelected(cell);
    }

    /**
    * Cell c was ejected for good: index the cells it may have been the last
    * one to block.
    */
    void release(const HXTCombineCellArray& cells, CellIndex c,
                 const CellLists& tetToCells, FreeCellIndex& freeCells,
                 const Flags& selected) const
    {
      if (isFree(cells[c], c, selected)) freeCells.add(cells[c], c);
      const HXTCombineCell& cell = cells[c];
      for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i) {
        TetIndex t = cell.interiorTetrahedra[i];
        if (tetOwner_[t] != NO_CELL) continue;
        for (CellIndex d : tetToCells[t])
          if (!freeCells.contains(d) && isFree(cells[d], d, selected))
            freeCells.add(cells[d], d);
      }
    }

    /**
    * Runs the operations of rank 0 to n - 1 in rounds of pending ones.
    * plan(op) decides from the state what op would do, and the READ and
    * WRITE operations reserve their vertices. A READ operation runs when no
    * earlier WRITE one of the round has reserved one of its vertices, a
    * WRITE one when no earlier one has; the others wait for the next round
    * and are planned again. capacity(op) bounds the cells a running WRITE
    * operation may select, apply(op) applies it, all of them at the same
    * time, and settle(op) completes it, one after the other. The state is
    * the one of the operations applied one after the other in their order.
    * The number of pending operations adapts so that most of them run.
    */
    template <class Plan, class Capacity, class Apply, class Settle>
    void runInRounds(std::size_t n, std::size_t window, bool adapt,
                     Reservations& reservations, const Plan& plan,
                     const Capacity& capacity, const Apply& apply,
                     const Settle& settle)
    {
      const std::size_t maxWindow = std::min(window, n);
      std::size_t target = adapt ? std::min(maxWindow, (std::size_t)256) : maxWindow;
      std::vector<Operation> ops(maxWindow);
      std::vector<char> runs(maxWindow);
      std::vector<int> writers; // the WRITE operations that run
      std::size_t nbPending = 0, next = 0;
      while (nbPending > 0 || next < n) {
        const std::size_t nbFresh =
          nbPending < target ? std::min(target - nbPending, n - next) : 0;
        for (std::size_t i = 0; i < nbFresh; ++i) {
          ops[nbPending + i].rank = (unsigned int)(next + i);
          ops[nbPending + i].planned = false;
        }
        next += nbFresh;
        const int nbOps = (int)(nbPending + nbFresh);
        reservations.nextRound();
        const uint32_t round = ++round_;

        // the new operations, and the pending ones around which the state
        // has changed, are planned
#pragma omp parallel for schedule(dynamic, 8)
        for (int i = 0; i < nbOps; ++i) {
          Operation& op = ops[i];
          if (!op.planned) {
            op.reset(op.rank);
            plan(op);
            op.planned = true;
          }
          if (op.kind != Operation::DONE)
            for (VertexIndex v : op.vertices)
              reservations.reserve(v, op.rank, op.kind == Operation::WRITE);
        }
        std::size_t nbNewCells = 0, nbRuns = 0;
#pragma omp parallel for schedule(static) reduction(+ : nbNewCells, nbRuns)
        for (int i = 0; i < nbOps; ++i) {
          const Operation& op = ops[i];
          bool run = true;
          for (std::size_t j = 0; run && op.kind != Operation::DONE && j < op.vertices.size(); ++j) {
            const VertexIndex v = op.vertices[j];
            run = op.kind == Operation::WRITE ? reservations.anyRank(v) == op.rank :
                                                reservations.writeRank(v) > op.rank;
          }
          runs[i] = run;
          nbRuns += run;
          if (run && op.kind == Operation::WRITE) nbNewCells += capacity(op);
        }
        writers.clear();
        for (int i = 0; i < nbOps; ++i)
          if (runs[i] && ops[i].kind == Operation::WRITE) writers.push_back(i);
#pragma omp parallel for schedule(dynamic, 1)
        for (int k = 0; k < (int)writers.size(); ++k) {
          apply(ops[writers[k]]);
          // the state changes only around the vertices of the WRITE
          // operations that run: the pending ones elsewhere keep their plan
          for (VertexIndex v : ops[writers[k]].vertices) dirty_[v] = round;
        }
        for (int i : writers) settle(ops[i]);
#pragma omp parallel for schedule(static)
        for (int i = 0; i < nbOps; ++i)
          if (!runs[i])
            for (VertexIndex v : ops[i].vertices)
              if (dirty_[v] == round) {
                ops[i].planned = false;
                break;
              }

        // the operations that did not run wait, in their order
        nbPending = 0;
        for (int i = 0; i < nbOps; ++i)
          if (!runs[i]) std::swap(ops[nbPending++], ops[i]);
        if (adapt) {
          if (4 * nbRuns < (std::size_t)nbOps) target = std::max((std::size_t)16, target / 2);
          else if (5 * nbRuns > 4 * (std::size_t)nbOps) target = std::min(maxWindow, 2 * target);
        }
      }
    }

    /**
    * Greedy selection in the order: a cell is selected if it is compatible
    * with the cells selected before it. Compatibility only depends on the
    * cells sharing vertices: a cell is decided once the cells before it
    * sharing a vertex are, i.e. once it is the first undecided one on each
    * of its vertices. Those share no vertex and are decided at the same
    * time, level after level. A cell with a taken interior tet is rejected
    * as soon as it is met (tets are never released here). Same selection
    * as one cell after the other.
    */
    void greedySelection(const HXTCombineCellArray& cells,
                         const std::vector<CellIndex>& order, Flags& flags)
    {
      const std::size_t n = order.size();
      if (!n) return;
      const std::size_t nbVertices = tets_.nbVertices();
      // the ranks of the cells of each vertex, in increasing order
      std::vector<std::size_t> start(nbVertices + 1, 0);
#pragma omp parallel for schedule(static)
      for (int r = 0; r < (int)n; ++r) {
        const HXTCombineCell cell = cells[order[r]];
        for (unsigned int i = 0; i < cell.nbVertices(); ++i)
          __atomic_fetch_add(&start[cell.vertexes[i] + 1], 1, __ATOMIC_RELAXED);
      }
      for (std::size_t v = 0; v < nbVertices; ++v) start[v + 1] += start[v];
      std::vector<CellIndex> ranks(start[nbVertices]);
      {
        std::vector<std::size_t> next(start.begin(), start.end() - 1);
#pragma omp parallel for schedule(static)
        for (int r = 0; r < (int)n; ++r) {
          const HXTCombineCell cell = cells[order[r]];
          for (unsigned int i = 0; i < cell.nbVertices(); ++i)
            ranks[__atomic_fetch_add(&next[cell.vertexes[i]], 1, __ATOMIC_RELAXED)] = r;
        }
      }
#pragma omp parallel for schedule(dynamic, 1024)
      for (int v = 0; v < (int)nbVertices; ++v)
        std::sort(ranks.begin() + start[v], ranks.begin() + start[v + 1]);

      std::vector<char> decided(n, 0);
      std::vector<unsigned int> checked(n, 0); // the last level each was checked in
      // a position in the list of each vertex before which all are decided
      std::vector<std::size_t> head(start.begin(), start.end() - 1);
      // moves the head of v past the decided cells, rejecting on its way the
      // cells with a taken interior tet; returns the first undecided rank of
      // v, n if none
      auto advance = [&](VertexIndex v, std::vector<CellIndex>* rejected) {
        std::size_t h = __atomic_load_n(&head[v], __ATOMIC_RELAXED);
        CellIndex first = (CellIndex)n;
        for (; h < start[v + 1]; ++h) {
          const CellIndex r = ranks[h];
          if (__atomic_load_n(&decided[r], __ATOMIC_RELAXED)) continue;
          const CellIndex c = order[r];
          if (rejected && !flags[c] && oneInteriorTetSelected(cells[c])) {
            char expected = 0;
            if (__atomic_compare_exchange_n(&decided[r], &expected, 1, false,
                                            __ATOMIC_RELAXED, __ATOMIC_RELAXED))
              rejected->push_back(r);
            continue;
          }
          first = r;
          break;
        }
        // several threads may move it: keep the farthest
        std::size_t current = __atomic_load_n(&head[v], __ATOMIC_RELAXED);
        while (h > current &&
               !__atomic_compare_exchange_n(&head[v], &current, h, true,
                                            __ATOMIC_RELAXED, __ATOMIC_RELAXED)) {}
        return first;
      };
      auto isFirst = [&](CellIndex r) {
        const HXTCombineCell cell = cells[order[r]];
        for (unsigned int i = 0; i < cell.nbVertices(); ++i)
          if (advance(cell.vertexes[i], nullptr) != r) return false;
        return true;
      };

      const int nbThreads = omp_get_max_threads();
      std::vector<std::vector<CellIndex> > found(nbThreads), touchedBy(nbThreads);
      std::vector<CellIndex> level;
#pragma omp parallel for schedule(dynamic, 1024)
      for (int r = 0; r < (int)n; ++r)
        if (isFirst(r)) found[omp_get_thread_num()].push_back(r);
      for (auto& f : found) {
        level.insert(level.end(), f.begin(), f.end());
        f.clear();
      }
      unsigned int levelId = 0;
      while (!level.empty()) {
        ++levelId;
#pragma omp parallel for schedule(dynamic, 16)
        for (int k = 0; k < (int)level.size(); ++k) {
          const CellIndex c = order[level[k]];
          const HXTCombineCell cell = cells[c];
          if (!flags[c] && isCellCompatible(cell)) {
            flags[c] = 1;
            addCellCompatibilityConstraints(cell, c);
          }
          decided[level[k]] = 1;
        }
        // the heads of the vertices of the decided cells move on, and those
        // of the vertices of the cells rejected on the way
#pragma omp parallel for schedule(dynamic, 16)
        for (int k = 0; k < (int)level.size(); ++k) {
          std::vector<CellIndex>& touched = touchedBy[omp_get_thread_num()];
          const std::size_t begin = touched.size();
          touched.push_back(level[k]);
          for (std::size_t j = begin; j < touched.size(); ++j) {
            const HXTCombineCell cell = cells[order[touched[j]]];
            for (unsigned int i = 0; i < cell.nbVertices(); ++i)
              advance(cell.vertexes[i], &touched);
          }
        }
        // their first undecided cells, if first on all their vertices
#pragma omp parallel
        {
          const int t = omp_get_thread_num();
          for (CellIndex d : touchedBy[t]) {
            const HXTCombineCell cell = cells[order[d]];
            for (unsigned int i = 0; i < cell.nbVertices(); ++i) {
              const CellIndex r = advance(cell.vertexes[i], nullptr);
              if (r == n) continue;
              unsigned int seen = __atomic_load_n(&checked[r], __ATOMIC_RELAXED);
              if (seen == levelId ||
                  !__atomic_compare_exchange_n(&checked[r], &seen, levelId, false,
                                               __ATOMIC_RELAXED, __ATOMIC_RELAXED))
                continue;
              if (isFirst(r)) found[t].push_back(r);
            }
          }
        }
        level.clear();
        for (int t = 0; t < nbThreads; ++t) {
          level.insert(level.end(), found[t].begin(), found[t].end());
          found[t].clear();
          touchedBy[t].clear();
        }
      }
    }

    // the vertices of the cells, sorted, without duplicates
    static void cellVertices(const HXTCombineCellArray& cells,
                             const std::vector<CellIndex>& list,
                             std::vector<VertexIndex>& vertices)
    {
      for (CellIndex c : list) {
        const HXTCombineCell cell = cells[c];
        vertices.insert(vertices.end(), cell.vertexes, cell.vertexes + cell.nbVertices());
      }
      std::sort(vertices.begin(), vertices.end());
      vertices.erase(std::unique(vertices.begin(), vertices.end()), vertices.end());
    }

    /**
    * Local-search polish on top of the greedy result: the greedy pass
    * above is a classic quality-sorted "scan and lock" heuristic for what
    * is really a set-packing problem, so it can get stuck -- a single
    * mediocre cell accepted early can permanently block two or three
    * better cells that would have fit together. For every currently
    * selected cell (worst quality first), try ejecting it and greedily
    * re-filling the freed tets/vertices/edges from the pool of previously
    * rejected candidates that actually touched that cell; keep the swap
    * only if it nets at least one more selected cell than before, else
    * put the original cell back exactly as it was. The trials touching
    * disjoint sets of vertices run at the same time.
    */
    void localSearch(const HXTCombineCellArray& cells, const double* cellQualities,
                     const CellLists& tetToCells, FreeCellIndex& freeCells,
                     Reservations& reservations, Flags& flags)
    {
      if (cells.empty()) return;
      BetterCell better{cellQualities};
      std::vector<CellIndex> selectedList;
      for (CellIndex c = 0; c < cells.size(); ++c)
        if (flags[c]) selectedList.push_back(c);
      // Try ejecting the worst-quality selected cells first: they are the
      // ones most likely to be worth trading away.
      selectedList = localSearchOrder(selectedList, cellQualities);

      runInRounds(selectedList.size(), 1 << 12, true, reservations,
        [&](Operation& op) {
          const CellIndex s = selectedList[op.rank];
          if (!flags[s]) return; // already ejected for good by an earlier swap
          const HXTCombineCell cellS = cells[s];
          // the cells around the interior tets of s, and the free cells of
          // its vertices (a refillable cell of a vertex of s, without an
          // interior tet of s, is free)
          std::vector<CellIndex>& visited = op.blockers;
          for (unsigned int i = 0; i < cellS.nbInteriorTets(); ++i)
            for (CellIndex c : tetToCells[cellS.interiorTetrahedra[i]])
              visited.push_back(c);
          for (unsigned int i = 0; i < cellS.nbVertices(); ++i)
            freeCells.forEachCell(cellS.vertexes[i],
                                  [&](CellIndex c) { visited.push_back(c); });
          std::sort(visited.begin(), visited.end());
          visited.erase(std::unique(visited.begin(), visited.end()), visited.end());
          // Tet ownership only grows during the refill below, so a candidate
          // with an interior tet owned by anything but s can never pass
          // isCellCompatible: leave it out of the pool.
          // A cell left out stays so while the tet that keeps it out keeps its
          // owner: only the vertices of that tet are read.
          for (CellIndex c : visited) {
            const HXTCombineCell cc = cells[c];
            TetIndex blocking = NO_ID;
            for (unsigned int i = 0; i < cc.nbInteriorTets() && blocking == NO_ID; ++i) {
              const CellIndex o = tetOwner_[cc.interiorTetrahedra[i]];
              if (o != NO_CELL && o != s) blocking = cc.interiorTetrahedra[i];
            }
            if (blocking == NO_ID && flags[c]) blocking = cc.interiorTetrahedra[0];
            if (blocking == NO_ID) op.pool.push_back(c);
            else
              for (TetVertexIndex j = 0; j < 4; ++j)
                op.vertices.push_back(tetVertex(blocking, j));
          }
          visited = op.pool;
          visited.push_back(s);
          cellVertices(cells, visited, op.vertices);
          visited.clear();
          // cannot reach the net gain of 2
          op.kind = op.pool.size() < 2 ? Operation::READ : Operation::WRITE;
        },
        [](const Operation& op) { return op.pool.size(); },
        [&](Operation& op) {
          const CellIndex s = selectedList[op.rank];
          removeCellCompatibilityConstraints(cells[s], s);
          flags[s] = 0;
          std::sort(op.pool.begin(), op.pool.end(), better);
          std::vector<CellIndex> added;
          for (CellIndex c : op.pool) {
            if (flags[c]) continue;
            if (isCellCompatible(cells[c])) {
              flags[c] = 1;
              addCellCompatibilityConstraints(cells[c], c);
              added.push_back(c);
            }
          }
          if (added.size() >= 2) {
            // net gain: keep s ejected and the newly added cells selected
            op.released.push_back(s);
          }
          else {
            for (CellIndex c : added) {
              removeCellCompatibilityConstraints(cells[c], c);
              flags[c] = 0;
            }
            flags[s] = 1;
            addCellCompatibilityConstraints(cells[s], s);
          }
        },
        [&](Operation& op) {
          for (CellIndex c : op.released) release(cells, c, tetToCells, freeCells, flags);
        });
    }

    /**
    * localSearch only ever ejects ONE already-selected cell at a time, so
    * it can never reach a good candidate that needs several neighboring
    * selected hexes ejected simultaneously to become
    * vertex/edge/diagonal-compatible -- exactly the situation around a
    * leftover-tet cavity entirely surrounded by already-selected hexes.
    * For every still-unselected candidate whose own interior tets are
    * all free (so it is blocked only by vertex-level sharing, not a raw
    * tet conflict), find every currently selected cell it shares a
    * vertex with, eject all of them at once, then try to reinsert the
    * candidate plus greedily refill the freed pool; keep only if this
    * nets strictly more selected cells than were ejected AND the
    * candidate itself is actually part of the kept result -- otherwise
    * put everything back exactly as it was. The trials touching disjoint
    * sets of vertices run at the same time.
    */
    void coverage(const HXTCombineCellArray& cells, const double* cellQualities,
                  const std::vector<CellIndex>& order, const CellLists& tetToCells,
                  FreeCellIndex& freeCells, Reservations& reservations, Flags& flags)
    {
      if (cells.empty()) return;
      // Bounds how many already-selected cells a single candidate is
      // allowed to displace at once. Measured on a hex-dominant stress
      // case: cap 18 already captures almost all of the reachable gain
      // (77978 -> 78170 selected hexes) at no measurable extra cost over
      // localSearch alone, whereas cap 30 only adds a further +0.1% for
      // +76% wall time -- steeply diminishing returns past this point.
      const std::size_t kMaxEject = 18;
      BetterCell better{cellQualities};

      runInRounds(order.size(), 1 << 14, true, reservations,
        [&](Operation& op) {
          const CellIndex c = order[op.rank];
          const HXTCombineCell cellC = cells[c];
          // whatever the outcome, it depends on the state around c
          op.kind = Operation::READ;
          op.vertices.assign(cellC.vertexes, cellC.vertexes + cellC.nbVertices());
          // the candidates are the free cells, all indexed
          if (!freeCells.contains(c)) return;
          if (flags[c] || !cellC.isHex()) return;
          if (oneInteriorTetSelected(cellC)) return;
          if (isCellCompatible(cellC)) return; // would have been picked already

          // the selected cells sharing a vertex with c (this is the only
          // call selecting hexes, so they are cells of this call)
          std::vector<CellIndex>& blockers = op.blockers;
          for (unsigned int i = 0; i < cellC.nbVertices(); ++i)
            for (CellTag tag : vertexToSelected_[cellC.vertexes[i]])
              if (typeOf(tag) == HEX && flags[indexOf(tag)]) blockers.push_back(indexOf(tag));
          std::sort(blockers.begin(), blockers.end());
          blockers.erase(std::unique(blockers.begin(), blockers.end()), blockers.end());
          if (blockers.empty() || blockers.size() > kMaxEject) return;

          auto isBlocker = [&](CellIndex x) {
            return x != NO_CELL && std::binary_search(blockers.begin(), blockers.end(), x);
          };
          std::vector<CellIndex> visited;
          for (CellIndex b : blockers) {
            const HXTCombineCell cb = cells[b];
            for (unsigned int i = 0; i < cb.nbInteriorTets(); ++i)
              for (CellIndex p : tetToCells[cb.interiorTetrahedra[i]]) visited.push_back(p);
            // a pool cell of a vertex of b, without an interior tet of a
            // blocker, is free
            for (unsigned int i = 0; i < cb.nbVertices(); ++i)
              freeCells.forEachCell(cb.vertexes[i], [&](CellIndex p) { visited.push_back(p); });
          }
          std::sort(visited.begin(), visited.end());
          visited.erase(std::unique(visited.begin(), visited.end()), visited.end());
          // Same exact pruning as in localSearch: once the blockers are
          // ejected, a candidate with an interior tet owned by any other
          // selected cell stays incompatible for the whole refill.
          // as in localSearch, a cell left out stays so while the tet that
          // keeps it out keeps its owner
          for (CellIndex p : visited) {
            if (p == c) continue;
            const HXTCombineCell cp = cells[p];
            TetIndex blocking = NO_ID;
            for (unsigned int i = 0; i < cp.nbInteriorTets() && blocking == NO_ID; ++i) {
              const CellIndex o = tetOwner_[cp.interiorTetrahedra[i]];
              if (o != NO_CELL && !isBlocker(o)) blocking = cp.interiorTetrahedra[i];
            }
            if (blocking == NO_ID && flags[p] && !isBlocker(p)) blocking = cp.interiorTetrahedra[0];
            if (blocking == NO_ID) op.pool.push_back(p);
            else
              for (TetVertexIndex j = 0; j < 4; ++j)
                op.vertices.push_back(tetVertex(blocking, j));
          }
          visited = op.pool;
          visited.insert(visited.end(), blockers.begin(), blockers.end());
          visited.push_back(c);
          cellVertices(cells, visited, op.vertices);
          // c plus the whole pool must beat the number of ejected blockers
          if (1 + op.pool.size() > blockers.size()) op.kind = Operation::WRITE;
        },
        [](const Operation& op) { return 1 + op.pool.size() + op.blockers.size(); },
        [&](Operation& op) {
          const CellIndex c = order[op.rank];
          const std::vector<CellIndex>& blockers = op.blockers;
          for (CellIndex b : blockers) {
            removeCellCompatibilityConstraints(cells[b], b);
            flags[b] = 0;
          }
          // the swap is only ever kept if c itself goes in first
          if (!isCellCompatible(cells[c])) {
            for (CellIndex b : blockers) {
              flags[b] = 1;
              addCellCompatibilityConstraints(cells[b], b);
            }
            return;
          }
          std::vector<CellIndex> added;
          flags[c] = 1;
          addCellCompatibilityConstraints(cells[c], c);
          added.push_back(c);

          std::sort(op.pool.begin(), op.pool.end(), better);
          for (CellIndex p : op.pool) {
            if (flags[p]) continue;
            if (isCellCompatible(cells[p])) {
              flags[p] = 1;
              addCellCompatibilityConstraints(cells[p], p);
              added.push_back(p);
            }
          }

          if (added.size() > blockers.size()) {
            // net gain, and it includes the candidate we were trying to
            // unlock: keep this swap.
            for (CellIndex b : blockers)
              if (!flags[b]) op.released.push_back(b);
          }
          else {
            for (CellIndex a : added) {
              removeCellCompatibilityConstraints(cells[a], a);
              flags[a] = 0;
            }
            for (CellIndex b : blockers) {
              flags[b] = 1;
              addCellCompatibilityConstraints(cells[b], b);
            }
          }
        },
        [&](Operation& op) {
          for (CellIndex b : op.released) release(cells, b, tetToCells, freeCells, flags);
        });
    }

    /** Check that the input cell is compatible with
    * all the already selected cells.
    *
    * A lot of invalid configurations are discarded implicitely.
    * No need to check triangular facets againt quad facets, because the
    * check of their edges against the diagonals is sufficient.
    *
    * The edges, quad facet diagonals and quad facet triangles of the
    * selected cells it is checked against are those of the selected cells
    * sharing two vertices with it, read from the cells of its vertices: no
    * table of all of them, and the cell and its neighbours only are read.
    */
    bool isCellCompatible(const HXTCombineCell& cell) const
    {
      // EXPERIMENTAL, opt-in only (GMSH_PAPER_COMPAT): the simpler
      // pairwise test from Pellerin, Johnen, Remacle (IMR26 2017)
      // "Identifying combinations of tetrahedra into hexahedra: a
      // vertex based strategy" -- see isCellCompatiblePaper2017 below.
      static bool paperCompat = getenv("GMSH_PAPER_COMPAT") != nullptr;
      if (paperCompat && cell.isHex())
        return isCellCompatiblePaper2017(cell);

      if (oneInteriorTetSelected(cell)) return false;

      const unsigned int nbVertices = cell.nbVertices();
      unsigned int nbCommonVertices = 0;
      for (unsigned int i = 0; i < nbVertices; ++i)
        nbCommonVertices += !vertexToSelected_[cell.vertexes[i]].empty();
      if (nbCommonVertices < 2) return true;

      const CellTopology& topology = topologyOf(nbVertices);
      bool diagonalFound[12] = {false}, triangleFound[24] = {false};
      CellTag neighbors[256];
      unsigned int nbNeighbors = 0;
      for (unsigned int i = 0; i < nbVertices; ++i)
        for (CellTag tag : vertexToSelected_[cell.vertexes[i]]) {
          bool known = false;
          for (unsigned int k = 0; k < nbNeighbors && !known; ++k) known = neighbors[k] == tag;
          if (!known && nbNeighbors < 256) neighbors[nbNeighbors++] = tag;
        }
      for (unsigned int k = 0; k < nbNeighbors; ++k) {
        const HXTCombineCell other = selectedCell(neighbors[k]);
        const CellTopology& otherTopology = topologyOf(other.nbVertices());
        // the local index in other of each vertex of cell, -1 if none
        int at[8];
        unsigned int nbShared = 0;
        for (unsigned int i = 0; i < nbVertices; ++i) {
          at[i] = -1;
          for (unsigned int j = 0; j < other.nbVertices(); ++j)
            if (other.vertexes[j] == cell.vertexes[i]) {
              at[i] = (int)j;
              nbShared++;
              break;
            }
        }
        if (nbShared < 2) continue;
        auto kind = [&](unsigned int i, unsigned int j) {
          return at[i] < 0 || at[j] < 0 ? (unsigned char)CellTopology::NONE :
                                          otherTopology.pair[at[i]][at[j]];
        };
        // the edges of cell against the diagonals of the others
        for (unsigned int e = 0; e < topology.nbEdges; ++e)
          if (kind(topology.edge[e][0], topology.edge[e][1]) == CellTopology::DIAGONAL)
            return false;
        // its diagonals against their edges, and their diagonals
        for (unsigned int d = 0; d < 2 * topology.nbQuadFacets; ++d) {
          const unsigned char pair = kind(topology.diagonal[d][0], topology.diagonal[d][1]);
          if (pair == CellTopology::EDGE) return false;
          if (pair == CellTopology::DIAGONAL) diagonalFound[d] = true;
        }
        if (nbCommonVertices > 2)
          for (unsigned int t = 0; t < 4 * topology.nbQuadFacets; ++t) {
            const int a = at[topology.quadTriangle[t][0]], b = at[topology.quadTriangle[t][1]],
                      c = at[topology.quadTriangle[t][2]];
            if (a >= 0 && b >= 0 && c >= 0 &&
                (otherTopology.quadFacets[a] & otherTopology.quadFacets[b] &
                 otherTopology.quadFacets[c]))
              triangleFound[t] = true;
          }
      }
      // if a diagonal of a quad facet is one of a selected quad facet, the
      // other one must be too: that same quad facet
      for (unsigned int f = 0; f < topology.nbQuadFacets; ++f)
        if (diagonalFound[2 * f] != diagonalFound[2 * f + 1]) return false;
      if (nbCommonVertices > 2) {
        // all or none of the 4 triangles of each quad facet are triangles
        // of selected quad facets
        for (unsigned int f = 0; f < topology.nbQuadFacets; ++f) {
          unsigned int nb = 0;
          for (unsigned int t = 0; t < 4; ++t) nb += triangleFound[4 * f + t];
          if (nb != 0 && nb != 4) return false;
        }
      }
      return true;
    }

    /**
    * EXPERIMENTAL: pairwise compatibility test exactly as described in
    * Pellerin, Johnen, Remacle, "Identifying combinations of tetrahedra
    * into hexahedra: a vertex based strategy", IMR26 2017, section on
    * hex-dominant mesh generation: "Two hexahedra of H are compatible
    * if their intersection is either empty or an element of their
    * boundary: a shared vertex, a shared edge, or a shared quadrilateral
    * face. [...] If the two hexahedra share one, two, or four vertices,
    * then we check that the corresponding vertex, edge, or face is
    * indeed on the boundary of both hexahedra. If the two hexahedra
    * share three vertices, they cannot be compatible." Unlike the
    * E/D_Q/D_H bookkeeping above (built for the more general hex +
    * prism + pyramid combinatorial search), this never looks at face
    * diagonals at all -- only at whether the shared vertex set is a
    * genuine edge/face of *both* hexes.
    */
    bool isCellCompatiblePaper2017(const HXTCombineCell& cell) const
    {
      if (oneInteriorTetSelected(cell)) return false;

      std::set<CellTag> neighbors;
      for (unsigned int i = 0; i < cell.nbVertices(); ++i)
        for (CellTag nb : vertexToSelected_[cell.vertexes[i]])
          if (typeOf(nb) == HEX) neighbors.insert(nb);

      std::vector<VertexIndex> shared;
      for (CellTag nbId : neighbors) {
        const HXTCombineCell other = selectedCell(nbId);
        shared.clear();
        for (unsigned int i = 0; i < cell.nbVertices(); ++i)
          if (other.hasVertex(cell.vertexes[i])) shared.push_back(cell.vertexes[i]);

        if (shared.size() <= 1) continue;
        if (shared.size() == 2) {
          if (!isEdgeOfHex(cell, shared[0], shared[1]) ||
              !isEdgeOfHex(other, shared[0], shared[1]))
            return false;
        }
        else if (shared.size() == 4) {
          if (!isFaceOfHex(cell, shared) || !isFaceOfHex(other, shared))
            return false;
        }
        else {
          // 3 shared vertices (explicitly ruled out by the paper), or
          // more than 4 (not covered -- treated conservatively).
          return false;
        }
      }
      return true;
    }

    static bool isEdgeOfHex(const HXTCombineCell& h, VertexIndex a, VertexIndex b)
    {
      for (unsigned int e = 0; e < Hex::nbEdges; ++e) {
        VertexIndex v0 = h.vertex(Hex::edgeVertex[e][0]);
        VertexIndex v1 = h.vertex(Hex::edgeVertex[e][1]);
        if ((v0 == a && v1 == b) || (v0 == b && v1 == a)) return true;
      }
      return false;
    }

    static bool isFaceOfHex(const HXTCombineCell& h, const std::vector<VertexIndex>& verts4)
    {
      std::array<VertexIndex, 4> sortedIn;
      std::copy(verts4.begin(), verts4.end(), sortedIn.begin());
      std::sort(sortedIn.begin(), sortedIn.end());
      for (unsigned int f = 0; f < Hex::nbQuadFacets; ++f) {
        std::array<VertexIndex, 4> fv = {
          h.vertex(Hex::facetVertex[f][0]), h.vertex(Hex::facetVertex[f][1]),
          h.vertex(Hex::facetVertex[f][2]), h.vertex(Hex::facetVertex[f][3]) };
        std::sort(fv.begin(), fv.end());
        if (fv == sortedIn) return true;
      }
      return false;
    }

    bool oneInteriorTetSelected(const HXTCombineCell& cell) const {
      for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i) {
        if (tetOwner_[cell.interiorTetrahedra[i]] != NO_CELL) return true;
      }
      return false;
    }

    /**
    * The cell has been selected: it takes its interior tets, and becomes
    * one of the selected cells of its vertices.
    */
    void addCellCompatibilityConstraints(const HXTCombineCell& cell, CellIndex id)
    {
      const CellTag tag = makeTag(cell, id);
      for (CellVertexIndex i = 0; i < cell.nbVertices(); ++i)
        vertexToSelected_[cell.vertexes[i]].push_back(tag);
      for (CellTetIndex i = 0; i < cell.nbInteriorTets(); ++i)
        tetOwner_[cell.interiorTets()[i]] = id;
    }

    /**
    * The reverse of addCellCompatibilityConstraints: undo exactly what
    * selecting this cell had added, so it (and only it) can be ejected
    * without disturbing any other still-selected cell that happens to
    * share a vertex/edge/diagonal with it.
    */
    void removeCellCompatibilityConstraints(const HXTCombineCell& cell, CellIndex id)
    {
      const CellTag tag = makeTag(cell, id);
      for (CellVertexIndex i = 0; i < cell.nbVertices(); ++i) {
        std::vector<CellTag>& atV = vertexToSelected_[cell.vertexes[i]];
        auto it = std::find(atV.begin(), atV.end(), tag);
        if (it != atV.end()) atV.erase(it);
      }
      for (CellTetIndex i = 0; i < cell.nbInteriorTets(); ++i) {
        TetIndex t = cell.interiorTets()[i];
        if (tetOwner_[t] == id) tetOwner_[t] = NO_CELL;
      }
    }

    // a selected cell: its type in the 2 high bits, its index in the others
    typedef unsigned int CellTag;
    enum { HEX = 0, PRISM = 1, PYRAMID = 2 };
    static unsigned int typeOf(const HXTCombineCell& cell)
    {
      return cell.isHex() ? HEX : cell.isPrism() ? PRISM : PYRAMID;
    }
    static CellTag makeTag(const HXTCombineCell& cell, CellIndex id)
    {
      return (typeOf(cell) << 30) | id;
    }
    static unsigned int typeOf(CellTag tag) { return tag >> 30; }
    static CellIndex indexOf(CellTag tag) { return tag & 0x3fffffffu; }
    HXTCombineCell selectedCell(CellTag tag) const
    {
      return (*allCells_)[typeOf(tag)][indexOf(tag)];
    }

  private:
    VertexIndex tetVertex(TetIndex t, TetVertexIndex j) const { return tets_.vertex(t, j); }

    const TetMeshWrapper& tets_;
    // the last round in which the state changed around each vertex
    std::vector<uint32_t> dirty_;
    uint32_t round_ = 0;
    // the cells of each type, hexes, prisms and pyramids
    const std::vector<HXTCombineCellArray>* allCells_;
    std::vector<CellIndex> tetOwner_;
    // the selected cells of each vertex (a vertex can be shared by several)
    std::vector<std::vector<CellTag> > vertexToSelected_;
  };

}

namespace HXTCombine {

  static void interiorVertices(
    const TetMeshForCombining& tets, const HXTCombineCell& cell, vector<VertexIndex>& intV)
  {
    std::set<VertexIndex> result;
    for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i) {
      TetIndex t = cell.tet(i);
      for (TetVertexIndex v = 0; v <4; ++v) {
        VertexIndex vi = tets.vertex(t, v);
        if (!cell.hasVertex(vi)) result.insert(vi);
      }
    }
    intV.assign(result.begin(), result.end());
  }

  static void flagFalseIndices(
    vector<bool>& flags, std::size_t n, const unsigned int *indices) {
    for (unsigned int i = 0; i < n; ++i)
      flags[indices[i]] = false;
  }

  struct HXTCombineCellStore::Selector {
    Selector(const TetMeshWrapper& mesh, const std::vector<HXTCombineCellArray>& cells) :
      selection(mesh, cells) {}
    CellGreedySelection selection;
  };

  void HXTCombineCellStore::resetSelection()
  {
    selector_ = std::make_shared<Selector>(mesh_, cells_);
    for (unsigned int i = 0; i+1 < nbCellTypes; ++i)
      selectedCells_[i].assign(cells_[i].size(), false);
    // All the tets of the input mesh are by default selected
    selectedCells_[TET].assign(mesh_.nbTets(), true);
  }

  void HXTCombineCellStore::selectCells(CELLTYPE type)
  {
    if (!selector_) resetSelection();
    HXTCombineCellArray& cells = cells_[type];
    std::vector<bool>& selected = selectedCells_[type];
    selected.resize(cells.size(), false);

    std::vector<double> qualities(cells.size());
    computeCellQualityVector(mesh_, cells, qualities.data());
    selector_->selection.computeCompatibleCellCombination(cells, qualities.data(), selected);
    // TODO Pyramids should swallow all quad facets
    updateSelectedTets();
  }

  // the tets of the input mesh not taken by a selected cell
  void HXTCombineCellStore::updateSelectedTets()
  {
    std::vector<bool>& selected = selectedTets();
    selected.assign(mesh_.nbTets(), true);
    for (unsigned int cellType = 0; cellType < 3; ++cellType) {
      const HXTCombineCellArray& curCells = cells_[cellType];
      for (unsigned int i = 0; i < curCells.size(); ++i) {
        if (i >= selectedCells_[cellType].size() || !selectedCells_[cellType][i]) continue;
        const HXTCombineCell& cell = curCells[i];
        flagFalseIndices(selected, cell.nbBoundaryTets(), cell.boundaryTets());
        flagFalseIndices(selected, cell.nbInteriorTets(), cell.interiorTets());
      }
    }
  }

  void HXTCombineCellStore::selectCellsGreedy(std::array<bool, nbCellTypes> flags)
  {
    resetSelection();
    for (unsigned int i = 0; i+1 < nbCellTypes; ++i)
      if (flags[i]) selectCells((CELLTYPE)i);
    // How do we ensure conformity? How do we ensure that the whole volume is filled?
    // TODO To get a conformal mesh there should be no visible quad facet anymore

    // Without tets, none of the tets of the mesh is taken
    if (!flags[TET]) selectedTets().assign(mesh_.nbTets(), true);
    selector_.reset();
  }


  void HXTCombineCellStore::selectAlongFrames(double minQuality,
                                              const std::vector<double>& frames,
                                              const std::vector<double>& sizes,
                                              bool prisms,
                                              FrameSelectionStatistics* statistics)
  {
    FrameSelectionStatistics stats;
    // the vertices of the tets no selected cell takes
    auto freeVertices = [&]() {
      std::vector<bool> fv(mesh_.nbVertices(), false);
      const std::vector<bool>& freeTets = selectedTets();
      for (TetIndex t = 0; t < mesh_.nbTets(); ++t)
        if (freeTets[t])
          for (TetVertexIndex i = 0; i < 4; ++i) fv[mesh_.vertex(t, i)] = true;
      return fv;
    };
    auto count = [](const std::vector<bool>& v) {
      return (std::size_t)std::count(v.begin(), v.end(), true);
    };

    resetSelection();
    // 2 neighbours along each axis: one misses the hexes of curved lattices
    computeGuidedHexes(minQuality, frames, sizes, nullptr, 2);
    stats.nbProposedHexes = hexes().size();
    selectCells(HEX);
    stats.nbSelectedProposedHexes = nbSelectedHexes();

    // more neighbours where the frames leave tets
    std::vector<bool> fv = freeVertices();
    stats.nbFreeVertices = count(fv);
    computeGuidedHexes(minQuality, frames, sizes, &fv, 3, 2);
    stats.nbResidualHexes = hexes().size() - stats.nbProposedHexes;
    selectCells(HEX);

    if (prisms) {
      stats.nbFreeTets = count(selectedTets());
      computeGuidedPrisms(minQuality, frames, sizes, selectedTets());
      stats.nbProposedPrisms = this->prisms().size();
      selectCells(PRISM);
    }
    if (statistics) *statistics = stats;
  }

  unsigned int HXTCombineCellStore::nbSelectedHexes() const
  {
    return std::count(selectedCells_[HEX].begin(), selectedCells_[HEX].end(), true);
  }
  unsigned int HXTCombineCellStore::nbSelectedPrisms() const 
  {
    return std::count(selectedCells_[PRISM].begin(), selectedCells_[PRISM].end(), true);
  }
  unsigned int HXTCombineCellStore::nbSelectedPyramids() const 
  {
    return std::count(selectedCells_[PYRAMID].begin(), selectedCells_[PYRAMID].end(), true);
  }
  unsigned int HXTCombineCellStore::nbSelectedTets() const 
  {
    return std::count(selectedCells_[TET].begin(), selectedCells_[TET].end(), true);
  }


  static void saveTetsMESH(const TetMeshWrapper& tets, const vector<bool>& tetsToSave, std::ofstream& out)
  {
    unsigned int nbTetsToSave = std::count(tetsToSave.begin(), tetsToSave.end(), true);
    out << "Tetrahedra" << std::endl;
    out << nbTetsToSave << std::endl;

    for (unsigned int t = 0; t < tets.nbTets(); ++t) {
      if (!tetsToSave[t]) continue;
      else {
        out
          << tets.vertex(t, 0)+1 << " "
          << tets.vertex(t, 1)+1 << " "
          << tets.vertex(t, 2)+1 << " "
          << tets.vertex(t, 3)+1 << " "
          << " 0 " << std::endl; // The real color is not known here
      }
    }
    out << std::endl;
  }

  static void saveTetMSH(const TetMeshWrapper& tets, const vector<bool>& tetsToSave,
    std::ofstream& out, unsigned int& elemCounter)
  {
    for (unsigned int t = 0; t < tets.nbTets(); ++t) {
      if (!tetsToSave[t]) continue;
      else {
        elemCounter++;
        out << elemCounter << " " <<  4 << " 2 0 0 "
          << tets.vertex(t, 0)+1 << " "
          << tets.vertex(t, 1)+1 << " "
          << tets.vertex(t, 2)+1 << " "
          << tets.vertex(t, 3)+1 << " "
          << std::endl;
      }
    }
  }


  void HXTCombineCellStore::saveMESH(
    const std::string& filename, std::array<bool, nbCellTypes> cellType)
  {
    // 1. Open the file
    std::ofstream out(filename.c_str());
    if (out.bad()) {
      std::cout<< "Error when opening the file: "<< filename.c_str() << std::endl;
      return;
    }
    out.precision(16);
    out << "MeshVersionFormatted 2" << std::endl
      << "Dimension" << std::endl
      << "3" << std::endl << std::endl;

    // 2. Save things
    saveVerticesMESH(mesh_, out);

    if (cellType[TET]) saveTetsMESH(mesh_, selectedTets(), out);

    // I am not really sure that we can save all this in this file format
    std::string cellTypesNames[nbCellTypes-1] = { "Hexahedra", "Prisms", "Pyramids" };

    for (unsigned int i = 0; i+1 < nbCellTypes; ++i) {
      if (!cellType[i]) continue;
      unsigned int nb = nbTrueValues(selectedCells_[i]);
      out << cellTypesNames[i] << std::endl;
      out << nb << std::endl;
      for (unsigned int j = 0; j < cells_[i].size(); ++j) {
        if (selectedCells_[i][j]) out << cells_[i][j] << " 0 " << std::endl;
      }
      out << std::endl;
    }

    out << "End" << std::endl;
    out.close();
  }


  /** Save tets, prisms and hexs */
  void HXTCombineCellStore::saveMSH(
    const std::string& filename, std::array<bool, nbCellTypes> cellType)
  {
    // 1. Open the file
    std::ofstream out(filename.c_str());
    if (out.bad()) {
      std::cout<< "Error when opening the file: "<< filename.c_str() << std::endl;
      return;
    }
    out.precision(16);
    out <<
      "$MeshFormat" << std::endl << "2.2 0 8" << std::endl
      << "$EndMeshFormat" << std::endl;

    // VERTICES
    saveVerticesMSH(mesh_, out);

    unsigned int nbHexes = cellType[HEX] ? nbTrueValues(selectedHexes()) : 0;
    unsigned int nbPrisms = cellType[PRISM] ? nbTrueValues(selectedPrisms()) : 0;
    unsigned int nbPyramids = cellType[PYRAMID] ? nbTrueValues(selectedPyramids()) : 0;
    unsigned int nbTets = cellType[TET] ? nbTrueValues(selectedTets()) : 0;

    out << "$Elements" << std::endl
      << nbTets + nbHexes + nbPrisms + nbPyramids  << std::endl;

    // TETS
    unsigned int elemCounter = 0;
    saveTetMSH(mesh_, selectedTets(), out, elemCounter);

    // OTHER CELLS
    for (unsigned int type = 0; type+1 < nbCellTypes; ++type) {
      if (!cellType[type]) continue;
      const HXTCombineCellArray& cells = cells_[type];
      const std::vector<bool>& selected = selectedCells_[type];

      for (unsigned int i = 0; i < cells.size(); ++i) {
        if (selected[i]) {
          elemCounter++;
          out << elemCounter << " ";

          if (cells[i].isPrism()) out << 6;
          else if (cells[i].isHex()) out << 5;
          else if (cells[i].isPyramid()) out << 7;
          else out << "ERROR";

          out << " 2 0 0 " << cells[i] << std::endl;
        }
      }
    }
    out << "$EndElements" << std::endl;
    out.close();
  }

  static void computeTetCorners(
    const HXTCombineCell& cell,
    const TetMeshWrapper& tet_mesh,
    bool withBoundaryTets,
    vector<VertexIndex>& corners)
  {
    size_t n = cell.nbInteriorTets();
    if (withBoundaryTets) n += cell.nbBoundaryTets();
    corners.resize(4*n, NO_ID);
    for (unsigned int t = 0; t < n; ++t) {
      for (TetVertexIndex v = 0; v <4; ++v) {
        TetIndex curTet = cell.tet(t);
        corners[4*t+v] = tet_mesh.vertex(curTet, v);
      }
    }
  }

  std::string cellTypeName(const HXTCombineCell& cell) {
    if (cell.isHex()) return "Hexahedra";
    else if (cell.isPrism()) return "Prisms";
    else if (cell.isPyramid()) return "Pyramids";
    else return std::string();
  }

  void writeCandidateCellMESH(
    const HXTCombineCell& cell,
    const TetMeshWrapper& tetMesh,
    std::ofstream& out,
    bool withBoundaryTets)
  {
    vector<VertexIndex> corners;
    computeTetCorners(cell, tetMesh, withBoundaryTets, corners);
    std::map<VertexIndex, unsigned int> old2new;
    vector<unsigned int> vertices; // new local indices

    // Get the vertices - renumber the corners - vector is small
    for (unsigned int i = 0; i < corners.size(); ++i) {
      if (std::count(vertices.begin(), vertices.end(), corners[i]) == 0) {
        unsigned int newV = vertices.size();
        vertices.push_back(corners[i]);
        old2new.insert(std::make_pair(corners[i], newV));
      }
    }

    vector<unsigned int> cellCorners(cell.nbVertices());
    for (unsigned int i = 0; i < cellCorners.size(); ++i) {
      cellCorners[i] = old2new[cell.vertices()[i]];
    }
    vector<unsigned int> tetCorners(corners.size());
    for (unsigned int i = 0; i < tetCorners.size(); ++i) {
      tetCorners[i] = old2new[corners[i]];
    }

    out << "MeshVersionFormatted 2" << std::endl
      << "Dimension" << std::endl
      << "3" << std::endl << std::endl;

    // VERTICES
    out << "Vertices" << std::endl;
    out << vertices.size() << std::endl;
    for (unsigned int i = 0; i < vertices.size(); ++i) {
      const vec3& p = tetMesh.point(vertices[i]);
      out << p[0] << "  " << p[1] << "  " << p[2] << "  " << "0" << std::endl;
    }
    out << std::endl;

    // THE CELL
    out << cellTypeName(cell) << std::endl << 1 << std::endl;
    out << cell << " " << std::endl;
    out << std::endl;

    // THE TETRAHEDRA
    out << "Tetrahedra" << std::endl;
    out << tetCorners.size()/4 << std::endl;

    int count = 0;
    for (unsigned int i = 0; i < tetCorners.size(); ++i) {
      out << tetCorners[i]+1 << " ";
      count++;
      if (count == 4) {
        out << "0" << std::endl;
        count = 0;
      }
    }
    out << std::endl << std::endl;
    out.close();
  }

  /**
  * Writes a .mesh file with all the cells
  *
  * Assumes that all potential cells are hexahedra!!
  * A "region id" equal to the first 2 decimals of the quality is given
  */
  void writeVectorCandidateCellsMeshFile(
    const HXTCombineCellArray& hexes,
    const TetMeshWrapper& tetMesh,
    std::ofstream& out)
  {
    out << "MeshVersionFormatted 2" << std::endl
      << "Dimension" << std::endl
      << "3" << std::endl << std::endl;

    out << "Vertices" << std::endl;
    out << tetMesh.nbVertices() << std::endl;
    for (unsigned int i = 0; i < tetMesh.nbVertices(); ++i) {
      const vec3& p = tetMesh.point(i);
      out << p[0] << "  " << p[1] << "  " << p[2] << "  " << "0" << std::endl;
    }
    out << std::endl;

    out << "Hexahedra" << std::endl << hexes.size() << std::endl;

    for (unsigned int i = 0; i < hexes.size(); ++i) {
      out << hexes[i] << " "<< 0 << std::endl;
    }
    out << std::endl;

    out.close();
  }

} // namespace

