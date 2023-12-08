#ifndef HXT_COMBINE_CELL_TYPES
#define HXT_COMBINE_CELL_TYPES

#include "basic_types.h"

/**
* \file cell_type.h Topology of the 3d mesh cells in Combine module
* To be used as template arguments.
*
* \author Jeanne Pellerin
*/


namespace HXTCombine {

struct Tet {
  static const unsigned int nbVertices = 4;
  static const unsigned int nbEdges = 6;
  static const unsigned int nbFacets = 4;
  static const unsigned int nbTriFacets = 4;
  static const unsigned int nbQuadFacets = 0;

  static constexpr TetVertexIndex facetVertex[4][3] {
    { 1,3,2 },{ 0,2,3 },{ 3,1,0 },{ 0,1,2 } };

  static constexpr TetVertexIndex edgeVertex[6][2]{
    { 1,2 },{ 2,3 },{ 3,1 },{ 0,1 },{ 0,2 },{ 0,3 } };
};



/*  Hexahedron template
*
*   7----------6
*   |\         |\
*   | \        | \
*   |  \       |  \
*   |   4------+---5
*   |   |      |   |
*   3---+------2   |
*    \  |       \  |
*     \ |        \ |
*      \|         \|
*       0----------1
*/
struct Hex {
  static const unsigned int nbVertices = 8;
  static const unsigned int nbEdges = 12;
  static const unsigned int nbFacets = 6;
  static const unsigned int nbTriFacets = 0;
  static const unsigned int nbQuadFacets = 6;
  static const unsigned int nbCornersQuality = 8;

  static constexpr HexVertexIndex facetVertex[6][4] = {
    { 0,1,2,3 },{ 4,5,6,7 },{ 0,1,5,4 },
    { 1,2,6,5 },{ 3,2,6,7 },{ 0,3,7,4 } };

  static constexpr HexVertexIndex edgeVertex[12][2]{
    { 0,1 },{ 0,3 },{ 0,4 },{ 1,2 },{ 1,5 },{ 2,3 },
    { 2,6 },{ 3,7 },{ 4,5 },{ 4,7 },{ 5,6 },{ 6,7 } };

  static constexpr HexVertexIndex quadFacetTriangleVertex[24][3] = {
    { 0,1,2 },{ 0,2,3 },{ 0,1,3 },{ 1,2,3 },
    { 4,5,6 },{ 4,6,7 },{ 4,5,7 },{ 5,6,7 },
    { 0,1,5 },{ 0,5,4 },{ 0,1,4 },{ 1,5,4 },
    { 1,2,6 },{ 1,6,5 },{ 1,2,5 },{ 2,6,5 },
    { 3,2,6 },{ 3,6,7 },{ 3,2,7 },{ 2,6,7 },
    { 0,3,7 },{ 0,7,4 },{ 3,7,4 },{ 3,4,0 } };

  static constexpr HexVertexIndex quadFacetDiagonalVertex[12][2] = {
    { 0,2 },{ 1,3 },{ 4,6 },{ 5,7 },
    { 0,5 },{ 1,4 },{ 1,6 },{ 2,5 },
    { 3,6 },{ 2,7 },{ 0,7 },{ 3,4 } };

  static constexpr HexFacetIndex vertexAdjacentFacet[8][3] = {
    { 0,2,5 },{ 0,2,3 },{ 0,3,4 },{ 0,4,5 },
    { 1,2,5 },{ 1,2,3 },{ 1,3,4 },{ 1,4,5 } };

  static constexpr HexVertexIndex vertexAdjacentVertex[8][3] = {
    { 1,3,4 },{ 2,0,5 },{ 3,1,6 },{ 0,2,7 },
    { 7,5,0 },{ 4,6,1 },{ 5,7,2 },{ 6,4,3 } };

  static constexpr HexVertexIndex orientedFacetVertex[6][4] = {
    { 0,1,2,3 },{ 4,7,6,5 },{ 0,4,5,1 },
    { 1,5,6,2 },{ 3,2,6,7 },{ 0,3,7,4 } };
  
  // Mapping of 3 vertices to the index of the boundary triangle 
  // containing them nbTriFacets + 4*nbQuadFacets.
  static constexpr unsigned int vertexToBoundaryTriangle[8][8][8] = {
    {{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,0,2,10,8,NO_ID,NO_ID},{NO_ID,0,NO_ID,1,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,2,1,NO_ID,23,NO_ID,NO_ID,20},{NO_ID,10,NO_ID,23,NO_ID,9,NO_ID,21},{NO_ID,8,NO_ID,NO_ID,9,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,20,21,NO_ID,NO_ID,NO_ID}},
    {{NO_ID,NO_ID,0,2,10,8,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{0,NO_ID,NO_ID,3,NO_ID,14,12,NO_ID},{2,NO_ID,3,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{10,NO_ID,NO_ID,NO_ID,NO_ID,11,NO_ID,NO_ID},{8,NO_ID,14,NO_ID,11,NO_ID,13,NO_ID},{NO_ID,NO_ID,12,NO_ID,NO_ID,13,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID}},
    {{NO_ID,0,NO_ID,1,NO_ID,NO_ID,NO_ID,NO_ID},{0,NO_ID,NO_ID,3,NO_ID,14,12,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{1,3,NO_ID,NO_ID,NO_ID,NO_ID,16,18},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,14,NO_ID,NO_ID,NO_ID,NO_ID,15,NO_ID},{NO_ID,12,NO_ID,16,NO_ID,15,NO_ID,19},{NO_ID,NO_ID,NO_ID,18,NO_ID,NO_ID,19,NO_ID}},
    {{NO_ID,2,1,NO_ID,23,NO_ID,NO_ID,20},{2,NO_ID,3,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{1,3,NO_ID,NO_ID,NO_ID,NO_ID,16,18},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{23,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,22},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,16,NO_ID,NO_ID,NO_ID,NO_ID,17},{20,NO_ID,18,NO_ID,22,NO_ID,17,NO_ID}},
    {{NO_ID,10,NO_ID,23,NO_ID,9,NO_ID,21},{10,NO_ID,NO_ID,NO_ID,NO_ID,11,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{23,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,22},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{9,11,NO_ID,NO_ID,NO_ID,NO_ID,4,6},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,4,NO_ID,5},{21,NO_ID,NO_ID,22,NO_ID,6,5,NO_ID}},
    {{NO_ID,8,NO_ID,NO_ID,9,NO_ID,NO_ID,NO_ID},{8,NO_ID,14,NO_ID,11,NO_ID,13,NO_ID},{NO_ID,14,NO_ID,NO_ID,NO_ID,NO_ID,15,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{9,11,NO_ID,NO_ID,NO_ID,NO_ID,4,6},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,13,15,NO_ID,4,NO_ID,NO_ID,7},{NO_ID,NO_ID,NO_ID,NO_ID,6,NO_ID,7,NO_ID}},
    {{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,12,NO_ID,NO_ID,13,NO_ID,NO_ID},{NO_ID,12,NO_ID,16,NO_ID,15,NO_ID,19},{NO_ID,NO_ID,16,NO_ID,NO_ID,NO_ID,NO_ID,17},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,4,NO_ID,5},{NO_ID,13,15,NO_ID,4,NO_ID,NO_ID,7},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,19,17,5,7,NO_ID,NO_ID}},
    {{NO_ID,NO_ID,NO_ID,20,21,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,18,NO_ID,NO_ID,19,NO_ID},{20,NO_ID,18,NO_ID,22,NO_ID,17,NO_ID},{21,NO_ID,NO_ID,22,NO_ID,6,5,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,6,NO_ID,7,NO_ID},{NO_ID,NO_ID,19,17,5,7,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID}}
  };
};


/*
*  Prism template
*
*               3
*              /| \
*            /  |   \
*          /    |     \
*        4------+------5
*        |      |      |
*        |      |      |
*        |      0      |
*        |     /  \    |
*        |   /      \  |
*        | /          \|
*        1-------------2
*/
struct Prism {
  static const unsigned int nbVertices = 6;
  static const unsigned int nbEdges = 9;
  static const unsigned int nbFacets = 5;
  static const unsigned int nbTriFacets = 2;
  static const unsigned int nbQuadFacets = 3;
  static const unsigned int nbCornersQuality = 6;

  static constexpr PrismVertexIndex facetVertex[5][4] = {
    { 0,1,2, NO_ID },{ 3,4,5, NO_ID },
    { 0,1,4,3 },{ 1,4,5,2 },{ 2,5,3,0 } };

  static constexpr PrismVertexIndex edgeVertex[9][2] = {
    { 0,1 },{ 0,2 },{ 0,3 },{ 1,2 },{ 2,5 },{ 1,4 },
    { 3,4 },{ 3,5 },{ 4,5 } };

  static constexpr PrismVertexIndex quadFacetTriangleVertex[12][3] = {
    { 0,1,4 },{ 0,4,3 },{ 0,1,3 },{ 1,3,4 },
    { 1,2,4 },{ 2,4,5 },{ 1,2,5 },{ 1,5,4 },
    { 2,5,3 },{ 2,3,0 },{ 2,5,0 },{ 5,3,0 } };

  static constexpr PrismVertexIndex quadFacetDiagonalVertex[6][2] = {
    { 0,4 },{ 1,3 },{ 1,5 },{ 2,4 },
    { 0,5 },{ 2,3 } };

  static constexpr PrismFacetIndex vertexAdjacentFacet[6][3] = {
    { 0,2,4 },{ 0,2,3 },{ 0,3,4 },{ 1,2,4 },
    { 1,2,3 },{ 1,3,4 } };

  // Orientation matters.
  static constexpr PrismVertexIndex vertexAdjacentVertex[6][3] = {
    { 1,2,3 },{ 2,0,4 },{ 0,1,5 },{ 5,4,0 },
    { 3,5,1 },{ 4,3,2 } };

  static constexpr PrismVertexIndex orientedFacetVertex[6][4] = {
    { 0,1,2, NO_ID },{ 3,5,4, NO_ID },
    { 0,1,4,3 }, { 1,4,5,2 },{ 2,5,3,0 } };

  // Mapping of 3 vertices to the index of the boundary triangle 
  // containing them nbTriFacets + 4*nbQuadFacets.
  static constexpr unsigned int vertexToBoundaryTriangle[6][6][6] = {
    {{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,0,4,2,NO_ID},{NO_ID,0,NO_ID,11,NO_ID,12},{NO_ID,4,11,NO_ID,3,13},{NO_ID,2,NO_ID,3,NO_ID,NO_ID},{NO_ID,NO_ID,12,13,NO_ID,NO_ID}},
    {{NO_ID,NO_ID,0,4,2,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{0,NO_ID,NO_ID,NO_ID,6,8},{4,NO_ID,NO_ID,NO_ID,5,NO_ID},{2,NO_ID,6,5,NO_ID,9},{NO_ID,NO_ID,8,NO_ID,9,NO_ID}},
    {{NO_ID,0,NO_ID,11,NO_ID,12},{0,NO_ID,NO_ID,NO_ID,6,8},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{11,NO_ID,NO_ID,NO_ID,NO_ID,10},{NO_ID,6,NO_ID,NO_ID,NO_ID,7},{12,8,NO_ID,10,7,NO_ID}},
    {{NO_ID,4,11,NO_ID,3,13},{4,NO_ID,NO_ID,NO_ID,5,NO_ID},{11,NO_ID,NO_ID,NO_ID,NO_ID,10},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{3,5,NO_ID,NO_ID,NO_ID,1},{13,NO_ID,10,NO_ID,1,NO_ID}},
    {{NO_ID,2,NO_ID,3,NO_ID,NO_ID},{2,NO_ID,6,5,NO_ID,9},{NO_ID,6,NO_ID,NO_ID,NO_ID,7},{3,5,NO_ID,NO_ID,NO_ID,1},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,9,7,1,NO_ID,NO_ID}},
    {{NO_ID,NO_ID,12,13,NO_ID,NO_ID},{NO_ID,NO_ID,8,NO_ID,9,NO_ID},{12,8,NO_ID,10,7,NO_ID},{13,NO_ID,10,NO_ID,1,NO_ID},{NO_ID,9,7,1,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID}}
  };

};

/*
* Pyramid template
*
*                 4
*               ,/|\
*             ,/ .'|\
*           ,/   | | \
*         ,/    .' | `.
*       ,/      |  '.  \
*     ,/       .'   |   \
*   ,/         |    |    \
*  0----------.'----3    `.
*   `\        |      `\    \
*     `\     .'        `\   \
*       `\   |           `\  \
*         `\.'             `\`
*            1----------------2
*
*
*/

struct Pyramid {
  static const unsigned int nbVertices = 5;
  static const unsigned int nbEdges = 8;
  static const unsigned int nbFacets = 5;
  static const unsigned int nbTriFacets = 4;
  static const unsigned int nbQuadFacets = 1;
  static const unsigned int nbCornersQuality = 4; // Only vertices of the base are considered for quality evaluation

  static constexpr CellVertexIndex facetVertex[5][4] = {
    { 0,1,4,NO_ID },{ 3,0,4,NO_ID },
    { 1,2,4,NO_ID },{ 2,3,4,NO_ID },
    { 0,3,2,1 } };

  static constexpr CellVertexIndex edgeVertex[8][2] = {
    { 0,1 },{ 0,3 },{ 0,4 },{ 1,2 },
    { 1,4 },{ 2,3 },{ 2,4 },{ 3,4 } };

  static constexpr CellVertexIndex quadFacetTriangleVertex[4][3] = {
    { 0,1,3 },{ 1,3,2 },{ 0,1,2 },{ 0,2,3 } };

  static constexpr CellVertexIndex quadFacetDiagonalVertex[2][2] = {
    { 0,2 },{ 1,3 } };

  static constexpr CellVertexIndex vertexAdjacentVertex[5][4] = {
    { 1,3,4, NO_ID },{ 2,0,4, NO_ID },
    { 3,1,4, NO_ID },{ 0,2,4, NO_ID },
    { 0,1,2,3 } };

  static constexpr CellFacetIndex vertexAdjacentFacet[5][4] = {
    { 0,1,4, NO_ID },
    { 0,2,4, NO_ID },
    { 2,3,4, NO_ID },
    { 1,3,4, NO_ID },
    { 0,1,2,3 } };

  // Mapping of 3 vertices to the index of the boundary triangle 
  // containing them nbTriFacets + 4*nbQuadFacets.
  static constexpr unsigned int vertexToBoundaryTriangle[5][5][5] = {
    {{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{NO_ID,NO_ID,6,4,0},{NO_ID,6,NO_ID,7,NO_ID},{NO_ID,4,7,NO_ID,1},{NO_ID,0,NO_ID,1,NO_ID}},
    {{NO_ID,NO_ID,6,4,0},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{6,NO_ID,NO_ID,5,2},{4,NO_ID,5,NO_ID,NO_ID},{0,NO_ID,2,NO_ID,NO_ID}},
    {{NO_ID,6,NO_ID,7,NO_ID},{6,NO_ID,NO_ID,5,2},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{7,5,NO_ID,NO_ID,3},{NO_ID,2,NO_ID,3,NO_ID}},
    {{NO_ID,4,7,NO_ID,1},{4,NO_ID,5,NO_ID,NO_ID},{7,5,NO_ID,NO_ID,3},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID},{1,NO_ID,3,NO_ID,NO_ID}},
    {{NO_ID,0,NO_ID,1,NO_ID},{0,NO_ID,2,NO_ID,NO_ID},{NO_ID,2,NO_ID,3,NO_ID},{1,NO_ID,3,NO_ID,NO_ID},{NO_ID,NO_ID,NO_ID,NO_ID,NO_ID}}
  };

};


/** Order the hex vertice vertices non-ambiguously.
* v0 < v1 < v2 < v3;  v4, v5 and v7 are placed relatively to these.
*
* \note Volume sign is lost.
*/
/*
*   3----------7
*   |\         |\
*   | \        | \
*   |  \       |  \
*   |   6------+---2
*   |   |      |   |
*   5---+------1   |
*    \  |       \  |
*     \ |        \ |
*      \|         \|
*       0----------4
*/
void computeHexVertexNormalizationPermutation(
  const VertexIndex vertices[8],
  vector<HexVertexIndex>& permutation);


/**
* \brief Order the six vertex indices of a prism non-ambiguously.
* \details Determines the permutation of the input vertices such that
* v0 < v1 < v2;  v3 is adjacent to v1, v1 and v2;
* v4 is in v0v1v2 quadrilateral facet, and v5 in v0v3v2 quadrilateral facet
*
* \note Volume sign is lost.
*/
/*
*               3
*              /| \
*            /  |   \
*          /    |     \
*        1------+------2
*        |      |      |
*        |      |      |
*        |      0      |
*        |     /  \    |
*        |   /      \  |
*        | /          \|
*        4-------------5
*
*/
void computePrismVertexNormalizationPermutation(
  const VertexIndex vertices[6],
  vector<PrismVertexIndex>& permutation);

}

#endif
