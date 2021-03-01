// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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

#include "GEdge.h"
#include "nodalBasis.h"
#include "SVector3.h"
#include <algorithm>
#include <limits>
#include "IntegralBoundaryDist.h"
#include "discreteFrechetDistance.h"
#include "MLine.h"
#include "MElement.h"
#include "MVertex.h"
#include "BasisFactory.h"

parametricLineNodalBasis::parametricLineNodalBasis(
  const nodalBasis &basis, const std::vector<SPoint3> &xyz)
  : _basis(basis), _xyz(xyz), psi(_xyz.size())
{
}

SPoint3 parametricLineNodalBasis::operator()(double xi) const
{
  SPoint3 p(0, 0, 0);
  _basis.f(-1 + 2 * xi, 0, 0, &psi[0]);
  for(size_t j = 0; j < psi.size(); ++j) {
    p[0] += psi[j] * _xyz[j].x();
    p[1] += psi[j] * _xyz[j].y();
    p[2] += psi[j] * _xyz[j].z();
  }
  return p;
}

SVector3 parametricLineNodalBasis::derivative(double xi) const
{
  double dpsi[1256][3];
  SVector3 p(0, 0, 0);
  _basis.df(-1 + 2 * xi, 0, 0, dpsi);
  for(size_t j = 0; j < _xyz.size(); ++j) {
    p[0] += dpsi[j][0] * _xyz[j].x();
    p[1] += dpsi[j][0] * _xyz[j].y();
    p[2] += dpsi[j][0] * _xyz[j].z();
  }
  return p;
}

SVector3 parametricLineNodalBasis::secondDerivative(double xi) const
{
  double ddpsi[1256][3][3];
  SVector3 p(0, 0, 0);
  _basis.ddf(-1 + 2 * xi, 0, 0, ddpsi);
  for(size_t j = 0; j < _xyz.size(); ++j) {
    p[0] += ddpsi[j][0][0] * _xyz[j].x();
    p[1] += ddpsi[j][0][0] * _xyz[j].y();
    p[2] += ddpsi[j][0][0] * _xyz[j].z();
  }
  return p;
}

parametricLineGEdge::parametricLineGEdge(const GEdge *edge, double t0,
                                         double t1)
  : _edge(edge), _t0(t0), _t1(t1)
{
}

SPoint3 parametricLineGEdge::operator()(double xi) const
{
  GPoint gp = _edge->point(_t0 + (_t1 - _t0) * xi);
  return SPoint3(gp.x(), gp.y(), gp.z());
}

SVector3 parametricLineGEdge::derivative(double xi) const
{
  return _edge->firstDer(_t0 + (_t1 - _t0) * xi);
}

SVector3 parametricLineGEdge::secondDerivative(double xi) const
{
  return _edge->secondDer(_t0 + (_t1 - _t0) * xi);
}

static void oversample(std::vector<SPoint3> &s, double tol)
{
  std::vector<SPoint3> t;
  for(std::size_t i = 1; i < s.size(); i++) {
    SPoint3 p0 = s[i - 1];
    SPoint3 p1 = s[i];
    double d = p0.distance(p1);
    int N = (int)(d / tol);
    t.push_back(p0);
    for(int j = 1; j < N; j++) {
      const double xi = (double)j / N;
      t.push_back(p0 + (p1 - p0) * xi);
    }
  }
  t.push_back(s[s.size() - 1]);
  s = t;
}

// FAST IMPLEMENTATION OF DISCRETE UNIDIRECTIONAL HAUSDORFF DISTANCE
double computeBndDistH(GEdge *edge,
                       std::vector<double> &params, // the model edge
                       const std::vector<MVertex *> &vs,
                       const nodalBasis &basis, const std::vector<SPoint3> &xyz,
                       const double tolerance) // the mesh edge
{
  if(edge->geomType() == GEntity::Line) return 0.0;
  std::vector<SPoint3> dpts;
  std::vector<double> ts;
  std::vector<MVertex *> hov;
  for(std::size_t i = 2; i < vs.size(); i++) hov.push_back(vs[i]);
  MLineN l(vs[0], vs[1], hov);
  l.discretize(tolerance, dpts, ts);
  oversample(dpts, tolerance);
  double maxDist = 0.0;
  for(std::size_t i = 0; i < dpts.size(); i++) {
    maxDist = std::max(
      maxDist, dpts[i].distance(edge->closestPointWithTol(dpts[i], tolerance)));
  }
  return maxDist;
}

SVector3 parametricLine::curvature(double xi) const
{
  SVector3 xp = derivative(xi);
  SVector3 xpp = secondDerivative(xi);
  const double nxp = xp.norm();
  const double onxp = 1. / nxp;
  SVector3 c = (onxp * onxp * onxp) * (xpp * nxp - xp * dot(xp, xpp) * onxp);
  return c;
}

double parametricLine::frechetDistance(const parametricLine &l, SPoint3 &p1,
                                       SPoint3 &p2, double tol) const
{
  std::vector<SPoint3> dpts1, dpts2;
  std::vector<double> ts1, ts2;
  discretize(dpts1, ts1, tol);
  l.discretize(dpts2, ts2, tol);
  // printf("discretizing gives %d %d points\n",dpts1.size(),dpts2.size());
  oversample(dpts1, tol);
  oversample(dpts2, tol);
  // printf("after oversaplinf an discretizing gives %d %d points\n",
  //        dpts1.size(),dpts2.size());
  return discreteFrechetDistance(dpts1, dpts2);
}
double parametricLine::hausdorffDistance(const parametricLine &l, SPoint3 &p1,
                                         SPoint3 &p2, double tolerance) const
{
  std::vector<SPoint3> dpts1, dpts2;
  std::vector<double> ts1, ts2;
  discretize(dpts1, ts1, tolerance);
  l.discretize(dpts2, ts2, tolerance);

  //  oversample(dpts1,tolerance);
  //  oversample(dpts2,tolerance);

  double h1 = 0.0;
  int I1 = 0, J1 = 0;
  int I2 = 0, J2 = 0;
  for(std::size_t i = 0; i < dpts1.size(); i++) {
    double hl = 1.e22;
    int JLOC = 0;
    for(std::size_t j = 0; j < dpts2.size(); j++) {
      double H = dpts1[i].distance(dpts2[j]);
      if(hl < H) {
        hl = H;
        JLOC = j;
      }
    }
    if(hl > h1) {
      h1 = hl;
      J1 = JLOC;
      I1 = i;
    }
  }
  double h2 = 0.0;
  for(std::size_t i = 0; i < dpts2.size(); i++) {
    double hl = 1.e22;
    int JLOC = 0;
    for(std::size_t j = 0; j < dpts1.size(); j++) {
      double H = dpts1[j].distance(dpts2[i]);
      if(hl < H) {
        hl = H;
        JLOC = j;
      }
    }
    if(hl > h2) {
      h2 = hl;
      J2 = JLOC;
      I2 = i;
    }
  }
  if(h1 > h2) {
    p1 = dpts1[I1];
    p2 = dpts2[J1];
    return h1;
  }
  else {
    p1 = dpts2[I2];
    p2 = dpts1[J2];
    return h2;
  }
}

// DISCRETE FRECHET DISTANCE
double computeBndDistF(GEdge *edge,
                       std::vector<double> &params, // the model edge
                       const nodalBasis &basis, const std::vector<SPoint3> &xyz,
                       const double tolerance) // the mesh edge
{
  if(edge->geomType() == GEntity::Line) return 0.0;
  parametricLineGEdge l1 = parametricLineGEdge(edge, params[0], params[1]);
  parametricLineNodalBasis l2 = parametricLineNodalBasis(basis, xyz);
  SPoint3 p1, p2;
  return l1.frechetDistance(l2, p1, p2, tolerance);
}

// GMSH's DISTANCE
double computeBndDistGb(GEdge *edge,
                        std::vector<double> &params, // the model edge
                        const nodalBasis &basis,
                        const std::vector<SPoint3> &xyz,
                        double tolerance) // the mesh edge
{
  parametricLineGEdge l1 = parametricLineGEdge(edge, params[0], params[1]);
  parametricLineNodalBasis l2 = parametricLineNodalBasis(basis, xyz);
  const std::size_t N = 20;
  SPoint3 P1[N];
  SPoint3 P2[N];
  double D = 0.0;
  for(std::size_t i = 0; i < N; i++) {
    const double _x2 = (double)i / (N - 1);
    P1[i] = l1(_x2);
    P2[i] = l2(_x2);
  }
  double L = 0.0;
  for(std::size_t i = 0; i < N - 1; i++) {
    SPoint3 p11 = P1[i];
    SPoint3 p12 = P1[i + 1];
    SPoint3 p21 = P2[i];
    SPoint3 p22 = P2[i + 1];
    SVector3 v1(p21, p11);
    SVector3 v2(p12, p11);
    SVector3 v12(p22, p11);
    SVector3 vl(p22, p21);
    SVector3 x1 = crossprod(v12, v1);
    SVector3 x2 = crossprod(v12, v2);
    D += 0.5 * (x1.norm() + x2.norm());
    L += vl.norm();
  }
  return D;
}

double computeBndDistG_(GEdge *edge, std::vector<double> &p, // the model edge
                        const nodalBasis &basis,
                        const std::vector<SPoint3> &xyz,
                        const std::size_t NN) // the mesh edge
{
  const std::size_t N = 200;
  std::vector<int> o;
  o.push_back(0);
  for(std::size_t i = 2; i < p.size(); i++) o.push_back(i);
  o.push_back(1);

  // printf("computing diustance with tolerance %g\n",tolerac);

  double D = 0.0;
  const double U0 = basis.points(0, 0);
  const double U1 = basis.points(1, 0);
  for(int i = 0; i < basis.order; i++) {
    const double u0 = basis.points(o[i], 0);
    const double u1 = basis.points(o[i + 1], 0);

    // U0 ----u0-----u1-----U1

    const double t0 = p[o[i]];
    const double t1 = p[o[i + 1]];
    parametricLineGEdge l1 = parametricLineGEdge(edge, t0, t1);
    parametricLineNodalBasis l2 = parametricLineNodalBasis(basis, xyz);
    std::vector<SPoint3> P1(N), P2(N);
    for(std::size_t i = 0; i < N; i++) {
      const double _x2 = (double)i / (N - 1);
      const double u = u0 + _x2 * (u1 - u0);
      // U0 + uu * (U1 - U0) = u
      const double uu = (u - U0) / (U1 - U0);
      P1[i] = l1(_x2);
      P2[i] = l2(uu);
    }
    //    double L = 0.0;
    for(std::size_t i = 0; i < N - 1; i++) {
      SPoint3 p11 = P1[i];
      SPoint3 p12 = P1[i + 1];
      SPoint3 p21 = P2[i];
      SPoint3 p22 = P2[i + 1];
      SVector3 v1(p21, p11);
      SVector3 v2(p12, p11);
      SVector3 v12(p22, p11);
      //      SVector3 vl (p22,p21);
      SVector3 x1 = crossprod(v12, v1);
      SVector3 x2 = crossprod(v12, v2);
      D += 0.5 * (x1.norm() + x2.norm());
      //      L += vl.norm();
    }
  }
  return D;
}

double computeBndDistG(GEdge *edge, std::vector<double> &p, // the model edge
                       const nodalBasis &basis, const std::vector<SPoint3> &xyz,
                       double tolerance) // the mesh edge
{
  int N = 5;
  double d = computeBndDistG_(edge, p, basis, xyz, N);

  while(1) {
    N *= 2;
    double dp = computeBndDistG_(edge, p, basis, xyz, N);
    if(fabs(d - dp) <
       tolerance * (d + dp)) // Richardson with assumed linear convergence ...
      return dp;
    d = dp;
  }
}

void parametricLine::recur_discretize(const double &t1, const double &t2,
                                      const SPoint3 &p1, const SPoint3 &p2,
                                      std::vector<SPoint3> &dpts,
                                      std::vector<double> &ts, double Prec,
                                      int depth) const
{
  double t = 0.5 * (t2 + t1);
  SPoint3 p = (*this)(t);
  SVector3 dx(p, (p1 + p2) * 0.5);
  if((depth > 20 && dx.norm() < Prec) || depth > 45) {
    dpts.push_back(p);
    ts.push_back(t);
    dpts.push_back(p2);
    ts.push_back(t2);
  }
  else {
    recur_discretize(t1, t, p1, p, dpts, ts, Prec, depth + 1);
    recur_discretize(t, t2, p, p2, dpts, ts, Prec, depth + 1);
  }
}

void parametricLine::discretize(std::vector<SPoint3> &dpts,
                                std::vector<double> &ts, double Prec, double t0,
                                double t1) const
{
  dpts.push_back((*this)(t0));
  ts.push_back(t0);
  recur_discretize(t0, t1, dpts[0], (*this)(t1), dpts, ts, Prec, 0);
}

double trapeze(SPoint3 &p1, SPoint3 &p2)
{
  return (p2.x() - p1.x()) * (p1.y() + p2.y()) * 0.5;
}

double computeDeviationOfTangents(
  GEdge *edge,
  std::vector<double> &p, // parameters of mesh vertices on the model edge
  const nodalBasis &basis,
  const std::vector<SPoint3> &xyz) // the mesh edge
{
  //  parametricLineGEdge l1 = parametricLineGEdge(edge,p[0],p[p.size()-1]);
  parametricLineNodalBasis l2 = parametricLineNodalBasis(basis, xyz);
  double deviation = 0;
  //  double ddeviation = 0;
  std::vector<int> o;
  o.push_back(0);
  for(std::size_t i = 2; i < p.size(); i++) o.push_back(i);
  o.push_back(1);

  SVector3 dx(xyz[xyz.size() - 1], xyz[0]);

  for(std::size_t i = 0; i < p.size(); i++) {
    const double u = basis.points(o[i], 0);
    SVector3 xp = edge->firstDer(p[o[i]]);
    // SVector3 xpp = edge->secondDer (p[o[i]]);
    // const double nxp = xp.norm();
    // const double onxp = 1./nxp;
    // SVector3 c = (onxp*onxp*onxp)*(xpp*nxp-xp*dot(xp,xpp)*onxp);

    SVector3 t_mesh_edge = l2.derivative(0.5 * (1 + u));
    // SVector3 c2  = l2.curvature(0.5*(1+u));
    // GPoint p0 = edge->point(p[o[i]]);
    // SPoint3 p1 = l2 (0.5*(1+u));
    xp.normalize();
    t_mesh_edge.normalize();
    SVector3 diff1 =
      (dot(xp, t_mesh_edge) > 0) ? xp - t_mesh_edge : xp + t_mesh_edge;
    // SVector3 diff2 = (dot(c, c2) > 0) ? c -  c2 : c +  c2;
    deviation += diff1.norm();
    // ddeviation += diff2.norm();
  }
  const double h = dx.norm();

  return deviation * h; // + ddeviation * h * h * 0.5;
}

double computeBndDistAccurateArea(
  GEdge *edge,
  std::vector<double> &p, // parameters of mesh vertices on the model edge
  const nodalBasis &basis, const std::vector<SPoint3> &xyz,
  double tolerance) // the mesh edge
{
  // assume mesh and CAD non intersecting except at mesh vertices
  // compute distance for "order" sub-polygonal curves
  double area = 0.0;
  double length = 0.0;
  std::vector<int> o;
  o.push_back(0);
  for(std::size_t i = 2; i < p.size(); i++) o.push_back(i);
  o.push_back(1);

  // printf("computing diustance with tolerance %g\n",tolerac);

  for(int i = 0; i < basis.order; i++) {
    const double u0 = basis.points(o[i], 0);
    const double u1 = basis.points(o[i + 1], 0);
    const double t0 = p[o[i]];
    const double t1 = p[o[i + 1]];
    parametricLineGEdge l1 = parametricLineGEdge(edge, t0, t1);
    parametricLineNodalBasis l2 = parametricLineNodalBasis(basis, xyz);
    std::vector<SPoint3> dpts1, dpts2;
    std::vector<double> ts1, ts2;
    l1.discretize(dpts1, ts1, tolerance);
    l2.discretize(dpts2, ts2, tolerance, 0.5 * (1 + u0), 0.5 * (1 + u1));
    // simple 2D version
    double arealocal = 0.0;
    for(std::size_t j = 1; j < dpts1.size(); j++) {
      length += dpts1[j - 1].distance(dpts1[j]);
      arealocal += trapeze(dpts1[j - 1], dpts1[j]);
    }
    for(std::size_t j = 1; j < dpts2.size(); j++) {
      arealocal -= trapeze(dpts2[j - 1], dpts2[j]);
    }
    area += fabs(arealocal);
  }
  return area;
}

double computeBndDistAndGradient(
  GEdge *edge,
  std::vector<double> &param, // parameters of mesh vertices on the model edge
  const std::vector<MVertex *> &vs, // vertices
  const nodalBasis &basis, // what is the FE basis of the edge
  std::vector<SPoint3>
    &xyz, // real coordinates of mesh vertices on the model edge
  std::vector<bool> &onEdge, // tell if a given vertex sits on the model edge
                             // and therefore can be movd
  std::vector<double> &grad,
  double tolerance) // model tolerance
{
  grad.resize(xyz.size());
  double ref;
  if(tolerance < 0)
    ref = computeDeviationOfTangents(edge, param, basis, xyz);
  else
    ref = computeBndDistG(edge, param, basis, xyz, tolerance);
  // double ref = computeBndDistAccurateArea(edge, param,basis, xyz, tolerance);
  double delta = (edge->getUpperBound() - edge->getLowerBound()) * 1e-8;
  for(size_t i = 0; i < xyz.size(); ++i) {
    if(!onEdge[i]) {
      grad[i] = 0;
      continue;
    }
    double p = param[i];
    double delta = 1e-6;
    param[i] += delta;
    xyz[i] = SPoint3(edge->position(param[i]));
    if(tolerance > 0)
      grad[i] =
        (computeBndDistG(edge, param, basis, xyz, tolerance) - ref) / delta;
    else
      grad[i] =
        (computeDeviationOfTangents(edge, param, basis, xyz) - ref) / delta;
    param[i] = p;
    xyz[i] = SPoint3(edge->position(param[i]));
  }
  return ref;
}

double computeBndDist(MElement *element, int distanceDefinition,
                      double tolerance)
{
  double dist = 0;
  const nodalBasis &elbasis = *element->getFunctionSpace();
  for(int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
    int clId = elbasis.getClosureId(iEdge, 1);
    const std::vector<int> &closure = elbasis.closures[clId];
    std::vector<SPoint3> xyz;
    GEdge *edge = nullptr;
    std::vector<MVertex *> vertices(closure.size());
    for(size_t i = 0; i < closure.size(); ++i) {
      MVertex *v = element->getVertex(closure[i]);
      vertices[i] = v;
      xyz.push_back(v->point());
      if((int)i >= 2 && v->onWhat() && v->onWhat()->dim() == 1) {
        edge = v->onWhat()->cast2Edge();
      }
    }
    if(edge) {
      std::vector<double> params(closure.size());
      for(size_t i = 0; i < closure.size(); ++i) {
        reparamMeshVertexOnEdge(element->getVertex(closure[i]), edge,
                                params[i]);
      }
      if(distanceDefinition == 1)
        dist = std::max(computeBndDistH(edge, params, vertices,
                                        *BasisFactory::getNodalBasis(
                                          elbasis.getClosureType(clId)),
                                        xyz, tolerance),
                        dist);
      else if(distanceDefinition == 2)
        dist = std::max(computeBndDistG(edge, params,
                                        *BasisFactory::getNodalBasis(
                                          elbasis.getClosureType(clId)),
                                        xyz, tolerance),
                        dist);
      else if(distanceDefinition == 4)
        dist = std::max(computeBndDistF(edge, params,
                                        *BasisFactory::getNodalBasis(
                                          elbasis.getClosureType(clId)),
                                        xyz, tolerance),
                        dist);
      else if(distanceDefinition == 5)
        dist =
          std::max(computeBndDistAccurateArea(
                     edge, params,
                     *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)),
                     xyz, tolerance),
                   dist);
      else if(distanceDefinition == 6)
        dist = std::max(
          computeDeviationOfTangents(
            edge, params,
            *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)), xyz),
          dist);
      else
        Msg::Error("unknown distance definition %d. Choose 1 for Hausdorff and "
                   "2 for Area/Length 4 for Discrete Frechet",
                   distanceDefinition);
    }
  }
  return dist;
}
