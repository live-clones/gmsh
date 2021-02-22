// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtQuadCavityRemeshing.h"

/* System includes */
// #include <vector>
// #include <array>
// #include <unordered_map>
// #include <cstdint>
// #include <math.h>
#include <queue>
#include <unordered_set>
// #include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
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
  using std::vector;
  using std::array;


  /* robin_hood hash sets and maps are much faster than the STL version */
  // using std::unordered_map;
  // using std::unordered_set;

  template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
           typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
             using unordered_map = robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

  template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key>,
           size_t MaxLoadFactor100 = 80>
             using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

  /* hash_combine from boost */
  template <class T>
    inline void hash_combine(std::size_t& seed, const T& v)
    {
      std::hash<T> hasher;
      seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }


  using id = uint32_t;
  using id2 = std::array<id,2>;
  using id4 = std::array<id,4>;

  constexpr bool DBG_VERBOSE = true;

  /* Quad meshes of patterns, known at compile time
   * These patterns must be CONVEX
   * WARNING: orientation of quads must be coherent ! */
  const std::vector<std::pair<size_t,std::vector<id4> > > quad_meshes = {
    /* regular quad patch */
    {PATTERN_QUAD_REGULAR,{{0,1,2,3}}},

    /* triangular patch with one val3 singularity */
    {PATTERN_TRIANGLE,{{0,1,6,5},{1,2,3,6},{3,4,5,6}}}, 

    /* pentagonal patch with one val5 singularity */
    {PATTERN_PENTAGON,{{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}}},

    /* quad patch with one val3 and one val5 singularities (on diagonal) */
    {PATTERN_QUAD_DIAG35,{{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {8, 9, 10, 11}}},

    /* quad patch with one val3, one val5 singularities and two regular inside (3-5 pair for size transition) */
    {PATTERN_QUAD_ALIGNED35,{{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {9, 10, 12, 11}, {3, 13, 12, 10}, {8, 9, 11, 14}, {2, 15, 13, 3}}},

    /* quad patch with two val3, two val5 inside, size transition by having a chord making a U-turn */
    {PATTERN_QUAD_CHORD_UTURN,{{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {9, 10, 12, 11}, {9, 11, 14, 13}, {8, 9, 13, 15}, {6, 7, 8, 15}}},

    /* patch with two corners, two val3 singularities inside (good for eye shape) */
    {PATTERN_2CORNERS,{{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 3, 6, 5}, {4, 5, 6, 7}}},

    /* patch with one corner, three val3 singularities inside and one regular vertiex */
    {PATTERN_1CORNER,{{0,1,6,5},{1,2,7,6},{2,3,8,7},{3,4,9,8},{4,5,6,9},{6,7,8,9}}},

    /* disk pattern (no corners) */
    {PATTERN_DISK,{{0,1,6,5},{1,2,7,6},{2,3,4,7},{0,5,4,3},{4,5,6,7}}},
  };

  constexpr id NO_ID = (id) -1;
  inline id2 sorted(id v1, id v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }
  inline id2 sorted(id2 e) { if (e[0] < e[1]) { return {e[0],e[1]}; } else { return {e[1],e[0]}; } }

  struct id2hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  struct vidHash {
    size_t operator()(const std::vector<id>& p) const noexcept {
      size_t seed = 0;
      for (size_t i = 0; i < p.size(); ++i) {
        hash_combine(seed, robin_hood::hash_bytes(&(p[i]), sizeof(id)));
      }
      return seed;
    }
  };

  bool build_quad_chord(const vector<id4>& quadEdges, const vector<vector<id> >& e2f, id eStart, std::vector<id>& chordEdges) {
    chordEdges.size();

    vector<bool> visited(e2f.size(),false);

    /* Init */
    visited[eStart] = true;
    std::queue<id> qq;
    qq.push(eStart);

    /* Propagation */
    while (qq.size() > 0) {
      id e = qq.front();
      qq.pop();
      chordEdges.push_back(e);

      for (size_t lf = 0; lf < e2f[e].size(); ++lf) {
        id f = e2f[e][lf];
        id oe = NO_ID;
        for (size_t le = 0; le < 4; ++le) {
          if (quadEdges[f][le] == e) {
            oe = quadEdges[f][(le+2)%4];
            break;
          }
        }
        if (oe == NO_ID) return false;
        if (visited[oe]) continue;
        visited[oe] = true;
        qq.push(oe);
      }
    }

    sort_unique(chordEdges);

    return true;
  }

  double sum_sqrt(const vector<int>& values) {
    double s = 0.;
    for (const auto& v: values) s += sqrt(v);
    return s;
  }

  bool all_strictly_positive(const vector<int>& values) {
    for (const auto& v: values) if (v <= 0) return false;
    return true;
  }

  /* Struct to interface with row_echelon_integer.hpp */
  struct IMatrix {
    /* Data */
    int m;
    int n;
    std::vector<int> a;

    /* Methods */
    IMatrix(int m_, int n_): m(m_), n(n_) {
      a.resize(m*n,0);
    }

    void set(int i, int j, int value) { a[i+j*m] = value; }
    int get(int i, int j) const {return a[i+j*m]; }

    int tansform_to_row_reduced_echelon() {
      return i4mat_ref(m,n,a.data());
    }

    void print(const std::string& title = "IMatrix") {
      i4mat_print(m, n, a.data(), title);
    }

    double solution_score(const std::vector<int>& x) {
      if (x.size() != (size_t) n-1) return 0.;
      for (int j = 0; j < n-1; ++j) {
        if (x[j] == 0) return 0.;
      }

      /* Verify x is solution */
      for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n-1; ++j) {
          sum += x[j] * get(i,j);
        }
        sum += get(i,n-1);
        if (sum != 0) { /* Not a solution */
          return 0.;
        }
      }

      return sum_sqrt(x);
    }

    double get_positive_solution_DFS(std::vector<int>& x, int& count, int count_limit, const std::vector<double>& x_ideal, int& ncalls) {
      if (x.size() == 0) {
        x.resize(n-1,0);
        /* Check if a unknown is uncontrained. Happen with purely internal chords */
        int sum_rhs = 0;
        vector<bool> touched(x.size(),false);
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n-1; ++j) {
            int acoef = get(i,j);
            if (acoef != 0) {
              touched[j] = true;
            }
          }
          sum_rhs += std::abs(get(i,n-1));
        }
        for (int j = 0; j < n-1; ++j) if (!touched[j]) {
          x[j] = sum_rhs / (n-1);
          if (x[j] < 0) x[j] = 1;
        }
      }

      ncalls += 1;
      if (ncalls > 1e7) {
        Msg::Debug("get_positive_solution_DFS: infinite loop ? %i calls in recursion", ncalls);
        return 0.;
      }
      if (all_strictly_positive(x)) count += 1;
      if (count > count_limit) return 0.;

      /* Stop condition: x is solution and has positive score */
      double current_score = solution_score(x);
      if (current_score > 0.) return current_score;


      double best_score = 0.;
      vector<int> best_x;
      std::vector<int> undetermined;
      /* Loop from last line to first line */
      for (int i = m-1; i >= 0; --i) { 
        undetermined.clear();
        /* Check line */
        int total = -1 * get(i,n-1);
        for (int j = 0; j < n-1; ++j) {
          int w = get(i,j);
          if (w != 0) {
            if (x[j] == 0) {
              undetermined.push_back(j);
            } else {
              total -= w * x[j];
            }
          }
        }
        if (undetermined.size() == 0) {
          if (total == 0) {
            continue;
          } else {
            return 0.;
          }
        }

        /* Fix one value and make recursive call */
        if (undetermined.size() == 1) {
          int j = undetermined[0];
          int w = get(i,j);
          if (total % w == 0) {
            int candidate = total / w;
            if (candidate < 1) return 0.;
            vector<int> x2 = x;
            x2[j] = candidate;
            double sub_score = get_positive_solution_DFS(x2, count, count_limit, x_ideal, ncalls);
            if (sub_score > 0.) { /* Found a solution ! Return this one */
              x = x2;
              return sub_score;
            }
          }
        } else {
          double sum = 0.;
          for (size_t k = 0; k < undetermined.size(); ++k) {
            int j = undetermined[k];
            int w = get(i,j);
            sum += std::abs(w);
          }
          for (size_t k = 0; k < undetermined.size(); ++k) {
            int j = undetermined[k];
            int w = get(i,j);
            double ideal_repartition = 1./sum * double(total);
            int xmin = 1;
            int xmax = int(double(total) / double(w));
            if (xmax < xmin) return 0.;
            if ((size_t)j < x_ideal.size()) {
              ideal_repartition = x_ideal[j];
            }

            vector<std::pair<double,int> > prio_candidate;
            if (xmax == xmin) {
              prio_candidate.push_back({0.,xmin});
            } else {
              for (int candidate = xmin; candidate < xmax+1; ++candidate) {
                double dist = std::pow(ideal_repartition-candidate,2);
                prio_candidate.push_back({dist,candidate});
              }
            }

            // TODO: better priority, see 2 corner cases
            std::sort(prio_candidate.begin(),prio_candidate.end());
            vector<int> x2;
            for (size_t l = 0; l < prio_candidate.size(); ++l) {
              int candidate = prio_candidate[l].second;
              x2 = x;
              x2[j] = candidate;
              double sub_score = get_positive_solution_DFS(x2, count, count_limit, x_ideal, ncalls);
              if (sub_score > 0.) { /* Found a solution ! Return this one */
                x = x2;
                return sub_score;
              }
            }
          }
        }
      }
      if (best_score > 0.) {
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

    bool load(size_t pId, const std::vector<id4>& quadVertices) {
      patternId = pId;
      ncorners = 0;
      edges.reserve(2*quadVertices.size());
      quads.reserve(quadVertices.size());
      unordered_map<id2,id,id2hash> vpair2e;
      n = 0;
      for (size_t f = 0; f < quadVertices.size(); ++f) {
        id4 quad;
        for (size_t le = 0; le < 4; ++le) {
          id v1 = quadVertices[f][le];
          id v2 = quadVertices[f][(le+1)%4];
          n = std::max(n,v1+1);
          id2 oedge = {v1,v2};
          id2 vpair = sorted(v1,v2);
          auto it = vpair2e.find(vpair);
          id e = 0; 
          if (it == vpair2e.end()) {
            e = edges.size();
            edges.push_back(oedge);
            vpair2e[vpair] = e;
          } else {
            e = it->second;
          }
          quad[le] = e;
        }
        quads.push_back(quad);
        qvertices.push_back(quadVertices[f]);
      }
      v2e.resize(n);
      for (size_t e = 0; e < edges.size(); ++e) {
        v2e[edges[e][0]].push_back(e);
        v2e[edges[e][1]].push_back(e);
      }
      e2f.resize(edges.size());
      for (size_t f = 0; f < quads.size(); ++f) {
        for (size_t le = 0; le < 4; ++le) {
          e2f[quads[f][le]].push_back(f);
        }
      }
      vOnBdr.resize(n,false);
      for (size_t e = 0; e < e2f.size(); ++e) if (e2f[e].size() == 1) {
        vOnBdr[edges[e][0]] = true;
        vOnBdr[edges[e][1]] = true;
      }

      { /* Build chords of the quad mesh */
        chords.clear();
        eChordId.resize(edges.size(),NO_ID);
        vector<id> chordEdges;
        for (size_t e = 0; e < edges.size(); ++e) if (eChordId[e] == NO_ID) {
          chordEdges.clear();
          bool ok = build_quad_chord(quads, e2f, e, chordEdges);
          if (!ok) return false;
          for (id e: chordEdges) {
            eChordId[e] = chords.size();
          }
          chords.push_back(chordEdges);
        }
      }

      { /* Build the boundary sides (seperated by convex corners) */
        sides.clear();
        vector<id>* cur_side = NULL;
        for (id v0 = 0; v0 < n; ++v0) if (vOnBdr[v0] && v2e[v0].size() == 2) {
          id v = v0;
          id e = NO_ID;
          do {
            if (v2e[v].size() == 2) { /* concave corner */
              sides.resize(sides.size()+1);
              cur_side = &sides.back();
              ncorners += 1;
            }
            for (id ee: v2e[v]) if (ee != e && e2f[ee].size() == 1) {
              if (edges[ee][0] == v) { /* assume edges are ordered on bdr */
                e = ee; break;
              }
            }
            if (e == NO_ID) {
              Msg::Error("load, edge not found !");
              return false;
            }
            cur_side->push_back(e);
            id v2 = (edges[e][0] != v) ? edges[e][0] : edges[e][1];
            v = v2;
          } while (v != v0);
          break;
        }
        if (cur_side == NULL) { /* No convex corner, should be disk disk */
          sides.resize(sides.size()+1);
          cur_side = &sides.back();
          for (id v0 = 0; v0 < n; ++v0) if (vOnBdr[v0] && v2e[v0].size() == 3) {
            id v = v0;
            id e = NO_ID;
            do {
              for (id ee: v2e[v]) if (ee != e && e2f[ee].size() == 1) {
                if (edges[ee][0] == v) { /* assume edges are ordered on bdr */
                  e = ee; break;
                }
              }
              if (e == NO_ID) {
                Msg::Error("load, edge not found !");
                return false;
              }
              cur_side->push_back(e);
              id v2 = (edges[e][0] != v) ? edges[e][0] : edges[e][1];
              v = v2;
            } while (v != v0);
            break;
          }
        }
        if (cur_side == NULL) return false;
      }

      return true;
    }
  };

  double patternIrregularity(const QuadMeshPattern& M) {
    double irreg = 0.;
    for (size_t i = 0; i < M.n; ++i) if (!M.vOnBdr[i]) {
      irreg += std::pow(double(M.v2e[i].size())-4.,2);
    }
    return irreg;
  }

  double checkPatternMatching(const QuadMeshPattern& P, const std::vector<size_t>& sideSizes, vector<int>& slt) {
    slt.clear();
    size_t N = sideSizes.size();
    bool possible = true;
    for (size_t s = 0; s < N; ++s) {
      if (sideSizes[s] < P.sides[s].size() + 1) {
        /* on given side, less edges in the cavity than edges in the pattern */
        possible = false; break;
      }
    }
    if (!possible) return 0.;

    int nvars = 0;
    for (id v: P.eChordId) nvars = std::max(nvars,(int)v+1);
    IMatrix mat(N,nvars+1);
    for (size_t s = 0; s < N; ++s) {
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        id var = P.eChordId[e];
        mat.set(s,var,mat.get(s,var)+1);
      }
      mat.set(s,nvars,-1. * (sideSizes[s]-1));
    }
    mat.tansform_to_row_reduced_echelon();

    // TODO IDEA
    // - give ideal_repartition to the get_positive_solution_DFS() fct ?
    //   to control a bit the quantization
    // - other idea: use row echelon to compute null space [x_kernel, ...] and find
    //               solution x0 + lambda * x_kernel that maximize an objective 
    //               function ?
    vector<double> ideal_repartition;
    if (P.patternId == PATTERN_2CORNERS) {
      ideal_repartition.resize(P.chords.size(),0);
      size_t navg = (sideSizes[0] + sideSizes[1] - 2)/2;
      for (size_t j = 0; j < P.chords.size(); ++j) {
        if (P.chords[j].size() == 3) {
          ideal_repartition[j] = 0.95 * navg;
        } else if (P.chords[j].size() == 4) {
          ideal_repartition[j] = 0.05 * navg;
        } else {
          Msg::Error("setting ideal_repartition for PATTERN_2CORNERS, should not happen");
        }
      }
    } else if (P.patternId == PATTERN_DISK) {
      // TODO: detect circular chord and use a smaller ideal_repartition on it
    }
    double score = 0.;
    slt.clear();
    int count = 0;
    int count_limit = 100; /* limit on the number of solution tried in the DFS */
    int ncalls = 0;
    score = mat.get_positive_solution_DFS(slt, count, count_limit, ideal_repartition, ncalls);

    return score;
  }


  double checkPatternMatchingWithRotations(const QuadMeshPattern& P, const std::vector<size_t>& sideSizes, int& rotation) {
    size_t N = sideSizes.size();
    if (P.sides.size() != N) return 0.;

    vector<size_t> ssr = sideSizes;
    vector<int> slt;

    double best = 0.;
    int rot = 0;

    /* Initial config */
    {
      double match = checkPatternMatching(P, ssr, slt);
      if (match > best) {
        best = match;
        rotation = rot;
      }
    }

    /* Forward rotation */
    for (size_t r = 1; r < ssr.size(); ++r) {
      rot += 1;
      std::rotate(ssr.begin(),ssr.begin()+1,ssr.end());
      double match = checkPatternMatching(P, ssr, slt);
      if (match > best) {
        best = match;
        rotation = rot;
      }
    }

    /* Try in reverse order */
    rot = 0;
    ssr = sideSizes;
    std::reverse(ssr.begin(),ssr.end());
    for (size_t r = 1; r < ssr.size(); ++r) {
      rot -= 1;
      std::rotate(ssr.begin(),ssr.begin()+1,ssr.end());
      double match = checkPatternMatching(P, ssr, slt);
      if (match > best) {
        best = match;
        rotation = rot;
      }
    }


    return best;
  }

  std::vector<MVertex*> createVertices (GFace* gf, MVertex *v1, MVertex *v2, int n,
      std::vector<MVertex*>& newVertices){
    bool haveParam = gf->haveParametrization();
    std::vector<MVertex*> r;
    r.push_back(v1);
    double uv1[2] = {0.,0.};
    double uv2[2] = {0.,0.};
    if (haveParam) {
      setVertexGFaceUV(gf, v1, uv1);
      setVertexGFaceUV(gf, v2, uv2);
    }
    for (int i=1;i<n;i++){
      double xi = (double)i/n;
      SPoint3 p ((1.-xi)*v1->x()+xi*v2->x(),(1.-xi)*v1->y()+xi*v2->y(),(1.-xi)*v1->z()+xi*v2->z());
      double uv[2] = {0.,0.};
      if (haveParam) {
        uv[0] = (1.-xi)*uv1[0]+xi*uv2[0];
        uv[1] = (1.-xi)*uv1[1]+xi*uv2[1];
      }
      MVertex *vNew = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
      // TODO: CAD / triangulation projection here ?
      newVertices.push_back(vNew);
      r.push_back(vNew);
    }
    r.push_back(v2);
    return r;
  }

  std::vector<MVertex*> reverseVector (const std::vector<MVertex*> &v){
    std::vector<MVertex*> r;
    for (size_t i=0;i<v.size();i++)r.push_back(v[v.size() - 1 - i]);
    return r;
  }

  void createQuadPatch (GFace* gf,
      const std::vector<MVertex*> &s1,
      const std::vector<MVertex*> &s2,
      const std::vector<MVertex*> &s3,
      const std::vector<MVertex*> &s4,
      std::vector<MElement*>& newQuads,
      std::vector<MVertex*>& newVertices){

    bool haveParam = gf->haveParametrization();

    std::vector<MVertex*> s3r = reverseVector(s3);
    std::vector<MVertex*> s4r = reverseVector(s4);
    std::vector< std::vector<MVertex*> > grid(s1.size());
    for (size_t i = 0; i < grid.size(); ++i) grid[i].resize(s2.size(),NULL);
    grid.front() = s4r;
    grid.back() = s2;

    /* Fill the interior with transfinite interpolation */
    if (s1.size() > 2) {
      SVector3 c00 = s1[0]->point();
      SVector3 c10 = s2[0]->point();
      SVector3 c11 = s3[0]->point();
      SVector3 c01 = s4[0]->point();
      for (size_t i=1; i < s1.size()-1; i++){
        grid[i][0] = s1[i];
        grid[i].back() = s3r[i];

        if (s2.size() <= 2) continue;

        double u = double(i) / double(s1.size()-1.);
        SVector3 s1u = s1[i]->point();
        SVector3 s3u = s3r[i]->point();

        for (size_t j=1; j < s2.size()-1; j++){
          double v = double(j) / double(s2.size()-1.);
          SVector3 s2v = s2[j]->point();
          SVector3 s4v = s4r[j]->point();

          SVector3 p = (1.-v) * s1u + v * s3u + (1.-u) * s4v + u * s2v
            - ((1.-u)*(1.-v)*c00 + u*v*c11 + u * (1.-v) * c10 + (1.-u)*v*c01);
          double uv[2] = {0.,0.};
          MVertex *vNew = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
          newVertices.push_back(vNew);
          grid[i][j] = vNew;

          // TODO: projection on CAD / triangulation here ?
        }
      }
    }

    for (size_t i=0;i<grid.size()-1;i++){
      for (size_t j=0;j<grid[i].size()-1;j++){
        MQuadrangle *q = new MQuadrangle (grid[i][j],grid[i+1][j],grid[i+1][j+1],grid[i][j+1]);
        newQuads.push_back(q);
      }
    }    
  }


  bool addQuadsAccordingToPattern(
      const QuadMeshPattern& P,
      const std::vector<int>& quantization,
      GFace* gf, 
      const std::vector<std::vector<MVertex*> >& sides, /* vertices on the boundary, not changed */
      std::vector<MVertex*>& newVertices,               /* new vertices inside the cavity */
      std::vector<MElement*>& newElements,              /* new quads inside the cavity */
      MVertex* oldCenter = NULL                         /* initial guess for new positions */
      ) {
    constexpr bool DBG_VIZU = false;
    if (P.sides.size() != sides.size()) {
      Msg::Error("wrong input sizes ... pattern: %li sides, input: %li sides", P.sides.size(),sides.size());
      return false;
    }

    unordered_map<id2, std::vector<MVertex*>,id2hash> vpair2vertices;
    std::vector<MVertex*> v2mv(P.n,NULL);
    std::vector<MVertex*> vert;

    /* Associate exising vertices to pattern sides */
    SVector3 center(0.,0.,0.);
    if (oldCenter) {
      center = oldCenter->point();
    } else {
      double csum = 0.;
      for (size_t s = 0; s < sides.size(); ++s) {
        for (size_t k = 0; k < sides[s].size(); ++k) {
          center += sides[s][k]->point();
          csum += 1.;
        }
      }
      if (csum == 0.) return false;
      center = 1./csum * center;
    }

    for (size_t s = 0; s < P.sides.size(); ++s) {
      size_t pos = 0;
      size_t sp = 0;
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        sp += quantization[P.eChordId[P.sides[s][j]]];
      }
      if (sp + 1 != sides[s].size()) {
        return false;
      }
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        int n_e = quantization[P.eChordId[e]];
        vert.resize(n_e+1);
        for (size_t k = 0; k < (size_t) n_e+1; ++k) {
          if (pos+k>=sides[s].size()) {
            Msg::Error("issue, pos=%li + k=%li = %li >= sides[s].size()=%li", pos, k, pos+k, sides[s].size());
            return false;
          }
          vert[k] = sides[s][pos+k];
        }
        pos += n_e;
        id v1 = P.edges[e][0];
        id v2 = P.edges[e][1];
        if (v2mv[v1] == NULL) v2mv[v1] = vert.front();
        if (v2mv[v2] == NULL) v2mv[v2] = vert.back();

        id2 vpair = sorted(v1,v2);
        if (v1 < v2) {
          vpair2vertices[vpair] = vert;
        } else {
          std::reverse(vert.begin(),vert.end());
          vpair2vertices[vpair] = vert;
        }
      }
    }

    /* Create vertices on internal points */
    for (size_t v = 0; v < P.n; ++v) if (!P.vOnBdr[v]) {
      GPoint pp;
      if (oldCenter) {
        double uv[2];
        oldCenter->getParameter(0,uv[0]);
        oldCenter->getParameter(1,uv[1]);
        pp = GPoint(center.x(),center.y(),center.z(),gf,uv[0],uv[1]);
      } else {
        pp = GPoint(center.x(),center.y(),center.z(),gf,0,0);
      }

      bool moveTowardBdr = true;
      if (moveTowardBdr) {
        double vsum = 10.; /* weight on center */
        SVector3 avg(vsum*pp.x(),vsum*pp.y(),vsum*pp.z());
        for (size_t e: P.v2e[v]) {
          size_t v2 = (P.edges[e][0] != v) ? P.edges[e][0] : P.edges[e][1];
          if (P.vOnBdr[v2]) {
            SVector3 p2 = v2mv[v2]->point();
            avg += p2;
            vsum += 1;
          }
        }
        if (vsum > 1) {
          pp.x() = avg.x() / vsum;
          pp.y() = avg.y() / vsum;
          pp.z() = avg.z() / vsum;
        }
      }

      double uv[2] = {0.,0.};
      MVertex *sing = new MFaceVertex(pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
      GPoint proj = gf->closestPoint(sing->point(),uv);
      if (proj.succeeded()) {
        sing->x() = proj.x();
        sing->y() = proj.y();
        sing->z() = proj.z();
        sing->setParameter(0,proj.u());
        sing->setParameter(1,proj.v());
      }

      newVertices.push_back(sing);
      bool irregular = (P.v2e[v].size() != 4);
      v2mv[v] = sing;
    }

    /* Create vertices on internal curves */
    for (size_t e = 0; e < P.edges.size(); ++e) if (P.e2f[e].size() == 2) {
      id v1 = P.edges[e][0];
      id v2 = P.edges[e][1];
      MVertex* mv1 = v2mv[v1];
      MVertex* mv2 = v2mv[v2];
      if (mv1 == NULL || mv2 == NULL) {
        Msg::Error("MVertex* not found ?");
        return false;
      }
      int n_e = quantization[P.eChordId[e]];
      id2 vpair = sorted(v1,v2);
      if (v1 < v2) {
        vpair2vertices[vpair] = createVertices (gf, mv1, mv2, n_e, newVertices);
      } else {
        vpair2vertices[vpair] = createVertices (gf, mv2, mv1, n_e, newVertices);
      }
    }

    /* Create vertices inside the quad patches */
    for (size_t f = 0; f < P.quads.size(); ++f) {
      std::vector<std::vector<MVertex*> > quadCurves(4);
      for (size_t le = 0; le < 4; ++le) {
        id v0 = P.qvertices[f][le];
        id v1 = P.qvertices[f][(le+1)%4];
        id2 vpair = sorted(v0,v1);
        auto it = vpair2vertices.find(vpair);
        if (it == vpair2vertices.end()) {
          Msg::Error("MVertex* vector not found for vertex pair (edge in pattern)");
          return false;
        }
        quadCurves[le] = it->second;
        if (v1 < v0) {
          std::reverse(quadCurves[le].begin(),quadCurves[le].end());
        }
      }
      createQuadPatch(gf, quadCurves[0], quadCurves[1], quadCurves[2], quadCurves[3], newElements, newVertices);
    }

    return true;
  }

  void clearStuff(std::vector<MVertex*>& newVertices,
      std::vector<MElement*>& newElements) {
    for (MVertex*& v: newVertices) if (v != NULL) {
      delete v;
      v = NULL;
    }
    newVertices.clear();
    for (MElement*& e: newElements) if (e != NULL) {
      delete e;
      e = NULL;
    }
    newElements.clear();
  }

  template<class T> 
    void remove_element_if_inside(const T& value, std::vector<T>& vec) {
      auto it = std::find(vec.begin(),vec.end(),value);
      if (it != vec.end()) {
        vec.erase(it);
      }
    }

  struct QuadqsContext {
    bool optimizeTopology = true;
    bool optimizeGeometry = true;
    unordered_map<std::string,double> stats;
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
    SurfaceProjector* sp = nullptr;
    /* Stats on execution */
    double t0 = 0.;
    size_t nSingCavityRemesh = 0;
    size_t nQuadCavityRemesh = 0;
    bool finished = false;

    /* Functions */
    QuadqsGFaceContext(const QuadqsContext& qqs) {
      timeoutQuadqsPerGFace = qqs.timeoutQuadqsPerGFace;
      timeoutQuadqsPerGFaceCavity = qqs.timeoutQuadqsPerGFaceCavity;
      timeoutGeomOptimPerGFace = qqs.timeoutGeomOptimPerGFace;
      t0 = Cpu();
    }

    double elapsedCpuTime() const {
      return Cpu() - t0;
    }
  };


  /* Cavity oriented edge */
  using COEdge = std::array<MVertex*,2>;

  COEdge opposite(const COEdge& coe) {
    return {coe[1],coe[0]};
  }

  COEdge quadCOEdge(MQuadrangle* q, size_t le) {
    return {q->getVertex(le),q->getVertex((le+1)%4)};
  }

  struct COEdgeHash {
    size_t operator()(const COEdge &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(MVertex*)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(MVertex*)));
      return seed;
    }
  };


  struct Cavity {
    unordered_set<MQuadrangle*> elements; /* quads in the cavity */
    unordered_set<COEdge,COEdgeHash> boundary; /* oriented edges on the cavity boundary */
    unordered_map<MVertex*,uint8_t> valence; /* vertex quad-valence */

    void add(MQuadrangle* e) {
      elements.insert(e);
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* a = e->getVertex(lv);
        valence[a] += 1;
        MVertex* b = e->getVertex((lv+1)%4);
        COEdge edge{a,b};
        COEdge opp = opposite(edge);
        auto it = boundary.find(opp);
        if (it != boundary.end()) { 
          /* Opposite oriented edge already in the cavity, so it is no longer on the boundary */
          boundary.erase(it);
        } else {
          /* Edge not in the cavity, so new boundary */
          boundary.insert(edge);
        }
      }
    }

    void add(const std::vector<MQuadrangle*>& newElements) {
      for (MQuadrangle* e: newElements) add(e);
    }
  };

  void geolog_cavity(const Cavity& cav, std::string name) {
    std::vector<MElement*> elts;
    for (MElement* e: cav.elements) elts.push_back(e);
    GeoLog::add(elts, name);
    for (const COEdge& pe: cav.boundary) {
      GeoLog::add({pe[0]->point(),pe[1]->point()},vector<double>{0.,1.}, name);
    }
  }

  void getCavityValences(
      const Cavity& cav,
      unordered_map<MVertex*, size_t >& iqVal,
      unordered_map<MVertex*, size_t >& bqVal
      ) {
    iqVal.clear();
    bqVal.clear();

    unordered_set<MVertex*> bdr;
    bdr.reserve(cav.boundary.size());
    for (const COEdge& pe: cav.boundary) {
      bdr.insert(pe[0]);
    }

    for (MQuadrangle* q: cav.elements) {
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = q->getVertex(lv);
        if (bdr.find(v) != bdr.end()) { /* On bdr */
          bqVal[v] += 1;
        } else {
          iqVal[v] += 1;
        }
      }
    }
  }

  size_t numberOfQuadOutsideCavity(
      const std::vector<MQuadrangle*>& quads,
      const Cavity& cav,
      /* stop the count if strictly above threshold */
      size_t countThreshold,
      /* last quad outside, only used if number outside is one */
      MQuadrangle*& quadOutside 
      ) {
    size_t count = 0;
    for (MQuadrangle* q: quads) {
      auto it = cav.elements.find(q);
      if (it == cav.elements.end()) {
        count += 1;
        if (count > countThreshold) {
          return count;
        }
        quadOutside = q;
      }
    }
    return count;
  }

  size_t numberOfQuadInsideCavity(
      const std::vector<MQuadrangle*>& quads,
      const Cavity& cav,
      /* stop the count if strictly above threshold */
      size_t countThreshold,
      /* last quad inside, only used if number inside is one */
      MQuadrangle*& quadInside 
      ) {
    size_t count = 0;
    for (MQuadrangle* q: quads) {
      auto it = cav.elements.find(q);
      if (it != cav.elements.end()) {
        count += 1;
        if (count > countThreshold) {
          return count;
        }
        quadInside = q;
      }
    }
    return count;
  }

  bool isValidConvexCavity(Cavity& cav, const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj) {
    /* Check convex and that there is no concave CAD corner absorbed by the cavity */
    /* Collect cavity boundary vertices */
    std::vector<MVertex*> bdr;
    bdr.reserve(cav.boundary.size());
    for (COEdge& pe: cav.boundary) {
      bdr.push_back(pe[0]);
    }
    for (MVertex* v: bdr) {
      auto it = adj.find(v);
      if (it == adj.end()) {
        Msg::Error("is valid cavity: no quads found around vertex %i, should NEVER happen", v->getNum());
        return false;
      }
      GFace* gf = dynamic_cast<GFace*>(v->onWhat());

      constexpr size_t countThreshold1 = 1;
      MQuadrangle* quadOutside = nullptr;
      if (gf && numberOfQuadOutsideCavity(it->second, cav, countThreshold1, quadOutside) == 1) {
        /* Concave cavity corner, inside the surface mesh */
        return false;
      } else if (gf == nullptr) {
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        constexpr size_t countThreshold2 = 3;
        if (gv && numberOfQuadOutsideCavity(it->second, cav, countThreshold2, quadOutside) >= 3) {
          /* CAD corner, valence is superior or equal to three, should not be absorbed in cavity */
          return false;
        }
      }
    }

    return true;
  }

  bool convexify(Cavity& cav, const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj)  {
    bool running = true;
    unordered_set<MVertex*> alreadyChecked;
    while (running) {
      running = false;
      /* Collect all vertices inside GFace and on cavity boundary */
      std::vector<MVertex*> bdr;
      bdr.reserve(cav.boundary.size());
      for (COEdge& pe: cav.boundary) {
        MVertex* v = pe[0];
        GFace* gf = dynamic_cast<GFace*>(v->onWhat());
        if (gf == nullptr) continue;
        bdr.push_back(v);
      }
      sort_unique(bdr);
      for (size_t i = 0; i < bdr.size(); ++i) {
        MVertex* v = bdr[i];
        auto it = adj.find(v);
        if (it == adj.end()) {
          Msg::Error("convexify: no quads found around vertex %i, should NEVER happen", v->getNum());
          return false;
        }
        MQuadrangle* quadOutside = nullptr;
        constexpr size_t countThreshold = 1;
        if (numberOfQuadOutsideCavity(it->second, cav, countThreshold, quadOutside) == 1) {
          cav.add(quadOutside);
          running = true;
        }
      }
    }
    return isValidConvexCavity(cav, adj);
  }

  bool getCavitySides(
      Cavity& cav,
      size_t& Ncorners,
      std::vector<std::vector<MVertex*> >& sides
      )  {
    /* note: repetition of MVertex if only one side (periodic) */
    Ncorners = 0;
    sides.clear();

    /* Convert boundary into continuous integers
     * after indirection, the i-th vertex is the first of the i-th COEdge */
    unordered_map<MVertex*,uint32_t> old2new;
    old2new.reserve(cav.boundary.size());
    vector<MVertex*> new2old(cav.boundary.size());
    uint32_t count = 0;
    for (const COEdge& pe: cav.boundary) {
      MVertex* v = pe[0];
      auto it = old2new.find(v);
      if (it != old2new.end()) {
        Msg::Debug("getCavitySides: non manifold cavity boundary or incoherent bdr edge orientation");
        return false;
      }
      old2new[v] = count;
      new2old[count] = v;
      count += 1;
    }
    std::vector<uint32_t> edgeSecondVertex(cav.boundary.size());
    count = 0;
    for (const COEdge& pe: cav.boundary) {
      MVertex* v = pe[1];
      auto it = old2new.find(v);
      if (it == old2new.end()) {
        Msg::Debug("getCavitySides: non manifold cavity boundary or incoherent bdr edge orientation");
        return false;
      }
      edgeSecondVertex[count] = it->second;
      count += 1;
    }

    /* Extract convex corners */
    constexpr uint32_t NO_UINT32 = (uint32_t) -1;
    uint32_t v0 = NO_UINT32; /* first vertex, corner is there is one */
    vector<bool> isCorner(new2old.size(),false);
    Ncorners = 0;
    {
      vector<uint32_t> bdrQValence(new2old.size(),0);
      for (MQuadrangle* q: cav.elements) {
        for (uint32_t lv = 0; lv < 4; ++lv) {
          MVertex* v = q->getVertex(lv);
          auto it = old2new.find(v);
          if (it != old2new.end()) {
            bdrQValence[it->second] += 1;
          }
        }
      }
      for (uint32_t i = 0; i < bdrQValence.size(); ++i) if (bdrQValence[i] == 1) {
        isCorner[i] = true;
        Ncorners += 1;
        if (v0 == NO_UINT32 || new2old[i]->getNum() < new2old[v0]->getNum()) {
          v0 = i;
        }
      }
      /* If no convex corner, takes an arbitrary vertex on the boundary.
       * Take the one with the minimum getNum() for reproductibility */
      if (v0 == NO_UINT32) {
        v0 = 0;
      }
    }
    uint32_t e0 = v0;

    if (Ncorners == 0) { 
      /* Patch is a disk, start at arbitrary vertex */
      sides.resize(1);
      sides[0].push_back(new2old[v0]);
    }

    /* Propagation along the boundary */
    unordered_set<MVertex*> cornerVisited;
    uint32_t nCornerVisited = 0;
    uint32_t v = v0;
    uint32_t e = e0;
    uint32_t iter = 0;
    while (true) {
      iter += 1;
      if (iter > 1e7) {
        Msg::Error("getCavitySides: infinite loop ? iter = {}", iter);
        return false;
      }

      if (isCorner[v]) {
        nCornerVisited += 1;
        sides.resize(sides.size()+1);
        sides.back().push_back(new2old[v]);
      }

      uint32_t v2 = edgeSecondVertex[e];
      uint32_t e2 = v2;

      sides.back().push_back(new2old[v2]);
      v = v2;
      e = e2;

      if (v2 == v0) { /* closed the loop */
        break;
      }
    }

    if (nCornerVisited != Ncorners) {
      Msg::Debug("getCavitySides: not all corners were visited, bdr has multiple loops ?");
      return false;
    }

    return true;
  }

  double cavityIrregularity(const Cavity& cav) {
    unordered_set<MVertex*> onBdr;
    for (const COEdge& pe: cav.boundary) {
      onBdr.insert(pe[0]);
    };
    double irreg = 0.;
    for (const auto& kv : cav.valence) {
      MVertex* v = kv.first;
      if (onBdr.find(v) != onBdr.end()) continue;
      irreg += std::pow(kv.second-4.,2);
    }
    return irreg;
  }


  enum GrowthPolicy {
    GROW_MINIMAL,
    GROW_MAXIMAL,
  };

  std::vector<MQuadrangle*> vector_from_set(const unordered_set<MQuadrangle*> input) {
    std::vector<MQuadrangle*> output(input.size());
    size_t i = 0;
    for (MQuadrangle* q: input) {
      output[i] = q;
      i += 1;
    }
    return output;
  }

  /* TODO note
   * This function is slow, mainly because of getCavitySides
   * Try to reduce the cavity to a condensed structure here ? 
   * Or try to use the position in gf->quadrangles as quad identifier ? 
   * + vector<bool> for inside/outside
   * same for vertices ? but somes on curves/corners */
  bool growCavityStep(
      Cavity& cav,
      const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj,
      const unordered_set<MVertex*>& allowedIrregularVertices,
      const unordered_set<MVertex*>& forbiddenIrregularVertices,
      /* number of irregular vertices which are not inside allowedIrregularVertices */
      size_t& nIrreg 
      ) {
    std::vector<std::vector<MVertex*> > sides;
    size_t Ncorners = 0;
    bool oks = getCavitySides(cav, Ncorners, sides);
    if (!oks) {
      if (DBG_VERBOSE) {Msg::Debug("cavity grow one side: %li quads, failed to build cavity boundary",
          cav.elements.size());}
      return false;
    }

    // For isotropic growth, we choose try the largest sides first,
    // and we add the getNum of the first vertex for reproductibility. */
    vector<std::pair<size_t,size_t> > sizeAndSide(sides.size());
    for (size_t i = 0; i < sides.size(); ++i) {
      sizeAndSide[i] = {size_t(1e7*sides[i].size()+sides[i].front()->getNum()),i};
    }
    std::sort(sizeAndSide.begin(),sizeAndSide.end());
    std::reverse(sizeAndSide.begin(),sizeAndSide.end());

    for (size_t k = 0; k < sizeAndSide.size(); ++k) {
      size_t i = sizeAndSide[k].second;
      if (sides[i].size() <= 2) continue;
      bool candidate = true;
      for (size_t j = 1; j < sides[i].size()-1; ++j) {
        MVertex* v = sides[i][j];
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        // GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
        // if (gv != nullptr || ge != nullptr) { /* side touching face boundary */
        //   candidate = false;
        //   break;
        // }
        if (gv != nullptr) { /* side touching CAD corner */
          candidate = false;
          break;
        }
        bool forbidden = (forbiddenIrregularVertices.find(v) != forbiddenIrregularVertices.end());
        if (forbidden) {
          candidate = false;
          break;
        }
      }
      if (candidate) {
        /* Build the new convex cavity by expanding on the side
         * and check if it is a valid */
        Cavity cav2 = cav;

        /* Add the new quads */
        size_t nAdded = 0;
        std::vector<MQuadrangle*> cQuads;
        cQuads.reserve(4*sides[i].size());
        for (size_t j = 1; j < sides[i].size()-1; ++j) {
          MVertex* v = sides[i][j];
          auto it = adj.find(v);
          if (it == adj.end()) continue;
          append(cQuads, it->second);
        }
        sort_unique(cQuads);
        for (MQuadrangle* q2: cQuads) {
          auto it2 = cav2.elements.find(q2);
          if (it2 == cav2.elements.end()) {
            cav2.add(q2);
            nAdded += 1;
          }
        }
        if (nAdded == 0) continue; /* try next side */

        /* Convexify the cavity */
        bool okc = convexify(cav2, adj);
        if (!okc) continue; /* try next side */

        /* Vertices and valences, check allowed/forbidden sings */
        bool containsForbiddenSingularities = false;
        nIrreg = 0;
        for (const auto& kv: cav2.valence) if (kv.second != 4 && kv.second >= 3) {
          MVertex* v = kv.first;
          auto it = allowedIrregularVertices.find(v);
          if (it != allowedIrregularVertices.end()) continue;
          auto it2 = forbiddenIrregularVertices.find(v);
          if (it2 != forbiddenIrregularVertices.end()) {
            containsForbiddenSingularities = true;
            break;
          }
          nIrreg += 1;
        }
        if (containsForbiddenSingularities) continue; /* try next side */ 

        /* Extended cavity is good, keep it */
        cav = cav2;
        return true;
      }
    }

    return false;
  }

  bool growCavity(
      GrowthPolicy policy,
      const std::vector<size_t>& patternsToCheck,
      const unordered_map<size_t,size_t>& patternSizeLimits,
      const std::vector<MQuadrangle*>& quadsInit,
      const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj,
      const unordered_set<MVertex*>& allowedIrregularVertices,
      const unordered_set<MVertex*>& forbiddenIrregularVertices,
      Cavity& cavity,/* if found, last remeshable cavity */
      std::vector<std::vector<MVertex*> >& cavitySides,
      std::pair<size_t,int>& patternNoAndRot
      ){

    size_t iter = 0;
    Cavity cav;
    cav.add(quadsInit);
    bool okc = convexify(cav, adj);
    if (!okc) {
      if (DBG_VERBOSE) {Msg::Debug("------ grow cavity: iter %li, failed to convexify %li quads",
          iter, cav.elements.size());}
      return false;
    }

    size_t lastNbIrregular = 0; // # irregular vertices outside allowed ones

    bool running = true;
    while (running) {
      iter += 1;

      /* Grow the cavity on one of its sides */
      size_t nIrreg = 0;
      bool okg = growCavityStep(cav, adj, allowedIrregularVertices, forbiddenIrregularVertices, nIrreg);
      if (!okg) {
        if (DBG_VERBOSE) {Msg::Debug("------ grow cavity: iter %li, %li quads, failed to grow cavity",
            iter, cav.elements.size());}
        break;
      }

      /* If no new irregular vertices, continue the growth */
      if (nIrreg <= lastNbIrregular) continue;

      /* Check if the cavity is topologicaly remeshable with patterns */
      double bestIrreg = DBL_MAX;
      for (size_t pId: patternsToCheck) {
        /* Check pattern size limit if any */
        auto it = patternSizeLimits.find(pId);
        if (it != patternSizeLimits.end() && cav.elements.size() > it->second)
          continue;

        /* Check if remeshable */
        std::vector<std::vector<MVertex*> > sides;
        size_t Ncorners = 0;
        bool oks = getCavitySides(cav, Ncorners, sides);
        if (!oks) {
          if (DBG_VERBOSE) {Msg::Debug("------ grow cavity: iter %li, %li quads, failed to build cavity boundary",
              iter, cav.elements.size());}
          break;
        }

        /* Number of vertices on each side, including extremities */
        std::vector<size_t> sideSizes(sides.size());
        for (size_t i = 0; i < sideSizes.size(); ++i) sideSizes[i] = sides[i].size();
        double irregMeasure;
        std::pair<size_t,int> par;
        bool meshable = patchIsRemeshableWithQuadPattern(patternsToCheck, Ncorners, sideSizes, par, irregMeasure);
        if (meshable && irregMeasure < bestIrreg && irregMeasure < cavityIrregularity(cav)) {
          /* set last remeshable cavity */
          bestIrreg = irregMeasure;
          lastNbIrregular = nIrreg;
          cavity = cav;
          cavitySides = sides;
          patternNoAndRot = par;
          if (DBG_VERBOSE) {Msg::Debug("------ grow cavity: iter %li, %li quads, set last remeshable cavity (#irreg = %li)",
              iter, cav.elements.size(), nIrreg);}
        }
      }
      if (policy == GROW_MINIMAL && bestIrreg != DBL_MAX) {
        /* Found a remeshable cavity, return */
        return true;
      }
    }

    return (lastNbIrregular > 0);
  }

  bool remeshCavity(GFace* gf, 
      Cavity& cav,
      std::vector<std::vector<MVertex*> >& sides,
      std::pair<size_t,int> patternNoAndRot,
      bool invertNormalsForQuality,
      unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj, /* invalid after remeshing ! */
      QuadqsGFaceContext& ctx
      ) {

    /* Collect current patch components */
    std::vector<MElement*> elements(cav.elements.size());
    std::vector<MVertex*> intVertices(4*cav.elements.size());
    size_t i = 0;
    for (MQuadrangle* q: cav.elements) {
      elements[i] = q;
      for (size_t lv = 0; lv < 4; ++lv) {
        intVertices[4*i+lv] = q->getVertex(lv);
      }
      i += 1;
    }
    std::vector<MVertex*> bdr(cav.boundary.size());
    i = 0;
    for (const COEdge& pe: cav.boundary) {
      bdr[i] = pe[0];
      i += 1;
    }
    intVertices = difference(intVertices, bdr);

    bool SHOW_REMESH_CAV = false;
    static size_t ccount = 0;
    if (SHOW_REMESH_CAV) {
      ccount += 1;
      std::string name = "cav" + std::to_string(ccount);
      GeoLog::add(elements,name+"_try");
    }

    /* Call the remeshing code */
    const double minSICNafer = 0.1;
    GFaceMeshDiff diff;
    int st = remeshPatchWithQuadPattern(gf, patternNoAndRot, sides, elements, 
        intVertices, minSICNafer, invertNormalsForQuality, ctx.sp, diff);
    if (st != 0) {
      if (DBG_VERBOSE) {Msg::Debug("remesh cavity: %li quads, failed to remesh path with quad pattern",
          cav.elements.size());}
      return false;
    }

    /* Check the geometry quality before / after*/
    double sicnMin, sicnAvg;
    computeSICN(diff.before.elements, sicnMin, sicnAvg);
    double sicnMinAfter, sicnAvgAfter;
    computeSICN(diff.after.elements, sicnMinAfter, sicnAvgAfter);
    if ((sicnMin > 0.3 && sicnAvg > 0.5) || sicnMinAfter > sicnMin) {
      constexpr bool verifyTopology = true;
      size_t neb = diff.before.elements.size();
      size_t nea = diff.after.elements.size();
      size_t nvb = diff.before.intVertices.size();
      size_t nva = diff.after.intVertices.size();

      if (SHOW_REMESH_CAV) {
        std::string name = "cav" + std::to_string(ccount);
        GeoLog::add(diff.after.elements,name+"_OK");
      }

      /* To smooth the interface between remeshed cavity and rest of the mesh,
       * we collect the boundary (interior to the mesh) and its adjacent quads */
      vector<MVertex*> toSmooth;
      vector<MElement*> neighbors;
      {
        /* Cavity boundary vertices, inside the surface, not changed by diff.execute() */
        toSmooth.reserve(diff.after.bdrVertices.front().size());
        for (MVertex* v: diff.after.bdrVertices.front()) {
          GFace* gf = dynamic_cast<GFace*>(v->onWhat());
          if (gf != nullptr) toSmooth.push_back(v);
        }

        /* Quads adjacent to interior bdr but exterior to cavity, not changed by diff.execute() */
        neighbors.reserve(2*toSmooth.size());
        for (MVertex* v: toSmooth) {
          auto it = adj.find(v);
          if (it != adj.end())  {
            for (MElement* e: it->second) {
              neighbors.push_back(e);
            }
          }
        }
        neighbors = difference(neighbors, diff.before.elements);

        /* New quads inside cavity, touching boundary, still present after execute() */
        for (MElement* e: diff.after.elements) for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v = e->getVertex(lv);
          auto it = std::find(toSmooth.begin(),toSmooth.end(),v);
          if (it != toSmooth.end()) {
            neighbors.push_back(e);
            break;
          }
        }
        sort_unique(neighbors);
      }

      /* Modify the GFace mesh ! (and empty the diff content) */
      bool oke = diff.execute(verifyTopology);
      if (!oke) {
        Msg::Error("remesh cavity: diff execute() failed, should not happen");
        return false;
      }

      Msg::Debug("----V remeshed a cavity, %li -> %li quads, %li -> %li int. vertices, SICN min: %.3f -> %.3f",
          neb, nea, nvb, nva, sicnMin, sicnMinAfter);

      /* Boundary vertex smoothing, to get a smooth transition with the
       * rest of the mesh after cavity remeshing */
      {
        GFaceMeshPatch patchBdr;
        bool okp = patchFromElements(gf, neighbors, patchBdr);
        if (okp) {
          Msg::Debug("----P smooth cavity boundary (%li vertices, %li quads)",
              patchBdr.intVertices.size(),patchBdr.elements.size());
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

      adj.clear(); /* was not longer valid after execute() */
      return true;
    } else {
      Msg::Debug("----X reject cavity new geometry, SICN min: %.3f -> %.3f, avg: %.3f -> %.3f",
          sicnMin, sicnMinAfter, sicnAvg, sicnAvgAfter);
      if (SHOW_REMESH_CAV) {
        std::string name = "cav" + std::to_string(ccount);
        GeoLog::add(diff.after.elements,name+"_REJQ");
      }
    }

    return false;
  }

  bool quadMeshIsMinimal(GFace* gf,
      const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj,
      const std::vector<std::pair<SPoint3,int> >& singularities) {

    size_t nIrregInt = 0;
    size_t nIrregBdr = 0;
    for (auto& kv: adj) {
      MVertex* v = kv.first;
      size_t val = kv.second.size();
      if (v->onWhat()->cast2Face() != nullptr && val != 4) {
        nIrregInt += 1;
      } else if (v->onWhat()->cast2Edge() != nullptr && val != 2) {
        nIrregBdr += 1;
      }
    }

    if (nIrregBdr == 0 && nIrregInt == singularities.size()) return true;

    return false;
  }

  void assignSingularitiesToIrregularVertices(
      GFace* gf,
      const unordered_map<MVertex*,std::vector<MQuadrangle*> > & adj,
      const std::vector<std::pair<SPoint3,int> >& singularities,
      std::vector<MVertex*>& irregularVertices) {
    irregularVertices.clear();

    /* Extract irregular vertices in face */
    vector<MVertex*> nodeVal3;
    vector<MVertex*> nodeVal5;
    for (const auto& kv: adj) {
      MVertex* v = kv.first;
      if (v->onWhat() != gf) continue;
      if (kv.second.size() != 4) {
        if (kv.second.size() == 3) {
          nodeVal3.push_back(kv.first);
        } else if (kv.second.size() == 5) {
          nodeVal5.push_back(kv.first);
        }
      }
    }

    /* Assign singular vertices */
    for (size_t i = 0; i < singularities.size(); ++i) {
      int index = singularities[i].second;
      vector<MVertex*>* verticesp;
      if (index == 1) {
        verticesp = &nodeVal3;
      } else if (index == -1) {
        verticesp = &nodeVal5;
      } else {
        Msg::Warning("cavity remeshing: face %i, singularity of index %i not supported", gf->tag(),index);
        continue;
      }
      SPoint3 p = singularities[i].first;
      vector<MVertex*>& vertices = *verticesp;
      double dmin = DBL_MAX;
      MVertex* best = nullptr;
      for (size_t j = 0; j < vertices.size(); ++j) {
        SVector3 p2 = vertices[j]->point();
        double dist = vertices[j]->point().distance(p);
        if (dist < dmin) {
          dmin = dist;
          best = vertices[j];
        }
      }
      if (best != nullptr) {
        irregularVertices.push_back(best);
      } else {
        Msg::Warning("- Face %i, singular node %i, failed to assign to irregular vertex", gf->tag(), i);
      }
    }
  }

  bool remeshQuadrilateralCavities(GFace* gf, 
      const std::vector<std::pair<SPoint3,int> >& singularities,
      const std::vector<size_t>& patternsToCheck,
      const unordered_map<size_t,size_t>& patternSizeLimits,
      unordered_map<MVertex*,size_t>& seedNbTries,
      QuadqsGFaceContext& ctx) 
  {
    if (ctx.finished) return true;

    Msg::Debug("-- remeshing quadrilateral cavities (%i quads, %i patterns to check) ...", 
        gf->quadrangles.size(), patternsToCheck.size());
    unordered_map<MVertex*, vector<MQuadrangle*> > v2q;
    unordered_set<MVertex*> allowedIrregularVertices;
    unordered_set<MVertex*> forbiddenIrregularVertices;
    std::vector<MVertex*> singularVertices; /* to be preserved */
    std::vector<SPoint3> repulsion; /* to distribute the cavities, add repulsion after remeshing */

    size_t nbCavityRemeshed = 0;

    /* for PASS_ALONG_GEDGES
     * The queue contains the curves which are not loop */
    std::queue<GEdge*> gedges;
    for (GEdge* ge: gf->edges()) {
      /* Ignore periodic curves */
      if (ge->vertices().size() != 2) continue;
      if (ge->vertices().front() == ge->vertices().back()) continue;
      gedges.push(ge);
    }

    /* for PASS_FROM_CORNERS
     * The queue contains the CAD corners which are not concave */
    std::queue<GVertex*> gcorners;
    for (GVertex* gv: gf->vertices()) {
      gcorners.push(gv);
    }

    /* for PASS_FROM_IRREGULAR
     * The priority queue contains the irregular vertices not associated 
     * to cross field singularity and a priority based on repulsion.
     * Higher values appear first when doing Q.top() */
    std::priority_queue<std::pair<double,MVertex*>,  std::vector<std::pair<double,MVertex*> > > Qirreg; 

    const size_t PASS_FROM_CORNERS = 1;
    const size_t PASS_ALONG_GEDGES = 2;
    const size_t PASS_FROM_IRREGULAR = 3;
    for (size_t pass : {PASS_FROM_CORNERS, PASS_ALONG_GEDGES, PASS_FROM_IRREGULAR}) {
      bool updateRequired = true;
      bool inProgress = true;
      while (inProgress 
          || (pass == PASS_FROM_CORNERS && gcorners.size() > 0)
          || (pass == PASS_ALONG_GEDGES && gedges.size() > 0)
          || (pass == PASS_FROM_IRREGULAR && Qirreg.size() > 0)) {
        inProgress = false;

        if (updateRequired) {
          /* Update adjacencies */
          v2q.clear();
          for (MQuadrangle* q: gf->quadrangles) for (size_t lv = 0; lv < 4; ++lv) {
            MVertex* v = q->getVertex(lv);
            vector<MQuadrangle*>& quads = v2q[v];
            size_t nl = quads.size();
            if (nl == 0) quads.reserve(5);
            quads.push_back(q);
          }

          if (quadMeshIsMinimal(gf, v2q, singularities)) {
            ctx.finished = true;
            break;
          }

          /* Get vertices to preserve from cross field singularities */
          assignSingularitiesToIrregularVertices(gf, v2q, singularities, singularVertices);

          forbiddenIrregularVertices.clear();
          for (MVertex* v: singularVertices) forbiddenIrregularVertices.insert(v);

          if (pass == PASS_FROM_IRREGULAR) {
            /* Update the queue */
            while (!Qirreg.empty()) { /* empty the queue */
              Qirreg.pop();
            }
            for (auto& kv: v2q) if (kv.second.size() != 4) {
              MVertex* v = kv.first;
              if (v->onWhat() != gf) continue;
              if (forbiddenIrregularVertices.find(v) != forbiddenIrregularVertices.end()) continue;

              SPoint3 pt = v->point();
              double prio = 0.;
              for (const SPoint3& r: repulsion) {
                prio += pt.distance(r);
              }
              /* deterministic offset for reproductibility */
              double offsetR = 1.e-16*double(v->getNum());
              Qirreg.push({prio+offsetR,v});
            }
          }

          updateRequired = false;
        }

        /* Initialize a remeshing cavity */
        std::vector<MQuadrangle*> quadsInit;
        GrowthPolicy policy;
        SPoint3 pos; /* only used with PASS_FROM_IRREGULAR */
        MVertex* vIrreg = nullptr; /* only used with PASS_FROM_IRREGULAR */
        if (pass == PASS_FROM_CORNERS) {
          if (gcorners.empty()) continue;
          policy = GROW_MAXIMAL;
          allowedIrregularVertices.clear();
          GVertex* gv = gcorners.front();
          gcorners.pop();
          for (MVertex* v: gv->mesh_vertices) {
            auto it = v2q.find(v);
            if (it == v2q.end()) continue;
            append(quadsInit,it->second);
          }
          sort_unique(quadsInit);
          if (quadsInit.size() >= 3) continue; /* do not start from concave corners */
          Msg::Debug("---< start cavity with %i quads adjacent to corner %i", quadsInit.size(), gv->tag());
        } else if (pass == PASS_ALONG_GEDGES) {
          if (gedges.empty()) continue;
          policy = GROW_MAXIMAL;
          allowedIrregularVertices.clear();
          /* Get adjacent to a GEdge not yet processed */
          GEdge* ge = gedges.front();
          gedges.pop();
          for (MVertex* v: ge->mesh_vertices) {
            auto it = v2q.find(v);
            if (it == v2q.end()) continue;
            append(quadsInit,it->second);
          }
          sort_unique(quadsInit);
          Msg::Debug("---< start cavity with %i quads adjacent to curve %i", quadsInit.size(), ge->tag());
        } else if (pass == PASS_FROM_IRREGULAR) {
          if (Qirreg.empty()) continue;
          policy = GROW_MINIMAL;
          vIrreg = Qirreg.top().second;
          Qirreg.pop();
          auto it = v2q.find(vIrreg);
          if (it == v2q.end()) {
            Msg::Error("remesh quad cavity: vertex not found in adjacency map, should NEVER happen");
            return false;
          }

          /* Check cavities have already been tried from this
           * mesh vertex */
          size_t nPreviousTry = 0;
          auto itt = seedNbTries.find(vIrreg);
          if (itt != seedNbTries.end()) nPreviousTry = itt->second;
          if (nPreviousTry >= ctx.nTryMaxPerVertex) continue;

          quadsInit = it->second;
          pos = vIrreg->point();
          Msg::Debug("---< start cavity with %i quads adjacent to irreg. vertex %i", quadsInit.size(), vIrreg->getNum());
        }
        if (quadsInit.size() == 0) continue;

        /* Grow a convex cavity containg irregular vertices to remove */
        Cavity cav;
        std::pair<size_t,int> patternNoAndRot;
        std::vector<std::vector<MVertex*> > sides;
        bool okg = growCavity(policy, patternsToCheck, patternSizeLimits, quadsInit,
            v2q, allowedIrregularVertices, forbiddenIrregularVertices, cav, sides, patternNoAndRot);
        if (!okg) {
          if (vIrreg != nullptr) seedNbTries[vIrreg] += 1;
          continue;
        }

        Msg::Debug("---- found a topological cavity with %i quads, try geometrical remeshing", cav.elements.size());

        bool okr = remeshCavity(gf, cav, sides, patternNoAndRot, ctx.invertNormalsForQuality, v2q, ctx);
        if (okr) {
          /* GFace mesh has changed, need to update adjacency info (v2q is no longer usable) */
          updateRequired = true;
          inProgress = true;
          nbCavityRemeshed += 1;
          if (pass == PASS_FROM_IRREGULAR && vIrreg != nullptr) {
            repulsion.push_back(pos);

            /* Unlock close other irregular vertices that may be have unlocked */
            std::vector<std::pair<double,MVertex*> > others;
            others.reserve(seedNbTries.size());
            for (const auto& kv: seedNbTries) {
              MVertex* v2 = kv.first;
              if (v2 == vIrreg) continue;
              auto it = v2q.find(v2);
              if (it != v2q.end()) { /* check if vertex still in the mesh */
                others.push_back({pos.distance(v2->point()),v2});
              }
            }
            std::sort(others.begin(),others.end());
            for (size_t j = 0; j < std::min(others.size(),size_t(ctx.nTryCloseReset)); ++j) {
              MVertex* v2 = others[j].second;
              auto itc = seedNbTries.find(v2);
              if (itc != seedNbTries.end()) {
                itc->second = 0; /* reset the counter to 0 */
              }
            }
          }
        } else {
          if (vIrreg != nullptr) seedNbTries[vIrreg] += 1;
        }
      }

      if (ctx.finished) break;
    }

    Msg::Debug("-- remeshed %i quadrilateral cavities", nbCavityRemeshed);

    ctx.nQuadCavityRemesh += nbCavityRemeshed;

    if (false && nbCavityRemeshed > 0) {
      // Msg::Debug("-- surface mesh smoothing");
      // GeomOptimStats stats;
      // std::vector<MElement*> elements = dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles);
      // quadMeshOptimizeDMOKernelGreedy(gf, elements, gf->mesh_vertices,
      //     0.5, 0.7, 50, 10., ctx.invertNormalsForQuality, stats);
      // if (stats.sicnMinAfter < 0.) {
      //   Msg::Error("Negative quality after cavity remeshing ! SICN min: %.3f", stats.sicnMinAfter);
      // }
    }

    // TODO: smoothing the pool ?

    return true;
  }

  bool remeshSingularityCavities(GFace* gf, 
      const std::vector<std::pair<SPoint3,int> >& singularities,
      const std::vector<size_t>& patternsToCheck,
      const unordered_map<size_t,size_t>& patternSizeLimits,
      unordered_map<MVertex*,size_t>& seedNbTries,
      QuadqsGFaceContext& ctx) 
  {
    if (ctx.finished) return true;

    Msg::Debug("-- remeshing singularity cavities (face %i, %i quads, %i patterns to check) ...", 
        gf->tag(), gf->quadrangles.size(), patternsToCheck.size());
    unordered_map<MVertex*, vector<MQuadrangle*> > v2q;
    unordered_set<MVertex*> allowedIrregularVertices;
    unordered_set<MVertex*> forbiddenIrregularVertices;
    std::vector<MVertex*> singularVertices; /* to preserve */
    std::vector<SPoint3> repulsion; /* to distribute the cavities, add repulsion after remeshing */

    size_t nbCavityRemeshed = 0;

    /* The priority queue contains the irregular vertices associated to 
     * cross field singularity and a priority based on repulsion.
     * Higher values appear first when doing Q.top() */
    std::priority_queue<std::pair<double,MVertex*>,  std::vector<std::pair<double,MVertex*> > > Q; 

    bool updateRequired = true;
    bool inProgress = true;
    while (inProgress || Q.size() > 0) {
      inProgress = false;

      if (updateRequired) {
        /* Update adjacencies */
        v2q.clear();
        for (MQuadrangle* q: gf->quadrangles) for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v = q->getVertex(lv);
          vector<MQuadrangle*>& quads = v2q[v];
          size_t nl = quads.size();
          if (nl == 0) quads.reserve(5);
          quads.push_back(q);
        }

        if (quadMeshIsMinimal(gf, v2q, singularities)) {
          ctx.finished = true;
          break;
        }

        bool PARANO_ORIENTATION = false;
        if (PARANO_ORIENTATION) {
          bool ok = true;
          for (auto& kv: v2q) {
            MVertex* v = kv.first;
            SVector3 ref = kv.second.front()->getFace(0).normal();
            for (MQuadrangle* q: kv.second) {
              SVector3 nn = q->getFace(0).normal();
              if (dot(nn,ref) < 0) {
                DBG(v->getNum(),nn,ref,dot(nn,ref));
                ok = false;
              }
            }
          }
          if (!ok) {
            DBG("BAD BAD NORMALS NOT COHERENT");
            gmsh::fltk::run();
            abort();
          }
        }

        /* Get vertices to preserve from cross field singularities */
        assignSingularitiesToIrregularVertices(gf, v2q, singularities, singularVertices);
        forbiddenIrregularVertices.clear();
        for (MVertex* v: singularVertices) forbiddenIrregularVertices.insert(v);

        /* Update the queue */
        while (!Q.empty()) { /* empty the queue */
          Q.pop();
        }
        for (MVertex* v: singularVertices) {
          SPoint3 pt = v->point();
          double prio = 0.;
          for (const SPoint3& r: repulsion) {
            prio += pt.distance(r);
          }
          /* deterministic offset for reproductibility */
          double offsetR = 1.e-16*double(v->getNum());
          Q.push({prio+offsetR,v});
        }

        updateRequired = false;
      }

      /* Initialize a remeshing cavity */
      if (Q.empty()) continue;
      GrowthPolicy policy = GROW_MINIMAL;
      if (singularities.size() == 1) policy = GROW_MAXIMAL;
      MVertex* vSing = Q.top().second;
      Q.pop();
      auto it = v2q.find(vSing);
      if (it == v2q.end()) {
        Msg::Error("remesh singularity cavity: vertex not found in adjacency map, should NEVER happen");
        return false;
      }
      std::vector<MQuadrangle*> quadsInit = it->second;
      allowedIrregularVertices.clear();
      allowedIrregularVertices.insert(vSing);
      SPoint3 pos = vSing->point();

      /* Check cavities have already been tried from this
       * mesh vertex */
      size_t nPreviousTry = 0;
      auto itt = seedNbTries.find(vSing);
      if (itt != seedNbTries.end()) nPreviousTry = itt->second;
      if (nPreviousTry >= ctx.nTryMaxPerVertex) {
        Msg::Debug("---- singular vertex %li, reached maximum number of tries (%li/%li)", 
            vSing->getNum(), nPreviousTry, ctx.nTryMaxPerVertex);
        continue;
      }

      Msg::Debug("---< start cavity with %i quads adjacent to singularity vertex %li", 
          quadsInit.size(), vSing->getNum());

      /* Grow a convex cavity containg irregular vertices to remove */
      Cavity cav;
      std::pair<size_t,int> patternNoAndRot;
      std::vector<std::vector<MVertex*> > sides;
      bool okg = growCavity(policy, patternsToCheck, patternSizeLimits, quadsInit,
          v2q, allowedIrregularVertices, forbiddenIrregularVertices, cav, sides, patternNoAndRot);
      if (!okg) {
        seedNbTries[vSing] += 1;
        continue;
      }

      Msg::Debug("---- found a topological cavity with %i quads, try geometrical remeshing", cav.elements.size());

      bool okr = remeshCavity(gf, cav, sides, patternNoAndRot, ctx.invertNormalsForQuality, v2q, ctx);
      if (okr) {
        /* GFace mesh has changed, need to update adjacency info (v2q is no longer usable) */
        updateRequired = true;
        inProgress = true;
        nbCavityRemeshed += 1;
        repulsion.push_back(pos);

        /* Unlock close other irregular vertices that may be have unlocked */
        std::vector<std::pair<double,MVertex*> > others;
        others.reserve(seedNbTries.size());
        for (const auto& kv: seedNbTries) {
          MVertex* v2 = kv.first;
          if (v2 == vSing) continue;
          auto it = v2q.find(v2);
          if (it != v2q.end()) { /* check if vertex still in the mesh */
            others.push_back({pos.distance(v2->point()),v2});
          }
        }
        std::sort(others.begin(),others.end());
        for (size_t j = 0; j < std::min(others.size(),size_t(ctx.nTryCloseReset)); ++j) {
          MVertex* v2 = others[j].second;
          auto itc = seedNbTries.find(v2);
          if (itc != seedNbTries.end()) {
            itc->second = 0; /* reset the counter to 0 */
          }
        }
      } else {
        seedNbTries[vSing] += 1;
      }
    }

    ctx.nSingCavityRemesh += nbCavityRemeshed;

    Msg::Debug("-- remeshed %i singularity cavities", nbCavityRemeshed);

    // TODO: smoothing the pool ?
    if (false && nbCavityRemeshed > 0) {
      // Msg::Debug("-- surface mesh smoothing");
      // GeomOptimStats stats;
      // std::vector<MElement*> elements = dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles);
      // quadMeshOptimizeDMOKernelGreedy(gf, elements, gf->mesh_vertices,
      //     0.5, 0.7, 50, 10., ctx.invertNormalsForQuality, stats);
      // if (stats.sicnMinAfter < 0.) {
      //   Msg::Error("Negative quality after cavity remeshing ! SICN min: %.3f", stats.sicnMinAfter);
      // }
    }

    return true;
  }


  /* Global storage. Patterns are initialized at runtime, by the call to initQuadPatterns() */
  std::vector<QuadMeshPattern> patterns;
}

using namespace QMT;

int initQuadPatterns() {
  if (patterns.size() != 0) return false;
  {
    Msg::Info("loading %li quad patterns", quad_meshes.size());
    patterns.resize(quad_meshes.size());
    for (size_t i = 0; i < quad_meshes.size(); ++i) {
      bool ok = patterns[i].load(quad_meshes[i].first, quad_meshes[i].second);
      if (!ok) {
        Msg::Error("mesh quad patterns, failed to init pattern no %i", i);
      }
    }
  }
  return true;
}

std::vector<size_t> getAllLoadedPatterns() {
  std::vector<size_t> pIds;
  for (size_t i = 0; i < patterns.size(); ++i) {
    pIds.push_back(patterns[i].patternId);
  }
  return pIds;
}

bool patchIsRemeshableWithQuadPattern(
    const std::vector<size_t>& patternsToCheck,
    size_t Ncorners, 
    const std::vector<size_t>& sideSizes, 
    std::pair<size_t,int>& patternNoAndRot,
    double& irregularityMeasure) {
  irregularityMeasure = DBL_MAX;
  if (patterns.size() == 0) {
    Msg::Error("Quad patterns are not loaded, please call initQuadPatterns() before");
    return false;
  }

  vector<bool> check(patterns.size(),false);
  for (size_t pId: patternsToCheck) check[pId] = true;

  double irreg_min = DBL_MAX;
  for (size_t i = 0; i < patterns.size(); ++i) if (check[i]) {
    const QuadMeshPattern& P = patterns[i];
    // DBG(" ", i, P.ncorners, P.sides.size());;
    if (Ncorners != P.ncorners) continue;
    if (sideSizes.size() != P.sides.size()) continue;

    int rot = 0;
    double score = checkPatternMatchingWithRotations(P, sideSizes, rot);
    if (score > 0.) {
      double irreg = patternIrregularity(P);
      if (irreg < irreg_min) {
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
    GFace* gf,
    const std::pair<size_t,int>& patternNoAndRot,
    const std::vector<std::vector<MVertex*> > & sides,
    const std::vector<MElement*> & elements,
    const std::vector<MVertex*>& intVertices,
    double minSICNrequired,
    bool invertNormalsForQuality,
    SurfaceProjector* sp,
    GFaceMeshDiff& diff) {
  if (patterns.size() == 0) {
    Msg::Error("Quad patterns are not loaded, please call initQuadPatterns() before");
    return false;
  }

  size_t N = sides.size();
  const QuadMeshPattern& P = patterns[patternNoAndRot.first];
  int rot = patternNoAndRot.second;
  if (P.sides.size() != N) {
    Msg::Error("remesh patch with patterns: sides not matching, shoud not happen (pattern has %li sides, but %li sides in input) ...", P.sides.size(), N);
    return -1;
  }

  /* Apply the rotation */
  std::vector<std::vector<MVertex*> > sidesr = sides;
  if (rot > 0) {
    std::rotate(sidesr.begin(),sidesr.begin()+(size_t)rot,sidesr.end());
  } else if (rot < 0) {
    std::reverse(sidesr.begin(),sidesr.end());
    std::rotate(sidesr.begin(),sidesr.begin()+(size_t) std::abs(rot),sidesr.end());
    for (size_t i = 0; i <sidesr.size(); ++i) {
      std::reverse(sidesr[i].begin(),sidesr[i].end());
    }
  }

  /* Verify the given pattern and given sides are coherent */
  vector<size_t> ssr(sidesr.size());
  for (size_t i = 0; i < sidesr.size(); ++i) ssr[i] = sidesr[i].size();
  vector<int> slt;
  double match = checkPatternMatching(P, ssr, slt);
  if (match <= 0.) {
    Msg::Error("remesh patch with patterns: given pattern not matching given sides");
    return -1;
  }

  /* Add the new vertices and quads in the GFace */
  MVertex* oldCenter = centerOfElements(elements);

  /* Generate new interior MVertex and MElement instances */
  diff.gf = gf;
  diff.after.gf = gf;
  bool oka = addQuadsAccordingToPattern(P, slt, gf, sidesr, diff.after.intVertices, diff.after.elements, oldCenter);
  if (!oka) {
    Msg::Error("failed to add quads according to pattern, weird");
    clearStuff(diff.after.intVertices, diff.after.elements);
    return -1;
  }

  /* Ensure coherent orientation between the new mesh and the boundary.
   * The reference orientation (a,b) is from the sides before applying 
   * rotation. */
  MVertex* a = sides[0][0];
  MVertex* b = sides[0][1];
  bool oko = orientElementsAccordingToBoundarySegment(a, b, diff.after.elements);
  if (!oko) {
    Msg::Error("remesh quad with patterns: bdr quad edge not found, weird");
    return false;
  }

  /* Build the old patch in the diff */
  diff.before.gf = gf;
  diff.before.intVertices = intVertices;
  diff.before.elements = elements;
  /* - build a continuous bdr loop from the sides */
  diff.before.bdrVertices = {{sides.front().front()}};
  for (auto& side: sides) for (MVertex* v: side) {
    if (v != diff.before.bdrVertices.front().back()) {
      diff.before.bdrVertices.front().push_back(v);
    }
  }
  if (diff.before.bdrVertices.front().back() == diff.before.bdrVertices.front().front()) {
    diff.before.bdrVertices.front().pop_back();
  }
  diff.after.bdrVertices = diff.before.bdrVertices; /* the new patch has the same bdr */

  /* Determine the new patch geometry by smoothing on the surface */
  GeomOptimStats stats;
  int stGeoGlobal = -1;
  if (gf->haveParametrization()) {
    stGeoGlobal = patchOptimizeGeometryGlobal(diff.after, stats);
    if (stGeoGlobal != 0) {
      Msg::Debug("failed to optimize geometry with global UV smoothing");
    }
  }

  if (!gf->haveParametrization() || stGeoGlobal != 0 || stats.sicnMinAfter < minSICNrequired) {
    /* Project */
    bool okp = patchProjectOnSurface(diff.after, sp);
    if (!okp) {
      Msg::Debug("failed to project geometry");
      return -1;
    }

    /* Smooth with kernel */
    GeomOptimOptions opt;
    opt.sp = sp;
    opt.invertCADNormals = invertNormalsForQuality;
    opt.outerLoopIterMax = 100;
    opt.timeMax = 0.5;
    opt.localLocking = true;
    opt.dxGlobalMax = 1.e-3;
    opt.dxLocalMax = 1.e-5;
    opt.withBackup = false;
    patchOptimizeGeometryWithKernel(diff.after, opt, stats);
  }

  if (stats.sicnMinAfter < minSICNrequired) {
    Msg::Debug("remesh patch with quad pattern: rejected because SICN min is %.3f", stats.sicnMinAfter);
    return -1;
  }

  return 0;
}


int improveQuadMeshTopologyWithCavityRemeshing(GFace* gf,
    const std::vector<std::pair<SPoint3,int> >& singularities,
    bool invertNormalsForQuality) {

  Msg::Info("- Face %i: optimize quad mesh topology (%i elements, %i cross field singularities) with cavity remeshing ...",
      gf->tag(), gf->quadrangles.size(), singularities.size());
  size_t nqb = gf->quadrangles.size();
  size_t nvb = gf->mesh_vertices.size();


  QuadqsContext qqs;
  QuadqsGFaceContext ctx(qqs);
  ctx.invertNormalsForQuality = invertNormalsForQuality;

  bool alwaysBuildSurfaceProjector = true;
  if (alwaysBuildSurfaceProjector || !haveNiceParametrization(gf)) {
    ctx.sp = new SurfaceProjector();
    bool okf = fillSurfaceProjector(gf, ctx.sp);
    if (!okf) {
      return false;
    }
  }


  unordered_map<size_t,size_t> patternSizeLimits;
  patternSizeLimits[PATTERN_QUAD_DIAG35] = 100;
  patternSizeLimits[PATTERN_QUAD_ALIGNED35] = 200;
  patternSizeLimits[PATTERN_QUAD_CHORD_UTURN] = 100;
  vector<size_t> patternsToCheck;

  /* For a given vertex, we count the number of cavities
   * that have been tried starting from it.
   * The count is reset when an another close cavity is remeshed.
   * When a cavity is remeshed, its interior vertices are changed,
   * so the count is automatically reset.
   * (the pointer is now invalid, shoud not be used without checking existence) */
  unordered_map<MVertex*,size_t> seedNbTries;

  bool running = true;
  while (running) {
    running = false;
    size_t ncrb = ctx.nQuadCavityRemesh + ctx.nSingCavityRemesh;

    Msg::Debug("<< start cavity remeshing iteration");

    /* 1st pass: check regular quad patch remeshing only */
    patternsToCheck = {PATTERN_QUAD_REGULAR};
    bool ok1 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck, patternSizeLimits, seedNbTries, ctx);
    if (!ok1) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities", gf->tag());
      return false;
    }

    /* 2d pass: remesh around cross field singularities */
    patternsToCheck = {PATTERN_TRIANGLE,PATTERN_PENTAGON};
    bool ok2 = remeshSingularityCavities(gf, singularities, patternsToCheck, patternSizeLimits, seedNbTries,ctx);
    if (!ok2) {
      Msg::Error("- Face %i: failed to remesh singularity cavities", gf->tag());
      return false;
    }

    /* 3d pass: check regular quad patches again (if unlocked by singularity remeshing) */
    patternsToCheck = {PATTERN_QUAD_REGULAR};
    bool ok3 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck, patternSizeLimits, seedNbTries, ctx);
    if (!ok3) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities", gf->tag());
      return false;
    }

    /* 4d pass: size transition patterns */
    patternsToCheck = {PATTERN_QUAD_REGULAR, PATTERN_QUAD_DIAG35, PATTERN_QUAD_ALIGNED35, PATTERN_QUAD_CHORD_UTURN};
    bool ok4 = remeshQuadrilateralCavities(gf, singularities, patternsToCheck, patternSizeLimits, seedNbTries, ctx);
    if (!ok4) {
      Msg::Error("- Face %i: failed to remesh quadrilateral cavities", gf->tag());
      return false;
    }

    size_t ncra = ctx.nQuadCavityRemesh + ctx.nSingCavityRemesh;
    if (ncra > ncrb) { /* The mesh changed */
      /* Smooth geometry (quick) */
      double timeMax = 1.;
      optimizeGeometryQuadMesh(gf, ctx.sp, timeMax);

      /* Decrease the try counter, to enable a new try everywhere */
      for (auto& kv: seedNbTries) if (kv.second > 0) {
        kv.second -= 1;
      }
    }

    /* Restart a full iteration if some cavities have been remeshed */
    if (ncra > ncrb) running = true;
    Msg::Debug(">> end of cavity remeshing iteration");

    if (ctx.finished) {
      Msg::Debug("quad mesh remeshing is finised (minimal number of irregular vertices)");
      break;
    }
  }

  if (ctx.sp) {
    delete ctx.sp;
    ctx.sp = nullptr;
  }

  Msg::Info("- Face %i: remeshed %i singular and %i quadrilateral cavities, %i -> %i quads, %i -> %i vertices",
      gf->tag(), ctx.nSingCavityRemesh, ctx.nQuadCavityRemesh, nqb, gf->quadrangles.size(), nvb, gf->mesh_vertices.size());

  return 0;
}

int meshFaceWithGlobalPattern(GFace* gf, bool invertNormalsForQuality, double minimumQualityRequired) {
  GFaceInfo info;
  bool okf = fillGFaceInfo(gf, info);
  if (!okf) return -1;

  /* Check if convex topological disk */
  bool topologicalDisk = false;
  if (info.chi == 1 && info.bdrValVertices[1].size() >= 0 
      && info.bdrValVertices[3].size() == 0 && info.bdrValVertices[4].size() == 0) {
    topologicalDisk = true;
  }
  if (!topologicalDisk) {
    return -1;
  }

  Msg::Debug("- Face %i: is topological disk, try quad pattern meshing", gf->tag());

  double t0 = Cpu();

  /* Build the ordered sides */
  const vector<GEdge *>& edges = gf->edges();
  unordered_map<GVertex*,vector<GEdge*> > v2e;
  for (GEdge* ge: edges) {
    if (ge->periodic(0)) continue;
    for (GVertex* gv: ge->vertices()) v2e[gv].push_back(ge);
  }
  for (auto& kv: v2e) { sort_unique(kv.second); }
  std::set<GVertex*> corners = info.bdrValVertices[1];
  bool disk = (corners.size() == 0 && info.bdrValVertices[2].size() > 0);

  /* Sort CAD edges in sides */
  vector<vector<GEdge*> > sides;
  vector<vector<bool> > sidesInv;
  for (GEdge* e0: edges) if (!e0->periodic(0)) {
    GVertex* v1 = e0->vertices()[0];
    GVertex* v2 = e0->vertices()[1];
    bool v1IsCorner = (corners.find(v1) != corners.end());
    if (!disk && !v1IsCorner) continue;
    if (disk) {
      sides.resize(1);
      sidesInv.resize(1);
    }

    size_t infLoop = 0;
    GVertex* v = v1;
    GEdge* e = e0;
    bool inv = false;
    do {
      infLoop += 1;
      if (infLoop > 1e6) {
        Msg::Warning("infinite loop in edges of face %i, cancel simple quad mesh", gf->tag());
        return -1;
      }
      bool vIsCorner = (corners.find(v) != corners.end());
      if (vIsCorner) {
        sides.resize(sides.size()+1);
        sidesInv.resize(sidesInv.size()+1);
      }
      v1 = e->vertices()[0];
      v2 = e->vertices()[1];

      inv = (v == v2);

      sides.back().push_back(e);
      sidesInv.back().push_back(inv);

      GVertex* v_next = NULL;
      if (v2 != v) {
        v_next = v2;
      } else {
        v_next = v1;
      }
      GEdge* e_next = NULL;
      if (v2e[v_next].size() == 2) {
        e_next = (v2e[v_next][0] != e) ? v2e[v_next][0] : v2e[v_next][1];
      } else {
        Msg::Warning("non manifold edge loop around face %li, cancel simple quad mesh", gf->tag());
        return -1;
      }

      e = e_next;
      v = v_next;
    } while (e != e0);
    break;
  }

  if (disk && gf->edges().size() == 1 && gf->edges()[0]->periodic(0)) {
    sides = {gf->edges()};
    sidesInv = {{false}};
  }

  if (sides.size() == 0) {
    Msg::Debug("face %i (%li edges), failed to build sides",gf->tag(),edges.size());
    DBG(disk);
    return -1;
  }

  /* Collect mesh vertices */
  vector<vector<MVertex*> > sideVertices(sides.size());
  for (size_t i = 0; i < sides.size(); ++i) {
    for (size_t j = 0; j < sides[i].size(); ++j) {
      GEdge* ge = sides[i][j];
      bool inv = sidesInv[i][j];
      GVertex* v1 = ge->vertices()[0];
      GVertex* v2 = ge->vertices()[1];

      /* Vertices from v1 to v2 */
      vector<MVertex*> ge_vert;
      {
        std::vector<MEdge> medges(ge->lines.size());
        for (size_t k = 0; k < ge->lines.size(); ++k) {
          medges[k] = MEdge(ge->lines[k]->getVertex(0),ge->lines[k]->getVertex(1));
        }
        std::vector<std::vector<MVertex* > > gevs;
        bool oks = SortEdgeConsecutive(medges, gevs);
        if (!oks || gevs.size() != 1) return -1;
        if (gevs[0].front() == v1->mesh_vertices[0]
            && gevs[0].back() == v2->mesh_vertices[0]) {
          ge_vert = gevs[0];
        } else if (gevs[0].front() == v2->mesh_vertices[0]
            && gevs[0].back() == v1->mesh_vertices[0]) {
          ge_vert = gevs[0];
          std::reverse(ge_vert.begin(),ge_vert.end());
        } else {
          Msg::Error("corner and edge vertices not matching");
          return -1;
        }
      }

      if (inv) {
        std::reverse(ge_vert.begin(),ge_vert.end());
      }
      if (sideVertices[i].size() == 0) {
        append(sideVertices[i], ge_vert);
      } else {
        if (sideVertices[i].back() == ge_vert[0]) {
          sideVertices[i].pop_back();
        }
        append(sideVertices[i], ge_vert);
      }
    }
  }

  /* When there is just one side, two possible cases:
   * - disk (all bdr vertices are quad-valence 2)
   * - face with only one convex corner
   */
  if (sides.size() == 1) {
    if (sides[0].size() < 1) {
      Msg::Warning("not enough vertices on face loop for quad meshing (%li vert)", sides[0].size());
      return -1;
    }
    if (disk) {
      if (sides[0].front() == sides[0].back()) {
        sides[0].pop_back();
      }
    } else {
      if (sides[0].front() == sides[0].back()) {
        sides[0].pop_back();
      }
    }
  }


  /* Pure topological check with side sizes */
  std::vector<size_t> patternsToCheck = getAllLoadedPatterns();
  std::vector<size_t> sideSizes(sideVertices.size());
  for (size_t i = 0; i < sideSizes.size(); ++i) sideSizes[i] = sideVertices[i].size();

  std::pair<size_t,int> patternNoAndRot;
  size_t Ncorners = disk ? 0 : sideSizes.size();
  double irreg;
  bool meshable = patchIsRemeshableWithQuadPattern(patternsToCheck, Ncorners, sideSizes, patternNoAndRot, irreg);
  if (!meshable) return -1;


  /* Build the mesh, smooth and check the geometry quality */
  std::vector<MElement*> oldElements;
  oldElements.reserve(gf->quadrangles.size()+gf->triangles.size());
  for (MElement* f: gf->triangles) oldElements.push_back(f);
  for (MElement* f: gf->quadrangles) oldElements.push_back(f);
  std::vector<MVertex*> oldVertices = gf->mesh_vertices;

  /* SurfaceProjector, useful for smoothing */
  SurfaceProjector* sp = new SurfaceProjector();
  bool oksp = fillSurfaceProjector(gf, sp);
  if (!oksp) {
    delete sp;
    sp = nullptr;
  }

  const double minSICNafer = -DBL_MAX; /* do not filter based on quality */
  GFaceMeshDiff diff;
  int st = remeshPatchWithQuadPattern(gf, patternNoAndRot, sideVertices, oldElements, 
      oldVertices, minSICNafer, invertNormalsForQuality, sp, diff);
  if (st != 0) {
    if (DBG_VERBOSE) {Msg::Debug("remesh cavity: %li quads, failed to remesh path with quad pattern",
        oldElements.size());}
    if (sp) delete sp;
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
    if (!oko) {
      if (sp) delete sp;
      return -1;
    }

    computeSICN(diff.before.elements, sicnMin, sicnAvg);
    computeSICN(diff.after.elements, sicnMinAfter, sicnAvgAfter);
    if (sicnMinAfter > minimumQualityRequired) {
      constexpr bool verifyTopology = true;
      bool oke = diff.execute(verifyTopology);
      if (oke) {
        good = true;
      } else {
        Msg::Error("remesh cavity: diff execute() failed, should not happen");
      }
    } else {
      Msg::Debug("- Face %i: pattern-based quad mesh REJECTED because SICN min %.3f < %.3f",
          gf->tag(), sicnMinAfter, minimumQualityRequired);
    }
  }

  if (good) {
    Msg::Info("- Face %i: remeshed with a global pattern, %li -> %li quads, %i -> %i int. vertices, SICN min: %.3f -> %.3f, SICN avg: %.3f -> %.3f, time: %.3fs",
        gf->tag(), neb, nea, nvb, nva, sicnMin, sicnMinAfter, sicnAvg, sicnAvgAfter, Cpu()-t0);
    gf->meshStatistics.status = GFace::DONE;
  }

  if (sp) delete sp;

  return good;
}
