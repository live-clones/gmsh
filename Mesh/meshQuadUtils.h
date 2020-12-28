// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_UTILS
#define MESH_QUAD_UTILS

#include <vector>
#include <algorithm>
#include <cfloat>
#include "SVector3.h"

class GFace;
class MVertex;
class MElement;
class MQuadrangle;
class SPoint3;
class SurfaceProjector;

namespace GeometryVec3 {
  using vec3 = std::array<double,3>;

  inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
  inline double length2  (const vec3& a) { return dot(a,a); }
  inline double length   (const vec3& a) { return std::sqrt(dot(a,a)); }
  inline vec3 cross(const vec3& a, const vec3& b) { return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};}
  inline vec3 operator-(const vec3& a, const vec3& b) { return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
  inline vec3 operator+(const vec3& a, const vec3& b) { return {a[0]+b[0], a[1]+b[1], a[2]+b[2]}; }
  inline vec3 operator*(const double& a, const vec3& b) { return {a*b[0], a*b[1], a*b[2]}; }
  inline vec3 operator*(const vec3& a, const double& b) { return {a[0]*b, a[1]*b, a[2]*b}; }

  inline void normalize(vec3& a) {
    double len = std::sqrt(length2(a));
    if (len != 0.) a = 1./len * a;
  }

  inline void normalize_accurate(vec3& a) {
    double amp = std::abs(a.data()[0]);
    amp = std::max(amp,std::abs(a.data()[1]));
    amp = std::max(amp,std::abs(a.data()[2]));
    if (amp == 0.) {
      return;
    }
    a[0] *= amp;
    a[1] *= amp;
    a[2] *= amp;
    normalize(a);
  }

  inline double gv3_clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }

  inline double angleVectors(vec3 a, vec3 b) {
    if (length2(a) == 0. || length2(b) == 0.) return DBL_MAX;
    normalize_accurate(a);
    normalize_accurate(b);
    return acos(gv3_clamp(dot(a,b),-1.,1.)); 
  }
  
  inline double angleVectorsAlreadyNormalized(const vec3& a, const vec3& b) {
    return acos(gv3_clamp(dot(a,b),-1.,1.)); 
  }

}

namespace QuadUtils {

  inline void normalize_accurate(SVector3& a) {
    double amp = std::abs(a.data()[0]);
    amp = std::max(amp,std::abs(a.data()[1]));
    amp = std::max(amp,std::abs(a.data()[2]));
    if (amp == 0.) {
      return;
    }
    a = amp * a;
    a.normalize();
  }

  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }

  inline double angleVectors(SVector3 a, SVector3 b) {
    if (a.normSq() == 0. || b.normSq() == 0.) return DBL_MAX;
    normalize_accurate(a);
    normalize_accurate(b);
    return acos(clamp(dot(a,b),-1.,1.)); 
  }
  
  inline double angleVectorsAlreadyNormalized(const SVector3& a, const SVector3& b) {
    return acos(clamp(dot(a,b),-1.,1.)); 
  }


  bool buildBoundary (const std::vector<MElement*>& elements, std::vector<MVertex*>& bnd);

  bool verticesStrictlyInside(const std::vector<MElement*>& quads,
      const std::vector<MVertex*>& bnd, std::vector<MVertex*>& inside);


  /* Templates */

  template<class T> 
    void sort_unique(std::vector<T>& vec) {
      std::sort( vec.begin(), vec.end() );
      vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
    }

  template<class T> 
    std::vector<T> difference(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(s3,s3.begin()));
      return s3;
    }

  template<class T> 
    void append(std::vector<T>& v1, const std::vector<T>& v2) {
      v1.insert(v1.end(),v2.begin(),v2.end());
    }

}

#endif
