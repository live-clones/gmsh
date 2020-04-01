// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>
#include <math.h>

namespace QMT {
  /* Basic types */
  using vec2 = std::array<double,2>;
  using vec3 = std::array<double,3>;
  using id   = uint32_t;
  using sid  = int64_t;
  using id2  = std::array<id, 2>;
  using id3  = std::array<id, 3>;
  using id4  = std::array<id, 4>;
  using sid2 = std::array<sid, 2>;
  using sid3 = std::array<sid, 3>;
  using sid4 = std::array<sid, 4>;

  constexpr QMT::id   NO_ID  = (QMT::id) -1;
  constexpr QMT::sid  NO_SID = (QMT::sid) NO_ID;
  constexpr uint8_t   NO_U8 = (uint8_t) -1;

  /* Quad mesh data structure */
  struct QMesh {
    /* one value per vertex */
    std::vector<vec3> points;
    // std::vector<bool> onCorner;
    // std::vector<bool> onBoundary;
    std::vector<double> size;
    // std::vector<std::pair<int,int>> geoEntity;
    std::vector<std::pair<int,int>> entity;

    /* one value per quad */
    std::vector<id4> quads;
    std::vector<id> color;
    std::vector<sid4> quad_neighbors;
    std::vector<std::vector<id>> nm_quad_neighbors;
    std::vector<int> quadEntity;
  };

  /* Triangular mesh data structure */
  struct TMesh {
    /* one value per vertex */
    std::vector<vec3> points;
    std::vector<bool> onCorner;
    std::vector<bool> onBoundary;
    std::vector<double> size;
    std::vector<id> pt_color;

    /* one value per line */
    std::vector<id2> lines;
    std::vector<id> line_colors;
    std::vector<id> line_elt_tags;

    /* one value per triangle */
    std::vector<id3> triangles;
    std::vector<id> tri_colors;
    std::vector<id> tri_elt_tags;
    std::vector<sid3> triangle_neighbors;
    std::vector<std::vector<id>> nm_triangle_neighbors;
  };

  /* Simplex mesh data structure */
  struct SMesh {
    /* one value per vertex */
    std::vector<vec3> points;
    std::vector<std::pair<int,int>> vEntity;

    /* one value per line */
    std::vector<id2> lines;
    std::vector<std::pair<int,int>> lEntity;

    /* one value per triangle */
    std::vector<id3> triangles;
    std::vector<std::pair<int,int>> triEntity;

    /* one value per tetrahedron */
    std::vector<id3> tetrahedra;
    std::vector<std::pair<int,int>> tetEntity;

  };


  /* Quad mesh with T junctions, brep representation */
  struct TVertex {
    vec3 pt;
    std::pair<int,int> entity;
    int origin;
  };

  struct TEdge {
    id2 vertices;
    std::vector<vec3> pts;
    std::pair<int,int> entity;
    int origin;
  };

  struct TFace {
    std::vector<id> edges;
    std::vector<uint8_t> edge_sides;
    std::vector<bool> edge_orient_invert;
    std::pair<int,int> entity;
    int origin;
  };

  struct QTMesh {
    std::vector<TVertex> vertices;
    std::vector<TEdge> edges;
    std::vector<TFace> faces;
    std::vector<std::vector<id>> vertToEdges;
    std::vector<std::vector<id>> edgeToFaces;
  };


  /* vec3 math */
  inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
  inline double length2  (const vec3& a) { return dot(a,a); }
  inline double length   (const vec3& a) { return sqrt(length2(a)); }
  inline vec3 operator-(const vec3& a, const vec3& b) { return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
  inline vec3 operator+(const vec3& a, const vec3& b) { return {a[0]+b[0], a[1]+b[1], a[2]+b[2]}; }
  inline vec3 operator*(const double& a, const vec3& b) { return {a*b[0], a*b[1], a*b[2]}; }
  inline vec3 operator*(const vec3& a, const double& b) { return {a[0]*b, a[1]*b, a[2]*b}; }
  inline vec3 cross(const vec3& a, const vec3& b) { return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};}
  inline vec3 normalize(vec3 v) { return v * double(1./length(v)); }
  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }
  inline double angle_nvectors(vec3 a, vec3 b) { return acos(clamp(dot(a,b),-1.,1.)); }
  inline double angle_vectors(vec3 a, vec3 b) { a = normalize(a); b = normalize(b); return angle_nvectors(a,b); }

  /* vec2 math */
  inline double dot      (const vec2& a, const vec2& b) { return a[0]*b[0]+a[1]*b[1]; }
  inline double length2  (const vec2& a) { return dot(a,a); }
  inline double length   (const vec2& a) { return sqrt(length2(a)); }
}
