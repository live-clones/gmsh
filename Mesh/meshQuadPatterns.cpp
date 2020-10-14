// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <iostream>
#include "meshQuadQuasiStructured.h"
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"

#include "meshRefine.h"
#include "Generator.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Field.h"
#include "geolog.h"
#include "meshWinslow2d.h"
#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing
#include "row_echelon_integer.hpp"
#include "meshQuadData.hpp"
#include "StringUtils.h"


#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;

namespace QuadPatternMatching {
  using id = uint32_t;
  using id2 = std::array<id,2>;
  using id4 = std::array<id,4>;


  /* Quad meshes of patterns, known at compile time */
  /* WARNING: orientation of quads must be coherent ! */
  const std::vector<std::vector<id4> > quad_meshes = {
    /* regular quad patch */
    {{0,1,2,3}},

    /* triangular patch with one val3 singularity */
    {{0,1,6,5},{1,2,3,6},{3,4,5,6}}, 

    /* pentagonal patch with one val5 singularity */
    {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}},

    /* quad patch with one val3 and one val5 singularities (on diagonal) */
    {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {8, 9, 10, 11}},

    /* quad patch with one val3, one val5 singularities and two regular inside (3-5 pair for size transition) */
    {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {9, 10, 12, 11}, {3, 13, 12, 10}, {8, 9, 11, 14}, {2, 15, 13, 3}},

    /* quad patch with two val3, two val5 inside, size transition by having a chord making a U-turn */
    {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 7, 6, 5}, {0, 9, 8, 7}, {0, 3, 10, 9}, {9, 10, 12, 11}, {9, 11, 14, 13}, {8, 9, 13, 15}, {6, 7, 8, 15}},

    /* patch with two corners, two val3 singularities inside (good for eye shape) */
    {{0, 1, 2, 3}, {0, 5, 4, 1}, {0, 3, 6, 5}, {4, 5, 6, 7}},

  };

  /* Quad meshes of patterns that have valence 3 on the boundary
   * WARNING: orientation of quad mesh must be coherent
   * Should be used carefully (because increase the valence on the cavity bdr)
   * Useful to remove high valence (e.g. 6) vertices from the quad mesh */

  /* To replace internal valence 6. The first 12 vertices (v = 0 .. 11) must be on the boundary */
  const std::vector<std::vector<id4> > quad_meshes_12bdr = {
    /* 6-sides pattern with 3 regular vertices inside, 8 quads */
    { { 0, 1, 2,12}, { 2, 3,13,12}, { 3, 4,14,13}, { 4, 5, 6,14}, { 6, 7, 8,14}, { 8, 9,13,14}, { 9,10,12,13}, { 0,12,10,11}, },
    /* 6-sides pattern with 2 regular vertices inside, 7 quads */
    { { 0, 1, 2,12}, { 2, 3, 4,13}, { 4, 5, 6,13}, { 6, 7, 8,13}, { 8, 9,10,12}, { 0,12,10,11}, { 2,13, 8,12}, },
    /* 6-sides pattern with 2 vertices inside (val 3 and val 5), 7 quads */
    { { 0, 1, 2,12}, { 2, 3, 4,12}, { 4, 5, 6,13}, { 6, 7, 8,13}, { 8, 9,10,12}, { 0,12,10,11}, { 4,13, 8,12}, },
  };

  /* To replace boundary valence 3. The first 8 vertices (v = 0 .. 7) must be on the boundary */
  const std::vector<std::vector<id4> > quad_meshes_8bdr = {
    /* 8 boundary edges, one internal vertex, split the top */
    { {0,1,2,8}, {2,3,4,8}, {4,5,6,8}, {0,8,6,7}, },
    /* 8 boundary edges, no internal vertex */
    { {0,1,2,5}, {2,3,4,5}, {0,5,6,7}, },
    /* 8 boundary edges, 2 internal vertices, split both sides */
    { {0,1,2,8}, {2,3,9,8}, {3,4,5,9}, {5,6,8,9}, {0,8,6,7}, },
  };

  /* To replace boundary valence 4. The first 10 vertices (v = 0 .. 9) must be on the boundary */
  const std::vector<std::vector<id4> > quad_meshes_10bdr = {
    /* 10 boundary edges, one internal vertex */
    { {0,1,2,10}, {2,3,4,10}, {4,5,6,10}, {6,7,8,10}, {0,10,8,9}, },
    /* 10 boundary edges, 2 internal vertices */
    { {0,1,2,10}, {2,3,11,10}, {3,4,5,11}, {5,6,7,11}, {7,8,10,11}, {0,10,8,9}, },
    /* 10 boundary edges, 0 internal vertex */
    { {0,1,2,7}, {2,3,6,7}, {3,4,5,6}, {0,7,8,9}, },
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
  std::vector< std::unordered_map< std::vector<id>, std::vector<id>, vidHash > > B_BVL_ids;


  template<class T> 
    void sort_unique(std::vector<T>& vec) {
      std::sort( vec.begin(), vec.end() );
      vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
    }

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

  struct QuadMesh {
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

    bool load(const std::vector<id4>& quadVertices) {
      edges.reserve(2*quadVertices.size());
      quads.reserve(quadVertices.size());
      std::unordered_map<id2,id,id2Hash> vpair2e;
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
        for (id v0 = 0; v0 < n; ++v0) if (v2e[v0].size() == 2) {
          id v = v0;
          id e = NO_ID;
          do {
            if (v2e[v].size() == 2) { /* concave corner */
              sides.resize(sides.size()+1);
              cur_side = &sides.back();
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
      }

      return true;
    }
  };


  /* Patterns are initialized at runtime, by the call to load_patterns() */
  std::vector<QuadMesh> patterns;

  bool load_patterns() {
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      if (patterns.size() != 0) patterns.clear();
      Msg::Info("loading %li quad patterns", quad_meshes.size());
      patterns.resize(quad_meshes.size());
      for (size_t i = 0; i < quad_meshes.size(); ++i) {
        bool ok = patterns[i].load(quad_meshes[i]);
        if (!ok) {
          Msg::Error("mesh quad patterns, failed to init pattern no %i", i);
        }
      }
    }
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

    bool get_positive_solution(std::vector<int>& x) {
      x.clear();
      x.resize(n-1,0);
      vector<int> indices;
      indices.reserve(n);
      for (int i = m-1; i >= 0; --i) {
        indices.clear();
        int sum = 0;
        int total = -1 * get(i,n-1);
        DBG(i,total);
        for (int j = 0; j < n-1; ++j) {
          double v = get(i,j);
          DBG(v,x[j]);
          if (v != 0) {
            if (x[j] == 0) {
              indices.push_back(j);
              sum += v;
            } else {
              total -= v * x[j];
            }
          }
        }
        if (indices.size() == 0) {
          if (total == 0) {
            continue;
          } else {
            return false;
          }
        }
        if (indices.size() == 0) continue;
        DBG(sum,indices,total);
        for (size_t k = 0; k < indices.size(); ++k) {
          int j = indices[k];
          if (k == indices.size() - 1) {
            x[j] = total;
            DBG(j,"<---", x[j]);
            if (x[j] <= 0) return false;
          } else {
            int value = int(double(get(i,j)) / double(sum) * double(total));
            if (value > total) {
              Msg::Error("get_positive_solution | bad ...");
              return false;
            }
            DBG(j,"<---", value);
            if (value <= 0) return false;
            x[j] = value;
            total -= value;
          }
        }
      }

      return true;
    }
  };

  std::vector<MVertex*> createVertices (GFace* gf, MVertex *v1, MVertex *v2, int n) {
    std::vector<MVertex*> r;
    r.push_back(v1);
    for (int i=1;i<n;i++){
      double xi = (double)i/n;
      SPoint3 p ((1.-xi)*v1->x()+xi*v2->x(),(1.-xi)*v1->y()+xi*v2->y(),(1.-xi)*v1->z()+xi*v2->z());
      double uv[2] = {0.,0.};
      MVertex *vNew = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
      gf->mesh_vertices.push_back(vNew);
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
      const std::vector<MVertex*> &s0,
      const std::vector<MVertex*> &s1,
      const std::vector<MVertex*> &s2,
      const std::vector<MVertex*> &s3,
      std::vector<MElement*> &newQuads){
    std::vector< std::vector<MVertex*> > grid;
    grid.push_back(s0);
    std::vector<MVertex*> s3r = reverseVector(s3);
    for (size_t i=1;i<s3r.size()-1;i++){
      grid.push_back(createVertices(gf,s3r[i],s1[i],s0.size()-1));
    }
    grid.push_back(reverseVector(s2));


    for (size_t i=0;i<grid.size()-1;i++){
      for (size_t j=0;j<grid[i].size()-1;j++){
        MQuadrangle *q = new MQuadrangle (grid[i][j],grid[i+1][j],grid[i+1][j+1],grid[i][j+1]);
        newQuads.push_back(q);
        gf->quadrangles.push_back(q);
      }
    }    
  }

  bool addQuadsAccordingToPattern(
      const QuadMesh& P,
      const std::vector<int>& quantization,
      GFace* gf, 
      const std::vector<std::vector<MVertex*> >& sides, /* vertices on the boundary, not changed */
      std::vector<MVertex*>& newVertices,               /* new vertices inside the cavity */
      std::vector<bool>& vertexIsIrregular,             /* for each new vertex, true if irregular */
      std::vector<MElement*>& newElements               /* new quads inside the cavity */
      ) {

    std::unordered_map<id2, std::vector<MVertex*>, id2Hash> vpair2vertices;
    std::vector<MVertex*> v2mv(P.n,NULL);
    std::vector<MVertex*> vert;
    /* Associate exising vertices to pattern sides */

    for (size_t s = 0; s < sides.size(); ++s) {
      for (size_t k = 0; k < sides[s].size()-1; ++k) {
        vector<array<double,3>> pts = {SVector3(sides[s][k]->point()),SVector3(sides[s][k+1]->point())};
        vector<double> values = {double(k),double(k+1)};
        GeoLog::add(pts,values,"side_input_vert_"+std::to_string(s));
      }
    }

    for (size_t s = 0; s < P.sides.size(); ++s) {
      size_t pos = 0;
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        int n_e = quantization[P.eChordId[e]];
        vert.resize(n_e+1);
        for (size_t k = 0; k < (size_t) n_e+1; ++k) {
          if (pos+k>=sides[s].size()) {
            Msg::Error("issue, pos=%li + k=%li = %li >= sides[s].size()=%li", pos, k, sides[s].size());
            return false;
          }
          vert[k] = sides[s][pos+k];
        }
        pos += n_e;
        id v1 = P.edges[e][0];
        id v2 = P.edges[e][1];
        if (v2mv[v1] == NULL) v2mv[v1] = vert.front();
        if (v2mv[v2] == NULL) v2mv[v2] = vert.back();

        {
          vector<array<double,3>> pts = {SVector3(v2mv[v1]->point()),SVector3(v2mv[v2]->point())};
          vector<double> values = {0.,1.};
          GeoLog::add(pts,values,"side_"+std::to_string(s)+"_"+std::to_string(j));
        }
        {
          for (size_t k = 0; k < vert.size()-1; ++k) {
            vector<array<double,3>> pts = {SVector3(vert[k]->point()),SVector3(vert[k+1]->point())};
            vector<double> values = {double(k),double(k+1)};
            GeoLog::add(pts,values,"side_vert_"+std::to_string(s)+"_"+std::to_string(j));
          }
        }
        DBG(s,j,e,n_e,pos-n_e,pos,v1,v2,vert,vert.size());
        DBG("  ", sides[s].size());

        id2 vpair = sorted(v1,v2);
        if (v1 < v2) {
          vpair2vertices[vpair] = vert;
        } else {
          std::reverse(vert.begin(),vert.end());
          vpair2vertices[vpair] = vert;
        }
      }
    }
    GeoLog::flush();

    /* Create vertices on internal points */
    for (size_t v = 0; v < P.n; ++v) if (!P.vOnBdr[v]) {
      GPoint pp(0,0,0);
      MVertex *sing = new MFaceVertex(pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
      gf->mesh_vertices.push_back(sing);
      newVertices.push_back(sing);
      bool irregular = true; // TODO !
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
        vpair2vertices[vpair] = createVertices (gf, mv1, mv2, n_e);
      } else {
        vpair2vertices[vpair] = createVertices (gf, mv2, mv1, n_e);
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
        {
          for (size_t k = 0; k < quadCurves[le].size()-1; ++k) {
            vector<array<double,3>> pts = {SVector3(quadCurves[le][k]->point()),SVector3(quadCurves[le][k+1]->point())};
            vector<double> values = {double(k),double(k+1)};
            GeoLog::add(pts,values,"quad_"+std::to_string(f));

          }
        }
      }
      GeoLog::flush();
      createQuadPatch(gf, quadCurves[0], quadCurves[1], quadCurves[2], quadCurves[3], newElements);
    }

    return true;
  }

  bool load_disk_quadrangulations() {
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      if (B_disk_quadrangulations.size() != 0) {
        B_disk_quadrangulations.clear();
        B_BVL_ids.clear();
      }
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
    /* Rotation in forward order */
    int rot = 0;
    vector<int> biv = bndIdealValence;
    vector<std::pair<int,int>>  bav = bndAllowedValenceRange;
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

    std::unordered_map<id,MVertex*> pv2mv;
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
      gf->quadrangles.push_back(q);
    }

    return true;
  }

  bool laplacianSmoothing(
    const std::vector<MVertex*>& newVertices,
    const std::vector<MElement*>& newElements,
    size_t iter = 10) {

    std::unordered_map<MVertex*,std::set<MVertex*>> v2v;
    for (MElement* f: newElements) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v1 = f->getVertex(le);
        MVertex* v2 = f->getVertex((le+1)%4);
        v2v[v1].insert(v2);
        v2v[v2].insert(v1);
      }
    }
    for (size_t i = 0; i < iter; ++i) {
      for (MVertex* v: newVertices) {
        SVector3 avg(0.,0.,0.);
        double sum = 0.;
        for (MVertex* v2: v2v[v]) {
          avg += v2->point();
          sum += 1.;
        }
        if (sum == 0) continue;
        v->x() = 1./sum * avg.x();
        v->y() = 1./sum * avg.y();
        v->z() = 1./sum * avg.z();
      }
    }

    return true;
  }

}

using namespace QuadPatternMatching;


int remeshPatchWithQuadPattern(
    GFace* gf, 
    const std::vector<std::vector<MVertex*> >& sides, /* vertices on the boundary, not changed */
    std::vector<MVertex*>& newVertices,               /* new vertices inside the cavity */
    std::vector<bool>& vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*>& newElements               /* new quads inside the cavity */
    ) {
  if (patterns.size() == 0) load_patterns();

  size_t N = sides.size();
  DBG(N);
  for (size_t i = 0; i < patterns.size(); ++i) {
    // TODO: rotation of patterns
    //       -> extract side sizes from "sides", rotate them to try solving system
    //          if ok, apply rotation to 'sides', call addQuadsAccordingToPattern()
 
    // DBG("");
    // DBG(i,patterns[i].edges);
    // DBG(i,patterns[i].quads);
    // DBG(i,patterns[i].sides);
    // DBG(i,patterns[i].chords);

    QuadMesh& P = patterns[i];
    if (P.sides.size() != N) continue;
    bool possible = true;
    for (size_t s = 0; s < N; ++s) {
      if (sides[s].size() < P.sides[s].size() + 1) {
        /* on given side, less edges in the cavity than edges in the pattern */
        possible = false; break;
      }
    }
    if (!possible) continue;

    DBG("matching", N, P.sides);
    for (size_t s = 0; s < N; ++s) {
      printf("side %li |  ", s);
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        id var = P.eChordId[e];
        printf("+ n[%i]", var);
      }
      printf(" =  %li \n", sides[s].size()-1);
    }


    int nvars = 0;
    for (id v: P.eChordId) nvars = std::max(nvars,(int)v+1);
    IMatrix mat(N,nvars+1);
    for (size_t s = 0; s < N; ++s) {
      for (size_t j = 0; j < P.sides[s].size(); ++j) {
        id e = P.sides[s][j];
        id var = P.eChordId[e];
        mat.set(s,var,1);
      }
      mat.set(s,nvars,-1. * (sides[s].size()-1));
    }

//    IMatrix mat(4,6);
//
//    mat.set(0,1,1);
//    mat.set(0,3,1);
//    mat.set(0,4,1);
//    mat.set(0,5,-12);
//
//    mat.set(1,0,1);
//    mat.set(1,1,1);
//    mat.set(1,2,1);
//    mat.set(1,5,-13);
//
//    mat.set(2,3,1);
//    mat.set(2,4,1);
//    mat.set(2,5,-10);
//
//    mat.set(3,0,1);
//    mat.set(3,2,1);
//    mat.set(3,5,-11);

    mat.print("before");
    int det = mat.tansform_to_row_reduced_echelon();
    mat.print("after");
    Msg::Info("pseudo-determinant: %i", det);
    vector<int> slt;
    bool ok = mat.get_positive_solution(slt);
    if (ok) {
      Msg::Info("solution found !");
      DBG(slt);
    } else {
      Msg::Error("no solution found");
      continue;
    }

    addQuadsAccordingToPattern(P, slt, gf, sides, newVertices, vertexIsIrregular, newElements);
    return 0;

    break;
  }


  return 1;
}

int remeshFewQuads(GFace* gf, 
    const std::vector<MVertex*>& bnd,
    const std::vector<int>& bndIdealValence,
    const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
    std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
    std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*> & newElements               /* new quads inside the cavity */
    ) {
  if (B_disk_quadrangulations.size() == 0) {
    load_disk_quadrangulations();
  }

  const vector<vector<id4> >* small_patterns = NULL;
  bool OLD = false;
  if (OLD) {
    if (bnd.size() == 12) {
      small_patterns = &quad_meshes_12bdr;
    } else if (bnd.size() == 8) {
      small_patterns = &quad_meshes_8bdr;
    } else if (bnd.size() == 10) {
      small_patterns = &quad_meshes_10bdr;
    } else {
      Msg::Error("no pattern for input (%li bnd vertices)", bnd.size());
      return 1;
    }
  } else {
    if (bnd.size() < B_disk_quadrangulations.size() && B_disk_quadrangulations[bnd.size()].size() > 0) {
      small_patterns = &(B_disk_quadrangulations[bnd.size()]);
    } else {
      Msg::Error("no pattern for input (%li bnd vertices)", bnd.size());
      return 1;
    }
  }

  const vector<vector<id4> >& qmeshes = *small_patterns;

  vector<int> valence;

  std::vector<std::pair<double,std::pair<size_t,int> > > irregularity_pattern_rotation;
  DBG(bnd.size(),qmeshes.size());
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
    Msg::Error("no pattern matching input");
    DBG("  ", bnd.size());
    DBG("  ", bndIdealValence);
    DBG("  ", bndAllowedValenceRange);

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
  if (ok) {
    Msg::Info("successfully remesh small cavity (%li bnd vertices) with %li quads", bnd.size(), newElements.size());
    laplacianSmoothing(newVertices, newElements,10);
    return 0;
  } else {
    Msg::Error("failed to remesh small cavity (%li bnd vertices) with %li quads", bnd.size(), newElements.size());
  }

  Msg::Info("failed to remesh small cavity (%li bnd vertices)", bnd.size());
  DBG(bnd);
  DBG(bndIdealValence);
  DBG(bndAllowedValenceRange);

  return 1;
}
