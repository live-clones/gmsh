// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

/*
  compute the hausdorff distance between two polygonal curves
  in n*m time where n and m are the nb of points of the
  polygonal curves
*/

#include "SVector3.h"
#include "hausdorffDistance.h"

static double intersect(SPoint3 &q, SVector3 &n, // a plane
                        SPoint3 &p1, SPoint3 &p2, // a segment
                        SPoint3 &result)
{
  // n * (x-q) = 0
  // x = p1 + t (p2-p1)
  // n *(p1 + t (p2-p1) - q) = 0
  // t = n*(q-p1) / n*(p2-p1)

  const double t = dot(n, q - p1) / dot(n, p2 - p1);
  result = p1 * (1. - t) + p2 * t;
  return t;
}

static double projection(SPoint3 &p1, SPoint3 &p2, SPoint3 &q, SPoint3 &result)
{
  // x = p1 + t (p2 - p1)
  // (x - q) * (p2 - p1) = 0
  // (p1 + t (p2 - p1) - q) (p2 - p1) = 0
  // t = (q-p1) * (p2-p1) / (p2-p1)^2
  SVector3 p21 = p2 - p1;
  const double t = dot(q - p1, p21) / dot(p21, p21);
  result = p1 * (1. - t) + p2 * t;
  return t;
}

static SPoint3 closestPoint(SPoint3 &p1, SPoint3 &p2, SPoint3 &q)
{
  double result;
  const double t = projection(p1, p2, q, result);
  if(t >= 0.0 && t <= 1.0) return result;
  if(t < 0) return p1;
  return p2;
}

double closestPoint(const std::vector<SPoint3> &P, const SPoint3 &p,
                    SPoint3 &result)
{
  double closestDistance = 1.e22;
  for(std::size_t i = 1; i < P.size(); i++) {
    SPoint3 q = closestPoint(P[i - 1], P[i], p);
    const double pq = p.distance(q);
    if(pq < closestDistance) {
      closestDistance = pq;
      result = q;
    }
  }
  return closestDistance;
}

// we test all points of P plus all points that are the intersections
// of angle bissectors of Q with P
double oneSidedHausdorffDistance(const std::vector<SPoint3> &P,
                                 const std::vector<SPoint3> &Q, SPoint3 &p1,
                                 SPoint3 &p2)
{
  const double hausdorffDistance = 0.0;

  // first test the points
  for(std::size_t i = 0; i < P.size(); i++) {
    SPoint3 result;
    double d = closestPoint(Q, P[i], result);
    if(d > hausdorffDistance) {
      hausdorffDistance = d;
      p1 = P[i];
      p2 = result;
    }
  }
  // compute angle bissectors intersections
  std::vector<SPoint3> intersections;
  for(std::size_t i = 1; i < Q.size() - 1; i++) {
    SPoint3 a = Q[i - 1];
    SPoint3 b = Q[i];
    SPoint3 c = Q[i + 1];
    SVector3 ba = b - a;
    SVector3 ca = c - a;
    SVector3 bissector = (ba + ca);
    SVector3 n; // normal to the bissector plane
    if(bissector.norm == 0) {
      ba.normalize();
      n = ba;
    }
    else {
      SVector3 b = crossprod(bissector, ba);
      n = crossprod(b, bissector);
      n.normalize();
    }
    for(std::size_t i = 1; i < P.size(); i++) {
      SPoint3 result;
      const double t = intersect(b, n, P[i - 1], P[i], result);
      if(t >= 0 && t <= 1) intersections.push_back(result);
    }
  }

  for(std::size_t i = 0; i < intersections.size(); i++) {
    SPoint3 result;
    double d = closestPoint(Q, intersections[i], result);
    if(d > hausdorffDistance) {
      hausdorffDistance = d;
      p1 = P[i];
      p2 = result;
    }
  }
  return hausdorffDistance;
}

double hausdorffDistance(const std::vector<SPoint3> &P,
                         const std::vector<SPoint3> &Q)
{
  return std::max(oneSidedHausdorffDistance(P, Q),
                  oneSidedHausdorffDistance(Q, P));
}
