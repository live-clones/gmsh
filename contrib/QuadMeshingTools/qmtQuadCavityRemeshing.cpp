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

    //    printf("sideSizes : ");
    //    for (auto i : sideSizes) printf("%lu ",i);
    //    printf("\n");
    
    
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

int meshFaceWithGlobalPattern(GFace *gf, bool invertNormalsForQuality,
                              double minimumQualityRequired)
{
  //  auto oldEdges = replaceCompounds(gf);

  GFaceInfo info;
  bool okf = fillGFaceInfo(gf, info);
  if(!okf) {
    //    gf->set(oldEdges);
    return -1;
  }

  /* Check if convex topological disk */
  bool convexTopologicalDisk =
    isTopologicalDisk(info) && !haveConcaveCorners(info);
  if(!convexTopologicalDisk) { return -1; }

  Msg::Debug("- Face %i: is topological disk, try quad pattern meshing",
             gf->tag());


  double t0 = Cpu();

  /* Build the ordered sides */
  std::vector<GEdge *> edges = gf->edges();
  
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
	  //	  gf->set(oldEdges);
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
	  //	  gf->set(oldEdges);
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
    //    gf->set(oldEdges);
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
        if(!oks || gevs.size() != 1) {
	  //	  gf->set(oldEdges);
	  return -1;
	}
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
	  //	  gf->set(oldEdges);
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
      //      gf->set(oldEdges);
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


  if(!meshable) {
    //    gf->set(oldEdges);
    return -1;
  }

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

  //  gf->set(oldEdges);
  return good;
}
