// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by J. Lambrechts

#include <algorithm>
#include "decasteljau.h"
#include "SPoint3.h"
#include "SVector3.h"

typedef struct {
  SPoint3 p;
  double t;
  int next;
} sortedPoint;

static int sortedPointInsert(const SPoint3 &p, const double t,
                             std::vector<sortedPoint> &pts, int pos)
{
  sortedPoint pnt = {p, t, pts[pos].next};
  pts.push_back(pnt);
  int newp = (int)pts.size() - 1;
  pts[pos].next = newp;
  return newp;
}

static void sortedPointToVector(const std::vector<sortedPoint> &spts,
                                std::vector<SPoint3> &pts,
                                std::vector<double> &ts)
{
  pts.clear();
  pts.reserve(spts.size());
  ts.clear();
  ts.reserve(spts.size());
  for(int p = 0; p != -1; p = spts[p].next) {
    pts.push_back(spts[p].p);
    ts.push_back(spts[p].t);
  }
}

double sqDistPointSegment(const SPoint3 &p, const SPoint3 &s0,
                          const SPoint3 &s1)
{
  SVector3 d(s1 - s0);
  SVector3 d0(p - s0);
  SVector3 d1(p - s1);
  double dn2 = crossprod(d, d0).normSq();
  double dt2 = std::max(0., std::max(-dot(d, d0), dot(d, d1)));
  dt2 *= dt2;
  return (dt2 + dn2) / d.normSq();
}

static void decasteljau(double tol, std::vector<sortedPoint> &discrete, int pos,
                        const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                        double t0, double t2)
{
  if(sqDistPointSegment(p1, p0, p2) < tol * tol) return;
  SPoint3 p01((p0 + p1) * 0.5);
  SPoint3 p12((p1 + p2) * 0.5);
  SPoint3 p012((p01 + p12) * 0.5);
  double t012 = 0.5 * (t0 + t2);
  int newpos = sortedPointInsert(p012, t012, discrete, pos);
  decasteljau(tol, discrete, pos, p0, p01, p012, t0, t012);
  decasteljau(tol, discrete, newpos, p012, p12, p2, t012, t2);
}

void decasteljau(double tol, const SPoint3 &p0, const SPoint3 &p1,
                 const SPoint3 &p2, std::vector<SPoint3> &pts,
                 std::vector<double> &ts)
{
  std::vector<sortedPoint> discrete;
  sortedPoint pnt1 = {p0, 0., 1};
  discrete.push_back(pnt1);
  sortedPoint pnt2 = {p2, 1., -1};
  discrete.push_back(pnt2);
  decasteljau(tol, discrete, 0, p0, p1, p2, 0., 1);
  sortedPointToVector(discrete, pts, ts);
}

static void decasteljau(double tol, std::vector<sortedPoint> &discrete, int pos,
                        const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                        const SPoint3 &p3, double t0, double t3)
{
  if(std::max(sqDistPointSegment(p1, p0, p3), sqDistPointSegment(p2, p0, p3)) <
     tol * tol)
    return;
  SPoint3 p01((p0 + p1) * 0.5);
  SPoint3 p12((p1 + p2) * 0.5);
  SPoint3 p23((p2 + p3) * 0.5);
  SPoint3 p012((p01 + p12) * 0.5);
  SPoint3 p123((p12 + p23) * 0.5);
  SPoint3 p0123((p012 + p123) * 0.5);
  double t0123 = 0.5 * (t0 + t3);
  int newpos = sortedPointInsert(p0123, t0123, discrete, pos);
  decasteljau(tol, discrete, pos, p0, p01, p012, p0123, t0, t0123);
  decasteljau(tol, discrete, newpos, p0123, p123, p23, p3, t0123, t3);
}

void decasteljau(double tol, const SPoint3 &p0, const SPoint3 &p1,
                 const SPoint3 &p2, const SPoint3 &p3,
                 std::vector<SPoint3> &pts, std::vector<double> &ts)
{
  std::vector<sortedPoint> discrete;
  sortedPoint pnt1 = {p0, 0., 1};
  discrete.push_back(pnt1);
  sortedPoint pnt2 = {p3, 1., -1};
  discrete.push_back(pnt2);
  decasteljau(tol, discrete, 0, p0, p1, p2, p3, 0., 1);
  sortedPointToVector(discrete, pts, ts);
}

static void decasteljau(double tol, std::vector<sortedPoint> &discrete, int pos,
                        const std::vector<SPoint3> &pts, double t0, double te)
{
  int order = (int)pts.size() - 1;
  double dmax2 = 0;
  for(int i = 1; i < order; ++i)
    dmax2 = std::max(dmax2, sqDistPointSegment(pts[i], pts[0], pts[order]));
  if(dmax2 < tol * tol) return;
  std::vector<SPoint3> sub0(pts.size());
  std::vector<SPoint3> sub1(pts);
  for(int l = 0; l < order + 1; ++l) {
    sub0[l] = sub1[0];
    for(int i = 0; i < order - l; ++i) sub1[i] = (sub1[i] + sub1[i + 1]) * 0.5;
  }
  double tmid = 0.5 * (t0 + te);
  int newpos = sortedPointInsert(sub1[0], tmid, discrete, pos);
  decasteljau(tol, discrete, pos, sub0, t0, tmid);
  decasteljau(tol, discrete, newpos, sub1, tmid, te);
}

void decasteljau(double tol, const std::vector<SPoint3> &controlPoints,
                 std::vector<SPoint3> &pts, std::vector<double> &ts)
{
  std::vector<sortedPoint> discrete;
  sortedPoint pnt1 = {controlPoints[0], 0., 1};
  discrete.push_back(pnt1);
  sortedPoint pnt2 = {controlPoints.back(), 1., -1};
  discrete.push_back(pnt2);
  decasteljau(tol, discrete, 0, controlPoints, 0., 1);
  sortedPointToVector(discrete, pts, ts);
}
