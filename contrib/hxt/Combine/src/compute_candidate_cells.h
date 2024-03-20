#ifndef HXT_COMBINE_COMPUTE_CANDIDATE_CELLS
#define HXT_COMBINE_COMPUTE_CANDIDATE_CELLS

#include "basic_types.h"
#include "combine_quality.h"
#include "tet_mesh.h"
#include "hxt_quality.h"

/**
* \file compute_candidate_cell.h THE algorithms to identify hexes, prisms and pyramids
*  in a tetrahedral mesh
*
* \author Jeanne Pellerin
*/

namespace HXTCombine{

  using HXTCombine::vec3;

/**
* \addtogroup Combine
* @{
*/
  
/**
* Resizes the sorted (decreasing order) vector \param input such
* that all values are strictly above \param minValue.
*/
template<class T>
inline void filterValues(vector<T>& input, const T& minValue)
{
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (input[i] <= minValue) {
      input.resize(i);
      return;
    }
  }
}

inline double cellQuality(const TetMeshWrapper& tets, const vector<VertexIndex>& vertices)
{
  vector<vec3> points(vertices.size());
  for (unsigned int i = 0; i < vertices.size(); ++i) {
    points[i] = tets.point(vertices[i]);
  }
  if      (vertices.size() == 8) return cellApproximateQuality<Hex>(points.data());
  else if (vertices.size() == 6) return cellApproximateQuality<Prism>(points.data());
  else if (vertices.size() == 5) return cellApproximateQuality<Pyramid>(points.data()); 
  else return -1.;
}

inline bool isCellReallyValid(const TetMeshWrapper& tets, const vector<VertexIndex>& vertices)
{
  vector<vec3> points(vertices.size());
  for (unsigned int i = 0; i < vertices.size(); ++i) {
    points[i] = tets.point(vertices[i]);
  }
  // Dirty casting to the vec3 class that is used in the hext_quality.cpp file
  // till a better solution is available
  if      (vertices.size() == 8) return hexExactValidity((::point3d*) points.data());
  else if (vertices.size() == 6) return prismValidity((::point3d*)points.data());
  else if (vertices.size() == 5) return pyramidValidityNotImplemented((::point3d*)points.data());
  else return false;
}


template< class ACTION >
void computeAllPrisms(ACTION& actionOnPrism, const TetMeshForCombining& M, double minQ)
{
  // --- 1  ---  A
#pragma omp parallel for schedule(dynamic)
  for (int aSigned = 0; aSigned < (int)M.nbVertices(); ++aSigned) {
    unsigned int a(aSigned);
    vector<VertexIndex> aroundA = M.verticesAroundVertices(a);
    filterValues(aroundA, a);
    // --- 2 --- B
    for (unsigned int i = 0; i < aroundA.size(); ++i) {
      VertexIndex b = aroundA[i];
      vector<VertexIndex> aroundAB = M.verticesAroundVertices(a, b);
      filterValues(aroundAB, a);
      // --- 3 --- C
      for (unsigned int j = 0; j < aroundAB.size(); ++j) {
        VertexIndex c = aroundAB[j];
        if (M.triangleCornerQuality(a, b, c) < minQ) continue;
        if (!M.isTriangleFacet(a, b, c)) continue;
        // --- 4 --- D
        for (unsigned int k = 0; k < aroundA.size(); ++k) {
          VertexIndex d = aroundA[k];
          if (d == b || d == c) continue;
          if (M.prismCornerQuality(a, b, c, d) < minQ) continue;
          vector<VertexIndex> aroundBD = M.verticesAroundVertices(b, d);
          filterValues(aroundBD, a);
          // --- 5 --- E
          for (unsigned int l = 0; l < aroundBD.size(); ++l) {
            VertexIndex e = aroundBD[l];
            if (e == c) continue;
            if (M.prismCornerQuality(b, c, a, e) < minQ) continue;
            if (!M.isTriangulatedQuad(a, b, e, d)) continue;
            vector<VertexIndex> aroundCDE = M.verticesAroundVertices(c, d, e);
            filterValues(aroundCDE, a);
            // --- 6 --- F
            for (unsigned int m = 0; m < aroundCDE.size(); ++m) {
              VertexIndex f = aroundCDE[m];
              if (f == b) continue;
              if (M.prismCornerQuality(c, a, b, f) < minQ) continue;
              if (M.prismCornerQuality(d, f, e, a) < minQ) continue;
              if (M.prismCornerQuality(f, e, d, c) < minQ) continue;
              if (M.prismCornerQuality(e, d, f, b) < minQ) continue;

              if (!M.isTriangleFacet(d, e, f)) continue;
              if (!M.isTriangulatedQuad(b, c, f, e)) continue;
              if (!M.isTriangulatedQuad(a, c, f, d)) continue;

              actionOnPrism({ a,b,c,d,e,f });
            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


/**
* There are 3 pyramids for each facet of the tetrahedral mesh
*/
template<class ACTION>
void computeAllPyramids(ACTION& actionOnPyramid, const TetMeshForCombining& M, double minQ)
{
#pragma omp parallel for schedule(dynamic)
  for (int t = 0; t < (int)M.nbTets(); ++t) {
    for (TetFacetIndex f = 0; f < 4; ++f) {
      AdjacentTetIndex adj = M.adjacentTet(t, f);
      if (M.isOnBoundary(t, f) || t > adj) continue;

      TetFacetIndex adjFacet = M.adjacentFacetInAdjacentTet(t, f);

      // The 2 vertices opposite to the facet are fixed
      VertexIndex a = M.vertex(t, f);
      VertexIndex c = M.vertex(adj, adjFacet);

      for (TetFacetVertexIndex v = 0; v < 3; ++v) {
        TetVertexIndex ve = Tet::facetVertex[f][v];
        TetVertexIndex vd = Tet::facetVertex[f][(v+1)%3];
        TetVertexIndex vb = Tet::facetVertex[f][(v+2)%3];

        VertexIndex e = M.vertex(t, ve);
        VertexIndex b = M.vertex(t, vb);
        VertexIndex d = M.vertex(t, vd);

        actionOnPyramid({ a,b,c,d,e }, t);
      }
    }
  }
}



//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

/**
* \brief The function to identify all hexes in a tetrahedral mesh
*/
template<class ACTION>
void computeAllHex(ACTION& actionOnHex, const TetMeshForCombining& M, double minQ)
{
  // --- 1  ---  A
#pragma omp parallel for schedule(dynamic)
  for (int a0 = 0; a0 < (int)M.nbVertices(); ++a0) {
    unsigned int a(a0);
    vector<VertexIndex> aroundA = M.verticesAroundVertices(a);
    filterValues(aroundA, a);
    // --- 2 --- B
    for (unsigned int i = 0; i < aroundA.size(); ++i) {
      VertexIndex b = aroundA[i];
      vector<VertexIndex> candidatesDorE(aroundA);
      filterValues(candidatesDorE, b);
      // --- 3 --- D
      for (unsigned int j = 0; j < candidatesDorE.size(); ++j) {
        VertexIndex d = candidatesDorE[j];
        if (M.quadCornerQuality(a, b, d) < minQ) continue;
        // --- 4 --- E
        for (unsigned int k = 0; k < candidatesDorE.size(); ++k) {
          VertexIndex e = candidatesDorE[k];
          if (e == d) continue;
          if (M.hexCornerQuality(a, b, d, e) < minQ) continue;
          vector<VertexIndex> aroundBD = M.verticesAroundVertices(b, d);
          filterValues(aroundBD, a);
          // --- 5 --- C
          for (unsigned int l = 0; l < aroundBD.size(); ++l) {
            VertexIndex c = aroundBD[l];
            if (c == e) continue;
            if (M.quadCornerQuality(b, a, c) < minQ) continue;
            if (M.quadCornerQuality(c, b, d) < minQ) continue;
            if (M.quadCornerQuality(d, a, c) < minQ) continue;
            if (!M.isTriangulatedQuad(a, b, c, d)) continue;
            vector<VertexIndex> aroundBE = M.verticesAroundVertices(b, e);
            filterValues(aroundBE, a);
            // --- 6 --- F
            for (unsigned int m = 0; m < aroundBE.size(); ++m) {
              VertexIndex f = aroundBE[m];
              if (f == c || f == d) continue;
              if (M.quadCornerQuality(f, b, e)   < minQ) continue;
              if (M.quadCornerQuality(e, a, f)   < minQ) continue;
              if (M.hexCornerQuality(b, c, a, f) < minQ) continue;
              if (!M.isTriangulatedQuad(a, b, f, e))     continue;
              // --- 7 --- H
              vector<VertexIndex> aroundDE = M.verticesAroundVertices(d, e);
              filterValues(aroundDE, a);
              for (unsigned int n = 0; n < aroundDE.size(); ++n) {
                VertexIndex h = aroundDE[n];
                if (h == b || h == c || h == f) continue;
                if (M.quadCornerQuality(h, d, e) < minQ)    continue;
                if (M.hexCornerQuality(d, a, c, h) < minQ) continue;
                if (M.hexCornerQuality(e, a, h, f) < minQ) continue;
                if (!M.isTriangulatedQuad(a, d, h, e)) continue;
                // --- 8 --- G
                vector<VertexIndex> aroundCFH = M.verticesAroundVertices(c, f, h);
                filterValues(aroundCFH, a);
                for (unsigned int p = 0; p < aroundCFH.size(); ++p) {
                  VertexIndex g = aroundCFH[p];
                  if (g == b || g == d || g == e) continue;
                  if (M.hexCornerQuality(g, f, h, c) < minQ) continue;
                  if (M.hexCornerQuality(f, e, g, b) < minQ) continue;
                  if (M.hexCornerQuality(h, g, e, d) < minQ) continue;
                  if (M.hexCornerQuality(c, b, g, d) < minQ) continue;

                  if (!M.isTriangulatedQuad(d, c, g, h)) continue;
                  if (!M.isTriangulatedQuad(e, f, g, h)) continue;
                  if (!M.isTriangulatedQuad(b, c, g, f)) continue;

                  actionOnHex({ a,b,c,d,e,f,g,h });
                }
              }
            }
          }
        }
      }
    }
  }
}

/**
* @}
*/

}

#endif
