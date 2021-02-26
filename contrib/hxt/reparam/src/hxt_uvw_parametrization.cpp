#include "hxt_uvw_parametrization.h"
#include "hxt_uvw_cpp_utils.hpp"
#include "OpenNL_psm.h" /* least square solver */

extern "C" {
#include "hxt_tetRepair.h"
}

#include <array>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <float.h>

#include <cstddef>
#include <ostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>

#ifdef GMSH_LINKED
#include "gmsh.h"
#include "geolog.h"
#endif

/* - Macros */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); UVWLogging::show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout)
#define RF(...) do {UVWLogging::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {UVWLogging::error(__VA_ARGS__); return false;} } while(0)

using std::vector;
using std::unordered_map;
using std::array;
using std::pair;

namespace UVWLogging {
  static inline void sformat(std::ostream& out, const char* s) {
    while (*s) {
      if (*s == '{' && *++s != '}') 
        throw std::runtime_error("invalid format string: missing arguments");
      out << *s++;
    }
  }

  template<typename T, typename... Args>
    static void sformat(std::ostream& out, const char* s, const T& value, const Args&... args) {
      while (*s) {
        if (*s == '{' && *++s == '}') {
          out << value;
          return sformat(out, ++s, args...);
        }
        out << *s++;
      }
      printf("! sformat problem, input: %s\n",s);
      throw std::runtime_error("extra arguments provided to printf");
    }

  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::stringstream stream;
      sformat(stream, format, args...);
      std::cerr << "[Error]   " << stream.str() << std::endl;
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::stringstream stream;
      sformat(stream, format, args...);
      std::cout << "[Warning] " << stream.str() << std::endl;
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::stringstream stream;
      sformat(stream, format, args...);
      std::cout << "[Info]    " << stream.str() << std::endl;
    }

  /* For debug prints */
  template<typename H1>
    std::ostream& show(std::ostream& out, const char* label, H1&& value) {
      return out << label << "=" << std::forward<H1>(value) << '\n';
    }

  template<typename H1, typename ...T>
    std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
      const char* pcomma = strchr(label, ',');
      return show(out.write(label, pcomma - label) << "="
          << std::forward<H1>(value)
          << ',',
          pcomma + 1,
          std::forward<T>(rest)...);
    }
}

using namespace UVWLogging;

namespace HxtUVW {
  constexpr double CRITERIA_SINGULAR_REGION = 0.2;


  /* Basic types */
  using vec3 = std::array<double,3>;
  using id   = uint32_t;
  using id2  = std::array<id, 2>;
  using id3  = std::array<id, 3>;
  using id4  = std::array<id, 4>;

  constexpr id   NO_ID  = (id) -1;
  constexpr vec3 NO_VEC3 = {DBL_MAX,DBL_MAX,DBL_MAX};
  constexpr std::pair<int,int> NO_ENTITY = {-1,-1};

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
  inline double angle_abs_nvectors(vec3 a, vec3 b) { return acos(clamp(std::abs(dot(a,b)),0.,1.)); }
  inline double angle_vectors(vec3 a, vec3 b) { a = normalize(a); b = normalize(b); return angle_nvectors(a,b); }

  /* other */
  inline double to_deg(double a) {return 180. / M_PI * a;}
  inline double to_rad(double a) {return M_PI / 180. * a;}

  /* id useful functions */
  inline id2 sorted(id v1, id v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }
  inline id2 sorted(id2 e) { if (e[0] < e[1]) { return {e[0],e[1]}; } else { return {e[1],e[0]}; } }
  struct id2Hash {
    size_t operator()(id2 p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };
  struct id4Hash {
    size_t operator()(id4 p) const noexcept {
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


  /* Some local ordering */
  constexpr id TET_FACET_VERT[4][3] = {{1,3,2},{0,2,3},{3,1,0},{0,1,2}};
  constexpr id TET_EDGES[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};

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
    std::vector<id4> tetrahedra;
    std::vector<std::pair<int,int>> tetEntity;

    /* tet adjacencies: adjacent[4*c+lf] = [4*c2+lf2] or NO_ID */
    std::vector<id> adjacent;
  };

  inline id tet_face_vertex(const SMesh& M, id c, id lf, id lfv) {
    return M.tetrahedra[c][TET_FACET_VERT[lf][lfv]];
  }

  inline id3 tet_face_vertices(const SMesh& M, id c, id lf) {
    return {
      M.tetrahedra[c][TET_FACET_VERT[lf][0]],
      M.tetrahedra[c][TET_FACET_VERT[lf][1]],
      M.tetrahedra[c][TET_FACET_VERT[lf][2]]};
  }

  inline id tet_edge_vertex(const SMesh& M, id c, id le, id lv) {
    return M.tetrahedra[c][TET_EDGES[le][lv]];
  }

  inline id2 tet_edge_vertices(const SMesh& M, id c, id le) {
    return {M.tetrahedra[c][TET_EDGES[le][0]],M.tetrahedra[c][TET_EDGES[le][1]]};
  }

  inline vec3 tri_normal(const vec3& p1, const vec3& p2, const vec3& p3) {
    return cross(p2 - p1, p3 - p1);
  }

  inline vec3 tet_face_normal(const SMesh& M, id c, id lf) {
    return tri_normal(
        M.points[tet_face_vertex(M,c,lf,0)],
        M.points[tet_face_vertex(M,c,lf,1)],
        M.points[tet_face_vertex(M,c,lf,2)]);
  }

  vec3 points_center(const vector<vec3>& pts) {
    if (pts.size() == 0) return NO_VEC3;
    vec3 center = {0.,0.,0.};
    F(i,pts.size()) center = center + pts[i];
    center = 1./double(pts.size()) * center;
    return center;
  }

  inline double tet_volume(const vec3& p1, const vec3& p2,
      const vec3& p3, const vec3& p4) {
    return std::abs(dot(p2 - p1, cross(p3 - p1, p4 - p1)) / 6.0);
  }

  inline double tet_volume(const array<vec3,4>& pts) {
    return std::abs(tet_volume(pts[0],pts[1],pts[2],pts[3]));
  }

  template<std::size_t dim>
    vec3 points_center(const array<vec3,dim>& pts) {
      if (pts.size() == 0) return NO_VEC3;
      vec3 center = {0.,0.,0.};
      F(i,pts.size()) center = center + pts[i];
      center = 1./double(pts.size()) * center;
      return center;
    }

  template<std::size_t dim>
    std::array<vec3,dim> points(const SMesh& M, std::array<id,dim> vert) {
      std::array<vec3,dim> pts;
      F(i,vert.size()) pts[i] = M.points[vert[i]];
      return pts;
    }

  /* For quick visualization via GeoLog */
  template<std::size_t dim>
    std::vector<vec3> to_vector(const std::array<vec3,dim>& arr) {
      std::vector<vec3> vec(arr.size());
      F(i,vec.size()) vec[i] = arr[i];
      return vec;
    }


  bool mesh_from_hxt(const HXTMesh* mesh, SMesh& M) {
    M.points.resize(mesh->vertices.size);
    M.vEntity.resize(mesh->vertices.size);
    M.lines.resize(mesh->lines.size);
    M.lEntity.resize(mesh->lines.size);
    M.triangles.resize(mesh->triangles.size);
    M.triEntity.resize(mesh->triangles.size);
    M.tetrahedra.resize(mesh->tetrahedra.size);
    M.tetEntity.resize(mesh->tetrahedra.size);
    M.adjacent.resize(4*mesh->tetrahedra.size);

    F(v,M.points.size()) {
      M.points[v] = {mesh->vertices.coord[4*v+0],
        mesh->vertices.coord[4*v+1],
        mesh->vertices.coord[4*v+2]};
      M.vEntity[v] = NO_ENTITY;
    }

    F(i,M.lines.size()) {
      M.lines[i] = {
        mesh->lines.node[2*i+0],
        mesh->lines.node[2*i+1]};
      M.lEntity[i] = NO_ENTITY;
    }

    F(i,M.triangles.size()) {
      M.triangles[i] = {
        mesh->triangles.node[3*i+0],
        mesh->triangles.node[3*i+1],
        mesh->triangles.node[3*i+2]
      };
      M.triEntity[i] = NO_ENTITY;
    }

    F(i,M.tetrahedra.size()) {
      M.tetrahedra[i] = {
        mesh->tetrahedra.node[4*i+0],
        mesh->tetrahedra.node[4*i+1],
        mesh->tetrahedra.node[4*i+2],
        mesh->tetrahedra.node[4*i+3]};
      M.tetEntity[i] = NO_ENTITY;
    }

    if (mesh->tetrahedra.neigh != NULL) {
      F(c,M.tetrahedra.size()) F(lf,4) {
        if (mesh->tetrahedra.neigh[4*c+lf] == HXT_NO_ADJACENT) {
          M.adjacent[4*c+lf] = NO_ID;
        } else {
          M.adjacent[4*c+lf] = mesh->tetrahedra.neigh[4*c+lf];
        }
      }
    } else {
      M.adjacent.clear();
    }

    return true;
  }

  double mesh_approximate_edge_size(const SMesh& M) {
    if (M.tetrahedra.size() == 0) return DBL_MAX;
    double sum = 0.;
    F(c,M.tetrahedra.size()) {
      vec3 p1 = M.points[M.tetrahedra[c][0]];
      vec3 p2 = M.points[M.tetrahedra[c][1]];
      sum += length(p2-p1);
    }
    sum /= double(M.tetrahedra.size());
    return sum;
  }
  

  bool approximate_distance_to_boundary_and_singular_regions(
      const SMesh& M, 
      const double* gradientIndicator,
      const unordered_map<id2,bool,id2Hash>& edgeIsSingular,
      vector<double>& tDist) {
    tDist.clear();
    tDist.resize(M.tetrahedra.size(),DBL_MAX);

    /* Approx. distance with Dijsktra algo. */
    vector<double>& dist = tDist;
    std::priority_queue<pair<double,id>,  vector<pair<double,id> >,  std::greater<pair<double,id> > > Q; 

    /* Init with tets connected to boundary */
    F(c,M.tetrahedra.size()) FC(lf,4,dist[c] == DBL_MAX && M.adjacent[4*c+lf] == NO_ID) {
      vec3 c_center = points_center(points(M,M.tetrahedra[c]));
      vec3 f_center = points_center(points(M,tet_face_vertices(M,c,lf)));
      dist[c] = length(f_center-c_center);
      Q.push({dist[c],c});
    }

    /* Init with tets touching singular edges */
    FC(c,M.tetrahedra.size(),dist[c] == DBL_MAX && gradientIndicator[c] > CRITERIA_SINGULAR_REGION/2.) {
      /* gradient indicator just used to avoid too many queries */
      F(le,6) {
        id2 edge = sorted(tet_edge_vertices(M,c,le));
        auto it = edgeIsSingular.find(edge);
        if (it != edgeIsSingular.end()) { /* Singular edge ! */
          vec3 c_center = points_center(points(M,M.tetrahedra[c]));
          vec3 e_center = points_center(points(M,edge));
          dist[c] = length(e_center-c_center);
          Q.push({dist[c],c});
          break;
        }
      }
    }

    /* Dijsktra loop */
    while (Q.size() > 0) {
      id c = Q.top().second;
      Q.pop();
      vec3 c_center = points_center(points(M,M.tetrahedra[c]));

      FC(lf,4,M.adjacent[4*c+lf] != NO_ID) {
        id n = M.adjacent[4*c+lf];
        id c2 = n / 4;
        id lf2 = n % 4;
        vec3 c2_center = points_center(points(M,M.tetrahedra[c2]));
        double dij = length(c2_center - c_center);
        if (dist[c] + dij < dist[c2]) {
          dist[c2] = dist[c] + dij;
          Q.push({dist[c2],c2});
        }
      }
    }

    return true;
  }

  /* i is the tet index, d in [0,6[ is the branch number */
  inline vec3 frame_branch(const double* directionsScaled, id i, id d) {
    if (d < 3) {
      return {
        directionsScaled[9*i+3*d+0],
        directionsScaled[9*i+3*d+1],
        directionsScaled[9*i+3*d+2]};
    } else if (d < 6) {
      return {
        -1. * directionsScaled[9*i+3*(d%3)+0],
        -1. * directionsScaled[9*i+3*(d%3)+1],
        -1. * directionsScaled[9*i+3*(d%3)+2]};
    }
    return NO_VEC3;
  }

  inline array<vec3,3> normalized_frame(const double* directionsScaled, id i) {
    return {
      normalize(frame_branch(directionsScaled,i,0)),
        normalize(frame_branch(directionsScaled,i,1)),
        normalize(frame_branch(directionsScaled,i,2))};
  }

  /* assume directions are normalized */
  inline id3 matching_directions(const array<vec3,3>& ref, const array<vec3,3>& candidates) {
    id3 out;
    bool matched[3] = {false,false,false};
    F(k,3) {
      double dmax = -DBL_MAX;
      id best = NO_ID;
      double bsign = 0.;
      FC(k2,3,!matched[k2]) {
        double dp = dot(ref[k],candidates[k2]);
        if (std::abs(dp) > dmax) {
          bsign = (dp > 0) ? 1. : -1.;
          best = k2;
          dmax = std::abs(dp);
        }
      }
      if (best != NO_ID) {
        out[k] = (bsign > 0) ? best : best+3;
        matched[best] = true;
      } else {
        error("no matching between reference and candidates directions, should not happen");
        return {NO_ID,NO_ID,NO_ID};
      }
    }
    return out;
  }

  bool ordered_edge_tet_fan(const SMesh& M,
      const vector<vector<id>>& e2t,
      id e,
      vector<id>& oTets) {
    oTets.clear();
    const vector<id>& tets = e2t[e];
    if (tets.size() < 3) return false;
    vector<bool> assigned(tets.size(),false);
    oTets.push_back(tets[0]);
    assigned[0] = true;
    while (oTets.size() != tets.size()) {
      id c = oTets.back();
      bool found = false;
      FC(lf,4,M.adjacent[4*c+lf] != NO_ID) {
        id n = M.adjacent[4*c+lf];
        id ac = n / 4;
        id alf = n % 4;
        if (inVector(ac,oTets)) continue;
        if (!inVector(ac,tets)) continue;
        oTets.push_back(ac);
        found = true;
        break;
      }
      if (!found) {
        break;
      }
    }
    if (oTets.size() != tets.size())  {
      oTets.clear();
      return false;
    }
    /* Check first and last are adjacent */
    bool ok = false;
    F(lf,4) {
      id ac = M.adjacent[4*oTets.back()+lf] / 4;
      if (ac == oTets.front()) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      oTets.clear();
      return false;
    } 
    return true;
  }

  bool detect_singular_edges(
      const SMesh& M,
      const double* directionsScaled,
      const double* gradientIndicator,
      unordered_map<id2,bool,id2Hash>& edgeIsSingular) {
    info("detect singular edges (permutation in tet fans) ...");

    /* Links between tet edges and unique internal edge */
    std::vector<id2> edges;
    std::vector<id> te2e(6*M.tetrahedra.size(),NO_ID);
    vector<vector<id>> e2t;
    {
      std::vector<id2> redges(6*M.tetrahedra.size());
      F(c,M.tetrahedra.size()) F(le,6) {
        id2 edge = sorted(tet_edge_vertices(M,c,le));
        redges[6*c+le] = edge;
      }
      sort_unique_with_perm(redges, edges, te2e);
      e2t.resize(edges.size());
      F(c,M.tetrahedra.size()) F(le,6) {
        e2t[te2e[6*c+le]].push_back(c);
      }
    }

    /* Loop over edges */
    vector<id> oTets;
    vector<array<vec3,3> > dirs;
    F(e,e2t.size()) {
      bool ok = ordered_edge_tet_fan(M,e2t,e,oTets);
      if (!ok || oTets.size() == 0) continue;

      /* Collect closest branches around the tet fan */
      dirs.clear();
      dirs.resize(oTets.size()+1);
      dirs[0] = normalized_frame(directionsScaled,oTets[0]);
      for (id i = 1; i < oTets.size()+1; ++i) {
        id ii = i % oTets.size();
        const array<vec3,3>& prev = dirs[i-1];
        array<vec3,3> candidates = normalized_frame(directionsScaled,oTets[ii]);
        id3 adjBranches = matching_directions(prev,candidates);
        dirs[i][0] = normalize(frame_branch(directionsScaled,oTets[ii],adjBranches[0]));
        dirs[i][1] = normalize(frame_branch(directionsScaled,oTets[ii],adjBranches[1]));
        dirs[i][2] = normalize(frame_branch(directionsScaled,oTets[ii],adjBranches[2]));
      }

      /* Check angle between first and last */
      bool isSingular = false;
      F(k,3) {
        double agl = angle_nvectors(dirs.front()[k],dirs.back()[k]);
        if (std::abs(agl) > 0.1) {
          isSingular = true;
          break;
        } 
      }
      if (isSingular) {
        edgeIsSingular[edges[e]] = true;
      }
    }
    info("{} singular edges detected",edgeIsSingular.size());

    return true;
  }

  bool build_cut_graph_and_lifting(
      const SMesh& M,
      const double* directionsScaled,
      const double* gradientIndicator,
      vector<bool>& tfIsCut,
      vector<id>& ballId, /* if multiple components */
      vector<vec3>& dir_u,
      vector<vec3>& dir_v,
      vector<vec3>& dir_w) {
    info("build cut graph and frame field lifting ...");
    tfIsCut.clear();
    ballId.clear();
    dir_u.clear();
    dir_v.clear();
    dir_w.clear();
    tfIsCut.resize(4*M.tetrahedra.size(),true);
    ballId.resize(M.tetrahedra.size(),NO_ID);
    dir_u.resize(M.tetrahedra.size(),NO_VEC3);
    dir_v.resize(M.tetrahedra.size(),NO_VEC3);
    dir_w.resize(M.tetrahedra.size(),NO_VEC3);

    /* Singularity extraction (network of edges) */
    unordered_map<id2,bool,id2Hash> edgeIsSingular;
    bool oks = detect_singular_edges(M, directionsScaled, gradientIndicator, edgeIsSingular);
    RFC(!oks,"failed to detect singularities");
    {
#ifdef GMSH_LINKED
      GLog::GeoLog log;
      for (auto kv: edgeIsSingular) {
        vector<vec3> pts = to_vector(points(M,kv.first));
        vector<double> values(2,0.);
        log.add(pts,values,"singularEdges");
      }
#endif
    }

    /* Distance for priority */
    vector<double> tDist(M.tetrahedra.size(),DBL_MAX);
    bool okd = approximate_distance_to_boundary_and_singular_regions(M, gradientIndicator, edgeIsSingular, tDist);
    RFC(!okd,"failed to compute distance to boundary and singular regions");

    /* Boundaries are not in cut graph */
    F(c,M.tetrahedra.size()) FC(lf,4,M.adjacent[4*c+lf] == NO_ID) {
      tfIsCut[4*c+lf] = false;
    }


    /* Step 1: spanning tree */
    {
      id nbBall = 0;
      info("- spanning tree ...");
      vector<bool> visited(M.tetrahedra.size(), false);
      vector<id> tetNo(M.tetrahedra.size(),false);
      FC(cInit,M.tetrahedra.size(),!visited[cInit]) {
        if (gradientIndicator[cInit] > 0.15) continue;
        /* BFS seed */
        std::priority_queue<pair<double,id>, vector<pair<double,id>>, std::less<pair<double,id>> > Q; 
        double distInit = tDist[cInit];
        Q.push({distInit,cInit});
        dir_u[cInit] = frame_branch(directionsScaled, cInit, 0);
        dir_v[cInit] = frame_branch(directionsScaled, cInit, 1);
        dir_w[cInit] = frame_branch(directionsScaled, cInit, 2);
        visited[cInit] = true;
        nbBall += 1;

        /* Propagation */
        id round = 0;
        while(Q.size() > 0) {
          id c = Q.top().second;
          double cDist = Q.top().first;
          Q.pop();
          ballId[c] = nbBall;
          array<vec3,3> curDirs = {
            normalize(dir_u[c]),
            normalize(dir_v[c]),
            normalize(dir_w[c])
          };
          tetNo[c] = round;
          round += 1;

          /* Neighbors */
          F(lf, 4)  {
            id n = M.adjacent[4*c+lf];
            if (n == NO_ID) continue;
            id ac = n / 4;
            id alf = n % 4;
            if (visited[ac]) continue;
            array<vec3,3> candidates = normalized_frame(directionsScaled,ac);
            id3 adjBranches = matching_directions(curDirs,candidates);
            dir_u[ac] = frame_branch(directionsScaled,ac,adjBranches[0]);
            dir_v[ac] = frame_branch(directionsScaled,ac,adjBranches[1]);
            dir_w[ac] = frame_branch(directionsScaled,ac,adjBranches[2]);
            visited[ac] = true;
            tfIsCut[4*c+lf] = 0;
            tfIsCut[4*ac+alf] = 0;
            double dist = tDist[c];
            Q.push({dist,ac});
          }
        }
      }
#ifdef GMSH_LINKED
      { /* Visu / debug */
        GLog::GeoLog log;
        F(c,M.tetrahedra.size()) {
          vector<vec3> pts = to_vector(points(M,M.tetrahedra[c]));
          {
            vector<double> values(4,double(tetNo[c]));
            log.add(pts,values,"cg_tet_no",true);
          {
            vector<double> values(4,tDist[c]);
            log.add(pts,values,"cg_tDist",true);
          }
          }
        }
      }
#endif
    }
    {
      id nicg = 0;
      F(c,M.tetrahedra.size()) FC(lf,4,tfIsCut[4*c+lf]) nicg += 1;
      nicg /= 2;
      info("  {} faces in cut-graph",nicg);
    }

    /* Step 2: prune cut graph */
    {
      info("- pruning ...");

      unordered_map<id2,id,id2Hash> bdrEdges;
      F(c,M.tetrahedra.size()) FC(lf,4, M.adjacent[4*c+lf] == NO_ID) {
        F(le,3) {
          id v1 = tet_face_vertex(M,c,lf,le);
          id v2 = tet_face_vertex(M,c,lf,(le+1)%3);
          bdrEdges[sorted(v1,v2)] = 1;
        }
      }

      /* tetFacetEdge to internal edge */
      std::vector<id> tfe2e(4*3*M.tetrahedra.size(),NO_ID);
      id nbEdges = 0;
      {
        std::vector<id2> redges(4*3*M.tetrahedra.size());
        F(c,M.tetrahedra.size()) F(lf,4) F(le,3) {
          id v1 = tet_face_vertex(M,c,lf,le);
          id v2 = tet_face_vertex(M,c,lf,(le+1)%3);
          redges[4*3*c+3*lf+le] = sorted(v1,v2);
        }
        std::vector<id2> iedges;
        sort_unique_with_perm(redges, iedges, tfe2e);
        nbEdges = (id) iedges.size();
      }

      /* pruning loop */
      bool remaining = true;
      id nbloop = 0;
      std::vector<id> edgeValence(nbEdges,0);
      std::vector<bool> tfAdded(4*M.tetrahedra.size(),false);
      while (remaining) {
        nbloop += 1;
        remaining = false;

        std::fill(edgeValence.begin(),edgeValence.end(),0);
        { 
          std::fill(tfAdded.begin(),tfAdded.end(),false);
          F(c,M.tetrahedra.size()) FC(lf,4, tfIsCut[4*c+lf] && !tfAdded[4*c+lf]) {
            F(le,3) {
              id edgeId = tfe2e[4*3*c+3*lf+le];
              edgeValence[edgeId] += 1;
            }
            tfAdded[4*c+lf] = true;
            if (M.adjacent[4*c+lf] == NO_ID) continue;
            tfAdded[M.adjacent[4*c+lf]] = true;
          }
        }

        F(c,M.tetrahedra.size()) FC(lf,4, tfIsCut[4*c+lf]) {
          id n = M.adjacent[4*c+lf];
          if (n == NO_ID) continue;
          id ac = n / 4;
          bool isHanging = false;
          F(le,3) {
            id v1 = tet_face_vertex(M,c,lf,le);
            id v2 = tet_face_vertex(M,c,lf,(le+1)%3);
            id edgeId = tfe2e[4*3*c+3*lf+le];
            if (edgeValence[edgeId] == 1) { /* Hanging edge candidate */
              /* Check if edge on boundary */
              auto it = bdrEdges.find(sorted(v1,v2));
              if (it == bdrEdges.end()) {
                /* Edge not on boundary, check if on singularity */
                id2 edg = sorted(v1,v2);
                auto it2 = edgeIsSingular.find(edg);
                if (it2 == edgeIsSingular.end()) {
                  /* Edge not on singularity */
                  isHanging = true;
                  break;
                }
              }
            }
          }
          if (!isHanging) continue;


          tfIsCut[4*c+lf] = false;
          tfIsCut[M.adjacent[4*c+lf]] = false;
          remaining = true;
        }

      }
      {
        id nicg = 0;
        F(c,M.tetrahedra.size()) FC(lf,4,tfIsCut[4*c+lf]) nicg += 1;
        nicg /= 2;
        info("  done ({} loops) -> {} faces in cut-graph",nbloop,nicg);
      }
    }

    return true;
  }

  bool system_reduction_using_graph(
      id n,
      const std::vector<id2>& equality_constraints,
      std::vector<id>& old2new,
      id& nbIndep) {

    std::vector<std::vector<id>> v2v(n);
    F(i,equality_constraints.size()) {
      v2v[equality_constraints[i][0]].push_back(equality_constraints[i][1]);
      v2v[equality_constraints[i][1]].push_back(equality_constraints[i][0]);
    }

    /* Greedy aggregation */
    std::deque<id> Q;
    old2new.resize(n);
    id count = 0;
    std::vector<bool> visited(n, false);
    F(i, n) {
      if (visited[i]) continue;
      Q.push_back(i);
      visited[i] = true;
      while(!Q.empty()) {
        id v = Q.front();
        Q.pop_front();
        old2new[v] = count;
        F(lv,v2v[v].size()) {
          id v2 = v2v[v][lv];
          if (visited[v2]) continue;
          visited[v2] = true;
          Q.push_back(v2);
        }
      }
      count += 1;
    }
    nbIndep = count;
    return true;
  }

  inline id var_from_mesh_ids(id ntets, id c, id lv, id k) {
    return 4*(ntets*k+c) + lv;
  }

  inline void var_to_mesh_ids(id ntets, id var, id& c, id& lv, id& k) {
    k = var / (4*ntets);
    id r = var - 4*ntets*k;
    c = r / 4;
    lv = r % 4;
  }

  inline const vector<vec3>& select_direction(
      const vector<vec3>& dir_u,
      const vector<vec3>& dir_v,
      const vector<vec3>& dir_w,
      id k) {
    if (k == 0) {
      return dir_u;
    } else if (k == 1) {
      return dir_v;
    } else {
      return dir_w;
    }
  }

  bool compute_uvw_integration(
      const SMesh& M,
      const HxtUVWParamOptions* opt,
      const vector<bool>& tfIsCut,
      const vector<id>& ballId,
      const vector<vec3>& dir_u,
      const vector<vec3>& dir_v,
      const vector<vec3>& dir_w,
      vector<vec3>& uvw
      ) {
    info("integrating lifted directions ...");

    /* Variables: u,v,w scalars at each tet corner */
    id ntets = M.tetrahedra.size();
    id nbvars = 12*ntets;
    uvw.clear();
    uvw.resize(ntets*4,{0.,0.,0.});
    info("- {} variables ({} tets)", nbvars,ntets);

    /* Equality constraints inside topological balls */
    vector<id2> equalities;
    F(c,M.tetrahedra.size()) {
      FC(lf,4,M.adjacent[4*c+lf] != NO_ID && !tfIsCut[4*c+lf]) {
        id3 matching_lfv = {TET_FACET_VERT[lf][0], TET_FACET_VERT[lf][1], TET_FACET_VERT[lf][2]};
        id3 matching_lfv2 = {NO_ID,NO_ID,NO_ID};

        id c2 = M.adjacent[4*c+lf] / 4;
        id lf2 = M.adjacent[4*c+lf] % 4;
        F(lfv,3) {
          id v = tet_face_vertex(M,c,lf,lfv);
          FC(lfv2,3,tet_face_vertex(M,c2,lf2,lfv2) == v) {
            matching_lfv2[lfv] = TET_FACET_VERT[lf2][lfv2];
          }
        }

        F(k,3) F(lv,3) {
          id2 eq = sorted(
              var_from_mesh_ids(ntets,c,matching_lfv[lv],k),
              var_from_mesh_ids(ntets,c2,matching_lfv2[lv],k));
          equalities.push_back(eq);
        }
      }
    }
    sort_unique(equalities);
    info("- {} variable equalities from topological ball",equalities.size());

    /* Reduction of unknowns */
    id nbi = 0;
    vector<id> old2new(nbvars,NO_ID);
    system_reduction_using_graph(nbvars,equalities,old2new,nbi);
    info("- {} free variables",nbi);

    /* Integration energy */
    vector<vector<pair<id,double>>> energy_constraints;
    const double scaling = 1. / mesh_approximate_edge_size(M);
    F(c,M.tetrahedra.size()) {
      double coef = -1./(3.*tet_volume(points(M, M.tetrahedra[c])));
      vec3 Ni[4];
      F(lf,4) {
        Ni[lf] = 0.5 * tet_face_normal(M,c,lf);
      }
      F(k,3) { /* Frame branch loop */
        const vector<vec3>& dir = select_direction(dir_u,dir_v,dir_w,k);
        F(d,3) { /* Vector components loop */
          vector<pair<id,double>> constraint;
          F(lv,4) { /* Tet vertices loop */
            id var = var_from_mesh_ids(ntets,c,lv,k);
            var = old2new[var]; /* system reduction */
            double val = coef * Ni[lv][d];
            if (std::abs(val) > 1.e-12) {
              constraint.push_back(std::make_pair(var, val));
            } 
          }
          double inv = 1. / length(dir[c]);
          vec3 uvec = normalize(dir[c]);
          if (opt->ignore_scaling) {
            inv = 1.;
          }
          constraint.push_back({NO_ID, scaling * inv * uvec[d]});
          energy_constraints.push_back(constraint);
        }
      }
    }

    /* Least square system */
    {
      nlNewContext();
      nlSolverParameteri(NL_LEAST_SQUARES, NL_TRUE);
      nlSolverParameteri(NL_NB_VARIABLES, (NLint) nbi);
      nlSolverParameteri(NL_MAX_ITERATIONS, 10000);
      nlSolverParameterd(NL_THRESHOLD, 1.e-10);
      nlEnable(NL_VERBOSE);
      nlBegin(NL_SYSTEM);
      nlBegin(NL_MATRIX);
      F(i,energy_constraints.size()) {
        nlBegin(NL_ROW);
        F(j,energy_constraints[i].size()) {
          id var = energy_constraints[i][j].first;
          double value = energy_constraints[i][j].second;
          if (var != NO_ID) {
            nlCoefficient(var,value);
          } else {
            nlRightHandSide(value);
          }
        }
        nlEnd(NL_ROW);
      }
      nlEnd(NL_MATRIX);
      nlEnd(NL_SYSTEM);

      /* Solve */
      nlSolve();

      /* Extract the result */
      vector<double> uvw_reduced(nbi,0.);
      F(i, uvw_reduced.size()) {
        uvw_reduced[i] = nlGetVariable(i);
      }
      nlDeleteContext(nlGetCurrent());

      /* Retrieve full solution */
      F(c,M.tetrahedra.size()) F(lv,4) F(k,3) {
        id var = var_from_mesh_ids(ntets,c,lv,k);
        id rvar = old2new[var];
        if (rvar != NO_ID) {
          uvw[4*c+lv][k] = uvw_reduced[rvar];
        }
      }
    }

    /* Statistics */
    double uvw_min[3] = {DBL_MAX,DBL_MAX,DBL_MAX};
    double uvw_max[3] = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    F(c,M.tetrahedra.size()) F(lv,4) F(d,3) {
      uvw_min[d] = std::min(uvw_min[d], uvw[4*c+lv][d]);
      uvw_max[d] = std::max(uvw_max[d], uvw[4*c+lv][d]);
    }

    info("uvw range: [{} {}] [{} {}] [{} {}]",
        uvw_min[0], uvw_max[0],
        uvw_min[1], uvw_max[1],
        uvw_min[2], uvw_max[2]);


    return true;
  }

};

using namespace HxtUVW;

HXTStatus computeUVW(
    HXTMesh* mesh,
    const double* directionsScaled,
    const double* gradientIndicator,
    const HxtUVWParamOptions* options,
    double* uvw
    ) {
  info("compute UVW parametrization ...");
  if (mesh->tetrahedra.neigh == NULL) {
    HXT_CHECK(hxtTetAdjacencies(mesh));
  }

  SMesh M;
  bool okm = mesh_from_hxt(mesh,M);
  if (!okm) HXT_ERROR_MSG(HXT_STATUS_ERROR, "failed to build SMesh from HXTMesh");

  /* Verify all frame directions are non-zero */
  {
    constexpr double EPS0 = 1.e-12;
    double dmin =  DBL_MAX;
    double dmax = -DBL_MAX;
    F(c,M.tetrahedra.size()) F(j,3) {
      vec3 dir = frame_branch(directionsScaled, c, j);
      double len = length(dir);
      if (len < EPS0) {
        error("tet {}, {}-th direction is ~0: {}", c, j, length(dir));
        error("Not supported, all cross branches must be non-zero.");
        return HXT_STATUS_ERROR;
      }
      dmin = std::min(dmin,len);
      dmax = std::max(dmax,len);
    }
    info("input direction norms: min={}, max={}",dmin,dmax);
  }

  if (options->ignore_scaling) {
    warn("ignore cross scaling (i.e. use unit vector fields)");
  }

  vector<bool> tfIsCut;
  vector<id> ballId;
  vector<vec3> dir_u;
  vector<vec3> dir_v;
  vector<vec3> dir_w;
  bool okcg = build_cut_graph_and_lifting(M, directionsScaled, gradientIndicator, tfIsCut, ballId, dir_u, dir_v, dir_w);
  if (!okcg) HXT_ERROR_MSG(HXT_STATUS_ERROR, "failed to build cut-graph");

  { /* Some stats */
    F(k,3) {
      const vector<vec3>& dir = select_direction(dir_u,dir_v,dir_w,k);
      double dmin =  DBL_MAX;
      double dmax = -DBL_MAX;
      F(i,dir.size()) {
        double len = length(dir[i]);
        dmin = std::min(dmin,len);
        dmax = std::max(dmax,len);
      }
      info("lifted field {} norms: min={}, max={}",k,dmin,dmax);
    }
  }

  /* Vizu */
#ifdef GMSH_LINKED
  if (options->debug) {
    gmsh::initialize();
    gmsh::option::setNumber("View.Visible", 0);
    using namespace GLog;
    GeoLog log;
    F(c,M.tetrahedra.size()) {
      vec3 pt = points_center(points(M,M.tetrahedra[c]));
      log.addVector(pt, dir_u[c], "dir_u");
      log.addVector(pt, dir_v[c], "dir_v");
      log.addVector(pt, dir_w[c], "dir_w");

      vector<double> val4(4,gradientIndicator[c]);
      log.add(to_vector(points(M,M.tetrahedra[c])),val4,"smoothness",true);

      FC(lf,4,tfIsCut[4*c+lf]) {
        vector<double> values(3,0.);
        id3 vert = tet_face_vertices(M,c,lf);
        log.add(to_vector(points(M,vert)),values,"cut_graph");
      }
    }
    log.toGmsh();
  }
#endif


  vector<vec3> uvw3;
  bool okp = compute_uvw_integration(M, options, tfIsCut, ballId, dir_u, dir_v, dir_w, uvw3);
  if (!okp) HXT_ERROR_MSG(HXT_STATUS_ERROR, "failed to compute UVW from lifted directions");

#ifdef GMSH_LINKED
  using namespace GLog;
  F(k,3) {
    GeoLog log;
    F(c,M.tetrahedra.size()) {
      id4 vert = M.tetrahedra[c];
      vector<vec3> pts = to_vector(points(M,vert));
      vector<double> values(4);
      F(lv,4) values[lv] = uvw3[4*c+lv][k];
      log.add(pts,values,"param_"+std::to_string(k),true);
    }
    int tag = -1;
    log.toGmsh(&tag);
    gmsh::option::setNumber("View["+std::to_string(tag)+"].ShowScale", 1);
    gmsh::option::setNumber("View["+std::to_string(tag)+"].IntervalsType", 1);
    gmsh::option::setNumber("View["+std::to_string(tag)+"].Visible", 1);

  }
  gmsh::fltk::run();
#endif

  F(k,3) {
    F(c,M.tetrahedra.size()) {
      F(lv,4) {
        uvw[k*4*M.tetrahedra.size()+4*c+lv] = uvw3[4*c+lv][k];
      }
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus get_lifting(
    HXTMesh* mesh,
    const double* directionsScaled,
    const double* gradientIndicator,
    const HxtUVWParamOptions* options,
    double* liftU,
    double* liftV,
    double* liftW
    ) {
  info("create lifting ...");
  if (mesh->tetrahedra.neigh == NULL) {
    HXT_CHECK(hxtTetAdjacencies(mesh));
  }

  SMesh M;
  bool okm = mesh_from_hxt(mesh,M);
  if (!okm) HXT_ERROR_MSG(HXT_STATUS_ERROR, "failed to build SMesh from HXTMesh");

  /* Verify all frame directions are non-zero */
  {
    constexpr double EPS0 = 1.e-12;
    double dmin =  DBL_MAX;
    double dmax = -DBL_MAX;
    F(c,M.tetrahedra.size()) F(j,3) {
      vec3 dir = frame_branch(directionsScaled, c, j);
      double len = length(dir);
      if (len < EPS0) {
        error("tet {}, {}-th direction is ~0: {}", c, j, length(dir));
        error("Not supported, all cross branches must be non-zero.");
        return HXT_STATUS_ERROR;
      }
      dmin = std::min(dmin,len);
      dmax = std::max(dmax,len);
    }
    info("input direction norms: min={}, max={}",dmin,dmax);
  }

  if (options->ignore_scaling) {
    warn("ignore cross scaling (i.e. use unit vector fields)");
  }

  vector<bool> tfIsCut;
  vector<id> ballId;
  vector<vec3> dir_u;
  vector<vec3> dir_v;
  vector<vec3> dir_w;
  bool okcg = build_cut_graph_and_lifting(M, directionsScaled, gradientIndicator, tfIsCut, ballId, dir_u, dir_v, dir_w);
  if (!okcg) HXT_ERROR_MSG(HXT_STATUS_ERROR, "failed to build cut-graph");

  F(c,M.tetrahedra.size()){
    F(k,3){
      liftU[3*c+k]=dir_u[c][k];
      liftV[3*c+k]=dir_v[c][k];
      liftW[3*c+k]=dir_w[c][k];
    }
  }  
  return HXT_STATUS_OK;
}

HXTStatus savePerTetDirectionsAndSmoothness(
    const HXTMesh* mesh,
    const double* directionsScaled,
    const double* gradientIndicator,
    const char* path) {

  size_t n = mesh->tetrahedra.size;
  vector<double> data;
  data.reserve(10*n);
  F(i,n) {
    F(j,9) {
      data.push_back(directionsScaled[9*i+j]);
    }
    data.push_back(gradientIndicator[i]);
  }
  bool ok = save_vector(data,std::string(path));
  if (!ok) {
    HXT_ERROR_MSG(HXT_STATUS_ERROR,"save directions: failed to save at file %s", path);
  }

  return HXT_STATUS_OK;
}

/* Assume arrays are already allocated with the right size */
HXTStatus loadPerTetDirectionsAndSmoothness(
    const char* path,
    const HXTMesh* mesh,
    double* directionsScaled,
    double* gradientIndicator) {
  if (!file_exists(path)) {
    HXT_ERROR_MSG(HXT_STATUS_ERROR,"load directions: file %s not found", path);
  }
  size_t n = mesh->tetrahedra.size;
  vector<double> data;
  data.reserve(10*n);
  bool ok = load_vector(std::string(path),data);
  if (!ok) {
    HXT_ERROR_MSG(HXT_STATUS_ERROR,"load directions: failed to load directions from file at file %s", path);
  }
  if (data.size() != 10*n) {
    HXT_ERROR_MSG(HXT_STATUS_ERROR,"load directions: wrong size, n_tets = %li but data size = %li", n, data.size());
  }
  F(i,data.size()/10) {
    F(j,9) {
      directionsScaled[9*i+j] = data[10*i+j];
    }
    gradientIndicator[i] = data[10*i+9];
  }

  return HXT_STATUS_OK;
}
