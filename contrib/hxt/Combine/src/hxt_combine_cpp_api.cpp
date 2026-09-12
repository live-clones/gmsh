#include "hxt_combine_cpp_api.h"

#include <array>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>

#include "basic_types.h"
#include "cell_types.h"
#include "tet_mesh.h"

//#include <hxt_omp.h>

/**
* \author Jeanne Pellerin
*/

namespace {
  using namespace HXTCombine;

  struct CompareCells {
    CompareCells(
      const std::vector<HXTCombineCell>& cells,
      const double* cellQualities) :
      cells_(cells), quality_(cellQualities)
    {}
    /**
    * If cells are of different type order hex > prisms > pyramids
    * else compare qualities
    */
    bool operator()(CellIndex h0, CellIndex h1) const {
      if (cells_[h0].nbVertices() == cells_[h1].nbVertices())
        return quality_[h0] > quality_[h1];
      else return cells_[h0].nbVertices() > cells_[h1].nbVertices();
    }
  private:
    const std::vector<HXTCombineCell>& cells_;
    const double* quality_;
  };

  /**
  * Sorts the cells indices according to their quality. Returns the ordered cell indices.
  */
  std::vector<CellIndex> orderCellDecreasingQuality(
    const std::vector<HXTCombineCell>& cells, const double* cellQualities)
  {
    std::vector<CellIndex> order(cells.size(), NO_ID);
    CompareCells compare(cells, cellQualities);
    for (unsigned int i = 0; i < cells.size(); ++i) order[i] = i;
    std::sort(order.begin(), order.end(), compare);
    return order;
  }

  class CellGreedySelection {
  public:
    static constexpr CellIndex NO_CELL = (CellIndex)-1;

    CellGreedySelection(const TetMeshWrapper& tets)
      :tetOwner_(tets.nbTets(), NO_CELL),
      vertexRefCount_(tets.nbVertices(), 0)
    {}

    /**
    * \pre selected is allocated.
    * It is assumed that already selected cells where so by the same instance of the Selector.
    */
    void computeCompatibleCellCombination(
      const vector<HXTCombineCell>& cells,
      const double* cellQualities,
      vector<bool>& selected)
    {
      frontalSelection(cells, cellQualities, selected);

      localSearchImprove(cells, cellQualities, selected);
    }

  private:
    /**
    * Canonical key for a hex's quad facet: its 4 global vertex indices,
    * sorted -- two hexes on either side of the same face produce the
    * same key, which is exactly the face-adjacency relation a frontal
    * growth strategy needs.
    */
    typedef std::array<VertexIndex, 4> FacetKey;

    static FacetKey hexFacetKey(const HXTCombineCell& cell, unsigned int f)
    {
      FacetKey k = {{ cell.vertex(Hex::facetVertex[f][0]),
                     cell.vertex(Hex::facetVertex[f][1]),
                     cell.vertex(Hex::facetVertex[f][2]),
                     cell.vertex(Hex::facetVertex[f][3]) }};
      std::sort(k.begin(), k.end());
      return k;
    }

    /**
    * Frontal cell selection: rather than sorting every candidate by
    * quality globally and scanning (which happily jumps to the next best
    * cell anywhere in the domain, with no notion of spatial continuity),
    * grow selected regions like the point-insertion frontal advance
    * does: seed with the best remaining candidate, then only consider
    * candidates that are face-adjacent to what has already been
    * selected, picking the best one available in that active front at
    * each step; re-seed globally only once a front is fully exhausted.
    * Currently scoped to hexes (the only cell type this store's caller
    * enables here); non-hex cells fall back to being handled entirely by
    * the trailing quality-sorted scan below, same as before.
    */
    void frontalSelection(
      const vector<HXTCombineCell>& cells,
      const double* cellQualities,
      vector<bool>& selected)
    {
      std::unordered_map<size_t, std::vector<CellIndex> > facetToCells;
      auto keyHash = [](const FacetKey& k) {
        size_t h = 1469598103934665603ull;
        for(VertexIndex v : k) { h ^= v; h *= 1099511628211ull; }
        return h;
      };
      for (CellIndex c = 0; c < cells.size(); ++c) {
        if (!cells[c].isHex()) continue;
        for (unsigned int f = 0; f < 6; ++f)
          facetToCells[keyHash(hexFacetKey(cells[c], f))].push_back(c);
      }

      std::vector<CellIndex> globalOrder =
        orderCellDecreasingQuality(cells, cellQualities);
      std::size_t nextSeed = 0;
      std::vector<bool> resolved(cells.size(), false);

      auto qualityCmp = [&](CellIndex a, CellIndex b) {
        return cellQualities[a] < cellQualities[b]; // priority_queue: max on top
      };
      std::priority_queue<CellIndex, std::vector<CellIndex>,
        decltype(qualityCmp)> front(qualityCmp);

      auto pushNeighbors = [&](CellIndex c) {
        if (!cells[c].isHex()) return;
        for (unsigned int f = 0; f < 6; ++f) {
          auto it = facetToCells.find(keyHash(hexFacetKey(cells[c], f)));
          if (it == facetToCells.end()) continue;
          for (CellIndex nb : it->second)
            if (nb != c && !resolved[nb]) front.push(nb);
        }
      };

      while (true) {
        while (front.empty() && nextSeed < globalOrder.size()) {
          CellIndex s = globalOrder[nextSeed++];
          if (!resolved[s] && !selected[s]) front.push(s);
        }
        if (front.empty()) break;

        CellIndex c = front.top();
        front.pop();
        if (resolved[c]) continue;
        resolved[c] = true;

        if (!cells[c].isHex()) continue; // let the trailing scan handle it
        if (isCellCompatible(cells[c])) {
          selected[c] = true;
          addCellCompatibilityConstraints(cells[c], c);
          pushNeighbors(c);
        }
      }

      // Non-hex candidates (or anything skipped above) still get the
      // original quality-sorted scan, unaffected by the above.
      for (unsigned int i = 0; i < globalOrder.size(); ++i) {
        CellIndex cellId = globalOrder[i];
        if (selected[cellId] || cells[cellId].isHex()) continue;
        if (isCellCompatible(cells[cellId])) {
          selected[cellId] = true;
          addCellCompatibilityConstraints(cells[cellId], cellId);
        }
      }
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
    * put the original cell back exactly as it was.
    */
    void localSearchImprove(
      const vector<HXTCombineCell>& cells,
      const double* cellQualities,
      vector<bool>& selected)
    {
      if (cells.empty()) return;

      // Reverse indices: for a given interior tet / vertex, which
      // (currently unselected, at build time) candidate cells touch it.
      // Built once, used to bound each ejection's re-fill search to the
      // handful of candidates that could plausibly be affected, instead
      // of rescanning all cells.
      std::vector<std::vector<CellIndex> > tetToCells(tetOwner_.size());
      std::vector<std::vector<CellIndex> > vertexToCells(vertexRefCount_.size());
      for (CellIndex c = 0; c < cells.size(); ++c) {
        const HXTCombineCell& cell = cells[c];
        for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i)
          tetToCells[cell.interiorTetrahedra[i]].push_back(c);
        for (unsigned int i = 0; i < cell.nbVertices(); ++i)
          vertexToCells[cell.vertexes[i]].push_back(c);
      }

      std::vector<CellIndex> selectedList;
      for (CellIndex c = 0; c < cells.size(); ++c)
        if (selected[c]) selectedList.push_back(c);
      // Try ejecting the worst-quality selected cells first: they are the
      // ones most likely to be worth trading away.
      std::sort(selectedList.begin(), selectedList.end(),
        [&](CellIndex a, CellIndex b) {
          return cellQualities[a] < cellQualities[b];
        });

      std::set<CellIndex> pool;
      std::vector<CellIndex> poolSorted, added;
      for (CellIndex s : selectedList) {
        if (!selected[s]) continue; // already ejected for good by an earlier swap
        const HXTCombineCell& cellS = cells[s];

        pool.clear();
        for (unsigned int i = 0; i < cellS.nbInteriorTets(); ++i)
          for (CellIndex c : tetToCells[cellS.interiorTetrahedra[i]])
            if (!selected[c]) pool.insert(c);
        for (unsigned int i = 0; i < cellS.nbVertices(); ++i)
          for (CellIndex c : vertexToCells[cellS.vertexes[i]])
            if (!selected[c]) pool.insert(c);
        if (pool.empty()) continue; // ejecting s cannot unlock anything

        removeCellCompatibilityConstraints(cellS, s);
        selected[s] = false;

        poolSorted.assign(pool.begin(), pool.end());
        std::sort(poolSorted.begin(), poolSorted.end(),
          [&](CellIndex a, CellIndex b) {
            return cellQualities[a] > cellQualities[b];
          });

        added.clear();
        for (CellIndex c : poolSorted) {
          if (selected[c]) continue;
          if (isCellCompatible(cells[c])) {
            selected[c] = true;
            addCellCompatibilityConstraints(cells[c], c);
            added.push_back(c);
          }
        }

        if (added.size() >= 2) {
          // net gain: keep s ejected and the newly added cells selected
        }
        else {
          for (CellIndex c : added) {
            removeCellCompatibilityConstraints(cells[c], c);
            selected[c] = false;
          }
          selected[s] = true;
          addCellCompatibilityConstraints(cellS, s);
        }
      }
    }

    /** Check that the input cell is compatible with
    * all the already selected cells.
    *
    * A lot of invalid configurations are discarded implicitely.
    * No need to check triangular facets againt quad facets, because the
    * check of their edges against the diagonals is sufficient.
    */
    bool isCellCompatible(const HXTCombineCell& cell) const
    {
      if (oneInteriorTetSelected(cell)) return false;

      unsigned int nbCommonVertices = numberSelectedVertices(cell);
      if (nbCommonVertices < 2) return true;
      else {
        if (!checkEdgesAgainstDiagonals(cell)) return false;
        if (!checkDiagonalsAgainstEdges(cell)) return false;
        if (!checkDiagonalsAgainstDiagonals(cell)) return false;
        if (nbCommonVertices > 2) {
          // Does this test really discard things ? 
          // REdundant ewith diagonal test ?
          // seems that it is most of the time.. not with pyramids ? non convex positions ?

          // once on prism
          return checkQuadFacetsAgainstQuadFacets(cell);
        }
        else return true;
      }
    }

    bool oneInteriorTetSelected(const HXTCombineCell& cell) const {
      for (unsigned int i = 0; i < cell.nbInteriorTets(); ++i) {
        if (tetOwner_[cell.interiorTetrahedra[i]] != NO_CELL) return true;
      }
      return false;
    }

    unsigned int numberSelectedVertices(const HXTCombineCell& cell) const {
      unsigned int nb = 0;
      for (unsigned int i = 0; i < cell.nbVertices(); ++i) {
        if (vertexRefCount_[cell.vertexes[i]] > 0) nb++;
      }
      return nb;
    }

    /**
    * \brief Returns true if all the quad facets are compatible with the already built quad facets
    * \details Check that all or none of the 4 triangles defined in the quad facet are stored.
    */
    template<class T>
    inline bool checkQuadFacetsAgainstQuadFacets(const HXTCombineCell& cell) const {
      for (CellFacetIndex f = 0; f < T::nbQuadFacets; ++f) {
        unsigned int nb = 0;
        for (unsigned int t = 0; t < 4; ++t) {
          VertexIndex v0 = cell.vertex(T::quadFacetTriangleVertex[4*f+t][0]);
          VertexIndex v1 = cell.vertex(T::quadFacetTriangleVertex[4*f+t][1]);
          VertexIndex v2 = cell.vertex(T::quadFacetTriangleVertex[4*f+t][2]);
          trindex curTriangle(v0, v1, v2);
          if (facetTriangles_.count(curTriangle)) nb++;
        }
        if (nb!= 0 && nb != 4) return false;
      }
      return true;
    }

    template<class T>
    inline bool checkEdgesAgainstDiagonals(const HXTCombineCell& cell) const
    {
      for (CellEdgeIndex e = 0; e < T::nbEdges; ++e) {
        bindex curEdge = cellEdge<T>(cell, e);
        if (facetDiagonals_.count(curEdge) == 1) return false;
      }
      return true;
    }

    /**
    * Check that all quad facet diagonals are not edges of the already built cell edges,
    * and that both diagonals exist at the same time.
    */
    template<class T>
    bool checkDiagonalsAgainstEdges(const HXTCombineCell& cell) const
    {
      for (CellFacetIndex f = 0; f < 2*T::nbQuadFacets; ++f) {
        bindex diagonal = quadFacetDiagonal<T>(cell, f);
        if (edges_.count(diagonal) == 1) return false;
      }
      return true;
    }

    /**
    * Checks that is a diagonal of quadrilateral facet exist the other one
    * exist too.
    * In other words, checks that if an existing quadrilateral has this diagonal
    * it is the same quadrilateral facet.
    */
    template<class T>
    bool checkDiagonalsAgainstDiagonals(const HXTCombineCell& cell) const
    {
      for (CellFacetIndex f = 0; f < T::nbQuadFacets; ++f) {
        bindex diagonal0 = quadFacetDiagonal<T>(cell, 2*f);
        bindex diagonal1 = quadFacetDiagonal<T>(cell, 2*f+1);
        bool found0 = facetDiagonals_.count(diagonal0) == 1;
        bool found1 = facetDiagonals_.count(diagonal1) == 1;

        if (found0 != found1) return false;
      }
      return true;
    }

    inline bool checkQuadFacetsAgainstQuadFacets(const HXTCombineCell& cell) const
    {
      if (cell.isHex())     return checkQuadFacetsAgainstQuadFacets<Hex>(cell);
      else if (cell.isPrism())   return checkQuadFacetsAgainstQuadFacets<Prism>(cell);
      else if (cell.isPyramid()) return checkQuadFacetsAgainstQuadFacets<Pyramid>(cell);
      else return false;
    }

    inline bool checkEdgesAgainstDiagonals(const HXTCombineCell& cell) const
    {
      if (cell.isHex())    return checkEdgesAgainstDiagonals<Hex>(cell);
      else if (cell.isPrism())  return checkEdgesAgainstDiagonals<Prism>(cell);
      else if (cell.isPyramid())return checkEdgesAgainstDiagonals<Pyramid>(cell);
      else return false;
    }

    bool checkDiagonalsAgainstEdges(const HXTCombineCell& cell) const
    {
      if (cell.isHex())     return checkDiagonalsAgainstEdges<Hex>(cell);
      else if (cell.isPrism())   return checkDiagonalsAgainstEdges<Prism>(cell);
      else if (cell.isPyramid()) return checkDiagonalsAgainstEdges<Pyramid>(cell);
      else return false;
    }

    bool checkDiagonalsAgainstDiagonals(const HXTCombineCell& cell) const
    {
      if (cell.isHex())     return checkDiagonalsAgainstDiagonals<Hex>(cell);
      else if (cell.isPrism())   return checkDiagonalsAgainstDiagonals<Prism>(cell);
      else if (cell.isPyramid()) return checkDiagonalsAgainstDiagonals<Pyramid>(cell);
      else return false;
    }

    /**
    * The Cell has been selected. Add its faces and edges as constraints for the following cells.
    */
    void addCellCompatibilityConstraints(const HXTCombineCell& cell, CellIndex id)
    {
      for (CellVertexIndex i = 0; i < cell.nbVertices(); ++i)
        vertexRefCount_[cell.vertexes[i]]++;

      for (CellTetIndex i = 0; i < cell.nbInteriorTets(); ++i)
        tetOwner_[cell.interiorTets()[i]] = id;

      addQuadFacetConstraints(cell);
      // Do not forget prisms triangular facets
      addEdgeConstraints(cell);
      addFacetDiagonalConstraints(cell);
    }

    /**
    * The reverse of addCellCompatibilityConstraints: undo exactly what
    * selecting this cell had added, so it (and only it) can be ejected
    * without disturbing any other still-selected cell that happens to
    * share a vertex/edge/diagonal with it.
    */
    void removeCellCompatibilityConstraints(const HXTCombineCell& cell, CellIndex id)
    {
      for (CellVertexIndex i = 0; i < cell.nbVertices(); ++i)
        vertexRefCount_[cell.vertexes[i]]--;

      for (CellTetIndex i = 0; i < cell.nbInteriorTets(); ++i) {
        TetIndex t = cell.interiorTets()[i];
        if (tetOwner_[t] == id) tetOwner_[t] = NO_CELL;
      }

      removeQuadFacetConstraints(cell);
      removeEdgeConstraints(cell);
      removeFacetDiagonalConstraints(cell);
    }

    template<class T>
    inline void addQuadFacetConstraints(const HXTCombineCell& cell)
    {
      for (unsigned int f = 0; f < 4*T::nbQuadFacets; ++f) {
        VertexIndex v0 = cell.vertex(T::quadFacetTriangleVertex[f][0]);
        VertexIndex v1 = cell.vertex(T::quadFacetTriangleVertex[f][1]);
        VertexIndex v2 = cell.vertex(T::quadFacetTriangleVertex[f][2]);
        facetTriangles_[trindex(v0, v1, v2)]++;
      }
    }
    template<class T>
    inline void addEdgeConstraints(const HXTCombineCell& cell) {
      for (CellEdgeIndex e = 0; e < T::nbEdges; ++e) {
        edges_[cellEdge<T>(cell, e)]++;
      }
    }

    template<class T>
    inline void addFacetDiagonalConstraints(const HXTCombineCell& cell) {
      for (unsigned int d = 0; d < 2*T::nbQuadFacets; ++d) {
        VertexIndex v0 = cell.vertex(T::quadFacetDiagonalVertex[d][0]);
        VertexIndex v1 = cell.vertex(T::quadFacetDiagonalVertex[d][1]);
        facetDiagonals_[bindex(v0, v1)]++;
      }
    }

    template<class Map, class Key>
    static inline void decrementAndErase(Map& m, const Key& k)
    {
      auto it = m.find(k);
      if (it == m.end()) return; // should not happen if add/remove stay paired
      if (--(it->second) <= 0) m.erase(it);
    }

    template<class T>
    inline void removeQuadFacetConstraints(const HXTCombineCell& cell)
    {
      for (unsigned int f = 0; f < 4*T::nbQuadFacets; ++f) {
        VertexIndex v0 = cell.vertex(T::quadFacetTriangleVertex[f][0]);
        VertexIndex v1 = cell.vertex(T::quadFacetTriangleVertex[f][1]);
        VertexIndex v2 = cell.vertex(T::quadFacetTriangleVertex[f][2]);
        decrementAndErase(facetTriangles_, trindex(v0, v1, v2));
      }
    }
    template<class T>
    inline void removeEdgeConstraints(const HXTCombineCell& cell) {
      for (CellEdgeIndex e = 0; e < T::nbEdges; ++e)
        decrementAndErase(edges_, cellEdge<T>(cell, e));
    }

    template<class T>
    inline void removeFacetDiagonalConstraints(const HXTCombineCell& cell) {
      for (unsigned int d = 0; d < 2*T::nbQuadFacets; ++d) {
        VertexIndex v0 = cell.vertex(T::quadFacetDiagonalVertex[d][0]);
        VertexIndex v1 = cell.vertex(T::quadFacetDiagonalVertex[d][1]);
        decrementAndErase(facetDiagonals_, bindex(v0, v1));
      }
    }

    void addQuadFacetConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return addQuadFacetConstraints<Hex>(cell);
      else if (cell.isPrism())   return addQuadFacetConstraints<Prism>(cell);
      else if (cell.isPyramid()) return addQuadFacetConstraints<Pyramid>(cell);
    }

    void addEdgeConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return addEdgeConstraints<Hex>(cell);
      else if (cell.isPrism())   return addEdgeConstraints<Prism>(cell);
      else if (cell.isPyramid()) return addEdgeConstraints<Pyramid>(cell);
    }

    void addFacetDiagonalConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return addFacetDiagonalConstraints<Hex>(cell);
      else if (cell.isPrism())   return addFacetDiagonalConstraints<Prism>(cell);
      else if (cell.isPyramid()) return addFacetDiagonalConstraints<Pyramid>(cell);
    }

    void removeQuadFacetConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return removeQuadFacetConstraints<Hex>(cell);
      else if (cell.isPrism())   return removeQuadFacetConstraints<Prism>(cell);
      else if (cell.isPyramid()) return removeQuadFacetConstraints<Pyramid>(cell);
    }

    void removeEdgeConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return removeEdgeConstraints<Hex>(cell);
      else if (cell.isPrism())   return removeEdgeConstraints<Prism>(cell);
      else if (cell.isPyramid()) return removeEdgeConstraints<Pyramid>(cell);
    }

    void removeFacetDiagonalConstraints(const HXTCombineCell& cell)
    {
      if (cell.isHex())     return removeFacetDiagonalConstraints<Hex>(cell);
      else if (cell.isPrism())   return removeFacetDiagonalConstraints<Prism>(cell);
      else if (cell.isPyramid()) return removeFacetDiagonalConstraints<Pyramid>(cell);
    }

  private:
    std::vector<CellIndex> tetOwner_;
    std::vector<int> vertexRefCount_;

    /**
    * \todo For very large meshes these sets are a bottleneck
    * An option is to have only visible facets of the selected cells.
    * Because for sure if we already have selected 2 hexes sharing a facet we can remove it from here.
    */
    std::map<trindex, int> facetTriangles_;
    std::map<bindex, int> facetDiagonals_;
    std::map<bindex, int> edges_;
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

  void HXTCombineCellStore::selectCellsGreedy(std::array<bool, nbCellTypes> flags)
  {
    CellGreedySelection selector(mesh_);

    // 1. Allocate the selected vectors
    for (unsigned int i = 0; i+1 < nbCellTypes; ++i) {
      selectedCells_[i].resize(cells_[i].size(), false);
    }
    // All the tets of the input mesh are by default selected
    selectedCells_[TET].resize(mesh_.nbTets(), true);

    for (unsigned int i = 0; i+1 < nbCellTypes; ++i) {
      std::vector<HXTCombineCell>& cells = cells_[i];
      std::vector<bool>& selected = selectedCells_[i];

      if (flags[i]) {
        std::vector<double> qualities(cells.size());
        computeCellQualityVector(mesh_, cells, qualities.data());

        selector.computeCompatibleCellCombination(cells, qualities.data(), selected);
        // TODO Pyramids should swallow all quad facets 
      }
      else {
        selected.resize(cells.size(), false);
      }
    }
    // How do we ensure conformity? How do we ensure that the whole volume is filled?
    // TODO To get a conformal mesh there should be no visible quad facet anymore

    // Let's now select the tets of the mesh that are not already taken
    if (flags[TET]) {
      std::vector<bool>& selected = selectedTets();
      for (unsigned int cellType = 0; cellType < 3; ++cellType) {
        const std::vector<HXTCombineCell>& curCells = cells_[cellType];
        for (unsigned int i = 0; i < curCells.size(); ++i) {
          if (!selectedCells_[cellType][i]) continue;
          const HXTCombineCell& cell = curCells[i];
          flagFalseIndices(selected, cell.nbBoundaryTets(), cell.boundaryTets());
          flagFalseIndices(selected, cell.nbInteriorTets(), cell.interiorTets());
        }
      }
    }
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
      const std::vector<HXTCombineCell>& cells = cells_[type];
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
    const vector<HXTCombineCell>& hexes,
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

