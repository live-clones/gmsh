// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <array>
#include <vector>
#include <cstdint>
#include <cfloat>
#include <math.h>

namespace ArrayGeometry {
  using vec2 = std::array<double,2>;
  using vec3 = std::array<double,3>;

  /* scalar utils */
  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }
  inline double maxAbs(double x, double y, double z) { return std::max(std::abs(x),std::max(std::abs(y),std::abs(z))); }

  /* vec3 math */
  inline vec3 operator-(const vec3& a, const vec3& b) { return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
  inline vec3 operator+(const vec3& a, const vec3& b) { return {a[0]+b[0], a[1]+b[1], a[2]+b[2]}; }
  inline vec3 operator*(const double& a, const vec3& b) { return {a*b[0], a*b[1], a*b[2]}; }
  inline vec3 operator*(const vec3& a, const double& b) { return {a[0]*b, a[1]*b, a[2]*b}; }
  inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
  inline double length2  (const vec3& a) { return dot(a,a); }
  inline double length   (const vec3& a) { return sqrt(length2(a)); }
  inline double maxAbs   (const vec3& a) { return maxAbs(a[0],a[1],a[2]); }
  inline vec3 cross(const vec3& a, const vec3& b) { return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};}
  inline void normalizeFast(vec3& a) { a = 1./sqrt(length2(a)) * a; } /* no check, not safe, not accurate */
  inline void normalize(vec3& a) { double amp = maxAbs(a); if (amp == 0.) { return; } a = amp * a; normalizeFast(a); }
  inline double angleVectorsAlreadyNormalized(const vec3& a, const vec3& b) { return acos(clamp(dot(a,b),-1.,1.)); }
  inline double angleVectors(vec3 a, vec3 b);

  /* vec2 math */
  inline vec2 operator-(const vec2& a, const vec2& b) { return {a[0]-b[0], a[1]-b[1]}; }
  inline vec2 operator+(const vec2& a, const vec2& b) { return {a[0]+b[0], a[1]+b[1]}; }
  inline vec2 operator*(const double& a, const vec2& b) { return {a*b[0], a*b[1]}; }
  inline vec2 operator*(const vec2& a, const double& b) { return {a[0]*b, a[1]*b}; }
  inline double dot      (const vec2& a, const vec2& b) { return a[0]*b[0]+a[1]*b[1]; }
  inline double length2  (const vec2& a) { return dot(a,a); }
  inline double length   (const vec2& a) { return sqrt(length2(a)); }


  /* functions */

  double bboxDiag(const std::vector<vec3>& points);
  inline vec3 triangleNormal(const vec3& p0, const vec3& p1, const vec3& p2); /* normalized */
  inline double triangleArea(const vec3& p0, const vec3& p1, const vec3& p2);



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
    if (maxAbs(N) == 0.) return {0.,0.,0.};
    normalize(N);
    return N;
  }

  double triangleArea(const vec3& p0, const vec3& p1, const vec3& p2) {
    vec3 N = cross(p2-p0,p1-p0);
    return length(N)/2.;
  }

}
