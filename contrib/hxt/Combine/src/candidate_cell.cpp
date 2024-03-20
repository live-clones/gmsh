#include "candidate_cell.h"

#include <cassert>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

#include "basic_types.h"
#include "cell_types.h"
#include "hxt_combine_cell.h"

/**
* \author Jeanne Pellerin
*/

namespace HXTCombine {

static void computeOrderedVertices(const HXTCombineCell& cell, vector<VertexIndex>& orderedVertices)
{
  const VertexIndex *cellVertices = cell.vertices();
  orderedVertices.resize(cell.nbVertices());
  vector<CellVertexIndex> permutation;
  if (cell.isHex()) {
    computeHexVertexNormalizationPermutation(cellVertices, permutation);
  }
  else if (cell.isPrism()) {
    computePrismVertexNormalizationPermutation(cellVertices, permutation);
  }
  else if (cell.isPyramid()) {
    std::cout << " Normalization of pyramid vertex order is not implemented yet !  " << std::endl;
    return;
  }
  for (unsigned int i = 0; i < permutation.size(); ++i) {
    assert(permutation[i] != NO_ID);
    orderedVertices[i] = cellVertices[permutation[i]];
  }
}

/**
* Comparator < of HXTCombineCells based on their normalized vertex order 
*/
class ComparatorCellVertices {
private:
  const std::vector<HXTCombineCell>& cells_;
  const std::vector<vector<VertexIndex>>& orderedVertices_;
  
public:
  ComparatorCellVertices(const std::vector<HXTCombineCell>& cells,
    const std::vector<vector<VertexIndex>>& orderedVertices)
    :cells_(cells), orderedVertices_(orderedVertices)
  {}
  bool operator()(CellIndex h0, CellIndex h1) const
  {
    const vector<VertexIndex>& v0 = orderedVertices_[h0];
    const vector<VertexIndex>& v1 = orderedVertices_[h1];

    if (v0.size() != v1.size()) return v0.size() < v1.size();
    for (CellVertexIndex i = 0; i < v0.size(); ++i) {
      if (v0[i] != v1[i]) return v0[i] < v1[i];
    }
    return false;
  }
};

/**
* Equality test of HXTCombineCells based on their normalized vertex order
*/
struct EqualCellVertices {
private:
  const std::vector<HXTCombineCell>& cells_;
  const std::vector<vector<VertexIndex>>& orderedVertices_;

public:
  EqualCellVertices(
    const std::vector<HXTCombineCell>& cells,
    const std::vector<vector<VertexIndex>>& orderedVertices) 
    :cells_(cells), orderedVertices_(orderedVertices)
  {}
  bool operator()(CellIndex h0, CellIndex h1) const {
    const vector<VertexIndex>& v0 = orderedVertices_[h0];
    const vector<VertexIndex>& v1 = orderedVertices_[h1];

    if (v0.size() != v1.size()) return false;
    for (CellVertexIndex i = 0; i < v0.size(); ++i) {
      if (v0[i] != v1[i]) return false;
    }
    return true;
  }
};


void uniqueCells(const vector<HXTCombineCell>& cells, vector<unsigned int>& indices)
{
  size_t nb = cells.size();
  indices.resize(nb);
  for (size_t i = 0; i < nb; ++i)
    indices[i] = i;
  
  if (nb < 2) return;

  std::vector<vector<VertexIndex>> orderedVertices(cells.size());
  for (unsigned int i = 0; i < cells.size(); ++i) {
    computeOrderedVertices(cells[i], orderedVertices[i]);
  }
  ComparatorCellVertices comparator(cells, orderedVertices);
  EqualCellVertices areEqual(cells, orderedVertices);
  std::sort(indices.begin(), indices.end(), comparator);
  auto newEnd = std::unique(indices.begin(), indices.end(), areEqual);
  size_t newNb = std::distance(indices.begin(), newEnd);
  indices.resize(newNb);
}


// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

bool CandidateCell::isOnCellBoundary(const bindex& edge) const {
  for (unsigned int i = 0; i < numBoundary_; ++i) {
    const TetFacet& cur = boundary_[i];
    const trindex& facet = tetMesh_.tetFacet(cur.first, cur.second);
    if ( edge == bindex(facet.indices[0], facet.indices[1])
      || edge == bindex(facet.indices[0], facet.indices[2])
      || edge == bindex(facet.indices[1], facet.indices[2]))
      return true;
  }
  return false;
}

}
