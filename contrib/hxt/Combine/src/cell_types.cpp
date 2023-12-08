#include "cell_types.h"

#include "basic_types.h"

#include <cassert>
#include <map>
#include <limits.h>

/**
* \author Jeanne Pellerin
*/

namespace HXTCombine {
  // These declarations are necessary to compile with GCC
  constexpr CellVertexIndex Tet::facetVertex[][3];
  constexpr CellVertexIndex Tet::edgeVertex[][2];

  constexpr CellVertexIndex Hex::facetVertex[][4];
  constexpr CellVertexIndex Hex::edgeVertex[][2];
  constexpr CellVertexIndex Hex::quadFacetTriangleVertex[][3];
  constexpr CellVertexIndex Hex::quadFacetDiagonalVertex[][2];
  constexpr CellFacetIndex  Hex::vertexAdjacentFacet[][3];
  constexpr CellVertexIndex Hex::vertexAdjacentVertex[][3];
  constexpr CellVertexIndex Hex::orientedFacetVertex[][4];
  constexpr unsigned int Hex::vertexToBoundaryTriangle[][8][8];


  constexpr CellVertexIndex Pyramid::facetVertex[][4];
  constexpr CellVertexIndex Pyramid::edgeVertex[][2];
  constexpr CellVertexIndex Pyramid::quadFacetTriangleVertex[][3];
  constexpr CellVertexIndex Pyramid::quadFacetDiagonalVertex[][2];
  constexpr CellVertexIndex Pyramid::vertexAdjacentVertex[][4];
  constexpr CellVertexIndex Pyramid::vertexAdjacentFacet[][4];
  constexpr unsigned int Pyramid::vertexToBoundaryTriangle[][5][5];


  constexpr CellVertexIndex Prism::facetVertex[][4];
  constexpr CellVertexIndex Prism::edgeVertex[][2];
  constexpr CellVertexIndex Prism::quadFacetTriangleVertex[][3];
  constexpr CellVertexIndex Prism::quadFacetDiagonalVertex[][2];
  constexpr CellFacetIndex  Prism::vertexAdjacentFacet[][3];
  constexpr CellVertexIndex Prism::vertexAdjacentVertex[][3];
  constexpr CellVertexIndex Prism::orientedFacetVertex[][4];
  constexpr unsigned int Prism::vertexToBoundaryTriangle[][6][6];
}


namespace {
  using namespace HXTCombine;

template<class T> 
CellVertexIndex minVertexIndex(const VertexIndex* vertices) 
{
  CellVertexIndex result = 0;
  VertexIndex min = INT_MAX;
  for (CellVertexIndex i = 0; i < T::nbVertices; ++i) {
    if (vertices[i] < min) {
      min = vertices[i];
      result = i;
    }
  }
  return result;
}

template<class T>
CellFacetVertexIndex vertexIndexInFacet(const VertexIndex* vertices, CellFacetIndex f, unsigned int v)
{
  unsigned int nbFacetVertices = f < T::nbTriFacets ? 3 : 4;
  for (CellFacetVertexIndex lv = 0; lv < nbFacetVertices; ++lv) {
    CellVertexIndex cur = T::facetVertex[f][lv];
    if (vertices[v] == vertices[cur]) return lv;
  }
  return NO_ID;
}


template<class T>
CellVertexIndex incidentVertex(trindex vertices) {
  for (CellVertexIndex v = 0; v < T::nbVertices; ++v) {
    trindex curAdjacent(
      T::vertexAdjacentVertex[v][0],
      T::vertexAdjacentVertex[v][1],
      T::vertexAdjacentVertex[v][2]);
    if (curAdjacent == vertices) return v;
  }
  assert(false);
  return NO_ID;
}

template<class T>
CellVertexIndex lastVertexInQuadFacet(trindex vertices)
{
  for (CellFacetIndex f = T::nbTriFacets; f < T::nbFacets; ++f) {
    trindex t0(T::facetVertex[f][0], T::facetVertex[f][1], T::facetVertex[f][3]);
    if (t0 == vertices) return T::facetVertex[f][2];

    trindex t1(T::facetVertex[f][0], T::facetVertex[f][1], T::facetVertex[f][2]);
    if (t1 == vertices) return T::facetVertex[f][3];

    trindex t2(T::facetVertex[f][0], T::facetVertex[f][2], T::facetVertex[f][3]);
    if (t2 == vertices) return T::facetVertex[f][1];

    trindex t3(T::facetVertex[f][1], T::facetVertex[f][2], T::facetVertex[f][3]);
    if (t3 == vertices) return T::facetVertex[f][0];
  }
  assert(false);
  return NO_ID;
}

template<class T>
std::map<VertexIndex, CellVertexIndex> diagonalOppositeVerticesIncidentQuadFacets(
  const VertexIndex* vertices, CellVertexIndex v0)
{
  std::map<VertexIndex, CellVertexIndex> result;

  for (unsigned int i = 0; i < 3; i++) {
    CellFacetIndex f = T::vertexAdjacentFacet[v0][i];
    if (f < T::nbTriFacets) continue;

    CellFacetVertexIndex v0InFacet = vertexIndexInFacet<T>(vertices, f, v0);
    assert(v0InFacet != NO_ID);

    CellFacetVertexIndex oppositeToV0 = (v0InFacet+2)%4;

    CellVertexIndex v = T::facetVertex[f][oppositeToV0];
    result.insert(std::make_pair(vertices[v], v));
  }
  assert( (T::nbVertices == 6 && result.size()==2) || (T::nbVertices == 8 && result.size()==3));
  return result;
}

} // anonymous namespace

namespace HXTCombine {

void computePrismVertexNormalizationPermutation(
  const VertexIndex vertices[6], vector<PrismVertexIndex>& permutation)
{
  permutation.resize(6, NO_ID);
  permutation[0] = minVertexIndex<Prism>(vertices);

  std::map<VertexIndex, PrismVertexIndex> v1v2 =
    diagonalOppositeVerticesIncidentQuadFacets<Prism>(vertices, permutation[0]);
  unsigned int i = 1;
  for (auto it = v1v2.begin(); it != v1v2.end(); ++it) {
    permutation[i] = it->second;
    ++i;
  }
  trindex v3Adj(permutation[0], permutation[1], permutation[2]);   // v3 is adjacent to v0, v1, v2
  permutation[3] = incidentVertex<Prism>(v3Adj);

  trindex v4Quad(permutation[0], permutation[1], permutation[3]);  // v4 is in quad facet v0, v3, v1
  trindex v5Quad(permutation[0], permutation[2], permutation[3]);  // v5 is in quad facet v0, v3, v2
  permutation[4] = lastVertexInQuadFacet<Prism>(v4Quad);
  permutation[5] = lastVertexInQuadFacet<Prism>(v5Quad);
}


void computeHexVertexNormalizationPermutation(
  const VertexIndex vertices[8], vector<HexVertexIndex>& permutation)
{
  permutation.resize(8, NO_ID);
  permutation[0] = minVertexIndex<Hex>(vertices);

  std::map<VertexIndex, HexVertexIndex> v1v2v3 =
    diagonalOppositeVerticesIncidentQuadFacets<Hex>(vertices, permutation[0]);
  unsigned int i = 1;
  for (auto it = v1v2v3.begin(); it != v1v2v3.end(); ++it) {
    permutation[i] = it->second;
    ++i;
  }
  trindex v4Adj(permutation[0], permutation[1], permutation[2]);  // v4 is adjacent to v0, v1, v2
  trindex v5Adj(permutation[0], permutation[1], permutation[3]);  // v5 is adjacent to v0, v1, v3
  trindex v6Adj(permutation[0], permutation[2], permutation[3]);  // v6 is adjacent to v0, v2, v3
  trindex v7Adj(permutation[1], permutation[2], permutation[3]);  // v7 is adjacent to v1, v2, v3
  permutation[4] = incidentVertex<Hex>(v4Adj);
  permutation[5] = incidentVertex<Hex>(v5Adj);
  permutation[6] = incidentVertex<Hex>(v6Adj);
  permutation[7] = incidentVertex<Hex>(v7Adj);
}

}

