// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ROBUST_PREDICATES_H
#define ROBUST_PREDICATES_H

#ifdef _MSC_VER
#ifndef __restrict__
#define __restrict__ __restrict
#endif
#endif

// namespace necessary to avoid conflicts with predicates used by Tetgen
namespace robustPredicates {

void exactinit(double maxx, double maxy, double maxz);

// static filters of orient3d() and insphere(), set by exactinit(): a plain
// floating-point determinant larger than them in magnitude has the right sign
extern double o3dstaticfilter, ispstaticfilter;

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

// orient3d without its static filter (only valid for coordinates in the
// ranges given to exactinit): the exact sign whatever the coordinates
double orient3dDynamic(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  const double* const __restrict__ pd);
// the exact values of orient2d and orient3d as expansions (sums of
// nonoverlapping components by increasing magnitude, of the sign of the last
// one) in h, at most 12 and 96 components: the number of components
int orient2dExact(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  double* const __restrict__ h);
int orient3dExact(
  const double* const __restrict__ pa,
  const double* const __restrict__ pb,
  const double* const __restrict__ pc,
  const double* const __restrict__ pd,
  double* const __restrict__ h);
// the sum of the expansions e and f, the product of the expansion e (at
// least one component) by b, in h (neither e nor f): the number of
// components of h, at most elen + flen and 2 elen
int fast_expansion_sum_zeroelim(
  const int elen, const double* const __restrict__ e,
  const int flen, const double* const __restrict__ f,
  double* const __restrict__ h);
int scale_expansion_zeroelim(
  const int elen, const double* const __restrict__ e, const double b,
  double* const __restrict__ h);
} // namespace robustPredicates

#endif
