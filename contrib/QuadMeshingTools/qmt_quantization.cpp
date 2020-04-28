// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "quad_meshing_tools.h"

#include <cfloat>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "gmsh.h"

#include "qmt_utils.hpp"
#include "geolog.h"

/* - Shortcuts for loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {error(__VA_ARGS__); return false;} } while(0)

using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;
using gmsh::vectorpair;

namespace QMT {
  std::ostream& print_vec_uint8_t(std::ostream& os, const std::vector<uint8_t>& values) { 
    os << "[";
    for (size_t i = 0; i < values.size(); ++i) {
      os << (uint32_t)values[i];
      if (i != values.size() - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }


  std::ostream& operator<<(std::ostream& os, const QMT::TFace& face) { 
    os << "[edges=";
    QMT_Utils::operator<<(os,face.edges);
    os << ", edge_sides=";
    print_vec_uint8_t(os,face.edge_sides);
    os << ", origin=";
    os << face.origin;
    os << ", entity=";
    QMT_Utils::operator<<(os,face.entity);
    os << "]";
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const QMT::TEdge& edge) { 
    os << "[vertices=";
    QMT_Utils::operator<<(os,edge.vertices);
    os << ", nb pts=";
    os << edge.pts.size();
    os << ", origin=";
    os << edge.origin;
    os << ", entity=";
    QMT_Utils::operator<<(os,edge.entity);
    os << "]";
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const QMT::TVertex& tv) { 
    os << "[";
    QMT_Utils::operator<<(os,tv.pt);
    os << ", origin=";
    os << tv.origin;
    os << ", entity=";
    QMT_Utils::operator<<(os,tv.entity);
    os << "]";
    return os;
  }


  std::ostream& operator<<(std::ostream& os, const QMT::QTMesh& M) { 
    os << "------ QTMesh" << std::endl;
    os << M.vertices.size() << " vertices" << std::endl;
    os << M.edges.size() << " edges:" << std::endl;
    F(e,M.edges.size()) {
      os << "  " << e << ": " << M.edges[e] << std::endl;
    }
    os << M.faces.size() << " faces:" << std::endl;
    F(f,M.faces.size()) {
      os << "  " << f << ": " << M.faces[f] << std::endl;
    }
    return os;
  }
}

namespace QMT_QZ_Utils {
  using namespace QMT;
  using namespace QMT_Utils;

  bool global_gmsh_initialized = false;
  const bool ERROR_VISU = true;

  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Quantization | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Quantization | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Quantization | " + stream.str(), "info");
    }
  
  template <typename... Args>
    void debug(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Quantization | " + stream.str(), "debug");
    }
  /************************************/

  bool is_file(const char *fileName) {
    std::ifstream in(fileName);
    return in.good();
  }

  inline id2 sorted(id v1, id v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }

  struct id2Hash {
    size_t operator()(id2 p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };

  bool edgesToOrderedAndSignedPositions(const vector<id2>& edges, vector<int>& pos) {
    if (edges.size() < 2) return false;
    pos.clear();
    int eStart = 0;
    id vStart = edges[eStart][0];

    size_t iter = 0;
    id e = eStart;
    id v = vStart;
    while (true) {
      iter += 1;
      if (iter > 100000) {
        error("infinite loop ? iter = {}", iter);
        return false;
      }
      RFC(edges[e][0] == edges[e][1], "periodic edge not supported: edge = {}", edges[e]);
      if (edges[e][0] == v) {
        pos.push_back(e);
      } else if (edges[e][1] == v) {
        pos.push_back(-e);
      } else {
        error("should not happen");
        return false;
      }

      id next_v = (edges[e][0]  != v) ? edges[e][0] : edges[e][1];
      if (next_v == vStart) { /* closed chain */
        break;
      }
      id next_e = NO_ID;
      FC(ee,edges.size(),ee!=e) FC(lv,2,edges[ee][lv] == next_v) {
        next_e = ee;
        break;
      }
      v = next_v;
      e = next_e;
    }

    if (edges.size() != pos.size()) {
      error("edgesToOrderedAndSignedPositions: edges = {}, pos = {}", edges, pos);
      error("TODO: is this a periodic quad ? (two times the same edge, e.g. ring)");
      return false;
    }

    return true;
  }

  bool getOrderedVerticesFromEdges(id vStart, const vector<id2>& edges, vector<id>& orderedVertices) {
    orderedVertices.clear();
    id eStart = NO_ID;
    id lvStart = NO_ID;
    F(e,edges.size()) FC(lv,2,edges[e][lv] == vStart) {
      eStart = e;
      lvStart = lv;
      break;
    }
    if (eStart == NO_ID) return false;

    size_t iter = 0;
    id e = eStart;
    id v = vStart;
    while (true) {
      iter += 1;
      if (iter > 100000) {
        error("infinite loop ? iter = {}", iter);
        return false;
      }
      orderedVertices.push_back(v);
      id next_v = (edges[e][0]  != v) ? edges[e][0] : edges[e][1];
      if (next_v == vStart) { /* closed chain */
        break;
      }
      id next_e = NO_ID;
      FC(ee,edges.size(),ee!=e) FC(lv,2,edges[ee][lv] == next_v) {
        next_e = ee;
        break;
      }
      if (next_e == NO_ID) { /* open chain */
        orderedVertices.push_back(next_v);
        break;
      }
      v = next_v;
      e = next_e;
    }
    return true;
  }

  bool computeEdgeLoops(
      const vector<id2>& edges, 
      const vector<vector<id>>& v2e,
      const vector<bool>& isCorner,
      vector<vector<id>>& loop_edges,
      vector<vector<id>>& loop_vertices) {
    loop_edges.clear();
    loop_vertices.clear();
    if (v2e.size() != isCorner.size()) {
      return false;
    }

    /* Look for loops */
    vector<bool> done(edges.size(),false);
    bool remaining = true;
    while (remaining)  {
      remaining = false;
      vector<id> orderedVertices;
      vector<id> orderedEdges;
      id vStart = NO_ID;
      id eStart = NO_ID;
      FC(v,isCorner.size(),isCorner[v]) { /* Loops starting at corners */
        FC(le,v2e[v].size(),!done[v2e[v][le]]) {
          vStart = v;
          eStart = v2e[v][le];
          break;
        }
        if (vStart != NO_ID) break;
      }

      if (vStart == NO_ID) { /* Remaing closed loops ? */
        FC(e,edges.size(),!done[e]) {
          eStart = e;
          vStart = edges[e][0];
          break;
        }
      }

      if (vStart == NO_ID || eStart == NO_ID) {
        break;
      }

      size_t iter = 0;
      id e = eStart;
      id v = vStart;
      while (true) {
        done[e] = true;

        /* Check infinite loop */
        iter += 1;
        if (iter > 1e6 - 100) {
          warn("  e={},v={}",e,v);
        }
        if (iter > 1e6) {
          error("infinite loop ? iter = {}", iter);
          return false;
        }

        /* Push */
        orderedVertices.push_back(v);
        orderedEdges.push_back(e);

        /* Get next */
        id next_v = (edges[e][0]  != v) ? edges[e][0] : edges[e][1];
        id next_e = NO_ID;
        F(le,v2e[next_v].size()) {
          id ee = v2e[next_v][le];
          if (ee != e && !done[ee]) {
            next_e = ee;
            break;
          }
        }

        /* Check end of loop */
        if (isCorner[next_v]) { /* reached another corner */
          orderedVertices.push_back(next_v);
          break;
        } else if (next_v == vStart) { /* closed loop */
          orderedVertices.push_back(next_v);
          break;
        }

        if (next_e == NO_ID || next_v == NO_ID) {
          error("edge loop issue: next_e = {}, next_v = {}, isCorner[next_v] = {}, v2e[next_v] = {}", next_e, next_v, isCorner[next_v], v2e[next_v]);
          return false;
        }

        /* Propagate */
        v = next_v;
        e = next_e;
      } /* end of while loop */

      if (orderedVertices.size() >= 2) {
        remaining = true;
        loop_vertices.push_back(orderedVertices);
        loop_edges.push_back(orderedEdges);
      }
    }
    return true;
  }

  bool getSurfaceTriangles(int tag, vector<id>& triangleNums) {
    std::vector<int> elementTypes;
    std::vector<std::vector<size_t>> elementTags;
    std::vector<std::vector<size_t>> nodeTags;
    gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,2,tag);
    if (elementTypes.size() != 1) {
      error("elementTypes.size() = {}", elementTypes.size());
      return false;
    }
    F(i,elementTags[0].size()) {
      triangleNums.push_back(elementTags[0][i]);
    }
    return true;
  }

  /* warning: call gmsh API */
  bool getCurveOrderedVertices(int curve, vector<id>& vertices, vector<vec3>& points, vector<id>& lines, id vStart) {
    /* Points in the curve */
    std::vector<size_t> vert;
    std::vector<double> coords;
    std::vector<double> paramCoords;
    gmsh::model::mesh::getNodes(vert, coords, paramCoords, 1, std::abs(curve), true, false);

    /* Edges in the curve */
    std::vector<int> elementTypes;
    std::vector<std::vector<size_t>> elementTags;
    std::vector<std::vector<size_t>> nodeTags;
    gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,1,curve);
    if (elementTypes.size() != 1) {
      error("elementTypes.size() = {}", elementTypes.size());
      return false;
    }
    if (elementTags[0].size() != nodeTags[0].size()/2) {
      error("getCurveOrderedVertices | elementTags[0].size() = {}, nodeTags[0].size()");
      return false;
    }
    F(i,elementTags[0].size()) {
      lines.push_back(elementTags[0][i]);
    }
    vector<id2> edges;
    F(i,nodeTags[0].size()/2) {
      edges.push_back({id(nodeTags[0][2*i]),id(nodeTags[0][2*i+1])});
    }

    bool okov =  getOrderedVerticesFromEdges(vStart, edges, vertices);
    if (!okov) {
      error("failed to get ordered vertices");
      return false;
    }
    points.resize(vertices.size(),{DBL_MAX,DBL_MAX,DBL_MAX});
    F(i,vertices.size()) {
      bool found = false;
      FC(j,vert.size(),vert[j] == vertices[i]) {
        points[i] = {coords[3*j], coords[3*j+1], coords[3*j+2]};
        found = true;
        break;
      }
      if (!found) {
        error("getCurveOrderedVertices | curve {}, vertex {} not found in vert = {}", curve, vertices[i], vert);
        return false;
      }
    }

    return true;
  }

  bool transfinite_interpolation(
      const vector<vec3>& c1,
      const vector<vec3>& c2,
      const vector<vec3>& c3,
      const vector<vec3>& c4,
      vector<vec3>& pts) {
    if (c1.size() <= 2 || c2.size() <= 2 || c3.size() <= 2 || c4.size() <= 2) {
      error("cannot TFI, c1.size={}, c2.size={}, c3.size={}, c4.size={}", c1.size(),c2.size(),c3.size(),c4.size());
      return false;
    }
    if (c1.size() != c3.size() || c2.size() != c4.size()) {
      error("cannot TFI, c1.size={}, c2.size={}, c3.size={}, c4.size={}", c1.size(),c2.size(),c3.size(),c4.size());
      return false;
    }

    size_t Ni = c1.size()-2;
    size_t Nj = c2.size()-2;

    vector<vec3> c1_u, c3_u, c2_v, c4_v;
    c1_u = std::vector<vec3>(c1.begin()+1, c1.end()-1);
    c3_u = std::vector<vec3>(c3.begin()+1, c3.end()-1);
    c2_v = std::vector<vec3>(c2.begin()+1, c2.end()-1);
    c4_v = std::vector<vec3>(c4.begin()+1, c4.end()-1);
    std::reverse(c3_u.begin(),c3_u.end());
    std::reverse(c4_v.begin(),c4_v.end());

    pts.resize(Ni*Nj);
    F(i,Ni) F(j,Nj) {
      double u = (1.+i) / (1.+Ni);
      double v = (1.+j) / (1.+Nj);
      pts[Ni*j+i] = (1.-v) * c1_u[i] + v * c3_u[i] + (1.-u) * c4_v[j] + u * c2_v[j] 
        - ((1.-u)*(1.-v)*c1[0] + u*v*c3[0] + u * (1.-v) * c2[0] + (1.-u)*v*c4[0]);
    }

    return true;
  }

  double curve_length(const vector<vec3>& pts) {
    if (pts.size() <= 1) return 0.;
    double L = 0.;
    F(i,pts.size()-1) L += length(pts[i+1]-pts[i]);
    return L;
  }

  vector<double> curve_ts(const vector<vec3>& pts, double curveLength = DBL_MAX) {
    vector<double> ts;
    if (pts.size() <= 1) return {};
    if (curveLength == DBL_MAX) curveLength = curve_length(pts);
    double L = 0.;
    ts.push_back(0.);
    F(i,pts.size()-1) {
      L += length(pts[i+1]-pts[i]);
      ts.push_back(L/curveLength);
    }
    ts.back() = 1.;
    return ts;
  }

  vector<vec3> curve_interpolate(const vector<vec3>& pts, const vector<double>& ts, double curveLength = DBL_MAX) {
    if (curveLength == DBL_MAX) curveLength = curve_length(pts);
    vector<double> targetLens(ts.size(),0.);
    F(i, ts.size()) {
      double t = ts[i];
      if (t < 0. || t > 1.) {
        error("cannot interpolate on curve at i = {}, t = {} (must be in [0,1])", i, t);
        return {};
      }
      targetLens[i] = t * curveLength;
    }
    vector<double> uniqueTargetLens;
    vector<size_t> old2new;
    QMT_Utils::sort_unique_with_perm(targetLens, uniqueTargetLens, old2new);

    vector<vec3> ipts;
    size_t prev_j = 0;
    double prev_acc = 0.;
    F(i,uniqueTargetLens.size()) {
      double targetLen = uniqueTargetLens[i];
      bool found = false;
      double acc = prev_acc;
      for(size_t j = prev_j; j < pts.size()-1; ++j) {
        double len_j = acc;
        acc += length(pts[j+1]-pts[j]);
        double len_jp1 = acc;

        if (len_j < targetLen && targetLen <= len_jp1) {
          double lambda = (targetLen - len_j) / (len_jp1 - len_j);
          vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
          ipts.push_back(pt);
          found = true;
          prev_j = j;
          prev_acc = len_j;
          break;
        } else if (len_j == targetLen) {
          ipts.push_back(pts[j]);
          found = true;
          prev_j = j;
          prev_acc = len_j;
          break;
        }
      }
      if (!found) {
        error("curve_interpolate | {}-th point (t = {}, targetLen = {}, curveLength = {}) not found !", 
            i, ts[i], targetLen, curveLength);
        return {};
      }
    }
    if (uniqueTargetLens.size() != ipts.size()) {
      error("curve_interpolate | wrong sizes");
      return {};
    }

    vector<vec3> opts(ts.size());
    F(i,old2new.size()) {
      opts[i] = ipts[old2new[i]];
    }
    return opts;
  }


  inline id add_vertex(QMesh& M, vec3 pt, double size = DBL_MAX, std::pair<int,int> entity = {-1,-1}) {
    id v = M.points.size();
    M.points.push_back(pt);
    M.size.push_back(size);
    M.entity.push_back(entity);
    return v;
  }

  inline size_t add_quad(QMesh& M, id4 vert, id color, int ent) {
    id q = M.quads.size();
    M.quads.push_back(vert);
    M.color.push_back(color);
    M.quad_neighbors.push_back({NO_SID,NO_SID,NO_SID,NO_SID});
    M.quadEntity.push_back(ent);
    return q;
  }

  inline id2 edge_vertices(const TEdge& edge, bool invert) {
    if (invert) return {edge.vertices[1],edge.vertices[0]};
    return edge.vertices;
  }


  using namespace GLog;
  void debug_show_face_in_view(const QTMesh& M, id f, const std::string& viewName, const vector<id>& edge_n = {}) {
    const vector<id>& edges = M.faces[f].edges; 
    GeoLog log;
    F(le,edges.size()) {
      const TEdge& te = M.edges[edges[le]];
      double val = (edge_n.size() > 0) ? edge_n[edges[le]] : double(le);
      F(i,te.pts.size()-1) {
        log.add({te.pts[i],te.pts[i+1]},val,viewName);
      }
    }
    log.toGmsh();
  }

  void debug_show_edge_in_view(const QTMesh& M, id e, const std::string& viewName) {
    GeoLog log;
    const TEdge& te = M.edges[e];
    log.add({M.vertices[te.vertices[0]].pt},0.,viewName);
    log.add({M.vertices[te.vertices[1]].pt},0.,viewName);
    F(i,te.pts.size()-1) {
      log.add({te.pts[i],te.pts[i+1]},{double(i),double(i+1)},viewName);
    }
    log.toGmsh();
  }

  void debug_show_qtmesh_in_view(const QTMesh& M, const std::string& viewName) {
    GeoLog log;
    F(e,M.edges.size()) {
      const TEdge& te = M.edges[e];
      double val = double(e);
      F(i,te.pts.size()-1) {
        log.add({te.pts[i],te.pts[i+1]},val,viewName);
      }
    }
    log.toGmsh();
  }

  vec3 tedge_center(const QTMesh& M, id e, id shift = NO_ID) {
    vec3 p;
    if (M.edges[e].pts.size() < 5) {
      if (shift == 0) {
        p = 0.4 * M.edges[e].pts[0] + 0.6 * M.edges[e].pts[1];
      } else if (shift == 1) {
        p = 0.6 * M.edges[e].pts[0] + 0.4 * M.edges[e].pts[1];
      } else {
        p = 0.5 * (M.edges[e].pts[0] + M.edges[e].pts[1]);
      }
    } else {
      if (shift == 0) {
        p = M.edges[e].pts[M.edges[e].pts.size()/2+1];
      } else if (shift == 1) {
        p = M.edges[e].pts[M.edges[e].pts.size()/2-1];
      } else {
        p = M.edges[e].pts[M.edges[e].pts.size()/2];
      }
    }

    return p;
  }

  bool dfs(const QTMesh& M, 
      const vector<id3>& gedges, 
      const vector<vector<id>>& gv2ge, 
      id gvStart,
      vector<id>& path) {

    vector<id> parent(gv2ge.size(),NO_ID);
    vector<uint8_t> discovered(gv2ge.size(),0);
    std::stack<id> S;
    S.push(gvStart);

    bool found = false;
    id last = NO_ID;
    while (!S.empty()) {
      id gv = S.top();
      S.pop();
      if (!discovered[gv]) {
        discovered[gv] = 1;
        vector<pair<double,id>> w_gv2;
        F(i,gv2ge[gv].size()) {
          double w_ij = 1.;
          id gv2 = gedges[gv2ge[gv][i]][1];
          if (gv2 == gvStart) {
            found = true;
            last = gv;
            break;
          }

          w_gv2.push_back({w_ij,gv2});
        }
        if (found) break;
        std::sort(w_gv2.begin(),w_gv2.end());
        F(i,w_gv2.size()) {
          S.push(w_gv2[i].second);
          parent[w_gv2[i].second] = gv;
          DBG("dfs", gv, w_gv2[i].second);
        }
      }
    }

    path.clear();
    if (found) {
      id cur = last;
      while (cur != NO_ID) {
        path.push_back(cur);
        cur = parent[cur];
      }
      std::reverse(path.begin(),path.end());
    }
    return found;
  }

  void debug_show_graph_in_view(const QTMesh& M, const vector<id3>& gedges, const vector<vector<id>>& gv2ge, const std::string& viewName) {
    GeoLog log;
    F(i,gedges.size()) {
      id gv1 = gedges[i][0];
      id gv2 = gedges[i][1];
      if (gv1 == NO_ID || gv2 == NO_ID) continue;
      if (gv1 == 2*M.edges.size() || gv2 == 2*M.edges.size()) continue;
      vec3 p1 = tedge_center(M, gv1/2, gv1%2);
      vec3 p2 = tedge_center(M, gv2/2, gv2%2);
      log.add({p1,p2},{0.,1.},viewName + "_gedges");
      vec3 mid = 0.5 * (p1+p2);
      vec3 dir = normalize(p2-p1);
      log.addVector(mid, dir, viewName + "_gedges");
    }

    // /* BFS from gvStart */
    // id gvStart = 205;
    // vector<bool> visited(gv2ge.size(),false);
    // std::queue<id> Q;
    // Q.push(gvStart);
    // visited[gvStart] = true;
    // vector<id> parent(gv2ge.size(),NO_ID);
    // vector<double> time(gv2ge.size(),0);
    // double count = 0;
    // while (Q.size() > 0) {
    //   id gv = Q.front();
    //   Q.pop();
    //   count += 1;
    //   F(i,gv2ge[gv].size()) {
    //     id gv2 = gedges[gv2ge[gv][i]][1];
    //     if (visited[gv2]) continue;
    //     Q.push(gv2);
    //     visited[gv2] = true;
    //     parent[gv2] = gv;
    //     time[gv2] = count;
    //   }
    // }
    // FC(gv2,gv2ge.size(),parent[gv2] != NO_ID) {
    //   id gv1 = parent[gv2];
    //   if (gv1 == NO_ID || gv2 == NO_ID) continue;
    //   if (gv1 == 2*M.edges.size() || gv2 == 2*M.edges.size()) continue;
    //   vec3 p1 = tedge_center(M, gv1/2, gv1%2);
    //   vec3 p2 = tedge_center(M, gv2/2, gv2%2);
    //   log.add({p1,p2},{time[gv1],time[gv2]},"bfs_gv"+std::to_string(gvStart));
    //   vec3 mid = 0.5 * (p1+p2);
    //   vec3 dir = normalize(p2-p1);
    //   log.addVector(mid, dir, "bfs_gv"+std::to_string(gvStart)+"_dir");
    // }

    // if (true) {
    //   vector<id> path;
    //   bool found = dfs(M, gedges, gv2ge, gvStart, path);
    //   if (found) {
    //     F(i,path.size()) {
    //       id gv1 = path[i];
    //       id gv2 = path[(i+1)%path.size()];
    //       if (gv1 == NO_ID || gv2 == NO_ID) continue;
    //       if (gv1 == 2*M.edges.size() || gv2 == 2*M.edges.size()) continue;
    //       vec3 p1 = tedge_center(M, gv1/2, gv1%2);
    //       vec3 p2 = tedge_center(M, gv2/2, gv2%2);
    //       log.add({p1,p2},{time[gv1],time[gv2]},"dfs_gv"+std::to_string(gvStart));
    //       vec3 mid = 0.5 * (p1+p2);
    //       vec3 dir = normalize(p2-p1);
    //       log.addVector(mid, dir, "dfs_gv"+std::to_string(gvStart)+"_dir");
    //     }
    //   } else {
    //     error("DFS cycle not found");
    //   }
    // }

    log.toGmsh();
  }

  void debug_show_tchord_in_view(const QTMesh& M, const vector<id>& tchord, const std::string& viewName) {
    if (tchord.size()<2) return;
    GeoLog log;
    F(i,tchord.size()-1) {
      id e1 = tchord[i];
      id e2 = tchord[i+1];
      vec3 p1 = tedge_center(M, e1);
      vec3 p2 = tedge_center(M, e2);
      log.add({p1,p2},double(i),viewName);
    }
    log.toGmsh();
  }

}

namespace QMT {
  using namespace QMT_Utils;
  using namespace QMT_QZ_Utils;
  using namespace GLog;

  struct SizeMapR {
    int tag;
    double h_uniform;
    SizeMapR(int _tag, double _h_uniform = 0.) : tag(_tag), h_uniform(_h_uniform) {
      vector<int> tags;
      gmsh::view::getTags(tags);
      if (tag == -1 || tags.size() == 0) {
        warn("SizeMapR constructor, tags: {}. Field (tag {}) not found", tags, tag);
        tag = -1;
        if (h_uniform == 0.) {
          error("SizeMapR constructor: field not found (tag={}) and h_uniform={}, using 0.1 (arbitrary choice)", tag, h_uniform);
          h_uniform = 0.1;
        }
      } else {
        info("SizeMapR constructor, using field from tag {}", tag);
        h_uniform = 0.;
      }
    }

    double eval(vec3 pt) const {
      if (h_uniform != 0.) return h_uniform;
      vector<double> values;
      gmsh::view::probe(tag, pt[0], pt[1], pt[2], values);
      if (values.size() == 0) {
        error("sizemap: probe failed at pt = {}", pt);
        return DBL_MAX;
      }
      return values[0];
    }
  };

  /* use N_fixed = 0 to let the number of sides as unknown */
  bool compute_edge_sides_from_angles(QTMesh& M, id f, id N_fixed = 4, double angle_threshold_deg = 0.) {
    vector<id>& edges = M.faces[f].edges;
    vector<uint8_t>& sides = M.faces[f].edge_sides;
    if (N_fixed != 0 && edges.size() < N_fixed) {
      error("compute sides | face {}: edges = {}", f, edges);
      if (ERROR_VISU) debug_show_face_in_view(M, f, "fprob_" + std::to_string(f));
      return false;
    } else if (N_fixed != 0 && edges.size() == N_fixed) {
      F(le,edges.size()) sides[le] = le;
      return true;
    }

    /* Compute the angle between consecutive edges */
    vector<bool>& einvert = M.faces[f].edge_orient_invert;
    vector<double> angles(edges.size(),0.);
    F(le,edges.size()) {
      id lep = (edges.size()+le-1)%edges.size();
      const TEdge& ep = M.edges[edges[lep]];
      const TEdge& ec = M.edges[edges[le]];
      { /* verification */
        id2 vp = ep.vertices;
        id2 vc = ec.vertices;
        if (einvert[lep]) std::reverse(vp.begin(),vp.end());
        if (einvert[le]) std::reverse(vc.begin(),vc.end());
        if (vp[1] != vc[0]) {
          error("face {}, {}-{} local edges: prev vertices = {}, cur vertices = {}. Do not match.", f, lep, le, vp, vc);
          return false;
        }
      }
      /* extract tangent vectors at contact */
      vec3 tgp = {0.,0.,0.};
      vec3 tgc = {0.,0.,0.};
      if (!einvert[lep]) {
        tgp = ep.pts[ep.pts.size()-1] - ep.pts[ep.pts.size()-2];
      } else {
        tgp = ep.pts[0] - ep.pts[1];
      }
      if (!einvert[le]) {
        tgc = ec.pts[1] - ec.pts[0];
      } else {
        tgc = ec.pts[ec.pts.size()-2] - ec.pts[ec.pts.size()-1];
      }
      double lp = length(tgp);
      double lc = length(tgc);
      constexpr double EPS_LEN = 1.e-14;
      if (lp < EPS_LEN && ep.pts.size() >= 3) { 
        if (!einvert[lep]) {
          tgp = ep.pts[ep.pts.size()-1] - ep.pts[ep.pts.size()-3];
        } else {
          tgp = ep.pts[0] - ep.pts[2];
        }
      }
      if (lc < EPS_LEN && ec.pts.size() >= 3) { 
        if (!einvert[le]) {
          tgc = ec.pts[2] - ec.pts[0];
        } else {
          tgc = ec.pts[ec.pts.size()-3] - ec.pts[ec.pts.size()-1];
        }
      }
      lp = length(tgp);
      lc = length(tgc);
      if (lp < EPS_LEN || lc < EPS_LEN) {
        error("face {}, {}-{} local edges: tangent length too small, cannot compute angle, length(tgp) = {}, length(tgc) = {}", f, lep, le, lp, lc);
        if (lp < EPS_LEN) error("  prev edge pts: {}", ep.pts);
        if (lc < EPS_LEN) error("  cur edge pts: {}", ec.pts);
        return false;
      }
      tgp = 1./lp * tgp;
      tgc = 1./lc * tgc;
      /* fill angle value */
      angles[le] = angle_nvectors(tgc,tgp);
    }

    /* Sort by angle and define the quad corners */
    vector<pair<double,id>> angle_le;
    F(le,edges.size()) angle_le.push_back({angles[le],le});
    std::sort(angle_le.begin(),angle_le.end());
    std::reverse(angle_le.begin(),angle_le.end());

    std::vector<bool> isCorner(edges.size(),false);
    id Nm = 0;
    if (N_fixed != 0) {
      /* There are more than N_fixed edges, each edge
       * must be assigned a side (0,1,2,3) to have a quad layout 
       * (with T-junctions) structure */
      F(i,N_fixed) isCorner[angle_le[i].second] = true;
      Nm = N_fixed;
    } else {
      F(i,angle_le.size()) {
        double a = angle_le[i].first;
        if (a * 180. / M_PI > angle_threshold_deg) {
          isCorner[angle_le[i].second] = true;
          Nm += 1;
        }
      }
    }
    if (Nm <= 2) {
      error("face {}: found only {} sides from {} edges", f, Nm, edges.size());
      F(i,angle_le.size()) {
        DBG("  ", i, angle_le[i].second, 180. / M_PI * angle_le[i].first);
      }
      if (ERROR_VISU) debug_show_face_in_view(M, f, "prob_face_" + std::to_string(f));
      return false;
    }

    /* Set the sides */
    id cs = 0;
    F(le,edges.size()) {
      if (isCorner[le]) {
        cs += 1;
      }
      sides[le] = uint8_t(cs % Nm); /* warning: number of sides limited to max uint8_t */
    }

    return true;
  }

  bool split_TEdge(QTMesh& M, id e, id& nv) {
    TEdge te = M.edges[e];
    id2 vert = te.vertices;

    /* Create midpoint vertex */
    TVertex ntv;
    ntv.origin = -1;
    ntv.entity = te.entity;
    double clen = curve_length(te.pts);
    vector<double> ts = curve_ts(te.pts,clen);
    vector<vec3> ipts = curve_interpolate(te.pts, {0.5}, clen);
    if (ipts.size() != 1) return false;
    vec3 mid = ipts[0];
    ntv.pt = mid;
    nv = M.vertices.size();

    /* Create 2 TEdge */
    TEdge te1;
    TEdge te2;
    te1.entity = te.entity;
    te2.entity = te.entity;
    te1.origin = te.origin;
    te2.origin = te.origin;
    vector<vec3> pts1;
    vector<vec3> pts2;
    pts2.push_back(mid);
    F(i,ts.size()) {
      if (ts[i] < 0.5) {
        pts1.push_back(te.pts[i]);
      } else if (ts[i] > 0.5){
        pts2.push_back(te.pts[i]);
      }
    }
    pts1.push_back(mid);
    te1.pts = pts1;
    te1.vertices[0] = te.vertices[0];
    te1.vertices[1] = nv;
    te2.pts = pts2;
    te2.vertices[0] = nv;
    te2.vertices[1] = te.vertices[1];

    /* Update the QTMesh datastructure */
    M.vertices.push_back(ntv);
    id e1 = e;
    M.edges[e] = te1;
    id e2 = M.edges.size();
    M.edges.push_back(te2);

    F(f,M.faces.size()) {
      vector<id>& edges = M.faces[f].edges;
      vector<uint8_t>& sides = M.faces[f].edge_sides;
      vector<bool>& orient = M.faces[f].edge_orient_invert;
      bool update_sides = false;
      F(le,edges.size()) {
        if (edges[le] != e) continue;
        if (M.faces[f].edge_orient_invert[le]) {
          edges.insert(edges.begin()+le,e2);
          sides.insert(sides.begin()+le,NO_U8);
          orient.insert(orient.begin()+le,true);
        } else {
          edges.insert(edges.begin()+le+1,e2);
          sides.insert(sides.begin()+le+1,NO_U8);
          orient.insert(orient.begin()+le+1,false);
        }
        update_sides = true;
        break;
      }
      if (update_sides) {
        F(le,sides.size()) sides[le] = NO_U8;
      }
    }

    return true;
  }

  bool split_TFace(QTMesh& M, id f, const vector<bool>& vertexFromEdgeSplit, id& fnv) {
    fnv = NO_ID;
    vector<id>& edges = M.faces[f].edges; 
    vector<bool>& invorient = M.faces[f].edge_orient_invert;
    vector<id> corners;
    vector<id> nvs;
    F(le,edges.size()) {
      id e = edges[le];
      id cv = (invorient[le]) ? M.edges[e].vertices[1] : M.edges[e].vertices[0];
      if (!vertexFromEdgeSplit[cv]) {
        corners.push_back(cv);
      } else {
        nvs.push_back(cv);
      }
    }

    /* Create midpoint */
    TVertex tvm;
    tvm.entity = M.faces[f].entity;
    tvm.origin = -1;
    tvm.pt = {0.,0.,0.};
    F(i,nvs.size()) {
      tvm.pt = tvm.pt + M.vertices[nvs[i]].pt;
    }
    tvm.pt = 1./double(nvs.size()) * tvm.pt;
    id vmid = M.vertices.size();
    fnv = vmid;

    /* Create edges to midpoint */
    map<id,id> nvToNe;
    F(i,nvs.size()) {
      TEdge te;
      te.vertices = {nvs[i],vmid};
      te.entity = M.faces[f].entity;
      te.origin = -1;
      te.pts = {M.vertices[nvs[i]].pt, tvm.pt};
      id ne = M.edges.size();
      nvToNe[nvs[i]] = ne;
      M.edges.push_back(te);
    }

    /* Create subdivided faces */
    edges = M.faces[f].edges; /* get new version, after split */
    invorient = M.faces[f].edge_orient_invert;
    vector<TFace> ntfaces;
    F(le,edges.size()) {
      id2 vertc = edge_vertices(M.edges[edges[le]],invorient[le]);
      if (!inVector(vertc[0],corners)) continue;
      id lep = (edges.size() + le - 1) % edges.size();
      id2 vertp = edge_vertices(M.edges[edges[lep]],invorient[lep]);
      if (vertc[0] == vertp[1] && inVector(vertc[0],corners) && inVector(vertp[0],nvs) && inVector(vertc[1],nvs)) {
        TFace ntf;
        ntf.entity = M.faces[f].entity;
        ntf.origin = -1;

        ntf.edges.push_back(edges[lep]);
        ntf.edge_orient_invert.push_back(invorient[lep]);
        ntf.edge_sides.push_back(NO_U8);

        ntf.edges.push_back(edges[le]);
        ntf.edge_orient_invert.push_back(invorient[le]);
        ntf.edge_sides.push_back(NO_U8);

        ntf.edges.push_back(nvToNe[vertc[1]]);
        ntf.edge_orient_invert.push_back(false);
        ntf.edge_sides.push_back(NO_U8);

        ntf.edges.push_back(nvToNe[vertp[0]]);
        ntf.edge_orient_invert.push_back(true);
        ntf.edge_sides.push_back(NO_U8);

        ntfaces.push_back(ntf);
      } else {
        error("failed to subdivide face {}: edges = {}", f, edges);
        F(j,edges.size()) {
          error("  edge {}, io = {} | {}", edges[j],invorient[j], M.edges[edges[j]]);
        }
        DBG(le);
        DBG(vertc);
        DBG(vertp);
        DBG(inVector(vertc[0],corners));
        DBG(inVector(vertp[0],nvs));
        DBG(inVector(vertc[1],nvs));
        return false;
      }
    }

    /* Update QTMesh datastructure */
    M.vertices.push_back(tvm);
    M.faces[f] = ntfaces[0];
    FC(i,ntfaces.size(),i>0) {
      M.faces.push_back(ntfaces[i]);
    }

    return true;
  }

  bool update_entity_and_project(vec3& pt, pair<int,int>& entity, const BoundaryProjector& projector) {
    if (entity.first == -1 || entity.second == -1) {
      double dist;
      bool okc = projector.closestEntity(pt,dist,entity.first,entity.second);
      if (!okc) return false;
    }
    vec3 proj;
    bool ok = projector.project(entity.first,entity.second,pt,proj);
    if (ok) {
      pt = proj;
    } else {
      return false;
    }
    return true;
  }

  bool subdivide_degenerate_faces(QTMesh& M, const BoundaryProjector* projector = NULL) {
    constexpr bool SHOW_MPS = false;
    size_t nf = 0;
    /* Collect edges and faces ti split */
    vector<id> edges_to_split;
    vector<id> faces_to_split;
    F(f,M.faces.size()) {
      if (M.faces[f].edges.size() < 3) {
        if (M.faces[f].edges.size() == 2) {
          warn("repair_decomposition | face {}: only {} edges, split both and try quads ...", f, M.faces[f].edges.size());
          /* warning: do not split face in this case ! */
          F(le,M.faces[f].edges.size()) {
            edges_to_split.push_back(M.faces[f].edges[le]);
          }
        } else {
          error("face {}: only {} edges: {}", f, M.faces[f].edges.size(), M.faces[f].edges);
          if (ERROR_VISU) debug_show_face_in_view(M, f, "prob_face_" + std::to_string(f));
          return false;
        }
      } else if (M.faces[f].edges.size() != 4) {
        double agl_deg = 45.;
        bool oks = compute_edge_sides_from_angles(M, f, 0, agl_deg);
        if (!oks) {
          error("face {}: failed to compute quad sides", f);
          return false;
        }
        id ns = 0;
        F(le,M.faces[f].edge_sides.size()) {
          ns = std::max(ns,id(M.faces[f].edge_sides[le]+1));
        }
        if (ns != 4) {
          faces_to_split.push_back(f);
          F(le,M.faces[f].edges.size()) {
            edges_to_split.push_back(M.faces[f].edges[le]);
          }
          warn("repair decomposition | face {} has {} sides, flag for midpoint subdivision", f, M.faces[f].edges.size());
          nf += 1;

          if (SHOW_MPS) debug_show_face_in_view(M,f,"to_split_"+std::to_string(f));
        }
      }
      // faces_to_split.push_back(f); // ONLY FOR DEBUG, SPLIT ALL
    }
    sort_unique(faces_to_split);
    sort_unique(edges_to_split);

    /* Split edges and flag new vertices */
    vector<bool> vertexFromEdgeSplit(M.vertices.size(),false);
    F(i,edges_to_split.size()) {
      id e = edges_to_split[i];
      id nv = NO_ID;
      bool okse = split_TEdge(M, e, nv);
      if (!okse || nv == NO_ID) {
        error("failed to split edge {}", e);
        return false;
      }
      if (projector != NULL) {
        bool oku = update_entity_and_project(M.vertices[nv].pt,M.vertices[nv].entity,*projector);
      }
      vertexFromEdgeSplit.resize(M.vertices.size(),false);
      vertexFromEdgeSplit[nv] = true;
    }

    if (projector != NULL) { /* Update tedge pts */
      F(e,M.edges.size()) FC(lv,2,vertexFromEdgeSplit[M.edges[e].vertices[lv]]) {
        if (lv == 0) {
          M.edges[e].pts.front() = M.vertices[M.edges[e].vertices[lv]].pt;
        } else if (lv == 1) {
          M.edges[e].pts.back() = M.vertices[M.edges[e].vertices[lv]].pt;
        }
      }
    }

    id nfb = M.faces.size();
    /* Split faces (midpoint subdivision) */
    vector<bool> vertexFromFaceSplit(M.vertices.size(),false);
    F(lf,faces_to_split.size()) {
      id f = faces_to_split[lf];
      id nv = NO_ID;
      bool oksf = split_TFace(M, f, vertexFromEdgeSplit, nv);
      if (!oksf) {
        error("failed to split face {}", f);
       return false;
      }
      if (projector != NULL) {
        bool oku = update_entity_and_project(M.vertices[nv].pt,M.vertices[nv].entity,*projector);
      }
      vertexFromEdgeSplit.resize(M.vertices.size(),false);
      vertexFromFaceSplit.resize(M.vertices.size(),false);
      vertexFromFaceSplit[nv] = true;
    }

    if (projector != NULL) { /* Update tedge pts */
      F(e,M.edges.size()) F(lv,2) {
        id v = M.edges[e].vertices[lv];
        if (vertexFromEdgeSplit[v] || vertexFromFaceSplit[v]) {
          if (lv == 0) {
            M.edges[e].pts.front() = M.vertices[M.edges[e].vertices[lv]].pt;
          } else if (lv == 1) {
            M.edges[e].pts.back() = M.vertices[M.edges[e].vertices[lv]].pt;
          }
        }
      }
    }

    if (nf > 0) info("repair decomposition | fixed {} degenerate faces via QTMesh splitting", nf);

    if (SHOW_MPS) {
      FC(f,M.faces.size(),M.faces[f].edges.size() > 0) {
        if (M.faces[f].edges.size() != 4) {
          debug_show_face_in_view(M,f,"tj_"+std::to_string(f));
        } else if (inVector(id(f),faces_to_split) || f >= nfb){
          debug_show_face_in_view(M,f,"as_"+std::to_string(f));
        }
      }
    }

    return true;
  }

  bool generate_qtmesh_from_gmsh_colored_triangulation(
      const std::string& modelName,
      QTMesh& M,
      bool accept_degenerate_faces = false) {
    if (!QMT_QZ_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_QZ_Utils::global_gmsh_initialized = true;
    }
    info("generate QTMesh (quad w/ T-jonctions) from gmsh colored triangulation ...");
    RF("obselete");

    M.vertices.clear();
    M.edges.clear();
    M.faces.clear();

    std::string cname;
    gmsh::model::getCurrent(cname);
    gmsh::model::setCurrent(modelName);

    /* A. Get info from gmsh */
    std::unordered_map<id,id> nodeToTVertex;
    std::unordered_map<id,id> nodeToMeshVertex;
    { /* Loop over Geometry Nodes */
      vectorpair nodes;
      gmsh::model::getEntities(nodes,0);
      info("- {} nodes", nodes.size());
      F(i,nodes.size()) {
        id node = nodes[i].second;
        std::vector<size_t> vertices;
        std::vector<double> coords;
        std::vector<double> paramCoords;
        gmsh::model::mesh::getNodes(vertices, coords, paramCoords, 0, node, false, false);
        if (vertices.size() != 1) {
          error("node {}: vertices.size() = {} (should be one)", node, vertices.size());
          return false;
        }
        pair<int,int> entity = {-1,-1};
        TVertex tv;
        tv.pt = {coords[0],coords[1],coords[2]};
        tv.entity = entity;
        tv.origin = node;
        id tvId = M.vertices.size();
        M.vertices.push_back(tv);
        nodeToTVertex[node] = tvId;
        nodeToMeshVertex[node] = vertices[0];
      }
    }

    std::unordered_map<id,id> curveToTEdge;;
    { /* Loop over Geometry Curves */
      vectorpair curves;
      gmsh::model::getEntities(curves,1);
      info("- {} curves", curves.size());
      F(i, curves.size()) {
        int curve = curves[i].second;
        if (curve < 0) {
          error("negative curve tag: curve[{}] = {}", i, curves[i]);
          return false;
        }
        vectorpair cnodes;
        gmsh::model::getBoundary({curves[i]},cnodes,false,false,false);
        if (cnodes.size() != 2) continue;
        id node1 = cnodes[0].second;
        id node2 = cnodes[1].second;
        id v1 = nodeToMeshVertex[node1];
        vector<id> vertices;
        vector<vec3> points;
        vector<id> lines;
        bool okc = getCurveOrderedVertices(std::abs(curve), vertices, points, lines, v1);
        if (!okc) {
          error("curve = {}, failed to get curve vertices ...", curve);
          return false;
        }
        if (points.size() < 2) {
          error("curve = {}, not enough points: {}", curve, points);
          return false;
        }
        pair<int,int> entity = {-1,-1};
        TEdge te;
        te.vertices[0] = nodeToTVertex[node1];
        te.vertices[1] = nodeToTVertex[node2];
        te.pts = points;
        te.entity = entity;
        te.origin = curve;
        id teId = M.edges.size();
        M.edges.push_back(te);
        curveToTEdge[curve] = teId;
      }
    }

    std::vector<bool> edgeUsed(M.edges.size(),false);
    std::unordered_map<id,id> surfaceToTFace;;
    bool has_degenerate_faces = false;
    { /* Loop over Geometry Surfaces (should be quad patches) */
      vectorpair surfaces;
      gmsh::model::getEntities(surfaces,2);
      info("- {} surfaces", surfaces.size());
      bool ok = true;
      F(s,surfaces.size()) {
        if (surfaces[s].second < 0) {
          error("negative surface tag: surfaces[{}] = {}", s, surfaces[s]);
          return false;
        }
        vectorpair sBdr;
        gmsh::model::getBoundary({surfaces[s]}, sBdr, false, true, false);
        if (sBdr.size() < 4) {
          if (accept_degenerate_faces) {
            warn("surface {}: not enough boundary curves: {}", surfaces[s], sBdr);
            has_degenerate_faces = true;
          } else {
            error("surface {}: not enough boundary curves (min. is 4): {}", surfaces[s], sBdr);
            ok = false;
            continue;
          }
        }
        /* Loop over boundaries of patch surfaces[s] */ 
        TFace tf;
        F(j,sBdr.size()) {
          int curve = sBdr[j].second; /* warning: can be negative if inverse orientation */
          auto it = curveToTEdge.find(std::abs(curve));
          if (it == curveToTEdge.end()) {
            error("surface {}: boundary curve {} not found, abort", surfaces[s], sBdr[j]);
            return false;
          }
          id te = it->second;
          tf.edges.push_back(te);
          tf.edge_sides.push_back(NO_U8);
          tf.edge_orient_invert.push_back(curve < 0);
          edgeUsed[te] = true;
        }

        pair<int,int> entity = {-1,-1};
        tf.entity = entity;
        tf.origin = surfaces[s].second;

        id tfId = M.faces.size();
        M.faces.push_back(tf);
        surfaceToTFace[surfaces[s].second] = tfId;
      }
      if (!ok) return false;
    }
    FC(e,M.edges.size(),!edgeUsed[e]) {
      error("edge {} not found in faces (edge details: {})", e, M.edges[e]);
      return false;
    }

    if (accept_degenerate_faces && has_degenerate_faces) {
      bool oks = subdivide_degenerate_faces(M);
      if (!oks) {
        error("failed to fix degenerate faces by subdivision");
        return false;
      }
    }

    /* B. Fill missing info in the QTMesh data structure */
    M.vertToEdges.resize(M.vertices.size());
    M.edgeToFaces.resize(M.edges.size());
    F(i,M.edges.size()) F(lv,2) {
      M.vertToEdges[M.edges[i].vertices[lv]].push_back(i);
    }
    F(i,M.faces.size()) F(le,M.faces[i].edges.size()) {
      M.edgeToFaces[M.faces[i].edges[le]].push_back(i);
    }


    /* Compute the edge_sides info from angles */
    F(f,M.faces.size()) {
      bool oks = compute_edge_sides_from_angles(M,f);
      if (!oks) {
        error("face {}: failed to compute quad sides", f);
        return false;
      }
      if (M.faces[f].edges.size() > 4) {
        info("  face {} with T-junctions: {}", f, M.faces[f]);
      }
    }

    info("QTMesh construction: {} vertices, {} edges, {} faces", M.vertices.size(), M.edges.size(), M.faces.size());

    // std::cout << M << std::endl; // for debug

    gmsh::model::setCurrent(cname);
    return true;
  }

  bool build_qtmesh_from_cut_mesh(const TMesh& M, QTMesh& Q) {
    vector<vector<id>> v2l(M.points.size());
    F(l,M.lines.size()) F(lv,2) v2l[M.lines[l][lv]].push_back(l);

    /* Build TVertex */
    vector<id> v2TVertex(M.points.size(), NO_ID);
    vector<bool> isCorner(M.points.size(),false);
    FC(v,v2l.size(),v2l[v].size() > 0) {
      if (v2l[v].size() != 2) {
        isCorner[v] = true;
      } else if (v2l[v].size() == 2) {
        if (M.line_colors[v2l[v][0]] != M.line_colors[v2l[v][1]]) {
          isCorner[v] = true;
        } else if (M.line_colors[v2l[v][0]] == NO_ID) { /* both uncolored line */
          id2 line1 = M.lines[v2l[v][0]];
          id2 line2 = M.lines[v2l[v][1]];
          if (line1[1] != v) std::reverse(line1.begin(),line1.end());
          if (line2[0] != v) std::reverse(line2.begin(),line2.end());
          vec3 tg1 = M.points[line1[1]] - M.points[line1[0]];
          vec3 tg2 = M.points[line2[1]] - M.points[line2[0]];
          const double EPS_LEN = 1.e-14;
          if (length(tg1) < EPS_LEN || length(tg2) < EPS_LEN) {
            continue;
          }
          tg1 = normalize(tg1);
          tg2 = normalize(tg2);
          double agl = angle_nvectors(tg1,tg2);
          const double line_split_angle_threshold_deg = 45;
          if (agl * 180. / M_PI > line_split_angle_threshold_deg) {
            isCorner[v] = true;
            warn("repair decomposition | corner created on uncolored curve because angle = {} deg", agl * 180./M_PI);
          }
        }
      }
      if (isCorner[v]) {
        TVertex tv;
        tv.pt = M.points[v];
        if (M.pt_color[v] != 0) {
          tv.entity = {0,M.pt_color[v]};
        } else {
          tv.entity = {-1,-1};
        }
        tv.origin = v;
        id tvId = Q.vertices.size();
        Q.vertices.push_back(tv);
        v2TVertex[v] = tvId;
      }
    }

    /* Build TEdges */
    vector<id> l2TEdge(M.points.size(), NO_ID);
    vector<vector<id>> loop_edges;
    vector<vector<id>> loop_vertices;
    bool okl = computeEdgeLoops(M.lines, v2l, isCorner, loop_edges, loop_vertices);
    RFC(!okl,"failed to compute edge loops");

    /* Pre-processing: split periodic loops in two loops if possible */
    F(i,loop_vertices.size()) {
      vector<id>& vert = loop_vertices[i];
      vector<id>& edgs = loop_edges[i];
      if (vert.front() == vert.back()) {
        if (!isCorner[vert.front()] || vert.size() < 3) {
          error("loop {}: got closed periodic edge without corner, cannot split, vert: {}" , i, vert);
          return false;
        } else { /* periodic edge that starts and stops at a corner */
          size_t mid = vert.size() / 2;
          vector<id> part1_vert(vert.begin(),vert.begin()+mid+1);
          vector<id> part1_edgs(edgs.begin(),edgs.begin()+mid);
          vector<id> part2_vert(vert.begin()+mid,vert.end());
          vector<id> part2_edgs(edgs.begin()+mid,edgs.end());

          /* Create a new TVertex */
          id tvId = Q.vertices.size();
          {
            id v = part1_vert.back();
            isCorner[v] = true;
            TVertex tv;
            tv.pt = M.points[v];
            if (M.pt_color[v] != 0) {
              tv.entity = {0,M.pt_color[v]};
            } else {
              tv.entity = {-1,-1};
            }
            tv.origin = v;
            Q.vertices.push_back(tv);
            v2TVertex[v] = tvId;
          }

          loop_vertices[i] = part1_vert;
          loop_edges[i] = part1_edgs;
          loop_vertices.push_back(part2_vert);
          loop_edges.push_back(part2_edgs);
          warn("splitting periodic edge {} in two edges by adding the node {}", i, tvId);
        }
      }
    }
    F(i,loop_vertices.size()) {
      vector<id>& vert = loop_vertices[i];
      if (vert.front() == vert.back()) {
        error("loop {}: got closed loop, should not happen, vert: {}" , i, vert);
        if (ERROR_VISU && vert.size() > 1) {
          GeoLog log;
          F(j,vert.size()-1) {
            log.add({M.points[vert[j]],M.points[vert[j+1]]},{double(j),double(1.+j)},"closed_loop_"+std::to_string(i));
          }
          log.toGmsh();
        }
        return false;
      }

      vector<vec3> pts(vert.size());
      F(j,vert.size()) pts[j] = M.points[vert[j]];

      id tv1 = v2TVertex[vert.front()];
      id tv2 = v2TVertex[vert.back()];
      if (tv1 == NO_ID || tv2 == NO_ID) {
        error("loop {}: extremities {},{} (-> {},{}) not found in TVertex, vert: {}" , i, vert.front(), vert.back(), tv1, tv2, vert);
        return false;
      }

      TEdge te;
      te.vertices[0] = tv1;
      te.vertices[1] = tv2;
      te.pts = pts;
      te.entity = {-1,-1}; /* todo: check if change of color on adj. triangles */
      te.origin = -1;
      id teId = Q.edges.size();
      Q.edges.push_back(te);
      F(j,loop_edges[i].size()) {
        l2TEdge[loop_edges[i][j]] = teId;
      }
    }

    /* Build TFaces */
    std::unordered_map<id2,id,id2Hash> ibdr;
    F(l,M.lines.size()) {
      id2 sedge = sorted(M.lines[l][0],M.lines[l][1]);
      ibdr[sedge] = l;
    }
    vector<id> color(M.triangles.size(),NO_ID);
    vector<vector<id>> colorToTris;
    id ccol = 0;
    FC(fi,M.triangles.size(),color[fi] == NO_ID) {
      ccol += 1;
      vector<id> tris;
      std::queue<id> Q;
      Q.push(fi);
      color[fi] = ccol;
      while (Q.size()) {
        id f = Q.front();
        Q.pop();
        tris.push_back(f);

        F(le,3) {
          sid neig = M.triangle_neighbors[f][le];
          if (neig < 0 || neig == NO_SID) continue; /* non-manifold edge or boundary */
          id af = (id) neig / 3;
          if (color[af] != NO_ID) continue;
          if (M.tri_colors[f] != M.tri_colors[af]) continue;
          id2 sedge = sorted(M.triangles[f][le],M.triangles[f][(le+1)%3]);
          if (ibdr.find(sedge) != ibdr.end()) continue; /* internal line */
          color[af] = ccol;
          Q.push(af);
        }
      }
      sort_unique(tris);
      if (ccol >= colorToTris.size())  colorToTris.resize(ccol+1);
      colorToTris[ccol] = tris;
    }
    FC(col,colorToTris.size(),colorToTris[col].size() > 0) {
      /* Collect colored face bdr edges */
      vector<id> tedges;
      F(lf,colorToTris[col].size()) {
        id f = colorToTris[col][lf];
        F(le,3) {
          id2 sedge = sorted(M.triangles[f][le],M.triangles[f][(le+1)%3]);
          auto it = ibdr.find(sedge);
          if (it != ibdr.end()) {
            id te = l2TEdge[it->second];
            tedges.push_back(te);
          } else {
            sid neig = M.triangle_neighbors[f][le];
            if (neig < 0 || neig == NO_SID || color[f] != color[neig/3]) {
              error("color {}: tri {}, le={}, neig={}, edge {} not found in lines", col, f, le, neig, sedge);
              if (ERROR_VISU) {
                GeoLog log;
                vec3 p1 = M.points[sedge[0]];
                vec3 p2 = M.points[sedge[1]];
                log.add({p1,p2},double(0),"edge_not_found_in_lines");
                log.toGmsh();
              }
              return false;
            }
          }
        }
      }

      sort_unique(tedges);
      vector<id2> teVertices(tedges.size());
      F(i,tedges.size()) teVertices[i] = Q.edges[tedges[i]].vertices;
      vector<int> pos;
      bool oke = edgesToOrderedAndSignedPositions(teVertices, pos);
      if (!oke && ERROR_VISU) {
        F(i,tedges.size()) {
          debug_show_edge_in_view(Q, tedges[i], "error_edgesToOrderedAndSignedPositions");
        }
        debug_show_qtmesh_in_view(Q, "qtmesh");
      }
      RFC(!oke, "failed to get ordered/signed positions");

      TFace tf;
      F(i,pos.size()) {
        tf.edges.push_back(tedges[std::abs(pos[i])]);
        tf.edge_sides.push_back(NO_U8);
        tf.edge_orient_invert.push_back(pos[i] < 0);
      }
      tf.entity = {2,M.tri_colors[colorToTris[col][0]]};
      tf.origin = M.tri_colors[colorToTris[col][0]];
      id tfId = Q.faces.size();
      Q.faces.push_back(tf);
    }

    return true;
  }

  bool generate_qtmesh_from_cut_mesh(
      const std::string& modelName,
      QTMesh& M,
      const BoundaryProjector* projector = NULL,
      bool repair_decomposition = false) {
    if (!QMT_QZ_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_QZ_Utils::global_gmsh_initialized = true;
    }
    info("generate QTMesh (quad w/ T-jonctions) from gmsh cut mesh ...");

    std::string cname;
    gmsh::model::getCurrent(cname);
    gmsh::model::setCurrent(modelName);

    TMesh T;
    bool compute_adjacencies = true;
    bool add_missing_non_manifold_lines = true;
    bool oki = import_TMesh_from_gmsh(modelName, T, compute_adjacencies, add_missing_non_manifold_lines);
    RFC(!oki,"failed to import TMesh from gmsh");

    bool okcs = build_qtmesh_from_cut_mesh(T, M);
    RFC(!okcs,"failed build qtmesh from cut mesh");

    if (repair_decomposition) {
      debug_show_qtmesh_in_view(M, "qtmesh_Bsplit");
      bool oks = subdivide_degenerate_faces(M, projector);
      if (!oks) {
        error("failed to fix degenerate faces by subdivision");
        return false;
      }
      debug_show_qtmesh_in_view(M, "qtmesh_Asplit");
    }

    /* B. Fill missing info in the QTMesh data structure */
    M.vertToEdges.resize(M.vertices.size());
    M.edgeToFaces.resize(M.edges.size());
    F(i,M.edges.size()) F(lv,2) {
      M.vertToEdges[M.edges[i].vertices[lv]].push_back(i);
    }
    F(i,M.faces.size()) F(le,M.faces[i].edges.size()) {
      M.edgeToFaces[M.faces[i].edges[le]].push_back(i);
    }

    /* Compute the edge_sides info from angles */
    F(f,M.faces.size()) {
      bool oks = compute_edge_sides_from_angles(M,f);
      if (!oks) {
        error("face {}: failed to compute quad sides", f);
        return false;
      }
      if (M.faces[f].edges.size() > 4) {
        info("  face {} with T-junctions: {}", f, M.faces[f]);
      }
    }

    info("QTMesh construction: {} vertices, {} edges, {} faces", M.vertices.size(), M.edges.size(), M.faces.size());

    // std::cout << M << std::endl; // for debug

    gmsh::model::setCurrent(cname);
    return true;
  }




  bool edge_pts_length(const std::vector<vec3>& pts, bool use_sizemap, const SizeMapR& sizemap, double& curveLen) {
    if (pts.size() < 2) return false;

    /* Size map size(t) */
    vector<vec3> failed_probes;
    vector<double> size(pts.size(),0.);
    if (use_sizemap) {
      F(i, size.size()) {
        size[i] = sizemap.eval(pts[i]);
        if (size[i] == DBL_MAX) {
          failed_probes.push_back(pts[i]);
        }
      }
    }

    vector<double> Pri(pts.size(),0.);
    /* Integral of inverse, Pri = int(1/size(t),t) */
    double totalLen = 0.;
    F(i,pts.size()-1.) {
      double len = length(pts[i+1]-pts[i]);
      totalLen += len;
      if (use_sizemap) {
        Pri[i+1] = Pri[i] + 0.5 * (1./size[i] + 1./size[i+1]) * len;
      }
    }
    if (use_sizemap) {
      curveLen = Pri.back();
    } else {
      curveLen = totalLen;
    }

    if (ERROR_VISU && failed_probes.size() > 0) {
      GeoLog log;
      F(i,failed_probes.size()) {
        log.add({failed_probes[i]},double(i), "edge_pts_length_probe_failures");
      }
      log.toGmsh();
    }
    RFC(failed_probes.size() > 0, "edge_pts_length | {} probe failures", failed_probes.size());

    return true;
  }

  /* warning: call the gmsh API (via sizemap.eval()) */
  bool compute_subdivided_edge_internal_points(const std::vector<vec3>& pts, size_t N, const SizeMapR& sizemap, vector<vec3>& newPts, vector<double>& newSizes) {
    newPts.clear();
    if (N == 0) return true;

    /* Size map size(t) */
    vector<vec3> failed_probes;
    vector<double> size(pts.size(),0.);
    F(i, size.size()) {
      size[i] = sizemap.eval(pts[i]);
      if (size[i] == DBL_MAX) {
        failed_probes.push_back(pts[i]);
      }
    }

    vector<double> Pri(pts.size(),0.);
    /* Integral of inverse, Pri = int(1/size(t),t) */
    double totalLen = 0.;
    F(i,pts.size()-1.) {
      double len = length(pts[i+1]-pts[i]);
      totalLen += len;
      Pri[i+1] = Pri[i] + 0.5 * (1./double(size[i]) + 1./double(size[i+1])) * len;
    }

    vector<double> targetLens(N, 0.);
    F(i,N) {
      double n = double(1.+i)/double(1.+N) * Pri.back();
      double len_j = 0.;
      double len_jp1 = 0.;
      F(j,pts.size()-1) {
        len_jp1 = len_j + length(pts[j+1] - pts[j]);
        if (Pri[j] <= n && n < Pri[j+1]) {
          double lambda = (n - Pri[j]) / (Pri[j+1] - Pri[j]);
          targetLens[i] = (1.-lambda) * len_j + lambda * len_jp1;
        } else if (n == Pri[j+1]) {
          targetLens[i] = len_jp1;
        }
        len_j = len_jp1;
      }
    }

    constexpr bool NAIVE = false;
    size_t prev_j = 0;
    double prev_acc = 0.;
    F(i,N) {
      double targetLen = targetLens[i];

      bool found = false;
      if (NAIVE) {
        double len_j = 0.;
        for(size_t j = 0; j < pts.size()-1; ++j) {
          double acc = length(pts[j+1]-pts[j]);
          double len_jp1 = len_j + acc;

          if (len_j < targetLen && targetLen <= len_jp1) {
            double lambda = (targetLen - len_j) / (len_jp1 - len_j);
            vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
            double h = (1.-lambda) * size[j] + lambda * size[j+1];
            newPts.push_back(pt);
            newSizes.push_back(h);
            found = true;
            break;
          }

          len_j = len_jp1;
        }
      } else {
        double acc = prev_acc;
        for(size_t j = prev_j; j < pts.size()-1; ++j) {
          double len_j = acc;
          acc += length(pts[j+1]-pts[j]);
          double len_jp1 = acc;

          if (len_j < targetLen && targetLen <= len_jp1) {
            double lambda = (targetLen - len_j) / (len_jp1 - len_j);
            vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
            double h = (1.-lambda) * size[j] + lambda * size[j+1];
            newPts.push_back(pt);
            newSizes.push_back(h);
            found = true;
            prev_j = j;
            prev_acc = len_j;
            break;
          }
        }
      }
      if (!found) {
        error("sample point not found !");
        return false;
      }
    }

    if (ERROR_VISU && failed_probes.size() > 0) {
      GeoLog log;
      F(i,failed_probes.size()) {
        log.add({failed_probes[i]},double(i), "compute_subdivided_edge_internal_points");
      }
      log.toGmsh();
    }
    RFC(failed_probes.size() > 0, "compute_subdivided_edge_internal_points | {} probe failures", failed_probes.size());

    return true;
  }

  inline uint8_t side_of_edge(const QTMesh& M, id f, id e) {
    F(le,M.faces[f].edges.size()) {
      if (M.faces[f].edges[le] == e) return M.faces[f].edge_sides[le];
    }
    error("side_of_edge | edge {} not in face {}", e, f);
    return NO_U8;
  }

  inline vector<id> edges_from_face_side(const QTMesh& M, id f, id s) {
    vector<id> edges;
    FC(le,M.faces[f].edges.size(),M.faces[f].edge_sides[le] == s) {
      edges.push_back(M.faces[f].edges[le]);
    }
    return edges;
  }

  bool unroll_parent(const vector<id>& parent, id e, vector<id>& path, id eStart, const vector<id>& finished) {
    if (e == NO_ID) return false;
    if (parent[e] == NO_ID) return false;
    path.clear();
    path.push_back(e);
    bool stop = false;
    do {
      e = parent[e];
      stop = (e == NO_ID) || (parent[e] == e) || inVector(e, finished);
      if (!stop) path.push_back(e);
    } while(!stop);
    return true;
  }

  /* return edge ids, warning: not sorted by propagation ! */
  bool tchord_propagation(
      const QTMesh& M, 
      const vector<double>& edge_nx,
      id eStart,
      vector<id>& tchord) {
    tchord.clear(); 

    /* BFS propagation with priority queue */
    if (M.edgeToFaces[eStart].size() == 0) {
      error("no face adjacent to eStart = {}", eStart);
      return false;
    }

    vector<array<bool,4>> face_side_done(M.faces.size(),{false,false,false,false});
    vector<bool> reached(M.edges.size(), false);
    vector<id> parent(M.edges.size(), NO_ID);
    // TODO: which heuristic for the priority queue ?
    // std::priority_queue<std::pair<double,id>, std::vector<std::pair<double,id>>, std::greater<std::pair<double,id>>> Q; 
    std::priority_queue<std::pair<double,id>, std::vector<std::pair<double,id> > > Q; 

    /* Init */
    id fStart = M.edgeToFaces[eStart][0];
    parent[eStart] = eStart;
    Q.push({0.,eStart});
    vector<id> direction(M.edges.size(),NO_ID); /* lf from eStart */
    vector<id> finished(M.edgeToFaces[eStart].size(), NO_ID);

    bool VERB = false;
    if (VERB) info("====== tchord from eStart = {} ======", eStart);
    /* Propagation */
    bool all_finished = false;
    while (Q.size() > 0.) {
      id e = Q.top().second;
      Q.pop();
      reached[e] = true;
      if (VERB) info("- e = {}, M.edgeToFaces[e].size() = {}", e, M.edgeToFaces[e].size());

      bool prop = false;
      F(lf,M.edgeToFaces[e].size()) {
        id f = M.edgeToFaces[e][lf];
        id s = side_of_edge(M, f, e);
        id op_side = (s+2)%4;
        if (VERB) info("--- lf = {}, f = {}, s = {}, op_side = {}, face_side_done[f][op_side] = {}", lf, f, s, op_side, face_side_done[f][op_side]);
        if (face_side_done[f][op_side]) continue;
        vector<id> oedges = edges_from_face_side(M, f, op_side);
        if (VERB) info("---- oedges = {}", oedges);
        F(le,oedges.size()) {
          id oe = oedges[le];
          if (VERB) info("---- oe = {}, reached[oe] = {}", oe, reached[oe]);
          if (reached[oe]) { /* closed loop ! */
            if (VERB) info("---- ! CLOSED LOOP");
            finished.clear();
            finished.push_back(oe);
            finished.push_back(e);
            all_finished = true;
            break;
          }
          if (parent[oe] != NO_ID) continue;
          parent[oe] = e;
          Q.push({edge_nx[oe],oe});
          direction[oe] = (e == eStart) ? lf : direction[e];
          reached[oe] = true;
          if (VERB) info("---- Q+=({},{})",edge_nx[oe],oe);
          prop = true;
        }
        face_side_done[f][s] = true;
        if (all_finished) break;
      }
      if (all_finished) break;
      if (!prop) {
        finished[direction[e]] = e;
        if (VERB) info("---- ! NO PROP, finished[{}] = {}", direction[e], e);
      }
      all_finished = true;
      FC(i,finished.size(),finished[i] == NO_ID) all_finished = false;
      if (all_finished) break;
    }

    if (!all_finished) {
      error("failed to build the t-chord (not all sides are finished)");
      if (VERB) F(i,finished.size()) info("- finished[{}]={}",i,finished[i]);
      return false;
    }

    F(i,finished.size()) {
      vector<id> path;
      bool oku = unroll_parent(parent, finished[i], path, eStart, finished);
      if (!oku) {
        error("failed to unroll parent chain for finished[{}]={}", i, finished[i]);
        return false;
      }
      if (finished.size() == 2) {
        if (i == 0) {
          path.push_back(eStart);
          std::reverse(path.begin(),path.end());
        }
      }
      
      F(j,path.size()) tchord.push_back(path[j]);
    }

    sort_unique(tchord);

    return true;
  }

  bool build_graph_from_QTMesh(const QTMesh& M, vector<id3>& gedges, vector<vector<id>>& gv2ge) {
    /* QTMesh edge becomes gvertices, linked by gedges */
    gedges.clear();
    gv2ge.clear();
    id mgv = 0;
    F(f,M.faces.size()) {
      vector<vector<id> > side_edges(4);
      F(le,M.faces[f].edges.size()) {
        side_edges[M.faces[f].edge_sides[le]].push_back(M.faces[f].edges[le]);
      }
      F(s,2) {
        id os = s+2;
        F(i,side_edges[s].size()) {
          F(j,side_edges[os].size()) {
            id2 gedge_01 = sorted(side_edges[s][i],side_edges[os][j]);
            id3 gedge = {gedge_01[0],gedge_01[1],(id)f};
            gedges.push_back(gedge);
            mgv = std::max(mgv,gedge[0]);
            mgv = std::max(mgv,gedge[1]);
          }
        }
      }
    }
    sort_unique(gedges);
    gv2ge.resize(mgv+1);
    F(i,gedges.size()) F(lv,2) gv2ge[gedges[i][lv]].push_back(i);

    return true;
  }

  bool build_double_directed_graph_from_QTMesh(
      const QTMesh& M, 
      vector<id3>& gedges, 
      vector<vector<id>>& gv2ge,
      bool add_infinite_gv = false) {
    /* Two graph vertices per edge:
     * - 2*e+0 points to M.edgeToFaces[e][0]
     * - 2*e+1 points to M.edgeToFaces[e][1] */
    gedges.clear();
    bool has_bdr = false;
    F(e,M.edges.size()) {
      if (M.edgeToFaces[e].size() == 0 || M.edgeToFaces[e].size() > 2) {
        RF("case not supported, e = {}, edgeToFaces[e] = {}", M.edgeToFaces[e]);
      }
      F(li,M.edgeToFaces[e].size()) {
        id gv = 2 * e + li;
        id f = M.edgeToFaces[e][li];
        /* Get side in f */
        id es = NO_ID;
        FC(le,M.faces[f].edges.size(),M.faces[f].edges[le] == e) {
          es = M.faces[f].edge_sides[le];
          break;
        }
        RFC(es == NO_ID, "side not found");

        /* Collect face-opposite edges */
        F(le,M.faces[f].edges.size()) {
          id os = M.faces[f].edge_sides[le];
          if (os == es || os % 2 != es % 2) continue;
          id e2 = M.faces[f].edges[le];
          id gv2 = NO_ID;
          if (M.edgeToFaces[e2].size() == 1 && M.edgeToFaces[e2][0] == f) {
            has_bdr = true;
            if (add_infinite_gv) {
              gv2 = 2*e2+1;
            } else {
              gv2 = 2*e2;
            }
          } else if (M.edgeToFaces[e2].size() == 2 && M.edgeToFaces[e2][0] == f) {
            gv2 = 2*e2+1;
          } else if (M.edgeToFaces[e2].size() == 2 && M.edgeToFaces[e2][1] == f) {
            gv2 = 2*e2+0;
          } else {
            RF("should not happen");
          }
          id3 gedge = {gv,gv2,f};
          gedges.push_back(gedge);
        }
      }
    }
    gv2ge.resize(2*M.edges.size());

    if (add_infinite_gv && has_bdr) {
      gv2ge.resize(2*M.edges.size()+1);
      id gv_inf = 2*M.edges.size();
      FC(e,M.edges.size(), M.edgeToFaces[e].size() == 1) {
        id gv_out = 2 * e + 1;
        id gv_in = 2 * e + 0;
        id f = NO_ID;
        gedges.push_back({gv_out,gv_inf,f});
        gedges.push_back({gv_inf,gv_in,f});
      }
    }

    F(i,gedges.size()) gv2ge[gedges[i][0]].push_back(i);

    return true;
  }

  /* See Campen et al. 2015 */
  inline double quantization_weigth(const id e, const vector<double>& edge_nx, const vector<id>& edge_n) {
    const size_t Ne = edge_n.size();
    if (e == Ne) { /* infinite node */
      return 1; /* arbitrary choice, TODO: better ! */
    }
    const double dp = edge_nx[e] - (double) edge_n[e];
    if (1. <= dp) { 
      return 1./ (dp+1.);
    } else if (0. <= dp && dp < 1.) {
      return Ne / (dp+1.);
    } else if (dp < 0.) {
      return Ne*Ne / (1.-dp);
    }
    error("should not happen");
    return DBL_MAX;
  }

  bool tchord_propagation_in_double_directed_graph_simple(
      const vector<id3>& gedges,
      const vector<vector<id> >& gv2ge,
      const vector<double>& edge_nx,
      const vector<id>& edge_n,
      id gvStart,
      vector<id>& tchord,
      const QTMesh& Mdbg) {
    /* Assume 'closed surface' graph, via infinite node if necessary */

    id eStart = gvStart/2;
    /* Dijsktra algorithm */
    vector<double> dist(gv2ge.size(),DBL_MAX);
    vector<id> prev(gv2ge.size(),NO_ID);
    // vector<bool> visited(gv2ge.size(),false);
    std::priority_queue<std::pair<double,id>,  std::vector<std::pair<double,id> >,  std::greater<std::pair<double,id> > > Q; 

    /* Init */
    dist[gvStart] = 0.;
    Q.push({0.,gvStart});
    double time_count = 0.; /* only for debug */

    /* Dijsktra loop */
    bool first_time = true;
    bool closed = false;
    while (Q.size() > 0) {
      id gv = Q.top().second;
      Q.pop();

      /* Check ending condition: closed circuit */
      if (gv == gvStart && prev[gv] != NO_ID) {
        closed = true;
        break;
      }


      /* Propagate */
      F(j,gv2ge[gv].size()) {
        id ge = gv2ge[gv][j];
        id3 gedge = gedges[ge];
        RFC(gedge[0] != gv || gedge[1] == gv, "dijkstra issue: gv={}, j = {}, gedge = {}", gv, j, gedge);
        id gv2 = gedge[1];
        double w_ij = quantization_weigth(gv2 / 2, edge_nx, edge_n);
        // DBG(gv,gv2,w_ij);

        if (dist[gv] + w_ij < dist[gv2]) {
          dist[gv2] = dist[gv] + w_ij;
          Q.push({dist[gv2],gv2});
          prev[gv2] = gv;
          // error("  +=[{},{}]", dist[gv2], gv2);
        } else if (gv2 == gvStart) {
          dist[gv2] = 0.;
          prev[gv2] = gv;
          Q.push({dist[gv2],gv2});
          // error("! +=[{},{}]", dist[gv2], gv2);
        }
        // TODO: optimization with visited[]

        // double alt = dist[gv] + w_ij;
        // if (alt < dist[gv2]) {
        //   dist[gv2] = alt;
        //   prev[gv2] = gv;
        // }
        // if (gv2 == gvStart) { /* closing the loop */
        //   dist[gv2] = alt;
        //   dist[gv2] = 0.; /* just for testing */
        //   prev[gv2] = gv;
        // }
        // if (!visited[gv2]) {
        //   Q.push({dist[gv2],gv2});
        //   visited[gv2] = true;
        // }
      }
    }

    if (!closed) {
      warn("finished dijkstra but didn't find a closed loop ... gvStart = {}", gvStart);
      if (false && ERROR_VISU) {
        GeoLog log;
        FC(gv, gv2ge.size(), prev[gv] < gv2ge.size()) {
          id gv1 = prev[gv];
          id gv2 = gv;
          if (gv1 == NO_ID || gv2 == NO_ID) continue;
          if (gv1 == 2*edge_n.size() || gv2 == 2*edge_n.size()) continue;
          vec3 p1 = tedge_center(Mdbg, gv1/2, gv1%2);
          vec3 p2 = tedge_center(Mdbg, gv2/2, gv2%2);
          log.add({p1,p2},{dist[prev[gv]],dist[gv]},"PROB_prop_gv"+std::to_string(gvStart));
        }
        log.toGmsh();
      }
      return false;
    }

    /* Unroll the path */
    vector<id> path;
    {
      size_t it = 0;
      id gv = gvStart;
      while (gv != NO_ID) {
        it += 1;
        RFC(it > 1e6, "infinite loop in unroll closed loop ? it = {}", it);
        path.push_back(gv);
        gv = prev[gv];
        if (gv == gvStart) break; /* closed loop */
      }
      std::reverse(path.begin(),path.end());
    }

    /* Get the edges from the gv */
    tchord.clear();
    F(i,path.size()) {
      if (path[i] == 2*edge_n.size()) continue; /* infinite node, ignore */
      tchord.push_back(path[i] / 2);
    }

    if (false) {
      GeoLog log;
      F(i, path.size()) {
        id gv1 = path[i];
        id gv2 = path[(i+1)%path.size()];
        if (gv1 == 2*edge_n.size() || gv2 == 2*edge_n.size()) continue;
        vec3 p1 = tedge_center(Mdbg, gv1/2, gv1%2);
        vec3 p2 = tedge_center(Mdbg, gv2/2, gv2%2);
        log.add({p1,p2},{double(i),double(i+2)},"_dbg_gvStart"+std::to_string(gvStart));
      }
      log.toGmsh();
    }

    return true;
  }


  bool tchord_propagation_in_double_directed_graph(
      const vector<id3>& gedges,
      const vector<vector<id> >& gv2ge,
      const vector<double>& edge_nx,
      const vector<id>& edge_n,
      id gvStart,
      vector<id>& tchord,
      const QTMesh& Mdbg) {

    /* Two cases:
     * - starting edge (eq. gv/2) is on the boundary => looking for open circuit
     * - starting edge (eq. gv/2) inside => looking for either closed circuit or open circuit
     */
    const id SE_INSIDE = 1;
    const id SE_BDR = 2;
    id tt = 0;
    id eStart = gvStart/2;
    id2 gvStarts = {NO_ID,NO_ID};
    if (gv2ge[2*eStart+0].size() > 0 && gv2ge[2*eStart+1].size() > 0) {
      /* Both directions available from eStart => inside, open or closed */
      tt = SE_INSIDE;
      gvStarts = {2*eStart,2*eStart+1};
    } else if (gvStart == 2*eStart && gv2ge[2*eStart].size() > 0 && gv2ge[2*eStart+1].size() == 0) {
      /* Only one direction from eStart => on the boundary */
      gvStarts = {gvStart,NO_ID};
      tt = SE_BDR;
    } else {
      RF("tchord prop. case not supported: gvStart = {}, eStart = {}, gv2ge[2*eStart+0] = {}, gv2ge[2*eStart+1] = {}", 
          gvStart, eStart, gv2ge[2*eStart], gv2ge[2*eStart+1]);
    }

    /* Dijsktra algorithm */
    // info("tchord eStart {} | tt = {}, prop ...", eStart, tt);
    vector<double> dist(gv2ge.size(),DBL_MAX);
    vector<id> prev(gv2ge.size(),NO_ID);
    vector<bool> visited(gv2ge.size(),false);
    id2 lasts = {NO_ID,NO_ID}; /* for open circuits, the two extremities are two bdr edges */
    std::priority_queue<std::pair<double,id>,  std::vector<std::pair<double,id> >,  std::greater<std::pair<double,id> > > Q; 

    /* Init */
    F(i,2) {
      if (gvStarts[i] != NO_ID) {
        dist[gvStarts[i]] = 0.;
        Q.push({0.,gvStarts[i]});
      }
    }
    double time_count = 0.; /* only for debug */

    /* Dijsktra loop */
    while (Q.size() > 0) {
      id gv = Q.top().second;
      Q.pop();

      /* Check ending condition */
      /* - Closed circuit condition */
      if (tt == SE_INSIDE) {
        bool finished = false;
        FC(i,2,visited[gv] && gv == gvStarts[i]) {
          finished = true;
          lasts = {gvStarts[i],gvStarts[i]};
          break;
        }
        if (finished) break;
      }
      /* - Open circuit condition */
      if (tt == SE_BDR || tt == SE_INSIDE) {
        bool onBdr = (gv2ge[2*(gv/2)].size() > 0 && gv2ge[2*(gv/2)+1].size() == 0);
        if (onBdr) {
          if (lasts[0] == NO_ID) {
            lasts[0] = gv;
          } else if (lasts[1] == NO_ID) {
            lasts[1] = gv;
          } else {
            RF("should not happen, lasts already full");
          }
          if (lasts[0] != NO_ID && lasts[1] != NO_ID) {
            break; /* finished, both ends reached */
          }
          /* do not propagate from bdrs, except if starting from bdr */
          if (!(tt == SE_BDR && gv == gvStart)) continue; 
        }
      }

      /* Propagate */
      F(j,gv2ge[gv].size()) {
        id ge = gv2ge[gv][j];
        id3 gedge = gedges[ge];
        RFC(gedge[0] != gv || gedge[1] == gv, "dijkstra issue: gv={}, j = {}, gedge = {}", gv, j, gedge);
        id gv2 = gedge[1];
        double w_ij = quantization_weigth(gv2 / 2, edge_nx, edge_n);
        double alt = dist[gv] + w_ij;
        if (alt < dist[gv2]) {
          dist[gv2] = alt;
          prev[gv2] = gv;
        }
        if (tt == SE_INSIDE) { /* Special case for closed loop */
          if (gv2 == gvStarts[0] || gv2 == gvStarts[1]) { /* closing loop (see ending condition) */
            dist[gv2] = alt;
            prev[gv2] = gv;
          }
        }
        if (!visited[gv2]) {
          Q.push({dist[gv2],gv2});
          visited[gv2] = true;
        }
      }
    }

    // if (last == NO_ID && ERROR_VISU) {
    //   GeoLog log;
    //   FC(gv, gv2ge.size(), prev[gv] < gv2ge.size()) {
    //     vec3 p1 = tedge_center(Mdbg, prev[gv]/2, prev[gv]%2);
    //     vec3 p2 = tedge_center(Mdbg, gv/2, gv%2);
    //     log.add({p1,p2},{dist[prev[gv]],dist[gv]},"prop_gv"+std::to_string(gvStart));
    //   }
    //   log.toGmsh();
    // }
    // RFC(last == NO_ID, "dijkstra issue, failed to propagate: finished but last = {}", last);

    /* Unroll the path */
    vector<id> path;
    if (tt == SE_INSIDE && lasts[0] == lasts[1]){ /* closed loop */
      // info("tchord eStart {} | unroll closed loop", eStart);
      size_t it = 0;
      id gv = lasts[0];
      while (gv != NO_ID) {
        it += 1;
        RFC(it > 1e6, "infinite loop in unroll closed loop ? it = {}", it);
        path.push_back(gv);
        gv = prev[gv];
        if (gv == lasts[0]) break; /* closed loop */
      }
      std::reverse(path.begin(),path.end());
    } else { /* open loop */
      // info("tchord eStart {} | unroll open loop", eStart);
      id gv = lasts[0];
      size_t it = 0;
      while (gv != NO_ID) {
        it += 1;
        RFC(it > 1e6, "infinite loop in unroll open loop ? it = {}", it);
        path.push_back(gv);
        gv = prev[gv];
      }
      vector<id> path2;
      gv = lasts[1];
      while (gv != NO_ID) {
        it += 1;
        RFC(it > 1e6, "infinite loop in unroll open loop ? it = {}", it);
        path2.push_back(gv);
        gv = prev[gv];
      }
      std::reverse(path2.begin(),path2.end());
      FC(i,path2.size(),i>0) {
        path.push_back(path2[i]);
      }
    }

    /* Get the edges from the gv */
    tchord.resize(path.size());
    F(i,path.size()) tchord[i] = path[i] / 2;

    if (ERROR_VISU && intersection(tchord,{3,90,99,5}).size() > 0) {
      GeoLog log;
      F(i, path.size()-1) {
        vec3 p1 = tedge_center(Mdbg, path[i]/2, path[i]%2);
        vec3 p2 = tedge_center(Mdbg, path[i+1]/2, path[i+1]%2);
        log.add({p1,p2},{double(i),double(i+2)},"_dbg_gvStart"+std::to_string(gvStart));
      }
      log.toGmsh();
    }

    const id DBG_ID = NO_ID;
    if (ERROR_VISU && eStart == DBG_ID) {
      GeoLog log;
      F(i, path.size()-1) {
        vec3 p1 = tedge_center(Mdbg, path[i]/2, path[i]%2);
        vec3 p2 = tedge_center(Mdbg, path[i+1]/2, path[i+1]%2);
        log.add({p1,p2},{double(i),double(i+2)},"_dbg_eStart"+std::to_string(DBG_ID));
      }
      log.toGmsh();
    }

    return true;
  }



  bool tchord_propagation(
      const vector<id3>& gedges,
      const vector<vector<id> >& e2ge,
      const vector<bool>& eIsStop,
      const vector<double>& edge_nx,
      const vector<id>& edge_n,
      id eStart,
      vector<id>& tchord,
      const QTMesh& Mdbg) {

    /* QTMesh meshes adjacent to eStart */
    vector<id> startFs;
    F(i,e2ge[eStart].size()) {
      id ge = e2ge[eStart][i];
      id f = gedges[ge][2];
      startFs.push_back(f);
    }
    sort_unique(startFs);
    if (startFs.size() != 1 && startFs.size() != 2) {
      error("cannot propagate from eStart = {}, adjacent faces: {}", eStart, startFs);
      return false;
    }
    std::unordered_map<id,id> startFaceEnding;
    F(i,startFs.size()) startFaceEnding[startFs[i]] = NO_ID;

    vector<bool> visited(gedges.size(),false);
    vector<id> parent(e2ge.size(),NO_ID);
    vector<id> parent_face(e2ge.size(),NO_ID);
    vector<id> parent_face_start(e2ge.size(),NO_ID);
    std::priority_queue<std::pair<double,id>, std::vector<std::pair<double,id> > > Q; 

    bool finished = false;
    id FIRST = NO_ID - 1;
    parent[eStart] = FIRST;
    parent_face[eStart] = FIRST;
    parent_face_start[eStart] = FIRST;
    Q.push({DBL_MAX,eStart});
    vector<id> lgeStrartReachedBdr(e2ge[eStart].size(),NO_ID);
    bool closed_loop = false;
    while (Q.size() > 0.) {
      id e = Q.top().second;
      id pf = parent_face[e];
      Q.pop();
      bool prop = false;
      F(lge,e2ge[e].size()) {
        if (e != eStart && eIsStop[e]) continue; /* do not propagate through boundary / non-manifold */
        id ge = e2ge[e][lge];
        if (visited[ge]) continue; /* each graph edge visited only one time */
        id3 gedge = gedges[ge];
        id e2 = (gedge[0] != e) ? gedge[0] : gedge[1];
        id f = gedge[2];
        if (f == pf) continue; /* avoid come back through the same face in the QTMesh */
        if (parent[e2] != NO_ID) { /* node already reached ... */
          if (parent_face[e2] == f) { /* do not go again through the same edge in the same direction */
            continue;
          }

          /* closed loop */
          startFaceEnding[parent_face_start[e]] = e; /* finish current path */
          startFaceEnding[parent_face_start[e2]] = e2; /* cut the other path */
          closed_loop = true;
          break;
        }
        double prio = 0;
        if (edge_n[e2] == 0.) {
          prio = 1.e6 * std::abs(edge_nx[e2] - double(edge_n[e2]));
        } else {
          prio = edge_nx[e2] - edge_n[e2]; /* negative if nx < n */
        }
        Q.push({prio,e2});
        visited[ge] = true;
        parent[e2] = e;
        parent_face[e2] = f;
        if (e == eStart) {
          parent_face_start[e2] = f;
        } else {
          parent_face_start[e2] = parent_face_start[e];
        }
        prop = true;
      }
      if (closed_loop || (!prop && eIsStop[e])) {
        if (e == eStart) {
          error("no propagation from eStart = {}", eStart);
          return false;
        }
        startFaceEnding[parent_face_start[e]] = e;
        finished = true;
        for (auto& kv: startFaceEnding) {
          if (kv.second == NO_ID) finished = false;
        }
        if (finished) break;
      }
    }
    if (!finished) {
      error("tchord_propagation: failed to finish, eStart = {}", eStart);
      for (auto& kv: startFaceEnding) {
        error("  k={}, startFaceEnding[k]]={}", kv.first, kv.second);
        if (kv.second != NO_ID) finished = false;
        if (kv.second != NO_ID && ERROR_VISU) {
          id e_last = kv.second;
          id e = e_last;
          vector<id> spath;
          if (e != eStart) {
            do {
              spath.push_back(e);
              e = parent[e];
            } while (e != eStart);
          }
          spath.push_back(eStart);
          std::reverse(spath.begin(),spath.end());
          error("    tchord path: {}", spath);
          debug_show_tchord_in_view(Mdbg, spath, "_tchord_"+std::to_string(kv.second));
        }
      }
      return false;
    }

    /* Path unrolling */
    tchord.clear();
    id i = 0;
    for (auto& kv: startFaceEnding) {
      id e_last = kv.second;
      id e = e_last;
      vector<id> spath;
      if (e != eStart) {
        do {
          spath.push_back(e);
          e = parent[e];
        } while (e != eStart);
      }
      if (i == 0) {
        F(j,spath.size()) tchord.push_back(spath[j]);
        tchord.push_back(eStart);
      } else if (i == 1) {
        std::reverse(spath.begin(),spath.end());
        F(j,spath.size()) tchord.push_back(spath[j]);
      } else {
        error("more than 2 startFaceEnding should not happen");
        return false;
      }
      i += 1;
    }

    return true;
  }

  bool tchord_propagation_one_way(
      const vector<id3>& gedges,
      const vector<vector<id> >& e2ge,
      const vector<double>& edge_nx,
      const vector<id>& edge_n,
      id eStart,
      vector<id>& tchord,
      const QTMesh& Mdbg) {

    /* Looking for T-chord of type */
    const id TT_CLOSED = 1;
    const id TT_OPEN = 2;
    id tchord_type = 0;
    if (e2ge[eStart].size() == 0 || e2ge[eStart].size() > 2) {
      RF("cannot propagate from eStart = {}, e2ge[eStart] = {}", e2ge[eStart]);
    } else if (e2ge[eStart].size() == 1) {
      tchord_type = TT_OPEN;
    } else if (e2ge[eStart].size() == 2) {
      tchord_type = TT_CLOSED;
    }

    vector<bool> visited(gedges.size(),false); /* graph-edge can be visited only one time */
    vector<id> parent(e2ge.size(),NO_ID);
    vector<id> parent_face(e2ge.size(),NO_ID);
    vector<double> time(gedges.size(),0); /* for debugging ... */
    std::priority_queue<std::pair<double,id>, std::vector<std::pair<double,id> > > Q; 
    bool finished = false;
    id FIRST = NO_ID - 1;
    parent[eStart] = FIRST;
    parent_face[eStart] = FIRST;
    id eStart_init_face = NO_ID;
    Q.push({DBL_MAX,eStart});
    id eLast = NO_ID;
    id count = 0;
    while (Q.size() > 0.) {
      id e = Q.top().second;
      id pf = parent_face[e];
      Q.pop();
      count += 1;

      /* Sort candidates for progation */
      vector<pair<double,id>> ges;
      F(lge,e2ge[e].size()) {
        id ge = e2ge[e][lge];
        if (visited[ge]) continue; /* each graph edge visited only one time */
        id3 gedge = gedges[ge];
        id e2 = (gedge[0] != e) ? gedge[0] : gedge[1];
        id f = gedge[2];
        if (eStart_init_face == NO_ID) eStart_init_face = f;
        if (e == eStart && eStart_init_face != NO_ID && eStart_init_face != f) continue;
        if (f == pf) continue; /* avoid come back through the same face in the QTMesh */
        if (parent[e2] != NO_ID) { /* node already reached ... */
          if (parent_face[e2] == f) { /* do not go again through the same edge in the same direction */
            continue;
          }
        }
        double prio = 0;
        if (edge_n[e2] == 0.) {
          prio = 1.e6 * std::abs(edge_nx[e2] - double(edge_n[e2]));
        } else {
          prio = edge_nx[e2] - edge_n[e2]; /* negative if nx < n */
        }
        ges.push_back({prio,ge});
      }
      std::sort(ges.begin(),ges.end(),std::greater<pair<double,id>>());

      /* Check ending condition or propagate by adding to queue */
      bool prop = false;
      F(j,ges.size()) {
        id ge = ges[j].second;
        id3 gedge = gedges[ge];
        id e2 = (gedge[0] != e) ? gedge[0] : gedge[1];
        /* Check ending condition */
        if (tchord_type == TT_CLOSED && e2 == eStart) {
          finished = true;
          eLast = e;
          break;
        } else if (tchord_type == TT_OPEN && e2ge[e2].size() == 1) {
          finished = true;
          eLast = e2;
          parent[e2] = e;
          parent_face[e2] = gedge[2];
          break;
        }

        /* Propagate */
        Q.push({ges[j].first,e2});
        visited[ge] = true;
        parent[e2] = e;
        parent_face[e2] = gedge[2];
        prop = true;
        time[e2] = count;
      }

      if (finished) {
        break;
      } else if (!finished && !prop) {
        error("tchord_propagation: failed to finish, eStart = {}", eStart);
        if (ERROR_VISU) {
          GeoLog log;
          FC(e,e2ge.size(),parent[e] < e2ge.size()) {
            vec3 p1 = tedge_center(Mdbg, parent[e]);
            vec3 p2 = tedge_center(Mdbg, e);
            log.add({p1,p2},{time[parent[e]],time[e]},"prop");
          }
          log.toGmsh();
        }
        return false;
      }
    }

    if (finished) {
      /* Path unrolling */
      tchord.clear();
      id e = eLast;
      if (e != eStart) {
        do {
          tchord.push_back(e);
          e = parent[e];
        } while (e != eStart);
      }
      tchord.push_back(eStart);
      std::reverse(tchord.begin(),tchord.end());
      return true;
    }

    return false;
  }

  bool quantization_greedy_approach(
      const QTMesh& M,
      const SizeMapR& sizemap,
      vector<id>& edge_n) {
    info("quantization of QTMesh ...");
    edge_n.clear();
    edge_n.resize(M.edges.size(),0);

    /* Compute ideal number of points for each curve */
    vector<double> edge_nx(M.edges.size(),0.);
    vector<pair<double,id>> nx_edge(M.edges.size());
    F(e,M.edges.size()) {
      double clen = 0.;
      bool okl = edge_pts_length(M.edges[e].pts, true, sizemap, clen);
      if (!okl) {
        error("TEdge {}: failed to compute polyline length, details: {}", e, M.edges[e]);
        if (ERROR_VISU) debug_show_edge_in_view(M, e, "error_polyline_"+std::to_string(e));
        return false;
      }
      // double nx = clen / target_edge_len;
      double nx = clen;
      edge_nx[e] = nx;
      nx_edge[e] = {nx, e};
    }
    std::sort(nx_edge.begin(), nx_edge.end());

    constexpr bool USE_DOUBLE_DIRECTED_GRAPH_INF = true;
    constexpr bool USE_DOUBLE_DIRECTED_GRAPH = true;
    constexpr bool GRAPH_VERSION = true;
    constexpr bool USE_ONE_WAY = true;
    if (USE_DOUBLE_DIRECTED_GRAPH_INF) {
      info("use DOUBLE DIRECTED GRAPH with INF node (experimental)");
    } else if (USE_DOUBLE_DIRECTED_GRAPH) {
      info("use DOUBLE DIRECTED GRAPH (experimental)");
    } else if (GRAPH_VERSION) {
      info("use GRAPH_VERSION");
      if (USE_ONE_WAY) info("use ONE_WAY tchord propagation");
    }

    if (USE_DOUBLE_DIRECTED_GRAPH_INF) {
      vector<id3> gedges; /* graph edges, triplet (gv1,gv2,f) */
      vector<vector<id> > gv2ge; /* graph vertex to graph edges */
      bool okbg = build_double_directed_graph_from_QTMesh(M, gedges, gv2ge, true);
      RFC(!okbg, "failed to build double directed graph from QTMesh");
      RFC(gv2ge.size() != 2*M.edges.size() && gv2ge.size() != 2*M.edges.size() + 1, "wrong number of graph vertices");
      debug_show_graph_in_view(M, gedges, gv2ge, "ddg");
      vector<id> edges_to_0;
      F(gvStart,2*M.edges.size()) {
        id e = gvStart / 2;
        if (edge_n[e] != 0) continue;

        // TODO: also append value if edge_n[e] different from rounded nx ? -> in second pass, try to improve

        vector<id> tchord;
        bool oktc = tchord_propagation_in_double_directed_graph_simple(gedges, gv2ge, edge_nx, edge_n, gvStart, tchord, M);
        if (!oktc || tchord.size() == 0) {
          warn("failed to propagate tchord in double directed graph from gv = {}", gvStart);
          edges_to_0.push_back(gvStart/2);
          continue;

          error("failed to propagate tchord in double directed graph from gv = {}", gvStart);
          error("  tedge {}: {}", e, M.edges[e]);
          if (ERROR_VISU) {
            // debug_show_qtmesh_in_view(M, "qtmesh");
            debug_show_edge_in_view(M, e, "qprob_e"+std::to_string(e));
          }
          return false;
        }

        // if (ERROR_VISU) {
        //   DBG(e,tchord);
        //   debug_show_tchord_in_view(M, tchord, "_dbg_e"+std::to_string(e));
        // }

        double diff_avg = 0.;
        double diff_min = DBL_MAX;
        F(j,tchord.size()) {
          id e2 = tchord[j];
          diff_avg += (edge_nx[e2] - double(edge_n[e2]));
          diff_min = std::min(diff_min, std::abs(edge_nx[e2] - double(edge_n[e2])));
        }
        diff_avg /= double(tchord.size());
        constexpr bool USE_MIN = true;
        int inc = 0;
        if (USE_MIN) {
          inc = (int) std::floor(diff_min);
        } else {
          inc = (int) std::floor(diff_avg);
        }
        if (inc <= 0) inc = 1;
        F(j,tchord.size()) {
          id e2 = tchord[j];
          edge_n[e2] += inc;
        }
      }
      if (edges_to_0.size() > 0) {
        warn("edge where propagation failed: {}", edges_to_0);
      }
    } else if (USE_DOUBLE_DIRECTED_GRAPH) {
      vector<id3> gedges; /* graph edges, triplet (gv1,gv2,f) */
      vector<vector<id> > gv2ge; /* graph vertex to graph edges */
      bool okbg = build_double_directed_graph_from_QTMesh(M, gedges, gv2ge);
      RFC(!okbg, "failed to build double directed graph from QTMesh");
      RFC(gv2ge.size() != 2*M.edges.size(), "wrong number of graph vertices");
      /* Append integer values to edge_n by using t-chord propagation */
      F(pass,2) {
        /* pass = 0: all the open t-chods that start on the boundary */
        /* pass = 1: all the closed t-chords that stay inside, or open t-chord that starts inside */
        F(gvStart,gv2ge.size()) {
          id e = gvStart / 2;
          if (edge_n[e] != 0) continue;
          if (pass == 0 && (gvStart == 2*e+1 ||  gv2ge[2*e+1].size() != 0)) continue;
          if (pass == 1 && (gv2ge[2*e+0].size() == 0 || gv2ge[2*e+1].size() == 0)) continue;

          // TODO: also append value if edge_n[e] different from rounded nx ? 

          vector<id> tchord;
          bool oktc = tchord_propagation_in_double_directed_graph(gedges, gv2ge, edge_nx, edge_n, gvStart, tchord, M);
          if (!oktc || tchord.size() == 0) {
            error("failed to propagate tchord in double directed graph from gv = {}", gvStart);
            error("  tedge {}: {}", e, M.edges[e]);
            if (ERROR_VISU) {
              debug_show_qtmesh_in_view(M, "qtmesh");
              debug_show_edge_in_view(M, e, "qprob_e"+std::to_string(e));
            }
            return false;
          }

          if (ERROR_VISU && intersection(tchord,M.faces[2].edges).size() > 0) {
            DBG(pass,e,tchord);
            debug_show_tchord_in_view(M, tchord, "_dbg_e"+std::to_string(e));
          }

          double diff_avg = 0.;
          double diff_min = DBL_MAX;
          F(j,tchord.size()) {
            id e2 = tchord[j];
            diff_avg += (edge_nx[e2] - double(edge_n[e2]));
            diff_min = std::min(diff_min, std::abs(edge_nx[e2] - double(edge_n[e2])));
          }
          diff_avg /= double(tchord.size());
          constexpr bool USE_MIN = true;
          int inc = 0;
          if (USE_MIN) {
            inc = (int) std::floor(diff_min);
          } else {
            inc = (int) std::floor(diff_avg);
          }
          if (inc <= 0) inc = 1;
          F(j,tchord.size()) {
            id e2 = tchord[j];
            edge_n[e2] += inc;
          }
        }
      }
    } else if (GRAPH_VERSION) {
      vector<id3> gedges; /* graph edges, triplet (e1,e2,f) */
      vector<vector<id> > e2ge; /* QTMesh edge to graph edges */
      bool okbg = build_graph_from_QTMesh(M, gedges, e2ge);
      RFC(!okbg, "failed to build graph from QTMesh");
      RFC(e2ge.size() != M.edges.size(), "wrong number of graph edges");
      vector<bool> eIsStop(M.edges.size(),false);
      FC(e,M.edgeToFaces.size(),M.edgeToFaces[e].size() != 2) eIsStop[e] = true;

      /* Append integer values to edge_n by using t-chord propagation */
      F(pass,2) {
        F(i,nx_edge.size()) {
          id e = nx_edge[i].second;
          if (edge_n[e] != 0) continue;
          if (USE_ONE_WAY) {
            if (pass == 0 && e2ge[e].size() != 1) continue;
            if (pass == 1 && e2ge[e].size() != 2) continue;
          } else {
            if (pass == 1) continue;
          }

          // TODO: also append value if edge_n[e] different from rounded nx ? 

          vector<id> tchord;
          bool oktc = false;
          if (USE_ONE_WAY) {
            oktc = tchord_propagation_one_way(gedges, e2ge, edge_nx, edge_n, e, tchord, M);
          } else {
            oktc = tchord_propagation(gedges, e2ge, eIsStop, edge_nx, edge_n, e, tchord, M);
          }
          if (!oktc || tchord.size() == 0) {
            error("failed to propagate tchord in graph from e = {}", e);
            error("  tedge {}: {}", e, M.edges[e]);
            error("  tvertex {}: {}", M.edges[e].vertices[0], M.vertices[M.edges[e].vertices[0]]);
            error("  tvertex {}: {}", M.edges[e].vertices[1], M.vertices[M.edges[e].vertices[1]]);
            if (ERROR_VISU) {
              debug_show_qtmesh_in_view(M, "qtmesh");
              debug_show_edge_in_view(M, e, "qprob_e"+std::to_string(e));
            }
            return false;
          }
          // debug_show_tchord_in_view(M, tchord, "view_tc"+std::to_string(e)); 

          double diff_avg = 0.;
          double diff_min = DBL_MAX;
          F(j,tchord.size()) {
            id e2 = tchord[j];
            diff_avg += (edge_nx[e2] - double(edge_n[e2]));
            diff_min = std::min(diff_min, std::abs(edge_nx[e2] - double(edge_n[e2])));
          }
          diff_avg /= double(tchord.size());
          constexpr bool USE_MIN = true;
          int inc = 0;
          if (USE_MIN) {
            inc = (int) std::floor(diff_min);
          } else {
            inc = (int) std::floor(diff_avg);
          }
          if (inc <= 0) inc = 1;
          F(j,tchord.size()) {
            id e2 = tchord[j];
            edge_n[e2] += inc;
          }
        }
      }
    } else {
      /* Append integer values to edge_n by using t-chord propagation */
      F(i,nx_edge.size()) {
        id e = nx_edge[i].second;
        if (edge_n[e] != 0) continue;
        // TODO: also append value if edge_n[e] different from rounded nx ? 

        vector<id> tchord;
        bool oktc = tchord_propagation(M, edge_nx, e, tchord);
        if (!oktc || tchord.size() == 0) {
          error("failed to propagate tchord from e = {}", e);
          return false;
        }

        double nx_avg = 0.;
        F(j,tchord.size()) {
          id e2 = tchord[j];
          nx_avg += (edge_nx[e2] - double(edge_n[e2]));
        }
        nx_avg /= double(tchord.size());
        int inc = (int) std::round(nx_avg);
        if (inc <= 0) inc = 1;
        F(j,tchord.size()) {
          id e2 = tchord[j];
          edge_n[e2] += inc;
        }
      }
    }


    F(e,M.edges.size()) {
      debug("  e={},edge={} | nx = {} -> n = {}]", e, M.edges[e], edge_nx[e], edge_n[e]);
    }

    constexpr bool VERIFY_QUANTIZATION = true;
    if (VERIFY_QUANTIZATION) {
      F(f,M.faces.size()) {
        const TFace& tf = M.faces[f];
        id4 side_n = {0,0,0,0};
        F(le,tf.edges.size()) {
          id e = tf.edges[le];
          uint8_t side = tf.edge_sides[le];
          if (side > 3) {
            error("Quantization verification | face {}, edge {}: side={}", f, e, id(side));
            return false;
          }
          // if (edge_n[e] == 0) {
          //   error("Quantization verification | face {}, edge {}, side={}: n = {} (nx = {})",
          //       f, e, id(side), edge_n[e], edge_nx[e]);
          //   error("  face {}: {}", f, tf);
          //   F(le,tf.edges.size()) {
          //     id e = tf.edges[le];
          //     error("    edge {} (n={},nx={}): {}", e, edge_n[e], edge_nx[e], M.edges[e]);
          //   }
          //   return false;
          // }
          side_n[side] += edge_n[e];
        }
        if (side_n[0] != side_n[2] || side_n[1] != side_n[3] || side_n[0] == 0 || side_n[1] == 0) {
          error("Quantization verification | face {}: side_n = {}  (edges = {})",
              f, side_n, tf.edges);
          error("  face {}: {}", f, tf);
          F(le,tf.edges.size()) {
            id e = tf.edges[le];
            error("    edge {} (n={},nx={}): {}", e, edge_n[e], edge_nx[e], M.edges[e]);
          }
          if (ERROR_VISU) {
            debug_show_qtmesh_in_view(M, "qtmesh");
            debug_show_face_in_view(M, f, "qprob_f"+std::to_string(f), edge_n);
          }
          return false;
        }
      }
    }

    return true;
  }

  bool generate_quad_mesh_from_quantization(
      const QTMesh& M,
      const vector<id>& edge_n,
      const SizeMapR& sizemap,
      const BoundaryProjector* projector,
      QMesh& Q) {
    info("generate quad mesh from quantization ...");

    /* Vertices from QTMesh vertices */
    vector<id> old2new(M.vertices.size(),NO_ID);
    {
      Q.points.clear();
      Q.size.clear();
      F(v,M.vertices.size()) {
        const TVertex& tv = M.vertices[v];
        double h = sizemap.eval(tv.pt);
        id nv = add_vertex(Q, tv.pt, h, tv.entity);
        old2new[v] = nv;
      }
    }

    /* Edge collapses (experimental) */
    FC(e,M.edges.size(),edge_n[e] == 0.) {
      id v1 = M.edges[e].vertices[0];
      id v2 = M.edges[e].vertices[1];
      id nv1 = old2new[v1];
      old2new[v2] = nv1;
      warn("edge {}, quantization length is 0, trying collapse {}-{}",e,v1,v2);
    }


    /* Vertices from subdivision of QTMesh edges */
    vector<vector<id> > edge2nivert(M.edges.size());
    FC(e,M.edges.size(),edge_n[e] > 0.) {
      size_t nb_ipts = edge_n[e] - 1;
      const vector<vec3>& pts = M.edges[e].pts;
      vector<vec3> ipts;
      vector<double> newSizes;
      /* warning: call the gmsh API (via sizemap.eval()) */
      bool oks = compute_subdivided_edge_internal_points(pts, nb_ipts, sizemap, ipts, newSizes);
      if (!oks) {
        error("failed to sample edge {}, nb_ipts={}", e, nb_ipts);
        return false;
      }
      pair<int,int> entity = M.edges[e].entity;
      vector<id> nvert;
      F(k,ipts.size()) {
        double h = newSizes[k];
        vec3 pt = ipts[k];
        id nv = add_vertex(Q, pt, h, entity);
        nvert.push_back(nv);
      }
      edge2nivert[e] = nvert;
    }

    /* Loop over faces, create interal vertices and quads */
    F(f,M.faces.size()) {
      const TFace& face = M.faces[f];
      vector<vector<id>> side_edges(4);
      vector<vector<id>> side_edge_invert(4);
      vector<bool> done(face.edges.size(),false);
      id le0 = 0; /* initial edge such that previous edge is in a different side */
      F(le,face.edges.size()) {
        id lep = (face.edges.size()+le-1)%face.edges.size();
        id s = face.edge_sides[le];
        id sp = face.edge_sides[lep];
        if (s != sp) {
          le0 = le;
          break;
        }
      }
      id2 prev = edge_vertices(M.edges[face.edges[le0]],face.edge_orient_invert[le0]);
      for (size_t i = le0; i < le0 + face.edges.size(); ++i) {
        id le = i % face.edges.size();
        id e = face.edges[le];
        id s = face.edge_sides[le];
        if (edge_n[e] == 0) continue;
        side_edges[s].push_back(e);
        side_edge_invert[s].push_back(face.edge_orient_invert[le]);
      }
      // warning/note: if face.edge_orient_invert[le0] = true, not sure if it works
      // if (face.edge_orient_invert[le0]) {
      //   warn("(not sure if ok) f={}, le0={}: edge orient invert = true", f, le0);
      // }

      // DBG("-----");
      // DBG(f);
      // DBG(side_edges[0]);
      // DBG(side_edges[1]);
      // DBG(side_edges[2]);
      // DBG(side_edges[3]);
      vector<vector<vec3>> side_points(4);
      vector<vector<id>> side_nvertices(4);
      id4 patchNV;
      F(s,4) {
        F(le,side_edges[s].size()) {
          id e = side_edges[s][le];
          bool inv = side_edge_invert[s][le];
          id2 ext = M.edges[e].vertices;
          id2 next = {old2new[ext[0]],old2new[ext[1]]};
          if (next[0] == NO_ID || next[1] == NO_ID) {
            error("next = {}", next);
            return false;
          }
          vector<id> nivert = edge2nivert[e]; /* do not contain extremities */
          if (inv) {
            std::reverse(next.begin(),next.end());
            std::reverse(nivert.begin(),nivert.end());
          }
          side_points[s].push_back(Q.points[next[0]]);
          if (le != 0) side_nvertices[s].push_back(next[0]);
          F(j,nivert.size()) {
            side_points[s].push_back(Q.points[nivert[j]]);
            side_nvertices[s].push_back(nivert[j]);
          }
          if (le == side_edges[s].size()-1) {
            side_points[s].push_back(Q.points[next[1]]);
          }
          if (le == 0) patchNV[s] = next[0];
        }
        // DBG(s, side_nvertices[s].size(), side_points[s].size());
        // DBG(side_points[s]);
        // DBG(side_nvertices[s]);
      }

      /* Create the interior points */
      vector<vec3> ipts;
      if (side_points[0].size() > 2 && side_points[1].size() > 2)  {
        bool oktfi = transfinite_interpolation(side_points[0],side_points[1],side_points[2],side_points[3], ipts);
        if (!oktfi) {
          error("generate quads, failed to TFI face {}", f);
          error("  side 0 points: {}", side_points[0]);
          error("  side 1 points: {}", side_points[1]);
          error("  side 2 points: {}", side_points[2]);
          error("  side 3 points: {}", side_points[3]);
          return false;
        }
      }
      vector<id> qVertices(ipts.size(),NO_ID);
      F(i,ipts.size()) {
        vec3 pt = ipts[i];
        pair<int,int> nvEntity = face.entity;
        if (projector != NULL) {
          bool oku = update_entity_and_project(pt,nvEntity,*projector);
          RFC(!oku, "interior point {}: failed to update entity and project", pt);
        }
        double h = sizemap.eval(pt); /* call the gmsh API */
        if (h == DBL_MAX) {
          error("probe failed at new patch interior vertex");
          return false;
        }
        id nv = add_vertex(Q, pt, h, nvEntity);
        qVertices[i] = nv;
      }
      /* Generate refined quads in patch */
      std::reverse(side_nvertices[2].begin(),side_nvertices[2].end());
      std::reverse(side_nvertices[3].begin(),side_nvertices[3].end());
      vector<vector<id>> allVertices(2+side_nvertices[0].size());
      F(i,allVertices.size()) allVertices[i].resize(2+side_nvertices[1].size(),NO_ID);
      /* corners */
      allVertices[0][0]         = patchNV[0];
      allVertices.back()[0]     = patchNV[1];
      allVertices.back().back() = patchNV[2];
      allVertices[0].back()     = patchNV[3];
      /* boundaries */
      F(i,side_nvertices[0].size()) allVertices[i+1][0] = side_nvertices[0][i];
      F(i,side_nvertices[2].size()) allVertices[i+1].back() = side_nvertices[2][i];
      F(j,side_nvertices[1].size()) allVertices.back()[1+j] = side_nvertices[1][j];
      F(j,side_nvertices[3].size()) allVertices[0][1+j] = side_nvertices[3][j];
      /* interior */
      F(i,side_nvertices[0].size()) F(j,side_nvertices[1].size()) {
        allVertices[1+i][1+j] = qVertices[side_nvertices[0].size()*j+i];
      }

      F(i,side_nvertices[0].size()+1) F(j,side_nvertices[1].size()+1) {
        id4 vert;
        vert[0] = allVertices[i][j];
        vert[1] = allVertices[1+i][j];
        vert[2] = allVertices[1+i][1+j];
        vert[3] = allVertices[i][1+j];
        add_quad(Q, vert, f, face.entity.second);
      }
    }

    Q.quad_neighbors.clear();

    info("quad mesh: {} vertices, {} quads", Q.points.size(), Q.quads.size());

    return true;
  }

  bool generate_quad_mesh_via_tmesh_quantization(
      const std::string& modelName,
      int sizemapTag,
      double size_min,
      double size_max,
      QMesh& M,
      const BoundaryProjector* projector,
      bool repair_decomposition) {
    if (!QMT_QZ_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_QZ_Utils::global_gmsh_initialized = true;
    }

    if (size_min == 0 && size_max == 1.e22) {
      double xmin, ymin, zmin, xmax, ymax, zmax;
      gmsh::model::getBoundingBox(-1,-1,xmin,ymin,zmin,xmax,ymax,zmax);
      double h = 0.08 * length({xmax-xmin,ymax-ymin,zmax-zmin});
      warn("size_min = {} and size_max = {}, using size_min = {} (0.08 of bounding box diagonal)", size_min, size_max, h);
      size_min = h;
    }

    QTMesh tM;
    constexpr bool NEW_VERSION = true;
    if (NEW_VERSION) {
      bool okq = generate_qtmesh_from_cut_mesh(modelName, tM, projector, repair_decomposition);
      if (!okq) {
        error("failed to generate QTMesh (quad mesh with T-junctions)");
        return false;
      }
    } else {
      bool okq = generate_qtmesh_from_gmsh_colored_triangulation(modelName, tM, true);
      if (!okq) {
        error("failed to generate QTMesh (quad mesh with T-junctions)");
        return false;
      }
    }

    double target_edge_len = 1.;
    if (size_min != 0.) {
      target_edge_len = size_min;
    } else if (size_max != 1.e22) {
      target_edge_len = size_max;
    }
    info("target edge length: {}", target_edge_len);

    SizeMapR sizemap(sizemapTag,target_edge_len);

    vector<id> edge_n(tM.edges.size(),0);
    bool okqt = quantization_greedy_approach(tM, sizemap, edge_n);
    if (!okqt) {
      error("failed to compute quantization of QTMesh");
      return false;
    }
    bool okg = generate_quad_mesh_from_quantization(tM, edge_n, sizemap, projector, M);
    if (!okg) {
      error("failed to generate quad mesh from quantization");
      return false;
    }

    return true;
  }

  bool fill_vertex_sizes_from_sizemap(QMesh& M, int sizemapTag, double size_uniform) {
    if (!QMT_QZ_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_QZ_Utils::global_gmsh_initialized = true;
    }
    if (size_uniform == 0. && sizemapTag < 0) {
      error("wrong size map tag: {}", sizemapTag);
      return false;
    }

    SizeMapR sizemap(sizemapTag,size_uniform);

    vector<bool> used(M.points.size(),false);
    FC(c,M.quads.size(),M.quads[c][0] != NO_ID)  F(lv,4) used[M.quads[c][lv]] = true;

    FC(v,M.points.size(),used[v]) {
      vec3 pt = M.points[v];
      double val = sizemap.eval(pt);
      if (val == DBL_MAX) {
        error("size map probing failed at pt = {}", pt);
      }
      M.size[v] = val;
    }

    return true;
  }
}


