// MeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#ifndef CAD_DISTANCES_H
#define CAD_DISTANCES_H

#include "fullMatrix.h"
#include <vector>
#include <map>

class GradientBasis;
class MLine;
class MElement;
class GEdge;
class GFace;
class SVector3;
class GModel;

enum { CADDIST_GEN, CADDIST_DECASTELJAU };
enum { CADDIST_TAYLOR, CADDIST_FRECHET, CADDIST_HAUSFAST, CADDIST_HAUSBRUTE };

double discreteFrechetDistanceEdge(MLine *l, GEdge *ed, double tol,
                                   int meshDiscr = CADDIST_GEN,
                                   int geomDiscr = CADDIST_GEN);
double discreteHausdorffDistanceBruteEdge(MLine *l, GEdge *ed, double tol,
                                          int meshDiscr = CADDIST_GEN,
                                          int geomDiscr = CADDIST_GEN);
double discreteHausdorffDistanceFastEdge(MLine *l, GEdge *ed, double tol,
                                         int meshDiscr = CADDIST_GEN,
                                         int geomDiscr = CADDIST_GEN);
double taylorDistanceSq1D(const GradientBasis *gb,
                          const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &tanCAD);
double taylorDistanceSq2D(const GradientBasis *gb,
                          const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &normCAD);
double taylorDistanceEdge(MLine *l, GEdge *ge);
double taylorDistanceFace(MElement *el, GFace *gf);

void distanceFromElementsToGeometry(GModel *gm, int dim,
                                    std::map<MElement *, double> &distances);
double distanceToGeometry(GModel *gm, int distType = CADDIST_TAYLOR,
                          double tol = 1e-3,
                          int meshDiscr = CADDIST_DECASTELJAU,
                          int geomDiscr = CADDIST_DECASTELJAU);
double distanceToGeometry(GModel *gm, int dim, int tag,
                          int distType = CADDIST_TAYLOR, double tol = 1e-3,
                          int meshDiscr = CADDIST_DECASTELJAU,
                          int geomDiscr = CADDIST_DECASTELJAU);

#endif
