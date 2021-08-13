// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblBrepMesh.h"

#include <map>
#include <queue>
#include <unordered_map>
#include <numeric>

// Gmsh includes
#include "GEntity.h"
#include "robin_hood.h"

// QuadMeshingTools includes
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

// HexMeshingTools includes
#include "hblLogging.hpp"
#include "hblUtils.h"
#include "hblTypes.hpp"

/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)

using std::vector;
using std::map;
using std::array;
using std::pair;

using namespace CppUtils;
using namespace ArrayGeometry;


namespace hbl {
  const double EPS0 = 1.e-15;

  template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
         typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
         using unordered_map = robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

  template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key>,
         size_t MaxLoadFactor100 = 80>
         using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

  struct id2Hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };


  vector<id> face_vertices_from_edges(const BrepMesh& M, const vector<id>& edges) {
    vector<id2> edge_pairs(edges.size());
    F(j,edge_pairs.size()) edge_pairs[j] = M.edges[edges[j]].vertices;
    vector<id> overt;
    getOrderedVerticesFromEdges(edge_pairs,overt);
    return overt;
  }

  bool face_vertices(const BrepMesh& M, id f, vector<id>& vert) {
    size_t n = 0;
    if (vert.size() < M.faces[f].edges.size()) vert.resize(M.faces[f].edges.size());
    F(le,M.faces[f].edges.size()) {
      id e = M.faces[f].edges[le];
      bool inv = M.faces[f].edge_orient_invert[le];
      id v = inv ? M.edges[e].vertices[1] : M.edges[e].vertices[0];
      vert[le] = v;
      n += 1;
    }
    vert.resize(n);
    return n;
  }

  vector<id> face_vertices(const BrepMesh& M, id f) {
    vector<id> vert(2*M.faces[f].edges.size());
    face_vertices(M, f, vert);
    return vert;
  }

  id quad_opposite_edge(const BrepMesh& M, id f, id e) {
    if (M.faces[f].edges.size() != 4) {
      error("quad_opposite_edge() called on face {} with {} edges", f, M.faces[f].edges.size());
      return NO_ID;
    }
    id2 in_vert = M.edges[e].vertices;
    id leIn = NO_ID;
    id oe = NO_ID;
    F(le,4) {
      id2 cur_vert = M.edges[M.faces[f].edges[le]].vertices;
      if (cur_vert == in_vert) {
        leIn = le;
      } else {
        if (cur_vert[0] == in_vert[0] || cur_vert[1] == in_vert[0]) continue;
        if (cur_vert[0] == in_vert[1] || cur_vert[1] == in_vert[1]) continue;
        oe = M.faces[f].edges[le];
      }
    }
    if (leIn == NO_ID) {
      error("quad_opposite_edge(): input edge {} not found in face {}, edges: {}", e, f, M.faces[f].edges);
      return NO_ID;
    }
    if (oe == NO_ID) {
      error("quad_opposite_edge(): opposite edge to edge {} not found in face {}", e, f);
      return NO_ID;
    }
    return oe;
  }

  id quad_opposite_vertex(const BrepMesh& M, id f, id v) {
    if (M.faces[f].edges.size() != 4) {
      error("quad_opposite_vertex() called on face {} with {} edges", f, M.faces[f].edges.size());
      return NO_ID;
    }
    /*  warning: this function does not assume the edges are sorted (could be simpler else)
     *
     *    v--v1
     *    |  |
     *    X--ov
     */
    id v1 = NO_ID;
    for (id ec: M.faces[f].edges) {
      id ec_v0 = M.edges[ec].vertices[0];
      id ec_v1 = M.edges[ec].vertices[1];
      if (ec_v0 == v) {
        v1 = ec_v1;
      } else if (ec_v1 == v) {
        v1 = ec_v0;
      }
      if (v1 != NO_ID) break;
    }
    id ov = NO_ID;
    for (id ec: M.faces[f].edges) {
      id ec_v0 = M.edges[ec].vertices[0];
      id ec_v1 = M.edges[ec].vertices[1];
      if (ec_v0 == v1 && ec_v1 != v) {
        ov = ec_v1;
      } else if (ec_v1 == v1 && ec_v0 != v) {
        ov = ec_v0;
      }
      if (ov != NO_ID) break;
    }

    return ov;
  }

  id add_vertex(BrepMesh& M, vec3 pt, 
      GEntity* entity, MVertex* origin, bool updateMapping) {
    Vertex bv;
    bv.pt = pt;
    bv.entity = entity;
    bv.origin = origin;
    id nv = M.vertices.size();
    M.vertices.push_back(bv);
    if (updateMapping) {
      M.vertToEdges.resize(nv+1);
    }
    return nv;
  }

  id add_edge(BrepMesh& M, const id2& vertices, 
      GEntity* entity, MLine* origin, bool updateMapping) {
    Edge de;
    de.entity = entity;
    de.vertices = vertices;
    de.origin = origin;
    id ne = M.edges.size();
    M.edges.push_back(de);
    if (updateMapping) {
      M.vertToEdges[vertices[0]].push_back(ne);
      M.vertToEdges[vertices[1]].push_back(ne);
      M.edgeToFaces.resize(ne+1);
    }
    return ne;
  }

  id add_face(BrepMesh& M, const std::vector<id>& edgeIds, 
      GEntity* entity, MElement* origin, bool updateMapping) {
    Face f;
    f.edges.clear();
    f.edge_orient_invert.clear();
    f.edges.push_back(edgeIds[0]);
    f.edge_orient_invert.push_back(false);
    vector<bool> done(edgeIds.size(),false);
    done[0] = true;
    while (f.edges.size() != edgeIds.size()) {
      id cv = f.edge_orient_invert.back() ?
        M.edges[f.edges.back()].vertices[0]: M.edges[f.edges.back()].vertices[1];
      bool found = false;
      FC(i,edgeIds.size(),!done[i]) {
        id e = edgeIds[i];
        id2 vs = M.edges[e].vertices;
        if (vs[0] == cv) {
          f.edges.push_back(e);
          f.edge_orient_invert.push_back(false);
          found = true;
          done[i] = true;
          break;
        } else if (vs[1] == cv) {
          f.edges.push_back(e);
          f.edge_orient_invert.push_back(true);
          found = true;
          done[i] = true;
          break;
        }
      }
      if (!found) {
        error("failed to build a Brep face from edges, not a loop ?");
        F(i,edgeIds.size()) {
          error(" edge {}: {}", edgeIds[i], M.edges[edgeIds[i]].vertices);
        }
        return NO_ID;
      }
    }
    f.entity = entity;
    f.origin = origin;
    id nf = M.faces.size();
    vector<id> uniques = f.edges;
    sort_unique(uniques);
    if (uniques.size() != f.edges.size()) {
      error("new face: {}, from edgeIds = {}", f.edges, edgeIds);
      F(i,edgeIds.size()) {
        error(" edge {}: {}", edgeIds[i], M.edges[edgeIds[i]].vertices);
      }
      return NO_ID;
    }
    M.faces.push_back(f);
    if (updateMapping) {
      for (auto e: f.edges) M.edgeToFaces[e].push_back(nf);
      M.faceToCells.resize(nf+1);
    }
    return nf;
  }

  bool invert_face(BrepMesh& Q, id f) {
    RFC(f >= Q.faces.size(), "wrong index: f={} but {} faces", f, Q.faces.size());
    RFC(Q.faces[f].edges.size() != Q.faces[f].edge_orient_invert.size(), "face {}, wrong sizes", f);

    vector<std::pair<id,bool>> edge_inv(Q.faces[f].edges.size());
    F(j,Q.faces[f].edges.size()) edge_inv[j] = {Q.faces[f].edges[j],Q.faces[f].edge_orient_invert[j]};
    std::reverse(edge_inv.begin(),edge_inv.end());
    F(j,Q.faces[f].edges.size()) {
      Q.faces[f].edges[j] = edge_inv[j].first;
      Q.faces[f].edge_orient_invert[j] = !(edge_inv[j].second);
    }

    return true;
  }

  id add_cell(BrepMesh& M, const vector<id>& faces, 
      GEntity* entity, MElement* origin, bool updateMapping) {
    Cell ce;
    ce.entity = entity;
    ce.faces = faces;
    ce.origin = origin;
    id nc = M.cells.size();
    M.cells.push_back(ce);
    if (updateMapping) {
      for (auto f: faces) M.faceToCells[f].push_back(nc);
    }
    return nc;
  }


  bool cell_vertices(const BrepMesh& M, id c, vector<id>& vert) {
    vert.clear();
    vert.reserve(M.cells[c].faces.size()*6);
    vector<id> fvert(4);
    for (id f: M.cells[c].faces) {
      face_vertices(M, f, fvert);
      append(vert,fvert);
    }
    sort_unique(vert);
    return true;
  }

  vector<id> cell_vertices(const BrepMesh& M, id c) {
    vector<id> vert;
    cell_vertices(M,c,vert);
    return vert;
  }

  vector<id> cell_edges(const BrepMesh& M, id c) {
    vector<id> edges;
    edges.reserve(100);
    for (id f: M.cells[c].faces) {
      append(edges,M.faces[f].edges);
    }
    sort_unique(edges);
    return edges;
  }

  bool cell_edges(const BrepMesh& M, id c, vector<id>& edges) {
    edges.clear();
    edges.reserve(M.cells[c].faces.size()*6);
    for (id f: M.cells[c].faces) {
      append(edges,M.faces[f].edges);
    }
    sort_unique(edges);
    return true;
  }

  bool cell_edges_and_vertices(const BrepMesh& M, id c, vector<id>& edges, vector<id>& vert) {
    edges.clear();
    vert.clear();
    vector<id> fvert;
    for (id f: M.cells[c].faces) {
      append(edges,M.faces[f].edges);
      face_vertices(M, f, fvert);
      append(vert,fvert);
    }
    sort_unique(edges);
    sort_unique(vert);
    return true;
  }

  bool cell_face_vertices(const BrepMesh& M, id c, id lf, std::vector<id>& vert) {
    return face_vertices(M, M.cells[c].faces[lf], vert);
  }

  bool vertex_adjacent_faces(const BrepMesh& M, id v, std::vector<id>& faces) {
    faces.clear();
    for (id e: M.vertToEdges[v]) for (id f: M.edgeToFaces[e]) {
      faces.push_back(f);
    }
    sort_unique(faces);
    return true;
  }

  bool vertex_adjacent_cells(const BrepMesh& M, id v, std::vector<id>& cells) {
    cells.clear();
    for (id e: M.vertToEdges[v]) for (id f: M.edgeToFaces[e]) for (id c: M.faceToCells[f]) {
      cells.push_back(c);
    }
    sort_unique(cells);
    return true;
  }

  void print_cell_details(const BrepMesh& M, const Cell& cell) {
    info("cell details:");
    info("- {} faces: {} ", cell.faces.size(), cell.faces);
    F(i,cell.faces.size()) {
      info("  - face {}: edges: {}, vertices: {}", cell.faces[i], M.faces[cell.faces[i]].edges, face_vertices(M, cell.faces[i]));
    }
    vector<id> edges;
    F(lf,cell.faces.size()) edges = merge(edges,M.faces[cell.faces[lf]].edges);
    vector<id2> edge_verts(edges.size());
    F(i,edge_verts.size()) edge_verts[i] = M.edges[edges[i]].vertices;
    info("- {} edges: {}", edges.size(), edges);
    info("  - edge vertices: {}", edge_verts);
  }

  bool hex_is_valid(const BrepMesh& M, const Cell& cell, bool print_error_details) {
    if (print_error_details) {
      bool ok = hex_is_valid(M, cell, false);
      if (!ok) print_cell_details(M, cell);
      return ok;
    }
    if(cell.faces.size() != 6) {
      if (print_error_details) error("cell is not a hex, {} faces = {}", cell.faces.size(), cell.faces);
      return false;
    }
    vector<id> edges;
    F(lf,cell.faces.size()) append(edges,M.faces[cell.faces[lf]].edges);
    sort_unique(edges);
    if(edges.size() != 12) {
      if (print_error_details) error("cell is not a hex, {} edges = {}", edges.size(), edges);
      return false;
    }
    vector<id> vert;
    F(le,edges.size()) append(vert,{M.edges[edges[le]].vertices[0],M.edges[edges[le]].vertices[1]});
    sort_unique(vert);
    if(vert.size() != 8) {
      if (print_error_details) error("cell is not a hex, {} vertices = {}", vert.size(), vert);
      return false;
    }

    unordered_map<id,id> edge_val;
    unordered_map<id,id> vert_val;
    F(lf,cell.faces.size()) {
      vector<id> vert = face_vertices(M,cell.faces[lf]);
      F(lv,vert.size()) {
        vert_val[vert[lv]] += 1;
      }
      F(le,M.faces[cell.faces[lf]].edges.size()) {
        id e = M.faces[cell.faces[lf]].edges[le];
        edge_val[e] += 1;
      }
    }

    for (auto& kv: edge_val) {
      if (kv.second != 2) {
        if (print_error_details) error("cell is not a hex, edge {} has face-valence {}", kv.first, kv.second);
        return false;
      }
    }
    for (auto& kv: vert_val) {
      if (kv.second != 3) {
        if (print_error_details) error("cell is not a hex, vertex {} has face-valence {}", kv.first, kv.second);
        return false;
      }
    }

    return true;
  }

  bool hex_is_valid(const BrepMesh& M, id c) {
    return hex_is_valid(M, M.cells[c]);
  }

  bool hex_opposite_face_vertices(const BrepMesh& M, id c, const vector<id>& face_vert, vector<id>& op_face_vert) {
    if (face_vert.size() != 4 || op_face_vert.size() != 4) {
      RF("hex_opposite_face_vertices | wrong sizes, face_vert = {}, op_face_vert.size() = {}", face_vert, op_face_vert.size());
    }
    vector<id> hex_edges = cell_edges(M,c);
    vector<id> edges;
    F(le,hex_edges.size()) {
      id v1 = M.edges[hex_edges[le]].vertices[0];
      id v2 = M.edges[hex_edges[le]].vertices[1];
      bool v1_in_bot = inVector(v1,face_vert);
      bool v2_in_bot = inVector(v2,face_vert);
      if (v1_in_bot && !v2_in_bot) {
        edges.push_back(hex_edges[le]);
      } else if (!v1_in_bot && v2_in_bot) {
        edges.push_back(hex_edges[le]);
      }
    }
    F(lv,4) {
      id v = face_vert[lv];
      bool found = false;
      F(le,edges.size()) {
        id2 edge = M.edges[edges[le]].vertices;
        if (edge[0] == v) {
          op_face_vert[lv] = edge[1];
          found = true;
          break;
        } else if (edge[1] == v) {
          op_face_vert[lv] = edge[0];
          found = true;
          break;
        }
      }
      RFC(!found,"hex_opposite_face_vertices | c = {}, vertex not found, opposite of lv = {}, v = {}", c, lv, v);
    }
    return true;
  }

  bool hex_vertices(const BrepMesh& M, id c, vector<id>& hex_vert) {
    if (M.cells[c].faces.size() != 6) {
      error("cell {} is not a hex, faces = {}", c, M.cells[c].faces);
      return false;
    }
    vector<id> bot_vert(4);
    vector<id> top_vert(4);
    face_vertices(M,M.cells[c].faces[0],bot_vert);
    RFC(bot_vert.size() != 4, "hex_vertices | c={}, lf=0 => bot_vert={} (face={}, face edges = {})", 
        c, bot_vert, M.cells[c].faces[0], M.faces[M.cells[c].faces[0]].edges);
    bool oko = hex_opposite_face_vertices(M, c, bot_vert, top_vert);
    RFC(!oko, "failed to get hex opposite vertices for c={}, M.cells[c].faces={}",c,M.cells[c].faces);
    hex_vert.resize(8);
    F(lv,4) hex_vert[lv] = bot_vert[lv];
    F(lv,4) hex_vert[4+lv] = top_vert[lv];
    // if (PARANO) return hex_is_valid(M,M.cells[c],true);
    return true;
  }

  vector<id> hex_vertices(const BrepMesh& M, id c) {
    vector<id> vert(8);
    hex_vertices(M, c, vert);
    return vert;
  }

  id hex_opposite_face(const BrepMesh& M, id c, id f) {
    if (!inVector(f,M.cells[c].faces)) {
      error("face {} not in cell {}",f, c);
      return NO_ID;
    }
    vector<id> fvert(4);
    face_vertices(M,f,fvert);
    vector<id> fvert2(4);
    F(lf,M.cells[c].faces.size()) {
      id of = M.cells[c].faces[lf];
      if (of == f) continue;
      face_vertices(M,of,fvert2);
      if (intersection(fvert,fvert2).size() == 0) {
        return of;
      }
    }
    return NO_ID;
  }

  vector<vec3> points_from_vertices(const BrepMesh& M, const vector<id>& vert) {
    vector<vec3> pts(vert.size());
    F(i,vert.size()) pts[i] = M.vertices[vert[i]].pt;
    return pts;
  }

  vector<vec3> edge_points(const BrepMesh& M, const id2& vert) {
    vector<vec3> pts(vert.size());
    F(i,vert.size()) pts[i] = M.vertices[vert[i]].pt;
    return pts;
  }

  vector<vec3> edge_points(const BrepMesh& M, id f) {
    vector<vec3> pts(2);
    F(i,pts.size()) pts[i] = M.vertices[M.edges[f].vertices[i]].pt;
    return pts;
  }

  vec3 points_center(const vector<vec3>& pts) {
    if (pts.size() == 0) return NO_VEC3;
    vec3 center = {0.,0.,0.};
    F(i,pts.size()) center = center + pts[i];
    center = 1./double(pts.size()) * center;
    return center;
  }

  vec3 edge_center(const BrepMesh& M, id e) {
    vec3 p1 = M.vertices[M.edges[e].vertices[0]].pt;
    vec3 p2 = M.vertices[M.edges[e].vertices[1]].pt;
    return 0.5 * (p1+p2);
  }

  double edge_length(const BrepMesh& M, id e) {
    vec3 p1 = M.vertices[M.edges[e].vertices[0]].pt;
    vec3 p2 = M.vertices[M.edges[e].vertices[1]].pt;
    return length(p2-p1);
  }

  vec3 edge_direction(const BrepMesh& M, id e) {
    vec3 p1 = M.vertices[M.edges[e].vertices[0]].pt;
    vec3 p2 = M.vertices[M.edges[e].vertices[1]].pt;
    return p2 - p1;
  }

  vec3 face_center(const BrepMesh& M, id f) {
    vec3 center = {0.,0.,0.};
    vector<id> vert = face_vertices(M,f);
    vector<vec3> pts = points_from_vertices(M,vert);
    return points_center(pts);
  }

  double face_average_edge_length(const BrepMesh& M, id f) {
    double avg = 0.;
    double n = 0.;
    for (id e: M.faces[f].edges) {
      avg += edge_length(M,e);
      n += 1.;
    }
    if (n == 0.) return DBL_MAX;
    return avg / n;
  }

  vec3 quad_normal(vec3 a, vec3 b, vec3 c, vec3 d) {
    const vec3 t_u = 0.5 * (b+c-a-d);
    const vec3 t_v = 0.5 * (c+d-a-b);
    return cross(t_u,t_v);
  }

  vec3 quad_normal(const BrepMesh& M, id f) {
    vector<id> vert = face_vertices(M,f);
    if (vert.size() != 4) {
      error("quad normal asked but face {} is not a quad", f);
      return NO_VEC3;
    }
    vec3 a = M.vertices[vert[0]].pt;
    vec3 b = M.vertices[vert[1]].pt;
    vec3 c = M.vertices[vert[2]].pt;
    vec3 d = M.vertices[vert[3]].pt;
    return quad_normal(a,b,c,d);
  }

  vec3 face_normal(const BrepMesh& M, id f) {
    vector<id> vert = face_vertices(M,f);
    vec3 n = {0.,0.,0.};
    if (vert.size() == 3) {
      vec3 ab = M.vertices[vert[1]].pt-M.vertices[vert[0]].pt;
      vec3 ac = M.vertices[vert[2]].pt-M.vertices[vert[0]].pt;
      vec3 n_tri = cross(ab,ac);
      n = n + n_tri;
    } else if (vert.size() == 4) {
      return quad_normal(M,f);
    } else {
      vec3 center = {0.,0.,0.};
      if (vert.size() == 0) return NO_VEC3;
      F(i,vert.size()) {
        center = center + M.vertices[vert[i]].pt;
      }
      center = 1./double(vert.size()) * center;
      F(i,vert.size()) {
        vec3 ab = M.vertices[vert[i]].pt-center;
        vec3 ac = M.vertices[vert[(i+1)%3]].pt-center;
        vec3 n_tri = cross(ab,ac);
        n = n + n_tri;
      }
    }
    if(length(n) < EPS0) {
      error("bad face normal ? n = {}", n);
      return NO_VEC3;
    }
    normalize(n);
    return n;
  }

  bool merge_vertices(BrepMesh& H, 
      const vector<id2>& equalities,
      vector<id>& v_old2new,
      vector<id>& e_old2new,
      vector<id>& f_old2new,
      vector<id>& c_old2new) {

    id va,vb;
    {
      id nbi = 0;
      system_reduction_using_graph(H.vertices.size(),equalities,v_old2new,nbi);
      /* compute averaged positions */
      vector<vec3> pos(nbi, {0.,0.,0.});
      vector<Vertex> new_vertices(nbi);
      F(i,new_vertices.size()) new_vertices[i].pt = {0.,0.,0.};
      vector<vector<id>> v_new2old(nbi);
      F(i,H.vertices.size()) v_new2old[v_old2new[i]].push_back(i);
      vector<vector<id>> dim_to_vertices(4);
      F(nv,v_new2old.size()) {
        if (v_new2old[nv].size() == 0) {
          RF("should not happen");
        } else if (v_new2old[nv].size() == 1){
          new_vertices[nv] = H.vertices[v_new2old[nv][0]];
        } else {
          std::sort(v_new2old[nv].begin(),v_new2old[nv].end());
          F(d,4) dim_to_vertices[d].clear();
          F(j,v_new2old[nv].size()) {
            id ov = v_new2old[nv][j];
            int dim = 3;
            if (H.vertices[ov].entity == nullptr) {
              dim = 3;
            } else {
              dim = H.vertices[ov].entity->dim();
            }
            if (dim < 0 || dim > 3) {
              error("merge_vertices | invalid dim, v={}", ov);
              return false;
            }
            dim_to_vertices[dim].push_back(ov);
          }
          bool done = false;
          FC(d,4,dim_to_vertices[d].size() > 0) {
            vec3 pt;
            if (dim_to_vertices[d].size() == 1) {
              pt = H.vertices[dim_to_vertices[d][0]].pt;
            } else {
              pt = points_center(points_from_vertices(H,dim_to_vertices[d]));
            }
            new_vertices[nv] = H.vertices[dim_to_vertices[d][0]];
            new_vertices[nv].pt = pt;
            done = true;
            break;
          }
          RFC(!done,"merge_vertices | no new vertex attach to old vertex ? dim_to_vertices = {}", dim_to_vertices);
        }
      }
      vb = H.vertices.size();
      va = new_vertices.size();
      H.vertices = new_vertices; /* replace vertices */
    }

    /* update edges */
    vector<Edge> new_edges;
    {
      unordered_map<id2,id,id2Hash> existing_edges;
      vector<id2> edge_equalities;
      vector<bool> edge_to_delete(H.edges.size(),false);
      F(i,H.edges.size()) {
        id2 eb = H.edges[i].vertices;
        id2 ea = {v_old2new[eb[0]],v_old2new[eb[1]]};
        if (ea[0] == ea[1]) {
          H.edges[i].vertices = ea;
          edge_to_delete[i] = true;
          continue;
        }
        id2 sea = sorted(ea[0],ea[1]);
        auto it = existing_edges.find(sea);
        if (it == existing_edges.end()) {
          H.edges[i].vertices = ea;
          existing_edges[sea] = i;
        } else {
          H.edges[i].vertices = ea;
          edge_equalities.push_back({id(i),it->second});
        }
      }
      id nbe = 0;
      system_reduction_using_graph(H.edges.size(),edge_equalities,edge_to_delete,e_old2new,nbe);
      new_edges.resize(nbe);
      FC(i,e_old2new.size(),e_old2new[i] != NO_ID) new_edges[e_old2new[i]] = H.edges[i];
    }

    /* update faces */
    vector<bool> face_to_delete(H.faces.size(),false);
    F(i,H.faces.size()) {
      Face nf = H.faces[i];
      nf.edges.clear();
      nf.edge_orient_invert.clear();
      F(j,H.faces[i].edges.size()) {
        id oe = H.faces[i].edges[j];
        bool oinv = H.faces[i].edge_orient_invert[j];
        id2 v1v2 = H.edges[oe].vertices;
        if (oinv) std::reverse(v1v2.begin(),v1v2.end());
        id ne = e_old2new[oe];
        if (ne == NO_ID) continue; /* edge has been removed */
        { /* remove pair of edges after vertex merge (non manifold branch) */
          auto it = std::find(nf.edges.begin(),nf.edges.end(),ne);
          if (it != nf.edges.end()) {
            id pos = it - nf.edges.begin();
            nf.edges.erase(nf.edges.begin()+pos);
            nf.edge_orient_invert.erase(nf.edge_orient_invert.begin()+pos);
            continue;
          }
        }
        id2 new_edge = new_edges[ne].vertices;
        if (new_edge[0] == v1v2[0] && new_edge[1] == v1v2[1]) {
          nf.edges.push_back(ne);
          nf.edge_orient_invert.push_back(false);
        } else if (new_edge[1] == v1v2[0] && new_edge[0] == v1v2[1]) {
          nf.edges.push_back(ne);
          nf.edge_orient_invert.push_back(true);
        } else {
          RF("should not happen");
        }
      }
      if (nf.edges.size() == 0) face_to_delete[i] = true;
      H.faces[i] = nf;
    }
    id eb = H.edges.size();
    id ea = new_edges.size();
    // debug("merge vertices: {} -> {} edges", H.edges.size(), new_edges.size());
    H.edges = new_edges; /* replace edges AFTER update of faces */

    /* remove duplicated faces */
    id fb = H.faces.size();
    id fa = H.faces.size();
    vector<vector<id>> face_edges(H.faces.size());
    const vector<id> COLLAPSED_FACE(1,NO_ID);
    F(f,H.faces.size()) {
      if (face_to_delete[f]) {
        face_edges[f] = COLLAPSED_FACE; /* So this face will be the last in unique faces */
      } else {
        face_edges[f] = H.faces[f].edges;
        std::sort(face_edges[f].begin(),face_edges[f].end());
      }
    }
    vector<vector<id>> f_uniques;
    sort_unique_with_perm(face_edges, f_uniques, f_old2new);
    if (f_uniques.back() == COLLAPSED_FACE) {
      f_uniques.pop_back();
      FC(f,H.faces.size(),face_to_delete[f]) f_old2new[f] = NO_ID;
    }
    if (f_uniques.size() != H.faces.size()) {
      vector<Face> new_faces(f_uniques.size());
      FC(f,H.faces.size(),f_old2new[f] != NO_ID) {
        new_faces[f_old2new[f]] = H.faces[f];
      }
      /* update cells */
      vector<id> cell_faces;
      F(c,H.cells.size()) {
        cell_faces.clear();
        FC(lf,H.cells[c].faces.size(),f_old2new[H.cells[c].faces[lf]] != NO_ID) {
          cell_faces.push_back(f_old2new[H.cells[c].faces[lf]]);
        }
        H.cells[c].faces = cell_faces;
      }
      fa = new_faces.size();
      // info("merge vertices: {} -> {} faces", H.faces.size(), new_faces.size());
      H.faces = new_faces;
    } else {
      f_old2new.clear();
    }

    /* remove duplicated cells */
    id cb = H.cells.size();
    id ca = H.cells.size();
    const vector<id> COLLAPSED_CELL(1,NO_ID);
    vector<vector<id>> cell_faces(H.cells.size());
    vector<bool> cell_to_delete(H.cells.size(),false);
    F(c,H.cells.size()) {
      vector<id> faces = H.cells[c].faces;
      sort_unique(faces);
      if (faces.size() <= 1) {
        cell_faces[c] = COLLAPSED_CELL;
        cell_to_delete[c] = true;
      } else {
        cell_faces[c] = faces;
      }
    }
    vector<vector<id>> c_uniques;
    sort_unique_with_perm(cell_faces, c_uniques, c_old2new);
    if (c_uniques.back() == COLLAPSED_CELL) {
      c_uniques.pop_back();
      FC(c,H.cells.size(),cell_to_delete[c]) c_old2new[c] = NO_ID;
    }
    if (c_uniques.size() != H.cells.size()) {
      vector<Cell> new_cells(c_uniques.size());
      FC(c,H.cells.size(),c_old2new[c] != NO_ID) {
        new_cells[c_old2new[c]] = H.cells[c];
      }
      ca = new_cells.size();
      H.cells = new_cells;
    } else {
      c_old2new.clear();
    }

    debug("merge vertices: {} -> {} vertices, {} -> {} edges, {} -> {} faces, {} -> {} cells", vb, va, eb, ea, fb, fa, cb, ca);
    H.vertToEdges.clear(); /* no longer valid */
    return true;
  }

  bool merge_vertices(BrepMesh& H, const vector<id2>& equalities) {
    vector<id> v_old2new;
    vector<id> e_old2new;
    vector<id> f_old2new;
    vector<id> c_old2new;
    return merge_vertices(H,equalities,v_old2new,e_old2new,f_old2new,c_old2new);
  }

  struct vidHash {
    size_t operator()(const vector<id>& p) const noexcept {
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

  /* Version to merge vertices without moving everything
   * Resulting mesh has "merged" elements (old2new[elem] != elem) */
  bool merge_vertices_light(BrepMesh& H, 
      const vector<id2>& equalities,
      vector<id>& v_old2new,
      vector<id>& e_old2new,
      vector<id>& f_old2new,
      vector<id>& c_old2new) {
    v_old2new.resize(H.vertices.size());
    e_old2new.resize(H.edges.size());
    f_old2new.resize(H.faces.size());
    c_old2new.resize(H.cells.size());
    std::iota(v_old2new.begin(),v_old2new.end(),0);
    std::iota(e_old2new.begin(),e_old2new.end(),0);
    std::iota(f_old2new.begin(),f_old2new.end(),0);
    std::iota(c_old2new.begin(),c_old2new.end(),0);

    vector<bool> vAffected(H.vertices.size(),false);
    id nredir_v = 0;
    {
      /* Merge vertices via greedy aggregation */
      std::vector<std::vector<id> > v2v(H.vertices.size());
      F(i,equalities.size()) {
        v2v[equalities[i][0]].push_back(equalities[i][1]);
        v2v[equalities[i][1]].push_back(equalities[i][0]);
        vAffected[equalities[i][0]] = true;
        vAffected[equalities[i][1]] = true;
      }
      /* BFS aggregation */
      std::deque<id> Q;
      std::vector<bool> visited(H.vertices.size(), false);
      vector<id> _ivert;
      vector<vector<id>> _dim_to_vertices(4);
      FC(i, H.vertices.size(), vAffected[i]) {
        if (visited[i]) continue;
        _ivert.clear();
        Q.clear();
        Q.push_back(i);
        visited[i] = true;
        while(!Q.empty()) {
          id v = Q.front();
          Q.pop_front();
          v_old2new[v] = i;
          if (v != i) {
            nredir_v += 1;
          }
          _ivert.push_back(v);
          F(lv,v2v[v].size()) {
            id v2 = v2v[v][lv];
            if (visited[v2]) continue;
            visited[v2] = true;
            Q.push_back(v2);
          }
        }
        sort_unique(_ivert);
        if (_ivert.size() > 1) { /* Multiple vertices merged together */
          F(d,4) _dim_to_vertices[d].clear();
          for (id ov:_ivert) {
            if (H.vertices[ov].entity == nullptr) {
              error("merge_vertices | no entity for v={} -> entity = {}", ov);
              return false;
            }
            int dim = H.vertices[ov].entity->dim();
            if (dim < 0 || dim > 3) {
              error("merge_vertices | invalid dim, v={} -> entity = {}", ov, H.vertices[ov].entity);
              return false;
            }
            _dim_to_vertices[dim].push_back(ov);
          }
          bool done = false;
          FC(d,4,_dim_to_vertices[d].size() > 0) {
            vec3 pt;
            if (_dim_to_vertices[d].size() == 1) {
              pt = H.vertices[_dim_to_vertices[d][0]].pt;
            } else {
              pt = points_center(points_from_vertices(H,_dim_to_vertices[d]));
            }
            H.vertices[i] = H.vertices[_dim_to_vertices[d][0]];
            H.vertices[i].pt = pt;
            done = true;
            break;
          }
          RFC(!done,"merge_vertices | no new vertex attach to old vertex ? dim_to_vertices = {}", _dim_to_vertices);
        }
      }
    }
    if (nredir_v == 0 || H.edges.size() == 0) return true;
    H.vertToEdges.clear(); /* no longer valid */

    /* update edges */
    id nredir_e = 0;
    vector<bool> eAffected(H.edges.size(),false);
    vector<id> edges_to_empty_after;
    {
      unordered_map<id2,id,id2Hash> existing_edges;
      F(i,H.edges.size()) {
        id2 eb = H.edges[i].vertices;
        if (eb[0] == NO_ID || eb[1] == NO_ID) continue;
        /* ignore edges not touching affected vertices */
        if (!vAffected[eb[0]] && !vAffected[eb[1]]) continue;
        eAffected[i] = true;
        id2 ea = {v_old2new[eb[0]],v_old2new[eb[1]]};
        if (ea[0] == ea[1]) {
          H.edges[i].vertices = {NO_ID,NO_ID};
          e_old2new[i] = NO_ID;
          nredir_e += 1;
          continue;
        }
        id2 sea = sorted(ea[0],ea[1]);
        auto it = existing_edges.find(sea);
        if (it == existing_edges.end()) {
          H.edges[i].vertices = ea;
          e_old2new[i] = i;
          existing_edges[sea] = i;
        } else {
          H.edges[i].vertices = ea;
          e_old2new[i] = it->second;
          nredir_e += 1;
          edges_to_empty_after.push_back(i);
        }
      }
    }
    if (nredir_e == 0 || H.faces.size() == 0) return true;
    H.edgeToFaces.clear(); /* no longer valid */

    /* update faces */
    vector<bool> fAffected(H.faces.size(),false);
    id nredir_f = 0;
    {
      std::unordered_map<vector<id>,id,vidHash> face_hashes;
      F(i,H.faces.size()) {
        bool changed = false;
        for (id e: H.faces[i].edges) if (eAffected[e]) {
          changed = true;
          break;
        }
        if (!changed) continue;
        fAffected[i] = true;

        Face nf = H.faces[i];
        nf.edges.clear();
        nf.edge_orient_invert.clear();
        F(j,H.faces[i].edges.size()) {
          id oe = H.faces[i].edges[j];
          bool oinv = H.faces[i].edge_orient_invert[j];
          id2 v1v2 = H.edges[oe].vertices;
          if (oinv) std::reverse(v1v2.begin(),v1v2.end());
          id ne = e_old2new[oe];
          if (ne == NO_ID) continue; /* edge has been removed */
          { /* remove pair of edges after vertex merge (non manifold branch) */
            auto it = std::find(nf.edges.begin(),nf.edges.end(),ne);
            if (it != nf.edges.end()) {
              id pos = it - nf.edges.begin();
              nf.edges.erase(nf.edges.begin()+pos);
              nf.edge_orient_invert.erase(nf.edge_orient_invert.begin()+pos);
              continue;
            }
          }
          id2 new_edge = H.edges[ne].vertices;
          if (new_edge[0] == v1v2[0] && new_edge[1] == v1v2[1]) {
            nf.edges.push_back(ne);
            nf.edge_orient_invert.push_back(false);
          } else if (new_edge[1] == v1v2[0] && new_edge[0] == v1v2[1]) {
            nf.edges.push_back(ne);
            nf.edge_orient_invert.push_back(true);
          } else {
            RF("merge_vertices_light | should not happen: new_edge = {}, v1v2 = {}", new_edge, v1v2);
          }
        }
        if (nf.edges.size() == 0) {
          f_old2new[i] = NO_ID;
          H.faces[i].edges.clear();
          H.faces[i].edge_orient_invert.clear();
          nredir_f += 1;
          continue;
        } else {
          vector<id> sedges = nf.edges;
          sort_unique(sedges);
          auto it = face_hashes.find(sedges);
          if (it == face_hashes.end()) {
            H.faces[i] = nf;
            face_hashes[sedges] = i;
          } else {
            f_old2new[i] = it->second;
            nredir_f += 1;
            H.faces[i].edges.clear();
            H.faces[i].edge_orient_invert.clear();
          }
        }
      }
    }
    for (id e: edges_to_empty_after) H.edges[e].vertices = {NO_ID,NO_ID};
    if (nredir_f == 0 || H.cells.size() == 0) return true;
    H.faceToCells.clear(); /* no longer valid */

    /* update cells */
    id nredir_c = 0;
    {
      std::unordered_map<vector<id>,id,vidHash> cell_hashes;
      vector<id> _cell_faces;
      F(c,H.cells.size()) {
        bool changed = false;
        for (id f: H.cells[c].faces) if (fAffected[f]) {
          changed = true;
          break;
        }
        if (!changed) continue;

        _cell_faces.clear();
        FC(lf,H.cells[c].faces.size(),f_old2new[H.cells[c].faces[lf]] != NO_ID) {
          id nf = f_old2new[H.cells[c].faces[lf]];
          _cell_faces.push_back(nf);
        }
        sort_unique(_cell_faces);
        if (_cell_faces.size() <= 1) { /* Collapsed cell */
          c_old2new[c] = NO_ID;
          nredir_c += 1;
          H.cells[c].faces.clear();
        } else {
          auto it = cell_hashes.find(_cell_faces);
          if (it == cell_hashes.end()) {
            cell_hashes[_cell_faces] = c;
            H.cells[c].faces = _cell_faces;
          } else {
            c_old2new[c] = it->second;
            nredir_c += 1;
            H.cells[c].faces.clear();
          }
        }
      }
    }
    debug("nredir_v = {} / {}, nredir_e = {} / {}, nredir_f = {} / {}, nredir_c = {} / {}",
        nredir_v, H.vertices.size(), nredir_e, H.edges.size(), nredir_f, H.faces.size(), nredir_c, H.cells.size());

    return true;
  }

  bool merge_vertices_hash(BrepMesh& H, 
      const vector<id2>& equalities,
      std::unordered_map<id,id>& v_old2new,
      std::unordered_map<id,id>& e_old2new,
      std::unordered_map<id,id>& f_old2new,
      std::unordered_map<id,id>& c_old2new) {
    v_old2new.clear();
    e_old2new.clear();
    f_old2new.clear();
    c_old2new.clear();

    id nredir_v = 0;
    {
      /* Merge vertices via greedy aggregation */
      std::unordered_map<id,std::vector<id> > v2v;
      vector<id> avert;
      F(i,equalities.size()) {
        v2v[equalities[i][0]].push_back(equalities[i][1]);
        v2v[equalities[i][1]].push_back(equalities[i][0]);
        v_old2new[equalities[i][0]] = equalities[i][0];
        v_old2new[equalities[i][1]] = equalities[i][1];
        avert.push_back(equalities[i][0]);
        avert.push_back(equalities[i][1]);
      }
      sort_unique(avert);
      /* BFS aggregation */
      std::deque<id> Q;
      std::unordered_set<id> visited;
      vector<id> _ivert;
      vector<vector<id>> _dim_to_vertices(4);
      for (id i: avert) {
        if (visited.find(i) != visited.end()) continue;
        _ivert.clear();
        Q.clear();
        Q.push_back(i);
        visited.insert(i);
        while(!Q.empty()) {
          id v = Q.front();
          Q.pop_front();
          v_old2new[v] = i;
          if (v != i) {
            nredir_v += 1;
          }
          _ivert.push_back(v);
          const vector<id>& vs = v2v[v];
          for (id v2: vs) {
            if (visited.find(v2) != visited.end()) continue;
            visited.insert(v2);
            Q.push_back(v2);
          }
        }
        sort_unique(_ivert);
        if (_ivert.size() > 1) { /* Multiple vertices merged together */
          F(d,4) _dim_to_vertices[d].clear();
          for (id ov:_ivert) {
            if (H.vertices[ov].entity == nullptr) {
              error("merge_vertices | no entity for v={} -> entity = {}", ov);
              return false;
            }
            int dim = H.vertices[ov].entity->dim();
            if (dim < 0 || dim > 3) {
              error("merge_vertices | invalid dim, v={} -> entity = {}", ov, H.vertices[ov].entity);
              return false;
            }
            _dim_to_vertices[dim].push_back(ov);
          }
          bool done = false;
          FC(d,4,_dim_to_vertices[d].size() > 0) {
            vec3 pt;
            if (_dim_to_vertices[d].size() == 1) {
              pt = H.vertices[_dim_to_vertices[d][0]].pt;
            } else {
              pt = points_center(points_from_vertices(H,_dim_to_vertices[d]));
            }
            H.vertices[i] = H.vertices[_dim_to_vertices[d][0]];
            H.vertices[i].pt = pt;
            done = true;
            break;
          }
          RFC(!done,"merge_vertices | no new vertex attach to old vertex ? dim_to_vertices = {}", _dim_to_vertices);
        }
      }
    }
    if (nredir_v == 0 || H.edges.size() == 0) return true;
    H.vertToEdges.clear(); /* no longer valid */

    /* update edges */
    id nredir_e = 0;
    vector<id> edges_to_empty_after;
    {
      unordered_map<id2,id,id2Hash> existing_edges;
      F(i,H.edges.size()) {
        /* Check if edge is affected */
        bool affected = false;
        id2 eb = H.edges[i].vertices;
        id2 ea = eb;
        if (eb[0] == NO_ID || eb[1] == NO_ID) continue;
        auto it1 = v_old2new.find(eb[0]);
        if (it1 != v_old2new.end()) {
          affected = true;
          ea[0] = it1->second;
        } 
        auto it2 = v_old2new.find(eb[1]);
        if (it2 != v_old2new.end()) {
          affected = true;
          ea[1] = it2->second;
        }
        if (!affected) continue;

        if (ea[0] == ea[1]) { /* Collapsed edge */
          H.edges[i].vertices = {NO_ID,NO_ID};
          e_old2new[i] = NO_ID;
          nredir_e += 1;
          // DBG(i,eb,ea,"collapse");
          continue;
        }

        id2 sea = sorted(ea[0],ea[1]);
        auto it = existing_edges.find(sea);
        if (it == existing_edges.end()) {
          H.edges[i].vertices = ea;
          e_old2new[i] = i;
          existing_edges[sea] = i;
          // DBG(i,eb,ea,"new");
        } else {
          H.edges[i].vertices = ea;
          e_old2new[i] = it->second;
          nredir_e += 1;
          edges_to_empty_after.push_back(i);
          // DBG(i,eb,ea,"redir",it->second);
        }
      }
    }
    if (nredir_e == 0 || H.faces.size() == 0) return true;
    H.edgeToFaces.clear(); /* no longer valid */

    /* update faces */
    id nredir_f = 0;
    {
      std::unordered_map<vector<id>,id,vidHash> face_hashes;
      vector<id> nedges;
      F(i,H.faces.size()) {
        bool affected = false;
        nedges = H.faces[i].edges;
        F(le,nedges.size()) {
          id e = nedges[le];
          auto it = e_old2new.find(e);
          if (it != e_old2new.end()) {
            affected = true;
            nedges[le] = it->second;
          }
        }
        if (!affected) continue;

        Face nf = H.faces[i];
        nf.edges.clear();
        nf.edge_orient_invert.clear();
        F(j,H.faces[i].edges.size()) {
          id oe = H.faces[i].edges[j];
          bool oinv = H.faces[i].edge_orient_invert[j];
          id2 v1v2 = H.edges[oe].vertices;
          if (oinv) std::reverse(v1v2.begin(),v1v2.end());
          id ne = nedges[j];
          if (ne == NO_ID) continue; /* edge has been removed */
          { /* remove pair of edges after vertex merge (non manifold branch) */
            auto it = std::find(nf.edges.begin(),nf.edges.end(),ne);
            if (it != nf.edges.end()) {
              id pos = it - nf.edges.begin();
              nf.edges.erase(nf.edges.begin()+pos);
              nf.edge_orient_invert.erase(nf.edge_orient_invert.begin()+pos);
              continue;
            }
          }
          id2 new_edge = H.edges[ne].vertices;
          if (new_edge[0] == v1v2[0] && new_edge[1] == v1v2[1]) {
            nf.edges.push_back(ne);
            nf.edge_orient_invert.push_back(false);
          } else if (new_edge[1] == v1v2[0] && new_edge[0] == v1v2[1]) {
            nf.edges.push_back(ne);
            nf.edge_orient_invert.push_back(true);
          } else {
            RF("merge_vertices_light | should not happen: new_edge = {}, v1v2 = {}", new_edge, v1v2);
          }
        }
        if (nf.edges.size() == 0) {
          f_old2new[i] = NO_ID;
          H.faces[i].edges.clear();
          H.faces[i].edge_orient_invert.clear();
          nredir_f += 1;
        } else {
          vector<id> sedges = nf.edges;
          sort_unique(sedges);
          auto it = face_hashes.find(sedges);
          if (it == face_hashes.end()) {
            H.faces[i] = nf;
            face_hashes[sedges] = i;
            f_old2new[i] = i;
            // DBG(i,"new",sedges);
          } else {
            f_old2new[i] = it->second;
            nredir_f += 1;
            H.faces[i].edges.clear();
            H.faces[i].edge_orient_invert.clear();
            // DBG(i,"redir");
          }
        }
      }
    }
    for (id e: edges_to_empty_after) H.edges[e].vertices = {NO_ID,NO_ID};
    if (nredir_f == 0 || H.cells.size() == 0) return true;
    H.faceToCells.clear(); /* no longer valid */

    /* update cells */
    id nredir_c = 0;
    {
      std::unordered_map<vector<id>,id,vidHash> cell_hashes;
      vector<id> _cell_faces;
      vector<id> nfaces(6);
      F(c,H.cells.size()) {
        bool affected = false;
        nfaces = H.cells[c].faces;
        F(lf,H.cells[c].faces.size()) {
          id f = H.cells[c].faces[lf];
          auto it = f_old2new.find(f);
          if (it != f_old2new.end()) {
            affected = true;
            nfaces[lf] = it->second;
          }
        }
        if (!affected) continue;

        _cell_faces.clear();
        FC(lf,nfaces.size(),nfaces[lf] != NO_ID) {
          _cell_faces.push_back(nfaces[lf]);
        }
        sort_unique(_cell_faces);

        if (_cell_faces.size() <= 1) { /* Collapsed cell */
          c_old2new[c] = NO_ID;
          nredir_c += 1;
          H.cells[c].faces.clear();
        } else {
          auto it = cell_hashes.find(_cell_faces);
          if (it == cell_hashes.end()) {
            cell_hashes[_cell_faces] = c;
            H.cells[c].faces = _cell_faces;
            c_old2new[c] = c; /* c->c added in the map to mark the hexes as affected */
          } else {
            c_old2new[c] = it->second;
            nredir_c += 1;
            H.cells[c].faces.clear();
          }
        }
      }
    }
    // debug("nredir_v = {} / {}, nredir_e = {} / {}, nredir_f = {} / {}, nredir_c = {} / {}", nredir_v, H.vertices.size(), nredir_e, H.edges.size(), nredir_f, H.faces.size(), nredir_c, H.cells.size());

    return true;
  }

  bool remove_empty_elements(BrepMesh& M) {
    { /* Vertices */
      vector<id> v_old2new(M.vertices.size(),NO_ID);
      id count = 0;
      F(i,M.vertices.size()) {
        if (M.vertices[i].pt[0] != DBL_MAX) {
          v_old2new[i] = count;
          count += 1;
        }
      }
      if (count != M.vertices.size()) { /* update edges */
        F(e,M.edges.size()) F(lv,2) {
          id v = M.edges[e].vertices[lv];
          if (v != NO_ID) {
            M.edges[e].vertices[lv] = v_old2new[v];
          }
        }
        vector<Vertex> new_elems(count);
        FC(i,v_old2new.size(),v_old2new[i] != NO_ID) new_elems[v_old2new[i]] = M.vertices[i];
        M.vertices = new_elems;
      }
    }

    { /* Edges */
      vector<id> e_old2new(M.edges.size(),NO_ID);
      id count = 0;
      F(i,M.edges.size()) {
        if (M.edges[i].vertices[0] != NO_ID && M.edges[i].vertices[1] != NO_ID) {
          e_old2new[i] = count;
          count += 1;
        }
      }
      if (count != M.edges.size()) { /* update faces */
        F(i,M.faces.size()) F(le,M.faces[i].edges.size()) {
          id e = M.faces[i].edges[le];
          if (e != NO_ID) {
            M.faces[i].edges[le] = e_old2new[e];
          }
        }
        vector<Edge> new_elems(count);
        FC(i,e_old2new.size(),e_old2new[i] != NO_ID) new_elems[e_old2new[i]] = M.edges[i];
        M.edges = new_elems;
      }
    }

    { /* Faces */
      vector<id> f_old2new(M.faces.size(),NO_ID);

      id count = 0;
      F(i,M.faces.size()) {
        if (M.faces[i].edges.size() > 0) {
          f_old2new[i] = count;
          count += 1;
        }
      }
      if (count != M.faces.size()) { /* update cells */
        F(i,M.cells.size()) F(le,M.cells[i].faces.size()) {
          id e = M.cells[i].faces[le];
          if (e != NO_ID) {
            M.cells[i].faces[le] = f_old2new[e];
          }
        }
        vector<Face> new_elems(count);
        FC(i,f_old2new.size(),f_old2new[i] != NO_ID) new_elems[f_old2new[i]] = M.faces[i];
        M.faces = new_elems;
      }
    }

    { /* Cells */
      vector<id> c_old2new(M.cells.size(),NO_ID);

      id count = 0;
      F(i,M.cells.size()) {
        if (M.cells[i].faces.size() > 0) {
          c_old2new[i] = count;
          count += 1;
        }
      }
      if (count != M.cells.size()) {
        vector<Cell> new_elems(count);
        FC(i,c_old2new.size(),c_old2new[i] != NO_ID) new_elems[c_old2new[i]] = M.cells[i];
        M.cells = new_elems;
      }
    }

    return true;
  }



  vec3 apply_scaling(vec3 p, vec3 c, double scale) {
    return c + scale * (p-c);
  }

  vector<vec3> apply_scaling(const vector<vec3>& pts, vec3 c, double scale) {
    vector<vec3> out = pts;
    F(i,out.size()) out[i] = apply_scaling(pts[i], c, scale);
    return out;
  }


  bool visualization_show_cell(const BrepMesh& M, const Cell& cell, const std::string& viewName, double scale) {
    vector<id> edges;
    F(lf,cell.faces.size()) edges = merge(edges,M.faces[cell.faces[lf]].edges);
    vector<id> vert;
    F(le,edges.size()) vert = merge(vert,{M.edges[edges[le]].vertices[0],M.edges[edges[le]].vertices[1]});

    vector<vec3> vpts = points_from_vertices(M, vert);
    vec3 center = {0.,0.,0.};
    if (scale != 1.) center = points_center(vpts);
    if (scale != 1.) vpts = apply_scaling(vpts,center, scale);

    F(lv,vert.size()) {
      GeoLog::add({vpts[lv]},double(lv),viewName);
    }
    F(i,edges.size()) {
      id2 vert = M.edges[edges[i]].vertices;
      vector<vec3> pts = points_from_vertices(M,{vert[0],vert[1]});
      if (scale != 1.) pts = apply_scaling(pts,center, scale);
      GeoLog::add(pts,double(i),viewName);
    }
    F(i,cell.faces.size()) {
      vector<id> vert = face_vertices(M,cell.faces[i]);
      vector<vec3> pts = points_from_vertices(M,vert);
      if (scale != 1.) pts = apply_scaling(pts,center, scale);
      GeoLog::add(pts,double(i),viewName);
    }
    return true;
  }

  bool check_hex_mesh_cells(const BrepMesh& H, const vector<id>& hexes, bool verbose, bool vizu_errors, bool ignore_empty) {
    bool valid = true;
    for (id c: hexes) {
      if (ignore_empty && H.cells[c].faces.empty()) continue;
      if (!hex_is_valid(H,H.cells[c])) {
        if (verbose) {
          error("invalid hex mesh, cell {} is not a valid hex", c);
          hex_is_valid(H,H.cells[c],true);
        }
        valid = false;
        if (vizu_errors) {
          visualization_show_cell(H, H.cells[c], "!invalid_hex_"+std::to_string(c));
        }
      }
    }
    if (!valid) return false;
    return true;
  }

  bool check_hex_mesh_cells(const BrepMesh& H, bool verbose, bool vizu_errors, bool ignore_empty) {
    vector<id> hexes(H.cells.size());
    std::iota(hexes.begin(),hexes.end(),0);
    return check_hex_mesh_cells(H,hexes,verbose,vizu_errors,ignore_empty);
  }

  bool hex_mesh_is_valid(const BrepMesh& H, 
      const vector<id>& edges,
      const vector<id>& faces,
      const vector<id>& hexes,
      bool verbose, bool vizu_errors, bool ignore_empty) {

    bool valid = check_hex_mesh_cells(H, hexes, verbose, vizu_errors, ignore_empty);
    if (!valid) return false;

    /* Check conformality compatibility stuff */
    unordered_map<id2,id,id2Hash> hash_edges;
    unordered_map<id2,id,id2Hash> hash_quad_diags;
    unordered_map<id2,id,id2Hash> hash_hex_diags;
    for (id i: edges) {
      if (ignore_empty && H.edges[i].vertices[0] == NO_ID && H.edges[i].vertices[1] == NO_ID) continue;
      id2 edg = sorted(H.edges[i].vertices[0],H.edges[i].vertices[1]);
      hash_edges[edg] = i;
    }
    vector<id> vert(4);
    for (id i: faces) {
      if (ignore_empty && H.faces[i].edges.empty()) continue;
      if(H.faces[i].edges.size() != 4) {
        error("verify hex mesh: H.faces[{}].edges = {}", i, H.faces[i].edges);
        if (vizu_errors) {
          // DBG(points_from_vertices(H,face_vertices(H,i)));
          GeoLog::add(points_from_vertices(H,face_vertices(H,i)),double(i),"pb_face_"+std::to_string(i));
        }
        valid = false;
        continue;
      }
      face_vertices(H,i,vert);
      hash_quad_diags[sorted(vert[0],vert[2])] = i;
      hash_quad_diags[sorted(vert[1],vert[3])] = i;
    }
    vert.resize(8);
    for (id i: hexes) {
      if (ignore_empty && H.cells[i].faces.empty()) continue;
      RFC(H.cells[i].faces.size() != 6, "should not happen");
      hex_vertices(H,i,vert);
      hash_hex_diags[sorted(vert[0],vert[6])] = i;
      hash_hex_diags[sorted(vert[1],vert[7])] = i;
      hash_hex_diags[sorted(vert[2],vert[4])] = i;
      hash_hex_diags[sorted(vert[3],vert[5])] = i;
    }

    for (const auto& kv: hash_edges) {
      id2 query = kv.first;
      if (hash_quad_diags.find(query) != hash_quad_diags.end()) {
        if (verbose) error("edge {} is also a quad diagonal", query);
        valid = false;
      }
      if (hash_hex_diags.find(query) != hash_hex_diags.end()) {
        if (verbose) error("edge {} is also a hex diagonal", query);
        valid = false;
      }
    }
    for (const auto& kv: hash_hex_diags) {
      id2 query = kv.first;
      if (hash_quad_diags.find(query) != hash_quad_diags.end()) {
        if (verbose) error("hex diag {} is also a quad diagonal", query);
        valid = false;
      }
    }

    /* Check number of edges shared by two faces */
    vector<vector<id>> e2q(H.edges.size());
    for (id f: faces) {
      F(le,H.faces[f].edges.size()) {
        e2q[H.faces[f].edges[le]].push_back(f);
      }
    }
    for (id e: edges) if (e2q[e].size() >= 2) {
      F(i,e2q[e].size()) {
        id f1 = e2q[e][i];
        const vector<id>& edges1 = H.faces[f1].edges;
        FC(j,e2q[e].size(),j>i) {
          id f2 = e2q[e][j];
          const vector<id>& edges2 = H.faces[f2].edges;
          vector<id> inter = intersection(edges1,edges2);
          if (inter.size() != 1) {
            if (verbose) {
              error("faces {} and {} share too many edges: {}",f1,f2,inter);
              if (H.faceToCells.size() > 0) {DBG(H.faceToCells[f1],H.faceToCells[f2]);}
            }
            valid = false;

            if (vizu_errors) {
              std::string pbname = "!f_sh" + std::to_string(inter.size()) + "e_" + std::to_string(f1/2+f2/4);
              vector<vec3> pts1 = points_from_vertices(H,face_vertices(H,f1));
              vector<vec3> pts2 = points_from_vertices(H,face_vertices(H,f2));
              // DBG(pts1,pts2);
              GeoLog::add(pts1,double(f1),pbname);
              GeoLog::add(pts2,double(f2),pbname);
              if (H.faceToCells.size() > 0) {
                vector<id> _hexes;
                F(_le,inter.size()) {
                  F(_lv,2) {
                    id _v = H.edges[inter[_le]].vertices[_lv];
                    F(_le2,H.vertToEdges[_v].size()) {
                      id _e2 = H.vertToEdges[_v][_le2];
                      F(_lf2,H.edgeToFaces[_e2].size()) {
                        id _f2 = H.edgeToFaces[_e2][_lf2];
                        F(_lc2,H.faceToCells[_f2].size()) {
                          id _c2 = H.faceToCells[_f2][_lc2];
                          _hexes.push_back(_c2);
                        }
                      }
                    }
                  }
                }
                sort_unique(_hexes);
                F(_lc,_hexes.size()) {
                  vector<vec3> _pts = points_from_vertices(H, hex_vertices(H,_hexes[_lc]));
                  GeoLog::add(_pts,double(_lc),pbname);
                }
              }
            } /* end of vizu */

          }
        }
      }
    }
    if (vizu_errors) GeoLog::flush();

    return valid;

  }


  bool hex_mesh_is_valid(const BrepMesh& H, bool verbose, bool vizu_errors, bool ignore_empty) {
    vector<id> edges(H.edges.size());
    vector<id> faces(H.faces.size());
    vector<id> cells(H.cells.size());
    std::iota(edges.begin(),edges.end(),0);
    std::iota(faces.begin(),faces.end(),0);
    std::iota(cells.begin(),cells.end(),0);

    return hex_mesh_is_valid(H, edges, faces, cells, verbose, vizu_errors, ignore_empty);
  }

  bool hex_mesh_is_valid(const BrepMesh& H, const vector<id>& hexes, bool verbose, bool vizu_errors, bool ignore_empty) {
    vector<id> edges;
    vector<id> faces;
    edges.reserve(12*hexes.size());
    faces.reserve(6*hexes.size());
    for (id c: hexes) {
      append(edges,cell_edges(H,c));
      append(faces,H.cells[c].faces);
    }
    sort_unique(edges);
    sort_unique(faces);
    return hex_mesh_is_valid(H, edges, faces, hexes, verbose, vizu_errors, ignore_empty);
  }

  void clear_mesh(BrepMesh& M) {
    M.vertices.clear();
    M.vertToEdges.clear();
    M.edges.clear();
    M.edgeToFaces.clear();
    M.faces.clear();
    M.faceToCells.clear();
    M.cells.clear();
  }

  bool explicit_triangles_from_quad_faces(
      const BrepMesh& M, 
      const std::vector<id>& quadFaces,
      std::vector<id3>& triVertices) {
    vector<id> fvert(4);
    triVertices.reserve(triVertices.size() + 2*quadFaces.size());
    for (id f: quadFaces) {
      face_vertices(M,f,fvert); /* assumed to match the edges */
      RFC(fvert.size() != M.faces[f].edges.size(), "triangulate_faces | face {} has {} edges and {} vertices",
          f, M.faces[f].edges.size(), fvert.size());
      bool done = false;
      if (fvert.size() == 4) {
        double diag1 = length(M.vertices[fvert[2]].pt - M.vertices[fvert[0]].pt);
        double diag2 = length(M.vertices[fvert[3]].pt - M.vertices[fvert[1]].pt);
        if (diag1 < diag2) {
          triVertices.push_back({fvert[0],fvert[1],fvert[2]});
          triVertices.push_back({fvert[0],fvert[2],fvert[3]});
        } else {
          triVertices.push_back({fvert[0],fvert[1],fvert[3]});
          triVertices.push_back({fvert[3],fvert[1],fvert[2]});
        }
      } else {
        error("explicit_triangles_from_quad_faces: face {} is not a quad", f);
        return false;
      }
    }
    return true;
  }

  double localEdgeLengthAroundVertex(const BrepMesh& Q, id v, bool secondRing) {
    if (Q.vertToEdges[v].size() == 0) return 0.;
    double elen = 0.;
    double s = 0.;
    F(le,Q.vertToEdges[v].size()) {
      id e = Q.vertToEdges[v][le];
      elen += length(Q.vertices[Q.edges[e].vertices[1]].pt - Q.vertices[Q.edges[e].vertices[0]].pt);
      s += 1.;
    }
    if (secondRing) {
      F(le,Q.vertToEdges[v].size()) {
        id e = Q.vertToEdges[v][le];
        id v2 = edge_opposite_vertex(Q.edges[e].vertices,v);
        elen += localEdgeLengthAroundVertex(Q,v2,false);
        s += 1.;
      }
    }

    elen /= s;
    return elen;
  }


  bool triangulate_faces(BrepMesh& M, bool update_mappings) {
    if (M.cells.size() > 0) {
      error("the mesh contains {} cells, cannot triangulate faces without breaking everything", M.cells.size());
      return false;
    }

    const bool special_quad_split = true;

    /* warning: assume ordered edges */
    size_t ns = 0;
    vector<id> fvert;
    size_t nfaces = M.faces.size();
    F(f,nfaces) {
      if (M.faces[f].edges.size() > 3) {
        face_vertices(M,f,fvert); /* assumed to match the edges */
        RFC(fvert.size() != M.faces[f].edges.size(), "triangulate_faces | face {} has {} edges and {} vertices",
            f, M.faces[f].edges.size(), fvert.size());
        bool done = false;
        if (fvert.size() == 4 && special_quad_split) {
          double diag1 = length(M.vertices[fvert[2]].pt - M.vertices[fvert[0]].pt);
          double diag2 = length(M.vertices[fvert[3]].pt - M.vertices[fvert[1]].pt);
          if (diag2 < diag1) { /* Split to have better quality triangles */
            id ne = add_edge(M, {fvert[1],fvert[3]}, M.faces[f].entity, nullptr, false);
            vector<id> edges_t1 = {M.faces[f].edges[0], ne, M.faces[f].edges[3]};
            vector<id> edges_t2 = {M.faces[f].edges[1], ne, M.faces[f].edges[2]};
            id nf_t1 = add_face(M, edges_t1, M.faces[f].entity, M.faces[f].origin, false);
            id nf_t2 = add_face(M, edges_t2, M.faces[f].entity, M.faces[f].origin, false);
            if (nf_t1 == NO_ID || nf_t2 == NO_ID) {
              Msg::Error("triangulate_faces: failed to split quads into two triangles");
              return false;
            }
            done = true;
          }
        }
        if (!done) {
          /* Create edges to triangulate the face */
          vector<id> nes;
          for (id i = 2; i < fvert.size()-1; ++i) {
            id ne = add_edge(M, {fvert[0],fvert[i]}, M.faces[f].entity, nullptr, false);
            nes.push_back(ne);
          }
          /* Create the new faces */
          F(lf,fvert.size()-2) {
            vector<id> edges;
            if (lf == 0) {
              edges = {M.faces[f].edges[0],M.faces[f].edges[1],nes.front()};
            } else if (lf == fvert.size()-3) {
              edges = {nes.back(), M.faces[f].edges[fvert.size()-2],M.faces[f].edges[fvert.size()-1]};
            } else {
              edges = {nes[lf],M.faces[f].edges[2+lf],nes[lf+1]};
            }
            id nf = add_face(M, edges, M.faces[f].entity, M.faces[f].origin, false);
            if (nf == NO_ID) {
              Msg::Error("triangulate_faces: failed to split polygon into triangles");
              return false;
            }
          }
        }
        /* Empty the current one */
        M.faces[f].edges.clear();
        M.faces[f].edge_orient_invert.clear();
        ns += 1;
      }
    }

    if (ns > 0) remove_empty_elements(M);

    if (update_mappings) {
      update_brep_mesh_mappings(M);
    }

    return true;
  }

  bool update_brep_mesh_mappings(BrepMesh& M) {
    /* Vertex to edges */
    if (M.edges.size() > 0) {
      M.vertToEdges.resize(M.vertices.size());
      F(v,M.vertToEdges.size()) M.vertToEdges[v].clear();
      F(i,M.edges.size()) F(lv,2) {
        id v = M.edges[i].vertices[lv];
        if (v == NO_ID) continue;
        M.vertToEdges[v].push_back(i);
      }
    }

    /* Edge to faces */
    if (M.faces.size() > 0) {
      M.edgeToFaces.resize(M.edges.size());
      F(e,M.edgeToFaces.size()) M.edgeToFaces[e].clear();
      F(f,M.faces.size()) F(le,M.faces[f].edges.size()) {
        id e = M.faces[f].edges[le];
        if (e == NO_ID) continue;
        M.edgeToFaces[e].push_back(f);
      }
    }

    /* Face to cells */
    if (M.cells.size() > 0) {
      M.faceToCells.resize(M.faces.size());
      F(f,M.faces.size()) M.faceToCells[f].clear();
      F(i,M.cells.size()) F(lf,M.cells[i].faces.size()) {
        id f = M.cells[i].faces[lf];
        if (f == NO_ID) continue;
        M.faceToCells[f].push_back(i);
      }
    }

    return true;
  }

  std::pair<vec3,vec3> bbox_of_points(const std::vector<vec3>& pts) {
    vec3 pMin = { DBL_MAX, DBL_MAX, DBL_MAX};
    vec3 pMax = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    F(i,pts.size()) {
      const vec3& p = pts[i];
      F(d,3) {
        pMin[d] = std::min(pMin[d],p[d]);
        pMax[d] = std::max(pMax[d],p[d]);
      }
    }
    return {pMin,pMax};
  }

  std::pair<vec3,vec3> bbox_of_mesh(const BrepMesh& M) {
    vec3 pMin = { DBL_MAX, DBL_MAX, DBL_MAX};
    vec3 pMax = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    F(i,M.vertices.size()) {
      const vec3& p = M.vertices[i].pt;
      F(d,3) {
        if (p[d] == DBL_MAX) continue;
        pMin[d] = std::min(pMin[d],p[d]);
        pMax[d] = std::max(pMax[d],p[d]);
      }
    }
    return {pMin,pMax};
  }
  
  bool in_tetrahedron(vec3 query, const std::array<vec3,4>& points, double lambda[4], double lambda_epsilon) {
    const double eps = lambda_epsilon;
    const vec3& v0 = points[0];
    const vec3& v1 = points[1];
    const vec3& v2 = points[2];
    const vec3& v3 = points[3];

    const double x0 = basicOrient3d(query, v1, v2, v3);
    const double x4 = basicOrient3d(v0, v1, v2, v3);
    lambda[0] = x0/x4;

    const double x1 = basicOrient3d(query, v0, v2, v3);
    const double x5 = basicOrient3d(v1, v0, v2, v3);
    lambda[1] = x1/x5;

    double x2 = basicOrient3d(query, v0, v1, v3);
    double x6 = basicOrient3d(v2, v0, v1, v3);
    lambda[2] = x2/x6;

    lambda[3] = 1.-lambda[0]-lambda[1]-lambda[2];

    if (lambda[0] < 0. - eps || lambda[0] > 1. + eps) return false;
    if (lambda[1] < 0. - eps || lambda[1] > 1. + eps) return false;
    if (lambda[2] < 0. - eps || lambda[2] > 1. + eps) return false;
    return lambda[3] >= 0. - eps && lambda[3] <= 1 + eps;
  }

  static const id HEX_FACETS[][4] = 
  { {0, 1, 2, 3},   
    {4, 5, 1, 0},   
    {5, 6, 2, 1},   
    {7, 3, 2, 6},   
    {4, 0, 3, 7},
    {4, 7, 6, 5} };

  static const id TET_FACETS[][3] = 
  { {0, 2, 1},
    {0, 1, 3},
    {0, 3, 2},
    {3, 1, 2} };

  inline id3 get_smallest_rotation(const id3& vec) {
    id3 smallest = vec;
    id3 rot_l = vec;
    F(i,vec.size()) {
      std::rotate(rot_l.begin(),rot_l.begin()+1,rot_l.end());
      if (rot_l < smallest) smallest = rot_l;
    }
    return smallest;
  }

  inline id4 get_smallest_rotation(const id4& vec) {
    id4 smallest = vec;
    id4 rot_l = vec;
    F(i,vec.size()) {
      std::rotate(rot_l.begin(),rot_l.begin()+1,rot_l.end());
      if (rot_l < smallest) smallest = rot_l;
    }
    return smallest;
  }

  inline id4 hex_face_smallest(const id8& hex, id lf, bool invert) {
    id4 vert = {hex[HEX_FACETS[lf][0]], hex[HEX_FACETS[lf][1]], hex[HEX_FACETS[lf][2]], hex[HEX_FACETS[lf][3]]};
    if (invert) std::reverse(vert.begin(),vert.end());
    return get_smallest_rotation(vert);
  }

  inline id3 tet_face_smallest(const id4& tet, id lf, bool invert) {
    id3 vert = {tet[TET_FACETS[lf][0]], tet[TET_FACETS[lf][1]], tet[TET_FACETS[lf][2]]};
    if (invert) std::reverse(vert.begin(),vert.end());
    return get_smallest_rotation(vert);
  }

  inline id4 hex_face_canonical(const id8& hex, id lf) {
    id4 vert1 = hex_face_smallest(hex, lf, false);
    id4 vert2 = hex_face_smallest(hex, lf, true);
    if (vert1 < vert2) {
      return vert1;
    }
    return vert2;
  }




  bool compute_oriented_hexahedra(const BrepMesh& H, std::vector<id8>& hexes, std::vector<int>& ballId) {
    RFC(H.cells.size() == 0, "no cells to orient");
    vector<id8> base_hexes(H.cells.size());
    vector<vector<id>> hex_neighbors(base_hexes.size());
    {
      /* collect faces to determine adjacencies */
      vector<id4> faces(6*H.cells.size());
      vector<id> vert(8);
      F(c,H.cells.size()) {
        if (H.cells[c].faces.size() != 6) RF("not a hex !");
        hex_vertices(H,c,vert); /* collect vertices (not oriented) */
        F(lv,8) base_hexes[c][lv] = vert[lv];
        F(lf,6) {
          id4 quad = hex_face_canonical(base_hexes[c],lf);
          faces[6*c+lf] = quad;
        }
      }
      vector<id4> uFaces;
      vector<id> hf2f;
      size_t nf = sort_unique_with_perm(faces, uFaces, hf2f);
      /* invert the mapping to get unique face to hex faces */
      vector<id2> f2hf(nf,{NO_ID,NO_ID});
      F(i,6*base_hexes.size()) {
        id f = hf2f[i];
        if (f2hf[f][0] == NO_ID) {
          f2hf[f][0] = i;
        } else if (f2hf[f][1] == NO_ID) {
          f2hf[f][1] = i;
        } else {
          RF("face adjacent to more than 2 hexes !");
        }
      }
      /* extract hex adjacencies */
      F(f,nf) {
        if (f2hf[f][0] != NO_ID && f2hf[f][1] != NO_ID) {
          hex_neighbors[f2hf[f][0]/6].push_back(f2hf[f][1]/6);
          hex_neighbors[f2hf[f][1]/6].push_back(f2hf[f][0]/6);
        }
      }
    }

    hexes = base_hexes;
    ballId.clear();
    ballId.resize(hexes.size(),0);
    vector<bool> visited(hexes.size(),false);
    int ball = 0;
    size_t nbi = 0;
    FC(cInit,hexes.size(),!visited[cInit]) {
      ball += 1;
      std::queue<id> qq;
      qq.push(cInit);
      visited[cInit] = true;
      while (qq.size() > 0) {
        id c = qq.front();
        qq.pop();
        ballId[c] = ball;

        /* Check if orientation compatible with neighbors */
        F(i,hex_neighbors[c].size()) {
          id c2 = hex_neighbors[c][i];
          if (visited[c2]) continue;
          /* Find the common face */
          id lf1 = NO_ID;
          id lf2 = NO_ID;
          F(j1,6) {
            id4 quad1 = hex_face_canonical(hexes[c],j1);
            F(j2,6) {
              id4 quad2 = hex_face_canonical(hexes[c2],j2);
              if (quad1 == quad2) {
                lf1 = j1;
                lf2 = j2;
                break;
              }
            }
            if (lf1 != NO_ID) break;
          }
          if (lf1 == NO_ID || lf2 == NO_ID) {
            RF("common face not found ? c={}, c2={}", c, c2);
          }
          id4 quad1 = hex_face_smallest(hexes[c],lf1,false);
          id4 quad2 = hex_face_smallest(hexes[c2],lf2,true);
          if (quad1 == quad2) {
            /* good */
            qq.push(c2);
            visited[c2] = true;
          } else {
            quad2 = hex_face_smallest(hexes[c2],lf2,false);
            if (quad1 == quad2) { /* need to invert c2 */
              hexes[c2] = invert_hex(hexes[c2]);
              qq.push(c2);
              visited[c2] = true;
              nbi += 1;
            } else {
              DBG(c,lf1,quad1);
              DBG(hex_face_canonical(hexes[c],lf1));
              DBG(c2,lf2,quad2);
              DBG(hex_face_canonical(hexes[c2],lf2));
              RF("should not happen ? quad1 = {}, quad2 = {}", quad1, quad2);
            }
          }
        }
      }
    }
    debug("compute oriented hexahedra: {}/{} hexes inverted, {} disconnected components", nbi, hexes.size(), ball);

    return true;
  }

  bool compute_oriented_hexahedra(const BrepMesh& H, std::vector<std::vector<id> >& eltVertices, std::vector<int>& ballId) {
    RFC(H.cells.size() == 0, "no cells to orient");
    RFC(ballId.size() != H.cells.size(), "wrong input size for ballId");
    vector<id8> base_hexes(H.cells.size());
    vector<vector<id> > hex_neighbors(base_hexes.size());
    {
      /* collect faces to determine adjacencies */
      vector<id4> faces(6*H.cells.size(),{NO_ID,NO_ID,NO_ID,NO_ID});
      vector<id> vert(8);
      F(c,H.cells.size()) {
        if (H.cells[c].faces.size() != 6) continue;
        hex_vertices(H,c,vert); /* collect vertices (not oriented) */
        F(lv,8) base_hexes[c][lv] = vert[lv];
        F(lf,6) {
          id4 quad = hex_face_canonical(base_hexes[c],lf);
          faces[6*c+lf] = quad;
        }
      }
      vector<id4> uFaces;
      vector<id> hf2f;
      size_t nf = sort_unique_with_perm(faces, uFaces, hf2f);
      /* invert the mapping to get unique face to hex faces */
      vector<id2> f2hf(nf,{NO_ID,NO_ID});
      F(i,6*base_hexes.size()) {
        if (faces[i][0] == NO_ID) continue;
        id f = hf2f[i];
        if (f2hf[f][0] == NO_ID) {
          f2hf[f][0] = i;
        } else if (f2hf[f][1] == NO_ID) {
          f2hf[f][1] = i;
        } else {
          RF("face adjacent to more than 2 hexes !");
        }
      }
      /* extract hex adjacencies */
      F(f,nf) {
        if (f2hf[f][0] != NO_ID && f2hf[f][1] != NO_ID) {
          hex_neighbors[f2hf[f][0]/6].push_back(f2hf[f][1]/6);
          hex_neighbors[f2hf[f][1]/6].push_back(f2hf[f][0]/6);
        }
      }
    }

    vector<id8> hexes = base_hexes;
    vector<bool> visited(H.cells.size(),false);
    int ballMax = *std::max_element(ballId.begin(),ballId.end());
    int ball = ballMax;
    size_t nbi = 0;
    FC(cInit,H.cells.size(),!visited[cInit] && H.cells[cInit].faces.size() == 6) {
      ball += 1;
      std::queue<id> qq;
      qq.push(cInit);
      visited[cInit] = true;
      while (qq.size() > 0) {
        id c = qq.front();
        qq.pop();
        ballId[c] = ball;

        /* Check if orientation compatible with neighbors */
        F(i,hex_neighbors[c].size()) {
          id c2 = hex_neighbors[c][i];
          if (visited[c2]) continue;
          /* Find the common face */
          id lf1 = NO_ID;
          id lf2 = NO_ID;
          F(j1,6) {
            id4 quad1 = hex_face_canonical(hexes[c],j1);
            F(j2,6) {
              id4 quad2 = hex_face_canonical(hexes[c2],j2);
              if (quad1 == quad2) {
                lf1 = j1;
                lf2 = j2;
                break;
              }
            }
            if (lf1 != NO_ID) break;
          }
          if (lf1 == NO_ID || lf2 == NO_ID) {
            RF("common face not found ? c={}, c2={}", c, c2);
          }
          id4 quad1 = hex_face_smallest(hexes[c],lf1,false);
          id4 quad2 = hex_face_smallest(hexes[c2],lf2,true);
          if (quad1 == quad2) {
            /* good */
            qq.push(c2);
            visited[c2] = true;
          } else {
            quad2 = hex_face_smallest(hexes[c2],lf2,false);
            if (quad1 == quad2) { /* need to invert c2 */
              hexes[c2] = invert_hex(hexes[c2]);
              qq.push(c2);
              visited[c2] = true;
              nbi += 1;
            } else {
              DBG(c,lf1,quad1);
              DBG(hex_face_canonical(hexes[c],lf1));
              DBG(c2,lf2,quad2);
              DBG(hex_face_canonical(hexes[c2],lf2));
              RF("should not happen ? quad1 = {}, quad2 = {}", quad1, quad2);
            }
          }
        }
      }
    }
    debug("compute oriented hexahedra: {}/{} hexes inverted, {} disconnected components", nbi, hexes.size(), ball);
    eltVertices.resize(H.cells.size());
    FC(c,H.cells.size(),H.cells[c].faces.size() == 6) {
      eltVertices[c].resize(8);
      F(lv,8) eltVertices[c][lv] = hexes[c][lv];
    }

    return true;

  }


  bool compute_oriented_tetrahedra(const BrepMesh& H, std::vector<std::vector<id> >& eltVertices, std::vector<int>& ballId) {
    RFC(H.cells.size() == 0, "no cells to orient");
    RFC(ballId.size() != H.cells.size(), "wrong input size for ballId");
    vector<id4> base_tets(H.cells.size());
    vector<vector<id> > tets_neighbors(base_tets.size());
    {
      /* collect faces to determine adjacencies */
      vector<id3> faces(4*H.cells.size(),{NO_ID,NO_ID,NO_ID});
      vector<id> vert(4);
      vector<id> fvert(3);
      F(c,H.cells.size()) {
        if (H.cells[c].faces.size() != 4) continue;
        cell_vertices(H,c,vert); /* collect vertices (not oriented) */
        F(lv,4) base_tets[c][lv] = vert[lv];
        F(lf,4) {
          cell_face_vertices(H, c, lf, fvert);
          id3 tri = sorted(fvert[0],fvert[1],fvert[2]);
          faces[4*c+lf] = tri;
        }
      }
      vector<id3> uFaces;
      vector<id> tf2f;
      size_t nf = sort_unique_with_perm(faces, uFaces, tf2f);
      /* invert the mapping to get unique face to hex faces */
      vector<id2> f2tf(nf,{NO_ID,NO_ID});
      F(i,4*base_tets.size()) {
        if (faces[i][0] == NO_ID) continue;
        id f = tf2f[i];
        if (f2tf[f][0] == NO_ID) {
          f2tf[f][0] = i;
        } else if (f2tf[f][1] == NO_ID) {
          f2tf[f][1] = i;
        } else {
          RF("face adjacent to more than 2 hexes !");
        }
      }
      /* extract hex adjacencies */
      F(f,nf) {
        if (f2tf[f][0] != NO_ID && f2tf[f][1] != NO_ID) {
          tets_neighbors[f2tf[f][0]/4].push_back(f2tf[f][1]/4);
          tets_neighbors[f2tf[f][1]/4].push_back(f2tf[f][0]/4);
        }
      }
    }

    vector<id4> tets = base_tets;
    vector<bool> visited(H.cells.size(),false);
    int ballMax = *std::max_element(ballId.begin(),ballId.end());
    int ball = ballMax;
    size_t nbi = 0;
    vector<id> _fvert1(4);
    vector<id> _fvert2(4);
    FC(cInit,H.cells.size(),!visited[cInit] && H.cells[cInit].faces.size() == 4) {
      ball += 1;
      std::queue<id> qq;
      qq.push(cInit);
      visited[cInit] = true;
      while (qq.size() > 0) {
        id c = qq.front();
        qq.pop();
        ballId[c] = ball;

        /* Check if orientation compatible with neighbors */
        F(i,tets_neighbors[c].size()) {
          id c2 = tets_neighbors[c][i];
          if (visited[c2]) continue;
          /* Find the common face */
          id lf1 = NO_ID;
          id lf2 = NO_ID;
          F(j1,4) {
            id3 tri1 = tet_face_smallest(tets[c], j1, false);
            tri1 = sorted(tri1[0],tri1[1],tri1[2]);

            F(j2,4) {
              id3 tri2 = tet_face_smallest(tets[c2], j2, false);
              tri2 = sorted(tri2[0],tri2[1],tri2[2]);

              if (tri1 == tri2) {
                lf1 = j1;
                lf2 = j2;
                break;
              }
            }
            if (lf1 != NO_ID) break;
          }
          if (lf1 == NO_ID || lf2 == NO_ID) {
            RF("common face not found ? c={}, c2={}", c, c2);
          }
          id3 tri1 = tet_face_smallest(tets[c],lf1,false);
          id3 tri2 = tet_face_smallest(tets[c2],lf2,true);
          if (tri1 == tri2) {
            /* good */
            qq.push(c2);
            visited[c2] = true;
          } else {
            tri2 = tet_face_smallest(tets[c2],lf2,false);
            if (tri1 == tri2) { /* need to invert c2 */
              tets[c2] = invert_tet(tets[c2]);
              qq.push(c2);
              visited[c2] = true;
              nbi += 1;
            } else {
              RF("should not happen ? tri1 = {}, tri2 = {}", tri1, tri2);
            }
          }
        }
      }
    }
    debug("compute oriented hexahedra: {}/{} tets inverted, {} disconnected components", nbi, tets.size(), ball);
    eltVertices.resize(H.cells.size());
    FC(c,H.cells.size(),H.cells[c].faces.size() == 4) {
      eltVertices[c].resize(4);
      F(lv,4) eltVertices[c][lv] = tets[c][lv];
    }

    return true;

  }

  bool compute_oriented_elements(const BrepMesh& H, 
      std::vector<std::vector<id> >& eltVertices, std::vector<int>& ballId) {

    ballId.clear();
    ballId.resize(H.cells.size(),0);

    bool okh = compute_oriented_hexahedra(H, eltVertices, ballId);
    RFC(!okh, "failed to orient hexahedra");
    bool okt = compute_oriented_tetrahedra(H, eltVertices, ballId);
    RFC(!okt, "failed to orient tetrahedra");

    return true;
  }

  bool brepMeshMappingsAreUpToDate(const BrepMesh& M) {
    if (M.vertToEdges.size() != M.vertices.size()) return false;
    if (M.edgeToFaces.size() != M.edges.size()) return false;
    if (M.faceToCells.size() != M.faces.size()) return false;
    return true;
  }

  bool face_ordered_edges_vertices(const BrepMesh& M, id f, std::vector<id>& edges, std::vector<id>& vert) {
    vert.clear();
    edges.clear();
    if (M.faces[f].edges.size() <= 1) return false;

    unordered_map<id,vector<id> > v2e;
    for (id e: M.faces[f].edges) {
      v2e[M.edges[e].vertices[0]].push_back(e);
      v2e[M.edges[e].vertices[1]].push_back(e);
    }

    id it = 0;
    id e = M.faces[f].edges[0];
    id v = M.edges[e].vertices[0];
    while (true) {
      it += 1;
      RFC(it > 1000, "face_ordered_edges | infinite loop ? it = {}", it);
      if (v2e[v].size() != 2) return false;
      vert.push_back(v);
      edges.push_back(e);
      id next_v = edge_opposite_vertex(M.edges[e].vertices,v);
      if (next_v == NO_ID) return false;
      id next_e = (v2e[next_v][0] != e) ? v2e[next_v][0] : v2e[next_v][1];
      v = next_v;
      e = next_e;
      if (e == M.faces[f].edges[0]) break;
    }
    if (edges.size() != M.faces[f].edges.size()) {
      error("face_ordered_edges_vertices | f={}, got edges={} and vert={}", f, edges, vert);
      return false;
    }
    return true;
  }

  bool midpoint_subdivision(BrepMesh& H) {
    if (!brepMeshMappingsAreUpToDate(H)) {
      update_brep_mesh_mappings(H);
    }

    id nbe = H.edges.size();
    id nbf = H.faces.size();
    id nbc = H.cells.size();

    const bool update = false;

    /* Subdivide edges (create midpoint) */
    vector<id2> edgeToSubedges(nbe);
    vector<id> edgeToMidVertex(nbe);
    F(e,nbe) {
      vec3 p = edge_center(H,e);
      GEntity* entity = H.edges[e].entity;
      MLine* origin = H.edges[e].origin;
      id nv = add_vertex(H, p, entity, nullptr, update);
      edgeToMidVertex[e] = nv;
      F(j,2) {
        id2 vert;
        if (j == 0) {
          vert = {H.edges[e].vertices[0],nv};
        } else if (j == 1) {
          vert = {nv,H.edges[e].vertices[1]};
        }
        id ne = add_edge(H, vert, entity, origin, update);
        edgeToSubedges[e][j] = ne;
      }
    }

    /* Subdivide faces (create midpoint and edges) */
    vector<vector<id> > faceToSubfaces(nbf);
    vector<vector<id> > faceToSubedges(nbf);
    vector<id> faceToMidVertex(nbf);
    vector<id> fedges;
    vector<id> fvert;
    F(f,nbf) {
      bool oke = face_ordered_edges_vertices(H, f, fedges, fvert);
      RFC(!oke, "failed to get ordered edges for f = {}", f);

      /* Midpoint */
      vec3 p = face_center(H,f);
      GEntity* entity = H.faces[f].entity;
      MElement* origin = H.faces[f].origin;
      id nv = add_vertex(H, p, entity, nullptr, update);
      faceToMidVertex[f] = nv;

      /* Edges to split the face */
      vector<id> midedges(fedges.size());
      F(j,fedges.size()) {
        id oe = fedges[j];
        id mv = edgeToMidVertex[oe];
        id ne = add_edge(H, {mv,nv}, entity, nullptr, update);
        faceToSubedges[f].push_back(ne);
        midedges[j] = ne;
      }

      /* New faces */
      F(j,fedges.size()) {
        id jp = (fedges.size()+j-1)%fedges.size();
        id oe = fedges[j];
        id oe_prev = fedges[jp];

        vector<id> sfedges(4);
        sfedges[0] = NO_ID;
        F(k,2) {
          id se = edgeToSubedges[oe][k];
          id se_v1 = H.edges[se].vertices[0];
          id se_v2 = H.edges[se].vertices[1];
          if (se_v1 == fvert[j] || se_v2 == fvert[j]) {
            sfedges[0] = se;
          }
        }
        RFC(sfedges[0] == NO_ID, "MPS | subedge not found ?");
        sfedges[1] = midedges[j];
        sfedges[2] = midedges[jp];
        sfedges[3] = NO_ID;
        F(k,2) {
          id se = edgeToSubedges[oe_prev][k];
          id se_v1 = H.edges[se].vertices[0];
          id se_v2 = H.edges[se].vertices[1];
          if (se_v1 == fvert[j] || se_v2 == fvert[j]) {
            sfedges[3] = se;
          }
        }
        RFC(sfedges[3] == NO_ID, "MPS | subedge not found ?");

        id nf = add_face(H, sfedges, entity, origin, update);
        faceToSubfaces[f].push_back(nf);
      }
    }

    /* Subdivide cells */
    vector<id> vert;
    vector<id> edges;
    vector<id> faces;
    vector<id> _efedges;
    vector<id> _efvert;
    F(c,nbc) {
      /* Cell info */
      cell_vertices(H,c,vert);
      cell_edges(H, c, edges);
      vector<id> faces = H.cells[c].faces;
      unordered_map<id,vector<id>> vertex_to_nfaces;

      /* Midpoint */
      vec3 p = points_center(points_from_vertices(H,vert));
      GEntity* entity = H.cells[c].entity;
      MElement* origin = H.cells[c].origin;
      id nv = add_vertex(H, p, entity, nullptr, update);

      /* Edges from mid faces to mid cell */
      vector<id> midedges(H.cells[c].faces.size());
      F(j,H.cells[c].faces.size()) {
        id of = H.cells[c].faces[j];
        id mv = faceToMidVertex[of];
        id ne = add_edge(H, {mv,nv}, entity, nullptr, update);
        midedges[j] = ne;
      }

      /* Faces associated to cell edges */
      F(le,edges.size()) {
        vector<id> fedges;
        id oe = edges[le];
        id fcount = 0;
        for (id f: H.edgeToFaces[oe]) if (inVector(f,faces)) {
          F(le2,faces.size()) {
            id f2 = faces[le2];
            if (f == f2) {
              id ne = midedges[le2];
              fedges.push_back(ne);
            }
          }
          face_ordered_edges_vertices(H, f, _efedges, _efvert);
          F(le2,_efedges.size()) {
            id oe2 = _efedges[le2];
            if (oe2 == oe) {
              id ne = faceToSubedges[f][le2];
              fedges.push_back(ne);
            }
          }
          // F(le2,H.faces[f].edges.size()) {
          //   id oe2 = H.faces[f].edges[le2];
          //   if (oe2 == oe) {
          //     id ne = faceToSubedges[f][le2];
          //     fedges.push_back(ne);
          //   }
          // }
          fcount += 1;
        }
        RFC(fcount != 2, "should have two faces adjacent to edge {} in cell {} !", oe, c);
        RFC(fedges.size() != 4, "wrong number of edges for quad face");
        id nf = add_face(H, fedges, entity);
        F(lv,2) {
          id ov = H.edges[oe].vertices[lv];
          vertex_to_nfaces[ov].push_back(nf);
        }
      }

      /* Subfaces from face subdivision */
      vector<id> fvert(4);
      for (id of: faces) {
        for (id nf: faceToSubfaces[of]) {
          face_vertices(H,nf,fvert);
          for (id v: fvert) if (inVector(v,vert)) {
            vertex_to_nfaces[v].push_back(nf);
          }
        }
      }

      /* Create cells */
      for (const auto& kv: vertex_to_nfaces) {
        if (kv.second.size() != 6) {
          error("cannot create sub hex with {} faces", kv.second.size());
          return false;
        }
        id nc = add_cell(H, kv.second, entity, origin, update);
      }
    }

    /* Clean empty cells */
    for (id i = 0; i < nbe; ++i) {
      H.edges[i].vertices = {NO_ID,NO_ID};
    }
    for (id i = 0; i < nbf; ++i) {
      H.faces[i].edges.clear();
    }
    for (id i = 0; i < nbc; ++i) {
      H.cells[i].faces.clear();
    }
    remove_empty_elements(H);
    update_brep_mesh_mappings(H);

    return true;
  }
}
