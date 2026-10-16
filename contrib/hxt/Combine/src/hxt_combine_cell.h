#ifndef HXT_COMBINE_CELL_STRUCTURE_
#define HXT_COMBINE_CELL_STRUCTURE_

#include "hxt_message.h"

#include "basic_types.h"
#include "cell_types.h"
#include <string.h>

#include <array>
#include <vector>

/**
* \file hxt_combine_cell.h Declaration of the structure holding a tet combination.
* \author Jeanne Pellerin
*/

namespace HXTCombine{

/**
 * \addtogroup Combine
 * @{
 */

/**
 * CombineCell is a combination of tetrahedra of Mesh 
 * that define a hexahedron, or a prism, or a pyramid.
 * 
 * It refers to the indices of the vertices and tetrahedra in the Mesh, held
 * by an HXTCombineCellArray: it is a view, valid until the array changes.
 * Tets are separated between interior and boundary tets.
 * Boundary tets connect 4 vertices in the same cell quad facet.
*/
struct HXTCombineCell {
  HXTIndex numVertices;
  HXTIndex numInteriorTets;
  HXTIndex numBoundaryTets;
  const HXTIndex* vertexes;
  const HXTIndex* interiorTetrahedra;
  const HXTIndex* boundaryTetrahedra;

  HXTCombineCell(
    const HXTIndex* inputVertices, HXTIndex inputNbVertices,
    const HXTIndex* inputInteriorTets, HXTIndex inputNbInteriorTets,
    const HXTIndex* inputBoundaryTets, HXTIndex inputNbBoundaryTets
  ) :
    numVertices(inputNbVertices), numInteriorTets(inputNbInteriorTets),
    numBoundaryTets(inputNbBoundaryTets), vertexes(inputVertices),
    interiorTetrahedra(inputInteriorTets), boundaryTetrahedra(inputBoundaryTets)
  {}

  HXTIndex nbVertices() const { return numVertices; }
  const HXTIndex* vertices() const { return vertexes; }
  HXTIndex vertex(HXTIndex hexVertexIndex) const { return vertexes[hexVertexIndex]; }
  bool hasVertex(HXTIndex vertexIndex) const {
    for (HXTIndex i = 0; i < numVertices; ++i) {
      if (vertexes[i] == vertexIndex) return true;
    }
    return false;
  }

  bool isHex() const { return numVertices == 8; }
  bool isPrism() const { return numVertices == 6; }
  bool isPyramid() const { return numVertices == 5; }

  const HXTIndex* interiorTets() const { return interiorTetrahedra; }
  const HXTIndex* boundaryTets() const { return boundaryTetrahedra; }
  HXTIndex nbInteriorTets() const { return numInteriorTets; }
  HXTIndex nbBoundaryTets() const { return numBoundaryTets; }

  bool hasInteriorTet(HXTIndex tetIndex) const {
    for (HXTIndex i = 0; i < numInteriorTets; ++i) {
      if (interiorTetrahedra[i] == tetIndex) return true;
    }
    return false;
  }
  bool hasBoundaryTet(HXTIndex tetIndex) const {
    for (HXTIndex i = 0; i < numBoundaryTets; ++i) {
      if (boundaryTetrahedra[i] == tetIndex) return true;
    }
    return false;
  }
  bool hasTet(HXTIndex tetIndex) const {
    return hasInteriorTet(tetIndex) || hasBoundaryTet(tetIndex);
  }
  HXTIndex tet(unsigned int localTetIndex) const {
    if (localTetIndex < nbInteriorTets()) return interiorTetrahedra[localTetIndex];
    else return boundaryTetrahedra[localTetIndex-nbInteriorTets()];
  }
};

/**
 * The cells of a type, one after the other in one array: the vertices, the
 * interior tets and the boundary tets of each, 7 tets for an average hex
 * candidate (from 5 to 13), with its offset and its 3 counts. Half the 140
 * bytes per hex of fixed-size arrays, the third for a prism, and a cell is
 * read in one or two cache lines.
 */
class HXTCombineCellArray {
public:
  HXTCombineCellArray() : start_(1, 0) {}

  std::size_t size() const { return counts_.size(); }
  bool empty() const { return counts_.empty(); }

  HXTCombineCell operator[](std::size_t c) const {
    const HXTIndex* v = data_.data() + start_[c];
    const unsigned int nv = counts_[c].nbVertices, ni = counts_[c].nbInteriorTets;
    return HXTCombineCell(v, nv, v + nv, ni, v + nv + ni,
                          counts_[c].nbBoundaryTets);
  }

  void push_back(const HXTIndex* vertices, unsigned int nbVertices,
                 const HXTIndex* interiorTets, unsigned int nbInteriorTets,
                 const HXTIndex* boundaryTets, unsigned int nbBoundaryTets) {
    data_.insert(data_.end(), vertices, vertices + nbVertices);
    data_.insert(data_.end(), interiorTets, interiorTets + nbInteriorTets);
    data_.insert(data_.end(), boundaryTets, boundaryTets + nbBoundaryTets);
    start_.push_back(data_.size());
    counts_.push_back({(unsigned char)nbVertices, (unsigned char)nbInteriorTets,
                       (unsigned char)nbBoundaryTets});
  }
  void push_back(const HXTCombineCell& cell) {
    push_back(cell.vertexes, cell.numVertices, cell.interiorTetrahedra,
              cell.numInteriorTets, cell.boundaryTetrahedra, cell.numBoundaryTets);
  }
  // the cells of more after these
  void append(const HXTCombineCellArray& more) {
    reserve(size() + more.size(), data_.size() + more.data_.size());
    const std::size_t offset = data_.size();
    data_.insert(data_.end(), more.data_.begin(), more.data_.end());
    for (std::size_t c = 1; c < more.start_.size(); ++c)
      start_.push_back(offset + more.start_[c]);
    counts_.insert(counts_.end(), more.counts_.begin(), more.counts_.end());
  }
  // exactly, not to a power of 2 of the current sizes
  void reserve(std::size_t nbCells, std::size_t nbIndices) {
    if (start_.capacity() < nbCells + 1) start_.reserve(nbCells + 1);
    if (counts_.capacity() < nbCells) counts_.reserve(nbCells);
    if (data_.capacity() < nbIndices) data_.reserve(nbIndices);
  }
  void clear() {
    start_.assign(1, 0);
    counts_.clear();
    data_.clear();
  }
  void shrink_to_fit() {
    start_.shrink_to_fit();
    counts_.shrink_to_fit();
    data_.shrink_to_fit();
  }
  void swap(HXTCombineCellArray& other) {
    start_.swap(other.start_);
    counts_.swap(other.counts_);
    data_.swap(other.data_);
  }
  std::size_t nbIndices() const { return data_.size(); }
  std::size_t memoryBytes() const {
    return start_.capacity() * sizeof(start_[0]) +
           counts_.capacity() * sizeof(counts_[0]) +
           data_.capacity() * sizeof(data_[0]);
  }

  class const_iterator {
  public:
    const_iterator(const HXTCombineCellArray* array, std::size_t c) : array_(array), c_(c) {}
    HXTCombineCell operator*() const { return (*array_)[c_]; }
    const_iterator& operator++() { ++c_; return *this; }
    bool operator!=(const const_iterator& other) const { return c_ != other.c_; }
  private:
    const HXTCombineCellArray* array_;
    std::size_t c_;
  };
  const_iterator begin() const { return const_iterator(this, 0); }
  const_iterator end() const { return const_iterator(this, size()); }

private:
  struct Counts {
    unsigned char nbVertices, nbInteriorTets, nbBoundaryTets;
  };
  std::vector<std::size_t> start_; // nbCells + 1
  std::vector<Counts> counts_;
  std::vector<HXTIndex> data_;
};


/** Output the vertices of the hex in the stream.
* Vertex indices are incremented for the .mesh format
*/
inline std::ostream& operator<< (std::ostream& out, const HXTCombineCell& cell) {
  for (unsigned int i = 0; i < cell.nbVertices(); ++i) {
    out << cell.vertex(i)+1 << " ";
  }
  return out;
}

// Set of template functions to access and find elements of a cell
// These functions can be accelerated by pre-computing 
// for each type of cell tables mapping the vertices to the edges/faces in the cells
// Removed for now as it complicates the code and does not really improve performances.

template<class T>
inline bindex cellEdge(const HXTCombineCell& cell, CellEdgeIndex e)
{
  VertexIndex v0 = cell.vertex(T::edgeVertex[e][0]);
  VertexIndex v1 = cell.vertex(T::edgeVertex[e][1]);
  return bindex(v0, v1);
}

template<class T>
inline CellEdgeIndex findCellEdge(const HXTCombineCell& cell, const bindex& inputEdge)
{
  for (CellEdgeIndex i = 0; i < T::nbEdges; ++i) {
    if (cellEdge<T>(cell, i) == inputEdge) return i;
  }
  return NO_ID;
}

template<class T>
inline CellFacetIndex findCellFacet(const HXTCombineCell& cell, const quadindex& inputFacet)
{
  for (CellFacetIndex f = T::nbTriFacets; f < T::nbFacets; ++f) {
    quadindex hexFacet(
      cell.vertex(T::facetVertex[f][0]),
      cell.vertex(T::facetVertex[f][1]),
      cell.vertex(T::facetVertex[f][2]),
      cell.vertex(T::facetVertex[f][3]));
    if (hexFacet == inputFacet) return f;
  }
  return NO_ID;
}

template<class T>
inline CellFacetIndex findCellFacet(const HXTCombineCell& cell, const trindex& inputFacet) {
  for (CellFacetIndex f = 0; f < T::nbTriFacets; ++f) {
    trindex facet(
      cell.vertex(T::facetVertex[f][0]),
      cell.vertex(T::facetVertex[f][1]),
      cell.vertex(T::facetVertex[f][2]));
    if (facet == inputFacet) return f;
  }
  return NO_ID;
}
  
template<class T>
inline bindex quadFacetDiagonal(const HXTCombineCell& cell, unsigned int d)
{
  VertexIndex v0 = cell.vertex(T::quadFacetDiagonalVertex[d][0]);
  VertexIndex v1 = cell.vertex(T::quadFacetDiagonalVertex[d][1]);
  return bindex(v0, v1);
}

inline bool isEdge(const HXTCombineCell& cell, const bindex& edge)  {
  if      (cell.isHex())     return findCellEdge<Hex>    (cell, edge) != NO_ID;
  else if (cell.isPrism())   return findCellEdge<Prism>  (cell, edge) != NO_ID;
  else if (cell.isPyramid()) return findCellEdge<Pyramid>(cell, edge) != NO_ID;
  else return false;
}

inline bool isQuadFacet(const HXTCombineCell& cell, const quadindex& facet) {
  if      (cell.isHex())     return findCellFacet<Hex>    (cell, facet) != NO_ID;
  else if (cell.isPrism())   return findCellFacet<Prism>  (cell, facet) != NO_ID;
  else if (cell.isPyramid()) return findCellFacet<Pyramid>(cell, facet) != NO_ID;
  else return false;
}

inline bool isTriFacet(const HXTCombineCell& cell, const trindex& facet) {
  if      (cell.isPrism())   return findCellFacet<Prism>  (cell, facet) != NO_ID;
  else if (cell.isPyramid()) return findCellFacet<Pyramid>(cell, facet) != NO_ID;
  else return false;
}


inline VertexIndex firstSharedVertex(const HXTCombineCell& cell0, const HXTCombineCell& cell1) {
  for (CellVertexIndex i = 0; i < cell0.nbVertices(); ++i) {
    for (CellVertexIndex j = 0; j < cell1.nbVertices(); ++j) {
      if (cell0.vertex(i) == cell1.vertex(j)) return cell0.vertex(i);
    }
  }
  return NO_ID;
}

inline bool shareOneInteriorTet(const HXTCombineCell& cell0, const HXTCombineCell& cell1)  {
  unsigned int i0 = 0, i1 = 0;
  while (i0!=cell0.numInteriorTets && i1!=cell1.numInteriorTets) {
    unsigned int t0 = cell0.interiorTetrahedra[i0];
    unsigned int t1 = cell1.interiorTetrahedra[i1];
    if (t0 < t1) ++i0;
    else if (t1 < t0) ++i1;
    else return true;
  }
  return false;
}

inline CellVertexIndex findCellVertex(const HXTCombineCell& cell, VertexIndex v) {
  for (CellVertexIndex i = 0; i < cell.nbVertices(); i++) {
    if (cell.vertexes[i] == v) return i;
  }
  return NO_ID;
}

inline void sharedVertices(
  const HXTCombineCell& cell0,
  const HXTCombineCell& cell1,
  VertexIndex common[8],
  CellVertexIndex idsCommon0[8],
  CellVertexIndex idsCommon1[8],
  unsigned int& nbCommon)
{
  nbCommon = 0;
  for (CellVertexIndex i = 0; i < cell0.nbVertices(); ++i) {
    VertexIndex v = cell0.vertexes[i];

    CellVertexIndex j = findCellVertex(cell1, v);

    common[nbCommon] = v;
    idsCommon0[nbCommon] = i;
    idsCommon1[nbCommon] = j;

    if (j != NO_ID) nbCommon++;
  }
}

inline void sharedVertices(
  VertexIndex *common, unsigned int &nbCommon,
  const HXTCombineCell& cell0, const HXTCombineCell& cell1)
{
  nbCommon = 0;
  for (CellVertexIndex i = 0; i < cell0.nbVertices(); ++i) {
    for (CellVertexIndex j = 0; j < cell1.nbVertices(); ++j) {
      if (cell0.vertex(i) == cell1.vertex(j)) {
        common[nbCommon++] = cell0.vertex(i);
        break;
      }
    }
  }
}


/** Two hexes/prisms/pyramids are not compatible if they
*  - share 1 interior tet
*  - share more than 4 vertices
*  - share 3 vertices that do not match a facet in both cells
*  - share 2 vertices that do not match one edge in both cells
*  - share 4 vertices that do not match a facet in both cells
*/
inline bool areCellsCompatible(const HXTCombineCell& c0, const HXTCombineCell& c1) {
  if (shareOneInteriorTet(c0, c1)) return false;
  else {
    VertexIndex commonVertices[8];
    unsigned int nbCommonVertices=0;
    sharedVertices(commonVertices, nbCommonVertices, c0, c1);

    if (nbCommonVertices < 2 ) return true;
    else if (nbCommonVertices == 2) {
      bindex edge(commonVertices[0], commonVertices[1]);
      if (!isEdge(c0, edge)) return false;
      else if (!isEdge(c1, edge)) return false;
      else return true;
    }
    else if (nbCommonVertices == 3) {
      if (c0.isHex() || c1.isHex()) return false;
      else {
        trindex facet(commonVertices[0], commonVertices[1], commonVertices[2]);
        if (!isTriFacet(c0, facet)) return false;
        else if (!isTriFacet(c1, facet)) return false;
        else return true;
      }
    }
    else if (nbCommonVertices == 4) {
      quadindex facet(commonVertices[0], commonVertices[1], commonVertices[2], commonVertices[3]);
      if (!isQuadFacet(c0, facet)) return false;
      else if (!isQuadFacet(c1, facet)) return false;
      else return true;
    }
    else return false;
  }
}

/**
* @}
*/

}

#endif
