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
#include <queue>
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
}

namespace QMT_QZ_Utils {
  using namespace QMT;
  using namespace QMT_Utils;

  bool global_gmsh_initialized = false;

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


  /* warning: call gmsh API */
  bool getCurveOrderedVertices(int curve, vector<id>& vertices, vector<vec3>& points, id vStart) {
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
        warn("SizeMapR constructor, using field from tag {}", tag);
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

  bool compute_edge_sides_from_angles(QTMesh& M, id f) {
    vector<id>& edges = M.faces[f].edges;
    vector<uint8_t>& sides = M.faces[f].edge_sides;
    if (edges.size() < 4) {
      return false;
    } else if (edges.size() == 4) {
      F(le,edges.size()) sides[le] = le;
      return true;
    }

    /* Remaining case: there are more than 4 edges, each edge
     * must be assigned a side (0,1,2,3) to have a quad layout 
     * (with T-junctions) structure */

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
        tgc = ec.pts[ec.pts.size()-1] - ec.pts[ec.pts.size()-2];
      } else {
        tgc = ec.pts[0] - ec.pts[1];
      }
      double lp = length(tgp);
      double lc = length(tgc);
      constexpr double EPS_LEN = 1.e-14;
      if (lp < EPS_LEN || lc < EPS_LEN) {
        error("face {}, {}-{} local edges: tangent length too small, cannot compute angle, length(tgp) = {}, length(tgc) = {}", f, lep, le, lp, lc);
        return true;
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
    F(i,4) isCorner[angle_le[i].second] = true;

    /* Set the sides */
    uint8_t cs = 0;
    F(le,edges.size()) {
      if (isCorner[le]) {
        cs += 1;
      }
      sides[le] = cs % 4;
    }

    return true;
  }

  bool generate_qtmesh_from_gmsh_colored_triangulation(
      const std::string& modelName,
      QTMesh& M,
      const std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity) {
    if (!QMT_QZ_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_QZ_Utils::global_gmsh_initialized = true;
    }
    info("generate QTMesh (quad w/ T-jonctions) from gmsh colored triangulation ...");

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
        auto it = entityToInitialEntity->find({0,node});
        if (it != entityToInitialEntity->end()) entity = it->second;

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
        bool okc = getCurveOrderedVertices(std::abs(curve), vertices, points, v1);
        if (!okc) {
          error("curve = {}, failed to get curve vertices ...", curve);
          return false;
        }
        if (points.size() < 2) {
          error("curve = {}, not enough points: {}", curve, points);
          return false;
        }
        pair<int,int> entity = {-1,-1};
        auto it = entityToInitialEntity->find(curves[i]);
        if (it != entityToInitialEntity->end()) entity = it->second;

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
          error("surface {}: not enough boundary curves (min. is 4): {}", surfaces[s], sBdr);
          ok = false;
          continue;
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
        auto it = entityToInitialEntity->find(surfaces[s]);
        if (it != entityToInitialEntity->end()) entity = it->second;
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
      info("  face {}: {}", f, M.faces[f]);
    }

    gmsh::model::setCurrent(cname);
    return true;
  }

  bool edge_pts_length(const std::vector<vec3>& pts, bool use_sizemap, const SizeMapR& sizemap, double& curveLen) {
    /* Size map size(t) */
    vector<double> size(pts.size(),0.);
    if (use_sizemap) {
      F(i, size.size()) size[i] = sizemap.eval(pts[i]);
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

    return true;
  }

  /* warning: call the gmsh API (via sizemap.eval()) */
  bool compute_subdivided_edge_internal_points(const std::vector<vec3>& pts, size_t N, const SizeMapR& sizemap, vector<vec3>& newPts) {
    newPts.clear();
    if (N == 0) return true;

    /* Size map size(t) */
    vector<double> size(pts.size(),0.);
    F(i, size.size()) size[i] = sizemap.eval(pts[i]);

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
            newPts.push_back(pt);
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
            newPts.push_back(pt);
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

  bool unroll_parent(const vector<id>& parent, id e, vector<id>& path) {
    if (e == NO_ID) return false;
    if (parent[e] == NO_ID) return false;
    path.clear();
    path.push_back(e);
    while(parent[path.back()] != path.back()) {
      path.push_back(parent[path.back()]);
      if (parent[path.back()] == NO_ID) return false;
    }
    std::reverse(path.begin(),path.end());
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

    constexpr bool VERB = false;
    if (VERB) info("---- tchord from eStart = {}", eStart);
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
          parent[oe] = e;
          Q.push({edge_nx[oe],oe});
          direction[oe] = (e == eStart) ? lf : direction[e];
          if (VERB) info("---- Q+=({},{})",edge_nx[oe],oe);
          prop = true;
        }
        face_side_done[f][s] = true;
        if (all_finished) break;
      }
      if (all_finished) break;
      if (!prop) {
        finished[direction[e]] = e;
        if (VERB) info("---- ! no prop, finished[{}] = {}", direction[e], e);
      }
      all_finished = true;
      FC(i,finished.size(),finished[i] == NO_ID) all_finished = false;
      if (all_finished) break;
    }

    if (!all_finished) {
      error("failed to build the t-chord");
      if (VERB) F(i,finished.size()) info("- finished[{}]={}",i,finished[i]);
      return false;
    }

    F(i,finished.size()) {
      vector<id> path;
      bool oku = unroll_parent(parent, finished[i], path);
      if (!oku) {
        error("failed to unroll parent chain for finished[{}]={}", i, finished[i]);
      }
      F(j,path.size()) tchord.push_back(path[j]);
    }
    sort_unique(tchord);

    return true;
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
        error("curve {}: failed to compute polyline length", e);
        return false;
      }
      // double nx = clen / target_edge_len;
      double nx = clen;
      edge_nx[e] = nx;
      nx_edge[e] = {nx, e};
    }
    std::sort(nx_edge.begin(), nx_edge.end());

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

    F(e,M.edges.size()) {
      info("  e={},edge={} | nx = {} -> n = {}]", e, M.edges[e], edge_nx[e], edge_n[e]);
    }

    return true;
  }

  bool generate_quad_mesh_from_quantization(
      const QTMesh& M,
      const vector<id>& edge_n,
      const SizeMapR& sizemap,
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

    /* Vertices from subdivision of QTMesh edges */
    vector<vector<id> > edge2nivert(M.edges.size());
    FC(e,M.edges.size(),edge_n[e] > 0.) {
      size_t nb_ipts = edge_n[e] - 1;
      const vector<vec3>& pts = M.edges[e].pts;
      vector<vec3> ipts;
      /* warning: call the gmsh API (via sizemap.eval()) */
      bool oks = compute_subdivided_edge_internal_points(pts, nb_ipts, sizemap, ipts);
      if (!oks) {
        error("failed to sample edge {}, nb_ipts={}", e, nb_ipts);
        return false;
      }
      pair<int,int> entity = M.edges[e].entity;
      vector<id> nvert;
      F(k,ipts.size()) {
        double h = sizemap.eval(ipts[k]); /* call the gmsh API */
        id nv = add_vertex(Q, ipts[k], h, entity);
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
        side_edges[s].push_back(e);
        side_edge_invert[s].push_back(face.edge_orient_invert[le]);
      }
      // warning/note: if face.edge_orient_invert[le0] = true, not sure if it works
      if (face.edge_orient_invert[le0]) {
        warn("(not sure if ok) f={}, le0={}: edge orient invert = true", f, le0);
      }

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
          error("generate quads, failed to TFI");
          return false;
        }
      }
      vector<id> qVertices(ipts.size(),NO_ID);
      F(i,ipts.size()) {
        double h = sizemap.eval(ipts[i]); /* call the gmsh API */
        id nv = add_vertex(Q, ipts[i], h, face.entity);
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
      const std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity) {
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
    bool okq = generate_qtmesh_from_gmsh_colored_triangulation(modelName, tM, entityToInitialEntity);
    if (!okq) {
      error("failed to generate QTMesh (quad mesh with T-junctions)");
      return false;
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
    if (!okq) {
      error("failed to compute quantization of QTMesh");
      return false;
    }
    bool okg = generate_quad_mesh_from_quantization(tM, edge_n, sizemap, M);
    if (!okg) {
      error("failed to generate quad mesh from quantization");
      return false;
    }

    return true;
  }
}

