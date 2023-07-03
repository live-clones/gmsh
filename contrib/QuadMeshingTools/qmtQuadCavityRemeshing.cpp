// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtQuadCavityRemeshing.h"

/* System includes */
// #include <vector>
// #include <array>
// #include <unordered_map>
// #include <cstdint>
// #include <cmath>
#include <queue>
#include <unordered_set>
#include <cassert>
// #include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "BackgroundMesh.h"
#include "StringUtils.h"
#include "meshOctreeLibOL.h"
#include "gmsh.h" // api

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "qmtMeshUtils.h"
#include "qmtMeshGeometryOptimization.h"
#include "row_echelon_integer.hpp"
#include "geolog.h"
#include "robin_hood.h" // fast unordered_set and unordered_map

using namespace CppUtils;

const size_t PATTERN_QUAD_REGULAR = 0;
const size_t PATTERN_TRIANGLE = 1;
const size_t PATTERN_PENTAGON = 2;
const size_t PATTERN_QUAD_DIAG35 = 3;
const size_t PATTERN_QUAD_ALIGNED35 = 4;
const size_t PATTERN_QUAD_CHORD_UTURN = 5;
const size_t PATTERN_2CORNERS = 6;
const size_t PATTERN_1CORNER = 7;
const size_t PATTERN_DISK = 8;

size_t patternNumberOfCorners(size_t pId)
{
  switch(pId) {
  case PATTERN_QUAD_REGULAR: return 4;
  case PATTERN_TRIANGLE: return 3;
  case PATTERN_PENTAGON: return 5;
  case PATTERN_QUAD_DIAG35: return 4;
  case PATTERN_QUAD_ALIGNED35: return 4;
  case PATTERN_QUAD_CHORD_UTURN: return 4;
  case PATTERN_2CORNERS: return 2;
  case PATTERN_1CORNER: return 1;
  case PATTERN_DISK: return 0;
  default: Msg::Error("patternNumberOfCorners: pattern not supported");
  };
  return 0;
}

namespace QMT {
  using std::array;
  using std::vector;
  using namespace ArrayGeometry;

  /* robin_hood hash sets and maps are much faster than the STL version */
  // using std::unordered_map;
  // using std::unordered_set;

  template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
            typename KeyEqual = std::equal_to<Key>,
            size_t MaxLoadFactor100 = 80>
  using unordered_map =
    robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

  template <typename Key, typename Hash = robin_hood::hash<Key>,
            typename KeyEqual = std::equal_to<Key>,
            size_t MaxLoadFactor100 = 80>
  using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key,
                                                  void, Hash, KeyEqual>;

  using id = uint32_t;
  using id2 = std::array<id, 2>;
  using id4 = std::array<id, 4>;

  constexpr bool DBG_VERBOSE = false;

  /* Quad meshes of patterns, known at compile time
   * These patterns must be CONVEX
   * WARNING: orientation of quads must be coherent ! */
  const std::vector<std::pair<size_t, std::vector<id4> > > quad_meshes = {
    /* regular quad patch */
    {PATTERN_QUAD_REGULAR, {{0, 1, 2, 3}}},

    /* triangular patch with one val3 singularity */
    {PATTERN_TRIANGLE, {{0, 1, 6, 5}, {1, 2, 3, 6}, {3, 4, 5, 6}}},

    /* pentagonal patch with one val5 singularity */
    {PATTERN_PENTAGON,
     {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}}},

    /* quad patch with one val3 and one val5 singularities (on diagonal) */
    {PATTERN_QUAD_DIAG35,
     {{0, 1, 2, 3},
      {0, 5, 4, 1},
      {0, 7, 6, 5},
      {0, 9, 8, 7},
      {0, 3, 10, 9},
      {8, 9, 10, 11}}},

    /* quad patch with one val3, one val5 singularities and two regular inside
       (3-5 pair for size transition) */
    {PATTERN_QUAD_ALIGNED35,
     {{0, 1, 2, 3},
      {0, 5, 4, 1},
      {0, 7, 6, 5},
      {0, 9, 8, 7},
      {0, 3, 10, 9},
      {9, 10, 12, 11},
      {3, 13, 12, 10},
      {8, 9, 11, 14},
      {2, 15, 13, 3}}},

    /* quad patch with two val3, two val5 inside, size transition by having a
       chord making a U-turn */
    {PATTERN_QUAD_CHORD_UTURN,
     {{0, 1, 2, 3},
      {0, 5, 4, 1},
      {0, 7, 6, 5},
      {0, 9, 8, 7},
      {0, 3, 10, 9},
      {9, 10, 12, 11},
      {9, 11, 14, 13},
      {8, 9, 13, 15},
      {6, 7, 8, 15}}},

    /* patch with two corners, two val3 singularities inside (good for eye
       shape) */
    {PATTERN_2CORNERS,
     {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 3, 6, 5}, {4, 5, 6, 7}}},

    /* patch with one corner, three val3 singularities inside and one regular
       vertiex */
    {PATTERN_1CORNER,
     {{0, 1, 6, 5},
      {1, 2, 7, 6},
      {2, 3, 8, 7},
      {3, 4, 9, 8},
      {4, 5, 6, 9},
      {6, 7, 8, 9}}},

    /* disk pattern (no corners) */
    {PATTERN_DISK,
     {{0, 1, 6, 5}, {1, 2, 7, 6}, {2, 3, 4, 7}, {0, 5, 4, 3}, {4, 5, 6, 7}}},
  };

  constexpr id NO_ID = (id)-1;
  inline id2 sorted(id v1, id v2)
  {
    if(v1 < v2) { return {v1, v2}; }
    else {
      return {v2, v1};
    }
  }
  inline id2 sorted(id2 e)
  {
    if(e[0] < e[1]) { return {e[0], e[1]}; }
    else {
      return {e[1], e[0]};
    }
  }

  struct id2hash {
    size_t operator()(const id2 &pr) const noexcept
    {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  struct vidHash {
    size_t operator()(const std::vector<id> &p) const noexcept
    {
      size_t seed = 0;
      for(size_t i = 0; i < p.size(); ++i) {
        hash_combine(seed, robin_hood::hash_bytes(&(p[i]), sizeof(id)));
      }
      return seed;
    }
  };

  bool build_quad_chord(const vector<id4> &quadEdges,
                        const vector<vector<id> > &e2f, id eStart,
                        std::vector<id> &chordEdges)
  {
    chordEdges.size();

    vector<bool> visited(e2f.size(), false);

    /* Init */
    visited[eStart] = true;
    std::queue<id> qq;
    qq.push(eStart);

    /* Propagation */
    while(qq.size() > 0) {
      id e = qq.front();
      qq.pop();
      chordEdges.push_back(e);

      for(size_t lf = 0; lf < e2f[e].size(); ++lf) {
        id f = e2f[e][lf];
        id oe = NO_ID;
        for(size_t le = 0; le < 4; ++le) {
          if(quadEdges[f][le] == e) {
            oe = quadEdges[f][(le + 2) % 4];
            break;
          }
        }
        if(oe == NO_ID) return false;
        if(visited[oe]) continue;
        visited[oe] = true;
        qq.push(oe);
      }
    }

    sort_unique(chordEdges);

    return true;
  }

  double sum_sqrt(const vector<int> &values)
  {
    double s = 0.;
    for(const auto &v : values) s += sqrt(v);
    return s;
  }

  bool all_strictly_positive(const vector<int> &values)
  {
    for(const auto &v : values)
      if(v <= 0) return false;
    return true;
  }

  /* Struct to interface with row_echelon_integer.hpp */
  struct IMatrix {
    /* Data */
    int m;
    int n;
    std::vector<int> a;

    /* Methods */
    IMatrix(int m_, int n_) : m(m_), n(n_) { a.resize(m * n, 0); }

    void set(int i, int j, int value) { a[i + j * m] = value; }
    int get(int i, int j) const { return a[i + j * m]; }

    int tansform_to_row_reduced_echelon() { return i4mat_ref(m, n, a.data()); }

    void print(const std::string &title = "IMatrix")
    {
      i4mat_print(m, n, a.data(), title);
    }

    double solution_score(const std::vector<int> &x)
    {
      if(x.size() != (size_t)n - 1) return 0.;
      for(int j = 0; j < n - 1; ++j) {
        if(x[j] == 0) return 0.;
      }

      /* Verify x is solution */
      for(int i = 0; i < m; ++i) {
        int sum = 0;
        for(int j = 0; j < n - 1; ++j) { sum += x[j] * get(i, j); }
        sum += get(i, n - 1);
        if(sum != 0) { /* Not a solution */
          return 0.;
        }
      }

      return sum_sqrt(x);
    }

    double get_positive_solution_DFS(std::vector<int> &x, int &count,
                                     int count_limit,
                                     const std::vector<double> &x_ideal,
                                     int &ncalls)
    {
      if(x.size() == 0) {
        x.resize(n - 1, 0);
        /* Check if a unknown is uncontrained. Happen with purely internal
         * chords */
        int sum_rhs = 0;
        vector<bool> touched(x.size(), false);
        for(int i = 0; i < m; ++i) {
          for(int j = 0; j < n - 1; ++j) {
            int acoef = get(i, j);
            if(acoef != 0) { touched[j] = true; }
          }
          sum_rhs += std::abs(get(i, n - 1));
        }
        for(int j = 0; j < n - 1; ++j)
          if(!touched[j]) {
            x[j] = sum_rhs / (n - 1);
            if(x[j] < 0) x[j] = 1;
          }
      }

      ncalls += 1;
      if(ncalls > 1e7) {
        Msg::Debug(
          "get_positive_solution_DFS: infinite loop ? %i calls in recursion",
          ncalls);
        return 0.;
      }
      if(all_strictly_positive(x)) count += 1;
      if(count > count_limit) return 0.;

      /* Stop condition: x is solution and has positive score */
      double current_score = solution_score(x);
      if(current_score > 0.) return current_score;

      double best_score = 0.;
      vector<int> best_x;
      std::vector<int> undetermined;
      /* Loop from last line to first line */
      for(int i = m - 1; i >= 0; --i) {
        undetermined.clear();
        /* Check line */
        int total = -1 * get(i, n - 1);
        for(int j = 0; j < n - 1; ++j) {
          int w = get(i, j);
          if(w != 0) {
            if(x[j] == 0) { undetermined.push_back(j); }
            else {
              total -= w * x[j];
            }
          }
        }
        if(undetermined.size() == 0) {
          if(total == 0) { continue; }
          else {
            return 0.;
          }
        }

        /* Fix one value and make recursive call */
        if(undetermined.size() == 1) {
          int j = undetermined[0];
          int w = get(i, j);
          if(total % w == 0) {
            int candidate = total / w;
            if(candidate < 1) return 0.;
            vector<int> x2 = x;
            x2[j] = candidate;
            double sub_score = get_positive_solution_DFS(x2, count, count_limit,
                                                         x_ideal, ncalls);
            if(sub_score > 0.) { /* Found a solution ! Return this one */
              x = x2;
              return sub_score;
            }
          }
        }
        else {
          double sum = 0.;
          for(size_t k = 0; k < undetermined.size(); ++k) {
            int j = undetermined[k];
            int w = get(i, j);
            sum += std::abs(w);
          }
          for(size_t k = 0; k < undetermined.size(); ++k) {
            int j = undetermined[k];
            int w = get(i, j);
            double ideal_repartition = 1. / sum * double(total);
            int xmin = 1;
            int xmax = int(double(total) / double(w));
            if(xmax < xmin) return 0.;
            if((size_t)j < x_ideal.size()) { ideal_repartition = x_ideal[j]; }

            vector<std::pair<double, int> > prio_candidate;
            if(xmax == xmin) { prio_candidate.push_back({0., xmin}); }
            else {
              for(int candidate = xmin; candidate < xmax + 1; ++candidate) {
                double dist = std::pow(ideal_repartition - candidate, 2);
                prio_candidate.push_back({dist, candidate});
              }
            }

            // TODO: better priority, see 2 corner cases
            std::sort(prio_candidate.begin(), prio_candidate.end());
            vector<int> x2;
            for(size_t l = 0; l < prio_candidate.size(); ++l) {
              int candidate = prio_candidate[l].second;
              x2 = x;
              x2[j] = candidate;
              double sub_score = get_positive_solution_DFS(
                x2, count, count_limit, x_ideal, ncalls);
              if(sub_score > 0.) { /* Found a solution ! Return this one */
                x = x2;
                return sub_score;
              }
            }
          }
        }
      }
      if(best_score > 0.) {
        x = best_x;
        return best_score;
      }
      return 0.;
    }
  };

  struct QuadMeshPattern {
    size_t patternId;
    id n = 0;
    vector<id2> edges;
    vector<id4> quads; /* contains edge id's, not vertex ! */
    vector<id4> qvertices;
    vector<bool> vOnBdr;
    vector<id> eChordId;
    vector<vector<id> > v2e;
    vector<vector<id> > e2f;
    vector<vector<id> > chords;
    vector<vector<id> > sides;
    id ncorners;

    bool load(size_t pId, const std::vector<id4> &quadVertices)
    {
      patternId = pId;
      ncorners = 0;
      edges.reserve(2 * quadVertices.size());
      quads.reserve(quadVertices.size());
      unordered_map<id2, id, id2hash> vpair2e;
      n = 0;
      for(size_t f = 0; f < quadVertices.size(); ++f) {
        id4 quad;
        for(size_t le = 0; le < 4; ++le) {
          id v1 = quadVertices[f][le];
          id v2 = quadVertices[f][(le + 1) % 4];
          n = std::max(n, v1 + 1);
          id2 oedge = {v1, v2};
          id2 vpair = sorted(v1, v2);
          auto it = vpair2e.find(vpair);
          id e = 0;
          if(it == vpair2e.end()) {
            e = edges.size();
            edges.push_back(oedge);
            vpair2e[vpair] = e;
          }
          else {
            e = it->second;
          }
          quad[le] = e;
        }
        quads.push_back(quad);
        qvertices.push_back(quadVertices[f]);
      }
      v2e.resize(n);
      for(size_t e = 0; e < edges.size(); ++e) {
        v2e[edges[e][0]].push_back(e);
        v2e[edges[e][1]].push_back(e);
      }
      e2f.resize(edges.size());
      for(size_t f = 0; f < quads.size(); ++f) {
        for(size_t le = 0; le < 4; ++le) { e2f[quads[f][le]].push_back(f); }
      }
      vOnBdr.resize(n, false);
      for(size_t e = 0; e < e2f.size(); ++e)
        if(e2f[e].size() == 1) {
          vOnBdr[edges[e][0]] = true;
          vOnBdr[edges[e][1]] = true;
        }

      { /* Build chords of the quad mesh */
        chords.clear();
        eChordId.resize(edges.size(), NO_ID);
        vector<id> chordEdges;
        for(size_t e = 0; e < edges.size(); ++e)
          if(eChordId[e] == NO_ID) {
            chordEdges.clear();
            bool ok = build_quad_chord(quads, e2f, e, chordEdges);
            if(!ok) return false;
            for(id e : chordEdges) { eChordId[e] = chords.size(); }
            chords.push_back(chordEdges);
          }
      }

      { /* Build the boundary sides (seperated by convex corners) */
        sides.clear();
        vector<id> *cur_side = NULL;
        for(id v0 = 0; v0 < n; ++v0)
          if(vOnBdr[v0] && v2e[v0].size() == 2) {
            id v = v0;
            id e = NO_ID;
            do {
              if(v2e[v].size() == 2) { /* concave corner */
                sides.resize(sides.size() + 1);
                cur_side = &sides.back();
                ncorners += 1;
              }
              for(id ee : v2e[v])
                if(ee != e && e2f[ee].size() == 1) {
                  if(edges[ee][0] == v) { /* assume edges are ordered on bdr */
                    e = ee;
                    break;
                  }
                }
              if(e == NO_ID) {
                Msg::Error("load, edge not found !");
                return false;
              }
              cur_side->push_back(e);
              id v2 = (edges[e][0] != v) ? edges[e][0] : edges[e][1];
              v = v2;
            } while(v != v0);
            break;
          }
        if(cur_side == NULL) { /* No convex corner, should be disk disk */
          sides.resize(sides.size() + 1);
          cur_side = &sides.back();
          for(id v0 = 0; v0 < n; ++v0)
            if(vOnBdr[v0] && v2e[v0].size() == 3) {
              id v = v0;
              id e = NO_ID;
              do {
                for(id ee : v2e[v])
                  if(ee != e && e2f[ee].size() == 1) {
                    if(edges[ee][0] ==
                       v) { /* assume edges are ordered on bdr */
                      e = ee;
                      break;
                    }
                  }
                if(e == NO_ID) {
                  Msg::Error("load, edge not found !");
                  return false;
                }
                cur_side->push_back(e);
                id v2 = (edges[e][0] != v) ? edges[e][0] : edges[e][1];
                v = v2;
              } while(v != v0);
              break;
            }
        }
        if(cur_side == NULL) return false;
      }

      return true;
    }
  };

  double patternIrregularity(const QuadMeshPattern &M)
  {
    double irreg = 0.;
    for(size_t i = 0; i < M.n; ++i)
      if(!M.vOnBdr[i]) { irreg += std::pow(double(M.v2e[i].size()) - 4., 2); }
    return irreg;
  }

  double checkPatternMatching(const QuadMeshPattern &P,
                              const std::vector<size_t> &sideSizes,
                              vector<int> &slt)
  {
    slt.clear();
    size_t N = sideSizes.size();
    bool possible = true;
    for(size_t s = 0; s < N; ++s) {
      if(sideSizes[s] < P.sides[s].size() + 1) {
        /* on given side, less edges in the cavity than edges in the pattern */
        possible = false;
        break;
      }
    }
    if(!possible) return 0.;

    int nvars = 0;
    for(id v : P.eChordId) nvars = std::max(nvars, (int)v + 1);
    IMatrix mat(N, nvars + 1);
    for(size_t s = 0; s < N; ++s) {
      for(size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        id var = P.eChordId[e];
        mat.set(s, var, mat.get(s, var) + 1);
      }
      mat.set(s, nvars, -1. * (sideSizes[s] - 1));
    }
    mat.tansform_to_row_reduced_echelon();

    // TODO IDEA
    // - give ideal_repartition to the get_positive_solution_DFS() fct ?
    //   to control a bit the quantization
    // - other idea: use row echelon to compute null space [x_kernel, ...] and
    // find
    //               solution x0 + lambda * x_kernel that maximize an objective
    //               function ?
    vector<double> ideal_repartition;
    if(P.patternId == PATTERN_2CORNERS) {
      ideal_repartition.resize(P.chords.size(), 0);
      size_t navg = (sideSizes[0] + sideSizes[1] - 2) / 2;
      for(size_t j = 0; j < P.chords.size(); ++j) {
        if(P.chords[j].size() == 3) { ideal_repartition[j] = 0.95 * navg; }
        else if(P.chords[j].size() == 4) {
          ideal_repartition[j] = 0.05 * navg;
        }
        else {
          Msg::Error("setting ideal_repartition for PATTERN_2CORNERS, should "
                     "not happen");
        }
      }
    }
    else if(P.patternId == PATTERN_DISK) {
      // TODO: detect circular chord and use a smaller ideal_repartition on it
    }
    double score = 0.;
    slt.clear();
    int count = 0;
    int count_limit =
      100; /* limit on the number of solution tried in the DFS */
    int ncalls = 0;
    score = mat.get_positive_solution_DFS(slt, count, count_limit,
                                          ideal_repartition, ncalls);

    return score;
  }

  double checkPatternMatchingWithRotations(const QuadMeshPattern &P,
                                           const std::vector<size_t> &sideSizes,
                                           int &rotation)
  {
    size_t N = sideSizes.size();
    if(P.sides.size() != N) return 0.;

    vector<size_t> ssr = sideSizes;
    vector<int> slt;

    double best = 0.;
    int rot = 0;

    /* Initial config */
    {
      double match = checkPatternMatching(P, ssr, slt);
      if(match > best) {
        best = match;
        rotation = rot;
      }
    }

    /* Forward rotation */
    for(size_t r = 1; r < ssr.size(); ++r) {
      rot += 1;
      std::rotate(ssr.begin(), ssr.begin() + 1, ssr.end());
      double match = checkPatternMatching(P, ssr, slt);
      if(match > best) {
        best = match;
        rotation = rot;
      }
    }

    /* Try in reverse order */
    rot = 0;
    ssr = sideSizes;
    std::reverse(ssr.begin(), ssr.end());
    for(size_t r = 1; r < ssr.size(); ++r) {
      rot -= 1;
      std::rotate(ssr.begin(), ssr.begin() + 1, ssr.end());
      double match = checkPatternMatching(P, ssr, slt);
      if(match > best) {
        best = match;
        rotation = rot;
      }
    }

    return best;
  }

  std::vector<MVertex *> createVertices(GFace *gf, MVertex *v1, MVertex *v2,
                                        int n,
                                        std::vector<MVertex *> &newVertices)
  {
    bool haveParam = gf->haveParametrization();
    std::vector<MVertex *> r;
    r.push_back(v1);
    double uv1[2] = {0., 0.};
    double uv2[2] = {0., 0.};
    if(haveParam) {
      setVertexGFaceUV(gf, v1, uv1);
      setVertexGFaceUV(gf, v2, uv2);
    }
    for(int i = 1; i < n; i++) {
      double xi = (double)i / n;
      SPoint3 p((1. - xi) * v1->x() + xi * v2->x(),
                (1. - xi) * v1->y() + xi * v2->y(),
                (1. - xi) * v1->z() + xi * v2->z());
      double uv[2] = {0., 0.};
      if(haveParam) {
        uv[0] = (1. - xi) * uv1[0] + xi * uv2[0];
        uv[1] = (1. - xi) * uv1[1] + xi * uv2[1];
      }
      MVertex *vNew = new MFaceVertex(p.x(), p.y(), p.z(), gf, uv[0], uv[1]);
      newVertices.push_back(vNew);
      r.push_back(vNew);
    }
    r.push_back(v2);
    return r;
  }

  std::vector<MVertex *> reverseVector(const std::vector<MVertex *> &v)
  {
    std::vector<MVertex *> r;
    for(size_t i = 0; i < v.size(); i++) r.push_back(v[v.size() - 1 - i]);
    return r;
  }

  void createQuadPatch(GFace *gf, const std::vector<MVertex *> &s1,
                       const std::vector<MVertex *> &s2,
                       const std::vector<MVertex *> &s3,
                       const std::vector<MVertex *> &s4,
                       std::vector<MElement *> &newQuads,
                       std::vector<MVertex *> &newVertices)
  {
    std::vector<MVertex *> s3r = reverseVector(s3);
    std::vector<MVertex *> s4r = reverseVector(s4);
    std::vector<std::vector<MVertex *> > grid(s1.size());
    for(size_t i = 0; i < grid.size(); ++i) grid[i].resize(s2.size(), NULL);
    grid.front() = s4r;
    grid.back() = s2;

    /* Fill the interior with transfinite interpolation */
    if(s1.size() > 2) {
      SVector3 c00 = s1[0]->point();
      SVector3 c10 = s2[0]->point();
      SVector3 c11 = s3[0]->point();
      SVector3 c01 = s4[0]->point();
      for(size_t i = 1; i < s1.size() - 1; i++) {
        grid[i][0] = s1[i];
        grid[i].back() = s3r[i];

        if(s2.size() <= 2) continue;

        double u = double(i) / double(s1.size() - 1.);
        SVector3 s1u = s1[i]->point();
        SVector3 s3u = s3r[i]->point();

        for(size_t j = 1; j < s2.size() - 1; j++) {
          double v = double(j) / double(s2.size() - 1.);
          SVector3 s2v = s2[j]->point();
          SVector3 s4v = s4r[j]->point();

          SVector3 p = (1. - v) * s1u + v * s3u + (1. - u) * s4v + u * s2v -
                       ((1. - u) * (1. - v) * c00 + u * v * c11 +
                        u * (1. - v) * c10 + (1. - u) * v * c01);
          double uv[2] = {0., 0.};
          // TODO: interpolate uv if param available
          MVertex *vNew =
            new MFaceVertex(p.x(), p.y(), p.z(), gf, uv[0], uv[1]);
          newVertices.push_back(vNew);
          grid[i][j] = vNew;
        }
      }
    }

    for(size_t i = 0; i < grid.size() - 1; i++) {
      for(size_t j = 0; j < grid[i].size() - 1; j++) {
        MQuadrangle *q = new MQuadrangle(grid[i][j], grid[i + 1][j],
                                         grid[i + 1][j + 1], grid[i][j + 1]);
        newQuads.push_back(q);
      }
    }
  }

  bool addQuadsAccordingToPattern(
    const QuadMeshPattern &P, const std::vector<int> &quantization, GFace *gf,
    const std::vector<std::vector<MVertex *> >
      &sides, /* vertices on the boundary, not changed */
    std::vector<MVertex *> &newVertices, /* new vertices inside the cavity */
    std::vector<MElement *> &newElements, /* new quads inside the cavity */
    MVertex *oldCenter = NULL /* initial guess for new positions */
  )
  {
    constexpr bool DBG_VIZU = false;
    if(P.sides.size() != sides.size()) {
      Msg::Error("wrong input sizes ... pattern: %li sides, input: %li sides",
                 P.sides.size(), sides.size());
      return false;
    }

    unordered_map<id2, std::vector<MVertex *>, id2hash> vpair2vertices;
    std::vector<MVertex *> v2mv(P.n, NULL);
    std::vector<MVertex *> vert;

    /* Associate exising vertices to pattern sides */
    SVector3 center(0., 0., 0.);
    if(oldCenter != nullptr) { center = oldCenter->point(); }
    else {
      double csum = 0.;
      for(size_t s = 0; s < sides.size(); ++s) {
        for(size_t k = 0; k < sides[s].size(); ++k) {
          center += sides[s][k]->point();
          csum += 1.;
        }
      }
      if(csum == 0.) return false;
      center = 1. / csum * center;
    }

    for(size_t s = 0; s < P.sides.size(); ++s) {
      size_t pos = 0;
      size_t sp = 0;
      for(size_t j = 0; j < P.sides[s].size(); ++j) {
        sp += quantization[P.eChordId[P.sides[s][j]]];
      }
      if(sp + 1 != sides[s].size()) { return false; }
      for(size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        int n_e = quantization[P.eChordId[e]];
        vert.resize(n_e + 1);
        for(size_t k = 0; k < (size_t)n_e + 1; ++k) {
          if(pos + k >= sides[s].size()) {
            Msg::Error("issue, pos=%li + k=%li = %li >= sides[s].size()=%li",
                       pos, k, pos + k, sides[s].size());
            return false;
          }
          vert[k] = sides[s][pos + k];
        }
        pos += n_e;
        id v1 = P.edges[e][0];
        id v2 = P.edges[e][1];
        if(v2mv[v1] == NULL) v2mv[v1] = vert.front();
        if(v2mv[v2] == NULL) v2mv[v2] = vert.back();

        id2 vpair = sorted(v1, v2);
        if(v1 < v2) { vpair2vertices[vpair] = vert; }
        else {
          std::reverse(vert.begin(), vert.end());
          vpair2vertices[vpair] = vert;
        }
      }
    }

    /* Create vertices on internal points */
    for(size_t v = 0; v < P.n; ++v)
      if(!P.vOnBdr[v]) {
        double uvc[2] = {0., 0.};
        if(oldCenter != nullptr && gf->haveParametrization() &&
           dynamic_cast<MFaceVertex *>(oldCenter)) {
          oldCenter->getParameter(0, uvc[0]);
          oldCenter->getParameter(1, uvc[1]);
        }
        GPoint pp =
          GPoint(center.x(), center.y(), center.z(), gf, uvc[0], uvc[1]);

        bool moveTowardBdr = true;
        if(moveTowardBdr) {
          double vsum = 10.; /* weight on center */
          SVector3 avg(vsum * pp.x(), vsum * pp.y(), vsum * pp.z());
          for(size_t e : P.v2e[v]) {
            size_t v2 = (P.edges[e][0] != v) ? P.edges[e][0] : P.edges[e][1];
            if(P.vOnBdr[v2]) {
              SVector3 p2 = v2mv[v2]->point();
              avg += p2;
              vsum += 1;
            }
          }
          if(vsum > 1) {
            pp.x() = avg.x() / vsum;
            pp.y() = avg.y() / vsum;
            pp.z() = avg.z() / vsum;
          }
        }

        double uv[2] = {0., 0.};
        MVertex *sing =
          new MFaceVertex(pp.x(), pp.y(), pp.z(), gf, pp.u(), pp.v());
        if(gf->haveParametrization()) {
          GPoint proj = gf->closestPoint(sing->point(), uv);
          if(proj.succeeded()) {
            sing->x() = proj.x();
            sing->y() = proj.y();
            sing->z() = proj.z();
            sing->setParameter(0, proj.u());
            sing->setParameter(1, proj.v());
          }
        }

        newVertices.push_back(sing);
        bool irregular = (P.v2e[v].size() != 4);
        v2mv[v] = sing;
      }

    /* Create vertices on internal curves */
    for(size_t e = 0; e < P.edges.size(); ++e)
      if(P.e2f[e].size() == 2) {
        id v1 = P.edges[e][0];
        id v2 = P.edges[e][1];
        MVertex *mv1 = v2mv[v1];
        MVertex *mv2 = v2mv[v2];
        if(mv1 == NULL || mv2 == NULL) {
          Msg::Error("MVertex* not found ?");
          return false;
        }
        int n_e = quantization[P.eChordId[e]];
        id2 vpair = sorted(v1, v2);
        if(v1 < v2) {
          vpair2vertices[vpair] =
            createVertices(gf, mv1, mv2, n_e, newVertices);
        }
        else {
          vpair2vertices[vpair] =
            createVertices(gf, mv2, mv1, n_e, newVertices);
        }
      }

    /* Create vertices inside the quad patches */
    for(size_t f = 0; f < P.quads.size(); ++f) {
      std::vector<std::vector<MVertex *> > quadCurves(4);
      for(size_t le = 0; le < 4; ++le) {
        id v0 = P.qvertices[f][le];
        id v1 = P.qvertices[f][(le + 1) % 4];
        id2 vpair = sorted(v0, v1);
        auto it = vpair2vertices.find(vpair);
        if(it == vpair2vertices.end()) {
          Msg::Error(
            "MVertex* vector not found for vertex pair (edge in pattern)");
          return false;
        }
        quadCurves[le] = it->second;
        if(v1 < v0) {
          std::reverse(quadCurves[le].begin(), quadCurves[le].end());
        }
      }
      createQuadPatch(gf, quadCurves[0], quadCurves[1], quadCurves[2],
                      quadCurves[3], newElements, newVertices);
    }

    return true;
  }

  void clearStuff(std::vector<MVertex *> &newVertices,
                  std::vector<MElement *> &newElements)
  {
    for(MVertex *&v : newVertices)
      if(v != NULL) {
        delete v;
        v = NULL;
      }
    newVertices.clear();
    for(MElement *&e : newElements)
      if(e != NULL) {
        delete e;
        e = NULL;
      }
    newElements.clear();
  }

  template <class T>
  void remove_element_if_inside(const T &value, std::vector<T> &vec)
  {
    auto it = std::find(vec.begin(), vec.end(), value);
    if(it != vec.end()) { vec.erase(it); }
  }

  struct QuadqsContext {
    bool optimizeTopology = true;
    bool optimizeGeometry = true;
    unordered_map<std::string, double> stats;
    double timeoutQuadqsPerGFace = DBL_MAX;
    double timeoutQuadqsPerGFaceCavity = DBL_MAX;
    double timeoutGeomOptimPerGFace = DBL_MAX;
  };

  struct QuadqsGFaceContext {
    /* Options (all timings in seconds) */
    double timeoutQuadqsPerGFace = DBL_MAX;
    double timeoutQuadqsPerGFaceCavity = DBL_MAX;
    double timeoutGeomOptimPerGFace = DBL_MAX;
    bool invertNormalsForQuality = false;
    size_t nTryMaxPerVertex = 2;
    size_t nTryCloseReset = 5;
    SurfaceProjector *sp = nullptr;
    /* Stats on execution */
    double t0 = 0.;
    size_t nSingCavityRemesh = 0;
    size_t nQuadCavityRemesh = 0;
    bool finished = false;

    /* Functions */
    QuadqsGFaceContext(const QuadqsContext &qqs)
    {
      timeoutQuadqsPerGFace = qqs.timeoutQuadqsPerGFace;
      timeoutQuadqsPerGFaceCavity = qqs.timeoutQuadqsPerGFaceCavity;
      timeoutGeomOptimPerGFace = qqs.timeoutGeomOptimPerGFace;
      t0 = Cpu();
    }

    double elapsedCpuTime() const { return Cpu() - t0; }
  };

  enum GrowthPolicy {
    GROW_MINIMAL,
    GROW_MAXIMAL,
  };

  const uint32_t NO_U32 = (uint32_t)-1;

  struct RemeshableCavity {
    std::vector<MElement *> elements;
    std::vector<std::vector<MVertex *> > sides;
    std::vector<MVertex *> intVertices;
    double irregularityMeasure = 0;
    uint32_t nIrregular = 0; // # irregular vertices outside allowed ones
    std::pair<size_t, int> patternNoAndRot = {(size_t)-1, 0};
  };

  struct GrowingCavity {
    std::vector<bool> quadIsInside; /* fixed size: farmer.quads.size() */
    std::vector<uint32_t> quadEdgeIsBdr; /* fixed size: 4*farmer.quads.size() */
    std::vector<uint32_t>
      vertexValenceInside; /* fixed size: farmer.vertices.size() */
    unordered_set<uint32_t> verticesInt; /* growing with cavity */
    unordered_set<uint32_t> verticesBdr; /* growing with cavity */
    unordered_set<uint32_t> elements; /* growing with cavity */
    /* nb of irregular vertices strictly inside cavity (include singularities)
     */
    uint32_t nIrregInterior = 0;

    void clear()
    {
      quadIsInside.clear();
      quadEdgeIsBdr.clear();
      vertexValenceInside.clear();
      verticesInt.clear();
      verticesBdr.clear();
      elements.clear();
      nIrregInterior = 0;
    }
  };

  struct CavityFarmer { /* the guy who grows cavities */
  public:
    GFace *gf = nullptr;

    /* contiguous representation of the GFace quad mesh  */
    std::vector<MVertex *> vertices;
    unordered_map<MVertex *, uint32_t> vertexLocal;
    std::vector<MQuadrangle *> quadrangles;
    unordered_map<MQuadrangle *, uint32_t> quadLocal;
    std::vector<std::array<uint32_t, 4> > quads;

    /* quad adjacency information */
    std::vector<uint32_t> adjacent; /* adjacent[4*q1+le1] = 4*q2+le2 */
    std::vector<uint32_t> v2q_first; /* vertex to quads */
    std::vector<uint32_t> v2q_values; /* vertex to quads */

    GrowingCavity cav; /* current cavity */
    GrowingCavity cavBackup; /* potential extension */

    /* growth constraints */
    std::vector<bool> vertexForbidden;
    std::vector<bool> quadEdgeForbidden;

    /* outside allocation for functions */
    vector<uint32_t> _vertex2pos;

  public:
    CavityFarmer(GFace *gf_) : gf(gf_){};

    void clear()
    {
      vertices.clear();
      vertexLocal.clear();
      quadrangles.clear();
      quadLocal.clear();
      quads.clear();
      adjacent.clear();
      v2q_first.clear();
      v2q_values.clear();
      vertexForbidden.clear();
      quadEdgeForbidden.clear();
      cav.clear();
      cavBackup.clear();
    }

    void debug_show_cavity(const std::string &name, bool light = true)
    {
      std::vector<MElement *> elts;
      for(uint32_t f : cav.elements) { elts.push_back(quadrangles[f]); }
      if(light) {
        GeoLog::add(elts, name);
        return;
      }
      GeoLog::add(elts, name + "_cav.elements");
      std::vector<array<double, 3> > interior;
      std::vector<array<double, 3> > bdr;
      for(uint32_t v : cav.verticesInt) {
        interior.push_back(vertices[v]->point());
      }
      for(uint32_t v : cav.verticesBdr) { bdr.push_back(vertices[v]->point()); }
      GeoLog::add(interior, 0., name + "_cav.verticesInt");
      GeoLog::add(bdr, 1., name + "_cav.verticesBdr");

      std::vector<MElement *> elts2;
      for(size_t f = 0; f < quadrangles.size(); ++f)
        if(cav.quadIsInside[f]) { elts2.push_back(quadrangles[f]); }
      GeoLog::add(elts2, name + "_cav.quadIsInside");
      for(size_t f = 0; f < quadrangles.size(); ++f) {
        for(size_t le = 0; le < 4; ++le) {
          if(cav.quadEdgeIsBdr[4 * f + le]) {
            uint32_t v1 = quads[f][le];
            uint32_t v2 = quads[f][(le + 1) % 4];
            std::vector<array<double, 3> > bdrEdges = {vertices[v1]->point(),
                                                       vertices[v2]->point()};
            GeoLog::add(bdrEdges, 0., name + "_cav.quadEdgeIsBdr");
          }
        }
      }
      GeoLog::flush();
    }

    bool updateFarmer(GFace *gf)
    {
      /* assume coherent orientation of quads in GFace */
      clear();
      std::vector<uint32_t> valence;
      vertices.reserve(2 * gf->mesh_vertices.size());
      valence.reserve(2 * gf->mesh_vertices.size());
      quads.reserve(gf->quadrangles.size());
      quadrangles = gf->quadrangles;
      for(size_t f = 0; f < quadrangles.size(); ++f) {
        MQuadrangle *q = quadrangles[f];
        quadLocal[q] = f;
        array<uint32_t, 4> quad;
        for(size_t lv = 0; lv < 4; ++lv) {
          MVertex *v = q->getVertex(lv);
          auto it = vertexLocal.find(v);
          if(it != vertexLocal.end()) {
            uint32_t nv = it->second;
            quad[lv] = nv;
            valence[nv] += 1;
          }
          else {
            uint32_t nv = vertices.size();
            vertices.push_back(v);
            valence.push_back(1);
            vertexLocal[v] = nv;
            quad[lv] = nv;
          }
        }
        quads.push_back(quad);
      }

      /* Build the vertex to quads adjacencies */
      v2q_first.resize(vertices.size() + 1, 0);
      for(uint32_t v = 0; v < vertices.size(); ++v) {
        v2q_first[v + 1] = v2q_first[v] + valence[v];
      }
      v2q_values.resize(v2q_first.back(), NO_U32);
      for(uint32_t f = 0; f < quads.size(); ++f) {
        for(uint32_t lv = 0; lv < 4; ++lv) {
          const uint32_t v = quads[f][lv];
          const uint32_t begin = v2q_first[v];
          const uint32_t end = v2q_first[v + 1];
          bool foundSlot = false;
          for(uint32_t pos = begin; pos < end; ++pos) {
            if(v2q_values[pos] == NO_U32) {
              v2q_values[pos] = f;
              foundSlot = true;
              break;
            }
          }
          if(!foundSlot) {
            Msg::Error("cavity farmer: no slot found !");
            return false;
          }
        }
      }

      /* Build the quad to quads adjacencies */
      adjacent.resize(4 * quads.size(), NO_U32);
      for(uint32_t f = 0; f < quads.size(); ++f) {
        for(uint32_t le = 0; le < 4; ++le) {
          if(adjacent[4 * f + le] != NO_U32) continue;
          const uint32_t v1 = quads[f][le];
          const uint32_t v2 = quads[f][(le + 1) % 4];
          const uint32_t begin = v2q_first[v1];
          const uint32_t end = v2q_first[v1 + 1];
          for(uint32_t pos = begin; pos < end; ++pos) {
            const uint32_t f2 = v2q_values[pos];
            for(uint32_t le2 = 0; le2 < 4; ++le2) {
              const uint32_t av1 = quads[f2][le2];
              const uint32_t av2 = quads[f2][(le2 + 1) % 4];
              if(av1 == v2 && av2 == v1) {
                adjacent[4 * f + le] = 4 * f2 + le2;
                adjacent[4 * f2 + le2] = 4 * f + le;
                break;
              }
            }
            if(adjacent[4 * f + le] != NO_U32) break;
          }
        }
      }

      /* Embedded edges in faces */
      std::vector<GEdge *> embEdges;
      for(GEdge *ge : gf->embeddedEdges()) embEdges.push_back(ge);
      for(GEdge *ge : gf->edges())
        if(ge->isSeam(gf)) embEdges.push_back(ge);

      unordered_set<id2, id2hash> embLines;
      for(GEdge *ge : embEdges) {
        for(MLine *line : ge->lines) {
          MVertex *v1 = line->getVertex(0);
          MVertex *v2 = line->getVertex(1);
          auto it1 = vertexLocal.find(v1);
          auto it2 = vertexLocal.find(v2);
          if(it1 == vertexLocal.end() || it2 == vertexLocal.end()) {
            Msg::Debug(
              "cavity farmer update: vertex of embedded line not found, weird");
            continue;
          }
          id2 vpair = sorted(it1->second, it2->second);
          embLines.insert(vpair);
        }
      }
      if(quadEdgeForbidden.size() == 0) {
        quadEdgeForbidden.resize(4 * quads.size(), false);
      }
      if(embLines.size() != 0) {
        for(uint32_t f = 0; f < quads.size(); ++f) {
          for(uint32_t le = 0; le < 4; ++le) {
            const uint32_t v1 = quads[f][le];
            const uint32_t v2 = quads[f][(le + 1) % 4];
            id2 vpair = sorted(v1, v2);
            auto it = embLines.find(vpair);
            if(it != embLines.end()) { quadEdgeForbidden[4 * f + le] = true; }
          }
        }
      }

      return true;
    }

    bool vertexValence(uint32_t v, uint32_t &valIn, uint32_t &valOut,
                       uint32_t *qOut = nullptr)
    {
      valIn = 0;
      valOut = 0;
      if(v >= v2q_first.size()) {
        Msg::Error("vertexValence: incoherent state");
        return false;
      }
      const uint32_t begin = v2q_first[v];
      const uint32_t end = v2q_first[v + 1];
      for(uint32_t pos = begin; pos < end; ++pos) {
        const uint32_t f = v2q_values[pos];
        if(f == NO_U32) continue;
        if(cav.quadIsInside[f]) { valIn += 1; }
        else {
          valOut += 1;
          if(qOut != nullptr) { *qOut = f; }
        }
      }
      return true;
    }

    /* slow, do not call often */
    bool vertexAdjacentQuads(MVertex *vp, std::vector<MQuadrangle *> &adjQuads)
    {
      auto it = vertexLocal.find(vp);
      if(it == vertexLocal.end()) { return false; }
      const uint32_t v = it->second;
      const uint32_t begin = v2q_first[v];
      const uint32_t end = v2q_first[v + 1];
      const uint32_t n = end - begin;
      adjQuads.resize(n);
      for(uint32_t i = 0; i < n; ++i) {
        const uint32_t f = v2q_values[begin + i];
        adjQuads[i] = quadrangles[f];
      }
      return adjQuads.size() > 0;
    }

    /* warning: when false is returned, the current cavity
     *          is no longer valid and it should be discarded
     *          or repaired by a external backup */
    bool addQuads(const std::vector<uint32_t> &toAdd,
                  bool checkForbidden = true)
    {
      vector<uint32_t> touched;
      touched.reserve(4 * toAdd.size());
      for(uint32_t f : toAdd) {
        if(cav.quadIsInside[f] == false) {
          cav.quadIsInside[f] = true;
          cav.elements.insert(f);
        }
        else {
          Msg::Error(
            "cavity farmer: quad already in cavity, should not happen");
          return false;
        }
        for(size_t le = 0; le < 4; ++le) {
          cav.vertexValenceInside[quads[f][le]] += 1;
          touched.push_back(quads[f][le]);
          uint32_t opp = adjacent[4 * f + le];
          if(cav.quadEdgeIsBdr[4 * f + le]) {
            Msg::Error(
              "cavity farmer: quad edge already cavity bdr, should not happen");
            return false;
          }
          else if(opp != NO_U32 && cav.quadEdgeIsBdr[opp]) {
            /* adjacent quad was in cavity and boundary */

            if(checkForbidden && quadEdgeForbidden.size() > 0) {
              /* check if adding the quad would include a forbidden quad edge */
              if(quadEdgeForbidden[4 * f + le]) return false;
            }

            /* adjacent quad was in cavity and boundary => no longer boundary */
            cav.quadEdgeIsBdr[opp] = false;
          }
          else {
            /* adjacent quad edge was not cavity bdr, this one becomes one */
            cav.quadEdgeIsBdr[4 * f + le] = true;
          }
        }
      }
      sort_unique(touched);

      for(uint32_t v : touched) {
        uint32_t n = v2q_first[v + 1] - v2q_first[v];
        uint32_t valIn = cav.vertexValenceInside[v];
        uint32_t valOut = n - valIn;
        if(valOut > 0) { cav.verticesBdr.insert(v); }
        else if(valOut == 0 && valIn > 0) {
          MVertex *pv = vertices[v];
          GFace *pgf = pv->onWhat()->cast2Face();
          if(pgf != nullptr) { /* vertex inside GFace */
            auto it = cav.verticesInt.find(v);
            if(it == cav.verticesInt.end()) { /* New interior */
              if(checkForbidden && vertexForbidden[v]) { return false; }
              cav.verticesInt.insert(v);

              if(valIn != 4) { cav.nIrregInterior += 1; }

              /* remove from boundary*/
              auto itb = cav.verticesBdr.find(v);
              if(itb != cav.verticesBdr.end()) { cav.verticesBdr.erase(itb); }
            }
          }
          else { /* vertex on GFace boundary */
            cav.verticesBdr.insert(v);
          }
        }
        else {
          Msg::Error("cavity farmer: incoherent vertex state in addQuads");
          return false;
        }
      }

      return true;
    }

    double cavityIrregularity(uint32_t &nIrregular, uint32_t &nConvexCorners)
    {
      nIrregular = 0;
      nConvexCorners = 0;
      double ir = 0.;
      for(uint32_t v : cav.verticesInt) {
        uint32_t n = v2q_first[v + 1] - v2q_first[v];
        uint32_t valIn = cav.vertexValenceInside[v];
        uint32_t valOut = n - valIn;
        if(valOut > 0) {
          Msg::Error("weird: cavity interior vertex has valence-out=%i",
                     valOut);
        }
        if(valIn != 4) {
          ir += std::pow(valIn - 4., 2);
          nIrregular += 1;
        }
      }
      for(uint32_t v : cav.verticesBdr) {
        uint32_t n = v2q_first[v + 1] - v2q_first[v];
        uint32_t valIn = cav.vertexValenceInside[v];
        if(valIn == 1) { nConvexCorners += 1; }
        else if(valIn > 2) {
          /* inside-valence 3+ on cavity boundary will be eliminated
           * inside-valence 1 is a cavity corner, does not count as irregular
           * here*/
          nIrregular += 1;
          ir += std::pow(valIn - 2., 2);
        }
      }
      return ir;
    }

    bool isValidConvexCavity()
    {
      for(uint32_t v : cav.verticesBdr) {
        uint32_t n = v2q_first[v + 1] - v2q_first[v];
        uint32_t valIn = cav.vertexValenceInside[v];
        uint32_t valOut = n - valIn;
        if(valOut == 1) {
          MVertex *vp = vertices[v];
          GFace *gf = vp->onWhat()->cast2Face();
          if(gf != nullptr) {
            /* Concave cavity corner, inside the surface mesh */
            return false;
          }
        }
        else if(valOut >= 3) {
          MVertex *vp = vertices[v];
          GVertex *gv = vp->onWhat()->cast2Vertex();
          if(gv != nullptr) {
            /* CAD corner, valence is superior or equal to three, should not be
             * absorbed in cavity */
            return false;
          }
        }
        else if(valIn == 3 && valOut == 2 && vertexForbidden[v]) {
          /* Would change a valence 5 singularity into a regular vertex */
          return false;
        }
      }

      return true;
    }

    bool convexify(bool checkForbidden = true)
    {
      bool running = true;
      while(running) {
        running = false;
        std::vector<uint32_t> quadsAtConcavities;
        for(uint32_t v : cav.verticesBdr) {
          uint32_t n = v2q_first[v + 1] - v2q_first[v];
          uint32_t valIn = cav.vertexValenceInside[v];
          uint32_t valOut = n - valIn;

          /* Add exterior quad if cavity bdr vertex out-valence is one
           * and cavity bdr vertex is inside the GFace */
          if(valOut == 1) {
            uint32_t qOut = NO_U32;
            vertexValence(v, valIn, valOut, &qOut);
            assert(qOut != NO_U32);
            GFace *pgf = vertices[v]->onWhat()->cast2Face();
            if(pgf == nullptr) continue;
            quadsAtConcavities.push_back(qOut);
          }
        }
        if(quadsAtConcavities.size() > 0) {
          sort_unique(quadsAtConcavities);
          bool oka = addQuads(quadsAtConcavities, checkForbidden);
          if(!oka) return false;
          running = true;
        }
      }
      return isValidConvexCavity();
    }

    bool getCavitySides(uint32_t &Ncorners,
                        std::vector<std::vector<uint32_t> > &sides)
    {
      /* Prepare the cavity boundary edges to make
       * a continuous loop on them */
      vector<uint32_t> pos2vertex;
      if(_vertex2pos.size() != vertices.size()) {
        _vertex2pos.resize(vertices.size());
      }
      std::fill(_vertex2pos.begin(), _vertex2pos.end(),
                NO_U32); /* _vertex2pos allocated outside */
      vector<uint32_t> pos2nextVertex;
      vector<bool> isCorner;
      pos2vertex.reserve(cav.verticesBdr.size());
      pos2vertex.reserve(cav.verticesBdr.size());
      isCorner.reserve(cav.verticesBdr.size());
      uint32_t v0 = NO_U32;

      for(uint32_t v : cav.verticesBdr) {
        uint32_t n = v2q_first[v + 1] - v2q_first[v];
        int edgeFound = 0;
        for(uint32_t lq = 0; lq < n; ++lq) {
          uint32_t q = v2q_values[v2q_first[v] + lq];
          if(!cav.quadIsInside[q]) continue;
          for(uint32_t le = 0; le < 4; ++le) {
            if(quads[q][le] == v && cav.quadEdgeIsBdr[4 * q + le]) {
              edgeFound += 1;
              if(edgeFound == 1) { /* edgeFound >= 2 means non manifold */
                uint32_t v2 = quads[q][(le + 1) % 4];
                if(_vertex2pos[v] != NO_U32) {
                  Msg::Debug("cavity farmer: get sides, vertex already "
                             "assigned, not manifold bdr loop");
                  return false;
                }
                _vertex2pos[v] = pos2vertex.size();
                pos2vertex.push_back(v);
                pos2nextVertex.push_back(v2);
                uint32_t n = v2q_first[v + 1] - v2q_first[v];
                uint32_t valIn = cav.vertexValenceInside[v];
                if(valIn == 1) {
                  isCorner.push_back(true);
                  Ncorners += 1;
                  if(v0 == NO_U32) { v0 = v; }
                  else {
                    /* deterministic choice of the start */
                    size_t num0 = vertices[v0]->getNum();
                    size_t num = vertices[v]->getNum();
                    if(num < num0) { v0 = v; }
                  }
                }
                else {
                  isCorner.push_back(false);
                }
              }
            }
          }
        }
        if(edgeFound == 0) {
          Msg::Warning("cavity sides: cavity bdr edge not found around vertex "
                       "%i, shoud NOT happen",
                       v);
          // debug_show_cavity("cav_bdr_edge_not_found_around_v",false);
          // gmsh::initialize();
          // GeoLog::flush();
          // gmsh::fltk::run();
          // abort();
          return false;
        }
        else if(edgeFound >= 2) {
          Msg::Debug(
            "cavity sides: found %i cavity bdr edge, bdr loop is not manifold",
            edgeFound);
          return false;
        }
      }
      if(pos2vertex.size() == 0) { return false; }

      if(v0 == NO_U32) {
        /* No corner, the cavity is a disk */
        v0 = pos2vertex[0];
        sides.resize(1);
        sides[0].push_back(v0);
      }

      /* Propagation along the boundary */
      uint32_t nCornerVisited = 0;
      uint32_t nVertexVisited = 0;
      uint32_t v = v0;
      uint32_t iter = 0;
      while(true) {
        iter += 1;
        if(iter > 2 * cav.verticesBdr.size()) {
          Msg::Warning("cavity farmer, get sides: infinite loop ? iter = %i "
                       "but #bdr=%li, may happen if loop not manifold",
                       iter, cav.verticesBdr.size());
          return false;
          // debug_show_cavity("infinite_loop",false);
          // gmsh::initialize();
          // GeoLog::flush();
          // gmsh::fltk::run();
          // abort();
        }

        uint32_t pos = _vertex2pos[v];
        if(pos >= isCorner.size()) {
          Msg::Warning("cavity farmer, get sides: iter %i, pos = %li > "
                       "_vertex2pos.size()=%li, weird",
                       iter, pos, _vertex2pos.size());
          // debug_show_cavity("bad_vertex2pos",false);
          // gmsh::initialize();
          // GeoLog::flush();
          // gmsh::fltk::run();
          // abort();
          return false;
        }
        if(isCorner[pos]) {
          nCornerVisited += 1;
          sides.resize(sides.size() + 1);
          sides.back().push_back(v);
        }

        uint32_t v2 = pos2nextVertex[pos];
        sides.back().push_back(v2);
        v = v2;
        nVertexVisited += 1;

        if(v2 == v0) { /* closed the loop */
          break;
        }
      }

      if(nCornerVisited != Ncorners ||
         nVertexVisited != cav.verticesBdr.size()) {
        Msg::Debug("getCavitySides: not all cavity bdr corners/vertices were "
                   "visited, bdr has multiple loops (i.e. not a topo. disk)");

        // debug_show_cavity("bad_cav_" + std::to_string(nVertexVisited) + "!="
        // + std::to_string(cav.verticesBdr.size())); GeoLog::flush();

        return false;
      }

      return true;
    }

    bool growCavityStep()
    {
      std::vector<std::vector<uint32_t> > sides;
      uint32_t Ncorners = 0;
      bool oks = getCavitySides(Ncorners, sides);
      if(!oks) {
        if(DBG_VERBOSE) {
          Msg::Debug(
            "cavity farmer: grow one side, failed to build cavity boundary");
        }
        return false;
      }

      // For isotropic growth, we choose try the largest sides first,
      // and we add the getNum of the first vertex for reproductibility. */
      vector<std::pair<size_t, size_t> > sizeAndSide(sides.size());
      for(size_t i = 0; i < sides.size(); ++i) {
        size_t num = vertices[sides[i].front()]->getNum();
        sizeAndSide[i] = {size_t(1e7 * sides[i].size() + num), i};
      }
      std::sort(sizeAndSide.begin(), sizeAndSide.end());
      std::reverse(sizeAndSide.begin(), sizeAndSide.end());

      cavBackup = cav; /* to be able to restore if candidate is not good */

      for(size_t k = 0; k < sizeAndSide.size(); ++k) {
        size_t i = sizeAndSide[k].second;
        if(sides[i].size() < 2) continue;
        bool candidate = true;
        /* Look at side interior vertices */
        for(size_t j = 1; j < sides[i].size() - 1; ++j) {
          uint32_t v = sides[i][j];
          /* Check if side is touching a growth limit */
          if(vertexForbidden[v]) {
            candidate = false;
            break;
          }
          /* Check if touching a CAD corner */
          MVertex *pv = vertices[v];
          GVertex *gv = dynamic_cast<GVertex *>(pv->onWhat());
          if(gv != nullptr) { /* side touching CAD corner */
            candidate = false;
            break;
          }
        }

        if(candidate) {
          /* Build the new convex cavity by expanding on the side
           * and check if it is a valid */

          /* Add the new quads */
          size_t nAdded = 0;
          std::vector<uint32_t> cQuads;
          cQuads.reserve(4 * sides[i].size());
          if(sides[i].size() == 2) { /* Side is one edge */
            uint32_t v1 = sides[i][0];
            uint32_t v2 = sides[i][1];
            const uint32_t begin = v2q_first[v1];
            const uint32_t end = v2q_first[v1 + 1];
            for(uint32_t pos = begin; pos < end; ++pos) {
              const uint32_t f = v2q_values[pos];
              if(!cav.quadIsInside[f]) {
                for(size_t le = 0; le < 4; ++le) {
                  uint32_t qv1 = quads[f][le];
                  uint32_t qv2 = quads[f][(le + 1) % 4];
                  if((qv1 == v1 && qv2 == v2) || (qv1 == v2 && qv2 == v1)) {
                    cQuads.push_back(f);
                    break;
                  }
                }
              }
              if(cQuads.size() > 0) break;
            }
          }
          else { /* Take quads adjacent to interior side vertices */
            for(size_t j = 1; j < sides[i].size() - 1; ++j) {
              uint32_t v = sides[i][j];

              const uint32_t begin = v2q_first[v];
              const uint32_t end = v2q_first[v + 1];
              for(uint32_t pos = begin; pos < end; ++pos) {
                const uint32_t f = v2q_values[pos];
                if(!cav.quadIsInside[f]) { cQuads.push_back(f); }
              }
            }
          }
          if(cQuads.size() == 0) continue;
          sort_unique(cQuads);
          bool oka = addQuads(cQuads);
          if(!oka) { /* try next side */
            if(DBG_VERBOSE) {
              Msg::Debug("cavity grow one side: %li quads, side %i, FAILED to "
                         "add %li quads",
                         cav.elements.size(), k, cQuads.size());
            }
            cav = cavBackup;
            continue;
          }

          /* Convexify the cavity */
          bool okc = convexify();
          if(!okc) { /* try next side */
            if(DBG_VERBOSE) {
              Msg::Debug("cavity grow one side: %li quads, side %i, FAILED to "
                         "convexify after adding %li quads",
                         cav.elements.size(), k, cQuads.size());
            }
            cav = cavBackup;
            continue;
          }

          /* Extended cavity is good, keep it */
          cavBackup.clear();

          if(DBG_VERBOSE) {
            Msg::Debug("cavity grow one side: %li quads, side %i, OK convexify "
                       "(after adding %li quads)",
                       cav.elements.size(), k, cQuads.size());
          }

          return true;
        }
      }
      if(DBG_VERBOSE) {
        Msg::Debug("cavity grow one side: %li quads, tried all sides, no "
                   "extension possible",
                   cav.elements.size());
      }
      cav = cavBackup;
      return false;
    }

    bool growCavity(const std::vector<MQuadrangle *> &quadsInit,
                    GrowthPolicy policy,
                    const std::vector<size_t> &patternsToCheck,
                    const unordered_map<size_t, size_t> &patternSizeLimits,
                    const unordered_set<MVertex *> &allowedIrregularVertices,
                    const unordered_set<MVertex *> &forbiddenIrregularVertices,
                    RemeshableCavity &rcav)
    {
      /* clear current cavity */
      cav.clear();
      cavBackup.clear();
      cav.quadIsInside.resize(quads.size(), false);
      cav.quadEdgeIsBdr.resize(4 * quads.size(), false);
      cav.vertexValenceInside.resize(vertices.size(), 0);

      /* constrain the growth */
      vertexForbidden.clear();
      vertexForbidden.resize(vertices.size(), false);
      for(MVertex *v : forbiddenIrregularVertices) {
        if(allowedIrregularVertices.find(v) != allowedIrregularVertices.end()) {
          continue;
        }
        auto it = vertexLocal.find(v);
        if(it != vertexLocal.end()) vertexForbidden[it->second] = true;
      }

      /* initialize the cavity with given quads */
      vector<uint32_t> lquads;
      for(MQuadrangle *q : quadsInit) {
        auto it = quadLocal.find(q);
        if(it == quadLocal.end()) {
          Msg::Error("cavity farmer: quad not found in farmer mesh");
          return false;
        }
        lquads.push_back(it->second);
      }
      sort_unique(lquads);

      bool oka = addQuads(lquads);
      if(!oka) {
        // Initialization may be rejected if it includes forbidden vertices or
        // quad edges (e.g. around the vertex of an embedded line)
        Msg::Debug("cavity remeshing: failed to initialize (%li quads)",
                   lquads.size());
        return false;
      }

      uint32_t lastNbIrregular = 0;
      bool running = true;
      uint32_t iter = 0;
      while(running) {
        iter += 1;
        /* Grow the cavity on one of its sides */
        bool okg = growCavityStep();
        // if (false) {
        //   std::string name = "cav" + std::to_string(ccc) + "_it" +
        //   std::to_string(iter) + "_" + std::to_string(okg);
        //   debug_show_cavity(name, true);
        //   GeoLog::flush();
        // }
        if(!okg) {
          if(DBG_VERBOSE) {
            Msg::Debug("------ grow cavity: iter %li, %li vertices, failed to "
                       "grow cavity",
                       iter, cav.verticesInt.size() + cav.verticesBdr.size());
          }
          break;
        }

        /* nb of irregular vertices in cavity, counting interior and boundary,
         * and singularities */
        uint32_t curCavityNirreg = 0;
        uint32_t curNcorners = 0;
        double curCavityIrregularity =
          cavityIrregularity(curCavityNirreg, curNcorners);
        /* If no new irregular vertices, continue the growth */
        if(curCavityNirreg <= lastNbIrregular) continue;

        /* Check if the cavity is topologicaly remeshable with patterns */
        std::vector<std::vector<uint32_t> >
          sides; /* same for the different pattern checks */
        uint32_t Ncorners = 0;
        double bestIrreg = DBL_MAX;
        for(size_t pId : patternsToCheck) {
          /* Check pattern size limit if any */
          auto it = patternSizeLimits.find(pId);
          if(it != patternSizeLimits.end() && cav.elements.size() > it->second)
            continue;

          if(patternNumberOfCorners(pId) != curNcorners) {
            if(DBG_VERBOSE) {
              Msg::Debug("------ grow cavity: iter %li, %li quads, not right "
                         "number of corners (%i)",
                         iter, cav.elements.size(), curNcorners);
            }
            continue;
          }

          if(pId == PATTERN_QUAD_DIAG35 || pId == PATTERN_QUAD_ALIGNED35 ||
             pId == PATTERN_QUAD_CHORD_UTURN) {
            /* these patterns have two irregular vertices inside, no need to
             * check
             * if there are only two irregular vertices in current cavity */
            if(curCavityNirreg <= 2) continue;
          }

          /* Get the sides to check if remeshable */
          if(sides.size() ==
             0) { /* first time, same for the next pattern checks */
            bool oks = getCavitySides(Ncorners, sides);
            if(!oks) {
              if(DBG_VERBOSE) {
                Msg::Debug("------ grow cavity: iter %li, %li quads, failed to "
                           "build cavity boundary",
                           iter, cav.elements.size());
              }
              break;
            }
          }

          /* Number of vertices on each side, including extremities */
          std::vector<size_t> sideSizes(sides.size());
          for(size_t i = 0; i < sideSizes.size(); ++i)
            sideSizes[i] = sides[i].size();

          if(pId == PATTERN_QUAD_REGULAR) {
            /* two opposite sides must have same number of vertices, no need to
             * check else */
            if(sideSizes.size() != 4) continue;
            if(sideSizes[0] != sideSizes[2] || sideSizes[1] != sideSizes[3])
              continue;
          }

          /* Check if remeshable with pattern pId */
          double irregAfterRemeshing =
            0.; /* to ensure irregularity decrease with remeshing */
          std::pair<size_t, int> par;
          bool meshable = patchIsRemeshableWithQuadPattern(
            {pId}, Ncorners, sideSizes, par, irregAfterRemeshing);

          if(DBG_VERBOSE) {
            Msg::Debug(
              "------ grow cavity: iter %li, %li quads, #sides=%li, "
              "#irregular=%i, cavityIrregularity=%f | CHECK pId %li: "
              "remeshability: %i, irregAfterRemeshing=%e (best was %e)",
              iter, cav.elements.size(), sides.size(), curCavityNirreg,
              curCavityIrregularity, pId, meshable, irregAfterRemeshing,
              bestIrreg);
          }

          if(!meshable) continue;
          if(irregAfterRemeshing >= bestIrreg) {
            if(DBG_VERBOSE) {
              Msg::Debug("------- discard because irregAfterRemeshing=%f >= "
                         "bestIrreg=%f",
                         irregAfterRemeshing, bestIrreg);
            }
            continue;
          }
          if(irregAfterRemeshing >= curCavityIrregularity) {
            if(DBG_VERBOSE) {
              Msg::Debug("------- discard because irregAfterRemeshing=%f >= "
                         "curCavityIrregularity=%f",
                         irregAfterRemeshing, curCavityIrregularity);
            }
            continue;
          }

          { /* set last remeshable cavity */
            if(DBG_VERBOSE) {
              Msg::Debug("------ grow cavity: iter %li, %li quads, set new "
                         "remeshable cavity (irregAfterRemeshing=%f)",
                         iter, cav.elements.size(), irregAfterRemeshing);
            }
            bestIrreg = irregAfterRemeshing;
            lastNbIrregular = curCavityNirreg;

            /* set last remeshable cavity */
            rcav.irregularityMeasure = irregAfterRemeshing;
            rcav.nIrregular = curCavityNirreg;
            rcav.patternNoAndRot = par;
            /* - convert local indices to gmsh elements */
            rcav.elements.clear();
            rcav.elements.reserve(cav.elements.size());
            for(uint32_t f : cav.elements) {
              rcav.elements.push_back(quadrangles[f]);
            }
            rcav.intVertices.clear();
            rcav.intVertices.reserve(cav.verticesInt.size());
            for(uint32_t v : cav.verticesInt) {
              rcav.intVertices.push_back(vertices[v]);
            }
            rcav.sides.resize(sides.size());
            for(size_t i = 0; i < sides.size(); ++i) {
              rcav.sides[i].resize(sides[i].size());
              for(size_t j = 0; j < sides[i].size(); ++j) {
                rcav.sides[i][j] = vertices[sides[i][j]];
              }
            }

            if(DBG_VERBOSE) {
              Msg::Debug("------ grow cavity: iter %li, %li quads, SET LAST "
                         "remeshable cavity (#irreg = %li)",
                         iter, rcav.elements.size(), curCavityNirreg);
            }
          }
        }
        if(policy == GROW_MINIMAL && bestIrreg != DBL_MAX &&
           lastNbIrregular > 0) {
          /* Found a remeshable cavity, return */
          if(DBG_VERBOSE) {
            Msg::Debug("------ grow cavity: iter %li, %li quads, policy is "
                       "MINIMAL growth, RETURN cavity",
                       iter, rcav.elements.size());
          }
          return true;
        }
      }

      if(lastNbIrregular > 0) {
        if(DBG_VERBOSE) {
          Msg::Debug("------ grow cavity: iter %li, %li quads, MAXIMAL growth, "
                     "RETURN cavity",
                     iter, rcav.elements.size());
        }
      }

      return lastNbIrregular > 0;
    }

    bool getCavityNeighbors(RemeshableCavity &rcav,
                            std::vector<MElement *> &neighbors)
    {
      neighbors.clear();
      std::vector<uint32_t> bdr;
      for(auto &side : rcav.sides)
        for(MVertex *v : side) {
          auto it = vertexLocal.find(v);
          if(it != vertexLocal.end()) { bdr.push_back(it->second); }
        }
      sort_unique(bdr);
      for(uint32_t v : bdr) {
        const uint32_t begin = v2q_first[v];
        const uint32_t end = v2q_first[v + 1];
        for(uint32_t pos = begin; pos < end; ++pos) {
          const uint32_t f = v2q_values[pos];
          MElement *elt = quadrangles[f];
          neighbors.push_back(elt);
        }
      }
      neighbors = difference(neighbors, rcav.elements);
      return true;
    }
  };

  bool
  quadMeshIsMinimal(const CavityFarmer &farmer,
                    const std::vector<std::pair<SPoint3, int> > &singularities)
  {
    if(farmer.vertices.size() == 0) {
      Msg::Error("quadMeshIsMinimal: farmer not initialized");
      return false;
    }
    size_t nIrregInt = 0;
    size_t nIrregBdr = 0;
    for(uint32_t i = 0; i < farmer.vertices.size(); ++i) {
      uint32_t val = farmer.v2q_first[i + 1] - farmer.v2q_first[i];
      MVertex *v = farmer.vertices[i];
      if(v->onWhat()->cast2Face() != nullptr && val != 4) { nIrregInt += 1; }
      else if(v->onWhat()->cast2Edge() != nullptr && val != 2) {
        nIrregBdr += 1;
      }
    }
    if(nIrregBdr == 0 && nIrregInt == singularities.size()) return true;
    return false;
  }

  struct PatchQualityStats {
    double sicnMin = DBL_MAX;
    double sicnAvg = 0.;
    double sigeMin = DBL_MAX;
    double sigeAvg = 0.;
    double skewMax = -DBL_MAX;
    double skewAvg = 0.;
  };

  /* Quad skew metric according to Verdict quality library definition:
   * - skew = |cos(A)| with A angle between the two principal axis
   * - range: from 0 (good) to 1 (bad) */
  double quadSkew(MElement *elt)
  {
    MQuadrangle *q = dynamic_cast<MQuadrangle *>(elt);
    if(q == nullptr) return 0.;
    const vec3 p0 = q->getVertex(0)->point();
    const vec3 p1 = q->getVertex(1)->point();
    const vec3 p2 = q->getVertex(2)->point();
    const vec3 p3 = q->getVertex(3)->point();
    vec3 x1 = p1 - p0 + p2 - p3;
    vec3 x2 = p2 - p1 + p3 - p0;
    double n1 = length2(x1);
    double n2 = length2(x2);
    if(n1 == 0 || n2 == 0) return 0.;
    normalize(x1);
    normalize(x2);
    return std::abs(dot(x1, x2));
  }

  PatchQualityStats
  computePatchQualityStats(const std::vector<MElement *> &elements)
  {
    PatchQualityStats s;
    s.sicnMin = DBL_MAX;
    s.sicnAvg = 0.;
    s.sigeMin = DBL_MAX;
    s.sigeAvg = 0.;
    s.skewMax = -DBL_MAX;
    s.skewAvg = 0.;
    if(elements.size() == 0) return s;
    for(MElement *e : elements) {
      const double sicn = e->minSICNShapeMeasure();
      const double sige = e->minSIGEShapeMeasure();
      const double skew = quadSkew(e);
      if(sicn < s.sicnMin) s.sicnMin = sicn;
      if(sige < s.sigeMin) s.sigeMin = sige;
      if(skew > s.skewMax) s.skewMax = skew;
      s.sicnAvg += sicn;
      s.sigeAvg += sige;
      s.skewAvg += skew;
    }
    s.sicnAvg /= double(elements.size());
    s.sigeAvg /= double(elements.size());
    s.skewAvg /= double(elements.size());
    return s;
  }

  bool
  patchPassesQualityConstraints(const std::vector<MElement *> &elements,
                                const QualityConstraints &qualityConstraints)
  {
    PatchQualityStats s = computePatchQualityStats(elements);
    if(s.sicnMin <= qualityConstraints.SICNmin) return false;
    if(s.sigeMin <= qualityConstraints.SIGEmin) return false;
    if(s.skewMax >= qualityConstraints.skewMax) return false;
    return true;
  }

  // bool keepCavityRemeshing(
  //     double sicnMinBefore,
  //     double sicnAvgBefore,
  //     double sicnMinAfter,
  //     double sicnAvgAfter) {
  //   double boldness = CTX::instance()->mesh.quadqsRemeshingBoldness;
  //   if (boldness < 0.) boldness = 0.;
  //   if (boldness > 1.) boldness = 1.;
  //   if (boldness == 1. && sicnMinAfter > 0.) {
  //     return true;
  //   } else if (boldness == 0. && sicnMinAfter < sicnMinBefore) {
  //     return false;
  //   }
  //   if (boldness == 0.501) { /* backward compatibility */
  //     return ((sicnMinAfter > 0.3 && sicnAvgAfter > 0.5) || sicnMinAfter >
  //     sicnMinBefore);
  //   }
  //   double acceptMin = (1.-boldness) * sicnMinBefore;
  //   double acceptAvg = (1.-boldness) * sicnAvgBefore * 0.5;
  //   if (sicnMinAfter > acceptMin && sicnAvgAfter > acceptAvg) return true;

  //   return false;
  // }

  bool keepCavityRemeshing(const PatchQualityStats &before,
                           const PatchQualityStats &after)
  {
    double boldness = CTX::instance()->mesh.quadqsRemeshingBoldness;
    if(boldness < 0.) boldness = 0.;
    if(boldness > 1.) boldness = 1.;
    if(boldness == 1. && before.sigeMin > 0.) { return true; }
    else if(boldness == 0. && after.sigeMin < before.sigeMin) {
      return false;
    }
    if(boldness == 0.501) { /* backward compatibility */
      return ((after.sicnMin > 0.3 && after.sicnAvg > 0.5) ||
              after.sicnMin > before.sicnMin);
    }
    bool newVersion = true;
    if(newVersion) {
      double acceptMin = (1. - boldness) * before.sigeMin;
      double acceptAvg = (1. - boldness) * before.sigeAvg * 0.5;
      double acceptSkewAvg = before.skewAvg + (1. - before.skewAvg) * boldness;
      double acceptSkewMax = before.skewMax + (1. - before.skewMax) * boldness;
      if(after.sigeMin > acceptMin && after.sigeAvg > acceptAvg &&
         after.skewAvg < acceptSkewAvg && after.skewMax < acceptSkewMax)
        return true;
    }
    else {
      double acceptMin = (1. - boldness) * before.sicnMin;
      double acceptAvg = (1. - boldness) * before.sicnAvg * 0.5;
      if(after.sicnMin > acceptMin && after.sicnAvg > acceptAvg) return true;
    }

    return false;
  }

  bool remeshCavity(GFace *gf, RemeshableCavity &cav, QuadqsGFaceContext &ctx,
                    const std::vector<MElement *> &cavityNeighborsForSmoothing)
  {
    /* Collect current patch components */
    bool SHOW_REMESH_CAV = false;
    static size_t ccount = 0;
    if(SHOW_REMESH_CAV) {
      ccount += 1;
      std::string name = "cav" + std::to_string(ccount);
      GeoLog::add(cav.elements, name + "_try");
    }

    /* Call the remeshing code */
    const double minSICNafer = 0.;
    QualityConstraints qConstraints;
    qConstraints.SICNmin = 0.;
    qConstraints.SIGEmin = 0.;
    qConstraints.skewMax = DBL_MAX;
    GFaceMeshDiff diff;
    int st = remeshPatchWithQuadPattern(
      gf, cav.patternNoAndRot, cav.sides, cav.elements, cav.intVertices,
      qConstraints, ctx.invertNormalsForQuality, ctx.sp, diff);
    if(st != 0) {
      if(DBG_VERBOSE) {
        Msg::Debug(
          "remesh cavity: %li quads, failed to remesh path with quad pattern",
          cav.elements.size());
      }
      return false;
    }

    /* Check the geometry quality before / after */
    // double sicnMin, sicnAvg;
    // computeSICN(diff.before.elements, sicnMin, sicnAvg);
    // double sicnMinAfter, sicnAvgAfter;
    // computeSICN(diff.after.elements, sicnMinAfter, sicnAvgAfter);
    // if (keepCavityRemeshing(sicnMin, sicnAvg, sicnMinAfter, sicnAvgAfter)) {
    PatchQualityStats sBefore = computePatchQualityStats(diff.before.elements);
    PatchQualityStats sAfter = computePatchQualityStats(diff.after.elements);
    if(keepCavityRemeshing(sBefore, sAfter)) {
      constexpr bool verifyTopology = true;
      size_t neb = diff.before.elements.size();
      size_t nea = diff.after.elements.size();
      size_t nvb = diff.before.intVertices.size();
      size_t nva = diff.after.intVertices.size();

      if(SHOW_REMESH_CAV) {
        std::string name = "cav" + std::to_string(ccount);
        GeoLog::add(diff.after.elements, name + "_OK");
      }

      /* To smooth the interface between remeshed cavity and rest of the mesh,
       * we collect the boundary (interior to the mesh) and its adjacent quads
       */
      vector<MVertex *> toSmooth;
      vector<MElement *> neighbors = cavityNeighborsForSmoothing;
      {
        /* Cavity boundary vertices, inside the surface, not changed by
         * diff.execute() */
        toSmooth.reserve(diff.after.bdrVertices.front().size());
        for(MVertex *v : diff.after.bdrVertices.front()) {
          GFace *gf = dynamic_cast<GFace *>(v->onWhat());
          if(gf != nullptr) toSmooth.push_back(v);
        }

        /* New quads inside cavity, touching boundary, still present after
         * execute() */
        for(MElement *e : diff.after.elements)
          for(size_t lv = 0; lv < 4; ++lv) {
            MVertex *v = e->getVertex(lv);
            auto it = std::find(toSmooth.begin(), toSmooth.end(), v);
            if(it != toSmooth.end()) {
              neighbors.push_back(e);
              break;
            }
          }
        sort_unique(neighbors);
      }

      /* Modify the GFace mesh ! (and empty the diff content) */
      bool oke = diff.execute(verifyTopology);
      if(!oke) {
        Msg::Error("remesh cavity: diff execute() failed, should not happen");
        return false;
      }

      Msg::Debug("----V remeshed a cavity, %li -> %li quads, %li -> %li int. "
                 "vertices, SICN min: %.3f -> %.3f",
                 neb, nea, nvb, nva, sBefore.sicnMin, sAfter.sicnMin);

      /* Boundary vertex smoothing, to get a smooth transition with the
       * rest of the mesh after cavity remeshing */
      {
        GFaceMeshPatch patchBdr;
        bool okp = patchFromElements(gf, neighbors, patchBdr);
        if(okp) {
          Msg::Debug("----P smooth cavity boundary (%li vertices, %li quads)",
                     patchBdr.intVertices.size(), patchBdr.elements.size());
          GeomOptimStats stats;
          GeomOptimOptions opt;
          opt.sp = ctx.sp;
          opt.outerLoopIterMax = 20.;
          opt.timeMax = 10.;
          opt.withBackup = true;
          opt.invertCADNormals = ctx.invertNormalsForQuality;
          opt.smartMinThreshold = 0.1;
          opt.localLocking = true;
          opt.dxLocalMax = 1.e-4;
          patchOptimizeGeometryWithKernel(patchBdr, opt, stats);
        }
      }
      Msg::Debug("---->");
      return true;
    }
    else {
      Msg::Debug("----X reject cavity new geometry, SICN min: %.2f -> %.2f, "
                 "avg: %.2f -> %.2f",
                 sBefore.sicnMin, sAfter.sicnMin, sBefore.sicnAvg,
                 sAfter.sicnAvg, sBefore.skewAvg, sAfter.skewAvg);
      Msg::Debug("------- [SICN] min: %.3f -> %.3f, avg: %.3f -> %.3f",
                 sBefore.sicnMin, sAfter.sicnMin, sBefore.sicnAvg,
                 sAfter.sicnAvg);
      Msg::Debug("------- [SIGE] min: %.3f -> %.3f, avg: %.3f -> %.3f",
                 sBefore.sigeMin, sAfter.sigeMin, sBefore.sigeAvg,
                 sAfter.sigeAvg);
      Msg::Debug("------- [skew] max: %.3f -> %.3f, avg: %.3f -> %.3f",
                 sBefore.skewMax, sAfter.skewMax, sBefore.skewAvg,
                 sAfter.skewAvg);
      if(SHOW_REMESH_CAV) {
        std::string name = "cav" + std::to_string(ccount);
        GeoLog::add(diff.after.elements, name + "_REJQ");
      }
    }

    return false;
  }

  void assignSingularitiesToIrregularVertices(
    GFace *gf, const CavityFarmer &farmer,
    const std::vector<std::pair<SPoint3, int> > &singularities,
    std::vector<MVertex *> &irregularVertices)
  {
    irregularVertices.clear();

    /* Extract irregular vertices in face */
    vector<MVertex *> nodeVal3;
    vector<MVertex *> nodeVal5;

    for(uint32_t i = 0; i < farmer.vertices.size(); ++i) {
      uint32_t val = farmer.v2q_first[i + 1] - farmer.v2q_first[i];
      MVertex *v = farmer.vertices[i];
      if(v->onWhat() != gf) continue;
      if(val != 4) {
        if(val == 3) { nodeVal3.push_back(v); }
        else if(val == 5) {
          nodeVal5.push_back(v);
        }
      }
    }

    /* Assign singular vertices */
    for(size_t i = 0; i < singularities.size(); ++i) {
      int index = singularities[i].second;
      vector<MVertex *> *verticesp;
      if(index == 1) { verticesp = &nodeVal3; }
      else if(index == -1) {
        verticesp = &nodeVal5;
      }
      else {
        Msg::Warning(
          "cavity remeshing: face %i, singularity of index %i not supported",
          gf->tag(), index);
        continue;
      }
      SPoint3 p = singularities[i].first;
      vector<MVertex *> &vertices = *verticesp;
      double dmin = DBL_MAX;
      MVertex *best = nullptr;
      for(size_t j = 0; j < vertices.size(); ++j) {
        SVector3 p2 = vertices[j]->point();
        double dist = vertices[j]->point().distance(p);
        if(dist < dmin) {
          dmin = dist;
          best = vertices[j];
        }
      }
      if(best != nullptr) { irregularVertices.push_back(best); }
      else {
        Msg::Warning(
          "- Face %i, singular node %i, failed to assign to irregular vertex",
          gf->tag(), i);
      }
    }
  }

  struct CavityStart {
    std::vector<MQuadrangle *> quads;
    SPoint3 center;

    CavityStart(const std::vector<MQuadrangle *> &_qs)
    {
      quads = _qs;
      sort_unique(quads);
      center = SPoint3(0., 0., 0.);
      for(MQuadrangle *e : quads) { center = center + e->barycenter(); }
      if(quads.size() > 0) {
        center = center * double(1. / double(quads.size()));
      }
    }

    bool operator==(CavityStart const &b) const { return b.quads == quads; }
  };

  struct CavityStartHash {
    size_t operator()(const CavityStart &start) const noexcept
    {
      size_t seed = 0;
      for(MQuadrangle *a : start.quads) {
        hash_combine(seed, robin_hood::hash_bytes(&a, sizeof(MQuadrangle *)));
      }
      return seed;
    }
  };

  struct StartStats {
    int nTry = 0;
    int nTryMax = 0;
  };

  struct CavityRegulator {
    unordered_map<CavityStart, StartStats, CavityStartHash> starts;

    bool authorized(const CavityStart &start)
    {
      auto it = starts.find(start);
      if(it == starts.end()) { return true; }
      else {
        if(it->second.nTry < it->second.nTryMax) return true;
      }
      return false;
    }

    void declare(const CavityStart &start, int nTryMaxIfFirstTime = 3)
    {
      auto it = starts.find(start);
      if(it != starts.end()) { it->second.nTry += 1; }
      else { /* new start */
        StartStats st;
        st.nTry = 1;
        st.nTryMax = nTryMaxIfFirstTime;
        starts[start] = st;
      }
    }

    void decreaseCounterCloseStarts(const CavityFarmer &farmer,
                                    const SPoint3 &pos, size_t Nclose = 4)
    {
      std::vector<std::pair<double, StartStats *> > dist_stats;
      for(auto &kv : starts) {
        bool stillExists = true;
        for(MQuadrangle *q : kv.first.quads) {
          if(farmer.quadLocal.find(q) == farmer.quadLocal.end()) {
            stillExists = false;
            break;
          }
        }
        if(!stillExists) continue;
        double dist = pos.distance(kv.first.center);
        if(dist > 1.e-22) { dist_stats.push_back({dist, &(kv.second)}); }
      }
      std::sort(dist_stats.begin(), dist_stats.end());
      for(size_t i = 0; i < std::min(Nclose, dist_stats.size()); ++i) {
        dist_stats[i].second->nTry -= 1;
      }
    }
  };

  bool remeshQuadrilateralCavities(
    GFace *gf, const std::vector<std::pair<SPoint3, int> > &singularities,
    const std::vector<size_t> &patternsToCheck,
    const unordered_map<size_t, size_t> &patternSizeLimits,
    CavityRegulator &regulator, QuadqsGFaceContext &ctx)
  {
    if(ctx.finished) return true;

    Msg::Debug("-- remeshing quadrilateral cavities (%i quads, %i patterns to "
               "check) ...",
               gf->quadrangles.size(), patternsToCheck.size());
    unordered_set<MVertex *> allowedIrregularVertices;
    unordered_set<MVertex *> forbiddenIrregularVertices;
    std::vector<MVertex *> singularVertices; /* to be preserved */
    std::vector<MVertex *> seamExtremities;
    std::vector<SPoint3>
      repulsion; /* to distribute the cavities, add repulsion after remeshing */

    size_t nbCavityRemeshed = 0;

    /* for PASS_FROM_CORNERS
     * The queue contains the CAD corners which are not concave */
    std::deque<GVertex *> gcorners;
    for(GVertex *gv : gf->vertices()) { gcorners.push_back(gv); }

    /* for PASS_ALONG_GEDGES
     * The queue contains the curves which are not loop */
    std::queue<GEdge *> gedges;
    for(GEdge *ge : gf->edges()) {
      if(ge->faces().size() == 1 && ge->isSeam(ge->faces()[0])) {
        for(auto &gv : ge->vertices()) {
          auto it = std::find(gcorners.begin(), gcorners.end(), gv);
          if(it != gcorners.end()) { gcorners.erase(it); }
          for(auto &mv : gv->mesh_vertices) { seamExtremities.push_back(mv); }
        }
        continue;
      }
      /* Ignore periodic curves */
      if(ge->vertices().size() != 2) continue;
      if(ge->periodic(0)) continue;
      if(ge->vertices().front() == ge->vertices().back()) continue;
      gedges.push(ge);
    }

    /* for PASS_FROM_IRREGULAR
     * The priority queue contains the irregular vertices not associated
     * to cross field singularity and a priority based on repulsion.
     * Higher values appear first when doing Q.top() */
    std::priority_queue<std::pair<double, MVertex *>,
                        std::vector<std::pair<double, MVertex *> > >
      Qirreg;

    CavityFarmer farmer(gf);

    const size_t PASS_FROM_CORNERS = 1;
    const size_t PASS_ALONG_GEDGES = 2;
    const size_t PASS_FROM_IRREGULAR = 3;
    for(size_t pass :
        {PASS_FROM_CORNERS, PASS_ALONG_GEDGES, PASS_FROM_IRREGULAR}) {
      bool updateRequired = true;
      bool inProgress = true;
      while(inProgress || (pass == PASS_FROM_CORNERS && gcorners.size() > 0) ||
            (pass == PASS_ALONG_GEDGES && gedges.size() > 0) ||
            (pass == PASS_FROM_IRREGULAR && Qirreg.size() > 0)) {
        inProgress = false;

        if(updateRequired) {
          farmer.updateFarmer(gf);

          if(quadMeshIsMinimal(farmer, singularities)) {
            ctx.finished = true;
            break;
          }

          /* Get vertices to preserve from cross field singularities */
          assignSingularitiesToIrregularVertices(gf, farmer, singularities,
                                                 singularVertices);
          forbiddenIrregularVertices.clear();
          for(MVertex *v : singularVertices)
            forbiddenIrregularVertices.insert(v);
          for(MVertex *v : seamExtremities)
            forbiddenIrregularVertices.insert(v);

          if(pass == PASS_FROM_IRREGULAR) {
            /* Update the queue */
            while(!Qirreg.empty()) { /* empty the queue */
              Qirreg.pop();
            }
            for(uint32_t i = 0; i < farmer.vertices.size(); ++i) {
              uint32_t val = farmer.v2q_first[i + 1] - farmer.v2q_first[i];
              MVertex *v = farmer.vertices[i];
              if(v->onWhat() != gf) continue;
              if(val == 4) continue;
              if(forbiddenIrregularVertices.find(v) !=
                 forbiddenIrregularVertices.end())
                continue;

              SPoint3 pt = v->point();
              double prio = 0.;
              for(const SPoint3 &r : repulsion) { prio += pt.distance(r); }
              /* deterministic offset for reproductibility */
              double offsetR = 1.e-16 * double(v->getNum());
              Qirreg.push({prio + offsetR, v});
            }
          }

          updateRequired = false;
        }

        if(ctx.elapsedCpuTime() > ctx.timeoutQuadqsPerGFaceCavity) { break; }

        /* Initialize a remeshing cavity */
        std::vector<MQuadrangle *> quadsInit;
        size_t nTryMax = 3;
        GrowthPolicy policy;
        MVertex *vIrreg = nullptr; /* only used with PASS_FROM_IRREGULAR */
        if(pass == PASS_FROM_CORNERS) {
          if(gcorners.empty()) continue;
          policy = GROW_MAXIMAL;
          nTryMax = 1;
          allowedIrregularVertices.clear();
          GVertex *gv = gcorners.front();
          gcorners.pop_front();
          for(MVertex *v : gv->mesh_vertices) {
            std::vector<MQuadrangle *> adjQuads;
            bool oka = farmer.vertexAdjacentQuads(v, adjQuads);
            if(oka) { append(quadsInit, adjQuads); }
          }
          sort_unique(quadsInit);
          if(quadsInit.size() == 0 || quadsInit.size() >= 3)
            continue; /* do not start from concave corners */
        }
        else if(pass == PASS_ALONG_GEDGES) {
          if(gedges.empty()) continue;
          policy = GROW_MAXIMAL;
          nTryMax = 1;
          allowedIrregularVertices.clear();
          /* Get adjacent to a GEdge not yet processed */
          GEdge *ge = gedges.front();
          gedges.pop();
          for(MVertex *v : ge->mesh_vertices) {
            std::vector<MQuadrangle *> adjQuads;
            bool oka = farmer.vertexAdjacentQuads(v, adjQuads);
            if(oka) { append(quadsInit, adjQuads); }
          }
          sort_unique(quadsInit);
        }
        else if(pass == PASS_FROM_IRREGULAR) {
          if(Qirreg.empty()) continue;
          policy = GROW_MINIMAL;
          nTryMax = 3;
          vIrreg = Qirreg.top().second;
          Qirreg.pop();
          std::vector<MQuadrangle *> adjQuads;
          bool oka = farmer.vertexAdjacentQuads(vIrreg, adjQuads);
          if(oka) { append(quadsInit, adjQuads); }
          else {
            Msg::Error("remesh quad cavity: vertex not found in adjacency map, "
                       "should NEVER happen");
            return false;
          }
        }
        if(quadsInit.size() == 0) continue;

        /* Check if not too many try already done */
        CavityStart start(quadsInit);
        if(!regulator.authorized(start)) { continue; }
        regulator.declare(start, nTryMax);

        Msg::Debug("---< start cavity with %i quads", quadsInit.size());

        /* Grow a convex cavity containg irregular vertices to remove */
        RemeshableCavity cav;
        bool okg = farmer.growCavity(
          quadsInit, policy, patternsToCheck, patternSizeLimits,
          allowedIrregularVertices, forbiddenIrregularVertices, cav);
        if(!okg) { continue; }

        Msg::Debug("---- found a topological cavity with %i quads, try "
                   "geometrical remeshing",
                   cav.elements.size());

        std::vector<MElement *> neighbors;
        farmer.getCavityNeighbors(cav, neighbors);

        bool okr = remeshCavity(gf, cav, ctx, neighbors);
        if(okr) {
          /* GFace mesh has changed, need to update adjacency info (v2q is no
           * longer usable) */
          updateRequired = true;
          inProgress = true;
          nbCavityRemeshed += 1;
          repulsion.push_back(start.center);
          size_t NcloseUnlock = 4;
          regulator.decreaseCounterCloseStarts(farmer, start.center,
                                               NcloseUnlock);
        }
      }

      if(ctx.finished) break;
    }

    Msg::Debug("-- remeshed %i quadrilateral cavities", nbCavityRemeshed);

    ctx.nQuadCavityRemesh += nbCavityRemeshed;

    return true;
  }

  bool remeshSingularityCavities(
    GFace *gf, const std::vector<std::pair<SPoint3, int> > &singularities,
    const std::vector<size_t> &patternsToCheck,
    const unordered_map<size_t, size_t> &patternSizeLimits,
    CavityRegulator &regulator, QuadqsGFaceContext &ctx)
  {
    if(ctx.finished) return true;

    Msg::Debug("-- remeshing singularity cavities (face %i, %i quads, %i "
               "patterns to check) ...",
               gf->tag(), gf->quadrangles.size(), patternsToCheck.size());
    unordered_set<MVertex *> allowedIrregularVertices;
    unordered_set<MVertex *> forbiddenIrregularVertices;
    std::vector<MVertex *> singularVertices; /* to preserve */
    std::vector<SPoint3>
      repulsion; /* to distribute the cavities, add repulsion after remeshing */

    size_t nbCavityRemeshed = 0;

    /* The priority queue contains the irregular vertices associated to
     * cross field singularity and a priority based on repulsion.
     * Higher values appear first when doing Q.top() */
    std::priority_queue<std::pair<double, MVertex *>,
                        std::vector<std::pair<double, MVertex *> > >
      Q;

    CavityFarmer farmer(gf);

    bool updateRequired = true;
    bool inProgress = true;
    while(inProgress || Q.size() > 0) {
      inProgress = false;

      if(updateRequired) {
        farmer.updateFarmer(gf);

        if(quadMeshIsMinimal(farmer, singularities)) {
          ctx.finished = true;
          break;
        }

        /* Get vertices to preserve from cross field singularities */
        assignSingularitiesToIrregularVertices(gf, farmer, singularities,
                                               singularVertices);
        forbiddenIrregularVertices.clear();
        for(MVertex *v : singularVertices) forbiddenIrregularVertices.insert(v);

        /* Update the queue */
        while(!Q.empty()) { /* empty the queue */
          Q.pop();
        }
        for(MVertex *v : singularVertices) {
          SPoint3 pt = v->point();
          double prio = 0.;
          for(const SPoint3 &r : repulsion) { prio += pt.distance(r); }
          /* deterministic offset for reproductibility */
          double offsetR = 1.e-16 * double(v->getNum());
          Q.push({prio + offsetR, v});
        }

        updateRequired = false;
      }

      if(ctx.elapsedCpuTime() > ctx.timeoutQuadqsPerGFaceCavity) { break; }

      /* Initialize a remeshing cavity */
      if(Q.empty()) continue;
      GrowthPolicy policy = GROW_MINIMAL;
      if(singularities.size() == 1) policy = GROW_MAXIMAL;
      MVertex *vSing = Q.top().second;
      Q.pop();
      std::vector<MQuadrangle *> quadsInit;
      bool oka = farmer.vertexAdjacentQuads(vSing, quadsInit);
      if(!oka) {
        Msg::Error("remesh singularity cavity: vertex not found in adjacency "
                   "map, should NEVER happen");
        return false;
      }
      allowedIrregularVertices.clear();
      allowedIrregularVertices.insert(vSing);

      /* Check if not too many try already done */
      CavityStart start(quadsInit);
      if(!regulator.authorized(start)) { continue; }
      int nTryMax = 3;
      regulator.declare(start, nTryMax);

      Msg::Debug(
        "---< start cavity with %i quads adjacent to singularity vertex %li",
        quadsInit.size(), vSing->getNum());

      /* Grow a convex cavity containg irregular vertices to remove */
      RemeshableCavity cav;
      bool okg = farmer.growCavity(quadsInit, policy, patternsToCheck,
                                   patternSizeLimits, allowedIrregularVertices,
                                   forbiddenIrregularVertices, cav);
      if(!okg) { continue; }

      Msg::Debug("---- found a topological cavity with %i quads, try "
                 "geometrical remeshing",
                 cav.elements.size());

      std::vector<MElement *> neighbors;
      farmer.getCavityNeighbors(cav, neighbors);

      bool okr = remeshCavity(gf, cav, ctx, neighbors);

      if(okr) {
        /* GFace mesh has changed, need to update adjacency info (v2q is no
         * longer usable) */
        updateRequired = true;
        inProgress = true;
        nbCavityRemeshed += 1;
        repulsion.push_back(start.center);
        size_t NcloseUnlock = 4;
        regulator.decreaseCounterCloseStarts(farmer, start.center,
                                             NcloseUnlock);
      }
    }

    ctx.nSingCavityRemesh += nbCavityRemeshed;

    Msg::Debug("-- remeshed %i singularity cavities", nbCavityRemeshed);

    return true;
  }

  /* Global storage. Patterns are initialized at runtime, by the call to
   * initQuadPatterns() */
  std::vector<QuadMeshPattern> patterns;
} // namespace QMT

using namespace QMT;

int initQuadPatterns()
{
  if(patterns.size() != 0) return false;
  {
    Msg::Info("loading %li quad patterns", quad_meshes.size());
    patterns.resize(quad_meshes.size());
    for(size_t i = 0; i < quad_meshes.size(); ++i) {
      bool ok = patterns[i].load(quad_meshes[i].first, quad_meshes[i].second);
      if(!ok) {
        Msg::Error("mesh quad patterns, failed to init pattern no %i", i);
      }
    }
  }
  return true;
}

std::vector<size_t> getAllLoadedPatterns()
{
  std::vector<size_t> pIds;
  for(size_t i = 0; i < patterns.size(); ++i) {
    pIds.push_back(patterns[i].patternId);
  }
  return pIds;
}

bool patchIsRemeshableWithQuadPattern(
  const std::vector<size_t> &patternsToCheck, size_t Ncorners,
  const std::vector<size_t> &sideSizes, std::pair<size_t, int> &patternNoAndRot,
  double &irregularityMeasure)
{
  irregularityMeasure = DBL_MAX;
  if(patterns.size() == 0) {
    Msg::Error(
      "Quad patterns are not loaded, please call initQuadPatterns() before");
    return false;
  }

  vector<bool> check(patterns.size(), false);
  for(size_t pId : patternsToCheck) check[pId] = true;

  double irreg_min = DBL_MAX;
  for(size_t i = 0; i < patterns.size(); ++i)
    if(check[i]) {
      const QuadMeshPattern &P = patterns[i];
      // DBG(" ", i, P.ncorners, P.sides.size());;
      if(Ncorners != P.ncorners) continue;
      if(sideSizes.size() != P.sides.size()) continue;

      int rot = 0;
      double score = checkPatternMatchingWithRotations(P, sideSizes, rot);
      if(score > 0.) {
        double irreg = patternIrregularity(P);
        if(irreg < irreg_min) {
          patternNoAndRot.first = i;
          patternNoAndRot.second = rot;
          irreg_min = irreg;
        }
      }
    }

  irregularityMeasure = irreg_min;
  return (irreg_min != DBL_MAX);
}

int remeshPatchWithQuadPattern(
  GFace *gf, const std::pair<size_t, int> &patternNoAndRot,
  const std::vector<std::vector<MVertex *> > &sides,
  const std::vector<MElement *> &elements,
  const std::vector<MVertex *> &intVertices,
  const QualityConstraints &qualityConstraints, bool invertNormalsForQuality,
  SurfaceProjector *sp, GFaceMeshDiff &diff)
{
  if(patterns.size() == 0) {
    Msg::Error(
      "Quad patterns are not loaded, please call initQuadPatterns() before");
    return false;
  }

  size_t N = sides.size();
  const QuadMeshPattern &P = patterns[patternNoAndRot.first];
  int rot = patternNoAndRot.second;
  if(P.sides.size() != N) {
    Msg::Error("remesh patch with patterns: sides not matching, shoud not "
               "happen (pattern has %li sides, but %li sides in input) ...",
               P.sides.size(), N);
    return -1;
  }

  /* Apply the rotation */
  std::vector<std::vector<MVertex *> > sidesr = sides;
  if(rot > 0) {
    std::rotate(sidesr.begin(), sidesr.begin() + (size_t)rot, sidesr.end());
  }
  else if(rot < 0) {
    std::reverse(sidesr.begin(), sidesr.end());
    std::rotate(sidesr.begin(), sidesr.begin() + (size_t)std::abs(rot),
                sidesr.end());
    for(size_t i = 0; i < sidesr.size(); ++i) {
      std::reverse(sidesr[i].begin(), sidesr[i].end());
    }
  }

  /* Verify the given pattern and given sides are coherent */
  vector<size_t> ssr(sidesr.size());
  for(size_t i = 0; i < sidesr.size(); ++i) ssr[i] = sidesr[i].size();
  vector<int> slt;
  double match = checkPatternMatching(P, ssr, slt);
  if(match <= 0.) {
    Msg::Error(
      "remesh patch with patterns: given pattern not matching given sides");
    return -1;
  }

  /* Add the new vertices and quads in the GFace */
  MVertex *oldCenter = centerOfElements(elements);

  /* Generate new interior MVertex and MElement instances */
  diff.gf = gf;
  diff.after.gf = gf;
  bool oka = addQuadsAccordingToPattern(
    P, slt, gf, sidesr, diff.after.intVertices, diff.after.elements, oldCenter);
  if(!oka) {
    Msg::Error("failed to add quads according to pattern, weird");
    clearStuff(diff.after.intVertices, diff.after.elements);
    return -1;
  }

  /* Ensure coherent orientation between the new mesh and the boundary.
   * The reference orientation (a,b) is from the sides before applying
   * rotation. */
  MVertex *a = sides[0][0];
  MVertex *b = sides[0][1];
  bool oko =
    orientElementsAccordingToBoundarySegment(a, b, diff.after.elements);
  if(!oko) {
    Msg::Error("remesh quad with patterns: bdr quad edge not found, weird");
    return false;
  }

  /* Build the old patch in the diff */
  diff.before.gf = gf;
  diff.before.intVertices = intVertices;
  diff.before.elements = elements;
  /* - build a continuous bdr loop from the sides */
  diff.before.bdrVertices = {{sides.front().front()}};
  for(auto &side : sides)
    for(MVertex *v : side) {
      if(v != diff.before.bdrVertices.front().back()) {
        diff.before.bdrVertices.front().push_back(v);
      }
    }
  if(diff.before.bdrVertices.front().back() ==
     diff.before.bdrVertices.front().front()) {
    diff.before.bdrVertices.front().pop_back();
  }
  diff.after.bdrVertices =
    diff.before.bdrVertices; /* the new patch has the same bdr */

  /* Determine the new patch geometry by smoothing on the surface */
  GeomOptimStats stats;
  int stGeoGlobal = -1;
  bool statsOk = false;
  if(gf->haveParametrization()) {
    stGeoGlobal = patchOptimizeGeometryGlobal(diff.after, stats);
    if(stGeoGlobal == 0) {
      statsOk =
        patchPassesQualityConstraints(diff.after.elements, qualityConstraints);
    }
    else {
      Msg::Debug("failed to optimize geometry with global UV smoothing");
    }
  }

  if(!gf->haveParametrization() || stGeoGlobal != 0 || !statsOk) {
    /* Project */
    bool okp = patchProjectOnSurface(diff.after, sp);
    if(!okp) {
      Msg::Debug("failed to project geometry");
      return -1;
    }

    /* Smooth with kernel */
    GeomOptimOptions opt;
    opt.sp = sp;
    opt.invertCADNormals = invertNormalsForQuality;
    opt.outerLoopIterMax = 100;
    opt.timeMax = 0.5;
    opt.kernelRegular = SmoothingKernel::WinslowFDM;
    opt.kernelIrregular = SmoothingKernel::Laplacian;
    opt.localLocking = true;
    opt.dxGlobalMax = 0.;
    opt.dxLocalMax = 1.e-5;
    opt.withBackup = false;
    patchOptimizeGeometryWithKernel(diff.after, opt, stats);
    statsOk =
      patchPassesQualityConstraints(diff.after.elements, qualityConstraints);
  }

  if(!statsOk) {
    Msg::Debug("remesh patch with quad pattern: rejected because of quality "
               "constraints (SICN min is %.3f)",
               stats.sicnMinAfter);
    return -1;
  }

  return 0;
}

int improveQuadMeshTopologyWithCavityRemeshing(
  GFace *gf, const std::vector<std::pair<SPoint3, int> > &singularities,
  bool invertNormalsForQuality)
{
  Msg::Info("- Face %i: optimize quad mesh topology (%i elements, %i cross "
            "field singularities) with cavity remeshing ...",
            gf->tag(), gf->quadrangles.size(), singularities.size());
  size_t nqb = gf->quadrangles.size();
  size_t nvb = gf->mesh_vertices.size();

  QuadqsContext qqs;

  // Msg::Warning("- timeout set to 100s (debugging)");
  // qqs.timeoutQuadqsPerGFace = 100;
  // qqs.timeoutQuadqsPerGFaceCavity = 100;

  QuadqsGFaceContext ctx(qqs);
  ctx.invertNormalsForQuality = invertNormalsForQuality;

  bool alwaysBuildSurfaceProjector = true;
  if(alwaysBuildSurfaceProjector || !haveNiceParametrization(gf)) {
    ctx.sp = new SurfaceProjector();
    bool okf = fillSurfaceProjector(gf, ctx.sp);
    if(!okf) { return false; }
  }

  unordered_map<size_t, size_t> patternSizeLimits;
  patternSizeLimits[PATTERN_QUAD_DIAG35] = 100;
  patternSizeLimits[PATTERN_QUAD_ALIGNED35] = 200;
  patternSizeLimits[PATTERN_QUAD_CHORD_UTURN] = 100;
  vector<size_t> patternsToCheck;

  /* For a given cavity start, we count the number of cavities
   * that have been tried
   * The count is reset when an another close cavity is remeshed.
   * When a cavity is remeshed, its interior vertices are changed,
   * so the count is automatically reset.
   * (the content may be invalid, so it shoud not be used without checking
   * existence) */
  CavityRegulator regulator;

  bool running = true;
  while(running) {
    running = false;
    size_t ncrb = ctx.nQuadCavityRemesh + ctx.nSingCavityRemesh;

    Msg::Debug("<< start cavity remeshing iteration");

    /* 1st pass: check regular quad patch remeshing only */
    patternsToCheck = {PATTERN_QUAD_REGULAR};
    bool ok1 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck,
                                           patternSizeLimits, regulator, ctx);
    if(!ok1) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities",
                 gf->tag());
      return false;
    }

    /* 2d pass: remesh around cross field singularities */
    patternsToCheck = {PATTERN_TRIANGLE, PATTERN_PENTAGON};
    bool ok2 = remeshSingularityCavities(gf, singularities, patternsToCheck,
                                         patternSizeLimits, regulator, ctx);
    if(!ok2) {
      Msg::Error("- Face %i: failed to remesh singularity cavities", gf->tag());
      return false;
    }

    /* 3d pass: check regular quad patches again (if unlocked by singularity
     * remeshing) */
    patternsToCheck = {PATTERN_QUAD_REGULAR};
    bool ok3 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck,
                                           patternSizeLimits, regulator, ctx);
    if(!ok3) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities",
                 gf->tag());
      return false;
    }

    /* 4d pass: size transition patterns */
    patternsToCheck = {PATTERN_QUAD_REGULAR, PATTERN_QUAD_DIAG35,
                       PATTERN_QUAD_ALIGNED35, PATTERN_QUAD_CHORD_UTURN};
    bool ok4 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck,
                                           patternSizeLimits, regulator, ctx);
    if(!ok4) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities",
                 gf->tag());
      return false;
    }

    size_t ncra = ctx.nQuadCavityRemesh + ctx.nSingCavityRemesh;
    if(ncra > ncrb) { /* The mesh changed */
      /* Smooth geometry (quick) */
      double timeMax = 1.;
      optimizeGeometryQuadMesh(gf, ctx.sp, timeMax);

      /* Decrease the try counter, to enable a new try everywhere */
      for(auto &kv : regulator.starts)
        if(kv.second.nTry > 0) { kv.second.nTry -= 1; }
    }

    /* Restart a full iteration if some cavities have been remeshed */
    if(ncra > ncrb) running = true;
    Msg::Debug(">> end of cavity remeshing iteration");

    if(ctx.finished) {
      Msg::Debug("quad mesh remeshing is finised (minimal number of irregular "
                 "vertices)");
      break;
    }

    if(ctx.elapsedCpuTime() > ctx.timeoutQuadqsPerGFaceCavity) {
      Msg::Debug("quad mesh remeshing has reached timeout, break");
      break;
    }
  }

  if(ctx.sp) {
    delete ctx.sp;
    ctx.sp = nullptr;
  }

  Msg::Info("- Face %i: remeshed %i singular and %i quadrilateral cavities, %i "
            "-> %i quads, %i -> %i vertices",
            gf->tag(), ctx.nSingCavityRemesh, ctx.nQuadCavityRemesh, nqb,
            gf->quadrangles.size(), nvb, gf->mesh_vertices.size());

  return 0;
}

int meshFaceWithGlobalPattern(GFace *gf, bool invertNormalsForQuality,
                              double minimumQualityRequired)
{
  GFaceInfo info;
  bool okf = fillGFaceInfo(gf, info);
  if(!okf) return -1;

  /* Check if convex topological disk */
  bool convexTopologicalDisk =
    isTopologicalDisk(info) && !haveConcaveCorners(info);
  if(!convexTopologicalDisk) { return -1; }

  Msg::Debug("- Face %i: is topological disk, try quad pattern meshing",
             gf->tag());

  double t0 = Cpu();

  /* Build the ordered sides */
  const vector<GEdge *> &edges = gf->edges();
  unordered_map<GVertex *, vector<GEdge *> > v2e;
  for(GEdge *ge : edges) {
    if(ge->periodic(0)) continue;
    for(GVertex *gv : ge->vertices()) v2e[gv].push_back(ge);
  }
  for(auto &kv : v2e) { sort_unique(kv.second); }
  std::set<GVertex *> corners = info.bdrValVertices[1];
  bool disk = (corners.size() == 0 && info.bdrValVertices[2].size() > 0);

  /* Sort CAD edges in sides */
  vector<vector<GEdge *> > sides;
  vector<vector<bool> > sidesInv;
  for(GEdge *e0 : edges)
    if(!e0->periodic(0)) {
      GVertex *v1 = e0->vertices()[0];
      GVertex *v2 = e0->vertices()[1];
      bool v1IsCorner = (corners.find(v1) != corners.end());
      if(!disk && !v1IsCorner) continue;
      if(disk) {
        sides.resize(1);
        sidesInv.resize(1);
      }

      size_t infLoop = 0;
      GVertex *v = v1;
      GEdge *e = e0;
      bool inv = false;
      do {
        infLoop += 1;
        if(infLoop > 1e6) {
          Msg::Warning(
            "infinite loop in edges of face %i, cancel simple quad mesh",
            gf->tag());
          return -1;
        }
        bool vIsCorner = (corners.find(v) != corners.end());
        if(vIsCorner) {
          sides.resize(sides.size() + 1);
          sidesInv.resize(sidesInv.size() + 1);
        }
        v1 = e->vertices()[0];
        v2 = e->vertices()[1];

        inv = (v == v2);

        sides.back().push_back(e);
        sidesInv.back().push_back(inv);

        GVertex *v_next = NULL;
        if(v2 != v) { v_next = v2; }
        else {
          v_next = v1;
        }
        GEdge *e_next = NULL;
        if(v2e[v_next].size() == 2) {
          e_next = (v2e[v_next][0] != e) ? v2e[v_next][0] : v2e[v_next][1];
        }
        else {
          Msg::Warning(
            "non manifold edge loop around face %li, cancel simple quad mesh",
            gf->tag());
          return -1;
        }

        e = e_next;
        v = v_next;
      } while(e != e0);
      break;
    }

  if(disk && gf->edges().size() == 1 && gf->edges()[0]->periodic(0)) {
    sides = {gf->edges()};
    sidesInv = {{false}};
  }

  if(sides.size() == 0) {
    Msg::Debug("face %i (%li edges), failed to build sides", gf->tag(),
               edges.size());
    // DBG(disk);
    return -1;
  }

  /* Collect mesh vertices */
  vector<vector<MVertex *> > sideVertices(sides.size());
  for(size_t i = 0; i < sides.size(); ++i) {
    for(size_t j = 0; j < sides[i].size(); ++j) {
      GEdge *ge = sides[i][j];
      bool inv = sidesInv[i][j];
      GVertex *v1 = ge->vertices()[0];
      GVertex *v2 = ge->vertices()[1];

      /* Vertices from v1 to v2 */
      vector<MVertex *> ge_vert;
      {
        std::vector<MEdge> medges(ge->lines.size());
        for(size_t k = 0; k < ge->lines.size(); ++k) {
          medges[k] =
            MEdge(ge->lines[k]->getVertex(0), ge->lines[k]->getVertex(1));
        }
        std::vector<std::vector<MVertex *> > gevs;
        bool oks = SortEdgeConsecutive(medges, gevs);
        if(!oks || gevs.size() != 1) return -1;
        if(gevs[0].front() == v1->mesh_vertices[0] &&
           gevs[0].back() == v2->mesh_vertices[0]) {
          ge_vert = gevs[0];
        }
        else if(gevs[0].front() == v2->mesh_vertices[0] &&
                gevs[0].back() == v1->mesh_vertices[0]) {
          ge_vert = gevs[0];
          std::reverse(ge_vert.begin(), ge_vert.end());
        }
        else {
          Msg::Error("corner and edge vertices not matching");
          return -1;
        }
      }

      if(inv) { std::reverse(ge_vert.begin(), ge_vert.end()); }
      if(sideVertices[i].size() == 0) { append(sideVertices[i], ge_vert); }
      else {
        if(sideVertices[i].back() == ge_vert[0]) { sideVertices[i].pop_back(); }
        append(sideVertices[i], ge_vert);
      }
    }
  }

  /* When there is just one side, two possible cases:
   * - disk (all bdr vertices are quad-valence 2)
   * - face with only one convex corner
   */
  if(sides.size() == 1) {
    if(sides[0].size() < 1) {
      Msg::Warning(
        "not enough vertices on face loop for quad meshing (%li vert)",
        sides[0].size());
      return -1;
    }
    if(disk) {
      if(sides[0].front() == sides[0].back()) { sides[0].pop_back(); }
    }
    else {
      if(sides[0].front() == sides[0].back()) { sides[0].pop_back(); }
    }
  }

  /* Pure topological check with side sizes */
  std::vector<size_t> patternsToCheck = getAllLoadedPatterns();
  std::vector<size_t> sideSizes(sideVertices.size());
  for(size_t i = 0; i < sideSizes.size(); ++i)
    sideSizes[i] = sideVertices[i].size();

  std::pair<size_t, int> patternNoAndRot;
  size_t Ncorners = disk ? 0 : sideSizes.size();
  double irreg;
  bool meshable = patchIsRemeshableWithQuadPattern(
    patternsToCheck, Ncorners, sideSizes, patternNoAndRot, irreg);
  if(!meshable) return -1;

  /* Build the mesh, smooth and check the geometry quality */
  std::vector<MElement *> oldElements;
  oldElements.reserve(gf->quadrangles.size() + gf->triangles.size());
  for(MElement *f : gf->triangles) oldElements.push_back(f);
  for(MElement *f : gf->quadrangles) oldElements.push_back(f);
  std::vector<MVertex *> oldVertices = gf->mesh_vertices;

  /* SurfaceProjector, useful for smoothing */
  SurfaceProjector *sp = new SurfaceProjector();
  bool oksp = fillSurfaceProjector(gf, sp);
  if(!oksp) {
    delete sp;
    sp = nullptr;
  }

  /* do not filter based on quality */
  QualityConstraints qConstraints;
  qConstraints.SICNmin = -DBL_MAX;
  qConstraints.SIGEmin = -DBL_MAX;
  qConstraints.skewMax = DBL_MAX;
  GFaceMeshDiff diff;
  int st = remeshPatchWithQuadPattern(gf, patternNoAndRot, sideVertices,
                                      oldElements, oldVertices, qConstraints,
                                      invertNormalsForQuality, sp, diff);
  if(st != 0) {
    if(DBG_VERBOSE) {
      Msg::Debug(
        "remesh cavity: %li quads, failed to remesh path with quad pattern",
        oldElements.size());
    }
    if(sp) delete sp;
    return -1;
  }

  bool good = false;
  double sicnMin, sicnAvg;
  double sicnMinAfter, sicnAvgAfter;
  size_t neb = diff.before.elements.size();
  size_t nea = diff.after.elements.size();
  size_t nvb = diff.before.intVertices.size();
  size_t nva = diff.after.intVertices.size();
  {
    GeomOptimStats stats;
    GeomOptimOptions opt;
    opt.sp = sp;
    opt.outerLoopIterMax = 100;
    opt.timeMax = 3.;
    opt.localLocking = true;
    opt.dxGlobalMax = 1.e-3;
    opt.dxLocalMax = 1.e-5;
    opt.force3DwithProjection = true;
    opt.withBackup = false;
    bool oko = patchOptimizeGeometryWithKernel(diff.after, opt, stats);
    if(!oko) {
      if(sp) delete sp;
      return -1;
    }

    computeSICN(diff.before.elements, sicnMin, sicnAvg);
    computeSICN(diff.after.elements, sicnMinAfter, sicnAvgAfter);
    if(sicnMinAfter > minimumQualityRequired) {
      constexpr bool verifyTopology = true;
      bool oke = diff.execute(verifyTopology);
      if(oke) { good = true; }
      else {
        Msg::Error("remesh cavity: diff execute() failed, should not happen");
      }
    }
    else {
      Msg::Debug("- Face %i: pattern-based quad mesh REJECTED because SICN min "
                 "%.3f < %.3f",
                 gf->tag(), sicnMinAfter, minimumQualityRequired);
    }
  }

  if(good) {
    Msg::Info("- Face %i: remeshed with a global pattern, %li -> %li quads, %i "
              "-> %i int. vertices, SICN min: %.3f -> %.3f, SICN avg: %.3f -> "
              "%.3f, time: %.3fs",
              gf->tag(), neb, nea, nvb, nva, sicnMin, sicnMinAfter, sicnAvg,
              sicnAvgAfter, Cpu() - t0);
    gf->meshStatistics.status = GFace::DONE;
  }

  if(sp) delete sp;

  return good;
}
