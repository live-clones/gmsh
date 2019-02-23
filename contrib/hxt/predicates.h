#ifndef _ROBUST_PREDICATES_H_
#define _ROBUST_PREDICATES_H_

#include <hxt_tools.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double splitter;
extern double o3dstaticfilter;
extern double o3derrboundA;
extern double ispstaticfilter;
extern double isperrboundA;

double exactinit(double maxx, double maxy, double maxz);
// double incircle(double *pa, double *pb, double *pc, double *pd);

/** \todo Please comment the freaking variable type you are using. [JP]
 */
double insphere(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  const double* const __restrict__ pd,
  const double* const __restrict__ pe);

double orient3d(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  const double* const __restrict__ pd);

double incircle(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  const double* const __restrict__ pd);

double orient2d(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc);

int grow_expansion(
  int elen, const double *e, double b, double *h);

int grow_expansion_zeroelim(
  int elen, const double *e, double b, double *h);

int fast_expansion_sum_zeroelim(
  const int elen, const double *e,
  const int flen, const double *f, double *h);

int fast_expansion_sum(
  int elen, const double *e, int flen, const double *f, double *h);

int fast_expansion_sum_zeroelim(
  const int elen, const double *e,
  const int flen, const double *f, double *h);

int scale_expansion(
  const int elen, const double *e, const double b, double *h);

int scale_expansion_zeroelim(
  const int elen, const double *e, const double b, double *h);

#ifdef __cplusplus
}
#endif

#endif
