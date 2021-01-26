// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ROBUST_PREDICATES_H
#define ROBUST_PREDICATES_H

// namespace necessary to avoid conflicts with predicates used by Tetgen
namespace robustPredicates {
  double exactinit(int filter, double maxx, double maxy, double maxz);
  double incircle(double *pa, double *pb, double *pc, double *pd);
  double insphere(double *pa, double *pb, double *pc, double *pd, double *pe);
  double orient2d(double *pa, double *pb, double *pc);
  double orient3d(double *pa, double *pb, double *pc, double *pd);
} // namespace robustPredicates

#endif
