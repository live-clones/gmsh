// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include "hblTypes.hpp"

#include <string>
#include <unordered_map>

// QuadMeshingTools includes
#include "arrayGeometry.h"

class MVertex;
class MLine;
class MElement;
class GEntity;

namespace hbl {

  using namespace ArrayGeometry;

  /***********************************/
  /* Boundary representation of mesh */
  struct Vertex {
    vec3 pt = NO_VEC3;
    GEntity* entity = nullptr;
    MVertex* origin = nullptr;
  };

  struct Edge {
    id2 vertices = {NO_ID,NO_ID};
    GEntity* entity = nullptr;
    MLine* origin = nullptr;
  };

  struct Face {
    std::vector<id> edges;
    std::vector<bool> edge_orient_invert;
    GEntity* entity = nullptr;
    MElement* origin = nullptr;
  };

  struct Cell {
    std::vector<id> faces;
    GEntity* entity = nullptr;
    MElement* origin = nullptr;
    int data = 0;
  };

  struct BrepMesh {
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Face> faces;
    std::vector<Cell> cells;
    std::vector<std::vector<id> > vertToEdges;
    std::vector<std::vector<id> > edgeToFaces;
    std::vector<std::vector<id> > faceToCells;
  };
  /***********************************/


  /***********************************/
  /* Warning: be careful with performance when using the functions that
   *          return std::vector by value. Use them outside of loops or for 
   *          debugging and quick prototyping */
  /* BrepMesh functions */
  bool face_vertices(const BrepMesh& M, id f, std::vector<id>& vert);
  bool cell_vertices(const BrepMesh& M, id c, std::vector<id>& vert);
  bool cell_edges(const BrepMesh& M, id c, std::vector<id>& edges);
  bool cell_edges_and_vertices(const BrepMesh& M, id c, std::vector<id>& edges, std::vector<id>& vert);
  bool cell_face_vertices(const BrepMesh& M, id c, id lf, std::vector<id>& vert);
  inline id edge_opposite_vertex(id2 edge, id v);
  inline id2 edge_overtices(const BrepMesh& M, id e, bool inv);

  /* When brep mappings computed */
  bool vertex_adjacent_faces(const BrepMesh& M, id v, std::vector<id>& faces);
  bool vertex_adjacent_cells(const BrepMesh& M, id v, std::vector<id>& cells);

  /* More convenient but less efficient functions, because containers are not re-used in loops */
  std::vector<id> face_vertices(const BrepMesh& M, id f);
  std::vector<id> cell_vertices(const BrepMesh& M, id c);
  std::vector<id> cell_edges(const BrepMesh& M, id c);

  /* Shortcuts to add stuff */
  id add_vertex(BrepMesh& M, vec3 pt, GEntity* entity = nullptr, MVertex* origin = nullptr, bool updateMapping = false);
  id add_edge(BrepMesh& M, const id2& vertices, GEntity* entity = nullptr, MLine* origin = nullptr, bool updateMapping = false);
  id add_face(BrepMesh& M, const std::vector<id>& edges, GEntity* entity = nullptr, MElement* origin = nullptr, bool updateMapping = false);
  id add_cell(BrepMesh& M, const std::vector<id>& faces, GEntity* entity = nullptr, MElement* origin = nullptr, bool updateMapping = false);
  bool invert_face(BrepMesh& M, id f);

  /* Geometry */
  std::vector<vec3> points_from_vertices(const BrepMesh& M, const std::vector<id>& vert);
  std::vector<vec3> edge_points(const BrepMesh& M, const id2& vert);
  std::vector<vec3> edge_points(const BrepMesh& M, id f);
  vec3 points_center(const std::vector<vec3>& pts);
  vec3 edge_center(const BrepMesh& M, id e);
  vec3 edge_direction(const BrepMesh& M, id e);
  double edge_length(const BrepMesh& M, id e);
  vec3 face_center(const BrepMesh& M, id f);
  vec3 face_normal(const BrepMesh& M, id f);
  double face_average_edge_length(const BrepMesh& M, id f);
  vec3 apply_scaling(vec3 p, vec3 c, double scale);
  std::vector<vec3> apply_scaling(const std::vector<vec3>& pts, vec3 c, double scale);

  /* Specific to quad faces */
  id quad_opposite_edge(const BrepMesh& M, id f, id e);
  id quad_opposite_vertex(const BrepMesh& M, id f, id v);

  /* Specific to hex cells */
  bool hex_vertices(const BrepMesh& M, id c, std::vector<id>& hex_vert);
  std::vector<id> hex_vertices(const BrepMesh& M, id c);
  bool hex_opposite_face_vertices(const BrepMesh& M, id c, const std::vector<id>& face_vert, std::vector<id>& op_face_vert);
  id hex_opposite_face(const BrepMesh& M, id c, id f);
  /* hex mesh validity */
  bool hex_is_valid(const BrepMesh& M, const Cell& cell, bool print_error_details = false);
  bool check_hex_mesh_cells(const BrepMesh& H, bool verbose = false, bool vizu_errors = false, bool ignore_empty = false);
  bool hex_mesh_is_valid(const BrepMesh& H, bool verbose = true, bool vizu_errors = false, bool ignore_empty = false);
  /* only check subset of hex mesh */
  bool check_hex_mesh_cells(const BrepMesh& H, const std::vector<id>& hexes, bool verbose = false, bool vizu_errors = false, bool ignore_empty = false);
  bool hex_mesh_is_valid(const BrepMesh& H, const std::vector<id>& hexes, bool verbose = true, bool vizu_errors = false, bool ignore_empty = false);
  inline id8 invert_hex(const id8& hex);
  inline id4 invert_tet(const id4& tet);

  /* Diagnostic tools */
  void print_cell_details(const BrepMesh& M, const Cell& cell);

  /* More high level functions */
  bool remove_empty_elements(BrepMesh& M);
  void clear_mesh(BrepMesh& M);
  std::vector<id> face_vertices_from_edges(const BrepMesh& M, const std::vector<id>& edges);
  bool triangulate_faces(BrepMesh& M, bool update_mappings = false);
  bool compute_oriented_hexahedra(const BrepMesh& H, std::vector<id8>& hexes, std::vector<int>& ballId); /* purely topological */
  bool explicit_triangles_from_quad_faces(const BrepMesh& M, const std::vector<id>& quadFaces, std::vector<id3>& triVertices);
  double localEdgeLengthAroundVertex(const BrepMesh& Q, id v, bool secondRing = false);

  bool compute_oriented_elements(const BrepMesh& H, std::vector<std::vector<id> >& eltVertices, std::vector<int>& ballId); /* purely topological */

  /* Very high level functions */
  bool update_brep_mesh_mappings(BrepMesh& M);
  bool merge_vertices(BrepMesh& H, 
      const std::vector<id2>& equalities,
      std::vector<id>& v_old2new,
      std::vector<id>& e_old2new,
      std::vector<id>& f_old2new,
      std::vector<id>& c_old2new);

  bool brepMeshMappingsAreUpToDate(const BrepMesh& M); /* only check dimensions */

  bool merge_vertices(BrepMesh& H, const std::vector<id2>& equalities);

  bool merge_vertices_light(BrepMesh& H, 
      const std::vector<id2>& equalities,
      std::vector<id>& v_old2new,
      std::vector<id>& e_old2new,
      std::vector<id>& f_old2new,
      std::vector<id>& c_old2new);

  bool subdivide_hex_boundary_layer_anistropic(BrepMesh& H, int N);

  /* Use merge_vertices_hash if the mesh is big and the number of affected elements is small
   * compared to the mesh size (e.g. less than 1%).
   * Under the hood, it will use hash maps intead of global vectors */
  bool merge_vertices_hash(BrepMesh& H, 
      const std::vector<id2>& equalities,
      std::unordered_map<id,id>& v_old2new,
      std::unordered_map<id,id>& e_old2new,
      std::unordered_map<id,id>& f_old2new,
      std::unordered_map<id,id>& c_old2new);


  bool midpoint_subdivision(BrepMesh& H);

  /* basic geometric check using epsilon, without exact predicates, not robust */
  bool in_tetrahedron(vec3 query, const std::array<vec3,4>& points, double lambda[4], double lambda_epsilon = 0.);

  /* Visualization functions (via GeoLog) */
  bool visualization_show_cell(const BrepMesh& M, const Cell& cell, const std::string& viewName, double scale = 1.);


  /***********************************/

  /***********************************/
  /* Utility functions */
  inline vec3 opposite_right_angled_corner(vec3 pPrev, vec3 pCorner, vec3 pNext);
  std::pair<vec3,vec3> bbox_of_points(const std::vector<vec3>& pts);
  std::pair<vec3,vec3> bbox_of_mesh(const BrepMesh& M);

  /***********************************/
  /* Inline definitions */
  /***********************************/
  id edge_opposite_vertex(id2 edge, id v) {
    if (edge[0] == v) {
      return edge[1];
    } else if (edge[1] == v) {
      return edge[0];
    }
    return NO_ID;
  }

  id2 edge_overtices(const BrepMesh& M, id e, bool inv) {
    if (!inv) return M.edges[e].vertices;
    return {M.edges[e].vertices[1],M.edges[e].vertices[0]};
  }

  id8 invert_hex(const id8& hex) {
    id8 ihex = hex;
    ihex[1] = hex[4];
    ihex[4] = hex[1];
    ihex[2] = hex[7];
    ihex[7] = hex[2];
    return ihex;
  }

  id4 invert_tet(const id4& tet) {
    return {tet[0],tet[1],tet[3],tet[2]};
  }

  vec3 opposite_right_angled_corner(vec3 pPrev, vec3 pCorner, vec3 pNext) {
    double radius = 0.5 * length(pPrev-pNext);
    vec3 center = 0.5 * (pPrev+pNext);
    if (length(center-pCorner) < 1.e-10) {
      return center;
    }
    vec3 dir = center-pCorner;
    normalize(dir);
    return center + radius * dir;
  }
}
