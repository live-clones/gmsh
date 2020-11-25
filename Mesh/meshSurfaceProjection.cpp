// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol


#include "meshSurfaceProjection.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "nanoflann.hpp"
#include <unordered_map>
#include <unordered_set>
#include <queue>

/* for visualization */
#include "gmsh.h"
#include "geolog.h"

namespace SurfaceProjectorUtils {
  using vec2 = std::array<double,2>;
  using vec3 = std::array<double,3>;
  const size_t NO_ID = (size_t) -1;

  inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
  inline double length2  (const vec3& a) { return dot(a,a); }
  inline vec3 operator-(const vec3& a, const vec3& b) { return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
  inline vec3 operator+(const vec3& a, const vec3& b) { return {a[0]+b[0], a[1]+b[1], a[2]+b[2]}; }
  inline vec3 operator*(const double& a, const vec3& b) { return {a*b[0], a*b[1], a*b[2]}; }
  inline vec3 operator*(const vec3& a, const double& b) { return {a[0]*b, a[1]*b, a[2]*b}; }

  inline double project_point_segment_l2(const vec3& query, const vec3& a, const vec3& b, vec3& proj, double& lambda) {
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

  /* This function is adapted from a equivalent function in the Geogram library,
   * which is based on https://www.geometrictools.com/Source/Distance3D.html */
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
}

using namespace SurfaceProjectorUtils;

namespace NanoflannWrapper {
  using namespace nanoflann;

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

  typedef KDTreeSingleIndexAdaptor<L2_Simple_Adaptor<double, PointCloudAdaptor<PointCloud> >,
          PointCloudAdaptor<PointCloud>, 3> static_kd_tree_t;
}

using namespace NanoflannWrapper;

SurfaceProjector::SurfaceProjector(GFace* gf_):gf(NULL),tree(NULL),pc(NULL),pca(NULL) {
  bool ok = initialize(gf_);
  if (!ok) {
    Msg::Error("failed to initialize SurfaceProjector");
  }
}

SurfaceProjector::~SurfaceProjector() {
  if (tree != NULL) {
    delete (static_kd_tree_t*) tree;
    tree = NULL;
  }
  if (pc != NULL) {
    delete (PointCloud*) pc;
    pc = NULL;
  }
  if (pca != NULL) {
    delete (PointCloudAdaptor<PointCloud>*) pca;
    pca = NULL;
  }
}

bool SurfaceProjector::initialize(GFace* gf_) {
  gf = gf_;
  if (tree != NULL) {
    delete (static_kd_tree_t*) tree;
    tree = NULL;
  }
  if (pc != NULL) {
    delete (PointCloud*) pc;
    pc = NULL;
  }
  if (pca != NULL) {
    delete (PointCloudAdaptor<PointCloud>*) pca;
    pca = NULL;
  }
  if (gf->triangles.size() == 0)  {
    Msg::Error("SurfaceProjector cannot be initialized for face %i: no triangles", gf->tag());
    return false;
  }

  /* Build the triangles, the 3D point to triangles mapping
   * the triangle uv if available (not discrete face) */
  bool paramAvailable = true;
  discreteFace* df = dynamic_cast<discreteFace*>(gf);
  if (df && !df->haveParametrization()) paramAvailable = false;

  size_t vCount = 0;
  std::unordered_map<MVertex*,size_t> old2new;
  for (MVertex* v: gf->mesh_vertices) {
    old2new[v] = vCount;
    vCount += 1;
  }
  idx2t.resize(vCount);

  /* If periodic parametrization, get periods */
  double Ts[2] = {0.,0.};
  if (gf->periodic(0)) Ts[0] = gf->period(0);
  if (gf->periodic(1)) Ts[1] = gf->period(1);

  triangles.reserve(gf->triangles.size());
  triangles_idx.reserve(gf->triangles.size());
  if (df) uvs.reserve(gf->triangles.size());
  for (MTriangle* f: gf->triangles) {
    std::array<vec3,3> tri_pts;
    std::array<vec2,3> tri_uvs;
    std::array<size_t,3> tri_idx;
    bool check_periodicity = false;
    for (size_t lv = 0; lv < f->getNumVertices(); ++lv) {
      MVertex* v = f->getVertex(lv);
      tri_pts[lv] = {v->x(),v->y(),v->z()};

      if (paramAvailable) { /* Get the uv in GFace */
        bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
        if (onGf) {
          v->getParameter(0,tri_uvs[lv][0]);
          v->getParameter(1,tri_uvs[lv][1]);
        } else {
          GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
          if (ge != NULL) {
            double t;
            v->getParameter(0,t);
            SPoint2 uv = ge->reparamOnFace(gf, t, -1);
            tri_uvs[lv] = {uv.x(),uv.y()};
            if (ge->isSeam(gf)) { /* multiple uv param are possible, see later*/
              check_periodicity = true;
            } 
          } else {
            check_periodicity = true;
            GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
            if (gv != NULL) {
              SPoint2 uv = gv->reparamOnFace(gf,0);
              tri_uvs[lv] = {uv.x(),uv.y()};
            } else {
              Msg::Error("vertex not on GEntity ?");
            }
          }
        }

        /* Check periodicity jumps */
        if (check_periodicity && lv > 0) {
          for (size_t d = 0; d < 2; ++d) {
            if (Ts[d] != 0.) {
              double diff = std::abs(tri_uvs[lv][d] - tri_uvs[lv-1][d]);
              if (diff > 0.5 * Ts[d]) { /* Probably got a period jump ! */
                double diffP = std::abs(tri_uvs[lv][d] + Ts[d] - tri_uvs[lv-1][d]);
                double diffN = std::abs(tri_uvs[lv][d] - Ts[d] - tri_uvs[lv-1][d]);
                if (diffP < diff) {
                  tri_uvs[lv][d] += Ts[d];
                } else if (diffN < diff) {
                  tri_uvs[lv][d] -= Ts[d];
                }
              }
            }
          }
        }
      }

      auto it = old2new.find(v);
      if (it == old2new.end()) {
        old2new[v] = vCount;
        tri_idx[lv] = vCount;
        idx2t.resize(vCount+1);
        idx2t[vCount].push_back(triangles.size());
        vCount += 1;
      } else {
        tri_idx[lv] = it->second;
        idx2t[it->second].push_back(triangles.size());
      }
    }

    // if (false && paramAvailable && check_periodicity) {
    //   bool shift = true;
    //   GEdge* ge = NULL;
    //   for (size_t lv = 0; lv < 3; ++lv) {
    //     if (gep[lv] != NULL && ge == NULL) {
    //       ge = gep[lv];
    //     }
    //     if (gep[lv] != NULL && ge != NULL && gep[lv] != ge) {
    //       shift = false;
    //     }
    //   }
    //   if (ge == NULL || shift) {
    //     tri_uvs[1] = tri_uvs[0];
    //     tri_uvs[2] = tri_uvs[0];
    //   } else {
    //     for (size_t d = 0; d < 2; ++d) {
    //       if (gf->periodic(d)) {
    //         /* Check if +-T is closer */
    //         double T = gf->period(d);
    //         double d01 = std::abs(tri_uvs[0][d]-tri_uvs[1][d]);
    //         double d12 = std::abs(tri_uvs[1][d]-tri_uvs[2][d]);
    //         double d02 = std::abs(tri_uvs[0][d]-tri_uvs[2][d]);
    //         if        (d01 <= d12 && d01 <= d02) {
    //           double mid = 0.5  * (tri_uvs[0][d]+tri_uvs[1][d]);
    //           if (std::abs((tri_uvs[2][d]-T)-mid) < std::abs(tri_uvs[2][d]-mid)) {
    //             tri_uvs[2][d] -= T;
    //           } else if (std::abs((tri_uvs[2][d]+T)-mid) < std::abs(tri_uvs[2][d]-mid)) {
    //             tri_uvs[2][d] += T;
    //           }
    //         } else if (d12 <= d01 && d12 <= d02) {
    //           double mid = 0.5  * (tri_uvs[1][d]+tri_uvs[2][d]);
    //           if (std::abs((tri_uvs[0][d]-T)-mid) < std::abs(tri_uvs[0][d]-mid)) {
    //             tri_uvs[0][d] -= T;
    //           } else if (std::abs((tri_uvs[0][d]+T)-mid) < std::abs(tri_uvs[0][d]-mid)) {
    //             tri_uvs[0][d] += T;
    //           }
    //         } else if (d02 <= d01 && d02 <= d12) {
    //           double mid = 0.5  * (tri_uvs[0][d]+tri_uvs[2][d]);
    //           if (std::abs((tri_uvs[1][d]-T)-mid) < std::abs(tri_uvs[1][d]-mid)) {
    //             tri_uvs[1][d] -= T;
    //           } else if (std::abs((tri_uvs[1][d]+T)-mid) < std::abs(tri_uvs[1][d]-mid)) {
    //             tri_uvs[1][d] += T;
    //           }
    //         }
    //       }
    //     }
    //   }
    // }

    triangles.push_back(tri_pts);
    triangles_idx.push_back(tri_idx);
    if (paramAvailable) uvs.push_back(tri_uvs);
  }

  /* Collect the points */
  std::vector<vec3> pts(vCount);
  for (auto& kv: old2new) {
    SPoint3 pt = kv.first->point();
    pts[kv.second] = {pt.x(),pt.y(),pt.z()};
  }

  /* Build the kdtree */
  PointCloud* _pc = new PointCloud(pts);
  PointCloudAdaptor<PointCloud>* _pca = new PointCloudAdaptor<PointCloud>(*_pc);
  static_kd_tree_t* _tree = new static_kd_tree_t(3, *_pca, KDTreeSingleIndexAdaptorParams(10));
  _tree->buildIndex();
  tree = (void*) _tree;
  pc = (void*) _pc;
  pca = (void*) _pca;

  return true;
}

GPoint SurfaceProjector::closestPoint(const double query_ptr[3], size_t& cache, bool evalOnCAD, bool projectOnCAD) const {
  if (tree == NULL) {
    Msg::Error("closestPoint in SurfaceProjector: no kdtree");
    GPoint fail(DBL_MAX,DBL_MAX,DBL_MAX,NULL);
    fail.setNoSuccess();
    return fail;
  }

  vec3 query = {query_ptr[0],query_ptr[1],query_ptr[2]};
  std::unordered_set<size_t> done;

  /* Try the triangle whose index is given via cache */
  if (cache < triangles.size()) {
    vec3 p1 = triangles[cache][0];
    vec3 p2 = triangles[cache][1];
    vec3 p3 = triangles[cache][2];
    double lambda[3];
    vec3 cproj;
    project_point_triangle_l2(query, p1, p2, p3, cproj, lambda);
    /* strict inequality because lambda is clamped [0.,1.] in project_point_triangle_l2 */
    if (lambda[0] > 0. && lambda[1] > 0. && lambda[2] > 0.
        && lambda[0] < 1. && lambda[1] < 1. && lambda[2] < 1.) {
      if (uvs.size() > 0) {
        double u = lambda[0] * uvs[cache][0][0] + lambda[1] * uvs[cache][1][0] + lambda[2] * uvs[cache][2][0];
        double v = lambda[0] * uvs[cache][0][1] + lambda[1] * uvs[cache][1][1] + lambda[2] * uvs[cache][2][1];
        GPoint proj(cproj[0],cproj[1],cproj[2],gf,u,v);
        if (projectOnCAD) {
          /* Use the discrete projection + uv interpolation
           * as initial guess for CAD closest point query */
          double initialGuess[2] = {proj.u(),proj.v()};
          SPoint3 query(proj.x(),proj.y(),proj.z());
          GPoint cadProj = gf->closestPoint(query,initialGuess);
          if (cadProj.succeeded()) {
            proj = cadProj;
          }
        } else if (evalOnCAD) {
          proj = gf->point(u,v);
        }
        return proj;
      } else {
        GPoint proj(cproj[0],cproj[1],cproj[2],gf);
        return proj;
      }
    }
    done.insert(cache);
  }

  /* kdtree search (closest vertex) then loop on adjacent elements */
  static_kd_tree_t* ttree = (static_kd_tree_t*) tree;
  size_t N_search = 3;
  std::vector<size_t> ids(N_search);
  std::vector<double> dists(N_search);
  size_t Nf = ttree->knnSearch(query.data(), N_search, &ids[0], &dists[0]);
  if (Nf == 0) {
    Msg::Error("closestPoint in SurfaceProjector: no closest point in the kdtree (%li points) for query (%f,%f,%f)",
        ttree->size(), query[0],query[1],query[2]);
    GPoint fail(DBL_MAX,DBL_MAX,DBL_MAX,NULL);
    fail.setNoSuccess();
    return fail;
  }

  size_t N_TRIANGLE_MAX = 30;
  std::queue<size_t> Q;
  std::unordered_set<size_t> visited;
  for (size_t v: ids) {
    Q.push(v);
  }
  double d2min_in  = DBL_MAX;
  double d2min_out = DBL_MAX;
  size_t elem = NO_ID;
  GPoint proj;
  while (Q.size() > 0) {
    if (done.size() > N_TRIANGLE_MAX) {
      break;
    }

    size_t v = Q.front();
    Q.pop();
    for (size_t f: idx2t[v]) {
      if (done.find(f) != done.end()) continue;

      /* Try the triangle */
      vec3 p1 = triangles[f][0];
      vec3 p2 = triangles[f][1];
      vec3 p3 = triangles[f][2];
      double lambda[3];
      vec3 cproj;
      double d2 = project_point_triangle_l2(query, p1, p2, p3, cproj, lambda);
      /* strict inequality because lambda is clamped [0.,1.] in project_point_triangle_l2 */
      double u = lambda[0] * uvs[f][0][0] + lambda[1] * uvs[f][1][0] + lambda[2] * uvs[f][2][0];
      double v = lambda[0] * uvs[f][0][1] + lambda[1] * uvs[f][1][1] + lambda[2] * uvs[f][2][1];
      bool inside = (lambda[0] > 0. && lambda[1] > 0. && lambda[2] > 0. 
          && lambda[0] < 1. && lambda[1] < 1. && lambda[2] < 1.);
      if (inside && d2 < d2min_in) {
        if (uvs.size() > 0) {
          proj = GPoint(cproj[0],cproj[1],cproj[2],gf,u,v);
        } else {
          proj = GPoint(cproj[0],cproj[1],cproj[2],gf);
        }
        d2min_in = d2;
        elem = f;
      } else if (!inside && d2min_in == DBL_MAX && d2 < d2min_out) {
        if (uvs.size() > 0) {
          proj = GPoint(cproj[0],cproj[1],cproj[2],gf,u,v);
        } else {
          proj = GPoint(cproj[0],cproj[1],cproj[2],gf);
        }
        d2min_out = d2;
        elem = f;
      }

      done.insert(f);

      /* Add triangle vertices to the queue */
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t idx = triangles_idx[f][lv];
        if (visited.find(idx) != visited.end()) continue;
        Q.push(idx);
      }
    }
    
    visited.insert(v);

    if (d2min_in != DBL_MAX) {
      cache = elem;
      if (uvs.size() > 0 && projectOnCAD) {
        /* Use the discrete projection + uv interpolation
         * as initial guess for CAD closest point query */
        double initialGuess[2] = {proj.u(),proj.v()};
        SPoint3 query(proj.x(),proj.y(),proj.z());
        GPoint cadProj = gf->closestPoint(query,initialGuess);
        if (cadProj.succeeded()) {
          proj = cadProj;
        }
      } else if (uvs.size() > 0 && evalOnCAD) {
        proj = gf->point(proj.u(),proj.v());
      }
      return proj;
    }
  }

  if (d2min_in != DBL_MAX || d2min_out != DBL_MAX) {
    cache = elem;
    if (uvs.size() > 0 && projectOnCAD) {
      /* Use the discrete projection + uv interpolation
       * as initial guess for CAD closest point query */
      double initialGuess[2] = {proj.u(),proj.v()};
      SPoint3 query(proj.x(),proj.y(),proj.z());
      GPoint cadProj = gf->closestPoint(query,initialGuess);
      if (cadProj.succeeded()) {
        proj = cadProj;
      }
    } else if (uvs.size() > 0 && evalOnCAD) {
      proj = gf->point(proj.u(),proj.v());
    }
    return proj;
  }

  Msg::Debug("closestPoint in SurfaceProjector (face %i): did not find a projection on a triangle (%li tried)",
      gf->tag(),
      done.size());
  GPoint fail(DBL_MAX,DBL_MAX,DBL_MAX,NULL);
  fail.setNoSuccess();
  return fail;
}

void SurfaceProjector::show(const std::string& viewName) {
  gmsh::initialize();
  for (size_t i = 0; i < triangles.size(); ++i) {
    std::vector<std::array<double,3> > pts = {
      triangles[i][0],
      triangles[i][1],
      triangles[i][2]
    };
    std::vector<double> values_u = { uvs[i][0][0], uvs[i][1][0], uvs[i][2][0]};
    std::vector<double> values_v = { uvs[i][0][1], uvs[i][1][1], uvs[i][2][1]};
    GeoLog::add(pts,values_u,viewName+"_u");
    GeoLog::add(pts,values_v,viewName+"_v");
  }
  GeoLog::flush();
}
