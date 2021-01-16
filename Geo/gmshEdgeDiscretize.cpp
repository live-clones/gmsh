// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdio>
#include <cmath>
#include <vector>
#include "SPoint3.h"
#include "SVector3.h"
#include "GEdge.h"
#include "gmshEdge.h"
#include "Geo.h"

class discreteList {
  std::vector<std::pair<SPoint3, double> > _pts;
  std::vector<int> _next;

public:
  int insertPoint(int pos, const SPoint3 &pt, double t)
  {
    _pts.push_back(std::make_pair(pt, t));
    _next.push_back(_next[pos + 1]);
    _next[pos + 1] = _pts.size() - 1;
    return _pts.size() - 1;
  }
  void sort(std::vector<SPoint3> &spts, std::vector<double> &ts)
  {
    spts.clear();
    spts.reserve(_pts.size());
    ts.clear();
    ts.reserve(_pts.size());
    for(int p = _next[0]; p != -1; p = _next[p + 1]) {
      spts.push_back(_pts[p].first);
      ts.push_back(_pts[p].second);
    }
  }
  discreteList() { _next.push_back(-1); }
};

static void decasteljau(double tol, discreteList &discrete, int pos,
                        const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                        const SPoint3 &p3, double t0, double t3)
{
  SVector3 d30 = p3 - p0;
  SVector3 d13 = p1 - p3;
  SVector3 d23 = p2 - p3;
  SVector3 d130 = crossprod(d13, d30);
  SVector3 d230 = crossprod(d23, d30);
  double d = std::max(dot(d130, d130), dot(d230, d230));
  double l2 = dot(d30, d30);

  if(d < tol * tol * l2) { return; }

  SPoint3 p01((p0 + p1) * 0.5);
  SPoint3 p12((p1 + p2) * 0.5);
  SPoint3 p23((p2 + p3) * 0.5);
  SPoint3 p012((p01 + p12) * 0.5);
  SPoint3 p123((p12 + p23) * 0.5);
  SPoint3 p0123((p012 + p123) * 0.5);
  double t0123 = 0.5 * (t0 + t3);
  int newpos = discrete.insertPoint(pos, p0123, t0123);

  decasteljau(tol, discrete, pos, p0, p01, p012, p0123, t0, t0123);
  decasteljau(tol, discrete, newpos, p0123, p123, p23, p3, t0123, t3);
}

static int discretizeBezier(double tol, discreteList &discrete, int pos,
                            const SPoint3 pt[4], double t0, double t3,
                            bool insertFirstPoint)
{
  if(insertFirstPoint) pos = discrete.insertPoint(pos, pt[0], t0);
  int newp = discrete.insertPoint(pos, pt[3], t3);
  decasteljau(tol, discrete, pos, pt[0], pt[1], pt[2], pt[3], t0, t3);
  return newp;
}

static int discretizeBSpline(double tol, discreteList &discrete, int pos,
                             const SPoint3 pt[4], double t0, double t3,
                             bool insertFirstPoint)
{
  SPoint3 bpt[4] = {SPoint3((pt[0] + 4 * pt[1] + pt[2]) * (1. / 6.)),
                    SPoint3((2 * pt[1] + pt[2]) * (1. / 3.)),
                    SPoint3((pt[1] + 2 * pt[2]) * (1. / 3.)),
                    SPoint3((pt[1] + 4 * pt[2] + pt[3]) * (1. / 6.))};
  return discretizeBezier(tol, discrete, pos, bpt, t0, t3, insertFirstPoint);
}

static int discretizeCatmullRom(double tol, discreteList &discrete, int pos,
                                const SPoint3 pt[4], double t0, double t3,
                                bool insertFirstPoint)
{
  SPoint3 bpt[4] = {pt[1], SPoint3((6 * pt[1] + pt[2] - pt[0]) * (1. / 6.)),
                    SPoint3((6 * pt[2] - pt[3] + pt[1]) * (1. / 6.)), pt[2]};
  return discretizeBezier(tol, discrete, pos, bpt, t0, t3, insertFirstPoint);
}

static inline SPoint3 curveGetPoint(Curve *c, int i)
{
  Vertex *v;
  List_Read(c->Control_Points, i, &v);
  return SPoint3(v->Pos.X, v->Pos.Y, v->Pos.Z);
}

static void discretizeCurve(Curve *c, double tol, std::vector<SPoint3> &pts,
                            std::vector<double> &ts)
{
  discreteList discrete;
  switch(c->Typ) {
  case MSH_SEGM_LINE: {
    int NPt = List_Nbr(c->Control_Points);
    pts.resize(NPt);
    ts.resize(NPt);
    for(int i = 0; i < NPt; ++i) {
      pts[i] = curveGetPoint(c, i);
      ts[i] = i / (double)(NPt - 1);
    }
    return;
  }
  case MSH_SEGM_BEZIER: {
    int back = -1;
    int NbCurves = (List_Nbr(c->Control_Points) - 1) / 3;
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      SPoint3 pt[4];
      for(int i = 0; i < 4; i++) { pt[i] = curveGetPoint(c, iCurve * 3 + i); }
      back = discretizeBezier(tol, discrete, back, pt, t1, t2, iCurve == 0);
    }
    break;
  }
  case MSH_SEGM_BSPLN: {
    int back = -1;
    bool periodic = (c->end == c->beg);
    int NbControlPoints = List_Nbr(c->Control_Points);
    int NbCurves = NbControlPoints + (periodic ? -1 : 1);
    SPoint3 pt[4];
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      for(int i = 0; i < 4; i++) {
        int k;
        if(periodic) {
          k = (iCurve - 1 + i) % (NbControlPoints - 1);
          if(k < 0) k += NbControlPoints - 1;
        }
        else {
          k = std::max(0, std::min(iCurve - 2 + i, NbControlPoints - 1));
        }
        pt[i] = curveGetPoint(c, k);
      }
      back = discretizeBSpline(tol, discrete, back, pt, t1, t2, iCurve == 0);
    }
    break;
  }
  case MSH_SEGM_SPLN: {
    int NbCurves = List_Nbr(c->Control_Points) - 1;
    SPoint3 pt[4];
    int back = -1;
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      pt[1] = curveGetPoint(c, iCurve);
      pt[2] = curveGetPoint(c, iCurve + 1);
      if(iCurve == 0) {
        if(c->beg == c->end)
          pt[0] = curveGetPoint(c, NbCurves - 1);
        else
          pt[0] = SPoint3(pt[1] * 2 - pt[2]);
      }
      else
        pt[0] = curveGetPoint(c, iCurve - 1);
      if(iCurve == NbCurves - 1) {
        if(c->beg == c->end)
          pt[3] = curveGetPoint(c, 1);
        else
          pt[3] = SPoint3(2 * pt[2] - pt[1]);
      }
      else
        pt[3] = curveGetPoint(c, iCurve + 2);
      back = discretizeCatmullRom(tol, discrete, back, pt, t1, t2, iCurve == 0);
    }
    break;
  }
  default:
    Msg::Error("discretizeCurve not implemented for curve type %d", c->Typ);
  }
  discrete.sort(pts, ts);
}

void gmshEdge::discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts)
{
  discretizeCurve(c, tol, dpts, ts);
}
