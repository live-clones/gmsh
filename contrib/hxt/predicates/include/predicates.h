#ifndef ROBUST_PREDICATES_H
#define ROBUST_PREDICATES_H

#ifdef _MSC_VER
#ifndef __restrict__
#define __restrict__ __restrict
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern double splitter;
extern double o3dstaticfilter;
extern double o3derrboundA;
extern double ispstaticfilter;
extern double isperrboundA;

void exactinit(double maxx, double maxy, double maxz);

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


/* if you want a rough idea of the volume of one tet, but you don't need
 * exact sign computation */
static inline double orient3d_inexact(const double* __restrict__  pa,
                                      const double* __restrict__  pb,
                                      const double* __restrict__  pc,
                                      const double* __restrict__  pd)
{
  double adx, bdx, cdx, ady, bdy, cdy, adz, bdz, cdz;
  double bdxcdy, cdxbdy, cdxady, adxcdy, adxbdy, bdxady;

  adx = pa[0] - pd[0];
  bdx = pb[0] - pd[0];
  cdx = pc[0] - pd[0];
  ady = pa[1] - pd[1];
  bdy = pb[1] - pd[1];
  cdy = pc[1] - pd[1];
  adz = pa[2] - pd[2];
  bdz = pb[2] - pd[2];
  cdz = pc[2] - pd[2];

  bdxcdy = bdx * cdy;
  cdxbdy = cdx * bdy;

  cdxady = cdx * ady;
  adxcdy = adx * cdy;

  adxbdy = adx * bdy;
  bdxady = bdx * ady;

  return adz * (bdxcdy - cdxbdy)
       + bdz * (cdxady - adxcdy)
       + cdz * (adxbdy - bdxady);
}


// remember to call exactinit with the right ranges beforehand !!!
static inline int orient3d_inline(const double* __restrict__  pa,
                                  const double* __restrict__  pb,
                                  const double* __restrict__  pc,
                                  const double* __restrict__  pd)
{
  double det = orient3d_inexact(pa, pb, pc, pd);

  int ret = (det > o3dstaticfilter) - (det < -o3dstaticfilter);

  if (ret!=0) return ret;

  det = orient3d(pa,pb,pc,pd);

  return (det>0.0) - (det<0.0);
}


#ifdef __cplusplus
}
#endif

#endif
