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

#ifndef OPT_HOM_INTEGRAL_BOUNDARY_DIST_H
#define OPT_HOM_INTEGRAL_BOUNDARY_DIST_H

#include <vector>

class GEdge;
class nodalBasis;
class SPoint3;
class MElement;
class MVertex;
double computeBndDist(MElement *element, int distanceDefinition,
                      double tolerance);
double computeBndDistAndGradient(GEdge *edge, std::vector<double> &param,
                                 const std::vector<MVertex *> &vs,
                                 const nodalBasis &basis,
                                 std::vector<SPoint3> &xyz,
                                 std::vector<bool> &onEdge,
                                 std::vector<double> &grad, double tolerance);

class parametricLine {
public:
  virtual SPoint3 operator()(double xi) const = 0;
  virtual SVector3 derivative(double xi) const = 0;
  virtual SVector3 secondDerivative(double xi) const = 0;
  SVector3 curvature(double xi) const;
  void discretize(std::vector<SPoint3> &dpts, std::vector<double> &ts,
                  double Prec, double t0 = 0.0, double t1 = 1.0) const;
  void recur_discretize(const double &t1, const double &t2, const SPoint3 &p1,
                        const SPoint3 &p2, std::vector<SPoint3> &dpts,
                        std::vector<double> &ts, double Prec, int depth) const;
  double frechetDistance(const parametricLine &l, SPoint3 &p1, SPoint3 &p2,
                         double tol = 1.e-6) const;
  double hausdorffDistance(const parametricLine &l, SPoint3 &p1, SPoint3 &p2,
                           double tol = 1.e-6) const;
};

class parametricLineNodalBasis : public parametricLine {
  const nodalBasis &_basis;
  const std::vector<SPoint3> &_xyz;
  mutable std::vector<double> psi;

public:
  parametricLineNodalBasis(const nodalBasis &basis,
                           const std::vector<SPoint3> &xyz);
  virtual SPoint3 operator()(double xi) const;
  virtual SVector3 derivative(double xi) const;
  virtual SVector3 secondDerivative(double xi) const;
};

class parametricLineGEdge : public parametricLine {
  const GEdge *_edge;
  double _t0, _t1;

public:
  parametricLineGEdge(const GEdge *edge, double t0, double t1);
  virtual SPoint3 operator()(double xi) const;
  virtual SVector3 derivative(double xi) const;
  virtual SVector3 secondDerivative(double xi) const;
};

#endif
