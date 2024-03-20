#ifndef HXT_COMBINE_QUALITY
#define HXT_COMBINE_QUALITY

#include "basic_types.h"
#include "cell_types.h"
#include <float.h>

/** 
 * \file combine_quality.h Fast evaluation of H1 cells at corners 
 */

namespace HXTCombine{

/** 
* Approximate quality of a cell computed from the quality at its corners.
* \pre The number of vertices matches the size of the input table.
* NOT ROBUST
*/
template<class T>
inline double cellApproximateQuality(const vec3* points);

template<class T>
inline double cellCornerQuality(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3);

/**
* Corner quality in a Hex is the Scaled Jacobian. Not fully ROBUST
*/
template<>
inline double cellCornerQuality<Hex>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3);

/**
* Corner quality in a prism. NOT ROBUST.
*/
template<>
inline double cellCornerQuality<Prism>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3);

/**
* Corner quality in a Pyramid. Corners of the quadrilateral facet.
* \param p3 is the pyramid apex. NOT ROBUST
*/
template<>
inline double cellCornerQuality<Pyramid>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3);

/**
* The sinus of the angle (p0p1, p0p2) is an upper bound on the quality of the quad
*/
inline double quadCornerApproximateQuality(const vec3& p0, const vec3& p1, const vec3& p2);
inline double evaluateTriangle(const vec3& p0, const vec3& p1, const vec3& p2);


// --------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------
//                Implementation of inline and template functions
// --------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------


template<>
inline double cellCornerQuality<Hex>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3)
{
  double det = orient3d(p1, p2, p3, p0);
  if (det == 0.) return 0.;

  const vec3 u(p1-p0);
  const vec3 v(p2-p0);
  const vec3 w(p3-p0);
  double norm = u.length()*v.length()*w.length();

  if (norm > DBL_MIN) return det / norm;
  else return 0.0;
}


template<>
inline double cellCornerQuality<Prism>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3)
{  
  double det = orient3d(p1, p2, p3, p0);
  if (det == 0.) return 0.;

  const vec3 u(p1-p0);
  const vec3 v(p2-p0);
  const vec3 p(p3-p0);
  const vec3 w(p2-p1);

  const double lU = u.length();
  const double lV = v.length();
  const double lW = w.length();
  const double lp = p.length();

  double sumInverse = 0.;
  if (lU*lV > DBL_MIN) sumInverse += 1./(lU*lV);
  if (lV*lW > DBL_MIN) sumInverse += 1./(lV*lW);
  if (lU*lW > DBL_MIN) sumInverse += 1./(lU*lW);

  if (lp > DBL_MIN) {
    return 2./(3*sqrt(3)) * det * sumInverse / lp;
  }
  else return 0.;
}

template<>
double cellCornerQuality<Pyramid>(
  const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3)
{
  vec3 p3Bis = p3 - .5 * (p1-p0) - .5 * (p2-p0);
  p3Bis = p0 + std::sqrt(2) * (p3Bis - p0);

  double det = orient3d(p1, p2, p3Bis, p0);
  if (det == 0) return 0.;

  double J[3][3] = {
    { p1.x-p0.x, p2.x-p0.x, p3Bis.x-p0.x },
    { p1.y-p0.y, p2.y-p0.y, p3Bis.y-p0.y },
    { p1.z-p0.z, p2.z-p0.z, p3Bis.z-p0.z }
  };

  double FrobNorm = J[0][0] * J[0][0] + J[0][1] * J[0][1] + J[0][2] * J[0][2]
    + J[1][0] * J[1][0] + J[1][1] * J[1][1] + J[1][2] * J[1][2]
    + J[2][0] * J[2][0] + J[2][1] * J[2][1] + J[2][2] * J[2][2];
  
  int sign = det > 0 ? 1 : -1;
  return sign * 3 * std::cbrt(det*det) / FrobNorm;
}


template<class T>
double cellApproximateQuality(const vec3* vertices) {
  double qualities[T::nbCornersQuality];
  for (unsigned int i = 0; i< T::nbCornersQuality; ++i) {
    const vec3& p0 = vertices[i];
    const vec3& p1 = vertices[T::vertexAdjacentVertex[i][0]];
    const vec3& p2 = vertices[T::vertexAdjacentVertex[i][1]];
    const vec3& p3 = vertices[T::vertexAdjacentVertex[i][2]];
    qualities[i] = cellCornerQuality<T>(p0, p1, p2, p3);
  }
  return *std::min_element(qualities, qualities + T::nbCornersQuality);
}


double quadCornerApproximateQuality(const vec3& p0, const vec3& p1, const vec3& p2)
{
  const vec3 u(p1-p0);
  const vec3 v(p2-p0);
  double lengthuv = u.length()*v.length();
  double lengthW = length(cross(u, v));
  if (lengthuv < DBL_MIN) {
    return lengthW;
  }
  return lengthW/lengthuv;
}


double evaluateTriangle(const vec3& p0, const vec3& p1, const vec3& p2)
{
  const vec3 u(p1-p0);
  const vec3 v(p2-p0);
  const vec3 w(p2-p1);
  const vec3 crossUv = cross(u, v);

  const double lU = u.length();
  const double lV = v.length();
  const double lW = w.length();

  double sumInverse = 0.;
  if (lU*lV > DBL_MIN) sumInverse += 1./(lU*lV);
  if (lV*lW > DBL_MIN) sumInverse += 1./(lV*lW);
  if (lU*lW > DBL_MIN) sumInverse += 1./(lU*lW);
  return  2./(3*sqrt(3)) * crossUv.length() * sumInverse;
}




}
#endif
