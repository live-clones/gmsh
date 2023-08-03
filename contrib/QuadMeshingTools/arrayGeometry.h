// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <array>
#include <vector>
#include <cstdint>
#include <cfloat>
#include <cmath>

namespace ArrayGeometry {
  using vec2 = std::array<double,2>;
  using vec3 = std::array<double,3>;

  /* scalar utils */
  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }
  inline double maxAbs(double x, double y, double z) { return std::max(std::abs(x),std::max(std::abs(y),std::abs(z))); }

  /* vec3 math */
  inline vec3 operator-(const vec3& a, const vec3& b) { return {{a[0]-b[0], a[1]-b[1], a[2]-b[2]}}; }
  inline vec3 operator+(const vec3& a, const vec3& b) { return {{a[0]+b[0], a[1]+b[1], a[2]+b[2]}}; }
  inline vec3 operator*(const double& a, const vec3& b) { return {{a*b[0], a*b[1], a*b[2]}}; }
  inline vec3 operator*(const vec3& a, const double& b) { return {{a[0]*b, a[1]*b, a[2]*b}}; }
  inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
  inline double length2  (const vec3& a) { return dot(a,a); }
  inline double length   (const vec3& a) { return sqrt(length2(a)); }
  inline double maxAbs   (const vec3& a) { return maxAbs(a[0],a[1],a[2]); }
  inline vec3 cross(const vec3& a, const vec3& b) { return {{a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]}};}
  inline void normalizeFast(vec3& a) { a = 1./sqrt(length2(a)) * a; } /* no check, not safe, not accurate */
  inline void normalize(vec3& a) { double amp = maxAbs(a); if (amp == 0.) { return; } a = amp * a; normalizeFast(a); }
  inline double angleVectorsAlreadyNormalized(const vec3& a, const vec3& b) { return acos(clamp(dot(a,b),-1.,1.)); }
  inline double angleVectors(vec3 a, vec3 b);

  /* vec2 math */
  inline vec2 operator-(const vec2& a, const vec2& b) { return {{a[0]-b[0], a[1]-b[1]}}; }
  inline vec2 operator+(const vec2& a, const vec2& b) { return {{a[0]+b[0], a[1]+b[1]}}; }
  inline vec2 operator*(const double& a, const vec2& b) { return {{a*b[0], a*b[1]}}; }
  inline vec2 operator*(const vec2& a, const double& b) { return {{a[0]*b, a[1]*b}}; }
  inline double dot      (const vec2& a, const vec2& b) { return a[0]*b[0]+a[1]*b[1]; }
  inline double length2  (const vec2& a) { return dot(a,a); }
  inline double length   (const vec2& a) { return sqrt(length2(a)); }


  /* functions */

  double bboxDiag(const std::vector<vec3>& points);
  inline vec3 triangleNormal(const vec3& p0, const vec3& p1, const vec3& p2); /* normalized */
  inline double triangleArea(const vec2& a, const vec2& b, const vec2& c);
  inline double triangleArea(const vec3& p0, const vec3& p1, const vec3& p2);
  inline vec3 tetrahedronFaceNormal(const std::array<vec3,4>& pts, size_t lf);
  inline double tetrahedronDihedralAngle(const std::array<vec3,4>& pts, size_t le);
  inline double tetrahedronSolidAngle(const std::array<vec3,4>& pts, size_t lv);
  inline double basicOrient3d(const vec3& p1, const vec3& p2, const vec3& p3, const vec3& p4);


  /**********************/
  /* inline definitions */
  /**********************/

  double angleVectors(vec3 a, vec3 b) {
    double ma = maxAbs(a);
    double mb = maxAbs(b);
    if (ma == 0. || mb == 0.) return DBL_MAX;
    a = ma*a;
    b = mb*b;
    normalizeFast(a);
    normalizeFast(b);
    return angleVectorsAlreadyNormalized(a,b);
  }

  vec3 triangleNormal(const vec3& p0, const vec3& p1, const vec3& p2) {
    vec3 N = cross(p2-p0,p1-p0);
    if (maxAbs(N) == 0.) return {{0.,0.,0.}};
    normalize(N);
    return N;
  }

  double triangleArea(const vec2& a, const vec2& b, const vec2& c) {
    return .5*((b[1]-a[1])*(b[0]+a[0]) + (c[1]-b[1])*(c[0]+b[0]) + (a[1]-c[1])*(a[0]+c[0]));
  }

  double triangleArea(const vec3& p0, const vec3& p1, const vec3& p2) {
    vec3 N = cross(p2-p0,p1-p0);
    return length(N)/2.;
  }

  vec3 tetrahedronFaceNormal(const std::array<vec3,4>& pts, size_t lf) {
    constexpr size_t f[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
    const vec3 p0 = pts[f[lf][0]];
    const vec3 p1 = pts[f[lf][1]];
    const vec3 p2 = pts[f[lf][2]];
    vec3 tfn = cross(p2-p0,p1-p0);
    normalize(tfn);
    return tfn;
  }

  double tetrahedronDihedralAngle(const std::array<vec3,4>& pts, size_t le) {
    constexpr size_t e2f[6][2] = {{0,1},{0,3},{0,2},{1,2},{2,3},{1,3}};
    const vec3 n1 = tetrahedronFaceNormal(pts,e2f[le][0]);
    const vec3 n2 = tetrahedronFaceNormal(pts,e2f[le][1]);
    return acos(clamp(dot(-1.*n1,n2),-1.,1.));
  }

  double tetrahedronSolidAngle(const std::array<vec3,4>& pts, size_t lv) {
    const vec3 pa = pts[(lv+1)%4]-pts[lv];
    const vec3 pb = pts[(lv+2)%4]-pts[lv];
    const vec3 pc = pts[(lv+3)%4]-pts[lv];
    const double top = std::abs(dot(pa,cross(pb,pc)));
    const double bot = length(pa)*length(pb)*length(pc)
      + dot(pa,pb) * length(pc)
      + dot(pb,pc) * length(pb)
      + dot(pb,pc) * length(pa);
    if (std::abs(bot) < 1.e-14) return 0.;
    double sagl = atan(top/bot);
    if (sagl < 0.) sagl = sagl + M_PI;
    sagl = 2. * sagl;
    return sagl;
  }

  double basicOrient3d(const vec3& p1, const vec3& p2, const vec3& p3, const vec3& p4) {
    const double det =  dot(p2 - p1, cross(p3 - p1, p4 - p1));
    return det;
  }

}
