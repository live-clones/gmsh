// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshOctreeLibOL.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "OS.h"

extern "C" {
#include "libol1.h"
}

#include "robin_hood.h"

// Debug vizu
// #include "geolog.h"

namespace SurfaceProjectorUtils {
  /* Copy useful functions from contrib/QuadMeshingTools/arrayGeometry.h
   * because this functions should work without QUADMESHINGTOOLS module */
  using vec2 = std::array<double, 2>;
  using vec3 = std::array<double, 3>;
  inline vec3 operator-(const vec3 &a, const vec3 &b)
  {
    return {{a[0] - b[0], a[1] - b[1], a[2] - b[2]}};
  }
  inline vec3 operator+(const vec3 &a, const vec3 &b)
  {
    return {{a[0] + b[0], a[1] + b[1], a[2] + b[2]}};
  }
  inline vec3 operator*(const double &a, const vec3 &b)
  {
    return {{a * b[0], a * b[1], a * b[2]}};
  }
  inline vec3 operator*(const vec3 &a, const double &b)
  {
    return {{a[0] * b, a[1] * b, a[2] * b}};
  }
  inline double dot(const vec3 &a, const vec3 &b)
  {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }
  inline double length2(const vec3 &a) { return dot(a, a); }
  inline double maxAbs(double x, double y, double z)
  {
    return std::max(std::abs(x), std::max(std::abs(y), std::abs(z)));
  }
  inline double maxAbs(const vec3 &a) { return maxAbs(a[0], a[1], a[2]); }
  inline void normalizeFast(vec3 &a)
  {
    a = 1. / std::sqrt(length2(a)) * a;
  } /* no check, not safe, not accurate */
  inline void normalize(vec3 &a)
  {
    double amp = maxAbs(a);
    if(amp == 0.) { return; }
    a = amp * a;
    normalizeFast(a);
  }

  inline double project_point_segment_l2(const vec3 &query, const vec3 &a,
                                         const vec3 &b, vec3 &proj,
                                         double &lambda)
  {
    double l2 = length2(a - b);
    double t = dot(query - a, b - a);
    if(t <= 0. || l2 == 0.) {
      proj = a;
      lambda = 1.;
      return length2(query - a);
    }
    else if(t > l2) {
      proj = b;
      lambda = 0.;
      return length2(query - b);
    }
    lambda = 1. - t / l2;
    proj = lambda * a + (1. - lambda) * b;
    return length2(query - proj);
  }

  /* This function is adapted from a equivalent function in the Geogram library,
   * which is based on https://www.geometrictools.com/Source/Distance3D.html */
  inline double project_point_triangle_l2(const vec3 &query, const vec3 &p1,
                                          const vec3 &p2, const vec3 &p3,
                                          vec3 &proj, double lambda[3])
  {
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
      double cur_dist =
        project_point_segment_l2(query, p1, p2, cur_closest, cur_l1);
      result = cur_dist;
      proj = cur_closest;
      lambda[0] = cur_l1;
      lambda[1] = 1. - cur_l1;
      lambda[2] = 0.0;
      cur_dist = project_point_segment_l2(query, p1, p3, cur_closest, cur_l1);
      if(cur_dist < result) {
        result = cur_dist;
        proj = cur_closest;
        lambda[0] = cur_l1;
        lambda[2] = 1. - cur_l1;
        lambda[1] = 0.0;
      }
      cur_dist = project_point_segment_l2(query, p2, p3, cur_closest, cur_l1);
      if(cur_dist < result) {
        result = cur_dist;
        proj = cur_closest;
        lambda[1] = cur_l1;
        lambda[2] = 1. - cur_l1;
        lambda[0] = 0.0;
      }
      return result;
    }

    if(s + t <= det) {
      if(s < 0.0) {
        if(t < 0.0) { // region 4
          if(b0 < 0.0) {
            t = 0.0;
            if(-b0 >= a00) {
              s = 1.0;
              sqrDistance = a00 + 2.0 * b0 + c;
            }
            else {
              s = -b0 / a00;
              sqrDistance = b0 * s + c;
            }
          }
          else {
            s = 0.0;
            if(b1 >= 0.0) {
              t = 0.0;
              sqrDistance = c;
            }
            else if(-b1 >= a11) {
              t = 1.0;
              sqrDistance = a11 + 2.0 * b1 + c;
            }
            else {
              t = -b1 / a11;
              sqrDistance = b1 * t + c;
            }
          }
        }
        else { // region 3
          s = 0.0;
          if(b1 >= 0.0) {
            t = 0.0;
            sqrDistance = c;
          }
          else if(-b1 >= a11) {
            t = 1.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          }
          else {
            t = -b1 / a11;
            sqrDistance = b1 * t + c;
          }
        }
      }
      else if(t < 0.0) { // region 5
        t = 0.0;
        if(b0 >= 0.0) {
          s = 0.0;
          sqrDistance = c;
        }
        else if(-b0 >= a00) {
          s = 1.0;
          sqrDistance = a00 + 2.0 * b0 + c;
        }
        else {
          s = -b0 / a00;
          sqrDistance = b0 * s + c;
        }
      }
      else { // region 0
        // minimum at interior query
        double invDet = double(1.0) / det;
        s *= invDet;
        t *= invDet;
        sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
                      t * (a01 * s + a11 * t + 2.0 * b1) + c;
      }
    }
    else {
      double tmp0, tmp1, numer, denom;

      if(s < 0.0) { // region 2
        tmp0 = a01 + b0;
        tmp1 = a11 + b1;
        if(tmp1 > tmp0) {
          numer = tmp1 - tmp0;
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            s = 1.0;
            t = 0.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          }
          else {
            s = numer / denom;
            t = 1.0 - s;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
                          t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        }
        else {
          s = 0.0;
          if(tmp1 <= 0.0) {
            t = 1.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          }
          else if(b1 >= 0.0) {
            t = 0.0;
            sqrDistance = c;
          }
          else {
            t = -b1 / a11;
            sqrDistance = b1 * t + c;
          }
        }
      }
      else if(t < 0.0) { // region 6
        tmp0 = a01 + b1;
        tmp1 = a00 + b0;
        if(tmp1 > tmp0) {
          numer = tmp1 - tmp0;
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            t = 1.0;
            s = 0.0;
            sqrDistance = a11 + 2.0 * b1 + c;
          }
          else {
            t = numer / denom;
            s = 1.0 - t;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
                          t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        }
        else {
          t = 0.0;
          if(tmp1 <= 0.0) {
            s = 1.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          }
          else if(b0 >= 0.0) {
            s = 0.0;
            sqrDistance = c;
          }
          else {
            s = -b0 / a00;
            sqrDistance = b0 * s + c;
          }
        }
      }
      else { // region 1
        numer = a11 + b1 - a01 - b0;
        if(numer <= 0.0) {
          s = 0.0;
          t = 1.0;
          sqrDistance = a11 + 2.0 * b1 + c;
        }
        else {
          denom = a00 - 2.0 * a01 + a11;
          if(numer >= denom) {
            s = 1.0;
            t = 0.0;
            sqrDistance = a00 + 2.0 * b0 + c;
          }
          else {
            s = numer / denom;
            t = 1.0 - s;
            sqrDistance = s * (a00 * s + a01 * t + 2.0 * b0) +
                          t * (a01 * s + a11 * t + 2.0 * b1) + c;
          }
        }
      }
    }

    // Account for numerical round-off error.
    if(sqrDistance < 0.0) { sqrDistance = 0.0; }

    proj = p1 + s * edge0 + t * edge1;
    lambda[0] = 1.0 - s - t;
    lambda[1] = s;
    lambda[2] = t;
    return sqrDistance;
  }
} // namespace SurfaceProjectorUtils

using namespace SurfaceProjectorUtils;

SurfaceProjector::SurfaceProjector(GFace *gf_) : gf(NULL), OctIdx(0)
{
  std::vector<MTriangle *> triangles = gf->triangles;
  if(gf->quadrangles.size() > 0) {
    Msg::Error("SurfaceProjector: quads not implemented yet, should create "
               "fake MTriangle* just for initialize()");
    abort();
  }
  bool ok = initialize(gf_, triangles);
  if(!ok) { Msg::Error("failed to initialize SurfaceProjector"); }
}

void SurfaceProjector::clear()
{
  if(OctIdx != 0) {
    Msg::Debug("free libOL octree (OctIdx: %li)", OctIdx);
    LolFreeOctree(OctIdx);
    OctIdx = 0;
  }
  points.clear();
  triangles.clear();
  triangle_uvs.clear();
}

SurfaceProjector::~SurfaceProjector() { clear(); }

bool SurfaceProjector::setAnalyticalProjection(GFace *gf)
{
  if(gf->geomType() == GFace::GeomType::Sphere) {
    double radius = 0.;
    SPoint3 center;
    if(gf->isSphere(radius, center)) {
      analyticalShape = GFace::GeomType::Sphere;
      useAnalyticalFormula = true;
      analyticalParameters[0] = center.x();
      analyticalParameters[1] = center.y();
      analyticalParameters[2] = center.z();
      analyticalParameters[3] = radius;
      return true;
    }
  }

  Msg::Error(
    "Surface projector: analytical formula for given shape not supported");
  return false;
}

bool SurfaceProjector::initialize(GFace *gf_,
    const std::vector<MTriangle *> &gfTriangles,
    bool useCADStl)
{
  clear();
  gf = gf_;
  bool paramAvailable = gf->haveParametrization();
  const int BasIdx = 1; /* indices start at one in libOL */

  if (useCADStl) {
    if (gf->buildSTLTriangulation()) {
      this->points.resize(gf->stl_vertices_xyz.size());
      for (size_t i = 0; i < this->points.size(); ++i) {
        this->points[i] = {
          gf->stl_vertices_xyz[i].x(),
          gf->stl_vertices_xyz[i].y(),
          gf->stl_vertices_xyz[i].z()};
      }

      this->triangles.resize(gf->stl_triangles.size()/3);
      for (size_t i = 0; i < this->triangles.size(); ++i) {
        this->triangles[i] = {gf->stl_triangles[3*i+0]+BasIdx,
          gf->stl_triangles[3*i+1]+BasIdx, gf->stl_triangles[3*i+2]+BasIdx};
      }

      if (paramAvailable && gf->stl_vertices_uv.size()) {
        this->triangle_uvs.resize(gf->stl_triangles.size()/3);
        for (size_t i = 0; i < this->triangle_uvs.size(); ++i) {
          this->triangle_uvs[i][0] = {
            gf->stl_vertices_uv[gf->stl_triangles[3*i+0]].x(),
            gf->stl_vertices_uv[gf->stl_triangles[3*i+0]].y()};
          this->triangle_uvs[i][1] = {
            gf->stl_vertices_uv[gf->stl_triangles[3*i+1]].x(),
            gf->stl_vertices_uv[gf->stl_triangles[3*i+1]].y()};
          this->triangle_uvs[i][2] = {
            gf->stl_vertices_uv[gf->stl_triangles[3*i+2]].x(),
            gf->stl_vertices_uv[gf->stl_triangles[3*i+2]].y()};
        }
      }
    } else {
      Msg::Warning("SurfaceProjector initialize: failed to build STL triangulation");
      return false;
    }
  } else {
    /* If periodic parametrization, get periods */
    bool disableParamPer = false;
    if(paramAvailable && (gf->periodic(0) || gf->periodic(1))) {
      disableParamPer = true;
    }

    /* Collect coordinates and triangle-continuous uv param */
    robin_hood::unordered_map<MVertex *, int32_t> old2new;
    int32_t count = 0;
    triangles.reserve(gfTriangles.size());
    points.reserve(gfTriangles.size());
    if(paramAvailable) {
      triangle_uvs.reserve(gfTriangles.size());
      if(disableParamPer) triangle_no_uv_eval.reserve(gfTriangles.size());
    }
    for(MTriangle *f : gfTriangles) {
      std::array<int32_t, 3> tri_pts;
      std::array<vec2, 3> tri_uvs;
      bool check_periodicity = false;
      bool no_eval = false;
      for(size_t lv = 0; lv < f->getNumVertices(); ++lv) {
        MVertex *v = f->getVertex(lv);
        auto it = old2new.find(v);
        if(it == old2new.end()) {
          old2new[v] = count;
          tri_pts[lv] = count + BasIdx;
          points.push_back(v->point());
          count += 1;
        }
        else {
          tri_pts[lv] = it->second + BasIdx;
        }

        if(paramAvailable) { /* Get the uv in GFace */
          bool onGf = (dynamic_cast<GFace *>(v->onWhat()) == gf);
          if(onGf) {
            v->getParameter(0, tri_uvs[lv][0]);
            v->getParameter(1, tri_uvs[lv][1]);
          }
          else {
            check_periodicity = true;
          }
        }
      }

      if(check_periodicity) {
        bool found = false;
        for(size_t lv = 0; lv < 3; ++lv) {
          MVertex *v1 = f->getVertex(lv);
          bool onGf = (dynamic_cast<GFace *>(v1->onWhat()) == gf);
          if(onGf) { /* If neither of the 3 are on surface, takes random ... */
            MVertex *v2 = f->getVertex((lv + 1) % 3);
            MVertex *v3 = f->getVertex((lv + 2) % 3);
            SPoint2 param1;
            SPoint2 param2;
            SPoint2 param3;
            reparamMeshEdgeOnFace(v1, v2, gf, param1, param2);
            reparamMeshEdgeOnFace(v1, v3, gf, param1, param3);
            tri_uvs[(lv + 0) % 3] = {{param1.x(), param1.y()}};
            tri_uvs[(lv + 1) % 3] = {{param2.x(), param2.y()}};
            tri_uvs[(lv + 2) % 3] = {{param3.x(), param3.y()}};
            found = true;
            break;
          }
        }
        if(!found) {
          /* Triangle with no vertex inside the GFace, difficult to get
           * good UV parametrization, we use center projection to get
           * a initial guess */
          SPoint3 center = f->barycenter();
          double initialGuess[2] = {0., 0.};
          GPoint proj = gf->closestPoint(center, initialGuess);
          if(proj.succeeded()) {
            MFaceVertex cv(proj.x(), proj.y(), proj.z(), gf, proj.u(), proj.v());
            MVertex *v1 = f->getVertex(0);
            MVertex *v2 = f->getVertex(1);
            MVertex *v3 = f->getVertex(2);
            SPoint2 paramc;
            SPoint2 param1;
            SPoint2 param2;
            SPoint2 param3;
            reparamMeshEdgeOnFace(&cv, v1, gf, paramc, param1);
            reparamMeshEdgeOnFace(&cv, v2, gf, paramc, param2);
            reparamMeshEdgeOnFace(&cv, v3, gf, paramc, param3);
            tri_uvs[0] = {{param1.x(), param1.y()}};
            tri_uvs[1] = {{param2.x(), param2.y()}};
            tri_uvs[2] = {{param3.x(), param3.y()}};
          }
          else {
            no_eval = true;
            tri_uvs[0] = {{0., 0.}};
            tri_uvs[1] = {{0., 0.}};
            tri_uvs[2] = {{0., 0.}};
          }
        }
      }

      triangles.push_back(tri_pts);
      if(paramAvailable) triangle_uvs.push_back(tri_uvs);
      if(paramAvailable && disableParamPer)
        triangle_no_uv_eval.push_back(no_eval);
      // Debug to visualize param
      // {
      //   GeoLog::add({points[tri_pts[0]-1], points[tri_pts[1]-1],
      //   points[tri_pts[2]-1]},
      //       std::vector<double>{tri_uvs[0][0],tri_uvs[1][0],tri_uvs[2][0]},
      //       "sp_u");
      //   GeoLog::add({points[tri_pts[0]-1], points[tri_pts[1]-1],
      //   points[tri_pts[2]-1]},
      //       std::vector<double>{tri_uvs[0][1],tri_uvs[1][1],tri_uvs[2][1]},
      //       "sp_v");
      // }
    }
  }

  points.shrink_to_fit();
  triangles.shrink_to_fit();
  triangle_uvs.shrink_to_fit();

  // Build an octree from a surface mesh
  int32_t NmbVer = (int32_t)points.size();
  double *VerTab1 = points[0].data();
  double *VerTab2 = points[1].data();
  // double* VerTab2  = VerTab1[3];
  int32_t NmbTri = (int32_t)triangles.size();
  int32_t *TriTab1 = triangles[0].data();
  // int32_t* TriTab2  = TriTab1[3];
  int32_t *TriTab2 = triangles[1].data();
  Msg::Debug("create libOL octree (%i vertices and %i triangles)", NmbVer,
             NmbTri);
  OctIdx = LolNewOctree(NmbVer, VerTab1, VerTab2, 0, NULL, NULL, NmbTri,
                        TriTab1, TriTab2, 0, NULL, NULL, 0, NULL, NULL, 0, NULL,
                        NULL, 0, NULL, NULL, 0, NULL, NULL, BasIdx, 1);

  return true;
}

GPoint failedProjection()
{
  GPoint fail(DBL_MAX, DBL_MAX, DBL_MAX, NULL);
  fail.setNoSuccess();
  return fail;
}

GPoint sphereProjection(GFace *gf, const double query[3],
                        const std::array<double, 10> &analyticalParameters)
{
  vec3 dir = {{query[0] - analyticalParameters[0],
               query[1] - analyticalParameters[1],
               query[2] - analyticalParameters[2]}};
  if(length2(dir) == 0.) { return failedProjection(); }
  normalize(dir);
  const vec3 newPos = {{
    analyticalParameters[0] + analyticalParameters[3] * dir[0],
    analyticalParameters[1] + analyticalParameters[3] * dir[1],
    analyticalParameters[2] + analyticalParameters[3] * dir[2]}};
  return GPoint(newPos[0], newPos[1], newPos[2], gf);
}

GPoint SurfaceProjector::closestPoint(const double query[3], bool evalOnCAD,
                                      bool projectOnCAD) const
{
  if(useAnalyticalFormula) {
    if(analyticalShape == GFace::GeomType::Sphere) {
      return sphereProjection(gf, query, analyticalParameters);
    }
    else {
      Msg::Error(
        "SurfaceProjector::closestPoint(): no analytical formula for shape");
      return failedProjection();
    }
  }

  if(OctIdx == 0) {
    Msg::Error("SurfaceProjector::closestPoint(): no octree (face %i, %li "
               "points, %li triangles)",
               gf->tag(), points.size(), triangles.size());
    return failedProjection();
  }

  const int BasIdx = 1; /* indices start at one in libOL */

  /* Octree query */
  double crd[3] = {query[0], query[1], query[2]};
  double dis = DBL_MAX;
  int idx = LolGetNearest(OctIdx, LolTypTri, crd, &dis, 0, NULL, NULL, 0);
  if(idx <= 0) {
    Msg::Warning("SurfaceProjector::closestPoint(): no closest triangle found "
                 "(face %i, %li triangles)",
                 gf->tag(), triangles.size());
    return failedProjection();
  }
  size_t tri = idx - 1;

  /* Projection to get the barycentric coordinates */
  const vec3 queryv3 = {{query[0], query[1], query[2]}};
  const vec3 &p1 = points[triangles[tri][0] - BasIdx];
  const vec3 &p2 = points[triangles[tri][1] - BasIdx];
  const vec3 &p3 = points[triangles[tri][2] - BasIdx];

  // {
  //   int rdi = rand();
  //   GeoLog::add({p1,p2,p3},0.,"proj_"+std::to_string(rdi));
  //   GeoLog::add(queryv3,double(dis),"proj_"+std::to_string(rdi));
  // }

  double lambda[3];
  vec3 cproj;
  project_point_triangle_l2(queryv3, p1, p2, p3, cproj, lambda);
  GPoint proj;
  if(triangle_uvs.size() > 0) {
    double uv[2] = {0., 0.};
    uv[0] = lambda[0] * triangle_uvs[tri][0][0] +
            lambda[1] * triangle_uvs[tri][1][0] +
            lambda[2] * triangle_uvs[tri][2][0];
    uv[1] = lambda[0] * triangle_uvs[tri][0][1] +
            lambda[1] * triangle_uvs[tri][1][1] +
            lambda[2] * triangle_uvs[tri][2][1];
    if(projectOnCAD) {
      SPoint3 queryp3(query[0], query[1], query[2]);
      GPoint cadProj = gf->closestPoint(queryp3, uv);
      if(cadProj.succeeded()) { proj = cadProj; }
    }
    else if(evalOnCAD) {
      if(triangle_no_uv_eval.size() > 0 && triangle_no_uv_eval[tri]) {
        /* 3D projection */
        SPoint3 queryp3(query[0], query[1], query[2]);
        GPoint cadProj = gf->closestPoint(queryp3, uv);
        if(cadProj.succeeded()) { proj = cadProj; }
      }
      else {
        proj = gf->point(uv[0], uv[1]);
      }
    }
    else {
      proj = GPoint(cproj[0], cproj[1], cproj[2], gf, uv[0], uv[1]);
    }
  }
  else {
    proj = GPoint(cproj[0], cproj[1], cproj[2], gf);
  }

  return proj;
}

libOLwrapper::libOLwrapper(
        const std::vector<std::array<double,3> >&  _points,
        const std::vector<std::array<int32_t,2> >& _edges,
        const std::vector<std::array<int32_t,3> >& _triangles,
        const std::vector<std::array<int32_t,4> >& _quads,
        const std::vector<std::array<int32_t,4> >& _tetrahedra,
        const std::vector<std::array<int32_t,5> >& _pyramids,
        const std::vector<std::array<int32_t,6> >& _prisms,
        const std::vector<std::array<int32_t,8> >& _hexahedra):
 points(_points), edges(_edges), triangles(_triangles), quads(_quads),
  tetrahedra(_tetrahedra), pyramids(_pyramids), prisms(_prisms),
  hexahedra(_hexahedra)
{
  const int BasIdx = 1; /* indices start at one in libOL */
  for (size_t i = 0; i < edges.size(); ++i) for (size_t j = 0; j < edges[0].size(); ++j) edges[i][j] += BasIdx;
  for (size_t i = 0; i < triangles.size(); ++i) for (size_t j = 0; j < triangles[0].size(); ++j) triangles[i][j] += BasIdx;
  for (size_t i = 0; i < quads.size(); ++i) for (size_t j = 0; j < quads[0].size(); ++j) quads[i][j] += BasIdx;
  for (size_t i = 0; i < tetrahedra.size(); ++i) for (size_t j = 0; j < tetrahedra[0].size(); ++j) tetrahedra[i][j] += BasIdx;
  for (size_t i = 0; i < pyramids.size(); ++i) for (size_t j = 0; j < pyramids[0].size(); ++j) pyramids[i][j] += BasIdx;
  for (size_t i = 0; i < prisms.size(); ++i) for (size_t j = 0; j < prisms[0].size(); ++j) prisms[i][j] += BasIdx;
  for (size_t i = 0; i < hexahedra.size(); ++i) for (size_t j = 0; j < hexahedra[0].size(); ++j) hexahedra[i][j] += BasIdx;

  // Build an octree
  double t0 = Cpu();
  OctIdx = LolNewOctree(
      (int32_t)points.size(), points[0].data(), points[1].data(),
      (int32_t)edges.size(), edges[0].data(), edges[1].data(),
      (int32_t)triangles.size(), triangles[0].data(), triangles[1].data(),
      (int32_t)quads.size(), quads[0].data(), quads[1].data(),
      (int32_t)tetrahedra.size(), tetrahedra[0].data(), tetrahedra[1].data(),
      (int32_t)pyramids.size(), pyramids[0].data(), pyramids[1].data(),
      (int32_t)prisms.size(), prisms[0].data(), prisms[1].data(),
      (int32_t)hexahedra.size(), hexahedra[0].data(), hexahedra[1].data(),
      BasIdx, 1);

  Msg::Debug("libOL octree created (%li vertices, %.3f sec), OctIdx: %li", points.size(), Cpu()-t0, OctIdx);
}

libOLwrapper::~libOLwrapper() {
  if(OctIdx != 0) {
    Msg::Debug("libOL octree freed (OctIdx: %li)", OctIdx);
    LolFreeOctree(OctIdx);
    OctIdx = 0;
  }
}

int libOLwrapper::elementsInsideBoundingBox(libOLTypTag elementType,
    double* bboxMin, double* bboxMax,
    std::vector<int32_t>& elements) {

  const int BufSiz = 1e5;
  int buf[BufSiz];

  int NmbItm = LolGetBoundingBox(OctIdx, (int)elementType, BufSiz, buf, bboxMin, bboxMax, 0);
  elements.resize(NmbItm);
  for (int i = 0; i < NmbItm; ++i) {
    elements[i] = buf[i]-1;
  }

  return NmbItm;
}
