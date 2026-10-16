#include "tet_mesh.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <utility>
#include <string>
#include <string.h>

#include "basic_types.h"
#include "hxt_omp.h"

/**
* \author Jeanne Pellerin
*/


namespace HXTCombine {

trindex tetFacet(const MeshStore& tets, TetIndex t, TetFacetIndex lf) {
  VertexIndex v0 = tets.tetCorners[4*t+Tet::facetVertex[lf][0]];
  VertexIndex v1 = tets.tetCorners[4*t+Tet::facetVertex[lf][1]];
  VertexIndex v2 = tets.tetCorners[4*t+Tet::facetVertex[lf][2]];
  return trindex(v0, v1, v2);
}

// The facets matched around their smallest vertex: the tets around each
// vertex in compressed rows, then each facet looks for the other tet that
// has its 3 vertices, the tets in parallel (each one writes its own facets)
void computeTetAdjacencies(MeshStore& store){

  const AdjacentTetIndex NO_ADJACENT = store.NO_ADJACENT_ID;
  const int64_t nbTets = store.tetCorners.size()/4;
  const std::size_t nbVertices = store.vertices.size()/4;
  const VertexIndex* corners = store.tetCorners.data();

  vector<std::size_t> start(nbVertices + 1, 0);
  for (std::size_t c = 0; c < 4*(std::size_t)nbTets; ++c) start[corners[c] + 1]++;
  for (std::size_t v = 0; v < nbVertices; ++v) start[v + 1] += start[v];
  vector<TetIndex> tetsAround(4*(std::size_t)nbTets);
  {
    vector<std::size_t> pos(start.begin(), start.end() - 1);
    for (std::size_t c = 0; c < 4*(std::size_t)nbTets; ++c)
      tetsAround[pos[corners[c]]++] = (TetIndex)(c/4);
  }

  store.tetAdjacent.assign(4*(std::size_t)nbTets, NO_ADJACENT);
  AdjacentTetIndex* adjacent = store.tetAdjacent.data();
#pragma omp parallel for schedule(static)
  for (int64_t t = 0; t < nbTets; ++t) {
    const VertexIndex* tc = corners + 4*t;
    for (TetFacetIndex f = 0; f < 4; ++f) {
      // the facet opposite to its vertex f
      const VertexIndex a = tc[Tet::facetVertex[f][0]];
      const VertexIndex b = tc[Tet::facetVertex[f][1]];
      const VertexIndex c = tc[Tet::facetVertex[f][2]];
      const VertexIndex v = std::min(a, std::min(b, c));
      for (std::size_t k = start[v]; k < start[v + 1]; ++k) {
        const TetIndex u = tetsAround[k];
        if (u == (TetIndex)t) continue;
        const VertexIndex* uc = corners + 4*(std::size_t)u;
        unsigned int nb = 0, other = 0;
        for (TetVertexIndex lv = 0; lv < 4; ++lv) {
          if (uc[lv] == a || uc[lv] == b || uc[lv] == c) nb++;
          else other = lv;
        }
        if (nb == 3) {
          adjacent[4*t + f] = 4*(AdjacentTetIndex)u + other;
          break;
        }
      }
    }
  }
}

void buildhxtVertexFromCoordinates(const std::vector<double>& points, std::vector<double>& hxtvertices)
{
  size_t nbVertices = points.size()/3;
  hxtvertices.resize(4*nbVertices);
  for (unsigned int i = 0; i < nbVertices; ++i) {
    hxtvertices[4*i] = points[3*i];
    hxtvertices[4*i+1] = points[3*i+1];
    hxtvertices[4*i+2] = points[3*i+2];
  }
}

/** Reading .mesh file - only the vertices - triangles - quads
*/
void readFileMESH(const std::string& filename, HXTCombine::MeshStore& mesh, bool read_triangles)
{
  FILE *fp = std::fopen(filename.c_str(), "r");
  if (!fp) {
    std::cout << "Unable to open file " << filename << std::endl;
    return;
  }

  char buffer[256];
  if (!fgets(buffer, sizeof(buffer), fp)) { fclose(fp); return; }

  char str[256];
  int format;
  sscanf(buffer, "%s %d", str, &format);

  std::vector<double>& vertexVector = mesh.vertices;

  std::vector<VertexIndex>& triangles = mesh.triangleCorners;
  std::vector<VertexIndex>& quads = mesh.quadCorners;
  std::vector<VertexIndex>& tets = mesh.tetCorners;
  std::vector<VertexIndex>& hex = mesh.hexCorners;

  std::vector<ColorIndex>& triangleColors = mesh.triangleColors;
  std::vector<ColorIndex>& quadColors = mesh.quadColors;
  std::vector<ColorIndex>& hexColors = mesh.hexColors;
  std::vector<ColorIndex>& tetColors = mesh.tetColors;


  while (!feof(fp)) {
    if (!fgets(buffer, 256, fp)) break;
    if (buffer[0] != '#') { // skip comments and empty lines
      str[0] = '\0';
      sscanf(buffer, "%s", str);
      if (!strncmp(buffer, "Dimension 3", 11)) {
      }
      else if (!strcmp(str, "Dimension")) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
      }
      else if (!strcmp(str, "Vertices")) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
        int nbv;
        sscanf(buffer, "%d", &nbv);
        std::cout << nbv << " vertices  ";
        vertexVector.resize(4*nbv);
        for (int i = 0; i < nbv; i++) {
          if (!fgets(buffer, sizeof(buffer), fp)) break;
          int dum;
          double x, y, z;
          sscanf(buffer, "%lf %lf %lf %d", &x, &y, &z, &dum);
          vertexVector[4*i+0] = x;
          vertexVector[4*i+1] = y;
          vertexVector[4*i+2] = z;
        }
      }
      else if (!strcmp(str, "Triangles") && read_triangles) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        std::cout << nbe << " triangles  ";
        triangles.reserve(3*nbe);
        triangleColors.reserve(nbe);
        for (int i = 0; i < nbe; i++) {
          if (!fgets(buffer, sizeof(buffer), fp)) break;
          int n[3], cl;
          sscanf(buffer, "%d %d %d %d", &n[0], &n[1], &n[2], &cl);
          for (int j = 0; j < 3; j++) {
            n[j]--;
            triangles.push_back(n[j]);
          }
          triangleColors.push_back(cl);
        }
      }
      else if (!strcmp(str, "Quadrilaterals")) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        std::cout << nbe << " quads  ";
        quads.reserve(4*nbe);
        quadColors.reserve(nbe);
        for (int i = 0; i < nbe; i++) {
          if (!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for (int j = 0; j < 4; j++) {
            n[j]--;
            quads.push_back(n[j]);
          }
          quadColors.push_back(cl);
        }
      }
      else if (!strcmp(str, "Tetrahedra")) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        std::cout << nbe << " tetrahedra  ";
        tets.reserve(4*nbe);
        tetColors.reserve(nbe);
        for (int i = 0; i < nbe; i++) {
          if (!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for (int j = 0; j < 4; j++) {
            n[j]--;
            tets.push_back(n[j]);
          }
          tetColors.push_back(cl);
        }
      }
      else if (!strcmp(str, "Hexahedra")) {
        if (!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        std::cout << nbe << " hexahedra ";
        hex.reserve(8*nbe);
        hexColors.reserve(nbe);
        for (int i = 0; i < nbe; i++) {
          if (!fgets(buffer, sizeof(buffer), fp)) break;
          int n[8], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3],
            &n[4], &n[5], &n[6], &n[7], &cl);
          for (int j = 0; j < 8; j++) {
            n[j]--;
            hex.push_back(n[j]);
          }
          hexColors.push_back(cl);
        }
      }
    }
  }
  std::cout << std::endl << std::endl;

  fclose(fp);

  // Compute adjacencies
  computeTetAdjacencies(mesh);
}


void TetMeshForCombining::initConnectivityTables()
{
  fillFacets();
  chainTetCornersAroundVertices();
  fillVertexToVertices();
  if (nbTriangles() > 0) connectTetsToTriangles();
}

/*
* This is not bad and works well, but how can I parallelize it ??
*
* \todo See if I can use Celestin's version for this
*/
void TetMeshForCombining::chainTetCornersAroundVertices() {
  vertexToTetCorner_.resize(nbVertices(), NO_ID);
  nextTetCornerAroundVertex_.resize(4*nbTets(), NO_ID);

  for (TetIndex t = 0; t < nbTets(); ++t) {
    for (TetVertexIndex lv = 0; lv < 4; ++lv) {
      TetCornerIndex c = 4*t+lv;
      VertexIndex v = vertex(t, lv);
      nextTetCornerAroundVertex_[c] = vertexToTetCorner_[v];
      vertexToTetCorner_[v] = c;
    }
  }
}


void TetMeshForCombining::fillVertexToVertices()
{
  // the sorted neighbours of a vertex, in compressed rows: counted, then
  // written, the vertices in parallel
  auto around = [&](VertexIndex v, vector<VertexIndex>& temp) {
    temp.resize(0);
    TetCornerIndex c = vertexToTetCorner_[v];
    while (c != NO_ID) {
      TetIndex t = c/4;
      TetVertexIndex lv = c%4;
      temp.push_back(vertex(t, Tet::facetVertex[lv][0]));
      temp.push_back(vertex(t, Tet::facetVertex[lv][1]));
      temp.push_back(vertex(t, Tet::facetVertex[lv][2]));
      c = nextTetCornerAroundVertex_[c];
    }
    std::sort(temp.begin(), temp.end(), std::greater<VertexIndex>());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
  };
  vertexToVerticesStart_.assign(nbVertices() + 1, 0);
#pragma omp parallel
  {
    vector<VertexIndex> temp;
#pragma omp for schedule(dynamic, 1024)
    for (int v = 0; v < (int)nbVertices(); ++v) {
      around(v, temp);
      vertexToVerticesStart_[v + 1] = temp.size();
    }
  }
  for (VertexIndex v = 0; v < nbVertices(); ++v)
    vertexToVerticesStart_[v + 1] += vertexToVerticesStart_[v];
  vertexToVertices_.resize(vertexToVerticesStart_[nbVertices()]);
#pragma omp parallel
  {
    vector<VertexIndex> temp;
#pragma omp for schedule(dynamic, 1024)
    for (int v = 0; v < (int)nbVertices(); ++v) {
      around(v, temp);
      std::copy(temp.begin(), temp.end(),
                vertexToVertices_.begin() + vertexToVerticesStart_[v]);
    }
  }
}

void TetMeshForCombining::fillFacets()
{
  // the facets by smallest vertex, in compressed rows sorted by the 2 others
  facetStart_.assign(nbVertices() + 1, 0);
#pragma omp parallel for schedule(static)
  for (int t = 0; t < (int)nbTets(); ++t)
    for (TetFacetIndex f = 0; f < 4; ++f)
      if ((TetIndex)t < adjacentTet(t, f))
        __atomic_fetch_add(&facetStart_[tetFacet(t, f).indices[0] + 1], 1, __ATOMIC_RELAXED);
  for (VertexIndex v = 0; v < nbVertices(); ++v) facetStart_[v + 1] += facetStart_[v];
  facets_.resize(facetStart_[nbVertices()]);
  std::vector<std::size_t> next(facetStart_.begin(), facetStart_.end() - 1);
#pragma omp parallel for schedule(static)
  for (int t = 0; t < (int)nbTets(); ++t)
    for (TetFacetIndex f = 0; f < 4; ++f)
      if ((TetIndex)t < adjacentTet(t, f)) {
        const trindex facet = tetFacet(t, f);
        facets_[__atomic_fetch_add(&next[facet.indices[0]], 1, __ATOMIC_RELAXED)] =
          std::make_pair(facet.indices[1], facet.indices[2]);
      }
#pragma omp parallel for schedule(dynamic, 1024)
  for (int v = 0; v < (int)nbVertices(); ++v)
    std::sort(facets_.begin() + facetStart_[v], facets_.begin() + facetStart_[v + 1]);
}

/** Maybe could be done at the same time than tet connection to avoid
*  one loop over the tets.
*/
void TetMeshForCombining::connectTetsToTriangles()
{
  if (nbTriangles() == 0) return;

  // 0. Allocate storage space
  adjacentTriangles_.resize(4*nbTets(), NO_ADJACENT);

  // 1. Chain triangle corners around triangle vertices
  vector<TetCornerIndex> nextTriangleCornerAroundVertex(3*nbTriangles(), NO_ID);
  vector<TetCornerIndex> vertexToTriangleCorner(nbVertices(), NO_ID);
  for (TriangleIndex t = 0; t < nbTriangles(); ++t) {
    for (TriangleVertexIndex lv = 0; lv<3; ++lv) {
      TriangleCornerIndex c = 3*t+lv;
      VertexIndex v = triangleVertex(t, lv);
      nextTriangleCornerAroundVertex[c] = vertexToTriangleCorner[v];
      vertexToTriangleCorner[v] = c;
    }
  }

  // 2. Set adjacencies between tets and triangles
  for (TetIndex tet = 0; tet < nbTets(); ++tet) {
    for (TetFacetIndex f = 0; f < 4; ++f) {
      TriangleIndex adjacentTriangle = adjacentTriangles_[4*tet+f];
      if (adjacentTriangle == NO_ADJACENT) {
        trindex facet = tetFacet(tet, f);
        VertexIndex v0 = facet.indices[0];
        for (TriangleCornerIndex c = vertexToTriangleCorner[v0];
          c!= NO_ID; c = nextTriangleCornerAroundVertex[c]
          ) {
          TriangleIndex tri = c/3;
          trindex triFacet = triangleFacet(tri);
          if (facet == triFacet) {
            adjacentTriangles_[4*tet+f] = tri;
            break;
          }
        }
      }
    }
  }
}



}
