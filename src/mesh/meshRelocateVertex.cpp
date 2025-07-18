// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "Context.h"
#include "meshGFaceOptimize.h"
#include "qualityMeasures.h"
#include "Context.h"

#if defined(HAVE_WINSLOWUNTANGLER)
#include "winslowUntangler.h"
#endif

using vec3 = std::array<double, 3>;
inline double dot(const vec3 &a, const vec3 &b)
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
inline vec3 cross(const vec3 &a, const vec3 &b)
{
  return {{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
           a[0] * b[1] - a[1] * b[0]}};
}
inline vec3 operator-(const vec3 &a, const vec3 &b)
{
  return {{a[0] - b[0], a[1] - b[1], a[2] - b[2]}};
}
inline vec3 operator+(const vec3 &a, const vec3 &b)
{
  return {{a[0] + b[0], a[1] + b[1], a[2] + b[2]}};
}
inline double tet_volume(vec3 a, vec3 b, vec3 c, vec3 d)
{
  return dot((a - d), cross(b - d, c - d)) / 6.;
}

static double objective_function(double xi, MVertex *ver, double xTarget,
                                 double yTarget, double zTarget,
                                 const std::vector<MElement *> &lt,
                                 bool onlytet = false)
{
  double x = ver->x();
  double y = ver->y();
  double z = ver->z();
  ver->x() = (1. - xi) * ver->x() + xi * xTarget;
  ver->y() = (1. - xi) * ver->y() + xi * yTarget;
  ver->z() = (1. - xi) * ver->z() + xi * zTarget;
  double minQual = 1.0;
  for(std::size_t i = 0; i < lt.size(); i++) {
    if(lt[i]->getNumVertices() == 4) {
      double V;
      double Q = qmTetrahedron::gamma(
        lt[i]->getVertex(0)->x(), lt[i]->getVertex(0)->y(),
        lt[i]->getVertex(0)->z(), lt[i]->getVertex(1)->x(),
        lt[i]->getVertex(1)->y(), lt[i]->getVertex(1)->z(),
        lt[i]->getVertex(2)->x(), lt[i]->getVertex(2)->y(),
        lt[i]->getVertex(2)->z(), lt[i]->getVertex(3)->x(),
        lt[i]->getVertex(3)->y(), lt[i]->getVertex(3)->z(), &V);
      if(V > 0) Q = -Q;
      minQual = std::min(Q, minQual);
    }
    else if(!onlytet) {
      minQual = std::min(std::abs(lt[i]->minSICNShapeMeasure()) * .2, minQual);
    }
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}

static double objective_function(double xi, MVertex *ver, GFace *gf,
                                 SPoint2 &p1, SPoint2 &p2,
                                 const std::vector<MElement *> &lt)
{
  double x = ver->x();
  double y = ver->y();
  double z = ver->z();
  SPoint2 p = p1 * (1. - xi) + p2 * xi;
  GPoint pp = gf->point(p);
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  double minQual = 1.0;
  for(std::size_t i = 0; i < lt.size(); i++) {
    if(lt[i]->getNumVertices() == 4)
      minQual = std::min((lt[i]->etaShapeMeasure()), minQual);
    else
      minQual = std::min(std::abs(lt[i]->gammaShapeMeasure()), minQual);
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}

static double objective_function(double const xi, MVertex *const ver,
                                 GFace *const gf, SPoint3 &p1, SPoint3 &p2,
                                 const std::vector<MElement *> &lt)
{
  double const x = ver->x();
  double const y = ver->y();
  double const z = ver->z();
  SPoint3 p = p1 * (1. - xi) + p2 * xi;

  double initialGuess[2] = {0, 0};

  GPoint pp = gf->closestPoint(p, initialGuess);
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  double minQual = 1.0;
  for(std::size_t i = 0; i < lt.size(); i++) {
    if(lt[i]->getNumVertices() == 4)
      minQual = std::min(lt[i]->etaShapeMeasure(), minQual);
    else
      minQual = std::min(std::abs(lt[i]->gammaShapeMeasure()), minQual);
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}

static bool Stopping_Rule(double const x0, double const x1, double const tol)
{
  return std::abs(x1 - x0) < tol;
}

static double Maximize_Quality_Golden_Section(MVertex *ver, double xTarget,
                                              double yTarget, double zTarget,
                                              const std::vector<MElement *> &lt,
                                              double const tol, double &q)
{
  const double lambda = 0.5 * (std::sqrt(5.0) - 1.0);
  const double mu = 0.5 * (3.0 - std::sqrt(5.0)); // = 1 - lambda
  double a = 0.0;
  double b = 2.0;

  double x1 = b - lambda * (b - a);
  double x2 = a + lambda * (b - a);
  double fx1 = objective_function(x1, ver, xTarget, yTarget, zTarget, lt);
  double fx2 = objective_function(x2, ver, xTarget, yTarget, zTarget, lt);

  if(tol < 0.0) return fx1 > fx2 ? x1 : x2;

  while(!Stopping_Rule(a, b, tol)) {
    // printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if(fx1 < fx2) {
      a = x1;
      if(Stopping_Rule(a, b, tol)) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function(x2, ver, xTarget, yTarget, zTarget, lt);
    }
    else {
      b = x2;
      if(Stopping_Rule(a, b, tol)) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function(x1, ver, xTarget, yTarget, zTarget, lt);
    }
  }
  // printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  q = std::min(fx1, fx2);
  return a;
}

static double Maximize_Quality_Golden_Section(MVertex *ver, GFace *gf,
                                              SPoint2 &p1, SPoint2 &p2,
                                              const std::vector<MElement *> &lt,
                                              double tol, double &worst)
{
  const double lambda = 0.5 * (std::sqrt(5.0) - 1.0);
  const double mu = 0.5 * (3.0 - std::sqrt(5.0)); // = 1 - lambda
  double a = 0.0;
  double b = 1.0;

  worst = objective_function(0.0, ver, gf, p1, p2, lt);

  if(worst > 0.5) return 0.0;

  double x1 = b - lambda * (b - a);
  double x2 = a + lambda * (b - a);
  double fx1 = objective_function(x1, ver, gf, p1, p2, lt);
  double fx2 = objective_function(x2, ver, gf, p1, p2, lt);

  if(tol < 0.0) return fx1 > fx2 ? x1 : x2;

  while(!Stopping_Rule(a, b, tol)) {
    // printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if(fx1 < fx2) {
      a = x1;
      if(Stopping_Rule(a, b, tol)) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function(x2, ver, gf, p1, p2, lt);
    }
    else {
      b = x2;
      if(Stopping_Rule(a, b, tol)) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function(x1, ver, gf, p1, p2, lt);
    }
  }
  double final = objective_function(a, ver, gf, p1, p2, lt);
  if(final < worst) return 0.0;
  worst = final;
  // printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  return a;
}

static double Maximize_Quality_Golden_Section(MVertex *ver, GFace *gf,
                                              SPoint3 &p1, SPoint3 &p2,
                                              const std::vector<MElement *> &lt,
                                              double tol, double &worst)
{
  const double lambda = 0.5 * (std::sqrt(5.0) - 1.0);
  const double mu = 0.5 * (3.0 - std::sqrt(5.0)); // = 1 - lambda
  double a = 0.0;
  double b = 1.0;

  worst = objective_function(0.0, ver, gf, p1, p2, lt);

  if(worst > 0.5) return 0.0;

  double x1 = b - lambda * (b - a);
  double x2 = a + lambda * (b - a);
  double fx1 = objective_function(x1, ver, gf, p1, p2, lt);
  double fx2 = objective_function(x2, ver, gf, p1, p2, lt);

  if(tol < 0.0) return fx1 > fx2 ? x1 : x2;

  while(!Stopping_Rule(a, b, tol)) {
    // printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if(fx1 < fx2) {
      a = x1;
      if(Stopping_Rule(a, b, tol)) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function(x2, ver, gf, p1, p2, lt);
    }
    else {
      b = x2;
      if(Stopping_Rule(a, b, tol)) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function(x1, ver, gf, p1, p2, lt);
    }
  }
  double final = objective_function(a, ver, gf, p1, p2, lt);
  if(final < worst) return 0.0;
  worst = final;
  // printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  return a;
}

void relocateVertexOfPyramid(MVertex *ver, const std::vector<MElement *> &lt,
                             double relax)
{
  if(ver->onWhat()->dim() != 3) return;
  double x = 0.0, y = 0.0, z = 0.0;
  int N = 0;
  MElement *pyramid = nullptr;

  for(std::size_t i = 0; i < lt.size(); i++) {
    double XCG = 0.0, YCG = 0.0, ZCG = 0.0;
    if(lt[i]->getNumVertices() == 5)
      pyramid = lt[i];
    else {
      for(std::size_t j = 0; j < lt[i]->getNumVertices(); j++) {
        XCG += lt[i]->getVertex(j)->x();
        YCG += lt[i]->getVertex(j)->y();
        ZCG += lt[i]->getVertex(j)->z();
      }
      x += XCG;
      y += YCG;
      z += ZCG;
      N += lt[i]->getNumVertices();
    }
  }
  x /= N;
  y /= N;
  z /= N;

  if(pyramid) {
    MFace q = pyramid->getFace(4);
    double A = q.approximateArea();
    SVector3 n = q.normal();
    n.normalize();
    SPoint3 c = q.barycenter();
    SVector3 d(x - c.x(), y - c.y(), z - c.z());
    if(dot(n, d) < 0) n = n * (-1.0);
    double H = .5 * sqrt(fabs(A));
    double XOPT = c.x() + relax * H * n.x();
    double YOPT = c.y() + relax * H * n.y();
    double ZOPT = c.z() + relax * H * n.z();
    double FULL_MOVE_OBJ =
      objective_function(1.0, ver, XOPT, YOPT, ZOPT, lt, true);
    if(FULL_MOVE_OBJ > 1e-6) {
      ver->x() = XOPT;
      ver->y() = YOPT;
      ver->z() = ZOPT;
      return;
    }
  }
}

static void relocateVertexGolden(MVertex *ver,
                                 const std::vector<MElement *> &lt,
                                 double relax, double tol)
{
  if(ver->onWhat()->dim() != 3) return;
  double x = 0.0, y = 0.0, z = 0.0;
  int N = 0;

  for(std::size_t i = 0; i < lt.size(); i++) {
    double XCG = 0.0, YCG = 0.0, ZCG = 0.0;
    for(std::size_t j = 0; j < lt[i]->getNumVertices(); j++) {
      XCG += lt[i]->getVertex(j)->x();
      YCG += lt[i]->getVertex(j)->y();
      ZCG += lt[i]->getVertex(j)->z();
    }
    x += XCG;
    y += YCG;
    z += ZCG;
    N += lt[i]->getNumVertices();
  }

  double NO_MOVE_OBJ = objective_function(0.0, ver, x / N, y / N, z / N, lt);
  double FULL_MOVE_OBJ = objective_function(1.0, ver, x / N, y / N, z / N, lt);
  if(FULL_MOVE_OBJ > NO_MOVE_OBJ) {
    ver->x() = x / N;
    ver->y() = y / N;
    ver->z() = z / N;
    //    return;
  }

  double q;
  double xi =
    Maximize_Quality_Golden_Section(ver, x / N, y / N, z / N, lt, tol, q);
  ver->x() = (1. - xi) * ver->x() + xi * x / N;
  ver->y() = (1. - xi) * ver->y() + xi * y / N;
  ver->z() = (1. - xi) * ver->z() + xi * z / N;
}

// use real space + projection at the end
static double relocateVertex2(GFace *gf, MVertex *ver,
                              const std::vector<MElement *> &lt, double tol)
{
  SPoint3 p1(0, 0, 0);
  std::size_t counter = 0;
  for(std::size_t i = 0; i < lt.size(); i++) {
    for(std::size_t j = 0; j < lt[i]->getNumVertices(); j++) {
      MVertex *v = lt[i]->getVertex(j);
      p1 += SPoint3(v->x(), v->y(), v->z());
      counter++;
    }
  }
  p1 *= 1.0 / (double)counter;
  SPoint3 p2(ver->x(), ver->y(), ver->z());
  double worst;
  double xi = Maximize_Quality_Golden_Section(ver, gf, p1, p2, lt, tol, worst);

  SPoint3 p = p1 * (1 - xi) + p2 * xi;
  double initialGuess[2] = {0, 0};
  GPoint pp = gf->closestPoint(p, initialGuess);
  if(!pp.succeeded()) return 2.0;
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  return worst;
}

static double relocateVertex(GFace *gf, MVertex *ver,
                             const std::vector<MElement *> &lt, double tol)
{
  if(ver->onWhat()->dim() != 2) return 2.0;

  SPoint2 p1(0, 0);
  SPoint2 p2;
  if(ver->getParameter(0, p2[0])) { ver->getParameter(1, p2[1]); }
  else {
    return relocateVertex2(gf, ver, lt, tol);
  }

  std::size_t counter = 0;
  for(std::size_t i = 0; i < lt.size(); i++) {
    for(std::size_t j = 0; j < lt[i]->getNumVertices(); j++) {
      MVertex *v = lt[i]->getVertex(j);
      SPoint2 pp;
      reparamMeshVertexOnFace(v, gf, pp);
      counter++;
      if(v->onWhat()->dim() == 1) {
        GEdge *ge = dynamic_cast<GEdge *>(v->onWhat());
        // do not take any chance
        if(ge->isSeam(gf)) return 2.0;
      }
      p1 += pp;
    }
  }
  p1 *= 1. / (double)counter;
  double worst;
  double xi = Maximize_Quality_Golden_Section(ver, gf, p1, p2, lt, tol, worst);
  // if (xi != 0) printf("xi = %g\n",xi);
  SPoint2 p = p1 * (1 - xi) + p2 * xi;
  GPoint pp = gf->point(p);
  if(!pp.succeeded()) return 2.0;
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  ver->setParameter(0, pp.u());
  ver->setParameter(1, pp.v());
  return worst;
}

void getAllBoundaryLayerVertices(GFace *gf, std::set<MVertex *> &vs);

void RelocateVertices(GFace *gf, int niter, double tol)
{
  if(!niter) return;
  Msg::Debug("relocate vertices (face %i)", gf->tag());

  std::set<MVertex *> vs;
  getAllBoundaryLayerVertices(gf, vs);

  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  for(int i = 0; i < niter; i++) {
    auto it = adj.begin();
    while(it != adj.end()) {
      if(vs.find(it->first) == vs.end()) {
        relocateVertex(gf, it->first, it->second, tol);
      }
      ++it;
    }
  }
}

void RelocateVertices(GRegion *region, int niter, double tol)
{
  if(!niter) return;

  v2t_cont adj;
  buildVertexToElement(region->tetrahedra, adj);
  buildVertexToElement(region->pyramids, adj);
  buildVertexToElement(region->prisms, adj);
  buildVertexToElement(region->hexahedra, adj);
  for(int i = 0; i < niter + 2; i++) {
    auto it = adj.begin();
    double relax = std::min((double)(i + 1) / niter, 1.0);
    while(it != adj.end()) {
      relocateVertexGolden(it->first, it->second, relax, tol);
      ++it;
    }
  }
}

#if defined(HAVE_WINSLOWUNTANGLER)

void _getVertices(std::vector<MElement *> &el, std::vector<MVertex *> &interior,
                  std::vector<MVertex *> &boundary)
{
  std::set<MFace, MFaceLessThan> _fcs;
  std::set<MVertex *> _v, _vin, _vbd;
  for(auto e : el) {
    for(int i = 0; i < e->getNumFaces(); i++) {
      auto f = e->getFace(i);
      auto it = _fcs.find(f);
      if(it == _fcs.end())
        _fcs.insert(f);
      else
        _fcs.erase(it);
    }
  }
  for(auto f : _fcs) {
    for(size_t i = 0; i < f.getNumVertices(); i++) {
      _vbd.insert(f.getVertex(i));
    }
  }
  for(auto e : el) {
    for(size_t i = 0; i < e->getNumVertices(); i++) {
      auto v = e->getVertex(i);
      if(_vbd.find(v) == _vbd.end()) _vin.insert(v);
    }
  }
  interior.insert(interior.begin(), _vin.begin(), _vin.end());
  boundary.insert(boundary.begin(), _vbd.begin(), _vbd.end());
}

void _untanglePyramidsLocal(GRegion *region)
{
  v2t_cont adj;
  buildVertexToElement(region->tetrahedra, adj);
  buildVertexToElement(region->pyramids, adj);
  buildVertexToElement(region->prisms, adj);
  buildVertexToElement(region->hexahedra, adj);

  double avgEdgeSize = 0.0;
  for(auto t : region->tetrahedra)
    for(size_t k = 0; k < 4; k++)
      for(size_t l = k + 1; l < 4; l++)
        avgEdgeSize += t->getVertex(k)->distance(t->getVertex(l));
  avgEdgeSize /= (6.0 * region->tetrahedra.size());
  double ee[4][3] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                     {-.5, 0, -1. / (2. * std::sqrt(2.))},
                     {0, .5, 1. / (2. * std::sqrt(2.))},
                     {0, -.5, 1. / (2. * std::sqrt(2.))}};
  std::array<std::array<double, 3>, 4> equi;
  for(size_t lv = 0; lv < 4; ++lv) {
    equi[lv][0] = ee[lv][0] * (avgEdgeSize);
    equi[lv][1] = ee[lv][1] * (avgEdgeSize);
    equi[lv][2] = ee[lv][2] * (avgEdgeSize);
  }

  std::set<MVertex *> _v_pyr;
  for(size_t i = 0; i < region->pyramids.size(); i++) {
    _v_pyr.insert(region->pyramids[i]->getVertex(4));
  }

  // all pyramid vertex relocated one by one
  int ITER = 0, MAXITER = 3;
  while(ITER++ < MAXITER) {
    std::set<MVertex *> _v_pyr_new;
    for(auto v_current : _v_pyr) {
      std::vector<MElement *> el = adj[v_current];
      //      for (int k=0;k<=ITER;k++){
      //	_addLayer (el,adj);
      //      }
      std::vector<MVertex *> interior, boundary;
      _getVertices(el, interior, boundary);
      std::vector<std::array<double, 3>> points;
      int index = 0;
      std::vector<bool> locked;
      for(auto v : interior) {
        v->setIndex(index++);
        points.push_back({v->x(), v->y(), v->z()});
        locked.push_back(false);
      }
      double X = 0, Y = 0, Z = 0;
      for(auto v : boundary) {
        v->setIndex(index++);
        points.push_back({v->x(), v->y(), v->z()});
        X += v->x();
        Y += v->y();
        Z += v->z();
        locked.push_back(true);
      }
      X /= boundary.size();
      Y /= boundary.size();
      Z /= boundary.size();
      //      if (interior.size() == 1){
      //	points[0][0] = X / boundary.size();
      //	points[0][1] = Y / boundary.size();
      //	points[0][2] = Z / boundary.size();
      //      }

      std::vector<std::array<uint32_t, 4>> tets;
      std::vector<std::array<std::array<double, 3>, 4>> tetIdealShapes;
      for(auto e : el) {
        uint32_t n0 = e->getVertex(0)->getIndex();
        uint32_t n1 = e->getVertex(1)->getIndex();
        uint32_t n2 = e->getVertex(2)->getIndex();
        uint32_t n3 = e->getVertex(3)->getIndex();
        if(e->getNumVertices() == 4) {
          int order[4] = {0, 3, 2, 1};
          tets.push_back({n0, n3, n2, n1});
          for(size_t lv = 0; lv < 4; ++lv) {
            equi[lv][0] = e->getVertex(order[lv])->x();
            equi[lv][1] = e->getVertex(order[lv])->y();
            equi[lv][2] = e->getVertex(order[lv])->z();
          }
          // double reg_vol = tet_volume(equi[0], equi[1], equi[2], equi[3]);
          // printf("reg_vol = %g -- %lu %lu %lu %lu \n",reg_vol,n0,n3,n2,n1);
          tetIdealShapes.push_back(equi);
        }
        else if(e->getNumVertices() == 5) {
          uint32_t n4 = e->getVertex(4)->getIndex();
          tets.push_back({n0, n4, n2, n1});
          tets.push_back({n2, n4, n0, n3});
          tets.push_back({n1, n4, n3, n2});
          tets.push_back({n3, n4, n1, n0});
          int e0[4][4] = {
            {0, 4, 2, 1}, {2, 4, 0, 3}, {1, 4, 3, 2}, {3, 4, 1, 0}};
          for(size_t k = 0; k < 4; ++k) {
            for(size_t lv = 0; lv < 4; ++lv) {
              equi[lv][0] = e0[k][lv] == 4 ? X : e->getVertex(e0[k][lv])->x();
              equi[lv][1] = e0[k][lv] == 4 ? Y : e->getVertex(e0[k][lv])->y();
              equi[lv][2] = e0[k][lv] == 4 ? Z : e->getVertex(e0[k][lv])->z();
            }
            // double reg_vol = tet_volume(equi[0], equi[1], equi[2], equi[3]);
            // printf("reg_vol 2= %g -- %lu %lu %lu %lu
            // %lu\n",reg_vol,n0,n1,n2,n3,n4);
            tetIdealShapes.push_back(equi);
          }
        }
      }
      // printf("Untangling vertex %d (%lu elements, %lu interior, %lu bnd)\n",
      //        v_current->getIndex(),el.size(), interior.size(),
      //        boundary.size());
      untangle_tetrahedra(points, locked, tets, tetIdealShapes, 1.e-0, 130, 2);
      bool success = true;
      if(!success)
        _v_pyr_new.insert(v_current);
      else {
        for(auto v : interior) {
          v->x() = points[v->getIndex()][0];
          v->y() = points[v->getIndex()][1];
          v->z() = points[v->getIndex()][2];
        }
        for(auto v : boundary) {
          v->x() = points[v->getIndex()][0];
          v->y() = points[v->getIndex()][1];
          v->z() = points[v->getIndex()][2];
        }
      }
    }
    _v_pyr = _v_pyr_new;
  }
}

int _untanglePyramids(GRegion *region, bool topological, bool geometrical)
{
  std::set<MVertex *> _vts;
  std::set<MVertex *> _v_pyr;
  for(size_t i = 0; i < region->pyramids.size(); i++) {
    _v_pyr.insert(region->pyramids[i]->getVertex(4));
  }

  std::set<MFace, MFaceLessThan> _fcs;

  std::vector<MTetrahedron *> _tets;
  for(size_t i = 0; i < region->tetrahedra.size(); i++) {
    MTetrahedron *t = region->tetrahedra[i];
    for(size_t j = 0; j < 4; j++) _fcs.insert(t->getFace(j));
    for(size_t j = 0; j < 4; j++) {
      MVertex *v = t->getVertex(j);
      if(_v_pyr.find(v) != _v_pyr.end()) {
        _tets.push_back(t);
        _vts.insert(t->getVertex(0));
        _vts.insert(t->getVertex(1));
        _vts.insert(t->getVertex(2));
        _vts.insert(t->getVertex(3));
        break;
      }
    }
  }

  int count = 0;
  std::vector<bool> locked;

  std::vector<std::array<double, 3>> points;
  for(auto v : _vts) {
    points.push_back({v->x(), v->y(), v->z()});
    if(v->onWhat()->dim() == 3 &&
       std::binary_search(_v_pyr.begin(), _v_pyr.end(), v))
      locked.push_back(false);
    else
      locked.push_back(true);
    v->setIndex(count++);
  }
  std::vector<std::array<uint32_t, 4>> tets;

  double avgEdgeSize = 0.0;

  for(auto t : _tets) {
    for(size_t k = 0; k < 4; k++)
      for(size_t l = k + 1; l < 4; l++)
        avgEdgeSize += t->getVertex(k)->distance(t->getVertex(l));
    uint32_t n0 = t->getVertex(0)->getIndex();
    uint32_t n1 = t->getVertex(1)->getIndex();
    uint32_t n2 = t->getVertex(2)->getIndex();
    uint32_t n3 = t->getVertex(3)->getIndex();
    std::array<uint32_t, 4> _tt = {n0, n3, n2, n1};
    tets.push_back(_tt);
  }
  avgEdgeSize /= (6.0 * _tets.size());
  double ee[4][3] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                     {-.5, 0, -1. / (2. * std::sqrt(2.))},
                     {0, .5, 1. / (2. * std::sqrt(2.))},
                     {0, -.5, 1. / (2. * std::sqrt(2.))}};

  // avgEdgeSize *= 0.2;
  std::array<std::array<double, 3>, 4> equi;

  for(size_t lv = 0; lv < 4; ++lv) {
    equi[0][lv] = ee[lv][0] * (avgEdgeSize);
    equi[1][lv] = ee[lv][1] * (avgEdgeSize);
    equi[2][lv] = ee[lv][2] * (avgEdgeSize);
  }

  for(size_t i = 0; i < region->pyramids.size(); i++) {
    MFace mf = region->pyramids[i]->getFace(0);
    auto mf2 = _fcs.find(mf);
    if(mf2 == _fcs.end()) {
      Msg::Warning("Error in Pyramid Untangling");
      return -1;
    }
    if(topological) {
      SVector3 nf = mf.normal();
      SVector3 nf2 = (*mf2).normal();
      //      printf("%12.5E\n",dot(nf,nf2));
      if(dot(nf, nf2) > 0) {
        MVertex *v1 = region->pyramids[i]->getVertex(1);
        MVertex *v3 = region->pyramids[i]->getVertex(3);
        region->pyramids[i]->setVertex(1, v3);
        region->pyramids[i]->setVertex(3, v1);
      }
    }

    MVertex *v0 = region->pyramids[i]->getVertex(0);
    MVertex *v1 = region->pyramids[i]->getVertex(1);
    MVertex *v2 = region->pyramids[i]->getVertex(2);
    MVertex *v3 = region->pyramids[i]->getVertex(3);
    MVertex *v4 = region->pyramids[i]->getVertex(4);

    locked[v0->getIndex()] = true;
    locked[v1->getIndex()] = true;
    locked[v2->getIndex()] = true;
    locked[v3->getIndex()] = true;

    tets.push_back({(uint32_t)v0->getIndex(), (uint32_t)v4->getIndex(),
                    (uint32_t)v2->getIndex(), (uint32_t)v1->getIndex()});
    tets.push_back({(uint32_t)v2->getIndex(), (uint32_t)v4->getIndex(),
                    (uint32_t)v0->getIndex(), (uint32_t)v3->getIndex()});

    tets.push_back({(uint32_t)v1->getIndex(), (uint32_t)v4->getIndex(),
                    (uint32_t)v3->getIndex(), (uint32_t)v2->getIndex()});
    tets.push_back({(uint32_t)v3->getIndex(), (uint32_t)v4->getIndex(),
                    (uint32_t)v1->getIndex(), (uint32_t)v0->getIndex()});
  }
  if(geometrical) {
    std::vector<std::array<std::array<double, 3>, 4>> tetIdealShapes;

    for(size_t i = 0; i < tets.size(); i++) { tetIdealShapes.push_back(equi); }

    untangle_tetrahedra(points, locked, tets, tetIdealShapes, 1.e-12, 130, 2);

    for(auto v : _v_pyr) {
      v->x() = points[v->getIndex()][0];
      v->y() = points[v->getIndex()][1];
      v->z() = points[v->getIndex()][2];
    }
  }
  return 0;
}
#endif

void RelocateVerticesOfPyramids(GRegion *region, int niter, double tol)
{
#if defined(HAVE_WINSLOWUNTANGLER)
  if(CTX::instance()->mesh.optimizePyramids == 1) {
    Msg::Info("Using new pyramid optimization");
    _untanglePyramids(region, true, false);
    _untanglePyramidsLocal(region);
    return;
  }
#endif

  if(!niter) return;

  Msg::Info("Using old pyramid optimization");

  std::vector<MVertex *> _v_pyr;
  for(size_t i = 0; i < region->pyramids.size(); i++) {
    _v_pyr.push_back(region->pyramids[i]->getVertex(4));
  }
  std::sort(_v_pyr.begin(), _v_pyr.end());

  std::set<MVertex *> _vts;
  for(size_t i = 0; i < region->tetrahedra.size(); i++) {
    MTetrahedron *t = region->tetrahedra[i];
    for(size_t j = 0; j < 4; j++) {
      MVertex *v = t->getVertex(j);
      if(std::binary_search(_v_pyr.begin(), _v_pyr.end(), v)) {
        _vts.insert(t->getVertex(0));
        _vts.insert(t->getVertex(1));
        _vts.insert(t->getVertex(2));
        _vts.insert(t->getVertex(3));
        break;
      }
    }
  }

  std::vector<MTetrahedron *> _tets;
  for(size_t i = 0; i < region->tetrahedra.size(); i++) {
    MTetrahedron *t = region->tetrahedra[i];
    for(size_t j = 0; j < 4; j++) {
      MVertex *v = t->getVertex(j);
      if(_vts.find(v) != _vts.end()) {
        _tets.push_back(t);
        break;
      }
    }
  }

  v2t_cont adj;
  buildVertexToElement(_tets, adj);
  buildVertexToElement(region->pyramids, adj);
  buildVertexToElement(region->prisms, adj);
  buildVertexToElement(region->hexahedra, adj);

  for(int i = 0; i < 10; i++) {
    double relax = (double)i / 10. + 1e-6;
    auto it = adj.begin();
    while(it != adj.end()) {
      relocateVertexOfPyramid(it->first, it->second, relax);
      ++it;
    }
  }

  // return;

  for(int i = 0; i < niter + 2; i++) {
    auto it = adj.begin();
    double relax = std::min((double)(i + 1) / niter, 1.0);
    while(it != adj.end()) {
      relocateVertexGolden(it->first, it->second, relax, tol);
      ++it;
    }
  }
}

void RelocateVerticesOfPyramids(std::vector<GRegion *> &regions, int niter,
                                double tol)
{
  for(std::size_t k = 0; k < regions.size(); k++) {
    RelocateVerticesOfPyramids(regions[k], niter, tol);
  }
}

void RelocateVertices(std::vector<GRegion *> &regions, int niter, double tol)
{
  for(std::size_t k = 0; k < regions.size(); k++) {
    RelocateVertices(regions[k], niter, tol);
  }
}
