#include "hxt_point_gen_orientation.h"

/*#include "hxt_orientation3d.h"*/
/*#include "hxt_orientation3d_explicit.h"*/

#include "hxt_orientation3d_tools.h"
#include <math.h>

//#include "float.h"

/*HXTStatus hxtOrientationFieldToDirections(uint32_t n, const double* orientation3d, double* directions) {*/
/*//  #pragma parallel for*/
  /*for (uint32_t v = 0; v < n; ++v) {*/
    /*const double* tensor = &orientation3d[9*v];*/
    /*double dev = 0.;*/
    /*hxtOrientation3DcomputeQuality(tensor, &dev);*/
    /*double _vectors[9]={0.};*/
    /*hxtOrientation3DframeToDirections(_vectors, NULL, tensor);*/
    /*if (dev < 0.2) { [> valid cross <]*/
      /*for (uint8_t i = 0; i < 3; ++i) {*/
        /*for (uint8_t j = 0; j < 3; ++j) {*/
          /*directions[9*v+3*i+j] = _vectors[3*j+i];*/
        /*}*/
      /*}*/
    /*}*/
  /*}*/
  /*return HXT_STATUS_OK;*/
/*}*/

/*static double clamp(double x, double lower, double upper) {*/
  /*const double tmp = x >= lower ? x : lower;*/
  /*return tmp <= upper ? tmp : upper;*/
/*}*/

static double dot(const double a[3], const double b[3]) {
  return a[0]*b[0] + a[1] * b[1] + a[2]*b[2];
}

static double norm2(const double v[3]) {
  return v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
}

static double* normalize(const double v[3], double vn[3]) {
  const double n = sqrt(norm2(v));
  HXT_ASSERT(n > 1.e-12);
  vn[0] = v[0] / n;
  vn[1] = v[1] / n;
  vn[2] = v[2] / n;
  return vn;
}

/*static double angleBetweenVectors(const double A[3], const double B[3]) {*/
  /*double ta[3], tb[3];*/
  /*return 180./M_PI * acos(clamp(fabs(dot(normalize(A,ta),normalize(B,tb))),-1.,1.));*/
/*}*/

static double sign(double a) {
  return a >= 0 ? 1. : -1;
}

HXTStatus hxtGetCoherentDirectionsInTri(HXTMesh* m, const double* directions, uint64_t tri, double triDirs[3][9]) {
  const uint32_t* nodes = &(m->triangles.node[3*tri]);
  /* Directions of cross on first node of the tet are taken as reference
   * (other directions will be aligned with these ones) */
  for (uint8_t i = 0; i < 9; ++i) {
    triDirs[0][i] = directions[9*nodes[0]+i];
  }
  /* Loop on the two other vertices */
  for (uint8_t lv = 1; lv < 3; ++lv) {
    /* Loop on the three branches of first vertex */
    for (uint8_t d = 0; d < 3; ++d) {
      const double* ref = &triDirs[0][3*d];
      /* Loop on the 3 branches of the lv cross */
      double maxDot = 0;
      uint8_t cb = UINT8_MAX;
      double nref[3];
      normalize(ref,nref);
      for (uint8_t b = 0; b < 3; ++b) {
        const double* B = &(directions[9*nodes[lv]+3*b]);
        double Bn[3];
        normalize(B, Bn);
        const double cdot = dot(nref, Bn);
        if (fabs(cdot) > fabs(maxDot)) {
          maxDot = cdot;
          cb = b;
        }
      }
      HXT_ASSERT(cb != UINT8_MAX);
      for (uint8_t i = 0; i < 3; ++i) { 
        triDirs[lv][3*d+i] = sign(maxDot) * directions[9*nodes[lv]+3*cb+i];
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtGetCoherentDirectionsInTet(HXTMesh* m, const double* directions, uint64_t tet, double tetDirs[4][9]) {
  const uint32_t* nodes = &(m->tetrahedra.node[4*tet]);
  /* Directions of cross on first node of the tet are taken as reference
   * (other directions will be aligned with these ones) */
  for (uint8_t i = 0; i < 9; ++i) {
    tetDirs[0][i] = directions[9*nodes[0]+i];
  }
  /* Loop on the three other vertices */
  for (uint8_t lv = 1; lv < 4; ++lv) {
    /* Loop on the three branches of first vertex */
    for (uint8_t d = 0; d < 3; ++d) {
      const double* ref = &tetDirs[0][3*d];
      /* Loop on the 3 branches of the lv cross */
      double maxDot = 0;
      uint8_t cb = UINT8_MAX;
      double nref[3];
      normalize(ref,nref);
      for (uint8_t b = 0; b < 3; ++b) {
        const double* B = &(directions[9*nodes[lv]+3*b]);
        double Bn[3];
        normalize(B, Bn);
        const double cdot = dot(nref, Bn);
        if (fabs(cdot) > fabs(maxDot)) {
          maxDot = cdot;
          cb = b;
        }
      }
      HXT_ASSERT(cb != UINT8_MAX);
      for (uint8_t i = 0; i < 3; ++i) { 
        tetDirs[lv][3*d+i] = sign(maxDot) * directions[9*nodes[lv]+3*cb+i];
      }
    }
  }
  return HXT_STATUS_OK;
}
