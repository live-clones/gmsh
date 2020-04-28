// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmt_projection.h"
#include <cfloat>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unordered_set>

#include "nanoflann.hpp"
#include "gmsh.h"
#include "qmt_utils.hpp"
#include "geolog.h"

/* - Shortcuts for loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)

using std::vector;
using std::map;
using std::array;
using std::pair;

namespace QMT_PROJ_Utils {
  using namespace QMT_Utils;
  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Projection | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Projection | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Projection | " + stream.str(), "info");
    }

  template <typename... Args>
    void trace(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Projection | " + stream.str(), "debug");
    }
  /************************************/
}

namespace QMT {
  using namespace QMT_PROJ_Utils;
  using namespace nanoflann;

  /* from geogram */
  double project_point_segment_l2(const vec3& query, const vec3& a, const vec3& b, vec3& proj, double& lambda) {
    double l2 = length2(a-b);
    double t = dot(query-a,b-a);
    if (t <= 0. || l2 == 0.) {
      proj = a;
      lambda = 1.;
      return length2(query-a);
    } else if (t > l2) {
      proj = b;
      lambda = 0.;
      return length2(query-b);
    }
    lambda = 1. - t / l2;
    proj = lambda * a + (1. - lambda) * b;
    return length2(query-proj);
  }

  /* from geogram, which links to http://www.geometrictools.com/LibMathematics/Distance/Distance.html */
  inline double project_point_triangle_l2(
      const vec3& query,
      const vec3& p1,
      const vec3& p2,
      const vec3& p3,
      vec3& proj,
      double lambda[3]) {
    vec3 diff = p1 - query;
    vec3 edge0 = p2 - p1;
    vec3 edge1 = p3 - p1;
    double a00 = length2(edge0);
    double a01 = dot(edge0, edge1);
    double a11 = length2(edge1);
    double b0 = dot(diff, edge0);
    double b1 = dot(diff, edge1);
    double c = length2(diff);
    double det = ::fabs(a00 * a11 - a01 * a01);
    double s = a01 * b1 - a11 * b0;
    double t = a01 * b0 - a00 * b1;
    double sqrDistance;

    // If the triangle is degenerate
    if(det < 1e-30) {
      double cur_l1;
      vec3 cur_closest;
      double result;
      double cur_dist = project_point_segment_l2(query, p1, p2, cur_closest, cur_l1);
      result = cur_dist;
      proj = cur_closest;
      lambda[0] = cur_l1;
      lambda[1] = 1.-cur_l1;
      lambda[2] = 0.0;
      cur_dist = project_point_segment_l2(query, p1, p3, cur_closest, cur_l1);
      if(cur_dist < result) {
        result = cur_dist;
        proj = cur_closest;
        lambda[0] = cur_l1;
        lambda[2] = 1.-cur_l1;
        lambda[1] = 0.0;
      }
      cur_dist = project_point_segment_l2(query, p2, p3, cur_closest, cur_l1);
      if(cur_dist < result) {
        result = cur_dist;
        proj = cur_closest;
        lambda[1] = cur_l1;
        lambda[2] = 1.-cur_l1;
        lambda[0] = 0.0;
      }
      return result;
    }

    if(s + t <= det) {
      if(s < 0.0) {
        if(t < 0.0) {   // region 4
          if(b0 < 0.0) {
            t = 0.0;
            if(-b0 >= a00) {
              s = 1.0;
              sqrDistance = a00 + 2.0 * b0 + c;
            } else {
              s = -b0 / a00;
              sqrDistance = b0 * s + c;
            }
          } else {
            s = 0.0;
            if(b1 >= 0.0) {
              t = 0.0;
              sqrDistance = c;
            } else if(-b1 >= a11) {
              t = 1.0;
              sqrDistance = a11 + 2.0 * b1 + c;
            } else {
              t = -b1 / a11;
              sqrDistance = b1 * t + c;
            }
          }
        } else {  // region 3
          s = 0.0;
          if(b1 >= 0.0) {
            t = 0.0;
            sqrDistance = c;
          } else if(-b1 >= a11) {
            t = 1.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          } else {
            t = -b1 / a11;
            sqrDistance = b1 * t + c;
          }
        }
      } else if(t < 0.0) {  // region 5
        t = 0.0;
        if(b0 >= 0.0) {
          s = 0.0;
          sqrDistance = c;
        } else if(-b0 >= a00) {
          s = 1.0;
          sqrDistance = a00 + 2.0 * b0 + c;
        } else {
          s = -b0 / a00;
          sqrDistance = b0 * s + c;
        }
      } else {  // region 0
        // minimum at interior query
        double invDet = double(1.0) / det;
        s *= invDet;
        t *= invDet;
        sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
          t * (a01 * s + a11 * t + 2.0 * b1) + c;
      }
    } else {
      double tmp0, tmp1, numer, denom;

      if(s < 0.0) {   // region 2
        tmp0 = a01 + b0;
        tmp1 = a11 + b1;
        if(tmp1 > tmp0) {
          numer = tmp1 - tmp0;
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            s = 1.0;
            t = 0.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          } else {
            s = numer / denom;
            t = 1.0 - s;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
              t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        } else {
          s = 0.0;
          if(tmp1 <= 0.0) {
            t = 1.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          }
          else if(b1 >= 0.0) {
            t = 0.0;
            sqrDistance = c;
          } else {
            t = -b1 / a11;
            sqrDistance = b1 * t + c;
          }
        }
      } else if(t < 0.0) {  // region 6
        tmp0 = a01 + b1;
        tmp1 = a00 + b0;
        if(tmp1 > tmp0) {
          numer = tmp1 - tmp0;
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            t = 1.0;
            s = 0.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          } else {
            t = numer / denom;
            s = 1.0 - t;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
              t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        } else {
          t = 0.0;
          if(tmp1 <= 0.0) {
            s = 1.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          } else if(b0 >= 0.0) {
            s = 0.0;
            sqrDistance = c;
          } else {
            s = -b0 / a00;
            sqrDistance = b0 * s + c;
          }
        }
      } else { // region 1
        numer = a11 + b1 - a01 - b0;
        if(numer <= 0.0) {
          s = 0.0;
          t = 1.0;
          sqrDistance = a11 + 2.0 * b1 + c;
        } else {
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            s = 1.0;
            t = 0.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          } else {
            s = numer / denom;
            t = 1.0 - s;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
              t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        }
      }
    }

    // Account for numerical round-off error.
    if(sqrDistance < 0.0) {
      sqrDistance = 0.0;
    }

    proj = p1 + s * edge0 + t * edge1;
    lambda[0] = 1.0 - s - t;
    lambda[1] = s;
    lambda[2] = t;
    return sqrDistance;
  }




  struct PointCloud {
    PointCloud(const std::vector<vec3>& pts_):pts(pts_){}
    const std::vector<vec3> pts;
  };

  template <typename Derived> 
  struct PointCloudAdaptor {
    const Derived& obj;
    PointCloudAdaptor(const Derived& obj_) : obj(obj_) {};
    inline size_t kdtree_get_point_count() const { return obj.pts.size(); }
    inline double kdtree_get_pt(const size_t idx, const size_t dim) const {
      if (dim == 0) return obj.pts[idx][0];
      else if (dim == 1) return obj.pts[idx][1];
      else return obj.pts[idx][2];
    }

    inline double kdtree_distance(const double *p1, const size_t idx_p2,
        size_t /*size*/) const
    {
      const double d0 = p1[0] - obj.pts[idx_p2][0];
      const double d1 = p1[1] - obj.pts[idx_p2][1];
      const double d2 = p1[2] - obj.pts[idx_p2][2];
      return d0 * d0 + d1 * d1 + d2 * d2;
    }

    template <class BBOX>
      bool kdtree_get_bbox(BBOX& bb) const { 
        return false; 
      }

  };

  /* static kdtree */
  typedef KDTreeSingleIndexAdaptor<L2_Simple_Adaptor<double, PointCloudAdaptor<PointCloud>>,
          PointCloudAdaptor<PointCloud>, 3> static_kd_tree_t;

  BoundaryProjector::BoundaryProjector(const TMesh& mesh) : M(mesh) {
    trace("BoundaryProjector constructor call");
    size_t nn = 0;
    size_t nc = 0;
    size_t ns = 0;

    { /* Save nodes */
      FC(v,M.points.size(),M.pt_color[v] > 0) {
        id nodeTag = M.pt_color[v];
        if (nodeTag >= nodes.size()) {
          nodes.resize(nodeTag+1,vec3{DBL_MAX,DBL_MAX,DBL_MAX});
        }
        nodes[nodeTag] = M.points[v];
        nn += 1;
      }
    }

    /* Build edge kd-trees */
    {
      trace("building curve kdtrees");
      vector<vector<id>> v2e(M.points.size());
      vector<vector<id>> curve_o2n;
      vector<vector<vec3>> curve_pts;
      vector<id> curve_count;
      F(e,M.lines.size()) {
        id tag = M.line_colors[e];
        if (tag >= curve_o2n.size()) {
          curve_o2n.resize(tag+1);
          curve_o2n[tag].resize(M.points.size(),NO_ID);
          curve_count.resize(tag+1,0);
          curve_pts.resize(tag+1);
        }
        F(lv,2) {
          id v = M.lines[e][lv];
          v2e[v].push_back(e);
          if (curve_o2n[tag][v] == NO_ID) {
            curve_o2n[tag][v] = curve_count[tag];
            curve_pts[tag].push_back(M.points[v]);
            curve_count[tag] += 1;
          }
        }
      }
      curve_tree.resize(curve_pts.size(),NULL);
      cTreeIdToEdges.resize(curve_pts.size());
      FC(tag, curve_pts.size(), curve_pts[tag].size() > 0) {
        PointCloud* pc = new PointCloud(curve_pts[tag]);
        pcs.push_back((void*)pc);
        PointCloudAdaptor<PointCloud>* pca = new PointCloudAdaptor<PointCloud>(*pc);
        pcas.push_back((void*)pca);
        static_kd_tree_t* tree = new static_kd_tree_t(3, *pca, KDTreeSingleIndexAdaptorParams(10));
        tree->buildIndex();
        nc += 1;
        curve_tree[tag] = (void*) tree;
        cTreeIdToEdges[tag].resize(curve_count[tag]);
        FC(v,curve_o2n[tag].size(),curve_o2n[tag][v] != NO_ID) {
          vector<id> edges;
          FC(le,v2e[v].size(),M.line_colors[v2e[v][le]] == tag) edges.push_back(v2e[v][le]);
          cTreeIdToEdges[tag][curve_o2n[tag][v]] = edges;
        }
      }
    }

    /* Build surface kd-trees */
    {
      trace("building surface kdtrees");
      vector<vector<id>> v2f(M.points.size());
      vector<vector<id>> surf_o2n;
      vector<vector<vec3>> surf_pts;
      vector<id> surf_count;
      F(f,M.triangles.size()) {
        id tag = M.tri_colors[f];
        if (tag >= surf_o2n.size()) {
          surf_o2n.resize(tag+1);
          surf_o2n[tag].resize(M.points.size(),NO_ID);
          surf_count.resize(tag+1,0);
          surf_pts.resize(tag+1);
        }
        F(lv,3) {
          id v = M.triangles[f][lv];
          v2f[v].push_back(f);
          if (surf_o2n[tag][v] == NO_ID) {
            surf_o2n[tag][v] = surf_count[tag];
            surf_pts[tag].push_back(M.points[v]);
            surf_count[tag] += 1;
          }
        }
      }
      surface_tree.resize(surf_pts.size(),NULL);
      sTreeIdToTris.resize(surf_pts.size());
      FC(tag, surf_pts.size(), surf_pts[tag].size() > 0) {
        PointCloud* pc = new PointCloud(surf_pts[tag]);
        pcs.push_back((void*)pc);
        PointCloudAdaptor<PointCloud>* pca = new PointCloudAdaptor<PointCloud>(*pc);
        pcas.push_back((void*)pca);
        static_kd_tree_t* tree = new static_kd_tree_t(3, *pca, KDTreeSingleIndexAdaptorParams(10));
        tree->buildIndex();
        ns += 1;
        surface_tree[tag] = (void*) tree;
        sTreeIdToTris[tag].resize(surf_count[tag]);
        FC(v,surf_o2n[tag].size(),surf_o2n[tag][v] != NO_ID) {
          vector<id> tris;
          FC(lf,v2f[v].size(),M.tri_colors[v2f[v][lf]] == tag) tris.push_back(v2f[v][lf]);
          sTreeIdToTris[tag][surf_o2n[tag][v]] = tris;
        }
      }
    }
    info("BoundaryProjector built, contains: {} nodes, {} curve kdtrees and {} surface kdtrees", nn, nc, ns);
  }

  BoundaryProjector::~BoundaryProjector() {
    FC(i,curve_tree.size(),curve_tree[i] != NULL) {
      delete (static_kd_tree_t*) curve_tree[i];
      curve_tree[i] = NULL;
    }
    FC(i,surface_tree.size(),surface_tree[i] != NULL) {
      delete (static_kd_tree_t*) surface_tree[i];
      surface_tree[i] = NULL;
    }
    FC(i, pcs.size(), pcs[i] != NULL){
      delete (PointCloud*) pcs[i];
      pcs[i] = NULL;
    }
    FC(i, pcas.size(), pcas[i] != NULL){
      delete (PointCloudAdaptor<PointCloud>*) pcas[i];
      pcas[i] = NULL;
    }
  }

  bool BoundaryProjector::projectionOnEntityAvailable(int dim, int tag) const {
    if (tag < 0 || dim < 0 || dim > 2) return false;
    if (dim == 0 && tag >= nodes.size()) {
      return false;
    } else if (dim == 1 && tag >= curve_tree.size()) {
      return false;
    } else if (dim == 2 && tag >= surface_tree.size()) {
      return false;
    } else if (dim == 1 && curve_tree[tag] == NULL) {
      return false;
    } else if (dim == 2 && surface_tree[tag] == NULL) {
      return false;
    }
    return true;
  }

  bool BoundaryProjector::project(int dim, int tag, vec3 query, vec3& projection) const {
    id cache = NO_ID;
    return project(dim,tag,query,projection,cache);
  }

  bool BoundaryProjector::project(int dim, int tag, vec3 query, vec3& projection, id& cache) const {
    projection = {DBL_MAX,DBL_MAX,DBL_MAX};
    static_kd_tree_t* tree = NULL;
    if (!projectionOnEntityAvailable(dim,tag)) {
      error("no kdtree available for entity ({},{})", dim, tag);
      return false;
    }
    if (dim == 0) {
      projection = nodes[tag];
      return true;
    } else if (dim == 1) {
      tree = (static_kd_tree_t*) curve_tree[tag];
    } else if (dim == 2) {
      tree = (static_kd_tree_t*) surface_tree[tag];
    } else {
      return false;
    }

    std::unordered_set<size_t> done;

    /* try the cached element */
    if (cache != NO_ID) {
      if (dim == 1 && cache < M.lines.size()) {
        vec3 p1 = M.points[M.lines[cache][0]];
        vec3 p2 = M.points[M.lines[cache][1]];
        double lambda;
        vec3 cproj;
        /* strict inequality because lambda is clamped [0.,1.] in project_point_segment_l2 */
        double d2 = project_point_segment_l2(query, p1, p2, cproj, lambda);
        if (lambda > 0. && lambda < 1.) {
          projection = cproj;
          return true;
        }
        done.insert(cache);
      } else if (dim == 2 && cache < M.triangles.size()) {
        vec3 p1 = M.points[M.triangles[cache][0]];
        vec3 p2 = M.points[M.triangles[cache][1]];
        vec3 p3 = M.points[M.triangles[cache][2]];
        double lambda[3];
        vec3 cproj;
        double d2 = project_point_triangle_l2(query, p1, p2, p3, cproj, lambda);
        /* strict inequality because lambda is clamped [0.,1.] in project_point_triangle_l2 */
        if (lambda[0] > 0. && lambda[1] > 0. && lambda[2] > 0.
            && lambda[0] < 1. && lambda[1] < 1. && lambda[2] < 1.) {
          projection = cproj;
          return true;
        }
        done.insert(cache);
      }
    }


    /* kdtree search (closest vertex) then loop on adjacent elements */
    std::vector<size_t> ids(N_search);
    std::vector<double> dists(N_search);
    size_t Nf = tree->knnSearch(query.data(), N_search, &ids[0], &dists[0]);
    if (Nf == 0) return false;

    double d2min = DBL_MAX;
    id elem = NO_ID;
    F(i,Nf) {
      size_t cur = ids[i];
      if (dim == 1) {
        F(le,cTreeIdToEdges[tag][cur].size()) {
          size_t e = cTreeIdToEdges[tag][cur][le];
          if (done.find(e) != done.end()) continue;
          vec3 p1 = M.points[M.lines[e][0]];
          vec3 p2 = M.points[M.lines[e][1]];
          double lambda;
          vec3 cproj;
          double d2 = project_point_segment_l2(query, p1, p2, cproj, lambda);
          if (d2 < d2min) {
            elem = e;
            d2min = d2;
            projection = cproj;
          }
          done.insert(e);
        }
      } else if (dim == 2) {
        F(lf,sTreeIdToTris[tag][cur].size()) {
          size_t f = sTreeIdToTris[tag][cur][lf];
          if (done.find(f) != done.end()) continue;
          vec3 p1 = M.points[M.triangles[f][0]];
          vec3 p2 = M.points[M.triangles[f][1]];
          vec3 p3 = M.points[M.triangles[f][2]];
          double lambda[3];
          vec3 cproj;
          double d2 = project_point_triangle_l2(query, p1, p2, p3, cproj, lambda);
          if (d2 < d2min) {
            elem = f;
            d2min = d2;
            projection = cproj;
          }
          done.insert(f);
        }
      }
    }
    cache = elem;
    return true;
  }

  bool BoundaryProjector::closestEntity(const vec3& query, double& dist, int& dim, int& tag) const {
    constexpr double EPS = 1.e-12;
    dist = DBL_MAX;
    double d2min = DBL_MAX;
    int initDim = dim;
    tag = -1;
    dim = -1;


    /* Test nodes */
    F(i,nodes.size()) {
      vec3 proj;
      bool okp = project(0, i, query, proj);
      if (!okp || proj[0] == DBL_MAX) continue;
      double d2 = length2(query-proj);
      if (d2 < d2min) {
        d2min = d2;
        dim = 0;
        tag = i;
      }
    }
    if (dim == 0 && (initDim == 0 || d2min < EPS)) {
      dist = std::sqrt(d2min);
      return true;
    }

    /* Test curves */
    FC(i,curve_tree.size(),curve_tree[i] != NULL) {
      vec3 proj;
      bool okp = project(1, i, query, proj);
      if (!okp || proj[0] == DBL_MAX) continue;
      double d2 = length2(query-proj);
      if (d2 < d2min) {
        if (dim == 0 && d2 + EPS > d2min) continue; /* epsilon priority to nodes */
        d2min = d2;
        dim = 1;
        tag = i;
      }
    }
    if (dim == 1 && (initDim == 1 || d2min < EPS)) {
      dist = std::sqrt(d2min);
      return true;
    }

    /* Test surfaces */
    FC(i,surface_tree.size(),surface_tree[i] != NULL) {
      vec3 proj;
      bool okp = project(2, i, query, proj);
      if (!okp || proj[0] == DBL_MAX) continue;
      double d2 = length2(query-proj);
      if (d2 < d2min) {
        if (dim == 1 && d2 + 1.1 * EPS > d2min) continue; /* epsilon priority to curves */
        d2min = d2;
        dim = 2;
        tag = i;
      }
    }

    if (dim == -1) return false;
    dist = std::sqrt(d2min);

    return true;
  }

  bool BoundaryProjector::closestEntity(const std::vector<vec3>& queries, double& dist, int& dim, int& tag) const {
    constexpr double EPS = 1.e-12;
    dist = DBL_MAX;
    double mind2max = DBL_MAX;
    int initDim = dim;
    tag = -1;
    dim = -1;
    if (initDim != 2) {
      FC(i,curve_tree.size(),curve_tree[i] != NULL) {
        double d2max = 0.;
        const static_kd_tree_t* tree = (static_kd_tree_t*) curve_tree[i];
        F(j,queries.size()) {
          vec3 query = queries[j];
          vec3 proj;
          bool okp = project(1, i, query, proj);
          if (!okp || proj[0] == DBL_MAX) return false;
          double d2 = length2(query-proj);
          if (d2 > d2max) {
            d2max = d2;
          }
        }
        if (d2max < mind2max) {
          mind2max = d2max;
          dim = 1;
          tag = i;
        }
      }
    }
    if (initDim != 1) {
      FC(i,surface_tree.size(),surface_tree[i] != NULL) {
        double d2max = 0.;
        const static_kd_tree_t* tree = (static_kd_tree_t*) surface_tree[i];
        F(j,queries.size()) {
          vec3 query = queries[j];
          vec3 proj;
          bool okp = project(2, i, query, proj);
          if (!okp || proj[0] == DBL_MAX) return false;
          double d2 = length2(query-proj);
          if (d2 > d2max) {
            d2max = d2;
          }
        }
        if (d2max < mind2max) {
          if (dim == 1 && d2max + EPS > mind2max) continue; /* epsilon priority to curves */
          mind2max = d2max;
          dim = 2;
          tag = i;
        }
      }
    }
    if (dim == -1) return false;
    dist = std::sqrt(mind2max);
    return true;
  }

  using namespace GLog;
  void BoundaryProjector::show_projector(const std::string& viewPrefix) {
    GeoLog log;
    FC(i,curve_tree.size(),curve_tree[i] != NULL) {
      vector<id> edges;
      F(j,cTreeIdToEdges[i].size()) {
        F(k,cTreeIdToEdges[i][j].size()) {
          id e = cTreeIdToEdges[i][j][k];
          edges.push_back(e);
        }
      }
      sort_unique(edges);
      F(le,edges.size()) {
        id e = edges[le];
        vec3 p1 = M.points[M.lines[e][0]];
        vec3 p2 = M.points[M.lines[e][1]];
        log.add({p1,p2},double(i),viewPrefix+"_c"+std::to_string(i));
      }
    }
    FC(i,surface_tree.size(),surface_tree[i] != NULL) {
      vector<id> tris;
      F(j,sTreeIdToTris[i].size()) {
        F(k,sTreeIdToTris[i][j].size()) {
          id t = sTreeIdToTris[i][j][k];
          tris.push_back(t);
        }
      }
      sort_unique(tris);
      F(lt,tris.size()) {
        id t = tris[lt];
        vec3 p1 = M.points[M.triangles[t][0]];
        vec3 p2 = M.points[M.triangles[t][1]];
        vec3 p3 = M.points[M.triangles[t][2]];
        log.add({p1,p2,p3},double(i),viewPrefix+"_s"+std::to_string(i));
      }
    }

    log.toGmsh();
  }

  bool assignClosestEntities(QMesh& M, const BoundaryProjector& projector) {
    vector<bool> used(M.points.size(),false);
    F(f,M.quads.size()) 
      FC(lv,4,M.quads[f][lv] < M.points.size()) used[M.quads[f][lv]] = true;

    size_t nb[3] = {0,0,0};
    size_t nv = 0;
    FC(v,M.points.size(),used[v]) {
      int dim = -1;
      int tag = -1;
      double dist = DBL_MAX;
      bool okc = projector.closestEntity(M.points[v],dist,dim,tag);
      if (okc) {
        M.entity[v] = {dim,tag};
        nb[dim] += 1;
        nv += 1;
      } else {
        error("failed to assign closest entity to M.points[{}]={}",v,M.points[v]);
        return false;
      }
    }
    info("vertex to entity assignement: {} vertices -> {} to nodes, {} to curves and {} to surfaces",nv,nb[0],nb[1],nb[2]);
    F(f,M.quads.size()) {
      vec3 mid = 0.25 * (M.points[M.quads[f][0]] + M.points[M.quads[f][1]]
          + M.points[M.quads[f][2]] + M.points[M.quads[f][3]]);
      int dim = -1;
      int tag = -1;
      double dist = DBL_MAX;
      bool okc = projector.closestEntity(mid,dist,dim,tag);
      if (okc) {
        M.quadEntity[f] = tag;
      } else {
        error("failed to assign closest entity to quad {}",f);
        return false;
      }
    }
    info("{} quads assigned to surface entities", M.quads.size());
    return true;
  }

}
