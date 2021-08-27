// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblTetOptimize.h"

#include <unordered_map>
#include <queue>

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

/* gmsh includes */
#include "Context.h"
#include "gmsh.h"
#include "GmshMessage.h"
#include "robin_hood.h"

#include "hblUtils.h"
#include "hblDiskTriangulation.h"

/* - Useful macros */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


using std::vector;
using std::unordered_map;
using std::array;
using std::pair;

namespace hbl {
  using namespace CppUtils;
  using namespace ArrayGeometry;

  constexpr bool PARANO = false;

  struct id2Hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  struct id3Hash {
    size_t operator()(const id3 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[2]), sizeof(id)));
      return seed;
    }
  };

  class DiskTriangulationManager {
    public:
    DiskTriangulationManager() {
      bool ok = load_disk_triangulations(trgls);
      if (!ok) {
        Msg::Error("failed to load disk triangulations");
      }
      F(i,trgls.trgls.size()) {
        DTriangulation* dt = trgls.trgls[i].get();
        if (dt->nv == dt->nb) {
          size_t n = dt->nv;
          if (n >= n_to_trgls.size()) n_to_trgls.resize(n+1);
          n_to_trgls[n].push_back(dt);
        }
      }
    }

    bool getDiskTriangulations(size_t n, std::vector<std::vector<id3>* > & triangulationPtrs) const {
      if (n >= n_to_trgls.size()) {
        Msg::Debug("No disk triangulation for size %li", n);
        return false;
      }
      triangulationPtrs.resize(n_to_trgls[n].size());
      F(i,triangulationPtrs.size()) {
        triangulationPtrs[i] = &(n_to_trgls[n][i]->triangles);
      }
      return true;
    }

    protected:
      DiskTriangulations trgls;
      std::vector<std::vector<DTriangulation*> > n_to_trgls;
  };


  struct TetMesh {
    vector<vec3> points;
    vector<id4> tets;

    /* additional info */
    vector<bool> vOnBdr; /* vertex is on boundary */
    vector<vector<id> > v2c; /* vertex to adjacent cells */
    vector<id2> iEdges; /* interior edges */
    robin_hood::unordered_set<id2,id2Hash> bdrEdges; /* edge is on boundary */
    robin_hood::unordered_set<id3,id3Hash> bdrTris; /* triangle is on boundary */
    vector<double> tetVolume; /* volume of each tet */
    vector<bool> dirty; /* flag on tet */
  };

  constexpr id TET_FACETS[][3] = 
  { {0, 2, 1},
    {0, 1, 3},
    {0, 3, 2},
    {3, 1, 2} };

  constexpr id TET_EDGES[6][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {3, 1}};

  inline id3 sface(id4 tet, id lf) {
    return sorted(tet[TET_FACETS[lf][0]],tet[TET_FACETS[lf][1]],tet[TET_FACETS[lf][2]]);
  }

  bool tetMeshIsValid(const TetMesh& M) {
    bool valid = true;
    robin_hood::unordered_map<id3,int,id3Hash> triCount;
    FC(c,M.tets.size(),M.tets[c][0] != NO_ID) {
      F(lf,4) {
        id3 tri = sface(M.tets[c],lf);
        triCount[tri] += 1;
      }
    }
    robin_hood::unordered_map<id2,int,id2Hash> bdrEdgeCount;
    for (auto& kv: triCount) {
      if (kv.second > 2) {
        Msg::Error("tetMeshIsValid: tet face adjacent to %li tets", kv.second);
        DBG(kv.first);
        valid = false;
      } else if (kv.second == 1) {
        auto it = M.bdrTris.find(kv.first);
        if (it == M.bdrTris.end()) {
          Msg::Error("tetMeshIsValid: tet face adjacent to one tet but not in boundary triangles");
          DBG(kv.first);
          valid = false;
        }
        const id3& tri = kv.first;
        F(le,3) {
          id v1 = tri[le];
          id v2 = tri[(le+1)%3];
          bdrEdgeCount[sorted(v1,v2)] += 1;
        }
      }
    }
    F(v,M.v2c.size()) {
      F(i,M.v2c[v].size()) F(j,M.v2c[v].size()) if (i < j) {
        id c1 = M.v2c[v][i];
        id c2 = M.v2c[v][j];
        std::vector<id> vert1 = { M.tets[c1][0], M.tets[c1][1], M.tets[c1][2], M.tets[c1][3]};
        std::vector<id> vert2 = { M.tets[c2][0], M.tets[c2][1], M.tets[c2][2], M.tets[c2][3]};
        std::vector<id> common = intersection(vert1,vert2);
        if (common.size() == 0 || common.size() > 3) {
          Msg::Error("tetMeshIsValid: tet %i and tet %i share %li vertices", c1, c2, common.size());
          DBG(M.tets[c1],M.tetVolume[c1]);
          DBG(M.tets[c2],M.tetVolume[c2]);
          valid = false;
        }
      }
    }
    for (auto& kv: bdrEdgeCount) {
      if (kv.second != 2) {
        /* boundary triangulation is not manifold */
        Msg::Error("tetMeshIsValid: boundary triangulation is not manifold, bdr edge valence: %li", kv.second);
        valid = false;
      }
    }

    return valid;
  }

  inline bool edgeOnBoundary(const TetMesh& M, id v1, id v2) {
    if (!M.vOnBdr[v1] || !M.vOnBdr[v2]) return false;
    id2 edge = sorted(v1,v2);
    auto it = M.bdrEdges.find(edge);
    return it != M.bdrEdges.end();
  }

  inline bool triangleOnBoundary(const TetMesh& M, const id3& stri) {
    if (!M.vOnBdr[stri[0]] || !M.vOnBdr[stri[1]] || !M.vOnBdr[stri[2]]) return false;
    auto it = M.bdrTris.find(stri);
    return it != M.bdrTris.end();
  }

  inline double tetVolume(const TetMesh& M, const id4& tet) {
    return 1./6. * basicOrient3d(M.points[tet[0]], M.points[tet[1]], M.points[tet[2]], M.points[tet[3]]);
  }

  bool cavityVolume(const TetMesh& M, const std::vector<id>& cavity, 
      double& volume, double& absVolume, size_t& nNeg) {
    volume = 0.;
    absVolume = 0.;
    nNeg = 0;
    for (id c: cavity) {
      if (M.dirty[c]) return false;
      if (M.tets[c][0] == NO_ID) return false;
      volume += M.tetVolume[c];
      absVolume += std::abs(M.tetVolume[c]);
      if (M.tetVolume[c] <= 0.) nNeg += 1;
    }
    return true;
  }

  bool cavityVolume(const TetMesh& M, const std::vector<id4>& tets, 
      double& volume, double& absVolume, size_t& nNeg) {
    volume = 0.;
    absVolume = 0.;
    nNeg = 0;
    F(i,tets.size()) {
      if (tets[i][0] == NO_ID) return false;
      double tvol = tetVolume(M, tets[i]);
      volume += tvol;
      absVolume += std::abs(tvol);
      if (tvol <= 0.) nNeg += 1;
    }
    return true;
  }

  bool isValidMeshTopology(const vector<id4>& tets) {
    bool valid = true;
    robin_hood::unordered_map<id3,int,id3Hash> triCount;
    FC(c,tets.size(),tets[c][0] != NO_ID) {
      F(lf,4) {
        id3 tri = sface(tets[c],lf);
        triCount[tri] += 1;
      }
    }

    robin_hood::unordered_map<id2,int,id2Hash> bdrEdgeCount;
    for (auto& kv: triCount) {
      if (kv.second > 2) {
        valid = false;
        return false;
      } else if (kv.second == 1) { /* boundary face */
        const id3& tri = kv.first;
        F(le,3) {
          id v1 = tri[le];
          id v2 = tri[(le+1)%3];
          bdrEdgeCount[sorted(v1,v2)] += 1;
        }
      }
    }

    for (auto& kv: bdrEdgeCount) {
      if (kv.second != 2) {
        /* boundary triangulation is not manifold */
        return false;
      }
    }

    return valid;
  }

  bool buildSwapTets(
      id v1, id v2,
      id r, /* rotation */
      const std::vector<id>& oVertices, 
      const std::vector<id3>& dtris,
      const id3& oRefOTri,
      const id3& oRefTri,
      vector<id4>& newTets) {
    std::vector<id> oVerticesR = oVertices;
    if (r > 0) {
      std::rotate(oVerticesR.begin(),oVerticesR.begin()+r,oVerticesR.end());
    }

    std::vector<id3> tris(dtris.size());
    F(j,tris.size()) F(lv,3) {
      tris[j][lv] = oVerticesR[dtris[j][lv]];
    }

    int invertAll = -1;
    newTets.resize(2*tris.size());
    F(k,tris.size()) {
      const id4 tet1 = {tris[k][0], tris[k][1], tris[k][2], v1};
      const id4 tet2 = {tris[k][0], tris[k][2], tris[k][1], v2};
      newTets[2*k+0] = tet1;
      newTets[2*k+1] = tet2;
      /* Ensure coherent orientation with cavity boundary */
      if (invertAll == -1) {
        F(lf,4) {
          id3 tetFace = {
            tet1[TET_FACETS[lf][0]],
            tet1[TET_FACETS[lf][1]],
            tet1[TET_FACETS[lf][2]]};
          if (sorted(tetFace[0],tetFace[1],tetFace[2]) == oRefOTri) {
            id3 tri = get_smallest_rotation(tetFace);
            if (tri == oRefTri) {
              invertAll = 0;
            } else {
              std::reverse(tri.begin(),tri.end());
              tri = get_smallest_rotation(tri);
              if (tri == oRefTri) {
                invertAll = 1;
              } else {
                Msg::Error("tryEdgeSwap: weird, reverse tri not matching");
                return false;
              }
            }
          }
        }
      }
    }
    if (invertAll == 1) {
      F(j,newTets.size()) {
        id tmp = newTets[j][2];
        newTets[j][2] = newTets[j][1];
        newTets[j][1] = tmp;
      }
    }
    return true;
  }

  bool tryEdgeSwap(TetMesh& M, id edgeId, const std::vector<id>& cavity, const DiskTriangulationManager& dtm, double& absVolDiff) {
    id v1 = M.iEdges[edgeId][0];
    id v2 = M.iEdges[edgeId][1];
    if (v1 == NO_ID || v2 == NO_ID) return false;

    if (PARANO) {
      vector<id4> tets(cavity.size());
      F(i,tets.size()) tets[i] = M.tets[cavity[i]];
      bool valid = isValidMeshTopology(tets);
      if (!valid) {
        Msg::Error("tryEdgeSwap: input is not valid topological mesh");
      }
    }

    double cavityVol = 0.;
    double cavityAbsVol = 0.;
    size_t nNeg = 0;
    bool okc = cavityVolume(M, cavity, cavityVol, cavityAbsVol, nNeg);
    if (!okc) return false;

    std::vector<id> ring;
    vector<id2> uedges;
    id r0 = NO_ID;
    for (id c: cavity) F(le,6) {
      id a = M.tets[c][TET_EDGES[le][0]];
      id b = M.tets[c][TET_EDGES[le][1]];
      if (a == v1 || a == v2) continue;
      if (b == v1 || b == v2) continue;
      if (r0 == NO_ID) r0 = a;
      uedges.push_back(sorted(a,b));
    }
    std::vector<id> oVertices;
    bool oko = getOrderedVerticesFromEdges(r0, uedges, oVertices);
    if (!oko || oVertices.size() < 3) {
      Msg::Error("tryEdgeSwap: failed to get ordered vertices on ring !");
      return false;
    }
    if (oVertices.back() == oVertices.front()) oVertices.pop_back();

    /* Reference cavity boundary triangle to control orientation */
    id3 oRefOTri = {NO_ID,NO_ID,NO_ID};
    id3 oRefTri = {NO_ID,NO_ID,NO_ID};
    {
      id c0 = cavity[0];
      F(lf,4) {
        id3 tetFace = {
          M.tets[c0][TET_FACETS[lf][0]],
          M.tets[c0][TET_FACETS[lf][1]],
          M.tets[c0][TET_FACETS[lf][2]]};
        if (tetFace[0] != v1 && tetFace[1] != v1 && tetFace[2] != v1) continue;
        if (tetFace[0] == v2 || tetFace[1] == v2 || tetFace[2] == v2) continue;
        oRefOTri = sorted(tetFace[0],tetFace[1],tetFace[2]);
        oRefTri = get_smallest_rotation(tetFace);
      }
      if (oRefTri[0] == NO_ID) {
        Msg::Error("tryEdgeSwap: No reference triangle ?");
        return false;
      }
    }

    /* Get all the disk triangulations with no interior vertex 
     * and N vertices on the boundary */
    size_t N = oVertices.size();
    std::vector<std::vector<id3>* > triangulationPtrs;
    bool okg = dtm.getDiskTriangulations(N,triangulationPtrs);
    if (!okg) return false;

    /* Loop over the triangulations and try the swaps, keep the best one */
    double best = cavityAbsVol;
    id bestI = NO_ID;
    int bestR = 0;
    size_t bestNN =0;
    vector<id4> newTets;
    F(i,triangulationPtrs.size()) {
      const std::vector<id3>& dtris = *(triangulationPtrs[i]);

      // Loop over all rotations of the disk triangulation 
      for (int r = 0; r <= int(N-1); ++r) {
        bool oks = buildSwapTets(v1, v2, r, oVertices, dtris, oRefOTri, oRefTri, newTets);
        if (!oks) return false;

        // Compare absolute volume
        double cVol2 = 0.;
        double cAbsVol2 = 0.;;
        size_t nNeg2 = 0;
        cavityVolume(M, newTets, cVol2, cAbsVol2, nNeg2);
        if (cAbsVol2 < best) {
          best = cAbsVol2;
          bestI = i;
          bestR = r;
          bestNN = nNeg2;
        }
      }
    }
    if (bestI == NO_ID) return false; /* no good swap */

    const std::vector<id3>& dtris = *(triangulationPtrs[bestI]);
    bool oks = buildSwapTets(v1, v2, bestR, oVertices, dtris, oRefOTri, oRefTri, newTets);
    if (!oks) return false;

    /* Check if the remeshing is not breaking tet mesh topology */
    {
      bool valid = isValidMeshTopology(newTets);
      if (!valid) {
        Msg::Warning("--- new cavity tet mesh is not topologicaly valid, cancel swap");
        return false;
      }

      vector<id> adjTets = M.v2c[v1];
      append(adjTets, M.v2c[v2]);
      for (id v: oVertices) append(adjTets, M.v2c[v]);
      adjTets = difference(adjTets, cavity);

      /* Collect faces of cavity-adjacent tetra */
      vector<id3> adjIFaces;
      F(i,adjTets.size()) F(lf,4) {
        id3 tri = sface(M.tets[adjTets[i]],lf);
        adjIFaces.push_back(tri);
      }
      /* Ensure new interior faces are distinct from existing ones */
      F(i,newTets.size()) {
        if (i % 2 == 1) continue; /* ignore inferior tets */
        id3 tri = sorted(newTets[i][0], newTets[i][1], newTets[i][2]);
        auto it = std::find(adjIFaces.begin(),adjIFaces.end(),tri);
        if (it != adjIFaces.end()) {
          Msg::Warning("--- new interior face produced by swap already in tet mesh outside cavity, cancel swap");
          return false;
        }
      }

      // vector<id4> adjTetsVert(adjTets.size());
      // F(i,adjTetsVert.size()) {
      //   adjTetsVert[i] = M.tets[adjTets[i]];
      //   std::sort(adjTetsVert[i].begin(),adjTetsVert[i].end());
      // }
      // F(i,newTets.size()) {
      //   id4 query = newTets[i];
      //   std::sort(query.begin(),query.end());
      //   auto it = std::find(adjTetsVert.begin(), adjTetsVert.end(), query);
      //   if (it != adjTetsVert.end()) {
      //     Msg::Warning("--- new tet produced by swap already in tet mesh outside cavity, cancel swap");
      //     return false;
      //   }
      // }
    }

    /* Update mesh datastructure with the edge swap */
    /* - add new tets */
    std::vector<id> new2Mt(newTets.size());
    F(i,newTets.size()) {
      new2Mt[i] = M.tets.size();
      M.tets.push_back(newTets[i]);
      M.tetVolume.push_back(tetVolume(M, newTets[i]));
      M.dirty.push_back(true);
      F(lv,4) {
        id v = newTets[i][lv];
        M.v2c[v].push_back(new2Mt[i]);
      }
    }
    vector<id4> dbg_old_tets;
    /* - remove previous tets */
    for (id c: cavity) {
      F(lv,4) {
        id v = M.tets[c][lv];
        M.v2c[v] = difference(M.v2c[v],cavity);
      }
      M.tetVolume[c] = DBL_MAX;
      dbg_old_tets.push_back(M.tets[c]);
      M.tets[c] = {NO_ID,NO_ID,NO_ID,NO_ID};
    }
    /* - update interior edges */
    M.iEdges[edgeId] = {NO_ID,NO_ID};
    {
      // Msg::Info("------");
      // DBG(oVertices);
      // new edges (knowing 4-th vertex is v1 or v2 is newTets)
      std::unordered_map<id2,int,id2Hash> edgeCount;
      F(i,newTets.size()) {
        if (i % 2 == 1) continue; /* ignore inferior tets */
        F(le,3) {
          id tv1 = newTets[i][le];
          id tv2 = newTets[i][(le+1)%3];
          edgeCount[sorted(tv1,tv2)] += 1;
        }
      }
      for (auto& kv: edgeCount) if (kv.second == 2) {
        // DBG("+", kv.first);
        M.iEdges.push_back(kv.first);
      }
    }
    absVolDiff = best - cavityAbsVol;
    Msg::Debug("--- edge swap (%i,%i): %li -> %li tets, delta(|vol|): %.3e", v1, v2, cavity.size(), newTets.size(), absVolDiff);

    if (PARANO && !tetMeshIsValid(M)) {
      Msg::Error("bad swap ?");
      DBG("INPUT");
      F(i,cavity.size()) {
        DBG(cavity[i], dbg_old_tets[i]);
        vector<vec3> pts = {
          M.points[dbg_old_tets[i][0]],
          M.points[dbg_old_tets[i][1]],
          M.points[dbg_old_tets[i][2]],
          M.points[dbg_old_tets[i][3]]
        };
        GeoLog::add(pts,0., "swap_before", true);
      }
      DBG("OUTPUT");
      F(i,newTets.size()) {
        DBG(new2Mt[i], newTets[i]);
        vector<vec3> pts = {
          M.points[newTets[i][0]],
          M.points[newTets[i][1]],
          M.points[newTets[i][2]],
          M.points[newTets[i][3]]
        };
        GeoLog::add(pts,1., "swap_after", true);
      }
      GeoLog::flush();
      gmsh::fltk::run();
      abort();
    }

    // DBG("-> better found", N, bestI, bestR, "|", cavityAbsVol, nNeg, "->", best, bestNN);
    return true;
  }

  bool optimizeTetMeshVolumeWithSwaps(std::vector<ArrayGeometry::vec3>& points, std::vector<id4>& tets) {
    Msg::Info("Optimize tet mesh (%li vertices, %li tets) with edge swaps ...", points.size(), tets.size());
    Msg::Warning("NOT WORKING YET, STILL IN PROGRESS");

    DiskTriangulationManager dtm;

    TetMesh M;
    M.points = points;
    M.tets  = tets;
    M.v2c.resize(M.points.size());

    robin_hood::unordered_map<id3,int,id3Hash> triCount;

    F(c,M.tets.size()) {
      F(lv,4) M.v2c[M.tets[c][lv]].push_back(c);
      F(lf,4) {
        id3 tri = sface(M.tets[c],lf);
        triCount[tri] += 1;
      }
    }

    /* Flag boundary */
    M.vOnBdr.resize(M.points.size(),false);
    for (auto& kv : triCount) {
      if (kv.second == 1) {
        M.bdrTris.insert(kv.first);
        F(lv,3) {
          id v1 = kv.first[lv];
          M.vOnBdr[v1] = true;
          id v2 = kv.first[(lv+1)%3];
          id2 edge = sorted(v1,v2);
          M.bdrEdges.insert(edge);
        }
      } else if (kv.second > 2) {
        Msg::Error("optimizeTetMeshVolumeWithSwaps: wrong input, triangular face adjacent to %li tets", kv.second);
        return false;
      }
    }

    /* List of internal edges */
    M.iEdges.reserve(6*M.tets.size());
    F(c,M.tets.size()) {
      F(le,6) {
        id v1 = M.tets[c][TET_EDGES[le][0]];
        id v2 = M.tets[c][TET_EDGES[le][1]];
        if (!edgeOnBoundary(M, v1, v2)) {
          M.iEdges.push_back(sorted(v1,v2));
        }
      }
    }
    sort_unique(M.iEdges);

    Msg::Info("- verify tet mesh validity of input ...");
    bool validInput = tetMeshIsValid(M);
    if (!validInput) {
      return false;
    }

    /* Optimization loop */
    size_t nNeg0 = 0;
    const size_t iterMax = 1e6;
    size_t iter = 0;
    size_t nSwap = 0;
    while (iter < iterMax) {
      size_t nSwapIter = 0;

      /* Update volume of each tet */
      M.dirty.clear();
      M.dirty.resize(M.tets.size(),false);
      M.tetVolume.clear();
      M.tetVolume.resize(M.tets.size(),DBL_MAX);
      double volAbs = 0.;
      size_t nNegT = 0;
      size_t nTet = 0;
      double volT = 0.;
      FC(c,M.tets.size(),M.tets[c][0] != NO_ID) {
        double tv = tetVolume(M,M.tets[c]);
        M.tetVolume[c] = tv;
        volAbs += std::abs(tv);
        volT += tv;
        if (tv <= 0.) nNegT += 1;
        nTet += 1;
      }
      if (iter == 0) {
        Msg::Info("- initial stats: %li tets, sum(vol): %.5e, sum(|vol|): %.5e, #(vol<0): %li", 
            tets.size(), volT, volAbs, nNegT);
        nNeg0 = nNegT;
      }
      double volAbsInit = volAbs;

      /* Loop on internal edges */
      size_t nEdges = M.iEdges.size();
      vector<id> cavity;
      F(i,nEdges) {
        id v1 = M.iEdges[i][0];
        id v2 = M.iEdges[i][1];
        if (v1 == NO_ID || v2 == NO_ID) continue;
        cavity = intersection(M.v2c[v1],M.v2c[v2]);
        if (cavity.size() <= 2) {
          Msg::Warning("optimizeTetMeshVolumeWithSwaps: iter %li, edge %i (%i,%i): cavity size: %li", iter, i, v1, v2, cavity.size());
          DBG(cavity,M.tets[cavity[0]],M.tets[cavity[1]]);
          continue;
        }
        double cavityVol = 0.;
        double cavityAbsVol = 0.;
        size_t nNeg = 0;
        if (cavityVolume(M, cavity, cavityVol, cavityAbsVol, nNeg)) {
          if (nNeg == 0) continue;
          // Msg::Info("-- check edge %i (%i,%i): cavity size %li, volume: %.3e, #(vol<=0): %li", i, v1, v2, cavity.size(), cavityVol, nNeg);

          double absVolDiff = 0.;
          bool swap = tryEdgeSwap(M, i, cavity, dtm, absVolDiff);
          if (swap) {
            nSwapIter += 1;
            volAbs += absVolDiff;
          }
        }
      }
      nSwap += nSwapIter;
      Msg::Info("- iter %li: #(det<0.): %li/%li, %li edge swaps, |vol|: %.5e -> %.5e", iter+1, nNegT, nTet, nSwapIter, volAbsInit, volAbs);
      if (nSwapIter == 0) break;

      iter += 1;
    }

    Msg::Info("- verify tet mesh validity ...");
    bool valid = tetMeshIsValid(M);
    if (!valid) {
      return false;
    }

    /* Update input/output tets */
    double volAbs = 0.;
    double vol = 0.;
    size_t nNeg = 0;
    size_t nTet = 0;
    size_t nTetInit = tets.size();
    tets.clear();
    FC(c,M.tets.size(),M.tets[c][0] != NO_ID) {
      tets.push_back(M.tets[c]);
      double tv = tetVolume(M,M.tets[c]);
      volAbs += std::abs(tv);
      vol += tv;
      if (tv <= 0.) nNeg += 1;
      nTet += 1;
    }

    Msg::Info("- final stats: %li edge swaps, %li -> %li tets, sum(vol): %.5e, sum(|vol|): %.5e, #(vol<0): %li -> %li", 
        nSwap, nTetInit, tets.size(), vol, volAbs, nNeg0, nNeg);

    return true;
  }

}

