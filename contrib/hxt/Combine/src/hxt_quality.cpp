#include "hxt_quality.h"

#include "float.h"
#include "math.h"

// Error when trying to include. Would be better for sqrt and cbrt computations
//#include "cmath.h"   

#include <algorithm>

#include "expansion.h"
#include "predicates.h"

#include "hxt_tools.h"

/**
* \authors Amaury Johnen, Kilian Verhetsel, Jeanne Pellerin
*/

// This is a vec 3 -- I am trying to compile [jeanne]
/** Class to represent a 3d point or vector
 * Particularly useful to write and read code
 *
 * TODO -- share that structure in HXT
 */
class point3d {
public:
  point3d() {
    x = 0; y = 0; z = 0;
  }
  point3d(double a, double b, double c) {
    x = a; y = b; z = c;
  }
  point3d(const double *a) {
    x = a[0]; y = a[1]; z = a[2];
  }
  void setData(const double *a) {
    x = a[0]; y = a[1]; z = a[2];
  }
  double operator[](unsigned int i) const { return data()[i]; }
  point3d operator+(const point3d& v) const { return point3d(x+v.x, y+v.y, z+v.z); }
  point3d operator-(const point3d& v) const { return point3d(x-v.x, y-v.y, z-v.z); }
  point3d operator/(const double f) const { return point3d(x / f, y / f, z / f); }
  point3d operator*(const double f) const { return point3d(x * f, y * f, z * f); }
  double norm2() const { return x*x+y*y+z*z; }
  const double* data() const { return &x; }
  double length() const { return sqrt(x * x + y * y + z * z); }

public:
  double x;
  double y;
  double z;
};

// Helper functions on point3d
inline point3d operator*(double f, const point3d& v) {
  return point3d(f*v.x, f*v.y, f*v.z);
}
inline double dot(point3d a, point3d b) { return a[0]*b[0] + a[1] * b[1] + a[2]*b[2]; };
inline point3d cross(point3d v1, point3d v2) {
  return point3d(v1.y * v2.z - v1.z * v2.y,
    v1.z * v2.x - v1.x * v2.z,
    v1.x * v2.y - v1.y * v2.x
  );
}
inline double orient3d(point3d a, point3d b, point3d c, point3d d) {
  return orient3d(a.data(), b.data(), c.data(), d.data());
}
inline double length(const point3d& v) { return v.length(); }


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

namespace {
 
  // We need some default index value
  const unsigned int NO_ID(-1);

  static const unsigned int hexVertexAdjacentVertex[8][3] = {
    { 1,3,4 },{ 2,0,5 },{ 3,1,6 },{ 0,2,7 },
    { 7,5,0 },{ 4,6,1 },{ 5,7,2 },{ 6,4,3 } };

  static const unsigned int prismVertexAdjacentVertex[6][3] = {
    { 1,2,3 },{ 2,0,4 },{ 0,1,5 },{ 5,4,0 },
    { 3,5,1 },{ 4,3,2 } };

  static const unsigned int pyramidVertexAdjacentVertex[5][4] = {
    { 1,3,4, NO_ID },{ 2,0,4, NO_ID },
    { 3,1,4, NO_ID },{ 0,2,4, NO_ID },
    { 0,1,2,3 } };

  /**
  * Corner quality in a Hex is the Scaled Jacobian.
  */
  inline double cellCornerQualityHex(
    const point3d& p0, const point3d& p1, const point3d& p2, const point3d& p3)
  {
    double det = orient3d(p1, p2, p3, p0);
    if (det == 0.) return 0.;

    const point3d u(p1-p0);
    const point3d v(p2-p0);
    const point3d w(p3-p0);
    double norm = u.length()*v.length()*w.length();

    if (norm > DBL_MIN) return det / norm;
    else return 0.0;
  }

  /**
  * Corner quality in a prism.
  */
  inline double cellCornerQualityPrism(
    const point3d& p0, const point3d& p1, const point3d& p2, const point3d& p3)
  {
    double det = orient3d(p1, p2, p3, p0);
    if (det == 0.) return 0.;

    const point3d u(p1-p0);
    const point3d v(p2-p0);
    const point3d p(p3-p0);
    const point3d w(p2-p1);

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

  /**
  * Corner quality in a Pyramid. Corners of the quadrilateral facet.
  * \param p3 is the pyramid apex.
  */
  double cellCornerQualityPyramid(
    const point3d& p0, const point3d& p1, const point3d& p2, const point3d& p3)
  {
    point3d p3Bis = p3 - (p1-p0)* .5 - (p2-p0)*.5;
    p3Bis = p0 + (p3Bis - p0) * /*std::*/sqrt(2);

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
    return sign * 3 * /*std::*/cbrt(det*det) / FrobNorm;
  }

  /**
  * Approximate quality of a cell computed from the quality at its corners.
  * \pre The number of vertices matches the size of the input table.
  * NOT ROBUST
  */
  double cellApproximateHexQuality(const point3d* vertices) {
    double qualities[8];

    for (unsigned int i = 0; i< 8; ++i) {
      const point3d& p0 = vertices[i];
      const point3d& p1 = vertices[hexVertexAdjacentVertex[i][0]];
      const point3d& p2 = vertices[hexVertexAdjacentVertex[i][1]];
      const point3d& p3 = vertices[hexVertexAdjacentVertex[i][2]];
      qualities[i] = cellCornerQualityHex(p0, p1, p2, p3);
    }
    return *std::min_element(qualities, qualities + 8);
  }

  double cellApproximatePrismQuality(const point3d* vertices) {
    double qualities[6];
    for (unsigned int i = 0; i< 6; ++i) {
      const point3d& p0 = vertices[i];
      const point3d& p1 = vertices[prismVertexAdjacentVertex[i][0]];
      const point3d& p2 = vertices[prismVertexAdjacentVertex[i][1]];
      const point3d& p3 = vertices[prismVertexAdjacentVertex[i][2]];
      qualities[i] = cellCornerQualityPrism(p0, p1, p2, p3);
    }
    return *std::min_element(qualities, qualities + 6);
  }

  double cellApproximatePyramidQuality(const point3d* vertices) {
    double qualities[4];
    for (unsigned int i = 0; i< 4; ++i) {
      const point3d& p0 = vertices[i];
      const point3d& p1 = vertices[pyramidVertexAdjacentVertex[i][0]];
      const point3d& p2 = vertices[pyramidVertexAdjacentVertex[i][1]];
      const point3d& p3 = vertices[pyramidVertexAdjacentVertex[i][2]];
      qualities[i] = cellCornerQualityPyramid(p0, p1, p2, p3);
    }
    return *std::min_element(qualities, qualities + 4);
  }


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

double orient3dInexact(point3d pa, point3d pb, point3d pc, point3d pd, double &errbound) 
{
  double adx = pa[0] - pd[0];
  double bdx = pb[0] - pd[0];
  double cdx = pc[0] - pd[0];
  double ady = pa[1] - pd[1];
  double bdy = pb[1] - pd[1];
  double cdy = pc[1] - pd[1];
  double adz = pa[2] - pd[2];
  double bdz = pb[2] - pd[2];
  double cdz = pc[2] - pd[2];

  double bdxcdy = bdx * cdy;
  double cdxbdy = cdx * bdy;

  double cdxady = cdx * ady;
  double adxcdy = adx * cdy;

  double adxbdy = adx * bdy;
  double bdxady = bdx * ady;

  double det = adz * (bdxcdy - cdxbdy)
    + bdz * (cdxady - adxcdy)
    + cdz * (adxbdy - bdxady);

  double permanent = (std::abs(bdxcdy) + std::abs(cdxbdy)) * std::abs(adz)
    + (std::abs(cdxady) + std::abs(adxcdy)) * std::abs(bdz)
    + (std::abs(adxbdy) + std::abs(bdxady)) * std::abs(cdz);

  errbound = o3derrboundA * permanent;
  return -det;
}

double orient3dMidpointInexact(point3d p0, point3d p1, point3d p2, point3d p3,
                                      point3d p4, point3d p5, double &errbound)
{
  double adx = p0[0] - .5*(p4[0] + p5[0]);
  double bdx = p1[0] - .5*(p4[0] + p5[0]);
  double cdx = .5*(p2[0] + p3[0]) - .5*(p4[0] + p5[0]);

  double ady = p0[1] - .5*(p4[1] + p5[1]);
  double bdy = p1[1] - .5*(p4[1] + p5[1]);
  double cdy = .5*(p2[1] + p3[1]) - .5*(p4[1] + p5[1]);

  double adz = p0[2] - .5*(p4[2] + p5[2]);
  double bdz = p1[2] - .5*(p4[2] + p5[2]);
  double cdz = .5*(p2[2] + p3[2]) - .5*(p4[2] + p5[2]);

  double bdxcdy = bdx * cdy;
  double cdxbdy = cdx * bdy;

  double cdxady = cdx * ady;
  double adxcdy = adx * cdy;

  double adxbdy = adx * bdy;
  double bdxady = bdx * ady;

  double det = adz * (bdxcdy - cdxbdy)
    + bdz * (cdxady - adxcdy)
    + cdz * (adxbdy - bdxady);

  double absP2_0 = std::abs(.5*(p2[0] + p3[0]));
  double absP3_0 = std::abs(.5*(p4[0] + p5[0]));

  double absP2_1 = std::abs(.5*(p2[1] + p3[1]));
  double absP3_1 = std::abs(.5*(p4[1] + p5[1]));

  double absP2_2 = std::abs(.5*(p2[2] + p3[2]));
  double absP3_2 = std::abs(.5*(p4[2] + p5[2]));

  double absAdx = std::abs(p0[0]) + absP3_0;
  double absBdx = std::abs(p1[0]) + absP3_0;
  double absCdx = absP2_0 + absP3_0;

  double absAdy = std::abs(p0[1]) + absP3_1;
  double absBdy = std::abs(p1[1]) + absP3_1;
  double absCdy = absP2_1 + absP3_1;

  double absAdz = std::abs(p0[2]) + absP3_2;
  double absBdz = std::abs(p1[2]) + absP3_2;
  double absCdz = absP2_2 + absP3_2;

  double permanent = (absBdx*absCdy + absCdx*absBdy) * absAdz
    + (absCdx*absAdy + absAdx*absCdy) * absBdz
    + (absAdx*absBdy + absBdx*absAdy) * absCdz;

  static constexpr double boundCoeff = (92.0 * DBL_EPSILON/2 + 10) * DBL_EPSILON/2;
  errbound = boundCoeff * permanent;

  return -det;
}

void orient3dExact(DynamicExpansion &det, point3d pa, point3d pb, point3d pc, point3d pd)
{
  auto axby = exact(pa[0]) * exact(pb[1]);
  auto bxay = exact(pb[0]) * exact(pa[1]);
  auto ab = axby - bxay;

  auto bxcy = exact(pb[0]) * exact(pc[1]);
  auto cxby = exact(pc[0]) * exact(pb[1]);
  auto bc = bxcy - cxby;

  auto cxdy = exact(pc[0]) * exact(pd[1]);
  auto dxcy = exact(pd[0]) * exact(pc[1]);
  auto cd = cxdy - dxcy;

  auto dxay = exact(pd[0]) * exact(pa[1]);
  auto axdy = exact(pa[0]) * exact(pd[1]);
  auto da = dxay - axdy;

  auto axcy = exact(pa[0]) * exact(pc[1]);
  auto cxay = exact(pc[0]) * exact(pa[1]);
  auto ac = axcy - cxay;

  auto bxdy = exact(pb[0]) * exact(pd[1]);
  auto dxby = exact(pd[0]) * exact(pb[1]);
  auto bd = bxdy - dxby;

  auto tmp = cd.withZeroElimination() + da.withZeroElimination();
  auto cda = tmp + ac.withZeroElimination();

  tmp = da.withZeroElimination() + ab.withZeroElimination();
  auto dab = tmp + bd.withZeroElimination();

  bd.scaleInPlace(-1.0);
  ac.scaleInPlace(-1.0);

  tmp = ab.withZeroElimination() + bc.withZeroElimination();
  auto abc = tmp + ac.withZeroElimination();

  tmp = bc.withZeroElimination() + cd.withZeroElimination();
  auto bcd = tmp + bd.withZeroElimination();

  auto adet = bcd * pa[2];
  auto bdet = cda * (-pb[2]);
  auto cdet = dab * pc[2];
  auto ddet = abc * (-pd[2]);

  det = (DynamicExpansion)((adet + bdet) + (cdet + ddet));
  det.scaleInPlace(-1.0);
}

/**
  * This operation is about twice as slow as an exact orient3d. There may still
  * be a better way to decompose the determinant into smaller terms.
  */
 void orient3dMidpointExact(DynamicExpansion &det,
    point3d pa, point3d pb,
    point3d origPc, point3d origPd,
    point3d origPe, point3d origPf) 
{
  auto pcx = (exact(origPc[0]) + exact(origPd[0])).scaleInPlace(0.5);
  auto pcy = (exact(origPc[1]) + exact(origPd[1])).scaleInPlace(0.5);
  auto pcz = (exact(origPc[2]) + exact(origPd[2])).scaleInPlace(0.5);

  auto pdx = (exact(origPe[0]) + exact(origPf[0])).scaleInPlace(0.5);
  auto pdy = (exact(origPe[1]) + exact(origPf[1])).scaleInPlace(0.5);
  auto pdz = (exact(origPe[2]) + exact(origPf[2])).scaleInPlace(0.5);

  auto axby = exact(pa[0]) * exact(pb[1]);
  auto bxay = exact(pb[0]) * exact(pa[1]);
  auto ab = axby - bxay;

  auto bxcy = exact(pb[0]) * pcy;
  auto cxby = pcx * exact(pb[1]);
  auto bc = bxcy - cxby;

  auto cxdy = pcx * pdy;
  auto dxcy = pdx * pcy;
  auto cd = cxdy - dxcy;

  auto dxay = pdx * exact(pa[1]);
  auto axdy = exact(pa[0]) * pdy;
  auto da = dxay - axdy;

  auto axcy = exact(pa[0]) * pcy;
  auto cxay = pcx * exact(pa[1]);
  auto ac = axcy - cxay;

  auto bxdy = exact(pb[0]) * pdy;
  auto dxby = pdx * exact(pb[1]);
  auto bd = bxdy - dxby;

  auto tmp1 = cd.withZeroElimination() + da.withZeroElimination();
  auto cda = tmp1 + ac.withZeroElimination();

  auto tmp2 = da.withZeroElimination() + ab.withZeroElimination();
  auto dab = tmp2 + bd.withZeroElimination();

  bd.scaleInPlace(-1.0);
  ac.scaleInPlace(-1.0);

  auto tmp3 = ab.withZeroElimination() + bc.withZeroElimination();
  auto abc = tmp3 + ac.withZeroElimination();

  auto tmp4 = bc.withZeroElimination() + cd.withZeroElimination();
  auto bcd = tmp4 + bd.withZeroElimination();

  auto adet = bcd * pa[2];
  auto bdet = cda * (-pb[2]);
  auto cdet = dab * pcz;
  auto ddet = abc * pdz.scaleInPlace(-1.0);

  det = (DynamicExpansion)((adet + bdet) + (cdet + ddet));
  det.scaleInPlace(-1.0);
}

/** Class to manage the computation of Bezier Coefficients to have an
* evaluation of an hexahedron validity that is robust to floating point errors.
* 
* \author Kilian Verhetsel
*/
class BezierCoefficient {
  double value_, errorBound_;
  BezierCoefficient *parentA_;

  union {
    BezierCoefficient *parentB_;
    const point3d *hex_;
  };

  HXTIndex id_;

  DynamicExpansion exactValue_;
  bool exactValueKnown_;

public:
  BezierCoefficient(BezierCoefficient &a, BezierCoefficient &b) :
    exactValueKnown_(false) {
    setAverage(&a, &b);
  }

  BezierCoefficient(HXTIndex i, const point3d *hex, double value, double bound) :
    value_(value), errorBound_(bound),
    parentA_(nullptr), hex_(hex), id_(i),
    exactValueKnown_(false) {
  }

  BezierCoefficient(double value = 0.0) :
    value_(value), errorBound_(0.0),
    parentA_(nullptr), parentB_(nullptr),
    exactValueKnown_(false) {
  }

  int sign() {
    if (value_ > errorBound_) return 1;
    else if (value_ < -errorBound_) return -1;
    else return exactValue().sign();
  }

  double value() const { return value_; }
  double errorBound() const { return errorBound_; }

  const DynamicExpansion &exactValue() {
    if (exactValueKnown_) return exactValue_;

    if (!parentA_) {
      if (id_ < 20) {
        switch (id_) {
        case 0: computeTetVolumeSimple(0, 1, 3, 4); break;
        case 1: computeTetVolumeSimple(1, 2, 0, 5); break;
        case 2: computeTetVolumeSimple(2, 3, 1, 6); break;
        case 3: computeTetVolumeSimple(3, 0, 2, 7); break;

        case 4: computeTetVolumeSimple(4, 7, 5, 0); break;
        case 5: computeTetVolumeSimple(5, 4, 6, 1); break;
        case 6: computeTetVolumeSimple(6, 5, 7, 2); break;
        case 7: computeTetVolumeSimple(7, 6, 4, 3); break;

        case 8: computeTetVolumeMidpoint(0, 1, 2, 3, 4, 5); break;
        case 9: computeTetVolumeMidpoint(1, 2, 3, 0, 5, 6); break;
        case 10: computeTetVolumeMidpoint(2, 3, 0, 1, 6, 7); break;
        case 11: computeTetVolumeMidpoint(3, 0, 1, 2, 7, 4); break;

        case 12: computeTetVolumeMidpoint(0, 4, 1, 5, 3, 7); break;
        case 13: computeTetVolumeMidpoint(1, 5, 2, 6, 0, 4); break;
        case 14: computeTetVolumeMidpoint(2, 6, 3, 7, 1, 5); break;
        case 15: computeTetVolumeMidpoint(3, 7, 0, 4, 2, 6); break;

        case 16: computeTetVolumeMidpoint(4, 5, 0, 1, 6, 7); break;
        case 17: computeTetVolumeMidpoint(5, 6, 1, 2, 7, 4); break;
        case 18: computeTetVolumeMidpoint(6, 7, 2, 3, 4, 5); break;
        case 19: computeTetVolumeMidpoint(7, 4, 3, 0, 5, 6); break;
        }
      }
      else {
        int i = id_ - 20;
        BezierCoefficient *jacobian = parentB_;

        switch (i) {
        case 8: case 9: case 10: case 11:
          exactValue_ = jacobian[i].exactValue().scalePowerOfTwo(2.0) +
            (jacobian[i - 8].exactValue() + jacobian[(i-7) % 4].exactValue()).
            scaleInPlace(-0.5);
          break;
        case 12: case 13: case 14: case 15:
          exactValue_ = jacobian[i].exactValue().scalePowerOfTwo(2.0) +
            (jacobian[i - 12].exactValue() + jacobian[i-8].exactValue()).
            scaleInPlace(-0.5);
          break;
        case 16: case 17: case 18: case 19:
          exactValue_ = jacobian[i].exactValue().scalePowerOfTwo(2.0) +
            (jacobian[i - 12].exactValue() + jacobian[4+(i-15)%4].exactValue()).
            scaleInPlace(-0.5);
          break;
        case 20:
          exactValue_ =
            ((jacobian[8].exactValue()  + jacobian[9].exactValue()) +
            (jacobian[10].exactValue() + jacobian[11].exactValue())) +
              ((jacobian[0].exactValue() + jacobian[1].exactValue()) +
            (jacobian[2].exactValue() + jacobian[3].exactValue())) * (-3/4.0);
          break;
        case 21: case 22: case 23: case 24:
          exactValue_ =
            ((jacobian[(i-13)].exactValue()  + jacobian[(i-9)].exactValue()) +
            (jacobian[12+(i-20)%4].exactValue() + jacobian[i-5].exactValue())) +
              ((jacobian[i-21].exactValue() + jacobian[i-17].exactValue()) +
            (jacobian[(i-20)%4].exactValue() + jacobian[4+(i-20)%4].exactValue())) *
                (-3/4.0);
          break;
        case 25:
          exactValue_ =
            ((jacobian[16].exactValue()  + jacobian[17].exactValue()) +
            (jacobian[18].exactValue() + jacobian[19].exactValue())) +
              ((jacobian[4].exactValue() + jacobian[5].exactValue()) +
            (jacobian[6].exactValue() + jacobian[7].exactValue())) * (-3/4.0);
          break;
        case 26:
          for (int k = 0; k < 8; ++k)
            exactValue_ = exactValue_ + jacobian[k].exactValue();
          exactValue_ = exactValue_ * -5.4;
          for (int k = 8; k < 20; ++k)
            exactValue_ = exactValue_ + jacobian[k].exactValue();
          exactValue_.scaleInPlace(0.5);
          break;
        }
      }
    }
    else {
      const DynamicExpansion &valA = parentA_->exactValue();
      const DynamicExpansion &valB = parentB_->exactValue();
      exactValue_ = (valA + valB).scaleInPlace(0.5);
    }

    exactValueKnown_ = true;
    return exactValue_;
  }

  BezierCoefficient *setTetVolume(HXTIndex id, const point3d *hex,
    HXTIndex i0, HXTIndex i1,
    HXTIndex i2, HXTIndex i3) {
    hex_ = hex;
    id_ = id;
    value_ = orient3dInexact(hex[i0], hex[i1], hex[i2], hex[i3], errorBound_);
    return this;
  }

  BezierCoefficient *setTetVolumeMidpoint(HXTIndex id, const point3d *hex,
    HXTIndex i0, HXTIndex i1,
    HXTIndex i2, HXTIndex i3,
    HXTIndex i4, HXTIndex i5) {
    hex_ = hex;
    id_ = id;
    value_ = orient3dMidpointInexact(
      hex[i0], hex[i1], hex[i2], hex[i3], hex[i4], hex[i5], errorBound_);
    return this;
  }

  BezierCoefficient *setValue(double value) {
    value_ = value;
    errorBound_ = 0.0;
    return this;
  }

  BezierCoefficient *setValue(HXTIndex id, BezierCoefficient *jacobian,
    double value, double bound) {
    value_ = value;
    errorBound_ = bound;
    id_ = id;
    parentB_ = jacobian;
    return this;
  }

  BezierCoefficient *setAverage(BezierCoefficient *a, BezierCoefficient *b) {
    parentA_ = a;
    parentB_ = b;

    value_ = 0.5 * (a->value() + b->value());

    constexpr double eps = DBL_EPSILON/2;
    errorBound_ = (1 + 4*eps) * 0.5 *
      (a->errorBound() + b->errorBound() +
        eps*(1+4*eps)*(std::abs(a->value()) + std::abs(b->value()) +
          a->errorBound() + b->errorBound()));

    return this;
  }

private:
  void computeTetVolumeSimple(HXTIndex i0, HXTIndex i1, HXTIndex i2, HXTIndex i3) {
    orient3dExact(exactValue_, hex_[i0], hex_[i1], hex_[i2], hex_[i3]);
  }

  void computeTetVolumeMidpoint(HXTIndex i0, HXTIndex i1, HXTIndex i2, HXTIndex i3,
    HXTIndex i4, HXTIndex i5) {
    orient3dMidpointExact(exactValue_, hex_[i0], hex_[i1], hex_[i2],
      hex_[i3], hex_[i4], hex_[i5]);
  }
};

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//--------------------------   Validity of a Hexahedron         ---------------------------------------
//-----------------------------------------------------------------------------------------------------

template<typename T>
  inline void copyHexSubBezier(T allSubBezier[5][5][5],
    T subBezier[27], int subdomain)
  {
    int i0, j0, k0;
    switch (subdomain) {
    case 0: i0 = 0; j0 = 0; k0 = 0; break;
    case 1: i0 = 2; j0 = 0; k0 = 0; break;
    case 2: i0 = 2; j0 = 2; k0 = 0; break;
    case 3: i0 = 0; j0 = 2; k0 = 0; break;
    case 4: i0 = 0; j0 = 0; k0 = 2; break;
    case 5: i0 = 2; j0 = 0; k0 = 2; break;
    case 6: i0 = 2; j0 = 2; k0 = 2; break;
    case 7: i0 = 0; j0 = 2; k0 = 2; break;
    }

    subBezier[0] = allSubBezier[i0][j0][k0];
    subBezier[1] = allSubBezier[2+i0][j0][k0];
    subBezier[2] = allSubBezier[2+i0][2+j0][k0];
    subBezier[3] = allSubBezier[i0][2+j0][k0];
    subBezier[4] = allSubBezier[i0][j0][2+k0];
    subBezier[5] = allSubBezier[2+i0][j0][2+k0];
    subBezier[6] = allSubBezier[2+i0][2+j0][2+k0];
    subBezier[7] = allSubBezier[i0][2+j0][2+k0];

    subBezier[8] = allSubBezier[1+i0][j0][k0];
    subBezier[9] = allSubBezier[2+i0][1+j0][k0];
    subBezier[10] = allSubBezier[1+i0][2+j0][k0];
    subBezier[11] = allSubBezier[i0][1+j0][k0];

    subBezier[12] = allSubBezier[i0][j0][1+k0];
    subBezier[13] = allSubBezier[2+i0][j0][1+k0];
    subBezier[14] = allSubBezier[2+i0][2+j0][1+k0];
    subBezier[15] = allSubBezier[i0][2+j0][1+k0];

    subBezier[16] = allSubBezier[1+i0][j0][2+k0];
    subBezier[17] = allSubBezier[2+i0][1+j0][2+k0];
    subBezier[18] = allSubBezier[1+i0][2+j0][2+k0];
    subBezier[19] = allSubBezier[i0][1+j0][2+k0];

    subBezier[20] = allSubBezier[1+i0][1+j0][k0];
    subBezier[21] = allSubBezier[1+i0][j0][1+k0];
    subBezier[22] = allSubBezier[2+i0][1+j0][1+k0];
    subBezier[23] = allSubBezier[1+i0][2+j0][1+k0];
    subBezier[24] = allSubBezier[i0][1+j0][1+k0];
    subBezier[25] = allSubBezier[1+i0][1+j0][2+k0];

    subBezier[26] = allSubBezier[1+i0][1+j0][1+k0];
  }

  template<typename T>
  inline void initBezierSubdivisionCoefficients(
    T bezier[27], T allSubBezier[5][5][5])
  {
    // First put the coefficients of the full domain on the grid {0,2,4}^3.
    allSubBezier[0][0][0] = bezier[0];
    allSubBezier[4][0][0] = bezier[1];
    allSubBezier[4][4][0] = bezier[2];
    allSubBezier[0][4][0] = bezier[3];
    allSubBezier[0][0][4] = bezier[4];
    allSubBezier[4][0][4] = bezier[5];
    allSubBezier[4][4][4] = bezier[6];
    allSubBezier[0][4][4] = bezier[7];
    allSubBezier[2][0][0] = bezier[8];
    allSubBezier[4][2][0] = bezier[9];
    allSubBezier[2][4][0] = bezier[10];
    allSubBezier[0][2][0] = bezier[11];
    allSubBezier[0][0][2] = bezier[12];
    allSubBezier[4][0][2] = bezier[13];
    allSubBezier[4][4][2] = bezier[14];
    allSubBezier[0][4][2] = bezier[15];
    allSubBezier[2][0][4] = bezier[16];
    allSubBezier[4][2][4] = bezier[17];
    allSubBezier[2][4][4] = bezier[18];
    allSubBezier[0][2][4] = bezier[19];
    allSubBezier[2][2][0] = bezier[20];
    allSubBezier[2][0][2] = bezier[21];
    allSubBezier[4][2][2] = bezier[22];
    allSubBezier[2][4][2] = bezier[23];
    allSubBezier[0][2][2] = bezier[24];
    allSubBezier[2][2][4] = bezier[25];
    allSubBezier[2][2][2] = bezier[26];
  }

  inline void precomputeBezierSubdivisionCoefficients(BezierCoefficient *allSubBezier[5][5][5],
    BezierCoefficient *newlyAllocated)
  {
    HXTIndex numCoeffs = 0;

    // Then use De Casteljau algorithm to fill the holes.
    // computing {0,2,4}^2 x {0,1,2,3,4}
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        allSubBezier[i][j][1] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][j][0], allSubBezier[i][j][2]);
        allSubBezier[i][j][3] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][j][2], allSubBezier[i][j][4]);
        allSubBezier[i][j][2] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][j][1], allSubBezier[i][j][3]);
      }
    }
    // computing {0,2,4} x {0,1,2,3,4}^2
    for (int i = 0; i < 5; i += 2) {
      for (int k = 0; k < 5; ++k) {
        allSubBezier[i][1][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][0][k], allSubBezier[i][2][k]);
        allSubBezier[i][3][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][2][k], allSubBezier[i][4][k]);
        allSubBezier[i][2][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[i][1][k], allSubBezier[i][3][k]);
      }
    }
    // computing {0,1,2,3,4}^3
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        allSubBezier[1][j][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[0][j][k], allSubBezier[2][j][k]);
        allSubBezier[3][j][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[2][j][k], allSubBezier[4][j][k]);
        allSubBezier[2][j][k] = newlyAllocated[numCoeffs++].setAverage(
          allSubBezier[1][j][k], allSubBezier[3][j][k]);
      }
    }
  }

  inline void precomputeBezierSubdivisionCoefficients(double allSubBezier[5][5][5])
  {
    // Then use De Casteljau algorithm to fill the holes.
    // computing {0,2,4}^2 x {0,1,2,3,4}
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        allSubBezier[i][j][1] = .5 * (allSubBezier[i][j][0] +
          allSubBezier[i][j][2]);
        allSubBezier[i][j][3] = .5 * (allSubBezier[i][j][2] +
          allSubBezier[i][j][4]);
        allSubBezier[i][j][2] = .5 * (allSubBezier[i][j][1] +
          allSubBezier[i][j][3]);
      }
    }
    // computing {0,2,4} x {0,1,2,3,4}^2
    for (int i = 0; i < 5; i += 2) {
      for (int k = 0; k < 5; ++k) {
        allSubBezier[i][1][k] = .5 * (allSubBezier[i][0][k] +
          allSubBezier[i][2][k]);
        allSubBezier[i][3][k] = .5 * (allSubBezier[i][2][k] +
          allSubBezier[i][4][k]);
        allSubBezier[i][2][k] = .5 * (allSubBezier[i][1][k] +
          allSubBezier[i][3][k]);
      }
    }
    // computing {0,1,2,3,4}^3
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        allSubBezier[1][j][k] = .5 * (allSubBezier[0][j][k] +
          allSubBezier[2][j][k]);
        allSubBezier[3][j][k] = .5 * (allSubBezier[2][j][k] +
          allSubBezier[4][j][k]);
        allSubBezier[2][j][k] = .5 * (allSubBezier[1][j][k] +
          allSubBezier[3][j][k]);
      }
    }
  }

  // Check if negative values among coefficients that are
  // true values of the Jacobian determinant
  inline bool hasNegativeTrueJacobianCoefficients(BezierCoefficient *allSubBezier[5][5][5])
  {
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        for (int k = 0; k < 5; k += 2) {
          if (allSubBezier[i][j][k]->sign() <= 0) return true;
        }
      }
    }
    return false;
  }

  inline bool hasNegativeTrueJacobianCoefficients(double allSubBezier[5][5][5])
  {
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        for (int k = 0; k < 5; k += 2) {
          if (allSubBezier[i][j][k] <= 0) return true;
        }
      }
    }
    return false;
  }


  inline bool hasOnlyPositiveCoefficients(BezierCoefficient *allSubBezier[5][5][5])
  {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 5; ++k) {
          if (allSubBezier[i][j][k]->sign() <= 0) return false;
        }
      }
    }
    return true;
  }

  // Coefficients after subdivision will be computed on a grid of 5x5x5.
  bool subdivideAndIsHexValid(BezierCoefficient *bezier[27], int depth)
  {
    // To prevent meaning less computations when the scaled Jacobian
    // is nearly 0.
    if (depth > 4) return false;

    BezierCoefficient *allSubBezier[5][5][5];
    BezierCoefficient newlyAllocated[147];

    initBezierSubdivisionCoefficients(bezier, allSubBezier);
    precomputeBezierSubdivisionCoefficients(allSubBezier, newlyAllocated);

    if (hasNegativeTrueJacobianCoefficients(allSubBezier)) return false;
    if (hasOnlyPositiveCoefficients(allSubBezier)) return true;

    // We have to subdivide more
    BezierCoefficient *subBezier[27];
    for (int n = 0; n < 8; ++n) {
      copyHexSubBezier(allSubBezier, subBezier, n);
      if (!subdivideAndIsHexValid(subBezier, depth+1)) return false;
    }
    return true;
  }

  double pseudoTetVolume(const point3d&a, const point3d&b, const point3d&c, const point3d&d)
  {
    const point3d vCross = cross(b-a, c-a);
    return dot(vCross, d-a);
  }

  inline bool computeJacobian(const point3d v[8], double jacobian[20])
  {
    if ((jacobian[0] = pseudoTetVolume(v[0], v[1], v[3], v[4])) <= 0) return false;
    if ((jacobian[1] = pseudoTetVolume(v[1], v[2], v[0], v[5])) <= 0) return false;
    if ((jacobian[2] = pseudoTetVolume(v[2], v[3], v[1], v[6])) <= 0) return false;
    if ((jacobian[3] = pseudoTetVolume(v[3], v[0], v[2], v[7])) <= 0) return false;

    if ((jacobian[4] = pseudoTetVolume(v[4], v[7], v[5], v[0])) <= 0) return false;
    if ((jacobian[5] = pseudoTetVolume(v[5], v[4], v[6], v[1])) <= 0) return false;
    if ((jacobian[6] = pseudoTetVolume(v[6], v[5], v[7], v[2])) <= 0) return false;
    if ((jacobian[7] = pseudoTetVolume(v[7], v[6], v[4], v[3])) <= 0) return false;

    if ((jacobian[8] = pseudoTetVolume(v[0], v[1], .5*(v[2]+v[3]), .5*(v[4]+v[5]))) <= 0) return false;
    if ((jacobian[9] = pseudoTetVolume(v[1], v[2], .5*(v[3]+v[0]), .5*(v[5]+v[6]))) <= 0) return false;
    if ((jacobian[10] = pseudoTetVolume(v[2], v[3], .5*(v[0]+v[1]), .5*(v[6]+v[7]))) <= 0) return false;
    if ((jacobian[11] = pseudoTetVolume(v[3], v[0], .5*(v[1]+v[2]), .5*(v[7]+v[4]))) <= 0) return false;

    if ((jacobian[12] = pseudoTetVolume(v[0], v[4], .5*(v[1]+v[5]), .5*(v[3]+v[7]))) <= 0) return false;
    if ((jacobian[13] = pseudoTetVolume(v[1], v[5], .5*(v[2]+v[6]), .5*(v[0]+v[4]))) <= 0) return false;
    if ((jacobian[14] = pseudoTetVolume(v[2], v[6], .5*(v[3]+v[7]), .5*(v[1]+v[5]))) <= 0) return false;
    if ((jacobian[15] = pseudoTetVolume(v[3], v[7], .5*(v[0]+v[4]), .5*(v[2]+v[6]))) <= 0) return false;

    if ((jacobian[16] = pseudoTetVolume(v[4], v[5], .5*(v[0]+v[1]), .5*(v[6]+v[7]))) <= 0) return false;
    if ((jacobian[17] = pseudoTetVolume(v[5], v[6], .5*(v[1]+v[2]), .5*(v[7]+v[4]))) <= 0) return false;
    if ((jacobian[18] = pseudoTetVolume(v[6], v[7], .5*(v[2]+v[3]), .5*(v[4]+v[5]))) <= 0) return false;
    if ((jacobian[19] = pseudoTetVolume(v[7], v[4], .5*(v[3]+v[0]), .5*(v[5]+v[6]))) <= 0) return false;

    return true;
  }

  inline bool computeJacobian(const point3d v[8], BezierCoefficient jacobian[20])
  {
    if (jacobian[0].setTetVolume(0, v, 0, 1, 3, 4)->sign() <= 0) return false;
    if (jacobian[1].setTetVolume(1, v, 1, 2, 0, 5)->sign() <= 0) return false;
    if (jacobian[2].setTetVolume(2, v, 2, 3, 1, 6)->sign() <= 0) return false;
    if (jacobian[3].setTetVolume(3, v, 3, 0, 2, 7)->sign() <= 0) return false;

    if (jacobian[4].setTetVolume(4, v, 4, 7, 5, 0)->sign() <= 0) return false;
    if (jacobian[5].setTetVolume(5, v, 5, 4, 6, 1)->sign() <= 0) return false;
    if (jacobian[6].setTetVolume(6, v, 6, 5, 7, 2)->sign() <= 0) return false;
    if (jacobian[7].setTetVolume(7, v, 7, 6, 4, 3)->sign() <= 0) return false;

    if (jacobian[8].setTetVolumeMidpoint(8, v, 0, 1, 2, 3, 4, 5)->sign() <= 0) return false;
    if (jacobian[9].setTetVolumeMidpoint(9, v, 1, 2, 3, 0, 5, 6)->sign() <= 0) return false;
    if (jacobian[10].setTetVolumeMidpoint(10, v, 2, 3, 0, 1, 6, 7)->sign() <= 0) return false;
    if (jacobian[11].setTetVolumeMidpoint(11, v, 3, 0, 1, 2, 7, 4)->sign() <= 0) return false;

    if (jacobian[12].setTetVolumeMidpoint(12, v, 0, 4, 1, 5, 3, 7)->sign() <= 0) return false;
    if (jacobian[13].setTetVolumeMidpoint(13, v, 1, 5, 2, 6, 0, 4)->sign() <= 0) return false;
    if (jacobian[14].setTetVolumeMidpoint(14, v, 2, 6, 3, 7, 1, 5)->sign() <= 0) return false;
    if (jacobian[15].setTetVolumeMidpoint(15, v, 3, 7, 0, 4, 2, 6)->sign() <= 0) return false;

    if (jacobian[16].setTetVolumeMidpoint(16, v, 4, 5, 0, 1, 6, 7)->sign() <= 0) return false;
    if (jacobian[17].setTetVolumeMidpoint(17, v, 5, 6, 1, 2, 7, 4)->sign() <= 0) return false;
    if (jacobian[18].setTetVolumeMidpoint(18, v, 6, 7, 2, 3, 4, 5)->sign() <= 0) return false;
    if (jacobian[19].setTetVolumeMidpoint(19, v, 7, 4, 3, 0, 5, 6)->sign() <= 0) return false;

    return true;
  }

  inline void computeBezierCoefficients(const double jacobian[20], double bezier[27])
  {
    for (int i = 0; i < 8; ++i) bezier[i] = jacobian[i];
    for (int i = 8; i < 12; ++i) bezier[i] = 2*jacobian[i] -
      .5*(jacobian[i-8]+jacobian[(i-7)%4]);
    for (int i = 12; i < 16; ++i) bezier[i] = 2*jacobian[i] -
      .5*(jacobian[i-12]+jacobian[i-8]);
    for (int i = 16; i < 20; ++i) bezier[i] = 2*jacobian[i] -
      .5*(jacobian[i-12]+jacobian[4+(i-15)%4]);

    bezier[20] = jacobian[8]+jacobian[9]+jacobian[10]+jacobian[11]
      - 3/4. * (jacobian[0]+jacobian[1]+jacobian[2]+jacobian[3]);
    for (int i = 21; i < 25; ++i) {
      bezier[i] = jacobian[i-13]+jacobian[i-9]+jacobian[12+(i-20)%4]+jacobian[i-5]
        - 3/4. * (jacobian[i-21]+jacobian[i-17]+jacobian[(i-20)%4]+jacobian[4+(i-20)%4]);
    }
    bezier[25] = jacobian[16]+jacobian[17]+jacobian[18]+jacobian[19]
      - 3/4. * (jacobian[4]+jacobian[5]+jacobian[6]+jacobian[7]);

    bezier[26] = 0;
    for (int k = 0; k < 8; ++k) bezier[26] += jacobian[k];
    bezier[26] *= -5/4.;
    for (int k = 8; k < 20; ++k) bezier[26] += jacobian[k];
    bezier[26] /= 2;
  }

  inline void computeBezierCoefficients(BezierCoefficient *jacobian, BezierCoefficient **bezier)
  {
    int numCoeff = 20;

    for (int i = 0; i < 8; ++i) bezier[i] = &jacobian[i];

    static constexpr double errCoeff1 = (30*DBL_EPSILON/2 + 3)*(DBL_EPSILON/2);

    for (int i = 8; i < 12; ++i) {
      bezier[i] = jacobian[numCoeff++].setValue(
        20 + i, jacobian,
        2*jacobian[i].value() - .5*(jacobian[i-8].value()+jacobian[(i-7)%4].value()),
        errCoeff1 * (2*std::abs(jacobian[i].value()) +
          0.5*(std::abs(jacobian[i-8].value()) +
            std::abs(jacobian[(i-7)%4].value()))) +
            (1 + errCoeff1) * (2*std::abs(jacobian[i].errorBound()) +
              0.5*(std::abs(jacobian[i-8].errorBound()) +
                std::abs(jacobian[(i-7)%4].errorBound()))));
    }

    for (int i = 12; i < 16; ++i) {
      bezier[i] = jacobian[numCoeff++].setValue(
        20 + i, jacobian,
        2*jacobian[i].value() - .5*(jacobian[i-12].value()+jacobian[i-8].value()),
        errCoeff1 * (2*std::abs(jacobian[i].value()) +
          0.5*(std::abs(jacobian[i-12].value()) +
            std::abs(jacobian[i-8].value()))) +
            (1 + errCoeff1) * (2*std::abs(jacobian[i].errorBound()) +
              0.5*(std::abs(jacobian[i-12].errorBound()) +
                std::abs(jacobian[i-8].errorBound()))));
    }

    for (int i = 16; i < 20; ++i) {
      bezier[i] = jacobian[numCoeff++].setValue(
        20 + i, jacobian,
        2*jacobian[i].value() - .5*(jacobian[i-12].value()+jacobian[4+(i-15)%4].value()),
        errCoeff1 * (2*std::abs(jacobian[i].value()) +
          0.5*(std::abs(jacobian[i-12].value()) +
            std::abs(jacobian[4+(i-15)%4].value()))) +
            (1 + errCoeff1) * (2*std::abs(jacobian[i].errorBound()) +
              0.5*(std::abs(jacobian[i-12].errorBound()) +
                std::abs(jacobian[4+(i-15)%4].errorBound()))));
    }

    static constexpr double errCoeff2 = (44*DBL_EPSILON/2 + 4)*(DBL_EPSILON/2);

    bezier[20] = jacobian[numCoeff++].setValue(
      20 + 20, jacobian,
      ((jacobian[8].value() + jacobian[9].value()) +
      (jacobian[10].value() + jacobian[11].value())) -
      3/4.0*((jacobian[0].value() + jacobian[1].value()) +
      (jacobian[2].value() + jacobian[3].value())),
      errCoeff2 * (((std::abs(jacobian[8].value())  + std::abs(jacobian[9].value())) +
      (std::abs(jacobian[10].value()) + std::abs(jacobian[11].value()))) +
        3/4.0*((std::abs(jacobian[0].value()) + std::abs(jacobian[1].value())) +
        (std::abs(jacobian[2].value()) + std::abs(jacobian[3].value())))) +
          (1 + errCoeff2) * (((jacobian[8].errorBound() + jacobian[9].errorBound()) +
      (jacobian[10].errorBound() + jacobian[11].errorBound())) +
            3/4.0*((jacobian[0].errorBound() + jacobian[1].errorBound()) +
            (jacobian[2].errorBound() + jacobian[3].errorBound()))));

    for (int i = 21; i < 25; ++i) {
      bezier[i] = jacobian[numCoeff++].setValue(
        20 + i, jacobian,
        ((jacobian[i-13].value() + jacobian[i-9].value()) +
        (jacobian[12+(i-20)%4].value() + jacobian[i-5].value())) -
        3/4.0*((jacobian[i-21].value() + jacobian[i-17].value()) +
        (jacobian[(i-20)%4].value() + jacobian[4+(i-20)%4].value())),
        errCoeff2 * (((std::abs(jacobian[i-13].value())  + std::abs(jacobian[i-9].value())) +
        (std::abs(jacobian[12+(i-20)%4].value()) + std::abs(jacobian[i-5].value()))) +
          3/4.0*((std::abs(jacobian[i-21].value()) + std::abs(jacobian[i-17].value())) +
          (std::abs(jacobian[(i-20)%4].value()) + std::abs(jacobian[4+(i-20)%4].value())))) +
            (1 + errCoeff2) * (((jacobian[i-13].errorBound() + jacobian[i-9].errorBound()) +
        (jacobian[12+(i-20)%4].errorBound() + jacobian[i-5].errorBound())) +
              3/4.0*((jacobian[i-21].errorBound() + jacobian[i-17].errorBound()) +
              (jacobian[(i-20)%4].errorBound() + jacobian[4+(i-20)%4].errorBound()))));
    }

    bezier[25] = jacobian[numCoeff++].setValue(
      20 + 25, jacobian,
      ((jacobian[16].value() + jacobian[17].value()) +
      (jacobian[18].value() + jacobian[19].value())) -
      3/4.0*((jacobian[4].value() + jacobian[5].value()) +
      (jacobian[6].value() + jacobian[7].value())),
      errCoeff2 * (((std::abs(jacobian[16].value())  + std::abs(jacobian[17].value())) +
      (std::abs(jacobian[18].value()) + std::abs(jacobian[19].value()))) +
        3/4.0*((std::abs(jacobian[4].value()) + std::abs(jacobian[5].value())) +
        (std::abs(jacobian[6].value()) + std::abs(jacobian[7].value())))) +
          (1 + errCoeff2) * (((jacobian[16].errorBound() + jacobian[17].errorBound()) +
      (jacobian[18].errorBound() + jacobian[19].errorBound())) +
            3/4.0*((jacobian[4].errorBound() + jacobian[5].errorBound()) +
            (jacobian[6].errorBound() + jacobian[7].errorBound()))));

    double value = 0.0;
    double boundA = 0.0, boundB = 0.0;

    for (int k = 0; k < 8; ++k) {
      value += jacobian[k].value();
      boundA += std::abs(jacobian[k].value());
      boundB += jacobian[k].errorBound();
    }

    value *= -5/4.0;
    boundA *= 5/4.0;
    boundB *= 5/4.0;

    for (int k = 8; k < 20; ++k) {
      value += jacobian[k].value();
      boundA += std::abs(jacobian[k].value());
      boundB += jacobian[k].errorBound();
    }

    value *= 0.5;
    boundA *= 0.5;
    boundB *= 0.5;

    static constexpr double errCoeff3 = (262*(DBL_EPSILON/2) + 12)*(DBL_EPSILON/2);

    bezier[26] = jacobian[numCoeff++].setValue(
      20 + 26, jacobian,
      value, errCoeff3 * boundA + (1 + errCoeff3)*boundB);
  }

  inline void copyHexSubDxdxi(double allSubDxdxi[3][3][9],
    double subDxdxi[3][3][4], int subdomain)
  {
    int nxi[3];
    switch (subdomain) {
    case 0: nxi[0] = 0; nxi[1] = 0; nxi[2] = 0; break;
    case 1: nxi[0] = 0; nxi[1] = 3; nxi[2] = 1; break;
    case 2: nxi[0] = 1; nxi[1] = 3; nxi[2] = 2; break;
    case 3: nxi[0] = 1; nxi[1] = 0; nxi[2] = 3; break;
    case 4: nxi[0] = 3; nxi[1] = 1; nxi[2] = 0; break;
    case 5: nxi[0] = 3; nxi[1] = 2; nxi[2] = 1; break;
    case 6: nxi[0] = 2; nxi[1] = 2; nxi[2] = 2; break;
    case 7: nxi[0] = 2; nxi[1] = 1; nxi[2] = 3; break;
    }

    for (int j = 0; j < 3; ++j) {
      switch (nxi[j]) {
      case 0:
        for (int i = 0; i < 3; ++i) {
          subDxdxi[i][j][0] = allSubDxdxi[i][j][0];
          subDxdxi[i][j][1] = allSubDxdxi[i][j][4];
          subDxdxi[i][j][2] = allSubDxdxi[i][j][8];
          subDxdxi[i][j][3] = allSubDxdxi[i][j][7];
        }
        break;
      case 1:
        for (int i = 0; i < 3; ++i) {
          subDxdxi[i][j][0] = allSubDxdxi[i][j][4];
          subDxdxi[i][j][1] = allSubDxdxi[i][j][1];
          subDxdxi[i][j][2] = allSubDxdxi[i][j][5];
          subDxdxi[i][j][3] = allSubDxdxi[i][j][8];
        }
        break;
      case 2:
        for (int i = 0; i < 3; ++i) {
          subDxdxi[i][j][0] = allSubDxdxi[i][j][8];
          subDxdxi[i][j][1] = allSubDxdxi[i][j][5];
          subDxdxi[i][j][2] = allSubDxdxi[i][j][2];
          subDxdxi[i][j][3] = allSubDxdxi[i][j][6];
        }
        break;
      case 3:
        for (int i = 0; i < 3; ++i) {
          subDxdxi[i][j][0] = allSubDxdxi[i][j][7];
          subDxdxi[i][j][1] = allSubDxdxi[i][j][8];
          subDxdxi[i][j][2] = allSubDxdxi[i][j][6];
          subDxdxi[i][j][3] = allSubDxdxi[i][j][3];
        }
        break;
      }
    }
  }

  inline void precomputeSubdivisionDxdxiCoefficients(double dxdxi[3][3][4],
    double allSubDxdxi[3][3][9])
  {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        allSubDxdxi[i][j][0] = dxdxi[i][j][0];
        allSubDxdxi[i][j][1] = dxdxi[i][j][1];
        allSubDxdxi[i][j][2] = dxdxi[i][j][2];
        allSubDxdxi[i][j][3] = dxdxi[i][j][3];

        allSubDxdxi[i][j][4] = .5 * (dxdxi[i][j][0] + dxdxi[i][j][1]);
        allSubDxdxi[i][j][5] = .5 * (dxdxi[i][j][1] + dxdxi[i][j][2]);
        allSubDxdxi[i][j][6] = .5 * (dxdxi[i][j][2] + dxdxi[i][j][3]);
        allSubDxdxi[i][j][7] = .5 * (dxdxi[i][j][3] + dxdxi[i][j][0]);

        allSubDxdxi[i][j][8] = .5 * (allSubDxdxi[i][j][4] +
          allSubDxdxi[i][j][6]);
      }
    }
  }

  inline void computePartialDerivatives(const point3d v[8],
    double dxyzdxi[3][3][4])
  {
    // d.dxi
    dxyzdxi[0][0][0] = v[1].x - v[0].x;
    dxyzdxi[1][0][0] = v[1].y - v[0].y;
    dxyzdxi[2][0][0] = v[1].z - v[0].z;
    dxyzdxi[0][0][1] = v[2].x - v[3].x;
    dxyzdxi[1][0][1] = v[2].y - v[3].y;
    dxyzdxi[2][0][1] = v[2].z - v[3].z;
    dxyzdxi[0][0][2] = v[6].x - v[7].x;
    dxyzdxi[1][0][2] = v[6].y - v[7].y;
    dxyzdxi[2][0][2] = v[6].z - v[7].z;
    dxyzdxi[0][0][3] = v[5].x - v[4].x;
    dxyzdxi[1][0][3] = v[5].y - v[4].y;
    dxyzdxi[2][0][3] = v[5].z - v[4].z;
    // d.deta
    dxyzdxi[0][1][0] = v[3].x - v[0].x;
    dxyzdxi[1][1][0] = v[3].y - v[0].y;
    dxyzdxi[2][1][0] = v[3].z - v[0].z;
    dxyzdxi[0][1][1] = v[7].x - v[4].x;
    dxyzdxi[1][1][1] = v[7].y - v[4].y;
    dxyzdxi[2][1][1] = v[7].z - v[4].z;
    dxyzdxi[0][1][2] = v[6].x - v[5].x;
    dxyzdxi[1][1][2] = v[6].y - v[5].y;
    dxyzdxi[2][1][2] = v[6].z - v[5].z;
    dxyzdxi[0][1][3] = v[2].x - v[1].x;
    dxyzdxi[1][1][3] = v[2].y - v[1].y;
    dxyzdxi[2][1][3] = v[2].z - v[1].z;
    // d.dzeta
    dxyzdxi[0][2][0] = v[4].x - v[0].x;
    dxyzdxi[1][2][0] = v[4].y - v[0].y;
    dxyzdxi[2][2][0] = v[4].z - v[0].z;
    dxyzdxi[0][2][1] = v[5].x - v[1].x;
    dxyzdxi[1][2][1] = v[5].y - v[1].y;
    dxyzdxi[2][2][1] = v[5].z - v[1].z;
    dxyzdxi[0][2][2] = v[6].x - v[2].x;
    dxyzdxi[1][2][2] = v[6].y - v[2].y;
    dxyzdxi[2][2][2] = v[6].z - v[2].z;
    dxyzdxi[0][2][3] = v[7].x - v[3].x;
    dxyzdxi[1][2][3] = v[7].y - v[3].y;
    dxyzdxi[2][2][3] = v[7].z - v[3].z;
  }

  inline void computeUpperBoundingFunctions(double dxdxi[3][3][4],
    double Vj[3][4])
  {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; ++j) {
        Vj[i][j] = sqrt(dxdxi[0][i][j] * dxdxi[0][i][j] +
          dxdxi[1][i][j] * dxdxi[1][i][j] +
          dxdxi[2][i][j] * dxdxi[2][i][j]);
      }
    }
  }

  inline void computeBezierCoeffDenominator(double Vj[3][4], double coeff[27])
  {
    coeff[0] = Vj[0][0] * Vj[1][0] * Vj[2][0];
    coeff[1] = Vj[0][0] * Vj[1][3] * Vj[2][1];
    coeff[2] = Vj[0][1] * Vj[1][3] * Vj[2][2];
    coeff[3] = Vj[0][1] * Vj[1][0] * Vj[2][3];

    coeff[4] = Vj[0][3] * Vj[1][1] * Vj[2][0];
    coeff[5] = Vj[0][3] * Vj[1][2] * Vj[2][1];
    coeff[6] = Vj[0][2] * Vj[1][2] * Vj[2][2];
    coeff[7] = Vj[0][2] * Vj[1][1] * Vj[2][3];

    coeff[8] = .5 * (Vj[0][0] * Vj[1][0] * Vj[2][1] +
      Vj[0][0] * Vj[1][3] * Vj[2][0]);
    coeff[9] = .5 * (Vj[0][0] * Vj[1][3] * Vj[2][2] +
      Vj[0][1] * Vj[1][3] * Vj[2][1]);
    coeff[10] = .5 * (Vj[0][1] * Vj[1][0] * Vj[2][2] +
      Vj[0][1] * Vj[1][3] * Vj[2][3]);
    coeff[11] = .5 * (Vj[0][0] * Vj[1][0] * Vj[2][3] +
      Vj[0][1] * Vj[1][0] * Vj[2][0]);

    coeff[12] = .5 * (Vj[0][0] * Vj[1][1] * Vj[2][0] +
      Vj[0][3] * Vj[1][0] * Vj[2][0]);
    coeff[13] = .5 * (Vj[0][0] * Vj[1][2] * Vj[2][1] +
      Vj[0][3] * Vj[1][3] * Vj[2][1]);
    coeff[14] = .5 * (Vj[0][1] * Vj[1][2] * Vj[2][2] +
      Vj[0][2] * Vj[1][3] * Vj[2][2]);
    coeff[15] = .5 * (Vj[0][1] * Vj[1][1] * Vj[2][3] +
      Vj[0][2] * Vj[1][0] * Vj[2][3]);

    coeff[16] = .5 * (Vj[0][3] * Vj[1][1] * Vj[2][1] +
      Vj[0][3] * Vj[1][2] * Vj[2][0]);
    coeff[17] = .5 * (Vj[0][3] * Vj[1][2] * Vj[2][2] +
      Vj[0][2] * Vj[1][2] * Vj[2][1]);
    coeff[18] = .5 * (Vj[0][2] * Vj[1][1] * Vj[2][2] +
      Vj[0][2] * Vj[1][2] * Vj[2][3]);
    coeff[19] = .5 * (Vj[0][3] * Vj[1][1] * Vj[2][3] +
      Vj[0][2] * Vj[1][1] * Vj[2][0]);

    coeff[20] = .25 * (Vj[0][1] * Vj[1][3] * Vj[2][0] +
      Vj[0][1] * Vj[1][0] * Vj[2][1] +
      Vj[0][0] * Vj[1][0] * Vj[2][2] +
      Vj[0][0] * Vj[1][3] * Vj[2][3]);

    coeff[21] = .25 * (Vj[0][3] * Vj[1][0] * Vj[2][1] +
      Vj[0][0] * Vj[1][1] * Vj[2][1] +
      Vj[0][0] * Vj[1][2] * Vj[2][0] +
      Vj[0][3] * Vj[1][3] * Vj[2][0]);
    coeff[22] = .25 * (Vj[0][0] * Vj[1][2] * Vj[2][2] +
      Vj[0][1] * Vj[1][2] * Vj[2][1] +
      Vj[0][2] * Vj[1][3] * Vj[2][1] +
      Vj[0][3] * Vj[1][3] * Vj[2][2]);
    coeff[23] = .25 * (Vj[0][2] * Vj[1][0] * Vj[2][2] +
      Vj[0][1] * Vj[1][1] * Vj[2][2] +
      Vj[0][1] * Vj[1][2] * Vj[2][3] +
      Vj[0][2] * Vj[1][3] * Vj[2][3]);
    coeff[24] = .25 * (Vj[0][0] * Vj[1][1] * Vj[2][3] +
      Vj[0][1] * Vj[1][1] * Vj[2][0] +
      Vj[0][2] * Vj[1][0] * Vj[2][0] +
      Vj[0][3] * Vj[1][0] * Vj[2][3]);

    coeff[25] = .25 * (Vj[0][2] * Vj[1][2] * Vj[2][0] +
      Vj[0][2] * Vj[1][1] * Vj[2][1] +
      Vj[0][3] * Vj[1][1] * Vj[2][2] +
      Vj[0][3] * Vj[1][2] * Vj[2][3]);

    coeff[26] = .125 * (Vj[0][0] * Vj[1][1] * Vj[2][2] +
      Vj[0][0] * Vj[1][2] * Vj[2][3] +
      Vj[0][1] * Vj[1][1] * Vj[2][1] +
      Vj[0][1] * Vj[1][2] * Vj[2][0] +
      Vj[0][2] * Vj[1][0] * Vj[2][1] +
      Vj[0][2] * Vj[1][3] * Vj[2][0] +
      Vj[0][3] * Vj[1][0] * Vj[2][2] +
      Vj[0][3] * Vj[1][3] * Vj[2][3]);
  }

  double computeBoundRational(double numerator[27], double denominator[27])
  {
    double upperBound = 1;
    double lowerBound = 0;

    // we seek: bound * den <= num
    for (int i = 0; i < 27; ++i) {
      if (denominator[i] == 0) {
        if (numerator[i] < 0) return 0;
      }
      else if (denominator[i] > 0)
        upperBound = std::min(upperBound, numerator[i]/denominator[i]);
      else
        lowerBound = std::max(lowerBound, numerator[i]/denominator[i]);
    }
    if (lowerBound > upperBound)
      return 0;
    else
      return upperBound;
  }

  void computeBoundsScaledJacobian(double numerator[27], double dxdxi[3][3][4],
    double &lowerBound, double &upperBound)
  {
    double Vj[3][4];
    computeUpperBoundingFunctions(dxdxi, Vj);
    double denominator[27];
    computeBezierCoeffDenominator(Vj, denominator);

    upperBound = 1;
    for (int i = 0; i < 8; ++i) {
      upperBound = std::min(upperBound, numerator[i]/denominator[i]);
    }
    lowerBound = computeBoundRational(numerator, denominator);
  }

  void subdivideAndHexQuality(double numerator[27],
    double dxdxi[3][3][4], int depth,
    double &globalLowerBound,
    double &globalUpperBound)
  {
    double allSubBezier[5][5][5];
    initBezierSubdivisionCoefficients(numerator, allSubBezier);
    precomputeBezierSubdivisionCoefficients(allSubBezier);
    if (hasNegativeTrueJacobianCoefficients(allSubBezier)) {
      globalLowerBound = 0;
      globalUpperBound = 0;
      return;
    }

    // We have to subdivide more
    double subNumerator[27];
    double subDxdxi[3][3][4];
    double allSubDxdxi[3][3][9];
    precomputeSubdivisionDxdxiCoefficients(dxdxi, allSubDxdxi);

    globalLowerBound = globalUpperBound;
    for (int n = 0; n < 8; ++n) {
      copyHexSubBezier(allSubBezier, subNumerator, n);
      copyHexSubDxdxi(allSubDxdxi, subDxdxi, n);

      double lowerBound, upperBound;
      computeBoundsScaledJacobian(subNumerator, subDxdxi, lowerBound, upperBound);
      globalUpperBound = std::min(globalUpperBound, upperBound);

      if (globalUpperBound - lowerBound > 1e-3) {
        subdivideAndHexQuality(subNumerator, subDxdxi, depth+1,
          lowerBound, globalUpperBound);
      }
      globalLowerBound = std::min(globalLowerBound, lowerBound);
    }
  }


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//--------------------------Validity computation of a Prism  ------------------------------------------
//-----------------------------------------------------------------------------------------------------

  inline void copyPrismSubBezier(
    double allSubBezier[15], double subBezier[9], int subdomain)
  {
    int i0 = 0;
    if (subdomain > 0) i0 = 6;

    subBezier[0] = allSubBezier[i0];
    subBezier[1] = allSubBezier[i0+1];
    subBezier[2] = allSubBezier[i0+2];

    subBezier[3] = allSubBezier[i0+6];
    subBezier[4] = allSubBezier[i0+7];
    subBezier[5] = allSubBezier[i0+8];

    subBezier[6] = allSubBezier[i0+3];
    subBezier[7] = allSubBezier[i0+4];
    subBezier[8] = allSubBezier[i0+5];
  }

  inline void initBezierSubdivisionCoefficientsPrism(
    const double bezier[9], double allSubBezier[15])
  {
    allSubBezier[0] = bezier[0];
    allSubBezier[1] = bezier[1];
    allSubBezier[2] = bezier[2];
    allSubBezier[12] = bezier[3];
    allSubBezier[13] = bezier[4];
    allSubBezier[14] = bezier[5];
    allSubBezier[6] = bezier[6];
    allSubBezier[7] = bezier[7];
    allSubBezier[8] = bezier[8];
  }

  inline void precomputeBezierSubdivisionCoefficientsPrism(double allSubBezier[15])
  {
    // Use De Casteljau algorithm to fill the holes.
    for (int i = 0; i < 3; i++) {
      allSubBezier[i+3] = .5 * (allSubBezier[i] + allSubBezier[i+6]);
      allSubBezier[i+9] = .5 * (allSubBezier[i+6] + allSubBezier[i+12]);
      allSubBezier[i+6] = .5 * (allSubBezier[i+3] + allSubBezier[i+9]);
    }
  }

  inline bool hasNegativeTrueJacobianCoefficientsPrism(const double allSubBezier[15])
  {
    for (int i = 6; i < 9; i++) {
      if (allSubBezier[i] <= 0) return true;
    }
    return false;
  }

  inline bool hasOnlyPositiveCoefficientsPrism(const double allSubBezier[15])
  {
    for (int i = 0; i < 15; ++i) {
      if (allSubBezier[i] <= 0) return false;
    }
    return true;
  }

  bool subdivideAndIsPrismValid(double bezier[9], int depth)
  {
    if (depth > 9) return false;

    // Coefficients in allSubBezier are put in this order:
    // the three at the basis, the three just above, the three in the middle, ...
    double allSubBezier[15];

    initBezierSubdivisionCoefficientsPrism(bezier, allSubBezier);

    precomputeBezierSubdivisionCoefficientsPrism(allSubBezier);

    if (hasNegativeTrueJacobianCoefficientsPrism(allSubBezier)) return false;
    if (hasOnlyPositiveCoefficientsPrism(allSubBezier)) return true;

    // We have to subdivide more
    double subBezier[9];

    for (int n = 0; n < 2; ++n) {
      copyPrismSubBezier(allSubBezier, subBezier, n);
      if (!subdivideAndIsPrismValid(subBezier, depth+1)) return false;
    }
    return true;
  }

  inline void computeJacobianPrism(const point3d v[6], double jacobian[9])
  {
    jacobian[0] = pseudoTetVolume(v[0], v[1], v[2], v[3]);
    jacobian[1] = pseudoTetVolume(v[1], v[2], v[0], v[4]);
    jacobian[2] = pseudoTetVolume(v[2], v[0], v[1], v[5]);

    jacobian[3] = pseudoTetVolume(v[3], v[5], v[4], v[0]);
    jacobian[4] = pseudoTetVolume(v[4], v[3], v[5], v[1]);
    jacobian[5] = pseudoTetVolume(v[5], v[4], v[3], v[2]);

    jacobian[6] = pseudoTetVolume(v[0], v[3], .5*(v[1]+v[4]), .5*(v[2]+v[5]));
    jacobian[7] = pseudoTetVolume(v[1], v[4], .5*(v[2]+v[5]), .5*(v[0]+v[3]));
    jacobian[8] = pseudoTetVolume(v[2], v[5], .5*(v[0]+v[3]), .5*(v[1]+v[4]));
  }

  inline void computeBezierCoefficientsPrism(const double jacobian[9], double bezier[9])
  {
    for (int i = 0; i < 6; ++i) {
      bezier[i] = jacobian[i];
    }
    for (int i = 6; i < 9; ++i) {
      bezier[i] = 2*jacobian[i] - .5*(jacobian[i-6]+jacobian[i-3]);
    }
  }

} // anonymous namespace


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//                  API   FUNCTION    IMPLEMENTATIONS                                                 
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

// Solve the ambiguity with the point3d that is omnipresent in module Combine
// This dependancy is TO REMOVE, solving the problem.
using ::point3d;


bool pyramidValidityNotImplemented(const point3d* pointCoordinates) {
  return true; 
}

/** 
 * Not robust to floating point errors
 */
bool prismValidity(const point3d* pointCoordinates)
{
  double jacobian[9];
  computeJacobianPrism(pointCoordinates, jacobian);

  for (int i = 0; i < 9; ++i) {
    if (jacobian[i] <= 0) return false;
  }

  double bezier[9];
  computeBezierCoefficientsPrism(jacobian, bezier);

  double minBezier = *std::min_element(bezier, bezier+9);
  if (minBezier > 0) return true;

  return subdivideAndIsPrismValid(bezier, 1);
}

/**
  * \returns False if there is one point inside the hexahedron where the Jacobian is negative or zero
  *          otherwise returns True
  * Implementation is robust to floating point errors.
  */
bool hexExactValidity(const point3d* pointCoordinates)
{
  BezierCoefficient jacobian[20 + (27-8)];
  BezierCoefficient *bezier[27];

  if (!computeJacobian(pointCoordinates, jacobian)) {
    return false;
  }
  computeBezierCoefficients(jacobian, bezier);

  HXTIndex i;
  for (i = 0; i < 27; i++) {
    if (bezier[i]->sign() <= 0) break;
  }
  if (i == 27) return true;

  // No answer yet. Subdivide until we get one negative Jacobian value
  // or all positive Bezier coefficients
  return subdivideAndIsHexValid(bezier, 1);
}

/**
   * \returns Zero if invalid otherwise the minimal scaled
   * Jacobian value over the hex.
 */
double hexSubdivisionBasedQuality(const point3d* pointCoordinates)
{
  double jacobian[20];
  if (!computeJacobian(pointCoordinates, jacobian)) return 0;

  double numerator[27];
  computeBezierCoefficients(jacobian, numerator);

  double dxdxi[3][3][4];
  computePartialDerivatives(pointCoordinates, dxdxi);

  double lowerBound, upperBound;
  computeBoundsScaledJacobian(numerator, dxdxi, lowerBound, upperBound);

  if (upperBound - lowerBound > 1e-3)
    subdivideAndHexQuality(numerator, dxdxi, 1, lowerBound, upperBound);

  return .5 * (lowerBound + upperBound);
}


bool hxtValidityHexahedron(
  const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5, const double* p6, const double* p7) 
{
  point3d points[8];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);
  points[5].setData(p5);
  points[6].setData(p6);
  points[7].setData(p7);

  return hexExactValidity(points);
}

bool hxtValidityPrism(
  const double* p0, const double* p1, const double* p2,
  const double* p3, const double* p4, const double* p5)
{
  point3d points[6];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);
  points[5].setData(p5);

  return prismValidity(points);
}

double hxtHexSubdivisionBasedQuality(
  const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5, const double* p6, const double* p7) 
{
  point3d points[8];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);
  points[5].setData(p5);
  points[6].setData(p6);
  points[7].setData(p7);

  return hexSubdivisionBasedQuality(points);
}


bool hxtValidityPyramid(const double* p0, const double* p1, const double* p2, const double* p3, const double* p4) {
  HXT_ASSERT(false);
  // This is not implemented 
  return false;
}

bool hxtValidityTetrahedron(const double* p0, const double* p1, const double* p2, const double* p3) {
  return orient3d(p0, p1, p2, p3);
}

double hxtQualityTetrahedron(const double* p0, const double* p1, const double* p2, const double* p3)
{
  HXT_ASSERT(false);
  //std::cout << "Tetrahedron quality is to implement!!" << std::endl;
  return -1;
}

double hxtQualityPrism(const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5)
{
  point3d points[6];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);
  points[5].setData(p5);

  return cellApproximatePrismQuality(points);
}

double hxtQualityHexahedron(const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5, const double* p6, const double* p7)
{
  point3d points[8];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);
  points[5].setData(p5);
  points[6].setData(p6);
  points[7].setData(p7);

  return cellApproximateHexQuality(points);
}

double hxtQualityPyramid2(const double* p0, const double* p1, const double* p2, const double* p3, const double* p4)
{
  point3d points[5];
  points[0].setData(p0);
  points[1].setData(p1);
  points[2].setData(p2);
  points[3].setData(p3);
  points[4].setData(p4);

  return cellApproximatePyramidQuality(points);
}

//  -------   Some other code to compute the quality of pyramids -------

static double pyramidQualityAtPoint(
  const double* pt,
  const double* p0,
  const double* p1,
  const double* p2,
  const double* p3,
  const double* p4
) {

  const double u = pt[0];
  const double v = pt[1];
  const double w = pt[2];

  if (w == 1.) {
    // Error, quality not defined at summit
    return -10;
  }
  const double U = u / (1-w);
  const double V = v / (1-w);
  double dxyzdu[3] = {
      (p1[0]-p0[0]) * .25*(1-V) + (p2[0]-p3[0]) * .25*(1+V),
      (p1[1]-p0[1]) * .25*(1-V) + (p2[1]-p3[1]) * .25*(1+V),
      (p1[2]-p0[2]) * .25*(1-V) + (p2[2]-p3[2]) * .25*(1+V) };
  double dxyzdv[3] = {
      (p3[0]-p0[0]) * .25*(1-U) + (p2[0]-p1[0]) * .25*(1+U),
      (p3[1]-p0[1]) * .25*(1-U) + (p2[1]-p1[1]) * .25*(1+U),
      (p3[2]-p0[2]) * .25*(1-U) + (p2[2]-p1[2]) * .25*(1+U) };
  double dxyzdw[3] = {
      p4[0] - (p0[0]+p1[0]+p2[0]+p3[0]) * .25 + (p0[0]-p1[0]+p2[0]-p3[0]) * .25*U*V,
      p4[1] - (p0[1]+p1[1]+p2[1]+p3[1]) * .25 + (p0[1]-p1[1]+p2[1]-p3[1]) * .25*U*V,
      p4[2] - (p0[2]+p1[2]+p2[2]+p3[2]) * .25 + (p0[2]-p1[2]+p2[2]-p3[2]) * .25*U*V };

  // transform (this can be done when computing dxyzd* actually
  static const double sqrt2 = sqrt(2);
  dxyzdu[0] *= 2;
  dxyzdu[1] *= 2;
  dxyzdu[2] *= 2;
  dxyzdv[0] *= 2;
  dxyzdv[1] *= 2;
  dxyzdv[2] *= 2;
  dxyzdw[0] *= sqrt2;
  dxyzdw[1] *= sqrt2;
  dxyzdw[2] *= sqrt2;

  const double cross[3] = {
      dxyzdu[1]*dxyzdv[2] - dxyzdu[2]*dxyzdv[1],
      dxyzdu[2]*dxyzdv[0] - dxyzdu[0]*dxyzdv[2],
      dxyzdu[0]*dxyzdv[1] - dxyzdu[1]*dxyzdv[0] };
  const double detJ_ =
    cross[0] * dxyzdw[0] + cross[1] * dxyzdw[1] + cross[2] * dxyzdw[2];
  const double frobJ_ =
    dxyzdu[0] * dxyzdu[0] + dxyzdu[1] * dxyzdu[1] + dxyzdu[2] * dxyzdu[2]
    + dxyzdv[0] * dxyzdv[0] + dxyzdv[1] * dxyzdv[1] + dxyzdv[2] * dxyzdv[2]
    + dxyzdw[0] * dxyzdw[0] + dxyzdw[1] * dxyzdw[1] + dxyzdw[2] * dxyzdw[2];

  return 5.1961524*detJ_/pow(frobJ_, 3./2);
}

double hxtQualityPyramid(const double* p0, const double* p1, const double* p2, const double* p3, const double* p4) {
  double qmin = 100.;
  {
    const double pt[3] = { -1.,-1.,0. };
    const double q = pyramidQualityAtPoint(pt, p0, p1, p2, p3, p4);
    if (q < qmin) qmin = q;
  }
  {
    const double pt[3] = { 1.,-1.,0. };
    const double q = pyramidQualityAtPoint(pt, p0, p1, p2, p3, p4);
    if (q < qmin) qmin = q;
  }
  {
    const double pt[3] = { 1.,1.,0. };
    const double q = pyramidQualityAtPoint(pt, p0, p1, p2, p3, p4);
    if (q < qmin) qmin = q;
  }
  {
    const double pt[3] = { -1., 1.,0. };
    const double q = pyramidQualityAtPoint(pt, p0, p1, p2, p3, p4);
    if (q < qmin) qmin = q;
  }
  return qmin;
}


