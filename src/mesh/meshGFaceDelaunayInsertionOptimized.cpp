// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Mesh.Algorithm = 12, "Frontal-Delaunay Optimized": a performance-oriented
// variant of the 2D Frontal-Delaunay algorithm (Mesh.Algorithm = 6,
// bowyerWatsonFrontal in meshGFaceDelaunayInsertion.cpp). This file starts
// out as a behavioral copy of the original algorithm — the static functions
// below are copies of their algo-6 counterparts — so that the optimized
// algorithm can be reworked without touching the original one, and the two
// can be compared on the same input.

#include <set>
#include <list>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGFace.h"
#include "GFace.h"
#include "Numeric.h"
#include "Context.h"
#include "discreteFace.h"
#include "intersectCurveSurface.h"

static constexpr double ONE_THIRD = 1.0 / 3.0;
// radius threshold (in metric units) below which a triangle is small enough
// and does not need to be refined
static double LIMIT_ = 0.5 * std::sqrt(2.0);

static inline bool intersection_segments_2(double *p1, double *p2, double *q1,
                                           double *q2)
{
  double a = robustPredicates::orient2d(p1, p2, q1);
  double b = robustPredicates::orient2d(p1, p2, q2);
  if(a * b > 0) return 0;
  a = robustPredicates::orient2d(q1, q2, p1);
  b = robustPredicates::orient2d(q1, q2, p2);
  if(a * b > 0) return 0;
  return 1;
}

// a triangle is "active" when it has at least one edge on the front, i.e.
// shared with a triangle that is either outside the domain or small enough
static bool isActive(MTri3 *t, double limit_, int &active)
{
  if(t->isDeleted()) return false;
  for(active = 0; active < 3; active++) {
    MTri3 *neigh = t->getNeigh(active);
    if(!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      return true;
    }
  }
  return false;
}

static void circumCenterMetric(double *pa, double *pb, double *pc,
                               const double *metric, double *x, double &Radius2)
{
  // d = (u2-u1) M (u2-u1) = u2 M u2 + u1 M u1 - 2 u2 M u1
  double sys[2][2];
  double rhs[2];

  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];

  sys[0][0] = 2. * a * (pa[0] - pb[0]) + 2. * b * (pa[1] - pb[1]);
  sys[0][1] = 2. * d * (pa[1] - pb[1]) + 2. * b * (pa[0] - pb[0]);
  sys[1][0] = 2. * a * (pa[0] - pc[0]) + 2. * b * (pa[1] - pc[1]);
  sys[1][1] = 2. * d * (pa[1] - pc[1]) + 2. * b * (pa[0] - pc[0]);

  rhs[0] = a * (pa[0] * pa[0] - pb[0] * pb[0]) +
           d * (pa[1] * pa[1] - pb[1] * pb[1]) +
           2. * b * (pa[0] * pa[1] - pb[0] * pb[1]);
  rhs[1] = a * (pa[0] * pa[0] - pc[0] * pc[0]) +
           d * (pa[1] * pa[1] - pc[1] * pc[1]) +
           2. * b * (pa[0] * pa[1] - pc[0] * pc[1]);

  // on a degenerate system x is left as it was (the caller passes in the
  // isotropic circumcenter)
  sys2x2(sys, rhs, x);

  Radius2 = (x[0] - pa[0]) * (x[0] - pa[0]) * a +
            (x[1] - pa[1]) * (x[1] - pa[1]) * d +
            2. * (x[0] - pa[0]) * (x[1] - pa[1]) * b;
}

static void circumCenterMetric(MTriangle *base, const double *metric,
                               bidimMeshData &data, double *x, double &Radius2)
{
  int index0 = data.getIndex(base->getVertex(0));
  int index1 = data.getIndex(base->getVertex(1));
  int index2 = data.getIndex(base->getVertex(2));
  double pa[2] = {data.Us[index0], data.Vs[index0]};
  double pb[2] = {data.Us[index1], data.Vs[index1]};
  double pc[2] = {data.Us[index2], data.Vs[index2]};
  circumCenterMetric(pa, pb, pc, metric, x, Radius2);
}

template <class Iterator>
static void connectTris(Iterator beg, Iterator end,
                        std::vector<edgeXface> &conn)
{
  conn.clear();

  while(beg != end) {
    if(!(*beg)->isDeleted()) {
      for(int j = 0; j < 3; j++) { conn.push_back(edgeXface(*beg, j)); }
    }
    ++beg;
  }

  if(conn.empty()) return;

  std::sort(conn.begin(), conn.end());

  for(std::size_t i = 0; i < conn.size() - 1; i++) {
    edgeXface &f1 = conn[i];
    edgeXface &f2 = conn[i + 1];

    if(f1 == f2 && f1.t1 != f2.t1) {
      f1.t1->setNeigh(f1.i1, f2.t1);
      f2.t1->setNeigh(f2.i1, f1.t1);
      ++i;
    }
  }
}

// grow the cavity of triangles whose (metric) circumcircle contains the new
// point, and collect its boundary edges in the shell
static void recurFindCavityAniso(GFace *gf, std::list<edgeXface> &shell,
                                 std::list<MTri3 *> &cavity, double *metric,
                                 double *param, MTri3 *t, bidimMeshData &data)
{
  t->setDeleted(true);
  cavity.push_back(t);

  for(int i = 0; i < 3; i++) {
    MTri3 *neigh = t->getNeigh(i);
    edgeXface exf(t, i);
    // take care of untouchable internal edges
    auto it = data.internalEdges.find(MEdge(exf._v(0), exf._v(1)));
    if(!neigh || it != data.internalEdges.end())
      shell.push_back(exf);
    else if(!neigh->isDeleted()) {
      int circ = inCircumCircleAniso(gf, neigh->tri(), param, metric, data);
      if(circ)
        recurFindCavityAniso(gf, shell, cavity, metric, param, neigh, data);
      else
        shell.push_back(exf);
    }
  }
}

static bool circUV(MTriangle *t, bidimMeshData &data, double *res, GFace *gf)
{
  int index0 = data.getIndex(t->getVertex(0));
  int index1 = data.getIndex(t->getVertex(1));
  int index2 = data.getIndex(t->getVertex(2));
  double u1[3] = {data.Us[index0], data.Vs[index0], 0};
  double u2[3] = {data.Us[index1], data.Vs[index1], 0};
  double u3[3] = {data.Us[index2], data.Vs[index2], 0};
  circumCenterXY(u1, u2, u3, res);
  return true;
}

static bool invMapUV(MTriangle *t, double *p, bidimMeshData &data, double *uv,
                     double tol)
{
  double mat[2][2];
  double b[2];

  int index0 = data.getIndex(t->getVertex(0));
  int index1 = data.getIndex(t->getVertex(1));
  int index2 = data.getIndex(t->getVertex(2));

  double u0 = data.Us[index0];
  double v0 = data.Vs[index0];
  double u1 = data.Us[index1];
  double v1 = data.Vs[index1];
  double u2 = data.Us[index2];
  double v2 = data.Vs[index2];

  mat[0][0] = u1 - u0;
  mat[0][1] = u2 - u0;
  mat[1][0] = v1 - v0;
  mat[1][1] = v2 - v0;

  b[0] = p[0] - u0;
  b[1] = p[1] - v0;
  sys2x2(mat, b, uv);

  return uv[0] >= -tol && uv[1] >= -tol && uv[0] <= 1. + tol &&
         uv[1] <= 1. + tol && 1. - uv[0] - uv[1] > -tol;
}

static inline double getSurfUV(MTriangle *t, bidimMeshData &data)
{
  int index0 = data.getIndex(t->getVertex(0));
  int index1 = data.getIndex(t->getVertex(1));
  int index2 = data.getIndex(t->getVertex(2));

  double u1 = data.Us[index0];
  double v1 = data.Vs[index0];
  double u2 = data.Us[index1];
  double v2 = data.Vs[index1];
  double u3 = data.Us[index2];
  double v3 = data.Vs[index2];

  const double vv1[2] = {u2 - u1, v2 - v1};
  const double vv2[2] = {u3 - u1, v3 - v1};

  return 0.5 * (vv1[0] * vv2[1] - vv1[1] * vv2[0]);
}

// retriangulate the cavity by connecting the new vertex to the shell; the
// new triangles are staged so the whole insertion can be rolled back if the
// cavity turns out not to be star-shaped around v or v is too close to an
// existing vertex or edge
static int insertVertexB(std::list<edgeXface> &shell,
                         std::list<MTri3 *> &cavity, bool force, GFace *gf,
                         MVertex *v, double *param, MTri3 *t,
                         std::set<MTri3 *, compareTri3Ptr> &allTets,
                         std::set<MTri3 *, compareTri3Ptr> *activeTets,
                         bidimMeshData &data, double *metric,
                         MTri3 **oneNewTriangle,
                         bool verifyStarShapeness = true)
{
  if(cavity.size() == 1) return -1;

  if(shell.size() != cavity.size() + 2) return -2;

  double EPS = verifyStarShapeness ? 1.e-12 : 1.e12;

  // check that volume is conserved
  double newVolume = 0.0;
  double newMinQuality = 2.0;

  double oldVolume = std::accumulate(
    begin(cavity), end(cavity), 0.0, [&](double volume, MTri3 *const triangle) {
      return volume + std::abs(getSurfUV(triangle->tri(), data));
    });

  MTri3 **newTris = new MTri3 *[shell.size()];

  std::vector<MTri3 *> new_cavity;

  int k = 0;

  auto it = shell.begin();

  bool onePointIsTooClose = false;

  while(it != shell.end()) {
    MVertex *v0, *v1;
    if(it->ori > 0) {
      v0 = it->_v(0);
      v1 = it->_v(1);
    }
    else {
      v0 = it->_v(1);
      v1 = it->_v(0);
    }
    MTriangle *t = new MTriangle(v0, v1, v);
    int index0 = data.getIndex(t->getVertex(0));
    int index1 = data.getIndex(t->getVertex(1));
    int index2 = data.getIndex(t->getVertex(2));
    double lc = ONE_THIRD * (data.vSizes[index0] + data.vSizes[index1] +
                             data.vSizes[index2]);
    double lcBGM =
      ONE_THIRD * (data.vSizesBGM[index0] + data.vSizesBGM[index1] +
                   data.vSizesBGM[index2]);
    double LL = std::min(lc, lcBGM);

    MTri3 *t4 = new MTri3(t, Extend1dMeshIn2dSurfaces(gf) ? LL : lcBGM, nullptr,
                          &data, gf);

    if(oneNewTriangle) {
      force = true;
      *oneNewTriangle = t4;
    }

    double d1 = distance(v0, v);
    double d2 = distance(v1, v);
    double d3 = distance(v0, v1);
    double d4 = 1.e22;
    // avoid angles that are too obtuse
    double cosv = ((d1 * d1 + d2 * d2 - d3 * d3) / (2. * d1 * d2));

    if(v0->onWhat()->dim() != 2 && v1->onWhat()->dim() != 2) {
      SVector3 v0v1(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
      SVector3 v0v(v->x() - v0->x(), v->y() - v0->y(), v->z() - v0->z());
      SVector3 pv = crossprod(v0v1, v0v);
      d4 = pv.norm() / d3;
    }

    if((d1 < LL * .5 || d2 < LL * .5 || d4 < LL * .4 || cosv < -.9999) &&
       !force) {
      onePointIsTooClose = true;
    }

    newTris[k++] = t4;
    // all new triangles are pushed front in order to be able to destroy them
    // if the cavity is not star shaped around the new vertex
    new_cavity.push_back(t4);

    MTri3 *otherSide = it->t1->getNeigh(it->i1);
    if(otherSide) new_cavity.push_back(otherSide);

    double ss = std::abs(getSurfUV(t4->tri(), data));
    if(ss < 1.e-25) ss = 1.e22;

    newVolume += ss;
    newMinQuality = std::min(newMinQuality, t4->tri()->gammaShapeMeasure());

    ++it;
  }

  std::vector<edgeXface> conn;

  // for adding a point we require that the area remains the same after
  // addition of the point, and that the point is not too close to an edge
  if(std::abs(oldVolume - newVolume) < EPS * oldVolume && !onePointIsTooClose) {
    connectTris(new_cavity.begin(), new_cavity.end(), conn);
    allTets.insert(newTris, newTris + shell.size());
    if(activeTets) {
      for(auto i = new_cavity.begin(); i != new_cavity.end(); ++i) {
        int active_edge;
        if(isActive(*i, LIMIT_, active_edge) && (*i)->getRadius() > LIMIT_) {
          if((*activeTets).find(*i) == (*activeTets).end())
            (*activeTets).insert(*i);
        }
      }
    }
    delete[] newTris;
    return 1;
  }
  else {
    // the cavity is NOT star shaped
    std::for_each(begin(cavity), end(cavity),
                  [](MTri3 *triangle) { triangle->setDeleted(false); });
    for(std::size_t i = 0; i < shell.size(); i++) {
      delete newTris[i]->tri();
      delete newTris[i];
    }
    delete[] newTris;

    if(std::abs(oldVolume - newVolume) > EPS * oldVolume) return -3;
    if(onePointIsTooClose) return -4;
    return -5;
  }
}

// walk from t towards pt, crossing the edge whose supporting line separates
// the current triangle's barycenter from pt
static MTri3 *search4Triangle(MTri3 *t, double pt[2], bidimMeshData &data,
                              std::set<MTri3 *, compareTri3Ptr> &AllTris,
                              double uv[2], bool force = false)
{
  bool inside = invMapUV(t->tri(), pt, data, uv, 1.e-8);

  if(inside) return t;
  SPoint3 q1(pt[0], pt[1], 0);
  int ITER = 0;
  while(1) {
    int index0 = data.getIndex(t->tri()->getVertex(0));
    int index1 = data.getIndex(t->tri()->getVertex(1));
    int index2 = data.getIndex(t->tri()->getVertex(2));
    SPoint3 q2((data.Us[index0] + data.Us[index1] + data.Us[index2]) * ONE_THIRD,
               (data.Vs[index0] + data.Vs[index1] + data.Vs[index2]) * ONE_THIRD, 0);
    int i;
    for(i = 0; i < 3; i++) {
      int i1 = data.getIndex(t->tri()->getVertex(i == 0 ? 2 : i - 1));
      int i2 = data.getIndex(t->tri()->getVertex(i));
      SPoint3 p1(data.Us[i1], data.Vs[i1], 0);
      SPoint3 p2(data.Us[i2], data.Vs[i2], 0);
      if(intersection_segments_2(p1, p2, q1, q2)) break;
    }
    if(i >= 3) {
      Msg::Warning("Impossible case in triangle search");
      break;
    }
    t = t->getNeigh(i);
    if(!t) break;
    bool inside = invMapUV(t->tri(), pt, data, uv, 1.e-8);
    if(inside) return t;
    if(ITER++ > (int)AllTris.size()) break;
  }

  if(!force)
    return nullptr; // FIXME: removing this leads to horrible performance

  // when the walk is allowed to fail (seams, degenerated edges), fall back
  // to a linear scan
  for(auto itx = AllTris.begin(); itx != AllTris.end(); ++itx) {
    if(!(*itx)->isDeleted()) {
      inside = invMapUV((*itx)->tri(), pt, data, uv, 1.e-8);
      if(inside) { return *itx; }
    }
  }
  return nullptr;
}

static bool
insertAPoint(GFace *gf, std::set<MTri3 *, compareTri3Ptr>::iterator it,
             double center[2], double metric[3], bidimMeshData &data,
             std::set<MTri3 *, compareTri3Ptr> &AllTris,
             std::set<MTri3 *, compareTri3Ptr> *ActiveTris = nullptr,
             MTri3 *worst = nullptr, MTri3 **oneNewTriangle = nullptr,
             bool testStarShapeness = false)
{
  if(worst) {
    it = AllTris.find(worst);
    if(worst != *it) {
      Msg::Error("Could not insert point");
      return false;
    }
  }
  else
    worst = *it;

  MTri3 *ptin = nullptr;
  std::list<edgeXface> shell;
  std::list<MTri3 *> cavity;
  double uv[2];

  // if the point is able to break the bad triangle "worst"
  if(inCircumCircleAniso(gf, worst->tri(), center, metric, data)) {
    recurFindCavityAniso(gf, shell, cavity, metric, center, worst, data);
    for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
      if(invMapUV((*itc)->tri(), center, data, uv, 1.e-8)) {
        ptin = *itc;
        break;
      }
    }
  }
  else {
    ptin = search4Triangle(worst, center, data, AllTris, uv,
                           oneNewTriangle ? true : false);
    if(ptin) {
      recurFindCavityAniso(gf, shell, cavity, metric, center, ptin, data);
    }
  }

  if(ptin) {
    // we use here local coordinates as real coordinates x,y and z will be
    // computed hereafter
    GPoint p = gf->point(center[0], center[1]);

    MVertex *v = new MFaceVertex(p.x(), p.y(), p.z(), gf, center[0], center[1]);

    double lc1, lc;
    int index0 = data.getIndex(ptin->tri()->getVertex(0));
    int index1 = data.getIndex(ptin->tri()->getVertex(1));
    int index2 = data.getIndex(ptin->tri()->getVertex(2));
    lc1 = (1. - uv[0] - uv[1]) * data.vSizes[index0] +
          uv[0] * data.vSizes[index1] + uv[1] * data.vSizes[index2];
    if(CTX::instance()->mesh.algo2d == ALGO_2D_BAMG)
      lc = 1.;
    else
      lc = BGM_MeshSize(gf, center[0], center[1], p.x(), p.y(), p.z());

    data.addVertex(v, center[0], center[1], lc1, lc);

    int result = -9;
    if(p.succeeded()) {
      result = insertVertexB(shell, cavity, false, gf, v, center, ptin, AllTris,
                             ActiveTris, data, metric, oneNewTriangle,
                             testStarShapeness);
    }
    if(result != 1) {
      if(result == -1)
        Msg::Debug("Point %g %g cannot be inserted because cavity if of size 1",
                   center[0], center[1]);
      if(result == -2)
        Msg::Debug("Point %g %g cannot be inserted because euler formula is "
                   "not fulfilled",
                   center[0], center[1]);
      if(result == -3)
        Msg::Debug(
          "Point %g %g cannot be inserted because cavity is not star shaped",
          center[0], center[1]);
      if(result == -4)
        Msg::Debug("Point %g %g cannot be inserted because it is too close to "
                   "another point)",
                   center[0], center[1]);
      if(result == -5)
        Msg::Debug("Point %g %g cannot be inserted because it is out of the "
                   "parametric domain)",
                   center[0], center[1]);

      AllTris.erase(it);
      worst->forceRadius(-1);
      AllTris.insert(worst);
      delete v;
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
        (*itc)->setDeleted(false);
      return false;
    }
    else {
      gf->mesh_vertices.push_back(v);
      return true;
    }
  }
  else {
    for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
      (*itc)->setDeleted(false);
    AllTris.erase(it);
    worst->forceRadius(0);
    AllTris.insert(worst);
    return false;
  }
}

static double lengthMetric(const double p[2], const double q[2],
                           const double metric[3])
{
  return std::sqrt((p[0] - q[0]) * metric[0] * (p[0] - q[0]) +
                   2 * (p[0] - q[0]) * metric[1] * (p[1] - q[1]) +
                   (p[1] - q[1]) * metric[2] * (p[1] - q[1]));
}

static double optimalPointFrontal(GFace *gf, MTri3 *worst, int active_edge,
                                  bidimMeshData &data, double newPoint[2],
                                  double metric[3])
{
  double center[2], r2;
  MTriangle *base = worst->tri();
  circUV(base, data, center, gf);
  int index0 = data.getIndex(base->getVertex(0));
  int index1 = data.getIndex(base->getVertex(1));
  int index2 = data.getIndex(base->getVertex(2));
  double pa[2] = {(data.Us[index0] + data.Us[index1] + data.Us[index2]) * ONE_THIRD,
                  (data.Vs[index0] + data.Vs[index1] + data.Vs[index2]) * ONE_THIRD};
  buildMetric(gf, pa, metric);
  circumCenterMetric(worst->tri(), metric, data, center, r2);
  // compute the middle point of the edge
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;

  index0 = data.getIndex(base->getVertex(ip1));
  index1 = data.getIndex(base->getVertex(ip2));
  double P[2] = {data.Us[index0], data.Vs[index0]};
  double Q[2] = {data.Us[index1], data.Vs[index1]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};

  // now we have the edge center and the center of the circumcircle, we try to
  // find a point that would produce a perfect triangle while connecting the 2
  // points of the active edge
  double dir[2] = {center[0] - midpoint[0], center[1] - midpoint[1]};
  double norm = std::sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  dir[0] /= norm;
  dir[1] /= norm;
  const double RATIO =
    std::sqrt(dir[0] * dir[0] * metric[0] + 2 * dir[1] * dir[0] * metric[1] +
              dir[1] * dir[1] * metric[2]);

  const double rhoM1 = 0.5 * (data.vSizes[index0] + data.vSizes[index1]);
  const double rhoM2 = 0.5 * (data.vSizesBGM[index0] + data.vSizesBGM[index1]);
  const double rhoM =
    Extend1dMeshIn2dSurfaces(gf) ? std::min(rhoM1, rhoM2) : rhoM2;
  const double rhoM_hat = rhoM;

  const double q = lengthMetric(center, midpoint, metric);
  const double d = rhoM_hat * std::sqrt(3.0) * 0.5;

  // d is corrected in a way that the mesh size is computed at point newPoint

  const double L = std::min(d, q);

  newPoint[0] = midpoint[0] + L * dir[0] / RATIO;
  newPoint[1] = midpoint[1] + L * dir[1] / RATIO;

  return L;
}

/*
            x
            |
            |
            | d =  3^{1/2}/2 h
            |
            |
      ------p------->   n
            h

   x point of the plane

   h being some kind of average between the size field
   and the edge length
*/

static bool optimalPointFrontalB(GFace *gf, MTri3 *worst, int active_edge,
                                 bidimMeshData &data, double newPoint[2],
                                 double metric[3])
{
  // as a starting point, let us use the "fast algo"
  double d =
    optimalPointFrontal(gf, worst, active_edge, data, newPoint, metric);
  int ip1 = (active_edge + 2) % 3;
  int ip2 = active_edge;
  int ip3 = (active_edge + 1) % 3;
  MVertex *v1 = worst->tri()->getVertex(ip1);
  MVertex *v2 = worst->tri()->getVertex(ip2);
  MVertex *v3 = worst->tri()->getVertex(ip3);
  SVector3 middle((v1->x() + v2->x()) * .5, (v1->y() + v2->y()) * .5,
                  (v1->z() + v2->z()) * .5);
  SVector3 v1v2(v2->x() - v1->x(), v2->y() - v1->y(), v2->z() - v1->z());
  SVector3 tmp(v3->x() - middle.x(), v3->y() - middle.y(),
               v3->z() - middle.z());
  SVector3 n1 = crossprod(v1v2, tmp);
  if(n1.norm() < 1.e-12) return true;

  SVector3 n2 = crossprod(n1, v1v2);
  n1.normalize();
  n2.normalize();
  // we look for a point that is
  // P = d * (n1 std::cos(t) + n2 std::sin(t)) that is on the surface
  // so we have to find t, starting with t = 0

#if defined(HAVE_HXT)
  if(gf->geomType() == GEntity::DiscreteSurface) {
    discreteFace *ddf = dynamic_cast<discreteFace *>(gf);
    if(ddf) {
      GPoint gp = ddf->intersectionWithCircle(n1, n2, middle, d, newPoint);
      if(gp.succeeded()) return true;
      return false;
    }
  }
#endif

  double uvt[3] = {newPoint[0], newPoint[1], 0.0};
  curveFunctorCircle cc(n2, n1, middle, d);
  surfaceFunctorGFace ss(gf);

  if(intersectCurveSurface(cc, ss, uvt, d * 1.e-8)) {
    newPoint[0] = uvt[0];
    newPoint[1] = uvt[1];
    return true;
  }

  return true;
}

void bowyerWatsonFrontalOptimized(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence,
  std::map<MVertex *, SPoint2> *parametricCoordinates,
  std::vector<SPoint2> *true_boundary)
{
  std::set<MTri3 *, compareTri3Ptr> AllTris;
  std::set<MTri3 *, compareTri3Ptr> ActiveTris;
  bidimMeshData DATA(equivalence, parametricCoordinates);
  bool testStarShapeness = true;

  // Debug-only phase timers (verbosity >= 4), mirroring the ones in
  // bowyerWatsonFrontal so the two algorithms can be compared phase by phase.
  using _clk = std::chrono::steady_clock;
  const bool _timePhases = Msg::GetVerbosity() >= 4;
  auto _ms = [](_clk::time_point a, _clk::time_point b) {
    return std::chrono::duration<double, std::milli>(b - a).count();
  };
  const auto _tStart = _clk::now();

  if(!buildMeshGenerationDataStructures(gf, AllTris, DATA)) {
    Msg::Error("Invalid meshing data structure");
    return;
  }
  const auto _tBuilt = _clk::now();

  int ITER = 0, active_edge;
  // seed the front: scan triangles by decreasing circumradius and collect
  // the active ones, stopping at the first inactive triangle that is
  // already small enough
  auto it = AllTris.begin();
  for(; it != AllTris.end(); ++it) {
    if(isActive(*it, LIMIT_, active_edge))
      ActiveTris.insert(*it);
    else if((*it)->getRadius() < LIMIT_)
      break;
  }

  Range<double> RU = gf->parBounds(0);
  Range<double> RV = gf->parBounds(1);
  SPoint2 FAR(RU.high() + (RU.high() - RU.low()),
              RV.high() + (RV.high() - RV.low()));

  // insert points
  while(1) {
    if(!ActiveTris.size()) break;
    MTri3 *worst = (*ActiveTris.begin());
    ActiveTris.erase(ActiveTris.begin());

    if(!worst->isDeleted() && isActive(worst, LIMIT_, active_edge) &&
       worst->getRadius() > LIMIT_) {
      if(ITER++ % 5000 == 0)
        Msg::Debug("%7d points created -- Worst tri radius is %8.3f",
                   gf->mesh_vertices.size(), worst->getRadius());
      double newPoint[2], metric[3];
      if(optimalPointFrontalB(gf, worst, active_edge, DATA, newPoint, metric)) {
        SPoint2 NP(newPoint[0], newPoint[1]);
        int nnnn;
        if(!true_boundary ||
           pointInsideParametricDomain(*true_boundary, NP, FAR, nnnn))
          insertAPoint(gf, AllTris.end(), newPoint, metric, DATA, AllTris,
                       &ActiveTris, worst, nullptr, testStarShapeness);
      }
      else {
        Msg::Debug("no point found");
      }
    }
  }

  const auto _tRefined = _clk::now();
  transferDataStructure(gf, AllTris, DATA);

  if(_timePhases) {
    const auto _tTransfer = _clk::now();
    Msg::Info("algo12 face %d phases (ms): build=%.1f refine=%.1f "
              "transfer=%.1f total=%.1f",
              gf->tag(), _ms(_tStart, _tBuilt), _ms(_tBuilt, _tRefined),
              _ms(_tRefined, _tTransfer), _ms(_tStart, _tTransfer));
  }

  splitElementsInBoundaryLayerIfNeeded(gf);
}
