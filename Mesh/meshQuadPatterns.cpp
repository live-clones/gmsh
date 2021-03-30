// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshQuadPatterns.h"
#include <map>
#include <iostream>
#include "meshQuadQuasiStructured.h"
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "discreteFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"

#if defined(HAVE_EIGEN)
#include<Eigen/IterativeLinearSolvers>
#include<Eigen/SparseCholesky>
#include<Eigen/SparseLU>
#endif

#include "meshRefine.h"
#include "Generator.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Field.h"
#include "geolog.h"
#include "meshWinslow2d.h"
#include "meshQuadGeometry.h"
#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing
#include "robin_hood.h"
#include "row_echelon_integer.hpp"
#include "meshQuadData.hpp"
#include "meshSurfaceProjection.h"
#include "StringUtils.h"
#include "meshQuadUtils.h"


#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;
using namespace QuadUtils;

namespace QuadPatternMatching {

  const size_t PATTERN_QUAD_REGULAR = 0;
  const size_t PATTERN_TRIANGLE = 1;
  const size_t PATTERN_PENTAGON = 2;
  const size_t PATTERN_QUAD_DIAG35 = 3;
  const size_t PATTERN_QUAD_ALIGNED35 = 4;
  const size_t PATTERN_QUAD_CHORD_UTURN = 5;
  const size_t PATTERN_2CORNERS = 6;
  const size_t PATTERN_1CORNER = 7;
  const size_t PATTERN_DISK = 8;

  using id = uint32_t;
  using id2 = std::array<id,2>;
  using id4 = std::array<id,4>;

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
  struct id2Hash {
    size_t operator()(id2 p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };

  struct vidHash {
    size_t operator()(const std::vector<id>& p) const noexcept {
      uint32_t hash = 0;
      for (size_t i = 0; i < p.size(); ++i) {
        hash += p[i];
        hash += hash << 10;
        hash ^= hash >> 6;
      }
      hash += hash << 3;
      hash ^= hash >> 11;
      hash += hash << 15;
      return hash;
    }
  };


  using Quadrangulation = std::vector< std::array<id,4> >;
  /* Global variable, filled by load_disk_quadrangulations() with the data 
   * in Mesh/meshQuadData.hpp */
  std::vector< std::vector<Quadrangulation> > B_disk_quadrangulations;
  /* Hash mapping from boundary valence loop (BVL) to disk_quadrangulations
   * Useful for fast queries */
  std::vector< robin_hood::unordered_map< std::vector<id>, std::vector<id>, vidHash > > B_BVL_ids;

  /* Keep track of pattern usage, just for statistics */
  robin_hood::unordered_map<id2,id,id2Hash> usage_count;

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
      robin_hood::unordered_map<id2,id,id2Hash> vpair2e;
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

  /* Patterns are initialized at runtime, by the call to load_patterns() */
  std::vector<QuadMeshPattern> patterns;

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

  bool setVertexGFaceUV(GFace* gf, MVertex* v, double uv[2]) {
    bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
    if (onGf) {
      v->getParameter(0,uv[0]);
      v->getParameter(1,uv[1]);
      return true;
    } else {
      GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
      if (ge != NULL) {
        double t;
        v->getParameter(0,t);
        SPoint2 uvp = ge->reparamOnFace(gf, t, -1);
        uv[0] = uvp.x();
        uv[1] = uvp.y();
        return true;
      } else {
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        if (gv != NULL) {
          SPoint2 uvp = gv->reparamOnFace(gf,0);
          uv[0] = uvp.x();
          uv[1] = uvp.y();
          return true;
        }
      }
    }
    uv[0] = 0.;
    uv[1] = 0.;
    return false;
  }

  bool parametrizationAvailable(GFace* gf) {
    discreteFace* df = dynamic_cast<discreteFace*>(gf);
    if (df != NULL && df->haveParametrization() == false) return false;
    return true;
  }

  std::vector<MVertex*> createVertices (GFace* gf, MVertex *v1, MVertex *v2, int n,
      std::vector<MVertex*>& newVertices, SurfaceProjector* sp = NULL){
    bool haveParam = parametrizationAvailable(gf);
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
      GPoint proj;
      if (sp != NULL) {
        size_t cache = (size_t) -1;
        proj = sp->closestPoint(vNew->point(), cache, true, false);
      } else {
        proj = gf->closestPoint(vNew->point(),uv);
      }
      if (proj.succeeded()) {
        vNew->setXYZ(proj.x(), proj.y(), proj.z());
        vNew->setParameter(0,proj.u());
        vNew->setParameter(1,proj.v());
      } else {
        vNew->setXYZ(p.x(), p.y(), p.z());
        vNew->setParameter(0,uv[0]);
        vNew->setParameter(1,uv[1]);
      }
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
      std::vector<MVertex*>& newVertices,
      SurfaceProjector* sp = NULL){

    bool haveParam = parametrizationAvailable(gf);

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

          GPoint proj;
          if (sp != NULL) { /* Project on triangulation then interpolate CAD */
            size_t cache = (size_t) -1;
            proj = sp->closestPoint(vNew->point(), cache, haveParam, false);
          } else {
            proj = gf->closestPoint(vNew->point(),uv);
          }
          if (proj.succeeded()) {
            vNew->setXYZ(proj.x(), proj.y(), proj.z());
            if (haveParam) {
              vNew->setParameter(0,proj.u());
              vNew->setParameter(1,proj.v());
            }
          } else {
            vNew->setXYZ(p.x(), p.y(), p.z());
            vNew->setParameter(0,uv[0]);
            vNew->setParameter(1,uv[1]);
          }
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
      std::vector<bool>& vertexIsIrregular,             /* for each new vertex, true if irregular */
      std::vector<MElement*>& newElements,              /* new quads inside the cavity */
      MVertex* oldCenter = NULL,                        /* initial guess for new positions */
      SurfaceProjector* sp = NULL
      ) {
    constexpr bool DBG_VIZU = false;
    if (P.sides.size() != sides.size()) {
      Msg::Error("wrong input sizes ... pattern: %li sides, input: %li sides", P.sides.size(),sides.size());
      return false;
    }

    robin_hood::unordered_map<id2, std::vector<MVertex*>, id2Hash> vpair2vertices;
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

          if (DBG_VIZU) {
            if (k != sides[s].size()-1) {
              vector<array<double,3>> pts = {SVector3(sides[s][k]->point()),SVector3(sides[s][k+1]->point())};
              vector<double> values = {double(k),double(k+1)};
              GeoLog::add(pts,values,"side_input_vert_"+std::to_string(s));
            }
          }
        }
      }
      if (csum == 0.) return false;
      center = 1./csum * center;
    }

    // DBG("--------");
    for (size_t s = 0; s < P.sides.size(); ++s) {
      size_t pos = 0;
      // DBG(s);
      // DBG("- input:", sides[s].size());
      size_t sp = 0;
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        sp += quantization[P.eChordId[P.sides[s][j]]];
      }
      // DBG("- pattern:", sp+1);
      if (sp + 1 != sides[s].size()) {
        // DBG("bad");
        return false;
      }
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        int n_e = quantization[P.eChordId[e]];
        // DBG(" ", j, P.sides[s].size(), e, n_e);
        vert.resize(n_e+1);
        for (size_t k = 0; k < (size_t) n_e+1; ++k) {
          // DBG("   ", k, n_e+1, pos, pos+k, sides[s].size());
          if (pos+k>=sides[s].size()) {
            Msg::Error("issue, pos=%li + k=%li = %li >= sides[s].size()=%li", pos, k, pos+k, sides[s].size());
            if (DBG_VIZU) GeoLog::flush();
            return false;
          }
          vert[k] = sides[s][pos+k];
        }
        pos += n_e;
        id v1 = P.edges[e][0];
        id v2 = P.edges[e][1];
        if (v2mv[v1] == NULL) v2mv[v1] = vert.front();
        if (v2mv[v2] == NULL) v2mv[v2] = vert.back();

        if (DBG_VIZU) {
          vector<array<double,3>> pts = {SVector3(v2mv[v1]->point()),SVector3(v2mv[v2]->point())};
          vector<double> values = {0.,1.};
          GeoLog::add(pts,values,"side_"+std::to_string(s)+"_"+std::to_string(j));
        }
        if (DBG_VIZU) {
          for (size_t k = 0; k < vert.size()-1; ++k) {
            vector<array<double,3>> pts = {SVector3(vert[k]->point()),SVector3(vert[k+1]->point())};
            vector<double> values = {double(k),double(k+1)};
            GeoLog::add(pts,values,"side_vert_"+std::to_string(s)+"_"+std::to_string(j));
          }
        }
        // // DBG(s,j,e,n_e,pos-n_e,pos,v1,v2,vert,vert.size());
        // DBG("  ", sides[s].size());

        id2 vpair = sorted(v1,v2);
        if (v1 < v2) {
          vpair2vertices[vpair] = vert;
        } else {
          std::reverse(vert.begin(),vert.end());
          vpair2vertices[vpair] = vert;
        }
      }
    }
    if (DBG_VIZU) GeoLog::flush();

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
      vertexIsIrregular.push_back(irregular);
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
        vpair2vertices[vpair] = createVertices (gf, mv1, mv2, n_e, newVertices, sp);
      } else {
        vpair2vertices[vpair] = createVertices (gf, mv2, mv1, n_e, newVertices, sp);
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
        if (DBG_VIZU) {
          for (size_t k = 0; k < quadCurves[le].size()-1; ++k) {
            vector<array<double,3>> pts = {SVector3(quadCurves[le][k]->point()),SVector3(quadCurves[le][k+1]->point())};
            vector<double> values = {double(k),double(k+1)};
            GeoLog::add(pts,values,"quad_"+std::to_string(f));

          }
        }
      }
      if (DBG_VIZU) GeoLog::flush();
      createQuadPatch(gf, quadCurves[0], quadCurves[1], quadCurves[2], quadCurves[3], newElements, newVertices, sp);
    }
    vertexIsIrregular.resize(newVertices.size(),false);


    return true;
  }


  bool computeQuadMeshValences(const vector<id4>& quads, vector<int>& valence) {
    valence.clear();
    valence.reserve(quads.size()*4);
    for (size_t f = 0; f < quads.size(); ++f) for (size_t lv = 0; lv < 4; ++lv) {
      size_t v = quads[f][lv];
      if (v >= valence.size()) valence.resize(v+1,0);
      valence[v] += 1;
    }
    return true;
  }

  double computeIrregularity(
      const vector<id4>& quads, 
      const vector<int>& valence,
      const std::vector<int>& bndIdealValence,
      const std::vector<std::pair<int,int> >& bndAllowedValenceRange) 
  {
    double irregularity = 0.;
    for (size_t bv = 0; bv < bndIdealValence.size(); ++bv) {
      if (valence[bv] < bndAllowedValenceRange[bv].first) return DBL_MAX;
      if (valence[bv] > bndAllowedValenceRange[bv].second) return DBL_MAX;
      if (bndIdealValence[bv] <= 1 && valence[bv] >= 2) { /* probably making a 6+ ... */
        irregularity += 1000;
      } else {
        irregularity += 10*std::pow(bndIdealValence[bv]-valence[bv],2);
      }
    }
    for (size_t iv = bndIdealValence.size(); iv < valence.size(); ++iv) {
      irregularity += std::pow(4-valence[iv],2);
    }
    return irregularity;
  }

  bool computeBestMatchingConfiguration(
      const vector<id4>& quads, 
      const vector<int>& valence,
      const vector<int>& bndIdealValence,
      const vector<std::pair<int,int> >& bndAllowedValenceRange,
      int& rotation,
      double& irregularity)
  {
    double best = DBL_MAX;
    int rot = 0;
    vector<int> biv = bndIdealValence;
    vector<std::pair<int,int>>  bav = bndAllowedValenceRange;

    /* Initial config */
    {
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    /* Forward rotation */
    for (size_t r = 1; r < biv.size(); ++r) {
      rot += 1;
      std::rotate(biv.begin(),biv.begin()+1,biv.end());
      std::rotate(bav.begin(),bav.begin()+1,bav.end());
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    /* Try in reverse order */
    rot = 0;
    biv = bndIdealValence;
    bav = bndAllowedValenceRange;
    std::reverse(biv.begin(),biv.end());
    std::reverse(bav.begin(),bav.end());
    for (size_t r = 1; r < biv.size(); ++r) {
      rot -= 1;
      std::rotate(biv.begin(),biv.begin()+1,biv.end());
      std::rotate(bav.begin(),bav.begin()+1,bav.end());
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    irregularity = best;
    return (best != DBL_MAX);
  }

  /* WARNING: GFace is not modified, just the "floating" MVertex
   * and MQuadrangle are created, they must be inserted in the GFace
   * later is the pattern is kept */
  bool applyPatternToRemeshFewQuads(
      GFace* gf,
      const std::vector<MVertex*>& bnd,
      const std::vector<int>& bndIdealValence,
      const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
      int rotation,                                      /* rotation to apply to input */
      const std::vector<id4>& quads,                     /* pattern */
      const vector<int>& valence,                        /* valence in pattern */
      std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
      std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
      std::vector<MElement*> & newElements               /* new quads inside the cavity */
      ) {

    std::vector<MVertex*> bndr = bnd;
    if (rotation > 0) {
      std::rotate(bndr.begin(),bndr.begin()+(size_t)rotation,bndr.end());
    } else if (rotation < 0) {
      std::reverse(bndr.begin(),bndr.end());
      std::rotate(bndr.begin(),bndr.begin()+(size_t) std::abs(rotation),bndr.end());
    }

    robin_hood::unordered_map<id,MVertex*> pv2mv;
    for (size_t f = 0; f < quads.size(); ++f) {
      std::array<MVertex*,4> vert;
      for (size_t lv = 0; lv < 4; ++lv) {
        size_t pv = quads[f][lv];
        if (pv < bndr.size()) {
          vert[lv] = bndr[pv];
        } else {
          auto it = pv2mv.find(pv);
          if (it == pv2mv.end()) {
            SVector3 p = bndr[0]->point();
            double uv[2] = {0.,0.};
            MVertex *mv = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
            pv2mv[pv] = mv;
            vert[lv] = mv;
            newVertices.push_back(mv);
            vertexIsIrregular.push_back(valence[pv]!=4);
          } else {
            vert[lv] = it->second;
          }
        }
      }
      if (rotation < 0) { /* revert quad to keep coherent orientation */
        std::reverse(vert.begin(),vert.end());
      }
      MQuadrangle *q = new MQuadrangle (vert[0],vert[1],vert[2],vert[3]);
      newElements.push_back(q);
    }

    return true;
  }

  bool laplacianSmoothing(
      const std::vector<MVertex*>& newVertices,
      const std::vector<MElement*>& newElements,
      size_t iter = 10) {
    Msg::Debug("laplacian smoothing with %li new vertices and %li new quads, %li iterations (no projection) ... ", newVertices.size(), newElements.size(), iter);

    robin_hood::unordered_map<MVertex*,size_t> old2new;
    size_t vcount = 0;
    for (MVertex* v: newVertices) {
      old2new[v] = vcount;
      vcount += 1;
    }
    size_t nInterior = vcount;
    vector<vector<size_t> > v2v(nInterior);
    for (MElement* f: newElements) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v1 = f->getVertex(le);
        MVertex* v2 = f->getVertex((le+1)%4);
        size_t nv1 = NO_ID;
        auto it1 = old2new.find(v1);
        if (it1 == old2new.end()) {
          old2new[v1] = vcount;
          nv1 = vcount;
          vcount += 1;
        } else {
          nv1 = it1->second;
        }
        size_t nv2 = NO_ID;
        auto it2 = old2new.find(v2);
        if (it2 == old2new.end()) {
          old2new[v2] = vcount;
          vcount += 1;
        } else {
          nv2 = it2->second;
        }
        if (nv1 < nInterior) v2v[old2new[v1]].push_back(old2new[v2]);
        if (nv2 < nInterior) v2v[old2new[v2]].push_back(old2new[v1]);
      }
    }
    vector<SVector3> pts(vcount);
    for (auto& kv: old2new)  {
      MVertex* v = kv.first;
      size_t idx = kv.second;
      pts[idx] = v->point();
    }
    for (size_t i = 0; i < iter; ++i) {
      for (size_t v = 0; v < nInterior; ++v) {
        SVector3 avg(0.,0.,0.);
        double sum = 0.;
        for (size_t v2: v2v[v]) {
          avg += pts[v2];
          sum += 1.;
        }
        if (sum == 0) continue;
        pts[v] = SPoint3(avg.x()/sum,avg.y()/sum,avg.z()/sum);
      }
    }
    for (MVertex* v: newVertices) {
      size_t idx = old2new[v];
      SVector3 p = pts[idx];
      v->setXYZ(p.x(),p.y(),p.z());
    }

    return true;
  }

  MVertex* centerOfElements(const std::vector<MElement*>& elements) {
    std::map<std::array<MVertex*,2>,size_t> vPairCount;
    robin_hood::unordered_map<MVertex*,robin_hood::unordered_set<MVertex*> > v2v;
    for (MElement* f: elements) {
      size_t N = f->getNumEdges();
      for (size_t le = 0; le < N; ++le) {
        MVertex* v1 = f->getVertex(le);
        MVertex* v2 = f->getVertex((le+1)%N);
        v2v[v1].insert(v2);
        v2v[v2].insert(v1);
        std::array<MVertex*,2> vPair = {v1,v2};
        if (v2 < v1) {
          vPair = {v2,v1};
        }
        vPairCount[vPair] += 1;
      }
    }

    /* Init from boundary */
    robin_hood::unordered_map<MVertex*,double> dist;
    std::priority_queue<std::pair<double,MVertex*>,  std::vector<std::pair<double,MVertex*> >,  std::greater<std::pair<double,MVertex*> > > Q; 
    for (const auto& kv: vPairCount) if (kv.second == 1) {
      dist[kv.first[0]] = 0.;
      dist[kv.first[1]] = 0.;
      Q.push({0.,kv.first[0]});
      Q.push({0.,kv.first[1]});
    }

    /* Dijkstra propagation */
    while (Q.size() > 0) {
      MVertex* v = Q.top().second;
      double cdist = Q.top().first;
      Q.pop();
      for (MVertex* v2: v2v[v]) {
        double w_ij = v->distance(v2);
        auto it = dist.find(v2);
        if (it == dist.end() || cdist + w_ij < it->second) {
          double new_dist = cdist + w_ij;
          dist[v2] = cdist + w_ij;
          Q.push({new_dist,v2});
        }
      }
    }

    double dmax = 0.;
    MVertex* center = NULL;
    for (const auto& kv: dist) {
      if (kv.second > dmax) {
        dmax = kv.second;
        center = kv.first;
      }
    }
    return center;
  }

  SVector3 projectPointLaplacian(GFace* gf, SVector3 currentPosition, SVector3 newAveragedPosition,
      SPoint2& newUv) {
    newUv[0] = DBL_MAX;
    double uv[2] = {0.,0.};
    SPoint3 p(newAveragedPosition);
    GPoint proj = gf->closestPoint(p,uv);
    if (proj.succeeded()) {
      newUv.setPosition(proj.u(),proj.v());
      return SVector3(proj.x(),proj.y(),proj.z());
    } else {
      p = (SPoint3(currentPosition) + SPoint3(newAveragedPosition)) * 0.5;
      proj = gf->closestPoint(p,uv);
      if (proj.succeeded()) {
        newUv.setPosition(proj.u(),proj.v());
        return SVector3(proj.x(),proj.y(),proj.z());
      }
    }
    return currentPosition;
  }

  bool laplacianSmoothingWithProjection(
      GFace* gf,
      const std::vector<MElement*>& oldElements,
      const std::vector<MVertex*>& newVertices,
      const std::vector<MElement*>& newElements,
      size_t iter = 10) {
    Msg::Debug("laplacian smoothing with %li new vertices and %li new quads, %li iterations (with projections) ... ", newVertices.size(), newElements.size(), iter);
    discreteFace* df = dynamic_cast<discreteFace*>(gf);

    SVector3 center(DBL_MAX,DBL_MAX,DBL_MAX);
    if (oldElements.size() > 0) {
      MVertex* oldv = centerOfElements(oldElements);
      if (oldv) center = oldv->point();
    }

    robin_hood::unordered_map<MVertex*,size_t> old2new;
    size_t vcount = 0;
    for (MVertex* v: newVertices) {
      old2new[v] = vcount;
      vcount += 1;
    }
    size_t nInterior = vcount;
    vector<vector<size_t> > v2v(nInterior);
    for (MElement* f: newElements) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v1 = f->getVertex(le);
        MVertex* v2 = f->getVertex((le+1)%4);
        size_t nv1 = NO_ID;
        auto it1 = old2new.find(v1);
        if (it1 == old2new.end()) {
          old2new[v1] = vcount;
          nv1 = vcount;
          vcount += 1;
        } else {
          nv1 = it1->second;
        }
        size_t nv2 = NO_ID;
        auto it2 = old2new.find(v2);
        if (it2 == old2new.end()) {
          old2new[v2] = vcount;
          vcount += 1;
        } else {
          nv2 = it2->second;
        }
        if (nv1 < nInterior) v2v[old2new[v1]].push_back(old2new[v2]);
        if (nv2 < nInterior) v2v[old2new[v2]].push_back(old2new[v1]);
        if (center.x() == DBL_MAX && nv1 >= nInterior) {
          center = v1->point();
        }
      }
    }
    vector<SVector3> pts(vcount);
    vector<SPoint2> uvs(vcount);
    for (auto& kv: old2new)  {
      MVertex* v = kv.first;
      size_t idx = kv.second;
      pts[idx] = v->point();
      if (kv.second < nInterior && center.x() != DBL_MAX) {
        pts[idx] = center;
      }
    }
    for (size_t i = 0; i < iter; ++i) {
      for (size_t v = 0; v < nInterior; ++v) {
        SVector3 avg(0.,0.,0.);
        double sum = 0.;
        for (size_t v2: v2v[v]) {
          avg += pts[v2];
          sum += 1.;
        }
        if (sum == 0) continue;
        SVector3 np(avg.x()/sum,avg.y()/sum,avg.z()/sum);
        if (i < 10) { /* easier projection at beginning */
          np = 0.9 * pts[v] + 0.1 * np;
        }
        pts[v] = projectPointLaplacian(gf,pts[v],np,uvs[v]);
      }
    }
    for (MVertex* v: newVertices) {
      size_t idx = old2new[v];
      SVector3 p = pts[idx];
      v->setXYZ(p.x(),p.y(),p.z());
      if (!df && uvs[idx][0] != DBL_MAX) {
        v->setParameter(0,uvs[idx][0]);
        v->setParameter(1,uvs[idx][1]);
      }
    }

    return true;
  }


  inline double distance2(const SPoint2& a, const SPoint2& b) {
    const double dx = a.x()-b.x();
    const double dy = a.y()-b.y();
    return dx*dx+dy*dy;
  }

  inline double distance2(const SPoint3& a, const SPoint3& b) {
    const double dx = a.x()-b.x();
    const double dy = a.y()-b.y();
    const double dz = a.z()-b.z();
    return dx*dx+dy*dy+dz*dz;
  }

  bool solveLaplaceLinearSystem(
      size_t nInterior,
      const vector<vector<size_t> >& v2v, vector<SPoint2>& uvs) {
    Msg::Debug("solve laplace linear system ...");

#if defined(HAVE_EIGEN)
    size_t N = uvs.size();
    Eigen::VectorXd x_u(N), x_v(N), b_u(N), b_v(N);
    Eigen::SparseMatrix<double> A(N,N);
    b_u.fill(0.);
    b_v.fill(0.);
    double PENALTY = 1.e8;

    std::vector<Eigen::Triplet<double> > triplets;
    for (size_t v = 0; v < uvs.size(); ++v) {
      if (v < nInterior) {
        triplets.push_back({v,v,1.});
        if (v2v[v].size() == 0) continue;
        double sum = double(v2v[v].size());
        for (size_t v2: v2v[v]) {
          triplets.push_back({v,v2,-1./sum});
        }
      } else { /* fixed value */
        triplets.push_back({v,v,PENALTY});
        b_u[v] = PENALTY * uvs[v][0];
        b_v[v] = PENALTY * uvs[v][1];
      }
    }
    A.setFromTriplets(triplets.begin(),triplets.end());

    bool solveOk = true;
    { /* Try SparseLU */
      Eigen::SparseLU<Eigen::SparseMatrix<double> > solver;
      solver.analyzePattern(A);
      solver.factorize(A);
      x_u = solver.solve(b_u);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
    }
    if (!solveOk) { /* Try least square */
      solveOk = true;
      Eigen::LeastSquaresConjugateGradient<Eigen::SparseMatrix<double> > solver;
      solver.compute(A);
      x_u = solver.solve(b_u);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
    }

    for (size_t v = 0; v < nInterior; ++v) {
      uvs[v][0] = x_u[v];
      uvs[v][1] = x_v[v];
    }
    if (!solveOk) {
      Msg::Error("failed to solve linear system to solve uv");
      return false;
    }

#else 
    Msg::Error("solveLaplaceLinearSystem requires the EIGEN module");
    return -1;
#endif
    return true;
  }

  bool solveLaplaceLinearSystemWith3DMetric(
      size_t nInterior,
      const vector<vector<size_t> >& v2v, 
      const std::vector<MVertex*>& vertices,
      vector<SPoint2>& uvs) {
    Msg::Debug("solve laplace linear system ...");

#if defined(HAVE_EIGEN)
    size_t N = uvs.size();
    Eigen::VectorXd x_u(N), x_v(N), b_u(N), b_v(N);
    Eigen::SparseMatrix<double> A(N,N);
    b_u.fill(0.);
    b_v.fill(0.);
    double PENALTY = 1.e8;

    const double eps = std::pow(1.e-16,2);
    std::vector<Eigen::Triplet<double> > triplets;
    for (size_t v = 0; v < uvs.size(); ++v) {
      if (v < nInterior) {
        if (v2v[v].size() == 0) continue;
        double sum = 0.;
        for (size_t v2: v2v[v]) {
          //double duv2 = distance2(uvs[v],uvs[v2]);
          double d2 = distance2(vertices[v]->point(),vertices[v2]->point());
          // double w = (d2 > eps) ? 1./std::sqrt(d2) : 1.;
          double w = (d2 > eps) ? 1./d2 : 1.;
          // double w = (d2 > eps) ? std::sqrt(duv2)/std::sqrt(d2) : 1.;
          // double w = (d2 > eps) ? 1./std::sqrt(d2) : 1.;
          // double w = (d2 > eps) ? -std::sqrt(d2) : 1.;
          triplets.push_back({v,v2,-w});
          sum += w;
        }
        triplets.push_back({v,v,sum});
      } else { /* fixed value */
        triplets.push_back({v,v,PENALTY});
        b_u[v] = PENALTY * uvs[v][0];
        b_v[v] = PENALTY * uvs[v][1];
      }
    }
    A.setFromTriplets(triplets.begin(),triplets.end());

    bool solveOk = true;
    { /* Try SparseLU */
      Eigen::SparseLU<Eigen::SparseMatrix<double> > solver;
      solver.analyzePattern(A);
      solver.factorize(A);
      x_u = solver.solve(b_u);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with SparseLU (%li variables)", N);
        solveOk = false;
      }
    }
    if (!solveOk) { /* Try least square */
      solveOk = true;
      Eigen::LeastSquaresConjugateGradient<Eigen::SparseMatrix<double> > solver;
      solver.compute(A);
      x_u = solver.solve(b_u);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
      x_v = solver.solve(b_v);
      if (solver.info() != Eigen::ComputationInfo::Success) {
        Msg::Warning("failed to solve linear system with least-square (%li variables)", N);
        solveOk = false;
      }
    }

    for (size_t v = 0; v < nInterior; ++v) {
      uvs[v][0] = x_u[v];
      uvs[v][1] = x_v[v];
    }
    if (!solveOk) {
      Msg::Error("failed to solve linear system to solve uv");
      return false;
    }

#else 
    Msg::Error("solveLaplaceLinearSystem requires the EIGEN module");
    return -1;
#endif
    return true;
  }


  std::vector<MVertex*> boundaryFromSides(const std::vector<std::vector<MVertex*> >& sides) {
    std::vector<MVertex*> bnd;
    for (auto& side: sides) for (MVertex* v: side) {
      if (bnd.size() == 0 || (v != bnd.back() && v != bnd.front())) {
        bnd.push_back(v);
      }
    }
    return bnd;
  }

  bool getContinuousUVOnLoop(
      GFace* gf,
      const std::vector<MVertex*>& bndOrdered,
      std::vector<SPoint2>& bndUvs) {
    /* If periodic parametrization, get periods */
    double Ts[2] = {0.,0.};
    if (gf->periodic(0)) Ts[0] = gf->period(0);
    if (gf->periodic(1)) Ts[1] = gf->period(1);

    bndUvs.resize(bndOrdered.size());
    SPoint2 prev(DBL_MAX,DBL_MAX);
    double gapMax[2] = {0.,0.};
    for (size_t i = 0; i < bndOrdered.size(); ++i) {
      MVertex* v = bndOrdered[i];
      SPoint2 uv;
      setVertexGFaceUV(gf, v, uv.data());
      if (prev.x() != DBL_MAX) {
        for (size_t d = 0; d < 2; ++d) if (Ts[d] != 0.) {
          double diff = std::abs(uv.data()[d] - prev.data()[d]);
          if (diff > 0.5 * Ts[d]) { /* Probably got a period jump ! */
            double diffP = std::abs(uv.data()[d] + Ts[d] - prev.data()[d]);
            double diffN = std::abs(uv.data()[d] - Ts[d] - prev.data()[d]);
            if (diffP < diff) {
              uv.data()[d] += Ts[d];
            } else if (diffN < diff) {
              uv.data()[d] -= Ts[d];
            }
          }
          gapMax[d] = std::max(gapMax[d],std::abs(uv.data()[d] - prev.data()[d]));
        }
      }
      prev = uv;
      bndUvs[i] = uv;
    }
    if (Ts[0] > 0 && gapMax[0] > 0.5 * Ts[0]) {
      Msg::Debug("- uv laplacian smoothing because gap on boundary: %f (period %f)", gapMax[0], Ts[0]);
      return false;
    }
    if (Ts[1] > 0 && gapMax[1] > 0.5 * Ts[1]) {
      Msg::Debug("- uv laplacian smoothing because gap on boundary: %f (period %f)", gapMax[1], Ts[1]);
      return false;
    }
    return true;
  }

  bool laplacianSmoothingInParametricDomain(
      GFace* gf,
      const std::vector<MVertex*>& bndOrdered,
      const std::vector<MVertex*>& newVertices,
      const std::vector<MElement*>& newElements)
  {
    Msg::Debug("laplacian smoothing in param. domain, with %li new vertices and %li new quads... ", newVertices.size(), newElements.size());

    /* Build the old2new mapping */
    robin_hood::unordered_map<MVertex*,size_t> old2new;
    size_t vcount = 0;
    for (MVertex* v: newVertices) {
      old2new[v] = vcount;
      vcount += 1;
    }
    size_t nInterior = vcount;
    if (nInterior == 0) return true; /* nothing to smooth */
    vector<vector<size_t> > v2v(nInterior);
    for (MElement* f: newElements) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* vs[2] = {
          f->getVertex(le),
          f->getVertex((le+1)%4)
        };
        size_t nvs[2];
        for (size_t lv = 0; lv < 2; ++lv) {
          MVertex* v = vs[lv];
          size_t nv = NO_ID;
          auto it = old2new.find(v);
          if (it == old2new.end()) {
            old2new[v] = vcount;
            nv = vcount;
            vcount += 1;
          } else {
            nv = it->second;
          }
          nvs[lv] = nv;
        }
        if (nvs[0] < nInterior) v2v[old2new[vs[0]]].push_back(old2new[vs[1]]);
        if (nvs[1] < nInterior) v2v[old2new[vs[1]]].push_back(old2new[vs[0]]);
      }
      constexpr bool addDiags = false;
      if (addDiags) {
        for (size_t d = 0; d < 2; ++d) {
          MVertex* vs[2] = {
            f->getVertex(d),
            f->getVertex((d+2)%4)
          };
          size_t nvs[2] = {old2new[vs[0]],old2new[vs[1]]};
          if (nvs[0] < nInterior) v2v[old2new[vs[0]]].push_back(old2new[vs[1]]);
          if (nvs[1] < nInterior) v2v[old2new[vs[1]]].push_back(old2new[vs[0]]);
        }
      }
    }

    /* Get a continuous (without jumps) uv parametrization on
     * the cavity boundary */
    vector<SPoint2> bndUvs;
    bool okl = getContinuousUVOnLoop(gf, bndOrdered, bndUvs);
    if (!okl) {
      Msg::Debug("failed to get continuous UV on boundary loop");
      return false;
    }

    vector<SPoint2> uvs(vcount,SPoint2(DBL_MAX,DBL_MAX));
    for (size_t i = 0; i < bndOrdered.size(); ++i){
      MVertex* v = bndOrdered[i];
      auto it = old2new.find(v);
      if (it == old2new.end()) {
        Msg::Error("laplacianSmoothingInParametricDomain: boundary vertex not found in old2new");
        return false;
      }
      size_t idx = it->second;
      if (uvs[idx].x() != DBL_MAX) continue;
      uvs[idx] = bndUvs[i];
    }
    for (size_t v = 0; v < nInterior; ++v) {
      sort_unique(v2v[v]);
      uvs[v] = SPoint2(0.,0.);
    }

    /* Laplacian smoothing via linear system */
    bool ok = solveLaplaceLinearSystem(nInterior, v2v, uvs);
    if (!ok) {
      return false;
    }

    for (MVertex* v: newVertices) {
      size_t idx = old2new[v];
      SPoint2 uv = uvs[idx];
      v->setParameter(0,uv[0]);
      v->setParameter(1,uv[1]);
      GPoint p = gf->point(uv);
      if (p.succeeded()) {
        v->setXYZ(p.x(),p.y(),p.z());
      } else {
        Msg::Debug("CAD evaluation failed on face %i at uv=(%f,%f)",gf->tag(),uv[0],uv[1]);
        return false;
      }
    }

    return true;

    /* testing stuff */

    {
      double minSICN = DBL_MAX;
      double avgSICN = 0.;
      quadQualityStats(newElements, minSICN, avgSICN);
      DBG("arithmetic", minSICN, avgSICN);
    }

    size_t iter3D = 0;
    if (iter3D > 0) {
      vector<MVertex*> vertices(old2new.size(),NULL);
      for (auto& kv: old2new) {
        vertices[kv.second] = kv.first;
      }
      for (size_t i = 0; i < iter3D; ++i) {
        bool ok = solveLaplaceLinearSystemWith3DMetric(nInterior, v2v, vertices, uvs);
        if (!ok) {
          return false;
        }

        for (MVertex* v: newVertices) {
          size_t idx = old2new[v];
          SPoint2 uv = uvs[idx];
          v->setParameter(0,uv[0]);
          v->setParameter(1,uv[1]);
          GPoint p = gf->point(uv);
          if (p.succeeded()) {
            v->setXYZ(p.x(),p.y(),p.z());
          } else {
            Msg::Debug("CAD evaluation failed on face %i at uv=(%f,%f)",gf->tag(),uv[0],uv[1]);
            return false;
          }
        }

        {
          double minSICN = DBL_MAX;
          double avgSICN = 0.;
          quadQualityStats(newElements, minSICN, avgSICN);
          DBG("iter", iter3D, minSICN, avgSICN);
        }

      }
    }

    return true;
  }

  bool optimizeCavityGeometry(
      GFace* gf,
      const std::vector<MElement*> & oldElements,
      const std::vector<MVertex*>& bndOrdered,
      const std::vector<MElement*> & newElements,
      const std::vector<MVertex*> & newVertices,
      SurfaceProjector* sp = NULL,
      double qualityMin = 0.1,
      double qualityFactor = 0.5,
      bool tryUntangle = false,
      bool tryShapeImprovement = false) {

    /* Reference quality to improve */
    double minSICN_before = DBL_MAX;
    double avgSICN_before = 0.;
    double minSICN_after = -1.;
    double avgSICN_after = -1.;
    if (oldElements.size() > 0) {
      quadQualityStats(oldElements, minSICN_before, avgSICN_before);
    } else {
      minSICN_before = 0.;
    }
    quadQualityStats(newElements, minSICN_after, avgSICN_after);

    /* Initial smoothing */
    bool ok = false;
    if (newVertices.size() > 0) {
      bool smoothingInParam = parametrizationAvailable(gf);
      if (gf->geomType() == GEntity::Sphere) smoothingInParam = false;
      if (smoothingInParam) {
        /* Smooth in uv parameters */
        ok = laplacianSmoothingInParametricDomain(gf, bndOrdered, newVertices, newElements);
      } else {
        /* Use oldElements as a geometric support */
        size_t iter = std::min((size_t)newVertices.size(),(size_t)100);
        if (iter < 20) iter = 20;
        ok = laplacianSmoothingWithProjection(gf, oldElements, newVertices, newElements, iter);
      }
      if (ok) {
        quadQualityStats(newElements, minSICN_after, avgSICN_after);
        Msg::Debug("- smoothing of (%li quads, %li free vertices): SICN min: %f -> %f, avg: %f -> %f", 
            newElements.size(), newVertices.size(), minSICN_before, minSICN_after, avgSICN_before, avgSICN_after);
      } else {
        Msg::Debug("- smoothing of (%li quads, %li free vertices): failed", 
            newElements.size(), newVertices.size());
      }
    }

    if (!tryUntangle && !tryShapeImprovement){
      bool keep = true;
      if (oldElements.size() > 0) {
        if (minSICN_after < qualityMin) keep = false;
        if (minSICN_after < qualityFactor * minSICN_before) keep = false;
      }
      Msg::Debug("- mesh optim of (%li quads, %li free vertices): keep=%i, SICN min: %f -> %f, avg: %f -> %f", 
          newElements.size(), newVertices.size(), int(keep), minSICN_before, minSICN_after, avgSICN_before, avgSICN_after);
      return keep;
    }

    /* Untangling */
    if (tryUntangle && minSICN_after < 0. && newVertices.size() > 0 && sp) {
      MesquiteOptions opt;
      opt.smoother = MesquiteUntangler;
      opt.cpu_time_limit_sec = 5;
      if (newVertices.size() < 10) opt.cpu_time_limit_sec = 0.5 * double(newVertices.size());
      int status = optimizeQuadCavity(opt, sp, newElements, newVertices,
          minSICN_after, avgSICN_after);
      double minSICNb = minSICN_after;
      double avgSICNb = avgSICN_after;
      if (status == 0) {
        Msg::Debug("- untangling (Mesquite) of (%li quads, %li free vertices): SICN min: %f -> %f, avg: %f -> %f", 
            newElements.size(), newVertices.size(), minSICNb, minSICN_after, avgSICNb, avgSICN_after);
        tryShapeImprovement = false; /* shape improvement done just after untangling in optimizeQuadCavity */
      } else {
        Msg::Debug("- untangling (Mesquite) of (%li quads, %li free vertices): failed", 
            newElements.size(), newVertices.size());
      }
    }

    /* Optimization */
    if (tryShapeImprovement && newVertices.size() > 0 && minSICN_after > 0.) {
      MesquiteOptions opt;
      opt.smoother = MesquiteShapeImprovement;
      int status = optimizeQuadCavity(opt, sp, newElements, newVertices,
          minSICN_after, avgSICN_after);
      double minSICNb = minSICN_after;
      double avgSICNb = avgSICN_after;
      if (status == 0) {
        Msg::Debug("- shape improvement (Mesquite) of (%li quads, %li free vertices): SICN min: %f -> %f, avg: %f -> %f", 
            newElements.size(), newVertices.size(), minSICNb, minSICN_after, avgSICNb, avgSICN_after);
      } else {
        Msg::Debug("- shape improvement (Mesquite) of (%li quads, %li free vertices): failed", 
            newElements.size(), newVertices.size());
      }
    }

    bool keep = true;
    if (oldElements.size() > 0) {
      if (minSICN_after < qualityMin) keep = false;
      if (minSICN_after < qualityFactor * minSICN_before) keep = false;
    }
    Msg::Debug("- mesh optim of (%li quads, %li free vertices): keep=%i, SICN min: %f -> %f, avg: %f -> %f", 
        newElements.size(), newVertices.size(), int(keep), minSICN_before, minSICN_after, avgSICN_before, avgSICN_after);
    return keep;
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

  // WIP: the quantization should takes the geometry into account !
  // double checkPatternMatchingWithGeometry(
  //     const QuadMeshPattern& P, 
  //     GFace* gf,
  //     SurfaceProjector* sp,
  //     const std::vector<std::vector<MVertex*> >& sides) {

  //   std::vector<MVertex*> corners;
  //   for (auto& side: sides) corners.push_back(side[0]);

  //   size_t cc = 0;
  //   robin_hood::unordered_node_map<size_t,MVertex*> pVertexToCorner;
  //   for (size_t i = 0; i < P.n; ++i) if (P.vOnBdr[i] && P.v2e[i].size() == 2) {
  //     if (cc >= corners.size()) {
  //       DBG("BAD !", cc, corners.size());
  //       return -1;
  //     }
  //     pVertexToCorner[i] = corners[cc];
  //     cc += 1;
  //   }
  //   if (cc != corners.size()) {
  //     DBG("BAD matching !", cc, corners.size());
  //     return -1;
  //   }


  //   /* Create a quad mesh to smooth */

  //   vector<MElement*> pQuads;
  //   vector<MElement*> pVerices;

  //   /* Place the convex corners */
  //   for (size_t i = 0; i < P.n; ++i) {
  //     MVertex* v = NULL;
  //     if (P.vOnBdr[i] && P.v2e[i].size() == 2) {
  //       MVertex* cv = pVertexToCorner[i];
  //       double uv[2];
  //       setVertexGFaceUV(gf,cv,uv);
  //       v = new MFaceVertex(cv->x(),cv->y(),cv->z(),gf,uv[0],uv[1]);
  //     } else {
  //       v = new MFaceVertex(0.,0.,0.,gf,0.,0.);
  //     }
  //   }


  //   return 0.;
  // }

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


  bool load_patterns() {
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

  bool load_disk_quadrangulations() {
    if (B_disk_quadrangulations.size() != 0) return false;
    {
      Msg::Info("loading disk quadrangulations ...");
      B_disk_quadrangulations.reserve(20);
      B_BVL_ids.reserve(20);
      std::string data(disk_quadrangulations);
      vector<std::string> lines = SplitString(data,'\n');
      Quadrangulation qdrl;
      vector<std::string> numbers;
      vector<id> bdrValLoop;
      for (size_t i = 0; i < lines.size(); ++i) {
        numbers = SplitString(lines[i],' ');
        if (numbers.size() < 7) continue;
        size_t B = std::stoi(numbers[0]);
        size_t I = std::stoi(numbers[1]);
        size_t Q = std::stoi(numbers[2]);
        if (numbers.size() != 3 + 4 * Q) {
          Msg::Warning("load_disk_quadrangulations | wrong sizes: B=%li, I=%li, Q=%li and numbers.size = %li",
              B, I, Q, numbers.size());
          continue;
        }
        qdrl.resize(Q);
        for (size_t j = 0; j < Q; ++j) {
          for (size_t lv = 0; lv < 4; ++lv) {
            qdrl[j][lv] = std::stoi(numbers[3 + 4 * j + lv]);
          }
        }

        if (B >= B_disk_quadrangulations.size()) {
          B_disk_quadrangulations.resize(B+1);
          B_disk_quadrangulations[B].reserve(1000);
          B_BVL_ids.resize(B+1);
        }

        id qId = B_disk_quadrangulations[B].size();
        B_disk_quadrangulations[B].push_back(qdrl);

        /* Assumes:
         * - first B vertices are on the boundary 
         * - canonical valence ordering according to boundary valence loop 
         *   (should be compatible with the generator) */
        bdrValLoop.clear();
        bdrValLoop.resize(B,0);
        for (size_t j = 0; j < Q; ++j) for (size_t lv = 0; lv < 4; ++lv){
          id v = qdrl[j][lv];
          if (v < B) bdrValLoop[v] += 1;
        }
        B_BVL_ids[B][bdrValLoop].push_back(qId);
      }
      Msg::Info("%li disk quadrangulations loaded", lines.size());
    }
    return true;
  }




  bool patchIsRemeshableWithQuadPattern(
      const std::vector<size_t>& patternsToCheck,
      size_t Ncorners,
      const std::vector<size_t>& sideSizes, 
      std::pair<size_t,int>& patternNoAndRot,
      double& irregularityMeasure
      ) {
    irregularityMeasure = DBL_MAX;
    if (patterns.size() == 0) {
      Msg::Error("patterns not loaded, please call load_patterns() before");
      return false;
    }
    // DBG("---");
    // DBG("isRemeshable ?", Ncorners, sideSizes);

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
      // DBG("-",i,score);
    }
    // DBG("isRemeshable?", best, patternNoAndRot);

    irregularityMeasure = irreg_min;
    return (irreg_min != DBL_MAX);
  }

  bool gfaceContainsSeamCurves(GFace* gf) {
    for (GEdge* ge: gf->edges()) if (ge->isSeam(gf)) {
      return true;
    }
    return false;
  }

  bool reorientQuadAccordingToCavityBoundary(
      const std::vector<std::vector<MVertex*> >& sides, /* vertices on the boundary, not changed */
      std::vector<MElement*>& newElements               /* new quads inside the cavity */
      ) {
    robin_hood::unordered_set<id2,id2Hash> oedges;
    for (auto& side : sides) if (side.size() >= 2) {
      oedges.insert({(id)side[0]->getNum(),(id)side[1]->getNum()});
    }
    bool found = false;
    bool orientation_ok = true;
    for (MElement* f: newElements) {
      for (size_t le = 0; le < 4; ++le) {
        id v1 = (id) f->getVertex(le)->getNum();
        id v2 = (id) f->getVertex((le+1)%4)->getNum();
        id2 vPair = {v1,v2};
        auto it = oedges.find(vPair);
        if (it != oedges.end()) {
          found = true;
          orientation_ok = true;
          break;
        }
        id2 vPairInv = {v2,v1};
        auto it2 = oedges.find(vPairInv);
        if (it2 != oedges.end()) {
          found = true;
          orientation_ok = false;
          break;
        }
      }
      if (found) break;
    }
    if (!found) {
      Msg::Error("common edge not found ! cannot check orientation");
    }
    if (!orientation_ok) { /* Invert quads ! */
      for (MElement* f: newElements) {
        MVertex* v1 = f->getVertex(1);
        MVertex* v3 = f->getVertex(3);
        f->setVertex(1,v3);
        f->setVertex(3,v1);
      }
    }
    return true;
  }

  bool verticesStrictlyInside(const std::vector<MElement*>& quads,
      const std::vector<MVertex*>& bnd, std::vector<MVertex*>& inside) {
    std::vector<MVertex*> vert;
    vert.reserve(4*quads.size());
    for (MElement* f: quads) for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = f->getVertex(lv);
      vert.push_back(v);
    }
    sort_unique(vert);
    inside = difference(vert,bnd);
    return true;
  }

  int clearStuff(std::vector<MVertex*>& newVertices,
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
    return -1;
  }

  int remeshPatchWithQuadPattern(
      GFace* gf, 
      const std::vector<std::vector<MVertex*> >& sides, /* vertices on the boundary, not changed */
      const std::pair<size_t,int>& patternNoAndRot,     /* pattern to use, from patchIsRemeshableWithQuadPattern */
      std::vector<MElement*> & oldElements,             /* elements to replace */
      std::vector<MVertex*>& newVertices,               /* new vertices inside the cavity */
      std::vector<bool>& vertexIsIrregular,             /* for each new vertex, true if irregular */
      std::vector<MElement*>& newElements,              /* new quads inside the cavity */
      SurfaceProjector* sp,                             /* a quick way to project on GFace triangulation */
      double qualityMin,                                /* only remesh if resulting quality > qualityMin */
      double qualityFactor                              /* only remesh if quality > qualityDegradeFactor * qualityBefore */
      ) {

    size_t N = sides.size();
    const QuadMeshPattern& P = patterns[patternNoAndRot.first];
    int rot = patternNoAndRot.second;
    if (P.sides.size() != N) {
      Msg::Error("sides not matching, shoud not happen (pattern has %li sides, but %li sides in input) ...", P.sides.size(), N);
      return -1;
    }

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

    vector<size_t> ssr(sidesr.size());
    for (size_t i = 0; i < sidesr.size(); ++i) ssr[i] = sidesr[i].size();
    vector<int> slt;
    double match = checkPatternMatching(P, ssr, slt);
    if (match <= 0.) {
      Msg::Error("given pattern not marching sides, weird... N=%li", N);
      DBG(patternNoAndRot);
      DBG(match);
      DBG(ssr);
      return -1;
    }

    /* Add the new vertices and quads in the GFace */
    MVertex* oldCenter = centerOfElements(oldElements);
    bool oka = addQuadsAccordingToPattern(P, slt, gf, sidesr, newVertices, vertexIsIrregular, newElements, oldCenter, sp);
    if (!oka) {
      Msg::Error("failed to add quads according to pattern, weird");
      clearStuff(newVertices,newElements);
      return -1;
    }

    bool oko = reorientQuadAccordingToCavityBoundary(sides, newElements);
    if (!oko) {
      Msg::Error("failed to orient quads according to input boundary, weird");
      clearStuff(newVertices,newElements);
      return -1;
    }

    /* Check quality before / after */
    vector<MVertex*> bnd = boundaryFromSides(sides);
    bool tryUntangle = false;
    bool tryShapeImprovement = false;
    bool okGeom = optimizeCavityGeometry(gf,oldElements, bnd, newElements, newVertices, sp,
        qualityMin, qualityFactor, tryUntangle, tryShapeImprovement);
    if (!okGeom) {
      Msg::Debug("cavity remeshing: cancel because of element quality");
      clearStuff(newVertices,newElements);
      return -1;
    }

    /* Add new vertices and elements to GFace */
    for (MVertex* v: newVertices) gf->addMeshVertex(v);
    for (MElement* e: newElements) gf->addQuadrangle(dynamic_cast<MQuadrangle*>(e));

    /* Remove old vertices and elements */
    std::vector<MVertex*> inside;
    {
      vector<MVertex*> bnd;
      for (auto& side: sides) for (MVertex* v: side) {
        bnd.push_back(v);
      }
      sort_unique(bnd);
      std::vector<MVertex*> vert;
      vert.reserve(4*oldElements.size());
      for (MElement* f: oldElements) for (size_t lv = 0; lv < f->getNumVertices(); ++lv) {
        MVertex* v = f->getVertex(lv);
        vert.push_back(v);
      }
      sort_unique(vert);
      inside = difference(vert,bnd);
    }
    for (MElement* elt: oldElements) {
      gf->removeElement(elt->getType(),elt);
      delete elt;
    }
    for (MVertex* v: inside) {
      GEntity* entity = v->onWhat();
      if (entity != NULL) {
        auto it = std::find(entity->mesh_vertices.begin(),entity->mesh_vertices.end(),v);
        if (it != entity->mesh_vertices.end()) {
          entity->mesh_vertices.erase(it);
        } else {
          Msg::Error("remeshPatchWithQuadPattern | vertex (num %li) not found in its GEntity (tag = %i, dim = %i), weird", v->getNum(), entity->tag(), entity->dim());
          // BUG HERE ? Should build GFaceDiff, valid it, then execute it 
        }
      } else {
        Msg::Error("remeshPatchWithQuadPattern | vertex (num %li) not in a GEntity ? weird", v->getNum());
      }
      delete v;
    }

    return 0; /* ok ! */
  }

  void printPatternUsage() {
    Msg::Info("disk quadrangulation remeshing stats: %li distinct patterns used", usage_count.size());
  }

  int remeshFewQuads(GFace* gf, 
      const std::vector<MVertex*>& bnd,
      const std::vector<MElement*> & oldElements,              /* old quads inside the cavity */
      const std::vector<int>& bndIdealValence,
      const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
      std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
      std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
      std::vector<MElement*> & newElements,              /* new quads inside the cavity */
      SurfaceProjector* sp,
      double qualityMin,                                 /* only remesh if resulting quality > qualityMin */
      double qualityFactor,                              /* only remesh if quality > qualityDegradeFactor * qualityBefore */
      const std::vector<MElement*>& neighborsForGeometry
      ) {

    if (B_disk_quadrangulations.size() == 0) {
      Msg::Error("disk quadrangulations not loaded, please call load_disk_quadrangulations() before");
      return false;
    }

    const vector<vector<id4> >* small_patterns = NULL;
    if (bnd.size() < B_disk_quadrangulations.size() && B_disk_quadrangulations[bnd.size()].size() > 0) {
      small_patterns = &(B_disk_quadrangulations[bnd.size()]);
    } else {
      Msg::Error("no pattern for input size (%li bnd vertices)", bnd.size());
      return 1;
    }

    const vector<vector<id4> >& qmeshes = *small_patterns;

    vector<int> valence;

    std::vector<std::pair<double,std::pair<size_t,int> > > irregularity_pattern_rotation;
    for (size_t i = 0; i < qmeshes.size(); ++i) {
      const vector<id4>& quads = qmeshes[i];
      computeQuadMeshValences(quads, valence);
      double irregularity = DBL_MAX;
      int rotation = 0;
      bool found = computeBestMatchingConfiguration(quads, valence, bndIdealValence, bndAllowedValenceRange, rotation, irregularity);
      if (found) {
        // DBG("  ", i, rotation, irregularity);
        irregularity_pattern_rotation.push_back({irregularity,{i,rotation}});
      }
    }
    if (irregularity_pattern_rotation.size() == 0) {
      Msg::Debug("remeshFewQuads: no pattern matching input allowed valence range");
      // DBG("  ", bnd.size());
      // DBG("  ", bndIdealValence);
      // DBG("  ", bndAllowedValenceRange);
      return 1; /* no pattern matching allowed valence range */
    }

    /* Apply best pattern */
    std::sort(irregularity_pattern_rotation.begin(),irregularity_pattern_rotation.end());
    size_t no = irregularity_pattern_rotation[0].second.first;
    int rotation = irregularity_pattern_rotation[0].second.second;

    const vector<id4>& quads = qmeshes[no];
    computeQuadMeshValences(quads, valence);
    bool ok = applyPatternToRemeshFewQuads(gf, bnd, bndIdealValence, bndAllowedValenceRange, rotation,
        quads, valence, newVertices, vertexIsIrregular, newElements);
    if (!ok) {
      Msg::Debug("failed to remesh small cavity (%li bnd vertices) with %li quads", bnd.size(), newElements.size());
      return -1;
    }

    /* Check geometry */
    bool tryUntangle = true;
    bool tryShapeImprovement = true;
    bool okGeom = optimizeCavityGeometry(gf, oldElements, bnd, newElements, newVertices, sp,
        qualityMin, qualityFactor, tryUntangle, tryShapeImprovement);
    if (!okGeom) {
      Msg::Debug("small cavity remeshing: initially invalid because of element quality");

      if (neighborsForGeometry.size() > 0) {
        Msg::Debug("small cavity remeshing: try untangling on extended cavity (+%li quads)", neighborsForGeometry.size());
        /* Try with enlarging the untangling/smoothing cavity */
        std::vector<MElement*> newElements2 = newElements;
        for (MElement* e: neighborsForGeometry) newElements2.push_back(e);
        std::vector<MVertex*> bnd2;
        bool okb = buildBoundary(newElements2,bnd2);
        if (!okb) return clearStuff(newVertices,newElements);
        std::vector<MVertex*> inside;
        bool oki = verticesStrictlyInside(newElements2, bnd2, inside);
        if (!oki) return clearStuff(newVertices,newElements);
        /* Save current position */
        robin_hood::unordered_map<MVertex*,SPoint3> posBefore;
        for (MVertex* v: bnd) posBefore[v] = v->point();
        /* Optimize geometry */
        okGeom = optimizeCavityGeometry(gf, oldElements, bnd2, newElements2, inside, sp,
            qualityMin, qualityFactor, tryUntangle, tryShapeImprovement);
        if (okGeom) {
          Msg::Debug("small cavity remeshing: good !");
        } else {
          /* Restore position */
          for (MVertex* v: bnd) {
            SPoint3 pos = posBefore[v];
            v->setXYZ(pos.x(),pos.y(),pos.z());
          }
          Msg::Debug("small cavity remeshing: still invalid");
        }
      }

      if (!okGeom) return clearStuff(newVertices,newElements);
    }

    Msg::Debug("successfully remeshed small cavity (%li -> %li quads)", oldElements.size(), newElements.size());
    Msg::Debug("----");
    return 0;
  }

}
