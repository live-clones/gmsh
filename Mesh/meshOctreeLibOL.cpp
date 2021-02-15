// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol


#include "meshOctreeLibOL.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertex.h"
#include "MTriangle.h"

extern "C" {
#include "libol1.h"
}

#include "robin_hood.h"

// QuadMeshingTools headers
#include "arrayGeometry.h"

// Debug vizu
#include "geolog.h"

using namespace ArrayGeometry;

namespace SurfaceProjectorUtils {
  using vec2 = std::array<double,2>;

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

SurfaceProjector::SurfaceProjector(GFace* gf_):gf(NULL),OctIdx(0) {
  std::vector<MTriangle*> triangles = gf->triangles;
  if (gf->quadrangles.size() > 0) {
    Msg::Error("SurfaceProjector: quads not implemented yet, should create fake MTriangle* just for initialize()");
    abort();
  }
  bool ok = initialize(gf_, triangles);
  if (!ok) {
    Msg::Error("failed to initialize SurfaceProjector");
  }
}

void SurfaceProjector::clear() {
  if (OctIdx != 0) {
    Msg::Debug("free libOL octree (OctIdx: %li)",OctIdx);
    LolFreeOctree(OctIdx);
    OctIdx = 0;
  }
  points.clear();
  triangles.clear();
  triangle_uvs.clear();
}

SurfaceProjector::~SurfaceProjector() {
  clear();
}

bool SurfaceProjector::setAnalyticalProjection(GFace* gf) {
  if (gf->geomType() == GFace::GeomType::Sphere) {
    double radius = 0.;
    SPoint3 center;
    if (gf->isSphere(radius, center)) {
      analyticalShape = GFace::GeomType::Sphere;
      useAnalyticalFormula = true;
      analyticalParameters[0] = center.x();
      analyticalParameters[1] = center.y();
      analyticalParameters[2] = center.z();
      analyticalParameters[3] = radius;
      return true;
    }
  }

  Msg::Error("Surface projecor: analytical formula for given shape not supported");
  return false;
}

bool SurfaceProjector::initialize(GFace* gf_, const std::vector<MTriangle*>& gfTriangles) {
  clear();
  gf = gf_;
  bool paramAvailable = gf->haveParametrization();

  const int BasIdx = 1; /* indices start at one in libOL */

  /* If periodic parametrization, get periods */
  bool disableParamPoles = false;
  if (paramAvailable && (gf->periodic(0) || gf->periodic(1))) {
    disableParamPoles = true;
  }

  /* Collect coordinates and triangle-continuous uv param */
  robin_hood::unordered_map<MVertex*,int32_t> old2new;
  int32_t count = 0;
  triangles.reserve(gfTriangles.size());
  points.reserve(gfTriangles.size());
  if (paramAvailable) {
    triangle_uvs.reserve(gfTriangles.size());
    if (disableParamPoles) triangle_no_uv_eval.reserve(gfTriangles.size());
  }
  for (MTriangle* f: gfTriangles) {
    std::array<int32_t,3> tri_pts;
    std::array<vec2,3> tri_uvs;
    bool check_periodicity = false;
    bool no_eval = false;
    for (size_t lv = 0; lv < f->getNumVertices(); ++lv) {
      MVertex* v = f->getVertex(lv);
      auto it = old2new.find(v);
      if (it == old2new.end()) {
        old2new[v] = count;
        tri_pts[lv] = count + BasIdx;
        points.push_back(v->point());
        count += 1;
      } else {
        tri_pts[lv] = it->second + BasIdx;
      }

      if (paramAvailable) { /* Get the uv in GFace */
        bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
        if (onGf) {
          v->getParameter(0,tri_uvs[lv][0]);
          v->getParameter(1,tri_uvs[lv][1]);
        } else {
          check_periodicity = true;
        }
      }
    }

    if (check_periodicity) {
      for (size_t lv = 0; lv < 3; ++lv) {
        MVertex* v1 = f->getVertex(lv);
        bool onGf = (dynamic_cast<GFace*>(v1->onWhat()) == gf);
        if (onGf || lv == 2) { /* If neither of the 3 are on surface, takes random ... */
          MVertex* v2 = f->getVertex((lv+1)%3);
          MVertex* v3 = f->getVertex((lv+2)%3);
          SPoint2 param1;
          SPoint2 param2;
          SPoint2 param3;
          reparamMeshEdgeOnFace(v1, v2, gf, param1, param2);
          reparamMeshEdgeOnFace(v1, v3, gf, param1, param3);
          tri_uvs[(lv+0)%3] = {param1.x(),param1.y()};
          tri_uvs[(lv+1)%3] = {param2.x(),param2.y()};
          tri_uvs[(lv+2)%3] = {param3.x(),param3.y()};
          break;
        }
      }
    }

    triangles.push_back(tri_pts);
    if (paramAvailable) triangle_uvs.push_back(tri_uvs);
    if (paramAvailable && disableParamPoles) triangle_no_uv_eval.push_back(no_eval);
    // Debug to visualize param
    // {
    //   GeoLog::add({points[tri_pts[0]-1], points[tri_pts[1]-1], points[tri_pts[2]-1]},
    //       std::vector<double>{tri_uvs[0][0],tri_uvs[1][0],tri_uvs[2][0]}, "sp_u");
    //   GeoLog::add({points[tri_pts[0]-1], points[tri_pts[1]-1], points[tri_pts[2]-1]},
    //       std::vector<double>{tri_uvs[0][1],tri_uvs[1][1],tri_uvs[2][1]}, "sp_v");
    // }
  }

  points.shrink_to_fit();
  triangles.shrink_to_fit();
  triangle_uvs.shrink_to_fit();

  // Build an octree from a surface mesh
  int32_t NmbVer = (int32_t) points.size();
  double* VerTab1  = points[0].data();
  double* VerTab2  = points[1].data();
  // double* VerTab2  = VerTab1[3];
  int32_t NmbTri = (int32_t) triangles.size();
  int32_t* TriTab1  = triangles[0].data();
  //int32_t* TriTab2  = TriTab1[3];
  int32_t* TriTab2  = triangles[1].data();
  Msg::Debug("create libOL octree (%i vertices and %i triangles)", NmbVer, NmbTri);
  OctIdx = LolNewOctree(NmbVer, VerTab1, VerTab2,
      0, NULL, NULL,
      NmbTri, TriTab1, TriTab2,
      0, NULL, NULL,
      0, NULL, NULL,
      0, NULL, NULL,
      0, NULL, NULL,
      0, NULL, NULL,
      BasIdx, 1);


  return true;
}

GPoint failedProjection() {
  GPoint fail(DBL_MAX,DBL_MAX,DBL_MAX,NULL);
  fail.setNoSuccess();
  return fail;
}

GPoint sphereProjection(GFace* gf, const double query[3], const std::array<double,10>& analyticalParameters) {
  vec3 dir = {
    query[0] - analyticalParameters[0],
    query[1] - analyticalParameters[1],
    query[2] - analyticalParameters[2]};
  if (length2(dir) == 0.) {
    return failedProjection();
  }
  normalize(dir);
  const vec3 newPos = {
    analyticalParameters[0] + analyticalParameters[3] * dir[0],
    analyticalParameters[1] + analyticalParameters[3] * dir[1],
    analyticalParameters[2] + analyticalParameters[3] * dir[2]};
  return GPoint(newPos[0],newPos[1],newPos[2],gf);
}

GPoint SurfaceProjector::closestPoint(const double query[3], bool evalOnCAD, bool projectOnCAD) const {
  if (useAnalyticalFormula) {
    if (analyticalShape == GFace::GeomType::Sphere) {
      return sphereProjection(gf, query, analyticalParameters);
    } else {
      Msg::Error("SurfaceProjector::closestPoint(): no analytical formula for shape");
      return failedProjection();
    }
  }

  if (OctIdx == 0) {
    Msg::Error("SurfaceProjector::closestPoint(): no octree");
    return failedProjection();
  }

  const int BasIdx = 1; /* indices start at one in libOL */

  /* Octree query */
  double crd[3] = {query[0],query[1],query[2]};
  double dis;
  int idx = LolGetNearest(OctIdx, LolTypTri, crd, &dis, 0, NULL, NULL, 0);
  if (idx <= 0) {
    Msg::Error("SurfaceProjector::closestPoint(): no octree");
    return failedProjection();
  }
  size_t tri = idx - 1;

  /* Projection to get the barycentric coordinates */
  const vec3 queryv3 = {query[0],query[1],query[2]};
  const vec3& p1 = points[triangles[tri][0]-BasIdx];
  const vec3& p2 = points[triangles[tri][1]-BasIdx];
  const vec3& p3 = points[triangles[tri][2]-BasIdx];

  // {
  //   int rdi = rand();
  //   GeoLog::add({p1,p2,p3},0.,"proj_"+std::to_string(rdi));
  //   GeoLog::add(queryv3,double(dis),"proj_"+std::to_string(rdi));
  // }


  double lambda[3];
  vec3 cproj;
  project_point_triangle_l2(queryv3, p1, p2, p3, cproj, lambda);
  GPoint proj;
  if (triangle_uvs.size() > 0) {
    double uv[2] = {0.,0.};
    uv[0] = lambda[0] * triangle_uvs[tri][0][0] + lambda[1] * triangle_uvs[tri][1][0] + lambda[2] * triangle_uvs[tri][2][0];
    uv[1] = lambda[0] * triangle_uvs[tri][0][1] + lambda[1] * triangle_uvs[tri][1][1] + lambda[2] * triangle_uvs[tri][2][1];
    if (projectOnCAD) {
      SPoint3 queryp3(query[0],query[1],query[2]);
      GPoint cadProj = gf->closestPoint(queryp3,uv);
      if (cadProj.succeeded()) {
        proj = cadProj;
      }
    } else if (evalOnCAD) {
      if (triangle_no_uv_eval.size() > 0 && triangle_no_uv_eval[tri]) {
        /* 3D projection */
        SPoint3 queryp3(query[0],query[1],query[2]);
        GPoint cadProj = gf->closestPoint(queryp3,uv);
        if (cadProj.succeeded()) {
          proj = cadProj;
        }
      } else {
        proj = gf->point(uv[0],uv[1]);
      }
    } else {
      proj = GPoint(cproj[0],cproj[1],cproj[2],gf,uv[0],uv[1]);
    }
  } else {
    proj = GPoint(cproj[0],cproj[1],cproj[2],gf);
  }

  return proj;
}
