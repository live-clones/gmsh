#ifndef HXT_COMBINE_CANDIDATE_CELL_HEXTREME_
#define HXT_COMBINE_CANDIDATE_CELL_HEXTREME_

#include <vector>
#include <cassert>
#include <stack>
#include <set>
#include <array>

#include "basic_types.h"
#include "tet_mesh.h"
#include "hxt_combine_cell.h"

/**
* \file candidate_cell.h Internal structure building combination of tetrahedra 
*  in a tetrahedral mesh
* \author Jeanne Pellerin
*/

namespace HXTCombine {

/**
* \addtogroup Combine
* @{
*/

/**
  * Internal -- Generic combination of tetrahedra into a Hex - Pyramid - Prism
  *
  * \details Computes the subset of tets meshing the cell defined by a set of given points.
  * Determines the triangulation of the CandidateCell from its corner vertices.
  * Computes the tetrahedra inside the theoretical cell boundary, and the real boundary.
  */
class CandidateCell {
public:
  typedef std::pair<TetIndex, TetFacetIndex> TetFacet;

  CandidateCell(const vector<VertexIndex>& vertices,
    const TetMeshForCombining& tets
  ) :
    tetMesh_(tets), numVertices_(vertices.size())
  {
    for (unsigned int i = 0; i< vertices.size(); ++i)
      vertices_[i] = vertices[i];

    if (vertices.size() == 8) {
      computeInteriorAndBoundaryTets<Hex>(computeOneInteriorTet<Hex>());
      computeRealCellBoundary<Hex>();
    }
    else if (vertices.size() == 6) {
      computeInteriorAndBoundaryTets<Prism>(computeOneInteriorTet<Prism>());
      computeRealCellBoundary<Prism>();
    }
  }

  CandidateCell(
    const vector<VertexIndex>& vertices,
    TetIndex oneInteriorTet,
    const TetMeshForCombining& tets
  ) :
    tetMesh_(tets), numVertices_(vertices.size())
  {
    for (unsigned int i = 0; i< vertices.size(); ++i)
      vertices_[i] = vertices[i];

    if (vertices.size() == 5) {
      computeInteriorAndBoundaryTets<Pyramid>(oneInteriorTet);
      computeRealCellBoundary<Pyramid>();
    }
  }

  bool isHex() const { return numVertices_ == 8; }
  bool isPrism() const { return numVertices_ == 6; }
  bool isPyramid() const { return numVertices_ == 5; }

  inline bool checkTetsTopology() const
  {
    if (nbTets() == 0) return false;
    else if (isHex()) return nbInteriorTets() > 4 && nbTets() < 16;
    else if (isPrism()) return nbTets() > 2 && nbTets() < 7;
    else if (isPyramid()) return nbTets() == 2 || nbTets() == 3;
    else return false;
  }
  inline bool haveTetsSameColor() const
  {
    if (!tetMesh_.haveTetsColors()) return true;
    else {
      ColorIndex color0 = tetMesh_.tetColor(tet(0));
      for (unsigned int i = 1; i < nbTets(); ++i) {
        if (tetMesh_.tetColor(tet(i)) != color0) return false;
      }
      return true;
    }
  }
  inline bool checkQuadFacetColor() const
  {
    if (!tetMesh().hasColoredTriangles()) return true;
    else if (isHex())     return checkQuadFacetColor<Hex>();
    else if (isPrism())   return checkQuadFacetColor<Prism>();
    else if (isPyramid()) return checkQuadFacetColor<Pyramid>();
    else return false;
  }

  inline bool checkQuadFacetBoundary() const
  {
    if (isHex())          return checkQuadFacetBoundary<Hex>();
    else if (isPrism())   return checkQuadFacetBoundary<Prism>();
    else if (isPyramid()) return checkQuadFacetBoundary<Pyramid>();
    else return false;
  }

  unsigned int nbVertices() const { return numVertices_; }
  unsigned int nbTets() const { return nbInteriorTets() + nbBoundaryTets(); }
  unsigned int nbInteriorTets() const { return numInteriorTets_; }
  unsigned int nbBoundaryTets() const { return numBoundaryTets_; }
  unsigned int nbBoundary() const { return numBoundary_; }

  const VertexIndex* vertices() const { return vertices_; }
  const TetIndex* interiorTets() const { return interiorTets_; }
  const TetIndex* boundaryTets() const { return boundaryTets_; }
  const TetFacet* boundaryFacets() const { return boundary_; }

  VertexIndex vertex(CellVertexIndex v) const { return vertices_[v]; }
  TetIndex tet(CellTetIndex t) const {
    if (t < nbInteriorTets()) return interiorTets_[t];
    else if (t < nbTets()) return boundaryTets_[t-nbInteriorTets()];
    else { return NO_ID; assert(false); }
  }
  bool hasTet(TetIndex t) const { return hasInteriorTet(t) || hasBoundaryTet(t); }

  const TetMeshForCombining& tetMesh() const { return tetMesh_; }

  CellTetIndex tetLocalIndex(TetIndex t) const {
    for (CellTetIndex i = 0; i < nbTets(); ++i) {
      if (tet(i) == t) return i;
    }
    return NO_ID;
  }

  bool isCellVertex(VertexIndex v) const {
    for (CellVertexIndex i = 0; i < numVertices_; ++i) {
      if (vertices_[i] == v) return true;
    }
    return false;
  }
  /** \return true if the 4 tet vertices are points of one cell quad facets */
  template<class T>
  inline bool isTetInBoundary(TetIndex t) const;

  bool isTetInBoundary(TetIndex t) const {
    if      (isHex())     return isTetInBoundary<Hex>(t);
    else if (isPrism())   return isTetInBoundary<Prism>(t);
    else if (isPyramid()) return isTetInBoundary<Pyramid>(t);
    else return false;
  }

  bool isOnCellBoundary(const bindex& edge) const;

  HXTCombineCell createCombineCell() const
  {
    return HXTCombineCell(
      vertices_, numVertices_,
      interiorTets_, numInteriorTets_,
      boundaryTets_, numBoundaryTets_);
  }

  /**
  * \name To be removed ultimately -- used to compare to pattern matching methods
  * @{
  */
  unsigned int countNumberOfTetsWithXNeighbors(unsigned int X) const
  {
    // Adjacency graph in this cell
    vector<vector<bool>> adjacentTets;
    size_t n = nbInteriorTets();
    adjacentTets.resize(n, vector<bool>(n));
    for (unsigned int i = 0; i < n; i++) {
      for (unsigned int j = 0; j < n; j++) {
        adjacentTets[i][j] = areAdjacent(tet(i), tet(j));
      }
    }
    unsigned int counter = 0;
    for (unsigned int i = 0; i < adjacentTets.size(); ++i) {
      if (std::count(adjacentTets[i].begin(), adjacentTets[i].end(), true) == X)
        counter++;
    }
    return counter;
  }
  bool isCubeDecomposition() const
  {
    if (!isHex()) return false;
    if (nbInteriorTets() > 4 && nbInteriorTets() < 7) return true;
    else return false;
  }
  bool isBotellaDecomposition() const
  {
    if (!isHex()) return false;
    if (isCubeDecomposition()) return true;
    if (nbInteriorTets() != 7) return false;
    else {
      if (countNumberOfTetsWithXNeighbors(4) == 1) return true;
      else return false;;
    }
  }
  bool isYamakawaDecomposition() const
  {
    if (!isHex()) return false;
    if (nbInteriorTets() != 0 && nbInteriorTets() < 8) return true;
    else return countNumberOfTetsWithXNeighbors(1) > 0;
  }
  /*
  * @}
  */

private:
  bool hasInteriorTet(TetIndex t) const {
    for (CellTetIndex i = 0; i < numInteriorTets_; ++i) {
      if (interiorTets_[i] == t) return true;
    }
    return false;
  }
  bool hasBoundaryTet(TetIndex t) const {
    for (CellTetIndex i = 0; i < numBoundaryTets_; ++i) {
      if (boundaryTets_[i] == t) return true;
    }
    return false;
  }

  ColorIndex tetFacetColor(const TetFacet& f) const {
    return tetMesh_.tetAdjacentTriangleColor(f.first, f.second);
  }

  template<class T>
  inline bool checkQuadFacetColor() const {
    for (CellFacetIndex f = 0; f < T::nbQuadFacets; ++f) {
      if (tetFacetColor(boundary_[T::nbTriFacets + 2*f]) != tetFacetColor(boundary_[T::nbTriFacets + 2*f+1]))
        return false;
    }
    return true;
  }

  // Check if the 2 triangles constituting a facet are both on the surface boudary 
  template<class T>
  inline bool checkQuadFacetBoundary() const {
    for (CellFacetIndex f = 0; f < T::nbQuadFacets; ++f) {
      const TetFacet& t0 = boundary_[T::nbTriFacets + 2*f];
      const TetFacet& t1 = boundary_[T::nbTriFacets + 2*f+1];

      if (tetMesh_.isOnBoundary(t0.first, t0.second) != tetMesh_.isOnBoundary(t1.first, t1.second))
        return false;
    }
    return true;
  }

  bool areAdjacent(TetIndex t0, TetIndex t1) const
  {
    for (TetFacetIndex j = 0; j < 4; ++j) {
      if (tetMesh().adjacentTet(t0, j) == t1) return true;
    }
    return false;
  }
  bool has4CellVertices(TetIndex tet) const
  {
    for (TetVertexIndex lv = 0; lv < 4; ++lv) {
      VertexIndex cur = tetMesh_.vertex(tet, lv);
      if (!isCellVertex(cur)) return false;
    }
    return true;
  }

  template<class T>
  inline bool isOnTheoreticalBoundary(TetIndex t, TetFacetIndex f) const
  {
    trindex tri = tetMesh_.tetFacet(t, f);
    CellVertexIndex v0 = NO_ID;
    CellVertexIndex v1 = NO_ID;
    CellVertexIndex v2 = NO_ID;
    for (CellVertexIndex i = 0; i < numVertices_; ++i) {
      if      (vertices_[i] == tri.indices[0]) v0 = i;
      else if (vertices_[i] == tri.indices[1]) v1 = i;
      else if (vertices_[i] == tri.indices[2]) v2 = i;
    }
    if( v0 != NO_ID && v1 != NO_ID && v2 != NO_ID ) 
      return T::vertexToBoundaryTriangle[v0][v1][v2] != NO_ID;
    else return false;
  }

  template<class T>
  void computeRealCellBoundary();

  template<class T>
  TetIndex computeOneInteriorTet() const;

  template<class T>
  void computeInteriorAndBoundaryTets(TetIndex t0);  

private:
  const TetMeshForCombining& tetMesh_;
  VertexIndex vertices_[8];
  TetIndex interiorTets_[16];     // sorted by increasing value
  TetIndex boundaryTets_[6];      // sorted by increasing value
  
  TetFacet boundary_[12];

  unsigned int numInteriorTets_ = 0;
  unsigned int numBoundaryTets_ = 0;
  unsigned int numVertices_ = 0;
  unsigned int numBoundary_ = 0;

};


/**
  * Create the API structure HXTCombineCell that corresponod to this CandidateCell
  */
struct CreateCombineCell {
  HXTCombineCell operator()(const CandidateCell& cell) {
    return cell.createCombineCell();
  }
};


/**
* True if the tet connect 4 vertices of the same quad facet of the cell
*
* \todo Is it faster to classify hex edges ? Put this inline !!!
* Most of the cases the tet is not in boundary -> this function is inefficient !!
*/
template<class T>
bool CandidateCell::isTetInBoundary(TetIndex t) const {
  quadindex tetra = tetMesh_.tet(t);

  for (CellFacetIndex f = T::nbTriFacets; f < T::nbFacets; ++f) {
    quadindex quadFacet(
      vertex(T::facetVertex[f][0]),
      vertex(T::facetVertex[f][1]),
      vertex(T::facetVertex[f][2]),
      vertex(T::facetVertex[f][3]));
    if (tetra == quadFacet) return true;
  }
  return false;
}

/**
* \brief Computes the tet facets that actually are on the cell boundary
* \details Iterate on all the tet facets and decide for each if it is or not on the boundary.
*/
template<class T>
void CandidateCell::computeRealCellBoundary()
{
  numBoundary_ = T::nbTriFacets + 2*T::nbQuadFacets;
  for (unsigned int i = 0; i < numBoundary_; ++i) {
    boundary_[i] = { NO_ID,NO_ID };
  }

  for (unsigned int i = 0; i < nbTets(); ++i) {
    TetIndex t = tet(i);
    for (TetFacetIndex f = 0; f < 4; ++f) {      
      if (!tetMesh_.isOnBoundary(t, f) && hasTet(tetMesh_.adjacentTet(t, f))) continue;

      trindex triangle = tetMesh_.tetFacet(t, f);
      TetFacet cur(t, f);
      
      CellVertexIndex v0 = NO_ID;
      CellVertexIndex v1 = NO_ID;
      CellVertexIndex v2 = NO_ID;
      for (CellVertexIndex i = 0; i < numVertices_; ++i) {
        if      (vertices_[i] == triangle.indices[0]) v0 = i;
        else if (vertices_[i] == triangle.indices[1]) v1 = i;
        else if (vertices_[i] == triangle.indices[2]) v2 = i;
      }
      unsigned int theoreticalIndex = T::vertexToBoundaryTriangle[v0][v1][v2];

      if (theoreticalIndex < T::nbTriFacets) {
        boundary_[theoreticalIndex] = cur;
      }
      else if (theoreticalIndex < T::nbTriFacets + 4*T::nbQuadFacets) {
        CellFacetIndex cellFacet = (theoreticalIndex - T::nbTriFacets)/4;
        unsigned int triangleId = T::nbTriFacets + 2*cellFacet;
        if (boundary_[triangleId].first == NO_ID) boundary_[triangleId] = cur;
        else boundary_[triangleId + 1] = cur;
      }
    }
  }
  assert(nbTets()== 0 || std::count(boundary_, boundary_+numBoundary_, TetFacet(NO_ID,NO_ID)) == 0);
}


/**
* \brief Find one tet of the TetMeshForCombining for which we are sure that it is inside the hex
* \details No boundary tet is returned.
* \warning This fails on pyramids.
* In fact this only WORKS because the vertices of the cells are in convex position.
*/
template<class T>
TetIndex CandidateCell::computeOneInteriorTet() const
{
  // 1. Find one tet connecting 4 vertices of the cell
  for (CellVertexIndex i = 0; i < numVertices_; ++i) {
    VertexIndex v = vertex(i);
    const vector<TetIndex>& tetsAroundV = tetMesh().tetsAroundVertex(v);
    for (unsigned int j = 0; j < tetsAroundV.size(); ++j) {
      TetIndex t = tetsAroundV[j];
      if (has4CellVertices(t) && !isTetInBoundary<T>(t)) {
        return t;
      }
    }
  }
  // 2. Find a tet adjacent to one of the triangles of the theoretical
  // boundary that has a positive volume
  for (unsigned int i = 0; i < T::nbTriFacets + 4*T::nbQuadFacets; ++i) {
    const CellVertexIndex* ids = i < T::nbTriFacets ? T::facetVertex[i] : T::quadFacetTriangleVertex[i-T::nbTriFacets];

    VertexIndex v0 = vertex(ids[0]);
    VertexIndex v1 = vertex(ids[1]);
    VertexIndex v2 = vertex(ids[2]);
    
    trindex facet(v0, v1, v2);
    const vector<TetIndex>& tetsAroundV0 = tetMesh().tetsAroundVertex(v0);
    for (unsigned int j = 0; j < tetsAroundV0.size(); ++j) {
      TetIndex t = tetsAroundV0[j];
      for (TetFacetIndex f = 0; f < 4; ++f) {
        if (tetMesh_.tetFacet(t, f) == facet) {
          // Are we inside or outside the hex?
          VertexIndex v3 = tetMesh_.vertex(t, f);
          if (tetMesh_.isVolumePositive(v0, v1, v2, v3) && !isTetInBoundary<T>(t)) {
            return t;
          }
        }
      }
    }
  }
  // The algorithm to build pyramid does not swallow points yet
  assert(false);
  return NO_ID;
}


/**
* \brief Computes the tets inside a hex determined by its 8 vertices
* \details From a tet that we know being in the cell, propagate to adjacent tets
* without crossing the triangles defining the theoretical cell boundary.
*
* \pre All cell quad facet correspond to 2 triangle facets of the tet mesh
*
* There might be additional points inside the hex.
*
* \todo Find a way to test that we have the good result.
*/
template<class T>
void CandidateCell::computeInteriorAndBoundaryTets(TetIndex tet)
{
  if (tet == NO_ID) {
    std::cout << "Error 403: first tet not found when building CandidateCell  ";
    for (CellVertexIndex i = 0; i < numVertices_; ++i) std::cout << vertices_[i] << " ";
     std::cout << std::endl;
    return;
  }
  numInteriorTets_ = 0;
  numBoundaryTets_ = 0;

  std::stack<TetIndex> S;
  S.push(tet);
  interiorTets_[ numInteriorTets_] = tet;
  numInteriorTets_++;

  while (!S.empty()) {
    TetIndex t = S.top();
    S.pop();
    for (TetFacetIndex lf = 0; lf <4; ++lf) {
      if (numInteriorTets_ > 15 || numBoundaryTets_ > 5) {
        numBoundaryTets_ = 0;
        numInteriorTets_ = 0;
        return;
      }
      if (!tetMesh_.isOnBoundary(t, lf)) {
        TetIndex adjacentTet = tetMesh_.adjacentTet(t, lf);

        if (!hasTet(adjacentTet)) {
          if (!isOnTheoreticalBoundary<T>(t, lf)) {
            interiorTets_[numInteriorTets_] = adjacentTet;
            numInteriorTets_++;
            
            S.push(adjacentTet);
          }
          else if (isTetInBoundary(adjacentTet)) {
            boundaryTets_[numBoundaryTets_] = adjacentTet;
            numBoundaryTets_++;
          }
        }
      }
      else if (!isOnTheoreticalBoundary<T>(t, lf)) {
        // It does happen a lot, but where ? save a few of these to see
        /// \todo Save cell in the current state, the first ten tets
        numBoundaryTets_ = 0;
        numInteriorTets_ = 0;
        return;
      }
    }
  }
  std::sort(interiorTets_, interiorTets_+numInteriorTets_);
  std::sort(boundaryTets_, boundaryTets_+numBoundaryTets_);
}

/**
* @}
*/

}


#endif
