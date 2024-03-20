// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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

} // namespace robustPredicates

#endif
